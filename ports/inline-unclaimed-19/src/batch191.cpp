// batch191.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
// Three call-free functions: an indexed slot read with a range check, a last-element read, and a UTF-8 encoder.
#include "ff.h"

// 0x5a4720: slot read. idx in [3, 6] reads the dword at +0xe9 + (idx - 3) * 4; otherwise returns 0.
// Stack arg (ret 4). Range check is signed (js, jg). GUESS: an indexed table read.
static u32 THISCALL slotRead_5a4720(u8 *self, u32 idx) {
    s32 k = (s32)idx - 3;
    if (k >= 0 && (s32)idx <= 6) return *(u32 *)(self + 0xe9u + (u32)k * 4u);
    return 0u;
}
PCREG(5a4720, slotRead_5a4720);

// 0x4ce4e0: n = dword at this+0x18; reads arr[n - 1] (arr is the stack argument). If that is 0, returns 0;
// otherwise returns arr[n - 1] + (2 - n) * 4, all mod 2^32. GUESS: a last-entry offset lookup.
static u32 THISCALL lastEntry_4ce4e0(u8 *self, u32 arr) {
    u32 n = *(u32 *)(self + 0x18);
    u32 v = *(u32 *)(arr + n * 4u - 4u);
    if (v == 0u) return 0u;
    return v + (2u - n) * 4u;
}
PCREG(4ce4e0, lastEntry_4ce4e0);

// 0x4cc6e0: UTF-8 encoder. out in ECX, codepoint in EDX (fastcall, plain ret). Writes 1 to 4 bytes plus a zero
// terminator byte after the last one (out[1] for 1 byte, out[2] for 2, out[3] for 3, out[4] for 4) and returns the
// length. GUESS: a codepoint-to-UTF-8 helper.
static u32 FASTCALL utf8Put_4cc6e0(u8 *out, u32 cp) {
    if (cp <= 0x7fu) {
        out[0] = (u8)cp;
        out[1] = 0;
        return 1u;
    }
    if (cp <= 0x7ffu) {
        out[2] = 0;
        out[0] = (u8)((cp >> 6) | 0xc0u);
        out[1] = (u8)((cp & 0x3fu) | 0x80u);
        return 2u;
    }
    if (cp <= 0xffffu) {
        out[3] = 0;
        out[0] = (u8)((cp >> 12) | 0xe0u);
        out[1] = (u8)(((cp >> 6) & 0x3fu) | 0x80u);
        out[2] = (u8)((cp & 0x3fu) | 0x80u);
        return 3u;
    }
    out[4] = 0;
    out[0] = (u8)((cp >> 18) | 0xf0u);
    out[1] = (u8)(((cp >> 12) & 0x3fu) | 0x80u);
    out[2] = (u8)(((cp >> 6) & 0x3fu) | 0x80u);
    out[3] = (u8)((cp & 0x3fu) | 0x80u);
    return 4u;
}
PCREG(4cc6e0, utf8Put_4cc6e0);
