// batch242003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4de7e0_fastcall2(u32, u32) __asm__("ext_4de7e0");
extern "C" u32 THISCALL ext_4b48c0_thiscall2(u32, u32) __asm__("ext_4b48c0");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db2a0_thiscall2(u32, u32) __asm__("ext_4db2a0");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_4db600_thiscall3(u32, u32, u32) __asm__("ext_4db600");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4dcf80_thiscall3(u32, u32, u32) __asm__("ext_4dcf80");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_4c4f10(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c4f10
  ecx = edi;  // @1_4c4f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_4c4f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @3_4c4f10
  ecx = edx = 0;  // @4_4c4f10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_4c4f10
  FL[2] = (ebx & ebx);  // @6_4c4f10
  if (FL[2] == 0) goto L4c4f73;  // @7_4c4f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_4c4f10
  ecx = (u32)(EBP - 12);  // @9_4c4f10
  PV[0] = (u32)(ecx);  // @10_4c4f10
  ecx = ebx;  // @11_4c4f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @12_4c4f10
  ecx = edx = 0;  // @13_4c4f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_4c4f10
  ecx = (u32)(EBP - 12);  // @15_4c4f10
  PV[1] = (u32)(ecx);  // @16_4c4f10
  ecx = ebx;  // @17_4c4f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @18_4c4f10
  ecx = edx = 0;  // @19_4c4f10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_4c4f10
  esi = eax;  // @21_4c4f10
  if (FL[0] == FL[1]) goto L4c4f72;  // @22_4c4f10
  L4c4f48:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @24_4c4f10
  ecx = eax;  // @25_4c4f10
  PV[2] = (u32)(esi);  // @26_4c4f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_4c4f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 40)))(ecx, PV[2]);  // @28_4c4f10
  ecx = edx = 0;  // @29_4c4f10
  FL[2] = (eax & eax);  // @30_4c4f10
  if (FL[2] != 0) goto L4c4f5f;  // @31_4c4f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_4c4f10
  ecx = edi;  // @33_4c4f10
  PV[3] = (u32)(esi);  // @34_4c4f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[3]);  // @35_4c4f10
  ecx = edx = 0;  // @36_4c4f10
  L4c4f5f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @38_4c4f10
  ecx = (u32)(EBP - 12);  // @39_4c4f10
  PV[4] = (u32)(ecx);  // @40_4c4f10
  ecx = ebx;  // @41_4c4f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @42_4c4f10
  ecx = edx = 0;  // @43_4c4f10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @44_4c4f10
  esi = eax;  // @45_4c4f10
  if (FL[0] != FL[1]) goto L4c4f48;  // @46_4c4f10
  L4c4f72:;
  L4c4f73:;
  return eax;  // @49_4c4f10
}
PCREG(4c4f10, lifted_4c4f10);

