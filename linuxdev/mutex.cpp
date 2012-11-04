/*
 * Mutex.cpp
 *
 *  Created on: Nov 2, 2012
 *      Author: peter
 */

#include "mutex.h"

namespace multithreading
{

Mutex::Mutex()
{
	_mutex = PTHREAD_MUTEX_INITIALIZER;
}

Mutex::~Mutex()
{
	pthread_mutex_unlock (&_mutex);
}

void Mutex::Lock()
{
	//pthread_mutex_lock (&_mutex);
	pthread_mutex_trylock(&_mutex);
}


}
