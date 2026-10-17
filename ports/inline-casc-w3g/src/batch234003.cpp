// batch234003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_509b10(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_509b10
  edi = ecx;  // @1_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_509b10
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_509b10
  ecx = edx = 0;  // @4_509b10
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @5_509b10
  edx = (edx - (u32)(3));  // @6_509b10
  FL[3] = edx;  // @7_509b10
  if (FL[3] == 0) goto L509b7a;  // @8_509b10
  edx = (edx - (u32)(1));  // @9_509b10
  FL[3] = edx;  // @10_509b10
  if (FL[3] == 0) goto L509b71;  // @11_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @12_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_509b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(273));  // @14_509b10
  ecx = edx = 0;  // @15_509b10
  PV[0] = (u32)(eax);  // @16_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_509b10
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932912));  // @18_509b10
  ecx = edx = 0;  // @19_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_509b10
  FL[2] = (eax & eax);  // @21_509b10
  if (FL[2] == 0) goto L509b6c;  // @22_509b10
  eax = ((u32(STDCALL *)(void))(eax))();  // @23_509b10
  ecx = edx = 0;  // @24_509b10
  eax = 0;  // @25_509b10
  FL[3] = eax;  // @26_509b10
  goto L509b7c;  // @27_509b10
  L509b6c:;
  __builtin_trap();  // @29_509b10
  L509b71:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_509b10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @33_509b10
  ecx = edx = 0;  // @34_509b10
  goto L509b7c;  // @35_509b10
  L509b7a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @37_509b10
  L509b7c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @39_509b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @40_509b10
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @41_509b10
  ecx = edx = 0;  // @42_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @43_509b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @44_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @45_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @46_509b10
  FL[2] = (ecx & ecx);  // @47_509b10
  if (FL[2] == 0) goto L509c13;  // @48_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_509b10
  edx = (u32)(EBP - 20);  // @50_509b10
  PV[1] = (u32)(edx);  // @51_509b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @52_509b10
  ecx = edx = 0;  // @53_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @54_509b10
  edx = (u32)(EBP - 20);  // @55_509b10
  PV[2] = (u32)(edx);  // @56_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @57_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_509b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @59_509b10
  ecx = edx = 0;  // @60_509b10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @61_509b10
  ebx = eax;  // @62_509b10
  if (FL[0] == FL[1]) goto L509c12;  // @63_509b10
  L509bc0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @65_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_509b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @68_509b10
  eax = (u32)(EBP - 8);  // @69_509b10
  PV[3] = (u32)(eax);  // @70_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_509b10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6900844), (u32)(0), (u32)(6935060), (u32)(208), PV[3]);  // @72_509b10
  ecx = edx = 0;  // @73_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @74_509b10
  eax = (eax & 0xffff);  // @75_509b10
  PV[4] = (u32)(eax);  // @76_509b10
  PV[5] = (u32)(ebx);  // @77_509b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 300)))(ecx, PV[5], PV[4]);  // @78_509b10
  ecx = edx = 0;  // @79_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @80_509b10
  edx = (u32)(EBP - 20);  // @81_509b10
  PV[6] = (u32)(edx);  // @82_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @83_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_509b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @85_509b10
  ecx = edx = 0;  // @86_509b10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @87_509b10
  ebx = eax;  // @88_509b10
  if (FL[0] != FL[1]) goto L509bc0;  // @89_509b10
  L509c12:;
  L509c13:;
  return eax;  // @92_509b10
}
PCREG(509b10, lifted_509b10);

