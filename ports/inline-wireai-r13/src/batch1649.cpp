// batch1649.cpp - CMsgForward::Init() (0x49ef10, residue 13, 2026-10-12). Name map: high (vt CMsgForward[2]). When the
// flag byte at +4 has bit 2, takes the id from the object at +0x44 (vslot 0x20), passes it to the manager's vslot 0x4c
// and stores the result at +0x48, then clears the word at +0x4c. The manager is sys+0x9b. GUESS: the slot names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

void THISCALL CMsgForward_Init(u8 *self) {
  if (!(AT(u8, self, 4) & 2)) return;
  u8 *src = AT(u8 *, self, 0x44);
  u32 id = vcall<u32>(src, 0x20);
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  AT(u32, self, 0x48) = vcall<u32>(mgr, 0x4c, id);
  AT(u16, self, 0x4c) = 0;
}
PCREG(49ef10, CMsgForward_Init);
