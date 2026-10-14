// batch1634.cpp - ZDllSound::DeleteSounds(int group) (soundtimers thread, 2026-10-11).
#include "st.h"

extern "C" char ext_44b610[];  // ZSoundObject pre-free (thiscall, ECX = object)
extern "C" void ext_44b740(void *o);  // ZSoundObject delete (cdecl)
typedef void(THISCALL *Fn0)(void *);

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }

// 0x535ac0 ZDllSound::DeleteSounds(int group) [medium name]: logs "DELETE SOUNDS %d" (sound.cpp line 0xbc1), then walks the
// play list (+0x53b2: vtable +0x4c first, +0x5c next) and frees each sound object whose group (+0x2c) is `group`, or every
// sound when group is -1. Freeing: the pre-free method (0x44b610) and the delete (0x44b740).
void THISCALL ZDllSound_DeleteSounds(u8 *self, s32 group) {
  void *log = G(void *, 0x700390);
  void *ch = vcall<void *>(log, 0x20, (const char *)0x6a1e2c, (u32)0xbc1);
  typedef void (*Print)(void *, const char *, s32);
  (*(Print *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6a24c0, group);
  u8 *lst = self + 0x53b2;
  u32 tmp = 0;
  vcall<void>(lst, 0x4c, &tmp);
  u32 r = vcall<u32>(lst, 0x5c, &tmp);
  while (tmp) {
    u8 *o = (u8 *)srefToPtr(r);
    if (o && (AT(s32, o, 0x2c) == group || group == -1)) {
      ((Fn0)(void *)ext_44b610)(o);
      ext_44b740(o);
    }
    r = vcall<u32>(lst, 0x5c, &tmp);
  }
}
PCREG(535ac0, ZDllSound_DeleteSounds);
