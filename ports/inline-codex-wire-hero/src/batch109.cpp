// batch109.cpp - going down into a sewer: small members of ZFFHeroMovementOpenSewer (climb thread, batch 109).
#include "ff.h"

extern "C" void THISCALL ext_480fd0(void *self);   // ZAnimDefsList::~ZAnimDefsList body (batch 104)
extern "C" void THISCALL ext_4878d0(void *self);   // ZMovementBaseMove::~ZMovementBaseMove body (batch 104)
extern "C" void THISCALL ext_5e3e90(void *self);   // ZFFHeroMovementBaseMove::GetAnims
extern "C" void THISCALL ext_594590(void *hero);   // ZFFHERO::RestoreItem
extern "C" void THISCALL ext_59a6a0(void *osd, bool on);  // below
extern "C" void ext_634273(void *p, u32 size);     // operator delete(p, size), CRT

// 0x5e15d0, ZFFHeroMovementOpenSewer scalar deleting destructor (vtable 0x6b78f8, size 0x5bb); same shape as the jump and
// fall destructors of batch 104.
static u8 *THISCALL openSewerDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b78f8u;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if (flags & 1)
    ext_634273(self, 0x5bb);
  return self;
}
PCREG(5e15d0, openSewerDtor);

// 0x5e46e0, ZFFHeroMovementOpenSewer::GetAnims() (GC map high). Base GetAnims, +0x553 = slot 0x58("Open_Sewer"), and
// the two bytes +0x371, +0x372 set to 1 (one 16-bit store).
static void THISCALL openSewerGetAnims(u8 *self) {
  ext_5e3e90(self);
  *(void **)(self + 0x553) = vcall<void *>(self, 0x58, (const char *)0x6b7eec);
  *(u16 *)(self + 0x371) = 0x101;
}
PCREG(5e46e0, openSewerGetAnims);

// 0x59a6a0, thiscall, one stack arg (bool), ret 4: byte +0x22ce = arg. Called on the hero's +0x852 object (the on-screen
// display, inferred: ZGameOSD::ProgressValue sits right after it at 0x59a6b0). Name guess: ZGameOSD show/hide flag.
static void THISCALL osdSetFlag(u8 *self, bool on) { self[0x22ce] = on; }
PCREG(59a6a0, osdSetFlag);

// 0x5e7420, ZFFHeroMovementOpenSewer::TerminateControl(bool force) (GC map low: PC body shared by two GC functions).
// thiscall, ret 4, AL. force clears "opening" (+0x54c). When clear: the hero (+0x36d) gets its item back (RestoreItem),
// the display flag goes off (0x59a6a0 on hero+0x852 with 0), hero+0x9e3 = 0, and the byte is read again for the result.
static bool THISCALL openSewerTerminate(u8 *self, bool force) {
  if (force)
    self[0x54c] = 0;
  if (self[0x54c])
    return false;
  ext_594590(*(void **)(self + 0x36d));
  ext_59a6a0(*(void **)(*(u8 **)(self + 0x36d) + 0x852), false);
  *(u32 *)(*(u8 **)(self + 0x36d) + 0x9e3) = 0;
  return self[0x54c] == 0;
}
PCREG(5e7420, openSewerTerminate);
