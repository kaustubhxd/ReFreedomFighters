// batch623.cpp - band 0x421000-0x441000, batch 623: three small functions.
//   0x428960 (thiscall, no args): o = [this+0x71]; if !o return (eax = 0); else call o's slot 0x1c with ecx = THIS and one
//     argument o (the exe does not reload ecx); byte [this+0xb1] = (result == 0). The return value is not defined on that path.
//   0x43e5f0 ZHELPER::DispSphere(int) (thiscall, ret 4): if (low byte of dword [this+0x18]) & 0xc is zero, set bit 1 of the
//     dword when the argument is non-zero, else clear it.
//   0x42fb60 (thiscall, four float arguments, ret 0x10): float [this+0x9a7] = a, [+0x9ab] = b, [+0x9af] = c, [+0x9b3] = d.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);

static void THISCALL flagAfterSlot1c(u8 *self) {
  u8 *o = *(u8 **)(self + 0x71);
  if (!o)
    return;
  u32 r = ((vOne)VT(o, 0x1c))(self, (u32)o);
  *(u8 *)(self + 0xb1) = (r == 0);
}
PCREG(428960, flagAfterSlot1c);

static void THISCALL setBit1(u8 *self, u32 a) {
  u32 v = *(u32 *)(self + 0x18);
  if ((u8)v & 0xc)
    return;
  if (a)
    v |= 2;
  else
    v &= 0xfffffffdu;
  *(u32 *)(self + 0x18) = v;
}
PCREG(43e5f0, setBit1);

static void THISCALL storeFour(u8 *self, float a, float b, float c, float d) {
  *(float *)(self + 0x9a7) = a;
  *(float *)(self + 0x9ab) = b;
  *(float *)(self + 0x9af) = c;
  *(float *)(self + 0x9b3) = d;
}
PCREG(42fb60, storeFour);
