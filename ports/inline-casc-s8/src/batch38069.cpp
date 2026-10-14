// batch38069.cpp - cascade s8 batch 38069: 0x5709d0 (resolve the object's named handles and pick up the flagged child objects).
#include "ff.h"

extern "C" void THISCALL ext_563750(u8 *self, u32 a, u32 b);  // ret 8
extern "C" void THISCALL ext_563610(u8 *self, u32 a);         // ret 4
extern "C" void THISCALL ext_570310(u8 *self);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8(THISCALL *b1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u8 *table() { return *(u8 **)(ENG + 0x9b); }
static u32 lookup(u8 *self, u32 off) {
  u8 *t = table();
  return SLOT(t, 0x58, v1_t)(t, W(self, off));
}
static u32 named(const u32 name) {   // table slot 0x138 -> object, slot 0x88(name, &out)
  u8 *t = table();
  u8 *o = (u8 *)SLOT(t, 0x138, v0_t)(t);
  u32 out = 0;
  SLOT(o, 0x88, v2_t)(o, name, (u32)&out);
  return out;
}

// 0x5709d0, thiscall(this) void.
static void THISCALL fn5709d0(u8 *self) {
  W(self, 0x180) = lookup(self, 0x1b0);
  W(self, 0x184) = lookup(self, 0x1b4);
  W(self, 0x188) = lookup(self, 0x1b8);
  W(self, 0x18c) = lookup(self, 0x1bc);
  ext_563750(self, 3, 1);
  u8 *t = table();
  u8 *x = (u8 *)SLOT(t, 0x134, v0_t)(t);
  SLOT(x, 0x5c, v3_t)(x, 0x6a66ec, 0, 2);
  u8 *blk = (u8 *)W(self, 0x94);
  W(self, 0x1ac) = (u32)(blk + 0x57);
  if (blk[0x103e] == 0) {
    u8 *y = (u8 *)SLOT(self, 0x84, v0_t)(self);
    SLOT(y, 0x114, v1_t)(y, 0x10);
  }
  W(self, 0x194) = named(0x6a7a40);
  W(self, 0x198) = named(0x6a7a50);
  u32 v = named(0x6a8704);
  u8 f = self[0x1a3];
  W(self, 0x19c) = v;
  if (f) return;
  u8 *c54 = (u8 *)W(self, 0x54);
  self[0x87] = 0;
  u8 *o = (u8 *)SLOT(c54, 0x25c, v2_t)(c54, 0x6a674c, 0);
  u8 *tb = *(u8 **)(*(u8 **)(ENG + 0x9b) + 0xae4);
  u32 txt = SLOT(tb, 0, v2_t)(tb, 0x6a6fc0, 0x6a871c);
  SLOT(o, 0x284, v1_t)(o, txt);
  ext_563610(self, 0x6a6c1c);
  if (self[0x1a3]) return;
  u8 *a = (u8 *)SLOT((u8 *)W(self, 0x54), 0x25c, v2_t)((u8 *)W(self, 0x54), 0x6a69fc, 0);
  u8 *b = (u8 *)SLOT(a, 0x25c, v2_t)(a, 0x6a8730, 0);
  W(self, 0x1c8) = (u32)b;
  W(self, 0x22c) = 0;
  u32 found = 0;
  u32 *cursor = (u32 *)(self + 0x1c0);
  for (u8 *n = (u8 *)W(b, 0x50); n; n = (u8 *)W(n, 0x60)) {
    u8 *ch = (u8 *)W(n, 0x54);
    if (SLOT(ch, 0x1e0, b1_t)(ch, 0x20002d)) {
      u32 cnt = W(self, 0x22c);
      if (cnt < 0x18) {
        W(self, 0x1cc + cnt * 4) = (u32)ch;
        W(self, 0x22c)++;
      }
    }
    if (SLOT(ch, 0x1e0, b1_t)(ch, 0x200046)) {
      if (found < 2) {
        found++;
        *cursor++ = (u32)ch;
      }
    }
  }
  u32 vec[2] = {0x43820000, 0x3f000000};
  u32 *p = (u32 *)(self + 0x1c0);
  for (int i = 0; i < 2; i++, p++) {
    u8 *ob = (u8 *)*p;
    SLOT(ob, 0x258, v2_t)(ob, (u32)vec, 0);
  }
  ext_570310(self);
}
PCREG(5709d0, fn5709d0);
