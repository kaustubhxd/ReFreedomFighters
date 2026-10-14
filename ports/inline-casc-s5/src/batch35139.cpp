// batch35139.cpp - cascade s5 batch 35139: 0x602160 (GUESS match a name against the pattern *s*).
#include "ff.h"

extern "C" u32 FASTCALL ext_4cc850(u32 a, const char *pat);   // fastcall (ecx, edx), plain ret
typedef char *(*strncpy_t)(char *, const char *, u32);

// 0x602160, stdcall(a, s) ret 8, returns EAX. len = strlen(s) (signed compare); len > 0x3e8 gives -1. Otherwise the pattern "*" + s + "*" is built in a 0x400-byte local (strncpy through the IAT at 0x67642c copies the len bytes after
// the leading star) and the result of 0x4cc850(a, pattern) is returned.
static u32 STDCALL fn602160(u32 a, const char *s) {
  char buf[0x400];
  const char *q = s;
  while (*q++) {}
  s32 len = (s32)(q - s - 1);
  if (len > 0x3e8) return 0xffffffff;
  G(strncpy_t, 0x67642c)(buf + 1, s, (u32)len);
  buf[0] = '*';
  buf[len + 1] = '*';
  buf[len + 2] = 0;
  return ext_4cc850(a, buf);
}
PCREG(602160, fn602160);
