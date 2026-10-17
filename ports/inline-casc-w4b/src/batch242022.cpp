// batch242022.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }
extern "C" u32 THISCALL ext_40fa80_thiscall1(u32) __asm__("ext_40fa80");
extern "C" u32 ext_405090_cdecl1(...) __asm__("ext_405090");
extern "C" u32 ext_405ee0_cdecl3(...) __asm__("ext_405ee0");
extern "C" u32 ext_4067b0_cdecl3(...) __asm__("ext_4067b0");
extern "C" u32 ext_406cc0_cdecl1(...) __asm__("ext_406cc0");
extern "C" u32 ext_4071d0_cdecl4(...) __asm__("ext_4071d0");
extern "C" u32 ext_40c780_cdecl3(...) __asm__("ext_40c780");
extern "C" u32 ext_40cc20_cdecl4(...) __asm__("ext_40cc20");
extern "C" u32 ext_40ce50_cdecl14(...) __asm__("ext_40ce50");
extern "C" u32 ext_40ce50_cdecl6(...) __asm__("ext_40ce50");
extern "C" u32 ext_40fc00_cdecl3(...) __asm__("ext_40fc00");
extern "C" u32 ext_40fe00_cdecl2(...) __asm__("ext_40fe00");
extern "C" u32 ext_40fe70_cdecl3(...) __asm__("ext_40fe70");
extern "C" u32 ext_410000_cdecl3(...) __asm__("ext_410000");
extern "C" u32 ext_410bf0_cdecl3(...) __asm__("ext_410bf0");
extern "C" u32 ext_634dca_cdecl0(void) __asm__("ext_634dca");
extern "C" double ext_634dca_dbl(double) __asm__("ext_634dca");
extern "C" u32 ext_40fa80_cdecl8(...) __asm__("ext_40fa80");
extern "C" u32 ext_634dd0_cdecl4(...) __asm__("ext_634dd0");
extern "C" u32 ext_634dfa_cdecl0(void) __asm__("ext_634dfa");
extern "C" u32 ext_634e0c_cdecl0(void) __asm__("ext_634e0c");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_4072f0(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4072f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1_4072f0
  esi = eax;  // @2_4072f0
  ebx = eax;  // @3_4072f0
  edi = eax;  // @4_4072f0
  eax = (eax << (u32)(2));  // @5_4072f0
  FL[3] = eax;  // @6_4072f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @7_4072f0
  eax = (eax + (u32)(3));  // @8_4072f0
  FL[3] = eax;  // @9_4072f0
  ebx = (u32)((s32)ebx >> (u32)(2));  // @10_4072f0
  FL[3] = ebx;  // @11_4072f0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @12_4072f0
  FL[3] = (eax & 0xff);  // @13_4072f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @14_4072f0
  esi = (u32)((s32)esi >> (u32)(1));  // @15_4072f0
  FL[3] = esi;  // @16_4072f0
  edi = (u32)((s32)edi >> (u32)(3));  // @17_4072f0
  FL[3] = edi;  // @18_4072f0
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @19_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @20_4072f0
  ecx = ALLOC_PTR;  // @21_4072f0
  eax = (u32)(esi*4);  // @22_4072f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @23_4072f0
  ecx = (ecx + eax);  // @24_4072f0
  FL[3] = ecx;  // @25_4072f0
  ebx = (ebx + esi);  // @26_4072f0
  FL[3] = ebx;  // @27_4072f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @28_4072f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @29_4072f0
  ecx = (u32)(edx + ebx*4);  // @30_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @31_4072f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @32_4072f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }));  // @33_4072f0
  FL[3] = eax;  // @34_4072f0
  ebx = (u32)(ecx + 4);  // @35_4072f0
  FL[2] = (edi & edi);  // @36_4072f0
  if ((s32)FL[2] <= 0) goto L4073a1;  // @37_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @38_4072f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @39_4072f0
  edx = (u32)(edi + 1);  // @40_4072f0
  edx = (edx >> (u32)(1));  // @41_4072f0
  FL[3] = edx;  // @42_4072f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @43_4072f0
  edx = (edx + edx);  // @44_4072f0
  FL[3] = edx;  // @45_4072f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @46_4072f0
  L407362:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 8)) : "st");  // @48_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @49_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx + 8)) : "st");  // @50_4072f0
  ecx = (ecx - (u32)(16));  // @51_4072f0
  FL[3] = ecx;  // @52_4072f0
  eax = (eax - (u32)(8));  // @53_4072f0
  FL[3] = eax;  // @54_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @55_4072f0
  ebx = (ebx + (u32)(16));  // @56_4072f0
  FL[3] = ebx;  // @57_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @58_4072f0
  edx = (edx + (u32)(8));  // @59_4072f0
  FL[3] = edx;  // @60_4072f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @61_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @62_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @63_4072f0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @64_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @65_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @66_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 8)) :: "st");  // @67_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @68_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @69_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @70_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @71_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 4)) :: "st");  // @72_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @73_4072f0
  edx = (edx - 1);  // @74_4072f0
  FL[3] = edx;  // @75_4072f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @76_4072f0
  if (FL[3] != 0) goto L407362;  // @77_4072f0
  L4073a1:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @79_4072f0
  ebx = esi;  // @80_4072f0
  ebx = (ebx - edi);  // @81_4072f0
  FL[3] = ebx;  // @82_4072f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @83_4072f0
  edx = (edx + (u32)(4));  // @84_4072f0
  FL[3] = edx;  // @85_4072f0
  FL[0] = edi; FL[1] = ebx;  // @86_4072f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @87_4072f0
  if ((s32)FL[0] >= (s32)FL[1]) goto L407403;  // @88_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @89_4072f0
  ebx = (u32)(ebx + edi*4);  // @90_4072f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @91_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @92_4072f0
  ebx = (ebx - edi);  // @93_4072f0
  FL[3] = ebx;  // @94_4072f0
  ebx = (ebx + 1);  // @95_4072f0
  FL[3] = ebx;  // @96_4072f0
  ebx = (ebx >> (u32)(1));  // @97_4072f0
  FL[3] = ebx;  // @98_4072f0
  edi = (u32)(edi + ebx*2);  // @99_4072f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @100_4072f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @101_4072f0
  L4073cf:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 8)) : "st");  // @103_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @104_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 16)) : "st");  // @105_4072f0
  ecx = (ecx - (u32)(16));  // @106_4072f0
  FL[3] = ecx;  // @107_4072f0
  eax = (eax - (u32)(8));  // @108_4072f0
  FL[3] = eax;  // @109_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edx + 8)) : "st");  // @110_4072f0
  edx = (edx + (u32)(16));  // @111_4072f0
  FL[3] = edx;  // @112_4072f0
  edi = (edi + (u32)(8));  // @113_4072f0
  FL[3] = edi;  // @114_4072f0
  ebx = (ebx - 1);  // @115_4072f0
  FL[3] = ebx;  // @116_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @117_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @118_4072f0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @119_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @120_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @121_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi - 8)) :: "st");  // @122_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @123_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @124_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @125_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @126_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi - 4)) :: "st");  // @127_4072f0
  if (FL[3] != 0) goto L4073cf;  // @128_4072f0
  L407403:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @130_4072f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @131_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @132_4072f0
  edi = (edi + ecx);  // @133_4072f0
  FL[3] = edi;  // @134_4072f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @135_4072f0
  FL[0] = ecx; FL[1] = esi;  // @136_4072f0
  if ((s32)FL[0] >= (s32)FL[1]) goto L40745a;  // @137_4072f0
  ecx = (u32)(ebx + ecx*4);  // @138_4072f0
  ebx = esi;  // @139_4072f0
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }));  // @140_4072f0
  FL[3] = ebx;  // @141_4072f0
  ebx = (ebx + 1);  // @142_4072f0
  FL[3] = ebx;  // @143_4072f0
  ebx = (ebx >> (u32)(1));  // @144_4072f0
  FL[3] = ebx;  // @145_4072f0
  L407420:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi - 8)) : "st");  // @147_4072f0
  edi = (edi - (u32)(16));  // @148_4072f0
  FL[3] = edi;  // @149_4072f0
  eax = (eax - (u32)(8));  // @150_4072f0
  FL[3] = eax;  // @151_4072f0
  __asm__ volatile("fchs" ::: "st");  // @152_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @153_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @154_4072f0
  __asm__ volatile("fchs" ::: "st");  // @155_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edx + 8)) : "st");  // @156_4072f0
  edx = (edx + (u32)(16));  // @157_4072f0
  FL[3] = edx;  // @158_4072f0
  ecx = (ecx + (u32)(8));  // @159_4072f0
  FL[3] = ecx;  // @160_4072f0
  ebx = (ebx - 1);  // @161_4072f0
  FL[3] = ebx;  // @162_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @163_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @164_4072f0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @165_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @166_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @167_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 8)) :: "st");  // @168_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @169_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @170_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @171_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @172_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 4)) :: "st");  // @173_4072f0
  if (FL[3] != 0) goto L407420;  // @174_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @175_4072f0
  L40745a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @177_4072f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @178_4072f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @179_4072f0
  eax = (eax - (u32)(6));  // @180_4072f0
  FL[3] = eax;  // @181_4072f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @182_4072f0
  FL[2] = (eax & eax);  // @183_4072f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @184_4072f0
  if ((s32)FL[2] <= 0) goto L40757f;  // @185_4072f0
  ecx = esi;  // @186_4072f0
  edx = (u32)(edi + 16);  // @187_4072f0
  ecx = (u32)((s32)ecx >> (u32)(1));  // @188_4072f0
  FL[3] = ecx;  // @189_4072f0
  edi = esi;  // @190_4072f0
  eax = (u32)(ebx + ecx*4 - 32);  // @191_4072f0
  edi = (edi - ecx);  // @192_4072f0
  FL[3] = edi;  // @193_4072f0
  ecx = (u32)(eax + edi*4 + 28);  // @194_4072f0
  L407487:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @196_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + 24)) : "st");  // @197_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @198_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + 28)) : "st");  // @199_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 24)) : "st");  // @200_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @201_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 4)) :: "st");  // @202_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 28)) : "st");  // @203_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @204_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @205_4072f0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @206_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx - 16)) : "st");  // @207_4072f0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @208_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx - 12)) : "st");  // @209_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @210_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 24)) :: "st");  // @211_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx - 16)) : "st");  // @212_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @213_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx - 12)) : "st");  // @214_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @215_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 28)) :: "st");  // @216_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 12)) : "st");  // @217_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + 16)) : "st");  // @218_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 8)) : "st");  // @219_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + 20)) : "st");  // @220_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 16)) : "st");  // @221_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx - 12)) : "st");  // @222_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 12)) :: "st");  // @223_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 8)) : "st");  // @224_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax + 20)) : "st");  // @225_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 8)) :: "st");  // @226_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @227_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx + 4)) : "st");  // @228_4072f0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @229_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @230_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @231_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 16)) :: "st");  // @232_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @233_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @234_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx + 4)) : "st");  // @235_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @236_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 20)) :: "st");  // @237_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 20)) : "st");  // @238_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @239_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 16)) : "st");  // @240_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + 12)) : "st");  // @241_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @242_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx - 20)) : "st");  // @243_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 20)) :: "st");  // @244_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 12)) : "st");  // @245_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx - 16)) : "st");  // @246_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 16)) :: "st");  // @247_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @248_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx + 20)) : "st");  // @249_4072f0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @250_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx + 16)) : "st");  // @251_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @252_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 8)) :: "st");  // @253_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx + 16)) : "st");  // @254_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @255_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx + 20)) : "st");  // @256_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @257_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 12)) :: "st");  // @258_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 28)) : "st");  // @259_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @260_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 24)) : "st");  // @261_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @262_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 28)) : "st");  // @263_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @264_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 28)) :: "st");  // @265_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @266_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx - 24)) : "st");  // @267_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 24)) :: "st");  // @268_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @269_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx + 36)) : "st");  // @270_4072f0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @271_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx + 32)) : "st");  // @272_4072f0
  eax = (eax - (u32)(32));  // @273_4072f0
  FL[3] = eax;  // @274_4072f0
  ecx = (ecx - (u32)(32));  // @275_4072f0
  FL[3] = ecx;  // @276_4072f0
  edx = (edx + (u32)(64));  // @277_4072f0
  FL[3] = edx;  // @278_4072f0
  FL[0] = eax; FL[1] = ebx;  // @279_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @280_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 32)) :: "st");  // @281_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx - 32)) : "st");  // @282_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @283_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edx - 28)) : "st");  // @284_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @285_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 36)) :: "st");  // @286_4072f0
  if (FL[0] >= FL[1]) goto L407487;  // @287_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @288_4072f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @289_4072f0
  L40757f:;
  eax = (eax - 1);  // @291_4072f0
  FL[3] = eax;  // @292_4072f0
  ecx = (u32)(1);  // @293_4072f0
  FL[2] = (eax & eax);  // @294_4072f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @295_4072f0
  if ((s32)FL[2] <= 0) goto L4075e7;  // @296_4072f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @297_4072f0
  L40758f:;
  edx = (u32)(1);  // @299_4072f0
  edx = (edx << (ecx & 0xff));  // @300_4072f0
  FL[3] = edx;  // @301_4072f0
  FL[2] = (edx & edx);  // @302_4072f0
  if ((s32)FL[2] <= 0) goto L4075d7;  // @303_4072f0
  eax = (u32)(4);  // @304_4072f0
  edi = esi;  // @305_4072f0
  eax = (eax << (ecx & 0xff));  // @306_4072f0
  FL[3] = eax;  // @307_4072f0
  edi = (u32)((s32)edi >> (ecx & 0xff));  // @308_4072f0
  FL[3] = edi;  // @309_4072f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @310_4072f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @311_4072f0
  goto L4075b0;  // @312_4072f0
  L4075ad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @314_4072f0
  L4075b0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @316_4072f0
  PV[0] = (u32)(eax);  // @317_4072f0
  PV[1] = (u32)(edi);  // @318_4072f0
  PV[2] = (u32)(ebx);  // @319_4072f0
  PV[3] = (u32)(edx);  // @320_4072f0
  eax = ext_4071d0_cdecl4(PV[3], PV[2], PV[1], PV[0]);  // @321_4072f0
  ecx = edx = 0;  // @322_4072f0
  eax = (u32)(edi*4);  // @323_4072f0
  ebx = (ebx + eax);  // @324_4072f0
  FL[3] = ebx;  // @325_4072f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @326_4072f0
  eax = (eax - 1);  // @327_4072f0
  FL[3] = eax;  // @328_4072f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @329_4072f0
  if (FL[3] != 0) goto L4075ad;  // @330_4072f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @331_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @332_4072f0
  L4075d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @334_4072f0
  ecx = (ecx + 1);  // @335_4072f0
  FL[3] = ecx;  // @336_4072f0
  eax = (eax - 1);  // @337_4072f0
  FL[3] = eax;  // @338_4072f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @339_4072f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @340_4072f0
  if (FL[3] != 0) goto L40758f;  // @341_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @342_4072f0
  L4075e7:;
  FL[2] = (esi & esi);  // @344_4072f0
  if ((s32)FL[2] <= 0) goto L407606;  // @345_4072f0
  esi = (esi + (u32)(31));  // @346_4072f0
  FL[3] = esi;  // @347_4072f0
  esi = (esi >> (u32)(5));  // @348_4072f0
  FL[3] = esi;  // @349_4072f0
  L4075f1:;
  PV[4] = (u32)(ebx);  // @351_4072f0
  eax = ext_406cc0_cdecl1(PV[4]);  // @352_4072f0
  ecx = edx = 0;  // @353_4072f0
  ebx = (ebx + (u32)(128));  // @354_4072f0
  FL[3] = ebx;  // @355_4072f0
  esi = (esi - 1);  // @356_4072f0
  FL[3] = esi;  // @357_4072f0
  if (FL[3] != 0) goto L4075f1;  // @358_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @359_4072f0
  L407606:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @361_4072f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @362_4072f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @363_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @364_4072f0
  edi = eax;  // @365_4072f0
  edi = (u32)((s32)edi >> (u32)(1));  // @366_4072f0
  FL[3] = edi;  // @367_4072f0
  eax = (u32)(edx + eax*4);  // @368_4072f0
  edx = (u32)(ecx + 8);  // @369_4072f0
  edi = (u32)(ecx + edi*4);  // @370_4072f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @371_4072f0
  ecx = (u32)(edi + 12);  // @372_4072f0
  goto L407629;  // @373_4072f0
  L407626:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @375_4072f0
  L407629:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @377_4072f0
  ecx = (ecx - (u32)(16));  // @378_4072f0
  FL[3] = ecx;  // @379_4072f0
  ebx = (u32)(edi + ebx*4);  // @380_4072f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @381_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @382_4072f0
  edi = (u32)(edi + ebx*4);  // @383_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @384_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx + 4)) : "st");  // @385_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edi + 4)) : "st");  // @386_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @387_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @388_4072f0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @389_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @390_4072f0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @391_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @392_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @393_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 12)) :: "st");  // @394_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @395_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @396_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @397_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @398_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi + 4)) : "st");  // @399_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebx + 4)) : "st");  // @400_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7069692)) : "st");  // @401_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @402_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @403_4072f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @404_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7069692)) : "st");  // @405_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 8)) :: "st");  // @406_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 12)) : "st");  // @407_4072f0
  __asm__ volatile(".byte 0xd8, 0xc1" ::: "st");  // @408_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 8)) :: "st");  // @409_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(EBP + 12)) : "st");  // @410_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 4)) :: "st");  // @411_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @412_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(EBP - 8)) : "st");  // @413_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 4)) :: "st");  // @414_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(EBP - 8)) : "st");  // @415_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @416_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @417_4072f0
  ebx = (u32)(edi + ebx*4);  // @418_4072f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @419_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @420_4072f0
  edi = (u32)(edi + ebx*4);  // @421_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @422_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx + 4)) : "st");  // @423_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edi + 4)) : "st");  // @424_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @425_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @426_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @427_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @428_4072f0
  __asm__ volatile(".byte 0xd9, 0xc2" ::: "st");  // @429_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 12)) : "st");  // @430_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @431_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 12)) :: "st");  // @432_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 12)) : "st");  // @433_4072f0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @434_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @435_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @436_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edi + 4)) : "st");  // @437_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebx + 4)) : "st");  // @438_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7069692)) : "st");  // @439_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @440_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edi)) : "st");  // @441_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7069692)) : "st");  // @442_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 8)) :: "st");  // @443_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 12)) : "st");  // @444_4072f0
  __asm__ volatile(".byte 0xd8, 0xc1" ::: "st");  // @445_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx)) :: "st");  // @446_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(EBP + 12)) : "st");  // @447_4072f0
  edx = (edx + (u32)(16));  // @448_4072f0
  FL[3] = edx;  // @449_4072f0
  edi = (u32)(ecx - 12);  // @450_4072f0
  eax = (eax + (u32)(16));  // @451_4072f0
  FL[3] = eax;  // @452_4072f0
  esi = (esi + (u32)(16));  // @453_4072f0
  FL[3] = esi;  // @454_4072f0
  ebx = (u32)(edx - 8);  // @455_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 12)) :: "st");  // @456_4072f0
  FL[0] = ebx; FL[1] = edi;  // @457_4072f0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @458_4072f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(EBP - 8)) : "st");  // @459_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx - 12)) :: "st");  // @460_4072f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(EBP - 8)) : "st");  // @461_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx - 8)) :: "st");  // @462_4072f0
  if (FL[0] < FL[1]) goto L407626;  // @463_4072f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @464_4072f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @465_4072f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @466_4072f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @467_4072f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @468_4072f0
  eax = ecx;  // @469_4072f0
  eax = (eax + edx);  // @470_4072f0
  FL[3] = eax;  // @471_4072f0
  edx = (u32)(ecx + esi);  // @472_4072f0
  FL[2] = (ebx & ebx);  // @473_4072f0
  if ((s32)FL[2] <= 0) goto L407766;  // @474_4072f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @475_4072f0
  L407732:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @477_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @478_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @479_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @480_4072f0
  edx = (edx - (u32)(4));  // @481_4072f0
  FL[3] = edx;  // @482_4072f0
  ecx = (ecx + (u32)(8));  // @483_4072f0
  FL[3] = ecx;  // @484_4072f0
  eax = (eax + (u32)(8));  // @485_4072f0
  FL[3] = eax;  // @486_4072f0
  esi = (esi + (u32)(4));  // @487_4072f0
  FL[3] = esi;  // @488_4072f0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @489_4072f0
  ebx = (ebx - 1);  // @490_4072f0
  FL[3] = ebx;  // @491_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edi + 16)) : "st");  // @492_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi - 4)) :: "st");  // @493_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @494_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx - 8)) : "st");  // @495_4072f0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax - 8)) : "st");  // @496_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @497_4072f0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @498_4072f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edi + 16)) : "st");  // @499_4072f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx)) :: "st");  // @500_4072f0
  if (FL[3] != 0) goto L407732;  // @501_4072f0
  L407766:;
  return eax;  // @503_4072f0
}
PCREG(4072f0, lifted_4072f0);

