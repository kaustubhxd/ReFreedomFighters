// batch33059.cpp - h3 (Sonnet) batch 33059: tier C wrappers
#include "ff.h"

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();

// 0x5f55e0: thiscall: pop records (8 bytes: obj, type byte at +4) off the array at [this], count [this+8]; type 4 -> obj->slot 0x28(); clear type
static void THISCALL fn5f55e0(u8 *self) {
  if (*(u32 *)(self + 8) == 0) return;
  do {
    (*(u32 *)(self + 8))--;
    u32 n = *(u32 *)(self + 8);
    u8 *rec = *(u8 **)self + n * 8;
    if (rec[4] == 4) vcall<u32>(*(u8 **)rec, 0x28);
    rec[4] = 0;
  } while (*(u32 *)(self + 8) > 0);
}
PCREG(5f55e0, fn5f55e0);

// 0x64f860: thiscall(a) ret 4 bool: vt of o=[this+0x8c] read first; r=table->slot 0x4c(a); return o'->vtable[0x28](r) != 0
static u32 THISCALL fn64f860(u8 *self, u32 a) {
  u8 *vto = *(u8 **)(*(u8 **)(self + 0x8c));
  u32 r = vcall<u32>(SYS_TABLE, 0x4c, a);
  u8 *o2 = *(u8 **)(self + 0x8c);
  u32 x = ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vto + 0x28))(o2, r);
  return x != 0;
}
PCREG(64f860, fn64f860);

// 0x463940: thiscall: slot 0x2f8(0); clear [0x5c],[0x60]; slot 0x330() (vtable re-read); shuffle [0x72..0x7e] into [0x5c..0x68]; zero [0x72],[0x76]; returns old [0x76]
static u32 THISCALL fn463940(u8 *self) {
  vcall<u32>(self, 0x2f8, 0u);
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x60) = 0;
  vcall<u32>(self, 0x330);
  *(u32 *)(self + 0x64) = *(u32 *)(self + 0x7a);
  *(u32 *)(self + 0x68) = *(u32 *)(self + 0x7e);
  *(u32 *)(self + 0x5c) = *(u32 *)(self + 0x72);
  u32 e = *(u32 *)(self + 0x76);
  *(u32 *)(self + 0x60) = e;
  *(u32 *)(self + 0x72) = 0;
  *(u32 *)(self + 0x76) = 0;
  return e;
}
PCREG(463940, fn463940);

// 0x4870c0: thiscall: vt of o=[this+8] read first; r=table->slot 0x114(str,0,str,0x307,0,0); o'->vtable[0x128]((u16)r)
static u32 THISCALL fn4870c0(u8 *self) {
  u8 *vto = *(u8 **)(*(u8 **)(self + 8));
  u32 r = vcall<u32>(SYS_TABLE, 0x114, 0x68ce84u, 0u, 0x68cdc4u, 0x307u, 0u, 0u);
  u8 *o2 = *(u8 **)(self + 8);
  return ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vto + 0x128))(o2, (u32)(u16)r);
}
PCREG(4870c0, fn4870c0);

// 0x4dce70: thiscall(a) ret 4: [this+0x5c] = a ? (u16)[[sysobj+0x9b]+8]->slot 0x58(a) : 0
static void THISCALL fn4dce70(u8 *self, u32 a) {
  u16 v = 0;
  if (a) {
    u8 *o = *(u8 **)(SYS_TABLE + 8);
    v = (u16)vcall<u32>(o, 0x58, a);
  }
  *(u16 *)(self + 0x5c) = v;
}
PCREG(4dce70, fn4dce70);

// 0x52b080: thiscall: o=[this+0x44]; if (o && o[0x10]) { r=sysobj->slot 0x1c8(str,0x3d); o=[this+0x44]; if (r - o[0] > o[4]) o[0]=r }; byte [this+0x48]=1
static void THISCALL fn52b080(u8 *self) {
  u8 *o = *(u8 **)(self + 0x44);
  if (o && o[0x10]) {
    u32 r = vcall<u32>(SYS, 0x1c8, 0x6a0ea8u, 0x3du);
    u8 *e = *(u8 **)(self + 0x44);
    if (!(r - *(u32 *)e <= *(u32 *)(e + 4))) *(u32 *)e = r;
  }
  self[0x48] = 1;
}
PCREG(52b080, fn52b080);

// 0x5b6b30: thiscall(a,b) ret 8: r=[this+0x48]->slot 0x2c(a); r && x=[r+4]->slot 0x2c(b): byte [r+0x90]=1; x: byte [x+0x10]=0, dword [x+0x11]=-1.0f
static void THISCALL fn5b6b30(u8 *self, u32 a, u32 b) {
  u8 *r = vcall<u8 *>(*(u8 **)(self + 0x48), 0x2c, a);
  if (!r) return;
  u8 *x = vcall<u8 *>(*(u8 **)(r + 4), 0x2c, b);
  if (!x) return;
  r[0x90] = 1;
  x[0x10] = 0;
  *(u32 *)(x + 0x11) = 0xbf800000;
}
PCREG(5b6b30, fn5b6b30);

// 0x5f2fc0: thiscall(out) ret 4: if [this+8]+2 > [this+0xc] assert hook (int3 when null); word [out] = word [[this+8]]; [this+8] += 2
static void THISCALL fn5f2fc0(u8 *self, u16 *out) {
  if (*(u32 *)(self + 8) + 2 > *(u32 *)(self + 0xc)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u16 v = **(u16 **)(self + 8);
  *out = v;
  *(u32 *)(self + 8) += 2;
}
PCREG(5f2fc0, fn5f2fc0);
