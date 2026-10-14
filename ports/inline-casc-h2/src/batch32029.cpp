#include "ff.h"

// 0x63ea80: thiscall(this, arg) ret 4, reads [arg+4], returns it
int __stdcall sub_63ea80(int* arg) {
    return arg[1];  // [arg+4]
}
PCREG(63ea80, sub_63ea80);

// 0x650dc0: thiscall(this, arg) ret 4, stores at [ecx+0xc], returns arg
int __thiscall sub_650dc0(int* ecx, int arg) {
    *(int*)((char*)ecx + 0xc) = arg;
    return arg;
}
PCREG(650dc0, sub_650dc0);

// 0x464710: thiscall(this, arg) ret 4, reads [ecx+0x6c], stores arg at [field+0x268]
int __thiscall sub_464710(int* ecx, int arg) {
    int* field = (int*)ecx[0x1b];  // [ecx+0x6c]
    *(int*)((char*)field + 0x268) = arg;
    return arg;
}
PCREG(464710, sub_464710);
