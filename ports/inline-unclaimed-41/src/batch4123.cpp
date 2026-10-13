// batch4123.cpp - unclaimed-41 batch 23 (slice 13): 0x43b2d0 ZInputAction::UpdateActionBooleans() (thiscall, no arguments, ret 0).
// Whole function in one file. Groups: G1 prologue and the first early return; G2 the flag-byte 0x33 updates from the x1 branch;
// G3 the dl & 0x40 path (return or continue); G4 the bit-0 and bit-2/bit-1 updates with A2d; G5 the flag-call blocks (rm.vt[0x190]
// and the object's vtable slot 0x184 with caller pop 16).
#include "ff.h"

typedef u32(THISCALL * f0_t)(u8 *);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

// G5 block: r = rm.vt[0x190](rm); then (*r).vt[0x184] with ecx = *(r), arguments (r, 0x14, k, cnst), caller pops 16.
static void flagBlock(u8 *rm, u32 cnst, u32 k) {
  u8 *r = (u8 *)((f0_t)vslot(rm, 0x190))(rm);
  u8 *tmp = *(u8 **)r;
  u32 fn = *(u32 *)(tmp + 0x184);
  asm volatile("pushl %[c]\n\tpushl %[k]\n\tpushl $0x14\n\tpushl %[r]\n\tcall *%[fn]\n\taddl $16, %%esp"
               : "+c"(tmp)
               : [c] "r"(cnst), [k] "r"(k), [r] "r"(r), [fn] "r"(fn)
               : "eax", "edx", "memory", "cc");
}

static void THISCALL fn43b2d0(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  float K1 = G(float, 0x6785e4);
  float T1 = G(float, 0x67af24);
  float K2 = G(float, 0x679540);
  float T2 = G(float, 0x67af1c);

  // G1: the frame value F (rm+0x1c) and the x1 and x2 values
  u32 F = *(u32 *)(rm + 0x1c);
  u32 A25 = *(u32 *)(self + 0x25);
  u32 A1d = *(u32 *)(self + 0x1d);
  float x1 = (float)(s32)(F - A25) * K1;
  float x2 = (float)(s32)(F - A1d) * K1;
  u8 *b32 = self + 0x32;
  u8 *b33 = self + 0x33;
  if (x1 + x1 > T1) {
    float v = x2 + K2;
    if (0.0f > v) {
      *b32 &= 0x7f;
      *b33 &= 0x08;
      return;
    }
  }

  // G2: the dl & 0x10 branch on x1 and the flag byte 0x33
  u8 dl = *b32;
  u8 cl = dl & 0x10;
  if (cl != 0 && x1 > T2) {
    s32 d = (s32)(A25 - *(u32 *)(self + 0x2d));
    u8 al = *b33;
    if (d < 0x99)
      al = (u8)((al & ~0x20) | 0x08);
    else
      al = (u8)((al & ~0x08) | 0x20);
    *b33 = al;
  } else {
    if (cl == 0)
      *b33 &= ~0x20;
    *b33 &= ~0x08;
  }
  if (cl != 0) {
    u8 al = *b33;
    if (al >= 0x80)
      al = (u8)(al & ~0x40);
    else
      al = (u8)(al | 0xC0);
    *b33 = al;
  } else {
    *b33 &= 0x3f;
  }
  if (cl != 0)
    *b33 |= 0x10;
  else
    *b33 &= ~0x10;

  // G3: dl & 0x40 set: return (and clear bit 0 of 0x33 unless F == A2d); clear: continue
  if (dl & 0x40) {
    u8 c2 = *b33;
    if (!(c2 & 1))
      return;
    if (F == *(u32 *)(self + 0x2d))
      return;
    *b33 = (u8)(c2 & ~1);
    return;
  }

  // G4: the dl bits 0x80, the bit-0 and bit-2/bit-1 updates; A2d = F when bit 0 is set here
  u32 A21 = *(u32 *)(self + 0x21);
  u32 A29 = *(u32 *)(self + 0x29);
  float p1 = (float)(s32)(A1d - A25) * K1;
  float p4 = (float)(s32)(A21 - A29) * K1;
  float p3 = (float)(s32)(A25 - A21) * K1;
  dl |= 0x40;
  *b32 = dl;
  if (!(dl & 0x10) || (dl & 0x20))
    dl &= 0x7f;
  else
    dl |= 0x80;
  *b32 = dl;

  bool c_a = !(dl & 0x10) && (T2 > p1) && (T2 > x2);
  if (dl & 0x10) {
    *b33 &= ~1;
  } else if (c_a) {
    u8 al = *b33;
    if (al & 1) {
      *b33 = (u8)(al & ~1);
    } else {
      *b33 = (u8)(al | 1);
      *(u32 *)(self + 0x2d) = F;
    }
  } else {
    *b33 &= ~1;
  }

  dl = *b32;
  u8 al2 = dl & 0x10;
  if (al2 == 0 && T2 > p1 && T2 > p3 && T2 > p4 && T2 > x2)
    *b33 |= 4;
  else
    *b33 &= ~4;
  if (al2 != 0)
    *b33 &= ~2;
  else if (dl & 0x20)
    *b33 |= 2;
  else
    *b33 &= ~2;

  // G4 (tail): the render manager's object at +0x1907; equal to 0.0 returns
  u8 *p2 = *(u8 **)(rm + 0x1907);
  float fv = *(float *)(p2 + 4);
  if (fv == 0.0f)
    return;

  // G5: the seven flag blocks; each reads its bit when it is reached (the bit can change between blocks only through callees)
  flagBlock(rm, (*b32 & 0x80) ? 0x67a0a8u : 0x67aee8u, 0x14u);
  flagBlock(rm, (*b33 & 0x01) ? 0x67aeecu : 0x67aef4u, 0x15u);
  flagBlock(rm, (*b33 & 0x02) ? 0x67a0acu : 0x67aefcu, 0x16u);
  flagBlock(rm, (*b33 & 0x04) ? 0x67a0bcu : 0x67aee8u, 0x17u);
  flagBlock(rm, (*b33 & 0x08) ? 0x67a0d4u : 0x67af04u, 0x18u);
  flagBlock(rm, (*b33 & 0x10) ? 0x67a0a0u : 0x67a848u, 0x19u);
  flagBlock(rm, (*b33 & 0x20) ? 0x67a0c8u : 0x67af10u, 0x1au);
}
PCREG(43b2d0, fn43b2d0);
