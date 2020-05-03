# Arduino UNO on MAME - WIP branch

## Build

```
make -j8 SUBTARGET=kanon SOURCES=src/mame/drivers/vgmduino.cpp
```

```
./kanon64 kanon -window -resolution0 1024x768
```

## Files

```
src/devices/cpu/avr8/avr8.cpp
src/devices/cpu/avr8/avr8.h
src/mame/drivers/vgmduino.cpp
roms/kanon.zip
```

## Target Arduino UNO and apps

https://github.com/h1romas4/arduino-vgmplayer

## Demo

[![mame-arduino-ym2151](https://raw.githubusercontent.com/h1romas4/arduino-vgmplayer/master/assets/mame-emurate-work-in-progress01.png
)](https://youtu.be/7sPtBW2uDG8)
