// batch267.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch267"): ZFFActor::_FireWeapon,
// how a soldier or the hero fires the weapon in a hand (guns, rocket launcher, grenades, molotovs). Name from the GameCube
// name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" const char *THISCALL ext_4cc1d0(u8 *str);   // original string c_str
extern "C" void THISCALL ext_4cbec0(u8 *str);          // original string destructor
extern "C" void THISCALL ext_4db500(u8 *geom, float *out);                      // ZBaseGeom::GetPos (inline-batch45)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                  // vmmul (inline-batch45)
extern "C" void FASTCALL ext_441940(float *v, const float *a);                  // PSVECAdd (inline-batch45)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b); // PSVECSubtract (inline-batch45)
extern "C" float FASTCALL ext_44c840(float *v);                                 // vnorm (inline-batch45)
extern "C" void FASTCALL ext_4e0d00(float *v, float s);                         // vscalar (inline-batch45)

typedef void(__attribute__((cdecl)) * logs_t)(void *, const char *, const char *);
typedef void(__attribute__((cdecl)) * log0_t)(void *, const char *);
typedef u32(THISCALL *coli_t)(u8 *, float *, u32, float *, float *, u32, u32, u32, u32);

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x5a31d0 ZFFActor::_FireWeapon(int hand, unsigned char flag) ret 8. Nothing while +0x64c is 10. The weapon is the right
// (+0x78a) or, with hand != 0, the left (+0x78e) item; none logs "WARNING: Actor %s tries to shoot but have no weapon"
// (ZFFActor.cpp 0x3a4, log slot 0x30). this->vt[0x4cc](&muzzle) (byte) must succeed.
// Weapon types 7 (range 600) and 11/12 (range 400) first test the line from the muzzle to the weapon's barrel point: the
// template's (+0x11b) base geom position, rotated (vmmul) by the weapon's matrix and moved (PSVECAdd) by its position
// (weapon vt[0x2c4](&m, &p)); dir = point - muzzle, normalised, scaled to the range (or to length - 25 when shorter);
// the collision object ([render manager +0x1aa3]+0x1c)->vt[0x30](&hit{1.0}, 0, &point, &dir, 1, 2, 1, 0) (byte) blocks
// the shot when true.
// Then weapon->vt[0x32c](&muzzle). A template that needs ammo (vt[0x328]) with an empty magazine (vt[0x35c] == 0) asks for
// a reload (this->vt[0x4ec](weapon)), one that cannot fire now (vt[0x354] false) this->vt[0x4f0](weapon), both only when
// no action is running (vt[0x3f0] == 0). Otherwise +0x79e = flag; types other than 11/12 fire (weapon vt[0x2d0](0, 0)
// and vt[0x2d0](3, 0)); grenades/molotovs (11, 12) set +0x79e = 1 and, with no action running, start the throw animation
// of the hand holding them (vt[0x3d8](vt[0x3ec](0x13 right / 0x12 left))), or log "Trying to throw grenade/molotov not in
// any hand" (0x3ee).
static void THISCALL fireWeapon_5a31d0(u8 *self, u32 hand, u8 flag) {
  if (*(u32 *)(self + 0x64c) == 10) return;
  u32 id = hand ? *(u32 *)(self + 0x78e) : *(u32 *)(self + 0x78a);
  if (!id) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x6ae6a0u, 0x3a4u);
    u8 str[0x80];
    u8 *sp = (u8 *)vcall<u32>(self, 0x1d8, (u32)str, 1u);
    (*(logs_t *)(*(u8 **)log + 0x30))(log, (const char *)0x6aea0cu, ext_4cc1d0(sp));
    ext_4cbec0(str);
    return;
  }
  u8 *w = (u8 *)vcall<u32>(DB, 0x58, id);
  float muzzle[3];
  if (!(u8)vcall<u32>(self, 0x4cc, (u32)muzzle)) return;
  u32 k = vcall<u32>((u8 *)vcall<u32>(w, 0x350), 0x330);
  if (k == 7 || k == 0xb || k == 0xc) {
    float range = k == 7 ? *(float *)0x6a60acu : *(float *)0x694d10u;
    float m[9], p[3];
    vcall<void>(w, 0x2c4, (u32)m, (u32)p);
    u8 *b = *(u8 **)((u8 *)vcall<u32>(w, 0x350) + 0x11b);
    if (b) {
      float pt[3], dir[3];
      ext_4db500(*(u8 **)(b + 8), pt);
      ext_4419f0(pt, m);
      ext_441940(pt, p);
      ext_43e920(dir, muzzle, pt);
      float L = ext_44c840(dir);
      float s = range;
      if (!(L > range)) s = L - *(float *)0x685270u;
      ext_4e0d00(dir, s);
      u8 *coli = *(u8 **)(*(u8 **)(*(u8 **)0x70039cu + 0x1aa3) + 0x1c);
      float hit[0x24];
      hit[0] = 1.0f;
      if ((u8)(*(coli_t *)(*(u8 **)coli + 0x30))(coli, hit, 0u, pt, dir, 1u, 2u, 1u, 0u)) return;
    }
  }
  vcall<void>(w, 0x32c, (u32)muzzle);
  if ((u8)vcall<u32>((u8 *)vcall<u32>(w, 0x350), 0x328)) {
    if (!vcall<u32>(w, 0x35c)) {
      if (!vcall<u32>(self, 0x3f0)) vcall<void>(self, 0x4ec, (u32)w);
      return;
    }
    if (!(u8)vcall<u32>(w, 0x354)) {
      if (!vcall<u32>(self, 0x3f0)) vcall<void>(self, 0x4f0, (u32)w);
      return;
    }
  }
  self[0x79e] = flag;
  if (vcall<u32>((u8 *)vcall<u32>(w, 0x350), 0x330) != 0xb && vcall<u32>((u8 *)vcall<u32>(w, 0x350), 0x330) != 0xc) {
    vcall<void>(w, 0x2d0, 0u, 0u);
    vcall<void>(w, 0x2d0, 3u, 0u);
    return;
  }
  self[0x79e] = 1;
  if (vcall<u32>(self, 0x3f0)) return;
  if (w == (u8 *)vcall<u32>(self, 0x504)) {
    vcall<void>(self, 0x3d8, vcall<u32>(self, 0x3ec, 0x13u));
    return;
  }
  if (w == (u8 *)vcall<u32>(self, 0x500)) {
    vcall<void>(self, 0x3d8, vcall<u32>(self, 0x3ec, 0x12u));
    return;
  }
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x6ae6a0u, 0x3eeu);
  (*(log0_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6aea40u);
}
PCREG(5a31d0, fireWeapon_5a31d0);
#undef DB
