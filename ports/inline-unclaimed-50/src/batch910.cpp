// batch910.cpp - residue-9 slice: three short bodies, each read in full.
//  0x4976d0 [thiscall, one stack arg (a word; only its low 16 bits are read), ret 4, returns a dword]: 0 for a zero word, else
//           dword at this+0x51 - 0x20 + 32 * word.
//  0x650fd0 [thiscall, two stack args (a float, a dword), ret 8, void]: this+0x80 = dword, this+0x84 = float; this+0x88 = 0 when the
//           float equals the constant at 0x6785d0 (ordered compare), else 1.
//  0x628e90 [cdecl, four stack args, no pop, void]: calls 0x628c80 (cdecl, six words: 0x6f4408, a, 0, b, c, d; the caller pops 0x18).
//           0x628c80 is stood in.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" void ext_628c80(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);   // stood in; cdecl, six words

// 0x4976d0 (no name in the map).
static u32 THISCALL Index4976d0(u8 *self, u32 w) {
  u16 w16 = (u16)w;
  if (w16 == 0) return 0;
  return U32(self, 0x51) - 0x20 + ((u32)w16 << 5);
}
PCREG(4976d0, Index4976d0);

// 0x650fd0 (no name in the map).
static void THISCALL Set650fd0(u8 *self, float f, u32 v) {
  U32(self, 0x80) = v;
  F32(self, 0x84) = f;
  U8(self, 0x88) = (f == G(float, 0x6785d0)) ? 0 : 1;
}
PCREG(650fd0, Set650fd0);

// 0x628e90 (no name in the map).
void Wrap628e90(u32 a, u32 b, u32 c, u32 d) {
  ext_628c80(0x6f4408u, a, 0u, b, c, d);
}
PCREG(628e90, Wrap628e90);
