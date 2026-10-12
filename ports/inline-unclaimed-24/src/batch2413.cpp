// batch2413.cpp - decomp area 24, batch 2413: CHitpointControl::Load(ZLoadGame*) (0x584970), thiscall, ret 4, AL = 1.
// A local dword (the DBREAD) is cleared; flag 0x40 of this is cleared; ZEventBase::GetInput(&local) (exe); vtable
// slot 4 of this with &local; then load-game slot 0x50 with +0x64 and +0x57 and slot 0x40 with +0x6c.
#include "ff.h"

extern "C" void THISCALL ext_6352f0(void *self, void *dbread);  // ZEventBase::GetInput(DBREAD&), ret 4

// 0x584970
static u8 THISCALL hitpointControlLoad(u8 *self, void *ld) {
  u32 local = 0;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ext_6352f0(self, &local);
  vcall<void>(self, 4, &local);
  vcall<void>(ld, 0x50, self + 0x64);
  vcall<void>(ld, 0x50, self + 0x57);
  vcall<void>(ld, 0x40, self + 0x6c);
  return 1;
}
PCREG(584970, hitpointControlLoad);
