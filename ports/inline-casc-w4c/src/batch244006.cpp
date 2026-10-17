// batch244006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_65a630_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_65a630");
extern "C" u32 STDCALL ext_65ae70_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_65ae70");
extern "C" u32 THISCALL ext_420a60_thiscall1(u32) __asm__("ext_420a60");
extern "C" u32 THISCALL ext_54e100_thiscall1(u32) __asm__("ext_54e100");
extern "C" u32 THISCALL ext_65b550_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_65b550");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_65bc60(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_65bc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_65bc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_65bc60
  FL[2] = (u32)(s32)(s8)(ecx & 0xff);  // @3_65bc60 (w4c: byte sign-extended before the signed jump)
  if ((s32)FL[2] < 0) goto L65bc82;  // @4_65bc60
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_65bc60
  ecx = ebx;  // @6_65bc60
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_65bc60
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_65bc60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[2], PV[1], PV[0]);  // @9_65bc60
  ecx = edx = 0;  // @10_65bc60
  return eax;  // @11_65bc60
  L65bc82:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @13_65bc60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @14_65bc60
  PV[3] = (u32)(ecx);  // @15_65bc60
  PV[4] = (u32)(edi);  // @16_65bc60
  PV[5] = (u32)(esi);  // @17_65bc60
  ecx = ebx;  // @18_65bc60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[5], PV[4], PV[3]);  // @19_65bc60
  ecx = edx = 0;  // @20_65bc60
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @21_65bc60
  ecx = ebx;  // @22_65bc60
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @23_65bc60
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @24_65bc60
  PV[9] = (u32)(edi);  // @25_65bc60
  PV[10] = (u32)(esi);  // @26_65bc60
  eax = ext_65a630_stdcall5(PV[10], PV[9], PV[8], PV[7], PV[6]);  // @27_65bc60
  ecx = edx = 0;  // @28_65bc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_65bc60
  ecx = ebx;  // @30_65bc60
  PV[11] = (u32)(edi);  // @31_65bc60
  PV[12] = (u32)(esi);  // @32_65bc60
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_65bc60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, PV[13], PV[12], PV[11]);  // @34_65bc60
  ecx = edx = 0;  // @35_65bc60
  return eax;  // @36_65bc60
}
PCREG(65bc60, lifted_65bc60);

extern "C" u32 THISCALL lifted_65bcc0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_65bcc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_65bcc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_65bcc0
  FL[2] = (u32)(s32)(s8)(ecx & 0xff);  // @3_65bcc0 (w4c: byte sign-extended before the signed jump)
  if ((s32)FL[2] < 0) goto L65bce2;  // @4_65bcc0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_65bcc0
  ecx = ebx;  // @6_65bcc0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_65bcc0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_65bcc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[2], PV[1], PV[0]);  // @9_65bcc0
  ecx = edx = 0;  // @10_65bcc0
  return eax;  // @11_65bcc0
  L65bce2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @13_65bcc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @14_65bcc0
  PV[3] = (u32)(ecx);  // @15_65bcc0
  PV[4] = (u32)(edi);  // @16_65bcc0
  PV[5] = (u32)(esi);  // @17_65bcc0
  ecx = ebx;  // @18_65bcc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[5], PV[4], PV[3]);  // @19_65bcc0
  ecx = edx = 0;  // @20_65bcc0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @21_65bcc0
  ecx = ebx;  // @22_65bcc0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @23_65bcc0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @24_65bcc0
  PV[9] = (u32)(edi);  // @25_65bcc0
  PV[10] = (u32)(esi);  // @26_65bcc0
  eax = ext_65ae70_stdcall5(PV[10], PV[9], PV[8], PV[7], PV[6]);  // @27_65bcc0
  ecx = edx = 0;  // @28_65bcc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_65bcc0
  ecx = ebx;  // @30_65bcc0
  PV[11] = (u32)(edi);  // @31_65bcc0
  PV[12] = (u32)(esi);  // @32_65bcc0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_65bcc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[13], PV[12], PV[11]);  // @34_65bcc0
  ecx = edx = 0;  // @35_65bcc0
  return eax;  // @36_65bcc0
}
PCREG(65bcc0, lifted_65bcc0);

extern "C" u32 THISCALL lifted_65bd20(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_65bd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_65bd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_65bd20
  FL[2] = (u32)(s32)(s8)(ecx & 0xff);  // @3_65bd20 (w4c: byte sign-extended before the signed jump)
  if ((s32)FL[2] < 0) goto L65bd42;  // @4_65bd20
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_65bd20
  ecx = ebx;  // @6_65bd20
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_65bd20
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_65bd20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[2], PV[1], PV[0]);  // @9_65bd20
  ecx = edx = 0;  // @10_65bd20
  return eax;  // @11_65bd20
  L65bd42:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @13_65bd20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @14_65bd20
  PV[3] = (u32)(ecx);  // @15_65bd20
  PV[4] = (u32)(edi);  // @16_65bd20
  PV[5] = (u32)(esi);  // @17_65bd20
  ecx = ebx;  // @18_65bd20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 28)))(ecx, PV[5], PV[4], PV[3]);  // @19_65bd20
  ecx = edx = 0;  // @20_65bd20
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @21_65bd20
  ecx = ebx;  // @22_65bd20
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @23_65bd20
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @24_65bd20
  PV[9] = (u32)(edi);  // @25_65bd20
  PV[10] = (u32)(esi);  // @26_65bd20
  eax = ext_65b550_thiscall6(ecx, PV[10], PV[9], PV[8], PV[7], PV[6]);  // @27_65bd20
  ecx = edx = 0;  // @28_65bd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_65bd20
  ecx = ebx;  // @30_65bd20
  PV[11] = (u32)(edi);  // @31_65bd20
  PV[12] = (u32)(esi);  // @32_65bd20
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_65bd20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[13], PV[12], PV[11]);  // @34_65bd20
  ecx = edx = 0;  // @35_65bd20
  return eax;  // @36_65bd20
}
PCREG(65bd20, lifted_65bd20);

