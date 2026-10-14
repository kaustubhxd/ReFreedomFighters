// batch1712.cpp - 0x575150 (GUESS, area-13 band, 2026-10-12). Thiscall, no stack arguments, plain ret. Calls 0x573da0 (thunk to
// ZBaseMap::LoadInit2 0x573dd0; thiscall, no arguments, plain ret; hooked by address) on this, then tail-jumps into 0x575230
// (ZZoneMap::LoadInit2 body; thiscall, no arguments, plain ret; hooked by address) on this; returns its eax.
#include "ff.h"

extern "C" char ext_573da0[];
extern "C" char ext_575230[];
typedef u32(THISCALL *Init0Fn)(void *self);

u32 THISCALL GUESS_575150(u8 *self) {
  ((Init0Fn)(void *)ext_573da0)(self);
  return ((Init0Fn)(void *)ext_575230)(self);
}
PCREG(575150, GUESS_575150);
