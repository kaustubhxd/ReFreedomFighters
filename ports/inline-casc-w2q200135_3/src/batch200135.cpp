// batch200135.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double THISCALL ext_4e5e80_thiscall1_f(u32) __asm__("ext_4e5e80");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 THISCALL ext_41e680_thiscall1(u32) __asm__("ext_41e680");
extern "C" u32 THISCALL ext_44c2b0_thiscall1(u32) __asm__("ext_44c2b0");
extern "C" u32 THISCALL ext_44c370_thiscall1(u32) __asm__("ext_44c370");
extern "C" u32 THISCALL ext_494ac0_thiscall2(u32, u32) __asm__("ext_494ac0");
extern "C" u32 THISCALL ext_494b40_thiscall2(u32, u32) __asm__("ext_494b40");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4e5e40_thiscall1(u32) __asm__("ext_4e5e40");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d70_cdecl0(void) __asm__("ext_634d70");
extern "C" u32 ext_634d76_cdecl0(void) __asm__("ext_634d76");
extern "C" u32 ext_634dac_cdecl0(void) __asm__("ext_634dac");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c14b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c14b0
  esi = ecx;  // @1_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_4c14b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @3_4c14b0
  if ((eax & 0xff) == (u32)(255)) goto L4c14d6;  // @4_4c14b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @5_4c14b0
  if ((eax & 0xff) != (u32)(10)) goto L4c14d6;  // @6_4c14b0
  ecx = edi;  // @7_4c14b0
  eax = ext_4e5e40_thiscall1(ecx);  // @8_4c14b0
  ecx = edx = 0;  // @9_4c14b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @10_4c14b0
  L4c14d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_4c14b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @13_4c14b0
  if ((eax & 0xff) == (u32)(255)) goto L4c14ef;  // @14_4c14b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @15_4c14b0
  if ((eax & 0xff) != (u32)(10)) goto L4c14ef;  // @16_4c14b0
  ecx = edi;  // @17_4c14b0
  eax = ext_4e5e40_thiscall1(ecx);  // @18_4c14b0
  ecx = edx = 0;  // @19_4c14b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @20_4c14b0
  L4c14ef:;
  ecx = edi;  // @22_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @23_4c14b0
  ecx = edx = 0;  // @24_4c14b0
  ecx = edi;  // @25_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @26_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @27_4c14b0
  ecx = edx = 0;  // @28_4c14b0
  ecx = edi;  // @29_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @30_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @31_4c14b0
  ecx = edx = 0;  // @32_4c14b0
  ecx = edi;  // @33_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @34_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @35_4c14b0
  ecx = edx = 0;  // @36_4c14b0
  ecx = edi;  // @37_4c14b0
  ebx = eax;  // @38_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @39_4c14b0
  ecx = edx = 0;  // @40_4c14b0
  ecx = edi;  // @41_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @42_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @43_4c14b0
  ecx = edx = 0;  // @44_4c14b0
  ecx = edi;  // @45_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @46_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @47_4c14b0
  ecx = edx = 0;  // @48_4c14b0
  ecx = edi;  // @49_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @50_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @51_4c14b0
  ecx = edx = 0;  // @52_4c14b0
  ecx = edi;  // @53_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @54_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @55_4c14b0
  ecx = edx = 0;  // @56_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @57_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_4c14b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @59_4c14b0
  if ((ecx & 0xff) == (u32)(255)) goto L4c1564;  // @60_4c14b0
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @61_4c14b0
  if ((ecx & 0xff) != (u32)(2)) goto L4c1564;  // @62_4c14b0
  ecx = edi;  // @63_4c14b0
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @64_4c14b0
  ecx = edx = 0;  // @65_4c14b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 102), &v, 4); }  // @66_4c14b0
  L4c1564:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @68_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @69_4c14b0
  eax = (eax << (u32)(4));  // @70_4c14b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @71_4c14b0
  ecx = (u32)(ecx + eax*4);  // @72_4c14b0
  eax = ecx;  // @73_4c14b0
  eax = (eax << (u32)(4));  // @74_4c14b0
  eax = (eax - ecx);  // @75_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @76_4c14b0
  eax = (u32)(ecx + eax*4);  // @77_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @78_4c14b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @79_4c14b0
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @80_4c14b0
  eax = (eax >> (u32)(31));  // @81_4c14b0
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(eax*8 + 6818464))));  // @82_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @83_4c14b0
  eax = (eax << (u32)(4));  // @84_4c14b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @85_4c14b0
  x2 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @86_4c14b0
  ecx = (u32)(ecx + eax*4);  // @87_4c14b0
  eax = ecx;  // @88_4c14b0
  eax = (eax << (u32)(4));  // @89_4c14b0
  eax = (eax - ecx);  // @90_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @91_4c14b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ebx));  // @92_4c14b0
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @93_4c14b0
  ebx = (ebx >> (u32)(31));  // @94_4c14b0
  eax = (u32)(ecx + eax*4);  // @95_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_4c14b0
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(ebx*8 + 6818464))));  // @97_4c14b0
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @98_4c14b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6840448)));  // @99_4c14b0
  x2 = _mm_add_ss(x2, x0);  // @100_4c14b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @101_4c14b0
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @102_4c14b0
  eax = (eax >> (u32)(31));  // @103_4c14b0
  _mm_store_ss((float *)(u32)(EBP - 8), x2);  // @104_4c14b0
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(eax*8 + 6818464))));  // @105_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @106_4c14b0
  x2 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @107_4c14b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @108_4c14b0
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @109_4c14b0
  eax = (eax >> (u32)(31));  // @110_4c14b0
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(eax*8 + 6818464))));  // @111_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @113_4c14b0
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @114_4c14b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6840448)));  // @115_4c14b0
  x2 = _mm_add_ss(x2, x0);  // @116_4c14b0
  _mm_store_ss((float *)(u32)(EBP - 24), x2);  // @117_4c14b0
  T[0] = ((double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6896704), (u32)(3103));  // @118_4c14b0
  ecx = edx = 0;  // @119_4c14b0
  x0 = _mm_load_ss((const float *)(u32)(esi + 102));  // @120_4c14b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP + 8), &v, 4); }  // @121_4c14b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(EBP + 8)));  // @122_4c14b0
  if (!(fa_ >= fb_)) goto L4c1650;  // @123_4c14b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @124_4c14b0
  goto L4c1654;  // @125_4c14b0
  L4c1650:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @127_4c14b0
  L4c1654:;
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }) == (u32)(0)) goto L4c165f;  // @129_4c14b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @130_4c14b0
  L4c165f:;
  x0 = _mm_load_ss((const float *)(u32)(EBP - 24));  // @132_4c14b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6784464)));  // @133_4c14b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @134_4c14b0
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4c168f;  // @135_4c14b0
  x1 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @136_4c14b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @137_4c14b0
  if (!(fa_ > fb_)) goto L4c168f;  // @138_4c14b0
  _mm_store_ss((float *)(u32)(esi + 82), x1);  // @139_4c14b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @140_4c14b0
  _mm_store_ss((float *)(u32)(esi + 86), x0);  // @141_4c14b0
  __asm__ volatile("" :: "Yz"(x0));  // @142_4c14b0
  return eax;  // @143_4c14b0
  L4c168f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @145_4c14b0
  ecx = esi;  // @146_4c14b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @147_4c14b0
  ecx = edx = 0;  // @148_4c14b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @149_4c14b0
  __asm__ volatile("" :: "Yz"(x0));  // @150_4c14b0
  return eax;  // @151_4c14b0
}
PCREG(4c14b0, lifted_4c14b0);

