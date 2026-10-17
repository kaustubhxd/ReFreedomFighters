// batch242029.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_40d690(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9) {
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
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  __builtin_memcpy(F + 0x300 + 40, &a8, 4);
  __builtin_memcpy(F + 0x300 + 44, &a9, 4);
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 52) + 64)) : "st");  // @0_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 52) + 64), sizeof v); (u32)v; });  // @1_40d690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 52) + 60), sizeof v); (u32)v; });  // @2_40d690
  __asm__ volatile("fdivrs %0" :: "m"(*(float *)(u32)(7283736)) : "st");  // @3_40d690
  eax = (u32)(ecx + 1);  // @4_40d690
  eax = (u32)((s32)eax >> (u32)(1));  // @5_40d690
  FL[3] = eax;  // @6_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 64) + 12), &v, sizeof v); }  // @7_40d690
  eax = (u32)(edx - 1);  // @8_40d690
  eax = (u32)((s32)eax >> (u32)(1));  // @9_40d690
  FL[3] = eax;  // @10_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 64) + 32), &v, sizeof v); }  // @11_40d690
  eax = edx;  // @12_40d690
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @13_40d690
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; }));  // @14_40d690
  FL[3] = eax;  // @15_40d690
  __asm__ volatile(".byte 0xd9, 0xff" ::: "st");  // @16_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 76), &v, sizeof v); }  // @17_40d690
  eax = edx;  // @18_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 68) + 56)) :: "st");  // @19_40d690
  eax = (u32)((s32)eax * (s32)ecx);  // @20_40d690
  FL[3] = eax;  // @21_40d690
  __asm__ volatile(".byte 0xd9, 0xfe" ::: "st");  // @22_40d690
  FL[0] = edx; FL[1] = (u32)(1);  // @23_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 24), &v, sizeof v); }  // @24_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 68) + 52)) :: "st");  // @25_40d690
  if (FL[0] == FL[1]) goto L40db50;  // @26_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @27_40d690
  FL[2] = (esi & esi);  // @28_40d690
  if ((s32)FL[2] <= 0) goto L40d703;  // @29_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 108), sizeof v); (u32)v; });  // @30_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @31_40d690
  ecx = (ecx - eax);  // @32_40d690
  FL[3] = ecx;  // @33_40d690
  L40d6f8:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @35_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @36_40d690
  eax = (eax + (u32)(4));  // @37_40d690
  FL[3] = eax;  // @38_40d690
  esi = (esi - 1);  // @39_40d690
  FL[3] = esi;  // @40_40d690
  if (FL[3] != 0) goto L40d6f8;  // @41_40d690
  L40d703:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @43_40d690
  FL[0] = esi; FL[1] = (u32)(1);  // @44_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40d75e;  // @45_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @46_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @47_40d690
  ecx = (u32)(esi - 1);  // @48_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @49_40d690
  L40d71b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @51_40d690
  ecx = (ecx << (u32)(2));  // @52_40d690
  FL[3] = ecx;  // @53_40d690
  eax = (eax + ecx);  // @54_40d690
  FL[3] = eax;  // @55_40d690
  FL[2] = (ebx & ebx);  // @56_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @57_40d690
  if ((s32)FL[2] <= 0) goto L40d751;  // @58_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @59_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @60_40d690
  ecx = (ecx - esi);  // @61_40d690
  FL[3] = ecx;  // @62_40d690
  edi = (u32)(edx*4);  // @63_40d690
  esi = ebx;  // @64_40d690
  L40d73f:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @66_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @67_40d690
  eax = (eax + edi);  // @68_40d690
  FL[3] = eax;  // @69_40d690
  esi = (esi - 1);  // @70_40d690
  FL[3] = esi;  // @71_40d690
  if (FL[3] != 0) goto L40d73f;  // @72_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 60), sizeof v); (u32)v; });  // @73_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @74_40d690
  L40d751:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 32), sizeof v); (u32)v; });  // @76_40d690
  ecx = (ecx - 1);  // @77_40d690
  FL[3] = ecx;  // @78_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @79_40d690
  if (FL[3] != 0) goto L40d71b;  // @80_40d690
  goto L40d762;  // @81_40d690
  L40d75e:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @83_40d690
  L40d762:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 36), sizeof v); (u32)v; });  // @85_40d690
  eax = edx;  // @86_40d690
  FL[1] = eax;  // @87_40d690
  eax = (0u - eax);  // @88_40d690
  FL[0] = ecx; FL[1] = ebx;  // @89_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40d85a;  // @90_40d690
  FL[0] = esi; FL[1] = (u32)(1);  // @91_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40d928;  // @92_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @93_40d690
  edi = 0;  // @94_40d690
  FL[3] = edi;  // @95_40d690
  ecx = (ecx << (u32)(2));  // @96_40d690
  FL[3] = ecx;  // @97_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @98_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @99_40d690
  esi = (esi - 1);  // @100_40d690
  FL[3] = esi;  // @101_40d690
  eax = (u32)(ecx + eax*4 - 4);  // @102_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 20), &v, sizeof v); }  // @103_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @104_40d690
  L40d799:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 60), sizeof v); (u32)v; });  // @106_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @107_40d690
  edi = (edi + eax);  // @108_40d690
  FL[3] = edi;  // @109_40d690
  ecx = (u32)(edx*4);  // @110_40d690
  eax = edi;  // @111_40d690
  ebq = (ebq + ecx);  // @112_40d690
  FL[3] = ebq;  // @113_40d690
  eax = (eax - ecx);  // @114_40d690
  FL[3] = eax;  // @115_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @116_40d690
  FL[2] = (ebx & ebx);  // @117_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @118_40d690
  if ((s32)FL[2] <= 0) goto L40d846;  // @119_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @120_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @121_40d690
  ebq = (u32)(eax + ecx);  // @122_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @123_40d690
  eax = (u32)(eax + ecx - 4);  // @124_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @125_40d690
  L40d7d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @127_40d690
  eax = (u32)(edx*4);  // @128_40d690
  ebq = (ebq + eax);  // @129_40d690
  FL[3] = ebq;  // @130_40d690
  ecx = (ecx + eax);  // @131_40d690
  FL[3] = ecx;  // @132_40d690
  FL[0] = edx; FL[1] = (u32)(2);  // @133_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @134_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40d837;  // @135_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @136_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @137_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @138_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @139_40d690
  edi = (edi - esi);  // @140_40d690
  FL[3] = edi;  // @141_40d690
  esi = (u32)(edx - 1);  // @142_40d690
  ebx = ebq;  // @143_40d690
  esi = (esi >> (u32)(1));  // @144_40d690
  FL[3] = esi;  // @145_40d690
  L40d808:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 12)) : "st");  // @147_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @148_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @149_40d690
  eax = (eax + (u32)(8));  // @150_40d690
  FL[3] = eax;  // @151_40d690
  ecx = (ecx + (u32)(8));  // @152_40d690
  FL[3] = ecx;  // @153_40d690
  ebx = (ebx + (u32)(8));  // @154_40d690
  FL[3] = ebx;  // @155_40d690
  esi = (esi - 1);  // @156_40d690
  FL[3] = esi;  // @157_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @158_40d690
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @159_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + eax)) :: "st");  // @160_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @161_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @162_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @163_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @164_40d690
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @165_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @166_40d690
  if (FL[3] != 0) goto L40d808;  // @167_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @168_40d690
  L40d837:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 32), sizeof v); (u32)v; });  // @170_40d690
  eax = (eax - 1);  // @171_40d690
  FL[3] = eax;  // @172_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @173_40d690
  if (FL[3] != 0) goto L40d7d7;  // @174_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 48), sizeof v); (u32)v; });  // @175_40d690
  L40d846:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 20), sizeof v); (u32)v; });  // @177_40d690
  eax = (eax - 1);  // @178_40d690
  FL[3] = eax;  // @179_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 20), &v, sizeof v); }  // @180_40d690
  if (FL[3] != 0) goto L40d799;  // @181_40d690
  goto L40d928;  // @182_40d690
  L40d85a:;
  FL[0] = esi; FL[1] = (u32)(1);  // @184_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40d928;  // @185_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @186_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @187_40d690
  ebq = (u32)(edx*4);  // @188_40d690
  ecx = (u32)(ecx + eax*4 - 4);  // @189_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @190_40d690
  edi = (u32)(eax - 4);  // @191_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @192_40d690
  eax = (eax - 1);  // @193_40d690
  FL[3] = eax;  // @194_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @195_40d690
  L40d886:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @197_40d690
  ecx = (ecx + ebq);  // @198_40d690
  FL[3] = ecx;  // @199_40d690
  eax = (eax << (u32)(2));  // @200_40d690
  FL[3] = eax;  // @201_40d690
  esi = (esi + eax);  // @202_40d690
  FL[3] = esi;  // @203_40d690
  edi = (edi + eax);  // @204_40d690
  FL[3] = edi;  // @205_40d690
  FL[0] = edx; FL[1] = (u32)(2);  // @206_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 44), &v, sizeof v); }  // @207_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @208_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 40), &v, sizeof v); }  // @209_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40d919;  // @210_40d690
  eax = edi;  // @211_40d690
  edi = (u32)(edx - 1);  // @212_40d690
  edi = (edi >> (u32)(1));  // @213_40d690
  FL[3] = edi;  // @214_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @215_40d690
  L40d8af:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @217_40d690
  ecx = (ecx + (u32)(8));  // @218_40d690
  FL[3] = ecx;  // @219_40d690
  esi = (esi + (u32)(8));  // @220_40d690
  FL[3] = esi;  // @221_40d690
  eax = (eax + (u32)(8));  // @222_40d690
  FL[3] = eax;  // @223_40d690
  FL[2] = (edi & edi);  // @224_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @225_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @226_40d690
  if ((s32)FL[2] <= 0) goto L40d902;  // @227_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @228_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @229_40d690
  edi = (edi - ebx);  // @230_40d690
  FL[3] = edi;  // @231_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @232_40d690
  L40d8d6:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @234_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @235_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @236_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @237_40d690
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @238_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + edi)) :: "st");  // @239_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @240_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @241_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @242_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @243_40d690
  eax = (eax + ebq);  // @244_40d690
  FL[3] = eax;  // @245_40d690
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @246_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi)) :: "st");  // @247_40d690
  esi = (esi + ebq);  // @248_40d690
  FL[3] = esi;  // @249_40d690
  ebx = (ebx - 1);  // @250_40d690
  FL[3] = ebx;  // @251_40d690
  if (FL[3] != 0) goto L40d8d6;  // @252_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 60), sizeof v); (u32)v; });  // @253_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 48), sizeof v); (u32)v; });  // @254_40d690
  L40d902:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @256_40d690
  edi = (edi - 1);  // @257_40d690
  FL[3] = edi;  // @258_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @259_40d690
  if (FL[3] != 0) goto L40d8af;  // @260_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 44), sizeof v); (u32)v; });  // @261_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 40), sizeof v); (u32)v; });  // @262_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @263_40d690
  L40d919:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 32), sizeof v); (u32)v; });  // @265_40d690
  eax = (eax - 1);  // @266_40d690
  FL[3] = eax;  // @267_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @268_40d690
  if (FL[3] != 0) goto L40d886;  // @269_40d690
  L40d928:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @271_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @272_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 36), sizeof v); (u32)v; });  // @273_40d690
  ebq = (u32)((s32)ebq * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; }));  // @274_40d690
  FL[3] = ebq;  // @275_40d690
  ebx = 0;  // @276_40d690
  FL[3] = ebx;  // @277_40d690
  FL[0] = eax; FL[1] = ecx;  // @278_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @279_40d690
  if ((s32)FL[0] >= (s32)FL[1]) goto L40da44;  // @280_40d690
  FL[0] = eax; FL[1] = (u32)(1);  // @281_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40db50;  // @282_40d690
  eax = (eax - 1);  // @283_40d690
  FL[3] = eax;  // @284_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @285_40d690
  L40d955:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @287_40d690
  ebx = (ebx + eax);  // @288_40d690
  FL[3] = ebx;  // @289_40d690
  ebq = (ebq - eax);  // @290_40d690
  FL[3] = ebq;  // @291_40d690
  FL[0] = edx; FL[1] = (u32)(2);  // @292_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @293_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @294_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40da30;  // @295_40d690
  eax = (u32)(edx - 1);  // @296_40d690
  ebq = (ebq - ebx);  // @297_40d690
  FL[3] = ebq;  // @298_40d690
  eax = (eax >> (u32)(1));  // @299_40d690
  FL[3] = eax;  // @300_40d690
  edi = (u32)(ebx*4);  // @301_40d690
  esi = (u32)(edx*4);  // @302_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 64), &v, sizeof v); }  // @303_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 44), &v, sizeof v); }  // @304_40d690
  L40d98b:;
  ebx = (ebx + (u32)(2));  // @306_40d690
  FL[3] = ebx;  // @307_40d690
  edi = (edi + (u32)(8));  // @308_40d690
  FL[3] = edi;  // @309_40d690
  ecx = ebx;  // @310_40d690
  eax = edi;  // @311_40d690
  ecx = (ecx - edx);  // @312_40d690
  FL[3] = ecx;  // @313_40d690
  eax = (eax - esi);  // @314_40d690
  FL[3] = eax;  // @315_40d690
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @316_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 20), &v, sizeof v); }  // @317_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @318_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40da19;  // @319_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @320_40d690
  ecx = (ecx + ebq);  // @321_40d690
  FL[3] = ecx;  // @322_40d690
  ecx = (ecx << (u32)(2));  // @323_40d690
  FL[3] = ecx;  // @324_40d690
  ebx = (u32)(eax + edi);  // @325_40d690
  ebq = (u32)(ecx + edi);  // @326_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @327_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @328_40d690
  edi = (edi - ebq);  // @329_40d690
  FL[3] = edi;  // @330_40d690
  eax = (u32)(eax + ebq - 4);  // @331_40d690
  ecx = (u32)(ecx + ebq - 4);  // @332_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @333_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 40), &v, sizeof v); }  // @334_40d690
  L40d9d1:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + esi)) : "st");  // @336_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx + esi)) : "st");  // @337_40d690
  eax = (eax + esi);  // @338_40d690
  FL[3] = eax;  // @339_40d690
  ecx = (ecx + esi);  // @340_40d690
  FL[3] = ecx;  // @341_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 32), sizeof v); (u32)v; });  // @342_40d690
  ebx = (ebx + esi);  // @343_40d690
  FL[3] = ebx;  // @344_40d690
  ebq = (ebq + esi);  // @345_40d690
  FL[3] = ebq;  // @346_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + eax)) :: "st");  // @347_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @348_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @349_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @350_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + edi)) :: "st");  // @351_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @352_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @353_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @354_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @355_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @356_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @357_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 40), sizeof v); (u32)v; });  // @358_40d690
  ebq = (ebq - 1);  // @359_40d690
  FL[3] = ebq;  // @360_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 40), &v, sizeof v); }  // @361_40d690
  if (FL[3] != 0) goto L40d9d1;  // @362_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 60), sizeof v); (u32)v; });  // @363_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 64), sizeof v); (u32)v; });  // @364_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 20), sizeof v); (u32)v; });  // @365_40d690
  L40da19:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 44), sizeof v); (u32)v; });  // @367_40d690
  eax = (eax - 1);  // @368_40d690
  FL[3] = eax;  // @369_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 44), &v, sizeof v); }  // @370_40d690
  if (FL[3] != 0) goto L40d98b;  // @371_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @372_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @373_40d690
  L40da30:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 48), sizeof v); (u32)v; });  // @375_40d690
  eax = (eax - 1);  // @376_40d690
  FL[3] = eax;  // @377_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @378_40d690
  if (FL[3] != 0) goto L40d955;  // @379_40d690
  goto L40db50;  // @380_40d690
  L40da44:;
  FL[0] = eax; FL[1] = (u32)(1);  // @382_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40db50;  // @383_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @384_40d690
  ebx = eax;  // @385_40d690
  edi = (u32)(eax + ebq*4);  // @386_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @387_40d690
  ecx = (u32)(eax + ebq*4 - 4);  // @388_40d690
  esi = (u32)(eax - 4);  // @389_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @390_40d690
  eax = (eax - 1);  // @391_40d690
  FL[3] = eax;  // @392_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @393_40d690
  L40da6a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @395_40d690
  eax = (eax << (u32)(2));  // @396_40d690
  FL[3] = eax;  // @397_40d690
  ebx = (ebx + eax);  // @398_40d690
  FL[3] = ebx;  // @399_40d690
  esi = (esi + eax);  // @400_40d690
  FL[3] = esi;  // @401_40d690
  edi = (edi - eax);  // @402_40d690
  FL[3] = edi;  // @403_40d690
  ecx = (ecx - eax);  // @404_40d690
  FL[3] = ecx;  // @405_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @406_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 64), &v, sizeof v); }  // @407_40d690
  FL[2] = (eax & eax);  // @408_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 20), &v, sizeof v); }  // @409_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 68), &v, sizeof v); }  // @410_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @411_40d690
  if ((s32)FL[2] <= 0) goto L40db41;  // @412_40d690
  ebq = edi;  // @413_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @414_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @415_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 44), &v, sizeof v); }  // @416_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 40), &v, sizeof v); }  // @417_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @418_40d690
  L40daab:;
  FL[0] = edx; FL[1] = (u32)(2);  // @420_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40daf3;  // @421_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @422_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @423_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @424_40d690
  esi = (esi - edi);  // @425_40d690
  FL[3] = esi;  // @426_40d690
  edi = (u32)(edx - 1);  // @427_40d690
  edi = (edi >> (u32)(1));  // @428_40d690
  FL[3] = edi;  // @429_40d690
  L40dac3:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @431_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @432_40d690
  ecx = (ecx + (u32)(8));  // @433_40d690
  FL[3] = ecx;  // @434_40d690
  eax = (eax + (u32)(8));  // @435_40d690
  FL[3] = eax;  // @436_40d690
  ebx = (ebx + (u32)(8));  // @437_40d690
  FL[3] = ebx;  // @438_40d690
  ebq = (ebq + (u32)(8));  // @439_40d690
  FL[3] = ebq;  // @440_40d690
  edi = (edi - 1);  // @441_40d690
  FL[3] = edi;  // @442_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + eax)) :: "st");  // @443_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @444_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @445_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + esi)) :: "st");  // @446_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @447_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @448_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @449_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @450_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @451_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @452_40d690
  if (FL[3] != 0) goto L40dac3;  // @453_40d690
  L40daf3:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @455_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 48), sizeof v); (u32)v; });  // @456_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 40), sizeof v); (u32)v; });  // @457_40d690
  eax = (u32)(edx*4);  // @458_40d690
  ebq = (ebq + eax);  // @459_40d690
  FL[3] = ebq;  // @460_40d690
  ebx = (ebx + eax);  // @461_40d690
  FL[3] = ebx;  // @462_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @463_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 44), sizeof v); (u32)v; });  // @464_40d690
  ebq = (ebq + eax);  // @465_40d690
  FL[3] = ebq;  // @466_40d690
  ecx = (ecx + eax);  // @467_40d690
  FL[3] = ecx;  // @468_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 32), sizeof v); (u32)v; });  // @469_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @470_40d690
  eax = (eax - 1);  // @471_40d690
  FL[3] = eax;  // @472_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 44), &v, sizeof v); }  // @473_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 40), &v, sizeof v); }  // @474_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @475_40d690
  if (FL[3] != 0) goto L40daab;  // @476_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 64), sizeof v); (u32)v; });  // @477_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 60), sizeof v); (u32)v; });  // @478_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 20), sizeof v); (u32)v; });  // @479_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 68), sizeof v); (u32)v; });  // @480_40d690
  L40db41:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @482_40d690
  eax = (eax - 1);  // @483_40d690
  FL[3] = eax;  // @484_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @485_40d690
  if (FL[3] != 0) goto L40da6a;  // @486_40d690
  L40db50:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @488_40d690
  FL[2] = (ebq & ebq);  // @489_40d690
  if ((s32)FL[2] <= 0) goto L40db6f;  // @490_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @491_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 108), sizeof v); (u32)v; });  // @492_40d690
  ecx = (ecx - eax);  // @493_40d690
  FL[3] = ecx;  // @494_40d690
  esi = ebq;  // @495_40d690
  L40db64:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @497_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @498_40d690
  eax = (eax + (u32)(4));  // @499_40d690
  FL[3] = eax;  // @500_40d690
  esi = (esi - 1);  // @501_40d690
  FL[3] = esi;  // @502_40d690
  if (FL[3] != 0) goto L40db64;  // @503_40d690
  L40db6f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @505_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @506_40d690
  ecx = (u32)((s32)ecx * (s32)ebq);  // @507_40d690
  FL[3] = ecx;  // @508_40d690
  edi = 0;  // @509_40d690
  FL[3] = edi;  // @510_40d690
  FL[0] = ebx; FL[1] = (u32)(1);  // @511_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 64), &v, sizeof v); }  // @512_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @513_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40dc2a;  // @514_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @515_40d690
  ecx = 0;  // @516_40d690
  FL[3] = ecx;  // @517_40d690
  ebx = (ebx - 1);  // @518_40d690
  FL[3] = ebx;  // @519_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 44), &v, sizeof v); }  // @520_40d690
  goto L40db9e;  // @521_40d690
  L40db9a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 68), sizeof v); (u32)v; });  // @523_40d690
  L40db9e:;
  eax = (u32)(esi*4);  // @525_40d690
  edi = (edi + esi);  // @526_40d690
  FL[3] = edi;  // @527_40d690
  ecx = (ecx + eax);  // @528_40d690
  FL[3] = ecx;  // @529_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @530_40d690
  eax = (eax - esi);  // @531_40d690
  FL[3] = eax;  // @532_40d690
  ebx = (u32)(edx*4);  // @533_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 68), &v, sizeof v); }  // @534_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @535_40d690
  eax = edi;  // @536_40d690
  ecx = (ecx - ebx);  // @537_40d690
  FL[3] = ecx;  // @538_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @539_40d690
  eax = (eax - edx);  // @540_40d690
  FL[3] = eax;  // @541_40d690
  FL[2] = (ebx & ebx);  // @542_40d690
  if ((s32)FL[2] <= 0) goto L40dc13;  // @543_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @544_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @545_40d690
  eax = (eax - edi);  // @546_40d690
  FL[3] = eax;  // @547_40d690
  ecx = (ecx + ebx);  // @548_40d690
  FL[3] = ecx;  // @549_40d690
  eax = (eax + esi);  // @550_40d690
  FL[3] = eax;  // @551_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @552_40d690
  esi = (esi - ebx);  // @553_40d690
  FL[3] = esi;  // @554_40d690
  eax = (u32)(ebx + eax*4);  // @555_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @556_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @557_40d690
  L40dbeb:;
  ebx = (u32)(edx*4);  // @559_40d690
  eax = (eax + ebx);  // @560_40d690
  FL[3] = eax;  // @561_40d690
  ecx = (ecx + ebx);  // @562_40d690
  FL[3] = ecx;  // @563_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 48), sizeof v); (u32)v; });  // @564_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @565_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @566_40d690
  ebx = (ebx - 1);  // @567_40d690
  FL[3] = ebx;  // @568_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @569_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + esi)) :: "st");  // @570_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @571_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @572_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + esi)) :: "st");  // @573_40d690
  if (FL[3] != 0) goto L40dbeb;  // @574_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @575_40d690
  L40dc13:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 44), sizeof v); (u32)v; });  // @577_40d690
  eax = (eax - 1);  // @578_40d690
  FL[3] = eax;  // @579_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 44), &v, sizeof v); }  // @580_40d690
  if (FL[3] != 0) goto L40db9a;  // @581_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 64), sizeof v); (u32)v; });  // @582_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @583_40d690
  L40dc2a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @585_40d690
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @586_40d690
  eax = (eax - 1);  // @587_40d690
  FL[3] = eax;  // @588_40d690
  eax = (u32)((s32)eax * (s32)ebq);  // @589_40d690
  FL[3] = eax;  // @590_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7069652)) : "st");  // @591_40d690
  FL[0] = ebx; FL[1] = (u32)(1);  // @592_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @593_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40ddb3;  // @594_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 108), sizeof v); (u32)v; });  // @595_40d690
  ebx = (ebx - 1);  // @596_40d690
  FL[3] = ebx;  // @597_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 68) + 96)) : "st");  // @598_40d690
  ecx = (u32)(eax + ecx*4);  // @599_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 20), &v, sizeof v); }  // @600_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @601_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @602_40d690
  L40dc65:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @604_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 68) + 56)) : "st");  // @605_40d690
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @606_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 68) + 52)) : "st");  // @607_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 20), sizeof v); (u32)v; });  // @608_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @609_40d690
  eax = (u32)(ebq*4);  // @610_40d690
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @611_40d690
  edi = (edi + eax);  // @612_40d690
  FL[3] = edi;  // @613_40d690
  esi = (esi - eax);  // @614_40d690
  FL[3] = esi;  // @615_40d690
  FL[2] = (ebq & ebq);  // @616_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 68) + 96)) :: "st");  // @617_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 20), &v, sizeof v); }  // @618_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @619_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 68) + 52)) : "st");  // @620_40d690
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @621_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 68) + 56)) : "st");  // @622_40d690
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @623_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 68) + 96)) : "st");  // @624_40d690
  if ((s32)FL[2] <= 0) goto L40dce8;  // @625_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @626_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 48), sizeof v); (u32)v; });  // @627_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @628_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @629_40d690
  esi = (u32)(ebx + ecx*4);  // @630_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 20), sizeof v); (u32)v; });  // @631_40d690
  eax = (eax + ebx);  // @632_40d690
  FL[3] = eax;  // @633_40d690
  L40dcbf:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 68) + 96)) : "st");  // @635_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @636_40d690
  eax = (eax + (u32)(4));  // @637_40d690
  FL[3] = eax;  // @638_40d690
  ecx = (ecx + (u32)(4));  // @639_40d690
  FL[3] = ecx;  // @640_40d690
  esi = (esi + (u32)(4));  // @641_40d690
  FL[3] = esi;  // @642_40d690
  edi = (edi + (u32)(4));  // @643_40d690
  FL[3] = edi;  // @644_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @645_40d690
  ebx = (ebx + (u32)(4));  // @646_40d690
  FL[3] = ebx;  // @647_40d690
  ebq = (ebq - 1);  // @648_40d690
  FL[3] = ebq;  // @649_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 4)) :: "st");  // @650_40d690
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @651_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @652_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi - 4)) :: "st");  // @653_40d690
  if (FL[3] != 0) goto L40dcbf;  // @654_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @655_40d690
  L40dce8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @657_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @658_40d690
  FL[0] = ecx; FL[1] = (u32)(2);  // @659_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 68), &v, sizeof v); }  // @660_40d690
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @661_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40dda0;  // @662_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @663_40d690
  ecx = (ecx + (u32)(-2));  // @664_40d690
  FL[3] = ecx;  // @665_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 68) + 68)) : "st");  // @666_40d690
  esi = (u32)(eax + ebq*4);  // @667_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 40), &v, sizeof v); }  // @668_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @669_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 48), sizeof v); (u32)v; });  // @670_40d690
  eax = (u32)(eax + esi*4);  // @671_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @672_40d690
  L40dd20:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @674_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 68) + 96)) : "st");  // @675_40d690
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @676_40d690
  __asm__ volatile(".byte 0xd8, 0xcd" ::: "st");  // @677_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 32), sizeof v); (u32)v; });  // @678_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @679_40d690
  eax = (u32)(ebq*4);  // @680_40d690
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @681_40d690
  esi = (esi + eax);  // @682_40d690
  FL[3] = esi;  // @683_40d690
  ecx = (ecx - eax);  // @684_40d690
  FL[3] = ecx;  // @685_40d690
  FL[2] = (ebq & ebq);  // @686_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 68) + 44)) :: "st");  // @687_40d690
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @688_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 68) + 96)) : "st");  // @689_40d690
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @690_40d690
  __asm__ volatile(".byte 0xd8, 0xcb" ::: "st");  // @691_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 32), &v, sizeof v); }  // @692_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @693_40d690
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @694_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 68) + 44)) : "st");  // @695_40d690
  if ((s32)FL[2] <= 0) goto L40dd93;  // @696_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @697_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @698_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 20), sizeof v); (u32)v; });  // @699_40d690
  ebx = ebq;  // @700_40d690
  L40dd6d:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 68) + 44)) : "st");  // @702_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @703_40d690
  esi = (esi + (u32)(4));  // @704_40d690
  FL[3] = esi;  // @705_40d690
  eax = (eax + (u32)(4));  // @706_40d690
  FL[3] = eax;  // @707_40d690
  edi = (edi + (u32)(4));  // @708_40d690
  FL[3] = edi;  // @709_40d690
  ecx = (ecx + (u32)(4));  // @710_40d690
  FL[3] = ecx;  // @711_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @712_40d690
  ebx = (ebx - 1);  // @713_40d690
  FL[3] = ebx;  // @714_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax - 4)) :: "st");  // @715_40d690
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @716_40d690
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edi - 4)) : "st");  // @717_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @718_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 4)) :: "st");  // @719_40d690
  if (FL[3] != 0) goto L40dd6d;  // @720_40d690
  L40dd93:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 40), sizeof v); (u32)v; });  // @722_40d690
  eax = (eax - 1);  // @723_40d690
  FL[3] = eax;  // @724_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 40), &v, sizeof v); }  // @725_40d690
  if (FL[3] != 0) goto L40dd20;  // @726_40d690
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @727_40d690
  L40dda0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 60), sizeof v); (u32)v; });  // @729_40d690
  eax = (eax - 1);  // @730_40d690
  FL[3] = eax;  // @731_40d690
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @732_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @733_40d690
  if (FL[3] != 0) goto L40dc65;  // @734_40d690
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @735_40d690
  L40ddb3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @737_40d690
  FL[0] = eax; FL[1] = (u32)(1);  // @738_40d690
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @739_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40ddf7;  // @740_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @741_40d690
  eax = (eax - 1);  // @742_40d690
  FL[3] = eax;  // @743_40d690
  ebx = (u32)(ebq*4);  // @744_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @745_40d690
  L40ddce:;
  edi = (edi + ebx);  // @747_40d690
  FL[3] = edi;  // @748_40d690
  FL[2] = (ebq & ebq);  // @749_40d690
  if ((s32)FL[2] <= 0) goto L40ddec;  // @750_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 108), sizeof v); (u32)v; });  // @751_40d690
  ecx = edi;  // @752_40d690
  esi = ebq;  // @753_40d690
  L40dddc:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @755_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @756_40d690
  ecx = (ecx + (u32)(4));  // @757_40d690
  FL[3] = ecx;  // @758_40d690
  eax = (eax + (u32)(4));  // @759_40d690
  FL[3] = eax;  // @760_40d690
  esi = (esi - 1);  // @761_40d690
  FL[3] = esi;  // @762_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax - 4)) :: "st");  // @763_40d690
  if (FL[3] != 0) goto L40dddc;  // @764_40d690
  L40ddec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @766_40d690
  eax = (eax - 1);  // @767_40d690
  FL[3] = eax;  // @768_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @769_40d690
  if (FL[3] != 0) goto L40ddce;  // @770_40d690
  L40ddf7:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @772_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 92), sizeof v); (u32)v; });  // @773_40d690
  FL[0] = edx; FL[1] = ebx;  // @774_40d690
  if ((s32)FL[0] >= (s32)FL[1]) goto L40de56;  // @775_40d690
  FL[2] = (edx & edx);  // @776_40d690
  if ((s32)FL[2] <= 0) goto L40debc;  // @777_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @778_40d690
  ecx = edi;  // @779_40d690
  ecx = (ecx - esi);  // @780_40d690
  FL[3] = ecx;  // @781_40d690
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @782_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 100), &v, sizeof v); }  // @783_40d690
  L40de1b:;
  FL[2] = (ebx & ebx);  // @785_40d690
  if ((s32)FL[2] <= 0) goto L40de46;  // @786_40d690
  ecx = (ecx + esi);  // @787_40d690
  FL[3] = ecx;  // @788_40d690
  eax = esi;  // @789_40d690
  ebq = ebx;  // @790_40d690
  L40de25:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @792_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @793_40d690
  edi = (u32)(edx*4);  // @794_40d690
  eax = (eax + edi);  // @795_40d690
  FL[3] = eax;  // @796_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 24), sizeof v); (u32)v; });  // @797_40d690
  edi = (edi << (u32)(2));  // @798_40d690
  FL[3] = edi;  // @799_40d690
  ecx = (ecx + edi);  // @800_40d690
  FL[3] = ecx;  // @801_40d690
  ebq = (ebq - 1);  // @802_40d690
  FL[3] = ebq;  // @803_40d690
  if (FL[3] != 0) goto L40de25;  // @804_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @805_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 92), sizeof v); (u32)v; });  // @806_40d690
  L40de46:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @808_40d690
  esi = (esi + (u32)(4));  // @809_40d690
  FL[3] = esi;  // @810_40d690
  eax = (eax - 1);  // @811_40d690
  FL[3] = eax;  // @812_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @813_40d690
  if (FL[3] != 0) goto L40de1b;  // @814_40d690
  goto L40debc;  // @815_40d690
  L40de56:;
  FL[2] = (ebx & ebx);  // @817_40d690
  if ((s32)FL[2] <= 0) goto L40debc;  // @818_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 24), sizeof v); (u32)v; });  // @819_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 88), &v, sizeof v); }  // @820_40d690
  eax = (u32)(ecx*4);  // @821_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @822_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @823_40d690
  ecx = edi;  // @824_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 108), &v, sizeof v); }  // @825_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 100), &v, sizeof v); }  // @826_40d690
  L40de7b:;
  FL[2] = (edx & edx);  // @828_40d690
  if ((s32)FL[2] <= 0) goto L40de92;  // @829_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @830_40d690
  esi = edx;  // @831_40d690
  L40de85:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @833_40d690
  eax = (eax + (u32)(4));  // @834_40d690
  FL[3] = eax;  // @835_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @836_40d690
  ecx = (ecx + (u32)(4));  // @837_40d690
  FL[3] = ecx;  // @838_40d690
  esi = (esi - 1);  // @839_40d690
  FL[3] = esi;  // @840_40d690
  if (FL[3] != 0) goto L40de85;  // @841_40d690
  L40de92:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @843_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @844_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 108), sizeof v); (u32)v; });  // @845_40d690
  eax = (u32)(edx*4);  // @846_40d690
  ebq = (ebq + eax);  // @847_40d690
  FL[3] = ebq;  // @848_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @849_40d690
  ecx = (ecx + esi);  // @850_40d690
  FL[3] = ecx;  // @851_40d690
  eax = (eax - 1);  // @852_40d690
  FL[3] = eax;  // @853_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @854_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 100), &v, sizeof v); }  // @855_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 88), &v, sizeof v); }  // @856_40d690
  if (FL[3] != 0) goto L40de7b;  // @857_40d690
  L40debc:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @859_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @860_40d690
  eax = ebq;  // @861_40d690
  ecx = (u32)(edx + edx);  // @862_40d690
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; }));  // @863_40d690
  FL[3] = eax;  // @864_40d690
  FL[0] = esi; FL[1] = (u32)(1);  // @865_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 68), &v, sizeof v); }  // @866_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40df64;  // @867_40d690
  ecx = (ecx << (u32)(2));  // @868_40d690
  FL[3] = ecx;  // @869_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 100), &v, sizeof v); }  // @870_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @871_40d690
  esi = (u32)(ecx + eax*4);  // @872_40d690
  eax = edi;  // @873_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @874_40d690
  edi = (edi - 1);  // @875_40d690
  FL[3] = edi;  // @876_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 80), &v, sizeof v); }  // @877_40d690
  L40def4:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @879_40d690
  eax = (eax + edi);  // @880_40d690
  FL[3] = eax;  // @881_40d690
  edi = (u32)(ebq*4);  // @882_40d690
  ecx = (ecx + edi);  // @883_40d690
  FL[3] = ecx;  // @884_40d690
  esi = (esi - edi);  // @885_40d690
  FL[3] = esi;  // @886_40d690
  FL[2] = (ebx & ebx);  // @887_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 88), &v, sizeof v); }  // @888_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 108), &v, sizeof v); }  // @889_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @890_40d690
  if ((s32)FL[2] <= 0) goto L40df51;  // @891_40d690
  edi = (u32)(edx*4);  // @892_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @893_40d690
  L40df20:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @895_40d690
  ecx = (ecx + edi);  // @896_40d690
  FL[3] = ecx;  // @897_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @898_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @899_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @900_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 24), sizeof v); (u32)v; });  // @901_40d690
  ebq = (ebq << (u32)(2));  // @902_40d690
  FL[3] = ebq;  // @903_40d690
  eax = (eax + ebq);  // @904_40d690
  FL[3] = eax;  // @905_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @906_40d690
  esi = (esi + edi);  // @907_40d690
  FL[3] = esi;  // @908_40d690
  ebq = (ebq - 1);  // @909_40d690
  FL[3] = ebq;  // @910_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @911_40d690
  if (FL[3] != 0) goto L40df20;  // @912_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @913_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 108), sizeof v); (u32)v; });  // @914_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @915_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @916_40d690
  L40df51:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @918_40d690
  edi = (edi - 1);  // @919_40d690
  FL[3] = edi;  // @920_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 80), &v, sizeof v); }  // @921_40d690
  if (FL[3] != 0) goto L40def4;  // @922_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 68), sizeof v); (u32)v; });  // @923_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 92), sizeof v); (u32)v; });  // @924_40d690
  L40df64:;
  ecx = (u32)(1);  // @926_40d690
  FL[0] = edx; FL[1] = ecx;  // @927_40d690
  if (FL[0] == FL[1]) goto L40e238;  // @928_40d690
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 36), sizeof v); (u32)v; }); FL[1] = ebx;  // @929_40d690
  if ((s32)FL[0] >= (s32)FL[1]) goto L40e111;  // @930_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @931_40d690
  ebx = edx;  // @932_40d690
  FL[1] = ebx;  // @933_40d690
  ebx = (0u - ebx);  // @934_40d690
  FL[0] = esi; FL[1] = ecx;  // @935_40d690
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 68) + 20), &v, sizeof v); }  // @936_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40e238;  // @937_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @938_40d690
  ebq = 0;  // @939_40d690
  FL[3] = ebq;  // @940_40d690
  eax = (eax << (u32)(2));  // @941_40d690
  FL[3] = eax;  // @942_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @943_40d690
  eax = (u32)(edx + edx);  // @944_40d690
  eax = (eax << (u32)(2));  // @945_40d690
  FL[3] = eax;  // @946_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 68), &v, sizeof v); }  // @947_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @948_40d690
  esi = (u32)(ecx*4);  // @949_40d690
  ecx = (u32)(ebx + edx - 2);  // @950_40d690
  eax = (eax - 1);  // @951_40d690
  FL[3] = eax;  // @952_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 56), &v, sizeof v); }  // @953_40d690
  edi = (u32)(edi + ecx*4);  // @954_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @955_40d690
  goto L40dfcb;  // @956_40d690
  L40dfc7:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @958_40d690
  L40dfcb:;
  eax = (u32)(edx + edx);  // @960_40d690
  ebq = (ebq + esi);  // @961_40d690
  FL[3] = ebq;  // @962_40d690
  ebx = (ebx + eax);  // @963_40d690
  FL[3] = ebx;  // @964_40d690
  ecx = (ecx + eax);  // @965_40d690
  FL[3] = ecx;  // @966_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @967_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 68), sizeof v); (u32)v; });  // @968_40d690
  edi = (edi + ebx);  // @969_40d690
  FL[3] = edi;  // @970_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 20), sizeof v); (u32)v; });  // @971_40d690
  ebx = (ebx + eax);  // @972_40d690
  FL[3] = ebx;  // @973_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 52), &v, sizeof v); }  // @974_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 20), &v, sizeof v); }  // @975_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @976_40d690
  ebx = (ebx - esi);  // @977_40d690
  FL[3] = ebx;  // @978_40d690
  FL[0] = edx; FL[1] = (u32)(2);  // @979_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 48), &v, sizeof v); }  // @980_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 64), &v, sizeof v); }  // @981_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @982_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40e0fa;  // @983_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 80), &v, sizeof v); }  // @984_40d690
  ecx = (u32)(edx - 1);  // @985_40d690
  eax = (u32)(ebq + 8);  // @986_40d690
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)((EBP - 68) + 100), &v, sizeof v); }  // @987_40d690
  ecx = (ecx >> (u32)(1));  // @988_40d690
  FL[3] = ecx;  // @989_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 108), &v, sizeof v); }  // @990_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @991_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 76), &v, sizeof v); }  // @992_40d690
  L40e027:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @994_40d690
  FL[2] = (ecx & ecx);  // @995_40d690
  if ((s32)FL[2] <= 0) goto L40e0b7;  // @996_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 24), sizeof v); (u32)v; });  // @997_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @998_40d690
  ebx = (u32)(ecx*4);  // @999_40d690
  ecx = (u32)(eax + esi);  // @1000_40d690
  eax = (eax - ebq);  // @1001_40d690
  FL[3] = eax;  // @1002_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @1003_40d690
  eax = (eax + ebq);  // @1004_40d690
  FL[3] = eax;  // @1005_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 28), sizeof v); (u32)v; });  // @1006_40d690
  eax = (eax + esi);  // @1007_40d690
  FL[3] = eax;  // @1008_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @1009_40d690
  esi = (esi - ebq);  // @1010_40d690
  FL[3] = esi;  // @1011_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @1012_40d690
  esi = (esi - edx);  // @1013_40d690
  FL[3] = esi;  // @1014_40d690
  esi = (esi + ebq);  // @1015_40d690
  FL[3] = esi;  // @1016_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 20), sizeof v); (u32)v; });  // @1017_40d690
  esi = (esi + ebq);  // @1018_40d690
  FL[3] = esi;  // @1019_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 92), sizeof v); (u32)v; });  // @1020_40d690
  esi = (u32)(ebq + esi*4);  // @1021_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @1022_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 88), &v, sizeof v); }  // @1023_40d690
  L40e077:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @1025_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @1026_40d690
  ebq = (u32)(edx*4);  // @1027_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi - 4)) :: "st");  // @1028_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @1029_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @1030_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi - 4)) :: "st");  // @1031_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @1032_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @1033_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi)) :: "st");  // @1034_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @1035_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @1036_40d690
  eax = (eax + ebq);  // @1037_40d690
  FL[3] = eax;  // @1038_40d690
  ecx = (ecx + ebq);  // @1039_40d690
  FL[3] = ecx;  // @1040_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @1041_40d690
  esi = (esi + ebx);  // @1042_40d690
  FL[3] = esi;  // @1043_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @1044_40d690
  edi = (edi + ebx);  // @1045_40d690
  FL[3] = edi;  // @1046_40d690
  ebq = (ebq - 1);  // @1047_40d690
  FL[3] = ebq;  // @1048_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 88), &v, sizeof v); }  // @1049_40d690
  if (FL[3] != 0) goto L40e077;  // @1050_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 64), sizeof v); (u32)v; });  // @1051_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 108), sizeof v); (u32)v; });  // @1052_40d690
  L40e0b7:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @1054_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @1055_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @1056_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @1057_40d690
  eax = (eax + (u32)(8));  // @1058_40d690
  FL[3] = eax;  // @1059_40d690
  edi = (edi - (u32)(8));  // @1060_40d690
  FL[3] = edi;  // @1061_40d690
  ebx = (ebx - (u32)(2));  // @1062_40d690
  FL[3] = ebx;  // @1063_40d690
  esi = (esi + (u32)(4));  // @1064_40d690
  FL[3] = esi;  // @1065_40d690
  ecx = (ecx - 1);  // @1066_40d690
  FL[3] = ecx;  // @1067_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 108), &v, sizeof v); }  // @1068_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @1069_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 80), &v, sizeof v); }  // @1070_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 100), &v, sizeof v); }  // @1071_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 76), &v, sizeof v); }  // @1072_40d690
  if (FL[3] != 0) goto L40e027;  // @1073_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 56), sizeof v); (u32)v; });  // @1074_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 52), sizeof v); (u32)v; });  // @1075_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 48), sizeof v); (u32)v; });  // @1076_40d690
  L40e0fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 60), sizeof v); (u32)v; });  // @1078_40d690
  eax = (eax - 1);  // @1079_40d690
  FL[3] = eax;  // @1080_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 60), &v, sizeof v); }  // @1081_40d690
  if (FL[3] != 0) goto L40dfc7;  // @1082_40d690
  return eax;  // @1083_40d690
  L40e111:;
  esi = edx;  // @1085_40d690
  FL[1] = esi;  // @1086_40d690
  esi = (0u - esi);  // @1087_40d690
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; }); FL[1] = ecx;  // @1088_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40e238;  // @1089_40d690
  ecx = (u32)(edx + edx);  // @1090_40d690
  esi = (esi + edx);  // @1091_40d690
  FL[3] = esi;  // @1092_40d690
  ecx = (ecx << (u32)(2));  // @1093_40d690
  FL[3] = ecx;  // @1094_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 92), &v, sizeof v); }  // @1095_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @1096_40d690
  ebq = (ebq << (u32)(2));  // @1097_40d690
  FL[3] = ebq;  // @1098_40d690
  eax = (u32)(ecx + eax*4 + 8);  // @1099_40d690
  ecx = (ecx + (u32)(8));  // @1100_40d690
  FL[3] = ecx;  // @1101_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 104), &v, sizeof v); }  // @1102_40d690
  eax = (u32)(edi + 8);  // @1103_40d690
  edi = (u32)(edi + esi*4 - 8);  // @1104_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @1105_40d690
  esi = (esi - 1);  // @1106_40d690
  FL[3] = esi;  // @1107_40d690
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 68) + 112), &v, sizeof v); }  // @1108_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 108), &v, sizeof v); }  // @1109_40d690
  L40e151:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 92), sizeof v); (u32)v; });  // @1111_40d690
  ecx = (ecx + ebq);  // @1112_40d690
  FL[3] = ecx;  // @1113_40d690
  edi = (edi + esi);  // @1114_40d690
  FL[3] = edi;  // @1115_40d690
  eax = (eax + esi);  // @1116_40d690
  FL[3] = eax;  // @1117_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 104), sizeof v); (u32)v; });  // @1118_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 68), &v, sizeof v); }  // @1119_40d690
  esi = (esi - ebq);  // @1120_40d690
  FL[3] = esi;  // @1121_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 76), &v, sizeof v); }  // @1122_40d690
  FL[2] = (ebx & ebx);  // @1123_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 64), &v, sizeof v); }  // @1124_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 104), &v, sizeof v); }  // @1125_40d690
  if ((s32)FL[2] <= 0) goto L40e229;  // @1126_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 80), &v, sizeof v); }  // @1127_40d690
  ecx = esi;  // @1128_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @1129_40d690
  ebq = eax;  // @1130_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 100), &v, sizeof v); }  // @1131_40d690
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 68) + 88), &v, sizeof v); }  // @1132_40d690
  L40e18d:;
  FL[0] = edx; FL[1] = (u32)(2);  // @1134_40d690
  if ((s32)FL[0] <= (s32)FL[1]) goto L40e1d8;  // @1135_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @1136_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @1137_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @1138_40d690
  ebx = (u32)(edx - 1);  // @1139_40d690
  esi = ebq;  // @1140_40d690
  ebx = (ebx >> (u32)(1));  // @1141_40d690
  FL[3] = ebx;  // @1142_40d690
  L40e1a5:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @1144_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @1145_40d690
  esi = (esi + (u32)(8));  // @1146_40d690
  FL[3] = esi;  // @1147_40d690
  eax = (eax + (u32)(8));  // @1148_40d690
  FL[3] = eax;  // @1149_40d690
  ecx = (ecx + (u32)(8));  // @1150_40d690
  FL[3] = ecx;  // @1151_40d690
  edi = (edi - (u32)(8));  // @1152_40d690
  FL[3] = edi;  // @1153_40d690
  ebx = (ebx - 1);  // @1154_40d690
  FL[3] = ebx;  // @1155_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi - 12)) :: "st");  // @1156_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 12)) : "st");  // @1157_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax - 12)) : "st");  // @1158_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + 4)) :: "st");  // @1159_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 8)) : "st");  // @1160_40d690
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax - 8)) : "st");  // @1161_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi - 8)) :: "st");  // @1162_40d690
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax - 8)) : "st");  // @1163_40d690
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx - 8)) : "st");  // @1164_40d690
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + 8)) :: "st");  // @1165_40d690
  if (FL[3] != 0) goto L40e1a5;  // @1166_40d690
  L40e1d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 24), sizeof v); (u32)v; });  // @1168_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 96), sizeof v); (u32)v; });  // @1169_40d690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @1170_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 100), sizeof v); (u32)v; });  // @1171_40d690
  eax = (eax << (u32)(2));  // @1172_40d690
  FL[3] = eax;  // @1173_40d690
  ebq = (ebq + eax);  // @1174_40d690
  FL[3] = ebq;  // @1175_40d690
  edi = (edi + eax);  // @1176_40d690
  FL[3] = edi;  // @1177_40d690
  eax = (u32)(edx*4);  // @1178_40d690
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 68) + 96), &v, sizeof v); }  // @1179_40d690
  esi = (esi + eax);  // @1180_40d690
  FL[3] = esi;  // @1181_40d690
  ecx = (ecx + eax);  // @1182_40d690
  FL[3] = ecx;  // @1183_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 88), sizeof v); (u32)v; });  // @1184_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 80), &v, sizeof v); }  // @1185_40d690
  eax = (eax - 1);  // @1186_40d690
  FL[3] = eax;  // @1187_40d690
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 68) + 100), &v, sizeof v); }  // @1188_40d690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 68) + 88), &v, sizeof v); }  // @1189_40d690
  if (FL[3] != 0) goto L40e18d;  // @1190_40d690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 84), sizeof v); (u32)v; });  // @1191_40d690
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 112), sizeof v); (u32)v; });  // @1192_40d690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 76), sizeof v); (u32)v; });  // @1193_40d690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 68), sizeof v); (u32)v; });  // @1194_40d690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 64), sizeof v); (u32)v; });  // @1195_40d690
  L40e229:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 108), sizeof v); (u32)v; });  // @1197_40d690
  esi = (esi - 1);  // @1198_40d690
  FL[3] = esi;  // @1199_40d690
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 108), &v, sizeof v); }  // @1200_40d690
  if (FL[3] != 0) goto L40e151;  // @1201_40d690
  L40e238:;
  return eax;  // @1203_40d690
}
PCREG(40d690, lifted_40d690);

