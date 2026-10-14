// batch1507.cpp - recruits thread, batch 1507: charisma points (CharismaAddExperience), finding the next recruit,
// and small helpers.
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void(__attribute__((cdecl)) * logPrintf)(void *log, const char *fmt, ...);
static inline void *logAt(const char *file, u32 line) { return vcall<void *>(G(void *, 0x700390), 0x20, file, line); }

extern "C" u8 THISCALL ext_597a70(u8 *osd, u32 id);   // ZGameOSD::IsRecruited

// 0x597a20 (unnamed; "is my recruit"), thiscall, ret 4, AL. In multiplayer ([sys+0x1b5d] == 1) this is IsRecruited
// (tail call, any same-team player); otherwise the id is looked up in this OSD's recruit list.
static u8 THISCALL osdIsMyRecruit(u8 *self, u32 id) {
  if (*(u32 *)(G(u8 *, 0x70039c) + 0x1b5d) == 1)
    return ext_597a70(self, id);
  s32 n = *(s32 *)(self + 0x1fae);
  for (s32 i = 0; i < n; ++i)
    if (((u32 *)(self + 0x1dae))[i] == id)
      return 1;
  return 0;
}
PCREG(597a20, osdIsMyRecruit);

// 0x597b10 (unnamed; "is selected"), thiscall, ret 4, AL: the id is in the selected list (+0xe6, count +0x2e6).
static u8 THISCALL osdIsSelected(u8 *self, u32 id) {
  s32 n = *(s32 *)(self + 0x2e6);
  for (s32 i = 0; i < n; ++i)
    if (((u32 *)(self + 0xe6))[i] == id)
      return 1;
  return 0;
}
PCREG(597b10, osdIsSelected);

extern "C" u32 THISCALL ext_59a5e0(u8 *osd, u32 type);   // ZGameOSD::PlaySound

// 0x59a650 (unnamed; ZGameOSD play sound with a volume/fade value), thiscall, ret 8, returns the sound handle.
// Plays the OSD sound `type`, remembers the handle (+0xd9) and, when the handle resolves to a sound object (table
// slot 0x60), sets its +0x78 to v / 1000.
static u32 THISCALL osdPlaySoundV(u8 *self, u32 type, float v) {
  u32 h = ext_59a5e0(self, type);
  *(u32 *)(self + 0xd9) = h;
  u8 *o = vcall<u8 *>(objTable(), 0x60, h);
  if (o)
    *(float *)(o + 0x78) = v * 0.001f;   // 0x67d9fc
  return *(u32 *)(self + 0xd9);
}
PCREG(59a650, osdPlaySoundV);

// 0x48aad0 (unnamed; resolve a {name table, name} pair to an id), thiscall, plain ret: the table's slot 0x88
// (name, &id), id starting at 0.
static u32 THISCALL nameRefResolve(void **self) {
  u32 id = 0;
  vcall<void>(self[0], 0x88, self[1], &id);
  return id;
}
PCREG(48aad0, nameRefResolve);

extern "C" u32 THISCALL ext_59a650(u8 *osd, u32 type, float v);
extern "C" u32 THISCALL ext_48aad0(void *ref);
extern "C" void THISCALL ext_59a580(u8 *osd, const char *msg, u32 color, u32 snd);   // ZGameOSD::MessageAdd
extern "C" void THISCALL ext_4f9680(void *gui, u32 set);                              // ZGui_Sound::PlaySound
extern "C" void THISCALL ext_5a5e90(u8 *osd, u32 v);                                 // ZOnScreenDisplay::CharismaSet

// Charisma music sting: the level controller (looked up by name "LevelController" through the table's name
// table, slot 0x138) gets message "Msg_Music_Charisma" (id from table slot 0x114 (name, 0, file, line)) through the
// event system (table +0xadc, slot 0x12c (target, id, 0)).
static void charismaMusic(u32 line) {
  struct {
    void *names;
    const char *name;
  } ref;
  ref.names = vcall<void *>(objTable(), 0x138);
  ref.name = (const char *)0x6a5c48;
  void *ev = *(void **)((u8 *)objTable() + 0xadc);
  void **evvt = *(void ***)ev;
  u16 msg = vcall<u16>(objTable(), 0x114, (const char *)0x6a4f88, 0u, (const char *)0x6ad250, line);
  u32 target = ext_48aad0(&ref);
  typedef void(THISCALL * f12c)(void *, u32, u32, u32);
  ((f12c)evvt[0x12c / 4])(*(void **)((u8 *)objTable() + 0xadc), target, (u32)msg, 0);
}