extern "C" u32 THISCALL lifted_4c16b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c16b0
  esi = ecx;  // @1_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_4c16b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @3_4c16b0
  if ((eax & 0xff) == (u32)(255)) goto L4c16d6;  // @4_4c16b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @5_4c16b0
  if ((eax & 0xff) != (u32)(10)) goto L4c16d6;  // @6_4c16b0
  ecx = edi;  // @7_4c16b0
  eax = ext_4e5e40_thiscall1(ecx);  // @8_4c16b0
  ecx = edx = 0;  // @9_4c16b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @10_4c16b0
  L4c16d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_4c16b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @13_4c16b0
  if ((eax & 0xff) == (u32)(255)) goto L4c16ef;  // @14_4c16b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @15_4c16b0
  if ((eax & 0xff) != (u32)(10)) goto L4c16ef;  // @16_4c16b0
  ecx = edi;  // @17_4c16b0
  eax = ext_4e5e40_thiscall1(ecx);  // @18_4c16b0
  ecx = edx = 0;  // @19_4c16b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @20_4c16b0
  L4c16ef:;
  ecx = edi;  // @22_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @23_4c16b0
  ecx = edx = 0;  // @24_4c16b0
  ecx = edi;  // @25_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @26_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @27_4c16b0
  ecx = edx = 0;  // @28_4c16b0
  ecx = edi;  // @29_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @30_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @31_4c16b0
  ecx = edx = 0;  // @32_4c16b0
  ecx = edi;  // @33_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @34_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @35_4c16b0
  ecx = edx = 0;  // @36_4c16b0
  ecx = edi;  // @37_4c16b0
  ebx = eax;  // @38_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @39_4c16b0
  ecx = edx = 0;  // @40_4c16b0
  ecx = edi;  // @41_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @42_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @43_4c16b0
  ecx = edx = 0;  // @44_4c16b0
  ecx = edi;  // @45_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @46_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @47_4c16b0
  ecx = edx = 0;  // @48_4c16b0
  ecx = edi;  // @49_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @50_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @51_4c16b0
  ecx = edx = 0;  // @52_4c16b0
  ecx = edi;  // @53_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @54_4c16b0
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @55_4c16b0
  ecx = edx = 0;  // @56_4c16b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 94), &v, 4); }  // @57_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_4c16b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @59_4c16b0
  if ((ecx & 0xff) == (u32)(255)) goto L4c1764;  // @60_4c16b0
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @61_4c16b0
  if ((ecx & 0xff) != (u32)(2)) goto L4c1764;  // @62_4c16b0
  ecx = edi;  // @63_4c16b0
  T[0] = ext_4e5e80_thiscall1_f(ecx);  // @64_4c16b0
  ecx = edx = 0;  // @65_4c16b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(esi + 102), &v, 4); }  // @66_4c16b0
  L4c1764:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @68_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @69_4c16b0
  eax = (eax << (u32)(4));  // @70_4c16b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @71_4c16b0
  ecx = (u32)(ecx + eax*4);  // @72_4c16b0
  eax = ecx;  // @73_4c16b0
  eax = (eax << (u32)(4));  // @74_4c16b0
  eax = (eax - ecx);  // @75_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @76_4c16b0
  eax = (u32)(ecx + eax*4);  // @77_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @78_4c16b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @79_4c16b0
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @80_4c16b0
  eax = (eax >> (u32)(31));  // @81_4c16b0
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(eax*8 + 6818464))));  // @82_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @83_4c16b0
  eax = (eax << (u32)(4));  // @84_4c16b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @85_4c16b0
  x2 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @86_4c16b0
  ecx = (u32)(ecx + eax*4);  // @87_4c16b0
  eax = ecx;  // @88_4c16b0
  eax = (eax << (u32)(4));  // @89_4c16b0
  eax = (eax - ecx);  // @90_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @91_4c16b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ebx));  // @92_4c16b0
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @93_4c16b0
  ebx = (ebx >> (u32)(31));  // @94_4c16b0
  eax = (u32)(ecx + eax*4);  // @95_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_4c16b0
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(ebx*8 + 6818464))));  // @97_4c16b0
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @98_4c16b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6840448)));  // @99_4c16b0
  x2 = _mm_add_ss(x2, x0);  // @100_4c16b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @101_4c16b0
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @102_4c16b0
  eax = (eax >> (u32)(31));  // @103_4c16b0
  _mm_store_ss((float *)(u32)(EBP - 8), x2);  // @104_4c16b0
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(eax*8 + 6818464))));  // @105_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @106_4c16b0
  x2 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @107_4c16b0
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @108_4c16b0
  x0 = _mm_castpd_ps(_mm_cvtepi32_pd(_mm_castps_si128(x0)));  // @109_4c16b0
  eax = (eax >> (u32)(31));  // @110_4c16b0
  x0 = _mm_castpd_ps(_mm_add_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(eax*8 + 6818464))));  // @111_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @113_4c16b0
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @114_4c16b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6840448)));  // @115_4c16b0
  x2 = _mm_add_ss(x2, x0);  // @116_4c16b0
  _mm_store_ss((float *)(u32)(EBP - 24), x2);  // @117_4c16b0
  T[0] = ((double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6896704), (u32)(3294));  // @118_4c16b0
  ecx = edx = 0;  // @119_4c16b0
  x0 = _mm_load_ss((const float *)(u32)(esi + 102));  // @120_4c16b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP + 8), &v, 4); }  // @121_4c16b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(EBP + 8)));  // @122_4c16b0
  if (!(fa_ >= fb_)) goto L4c1850;  // @123_4c16b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @124_4c16b0
  goto L4c1854;  // @125_4c16b0
  L4c1850:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @127_4c16b0
  L4c1854:;
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }) == (u32)(0)) goto L4c185f;  // @129_4c16b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @130_4c16b0
  L4c185f:;
  x0 = _mm_load_ss((const float *)(u32)(EBP - 24));  // @132_4c16b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6784464)));  // @133_4c16b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @134_4c16b0
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4c188f;  // @135_4c16b0
  x1 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @136_4c16b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @137_4c16b0
  if (!(fa_ > fb_)) goto L4c188f;  // @138_4c16b0
  _mm_store_ss((float *)(u32)(esi + 82), x1);  // @139_4c16b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @140_4c16b0
  _mm_store_ss((float *)(u32)(esi + 86), x0);  // @141_4c16b0
  __asm__ volatile("" :: "Yz"(x0));  // @142_4c16b0
  return eax;  // @143_4c16b0
  L4c188f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @145_4c16b0
  ecx = esi;  // @146_4c16b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @147_4c16b0
  ecx = edx = 0;  // @148_4c16b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @149_4c16b0
  __asm__ volatile("" :: "Yz"(x0));  // @150_4c16b0
  return eax;  // @151_4c16b0
}
PCREG(4c16b0, lifted_4c16b0);

