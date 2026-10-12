// u69_68.cpp - area 69, group 68 (slice 8). A case-insensitive byte search over two ranges. The byte compare is 0x4cc4b0 (another area, pure: real code runs).
#include "ff.h"

extern "C" u8 __attribute__((fastcall)) ext_4cc4b0(u8 a, u8 b);   // a, b in cl, dl: 1 when the bytes are equal ignoring ASCII case

// 0x605ac0, fastcall: ECX = start of the walk (pos2), EDX = its end (end2), stack: s1, s1end, unused (ret 0xc). For each pos2 in [ECX, end2) it looks for a byte in
// [s1, s1end) that compares equal to *pos2 ignoring case; the first such pos2 is returned. Otherwise returns end2. If ECX == end2 at once, returns end2.
static u8 *__attribute__((fastcall)) search605ac0(u8 *pos2, u8 *end2, u8 *s1, u8 *s1end, u32 unused) {
  if (pos2 == end2)
    return end2;
  u8 *start1 = s1;
  for (;;) {
    u8 *p1 = start1;
    if (p1 != s1end) {
      do {
        if (ext_4cc4b0(*p1, *pos2))
          return pos2;
        ++p1;
      } while (p1 != s1end);
    }
    ++pos2;
    if (pos2 == end2)
      break;
  }
  return end2;
}
PCREG(605ac0, search605ac0);
