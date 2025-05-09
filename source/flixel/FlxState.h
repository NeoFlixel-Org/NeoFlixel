#pragma once

namespace flixel {

class FlxState {
public:
    FlxState() = default;
    virtual ~FlxState() = default;

    virtual void create() = 0;
    virtual void update(float elapsed) = 0;
    virtual void draw() = 0;
    virtual void destroy() = 0;
};

}