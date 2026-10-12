// batch274.cpp - unclaimed area 67, gap band 0x5e1000-0x601000: 0x5f1580, forwarder on the object at [this+0xc]+8.
#include "ff.h"

typedef u32 (THISCALL *F0)(u8 *self);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f1580, thiscall: o = [this+0xc] + 8; return o->vslot[4](o) (ECX = o, no arguments).
static u32 THISCALL fwdNested(u8 *selfP) {
  u32 o = rdw((u32)(unsigned long)selfP, 0xc) + 8;
  return ((F0)rdw(rdw(o, 0), 4))((u8 *)(unsigned long)o);
}
PCREG(5f1580, fwdNested);
