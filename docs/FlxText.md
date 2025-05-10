# FlxSprite

## Creating and setting the FlxText

```cpp
flixel::FlxText text(100, 100, 200, "No way im documenting it...", 16); // x, y, field width, text, and font size
```

## Setting the font and style

```cpp
text.setFont("assets/fonts/yourfont.ttf"); // path to ur font, true type font only
text.setBold(true); // sets ur font bold or not
text.setColor(0xFFFFFFFF); // White color (HEX), reminder to reimplement FlxColor and use that instead :3
text.setBorderStyle(flixel::FlxTextBorderStyle::SHADOW, {0, 0, 0, 255}, 2.0f); // shadow the hedgehog, can use NONE, SHADOW, SHADOW_XY, OUTLINE and OUTLINE_FAST
text.setAlignment(flixel::FlxTextAlign::CENTER); // allignment, can use LEFT, CENTER, RIGHT, or JUSTIFY
```

## Setting the text in the center

```cpp
text->screenCenter(); // Center both X and Y (default behavior)
text->screenCenter(util::FlxAxes::X); // Center only X
text->screenCenter(util::FlxAxes::Y); // Center only Y
```

## adding the text

```cpp
add(text); // adds the text to the state, duhh
```