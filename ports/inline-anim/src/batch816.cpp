// batch816.cpp - animation layer thread, batch 816: the clip sampler ZAnimFilePack::GetFramePosQuat and its
// bit-packed key reader. This is what turns (bone anim, time) into a bone position and rotation.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

static double crtFmod(double a, double b) {
  double r;
  __asm__ volatile("fldl %1\n\tfldl %2\n\tcall *0x676358\n\tfstpl %0" : "=m"(r) : "m"(a), "m"(b) : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

// The engine's assert: the handler at [0x7003b0], or int3 when none is installed.
static inline void engineAssert() {
  typedef void (*hook_t)();
  hook_t fp = G(hook_t, 0x7003b0);
  if (fp) fp();
  else __builtin_debugtrap();
}

// 0x4e5de0 ZAnimFilePack::UnpackBits(off, i) (no GC name; thiscall ret 8). Packed array at pack+0x10 + off: first a
// signed byte = bits per entry, then big-endian bit-packed entries. Returns entry i-1 (entry "0" is 0), read from a
// 24-bit window (entries up to 17 bits work). Shift counts are taken mod 32 as on x86.
static u32 THISCALL UnpackBits(u8 *self, u32 off, s32 i) {
  if (!i) return 0;
  u8 *p = (u8 *)FP(self, 0x10) + off;
  s32 bits = (s8)p[0];
  s32 b = (i - 1) * bits;
  p += b >> 3;
  u32 r = b & 7;
  s32 v = (s32)(((u32)p[1] << 24) | ((u32)p[2] << 16) | ((u32)p[3] << 8));
  v >>= (32 - r - bits) & 31;
  return (u32)v & ((1u << (bits & 31)) - 1);
}
PCREG(4e5de0, UnpackBits);

// ZAnimFilePack::GetFramePosQuat(ZBoneAnim-data* ba, bool loop, float* pos, float* quat, float t) [medium, GC 8028d6a4].
// thiscall ret 0x14. Bone anim (ba): +4 const position index, +6 const rotation index, +8 frame count (u16),
// +0xa flags (u16), +0xc rotation keys offset, +0x10/+0x14 rotation key-index / key-frame tables, +0x18 position keys
// offset, +0x1c/+0x20 position key-index / key-frame tables. Pack: +0x14 rotation key base, +0x18 position key base,
// +0x1c constant positions (12 bytes), +0x20 constant rotations (16 bytes).
// t is clamped to >= 0, then wrapped (loop, fmod by the frame count) or clamped to the frame count. Flags:
// 8 = constant position, 4 = keyed position (linear between keys), 0x10 = constant rotation, 1 = 16-bit rotation keys
// (x 1/32512), 2 = 8-bit rotation keys (x 1/127); rotations between keys use qpul. A key whose frame is after the
// sample frame (or a next key not after it) trips the engine assert.
extern "C" void FASTCALL ext_4df040(float *out, const float *a, const float *b, float t);   // qpul (batch 801)
static void THISCALL GetFramePosQuat(u8 *self, u8 *ba, u8 loop, float *pos, float *quat, float t) {
  float tc = 0.0f > t ? 0.0f : t;
  u32 n = F16(ba, 8);
  float f;
  if (loop) f = (float)crtFmod((double)tc, (double)(s32)n);
  else {
    float fn = (float)(s32)n;
    f = fn < tc ? fn : tc;
  }
  s32 fi = (s32)f;
  if (F16(ba, 0xa) & 8) {
    u8 *src = (u8 *)FP(self, 0x1c) + F16(ba, 4) * 12;
    F32(pos, 0) = F32(src, 0);
    F32(pos, 4) = F32(src, 4);
    F32(pos, 8) = F32(src, 8);
  } else {
    s32 kA = UnpackBits(self, F32(ba, 0x1c), fi);
    s32 fA = UnpackBits(self, F32(ba, 0x20), kA);
    if (F16(ba, 0xa) & 4) {
      float *base = (float *)(F32(ba, 0x18) + (u8 *)FP(self, 0x18)) + kA * 3;
      if (fA > fi) engineAssert();
      F32(pos, 0) = F32(base, 0);
      F32(pos, 4) = F32(base, 4);
      F32(pos, 8) = F32(base, 8);
      if ((u32)fA != F16(ba, 8)) {
        s32 fB = UnpackBits(self, F32(ba, 0x20), kA + 1);
        float nx = base[3], ny = base[4], nz = base[5];
        if (!(fB > fi)) engineAssert();
        float w = (f - (float)fA) / (float)(fB - fA);
        pos[0] = (nx - pos[0]) * w + pos[0];
        pos[1] = (ny - pos[1]) * w + pos[1];
        pos[2] = (nz - pos[2]) * w + pos[2];
      }
    }
  }
  if (F16(ba, 0xa) & 0x10) {
    u8 *src = (u8 *)FP(self, 0x20) + F16(ba, 6) * 16;
    F32(quat, 0) = F32(src, 0);
    F32(quat, 4) = F32(src, 4);
    F32(quat, 8) = F32(src, 8);
    F32(quat, 0xc) = F32(src, 0xc);
    return;
  }
  s32 qA = UnpackBits(self, F32(ba, 0x10), fi);
  s32 fqA = UnpackBits(self, F32(ba, 0x14), qA);
  u32 fl = F16(ba, 0xa);
  float nxt[4];
  s32 fqB;
  if (fl & 1) {
    u8 *base = F32(ba, 0xc) + (u8 *)FP(self, 0x14);
    if (fqA > fi) engineAssert();
    const float s = G(float, 0x69745c);
    s16 *k = (s16 *)(base + qA * 8);
    float q1 = (float)k[1] * s, q2 = (float)k[2] * s, q3 = (float)k[3] * s, q0 = (float)k[0] * s;
    quat[1] = q1; quat[2] = q2; quat[0] = q0; quat[3] = q3;
    if ((u32)fqA == F16(ba, 8)) return;
    fqB = UnpackBits(self, F32(ba, 0x14), qA + 1);
    const float s2 = G(float, 0x69745c);
    nxt[0] = (float)k[4] * s2;
    nxt[1] = (float)k[5] * s2;
    nxt[2] = (float)k[6] * s2;
    nxt[3] = (float)k[7] * s2;
  } else if (fl & 2) {
    u8 *base = F32(ba, 0xc) + (u8 *)FP(self, 0x14);
    if (fqA > fi) engineAssert();
    const float s = G(float, 0x697460);
    s8 *k = (s8 *)(base + qA * 4);
    float q1 = (float)k[1] * s, q2 = (float)k[2] * s, q3 = (float)k[3] * s, q0 = (float)k[0] * s;
    quat[1] = q1; quat[2] = q2; quat[0] = q0; quat[3] = q3;
    if ((u32)fqA == F16(ba, 8)) return;
    fqB = UnpackBits(self, F32(ba, 0x14), qA + 1);
    const float s2 = G(float, 0x697460);
    nxt[0] = (float)k[4] * s2;
    nxt[1] = (float)k[5] * s2;
    nxt[2] = (float)k[6] * s2;
    nxt[3] = (float)k[7] * s2;
  } else {
    engineAssert();
    return;
  }
  if (!(fqB > fi)) engineAssert();
  float w = (f - (float)fqA) / (float)(fqB - fqA);
  ext_4df040(quat, quat, nxt, w);
}
PCREG(4e54c0, GetFramePosQuat);
