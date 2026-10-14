// batch821.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
// Reworked by the 12th agent: every stream call is a plain thiscall with one stack word (the movss/push pairs only move
// float bits), so no SSE or asm is needed.
#include "ff.h"

extern "C" void THISCALL ext_4e74d0(u8 *obj, u8 *stream);   // thiscall on this+0x48, ret 4: hooked (GUESS)
typedef void (THISCALL *vs_t)(u8 *stream, u32 arg);

static inline void vcall(u8 *st, u32 slot, u32 arg) { (*(vs_t *)(*(u8 **)st + slot))(st, arg); }

// 0x4a77b0, thiscall(stream) ret 4: clears this[4] bit 0x40, then writes its fields to the stream through vtable slots
// 0x3c/0x44/0x4c (dword/float), 0x54, 0x60 (byte), 0x68 (12-byte vec by pointer), 0x70 (pointer); finally 0x4e74d0. Returns 1.
static u8 THISCALL writeFields_4a77b0(u8 *self, u8 *st) {
  *(u32 *)(self + 4) &= ~0x40u;
#define D(off) (*(u32 *)(self + (off)))
#define B(off) ((u32)self[off])
#define P(off) ((u32)(self + (off)))
  vcall(st, 0x44, D(0x74));
  vcall(st, 0x68, P(0x78));
  vcall(st, 0x4c, D(0xb4));
  vcall(st, 0x60, B(0xb8));
  vcall(st, 0x60, B(0xb9));
  vcall(st, 0x68, P(0xba));
  vcall(st, 0x68, P(0xc6));
  vcall(st, 0x68, P(0xd2));
  vcall(st, 0x68, P(0xde));
  vcall(st, 0x4c, D(0xea));
  vcall(st, 0x4c, D(0xee));
  vcall(st, 0x4c, D(0xf2));
  vcall(st, 0x54, D(0xf6));
  vcall(st, 0x44, D(0xfa));
  vcall(st, 0x3c, D(0xfe));
  vcall(st, 0x68, P(0x102));
  vcall(st, 0x60, B(0x10e));
  vcall(st, 0x60, B(0x10f));
  vcall(st, 0x60, B(0x110));
  vcall(st, 0x3c, D(0x111));
  vcall(st, 0x60, B(0x133));
  vcall(st, 0x68, P(0x11b));
  vcall(st, 0x68, P(0x127));
  vcall(st, 0x3c, D(0x117));
  vcall(st, 0x70, P(0x90));
  vcall(st, 0x68, P(0x84));
#undef D
#undef B
#undef P
  ext_4e74d0(self + 0x48, st);
  return 1;
}
PCREG(4a77b0, writeFields_4a77b0);
