HmIdiD is intented to be a piece of software converting HID messages from any HID Device to MIDI Messages. 

It is mostly intented to people who wish to use an HID device with a MIDI compliant Digital Audio Workstation. Indeed, some audio controllers do not provide a MIDI over USB output at all. Other need drivers which may be non existent on Linux or deprecated for the latest versions of Windows.

This project aims at providing a software able to replace these drivers regardless of the harware (as long as it uses HID to communicate, which is the case of most USB controllers, including a wide range gamepads and "DJ-controllers").

On the long term, this project is intended to be cross-platform (the HID and Midi toolkits I use are) and provide a simple GUI to analyse and map the HID messages to MIDI (for faders, pads, encoders, knobs and other inputs) and vice versa (for LEDs mostly). The mappings will be saved as JSON or XML.

At the moment, I made it work with the faders of my old Hercules Mk2 under Linux. Running it while the controller is plugged in (provided that its path is /dev/hidraw1, it can be changed in the main.cpp file of course) will create a virtual MIDI device and broadcast the fader status (when they change) over this device. Under Linux, if your DAW doesn't support virtual MIDI devices, you can use the ALSA virmidi module to create "fake" hardware midi devices you can connect to your DAW and then "plug" your virtual midi device into it using Jack or any other software midi router.

Requirements : 

HmIdiD uses the cross-platform HID Api (www.signal11.us/oss/hidapi/) and RtMidi (http://www.music.mcgill.ca/~gary/rtmidi/) to manage virtual MIDI devices. Make sure both are in installed in your include and lib path before trying to compile. I use a hand made makefile for compilation, the make and make clean routines should work out of the box.
