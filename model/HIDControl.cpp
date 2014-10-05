/*
 * =====================================================================================
 *
 *       Filename:  HIDControl.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/08/2014 23:26:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "HIDControl.hpp"
#include <iostream>

HIDControl::HIDControl(std::string name, unsigned char mask, unsigned char offset, unsigned char ratio) : mName(name), mMask(mask), mOffset(offset), mValue(0), mRatio(ratio){
    this->setMask(mask);
}

HIDControl::HIDControl(std::string name, unsigned char mask, unsigned char offset) : mName(name), mMask(mask), mOffset(offset), mValue(0), mRatio(1){
    this->setMask(mask);
}


void HIDControl::setByteValue(unsigned char value){
    unsigned char newValue = (value & this->mMask) / mLSBFactor / mRatio;
    if(newValue != mValue){
        mValue = newValue; // The weird operation uses unsigned char overflow to keep only the value defined by the mask
        this->notifyObservers();
    }
}


std::string HIDControl::getName(){
    return mName;
}

void HIDControl::setName(std::string name){
    mName = name;
}

unsigned char HIDControl::getMask(){
    return mMask;
}

void HIDControl::setMask(unsigned char mask){
    if(mask == 0)
        std::cout << "Null mask cannot describe a fader" << std::endl;
    //Here we process the first non zero bit of the mask number to figure out where the least significqnt bit of our value is
    unsigned char movingMask = mask;
    unsigned char factor = 1;
    while(movingMask % 2 != 1 && mask != 0)
        factor *= 2;

    mLSBFactor = factor;

    //Same for the mostly significant bit of the mask
    movingMask = mask;
    factor = 1;
    while((movingMask / 128) % 2 != 1 && movingMask != 128)
        factor *= 2;
    mMSBFactor = factor;
}

unsigned char HIDControl::getOffset(){
    return mOffset;
}

void HIDControl::setOffset(unsigned char offset){
    mOffset = offset;
}

unsigned char HIDControl::getValue(){
    return mValue;
}

unsigned char HIDControl::getLSBFactor(){
    return mLSBFactor;
}

unsigned char HIDControl::getMSBFactor(){
    return mMSBFactor;
}