extern "C" u32 lifted_40eda0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9) {
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
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  __builtin_memcpy(F + 0x300 + 40, &a8, 4);
  __builtin_memcpy(F + 0x300 + 44, &a9, 4);
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 60) + 72)) : "st");  // @0_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 60) + 76), sizeof v); (u32)v; });  // @1_40eda0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 72), sizeof v); (u32)v; });  // @2_40eda0
  __asm__ volatile("fdivrs %0" :: "m"(*(float *)(u32)(7283752)) : "st");  // @3_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 80), sizeof v); (u32)v; });  // @4_40eda0
  edx = ebx;  // @5_40eda0
  eax = ebx;  // @6_40eda0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @7_40eda0
  edx = (u32)((s32)edx * (s32)ecx);  // @8_40eda0
  FL[3] = edx;  // @9_40eda0
  __asm__ volatile(".byte 0xd9, 0xff" ::: "st");  // @10_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 16), &v, sizeof v); }  // @11_40eda0
  edx = (u32)(ebx - 1);  // @12_40eda0
  edx = (u32)((s32)edx >> (u32)(1));  // @13_40eda0
  FL[3] = edx;  // @14_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 36), &v, sizeof v); }  // @15_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @16_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 76) + 52)) :: "st");  // @17_40eda0
  eax = (u32)((s32)eax * (s32)ebq);  // @18_40eda0
  FL[3] = eax;  // @19_40eda0
  __asm__ volatile(".byte 0xd9, 0xfe" ::: "st");  // @20_40eda0
  ebq = (ebq + 1);  // @21_40eda0
  FL[3] = ebq;  // @22_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 28), &v, sizeof v); }  // @23_40eda0
  ebq = (u32)((s32)ebq >> (u32)(1));  // @24_40eda0
  FL[3] = ebq;  // @25_40eda0
  FL[0] = ebx; FL[1] = ecx;  // @26_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 20), &v, sizeof v); }  // @27_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 76) + 48)) :: "st");  // @28_40eda0
  if ((s32)FL[0] >= (s32)FL[1]) goto L40ee52;  // @29_40eda0
  FL[2] = (ebx & ebx);  // @30_40eda0
  if ((s32)FL[2] <= 0) goto L40eea2;  // @31_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @32_40eda0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @33_40eda0
  eax = esi;  // @34_40eda0
  eax = (eax - edx);  // @35_40eda0
  FL[3] = eax;  // @36_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @37_40eda0
  L40ee0d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @39_40eda0
  FL[2] = (ecx & ecx);  // @40_40eda0
  if ((s32)FL[2] <= 0) goto L40ee42;  // @41_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @42_40eda0
  edi = (u32)(ebx*4);  // @43_40eda0
  eax = (eax + edx);  // @44_40eda0
  FL[3] = eax;  // @45_40eda0
  ecx = edx;  // @46_40eda0
  L40ee24:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @49_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 28), sizeof v); (u32)v; });  // @50_40eda0
  ebq = (ebq << (u32)(2));  // @51_40eda0
  FL[3] = ebq;  // @52_40eda0
  eax = (eax + edi);  // @53_40eda0
  FL[3] = eax;  // @54_40eda0
  ecx = (ecx + ebq);  // @55_40eda0
  FL[3] = ecx;  // @56_40eda0
  esi = (esi - 1);  // @57_40eda0
  FL[3] = esi;  // @58_40eda0
  if (FL[3] != 0) goto L40ee24;  // @59_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @60_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @61_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @62_40eda0
  L40ee42:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 32), sizeof v); (u32)v; });  // @64_40eda0
  edx = (edx + (u32)(4));  // @65_40eda0
  FL[3] = edx;  // @66_40eda0
  ecx = (ecx - 1);  // @67_40eda0
  FL[3] = ecx;  // @68_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @69_40eda0
  if (FL[3] != 0) goto L40ee0d;  // @70_40eda0
  goto L40eea6;  // @71_40eda0
  L40ee52:;
  FL[2] = (ecx & ecx);  // @73_40eda0
  if ((s32)FL[2] <= 0) goto L40eea2;  // @74_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @75_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 24), &v, sizeof v); }  // @76_40eda0
  eax = (eax << (u32)(2));  // @77_40eda0
  FL[3] = eax;  // @78_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @79_40eda0
  eax = edx;  // @80_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @81_40eda0
  L40ee6b:;
  FL[2] = (ebx & ebx);  // @83_40eda0
  if ((s32)FL[2] <= 0) goto L40ee80;  // @84_40eda0
  ecx = esi;  // @85_40eda0
  edx = ebx;  // @86_40eda0
  L40ee73:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_40eda0
  eax = (eax + (u32)(4));  // @89_40eda0
  FL[3] = eax;  // @90_40eda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @91_40eda0
  ecx = (ecx + (u32)(4));  // @92_40eda0
  FL[3] = ecx;  // @93_40eda0
  edx = (edx - 1);  // @94_40eda0
  FL[3] = edx;  // @95_40eda0
  if (FL[3] != 0) goto L40ee73;  // @96_40eda0
  L40ee80:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @98_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 24), sizeof v); (u32)v; });  // @99_40eda0
  eax = (u32)(ebx*4);  // @100_40eda0
  esi = (esi + eax);  // @101_40eda0
  FL[3] = esi;  // @102_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 32), sizeof v); (u32)v; });  // @103_40eda0
  eax = (eax + edx);  // @104_40eda0
  FL[3] = eax;  // @105_40eda0
  ecx = (ecx - 1);  // @106_40eda0
  FL[3] = ecx;  // @107_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @108_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 24), &v, sizeof v); }  // @109_40eda0
  if (FL[3] != 0) goto L40ee6b;  // @110_40eda0
  L40eea2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @112_40eda0
  L40eea6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @114_40eda0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 88), sizeof v); (u32)v; }));  // @115_40eda0
  FL[3] = eax;  // @116_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 24), &v, sizeof v); }  // @117_40eda0
  FL[0] = ebq; FL[1] = (u32)(1);  // @118_40eda0
  eax = (u32)(ebx + ebx);  // @119_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40ef58;  // @120_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 24), sizeof v); (u32)v; });  // @121_40eda0
  edi = (u32)(eax*4);  // @122_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @123_40eda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 76) + 56), &v, sizeof v); }  // @124_40eda0
  eax = (eax + edi);  // @125_40eda0
  FL[3] = eax;  // @126_40eda0
  edx = (u32)(esi + ecx*4);  // @127_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @128_40eda0
  eax = (u32)(ebq - 1);  // @129_40eda0
  ecx = esi;  // @130_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @131_40eda0
  L40eee4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @133_40eda0
  eax = (eax << (u32)(2));  // @134_40eda0
  FL[3] = eax;  // @135_40eda0
  ecx = (ecx + eax);  // @136_40eda0
  FL[3] = ecx;  // @137_40eda0
  edx = (edx - eax);  // @138_40eda0
  FL[3] = edx;  // @139_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @140_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @141_40eda0
  FL[2] = (eax & eax);  // @142_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 60), &v, sizeof v); }  // @143_40eda0
  if ((s32)FL[2] <= 0) goto L40ef43;  // @144_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 28), sizeof v); (u32)v; });  // @145_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @146_40eda0
  edi = (u32)(ebx*4);  // @147_40eda0
  esi = (u32)(eax*4);  // @148_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 32), sizeof v); (u32)v; });  // @149_40eda0
  L40ef19:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @151_40eda0
  __asm__ volatile(".byte 0xd8, 0xc0" ::: "st");  // @152_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @153_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @154_40eda0
  __asm__ volatile(".byte 0xd8, 0xc0" ::: "st");  // @155_40eda0
  ecx = (ecx + edi);  // @156_40eda0
  FL[3] = ecx;  // @157_40eda0
  eax = (eax + esi);  // @158_40eda0
  FL[3] = eax;  // @159_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx)) :: "st");  // @160_40eda0
  edx = (edx + edi);  // @161_40eda0
  FL[3] = edx;  // @162_40eda0
  ebq = (ebq - 1);  // @163_40eda0
  FL[3] = ebq;  // @164_40eda0
  if (FL[3] != 0) goto L40ef19;  // @165_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @166_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @167_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 60), sizeof v); (u32)v; });  // @168_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 56), sizeof v); (u32)v; });  // @169_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @170_40eda0
  L40ef43:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 32), sizeof v); (u32)v; });  // @172_40eda0
  eax = (eax + edi);  // @173_40eda0
  FL[3] = eax;  // @174_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @175_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 40), sizeof v); (u32)v; });  // @176_40eda0
  eax = (eax - 1);  // @177_40eda0
  FL[3] = eax;  // @178_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @179_40eda0
  if (FL[3] != 0) goto L40eee4;  // @180_40eda0
  L40ef58:;
  FL[0] = ebx; FL[1] = (u32)(1);  // @182_40eda0
  if (FL[0] == FL[1]) goto L40f14c;  // @183_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @184_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 36), sizeof v); (u32)v; });  // @185_40eda0
  FL[0] = eax; FL[1] = ecx;  // @186_40eda0
  if ((s32)FL[0] >= (s32)FL[1]) goto L40f060;  // @187_40eda0
  FL[0] = ebq; FL[1] = (u32)(1);  // @188_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f14c;  // @189_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 24), sizeof v); (u32)v; });  // @190_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @191_40eda0
  ebq = (ebq - 1);  // @192_40eda0
  FL[3] = ebq;  // @193_40eda0
  edx = esi;  // @194_40eda0
  esi = (u32)(esi + eax*4);  // @195_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @196_40eda0
  L40ef8c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @198_40eda0
  eax = (u32)(ecx*4);  // @199_40eda0
  edx = (edx + eax);  // @200_40eda0
  FL[3] = edx;  // @201_40eda0
  esi = (esi - eax);  // @202_40eda0
  FL[3] = esi;  // @203_40eda0
  eax = (u32)(ebx*8);  // @204_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 72), &v, sizeof v); }  // @205_40eda0
  edi = (edi + eax);  // @206_40eda0
  FL[3] = edi;  // @207_40eda0
  FL[0] = ebx; FL[1] = (u32)(2);  // @208_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 68), &v, sizeof v); }  // @209_40eda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @210_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f048;  // @211_40eda0
  ebq = (u32)(ebx - 1);  // @212_40eda0
  eax = edi;  // @213_40eda0
  ebq = (ebq >> (u32)(1));  // @214_40eda0
  FL[3] = ebq;  // @215_40eda0
  ecx = edi;  // @216_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @217_40eda0
  L40efc6:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @219_40eda0
  ecx = (ecx + (u32)(8));  // @220_40eda0
  FL[3] = ecx;  // @221_40eda0
  edx = (edx + (u32)(8));  // @222_40eda0
  FL[3] = edx;  // @223_40eda0
  esi = (esi + (u32)(8));  // @224_40eda0
  FL[3] = esi;  // @225_40eda0
  eax = (eax - (u32)(8));  // @226_40eda0
  FL[3] = eax;  // @227_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 60), &v, sizeof v); }  // @228_40eda0
  FL[2] = (ebq & ebq);  // @229_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 56), &v, sizeof v); }  // @230_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 44), &v, sizeof v); }  // @231_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @232_40eda0
  if ((s32)FL[2] <= 0) goto L40f035;  // @233_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 28), sizeof v); (u32)v; });  // @234_40eda0
  edi = (edi << (u32)(2));  // @235_40eda0
  FL[3] = edi;  // @236_40eda0
  ebx = (ebx << (u32)(2));  // @237_40eda0
  FL[3] = ebx;  // @238_40eda0
  L40eff4:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @240_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @241_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 4)) :: "st");  // @242_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @243_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @244_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi - 4)) :: "st");  // @245_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @246_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @247_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx)) :: "st");  // @248_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @249_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @250_40eda0
  edx = (edx + ebx);  // @251_40eda0
  FL[3] = edx;  // @252_40eda0
  eax = (eax + edi);  // @253_40eda0
  FL[3] = eax;  // @254_40eda0
  ecx = (ecx + edi);  // @255_40eda0
  FL[3] = ecx;  // @256_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi)) :: "st");  // @257_40eda0
  esi = (esi + ebx);  // @258_40eda0
  FL[3] = esi;  // @259_40eda0
  ebq = (ebq - 1);  // @260_40eda0
  FL[3] = ebq;  // @261_40eda0
  if (FL[3] != 0) goto L40eff4;  // @262_40eda0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 84), sizeof v); (u32)v; });  // @263_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @264_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 60), sizeof v); (u32)v; });  // @265_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 56), sizeof v); (u32)v; });  // @266_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 44), sizeof v); (u32)v; });  // @267_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 32), sizeof v); (u32)v; });  // @268_40eda0
  L40f035:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @270_40eda0
  ebq = (ebq - 1);  // @271_40eda0
  FL[3] = ebq;  // @272_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @273_40eda0
  if (FL[3] != 0) goto L40efc6;  // @274_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 68), sizeof v); (u32)v; });  // @275_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 72), sizeof v); (u32)v; });  // @276_40eda0
  L40f048:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 40), sizeof v); (u32)v; });  // @278_40eda0
  eax = (eax - 1);  // @279_40eda0
  FL[3] = eax;  // @280_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @281_40eda0
  if (FL[3] != 0) goto L40ef8c;  // @282_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @283_40eda0
  goto L40f14c;  // @284_40eda0
  L40f060:;
  FL[0] = ebq; FL[1] = (u32)(1);  // @286_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f14c;  // @287_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 24), sizeof v); (u32)v; });  // @288_40eda0
  eax = (u32)(ebq - 1);  // @289_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 44), &v, sizeof v); }  // @290_40eda0
  ecx = (u32)(esi + edx*4);  // @291_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @292_40eda0
  L40f07b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @294_40eda0
  eax = (eax << (u32)(2));  // @295_40eda0
  FL[3] = eax;  // @296_40eda0
  esi = (esi + eax);  // @297_40eda0
  FL[3] = esi;  // @298_40eda0
  ecx = (ecx - eax);  // @299_40eda0
  FL[3] = ecx;  // @300_40eda0
  eax = (u32)(ebx*8);  // @301_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @302_40eda0
  edx = (edx + eax);  // @303_40eda0
  FL[3] = edx;  // @304_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @305_40eda0
  FL[2] = (eax & eax);  // @306_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 68), &v, sizeof v); }  // @307_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 72), &v, sizeof v); }  // @308_40eda0
  if ((s32)FL[2] <= 0) goto L40f13d;  // @309_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @310_40eda0
  ecx = eax;  // @311_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @312_40eda0
  ebq = edx;  // @313_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @314_40eda0
  L40f0b7:;
  FL[0] = ebx; FL[1] = (u32)(2);  // @316_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f0fa;  // @317_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @318_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 32), sizeof v); (u32)v; });  // @319_40eda0
  edi = (u32)(ebx - 1);  // @320_40eda0
  eax = ebq;  // @321_40eda0
  ecx = ebq;  // @322_40eda0
  edi = (edi >> (u32)(1));  // @323_40eda0
  FL[3] = edi;  // @324_40eda0
  L40f0cd:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 12)) : "st");  // @326_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @327_40eda0
  ecx = (ecx - (u32)(8));  // @328_40eda0
  FL[3] = ecx;  // @329_40eda0
  eax = (eax + (u32)(8));  // @330_40eda0
  FL[3] = eax;  // @331_40eda0
  edx = (edx + (u32)(8));  // @332_40eda0
  FL[3] = edx;  // @333_40eda0
  esi = (esi + (u32)(8));  // @334_40eda0
  FL[3] = esi;  // @335_40eda0
  edi = (edi - 1);  // @336_40eda0
  FL[3] = edi;  // @337_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 4)) :: "st");  // @338_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @339_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @340_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi - 4)) :: "st");  // @341_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @342_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @343_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx)) :: "st");  // @344_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @345_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @346_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi)) :: "st");  // @347_40eda0
  if (FL[3] != 0) goto L40f0cd;  // @348_40eda0
  L40f0fa:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 32), sizeof v); (u32)v; });  // @350_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @351_40eda0
  eax = (u32)(ebx*4);  // @352_40eda0
  edx = (edx + eax);  // @353_40eda0
  FL[3] = edx;  // @354_40eda0
  esi = (esi + eax);  // @355_40eda0
  FL[3] = esi;  // @356_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @357_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 28), sizeof v); (u32)v; });  // @358_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @359_40eda0
  eax = (u32)(edx*4);  // @360_40eda0
  ebq = (ebq + eax);  // @361_40eda0
  FL[3] = ebq;  // @362_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 40), sizeof v); (u32)v; });  // @363_40eda0
  eax = (eax - 1);  // @364_40eda0
  FL[3] = eax;  // @365_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @366_40eda0
  if (FL[3] != 0) goto L40f0b7;  // @367_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @368_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 72), sizeof v); (u32)v; });  // @369_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 68), sizeof v); (u32)v; });  // @370_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @371_40eda0
  L40f13d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 44), sizeof v); (u32)v; });  // @373_40eda0
  eax = (eax - 1);  // @374_40eda0
  FL[3] = eax;  // @375_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 44), &v, sizeof v); }  // @376_40eda0
  if (FL[3] != 0) goto L40f07b;  // @377_40eda0
  L40f14c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 88), sizeof v); (u32)v; });  // @379_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 96), sizeof v); (u32)v; });  // @380_40eda0
  esi = eax;  // @381_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 116), sizeof v); (u32)v; });  // @382_40eda0
  esi = (u32)((s32)esi * (s32)edi);  // @383_40eda0
  FL[3] = esi;  // @384_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7069652)) : "st");  // @385_40eda0
  eax = (eax - 1);  // @386_40eda0
  FL[3] = eax;  // @387_40eda0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @388_40eda0
  eax = (u32)((s32)eax * (s32)edi);  // @389_40eda0
  FL[3] = eax;  // @390_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 72), &v, sizeof v); }  // @391_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 108), sizeof v); (u32)v; });  // @392_40eda0
  FL[0] = ebq; FL[1] = (u32)(1);  // @393_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 68), &v, sizeof v); }  // @394_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f2f8;  // @395_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 76) + 100)) : "st");  // @396_40eda0
  edx = eax;  // @397_40eda0
  esi = (u32)(eax + esi*4);  // @398_40eda0
  eax = (u32)(ebq - 1);  // @399_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @400_40eda0
  goto L40f19e;  // @401_40eda0
  L40f196:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 60), sizeof v); (u32)v; });  // @403_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 56), sizeof v); (u32)v; });  // @404_40eda0
  L40f19e:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @406_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 76) + 52)) : "st");  // @407_40eda0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @408_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 76) + 48)) : "st");  // @409_40eda0
  eax = (u32)(edi*4);  // @410_40eda0
  edx = (edx + eax);  // @411_40eda0
  FL[3] = edx;  // @412_40eda0
  esi = (esi - eax);  // @413_40eda0
  FL[3] = esi;  // @414_40eda0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @415_40eda0
  FL[2] = (edi & edi);  // @416_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 60), &v, sizeof v); }  // @417_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 56), &v, sizeof v); }  // @418_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 76) + 100)) :: "st");  // @419_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 76) + 48)) : "st");  // @420_40eda0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @421_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 76) + 52)) : "st");  // @422_40eda0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @423_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 76) + 100)) : "st");  // @424_40eda0
  if ((s32)FL[2] <= 0) goto L40f225;  // @425_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 44), &v, sizeof v); }  // @426_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 72), sizeof v); (u32)v; });  // @427_40eda0
  eax = (eax + ecx);  // @428_40eda0
  FL[3] = eax;  // @429_40eda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @430_40eda0
  ebq = (u32)(ecx + esi*4);  // @431_40eda0
  L40f1e8:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 76) + 100)) : "st");  // @433_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @434_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 44), sizeof v); (u32)v; });  // @435_40eda0
  eax = (eax + (u32)(4));  // @436_40eda0
  FL[3] = eax;  // @437_40eda0
  esi = (esi + (u32)(4));  // @438_40eda0
  FL[3] = esi;  // @439_40eda0
  edx = (edx + (u32)(4));  // @440_40eda0
  FL[3] = edx;  // @441_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @442_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 44), &v, sizeof v); }  // @443_40eda0
  ecx = (ecx + (u32)(4));  // @444_40eda0
  FL[3] = ecx;  // @445_40eda0
  ebq = (ebq + (u32)(4));  // @446_40eda0
  FL[3] = ebq;  // @447_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 4)) :: "st");  // @448_40eda0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @449_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebq - 4)) : "st");  // @450_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi - 4)) :: "st");  // @451_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 40), sizeof v); (u32)v; });  // @452_40eda0
  esi = (esi - 1);  // @453_40eda0
  FL[3] = esi;  // @454_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @455_40eda0
  if (FL[3] != 0) goto L40f1e8;  // @456_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 116), sizeof v); (u32)v; });  // @457_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @458_40eda0
  L40f225:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 68), sizeof v); (u32)v; });  // @460_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @461_40eda0
  eax = (eax - edi);  // @462_40eda0
  FL[3] = eax;  // @463_40eda0
  FL[0] = ebq; FL[1] = (u32)(2);  // @464_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 76), &v, sizeof v); }  // @465_40eda0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @466_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f2e5;  // @467_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 76) + 76)) : "st");  // @468_40eda0
  edx = (u32)(ecx + edi*4);  // @469_40eda0
  eax = (u32)(ecx + eax*4);  // @470_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 28), &v, sizeof v); }  // @471_40eda0
  edx = (u32)(ebq - 2);  // @472_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @473_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @474_40eda0
  L40f257:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @476_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 76) + 100)) : "st");  // @477_40eda0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @478_40eda0
  __asm__ volatile(".byte 0xd8, 0xcd" ::: "st");  // @479_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 28), sizeof v); (u32)v; });  // @480_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 32), sizeof v); (u32)v; });  // @481_40eda0
  eax = (u32)(edi*4);  // @482_40eda0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @483_40eda0
  esi = (esi + eax);  // @484_40eda0
  FL[3] = esi;  // @485_40eda0
  edx = (edx - eax);  // @486_40eda0
  FL[3] = edx;  // @487_40eda0
  FL[2] = (edi & edi);  // @488_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 76) + 44)) :: "st");  // @489_40eda0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @490_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 76) + 100)) : "st");  // @491_40eda0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @492_40eda0
  __asm__ volatile(".byte 0xd8, 0xcb" ::: "st");  // @493_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 28), &v, sizeof v); }  // @494_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 32), &v, sizeof v); }  // @495_40eda0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @496_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 76) + 44)) : "st");  // @497_40eda0
  if ((s32)FL[2] <= 0) goto L40f2d4;  // @498_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 56), sizeof v); (u32)v; });  // @499_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 60), sizeof v); (u32)v; });  // @500_40eda0
  esi = edx;  // @501_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 28), sizeof v); (u32)v; });  // @502_40eda0
  ebq = edi;  // @503_40eda0
  L40f2a6:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 76) + 44)) : "st");  // @505_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @506_40eda0
  edx = (edx + (u32)(4));  // @507_40eda0
  FL[3] = edx;  // @508_40eda0
  eax = (eax + (u32)(4));  // @509_40eda0
  FL[3] = eax;  // @510_40eda0
  esi = (esi + (u32)(4));  // @511_40eda0
  FL[3] = esi;  // @512_40eda0
  ecx = (ecx + (u32)(4));  // @513_40eda0
  FL[3] = ecx;  // @514_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @515_40eda0
  ebq = (ebq - 1);  // @516_40eda0
  FL[3] = ebq;  // @517_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax - 4)) :: "st");  // @518_40eda0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @519_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @520_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @521_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 4)) :: "st");  // @522_40eda0
  if (FL[3] != 0) goto L40f2a6;  // @523_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @524_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 116), sizeof v); (u32)v; });  // @525_40eda0
  L40f2d4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 40), sizeof v); (u32)v; });  // @527_40eda0
  eax = (eax - 1);  // @528_40eda0
  FL[3] = eax;  // @529_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 40), &v, sizeof v); }  // @530_40eda0
  if (FL[3] != 0) goto L40f257;  // @531_40eda0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @532_40eda0
  L40f2e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @534_40eda0
  eax = (eax - 1);  // @535_40eda0
  FL[3] = eax;  // @536_40eda0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @537_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @538_40eda0
  if (FL[3] != 0) goto L40f196;  // @539_40eda0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @540_40eda0
  L40f2f8:;
  FL[0] = ebq; FL[1] = (u32)(1);  // @542_40eda0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @543_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f3bd;  // @544_40eda0
  eax = (u32)(ebq - 1);  // @545_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @546_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @547_40eda0
  L40f30e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @549_40eda0
  eax = (u32)(edi*4);  // @550_40eda0
  edx = (edx + eax);  // @551_40eda0
  FL[3] = edx;  // @552_40eda0
  FL[2] = (edi & edi);  // @553_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @554_40eda0
  if ((s32)FL[2] <= 0) goto L40f337;  // @555_40eda0
  eax = ecx;  // @556_40eda0
  esi = edi;  // @557_40eda0
  L40f327:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @559_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @560_40eda0
  edx = (edx + (u32)(4));  // @561_40eda0
  FL[3] = edx;  // @562_40eda0
  eax = (eax + (u32)(4));  // @563_40eda0
  FL[3] = eax;  // @564_40eda0
  esi = (esi - 1);  // @565_40eda0
  FL[3] = esi;  // @566_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax - 4)) :: "st");  // @567_40eda0
  if (FL[3] != 0) goto L40f327;  // @568_40eda0
  L40f337:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @570_40eda0
  eax = (eax - 1);  // @571_40eda0
  FL[3] = eax;  // @572_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @573_40eda0
  if (FL[3] != 0) goto L40f30e;  // @574_40eda0
  FL[0] = ebq; FL[1] = (u32)(1);  // @575_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f3bd;  // @576_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @577_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 104), sizeof v); (u32)v; });  // @578_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 24), sizeof v); (u32)v; });  // @579_40eda0
  esi = (u32)(ebq - 1);  // @580_40eda0
  edx = (u32)(ecx*4);  // @581_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @582_40eda0
  ecx = (u32)(edi + eax*4);  // @583_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 68), &v, sizeof v); }  // @584_40eda0
  eax = edi;  // @585_40eda0
  L40f36a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @587_40eda0
  eax = (eax + edx);  // @588_40eda0
  FL[3] = eax;  // @589_40eda0
  ecx = (ecx - edx);  // @590_40eda0
  FL[3] = ecx;  // @591_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 76), &v, sizeof v); }  // @592_40eda0
  FL[2] = (esi & esi);  // @593_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 72), &v, sizeof v); }  // @594_40eda0
  if ((s32)FL[2] <= 0) goto L40f3b0;  // @595_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @596_40eda0
  ebq = (u32)(ebx*4);  // @597_40eda0
  edx = (edx - edi);  // @598_40eda0
  FL[3] = edx;  // @599_40eda0
  L40f38b:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @601_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @602_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + eax)) :: "st");  // @603_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @604_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @605_40eda0
  eax = (eax + ebq);  // @606_40eda0
  FL[3] = eax;  // @607_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx)) :: "st");  // @608_40eda0
  ecx = (ecx + ebq);  // @609_40eda0
  FL[3] = ecx;  // @610_40eda0
  esi = (esi - 1);  // @611_40eda0
  FL[3] = esi;  // @612_40eda0
  if (FL[3] != 0) goto L40f38b;  // @613_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @614_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 76), sizeof v); (u32)v; });  // @615_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 72), sizeof v); (u32)v; });  // @616_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 68), sizeof v); (u32)v; });  // @617_40eda0
  L40f3b0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @619_40eda0
  esi = (esi - 1);  // @620_40eda0
  FL[3] = esi;  // @621_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @622_40eda0
  if (FL[3] != 0) goto L40f36a;  // @623_40eda0
  goto L40f3c1;  // @624_40eda0
  L40f3bd:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 104), sizeof v); (u32)v; });  // @626_40eda0
  L40f3c1:;
  FL[0] = ebx; FL[1] = (u32)(1);  // @628_40eda0
  if (FL[0] == FL[1]) goto L40f846;  // @629_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @630_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 36), sizeof v); (u32)v; });  // @631_40eda0
  FL[0] = eax; FL[1] = ecx;  // @632_40eda0
  if ((s32)FL[0] >= (s32)FL[1]) goto L40f4e4;  // @633_40eda0
  FL[0] = ebq; FL[1] = (u32)(1);  // @634_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f5f5;  // @635_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @636_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 24), sizeof v); (u32)v; });  // @637_40eda0
  edx = (u32)(edi - 4);  // @638_40eda0
  esi = (u32)(ecx + eax*4);  // @639_40eda0
  ebq = (u32)(edi + eax*4 - 4);  // @640_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @641_40eda0
  eax = (eax - 1);  // @642_40eda0
  FL[3] = eax;  // @643_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @644_40eda0
  L40f3fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @646_40eda0
  eax = (eax << (u32)(2));  // @647_40eda0
  FL[3] = eax;  // @648_40eda0
  ecx = (ecx + eax);  // @649_40eda0
  FL[3] = ecx;  // @650_40eda0
  edx = (edx + eax);  // @651_40eda0
  FL[3] = edx;  // @652_40eda0
  esi = (esi - eax);  // @653_40eda0
  FL[3] = esi;  // @654_40eda0
  ebq = (ebq - eax);  // @655_40eda0
  FL[3] = ebq;  // @656_40eda0
  FL[0] = ebx; FL[1] = (u32)(2);  // @657_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 52), &v, sizeof v); }  // @658_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 44), &v, sizeof v); }  // @659_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 56), &v, sizeof v); }  // @660_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 48), &v, sizeof v); }  // @661_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f4d0;  // @662_40eda0
  eax = edx;  // @663_40eda0
  edx = (u32)(ebx - 1);  // @664_40eda0
  edx = (edx >> (u32)(1));  // @665_40eda0
  FL[3] = edx;  // @666_40eda0
  edi = ecx;  // @667_40eda0
  ecx = ebq;  // @668_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @669_40eda0
  L40f435:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @671_40eda0
  edi = (edi + (u32)(8));  // @672_40eda0
  FL[3] = edi;  // @673_40eda0
  eax = (eax + (u32)(8));  // @674_40eda0
  FL[3] = eax;  // @675_40eda0
  esi = (esi + (u32)(8));  // @676_40eda0
  FL[3] = esi;  // @677_40eda0
  ecx = (ecx + (u32)(8));  // @678_40eda0
  FL[3] = ecx;  // @679_40eda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 76) + 60), &v, sizeof v); }  // @680_40eda0
  FL[2] = (edx & edx);  // @681_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 68), &v, sizeof v); }  // @682_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 72), &v, sizeof v); }  // @683_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 76), &v, sizeof v); }  // @684_40eda0
  if ((s32)FL[2] <= 0) goto L40f4ad;  // @685_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 104), sizeof v); (u32)v; });  // @686_40eda0
  edx = (u32)(ebx*4);  // @687_40eda0
  ebx = esi;  // @688_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @689_40eda0
  esi = (esi - ebq);  // @690_40eda0
  FL[3] = esi;  // @691_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @692_40eda0
  L40f470:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @694_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @695_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + esi)) :: "st");  // @696_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @697_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @698_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + esi)) :: "st");  // @699_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @700_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @701_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @702_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @703_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @704_40eda0
  edi = (edi + edx);  // @705_40eda0
  FL[3] = edi;  // @706_40eda0
  eax = (eax + edx);  // @707_40eda0
  FL[3] = eax;  // @708_40eda0
  ecx = (ecx + edx);  // @709_40eda0
  FL[3] = ecx;  // @710_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @711_40eda0
  ebx = (ebx + edx);  // @712_40eda0
  FL[3] = ebx;  // @713_40eda0
  ebq = (ebq - 1);  // @714_40eda0
  FL[3] = ebq;  // @715_40eda0
  if (FL[3] != 0) goto L40f470;  // @716_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 76), sizeof v); (u32)v; });  // @717_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 72), sizeof v); (u32)v; });  // @718_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 68), sizeof v); (u32)v; });  // @719_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 60), sizeof v); (u32)v; });  // @720_40eda0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 84), sizeof v); (u32)v; });  // @721_40eda0
  L40f4ad:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @723_40eda0
  edx = (edx - 1);  // @724_40eda0
  FL[3] = edx;  // @725_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @726_40eda0
  if (FL[3] != 0) goto L40f435;  // @727_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 104), sizeof v); (u32)v; });  // @728_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 56), sizeof v); (u32)v; });  // @729_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 52), sizeof v); (u32)v; });  // @730_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 48), sizeof v); (u32)v; });  // @731_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 44), sizeof v); (u32)v; });  // @732_40eda0
  L40f4d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @734_40eda0
  eax = (eax - 1);  // @735_40eda0
  FL[3] = eax;  // @736_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @737_40eda0
  if (FL[3] != 0) goto L40f3fe;  // @738_40eda0
  goto L40f5f5;  // @739_40eda0
  L40f4e4:;
  FL[0] = ebq; FL[1] = (u32)(1);  // @741_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f5f5;  // @742_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @743_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 24), sizeof v); (u32)v; });  // @744_40eda0
  edx = (u32)(edi - 4);  // @745_40eda0
  ebq = (u32)(ecx + eax*4);  // @746_40eda0
  esi = (u32)(edi + eax*4 - 4);  // @747_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 20), sizeof v); (u32)v; });  // @748_40eda0
  eax = (eax - 1);  // @749_40eda0
  FL[3] = eax;  // @750_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 52), &v, sizeof v); }  // @751_40eda0
  L40f508:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @753_40eda0
  eax = (eax << (u32)(2));  // @754_40eda0
  FL[3] = eax;  // @755_40eda0
  ecx = (ecx + eax);  // @756_40eda0
  FL[3] = ecx;  // @757_40eda0
  edx = (edx + eax);  // @758_40eda0
  FL[3] = edx;  // @759_40eda0
  ebq = (ebq - eax);  // @760_40eda0
  FL[3] = ebq;  // @761_40eda0
  esi = (esi - eax);  // @762_40eda0
  FL[3] = esi;  // @763_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @764_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 72), &v, sizeof v); }  // @765_40eda0
  FL[2] = (eax & eax);  // @766_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 48), &v, sizeof v); }  // @767_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 76), &v, sizeof v); }  // @768_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 68), &v, sizeof v); }  // @769_40eda0
  if ((s32)FL[2] <= 0) goto L40f5e6;  // @770_40eda0
  edi = ecx;  // @771_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @772_40eda0
  ecx = esi;  // @773_40eda0
  edx = eax;  // @774_40eda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 76) + 84), &v, sizeof v); }  // @775_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @776_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 60), &v, sizeof v); }  // @777_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 56), &v, sizeof v); }  // @778_40eda0
  L40f54d:;
  FL[0] = ebx; FL[1] = (u32)(2);  // @780_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f594;  // @781_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @782_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 104), sizeof v); (u32)v; });  // @783_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @784_40eda0
  edx = (edx - esi);  // @785_40eda0
  FL[3] = edx;  // @786_40eda0
  esi = (u32)(ebx - 1);  // @787_40eda0
  esi = (esi >> (u32)(1));  // @788_40eda0
  FL[3] = esi;  // @789_40eda0
  L40f565:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @791_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx + 12)) : "st");  // @792_40eda0
  eax = (eax + (u32)(8));  // @793_40eda0
  FL[3] = eax;  // @794_40eda0
  ecx = (ecx + (u32)(8));  // @795_40eda0
  FL[3] = ecx;  // @796_40eda0
  edi = (edi + (u32)(8));  // @797_40eda0
  FL[3] = edi;  // @798_40eda0
  ebq = (ebq + (u32)(8));  // @799_40eda0
  FL[3] = ebq;  // @800_40eda0
  esi = (esi - 1);  // @801_40eda0
  FL[3] = esi;  // @802_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + edx)) :: "st");  // @803_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @804_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @805_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + edx)) :: "st");  // @806_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @807_40eda0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @808_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @809_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @810_40eda0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @811_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @812_40eda0
  if (FL[3] != 0) goto L40f565;  // @813_40eda0
  L40f594:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @815_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 84), sizeof v); (u32)v; });  // @816_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 60), sizeof v); (u32)v; });  // @817_40eda0
  eax = (u32)(ebx*4);  // @818_40eda0
  ebq = (ebq + eax);  // @819_40eda0
  FL[3] = ebq;  // @820_40eda0
  edi = (edi + eax);  // @821_40eda0
  FL[3] = edi;  // @822_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @823_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 64), sizeof v); (u32)v; });  // @824_40eda0
  ebq = (ebq + eax);  // @825_40eda0
  FL[3] = ebq;  // @826_40eda0
  ecx = (ecx + eax);  // @827_40eda0
  FL[3] = ecx;  // @828_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 56), sizeof v); (u32)v; });  // @829_40eda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 76) + 84), &v, sizeof v); }  // @830_40eda0
  eax = (eax - 1);  // @831_40eda0
  FL[3] = eax;  // @832_40eda0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 76) + 64), &v, sizeof v); }  // @833_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 60), &v, sizeof v); }  // @834_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 56), &v, sizeof v); }  // @835_40eda0
  if (FL[3] != 0) goto L40f54d;  // @836_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 104), sizeof v); (u32)v; });  // @837_40eda0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 76), sizeof v); (u32)v; });  // @838_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 72), sizeof v); (u32)v; });  // @839_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 68), sizeof v); (u32)v; });  // @840_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 48), sizeof v); (u32)v; });  // @841_40eda0
  L40f5e6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 52), sizeof v); (u32)v; });  // @843_40eda0
  eax = (eax - 1);  // @844_40eda0
  FL[3] = eax;  // @845_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 52), &v, sizeof v); }  // @846_40eda0
  if (FL[3] != 0) goto L40f508;  // @847_40eda0
  L40f5f5:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 96), sizeof v); (u32)v; });  // @849_40eda0
  FL[2] = (edx & edx);  // @850_40eda0
  if ((s32)FL[2] <= 0) goto L40f612;  // @851_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 108), sizeof v); (u32)v; });  // @852_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 116), sizeof v); (u32)v; });  // @853_40eda0
  ecx = (ecx - eax);  // @854_40eda0
  FL[3] = ecx;  // @855_40eda0
  L40f607:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @857_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @858_40eda0
  eax = (eax + (u32)(4));  // @859_40eda0
  FL[3] = eax;  // @860_40eda0
  edx = (edx - 1);  // @861_40eda0
  FL[3] = edx;  // @862_40eda0
  if (FL[3] != 0) goto L40f607;  // @863_40eda0
  L40f612:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 88), sizeof v); (u32)v; });  // @865_40eda0
  FL[0] = esi; FL[1] = (u32)(1);  // @866_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f667;  // @867_40eda0
  ecx = (u32)(esi - 1);  // @868_40eda0
  eax = edi;  // @869_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @870_40eda0
  L40f624:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @872_40eda0
  ecx = (u32)(edx*4);  // @873_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @874_40eda0
  eax = (eax + ecx);  // @875_40eda0
  FL[3] = eax;  // @876_40eda0
  FL[2] = (edx & edx);  // @877_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 116), &v, sizeof v); }  // @878_40eda0
  if ((s32)FL[2] <= 0) goto L40f65c;  // @879_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @880_40eda0
  ebq = (u32)(ebx*4);  // @881_40eda0
  ecx = (ecx - edi);  // @882_40eda0
  FL[3] = ecx;  // @883_40eda0
  L40f64a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; });  // @885_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @886_40eda0
  eax = (eax + ebq);  // @887_40eda0
  FL[3] = eax;  // @888_40eda0
  edx = (edx - 1);  // @889_40eda0
  FL[3] = edx;  // @890_40eda0
  if (FL[3] != 0) goto L40f64a;  // @891_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 116), sizeof v); (u32)v; });  // @892_40eda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 88), sizeof v); (u32)v; });  // @893_40eda0
  L40f65c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @895_40eda0
  ecx = (ecx - 1);  // @896_40eda0
  FL[3] = ecx;  // @897_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @898_40eda0
  if (FL[3] != 0) goto L40f624;  // @899_40eda0
  L40f667:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @901_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 36), sizeof v); (u32)v; });  // @902_40eda0
  FL[0] = ecx; FL[1] = eax;  // @903_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f76e;  // @904_40eda0
  eax = (eax | (u32)(4294967295));  // @905_40eda0
  FL[3] = eax;  // @906_40eda0
  eax = (eax - ebx);  // @907_40eda0
  FL[3] = eax;  // @908_40eda0
  FL[0] = esi; FL[1] = (u32)(1);  // @909_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f846;  // @910_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @911_40eda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 76) + 88), &v, sizeof v); }  // @912_40eda0
  edx = (u32)(ecx*4);  // @913_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 120), sizeof v); (u32)v; });  // @914_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 76), &v, sizeof v); }  // @915_40eda0
  edx = (u32)(ecx + eax*4);  // @916_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @917_40eda0
  eax = (eax + (u32)(-4));  // @918_40eda0
  FL[3] = eax;  // @919_40eda0
  esi = (esi - 1);  // @920_40eda0
  FL[3] = esi;  // @921_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 116), &v, sizeof v); }  // @922_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @923_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 108), &v, sizeof v); }  // @924_40eda0
  L40f6b3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 116), sizeof v); (u32)v; });  // @926_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 88), sizeof v); (u32)v; });  // @927_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @928_40eda0
  eax = (u32)(ebx*4);  // @929_40eda0
  esi = (esi + eax);  // @930_40eda0
  FL[3] = esi;  // @931_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 76), sizeof v); (u32)v; });  // @932_40eda0
  edx = (edx + eax);  // @933_40eda0
  FL[3] = edx;  // @934_40eda0
  ecx = (ecx + eax);  // @935_40eda0
  FL[3] = ecx;  // @936_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @937_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 116), &v, sizeof v); }  // @938_40eda0
  FL[2] = (eax & eax);  // @939_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 88), &v, sizeof v); }  // @940_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @941_40eda0
  if ((s32)FL[2] <= 0) goto L40f757;  // @942_40eda0
  ebq = edx;  // @943_40eda0
  edx = eax;  // @944_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 84), &v, sizeof v); }  // @945_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 96), &v, sizeof v); }  // @946_40eda0
  L40f6f0:;
  FL[0] = ebx; FL[1] = (u32)(2);  // @948_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f739;  // @949_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @950_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 116), sizeof v); (u32)v; });  // @951_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 84), sizeof v); (u32)v; });  // @952_40eda0
  edi = (edi - edx);  // @953_40eda0
  FL[3] = edi;  // @954_40eda0
  edx = (u32)(ebx - 1);  // @955_40eda0
  esi = ebq;  // @956_40eda0
  edx = (edx >> (u32)(1));  // @957_40eda0
  FL[3] = edx;  // @958_40eda0
  L40f70a:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @960_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @961_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @962_40eda0
  ecx = (ecx + (u32)(8));  // @963_40eda0
  FL[3] = ecx;  // @964_40eda0
  eax = (eax + (u32)(8));  // @965_40eda0
  FL[3] = eax;  // @966_40eda0
  esi = (esi + (u32)(8));  // @967_40eda0
  FL[3] = esi;  // @968_40eda0
  edx = (edx - 1);  // @969_40eda0
  FL[3] = edx;  // @970_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @971_40eda0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @972_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + eax)) :: "st");  // @973_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @974_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @975_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @976_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @977_40eda0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @978_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi)) :: "st");  // @979_40eda0
  if (FL[3] != 0) goto L40f70a;  // @980_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 104), sizeof v); (u32)v; });  // @981_40eda0
  L40f739:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 84), sizeof v); (u32)v; });  // @983_40eda0
  eax = (u32)(ebx*4);  // @984_40eda0
  ebq = (ebq + eax);  // @985_40eda0
  FL[3] = ebq;  // @986_40eda0
  ecx = (ecx + eax);  // @987_40eda0
  FL[3] = ecx;  // @988_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 96), sizeof v); (u32)v; });  // @989_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 84), &v, sizeof v); }  // @990_40eda0
  eax = (eax - 1);  // @991_40eda0
  FL[3] = eax;  // @992_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 96), &v, sizeof v); }  // @993_40eda0
  if (FL[3] != 0) goto L40f6f0;  // @994_40eda0
  L40f757:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 108), sizeof v); (u32)v; });  // @996_40eda0
  eax = (eax - 1);  // @997_40eda0
  FL[3] = eax;  // @998_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 108), &v, sizeof v); }  // @999_40eda0
  if (FL[3] != 0) goto L40f6b3;  // @1000_40eda0
  return eax;  // @1001_40eda0
  L40f76e:;
  eax = (eax | (u32)(4294967295));  // @1003_40eda0
  FL[3] = eax;  // @1004_40eda0
  eax = (eax - ebx);  // @1005_40eda0
  FL[3] = eax;  // @1006_40eda0
  FL[0] = esi; FL[1] = (u32)(1);  // @1007_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f846;  // @1008_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 16), sizeof v); (u32)v; });  // @1009_40eda0
  ebq = (u32)(ebx*4);  // @1010_40eda0
  edx = (u32)(ecx*4);  // @1011_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 120), sizeof v); (u32)v; });  // @1012_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 116), &v, sizeof v); }  // @1013_40eda0
  edx = edi;  // @1014_40eda0
  ecx = (u32)(ecx + eax*4);  // @1015_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @1016_40eda0
  eax = (eax + (u32)(-4));  // @1017_40eda0
  FL[3] = eax;  // @1018_40eda0
  esi = (esi - 1);  // @1019_40eda0
  FL[3] = esi;  // @1020_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @1021_40eda0
  L40f7a7:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 116), sizeof v); (u32)v; });  // @1023_40eda0
  ecx = (ecx + ebq);  // @1024_40eda0
  FL[3] = ecx;  // @1025_40eda0
  edx = (edx + esi);  // @1026_40eda0
  FL[3] = edx;  // @1027_40eda0
  eax = (eax + esi);  // @1028_40eda0
  FL[3] = eax;  // @1029_40eda0
  FL[0] = ebx; FL[1] = (u32)(2);  // @1030_40eda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 76) + 108), &v, sizeof v); }  // @1031_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 120), &v, sizeof v); }  // @1032_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 76), &v, sizeof v); }  // @1033_40eda0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40f837;  // @1034_40eda0
  esi = (u32)(ebx - 1);  // @1035_40eda0
  esi = (esi >> (u32)(1));  // @1036_40eda0
  FL[3] = esi;  // @1037_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 88), &v, sizeof v); }  // @1038_40eda0
  L40f7cb:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @1040_40eda0
  ecx = (ecx + (u32)(8));  // @1041_40eda0
  FL[3] = ecx;  // @1042_40eda0
  edx = (edx + (u32)(8));  // @1043_40eda0
  FL[3] = edx;  // @1044_40eda0
  eax = (eax + (u32)(8));  // @1045_40eda0
  FL[3] = eax;  // @1046_40eda0
  FL[2] = (esi & esi);  // @1047_40eda0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 76) + 96), &v, sizeof v); }  // @1048_40eda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 76) + 84), &v, sizeof v); }  // @1049_40eda0
  if ((s32)FL[2] <= 0) goto L40f820;  // @1050_40eda0
  esi = edi;  // @1051_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 112), sizeof v); (u32)v; });  // @1052_40eda0
  esi = (esi - edi);  // @1053_40eda0
  FL[3] = esi;  // @1054_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 92), sizeof v); (u32)v; });  // @1055_40eda0
  L40f7f0:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @1057_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @1058_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @1059_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @1060_40eda0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @1061_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + eax)) :: "st");  // @1062_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @1063_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @1064_40eda0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @1065_40eda0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @1066_40eda0
  eax = (eax + ebq);  // @1067_40eda0
  FL[3] = eax;  // @1068_40eda0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @1069_40eda0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx)) :: "st");  // @1070_40eda0
  edx = (edx + ebq);  // @1071_40eda0
  FL[3] = edx;  // @1072_40eda0
  edi = (edi - 1);  // @1073_40eda0
  FL[3] = edi;  // @1074_40eda0
  if (FL[3] != 0) goto L40f7f0;  // @1075_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 84), sizeof v); (u32)v; });  // @1076_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 96), sizeof v); (u32)v; });  // @1077_40eda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 104), sizeof v); (u32)v; });  // @1078_40eda0
  L40f820:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 88), sizeof v); (u32)v; });  // @1080_40eda0
  esi = (esi - 1);  // @1081_40eda0
  FL[3] = esi;  // @1082_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 88), &v, sizeof v); }  // @1083_40eda0
  if (FL[3] != 0) goto L40f7cb;  // @1084_40eda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 108), sizeof v); (u32)v; });  // @1085_40eda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 120), sizeof v); (u32)v; });  // @1086_40eda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 76), sizeof v); (u32)v; });  // @1087_40eda0
  L40f837:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 76) + 100), sizeof v); (u32)v; });  // @1089_40eda0
  esi = (esi - 1);  // @1090_40eda0
  FL[3] = esi;  // @1091_40eda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 76) + 100), &v, sizeof v); }  // @1092_40eda0
  if (FL[3] != 0) goto L40f7a7;  // @1093_40eda0
  L40f846:;
  return eax;  // @1095_40eda0
}
PCREG(40eda0, lifted_40eda0);

