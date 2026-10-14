// batch1633.cpp - ZDllSound::GetCurrentRoom (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
extern "C" char ext_445c50[];  // ZCAMERA::CurrentRoom (high), ECX = geom, result in EAX
typedef u32(THISCALL *CurrentRoomFn)(void *geom);

// 0x536c40 ZDllSound::GetCurrentRoom(ZGEOM* geom) [high]: with a geom, the camera's current room (ZCAMERA::CurrentRoom
// 0x445c50). Without one, the listener's room field of the database (+0xadc).
u32 THISCALL ZDllSound_GetCurrentRoom(void *self, void *geom) {
  (void)self;
  if (!geom) return AT(u32, AT(u8 *, sys(), 0x9b), 0xadc);
  return ((CurrentRoomFn)(void *)ext_445c50)(geom);
}
PCREG(536c40, ZDllSound_GetCurrentRoom);
