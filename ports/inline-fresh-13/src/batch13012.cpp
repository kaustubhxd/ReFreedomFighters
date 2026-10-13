// batch13012.cpp - fresh slice 13, batch 12 (docs/20-fresh-13.md), 2026-10-12.
// 0x4952d0 ZEngineGeomControl::UpdateMovedGeoms() (name map high). Thiscall, no arguments.
// Profiler blocks (GUESS meaning): when both floats sys+0x9c7 and sys+0x9c3 are non-zero (NaN counts as non-zero),
// t = sys->vtbl[+0x1c8](0x67a7f8, line) (thiscall, ret 8, 64-bit result in edx:eax), then sys->vtbl[+0x178 begin /
// +0x17c end](t_lo, t_hi, 0x68e15c "hasmovedlist") (thiscall, ret 0xc); sys = *(0x70039c).
// The id list at this+4 (count +0xcc) is resolved through the engine db (sys+0x9b)->vtbl[+0x54](id) (thiscall, ret 4);
// found geoms get SetControl 0x4dc630(geom; 0, 0x20000000) (ret 8) and are compacted in place. Byte +0xd0 == 0: count
// = 0, end block, return. Otherwise count = found; for each geom without flag 0x200000 (+0x3c): flag 0x40000 -> 0x4dabe0
// (thiscall, no args), else when db->vtbl[+0x70]() (bool) is false -> 0x4d96d0(geom; 0) (ret 4); then the end block,
// this->vtbl[+0xc]() and count = 0.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4dc630[], ext_4dabe0[], ext_4d96d0[];
typedef u64(THISCALL *Time2)(void *self, u32 file, u32 line);
typedef void(THISCALL *Prof3)(void *self, u32 lo, u32 hi, u32 name);
typedef u8 *(THISCALL *Find1)(void *self, u32 id);
typedef void(THISCALL *SetCtl2)(void *self, u32 a, u32 b);
typedef void(THISCALL *V0)(void *self);
typedef u8(THISCALL *B0)(void *self);
typedef void(THISCALL *V1)(void *self, u32 a);

static inline u8 *sys() { return (u8 *)G(u32, 0x70039c); }
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

static bool profOn(u8 *s) { return AT(float, s, 0x9c7) != 0.0f && AT(float, s, 0x9c3) != 0.0f; }

static void prof(u32 line, u32 slot) {
  u8 *s = sys();
  u64 t = ((Time2)VT(s, 0x1c8))(s, 0x67a7f8, line);
  s = sys();
  ((Prof3)VT(s, slot))(s, (u32)t, (u32)(t >> 32), 0x68e15c);
}

static void THISCALL updateMovedGeoms(u8 *self) {
  if (profOn(sys()))
    prof(0x259, 0x178);
  u32 k = 0;
  if (AT(u32, self, 0xcc) != 0) {
    u32 *out = (u32 *)(self + 4);
    u32 *in = (u32 *)(self + 4);
    u32 i = 0;
    do {
      u8 *db = AT(u8 *, sys(), 0x9b);
      u8 *g = ((Find1)VT(db, 0x54))(db, *in);
      if (g) {
        ((SetCtl2)(void *)ext_4dc630)(g, 0, 0x20000000);
        *out++ = (u32)g;
        k++;
      }
      i++;
      in++;
    } while (i != AT(u32, self, 0xcc));
  }
  if (!AT(u8, self, 0xd0)) {
    AT(u32, self, 0xcc) = 0;
    if (profOn(sys()))
      prof(0x260, 0x17c);
    return;
  }
  AT(u32, self, 0xcc) = k;
  if (k) {
    u32 j = 0;
    u32 *p = (u32 *)(self + 4);
    do {
      u8 *g = (u8 *)*p;
      u32 fl = AT(u32, g, 0x3c);
      if (!(fl & 0x200000)) {
        if (fl & 0x40000) {
          ((V0)(void *)ext_4dabe0)(g);
        } else {
          u8 *db = AT(u8 *, sys(), 0x9b);
          if (!((B0)VT(db, 0x70))(db))
            ((V1)(void *)ext_4d96d0)(g, 0);
        }
      }
      j++;
      p++;
    } while (j != AT(u32, self, 0xcc));
  }
  if (profOn(sys()))
    prof(0x260, 0x17c);
  ((V0)VT(self, 0xc))(self);
  AT(u32, self, 0xcc) = 0;
}
PCREG(4952d0, updateMovedGeoms);
