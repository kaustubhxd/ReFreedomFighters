// batch242025.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_404ed0_cdecl7(...) __asm__("ext_404ed0");
extern "C" u32 ext_404fd0_cdecl9(...) __asm__("ext_404fd0");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_404bd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 100) + 108), sizeof v); (u32)v; });  // @0_404bd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 116), sizeof v); (u32)v; });  // @1_404bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 104) + 48), &v, sizeof v); }  // @2_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @4_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1228), sizeof v); (u32)v; });  // @5_404bd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 44), &v, sizeof v); }  // @6_404bd0
  FL[2] = (eax & eax);  // @7_404bd0
  if ((s32)FL[2] <= 0) goto L404ebe;  // @8_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 136), sizeof v); (u32)v; });  // @9_404bd0
  edi = eax;  // @10_404bd0
  ebq = (u32)(esi + 2256);  // @11_404bd0
  edi = (edi << (u32)(4));  // @12_404bd0
  FL[3] = edi;  // @13_404bd0
  edi = (edi + eax);  // @14_404bd0
  FL[3] = edi;  // @15_404bd0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 116) + 28), &v, sizeof v); }  // @16_404bd0
  ecx = (u32)(ecx + edi*8);  // @17_404bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 116) + 32), &v, sizeof v); }  // @18_404bd0
  goto L404c23;  // @19_404bd0
  L404c1f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 32), sizeof v); (u32)v; });  // @21_404bd0
  L404c23:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1892), sizeof v); (u32)v; });  // @23_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1896), sizeof v); (u32)v; });  // @24_404bd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 144), sizeof v); (u32)v; });  // @25_404bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 116) + 36), &v, sizeof v); }  // @26_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq - 1024), sizeof v); (u32)v; });  // @27_404bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 116) + 40), &v, sizeof v); }  // @28_404bd0
  ecx = (ecx << (u32)(2));  // @29_404bd0
  FL[3] = ecx;  // @30_404bd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @31_404bd0
  if (FL[0] != FL[1]) goto L404c5a;  // @32_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq), sizeof v); (u32)v; });  // @33_404bd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @34_404bd0
  if (FL[0] == FL[1]) goto L404e96;  // @35_404bd0
  L404c5a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 132), sizeof v); (u32)v; });  // @37_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq), sizeof v); (u32)v; });  // @38_404bd0
  eax = (eax << (u32)(2));  // @39_404bd0
  FL[3] = eax;  // @40_404bd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi), sizeof v); (u32)v; });  // @41_404bd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 116) + 68), &v, sizeof v); }  // @42_404bd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; });  // @43_404bd0
  ebx = (u32)(ebx + edx*4);  // @44_404bd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 116) + 64), &v, sizeof v); }  // @45_404bd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 136), sizeof v); (u32)v; });  // @46_404bd0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx), sizeof v); (u32)v; });  // @47_404bd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx), sizeof v); (u32)v; });  // @48_404bd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 116) + 76), &v, sizeof v); }  // @49_404bd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 140), sizeof v); (u32)v; });  // @50_404bd0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 116) + 72), &v, sizeof v); }  // @51_404bd0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx), sizeof v); (u32)v; });  // @52_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx), sizeof v); (u32)v; });  // @53_404bd0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 116) + 80), &v, sizeof v); }  // @54_404bd0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 28), sizeof v); (u32)v; });  // @55_404bd0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + edi), &v, sizeof v); }  // @56_404bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 116) + 84), &v, sizeof v); }  // @57_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq), sizeof v); (u32)v; });  // @58_404bd0
  eax = 0;  // @59_404bd0
  FL[3] = eax;  // @60_404bd0
  FL[2] = (edx & edx);  // @61_404bd0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + ecx*4), &v, sizeof v); }  // @62_404bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 116) + 24), &v, sizeof v); }  // @63_404bd0
  if ((s32)FL[2] <= 0) goto L404e96;  // @64_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 32), sizeof v); (u32)v; });  // @65_404bd0
  ecx = (ecx + (u32)(1900));  // @66_404bd0
  FL[3] = ecx;  // @67_404bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 116) + 148), &v, sizeof v); }  // @68_404bd0
  L404cd6:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @70_404bd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 116) + 52), &v, sizeof v); }  // @71_404bd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @72_404bd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 116) + 108), &v, sizeof v); }  // @73_404bd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_404bd0
  FL[0] = eax; FL[1] = edi;  // @75_404bd0
  if ((s32)FL[0] >= (s32)FL[1]) goto L404e80;  // @76_404bd0
  ecx = (u32)(esi + edx*4);  // @77_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 64), sizeof v); (u32)v; });  // @78_404bd0
  ecx = (ecx - edx);  // @79_404bd0
  FL[3] = ecx;  // @80_404bd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 80), sizeof v); (u32)v; });  // @81_404bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 116) + 104), &v, sizeof v); }  // @82_404bd0
  ecx = edx;  // @83_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 72), sizeof v); (u32)v; });  // @84_404bd0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 84), sizeof v); (u32)v; });  // @85_404bd0
  ecx = (ecx - esi);  // @86_404bd0
  FL[3] = ecx;  // @87_404bd0
  edx = (edx - esi);  // @88_404bd0
  FL[3] = edx;  // @89_404bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 116) + 92), &v, sizeof v); }  // @90_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 68), sizeof v); (u32)v; });  // @91_404bd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 116) + 112), &v, sizeof v); }  // @92_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 76), sizeof v); (u32)v; });  // @93_404bd0
  ecx = (ecx - esi);  // @94_404bd0
  FL[3] = ecx;  // @95_404bd0
  edx = (edx - esi);  // @96_404bd0
  FL[3] = edx;  // @97_404bd0
  ebx = (ebx - esi);  // @98_404bd0
  FL[3] = ebx;  // @99_404bd0
  edi = (u32)(esi + eax*4);  // @100_404bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 116) + 88), &v, sizeof v); }  // @101_404bd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 116) + 116), &v, sizeof v); }  // @102_404bd0
  ebq = (ebq - esi);  // @103_404bd0
  FL[3] = ebq;  // @104_404bd0
  goto L404d3a;  // @105_404bd0
  L404d32:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 88), sizeof v); (u32)v; });  // @107_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 24), sizeof v); (u32)v; });  // @108_404bd0
  L404d3a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 124), sizeof v); (u32)v; });  // @110_404bd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @111_404bd0
  if ((s32)FL[0] >= (s32)FL[1]) goto L404e75;  // @112_404bd0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + edi)) : "st");  // @113_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @114_404bd0
  __asm__ volatile("fsts %0" : "=m"(*(float *)(u32)((EBP - 116) + 20)) :: "st");  // @115_404bd0
  __asm__ volatile("fabs" ::: "st");  // @116_404bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 116) + 16), &v, sizeof v); }  // @117_404bd0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 116) + 16)) : "st");  // @118_404bd0
  __asm__ volatile("fabs" ::: "st");  // @119_404bd0
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 116) + 96)) :: "st");  // @120_404bd0
  __asm__ volatile("fcoml %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(double *)(u32)((EBP - 116) + 96)) : "st", "cc");  // @121_404bd0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @122_404bd0
  FL[2] = ((eax >> 8) & 65);  // @123_404bd0
  if (FL[2] != 0) goto L404d73;  // @124_404bd0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + edi)) : "st");  // @125_404bd0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 116) + 20)) :: "st");  // @126_404bd0
  goto L404d7f;  // @127_404bd0
  L404d73:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @129_404bd0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @130_404bd0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 116) + 96)) : "st");  // @131_404bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 116) + 16), &v, sizeof v); }  // @132_404bd0
  L404d7f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 148), sizeof v); (u32)v; });  // @134_404bd0
  __asm__ volatile("fsts %0" : "=m"(*(float *)(u32)((EBP - 116) + 96)) :: "st");  // @135_404bd0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(edx + 12)) : "st", "cc");  // @136_404bd0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @137_404bd0
  FL[2] = ((eax >> 8) & 1);  // @138_404bd0
  if (FL[2] == 0) goto L404dd2;  // @139_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 92), sizeof v); (u32)v; });  // @140_404bd0
  ecx = (u32)((EBP - 116) + 48);  // @141_404bd0
  edx = (u32)((EBP - 116) + 44);  // @142_404bd0
  PV[0] = (u32)(ecx);  // @143_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 120) + 100), sizeof v); (u32)v; });  // @144_404bd0
  PV[1] = (u32)(edx);  // @145_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 124) + 44), sizeof v); (u32)v; });  // @146_404bd0
  PV[2] = (u32)(ecx);  // @147_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 128) + 52), sizeof v); (u32)v; });  // @148_404bd0
  PV[3] = (u32)(edx);  // @149_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 132) + 120), sizeof v); (u32)v; });  // @150_404bd0
  eax = (eax + edi);  // @151_404bd0
  FL[3] = eax;  // @152_404bd0
  PV[4] = (u32)(ecx);  // @153_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; });  // @154_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @155_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 136) + 36), sizeof v); (u32)v; });  // @156_404bd0
  PV[5] = (u32)(ecx);  // @157_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 140) + 44), sizeof v); (u32)v; });  // @158_404bd0
  PV[6] = (u32)(edx);  // @159_404bd0
  PV[7] = (u32)(eax);  // @160_404bd0
  PV[8] = (u32)(ecx);  // @161_404bd0
  eax = ext_404fd0_cdecl9(PV[8], PV[7], PV[6], PV[5], PV[4], PV[3], PV[2], PV[1], PV[0]);  // @162_404bd0
  ecx = edx = 0;  // @163_404bd0
  goto L404dfd;  // @164_404bd0
  L404dd2:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 108), sizeof v); (u32)v; });  // @166_404bd0
  eax = (u32)((EBP - 116) + 48);  // @167_404bd0
  PV[9] = (u32)(edx);  // @168_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 120) + 40), sizeof v); (u32)v; });  // @169_404bd0
  ecx = (u32)((EBP - 120) + 48);  // @170_404bd0
  PV[10] = (u32)(eax);  // @171_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 124) + 48), sizeof v); (u32)v; });  // @172_404bd0
  PV[11] = (u32)(ecx);  // @173_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 128) + 28), sizeof v); (u32)v; });  // @174_404bd0
  PV[12] = (u32)(edx);  // @175_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 132) + 36), sizeof v); (u32)v; });  // @176_404bd0
  PV[13] = (u32)(eax);  // @177_404bd0
  PV[14] = (u32)(ecx);  // @178_404bd0
  PV[15] = (u32)(edx);  // @179_404bd0
  eax = ext_404ed0_cdecl7(PV[15], PV[14], PV[13], PV[12], PV[11], PV[10], PV[9]);  // @180_404bd0
  ecx = edx = 0;  // @181_404bd0
  L404dfd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 112), sizeof v); (u32)v; });  // @183_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 116), sizeof v); (u32)v; });  // @184_404bd0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 116) + 44)) : "st");  // @185_404bd0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + edi)) : "st");  // @186_404bd0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx + edi)) :: "st");  // @187_404bd0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 116) + 48)) : "st");  // @188_404bd0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx + edi)) : "st");  // @189_404bd0
  __asm__ volatile("fsts %0" : "=m"(*(float *)(u32)((EBP - 116) + 20)) :: "st");  // @190_404bd0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + ebq)) :: "st");  // @191_404bd0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 116) + 52)) : "st");  // @192_404bd0
  __asm__ volatile("fchs" ::: "st");  // @193_404bd0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)((EBP - 116) + 20)) : "st", "cc");  // @194_404bd0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @195_404bd0
  FL[2] = ((eax >> 8) & 65);  // @196_404bd0
  if (FL[2] == 0) goto L404e3d;  // @197_404bd0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 116) + 20)) : "st");  // @198_404bd0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)((EBP - 116) + 52)) : "st", "cc");  // @199_404bd0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @200_404bd0
  FL[2] = ((eax >> 8) & 65);  // @201_404bd0
  if (FL[2] != 0) goto L404e4b;  // @202_404bd0
  L404e3d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + edi), &v, sizeof v); }  // @204_404bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + ebq), &v, sizeof v); }  // @205_404bd0
  L404e4b:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 148), sizeof v); (u32)v; });  // @207_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 24), sizeof v); (u32)v; });  // @208_404bd0
  eax = (eax + 1);  // @209_404bd0
  FL[3] = eax;  // @210_404bd0
  edi = (edi + (u32)(4));  // @211_404bd0
  FL[3] = edi;  // @212_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @213_404bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 116) + 24), &v, sizeof v); }  // @214_404bd0
  FL[0] = eax; FL[1] = ecx;  // @215_404bd0
  if ((s32)FL[0] < (s32)FL[1]) goto L404d32;  // @216_404bd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 56), sizeof v); (u32)v; });  // @217_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 148), sizeof v); (u32)v; });  // @218_404bd0
  goto L404e80;  // @219_404bd0
  L404e75:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 56), sizeof v); (u32)v; });  // @221_404bd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 148), sizeof v); (u32)v; });  // @222_404bd0
  L404e80:;
  ecx = (ecx + (u32)(16));  // @224_404bd0
  FL[3] = ecx;  // @225_404bd0
  FL[0] = eax; FL[1] = edx;  // @226_404bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 116) + 148), &v, sizeof v); }  // @227_404bd0
  if ((s32)FL[0] < (s32)FL[1]) goto L404cd6;  // @228_404bd0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 28), sizeof v); (u32)v; });  // @229_404bd0
  L404e96:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 128), sizeof v); (u32)v; });  // @231_404bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 60), sizeof v); (u32)v; });  // @232_404bd0
  eax = (eax + 1);  // @233_404bd0
  FL[3] = eax;  // @234_404bd0
  ebq = (ebq + (u32)(4));  // @235_404bd0
  FL[3] = ebq;  // @236_404bd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1228), sizeof v); (u32)v; });  // @237_404bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 116) + 60), &v, sizeof v); }  // @238_404bd0
  FL[0] = eax; FL[1] = esi;  // @239_404bd0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 116) + 28), &v, sizeof v); }  // @240_404bd0
  if ((s32)FL[0] < (s32)FL[1]) goto L404c1f;  // @241_404bd0
  L404ebe:;
  return eax;  // @243_404bd0
}
PCREG(404bd0, lifted_404bd0);

