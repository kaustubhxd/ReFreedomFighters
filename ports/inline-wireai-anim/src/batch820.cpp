// batch820.cpp - animation layer thread, batch 820: ZAnimDefsList (weighted clip lists by movement type).
// PC layout: +4 current clip, +0xc last clock time (s), +0x10 end time (s), +0x14 list of nodes.
// Node: +0 clip, +4 ANIMTYPE, +8 weight (float). The list object's vtable: +0x14 count, +0x4c begin, +0x64 next.
// Engine clock: [0x70039c] + 0x40 (int ticks, 1024 per second), +0x48 float frame-rate scale. Assert vt +0x1c0.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

static double crtFmod(double a, double b) {
  double r;
  __asm__ volatile("fldl %1\n\tfldl %2\n\tcall *0x676358\n\tfstpl %0" : "=m"(r) : "m"(a), "m"(b) : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

static inline u8 *engine() { return G(u8 *, 0x70039c); }

// Stamps the last-use time of this list (clock / 1024), as every GetAnim does first.
static inline void stamp(u8 *self) { FF(self, 0xc) = (float)(s32)F32(engine(), 0x40) * bitsf(0x3a800000); }

// ZAnimDefsList::GetAnim(ANIMTYPE) [medium]: the first node of the type, and it becomes current.
// Otherwise the current clip stays.
static void *THISCALL GetAnim(u8 *self, u32 type) {
  stamp(self);
  u8 it[12];
  void *list = FP(self, 0x14);
  if (list) {
    vcall<void>(list, 0x4c, it);
    u32 *n = vcall<u32 *>(list, 0x64, it);
    while (n) {
      if (n[1] == type) {
        FP(self, 4) = (void *)n[0];
        return FP(self, 4);
      }
      n = vcall<u32 *>(list, 0x64, it);
    }
  }
  return FP(self, 4);
}
PCREG(4837e0, GetAnim);

// ZAnimDefsListRandom::GetAnim(float t) [medium]. The subclass's vt +0xc(t) gives a float r (the clip's
// own time-to-end). If the current clip still has r > t, it stays. Otherwise the weights of the nodes are summed
// until the sum reaches w = weight-scale * assert(0x227) and the node where that happens is taken. The assert value
// is 0 when the end time is not ahead of the clock (the usual case).
static void *THISCALL GetAnimRandom(u8 *self, float t) {
  stamp(self);
  float r = vcall<float>(self, 0xc, t);
  if (FP(self, 4) && r > t) return FP(self, 4);
  float m = 0.0f;
  if ((s32)F32(engine(), 0x40) >= (s32)(FF(self, 0x10) * G(float, 0x678620))) {
    m = vcall<float>(engine(), 0x1c0, (const char *)0x68bcbc, 0x227);
  }
  float w = FF(self, 8) * m;
  void *list = FP(self, 0x14);
  if (!list) return FP(self, 4);
  u32 cnt = vcall<u32>(list, 0x14);
  u8 it[12];
  vcall<void>(list, 0x4c, it);
  u32 *n = vcall<u32 *>(list, 0x64, it);
  float sum = 0.0f;
  while (n) {
    sum = FF(n, 8) + sum;
    cnt--;
    if (cnt == 0 || sum >= w) {
      FP(self, 4) = (void *)n[0];
      return FP(self, 4);
    }
    n = vcall<u32 *>(list, 0x64, it);
  }
  return FP(self, 4);
}
PCREG(483860, GetAnimRandom);

// ZAnimDefsList::GetFramePrc(float t) [high]: fraction 0..1 of the current clip at time t (seconds).
// 0 without a clip. Frames = clip+0x6c * the engine's scale (+0x48) / (end - start); fmod 1.
static float THISCALL GetFramePrc(u8 *self, float t) {
  void *clip = FP(self, 4);
  if (!clip) return 0.0f;
  u8 *c = (u8 *)FP(clip, 0);   // +4 holds a reference; its first word is the clip
  float v = (float)(s32)F32(c, 0x6c) * FF(engine(), 0x48);
  float d = (float)(s32)(F32(c, 0x64) - F32(c, 0x60));
  float x = v / d + t;
  volatile float r = (float)crtFmod((double)x, 1.0);
  return r;
}
PCREG(483aa0, GetFramePrc);

// ZAnimDefsList::UpdateEnd() [high]: when the stamped time differs from the clock, the current clip is
// dropped and the end time is set to now + 1024 ticks (one second).
static void THISCALL UpdateEnd(u8 *self) {
  s32 stamped = (s32)(FF(self, 0xc) * G(float, 0x678620));
  if (stamped == (s32)F32(engine(), 0x40)) return;
  FP(self, 4) = 0;
  FF(self, 0x10) = (float)(s32)(F32(engine(), 0x40) + 0x1000) * bitsf(0x3a800000);
}
PCREG(4850c0, UpdateEnd);