extern "C" u32 THISCALL lifted_4bfc70(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4bfc70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; }) == (u32)(0)) goto L4bfede;  // @1_4bfc70
  x0 = _mm_load_ss((const float *)(u32)(esi + 89));  // @2_4bfc70
  x1 = _mm_setzero_ps();  // @3_4bfc70
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @4_4bfc70
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @5_4bfc70
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4bfcbe;  // @6_4bfc70
  x0 = _mm_load_ss((const float *)(u32)(esi + 101));  // @7_4bfc70
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @8_4bfc70
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @9_4bfc70
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4bfcbe;  // @10_4bfc70
  x0 = _mm_load_ss((const float *)(u32)(esi + 85));  // @11_4bfc70
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @12_4bfc70
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @13_4bfc70
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4bfcbe;  // @14_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @15_4bfc70
  if ((eax & eax) == 0) goto L4bfcbe;  // @16_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @17_4bfc70
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 132), &v, sizeof v); }  // @18_4bfc70
  L4bfcbe:;
  x0 = _mm_load_ss((const float *)(u32)(esi + 85));  // @20_4bfc70
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @21_4bfc70
  x1 = _mm_load_ss((const float *)(u32)(6784544));  // @22_4bfc70
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @23_4bfc70
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4bfd13;  // @24_4bfc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_4bfc70
  x0 = _mm_load_ss((const float *)(u32)(ecx + 72));  // @26_4bfc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; });  // @27_4bfc70
  x0 = _mm_mul_ss(x0, x1);  // @28_4bfc70
  eax = (u32)_mm_cvtss_si32(x0);  // @29_4bfc70
  ecx = (ecx - eax);  // @30_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @31_4bfc70
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ecx));  // @32_4bfc70
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @33_4bfc70
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784484)));  // @34_4bfc70
  _mm_store_ss((float *)(u32)(esi + 85), x0);  // @35_4bfc70
  if ((eax & eax) == 0) goto L4bfd13;  // @36_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @37_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 132), sizeof v); (u32)v; });  // @38_4bfc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @39_4bfc70
  L4bfd13:;
  x0 = _mm_load_ss((const float *)(u32)(esi + 89));  // @41_4bfc70
  x0 = _mm_add_ss(x0, _mm_load_ss((const float *)(u32)(esi + 85)));  // @42_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4bfc70
  x0 = _mm_mul_ss(x0, x1);  // @44_4bfc70
  ecx = (u32)_mm_cvtss_si32(x0);  // @45_4bfc70
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }) < (s32)ecx) goto L4bfede;  // @46_4bfc70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 115), sizeof v); (u32)v; }) == (u32)(0)) goto L4bfd47;  // @47_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_4bfc70
  ecx = esi;  // @49_4bfc70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 136)))(ecx);  // @50_4bfc70
  ecx = edx = 0;  // @51_4bfc70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @52_4bfc70
  L4bfd47:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) != (u32)(0)) goto L4bfd5d;  // @54_4bfc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @55_4bfc70
  if ((ecx & ecx) == 0) goto L4bfd59;  // @56_4bfc70
  eax = ext_44c2b0_thiscall1(ecx);  // @57_4bfc70
  ecx = edx = 0;  // @58_4bfc70
  L4bfd59:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @60_4bfc70
  L4bfd5d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; }) == (u32)(0)) goto L4bfd89;  // @62_4bfc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @63_4bfc70
  if ((ecx & ecx) == 0) goto L4bfd89;  // @64_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4bfc70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 260)))(ecx, (u32)(6880432));  // @66_4bfc70
  ecx = edx = 0;  // @67_4bfc70
  if ((eax & eax) == 0) goto L4bfd85;  // @68_4bfc70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @69_4bfc70
  ecx = eax;  // @70_4bfc70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 132)))(ecx);  // @71_4bfc70
  ecx = edx = 0;  // @72_4bfc70
  L4bfd85:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @74_4bfc70
  L4bfd89:;
  x1 = _mm_load_ss((const float *)(u32)(esi + 93));  // @76_4bfc70
  x2 = _mm_setzero_ps();  // @77_4bfc70
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x2);  // @78_4bfc70
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @79_4bfc70
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4bfda4;  // @80_4bfc70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 83), sizeof v); (u32)v; }) == (u32)(0)) goto L4bfe6b;  // @81_4bfc70
  L4bfda4:;
  x1 = _mm_add_ss(x1, _mm_load_ss((const float *)(u32)(esi + 85)));  // @83_4bfc70
  x4 = _mm_load_ss((const float *)(u32)(esi + 105));  // @84_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_4bfc70
  x0 = x4;  // @86_4bfc70
  x3 = _mm_load_ss((const float *)(u32)(6784544));  // @87_4bfc70
  x0 = _mm_add_ss(x0, x1);  // @88_4bfc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @89_4bfc70
  x0 = _mm_mul_ss(x0, x3);  // @90_4bfc70
  eax = (u32)_mm_cvtss_si32(x0);  // @91_4bfc70
  if ((s32)ecx <= (s32)eax) goto L4bfdfc;  // @92_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_4bfc70
  ecx = esi;  // @94_4bfc70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 83), &v, sizeof v); }  // @95_4bfc70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @96_4bfc70
  ecx = edx = 0;  // @97_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_4bfc70
  ecx = esi;  // @99_4bfc70
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @100_4bfc70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 140)))(ecx);  // @101_4bfc70
  ecx = edx = 0;  // @102_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @103_4bfc70
  ecx = esi;  // @104_4bfc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @105_4bfc70
  ecx = edx = 0;  // @106_4bfc70
  __asm__ volatile("" :: "Yz"(x0));  // @107_4bfc70
  return eax;  // @108_4bfc70
  L4bfdfc:;
  fa_ = _mm_cvtss_f32(x4); fb_ = _mm_cvtss_f32(x2);  // @110_4bfc70
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @111_4bfc70
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4bfe73;  // @112_4bfc70
  x1 = _mm_mul_ss(x1, x3);  // @113_4bfc70
  eax = (u32)_mm_cvtss_si32(x1);  // @114_4bfc70
  if ((s32)ecx < (s32)eax) goto L4bfe73;  // @115_4bfc70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }) == (u32)(0)) goto L4bfe2e;  // @116_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @117_4bfc70
  if ((eax & eax) == 0) goto L4bfe2a;  // @118_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @119_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 132), sizeof v); (u32)v; });  // @120_4bfc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @121_4bfc70
  L4bfe2a:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @123_4bfc70
  L4bfe2e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_4bfc70
  x1 = _mm_load_ss((const float *)(u32)(esi + 97));  // @126_4bfc70
  x0 = _mm_load_ss((const float *)(u32)(eax + 72));  // @127_4bfc70
  x0 = _mm_div_ss(x0, x4);  // @128_4bfc70
  x1 = _mm_sub_ss(x1, x0);  // @129_4bfc70
  fa_ = _mm_cvtss_f32(x2); fb_ = _mm_cvtss_f32(x1);  // @130_4bfc70
  _mm_store_ss((float *)(u32)(esi + 97), x1);  // @131_4bfc70
  if (!(fa_ > fb_)) goto L4bfe56;  // @132_4bfc70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @133_4bfc70
  L4bfe56:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @135_4bfc70
  if ((ecx & ecx) == 0) goto L4bfe73;  // @136_4bfc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @137_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 97), sizeof v); (u32)v; });  // @138_4bfc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 132), &v, sizeof v); }  // @139_4bfc70
  goto L4bfe73;  // @140_4bfc70
  L4bfe6b:;
  x3 = _mm_load_ss((const float *)(u32)(6784544));  // @142_4bfc70
  L4bfe73:;
  x1 = _mm_load_ss((const float *)(u32)(esi + 101));  // @144_4bfc70
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x2);  // @145_4bfc70
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @146_4bfc70
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4bfede;  // @147_4bfc70
  x0 = _mm_load_ss((const float *)(u32)(esi + 89));  // @148_4bfc70
  x0 = _mm_add_ss(x0, _mm_load_ss((const float *)(u32)(esi + 85)));  // @149_4bfc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @150_4bfc70
  x0 = _mm_add_ss(x0, x1);  // @151_4bfc70
  x0 = _mm_mul_ss(x0, x3);  // @152_4bfc70
  eax = (u32)_mm_cvtss_si32(x0);  // @153_4bfc70
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; }) > (s32)eax) goto L4bfede;  // @154_4bfc70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 83), sizeof v); (u32)v; }) != (u32)(0)) goto L4bfede;  // @155_4bfc70
  x0 = _mm_load_ss((const float *)(u32)(ecx + 72));  // @156_4bfc70
  x0 = _mm_div_ss(x0, x1);  // @157_4bfc70
  x0 = _mm_add_ss(x0, _mm_load_ss((const float *)(u32)(esi + 97)));  // @158_4bfc70
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6785112)));  // @159_4bfc70
  _mm_store_ss((float *)(u32)(esi + 97), x0);  // @160_4bfc70
  if (!(fa_ > fb_)) goto L4bfecb;  // @161_4bfc70
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @162_4bfc70
  L4bfecb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @164_4bfc70
  if ((ecx & ecx) == 0) goto L4bfede;  // @165_4bfc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @166_4bfc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 97), sizeof v); (u32)v; });  // @167_4bfc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 132), &v, sizeof v); }  // @168_4bfc70
  L4bfede:;
  __asm__ volatile("" :: "Yz"(x0));  // @170_4bfc70
  return eax;  // @171_4bfc70
}
PCREG(4bfc70, lifted_4bfc70);

