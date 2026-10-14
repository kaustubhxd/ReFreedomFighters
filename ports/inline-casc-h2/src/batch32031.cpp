#include "ff.h"

// 0x4dbbc0: thiscall, read field [ecx+0x54], test for null, if not null read vtable and jump [vtable+0x18]
typedef int (__thiscall* vtable_fn_t)(int*);

int __thiscall sub_4dbbc0(int* ecx) {
    int* field = (int*)ecx[0x15];  // [ecx+0x54]
    if (!field) {
        return 0;  // ret without calling
    }
    int* vtable = (int*)field[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[6];  // [vtable+0x18]
    return fn(field);
}
PCREG(4dbbc0, sub_4dbbc0);
