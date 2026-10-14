// batch35092.cpp - cascade s5 batch 35092: 0x50e760 (GUESS hand a looked-up name to a created object and store it in a tagged slot).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4, returns a record {value dword, kind byte at +4}
typedef u8 *(THISCALL *c2_t)(void *, u32, u32);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);
typedef u32(THISCALL *g0_t)(void *);

// 0x50e760, stdcall(s) ret 4. o = [s+0xc] slot 0(0x67a14c, 0); id = *0x5003d0([s+4], 0); e = [engine+0x9b] slot 0x58(id); name = e ? ([e+4] or the default 0x67c8e8) : default; o slot 0x30(name). Then t = 0x5003d0([s+8], 0)
// (value dword, kind byte at +4): kind 4 first calls (value) slot 0x28(); kinds 0 and 4 set value = o slot 0x24() and kind = 4; other kinds are left alone. Finally o slot 0x28().
static void STDCALL fn50e760(u8 *s) {
  u8 *X = *(u8 **)(s + 0xc);
  u8 *o = (*(c2_t **)X)[0](X, 0x67a14c, 0);
  u32 *r1 = ext_5003d0(*(u32 *)(s + 4), 0);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *e = (*(e1_t **)tab)[0x58 / 4](tab, *r1);
  u32 name = 0x67c8e8;
  if (e && *(u32 *)(e + 4)) name = *(u32 *)(e + 4);
  (*(v1_t **)o)[0x30 / 4](o, name);
  u32 *t = ext_5003d0(*(u32 *)(s + 8), 0);
  u8 k = ((u8 *)t)[4];
  if (k == 0 || k == 4) {
    if (k == 4) {
      u8 *ov = (u8 *)t[0];
      (*(v0_t **)ov)[0x28 / 4](ov);
    }
    t[0] = (*(g0_t **)o)[0x24 / 4](o);
    ((u8 *)t)[4] = 4;
  }
  (*(v0_t **)o)[0x28 / 4](o);
}
PCREG(50e760, fn50e760);
