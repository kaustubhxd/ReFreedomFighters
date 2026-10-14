// batch38032.cpp - cascade s8 batch 38032: 0x4f9350 (sort keyed records and group them by key).
#include "ff.h"

extern "C" void THISCALL ext_4f9520(u8 *rec, u32 size);   // ret 4
typedef void (*qsort_t)(void *, u32, u32, void *);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v1_t)(void *, u32);
#define imp_qsort G(qsort_t, 0x676450)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
static u8 *factory() {
  u8 *o = *(u8 **)(ENG + 0x1aa3);
  return *(u8 **)(o + 0x18);
}

// 0x4f9350, fastcall(pairs = ECX, recs = EDX; out1, out2, n, arg, owner) ret 0x14, returns the number of key groups. pairs are n (key, source index) dwords-pairs that are sorted by key through the
// qsort import (comparator 0x4f9510 = a[0] - b[0]); recs are n records of 0x28 bytes. Every position whose source index chain leads to a different record than itself gets 0x4f9520(record, 0x28).
// The number of key changes (starting from key 0) is the group count; when *out1 is null both output tables are fetched from the engine's object (+0x1aa3 -> +0x18, slots 0x34 / 0x38
// with the group count). Then every run of equal keys gets a handle (owner slot 0x218 or the engine object's slot 0x108 with (key, arg, 5)) stored in table 1 and a (count, first record) pair
// in table 2.
static u32 FASTCALL fn4f9350(u8 *A, u8 *B, u32 **out1, u32 **out2, u32 n, u32 arg, u8 *owner) {
  if (n == 0) return 0;
  imp_qsort(A, n, 8, (void *)0x4f9510);
  u32 *pairs = (u32 *)A;
  for (u32 i = 0; i < n; i++) {
    u32 j = pairs[2 * i + 1];
    if (j < i) {
      do {
        j = pairs[2 * j + 1];
      } while (j < i);
    }
    if (j != i) ext_4f9520(B + j * 0x28, 0x28);
  }
  u32 groups = 0, last = 0;
  for (u32 k = 0; k < n; k++) {
    if (last != pairs[2 * k]) {
      groups++;
      last = pairs[2 * k];
    }
  }
  if (groups == 0) return 0;
  if (*out1 == 0) {
    u8 *f = factory();
    *(u32 *)out1 = SLOT(f, 0x34, v1_t)(f, groups);
    f = factory();
    *(u32 *)out2 = SLOT(f, 0x38, v1_t)(f, groups);
  }
  u8 *bcur = B;
  u32 run = 0, lastKey = 0, outOff = 0, outIdx = 0;
  for (u32 k = 0; k <= n; k++) {
    u32 flag;
    if (k == n) {
      if (run != 0) *(u32 *)((u8 *)*out2 + outOff - 8) = run;
      outIdx += 4;
      outOff += 8;
      flag = 0;
    } else if (lastKey == pairs[2 * k]) {
      flag = run + 1;
    } else {
      u32 key = pairs[2 * k];
      u32 h;
      if (owner) h = SLOT(owner, 0x218, v3_t)(owner, key, arg, 5);
      else {
        u8 *f = factory();
        h = SLOT(f, 0x108, v3_t)(f, key, arg, 5);
      }
      *(u32 *)((u8 *)*out1 + outIdx) = h;
      lastKey = key;
      *(u8 **)((u8 *)*out2 + outOff + 4) = bcur;
      if (run != 0) *(u32 *)((u8 *)*out2 + outOff - 8) = run;
      outIdx += 4;
      outOff += 8;
      flag = 1;
    }
    bcur += 0x28;
    run = flag;
  }
  return groups;
}
PCREG(4f9350, fn4f9350);
