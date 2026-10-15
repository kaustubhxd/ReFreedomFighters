// batch66082.cpp - cascade s4 batch 66082: 0x4c29a0 (tier H row from the queue, redone by Sonnet).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x4c29a0, thiscall(w) ret 4, returns al = 1 (this = t): t[4] &= ~0x40; writer w: slot 0x10 (0x40)(u16 t[0x48]), slot 0x40(u16 t[0x4a]), slot 0x18 (0x60)(u8 t[0x4c]), slot 0x60(u8 t[0x4d]),
// then seven floats (raw bits) t[0x4e], 0x52, 0x56, 0x5a, 0x5e, 0x62, 0x66 through slot 0x13 (0x4c).
static u8 THISCALL fn4c29a0(u8 *t, u8 *w) {
  void **vt = *(void ***)w;
  wr(t + 4, rd(t + 4) & 0xffffffbf);
  ((v1_t)vt[0x40 / 4])(w, *(u16 *)(t + 0x48));
  ((v1_t)vt[0x40 / 4])(w, *(u16 *)(t + 0x4a));
  ((v1_t)vt[0x60 / 4])(w, t[0x4c]);
  ((v1_t)vt[0x60 / 4])(w, t[0x4d]);
  static const u8 offs[7] = {0x4e, 0x52, 0x56, 0x5a, 0x5e, 0x62, 0x66};
  for (int i = 0; i < 7; i++) ((v1_t)vt[0x4c / 4])(w, rd(t + offs[i]));
  return 1;
}
PCREG(4c29a0, fn4c29a0);
