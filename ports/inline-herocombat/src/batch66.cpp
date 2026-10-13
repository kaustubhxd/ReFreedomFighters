// batch66.cpp - grenade flight, inline session batch 66: ZParamParticle::ZParamParticle (0x4e7160) and ZProjectile
// GetMaterialDesc (0x4ba180), SetTarget (0x4ba620), SetPrecision (0x4ba470), SetProjectileInfo (0x4ba570) and Command
// (0x4b94f0).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u32(THISCALL *vcallU0)(void *self);
typedef void(THISCALL *vcallV0)(void *self);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef long double(THISCALL *rndFn)(void *self, u32 file, u32 line);   // result in ST0, kept at full x87 width

extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                    // vmmul, v = v * m (batch 48)
extern "C" void FASTCALL ext_4de7a0(float *m);                                    // mreset (identity)
extern "C" void THISCALL ext_4db2a0(u8 *geom, float *m);                          // ZBaseGeom::GetMat (mcpy)
extern "C" void THISCALL ext_4deb20(float *m, float deg, float x, float y, float z);   // mrotaxis
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract (batch 34)
extern "C" void FASTCALL ext_4e09b0(float *v);                                    // vneg in place
extern "C" void FASTCALL ext_4de040(float *out, const float *p, const float *q);  // createmat (batch 36)
extern "C" void THISCALL ext_4e73b0(u8 *pp, const float *pos, const float *vel, const float *acc, float drag,
                                    float time);                                  // ZParamParticle::Init (batch 65)
extern "C" void THISCALL ext_4ba620(u8 *self, const float *target);              // SetTarget (this batch)
extern "C" void THISCALL ext_4ba470(u8 *self, float prec);                        // SetPrecision (this batch)
extern "C" void THISCALL ext_4ba310(u8 *self);                                    // ZProjectile::Reset (batch 24)
extern "C" void THISCALL ext_4ba570(u8 *self, const u8 *info);                    // SetProjectileInfo (this batch)
extern "C" void FASTCALL ext_4de480(float *a, const float *b);                  // rows times matrix (batch 48)

// 0x4e7160 ZParamParticle::ZParamParticle(), thiscall, eax = this. All eleven floats (+0 to +0x28) start at 0.
static u8 *THISCALL particleCtor(u8 *self) {
  for (int i = 0; i < 11; ++i)
    *(u32 *)(self + 4 * i) = 0;
  return self;
}
PCREG(4e7160, particleCtor);

// 0x4ba180 ZProjectile::GetMaterialDesc(unsigned id), thiscall, ret 4, eax. With an owner handle (+0x4c) the owner
// (render-manager slot 0x58) is asked for the material (slot 0x2c8), falling back to material 0; without one the render
// manager's slot 0x160 answers the same way.
static u32 THISCALL getMaterialDesc(u8 *self, u32 id) {
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  void **vt = *(void ***)rm;
  u32 h = *(u32 *)(self + 0x4c);
  if (h) {
    u8 *o = (u8 *)((vcallUU)vt[0x58 / 4])(rm, h);
    u32 r = ((vcallUU)VT(o, 0x2c8))(o, id);
    if (!r)
      r = ((vcallUU)VT(o, 0x2c8))(o, 0);
    return r;
  }
  u32 r = ((vcallUU)vt[0x160 / 4])(rm, id);
  if (r)
    return r;
  rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((vcallUU)VT(rm, 0x160))(rm, 0);
}
PCREG(4ba180, getMaterialDesc);

// The inline x87 normalise (53-bit, so double arithmetic); an all-zero vector is left alone.
static void normalize3(float *v) {
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)
    return;
  double x = v[0], y = v[1], z = v[2];
  double inv = 1.0 / crt::sqrt(((x * x) + (y * y)) + (z * z));
  v[0] = (float)((double)v[0] * inv);
  v[1] = (float)((double)v[1] * inv);
  v[2] = (float)((double)v[2] * inv);
}

