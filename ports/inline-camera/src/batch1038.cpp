// batch1038.cpp - ZCAMERA activate/deactivate, room accessors and the always-draw list. Camera thread, 2026-10-11.
#include "cam.h"

// Always-draw list: count at +0x2c, entries at +0x24 (max 2 in the original's own check; a third add calls the
// debug hook at 0x7003b0, or executes int3 when there is none).

// 0x445390 ZCAMERA::ActivateCam(): once (flag 0x20), tell the camera list (sys +0x190f, vslot 0x2c) and set the flag.
static THISCALL void ZCAMERA_ActivateCam(u8 *self) {
  if (at<u8>(self, 0x48) & 0x20) return;
  u8 *list = ptr(G(u8 *, 0x70039c), 0x190f);
  if (list) vcall<void>(list, 0x2c);
  at<u32>(self, 0x48) |= 0x20;
}
PCREG(445390, ZCAMERA_ActivateCam);

// 0x445c70 ZCAMERA::DeactivateCam(): the reverse of ActivateCam.
static THISCALL void ZCAMERA_DeactivateCam(u8 *self) {
  if (at<u8>(self, 0x48) & 0x20) {
    u8 *list = ptr(G(u8 *, 0x70039c), 0x190f);
    if (list) vcall<void>(list, 0x2c);
  }
  at<u32>(self, 0x48) &= 0xffffffdfu;
}
PCREG(445c70, ZCAMERA_DeactivateCam);

// 0x445c50 ZCAMERA::CurrentRoom(): the cached room (+0x18), or the world object (manager +0xadc).
static THISCALL u32 ZCAMERA_CurrentRoom(u8 *self) {
  u32 r = at<u32>(self, 0x18);
  if (r) return r;
  return at<u32>(ptr(G(u8 *, 0x70039c), 0x9b), 0xadc);
}
PCREG(445c50, ZCAMERA_CurrentRoom);

// 0x445e70 ZCAMERA::GetCurrentRoomHint() const and 0x446d70 ZCAMERA::SetCurrentRoomHint(ZROOM*): dword at +0x192.
static THISCALL u32 ZCAMERA_GetCurrentRoomHint(u8 *self) { return at<u32>(self, 0x192); }
PCREG(445e70, ZCAMERA_GetCurrentRoomHint);
static THISCALL void ZCAMERA_SetCurrentRoomHint(u8 *self, u32 room) { at<u32>(self, 0x192) = room; }
PCREG(446d70, ZCAMERA_SetCurrentRoomHint);

// 0x4454a0 ZCAMERA::AddAlwaysDrawGeom(ZBaseGeom*): with two entries already, the debug hook (0x7003b0) runs first
// (or int3 when there is none); then the geometry is appended.
static THISCALL void ZCAMERA_AddAlwaysDrawGeom(u8 *self, u32 geom) {
  if (at<u32>(self, 0x2c) >= 2) {
    typedef void (*hookfn)();
    hookfn hook = G(hookfn, 0x7003b0);
    if (!hook) __builtin_debugtrap();
    hook();
  }
  u32 n = at<u32>(self, 0x2c);
  at<u32>(self, 0x24 + n * 4) = geom;  // with n == 2 this is the count word itself (the original's layout)
  at<u32>(self, 0x2c) += 1;            // incremented in place, as the original's inc does
}
PCREG(4454a0, ZCAMERA_AddAlwaysDrawGeom);

// 0x4464a0 ZCAMERA::RemoveAlwaysDrawGeom(ZBaseGeom*): finds the geometry, moves the last entry into its place.
static THISCALL u32 ZCAMERA_RemoveAlwaysDrawGeom(u8 *self, u32 geom) {
  u32 n = at<u32>(self, 0x2c);
  for (u32 i = 0; i < n; i++) {
    if (at<u32>(self, 0x24 + i * 4) == geom) {
      u32 last = n - 1;
      at<u32>(self, 0x2c) = last;
      at<u32>(self, 0x24 + i * 4) = at<u32>(self, 0x24 + last * 4);
      return 1;
    }
  }
  return 0;
}
PCREG(4464a0, ZCAMERA_RemoveAlwaysDrawGeom);
