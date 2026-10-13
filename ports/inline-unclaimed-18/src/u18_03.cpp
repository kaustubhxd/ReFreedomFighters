// u18_03.cpp - area 18, group 3 (unclaimed-18 thread).
#include "ff.h"

extern "C" void THISCALL ext_5eac30(void *marker, void *obj);  // CActorActionMarker::Remove (one arg, ret 4; original code)

// 0x4bc050, ZSoundRandomVolume::ActivateVolume(bool) (GC map high). thiscall, ret 4: stores the flag byte at +0x78.
static void THISCALL activateVolume(u8 *self, u32 flag) { self[0x78] = (u8)flag; }
PCREG(4bc050, activateVolume);

// 0x59a850, ZGameOSD::RemoveActorActionMarker(ZCTRLIKLNKOBJ*) (GC map high). thiscall, ret 4. The exe tail-jumps to
// CActorActionMarker::Remove with the marker at +0x22d7 as `this` and the same argument; the callee pops the argument,
// which matches calling it with one argument and returning with ret 4.
static void THISCALL removeActorActionMarker(u8 *self, void *obj) {
  ext_5eac30(*(void **)(self + 0x22d7), obj);
}
PCREG(59a850, removeActorActionMarker);
