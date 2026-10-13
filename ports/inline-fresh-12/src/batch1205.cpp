// batch1205.cpp - fresh slice 12, batch 5. Names are FUN_ in the exe list (no map entry). Exe callees run as
// ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" u32 FASTCALL ext_4cc850(const char *a, const char *b);     // fastcall (ecx, edx), ret 0
extern "C" void THISCALL ext_610100(u8 *self, u8 *s);                 // empty, ret 4
extern "C" u32 THISCALL ext_4e5e60(u8 *s);                            // reads the next value, ret 0

// 0x4ce480: writes the pair list (+4 array of {a, b}, count +8) through the stream s: when s->slot 0x18() == 1 both
// words go out via slot 4; otherwise slot 4(b) returns a cell that receives a. ret 4.
static void THISCALL pairsIO(u8 *self, u8 *s) {
  u32 *p = *(u32 **)(self + 4);
  if (!*(u32 *)(self + 8)) return;
  u32 i = 0;
  do {
    if (vcall<u32>(s, 0x18) == 1) {
      vcall<u32>(s, 4, p[0]);
      vcall<u32>(s, 4, p[1]);
    } else {
      u32 *cell = vcall<u32 *>(s, 4, p[1]);
      *cell = p[0];
    }
    i++;
    p += 2;
  } while (i != *(u32 *)(self + 8));
}
PCREG(4ce480, pairsIO);

// 0x455080: if slot 0x20()->+0xc->+0x23 == 0x1000f0: slot 0x20()->slot 0x2c4(this); else when 0x4cc850(name or
// 0x67c8e8, 0x68288c) is non-zero (name = slot 0x20()->+4): engine(+0x9b)+0xb00 ->slot 4(this). EAX is the last result.
static u32 THISCALL f455080(u8 *self) {
  u8 *d = vcall<u8 *>(self, 0x20);
  if (*(u32 *)(*(u8 **)(d + 0xc) + 0x23) == 0x1000f0) {
    u8 *d2 = vcall<u8 *>(self, 0x20);
    return vcall<u32>(d2, 0x2c4, self);
  }
  u8 *d2 = vcall<u8 *>(self, 0x20);
  const char *nm = *(const char **)(d2 + 4);
  u32 r = ext_4cc850(nm ? nm : (const char *)0x67c8e8, (const char *)0x68288c);
  if (!r) return 0;
  u8 *l = *(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xb00;
  return vcall<u32>(l, 4, self);
}
PCREG(455080, f455080);

// 0x423440: walks the list at +0x2191 (slot 0x4c(&it) begins, slot 0x5c(&it) returns the next node, it.first == 0 at
// the end); the first node whose slot 4() is true is passed to this->slot 0x4c(node) and the walk starts over.
static void THISCALL purgeList(u8 *self) {
  u8 *l = self + 0x2191;
  u32 it[3];
  for (;;) {
    if (!l) return;
    vcall<u32>(l, 0x4c, it);
    u8 *n = vcall<u8 *>(l, 0x5c, it);
    for (;;) {
      if (!it[0]) return;
      if (vcall<u8>(n, 4)) break;
      n = vcall<u8 *>(l, 0x5c, it);
    }
    vcall<u32>(self, 0x4c, n);
  }
}
PCREG(423440, purgeList);

// 0x578c00: 0x610100(s) (empty), then six values read by 0x4e5e60(s) into +0x180, +0x184, +0x188, +0x194, +0x18c,
// +0x190 (in that order). ret 4.
static void THISCALL readSix(u8 *self, u8 *s) {
  ext_610100(self, s);
  *(u32 *)(self + 0x180) = ext_4e5e60(s);
  *(u32 *)(self + 0x184) = ext_4e5e60(s);
  *(u32 *)(self + 0x188) = ext_4e5e60(s);
  *(u32 *)(self + 0x194) = ext_4e5e60(s);
  *(u32 *)(self + 0x18c) = ext_4e5e60(s);
  *(u32 *)(self + 0x190) = ext_4e5e60(s);
}
PCREG(578c00, readSix);

// 0x435dc0: slot 0x24(0) on every object of three arrays: [+4] x count +0xc, [+0x10] x count +0x1c, [+0x20] x count
// +0x60 (counts re-read each step).
static void THISCALL resetAll(u8 *self) {
  for (u32 i = 0; i < *(u32 *)(self + 0xc); i++) vcall<u32>(((u8 **)(self + 4))[i], 0x24, 0);
  for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) vcall<u32>(((u8 **)(self + 0x10))[i], 0x24, 0);
  for (u32 i = 0; i < *(u32 *)(self + 0x60); i++) vcall<u32>(((u8 **)(self + 0x20))[i], 0x24, 0);
}
PCREG(435dc0, resetAll);

