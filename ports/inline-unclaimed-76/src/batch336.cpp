// batch336.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x61bfa0 (cdecl, four arguments a, b, c, d; plain ret; GUESS).
// Copies b, c, d into a local three-dword record (at offsets 0, 4, 8) and returns 0x61bfe0(a, &record, 0) (exe, cdecl, three arguments).
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_61bfe0(u32 a, u32 rec, u32 zero);

static u32 __attribute__((cdecl)) wrap_61bfa0(u32 a, u32 b, u32 c, u32 d) {
    u32 rec[3];
    rec[0] = b;
    rec[1] = c;
    rec[2] = d;
    return ext_61bfe0(a, (u32)rec, 0u);
}
PCREG(61bfa0, wrap_61bfa0);
