// batch33085.cpp - h3 () batch 33085: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" float THISCALL ext_4e5e80(u8 *self);                      // float in st0
extern "C" void THISCALL ext_4e6330(u8 *self, u8 *dst);              // ret 4
extern "C" float THISCALL ext_4e0830(u8 *self);                      // float in st0, no stack args

// 0x4bb980: thiscall(stream) ret 4: 0x4e6330(s, this+0x54); 0x4e6330(s, this+0x100); b=**s; b != 0xff and (b & 0x3f) == 2: [this+0x4c]=e80(s); [this+0x50]=e80(s)
static void THISCALL fn4bb980(u8 *self, u8 *s) {
  ext_4e6330(s, self + 0x54);
  ext_4e6330(s, self + 0x100);
  u8 b = **(u8 **)s;
  if (b != 0xff && (b & 0x3f) == 2) {
    float f = ext_4e5e80(s);
    *(float *)(self + 0x4c) = f;
    f = ext_4e5e80(s);
    *(float *)(self + 0x50) = f;
  }
}
PCREG(4bb980, fn4bb980);

// 0x537370: thiscall(arg) ret 4: o=[this+0x5302]; 0 -> return 0; r = sys slot 0x1c0(0x6a1e2c, 0x3ac) (x87 double); idx=(int)(float)(r*(float)u16[arg+8] - 0.01f); return [[arg+0x10]+o + 4*idx]
static u32 THISCALL fn537370(u8 *self, u8 *arg) {
  u32 o = *(u32 *)(self + 0x5302);
  if (!o) return 0;
  u8 *base = (u8 *)(*(u32 *)(arg + 0x10) + o);
  double r = vcall<double>(SYS, 0x1c0, 0x6a1e2cu, 0x3acu);
  float x = (float)*(u16 *)(arg + 8);
  double v = r * (double)x;
  v = v - (double)0.01f;
  float f = (float)v;
  s32 idx = _mm_cvttss_si32(_mm_set_ss(f));
  return *(u32 *)(base + (u32)idx * 4u);
}
PCREG(537370, fn537370);

// 0x47bce0: thiscall(float *v) ret 4: byte [this+0x74e]=1; copy v[0..2] to [0x742],[0x746],[0x74a]; p=[this+0x695]: f=0x4e0830(p[8]*16+p[0xc]-12) > 360000.0 -> slot 0x63c(0)
static void THISCALL fn47bce0(u8 *self, u32 *v) {
  self[0x74e] = 1;
  u32 a = v[0];
  __builtin_memcpy(self + 0x742, &a, 4);
  a = v[1];
  __builtin_memcpy(self + 0x746, &a, 4);
  a = v[2];
  __builtin_memcpy(self + 0x74a, &a, 4);
  u8 *p;
  __builtin_memcpy(&p, self + 0x695, 4);
  if (!p) return;
  u32 cnt = *(u32 *)(p + 8);
  u8 *arr = *(u8 **)(p + 0xc);
  float f = ext_4e0830(arr + (cnt << 4) - 0xc);
  if (f > 360000.0f) vcall<u32>(self, 0x63c, 0u);
}
PCREG(47bce0, fn47bce0);
