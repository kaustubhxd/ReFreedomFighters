// batch609.cpp - damage thread, batch 609: ZFFActor::OnDamageInfo (every damage to a soldier ends here).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
#define ENGINE G(u8 *, 0x70039c)

#pragma pack(push, 1)
struct SIKBoneCollision { u8 zone; u8 front; };
struct SDamageInfo { u32 attacker, useZoneMult, type, weapon; float pos[3], dir[3]; float damage; };
// SE_ProjectileHit payload posted to the script (11 dwords).
struct SProjectileHitMsg { float pos[3], dir[3]; s32 damage; u32 attacker, anim, type, limb; };
#pragma pack(pop)

typedef void (*AssertHook)(void);
extern "C" void THISCALL ext_466c10(void *self, const float *pos, const float *dir, float force);  // ZIKLNKOBJ::HitRagdoll
extern "C" float THISCALL ext_474250(void *self, u32 zone);                     // GetDamageMultForBone
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" u32 THISCALL ext_59fd30(void *self, SIKBoneCollision *c);            // GetHitAimHeaderFromCollision
extern "C" u8 THISCALL ext_5a0ad0(void *self);                                  // ZFFActor::IsDead
extern "C" void THISCALL ext_466ce0(void *self);                                // ZIKLNKOBJ::KillAllSounds
extern "C" void THISCALL ext_59a5e0(void *osd, u32 snd);                        // ZGameOSD::PlaySound

typedef void *(THISCALL *vP0)(void *self);
typedef void *(THISCALL *vPU)(void *self, u32 a);
typedef u8 (THISCALL *vB2)(void *self, u32 a, u32 b);
typedef void *(THISCALL *vLog)(void *self, const char *file, u32 line);
typedef void (*vMsg)(void *self, const char *msg);
typedef u32 (THISCALL *vBone)(void *self, u32 id);
typedef void (THISCALL *vMatPos)(void *self, u32 bone, float *mat, float *pos);
typedef void (THISCALL *vMP)(void *self, float *mat, float *pos);
typedef void (THISCALL *vSpawn)(void *self, void *room, float *mat, float *pos, u32, u32, u32, u32);
typedef void *(THISCALL *vColl)(void *self, SIKBoneCollision *out, const float *pos, const float *dir);
typedef u8 (THISCALL *vCanPlay)(void *self, u32 hdr, float a, float b, float *mat, float *pos, float c, float d);
typedef void (THISCALL *vPost)(void *self, u32 msg, void *data, u32 z);
typedef s32 (THISCALL *vI0)(void *self);
typedef float (THISCALL *vRand)(void *self, const char *file, u32 line);
typedef void (THISCALL *vU)(void *self, u32 a);

static const char *const kFile = (const char *)0x6ae6a0;  // "..\\..\\freedomfighter\\FFBackground\\ZFFActor.cpp"
static inline u8 *rm() { return *(u8 **)(ENGINE + 0x9b); }

// One try of the close-combat clip: CanPlayAnimSegment-like test (slot 0x37c) over the clip's frame range (+0x60,
// +0x64) at the pose createmat(dir) gives, with offsets 50 and -130. Returns the header when it can play, else 0.
static u32 ccClip(u8 *self, SDamageInfo *info, float *mat, float *pos) {
  u32 hdr = (u32)((vPU)VT(self, 0x21c))(self, 0x6ace70);  // GetAnim("CC_Hit_Head_Front_01")
  ((vMP)VT(self, 0x57c))(self, mat, pos);
  ext_4de040(mat, info->dir, 0);
  ((vMP)VT(self, 0x370))(self, mat, pos);
  ((vMP)VT(self, 0x57c))(self, mat, pos);
  if (!hdr) return 0;
  u8 *h = (u8 *)hdr;
  if (((vCanPlay)VT(self, 0x37c))(self, hdr, (float)*(s32 *)(h + 0x60), (float)*(s32 *)(h + 0x64), mat, pos, 50.0f,
                                  -130.0f))
    return hdr;
  return 0;
}

