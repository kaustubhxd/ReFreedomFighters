// batch785.cpp - unclaimed-77 claim 15 (docs/20-unclaimed-77.md): ZEngineDataBase::CreateGlobalStripColiTree() (medium). Thiscall, no
// arguments, plain ret. The callee 0x4edc10 is stubbed in the harness (GUESS): thiscall, one stack argument, ret 4.
#include "ff.h"

extern "C" void THISCALL ext_4edc10(void *self, u32 arg);   // stubbed (GUESS): the tree builder

// 0x48edc0, ZEngineDataBase::CreateGlobalStripColiTree() (medium).
static void THISCALL engineDataBaseCreateGlobalStripColiTree(u8 *self) {
  u32 arg = *(u32 *)(self + 0xafc);
  u8 *rm = G(u8 *, 0x70039c);
  u8 *p = *(u8 **)(rm + 0x1aa3);
  u8 *q = *(u8 **)(p + 0x1c);
  ext_4edc10(q, arg);
}
PCREG(48edc0, engineDataBaseCreateGlobalStripColiTree);
