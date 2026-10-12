// batch271.cpp - unclaimed area 67, GUESS name for 0x4d4960 (cursor search over a string array).
#include "ff.h"

typedef int(__attribute__((cdecl)) * nicmp_t)(const char *, const char *, u32);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline void wrw(u32 p, u32 off, u32 v) { *(u32 *)(unsigned long)(p + off) = v; }

// 0x4d4960, thiscall, plain ret. See docs/20-unclaimed-67.md batch 271.
static u32 THISCALL cursorSearch(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 s = rdw(self, 0xc);
  if (s == 0)
    return 0;
  u32 n = rdw(self, 0x10);
  wrw(self, 0x10, n - 1);
  if (n == 0) {
    wrw(self, 0x10, 0);
    return 0;
  }
  u32 arr = rdw(self, 4);
  u32 e = rdw(arr, (n - 1) * 4);
  u32 len = 0;
  while (((const char *)(unsigned long)s)[len] != 0)
    len++;
  if ((*(nicmp_t *)0x676408)((const char *)(unsigned long)s, (const char *)(unsigned long)e, len) == 0)
    return e;
  wrw(self, 0x10, rdw(self, 0x10) + 1);
  return 0;
}
PCREG(4d4960, cursorSearch);
