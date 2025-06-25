#include <stdio.h>
#include <math.h>

void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}

int getNextRandomValue(void)
{
    return rand();
}

int main(void)
{
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);

    int i;
    for(i = 0; i < 10; i++) 
    {
        printf("Element %2d: %2d \n", i, myarray[i]);
    }
}
