#pragma once

#include "FlxBasic.h"
#include <vector>
#include <memory>

namespace flixel {

class FlxState {
public:
    FlxState() = default;
    virtual ~FlxState() = default;

    virtual void create() = 0;
    virtual void update(float elapsed);
    virtual void draw();
    virtual void destroy();

    void add(FlxBasic* object);
    void remove(FlxBasic* object, bool destroy = true);
    void clear(bool destroy = true);

protected:
    std::vector<FlxBasic*> members;
};

}