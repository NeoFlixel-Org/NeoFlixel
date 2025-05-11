#include <string>
#include <sstream>
#include <iomanip>
#include "PlayState.h"
#include "flixel/FlxG.h"

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

    bgMusic = new flixel::FlxSound();
    if (bgMusic->loadStream("assets/music/freakyMenu.ogg", true, true)) {
        bgMusic->setVolume(0.3f);
        add(bgMusic);
        bgMusic->play();
    } else {
        flixel::FlxG::log.warn("Could not load background music");
        delete bgMusic;
        bgMusic = nullptr;
    }
}

void PlayState::update(float elapsed) {
    FlxState::update(elapsed);
    float speed = 200.0f * elapsed;

    if (flixel::FlxG::keys.pressed().count(SDL_SCANCODE_LEFT)) {
        player->x -= speed;
        flixel::FlxG::sound.muted = true;
    }
    if (flixel::FlxG::keys.pressed().count(SDL_SCANCODE_RIGHT)) {
        player->x += speed;
        flixel::FlxG::sound.muted = false;
    }
    if (flixel::FlxG::keys.pressed().count(SDL_SCANCODE_UP)) {
        player->y -= speed;
    }
    if (flixel::FlxG::keys.pressed().count(SDL_SCANCODE_DOWN)) {
        player->y += speed;
        flixel::FlxG::sound.stopAll();
    }

    if (flixel::FlxG::keys.justPressed().count(SDL_SCANCODE_SPACE)) {
        flixel::FlxG::log.notice("Space was just pressed!");
    }
    if (flixel::FlxG::keys.justReleased().count(SDL_SCANCODE_RETURN)) {
        flixel::FlxG::log.notice("Return was just released!");
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

    if (bgMusic) {
        remove(bgMusic, true);
        bgMusic = nullptr;
    }
    
    FlxState::destroy();
} 