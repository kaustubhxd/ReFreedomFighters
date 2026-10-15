// batch743.cpp - ZItemWeapon::Save(ZSaveGame* save) (0x4707c0) [high], area 72 (claim listed in docs/20-unclaimed-81.md), 2026-10-12.
// ZItem::Save (0x4705a0) on the item with the save object, then a chain of writes: slot 0x68 pointer (+0xaa), 0x3c / 0x44
// dwords, 0x60 bytes and 0x4c float. Several writes chain on the object returned by the previous write (eax reused as ecx),
// tracked explicitly. Returns true. No SEH frame in this function.
#include "ff.h"

extern "C" void THISCALL ext_4705a0(void *item, void *save);   // ZItem::Save

#define BY(o) ((u32)self[(o)])
#define DW(o) (*(u32 *)(self + (o)))
#define FL(o) (*(float *)(self + (o)))
#define PT(o) ((u32)(self + (o)))

// 0x4707c0 ZItemWeapon::Save(ZSaveGame* save) [high].
static bool THISCALL weapon_Save(u8 *self, u8 *save) {
  ext_4705a0(self, save);
  vcall<void>(save, 0x68, PT(0xaa));
  vcall<void>(save, 0x3c, DW(0xb6));
  vcall<void>(save, 0x44, DW(0xba));
  void *c5 = vcall<void *>(save, 0x60, BY(0xbe));
  void *c6 = vcall<void *>(c5, 0x60, BY(0xbf));
  void *c7 = vcall<void *>(c6, 0x44, DW(0xc0));
  vcall<void>(c7, 0x44, DW(0xc4));
  void *a = vcall<void *>(save, 0x60, BY(0xc8));
  a = vcall<void *>(a, 0x60, BY(0xc9));
  a = vcall<void *>(a, 0x60, BY(0xca));
  a = vcall<void *>(a, 0x60, BY(0xcb));
  vcall<void>(a, 0x60, BY(0xcc));
  void *r = vcall<void *>(save, 0x4c, FL(0xd1));
  vcall<void>(r, 0x3c, DW(0xd5));
  void *r9 = vcall<void *>(save, 0x3c, DW(0xdd));
  void *r10 = vcall<void *>(r9, 0x3c, DW(0xe5));
  void *r11 = vcall<void *>(r10, 0x3c, DW(0xe1));
  vcall<void>(r11, 0x3c, DW(0xed));
  vcall<void>(save, 0x68, PT(0xf1));
  void *r12 = vcall<void *>(save, 0x3c, DW(0xfd));
  vcall<void>(r12, 0x3c, DW(0x101));
  vcall<void>(save, 0x6c, DW(0xd9));
  return true;
}
PCREG(4707c0, weapon_Save);
