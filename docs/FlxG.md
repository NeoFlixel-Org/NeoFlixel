# FlxG

## Showing/Hiding the cursor

```cpp
FlxG::showCursor(false); // true to show, false to hide, duh
```

## Setting the cursor (setting a custom cursor image)

```cpp
FlxG::setCursor("assets/images/ur_cursor.png", 0, 0);
```

## Input

Use [SDL2's wiki page for scancodes](https://wiki.libsdl.org/SDL2/SDL_Scancode)

```cpp
flixel::FlxG::keys.pressed().count(SDL_SCANCODE_LEFT) // pressed
flixel::FlxG::keys.justPressed().count(SDL_SCANCODE_LEFT) // justPressed
flixel::FlxG::keys.justReleased().count(SDL_SCANCODE_LEFT) // justReleased
```