// batch33032.cpp - h3 batch 33032: call wrappers (tier B)
#include "ff.h"

extern "C" void STDCALL ext_4de420(u32 arg);
extern "C" void STDCALL ext_462040(u32 arg);
extern "C" void STDCALL ext_4e1b30(u32 arg);

// 0x4db2a0, stdcall: call 0x4de420 with arg
static void STDCALL fn4db2a0(u32 arg) {
  ext_4de420(arg);
}
PCREG(4db2a0, fn4db2a0);

// 0x466340, stdcall: call 0x462040 with arg, then call 0x4e1b30 with arg
static void STDCALL fn466340(u32 arg) {
  ext_462040(arg);
  ext_4e1b30(arg);
}
PCREG(466340, fn466340);
