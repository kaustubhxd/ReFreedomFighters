#include "ff.h"
// batch8001.cpp - unclaimed-79 gap-band accessor group 1 (docs/20-unclaimed-79.md). Names are GC names where known, else GUESS.

// 0x4827b0, ZPlayer::ControlsEnabled() const (getter at +0x600).
static u8 THISCALL f_4827b0(u8 *self) { return *(u8 *)(self + 0x600); }
PCREG(4827b0, f_4827b0);

// 0x4834c0, ZPlayer::EnableT1() (zero store at +0x5fe; 0 stack argument(s)).
static void THISCALL f_4834c0(u8 *self) { *(u8 *)(self + 0x5fe) = 0; }
PCREG(4834c0, f_4834c0);

// 0x483b00, ZPlayer::GetGroundContact() const (getter at +0x42c).
static u8 THISCALL f_483b00(u8 *self) { return *(u8 *)(self + 0x42c); }
PCREG(483b00, f_483b00);

// 0x483ea0, ZPlayer::GetSoundSet() const (getter at +0x60e).
static u32 THISCALL f_483ea0(u8 *self) { return *(u32 *)(self + 0x60e); }
PCREG(483ea0, f_483ea0);

// 0x483ed0, ZPlayer::GetStatus() const (getter at +0x417).
static u32 THISCALL f_483ed0(u8 *self) { return *(u32 *)(self + 0x417); }
PCREG(483ed0, f_483ed0);

// 0x4875d0, CPathUserProfile::GetUser() const (getter at +0x6).
static u32 THISCALL f_4875d0(u8 *self) { return *(u32 *)(self + 0x6); }
PCREG(4875d0, f_4875d0);

// 0x48d000, ZEngineGeomControl::Clear() (zero store at +0xcc; 0 stack argument(s)).
static void THISCALL f_48d000(u8 *self) { *(u32 *)(self + 0xcc) = 0; }
PCREG(48d000, f_48d000);

// 0x48db60, ZTimeUpdateList::Count() (getter at +0xa0c).
static u32 THISCALL f_48db60(u8 *self) { return *(u32 *)(self + 0xa0c); }
PCREG(48db60, f_48db60);

