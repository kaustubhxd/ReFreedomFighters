// batch1115.cpp - unclaimed-11 batch 16 (slice 10, full list): six leaves; GUESS where the name map disagrees.
#include "ff.h"

// 0x59b320, GUESS (name map: GetMaxNumberOfSaveGames; the body returns this+0x121ac): eax = this + 0x121ac.
static u8 *THISCALL guessAddrAt121ac(u8 *self) { return self + 0x121ac; }
PCREG(59b320, guessAddrAt121ac);

// 0x5b2520, ZActionMapP3Control::GetActionDefinitions(): eax = dword at 0x6edac8.
static u32 THISCALL p3GetActionDefinitions(u8 *self) { return G(u32, 0x6edac8); }
PCREG(5b2520, p3GetActionDefinitions);

// 0x5d70a0, ZActionMapMovieControlActionMap::GetActionDefinitions(): eax = dword at 0x6ef660.
static u32 THISCALL movieGetActionDefinitions(u8 *self) { return G(u32, 0x6ef660); }
PCREG(5d70a0, movieGetActionDefinitions);

// 0x65ca20, GUESS (no name): returns the old dword at this+4, then adds 0xc to it.
static u32 THISCALL guessPostAdvance(u8 *self) {
  u32 old = *(u32 *)(self + 4);
  *(u32 *)(self + 4) = old + 0xc;
  return old;
}
PCREG(65ca20, guessPostAdvance);

// 0x65f5e0, ZDrawBuffer::GetSizeY() const (low fit): inner = dword at this+0xc; eax = [inner+0x1006d] - [inner+0x10065].
static u32 THISCALL drawBufferGetSizeY(u8 *self) {
  u8 *inner = *(u8 **)(self + 0xc);
  return *(u32 *)(inner + 0x1006d) - *(u32 *)(inner + 0x10065);
}
PCREG(65f5e0, drawBufferGetSizeY);

// 0x64cda0, GUESS (no name): zeroes the dword at table[arg & 0xfff], where table = dword at this+0x10071.
static void THISCALL guessZeroSlot(u8 *self, u32 index) {
  u32 *table = *(u32 **)(self + 0x10071);
  table[index & 0xfff] = 0;
}
PCREG(64cda0, guessZeroSlot);
