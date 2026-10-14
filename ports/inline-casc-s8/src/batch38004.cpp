// batch38004.cpp - cascade s8 batch 38004: 0x651380 (per-frame step of an engine object).
#include "ff.h"

extern "C" u32 THISCALL ext_6511d0(u8 *self);
extern "C" u32 THISCALL ext_6500b0(u8 *self);
extern "C" u32 THISCALL ext_651180(u8 *self);
extern "C" void ext_634d10(void *dst, u32 val, u32 n);   // cdecl memset thunk
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(*c2_t)(void *, u32);   // cdecl, caller pops
#define VT(o) (*(u8 ***)(o))
#define SLOT(o, off, T) ((T)(*(u8 **)((u8 *)*(void **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)

// 0x651380, thiscall, no args, plain ret. Runs only when engine byte +0x1a9a and this+0x33 are set; resets the counters at +0x34..+0x58, then runs the
// virtual step chain (slots 0x24, 0xd0, 0x84, 0x10c/0x110, 0x70, the 0x128 / 0x6c / 0x120 helpers, 0x1b8, 0x28) and finishes with slot 0x50 and the engine counter +0x3c.
static void THISCALL fn651380(u8 *self) {
  u8 *eng = ENG;
  if (eng[0x1a9a] == 0) return;
  if (self[0x33] == 0) return;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x40) = 0;
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x50) = 0;
  *(u32 *)(self + 0x54) = 0;
  *(u32 *)(self + 0x58) = 0;
  if ((u8)SLOT(self, 0x24, v0_t)(self)) {
    SLOT(self, 0xd0, v0_t)(self);
    u8 *e = ENG;
    u8 *o = (u8 *)SLOT(e, 0x1b0, v0_t)(e);
    if (o && (u8)SLOT(o, 0xc, v0_t)(o)) SLOT(self, 0x84, v0_t)(self);
    if ((u8)ext_6511d0(self)) {
      SLOT(self, 0x10c, v1_t)(self, 4);
      SLOT(self, 0x110, v0_t)(self);
    }
    if ((u8)ext_6500b0(self)) SLOT(self, 0x70, v0_t)(self);
    if ((u8)ext_651180(self)) {
      s32 i = *(s32 *)(self + 0x78);
      if (i < *(s32 *)(self + 0x7c)) {
        do {
          SLOT(self, 0x128, c2_t)(self, 0x679e6c);
          i++;
        } while (i < *(s32 *)(self + 0x7c));
      }
      u8 **vt = VT(self);
      u32 a = ((v0_t)vt[0xf0 / 4])(self);
      u32 b = SLOT(self, 0xec, v0_t)(self);
      ((v3_t)vt[0x6c / 4])(self, *(u32 *)(self + 0x74), b, a);
      u32 w = SLOT(self, 0xf0, v0_t)(self);
      u32 h = SLOT(self, 0xec, v0_t)(self);
      ext_634d10(*(void **)(self + 0x74), 0, w * h);
    }
    e = ENG;
    o = (u8 *)SLOT(e, 0x1b0, v0_t)(e);
    if (!(o && (u8)SLOT(o, 0xc, v0_t)(o))) {
      if (SLOT(self, 0x1a4, v0_t)(self)) SLOT(self, 0x120, v1_t)(self, 0);
    }
    *(u32 *)(self + 0x7c) = *(u32 *)(self + 0x78);
    *(u32 *)(self + 0x78) = 0xa;
    SLOT(self, 0x1b8, v0_t)(self);
    e = ENG;
    o = (u8 *)SLOT(e, 0x1b0, v0_t)(e);
    if (o) {
      if (self[0x80] != 0) {
        self[0x80] = 0;
        SLOT(o, 0x2c, v0_t)(o);
        u8 *e2 = ENG;
        *(u32 *)(e2 + 0xa07) = 0;
        e2[0xa0b] = 0;
      }
      SLOT(o, 0, v0_t)(o);
    }
    SLOT(self, 0x28, v0_t)(self);
  }
  SLOT(self, 0x50, v0_t)(self);
  *(u32 *)(ENG + 0x3c) += 1;
}
PCREG(651380, fn651380);
