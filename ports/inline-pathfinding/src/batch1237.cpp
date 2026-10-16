// batch1237.cpp - pathfinding tree: CDoorBlocker::GetPos(float *out) [map 0x4875a0; thiscall, ret 4] and
// CDoorBlocker::GetType() [map 0x52b3e0; thiscall, returns 1]. GetPos: with a geometry (the door's +4), the geometry's
// sub-object (+8) fills out (0x4daf90 copies its three dwords at +0x30..+0x38), then the geometry's slot 0x84 is asked
// for the position (the exe tail-jumps there). Without a geometry nothing is written.
#include "pf.h"

extern "C" void THISCALL ext_4daf90(const u8 *self, float *out);   // three dwords at self+0x30 -> out (ret 4)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static void THISCALL doorGetPos(u8 *door, float *out) {
  u8 *geom = rdp(door + 4);
  if (geom) {
    ext_4daf90(rdp(geom + 8), out);
    vcall<void>(geom, 0x84, out);
  }
}
PCREG(4875a0, doorGetPos);

static u32 THISCALL doorGetType(u8 *door) {
  (void)door;
  return 1;
}
PCREG(52b3e0, doorGetType);
