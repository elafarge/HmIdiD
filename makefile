# MakeFile for HmIdiD
# 
# Author : Etienne LAFARGE (generated by hand)
# Email : etienne.lafarge@gmail.com
#
# Any comment/improvement idea for this Makefile is welcomed,
# Especially concerning ways to hande cross-compilation and
# different environments (DEBUG / RELEASE + WIN / MAC / LINUX)
# is welcomed. Feel free to write me an email.
#

vpath %.h /usr/local/include
vpath %.a /usr/local/lib
vpath %.so /usr/local/lib
vpath %.la /usr/local/lib


all: hmidid

hmidid: build/HIDDeviceList.o build/HIDDevice.o build/HIDControl.o build/MIDIDevice.o build/MIDIControl.o build/Observable.o build/main.o 
	gcc  -o hmidid -lhidapi-hidraw -lrtmidi  build/MIDIDevice.o build/MIDIControl.o build/HIDDeviceList.o build/HIDDevice.o build/HIDControl.o build/Observable.o build/main.o -lstdc++ 


build/main.o: main.cpp
	gcc -o build/main.o -c main.cpp 


build/HIDDeviceList.o: model/HIDDeviceList.cpp 
	gcc -o build/HIDDeviceList.o -c model/HIDDeviceList.cpp 


build/HIDDevice.o: model/HIDDevice.cpp
	gcc -o build/HIDDevice.o -c model/HIDDevice.cpp 

build/HIDControl.o: model/HIDControl.cpp build/Observable.o
	gcc -o build/HIDControl.o -c model/HIDControl.cpp

build/MIDIControl.o: model/MIDIControl.cpp
	gcc -o build/MIDIControl.o -c model/MIDIControl.cpp

build/MIDIDevice.o: model/MIDIDevice.cpp
	gcc -o build/MIDIDevice.o -c model/MIDIDevice.cpp

build/Observable.o: base/Observable.cpp
	gcc -o build/Observable.o -c base/Observable.cpp

clean:
	rm build/HIDControl.o build/MIDIControl.o build/MIDIDevice.o build/Observable.o build/HIDDeviceList.o build/HIDDevice.o build/main.o hmidid


