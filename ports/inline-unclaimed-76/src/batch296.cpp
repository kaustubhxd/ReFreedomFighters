// batch296.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4312f0 (ret 0xc; thiscall on a [begin, end] range).
#include "ff.h"

// Exe helper 0x42b2e0 (thiscall, three arguments, ret 0xc). Recorded by a GUESS call stub in the spec; runs as original code otherwise.
extern "C" void THISCALL ext_42b2e0(u32 self, u32 a, u32 b, u32 c);

// 0x4312f0(range, out, off, count) (ret 0xc). begin = range[0], end = range[1]. n = min(count, end - begin - off) (unsigned).
// Calls 0x42b2e0 on out with (begin + off, begin + off + n, &off + 3) (the last one points at the high byte of the off argument,
// as the exe does). Returns out. GUESS.
static u32 THISCALL sliceCall_4312f0(u32 range, u32 out, u32 off, u32 count) {
    u32 begin = *(u32 *)range;
    u32 rem = *(u32 *)(range + 4) - begin - off;
    u32 n = count;
    if (rem < n) n = rem;
    ext_42b2e0(out, begin + off, begin + off + n, (u32)((u8 *)&off + 3));
    return out;
}
PCREG(4312f0, sliceCall_4312f0);
