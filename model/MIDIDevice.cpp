/*
 * =====================================================================================
 *
 *       Filename:  MIDIDevice.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/10/2014 21:58:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "MIDIDevice.hpp"

MIDIDevice::MIDIDevice(std::string name) : mName(name){
    mMidiOut = new RtMidiOut(RtMidi::LINUX_ALSA, mName);
    mMidiOut->openPort(0, mName);

    mMidiIn = new RtMidiIn(RtMidi::LINUX_ALSA, mName);
    mMidiIn->openPort(0);
    mMidiIn->ignoreTypes(false, false, false);
    mMidiIn->setCallback(&MIDIDevice::inputCallback);
}

MIDIDevice::~MIDIDevice(){
    if(mMidiOut->isPortOpen())
        mMidiOut->closePort();
    if(mMidiIn->isPortOpen())
        mMidiIn->closePort();
    delete mMidiOut;
    delete mMidiIn;
    
}

void MIDIDevice::sendMessage(std::vector<unsigned char> & subMessage){
    std::vector<unsigned char> message;
    message.push_back(176); //Channel 0
    message.insert(message.end(), subMessage.begin(), subMessage.end());
    mMidiOut->sendMessage(&message);
}

void MIDIDevice::inputCallback(double deltatime, std::vector<unsigned char> *message, void* midiDevice){
    /* printf("Midi Input Message (%s) to send to the HID Device : \n", ((MIDIDevice*) midiDevice)->getName());
    unsigned int nBytes = message->size();
    for(unsigned int i = 0; i < nBytes; i++){
        printf("%x ", (int)message->at(i));
    }
    if(nBytes > 0)
        printf(";; D = %f \n", deltatime);*/

}

