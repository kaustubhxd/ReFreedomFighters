// batch66080.cpp - cascade s4 batch 66080: 0x5db4f0 (tier H row from the queue, redone by Sonnet).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x5db4f0, thiscall(w) ret 4, returns al = 1 (this = t, w = writer object): t[4] &= ~0x40; w->slot 0x19 (0x64)(t[0x48]); w->slot 0x13 (0x4c)(float t[0x4c]); w->slot 0x13(float t[0x50]); n = t[0x84]->slot 5 (0x14)(); w->slot 0xf (0x3c)(n).
// t[0x84] set: iterate it (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]): w->slot 0x13(float e[9]); w->slot 0xf (0x3c)(e[0]). The floats travel as raw 32-bit values.
static u8 THISCALL fn5db4f0(u8 *t, u8 *w) {
  void **wvt = *(void ***)w;
  wr(t + 4, rd(t + 4) & 0xffffffbf);
  ((v1_t)wvt[0x64 / 4])(w, rd(t + 0x48));
  wvt = *(void ***)w;
  ((v1_t)wvt[0x4c / 4])(w, rd(t + 0x4c));
  wvt = *(void ***)w;
  ((v1_t)wvt[0x4c / 4])(w, rd(t + 0x50));
  u8 *l = *(u8 **)(t + 0x84);
  void **svt = *(void ***)w;
  u32 n = (*(v0r_t **)l)[0x14 / 4](l);
  ((v1_t)svt[0x3c / 4])(w, n);
  l = *(u8 **)(t + 0x84);
  if (l) {
    u32 it[4];
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    l = *(u8 **)(t + 0x84);
    u8 *e = (u8 *)(*(v1r_t **)l)[0x5c / 4](l, (u32)it);
    if (it[0] != 0) {
      do {
        wvt = *(void ***)w;
        ((v1_t)wvt[0x4c / 4])(w, rd(e + 9));
        wvt = *(void ***)w;
        ((v1_t)wvt[0x3c / 4])(w, rd(e));
        l = *(u8 **)(t + 0x84);
        e = (u8 *)(*(v1r_t **)l)[0x5c / 4](l, (u32)it);
      } while (it[0] != 0);
    }
  }
  return 1;
}
PCREG(5db4f0, fn5db4f0);
