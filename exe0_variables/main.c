#include "stdio.h"


void foo(int *p) {
    *p = *p + 1;
}

void main(void) {
    while (1) {
        int a = 6, b = 0;
        foo(a);
        
        if (a > 5) {
            b = 1;
        }
    }
}