extern "C" u32 FASTCALL lifted_5460b0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  x0 = _mm_load_ss((const float *)(u32)(EBP + 12));  // @0_5460b0
  x0 = _mm_add_ss(x0, _mm_load_ss((const float *)(u32)(EBP + 16)));  // @1_5460b0
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_ESI, 4);  // @2_5460b0
  esi = ecx;  // @3_5460b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_5460b0
  __builtin_memcpy((void *)(u32)(EBP - 28), &SENT_EDI, 4);  // @5_5460b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_5460b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6792876)));  // @7_5460b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6806020)));  // @8_5460b0
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @9_5460b0
  _mm_store_sd((double *)(u32)(EBP - 8), _mm_castps_pd(x0));  // @10_5460b0
  eax = ext_634d76_cdecl0();  // @11_5460b0
  ecx = edx = 0;  // @12_5460b0
  x0 = _mm_cvtsd_ss(x0, _mm_castps_pd(x0));  // @13_5460b0
  _mm_store_ss((float *)(u32)(EBP - 12), x0);  // @14_5460b0
  _mm_store_ss((float *)(u32)(esi), x0);  // @15_5460b0
  x0 = _mm_castpd_ps(_mm_load_sd((const double *)(u32)(EBP - 8)));  // @16_5460b0
  eax = ext_634d70_cdecl0();  // @17_5460b0
  ecx = edx = 0;  // @18_5460b0
  x0 = _mm_cvtsd_ss(x0, _mm_castps_pd(x0));  // @19_5460b0
  _mm_store_ss((float *)(u32)(EBP - 4), x0);  // @20_5460b0
  _mm_store_ss((float *)(u32)(esi + 8), x0);  // @21_5460b0
  x0 = _mm_load_ss((const float *)(u32)(EBP + 20));  // @22_5460b0
  x0 = _mm_add_ss(x0, _mm_load_ss((const float *)(u32)(EBP + 24)));  // @23_5460b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6792876)));  // @24_5460b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6806020)));  // @25_5460b0
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @26_5460b0
  eax = ext_634dac_cdecl0();  // @27_5460b0
  ecx = edx = 0;  // @28_5460b0
  x2 = _mm_load_ss((const float *)(u32)(EBP - 4));  // @29_5460b0
  x3 = _mm_setzero_ps();  // @30_5460b0
  x1 = _mm_castpd_ps(_mm_cvtps_pd(x2));  // @31_5460b0
  x0 = _mm_castpd_ps(_mm_mul_sd(_mm_castps_pd(x0), _mm_castps_pd(x1)));  // @32_5460b0
  x1 = _mm_setzero_ps();  // @33_5460b0
  x3 = _mm_cvtsd_ss(x3, _mm_castps_pd(x0));  // @34_5460b0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 12));  // @35_5460b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @36_5460b0
  _mm_store_ss((float *)(u32)(esi + 4), x3);  // @37_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @38_5460b0
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L546169;  // @39_5460b0
  fa_ = _mm_cvtss_f32(x3); fb_ = _mm_cvtss_f32(x1);  // @40_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @41_5460b0
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L546169;  // @42_5460b0
  fa_ = _mm_cvtss_f32(x2); fb_ = _mm_cvtss_f32(x1);  // @43_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @44_5460b0
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L5461a5;  // @45_5460b0
  L546169:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @47_5460b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @48_5460b0
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx), 4); (double)v; });  // @49_5460b0
  T[0] = (T[0] * T[0]);  // @50_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), 4); (double)v; });  // @51_5460b0
  T[1] = (T[1] * T[1]);  // @52_5460b0
  T[0] = (T[0] + T[1]);  // @53_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), 4); (double)v; });  // @54_5460b0
  T[1] = (T[1] * T[1]);  // @55_5460b0
  T[0] = (T[0] + T[1]);  // @56_5460b0
  T[0] = _mm_cvtsd_f64(_mm_sqrt_sd(_mm_setzero_pd(), _mm_set_sd(T[0])));  // @57_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); (double)v; });  // @58_5460b0
  T[0] = (T[0] / T[1]);  // @59_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx), 4); (double)v; });  // @60_5460b0
  T[1] = (T[1] * T[2]);  // @61_5460b0
  { float v = (float)T[2]; __builtin_memcpy((void *)(u32)(ecx), &v, 4); }  // @62_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), 4); (double)v; });  // @63_5460b0
  T[1] = (T[1] * T[2]);  // @64_5460b0
  { float v = (float)T[2]; __builtin_memcpy((void *)(u32)(ecx + 4), &v, 4); }  // @65_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), 4); (double)v; });  // @66_5460b0
  T[1] = (T[1] * T[2]);  // @67_5460b0
  { float v = (float)T[1]; __builtin_memcpy((void *)(u32)(ecx + 8), &v, 4); }  // @68_5460b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @69_5460b0
  L5461a5:;
  x0 = _mm_load_ss((const float *)(u32)(esi));  // @71_5460b0
  edx = (u32)(esi + 24);  // @72_5460b0
  x0 = _mm_xor_ps(x0, _mm_loadu_ps((const float *)(u32)(6795072)));  // @73_5460b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @74_5460b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @75_5460b0
  _mm_store_ss((float *)(u32)(esi + 32), x0);  // @76_5460b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @77_5460b0
  x0 = _mm_load_ss((const float *)(u32)(edx));  // @78_5460b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @79_5460b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @80_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @81_5460b0
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L5461f0;  // @82_5460b0
  x0 = _mm_load_ss((const float *)(u32)(edx + 4));  // @83_5460b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @84_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @85_5460b0
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L5461f0;  // @86_5460b0
  x0 = _mm_load_ss((const float *)(u32)(edx + 8));  // @87_5460b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @88_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @89_5460b0
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L54622c;  // @90_5460b0
  L5461f0:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @92_5460b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @93_5460b0
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx), 4); (double)v; });  // @94_5460b0
  T[0] = (T[0] * T[0]);  // @95_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), 4); (double)v; });  // @96_5460b0
  T[1] = (T[1] * T[1]);  // @97_5460b0
  T[0] = (T[0] + T[1]);  // @98_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), 4); (double)v; });  // @99_5460b0
  T[1] = (T[1] * T[1]);  // @100_5460b0
  T[0] = (T[0] + T[1]);  // @101_5460b0
  T[0] = _mm_cvtsd_f64(_mm_sqrt_sd(_mm_setzero_pd(), _mm_set_sd(T[0])));  // @102_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); (double)v; });  // @103_5460b0
  T[0] = (T[0] / T[1]);  // @104_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx), 4); (double)v; });  // @105_5460b0
  T[1] = (T[1] * T[2]);  // @106_5460b0
  { float v = (float)T[2]; __builtin_memcpy((void *)(u32)(ecx), &v, 4); }  // @107_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), 4); (double)v; });  // @108_5460b0
  T[1] = (T[1] * T[2]);  // @109_5460b0
  { float v = (float)T[2]; __builtin_memcpy((void *)(u32)(ecx + 4), &v, 4); }  // @110_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), 4); (double)v; });  // @111_5460b0
  T[1] = (T[1] * T[2]);  // @112_5460b0
  { float v = (float)T[1]; __builtin_memcpy((void *)(u32)(ecx + 8), &v, 4); }  // @113_5460b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @114_5460b0
  L54622c:;
  edi = (u32)(esi + 12);  // @116_5460b0
  p0_ = edx;  // @117_5460b0
  edx = esi;  // @118_5460b0
  ecx = edi;  // @119_5460b0
  eax = ext_446ee0_fastcall3(ecx, edx, (u32)(p0_));  // @120_5460b0
  ecx = edx = 0;  // @121_5460b0
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @122_5460b0
  x1 = _mm_setzero_ps();  // @123_5460b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @124_5460b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @125_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @126_5460b0
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L546268;  // @127_5460b0
  x0 = _mm_load_ss((const float *)(u32)(edi + 4));  // @128_5460b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @129_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @130_5460b0
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L546268;  // @131_5460b0
  x0 = _mm_load_ss((const float *)(u32)(edi + 8));  // @132_5460b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @133_5460b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @134_5460b0
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L5462a4;  // @135_5460b0
  L546268:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @137_5460b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @138_5460b0
  T[0] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx), 4); (double)v; });  // @139_5460b0
  T[0] = (T[0] * T[0]);  // @140_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), 4); (double)v; });  // @141_5460b0
  T[1] = (T[1] * T[1]);  // @142_5460b0
  T[0] = (T[0] + T[1]);  // @143_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), 4); (double)v; });  // @144_5460b0
  T[1] = (T[1] * T[1]);  // @145_5460b0
  T[0] = (T[0] + T[1]);  // @146_5460b0
  T[0] = _mm_cvtsd_f64(_mm_sqrt_sd(_mm_setzero_pd(), _mm_set_sd(T[0])));  // @147_5460b0
  T[1] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); (double)v; });  // @148_5460b0
  T[0] = (T[0] / T[1]);  // @149_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx), 4); (double)v; });  // @150_5460b0
  T[1] = (T[1] * T[2]);  // @151_5460b0
  { float v = (float)T[2]; __builtin_memcpy((void *)(u32)(ecx), &v, 4); }  // @152_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), 4); (double)v; });  // @153_5460b0
  T[1] = (T[1] * T[2]);  // @154_5460b0
  { float v = (float)T[2]; __builtin_memcpy((void *)(u32)(ecx + 4), &v, 4); }  // @155_5460b0
  T[2] = ({ float v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), 4); (double)v; });  // @156_5460b0
  T[1] = (T[1] * T[2]);  // @157_5460b0
  { float v = (float)T[1]; __builtin_memcpy((void *)(u32)(ecx + 8), &v, 4); }  // @158_5460b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @159_5460b0
  L5462a4:;
  x0 = _mm_load_ss((const float *)(u32)(EBP + 16));  // @161_5460b0
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(EBP + 12)));  // @162_5460b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6792876)));  // @163_5460b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6806020)));  // @164_5460b0
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @165_5460b0
  eax = ext_634dac_cdecl0();  // @166_5460b0
  ecx = edx = 0;  // @167_5460b0
  x1 = _mm_castpd_ps(_mm_load_sd((const double *)(u32)(6784528)));  // @168_5460b0
  x1 = _mm_castpd_ps(_mm_div_sd(_mm_castps_pd(x1), _mm_castps_pd(x0)));  // @169_5460b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @170_5460b0
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x1));  // @171_5460b0
  _mm_store_ss((float *)(u32)(eax), x0);  // @172_5460b0
  x0 = _mm_load_ss((const float *)(u32)(EBP + 24));  // @173_5460b0
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(EBP + 20)));  // @174_5460b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6792876)));  // @175_5460b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6806020)));  // @176_5460b0
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @177_5460b0
  eax = ext_634dac_cdecl0();  // @178_5460b0
  ecx = edx = 0;  // @179_5460b0
  x1 = _mm_castpd_ps(_mm_load_sd((const double *)(u32)(6784528)));  // @180_5460b0
  x1 = _mm_castpd_ps(_mm_div_sd(_mm_castps_pd(x1), _mm_castps_pd(x0)));  // @181_5460b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @182_5460b0
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x1));  // @183_5460b0
  _mm_store_ss((float *)(u32)(eax), x0);  // @184_5460b0
  __asm__ volatile("" :: "Yz"(x0));  // @185_5460b0
  return eax;  // @186_5460b0
}
PCREG(5460b0, lifted_5460b0);

