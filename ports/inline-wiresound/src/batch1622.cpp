// batch1622.cpp - small ZDllSound accessors (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }

// 0x5398d0 ZDllSound::SetGroupPitch(int group, int pitch) [high]: this + group*9 + 0x515e = pitch.
void THISCALL ZDllSound_SetGroupPitch(u8 *self, u32 group, s32 pitch) {
  AT(s32, self, group * 9 + 0x515e) = pitch;
}
PCREG(5398d0, ZDllSound_SetGroupPitch);

// 0x5333c0 ZDllSound::GetGraph() [high]: the sound graph pointer at +0x52fe.
u32 THISCALL ZDllSound_GetGraph(u8 *self) { return AT(u32, self, 0x52fe); }
PCREG(5333c0, ZDllSound_GetGraph);

// 0x533b40 ZDllSound::IsPaused() const [high]: the pause flag at +0x50a9.
u8 THISCALL ZDllSound_IsPaused(u8 *self) { return AT(u8, self, 0x50a9); }
PCREG(533b40, ZDllSound_IsPaused);

// 0x5333d0 ZDllSound::GetMutedSourceGroups() [medium]: the float at +0x87 truncated to int (the field is not aligned
// to the DLL's own struct layout; read as the original does).
s32 THISCALL ZDllSound_GetMutedSourceGroups(u8 *self) {
  return _mm_cvttss_si32(_mm_set_ss(AT(float, self, 0x87)));
}
PCREG(5333d0, ZDllSound_GetMutedSourceGroups);

// 0x537200 ZDllSound::GetListener() [high]: the listener object for the current listener reference (+0x51ad). The
// database (sys+0x9b, vtable +0x58) resolves the reference; when that is empty, the sound engine's listener object
// (sys+0x190f, vtable +0xb4(0)) gives the reference to resolve.
u8 *THISCALL ZDllSound_GetListener(u8 *self) {
  u8 *db = AT(u8 *, sys(), 0x9b);
  u8 *o = vcall<u8 *>(db, 0x58, AT(u32, self, 0x51ad));
  if (o) return vcall<u8 *>(AT(void *, sys(), 0x9b), 0x58, AT(u32, self, 0x51ad));
  void *lis = AT(void *, sys(), 0x190f);
  if (!lis) return 0;
  u32 r = vcall<u32>(lis, 0xb4, (u32)0);
  return vcall<u8 *>(AT(void *, sys(), 0x9b), 0x58, r);
}
PCREG(537200, ZDllSound_GetListener);
