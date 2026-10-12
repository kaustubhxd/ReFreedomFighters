// batch275.cpp - unclaimed area 67, gap band 0x5e1000-0x601000.
#include "ff.h"

typedef u32 (THISCALL *F0)(u8 *self);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5fb910, thiscall, ret 4: [this+0x30] = v.
static void THISCALL setAt30(u8 *selfP, u32 v) { *(u32 *)(selfP + 0x30) = v; }
PCREG(5fb910, setAt30);

// 0x5f5150, thiscall: obj = this+0xaca; return obj->vslot[0](obj).
static u32 THISCALL fwdAca0(u8 *selfP) {
  u32 o = (u32)(unsigned long)selfP + 0xaca;
  return ((F0)rdw(rdw(o, 0), 0))((u8 *)(unsigned long)o);
}
PCREG(5f5150, fwdAca0);

// 0x5f3fb0, thiscall: obj = this+0xaca; return obj->vslot[4](obj).
static u32 THISCALL fwdAca4(u8 *selfP) {
  u32 o = (u32)(unsigned long)selfP + 0xaca;
  return ((F0)rdw(rdw(o, 0), 4))((u8 *)(unsigned long)o);
}
PCREG(5f3fb0, fwdAca4);

// 0x5fa5d0, thiscall, plain ret: [this] = 0x6b91dc; global 0x724270 = this; returns this.
static u32 THISCALL ctorGlobal724270(u8 *selfP) {
  *(u32 *)selfP = 0x6b91dcu;
  *(u32 *)0x724270 = (u32)(unsigned long)selfP;
  return (u32)(unsigned long)selfP;
}
PCREG(5fa5d0, ctorGlobal724270);

// 0x5f3150, thiscall, ret 4 (argument a): [this+8] = [this+4] + a.
static void THISCALL sumInto8(u8 *selfP, u32 a) {
  u32 self = (u32)(unsigned long)selfP;
  *(u32 *)(selfP + 8) = rdw(self, 4) + a;
}
PCREG(5f3150, sumInto8);
