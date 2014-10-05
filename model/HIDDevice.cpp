/*
 * =====================================================================================
 *
 *       Filename:  HIDDevice.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2014 13:44:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include "HIDDevice.hpp"


HIDDevice::HIDDevice(const hid_device_info *deviceInfo) : mApiInfo(deviceInfo), mApiDevice(nullptr), mLastReport(nullptr), mLastReportSize(0), mControls(){
    
}

HIDDevice::~HIDDevice(){

}

void HIDDevice::open(){
    mApiDevice = hid_open(this->mApiInfo->vendor_id, this->mApiInfo->product_id, nullptr);

    if(mApiDevice == NULL)
        std::cout << "Coucou tu veux voir ma bite !" << std::endl;
}

bool HIDDevice::read(){
    unsigned char* buffer = new unsigned char[255];
    int i = hid_read(mApiDevice, buffer, 255);
    if(i > 0){
         if(mLastReportSize > 0)
            delete[] mLastReport;
        mLastReport = new unsigned char[i];
        mLastReportSize = i;
        for(int j = 0; j < i; ++j)
            mLastReport[j] = buffer[j];
        return true;
    }
    return false;
}

void HIDDevice::updateControls(){
    for(std::vector<HIDControl*>::iterator i = mControls.begin(); i != mControls.end(); ++i){
        if((*i)->getOffset() < mLastReportSize)
            (*i)->setByteValue(mLastReport[(*i)->getOffset()]);
    } 
}

void HIDDevice::description(){
    std::cout << "############## HID DEVICE ##############" << std::endl;
    std::wcout << this->mApiInfo->manufacturer_string << " - " << this->mApiInfo->product_string << std::endl;
    std::wcout << "Serial No : " << this->mApiInfo->serial_number << std::endl;
    std::cout << "Release Number : " << this->mApiInfo->release_number << std::endl;
    std::cout << "Interface No : " << this->mApiInfo->interface_number << std::endl;
    std::cout << "Path : " << this->mApiInfo->path << std::endl;
    std::cout << "Vendor ID : " << this->mApiInfo->vendor_id << "  Product Id : " << this->mApiInfo->product_id << std::endl;
    std::cout << "Usage : " << this->mApiInfo->usage_page << " - Usage " << this->mApiInfo->usage << std::endl;
    std::cout << "########################################" << std::endl;
}

void HIDDevice::addControl(HIDControl* c){
    mControls.push_back(c);
}

bool HIDDevice::removeControl(const HIDControl* c){
   for(std::vector<HIDControl*>::iterator i = mControls.begin(); i != mControls.end(); ++i){
       if(*i == c){
            mControls.erase(i);
            return true;
       }
   } 
   return false;
}

unsigned short HIDDevice::getVendorId() const{
    return this->mApiInfo->vendor_id;
}


unsigned short HIDDevice::getProductId() const{
    return this->mApiInfo->product_id;
}

std::string HIDDevice::getPath() const{
    return this->mApiInfo->path;
}

unsigned char* HIDDevice::getLastReport() const{
    return this->mLastReport;
}

unsigned short HIDDevice::getLastReportSize() const{
    return this->mLastReportSize;
}

std::vector<HIDControl*> HIDDevice::getControls() const{
    return mControls;
}
