// batch1007.cpp - unclaimed-04 batch 7 (docs/20-unclaimed-04.md): CEntityTracker::GetEntityNear (0x5c0330, high name).
// thiscall, four stack arguments (ret 0x10): pos (const float *), radius (float), index (int *, in and out), mask.
// The records are 0x17 bytes each in a pool at this+0x50; the array at this+0x4c holds record numbers in key order.
// The record key is the float at +4 (the vector at +4..+0x10 goes to the distance helper). Each float compare is written
// with the same ordered test the exe uses (ja is >, jbe is not >), so NaN behaves as in the exe.
// 0x4e0830 (squared distance helper, returns in st0) is original code; it takes pos in edx (see its declaration).
#include "ff.h"

typedef u32(THISCALL *vfn0_t)(void *self);

// squared distance helper, original code: ecx = the record's vector, edx = pos (the helper reads its second point from
// the caller's edx, which is pos at every call site here); returns the squared length in st0.
extern "C" float FASTCALL ext_4e0830(void *vec, const float *pos);

static inline float keyOf(u32 recBase, const u32 *arr, u32 i) {
  return *(float *)(recBase + arr[i] * 0x17u + 4);
}

static inline u32 recOf(u32 recBase, const u32 *arr, u32 i) {
  return recBase + arr[i] * 0x17u;
}

// 0x5c0330: returns the first entity in range (its record's entity pointer) or 0. *index is updated as the search goes.
static u32 THISCALL entityTrackerGetEntityNear(u8 *self, const float *pos, float radius, s32 *index, u32 mask) {
  u32 count = *(u32 *)(self + 0x54);
  if (count == 0) return 0;

  float r2 = *(float *)(self + 0x60) + radius;  // addss xmm2: this+0x60 plus radius
  float hi = pos[0] + r2;
  float lo = pos[0] - r2;
  const u32 *arr = *(const u32 **)(self + 0x4c);
  u32 recBase = *(u32 *)(self + 0x50);

  s32 idx = *index;
  if (idx == -1) {
    // first call: the window's first record must not be above hi, the last must not be below lo
    if (keyOf(recBase, arr, 0) > hi) return 0;
    if (lo > keyOf(recBase, arr, count - 1)) return 0;

    // binary search for the first record at or above lo (ja / jbe are > and not >)
    u32 hiI = count - 1;
    u32 loI = 0;
    if (hiI > 1) {
      while (hiI > loI + 1) {
        u32 mid = (hiI + loI) >> 1;
        if (!(lo > keyOf(recBase, arr, mid)))
          hiI = mid;
        else
          loI = mid;
      }
    }
    *index = (s32)loI;
  } else {
    *index = idx + 1;
  }

  // walk from *index while the keys are not above hi
  if (*index >= (s32)count) {
    *index = -1;
    return 0;
  }
  for (;;) {
    u32 rec = recOf(recBase, arr, (u32)*index);
    if (*(float *)(rec + 4) > hi) {
      *index = -1;
      return 0;
    }
    u32 ent = *(u32 *)rec;
    u32 type = *(u32 *)(ent + 0x54);
    u32 shift = *(u32 *)(type + 4);
    if (mask & (1u << (shift & 31))) {
      float d = ext_4e0830((void *)(rec + 4), pos);
      if (r2 * r2 > d) {
        // entity vtable slot 0x20 (no arguments) gives X; the flag is bit 10 of the dword at (X+8)+0x3c
        u32 X = ((vfn0_t)(*(u32 *)(*(u32 *)ent + 0x20)))((void *)ent);
        u32 Y = *(u32 *)(X + 8);
        u32 flags = *(u32 *)(Y + 0x3c);
        if (((flags >> 10) & 1) == 0) return ent;
      }
    }
    (*index)++;
    if (*index >= (s32)count) {
      *index = -1;
      return 0;
    }
  }
}
PCREG(5c0330, entityTrackerGetEntityNear);
