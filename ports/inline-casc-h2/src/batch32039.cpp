#include "ff.h"

// 0x466470: thiscall, clears bit 0x20000 at [ecx+0x136]
void __thiscall sub_466470(int* ecx) {
    int* field = (int*)((char*)ecx + 0x136);
    *field &= 0xfffdffff;  // Clear bit 0x20000
}
PCREG(466470, sub_466470);

// 0x468a20: thiscall, returns byte from [ecx+0x52]
int __thiscall sub_468a20(int* ecx) {
    return (unsigned char)*(char*)((char*)ecx + 0x52);
}
PCREG(468a20, sub_468a20);
