/*
 * parameters.c
 *
 *  Created on: Dec 5, 2018
 *      Author: liroding
 */

#ifndef PARAMETERS_C_
#define PARAMETERS_C_

#include <getopt.h>
#include <stdio.h>
#include <sys/queue.h>
#include "parameters.h"
#include "main.h"

TAILQ_HEAD(, args_tailq_entry) args_tailq_head;



static struct option long_options[] =
{
			{"reqarg", required_argument,NULL, 'r'},
			{"optarg", optional_argument,NULL, 'o'},
			{"noarg",  no_argument,      NULL, 'n'},
			{"clog",   no_argument,		 NULL, 'c'},
			{"slog",   no_argument,      NULL, 's'},
};


void args_parse(int argc,char ** argv)
{

		int opt;
		int digit_optind = 0;
		int option_index = 0;
		char *string = "a:b:c:d";

		//定义一个结构体指针
		struct args_tailq_entry *item;
		//初始化队列
		TAILQ_INIT(&args_tailq_head);

		while((opt =getopt_long_only(argc,argv,string,long_options,&option_index))!= -1)
		{
			printf("opt = %c\t\t", opt);
			printf("optarg = %s\t\t",optarg);
			printf("optind = %d\t\t",optind);
			printf("argv[optind] =%s\t\t", argv[optind]);
			printf("option_index = %d\n",option_index);
			switch(opt)
			{
				case 'c':
					item = malloc(sizeof(*item));
					if (item == NULL)
					{
							perror("malloc failed");
							exit(-1);
					}
					//设置值
					item->flag = 'c';
					TAILQ_INSERT_TAIL(&args_tailq_head, item, entries);
					printf("!!!!!   c   \n");
					break;
				case 's':
					item = malloc(sizeof(*item));
					if (item == NULL)
					{
							perror("malloc failed");
							exit(-1);
					}
					//设置值
					item->flag = 's';
					TAILQ_INSERT_TAIL(&args_tailq_head, item, entries);
					printf("!!!!!   s   \n");
				break;
			}
		}

}

#endif /* PARAMETERS_C_ */
