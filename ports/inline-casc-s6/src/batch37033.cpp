// batch37033.cpp - cascade s6 batch 37033: 0x47f8d0.
#include "ff.h"

extern "C" void STDCALL ext_610100(u8 *a);                          // ret 4
extern "C" void THISCALL ext_4e1b30(u8 *a);                         // plain ret
extern "C" void THISCALL ext_4db2c0(u8 *self, u32 *a, u32 *b);     // ret 8
extern "C" void THISCALL ext_4dcdf0(u8 *self, u32 v);               // ret 4
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a, u32 b);        // ret 8
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *fn0_t)(u8 *);
#define F32(o) (*(u32 *)(self + (o)))

// engine allocator lookup, inlined twice in the original: 0 when the engine object at 0x70038c (slot 0x20) knows p, else the id stored at p-4 (made through slot 0xac
// when still 0), or what the engine's range callback ([+8], for p in [+0xc, +0x10)) returns.
static u32 handleOf(u8 *p) {
  u8 *g = *(u8 **)0x70038c;
  if ((*(v1_t **)g)[0x20 / 4](g, (u32)p)) return 0;
  g = *(u8 **)0x70038c;
  fn0_t fn = *(fn0_t *)(g + 8);
  if (fn && *(u32 *)(g + 0xc) <= (u32)p && (u32)p < *(u32 *)(g + 0x10)) return (u32)fn(p);
  if (*(u32 *)(p - 4) == 0) (*(v1_t **)g)[0xac / 4](g, (u32)p);
  return *(u32 *)(p - 4);
}

// 0x47f8d0, thiscall(a) ret 4: binds this entry to its engine object. Looks up the object named by this+4 (default string 0x67c8e8, 0x67c398) through
// [[engine+0x9b]+8] slot 8, gives it the handle of this (slot 0x214), links this->slot 0x20's object to it (slot 0x288), copies this+8's fields into the object's
// +8 sub-object (0x4dcdf0, 0x4dc630), lets the object update (slot 0x74), stores the object's handle at this+0x18, runs slot 0 of this and finally 0x4dc630 on this+8 with flags.
static void THISCALL fn47f8d0(u8 *self, u8 *a) {
  u32 v34[9], v10[3];
  ext_610100(a);
  ext_4e1b30(a);
  u32 ebx = *(u32 *)(*(u8 **)(self + 8) + 0x3c);
  ext_4db2c0(*(u8 **)(self + 8), v34, v10);
  u32 name = F32(4) ? F32(4) : 0x67c8e8;
  void *x = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 8);
  u8 *r = (u8 *)(*(v4_t **)x)[8 / 4](x, name, 0x67c398, 0, 0);
  u8 *esi = *(u8 **)(r + 0x54);
  u32 h1 = handleOf(self);
  (*(v1_t **)esi)[0x214 / 4](esi, h1);
  void *o = (void *)(*(v0_t **)self)[0x20 / 4](self);
  (*(v3_t **)o)[0x288 / 4](o, (u32)esi, 0, 1);
  ext_4dcdf0(*(u8 **)(esi + 8), *(u32 *)(*(u8 **)(self + 8) + 0x6c));
  ext_4dc630(*(u8 **)(esi + 8), *(u8 *)(*(u8 **)(self + 8) + 0x3c) | 0x800000, 1);
  (*(v2_t **)esi)[0x74 / 4](esi, (u32)v34, (u32)v10);
  F32(0x18) = handleOf(esi);
  (*(v0_t **)self)[0](self);
  ebx = (ebx & 0xffffff01) | 0x2001;
  ext_4dc630(*(u8 **)(self + 8), ebx, ~ebx);
}
PCREG(47f8d0, fn47f8d0);
