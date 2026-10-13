// batch4145.cpp - unclaimed-41 batch 45 (core-todo residue-19): 0x4702b0 ZItemState::ReadInput(DBREAD&) (thiscall, one stack argument r,
// ret 4). SEH frame not reproduced (fs:[0] writes not compared). The DBREAD operators are called with ecx = r.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *r);       // DBREAD::operator unsigned int (GUESS stub)
extern "C" float THISCALL ext_4e5e80(u8 *r);     // DBREAD::operator float, returns in st0 (GUESS stub)
extern "C" u32 THISCALL ext_4e5ea0(u8 *r);       // DBREAD read for the helper argument (GUESS stub)
extern "C" void THISCALL ext_4cbe80(u8 *self, u32 x);     // local object constructor, one argument (GUESS stub)
extern "C" void THISCALL ext_4cbee0(u8 *self, u8 *a);     // assign into this+0x61, one argument (GUESS stub)
extern "C" void THISCALL ext_4cbec0(u8 *self);            // local object destructor, no arguments (GUESS stub)

static void THISCALL fn4702b0(u8 *self, u8 *r) {
  *(u32 *)(self + 0x4e) = ext_4e5e60(r);
  self[0x52] = (u8)(ext_4e5e60(r) != 0);
  *(u32 *)(self + 0x53) = ext_4e5e60(r);
  *(float *)(self + 0x57) = ext_4e5e80(r);
  *(float *)(self + 0x5b) = ext_4e5e80(r);
  self[0x5f] = (u8)(ext_4e5e60(r) != 0);
  self[0x60] = (u8)(ext_4e5e60(r) != 0);
  u32 x = ext_4e5ea0(r);
  u32 L90[16];
  ext_4cbe80((u8 *)L90, x);
  ext_4cbee0(self + 0x61, (u8 *)L90);
  ext_4cbec0((u8 *)L90);
  *(u32 *)(self + 0xe1) = ext_4e5e60(r);
  self[0xe5] = (u8)(ext_4e5e60(r) != 0);
}
PCREG(4702b0, fn4702b0);
