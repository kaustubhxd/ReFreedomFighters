// batch200124.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d2d30_thiscall3(u32, u32, u32) __asm__("ext_4d2d30");
extern "C" u32 THISCALL ext_4db2f0_thiscall2(u32, u32) __asm__("ext_4db2f0");
extern "C" u32 ext_4513e0_cdecl0(void) __asm__("ext_4513e0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_46e6b0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 136), 4); (double)v; });  // @0_46e6b0
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @1_46e6b0
  return eax;  // @2_46e6b0
}
PCREG(46e6b0, lifted_46e6b0);

extern "C" u32 THISCALL lifted_46e6c0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 180), 4); (double)v; });  // @0_46e6c0
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @1_46e6c0
  return eax;  // @2_46e6c0
}
PCREG(46e6c0, lifted_46e6c0);

extern "C" u32 THISCALL lifted_46ece0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 132), 4); (double)v; });  // @0_46ece0
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @1_46ece0
  return eax;  // @2_46ece0
}
PCREG(46ece0, lifted_46ece0);

extern "C" u32 THISCALL lifted_46ecf0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 176), 4); (double)v; });  // @0_46ecf0
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @1_46ecf0
  return eax;  // @2_46ecf0
}
PCREG(46ecf0, lifted_46ecf0);

extern "C" u32 THISCALL lifted_46ed20(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), 4); (double)v; });  // @0_46ed20
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @1_46ed20
  return eax;  // @2_46ed20
}
PCREG(46ed20, lifted_46ed20);

extern "C" u32 THISCALL lifted_46ef60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 192), 4); (double)v; });  // @0_46ef60
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @1_46ef60
  return eax;  // @2_46ef60
}
PCREG(46ef60, lifted_46ef60);

extern "C" u32 lifted_655260(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  T[0] = 1.0;  // @0_655260
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @1_655260
  return eax;  // @2_655260
}
PCREG(655260, lifted_655260);

extern "C" u32 FASTCALL lifted_663bd0(u32 ecx_in, u32 edx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), 4); (double)v; });  // @0_663bd0
  T[0] = (T[0] * ({ float v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), 4); (double)v; }));  // @1_663bd0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx), 4); (double)v; });  // @2_663bd0
  T[1] = (T[1] * ({ float v; __builtin_memcpy(&v, (void *)(u32)(edx), 4); (double)v; }));  // @3_663bd0
  T[0] = (T[0] + T[1]);  // @4_663bd0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), 4); (double)v; });  // @5_663bd0
  T[1] = (T[1] * ({ float v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), 4); (double)v; }));  // @6_663bd0
  T[0] = (T[0] + T[1]);  // @7_663bd0
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @8_663bd0
  return eax;  // @9_663bd0
}
PCREG(663bd0, lifted_663bd0);

