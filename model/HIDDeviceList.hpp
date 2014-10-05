/*
 * =====================================================================================
 *
 *       Filename:  HIDDeviceList.hpp
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

#ifndef HID_DEVICE_LIST_HPP
#define HID_DEVICE_LIST_HPP

#ifndef nullptr
#define nullptr NULL
#endif

#include <string>
#include <hidapi/hidapi.h>
#include <vector>
#include "HIDDevice.hpp"

class HIDDeviceList {
    private:
        // List of all available HIDDevice
        std::vector<HIDDevice> mDevices;

        // Same list but using the HIDapi classes
        struct hid_device_info *mApiDevices;
    
    public:
        /**
         * Lists all the HID devices wired to the kernel and create
         * corresponding hid device entries (without starting them):
         */
        HIDDeviceList();

        /**
         * Frees the resources used by the list of HID Devices
         */
        ~HIDDeviceList();

        /**
         * Prints a list of the available devices on the standard output
         */
        void description();

        /**
         * Returns an HIDDevice object matching the vendor ID and product ID
         */
        HIDDevice getDevice(unsigned short vid, unsigned short pid);

        /**
         * Returns an HIDDevice object matching the path
         */
        HIDDevice getDevice(std::string path);

        /**
         * Returns the list of the HID devices detected on the computer (copied)
         */
         std::vector<HIDDevice> getAvailableDevices();

};

#endif
