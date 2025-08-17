/*
 * ClassB.h
 *
 */

#ifndef SRC_CALLBACKS_CLASSB_H_
#define SRC_CALLBACKS_CLASSB_H_

#include <cstdio>

class ClassB {
public:
	ClassB();
	virtual ~ClassB();

	void do_something_int(int);
	void do_something_void();
	void do_something_array_1(int);
	void do_something_array_2(int);
};

#endif /* SRC_CALLBACKS_CLASSB_H_ */
