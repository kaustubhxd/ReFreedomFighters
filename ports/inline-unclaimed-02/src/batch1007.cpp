#include "ff.h"
// batch1007.cpp - unclaimed-02 batch 7 (docs/20-unclaimed-02.md). Name from the GC name map (naming only).
// The callee at 0x46d530 (ZItemTemplate::CreateItem, inventory's port, not lifted here) runs as original code;
// the harness stubs it with a logging handler for both sides.

extern "C" u32 THISCALL ext_46d530(u8 *self, u32 a, u32 b);

// 0x46d5d0, ZItemTemplateWeapon::CreateItem(ZGROUP*, unsigned int) (high). The first argument (ZGROUP*) is not read.
// Calls ext_46d530 on this with two stack arguments: the dword at (system interface +0x9b) +0xadc, then the unsigned
// argument. Returns what that call returns (eax). Callee pops 8 bytes.
static u32 THISCALL weaponTemplateCreateItem(u8 *self, u8 *group, u32 arg) {
  (void)group;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *t = *(u8 **)(sys + 0x9b);
  return ext_46d530(self, *(u32 *)(t + 0xadc), arg);
}
PCREG(46d5d0, weaponTemplateCreateItem);
