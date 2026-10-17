// batch248001.cpp - Sonnet-w4e, hand-written ports of two frameless tail-call wrappers (the lifter rejects them).
#include "ff.h"
extern "C" u32 THISCALL ext_4da1d0_thiscall2(u32, u32) __asm__("ext_4da1d0");
extern "C" u32 THISCALL ext_466220_thiscall1(u32) __asm__("ext_466220");

extern "C" u32 THISCALL lifted_43df70(u32 ecx_in) {
  u32 ecx = ecx_in, eax = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @0_43df70
  eax = ext_4da1d0_thiscall2(ecx, 1);  // @1_43df70
  return eax;  // @2_43df70
}
PCREG(43df70, lifted_43df70);

extern "C" u32 THISCALL lifted_465650(u32 ecx_in) {
  u32 esi = 0, eax = 0;
  esi = ecx_in;  // @0_465650
  eax = ext_466220_thiscall1(ecx_in);  // @1_465650
  eax = esi;  // @2_465650
  return eax;  // @3_465650
}
PCREG(465650, lifted_465650);
