// batch340.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x61ab20 (fastcall: ECX = index, EDX = value, one stack argument arg;
// ret 4; GUESS). If table1[idx] != value or table2[idx] != arg (tables at 0x724970 and 0x7249b0, dword arrays): store both, then call
// obj.vtbl[0x14c] with ECX = the vtable pointer and four stack words (obj, idx, value, arg); the callee pops them.
#include "ff.h"

typedef u32(THISCALL * slot14c_t)(u32 vt, u32 obj, u32 idx, u32 value, u32 arg);

static void FASTCALL set_61ab20(u32 idx, u32 value, u32 arg) {
    u32 *t1 = (u32 *)0x724970u;
    u32 *t2 = (u32 *)0x7249b0u;
    if (t1[idx] == value && t2[idx] == arg) return;
    u32 obj = G(u32, 0x724a00u);
    t1[idx] = value;
    t2[idx] = arg;
    u32 vt = *(u32 *)obj;
    ((slot14c_t)*(u32 *)(vt + 0x14cu))(vt, obj, idx, value, arg);
}
PCREG(61ab20, set_61ab20);
