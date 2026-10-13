// batch19.cpp - first-level functions, inline session batch 19 (Haiku, overnight).
#include "ff.h"

static inline bool isSpaceByte(u8 c) { return c == ' ' || c == 9 || c == 0xd || c == 0xa; }

// 0x42f840, fastcall (string in ECX, plain ret): strips trailing space, tab, CR and LF by writing NULs. The first byte
// is never examined, so a one-character string is left alone. Name unknown.
static void FASTCALL trimTail(u8 *s) {
  u32 len = 0;
  while (s[len] != 0)
    len++;
  if (len == 0)
    return;
  u8 *p = s + len - 1;
  while (p != s) {
    if (!isSpaceByte(*p))
      break;
    *p = 0;
    p--;
  }
}
PCREG(42f840, trimTail);

// 0x42c130, fastcall (dst in ECX, src in EDX, returns the source position in EAX): skips leading white space, copies
// bytes up to the next white space or NUL into dst, writes a NUL to dst and returns the position of the stop byte.
// Name unknown.
static u8 *FASTCALL copyToken(u8 *dst, u8 *src) {
  u8 *s = src;
  while (isSpaceByte(*s))
    s++;
  if (*s != 0) {
    while (*s != 0 && !isSpaceByte(*s)) {
      *dst++ = *s++;
    }
  }
  *dst = 0;
  return s;
}
PCREG(42c130, copyToken);

// 0x430cd0, thiscall (ret 8), two stack args: ch (only its low byte is used) and start. self holds [begin, end). Returns
// the offset of the first byte equal to ch at or after start, or -1 when start is past the end, or when there is no
// match. Name unknown.
static s32 THISCALL findByteFrom(u8 *self, u32 ch, u32 start) {
  u32 begin = *(u32 *)self;
  u32 end = *(u32 *)(self + 4);
  u32 avail = end - begin;
  if (start >= avail)
    return -1;
  u32 p = begin + start;
  if (p == end)
    return -1;
  u8 want = (u8)ch;
  do {
    if (*(u8 *)(unsigned long)p == want)
      break;
    p++;
  } while (p != end);
  if (p == end)
    return -1;
  return (s32)(p - begin);
}
PCREG(430cd0, findByteFrom);
