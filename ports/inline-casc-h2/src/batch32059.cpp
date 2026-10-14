#include "ff.h"

// 0x597b10: thiscall(this, arg0) ret 4 - linear search through array
unsigned char __thiscall sub_597b10(int* ecx, int arg0) {
    int esi = *(int*)((char*)ecx + 0x2e6);  // array count
    int edx = 0;

    if (esi <= 0) {
        return 0;  // empty array
    }

    int* eax = (int*)((char*)ecx + 0xe6);  // array base

    while (edx < esi) {
        if (*eax == arg0) {
            return 1;  // found
        }
        edx++;
        eax++;
    }

    return 0;  // not found
}
PCREG(597b10, sub_597b10);
