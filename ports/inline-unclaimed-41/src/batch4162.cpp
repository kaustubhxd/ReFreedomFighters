// batch4162.cpp - unclaimed-41 batch 51 (residue 0): 0x522880 ZTankIf::SoundEngineStart(OpaqueCallParameters_t&) (thiscall, one stack
// argument a, ret 4). w = this->[0x1c]->vt[0x390](); r = 0x5003d0(ecx = a->[8], 0) (ret 4); 0x5002f0(ecx = r, w) (ret 4). Name from the
// ZTankIf native table (docs/20-mountedgun.md, batch 313 note); callees stubbed in the harness (GUESS).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);       // original, thiscall, one stack word, ret 4 (stubbed)
extern "C" void THISCALL ext_5002f0(u8 *self, u32 word);      // original, thiscall, one stack word, ret 4 (stubbed)

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static void THISCALL fn522880(u8 *self, u8 *a) {
  u8 *e = *(u8 **)(self + 0x1c);
  u32 w = ((u32(THISCALL *)(u8 *))vslot(e, 0x390))(e);
  u8 *r = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0(r, w);
}
PCREG(522880, fn522880);
