// batch67555.cpp - cascade s6 batch 67555: 0x4946b0.
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);                          // alloc, cdecl
extern "C" void ext_634d10(u8 *p, u32 v, u32 n);           // memset thunk, cdecl
extern "C" void ext_634273(u8 *p, u32 n);                  // free, cdecl
extern "C" void THISCALL ext_493820(u8 *self, u8 *entry, u32 payload, u32 z);   // ret 0xc

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4946b0, thiscall(newSize) ret 4, no return value: rehash of a bucket table (this[0x18] 8-byte buckets, this[4] occupancy bitmap, this[0x10] used count, this[8] size). A new size below the used
// count does nothing. Otherwise fresh zeroed arrays are allocated (size * 8 bytes with an overflow guard, size / 32 bitmap words), the counters (+0x10, +0x14, +0x1c) are cleared and every occupied
// old bucket (the next set bit of the old bitmap, `used` of them) is re-inserted with 0x493820(entry, entry[4], 0); the old arrays are freed (8 / 4 byte class arguments).
static void THISCALL fn4946b0(u8 *self, u32 newSize) {
  u32 used = D32(self, 0x10);
  if (newSize < used) return;
  u8 *oldBuckets = *(u8 **)(self + 0x18);
  D32(self, 8) = newSize;
  u64 bytes = (u64)newSize * 8;
  u32 sz = bytes >> 32 ? 0xffffffffu : (u32)bytes;
  u32 *oldMap = *(u32 **)(self + 4);
  D32(self, 0x1c) = 0;
  D32(self, 0x10) = 0;
  D32(self, 0x14) = 0;
  u8 *nb = ext_41e290(sz);
  D32(self, 0x18) = (u32)nb;
  ext_634d10(nb, 0, D32(self, 8) * 8);
  u32 w = D32(self, 8) >> 5;
  u8 *nm = ext_41e290(w * 4);
  D32(self, 4) = (u32)nm;
  ext_634d10(nm, 0, (D32(self, 8) >> 5) << 2);
  u32 i = 0;
  if (used) {
    do {
      while (!(oldMap[i >> 5] & (1u << (i & 31)))) i++;
      u8 *e = oldBuckets + i * 8;
      ext_493820(self, e, D32(e, 4), 0);
      i++;
    } while (--used);
  }
  ext_634273(oldBuckets, 8);
  ext_634273((u8 *)oldMap, 4);
}
PCREG(4946b0, fn4946b0);
