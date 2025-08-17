/*
 * ClassA.h
 */

#ifndef SRC_CALLBACKS_CLASSA_H_
#define SRC_CALLBACKS_CLASSA_H_

// using f_t = void(*)();
using f_int_t = void(*)(int);

class ClassA {
public:
	ClassA();
	virtual ~ClassA();

	void callback_caller_param(f_int_t, int);
	void callback_caller_array(f_int_t[]);

private:


};

#endif /* SRC_CALLBACKS_CLASSA_H_ */
