/*
 * BookProcessExamples.cpp
 *
 *  Created on: Nov 2, 2012
 *      Author: peter
 */
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>

#include "BookProcessExamples.h"

namespace book
{

BookProcessExamples::BookProcessExamples()
{
	// TODO Auto-generated constructor stub

}

BookProcessExamples::~BookProcessExamples()
{
	// TODO Auto-generated destructor stub
}

void BookProcessExamples::clean_up_child_process (int signal_number)
{
	// Clean up the child process.
	int process_status_1 = 0;
	//wait (&process_status_1);
	// Store its exit status in a global variable.
	//BookProcessExamples::_child_exit_status = process_status_1;
}

void BookProcessExamples::ForkExample()
{
    // "system" call
    //int return_value;
    //return_value = system ("ls -l /aaa");

	// fork
//	pid_t child_pid;
//	printf ("the main program process ID is %d\n", (int) getpid ());
//	child_pid = fork ();
//	if (child_pid != 0)
//	{
//		printf ("this is the parent process, with id %d\n", (int) getpid ());
//		printf ("the child’s process ID is %d\n", (int) child_pid);
//	}
//	else
//		printf ("this is the child process, with id %d\n", (int) getpid ());

    //execvp
    /*char * args[64];
	args[0] = new char[3];
	memcpy(args[0], "-l", 2);

	execvp ("ls", args);
	// The execvp function returns only if an error occurs.
	fprintf (stderr, "an error occurred in execvp\n");
	abort ();*/
    // wait for chiled process
    struct sigaction sigchld_action;
    memset(&sigchld_action, 0, sizeof (sigchld_action));
    sigchld_action.sa_handler = &clean_up_child_process;
    sigaction (SIGCHLD, &sigchld_action, NULL);
    pid_t child_pid;
    /* Create a child process. */
    child_pid = fork();
    if(child_pid > 0){
        /* This is the parent process. Sleep for a minute. */
        sleep(6);
    }else{
        /* This is the child process. Exit immediately. */
        exit(0);
    }
}

}
