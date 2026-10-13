// batch368.cpp - 0x401090 (gap band). cdecl(p): zero eight dwords at p (rep stosd, ecx = 8); then p[+0x1c] = calloc(1, 0x1070)
// (exe 0x634df4, cdecl). The calloc call is the exe's; the spec hooks it.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void *ext_634df4(unsigned long count, unsigned long size);   // calloc (cdecl)

static void allocAndZero(u8 *p) {
  for (u32 i = 0; i < 8; i++)
    ((u32 *)p)[i] = 0;
  U32(p, 0x1c) = (u32)(unsigned long)ext_634df4(1, 0x1070);
}
PCREG(401090, allocAndZero);
