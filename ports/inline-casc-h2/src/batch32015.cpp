#include "ff.h"

// 0x505de0: thunk to 0x50a410
extern "C" int __thiscall ext_50a410(int*);
int __thiscall sub_505de0(int* ecx) {
    return ext_50a410(ecx);
}
PCREG(505de0, sub_505de0);

// 0x57f350: thunk to 0x610100
extern "C" int __stdcall ext_610100(void);
int __stdcall sub_57f350() {
    return ext_610100();
}
PCREG(57f350, sub_57f350);

// 0x5ab090: thiscall, cmp at 0x300, inc at 0x8c7 if not equal (unaligned)
int __thiscall sub_5ab090(int* ecx) {
    if (*(int*)((char*)ecx + 0x300) != 0x10000000) {
        (*(int*)((char*)ecx + 0x8c7))++;
    }
    return 0;
}
PCREG(5ab090, sub_5ab090);
