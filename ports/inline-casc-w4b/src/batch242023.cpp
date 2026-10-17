// batch242023.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_401820_cdecl2(...) __asm__("ext_401820");
extern "C" u32 ext_403f90_cdecl4(...) __asm__("ext_403f90");
extern "C" u32 ext_403fe0_cdecl6(...) __asm__("ext_403fe0");
extern "C" u32 ext_404bd0_cdecl7(...) __asm__("ext_404bd0");
extern "C" u32 ext_4072f0_cdecl3(...) __asm__("ext_4072f0");
extern "C" u32 ext_40ce50_cdecl6(...) __asm__("ext_40ce50");
extern "C" u32 ext_40ce80_cdecl2(...) __asm__("ext_40ce80");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_4080d0(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[78], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @1_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @2_4080d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @3_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; });  // @4_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @5_4080d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @7_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @8_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @10_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @11_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; });  // @13_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @14_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @15_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @16_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @17_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @18_4080d0
  edx = (u32)(edi + edx*2);  // @19_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @20_4080d0
  edx = (u32)(edi + edx*2);  // @21_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4 + 4), sizeof v); (u32)v; });  // @22_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @23_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @24_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @25_4080d0
  eax = (eax << (u32)(2));  // @26_4080d0
  FL[3] = eax;  // @27_4080d0
  eax = (eax + (u32)(3));  // @28_4080d0
  FL[3] = eax;  // @29_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @30_4080d0
  FL[3] = (eax & 0xff);  // @31_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @32_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @33_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @34_4080d0
  eax = (u32)(ecx*4);  // @35_4080d0
  PV[0] = (u32)(eax);  // @36_4080d0
  PV[1] = (u32)(esi);  // @37_4080d0
  eax = ext_401820_cdecl2(PV[1], PV[0]);  // @38_4080d0
  ecx = edx = 0;  // @39_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @40_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @41_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @42_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @43_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @44_4080d0
  eax = (u32)(edi*4);  // @45_4080d0
  eax = (eax + (u32)(3));  // @46_4080d0
  FL[3] = eax;  // @47_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @48_4080d0
  FL[3] = (eax & 0xff);  // @49_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @50_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @51_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @52_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @53_4080d0
  ecx = 0;  // @54_4080d0
  FL[3] = ecx;  // @55_4080d0
  FL[2] = (edi & edi);  // @56_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @57_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @58_4080d0
  if ((s32)FL[2] <= 0) goto L40837a;  // @59_4080d0
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)(EBP - 8)) : "st");  // @60_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @61_4080d0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @62_4080d0
  __asm__ volatile("fdivrs %0" :: "m"(*(float *)(u32)(7069904)) : "st");  // @63_4080d0
  eax = (eax - edx);  // @64_4080d0
  FL[3] = eax;  // @65_4080d0
  edx = ALLOC_PTR;  // @66_4080d0
  eax = (u32)((s32)eax >> (u32)(1));  // @67_4080d0
  FL[3] = eax;  // @68_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @69_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @70_4080d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 36)) :: "st");  // @71_4080d0
  goto L4081a9;  // @72_4080d0
  L4081a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @74_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @75_4080d0
  L4081a9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_4080d0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 36)) : "st");  // @78_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @79_4080d0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069652)) : "st", "cc");  // @80_4080d0
  eax = (u32)(edi + eax*4);  // @81_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @82_4080d0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @83_4080d0
  FL[2] = ((eax >> 8) & 64);  // @84_4080d0
  if (FL[2] == 0) goto L4081cc;  // @85_4080d0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069888)) : "st");  // @86_4080d0
  goto L4081de;  // @87_4080d0
  L4081cc:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 36)) : "st");  // @89_4080d0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(EBP - 36)) : "st");  // @90_4080d0
  __asm__ volatile(".byte 0xd9, 0xed" ::: "st");  // @91_4080d0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @92_4080d0
  __asm__ volatile(".byte 0xd9, 0xf1" ::: "st");  // @93_4080d0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069880)) : "st");  // @94_4080d0
  L4081de:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @96_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492732), sizeof v); (u32)v; });  // @97_4080d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 76)) :: "st");  // @98_4080d0
  PV[2] = (u32)(edx);  // @99_4080d0
  eax = (eax + ecx);  // @100_4080d0
  FL[3] = eax;  // @101_4080d0
  PV[3] = (u32)(edi);  // @102_4080d0
  PV[4] = (u32)(eax);  // @103_4080d0
  eax = ext_40ce50_cdecl6((u32)(7282392), PV[4], PV[3], PV[2], (u32)(0), (u32)(0));  // @104_4080d0
    // @105_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @106_4080d0
  FL[2] = (eax & eax);  // @107_4080d0
  if ((s32)FL[2] <= 0) goto L408236;  // @108_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @109_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @110_4080d0
  ecx = (ecx - edi);  // @111_4080d0
  FL[3] = ecx;  // @112_4080d0
  edx = (edx - edi);  // @113_4080d0
  FL[3] = edx;  // @114_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @115_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @116_4080d0
  eax = edi;  // @117_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @118_4080d0
  L40821b:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + eax)) : "st");  // @120_4080d0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @121_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @122_4080d0
  eax = (eax + (u32)(4));  // @123_4080d0
  FL[3] = eax;  // @124_4080d0
  __asm__ volatile("fsts %0" : "=m"(*(float *)(u32)(eax - 4)) :: "st");  // @125_4080d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + eax - 4)) :: "st");  // @126_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @127_4080d0
  edx = (edx - 1);  // @128_4080d0
  FL[3] = edx;  // @129_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @130_4080d0
  if (FL[3] != 0) goto L40821b;  // @131_4080d0
  L408236:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @133_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @134_4080d0
  PV[5] = (u32)(edi);  // @135_4080d0
  PV[6] = (u32)(edi);  // @136_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4 + 36), sizeof v); (u32)v; });  // @137_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @138_4080d0
  PV[7] = (u32)(eax);  // @139_4080d0
  eax = ext_4072f0_cdecl3(PV[7], PV[6], PV[5]);  // @140_4080d0
  ecx = edx = 0;  // @141_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @142_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @143_4080d0
  PV[8] = (u32)(edi);  // @144_4080d0
  PV[9] = (u32)(ecx);  // @145_4080d0
  eax = ext_40ce80_cdecl2(PV[9], PV[8]);  // @146_4080d0
  ecx = edx = 0;  // @147_4080d0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 36)) : "st");  // @148_4080d0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @149_4080d0
  __asm__ volatile("fcoms %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069652)) : "st", "cc");  // @150_4080d0
  __asm__ volatile("fsts %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @151_4080d0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @152_4080d0
  FL[2] = ((eax >> 8) & 64);  // @153_4080d0
  if (FL[2] == 0) goto L408278;  // @154_4080d0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @155_4080d0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069888)) : "st");  // @156_4080d0
  goto L40828a;  // @157_4080d0
  L408278:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @159_4080d0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @160_4080d0
  __asm__ volatile(".byte 0xd9, 0xed" ::: "st");  // @161_4080d0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @162_4080d0
  __asm__ volatile(".byte 0xd9, 0xf1" ::: "st");  // @163_4080d0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069880)) : "st");  // @164_4080d0
  __asm__ volatile(".byte 0xdd, 0xd9" ::: "st");  // @165_4080d0
  L40828a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @167_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @168_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @169_4080d0
  ecx = (u32)(1);  // @170_4080d0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @171_4080d0
  eax = (eax - 1);  // @172_4080d0
  FL[3] = eax;  // @173_4080d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx)) :: "st");  // @174_4080d0
  FL[0] = eax; FL[1] = ecx;  // @175_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @176_4080d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @177_4080d0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40831a;  // @178_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @179_4080d0
  eax = (eax + (u32)(4));  // @180_4080d0
  FL[3] = eax;  // @181_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @182_4080d0
  L4082af:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @184_4080d0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @185_4080d0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @186_4080d0
  __asm__ volatile(".byte 0xde, 0xca" ::: "st");  // @187_4080d0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @188_4080d0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @189_4080d0
  __asm__ volatile(".byte 0xde, 0xc2" ::: "st");  // @190_4080d0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @191_4080d0
  __asm__ volatile("fcoms %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069652)) : "st", "cc");  // @192_4080d0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @193_4080d0
  FL[2] = ((eax >> 8) & 64);  // @194_4080d0
  if (FL[2] == 0) goto L4082d7;  // @195_4080d0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @196_4080d0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069888)) : "st");  // @197_4080d0
  goto L4082e9;  // @198_4080d0
  L4082d7:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @200_4080d0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @201_4080d0
  __asm__ volatile(".byte 0xd9, 0xed" ::: "st");  // @202_4080d0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @203_4080d0
  __asm__ volatile(".byte 0xd9, 0xf1" ::: "st");  // @204_4080d0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069880)) : "st");  // @205_4080d0
  __asm__ volatile(".byte 0xdd, 0xd9" ::: "st");  // @206_4080d0
  L4082e9:;
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069728)) : "st");  // @208_4080d0
  eax = (u32)(ecx + 1);  // @209_4080d0
  eax = (u32)((s32)eax >> (u32)(1));  // @210_4080d0
  FL[3] = eax;  // @211_4080d0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(EBP - 76)) : "st");  // @212_4080d0
  __asm__ volatile("fsts %0" : "=m"(*(float *)(u32)(edx + eax*4)) :: "st");  // @213_4080d0
  __asm__ volatile("fcoms %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(edi)) : "st", "cc");  // @214_4080d0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @215_4080d0
  FL[2] = ((eax >> 8) & 65);  // @216_4080d0
  if (FL[2] != 0) goto L408307;  // @217_4080d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @218_4080d0
  goto L408309;  // @219_4080d0
  L408307:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @221_4080d0
  L408309:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @223_4080d0
  ecx = (ecx + (u32)(2));  // @224_4080d0
  FL[3] = ecx;  // @225_4080d0
  eax = (eax + (u32)(8));  // @226_4080d0
  FL[3] = eax;  // @227_4080d0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @228_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @229_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L4082af;  // @230_4080d0
  L40831a:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @232_4080d0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069652)) : "st", "cc");  // @233_4080d0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @234_4080d0
  FL[2] = ((eax >> 8) & 65);  // @235_4080d0
  if (FL[2] != 0) goto L40832f;  // @236_4080d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @237_4080d0
  L40832f:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @239_4080d0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(EBP - 32)) : "st", "cc");  // @240_4080d0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @241_4080d0
  FL[2] = ((eax >> 8) & 65);  // @242_4080d0
  if (FL[2] != 0) goto L408340;  // @243_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @244_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @245_4080d0
  L408340:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @247_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492732), sizeof v); (u32)v; });  // @248_4080d0
  PV[10] = (u32)(eax);  // @249_4080d0
  PV[11] = (u32)(edx);  // @250_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @251_4080d0
  ecx = (ecx + edx);  // @252_4080d0
  FL[3] = ecx;  // @253_4080d0
  PV[12] = (u32)(ecx);  // @254_4080d0
  eax = ext_40ce50_cdecl6((u32)(7282388), PV[12], PV[11], PV[10], (u32)(1), (u32)(0));  // @255_4080d0
    // @256_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @257_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @258_4080d0
  eax = (eax + 1);  // @259_4080d0
  FL[3] = eax;  // @260_4080d0
  edi = (edi + (u32)(4));  // @261_4080d0
  FL[3] = edi;  // @262_4080d0
  FL[0] = eax; FL[1] = ecx;  // @263_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @264_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @265_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L4081a3;  // @266_4080d0
  L40837a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @268_4080d0
  edi = 0;  // @269_4080d0
  FL[3] = edi;  // @270_4080d0
  FL[2] = (eax & eax);  // @271_4080d0
  if ((s32)FL[2] <= 0) goto L408507;  // @272_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @273_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @274_4080d0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @275_4080d0
  eax = (eax - edx);  // @276_4080d0
  FL[3] = eax;  // @277_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @278_4080d0
  ebx = eax;  // @279_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @280_4080d0
  eax = (eax + (u32)(4));  // @281_4080d0
  FL[3] = eax;  // @282_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @283_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @284_4080d0
  ebx = (u32)((s32)ebx >> (u32)(1));  // @285_4080d0
  FL[3] = ebx;  // @286_4080d0
  eax = (eax - ecx);  // @287_4080d0
  FL[3] = eax;  // @288_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @289_4080d0
  goto L4083ad;  // @290_4080d0
  L4083aa:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @292_4080d0
  L4083ad:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @294_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @295_4080d0
  FL[2] = (ebx & ebx);  // @296_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @297_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @298_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @299_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @300_4080d0
  esi = (u32)(ecx + ebx*4);  // @301_4080d0
  if ((s32)FL[2] <= 0) goto L408406;  // @302_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @303_4080d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @304_4080d0
  edx = (edx - ecx);  // @305_4080d0
  FL[3] = edx;  // @306_4080d0
  L4083cc:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @308_4080d0
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069652)) : "st", "cc");  // @309_4080d0
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @310_4080d0
  FL[2] = ((eax >> 8) & 64);  // @311_4080d0
  if (FL[2] == 0) goto L4083e3;  // @312_4080d0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069888)) : "st");  // @313_4080d0
  goto L4083f7;  // @314_4080d0
  L4083e3:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @316_4080d0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @317_4080d0
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @318_4080d0
  __asm__ volatile(".byte 0xd9, 0xed" ::: "st");  // @319_4080d0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @320_4080d0
  __asm__ volatile(".byte 0xd9, 0xf1" ::: "st");  // @321_4080d0
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)(7069880)) : "st");  // @322_4080d0
  __asm__ volatile(".byte 0xdd, 0xd9" ::: "st");  // @323_4080d0
  L4083f7:;
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx)) :: "st");  // @325_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @326_4080d0
  ecx = (ecx + (u32)(4));  // @327_4080d0
  FL[3] = ecx;  // @328_4080d0
  eax = (eax - 1);  // @329_4080d0
  FL[3] = eax;  // @330_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @331_4080d0
  if (FL[3] != 0) goto L4083cc;  // @332_4080d0
  L408406:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492732), sizeof v); (u32)v; });  // @334_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @335_4080d0
  PV[13] = (u32)(ebx);  // @336_4080d0
  edx = (edx + edi);  // @337_4080d0
  FL[3] = edx;  // @338_4080d0
  PV[14] = (u32)(ecx);  // @339_4080d0
  PV[15] = (u32)(edx);  // @340_4080d0
  eax = ext_40ce50_cdecl6((u32)(7282380), PV[15], PV[14], PV[13], (u32)(1), (u32)(0));  // @341_4080d0
    // @342_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @343_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @344_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @345_4080d0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(eax + 168)) : "st");  // @346_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @347_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @348_4080d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 116))) :: "st");  // @349_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @350_4080d0
  PV[16] = (u32)(eax);  // @351_4080d0
  eax = (u32)(edx + ebx*4);  // @352_4080d0
  PV[17] = (u32)(ecx);  // @353_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @354_4080d0
  PV[18] = (u32)(eax);  // @355_4080d0
  eax = edx;  // @356_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @357_4080d0
  PV[19] = (u32)(eax);  // @358_4080d0
  PV[20] = (u32)(esi);  // @359_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4 + 32), sizeof v); (u32)v; });  // @360_4080d0
  PV[21] = (u32)(eax);  // @361_4080d0
  eax = ext_403fe0_cdecl6(PV[21], PV[20], PV[19], PV[18], PV[17], PV[16]);  // @362_4080d0
  ecx = edx = 0;  // @363_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @364_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492732), sizeof v); (u32)v; });  // @365_4080d0
  eax = (u32)(ecx + ebx*4);  // @366_4080d0
  PV[22] = (u32)(ebx);  // @367_4080d0
  edx = (edx + edi);  // @368_4080d0
  FL[3] = edx;  // @369_4080d0
  PV[23] = (u32)(eax);  // @370_4080d0
  PV[24] = (u32)(edx);  // @371_4080d0
  eax = ext_40ce50_cdecl6((u32)(7282372), PV[24], PV[23], PV[22], (u32)(1), (u32)(0));  // @372_4080d0
    // @373_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @374_4080d0
  PV[25] = (u32)(esi);  // @375_4080d0
  PV[26] = (u32)(esi);  // @376_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @377_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @378_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4), sizeof v); (u32)v; });  // @379_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @380_4080d0
  ecx = (u32)(ecx + ebx*4);  // @381_4080d0
  PV[27] = (u32)(ecx);  // @382_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @383_4080d0
  PV[28] = (u32)(ecx);  // @384_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @385_4080d0
  PV[29] = (u32)(ecx);  // @386_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @387_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @388_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4), sizeof v); (u32)v; });  // @389_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @390_4080d0
  PV[30] = (u32)(eax);  // @391_4080d0
  PV[31] = (u32)(ecx);  // @392_4080d0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 24)))(PV[31], PV[30], PV[29], PV[28], PV[27], PV[26], PV[25]);  // @393_4080d0
  ecx = edx = 0;  // @394_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @395_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @396_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @397_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @398_4080d0
  PV[32] = (u32)(eax);  // @399_4080d0
  PV[33] = (u32)(esi);  // @400_4080d0
  PV[34] = (u32)(eax);  // @401_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @402_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 + 32), sizeof v); (u32)v; });  // @403_4080d0
  PV[35] = (u32)(edx);  // @404_4080d0
  eax = ext_403f90_cdecl4(PV[35], PV[34], PV[33], PV[32]);  // @405_4080d0
  ecx = edx = 0;  // @406_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492732), sizeof v); (u32)v; });  // @407_4080d0
  PV[36] = (u32)(ebx);  // @408_4080d0
  eax = (eax + edi);  // @409_4080d0
  FL[3] = eax;  // @410_4080d0
  PV[37] = (u32)(esi);  // @411_4080d0
  PV[38] = (u32)(eax);  // @412_4080d0
  eax = ext_40ce50_cdecl6((u32)(7282360), PV[38], PV[37], PV[36], (u32)(1), (u32)(1));  // @413_4080d0
    // @414_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @415_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @416_4080d0
  eax = (u32)(4);  // @417_4080d0
  ecx = (ecx + eax);  // @418_4080d0
  FL[3] = ecx;  // @419_4080d0
  edx = (edx + eax);  // @420_4080d0
  FL[3] = edx;  // @421_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @422_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @423_4080d0
  edi = (edi + 1);  // @424_4080d0
  FL[3] = edi;  // @425_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @426_4080d0
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @427_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L4083aa;  // @428_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @429_4080d0
  ebx = ecx;  // @430_4080d0
  L408507:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @432_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @433_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @434_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @435_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @436_4080d0
  edi = (u32)(eax*4);  // @437_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @438_4080d0
  eax = edi;  // @439_4080d0
  eax = (eax + (u32)(3));  // @440_4080d0
  FL[3] = eax;  // @441_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @442_4080d0
  FL[3] = (eax & 0xff);  // @443_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @444_4080d0
  eax = edi;  // @445_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @446_4080d0
  eax = (eax + (u32)(3));  // @447_4080d0
  FL[3] = eax;  // @448_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @449_4080d0
  FL[3] = (eax & 0xff);  // @450_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @451_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @452_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @453_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @454_4080d0
  edi = (edi << (u32)(2));  // @455_4080d0
  FL[3] = edi;  // @456_4080d0
  eax = edi;  // @457_4080d0
  eax = (eax + (u32)(3));  // @458_4080d0
  FL[3] = eax;  // @459_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @460_4080d0
  FL[3] = (eax & 0xff);  // @461_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @462_4080d0
  eax = edi;  // @463_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @464_4080d0
  eax = (eax + (u32)(3));  // @465_4080d0
  FL[3] = eax;  // @466_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @467_4080d0
  FL[3] = (eax & 0xff);  // @468_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @469_4080d0
  eax = edi;  // @470_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @471_4080d0
  eax = (eax + (u32)(3));  // @472_4080d0
  FL[3] = eax;  // @473_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @474_4080d0
  FL[3] = (eax & 0xff);  // @475_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @476_4080d0
  eax = edi;  // @477_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @478_4080d0
  eax = (eax + (u32)(3));  // @479_4080d0
  FL[3] = eax;  // @480_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @481_4080d0
  FL[3] = (eax & 0xff);  // @482_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @483_4080d0
  eax = edi;  // @484_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @485_4080d0
  eax = (eax + (u32)(3));  // @486_4080d0
  FL[3] = eax;  // @487_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @488_4080d0
  FL[3] = (eax & 0xff);  // @489_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @490_4080d0
  eax = edi;  // @491_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @492_4080d0
  eax = (eax + (u32)(3));  // @493_4080d0
  FL[3] = eax;  // @494_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @495_4080d0
  FL[3] = (eax & 0xff);  // @496_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @497_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @498_4080d0
  eax = 0;  // @499_4080d0
  FL[3] = eax;  // @500_4080d0
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @501_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @502_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4200), sizeof v); (u32)v; });  // @503_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @504_4080d0
  FL[0] = ecx; FL[1] = eax;  // @505_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @506_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @507_4080d0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40862e;  // @508_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @509_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @510_4080d0
  eax = ecx;  // @511_4080d0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @512_4080d0
  eax = (eax - edx);  // @513_4080d0
  FL[3] = eax;  // @514_4080d0
  edi = eax;  // @515_4080d0
  eax = (u32)(ecx*4);  // @516_4080d0
  eax = (eax >> (u32)(1));  // @517_4080d0
  FL[3] = eax;  // @518_4080d0
  edi = (u32)((s32)edi >> (u32)(1));  // @519_4080d0
  FL[3] = edi;  // @520_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @521_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @522_4080d0
  ecx = esi;  // @523_4080d0
  edi = (edi << (u32)(2));  // @524_4080d0
  FL[3] = edi;  // @525_4080d0
  eax = (eax - ecx);  // @526_4080d0
  FL[3] = eax;  // @527_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @528_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @529_4080d0
  goto L4085ea;  // @530_4080d0
  L4085e7:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @532_4080d0
  L4085ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @534_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @535_4080d0
  eax = (eax << (u32)(2));  // @536_4080d0
  FL[3] = eax;  // @537_4080d0
  PV[39] = (u32)(eax);  // @538_4080d0
  PV[40] = (u32)(ecx);  // @539_4080d0
  eax = ext_401820_cdecl2(PV[40], PV[39]);  // @540_4080d0
  ecx = edx = 0;  // @541_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @542_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @543_4080d0
  edi = (edi + eax);  // @544_4080d0
  FL[3] = edi;  // @545_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + esi), &v, sizeof v); }  // @546_4080d0
  edx = ecx;  // @547_4080d0
  eax = 0;  // @548_4080d0
  FL[3] = eax;  // @549_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @550_4080d0
  ecx = (ecx >> (u32)(2));  // @551_4080d0
  FL[3] = ecx;  // @552_4080d0
  while (ecx) { __builtin_memcpy((void *)edi, &eax, 4); edi += 4; ecx--; }  // @553_4080d0
  ecx = edx;  // @554_4080d0
  esi = (esi + (u32)(4));  // @555_4080d0
  FL[3] = esi;  // @556_4080d0
  ecx = (ecx & (u32)(3));  // @557_4080d0
  FL[3] = ecx;  // @558_4080d0
  while (ecx) { *(u8 *)edi = (u8)eax; edi++; ecx--; }  // @559_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @560_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @561_4080d0
  eax = (eax + 1);  // @562_4080d0
  FL[3] = eax;  // @563_4080d0
  FL[0] = eax; FL[1] = ecx;  // @564_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @565_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L4085e7;  // @566_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @567_4080d0
  L40862e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @569_4080d0
  eax = (eax << (u32)(2));  // @570_4080d0
  FL[3] = eax;  // @571_4080d0
  eax = (eax + (u32)(3));  // @572_4080d0
  FL[3] = eax;  // @573_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @574_4080d0
  FL[3] = (eax & 0xff);  // @575_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @576_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @577_4080d0
  eax = ALLOC_PTR;  // @578_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @579_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @580_4080d0
  eax = (eax << (u32)(2));  // @581_4080d0
  FL[3] = eax;  // @582_4080d0
  eax = (eax + (u32)(3));  // @583_4080d0
  FL[3] = eax;  // @584_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @585_4080d0
  FL[3] = (eax & 0xff);  // @586_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @587_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @588_4080d0
  eax = ALLOC_PTR;  // @589_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @590_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @591_4080d0
  eax = (eax << (u32)(2));  // @592_4080d0
  FL[3] = eax;  // @593_4080d0
  eax = (eax + (u32)(3));  // @594_4080d0
  FL[3] = eax;  // @595_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @596_4080d0
  FL[3] = (eax & 0xff);  // @597_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @598_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @599_4080d0
  eax = ALLOC_PTR;  // @600_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @601_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @602_4080d0
  eax = (eax << (u32)(2));  // @603_4080d0
  FL[3] = eax;  // @604_4080d0
  eax = (eax + (u32)(3));  // @605_4080d0
  FL[3] = eax;  // @606_4080d0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @607_4080d0
  FL[3] = (eax & 0xff);  // @608_4080d0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @609_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @610_4080d0
  eax = ALLOC_PTR;  // @611_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @612_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @613_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1228), sizeof v); (u32)v; });  // @614_4080d0
  FL[2] = (ecx & ecx);  // @615_4080d0
  if (FL[2] != 0) goto L4086f5;  // @616_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @617_4080d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @618_4080d0
  FL[2] = (eax & eax);  // @619_4080d0
  if ((s32)FL[2] <= 0) goto L40871b;  // @620_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @621_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @622_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @623_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @624_4080d0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @625_4080d0
  eax = (eax - edx);  // @626_4080d0
  FL[3] = eax;  // @627_4080d0
  eax = (u32)((s32)eax >> (u32)(1));  // @628_4080d0
  FL[3] = eax;  // @629_4080d0
  ecx = (ecx - edi);  // @630_4080d0
  FL[3] = ecx;  // @631_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @632_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @633_4080d0
  goto L4086c3;  // @634_4080d0
  L4086c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @636_4080d0
  L4086c3:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi), sizeof v); (u32)v; });  // @638_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @639_4080d0
  FL[2] = (eax & eax);  // @640_4080d0
  if ((s32)FL[2] <= 0) goto L4086df;  // @641_4080d0
  edx = (edx - ecx);  // @642_4080d0
  FL[3] = edx;  // @643_4080d0
  L4086ce:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx), sizeof v); (u32)v; });  // @645_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @646_4080d0
  ecx = (ecx + (u32)(4));  // @647_4080d0
  FL[3] = ecx;  // @648_4080d0
  eax = (eax - 1);  // @649_4080d0
  FL[3] = eax;  // @650_4080d0
  if (FL[3] != 0) goto L4086ce;  // @651_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @652_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @653_4080d0
  L4086df:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @655_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @656_4080d0
  ecx = (ecx + 1);  // @657_4080d0
  FL[3] = ecx;  // @658_4080d0
  edi = (edi + (u32)(4));  // @659_4080d0
  FL[3] = edi;  // @660_4080d0
  FL[0] = ecx; FL[1] = edx;  // @661_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @662_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @663_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L4086c0;  // @664_4080d0
  goto L40871b;  // @665_4080d0
  L4086f5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @667_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @668_4080d0
  PV[41] = (u32)(ecx);  // @669_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @670_4080d0
  PV[42] = (u32)(edx);  // @671_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @672_4080d0
  PV[43] = (u32)(ecx);  // @673_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @674_4080d0
  PV[44] = (u32)(edx);  // @675_4080d0
  PV[45] = (u32)(eax);  // @676_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @677_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4 + 32), sizeof v); (u32)v; });  // @678_4080d0
  PV[46] = (u32)(edx);  // @679_4080d0
  eax = ext_404bd0_cdecl7(PV[46], PV[45], PV[44], PV[43], PV[42], PV[41], (u32)(0));  // @680_4080d0
  ecx = edx = 0;  // @681_4080d0
  L40871b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @683_4080d0
  edi = 0;  // @684_4080d0
  FL[3] = edi;  // @685_4080d0
  FL[2] = (eax & eax);  // @686_4080d0
  if ((s32)FL[2] <= 0) goto L40876c;  // @687_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @688_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @689_4080d0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @690_4080d0
  eax = (eax - edx);  // @691_4080d0
  FL[3] = eax;  // @692_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @693_4080d0
  eax = (u32)((s32)eax >> (u32)(1));  // @694_4080d0
  FL[3] = eax;  // @695_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @696_4080d0
  goto L40873a;  // @697_4080d0
  L408737:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @699_4080d0
  L40873a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @701_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492732), sizeof v); (u32)v; });  // @702_4080d0
  PV[47] = (u32)(eax);  // @703_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @704_4080d0
  ecx = (ecx + edi);  // @705_4080d0
  FL[3] = ecx;  // @706_4080d0
  PV[48] = (u32)(eax);  // @707_4080d0
  PV[49] = (u32)(ecx);  // @708_4080d0
  eax = ext_40ce50_cdecl6((u32)(7282352), PV[49], PV[48], PV[47], (u32)(1), (u32)(0));  // @709_4080d0
    // @710_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @711_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @712_4080d0
  edi = (edi + 1);  // @713_4080d0
  FL[3] = edi;  // @714_4080d0
  ecx = (ecx + (u32)(4));  // @715_4080d0
  FL[3] = ecx;  // @716_4080d0
  FL[0] = edi; FL[1] = eax;  // @717_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @718_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L408737;  // @719_4080d0
  L40876c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @721_4080d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @722_4080d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @723_4080d0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4088c8;  // @724_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @725_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @726_4080d0
  eax = esi;  // @727_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @728_4080d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @729_4080d0
  ecx = (ecx - eax);  // @730_4080d0
  FL[3] = ecx;  // @731_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @732_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @733_4080d0
  ecx = (ecx - eax);  // @734_4080d0
  FL[3] = ecx;  // @735_4080d0
  edx = (edx - eax);  // @736_4080d0
  FL[3] = edx;  // @737_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @738_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @739_4080d0
  ebx = (ebx - eax);  // @740_4080d0
  FL[3] = ebx;  // @741_4080d0
  ecx = (ecx - eax);  // @742_4080d0
  FL[3] = ecx;  // @743_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @744_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @745_4080d0
  goto L4087ae;  // @746_4080d0
  L4087ab:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @748_4080d0
  L4087ae:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @750_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @751_4080d0
  ecx = (ecx << (u32)(2));  // @752_4080d0
  FL[3] = ecx;  // @753_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @754_4080d0
  eax = 0;  // @755_4080d0
  FL[3] = eax;  // @756_4080d0
  edi = (edi + ecx);  // @757_4080d0
  FL[3] = edi;  // @758_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @759_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + edx), &v, sizeof v); }  // @760_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @761_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @762_4080d0
  edx = (edx + ecx);  // @763_4080d0
  FL[3] = edx;  // @764_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @765_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @766_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @767_4080d0
  edx = (edx + ecx);  // @768_4080d0
  FL[3] = edx;  // @769_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @770_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + ebx), &v, sizeof v); }  // @771_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @772_4080d0
  FL[2] = (edx & edx);  // @773_4080d0
  if ((s32)FL[2] <= 0) goto L408873;  // @774_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @775_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @776_4080d0
  edx = (edx + (u32)(4));  // @777_4080d0
  FL[3] = edx;  // @778_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @779_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @780_4080d0
  edx = (edx - ecx);  // @781_4080d0
  FL[3] = edx;  // @782_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @783_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @784_4080d0
  edx = (edx - ecx);  // @785_4080d0
  FL[3] = edx;  // @786_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @787_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @788_4080d0
  edx = (edx - ecx);  // @789_4080d0
  FL[3] = edx;  // @790_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @791_4080d0
  L408808:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @793_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @794_4080d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = edx;  // @795_4080d0
  if (FL[0] != FL[1]) goto L408858;  // @796_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @797_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx), sizeof v); (u32)v; });  // @798_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx), sizeof v); (u32)v; });  // @799_4080d0
  FL[2] = (edi & edi);  // @800_4080d0
  if (FL[2] == 0) goto L408828;  // @801_4080d0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edx + eax*4), &v, sizeof v); }  // @802_4080d0
  goto L40882f;  // @803_4080d0
  L408828:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + eax*4), &v, sizeof v); }  // @805_4080d0
  L40882f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @807_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @808_4080d0
  eax = (eax + 1);  // @809_4080d0
  FL[3] = eax;  // @810_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx), sizeof v); (u32)v; });  // @811_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx + eax*4 - 4), &v, sizeof v); }  // @812_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @813_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @814_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx), sizeof v); (u32)v; });  // @815_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi), sizeof v); (u32)v; });  // @816_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx + eax*4 - 4), &v, sizeof v); }  // @817_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @818_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @819_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx), sizeof v); (u32)v; });  // @820_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx + eax*4 - 4), &v, sizeof v); }  // @821_4080d0
  L408858:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @823_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @824_4080d0
  edi = (edi + (u32)(4));  // @825_4080d0
  FL[3] = edi;  // @826_4080d0
  edx = (edx + 1);  // @827_4080d0
  FL[3] = edx;  // @828_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @829_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @830_4080d0
  ecx = (ecx + (u32)(4));  // @831_4080d0
  FL[3] = ecx;  // @832_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @833_4080d0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @834_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L408808;  // @835_4080d0
  L408873:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @837_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @838_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @839_4080d0
  edx = (edx + eax);  // @840_4080d0
  FL[3] = edx;  // @841_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx), &v, sizeof v); }  // @842_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @843_4080d0
  PV[50] = (u32)(eax);  // @844_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx), sizeof v); (u32)v; });  // @845_4080d0
  PV[51] = (u32)(eax);  // @846_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @847_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @848_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @849_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; });  // @850_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @851_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi*4), sizeof v); (u32)v; });  // @852_4080d0
  PV[52] = (u32)(eax);  // @853_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*4), sizeof v); (u32)v; });  // @854_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @855_4080d0
  PV[53] = (u32)(eax);  // @856_4080d0
  PV[54] = (u32)(ecx);  // @857_4080d0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 24)))(PV[54], PV[53], PV[52], PV[51], PV[50]);  // @858_4080d0
  ecx = edx = 0;  // @859_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @860_4080d0
  edi = (edi + 1);  // @861_4080d0
  FL[3] = edi;  // @862_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edx), &v, sizeof v); }  // @863_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @864_4080d0
  esi = (esi + (u32)(4));  // @865_4080d0
  FL[3] = esi;  // @866_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @867_4080d0
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @868_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L4087ab;  // @869_4080d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @870_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @871_4080d0
  L4088c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @873_4080d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @874_4080d0
  FL[2] = (eax & eax);  // @875_4080d0
  if ((s32)FL[2] <= 0) goto L408a1a;  // @876_4080d0
  L4088da:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @878_4080d0
  edi = 0;  // @879_4080d0
  FL[3] = edi;  // @880_4080d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @881_4080d0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40895f;  // @882_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @883_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @884_4080d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @885_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @886_4080d0
  ecx = esi;  // @887_4080d0
  edx = (edx - ecx);  // @888_4080d0
  FL[3] = edx;  // @889_4080d0
  ebx = (ebx - ecx);  // @890_4080d0
  FL[3] = ebx;  // @891_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @892_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @893_4080d0
  eax = (eax - ecx);  // @894_4080d0
  FL[3] = eax;  // @895_4080d0
  edx = (edx - ecx);  // @896_4080d0
  FL[3] = edx;  // @897_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @898_4080d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @899_4080d0
  goto L40890b;  // @900_4080d0
  L408908:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @902_4080d0
  L40890b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @904_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; });  // @905_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @906_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi*4), sizeof v); (u32)v; });  // @907_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @908_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @909_4080d0
  PV[55] = (u32)(edx);  // @910_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi), sizeof v); (u32)v; });  // @911_4080d0
  PV[56] = (u32)(edx);  // @912_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @913_4080d0
  PV[57] = (u32)(edx);  // @914_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @915_4080d0
  PV[58] = (u32)(edx);  // @916_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @917_4080d0
  PV[59] = (u32)(eax);  // @918_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi), sizeof v); (u32)v; });  // @919_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @920_4080d0
  PV[60] = (u32)(eax);  // @921_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi), sizeof v); (u32)v; });  // @922_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @923_4080d0
  PV[61] = (u32)(eax);  // @924_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @925_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @926_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @927_4080d0
  PV[62] = (u32)(edx);  // @928_4080d0
  PV[63] = (u32)(eax);  // @929_4080d0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 28)))(PV[63], PV[62], PV[61], PV[60], PV[59], PV[58], PV[57], PV[56], PV[55]);  // @930_4080d0
  ecx = edx = 0;  // @931_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @932_4080d0
  edi = (edi + 1);  // @933_4080d0
  FL[3] = edi;  // @934_4080d0
  esi = (esi + (u32)(4));  // @935_4080d0
  FL[3] = esi;  // @936_4080d0
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @937_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L408908;  // @938_4080d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @939_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @940_4080d0
  eax = ecx;  // @941_4080d0
  L40895f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @943_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @944_4080d0
  ecx = (ecx + 1);  // @945_4080d0
  FL[3] = ecx;  // @946_4080d0
  FL[0] = ecx; FL[1] = edx;  // @947_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @948_4080d0
  if ((s32)FL[0] >= (s32)FL[1]) goto L408a1a;  // @949_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1228), sizeof v); (u32)v; });  // @950_4080d0
  FL[2] = (edx & edx);  // @951_4080d0
  if (FL[2] != 0) goto L4089f0;  // @952_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @953_4080d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @954_4080d0
  FL[2] = (eax & eax);  // @955_4080d0
  if ((s32)FL[2] <= 0) goto L4088da;  // @956_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @957_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @958_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @959_4080d0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @960_4080d0
  eax = (eax - edx);  // @961_4080d0
  FL[3] = eax;  // @962_4080d0
  esi = eax;  // @963_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @964_4080d0
  esi = (u32)((s32)esi >> (u32)(1));  // @965_4080d0
  FL[3] = esi;  // @966_4080d0
  ecx = (ecx - eax);  // @967_4080d0
  FL[3] = ecx;  // @968_4080d0
  edi = (edi - eax);  // @969_4080d0
  FL[3] = edi;  // @970_4080d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @971_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @972_4080d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @973_4080d0
  goto L4089b5;  // @974_4080d0
  L4089af:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @976_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @977_4080d0
  L4089b5:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @979_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @980_4080d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax), sizeof v); (u32)v; });  // @981_4080d0
  FL[2] = (esi & esi);  // @982_4080d0
  if ((s32)FL[2] <= 0) goto L4089d7;  // @983_4080d0
  edx = (edx - ecx);  // @984_4080d0
  FL[3] = edx;  // @985_4080d0
  edi = (edi - ecx);  // @986_4080d0
  FL[3] = edi;  // @987_4080d0
  L4089c5:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx + ecx)) : "st");  // @989_4080d0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @990_4080d0
  ecx = (ecx + (u32)(4));  // @991_4080d0
  FL[3] = ecx;  // @992_4080d0
  esi = (esi - 1);  // @993_4080d0
  FL[3] = esi;  // @994_4080d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + ecx - 4)) :: "st");  // @995_4080d0
  if (FL[3] != 0) goto L4089c5;  // @996_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @997_4080d0
  L4089d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @999_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @1000_4080d0
  ecx = (ecx + 1);  // @1001_4080d0
  FL[3] = ecx;  // @1002_4080d0
  eax = (eax + (u32)(4));  // @1003_4080d0
  FL[3] = eax;  // @1004_4080d0
  FL[0] = ecx; FL[1] = edx;  // @1005_4080d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @1006_4080d0
  if ((s32)FL[0] < (s32)FL[1]) goto L4089af;  // @1007_4080d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1008_4080d0
  goto L4088da;  // @1009_4080d0
  L4089f0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @1011_4080d0
  PV[64] = (u32)(ecx);  // @1012_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @1013_4080d0
  PV[65] = (u32)(edx);  // @1014_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @1015_4080d0
  PV[66] = (u32)(ecx);  // @1016_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @1017_4080d0
  PV[67] = (u32)(edx);  // @1018_4080d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1019_4080d0
  PV[68] = (u32)(ecx);  // @1020_4080d0
  PV[69] = (u32)(eax);  // @1021_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @1022_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4 + 32), sizeof v); (u32)v; });  // @1023_4080d0
  PV[70] = (u32)(ecx);  // @1024_4080d0
  eax = ext_404bd0_cdecl7(PV[70], PV[69], PV[68], PV[67], PV[66], PV[65], PV[64]);  // @1025_4080d0
  ecx = edx = 0;  // @1026_4080d0
  goto L4088da;  // @1027_4080d0
  L408a1a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @1029_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492732), sizeof v); (u32)v; });  // @1030_4080d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1031_4080d0
  eax = (eax + edx);  // @1032_4080d0
  FL[3] = eax;  // @1033_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7492732), &v, sizeof v); }  // @1034_4080d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @1035_4080d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 56), &v, sizeof v); }  // @1036_4080d0
  eax = 0;  // @1037_4080d0
  FL[3] = eax;  // @1038_4080d0
  return eax;  // @1039_4080d0
}
PCREG(4080d0, lifted_4080d0);

