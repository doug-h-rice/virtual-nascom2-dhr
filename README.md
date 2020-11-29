Doug Rice's changes in 2017 and 2019 and 2020
=============================================
I first used the x11 version, but upgrades to UBUNTU broke this.

I installed SDL1.2 and got this to work on the raspberry Pi

This runs on UBUNTU 14 and Raspberry Pi

The PC version of RPi seems to use SDL1.2

Raspbarian stretch broke this so I got it to work with SDL2

I tried BUSTER and SDL2 and it now scales 1:2 so is easier to read.

I use #define SDL1 and #ifdef SDL1 to select between SDL1.2 and SDL2

I added a tape recorder.

This allows W, R and V commands

It always appends to the end of the tape serialout.bin. 

F6 rewinds so you can use V or R without restarting the program.

Use  shift-enter a few times get back control if you R or V at the end of the tape.

When this was working, Tommy independently posted similar updates which added similar functionality.

My updates have been to do with the tape, and loading .nas and .ihx format files.

I got the BLS pascal to work and you can save and reload to tape.

I changed serialout.txt to serialout.bin !

usage:
./virtual-nascom-sdl2 -i serialout.bin test.ihx

E1000 runs test.ihx

I like BLS Pascal so it tries to load it from same directory.

Tommy's README.md

Virtual Nascom, Version 1.10, 2017-05-10
========================================

This is a version 1.10 of Virtual Nascom, yet another Nascom 2
emulator.  There's emulation support for all(?) of the standard
hardware and it runs nearly all of the software on the
nascomhomepage.com (see KNOWN ISSUES below).

Version 1.9 switches from a (partially broken) X Window specific
implementation to portable and more more robust SDL implementation. It
also gained basic serial port support in the process.

Version 1.10 adds support for "natural" keyboard, that is, US keyboard
events are translated into the equivalent Nascom keycombination.

* Homepage: http://www.nascomhomepage.com

* Git repository: http://github.com/tommythorn/virtual-nascom.git


INSTALLATION
------------

Virtual Nascom should compile on all platform with SDL support, but
has only been tested on macOS (10.12.4 and older) and various Linux
versions.

To compile you may have to adapt the Makefile with the libraries you
need and their path, but generally it should be enough to simply run

    $ make

USAGE
-----

    Usage: ./virtual-nascom {flags} [NAS files]
               -i <file>       take serial port input from file (when tape led is on)
               -m <file>       use <file> as monitor (default is nassys3.nal)
               -v              verbose

Virtual Nascom expects to find `nassys.nal` (unless you changed the
monitor using the `-m` option) and `basic.nal` upon startup.  You can
add files to be loaded by providing them as arguments at the end of
the line.

For example to run *Pac Man*, run

    $ ./virtual-nnascom programs/e1000/pacman.nas

and type `E1000` in the Nascom 2 window. Control with arrow keys.

The emulator conveniently dumps the memory state in `memorydump.nas`
upon exit so one might resume execution later on.

The following keys are supported:

* END - leaves a screendump in `screendump`
* F4 - exits the emulator
* F5 - toggles between stupidly fast and "normal" speed
* F9 - resets the emulated Nascom
* F10 - toggles between "raw" and "natural" keyboard emulation

All serial output is appended to `serialout.txt` which may be fed back
in on a subsequent launch via the `-i` option.

CREDITS
-------

A very crucial part of Virtual Nascom is the excellent Z80 emulator
from Yaze, Copyright (C) 1995,1998  Frank D. Cringle.

Thanks to Dene Carter for encouragement


TODO
----

* Support pixel doubling

* Reconsider the name

* Clean up code and document; improve UI

* Allow for switching input and output file while running

* Precise timings (a rough, but machine independent job should be
  easily done)

* Emulate sound (requires precise timings)


KNOWN ISSUES
------------

* *Galaxy Attack* doesn't work on Virtual Nascom.  As it does work on
  VNASCOM it must be an emulation bug.
