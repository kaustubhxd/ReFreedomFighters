// batch6340.cpp - unclaimed-63 gap-band batch 40: 0x4d3d30 (wrapper; no GC name), stdcall, three stack arguments a1, a2, a3, ret 0xc.
//   Returns 0x4d2700(a1, 4, a3, a2, 0) (stdcall, five arguments, the callee pops 20; original code, stubbed by the spec).
#include "ff.h"

extern "C" u32 STDCALL ext_4d2700(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);   // stdcall, ret 0x14, original, stubbed by the spec

// 0x4d3d30 (wrapper).
static u32 STDCALL unnamed4d3d30(u32 a1, u32 a2, u32 a3) {
  return ext_4d2700(a1, 4u, a3, a2, 0u);
}
PCREG(4d3d30, unnamed4d3d30);
