// batch33004.cpp - cascade h3: four small 2-instruction thiscall functions
#include "ff.h"

extern "C" void THISCALL ext_504870(u8 *self);  // tail jump target

// 0x4f22b0: read dword member at offset 0x1db
static u32 THISCALL fn4f22b0(u8 *self) {
  return *(u32 *)(self + 0x1db);
}
PCREG(4f22b0, fn4f22b0);

// 0x4f4d20: read byte member at offset 0x88
static u8 THISCALL fn4f4d20(u8 *self) {
  return self[0x88];
}
PCREG(4f4d20, fn4f4d20);

// 0x4f9f30: read dword member at offset 0x68
static u32 THISCALL fn4f9f30(u8 *self) {
  return *(u32 *)(self + 0x68);
}
PCREG(4f9f30, fn4f9f30);

// 0x506360: set vtable, tail jump
static void THISCALL fn506360(u8 *self) {
  *(u32 *)self = 0x69cf6c;
  ext_504870(self);
}
PCREG(506360, fn506360);
