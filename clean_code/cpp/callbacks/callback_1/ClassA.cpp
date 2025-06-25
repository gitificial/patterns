/*
 * ClassA.cpp
 *
 *  Created on: 08.02.2023
 *      Author: user
 */

#include "ClassA.h"

// using f_t = void(*)();
// using f_int_t = void(*)(int);

ClassA::ClassA() {
	// TODO Auto-generated constructor stub

}

ClassA::~ClassA() {
	// TODO Auto-generated destructor stub
}

void callback_caller_param(f_int_t callbacks, int a)
{
	callbacks(a);
}

void callback_caller_param(f_int_t callbacks[])
{
	std::cout << "callback_caller" << '\n';
}
