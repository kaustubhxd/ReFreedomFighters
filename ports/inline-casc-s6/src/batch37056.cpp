// batch37056.cpp - cascade s6 batch 37056: 0x54d760.
#include "ff.h"

extern "C" void ext_634d10(u8 *p, u32 v, u32 n);   // memset thunk, cdecl
typedef u32 (*hook_t)();
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
#define F32(o) (*(u32 *)(self + (o)))
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x54d760, thiscall(src, id) ret 8, returns bool: prepares a stream buffer from the format description src. Runs slot 0x40 of this, clears +0x79 / +0x28 / +0x29, stores src at +0x5d and id at
// +0x39. A negative src+8 (mode 3, compressed) sizes the unit from the type in its low 31 bits (0x11: 0x2000 / src+0x28 * src+0x2c * 4, 0x1000: this+4, else 0x10000), a
// non-negative one (mode 1) takes src+0x14; +0x10 = +0xc * unit (0x18000 for src+0x1c == 6). Zeroes the 0x4028 bytes at +0x7f and in mode 3 asks the object at
// [this+8]+0x8061 (slot 1) for a buffer of 0x2000 / 0x8000 / 0x10000 / 0x18000 bytes, failing (0) when none comes back; other modes <= 2 return 1, anything else the assert hook.
static u32 THISCALL fn54d760(u8 *self, u8 *src, u32 id) {
  (*(v0_t **)self)[0x40 / 4](self);
  *(u8 *)(self + 0x79) = 0;
  *(u8 *)(self + 0x28) = 0;
  F32(0x5d) = (u32)src;
  F32(0x39) = id;
  if ((s32)D32(src, 8) < 0) {
    F32(0x75) = 3;
    F32(0xc) = 1;
    u32 k = D32(src, 8) & 0x7fffffffu;
    if (k == 0x11) {
      u32 d = D32(src, 0x28);
      if (d == 0) {
        F32(0x40a9) = 0;
      } else {
        F32(0x40a9) = (0x2000u / d) * D32(src, 0x2c) * 4;
      }
    } else if (k == 0x1000) {
      F32(0x40a9) = F32(4);
    } else {
      F32(0x40a9) = 0x10000;
    }
  } else {
    F32(0x75) = 1;
    F32(0x40a9) = D32(src, 0x14);
  }
  F32(0x10) = F32(0xc) * F32(0x40a9);
  if (D32(src, 0x1c) == 6) F32(0x10) = 0x18000;
  *(u16 *)(self + 0x7d) = 0x101;
  *(u8 *)(self + 0x7c) = 0;
  F32(0x29) = 0;
  ext_634d10(self + 0x7f, 0, 0x4028);
  F32(0x1c) = F32(0x10);
  s32 mode = (s32)F32(0x75);
  if (mode > 0) {
    if (mode <= 2) return 1;
    if (mode == 3) {
      F32(0x40ad) = 0;
      *(u16 *)(self + 0x40a7) = 0;
      u8 *b = (u8 *)F32(0x5d);
      u32 k = D32(b, 8) & 0x7fffffffu;
      u32 sz;
      if (k == 0x11) sz = 0x2000;
      else if (k == 0x1000) sz = 0x8000;
      else sz = (D32(b, 0x1c) == 6) ? 0x18000 : 0x10000;
      u8 *e = (u8 *)F32(8);
      void *z = *(void **)(e + 0x8061);
      u32 r = (*(v4_t **)z)[1](z, D32(e, 0x802d), D32(b, 0x18), D32(b, 0x20), sz);
      F32(0x29) = r;
      if (!r) {
        *(u16 *)(self + 0x7c) = 0;
        return 0;
      }
      u8 *o = (u8 *)r;
      D32(o, 4) = D32((u8 *)F32(0x5d), 0x1c);
      *(u8 *)(o + 0x57) = *(u8 *)(self + 0x7b);
      (*(v1_t **)o)[2](o, 2);
      return 1;
    }
  }
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 1;
}
PCREG(54d760, fn54d760);
