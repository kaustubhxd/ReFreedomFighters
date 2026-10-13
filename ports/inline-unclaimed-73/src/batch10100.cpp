// batch 101: simple residue 6 setters 0x5aede0, 0x4e1b60
#include "ff.h"

// 0x5aede0: thiscall, no arguments, returns this
static void *THISCALL guess5aede0(void *self) {
  *(u32 *)self = 0;
  return self;
}
PCREG(5aede0, guess5aede0);

// 0x4e1b60: thiscall, no arguments, returns this (multi-field setter)
static void *THISCALL guess4e1b60(void *self) {
  *(float *)((u8 *)self + 0x34) = 1.0f;  // 0x3f800000
  *(u32 *)((u8 *)self + 0x44) = 0;
  *(u8 *)((u8 *)self + 0x6c) = 1;
  return self;
}
PCREG(4e1b60, guess4e1b60);
