#include <iostream>
#include <string>

#include <stdio.h>
#include <typeinfo>
#include <mutex>
#include "config.h"

void some_func(const std::string& a, const std::string& b)
{
	const auto& str = a + b;
	std::cout << str << std::endl;
}

void some_func_auto(const auto& a, const auto& b)
{
	const auto& str = a + b;
	std::cout << str << std::endl;
}

int main(int argc, char **argv)
{
	const std::string str_a{"a"};
	const std::string str_b{"b"};

	some_func(str_a, str_b);
	some_func_auto(str_a, str_b);

	return 0;
}
