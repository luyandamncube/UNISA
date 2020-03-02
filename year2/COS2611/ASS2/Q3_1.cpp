#include "stack.h"
#include <iostream>
#include <cstdlib>                          //For NULL definition
using namespace std;

template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

