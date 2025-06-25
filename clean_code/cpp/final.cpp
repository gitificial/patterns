
/*
 *
 * Specifies that a virtual function cannot be overridden in a derived class
 * or that a class cannot be derived from.
 *
 */

struct A;
struct A final {}; // OK, definition of struct A,
                   // not value-initialization of variable final

struct X
{
    struct C
	{
    	constexpr operator int()
		{
			return 5;
		}
	};

    struct B final : C{}; // OK, definition of nested class B,
                          // not declaration of a bit-field member final
};

// Abnormal final usage.

struct final final // OK, definition of a struct named `final` from which
{                  // you cannot inherit
};

// struct final final {}; // Error: redefinition of `struct final`, NOT a
                          // definition of a variable `final` using an elaborated
                          // type specifier `struct final` followed by an
                          // aggregate initialization

// struct override : final {}; // Error: cannot derive from final base type;
                               // `override` in given context is a normal name
void foo()
{
    [[maybe_unused]]
    final final; // OK, declaration of a variable named `final` of type
                 // `struct final`
}

struct final final; // OK, declaration of a variable named `final` of type
                    // `struct final` using an elaborated type specifier
int main()
{
}
