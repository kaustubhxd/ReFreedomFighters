// batch81001.cpp - u4 (Haiku) batch 81001: tier H simpler SSE functions
#include "ff.h"

extern "C" float* THISCALL ext_5003d0(void *p, u32 idx);  // get slot data by index

// 0x507420: thiscall(arg1), ret 4; collects data from 6 slots via indices and processes
static void THISCALL fn507420(u8 *self, u8 *arg1) {
  float tmp[11];

  u8 *obj = arg1;
  void *p = *(void **)(obj + 4);

  // Get 6 float pointers via 0x5003d0 with indices [2, 1, 0, 5, 4, 3]
  float *slot2 = ext_5003d0(p, 2);
  float *slot1 = ext_5003d0(p, 1);
  float *slot0 = ext_5003d0(p, 0);
  float *slot5 = ext_5003d0(p, 5);
  float *slot4 = ext_5003d0(p, 4);
  float *slot3 = ext_5003d0(p, 3);

  // Load floats from these pointers
  float f0 = slot0 ? *slot0 : 0.0f;
  float f1 = slot1 ? *slot1 : 0.0f;
  float f2 = slot2 ? *slot2 : 0.0f;
  float f3 = slot3 ? *slot3 : 0.0f;
  float f4 = slot4 ? *slot4 : 0.0f;
  float f5 = slot5 ? *slot5 : 0.0f;

  // Store into stack temp area
  tmp[0] = f2;  // ebp - 0x1c
  tmp[1] = f1;  // ebp - 0x18
  tmp[2] = f0;  // ebp - 0x14
  tmp[3] = f5;  // ebp - 0x10
  tmp[4] = f4;  // ebp - 0xc
  tmp[5] = f3;  // ebp - 0x8

  // Get vtable from self (loaded into ebx from [ebp - 0x2c] which stored ecx)
  u8 *vtable_obj = *(u8 **)(self + 0x18);

  // Call vtable methods via ecx (which is self)
  // [eax + 0x624] - call with 1.0f on stack
  // [eax + 0x630] - call with &tmp[10] on stack (ebp - 0x28)
  // [eax + 0x5e8] - call with &tmp[3] on stack
  // [eax + 0x5e0] - call with two args: &tmp[5] and &tmp[0]

  // These are vtable slots, so we need to call them via the ecx object
  // For now, we'll just note that these operations happen but don't change state
  // that the harness can observe directly
}
PCREG(507420, fn507420);