extern "C" u32 THISCALL lifted_451560(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_451560
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7338368), sizeof v); (u32)v; }) != (u32)(0)) goto L451579;  // @1_451560
  eax = ext_4513e0_cdecl0();  // @2_451560
  ecx = edx = 0;  // @3_451560
  L451579:;
  x5 = _mm_load_ss((const float *)(u32)(esi));  // @5_451560
  x2 = _mm_load_ss((const float *)(u32)(6820736));  // @6_451560
  x4 = _mm_load_ss((const float *)(u32)(esi + 4));  // @7_451560
  x5 = _mm_add_ss(x5, x2);  // @8_451560
  x1 = _mm_load_ss((const float *)(u32)(6785112));  // @9_451560
  x4 = _mm_add_ss(x4, x2);  // @10_451560
  x3 = _mm_load_ss((const float *)(u32)(esi + 8));  // @11_451560
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338360), sizeof v); (u32)v; });  // @12_451560
  x3 = _mm_add_ss(x3, x2);  // @13_451560
  x7 = _mm_load_ss((const float *)(u32)(6818408));  // @14_451560
  eax = (u32)_mm_cvtss_si32(x5);  // @15_451560
  ecx = (u32)_mm_cvtss_si32(x4);  // @16_451560
  edx = (eax & 0xff);  // @17_451560
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @18_451560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*4), sizeof v); (u32)v; });  // @19_451560
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @20_451560
  x6 = x7;  // @21_451560
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @22_451560
  edi = (ecx & 0xff);  // @23_451560
  eax = (u32)(edi + 1);  // @24_451560
  x5 = _mm_sub_ss(x5, x0);  // @25_451560
  ebx = (eax & 0xff);  // @26_451560
  x0 = x5;  // @27_451560
  _mm_store_ss((float *)(u32)(EBP - 4), x5);  // @28_451560
  x0 = _mm_sub_ss(x0, x1);  // @29_451560
  _mm_store_ss((float *)(u32)(EBP - 12), x0);  // @30_451560
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ecx));  // @31_451560
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @32_451560
  ecx = (u32)_mm_cvtss_si32(x3);  // @33_451560
  x4 = _mm_sub_ss(x4, x0);  // @34_451560
  eax = (ecx & 0xff);  // @35_451560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @36_451560
  eax = (eax + 1);  // @37_451560
  eax = (eax & 0xff);  // @38_451560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @39_451560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @40_451560
  x0 = x4;  // @41_451560
  x0 = _mm_sub_ss(x0, x1);  // @42_451560
  _mm_store_ss((float *)(u32)(EBP - 44), x4);  // @43_451560
  eax = (eax + 1);  // @44_451560
  eax = (eax & 0xff);  // @45_451560
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @46_451560
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ecx));  // @47_451560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4), sizeof v); (u32)v; });  // @48_451560
  eax = (u32)(edx + edi);  // @49_451560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4), sizeof v); (u32)v; });  // @50_451560
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @51_451560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @52_451560
  eax = (u32)(ecx + edi);  // @53_451560
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4), sizeof v); (u32)v; });  // @54_451560
  eax = (u32)(edx + ebx);  // @55_451560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4), sizeof v); (u32)v; });  // @56_451560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @57_451560
  x3 = _mm_sub_ss(x3, x0);  // @58_451560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @59_451560
  x0 = x5;  // @60_451560
  eax = (u32)(ecx + ebx);  // @61_451560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @62_451560
  x0 = _mm_add_ss(x0, x5);  // @63_451560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4), sizeof v); (u32)v; });  // @64_451560
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338364), sizeof v); (u32)v; });  // @65_451560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @66_451560
  _mm_store_ss((float *)(u32)(EBP - 16), x3);  // @67_451560
  eax = (u32)(edx + ecx);  // @68_451560
  x6 = _mm_sub_ss(x6, x0);  // @69_451560
  x0 = x5;  // @70_451560
  x0 = _mm_mul_ss(x0, x5);  // @71_451560
  x3 = _mm_sub_ss(x3, x1);  // @72_451560
  eax = (u32)(eax + eax*2);  // @73_451560
  x1 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 4));  // @74_451560
  x5 = x7;  // @75_451560
  x1 = _mm_mul_ss(x1, x4);  // @76_451560
  x6 = _mm_mul_ss(x6, x0);  // @77_451560
  x0 = x4;  // @78_451560
  x0 = _mm_add_ss(x0, x4);  // @79_451560
  _mm_store_ss((float *)(u32)(EBP - 24), x3);  // @80_451560
  x5 = _mm_sub_ss(x5, x0);  // @81_451560
  x0 = x4;  // @82_451560
  x0 = _mm_mul_ss(x0, x4);  // @83_451560
  x5 = _mm_mul_ss(x5, x0);  // @84_451560
  x0 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @85_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ebx + eax*4)));  // @86_451560
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @87_451560
  x1 = _mm_add_ss(x1, x0);  // @88_451560
  x0 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 8));  // @89_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 16)));  // @90_451560
  eax = (u32)(edi + ecx);  // @91_451560
  eax = (u32)(eax + eax*2);  // @92_451560
  x2 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 4));  // @93_451560
  x2 = _mm_mul_ss(x2, x4);  // @94_451560
  x1 = _mm_add_ss(x1, x0);  // @95_451560
  x0 = _mm_load_ss((const float *)(u32)(EBP - 12));  // @96_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ebx + eax*4)));  // @97_451560
  x2 = _mm_add_ss(x2, x0);  // @98_451560
  x0 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 8));  // @99_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 16)));  // @100_451560
  eax = (u32)(esi + ecx);  // @101_451560
  eax = (u32)(eax + eax*2);  // @102_451560
  x2 = _mm_add_ss(x2, x0);  // @103_451560
  x0 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @104_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ebx + eax*4)));  // @105_451560
  x2 = _mm_sub_ss(x2, x1);  // @106_451560
  x2 = _mm_mul_ss(x2, x6);  // @107_451560
  x2 = _mm_add_ss(x2, x1);  // @108_451560
  x1 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 4));  // @109_451560
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(EBP - 8)));  // @110_451560
  x1 = _mm_add_ss(x1, x0);  // @111_451560
  x0 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 8));  // @112_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 16)));  // @113_451560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @114_451560
  eax = (eax + ecx);  // @115_451560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @116_451560
  x1 = _mm_add_ss(x1, x0);  // @117_451560
  x0 = _mm_load_ss((const float *)(u32)(EBP - 12));  // @118_451560
  eax = (u32)(eax + eax*2);  // @119_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ebx + eax*4)));  // @120_451560
  x4 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 4));  // @121_451560
  x4 = _mm_mul_ss(x4, _mm_load_ss((const float *)(u32)(EBP - 8)));  // @122_451560
  x4 = _mm_add_ss(x4, x0);  // @123_451560
  x0 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 8));  // @124_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 16)));  // @125_451560
  eax = (u32)(edx + ecx);  // @126_451560
  eax = (u32)(eax + eax*2);  // @127_451560
  x4 = _mm_add_ss(x4, x0);  // @128_451560
  x0 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @129_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ebx + eax*4)));  // @130_451560
  x4 = _mm_sub_ss(x4, x1);  // @131_451560
  x4 = _mm_mul_ss(x4, x6);  // @132_451560
  x4 = _mm_add_ss(x4, x1);  // @133_451560
  x1 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 4));  // @134_451560
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(EBP - 44)));  // @135_451560
  x1 = _mm_add_ss(x1, x0);  // @136_451560
  x0 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 8));  // @137_451560
  x0 = _mm_mul_ss(x0, x3);  // @138_451560
  eax = (u32)(edi + ecx);  // @139_451560
  eax = (u32)(eax + eax*2);  // @140_451560
  x3 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 4));  // @141_451560
  x4 = _mm_sub_ss(x4, x2);  // @142_451560
  x3 = _mm_mul_ss(x3, _mm_load_ss((const float *)(u32)(EBP - 44)));  // @143_451560
  x1 = _mm_add_ss(x1, x0);  // @144_451560
  x0 = _mm_load_ss((const float *)(u32)(EBP - 12));  // @145_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ebx + eax*4)));  // @146_451560
  x4 = _mm_mul_ss(x4, x5);  // @147_451560
  x3 = _mm_add_ss(x3, x0);  // @148_451560
  x0 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 8));  // @149_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 24)));  // @150_451560
  eax = (u32)(esi + ecx);  // @151_451560
  eax = (u32)(eax + eax*2);  // @152_451560
  x4 = _mm_add_ss(x4, x2);  // @153_451560
  x3 = _mm_add_ss(x3, x0);  // @154_451560
  x0 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @155_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ebx + eax*4)));  // @156_451560
  x3 = _mm_sub_ss(x3, x1);  // @157_451560
  x3 = _mm_mul_ss(x3, x6);  // @158_451560
  x3 = _mm_add_ss(x3, x1);  // @159_451560
  x1 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 4));  // @160_451560
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(EBP - 8)));  // @161_451560
  x1 = _mm_add_ss(x1, x0);  // @162_451560
  x0 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 8));  // @163_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 24)));  // @164_451560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @165_451560
  x1 = _mm_add_ss(x1, x0);  // @166_451560
  x0 = _mm_load_ss((const float *)(u32)(EBP - 12));  // @167_451560
  eax = (eax + ecx);  // @168_451560
  eax = (u32)(eax + eax*2);  // @169_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ebx + eax*4)));  // @170_451560
  x2 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 4));  // @171_451560
  x2 = _mm_mul_ss(x2, _mm_load_ss((const float *)(u32)(EBP - 8)));  // @172_451560
  x2 = _mm_add_ss(x2, x0);  // @173_451560
  x0 = _mm_load_ss((const float *)(u32)(ebx + eax*4 + 8));  // @174_451560
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 24)));  // @175_451560
  x2 = _mm_add_ss(x2, x0);  // @176_451560
  x2 = _mm_sub_ss(x2, x1);  // @177_451560
  x2 = _mm_mul_ss(x2, x6);  // @178_451560
  x2 = _mm_add_ss(x2, x1);  // @179_451560
  x1 = _mm_load_ss((const float *)(u32)(EBP - 16));  // @180_451560
  x0 = x1;  // @181_451560
  x0 = _mm_add_ss(x0, x1);  // @182_451560
  x1 = _mm_mul_ss(x1, x1);  // @183_451560
  x2 = _mm_sub_ss(x2, x3);  // @184_451560
  x7 = _mm_sub_ss(x7, x0);  // @185_451560
  x2 = _mm_mul_ss(x2, x5);  // @186_451560
  x7 = _mm_mul_ss(x7, x1);  // @187_451560
  x2 = _mm_add_ss(x2, x3);  // @188_451560
  x2 = _mm_sub_ss(x2, x4);  // @189_451560
  x2 = _mm_mul_ss(x2, x7);  // @190_451560
  x2 = _mm_add_ss(x2, x4);  // @191_451560
  _mm_store_ss((float *)(u32)(EBP - 44), x2);  // @192_451560
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), 4); (double)v; });  // @193_451560
  __asm__ volatile("" :: "Yz"(x0));  // @194_451560
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @195_451560
  return eax;  // @196_451560
}
PCREG(451560, lifted_451560);

