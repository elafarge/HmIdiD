/*
 * =====================================================================================
 *
 *       Filename:  MIDIControl.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/10/2014 22:05:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "MIDIControl.hpp"
#include <vector>
#include <cstdio>

MIDIControl::MIDIControl(unsigned char number, MIDIDevice* device, HIDControl* control) : mNumber(number), mDevice(device), mHIDControl(control){
    mHIDControl->addObserver(this);
    
}

void MIDIControl::update(){
    std::vector<unsigned char> subMessage;
    //Retrieve and set the value of the control to the appropriate CC MIDI message
    subMessage.push_back(mNumber);
    subMessage.push_back(mHIDControl->getValue());
    printf("CC %d --> %d \n", mNumber, mHIDControl->getValue());
    this->mDevice->sendMessage(subMessage); 
}

