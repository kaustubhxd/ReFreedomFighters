// batch2407.cpp - decomp area 24, batch 2407: CSewerMenu::EnableButtons() (0x5706f0), thiscall, plain ret.
// The string at (*(self+0x94)) + 0x48 is compared with three constant strings in the exe image:
//   0x6a8794 equal -> self[0x1a1] = 0.
//   0x6a7808 or 0x6a7810 equal (the second is only tested when the first is not equal) -> self[0x1a0..0x1a1] = 0.
// self[0x1a0] = 1 and self[0x1a2] = 1 are set first; self[0x1a0] = 0 at the end when self[0x1a3] == 0.
#include "ff.h"

static bool strEq(const char *a, const char *b) {
  for (;; ++a, ++b) {
    if (*a != *b)
      return false;
    if (*a == 0)
      return true;
  }
}

// 0x5706f0
static void THISCALL sewerEnableButtons(u8 *self) {
  self[0x1a0] = 1;
  self[0x1a2] = 1;
  const char *s = (const char *)(*(u8 **)(self + 0x94) + 0x48);
  if (strEq(s, (const char *)0x6a8794u))
    self[0x1a1] = 0;
  bool zero = strEq(s, (const char *)0x6a7808u) || strEq(s, (const char *)0x6a7810u);
  if (zero)
    *(u16 *)(self + 0x1a0) = 0;
  if (self[0x1a3] == 0)
    self[0x1a0] = 0;
}
PCREG(5706f0, sewerEnableButtons);
