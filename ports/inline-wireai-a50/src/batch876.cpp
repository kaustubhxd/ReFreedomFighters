// batch876.cpp - area 50 (residue-09 candidate): 0x5ecfd0 [33 instr, thiscall, two stack args (an object and a dword), ret 8;
// GUESS "forward the state of this to an object's method"]. Nothing happens unless the dword pointed to by this+0x3a is non-zero.
// When the byte at +0xa6 is set: this.vt+0x20(object, dword) and the byte is cleared. When the byte at +0x35 is set: object.vt+0x2c
// with (dword +0x36, dword +0x3a, this+0x76, this+0xa7, byte +0x5e).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x5ecfd0 (name GUESS).
static void THISCALL Fwd5ecfd0(u8 *self, u8 *o, u32 a2) {
  if (U32(FP(self, 0x3a), 0) == 0) return;
  if (U8(self, 0xa6) != 0) {
    vcall<void>(self, 0x20, o, a2);
    U8(self, 0xa6) = 0;
  }
  if (U8(self, 0x35) != 0) {
    u32 b = U8(self, 0x5e);
    vcall<void>(o, 0x2c, U32(self, 0x36), U32(self, 0x3a), self + 0x76, self + 0xa7, b);
  }
}
PCREG(5ecfd0, Fwd5ecfd0);
