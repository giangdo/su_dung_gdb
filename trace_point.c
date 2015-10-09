#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/************************************************************************************
													README
* To compile this program with debug information
	$gcc trace_point.c -lpthread -g -o trace_point

* To compile this program in level 3rd of optimazation mode and debug information
	$gcc trace_point.c -lpthread -g -O3 -o trace_point

* To create a file contain debugging info
	$objcopy --only-keep-debug trace_point trace_point.dgb

* To create a striped executable file
	$objcopy --strip-debug --strip-unneeded trace_point

* To add a link to the debugging info into the stripped executable file
	$objcopy --add-gnu-debuglink=trace_point.dbg trace_point

* To run:
	$./trace_point
*************************************************************************************/

void* thread1Poll(void *arg)
{
	unsigned int data1;
	for (data1 = 0; data1 < 1000; data1++)
	{
		usleep(1000*500);
		fprintf(stdout, "thread1's data:%u\n", data1);
	}
	return 0;
}

void* thread2Poll(void *arg)
{
	unsigned int data2;
	for (data2 = 0; data2 < 1000; data2++)
	{
		usleep(1000*500);
		fprintf(stdout, "thread2's data:%u\n", data2);
	}
	return 0;
}

char* endString = "!trace_point example!";

int main(int argc, char *argv[])
{
	// Daemonize
	switch (fork())
	{
		case 0:
			break;
		case -1:
			fprintf(stderr, "fork failed");
			exit(1);
		default:
			exit(0);
	}
	if (setsid() == -1) //Create new sesion containing a single (new) process group
	{
		fprintf(stderr, "setsid failed");
		exit(1);
	}

	//Create thread 1
	pthread_t thread1;
	if (pthread_create(&thread1, NULL, thread1Poll, NULL))
	{
		fprintf(stderr, "can not create new thread");
	}

	//Create thread 2
	pthread_t thread2;
	if (pthread_create(&thread2, NULL, thread2Poll, NULL))
	{
		fprintf(stderr, "can not create new thread");
	}

	//Wait to join threads
	if (pthread_join(thread1, NULL) ||
	    pthread_join(thread2, NULL))
	{
		fprintf(stderr, "can not join thread");
		exit(1);
	}

	//Print endstring
	fprintf(stdout, "%s\n", endString);

	return 0;
}
