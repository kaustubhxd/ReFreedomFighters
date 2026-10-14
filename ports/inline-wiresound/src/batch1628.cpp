// batch1628.cpp - ZDllSound mute and environment setters (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }

// 0x537f80 ZDllSound::MuteSourceGroup(uint group, float volume) [high]: stores the volume at +0x514d, the group at
// +0x5149, sets the active flag +0x5148 and the start time +0x5151 = engine tick count x 1024^-1 (seconds). The
// "start time" is read from sys+0x1c (the same tick field the shouts use, see docs/20-soundtimers.md).
void THISCALL ZDllSound_MuteSourceGroup(u8 *self, u32 group, float volume) {
  AT(float, self, 0x514d) = volume;
  AT(u8, self, 0x5148) = 1;
  AT(u32, self, 0x5149) = group;
  AT(float, self, 0x5151) = (float)AT(s32, sys(), 0x1c) * 0.0009765625f;
}
PCREG(537f80, ZDllSound_MuteSourceGroup);

// 0x5398c0 ZDllSound::SetDefaultEnv(uint env) [high]: stores the environment id at +0x52f2.
void THISCALL ZDllSound_SetDefaultEnv(u8 *self, u32 env) { AT(u32, self, 0x52f2) = env; }
PCREG(5398c0, ZDllSound_SetDefaultEnv);

// 0x539c90 ZDllSound::SetTemporaryEnv(uint env) [high]: stores the temporary environment id at +0x52f6.
void THISCALL ZDllSound_SetTemporaryEnv(u8 *self, u32 env) { AT(u32, self, 0x52f6) = env; }
PCREG(539c90, ZDllSound_SetTemporaryEnv);