// Sound with the "no fade" flags: the handle's sound object gets flag 0x80 at +0x40 and +0x2c = 1.
static void charismaSoundFlags(u32 h) {
  u8 *o = vcall<u8 *>(objTable(), 0x60, h);
  if (!o)
    return;
  *(u32 *)(o + 0x40) |= 0x80;
  *(u32 *)(o + 0x2c) = 1;
}

// 0x596940 ZGameOSD::CharismaAddExperience(EEXPERIENCE kind, float* pos, bool show, int amount), thiscall,
// ret 0x10. Charisma points per kind (amount -1 = the kind's default):
//   0: 15 (sound + music sting), 1: none (sound only, then returns), 2: 25 (sound, flags), 3: 25 (long sound +
//   music sting), 4: 15, 5: none, 6, 7, 10: 25, 8: 10 (no sound), 9: 15 (sound, flags), other: 0.
// With `show`, the HUD message "<CharismaPoint text>" (sprintf'd with the amount; at most 31 characters, else an
// error is logged and nothing is added) is shown with a GUI sound. Every 100 points wrap to 0 and raise the
// recruitable count (+0x1fba) by one up to the maximum (+0x1fbe); points never go below 0. With `show`, a floating
// "+N" popup record is added at `pos` (+0x1fc2, 0x18 bytes each, count +0x22c2) and the meter is redrawn.
static void THISCALL charismaAddExperience(u8 *self, u32 kind, float *pos, u32 show, s32 amount) {
  s32 def = 0;
  switch (kind) {
    case 0:
      def = 15;
      if (!(u8)show)
        break;
      ext_59a650(self, 6, 1000.0f);
      charismaMusic(0x1e);
      break;
    case 1:
      if ((u8)show)
        ext_59a650(self, 6, 1000.0f);
      return;
    case 2:
      def = 25;
      if ((u8)show)
        charismaSoundFlags(ext_59a650(self, 6, 0.0f));
      break;
    case 3:
      def = 25;
      if (!(u8)show)
        break;
      ext_59a650(self, 6, 2000.0f);
      charismaMusic(0x52);
      break;
    case 4:
      def = 15;
      if ((u8)show)
        ext_59a650(self, 6, 1000.0f);
      break;
    case 5:
      return;
    case 6:
    case 7:
    case 10:
      def = 25;
      if ((u8)show)
        ext_59a650(self, 6, 1000.0f);
      break;
    case 8:
      def = 10;
      break;
    case 9:
      def = 15;
      if ((u8)show)
        charismaSoundFlags(ext_59a650(self, 6, 0.0f));
      break;
    default:
      break;
  }
  if (amount != -1)
    def = amount;
  void *texts = *(void **)((u8 *)objTable() + 0xae4);
  typedef const char *(THISCALL * fText)(void *, const char *, const char *);
  const char *t = ((fText)(*(void ***)texts)[0])(texts, (const char *)0x6a67e8, (const char *)0x6ad288);
  u32 len = 0;
  while (t[len])
    ++len;
  if (len > 0x1f) {
    void *lo = logAt((const char *)0x6ad250, 0x8d);
    ((logPrintf)(*(void ***)lo)[0x2c / 4])(lo, (const char *)0x6ad298, t);
    return;
  }
  char buf[0x20];
  void *fmt = vcall<void *>(G(void *, 0x70039c), 0x190);
  typedef void(__attribute__((cdecl)) * fSprintf)(void *, char *, const char *, s32);
  ((fSprintf)(*(void ***)fmt)[0x198 / 4])(fmt, buf, t, def);
  if ((u8)show) {
    ext_59a580(self, buf, 0xffffb100u, 0);
    ext_4f9680((void *)0x700e24, 2);
  }
  s32 *exp = (s32 *)(self + 0x1fb6);
  *exp += def;
  if (*exp >= 100) {
    *exp = *exp % 100;
    s32 rc = *(s32 *)(self + 0x1fba);
    if (rc < *(s32 *)(self + 0x1fbe))
      *(s32 *)(self + 0x1fba) = rc + 1;
  }
  if (*exp < 0)
    *exp = 0;
  if (!(u8)show)
    return;
  u32 k = *(u32 *)(self + 0x22c2);
  u8 *rec = self + 0x1fc2 + k * 0x18;
  *(u32 *)(rec + 0x14) = kind;
  *(u32 *)(rec + 4) = 0x40400000u;   // 3.0 (time left)
  *(u32 *)(rec + 0) = *(u32 *)(rec + 4);
  *(u32 *)(rec + 8) = ((u32 *)pos)[0];
  *(u32 *)(rec + 0xc) = ((u32 *)pos)[1];
  *(u32 *)(rec + 0x10) = ((u32 *)pos)[2];
  ++*(u32 *)(self + 0x22c2);
  u8 *osd = *(u8 **)(self + 0x1d0f);
  if (osd)
    ext_5a5e90(osd, *(u32 *)(self + 0x1fb6));
}
PCREG(596940, charismaAddExperience);

