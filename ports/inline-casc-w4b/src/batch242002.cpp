// batch242002.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_440e10_thiscall2(u32, u32) __asm__("ext_440e10");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 FASTCALL lifted_42ad40(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @0_42ad40
  ebx = edx;  // @1_42ad40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_42ad40
  FL[2] = (esi & esi);  // @3_42ad40
  if (FL[2] == 0) goto L42ad99;  // @4_42ad40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @5_42ad40
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @6_42ad40
  if (FL[0] == FL[1]) goto L42ad75;  // @7_42ad40
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @8_42ad40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_42ad40
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_42ad40
  PV[3] = (u32)(ebx);  // @11_42ad40
  PV[4] = (u32)(ecx);  // @12_42ad40
  ecx = esi;  // @13_42ad40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[4], PV[3], PV[2], PV[1], PV[0]);  // @14_42ad40
  ecx = edx = 0;  // @15_42ad40
  return eax;  // @16_42ad40
  L42ad75:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_42ad40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @19_42ad40
  ecx = (u32)(ecx + 675);  // @20_42ad40
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_42ad40
    // @22_42ad40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @23_42ad40
  PV[5] = (u32)(eax);  // @24_42ad40
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_42ad40
  PV[7] = (u32)(ebx);  // @26_42ad40
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @27_42ad40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 64)))(ecx, PV[8], PV[7], PV[6], PV[5], PV[0]);   // hand fix: the push of a2 before the `je` is shared by both paths (lifter dropped it on this one)  // @28_42ad40
  ecx = edx = 0;  // @29_42ad40
  L42ad99:;
  return eax;  // @31_42ad40
}
PCREG(42ad40, lifted_42ad40);

extern "C" u32 THISCALL lifted_485ac0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_485ac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_485ac0
  eax = ext_4e5ea0_thiscall1(ecx);  // @2_485ac0
  ecx = edx = 0;  // @3_485ac0
  esi = eax;  // @4_485ac0
  edx = esi;  // @5_485ac0
  eax = (u32)(edx + 1);  // @6_485ac0
  L485ad6:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @8_485ac0
  edx = (edx + 1);  // @9_485ac0
  FL[3] = edx;  // @10_485ac0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @11_485ac0
  if (FL[2] != 0) goto L485ad6;  // @12_485ac0
  edx = (edx - eax);  // @13_485ac0
  FL[3] = edx;  // @14_485ac0
  FL[0] = edx; FL[1] = (u32)(128);  // @15_485ac0
  if (FL[0] < FL[1]) goto L485b08;  // @16_485ac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @17_485ac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_485ac0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6867104), (u32)(76));  // @19_485ac0
  ecx = edx = 0;  // @20_485ac0
  PV[0] = (u32)(esi);  // @21_485ac0
  PV[1] = (u32)(eax);  // @22_485ac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @23_485ac0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6867152), PV[0]);  // @24_485ac0
  ecx = edx = 0;  // @25_485ac0
  L485b08:;
  eax = (u32)(edi + 76);  // @27_485ac0
  PV[2] = (u32)(esi);  // @28_485ac0
  PV[3] = (u32)(eax);  // @29_485ac0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x67642c))(PV[3], PV[2], (u32)(128));  // @30_485ac0
  ecx = edx = 0;  // @31_485ac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @32_485ac0
  eax = ext_4e5e60_thiscall1(ecx);  // @33_485ac0
  ecx = edx = 0;  // @34_485ac0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @35_485ac0
  return eax;  // @36_485ac0
}
PCREG(485ac0, lifted_485ac0);

