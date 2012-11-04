#pragma once

#include <pthread.h>

namespace multithreading
{

class Thread
{
public:

	typedef void* (*ThreadFunction)(void * parameter);

	Thread(ThreadFunction thread_function, void * parameter, const pthread_attr_t * thread_attributes = NULL):
		_thread_function(thread_function),
		_parameter(parameter),
		_p_thread_attributes(NULL)
	{
		if(thread_attributes)
		{
			_thread_attributes = *thread_attributes;
			_p_thread_attributes = &_thread_attributes;
		}
	}

	void Start()
	{
		pthread_create (&_thread_id, _p_thread_attributes, _thread_function, _parameter);
		pthread_attr_destroy (_p_thread_attributes);
	}

	void Join()
	{
		pthread_join(_thread_id, NULL);
	}

	/// Does not work
//	template<typename T>
//	void Join(T * result)
//	{
//		void * thread_result = static_cast<void*>(result);
//		pthread_join(_thread_id,  &thread_result);
//	}

private:
	ThreadFunction _thread_function;
	void * _parameter;
	pthread_t _thread_id;
	pthread_attr_t _thread_attributes;
	pthread_attr_t * _p_thread_attributes;

};

}
