// batch13017.cpp - fresh slice 13, batch 17 (docs/20-fresh-13.md), 2026-10-12.
// 0x4f7b10 ZSlider::ClassInit() (name map high): thiscall, no arguments. Packed layout.
//  - +0xa7 = 0x10; ZCONTROL::ClassInit 0x4f9bc0.
//  - Children list 1 (+0x50, next +0x60, object +0x54): stop at the first child whose type flags (object+0xc -> +0x23;
//    0x200002 without an object) lack 0x100000; skip children whose vtbl[+0x1e0](0x100033) is false; the first match
//    is the button: +0xab = db[+0x4c](button); this->vtbl[+0x2c4]() returns a sender that gets slot 0x34c(0x200000,
//    +0xab, this, 10.0f, 1).
//  - Children list 2 (+0x54, previous via ZBaseGeom::GetPrev 0x4db520): stop at the first child with flag 0x100000;
//    the first child answering vtbl[+0x1e0](0x20002c) with byte +0x21 == 0x80 is the window object: +0xaf = db[+0x4c]
//    (it); size = GetSize(it+8) (0x4db7c0); with a button, half = 2.0f * (button geom size.x) (db[+0x58] then GetSize).
//    Range +0xa3 == 0 (ordered equal): +0xa3 = size.x * 2.0f - half, pos = GetPos (0x4db500), pos.x -= half.
//    Otherwise it->vtbl[+0x258]({(range + half) / size.x * 0.5f, 1.0f}, 0) (a scale), pos = GetPos, pos.x -= 2 * half.
//    Then it->vtbl[+0x70](&pos).
//  - Without a button, and with range 0 and no window object, the logger (0x700390)[+0x20](file, line 0x6d / 0x6f)
//    gets slot 0x2c (cdecl: logger, format, name or "<NONAME>").
//  - this->vtbl[+0x364](+0x97), this->vtbl[+0x36c](0, 0).
// The /GS cookie check is not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_4f9bc0[], ext_4db520[], ext_4db7c0[], ext_4db500[];
typedef void(THISCALL *P0)(void *self);
typedef u32(THISCALL *R0)(void *self);
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef u8(THISCALL *B1)(void *self, u32 a);
typedef void(THISCALL *PV)(void *self, float *v);
typedef void(THISCALL *P2)(void *self, u32 a, u32 b);
typedef void(THISCALL *Send5)(void *self, u32 a, u32 b, void *c, float d, u32 e);
typedef void(THISCALL *Scale)(void *self, float *s, u32 z);
typedef u8 *(THISCALL *Log2)(void *self, u32 file, u32 line);
typedef void (*Printf)(void *lg, u32 fmt, u32 name);

static inline u8 *db() { return AT(u8 *, G(u8 *, 0x70039c), 0x9b); }

static inline u32 flags(u8 *o) { return o ? AT(u32, AT(u8 *, o, 0xc), 0x23) : 0x200002; }

static void logerr(u8 *self, u32 line, u32 fmt) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *l = ((Log2)VT(lg, 0x20))(lg, 0x69b214, line);
  u32 name = AT(u32, self, 4) ? AT(u32, self, 4) : 0x67c8e8;
  ((Printf)VT(l, 0x2c))(l, fmt, name);
}

static void THISCALL fn4f7b10(u8 *self) {
  AT(u32, self, 0xa7) = 0x10;
  ((P0)(void *)ext_4f9bc0)(self);
  for (u8 *n = AT(u8 *, self, 0x50); n; n = AT(u8 *, n, 0x60)) {
    u8 *o = AT(u8 *, n, 0x54);
    if (!(flags(o) & 0x100000))
      break;
    if (((B1)VT(o, 0x1e0))(o, 0x100033)) {
      AT(u32, self, 0xab) = ((R1)VT(db(), 0x4c))(db(), (u32)o);
      u8 *s = (u8 *)((R0)VT(self, 0x2c4))(self);
      ((Send5)VT(s, 0x34c))(s, 0x200000, AT(u32, self, 0xab), self, 10.0f, 1);
      break;
    }
  }
  for (u8 *n = AT(u8 *, self, 0x54); n; n = (u8 *)((R0)(void *)ext_4db520)(n)) {
    u8 *o = AT(u8 *, n, 0x54);
    if (flags(o) & 0x100000)
      break;
    if (o && ((B1)VT(o, 0x1e0))(o, 0x20002c) && AT(u8, o, 0x21) == 0x80) {
      AT(u32, self, 0xaf) = ((R1)VT(db(), 0x4c))(db(), (u32)o);
      float size[3];
      ((PV)(void *)ext_4db7c0)(AT(u8 *, o, 8), size);
      float half = 0.0f;
      if (AT(u32, self, 0xab)) {
        u8 *b = (u8 *)((R1)VT(db(), 0x58))(db(), AT(u32, self, 0xab));
        float bs[3];
        ((PV)(void *)ext_4db7c0)(AT(u8 *, b, 8), bs);
        half = bs[0] * G(float, 0x680a60);
      }
      float range = AT(float, self, 0xa3);
      float x;
      if (range == 0.0f) {
        AT(float, self, 0xa3) = size[0] * G(float, 0x680a60) - half;
        ((PV)(void *)ext_4db500)(AT(u8 *, o, 8), size);
        x = size[0] - half;
      } else {
        float sc[2];
        sc[0] = (range + half) / size[0] * G(float, 0x67a6ac);
        sc[1] = 1.0f;
        ((Scale)VT(o, 0x258))(o, sc, 0);
        ((PV)(void *)ext_4db500)(AT(u8 *, o, 8), size);
        x = size[0] - (half + half);
      }
      size[0] = x;
      ((PV)VT(o, 0x70))(o, size);
      break;
    }
  }
  if (!AT(u32, self, 0xab))
    logerr(self, 0x6d, 0x69b23c);
  if (AT(float, self, 0xa3) == 0.0f && !AT(u32, self, 0xaf))
    logerr(self, 0x6f, 0x69b270);
  ((R1)VT(self, 0x364))(self, AT(u32, self, 0x97));
  ((P2)VT(self, 0x36c))(self, 0, 0);
}
PCREG(4f7b10, fn4f7b10);
