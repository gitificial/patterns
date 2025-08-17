/*
 * ClassB.h
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
