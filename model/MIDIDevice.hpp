/*
 * =====================================================================================
 *
 *       Filename:  MIDIDevice.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/10/2014 21:32:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef MIDIDEVICE_HPP
#define MIDIDEVICE_HPP

#ifndef nullptr
#define nullptr NULL
#endif

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

#include <RtMidi.h>


class MIDIDevice{
    private:
        std::string mName;
        
        RtMidiIn* mMidiIn;
        RtMidiOut* mMidiOut;

    public:
        MIDIDevice(std::string name);
        ~MIDIDevice();

        void sendMessage(std::vector<unsigned char>& subMessage);

        static void inputCallback(double deltatime, std::vector<unsigned char> *message, void* midiDevice);
        
        std::string getName();

};

#endif
