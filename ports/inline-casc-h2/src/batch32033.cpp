#include "ff.h"

// 0x4d61c0: stdcall(arg) ret 4, compares [arg+0x42e] with 1, returns 1 or 0
int __stdcall sub_4d61c0(int* arg) {
    int val = *(int*)((char*)arg + 0x42e);
    return (val == 1) ? 1 : 0;
}
PCREG(4d61c0, sub_4d61c0);

// 0x52cf00: thiscall(this, arg_byte) ret 4, swap byte at [ecx+0x10], return old byte
int __thiscall sub_52cf00(int* ecx, int arg) {
    char* target = (char*)ecx + 0x10;
    int old_val = (unsigned char)*target;
    *target = (char)arg;
    return old_val;
}
PCREG(52cf00, sub_52cf00);

// 0x582730: thiscall(this, arg) ret 4, copy [arg+0x48] to [ecx+0x48]
int __thiscall sub_582730(int* ecx, int* arg) {
    int val = arg[0x12];  // [arg+0x48]
    *(int*)((char*)ecx + 0x48) = val;
    return val;
}
PCREG(582730, sub_582730);
