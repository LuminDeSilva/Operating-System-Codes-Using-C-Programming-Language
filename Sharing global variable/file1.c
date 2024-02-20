#include <stdio.h>
#include "global.h"

int globalVar = 10; // Definition of the global variable

void func1() {
    printf("Inside func1(): globalVar = %d\n", globalVar);
}
