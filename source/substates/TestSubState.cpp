#include "TestSubState.h"
#include <iostream>

TestSubState::TestSubState() : 
    testSprite(nullptr),
    testText(nullptr),
    timer(0.0f),
    isClosing(false)
{
}

void TestSubState::create()
{
    testText = new flixel::FlxText(0, 0, 300, "Paused?..", 16);
    testText->setFont("assets/fonts/nokiafc22.ttf");
    testText->setBold(true);
    testText->setColor(0xFFFFFFFF);
    testText->setBorderStyle(flixel::FlxTextBorderStyle::SHADOW, { 0, 0, 0, 255 }, 2.0f);
    testText->setAlignment(flixel::FlxTextAlign::CENTER);
    testText->screenCenter();
    add(testText);
}

void TestSubState::update(float elapsed)
{
    if (isClosing) return;

    flixel::FlxSubState::update(elapsed);

    timer += elapsed;
    if (flixel::FlxG::keys.justPressed().count(SDL_SCANCODE_RETURN) && !isClosing) {
        isClosing = true;
        close();
    }
}

void TestSubState::destroy()
{
    isClosing = true;

    if (testText) {
        remove(testText, false);
        delete testText;
        testText = nullptr;
    }

    flixel::FlxSubState::destroy();
} 