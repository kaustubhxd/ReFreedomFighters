// batch102.cpp - picking the sewer lid the hero climbs out of (climb thread, batch 102).
// Engine objects (from the GC names): g_pSysInterface (0x70039c) +0x9b = ZEngineDataBase* (unaligned, PC 1-byte packing);
// its slot 0x58 = GeomRefToPtr(ref), slot 0x138 = GetSceneCom(); the scene com's slot 0x88 looks a name up into a ref;
// 0x70038c is an object whose slot 0xcc turns that ref into the event object; 0x7003b8 = the game data
// (ZFFGameData), whose sewer list is a count at +0xc69 and 9-byte SSewer records at +0xc6d (+4 = the lid geom ref).
#include "ff.h"

extern "C" void THISCALL ext_5b15d0(void *ctl, const char *name, s32 *lid, float *pos, float *mat);  // GetSewerInfo
extern "C" s32 STDCALL ext_59b350(void *geom);                     // ZFFLevelController::GetSewerId, original code
extern "C" void THISCALL ext_5c3a90(void *self, u8 *sewer);        // COpenSewer::OpenLid, original code
extern "C" void THISCALL ext_4db2c0(void *geom, float *mat, float *pos);  // ZBaseGeom::GetMatPos, original code
extern "C" void FASTCALL ext_43e960(float *v, const float *b);     // v -= b (x87), original code

static inline u8 *engineDb() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x59b350, ZFFLevelController::GetSewerId(ZGEOM*) (GC map medium). this (ECX) is not used; one stack arg, ret 4.
// Null geom: -2. Otherwise the name is +4 of geom->slot 0x20()->slot 0x20() ("<NONAME>" when null), and the id is the
// last two characters read as signed bytes: name[len-2] * 10 + name[len-1] - 0x210 (that is two decimal digits minus
// '0' * 11). Short names read bytes before the string, as the exe does.
static s32 STDCALL getSewerId(void *geom) {
  if (!geom)
    return -2;
  void *a = vcall<void *>(geom, 0x20);
  u8 *b = vcall<u8 *>(a, 0x20);
  const char *name = *(const char **)(b + 4);
  if (!name)
    name = (const char *)0x67c8e8;   // "<NONAME>"
  const char *p = name;
  while (*p++) {
  }
  const char *end = name + (p - (name + 1));
  return (s32)(s8)end[-2] * 10 + (s32)(s8)end[-1] - 0x210;
}
PCREG(59b350, getSewerId);

// 0x5c3a90, COpenSewer::OpenLid(ZFFGameData::SSewer*) (GC name via the GetStartingSewerLid call site; PC unnamed).
// thiscall, this unused, one stack arg, ret 4. If sewer is non-null: geom = GeomRefToPtr(sewer+4); if found, look up the
// message id of "FrameCurrent" through engine slot 0x114 (RegisterZMsg(name, 0, file OpenSewer.cpp, line 0x43, 0x3e8, 0):
// six arguments, returns a 16-bit id) and send it to the geom: slot 0x128(id), one argument. Then sewer+8 = 1 (lid marked open).
static void THISCALL openLid(void *self, u8 *sewer) {
  (void)self;
  if (!sewer)
    return;
  void *geom = vcall<void *>(engineDb(), 0x58, *(u32 *)(sewer + 4));
  if (geom) {
    // RegisterZMsg takes four arguments (ret 0x10). The exe pushes two more values first (0x3e8, 0); they stay on the stack and
    // become the second and third arguments of slot 0x128 (ret 0xc on the geom classes), so they are passed on here.
    u16 id = vcall<u16>(engineDb(), 0x114, (const char *)0x68fee8, 0u, (const char *)0x6b3e68, 0x43u);
    vcall<void>(geom, 0x128, (u32)id, 0x3e8u, 0u);
  }
  sewer[8] = 1;
}
PCREG(5c3a90, openLid);

