// batch242027.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_403ab0_cdecl2(...) __asm__("ext_403ab0");
extern "C" u32 ext_403e50_cdecl2(...) __asm__("ext_403e50");
extern "C" u32 ext_403e80_cdecl1(...) __asm__("ext_403e80");
extern "C" u32 ext_403e80_cdecl2(...) __asm__("ext_403e80");
extern "C" u32 ext_403ea0_cdecl4(...) __asm__("ext_403ea0");
extern "C" u32 ext_405bb0_cdecl4(...) __asm__("ext_405bb0");
extern "C" u32 ext_634dca_cdecl2(...) __asm__("ext_634dca");
extern "C" u32 ext_634dfa_cdecl0(void) __asm__("ext_634dfa");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_405800(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 28) + 36), sizeof v); (u32)v; });  // @0_405800
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @1_405800
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2_405800
  eax = 0;  // @3_405800
  FL[3] = eax;  // @4_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq + 40), sizeof v); (u32)v; });  // @5_405800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq + 36), sizeof v); (u32)v; });  // @6_405800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq + 44), sizeof v); (u32)v; });  // @7_405800
  FL[0] = edx; FL[1] = eax;  // @8_405800
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 44) + 28), &v, sizeof v); }  // @9_405800
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 44) + 24), &v, sizeof v); }  // @10_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 16), &v, sizeof v); }  // @11_405800
  if (FL[0] == FL[1]) goto L4058c0;  // @12_405800
  ecx = (u32)(edi - 1);  // @13_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 36), &v, sizeof v); }  // @14_405800
  ecx = (u32)((s32)ecx * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 60), sizeof v); (u32)v; }));  // @15_405800
  FL[3] = ecx;  // @16_405800
  FL[2] = (edi & edi);  // @17_405800
  if ((s32)FL[2] <= 0) goto L4058b3;  // @18_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @19_405800
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 44) + 32), &v, sizeof v); }  // @20_405800
  ebq = (u32)(eax - 1);  // @21_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 60), sizeof v); (u32)v; });  // @22_405800
  eax = (eax << (u32)(2));  // @23_405800
  FL[3] = eax;  // @24_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 40), &v, sizeof v); }  // @25_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 56), sizeof v); (u32)v; });  // @26_405800
  ecx = (u32)(eax + ecx*4);  // @27_405800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 44) + 20), &v, sizeof v); }  // @28_405800
  L40585f:;
  ecx = 0;  // @30_405800
  FL[3] = ecx;  // @31_405800
  FL[2] = (ebq & ebq);  // @32_405800
  if ((s32)FL[2] <= 0) goto L40587e;  // @33_405800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @34_405800
  L405867:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 20), sizeof v); (u32)v; });  // @36_405800
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @37_405800
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(ebx)) : "st", "cc");  // @38_405800
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @39_405800
  FL[2] = ((eax >> 8) & 1);  // @40_405800
  if (FL[2] != 0) goto L40587e;  // @41_405800
  ecx = (ecx + 1);  // @42_405800
  FL[3] = ecx;  // @43_405800
  ebx = (ebx + (u32)(4));  // @44_405800
  FL[3] = ebx;  // @45_405800
  FL[0] = ecx; FL[1] = ebq;  // @46_405800
  if ((s32)FL[0] < (s32)FL[1]) goto L405867;  // @47_405800
  L40587e:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @49_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @50_405800
  ebx = (u32)((s32)ebx * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 36), sizeof v); (u32)v; }));  // @51_405800
  FL[3] = ebx;  // @52_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @53_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 40), sizeof v); (u32)v; });  // @54_405800
  eax = (eax + ebx);  // @55_405800
  FL[3] = eax;  // @56_405800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 20), sizeof v); (u32)v; });  // @57_405800
  ebx = (ebx - ecx);  // @58_405800
  FL[3] = ebx;  // @59_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 32), sizeof v); (u32)v; });  // @60_405800
  ecx = (ecx - 1);  // @61_405800
  FL[3] = ecx;  // @62_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 36), &v, sizeof v); }  // @63_405800
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 44) + 20), &v, sizeof v); }  // @64_405800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 44) + 32), &v, sizeof v); }  // @65_405800
  if (FL[3] != 0) goto L40585f;  // @66_405800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 24), sizeof v); (u32)v; });  // @67_405800
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 28), sizeof v); (u32)v; });  // @68_405800
  L4058b3:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq + 8), sizeof v); (u32)v; });  // @70_405800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @71_405800
  if ((s32)FL[0] > (s32)FL[1]) goto L405ba8;  // @72_405800
  L4058c0:;
  FL[2] = (esi & esi);  // @74_405800
  if (FL[2] == 0) goto L405a6a;  // @75_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq + 28), sizeof v); (u32)v; });  // @76_405800
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)((EBP - 44) + 36), &v, sizeof v); }  // @77_405800
  FL[2] = (eax & eax);  // @78_405800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 44) + 40), &v, sizeof v); }  // @79_405800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 44) + 20), &v, sizeof v); }  // @80_405800
  if (FL[2] == 0) goto L4059d6;  // @81_405800
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7069652)) : "st");  // @82_405800
  ebx = 0;  // @83_405800
  FL[3] = ebx;  // @84_405800
  ebq = (u32)(1);  // @85_405800
  FL[2] = (edi & edi);  // @86_405800
  if ((s32)FL[2] <= 0) goto L405961;  // @87_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 56), sizeof v); (u32)v; });  // @88_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 32), &v, sizeof v); }  // @89_405800
  L405904:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 32), sizeof v); (u32)v; });  // @91_405800
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @92_405800
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @93_405800
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @94_405800
  __asm__ volatile("fdivs %0" :: "m"(*(float *)(u32)(esi + 4)) : "st");  // @95_405800
  eax = ext_634dfa_cdecl0();  // @96_405800
    // @97_405800
  FL[2] = (eax & eax);  // @98_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 44), &v, sizeof v); }  // @99_405800
  if ((s32)FL[2] < 0) goto L405961;  // @100_405800
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @101_405800
  if ((s32)FL[0] >= (s32)FL[1]) goto L405961;  // @102_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @103_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 20), sizeof v); (u32)v; });  // @104_405800
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 44) + 44)) : "st");  // @105_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; });  // @106_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 60), sizeof v); (u32)v; });  // @107_405800
  eax = (u32)((s32)eax * (s32)ebq);  // @108_405800
  FL[3] = eax;  // @109_405800
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(esi + 4)) : "st");  // @110_405800
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @111_405800
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @112_405800
  ecx = (ecx + eax);  // @113_405800
  FL[3] = ecx;  // @114_405800
  eax = (u32)(edx*4);  // @115_405800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 44) + 20), &v, sizeof v); }  // @116_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @117_405800
  ebq = (u32)((s32)ebq * (s32)ecx);  // @118_405800
  FL[3] = ebq;  // @119_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 32), sizeof v); (u32)v; });  // @120_405800
  ebx = (ebx + 1);  // @121_405800
  FL[3] = ebx;  // @122_405800
  ecx = (ecx + eax);  // @123_405800
  FL[3] = ecx;  // @124_405800
  FL[0] = ebx; FL[1] = edi;  // @125_405800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 44) + 32), &v, sizeof v); }  // @126_405800
  if ((s32)FL[0] < (s32)FL[1]) goto L405904;  // @127_405800
  L405961:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @129_405800
  L405963:;
  FL[0] = ebx; FL[1] = edi;  // @131_405800
  if (FL[0] != FL[1]) goto L405a62;  // @132_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @133_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 20), sizeof v); (u32)v; });  // @134_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @135_405800
  FL[2] = (eax & eax);  // @136_405800
  if (FL[2] == 0) goto L405a62;  // @137_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @138_405800
  ebq = 0;  // @139_405800
  FL[3] = ebq;  // @140_405800
  FL[2] = (eax & eax);  // @141_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @142_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @143_405800
  ebx = (u32)(edx + ecx*4);  // @144_405800
  if ((s32)FL[2] <= 0) goto L405a56;  // @145_405800
  L405993:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @147_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 60), sizeof v); (u32)v; });  // @148_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 56), sizeof v); (u32)v; });  // @149_405800
  edx = (u32)((s32)edx * (s32)edi);  // @150_405800
  FL[3] = edx;  // @151_405800
  PV[0] = (u32)(eax);  // @152_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 48) + 56), sizeof v); (u32)v; });  // @153_405800
  PV[1] = (u32)(ecx);  // @154_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @155_405800
  edx = (u32)(ecx + edx*4);  // @156_405800
  PV[2] = (u32)(edx);  // @157_405800
  PV[3] = (u32)(edi);  // @158_405800
  eax = ext_405bb0_cdecl4(PV[3], PV[2], PV[1], PV[0]);  // @159_405800
  ecx = edx = 0;  // @160_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 60) + 52), sizeof v); (u32)v; });  // @161_405800
  FL[0] = eax; FL[1] = (u32)(-1);  // @162_405800
  if (FL[0] == FL[1]) goto L4059ca;  // @163_405800
  __asm__ volatile("fcoms %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)((EBP - 44) + 40)) : "st", "cc");  // @164_405800
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @165_405800
  FL[2] = ((eax >> 8) & 1);  // @166_405800
  if (FL[2] == 0) goto L405a40;  // @167_405800
  L4059ca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @169_405800
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 44) + 40)) :: "st");  // @170_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 36), &v, sizeof v); }  // @171_405800
  goto L405a42;  // @172_405800
  L4059d6:;
  eax = (u32)(edi - 1);  // @174_405800
  ebx = 0;  // @175_405800
  FL[3] = ebx;  // @176_405800
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 60), sizeof v); (u32)v; }));  // @177_405800
  FL[3] = eax;  // @178_405800
  FL[2] = (edi & edi);  // @179_405800
  if ((s32)FL[2] <= 0) goto L405963;  // @180_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 60), sizeof v); (u32)v; });  // @181_405800
  edx = (u32)(ecx*4);  // @182_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 56), sizeof v); (u32)v; });  // @183_405800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 44) + 44), &v, sizeof v); }  // @184_405800
  ebq = (u32)(ecx + eax*4);  // @185_405800
  L4059fe:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebq)) : "st");  // @187_405800
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @188_405800
  __asm__ volatile("fdivs %0" :: "m"(*(float *)(u32)(esi + 4)) : "st");  // @189_405800
  eax = ext_634dfa_cdecl0();  // @190_405800
    // @191_405800
  FL[2] = (eax & eax);  // @192_405800
  if ((s32)FL[2] < 0) goto L405963;  // @193_405800
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @194_405800
  if ((s32)FL[0] >= (s32)FL[1]) goto L405963;  // @195_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @196_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @197_405800
  ecx = (u32)((s32)ecx * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 20), sizeof v); (u32)v; }));  // @198_405800
  FL[3] = ecx;  // @199_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; });  // @200_405800
  edx = (edx + ecx);  // @201_405800
  FL[3] = edx;  // @202_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 44), sizeof v); (u32)v; });  // @203_405800
  ebx = (ebx + 1);  // @204_405800
  FL[3] = ebx;  // @205_405800
  ebq = (ebq - ecx);  // @206_405800
  FL[3] = ebq;  // @207_405800
  FL[0] = ebx; FL[1] = edi;  // @208_405800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 44) + 20), &v, sizeof v); }  // @209_405800
  if ((s32)FL[0] < (s32)FL[1]) goto L4059fe;  // @210_405800
  goto L405963;  // @211_405800
  L405a40:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @213_405800
  L405a42:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @215_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 20), sizeof v); (u32)v; });  // @216_405800
  ebq = (ebq + 1);  // @217_405800
  FL[3] = ebq;  // @218_405800
  ebx = (ebx + (u32)(4));  // @219_405800
  FL[3] = ebx;  // @220_405800
  FL[0] = ebq; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4), sizeof v); (u32)v; });  // @221_405800
  if ((s32)FL[0] < (s32)FL[1]) goto L405993;  // @222_405800
  L405a56:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 36), sizeof v); (u32)v; });  // @224_405800
  return eax;  // @225_405800
  L405a62:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 24), sizeof v); (u32)v; });  // @227_405800
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 28), sizeof v); (u32)v; });  // @228_405800
  L405a6a:;
  FL[2] = (ebx & ebx);  // @230_405800
  if (FL[2] == 0) goto L405b30;  // @231_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 52), sizeof v); (u32)v; });  // @232_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @233_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @234_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 44), &v, sizeof v); }  // @235_405800
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @236_405800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 44) + 40), &v, sizeof v); }  // @237_405800
  L405a87:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 16), sizeof v); (u32)v; });  // @239_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 44), sizeof v); (u32)v; });  // @240_405800
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7069652)) : "st");  // @241_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4), sizeof v); (u32)v; });  // @242_405800
  FL[2] = (edi & edi);  // @243_405800
  ecx = (u32)(ebq + edx*4);  // @244_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 40), sizeof v); (u32)v; });  // @245_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; });  // @246_405800
  eax = (u32)(ebq + eax*4);  // @247_405800
  if ((s32)FL[2] <= 0) goto L405b04;  // @248_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 60), sizeof v); (u32)v; });  // @249_405800
  ecx = (ecx - eax);  // @250_405800
  FL[3] = ecx;  // @251_405800
  esi = edi;  // @252_405800
  ebx = (u32)(edx*4);  // @253_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 56), sizeof v); (u32)v; });  // @254_405800
  L405abe:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @256_405800
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @257_405800
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx + eax)) : "st");  // @258_405800
  eax = (eax + (u32)(4));  // @259_405800
  FL[3] = eax;  // @260_405800
  edx = (edx + ebx);  // @261_405800
  FL[3] = edx;  // @262_405800
  esi = (esi - 1);  // @263_405800
  FL[3] = esi;  // @264_405800
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069728)) : "st");  // @265_405800
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @266_405800
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + eax - 4)) : "st");  // @267_405800
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @268_405800
  __asm__ volatile(".byte 0xde, 0xc9" ::: "st");  // @269_405800
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @270_405800
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @271_405800
  if (FL[3] != 0) goto L405abe;  // @272_405800
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069652)) : "st", "cc");  // @273_405800
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @274_405800
  FL[2] = ((eax >> 8) & 65);  // @275_405800
  if (FL[2] != 0) goto L405b06;  // @276_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 24), sizeof v); (u32)v; });  // @277_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 16), sizeof v); (u32)v; });  // @278_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @279_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4), sizeof v); (u32)v; });  // @280_405800
  FL[1] = eax;  // @281_405800
  eax = (0u - eax);  // @282_405800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 44) + 16), &v, sizeof v); }  // @283_405800
  goto L405b1a;  // @284_405800
  L405b04:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @286_405800
  L405b06:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 24), sizeof v); (u32)v; });  // @288_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 16), sizeof v); (u32)v; });  // @289_405800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @290_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; });  // @291_405800
  FL[1] = ecx;  // @292_405800
  ecx = (0u - ecx);  // @293_405800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 44) + 16), &v, sizeof v); }  // @294_405800
  L405b1a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 16), sizeof v); (u32)v; });  // @296_405800
  FL[2] = (eax & eax);  // @297_405800
  if ((s32)FL[2] > 0) goto L405a87;  // @298_405800
  FL[1] = eax;  // @299_405800
  eax = (0u - eax);  // @300_405800
  return eax;  // @301_405800
  L405b30:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 52), sizeof v); (u32)v; });  // @303_405800
  esi = 0;  // @304_405800
  FL[3] = esi;  // @305_405800
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)((EBP - 44) + 36), &v, sizeof v); }  // @306_405800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 44) + 40), &v, sizeof v); }  // @307_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @308_405800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @309_405800
  FL[2] = (ecx & ecx);  // @310_405800
  if ((s32)FL[2] <= 0) goto L405ba4;  // @311_405800
  L405b50:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebq + 8), sizeof v); (u32)v; });  // @313_405800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @314_405800
  if ((s32)FL[0] <= (s32)FL[1]) goto L405b91;  // @315_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 60), sizeof v); (u32)v; });  // @316_405800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 56), sizeof v); (u32)v; });  // @317_405800
  PV[4] = (u32)(eax);  // @318_405800
  PV[5] = (u32)(ecx);  // @319_405800
  PV[6] = (u32)(ebx);  // @320_405800
  PV[7] = (u32)(edi);  // @321_405800
  eax = ext_405bb0_cdecl4(PV[7], PV[6], PV[5], PV[4]);  // @322_405800
  ecx = edx = 0;  // @323_405800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 60) + 52), sizeof v); (u32)v; });  // @324_405800
  FL[0] = eax; FL[1] = (u32)(-1);  // @325_405800
  if (FL[0] == FL[1]) goto L405b81;  // @326_405800
  __asm__ volatile("fcoms %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)((EBP - 44) + 40)) : "st", "cc");  // @327_405800
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @328_405800
  FL[2] = ((eax >> 8) & 1);  // @329_405800
  if (FL[2] == 0) goto L405b8b;  // @330_405800
  L405b81:;
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 44) + 40)) :: "st");  // @332_405800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 44) + 36), &v, sizeof v); }  // @333_405800
  goto L405b8d;  // @334_405800
  L405b8b:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @336_405800
  L405b8d:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 28), sizeof v); (u32)v; });  // @338_405800
  L405b91:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 52), sizeof v); (u32)v; });  // @340_405800
  eax = (u32)(edi*4);  // @341_405800
  ebx = (ebx + eax);  // @342_405800
  FL[3] = ebx;  // @343_405800
  esi = (esi + 1);  // @344_405800
  FL[3] = esi;  // @345_405800
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @346_405800
  if ((s32)FL[0] < (s32)FL[1]) goto L405b50;  // @347_405800
  L405ba4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 44) + 36), sizeof v); (u32)v; });  // @349_405800
  L405ba8:;
  return eax;  // @351_405800
}
PCREG(405800, lifted_405800);


