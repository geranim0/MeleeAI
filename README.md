# MeleeAI

1) Build dolphin with https://wiki.dolphin-emu.org/index.php?title=Building_Dolphin_on_Linux

2) Build MeleeAi
    2.0) cd to your destination folder and hit: git clone https://github.com/luckycharms14/MeleeAI.git
    2.1) mkdir build
    2.2) cd source
    2.3) open PipeController.cpp and replace PipePath by your directory (mine was /root/.local/share/dolphin-emu/Pipes/                   pipe)   
    2.4) open SocketGameState.hpp and replace the path by yours, mine was /root/.config/dolphin-emu/MemoryWatcher/  MemoryWatcher (you have to create the 2 memorywatcher folders)
    2.5) cd to your Pipes directory and hit: mkfifo pipe
    2.6) cd to /MeleeAI/AI and hit make

3) set up the pipe
    3.1) cd to your dolphin  gcpad directory , mine was /root/.config/dolphin-emu/Profiles/GCPad/
    3.2) create a file name pipe.ini and paste this into it

[Profile]
Device = Pipe/0/pipe
Buttons/A = `Button A`
Buttons/B = `Button B`
Buttons/X = `Button X`
Buttons/Y = `Button Y`
Buttons/Z = `Button Z`
Buttons/Start = `Button START`
Main Stick/Up = `Axis MAIN Y +`
Main Stick/Down = `Axis MAIN Y -`
Main Stick/Left = `Axis MAIN X -`
Main Stick/Right = `Axis MAIN X +`
C-Stick/Up = `Axis C Y +`
C-Stick/Down = `Axis C Y -`
C-Stick/Left = `Axis C X -`
C-Stick/Right = `Axis C X +`
Triggers/L = `Button L`
Triggers/R = `Button R`
Triggers/L-Analog = `Axis L +`
Triggers/R-Analog = `Axis R +`
D-Pad/Up = `Button D_UP`
D-Pad/Down = `Button D_DOWN`
D-Pad/Left = `Button D_LEFT`
D-Pad/Right = `Button D_RIGHT`

    3.3) open dolphin, go to controller configuration, put the 1st controller to your mayflash and the 2nd controller chose standard controller. click configure and chose pipe/0 in the device menu.
    3.4) load pipe.ini from the profile menu and click ok

4) run the AI?
