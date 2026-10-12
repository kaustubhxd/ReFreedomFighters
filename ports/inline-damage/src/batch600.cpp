// batch600.cpp - damage thread, batch 600: hitpoint and damage-multiplier accessors.
// Names are the GameCube names from decoders/gc_pc_namemap.tsv; offsets are from the PC code (byte-packed).
//   ZFFActor   +0x7a0 s16 hitpoints, +0x7a2 s16 max hitpoints, +0x90f s32 playing hit anim id
//   ZLNKWHANDS +0x1e6 const char* hit animation name
//   ZLNKWHANDS damage multiplier per hit zone (float), zone -> offset:
//     0 +0x3ea, 1 +0x3fe, 2 +0x402, 3 +0x406, 4 +0x40a, 5 +0x3ee, 6 +0x3f6, 7 +0x40e, 8 +0x3f2, 9 +0x3fa
#include "ff.h"

// 0x7003b0: the assert hook (no arguments). When it is null the original executes int3.
typedef void (*AssertHook)(void);
#define g_assertHook G(AssertHook, 0x7003b0)

static inline u32 zoneOffset(u32 zone) {
  static const u16 off[10] = {0x3ea, 0x3fe, 0x402, 0x406, 0x40a, 0x3ee, 0x3f6, 0x40e, 0x3f2, 0x3fa};
  return off[zone];
}

// 0x5a2d90 ZFFActor::SetHitpoints(short): stores the value, then clamps it to max hitpoints (signed compare).
static void THISCALL setHitpoints(u8 *self, s16 hp) {
  s16 mx = *(s16 *)(self + 0x7a2);
  *(s16 *)(self + 0x7a0) = hp;
  if (hp > mx) *(s16 *)(self + 0x7a0) = mx;
}
PCREG(5a2d90, setHitpoints);

// 0x59fe00 ZFFActor::GetHitpoints() (sign-extended)
static s32 THISCALL getHitpoints(u8 *self) { return *(s16 *)(self + 0x7a0); }
PCREG(59fe00, getHitpoints);

// 0x5a2dc0 ZFFActor::SetMaxHitpoints(short): stores max, then lowers hitpoints to it when they are above.
static void THISCALL setMaxHitpoints(u8 *self, s16 mx) {
  *(s16 *)(self + 0x7a2) = mx;
  if (*(s16 *)(self + 0x7a0) > mx) *(s16 *)(self + 0x7a0) = mx;
}
PCREG(5a2dc0, setMaxHitpoints);

// 0x59fec0 ZFFActor::GetMaxHitpoints()
static s32 THISCALL getMaxHitpoints(u8 *self) { return *(s16 *)(self + 0x7a2); }
PCREG(59fec0, getMaxHitpoints);

// 0x5a2e10 ZFFActor::SetPlayingHitAnimId(int)
static void THISCALL setPlayingHitAnimId(u8 *self, s32 id) { *(s32 *)(self + 0x90f) = id; }
PCREG(5a2e10, setPlayingHitAnimId);

// 0x475930 ZLNKWHANDS::SetHitAnimation(const char*)
static void THISCALL setHitAnimation(u8 *self, const char *name) { *(const char **)(self + 0x1e6) = name; }
PCREG(475930, setHitAnimation);

// 0x474250 ZLNKWHANDS::GetDamageMultForBone(unsigned char) const: zone > 9 calls the assert hook and returns 0
// (int3 when there is no hook).
static float THISCALL getDamageMultForBone(u8 *self, u8 zone) {
  if (zone > 9) {
    AssertHook h = g_assertHook;
    if (!h) __builtin_debugtrap();
    h();
    return 0.0f;
  }
  return *(float *)(self + zoneOffset(zone));
}
PCREG(474250, getDamageMultForBone);

// 0x475820 ZLNKWHANDS::SetDamageMultForBone(unsigned char, float): zone > 9 is ignored (no assert).
static void THISCALL setDamageMultForBone(u8 *self, u8 zone, float m) {
  if (zone > 9) return;
  *(float *)(self + zoneOffset(zone)) = m;
}
PCREG(475820, setDamageMultForBone);