extern "C" u32 STDCALL lifted_5c6370(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_5c6370
  FL[2] = (esi & esi);  // @1_5c6370
  if (FL[2] == 0) goto L5c63da;  // @2_5c6370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_5c6370
  ecx = (u32)(EBP - 12);  // @4_5c6370
  PV[0] = (u32)(ecx);  // @5_5c6370
  ecx = esi;  // @6_5c6370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @7_5c6370
  ecx = edx = 0;  // @8_5c6370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_5c6370
  ecx = (u32)(EBP - 12);  // @10_5c6370
  PV[1] = (u32)(ecx);  // @11_5c6370
  ecx = esi;  // @12_5c6370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @13_5c6370
  ecx = edx = 0;  // @14_5c6370
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @15_5c6370
  edx = eax;  // @16_5c6370
  if (FL[0] == FL[1]) goto L5c63da;  // @17_5c6370
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xff);  // @18_5c6370
  L5c63a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_5c6370
  PV[2] = (u32)(edx);  // @21_5c6370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @22_5c6370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_5c6370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[2]);  // @24_5c6370
  ecx = edx = 0;  // @25_5c6370
  FL[2] = (eax & eax);  // @26_5c6370
  if (FL[2] == 0) goto L5c63c6;  // @27_5c6370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_5c6370
  ecx = eax;  // @29_5c6370
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @30_5c6370
  if (FL[2] == 0) goto L5c63c3;  // @31_5c6370
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 44)))(ecx);  // @32_5c6370
  ecx = edx = 0;  // @33_5c6370
  goto L5c63c6;  // @34_5c6370
  L5c63c3:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @36_5c6370
  ecx = edx = 0;  // @37_5c6370
  L5c63c6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_5c6370
  ecx = (u32)(EBP - 12);  // @40_5c6370
  PV[3] = (u32)(ecx);  // @41_5c6370
  ecx = esi;  // @42_5c6370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @43_5c6370
  ecx = edx = 0;  // @44_5c6370
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @45_5c6370
  edx = eax;  // @46_5c6370
  if (FL[0] != FL[1]) goto L5c63a0;  // @47_5c6370
  L5c63da:;
  return eax;  // @49_5c6370
}
PCREG(5c6370, lifted_5c6370);

extern "C" u32 THISCALL lifted_46f520(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_46f520
  PV[0] = (u32)(esi);  // @1_46f520
  edi = ecx;  // @2_46f520
  eax = ext_440e10_thiscall2(ecx, PV[0]);  // @3_46f520
  ecx = edx = 0;  // @4_46f520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_46f520
  ecx = (u32)(EBP + 8);  // @6_46f520
  PV[1] = (u32)(ecx);  // @7_46f520
  ecx = esi;  // @8_46f520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[1]);  // @9_46f520
  ecx = edx = 0;  // @10_46f520
  ecx = (u32)(edi + 96);  // @11_46f520
  PV[2] = (u32)(ecx);  // @12_46f520
  ecx = eax;  // @13_46f520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_46f520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[2]);  // @15_46f520
  ecx = edx = 0;  // @16_46f520
  ecx = (u32)(edi + 100);  // @17_46f520
  PV[3] = (u32)(ecx);  // @18_46f520
  ecx = eax;  // @19_46f520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_46f520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[3]);  // @21_46f520
  ecx = edx = 0;  // @22_46f520
  ecx = (u32)(edi + 104);  // @23_46f520
  PV[4] = (u32)(ecx);  // @24_46f520
  ecx = eax;  // @25_46f520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_46f520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[4]);  // @27_46f520
  ecx = edx = 0;  // @28_46f520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @29_46f520
  ecx = esi;  // @30_46f520
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; });  // @31_46f520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 92), &v, sizeof v); }  // @32_46f520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_46f520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[5]);  // @34_46f520
  ecx = edx = 0;  // @35_46f520
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; });  // @36_46f520
  ecx = eax;  // @37_46f520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_46f520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[6]);  // @39_46f520
  ecx = edx = 0;  // @40_46f520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_46f520
  ecx = esi;  // @42_46f520
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 120), sizeof v); (u32)v; });  // @43_46f520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[7]);  // @44_46f520
  ecx = edx = 0;  // @45_46f520
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; });  // @46_46f520
  ecx = eax;  // @47_46f520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_46f520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[8]);  // @49_46f520
  ecx = edx = 0;  // @50_46f520
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @51_46f520
  return eax;  // @52_46f520
}
PCREG(46f520, lifted_46f520);

