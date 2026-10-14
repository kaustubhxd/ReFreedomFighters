#include "ff.h"

// 0x4632c0: read [ecx+8], tail-call 0x4db2c0
extern "C" int __thiscall ext_4db2c0(int*);
int __thiscall sub_4632c0(int* ecx) {
    return ext_4db2c0((int*)ecx[2]);  // [ecx+8]
}
PCREG(4632c0, sub_4632c0);

// 0x4673c0: lea eax[ecx+0x25], cmp [eax] with 0x7fffffff, cmove eax to ecx
int __thiscall sub_4673c0(int* ecx) {
    int* eax = (int*)((char*)ecx + 0x25);  // lea eax, [ecx+0x25]
    if (*eax == 0x7fffffff) {
        return 0;  // cmove ecx (0) to eax
    }
    return (int)eax;  // return the address
}
PCREG(4673c0, sub_4673c0);
