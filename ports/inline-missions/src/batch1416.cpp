// batch1416.cpp - missions thread, batch 1416: ZFFCareTaker_C02A Init2, Save, Load and the byte-array save helpers.
#include "missions.h"

extern "C" s32 THISCALL ext_59b310(u8 *lc, const char *name);   // ZFFLevelController::GetLevelVar
extern "C" u8 *THISCALL ext_59b3c0(u8 *lc);                     // ZFFLevelController::GetStartingSewerLid
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);   // vdist2 (squared distance, x87 return)
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);      // mcpy (3x3 matrix copy)

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u8 *byHandle(u32 h) { return vcall<u8 *, u32>(mgr(), 0x58, h); }

// A small byte array: s32 count, then the bytes.
// 0x5ba850 (no GameCube name; ZSaveGame << byte array, fastcall): count with slot 0x3c, then each byte with 0x60.
extern "C" u8 *FASTCALL m_5ba850(u8 *sg, u8 *arr) {
  vcall<void, u32>(sg, 0x3c, *(u32 *)arr);
  for (u8 *p = arr + 4; p != arr + 4 + *(u32 *)arr; p++)
    vcall<void, u32>(sg, 0x60, (u32)*p);
  return sg;
}
PCREG(5ba850, m_5ba850);

// 0x5ba800 (no GameCube name; ZLoadGame >> byte array, fastcall): a count (slot 0x48), then that many bytes (slot
// 0x68) appended to the array (it is not cleared first).
extern "C" u8 *FASTCALL m_5ba800(u8 *lg, u8 *arr) {
  s32 n;
  vcall<void, s32 *>(lg, 0x48, &n);
  for (s32 i = 0; i < n; i++) {
    u8 b;
    vcall<void, u8 *>(lg, 0x68, &b);
    arr[4 + *(u32 *)arr] = b;
    (*(u32 *)arr)++;
  }
  return lg;
}
PCREG(5ba800, m_5ba800);

// 0x5bbb60 ZFFCareTaker_C02A::Save(ZSaveGame*): bools +0x294 +0x295, the flag array +0x2b8, bools +0x297 +0x296
// +0x298 +0x373 +0x374 +0x375. Returns true.
static u8 THISCALL c02aSave(u8 *ct, u8 *sg) {
  *(u32 *)(ct + 4) &= ~0x40u;
  vcall<void, u32>(sg, 0x60, (u32)ct[0x294]);
  vcall<void, u32>(sg, 0x60, (u32)ct[0x295]);
  m_5ba850(sg, ct + 0x2b8);
  static const u16 offs[6] = {0x297, 0x296, 0x298, 0x373, 0x374, 0x375};
  for (int i = 0; i < 6; i++) vcall<void, u32>(sg, 0x60, (u32)ct[offs[i]]);
  return 1;
}
PCREG(5bbb60, c02aSave);

// 0x5bb8c0 ZFFCareTaker_C02A::Load(ZLoadGame*): the mirror of Save.
static u8 THISCALL c02aLoad(u8 *ct, u8 *lg) {
  *(u32 *)(ct + 4) &= ~0x40u;
  vcall<void, u8 *>(lg, 0x68, ct + 0x294);
  vcall<void, u8 *>(lg, 0x68, ct + 0x295);
  m_5ba800(lg, ct + 0x2b8);
  static const u16 offs[6] = {0x297, 0x296, 0x298, 0x373, 0x374, 0x375};
  for (int i = 0; i < 6; i++) vcall<void, u8 *>(lg, 0x68, ct + offs[i]);
  return 1;
}
PCREG(5bb8c0, c02aLoad);

// 0x5bb520 ZFFCareTaker_C02A::Init2().
//  - The hero ("ObjectHero") into +0x64.
//  - Without the mission variable C02B_Flag (the other C02 sub-zone's flag not raised yet): +0x295 = 1.
//    With it: the actor +0x1dc is moved to the position of the list-+0x1e8 object nearest (squared distance) to
//    the level's starting sewer lid.
//  - Objects +0x70 (slot 0x28) and +0x74 (slot 0x2c) are switched; the +0x80 object is moved 100 units down.
//  - Registers itself as "CareTaker_2A".
static void THISCALL c02aInit2(u8 *ct) {
  {
    u8 *reg = vcall<u8 *>(mgr(), 0x138);
    u32 h = 0;
    vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x6ac89c, &h);
    *(u8 **)(ct + 0x64) = byHandle(h);
  }
  float bestMat[9], bestPos[3], mat[9], pos[3];   // best* stay uninitialised when nothing is nearer, as in the original
  u8 *lc = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c15);   // the game data's level controller
  if (ext_59b310(lc, (const char *)0x6b045c) == 0) {   // C02B_Flag
    ct[0x295] = 1;
  } else {
    float lidPos[3] = {0.0f, 0.0f, 0.0f};
    u8 *lid = ext_59b3c0(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c15));
    vcall<void, float *>(lid, 0x84, lidPos);
    float best = 9.99999968e37f;
    u8 *list = ct + 0x1e8;
    if (list) {
      u32 it;
      vcall<void, u32 *>(list, 0x4c, &it);
      u32 h = vcall<u32, u32 *>(list, 0x5c, &it);
      while (it) {
        u8 *o = byHandle(h);
        vcall<void, float *, float *>(o, 0x80, mat, pos);
        float d = ext_4e0830(lidPos, pos);
        if (comiss_gt(best, d)) {
          best = d;
          bestPos[0] = pos[0];
          bestPos[1] = pos[1];
          bestPos[2] = pos[2];
          ext_4de420(bestMat, mat);
        }
        h = vcall<u32, u32 *>(list, 0x5c, &it);
      }
    }
    u8 *a = byHandle(*(u32 *)(ct + 0x1dc));
    vcall<void, float *, float *>(a, 0x370, bestMat, bestPos);
    vcall<void, float *, float *>(a, 0x5dc, bestPos, bestMat);
  }
  if (*(u32 *)(ct + 0x70))
    vcall<void>(byHandle(*(u32 *)(ct + 0x70)), 0x28);
  if (*(u32 *)(ct + 0x74))
    vcall<void>(byHandle(*(u32 *)(ct + 0x74)), 0x2c);
  if (*(u32 *)(ct + 0x80)) {
    u8 *o = byHandle(*(u32 *)(ct + 0x80));
    vcall<void, float *, float *>(o, 0x80, mat, bestPos);   // the original reuses the same stack slots
    bestPos[1] = bestPos[1] - 100.0f;
    vcall<void, float *, float *>(o, 0x7c, mat, bestPos);
  }
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 t = vcall<u32, u32, u32>(mgr(), 0x4c, *(u32 *)(ct + 0x44), 0x10);   // manager slot 0x4c(sender, 0x10) -> handle
  vcall<void, const char *, u32>(reg, 0x60, (const char *)0x6b2b90, t);   // registry slot 0x60(name, handle): CareTaker_2A
}
PCREG(5bb520, c02aInit2);
