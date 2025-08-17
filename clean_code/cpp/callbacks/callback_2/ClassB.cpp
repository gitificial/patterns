/*
 * ClassB.cpp
 *
 */

#include "ClassB.h"

ClassB::ClassB() {
	// TODO Auto-generated constructor stub

}

ClassB::~ClassB() {
	// TODO Auto-generated destructor stub
}

void ClassB::do_something_int(int input)
{
	// std::cout << "do_something_int " << '\n';
	printf("do_something_int: %d \n", input);
}

void ClassB::do_something_void()
{
	// std::cout << "do_something_2" << '\n';
	printf("called: do_something_void \n");
}

void ClassB::do_something_array_1(int input)
{
	// std::cout << "do_something_2" << '\n';
	printf("do_something_array_1: %d \n", input);
}

void ClassB::do_something_array_2(int input)
{
	// std::cout << "do_something_2" << '\n';
	input++;
	printf("do_something_array_2: %d \n", input);
}

