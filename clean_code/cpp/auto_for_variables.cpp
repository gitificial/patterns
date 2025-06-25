#include <iostream>
#include <string>

#include <stdio.h>
#include <typeinfo>
#include <mutex>
#include "config.h"

int main(int argc, char **argv)
{
	struct Foo
	{
		int m_{};
		int val() const {return m_;}
	};

	auto i = 0;		// creates a int
	auto j = 0.0;	// creates a double
	auto x = Foo{};
	// auto y = std::create_object();
	auto z = std::mutex{};

	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(j).name() << std::endl;
	std::cout << typeid(x).name() << std::endl;
	std::cout << typeid(z).name() << std::endl;

	return 0;
}
