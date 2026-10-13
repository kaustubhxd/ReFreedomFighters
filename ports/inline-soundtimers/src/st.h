// st.h - cross-file declarations for the soundtimers batches (1600-1699).
#pragma once
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

// CRT float -> 64-bit integer helper (0x633910, an __ftol3-style routine: float in XMM0, result in EDX:EAX).
// Kept as a platform-layer call like crt::sin in ff.h.
extern "C" void ext_633910();
static inline u32 crt_ftoll_lo(float f) {
  u32 lo;
  asm volatile("call ext_633910"
               : "=a"(lo), "+Yz"(f)
               :
               : "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return lo;
}

// batch1600
u8 THISCALL ZCharacterControl_CanIPlay(void *self, u32 e, u32 teamArg);
void THISCALL ZCharacterControl_Play_OnScreen_Delayed(void *self, void *actor, u32 e, u32 delay, const char *s);
// batch1601
u32 THISCALL ZIKLNKOBJ_PlaySound1(void *self, u32 sound);
u32 THISCALL ZIKLNKOBJ_ControlSound(void *self, u32 sound, u32 force);
u32 THISCALL ZIKLNKOBJ_PlaySound3(void *self, u32 sound, s32 pitch, u32 speech);
u32 THISCALL ZIKLNKOBJ_PlaySound4(void *self, u32 sound, s32 pitch, s32 delayMs, u32 speech);
// batch1602
void THISCALL ZFFActor_ExpandSoundset(void *self);
