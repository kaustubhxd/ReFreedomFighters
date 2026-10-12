// batch607.cpp - band 0x421000-0x441000, batch 607: CConfiguration volume setters (0x433370, 0x433490, 0x4334e0, 0x433530).
// All four are thiscall, ret 4. Each one stores the new value when it differs from the stored one, calls the notify helper
// 0x431410 (thiscall, two arguments: a name pointer and the value; not ported, hooked by address in the spec), then calls
// slot 0x104 of the sound object at [[0x70039c]+0x1a9f] when that object exists, with three arguments (kind, value, 2).
// Note the exe compares one field and stores another for the intro-music and speech setters (ported as found).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vThree)(void *self, u32 a, u32 b, u32 c);        // slot 0x104: three arguments
extern "C" void THISCALL ext_431410(void *self, u32 name, u32 value);  // notify helper (thiscall, ret 8)

static inline void setVolume(u8 *self, u32 v, u32 cmpOff, u32 storeOff, u32 name, u32 kind) {
  if (*(u32 *)(self + cmpOff) == v)
    return;
  *(u32 *)(self + storeOff) = v;
  ext_431410(self, name, v);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *snd = *(u8 **)(sys + 0x1a9f);
  if (!snd)
    return;
  ((vThree)VT(snd, 0x104))(snd, kind, *(u32 *)(self + storeOff), 2);
}

// 0x433370 CConfiguration::SetIntroMusicVolume(int v): compares [+0xf0], stores [+0xf4]; name 0x679fe8, kind 3
static void THISCALL setIntroMusicVolume(u8 *self, u32 v) {
  setVolume(self, v, 0xf0, 0xf4, 0x679fe8, 3);
}
PCREG(433370, setIntroMusicVolume);

// 0x433490 CConfiguration::SetMusicVolume(int v): [+0xec]; name 0x679fdc, kind 1
static void THISCALL setMusicVolume(u8 *self, u32 v) {
  setVolume(self, v, 0xec, 0xec, 0x679fdc, 1);
}
PCREG(433490, setMusicVolume);

// 0x4334e0 CConfiguration::SetSfxVolume(int v): [+0xe8]; name 0x679fc8, kind 0
static void THISCALL setSfxVolume(u8 *self, u32 v) {
  setVolume(self, v, 0xe8, 0xe8, 0x679fc8, 0);
}
PCREG(4334e0, setSfxVolume);

// 0x433530 CConfiguration::SetSpeechVolume(int v): [+0xf0]; name 0x679ffc, kind 2
static void THISCALL setSpeechVolume(u8 *self, u32 v) {
  setVolume(self, v, 0xf0, 0xf0, 0x679ffc, 2);
}
PCREG(433530, setSpeechVolume);
