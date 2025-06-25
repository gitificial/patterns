// g++ -o callback main.cpp ClassA.cpp  ClassA.h  ClassB.cpp  ClassB.h

#include <stdio.h>
#include <functional>
#include <vector>

#include "ClassA.h"
#include "ClassB.h"

int main()
{
	ClassA classA;
	ClassB classB;

	ClassA::cb_void cb_void = std::bind(&ClassB::do_something_void, &classB);
	ClassA::cb_int cb_int = std::bind(&ClassB::do_something_int, &classB, std::placeholders::_1);

	ClassA::cb_array cb_array = {std::bind(&ClassB::do_something_array_1, &classB, std::placeholders::_1),
								 std::bind(&ClassB::do_something_array_2, &classB, std::placeholders::_1)};

	std::vector<ClassA::cb_int> cb_vector;
	cb_vector = {std::bind(&ClassB::do_something_array_1, &classB, std::placeholders::_1),
				 std::bind(&ClassB::do_something_array_2, &classB, std::placeholders::_1)};

	classA.ext_func_caller_void(cb_void);
	classA.ext_func_caller_int(cb_int);
	classA.ext_func_caller_array(cb_array);
	classA.ext_func_caller_vector(cb_vector);

	return 0;
}
