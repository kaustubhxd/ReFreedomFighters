// batch120.cpp - ZGameOSD::PlaySound(index) (climb thread, batch 120). GC map name: ZGameOSD::PlaySound(ESOUNDTYPE).
#include "ff.h"

static inline u8 *sys() { return G(u8 *, 0x70039c); }

// Plays the sound whose id is at +0x89 + 4*index of the OSD (a table of sound ids). With no sound manager (sys+0x1a9f) or
// a zero id: returns 0. Otherwise the manager's slot 0x120(id, 6) gives a handle, which the engine (sys+0x9b) looks up
// through slot 0x60; a found object gets +0xc = 3, and for index != 1 also +0x40 |= 0x80 and +0x2c = 2 (guesses: the
// sound's priority and loop/flag bits). Returns the handle.
static u32 THISCALL playSound(u8 *self, u32 index) {
  u32 id = *(u32 *)(self + 0x89 + index * 4);
  u8 *mgr = *(u8 **)(sys() + 0x1a9f);
  if (!mgr || !id)
    return 0;
  u32 h = vcall<u32>(mgr, 0x120, id, 6u);
  u8 *obj = vcall<u8 *>(*(void **)(sys() + 0x9b), 0x60, h);
  if (obj) {
    *(u32 *)(obj + 0xc) = 3;
    if (index != 1) {
      *(u32 *)(obj + 0x40) |= 0x80u;
      *(u32 *)(obj + 0x2c) = 2;
    }
  }
  return h;
}
PCREG(59a5e0, playSound);
