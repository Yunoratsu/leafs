/************************************************
 *
 *  Just a simple header to handle colors and libs*
 *
 *  ********************************************  *
 *  Author: Yunoratsu **************************  *
 *  ************************************************/
#ifndef C_HEADERS
#define C_HEADERS


/* Some important definitions */
#define _XOPEN_SOURCE 700 
#define MAX_SIZE 1024

/* just some libs */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>


/* just some colors */
#define RED     "\033[31m"
#define RST     "\033[0m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

/* Maybe some wrappers?*/
void    die(const char *msg);
void    printEntry(char *name, int depth, int isLast[], bool islastEntry);
void    traverseDir(const char *path, int depth, bool firstTime);

#endif
