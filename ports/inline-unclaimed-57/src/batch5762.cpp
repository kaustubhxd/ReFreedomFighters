// batch5762.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 62: 0x5c71c0 (GUESS name unnamed_5c71c0), thiscall, one stack
// argument (the load object, ret 4), returns al = 1. Order: clear bit 0x40 of this+4; 0x6352f0(this, &tmp) (writes tmp);
// dwords from 0x4e5e60(&tmp) at this+0x48 and +0x4c; 0x4e5ea0(&tmp) at this+0x50; load->vt[+0x68](load, this+0x54).
// The callees 0x6352f0, 0x4e5e60 and 0x4e5ea0 run as ORIGINAL code through ext_; the spec hooks all three and the load slot.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotLoad)(u8 *self, u32 a);

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);  // writes *out, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5ea0(u8 *db);  // reader, original code (hooked in the spec)

// 0x5c71c0, thiscall, one stack argument (the load object), ret 4 (GUESS name)
static u8 THISCALL unnamed5c71c0(u8 *self, u8 *load) {
  u32 tmp = 0;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ext_6352f0(self, &tmp);
  *(u32 *)(self + 0x48) = ext_4e5e60((u8 *)&tmp);
  *(u32 *)(self + 0x4c) = ext_4e5e60((u8 *)&tmp);
  *(u32 *)(self + 0x50) = ext_4e5ea0((u8 *)&tmp);
  ((SlotLoad)VT(load)[0x68 / 4])(load, (u32)(unsigned long)(self + 0x54));
  return 1;
}
PCREG(5c71c0, unnamed5c71c0);
