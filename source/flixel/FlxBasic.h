#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "../imports.h"

namespace flixel {

class FlxBasic {
public:
    FlxBasic() = default;
    virtual ~FlxBasic() = default;

    virtual void update(float elapsed) {}
    virtual void draw() {}
    virtual void destroy() {}

    bool active = true;
    bool visible = true;
    bool exists = true;

    float x = 0;
    float y = 0;

    float scaleX = 1.0f;
    float scaleY = 1.0f;

    float angle = 0.0f;

    float alpha = 1.0f;

    SDL_Color color = {255, 255, 255, 255};
};

}