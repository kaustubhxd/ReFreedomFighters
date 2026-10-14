// batch35057.cpp - cascade s5 batch 35057: 0x4931d0 (GUESS scan an embedded list for the first ready entry and reset or consume it).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, void *);
typedef u8 *(THISCALL *g1p_t)(void *, void *);

// 0x4931d0, thiscall, no arguments. The list object embedded at this+0x1c: slot 0x4c(&it), p = slot 0x64(&it) (null: done). Loop over p: s = p + 4; a non-zero byte p[5]: when byte s[0] is zero fall
// to the reset below, otherwise s[2] = 0, list slot 0x44(&it) and return; a zero p[5] fetches the next p (null: reset using the last s). Reset: word s[0..1] = 1, byte s[2] = 0, byte [this+0xbbf] = 1,
// dword [this+0x14] = 0.
static void THISCALL fn4931d0(u8 *self) {
  u32 it[3];
  u8 *L = self + 0x1c;
  (*(v1_t **)L)[0x4c / 4](L, it);
  u8 *p = (*(g1p_t **)L)[0x64 / 4](L, it);
  if (!p) return;
  u8 *s;
  for (;;) {
    s = p + 4;
    if (p[5] != 0) {
      if (s[0] == 0) break;
      s[2] = 0;
      (*(v1_t **)L)[0x44 / 4](L, it);
      return;
    }
    p = (*(g1p_t **)L)[0x64 / 4](L, it);
    if (!p) break;
  }
  s[0] = 1;
  s[1] = 0;
  s[2] = 0;
  self[0xbbf] = 1;
  *(u32 *)(self + 0x14) = 0;
}
PCREG(4931d0, fn4931d0);