extern "C" u32 THISCALL lifted_46d5f0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_46d5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 880), sizeof v); (u32)v; });  // @1_46d5f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 480), sizeof v); (u32)v; });  // @2_46d5f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4 + 76), sizeof v); (u32)v; });  // @3_46d5f0
  FL[2] = (ecx & ecx);  // @4_46d5f0
  if (FL[2] == 0) goto L46d62c;  // @5_46d5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_46d5f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @7_46d5f0
  ecx = edx = 0;  // @8_46d5f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 480), &v, sizeof v); }  // @9_46d5f0
  L46d62c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_46d5f0
  ecx = edi;  // @12_46d5f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @13_46d5f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 708)))(ecx, PV[0], (u32)(1230259533));  // @14_46d5f0
  ecx = edx = 0;  // @15_46d5f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 480), &v, sizeof v); }  // @16_46d5f0
  ecx = eax;  // @17_46d5f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_46d5f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 856)))(ecx, (u32)(1));  // @19_46d5f0
  ecx = edx = 0;  // @20_46d5f0
  ecx = (u32)(EBP - 64);  // @21_46d5f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_46d5f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @23_46d5f0
  { u32 v = (u32)((u32)(1070141403)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @24_46d5f0
  eax = ext_4de7a0_thiscall1(ecx);  // @25_46d5f0
    // @26_46d5f0
  edx = (u32)(EBP - 16);  // @27_46d5f0
  ecx = (u32)(EBP - 64);  // @28_46d5f0
  eax = ext_4de7e0_fastcall2(ecx, edx);  // @29_46d5f0
  ecx = edx = 0;  // @30_46d5f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 480), sizeof v); (u32)v; });  // @31_46d5f0
  edx = (u32)(EBP - 28);  // @32_46d5f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @33_46d5f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @34_46d5f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @35_46d5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_46d5f0
  PV[1] = (u32)(edx);  // @37_46d5f0
  edx = (u32)(EBP - 64);  // @38_46d5f0
  PV[2] = (u32)(edx);  // @39_46d5f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 724)))(ecx, PV[2], PV[1]);  // @40_46d5f0
  ecx = edx = 0;  // @41_46d5f0
  ext_633654(G(u32, 0x6f5630));  // @42_46d5f0
  return eax;  // @43_46d5f0
}
PCREG(46d5f0, lifted_46d5f0);

extern "C" u32 THISCALL lifted_4c58e0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4c58e0
  esi = ecx;  // @1_4c58e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_4c58e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @3_4c58e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @4_4c58e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_4c58e0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @6_4c58e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_4c58e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @8_4c58e0
  ecx = edx = 0;  // @9_4c58e0
  edi = eax;  // @10_4c58e0
  FL[2] = (edi & edi);  // @11_4c58e0
  if (FL[2] == 0) goto L4c5977;  // @12_4c58e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @13_4c58e0
  eax = (u32)(EBP - 28);  // @14_4c58e0
  PV[1] = (u32)(eax);  // @15_4c58e0
  eax = ext_4daf90_thiscall2(ecx, PV[1]);  // @16_4c58e0
  edx = 0;  // @17_4c58e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_4c58e0
  eax = (u32)(EBP - 28);  // @19_4c58e0
  PV[2] = (u32)(eax);  // @20_4c58e0
  ecx = edi;  // @21_4c58e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[2]);  // @22_4c58e0
  ecx = edx = 0;  // @23_4c58e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @24_4c58e0
  edx = (u32)(EBP - 16);  // @25_4c58e0
  PV[3] = (u32)(edx);  // @26_4c58e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4c58e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[3]);  // @28_4c58e0
  ecx = edx = 0;  // @29_4c58e0
  eax = (u32)(esi + 76);  // @30_4c58e0
  PV[4] = (u32)(eax);  // @31_4c58e0
  edx = (u32)(EBP - 28);  // @32_4c58e0
  ecx = (u32)(EBP - 40);  // @33_4c58e0
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @34_4c58e0
  ecx = edx = 0;  // @35_4c58e0
  edx = (u32)(EBP - 40);  // @36_4c58e0
  ecx = (u32)(EBP - 76);  // @37_4c58e0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @38_4c58e0
  ecx = edx = 0;  // @39_4c58e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @40_4c58e0
  edx = (u32)(EBP - 40);  // @41_4c58e0
  PV[5] = (u32)(edx);  // @42_4c58e0
  edx = (u32)(EBP - 76);  // @43_4c58e0
  PV[6] = (u32)(edx);  // @44_4c58e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4c58e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[6], PV[5]);  // @46_4c58e0
  ecx = edx = 0;  // @47_4c58e0
  L4c5977:;
  ext_633654(G(u32, 0x6f5630));  // @49_4c58e0
  return eax;  // @50_4c58e0
}
PCREG(4c58e0, lifted_4c58e0);

