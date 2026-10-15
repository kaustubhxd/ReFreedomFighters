// batch33080.cpp - h3 (Sonnet) batch 33080: tier H float/SSE functions
#include "ff.h"

extern "C" void THISCALL ext_4690b0(u8 *self);                      // 1-byte nop used as a thiscall
extern "C" void THISCALL ext_5248e0(u8 *self, u32 f);               // ret 4
extern "C" void THISCALL ext_5ee920(u8 *self);
extern "C" void THISCALL ext_655270(u8 *self);

#define SYS (*(u8 **)0x70039c)

// 0x4759b0: thiscall(a,b,f,v0..v3) ret 0x1c: sub-object p=this+0x34f (unaligned vtable): p->slot 0x1c(this, a, b, f, v0..v3)
static void THISCALL fn4759b0(u8 *self, u32 a, u32 b, u32 f, u32 v0, u32 v1, u32 v2, u32 v3) {
  vcall<u32>(self + 0x34f, 0x1c, (u32)self, a, b, f, v0, v1, v2, v3);
}
PCREG(4759b0, fn4759b0);

// 0x5166e0: thiscall(float f) ret 4: four constants into [this+0x11..0x1d]; nop-calls on this+0x41 and this+0x55; 0x5248e0(this+0x21, f)
static void THISCALL fn5166e0(u8 *self, u32 f) {
  *(u32 *)(self + 0x11) = 0xc47a0000;
  *(u32 *)(self + 0x15) = 0x42200000;
  *(u32 *)(self + 0x19) = 0x42dc0000;
  *(u32 *)(self + 0x1d) = 0x42700000;
  ext_4690b0(self + 0x41);
  ext_4690b0(self + 0x55);
  ext_5248e0(self + 0x21, f);
}
PCREG(5166e0, fn5166e0);

// 0x5eebf0: thiscall: x=[sysobj+0x48]+[this+0x41]; [this+0x41]=x; x > 3.0 (ordered): [this+0x11]==1 -> 0x5ee920(this); n=[this+0x19]: n -> byte [this+0x77]=1, [this+0x19]=n-1; [this+0x41]=0
static void THISCALL fn5eebf0(u8 *self) {
  float x = *(float *)(SYS + 0x48);
  x += *(float *)(self + 0x41);
  *(float *)(self + 0x41) = x;
  if (!(x > 3.0f)) return;
  if (*(u32 *)(self + 0x11) == 1) ext_5ee920(self);
  u32 n = *(u32 *)(self + 0x19);
  if (n) {
    self[0x77] = 1;
    *(u32 *)(self + 0x19) = n - 1;
  }
  *(u32 *)(self + 0x41) = 0;
}
PCREG(5eebf0, fn5eebf0);

// 0x470670: thiscall(a) ret 4 bool: a->slot 0x3c([this+0x52]); a->slot 0x4c([this+0x56] float bits); return 1
static u32 THISCALL fn470670(u8 *self, u8 *a) {
  vcall<u32>(a, 0x3c, *(u32 *)(self + 0x52));
  u32 f = *(u32 *)(self + 0x56);
  vcall<u32>(a, 0x4c, f);
  return 1;
}
PCREG(470670, fn470670);

// 0x4f1d10: thiscall: v=[this+0x1d7]; v == -1.0: nothing; else o=[this+0x6f]: v == 0.0 (ordered) ? o->slot 0x254() : o->slot 0x250(); [this+0x1d7] = -1.0
static void THISCALL fn4f1d10(u8 *self) {
  float v = *(float *)(self + 0x1d7);
  if (v == -1.0f) return;
  u8 *o = *(u8 **)(self + 0x6f);
  if (v == 0.0f) vcall<u32>(o, 0x254);
  else vcall<u32>(o, 0x250);
  *(u32 *)(self + 0x1d7) = 0xbf800000;
}
PCREG(4f1d10, fn4f1d10);

// 0x534010: thiscall(float a) ret 4: 0x400 entries (stride 0xfd) from [this+8]+0x78: when dword [entry-0x68] != 0 and [entry] != 0.0 (NaN counts as non-zero): [entry] += a
static void THISCALL fn534010(u8 *self, float a) {
  u8 *e = *(u8 **)(self + 8) + 0x78;
  for (int n = 0x400; n != 0; n--, e += 0xfd) {
    if (*(u32 *)(e - 0x68) == 0) continue;
    float x = *(float *)e;
    if (x == 0.0f) continue;
    *(float *)e = x + a;
  }
}
PCREG(534010, fn534010);

// 0x6550b0: thiscall(short a) ret 4: [sysobj+0x9ef] (unaligned float) = (float)(s16)a + it; [this+0x137]: 0x655270(this), import [0x6761f0](), byte [this+0x1185]=0, slot 0xc8()
typedef void (STDCALL *imp0_t)();
static void THISCALL fn6550b0(u8 *self, u32 a) {
  u8 *g = SYS;
  float x = (float)(s32)(s16)a;
  x += *(float *)(g + 0x9ef);
  *(float *)(g + 0x9ef) = x;
  if (*(u32 *)(self + 0x137) == 0) return;
  ext_655270(self);
  (*(imp0_t *)0x6761f0)();
  self[0x1185] = 0;
  vcall<u32>(self, 0xc8);
}
PCREG(6550b0, fn6550b0);

// 0x473a10: thiscall: slot 0x4b4(0, 0, 0, 0, -1 as bits); byte [this+0x3e8]=1
static void THISCALL fn473a10(u8 *self) {
  vcall<u32>(self, 0x4b4, 0u, 0u, 0u, 0u, 0xffffffffu);
  self[0x3e8] = 1;
}
PCREG(473a10, fn473a10);
