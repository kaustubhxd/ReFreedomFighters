// batch4111.cpp - unclaimed-41 batch 11 (slice 13): 0x5fa0d0, a linear name lookup (name not in the map; GUESS).
#include "ff.h"

// 0x5fa0d0 (GUESS name): thiscall, two stack arguments (s = a C string, flag; ret 8). Returns the index of the first entry whose
// stored name equals s, or -1. Entries: t = [this+4]; n = [t+0x14]; arr = [t+0xc]; entry e = arr[i] with e[0] = start P and
// e[4] = end Q (L = Q - P). An entry matches when the first min(len, L) bytes are equal and L == len (len = strlen(s)).
// If the flag byte is set and not found, the error hook at 0x7003b0 is called (no arguments) and -1 is returned.
// The exe traps (int3) when the flag is set and the hook pointer is zero; the port cannot model that, so the spec keeps the hook set.
static u32 THISCALL findName5fa0d0(u8 *self, u8 *s, u32 flag) {
  u8 *t = *(u8 **)(self + 4);
  u32 n = *(u32 *)(t + 0x14);
  s32 len = 0;
  while (s[len] != 0)
    len++;
  for (u32 i = 0; i < n; i++) {
    u8 *arr = *(u8 **)(t + 0xc);
    u8 *e = *(u8 **)(arr + 4 * i);
    u8 *p = *(u8 **)e;
    s32 L = (s32)((u32)*(u8 **)(e + 4) - (u32)p);
    s32 m = len < L ? len : L;
    int cmp = 0;
    for (s32 k = 0; k < m; k++) {
      if (p[k] != s[k]) {
        cmp = (p[k] < s[k]) ? -1 : 1;
        break;
      }
    }
    if (cmp != 0)
      continue;
    if (L < len)
      continue;
    if (L == len)
      return i;
  }
  if ((u8)flag != 0) {
    void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
    hook();
  }
  return 0xffffffffu;
}
PCREG(5fa0d0, findName5fa0d0);