extern "C" u32 THISCALL lifted_656510(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_656510
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @1_656510
  ecx = edx = 0;  // @2_656510
  edx = eax;  // @3_656510
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @4_656510
  if (eax > (u32)(3)) goto L656562;  // @5_656510
  switch (eax) { case 0: goto L65652d; case 1: goto L65652d; case 2: goto L65652d; case 3: goto L65655b; default: __builtin_trap(); }  // @6_656510
  L65652d:;
  x1 = _mm_load_ss((const float *)(u32)(edx + 28));  // @8_656510
  x0 = _mm_setzero_ps();  // @9_656510
  x1 = _mm_sub_ss(x1, _mm_load_ss((const float *)(u32)(EBP + 12)));  // @10_656510
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(edx + 32)));  // @11_656510
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @12_656510
  if (fa_ > fb_) goto L656550;  // @13_656510
  x0 = _mm_load_ss((const float *)(u32)(6785112));  // @14_656510
  x0 = _mm_min_ss(x0, x1);  // @15_656510
  L656550:;
  x1 = _mm_load_ss((const float *)(u32)(edx + 20));  // @17_656510
  x1 = _mm_mul_ss(x1, x0);  // @18_656510
  goto L656567;  // @19_656510
  L65655b:;
  x1 = _mm_load_ss((const float *)(u32)(edx + 20));  // @21_656510
  goto L656567;  // @22_656510
  L656562:;
  x1 = _mm_load_ss((const float *)(u32)(EBP + 12));  // @24_656510
  L656567:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 18), sizeof v); (u32)v; });  // @26_656510
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @27_656510
  ecx = (ecx + eax);  // @28_656510
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 17), sizeof v); (u32)v; });  // @29_656510
  ecx = (ecx + eax);  // @30_656510
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ecx));  // @31_656510
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @32_656510
  ecx = (ecx >> (u32)(31));  // @33_656510
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(ecx*8 + 6818464))));  // @34_656510
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @35_656510
  x0 = _mm_mul_ss(x0, x1);  // @36_656510
  _mm_store_ss((float *)(u32)(EBP + 12), x0);  // @37_656510
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), 4); (double)v; });  // @38_656510
  __asm__ volatile("" :: "Yz"(x0));  // @39_656510
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @40_656510
  return eax;  // @41_656510
}
PCREG(656510, lifted_656510);

