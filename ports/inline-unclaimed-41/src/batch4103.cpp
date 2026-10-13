// batch4103.cpp - unclaimed-41 batch 3 (residue 13): ZAnimSequence::Command(unsigned short, void*).
#include "ff.h"

extern "C" void THISCALL ext_4c5090(u8 *self, u32 a1, u32 a2);   // 2 stack arguments (ret 8); checksum stub in the spec (GUESS)
extern "C" void THISCALL ext_4c4fc0(u8 *self);                     // no stack arguments; checksum stub in the spec (GUESS)

// 0x4c4c10, ZAnimSequence::Command(unsigned short, void*) (high): thiscall, two stack arguments (ret 8), returns 1 on every path.
// If cmd == word[+0x48]: if byte[+0x69] == 0: ext_4c5090(+0x4c, +0x50); vt[+0x64](0x10); copy dword G+0x40 to +0x65 (unless
// they are the same address); byte[+0x69] = 1.
// Else if cmd == word[+0x4a]: ext_4c5090(+0x4c, +0x50); ext_4c5090(+0x50, +0x54); ext_4c4fc0().
static u32 THISCALL animSequenceCommand(u8 *self, u32 cmd, u8 *buf) {
  (void)buf;
  typedef void(THISCALL * v1_t)(u8 *, u32);
  if ((u16)cmd == *(u16 *)(self + 0x48)) {
    if (self[0x69] == 0) {
      ext_4c5090(self, *(u32 *)(self + 0x4c), *(u32 *)(self + 0x50));
      (*(v1_t *)(*(u32 *)self + 0x64))(self, 0x10u);
      u8 *src = G(u8 *, 0x70039c) + 0x40;
      if (self + 0x65 != src)
        *(u32 *)(self + 0x65) = *(u32 *)src;
      self[0x69] = 1;
    }
    return 1;
  }
  if ((u16)cmd == *(u16 *)(self + 0x4a)) {
    ext_4c5090(self, *(u32 *)(self + 0x4c), *(u32 *)(self + 0x50));
    ext_4c5090(self, *(u32 *)(self + 0x50), *(u32 *)(self + 0x54));
    ext_4c4fc0(self);
  }
  return 1;
}
PCREG(4c4c10, animSequenceCommand);
