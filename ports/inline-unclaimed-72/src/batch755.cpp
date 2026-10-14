// batch755.cpp - area 72, round 4 skipped rows (2026-10-12): callee-arity cases (read from the callee's ret) and virtual tail
// jumps modelled at arity 0 (GUESS). See docs/20-unclaimed-72.md.
#include "ff.h"

extern "C" void THISCALL ext_4bb550(void *self);                 // ZSoundToggle::DefaultValues (ret 0)
extern "C" void THISCALL ext_4c24b0(void *self);                 // callee of 0x4bb9d0 (ret 0)
extern "C" void THISCALL ext_5491a0(void *self);                 // CShatter::Setup (ret 0)
extern "C" u32 THISCALL ext_4c0a90(void *self, u32 a);           // ZMusicControl::GetValues (ret 4)
extern "C" u32 THISCALL ext_4c0b00(void *self, u32 a);           // ZSoundAnimation::GetValues (ret 4)

static bool THISCALL f_4bb600(u8 *self, u32 a) { (void)a; *(u32 *)(self + 4) &= 0xffffffbfu; ext_4bb550(self); return true; }
PCREG(4bb600, f_4bb600);

static bool THISCALL f_4bb9d0(u8 *self, u32 a) { (void)a; *(u32 *)(self + 4) &= 0xffffffbfu; ext_4c24b0(self); return true; }
PCREG(4bb9d0, f_4bb9d0);

static void THISCALL f_5490f0(u8 *self) { if (*(u8 *)(self + 4) & 4) ext_5491a0(self); }
PCREG(5490f0, f_5490f0);

static u32 THISCALL f_4c1e20(u8 *self, u32 a, u32 b) { (void)a; return ext_4c0a90(self, b); }
PCREG(4c1e20, f_4c1e20);

static u32 THISCALL f_4c1ed0(u8 *self, u32 a, u32 b) { (void)a; return ext_4c0b00(self, b); }
PCREG(4c1ed0, f_4c1ed0);

// GUESS arity 0: virtual tail jumps (the thunks have no pushes and no ret of their own)
static u32 THISCALL f_4c1f70(u8 *self) { u8 *db = *(u8 **)(*(u8 **)0x70039c + 0x9b); return vcall<u32>(db, 0x2c); }
PCREG(4c1f70, f_4c1f70);

static u32 THISCALL f_4d4040(u8 *self) { return vcall<u32>(self + 0x10db, 0x0); }
PCREG(4d4040, f_4d4040);

static void THISCALL f_4dbbc0(u8 *self) { u8 *o = *(u8 **)(self + 0x54); if (o) vcall<void>(o, 0x18); }
PCREG(4dbbc0, f_4dbbc0);

static void THISCALL f_4dbbd0(u8 *self) { u8 *o = *(u8 **)(self + 0x54); if (o) vcall<void>(o, 0x1c); }
PCREG(4dbbd0, f_4dbbd0);
