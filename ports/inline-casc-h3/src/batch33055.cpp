// batch33055.cpp - h3 () batch 33055: tiny tier C wrappers, a log-style function, one SEH funclet
#include "ff.h"

extern "C" void THISCALL ext_4e6330(u8 *self, u8 *p);                 // ret 4
extern "C" void THISCALL ext_539730(u8 *self, u8 *a);                 // ret 4
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a);                  // ret 4
extern "C" u32 __attribute__((cdecl)) ext_42ac56(u8 *buf, u32 fmt, u32 a, u32 b);   // sprintf-like

#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();
typedef u32 (__attribute__((cdecl)) *log3_t)(u8 *, u32, u32);

// 0x487030: thiscall(a) ret 4: vt of a read first; r = table->slot 0x4c([this+8]); a->vtable[0x3c](r)
static u32 THISCALL fn487030(u8 *self, u8 *a) {
  u8 *vta = *(u8 **)a;
  u32 r = vcall<u32>(SYS_TABLE, 0x4c, *(u32 *)(self + 8));
  return ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vta + 0x3c))(a, r);
}
PCREG(487030, fn487030);

// 0x4ab9b0: thiscall(a) ret 4: sub-object p=this+0x6e: p->slot 0xc(); if !([this+4]&2) 0x4e6330(a, p)
static void THISCALL fn4ab9b0(u8 *self, u8 *a) {
  u8 *p = self + 0x6e;
  vcall<u32>(p, 0xc);
  if (!(self[4] & 2)) ext_4e6330(a, p);
}
PCREG(4ab9b0, fn4ab9b0);

// 0x533bf0: thiscall(a) ret 4 bool: a->slot 8(0x14); 0x539730(this, a); return 1
static u32 THISCALL fn533bf0(u8 *self, u8 *a) {
  vcall<u32>(a, 8, 0x14u);
  ext_539730(self, a);
  return 1;
}
PCREG(533bf0, fn533bf0);

// 0x55baa0: thiscall(a) ret 4: r = 0x5003d0([a+4], 0); [this+0x1c]->slot 0x6e8((u8)*r, 0, 0)
static u32 THISCALL fn55baa0(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  return vcall<u32>(*(u8 **)(self + 0x1c), 0x6e8, (u32)*r, 0u, 0u);
}
PCREG(55baa0, fn55baa0);

// 0x5ef520: thiscall: slot 8() of the objects at +0xa9, +0xa1, +0xa5, then of +0xb1 when non-null
static void THISCALL fn5ef520(u8 *self) {
  vcall<u32>(*(u8 **)(self + 0xa9), 8);
  vcall<u32>(*(u8 **)(self + 0xa1), 8);
  vcall<u32>(*(u8 **)(self + 0xa5), 8);
  u8 *o = *(u8 **)(self + 0xb1);
  if (o) vcall<u32>(o, 8);
}
PCREG(5ef520, fn5ef520);

// 0x605110: cdecl(): r = [0x700390]->slot 0x20(str, 0x31); cdecl r->vtable[0x2c](r, s1, s2); assert hook; return 0
static u32 fn605110() {
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x6b9bc8u, 0x31u);
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x6b97ac);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(605110, fn605110);

// 0x467740: thiscall: o=[this+0x1ce]; if [o+4] assert hook; o=[this+0x1ce] re-read; return o->slot 4()
static u32 THISCALL fn467740(u8 *self) {
  u8 *o = *(u8 **)(self + 0x1ce);
  if (*(u32 *)(o + 4)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  o = *(u8 **)(self + 0x1ce);
  return vcall<u32>(o, 4);
}
PCREG(467740, fn467740);

// 0x42333d: SEH funclet: sprintf-like 0x42ac56(buf=ebp-0x414, fmt, p[0], p[1]) with p=[ebp-0x4bc]; [ebp-0x49c]->slot 0x3c(); MessageBox-like import [0x6761bc](0, buf, str, 0x40010); returns 0x423386
typedef u32 (STDCALL *imp4_t)(u32, u8 *, u32, u32);
static u32 fn42333d() {
  u8 *pebp = *(u8 **)__builtin_frame_address(0);
  u32 *p = *(u32 **)(pebp - 0x4bc);
  u8 *buf = pebp - 0x414;
  ext_42ac56(buf, 0x678054, p[0], p[1]);
  u8 *o = *(u8 **)(pebp - 0x49c);
  vcall<u32>(o, 0x3c);
  (*(imp4_t *)0x6761bc)(0, buf, 0x678018, 0x40010);
  return 0x423386;
}
PCREG(42333d, fn42333d);
