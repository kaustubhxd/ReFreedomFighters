// batch33050.cpp - h3 () batch 33050: tiny tier C wrappers, one SEH funclet with import calls
#include "ff.h"

extern "C" u32 THISCALL ext_463940(u8 *self);   // ret 0

// 0x4f10d0: thiscall: r = slot 0x274(-1); return slot 0x23c(r)
static u32 THISCALL fn4f10d0(u8 *self) {
  u8 *vt = *(u8 **)self;
  u32 r = ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vt + 0x274))(self, 0xffffffffu);
  return ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vt + 0x23c))(self, r);
}
PCREG(4f10d0, fn4f10d0);

// 0x5373d0: stdcall(p) ret 4: calls the assert hook at [0x7003b0] (int3 when null), [p]=0, returns 0
typedef u32 (*hook_t)();
static u32 STDCALL fn5373d0(u32 *p) {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  *p = 0;
  return 0;
}
PCREG(5373d0, fn5373d0);

// 0x6568b0: thiscall(a) ret 4: r = slot 0xc(a); o = [sysobj+0x1aa3]; tail-call o->slot 0x80(word [r+4])
static u32 THISCALL fn6568b0(u8 *self, u32 a) {
  u8 *r = vcall<u8 *>(self, 0xc, a);
  u8 *o = *(u8 **)(*(u8 **)0x70039c + 0x1aa3);
  return vcall<u32>(o, 0x80, (u32) * (u16 *)(r + 4));
}
PCREG(6568b0, fn6568b0);

// 0x462d10: thiscall(a,b,c) ret 0xc: [this+0x6c]->slot 0x14(b, c, a, this)
static u32 THISCALL fn462d10(u8 *self, u32 a, u32 b, u32 c) {
  return vcall<u32>(*(u8 **)(self + 0x6c), 0x14, b, c, a, (u32)self);
}
PCREG(462d10, fn462d10);

// 0x467390: thiscall: slot 0x360() when bit 17 of [this+0x159] else slot 0x364(); tail-call 0x463940(this)
static u32 THISCALL fn467390(u8 *self) {
  if (*(u32 *)(self + 0x159) & 0x20000) vcall<u32>(self, 0x360);
  else vcall<u32>(self, 0x364);
  return ext_463940(self);
}
PCREG(467390, fn467390);

// 0x473b20: thiscall: slot 0x548(0,0); return slot 0x54c(0,0)
static u32 THISCALL fn473b20(u8 *self) {
  vcall<u32>(self, 0x548, 0u, 0u);
  return vcall<u32>(self, 0x54c, 0u, 0u);
}
PCREG(473b20, fn473b20);

// 0x4d8bf0: thiscall(a) ret 4: r = [this+4]->slot 0x84(a); return r ? r + 4 : 0
static u32 THISCALL fn4d8bf0(u8 *self, u32 a) {
  u32 r = vcall<u32>(*(u8 **)(self + 4), 0x84, a);
  return r ? r + 4 : 0;
}
PCREG(4d8bf0, fn4d8bf0);

// 0x425c3b: SEH funclet in the parent frame (esi = parent's esi): release [ebp-0x1c] via import 0x676070, then esi via imports
typedef u32 (STDCALL *imp1_t)(u32);
typedef u32 (STDCALL *imp2_t)(u32, u32);
static u32 fn425c3b() {
  u32 esi;
  __asm__ volatile("" : "=S"(esi));
  u8 *pebp = *(u8 **)__builtin_frame_address(0);
  u32 p = *(u32 *)(pebp - 0x1c);
  if (p) (*(imp1_t *)0x676070)(p);
  if (esi) {
    u32 h = (*(imp2_t *)0x6760a8)(0, esi);
    (*(imp1_t *)0x6760a4)(h);
  }
  return 0;
}
PCREG(425c3b, fn425c3b);