extern "C" u32 lifted_40e5e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 64), sizeof v); (u32)v; });  // @0_40e5e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @1_40e5e0
  ebq = eax;  // @2_40e5e0
  ebq = (u32)((s32)ebq * (s32)esi);  // @3_40e5e0
  FL[3] = ebq;  // @4_40e5e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @5_40e5e0
  ecx = (u32)(eax + eax*2);  // @6_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 52), &v, sizeof v); }  // @7_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @8_40e5e0
  FL[2] = (esi & esi);  // @9_40e5e0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 72) + 68), &v, sizeof v); }  // @10_40e5e0
  edx = (u32)(eax + eax);  // @11_40e5e0
  if ((s32)FL[2] <= 0) goto L40e6b3;  // @12_40e5e0
  edx = (u32)(ecx + edx*4);  // @13_40e5e0
  esi = ecx;  // @14_40e5e0
  ecx = (u32)(ebq + ebq);  // @15_40e5e0
  edi = (u32)(eax*4);  // @16_40e5e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 72) + 20), &v, sizeof v); }  // @17_40e5e0
  ecx = (u32)(ebx + ecx*4);  // @18_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 28), &v, sizeof v); }  // @19_40e5e0
  ecx = (u32)(ebx + ebq*4);  // @20_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 24), &v, sizeof v); }  // @21_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 84), sizeof v); (u32)v; });  // @22_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 32), &v, sizeof v); }  // @23_40e5e0
  L40e63c:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx - 4)) : "st");  // @25_40e5e0
  __asm__ volatile(".byte 0xd8, 0xc0" ::: "st");  // @26_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7283740)) : "st");  // @27_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 20), sizeof v); (u32)v; });  // @28_40e5e0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @29_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @30_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 72) + 16)) :: "st");  // @31_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @32_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @33_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @34_40e5e0
  __asm__ volatile(".byte 0xd8, 0xc0" ::: "st");  // @35_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 24), sizeof v); (u32)v; });  // @36_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7283744)) : "st");  // @37_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 72) + 16)) : "st");  // @38_40e5e0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @39_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @40_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 28), sizeof v); (u32)v; });  // @41_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 72) + 16)) : "st");  // @42_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @43_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 20), sizeof v); (u32)v; });  // @44_40e5e0
  ecx = (ecx + edi);  // @45_40e5e0
  FL[3] = ecx;  // @46_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 20), &v, sizeof v); }  // @47_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 24), sizeof v); (u32)v; });  // @48_40e5e0
  ecx = (ecx + edi);  // @49_40e5e0
  FL[3] = ecx;  // @50_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 24), &v, sizeof v); }  // @51_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 28), sizeof v); (u32)v; });  // @52_40e5e0
  ecx = (ecx + edi);  // @53_40e5e0
  FL[3] = ecx;  // @54_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 28), &v, sizeof v); }  // @55_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 56), sizeof v); (u32)v; });  // @56_40e5e0
  ecx = (ecx << (u32)(2));  // @57_40e5e0
  FL[3] = ecx;  // @58_40e5e0
  edx = (edx + ecx);  // @59_40e5e0
  FL[3] = edx;  // @60_40e5e0
  esi = (esi + ecx);  // @61_40e5e0
  FL[3] = esi;  // @62_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 32), sizeof v); (u32)v; });  // @63_40e5e0
  ecx = (ecx - 1);  // @64_40e5e0
  FL[3] = ecx;  // @65_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 32), &v, sizeof v); }  // @66_40e5e0
  if (FL[3] != 0) goto L40e63c;  // @67_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 88), sizeof v); (u32)v; });  // @68_40e5e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 84), sizeof v); (u32)v; });  // @69_40e5e0
  L40e6b3:;
  FL[0] = eax; FL[1] = (u32)(1);  // @71_40e5e0
  if (FL[0] == FL[1]) goto L40e8a6;  // @72_40e5e0
  edx = 0;  // @73_40e5e0
  FL[3] = edx;  // @74_40e5e0
  FL[0] = esi; FL[1] = edx;  // @75_40e5e0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40e8a6;  // @76_40e5e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 72) + 32), &v, sizeof v); }  // @77_40e5e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 72) + 24), &v, sizeof v); }  // @78_40e5e0
  edi = (u32)(eax + eax);  // @79_40e5e0
  edx = (u32)(eax + eax*2);  // @80_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 20), &v, sizeof v); }  // @81_40e5e0
  ebx = (u32)(ebx + ebq*8);  // @82_40e5e0
  edx = (edx << (u32)(2));  // @83_40e5e0
  FL[3] = edx;  // @84_40e5e0
  ecx = (u32)(ecx + edi*4);  // @85_40e5e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 72) + 72), &v, sizeof v); }  // @86_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 60), &v, sizeof v); }  // @87_40e5e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 72) + 52), &v, sizeof v); }  // @88_40e5e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 72) + 64), &v, sizeof v); }  // @89_40e5e0
  L40e6f1:;
  FL[0] = eax; FL[1] = (u32)(2);  // @91_40e5e0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40e85b;  // @92_40e5e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 32), sizeof v); (u32)v; });  // @93_40e5e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 72) + 84), &v, sizeof v); }  // @94_40e5e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 24), sizeof v); (u32)v; });  // @95_40e5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 100), sizeof v); (u32)v; });  // @96_40e5e0
  ebx = (ebx - edi);  // @97_40e5e0
  FL[3] = ebx;  // @98_40e5e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 92), sizeof v); (u32)v; });  // @99_40e5e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 20), sizeof v); (u32)v; });  // @100_40e5e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 72) + 88), &v, sizeof v); }  // @101_40e5e0
  edi = (u32)(edi + ebx*4);  // @102_40e5e0
  ebx = (ebx + ebq);  // @103_40e5e0
  FL[3] = ebx;  // @104_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 92), sizeof v); (u32)v; });  // @105_40e5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 96), sizeof v); (u32)v; });  // @106_40e5e0
  eax = (eax + (u32)(4));  // @107_40e5e0
  FL[3] = eax;  // @108_40e5e0
  edx = ecx;  // @109_40e5e0
  ebx = (u32)(ebq + ebx*4);  // @110_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 96), sizeof v); (u32)v; });  // @111_40e5e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 72) + 28), &v, sizeof v); }  // @112_40e5e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 100), sizeof v); (u32)v; });  // @113_40e5e0
  ebx = (ebx - ebq);  // @114_40e5e0
  FL[3] = ebx;  // @115_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 80), sizeof v); (u32)v; });  // @116_40e5e0
  ebq = (ebq - 1);  // @117_40e5e0
  FL[3] = ebq;  // @118_40e5e0
  ebq = (ebq >> (u32)(1));  // @119_40e5e0
  FL[3] = ebq;  // @120_40e5e0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 72) + 48), &v, sizeof v); }  // @121_40e5e0
  L40e747:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx - 12)) : "st");  // @123_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @124_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7283740)) : "st");  // @125_40e5e0
  edx = (edx - (u32)(8));  // @126_40e5e0
  FL[3] = edx;  // @127_40e5e0
  ecx = (ecx + (u32)(8));  // @128_40e5e0
  FL[3] = ecx;  // @129_40e5e0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @130_40e5e0
  esi = (esi + (u32)(8));  // @131_40e5e0
  FL[3] = esi;  // @132_40e5e0
  edi = (edi + (u32)(8));  // @133_40e5e0
  FL[3] = edi;  // @134_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 28), sizeof v); (u32)v; });  // @135_40e5e0
  eax = (eax + (u32)(8));  // @136_40e5e0
  FL[3] = eax;  // @137_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @138_40e5e0
  ebq = (ebq + (u32)(8));  // @139_40e5e0
  FL[3] = ebq;  // @140_40e5e0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 72) + 28), &v, sizeof v); }  // @141_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 84), sizeof v); (u32)v; });  // @142_40e5e0
  ebq = (ebq + (u32)(8));  // @143_40e5e0
  FL[3] = ebq;  // @144_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 72) + 16)) :: "st");  // @145_40e5e0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 72) + 84), &v, sizeof v); }  // @146_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 28), sizeof v); (u32)v; });  // @147_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @148_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi - 4)) :: "st");  // @149_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @150_40e5e0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @151_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7283740)) : "st");  // @152_40e5e0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @153_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @154_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 72) + 36)) :: "st");  // @155_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @156_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @157_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @158_40e5e0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edx - 4)) : "st");  // @159_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7283744)) : "st");  // @160_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @161_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @162_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7283744)) : "st");  // @163_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 72) + 16)) : "st");  // @164_40e5e0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @165_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 72) + 40)) :: "st");  // @166_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 72) + 16)) : "st");  // @167_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 72) + 44)) :: "st");  // @168_40e5e0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @169_40e5e0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 72) + 36)) : "st");  // @170_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 72) + 16)) :: "st");  // @171_40e5e0
  __asm__ volatile("fsubrs %0" :: "m"(*(float *)(u32)((EBP - 72) + 36)) : "st");  // @172_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 72) + 40)) : "st");  // @173_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax - 12)) : "st");  // @174_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 72) + 16)) : "st");  // @175_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax - 8)) : "st");  // @176_40e5e0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @177_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq - 4)) :: "st");  // @178_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 72) + 40)) : "st");  // @179_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax - 8)) : "st");  // @180_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 72) + 16)) : "st");  // @181_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax - 12)) : "st");  // @182_40e5e0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @183_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @184_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 88), sizeof v); (u32)v; });  // @185_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 72) + 44)) : "st");  // @186_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebq)) : "st");  // @187_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 84), sizeof v); (u32)v; });  // @188_40e5e0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @189_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx + eax - 8)) : "st");  // @190_40e5e0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @191_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq - 4)) :: "st");  // @192_40e5e0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 72) + 44)) : "st");  // @193_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx + eax - 8)) : "st");  // @194_40e5e0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @195_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 88), sizeof v); (u32)v; });  // @196_40e5e0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebq)) : "st");  // @197_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 84), sizeof v); (u32)v; });  // @198_40e5e0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @199_40e5e0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @200_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 88), sizeof v); (u32)v; });  // @201_40e5e0
  ebq = (ebq + (u32)(8));  // @202_40e5e0
  FL[3] = ebq;  // @203_40e5e0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 72) + 88), &v, sizeof v); }  // @204_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 48), sizeof v); (u32)v; });  // @205_40e5e0
  ebq = (ebq - 1);  // @206_40e5e0
  FL[3] = ebq;  // @207_40e5e0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 72) + 48), &v, sizeof v); }  // @208_40e5e0
  if (FL[3] != 0) goto L40e747;  // @209_40e5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 60), sizeof v); (u32)v; });  // @210_40e5e0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 68), sizeof v); (u32)v; });  // @211_40e5e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 72), sizeof v); (u32)v; });  // @212_40e5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 80), sizeof v); (u32)v; });  // @213_40e5e0
  L40e85b:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 52), sizeof v); (u32)v; });  // @215_40e5e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 24), sizeof v); (u32)v; });  // @216_40e5e0
  esi = (u32)(eax*4);  // @217_40e5e0
  ecx = (ecx + edx);  // @218_40e5e0
  FL[3] = ecx;  // @219_40e5e0
  ebx = (ebx + esi);  // @220_40e5e0
  FL[3] = ebx;  // @221_40e5e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 56), sizeof v); (u32)v; });  // @222_40e5e0
  edi = (edi + esi);  // @223_40e5e0
  FL[3] = edi;  // @224_40e5e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 20), sizeof v); (u32)v; });  // @225_40e5e0
  esi = (esi + edx);  // @226_40e5e0
  FL[3] = esi;  // @227_40e5e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 72) + 24), &v, sizeof v); }  // @228_40e5e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 32), sizeof v); (u32)v; });  // @229_40e5e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 72) + 20), &v, sizeof v); }  // @230_40e5e0
  esi = (u32)(eax + eax);  // @231_40e5e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 72) + 52), &v, sizeof v); }  // @232_40e5e0
  edi = (edi + esi);  // @233_40e5e0
  FL[3] = edi;  // @234_40e5e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 72) + 64), sizeof v); (u32)v; });  // @235_40e5e0
  esi = (esi - 1);  // @236_40e5e0
  FL[3] = esi;  // @237_40e5e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 72) + 60), &v, sizeof v); }  // @238_40e5e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 72) + 32), &v, sizeof v); }  // @239_40e5e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 72) + 64), &v, sizeof v); }  // @240_40e5e0
  if (FL[3] != 0) goto L40e6f1;  // @241_40e5e0
  L40e8a6:;
  return eax;  // @243_40e5e0
}
PCREG(40e5e0, lifted_40e5e0);

