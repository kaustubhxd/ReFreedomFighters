// batch60.cpp - mounted-gun tree, inline session batch 60: ZFFHeroMovementMachinegun::Move (0x5e6ab0), the per-frame
// aim and fire on a mounted gun.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u8(THISCALL *vcallB0)(void *self);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVPP)(void *self, void *a, void *b);
typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *sendFn)(void *self, u32 name, u32 a, u32 file, u32 line, u32 param, u32 b);
struct Quad { u32 a, b, c, d; };   // passed by value
typedef void(THISCALL *vcallFireAt)(void *self, float *aim, float spread, Quad q);

extern "C" void THISCALL ext_5cf690(u8 *cam, float *out);                          // ZCamHelper::GetFireAimPos (batch 52)
extern "C" void FASTCALL ext_4e09e0(float *dst, const float *src);                 // vneg(dst, src)
extern "C" void FASTCALL ext_4de040(float *out, const float *p, const float *q);   // createmat (batch 36)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);          // dst += v * s
extern "C" void THISCALL ext_594f10(u8 *hero, u32 hold);                            // ZFFHERO::SetHoldFire

// ZFFHERO::SetHoldFire (0x594f10) was lifted in batch 30; Move calls it as exe code.

static u8 *rmgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// The inline normalise (x87 under 53-bit control, so double arithmetic), here only tested on x and z.
static void normalizeXZ(float *v) {
  if (v[0] == 0.0f && v[2] == 0.0f)
    return;
  double x = v[0], y = v[1], z = v[2];
  double len = crt::sqrt(((x * x) + (y * y)) + (z * z));
  double inv = 1.0 / len;
  v[0] = (float)(x * inv);
  v[1] = (float)(y * inv);
  v[2] = (float)(z * inv);
}

// 0x5e6ab0 ZFFHeroMovementMachinegun::Move(const float *a0, const float *a1, float *a2, float *a3, float *a4), thiscall,
// ret 0x14. The hero (+0x36d) gets its ZCamHelper (+0x85a, made with slot 0x100 when missing) and the aim point from
// GetFireAimPos; the gun (+0x551) is sent "AimWeaponAt" with it (line 0x839). The gun's centre object (+0x559) gives the
// frame and position (slot 0x80 into a2 and a3); a3.y = a1.y. The facing is -a2 flattened to y = 0 and normalised,
// a2 becomes createmat(facing) and a3 moves 57.9 along it. The hero aims (slot 0x8c) and fires its idle (slot 0x4b0 with
// spread 0 and (0, 0, 0, -1)); a4 = (0, 0, 0). A zero hero timer (+0x9e3) clears the in-use byte +0x54c. With the fire
// key (+0x669) the key is released (SetHoldFire(false)) and the held weapon (+0x555) gets slots 0x360(10000),
// 0x358(1) and 0x2d0(3, 0), and +0x58d catches up with the tick count when it is more than 0x99 behind; without it the
// weapon gets slot 0x2d0(0, 0). The hero's slot 0x438 (dead or similar) also clears +0x54c.
static void THISCALL mgMove(u8 *self, const float *a0, const float *a1, float *a2, float *a3, float *a4) {
  (void)a0;
  u8 *rm = rmgr();
  u8 *gun = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x551));
  u8 *hero = *(u8 **)(self + 0x36d);
  if (*(u32 *)(hero + 0x85a) == 0)
    *(u32 *)(hero + 0x85a) = ((vcallUU)VT(hero, 0x100))(hero, 0x6a6e88u);   // "ZCamHelper"
  float aim[3];
  ext_5cf690(*(u8 **)(hero + 0x85a), aim);
  void **gvt = *(void ***)gun;
  rm = rmgr();
  u16 id = (u16)((sendFn)VT(rm, 0x114))(rm, 0x6b49f8u, 0, 0x6b7a5cu, 0x839, (u32)aim, 0);   // "AimWeaponAt"
  ((vcallVU)gvt[0x128 / 4])(gun, id);
  rm = rmgr();
  u8 *ctr = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x559));
  ((vcallVPP)VT(ctr, 0x80))(ctr, a2, a3);
  a3[1] = a1[1];
  float f[3];
  ext_4e09e0(f, a2);
  f[1] = 0.0f;
  normalizeXZ(f);
  ext_4de040(a2, f, 0);
  ext_451890(a3, f, bitsf(0x4267999au));   // 57.9
  hero = *(u8 **)(self + 0x36d);
  ((vcallVP)VT(hero, 0x8c))(hero, aim);
  hero = *(u8 **)(self + 0x36d);
  Quad q = {0, 0, 0, 0xffffffffu};
  ((vcallFireAt)VT(hero, 0x4b0))(hero, aim, 0.0f, q);
  a4[0] = 0.0f;
  a4[1] = 0.0f;
  a4[2] = 0.0f;
  if (*(float *)(*(u8 **)(self + 0x36d) + 0x9e3) == 0.0f)
    self[0x54c] = 0;
  rm = rmgr();
  u8 *wpn = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x555));
  hero = *(u8 **)(self + 0x36d);
  if (hero[0x669]) {
    ext_594f10(hero, 0);
    ((vcallVU)VT(wpn, 0x360))(wpn, 10000);
    ((vcallVU)VT(wpn, 0x358))(wpn, 1);
    ((vcallVUU)VT(wpn, 0x2d0))(wpn, 3, 0);
    s32 *last = (s32 *)(self + 0x58d);
    s32 *now = (s32 *)(G(u8 *, 0x70039c) + 0x40);
    if (*now > (s32)((u32)*last + 0x99u) && last != now)
      *last = *now;
  } else {
    ((vcallVUU)VT(wpn, 0x2d0))(wpn, 0, 0);
  }
  hero = *(u8 **)(self + 0x36d);
  if (((vcallB0)VT(hero, 0x438))(hero))
    self[0x54c] = 0;
}
PCREG(5e6ab0, mgMove);
