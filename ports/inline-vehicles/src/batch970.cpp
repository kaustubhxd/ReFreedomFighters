// batch970.cpp - residue-04 (core todo), batch 970: the two CopyEventDataBlock forwarders (push ebp; mov ebp,esp; pop ebp; jmp):
//   0x4b89c0 -> 0x4b8a30 (ZRelayMessageList::CopyEventDataBlock body, thiscall(this, DBREAD&), ret 4; stood in)
//   0x4c8dc0 -> 0x4c8e20 (ZShotActivate::CopyEventDataBlock body, thiscall(this, DBREAD&), ret 4; stood in)
// A tail jump passes ECX and the argument on unchanged, so each port forwards its two parameters.
#include "ff.h"

extern "C" void THISCALL ext_4b8a30(void *self, void *db);   // stood in by the checker
extern "C" void THISCALL ext_4c8e20(void *self, void *db);   // stood in by the checker

// 0x4b89c0 (vtable) -> 0x4b8a30.
static void THISCALL fwdRelayCopy(u8 *t, void *db) {
  ext_4b8a30(t, db);
}
PCREG(4b89c0, fwdRelayCopy);

// 0x4c8dc0 (vtable) -> 0x4c8e20.
static void THISCALL fwdShotCopy(u8 *t, void *db) {
  ext_4c8e20(t, db);
}
PCREG(4c8dc0, fwdShotCopy);
