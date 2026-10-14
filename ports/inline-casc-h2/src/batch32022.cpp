#include "ff.h"

// 0x4754d0: thiscall(this, arg_byte) ret 4, stores byte at [ecx+0x3e9], returns arg
int __thiscall sub_4754d0(int* ecx, int arg) {
    *(char*)((char*)ecx + 0x3e9) = (char)arg;
    return arg;
}
PCREG(4754d0, sub_4754d0);
