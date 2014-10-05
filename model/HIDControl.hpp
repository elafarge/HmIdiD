/*
 * =====================================================================================
 *
 *       Filename:  HIDControl.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/08/2014 22:40:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef HID_CONTROL_HPP
#define HID_CONTROL_HPP

#include <string>
#include "../base/Observable.hpp"

class HIDControl : public Observable {
    private:
        std::string mName;
        unsigned char mMask;
        unsigned char mOffset;
        unsigned char mLSBFactor;
        unsigned char mMSBFactor;
        unsigned char mRatio;

        unsigned char mValue;
        
    public:
        HIDControl(std::string name, unsigned char mask, unsigned char offset);
        HIDControl(std::string name, unsigned char mask, unsigned char offset, unsigned char ratio);

        void setByteValue(unsigned char value);

        /* Getters and setters */
        unsigned char getValue();
        std::string getName();
        void setName(std::string name);
        unsigned char getMask();
        void setMask(unsigned char mask);
        unsigned char getOffset();
        void setOffset(unsigned char offset);
        unsigned char getLSBFactor();
        unsigned char getMSBFactor();
};

#endif
