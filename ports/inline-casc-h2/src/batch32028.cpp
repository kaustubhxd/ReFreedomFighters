#include "ff.h"

// 0x61bc70: thiscall, read arg, read vtable from arg, jump to [vtable+0x18]
typedef int (__thiscall* vtable_fn_t)(int*);

int __thiscall sub_61bc70(int* ecx_unused, int* arg) {
    int* vtable = (int*)arg[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[6];  // 0x18 / 4 = 6
    return fn(arg);
}
PCREG(61bc70, sub_61bc70);
