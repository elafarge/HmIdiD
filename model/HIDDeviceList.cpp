/*
 * =====================================================================================
 *
 *       Filename:  HIDDeviceList.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2014 13:48:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "HIDDeviceList.hpp"

#include <iostream>

HIDDeviceList::HIDDeviceList() : mDevices(){
    struct hid_device_info *cDev;
        
    mApiDevices = hid_enumerate(0x0, 0x0);

    for(cDev = mApiDevices; cDev; cDev = cDev->next){
        if(cDev->serial_number && !cDev->product_string){
            std::cout << "One device hasn't been opened because the current user doesn't have permission to access it." << std::endl;
        } else {
            mDevices.push_back(HIDDevice(cDev));
        }
    }

}

HIDDeviceList::~HIDDeviceList(){
    hid_free_enumeration(mApiDevices);
}

void HIDDeviceList::description(){
    std::cout << "### List of the available HID Devices ###" << std::endl << std::endl;

    std::vector<HIDDevice>::iterator i;

    for(i = this->mDevices.begin(); i != this->mDevices.end(); ++i){
        i->description();
        std::cout << std::endl;
    }

    std::cout << std::endl;
}


HIDDevice HIDDeviceList::getDevice(unsigned short vid, unsigned short pid){
    std::vector<HIDDevice>::iterator i;
    for(i = this->mDevices.begin(); i != this->mDevices.end(); ++i){
        if(i->getVendorId() == vid && i->getProductId() == pid)
            return *i;
    }

}

HIDDevice HIDDeviceList::getDevice(std::string path){
    std::vector<HIDDevice>::iterator i;
    for(i = this->mDevices.begin(); i != this->mDevices.end(); ++i){
        if(i->getPath() == path)
            return *i;
    }
    return nullptr;
}

std::vector<HIDDevice> HIDDeviceList::getAvailableDevices(){
    return this->mDevices;
}
