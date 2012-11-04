/*
 * BookProcessExamples.h
 *
 *  Created on: Nov 2, 2012
 *      Author: peter
 */

#ifndef BOOKPROCESSEXAMPLES_H_
#define BOOKPROCESSEXAMPLES_H_

#include <signal.h>

namespace book
{

class BookProcessExamples
{
public:
	BookProcessExamples();
	virtual ~BookProcessExamples();

	static void clean_up_child_process (int signal_number);
	static void ForkExample();

private:
	static sig_atomic_t _child_exit_status;

};

}

#endif /* BOOKPROCESSEXAMPLES_H_ */
