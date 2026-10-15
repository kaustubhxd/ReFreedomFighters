// batch36086.cpp - cascade s4 batch 36086: 0x4d4300 (tier F row).
#include "ff.h"

typedef s32(*nicmp_t)(const char *, const char *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *ext_41e290(u32 n);                 // cdecl
extern "C" void ext_634273(void *p, u32 flag);    // cdecl

static u32 slen(const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x4d4300, thiscall(str) ret 4 (this = t): t[0xc] set -> 0x634273(t[0xc], 1), t[0xc] = 0. str == 0 -> return 0.
// Otherwise t[0xc] = copy of str (0x41e290(len + 1)); t[0x10] = 0; for t[0x10] < t[8] (unsigned, at least once when t[8] != 0): p = t[4][t[0x10]];
// _strnicmp(t[0xc], p, strlen(t[0xc])) == 0 -> return p. End -> 0.
static u32 THISCALL fn4d4300(u8 *t, const char *str) {
  if (rd(t + 0xc)) {
    ext_634273(*(void **)(t + 0xc), 1);
    wr(t + 0xc, 0);
  }
  if (!str) return 0;
  char *buf = (char *)ext_41e290(slen(str) + 1);
  wr(t + 0xc, (u32)buf);
  const char *src = str;
  char ch;
  do {
    ch = *src++;
    *buf++ = ch;
  } while (ch);
  wr(t + 0x10, 0);
  if (!rd(t + 8)) return 0;
  do {
    const char *p = (const char *)(*(u32 **)(t + 4))[rd(t + 0x10)];
    const char *s = *(const char **)(t + 0xc);
    if (G(nicmp_t, 0x676408)(s, p, slen(s)) == 0) return (u32)p;
    wr(t + 0x10, rd(t + 0x10) + 1);
  } while (rd(t + 0x10) < rd(t + 8));
  return 0;
}
PCREG(4d4300, fn4d4300);
