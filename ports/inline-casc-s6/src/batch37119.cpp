// batch37119.cpp - cascade s6 batch 37119: 0x57d200.
#include "ff.h"

typedef char *(*strchr_t)(const char *, int);               // cdecl, through the IAT
typedef int (*strnicmp_t)(const char *, const char *, u32);   // cdecl, through the IAT
#define IAT(T, a) (*(T *)(a))

static u32 slen(const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x57d200, fastcall(str, out), returns the number of tokens resolved: parses up to four comma-separated names from `str` (each token is looked up, case-insensitively, in the
// groups of 12-byte {name, ...} entries hanging off the 16-byte records of the table at engine+0x190b; the result is the group's id (+0) plus the entry index, or'ed with
// 0x420000, and -1 when unknown) into out[0..3]. Faithful quirk: the cursor is set to the token's END (the comma itself), so a token followed by a comma is looked up again
// as an empty / comma-led token on the next round (whose length is then the rest of the string including the NUL).
static u32 FASTCALL fn57d200(const char *str, u32 *out) {
  u32 j = 0, found = 0;
  while (*str) {
    const char *p = IAT(strchr_t, 0x676254)(str, 0x2c);
    if (!p) p = str + slen(str);
    u32 len = (u32)(p - str);
    if (len == 0) len = slen(str) + 1;
    u32 code = 0xffffffffu;
    u8 *T = *(u8 **)(*(u8 **)0x70039c + 0x190b);
    for (u32 g = 0; *(u32 *)(T + g * 16 + 8) != 0; g++) {
      u8 *arr = *(u8 **)(T + g * 16 + 8);
      bool hit = false;
      for (u32 e = 0; *(u32 *)(arr + e * 12) != 0; e++) {
        const char *name = *(const char **)(arr + e * 12);
        if (slen(name) == len && IAT(strnicmp_t, 0x67640c)(name, str, len) == 0) {
          code = (*(u32 *)(T + g * 16) + e) | 0x420000u;
          hit = true;
          break;
        }
      }
      if (hit) break;
    }
    out[j++] = code;
    if (code != 0xffffffffu) found++;
    str = p;
    if (j >= 4) break;
  }
  return found;
}
PCREG(57d200, fn57d200);
