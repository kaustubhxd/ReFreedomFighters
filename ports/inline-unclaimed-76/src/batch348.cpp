// batch348.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x6200d0 (cdecl, one argument s, plain ret; GUESS). Normalizes line ends
// in place: the scan skips to the first CR; from there, each CR becomes LF and a directly following LF is skipped; a lone CR becomes LF and
// the byte after it is processed normally; the string is terminated at the new end. Returns nothing.
#include "ff.h"

static void __attribute__((cdecl)) normalizeNl_6200d0(u32 s) {
    u8 *p = (u8 *)s;
    for (;;) {
        if (*p == 0u) return;
        if (*p == 0x0du) break;
        p++;
    }
    u8 *w = p;
    u8 *r = p;
    do {
        u8 *save = r;
        if (*r != 0x0du) {
            *w = *r;
            r++;
            w++;
        } else {
            r++;
            *w = 0x0au;
            if (*r != 0x0au) r = save;
            r++;
            w++;
        }
    } while (*r != 0u);
    *w = 0u;
}
PCREG(6200d0, normalizeNl_6200d0);
