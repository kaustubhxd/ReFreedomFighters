#include "ff.h"

// 0x5df7c0: thiscall(this, arg0, arg1, arg2) ret 12 - constructor initializer
// Stores args at [ecx+4], [ecx+8], [ecx+0xc] and vtable at [ecx]
int* __thiscall sub_5df7c0(int* ecx, int arg0, int arg1, int arg2) {
    ecx[1] = arg0;      // [ecx+4] = arg0
    ecx[2] = arg1;      // [ecx+8] = arg1
    ecx[3] = arg2;      // [ecx+0xc] = arg2
    ecx[0] = 0x6b7428;  // [ecx] = vtable pointer
    return ecx;
}
PCREG(5df7c0, sub_5df7c0);
