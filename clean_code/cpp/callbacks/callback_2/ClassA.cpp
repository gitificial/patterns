/*
 * ClassA.cpp
 *
 */

#include "ClassA.h"

ClassA::ClassA() {
	// TODO Auto-generated constructor stub

}

ClassA::~ClassA() {
	// TODO Auto-generated destructor stub
}

void ClassA::ext_func_caller_void(cb_void callback)
{
	callback();
}

void ClassA::ext_func_caller_int(cb_int callback)
{
	callback(3);
}

void ClassA::ext_func_caller_array(cb_array callback)
{
	callback[0](6);
	callback[1](8);

	// The following statement won't work on array of pointers!!
	// for(int i = 0; i < (sizeof(callback) / sizeof(callback)[0]); ++i)
	// {
	//	callback[i](i);
	//}
}

// void ClassA::ext_func_caller_vector(std::vector<void (*)(int)> vector_callbacks)
void ClassA::ext_func_caller_vector(std::vector<std::function<void(int)>> vector_callbacks)
{
	for (auto vector_callback : vector_callbacks)
	{
		vector_callback(3);
	}
}
