#include "ff.h"

// 0x4711e0: thiscall(this, arg) ret 4, stores arg at [ecx+0xba], returns arg
// ret 4 means 1 stack arg (4 bytes)
int __thiscall sub_4711e0(int* ecx, int arg) {
    *(int*)((char*)ecx + 0xba) = arg;
    return arg;
}
PCREG(4711e0, sub_4711e0);
