// batch6205.cpp - unclaimed-62 claim 3 (slice-1 leaves): six getters. Field reads are unaligned, so they go through memcpy.
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

// 0x468210 ZCTRLIKLNKOBJ::LightReceived() const: the float at +0x1da (returns in ST0).
static float THISCALL lightReceived(const u8 *self) { return rdf(self + 0x1da); }
PCREG(468210, lightReceived);

// 0x46eed0 ZLNKOBJ::GetAnimFile(): the dword at +0x5c.
static u32 THISCALL getAnimFile(const u8 *self) { return rd32u(self + 0x5c); }
PCREG(46eed0, getAnimFile);

// 0x483a10 ZPlayer::GetCenterHeight() const: the float at +0x451 (ST0).
static float THISCALL getCenterHeight(const u8 *self) { return rdf(self + 0x451); }
PCREG(483a10, getCenterHeight);

// 0x483f10 ZPlayer::IsWalking() const: bit 0 of the dword at +0x417.
static u32 THISCALL isWalking(const u8 *self) { return rd32u(self + 0x417) & 1; }
PCREG(483f10, isWalking);

// 0x5abcd0 CMessageBasics::IsVisible(): the byte at +8 (returned in al).
static u8 THISCALL messageIsVisible(const u8 *self) { return self[8]; }
PCREG(5abcd0, messageIsVisible);

// 0x5139d0 ZMoveOnSpline::PathLen(): tail call to slot 0x10 of the object at +0x5c (no arguments).
static u32 THISCALL pathLen(u8 *self) {
  u8 *o = (u8 *)rd32u(self + 0x5c);
  return vcall<u32>(o, 0x10);
}
PCREG(5139d0, pathLen);
