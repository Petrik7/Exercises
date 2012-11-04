#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>

#include "BookProcessExamples.h"
#include "BookThreadExamples.h"

#include "thread.hpp"
#include "mutex.h"

using namespace multithreading;

/* Parameters to print_function.	*/
struct CharPrintParms
{
	/* The character to print. */
	char character;
	// The number of times to print it.
	int count;
	int some_result;
};

void* PrintChars (void* parameters)
{
	multithreading::Mutex mutex_lock;
	mutex_lock.Lock();
	mutex_lock.Lock();

	CharPrintParms* p = static_cast<CharPrintParms*>(parameters);
	for (int i = 0; i < p->count; ++i)
	{
		std::cout << p->character;
		//sleep(1);
	}
	p->some_result = 888;
	std::cout << std::endl << "Exit thread function";
	//pthread_exit(return_value);
	return 0;
}

int main (int argc, char **argv)
{
	int i;
	i = atoi (argv[1]);
	std::cout << i << std::endl;

    //book::BookProcessExamples::ForkExample();
    //book::BookThreadExamples::RunLinuxThreads();

	// test my thread
	CharPrintParms thread_1_args;
	thread_1_args.character = 'M';
	thread_1_args.count = 30000;

	int res = 0;
	int * thread_result = &res;

	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE);

	multithreading::Thread my_thread_1(&PrintChars, &thread_1_args, &attr);
	pthread_attr_destroy (&attr);

	my_thread_1.Start();
	my_thread_1.Join();


	return 0;
}
