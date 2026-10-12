// batch338.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two members (thiscall, ret 4, GUESS).
// 0x6046d0 (scalar deleting destructor): [this] = 0x6b9b7c; free634([this+0xc], 1) (exe wrapper 0x634273, cdecl, two arguments);
//   [this] = 0x69c968; if flag bit 0: free634(this, 0x12); returns this.
// 0x604310 (thiscall, one argument arg, ret 4): 0x603990(this, arg) (exe, thiscall, one argument); val = this.vtbl[0x38](this) (no
//   arguments); arg.vtbl[0](arg, val) (thiscall, one argument; the callee pops it).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(u32 p, u32 size);
extern "C" void THISCALL ext_603990(u8 *self, u32 arg);
typedef u32(THISCALL * slot38_t)(u32 self);
typedef u32(THISCALL * slot0_t)(u32 self, u32 val);

static u32 THISCALL dtor_6046d0(u8 *self, u32 flags) {
    *(u32 *)self = 0x6b9b7cu;
    ext_634273(*(u32 *)(self + 0xcu), 1u);
    *(u32 *)self = 0x69c968u;
    if ((flags & 1u) != 0u) ext_634273((u32)self, 0x12u);
    return (u32)self;
}
PCREG(6046d0, dtor_6046d0);

static void THISCALL link_604310(u8 *self, u32 arg) {
    ext_603990(self, arg);
    u32 vt = *(u32 *)self;
    u32 val = ((slot38_t)*(u32 *)(vt + 0x38u))((u32)self);
    u32 avt = *(u32 *)arg;
    ((slot0_t)*(u32 *)avt)(arg, val);
}
PCREG(604310, link_604310);
