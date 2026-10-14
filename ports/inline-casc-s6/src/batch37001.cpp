// batch37001.cpp - cascade s6 batch 37001: 0x4dc2b0.
#include "ff.h"

typedef void(THISCALL *w_t)(void *, void *, u32);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v0_t)(void *);

// 0x4dc2b0, thiscall(a) ret 4, bool: serialises this entry into stream a (slot 0x10 = write(ptr, size)): the byte run at +0x59, the flags +0x3c
// (bit 0x20000000 cleared when an ancestor of the owner at +0x54 carries 0x100bbd, 0x40001000 always cleared), then the blocks selected by the flags,
// and finally asks the owner (slot 0x10) to write itself; returns 0 when it says no.
static u32 THISCALL fn4dc2b0(u8 *self, u8 *a) {
  void *s = a;
  (*(w_t **)s)[4](s, self + 0x59, 1);
  u8 *owner = *(u8 **)(self + 0x54);
  u32 flags = *(u32 *)(self + 0x3c);
  u32 t = owner ? *(u32 *)(*(u8 **)(owner + 0xc) + 0x23) : 0x200002;
  if ((t & 0x100000) && owner) {
    u8 *p = *(u8 **)(owner + 0xc);
    while (p) {
      if (*(u32 *)(p + 0x23) == 0x100bbd) { flags &= 0xdfffffff; break; }
      p = *(u8 **)(p + 0xc);
    }
  }
  flags &= 0xbfffefff;
  (*(w_t **)s)[4](s, &flags, 4);
  if (flags & 0x100000) {
    (*(w_t **)s)[4](s, self, 0x24);
    (*(w_t **)s)[4](s, self + 0x24, 0xc);
    (*(w_t **)s)[4](s, self + 0x30, 0xc);
    (*(w_t **)s)[4](s, self + 0x40, 0xc);
    (*(w_t **)s)[4](s, self + 0x4c, 4);
    (*(w_t **)s)[4](s, self + 0x6c, 4);
  }
  if (flags & 0x40000) {
    u32 dx = *(u16 *)(self + 0x5c);
    u8 *e = 0;
    u8 *eng = *(u8 **)0x70039c;
    if (dx) {
      void *m = *(void **)(*(u8 **)(eng + 0x9b) + 8);
      e = (u8 *)(*(v1_t **)m)[0x5c / 4](m, dx);
    }
    u32 var4 = 0xffff;
    if (e && e[0x1c]) {
      u8 *q = *(u8 **)e;
      if (q) {
        void *m = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 8);
        u32 r = (*(v0_t **)m)[0x4c / 4](m);
        s32 d = (s32)(*(u32 *)(q + 8) - r);
        var4 = (u32)(u16)(d / 0x70);
      }
    }
    (*(w_t **)s)[4](s, &var4, 2);
  }
  void *o = *(void **)(self + 0x54);
  if (o) {
    u8 r = (u8)(*(v1_t **)o)[4](o, (u32)a);
    if (!r) return r;
  }
  return 1;
}
PCREG(4dc2b0, fn4dc2b0);
