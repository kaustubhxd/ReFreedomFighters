// batch2488.cpp - decomp area 24, batch 2488.
#include "ff.h"

extern "C" void THISCALL ext_4e6ce0(void *self);     // base destructor step (thiscall, no argument)
extern "C" u8 THISCALL ext_4e5ef0(void *self);       // DBREAD::operator bool (thiscall, AL)
extern "C" void ext_634273(void *p, u32 size);       // __builtin_delete (cdecl)

// 0x46e9c0 (GUESS): slot 0x25c of this with (0x688860, 0). A nonzero result is returned, otherwise this.
static u8 *THISCALL guess46e9c0(u8 *self) {
  u32 r = vcall<u32>(self, 0x25c, (u32)0x688860, 0u);
  return r ? (u8 *)r : self;
}
PCREG(46e9c0, guess46e9c0);

// 0x485f60 ZActionReloadItem::~ZActionReloadItem(), thiscall, ret 4. Sets the vtable, deletes the object (size 0x40) when bit 0 of the
// argument is set, and returns this.
static u8 *THISCALL reloadItemDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294u;
  if (flags & 1)
    ext_634273(self, 0x40);
  return self;
}
PCREG(485f60, reloadItemDtor);

// 0x49e490 ZRunParamAnim::~ZRunParamAnim(), thiscall, ret 4. Base destructor step, then delete (size 0xc1) when bit 0 is set.
static u8 *THISCALL runParamAnimDtor(u8 *self, u32 flags) {
  ext_4e6ce0(self);
  if (flags & 1)
    ext_634273(self, 0xc1);
  return self;
}
PCREG(49e490, runParamAnimDtor);

// 0x5db150 ZDamageBox::CopyEventDataBlock(DBREAD&), thiscall, ret 4. Stores the DBREAD bool as a byte at +0x88 and as a dword
// (0 or 1) at +0x60.
static void THISCALL damageBoxCopyDataBlock(u8 *self, void *db) {
  u8 b = ext_4e5ef0(db);
  *(u8 *)(self + 0x88) = b;
  *(u32 *)(self + 0x60) = b != 0;
}
PCREG(5db150, damageBoxCopyDataBlock);
