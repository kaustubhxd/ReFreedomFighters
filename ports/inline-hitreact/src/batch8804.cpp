// batch8804.cpp - hit-reaction thread, batch 8804: ZProjectile::ShotImpact, where a round that hit something tells the hit
// object (the "ProjectileHit" message with an SHitInfo), spawns the impact sound, decal and effects, and the explosion message.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" u8 *THISCALL ext_4ba180(void *self, u32 idx);                 // ZProjectile::GetMaterialDesc
extern "C" u8 *THISCALL ext_4db3b0(void *geom);                          // ZBaseGeom::GetOwnerRoom
extern "C" const char *THISCALL ext_4cc1d0(void *mystr);                 // MYSTR c_str
extern "C" void THISCALL ext_4cbec0(void *mystr);                        // MYSTR::~MYSTR
extern "C" u32 THISCALL ext_43ebb0(void *room, float *n, float *p, u32 snd, u32 a, u32 b, u32 owner, u32 hit);  // sound placement (7 args)
extern "C" void THISCALL ext_45bab0(void *decal, void *coli, u32 a, float b);   // decal on the hit (3 args)
extern "C" void THISCALL ext_45bfd0(void *coli, float *n);              // COLI hit-triangle normal
extern "C" void FASTCALL ext_4de040(float *m, const float *p, const float *q);  // createmat
extern "C" void FASTCALL ext_4e09b0(float *v);                          // vneg in place
extern "C" void FASTCALL ext_4e09e0(float *d, const float *s);          // d = -s
extern "C" void THISCALL ext_4e1b60(void *coli);                        // COLI::COLI
extern "C" void THISCALL ext_4e0d80(float *v, float len);               // vsetlen
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b

