// batch35114.cpp - cascade s5 batch 35114: 0x571690 (GUESS write three bytes and five dwords of a record to a stream; counterpart of 0x570930).
#include "ff.h"

extern "C" u8 THISCALL ext_563490(u8 *self, u8 *s);   // thiscall, ret 4, bool in AL
typedef void(THISCALL *v1_t)(void *, u32);

// 0x571690, thiscall(s) ret 4, returns bool. When 0x563490(this, s) is true: s slot 0x60 with the bytes +0x1a0, +0x1a1, +0x1a2 and s slot 0x3c with the dwords +0x1b0, +0x1b4, +0x1b8, +0x1bc, +0x190 (in that order); true. Otherwise false.
static u8 THISCALL fn571690(u8 *self, u8 *s) {
  if (!ext_563490(self, s)) return 0;
  (*(v1_t **)s)[0x60 / 4](s, self[0x1a0]);
  (*(v1_t **)s)[0x60 / 4](s, self[0x1a1]);
  (*(v1_t **)s)[0x60 / 4](s, self[0x1a2]);
  (*(v1_t **)s)[0x3c / 4](s, *(u32 *)(self + 0x1b0));
  (*(v1_t **)s)[0x3c / 4](s, *(u32 *)(self + 0x1b4));
  (*(v1_t **)s)[0x3c / 4](s, *(u32 *)(self + 0x1b8));
  (*(v1_t **)s)[0x3c / 4](s, *(u32 *)(self + 0x1bc));
  (*(v1_t **)s)[0x3c / 4](s, *(u32 *)(self + 0x190));
  return 1;
}
PCREG(571690, fn571690);
