#include "ff.h"
// batch3524.cpp - area 35 claim 24 (docs/20-unclaimed-35.md): 0x49ff60 (residue name, medium). Thiscall, one stack arg (the
// reader). The exe's SEH frame (fs:[0]) and the /GS cookie check (call 0x633654) are not modelled.
// Stubbed in the harness: readers 0x4e5e60, 0x4e5e40, 0x4e5ea0; 0x4cc1d0; 0x4cbec0; 0x633654; the fake objects.

typedef u32(THISCALL *Slot0)(u8 *self);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a0);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a0, u32 a1);
typedef u32(*Cdecl4)(u32 a0, u32 a1, u32 a2, u32 a3);

extern "C" u32 THISCALL ext_4e5e60(u8 *r);
extern "C" u32 THISCALL ext_4e5e40(u8 *r);
extern "C" u8 *THISCALL ext_4e5ea0(u8 *r);
extern "C" u32 THISCALL ext_4cc1d0(u8 *r1);
extern "C" void THISCALL ext_4cbec0(u8 *local);

static u32 vcall0(u8 *o, u32 off) {
  return ((Slot0)*(u32 *)(*(u32 *)o + off))(o);
}
static u32 vcall1(u8 *o, u32 off, u32 a0) {
  return ((Slot1)*(u32 *)(*(u32 *)o + off))(o, a0);
}
static u32 vcall2(u8 *o, u32 off, u32 a0, u32 a1) {
  return ((Slot2)*(u32 *)(*(u32 *)o + off))(o, a0, a1);
}

// 0x49ff60, residue-name function (medium).
void THISCALL readerBlock(u8 *self, u32 arg) {
  u8 *R = (u8 *)arg;
  u8 *str = ext_4e5ea0(R);
  u8 *edi = str;
  if (str[0] != 0) {
    u8 *M = *(u8 **)(*(u32 *)0x70039c + 0x9b);
    u8 *O = *(u8 **)(M + 0xae4);
    edi = (u8 *)vcall2(O, 0, 0x677b5a, (u32)str);
    if (edi == str) {
      u8 local90[0x90];
      u8 *G = *(u8 **)0x700390;
      u8 *X = (u8 *)vcall2(G, 0x20, 0x68f6b4, 0x355);
      u8 *B = *(u8 **)(self + 0x44);
      u32 r1 = vcall2(B, 0x1d8, (u32)local90, 1);
      u32 r2 = ext_4cc1d0((u8 *)r1);
      u8 *vt = *(u8 **)X;
      ((Cdecl4)*(u32 *)(vt + 0x30))((u32)X, 0x68f8b4, r2, (u32)str);
      ext_4cbec0(local90);
      edi = str;
    }
  }
  ext_4e5ea0(R);
  vcall2(self, 0x88, (u32)edi, (u32)str);
  *(u32 *)(self + 0x48) = ext_4e5e60(R);
  *(u16 *)(self + 0x4c) = (u16)ext_4e5e40(R);
  *(u32 *)(self + 0x4e) = ext_4e5e60(R);
  *(u32 *)(self + 0x52) = ext_4e5e60(R);
  *(u32 *)(self + 0x56) = ext_4e5e60(R);
  *(u16 *)(self + 0x5f) = (u16)ext_4e5e40(R);
  *(u16 *)(self + 0x61) = (u16)ext_4e5e40(R);
  u8 flag = *(*(u8 **)R);
  if (flag != 0xff && (flag & 0x3f) == 3) {
    if (ext_4e5e60(R) != 0) {
      u8 *M = *(u8 **)(*(u32 *)0x70039c + 0x9b);
      u32 r3 = vcall0(M, 0x138);
      u32 local94 = 0;
      vcall2((u8 *)r3, 0x88, 0x681320, (u32)&local94);
      *(u32 *)(self + 0x4e) = local94;
    }
  }
  if (ext_4e5e60(R) == 0)
    *(u32 *)(self + 0x5a) |= 1;
  *(u32 *)(self + 0x106) = ext_4e5e60(R);
  flag = *(*(u8 **)R);
  if (flag != 0xff && (flag & 0x3f) == 3)
    ext_4e5e60(R);
}
PCREG(49ff60, readerBlock);
