#include "ClassA.h"
#include "ClassB.h"

ClassA classA;
ClassB classB;

struct foo
{
    void bar(int, int);
	// void bar();
};



void test()
{}

int main()
{
	using func = void (foo::*)(int, int);
	func ptr = &foo::bar;

	using f_test = void(*)();
	using f_t_class = void(ClassB::*)();
	using f_int_t = void(ClassB::*)(int);

	f_int_t callback_4 = &ClassB::do_something_int;

	classA.callback_caller_param(callback_4, 3);

	return 0;
}
