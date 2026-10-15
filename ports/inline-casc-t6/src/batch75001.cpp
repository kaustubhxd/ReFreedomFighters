// batch75001.cpp - tier H slice 5 (t6, Haiku): 0x51cf10 (/GS function with SSE floats).
#include "ff.h"

extern "C" void THISCALL ext_vt_0x36c(void *);
extern "C" void THISCALL ext_vt_0x88(void *, void *);
extern "C" void THISCALL ext_vt_0x7c(void *, void *, void *);
extern "C" void FASTCALL ext_43e8e0(void *, void *, void *);

// 0x51cf10 thiscall: /GS guard, load three SSE floats, call vtable slots, direct call, min float operation.
static void THISCALL fn_51cf10(void *self) {
  float f1 = *(float *)((u8 *)self + 0x276);
  float f2 = *(float *)((u8 *)self + 0x27a);
  float f3 = *(float *)((u8 *)self + 0x27e);

  vcall<void>(self, 0x36c);

  u8 floats_buf[12];
  *(float *)(floats_buf + 0) = f1;
  *(float *)(floats_buf + 4) = f2;
  *(float *)(floats_buf + 8) = f3;

  vcall<void>(self, 0x88, floats_buf);

  float f2_result = f2;
  if (f2 <= 0.0f) {
    float global_val = *(float *)0x67cd44;
    if (global_val < f2) {
      f2_result = global_val;
    }
  }
  *(float *)(floats_buf + 4) = f2_result;

  u8 *ptr1 = (u8 *)self + 0x60;
  u8 *ptr2 = (u8 *)self + 0x6c;
  u8 result_buf[28];
  ext_43e8e0(result_buf, ptr1, floats_buf);

  vcall<void>(self, 0x7c, ptr1, ptr2);
}
PCREG(51cf10, fn_51cf10);