extern "C" u32 THISCALL lifted_4a3e80(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4a3e80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @1_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; }) == (u32)(0)) goto L4a3e99;  // @2_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 474), &v, sizeof v); }  // @3_4a3e80
  L4a3e99:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 474), sizeof v); (u32)v; }) != (u32)(0)) goto L4a420f;  // @5_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4a3e80
  x0 = _mm_load_ss((const float *)(u32)(edi + 436));  // @7_4a3e80
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784544)));  // @8_4a3e80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @9_4a3e80
  ecx = esi;  // @10_4a3e80
  eax = (u32)_mm_cvtss_si32(x0);  // @11_4a3e80
  ecx = (ecx - eax);  // @12_4a3e80
  if ((s32)ecx <= (s32)(u32)(71)) goto L4a420e;  // @13_4a3e80
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)esi));  // @14_4a3e80
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @15_4a3e80
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784484)));  // @16_4a3e80
  _mm_store_ss((float *)(u32)(edi + 436), x0);  // @17_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; }) == (u32)(0)) goto L4a3f04;  // @18_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 472), sizeof v); (u32)v; }) != (u32)(0)) goto L4a3f04;  // @19_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 472), &v, sizeof v); }  // @20_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 475), &v, sizeof v); }  // @21_4a3e80
  L4a3f04:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_4a3e80
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @24_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4a3e80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @27_4a3e80
  ecx = edx = 0;  // @28_4a3e80
  ecx = (u32)(EBP - 4);  // @29_4a3e80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @30_4a3e80
  p0_ = ecx;  // @31_4a3e80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_4a3e80
  ecx = eax;  // @33_4a3e80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6880492), (u32)(p0_));  // @34_4a3e80
  ecx = edx = 0;  // @35_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @36_4a3e80
  eax = (u32)(1);  // @37_4a3e80
  if ((ecx & ecx) == 0) ecx = eax;  // @38_4a3e80
  eax = 0;  // @39_4a3e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @40_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @41_4a3e80
  if ((s32)(ecx & ecx) <= 0) goto L4a4009;  // @42_4a3e80
  L4a3f51:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_4a3e80
  ecx = edi;  // @45_4a3e80
  p1_ = eax;  // @46_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 136)))(ecx, (u32)(p1_));  // @47_4a3e80
  ecx = edx = 0;  // @48_4a3e80
  p2_ = eax;  // @49_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @50_4a3e80
  ecx = edi;  // @51_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p2_));  // @52_4a3e80
  ecx = edx = 0;  // @53_4a3e80
  ebx = (ebx & 0xff);  // @54_4a3e80
  eax = (u32)(1);  // @55_4a3e80
  if (((eax & 0xff) & (eax & 0xff)) != 0) ebx = eax;  // @56_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @57_4a3e80
  eax = (eax + 1);  // @58_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @59_4a3e80
  if ((s32)eax < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; })) goto L4a3f51;  // @60_4a3e80
  if (((ebx & 0xff) & (ebx & 0xff)) == 0) goto L4a4009;  // @61_4a3e80
  x0 = _mm_load_ss((const float *)(u32)(edi + 444));  // @62_4a3e80
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6784464)));  // @63_4a3e80
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @64_4a3e80
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4a3fcb;  // @65_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 472), sizeof v); (u32)v; }) != (u32)(0)) goto L4a3fcb;  // @66_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @67_4a3e80
  eax = ext_44c2b0_thiscall1(ecx);  // @68_4a3e80
  ecx = edx = 0;  // @69_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @70_4a3e80
  if ((ecx & ecx) == 0) goto L4a3fbd;  // @71_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_4a3e80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @73_4a3e80
  ecx = edx = 0;  // @74_4a3e80
  L4a3fbd:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 472), &v, sizeof v); }  // @76_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 475), &v, sizeof v); }  // @77_4a3e80
  L4a3fcb:;
  x0 = _mm_load_ss((const float *)(u32)(6785112));  // @79_4a3e80
  x0 = _mm_div_ss(x0, _mm_load_ss((const float *)(u32)(edi + 448)));  // @80_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_4a3e80
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(eax + 72)));  // @82_4a3e80
  x0 = _mm_add_ss(x0, _mm_load_ss((const float *)(u32)(edi + 444)));  // @83_4a3e80
  _mm_store_ss((float *)(u32)(edi + 444), x0);  // @84_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 473), sizeof v); (u32)v; }) != (u32)(0)) goto L4a4053;  // @85_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 473), &v, sizeof v); }  // @86_4a3e80
  goto L4a4049;  // @87_4a3e80
  L4a4009:;
  x1 = _mm_load_ss((const float *)(u32)(6785112));  // @89_4a3e80
  x1 = _mm_div_ss(x1, _mm_load_ss((const float *)(u32)(edi + 452)));  // @90_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @91_4a3e80
  x0 = _mm_load_ss((const float *)(u32)(edi + 444));  // @92_4a3e80
  x1 = _mm_mul_ss(x1, _mm_load_ss((const float *)(u32)(eax + 72)));  // @93_4a3e80
  x0 = _mm_sub_ss(x0, x1);  // @94_4a3e80
  _mm_store_ss((float *)(u32)(edi + 444), x0);  // @95_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 473), sizeof v); (u32)v; }) == (u32)(0)) goto L4a4053;  // @96_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 473), &v, sizeof v); }  // @97_4a3e80
  L4a4049:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @99_4a3e80
  ecx = edi;  // @100_4a3e80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 140)))(ecx, (u32)(0), (u32)(1));  // @101_4a3e80
  ecx = edx = 0;  // @102_4a3e80
  L4a4053:;
  x0 = _mm_load_ss((const float *)(u32)(edi + 444));  // @104_4a3e80
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6785112)));  // @105_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 476), &v, sizeof v); }  // @106_4a3e80
  if (!(fa_ > fb_)) goto L4a4078;  // @107_4a3e80
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi + 444), &v, sizeof v); }  // @108_4a3e80
  goto L4a40d2;  // @109_4a3e80
  L4a4078:;
  x1 = _mm_setzero_ps();  // @111_4a3e80
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x0);  // @112_4a3e80
  if (!(fa_ >= fb_)) goto L4a40d9;  // @113_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 472), sizeof v); (u32)v; }) == (u32)(0)) goto L4a40c8;  // @114_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @115_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @116_4a3e80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 132), &v, sizeof v); }  // @117_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @118_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; }) == (u32)(0)) goto L4a40a7;  // @119_4a3e80
  eax = ext_44c370_thiscall1(ecx);  // @120_4a3e80
  ecx = edx = 0;  // @121_4a3e80
  L4a40a7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @123_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 472), &v, sizeof v); }  // @124_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 475), &v, sizeof v); }  // @125_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @126_4a3e80
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }) & (u32)(8)) != 0) goto L4a40c8;  // @127_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 474), &v, sizeof v); }  // @128_4a3e80
  L4a40c8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 444), &v, sizeof v); }  // @130_4a3e80
  L4a40d2:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 476), &v, sizeof v); }  // @132_4a3e80
  L4a40d9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 476), sizeof v); (u32)v; }) == (u32)(0)) goto L4a41db;  // @134_4a3e80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 475), sizeof v); (u32)v; }) != (u32)(0)) goto L4a4128;  // @135_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @136_4a3e80
  x0 = _mm_load_ss((const float *)(u32)(edi + 440));  // @137_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @138_4a3e80
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(ecx + 132)));  // @139_4a3e80
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @140_4a3e80
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L4a4128;  // @141_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 444), sizeof v); (u32)v; });  // @142_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 132), &v, sizeof v); }  // @143_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 444), sizeof v); (u32)v; });  // @144_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 440), &v, sizeof v); }  // @145_4a3e80
  __asm__ volatile("" :: "Yz"(x0));  // @146_4a3e80
  return eax;  // @147_4a3e80
  L4a4128:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @149_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 475), &v, sizeof v); }  // @150_4a3e80
  if ((ecx & ecx) == 0) goto L4a414d;  // @151_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, (u32)(0));  // @153_4a3e80
  ecx = edx = 0;  // @154_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @155_4a3e80
  x0 = _mm_load_ss((const float *)(u32)(eax + 210));  // @156_4a3e80
  goto L4a4184;  // @157_4a3e80
  L4a414d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @159_4a3e80
  if ((ecx & ecx) == 0) goto L4a416b;  // @160_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(0));  // @162_4a3e80
  ecx = edx = 0;  // @163_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @164_4a3e80
  x0 = _mm_load_ss((const float *)(u32)(eax + 213));  // @165_4a3e80
  goto L4a4184;  // @166_4a3e80
  L4a416b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @168_4a3e80
  if ((ecx & ecx) == 0) goto L4a41ac;  // @169_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(0));  // @171_4a3e80
  ecx = edx = 0;  // @172_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @173_4a3e80
  x0 = _mm_load_ss((const float *)(u32)(eax + 121));  // @174_4a3e80
  L4a4184:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @176_4a3e80
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 444)));  // @177_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @178_4a3e80
  _mm_store_ss((float *)(u32)(eax + 132), x0);  // @179_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 444), sizeof v); (u32)v; });  // @180_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 440), &v, sizeof v); }  // @181_4a3e80
  __asm__ volatile("" :: "Yz"(x0));  // @182_4a3e80
  return eax;  // @183_4a3e80
  L4a41ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @185_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @186_4a3e80
  x0 = _mm_load_ss((const float *)(u32)(eax + 132));  // @187_4a3e80
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(edi + 444)));  // @188_4a3e80
  _mm_store_ss((float *)(u32)(edi + 440), x0);  // @189_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @190_4a3e80
  _mm_store_ss((float *)(u32)(eax + 132), x0);  // @191_4a3e80
  __asm__ volatile("" :: "Yz"(x0));  // @192_4a3e80
  return eax;  // @193_4a3e80
  L4a41db:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @195_4a3e80
  if ((ecx & ecx) == 0) goto L4a41ec;  // @196_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @197_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, (u32)(1));  // @198_4a3e80
  ecx = edx = 0;  // @199_4a3e80
  L4a41ec:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @201_4a3e80
  if ((ecx & ecx) == 0) goto L4a41fd;  // @202_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @203_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(1));  // @204_4a3e80
  ecx = edx = 0;  // @205_4a3e80
  L4a41fd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @207_4a3e80
  if ((ecx & ecx) == 0) goto L4a420e;  // @208_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(1));  // @210_4a3e80
  ecx = edx = 0;  // @211_4a3e80
  L4a420e:;
  L4a420f:;
  __asm__ volatile("" :: "Yz"(x0));  // @214_4a3e80
  return eax;  // @215_4a3e80
}
PCREG(4a3e80, lifted_4a3e80);

