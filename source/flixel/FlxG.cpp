#include "FlxG.h"
#include "FlxGame.h"
#include <stdexcept>

namespace flixel {

bool FlxG::autoPause = true;
bool FlxG::fixedTimestep = true;
float FlxG::timeScale = 1.0f;
float FlxG::animationTimeScale = 1.0f;

int FlxG::width = 0;
int FlxG::height = 0;
int FlxG::initialWidth = 0;
int FlxG::initialHeight = 0;

FlxGame* FlxG::game = nullptr;
SDL_Window* FlxG::window = nullptr;
SDL_Renderer* FlxG::renderer = nullptr;

float FlxG::elapsed = 0.0f;
float FlxG::maxElapsed = 0.1f;

bool FlxG::initialized = false;

void FlxG::init(FlxGame* gameInstance, int gameWidth, int gameHeight) {
    if (initialized) {
        return;
    }

    game = gameInstance;
    width = gameWidth;
    height = gameHeight;
    initialWidth = gameWidth;
    initialHeight = gameHeight;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        throw std::runtime_error("Failed to initialize SDL: " + std::string(SDL_GetError()));
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw std::runtime_error("Failed to initialize SDL_image: " + std::string(IMG_GetError()));
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        throw std::runtime_error("Failed to initialize SDL_mixer: " + std::string(Mix_GetError()));
    }

    if (TTF_Init() < 0) {
        throw std::runtime_error("Failed to initialize SDL_ttf: " + std::string(TTF_GetError()));
    }

    window = SDL_CreateWindow(
        game->windowTitle.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        throw std::runtime_error("Failed to create window: " + std::string(SDL_GetError()));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        throw std::runtime_error("Failed to create renderer: " + std::string(SDL_GetError()));
    }

    initialized = true;
}

void FlxG::reset() {
    autoPause = true;
    fixedTimestep = true;
    timeScale = 1.0f;
    animationTimeScale = 1.0f;
    elapsed = 0.0f;
    maxElapsed = 0.1f;
}

void FlxG::resizeGame(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
}

void FlxG::resizeWindow(int newWidth, int newHeight) {
    SDL_SetWindowSize(window, newWidth, newHeight);
}

void FlxG::setFullscreen(bool fullscreen) {
    if (fullscreen) {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    } else {
        SDL_SetWindowFullscreen(window, 0);
    }
}

SDL_Texture* FlxG::loadTexture(const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        throw std::runtime_error("Failed to load image: " + std::string(IMG_GetError()));
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
    }

    return texture;
}

Mix_Chunk* FlxG::loadSound(const std::string& path) {
    Mix_Chunk* sound = Mix_LoadWAV(path.c_str());
    if (!sound) {
        throw std::runtime_error("Failed to load sound: " + std::string(Mix_GetError()));
    }
    return sound;
}

TTF_Font* FlxG::loadFont(const std::string& path, int size) {
    TTF_Font* font = TTF_OpenFont(path.c_str(), size);
    if (!font) {
        throw std::runtime_error("Failed to load font: " + std::string(TTF_GetError()));
    }
    return font;
}

void FlxG::destroy() {
    if (!initialized) {
        return;
    }

    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

    initialized = false;
}

}