// batch335.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two members (GUESS).
// 0x602c50 (thiscall, one argument (pointer), ret 4, bool in al): if byte [this] == 0, 0x602bc0(this) (exe init, hooked in the fixture);
//   then al = 1 when the four dwords at this+0xa equal the four dwords at the argument, else 0.
// 0x608e30 (thiscall, two arguments a, b, ret 8): f = (a & 1); if (a & 2): f |= 2, and if byte [this+0x13ee] != 0: f |= 4.
//   obj = [this+0x1377]; return obj.vtbl[0x90](obj, 0, 0, f, b, 1.0f, 0) (thiscall with ECX = the vtable pointer; the callee pops 28).
#include "ff.h"

extern "C" void THISCALL ext_602bc0(u8 *self);
typedef u32(THISCALL * slot90_t)(u32 vt, u32 obj, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

static u8 THISCALL match_602c50(u8 *self, u32 arg) {
    if (*(u8 *)self == 0u) ext_602bc0(self);
    for (u32 i = 0; i < 4u; i++) {
        if (*(u32 *)(self + 0xau + 4u * i) != *(u32 *)(arg + 4u * i)) return 0u;
    }
    return 1u;
}
PCREG(602c50, match_602c50);

static u32 THISCALL call_608e30(u8 *self, u32 a, u32 b) {
    u32 f = a & 1u;
    if ((a & 2u) != 0u) {
        f |= 2u;
        if (*(u8 *)(self + 0x13eeu) != 0u) f |= 4u;
    }
    u32 obj = *(u32 *)(self + 0x1377u);
    u32 vt = *(u32 *)obj;
    return ((slot90_t)*(u32 *)(vt + 0x90u))(vt, obj, 0u, 0u, f, b, 0x3f800000u, 0u);
}
PCREG(608e30, call_608e30);