extern "C" u32 THISCALL lifted_48fcb0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x667cb1);  // @h_48fcb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 292), &SENT_ESI, 4);  // @0_48fcb0
  __builtin_memcpy((void *)(u32)(EBP - 296), &SENT_EDI, 4);  // @1_48fcb0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @2_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @3_48fcb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_48fcb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_48fcb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L48fcfb;  // @6_48fcb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @7_48fcb0
  L48fcfb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @11_48fcb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6870936), (u32)(5263));  // @12_48fcb0
  ecx = edx = 0;  // @13_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @14_48fcb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @15_48fcb0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 16));  // @16_48fcb0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6785112)));  // @17_48fcb0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @18_48fcb0
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L48fe06;  // @19_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @20_48fcb0
  ecx = (u32)(EBP - 272);  // @21_48fcb0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }));  // @22_48fcb0
  ecx = edx = 0;  // @23_48fcb0
  ecx = (u32)(EBP - 144);  // @24_48fcb0
  reg.state = (s32)((u32)(0));  // @25_48fcb0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6873736));  // @26_48fcb0
  ecx = edx = 0;  // @27_48fcb0
  eax = (u32)(EBP - 144);  // @28_48fcb0
  reg.state = (s32)((u32)(1));  // @29_48fcb0
  p0_ = eax;  // @30_48fcb0
  ecx = (u32)(EBP - 272);  // @31_48fcb0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p0_));  // @32_48fcb0
  ecx = edx = 0;  // @33_48fcb0
  ecx = (u32)(EBP - 144);  // @34_48fcb0
  reg.state = (s32)((u32)(0));  // @35_48fcb0
  eax = ext_4cbec0_thiscall1(ecx);  // @36_48fcb0
  ecx = edx = 0;  // @37_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @38_48fcb0
  ecx = (u32)(6801640);  // @39_48fcb0
  if ((eax & eax) != 0) ecx = eax;  // @40_48fcb0
  p1_ = ecx;  // @41_48fcb0
  ecx = (u32)(EBP - 144);  // @42_48fcb0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @43_48fcb0
  ecx = edx = 0;  // @44_48fcb0
  eax = (u32)(EBP - 144);  // @45_48fcb0
  reg.state = (s32)((u32)(2));  // @46_48fcb0
  p2_ = eax;  // @47_48fcb0
  ecx = (u32)(EBP - 272);  // @48_48fcb0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p2_));  // @49_48fcb0
  ecx = edx = 0;  // @50_48fcb0
  ecx = (u32)(EBP - 144);  // @51_48fcb0
  reg.state = (s32)((u32)(0));  // @52_48fcb0
  eax = ext_4cbec0_thiscall1(ecx);  // @53_48fcb0
  ecx = edx = 0;  // @54_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @55_48fcb0
  eax = ext_494b40_thiscall2(ecx, (u32)(6873740));  // @56_48fcb0
  ecx = edx = 0;  // @57_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_48fcb0
  ecx = edi;  // @59_48fcb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 352)))(ecx);  // @60_48fcb0
  ecx = edx = 0;  // @61_48fcb0
  ecx = (u32)(EBP - 272);  // @62_48fcb0
  eax = ext_4cc1d0_thiscall1(ecx);  // @63_48fcb0
  ecx = edx = 0;  // @64_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @65_48fcb0
  p3_ = eax;  // @66_48fcb0
  eax = ext_494ac0_thiscall2(ecx, (u32)(p3_));  // @67_48fcb0
  ecx = edx = 0;  // @68_48fcb0
  ecx = (u32)(EBP - 272);  // @69_48fcb0
  reg.state = (s32)((u32)(4294967295));  // @70_48fcb0
  eax = ext_4cbec0_thiscall1(ecx);  // @71_48fcb0
  ecx = edx = 0;  // @72_48fcb0
  goto L48fe10;  // @73_48fcb0
  L48fe06:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_48fcb0
  ecx = edi;  // @76_48fcb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 352)))(ecx);  // @77_48fcb0
  ecx = edx = 0;  // @78_48fcb0
  L48fe10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @80_48fcb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L48feb3;  // @81_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @84_48fcb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6870936), (u32)(5280));  // @85_48fcb0
  ecx = edx = 0;  // @86_48fcb0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }));  // @87_48fcb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @88_48fcb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; }) != (u32)(0)) goto L48fea8;  // @89_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @90_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @91_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @93_48fcb0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(0));  // @94_48fcb0
  ecx = edx = 0;  // @95_48fcb0
  eax = (eax + (u32)(-4));  // @96_48fcb0
  x0 = _mm_setzero_ps();  // @97_48fcb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @98_48fcb0
  p4_ = edi;  // @99_48fcb0
  _mm_storeu_ps((float *)(u32)(eax), x0);  // @100_48fcb0
  _mm_storel_epi64((__m128i *)(u32)(eax + 16), _mm_castps_si128(x0));  // @101_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @103_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; });  // @105_48fcb0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p4_));  // @106_48fcb0
  ecx = edx = 0;  // @107_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @108_48fcb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @109_48fcb0
  ecx = esi;  // @110_48fcb0
  eax = ext_41e680_thiscall1(ecx);  // @111_48fcb0
  ecx = edx = 0;  // @112_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @113_48fcb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @114_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @115_48fcb0
  { u32 v = (u32)((u32)(134217744)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @116_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @117_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @118_48fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @119_48fcb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @120_48fcb0
  L48fea8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @122_48fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @123_48fcb0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) + ecx)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @124_48fcb0
  L48feb3:;
  SEH_LEAVE();  // @126_48fcb0
  ext_633654(G(u32, 0x6f5630));  // @127_48fcb0
  __asm__ volatile("" :: "Yz"(x0));  // @128_48fcb0
  return eax;  // @129_48fcb0
}
PCREG(48fcb0, lifted_48fcb0);

