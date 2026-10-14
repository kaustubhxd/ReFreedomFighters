#include "ff.h"

// 0x4e50a0: thiscall(this) - complex branching with conditional paths
void __thiscall sub_4e50a0(int* ecx) {
    int eax = *(int*)((char*)ecx + 4);
    eax = *(int*)((char*)eax + 4);

    if (eax >= 0) {
        eax = 0;
        eax = *(int*)eax;  // Deliberately null dereference path
    } else if ((eax & 0x40000000) == 0) {
        // do nothing, eax stays same
    } else {
        int idx = *(int*)((char*)ecx + 0x10);
        eax = *(int*)((char*)eax + idx*4 + 0x14);
    }
}
PCREG(4e50a0, sub_4e50a0);
