// u69_36.cpp - area 69, group 36 (slice 8). One stdcall wrapper around a cdecl helper (GUESS stub in the spec).
#include "ff.h"

extern "C" u32 ext_41e290(u32 n);  // cdecl, one arg; other area (stubbed in the spec: GUESS)

// 0x6014c0, allocCheck(unsigned int, const char*) (GC map high). stdcall, two args (ret 8). Returns ext_41e290(first arg); the second arg is not read.
static u32 STDCALL allocCheck6014c0(u32 n, const char *name) {
  return ext_41e290(n);
}
PCREG(6014c0, allocCheck6014c0);
