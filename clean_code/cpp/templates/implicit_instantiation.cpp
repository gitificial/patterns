#include <utility>
#include <iostream>

/*
 *
 * When code refers to a template in context that requires a completely defined type,
 * or when the completeness of the type affects the code, and this particular type
 * has not been explicitly instantiated, implicit instantiation occurs. For example,
 * when an object of this type is constructed, but not when a pointer to this type is constructed.
 *
 * This applies to the members of the class template: unless the member is used in the program,
 * it is not instantiated, and does not require a definition.
 *
 */

template<class T>
struct Z // template definition
{
    void f() {}
    void g(); 	// never defined
};

template struct Z<double>; // explicit instantiation of Z<double>
Z<int> a;                  // implicit instantiation of Z<int>
Z<char>* p;                // nothing is instantiated here

int main(int argc, char **argv)
{
	a.f();
	// a.g();  // error: undefined reference to `Z<int>::g()'

	p->f(); // implicit instantiation of Z<char> and Z<char>::f() occurs here.
	        // Z<char>::g() is never needed and never instantiated:
	        // it does not have to be defined

	return 0;
}
