/*
 * main.h
 *
 *  Created on: Dec 4, 2018
 *      Author: liroding
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <string.h>

#define _INIT(func) \
static void __attribute__((constructor,used)) func(void)

extern FILE *fp;

#define CREATE_LOGFILE(name) \
_INIT(zx_ ##name); \
static void zx_ ##name(void) \
{\
		int p;						\
		char buf[1024];				\
		getcwd(buf,sizeof(buf));		\
		fp=fopen(strcat(buf,"/debuglog.log"),"wb");		\
		if(fp==NULL)			\
			printf("file open failed\n");		\
		else									\
			printf("file open success!\n");		\
} \




#endif /* MAIN_H_ */