typedef u8 *(THISCALL *vPU)(void *self, u32 a);
typedef u32 (THISCALL *vHandle)(void *self, u32 a);
typedef u8 *(THISCALL *vPP)(void *self, void *a);
typedef u8 *(THISCALL *vP0)(void *self);
typedef u8 (THISCALL *vBU)(void *self, u32 a);
typedef u8 (THISCALL *vBPU)(void *self, void *a, u32 b);
typedef void (THISCALL *vVP)(void *self, void *a);
typedef void (THISCALL *vVPP)(void *self, void *a, void *b);
typedef u32 (THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32 (THISCALL *vUP)(void *self, const char *a);
typedef void (THISCALL *vSpawn)(void *self, void *room, float *m, float *p, u32, u32, u32, u32);
typedef void (THISCALL *vSend)(void *self, void *to, u32 msg, void *data);
typedef void (THISCALL *vCmd)(void *self, u32 msg, void *data, u32 z);
typedef u32 (THISCALL *vReg)(void *self, const char *name, u32 a, const char *file, u32 line);
typedef float (THISCALL *vRand)(void *self, const char *file, u32 line);
typedef u8 *(THISCALL *vLog)(void *self, const char *file, u32 line);
typedef u8 *(THISCALL *vName)(void *self, void *out, u32 full);
typedef void (*vPrintf)(void *self, const char *fmt, const char *s);

static const char *const FILE_PROJ = (const char *)0x692ab4;  // '..\\..\\code\\engine\\eventsbase\\zprojectile.cpp'
static inline u8 *eng() { return G(u8 *, 0x70039c); }
static inline u8 *rmgr() { return *(u8 **)(eng() + 0x9b); }

// SHitInfo as ShotImpact builds it (0x18 bytes on the stack).
#pragma pack(push, 1)
struct SHitInfo { u8 *coli; u32 ownerHandle; u32 weapon; u32 shooter; u32 tmplHandle; float dist; };
#pragma pack(pop)

// 0x4ba7f0 ZProjectile::ShotImpact(COLI*) (GC 802dfe08). this = the projectile; coli = its hit (+0x28 hit point, +0xc ray,
// +0x3c the surface id, +0x44 the hit object handle).
//  1. hit object = render manager slot 0x58(coli +0x44); none -> return.
//  2. material: [0x70039c]+0x1aa3 -> +0x1c slot 0x74(&coli+0x3c) -> +0x18 slot 0xf8 -> record; GetMaterialDesc(record byte +2);
//     a desc whose class (+0xc -> +0x23) is not 0x2000f0 -> "Error: %s is not a ZMaterialDesc" and return.
//  3. room = GetOwnerRoom(hit object +8) (assert when none).
//  4. impact sound when the sound manager [0x70039c]+0x1a9f and the projectile's sound (+0x91) exist: point = coli hit point to
//     room space (room slot 0x8c), normal (0, 0, 1), sound set = desc +0x28 (or "default" when the manager has none of it),
//     0x43ebb0(...) -> sound object (rm slot 0x60): pitch (random - 0.5) * 100 as an int into +0x64 (+0x60 = the change,
//     +0x40 |= 0x10).
//  5. decal (desc +0x20) when the hit geom's +0x5a is set: 0x45bab0(coli, desc +0x38, desc +0x30).
//  6. impact effect (desc +0x18) unless the hit object is an actor class 0x200006 (engine +0x68 == 0): frame from the hit
//     triangle's normal (to world by the object's slot 0x88), rows 0 and 1 swapped, row 0 negated, placed at the hit point.
//  7. exit effect (desc +0x1c): a line 100 long back along the ray from the hit point, tested against the object (slot 0x178);
//     on a hit the effect is placed there, facing back along the ray.
//  8. unless +0x89 bit 4: SHitInfo {coli, rm slot 0x4c(projectile +0x44), weapon +0x61 (0 when it no longer resolves),
//     shooter +0x5d, rm slot 0x4c(weapon slot 0x2e8), distance +0x55} sent with the "ProjectileHit" id (+0x99) by the
//     projectile's geom (+0x44) slot 0x130 to the hit object; the shooter gets message +0x9b with the COLI (slot 0x128).
//  9. unless +0x89 bit 4: "EXPLODE_Explode_Impact" registered (rm slot 0x114) and sent by the projectile's geom with
//     {hit point, 0,0,0, 0,0,0, shooter}.
static void THISCALL shotImpact(u8 *self, u8 *coli) {
  u8 *hit = ((vPU)VT(rmgr(), 0x58))(rmgr(), *(u32 *)(coli + 0x44));
  if (!hit) return;
  u8 *sm = *(u8 **)(eng() + 0x1aa3);
  void *o1c = *(void **)(sm + 0x1c);
  u32 sid = (u32)((vPP)VT(o1c, 0x74))(o1c, coli + 0x3c);
  sm = *(u8 **)(eng() + 0x1aa3);
  void *o18 = *(void **)(sm + 0x18);
  u8 *mrec = ((vPU)VT(o18, 0xf8))(o18, sid);
  u8 *md = 0;
  if (mrec) {
    md = ext_4ba180(self, mrec[2]);
    if (md && *(u32 *)(*(u8 **)(md + 0xc) + 0x23) != 0x2000f0) {
      void *lg = G(void *, 0x700390);
      u8 *out = ((vLog)VT(lg, 0x20))(lg, FILE_PROJ, 0xcf);
      u8 name[0x100];
      u8 *ms = ((vName)VT(md, 0x1d8))(md, name, 1);
      vPrintf pf = (vPrintf)VT(out, 0x2c);
      pf(out, (const char *)0x692b10, ext_4cc1d0(ms));   // 'Error: %s is not a ZMaterialDesc'
      ext_4cbec0(name);
      return;
    }
  }
  u8 *room = ext_4db3b0(*(void **)(hit + 8));
  if (!room) {
    typedef void (*AssertHook)();
    AssertHook h = G(AssertHook, 0x7003b0);
    if (!h) __builtin_trap();
    h();
  }
  if (*(u32 *)(eng() + 0x1a9f) && *(u32 *)(self + 0x91)) {
    float p[3], n[3];
    p[0] = *(float *)(coli + 0x28);
    p[1] = *(float *)(coli + 0x2c);
    p[2] = *(float *)(coli + 0x30);
    u32 set = 0;
    ((vVP)VT(room, 0x8c))(room, p);
    n[0] = 0.0f; n[1] = 0.0f; n[2] = 1.0f;
    if (md) set = *(u32 *)(md + 0x28);
    u8 *snd = *(u8 **)(eng() + 0x1a9f);
    u32 r = ((vUUU)VT(snd, 0x58))(snd, *(u32 *)(self + 0x91), set);
    u32 x;
    if (r) {
      x = set;
    } else {
      snd = *(u8 **)(eng() + 0x1a9f);
      x = ((vUP)VT(snd, 0x5c))(snd, (const char *)0x685ffc);   // 'default'
    }
    u32 so = ext_43ebb0(room, n, p, x, *(u32 *)(self + 0x91), 6, *(u32 *)(self + 0x5d), *(u32 *)(coli + 0x44));
    u8 *o = ((vPU)VT(rmgr(), 0x60))(rmgr(), so);
    if (o) {
      u8 *e = eng();
      long double rv = ((vRand)VT(e, 0x1c0))(e, FILE_PROJ, 0xe6);
      float f = (float)((rv - (long double)G(float, 0x67a6ac)) * (long double)G(float, 0x67cd40));
      s32 i = _mm_cvttss_si32(_mm_set_ss(f));
      *(u32 *)(o + 0x40) |= 0x10;
      *(s32 *)(o + 0x60) = i - *(s32 *)(o + 0x64);
      *(s32 *)(o + 0x64) = i;
    }
  }
  if (md && *(u16 *)(*(u8 **)(hit + 8) + 0x5a)) {
    u8 *d = ((vPU)VT(rmgr(), 0x58))(rmgr(), *(u32 *)(md + 0x20));
    if (d) ext_45bab0(d, coli, *(u32 *)(md + 0x38), *(float *)(md + 0x30));
  }
  if (!(*(u8 *)(eng() + 0x68) == 0 && ((vBU)VT(hit, 0x1e0))(hit, 0x200006)) && md) {
    u8 *fx = ((vPU)VT(rmgr(), 0x58))(rmgr(), *(u32 *)(md + 0x18));
    if (fx) {
      float nrm[3], m[9], pp[3];
      ext_45bfd0(coli, nrm);
      ((vVP)VT(hit, 0x88))(hit, nrm);
      ext_4de040(m, nrm, 0);
      float a0 = m[0], a1 = m[1], a2 = m[2];
      m[0] = m[3]; m[1] = m[4]; m[2] = m[5];
      m[3] = a0; m[4] = a1; m[5] = a2;
      ext_4e09b0(m);
      pp[0] = *(float *)(coli + 0x28);
      pp[1] = *(float *)(coli + 0x2c);
      pp[2] = *(float *)(coli + 0x30);
      ((vVPP)VT(room, 0x94))(room, m, pp);
      ((vSpawn)VT(fx, 0x1bc))(fx, room, m, pp, 0, 0, 0, 1);
    }
    u8 *fx2 = ((vPU)VT(rmgr(), 0x58))(rmgr(), *(u32 *)(md + 0x1c));
    if (fx2) {
      u8 c2[0x70];
      float nrm[3], m[9], pp[3];
      ext_4e1b60(c2);
      float *dv = (float *)(c2 + 0xc);
      dv[0] = *(float *)(coli + 0xc);
      dv[1] = *(float *)(coli + 0x10);
      dv[2] = *(float *)(coli + 0x14);
      c2[0x6c] = 1;
      ext_4e0d80(dv, 100.0f);
      ext_43e8e0((float *)c2, (float *)(coli + 0x28), dv);
      ext_4e09b0(dv);
      ((vVP)VT(hit, 0x90))(hit, dv);
      ((vVP)VT(hit, 0x8c))(hit, c2);
      if (((vBPU)VT(hit, 0x178))(hit, c2, 0)) {
        ext_4e09e0(nrm, dv);
        pp[0] = *(float *)(c2 + 0x28);
        pp[1] = *(float *)(c2 + 0x2c);
        pp[2] = *(float *)(c2 + 0x30);
        ((vVP)VT(hit, 0x84))(hit, pp);
        ((vVP)VT(hit, 0x88))(hit, nrm);
        ext_4de040(m, nrm, 0);
        ((vVPP)VT(room, 0x94))(room, m, pp);
        ((vSpawn)VT(fx2, 0x1bc))(fx2, room, m, pp, 0, 0, 0, 1);
      }
    }
  }
  if (!((*(u32 *)(self + 0x89) >> 4) & 1)) {
    SHitInfo hi;
    hi.ownerHandle = ((vHandle)VT(rmgr(), 0x4c))(rmgr(), *(u32 *)(self + 0x44));
    hi.shooter = *(u32 *)(self + 0x5d);
    hi.coli = coli;
    u8 *w = ((vPU)VT(rmgr(), 0x58))(rmgr(), *(u32 *)(self + 0x61));
    if (w) {
      u8 *t = ((vP0)VT(w, 0x2e8))(w);
      hi.tmplHandle = ((vHandle)VT(rmgr(), 0x4c))(rmgr(), (u32)t);
      hi.weapon = *(u32 *)(self + 0x61);
    } else {
      hi.weapon = 0;
      hi.tmplHandle = 0;   // not written by the exe on this path (stack garbage); the port writes 0
    }
    hi.dist = *(float *)(self + 0x55);
    u8 *own = *(u8 **)(self + 0x44);
    ((vSend)VT(own, 0x130))(own, hit, *(u16 *)(self + 0x99), &hi);
    u8 *sh = ((vPU)VT(rmgr(), 0x58))(rmgr(), *(u32 *)(self + 0x5d));
    if (sh) ((vCmd)VT(sh, 0x128))(sh, *(u16 *)(self + 0x9b), coli, 0);
  }
  if (!((*(u32 *)(self + 0x89) >> 4) & 1)) {
    struct { float p[3], a[3], b[3]; u32 shooter; } ex;
    ex.p[0] = *(float *)(coli + 0x28);
    ex.shooter = *(u32 *)(self + 0x5d);
    ex.p[1] = *(float *)(coli + 0x2c);
    ex.p[2] = *(float *)(coli + 0x30);
    ex.a[0] = ex.a[1] = ex.a[2] = 0.0f;
    ex.b[0] = ex.b[1] = ex.b[2] = 0.0f;
    u8 *own = *(u8 **)(self + 0x44);
    u32 id = (u16)((vReg)VT(rmgr(), 0x114))(rmgr(), (const char *)0x692b34, 0, FILE_PROJ, 0x149);   // 'EXPLODE_Explode_Impact'
    ((vCmd)VT(own, 0x128))(own, id, &ex, 0);
  }
}
PCREG(4ba7f0, shotImpact);
