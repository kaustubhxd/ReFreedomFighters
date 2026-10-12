// batch605.cpp - damage thread, batch 605: ZFFHERO::OnDamageInfo (explosions, fire, close combat on the Hero).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
#define ENGINE G(u8 *, 0x70039c)

#pragma pack(push, 1)
struct SIKBoneCollision { u8 zone; u8 front; };
struct SDamageInfo { u32 attacker, useZoneMult, type, weapon; float pos[3], dir[3]; float damage; };
#pragma pack(pop)

typedef void (*AssertHook)(void);
extern "C" void THISCALL ext_466f60(void *self, u32 snd);                         // ZIKLNKOBJ::PlaySound
extern "C" u8 *THISCALL ext_4db3b0(void *baseGeom);                               // ZBaseGeom::GetOwnerRoom
extern "C" float THISCALL ext_474250(void *self, u32 zone);                       // GetDamageMultForBone
extern "C" float THISCALL ext_58b9c0(void *self, float d, u32 owner, u32 force);  // ZFFHERO::AdjustHitPoints

typedef void *(THISCALL *vPU)(void *self, u32 a);
typedef u32 (THISCALL *vBone)(void *self, u32 id);
typedef void (THISCALL *vMatPos)(void *self, u32 bone, float *mat, float *pos);
typedef void (THISCALL *vMP)(void *self, float *mat, float *pos);
typedef void (THISCALL *vSpawn)(void *self, void *room, float *mat, float *pos, u32, u32, u32, u32);
typedef void *(THISCALL *vColl)(void *self, SIKBoneCollision *out, const float *pos, const float *dir);
typedef const char *(THISCALL *vAnimName)(void *self, SIKBoneCollision *zr, u32 a, u32 b);
typedef void (THISCALL *vSetName)(void *self, const char *name);
typedef void *(THISCALL *vGetAnim)(void *self, const char *name);
typedef void (THISCALL *vActivate)(void *self, void *hdr, u32 a);
typedef void (THISCALL *vDie)(void *self, const float *pos, const float *dir, float dmg);
typedef float (THISCALL *vRand)(void *self, const char *file, u32 line);

static inline u8 *rm() { return *(u8 **)(ENGINE + 0x9b); }

// 0x593220 ZFFHERO::OnDamageInfo(SDamageInfo*) (GC 8007e68c).
static void THISCALL heroOnDamageInfo(u8 *self, SDamageInfo *info) {
  u8 *att = (u8 *)((vPU)VT(rm(), 0x58))(rm(), info->attacker);
  if (att && att != self && (u8)(u32)((vPU)VT(att, 0x1e0))(att, 0x200006) &&
      *(u32 *)(*(u8 **)(att + 0x54) + 4) == *(u32 *)(*(u8 **)(self + 0x54) + 4))
    return;  // a team-mate's explosion or blow does nothing
  float dmg = info->damage;
  u8 cc = 0;
  if (info->type == 1 || info->type == 2 || info->type == 3) {
    cc = 1;
    ext_466f60(self, *(u32 *)(self + 0xf16));
    u8 *tmpl = (u8 *)((vPU)VT(rm(), 0x160))(rm(), 0xdc);
    if (tmpl) {
      u8 *fx = (u8 *)((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(tmpl + 0x18));
      if (fx) {
        if (!(*(u32 *)(*(u8 **)(fx + 0xc) + 0x23) & 0x100000)) {
          AssertHook h = G(AssertHook, 0x7003b0);
          if (!h) __builtin_debugtrap();
          h();
        }
        // bone id: type 1 -> 0x17, type 3 -> 2; type 2 reads an uninitialised stack slot in the original (0 here)
        u32 id = info->type == 1 ? 0x17 : (info->type == 3 ? 2 : 0);
        float mat[9], pos[3];
        u32 bone = ((vBone)VT(self, 0x2b4))(self, id);
        ((vMatPos)VT(self, 0x390))(self, bone, mat, pos);
        pos[2] = pos[2] - 20.0f;  // 0x67da20
        ((vMP)VT(self, 0x98))(self, mat, pos);
        u8 *room = ext_4db3b0(*(u8 **)(self + 8));
        if (room) {
          ((vMP)VT(room, 0x94))(room, mat, pos);
          ((vSpawn)VT(fx, 0x1bc))(fx, room, mat, pos, 0, 0, 0, 1);
        }
      }
    }
  }
  union { SIKBoneCollision c; u32 word; } zr;
  ((vColl)VT(self, 0x388))(self, &zr.c, info->pos, info->dir);
  float mult = info->useZoneMult ? ext_474250(self, zr.word) : 1.0f;
  if (zr.c.zone == 2 && att && *(u32 *)(*(u8 **)(att + 0xc) + 0x23) == 0x2003e8 &&
      *(s32 *)(ENGINE + 0x1b5d) != 1)
    mult = 10.0f;  // 0x680a70: head hit by a Hero outside multiplayer
  float v = mult * dmg;
  u32 vb = fbits(v);
  asm("" : "+r"(vb));  // keep the sign flip after the multiply (NaN sign), see batch604
  float hp = ext_58b9c0(self, bitsf(vb ^ 0x80000000u), info->attacker, 0);
  bool alive = hp > 0.0f;
  bool zeroDmg = dmg == 0.0f;  // ucomiss: an exact 0 (or -0) damage goes to the Die call too
  if (!alive || zeroDmg) {
    ((vDie)VT(self, 0x5bc))(self, info->pos, info->dir, dmg);
    return;
  }
  const char *anim;
  if (cc) {
    *(u32 *)(self + 0x9e3) = 0;
    anim = (const char *)0x6ace70;  // "CC_Hit_Head_Front_01"
  } else {
    if (G(float, 0x6ffa60) == 0.0f) {
      u8 *e = ENGINE;
      float r = ((vRand)VT(e, 0x1c0))(e, (const char *)0x6ac6d0, 0xae1);
      if (r > 0.5f) ext_466f60(self, *(u32 *)(self + (info->weapon == 1 ? 0xefe : 0xefa)));
    }
    anim = ((vAnimName)VT(self, 0x5d4))(self, &zr.c, 0, 0);
  }
  ((vSetName)VT(self, 0x4d8))(self, anim);
  if (!*(u32 *)(self + 0x1e6)) return;
  s32 *last = (s32 *)(self + 0x694), *now = (s32 *)(ENGINE + 0x40);
  if (!(*now > *last + 0x200)) return;
  if (last != now) *last = *now;
  void *hdr = ((vGetAnim)VT(self, 0x21c))(self, *(const char **)(self + 0x1e6));
  if (!hdr) return;
  if (cc && self[0x9f4]) ((vActivate)VT(self, 0x230))(self, hdr, 1);
  self[0x831] = 1;
}
PCREG(593220, heroOnDamageInfo);
