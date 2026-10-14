// batch1627.cpp - ZDllSound::SetListener (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }

// 0x539be0 ZDllSound::SetListener(uint ref) [high]: when the database resolves the reference (vtable +0x58), it becomes
// the listener (+0x51ad) and the three listener counters +0x50aa, +0x50ae, +0x50b2 are cleared. Otherwise logs
// "WARNING: ZDllSound::SetListener - invalid geomref %x" (sound.cpp line 0x5ed) and changes nothing.
void THISCALL ZDllSound_SetListener(u8 *self, u32 ref) {
  if (vcall<void *>(AT(void *, sys(), 0x9b), 0x58, ref)) {
    AT(u32, self, 0x51ad) = ref;
    AT(u32, self, 0x50b2) = 0;
    AT(u32, self, 0x50ae) = 0;
    AT(u32, self, 0x50aa) = 0;
    return;
  }
  void *log = G(void *, 0x700390);
  void *ch = vcall<void *>(log, 0x20, (const char *)0x6a1e2c, (u32)0x5ed);
  typedef void (*Print)(void *, const char *, u32);
  (*(Print *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6a21a8, ref);
}
PCREG(539be0, ZDllSound_SetListener);
