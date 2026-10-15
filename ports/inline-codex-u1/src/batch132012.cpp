// Port derived from inline-soundtimers batch1616; strict verification by codex-u1.
// batch1616.cpp - ZDllSound::AddNewPlayBuffer: a new sound object's settings from its SND record (soundtimers).
#include "ff.h"
template<class T> static T& field12(void* p,u32 off){return *(T*)((u8*)p+off);}
#define AT(T,p,o) field12<T>(p,o)

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

