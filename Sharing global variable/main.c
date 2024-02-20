#include <stdio.h>
#include "global.h"

extern int globalVar; // Declaration of the global variable (optional)

int main() {
    printf("In main(): globalVar = %d\n", globalVar);
    func1();
    func2();

    globalVar = 20; // Modify global variable

    printf("After modification: globalVar = %d\n", globalVar);
    func1();
    func2();

    return 0;
}
