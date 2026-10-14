#include "ff.h"

// 0x46e690: simple getter, reads ecx+0x7c
int __thiscall sub_46e690(int* ecx) {
    return ecx[0x1f]; // 0x7c / 4 = 0x1f
}
PCREG(46e690, sub_46e690);

// 0x46e730: returns constant address
int __cdecl sub_46e730() {
    return 0x6867bc;
}
PCREG(46e730, sub_46e730);
