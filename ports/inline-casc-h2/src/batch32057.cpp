#include "ff.h"

extern "C" void __cdecl ext_53b1b0(void);

// 0x534d80: thiscall(this) - conditional path: return or tail-jump
void __thiscall sub_534d80(int* ecx) {
    int val = *(int*)((char*)ecx + 0x52fa);
    if (val != 0) {
        // Tail jump path - hooked in spec
        ext_53b1b0();
    }
}
PCREG(534d80, sub_534d80);