extern "C" u32 THISCALL ext_597a20(u8 *osd, u32 id);
extern "C" u32 THISCALL ext_597b10(u8 *osd, u32 id);
extern "C" u32 THISCALL ext_59ffc0(u8 *actor);
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);   // vdist2 (squared distance), ST0

// 0x597720 ZGameOSD::FindNextRecruit(float* dist), thiscall, ret 4, returns the actor id or 0.
// Nearest recruitable actor within 1500 units of the hero, from the area search object +0x4f7 (slot 0x84
// (center, radius, &cursor, team) returns the next actor or null; cursor starts at -1; team = [[hero+0x54]+0x10]).
// Skipped: the hero, actors in state 4 ([[a+0x54]+8]), actors whose slot 0x438 answers yes, ids on the
// non-recruitable list (+0x2ef), recruits already mine, selected ones, wounded (mode 5), and anything with a squared
// distance over 2,250,000. When `dist` is given it gets sqrt(best squared distance) (1e38 squared when none).
static u32 THISCALL findNextRecruit(u8 *self, float *dist) {
  void *srch = *(void **)(self + 0x4f7);
  if (!srch)
    return 0;
  float hp[3] = {0, 0, 0};
  vcall<void>(*(u8 **)(self + 0x1d0b), 0x84, hp);
  u32 bestId = 0;
  float best = 9.99999968e37f;   // 0x67cd44
  s32 cursor = -1;
  u32 team = *(u32 *)(*(u8 **)(*(u8 **)(self + 0x1d0b) + 0x54) + 0x10);
  typedef u8 *(THISCALL * fFind)(void *, float *, float, s32 *, u32);
  u8 *a = ((fFind)(*(void ***)srch)[0x84 / 4])(srch, hp, 1500.0f, &cursor, team);
  while (a) {
    if (*(u8 **)(self + 0x1d0b) != a && *(u32 *)(*(u8 **)(a + 0x54) + 8) != 4 && !vcall<u8>(a, 0x438)) {
      u32 id = vcall<u32>(objTable(), 0x4c, a);
      bool skip = false;
      s32 n = *(s32 *)(self + 0x4ef);
      for (s32 i = 0; i < n; ++i)
        if (((u32 *)(self + 0x2ef))[i] == id) {
          skip = true;
          break;
        }
      if (!skip && !(u8)ext_597a20(self, id) && !(u8)ext_597b10(self, id) && ext_59ffc0(a) != 5) {
        float p[3] = {0, 0, 0};
        vcall<void>(a, 0x84, p);
        float d = ext_4e0830(p, hp);
        if (!(d > 2250000.0f) && best > d) {   // 0x6ad31c
          best = d;
          bestId = id;
        }
      }
    }
    srch = *(void **)(self + 0x4f7);
    a = ((fFind)(*(void ***)srch)[0x84 / 4])(srch, hp, 1500.0f, &cursor, team);
  }
  if (dist)
    *dist = (float)crt::sqrt((double)best);
  return bestId;
}
PCREG(597720, findNextRecruit);
