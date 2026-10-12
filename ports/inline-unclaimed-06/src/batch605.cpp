// batch605.cpp - unclaimed-06 claim 5 (docs/20-unclaimed-06.md): ZDamageBox::CopyEventDataBlock(DBREAD&). Thiscall, one
// argument, ret 4. Names are from the GC name map (naming only). The callee 0x4e5ef0 is original code (it reads through
// DBREAD, which the harness stubs with serial_stubs.dbread_patch).
#include "ff.h"

extern "C" u8 THISCALL ext_4e5ef0(void *dbread);   // original code, returns a bool in al; ecx = the DBREAD reference

// 0x5db150, ZDamageBox::CopyEventDataBlock(DBREAD&) (high): stores the callee's byte result at this+0x88 and
// (result != 0) as a dword at this+0x60.
static void THISCALL damageBoxCopyEventDataBlock(u8 *self, void *dbread) {
  u8 r = ext_4e5ef0(dbread);
  self[0x88] = r;
  *(u32 *)(self + 0x60) = (r != 0);
}
PCREG(5db150, damageBoxCopyEventDataBlock);
