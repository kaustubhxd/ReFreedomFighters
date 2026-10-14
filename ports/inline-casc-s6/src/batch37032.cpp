// batch37032.cpp - cascade s6 batch 37032: 0x4e4050.
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);                 // alloc, cdecl
extern "C" void STDCALL ext_4e3f60(u32 *req);       // ret 4

#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4e4050, thiscall(x0, y0, z0, x1, y1, z1, data) ret 0x1c, returns the new node: creates an octree box node (0x1c bytes {next, ?, data, 16-bit bounds at +0xc..+0x16})
// for the box x0..x1, y0..y1, z0..z1 (clamped into 0..0xffff by shifting the minimum corner when any coordinate is out of range), computes the box centre and the
// level 15 - floor(log2(largest extent + 1)), asks 0x4e3f60 to insert it into the tree at this+4 and counts it at this+0x19.
static u8 *THISCALL fn4e4050(u8 *self, u32 x0, u32 y0, u32 z0, u32 x1, u32 y1, u32 z1, u32 data) {
  if (x0 > 0xffff || x1 > 0xffff || y0 > 0xffff || y1 > 0xffff || z0 > 0xffff || (s32)z1 < 0 || (s32)z1 >= 0x10000) {
    x0 += 0xffff - x1;
    x1 = 0xffff;
    y0 += 0xffff - y1;
    y1 = 0xffff;
    z0 += 0xffff - z1;
    z1 = 0xffff;
  }
  u32 dx = x1 - x0, dy = y1 - y0, dz = z1 - z0;
  u32 cx = (u32)((s32)(dx + 1) >> 1) + x0;
  u32 cy = (u32)((s32)(dy + 1) >> 1) + y0;
  u32 cz = (u32)((s32)(dz + 1) >> 1) + z0;
  u32 m;
  if ((s32)(dx + 1) > (s32)(dy + 1)) m = ((s32)(dx + 1) > (s32)(dz + 1)) ? dx : dz;
  else m = ((s32)(dy + 1) > (s32)(dz + 1)) ? dy : dz;
  s32 ext = (s32)(m + 1);
  s32 level = 0xf;
  if (ext > 1) {
    s32 hb = 0x1f;
    u32 bit = 0x80000000u;
    do {
      bit >>= 1;
      hb--;
    } while (!(bit & (u32)ext));
    level = 0xf - hb;
  }
  u8 *node = ext_41e290(0x1c);
  if (node) {
    D32(node, 0) = 0;
    D32(node, 4) = 0;
    D32(node, 8) = data;
  }
  W16(node, 0xc) = (u16)x0;
  W16(node, 0xe) = (u16)y0;
  W16(node, 0x10) = (u16)z0;
  W16(node, 0x12) = (u16)x1;
  W16(node, 0x14) = (u16)y1;
  W16(node, 0x16) = (u16)z1;
  u32 req[7];
  req[0] = (u32)(self + 4);
  req[1] = (u32)node;
  req[2] = 0;
  req[3] = (u32)level;
  req[4] = (u32)cx;
  req[5] = (u32)cy;
  req[6] = (u32)cz;
  ext_4e3f60(req);
  D32(self, 0x19)++;
  return node;
}
PCREG(4e4050, fn4e4050);
