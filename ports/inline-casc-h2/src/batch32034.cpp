#include "ff.h"

extern "C" int ext_62dfa0;

// 0x530fb0: thiscall(this, arg1_byte, arg2_byte) ret 8, stores two bytes at [ecx+4] and [ecx+5], returns arg2_byte in al
int __thiscall sub_530fb0(int* ecx, int arg1, int arg2) {
    char* target = (char*)ecx + 4;
    target[0] = (char)arg1;
    target[1] = (char)arg2;
    return arg2 & 0xff;  // Return the second byte
}
PCREG(530fb0, sub_530fb0);

// 0x5b07f0: thiscall(this, arg1, arg2) ret 8, stores two dwords at [ecx+0xc] and [ecx+0x14], returns arg2
int __thiscall sub_5b07f0(int* ecx, int arg1, int arg2) {
    *(int*)((char*)ecx + 0xc) = arg1;
    *(int*)((char*)ecx + 0x14) = arg2;
    return arg2;  // Return the second dword
}
PCREG(5b07f0, sub_5b07f0);

// 0x62c9b0: cdecl(obj) - initialize object with vtable and fields
void __cdecl sub_62c9b0(int* obj) {
    obj[0] = (int)&ext_62dfa0;
    *(int*)((char*)obj + 0xc) = 1;
    *(int*)((char*)obj + 8) = 0;
}
PCREG(62c9b0, sub_62c9b0);
