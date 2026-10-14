#include "ff.h"

// 0x45f420: read field, conditional jump or return 0
extern "C" int __thiscall ext_4dc130(int*);
int __thiscall sub_45f420(int* ecx) {
    int* inner = (int*)ecx[2];  // [ecx + 8]
    if (inner[0x14] != 0) {     // 0x50 / 4 = 0x14
        return ext_4dc130(inner);
    }
    return 0;  // xor eax, eax
}
PCREG(45f420, sub_45f420);

// 0x474700: read vtable from ecx, jump through slot 0x4f4
typedef int (__thiscall* vtable_fn_t)(int*);
int __thiscall sub_474700(int* ecx) {
    int* vtable = (int*)ecx[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[0x13d];  // 0x4f4 / 4 = 0x13d
    return fn(ecx);
}
PCREG(474700, sub_474700);
