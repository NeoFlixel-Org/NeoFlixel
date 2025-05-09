# FlxSprite

## FlxState base

```cpp
// YourStateName.h
#pragma once

#include "flixel/FlxState.h"

class YourStateName : public flixel::FlxState {
public:
    YourStateName() = default;
    ~YourStateName() override = default;

    void create() override;
    void update(float elapsed) override;
    void draw() override;
    void destroy() override;

private:
}; 
```

```cpp
// YourStateName.cpp
#include "YourStateName.h"
#include "flixel/FlxG.h"

void YourStateName::create() {
    std::cout << "YourStateName: Create Function Called!" << std::endl;
}

void YourStateName::update(float elapsed) {
    FlxState::update(elapsed);
}

void YourStateName::draw() {
    FlxState::draw();
}

void YourStateName::destroy() {
    FlxState::destroy();
} 
```