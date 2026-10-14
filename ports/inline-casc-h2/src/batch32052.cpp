#include "ff.h"

// 0x570620: thiscall(this, source) ret 4 - copy multiple fields
// Copies 5 dwords (offsets 1b0,1b4,1b8,1bc,190) and 1 byte (1a3) from source to this
void __thiscall sub_570620(int* ecx, int* source) {
    *(int*)((char*)ecx + 0x1b0) = *(int*)((char*)source + 0x1b0);
    *(int*)((char*)ecx + 0x1b4) = *(int*)((char*)source + 0x1b4);
    *(int*)((char*)ecx + 0x1b8) = *(int*)((char*)source + 0x1b8);
    *(int*)((char*)ecx + 0x1bc) = *(int*)((char*)source + 0x1bc);
    *(int*)((char*)ecx + 0x190) = *(int*)((char*)source + 0x190);
    *(unsigned char*)((char*)ecx + 0x1a3) = *(unsigned char*)((char*)source + 0x1a3);
}
PCREG(570620, sub_570620);
