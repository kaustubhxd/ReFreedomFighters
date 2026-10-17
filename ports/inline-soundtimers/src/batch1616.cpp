// batch1616.cpp - ZDllSound::AddNewPlayBuffer: a new sound object's settings from its SND record (soundtimers).
#include "st.h"

static inline u8 *base(void *self) { return AT(u8 *, self, 0x5302); }
extern "C" char ext_537500[];  // resolves a sound id to the record that will play (not ported; 582 bytes)
typedef u32(THISCALL *ResolveFn)(void *self, u32 id);
typedef void(THISCALL *SetDistFn)(void *o, float d);
extern "C" char ext_441890[];  // batch 1611 SetDistances

// 0x534e60 ZDllSound::AddNewPlayBuffer(ZSoundObject*) [high]. Only for objects of type 3 (fresh from AddSound3d/2d).
// Resolves the id (+0x7c, 0x537500; 0 -> false), sets priority class 2, clears the fade state, stores the
// resolved id, start time = engine time, time left (+0x70) = own +0x74(id) (x87 float; the wave length, inferred).
// Then needs the record (+0x54) and its wave (+0x1dc), else false. Flag 0x40 when "start time x 1024" equals +0x50b6
// while +0x50a9 is set (not traced). By record type: 1 (wave) keeps volume 1.0; 2 (sound): flag 8 = record +0x14 bit
// 0, volume = record +0x10, distances = SetDistances(record +0xc) with that volume; other types log "ERROR: ...
// got unknown type" and fail. Finally object type +4 = 10 when the volume category's flag (+0x515d + 9 x category)
// is set, else 7, and the play list (+0x53b2) gets +4(object +0x10). Returns true.
u8 THISCALL ZDllSound_AddNewPlayBuffer(void *self, u8 *o) {
  if (AT(u32, o, 4) != 3) return 0;
  u32 id = ((ResolveFn)(void *)ext_537500)(self, AT(u32, o, 0x7c));
  if (!id) return 0;
  AT(u32, o, 0xc) = 2;
  AT(u8, o, 0xec) = 0;
  AT(u32, o, 0xed) = 0;
  AT(u32, o, 0xf1) = 0;
  AT(u32, o, 0xf5) = 0;
  AT(u32, o, 0x7c) = id;
  AT(u32, o, 0x6c) = AT(u32, G(u8 *, 0x70039c), 0x1c);
  typedef float(THISCALL * LenFn)(void *, u32);
  AT(float, o, 0x70) = (*(LenFn *)(*(u8 **)self + 0x74))(self, id);
  u8 *rec = vcall<u8 *>(self, 0x54, id);
  if (!rec) return 0;
  if (!vcall<void *>(self, 0x1dc, rec)) return 0;
  if (AT(u8, self, 0x50a9)) {
    float t = (float)AT(s32, o, 0x6c) * 0.0009765625f * 1024.0f;
    if (_mm_cvttss_si32(_mm_set_ss(t)) == AT(s32, self, 0x50b6)) AT(u32, o, 0x40) |= 0x40;
  }
  u32 ty = AT(u32, rec, 0);
  if (ty == 2) {
    if (AT(u8, rec, 0x14) & 1)
      AT(u32, o, 0x40) |= 8;
    else
      AT(u32, o, 0x40) &= 0xfffffff7u;
    AT(u32, o, 0x88) = AT(u32, rec, 0x10);
    ((SetDistFn)(void *)ext_441890)(o, AT(float, rec, 0xc));
  } else if (ty != 1) {
    void *log = G(void *, 0x700390);
    void *ch = vcall<void *>(log, 0x20, (const char *)0x6a1e2c, (u32)0x55c);
    typedef void (*Print)(void *, const char *);
    (*(Print *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6a20fc);
    return 0;
  }
  u32 cat = AT(u32, o, 0x2c);
  u32 push = AT(u32, o, 0x10);
  AT(u32, o, 4) = AT(u8, self, cat * 9 + 0x515d) ? 10 : 7;
  vcall<void>((u8 *)self + 0x53b2, 4, push);
  return 1;
}
PCREG(534e60, ZDllSound_AddNewPlayBuffer);

// 0x537500 (no map name; called only by AddNewPlayBuffer: "resolve a sound id at play time", name guessed).
// Types 1 (wave) and 2 (sound) play as they are; 5 (reference) follows +8; 3 (sound set) picks a member by the set's
// play mode (u16 +0xa) and repeats until it reaches a wave or sound:
//   mode 0  in order: member +0x14 is a counter, wrapping at the member count;
//   mode 1  random: trunc(rnd x count);
//   mode 2  random without repeats: +0x14 is a bit mask of members already played (bit i = DLL table +0x50c7[i]);
//           picks uniformly among the unplayed; when all were played, clears the mask and picks from all;
//   other   always member 0.
// rnd is the engine random (sys vtable +0x1c0); an index past the end is clamped to the last member. Returns the
// offset of the record to play, 0 for a zero member or an empty set reached through another set.
static inline float rnd01(u32 line) {
  typedef float(THISCALL * RndFn)(void *, const char *, u32);
  void *sys = G(void *, 0x70039c);
  return (*(RndFn *)(*(u8 **)sys + 0x1c0))(sys, (const char *)0x6a1e2c, line);
}
static inline s32 scaled(float r, s32 n) {
  long double x = (long double)r * (long double)(float)n;
  float f = (float)x;
  return _mm_cvttss_si32(_mm_set_ss(f));
}

u32 THISCALL ZDllSound_ResolvePlayId(void *self, u32 id) {
  if (!id) return 0;
  u8 *b = base(self);
  if (!b) return 0;
  u32 h = AT(u32, b, 0);
  if (AT(u32, b, h + 4) == 0 && AT(u32, b, h) == 0) return 0;
  u8 *rec = (u8 *)((u32)b + id);
  u32 cur = id;
  switch (AT(u32, rec, 0)) {
    case 1:
    case 2:
      return id;
    case 3:
      break;
    case 5: {
      u32 r8 = AT(u32, rec, 8);
      rec = (u8 *)((u32)b + r8);
      if (AT(u32, rec, 0) == 2) return r8;
      break;
    }
    default:
      return 0;
  }
  for (;;) {
    if (AT(u32, rec, 0) == 1) return cur;
    u32 cnt = AT(u16, rec, 8);
    if (!cnt) return 0;
    u32 *tab = (u32 *)((u32)AT(u8 *, self, 0x5302) + AT(u32, rec, 0x10));
    u32 mode = AT(u16, rec, 0xa);
    s32 idx = 0;
    if (mode == 0) {
      idx = AT(s32, rec, 0x14);
      u32 nx = (u32)idx + 1;
      AT(u32, rec, 0x14) = nx;
      if (nx >= cnt) AT(u32, rec, 0x14) = 0;
    } else if (mode == 1) {
      float r = rnd01(0x439);
      idx = scaled(r, (s32)AT(u16, rec, 8));
    } else if (mode == 2) {
      u8 local[0x20];
      s32 k = 0;
      u32 played = AT(u32, rec, 0x14);
      for (s32 i = 0; i < (s32)cnt; i++)
        if (!(AT(u32, self, 0x50c7 + 4 * i) & played)) local[k++] = (u8)i;
      if (k) {
        float r = rnd01(0x454);
        idx = local[scaled(r, k)];
      } else {
        AT(u32, rec, 0x14) = 0;
        float r = rnd01(0x451);
        idx = scaled(r, (s32)AT(u16, rec, 8));
      }
      AT(u32, rec, 0x14) |= AT(u32, self, 0x50c7 + 4 * idx);
    }
    if (idx >= (s32)AT(u16, rec, 8)) idx = (s32)AT(u16, rec, 8) - 1;
    u32 m = tab[idx];
    if (!m) return 0;
    rec = (u8 *)((u32)AT(u8 *, self, 0x5302) + m);
    u32 t = AT(u32, rec, 0);
    if (t == 3) {
      if (AT(u16, rec, 8) == 0) return 0;
    } else {
      cur = m;
      if (t == 2) return cur;
    }
  }
}
PCREG(537500, ZDllSound_ResolvePlayId);
