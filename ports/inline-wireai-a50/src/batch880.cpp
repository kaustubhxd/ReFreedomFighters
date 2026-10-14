// batch880.cpp - area 50 (residue-09 candidate): 0x4d9350 [40 instr, thiscall, two stack args (ret 8); GUESS "build a local helper
// from a1, run it on a2 and pass its result to this"]. SEH frame not reproduced (fs:[0] writes not compared). The helper calls are
// stood in: local ctor 0x4cbe80(a1), 0x4cc690, 0x4cc1d0(a2) (returns the value), this method 0x4d92e0(value), and the local dtor 0x4cbec0.
#include "ff.h"

extern "C" void THISCALL ext_4cbe80(void *local, u32 a1);   // helper ctor (stood in)
extern "C" void THISCALL ext_4cc690(void *local);           // helper step (stood in)
extern "C" u32 THISCALL ext_4cc1d0(void *local, u32 a2);    // helper query (stood in)
extern "C" void THISCALL ext_4d92e0(void *self, u32 v);     // this method (stood in)
extern "C" void THISCALL ext_4cbec0(void *local);           // helper dtor (stood in)

// 0x4d9350 (name GUESS).
static void THISCALL Build4d9350(u8 *self, u32 a1, u32 a2) {
  u8 local[0x90];
  ext_4cbe80(local, a1);
  ext_4cc690(local);
  u32 v = ext_4cc1d0(local, a2);
  ext_4d92e0(self, v);
  ext_4cbec0(local);
}
PCREG(4d9350, Build4d9350);