extern "C" u32 THISCALL lifted_4b7f90(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4b7f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4b7f90
  esi = ecx;  // @2_4b7f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_4b7f90
  PV[0] = (u32)(edx);  // @4_4b7f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4b7f90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[0]);  // @6_4b7f90
  ecx = edx = 0;  // @7_4b7f90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_4b7f90
  edi = eax;  // @9_4b7f90
  ecx = edi;  // @10_4b7f90
  if (FL[0] != FL[1]) goto L4b7fd4;  // @11_4b7f90
  eax = (u32)(EBP - 16);  // @12_4b7f90
  PV[1] = (u32)(eax);  // @13_4b7f90
  eax = (u32)(EBP - 52);  // @14_4b7f90
  PV[2] = (u32)(eax);  // @15_4b7f90
  eax = ext_4db6c0_thiscall3(ecx, PV[2], PV[1]);  // @16_4b7f90
  ecx = edx = 0;  // @17_4b7f90
  goto L4b800d;  // @18_4b7f90
  L4b7fd4:;
  eax = (u32)(EBP - 52);  // @20_4b7f90
  PV[3] = (u32)(eax);  // @21_4b7f90
  eax = ext_4db2a0_thiscall2(ecx, PV[3]);  // @22_4b7f90
  ecx = edx = 0;  // @23_4b7f90
  eax = (u32)(EBP - 16);  // @24_4b7f90
  ecx = edi;  // @25_4b7f90
  PV[4] = (u32)(eax);  // @26_4b7f90
  eax = ext_4db500_thiscall2(ecx, PV[4]);  // @27_4b7f90
  edx = 0;  // @28_4b7f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4b7f90
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; });  // @30_4b7f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_4b7f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4b7f90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[5]);  // @33_4b7f90
  ecx = edx = 0;  // @34_4b7f90
  ecx = (u32)(EBP - 16);  // @35_4b7f90
  PV[6] = (u32)(ecx);  // @36_4b7f90
  ecx = (u32)(EBP - 52);  // @37_4b7f90
  PV[7] = (u32)(ecx);  // @38_4b7f90
  ecx = eax;  // @39_4b7f90
  eax = ext_4db600_thiscall3(ecx, PV[7], PV[6]);  // @40_4b7f90
  ecx = edx = 0;  // @41_4b7f90
  L4b800d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4b7f90
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @44_4b7f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_4b7f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4b7f90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[8]);  // @47_4b7f90
  ecx = edx = 0;  // @48_4b7f90
  edi = eax;  // @49_4b7f90
  FL[2] = (edi & edi);  // @50_4b7f90
  if (FL[2] == 0) goto L4b8067;  // @51_4b7f90
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @52_4b7f90
  ecx = esi;  // @53_4b7f90
  eax = ext_4b48c0_thiscall2(ecx, PV[9]);   // hand fix: thiscall (ecx = this), the lifter had dropped ecx  // @54_4b7f90
  ecx = edx = 0;  // @55_4b7f90
  FL[2] = (eax & eax);  // @56_4b7f90
  if (FL[2] == 0) goto L4b8058;  // @57_4b7f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @58_4b7f90
  ecx = (u32)(EBP - 16);  // @59_4b7f90
  PV[10] = (u32)(ecx);  // @60_4b7f90
  ecx = (u32)(EBP - 52);  // @61_4b7f90
  PV[11] = (u32)(ecx);  // @62_4b7f90
  ecx = eax;  // @63_4b7f90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 880)))(ecx, PV[11], PV[10]);  // @64_4b7f90
  ecx = edx = 0;  // @65_4b7f90
  ext_633654(G(u32, 0x6f5630));  // @66_4b7f90
  return eax;  // @67_4b7f90
  L4b8058:;
  eax = (u32)(EBP - 16);  // @69_4b7f90
  ecx = edi;  // @70_4b7f90
  PV[12] = (u32)(eax);  // @71_4b7f90
  eax = (u32)(EBP - 52);  // @72_4b7f90
  PV[13] = (u32)(eax);  // @73_4b7f90
  eax = ext_4dcf80_thiscall3(ecx, PV[13], PV[12]);  // @74_4b7f90
  ecx = edx = 0;  // @75_4b7f90
  L4b8067:;
  ext_633654(G(u32, 0x6f5630));  // @77_4b7f90
  return eax;  // @78_4b7f90
}
PCREG(4b7f90, lifted_4b7f90);

