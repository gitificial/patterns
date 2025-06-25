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
	// using f_int_t = void(*)(int);
	// using f_int_t = int(ClassB::*)(int);

	using f_int_t = void(ClassB::*)(int);

	// f_t callback_test = test();
	// f_t callback_1 = &ClassB::do_something_1();
	// f_t callback_2 = classB.do_something_2();
	// f_t callback_3 = classB.do_something_3();

	// f_int_t callback_4 = classB.do_something_4(3);
	f_int_t callback_4 = &ClassB::do_something_int;
	// callback_4(1,2);

	// classA.callback_caller();
	classA.callback_caller_param(callback_4, 3);

	// f_t callbacks[] = {callback_1, callback_2, callback_3};

	// classA.callback_caller(callbacks);

	return 0;
}
