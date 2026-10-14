#include "ff.h"

// 0x4e5080: thiscall(this, arg) ret 4 - table lookup
// Reads table pointer from [arg+0x80], index from [ecx+0xc], returns [table + index]
int __thiscall sub_4e5080(int* ecx, int* arg) {
    int* table = (int*)arg[0x20];  // [arg+0x80]
    int index = *(int*)((char*)ecx + 0xc);
    return table[index];
}
PCREG(4e5080, sub_4e5080);
