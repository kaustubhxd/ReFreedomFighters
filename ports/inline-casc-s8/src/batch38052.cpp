// batch38052.cpp - cascade s8 batch 38052: 0x430d10 (std::string::insert(pos, first, last)).
#include "ff.h"

extern "C" u8 *THISCALL ext_6014a0(u32 *s, u32 n);               // allocate, ret 4
extern "C" void THISCALL ext_54f870(u32 *s, u8 *p, u32 n);       // free, ret 8
extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // memcpy, cdecl
typedef void (*memmove_t)(void *, const void *, u32);
#define imp_memmove G(memmove_t, 0x676278)

// 0x430d10, thiscall(pos, first, last) ret 0xc. The string is {+0 begin, +4 end, +8 capacity end} with a NUL at the end pointer; inserts the bytes [first, last) at pos. With room for n + 1 more bytes the
// tail (and NUL) is shifted up in place (two cases: tail >= n or tail < n), otherwise a new buffer of max(size, n) + 1 + size bytes is allocated (0x6014a0), prefix / new text / suffix are copied, the NUL is
// written, the old buffer is released (0x54f870) and the fields replaced. Nothing happens when first == last.
static void THISCALL fn430d10(u32 *s, u8 *pos, u8 *first, u8 *last) {
  if (first == last) return;
  s32 n = (s32)(last - first);
  s32 freesp = (s32)(s[2] - s[1]);
  if (freesp >= n + 1) {
    s32 tail = (s32)(s[1] - (u32)pos);
    u8 *e = (u8 *)s[1];
    if (tail >= n) {
      u8 *src = e - n + 1;
      u8 *dst = e + 1;
      for (s32 k = (s32)(e - src) + 1; k > 0; k--) *dst++ = *src++;
      s[1] += n;
      imp_memmove(pos + n, pos, (u32)(tail - n + 1));
      ext_634d22(pos, first, (u32)n);
    } else {
      imp_memmove(e + 1, first + tail + 1, (u32)(last - (first + tail + 1)));
      s[1] += (u32)(n - tail);
      u8 *d = (u8 *)s[1];
      u8 *p = pos;
      for (s32 k = (s32)(e - pos) + 1; k > 0; k--) *d++ = *p++;
      s[1] += (u32)tail;
      ext_634d22(pos, first, (u32)(tail + 1));
    }
    return;
  }
  u32 size = s[1] - s[0];
  u32 cap = (size < (u32)n ? (u32)n : size) + 1 + size;
  u8 *nb = cap == 0 ? 0 : ext_6014a0(s, cap);
  u8 *d = nb;
  u8 *b = (u8 *)s[0];
  for (s32 k = (s32)(pos - b); k > 0; k--) *d++ = *b++;
  imp_memmove(d, first, (u32)n);
  s32 suf = (s32)(s[1] - (u32)pos);
  d = d - (u32)first + (u32)last;
  if (suf > 0) {
    u8 *p = pos;
    for (; suf > 0; suf--) *d++ = *p++;
  }
  if (d) *d = 0;
  u8 *ob = (u8 *)s[0];
  u32 osz = s[2] - (u32)ob;
  if (ob && osz) ext_54f870(s, ob, osz);
  s[0] = (u32)nb;
  s[1] = (u32)d;
  s[2] = (u32)nb + cap;
}
PCREG(430d10, fn430d10);
