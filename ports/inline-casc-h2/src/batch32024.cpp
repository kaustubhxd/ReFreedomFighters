#include "ff.h"

// 0x4fa700: thiscall(this, arg) ret 4, stores at [ecx+0x68], returns arg
int __thiscall sub_4fa700(int* ecx, int arg) {
    *(int*)((char*)ecx + 0x68) = arg;
    return arg;
}
PCREG(4fa700, sub_4fa700);

// 0x520d30: thiscall(this, arg_byte) ret 4, movzx to dword, stores at [ecx+0x2620]
int __thiscall sub_520d30(int* ecx, int arg) {
    *(int*)((char*)ecx + 0x2620) = (unsigned char)arg;  // movzx zero-extends
    return arg;
}
PCREG(520d30, sub_520d30);
