#include "ff.h"

// 0x5b04c0: thiscall(this, ptr1, ptr2) ret 8 - copyout function
// Reads [ecx+0xc], [ecx+0x14] and writes to *ptr1, *ptr2
void __thiscall sub_5b04c0(int* ecx, int* ptr1, int* ptr2) {
    int val1 = *(int*)((char*)ecx + 0xc);
    int val2 = *(int*)((char*)ecx + 0x14);
    if (ptr1) *ptr1 = val1;
    if (ptr2) *ptr2 = val2;
}
PCREG(5b04c0, sub_5b04c0);