// 0x5a1030 ZFFActor::OnDamageInfo(const SDamageInfo*) (GC 800709b4). Walk-through in docs/20-damage.md.
static void THISCALL actorOnDamageInfo(u8 *self, SDamageInfo *info) {
  if (G(float, 0x7142ec) != 0.0f || G(float, 0x7142ec) != G(float, 0x7142ec)) return;  // No_Damage
  if (!(G(float, 0x7142f0) == 0.0f) && *(u32 *)(*(u8 **)(self + 0x54) + 4) == 0) return;  // No_DamageFriendly
  if (*(s16 *)(self + 0x7a0) == 0 && !((vP0)VT(self, 0x588))(self) && ((vB2)VT(self, 0x354))(self, 1, 1)) {
    float force = info->type == 5 ? 0.6f : (info->type == 4 ? 4.0f : 0.2f);
    ext_466c10(self, info->pos, info->dir, force);
  }
  if (!((vPU)VT(rm(), 0x58))(rm(), info->attacker)) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *o = (u8 *)((vLog)VT(lg, 0x20))(lg, kFile, 0x77c);
    ((vMsg)VT(o, 0x30))(o, (const char *)0x6aeb28);  // "WARNING: No damage owner. Score will not be given"
  }
  float dmg = info->damage;
  u8 flag = (u8)((*(u32 *)(self + 0x7a6) >> 2) & 1);
  u32 scratch = 0;  // the original reuses one stack slot for the effect object and the multiplied damage
  if (info->type == 1 || info->type == 2 || info->type == 3) {
    ((vU)VT(self, 0x3f4))(self, *(u32 *)(*(u8 **)(self + 0x936) + 0xc));
    if (flag) return;
    u8 *tmpl = (u8 *)((vPU)VT(rm(), 0x160))(rm(), 0xdc);
    if (tmpl) {
      u8 *fx = (u8 *)((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(tmpl + 0x18));
      scratch = (u32)fx;
      if (fx) {
        if (!(*(u32 *)(*(u8 **)(fx + 0xc) + 0x23) & 0x100000)) {
          AssertHook h = G(AssertHook, 0x7003b0);
          if (!h) __builtin_debugtrap();
          h();
        }
        u32 id = info->type == 1 ? 0x17 : (info->type == 3 ? 2 : (u32)fx);  // type 2 passes the effect pointer
        float mat[9], pos[3];
        u32 bone = ((vBone)VT(self, 0x2b4))(self, id);
        ((vMatPos)VT(self, 0x390))(self, bone, mat, pos);
        pos[2] = pos[2] - 20.0f;
        ((vMP)VT(self, 0x98))(self, mat, pos);
        u32 roomRef = (u32)((vP0)VT(self, 0x660))(self);
        u8 *room = (u8 *)((vPU)VT(rm(), 0x58))(rm(), roomRef);
        if (room) {
          ((vMP)VT(room, 0x94))(room, mat, pos);
          ((vSpawn)VT(fx, 0x1bc))(fx, room, mat, pos, 0, 0, 0, 1);
        }
      }
    }
  }
  SProjectileHitMsg m;
  m.attacker = info->attacker;
  m.type = 0;
  union { SIKBoneCollision c; u32 word; } bc;
  ((vColl)VT(self, 0x388))(self, &bc.c, info->pos, info->dir);
  if (bc.c.zone == 3 || bc.c.zone == 2) {
    u8 *a = (u8 *)((vPU)VT(rm(), 0x58))(rm(), info->attacker);
    if (a && !(u8)(u32)((vPU)VT(a, 0x1e0))(a, 0x80200014)) bc.c.zone = 1;  // only players score head zones
  }
  if (info->useZoneMult) {
    float prod = (float)((long double)ext_474250(self, bc.word) * (long double)dmg);
    scratch = fbits(prod);
    m.damage = (s32)prod;
  } else {
    m.damage = (s32)dmg;
  }
  switch (bc.c.zone) {
    case 1: m.limb = 2; break;
    case 2: m.limb = 1; break;
    case 5: m.limb = 3; break;
    case 6: m.limb = 5; break;
    case 8: m.limb = 4; break;
    case 9: m.limb = 6; break;
    default: m.limb = 0; break;
  }
  (void)scratch;
  u32 hdr = 0;
  if (info->type == 1) {
    float mat[9], pos[3];
    hdr = ccClip(self, info, mat, pos);
  } else if (info->type == 3) {
    float mat[9], pos[3];
    hdr = ccClip(self, info, mat, pos);
  }
  if (!hdr) hdr = ext_59fd30(self, &bc.c);
  m.anim = (u32)((vPU)VT(self, 0x598))(self, *(u32 *)(self + 0x91c) == 0 ? hdr : 0);
  m.pos[0] = info->pos[0]; m.pos[1] = info->pos[1]; m.pos[2] = info->pos[2];
  m.dir[0] = info->dir[0]; m.dir[1] = info->dir[1]; m.dir[2] = info->dir[2];
  m.type = info->type;
  ((vPost)VT(self, 0x128))(self, *(u16 *)0x7142dc, &m, 0);  // SE_ProjectileHit to the script
  if (((vI0)VT(self, 0x674))(self) >= 1 && ((vP0)VT(self, 0x588))(self)) {
    u8 *e = ENGINE;
    float r = ((vRand)VT(e, 0x1c0))(e, kFile, 0x830);
    if (r > 0.91f || ext_5a0ad0(info)) ((vU)VT(self, 0x6f0))(self, 1);
  } else {
    if (self[0x13a]) {
      u8 *e = ENGINE;
      float r = ((vRand)VT(e, 0x1c0))(e, kFile, 0x828);
      ((vU)VT(self, 0x6f0))(self, r > 0.5f ? 2 : 1);
    }
    ext_466ce0(self);
  }
  if (*(s32 *)(ENGINE + 0x1b5d) == 1) {
    u8 *p = *(u8 **)(self + 0x92e);
    if (p) {
      u8 *q = *(u8 **)(p + 0x852);
      if (q && !q[0xe1]) {
        q[0xe1] = 1;
        ext_59a5e0(q, 0xc);
      }
    }
  }
}
PCREG(5a1030, actorOnDamageInfo);