extern "C" u32 lifted_404700(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_404700
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069848)) : "st");  // @2_404700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069848)) : "st");  // @4_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069848)) : "st");  // @5_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069848)) : "st");  // @6_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069848)) : "st");  // @7_404700
  eax = (u32)((s32)eax >> (u32)(16));  // @8_404700
  FL[3] = eax;  // @9_404700
  ebx = eax;  // @10_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 96) + 16), &v, sizeof v); }  // @11_404700
  eax = 0;  // @12_404700
  FL[3] = eax;  // @13_404700
  FL[0] = edx; FL[1] = eax;  // @14_404700
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 36), &v, sizeof v); }  // @15_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 28), &v, sizeof v); }  // @16_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 32), &v, sizeof v); }  // @17_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 80), &v, sizeof v); }  // @18_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 84), &v, sizeof v); }  // @19_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 72), &v, sizeof v); }  // @20_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 76), &v, sizeof v); }  // @21_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 88), &v, sizeof v); }  // @22_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 92), &v, sizeof v); }  // @23_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 48), &v, sizeof v); }  // @24_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 52), &v, sizeof v); }  // @25_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 56), &v, sizeof v); }  // @26_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 60), &v, sizeof v); }  // @27_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 20), &v, sizeof v); }  // @28_404700
  if ((s32)FL[0] <= (s32)FL[1]) goto L404bb6;  // @29_404700
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @30_404700
  eax = ecx;  // @31_404700
  esi = (esi - ecx);  // @32_404700
  FL[3] = esi;  // @33_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 40), &v, sizeof v); }  // @34_404700
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 104) + 44), &v, sizeof v); }  // @35_404700
  L40478c:;
  FL[0] = ebx; FL[1] = edx;  // @37_404700
  if ((s32)FL[0] >= (s32)FL[1]) goto L4048f9;  // @38_404700
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_404700
  ecx = edi;  // @40_404700
  ecx = (ecx & (u32)(65535));  // @41_404700
  FL[3] = ecx;  // @42_404700
  FL[0] = ebx; FL[1] = ecx;  // @43_404700
  if ((s32)FL[0] >= (s32)FL[1]) goto L404844;  // @44_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @45_404700
  esi = ebx;  // @46_404700
  __asm__ volatile("fchs" ::: "st");  // @47_404700
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 16)) :: "st");  // @48_404700
  FL[1] = esi;  // @49_404700
  esi = (0u - esi);  // @50_404700
  esi = (esi << (u32)(2));  // @51_404700
  FL[3] = esi;  // @52_404700
  L4047b6:;
  FL[2] = (ebx & ebx);  // @54_404700
  edx = esi;  // @55_404700
  if ((s32)FL[2] < 0) goto L4047c3;  // @56_404700
  edx = (u32)(ebx*4);  // @57_404700
  L4047c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @59_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx + eax)) : "st");  // @60_404700
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)((EBP - 104) + 16)) : "st", "cc");  // @61_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @62_404700
  FL[2] = ((eax >> 8) & 1);  // @63_404700
  if (FL[2] == 0) goto L4047dc;  // @64_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069720)) : "st");  // @65_404700
  goto L4047e5;  // @66_404700
  L4047dc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @68_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @69_404700
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edx + eax)) : "st");  // @70_404700
  L4047e5:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @72_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @73_404700
  edx = ebx;  // @74_404700
  esi = (esi - (u32)(4));  // @75_404700
  FL[3] = esi;  // @76_404700
  edx = (u32)((s32)edx * (s32)ebx);  // @77_404700
  FL[3] = edx;  // @78_404700
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @79_404700
  __asm__ volatile("faddl %0" :: "m"(*(double *)(u32)((EBP - 104) + 48)) : "st");  // @80_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 48)) :: "st");  // @81_404700
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 36)) : "st");  // @82_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @83_404700
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 36), &v, sizeof v); }  // @84_404700
  ebx = (ebx + 1);  // @85_404700
  FL[3] = ebx;  // @86_404700
  FL[0] = ebx; FL[1] = ecx;  // @87_404700
  __asm__ volatile("fstl %0" : "=m"(*(double *)(u32)((EBP - 104) + 96)) :: "st");  // @88_404700
  __asm__ volatile(".byte 0xde, 0xc7" ::: "st");  // @89_404700
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @90_404700
  __asm__ volatile(".byte 0xd8, 0xca" ::: "st");  // @91_404700
  __asm__ volatile("faddl %0" :: "m"(*(double *)(u32)((EBP - 104) + 80)) : "st");  // @92_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 80)) :: "st");  // @93_404700
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 36)) : "st");  // @94_404700
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 104) + 36), &v, sizeof v); }  // @95_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @96_404700
  __asm__ volatile("faddl %0" :: "m"(*(double *)(u32)((EBP - 104) + 72)) : "st");  // @97_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 72)) :: "st");  // @98_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @99_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @100_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @101_404700
  __asm__ volatile("faddl %0" :: "m"(*(double *)(u32)((EBP - 104) + 88)) : "st");  // @102_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 88)) :: "st");  // @103_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @104_404700
  if ((s32)FL[0] < (s32)FL[1]) goto L4047b6;  // @105_404700
  L404844:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 24), sizeof v); (u32)v; });  // @107_404700
  edi = (u32)((s32)edi >> (u32)(16));  // @108_404700
  FL[3] = edi;  // @109_404700
  FL[0] = edx; FL[1] = edi;  // @110_404700
  if ((s32)FL[0] >= (s32)FL[1]) goto L4048f9;  // @111_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @112_404700
  __asm__ volatile("fchs" ::: "st");  // @113_404700
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 16)) :: "st");  // @114_404700
  FL[1] = edx;  // @115_404700
  edx = (0u - edx);  // @116_404700
  edx = (edx << (u32)(2));  // @117_404700
  FL[3] = edx;  // @118_404700
  L404861:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 24), sizeof v); (u32)v; });  // @120_404700
  ecx = edx;  // @121_404700
  FL[2] = (esi & esi);  // @122_404700
  if ((s32)FL[2] < 0) goto L404872;  // @123_404700
  ecx = (u32)(esi*4);  // @124_404700
  L404872:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @126_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + eax)) : "st");  // @127_404700
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)((EBP - 104) + 16)) : "st", "cc");  // @128_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @129_404700
  FL[2] = ((eax >> 8) & 1);  // @130_404700
  if (FL[2] == 0) goto L40488b;  // @131_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069720)) : "st");  // @132_404700
  goto L404894;  // @133_404700
  L40488b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @135_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @136_404700
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx + eax)) : "st");  // @137_404700
  L404894:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @139_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @140_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 48)) : "st");  // @141_404700
  ecx = esi;  // @142_404700
  edx = (edx - (u32)(4));  // @143_404700
  FL[3] = edx;  // @144_404700
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @145_404700
  ecx = (u32)((s32)ecx * (s32)esi);  // @146_404700
  FL[3] = ecx;  // @147_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 48)) :: "st");  // @148_404700
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 24)) : "st");  // @149_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @150_404700
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 24), &v, sizeof v); }  // @151_404700
  esi = (esi + 1);  // @152_404700
  FL[3] = esi;  // @153_404700
  FL[0] = esi; FL[1] = edi;  // @154_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 96)) :: "st");  // @155_404700
  __asm__ volatile(".byte 0xd9, 0xce" ::: "st");  // @156_404700
  __asm__ volatile("fsubl %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @157_404700
  __asm__ volatile(".byte 0xd9, 0xce" ::: "st");  // @158_404700
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @159_404700
  __asm__ volatile(".byte 0xd8, 0xca" ::: "st");  // @160_404700
  __asm__ volatile("fsubrl %0" :: "m"(*(double *)(u32)((EBP - 104) + 80)) : "st");  // @161_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 80)) :: "st");  // @162_404700
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 24)) : "st");  // @163_404700
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 104) + 24), &v, sizeof v); }  // @164_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @165_404700
  __asm__ volatile("fsubrl %0" :: "m"(*(double *)(u32)((EBP - 104) + 72)) : "st");  // @166_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 72)) :: "st");  // @167_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @168_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @169_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @170_404700
  __asm__ volatile("fsubrl %0" :: "m"(*(double *)(u32)((EBP - 104) + 88)) : "st");  // @171_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 88)) :: "st");  // @172_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @173_404700
  if ((s32)FL[0] < (s32)FL[1]) goto L404861;  // @174_404700
  L4048f9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @176_404700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 28), sizeof v); (u32)v; });  // @177_404700
  FL[0] = eax; FL[1] = edx;  // @178_404700
  if ((s32)FL[0] >= (s32)FL[1]) goto L404a68;  // @179_404700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @180_404700
  FL[2] = (eax & eax);  // @181_404700
  if ((s32)FL[2] <= 0) goto L404a68;  // @182_404700
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 20), sizeof v); (u32)v; });  // @183_404700
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @184_404700
  eax = (eax - edx);  // @185_404700
  FL[3] = eax;  // @186_404700
  ecx = eax;  // @187_404700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @188_404700
  ecx = (u32)((s32)ecx >> (u32)(1));  // @189_404700
  FL[3] = ecx;  // @190_404700
  ecx = (ecx + esi);  // @191_404700
  FL[3] = ecx;  // @192_404700
  FL[0] = ecx; FL[1] = eax;  // @193_404700
  if ((s32)FL[0] <= (s32)FL[1]) goto L404929;  // @194_404700
  ecx = eax;  // @195_404700
  L404929:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 28), sizeof v); (u32)v; });  // @197_404700
  FL[0] = edi; FL[1] = ecx;  // @198_404700
  if ((s32)FL[0] >= (s32)FL[1]) goto L4049bd;  // @199_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @200_404700
  esi = edi;  // @201_404700
  __asm__ volatile("fchs" ::: "st");  // @202_404700
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 16)) :: "st");  // @203_404700
  FL[1] = esi;  // @204_404700
  esi = (0u - esi);  // @205_404700
  esi = (esi << (u32)(2));  // @206_404700
  FL[3] = esi;  // @207_404700
  L404945:;
  FL[2] = (edi & edi);  // @209_404700
  edx = esi;  // @210_404700
  if ((s32)FL[2] < 0) goto L404952;  // @211_404700
  edx = (u32)(edi*4);  // @212_404700
  L404952:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @214_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx + eax)) : "st");  // @215_404700
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)((EBP - 104) + 16)) : "st", "cc");  // @216_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @217_404700
  FL[2] = ((eax >> 8) & 1);  // @218_404700
  if (FL[2] == 0) goto L40496b;  // @219_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069720)) : "st");  // @220_404700
  goto L404974;  // @221_404700
  L40496b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @223_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @224_404700
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edx + eax)) : "st");  // @225_404700
  L404974:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @227_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @228_404700
  edx = edi;  // @229_404700
  esi = (esi - (u32)(4));  // @230_404700
  FL[3] = esi;  // @231_404700
  edx = (u32)((s32)edx * (s32)edi);  // @232_404700
  FL[3] = edx;  // @233_404700
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @234_404700
  __asm__ volatile("faddl %0" :: "m"(*(double *)(u32)((EBP - 104) + 56)) : "st");  // @235_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 56)) :: "st");  // @236_404700
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 28)) : "st");  // @237_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @238_404700
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 104) + 28), &v, sizeof v); }  // @239_404700
  edi = (edi + 1);  // @240_404700
  FL[3] = edi;  // @241_404700
  FL[0] = edi; FL[1] = ecx;  // @242_404700
  __asm__ volatile("fstl %0" : "=m"(*(double *)(u32)((EBP - 104) + 96)) :: "st");  // @243_404700
  __asm__ volatile(".byte 0xde, 0xc6" ::: "st");  // @244_404700
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @245_404700
  __asm__ volatile(".byte 0xd8, 0xca" ::: "st");  // @246_404700
  __asm__ volatile(".byte 0xde, 0xc5" ::: "st");  // @247_404700
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 28)) : "st");  // @248_404700
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 104) + 28), &v, sizeof v); }  // @249_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @250_404700
  __asm__ volatile(".byte 0xde, 0xc4" ::: "st");  // @251_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @252_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @253_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @254_404700
  __asm__ volatile(".byte 0xde, 0xc2" ::: "st");  // @255_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @256_404700
  if ((s32)FL[0] < (s32)FL[1]) goto L404945;  // @257_404700
  L4049bd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @259_404700
  eax = (eax + 1);  // @260_404700
  FL[3] = eax;  // @261_404700
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @262_404700
  eax = (eax - edx);  // @263_404700
  FL[3] = eax;  // @264_404700
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 20), sizeof v); (u32)v; });  // @265_404700
  eax = (u32)((s32)eax >> (u32)(1));  // @266_404700
  FL[3] = eax;  // @267_404700
  edx = (edx - eax);  // @268_404700
  FL[3] = edx;  // @269_404700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 32), sizeof v); (u32)v; });  // @270_404700
  FL[0] = eax; FL[1] = edx;  // @271_404700
  if ((s32)FL[0] >= (s32)FL[1]) goto L404a68;  // @272_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @273_404700
  edi = eax;  // @274_404700
  esi = edi;  // @275_404700
  __asm__ volatile("fchs" ::: "st");  // @276_404700
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 104) + 16)) :: "st");  // @277_404700
  FL[1] = esi;  // @278_404700
  esi = (0u - esi);  // @279_404700
  esi = (esi << (u32)(2));  // @280_404700
  FL[3] = esi;  // @281_404700
  L4049ea:;
  FL[2] = (edi & edi);  // @283_404700
  ecx = esi;  // @284_404700
  if ((s32)FL[2] < 0) goto L4049f7;  // @285_404700
  ecx = (u32)(edi*4);  // @286_404700
  L4049f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @288_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + eax)) : "st");  // @289_404700
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)((EBP - 104) + 16)) : "st", "cc");  // @290_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @291_404700
  FL[2] = ((eax >> 8) & 1);  // @292_404700
  if (FL[2] == 0) goto L404a10;  // @293_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069720)) : "st");  // @294_404700
  goto L404a19;  // @295_404700
  L404a10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @297_404700
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @298_404700
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx + eax)) : "st");  // @299_404700
  L404a19:;
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @301_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @302_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 56)) : "st");  // @303_404700
  ecx = edi;  // @304_404700
  esi = (esi - (u32)(4));  // @305_404700
  FL[3] = esi;  // @306_404700
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @307_404700
  ecx = (u32)((s32)ecx * (s32)edi);  // @308_404700
  FL[3] = ecx;  // @309_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 56)) :: "st");  // @310_404700
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 32)) : "st");  // @311_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @312_404700
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 32), &v, sizeof v); }  // @313_404700
  edi = (edi + 1);  // @314_404700
  FL[3] = edi;  // @315_404700
  FL[0] = edi; FL[1] = edx;  // @316_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 96)) :: "st");  // @317_404700
  __asm__ volatile(".byte 0xd9, 0xcd" ::: "st");  // @318_404700
  __asm__ volatile("fsubl %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @319_404700
  __asm__ volatile(".byte 0xd9, 0xcd" ::: "st");  // @320_404700
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @321_404700
  __asm__ volatile(".byte 0xd8, 0xca" ::: "st");  // @322_404700
  __asm__ volatile(".byte 0xde, 0xed" ::: "st");  // @323_404700
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 32)) : "st");  // @324_404700
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 104) + 32), &v, sizeof v); }  // @325_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @326_404700
  __asm__ volatile(".byte 0xde, 0xec" ::: "st");  // @327_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @328_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @329_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @330_404700
  __asm__ volatile(".byte 0xde, 0xea" ::: "st");  // @331_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @332_404700
  if ((s32)FL[0] < (s32)FL[1]) goto L4049ea;  // @333_404700
  L404a68:;
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 48)) : "st");  // @335_404700
  __asm__ volatile("fcompl %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(double *)(u32)(7069736)) : "st", "cc");  // @336_404700
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 104) + 64), &v, sizeof v); }  // @337_404700
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 104) + 68), &v, sizeof v); }  // @338_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @339_404700
  FL[2] = ((eax >> 8) & 65);  // @340_404700
  if (FL[2] != 0) goto L404af0;  // @341_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 48)) : "st");  // @342_404700
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)((EBP - 104) + 72)) : "st");  // @343_404700
  __asm__ volatile(".byte 0xd9, 0xc5" ::: "st");  // @344_404700
  __asm__ volatile(".byte 0xd8, 0xce" ::: "st");  // @345_404700
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @346_404700
  __asm__ volatile("fdivrl %0" :: "m"(*(double *)(u32)(7069720)) : "st");  // @347_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 96)) :: "st");  // @348_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 48)) : "st");  // @349_404700
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)((EBP - 104) + 88)) : "st");  // @350_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 80)) : "st");  // @351_404700
  __asm__ volatile(".byte 0xd8, 0xce" ::: "st");  // @352_404700
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @353_404700
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @354_404700
  __asm__ volatile("fimull %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 20)) : "st");  // @355_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 72)) : "st");  // @356_404700
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)((EBP - 104) + 80)) : "st");  // @357_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 88)) : "st");  // @358_404700
  __asm__ volatile(".byte 0xd8, 0xcf" ::: "st");  // @359_404700
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @360_404700
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @361_404700
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @362_404700
  __asm__ volatile("fstl %0" : "=m"(*(double *)(u32)((EBP - 104) + 64)) :: "st");  // @363_404700
  __asm__ volatile("fcompl %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(double *)(u32)(7069848)) : "st", "cc");  // @364_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @365_404700
  FL[2] = ((eax >> 8) & 1);  // @366_404700
  if (FL[2] == 0) goto L404af0;  // @367_404700
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 104) + 64), &v, sizeof v); }  // @368_404700
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 104) + 68), &v, sizeof v); }  // @369_404700
  L404af0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @371_404700
  FL[2] = (eax & eax);  // @372_404700
  if ((s32)FL[2] <= 0) goto L404b89;  // @373_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069848)) : "st");  // @374_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 56)) : "st");  // @375_404700
  __asm__ volatile("fcompl %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(double *)(u32)(7069736)) : "st", "cc");  // @376_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @377_404700
  FL[2] = ((eax >> 8) & 65);  // @378_404700
  if (FL[2] != 0) goto L404b67;  // @379_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @380_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 56)) : "st");  // @381_404700
  __asm__ volatile(".byte 0xd8, 0xca" ::: "st");  // @382_404700
  __asm__ volatile(".byte 0xd9, 0xc4" ::: "st");  // @383_404700
  __asm__ volatile(".byte 0xd8, 0xcd" ::: "st");  // @384_404700
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @385_404700
  __asm__ volatile("fdivrl %0" :: "m"(*(double *)(u32)(7069720)) : "st");  // @386_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 96)) :: "st");  // @387_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 56)) : "st");  // @388_404700
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @389_404700
  __asm__ volatile(".byte 0xd9, 0xc3" ::: "st");  // @390_404700
  __asm__ volatile(".byte 0xd8, 0xcd" ::: "st");  // @391_404700
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @392_404700
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @393_404700
  __asm__ volatile("fimull %0" :: "m"(*(s32 *)(u32)((EBP - 104) + 20)) : "st");  // @394_404700
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @395_404700
  __asm__ volatile(".byte 0xd8, 0xcc" ::: "st");  // @396_404700
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @397_404700
  __asm__ volatile(".byte 0xd8, 0xce" ::: "st");  // @398_404700
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @399_404700
  __asm__ volatile("fmull %0" :: "m"(*(double *)(u32)((EBP - 104) + 96)) : "st");  // @400_404700
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @401_404700
  __asm__ volatile("fcoml %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(double *)(u32)(7069848)) : "st", "cc");  // @402_404700
  __asm__ volatile("fstl %0" : "=m"(*(double *)(u32)((EBP - 104) + 96)) :: "st");  // @403_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @404_404700
  FL[2] = ((eax >> 8) & 1);  // @405_404700
  if (FL[2] == 0) goto L404b67;  // @406_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @407_404700
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(7069848)) : "st");  // @408_404700
  L404b67:;
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 104) + 64)) : "st");  // @410_404700
  __asm__ volatile(".byte 0xd8, 0xd9; fnstsw %%ax" : "=a"(X87SW) :: "st", "cc");  // @411_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @412_404700
  FL[2] = ((eax >> 8) & 65);  // @413_404700
  if (FL[2] != 0) goto L404b87;  // @414_404700
  __asm__ volatile("fcoml %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(double *)(u32)(7069848)) : "st", "cc");  // @415_404700
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @416_404700
  FL[2] = ((eax >> 8) & 65);  // @417_404700
  if (FL[2] != 0) goto L404b87;  // @418_404700
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 104) + 64)) :: "st");  // @419_404700
  goto L404b89;  // @420_404700
  L404b87:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @422_404700
  L404b89:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @424_404700
  __asm__ volatile("fsubrl %0" :: "m"(*(double *)(u32)((EBP - 104) + 64)) : "st");  // @425_404700
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 44), sizeof v); (u32)v; });  // @426_404700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 40), sizeof v); (u32)v; });  // @427_404700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 104) + 20), sizeof v); (u32)v; });  // @428_404700
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + eax)) :: "st");  // @429_404700
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @430_404700
  ecx = (ecx + 1);  // @431_404700
  FL[3] = ecx;  // @432_404700
  eax = (eax + (u32)(4));  // @433_404700
  FL[3] = eax;  // @434_404700
  FL[0] = ecx; FL[1] = edx;  // @435_404700
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 104) + 20), &v, sizeof v); }  // @436_404700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 104) + 40), &v, sizeof v); }  // @437_404700
  if ((s32)FL[0] < (s32)FL[1]) goto L40478c;  // @438_404700
  L404bb6:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @440_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @441_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @442_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @443_404700
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @444_404700
  return eax;  // @445_404700
}
PCREG(404700, lifted_404700);

