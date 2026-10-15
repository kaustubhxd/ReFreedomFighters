// batch1020.cpp - unclaimed-10, batch 16 (docs/20-unclaimed-10.md): two save-game load routines. Thiscall, one argument (the
// ZLoadGame), return al = 1. The load object's virtual slots are unverified callees, stubbed in the spec (logging vtable).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotLoad)(u8 *self, u32 a);  // load->vt[+slot](value)

// 0x4b8a10, ZRelayMessageList::Load(ZLoadGame*) (high): clears bit 6 of this+4; load->vt[+0x50](this+0x54); returns 1.
static u8 THISCALL relayMessageListLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotLoad)VT(load)[0x50 / 4])(load, (u32)(unsigned long)(self + 0x54));
  return 1;
}
PCREG(4b8a10, relayMessageListLoad);

// 0x4c4e50, ZAnimSequence::Load(ZLoadGame*) (high): clears bit 6 of this+4; load->vt[+0x58](this+0x65); load->vt[+0x68](this+0x69);
// load->vt[+0x70](the dword at this+0x6a); returns 1.
static u8 THISCALL animSequenceLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotLoad)VT(load)[0x58 / 4])(load, (u32)(unsigned long)(self + 0x65));
  ((SlotLoad)VT(load)[0x68 / 4])(load, (u32)(unsigned long)(self + 0x69));
  ((SlotLoad)VT(load)[0x70 / 4])(load, *(u32 *)(self + 0x6a));
  return 1;
}
PCREG(4c4e50, animSequenceLoad);
