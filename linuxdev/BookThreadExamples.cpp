/*
 * BookThreadExamples.cpp
 *
 *  Created on: Nov 2, 2012
 *      Author: peter
 */

#include <stdio.h>
#include <pthread.h>

#include "BookThreadExamples.h"

namespace book
{

BookThreadExamples::BookThreadExamples()
{
	// TODO Auto-generated constructor stub

}

BookThreadExamples::~BookThreadExamples()
{
	// TODO Auto-generated destructor stub
}

void* BookThreadExamples::char_print (void* parameters)
{
	int return_value = 8;
	//struct char_print_parms* p = (struct char_print_parms*) parameters;
	struct char_print_parms* p = static_cast<char_print_parms*>(parameters);
	for (int i = 0; i < p->count; ++i)
	{
		fputc (p->character, stderr);
		//sleep(1);
	}
	return &return_value;
}

void BookThreadExamples::RunLinuxThreads()
{
    // Thread
    pthread_t thread1_id;
    pthread_t thread2_id;
    char_print_parms thread1_args;
    struct char_print_parms thread2_args;
    /* Create a new thread to print 30,000 ’x’s. */
    thread1_args.character = 'x';
    thread1_args.count = 30000;
    pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
    /* Create a new thread to print 20,000 o’s. */
    thread2_args.character = 'o';
    thread2_args.count = 20000;
    pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
    int result1 = 0;
    int *pointer_toresult = &result1;
    pthread_join(thread1_id, /*static_cast<*/(void**)((&pointer_toresult)));

    pthread_join(thread2_id, NULL);
}

}
