// batch34123.cpp - cascade tier E, batch 34123: 0x464dc0 (release three handles), 0x476a60 (read fields from a stream object), 0x484a80 (finish a nested update).
#include "ff.h"

extern "C" u32 THISCALL ext_43f900(void *self, void *a);                  // thiscall ret 4
extern "C" u32 THISCALL ext_4e11e0(void *self, void *p, u32 n);           // thiscall ret 8
extern "C" u32 THISCALL ext_4e11d0(void *self, void *p, u32 n);           // thiscall ret 8 (tail to 0x4e1110)
extern "C" u32 THISCALL ext_4e12e0(void *self, void *p, u32 n);           // thiscall ret 8 (tail to 0x4e11e0)
extern "C" u32 THISCALL ext_4e1600(void *self);                           // thiscall, plain ret (al)
extern "C" u32 THISCALL ext_4e1b30(void *self);                           // thiscall, plain ret
extern "C" u32 THISCALL ext_467390(void *self);                           // thiscall, plain ret

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x464dc0, thiscall plain: for the unaligned handles at +0x12a, +0x12e, +0x132 (in that order): when set, o = [[0x70039c]+0x9b]->slot0x58(h); when o is found o->slot0x210(1) and the handle field is cleared.
static void THISCALL fn464dc0(u8 *self) {
  static const u16 offs[] = {0x12a, 0x12e, 0x132};
  for (unsigned i = 0; i < 3; i++) {
    u32 h = rd32(self + offs[i]);
    if (!h) continue;
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tbl, 0x58, h);
    if (!o) continue;
    vcall<void>(o, 0x210, 1u);
    wr32(self + offs[i], 0);
  }
}
PCREG(464dc0, fn464dc0);

// 0x476a60, thiscall(a) ret 4, returns the last call's eax: ext_43f900(this, a); byte [this+0x72] = 0; unaligned dword [this+0x73] = 0; ext_4e11e0(a, this+0x5c, 1); ext_4e11d0(a, this+0x70, 1);
// when ext_4e1600(a) is 3: ext_4e12e0(a, &arg, 1) (the callee writes the argument slot) and byte [this+0x72] = (arg != 0); when ext_4e1600(a) is 8: ext_4e12e0(a, this+0x73, 1); returns ext_4e1b30(a).
static u32 THISCALL fn476a60(u8 *self, u32 a) {
  u8 *obj = (u8 *)a;
  ext_43f900(self, obj);
  self[0x72] = 0;
  wr32(self + 0x73, 0);
  ext_4e11e0(obj, self + 0x5c, 1);
  ext_4e11d0(obj, self + 0x70, 1);
  if ((u8)ext_4e1600(obj) == 3) {
    ext_4e12e0(obj, &a, 1);
    self[0x72] = *(volatile u32 *)&a != 0;
  }
  if ((u8)ext_4e1600(obj) == 8) ext_4e12e0(obj, self + 0x73, 1);
  return ext_4e1b30(obj);
}
PCREG(476a60, fn476a60);

// 0x484a80, thiscall plain: unaligned dword [this+0x60a] -= 1; nothing more unless it reaches 0. Then ext_467390(this); this->slot0x220(0); this->slot0x36c(); with h = unaligned [this+0x5ca]: h == 0 calls this->slot0x5b0(this+0x5ce, this+0x5f2);
// else o = [[0x70039c]+0x9b]->slot0x58(h): none ends here, else o->slot0x98(this+0x5ce, this+0x5f2) and this->slot0x5b0(this+0x5ce, this+0x5f2).
static void THISCALL fn484a80(u8 *self) {
  u32 c = rd32(self + 0x60a) - 1;
  wr32(self + 0x60a, c);
  if (c != 0) return;
  ext_467390(self);
  vcall<void>(self, 0x220, 0u);
  vcall<void>(self, 0x36c);
  u32 h = rd32(self + 0x5ca);
  if (h) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tbl, 0x58, h);
    if (!o) return;
    vcall<void>(o, 0x98, (u32)(self + 0x5ce), (u32)(self + 0x5f2));
  }
  vcall<void>(self, 0x5b0, (u32)(self + 0x5ce), (u32)(self + 0x5f2));
}
PCREG(484a80, fn484a80);
