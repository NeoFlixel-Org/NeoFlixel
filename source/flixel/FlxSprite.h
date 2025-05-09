#pragma once

#include "FlxBasic.h"
#include <SDL2/SDL.h>

namespace flixel {

class FlxSprite : public FlxBasic {
public:
    FlxSprite(float x = 0, float y = 0);
    virtual ~FlxSprite();

    void loadGraphic(const std::string& path);
    void loadGraphic(SDL_Texture* texture);

    void setScale(float x, float y);
    void setScale(float scale);
    float getScaleX() const { return scaleX; }
    float getScaleY() const { return scaleY; }

    void updateHitbox();
    void centerOffsets(bool adjustPosition = false);
    void centerOrigin();

    void draw() override;

    void destroy() override;

    float width = 0;
    float height = 0;
    float offsetX = 0;
    float offsetY = 0;
    float originX = 0;
    float originY = 0;

protected:
    SDL_Texture* texture = nullptr;
    SDL_Rect sourceRect = {0, 0, 0, 0};
    SDL_Rect destRect = {0, 0, 0, 0};
    float scaleX = 1.0f;
    float scaleY = 1.0f;
};

}