// batch369.cpp - 0x410b90 (gap band). cdecl(p): free(p[+8]) (exe 0x634d52, cdecl); then zero the dwords at p, p+4, p+8, p+0xc,
// p+0x10.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void ext_634d52(void *p);   // free (exe code, cdecl)

static void freeAndZeroHead(u8 *p) {
  ext_634d52((void *)(unsigned long)U32(p, 0x8));
  U32(p, 0x0) = 0;
  U32(p, 0x4) = 0;
  U32(p, 0x8) = 0;
  U32(p, 0xc) = 0;
  U32(p, 0x10) = 0;
}
PCREG(410b90, freeAndZeroHead);
