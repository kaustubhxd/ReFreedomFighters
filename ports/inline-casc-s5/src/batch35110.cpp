// batch35110.cpp - cascade s5 batch 35110: 0x5b6a30 (GUESS destroy the list at +0x48 and every pair of objects it holds).
#include "ff.h"

typedef void(THISCALL *v1p_t)(void *, void *);
typedef u8 *(THISCALL *g1p_t)(void *, void *);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x5b6a30, thiscall, no arguments. L = [this+0x48] (re-read before each use; null: just clears the field). L slot 0x4c(&it); for each entry p from L slot 0x64(&it): the objects [p+4] and [p+8] are deleted (slot 0 with 1) when non-null.
// Afterwards L (re-read) slot 0(1) when still set and [this+0x48] = 0.
static void THISCALL fn5b6a30(u8 *self) {
  u32 it[3];
  u8 *L = *(u8 **)(self + 0x48);
  if (L) {
    (*(v1p_t **)L)[0x4c / 4](L, it);
    L = *(u8 **)(self + 0x48);
    u8 *p = (*(g1p_t **)L)[0x64 / 4](L, it);
    while (p) {
      u8 *a = *(u8 **)(p + 4);
      if (a) (*(v1_t **)a)[0](a, 1);
      u8 *b = *(u8 **)(p + 8);
      if (b) (*(v1_t **)b)[0](b, 1);
      L = *(u8 **)(self + 0x48);
      p = (*(g1p_t **)L)[0x64 / 4](L, it);
    }
    L = *(u8 **)(self + 0x48);
    if (L) (*(v1_t **)L)[0](L, 1);
  }
  *(u32 *)(self + 0x48) = 0;
}
PCREG(5b6a30, fn5b6a30);
