// batch901.cpp - gap band slice: 0x41eee0 ZSysMem::NewWithRef(unsigned int) [thiscall, one stack arg (n), ret 4, returns a pointer].
// The block size is n + 0x10. If this+0x30 is zero, the block comes from the CRT malloc import (0x6762f0, cdecl). Otherwise it comes
// from 0x4d0700 (thiscall: ECX = this+0x31, one argument, ret 4) and n gets bit 30 set. The block header is written at block+8 (n),
// block+4 (1) and block+0xc (0); the returned pointer is block+0x10.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u8 *THISCALL ext_4d0700(void *obj, u32 size);   // stood in by the harness; ret 4

// 0x41eee0 (name map: ZSysMem::NewWithRef(unsigned int)).
static u8 *THISCALL NewWithRef41eee0(u8 *self, u32 n) {
  u32 size = n + 0x10;
  u32 flags = n;
  u8 *blk;
  if (U8(self, 0x30) == 0) {
    blk = ((u8 * (*)(u32))G(u32, 0x6762f0))(size);
  } else {
    blk = ext_4d0700(FP(self, 0x31), size);
    flags |= 0x40000000u;
  }
  U32(blk, 8) = flags;
  U32(blk, 4) = 1;
  U32(blk, 0xc) = 0;
  return blk + 0x10;
}
PCREG(41eee0, NewWithRef41eee0);
