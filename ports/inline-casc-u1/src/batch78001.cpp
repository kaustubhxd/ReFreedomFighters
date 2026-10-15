// batch78001.cpp - cascade tier H, batch 78001: 0x521bd0 (game entity state update with SSE math).
#include "ff.h"

extern "C" void ext_43e920(u8 *a1, u8 *a2, u8 *a3);
extern "C" void ext_4e0d00(u8 *a1, u8 *a2);
extern "C" void ext_521600(u8 *a1);
extern "C" void ext_44c840(u8 *ptr);
extern "C" double ext_634d7c(double d);

static float rd_f32(u8 *p) {
  u32 bits = p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24);
  return *(float *)&bits;
}
static void wr_f32(u8 *p, float f) {
  u32 bits = *(u32 *)&f;
  p[0] = bits; p[1] = bits >> 8; p[2] = bits >> 16; p[3] = bits >> 24;
}

static void THISCALL fn521bd0(u8 *obj) {
  u8 *vtable = *(u8 **)(obj + 0x2695);
  u8 *target = obj + 0x2d8;

  void (*slot2)(u8 *arg) = (void (*)(u8 *))(*(u32 *)(vtable + 8));
  slot2(obj + 0x2695);

  if (*(u32 *)(obj + 0x216) != 1) {
    u8 *base = *(u8 **)(obj + 0x5c);
    if (base) {
      float val = rd_f32(base + 0x24);
      float limit = rd_f32((u8 *)0x680a70);

      if (val > limit) {
        ext_43e920(obj + 0x90, obj + 0x60, target);

        float x = rd_f32(target);
        float y = rd_f32(target + 4);
        float z = rd_f32(target + 8);

        float mag_sq = x*x + y*y + z*z;
        double mag = ext_634d7c((double)mag_sq);
        float mag_f = (float)mag;

        float threshold = rd_f32((u8 *)0x697880);
        if (mag_f > threshold) {
          ext_4e0d00(target, obj + 0x2f0);
          ext_521600(obj);
        }
      }
    }

    if (base) {
      float val2 = rd_f32(base + 0x24);
      float limit2 = rd_f32((u8 *)0x680a84);
      if (val2 > limit2) {
        wr_f32(target, rd_f32(obj + 0x2e4));
        wr_f32(target + 4, rd_f32(obj + 0x2e8));
        wr_f32(target + 8, rd_f32(obj + 0x2ec));
      }
    }
  }

  void (*slot3)(u8 *arg) = (void (*)(u8 *))(*(u32 *)(vtable + 0xc));
  u8 ret = ((u8 (*)(u8 *))slot3)(obj + 0x2695);

  if (ret) {
    ext_44c840(obj + 0x2e4);
    *(u32 *)(obj + 0x2e8) = 0;

    void (*slot1)(u8 *arg1, u8 *arg2, u8 *arg3) =
      (void (*)(u8 *, u8 *, u8 *))(*(u32 *)(vtable + 4));
    slot1(obj + 0x2695, target, obj + 0x2d8);
  }

  *(u32 *)(obj + 0x2dc) = 0;
}
PCREG(521bd0, fn521bd0);
