// batch330.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x60eeb0, the cursor reader of batch 319 with unit 68 (thiscall, ret 8,
// GUESS). Same as 0x60ee10 (flag at +0x11, reset increments [this+0xc] and clears the cursor, success sets [this+0x10]) with the byte size
// 68 * n and 68 * cursor (the code computes 17x then shifts left by 2). buf.vtbl[0x2c](buf, 68*cursor, 68*n, &slot, count), stdcall.
#include "ff.h"

typedef u32(__attribute__((stdcall)) * slot2c_330_t)(u32, u32, u32, u32, u32);

static u32 THISCALL cursorRead_60eeb0(u8 *self, u32 pp, u32 pout) {
    u32 slot = 0u;
    *(u32 *)pout = 0u;
    u32 n = *(u32 *)pp;
    if (n > *(u32 *)(self + 4u)) return 0u;
    u32 buf = *(u32 *)self;
    if (buf == 0u) return slot;
    u32 cnt;
    if (*(u8 *)(self + 0x11u) == 0u && *(u32 *)(self + 8u) + n < *(u32 *)(self + 4u)) {
        cnt = 0x1800u;
    } else {
        *(u32 *)(self + 0xcu) += 1u;
        cnt = 0x2800u;
        *(u8 *)(self + 0x11u) = 0u;
        *(u32 *)(self + 8u) = 0u;
    }
    u32 eax = ((slot2c_330_t)*(u32 *)(*(u32 *)buf + 0x2cu))(buf, *(u32 *)(self + 8u) * 68u, n * 68u, (u32)&slot, cnt);
    if (eax == 0u) {
        *(u8 *)(self + 0x10u) = 1u;
        *(u32 *)pout = *(u32 *)(self + 8u);
        *(u32 *)(self + 8u) += n;
    }
    return slot;
}
PCREG(60eeb0, cursorRead_60eeb0);
