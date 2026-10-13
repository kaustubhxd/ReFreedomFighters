// batch376.cpp - 0x4102f0 (gap band). cdecl(p): if p != 0: free(p[0]) if nonzero, free(p[+0x10]) if nonzero, free(p[+0x14])
// if nonzero (exe free 0x634d52, cdecl); then zero 0x5a dwords at p. Returns 0 (eax).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void ext_634d52(void *p);   // free (cdecl)

static u32 freeThreeAndZero(u8 *p) {
  if (p == 0)
    return 0;
  if (U32(p, 0x0) != 0)
    ext_634d52((void *)(unsigned long)U32(p, 0x0));
  if (U32(p, 0x10) != 0)
    ext_634d52((void *)(unsigned long)U32(p, 0x10));
  if (U32(p, 0x14) != 0)
    ext_634d52((void *)(unsigned long)U32(p, 0x14));
  for (u32 i = 0; i < 0x5au; i++)
    ((u32 *)p)[i] = 0;
  return 0;
}
PCREG(4102f0, freeThreeAndZero);
