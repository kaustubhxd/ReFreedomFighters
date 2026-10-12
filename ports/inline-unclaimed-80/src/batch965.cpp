#include "ff.h"
// batch965.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): three cdecl wrappers that pass the address of one of their own parameters
// (the out slot) to a helper (GUESS, hooked by address in the spec). The helpers write through that pointer; eax passes through.
// 0x42ab0d(p0, p1, p2): ext_42aae8(p0, p1, 0, &p2).
// 0x42aba4(p0, p1, p2): ext_42ab81(p0, p1, 0, &p2).
// 0x428420(p0, p1, p2, p3): ext_42ac38(p0, 0x40, p1, p2, &p3).

extern "C" u32 ext_42aae8(u32 a, u32 b, u32 c, u32 *d);
extern "C" u32 ext_42ab81(u32 a, u32 b, u32 c, u32 *d);
extern "C" u32 ext_42ac38(u32 a, u32 b, u32 c, u32 d, u32 *e);

static u32 zg42ab0d(u32 p0, u32 p1, u32 p2) {
  return ext_42aae8(p0, p1, 0, &p2);
}
PCREG(42ab0d, zg42ab0d);

static u32 zg42aba4(u32 p0, u32 p1, u32 p2) {
  return ext_42ab81(p0, p1, 0, &p2);
}
PCREG(42aba4, zg42aba4);

static u32 zg428420(u32 p0, u32 p1, u32 p2, u32 p3) {
  return ext_42ac38(p0, 0x40, p1, p2, &p3);
}
PCREG(428420, zg428420);
