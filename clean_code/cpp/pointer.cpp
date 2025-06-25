/*
 * pointer.cpp
 *
 *  Created on: 24.01.2023
 *      Author: user
 */


/*
 * A pointer is a compound type that "points to" another type. Like references,
 * pointers are used for indirect access to other objects. Unlike a reference, a
 * pointer is an object in its own right. Pointers can be assigned and copied; a
 * single pointer can point to several different objects over its lifetime. Unlike a
 * reference, a pointer need not be initialized at the time it is defined. Like other,
 * built-in types, pointers defined at block scope have undefined value if they are
 * not initialized.
 *
 */

int *ip1, *ip2;  // both ip1 and ip2 are pointers to int

int ival = 42;
int *p = &ival;  // p holds the address of ival; p is a pointer to ival

double dval;
double *pd = &dval; // ok: initializer is the address of a double
double *pd2 = pd;   // ok: initializer is a pointer to double
int *pi = pd;  		// error: types of pi and pd differ




