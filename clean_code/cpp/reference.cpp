/*
 * reference.cpp
 *
 *  Created on: 24.01.2023
 *      Author: user
 */

/*
 * A reference is not an object. Instead, a reference is just another name for
 * an already existing object.
 */

int ival = 1024;
int &refVal = ival;  // refVal refers to (is another name for) ival
int &refVal2;        // error: a reference must be initialized


