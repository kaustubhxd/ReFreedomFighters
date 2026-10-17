// batch1503.cpp - recruits thread, batch 1503: hero follower list (add/remove), the script natives FollowHero,
// FreeVIPPrisoner, AddToFormation, GetFormationControlEventBase, and the script parameter accessors they use.
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

typedef void(__attribute__((cdecl)) * logPrintf)(void *log, const char *fmt, ...);
// Engine log: object at 0x700390, slot 0x20 (file, line) gives a log object whose slot 0x2c is a printf (cdecl).
static inline void *logAt(const char *file, u32 line) { return vcall<void *>(G(void *, 0x700390), 0x20, file, line); }
#define LOGF(lo, ...) ((logPrintf)(*(void ***)(lo))[0x2c / 4])(lo, __VA_ARGS__)

// ---------------------------------------------------------------- script parameters (OpaqueCallParameters_t)
// A parameter block: +0 array of 8-byte values {dword value, byte type}, +4 first index, +8 count (as read here).
typedef void(__attribute__((cdecl)) * assertHandler)();

// 0x5003d0 (unnamed; the parameter accessor), thiscall, ret 4: address of parameter i, i.e. value (first + i) of the
// value array. An index past the count (+8) calls the assert handler at 0x7003b0 (int3 when there is none) and then
// indexes the array without the first-index offset; an index past the array's own size (+8 of the array) does the
// same check again. The value array: +0 values (8 bytes each: dword value, byte type), +8 size.
static u8 *THISCALL paramAt(u32 *self, u32 i) {
  u32 *arr;
  u32 k;
  if (i >= self[2]) {
    assertHandler h = G(assertHandler, 0x7003b0);
    if (!h)
      __builtin_debugtrap();
    h();
    arr = (u32 *)self[0];
    k = i;
  } else {
    k = self[1] + i;
    arr = (u32 *)self[0];
  }
  if (k >= arr[2]) {
    assertHandler h = G(assertHandler, 0x7003b0);
    if (!h)
      __builtin_debugtrap();
    h();
  }
  return (u8 *)arr[0] + k * 8;
}
PCREG(5003d0, paramAt);

// 0x5002f0 (unnamed; set a script parameter to an integer), thiscall, ret 4, returns this. The type byte must be 0
// or 1, else the log gets the type-mismatch message (file 0x69c8e0 line 0x104) and the assert handler runs.
static u8 *THISCALL paramSetInt(u8 *self, u32 v) {
  u8 t = self[4];
  if (t != 0 && t != 1) {
    void *lo = logAt((const char *)0x69c8e0, 0x104);
    LOGF(lo, (const char *)0x69c6b0, (const char *)0x69c938);
    assertHandler h = G(assertHandler, 0x7003b0);
    if (!h)
      __builtin_debugtrap();
    h();
  }
  *(u32 *)self = v;
  self[4] = 1;
  return self;
}
PCREG(5002f0, paramSetInt);

// ---------------------------------------------------------------- ZFFHERO followers
extern "C" void THISCALL ext_5a2860(u8 *actor);            // ZFFActor::RemoveFromSquad
extern "C" void THISCALL ext_59dce0(u8 *actor, u8 *sq);    // ZFFActor::AddToSquad(SSquad*)
extern "C" char *THISCALL ext_4cc1d0(void *str);           // MYSTR -> const char*
extern "C" void THISCALL ext_4cbec0(void *str);            // MYSTR::~MYSTR

// Follower record (0x30 bytes, at hero +0xa1a, count +0xa16):
//   +0 actor, +4..+0x13 the 16-byte constant at 0x6ad240, +0x14 0, +0x18 0, +0x1c float 0 or 1 (hero flag 0x400 at
//   +0x417), +0x20..+0x2f not initialised by AddFollower (copied from the caller's stack; the port writes 0xcc bytes,
//   which is what the checker's stack fill gives; the game gets whatever was on the stack).

// 0x594460 ZFFHERO::RemoveFollower(ZFFActor*), thiscall, ret 4.
// Removes the actor's record (later records move down one), then takes the actor out of its squad. When the actor
// is not a follower, logs "not a follower" with the actor's name (+4, or the empty string 0x67c8e8).
static void THISCALL heroRemoveFollower(u8 *self, u8 *actor) {
  u32 *cnt = (u32 *)(self + 0xa16);
  u8 *p = self + 0xa1a;
  u8 *end = self + 0xa1a + *cnt * 0x30;
  for (; p != end; p += 0x30)
    if (*(u8 **)p == actor)
      break;
  if (p == end) {
    void *lo = logAt((const char *)0x6ac6d0, 0x595);
    const char *nm = *(const char **)(actor + 4);
    LOGF(lo, (const char *)0x6aca58, nm ? nm : (const char *)0x67c8e8);
    return;
  }
  s32 d = (s32)(p - (self + 0xa1a));
  u32 i = (u32)(d / 0x30);
  for (; i < *cnt - 1; ++i) {
    u8 *r = self + 0xa1a + i * 0x30;
    __builtin_memcpy(r, r + 0x30, 0x10);
    __builtin_memcpy(r + 0x10, r + 0x40, 0x10);
    __builtin_memcpy(r + 0x20, r + 0x50, 0x10);
  }
  --*cnt;
  ext_5a2860(actor);
}
PCREG(594460, heroRemoveFollower);

