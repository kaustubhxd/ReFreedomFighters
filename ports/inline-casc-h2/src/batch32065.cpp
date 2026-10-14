#include "ff.h"

// 0x5167d0: thiscall(this) - large field initializer with float values
int* __thiscall sub_5167d0(int* ecx) {
    *(int*)ecx = 0;
    *(int*)((char*)ecx + 4) = 0;
    *(int*)((char*)ecx + 8) = 0;
    *(int*)((char*)ecx + 0xc) = 0;
    *(int*)((char*)ecx + 0x10) = 0x3c23d70a;
    *(int*)((char*)ecx + 0x14) = 0x3f800000;
    *(int*)((char*)ecx + 0x18) = 0;
    *(unsigned char*)((char*)ecx + 0x1c) = 1;
    *(int*)((char*)ecx + 0x1d) = 0;
    *(int*)((char*)ecx + 0x21) = 0;
    *(int*)((char*)ecx + 0x25) = 0;
    *(int*)((char*)ecx + 0x29) = 0;
    *(int*)((char*)ecx + 0x2d) = 0;
    *(int*)((char*)ecx + 0x31) = 0;
    *(int*)((char*)ecx + 0x35) = 0;
    *(int*)((char*)ecx + 0x39) = 0;
    *(int*)((char*)ecx + 0x3d) = 0;
    *(int*)((char*)ecx + 0x41) = 0;
    *(int*)((char*)ecx + 0x45) = 0;
    *(int*)((char*)ecx + 0x49) = 0x3f800000;
    *(int*)((char*)ecx + 0x4d) = 0;
    *(int*)((char*)ecx + 0x51) = 0;
    *(int*)((char*)ecx + 0x55) = 0;
    *(int*)((char*)ecx + 0x59) = 0;
    *(int*)((char*)ecx + 0x5d) = 0x43960000;
    *(int*)((char*)ecx + 0x61) = 0;
    *(int*)((char*)ecx + 0x65) = 0;
    *(int*)((char*)ecx + 0x69) = 0;
    *(int*)((char*)ecx + 0x6d) = 0;
    *(int*)((char*)ecx + 0x71) = 0;
    *(int*)((char*)ecx + 0x75) = 0x3f800000;

    return ecx;
}
PCREG(5167d0, sub_5167d0);
