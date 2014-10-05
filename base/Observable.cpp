/*
 * =====================================================================================
 *
 *       Filename:  Observable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/08/2014 23:40:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Etienne LAFARGE (), etienne.lafarge@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Observable.hpp"

Observable::Observable() : obs(){

}

void Observable::addObserver(Observer* o){
    this->obs.push_back(o);
}

void Observable::removeObserver(Observer* o){
    this->obs.remove(o);
}

void Observable::notifyObservers(){
    for(std::list<Observer*>::iterator i = obs.begin(); i != obs.end(); ++i){
        (*i)->update();
    }
}
