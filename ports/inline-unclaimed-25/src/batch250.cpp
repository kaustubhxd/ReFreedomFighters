// batch250.cpp - unclaimed area 25, slice floor(addr/16) mod 20 == 4.
#include "ff.h"

extern "C" void FASTCALL ext_4de420(u8 *dst, u8 *src);   // copies 0x24 bytes from src to dst (plain ret), original code

typedef u8 *(THISCALL *F0)(u8 *self);
typedef u32 (THISCALL *F2)(u8 *self, u8 *a, u32 *out);

static inline u32 rdw(u8 *p, u32 off) { return *(u32 *)(p + off); }

// 0x478a00, thiscall, ret 8 (stack args: a1, out). Returns eax.
// Flag set (byte this+0x5d2 nonzero): ext_4de420(a1, this+0x5e7) copies 0x24 bytes, then out[0..2] = dwords at this+0x5db,
// +0x5df, +0x5e3, and eax = the last of them.
// Flag clear: tail call. o = this->vslot[0x20](this), then return o->vslot[0x80](o, a1, out) with the same stack args.
// Map name ZActor::CanPlayAnimSegment is a GUESS: the flag-set body only copies a 12-byte value.
static u32 THISCALL copyTriple(u8 *self, u8 *a1, u32 *out) {
  if (*(u8 *)(self + 0x5d2) == 0) {
    u8 *vt = *(u8 **)self;
    u8 *o = ((F0)rdw(vt, 0x20))(self);
    u8 *ovt = *(u8 **)o;
    return ((F2)rdw(ovt, 0x80))(o, a1, out);
  }
  ext_4de420(a1, self + 0x5e7);
  out[0] = rdw(self, 0x5db);
  out[1] = rdw(self, 0x5df);
  out[2] = rdw(self, 0x5e3);
  return out[2];
}
PCREG(478a00, copyTriple);
