// Extracted by browser-next/decomp-wasm/extract.py from batch202.cpp: setModeAndRun_59d430 (with the file preamble).
#include "ff.h"


extern "C" void THISCALL ext_59d450(u8 *self);   // original code, not ported in this claim (the harness binds it to the exe)

// 0x59d430, thiscall(mode): [this+4] = mode, then call the original setModeFlags 0x59d450 on this. Name GUESS.
static void THISCALL setModeAndRun_59d430(u8 *self, u32 mode) {
  *(u32 *)(self + 4) = mode;
  ext_59d450(self);
}
PCREG(59d430, setModeAndRun_59d430);

// batch227.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. The parked 0x59d450 from
// docs/20-unclaimed-20.md (its eight-way jump table on [this+4]), now verified in this claim. Name GUESS (mode-to-flags map).
#include "ff.h"

// 0x59d450, thiscall(): reset [this+0xc] and [this+0x10], then set bits from a jump table on [this+4] (cases 0..7;
// 0..7 map to (0xc,0x10) bits: 0 -> 2,1; 1 -> 1,2; 2 -> none; 3 -> 0xf0; 4 -> 0xe8; 5 -> 0xd8; 6 -> 0xb8; 7 -> 0x78).
// If [this+8] == 3, [this+0xc] is cleared again.
static void THISCALL setModeFlags_59d450(u8 *self) {
  u32 mode = *(u32 *)(self + 4);
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  if (mode <= 7) {
    switch (mode) {
    case 0:
      *(u32 *)(self + 0xc) |= 2;
      *(u32 *)(self + 0x10) |= 1;
      break;
    case 1:
      *(u32 *)(self + 0xc) |= 1;
      *(u32 *)(self + 0x10) |= 2;
      break;
    case 2:
      break;
    case 3:
      *(u32 *)(self + 0xc) |= 0xf0u;
      break;
    case 4:
      *(u32 *)(self + 0xc) |= 0xe8u;
      break;
    case 5:
      *(u32 *)(self + 0xc) |= 0xd8u;
      break;
    case 6:
      *(u32 *)(self + 0xc) |= 0xb8u;
      break;
    default:
      *(u32 *)(self + 0xc) |= 0x78u;
      break;
    }
  }
  if (*(u32 *)(self + 8) == 3) *(u32 *)(self + 0xc) = 0;
}
PCREG(59d450, setModeFlags_59d450);
