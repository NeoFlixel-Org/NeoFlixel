#include "PlayState.h"
#include "flixel/FlxG.h"
#include <sstream>
#include <iomanip>

void PlayState::create() {
    std::cout << "PlayState: Create Function Called!" << std::endl;
    
    player = new flixel::FlxSprite(100, 100);
    player->loadGraphic("assets/mario.png");
    player->setScale(0.2f, 0.2f);
    player->updateHitbox();
    add(player);
    
    positionText = new flixel::FlxText(0, 0, 300, "Position: (0, 0)", 16);
    positionText->setFont("assets/fonts/monsterrat.ttf");
    positionText->setColor(0xFFFFFFFF);
    positionText->setBorderStyle(flixel::FlxTextBorderStyle::SHADOW, {0, 0, 0, 255}, 2.0f);
    positionText->setAlignment(flixel::FlxTextAlign::CENTER);
    positionText->setWordWrap(true);
    positionText->updateHitbox();
    positionText->screenCenter();
    add(positionText);
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
    
    if (positionText) {
        std::stringstream ss;
        ss << "Position: (" << std::fixed << std::setprecision(1) 
           << player->x << ", " << player->y << ")";
        positionText->setText(ss.str());
        positionText->updateHitbox();
        positionText->screenCenter();
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
    
    if (positionText) {
        remove(positionText, true);
        positionText = nullptr;
    }
    
    FlxState::destroy();
} 