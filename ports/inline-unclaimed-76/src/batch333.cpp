// batch333.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x620840 (cdecl, four arguments a, b, c, d; GUESS).
// r = 0x620180(a, b, c, d) (exe, cdecl; it reads only a); if r == 0 return 0. If [a+0xc] == [a+8]: if 0x6206e0(a) (exe, cdecl) == 0 return 0.
// Then a byte 0 is written at [a+0xc] and [a+0xc] advances by one; returns [a+0x10].
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_620180(u32 a, u32 b, u32 c, u32 d);
extern "C" u32 __attribute__((cdecl)) ext_6206e0(u32 a);

static u32 __attribute__((cdecl)) take_620840(u32 a, u32 b, u32 c, u32 d) {
    if (ext_620180(a, b, c, d) == 0u) return 0u;
    if (*(u32 *)(a + 0xcu) == *(u32 *)(a + 8u)) {
        if (ext_6206e0(a) == 0u) return 0u;
    }
    *(u8 *)*(u32 *)(a + 0xcu) = 0u;
    *(u32 *)(a + 0xcu) += 1u;
    return *(u32 *)(a + 0x10u);
}
PCREG(620840, take_620840);
