#pragma once

#include "flixel/FlxSubState.h"
#include "flixel/FlxSprite.h"
#include "flixel/text/FlxText.h"
#include "flixel/FlxG.h"

class TestSubState : public flixel::FlxSubState {
public:
    TestSubState();
    virtual ~TestSubState() = default;

    void create() override;
    void update(float elapsed) override;
    void destroy() override;

private:
    flixel::FlxSprite* testSprite;
    flixel::FlxText* testText;
    float timer;
    bool isClosing;
}; 