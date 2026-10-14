// batch33015.cpp - cascade h3 tier B: four 6-instruction functions, mostly parameter setters
#include "ff.h"

extern "C" void THISCALL ext_641c90(u8 *self);

// 0x6461c0: load from offset, tail jump
static void THISCALL fn6461c0(u8 *self) {
  u8 *ptr = *(u8 **)(self + 0x291);
  ext_641c90(ptr);
}
PCREG(6461c0, fn6461c0);

// 0x446780: read parameter, write to offset 0x6c (stdcall)
static void STDCALL fn446780(u8 *self, u32 val) {
  *(u32 *)(self + 0x6c) = val;
}
PCREG(446780, fn446780);

// 0x4682d0: read parameter, write to offset 0x1d6 (stdcall)
static void STDCALL fn4682d0(u8 *self, u32 val) {
  *(u32 *)(self + 0x1d6) = val;
}
PCREG(4682d0, fn4682d0);

// 0x470c80: read parameter, write to offset 0x64 (stdcall)
static void STDCALL fn470c80(u8 *self, u32 val) {
  *(u32 *)(self + 0x64) = val;
}
PCREG(470c80, fn470c80);
