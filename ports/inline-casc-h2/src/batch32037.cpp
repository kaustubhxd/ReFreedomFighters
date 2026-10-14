#include "ff.h"

// 0x4e5450: thiscall(this, arg) ret 4 - arithmetic
// Returns [arg] + 1 + [ecx+8]
int __thiscall sub_4e5450(int* ecx, int* arg) {
    int val1 = arg[0];
    int val2 = *(int*)((char*)ecx + 8);
    return val1 + 1 + val2;
}
PCREG(4e5450, sub_4e5450);

// 0x5eebd0: thiscall(this, arg) ret 4 - conditional setter
// If [ecx+0x45] != arg: store arg at [ecx+0x45] and 1 at [ecx+0x77]
void __thiscall sub_5eebd0(int* ecx, int arg) {
    int* field45 = (int*)((char*)ecx + 0x45);
    if (*field45 != arg) {
        *field45 = arg;
        *(char*)((char*)ecx + 0x77) = 1;
    }
}
PCREG(5eebd0, sub_5eebd0);
