#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "../imports.h"
#include "math/FlxRect.h"
#include "FlxCamera.h"

namespace flixel {

class FlxGame;

class FlxG {
public:
    static bool autoPause;
    static bool fixedTimestep;
    static float timeScale;
    static float animationTimeScale;
    
    static int width;
    static int height;
    static int initialWidth;
    static int initialHeight;
    
    static FlxGame* game;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    
    static float elapsed;
    static float maxElapsed;
    
    static math::FlxRect worldBounds;
    
    static FlxCamera* camera;
    
    static void init(FlxGame* gameInstance, int gameWidth, int gameHeight);
    static void reset();
    
    static void resizeGame(int width, int height);
    static void resizeWindow(int width, int height);
    static void setFullscreen(bool fullscreen);
    
    static SDL_Texture* loadTexture(const std::string& path);
    static Mix_Chunk* loadSound(const std::string& path);
    static TTF_Font* loadFont(const std::string& path, int size);
    
    static void destroy();

private:
    static bool initialized;
};

inline int FlxG::width = 0;
inline int FlxG::height = 0;
inline math::FlxRect FlxG::worldBounds = math::FlxRect();
inline FlxCamera* FlxG::camera = nullptr;
}