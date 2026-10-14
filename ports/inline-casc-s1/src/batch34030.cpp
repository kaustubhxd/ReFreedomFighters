// batch34030.cpp - cascade tier E, batch 34030: 0x4f3f70 (walk a parent chain looking for this), 0x4fb2f0 (push two flag bytes and a table value to an object),
// 0x505490 (spawn from a table offset and register the result).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);          // thiscall ret 4: entry lookup
extern "C" void THISCALL ext_5002f0(void *self, u32 v);         // thiscall ret 4
extern "C" u32 THISCALL ext_5057e0(void *self, u32 a, u32 b);   // thiscall ret 8

// 0x4f3f70, thiscall(a, b) ret 8, returns false: t = this->slot0x2c4(); x = t->slot0x2f0(); walk from x via slot 0x20 until this is found (then
// this->slot0x2c4()->slot0x2f4(x, 0)) or the chain ends; always finishes with this->slot0xbc(1).
static bool THISCALL fn4f3f70(u8 *self, u32 a, u32 b) {
  (void)a; (void)b;
  u8 *t = vcall<u8 *>(self, 0x2c4);
  u8 *x = vcall<u8 *>(t, 0x2f0);
  u8 *n = x;
  if (x) {
    for (;;) {
      if (n == self) {
        u8 *t2 = vcall<u8 *>(self, 0x2c4);
        vcall<void>(t2, 0x2f4, (u32)x, 0u);
        break;
      }
      n = vcall<u8 *>(n, 0x20);
      if (!n) break;
    }
  }
  vcall<void>(self, 0xbc, 1u);
  return false;
}
PCREG(4f3f70, fn4f3f70);

// 0x4fb2f0, thiscall(a) ret 4, returns true: [this+4] &= ~0x40; a->slot0x60(byte [this+0x5a]); a->slot0x60(byte [this+0x5b]); p = [this+0x5c]: when set
// a->slot0x3c(engine table slot 0x4c([p+0x30])), else a->slot0x3c(0).
static bool THISCALL fn4fb2f0(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(a, 0x60, (u32)self[0x5a]);
  vcall<void>(a, 0x60, (u32)self[0x5b]);
  u8 *p = *(u8 **)(self + 0x5c);
  if (p) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 v = vcall<u32>(tbl, 0x4c, *(u32 *)(p + 0x30));
    vcall<void>(a, 0x3c, v);
  } else {
    vcall<void>(a, 0x3c, 0u);
  }
  return true;
}
PCREG(4fb2f0, fn4fb2f0);

// 0x505490, thiscall(a) ret 4: n = [0x5003d0([a+4], 0)] (signed); for n > 0: r = this->slot0x50([engine table+0x44] + n, 1, {0, -1.0f, 0, 1.0f}) (six stack dwords) is the
// value; otherwise 0x5057e0(this, 0x69ce60, n) and the value 0. Then 0x5002f0(0x5003d0([a+8], 0), value).
static void THISCALL fn505490(u8 *self, u8 *a) {
  s32 n = *(s32 *)ext_5003d0(*(u8 **)(a + 4), 0);
  u32 v;
  if (n > 0) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 base = *(u32 *)(tbl + 0x44);
    v = vcall<u32>(self, 0x50, base + (u32)n, 1u, 0u, 0xbf800000u, 0u, 0x3f800000u);
  } else {
    ext_5057e0(self, 0x69ce60u, (u32)n);
    v = 0;
  }
  u32 e = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0((void *)e, v);
}
PCREG(505490, fn505490);
