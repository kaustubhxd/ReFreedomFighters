// batch32102.cpp - cascade h2 (): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" u32 THISCALL ext_466290(u8 *self, u32 a, u32 b);   // thiscall ret 8
extern "C" u32 THISCALL ext_466f60(u8 *self, u32 a);          // thiscall ret 4
extern "C" void ext_634dc4();                                 // x87 CRT routine (st0 = 1.0, st1 = x on entry; result in st0)

static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x483aa0, thiscall(float a) ret 4, returns a float (st0): o = [this+4]; o == 0 -> 0.0; p = [o]; q = (float)(int)[p+0x6c] * [[0x70039c]+0x48] / (float)(int)([p+0x64] - [p+0x60]) + a;
// the x87 CRT routine 0x634dc4 with st1 = q (as double), st0 = 1.0 (fmod-style); the result is rounded to float.
static float THISCALL fn483aa0(u8 *self, float a) {
  u8 *o = *(u8 **)(self + 4);
  if (!o) return 0.0f;
  u8 *p = *(u8 **)o;
  float t = (float)*(s32 *)(p + 0x6c) * *(float *)(G(u8 *, 0x70039c) + 0x48);
  float d = (float)(s32)(*(u32 *)(p + 0x64) - *(u32 *)(p + 0x60));
  float q = t / d + a;
  double qd = (double)q;
  float r;
  __asm__ volatile("fldl %1\n\tfld1\n\tcall ext_634dc4\n\tfstps %0" : "=m"(r) : "m"(qd) : "eax", "ecx", "edx", "memory", "cc", "st", "st(1)", "st(2)", "st(3)");
  return r;
}
PCREG(483aa0, fn483aa0);

// 0x52b390, thiscall(out) ret 4, bool: head = [this+8] == [this+0xc] -> false; else copies the 0x32-byte record [this] + head*0x32 to out; [this+8] = (head + 1) % [this+4] (signed); true.
static bool THISCALL fn52b390(u8 *self, u8 *out) {
  s32 head = *(s32 *)(self + 8);
  if (head == *(s32 *)(self + 0xc)) return false;
  u8 *e = *(u8 **)self + head * 0x32;
  for (int i = 0; i < 0x32; i++) out[i] = e[i];
  *(s32 *)(self + 8) = (head + 1) % *(s32 *)(self + 4);
  return true;
}
PCREG(52b390, fn52b390);

// 0x467000, thiscall(a, b, c, flag) ret 0x10, returns r: r = flag != 0 ? 0x466290(this, a, 0) : 0x466f60(this, a); o = engine table slot 0x60 with r;
// o set -> [o+0x60] = b - [o+0x64]; [o+0x64] = b; [o+0x78] = (float)(int)c * K(0x67d9fc).
static u32 THISCALL fn467000(u8 *self, u32 a, u32 b, u32 c, u32 flag) {
  u32 r = ((u8)flag) ? ext_466290(self, a, 0) : ext_466f60(self, a);
  u8 *o = vcall<u8 *>(engTable(), 0x60, r);
  if (o) {
    *(u32 *)(o + 0x60) = b - *(u32 *)(o + 0x64);
    *(u32 *)(o + 0x64) = b;
    *(float *)(o + 0x78) = (float)(s32)c * G(float, 0x67d9fc);
  }
  return r;
}
PCREG(467000, fn467000);
