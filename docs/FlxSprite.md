# FlxSprite

## Creating and Loading a sprite

```cpp
flixel::FlxSprite* sprite = new flixel::FlxSprite(100, 100); // x and y pos
sprite->loadGraphic("assets/player.png"); // loading the .png asset
```

## Scaling the sprite and updating the hitbox

```cpp
sprite->setScale(0.2f, 0.2f); // scaling the sprite's x and y values

sprite->updateHitbox(); // update da hitbox

sprite->centerOffsets(); // center da hitbox relative to the sprite

sprite->centerOrigin(); // center da rotation origin
```

## Spritesheet and xml animations template

```cpp
// create func
std::ifstream file("assets/images/BOYFRIEND.xml");
std::stringstream buffer;
buffer << file.rdbuf();
std::string xmlText = buffer.str();
auto frames = flixel::graphics::frames::FlxAtlasFrames::fromSparrow("assets/images/BOYFRIEND.png", xmlText);
player = new flixel::FlxSprite(100, 100);
player->loadGraphic("assets/images/BOYFRIEND.png");
player->frames = frames;
player->animation = new flixel::animation::FlxAnimationController();
player->animation->addByPrefix("idle", frames->getFramesByPrefix("BF idle dance"), 24, true);
player->animation->play("idle");
add(player);

// update func
if (player->animation) {
    player->animation->update(elapsed);
}

// destroy func
if (player) {
    remove(player, true);
    delete player->animation;
    player = nullptr;
}
```

## Adding the sprite

```cpp
add(sprite); // adds the sprite to the state, duhh
```