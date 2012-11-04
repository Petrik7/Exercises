/*
 * Mutex.h
 *
 *  Created on: Nov 2, 2012
 *      Author: peter
 */

#ifndef MUTEX_H_
#define MUTEX_H_

#include <pthread.h>

namespace multithreading
{

class Mutex
{
public:
	Mutex();
	virtual ~Mutex();
	void Lock();

private:
	pthread_mutex_t _mutex;


};

}

#endif /* MUTEX_H_ */
