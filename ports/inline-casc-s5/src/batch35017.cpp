// batch35017.cpp - cascade s5 batch 35017: 0x570930 (GUESS read three bytes and five dwords of a record from a stream object).
#include "ff.h"

extern "C" u8 THISCALL ext_5626d0(u8 *self, u8 *s);   // ret 4, bool in AL
typedef void(THISCALL *v1_t)(void *, void *);

// 0x570930, thiscall(s) ret 4, returns bool. When 0x5626d0(this, s) is true, s reads (slot 0x68: byte, slot 0x40: dword) into this+0x1a0, +0x1a1, +0x1a2 (bytes) and
// +0x1b0, +0x1b4, +0x1b8, +0x1bc, +0x190 (dwords), and the result is true; otherwise false.
static u8 THISCALL fn570930(u8 *self, u8 *s) {
  if (!ext_5626d0(self, s)) return 0;
  (*(v1_t **)s)[0x68 / 4](s, self + 0x1a0);
  (*(v1_t **)s)[0x68 / 4](s, self + 0x1a1);
  (*(v1_t **)s)[0x68 / 4](s, self + 0x1a2);
  (*(v1_t **)s)[0x40 / 4](s, self + 0x1b0);
  (*(v1_t **)s)[0x40 / 4](s, self + 0x1b4);
  (*(v1_t **)s)[0x40 / 4](s, self + 0x1b8);
  (*(v1_t **)s)[0x40 / 4](s, self + 0x1bc);
  (*(v1_t **)s)[0x40 / 4](s, self + 0x190);
  return 1;
}
PCREG(570930, fn570930);
