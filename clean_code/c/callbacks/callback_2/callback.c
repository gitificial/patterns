#include <stdio.h>

// Define a type for the callback signature,
// it is not necessary but makes life easier

// Function pointer called CallbackType that takes a float
// and returns an int
typedef int (*CallbackType)(float);

void DoWork(CallbackType callback)
{
  float variable = 0.0f;
  
  // Do calculations
  
  // Call the callback with the variable, and retrieve the
  // result
  int result = callback(variable);

  // Do something with the result
}

int SomeCallback(float variable)
{
  int result;

  // Interpret variable
  result = 2;
  printf("Callback print: %2d \n", result);

  return result;
}

int main(int argc, char ** argv)
{
  // Pass in SomeCallback to the DoWork
  DoWork(&SomeCallback);
}
