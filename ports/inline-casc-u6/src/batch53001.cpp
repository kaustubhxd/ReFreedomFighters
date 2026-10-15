// batch53001.cpp - u6 batch 53001: tier H function with many callees.
#include "ff.h"

extern "C" u32 THISCALL ext_467260(u8 *self, u32 a, u32 b, u32 c);                                       // thiscall ret 0xc
extern "C" u32 THISCALL ext_4dc130(u8 *self);                                                            // getter: [[this+0x50]+0x54] or its (zero) test value
extern "C" u32 THISCALL ext_43ec00(u32 self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);                  // thiscall ret 0x18
extern "C" void THISCALL ext_441890(u8 *self, float a);                                                  // thiscall ret 4
typedef u32(THISCALL *vs0_t)(void *);
typedef u32(THISCALL *vs1_t)(void *, u32);
typedef u32(THISCALL *vs2_t)(void *, u32, u32);
typedef u8(THISCALL *vb1_t)(void *, u32);

// 0x4b7240, thiscall(a, unused) ret 8: a flag-driven update of an object found through the engine tables ([0x70039c], GUESS names).
// [this+0x180] set: [this+0x64] = [eng+0x40] (unless the same address), then vslot 0x64(0x10) when [this+0x181], then vslot 0x9c().
// [eng+0x1a9f] zero or table [eng+0x9b] vslot 0x58([this+0x50]) zero: return. o = [this+0x50] ? this.vslot 0x94(a, [this+0x50]) : 0; t = [o+0x54].
// t set and t.vslot 0x1e0(0x200027) (al): [this+0x54] == 0: n = 0x467260(t, [this+0x58], 0xc, 0) -> [this+0x6c]; e = table vslot 0x60(n); e set and
//   [eng+0x1a9f].vslot 0x70([this+0x58]) (al): [e+0x88] = [this+0x60], then the tail; [this+0x54] == 1: t.vslot 0x3f8([this+0x58] != 0), return; other: return.
// else: [this+0x50] zero -> return; o = this.vslot 0x94(a, [this+0x50]) zero -> return; n = 0x43ec00(0x4dc130(o), o, o+0x24, [this+0x58], 0, 0, 0) -> [this+0x6c];
//   e = table vslot 0x60(n); e zero -> return; [e+0x40] |= 0x80; [e+0x2c] = 2; [e+0x88] = [this+0x60]; tail.
// tail: 0x441890(e, [this+0x5c] float); [e+0x40] = ([e+0x40] & ~4) | 0x20.
static void THISCALL fn4b7240(u8 *self, u32 a, u32 unused) {
  if (self[0x180]) {
    u8 *eng = G(u8 *, 0x70039c);
    u32 *src = (u32 *)(eng + 0x40);
    u32 *dst = (u32 *)(self + 0x64);
    if (dst != src) *dst = *src;
    if (self[0x181]) vcall<u32>(self, 0x64, 0x10u);
    vcall<u32>(self, 0x9c);
  }
  u8 *eng = G(u8 *, 0x70039c);
  if (*(u32 *)(eng + 0x1a9f) == 0) return;
  void *mgr = *(void **)(eng + 0x9b);
  if (vcall<u32>(mgr, 0x58, *(u32 *)(self + 0x50)) == 0) return;
  u32 p50 = *(u32 *)(self + 0x50);
  u8 *o = 0;
  if (p50) o = (u8 *)vcall<u32>(self, 0x94, a, p50);
  u8 *t = *(u8 **)(o + 0x54);
  u8 *e;
  if (t && (u8)vcall<u32>(t, 0x1e0, 0x200027u)) {
    u32 mode = *(u32 *)(self + 0x54);
    if (mode == 0) {
      u32 n = ext_467260(t, *(u32 *)(self + 0x58), 0xc, 0);
      *(u32 *)(self + 0x6c) = n;
      mgr = *(void **)(G(u8 *, 0x70039c) + 0x9b);
      e = (u8 *)vcall<u32>(mgr, 0x60, n);
      if (!e) return;
      void *o3 = *(void **)(G(u8 *, 0x70039c) + 0x1a9f);
      if (!(u8)vcall<u32>(o3, 0x70, *(u32 *)(self + 0x58))) return;
      *(u32 *)(e + 0x88) = *(u32 *)(self + 0x60);
    } else if (mode == 1) {
      vcall<u32>(t, 0x3f8, (u32)(*(u32 *)(self + 0x58) != 0));
      return;
    } else {
      return;
    }
  } else {
    u32 q = *(u32 *)(self + 0x50);
    if (!q) return;
    o = (u8 *)vcall<u32>(self, 0x94, a, q);
    if (!o) return;
    u32 g = ext_4dc130(o);
    u32 n = ext_43ec00(g, (u32)o, (u32)(o + 0x24), *(u32 *)(self + 0x58), 0, 0, 0);
    *(u32 *)(self + 0x6c) = n;
    mgr = *(void **)(G(u8 *, 0x70039c) + 0x9b);
    e = (u8 *)vcall<u32>(mgr, 0x60, n);
    if (!e) return;
    *(u32 *)(e + 0x40) |= 0x80;
    *(u32 *)(e + 0x2c) = 2;
    *(u32 *)(e + 0x88) = *(u32 *)(self + 0x60);
  }
  ext_441890(e, *(float *)(self + 0x5c));
  *(u32 *)(e + 0x40) = (*(u32 *)(e + 0x40) & 0xfffffffb) | 0x20;
}
PCREG(4b7240, fn4b7240);
