#include "ff.h"

// 0x4d4040: add ecx 0x10db, read vtable, jump to [vtable+0]
typedef int (__thiscall* vtable_fn_t)(int*);
int __thiscall sub_4d4040(int* ecx) {
    int* adjusted = (int*)((char*)ecx + 0x10db);
    int* vtable = (int*)adjusted[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[0];
    return fn(adjusted);
}
PCREG(4d4040, sub_4d4040);
