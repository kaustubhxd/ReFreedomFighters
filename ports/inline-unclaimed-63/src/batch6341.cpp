// batch6341.cpp - unclaimed-63 gap-band batch 41: 0x4db7e0 (C-set; no GC name), thiscall, no stack arguments, returns a pointer or 0.
//   esi = this[+0x54]; flags = esi ? [[esi+0xc]+0x23] : 0x200002. If (flags & 0x100000) == 0: esi = this[+0x50]; if esi: esi = esi[+0x54].
//   Loop while esi != 0: if esi->vtbl[+0x1e0](0x100020) (thiscall, one stack argument, callee pops 4) returns nonzero: return esi.
//   Else esi = esi->vtbl[+0x20]() (thiscall, no arguments). When esi becomes 0 return 0.
#include "ff.h"

typedef u8(THISCALL * pred_fn)(void *, u32);
typedef u32(THISCALL * next_fn)(void *);

// 0x4db7e0 (C-set).
static u8 *THISCALL unnamed4db7e0(u8 *self) {
  u8 *esi = (u8 *)*(u32 *)(self + 0x54);
  u32 flags = esi ? *(u32 *)(*(u32 *)(esi + 0xc) + 0x23) : 0x200002u;
  if ((flags & 0x100000u) == 0) {
    esi = (u8 *)*(u32 *)(self + 0x50);
    if (esi == 0)
      return 0;
    esi = (u8 *)*(u32 *)(esi + 0x54);
  }
  if (esi == 0)
    return 0;
  for (;;) {
    u32 vt = *(u32 *)esi;
    if (((pred_fn)(*(u32 *)(vt + 0x1e0)))((void *)esi, 0x100020u) != 0)
      return esi;
    esi = (u8 *)((next_fn)(*(u32 *)(*(u32 *)esi + 0x20)))((void *)esi);
    if (esi == 0)
      return 0;
  }
}
PCREG(4db7e0, unnamed4db7e0);
