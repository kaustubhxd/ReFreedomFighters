// batch319.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): two buffer-cursor readers (thiscall, ret 8, GUESS).
// Both: *out = 0; slot = 0; n = *p; if n > [this+4] return 0; buf = [this]; if buf == 0 return slot.
//   0x60ed80: unit 2 (a size of [p]*2 and cursor*2 in bytes); a flag byte at +0xd, reset (0x2800, cursor 0) when set or when the cursor
//             plus n reaches the limit; otherwise 0x1800. buf.vtbl[0x2c](buf, cursor*2, n*2, &slot, count) (stdcall, five arguments).
//             On success (eax == 0): [this+0xc] = 1, *out = cursor, cursor += n. Returns slot.
//   0x60ee10: unit 36 (n*36, cursor*36); flag byte at +0x11; reset increments [this+0xc] and uses 0x2800. buf.vtbl[0x2c] as above.
//             On success: [this+0x10] = 1, *out = cursor, cursor += n. Returns slot.
#include "ff.h"

typedef u32(__attribute__((stdcall)) * slot2c_t)(u32, u32, u32, u32, u32);

static u32 THISCALL cursorRead_60ed80(u8 *self, u32 pp, u32 pout) {
    u32 slot = 0u;
    *(u32 *)pout = 0u;
    u32 n = *(u32 *)pp;
    if (n > *(u32 *)(self + 4u)) return 0u;
    u32 buf = *(u32 *)self;
    if (buf == 0u) return slot;
    u32 cnt;
    if (*(u8 *)(self + 0xdu) == 0u && *(u32 *)(self + 8u) + n < *(u32 *)(self + 4u)) {
        cnt = 0x1800u;
    } else {
        *(u8 *)(self + 0xdu) = 0u;
        cnt = 0x2800u;
        *(u32 *)(self + 8u) = 0u;
    }
    u32 eax = ((slot2c_t)*(u32 *)(*(u32 *)buf + 0x2cu))(buf, *(u32 *)(self + 8u) * 2u, n * 2u, (u32)&slot, cnt);
    if (eax == 0u) {
        *(u8 *)(self + 0xcu) = 1u;
        *(u32 *)pout = *(u32 *)(self + 8u);
        *(u32 *)(self + 8u) += n;
    }
    return slot;
}
PCREG(60ed80, cursorRead_60ed80);

static u32 THISCALL cursorRead_60ee10(u8 *self, u32 pp, u32 pout) {
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
    u32 eax = ((slot2c_t)*(u32 *)(*(u32 *)buf + 0x2cu))(buf, *(u32 *)(self + 8u) * 36u, n * 36u, (u32)&slot, cnt);
    if (eax == 0u) {
        *(u8 *)(self + 0x10u) = 1u;
        *(u32 *)pout = *(u32 *)(self + 8u);
        *(u32 *)(self + 8u) += n;
    }
    return slot;
}
PCREG(60ee10, cursorRead_60ee10);
