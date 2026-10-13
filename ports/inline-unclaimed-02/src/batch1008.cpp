#include "ff.h"
// batch1008.cpp - unclaimed-02 batch 8 (docs/20-unclaimed-02.md). Name from the GC name map (medium; naming only).

// 0x4e6ed0, ZRunParamAnim::Key(int, float&) (medium, GUESS name). The sub-object at this+0xc is walked through its
// vtable: slot +0x4c is called once with a flag pointer, then slot +0x5c returns an item (eax) and sets the flag. While
// the flag is set, the item's key (dword +4) is compared with the argument; on a match the item's dword +0x18 is stored
// through the second argument and the result is true. Otherwise the result is false. Callee pops 8 bytes.
static u8 THISCALL runParamAnimKey(u8 *self, s32 key, u32 *outp) {
  u8 *esi = self + 0xc;
  u32 flag = 0;
  vcall<void, u32 *>(esi, 0x4c, &flag);
  u8 *item = vcall<u8 *, u32 *>(esi, 0x5c, &flag);
  if (flag == 0)
    return 0;
  for (;;) {
    if (key == *(s32 *)(item + 4)) {
      *outp = *(u32 *)(item + 0x18);
      return 1;
    }
    item = vcall<u8 *, u32 *>(esi, 0x5c, &flag);
    if (flag == 0)
      return 0;
  }
}
PCREG(4e6ed0, runParamAnimKey);
