// batch54.cpp - name matching used by the hero update and the throw tree, inline session batch 54:
// striwcmp (wildcard, case-insensitive) and stricmpend (case-insensitive suffix compare).
// The CRT string functions are called through the exe's import slots, like crt::sqrt.
#include "ff.h"

typedef char *(__attribute__((cdecl)) *strchr_t)(const char *s, int c);
typedef int(__attribute__((cdecl)) *memicmp_t)(const void *a, const void *b, u32 n);
typedef int(__attribute__((cdecl)) *stricmp_t)(const char *a, const char *b);
#define CRT_STRCHR (*(strchr_t *)0x676254)
#define CRT_MEMICMP (*(memicmp_t *)0x67640c)
#define CRT_STRICMP (*(stricmp_t *)0x676414)

static inline s32 slen(const char *s) {
  const char *p = s;
  while (*p++)
    ;
  return (s32)(p - (s + 1));
}

// 0x4cc780 stricmpend(const char *s, const char *end), fastcall: 1 when s is shorter than end, else
// _stricmp(the last strlen(end) chars of s, end).
static int FASTCALL stricmpend(const char *s, const char *end) {
  u32 ls = (u32)slen(s);
  u32 le = (u32)slen(end);
  if (ls < le)
    return 1;
  return CRT_STRICMP(s + (slen(s) - slen(end)), end);
}
PCREG(4cc780, stricmpend);

extern "C" int FASTCALL ext_4cc780(const char *s, const char *end);
// 0x4cc850 striwcmp(const char *s, const char *pat), fastcall: 0 when s matches pat, where '*' matches any run of
// characters and letters compare without case. Returns 0 as soon as the pattern runs out (so pat matches any s it
// is a prefix of), -1 on a failed segment, and _stricmp / stricmpend results for the last literal piece.
static int FASTCALL striwcmp(const char *s, const char *pat) {
  for (;;) {
    if (*pat == 0)
      return 0;
    if (*pat == '*') {
      ++pat;
      const char *star = CRT_STRCHR(pat, '*');
      if (!star)
        return ext_4cc780(s, pat);
      s32 seg = (s32)(star - pat);
      if (seg == 0)
        return 0;
      s32 n = slen(s) - seg;
      if (n < 0)
        return -1;
      u32 tries = (u32)n + 1;
      u32 i = 0;
      if (tries == 0)
        return -1;
      for (;;) {
        if (CRT_MEMICMP(pat, s, (u32)seg) == 0)
          break;
        ++i;
        ++s;
        if (i == tries)
          return -1;
      }
      pat = star;
      continue;
    }
    const char *star = CRT_STRCHR(pat, '*');
    if (!star)
      return CRT_STRICMP(pat, s);
    s32 seg = (s32)(star - pat);
    if (CRT_MEMICMP(pat, s, (u32)seg) != 0)
      return -1;
    s += seg;
    pat = star;
  }
}
PCREG(4cc850, striwcmp);
