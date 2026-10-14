// batch35094.cpp - cascade s5 batch 35094: 0x4f0ee0 (GUESS set an alpha-style byte, toggling bit 0 of the flags, and refresh the children).
#include "ff.h"

typedef void(THISCALL *v2_t)(void *, u32, s32);
typedef void(THISCALL *c2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4f0ee0, thiscall(v) ret 4. c = [this+0x1c]. v == 0xff clears bit 0 of c (when it was set), any other v sets it (when it was clear); a change calls this slot 0x23c(c, -1). Then byte +0x8e = v, dword +0x18 =
// ([+0x18] & 0xffffff) | (v << 24). When the unaligned dword [+0x2a] is non-zero: for i < unaligned dword [+0x2e] (re-read): [[0x70039c]+0x1aa3] (unaligned) -> object, its [+0x18] object slot 0x12c([+0x2a] + 0x24 + 0x28 * i, this + 0x18).
static void THISCALL fn4f0ee0(u8 *self, u32 v) {
  u32 c = *(u32 *)(self + 0x1c);
  bool change;
  if (v == 0xff) {
    change = (c & 1) != 0;
    c &= 0xfffffffe;
  } else {
    change = (c & 1) == 0;
    c |= 1;
  }
  if (change) (*(v2_t **)self)[0x23c / 4](self, c, -1);
  self[0x8e] = (u8)v;
  *(u32 *)(self + 0x18) = (*(u32 *)(self + 0x18) & 0xffffff) | (v << 24);
  if (rd32u(self + 0x2a) != 0 && rd32u(self + 0x2e) > 0) {
    u32 i = 0;
    do {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *X = (u8 *)rd32u(eng + 0x1aa3);
      u8 *o = *(u8 **)(X + 0x18);
      (*(c2_t **)o)[0x12c / 4](o, rd32u(self + 0x2a) + 0x24 + i * 0x28, (u32)(self + 0x18));
      i++;
    } while (i < rd32u(self + 0x2e));
  }
}
PCREG(4f0ee0, fn4f0ee0);
