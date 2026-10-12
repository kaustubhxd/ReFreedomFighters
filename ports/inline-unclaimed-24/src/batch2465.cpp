// batch2465.cpp - decomp area 24, batch 2465 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_441c00(void *self);   // base destructor (recorder)
extern "C" void THISCALL ext_444020(void *self);   // base destructor (recorder)
extern "C" void ext_4690b0(void *self, u32 state); // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);               // ZGEOM::operator delete (cdecl)

static void releaseByFlagState(u8 *self, u32 flag, u32 state) {
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, state);
    else
      ext_45c510(self);
  }
}

// 0x441d50 (GUESS destructor), thiscall, ret 4, eax = this.
static u8 *THISCALL guessDtor441d50(u8 *self, u32 flag) {
  ext_441c00(self);
  releaseByFlagState(self, flag, 0x83u);
  return self;
}
PCREG(441d50, guessDtor441d50);

// 0x4440e0 ZROOM::~ZROOM, thiscall, ret 4, eax = this.
static u8 *THISCALL roomDtor(u8 *self, u32 flag) {
  ext_444020(self);
  releaseByFlagState(self, flag, 0xc4u);
  return self;
}
PCREG(4440e0, roomDtor);

// 0x45be20 ZProjectMarks::FadeMark(unsigned int, float), thiscall, ret 8. The float is passed as its bits.
static void THISCALL projectMarksFadeMark(u8 *self, u32 idx, u32 fbits) {
  u8 *sys = G(u8 *, 0x70039c);
  void *o1 = *(void **)(sys + 0x190f);
  void *o2 = vcall<void *>(o1, 0x20);
  u32 elem = *(u32 *)(*(u8 **)(self + 0x40) + 4 * idx);
  vcall<void>(o2, 0x44, elem, fbits);
}
PCREG(45be20, projectMarksFadeMark);