extern "C" u32 lifted_40d220(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 96), sizeof v); (u32)v; });  // @0_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 92) + 104), sizeof v); (u32)v; });  // @1_40d220
  ebq = eax;  // @2_40d220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 116), sizeof v); (u32)v; });  // @3_40d220
  ebq = (u32)((s32)ebq * (s32)ebx);  // @4_40d220
  FL[3] = ebq;  // @5_40d220
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 100) + 116), sizeof v); (u32)v; });  // @6_40d220
  FL[2] = (ebx & ebx);  // @7_40d220
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 104) + 80), &v, sizeof v); }  // @8_40d220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 104) + 28), &v, sizeof v); }  // @9_40d220
  if ((s32)FL[2] <= 0) goto L40d30e;  // @10_40d220
  ecx = (u32)(ebq + ebq*2);  // @11_40d220
  ebx = (u32)(esi + ebq*4);  // @12_40d220
  edi = (u32)(eax*4);  // @13_40d220
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 104) + 16), &v, sizeof v); }  // @14_40d220
  ecx = (u32)(esi + ecx*4);  // @15_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 40), &v, sizeof v); }  // @16_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 24), &v, sizeof v); }  // @17_40d220
  ecx = (u32)(esi + ebq*8);  // @18_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 20), &v, sizeof v); }  // @19_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 116), sizeof v); (u32)v; });  // @20_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 36), &v, sizeof v); }  // @21_40d220
  L40d27c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 24), sizeof v); (u32)v; });  // @23_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @24_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @25_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 20), sizeof v); (u32)v; });  // @26_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @27_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 16), sizeof v); (u32)v; });  // @28_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @29_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 28), sizeof v); (u32)v; });  // @30_40d220
  ecx = (ecx << (u32)(2));  // @31_40d220
  FL[3] = ecx;  // @32_40d220
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @33_40d220
  __asm__ volatile(".byte 0xd8, 0xc2" ::: "st");  // @34_40d220
  ebx = (u32)(edi + ecx);  // @35_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx*4)) :: "st");  // @36_40d220
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @37_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ebx*4 - 4)) :: "st");  // @38_40d220
  ebx = (u32)(eax + eax);  // @39_40d220
  ecx = (ecx + ebx);  // @40_40d220
  FL[3] = ecx;  // @41_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 16), sizeof v); (u32)v; });  // @42_40d220
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @43_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @44_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 20), sizeof v); (u32)v; });  // @45_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @46_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 24), sizeof v); (u32)v; });  // @47_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx*4 - 4)) :: "st");  // @48_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @49_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 40), sizeof v); (u32)v; });  // @50_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @51_40d220
  ebx = (ebx + edi);  // @52_40d220
  FL[3] = ebx;  // @53_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 40), &v, sizeof v); }  // @54_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx*4)) :: "st");  // @55_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 28), sizeof v); (u32)v; });  // @56_40d220
  ecx = (ecx + eax);  // @57_40d220
  FL[3] = ecx;  // @58_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 28), &v, sizeof v); }  // @59_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 16), sizeof v); (u32)v; });  // @60_40d220
  ecx = (ecx + edi);  // @61_40d220
  FL[3] = ecx;  // @62_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 16), &v, sizeof v); }  // @63_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 20), sizeof v); (u32)v; });  // @64_40d220
  ecx = (ecx + edi);  // @65_40d220
  FL[3] = ecx;  // @66_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 20), &v, sizeof v); }  // @67_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 24), sizeof v); (u32)v; });  // @68_40d220
  ecx = (ecx + edi);  // @69_40d220
  FL[3] = ecx;  // @70_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 24), &v, sizeof v); }  // @71_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 36), sizeof v); (u32)v; });  // @72_40d220
  ecx = (ecx - 1);  // @73_40d220
  FL[3] = ecx;  // @74_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 36), &v, sizeof v); }  // @75_40d220
  if (FL[3] != 0) goto L40d27c;  // @76_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 116), sizeof v); (u32)v; });  // @77_40d220
  L40d30e:;
  FL[0] = eax; FL[1] = (u32)(2);  // @79_40d220
  if ((s32)FL[0] < (s32)FL[1]) goto L40d67a;  // @80_40d220
  if (FL[0] == FL[1]) goto L40d5bc;  // @81_40d220
  edi = 0;  // @82_40d220
  FL[3] = edi;  // @83_40d220
  FL[2] = (ebx & ebx);  // @84_40d220
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 104) + 84), &v, sizeof v); }  // @85_40d220
  if ((s32)FL[2] <= 0) goto L40d5b4;  // @86_40d220
  ecx = (u32)(eax*4);  // @87_40d220
  ebx = (u32)(eax + eax);  // @88_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 104), &v, sizeof v); }  // @89_40d220
  ecx = eax;  // @90_40d220
  ecx = (ecx << (u32)(4));  // @91_40d220
  FL[3] = ecx;  // @92_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 100), &v, sizeof v); }  // @93_40d220
  ecx = (u32)(ebq + ebq*2);  // @94_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 92), &v, sizeof v); }  // @95_40d220
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 32), &v, sizeof v); }  // @96_40d220
  ecx = (u32)(esi + ecx*4);  // @97_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 40), &v, sizeof v); }  // @98_40d220
  ecx = (u32)(esi + ebq*4);  // @99_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 36), &v, sizeof v); }  // @100_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 116), sizeof v); (u32)v; });  // @101_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 88), &v, sizeof v); }  // @102_40d220
  goto L40d36a;  // @103_40d220
  L40d366:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 92), sizeof v); (u32)v; });  // @105_40d220
  L40d36a:;
  FL[0] = eax; FL[1] = (u32)(2);  // @107_40d220
  ecx = (u32)(ebx + edi*4);  // @108_40d220
  if ((s32)FL[0] <= (s32)FL[1]) goto L40d575;  // @109_40d220
  eax = (u32)(edx + ecx*4);  // @110_40d220
  ecx = (ecx + ebx);  // @111_40d220
  FL[3] = ecx;  // @112_40d220
  ebx = (u32)(ebx + edi*4);  // @113_40d220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 24), &v, sizeof v); }  // @114_40d220
  eax = (u32)(edx + ecx*4);  // @115_40d220
  ebq = (u32)(esi + edi*4);  // @116_40d220
  edx = (u32)(edx + ebx*4);  // @117_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 128), sizeof v); (u32)v; });  // @118_40d220
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 20), &v, sizeof v); }  // @119_40d220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 80), sizeof v); (u32)v; });  // @120_40d220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 16), &v, sizeof v); }  // @121_40d220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 136), sizeof v); (u32)v; });  // @122_40d220
  edx = (u32)(edi + edx*2);  // @123_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 32), sizeof v); (u32)v; });  // @124_40d220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 72), &v, sizeof v); }  // @125_40d220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 128), sizeof v); (u32)v; });  // @126_40d220
  esi = (u32)(esi + edx*4);  // @127_40d220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 132), sizeof v); (u32)v; });  // @128_40d220
  edx = (edx - ebx);  // @129_40d220
  FL[3] = edx;  // @130_40d220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 40), sizeof v); (u32)v; });  // @131_40d220
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 48), &v, sizeof v); }  // @132_40d220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 136), sizeof v); (u32)v; });  // @133_40d220
  edx = (edx - ebx);  // @134_40d220
  FL[3] = edx;  // @135_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 136), sizeof v); (u32)v; });  // @136_40d220
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 96), &v, sizeof v); }  // @137_40d220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 132), sizeof v); (u32)v; });  // @138_40d220
  edx = (edx - ebx);  // @139_40d220
  FL[3] = edx;  // @140_40d220
  eax = (eax + (u32)(4));  // @141_40d220
  FL[3] = eax;  // @142_40d220
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 44), &v, sizeof v); }  // @143_40d220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 112), sizeof v); (u32)v; });  // @144_40d220
  edx = (edx - 1);  // @145_40d220
  FL[3] = edx;  // @146_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 28), &v, sizeof v); }  // @147_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 36), sizeof v); (u32)v; });  // @148_40d220
  edx = (edx >> (u32)(1));  // @149_40d220
  FL[3] = edx;  // @150_40d220
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 76), &v, sizeof v); }  // @151_40d220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 72), sizeof v); (u32)v; });  // @152_40d220
  L40d406:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @154_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @155_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @156_40d220
  ecx = (ecx + (u32)(8));  // @157_40d220
  FL[3] = ecx;  // @158_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 28), sizeof v); (u32)v; });  // @159_40d220
  ebx = (ebx + (u32)(8));  // @160_40d220
  FL[3] = ebx;  // @161_40d220
  esi = (esi + (u32)(8));  // @162_40d220
  FL[3] = esi;  // @163_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @164_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 28), &v, sizeof v); }  // @165_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 20), sizeof v); (u32)v; });  // @166_40d220
  ebx = (ebx + (u32)(8));  // @167_40d220
  FL[3] = ebx;  // @168_40d220
  edi = (edi + (u32)(8));  // @169_40d220
  FL[3] = edi;  // @170_40d220
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @171_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @172_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @173_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @174_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @175_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 20), &v, sizeof v); }  // @176_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 24), sizeof v); (u32)v; });  // @177_40d220
  ebx = (ebx - (u32)(8));  // @178_40d220
  FL[3] = ebx;  // @179_40d220
  ebq = (ebq + (u32)(8));  // @180_40d220
  FL[3] = ebq;  // @181_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 24), &v, sizeof v); }  // @182_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 16), sizeof v); (u32)v; });  // @183_40d220
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @184_40d220
  ebx = (ebx - (u32)(8));  // @185_40d220
  FL[3] = ebx;  // @186_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 16), &v, sizeof v); }  // @187_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 44), sizeof v); (u32)v; });  // @188_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 52)) :: "st");  // @189_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @190_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx + edx)) : "st");  // @191_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 48), sizeof v); (u32)v; });  // @192_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx + eax)) : "st");  // @193_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @194_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 44), sizeof v); (u32)v; });  // @195_40d220
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @196_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 64)) :: "st");  // @197_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @198_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx + edx)) : "st");  // @199_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 48), sizeof v); (u32)v; });  // @200_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @201_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx + eax)) : "st");  // @202_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 96), sizeof v); (u32)v; });  // @203_40d220
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @204_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 60)) :: "st");  // @205_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx + eax)) : "st");  // @206_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @207_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi - 4)) : "st");  // @208_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @209_40d220
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @210_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @211_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @212_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi - 4)) : "st");  // @213_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx + eax)) : "st");  // @214_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 28), sizeof v); (u32)v; });  // @215_40d220
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @216_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 56)) :: "st");  // @217_40d220
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @218_40d220
  __asm__ volatile(".byte 0xd8, 0xc2" ::: "st");  // @219_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 68)) :: "st");  // @220_40d220
  __asm__ volatile(".byte 0xde, 0xe1" ::: "st");  // @221_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 56)) : "st");  // @222_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 104) + 52)) : "st");  // @223_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 72)) :: "st");  // @224_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 52)) : "st");  // @225_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 104) + 56)) : "st");  // @226_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 60)) : "st");  // @227_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebq)) : "st");  // @228_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 52)) :: "st");  // @229_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebq)) : "st");  // @230_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 104) + 60)) : "st");  // @231_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 60)) :: "st");  // @232_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 64)) : "st");  // @233_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebq - 4)) : "st");  // @234_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 56)) :: "st");  // @235_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebq - 4)) : "st");  // @236_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 104) + 64)) : "st");  // @237_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 56)) : "st");  // @238_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 104) + 68)) : "st");  // @239_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx - 4)) :: "st");  // @240_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 52)) : "st");  // @241_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 104) + 72)) : "st");  // @242_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @243_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 24), sizeof v); (u32)v; });  // @244_40d220
  eax = (eax + (u32)(8));  // @245_40d220
  FL[3] = eax;  // @246_40d220
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @247_40d220
  __asm__ volatile(".byte 0xd8, 0xe2" ::: "st");  // @248_40d220
  edx = (edx + (u32)(8));  // @249_40d220
  FL[3] = edx;  // @250_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx - 4)) :: "st");  // @251_40d220
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @252_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 104) + 60)) : "st");  // @253_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @254_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 20), sizeof v); (u32)v; });  // @255_40d220
  __asm__ volatile(".byte 0xd8, 0xc1" ::: "st");  // @256_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx - 4)) :: "st");  // @257_40d220
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @258_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 60)) : "st");  // @259_40d220
  __asm__ volatile(".byte 0xd8, 0xc1" ::: "st");  // @260_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @261_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 16), sizeof v); (u32)v; });  // @262_40d220
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @263_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 56)) : "st");  // @264_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 104) + 68)) : "st");  // @265_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx - 4)) :: "st");  // @266_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 104) + 72)) : "st");  // @267_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 104) + 52)) : "st");  // @268_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @269_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 76), sizeof v); (u32)v; });  // @270_40d220
  ebx = (ebx - 1);  // @271_40d220
  FL[3] = ebx;  // @272_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 76), &v, sizeof v); }  // @273_40d220
  if (FL[3] != 0) goto L40d406;  // @274_40d220
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 120), sizeof v); (u32)v; });  // @275_40d220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 124), sizeof v); (u32)v; });  // @276_40d220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 84), sizeof v); (u32)v; });  // @277_40d220
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 80), sizeof v); (u32)v; });  // @278_40d220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 112), sizeof v); (u32)v; });  // @279_40d220
  L40d575:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 100), sizeof v); (u32)v; });  // @281_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 32), sizeof v); (u32)v; });  // @282_40d220
  ebx = (ebx + ecx);  // @283_40d220
  FL[3] = ebx;  // @284_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 104), sizeof v); (u32)v; });  // @285_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 32), &v, sizeof v); }  // @286_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 36), sizeof v); (u32)v; });  // @287_40d220
  ebx = (ebx + ecx);  // @288_40d220
  FL[3] = ebx;  // @289_40d220
  edi = (edi + eax);  // @290_40d220
  FL[3] = edi;  // @291_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 36), &v, sizeof v); }  // @292_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 40), sizeof v); (u32)v; });  // @293_40d220
  ebx = (ebx + ecx);  // @294_40d220
  FL[3] = ebx;  // @295_40d220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 88), sizeof v); (u32)v; });  // @296_40d220
  ecx = (ecx - 1);  // @297_40d220
  FL[3] = ecx;  // @298_40d220
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 104) + 84), &v, sizeof v); }  // @299_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 40), &v, sizeof v); }  // @300_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 88), &v, sizeof v); }  // @301_40d220
  if (FL[3] != 0) goto L40d366;  // @302_40d220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 116), sizeof v); (u32)v; });  // @303_40d220
  L40d5b4:;
  FL[2] = ((eax & 0xff) & (u32)(1));  // @305_40d220
  if (FL[2] != 0) goto L40d67a;  // @306_40d220
  L40d5bc:;
  FL[2] = (ebx & ebx);  // @308_40d220
  edi = (u32)(eax + ebq - 1);  // @309_40d220
  ecx = (u32)(eax*4);  // @310_40d220
  if ((s32)FL[2] <= 0) goto L40d67a;  // @311_40d220
  ecx = (ecx << (u32)(2));  // @312_40d220
  FL[3] = ecx;  // @313_40d220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 128), &v, sizeof v); }  // @314_40d220
  ecx = (u32)(eax*4);  // @315_40d220
  eax = (u32)(eax + eax*2);  // @316_40d220
  ebx = (u32)(ecx + edx);  // @317_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 112), &v, sizeof v); }  // @318_40d220
  ebx = (u32)(edi + ebq*2);  // @319_40d220
  edx = (u32)(edx + eax*4);  // @320_40d220
  eax = (u32)(edi + ebq);  // @321_40d220
  ebx = (u32)(esi + ebx*4);  // @322_40d220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 136), &v, sizeof v); }  // @323_40d220
  ebx = (u32)(esi + edi*4);  // @324_40d220
  edi = (edi - ebq);  // @325_40d220
  FL[3] = edi;  // @326_40d220
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 112), sizeof v); (u32)v; });  // @327_40d220
  eax = (u32)(esi + eax*4);  // @328_40d220
  esi = (u32)(esi + edi*4);  // @329_40d220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 116), sizeof v); (u32)v; });  // @330_40d220
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 104) + 116), &v, sizeof v); }  // @331_40d220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 136), sizeof v); (u32)v; });  // @332_40d220
  goto L40d624;  // @333_40d220
  L40d61d:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 136), sizeof v); (u32)v; });  // @335_40d220
  L40d624:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @337_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @338_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7283732)) : "st");  // @339_40d220
  __asm__ volatile("fchs" ::: "st");  // @340_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @341_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @342_40d220
  edi = (edi + ecx);  // @343_40d220
  FL[3] = edi;  // @344_40d220
  ebx = (ebx + ecx);  // @345_40d220
  FL[3] = ebx;  // @346_40d220
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 104) + 136), &v, sizeof v); }  // @347_40d220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 128), sizeof v); (u32)v; });  // @348_40d220
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7283732)) : "st");  // @349_40d220
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @350_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @351_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq - 4)) :: "st");  // @352_40d220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @353_40d220
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @354_40d220
  esi = (esi + ecx);  // @355_40d220
  FL[3] = esi;  // @356_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 4)) :: "st");  // @357_40d220
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @358_40d220
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @359_40d220
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @360_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @361_40d220
  ebq = (ebq + edi);  // @362_40d220
  FL[3] = ebq;  // @363_40d220
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @364_40d220
  eax = (eax + ecx);  // @365_40d220
  FL[3] = eax;  // @366_40d220
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx)) :: "st");  // @367_40d220
  edx = (edx + edi);  // @368_40d220
  FL[3] = edx;  // @369_40d220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 116), sizeof v); (u32)v; });  // @370_40d220
  edi = (edi - 1);  // @371_40d220
  FL[3] = edi;  // @372_40d220
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 104) + 116), &v, sizeof v); }  // @373_40d220
  if (FL[3] != 0) goto L40d61d;  // @374_40d220
  L40d67a:;
  return eax;  // @376_40d220
}
PCREG(40d220, lifted_40d220);

