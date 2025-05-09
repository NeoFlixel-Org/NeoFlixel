#include "FlxSprite.h"
#include "FlxG.h"

namespace flixel {

FlxSprite::FlxSprite(float x, float y) {
    this->x = x;
    this->y = y;
}

FlxSprite::~FlxSprite() {
    destroy();
}

void FlxSprite::loadGraphic(const std::string& path) {
    texture = FlxG::loadTexture(path);
    
    SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);
    destRect.w = sourceRect.w;
    destRect.h = sourceRect.h;
    
    width = static_cast<float>(sourceRect.w);
    height = static_cast<float>(sourceRect.h);
    centerOrigin();
}

void FlxSprite::loadGraphic(SDL_Texture* newTexture) {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    
    texture = newTexture;
    
    SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);
    destRect.w = sourceRect.w;
    destRect.h = sourceRect.h;
    
    width = static_cast<float>(sourceRect.w);
    height = static_cast<float>(sourceRect.h);
    centerOrigin();
}

void FlxSprite::setScale(float x, float y) {
    scaleX = x;
    scaleY = y;
    updateHitbox();
}

void FlxSprite::setScale(float scale) {
    scaleX = scale;
    scaleY = scale;
    updateHitbox();
}

void FlxSprite::updateHitbox() {
    width = std::abs(scaleX) * static_cast<float>(sourceRect.w);
    height = std::abs(scaleY) * static_cast<float>(sourceRect.h);
    
    offsetX = -0.5f * (width - static_cast<float>(sourceRect.w));
    offsetY = -0.5f * (height - static_cast<float>(sourceRect.h));
    
    centerOrigin();
}

void FlxSprite::centerOffsets(bool adjustPosition) {
    offsetX = (static_cast<float>(sourceRect.w) - width) * 0.5f;
    offsetY = (static_cast<float>(sourceRect.h) - height) * 0.5f;
    
    if (adjustPosition) {
        x += offsetX;
        y += offsetY;
    }
}

void FlxSprite::centerOrigin() {
    originX = static_cast<float>(sourceRect.w) * 0.5f;
    originY = static_cast<float>(sourceRect.h) * 0.5f;
}

void FlxSprite::draw() {
    if (!texture || !visible) return;

    destRect.x = static_cast<int>(x + offsetX);
    destRect.y = static_cast<int>(y + offsetY);
    destRect.w = static_cast<int>(sourceRect.w * scaleX);
    destRect.h = static_cast<int>(sourceRect.h * scaleY);

    SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
    SDL_SetTextureAlphaMod(texture, static_cast<Uint8>(alpha * 255));

    SDL_RenderCopyEx(
        FlxG::renderer,
        texture,
        &sourceRect,
        &destRect,
        angle,
        nullptr,
        SDL_FLIP_NONE
    );
}

void FlxSprite::destroy() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

}