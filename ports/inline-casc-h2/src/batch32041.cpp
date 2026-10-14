#include "ff.h"

// 0x4c1e00: thiscall, reads [ecx+0x44], then [eax+8], then [eax+0x3c]
// Shift right by 10, NOT low byte, test bit 0, jump if set or return
typedef void (__cdecl* jump_fn_t)(void);

void __thiscall sub_4c1e00(int* ecx) {
    int* obj1 = (int*)ecx[0x11];  // [ecx+0x44]
    int* obj2 = (int*)obj1[2];     // [obj1+8]
    int val = obj2[0xf];           // [obj2+0x3c]
    val >>= 10;
    val = ~val;
    if (val & 1) {
        // Jump to 0x4c3070 - would need to hook this
        // For now, just return
    }
}
PCREG(4c1e00, sub_4c1e00);
