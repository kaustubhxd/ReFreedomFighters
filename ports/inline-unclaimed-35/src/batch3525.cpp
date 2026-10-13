#include "ff.h"
// batch3525.cpp - area 35 claim 25 (docs/20-unclaimed-35.md): 0x4a51e0 (residue name, medium). Thiscall, two stack args (a
// 16-bit selector and a pointer p); ret 8. The exe's control flow is kept with labels (the same targets as the disassembly).
// The SEH frame and the /GS cookie check are not modelled. Float constants 0x6785d0 and 0x6785e4 are read from the image.
// Stubbed in the harness: 0x4e7d70, 0x4e7930 (float return), 0x4a5da0, 0x4e7ce0, 0x4e7c50, 0x4a5f20 (float return), 0x4a5fe0,
// 0x4419f0, 0x43e960, 0x4de4f0 (fastcall), 0x633654 (no-op).

typedef u32(THISCALL *Slot0)(u8 *self);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a0);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a0, u32 a1);

extern "C" void THISCALL ext_4e7d70(u8 *self, u32 a0);
extern "C" float THISCALL ext_4e7930(u8 *self, u32 a0, u32 a1, u32 a2, float a3);
extern "C" void THISCALL ext_4a5da0(u8 *self, u32 a0);
extern "C" void THISCALL ext_4e7ce0(u8 *self, u32 a0);
extern "C" void THISCALL ext_4e7c50(u8 *self, u32 a0);
extern "C" float THISCALL ext_4a5f20(u8 *self, float a0);
extern "C" void THISCALL ext_4a5fe0(u8 *self);
extern "C" void FASTCALL ext_4419f0(u32 a0, u32 a1);
extern "C" void FASTCALL ext_43e960(u32 a0, u32 a1);
extern "C" void FASTCALL ext_4de4f0(u32 a0, u32 a1);

static u32 vcall0(u8 *o, u32 off) {
  return ((Slot0)*(u32 *)(*(u32 *)o + off))(o);
}
static u32 vcall1(u8 *o, u32 off, u32 a0) {
  return ((Slot1)*(u32 *)(*(u32 *)o + off))(o, a0);
}
static u32 vcall2(u8 *o, u32 off, u32 a0, u32 a1) {
  return ((Slot2)*(u32 *)(*(u32 *)o + off))(o, a0, a1);
}

// 0x4a51e0, residue-name dispatcher (medium).
void THISCALL dispatch4a51e0(u8 *self, u32 selArg, u32 p) {
  u16 si = (u16)selArg;
  u8 local10[0x20];
  u8 local34[0x20];
  if (si != 0x401) {
    if (si != 0x400)
      goto L528c;
    if (*(u8 *)(self + 0x92) != 0)
      goto L521f;
    if (*(u8 *)(self + 0xbf) != 1)
      goto L521f;
    vcall2(self, 0x68, 0x10, 0);
    goto L521f;
  }
  if (*(u8 *)(self + 0x92) == 0 && *(u8 *)(self + 0xbf) == 1)
    vcall1(self, 0x64, 0x10);

L521f:
  if (((s32)*(u32 *)(self + 0xb7) >> 10) == 0)
    goto L52ec;
  if (si != *(u16 *)0x700318)
    goto L52ec;
  *(u32 *)(self + 0xb7) = 0;
  vcall1(self, 0x64, 0x10);
  *(u8 *)(self + 0xbf) = 1;
  goto Lexit;

L528c:
  if (((s32)*(u32 *)(self + 0xb7) >> 10) != 0)
    goto L52cf;
  if (si != *(u16 *)0x70030c)
    goto L52cf;
  {
    u32 mgr = *(u32 *)0x70039c;
    if ((u32)(self + 0xb7) != mgr + 0x40)
      *(u32 *)(self + 0xb7) = *(u32 *)(mgr + 0x40);
  }
  vcall2(self, 0x68, 0x10, 0);
  *(u8 *)(self + 0xbf) = 0;
  goto Lexit;

L52cf:
  if (si != *(u16 *)0x700310)
    goto L521f;
  vcall2(self, 0x68, 0x10, 0);
  goto Lexit;

L52ec:
  if (si != *(u16 *)(self + 0x5d))
    goto L533c;
  *(u8 *)(self + 0xbf) = 1;
  ext_4e7d70(self + 0x48, *(u32 *)(*(u32 *)0x70039c + 0x40));
  vcall1(self, 0x64, 0x10);
  if (!(*(float *)(self + 0xbb) == *(float *)0x6785d0))
    goto Lexit;
  vcall0(self, 0x3c);
  goto Lexit;

L533c:
  if (si != *(u16 *)0x700308)
    goto L538c;
  if (!(*(u8 *)(self + 0x14) & 0x10))
    goto L5381;
  {
    float r = ext_4e7930(self + 0x48, *(u32 *)(*(u32 *)0x70039c + 0x40), (u32)local34, (u32)local10, -1.0f);
    *(float *)p = r;
  }
  goto Lexit;

L5381:
  *(u32 *)p = 0xbf800000u;
  goto Lexit;

L538c:
  if (si != *(u16 *)0x7002fc)
    goto L53a3;
  ext_4e7ce0(self + 0x48, p);
  goto Lexit;

L53a3:
  if (si != *(u16 *)0x700300)
    goto L53ba;
  ext_4e7c50(self + 0x48, p);
  goto Lexit;

L53ba:
  if (si != *(u16 *)0x700314)
    goto L53d8;
  ext_4a5da0(self, p != 0);
  goto Lexit;

L53d8:
  if (si != *(u16 *)0x700304)
    goto L5416;
  {
    float x = (float)(s32)p / *(float *)(self + 0x4c);
    float v = ext_4a5f20(self, x);
    if (!(0.0f > v))
      goto Lexit;
    ext_4a5fe0(self);
  }
  goto Lexit;

L5416:
  if (si != *(u16 *)0x70031c)
    goto Lexit;
  {
    u8 *B = *(u8 **)(self + 0x44);
    u32 pa = (u32)(self + 0x6b);
    u32 pb = (u32)(self + 0x5f);
    vcall2(B, 0x80, pa, pb);
    u8 *C = (u8 *)vcall0(B, 0x20);
    vcall2(C, 0x94, pa, pb);
    u32 v = *(u32 *)(self + 0x48);
    ext_4e7930(self + 0x48, v, (u32)local34, (u32)local10, -1.0f);
    ext_4419f0((u32)local10, (u32)(self + 0x93));
    ext_43e960((u32)(self + 0x5f), (u32)local34);
    ext_4de4f0((u32)(self + 0x6b), (u32)local34);
    float x = (float)(s32)*(u32 *)(*(u32 *)0x70039c + 0x40) * *(float *)0x6785e4;
    ext_4a5f20(self, x);
  }
  goto Lexit;

Lexit:
  return;
}
PCREG(4a51e0, dispatch4a51e0);
