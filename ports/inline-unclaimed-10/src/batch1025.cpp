// batch1025.cpp - unclaimed-10, batch 21 (residue-10 list, core-todo/residue-10.txt; docs/20-unclaimed-10.md): two save/load routines.
// Thiscall, one argument (the ZSaveGame / ZLoadGame), return al = 1. Each clears bit 0x40 of this+4 and calls the save/load
// object's virtual slots with values or addresses from this. The slots are unverified callees, stubbed in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

// 0x5b82e0, CCheckInsideBox::Save(ZSaveGame*) (high): save->vt[+0x3c](dword this+0x48); save->vt[+0x3c](dword +0x4c);
// save->vt[+0x64](dword +0x50); save->vt[+0x64](dword +0x54); save->vt[+0x3c](dword +0x5c); returns 1.
static u8 THISCALL checkInsideBoxSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((Slot1)VT(save)[0x3c / 4])(save, *(u32 *)(self + 0x48));
  ((Slot1)VT(save)[0x3c / 4])(save, *(u32 *)(self + 0x4c));
  ((Slot1)VT(save)[0x64 / 4])(save, *(u32 *)(self + 0x50));
  ((Slot1)VT(save)[0x64 / 4])(save, *(u32 *)(self + 0x54));
  ((Slot1)VT(save)[0x3c / 4])(save, *(u32 *)(self + 0x5c));
  return 1;
}
PCREG(5b82e0, checkInsideBoxSave);

// 0x4aace0, CCheckVisible::Load(ZLoadGame*) (high): load->vt[+0x18](this+0x54, 0x640); load->vt[+0x18](this+0x694, 0x157c0);
// load->vt[+0x40](this+0x15e54); load->vt[+0x40](this+0x15e58); load->vt[+0x50](this+0x15e78); returns 1.
static u8 THISCALL checkVisibleLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((Slot2)VT(load)[0x18 / 4])(load, (u32)(unsigned long)(self + 0x54), 0x640);
  ((Slot2)VT(load)[0x18 / 4])(load, (u32)(unsigned long)(self + 0x694), 0x157c0);
  ((Slot1)VT(load)[0x40 / 4])(load, (u32)(unsigned long)(self + 0x15e54));
  ((Slot1)VT(load)[0x40 / 4])(load, (u32)(unsigned long)(self + 0x15e58));
  ((Slot1)VT(load)[0x50 / 4])(load, (u32)(unsigned long)(self + 0x15e78));
  return 1;
}
PCREG(4aace0, checkVisibleLoad);
