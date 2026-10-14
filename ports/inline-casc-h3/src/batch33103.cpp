// batch33103.cpp - h3 () batch 33103: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_43d020(u8 *self);                       // plain ret

// 0x43dac0: thiscall(unused) ret 4: [0x349]==0 and [0x80]!=0 and byte [[0x7003a0]+0x7a]!=0 and ([sys+0x48] != 0.0 or byte [0x90]!=0): this->slot 0x10(); slot 0x14(); [this+4]->slot 0x48([0x88]); slot 0x4c([0x8c]); 0x43d020(this); else [this+4]->slot 0x48(0); slot 0x4c(0)
static void THISCALL fn43dac0(u8 *self, u32 unused) {
  (void)unused;
  bool on = false;
  if (self[0x349] == 0 && *(u32 *)(self + 0x80) != 0) {
    u8 *g = G(u8 *, 0x7003a0);
    if (g[0x7a] != 0) {
      float f = *(float *)(SYS + 0x48);
      if (!(f == 0.0f) || self[0x90] != 0) on = true;
    }
  }
  u8 *o = *(u8 **)(self + 4);
  if (on) {
    vcall<u32>(self, 0x10);
    vcall<u32>(self, 0x14);
    o = *(u8 **)(self + 4);
    vcall<u32>(o, 0x48, *(u32 *)(self + 0x88));
    o = *(u8 **)(self + 4);
    vcall<u32>(o, 0x4c, *(u32 *)(self + 0x8c));
    ext_43d020(self);
    return;
  }
  vcall<u32>(o, 0x48, 0u);
  o = *(u8 **)(self + 4);
  vcall<u32>(o, 0x4c, 0u);
}
PCREG(43dac0, fn43dac0);

// 0x4fd9a0: thiscall(s) ret 4, returns true: [this+4] &= ~0x40; for node = [this+0x48]; node; node = node[0xc], idx++: [this+0x50]==node -> sel=idx; s->slot 0x3c(node[0]); s->slot 0x60(byte node[0x14]); s->slot 0x4c(float node[4]); then s->slot 0x3c(-1); s->slot 0x3c(sel) (sel = -1 when none)
static u8 THISCALL fn4fd9a0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 sel = 0xffffffffu;
  u32 idx = 0;
  u8 *node = *(u8 **)(self + 0x48);
  while (node) {
    if (*(u8 **)(self + 0x50) == node) sel = idx;
    vcall<u32>(s, 0x3c, *(u32 *)node);
    vcall<u32>(s, 0x60, (u32)node[0x14]);
    vcall<u32>(s, 0x4c, *(u32 *)(node + 4));
    node = *(u8 **)(node + 0xc);
    idx++;
  }
  vcall<u32>(s, 0x3c, 0xffffffffu);
  vcall<u32>(s, 0x3c, sel);
  return 1;
}
PCREG(4fd9a0, fn4fd9a0);

// 0x5ddc10: thiscall no args: v={x,x} with x=(float)[sys+0x6f]/640 -> o=[this+0x44]: o->slot 0x258(v, 0); w={(float)[sys+0x6f]*[this+0x54], (float)[sys+0x73]*[this+0x58], 0}: o->slot 0x70(w); o->slot 0x250(0); o->slot 0xbc(1); [this+0x5c]=0
static void THISCALL fn5ddc10(u8 *self) {
  float x = (float)(s32)R32(SYS + 0x6f);
  x = x / 640.0f;
  float v[2] = {x, x};
  u8 *o = *(u8 **)(self + 0x44);
  vcall<u32>(o, 0x258, (u32)v, 0u);
  float w[3];
  float b = (float)(s32)R32(SYS + 0x73);
  float a = (float)(s32)R32(SYS + 0x6f);
  b = b * *(float *)(self + 0x58);
  a = a * *(float *)(self + 0x54);
  w[1] = b;
  w[0] = a;
  w[2] = 0.0f;
  o = *(u8 **)(self + 0x44);
  vcall<u32>(o, 0x70, (u32)w);
  o = *(u8 **)(self + 0x44);
  vcall<u32>(o, 0x250, 0u);
  o = *(u8 **)(self + 0x44);
  vcall<u32>(o, 0xbc, 1u);
  *(u32 *)(self + 0x5c) = 0;
}
PCREG(5ddc10, fn5ddc10);
