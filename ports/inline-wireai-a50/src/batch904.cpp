// batch904.cpp - gap band slice: 0x41ee20 [thiscall, one stack arg (n), ret 4, returns a pointer (eax); body read to its ret at 0x41ee7f].
// If this+0x49 is zero and the count at this+0x45 is nonzero, the entry this+0x31+4*count gets 0x4d1060 (thiscall, ECX = entry, one
// argument n, ret 4); a nonzero result is returned as is. Otherwise a block of n+0x10 bytes is taken from the CRT malloc import
// (cdecl) when this+0x30 is zero, or from 0x4d0700 (thiscall, ECX = this+0x31, one argument) with bit 30 set on the size word. The
// block header is written at block+8 (flags), block+4 (1), block+0xc (0), and the result is block+0x10.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_4d1060(void *obj, u32 n);      // stood in; ret 4
extern "C" u8 *THISCALL ext_4d0700(void *obj, u32 size);   // stood in (also used by batch901); ret 4

// 0x41ee20 (name GUESS "Alloc41ee20").
static u32 THISCALL Alloc41ee20(u8 *self, u32 n) {
  if (U32(self, 0x49) == 0 && U32(self, 0x45) != 0) {
    void *ent = FP(self, 0x31 + 4 * U32(self, 0x45));
    u32 r = ext_4d1060(ent, n);
    if (r != 0) return r;
  }
  u32 flags = n;
  u8 *blk;
  if (U8(self, 0x30) == 0) {
    blk = ((u8 * (*)(u32))G(u32, 0x6762f0))(n + 0x10);
  } else {
    blk = ext_4d0700(FP(self, 0x31), n + 0x10);
    flags |= 0x40000000u;
  }
  U32(blk, 8) = flags;
  U32(blk, 4) = 1;
  U32(blk, 0xc) = 0;
  return (u32)(blk + 0x10);
}
PCREG(41ee20, Alloc41ee20);
