// batch1051.cpp - unclaimed-04 batch 51 (docs/20-unclaimed-04.md): 0x4c9530 (residue 3).
// thiscall, two stack words (ret 8; only the first is read), returns 0. The word is compared with this+0x48 and this+0x4a (GUESS names).
// A match with +0x48 (when bytes +0x59 and +0x5a are zero) copies a dword from global 0x70039c + 0x40 to this+0x5b and
// sets the word at +0x59 to 0x101; then vtable slot 0x64 is called (thiscall, argument 0x10). A match with +0x4a sets the
// word at +0x58 to 1, clears +0x5a and copies the same dword to this+0x5b (skipped when the destination is the source).
#include "ff.h"

typedef void(THISCALL *slot64_t)(void *self, u32 arg);

// 0x4c9530
static u32 THISCALL unk4c9530(u8 *self, u32 msgArg, u32 unused) {
  (void)unused;  // the exe pops two stack words (ret 8) but reads only the first
  u16 m = (u16)msgArg;
  if (m == *(u16 *)(self + 0x48)) {
    if (self[0x59] == 0 && self[0x5a] == 0) {
      u8 *src = *(u8 **)0x70039c + 0x40;
      if (self + 0x5b != src) *(u32 *)(self + 0x5b) = *(u32 *)src;
      *(u16 *)(self + 0x59) = 0x101;
    }
    ((slot64_t)(*(u32 *)(*(u32 *)self + 0x64)))(self, 0x10);
  }
  if (m == *(u16 *)(self + 0x4a)) {
    *(u16 *)(self + 0x58) = 1;
    self[0x5a] = 0;
    u8 *dst = self + 0x5b;
    u8 *src = *(u8 **)0x70039c + 0x40;
    if (dst != src) *(u32 *)dst = *(u32 *)src;
  }
  return 0;
}
PCREG(4c9530, unk4c9530);
