/*
 * ClassB.h
 *
 *  Created on: 08.02.2023
 *      Author: user
 */

#ifndef SRC_CALLBACKS_CLASSB_H_
#define SRC_CALLBACKS_CLASSB_H_

// #include <iostream>
#include <stdio.h>

class ClassB {
public:
	ClassB();
	virtual ~ClassB();

	void do_something_int(int);
	void do_something_void();
};

#endif /* SRC_CALLBACKS_CLASSB_H_ */
