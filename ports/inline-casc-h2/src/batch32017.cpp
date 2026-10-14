#include "ff.h"

// 0x54dce0: clear global, read field, clear field, vtable jump
// The vtable jump will be hooked in the spec
typedef int (__thiscall* vtable_fn_t)(int*);

int __thiscall sub_54dce0(int* ecx) {
    *(char*)0x713e19 = 0;
    int* vtable = (int*)ecx[0];
    ecx[1] = 0;
    vtable_fn_t fn = (vtable_fn_t)vtable[6];  // 0x18 / 4 = 6
    return fn(ecx);
}
PCREG(54dce0, sub_54dce0);
