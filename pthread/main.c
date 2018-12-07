/*
 * main.c
 *
 *  Created on: Dec 4, 2018
 *      Author: liroding
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <getopt.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include </usr/include/python2.7/Python.h>

#include "main.h"
#include "parameters.h"

typedef struct _pthread_config{
	int master;
	sem_t sem;
	pthread_t thread_id;
	void *(*func)(void);
}pthread_config_t;

pthread_config_t pthread_config[2];
FILE *fp=NULL;

CREATE_LOGFILE(logfile);

extern TAILQ_HEAD(, args_tailq_entry) args_tailq_head;

void *pthread_1(void)
{
	int p;
	while(1)
	{
		//遍历队列
		printf("Forward traversal: \n");
		struct args_tailq_entry *item;
		/*
		TAILQ_FOREACH(item, &args_tailq_head, entries)
		{
			printf("%c ",item->flag);
			if(item->flag=='c')
			{

		 	 }
		}
		*/
		//action
		int i;
		for(i=0;i<2;i++)
		{
			sleep(2);
			printf("pthread_1\n");
			//	fwrite("pthread_1\n",sizeof("pthread_1\n"),1,fp);
		}
		//send sem
		sem_post(&pthread_config[0].sem);
		printf("pthread_1 sem_post\n");
		//	fwrite("pthread_1 sem_post\n",sizeof("pthread_1 sem_post\n"),1,fp);
		break;

	}
	p=fclose(fp);
	if(p==0)
		printf("file close ok\n");
	else
		printf("file close failed\n ");

	pthread_exit(0);
}

//handle the input arg by python
void *pthread_2(void)
{

	while(1)
	{
			printf("pthread_2 start\n");
			sem_wait(&pthread_config[0].sem);
			/*
			 * add python
			 */
			Py_Initialize();

		    PyRun_SimpleString("import sys");
		    PyRun_SimpleString("sys.path.append('./')");

		    PyObject *pModule = NULL, *pFunc = NULL, *pArg = NULL;

			PyRun_SimpleString("print 'nihao python'");
			pModule=PyImport_ImportModule("py");
		    pFunc = PyObject_GetAttrString(pModule, "creatui");
		    pArg = Py_BuildValue("(s)", "hello_python");
		    PyEval_CallObject(pFunc, pArg);

			printf("good !!!!\n");
			Py_Finalize();

			printf("----func=%s\n",__func__);
			sleep(3);
			break;
	}
	pthread_exit(0);
}


int main(int argc,char ** argv)
{



		int ret=0;
		int res=0;
		args_parse(argc,argv);
		//push the args_parse to queue
/*
		/*
		 * pthread test
		 */

		pthread_config[0].func=pthread_1;
		pthread_config[1].func=pthread_2;

		res=sem_init(&pthread_config[0].sem,0,0);
		if(res!=0)
		{
			printf("sem_init failed\n");
		}

		ret= pthread_create(&pthread_config[0].thread_id,NULL,pthread_config[0].func,NULL);
		ret= pthread_create(&pthread_config[1].thread_id,NULL,pthread_config[1].func,NULL);


		pthread_join(pthread_config[0].thread_id,NULL);
		pthread_join(pthread_config[1].thread_id,NULL);

		return 0;
}









