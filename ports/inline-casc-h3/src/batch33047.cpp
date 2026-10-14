// batch33047.cpp - h3 () batch 33047: tiny tier C vtable wrappers
#include "ff.h"

extern "C" u32 THISCALL ext_4db2c0(u8 *self, u32 a, u32 b);   // ret 8

// 0x475ac0: thiscall: sub-object at this+0x34f (unaligned vtable), slot 0xc(this)
static u32 THISCALL fn475ac0(u8 *self) { return vcall<u32>(self + 0x34f, 0xc, (u32)self); }
PCREG(475ac0, fn475ac0);

// 0x5646e0: thiscall(a) ret 4: if [this+0xc82]==0x20 slot 0xfc(0)
static void THISCALL fn5646e0(u8 *self, u32 a) {
  if (*(u32 *)(self + 0xc82) == 0x20) vcall<u32>(self, 0xfc, 0u);
}
PCREG(5646e0, fn5646e0);

// 0x5f9dc0: thiscall: if (--[this+4] == 0) slot 4(this)
static void THISCALL fn5f9dc0(u8 *self) {
  u32 v = *(u32 *)(self + 4) - 1;
  *(u32 *)(self + 4) = v;
  if (v == 0) vcall<u32>(self, 4, (u32)self);
}
PCREG(5f9dc0, fn5f9dc0);

// 0x46e6d0: thiscall(a,b) ret 8: r = slot 0x348(); tail-call 0x4db2c0([r+8], a, b)
static u32 THISCALL fn46e6d0(u8 *self, u32 a, u32 b) {
  u8 *r = vcall<u8 *>(self, 0x348);
  return ext_4db2c0(*(u8 **)(r + 8), a, b);
}
PCREG(46e6d0, fn46e6d0);

// 0x4d4f00: stdcall(a,b) ret 8: calls the assert hook at [0x7003b0] (int3 when null), returns al=0
typedef u32 (*hook_t)();
static u32 STDCALL fn4d4f00(u32 a, u32 b) {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(4d4f00, fn4d4f00);

// 0x635490: thiscall: o = [this+0x14]; if (o) o->slot 0(1)
static void THISCALL fn635490(u8 *self) {
  u8 *o = *(u8 **)(self + 0x14);
  if (o) vcall<u32>(o, 0, 1u);
}
PCREG(635490, fn635490);

// 0x466f30: thiscall: r = slot 0x20(); return r->slot 0x7c()
static u32 THISCALL fn466f30(u8 *self) {
  u8 *r = vcall<u8 *>(self, 0x20);
  return vcall<u32>(r, 0x7c);
}
PCREG(466f30, fn466f30);

// 0x51d100: thiscall: slot 0x2ec([this+0x499]); [this+0x499]=0
static void THISCALL fn51d100(u8 *self) {
  vcall<u32>(self, 0x2ec, *(u32 *)(self + 0x499));
  *(u32 *)(self + 0x499) = 0;
}
PCREG(51d100, fn51d100);
