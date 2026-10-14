// batch35168.cpp - cascade s5 batch 35168: 0x46b9d0 (GUESS dispatch an event id: act on two registered ids, else forward).
#include "ff.h"

extern "C" u32 THISCALL ext_41e680(u8 *self);                  // thiscall, plain ret
extern "C" void THISCALL ext_46b800(u8 *self, u32 a, u8 *b);   // thiscall, ret 8
typedef void(THISCALL *g2_t)(void *, u32, u32 *);
typedef void(THISCALL *h3_t)(void *, u32, u32, u32);
typedef void(THISCALL *h2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x46b9d0, thiscall(a, b) ret 8, returns 0. When this[0x60] != 0: when (u16)a == word [this+0x7c]: v = a; b slot 0x88(0x68884c, &v) (b written into); when v == 3 and the unaligned dword [this+0x8e] is non-zero:
// this slot 0x12c([this+0x8e], word [this+0x92], 0x41e680(this)); then falls through to 0x46b800(this, a, b). Else when (u16)a == word [this+0x92]: this slot 0x2d0(0, 0) and returns 0 without forwarding.
// Everything else (this[0x60] == 0 or no match) forwards through 0x46b800(this, a, b).
static u32 THISCALL fn46b9d0(u8 *self, u32 a, u8 *b) {
  if (*(u32 *)(self + 0x60) != 0) {
    if ((u16)a == *(u16 *)(self + 0x7c)) {
      u32 v = a;
      (*(g2_t **)b)[0x88 / 4](b, 0x68884c, &v);
      if (v == 3 && rd32u(self + 0x8e) != 0) {
        u32 *vt = *(u32 **)self;
        u32 r = ext_41e680(self);
        ((h3_t)vt[0x12c / 4])(self, rd32u(self + 0x8e), *(u16 *)(self + 0x92), r);
      }
    } else if ((u16)a == *(u16 *)(self + 0x92)) {
      (*(h2_t **)self)[0x2d0 / 4](self, 0, 0);
      return 0;
    }
  }
  ext_46b800(self, a, b);
  return 0;
}
PCREG(46b9d0, fn46b9d0);
