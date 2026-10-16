// batch210023.cpp - Sonnet-w3a: small BLOCKED rows (chain with out-params, flag set + slots, stream record fetch)
#include "ff.h"

extern "C" u32 THISCALL ext_5c2ec0(u8 *self);
extern "C" u32 THISCALL ext_5c2f90(u8 *self);
extern "C" u32 THISCALL ext_5c2e10(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5c2cb0(u8 *self);
extern "C" u32 THISCALL ext_5c2f30(u8 *self);
extern "C" u32 ext_42ab62(u32 fmt);

static inline u8 *mgr() { return (u8 *)(*(u32 *)(G(u8 *, 0x70039c) + 0x9b)); }

static u32 THISCALL fn5c2d90(u8 *self, u32 a, u32 *b, u32 *c) {
  ext_5c2ec0(self);  // @5c2d90_a
  ext_5c2f90(self);  // @5c2d90_b
  if (a) {
    u8 *r = (u8 *)ext_5c2e10(self, a);  // @5c2d90_c
    if (r) {
      u32 idx = ext_5c2cb0(r);  // @5c2d90_d
      *c = idx;  // @5c2d90_e
      if (idx != 0xffffffffu) {
        b[1] = *(u32 *)(self + idx * 14 + 8);  // @5c2d90_f
        b[0] = *(u32 *)self;  // @5c2d90_g
        u32 e = ext_5c2f30(self);  // @5c2d90_h
        return (e & ~0xffu) | 1;
      }
    }
  }
  b[1] = 0;  // @5c2d90_i
  b[0] = 0;
  return (u32)b & ~0xffu;
}
PCREG(5c2d90, fn5c2d90);

static u32 STDCALL fn5d92e0(u8 *a) {
  u8 *edi = (u8 *)vcall<u32>(a, 0x20);  // @5d92e0_a
  *(u32 *)(edi + 0x30) |= 0x400;  // @5d92e0_b
  u8 *r = (u8 *)vcall<u32, u32, u32>(edi, 0x25c, 0x6b6318, 0);  // @5d92e0_c
  if (r) {
    u32 v[2] = {0x42480000, 0x42480000};
    vcall<u32, u32 *, u32>(r, 0x258, v, 0);  // @5d92e0_d
  }
  u32 e = vcall<u32, u8 *>(mgr(), 0x4c, edi);  // @5d92e0_e
  *(u32 *)(a + 0x48) |= 0x210000;  // @5d92e0_f
  return vcall<u32, u32>(a, 0x27c, e);  // @5d92e0_g
}
PCREG(5d92e0, fn5d92e0);

typedef u32 (*HookU)();
static u8 *THISCALL fn603e40(u8 *self, u8 *a) {
  (*(u32 *)(self + 8))++;  // @603e40_a
  u8 *edi = *(u8 **)self;
  if (*(u32 *)(edi + 8) >= *(u32 *)(edi + 4)) {  // @603e40_b
    ext_42ab62(0x6b89b4);
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 cnt = *(u32 *)(edi + 8);
  u8 *rec = *(u8 **)edi + cnt * 8;
  *(u32 *)(edi + 8) = cnt + 1;  // @603e40_c
  u8 al = rec[4];
  if (al != 0) {
    if (al != 4) return rec;  // @603e40_d
    vcall<u32>(*(u8 **)rec, 0x28);  // @603e40_e
  }
  u32 p = vcall<u32>(a, 0x24);  // @603e40_f
  *(u32 *)rec = p;  // @603e40_g
  rec[4] = 4;  // @603e40_h
  return rec;
}
PCREG(603e40, fn603e40);
