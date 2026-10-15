// batch1317.cpp - inventory thread (inline-inventory, 2026-10-11): ZItem::UpdateDeactivate() (0x471930).
// The deactivation list (+0x74, cursor-based): an entry with no holder is removed; one whose time (controller slot 0x9c,
// float on the x87 stack) is after the clock stops the walk; otherwise its two owners (+0x70, +0x6c, slot 0x40) are
// told, the entry is removed and the holder gets slot 0x210(1).
#include "ff.h"

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

static void THISCALL itemUpdateDeactivate(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  float tnow = (float)(*(s32 *)(sys + 0x40)) * 0.0009765625f;
  u8 *C = *(u8 **)(self + 0x74);
  if (!C) return;
  u32 cur[4] = {0, 0, 0, 0};                                    // [ebp-0x14]
  vcall<u32>(C, 0x4c, cur);
  u8 *e = vcall<u8 *>(C, 0x64, cur);
  while (e) {
    u8 *holder = vcall<u8 *>(refTable(), 0x58, *(u32 *)e);
    if (!holder) {
      vcall<u32>(C, 0x44, cur);
    } else {
      float due = vcall<float>(C, 0x9c, (u32)e);
      if (due > tnow) return;
      vcall<u32>(*(u8 **)(self + 0x70), 0x40, *(u32 *)e);
      vcall<u32>(*(u8 **)(self + 0x6c), 0x40, *(u32 *)e);
      vcall<u32>(C, 0x44, cur);
      vcall<u32>(holder, 0x210, 1u);
    }
    e = vcall<u8 *>(C, 0x64, cur);
  }
}
PCREG(471930, itemUpdateDeactivate);
