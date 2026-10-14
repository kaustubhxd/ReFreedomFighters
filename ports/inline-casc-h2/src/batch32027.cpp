#include "ff.h"

// 0x5f2df0: thunk - read field, read field again, tail-jump
extern "C" int __thiscall ext_5fc260(int*);

int __thiscall sub_5f2df0(int* ecx) {
    int* field1 = (int*)ecx[3];      // [ecx+0xc]
    int* field2 = (int*)field1[1];   // [field1+4]
    return ext_5fc260(field2);
}
PCREG(5f2df0, sub_5f2df0);
