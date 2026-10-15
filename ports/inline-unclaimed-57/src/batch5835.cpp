// batch5835.cpp - residue 9, 0x4c4e50 (ZAnimSequence::Load(ZLoadGame*), gc name map), thiscall, one stack argument (load), ret 4, returns al = 1.
// this+4 &= ~0x40; load->vt[+0x58](this+0x65); load->vt[+0x68](this+0x69); load->vt[+0x70](dword this+0x6a).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

// 0x4c4e50, thiscall, one stack argument (ZAnimSequence::Load)
static u8 THISCALL unnamed4c4e50(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((Slot1)VT(load)[0x58 / 4])(load, (u32)(unsigned long)(self + 0x65));
  ((Slot1)VT(load)[0x68 / 4])(load, (u32)(unsigned long)(self + 0x69));
  ((Slot1)VT(load)[0x70 / 4])(load, *(u32 *)(self + 0x6a));
  return 1;
}
PCREG(4c4e50, unnamed4c4e50);
