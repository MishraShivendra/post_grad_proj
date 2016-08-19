#ifndef INCLUDE_PRE_PROCESSING_H
#define INCLUDE_PRE_PROCESSING_H __file__

#define NO_OF_SCENARIOS 7
#define TOTAL_TRIALS 80
#define THERMAL_IMAGE_BYTES 35
#define THERMAL_IMAGE_RESO 16

#if __linux__
#define _XOPEN_SOURCE 700
#include <error.h>                                     			/* Headers */
#include <getopt.h>
#include <unistd.h>
#include <ftw.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <errno.h>
#ifndef USE_FDS
#define USE_FDS 15
#endif
#define SCENARIO_1 0
#define SCENARIO_2 1
#define SCENARIO_3 2
#define SCENARIO_4 3
#define SCENARIO_5 4
#define SCENARIO_6 5
#define SCENARIO_7 6
/* Matrix for thermal imaging data*/
unsigned char ther[THERMAL_IMAGE_BYTES];
unsigned char diss[NO_OF_SCENARIOS][THERMAL_IMAGE_BYTES];
unsigned char readbuff1[NO_OF_SCENARIOS][THERMAL_IMAGE_BYTES],op1[20];
volatile int prec=0;                                 			
/* Result matrix of thermal imaging data*/

float fl1[NO_OF_SCENARIOS][THERMAL_IMAGE_RESO],val;
/* File pointers for i/o files*/
FILE *src[NO_OF_SCENARIOS], *temp[NO_OF_SCENARIOS],*oup[NO_OF_SCENARIOS];						
int count,ag=0;
char tmp[NO_OF_SCENARIOS], ip[NO_OF_SCENARIOS][THERMAL_IMAGE_BYTES], op[NO_OF_SCENARIOS][THERMAL_IMAGE_BYTES];
int is_input_file = 1;
pthread_mutex_t my_lock;

struct fil
{
	char *ip;
	/* For storing input file location */
	char *resl;								
	/* output file location*/
}links[NO_OF_SCENARIOS][TOTAL_TRIALS];

#else
#error "This implementation works only in Linux!"
#endif  /* Test end, If I am on Linux */

#endif /* .h file end */
