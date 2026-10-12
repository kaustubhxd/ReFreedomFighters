// batch243.cpp - parked item, ported bottom-up. 0x5eb8c0 (ZFFActorActionThrow::Update by its map name, GUESS for the body):
// thiscall() (ret). The helpers are the original code on both sides (claimed in batch35 / 29 / 34 / 63 / 100 / 302): 0x43e920
// and 0x43e8e0 fastcall (one stack word), 0x451890 fastcall (float stack word), 0x4e0d00 thiscall (float stack word), 0x44c840
// thiscall returning the length in ST0. The libm sqrt thunk (0x634d7c) is crt::sqrt. Stack-frame positions of the exe are
// replaced by named locals (the trace is in docs/20-unclaimed-21.md).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);   // dst = src - a (original)
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);      // dst = a + b (original)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);             // dst += v * s (original)
extern "C" void THISCALL ext_4e0d00(float *self, float s);                            // self[i] *= s (original)

typedef u32(THISCALL *SlotNone)(u8 *);
typedef u32(THISCALL *SlotOne)(u8 *, u32);
typedef void(THISCALL *SlotVoidOne)(u8 *, u32);
typedef void(THISCALL *SlotTwo)(u8 *, u32, u32);

static u32 vslot24(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x44c840: thiscall (ECX = the vector), plain ret, returns the length in ST0.
static float vnorm_44c840(float *vec) {
  float out;
  __asm__ volatile("movl %1, %%ecx\n\tcall *%2\n\tfstps %0"
                   : "=m"(out)
                   : "r"(vec), "r"(0x44c840u)
                   : "eax", "ecx", "edx", "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)",
                     "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7");
  return out;
}

static void THISCALL actionThrow_5eb8c0(u8 *self) {
  if (self[0x14]) return;
  float R = *(float *)(self + 0x10) * G(float, 0x678620);
  s32 ir = _mm_cvttss_si32(_mm_set_ss(R));
  u8 *rm = G(u8 *, 0x70039c);
  if ((s32)*(u32 *)(rm + 0x40) < ir) return;
  self[0x14] = 1;
  u32 r = ((SlotNone)vslot24(self, 4))(self);
  u8 *blk;
  if (r == 0x12) {
    u8 *o = *(u8 **)(self + 8);
    blk = (u8 *)(u32)((SlotNone)vslot24(o, 0x508))(o);
  } else {
    u32 r2 = ((SlotNone)vslot24(self, 4))(self);
    u8 *o = *(u8 **)(self + 8);
    blk = (r2 == 0x13) ? (u8 *)(u32)((SlotNone)vslot24(o, 0x50c))(o) : 0;
  }
  float vec[3] = {0.0f, 150.0f, -100.0f};
  u8 *o = *(u8 **)(self + 8);
  ((SlotOne)vslot24(o, 0x84))(o, (u32)(u32 *)vec);
  *(float *)(blk + 0x109) = vec[0];
  *(float *)(blk + 0x10d) = vec[1];
  *(float *)(blk + 0x111) = vec[2];
  float *esi = (float *)(self + 0x15);
  float d[3];
  ext_43e920(d, esi, vec);
  float Lsq = d[0] * d[0];
  Lsq += d[1] * d[1];
  Lsq += d[2] * d[2];
  float L = (float)crt::sqrt((double)Lsq);
  float t = L / G(float, 0x67d164);
  float sc = t * G(float, 0x67a6b0);
  sc = sc * t;
  float v16[3];
  v16[0] = 0.0f;
  v16[1] = bitsf(0xc4758000u);
  v16[2] = 0.0f;
  ext_451890(d, v16, sc);
  float inv = G(float, 0x678858) / t;
  ext_4e0d00(d, inv);
  float n = vnorm_44c840(d);
  float c = G(float, 0x68af28);
  float m = (c < n) ? c : n;
  ext_4e0d00(d, m);
  ext_43e8e0(esi, vec, d);
  ((SlotVoidOne)vslot24(blk, 0x32c))(blk, (u32)(u32 *)esi);
  ((SlotTwo)vslot24(blk, 0x2d0))(blk, 3, 0);
  ((SlotTwo)vslot24(blk, 0x2d0))(blk, 0, 0);
  ((SlotNone)vslot24(blk, 0x35c))(blk);
  u8 *o2 = *(u8 **)(self + 8);
  u8 *q = (u8 *)(u32)((SlotOne)vslot24(o2, 0x55c))(o2, (u32)blk);
  if (q) ((SlotNone)vslot24(q, 0x320))(q);
}
PCREG(5eb8c0, actionThrow_5eb8c0);
