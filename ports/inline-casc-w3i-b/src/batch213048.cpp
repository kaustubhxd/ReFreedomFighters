#include "ff.h"

// 0x623080 (LE pairs) and 0x623940 (BE pairs): cdecl(unused, u8 **in, u8 *in_end, u8 **out, u8 *out_end): converts UTF-16 pairs to UTF-8: ASCII (1 byte), hi 1..7
// (2 bytes), hi 8..0xd7 and above 0xdb (3 bytes), hi 0xd8..0xdb (surrogate pair, 4 bytes); stops (storing the unconsumed position in *in) when the output has too
// little room for the next character or the input is used up
template <bool LE>
static void utf16_to_utf8(u8 **in, u8 *in_end, u8 **out, u8 *out_end) {
  u8 *p = *in;
  if (p == in_end) {
    *in = p;
    return;
  }
  do {
    u32 hi = LE ? p[1] : p[0];
    u32 lo = LE ? p[0] : p[1];
    if (hi == 0 && lo < 0x80) {
      if (*out == out_end) goto done;
      **out = (u8)lo;
    } else if (hi >= 1 && hi <= 7) {
      if ((s32)(out_end - *out) < 2) goto done;
      **out = (u8)(0xc0 | (hi << 2) | (lo >> 6));
      ++*out;
      **out = (u8)((lo & 0x3f) | 0x80);
    } else if (hi == 0) {
      if ((s32)(out_end - *out) < 2) goto done;
      **out = (u8)(0xc0 | (lo >> 6));
      ++*out;
      **out = (u8)((lo & 0x3f) | 0x80);
    } else if (hi >= 0xd8 && hi <= 0xdb) {
      if ((s32)(out_end - *out) < 4) goto done;
      u32 w = (((hi & 3) << 2) | (lo >> 6)) + 1;
      u8 lo0 = (u8)lo;
      **out = (u8)(0xf0 | (w >> 2));
      ++*out;
      **out = (u8)(0x80 | ((w & 3) << 4) | ((lo0 >> 2) & 0xf));
      ++*out;
      p += 2;
      u32 hi1 = LE ? p[1] : p[0];
      u32 lo1 = LE ? p[0] : p[1];
      **out = (u8)(0x80 | ((lo0 & 3) << 4) | ((hi1 & 3) << 2) | (lo1 >> 6));
      ++*out;
      **out = (u8)((lo1 & 0x3f) | 0x80);
    } else {
      if ((s32)(out_end - *out) < 3) goto done;
      **out = (u8)(0xe0 | (hi >> 4));
      ++*out;
      **out = (u8)(0x80 | ((hi & 0xf) << 2) | (lo >> 6));
      ++*out;
      **out = (u8)((lo & 0x3f) | 0x80);
    }
    ++*out;
    p += 2;
  } while (p != in_end);
done:
  *in = p;
}

extern "C" void fn_623080(u32 unused, u8 **in, u8 *in_end, u8 **out, u8 *out_end) { (void)unused; utf16_to_utf8<true>(in, in_end, out, out_end); }
PCREG(623080, fn_623080);
extern "C" void fn_623940(u32 unused, u8 **in, u8 *in_end, u8 **out, u8 *out_end) { (void)unused; utf16_to_utf8<false>(in, in_end, out, out_end); }
PCREG(623940, fn_623940);
