#include "ff.h"

// 0x47bfb0: thiscall(this, arg) ret 4, stores at [ecx+0x5b2], returns arg
int __thiscall sub_47bfb0(int* ecx, int arg) {
    *(int*)((char*)ecx + 0x5b2) = arg;
    return arg;
}
PCREG(47bfb0, sub_47bfb0);

// 0x4e7c40: thiscall(this, arg) ret 4, stores at [ecx+9], returns arg
int __thiscall sub_4e7c40(int* ecx, int arg) {
    *(int*)((char*)ecx + 9) = arg;
    return arg;
}
PCREG(4e7c40, sub_4e7c40);
