// batch984.cpp - residue-11 (core todo), batch 984: ZFFPRIVATESTDOBJ::CopyDataBlock(DBLK*), 0x5a65f0, thiscall, ret 4.
// Base copy 0x610100(this, dblk) (stood in). Two reads 0x4e12e0(dblk, &v, 1) (the jump to 0x4e11e0, stood in; the value is written to
// the pointer): a = first, b = second. [this+0x18] = 2 when a != 0, else (b != 0); then the finish 0x4e1b30(dblk) (stood in).
#include "ff.h"

extern "C" void THISCALL ext_610100(void *self, void *dblk);     // base copy (stood in)
extern "C" void THISCALL ext_4e12e0(void *dblk, u32 *out, u32 n); // DBLK int read (stood in)
extern "C" void THISCALL ext_4e1b30(void *dblk);                 // DBLK finish (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5a65f0 ZFFPRIVATESTDOBJ::CopyDataBlock(DBLK*).
static void THISCALL privStdObjCopy(u8 *t, u8 *dblk) {
  ext_610100(t, dblk);
  u32 a = 0;
  ext_4e12e0(dblk, &a, 1);
  u32 b = 0;
  ext_4e12e0(dblk, &b, 1);
  if (a != 0)
    D(t, 0x18) = 2;
  else
    D(t, 0x18) = b != 0;
  ext_4e1b30(dblk);
}
PCREG(5a65f0, privStdObjCopy);