extern "C" u32 THISCALL lifted_660cf0(u32 ecx_in) {
  SEH_ENTER(0x66ee2f);  // @h_660cf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 32), &SENT_ESI, 4);  // @0_660cf0
  esi = ecx;  // @1_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_660cf0
  x1 = _mm_setzero_ps();  // @3_660cf0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 2503));  // @4_660cf0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @5_660cf0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @6_660cf0
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L660f2e;  // @7_660cf0
  x0 = _mm_load_ss((const float *)(u32)(ecx + 2499));  // @8_660cf0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @9_660cf0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @10_660cf0
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L660f2e;  // @11_660cf0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L660f2e;  // @12_660cf0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L660e66;  // @13_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_660cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7096616), (u32)(130));  // @16_660cf0
  ecx = edx = 0;  // @17_660cf0
  p0_ = eax;  // @18_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_660cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(7096720));  // @20_660cf0
  ecx = edx = 0;  // @21_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @22_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_660cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7096616), (u32)(131));  // @24_660cf0
  ecx = edx = 0;  // @25_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @26_660cf0
  ecx = (ecx + (u32)(440));  // @27_660cf0
  p1_ = ecx;  // @28_660cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @29_660cf0
  p2_ = eax;  // @30_660cf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(p2_), (u32)(7096788), (u32)(p1_));  // @31_660cf0
  ecx = edx = 0;  // @32_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @33_660cf0
  if ((ecx & ecx) == 0) goto L660dbc;  // @34_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @36_660cf0
  ecx = edx = 0;  // @37_660cf0
  L660dbc:;
  eax = ext_41e290_cdecl1((u32)(40));  // @39_660cf0
  ecx = edx = 0;  // @40_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @41_660cf0
  reg.state = (s32)((u32)(0));  // @42_660cf0
  if ((eax & eax) == 0) goto L660de3;  // @43_660cf0
  ecx = eax;  // @44_660cf0
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(122));  // @45_660cf0
  ecx = edx = 0;  // @46_660cf0
  ecx = eax;  // @47_660cf0
  goto L660de5;  // @48_660cf0
  L660de3:;
  ecx = 0;  // @50_660cf0
  L660de5:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @52_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_660cf0
  reg.state = (s32)((u32)(4294967295));  // @54_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @55_660cf0
  ecx = edx = 0;  // @56_660cf0
  x0 = _mm_loadu_ps((const float *)(u32)(7096808));  // @57_660cf0
  _mm_storeu_ps((float *)(u32)(eax + 444), x0);  // @58_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7096824), sizeof v); (u32)v; });  // @59_660cf0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 460), &v, sizeof v); }  // @60_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @61_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @62_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @63_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @64_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @65_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 32), &v, sizeof v); }  // @66_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 36), &v, sizeof v); }  // @67_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 40), &v, sizeof v); }  // @68_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 464), &v, sizeof v); }  // @69_660cf0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @70_660cf0
  SEH_LEAVE();  // @71_660cf0
  __asm__ volatile("" :: "Yz"(x0));  // @72_660cf0
  return eax;  // @73_660cf0
  L660e66:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @75_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_660cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @77_660cf0
  ecx = edx = 0;  // @78_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @79_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @80_660cf0
  if ((ecx & ecx) == 0) goto L660f17;  // @81_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_660cf0
  edx = (u32)(EBP - 28);  // @83_660cf0
  p3_ = edx;  // @84_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p3_));  // @85_660cf0
  ecx = edx = 0;  // @86_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @87_660cf0
  edx = (u32)(EBP - 28);  // @88_660cf0
  p4_ = edx;  // @89_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @91_660cf0
  ecx = edx = 0;  // @92_660cf0
  edx = eax;  // @93_660cf0
  if ((edx & edx) == 0) goto L660f17;  // @94_660cf0
  L660ea0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @96_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @97_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*8 + 48), &v, sizeof v); }  // @98_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @99_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*8 + 52), &v, sizeof v); }  // @100_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @101_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @102_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @103_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @104_660cf0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 477), sizeof v); (u32)v; }) == (u32)(0)) goto L660f3e;  // @105_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @106_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 485), &v, sizeof v); }  // @107_660cf0
  L660edf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 477), &v, sizeof v); }  // @109_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @110_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 36), &v, sizeof v); }  // @111_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 40), &v, sizeof v); }  // @112_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 44), &v, sizeof v); }  // @113_660cf0
  L660f05:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @115_660cf0
  edx = (u32)(EBP - 28);  // @116_660cf0
  p5_ = edx;  // @117_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p5_));  // @119_660cf0
  ecx = edx = 0;  // @120_660cf0
  edx = eax;  // @121_660cf0
  if ((edx & edx) != 0) goto L660ea0;  // @122_660cf0
  L660f17:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @124_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @125_660cf0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) != (u32)(50)) goto L660f2e;  // @126_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @127_660cf0
  L660f2e:;
  SEH_LEAVE();  // @129_660cf0
  __asm__ volatile("" :: "Yz"(x0));  // @130_660cf0
  return eax;  // @131_660cf0
  L660f3e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 485), sizeof v); (u32)v; });  // @133_660cf0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L660edf;  // @134_660cf0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 481), sizeof v); (u32)v; }) != (u32)(0)) goto L660edf;  // @135_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @136_660cf0
  edx = (u32)(EBP - 28);  // @137_660cf0
  p6_ = edx;  // @138_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(p6_));  // @140_660cf0
  ecx = edx = 0;  // @141_660cf0
  goto L660f05;  // @142_660cf0
}
PCREG(660cf0, lifted_660cf0);