extern "C" u32 lifted_40fc00(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_40fc00
  esi = (u32)(ebx + 1);  // @1_40fc00
  esi = (u32)((s32)esi >> (u32)(1));  // @2_40fc00
  FL[3] = esi;  // @3_40fc00
  edi = (u32)(esi*4 + 4);  // @4_40fc00
  eax = edi;  // @5_40fc00
  eax = (eax + (u32)(3));  // @6_40fc00
  FL[3] = eax;  // @7_40fc00
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @8_40fc00
  FL[3] = (eax & 0xff);  // @9_40fc00
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @10_40fc00
  eax = edi;  // @11_40fc00
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @12_40fc00
  eax = (eax + (u32)(3));  // @13_40fc00
  FL[3] = eax;  // @14_40fc00
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @15_40fc00
  FL[3] = (eax & 0xff);  // @16_40fc00
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @17_40fc00
  eax = edi;  // @18_40fc00
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @19_40fc00
  eax = (eax + (u32)(3));  // @20_40fc00
  FL[3] = eax;  // @21_40fc00
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @22_40fc00
  FL[3] = (eax & 0xff);  // @23_40fc00
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @24_40fc00
  eax = edi;  // @25_40fc00
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @26_40fc00
  eax = (eax + (u32)(3));  // @27_40fc00
  FL[3] = eax;  // @28_40fc00
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @29_40fc00
  FL[3] = (eax & 0xff);  // @30_40fc00
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @31_40fc00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @32_40fc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_40fc00
  edi = ebx;  // @34_40fc00
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @35_40fc00
  edi = (u32)((s32)edi >> (u32)(1));  // @36_40fc00
  FL[3] = edi;  // @37_40fc00
  FL[0] = esi; FL[1] = (u32)(1);  // @38_40fc00
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edx + esi*4), &v, sizeof v); }  // @39_40fc00
  if ((s32)FL[0] < (s32)FL[1]) goto L40fc9f;  // @40_40fc00
  edx = (u32)(edx + esi*4 - 4);  // @41_40fc00
  ecx = eax;  // @42_40fc00
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @43_40fc00
  eax = (u32)(eax + ebx*4 - 4);  // @44_40fc00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @45_40fc00
  L40fc7a:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @47_40fc00
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @48_40fc00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @49_40fc00
  ecx = (ecx + (u32)(4));  // @50_40fc00
  FL[3] = ecx;  // @51_40fc00
  edx = (edx - (u32)(4));  // @52_40fc00
  FL[3] = edx;  // @53_40fc00
  eax = (eax - (u32)(4));  // @54_40fc00
  FL[3] = eax;  // @55_40fc00
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @56_40fc00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + 4)) :: "st");  // @57_40fc00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @58_40fc00
  edx = (edx - 1);  // @59_40fc00
  FL[3] = edx;  // @60_40fc00
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @61_40fc00
  if (FL[3] != 0) goto L40fc7a;  // @62_40fc00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @63_40fc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @64_40fc00
  L40fc9f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @66_40fc00
  FL[0] = edi; FL[1] = (u32)(1);  // @67_40fc00
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ecx + edi*4), &v, sizeof v); }  // @68_40fc00
  if ((s32)FL[0] < (s32)FL[1]) goto L40fcd1;  // @69_40fc00
  ecx = (u32)(ecx + edi*4 - 4);  // @70_40fc00
  ebx = (u32)(eax + ebx*4 - 4);  // @71_40fc00
  edx = edi;  // @72_40fc00
  L40fcb8:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @74_40fc00
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @75_40fc00
  eax = (eax + (u32)(4));  // @76_40fc00
  FL[3] = eax;  // @77_40fc00
  ebx = (ebx - (u32)(4));  // @78_40fc00
  FL[3] = ebx;  // @79_40fc00
  ecx = (ecx - (u32)(4));  // @80_40fc00
  FL[3] = ecx;  // @81_40fc00
  edx = (edx - 1);  // @82_40fc00
  FL[3] = edx;  // @83_40fc00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @84_40fc00
  if (FL[3] != 0) goto L40fcb8;  // @85_40fc00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @86_40fc00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @87_40fc00
  L40fcd1:;
  FL[0] = esi; FL[1] = edi;  // @89_40fc00
  if ((s32)FL[0] <= (s32)FL[1]) goto L40fcf1;  // @90_40fc00
  FL[0] = edi; FL[1] = (u32)(2);  // @91_40fc00
  if ((s32)FL[0] < (s32)FL[1]) goto L40fd23;  // @92_40fc00
  eax = (u32)(ecx + edi*4 - 8);  // @93_40fc00
  ecx = (u32)(edi - 1);  // @94_40fc00
  L40fce1:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 8)) : "st");  // @96_40fc00
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @97_40fc00
  eax = (eax - (u32)(4));  // @98_40fc00
  FL[3] = eax;  // @99_40fc00
  ecx = (ecx - 1);  // @100_40fc00
  FL[3] = ecx;  // @101_40fc00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 4)) :: "st");  // @102_40fc00
  if (FL[3] != 0) goto L40fce1;  // @103_40fc00
  goto L40fd23;  // @104_40fc00
  L40fcf1:;
  FL[0] = esi; FL[1] = (u32)(1);  // @106_40fc00
  if ((s32)FL[0] < (s32)FL[1]) goto L40fd0a;  // @107_40fc00
  eax = (u32)(edx + esi*4 - 4);  // @108_40fc00
  ebx = esi;  // @109_40fc00
  L40fcfc:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @111_40fc00
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @112_40fc00
  eax = (eax - (u32)(4));  // @113_40fc00
  FL[3] = eax;  // @114_40fc00
  ebx = (ebx - 1);  // @115_40fc00
  FL[3] = ebx;  // @116_40fc00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 4)) :: "st");  // @117_40fc00
  if (FL[3] != 0) goto L40fcfc;  // @118_40fc00
  L40fd0a:;
  FL[0] = edi; FL[1] = (u32)(1);  // @120_40fc00
  if ((s32)FL[0] < (s32)FL[1]) goto L40fd23;  // @121_40fc00
  eax = (u32)(ecx + edi*4 - 4);  // @122_40fc00
  ecx = edi;  // @123_40fc00
  L40fd15:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(eax + 4)) : "st");  // @125_40fc00
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @126_40fc00
  eax = (eax - (u32)(4));  // @127_40fc00
  FL[3] = eax;  // @128_40fc00
  ecx = (ecx - 1);  // @129_40fc00
  FL[3] = ecx;  // @130_40fc00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax + 4)) :: "st");  // @131_40fc00
  if (FL[3] != 0) goto L40fd15;  // @132_40fc00
  L40fd23:;
  PV[0] = (u32)(esi);  // @134_40fc00
  PV[1] = (u32)(edx);  // @135_40fc00
  eax = ext_40fe00_cdecl2(PV[1], PV[0]);  // @136_40fc00
  ecx = edx = 0;  // @137_40fc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @138_40fc00
  PV[2] = (u32)(edi);  // @139_40fc00
  PV[3] = (u32)(eax);  // @140_40fc00
  eax = ext_40fe00_cdecl2(PV[3], PV[2]);  // @141_40fc00
  ecx = edx = 0;  // @142_40fc00
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @143_40fc00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @144_40fc00
  PV[4] = (u32)(ebx);  // @145_40fc00
  PV[5] = (u32)(esi);  // @146_40fc00
  PV[6] = (u32)(ecx);  // @147_40fc00
  eax = ext_40fe70_cdecl3(PV[6], PV[5], PV[4]);  // @148_40fc00
  ecx = edx = 0;  // @149_40fc00
  FL[2] = (eax & eax);  // @150_40fc00
  if (FL[2] != 0) goto L40fdee;  // @151_40fc00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @152_40fc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @153_40fc00
  PV[7] = (u32)(edx);  // @154_40fc00
  PV[8] = (u32)(edi);  // @155_40fc00
  PV[9] = (u32)(eax);  // @156_40fc00
  eax = ext_40fe70_cdecl3(PV[9], PV[8], PV[7]);  // @157_40fc00
  ecx = edx = 0;  // @158_40fc00
  FL[2] = (eax & eax);  // @159_40fc00
  if (FL[2] != 0) goto L40fdee;  // @160_40fc00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @161_40fc00
  PV[10] = (u32)(ebx);  // @162_40fc00
  PV[11] = (u32)(esi);  // @163_40fc00
  PV[12] = (u32)(ecx);  // @164_40fc00
  eax = ext_410000_cdecl3(PV[12], PV[11], PV[10]);  // @165_40fc00
  ecx = edx = 0;  // @166_40fc00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @167_40fc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @168_40fc00
  PV[13] = (u32)(edx);  // @169_40fc00
  PV[14] = (u32)(edi);  // @170_40fc00
  PV[15] = (u32)(eax);  // @171_40fc00
  eax = ext_410000_cdecl3(PV[15], PV[14], PV[13]);  // @172_40fc00
  ecx = edx = 0;  // @173_40fc00
  PV[16] = (u32)(esi);  // @174_40fc00
  PV[17] = (u32)(ebx);  // @175_40fc00
  eax = ext_634dd0_cdecl4(PV[17], PV[16], (u32)(4), (u32)(4259408));  // @176_40fc00
    // @177_40fc00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @178_40fc00
  PV[18] = (u32)(edi);  // @179_40fc00
  PV[19] = (u32)(ecx);  // @180_40fc00
  eax = ext_634dd0_cdecl4(PV[19], PV[18], (u32)(4), (u32)(4259408));  // @181_40fc00
    // @182_40fc00
  FL[2] = (esi & esi);  // @183_40fc00
  if ((s32)FL[2] <= 0) goto L40fdc3;  // @184_40fc00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @185_40fc00
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @186_40fc00
  L40fdab:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @188_40fc00
  eax = ext_634e0c_cdecl0();  // @189_40fc00
    // @190_40fc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @191_40fc00
  ebx = (ebx + (u32)(4));  // @192_40fc00
  FL[3] = ebx;  // @193_40fc00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax)) :: "st");  // @194_40fc00
  eax = (eax + (u32)(8));  // @195_40fc00
  FL[3] = eax;  // @196_40fc00
  esi = (esi - 1);  // @197_40fc00
  FL[3] = esi;  // @198_40fc00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @199_40fc00
  if (FL[3] != 0) goto L40fdab;  // @200_40fc00
  L40fdc3:;
  FL[2] = (edi & edi);  // @202_40fc00
  if ((s32)FL[2] <= 0) goto L40fde2;  // @203_40fc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @204_40fc00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @205_40fc00
  ebx = (u32)(eax + 4);  // @206_40fc00
  L40fdd0:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @208_40fc00
  eax = ext_634e0c_cdecl0();  // @209_40fc00
    // @210_40fc00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @211_40fc00
  esi = (esi + (u32)(4));  // @212_40fc00
  FL[3] = esi;  // @213_40fc00
  ebx = (ebx + (u32)(8));  // @214_40fc00
  FL[3] = ebx;  // @215_40fc00
  edi = (edi - 1);  // @216_40fc00
  FL[3] = edi;  // @217_40fc00
  if (FL[3] != 0) goto L40fdd0;  // @218_40fc00
  L40fde2:;
  eax = 0;  // @220_40fc00
  FL[3] = eax;  // @221_40fc00
  return eax;  // @222_40fc00
  L40fdee:;
  eax = (eax | (u32)(4294967295));  // @224_40fc00
  FL[3] = eax;  // @225_40fc00
  return eax;  // @226_40fc00
}
PCREG(40fc00, lifted_40fc00);

