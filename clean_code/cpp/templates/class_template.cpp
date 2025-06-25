#include <utility>
#include <iostream>

/*
 *	A class template defines a family of classes.
 */

namespace N
{
    template<class T>
    class Y // template definition
    {
        void mf() {}
    };
}

// template class Y<int>; // error: class template Y not visible in the global namespace
using N::Y;
// template class Y<int>; // error: explicit instantiation outside
                          // of the namespace of the template
template class N::Y<char*>;       // OK: explicit instantiation
template void N::Y<double>::mf(); // OK: explicit instantiation

int main(int argc, char **argv)
{
	return 0;
}
