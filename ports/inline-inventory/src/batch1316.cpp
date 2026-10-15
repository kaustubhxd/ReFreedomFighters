// batch1316.cpp - inventory thread (inline-inventory, 2026-10-11): ZItem::UpdateActivate() (0x471860).
// Each queued activation (list at +0x78, cursor-based) whose time (controller slot 0x9c, a float on the x87 stack)
// is not after the clock (sys+0x40 in 1/1024 s) is removed (slot 0x44) and handed to the holder at +0x60 (slot 0x2e8).
// The walk stops at the first activation that is still in the future (the `ja` exit).
#include "ff.h"

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

static void THISCALL itemUpdateActivate(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  float tnow = (float)(*(s32 *)(sys + 0x40)) * 0.0009765625f;   // cvtdq2ps, then *1/1024
  u8 *holder = vcall<u8 *>(refTable(), 0x58, *(u32 *)(self + 0x60));
  u8 *L = *(u8 **)(self + 0x78);
  if (!L) return;
  u32 cur[4] = {0, 0, 0, 0};                                    // [ebp-0x18]
  vcall<u32>(L, 0x4c, cur);       // (the caller's `push ebx` before this call saves EBX; the callee pops only the cursor)
  u8 *e = vcall<u8 *>(L, 0x64, cur);
  while (e) {
    u8 *r = vcall<u8 *>(G(u8 *, 0x70038c), 0xcc, *(u32 *)e);
    u32 val = *(u32 *)(r + 0x44);                               // [ebp-0xc]
    u8 *C = *(u8 **)(self + 0x74);
    float due = vcall<float>(C, 0x9c, (u32)e);
    if (due > tnow) return;
    vcall<u32>(L, 0x44, cur);
    if (holder) vcall<u32>(holder, 0x2e8, (u32)self, val);
    e = vcall<u8 *>(L, 0x64, cur);
  }
}
PCREG(471860, itemUpdateActivate);
