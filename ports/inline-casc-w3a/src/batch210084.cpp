// batch210084.cpp - Sonnet-w3a: 0x635380 (look a name up in the 78-entry packed table at 0x6f5728 with the string-compare import)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

typedef int (*StrCmp)(const u8 *a, const u8 *b);

static u32 STDCALL fn635380(const u8 *name) {
  const u8 *tbl = (const u8 *)0x6f5728;
  for (u32 i = 0; i != 0x186 / 5; i++) {  // @635380_a
    if (G(StrCmp, 0x676414)(name, (const u8 *)ld32(tbl + i * 5 + 1)) == 0)  // @635380_b
      return tbl[i * 5];  // @635380_c
  }
  return 0;
}
PCREG(635380, fn635380);