extern "C" u32 THISCALL lifted_549df0(u32 ecx_in) {
  SEH_ENTER(0x66ac42);  // @h_549df0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_549df0
  eax = ext_41e290_cdecl1((u32)(750));  // @1_549df0
  ecx = edx = 0;  // @2_549df0
  esi = eax;  // @3_549df0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_549df0
  reg.state = (s32)((u32)(0));  // @5_549df0
  FL[2] = (esi & esi);  // @6_549df0
  if (FL[2] == 0) goto L549e43;  // @7_549df0
  ecx = esi;  // @8_549df0
  eax = ext_54e100_thiscall1(ecx);  // @9_549df0
  ecx = edx = 0;  // @10_549df0
  { u32 v = (u32)((u32)(6960108)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_549df0
  goto L549e45;  // @12_549df0
  L549e43:;
  esi = 0;  // @14_549df0
  FL[3] = esi;  // @15_549df0
  L549e45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 41582), sizeof v); (u32)v; });  // @17_549df0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 32865), &v, sizeof v); }  // @18_549df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 453), &v, sizeof v); }  // @19_549df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32865), sizeof v); (u32)v; });  // @20_549df0
  reg.state = (s32)((u32)(4294967295));  // @21_549df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_549df0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @23_549df0
  ecx = edx = 0;  // @24_549df0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @25_549df0
  SEH_LEAVE();  // @26_549df0
  return eax;  // @27_549df0
}
PCREG(549df0, lifted_549df0);

extern "C" u32 THISCALL lifted_650b90(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_650b90
  edi = ecx;  // @1_650b90
  PV[0] = (u32)(ebx);  // @2_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @3_650b90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_650b90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @8_650b90
  ecx = edx = 0;  // @9_650b90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @10_650b90
  PV[1] = (u32)(eax);  // @11_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 40)))(ecx, PV[1]);  // @12_650b90
  ecx = edx = 0;  // @13_650b90
  FL[2] = (eax & eax);  // @14_650b90
  if (FL[2] == 0) goto L650bfd;  // @15_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @16_650b90
  PV[2] = (u32)(ebx);  // @17_650b90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_650b90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @22_650b90
  ecx = edx = 0;  // @23_650b90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @24_650b90
  PV[3] = (u32)(eax);  // @25_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 60)))(ecx, PV[3]);  // @26_650b90
  ecx = edx = 0;  // @27_650b90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_650b90
  ecx = edi;  // @29_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 164)))(ecx, (u32)(0));  // @30_650b90
  ecx = edx = 0;  // @31_650b90
  FL[2] = (eax & eax);  // @32_650b90
  if (FL[2] == 0) goto L650bfd;  // @33_650b90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_650b90
  ecx = eax;  // @35_650b90
  PV[4] = (u32)(ebx);  // @36_650b90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 12)))(ecx, PV[4]);  // @37_650b90
  ecx = edx = 0;  // @38_650b90
  L650bfd:;
  return eax;  // @40_650b90
}
PCREG(650b90, lifted_650b90);

extern "C" u32 THISCALL lifted_420ae0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @0_420ae0
  ebx = ecx;  // @1_420ae0
  PV[0] = (u32)(ebx);  // @2_420ae0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_420ae0
  eax = ((u32(*)(u32, u32))(esi))(PV[0], (u32)(92));  // @4_420ae0
  ecx = edx = 0;  // @5_420ae0
  PV[1] = (u32)(ebx);  // @6_420ae0
  edi = eax;  // @7_420ae0
  eax = ((u32(*)(u32, u32))(esi))(PV[1], (u32)(92));  // @8_420ae0
  ecx = edx = 0;  // @9_420ae0
  ebx = eax;  // @10_420ae0
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @11_420ae0
  FL[3] = ebx;  // @12_420ae0
  FL[2] = (edi & edi);  // @13_420ae0
  if (FL[2] == 0) goto L420b40;  // @14_420ae0
  FL[0] = ebx; FL[1] = (u32)(2);  // @15_420ae0
  if (FL[0] == FL[1]) goto L420b40;  // @16_420ae0
  ecx = (u32)(ebx + 1);  // @17_420ae0
  PV[2] = (u32)(ecx);  // @18_420ae0
  eax = ext_41e290_cdecl1(PV[2]);  // @19_420ae0
  ecx = edx = 0;  // @20_420ae0
  PV[3] = (u32)(ebx);  // @21_420ae0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @22_420ae0
  esi = eax;  // @23_420ae0
  PV[5] = (u32)(esi);  // @24_420ae0
  eax = ((u32(*)(u32, u32, u32))(*(u32 *)0x67642c))  /* strncpy is cdecl */(PV[5], PV[4], PV[3]);  // @25_420ae0
  ecx = edx = 0;  // @26_420ae0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + ebx), &v, sizeof v); }  // @27_420ae0
  FL[2] = (esi & esi);  // @28_420ae0
  if (FL[2] == 0) goto L420b40;  // @29_420ae0
  ecx = esi;  // @30_420ae0
  eax = ext_420a60_thiscall1(ecx);  // @31_420ae0
  ecx = edx = 0;  // @32_420ae0
  PV[6] = (u32)(esi);  // @33_420ae0
  eax = ext_41e2c0_cdecl1(PV[6]);  // @34_420ae0
  ecx = edx = 0;  // @35_420ae0
  L420b40:;
  return eax;  // @37_420ae0
}
PCREG(420ae0, lifted_420ae0);

