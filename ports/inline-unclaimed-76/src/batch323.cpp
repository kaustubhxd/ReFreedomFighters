// batch323.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two small members (GUESS).
// 0x604430 (thiscall, ret 8): idx = (u16) [global 0x724278].[+0x3c].vtbl[0](arg1) (one stack argument, callee pops); [[this+8] + idx*4] = arg2.
// 0x613900 (thiscall, plain ret, returns this): base ctor 0x65a380 (exe, thiscall, no arguments), then vtbl = 0x6bd8b4 and three
// dwords at +0xb9a8, +0xb9ac, +0xb9b0 are zeroed.
#include "ff.h"

extern "C" u32 THISCALL ext_65a380(u8 *self);

typedef u32(THISCALL * slot0_323_t)(u32, u32);

static void THISCALL setIndexed_604430(u8 *self, u32 arg1, u32 arg2) {
    u32 obj = *(u32 *)(G(u32, 0x724278u) + 0x3cu);
    u32 idx = (u16)((slot0_323_t)*(u32 *)(*(u32 *)obj))(obj, arg1);
    *(u32 *)(*(u32 *)(self + 8u) + idx * 4u) = arg2;
}
PCREG(604430, setIndexed_604430);

static u32 THISCALL ctor_613900(u8 *self) {
    ext_65a380(self);
    *(u32 *)self = 0x6bd8b4u;
    *(u32 *)(self + 0xb9a8u) = 0u;
    *(u32 *)(self + 0xb9acu) = 0u;
    *(u32 *)(self + 0xb9b0u) = 0u;
    return (u32)self;
}
PCREG(613900, ctor_613900);
