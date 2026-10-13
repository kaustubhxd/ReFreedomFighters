// batch322.cpp - 0x4cf0e0 (area 71 leaf, residue 10). stdcall with one argument (a pointer), ret 4. Sets dword [p+4] = 1,
// dword [p] = 0.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void STDCALL setPairOneZero(u8 *p) {
  U32(p, 4) = 1u;
  U32(p, 0) = 0u;
}
PCREG(4cf0e0, setPairOneZero);
