// batch1606.cpp - ZFFActor::PlaySound_Enum_On_Screen: a shout with a subtitle (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }
static inline void *dll() { return AT(void *, sys(), 0x1a9f); }

extern "C" void *ext_634d10(void *d, int v, u32 n);  // memset (CRT)
extern "C" void ext_634047();                        // ___report_rangecheckfailure (/GS, no return)
typedef void(FASTCALL *VecSubFn)(float *dst, const float *a, const float *b);  // PSVECSubtract: dst = a - b
extern "C" char ext_43e920[];
typedef void(THISCALL *ResCtorFn)(void *res, const char *key);
typedef void(THISCALL *ResSetKeyFn)(void *res, const char *key);
typedef void *(THISCALL *GetResourceFn)(void *coll, const char *key, void *res);
typedef const char *(THISCALL *GetTextFn)(void *res);
typedef void(THISCALL *MessageDialogFn)(void *osd, const char *name, const char *text, float t);
typedef void(THISCALL *AddActorActionMarkerFn)(void *osd, void *actor, u32 kind, float t);
extern "C" char ext_49e250[], ext_49e260[], ext_49df60[], ext_49e0d0[], ext_59a5b0[], ext_598e10[];

static inline u32 slen(const char *s) {
  const char *p = s;
  while (*p++) {}
  return (u32)(p - (s + 1));
}

// 0x5a1c50 ZFFActor::PlaySound_Enum_On_Screen(uchar enum, const char* speaker, bool marker) [high].
// Like PlaySound_Enum, plus a subtitle on the hero's OSD. Steps:
//  1. no Character_Controller, CanIPlay refuses, the table entry is 0 (after ExpandSoundset for enums above 38), or
//     sys+0x1b5d == 1 -> 0, nothing played.
//  2. Range: the actor must be within 350 units of the followed hero (+0x92e, no null check) vertically and
//     within 1500 units horizontally (dx^2 + dz^2 < 2.25e6), else 0, nothing played.
//  3. The shout as speech (ZIKLNKOBJ::PlaySound(sound, pitch, true)). No sound object for the handle -> returns 0.
//  4. Subtitle key from the wave's file path (DLL +0x40(sound+0x7c), +0x1dc, +0x1e8): from the second '/' on,
//     without the 4-character extension, e.g. "x/y/C01A_44_Jones.wav" -> "/C01A_44_Jones". Looked up in the
//     database's ResourceCollection (+0xae4); missing -> log "IMPORTANT: ... missing resource text [%s]".
//  5. Speaker name: "/Names/<speaker>" in the same collection ("N/A" when missing); no speaker -> null name.
//  6. ZGameOSD::MessageDialog(name, text, sound length) on the hero's OSD (hero+0x852), and with `marker` the
//     action marker (actor, 1, length). Returns the sound handle (from step 3 on).
u32 THISCALL ZFFActor_PlaySound_Enum_On_Screen(void *self, u32 e, const char *speaker, u32 marker) {
  u8 eb = (u8)e;
  void *cc = AT(void *, self, 0x93a);
  if (!cc) return 0;
  u32 ee = eb;
  if (!ZCharacterControl_CanIPlay(cc, ee, AT(u32, AT(u8 *, self, 0x54), 4))) return 0;
  if (eb > 0x26) ZFFActor_ExpandSoundset(self);
  if (!AT(u32 *, self, 0x936)[ee]) return 0;
  if (AT(u32, sys(), 0x1b5d) == 1) return 0;
  float hp[3] = {0, 0, 0}, mp[3] = {0, 0, 0}, d[3];
  vcall<void>(AT(void *, self, 0x92e), 0x84, hp);
  vcall<void>(self, 0x84, mp);
  ((VecSubFn)(void *)ext_43e920)(d, hp, mp);
  double ady = __builtin_fabs((double)d[1]);
  if (!(350.0 > ady)) return 0;  // 350.0 (double) at 0x6aef78
  if (!(2250000.0f > d[0] * d[0] + d[2] * d[2])) return 0;  // 0x6ad31c
  s32 pitch = vcall<s32>(self, 0x684);
  u32 h = ZIKLNKOBJ_PlaySound3(self, AT(u32 *, self, 0x936)[ee], pitch, 1);
  u8 *o = (u8 *)srefToPtr(h);
  if (!o) return 0;
  void *p = vcall<void *>(dll(), 0x40, AT(u32, o, 0x7c));
  if (!p) return h;
  p = vcall<void *>(dll(), 0x1dc, p);
  if (!p) return h;
  const char *path = vcall<const char *>(dll(), 0x1e8, p);
  if (!path) return h;
  char key[0x100];
  u32 n = slen(path);
  u32 i = 0;
  if (n) {
    while (path[i] != '/') {
      i++;
      if (i >= n) break;
    }
  }
  i++;
  while (i < n && path[i] != '/') i++;
  {
    const char *s = path + i;
    char *t = key;
    char ch;
    do {
      ch = *s++;
      *t++ = ch;
    } while (ch);
  }
  u32 cut = slen(key) - 4;
  if (cut >= 0x100) {
    ext_634047();
    __builtin_unreachable();
  }
  key[cut] = 0;
  void *coll = AT(void *, AT(u8 *, sys(), 0x9b), 0xae4);
  if (!coll) return h;
  u8 res[0x220];
  ((ResCtorFn)(void *)ext_49e250)(res, (const char *)0x677b5a);
  ((ResSetKeyFn)(void *)ext_49e260)(res, (const char *)0x677b5a);
  void *r = ((GetResourceFn)(void *)ext_49df60)(AT(void *, AT(u8 *, sys(), 0x9b), 0xae4), key, res);
  if (!r) {
    void *log = G(void *, 0x700390);
    void *ch = vcall<void *>(log, 0x20, (const char *)0x6ae6a0, (u32)0xaa1);  // ZFFActor.cpp, line 0xaa1
    typedef void (*Print)(void *, const char *, const char *);
    (*(Print *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6aed30, (const char *)key);
    return h;
  }
  float len = AT(float, o, 0x70);
  const char *text = ((GetTextFn)(void *)ext_49e0d0)(r);
  const char *name = 0;
  if (speaker) {
    char nk[0x100];
    ext_634d10(nk, 0, 0x100);
    char *t = nk;
    while (*t) t++;
    AT(u32, t, 0) = G(u32, 0x6aed24);  // "/Nam"
    AT(u32, t, 4) = G(u32, 0x6aed28);  // "es/\0"
    u32 sl = slen(speaker) + 1;
    char *dst = nk;
    while (*dst) dst++;
    for (u32 k = 0; k < sl; k++) dst[k] = speaker[k];
    void *nr = ((GetResourceFn)(void *)ext_49df60)(AT(void *, AT(u8 *, sys(), 0x9b), 0xae4), nk, res);
    name = nr ? ((GetTextFn)(void *)ext_49e0d0)(nr) : 0;
    if (!name) name = (const char *)0x6852b8;  // "N/A"
  }
  u8 *hero = AT(u8 *, self, 0x92e);
  if (hero) {
    ((MessageDialogFn)(void *)ext_59a5b0)(AT(void *, hero, 0x852), name, text, len);
    if ((u8)marker)
      ((AddActorActionMarkerFn)(void *)ext_598e10)(AT(void *, AT(u8 *, self, 0x92e), 0x852), self, 1, len);
  }
  return h;
}
PCREG(5a1c50, ZFFActor_PlaySound_Enum_On_Screen);
