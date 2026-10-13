// batch13014.cpp - fresh slice 13, batch 14 (docs/20-fresh-13.md), 2026-10-12.
// 0x65c050 GUESS (no name map entry; a ZViewBase-family view: it calls ZViewBase::Clear 0x64a6b0 first): thiscall, one
// argument (a camera view entry), ret 4. Sets up the viewport of the render device object at this+0x10051:
//  - ZViewBase::Clear(entry); the camera is entry->+0xc->+0xc; mode = camera+0x6c, with 1 read as 0;
//    rect = 0x65c530(camera) (thiscall, returns 4 floats); this->vtbl[+0x84](entry).
//  - Once per frame: when entry+0x74 differs from the engine frame counter (sys+0x3c) it is updated, otherwise return.
//  - camera+0x48 bit 0x8000 skips the rest. camera+0x30 selects: 0 -> dev[+0x138](3, mode); 5 -> dev[+0x138](2, 0);
//    4 -> viewport set-up below; anything else -> dev[+0x138](3, 0).
//  - Case 4: the screen size is (this+0x10069 - this+0x10061, this+0x1006d - this+0x10065) as unsigned; the rect is
//    scaled by it and converted to integers by 0x633910 (CRT float -> unsigned, float argument in xmm0, run as exe code).
//    mode 0: dev[+0x134](0, 0, w, h), dev[+0x138](3, 0), dev[+0x134](x0, y0, x1, y1).
//    mode != 0 (letterbox): bar = h - y1 - y0; dev[+0x134](0, 0, w, y0) and (0, h - bar, w, bar), each followed by
//    dev[+0x138](3, 0), then dev[+0x134](x0, y0, x1, y1) and dev[+0x138](3, mode).
//  Integers become floats through double ((float)(double)(u32)), as the exe does (cvtdq2pd + 2^32 table at 0x680aa0).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_64a6b0[], ext_65c530[], ext_633910[];
typedef void(THISCALL *P1)(void *self, void *a);
typedef float *(THISCALL *Rect)(void *self, void *cam);
typedef u32(VECTORCALL *F2U)(float x);
typedef void(THISCALL *Set2)(void *self, u32 a, u32 b);
typedef void(THISCALL *Vp)(void *self, float x, float y, float w, float h);

static inline float u2f(u32 u) { return (float)(double)u; }
static inline u32 f2u(float x) { return ((F2U)(void *)ext_633910)(x); }

static void THISCALL fn65c050(u8 *self, u8 *entry) {
  ((P1)(void *)ext_64a6b0)(self, entry);
  u8 *cam = AT(u8 *, AT(u8 *, entry, 0xc), 0xc);
  u8 *dev = AT(u8 *, self, 0x10051);
  u32 mode = AT(u32, cam, 0x6c);
  if (mode == 1)
    mode = 0;
  float *rc = ((Rect)(void *)ext_65c530)(self, cam);
  ((P1)VT(self, 0x84))(self, entry);
  u32 now = AT(u32, G(u8 *, 0x70039c), 0x3c);
  if (AT(u32, entry, 0x74) == now)
    return;
  AT(u32, entry, 0x74) = now;
  u32 w = AT(u32, self, 0x10069) - AT(u32, self, 0x10061);
  u32 h = AT(u32, self, 0x1006d) - AT(u32, self, 0x10065);
  if (AT(u32, cam, 0x48) & 0x8000)
    return;
  u32 kind = AT(u32, cam, 0x30);
  if (kind == 0) {
    ((Set2)VT(dev, 0x138))(dev, 3, mode);
    return;
  }
  if (kind == 5) {
    ((Set2)VT(dev, 0x138))(dev, 2, 0);
    return;
  }
  if (kind != 4) {
    ((Set2)VT(dev, 0x138))(dev, 3, 0);
    return;
  }
  float fw = u2f(w);
  u32 x0 = f2u(rc[0] * fw);
  float fh = u2f(h);
  u32 y0 = f2u(rc[1] * fh);
  u32 x1 = f2u(rc[2] * fw);
  u32 y1 = f2u(rc[3] * fh);
  if (mode != 0) {
    float bar = u2f(h - y1 - y0);
    float fy0 = u2f(y0);
    ((Vp)VT(dev, 0x134))(dev, 0.0f, 0.0f, fw, fy0);
    ((Set2)VT(dev, 0x138))(dev, 3, 0);
    ((Vp)VT(dev, 0x134))(dev, 0.0f, fh - bar, fw, bar);
    ((Set2)VT(dev, 0x138))(dev, 3, 0);
    ((Vp)VT(dev, 0x134))(dev, u2f(x0), fy0, u2f(x1), u2f(y1));
    ((Set2)VT(dev, 0x138))(dev, 3, mode);
    return;
  }
  ((Vp)VT(dev, 0x134))(dev, 0.0f, 0.0f, fw, fh);
  ((Set2)VT(dev, 0x138))(dev, 3, 0);
  ((Vp)VT(dev, 0x134))(dev, u2f(x0), u2f(y0), u2f(x1), u2f(y1));
}
PCREG(65c050, fn65c050);