// 0x58b780 ZFFHERO::AddFollower(ZFFActor*), thiscall, ret 4.
// Appends a follower record (layout above; no capacity check), sends the actor the hero's "follow me" event (+0x7ea)
// with the int 0/1 when +0xee3 is set, and puts the actor in the hero's squad (+0x64f). An actor already in the
// list only logs "already a follower" with its name (actor slot 0x1d8 builds a MYSTR). The stack-cookie and SEH
// frame are not part of the port.
static void THISCALL heroAddFollower(u8 *self, u8 *actor) {
  for (u8 *p = self + 0xa1a; p != self + 0xa1a + *(u32 *)(self + 0xa16) * 0x30; p += 0x30) {
    if (*(u8 **)p == actor) {
      void *lo = logAt((const char *)0x6ac6d0, 0x577);
      u8 str[0x80];
      void *s = vcall<void *>(actor, 0x1d8, str, 1u);
      char *cs = ext_4cc1d0(s);
      LOGF(lo, (const char *)0x6aca24, cs);
      ext_4cbec0(str);
      return;
    }
  }
  u32 rec[12];
  rec[0] = (u32)actor;
  __builtin_memcpy(&rec[1], (const void *)0x6ad240, 16);
  rec[5] = 0;
  rec[6] = 0;
  float f = (*(u32 *)(self + 0x417) & 0x400u) ? 1.0f : 0.0f;
  rec[7] = fbits(f);
  for (int k = 8; k < 12; ++k)
    rec[k] = 0xccccccccu;   // indeterminate in the original (see the record note above)
  s32 fi = _mm_cvttss_si32(_mm_set_ss(f));
  u32 n = *(u32 *)(self + 0xa16);
  __builtin_memcpy(self + 0xa1a + n * 0x30, rec, 0x30);
  ++*(u32 *)(self + 0xa16);
  if (self[0xee3])
    vcall<void>(actor, 0x128, (u32) * (u16 *)(self + 0x7ea), &fi, 0u);
  ext_59dce0(actor, *(u8 **)(self + 0x64f));
}
PCREG(58b780, heroAddFollower);

// ---------------------------------------------------------------- script natives
extern "C" u8 *THISCALL ext_5003d0(void *params, u32 i);
extern "C" u8 *THISCALL ext_5002f0(void *param, u32 v);
extern "C" void THISCALL ext_58b780(u8 *hero, u8 *actor);
extern "C" void THISCALL ext_594460(u8 *hero, u8 *actor);

// Type check of a script parameter (inlined in the natives): type byte 0 or 1, else log + assert handler.
static inline void paramCheckInt(u8 *p) {
  u8 t = p[4];
  if (t == 0 || t == 1)
    return;
  void *lo = logAt((const char *)0x69c8e0, 0x104);
  LOGF(lo, (const char *)0x69c6b0, (const char *)0x69c938);
  assertHandler h = G(assertHandler, 0x7003b0);
  if (!h)
    __builtin_debugtrap();
  h();
}

// 0x5591b0 ZFFActorIf::FollowHero(OpaqueCallParameters_t&), thiscall, ret 4.
// Script: FollowHero(heroId, follow). The id must name an object of the hero class (class object from the table's
// slot 0x154 with the name at 0x6a6088, class id at +0x23, checked with IsKindOf slot 0x1e0); then the hero adds
// or removes this interface's actor (+0x1c) as a follower. A bad id gives a null hero (which faults in the callee).
static void THISCALL ifFollowHero(u8 *self, u8 *params) {
  u8 *p0 = ext_5003d0(*(void **)(params + 4), 0);
  paramCheckInt(p0);
  u32 id = *(u32 *)p0;
  u8 *p1 = ext_5003d0(*(void **)(params + 4), 1);
  paramCheckInt(p1);
  u32 follow = *(u32 *)p1;
  u8 *hero = 0;
  if (vcall<void *>(objTable(), 0x58, id)) {
    void *o = vcall<void *>(objTable(), 0x58, id);
    u8 *cls = vcall<u8 *>(objTable(), 0x154, (const char *)0x6a6088, 0u);
    if (vcall<u8>(o, 0x1e0, *(u32 *)(cls + 0x23)))
      hero = vcall<u8 *>(objTable(), 0x58, id);
  }
  if (follow)
    ext_58b780(hero, *(u8 **)(self + 0x1c));
  else
    ext_594460(hero, *(u8 **)(self + 0x1c));
}
PCREG(5591b0, ifFollowHero);

