// batch311.cpp - unclaimed-03 batch 11 (docs/20-unclaimed-03.md): ZOnScreenDisplay::MapIconAdd(float*, EMAPICON, bool,
// ZCHAROBJ*) at 0x5aa660. Name from the GC name map (medium, GUESS). A leaf: no calls. The HUD map-icon table is kept in
// the display object; the index is the count at this+0x69d, which is then incremented.
#include "ff.h"

// 0x5aa660, ZOnScreenDisplay::MapIconAdd (medium, GUESS). idx = [this+0x69d]. Copies the three floats of pos to
// this+0x6a1 + 12*idx; stores kind at this+0x7c1 + 4*idx; stores the low byte of flag at this+0x881 + idx; stores obj at
// this+0x821 + 4*idx; then [this+0x69d] += 1 and the byte at this+0x899 is set to 1. The stores run in this order, and
// some of the arrays overlap (0x6a1 table and 0x7c1 table), so the order matters. Callee pops 0x10 (ret 0x10).
static void THISCALL onScreenMapIconAdd(u8 *self, u32 pos, u32 kind, u32 flag, u32 obj) {
  u32 idx = *(u32 *)(self + 0x69d);
  u32 *p = (u32 *)pos;
  u32 *dst = (u32 *)(self + 0x6a1 + idx * 12);
  dst[0] = p[0];
  dst[1] = p[1];
  dst[2] = p[2];
  *(u32 *)(self + 0x7c1 + idx * 4) = kind;
  self[0x881 + idx] = (u8)flag;
  *(u32 *)(self + 0x821 + idx * 4) = obj;
  *(u32 *)(self + 0x69d) += 1;
  self[0x899] = 1;
}
PCREG(5aa660, onScreenMapIconAdd);
