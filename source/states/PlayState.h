#pragma once

#include "flixel/FlxState.h"

class PlayState : public flixel::FlxState {
public:
    PlayState() = default;
    ~PlayState() override = default;

    void create() override;
    void update(float elapsed) override;
    void draw() override;
    void destroy() override;
}; 