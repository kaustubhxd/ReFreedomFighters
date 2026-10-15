// batch1609.cpp - the other two ZIKLNKOBJ sound paths: PlaySoundSFX and PlaySoundSpeech (soundtimers thread).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }
typedef u32(THISCALL *AddSound3dFn)(void *grp, float *mat, float *pos, u32 sound, u32, u32, u32);
extern "C" char ext_43ec00[];                    // ZGROUP::AddSound3d [high]
typedef void(THISCALL *Fn0)(void *);
extern "C" char ext_44b610[];                    // ZSoundObject method called before freeing it (not named)
extern "C" void ext_44b740(void *o);             // frees a ZSoundObject (map: ~ZSoundObject, low; cdecl here)

// 0x467230 ZIKLNKOBJ::PlaySoundSFX(uint sound) [high]: a plain 3D sound at the object's transform. Unlike
// PlaySound(uint) it does not touch the sound's flags, category or priority, so an SFX keeps flag 4 and IS tested
// against the sound graph.
u32 THISCALL ZIKLNKOBJ_PlaySoundSFX(void *self, u32 sound) {
  u8 *m = AT(u8 *, self, 8);
  void *grp = vcall<void *>(self, 0x20);
  return ((AddSound3dFn)(void *)ext_43ec00)(grp, (float *)m, (float *)(m + 0x24), sound, 0, 0, 0);
}
PCREG(467230, ZIKLNKOBJ_PlaySoundSFX);

// 0x467260 ZIKLNKOBJ::PlaySoundSpeech(uint sound, uint arg, int pitch) [high] (cutscene speech,
// CCutSequenceCharacterSound::Run): needs the sound DLL. Stops and frees the previous cutscene line (+0x153),
// asks the object for a matrix and position (vtable +0x3a0(mat, pos), result passed to +0x390; head position,
// inferred), starts the sound there (AddSound3d(mat, pos, sound, arg, 0, 0)), then flag 0x80, category 2 and the
// pitch; when the DLL's +0x70(sound) says so (meaning not traced), volume 30 (+0x88), min distance 150 (+0x54) and
// max distance 5760 (+0x5c). Flag 4 is left as AddSound3d set it.
u32 THISCALL ZIKLNKOBJ_PlaySoundSpeech(void *self, u32 sound, u32 arg, s32 pitch) {
  if (!AT(void *, sys(), 0x1a9f)) return 0;
  u32 old = AT(u32, self, 0x153);
  if (old) {
    void *o = srefToPtr(old);
    if (o) {
      ((Fn0)(void *)ext_44b610)(o);
      ext_44b740(o);
    }
    AT(u32, self, 0x153) = 0;
  }
  float mat[9], pos[3];
  void *x = vcall<void *>(self, 0x3a0, mat, pos);
  vcall<void>(self, 0x390, x);
  void *grp = vcall<void *>(self, 0x20);
  u32 h = ((AddSound3dFn)(void *)ext_43ec00)(grp, mat, pos, sound, arg, 0, 0);
  AT(u32, self, 0x153) = h;
  u8 *o = (u8 *)srefToPtr(h);
  if (o) {
    s32 d = pitch - AT(s32, o, 0x64);
    AT(u32, o, 0x40) |= 0x80;
    AT(u32, o, 0x2c) = 2;
    AT(s32, o, 0x60) = d;
    AT(s32, o, 0x64) = pitch;
    if (vcall<u8>(AT(void *, sys(), 0x1a9f), 0x70, sound)) {
      AT(u32, o, 0x88) = 0x41f00000;  // 30
      AT(u32, o, 0x54) = 0x43160000;  // 150
      AT(u32, o, 0x5c) = 0x45b40000;  // 5760
    }
  }
  return h;
}
PCREG(467260, ZIKLNKOBJ_PlaySoundSpeech);
