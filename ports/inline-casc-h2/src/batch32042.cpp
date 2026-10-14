#include "ff.h"

// 0x4619e0: thiscall(this, arg) ret 4 - byte test with complex indexing
// arg*3*8+4 is offset into array at [ecx+0x1c], test if bits 0 or 1 set
int __thiscall sub_4619e0(int* ecx, int arg) {
    int* array = (int*)ecx[7];  // [ecx+0x1c]
    int index = arg * 3 * 8 + 4;
    unsigned char byte_val = *(unsigned char*)((char*)array + index);
    return (byte_val & 3) ? 1 : 0;
}
PCREG(4619e0, sub_4619e0);
