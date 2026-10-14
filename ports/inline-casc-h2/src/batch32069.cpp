#include "ff.h"

extern "C" int __stdcall ext_4c24b0(int ecx);

// 0x4bb9d0: thiscall(this) ret 4 - modify field, call external, return 1
unsigned char __stdcall sub_4bb9d0(int ecx) {
    *(int*)((char*)ecx + 4) &= 0xffffffbf;
    ext_4c24b0(ecx);
    return 1;
}
PCREG(4bb9d0, sub_4bb9d0);
