// batch33091.cpp - h3 () batch 33091: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" void THISCALL ext_574280(u8 *self, u32 a, u32 b);        // ret 8
extern "C" void THISCALL ext_5738c0(u8 *self, u32 a);               // ret 4

// 0x6500b0: thiscall no args, bool: twice (o = sys slot 0x1b0(); o && o->slot 0xc() -> false); [sys+0x9c7] == 0.0 (ordered) -> false; [this+0x74]==0 -> false; byte [sys+0x64]==0 -> false; else true
static u8 THISCALL fn6500b0(u8 *self) {
  u8 *o = vcall<u8 *>(SYS, 0x1b0);
  if (o && vcall<u8>(o, 0xc)) return 0;
  o = vcall<u8 *>(SYS, 0x1b0);
  if (o && vcall<u8>(o, 0xc)) return 0;
  float f = *(float *)(SYS + 0x9c7);
  if (f == 0.0f) return 0;
  if (*(u32 *)(self + 0x74) == 0) return 0;
  if (SYS[0x64] == 0) return 0;
  return 1;
}
PCREG(6500b0, fn6500b0);

// 0x5765c0: thiscall(a, b) ret 8, returns false: 0x574280(a, b); (u8)b: flags [0x20b]=1,[0x20d]=0, p=table slot 0x60([this+0x21d]): p: [p+0xec]=1, [p+0xed]=(float)[sys+0x40]/1024, [p+0xf1]=[p+0x88], [p+0xf5]=[p+0x88]/0.1; [this+0x229]->slot 0xbc(1); [this+0x20f]=0; 0x5738c0([this+0x1b8])
static u8 THISCALL fn5765c0(u8 *self, u32 a, u32 b) {
  ext_574280(self, a, b);
  if ((u8)b) {
    u32 key;
    __builtin_memcpy(&key, self + 0x21d, 4);
    self[0x20b] = 1;
    self[0x20d] = 0;
    u8 *tab = *(u8 **)(SYS + 0x9b);
    u8 *p = vcall<u8 *>(tab, 0x60, key);
    if (p) {
      p[0xec] = 1;
      float t = (float)*(s32 *)(SYS + 0x40) * 0.0009765625f;
      __builtin_memcpy(p + 0xed, &t, 4);
      float g;
      __builtin_memcpy(&g, p + 0x88, 4);
      __builtin_memcpy(p + 0xf1, &g, 4);
      float h = g / 0.1f;
      __builtin_memcpy(p + 0xf5, &h, 4);
    }
  }
  u8 *o;
  __builtin_memcpy(&o, self + 0x229, 4);
  self[0x20f] = 0;
  vcall<u32>(o, 0xbc, 1u);
  ext_5738c0(self, *(u32 *)(self + 0x1b8));
  return 0;
}
PCREG(5765c0, fn5765c0);

// 0x524460: thiscall(obj) ret 4, returns true: obj->slot 0x4c(float [this+off]) for off = 0, 4, 8, 0xc, 0x10
static u8 THISCALL fn524460(u8 *self, u8 *obj) {
  vcall<u32>(obj, 0x4c, *(u32 *)(self + 0));
  vcall<u32>(obj, 0x4c, *(u32 *)(self + 4));
  vcall<u32>(obj, 0x4c, *(u32 *)(self + 8));
  vcall<u32>(obj, 0x4c, *(u32 *)(self + 0xc));
  vcall<u32>(obj, 0x4c, *(u32 *)(self + 0x10));
  return 1;
}
PCREG(524460, fn524460);
