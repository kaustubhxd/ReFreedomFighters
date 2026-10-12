// batch6330.cpp - unclaimed-63 gap-band batch 30: 0x4cc630 (A+D+E set; no GC name), thiscall, one stack argument s (a C string),
// ret 4. n = strlen(s). If n + 1 <= 0x7c the buffer is the inline bytes at this+4; else it is 0x41e290(n + 1) (cdecl allocation,
// original, stubbed by the spec). [this] = buffer; the string including its NUL is copied into the buffer.
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);   // cdecl allocation, original, stubbed by the spec

// 0x4cc630 (A+D+E set).
static void THISCALL unnamed4cc630(u8 *self, const u8 *s) {
  u32 n = 0;
  while (s[n] != 0)
    n++;
  u8 *dst;
  if (n + 1 <= 0x7cu)
    dst = self + 4;
  else
    dst = (u8 *)ext_41e290(n + 1);
  *(u32 *)self = (u32)dst;
  for (u32 i = 0; i <= n; i++)
    dst[i] = s[i];
}
PCREG(4cc630, unnamed4cc630);
