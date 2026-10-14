// batch33108.cpp - h3 () batch 33108: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)
#define LOGOBJ (*(u8 **)0x700390)

typedef void (*log3_t)(u8 *, u32, u32);
typedef void (*logd_t)(u8 *, u32, double);

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_5eeab0(u8 *self, u32 f);                // ret 4
extern "C" void THISCALL ext_516780(u8 *self, u32 f);                // ret 4
extern "C" void THISCALL ext_52a200(u8 *self);                       // plain ret

// 0x5eff00: thiscall no args: byte [4]==0 return; state [0x94]: 0: x=[0x84] < 1.0: x += sys48/[0x88], clamp to 1.0, tail 0x5eeab0(x); else byte [0x98] ? ([0x90]=10.0, state 2) : state 3; 1: x=[0x84] > 0: x -= sys48/[0x8c], clamp at 0, tail 0x5eeab0(x); else byte [4]=0; 2: [0x90] < 0: state 1; [0x90] -= sys48
static void THISCALL fn5eff00(u8 *self) {
  if (self[4] == 0) return;
  u32 st = *(u32 *)(self + 0x94);
  if (st == 0) {
    float x = *(float *)(self + 0x84);
    if (1.0f > x) {
      float y = *(float *)(SYS + 0x48) / *(float *)(self + 0x88);
      y = y + x;
      *(float *)(self + 0x84) = y;
      if (y > 1.0f) *(u32 *)(self + 0x84) = 0x3f800000;
      ext_5eeab0(self, *(u32 *)(self + 0x84));
      return;
    }
    if (self[0x98] != 0) {
      *(u32 *)(self + 0x90) = 0x41200000;
      *(u32 *)(self + 0x94) = 2;
      return;
    }
    *(u32 *)(self + 0x94) = 3;
    return;
  }
  if (st == 1) {
    float x = *(float *)(self + 0x84);
    if (x > 0.0f) {
      float y = *(float *)(SYS + 0x48) / *(float *)(self + 0x8c);
      y = x - y;
      *(float *)(self + 0x84) = y;
      if (0.0f > y) *(u32 *)(self + 0x84) = 0;
      ext_5eeab0(self, *(u32 *)(self + 0x84));
      return;
    }
    self[4] = 0;
    return;
  }
  if (st == 2) {
    float v = *(float *)(self + 0x90);
    if (0.0f > v) *(u32 *)(self + 0x94) = 1;
    *(float *)(self + 0x90) = v - *(float *)(SYS + 0x48);
  }
}
PCREG(5eff00, fn5eff00);

// 0x5267b0: thiscall(float f) ret 4: [0x94]=400.0, [0x98]=0x3f860a92, [0x9c]=0x3b03126f; for i < [0x8c] (signed, re-read): 0x516780(this+0xbd+0xde*i, f); 0x52a200(this+0x7dd+0x163*i); for i < [0x90]: 0x516780(this+0x435+0xde*i, f); 0x52a200(this+0xd39+0x133*i)
static void THISCALL fn5267b0(u8 *self, u32 f) {
  W32(self + 0x94, 0x43c80000);
  W32(self + 0x98, 0x3f860a92);
  W32(self + 0x9c, 0x3b03126f);
  if (*(s32 *)(self + 0x8c) > 0) {
    s32 i = 0;
    do {
      ext_516780(self + 0xbd + 0xde * i, f);
      ext_52a200(self + 0x7dd + 0x163 * i);
      i++;
    } while (i < *(s32 *)(self + 0x8c));
  }
  if (*(s32 *)(self + 0x90) > 0) {
    s32 i = 0;
    do {
      ext_516780(self + 0x435 + 0xde * i, f);
      ext_52a200(self + 0xd39 + 0x133 * i);
      i++;
    } while (i < *(s32 *)(self + 0x90));
  }
}
PCREG(5267b0, fn5267b0);

// 0x5354a0: thiscall(idx, float v) ret 8: o=[this+0x52fe]; o == 0 or idx == -1: return; idx >= [o+0x11e9]: log (0x6a1e2c,0x584)/(r,0x6a2130,idx), return; v < 0 or v > 1: log (0x588)/(r,0x6a215c,(double)v); [[o+0x11f9]+0xa4*idx+8] = v
static void THISCALL fn5354a0(u8 *self, u32 idx, u32 vb) {
  u8 *o = (u8 *)R32(self + 0x52fe);
  if (!o) return;
  if (idx == 0xffffffffu) return;
  if (idx >= R32(o + 0x11e9)) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x6a1e2cu, 0x584u);
    (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x6a2130, idx);
    return;
  }
  float v = bitsf(vb);
  if (0.0f > v || v > 1.0f) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x6a1e2cu, 0x588u);
    (*(logd_t *)(*(u8 **)r + 0x2c))(r, 0x6a215c, (double)v);
  }
  o = (u8 *)R32(self + 0x52fe);
  u8 *arr = (u8 *)R32(o + 0x11f9);
  *(u32 *)(arr + idx * 0xa4u + 8) = vb;
}
PCREG(5354a0, fn5354a0);
