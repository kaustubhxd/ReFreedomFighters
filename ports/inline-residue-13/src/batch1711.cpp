// batch1711.cpp - 0x628ed0 (GUESS, area-13 band, 2026-10-12). Cdecl, four stack arguments (the callee's), plain ret.
// Overwrites its first argument slot with 0x6be728 and tail-jumps into 0x622ad0 (cdecl, four arguments, plain ret; hooked
// by address) with the other three unchanged; returns its eax.
#include "ff.h"

extern "C" char ext_622ad0[];
typedef u32 (*Fn622ad0)(u32 a, u32 b, u32 c, u32 d);

u32 GUESS_628ed0(u32 a, u32 b, u32 c, u32 d) {
  (void)a;
  return ((Fn622ad0)(void *)ext_622ad0)(0x6be728u, b, c, d);
}
PCREG(628ed0, GUESS_628ed0);
