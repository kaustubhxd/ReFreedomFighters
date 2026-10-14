// batch34121.cpp - cascade tier E, batch 34121: 0x5e0330 (hand a pending object over), 0x5eb600 (read an object's fields through its getters).
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5e0330, thiscall plain, returns false: o = [this+8]; o->slot0x144(0x68ce24). When (u8) o->slot0x1e0(0x1007d8): o->slot0x2d0(1, 0); then with vt = the vtable of [this+8] read now and r = [[0x70039c]+0x9b]->slot0x4c([this+0xc], 0, 1):
// ([this+8])->vt[0x2f0](r). Otherwise r = the same table slot 0x4c(o) and [this+0x10]->slot8([this+0xc], r).
static u32 THISCALL fn5e0330(u8 *self) {
  u8 *o = *(u8 **)(self + 8);
  vcall<void>(o, 0x144, 0x68ce24u);
  o = *(u8 **)(self + 8);
  if ((u8)vcall<u32>(o, 0x1e0, 0x1007d8u)) {
    o = *(u8 **)(self + 8);
    vcall<void>(o, 0x2d0, 1u, 0u);
    u8 *vt = *(u8 **)*(u8 **)(self + 8);
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 r = vcall<u32>(tbl, 0x4c, *(u32 *)(self + 0xc), 0u, 1u);
    typedef void (THISCALL *f1)(void *, u32);
    (*(f1 *)(vt + 0x2f0))(*(u8 **)(self + 8), r);
    return 0;
  }
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32>(tbl, 0x4c, *(u32 *)(self + 8));
  u8 *p = *(u8 **)(self + 0x10);
  vcall<void>(p, 8, *(u32 *)(self + 0xc), r);
  return 0;
}
PCREG(5e0330, fn5e0330);

// 0x5eb600, thiscall(a) ret 4: a->slot0x40(&a) (the callee overwrites the argument slot with a handle h); [this+8] = [[0x70039c]+0x9b]->slot0x58(h); a->slot0x40(&w); [this+0xc] = [[[0x70039c]+0x9b]+0x44] + w;
// a->slot0x50(this+0x10); a->slot0x68(this+0x14); returns a->slot0x6c(this+0x15).
static u32 THISCALL fn5eb600(u8 *self, u32 a) {
  u8 *obj = (u8 *)a;
  u32 w;
  vcall<void>(obj, 0x40, (u32)&a);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u8 **)(self + 8) = vcall<u8 *>(tbl, 0x58, *(volatile u32 *)&a);
  vcall<void>(obj, 0x40, (u32)&w);
  u8 *t2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0xc) = *(u32 *)(t2 + 0x44) + w;
  vcall<void>(obj, 0x50, (u32)(self + 0x10));
  vcall<void>(obj, 0x68, (u32)(self + 0x14));
  return vcall<u32>(obj, 0x6c, (u32)(self + 0x15));
}
PCREG(5eb600, fn5eb600);
