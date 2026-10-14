// batch34111.cpp - escalation batch 34111: 0x4d1320, 0x5cda40, 0x65bfe0, 0x532ed0, 0x659bb0, 0x54da10, 0x64de00.
#include "ff.h"

extern "C" u32 THISCALL ext_4d21b0(void *self, u32 a, u32 b);                  // thiscall ret 8
extern "C" u32 THISCALL ext_5cf110(void *self);                                // thiscall, plain ret (al)
extern "C" u32 THISCALL ext_647fd0(void *self, u32 a, u32 b, u32 c, u32 d);    // thiscall ret 0x10
extern "C" u32 ext_634d10(void *p, u32 v, u32 n);                              // cdecl import thunk (memset)
extern "C" u32 FASTCALL ext_4de420(u8 *dst, u8 *src);                          // ecx = dst, edx = src; copies 0x24 bytes
extern "C" u32 THISCALL ext_4ce1c0(void *self, u32 a, u32 b);                  // thiscall ret 8
extern "C" void ext_634273(void *p, u32 n);                                    // cdecl free

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4d1320, thiscall(a, b, c) ret 0xc, returns this: [this] = 0x695f78; dwords +0xc, +0x24, +0x28, +0x14, +0x10, +0x18, +0x1c, +0x2c, +0x34, +0x30 = 0; [this+0x20] = a; then ext_4d21b0(this, b, c).
static u32 THISCALL fn4d1320(u32 *self, u32 a, u32 b, u32 c) {
  self[0] = 0x695f78;
  self[3] = 0; self[9] = 0; self[10] = 0; self[5] = 0; self[4] = 0; self[6] = 0; self[7] = 0;
  self[8] = a;
  self[11] = 0; self[13] = 0; self[12] = 0;
  ext_4d21b0(self, b, c);
  return (u32)self;
}
PCREG(4d1320, fn4d1320);

// 0x5cda40, thiscall plain: [this+0xb50] = [[[this+0x44]+0x54]+0xc]; unaligned dwords +0xdfd = 0x46c35000, +0xe01 = 0x4e1502f9; +0xdf9 = byte [this+0xb45] ? 0x3d0efa35 : 0x3ed67750;
// v = ext_5cf110(this) low byte ? unaligned [this+0xd2e] : 0; unaligned [this+0xd11] = v; returns v.
static u32 THISCALL fn5cda40(u8 *self) {
  u8 flag = self[0xb45];
  u8 *p = *(u8 **)(*(u8 **)(self + 0x44) + 0x54);
  *(u32 *)(self + 0xb50) = *(u32 *)(p + 0xc);
  wr32(self + 0xdfd, 0x46c35000);
  wr32(self + 0xe01, 0x4e1502f9);
  wr32(self + 0xdf9, flag ? 0x3d0efa35 : 0x3ed67750);
  u32 v = 0;
  if ((u8)ext_5cf110(self)) v = rd32(self + 0xd2e);
  wr32(self + 0xd11, v);
  return v;
}
PCREG(5cda40, fn5cda40);

// 0x65bfe0, thiscall(a, b, c, d) ret 0x10, returns this: ext_647fd0(this, a, b, c, d); [this] = 0x6c4714; ext_634d10(this+0x28, 0, 0x10000); [this+0x20] = 0.
static u32 THISCALL fn65bfe0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  ext_647fd0(self, a, b, c, d);
  *(u32 *)self = 0x6c4714;
  ext_634d10(self + 0x28, 0, 0x10000);
  *(u32 *)(self + 0x20) = 0;
  return (u32)self;
}
PCREG(65bfe0, fn65bfe0);

