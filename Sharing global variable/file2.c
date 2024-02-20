#include <stdio.h>
#include "global.h"

extern int globalVar; // Declaration of the global variable (optional)

void func2() {
    printf("Inside func2(): globalVar = %d\n", globalVar);
}