extern "C" u32 lifted_408a40(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_408a40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @2_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @3_408a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @5_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @6_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @7_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; });  // @8_408a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @9_408a40
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @10_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @11_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx*4), sizeof v); (u32)v; });  // @12_408a40
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @13_408a40
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @14_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @15_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @16_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @17_408a40
  ecx = (u32)(ebx + ecx*2);  // @18_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @19_408a40
  ecx = (u32)(ebx + ecx*2);  // @20_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 + 4), sizeof v); (u32)v; });  // @21_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @22_408a40
  edi = (u32)(edx*4);  // @23_408a40
  eax = edi;  // @24_408a40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @25_408a40
  eax = (eax + (u32)(3));  // @26_408a40
  FL[3] = eax;  // @27_408a40
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @28_408a40
  FL[3] = (eax & 0xff);  // @29_408a40
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @30_408a40
  eax = edi;  // @31_408a40
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @32_408a40
  eax = (eax + (u32)(3));  // @33_408a40
  FL[3] = eax;  // @34_408a40
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @35_408a40
  FL[3] = (eax & 0xff);  // @36_408a40
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @37_408a40
  eax = edi;  // @38_408a40
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @39_408a40
  eax = (eax + (u32)(3));  // @40_408a40
  FL[3] = eax;  // @41_408a40
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @42_408a40
  FL[3] = (eax & 0xff);  // @43_408a40
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @44_408a40
  eax = edi;  // @45_408a40
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @46_408a40
  eax = (eax + (u32)(3));  // @47_408a40
  FL[3] = eax;  // @48_408a40
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @49_408a40
  FL[3] = (eax & 0xff);  // @50_408a40
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @51_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @52_408a40
  eax = ALLOC_PTR;  // @53_408a40
  ebx = 0;  // @54_408a40
  FL[3] = ebx;  // @55_408a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @56_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @57_408a40
  FL[2] = (ecx & ecx);  // @58_408a40
  if ((s32)FL[2] <= 0) goto L408b6c;  // @59_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @60_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @61_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @62_408a40
  edx = (edx + (u32)(4));  // @63_408a40
  FL[3] = edx;  // @64_408a40
  ecx = (ecx << (u32)(2));  // @65_408a40
  FL[3] = ecx;  // @66_408a40
  ecx = (ecx >> (u32)(1));  // @67_408a40
  FL[3] = ecx;  // @68_408a40
  eax = (eax - edi);  // @69_408a40
  FL[3] = eax;  // @70_408a40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @71_408a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @72_408a40
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @73_408a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @74_408a40
  goto L408b0b;  // @75_408a40
  L408b08:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @77_408a40
  L408b0b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @79_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @80_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @81_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @82_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @83_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; });  // @84_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4), sizeof v); (u32)v; });  // @85_408a40
  PV[0] = (u32)(eax);  // @86_408a40
  PV[1] = (u32)(esi);  // @87_408a40
  eax = ((u32( *)(u32, u32))(*(u32 *)(edx + 28)))(PV[1], PV[0]);  // @88_408a40
  ecx = edx = 0;  // @89_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @90_408a40
  edx = 0;  // @91_408a40
  FL[3] = edx;  // @92_408a40
  FL[2] = (eax & eax);  // @93_408a40
  edx = (edx & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @94_408a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edi), &v, sizeof v); }  // @95_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @96_408a40
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @97_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_408a40
  eax = 0;  // @99_408a40
  FL[3] = eax;  // @100_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx*4), sizeof v); (u32)v; });  // @101_408a40
  edx = ecx;  // @102_408a40
  ecx = (ecx >> (u32)(2));  // @103_408a40
  FL[3] = ecx;  // @104_408a40
  while (ecx) { __builtin_memcpy((void *)edi, &eax, 4); edi += 4; ecx--; }  // @105_408a40
  ecx = edx;  // @106_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @107_408a40
  ecx = (ecx & (u32)(3));  // @108_408a40
  FL[3] = ecx;  // @109_408a40
  ebx = (ebx + 1);  // @110_408a40
  FL[3] = ebx;  // @111_408a40
  while (ecx) { *(u8 *)edi = (u8)eax; edi++; ecx--; }  // @112_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @113_408a40
  eax = (u32)(4);  // @114_408a40
  edi = (edi + eax);  // @115_408a40
  FL[3] = edi;  // @116_408a40
  edx = (edx + eax);  // @117_408a40
  FL[3] = edx;  // @118_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @119_408a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @120_408a40
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @121_408a40
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @122_408a40
  if ((s32)FL[0] < (s32)FL[1]) goto L408b08;  // @123_408a40
  L408b6c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @125_408a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @126_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1228), sizeof v); (u32)v; });  // @127_408a40
  FL[2] = (eax & eax);  // @128_408a40
  if ((s32)FL[2] <= 0) goto L408bc4;  // @129_408a40
  eax = (u32)(edx + 2256);  // @130_408a40
  L408b86:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 1024), sizeof v); (u32)v; });  // @132_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @133_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*4), sizeof v); (u32)v; });  // @134_408a40
  edi = (u32)(ecx + edi*4);  // @135_408a40
  FL[2] = (ebx & ebx);  // @136_408a40
  if (FL[2] != 0) goto L408ba1;  // @137_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @138_408a40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @139_408a40
  if (FL[0] == FL[1]) goto L408bb0;  // @140_408a40
  L408ba1:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @142_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @143_408a40
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + edi*4), &v, sizeof v); }  // @144_408a40
  L408bb0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @146_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1228), sizeof v); (u32)v; });  // @147_408a40
  ecx = (ecx + 1);  // @148_408a40
  FL[3] = ecx;  // @149_408a40
  eax = (eax + (u32)(4));  // @150_408a40
  FL[3] = eax;  // @151_408a40
  FL[0] = ecx; FL[1] = edi;  // @152_408a40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @153_408a40
  if ((s32)FL[0] < (s32)FL[1]) goto L408b86;  // @154_408a40
  L408bc4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @156_408a40
  ebx = 0;  // @157_408a40
  FL[3] = ebx;  // @158_408a40
  FL[2] = (eax & eax);  // @159_408a40
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @160_408a40
  if ((s32)FL[2] <= 0) goto L408c5e;  // @161_408a40
  L408bd3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @163_408a40
  ecx = 0;  // @164_408a40
  FL[3] = ecx;  // @165_408a40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @166_408a40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = ecx;  // @167_408a40
  if ((s32)FL[0] <= (s32)FL[1]) goto L408c2a;  // @168_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @169_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @170_408a40
  edx = (edx + (u32)(4));  // @171_408a40
  FL[3] = edx;  // @172_408a40
  edi = (edi - eax);  // @173_408a40
  FL[3] = edi;  // @174_408a40
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @175_408a40
  L408bee:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @177_408a40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = ebx;  // @178_408a40
  if (FL[0] != FL[1]) goto L408c18;  // @179_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @180_408a40
  edx = 0;  // @181_408a40
  FL[3] = edx;  // @182_408a40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx*4), sizeof v); (u32)v; }); FL[1] = edx;  // @183_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @184_408a40
  edx = (edx & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @185_408a40
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @186_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @187_408a40
  ebx = (ebx + 1);  // @188_408a40
  FL[3] = ebx;  // @189_408a40
  eax = (eax + (u32)(4));  // @190_408a40
  FL[3] = eax;  // @191_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @192_408a40
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @193_408a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @194_408a40
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + edi - 4), &v, sizeof v); }  // @195_408a40
  L408c18:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @197_408a40
  ecx = (ecx + 1);  // @198_408a40
  FL[3] = ecx;  // @199_408a40
  edx = (edx + (u32)(4));  // @200_408a40
  FL[3] = edx;  // @201_408a40
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @202_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @203_408a40
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @204_408a40
  if ((s32)FL[0] < (s32)FL[1]) goto L408bee;  // @205_408a40
  L408c2a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @207_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @208_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @209_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*4), sizeof v); (u32)v; });  // @210_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @211_408a40
  PV[2] = (u32)(ecx);  // @212_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @213_408a40
  PV[3] = (u32)(ecx);  // @214_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @215_408a40
  PV[4] = (u32)(ecx);  // @216_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*4), sizeof v); (u32)v; });  // @217_408a40
  PV[5] = (u32)(ecx);  // @218_408a40
  PV[6] = (u32)(esi);  // @219_408a40
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 32)))(PV[6], PV[5], PV[4], PV[3], PV[2]);  // @220_408a40
  ecx = edx = 0;  // @221_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @222_408a40
  ebx = (ebx + 1);  // @223_408a40
  FL[3] = ebx;  // @224_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @225_408a40
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @226_408a40
  FL[0] = ebx; FL[1] = eax;  // @227_408a40
  if ((s32)FL[0] < (s32)FL[1]) goto L408bd3;  // @228_408a40
  L408c5e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1228), sizeof v); (u32)v; });  // @230_408a40
  ecx = (ecx - 1);  // @231_408a40
  FL[3] = ecx;  // @232_408a40
  if ((s32)FL[3] < 0) goto L408d05;  // @233_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @234_408a40
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @235_408a40
  eax = (eax - edx);  // @236_408a40
  FL[3] = eax;  // @237_408a40
  edi = eax;  // @238_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @239_408a40
  edi = (u32)((s32)edi >> (u32)(1));  // @240_408a40
  FL[3] = edi;  // @241_408a40
  ebx = (u32)(eax + ecx*4 + 2256);  // @242_408a40
  ecx = (ecx + 1);  // @243_408a40
  FL[3] = ecx;  // @244_408a40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @245_408a40
  L408c83:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @247_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 1024), sizeof v); (u32)v; });  // @248_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @249_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @250_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @251_408a40
  FL[2] = (edi & edi);  // @252_408a40
  if ((s32)FL[2] <= 0) goto L408cf6;  // @253_408a40
  edx = eax;  // @254_408a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @255_408a40
  edx = (edx - ecx);  // @256_408a40
  FL[3] = edx;  // @257_408a40
  L408c9e:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @259_408a40
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx + ecx)) : "st");  // @260_408a40
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @261_408a40
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069652)) : "st", "cc");  // @262_408a40
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @263_408a40
  __asm__ volatile("fcoms %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(7069652)) : "st", "cc");  // @264_408a40
  FL[2] = ((eax >> 8) & 65);  // @265_408a40
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @266_408a40
  if (FL[2] != 0) goto L408cd1;  // @267_408a40
  FL[2] = ((eax >> 8) & 65);  // @268_408a40
  if (FL[2] != 0) goto L408cc8;  // @269_408a40
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @270_408a40
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @271_408a40
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx)) :: "st");  // @272_408a40
  goto L408ce8;  // @273_408a40
  L408cc8:;
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @275_408a40
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx)) :: "st");  // @276_408a40
  __asm__ volatile(".byte 0xd8, 0xc1" ::: "st");  // @277_408a40
  goto L408ce6;  // @278_408a40
  L408cd1:;
  FL[2] = ((eax >> 8) & 65);  // @280_408a40
  if (FL[2] != 0) goto L408cdd;  // @281_408a40
  __asm__ volatile(".byte 0xd8, 0xc1" ::: "st");  // @282_408a40
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx)) :: "st");  // @283_408a40
  goto L408ce8;  // @284_408a40
  L408cdd:;
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @286_408a40
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edx + ecx)) :: "st");  // @287_408a40
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @288_408a40
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @289_408a40
  L408ce6:;
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @291_408a40
  L408ce8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @293_408a40
  ecx = (ecx + (u32)(4));  // @294_408a40
  FL[3] = ecx;  // @295_408a40
  eax = (eax - 1);  // @296_408a40
  FL[3] = eax;  // @297_408a40
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @298_408a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @299_408a40
  if (FL[3] != 0) goto L408c9e;  // @300_408a40
  L408cf6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @302_408a40
  ebx = (ebx - (u32)(4));  // @303_408a40
  FL[3] = ebx;  // @304_408a40
  eax = (eax - 1);  // @305_408a40
  FL[3] = eax;  // @306_408a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @307_408a40
  if (FL[3] != 0) goto L408c83;  // @308_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @309_408a40
  L408d05:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @311_408a40
  edi = 0;  // @312_408a40
  FL[3] = edi;  // @313_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @314_408a40
  FL[2] = (ecx & ecx);  // @315_408a40
  if ((s32)FL[2] <= 0) goto L408d49;  // @316_408a40
  ebx = (u32)(edx + 4);  // @317_408a40
  L408d14:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @319_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @320_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @321_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; });  // @322_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @323_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi*4), sizeof v); (u32)v; });  // @324_408a40
  PV[7] = (u32)(edx);  // @325_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @326_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi*4), sizeof v); (u32)v; });  // @327_408a40
  PV[8] = (u32)(edx);  // @328_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @329_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 24), sizeof v); (u32)v; });  // @330_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; });  // @331_408a40
  PV[9] = (u32)(eax);  // @332_408a40
  PV[10] = (u32)(esi);  // @333_408a40
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 32)))(PV[10], PV[9], PV[8], PV[7]);  // @334_408a40
  ecx = edx = 0;  // @335_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @336_408a40
  edi = (edi + 1);  // @337_408a40
  FL[3] = edi;  // @338_408a40
  ebx = (ebx + (u32)(4));  // @339_408a40
  FL[3] = ebx;  // @340_408a40
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @341_408a40
  if ((s32)FL[0] < (s32)FL[1]) goto L408d14;  // @342_408a40
  L408d49:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @344_408a40
  edi = 0;  // @345_408a40
  FL[3] = edi;  // @346_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @347_408a40
  FL[2] = (eax & eax);  // @348_408a40
  if ((s32)FL[2] <= 0) goto L408d7a;  // @349_408a40
  L408d55:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @351_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @352_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @353_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @354_408a40
  PV[11] = (u32)(eax);  // @355_408a40
  PV[12] = (u32)(eax);  // @356_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 36), sizeof v); (u32)v; });  // @357_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @358_408a40
  PV[13] = (u32)(ecx);  // @359_408a40
  eax = ext_4067b0_cdecl3(PV[13], PV[12], PV[11]);  // @360_408a40
  ecx = edx = 0;  // @361_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @362_408a40
  edi = (edi + 1);  // @363_408a40
  FL[3] = edi;  // @364_408a40
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @365_408a40
  if ((s32)FL[0] < (s32)FL[1]) goto L408d55;  // @366_408a40
  L408d7a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @368_408a40
  ebx = 0;  // @369_408a40
  FL[3] = ebx;  // @370_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @371_408a40
  FL[2] = (ecx & ecx);  // @372_408a40
  if ((s32)FL[2] <= 0) goto L408dc9;  // @373_408a40
  L408d86:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @375_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @376_408a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx*4), sizeof v); (u32)v; });  // @377_408a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*4), sizeof v); (u32)v; });  // @378_408a40
  FL[2] = (eax & eax);  // @379_408a40
  if (FL[2] == 0) goto L408db3;  // @380_408a40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @381_408a40
  FL[2] = (edx & edx);  // @382_408a40
  if ((s32)FL[2] <= 0) goto L408dc0;  // @383_408a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @384_408a40
  eax = edi;  // @385_408a40
  ecx = (ecx - edi);  // @386_408a40
  FL[3] = ecx;  // @387_408a40
  L408da3:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + eax)) : "st");  // @389_408a40
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @390_408a40
  eax = (eax + (u32)(4));  // @391_408a40
  FL[3] = eax;  // @392_408a40
  edx = (edx - 1);  // @393_408a40
  FL[3] = edx;  // @394_408a40
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax - 4)) :: "st");  // @395_408a40
  if (FL[3] != 0) goto L408da3;  // @396_408a40
  goto L408dc0;  // @397_408a40
  L408db3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @399_408a40
  FL[2] = (eax & eax);  // @400_408a40
  if ((s32)FL[2] <= 0) goto L408dc0;  // @401_408a40
  ecx = eax;  // @402_408a40
  eax = 0;  // @403_408a40
  FL[3] = eax;  // @404_408a40
  while (ecx) { __builtin_memcpy((void *)edi, &eax, 4); edi += 4; ecx--; }  // @405_408a40
  L408dc0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @407_408a40
  ebx = (ebx + 1);  // @408_408a40
  FL[3] = ebx;  // @409_408a40
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @410_408a40
  if ((s32)FL[0] < (s32)FL[1]) goto L408d86;  // @411_408a40
  L408dc9:;
  eax = 0;  // @413_408a40
  FL[3] = eax;  // @414_408a40
  return eax;  // @415_408a40
}
PCREG(408a40, lifted_408a40);

