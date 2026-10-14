// batch750.cpp - area 72, tail-jump forwarders (2026-10-12): each function jumps to a known exe target with the same stack
// arguments. Ported as a call with the target's arity (its ret imm / 4) and the result returned as is.
#include "ff.h"

extern "C" u32 THISCALL ext_4c0e20(void *self, u32 a);                 // ZSoundExtend::GetValues (ret 4)
extern "C" u32 THISCALL ext_4c1060(void *self, u32 a);                 // ZSoundSegment::GetValues (ret 4)
extern "C" u32 THISCALL ext_4c16b0(void *self, u32 a);                 // ZSoundSegmentVolume::GetValues (ret 4)
extern "C" u32 THISCALL ext_4c18b0(void *self, u32 a);                 // ZSoundSpline::GetValues (ret 4)
extern "C" u32 THISCALL ext_4d7c30(void *self, u32 a, u32 b, u32 c, u32 d);   // target (ret 0x10)

// 0x4bf4b0 - jmp 0x4c0e20
static u32 THISCALL fwd_4bf4b0(u8 *self, u32 a) { return ext_4c0e20(self, a); }
PCREG(4bf4b0, fwd_4bf4b0);
// 0x4bf4c0 - jmp 0x4c1060
static u32 THISCALL fwd_4bf4c0(u8 *self, u32 a) { return ext_4c1060(self, a); }
PCREG(4bf4c0, fwd_4bf4c0);
// 0x4bf4e0 - jmp 0x4c16b0
static u32 THISCALL fwd_4bf4e0(u8 *self, u32 a) { return ext_4c16b0(self, a); }
PCREG(4bf4e0, fwd_4bf4e0);
// 0x4bf4f0 - jmp 0x4c18b0
static u32 THISCALL fwd_4bf4f0(u8 *self, u32 a) { return ext_4c18b0(self, a); }
PCREG(4bf4f0, fwd_4bf4f0);
// 0x4d5760 - jmp 0x4d7c30 (ret 0x10)
static u32 THISCALL fwd_4d5760(u8 *self, u32 a, u32 b, u32 c, u32 d) { return ext_4d7c30(self, a, b, c, d); }
PCREG(4d5760, fwd_4d5760);
