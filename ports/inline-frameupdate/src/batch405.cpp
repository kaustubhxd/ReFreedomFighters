// batch405.cpp - per-frame update chain: ZLNKOBJ::UpdateAnimationsAndGroundLink (slot 0x348).
#include "ff.h"
typedef long long s64;

static inline s32 cvtt(float x) { return _mm_cvtt_ss2si(_mm_set_ss(x)); }

// The exe calls the CRT's _CIfmod (import slot 0x676358) with both operands on the x87 stack: x pushed first, then
// y; it returns fmod(x, y) in ST0. Called through the same import slot here.
static inline float cifmod(double x, double y) {
  float r;
  asm volatile("fldl %1\n\tfldl %2\n\tcall *%3\n\tfstps %0"
               : "=m"(r)
               : "m"(x), "m"(y), "m"(*(u32 *)0x676358)
               : "eax", "ecx", "edx", "cc", "memory", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)",
                 "st(7)", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7");
  return r;
}

// ---------------------------------------------------------------- 0x4650c0 ZLNKOBJ::UpdateAnimationsAndGroundLink() [low]
// thiscall, returns al. Map confidence is low (size ratio 2.97); the body plays the object's bone animations, which
// fits the name, and ZLNKOBJ::ClassFrameUpdate (batch 402) calls it as slot 0x348 and only places the object when it
// returns true.
//
// Anim list: the object at +0x18 (iterator slots 0x4c begin, 0x64 next, 0x44 remove current; 24-byte iterator).
// Each node holds a ZBoneAnim at +4 (b): +0 previous time, +4 and +8 time, +0xc event period, +0x18 length,
// +0x1c start time (s), +0x28 speed, +0x44 state (-1 = to destroy), +0x4c event target, +0x70 anim data
// (+0x6c rate, +0x7c event id). Track table: +0x1c (24-byte entries: +0 time, +4 flags, +0x14 bone anim), count
// +0x20. Event counter +0x122. Ground link: +0x6c (slot 0x5c), placement matrix +0x24 and position +0x48.
extern "C" void THISCALL ext_462510(u8 *b, u32 really);  // ZBoneAnim::Destroy(bool) [medium]
extern "C" void THISCALL ext_465330(u8 *b, float t);     // ZBoneAnim::UpdateCallBacks(float) [medium]
extern "C" void THISCALL ext_463da0(u8 *self, float a, float b);  // (no name) applies the base track's pose (inference)
extern "C" void FASTCALL ext_4de7a0(float *m);                    // mreset [high]
static u8 THISCALL zlnkobjUpdateAnimationsAndGroundLink(u8 *self) {
  u8 ended = 0;
  if (*(u8 **)(self + 0x18)) {
    u8 it[0x18];
    vcall<void>(*(u8 **)(self + 0x18), 0x4c, it);
    u8 *node = vcall<u8 *>(*(u8 **)(self + 0x18), 0x64, it);
    while (node) {
      u8 *b = node + 4;
      s32 state = *(s32 *)(b + 0x44);
      if (state < 0) {
        if (state == -1) {
          ext_462510(b, 1);
          vcall<void>(*(u8 **)(self + 0x18), 0x44, it);
        }
      } else {
        *(u32 *)b = *(u32 *)(b + 8);
        u8 *data = *(u8 **)(b + 0x70);
        s32 rate = cvtt((float)*(s32 *)(data + 0x6c) * *(float *)(b + 0x28) * 1024.0f);  // [0x678620]
        s32 start = cvtt(*(float *)(b + 0x1c) * 1024.0f);
        s32 since = (s32)(*(u32 *)(G(u8 *, 0x70039c) + 0x40) - (u32)start);
        s32 ticks = (s32)(u32)(((s64)rate * (s64)since) >> 10);
        float t = (float)ticks * 0.0009765625f;  // [0x6785e4]
        *(float *)(b + 4) = t;
        *(float *)(b + 8) = t;
        ext_465330(b, t);
        float now = *(float *)(b + 4);
        if (now >= *(float *)(b + 0x18))
          ended = 1;
        s32 period = *(s32 *)(b + 0xc);
        if (period) {
          s32 n = *(s32 *)(self + 0x122);
          if (cvtt(now) / period == n) {
            *(s32 *)(self + 0x122) = n + 1;
            vcall<void>(self, 0x270, b + 0x4c, *(u32 *)(*(u8 **)(b + 0x70) + 0x7c));
            if (!ended)
              vcall<void>(self, 0x268, b + 0x4c, *(u32 *)(*(u8 **)(b + 0x70) + 0x7c));
          }
        }
      }
      node = vcall<u8 *>(*(u8 **)(self + 0x18), 0x64, it);
    }
  }
  vcall<void>(self, 0x26c);
  if (ended) {
    u8 *tr = *(u8 **)(self + 0x1c);
    for (u32 i = 0; i != *(u32 *)(self + 0x20); i++, tr += 0x18) {
      if (!(tr[4] & 3))
        continue;
      u8 *ba = *(u8 **)(tr + 0x14);
      float len = *(float *)(ba + 0x18);
      if (!(*(float *)(ba + 4) >= len))
        continue;
      s32 period = *(s32 *)(ba + 0xc);
      if (len == (float)period)
        *(float *)tr = len;
      else
        *(float *)tr = cifmod((double)len, (double)period);
      vcall<void>(self, 0x340, i, 1u);
    }
  }
  u8 *t0 = *(u8 **)(self + 0x1c);
  u8 *ba = *(u8 **)(t0 + 0x14);
  if (*(u8 **)(self + 0x18) && ba && (t0[4] & 3) && (ended || !(*(u32 *)(ba + 0x14) & 0x200))) {
    ext_463da0(self, *(float *)ba, *(float *)(ba + 8));
    vcall<u8>(*(u8 **)(self + 0x6c), 0x5c, self, (float *)(self + 0x24), (float *)(self + 0x48));
    return 1;
  }
  ((u32 *)(self + 0x48))[0] = 0;
  ((u32 *)(self + 0x48))[1] = 0;
  ((u32 *)(self + 0x48))[2] = 0;
  ext_4de7a0((float *)(self + 0x24));
  return vcall<u8>(*(u8 **)(self + 0x6c), 0x5c, self, (float *)(self + 0x24), (float *)(self + 0x48));
}
PCREG(4650c0, zlnkobjUpdateAnimationsAndGroundLink);
