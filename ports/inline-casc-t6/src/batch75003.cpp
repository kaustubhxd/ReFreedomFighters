// batch75003.cpp - tier H slice 5 (t6, Haiku): 0x5007e0 (/GS, 3 stack args), 0x51e470 (SSE float ops).
#include "ff.h"

extern "C" void *THISCALL ext_5003d0(void *);
extern "C" double VECTORCALL ext_634de2(double);

// 0x5007e0 thiscall(p1, p2, p3) ret 0xc: /GS; calls p1[0x18](p2), checks engine table, calls result[0x4c](0), 0x5003d0, then [0x30].
static u32 THISCALL fn_5007e0(void *self, void *p1, void *p2, void *p3) {
  void *esi = vcall<void *>(p1, 0x18, p2);

  if (!esi) return 0;

  u8 *eng = *(u8 **)0x70039c;
  void *table_obj = *(void **)(eng + 0x9b);
  void *table_res = vcall<void *>(table_obj, 0x58);

  if (table_res) {
    p3 = (void *)(u8 *)*(u32 *)((u8 *)table_res + 4);
  }

  void *res1 = vcall<void *>(esi, 0x4c, 0);
  void *res2 = ext_5003d0(res1);
  void *res2_vt = *(void **)res2;
  vcall<void>(res2_vt, 0x30, p3);
  return (u32)esi;
}
PCREG(5007e0, fn_5007e0);

// 0x51e470 thiscall no args: asserts, checks condition, does SSE float operations and comparisons, calls engine.
static void THISCALL fn_51e470(u8 *self) {
  void *assert_fn = *(void **)0x7003b0;
  if (assert_fn) ((void (*)(void))assert_fn)();

  if (*(u32 *)(self + 0x34a) != 0) return;

  float f = 0.0f;
  if (*(u32 *)(self + 0x469) != 0) {
    float v = *(float *)(self + 0x597);
    float div = *(float *)0x69f9dc;
    f = (float)ext_634de2((double)(v / div));
  } else {
    f = *(float *)0x69f9d0;
  }
  *(float *)(self + 0x232) = f;

  u8 *eng = *(u8 **)0x70039c;
  void *obj = vcall<void *>(eng, 0x190);

  float f236 = *(float *)(self + 0x236);
  float f23a = *(float *)(self + 0x23a);

  vcall<void>(obj, 0x184, obj, 10u, 0x24u, 0x69f998u, (double)f236, (double)f23a);

  float f232 = *(float *)(self + 0x232);
  if (f232 <= 0.0f) {
    f232 = *(float *)0x69f9d4;
    if (f232 > *(float *)(self + 0x232)) {
      f232 = *(float *)(self + 0x232);
    }
  }
  *(float *)(self + 0x232) = f232;

  float f23a_cmp = *(float *)(self + 0x23a);
  float cmp_val = *(float *)0x69f9e4;
  if (cmp_val <= f23a_cmp) {
    f23a_cmp = *(float *)0x69f9d8;
    if (f23a_cmp > *(float *)(self + 0x23a)) {
      f23a_cmp = *(float *)(self + 0x23a);
    }
  }
  *(float *)(self + 0x23a) = f23a_cmp;
}
PCREG(51e470, fn_51e470);
