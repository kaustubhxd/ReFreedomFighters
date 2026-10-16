// batch220016.cpp - Codex-x3a manual port of ResourceCollection::Lookup.
#include "ff.h"

typedef s32 (*strnicmp_t)(const char *, const char *, u32);

static inline u32 rd32_49e140(const u8 *p) {
  u32 v;
  __builtin_memcpy(&v, p, sizeof v);
  return v;
}

static inline s32 nicmp_49e140(const u8 *a, const u8 *b, u32 n) {
  return G(strnicmp_t, 0x676408)((const char *)a, (const char *)b, n);
}

// 0x49e140 ResourceCollection::Lookup(this, name, encoded tree), thiscall ret 8.
// Each node is { count:u8, offsets[count-1]:u32, entries... }.  Entry zero
// begins immediately after the final offset; each later offset is relative to
// that address.  A matched entry is followed by either NUL or '/' plus its
// child node.
extern "C" u32 THISCALL lifted_49e140(u32 self_unused, u32 name_arg, u32 data_arg) {
  (void)self_unused;
  const u8 *s = (const u8 *)name_arg;
  u8 *data = (u8 *)data_arg;
  for (;;) {
    if (s[0] == '/') {  // @slash_49e140
      do { ++s; } while (s[0] == '/');
    }

    u32 width = 0;
    while (s[width] && s[width] != '/') ++width;  // @span_49e140

    u32 count = data[0];
    u32 base = (u32)data + count * 4 - 3;
    u32 low = 0;
    u32 remaining = count;
    while ((s32)remaining > 0) {
      u32 mid = remaining >> 1;
      u32 index = low + mid;
      u32 rel = index ? rd32_49e140(data + 1 + (index - 1) * 4) : 0;
      s32 r = nicmp_49e140((const u8 *)(base + rel), s, width);
      if (r < 0) {  // @lower_49e140
        low = index + 1;  // @low_49e140
        remaining -= mid + 1;  // @remaining_49e140
      } else {
        remaining = mid;
      }
    }

    u32 chosen = count * 4 - 3 + (low ? rd32_49e140(data + 1 + (low - 1) * 4) : 0);
    if ((s32)low >= (s32)count) return 0;
    if (nicmp_49e140((const u8 *)((u32)data + chosen), s, width) != 0) return 0;  // @final_cmp_49e140

    s += width;
    data = (u8 *)((u32)data + chosen + width + 1);  // @next_data_49e140
    if (s[0] == 0) {
      if (data[-1] == 0) return (u32)data;  // @terminal_49e140
      return 0;
    }
    s = s + 1;  // @skip_sep_49e140
  }
}
PCREG(49e140, lifted_49e140);
