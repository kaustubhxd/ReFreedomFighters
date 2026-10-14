// batch36080.cpp - cascade s4 batch 36080: 0x604f50 (tier F row).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v0u_t)(void *);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4
extern "C" u8 *ext_41e290(u32 n);                         // cdecl
extern "C" void ext_634273(void *p, u32 flag);            // cdecl

static u32 slen(const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x604f50, thiscall(p) ret 4 (this = d): s = *(char **)*0x5003d0(p[4], 0); when slen(s) > (u16)d[0x10] - 1 (32-bit, unsigned):
// 0x634273(d[0xc], 1); n = slen(*(char **)*0x5003d0(p[4], 0)) + 1; d[0x10] = (u16)n; d[0xc] = 0x41e290((u16)n).
// Then copy the string (with NUL) of a fresh *0x5003d0(p[4], 0) to d[0xc]. rec = 0x5003d0(p[8], 0): tag rec[4]: 0 -> skip the release, 4 -> (*rec)->slot 0x28(*rec),
// any other -> return. Then rec[0] = d->slot 0x24(d), rec[4] = 4.
static void THISCALL fn604f50(u8 *d, u8 *p) {
  const char *s = *(const char **)ext_5003d0(*(u8 **)(p + 4), 0);
  u32 len = slen(s);
  u32 cap = *(u16 *)(d + 0x10);
  if (len > cap - 1) {
    ext_634273(*(void **)(d + 0xc), 1);
    const char *s2 = *(const char **)ext_5003d0(*(u8 **)(p + 4), 0);
    u16 n = (u16)(slen(s2) + 1);
    *(u16 *)(d + 0x10) = n;
    wr(d + 0xc, (u32)ext_41e290(n));
  }
  const char *src = *(const char **)ext_5003d0(*(u8 **)(p + 4), 0);
  char *dst = *(char **)(d + 0xc);
  char ch;
  do {
    ch = *src++;
    *dst++ = ch;
  } while (ch);
  u8 *rec = ext_5003d0(*(u8 **)(p + 8), 0);
  u8 tag = rec[4];
  if (tag) {
    if (tag != 4) return;
    u8 *old = *(u8 **)rec;
    (*(v0_t **)old)[0x28 / 4](old);
  }
  u32 v = (*(v0u_t **)d)[0x24 / 4](d);
  wr(rec, v);
  rec[4] = 4;
}
PCREG(604f50, fn604f50);
