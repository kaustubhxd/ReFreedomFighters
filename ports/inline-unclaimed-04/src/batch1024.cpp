// batch1024.cpp - unclaimed-04 batch 25 (docs/20-unclaimed-04.md): 0x44e970, thiscall, five stack arguments (ret 0x14).
// Stores vtable 0x680ce4, then tail-jumps to 0x43ea20 with the same five arguments. The port calls 0x43ea20 with a copy of
// the five arguments: the callee pops its copy (ret 0x14) and this function's own ret 0x14 pops the caller's arguments.
#include "ff.h"

extern "C" void THISCALL ext_43ea20(void *self, u32 a, u32 b, u32 c, u32 d, u32 e);  // original code (hooked by address)

// 0x44e970
static void THISCALL unk44e970TailToVtable(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  *(u32 *)self = 0x680ce4;
  ext_43ea20(self, a, b, c, d, e);
}
PCREG(44e970, unk44e970TailToVtable);
