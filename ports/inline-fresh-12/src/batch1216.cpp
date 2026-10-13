// batch1216.cpp - fresh slice 12, batch 16. Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

static inline s32 cvtt(float f) {
  s32 r;
  asm("cvttss2si %1, %0" : "=r"(r) : "x"(f));
  return r;
}

// 0x4fa800: switches this actor's target to id. When engine(+0x9b) slot 0x58(id) gives an object o, +0xaf =
// trunc(((float *)(o->+8 + 0x40))[+0x8f]). Then c = this slot 0x2c4(): c slot 0x350(0x200000, old +0x9b, this); +0x9b
// = id; c = this slot 0x2c4(): c slot 0x34c(0x200000, id, this, 10.0f, 1). ret 4.
static void THISCALL setTarget4fa800(u8 *self, u32 id) {
  u8 *eng = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  if (u8 *o = vcall<u8 *>(eng, 0x58, id))
    *(s32 *)(self + 0xaf) = cvtt(*(float *)(*(u8 **)(o + 8) + *(u32 *)(self + 0x8f) * 4 + 0x40));
  u8 *c = vcall<u8 *>(self, 0x2c4);
  vcall<void>(c, 0x350, 0x200000u, *(u32 *)(self + 0x9b), self);
  *(u32 *)(self + 0x9b) = id;
  c = vcall<u8 *>(self, 0x2c4);
  vcall<void>(c, 0x34c, 0x200000u, *(u32 *)(self + 0x9b), self, 0x41200000u, 1u);
}
PCREG(4fa800, setTarget4fa800);

// 0x49a040: copies a point list from src: this slot 0xc(src slot 0x14()) (count), then for each element p of src's
// iteration (slot 0x4c(&it) starts, slot 0x64(&it) steps, null ends): q = src slot 0x9c(p); this slot 0x3c(*p), slot
// 0x4c(q[1]), slot 0x4c(q[0]) (floats). ret 4.
static void THISCALL copyPoints49a040(u8 *self, u8 *src) {
  vcall<void>(self, 0xc, vcall<u32>(src, 0x14));
  u32 it[3];
  vcall<void>(src, 0x4c, it);
  for (u32 *p = vcall<u32 *>(src, 0x64, it); p; p = vcall<u32 *>(src, 0x64, it)) {
    float *q = vcall<float *>(src, 0x9c, p);
    vcall<void>(self, 0x3c, *p);
    vcall<void>(self, 0x4c, q[1]);
    vcall<void>(self, 0x4c, q[0]);
  }
}
PCREG(49a040, copyPoints49a040);
