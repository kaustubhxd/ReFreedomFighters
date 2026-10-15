// batch75000.cpp - tier H slice 5 (t6, Haiku): 0x49a560 (46 insns, thiscall+arg).
#include "ff.h"

// 0x49a560 thiscall(arg): arg->count determines loop count; iterate calling vtable slots on this and arg.
static void THISCALL fn_49a560(void *self, void *arg) {
  u32 count = *(u32 *)arg;
  for (u32 i = 0; i < count; i++) {
    vcall<void>(arg, 0xc);
    vcall<void>(self, 0x14, arg);

    u32 v_loc8 = 0;
    vcall<u32>(self, 0x40, &v_loc8);

    float v_locf = 0.0f;
    vcall<float>(self, 0x50, &v_locf);

    vcall<void>(arg, 0x98, v_locf, 0, v_loc8);
  }
}
PCREG(49a560, fn_49a560);

