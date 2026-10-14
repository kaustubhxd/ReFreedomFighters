#include "ff.h"

// 0x45edb0: mov ecx[8], jmp 0x4db150
extern "C" int __thiscall ext_4db150(int*);
int __thiscall sub_45edb0(int* ecx) {
    return ext_4db150((int*)ecx[2]);  // read [ecx + 8]
}
PCREG(45edb0, sub_45edb0);

// 0x45f030: mov ecx[8], jmp 0x4db600
extern "C" int __thiscall ext_4db600(int*);
int __thiscall sub_45f030(int* ecx) {
    return ext_4db600((int*)ecx[2]);  // read [ecx + 8]
}
PCREG(45f030, sub_45f030);
