/*
 * ClassA.h
 *
 *  Created on: 08.02.2023
 *      Author: user
 */

#ifndef SRC_CALLBACKS_CLASSA_H_
#define SRC_CALLBACKS_CLASSA_H_

#include <stdio.h>
#include <cstdio>
#include <functional>
#include <vector>

class ClassA {
public:
	using cb_void = std::function<void(void)>;
	using cb_int = std::function<void(int)>;


	using cb_array = std::function<void(int)>[];
	// using cb_array = std::vector<cb_int> vec_cb_int;
	// std::vector<void (*)(int)> vec_cb_int;

	ClassA();
	virtual ~ClassA();

	void ext_func_caller_void(cb_void);
	void ext_func_caller_int(cb_int);

	void ext_func_caller_array(cb_array);
	void ext_func_caller_vector(std::vector<void (*)(int)>);
	void ext_func_caller_vector(std::vector<std::function<void(int)>>);

};

#endif /* SRC_CALLBACKS_CLASSA_H_ */
