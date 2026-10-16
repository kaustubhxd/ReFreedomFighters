// batch113.cpp - the remaining vtable slots of the climb, jump, fall and open-sewer movements: ZMovementBase defaults and
// shared one-liners (climb thread, batch 113). Slot numbers are from the RTTI vtables (pc.vtables()).
#include "ff.h"

// 0x460e10, ZLnkAction::Name() (GC map low; ZFFActionClimbSewer slot 8): returns the string "N/A" (0x6852b8).
static const char *THISCALL lnkActionName(void *) { return (const char *)0x6852b8; }
PCREG(460e10, lnkActionName);

// 0x47fbd0, ZLnkAction::GetActionId() const (GC map low; ZFFActionClimbSewer slot 1): returns the dword at +4.
static u32 THISCALL getActionId(u8 *self) { return *(u32 *)(self + 4); }
PCREG(47fbd0, getActionId);

// 0x549de0, folded "return true" (ZFFActionClimbSewer slots 3 and 4; also ZMovementGuide::DisableUpperBody in the map).
static bool THISCALL returnTrue(void *) { return true; }
PCREG(549de0, returnTrue);

// 0x64fbd0, folded "return false" (movement vtables slots 10 and 11).
static bool THISCALL returnFalse(void *) { return false; }
PCREG(64fbd0, returnFalse);

// 0x610100, folded empty method with one stack arg (ZFFActionClimbSewer slots 6 and 7: Save/Load-shaped).
static void THISCALL emptyOneArg(void *, u32) {}
PCREG(610100, emptyOneArg);

// 0x487c30, ZMovementBase::CalcNewSpeed(a, b, c, d) (GC map medium; the climb's slot 15): zeroes d, then c (three floats
// each). thiscall, ret 0x10.
static void THISCALL baseCalcNewSpeed(void *, const float *, const float *, float *c, float *d) {
  d[0] = 0.0f;
  d[1] = 0.0f;
  d[2] = 0.0f;
  c[0] = 0.0f;
  c[1] = 0.0f;
  c[2] = 0.0f;
}
PCREG(487c30, baseCalcNewSpeed);

// 0x488490, ZMovementBase::FindBestAnim(const char*) const (GC map medium): forwards to the owner's (+4) slot 0x35c.
static void *THISCALL findBestAnim(u8 *self, const char *name) { return vcall<void *>(*(void **)(self + 4), 0x35c, name); }
PCREG(488490, findBestAnim);

// 0x489330, ZMovementBase::GetSettingsFromAnim(ZAnimDefs*) const (GC map medium): forwards to the owner's slot 0x5e4.
static u32 THISCALL getSettingsFromAnim(u8 *self, void *defs) { return vcall<u32>(*(void **)(self + 4), 0x5e4, defs); }
PCREG(489330, getSettingsFromAnim);

// 0x489350, ZMovementBase::Load(ZLoadGame*) (GC map medium): the load stream's slot 0x50 reads the float at +0xc, then
// the movement's own slot 0x20 (GetAnims) runs; returns true.
static bool THISCALL baseLoad(u8 *self, void *lg) {
  vcall<void>(lg, 0x50, (float *)(self + 0xc));
  vcall<void>(self, 0x20);
  return true;
}
PCREG(489350, baseLoad);

// 0x489d00, ZMovementBase::Save(ZSaveGame*) (GC map medium): the save stream's slot 0x4c writes the float at +0xc;
// returns true.
static bool THISCALL baseSave(u8 *self, void *sg) {
  vcall<void>(sg, 0x4c, *(float *)(self + 0xc));
  return true;
}
PCREG(489d00, baseSave);

// 0x4893c0, the fall's Move slot (GC map low; likely ZMovementBaseMove::Move shared by several classes): own slot 0x40
// (new position and speed) then own slot 0x48 (collision) with the same five arguments; EAX is what slot 0x48 left.
static u32 THISCALL baseMove(u8 *self, const float *a, const float *b, float *c, float *d, float *e) {
  vcall<void>(self, 0x40, a, b, c, d, e);
  return vcall<u32>(self, 0x48, a, b, c, d, e);
}
PCREG(4893c0, baseMove);

// 0x5e3da0 / 0x5e3d60, ZFFHeroMovementBaseMove::GetActiveWalkDefsList / GetActiveRunDefsList (GC map medium). With the
// owner's (+4) flag bit 27 set both give the list at +0x4ab; otherwise walk gives +0x3d (bit 10 set) or +0x25, and run
// gives +0x3eb (bit 10) or +0x3d3. (Guess: bit 27 = in water, bit 10 = crouched.)
static u8 *THISCALL activeWalkDefs(u8 *self) {
  u32 f = *(u32 *)(*(u8 **)(self + 4) + 0x417);
  if (f & 0x8000000u)
    return self + 0x4ab;
  return self + ((f & 0x400u) ? 0x3d : 0x25);
}
PCREG(5e3da0, activeWalkDefs);

static u8 *THISCALL activeRunDefs(u8 *self) {
  u32 f = *(u32 *)(*(u8 **)(self + 4) + 0x417);
  if (f & 0x8000000u)
    return self + 0x4ab;
  return self + ((f & 0x400u) ? 0x3eb : 0x3d3);
}
PCREG(5e3d60, activeRunDefs);
