// batch304.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x605ac0 and 0x605b20, two case-insensitive character
// scans (fastcall, three stack arguments; ret 0xc). Both use the 0x4cc4b0 case-insensitive character test, transliterated here.
#include "ff.h"

// 0x4cc4b0: case-insensitive equality of the byte in cl and the byte in dl ('A'..'Z' fold to lower case). Pure.
static inline bool ci_eq_605(u8 a, u8 b) {
    if ((u8)(a - 0x41) <= 0x19) a = (u8)(a + 0x20);
    if ((u8)(b - 0x41) <= 0x19) b = (u8)(b + 0x20);
    return a == b;
}

// 0x605ac0(begin = ecx, end = edx, s1, s2e, unused) (ret 0xc). Returns the first position in [begin, end) whose byte matches
// (case-insensitively) a byte in the pattern [s1, s2e); if none, returns end. GUESS: a case-insensitive find-any.
static u32 FASTCALL findAny_605ac0(u32 begin, u32 end, u32 s1, u32 s2e, u32 unused) {
    (void)unused;
    u32 a = begin;
    if (a == end) return end;
    do {
        u32 p = s1;
        if (s1 != s2e) {
            do {
                if (ci_eq_605(*(u8 *)a, *(u8 *)p)) return a;
                p++;
            } while (p != s2e);
        }
        a++;
    } while (a != end);
    return end;
}
PCREG(605ac0, findAny_605ac0);

// 0x605b20(begin = ecx, end = edx, s1, s2e, unused) (ret 0xc). Returns the first position in [begin, end) whose byte matches none
// of the bytes in [s1, s2e) (case-insensitively); if every byte matches, returns end. GUESS: a case-insensitive span.
static u32 FASTCALL spanNot_605b20(u32 begin, u32 end, u32 s1, u32 s2e, u32 unused) {
    (void)unused;
    u32 pos = begin;
    if (pos == end) return pos;
    for (;;) {
        u8 c = *(u8 *)pos;
        u32 p = s1;
        if (p == s2e) return pos;
        bool found = false;
        do {
            if (ci_eq_605(c, *(u8 *)p)) {
                found = true;
                break;
            }
            p++;
        } while (p != s2e);
        if (!found) return pos;
        pos++;
        if (pos == end) return pos;
    }
}
PCREG(605b20, spanNot_605b20);