// 0x532ed0, thiscall plain, returns the old cursor: e = unaligned [this+0x51a9]; [e] = 0x20, [e+4] = 0x44; ext_4de420(e+8, this+0x4a); [e+0x2c..0x34] = unaligned [this+0x6e, +0x72, +0x76]; [e+0x38..0x40] = 0; [this+0x51a9] = e + [e+4].
static u32 THISCALL fn532ed0(u8 *self) {
  u8 *e = (u8 *)rd32(self + 0x51a9);
  *(u32 *)(e + 4) = 0x44;
  *(u32 *)e = 0x20;
  ext_4de420(e + 8, self + 0x4a);
  *(u32 *)(e + 0x2c) = rd32(self + 0x6e);
  *(u32 *)(e + 0x30) = rd32(self + 0x72);
  *(u32 *)(e + 0x34) = rd32(self + 0x76);
  *(u32 *)(e + 0x40) = 0;
  *(u32 *)(e + 0x3c) = 0;
  *(u32 *)(e + 0x38) = 0;
  u8 *c = (u8 *)rd32(self + 0x51a9);
  wr32(self + 0x51a9, (u32)c + *(u32 *)(c + 4));
  return (u32)c;
}
PCREG(532ed0, fn532ed0);

// 0x659bb0, thiscall plain: nothing when [this+8] is null. Else q = [[this+8]+4]: when set ext_4ce1c0([this+0xc]+4, q & 0x7fffffff, [this+4]); then frees [this+8] (size 8) unless it is the inline block at this+0x10; [this+8] = 0.
static void THISCALL fn659bb0(u8 *self) {
  u8 *p = *(u8 **)(self + 8);
  if (!p) return;
  u32 q = *(u32 *)(p + 4);
  if (q) ext_4ce1c0(*(u8 **)(self + 0xc) + 4, q & 0x7fffffff, *(u32 *)(self + 4));
  u8 *m = *(u8 **)(self + 8);
  if (m != self + 0x10) ext_634273(m, 8);
  *(u32 *)(self + 8) = 0;
}
PCREG(659bb0, fn659bb0);

// 0x54da10, thiscall plain: when unaligned [this+0x75] == 3 and p = unaligned [this+0x29] is set: byte [p+0x58] = 0, [this+0x29] = 0. Then byte +0x7a = 0, word +0x7c = 0, unaligned dwords +0x71, +0x61, +0x5d, +0x6d, +0x69 = 0, +0x75 = 1;
// ext_634d10(this+0x7f, 0, 0x4028); unaligned [this+0x29] = 0; [this+0x10] = 0.
static void THISCALL fn54da10(u8 *self) {
  if (rd32(self + 0x75) == 3) {
    u8 *p = (u8 *)rd32(self + 0x29);
    if (p) {
      p[0x58] = 0;
      wr32(self + 0x29, 0);
    }
  }
  self[0x7a] = 0;
  self[0x7c] = 0; self[0x7d] = 0;
  wr32(self + 0x71, 0);
  wr32(self + 0x61, 0);
  wr32(self + 0x5d, 0);
  wr32(self + 0x6d, 0);
  wr32(self + 0x69, 0);
  wr32(self + 0x75, 1);
  ext_634d10(self + 0x7f, 0, 0x4028);
  wr32(self + 0x29, 0);
  *(u32 *)(self + 0x10) = 0;
}
PCREG(54da10, fn54da10);

// 0x64de00, thiscall(src) ret 4, returns the last dword: ext_4de420(this+0x10, src+0x18229); [this+0x34, +0x38, +0x3c] = unaligned [src+0x1824d, +0x18251, +0x18255]; ext_4de420(this+0x40, src+0x181f9); [this+0x64, +0x68, +0x6c] = [src+0x1821d, +0x18221, +0x18225].
static u32 THISCALL fn64de00(u8 *self, u8 *src) {
  ext_4de420(self + 0x10, src + 0x18229);
  *(u32 *)(self + 0x34) = rd32(src + 0x1824d);
  *(u32 *)(self + 0x38) = rd32(src + 0x18251);
  *(u32 *)(self + 0x3c) = rd32(src + 0x18255);
  ext_4de420(self + 0x40, src + 0x181f9);
  *(u32 *)(self + 0x64) = rd32(src + 0x1821d);
  *(u32 *)(self + 0x68) = rd32(src + 0x18221);
  u32 v = rd32(src + 0x18225);
  *(u32 *)(self + 0x6c) = v;
  return v;
}
PCREG(64de00, fn64de00);
