// batch613.cpp - band 0x421000-0x441000, batch 613: three methods.
//   0x428800 (thiscall, returns al): o = [this+0x71]; if !o return 0; call o's slot 0x1c with ecx = this and one argument o;
//     then byte [this+0xb1] = 1; return 1. (The call uses this, not o, as ecx: the exe does not reload ecx.)
//   0x429ae0 (thiscall, returns al): same with slot 0x20 and byte [this+0xb1] = 0.
//   0x432cd0 (thiscall, returns al): al = slot 0 of this() & slot 0x4c of this(), both with ecx = this, no arguments.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);
typedef u32(THISCALL *vNone)(void *self);

static u8 THISCALL flagAfterSlot1c(u8 *self) {
  u8 *o = *(u8 **)(self + 0x71);
  if (!o)
    return 0;
  ((vOne)VT(o, 0x1c))(self, (u32)o);
  *(u8 *)(self + 0xb1) = 1;
  return 1;
}
PCREG(428800, flagAfterSlot1c);

static u8 THISCALL flagAfterSlot20(u8 *self) {
  u8 *o = *(u8 **)(self + 0x71);
  if (!o)
    return 0;
  ((vOne)VT(o, 0x20))(self, (u32)o);
  *(u8 *)(self + 0xb1) = 0;
  return 1;
}
PCREG(429ae0, flagAfterSlot20);

static u8 THISCALL andOfTwoSlots(u8 *self) {
  u8 a = (u8)((vNone)VT(self, 0))(self);
  u8 b = (u8)((vNone)VT(self, 0x4c))(self);
  return a & b;
}
PCREG(432cd0, andOfTwoSlots);
