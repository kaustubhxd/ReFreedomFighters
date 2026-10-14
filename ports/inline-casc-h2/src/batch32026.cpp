#include "ff.h"

// 0x539c90: thiscall(this, arg) ret 4, stores at [ecx+0x52f6]
int __thiscall sub_539c90(int* ecx, int arg) {
    *(int*)((char*)ecx + 0x52f6) = arg;
    return arg;
}
PCREG(539c90, sub_539c90);

// 0x5eeb00: thiscall(this, arg_byte) ret 4, stores byte at [ecx+0x6a]
int __thiscall sub_5eeb00(int* ecx, int arg) {
    *(char*)((char*)ecx + 0x6a) = (char)arg;
    return arg;
}
PCREG(5eeb00, sub_5eeb00);

// 0x5f0180: thiscall(this, arg) ret 4, stores at [ecx+0xd7]
int __thiscall sub_5f0180(int* ecx, int arg) {
    *(int*)((char*)ecx + 0xd7) = arg;
    return arg;
}
PCREG(5f0180, sub_5f0180);
