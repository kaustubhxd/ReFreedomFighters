#include "ff.h"

// 0x5331c0: add ecx 0x8b, jmp 0x534090
extern "C" int __thiscall ext_534090(int*);
int __thiscall sub_5331c0(int* ecx) {
    return ext_534090((int*)((char*)ecx + 0x8b));
}
PCREG(5331c0, sub_5331c0);

// 0x63fc10: add ecx 0x8270, jmp 0x65f200
extern "C" int __thiscall ext_65f200(int*);
int __thiscall sub_63fc10(int* ecx) {
    return ext_65f200((int*)((char*)ecx + 0x8270));
}
PCREG(63fc10, sub_63fc10);
