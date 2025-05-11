#pragma once

#include <string>
#include "flixel/FlxState.h"
#include "flixel/FlxSprite.h"
#include "flixel/text/FlxText.h"
#include "flixel/sound/FlxSound.h"

class PlayState : public flixel::FlxState {
public:
    PlayState() = default;
    ~PlayState() override = default;

    void create() override;
    void update(float elapsed) override;
    void draw() override;
    void destroy() override;

private:
    flixel::FlxSprite* player = nullptr;
    flixel::FlxText* positionText = nullptr;
    flixel::FlxSound* bgMusic = nullptr;
};