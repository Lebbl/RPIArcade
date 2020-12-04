# RPIArcade v1.0
RPI Arcade with Arduino Uno LED controls and Arduino Leonardo microcontrollers

Have you ever wanted to play Pac-Man or classic fighting games with retro arcade controls? Now you can! This is a portable, 2 player, arcade that runs on an RPI and is controlled by Arduinos. You can play plenty of awesome classic games solo or with friends. Plus, all the electronics(minus the mointor) can fit inside the box making it decently portable. It has adjustable LED buttons with 4 different modes: ON, adjustable brightness via potentiometer, buttons that flash if any are pressed, and OFF. The LEDs are controlled by an Arduino UNO. On the other hand, I use an Arduino Leonardo and the "Keyboard.h" library instead of a generic controller boards for easily customizeable microcontrollers. The "RetroPie" emulator that I am running on the RPI recognizes keystrokes, but if you wanted to use this with other emulators or with Steam games that are not optimized for keyboard, there is also a gamepad library that you can find here: https://github.com/MHeironimus/ArduinoJoystickLibrary.
![](img/20201204_154357.jpg)
![](img/20201204_154429.jpg)
# What you will need:
|Electronics|:
RPI (model # from 2-4),
Arduino Uno (2x for 2 player version),
Arduino Leonardo (2X for 2 player version),
MDF planks,
10-20 LED arcade buttons,
1-2 joysticks,
~ 50 male to male jumper wires,
Breadboard,
Micro HDMI cable,
Monitor,
USB stick,
SD card(micro for RPI 3-4)
|Box/container|:
Box material(such as mdf planks),
Spade bit that matches button size,
2 spring loaded latches,
Wood glue,
1 inch screws,
¼ inch screws
|Optional|:
Speakers,
Male to male audio jack

|Dependencies|:
RetroPie Emulator: https://retropie.org.uk/,
Arduino IDE 1.8.13: https://www.arduino.cc/en/software,
ROMs: Can be legally obtained from the src files, or downloaded from the internet, of games YOU OWN or can no longer be purchased. 


