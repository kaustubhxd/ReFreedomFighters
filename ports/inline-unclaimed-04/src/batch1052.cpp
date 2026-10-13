// batch1052.cpp - unclaimed-04 batch 52 (docs/20-unclaimed-04.md): 0x622cb0 (residue 3).
// cdecl (state, &from, fromEnd, &to, toEnd). Copies as many bytes as fit; when the source is cut short, the cut moves back
// over UTF-8 continuation bytes so no character is split. GUESS: a UTF-8 passthrough codecvt::do_out (state unused).
// The exe leaves the &to argument in eax; the port returns it so the harness can compare eax.
#include "ff.h"

// 0x622cb0
static u8 **__attribute__((cdecl)) unk622cb0Utf8Copy(void *state, const u8 **pFrom, const u8 *fromEnd, u8 **pTo, u8 *toEnd) {
  (void)state;
  const u8 *from = *pFrom;
  u8 *to = *pTo;
  const u8 *end = fromEnd;
  if ((s32)(fromEnd - from) > (s32)(toEnd - to)) {
    end = from + (toEnd - to);
    while (end > from && (end[-1] & 0xc0) == 0x80) end--;
  }
  u32 n = from > end ? 0 : (u32)(end - from);
  // byte by byte, forward (overlapping buffers copy the way the exe does)
  for (u32 i = 0; i != n; i++) *to++ = *from++;
  *pFrom = from;
  *pTo = to;
  return pTo;
}
PCREG(622cb0, unk622cb0Utf8Copy);
