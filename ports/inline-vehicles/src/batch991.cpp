// batch991.cpp - residue-10 (core todo), batch 991: ZDamageBox2::FrameUpdate(), 0x5dba60, thiscall, no args, plain ret.
// Returns unless [this+0x54] is set and the list [this+0x48] is non-empty. Walks the list (L vslot 0x4c(&more), vslot 0x5c(&more)):
// for each entry e: X = render vslot 0x58(e); helper 0x4daf90(X+8, &v) (stood in); X vslot 0x84(&v); P = [this+0x44]: vslot 0x8c(&v);
// when P vslot 0x180(&v, -10.0) is set: [this+0x8b] += frame time; when above [this+0x50]: C1 = 1/[this+0x97] (constant 0x678858 over it);
// [this+0x9b] += frame time; when above C1: [this+0x7f] = [this+0x93]; render vslot 0x114(0x69eaac, 0, 0x6b695c, 0x83, &[this+0x57], 0) gives an
// id for X vslot 0x128(id); [this+0x9b] = 0; then [this+0x8f] = 0. Otherwise [this+0x8f] += frame time; when above [this+0x87], [this+0x8b] = 0
// and [this+0x8f] = 0.
#include "ff.h"

extern "C" void THISCALL ext_4daf90(void *self, float *v);   // stood in by the checker

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x5dba60 ZDamageBox2::FrameUpdate().
static void THISCALL dmgBox2FrameUpdate(u8 *t) {
  if (!t[0x54])
    return;
  u8 *l = (u8 *)D(t, 0x48);
  if (!l)
    return;
  u32 more = 0;
  vcall<void>(l, 0x4c, (u32)&more);
  u8 *e = (u8 *)vcall<u32>(l, 0x5c, (u32)&more);
  if (!more)
    return;
  do {
    u8 *sys = *(u8 **)0x70039c;
    void *rm = *(void **)(sys + 0x9b);
    u8 *x = (u8 *)vcall<u32>(rm, 0x58, (u32)e);
    u32 v[4];
    ext_4daf90((void *)D(x, 8), (float *)v);
    vcall<void>(x, 0x84, (u32)v);
    u8 *p = (u8 *)D(t, 0x44);
    vcall<void>(p, 0x8c, (u32)v);
    u32 al = vcall<u32>(p, 0x180, (u32)v, 0xc1200000u);
    if ((u8)al) {
      F(t, 0x8b) = F(sys, 0x48) + F(t, 0x8b);
      if (F(t, 0x8b) > F(t, 0x50)) {
        float c1 = *(float *)0x678858 / F(t, 0x97);
        float y = F(sys, 0x48) + F(t, 0x9b);
        F(t, 0x9b) = y;
        if (y > c1) {
          D(t, 0x7f) = D(t, 0x93);
          u16 id = vcall<u16>(rm, 0x114, 0x69eaacu, 0u, 0x6b695cu, 0x83u, (u32)(t + 0x57), 0u);
          vcall<void>(x, 0x128, (u32)id);
          D(t, 0x9b) = 0;
          D(t, 0x8f) = 0;
        }
      }
    } else {
      F(t, 0x8f) = F(sys, 0x48) + F(t, 0x8f);
      if (F(t, 0x8f) > F(t, 0x87)) {
        D(t, 0x8b) = 0;
        D(t, 0x8f) = 0;
      }
    }
    e = (u8 *)vcall<u32>(l, 0x5c, (u32)&more);
  } while (more);
}
PCREG(5dba60, dmgBox2FrameUpdate);
