// batch321.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two forwarders (thiscall, ret 8, GUESS).
// 0x60ef50: obj = [this+0x14]; 0x60ef80: obj = [this+0x2c]. Both: out = 0; obj.vtbl[0x2c](obj, a, b, &out, 0x1000) (stdcall, five args,
// a = [ebp+8], b = [ebp+0xc]); return out. The callee writes out.
#include "ff.h"

typedef void(__attribute__((stdcall)) * slot2c_321_t)(u32, u32, u32, u32, u32);

static u32 forward_321(u32 obj, u32 a, u32 b) {
    u32 out = 0u;
    ((slot2c_321_t)*(u32 *)(*(u32 *)obj + 0x2cu))(obj, a, b, (u32)&out, 0x1000u);
    return out;
}

static u32 THISCALL fwd_60ef50(u8 *self, u32 a, u32 b) { return forward_321(*(u32 *)(self + 0x14u), a, b); }
PCREG(60ef50, fwd_60ef50);

static u32 THISCALL fwd_60ef80(u8 *self, u32 a, u32 b) { return forward_321(*(u32 *)(self + 0x2cu), a, b); }
PCREG(60ef80, fwd_60ef80);
