// batch218024.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_46e800(u32 ecx_in) {
  SEH_ENTER(0x664d1b);  // @h_46e800
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_46e800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_46e800
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @2_46e800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_46e800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_46e800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @5_46e800
  ecx = edx = 0;  // @6_46e800
  ebx = eax;  // @7_46e800
  FL[2] = (ebx & ebx);  // @8_46e800
  if (FL[2] != 0) goto L46e899;  // @9_46e800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_46e800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_46e800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6850500), (u32)(1247));  // @12_46e800
  ecx = edx = 0;  // @13_46e800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_46e800
  edi = eax;  // @15_46e800
  eax = (u32)(EBP - 144);  // @16_46e800
  ecx = esi;  // @17_46e800
  PV[1] = (u32)(eax);  // @18_46e800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[1], (u32)(1));  // @19_46e800
  ecx = edx = 0;  // @20_46e800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @21_46e800
  ecx = eax;  // @22_46e800
  reg.state = (s32)(ebx);  // @23_46e800
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_46e800
  ecx = edx = 0;  // @25_46e800
  PV[2] = (u32)(eax);  // @26_46e800
  PV[3] = (u32)(edi);  // @27_46e800
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[3], (u32)(6851060), PV[2]);  // @28_46e800
  ecx = edx = 0;  // @29_46e800
  ecx = (u32)(EBP - 144);  // @30_46e800
  eax = ext_4cbec0_thiscall1(ecx);  // @31_46e800
  ecx = edx = 0;  // @32_46e800
  eax = ebx;  // @33_46e800
  L46e899:;
  SEH_LEAVE();  // @35_46e800
  ext_633654(G(u32, 0x6f5630));  // @36_46e800
  return eax;  // @37_46e800
}
PCREG(46e800, lifted_46e800);

