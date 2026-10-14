// batch37022.cpp - cascade s6 batch 37022: 0x4ed1d0.
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *v6_t)(void *, u32, u32, u32, u32, u32, u32);

// 0x4ed1d0, thiscall(arr, end, a10, n, a18) ret 0x14: gathers up to n entries into the pointer array arr through slot 0x18 of this (slot 0x14 as a fallback when it
// yields 0) with the object at this+0x1a1; when more than one entry results, drops every entry that is a descendant (parent chain via slot 0x20, depth via slot 0x260)
// of another one by zeroing it, compacts the array and returns the number of entries left (the count before that when it is 0 or 1).
static u32 THISCALL fn4ed1d0(u8 *self, u32 *arr, u32 end, u32 a10, u32 n, u32 a18) {
  u32 obj = *(u32 *)(self + 0x1a1);
  if (!obj) return 0;
  if (!(end > (u32)arr)) return 0;
  u32 cnt = (*(v4_t **)self)[0x18 / 4](self, (u32)arr, end, obj, n);
  if (cnt == 0) {
    cnt = (*(v6_t **)self)[0x14 / 4](self, (u32)arr, end, *(u32 *)(self + 0x1a1), a10, n, a18);
  }
  if ((s32)cnt <= 1) return cnt;
  u32 *p = arr;
  for (u32 j = cnt; j; j--, p++) {
    u8 *A = (u8 *)*p;
    if (!A) continue;
    u32 key = (*(v0_t **)A)[0x260 / 4](A);
    for (u32 i = 0; i != cnt; i++) {
      u32 *slot = arr + i;
      u8 *B = (u8 *)*slot;
      if (!B) continue;
      u32 k2 = (*(v0_t **)B)[0x260 / 4](B);
      if (k2 == key) continue;
      if (key < k2) {
        u8 *b = B;
        for (u32 d = k2 - key; d; d--) b = (u8 *)(*(v0_t **)b)[0x20 / 4](b);
        if (b == A) *p = 0;
      } else {
        u8 *a = A;
        for (u32 d = key - k2; d; d--) a = (u8 *)(*(v0_t **)a)[0x20 / 4](a);
        if (a == B) *slot = 0;
      }
    }
  }
  u32 w = 0;
  for (u32 r = 0; r != cnt; r++)
    if (arr[r]) arr[w++] = arr[r];
  return w;
}
PCREG(4ed1d0, fn4ed1d0);