// 0x59b3c0, ZFFLevelController::GetStartingSewerLid() (GC map high). thiscall, no args, returns the lid geom (EAX).
//  1. byte +0x103f set: returns 0. A cached lid at +0x1050 is returned as is.
//  2. GetSewerInfo on the sewer table at +0xedb with the level name at +0x48: lid id into +0x1048, position and matrix
//     into locals.
//  3. Looks up "SewerController" (scene com slot 0x88, then 0x70038c slot 0xcc: the COpenSewer event) and the hero's
//     ground geom "HitmanGround" (scene com slot 0x88, then GeomRefToPtr).
//  4. Lid -2 or -3: returns +0x1050 unchanged.
//  5. Lid >= 0 or below -3 (any other value): moves the hero ground to the lid (ground->slot 0x20()->slot 0x74(mat,
//     pos)), then walks the game data's sewer list; each entry's geom goes into +0x1050 and the first whose GetSewerId
//     equals the lid is opened (OpenLid). +0x1050 keeps the last geom looked at, matched or not.
//  6. Lid -1 (unknown): takes the hero ground position (GetMatPos of ground->slot 0x20()'s +8 geom) and opens the
//     nearest lid: distance = sqrt of the float sum of squares (CRT sqrt as double, rounded to float); the first entry
//     always wins, a later one only when strictly nearer (comiss, so a NaN distance never replaces). Each entry's geom
//     passes through +0x1050 on the way; at the end +0x1050 = the winner's geom.
static void *getHelper(const char *name) {
  void *sc = vcall<void *>(engineDb(), 0x138);
  u32 ref = 0;
  vcall<void>(sc, 0x88, name, &ref);
  return (void *)ref;
}

static void *THISCALL getStartingSewerLid(u8 *self) {
  if (self[0x103f])
    return 0;
  if (*(void **)(self + 0x1050))
    return *(void **)(self + 0x1050);
  u8 *gd = G(u8 *, 0x7003b8);
  float pos[3], mat[9];
  s32 *lid = (s32 *)(self + 0x1048);
  ext_5b15d0(self + 0xedb, (const char *)(self + 0x48), lid, pos, mat);
  u32 ctlRef = (u32)getHelper((const char *)0x6adca0);   // "SewerController"
  void *ctl = vcall<void *>(G(void *, 0x70038c), 0xcc, ctlRef);
  u32 groundRef = (u32)getHelper((const char *)0x681320);  // "HitmanGround"
  void *ground = vcall<void *>(engineDb(), 0x58, groundRef);
  s32 l = *lid;
  if (l == -2 || l == -3)
    return *(void **)(self + 0x1050);
  if (l != -1) {
    void *g = vcall<void *>(ground, 0x20);
    vcall<void>(g, 0x74, mat, pos);
    for (u8 *s = gd + 0xc6d; s != gd + 0xc6d + 9 * *(s32 *)(gd + 0xc69); s += 9) {
      void *lg = vcall<void *>(engineDb(), 0x58, *(u32 *)(s + 4));
      *(void **)(self + 0x1050) = lg;
      if (*(s32 *)(self + 0x1048) == ext_59b350(lg)) {
        ext_5c3a90(ctl, s);
        break;
      }
    }
    return *(void **)(self + 0x1050);
  }
  bool first = true;
  u8 *best = 0;
  float bestD = 0.0f;
  void *g = vcall<void *>(ground, 0x20);
  ext_4db2c0(*(void **)((u8 *)g + 8), mat, pos);
  for (u8 *s = gd + 0xc6d; s != gd + 0xc6d + 9 * *(s32 *)(gd + 0xc69); s += 9) {
    float v[3] = {0.0f, 0.0f, 0.0f};
    void *lg = vcall<void *>(engineDb(), 0x58, *(u32 *)(s + 4));
    *(void **)(self + 0x1050) = lg;
    vcall<void>(lg, 0x84, v);
    ext_43e960(v, pos);
    float d2 = v[1] * v[1] + v[0] * v[0];
    d2 = d2 + v[2] * v[2];
    float d = (float)crt::sqrt((double)d2);
    if (first) {
      bestD = d;
      best = s;
      first = false;
    } else if (bestD > d) {
      bestD = d;
      best = s;
    }
  }
  if (best) {
    ext_5c3a90(ctl, best);
    *(void **)(self + 0x1050) = vcall<void *>(engineDb(), 0x58, *(u32 *)(best + 4));
  }
  return *(void **)(self + 0x1050);
}
PCREG(59b3c0, getStartingSewerLid);
