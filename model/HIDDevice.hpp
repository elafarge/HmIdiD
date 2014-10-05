/*
 * =====================================================================================
 *
 *       Filename:  HIDDevice.hpp
 *
 *    Description:  Describes a standard HID Device
 *
 *        Version:  1.0
 *        Created:  10/08/2014 13:33:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef HIDDEVICE_HPP
#define HIDDEVICE_HPP

#ifndef nullptr
#define nullptr NULL
#endif

#include <string>
#include <vector>
#include <hidapi/hidapi.h>

#include "HIDControl.hpp"

class HIDDevice {
    private:
        const struct hid_device_info *mApiInfo;
        hid_device *mApiDevice;

        unsigned char * mLastReport;
        unsigned short mLastReportSize;

        std::vector<HIDControl*> mControls;

    public:
        HIDDevice(const hid_device_info* deviceInfo);
        ~HIDDevice();

        /**
         * Opens a device
         */
        void open();

        /**
         * Reads a report from the device
         */
        bool read();

        /**
         * Update all the attached devices
         */
        void updateControls();

        void description();

        /* Controls management methods  */
        void addControl(HIDControl* c);
        bool removeControl(const HIDControl* c);

        /* Getters and Setters  */
        unsigned short getVendorId() const;
        unsigned short getProductId() const;
        std::string getPath() const;
        unsigned char * getLastReport() const;
        unsigned short getLastReportSize() const ;
        std::vector<HIDControl*> getControls() const;
};

#endif
