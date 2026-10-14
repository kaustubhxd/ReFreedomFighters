// batch38039.cpp - cascade s8 batch 38039: 0x42cce0 (read one possibly quoted token into a growable string).
#include "ff.h"

extern "C" void THISCALL ext_5f2d60(u32 *vec, u32 a, u32 b);      // ret 8: assign(a, b)
extern "C" void THISCALL ext_431270(u32 *vec, u32 newcap);        // ret 4: reserve
extern "C" u8 *THISCALL ext_6014a0(u32 *vec, u32 n);              // ret 4: allocate
extern "C" void THISCALL ext_54f870(u32 *vec, u8 *p, u32 n);      // ret 8: free

static inline bool is_ws0(u8 c) { return c == 0x20 || c == 9 || c == 0xd || c == 0xa || c == 0; }

// appends c to the string vec ({begin, end, cap end}); the string keeps a NUL right after its end.
static void push_plain(u32 *vec, u8 c) {
  u8 *end = (u8 *)vec[1];
  if (end + 1 == (u8 *)vec[2]) {
    u32 size = (u32)end - vec[0];
    u32 e = size < 1 ? 1 : size;
    ext_431270(vec, e - vec[0] + (u32)end);
  }
  u8 *z = (u8 *)vec[1] + 1;
  if (z) *z = 0;
  *(u8 *)vec[1] = c;
  vec[1]++;
}
static void push_quoted(u32 *vec, u8 c) {
  u8 *end = (u8 *)vec[1];
  if (end + 1 == (u8 *)vec[2]) {
    u32 size = (u32)end - vec[0];
    u32 cap = size < 1 ? 1 : size;
    cap = cap - vec[0] + (u32)end;
    if (cap < size) cap = size;
    cap += 1;
    u8 *nb = cap == 0 ? 0 : ext_6014a0(vec, cap);
    u8 *dst = nb;
    u8 *src = (u8 *)vec[0];
    s32 n = (s32)((u32)end - vec[0]);
    for (; n > 0; n--) *dst++ = *src++;
    if (dst) *dst = 0;
    u8 *old = (u8 *)vec[0];
    u32 oldsz = vec[2] - (u32)old;
    if (old && oldsz) ext_54f870(vec, old, oldsz);
    vec[0] = (u32)nb;
    vec[1] = (u32)dst;
    vec[2] = (u32)nb + cap;
  }
  u8 *z = (u8 *)vec[1] + 1;
  if (z) *z = 0;
  *(u8 *)vec[1] = c;
  vec[1]++;
}

// 0x42cce0, stdcall(cur, vec) ret 8. Clears vec (0x5f2d60 assign of the empty string 0x677b5a), skips blanks (space, tab, CR, LF) at *cur and then copies one token: characters up to the next
// blank / NUL, where a double-quoted part is copied without its quotes (and may contain blanks); *cur ends on the blank / NUL that ended the token. The string grows by doubling through
// 0x431270 (unquoted characters) or an inline reallocation with 0x6014a0 / 0x54f870 (quoted ones).
static void STDCALL fn42cce0(u8 **cur, u32 *vec) {
  ext_5f2d60(vec, 0x677b5a, 0x677b5a);
  if (**cur == 0) return;
  for (;;) {
    u8 c = **cur;
    if (!(c == 0x20 || c == 9 || c == 0xd || c == 0xa || c == 0)) break;
    (*cur)++;
    if (**cur == 0) return;
  }
  for (;;) {
    u8 bl = **cur;
    if (is_ws0(bl)) return;
    if (bl == '"') {
      (*cur)++;
      if (**cur != 0) {
        do {
          bl = **cur;
          if (bl == '"') break;
          (*cur)++;
          push_quoted(vec, bl);
        } while (**cur != 0);
      }
      if (**cur != 0) (*cur)++;
      continue;
    }
    push_plain(vec, bl);
    (*cur)++;
  }
}
PCREG(42cce0, fn42cce0);
