# FlxSound

## Playing a sound
```cpp
flixel::FlxG::sound.play("assets/sounds/yoursound.ogg"); // no way path to ur sound
```

## loading music

```cpp
FlxSound* music = flixel::FlxG::sound.load("assets/music/theme.ogg", true); // path, loop, autoDestroy (ogg, wav, and mp3)
music->set_volume(0.5f); // setting the music volume
music->play(); // playing da music
```

## stopping da sound

```cpp
flixel::FlxG::sound.stopAll(); // stops all soundz
```

## muting and unmutuing

```cpp
flixel::FlxG::sound.muted = true; // mutes or unmutes the sound
```