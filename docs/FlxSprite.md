# FlxSprite

## Creating and Loading a sprite

```cpp
FlxSprite* sprite = new FlxSprite(100, 100); // x and y pos
sprite->loadGraphic("assets/player.png"); // loading the .png asset
```

## Scaling the sprite and updating the hitbox

```cpp
sprite->setScale(0.2f, 0.2f); // scaling the sprite's x and y values

sprite->updateHitbox(); // update da hitbox

sprite->centerOffsets(); // center da hitbox relative to the sprite

sprite->centerOrigin(); // center da rotation origin
```

## Adding the sprite

```cpp
add(sprite); // adds the sprite to the state, duhh
```