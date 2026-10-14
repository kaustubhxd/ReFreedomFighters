// batch38079.cpp - cascade s8 batch 38079: 0x4da440 (copy the state of another widget/node into this one and re-sync its flags, links and children).
#include "ff.h"

extern "C" void THISCALL ext_4dc630(u8 *self, u32 set, u32 clear);   // ret 8
extern "C" void THISCALL ext_4da3c0(u8 *self, u8 *other);            // ret 4
extern "C" void THISCALL ext_4da770(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_4dae60(u8 *self);
extern "C" u8 *THISCALL ext_4daff0(u8 *p);
extern "C" void THISCALL ext_4dbe30(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_4dc030(u8 *self);
extern "C" void THISCALL ext_4dc440(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_4dc970(u8 *self, u8 *p);                // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u8(THISCALL *b0_t)(void *);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

// the flag word of the owner's descriptor (this[0x54] -> [0xc] -> +0x23), or 0x200002 without an owner
static u32 owner_flags(u8 *self) {
  u8 *o = (u8 *)W(self, 0x54);
  return o ? UN32(*(u8 **)(o + 0xc), 0x23) : 0x200002;
}
static u8 *table() { return *(u8 **)(SYS + 0x9b); }

// 0x4da440, thiscall(other) ret 4: the tail of the original is a jump into slot 0x1d0 of this[0x54] (with other[0x54]); the port calls it and returns its value.
static u32 THISCALL fn4da440(u8 *self, u8 *other) {
  u32 old6c = W(self, 0x6c);
  W(self, 0x6c) = W(other, 0x6c);
  if (old6c != 0 && *(u16 *)(self + 0x5a) != 0) {
    if (!(owner_flags(self) & 0x800000)) {
      u8 *n = (u8 *)UN32(SYS, 0x190f);
      SLOT(n, 0x190, v2_t)(n, (u32)self, old6c);
    }
  }
  if (W(self, 0x6c) != old6c) W(self, 0x3c) |= 0x100000;
  u32 ebx = (W(other, 0x3c) & 0xb73ba3ff) | (W(self, 0x3c) & 0x8400000);
  ext_4dc630(self, ebx, ~ebx & 0xbfffffff);
  u8 *t = table();
  if (!SLOT(t, 0x178, b0_t)(t)) {
    if (W(self, 0x68) != 0) {
      W(self, 0x3c) |= 0x1000000;
    } else if ((ebx & 0x8000) || (owner_flags(self) & 0x800000)) {
      if (W(self, 0x6c) != 0 && (owner_flags(self) & 0xa00000)) {
        u8 *obj = (u8 *)UN32(table(), 0x5d35);
        if (obj) {
          u32 r = SLOT(obj, 0x24, v1_t)(obj, (u32)self);
          W(self, 0x3c) |= 0x1008000;
          W(self, 0x68) = r;
        }
      }
    }
  }
  W(self, 0x24) = W(other, 0x24);
  W(self, 0x28) = W(other, 0x28);
  W(self, 0x2c) = W(other, 0x2c);
  W(self, 0x3c) |= 0x100000;
  for (int i = 0; i < 9; i++) W(self, i * 4) = W(other, i * 4);   // 0x4de420: 0x24-byte copy (including the vtable pointer)
  W(self, 0x3c) |= 0x100000;
  u8 *h = (u8 *)UN32(table(), 0x5d31);
  SLOT(h, 0, v1_t)(h, (u32)self);
  ext_4da3c0(self, other);
  if (W(other, 0x3c) & 0x400) ext_4dc030(self);
  if ((W(other, 0x3c) & 0x800) && !(W(self, 0x3c) & 0x800)) {
    ext_4da770(self, 0);
    u32 f = W(self, 0x3c);
    if (f & 0x40000) {
      if (W(self, 0x64) != 0 && (u8)f != 0) {
        u8 *p50 = (u8 *)W(self, 0x50);
        u8 *c = p50 ? (u8 *)W(p50, 0x54) : 0;
        u8 *r = ext_4daff0((u8 *)W(c, 8));
        if (r) {
          SLOT(r, 0x320, v1_t)(r, (u32)self);
          W(self, 0x64) = 0;
        }
      }
      ext_4dae60(self);
    }
    ext_4dc630(self, 0x800, 0);
  }
  if (W(other, 0x3c) & 0x40000) ext_4dbe30(self, 1);
  u8 *p50 = (u8 *)W(self, 0x50);
  if (W(p50, 0x3c) & 0x40040000) {
    ext_4dc630(self, 0x40000000, 0);
    u8 *b = (u8 *)W(self, 0x50);
    if (W(b, 0x3c) & 0x40000) {
      ext_4dc970(self, b);
    } else {
      u8 *arg = 0;
      if ((W(b, 0x3c) & 0x40000000) && *(u16 *)(b + 0x5c) != 0) {
        u8 *X = (u8 *)W(table(), 8);
        u8 *base = (u8 *)SLOT(X, 0x4c, v0_t)(X);
        arg = base + *(u16 *)(b + 0x5c) * 0x70 - 0x70;
      }
      ext_4dc970(self, arg);
    }
  }
  if (W(other, 0x3c) & 0x4000) ext_4dc440(self, 1);
  u8 *o54 = (u8 *)W(self, 0x54);
  u8 *p54 = (u8 *)W(other, 0x54);
  if (o54 && p54) return SLOT(o54, 0x1d0, v1_t)(o54, (u32)p54);
  return 0;
}
PCREG(4da440, fn4da440);
