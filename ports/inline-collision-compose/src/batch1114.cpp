// batch1114.cpp - collision thread, batch 1114: ZBaseGeom::SetControl (the main render-manager blocker of
// docs/20-inline-batch-4-5.md batch 42) and ZBaseGeom::LightNotifyPotentialDetachment.
#include "ff.h"

static inline u8 *renderMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *lightMgr() { return *(u8 **)(renderMgr() + 0x5d35); }   // [[0x70039c]+0x9b]+0x5d35

// 0x4dbb00 ZBaseGeom::LightNotifyPotentialDetachment(bool attach) [high], thiscall, ret 4. Byte +0x58 marks a geom
// that has bumped its lights. attach: unless already marked, every light the light manager lists for +0x68 (slot 8:
// (&count, key) returns an array) gets its +0x58 counter incremented and flag 0x1000000 set; then marked. !attach:
// if marked, each listed light's non-zero counter is decremented; then unmarked. A missing manager only changes the mark.
static void THISCALL lightNotify(u8 *self, u32 attach) {
  if ((u8)attach) {
    if (self[0x58])
      return;
    u8 *L = lightMgr();
    if (L) {
      u32 n;
      u8 **arr = vcall<u8 **>(L, 8, &n, *(u32 *)(self + 0x68));
      for (u32 i = 0; i < n; i++) {
        arr[i][0x58]++;
        *(u32 *)(arr[i] + 0x3c) |= 0x1000000;
      }
    }
    self[0x58] = 1;
    return;
  }
  if (!self[0x58])
    return;
  u8 *L = lightMgr();
  if (L) {
    u32 n;
    u8 **arr = vcall<u8 **>(L, 8, &n, *(u32 *)(self + 0x68));
    for (u32 i = 0; i < n; i++)
      if (arr[i][0x58])
        arr[i][0x58]--;
  }
  self[0x58] = 0;
}
PCREG(4dbb00, lightNotify);

extern "C" void THISCALL ext_4d9d20(u8 *self, u8 *room);   // AttachToRoomsDrawLists (batch 1113)
extern "C" void THISCALL ext_4da770(u8 *self, u8 *room);   // DetachFromRoomsDrawLists (batch 1113)
extern "C" void THISCALL ext_4da360(u8 *self, u32 set, u32 mask);   // low control byte up the parent chain
extern "C" u32 THISCALL ext_4db840(const u8 *self);        // class id of the bound object (0x200002 without one)
extern "C" void THISCALL ext_4dbb00(u8 *self, u32 attach);

// 0x4dc630 ZBaseGeom::SetControl(unsigned set, unsigned mask) [high], thiscall, ret 8. flags (+0x3c) =
// (flags & ~mask) | set, with three side effects:
// - 0x2000 (hidden): clearing it re-attaches the geom to its room draw lists; setting it detaches first.
// - low byte: written straight away (low byte only) and pushed up the parent chain (0x4da360) when set is non-zero.
// - 0x8000 (light receiver): unless the render manager is busy (slot 0x178) or lighting is off (slot 0x40), a geom
//   in a room (+0x6c) whose class has 0xa00000 bits registers with the light manager ([rm]+0x5d35 slot 0x24, handle to
//   +0x68) when 0x8000 turns on, or unregisters (slot 0x28, after LightNotifyPotentialDetachment(false) for
//   0x800000 classes; +0x68 = 0) when it turns off. Either way 0x1000000 (lights dirty) is set.
static void THISCALL setControl(u8 *self, u32 set, u32 mask) {
  u32 *fl = (u32 *)(self + 0x3c);
  if ((mask & 0x2000) && !(set & 0x2000) && (*fl & 0x2000)) {
    *fl &= ~0x2000u;
    ext_4d9d20(self, 0);
    mask &= ~0x2000u;
  }
  if ((set & 0x2000) && !(*fl & 0x2000)) {
    ext_4da770(self, 0);
    *fl |= 0x2000;
    set &= ~0x2000u;
  }
  if ((u8)(set | mask)) {
    u32 lo = set & 0xff;
    u32 v = (~mask & *fl) | lo;
    self[0x3c] = 0;
    *fl |= (u8)v;
    if (lo)
      for (u8 *p = *(u8 **)(self + 0x50); p; p = *(u8 **)(p + 0x50))
        ext_4da360(p, lo, 0);
  }
  set &= 0xffffff00u;
  mask &= 0xffffff00u;
  if ((set | mask) & 0x8000) {
    if (!vcall<u8>(renderMgr(), 0x178) && vcall<u8>(renderMgr(), 0x40)) {
      if (set & 0x8000) {
        if (!(*fl & 0x8008000) && *(u32 *)(self + 0x6c)) {
          u32 cls = ext_4db840(self);
          u8 *L;
          if ((cls & 0xa00000) && (L = lightMgr())) {
            u32 h = vcall<u32>(L, 0x24, self);
            *fl |= 0x1000000;
            *(u32 *)(self + 0x68) = h;
            *fl = (~mask & *fl) | set;
            return;
          }
        }
      } else if (mask & 0x8000) {
        if ((*fl & 0x8008000) == 0x8000 && *(u32 *)(self + 0x6c)) {
          u32 cls = ext_4db840(self);
          u8 *L;
          if ((cls & 0xa00000) && (L = lightMgr())) {
            if (cls & 0x800000)
              ext_4dbb00(self, 0);
            vcall<void>(L, 0x28, self);
            *fl |= 0x1000000;
            *(u32 *)(self + 0x68) = 0;
            *fl = (~mask & *fl) | set;
            return;
          }
        }
      }
    }
  }
  *fl = (~mask & *fl) | set;
}
PCREG(4dc630, setControl);
