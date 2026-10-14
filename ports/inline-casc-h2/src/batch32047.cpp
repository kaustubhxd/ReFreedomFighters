#include "ff.h"

// 0x5cf7f0: thiscall(this, output) ret 4 - copy three dwords to output
// Copies [ecx+0xc71], [ecx+0xc75], [ecx+0xc79] to [output], [output+4], [output+8]
void __thiscall sub_5cf7f0(int* ecx, int* output) {
    output[0] = *(int*)((char*)ecx + 0xc71);
    output[1] = *(int*)((char*)ecx + 0xc75);
    output[2] = *(int*)((char*)ecx + 0xc79);
}
PCREG(5cf7f0, sub_5cf7f0);
