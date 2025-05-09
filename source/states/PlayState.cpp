#include "PlayState.h"
#include "flixel/FlxG.h"

void PlayState::create() {
    std::cout << "PlayState: Create Function Called!" << std::endl;
    player = new flixel::FlxSprite(100, 100);
    player->loadGraphic("assets/mario.png");
    player->setScale(0.2f, 0.2f);
    player->updateHitbox();
    add(player);
}

void PlayState::update(float elapsed) {
    FlxState::update(elapsed);
    
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    float speed = 200.0f * elapsed;
    
    if (state[SDL_SCANCODE_LEFT]) {
        player->x -= speed;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        player->x += speed;
    }
    if (state[SDL_SCANCODE_UP]) {
        player->y -= speed;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        player->y += speed;
    }
}

void PlayState::draw() {
    FlxState::draw();
}

void PlayState::destroy() {
    if (player) {
        remove(player, true);
        player = nullptr;
    }
    
    FlxState::destroy();
} 