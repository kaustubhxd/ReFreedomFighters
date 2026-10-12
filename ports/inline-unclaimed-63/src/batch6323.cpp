// batch6323.cpp - unclaimed-63 gap-band batch 23 (band 0x4c1000-0x4e1000, method docs/20-unclaimed-72.md). Four short functions
// that share one callee, 0x4d24e0 (original, stubbed here; thiscall, four stack arguments, ret 0x10).
//   0x4d2bc0 (C-set, no GC name): stores ECX at [a], and b at [a+4]; a and b are the two stack arguments (ret 8).
//   0x4d39c0 (C-set): 0x4d24e0(ECX; a1, 2, a2, a3) (ret 0xc).
//   0x4d3ab0 (C-set): 0x4d24e0(ECX; a1, 4, &a2, 0) (ret 8).
//   0x4d3db0 (C-set): 0x4d24e0(ECX; a1, 1, &a2, 0) (ret 8).
#include "ff.h"

extern "C" u32 THISCALL ext_4d24e0(void *self, u32 a1, u32 a2, u32 a3, u32 a4);   // original, stubbed by the spec

// 0x4d2bc0 (C-set).
static void THISCALL unnamed4d2bc0(u32 ecxv, u32 *dst, u32 b) {
  dst[0] = ecxv;
  dst[1] = b;
}
PCREG(4d2bc0, unnamed4d2bc0);

// 0x4d39c0 (C-set).
static void THISCALL unnamed4d39c0(u32 ecxv, u32 a1, u32 a2, u32 a3) {
  ext_4d24e0((void *)ecxv, a1, 2u, a2, a3);
}
PCREG(4d39c0, unnamed4d39c0);

// 0x4d3ab0 (C-set). The second stack argument's address is passed (the callee reads its content).
static void THISCALL unnamed4d3ab0(u32 ecxv, u32 a1, u32 a2) {
  ext_4d24e0((void *)ecxv, a1, 4u, (u32)&a2, 0u);
}
PCREG(4d3ab0, unnamed4d3ab0);

// 0x4d3db0 (C-set).
static void THISCALL unnamed4d3db0(u32 ecxv, u32 a1, u32 a2) {
  ext_4d24e0((void *)ecxv, a1, 1u, (u32)&a2, 0u);
}
PCREG(4d3db0, unnamed4d3db0);
