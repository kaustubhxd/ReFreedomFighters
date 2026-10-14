#include "ff.h"

// 0x466400: thiscall, reads [ecx+0x1ce], then [eax+4], test for null, jump [eax+4] or return 0
typedef int (__thiscall* vtable_fn_t)(int*);

int __thiscall sub_466400(int* ecx) {
    int* obj1 = (int*)ecx[0x73];  // [ecx+0x1ce]
    int* obj2 = (int*)obj1[1];     // [obj1+4]
    if (!obj2) return 0;
    int* vtable = (int*)obj2[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[1];  // [vtable+4]
    return fn(obj2);
}
PCREG(466400, sub_466400);
