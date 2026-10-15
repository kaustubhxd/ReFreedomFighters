// batch67521.cpp - cascade s6 batch 67521: 0x530a40.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

// Shared tail of modes 1 and 2: allocates the record's slot (+2) from the running 16-bit cursor, once, if the entry's size (byte) still fits below the pool limit (+0x50).
static u32 allocSlot(u8 *self, u8 *P, u8 *rec) {
  if (W16(rec, 2)) return W16(rec, 2);
  u8 *e = *(u8 **)(P + 0x78) + W16(rec, 0) * 10;
  u16 *cur = *(u16 **)(self + 4);
  u32 v = *cur;
  if (e[0] + v > W16(P, 0x50)) return 0;
  W16(rec, 2) = (u16)v;
  *cur += e[0];
  return W16(rec, 2);
}

// 0x530a40, thiscall(), returns ax: a three-mode slot allocator over a shared cursor (this+4 -> u16, size this+8, index +0x16, mode byte +0x20, pool P = [this]). Mode 1 uses the
// 0x16-byte records at P+0x54, mode 2 the 12-byte records at P+0x5a and takes a slot from the 10-byte entry table at P+0x78 (byte size) when the record has none yet; mode 3 allocates
// this+8 units from the cursor at record word +0xa (limit P+0x50, signed) and returns a packed value (+0x1a & 7) << 3 + (+0x18 & 7) + that slot. Anything else, or a pool overflow, returns 0.
static u32 THISCALL fn530a40(u8 *self) {
  u8 mode = self[0x20];
  u8 *P = *(u8 **)self;
  u32 idx = W16(self, 0x16);
  if (mode == 1) {
    u8 *rec = *(u8 **)(P + 0x54) + idx * 0x16;
    return allocSlot(self, P, rec);
  }
  if (mode == 2) {
    u8 *rec = *(u8 **)(P + 0x5a) + idx * 12;
    return allocSlot(self, P, rec);
  }
  if (mode != 3) return 0;
  u8 *rec = *(u8 **)(P + 0x5a) + idx * 12;
  if (!W16(rec, 0xa)) {
    u16 *cur = *(u16 **)(self + 4);
    u32 di = *cur;
    if ((s32)(di + D32(self, 8)) > (s32)W16(P, 0x50)) return 0;
    W16(rec, 0xa) = (u16)di;
    *cur += (u16)D32(self, 8);
  }
  return (u16)((((W16(self, 0x1a) & 7) << 3) + (W16(self, 0x18) & 7) + W16(rec, 0xa)) & 0xffff);
}
PCREG(530a40, fn530a40);