extern "C" u8 *THISCALL ext_589c20(u8 *game, u32 player);
extern "C" void THISCALL ext_596940(u8 *osd, u32 kind, float *v, u32 b, u32 n);

// 0x5592f0 ZFFActorIf::FreeVIPPrisoner(OpaqueCallParameters_t&), thiscall, ret 4.
// The actor (+0x1c) is told it is freed (slot 0x3a0 fills two buffers and returns a value passed to slot 0x390;
// both through the vtable read once), then player 0 gets charisma kind 10 shown 50 units above the actor's position
// (slot 0x20 -> geom, slot 0x84 -> position), with flag 1 and amount -1 (the kind's default).
static void THISCALL ifFreeVIPPrisoner(u8 *self, void *params) {
  (void)params;
  u8 buf[0x24];
  float pos[3];
  u8 *a = *(u8 **)(self + 0x1c);
  void **vt = *(void ***)a;
  typedef u32(THISCALL * f3a0)(void *, void *, void *);
  typedef void(THISCALL * f390)(void *, u32);
  u32 r = ((f3a0)vt[0x3a0 / 4])(a, buf, pos);
  ((f390)vt[0x390 / 4])(*(u8 **)(self + 0x1c), r);
  void *g = vcall<void *>(*(u8 **)(self + 0x1c), 0x20);
  vcall<void>(g, 0x84, pos);
  pos[1] = pos[1] + 50.0f;   // 0x680a84
  u8 *osd = ext_589c20(G(u8 *, 0x7003b8), 0);
  ext_596940(osd, 0xa, pos, 1, 0xffffffffu);
}
PCREG(5592f0, ifFreeVIPPrisoner);

// 0x553d00 CFFTools_if::GetFormationControlEventBase(), thiscall, plain ret: returns the cached formation control
// (+0xc). Looks up the level object named at 0x6a5c04 (table slot 0x138 -> name table, slot 0x88 (name, &id)),
// then the first entry of that object's list ([obj+0x10]+8, REFTAB begin/next) is turned into the formation
// control by the object manager at 0x70038c (slot 0xcc). Logs an error when the named object is missing.
static u32 THISCALL toolsGetFormationControl(u8 *self) {
  *(u32 *)(self + 0xc) = 0;
  void *names = vcall<void *>(objTable(), 0x138);
  u32 id = 0;
  vcall<void>(names, 0x88, (const char *)0x6a5c04, &id);
  u8 *o = vcall<u8 *>(objTable(), 0x58, id);
  if (!o) {
    void *lo = logAt((const char *)0x6a57fc, 0x426);
    LOGF(lo, (const char *)0x6a5c1c);
    return 0;
  }
  void *list = *(void **)(*(u8 **)(o + 0x10) + 8);
  if (list) {
    u32 it[3];
    vcall<void>(list, 0x4c, it);
    u32 x = vcall<u32>(*(void **)(*(u8 **)(o + 0x10) + 8), 0x5c, it);
    if (it[0] != 0)
      *(u32 *)(self + 0xc) = vcall<u32>(G(void *, 0x70038c), 0xcc, x);
  }
  return *(u32 *)(self + 0xc);
}
PCREG(553d00, toolsGetFormationControl);

extern "C" u32 THISCALL ext_553d00(u8 *self);

// 0x551d70 CFFTools_if::AddToFormation(OpaqueCallParameters_t&), thiscall, ret 4.
// Script: AddToFormation(a, b, c) -> result. Builds SAddToFormationParams {p0, p1, p2, 0, 0, 0} and hands it to the
// formation control's slot 0x84 (AddToFormationRef), which writes the result into the first dword; the result goes
// to return parameter 0. With no formation control: error log and result 0.
static void THISCALL toolsAddToFormation(u8 *self, u8 *params) {
  u32 prm[6];
  prm[0] = *(u32 *)ext_5003d0(*(void **)(params + 4), 0);
  prm[1] = *(u32 *)ext_5003d0(*(void **)(params + 4), 1);
  prm[2] = *(u32 *)ext_5003d0(*(void **)(params + 4), 2);
  prm[3] = 0;
  prm[4] = 0;
  prm[5] = 0;
  void *fc = *(void **)(self + 0xc);
  if (!fc) {
    ext_553d00(self);
    fc = *(void **)(self + 0xc);
    if (!fc) {
      void *lo = logAt((const char *)0x6a57fc, 0x265);
      LOGF(lo, (const char *)0x6a5894);
      ext_5002f0(ext_5003d0(*(void **)(params + 8), 0), 0);
      return;
    }
  }
  vcall<void>(fc, 0x84, prm);
  ext_5002f0(ext_5003d0(*(void **)(params + 8), 0), prm[0]);
}
PCREG(551d70, toolsAddToFormation);
