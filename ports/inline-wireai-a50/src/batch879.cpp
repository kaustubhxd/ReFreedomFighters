// batch879.cpp - area 50 (residue-09 candidate): 0x460f90 [52 instr, thiscall destructor, ret; GUESS "~object: reset the vtable, run
// the base teardown, then release the held sub-objects (deleting call through vt +0 with 1), skipping the duplicates"].
// SEH frame not reproduced (fs:[0] writes not compared). The base teardown (0x461f00) and the second base step (0x43de70) are stood in.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_461f00(void *self);   // base teardown (stood in)
extern "C" void THISCALL ext_43de70(void *self);   // second base step (stood in)

// 0x460f90 (name GUESS).
static void THISCALL Dtor460f90(u8 *self) {
  U32(self, 0) = 0x6854e0u;
  ext_461f00(self);
  u8 *a = (u8 *)FP(self, 0x72);
  if (a) vcall<void>(a, 0, 1u);
  u8 *b = (u8 *)FP(self, 0x76);
  if (b) vcall<void>(b, 0, 1u);
  u8 *c = (u8 *)FP(self, 0x5c);
  if (c && c != (u8 *)FP(self, 0x72)) vcall<void>(c, 0, 1u);
  u8 *d = (u8 *)FP(self, 0x60);
  if (d && d != (u8 *)FP(self, 0x76)) vcall<void>(d, 0, 1u);
  ext_43de70(self);
}
PCREG(460f90, Dtor460f90);
