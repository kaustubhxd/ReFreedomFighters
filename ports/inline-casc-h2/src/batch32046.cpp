#include "ff.h"

// 0x563d40: stdcall(arg0, arg1, arg2) ret 12 - conditional reset after increment
// Increments [arg1], compares with arg2, conditionally resets [arg1] to arg0
void __stdcall sub_563d40(int arg0, int* arg1, int arg2) {
    (*arg1)++;
    if (*arg1 >= arg2) {
        *arg1 = arg0;
    }
}
PCREG(563d40, sub_563d40);
