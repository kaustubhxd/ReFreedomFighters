// batch1902.cpp - unclaimed-66 batch 2 (residue 5): GUESS FUN_6461d0 (the name is a GUESS; the body is from the bytes).
// Thiscall, one stack argument (a name), ret 4. Original: id = (engine db ZSysInterface+0x9b) vtable +0x50(name); then the
// table at this+0x6d (count at this+0x69, 0x38-byte entries) is scanned: the first entry whose dword equals id gives its
// second dword (+4); none gives 0.
#include "ff.h"

// 0x6461d0, GUESS FUN_6461d0.
static u32 THISCALL tableLookupByName(u8 *self, const char *name) {
  u8 *sys = *(u8 **)0x70039c;
  u8 *db = *(u8 **)(sys + 0x9b);
  u32 id = vcall<u32>(db, 0x50, (u32)name);
  u32 count = *(u32 *)(self + 0x69);
  u32 i = 0;
  if (count == 0) return 0;
  u8 *e = self + 0x6d;
  for (;;) {
    if (*(u32 *)e == id) return *(u32 *)(e + 4);
    i++;
    e += 0x38;
    if (i == count) break;
  }
  return 0;
}
PCREG(6461d0, tableLookupByName);
