/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/08/2014 00:53:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdio>

#include "model/HIDDeviceList.hpp"
#include "model/HIDDevice.hpp"
#include "model/HIDControl.hpp"
#include "model/MIDIDevice.hpp"
#include "model/MIDIControl.hpp"

#include <RtMidi.h>

#ifndef nullptr
#define nullptr NULL
#endif

class Mapper{
    public:
        Mapper(){
            HIDDeviceList devList;
            HIDDevice mk2 = devList.getDevice("/dev/hidraw1");
            mk2.open();

            //We take all the Faders from the MK2
            HIDControl kALow("A-Low", 255, 9, 2);
            HIDControl kAMid("A-Mid", 255, 10, 2);
            HIDControl kAHigh("A-High", 255, 11, 2);
            HIDControl kAPitch("A-Pitch", 255, 15, 2);
            HIDControl kAJog("A-Jogwheel", 255, 17, 2);
            HIDControl kAMaster("A-Master", 255, 13, 2);
            
            HIDControl kBLow("B-Low", 255, 6, 2);
            HIDControl kBMid("B-Mid", 255, 7, 2);
            HIDControl kBHigh("B-High", 255, 8, 2);
            HIDControl kBPitch("B-Pitch", 255, 16, 2);
            HIDControl kBJog("B-Jogwheel", 255, 18, 2);
            HIDControl kBMaster("B-Master", 255, 14, 2);

            mk2.addControl(&kALow);
            mk2.addControl(&kAMid);
            mk2.addControl(&kAHigh);
            mk2.addControl(&kAPitch);
            mk2.addControl(&kAJog);
            mk2.addControl(&kAMaster);
            
            mk2.addControl(&kBLow);
            mk2.addControl(&kBMid);
            mk2.addControl(&kBHigh);
            mk2.addControl(&kBPitch);
            mk2.addControl(&kBJog);
            mk2.addControl(&kBMaster);

            //Now that all the HID Faders are digged out we assign them to a MIDI Control
            MIDIDevice midiMk2("Hercules Mk2");
            
            MIDIControl mc1(1, &midiMk2, &kALow);
            MIDIControl mc2(2, &midiMk2, &kAMid);
            MIDIControl mc3(3, &midiMk2, &kAHigh);
            MIDIControl mc4(4, &midiMk2, &kAPitch);
            MIDIControl mc5(5, &midiMk2, &kAJog);
            MIDIControl mc6(7, &midiMk2, &kAMaster);

            MIDIControl mc11(11, &midiMk2, &kBLow);
            MIDIControl mc12(12, &midiMk2, &kBMid);
            MIDIControl mc13(13, &midiMk2, &kBHigh);
            MIDIControl mc14(14, &midiMk2, &kBPitch);
            MIDIControl mc15(15, &midiMk2, &kBJog);
            MIDIControl mc16(74, &midiMk2, &kBMaster);

            //Now everything is supposed to be completely wired let's trigger the listening loop
            while(true){
                if(mk2.read()){
                    mk2.updateControls();
                }
            }

        }

};

int main(int argc, char** argv){

    Mapper m;

    /* HIDDeviceList devList;
    devList.description();

    std::cout << "Trying to connect to the Hercules Mk2" << std::endl;

    HIDDevice mk2 = devList.getDevice("/dev/hidraw1");

    mk2.open();

    unsigned char* buffer = nullptr;
    unsigned short s = 0;

    HIDControl f("bite", 255, 9);
    
    mk2.addControl( &f );

    MainObserver midiControl(&f);

    while(true){
        if(mk2.read()){
            mk2.updateControls();

             buffer = mk2.getLastReport();
            s = mk2.getLastReportSize();

            f.setByteValue(buffer[f.getOffset()]);

            for(unsigned short i = 0; i < s; ++i){
                printf("%x ", buffer[i]);
            }

            printf(" ----> %x", f.getValue());
            std::cout << std::endl;

        } else
            printf("AAaargh");
    }*/

    return 0;
}


/* 
class MainObserver : public Observer{
    
    private:
        RtMidiOut* mMidiOut;
        RtMidiIn*  mMidiIn;
        HIDControl* mControl;

    public:
        MainObserver(HIDControl* control) : mControl(control){
            mMidiOut = new RtMidiOut(RtMidi::LINUX_ALSA, "Hercules Mk2");
            mMidiOut->openPort(0, "Hercules Mk2");

            mMidiIn = new RtMidiIn();
            mMidiIn->openPort(0);
            mMidiIn->setCallback(&MainObserver::callback);
            mMidiIn->ignoreTypes(false, false, false);

            mControl->addObserver(this);
        }

        ~MainObserver(){
            if(mMidiOut->isPortOpen())
                mMidiOut->closePort();
            delete mMidiOut;
            if(mMidiIn->isPortOpen())
                mMidiIn->closePort();
            delete mMidiIn;
        }

        static void callback(double deltatime, std::vector<unsigned char> *message, void *userData){
            unsigned int nBytes = message->size();
            for(unsigned int i = 0; i < nBytes; i++){
                printf("%x ", (int)message->at(i));
            }
            if(nBytes > 0)
                printf(";; D = %f \n", deltatime);
        }

    protected:
        void update(){
            std::vector<unsigned char> message;
            message.push_back(176); //Channel 0
            message.push_back(8); //Control 0
            message.push_back(mControl->getValue()/2); //put here a value between 0 and 128
            mMidiOut->sendMessage( &message );
            printf(" ----> %d \n", mControl->getValue()/2);
        }
}; */


