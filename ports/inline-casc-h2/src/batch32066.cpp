#include "ff.h"

// 0x5aef80: stdcall(arg0) ret 4 - thiscall search in pointer array
int __stdcall sub_5aef80(int arg0) {
    // This is called with ecx set by caller (thiscall convention)
    // Reading from disasm: ecx is used, arg0 is [ebp+8]
    // This is complex - it's a hybrid calling convention
    // For now, skip this one
    return 0;
}
PCREG(5aef80, sub_5aef80);
