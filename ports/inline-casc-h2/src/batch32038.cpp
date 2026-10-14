#include "ff.h"

// 0x54c300: thiscall, reads [ecx+0x50], tests for null, jumps to vtable[0x18] or returns 0
typedef int (__thiscall* vtable_fn_t)(int*);

int __thiscall sub_54c300(int* ecx) {
    int* field = (int*)ecx[0x14];  // [ecx+0x50]
    if (!field) return 0;
    int* vtable = (int*)field[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[6];  // 0x18 / 4 = 6
    return fn(field);
}
PCREG(54c300, sub_54c300);