extern "C" u32 THISCALL lifted_4668d0(u32 ecx_in) {
  SEH_ENTER(0x666eeb);  // @h_4668d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4668d0
  ecx = (u32)(EBP - 16596);  // @1_4668d0
  eax = ext_4d2280_thiscall1(ecx);  // @2_4668d0
  ecx = edx = 0;  // @3_4668d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @4_4668d0
  reg.state = (s32)((u32)(0));  // @5_4668d0
  eax = ext_4db2f0_thiscall2(ecx, (u32)(0));  // @6_4668d0
  ecx = edx = 0;  // @7_4668d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_4668d0
  esi = eax;  // @9_4668d0
  eax = (u32)(EBP - 16596);  // @10_4668d0
  p0_ = eax;  // @11_4668d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @12_4668d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_4668d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4668d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 276)))(ecx, (u32)(6840152), (u32)(0), (u32)(6840032), (u32)(585), (u32)(p0_), (u32)(0));  // @15_4668d0
  ecx = edx = 0;  // @16_4668d0
  eax = (eax & 0xffff);  // @17_4668d0
  ecx = esi;  // @18_4668d0
  p1_ = eax;  // @19_4668d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 296)))(ecx, (u32)(p1_));  // @20_4668d0
  ecx = edx = 0;  // @21_4668d0
  eax = (u32)(EBP - 16600);  // @22_4668d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16600), &v, sizeof v); }  // @23_4668d0
  p2_ = eax;  // @24_4668d0
  ecx = (u32)(EBP - 16596);  // @25_4668d0
  eax = ext_4d2d30_thiscall3(ecx, (u32)(6840164), (u32)(p2_));  // @26_4668d0
  ecx = edx = 0;  // @27_4668d0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 16600));  // @28_4668d0
  ecx = (u32)(EBP - 16596);  // @29_4668d0
  _mm_store_ss((float *)(u32)(EBP - 16604), x0);  // @30_4668d0
  eax = ext_4d2330_thiscall1(ecx);  // @31_4668d0
  ecx = edx = 0;  // @32_4668d0
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), 4); (double)v; });  // @33_4668d0
  SEH_LEAVE();  // @34_4668d0
  ext_633654(G(u32, 0x6f5630));  // @35_4668d0
  __asm__ volatile("" :: "Yz"(x0));  // @36_4668d0
  __asm__ volatile("fldl %0" :: "m"(T[0]));  // @37_4668d0
  return eax;  // @38_4668d0
}
PCREG(4668d0, lifted_4668d0);

