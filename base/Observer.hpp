/*
 * =====================================================================================
 *
 *       Filename:  Observer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/08/2014 23:29:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "Observable.hpp"

class Observer{

    friend class Observable;
    
    protected:
        virtual void update() = 0;
};

#endif
