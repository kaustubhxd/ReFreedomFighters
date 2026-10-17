// batch1625.cpp - ZDllSound small setters and listeners (soundtimers thread, 2026-10-11).
#include "st.h"

// 0x533bc0 ZDllSound::SPtrToRef(ZSoundObject* o) [high]: the object's handle (+0x10), 0 for null.
u32 THISCALL ZDllSound_SPtrToRef(void *self, u8 *o) {
  if (!o) return 0;
  return AT(u32, o, 0x10);
}
PCREG(533bc0, ZDllSound_SPtrToRef);

// 0x539c60 ZDllSound::SetMasterPan(int) [high]: no-op; returns 1 (the pan is not implemented in this build).
u8 THISCALL ZDllSound_SetMasterPan(void *self, s32 pan) {
  (void)self;
  (void)pan;
  return 1;
}
PCREG(539c60, ZDllSound_SetMasterPan);

// 0x5332d0 ZDllSound::EnableMultiListeners(bool on) [high]: stores the flag at +0x49.
void THISCALL ZDllSound_EnableMultiListeners(u8 *self, u8 on) { AT(u8, self, 0x49) = on; }
PCREG(5332d0, ZDllSound_EnableMultiListeners);

// 0x537e70 ZDllSound::ListenerDisable(int idx) [high]: for idx < 4 (signed) clears the listener's active flag at
// this + idx*13 + 0x15 and returns 1; otherwise returns 0.
u8 THISCALL ZDllSound_ListenerDisable(u8 *self, s32 idx) {
  if (idx >= 4) return 0;
  AT(u8, self, idx * 13 + 0x15) = 0;
  return 1;
}
PCREG(537e70, ZDllSound_ListenerDisable);

// 0x537e90 ZDllSound::ListenerEnable(int idx, uint a, uint b) [high]: idx 4 returns 0. Otherwise stores a at
// this + idx*13 + 0x1e, sets the active flag at +0x15, stores b at this + (idx+2)*13 and returns 1.
// GUESS: the meaning of the two stored values (a position and a second word, per the field layout) is not traced.
u8 THISCALL ZDllSound_ListenerEnable(u8 *self, s32 idx, u32 a, u32 b) {
  if (idx == 4) return 0;
  AT(u32, self, idx * 13 + 0x1e) = a;
  AT(u8, self, idx * 13 + 0x15) = 1;
  AT(u32, self, (idx + 2) * 13) = b;
  return 1;
}
PCREG(537e90, ZDllSound_ListenerEnable);
