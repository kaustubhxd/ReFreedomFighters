#include "ff.h"
// batch3522.cpp - area 35 claim 22 (docs/20-unclaimed-35.md): 0x5dcea0, ZFFFlak::ReadInput(DBREAD&) (residue name, medium).
// Thiscall, one stack arg (the reader). Reads ints, floats and strings from the reader into this (see the claim table).
// Stubbed in the harness: 0x4e5e60 (int reader), 0x4e5e80 (float reader, st0), 0x4e5ea0 (string reader), 0x41e290 (cdecl alloc).

extern "C" u32 THISCALL ext_4e5e60(u8 *r);
extern "C" float THISCALL ext_4e5e80(u8 *r);
extern "C" u8 *THISCALL ext_4e5ea0(u8 *r);
extern "C" u8 *ext_41e290(u32 n);

// Copies the NUL-terminated string src into a new buffer from 0x41e290 (size = length + 1), NUL included.
static u8 *guessDupString(u8 *src) {
  u32 n = 0;
  while (src[n])
    n++;
  n++;
  u8 *p = ext_41e290(n);
  for (u32 i = 0;; i++) {
    p[i] = src[i];
    if (!src[i])
      break;
  }
  return p;
}

// 0x5dcea0, ZFFFlak::ReadInput(DBREAD&) (residue name).
void THISCALL flakReadInput(u8 *self, u32 reader) {
  u8 *r = (u8 *)reader;
  *(u32 *)(self + 0x54) = ext_4e5e60(r);
  *(u32 *)(self + 0x50) = ext_4e5e60(r);
  *(float *)(self + 0x5c) = ext_4e5e80(r);
  *(float *)(self + 0x60) = ext_4e5e80(r);
  *(u8 *)(self + 0x64) = ext_4e5e60(r) != 0;
  *(u32 *)(self + 0x65) = (u32)guessDupString(ext_4e5ea0(r));
  *(u32 *)(self + 0x69) = (u32)guessDupString(ext_4e5ea0(r));
  *(u32 *)(self + 0x6d) = (u32)guessDupString(ext_4e5ea0(r));
  *(u32 *)(self + 0x71) = (u32)guessDupString(ext_4e5ea0(r));
}
PCREG(5dcea0, flakReadInput);
