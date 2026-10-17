// batch1061.cpp - ZCAMERA::CopyDataBlock (0x445800, the camera's DBLK reader). Camera thread, 2026-10-11.
// The DBLK readers (GetType 0x4e1600, Get 0x4e11e0 / 0x4e12f0 / 0x4e1440, NextBlock 0x4e1b30) are the exe's own
// code (ext_), so the item format and cursor are the originals'. The 0x610100 call (a stdcall no-op) is not made.
#include "cam.h"

#define CDECL __attribute__((cdecl))

extern "C" THISCALL u8 ext_4e1600(void *dblk);                   // DBLK::GetType (al)
extern "C" THISCALL void ext_4e11e0(void *dblk, void *dst, u32 n);  // DBLK::Get (dwords)
extern "C" THISCALL void ext_4e12f0(void *dblk, void *dst, u32 n);  // DBLK::Get (floats)
extern "C" THISCALL void ext_4e1440(void *dblk, void *dst);         // DBLK::Get (one dword, type 4)
extern "C" THISCALL void ext_4e1b30(void *dblk);                    // DBLK::NextBlock

// Constants of the exe, as their exact bit patterns (a decimal literal can round to a neighbouring float).
static inline float bitsf32(u32 b) { return bitsf(b); }
static const float K_ONE = bitsf32(0x3f800000u);   // 0x678858: 1.0
static const float K_0A = bitsf32(0x3c23d70au);    // 0x67da00: 0.01
static const float K_0B = bitsf32(0x3df9db23u);    // 0x67da08
static const float K_0C = bitsf32(0x3e000000u);    // 0x67da0c: 0.125
static const float K_0D = bitsf32(0x3e5d2f1bu);    // 0x67da10
static const float K_0E = bitsf32(0x3faaaaabu);    // 0x67da14: 4/3
static const float K_0F = bitsf32(0x40490fdbu);    // 0x67da18: pi
static const float K_10 = bitsf32(0x43340000u);    // 0x67da28: 180.0

// The sys object's event list (+0x190f, nodes linked through +8, a flag byte at +0x81).
static inline u8 *sys_head() { return at<u8 *>(G(u8 *, 0x70039c), 0x190f); }

// Helper: slot 0x134 of the manager gives an object; its slot 0x90 writes a byte at the pointer (the flag).
static inline u8 flag90() {
  u8 *obj = (u8 *)(unsigned long)vcall<u32>(SYS9B, 0x134);
  u8 b = 0;
  vcall<void>(obj, 0x90, (u32)0x67d9dc, (void *)&b);
  return b;
}

// 0x445800 CopyDataBlock(DBLK *blk) (thiscall, one stack arg).
static THISCALL void ZCAMERA_CopyDataBlock(u8 *self, u8 *blk) {
  ext_4e12f0(blk, self + 0x64, 1);
  if (K_ONE > at<float>(self, 0x64)) at<float>(self, 0x64) = K_ONE;
  ext_4e12f0(blk, self + 0x68, 1);
  u32 t3[3];
  ext_4e11e0(blk, t3, 3);
  u32 bits = (u32)(u8)t3[0];
  bits = (bits << 8) + (u8)t3[1];
  bits = (bits << 8) + (u8)t3[2];
  at<u32>(self, 0x6c) = bits;
  ext_4e12f0(blk, self + 0x60, 1);
  float f2c;
  ext_4e12f0(blk, &f2c, 1);
  u32 t34;
  at<float>(self, 0x5c) = (f2c * K_0F) / K_10;
  ext_4e11e0(blk, &t34, 1);
  u32 cnt;
  ext_4e11e0(blk, &cnt, 1);
  ext_4e11e0(blk, self + 0x4c, 1);
  if (cnt) {
    // The cnt-th node of the event list (1-based), if it exists.
    u8 *node = sys_head();
    for (u32 i = 1; i != cnt && node; i++) node = at<u8 *>(node, 8);
    if (node) {
      vcall<u32>(at<u8 *>(SYS9B, 0xadc), 0x348, at<u32>(self, 0x6c));
      float fv = (float)(s32)at<u32>(self, 0x4c);
      vcall<void>(node, 0xac, (void *)self, fv);
    }
  }
  if (ext_4e1600(blk) == 3) {
    u32 t28 = 0;
    ext_4e11e0(blk, &t28, 1);
    if (t28 == 1) {
      float x2 = K_0C;
      u8 *sys = G(u8 *, 0x70039c);
      if (at<u8>(sys, 0x63)) {
        u8 *h = at<u8 *>(sys, 0x190f);
        if (h && at<u8>(h, 0x81)) x2 = K_0A;
        x2 = x2 * (K_0E / ((float)(s32)at<u32>(sys, 0x6f) / (float)(s32)at<u32>(sys, 0x73)));
      }
      float v[3] = {0.0f, x2, K_ONE};
      vcall<void>(self, 0x23c, (void *)v);
      at<u32>(self, 0x30) = 4;
    } else if (t28 == 2) {
      u8 *h = sys_head();
      float w1;
      if (h && at<u8>(h, 0x81)) w1 = K_0B;
      else w1 = flag90() ? K_0B : K_0D;
      float v[3] = {0.0f, w1, K_ONE};
      vcall<void>(self, 0x23c, (void *)v);
      at<u32>(self, 0x30) = 4;
    } else if (t28 == 3) {
      u8 *h = sys_head();
      float w1;
      if (h && at<u8>(h, 0x81)) w1 = K_0C;
      else w1 = flag90() ? K_0C : 0.0f;
      float v[3] = {w1, 0.0f, K_ONE - (w1 + w1)};
      vcall<void>(self, 0x23c, (void *)v);
    }
  }
  if (ext_4e1600(blk) == 3) {
    u32 t = 0;
    ext_4e11e0(blk, &t, 1);
    if (t == 0) at<u32>(self, 0x48) |= 0x80000;
  }
  if (ext_4e1600(blk) == 2) ext_4e12f0(blk, self + 0x70, 1);
  if (ext_4e1600(blk) == 2) ext_4e12f0(blk, self + 0x74, 1);
  if (ext_4e1600(blk) == 4) {
    u32 t = 0;
    ext_4e1440(blk, &t);
  }
  if (ext_4e1600(blk) == 3) {
    u32 t = 0;
    ext_4e11e0(blk, &t, 1);
    if (t) at<u32>(self, 0x48) |= 0x10000;
  }
  if (ext_4e1600(blk) == 2) {
    float v[4];
    ext_4e12f0(blk, v, 4);
    float a = at<float>(self, 0x171);
    float b = at<float>(self, 0x175);
    float c = at<float>(self, 0x179);
    float d = at<float>(self, 0x17d);
    float n0 = a * v[2];
    n0 = n0 + c * v[0];
    float n2 = c * v[2];
    float n1 = b * v[3];
    n1 = n1 + d * v[1];
    float n3 = d * v[3];
    v[0] = n0;
    v[2] = n2;
    v[3] = n3;
    v[1] = n1;
    vcall<void>(self, 0x23c, (void *)v);
  }
  if (ext_4e1600(blk) == 3) {
    u32 t = 0;
    ext_4e11e0(blk, &t, 1);
    at<u8>(self, 0x170) = (t != 0);
  }
  ext_4e1b30(blk);
}
PCREG(445800, ZCAMERA_CopyDataBlock);
