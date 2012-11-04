/*
 * BookThreadExamples.h
 *
 *  Created on: Nov 2, 2012
 *      Author: peter
 */

#ifndef BOOKTHREADEXAMPLES_H_
#define BOOKTHREADEXAMPLES_H_

namespace book
{

/* Parameters to print_function.	*/
struct char_print_parms
{
	/* The character to print. */
	char character;
	// The number of times to print it.
	int count;
};

class BookThreadExamples
{

public:
	BookThreadExamples();
	virtual ~BookThreadExamples();

	static void* char_print (void* parameters);
	static void RunLinuxThreads();

};

}

#endif /* BOOKTHREADEXAMPLES_H_ */
