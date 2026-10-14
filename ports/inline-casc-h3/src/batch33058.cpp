// batch33058.cpp - h3 () batch 33058: tier C wrappers, import loop, global array push
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *self);
extern "C" void THISCALL ext_4de7a0(u8 *self);
extern "C" u32 THISCALL ext_591ae0(u8 *self);
extern "C" void THISCALL ext_562e90(u8 *self, u32 a, u32 b);       // ret 8

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();
typedef void (__attribute__((cdecl)) *imp_free_t)(u32);

// 0x4b1800: thiscall(a) ret 4: [this+0x4a]=(0x4e5e60(a)!=0); [this+0x48]=(u16)table->slot 0x114(str,0,str,0xef0)
static void THISCALL fn4b1800(u8 *self, u8 *a) {
  u32 x = ext_4e5e60(a);
  self[0x4a] = x != 0;
  u32 r = vcall<u32>(SYS_TABLE, 0x114, 0x691fc8u, 0u, 0x691edcu, 0xef0u);
  *(u16 *)(self + 0x48) = (u16)r;
}
PCREG(4b1800, fn4b1800);

// 0x4c3220: thiscall(a) ret 4 bool: [this+4]&=~0x40; a->slot 0x40(&arg); [this+0x48]=table->slot 0x58(arg re-read); [this+0x4c]=0; return 1
static u32 THISCALL fn4c3220(u8 *self, u32 a) {
  u32 arg = a;
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<u32>((u8 *)a, 0x40, (u32)&arg);
  u32 r = vcall<u32>(SYS_TABLE, 0x58, arg);
  *(u32 *)(self + 0x48) = r;
  *(u32 *)(self + 0x4c) = 0;
  return 1;
}
PCREG(4c3220, fn4c3220);

// 0x4cfae0: thiscall: pop the pointer stack at this+8 (count [this+0x1c8]) calling import [0x6762ec](entry[-4])
static void THISCALL fn4cfae0(u8 *self) {
  if (*(u32 *)(self + 0x1c8) == 0) return;
  imp_free_t f = *(imp_free_t *)0x6762ec;
  do {
    (*(u32 *)(self + 0x1c8))--;
    u32 n = *(u32 *)(self + 0x1c8);
    u8 *e = *(u8 **)(self + n * 4 + 8);
    f(*(u32 *)(e - 4));
  } while (*(u32 *)(self + 0x1c8) != 0);
}
PCREG(4cfae0, fn4cfae0);

// 0x518790: thiscall: g=[sysobj+0x1a9f]; !g ? 0 : vtable (read first) [0x2e8](g->slot 0x60([this+0x12f], 0x69f178))
static u32 THISCALL fn518790(u8 *self) {
  u8 *g = *(u8 **)(SYS + 0x1a9f);
  if (!g) return 0;
  u8 *vt = *(u8 **)self;
  u32 r = vcall<u32>(g, 0x60, *(u32 *)(self + 0x12f), 0x69f178u);
  return ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vt + 0x2e8))(self, r);
}
PCREG(518790, fn518790);

// 0x5217f0: same with string 0x69f188
static u32 THISCALL fn5217f0(u8 *self) {
  u8 *g = *(u8 **)(SYS + 0x1a9f);
  if (!g) return 0;
  u8 *vt = *(u8 **)self;
  u32 r = vcall<u32>(g, 0x60, *(u32 *)(self + 0x12f), 0x69f188u);
  return ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vt + 0x2e8))(self, r);
}
PCREG(5217f0, fn5217f0);

// 0x560530: thiscall(a) ret 4: global stack of 0x32 entries: push a (returns a) else slot 0x44(str) + assert hook
static u32 THISCALL fn560530(u8 *self, u32 a) {
  u32 n = *(u32 *)0x714198;
  if (n < 0x32) {
    *(u32 *)(0x7141a0 + n * 4) = a;
    *(u32 *)0x714198 = n + 1;
    return a;
  }
  vcall<u32>(self, 0x44, 0x6a6218u);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(560530, fn560530);

// 0x56d100: thiscall(a,b) ret 8 bool: 0x562e90(a,b); if (u8)b: g=[sysobj+0x1907]; g && g->slot 0x14(str); [this+0x1c6]=0; return 0
static u32 THISCALL fn56d100(u8 *self, u32 a, u32 b) {
  ext_562e90(self, a, b);
  if ((u8)b) {
    u8 *g = *(u8 **)(SYS + 0x1907);
    if (g) vcall<u32>(g, 0x14, 0x6a8034u);
    *(u32 *)(self + 0x1c6) = 0;
  }
  return 0;
}
PCREG(56d100, fn56d100);

// 0x5d05b0: thiscall: tmp[0x28] initialised by 0x4de7a0; [this+0xb15]=500.0f; [this+0xb54]=0x591ae0([this+0x44])
static void THISCALL fn5d05b0(u8 *self) {
  u8 tmp[0x28];
  ext_4de7a0(tmp);
  *(u32 *)(self + 0xb15) = 0x43fa0000;
  *(u32 *)(self + 0xb54) = ext_591ae0(*(u8 **)(self + 0x44));
}
PCREG(5d05b0, fn5d05b0);
