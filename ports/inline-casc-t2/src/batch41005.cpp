// batch41005.cpp - cascade t2 (): tier H float function 0x565760.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x565760, thiscall(flag) ret 4: a = [this+0xc7e] (null -> return); t = a slot 0x25c(0x6a6acc, 0) (null -> return); t slot 0xbc((byte)flag == 0); byte flag == 0 -> return.
// sys = [0x70039c]; H = (float)sys[0x73], W = (float)sys[0x6f]; sys slot 0xc(((float)((sys[0x6f]-0x280)/2) + K1) / W, ((float)((sys[0x73]-0x1c0)/2) + K2) / H, K1 / W, K0 / H)
// with K0 = 0x681dc8, K1 = 0x6a6ad8, K2 = 0x6a6ad4 (exe floats); the signed halves round toward zero.
static void THISCALL fn565760(u8 *self, u32 flag) {
  void *a = (void *)rd32(self + 0xc7e);
  if (!a) return;
  void *t = vcall<void *>(a, 0x25c, 0x6a6accu, 0u);
  if (!t) return;
  u8 bl = flag & 0xff;
  vcall<void>(t, 0xbc, (u32)(bl == 0));
  if (!bl) return;
  u8 *sys = G(u8 *, 0x70039c);
  s32 hh = (s32)rd32(sys + 0x73);
  s32 ww = (s32)rd32(sys + 0x6f);
  float k0 = G(float, 0x681dc8);
  float k1 = G(float, 0x6a6ad8);
  float k2 = G(float, 0x6a6ad4);
  float H = (float)hh;
  float W = (float)ww;
  float f3 = k0 / H;
  float f2 = k1 / W;
  s32 t1 = (s32)((u32)hh - 0x1c0u);
  t1 = (t1 - (t1 >> 31)) >> 1;
  float f1 = ((float)t1 + k2) / H;
  s32 t2 = (s32)((u32)ww - 0x280u);
  t2 = (t2 - (t2 >> 31)) >> 1;
  float f0 = ((float)t2 + k1) / W;
  vcall<void>(sys, 0xc, f0, f1, f2, f3);
}
PCREG(565760, fn565760);
