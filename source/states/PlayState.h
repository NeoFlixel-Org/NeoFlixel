#pragma once

#include "flixel/FlxState.h"
#include "flixel/FlxSprite.h"

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
}; 