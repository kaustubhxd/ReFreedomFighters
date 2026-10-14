#include "ff.h"

// 0x52cfd0: thiscall(this) - multi-field initializer constructor
int* __thiscall sub_52cfd0(int* ecx) {
    *(int*)ecx = 0x6a1414;

    *(short*)((char*)ecx + 0x58) = 1;
    *(short*)((char*)ecx + 0x5e) = 1;
    *(short*)((char*)ecx + 0x64) = 1;
    *(short*)((char*)ecx + 0x6a) = 1;
    *(short*)((char*)ecx + 0x70) = 1;
    *(short*)((char*)ecx + 0x76) = 1;
    *(short*)((char*)ecx + 0x80) = 1;
    *(short*)((char*)ecx + 0x86) = 1;

    *(short*)((char*)ecx + 0x96) = 0;
    *(int*)((char*)ecx + 0x98) = 0;
    *(short*)((char*)ecx + 4) = 0;

    *(int*)((char*)ecx + 0x50) = 0x14e20;
    *(int*)((char*)ecx + 0x54) = 0;
    *(int*)((char*)ecx + 0x5a) = 0;
    *(int*)((char*)ecx + 0x60) = 0;
    *(int*)((char*)ecx + 0x66) = 0;
    *(int*)((char*)ecx + 0x6c) = 0;
    *(int*)((char*)ecx + 0x72) = 0;
    *(int*)((char*)ecx + 0x78) = 0;
    *(int*)((char*)ecx + 0x82) = 0;
    *(int*)((char*)ecx + 0x88) = 0;
    *(int*)((char*)ecx + 0x8c) = 0;
    *(int*)((char*)ecx + 0x90) = 0;
    *(int*)((char*)ecx + 0x7c) = 0;

    return ecx;
}
PCREG(52cfd0, sub_52cfd0);