extern "C" u32 lifted_40c900(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
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
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492744), sizeof v); (u32)v; });  // @0_40c900
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_40c900
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @2_40c900
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @3_40c900
  ecx = (ecx + 1);  // @4_40c900
  FL[3] = ecx;  // @5_40c900
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7492744), &v, sizeof v); }  // @6_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_40c900
  ecx = 0;  // @8_40c900
  FL[3] = ecx;  // @9_40c900
  FL[2] = (eax & eax);  // @10_40c900
  if ((s32)FL[2] <= 0) goto L40c940;  // @11_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @12_40c900
  eax = ebx;  // @13_40c900
  edx = (edx - ebx);  // @14_40c900
  FL[3] = edx;  // @15_40c900
  L40c92e:;
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)(edi + 16)) : "st");  // @17_40c900
  ecx = (ecx + 1);  // @18_40c900
  FL[3] = ecx;  // @19_40c900
  eax = (eax + (u32)(4));  // @20_40c900
  FL[3] = eax;  // @21_40c900
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edx + eax - 4)) : "st");  // @22_40c900
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax - 4)) :: "st");  // @23_40c900
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_40c900
  if ((s32)FL[0] < (s32)FL[1]) goto L40c92e;  // @25_40c900
  L40c940:;
  PV[0] = (u32)(esi);  // @27_40c900
  PV[1] = (u32)(ebx);  // @28_40c900
  PV[2] = (u32)(ebx);  // @29_40c900
  eax = ext_40c780_cdecl3(PV[2], PV[1], PV[0]);  // @30_40c900
  ecx = edx = 0;  // @31_40c900
  __asm__ volatile("fsqrt" ::: "st");  // @32_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @33_40c900
  ebx = (u32)(1);  // @34_40c900
  ebx = (ebx << (ecx & 0xff));  // @35_40c900
  FL[3] = ebx;  // @36_40c900
  ebx = (ebx - 1);  // @37_40c900
  FL[3] = ebx;  // @38_40c900
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @39_40c900
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)(EBP + 12)) : "st");  // @40_40c900
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 24)) :: "st");  // @41_40c900
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)(edi + 16)) : "st");  // @42_40c900
  __asm__ volatile(".byte 0xd8, 0xf9" ::: "st");  // @43_40c900
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @44_40c900
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(7069692)) : "st");  // @45_40c900
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 20))) :: "st");  // @46_40c900
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @47_40c900
  { double fl_ = ext_634dca_dbl(*(double *)(u32)(EBP - 20)); eax = (u32)(s32)fl_; }  // @48_40c900 floor + _ftol
    // @51_40c900
  FL[2] = (eax & eax);  // @52_40c900
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @53_40c900
  if ((s32)FL[2] >= 0) goto L40c992;  // @54_40c900
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @55_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @56_40c900
  L40c992:;
  FL[0] = eax; FL[1] = ebx;  // @58_40c900
  if ((s32)FL[0] <= (s32)FL[1]) goto L40c99b;  // @59_40c900
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @60_40c900
  eax = ebx;  // @61_40c900
  L40c99b:;
  FL[2] = (eax & eax);  // @63_40c900
  if ((s32)FL[2] <= 0) goto L40c9ad;  // @64_40c900
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)(EBP + 12)) : "st");  // @65_40c900
  __asm__ volatile("fdivs %0" :: "m"(*(float *)(u32)(EBP + 24)) : "st");  // @66_40c900
  __asm__ volatile("fimull %0" :: "m"(*(s32 *)(u32)(edi + 16)) : "st");  // @67_40c900
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 8)) :: "st");  // @68_40c900
  goto L40c9b4;  // @69_40c900
  L40c9ad:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @71_40c900
  L40c9b4:;
  FL[2] = (eax & eax);  // @73_40c900
  if (FL[2] == 0) goto L40c9f4;  // @74_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @75_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492744), sizeof v); (u32)v; });  // @76_40c900
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @77_40c900
  PV[3] = (u32)(eax);  // @78_40c900
  ecx = (ecx - 1);  // @79_40c900
  FL[3] = ecx;  // @80_40c900
  PV[4] = (u32)(ebx);  // @81_40c900
  PV[5] = (u32)(ecx);  // @82_40c900
  eax = ext_40ce50_cdecl6((u32)(7283672), PV[5], PV[4], PV[3], (u32)(0), (u32)(0));  // @83_40c900
    // @84_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @85_40c900
  PV[6] = (u32)(edx);  // @86_40c900
  PV[7] = (u32)(ebx);  // @87_40c900
  PV[8] = (u32)(ebx);  // @88_40c900
  eax = ext_40fc00_cdecl3(PV[8], PV[7], PV[6]);  // @89_40c900
  ecx = edx = 0;  // @90_40c900
  FL[2] = (eax & eax);  // @91_40c900
  if (FL[2] == 0) goto L40c9ef;  // @92_40c900
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @93_40c900
  L40c9ef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @95_40c900
  goto L40c9f7;  // @96_40c900
  L40c9f4:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @98_40c900
  L40c9f7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @100_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @101_40c900
  ecx = (ecx + (u32)(4));  // @102_40c900
  FL[3] = ecx;  // @103_40c900
  PV[9] = (u32)(edx);  // @104_40c900
  PV[10] = (u32)(eax);  // @105_40c900
  PV[11] = (u32)(ecx);  // @106_40c900
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @107_40c900
  eax = ext_410bf0_cdecl3(PV[11], PV[10], PV[9]);  // @108_40c900
  ecx = edx = 0;  // @109_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @110_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @111_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @112_40c900
  eax = (eax + 1);  // @113_40c900
  FL[3] = eax;  // @114_40c900
  edx = (edx + eax);  // @115_40c900
  FL[3] = edx;  // @116_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @117_40c900
  ecx = (ecx + 1);  // @118_40c900
  FL[3] = ecx;  // @119_40c900
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @120_40c900
  FL[2] = (eax & eax);  // @121_40c900
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @122_40c900
  if (FL[2] == 0) goto L40cbe1;  // @123_40c900
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @124_40c900
  eax = (u32)(ebx*4);  // @125_40c900
  eax = (eax + (u32)(3));  // @126_40c900
  FL[3] = eax;  // @127_40c900
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(252))) & 0xff);  // @128_40c900
  FL[3] = (eax & 0xff);  // @129_40c900
  ALLOC_PTR = (u32)__builtin_alloca(eax);  // @130_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @131_40c900
  { u32 v = (u32)(ALLOC_PTR); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @132_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; });  // @133_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @134_40c900
  PV[12] = (u32)(ebx);  // @135_40c900
  PV[13] = (u32)(ecx);  // @136_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 104), sizeof v); (u32)v; });  // @137_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492744), sizeof v); (u32)v; });  // @138_40c900
  edx = (edx - 1);  // @139_40c900
  FL[3] = edx;  // @140_40c900
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @141_40c900
  PV[14] = (u32)(edx);  // @142_40c900
  eax = ext_40ce50_cdecl6((u32)(7283668), PV[14], PV[13], PV[12], (u32)(0), (u32)(0));  // @143_40c900
    // @144_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @145_40c900
  FL[0] = edx; FL[1] = (u32)(1);  // @146_40c900
  if ((s32)FL[0] <= (s32)FL[1]) goto L40caba;  // @147_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @148_40c900
  ebx = 0;  // @149_40c900
  FL[3] = ebx;  // @150_40c900
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(7069652)) : "st");  // @151_40c900
  FL[2] = (eax & eax);  // @152_40c900
  if ((s32)FL[2] <= 0) goto L40caaa;  // @153_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @154_40c900
  L40ca87:;
  __asm__ volatile("fsubrs %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @156_40c900
  __asm__ volatile("fcoms %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(edi + 88)) : "st", "cc");  // @157_40c900
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @158_40c900
  FL[2] = ((eax >> 8) & 1);  // @159_40c900
  if (FL[2] != 0) goto L40caaa;  // @160_40c900
  __asm__ volatile("fcomps %1; fnstsw %%ax" : "=a"(X87SW) : "m"(*(float *)(u32)(edi + 92)) : "st", "cc");  // @161_40c900
  eax = (eax & 0xffff0000u) | ((u32)X87SW & 0xffffu);  // @162_40c900
  FL[2] = ((eax >> 8) & 65);  // @163_40c900
  if (FL[2] == 0) goto L40caac;  // @164_40c900
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @165_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @166_40c900
  ebx = (ebx + 1);  // @167_40c900
  FL[3] = ebx;  // @168_40c900
  ecx = (ecx + (u32)(4));  // @169_40c900
  FL[3] = ecx;  // @170_40c900
  FL[0] = ebx; FL[1] = eax;  // @171_40c900
  if ((s32)FL[0] < (s32)FL[1]) goto L40ca87;  // @172_40c900
  L40caaa:;
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @174_40c900
  L40caac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @176_40c900
  eax = 0;  // @177_40c900
  FL[3] = eax;  // @178_40c900
  FL[0] = ebx; FL[1] = ecx;  // @179_40c900
  eax = (eax & 0xffffff00u) | (((((s32)FL[0] >= (s32)FL[1]) ? 1 : 0)) & 0xff);  // @180_40c900
  ebx = eax;  // @181_40c900
  goto L40cabc;  // @182_40c900
  L40caba:;
  ebx = 0;  // @184_40c900
  FL[3] = ebx;  // @185_40c900
  L40cabc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*4 + 24), sizeof v); (u32)v; });  // @187_40c900
  PV[15] = (u32)(edx);  // @188_40c900
  ecx = (u32)(eax*8);  // @189_40c900
  ecx = (ecx - eax);  // @190_40c900
  FL[3] = ecx;  // @191_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @192_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @193_40c900
  ecx = (u32)(eax + ecx*4);  // @194_40c900
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @195_40c900
  eax = ext_405090_cdecl1(PV[15]);  // @196_40c900
  ecx = 0;  // @197_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @198_40c900
  PV[16] = (u32)(eax);  // @199_40c900
  PV[17] = (u32)(ebx);  // @200_40c900
  PV[18] = (u32)(edx);  // @201_40c900
  eax = ext_410bf0_cdecl3(PV[18], PV[17], PV[16]);  // @202_40c900
  ecx = edx = 0;  // @203_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @204_40c900
  PV[19] = (u32)(eax);  // @205_40c900
  eax = ext_405090_cdecl1(PV[19]);  // @206_40c900
  ecx = 0;  // @207_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @208_40c900
  ecx = (ecx + eax);  // @209_40c900
  FL[3] = ecx;  // @210_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @211_40c900
  ebx = 0;  // @212_40c900
  FL[3] = ebx;  // @213_40c900
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @214_40c900
  FL[2] = (eax & eax);  // @215_40c900
  if ((s32)FL[2] <= 0) goto L40cb3c;  // @216_40c900
  L40cb03:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @218_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @219_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @220_40c900
  PV[20] = (u32)(ebx);  // @221_40c900
  PV[21] = (u32)(ecx);  // @222_40c900
  PV[22] = (u32)(edx);  // @223_40c900
  PV[23] = (u32)(eax);  // @224_40c900
  eax = ext_40cc20_cdecl4(PV[23], PV[22], PV[21], PV[20]);  // @225_40c900
  ecx = edx = 0;  // @226_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @227_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @228_40c900
  PV[24] = (u32)(ecx);  // @229_40c900
  PV[25] = (u32)(eax);  // @230_40c900
  PV[26] = (u32)(edx);  // @231_40c900
  eax = ext_405ee0_cdecl3(PV[26], PV[25], PV[24]);  // @232_40c900
  ecx = edx = 0;  // @233_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @234_40c900
  edx = (edx + eax);  // @235_40c900
  FL[3] = edx;  // @236_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @237_40c900
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @238_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @239_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @240_40c900
  ebx = (ebx + ecx);  // @241_40c900
  FL[3] = ebx;  // @242_40c900
  FL[0] = ebx; FL[1] = eax;  // @243_40c900
  if ((s32)FL[0] < (s32)FL[1]) goto L40cb03;  // @244_40c900
  L40cb3c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @246_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492744), sizeof v); (u32)v; });  // @247_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @248_40c900
  PV[27] = (u32)(ecx);  // @249_40c900
  eax = (eax - 1);  // @250_40c900
  FL[3] = eax;  // @251_40c900
  PV[28] = (u32)(edx);  // @252_40c900
  PV[29] = (u32)(eax);  // @253_40c900
  eax = ext_40ce50_cdecl6((u32)(7283660), PV[29], PV[28], PV[27], (u32)(0), (u32)(0));  // @254_40c900
    // @255_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @256_40c900
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @257_40c900
  eax = 0;  // @258_40c900
  FL[3] = eax;  // @259_40c900
  FL[2] = (ecx & ecx);  // @260_40c900
  if ((s32)FL[2] <= 0) goto L40cb79;  // @261_40c900
  ecx = ebx;  // @262_40c900
  L40cb69:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @264_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @265_40c900
  eax = (eax + 1);  // @266_40c900
  FL[3] = eax;  // @267_40c900
  ecx = (ecx + (u32)(4));  // @268_40c900
  FL[3] = ecx;  // @269_40c900
  FL[0] = eax; FL[1] = edx;  // @270_40c900
  if ((s32)FL[0] < (s32)FL[1]) goto L40cb69;  // @271_40c900
  L40cb79:;
  __asm__ volatile("fildl %0" :: "m"(*(s32 *)(u32)(edi + 16)) : "st");  // @273_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @274_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @275_40c900
  PV[30] = (u32)(ecx);  // @276_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @277_40c900
  { float f_; __asm__ volatile("fstps %0" : "=m"(f_) :: "st"); PV[31] = F2U(f_); }  // @278_40c900
  PV[32] = (u32)(ecx);  // @279_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @280_40c900
  PV[33] = (u32)(edx);  // @281_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @282_40c900
  PV[34] = (u32)(eax);  // @283_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @284_40c900
  PV[35] = (u32)(ecx);  // @285_40c900
  PV[36] = (u32)(edx);  // @286_40c900
  PV[37] = (u32)(eax);  // @287_40c900
  PV[38] = (u32)(ebx);  // @288_40c900
  eax = ext_40fa80_cdecl8(PV[38], PV[37], PV[36], PV[35], PV[34], PV[33], PV[32], PV[31]);  // @289_40c900
  ecx = edx = 0;  // @290_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @291_40c900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492744), sizeof v); (u32)v; });  // @292_40c900
  PV[39] = (u32)(ecx);  // @293_40c900
  edx = (edx - 1);  // @294_40c900
  FL[3] = edx;  // @295_40c900
  PV[40] = (u32)(ebx);  // @296_40c900
  PV[41] = (u32)(edx);  // @297_40c900
  eax = ext_40ce50_cdecl14((u32)(7283652), PV[41], PV[40], PV[39], (u32)(1), (u32)(1), PV[38], PV[37], PV[36], PV[35], PV[34], PV[33], PV[32], PV[31]);  // @298_40c900
    // @299_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @300_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7492744), sizeof v); (u32)v; });  // @301_40c900
  PV[42] = (u32)(eax);  // @302_40c900
  ecx = (ecx - 1);  // @303_40c900
  FL[3] = ecx;  // @304_40c900
  PV[43] = (u32)(ebx);  // @305_40c900
  PV[44] = (u32)(ecx);  // @306_40c900
  eax = ext_40ce50_cdecl6((u32)(7283644), PV[44], PV[43], PV[42], (u32)(0), (u32)(1));  // @307_40c900
    // @308_40c900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @309_40c900
  return eax;  // @310_40c900
  L40cbe1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @312_40c900
  eax = 0;  // @313_40c900
  FL[3] = eax;  // @314_40c900
  ecx = (ecx << (u32)(2));  // @315_40c900
  FL[3] = ecx;  // @316_40c900
  edx = ecx;  // @317_40c900
  edi = ebx;  // @318_40c900
  ecx = (ecx >> (u32)(2));  // @319_40c900
  FL[3] = ecx;  // @320_40c900
  while (ecx) { __builtin_memcpy((void *)edi, &eax, 4); edi += 4; ecx--; }  // @321_40c900
  ecx = edx;  // @322_40c900
  ecx = (ecx & (u32)(3));  // @323_40c900
  FL[3] = ecx;  // @324_40c900
  while (ecx) { *(u8 *)edi = (u8)eax; edi++; ecx--; }  // @325_40c900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_40c900
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @327_40c900
  ecx = (ecx << (u32)(2));  // @328_40c900
  FL[3] = ecx;  // @329_40c900
  edx = ecx;  // @330_40c900
  eax = 0;  // @331_40c900
  FL[3] = eax;  // @332_40c900
  ecx = (ecx >> (u32)(2));  // @333_40c900
  FL[3] = ecx;  // @334_40c900
  while (ecx) { __builtin_memcpy((void *)edi, &eax, 4); edi += 4; ecx--; }  // @335_40c900
  ecx = edx;  // @336_40c900
  ecx = (ecx & (u32)(3));  // @337_40c900
  FL[3] = ecx;  // @338_40c900
  while (ecx) { *(u8 *)edi = (u8)eax; edi++; ecx--; }  // @339_40c900
  eax = 0;  // @340_40c900
  FL[3] = eax;  // @341_40c900
  return eax;  // @342_40c900
}
PCREG(40c900, lifted_40c900);

