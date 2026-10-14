#include "ff.h"

// 0x4e53d0: thiscall(this, arg1, arg2) ret 8 - complex 2-param indexed access
// Reads [arg1+0x80] as table, [ecx+0xc] as field, dereferences [table+arg2*4+field+4]+field
int __thiscall sub_4e53d0(int* ecx, int* arg1, int arg2) {
    int field = ecx[3];            // [ecx + 0xc]
    int* table = (int*)arg1[0x20]; // [arg1 + 0x80]
    int* addr = (int*)((char*)table + arg2 * 4); // lea: table + arg2*4
    int val = *(int*)((char*)addr + field + 4);  // dereference [addr + field + 4]
    return val + field;
}
PCREG(4e53d0, sub_4e53d0);
