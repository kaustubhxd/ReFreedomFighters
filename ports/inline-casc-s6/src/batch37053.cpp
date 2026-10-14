// batch37053.cpp - cascade s6 batch 37053: 0x52e4f0.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))

// 0x52e4f0, thiscall(box, centre, flag) ret 0xc, returns a count: this has U16 count +0x86, 12-byte records at +0x88 (two points of three u16) and a parallel array of 4-byte
// entries at +0x8c. The box is centre (three s16) +- the half extents (three u16 at box). For every record with at least one of its two points inside the box, the entry's two
// words get bit 15 cleared (flag set) or set (flag clear); the number of updated entries is returned.
static u32 THISCALL fn52e4f0(u8 *self, u8 *box, s16 *ctr, u32 flagw) {
  u8 flag = (u8)flagw;
  s32 cx = ctr[0], cy = ctr[1], cz = ctr[2];
  s32 bx = U16(box, 0), by = U16(box, 2), bz = U16(box, 4);
  s32 lowX = bx - cx, highX = cx + bx;
  s32 lowY = by - cy, highY = cy + by;
  s32 lowZ = bz - cz, highZ = cz + bz;
  u32 count = 0;
  u32 n = U16(self, 0x86);
  if (n == 0) return 0;
  s32 i = 0;
  u32 off = 0;
  do {
    u8 *rec = (u8 *)D32(self, 0x88) + off;
    u8 *ent = (u8 *)D32(self, 0x8c) + (u32)i * 4;
    if (ent) {
      s32 x0 = U16(rec, 0), y0 = U16(rec, 2), z0 = U16(rec, 4);
      bool out0 = !(x0 >= lowX && y0 >= lowY && z0 >= lowZ && x0 <= highX && y0 <= highY && z0 <= highZ);
      s32 x1 = U16(rec, 6), y1 = U16(rec, 8), z1 = U16(rec, 10);
      bool out1 = !(x1 >= lowX && y1 >= lowY && z1 >= lowZ && x1 <= highX && y1 <= highY && z1 <= highZ);
      if (!(out0 && out1)) {
        if (flag) {
          U16(ent, 0) &= 0x7fff;
          U16(ent, 2) &= 0x7fff;
        } else {
          U16(ent, 0) |= 0x8000;
          U16(ent, 2) |= 0x8000;
        }
        count++;
      }
    }
    i++;
    off += 12;
  } while (i < (s32)(u32)U16(self, 0x86));
  return count;
}
PCREG(52e4f0, fn52e4f0);
