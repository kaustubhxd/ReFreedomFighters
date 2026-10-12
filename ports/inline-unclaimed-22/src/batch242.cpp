// batch242.cpp - unclaimed area 22 (docs/20-unclaimed-22.md). Three script-native wrappers that store a value in element 0
// of the argument array at a->[+8]. The exe pushes (value, 0) and calls 0x5003d0 (ret 4), which pops the index 0; the value
// stays on the stack and is the one stack word 0x5002f0 (ret 4) pops. So each is ext_5002f0(ext_5003d0(arr, 0), value).
// Names GUESS.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 index);   // original, thiscall, ret 4 (element getter)
extern "C" u8 *THISCALL ext_5002f0(u8 *self, u32 value);   // original, thiscall, ret 4 (stores value, sets the type byte)
extern "C" u32 THISCALL ext_5133d0(u8 *self, float f);     // original, thiscall, one float stack word, ret 4; al used

// 0x519dd0, thiscall(a) ret 4: value = this->[+0x14]->vtable[0x334](); element 0 of a->[+8] gets value.
static void THISCALL slot334Ret_519dd0(u8 *self, u8 *a) {
  u32 value = vcall<u32>(*(u8 **)(self + 0x14), 0x334);
  ext_5002f0(ext_5003d0(*(u8 **)(a + 8), 0), value);
}
PCREG(519dd0, slot334Ret_519dd0);

// 0x55b2d0, thiscall(a) ret 4: value = byte this->[+0x1c]->[+0x3e9]; element 0 of a->[+8] gets value.
static void THISCALL byte3e9Ret_55b2d0(u8 *self, u8 *a) {
  u32 value = *(u8 *)(*(u8 **)(self + 0x1c) + 0x3e9);
  ext_5002f0(ext_5003d0(*(u8 **)(a + 8), 0), value);
}
PCREG(55b2d0, byte3e9Ret_55b2d0);

// 0x519790, thiscall(a) ret 4: f = *(float *)element 0 of a->[+4]; r = (u8)0x5133d0(this->[+0x14], f) (the asm pushes ecx
// as a placeholder and overwrites it with the float); element 0 of a->[+8] gets r.
static void THISCALL floatArgRet_519790(u8 *self, u8 *a) {
  float f = *(float *)ext_5003d0(*(u8 **)(a + 4), 0);
  u32 r = (u8)ext_5133d0(*(u8 **)(self + 0x14), f);
  ext_5002f0(ext_5003d0(*(u8 **)(a + 8), 0), r);
}
PCREG(519790, floatArgRet_519790);