// 0x4ba620 ZProjectile::SetTarget(const float *target), thiscall, ret 4. The geometry (+0x44) gives the world position
// (slot 0x84 on the origin); the direction to the target, turned by the geometry's parent (slot 0x20, then its slot
// 0x8c), normalised and negated, makes the frame (createmat) whose rows are rotated (1, 2, 0) and set with slot 0x6c.
// A ballistic projectile (flag 0x10 in +0x89) starts its flight (ZParamParticle at +0x6d) from the position with
// velocity target - position, gravity (0, -982, 0), no drag, at the current time.
static void THISCALL setTarget(u8 *self, const float *target) {
  float pos[3] = {0.0f, 0.0f, 0.0f};
  u8 *geom = *(u8 **)(self + 0x44);
  ((vcallVP)VT(geom, 0x84))(geom, pos);
  float d[3];
  ext_43e920(d, target, pos);
  geom = *(u8 **)(self + 0x44);
  u8 *par = (u8 *)((vcallU0)VT(geom, 0x20))(geom);
  ((vcallVP)VT(par, 0x8c))(par, d);
  normalize3(d);
  ext_4e09b0(d);
  float m[9];
  ext_4de040(m, d, 0);
  float r[9] = {m[3], m[4], m[5], m[6], m[7], m[8], m[0], m[1], m[2]};
  geom = *(u8 **)(self + 0x44);
  ((vcallVP)VT(geom, 0x6c))(geom, r);
  if (*(u32 *)(self + 0x89) & 0x10) {
    float g[3] = {0.0f, -982.0f, 0.0f}, v[3];
    ext_43e920(v, target, pos);
    float now = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * bitsf(0x3a800000u);
    ext_4e73b0(*(u8 **)(self + 0x6d), pos, v, g, 0.0f, now);
  }
}
PCREG(4ba620, setTarget);

// 0x4ba470 ZProjectile::SetPrecision(float spread), thiscall, ret 4. The geometry's frame M is turned twice by a random
// angle: around its row 0, then around its (new) row 1, each angle = the game's random number (0x70039c slot 0x1c4,
// ZProjectile.cpp lines 730 and 733, in ST0) times the spread, in degrees (mrotaxis). The frame goes back with slot
// 0x6c.
static void THISCALL setPrecision(u8 *self, float spread) {
  float m[9], r[9];
  ext_4db2a0(*(u8 **)(*(u8 **)(self + 0x44) + 8), m);
  ext_4de7a0(r);
  u8 *sys = G(u8 *, 0x70039c);
  long double a = ((rndFn)VT(sys, 0x1c4))(sys, 0x692ab4u, 0x2da);
  ext_4deb20(r, (float)(a * (long double)spread), m[0], m[1], m[2]);
  ext_4de480(m, r);
  ext_4de7a0(r);
  sys = G(u8 *, 0x70039c);
  a = ((rndFn)VT(sys, 0x1c4))(sys, 0x692ab4u, 0x2dd);
  ext_4deb20(r, (float)(a * (long double)spread), m[3], m[4], m[5]);
  ext_4de480(m, r);
  u8 *geom = *(u8 **)(self + 0x44);
  ((vcallVP)VT(geom, 0x6c))(geom, m);
}
PCREG(4ba470, setPrecision);

// 0x4ba570 ZProjectile::SetProjectileInfo(const CProjectileActivate *info), thiscall, ret 4. Copies +4 to +0x61, +0 to
// +0x5d, +8 / 100 to +0x51 and +0xc to +0x59; bytes +0x10 and +0x11 set or clear flags 0x10 (ballistic) and 0x20 in
// +0x89. A non-zero target at +0x12 goes to SetTarget, then the spread at +0x1e to SetPrecision.
static void THISCALL setProjectileInfo(u8 *self, const u8 *info) {
  *(u32 *)(self + 0x61) = *(const u32 *)(info + 4);
  *(u32 *)(self + 0x5d) = *(const u32 *)info;
  *(float *)(self + 0x51) = *(const float *)(info + 8) * bitsf(0x3c23d70au);
  *(u32 *)(self + 0x59) = *(const u32 *)(info + 0xc);
  if (info[0x10])
    *(u32 *)(self + 0x89) |= 0x10;
  else
    *(u32 *)(self + 0x89) &= ~0x10u;
  if (info[0x11])
    *(u32 *)(self + 0x89) |= 0x20;
  else
    *(u32 *)(self + 0x89) &= ~0x20u;
  const float *t = (const float *)(info + 0x12);
  if (!(t[0] == 0.0f && t[1] == 0.0f && t[2] == 0.0f))
    ext_4ba620(self, t);
  ext_4ba470(self, *(const float *)(info + 0x1e));
}
PCREG(4ba570, setProjectileInfo);

// 0x4b94f0 ZProjectile::Command(unsigned short cmd, void *data), thiscall, ret 8, eax = 1. The activate command (+0x95)
// resets the projectile, applies the CProjectileActivate data and calls its own slot 0x3c.
static u32 THISCALL command(u8 *self, u32 cmd, void *data) {
  if ((u16)cmd == *(u16 *)(self + 0x95)) {
    ext_4ba310(self);
    ext_4ba570(self, (const u8 *)data);
    ((vcallV0)VT(self, 0x3c))(self);
  }
  return 1;
}
PCREG(4b94f0, command);
