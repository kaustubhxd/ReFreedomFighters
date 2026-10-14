// batch35074.cpp - cascade s5 batch 35074: 0x4d40f0 (GUESS printf into a ring of 1000 message buffers, keeping the text after the first ')').
#include "ff.h"

extern "C" void ext_42abee(char *buf, const char *fmt, u32 *va);   // cdecl, vsprintf-style
typedef char *(*strchr_t)(const char *, int);
typedef char *(*strncpy_t)(char *, const char *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4d40f0, cdecl(this, fmt, ...), plain ret. A format shorter than 0x400 characters is expanded by 0x42abee(buf, fmt, address of the first variable argument); p = strchr(buf, ')') (IAT 0x676254) and
// text = p + 1 (buf when there is none); with idx = unaligned dword [this+0xfaf] and entry = unaligned dword [this + 4 * idx + 0xf]: strncpy(entry, text, 0x95) (IAT 0x67642c); entry (re-read) byte 0x95 = 0;
// idx + 1 is stored back, wrapping to 0 at 0x3e8.
static void fn4d40f0(u8 *self, const char *fmt, u32 va0) {
  char buf[0x400];
  const char *q = fmt;
  while (*q++) {}
  if ((u32)(q - fmt - 1) >= 0x400) return;
  ext_42abee(buf, fmt, &va0);
  char *p = G(strchr_t, 0x676254)(buf, 0x29);
  const char *text = p ? p + 1 : buf;
  u32 idx = rd32u(self + 0xfaf);
  G(strncpy_t, 0x67642c)((char *)rd32u(self + idx * 4 + 0xf), text, 0x95);
  idx = rd32u(self + 0xfaf);
  ((u8 *)rd32u(self + idx * 4 + 0xf))[0x95] = 0;
  wr32u(self + 0xfaf, rd32u(self + 0xfaf) + 1);
  if (rd32u(self + 0xfaf) == 0x3e8) wr32u(self + 0xfaf, 0);
}
PCREG(4d40f0, fn4d40f0);
