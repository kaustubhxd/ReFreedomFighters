// batch242028.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_403ab0_cdecl2(...) __asm__("ext_403ab0");
extern "C" u32 ext_403e50_cdecl2(...) __asm__("ext_403e50");
extern "C" u32 ext_403e80_cdecl1(...) __asm__("ext_403e80");
extern "C" u32 ext_403e80_cdecl2(...) __asm__("ext_403e80");
extern "C" u32 ext_403ea0_cdecl4(...) __asm__("ext_403ea0");
extern "C" u32 ext_634dca_cdecl2(...) __asm__("ext_634dca");
extern "C" u32 ext_634dfa_cdecl0(void) __asm__("ext_634dfa");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_403ae0(u32 a0, u32 a1, u32 a2) {
  u8 F[0xc20] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0xb20);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0xb20 + 8, &a0, 4);
  __builtin_memcpy(F + 0xb20 + 12, &a1, 4);
  __builtin_memcpy(F + 0xb20 + 16, &a2, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2712) + 2720), sizeof v); (u32)v; });  // @0_403ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @1_403ae0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_403ae0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 2720) + 2732)) : "st");  // @3_403ae0
  esi = (esi + (u32)(8));  // @4_403ae0
  FL[3] = esi;  // @5_403ae0
  edi = (edi + (u32)(8));  // @6_403ae0
  FL[3] = edi;  // @7_403ae0
  ecx = (u32)(56);  // @8_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069728)) : "st");  // @9_403ae0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @10_403ae0
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 2720) + 28)) :: "st");  // @11_403ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @12_403ae0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @13_403ae0
  esi = (esi + (u32)(8));  // @14_403ae0
  FL[3] = esi;  // @15_403ae0
  edi = (edi + (u32)(8));  // @16_403ae0
  FL[3] = edi;  // @17_403ae0
  ecx = (u32)(56);  // @18_403ae0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @19_403ae0
  esi = (u32)(4294967281);  // @20_403ae0
  edi = (u32)((EBP - 2720) + 36);  // @21_403ae0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 2720) + 20), &v, sizeof v); }  // @22_403ae0
  L403b33:;
  eax = (u32)(esi - 1);  // @24_403ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 2728) + 20), &v, sizeof v); }  // @25_403ae0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 2728) + 20)) : "st");  // @26_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069824)) : "st");  // @27_403ae0
  __asm__ volatile("faddl %0" :: "m"(*(double *)(u32)((EBP - 2728) + 36)) : "st");  // @28_403ae0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 2728) + 28)) : "st");  // @29_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069824)) : "st");  // @30_403ae0
  __asm__ volatile("faddl %0" :: "m"(*(double *)(u32)((EBP - 2728) + 36)) : "st");  // @31_403ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 2728) + 32)) :: "st");  // @32_403ae0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(7069820)) : "st");  // @33_403ae0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7069816)) : "st");  // @34_403ae0
  __asm__ volatile(".byte 0xd9, 0xea" ::: "st");  // @35_403ae0
  __asm__ volatile(".byte 0xde, 0xc9" ::: "st");  // @36_403ae0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @37_403ae0
  __asm__ volatile(".byte 0xd9, 0xfc" ::: "st");  // @38_403ae0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @39_403ae0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @40_403ae0
  __asm__ volatile(".byte 0xd9, 0xf0" ::: "st");  // @41_403ae0
  __asm__ volatile("fld1" ::: "st");  // @42_403ae0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @43_403ae0
  __asm__ volatile(".byte 0xd9, 0xfd" ::: "st");  // @44_403ae0
  __asm__ volatile(".byte 0xdd, 0xd9" ::: "st");  // @45_403ae0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @46_403ae0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @47_403ae0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @48_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069808)) : "st");  // @49_403ae0
  __asm__ volatile("fld1" ::: "st");  // @50_403ae0
  __asm__ volatile(".byte 0xd9, 0xf3" ::: "st");  // @51_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069680)) : "st");  // @52_403ae0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @53_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069800)) : "st");  // @54_403ae0
  __asm__ volatile("fld1" ::: "st");  // @55_403ae0
  __asm__ volatile(".byte 0xd9, 0xf3" ::: "st");  // @56_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069664)) : "st");  // @57_403ae0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @58_403ae0
  __asm__ volatile(".byte 0xd9, 0xca" ::: "st");  // @59_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069792)) : "st");  // @60_403ae0
  __asm__ volatile(".byte 0xde, 0xc2" ::: "st");  // @61_403ae0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @62_403ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 2728) + 20)) :: "st");  // @63_403ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @64_403ae0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 2728) + 20)) : "st");  // @65_403ae0
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[0] = (u32)v_; PV[1] = (u32)(v_ >> 32); }  // @66_403ae0
  eax = ext_634dca_cdecl2(PV[0], PV[1]);  // @67_403ae0
    // @68_403ae0
  eax = ext_634dfa_cdecl0();  // @69_403ae0
    // @70_403ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 2720) + 20), &v, sizeof v); }  // @71_403ae0
  FL[0] = eax; FL[1] = (u32)(26);  // @72_403ae0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 2720) + 20)) : "st");  // @73_403ae0
  __asm__ volatile("fsubrs %0" :: "m"(*(float *)(u32)((EBP - 2720) + 12)) : "st");  // @74_403ae0
  if ((s32)FL[0] >= (s32)FL[1]) goto L403c00;  // @75_403ae0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7069788)) : "st");  // @76_403ae0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @77_403ae0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax*4 + 7273792)) : "st");  // @78_403ae0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @79_403ae0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax*4 + 7273796)) : "st");  // @80_403ae0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @81_403ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 2720) + 16)) :: "st");  // @82_403ae0
  goto L403c0c;  // @83_403ae0
  L403c00:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273892), sizeof v); (u32)v; });  // @85_403ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @86_403ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 2720) + 16), &v, sizeof v); }  // @87_403ae0
  L403c0c:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 2720) + 24)) : "st");  // @89_403ae0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(7069820)) : "st");  // @90_403ae0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7069816)) : "st");  // @91_403ae0
  __asm__ volatile(".byte 0xd9, 0xea" ::: "st");  // @92_403ae0
  __asm__ volatile(".byte 0xde, 0xc9" ::: "st");  // @93_403ae0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @94_403ae0
  __asm__ volatile(".byte 0xd9, 0xfc" ::: "st");  // @95_403ae0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @96_403ae0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @97_403ae0
  __asm__ volatile(".byte 0xd9, 0xf0" ::: "st");  // @98_403ae0
  __asm__ volatile("fld1" ::: "st");  // @99_403ae0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @100_403ae0
  __asm__ volatile(".byte 0xd9, 0xfd" ::: "st");  // @101_403ae0
  __asm__ volatile(".byte 0xdd, 0xd9" ::: "st");  // @102_403ae0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @103_403ae0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @104_403ae0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @105_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069808)) : "st");  // @106_403ae0
  __asm__ volatile("fld1" ::: "st");  // @107_403ae0
  __asm__ volatile(".byte 0xd9, 0xf3" ::: "st");  // @108_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069680)) : "st");  // @109_403ae0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @110_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069800)) : "st");  // @111_403ae0
  __asm__ volatile("fld1" ::: "st");  // @112_403ae0
  __asm__ volatile(".byte 0xd9, 0xf3" ::: "st");  // @113_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069664)) : "st");  // @114_403ae0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @115_403ae0
  __asm__ volatile(".byte 0xd9, 0xca" ::: "st");  // @116_403ae0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069792)) : "st");  // @117_403ae0
  __asm__ volatile(".byte 0xde, 0xc2" ::: "st");  // @118_403ae0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @119_403ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 2728) + 20)) :: "st");  // @120_403ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @121_403ae0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 2728) + 20)) : "st");  // @122_403ae0
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[2] = (u32)v_; PV[3] = (u32)(v_ >> 32); }  // @123_403ae0
  eax = ext_634dca_cdecl2(PV[2], PV[3]);  // @124_403ae0
    // @125_403ae0
  eax = ext_634dfa_cdecl0();  // @126_403ae0
    // @127_403ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 2720) + 20), &v, sizeof v); }  // @128_403ae0
  FL[0] = eax; FL[1] = (u32)(26);  // @129_403ae0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 2720) + 20)) : "st");  // @130_403ae0
  __asm__ volatile("fsubrs %0" :: "m"(*(float *)(u32)((EBP - 2720) + 12)) : "st");  // @131_403ae0
  if ((s32)FL[0] >= (s32)FL[1]) goto L403cb2;  // @132_403ae0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7069788)) : "st");  // @133_403ae0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @134_403ae0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax*4 + 7273792)) : "st");  // @135_403ae0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @136_403ae0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax*4 + 7273796)) : "st");  // @137_403ae0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @138_403ae0
  goto L403cba;  // @139_403ae0
  L403cb2:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @141_403ae0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7273892)) : "st");  // @142_403ae0
  L403cba:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 2720) + 16)) : "st");  // @144_403ae0
  __asm__ volatile(".byte 0xd8, 0xd9; fnstsw %%ax" : "=a"(X87SW) :: "st", "cc");  // @145_403ae0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @146_403ae0
  FL[2] = ((eax >> 8) & 1);  // @147_403ae0
  if (FL[2] == 0) goto L403ccd;  // @148_403ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @149_403ae0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 2720) + 16)) : "st");  // @150_403ae0
  L403ccd:;
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @152_403ae0
  esi = (esi + 1);  // @153_403ae0
  FL[3] = esi;  // @154_403ae0
  edi = (edi + (u32)(4));  // @155_403ae0
  FL[3] = edi;  // @156_403ae0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 2720) + 20), &v, sizeof v); }  // @157_403ae0
  edx = (u32)(esi + 15);  // @158_403ae0
  FL[0] = edx; FL[1] = (u32)(56);  // @159_403ae0
  if ((s32)FL[0] < (s32)FL[1]) goto L403b33;  // @160_403ae0
  esi = ebx;  // @161_403ae0
  edi = (u32)(5);  // @162_403ae0
  L403cea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @164_403ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @165_403ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @166_403ae0
  eax = (eax + (u32)(8));  // @167_403ae0
  FL[3] = eax;  // @168_403ae0
  ecx = (ecx + (u32)(8));  // @169_403ae0
  FL[3] = ecx;  // @170_403ae0
  PV[4] = (u32)(eax);  // @171_403ae0
  edx = (edx + (u32)(8));  // @172_403ae0
  FL[3] = edx;  // @173_403ae0
  PV[5] = (u32)(ecx);  // @174_403ae0
  PV[6] = (u32)(edx);  // @175_403ae0
  eax = ext_403ea0_cdecl4(PV[6], PV[5], PV[4], (u32)(1056964608));  // @176_403ae0
  ecx = edx = 0;  // @177_403ae0
  esi = (esi + (u32)(8));  // @178_403ae0
  FL[3] = esi;  // @179_403ae0
  edi = (edi - 1);  // @180_403ae0
  FL[3] = edi;  // @181_403ae0
  if (FL[3] != 0) goto L403cea;  // @182_403ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2720) + 2736), sizeof v); (u32)v; });  // @183_403ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2720) + 2728), sizeof v); (u32)v; });  // @184_403ae0
  eax = (eax - ecx);  // @185_403ae0
  FL[3] = eax;  // @186_403ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2724) + 20), &v, sizeof v); }  // @187_403ae0
  ebq = (u32)((EBP - 2724) + 264);  // @188_403ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 2724) + 28), &v, sizeof v); }  // @189_403ae0
  goto L403d3b;  // @190_403ae0
  L403d37:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2724) + 28), sizeof v); (u32)v; });  // @192_403ae0
  L403d3b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @194_403ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx), sizeof v); (u32)v; });  // @195_403ae0
  ecx = (ecx + (u32)(8));  // @196_403ae0
  FL[3] = ecx;  // @197_403ae0
  PV[7] = (u32)(eax);  // @198_403ae0
  PV[8] = (u32)(ecx);  // @199_403ae0
  eax = ext_403e80_cdecl2(PV[8], PV[7]);  // @200_403ae0
  ecx = 0;  // @201_403ae0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 2732) + 28)) : "st");  // @202_403ae0
  ecx = (u32)(56);  // @203_403ae0
  esi = (u32)((EBP - 2728) + 44);  // @204_403ae0
  edi = ebq;  // @205_403ae0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7069784)) : "st");  // @206_403ae0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @207_403ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 2728))) :: "st");  // @208_403ae0
  PV[9] = (u32)(ebq);  // @209_403ae0
  eax = ext_403e80_cdecl2(PV[9], *(u32 *)(u32)(EBP - 2728));   // hand fix: the second argument is the stack slot rewritten by the preceding fstp [esp]  // @210_403ae0
  ecx = 0;  // @211_403ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @212_403ae0
  edx = (edx + (u32)(8));  // @213_403ae0
  FL[3] = edx;  // @214_403ae0
  PV[10] = (u32)(edx);  // @215_403ae0
  PV[11] = (u32)(ebq);  // @216_403ae0
  eax = ext_403e50_cdecl2(PV[11], PV[10]);  // @217_403ae0
  ecx = edx = 0;  // @218_403ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2724) + 20), sizeof v); (u32)v; });  // @219_403ae0
  eax = (eax - 1);  // @220_403ae0
  FL[3] = eax;  // @221_403ae0
  ebx = (ebx + (u32)(4));  // @222_403ae0
  FL[3] = ebx;  // @223_403ae0
  ebq = (ebq + (u32)(224));  // @224_403ae0
  FL[3] = ebq;  // @225_403ae0
  FL[0] = eax; FL[1] = (u32)(-11);  // @226_403ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 2724) + 20), &v, sizeof v); }  // @227_403ae0
  if ((s32)FL[0] > (s32)FL[1]) goto L403d37;  // @228_403ae0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2724) + 2732), sizeof v); (u32)v; });  // @229_403ae0
  esi = (u32)((EBP - 2724) + 488);  // @230_403ae0
  ebx = (u32)(10);  // @231_403ae0
  edi = (u32)(ebq + 4);  // @232_403ae0
  L403da9:;
  eax = (u32)(esi - 224);  // @234_403ae0
  PV[12] = (u32)(eax);  // @235_403ae0
  PV[13] = (u32)(esi);  // @236_403ae0
  eax = ext_403ab0_cdecl2(PV[13], PV[12]);  // @237_403ae0
  ecx = edx = 0;  // @238_403ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @239_403ae0
  PV[14] = (u32)(esi);  // @240_403ae0
  ecx = (ecx + (u32)(8));  // @241_403ae0
  FL[3] = ecx;  // @242_403ae0
  PV[15] = (u32)(ecx);  // @243_403ae0
  eax = ext_403ab0_cdecl2(PV[15], PV[14]);  // @244_403ae0
  ecx = edx = 0;  // @245_403ae0
  esi = (esi + (u32)(224));  // @246_403ae0
  FL[3] = esi;  // @247_403ae0
  edi = (edi + (u32)(4));  // @248_403ae0
  FL[3] = edi;  // @249_403ae0
  ebx = (ebx - 1);  // @250_403ae0
  FL[3] = ebx;  // @251_403ae0
  if (FL[3] != 0) goto L403da9;  // @252_403ae0
  edi = ebq;  // @253_403ae0
  ebx = (u32)(11);  // @254_403ae0
  L403dd9:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @256_403ae0
  ecx = 0;  // @257_403ae0
  FL[3] = ecx;  // @258_403ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 2720) + 12), &v, sizeof v); }  // @259_403ae0
  edx = (u32)(esi + 8);  // @260_403ae0
  L403de4:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @262_403ae0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069780)) : "st", "cc");  // @263_403ae0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @264_403ae0
  FL[2] = ((eax >> 8) & 65);  // @265_403ae0
  if (FL[2] == 0) goto L403dfc;  // @266_403ae0
  ecx = (ecx + 1);  // @267_403ae0
  FL[3] = ecx;  // @268_403ae0
  edx = (edx + (u32)(4));  // @269_403ae0
  FL[3] = edx;  // @270_403ae0
  FL[0] = ecx; FL[1] = (u32)(16);  // @271_403ae0
  if ((s32)FL[0] < (s32)FL[1]) goto L403de4;  // @272_403ae0
  L403dfc:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 2720) + 12), &v, sizeof v); }  // @274_403ae0
  ecx = (u32)(55);  // @275_403ae0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 2720) + 12)) : "st");  // @276_403ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 2720) + 12), &v, sizeof v); }  // @277_403ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi)) :: "st");  // @278_403ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @279_403ae0
  edx = (u32)(esi + 228);  // @280_403ae0
  L403e17:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @282_403ae0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069780)) : "st", "cc");  // @283_403ae0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @284_403ae0
  FL[2] = ((eax >> 8) & 65);  // @285_403ae0
  if (FL[2] == 0) goto L403e2f;  // @286_403ae0
  ecx = (ecx - 1);  // @287_403ae0
  FL[3] = ecx;  // @288_403ae0
  edx = (edx - (u32)(4));  // @289_403ae0
  FL[3] = edx;  // @290_403ae0
  FL[0] = ecx; FL[1] = (u32)(17);  // @291_403ae0
  if ((s32)FL[0] > (s32)FL[1]) goto L403e17;  // @292_403ae0
  L403e2f:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 2720) + 12), &v, sizeof v); }  // @294_403ae0
  edi = (edi + (u32)(4));  // @295_403ae0
  FL[3] = edi;  // @296_403ae0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 2720) + 12)) : "st");  // @297_403ae0
  ebx = (ebx - 1);  // @298_403ae0
  FL[3] = ebx;  // @299_403ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 4)) :: "st");  // @300_403ae0
  if (FL[3] != 0) goto L403dd9;  // @301_403ae0
  return eax;  // @302_403ae0
}
PCREG(403ae0, lifted_403ae0);

