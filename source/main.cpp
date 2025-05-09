#include "flixel/FlxGame.h"
#include "states/PlayState.h"
#include "imports.h"

struct GameConfig {
    int width = 1280;        // Width of the game in pixels
    int height = 720;        // Height of the game in pixels
    int framerate = 60;      // How many frames per second the game should run at
    bool skipSplash = false; // Whether to skip the splash screen (DOES NOTHING AS OF RN LOL)
    bool startFullscreen = false; // Whether to start in fullscreen
    std::string title = "NeoFlixel Game"; // Window title
};

int main(int argc, char* argv[]) {
    GameConfig config;

    try {
        flixel::FlxGame game(
            config.width,
            config.height,
            config.framerate,
            config.framerate,
            config.title
        );

        game.switchState(new PlayState());

        if (config.startFullscreen) {
            game.setFullscreen(true);
        }

        game.run();
    }
    catch (const std::exception& e) {
        SDL_Log("Error: %s", e.what());
        return 1;
    }

    return 0;
}
