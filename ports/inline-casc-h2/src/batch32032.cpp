#include "ff.h"

// 0x462d00: thiscall, read field [ecx+0x6c], get vtable, jump [vtable+0x24]
typedef int (__thiscall* vtable_fn_t)(int*);

int __thiscall sub_462d00(int* ecx) {
    int* field = (int*)ecx[0x1b];  // [ecx+0x6c]
    int* vtable = (int*)field[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[9];  // 0x24 / 4
    return fn(field);
}
PCREG(462d00, sub_462d00);

// 0x470540: thiscall, read field [ecx+0x94], get vtable, jump [vtable+0x3c]
int __thiscall sub_470540(int* ecx) {
    int* field = (int*)ecx[0x25];  // [ecx+0x94]
    int* vtable = (int*)field[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[15];  // 0x3c / 4
    return fn(field);
}
PCREG(470540, sub_470540);

// 0x64fad0: thiscall, read field [ecx+0xbd], test for null, jump [vtable+0x60] or return 0
int __thiscall sub_64fad0(int* ecx) {
    int* field = (int*)ecx[0x2f];  // [ecx+0xbd]
    if (!field) return 0;
    int* vtable = (int*)field[0];
    vtable_fn_t fn = (vtable_fn_t)vtable[24];  // 0x60 / 4
    return fn(field);
}
PCREG(64fad0, sub_64fad0);
