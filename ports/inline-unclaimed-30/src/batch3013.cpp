// batch3013.cpp - unclaimed-30: batch 13 (docs/20-unclaimed-30.md, claim 1). ZPlayer::DragBody(ZGEOM*) [map 0x4831d0; thiscall,
// ret 4]. If this+0x417 has bits 0x1800: those bits are cleared; the message table's slot 0x58 object (if any) gets slot 0x128 with
// a word from slot 0x114 (0x68bedc, 0x280); this's slot 0x594 is called with the geometry if it is not null; this+0x413 is zero.
// Otherwise this+0x413 is zeroed; with a geometry: this's slot 0x514 is called, bit 0x800 is set in this+0x417, the message table's
// slot 0x4c value for this goes to slot 0x114 (0x68becc, 0x277) and the word goes to the geometry's slot 0x128; this+0x413 becomes
// the slot 0x4c value for the geometry.
// NOTE (exe defect, see the claim table): the bit-set path pushes this+0x413 and never pops it, so the exe returns with its stack
// off by four. The port has the balanced return.
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL playerDragBody(u8 *self, u8 *g) {
  u32 flags = rd32u(self + 0x417);
  if (flags & 0x1800) {
    u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    wr32u(self + 0x417, flags & 0xffffe7ffu);
    u8 *t = (u8 *)vcall<u32>(msg, 0x58);
    if (t) {
      u32 w = vcall<u32>(msg, 0x114, (u32)0x68bedc, (u32)0, (u32)0x68bcbc, (u32)0x280, (u32)0, (u32)0);
      vcall<void>(t, 0x128, (u32)(u16)w);
    }
    wr32u(self + 0x413, 0);
    if (g) vcall<void>(self, 0x594, g);
    return;
  }
  wr32u(self + 0x413, 0);
  if (!g) return;
  vcall<void>(self, 0x514);
  wr32u(self + 0x417, rd32u(self + 0x417) | 0x800u);
  u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(msg, 0x4c, self, (u32)0);
  u32 w = vcall<u32>(msg, 0x114, (u32)0x68becc, (u32)0, (u32)0x68bcbc, (u32)0x277, v);
  vcall<void>(g, 0x128, (u32)(u16)w);
  wr32u(self + 0x413, vcall<u32>(msg, 0x4c, g));
}
PCREG(4831d0, playerDragBody);
