// batch3015.cpp - unclaimed-30: batch 15 (docs/20-unclaimed-30.md, claim 1). Unnamed in the name map: 0x4d2cd0 [thiscall, ret 8].
// Calls this's slot 0xb0 with (a1, 0). A null result returns 0. Otherwise, unless the flag byte +0x10 of the object at result+4 has bit 4, the debug
// reporter's slot 0x24 gets (format 0x696394, a1); then the result's data (at result + [result] + 0xc, n = result+8 bytes) is copied to
// the destination (the second argument), and n is returned. The copy is memcpy (an import in the exe).
#include "ff.h"

typedef void (*reportFn)(void *, const char *, u32);

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL unnamed4d2cd0(u8 *self, u32 a1, u8 *dst) {
  u8 *r = (u8 *)vcall<u32>(self, 0xb0, a1, (u32)0);
  if (!r) return 0;
  u8 *q = (u8 *)rd32u(r + 4);
  if (!(q[0x10] & 4)) {
    void *rep = (void *)G(u8 *, 0x700390);
    reportFn f = *(reportFn *)(*(u8 **)rep + 0x24);
    f(rep, (const char *)0x696394, a1);
  }
  u32 n = rd32u(r + 8);
  const u8 *src = r + rd32u(r) + 0xc;
  for (u32 i = 0; i < n; i++) dst[i] = src[i];   // the exe's memcpy (import), byte by byte
  return n;
}
PCREG(4d2cd0, unnamed4d2cd0);
