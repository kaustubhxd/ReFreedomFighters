// batch37117.cpp - cascade s6 batch 37117: 0x571720.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// One slot of the widget list: takes the next widget of the array at self+0x1cc (cursor +0x230 below the limit +0x22c), places it at (x, 0, 0) and hands it `arg`.
static void place(u8 *self, u32 arg, u32 mode, u32 x) {
  u32 cur = D32(self, 0x230);
  if (cur >= D32(self, 0x22c)) return;
  u8 *w = *(u8 **)(self + 0x1cc + cur * 4);
  D32(self, 0x230) = cur + 1;
  if (!w) return;
  u32 vec[3] = {x, 0, 0};
  vcall<void>(w, 0x260, mode);
  vcall<void>(w, 0x70, (u32)vec);
  vcall<void>(w, 0xbc, 0u);
  vcall<void>(w, 0x284, arg);
}

// 0x571720, thiscall(a, b, c) ret 0xc: unless +0x1a3 is set, places up to three consecutive widgets from the list (a at x = 0 in mode 1, b at x = 300.0f and c at x = 520.0f in
// mode 2), each only when its argument is non-zero and widgets remain.
static void THISCALL fn571720(u8 *self, u32 a, u32 b, u32 c) {
  if (self[0x1a3]) return;
  if (a) place(self, a, 1, 0);
  if (b) place(self, b, 2, 0x43960000u);
  if (c) place(self, c, 2, 0x44020000u);
}
PCREG(571720, fn571720);
