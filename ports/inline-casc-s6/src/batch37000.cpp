// batch37000.cpp - cascade s6 batch 37000: 0x498cc0.
#include "ff.h"

extern "C" void THISCALL ext_499360(u8 *self, u8 *a, u32 b);  // thiscall, ret 8 (hooked in the spec)
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, void *, u32);

// 0x498cc0, thiscall(a) ret 4: a = bit set object (vtable at +0, byte array at +8, count at +0xc). Walks the 0x380-byte groups of
// 8 entries (0x70 each) hanging off [[this+0x14]+4]; for every set bit it clears the bit and writes the entry index when the entry
// has flag 0x4000000 at +0x3c, otherwise follows the +0x50 chain and calls 0x499360. Ends with a fixed sequence of stream writes.
static void THISCALL fn498cc0(u8 *self, u8 *a) {
  u8 *eng = *(u8 **)0x70039c;
  u8 *tab = *(u8 **)(eng + 0x9b);
  ext_499360(self, a, *(u32 *)(*(u8 **)(tab + 0xadc) + 8));
  u32 base = *(u32 *)(*(u8 **)(self + 0x14) + 4);
  u32 cnt = *(u32 *)(a + 0xc);
  if (cnt) {
    u32 i = 0, off = 0;
    do {
      u32 v = (*(u8 **)(a + 8))[i];
      if (v) {
        u8 *e = (u8 *)(*(u32 *)(*(u8 **)(self + 0x14) + 4) + off);
        for (u32 bit = 1; bit <= 0x80; bit <<= 1, e += 0x70) {
          if (!(v & bit)) continue;
          if (*(u32 *)(e + 0x3c) & 0x4000000) {
            (*(u8 **)(a + 8))[i >> 3] &= (u8)~bit;
            void *s = *(void **)a;
            (*(v1_t **)s)[2](s, 5);
            s32 idx = (s32)((u32)e - base) / 0x70;
            s = *(void **)a;
            (*(v2_t **)s)[4](s, &idx, 4);
          } else {
            u8 *n = e;
            while (*(u8 **)(n + 0x50)) n = *(u8 **)(n + 0x50);
            ext_499360(self, a, (u32)n);
            v = (*(u8 **)(a + 8))[i];
          }
        }
      }
      i++;
      off += 0x380;
    } while (i != *(u32 *)(a + 0xc));
  }
  void *s = *(void **)a;
  u32 m1 = 0xffffffff, w = 0xffff;
  (*(v1_t **)s)[2](s, 5);
  s = *(void **)a; (*(v2_t **)s)[4](s, &m1, 4);
  s = *(void **)a; (*(v1_t **)s)[2](s, 6);
  s = *(void **)a; (*(v2_t **)s)[4](s, &m1, 4);
  s = *(void **)a; (*(v1_t **)s)[2](s, 0xa);
  s = *(void **)a; (*(v2_t **)s)[4](s, &w, 2);
  s = *(void **)a; (*(v1_t **)s)[2](s, 0xb);
  s = *(void **)a; (*(v2_t **)s)[4](s, &m1, 4);
}
PCREG(498cc0, fn498cc0);
