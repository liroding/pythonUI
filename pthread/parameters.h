/*
 * parameters.h
 *
 *  Created on: Dec 5, 2018
 *      Author: liroding
 */

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

extern void args_parse(int argc,char ** argv);

/*
  定义一个结构体，它只是尾队列的一个元素
  它必须包含一个TAILQ_ENTRY来指向上一个和下一个元素
*/
struct args_tailq_entry {
	char flag;
	TAILQ_ENTRY(args_tailq_entry) entries;
};


#endif /* PARAMETERS_H_ */
