#include "ff.h"
// batch915.cpp - unclaimed-01 claim 14 (docs/20-unclaimed-01.md). Address 0x4a1c80. The GC name map says
// CAction::InRange(ZGEOM*) (medium), but the body copies two null-terminated strings into allocations from the global
// allocator. GUESS: named CAction::SetStrings here; the map's name does not fit the code.

static u32 slotOf(u8 *o, u32 off) {
  return *(u32 *)(*(u32 *)o + off);
}

static u32 strlenPC(const u8 *s) {
  u32 n = 0;
  while (s[n] != 0)
    n++;
  return n;
}

// thiscall (this, a1, a2), void, ret 8. Frees the old pointer at +0x7a (allocator slot +0xfc), copies a1 into a new
// allocation (allocator slot +0xf8, length + 1) and stores it at +0x7a; a null a1 clears +0x7a instead. A non-null a1
// with a null a2 returns there. Otherwise the a2 part runs: a non-null a2 frees the old pointer at +0x76 first; a null a2
// (reached only when a1 is null) is measured and copied from address 0, as the exe does (its copy reads [edx] with
// edx = 0). The result goes to +0x76.
static void THISCALL actionSetStrings(u8 *self, const u8 *a1, const u8 *a2) {
  u8 *alloc = G(u8 *, 0x70039c);
  typedef void(THISCALL * free_fn)(u8 *, u32);
  typedef u32(THISCALL * alloc_fn)(u8 *, u32);
  u32 old = *(u32 *)(self + 0x7a);
  if (old != 0)
    ((free_fn)slotOf(alloc, 0xfc))(alloc, old);
  if (a1 != 0) {
    u32 n = strlenPC(a1);
    u8 *p = (u8 *)((alloc_fn)slotOf(alloc, 0xf8))(alloc, n + 1);
    *(u32 *)(self + 0x7a) = (u32)p;
    for (u32 i = 0; i <= n; i++)
      p[i] = a1[i];
    if (a2 == 0)
      return;
  } else {
    *(u32 *)(self + 0x7a) = 0;
  }
  if (a2 != 0) {
    u32 old2 = *(u32 *)(self + 0x76);
    if (old2 != 0)
      ((free_fn)slotOf(alloc, 0xfc))(alloc, old2);
  }
  const volatile u8 *src = a2 != 0 ? (const volatile u8 *)a2 : (const volatile u8 *)0;
  u32 n2 = 0;
  while (src[n2] != 0)
    n2++;
  u8 *q = (u8 *)((alloc_fn)slotOf(alloc, 0xf8))(alloc, n2 + 1);
  *(u32 *)(self + 0x76) = (u32)q;
  for (u32 i = 0; i <= n2; i++)
    q[i] = src[i];
}
PCREG(4a1c80, actionSetStrings);
