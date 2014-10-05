/*
 * =====================================================================================
 *
 *       Filename:  Observable.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/08/2014 23:32:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <list>
#include "Observer.hpp"

class Observable{
    private:
        std::list<Observer*> obs;

    protected:
        void notifyObservers();

    public:
        Observable();
        void addObserver(Observer* o);
        void removeObserver(Observer* o);

};

#endif
