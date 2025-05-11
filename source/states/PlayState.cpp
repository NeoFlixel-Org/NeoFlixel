#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "PlayState.h"
#include "flixel/FlxG.h"
#include "flixel/graphics/frames/FlxAtlasFrames.h"
#include "flixel/animation/FlxAnimationController.h"

void PlayState::create() {
    std::cout << "PlayState: Create Function Called!" << std::endl;
    
    std::ifstream file("assets/images/BOYFRIEND.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string xmlText = buffer.str();
    auto frames = flixel::graphics::frames::FlxAtlasFrames::fromSparrow("assets/images/BOYFRIEND.png", xmlText);
    player = new flixel::FlxSprite(100, 100);
    player->loadGraphic("assets/images/BOYFRIEND.png");
    player->frames = frames;
    player->animation = new flixel::animation::FlxAnimationController();
    player->animation->addByPrefix("idle", frames->getFramesByPrefix("BF idle dance"), 24, true);
    player->animation->addByPrefix("hey", frames->getFramesByPrefix("BF HEY!!"), 24, true);
    player->animation->play("idle");
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
        player->animation->play("hey");
    }
    if (flixel::FlxG::keys.justReleased().count(SDL_SCANCODE_RETURN)) {
        player->animation->play("idle");
    }

    if (player->animation) {
        player->animation->update(elapsed);
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
        delete player->animation;
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