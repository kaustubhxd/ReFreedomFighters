// batch237.cpp - small leaves, slice 0/1. 0x5625c0 (name GUESS): thiscall(a1) (ret 4). If [this+0x85]: return. vt[0xc4](this, 0).
// e = [this+0xdc] (signed): e < 0 or e not in {2} (and not <= 1): vt[0xe8](this); return. If e <= 1: return. Else (e == 2):
// [this+0x85] = 1; [this+0x64] = float(rm[0x30]) * K1; [this+0x48] = a1; r2 = vt[0x84](this) (NO pushed argument); r3 = (r2+0xcb)
// ->vt[0x14](); if [this+0x48] == 0 and r3 <= 1: [this+0xdc] = 1; r4 = vt[0x84](this, 0) (one argument); ext 0x4f21f0(r4); return.
// Else: [this+0xdc] = 4; r5 = vt[0x84](this, 0); ext 0x4f21f0(r5); if [this+0x48] == 0: return; a1 = 5; obj = [this+0x44];
// obj->vt[0x12c]([this+0x48], (u16)[this+0x74], &a1) (three words). K1 = [0x6785e4]. rm = [0x70039c].
// vt[0x84] is called twice: the first call pushes nothing and the second pushes one word; the stub that serves it pops by
// its call count (see specs_s237.py). The port reproduces the two prototypes.
#include "ff.h"

extern "C" void THISCALL ext_4f21f0(u8 *self);   // original (stored ecx in the harness)

typedef u32(THISCALL *SlotNone)(u8 *);             // vtable slot, no stack words, eax result
typedef u32(THISCALL *SlotOne)(u8 *, u32);         // vtable slot, one stack word, eax result
typedef void(THISCALL *SlotThree)(u8 *, u32, u32, u32 *);   // vtable 0x12c: three stack words

static u32 vslot17(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static void THISCALL path_5625c0(u8 *self, u32 a1) {
  if (*(u8 *)(self + 0x85)) return;
  ((SlotOne)vslot17(self, 0xc4))(self, 0);
  s32 e = *(s32 *)(self + 0xdc);
  if (e < 0 || e != 2) {
    if (e <= 1 && e >= 0) return;
    ((SlotNone)vslot17(self, 0xe8))(self);
    return;
  }
  *(u8 *)(self + 0x85) = 1;
  float k1 = G(float, 0x6785e4);
  float f = (float)(s32)*(u32 *)(G(u8 *, 0x70039c) + 0x30) * k1;
  *(float *)(self + 0x64) = f;
  *(u32 *)(self + 0x48) = a1;
  u8 *r2 = (u8 *)(u32)((SlotNone)vslot17(self, 0x84))(self);
  u8 *sub = r2 + 0xcb;
  u32 r3 = ((SlotNone)vslot17(sub, 0x14))(sub);
  if (*(u32 *)(self + 0x48) == 0 && (s32)r3 <= 1) {
    *(u32 *)(self + 0xdc) = 1;
    u8 *r4 = (u8 *)(u32)((SlotOne)vslot17(self, 0x84))(self, 0);
    ext_4f21f0(r4);
    return;
  }
  *(u32 *)(self + 0xdc) = 4;
  u8 *r5 = (u8 *)(u32)((SlotOne)vslot17(self, 0x84))(self, 0);
  ext_4f21f0(r5);
  if (*(u32 *)(self + 0x48) == 0) return;
  a1 = 5;
  u8 *obj = *(u8 **)(self + 0x44);
  ((SlotThree)vslot17(obj, 0x12c))(obj, *(u32 *)(self + 0x48), (u32)*(u16 *)(self + 0x74), &a1);
}
PCREG(5625c0, path_5625c0);
