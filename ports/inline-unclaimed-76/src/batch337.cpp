// batch337.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x61cd30 (cdecl, four arguments a, b, c, d; plain ret; GUESS).
// Returns 0x61d090(a, 0, [a+0x8c], b, c, d) (exe, cdecl, six arguments; the caller of this wrapper pops nothing extra).
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_61d090(u32 a, u32 zero, u32 w, u32 b, u32 c, u32 d);

static u32 __attribute__((cdecl)) wrap_61cd30(u32 a, u32 b, u32 c, u32 d) {
    return ext_61d090(a, 0u, *(u32 *)(a + 0x8cu), b, c, d);
}
PCREG(61cd30, wrap_61cd30);
