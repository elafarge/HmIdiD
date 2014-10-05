/*
 * =====================================================================================
 *
 *       Filename:  MIDIControl.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/10/2014 22:05:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef MIDICONTROL_HPP
#define MIDICONTROL_HPP

#include "../base/Observable.hpp"
#include "HIDControl.hpp"
#include "MIDIDevice.hpp"

class MIDIControl : public Observer{
    private:
        unsigned char mNumber; //Midi control (CC) number
        MIDIDevice* mDevice; //Parent device
        HIDControl* mHIDControl;

    protected:
        void update();

    public:
        MIDIControl(unsigned char number, MIDIDevice* device, HIDControl* control);

};

#endif
