// batch200169.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double FASTCALL ext_4e0830_fastcall2_f(u32, u32) __asm__("ext_4e0830");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_60f040_fastcall3(u32, u32, u32) __asm__("ext_60f040");
extern "C" u32 FASTCALL ext_60f0b0_fastcall2(u32, u32) __asm__("ext_60f0b0");
extern "C" u32 FASTCALL ext_60feb0_fastcall4(u32, u32, u32, u32) __asm__("ext_60feb0");
extern "C" u32 FASTCALL ext_60ff30_fastcall4(u32, u32, u32, u32) __asm__("ext_60ff30");
extern "C" u32 STDCALL ext_410f26_stdcall3(u32, u32, u32) __asm__("ext_410f26");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_5d6960_stdcall4(u32, u32, u32, u32) __asm__("ext_5d6960");
extern "C" u32 THISCALL ext_446320_thiscall3(u32, u32, u32) __asm__("ext_446320");
extern "C" u32 THISCALL ext_4569b0_thiscall1(u32) __asm__("ext_4569b0");
extern "C" u32 THISCALL ext_456b70_thiscall3(u32, u32, u32) __asm__("ext_456b70");
extern "C" u32 THISCALL ext_4cc500_thiscall1(u32) __asm__("ext_4cc500");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d9ce0_thiscall1(u32) __asm__("ext_4d9ce0");
extern "C" u32 THISCALL ext_4da720_thiscall2(u32, u32) __asm__("ext_4da720");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e3180_thiscall1(u32) __asm__("ext_4e3180");
extern "C" u32 THISCALL ext_4e49d0_thiscall2(u32, u32) __asm__("ext_4e49d0");
extern "C" u32 THISCALL ext_4f12e0_thiscall2(u32, u32) __asm__("ext_4f12e0");
extern "C" u32 THISCALL ext_609a70_thiscall1(u32) __asm__("ext_609a70");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 ext_44a1f0_cdecl0(void) __asm__("ext_44a1f0");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" u32 ext_634d7c_cdecl0(void) __asm__("ext_634d7c");
extern "C" u32 ext_634db8_cdecl0(void) __asm__("ext_634db8");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4f4790(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ecx;  // @0_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @1_4f4790
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 176), sizeof v); (u32)v; }) == (u32)(0)) goto L4f4973;  // @2_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 172), sizeof v); (u32)v; });  // @3_4f4790
  if ((ecx & ecx) == 0) goto L4f4973;  // @4_4f4790
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) == (u32)(0)) goto L4f4973;  // @5_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4f4790
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @9_4f4790
  ecx = edx = 0;  // @10_4f4790
  ecx = (u32)(EBP - 24);  // @11_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @12_4f4790
  p0_ = ecx;  // @13_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_4f4790
  ecx = eax;  // @15_4f4790
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6918004), (u32)(p0_));  // @16_4f4790
  ecx = edx = 0;  // @17_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @21_4f4790
  ecx = edx = 0;  // @22_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @23_4f4790
  edx = 0;  // @24_4f4790
  esi = 0;  // @25_4f4790
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 176), sizeof v); (u32)v; })));  // @26_4f4790
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @27_4f4790
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(eax + 155)));  // @28_4f4790
  eax = (u32)_mm_cvtss_si32(x0);  // @29_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @30_4f4790
  L4f4823:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; });  // @32_4f4790
  edi = 0;  // @33_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @34_4f4790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @35_4f4790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @36_4f4790
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) == (u32)(0)) goto L4f48fb;  // @37_4f4790
  L4f4840:;
  ecx = (u32)(EBP - 20);  // @39_4f4790
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @40_4f4790
  eax = ext_4cc500_thiscall1(ecx);  // @41_4f4790
  ecx = edx = 0;  // @42_4f4790
  edx = eax;  // @43_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @44_4f4790
  eax = (eax - ebx);  // @45_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @46_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @47_4f4790
  if (edx != (u32)(10)) goto L4f4866;  // @48_4f4790
  ecx = 0;  // @49_4f4790
  edi = 0;  // @50_4f4790
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @51_4f4790
  goto L4f48ad;  // @52_4f4790
  L4f4866:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @54_4f4790
  p1_ = edx;  // @55_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 159), sizeof v); (u32)v; });  // @56_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 640)))(ecx, (u32)(p1_));  // @58_4f4790
  ecx = edx = 0;  // @59_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @60_4f4790
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }));  // @61_4f4790
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @62_4f4790
  ecx = (ecx + eax);  // @63_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @64_4f4790
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @65_4f4790
  if (eax == (u32)(32)) goto L4f4894;  // @66_4f4790
  if (eax != (u32)(9)) goto L4f48aa;  // @67_4f4790
  L4f4894:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @69_4f4790
  edi = ebx;  // @70_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @71_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @72_4f4790
  if ((edx & edx) != 0) edi = esi;  // @73_4f4790
  goto L4f48b0;  // @74_4f4790
  L4f48aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @76_4f4790
  L4f48ad:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @78_4f4790
  L4f48b0:;
  if ((s32)ecx > (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; })) goto L4f48cf;  // @80_4f4790
  if ((edx & edx) == 0) goto L4f48c7;  // @81_4f4790
  p2_ = eax;  // @82_4f4790
  p3_ = ebx;  // @83_4f4790
  p4_ = esi;  // @84_4f4790
  eax = ext_634d22_cdecl3((u32)(p4_), (u32)(p3_), (u32)(p2_));  // @85_4f4790
  ecx = edx = 0;  // @86_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @87_4f4790
  L4f48c7:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @89_4f4790
  esi = (esi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @90_4f4790
  goto L4f48ef;  // @91_4f4790
  L4f48cf:;
  if ((edi & edi) == 0) goto L4f48e0;  // @93_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @94_4f4790
  { u8 v = (u8)((u32)(10)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @95_4f4790
  edi = 0;  // @96_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @97_4f4790
  goto L4f48ef;  // @98_4f4790
  L4f48e0:;
  if ((edx & edx) == 0) goto L4f48e7;  // @100_4f4790
  { u8 v = (u8)((u32)(10)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @101_4f4790
  L4f48e7:;
  esi = (esi + 1);  // @103_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @104_4f4790
  L4f48ef:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(0)) goto L4f4840;  // @106_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @107_4f4790
  L4f48fb:;
  if ((edx & edx) != 0) goto L4f493d;  // @109_4f4790
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; }));  // @110_4f4790
  if (esi == ebx) goto L4f492b;  // @111_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @112_4f4790
  eax = (u32)(esi + 1);  // @113_4f4790
  p5_ = eax;  // @114_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, (u32)(p5_));  // @116_4f4790
  ecx = edx = 0;  // @117_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @118_4f4790
  edx = eax;  // @119_4f4790
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + edx), &v, sizeof v); }  // @120_4f4790
  esi = edx;  // @121_4f4790
  goto L4f4823;  // @122_4f4790
  L4f492b:;
  eax = ext_4f12e0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; }));  // @124_4f4790
  ecx = edx = 0;  // @125_4f4790
  __asm__ volatile("" :: "Yz"(x0));  // @126_4f4790
  return eax;  // @127_4f4790
  L4f493d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 151), sizeof v); (u32)v; });  // @129_4f4790
  if ((esi & esi) == 0) goto L4f495c;  // @130_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @131_4f4790
  p6_ = esi;  // @132_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, (u32)(p6_));  // @134_4f4790
  ecx = edx = 0;  // @135_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @136_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @137_4f4790
  L4f495c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 151), &v, sizeof v); }  // @140_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 632), sizeof v); (u32)v; });  // @141_4f4790
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @142_4f4790
  ecx = edx = 0;  // @143_4f4790
  __asm__ volatile("" :: "Yz"(x0));  // @144_4f4790
  return eax;  // @145_4f4790
  L4f4973:;
  ecx = eax;  // @147_4f4790
  eax = ext_4f12e0_thiscall2(ecx, (u32)(6781786));  // @148_4f4790
  ecx = edx = 0;  // @149_4f4790
  __asm__ volatile("" :: "Yz"(x0));  // @150_4f4790
  return eax;  // @151_4f4790
}
PCREG(4f4790, lifted_4f4790);

extern "C" u32 THISCALL lifted_456590(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_456590
  eax = (eax ^ EBP);  // @1_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_456590
  __builtin_memcpy((void *)(u32)(EBP - 84), &SENT_ESI, 4);  // @3_456590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_456590
  eax = ecx;  // @5_456590
  __builtin_memcpy((void *)(u32)(EBP - 88), &SENT_EDI, 4);  // @6_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @7_456590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @8_456590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @9_456590
  ecx = (u32)(eax + 29);  // @10_456590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @11_456590
  L4565c0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_456590
  if ((edx & edx) == 0) goto L456984;  // @14_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @15_456590
  if ((ecx & ecx) == 0) goto L456968;  // @16_456590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2077), sizeof v); (u32)v; });  // @17_456590
  ecx = (u32)((s32)ecx * (s32)(u32)(2380));  // @18_456590
  edi = (edi + (u32)(4294964916));  // @19_456590
  edi = (edi + ecx);  // @20_456590
  if (edi == 0) goto L456965;  // @21_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_456590
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @23_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @26_456590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @27_456590
  ecx = edx = 0;  // @28_456590
  edx = eax;  // @29_456590
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 81), sizeof v); (u32)v; }) == (u32)(0)) goto L456965;  // @30_456590
  x0 = _mm_load_ss((const float *)(u32)(edx + 89));  // @31_456590
  eax = (u32)(edx + 225);  // @32_456590
  x1 = _mm_load_ss((const float *)(u32)(edx + 36));  // @33_456590
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 73), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @34_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @35_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_456590
  _mm_store_ss((float *)(u32)(EBP - 80), x0);  // @37_456590
  _mm_store_ss((float *)(u32)(EBP - 64), x1);  // @38_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @39_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @41_456590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @42_456590
  ecx = edx = 0;  // @43_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @44_456590
  if ((eax & eax) == 0) goto L45665f;  // @45_456590
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 237), sizeof v); (u32)v; }) != (u32)(0)) goto L45665f;  // @46_456590
  ecx = (u32)(EBP - 76);  // @47_456590
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @48_456590
  ecx = (u32)(EBP - 60);  // @49_456590
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @50_456590
  ecx = eax;  // @51_456590
  eax = ext_456b70_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @52_456590
  ecx = edx = 0;  // @53_456590
  L45665f:;
  x1 = _mm_load_ss((const float *)(u32)(6784544));  // @55_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @56_456590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @57_456590
  L456671:;
  x4 = _mm_load_ss((const float *)(u32)(edi + 8));  // @59_456590
  x0 = x4;  // @60_456590
  x0 = _mm_mul_ss(x0, x1);  // @61_456590
  eax = (u32)_mm_cvtss_si32(x0);  // @62_456590
  if ((s32)eax >= (s32)esi) goto L4568ab;  // @63_456590
  x0 = _mm_load_ss((const float *)(u32)(edi + 2328));  // @64_456590
  ecx = esi;  // @65_456590
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784556)));  // @66_456590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @67_456590
  x5 = _mm_load_ss((const float *)(u32)(6784484));  // @68_456590
  eax = (u32)_mm_cvtss_si32(x0);  // @69_456590
  ecx = (ecx - eax);  // @70_456590
  x4 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ecx));  // @71_456590
  x4 = _mm_cvtepi32_ps(_mm_castps_si128(x4));  // @72_456590
  x4 = _mm_mul_ss(x4, x5);  // @73_456590
  _mm_store_ss((float *)(u32)(EBP - 52), x4);  // @74_456590
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) <= (u32)(0)) goto L4568ab;  // @75_456590
  edx = (u32)(edi + 24);  // @76_456590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @77_456590
  L4566d0:;
  x0 = _mm_load_ss((const float *)(u32)(edx + 12));  // @79_456590
  ecx = esi;  // @80_456590
  x3 = _mm_load_ss((const float *)(u32)(edx + 16));  // @81_456590
  x0 = _mm_mul_ss(x0, x1);  // @82_456590
  eax = (u32)_mm_cvtss_si32(x0);  // @83_456590
  x0 = x3;  // @84_456590
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(edx + 12)));  // @85_456590
  ecx = (ecx - eax);  // @86_456590
  x1 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ecx));  // @87_456590
  x1 = _mm_cvtepi32_ps(_mm_castps_si128(x1));  // @88_456590
  x1 = _mm_mul_ss(x1, x5);  // @89_456590
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x0);  // @90_456590
  if (!(fa_ >= fb_)) goto L45687e;  // @91_456590
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }) == (u32)(0)) goto L456853;  // @92_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_456590
  { u32 v = (u32)((u32)(661)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @94_456590
  { u32 v = (u32)((u32)(6827288)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @95_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @97_456590
  T[0] = ((double(THISCALL *)(u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @98_456590
  ecx = edx = 0;  // @99_456590
  x0 = _mm_load_ss((const float *)(u32)(EBP - 80));  // @100_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @101_456590
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 44), &v, 4); }  // @102_456590
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(EBP - 44)));  // @103_456590
  if (!(fa_ > fb_)) goto L456846;  // @104_456590
  x0 = _mm_load_ss((const float *)(u32)(edx + 12));  // @105_456590
  ecx = esi;  // @106_456590
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784544)));  // @107_456590
  x1 = _mm_load_ss((const float *)(u32)(EBP - 64));  // @108_456590
  eax = (u32)_mm_cvtss_si32(x0);  // @109_456590
  ecx = (ecx - eax);  // @110_456590
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6806012)));  // @111_456590
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)ecx));  // @112_456590
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @113_456590
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784484)));  // @114_456590
  _mm_store_ss((float *)(u32)(EBP - 44), x0);  // @115_456590
  if (!(fa_ >= fb_)) goto L4567d9;  // @116_456590
  x0 = _mm_mul_ss(x0, x1);  // @117_456590
  x0 = _mm_xor_ps(x0, _mm_loadu_ps((const float *)(u32)(6795072)));  // @118_456590
  x0 = _mm_castpd_ps(_mm_cvtss_sd(_mm_castps_pd(x0), x0));  // @119_456590
  eax = ext_634db8_cdecl0();  // @120_456590
  ecx = edx = 0;  // @121_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @122_456590
  x0 = _mm_cvtsd_ss(x0, _mm_castps_pd(x0));  // @123_456590
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @124_456590
  ecx = (u32)(EBP - 16);  // @125_456590
  edx = (u32)(eax - 12);  // @126_456590
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @127_456590
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @128_456590
  _mm_store_ss((float *)(u32)(EBP - 76), x0);  // @129_456590
  eax = ext_443ef0_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @130_456590
  ecx = edx = 0;  // @131_456590
  x1 = _mm_load_ss((const float *)(u32)(EBP - 44));  // @132_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @133_456590
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @134_456590
  ecx = (u32)(EBP - 16);  // @135_456590
  _mm_store_ss((float *)(u32)(EBP - 8), x1);  // @136_456590
  eax = ext_451890_fastcall3(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @137_456590
  ecx = edx = 0;  // @138_456590
  x0 = _mm_load_ss((const float *)(u32)(EBP - 76));  // @139_456590
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 64)));  // @140_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @141_456590
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @142_456590
  x0 = _mm_xor_ps(x0, _mm_loadu_ps((const float *)(u32)(6795072)));  // @143_456590
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @144_456590
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @145_456590
  goto L45681a;  // @146_456590
  L4567d9:;
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @148_456590
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @149_456590
  ecx = (u32)(EBP - 16);  // @150_456590
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @151_456590
  edx = (edx + (u32)(-12));  // @152_456590
  eax = ext_443ef0_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @153_456590
  ecx = edx = 0;  // @154_456590
  x0 = _mm_load_ss((const float *)(u32)(EBP - 44));  // @155_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @156_456590
  x0 = _mm_mul_ss(x0, x0);  // @157_456590
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @158_456590
  ecx = (u32)(EBP - 16);  // @159_456590
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @160_456590
  eax = ext_451890_fastcall3(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @161_456590
  ecx = edx = 0;  // @162_456590
  x0 = _mm_load_ss((const float *)(u32)(EBP - 44));  // @163_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @164_456590
  x0 = _mm_add_ss(x0, x0);  // @165_456590
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @166_456590
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @167_456590
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @168_456590
  L45681a:;
  ecx = (u32)(EBP - 28);  // @170_456590
  eax = ext_443ef0_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @171_456590
  ecx = edx = 0;  // @172_456590
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @173_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @174_456590
  edx = (u32)(EBP - 28);  // @175_456590
  eax = (u32)(EBP - 8);  // @176_456590
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @177_456590
  edx = (u32)(EBP - 16);  // @178_456590
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, 4); }  // @179_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @180_456590
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @181_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @182_456590
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 237), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 20), &v, 4); }  // @183_456590
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 0), 4); v; }));  // @184_456590
  ecx = edx = 0;  // @185_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @186_456590
  L456846:;
  x5 = _mm_load_ss((const float *)(u32)(6784484));  // @188_456590
  x4 = _mm_load_ss((const float *)(u32)(EBP - 52));  // @189_456590
  L456853:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @191_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @192_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @193_456590
  if (ecx == eax) goto L456897;  // @194_456590
  eax = (u32)(eax + eax*8);  // @195_456590
  x0 = _mm_loadu_ps((const float *)(u32)(edi + eax*4 + 12));  // @196_456590
  _mm_storeu_ps((float *)(u32)(edx - 12), x0);  // @197_456590
  x0 = _mm_loadu_ps((const float *)(u32)(edi + eax*4 + 28));  // @198_456590
  _mm_storeu_ps((float *)(u32)(edx + 4), x0);  // @199_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 44), sizeof v); (u32)v; });  // @200_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @201_456590
  goto L456897;  // @202_456590
  L45687e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @204_456590
  x3 = _mm_min_ss(x3, x4);  // @205_456590
  ecx = (ecx + 1);  // @206_456590
  edx = (edx + (u32)(36));  // @207_456590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @208_456590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @209_456590
  x4 = x3;  // @210_456590
  _mm_store_ss((float *)(u32)(EBP - 52), x4);  // @211_456590
  L456897:;
  x1 = _mm_load_ss((const float *)(u32)(6784544));  // @213_456590
  if (ecx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) goto L4566d0;  // @214_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @215_456590
  L4568ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @217_456590
  if ((eax & eax) == 0) goto L4568f7;  // @218_456590
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)esi));  // @219_456590
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @220_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2316), &v, sizeof v); }  // @221_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @222_456590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @223_456590
  _mm_store_ss((float *)(u32)(edi + 8), x4);  // @224_456590
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784484)));  // @225_456590
  _mm_store_ss((float *)(u32)(edi + 2324), x0);  // @226_456590
  if ((eax & eax) == 0) goto L456965;  // @227_456590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2077), sizeof v); (u32)v; });  // @228_456590
  ecx = (u32)((s32)eax * (s32)(u32)(2380));  // @229_456590
  edi = (edi + (u32)(4294964916));  // @230_456590
  edi = (edi + ecx);  // @231_456590
  goto L45695d;  // @232_456590
  L4568f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @234_456590
  edx = edi;  // @235_456590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @236_456590
  if ((eax & eax) == 0) goto L456915;  // @237_456590
  ecx = (u32)((s32)eax * (s32)(u32)(2380));  // @238_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2077), sizeof v); (u32)v; });  // @239_456590
  eax = (eax + (u32)(4294964916));  // @240_456590
  eax = (eax + ecx);  // @241_456590
  L456915:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @243_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @244_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @245_456590
  if ((ecx & ecx) == 0) goto L456925;  // @246_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @247_456590
  goto L45692b;  // @248_456590
  L456925:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @250_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @251_456590
  L45692b:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2077), sizeof v); (u32)v; });  // @253_456590
  eax = (u32)(1847918703);  // @254_456590
  edx = (edx - edi);  // @255_456590
  { long long t_ = (long long)(s32)eax * (long long)(s32)edx; eax = (u32)t_; edx = (u32)((u64)t_ >> 32); }  // @256_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152576), sizeof v); (u32)v; });  // @257_456590
  edx = (u32)((s32)edx >> (u32)(10));  // @258_456590
  ecx = edx;  // @259_456590
  ecx = (ecx >> (u32)(31));  // @260_456590
  ecx = (ecx + edx);  // @261_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @262_456590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + eax*4 + 152320), &v, sizeof v); }  // @263_456590
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152576), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 152576), &v, sizeof v); }  // @264_456590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @265_456590
  L45695d:;
  if ((edi & edi) != 0) goto L456671;  // @267_456590
  L456965:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @269_456590
  L456968:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @271_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @272_456590
  edx = (edx + 1);  // @273_456590
  ecx = (ecx + (u32)(8));  // @274_456590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @275_456590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @276_456590
  if (edx < (u32)(256)) goto L4565c0;  // @277_456590
  L456984:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L456991;  // @279_456590
  ecx = eax;  // @280_456590
  eax = ext_4569b0_thiscall1(ecx);  // @281_456590
  ecx = edx = 0;  // @282_456590
  L456991:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @284_456590
  ecx = (ecx ^ EBP);  // @285_456590
  eax = ext_633654_thiscall1(ecx);  // @286_456590
  ecx = edx = 0;  // @287_456590
  __asm__ volatile("" :: "Yz"(x0));  // @288_456590
  return eax;  // @289_456590
}
PCREG(456590, lifted_456590);

extern "C" u32 THISCALL lifted_4711f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666eeb);  // @h_4711f0
  u8 F[0x4310] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x4210);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4210 + 8, &a0, 4);
  __builtin_memcpy(F + 0x4210 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 16604), &SENT_EBX, 4);  // @0_4711f0
  __builtin_memcpy((void *)(u32)(EBP - 16608), &SENT_ESI, 4);  // @1_4711f0
  __builtin_memcpy((void *)(u32)(EBP - 16612), &SENT_EDI, 4);  // @2_4711f0
  edi = ecx;  // @3_4711f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_4711f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16600), &v, sizeof v); }  // @6_4711f0
  if (ebx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; })) goto L4712d2;  // @7_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @8_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @9_4711f0
  eax = (eax >> (u32)(10));  // @10_4711f0
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @11_4711f0
  if (ebx != (u32)(1)) goto L471254;  // @12_4711f0
  if (((ebx & 0xff) & (eax & 0xff)) == 0) goto L47125d;  // @13_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_4711f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @15_4711f0
  ecx = edx = 0;  // @16_4711f0
  goto L47125d;  // @17_4711f0
  L471254:;
  if (((eax & 0xff) & (u32)(1)) != 0) goto L47125d;  // @19_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_4711f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @21_4711f0
  ecx = edx = 0;  // @22_4711f0
  L47125d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_4711f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4711f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; }));  // @27_4711f0
  ecx = edx = 0;  // @28_4711f0
  ecx = eax;  // @29_4711f0
  if ((ecx & ecx) == 0) goto L4712d6;  // @30_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4711f0
  p0_ = ebx;  // @32_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 756), sizeof v); (u32)v; });  // @33_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p0_), (u32)(0));  // @34_4711f0
  ecx = edx = 0;  // @35_4711f0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4712d6;  // @36_4711f0
  ecx = (u32)(EBP - 16596);  // @37_4711f0
  eax = ext_4d2280_thiscall1(ecx);  // @38_4711f0
  ecx = edx = 0;  // @39_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @40_4711f0
  esi = (u32)(EBP - 16596);  // @41_4711f0
  reg.state = (s32)((u32)(0));  // @42_4711f0
  p1_ = ebx;  // @43_4711f0
  if ((eax & eax) != 0) esi = eax;  // @44_4711f0
  ecx = esi;  // @45_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(6850636), (u32)(p1_));  // @47_4711f0
  ecx = edx = 0;  // @48_4711f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @49_4711f0
  ecx = edi;  // @50_4711f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @51_4711f0
  p2_ = esi;  // @52_4711f0
  p3_ = eax;  // @53_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(p3_), (u32)(p2_));  // @54_4711f0
  ecx = edx = 0;  // @55_4711f0
  ecx = (u32)(EBP - 16596);  // @56_4711f0
  eax = ext_4d2330_thiscall1(ecx);  // @57_4711f0
  ecx = edx = 0;  // @58_4711f0
  L4712d2:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @60_4711f0
  goto L4712d8;  // @61_4711f0
  L4712d6:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @63_4711f0
  L4712d8:;
  SEH_LEAVE();  // @65_4711f0
  ext_633654(G(u32, 0x6f5630));  // @66_4711f0
  return eax;  // @67_4711f0
}
PCREG(4711f0, lifted_4711f0);

extern "C" u32 THISCALL lifted_442ad0(u32 ecx_in) {
  SEH_ENTER(0x665e7b);  // @h_442ad0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 300), &SENT_ESI, 4);  // @0_442ad0
  esi = ecx;  // @1_442ad0
  eax = ext_44a1f0_cdecl0();  // @2_442ad0
  ecx = edx = 0;  // @3_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_442ad0
  ecx = esi;  // @5_442ad0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 788)))(ecx);  // @6_442ad0
  ecx = edx = 0;  // @7_442ad0
  esi = eax;  // @8_442ad0
  if ((esi & esi) == 0) goto L442be2;  // @9_442ad0
  ecx = (u32)(EBP - 188);  // @10_442ad0
  eax = ext_4ccba0_thiscall1(ecx);  // @11_442ad0
  ecx = edx = 0;  // @12_442ad0
  ecx = (u32)(EBP - 284);  // @13_442ad0
  reg.state = (s32)((u32)(0));  // @14_442ad0
  eax = ext_4e3180_thiscall1(ecx);  // @15_442ad0
  ecx = edx = 0;  // @16_442ad0
  eax = (u32)(EBP - 188);  // @17_442ad0
  { u32 v = (u32)((u32)(5124816)); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @18_442ad0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @19_442ad0
  ecx = esi;  // @20_442ad0
  eax = (u32)(EBP - 284);  // @21_442ad0
  p0_ = eax;  // @22_442ad0
  eax = ext_4e49d0_thiscall2(ecx, (u32)(p0_));  // @23_442ad0
  ecx = edx = 0;  // @24_442ad0
  eax = (u32)(EBP - 296);  // @25_442ad0
  p1_ = eax;  // @26_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @27_442ad0
  ecx = (u32)(EBP - 188);  // @28_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @29_442ad0
  ecx = edx = 0;  // @30_442ad0
  eax = (u32)(EBP - 296);  // @31_442ad0
  p2_ = eax;  // @32_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @33_442ad0
  ecx = (u32)(EBP - 188);  // @34_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @35_442ad0
  ecx = edx = 0;  // @36_442ad0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L442bd7;  // @37_442ad0
  L442b90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_442ad0
  p3_ = eax;  // @40_442ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @41_442ad0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(p3_));  // @43_442ad0
  ecx = edx = 0;  // @44_442ad0
  esi = eax;  // @45_442ad0
  if ((esi & esi) == 0) goto L442bb8;  // @46_442ad0
  ecx = esi;  // @47_442ad0
  eax = ext_4da720_thiscall2(ecx, (u32)(0));  // @48_442ad0
  ecx = edx = 0;  // @49_442ad0
  ecx = esi;  // @50_442ad0
  eax = ext_4d9ce0_thiscall1(ecx);  // @51_442ad0
  ecx = edx = 0;  // @52_442ad0
  L442bb8:;
  eax = (u32)(EBP - 296);  // @54_442ad0
  p4_ = eax;  // @55_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @56_442ad0
  ecx = (u32)(EBP - 188);  // @57_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p4_));  // @58_442ad0
  ecx = edx = 0;  // @59_442ad0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) != (u32)(0)) goto L442b90;  // @60_442ad0
  L442bd7:;
  ecx = (u32)(EBP - 188);  // @62_442ad0
  eax = ext_4ccf60_thiscall1(ecx);  // @63_442ad0
  ecx = edx = 0;  // @64_442ad0
  L442be2:;
  SEH_LEAVE();  // @66_442ad0
  ext_633654(G(u32, 0x6f5630));  // @67_442ad0
  return eax;  // @68_442ad0
}
PCREG(442ad0, lifted_442ad0);

extern "C" u32 THISCALL lifted_4627d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66693b);  // @h_4627d0
  u8 F[0x4360] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x4260);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4260 + 8, &a0, 4);
  __builtin_memcpy(F + 0x4260 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 16628), &SENT_EBX, 4);  // @0_4627d0
  __builtin_memcpy((void *)(u32)(EBP - 16632), &SENT_ESI, 4);  // @1_4627d0
  __builtin_memcpy((void *)(u32)(EBP - 16636), &SENT_EDI, 4);  // @2_4627d0
  esi = ecx;  // @3_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @5_4627d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16604), &v, sizeof v); }  // @6_4627d0
  ecx = (u32)(edi + edi*2);  // @7_4627d0
  ecx = (u32)(eax + ecx*8);  // @8_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @9_4627d0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4629f7;  // @10_4627d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @11_4627d0
  eax = (eax & (u32)(4294967292));  // @12_4627d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16600), &v, sizeof v); }  // @13_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @14_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @15_4627d0
  ecx = esi;  // @16_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_4627d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16612), &v, sizeof v); }  // @18_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @19_4627d0
  ecx = edx = 0;  // @20_4627d0
  edi = (u32)(edi + edi*2);  // @21_4627d0
  edi = (edi + edi);  // @22_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 47), sizeof v); (u32)v; }) == (u32)(3)) goto L462909;  // @23_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L462909;  // @24_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }) != (u32)(0)) goto L462909;  // @25_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_4627d0
  ecx = esi;  // @27_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @28_4627d0
  ecx = edx = 0;  // @29_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 12), sizeof v); (u32)v; });  // @30_4627d0
  if ((s32)(edi & edi) < 0) goto L462909;  // @31_4627d0
  L462880:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @33_4627d0
  ecx = (u32)(edi + edi*2);  // @34_4627d0
  ebx = (u32)(eax + ecx*8);  // @35_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @36_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16608), &v, sizeof v); }  // @37_4627d0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4628a1;  // @38_4627d0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; })) goto L4628ba;  // @39_4627d0
  L4628a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_4627d0
  ecx = esi;  // @42_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @43_4627d0
  ecx = edx = 0;  // @44_4627d0
  ecx = (u32)(edi + edi*2);  // @45_4627d0
  ecx = (ecx + ecx);  // @46_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 12), sizeof v); (u32)v; });  // @47_4627d0
  if ((s32)(edi & edi) >= 0) goto L462880;  // @48_4627d0
  goto L462903;  // @49_4627d0
  L4628ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_4627d0
  ecx = esi;  // @52_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 700)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; }));  // @53_4627d0
  ecx = edx = 0;  // @54_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @55_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16608), sizeof v); (u32)v; });  // @56_4627d0
  p0_ = eax;  // @57_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 48)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }), (u32)(p0_));  // @59_4627d0
  ecx = edx = 0;  // @60_4627d0
  ecx = eax;  // @61_4627d0
  if ((ecx & ecx) == 0) goto L462903;  // @62_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @63_4627d0
  p1_ = edi;  // @64_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 848), sizeof v); (u32)v; });  // @65_4627d0
  p2_ = ecx;  // @66_4627d0
  ecx = esi;  // @67_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }), (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; }), (u32)(p1_));  // @68_4627d0
  ecx = edx = 0;  // @69_4627d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462903;  // @70_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @71_4627d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 68), &v, sizeof v); }  // @72_4627d0
  L462903:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @74_4627d0
  L462909:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @76_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) != 0) goto L4629f7;  // @77_4627d0
  ecx = (u32)(EBP - 16596);  // @78_4627d0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @79_4627d0
  eax = ext_4d2280_thiscall1(ecx);  // @80_4627d0
  ecx = edx = 0;  // @81_4627d0
  edi = (u32)(ebx + 76);  // @82_4627d0
  reg.state = (s32)((u32)(0));  // @83_4627d0
  p3_ = edi;  // @84_4627d0
  ecx = (u32)(EBP - 16596);  // @85_4627d0
  eax = ext_4d39a0_stdcall2((u32)(6838552), (u32)(p3_));  // @86_4627d0
  ecx = edx = 0;  // @87_4627d0
  ecx = (u32)(EBP - 16596);  // @88_4627d0
  eax = ext_4d3ab0_stdcall2((u32)(6838564), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }));  // @89_4627d0
  ecx = edx = 0;  // @90_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @91_4627d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) == 0) goto L462979;  // @92_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_4627d0
  eax = (u32)(EBP - 16596);  // @94_4627d0
  p4_ = eax;  // @95_4627d0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 296), sizeof v); (u32)v; });  // @96_4627d0
  ecx = esi;  // @97_4627d0
  p5_ = eax;  // @98_4627d0
  p6_ = esi;  // @99_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, (u32)(p6_), (u32)(p5_), (u32)(p4_));  // @100_4627d0
  ecx = edx = 0;  // @101_4627d0
  L462979:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @103_4627d0
  ecx = esi;  // @104_4627d0
  p7_ = edi;  // @105_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 836)))(ecx, (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16612), sizeof v); (u32)v; }));  // @106_4627d0
  ecx = edx = 0;  // @107_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @108_4627d0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @109_4627d0
  if ((ecx & ecx) == 0) goto L4629ec;  // @110_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @111_4627d0
  edx = (u32)(EBP - 16624);  // @112_4627d0
  p8_ = edx;  // @113_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p8_));  // @114_4627d0
  ecx = edx = 0;  // @115_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @116_4627d0
  edx = (u32)(EBP - 16624);  // @117_4627d0
  p9_ = edx;  // @118_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p9_));  // @120_4627d0
  ecx = edx = 0;  // @121_4627d0
  edx = eax;  // @122_4627d0
  if ((edx & edx) == 0) goto L4629ec;  // @123_4627d0
  L4629b4:;
  ecx = (u32)(edx + 4);  // @125_4627d0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L4629d7;  // @126_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; }) != (u32)(-2)) goto L4629d7;  // @127_4627d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 68), &v, sizeof v); }  // @128_4627d0
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @129_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @130_4627d0
  p10_ = ecx;  // @131_4627d0
  ecx = esi;  // @132_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 844)))(ecx, (u32)(p10_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @133_4627d0
  ecx = edx = 0;  // @134_4627d0
  L4629d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @136_4627d0
  edx = (u32)(EBP - 16624);  // @137_4627d0
  p11_ = edx;  // @138_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p11_));  // @140_4627d0
  ecx = edx = 0;  // @141_4627d0
  edx = eax;  // @142_4627d0
  if ((edx & edx) != 0) goto L4629b4;  // @143_4627d0
  L4629ec:;
  ecx = (u32)(EBP - 16596);  // @145_4627d0
  eax = ext_4d2330_thiscall1(ecx);  // @146_4627d0
  ecx = edx = 0;  // @147_4627d0
  L4629f7:;
  SEH_LEAVE();  // @149_4627d0
  ext_633654(G(u32, 0x6f5630));  // @150_4627d0
  return eax;  // @151_4627d0
}
PCREG(4627d0, lifted_4627d0);

extern "C" u32 THISCALL lifted_5d6280(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_5d6280
  eax = (eax ^ (u32)(EBP - 284));  // @1_5d6280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 0), &v, sizeof v); }  // @2_5d6280
  __builtin_memcpy((void *)(u32)(EBP - 292), &SENT_ESI, 4);  // @3_5d6280
  __builtin_memcpy((void *)(u32)(EBP - 296), &SENT_EDI, 4);  // @4_5d6280
  edi = ecx;  // @5_5d6280
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }) == (u32)(0)) goto L5d67c7;  // @6_5d6280
  esi = (u32)(edi + 94);  // @7_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @9_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 102), &v, sizeof v); }  // @10_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 106), &v, sizeof v); }  // @11_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 110), &v, sizeof v); }  // @12_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 114), &v, sizeof v); }  // @13_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 118), &v, sizeof v); }  // @14_5d6280
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 122), sizeof v); (u32)v; }) == (u32)(0)) goto L5d6318;  // @15_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @17_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @18_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @19_5d6280
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 180), sizeof v); (u32)v; });  // @22_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @23_5d6280
  ecx = edx = 0;  // @24_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @26_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @27_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @28_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @29_5d6280
  ecx = edx = 0;  // @30_5d6280
  esi = (u32)(edi + 94);  // @31_5d6280
  goto L5d632d;  // @32_5d6280
  L5d6318:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_5d6280
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @35_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @38_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @39_5d6280
  ecx = edx = 0;  // @40_5d6280
  L5d632d:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @42_5d6280
  if ((eax & eax) != 0) goto L5d636b;  // @43_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @44_5d6280
  { u32 v = (u32)((u32)(111)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @45_5d6280
  { u32 v = (u32)((u32)(7035464)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, 4); }  // @46_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @48_5d6280
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @49_5d6280
  ecx = edx = 0;  // @50_5d6280
  { u32 v = (u32)((u32)(7035540)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @51_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, 4); }  // @52_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @53_5d6280
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @54_5d6280
  ecx = edx = 0;  // @55_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 0), sizeof v); (u32)v; });  // @56_5d6280
  ecx = (ecx ^ (u32)(EBP - 284));  // @57_5d6280
  eax = ext_633654_thiscall1(ecx);  // @58_5d6280
  ecx = edx = 0;  // @59_5d6280
  return eax;  // @60_5d6280
  L5d636b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_5d6280
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @63_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @66_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @67_5d6280
  ecx = edx = 0;  // @68_5d6280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @69_5d6280
  if ((eax & eax) == 0) goto L5d67c7;  // @70_5d6280
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 123), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 123), &v, sizeof v); }  // @71_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @72_5d6280
  if ((ecx & ecx) == 0) goto L5d679c;  // @73_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_5d6280
  edx = (u32)(EBP - 264);  // @75_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @76_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @77_5d6280
  ecx = edx = 0;  // @78_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @79_5d6280
  edx = (u32)(EBP - 264);  // @80_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @81_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @82_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @84_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @85_5d6280
  ecx = edx = 0;  // @86_5d6280
  edx = eax;  // @87_5d6280
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; }) == (u32)(0)) goto L5d679c;  // @88_5d6280
  L5d63c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @91_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @92_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @94_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @95_5d6280
  ecx = edx = 0;  // @96_5d6280
  esi = eax;  // @97_5d6280
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 228), &v, sizeof v); }  // @98_5d6280
  eax = (u32)(EBP - 72);  // @99_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @100_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @101_5d6280
  ecx = esi;  // @102_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @103_5d6280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @105_5d6280
  eax = (u32)(EBP - 36);  // @106_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, 4); }  // @107_5d6280
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @108_5d6280
  ecx = edx = 0;  // @109_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @110_5d6280
  edx = (u32)(EBP - 200);  // @111_5d6280
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 72)));  // @112_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @113_5d6280
  _mm_storel_epi64((__m128i *)(u32)(EBP - 200), _mm_castps_si128(x0));  // @114_5d6280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @115_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @117_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @118_5d6280
  ecx = edx = 0;  // @119_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @120_5d6280
  eax = (u32)(EBP - 200);  // @121_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @122_5d6280
  eax = (u32)(EBP - 224);  // @123_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, 4); }  // @124_5d6280
  eax = ext_446320_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @125_5d6280
  ecx = edx = 0;  // @126_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @127_5d6280
  edx = (u32)(EBP - 216);  // @128_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @129_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @131_5d6280
  ecx = edx = 0;  // @132_5d6280
  x5 = _mm_load_ss((const float *)(u32)(EBP - 208));  // @133_5d6280
  x4 = _mm_load_ss((const float *)(u32)(EBP - 220));  // @134_5d6280
  x0 = x5;  // @135_5d6280
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 224)));  // @136_5d6280
  x7 = _mm_load_ss((const float *)(u32)(6792876));  // @137_5d6280
  x6 = _mm_castpd_ps(_mm_load_sd((const double *)(u32)(6802768)));  // @138_5d6280
  x3 = _mm_load_ss((const float *)(u32)(EBP - 204));  // @139_5d6280
  x4 = _mm_mul_ss(x4, x5);  // @140_5d6280
  x5 = _mm_mul_ss(x5, x7);  // @141_5d6280
  x2 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @142_5d6280
  _mm_store_ss((float *)(u32)(EBP - 224), x0);  // @143_5d6280
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x5));  // @144_5d6280
  x2 = _mm_and_ps(x2, x6);  // @145_5d6280
  _mm_store_ss((float *)(u32)(EBP - 220), x4);  // @146_5d6280
  fa_ = _mm_cvtsd_f64(_mm_castps_pd(x2)); fb_ = _mm_cvtsd_f64(_mm_castps_pd(x0));  // @147_5d6280
  if (fa_ > fb_) goto L5d64d7;  // @148_5d6280
  x0 = x3;  // @149_5d6280
  x0 = _mm_mul_ss(x0, x7);  // @150_5d6280
  x1 = _mm_castpd_ps(_mm_cvtps_pd(x4));  // @151_5d6280
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @152_5d6280
  x1 = _mm_and_ps(x1, x6);  // @153_5d6280
  fa_ = _mm_cvtsd_f64(_mm_castps_pd(x1)); fb_ = _mm_cvtsd_f64(_mm_castps_pd(x0));  // @154_5d6280
  if (fa_ > fb_) goto L5d64d7;  // @155_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 228));  // @156_5d6280
  goto L5d6532;  // @157_5d6280
  L5d64d7:;
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x5));  // @159_5d6280
  x3 = _mm_mul_ss(x3, x7);  // @160_5d6280
  x2 = _mm_castpd_ps(_mm_sub_sd(_mm_castps_pd(x2), _mm_castps_pd(x0)));  // @161_5d6280
  x1 = _mm_castpd_ps(_mm_cvtps_pd(x4));  // @162_5d6280
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x3));  // @163_5d6280
  x1 = _mm_and_ps(x1, x6);  // @164_5d6280
  x1 = _mm_castpd_ps(_mm_sub_sd(_mm_castps_pd(x1), _mm_castps_pd(x0)));  // @165_5d6280
  x2 = _mm_cvtpd_ps(_mm_castps_pd(x2));  // @166_5d6280
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x1));  // @167_5d6280
  x2 = _mm_max_ss(x2, x0);  // @168_5d6280
  x0 = _mm_load_ss((const float *)(u32)(6945228));  // @169_5d6280
  fa_ = _mm_cvtss_f32(x2); fb_ = _mm_cvtss_f32(x0);  // @170_5d6280
  if (!(fa_ >= fb_)) goto L5d6516;  // @171_5d6280
  x0 = _mm_setzero_ps();  // @172_5d6280
  _mm_store_ss((float *)(u32)(EBP - 228), x0);  // @173_5d6280
  goto L5d667f;  // @174_5d6280
  L5d6516:;
  x2 = _mm_div_ss(x2, x0);  // @176_5d6280
  x0 = _mm_load_ss((const float *)(u32)(6785112));  // @177_5d6280
  x0 = _mm_sub_ss(x0, x2);  // @178_5d6280
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 228)));  // @179_5d6280
  _mm_store_ss((float *)(u32)(EBP - 228), x0);  // @180_5d6280
  L5d6532:;
  x1 = _mm_setzero_ps();  // @182_5d6280
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @183_5d6280
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @184_5d6280
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L5d6682;  // @185_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @186_5d6280
  ecx = esi;  // @187_5d6280
  { u32 v = (u32)((u32)(8388643)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @188_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @189_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @190_5d6280
  ecx = edx = 0;  // @191_5d6280
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5d6679;  // @192_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @193_5d6280
  edx = (u32)(EBP - 48);  // @194_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @195_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @196_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @197_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @198_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @199_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @200_5d6280
  ecx = edx = 0;  // @201_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @202_5d6280
  ecx = esi;  // @203_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 576), sizeof v); (u32)v; });  // @204_5d6280
  T[0] = ((double(THISCALL *)(u32))(eax))(ecx);  // @205_5d6280
  ecx = edx = 0;  // @206_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 36));  // @207_5d6280
  eax = (u32)(EBP - 252);  // @208_5d6280
  _mm_store_ss((float *)(u32)(EBP - 252), x0);  // @209_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 32));  // @210_5d6280
  _mm_store_ss((float *)(u32)(EBP - 248), x0);  // @211_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 28));  // @212_5d6280
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @213_5d6280
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 276), &v, 4); }  // @214_5d6280
  _mm_store_ss((float *)(u32)(EBP - 244), x0);  // @215_5d6280
  ecx = edi;  // @216_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 276));  // @217_5d6280
  _mm_store_ss((float *)(u32)(EBP - 296), x0);  // @218_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, 4); }  // @219_5d6280
  eax = (u32)(EBP - 72);  // @220_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, 4); }  // @221_5d6280
  eax = (u32)(EBP - 48);  // @222_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 308), &v, 4); }  // @223_5d6280
  eax = ext_5d6960_stdcall4(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 308), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @224_5d6280
  ecx = edx = 0;  // @225_5d6280
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5d6601;  // @226_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 228), &v, sizeof v); }  // @227_5d6280
  L5d6601:;
  eax = (u32)(EBP - 72);  // @229_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @230_5d6280
  edx = (u32)(EBP - 48);  // @231_5d6280
  ecx = (u32)(EBP - 240);  // @232_5d6280
  eax = ext_43e920_fastcall3(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @233_5d6280
  ecx = edx = 0;  // @234_5d6280
  x1 = _mm_load_ss((const float *)(u32)(EBP - 240));  // @235_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 236));  // @236_5d6280
  x0 = _mm_mul_ss(x0, x0);  // @237_5d6280
  x1 = _mm_mul_ss(x1, x1);  // @238_5d6280
  x1 = _mm_add_ss(x1, x0);  // @239_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 232));  // @240_5d6280
  x0 = _mm_mul_ss(x0, x0);  // @241_5d6280
  x1 = _mm_add_ss(x1, x0);  // @242_5d6280
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x1));  // @243_5d6280
  eax = ext_634d7c_cdecl0();  // @244_5d6280
  ecx = edx = 0;  // @245_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @246_5d6280
  ecx = esi;  // @247_5d6280
  x0 = _mm_cvtsd_ss(x0, _mm_castps_pd(x0));  // @248_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 584), sizeof v); (u32)v; });  // @249_5d6280
  _mm_store_ss((float *)(u32)(EBP - 276), x0);  // @250_5d6280
  T[0] = ((double(THISCALL *)(u32))(eax))(ecx);  // @251_5d6280
  ecx = edx = 0;  // @252_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 276));  // @253_5d6280
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 268), &v, 4); }  // @254_5d6280
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(EBP - 268)));  // @255_5d6280
  if (!(fa_ > fb_)) goto L5d6679;  // @256_5d6280
  x0 = _mm_setzero_ps();  // @257_5d6280
  _mm_store_ss((float *)(u32)(EBP - 228), x0);  // @258_5d6280
  goto L5d667f;  // @259_5d6280
  L5d6679:;
  x0 = _mm_load_ss((const float *)(u32)(EBP - 228));  // @261_5d6280
  L5d667f:;
  x1 = _mm_setzero_ps();  // @263_5d6280
  L5d6682:;
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x1);  // @265_5d6280
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @266_5d6280
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L5d6759;  // @267_5d6280
  ecx = (u32)(EBP - 188);  // @268_5d6280
  eax = ext_4e1b60_thiscall1(ecx);  // @269_5d6280
  ecx = edx = 0;  // @270_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @271_5d6280
  edx = (u32)(EBP - 60);  // @272_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @273_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @274_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @275_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @276_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @277_5d6280
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @278_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @279_5d6280
  ecx = edx = 0;  // @280_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 60));  // @281_5d6280
  eax = (u32)(EBP - 60);  // @282_5d6280
  _mm_store_ss((float *)(u32)(EBP - 188), x0);  // @283_5d6280
  edx = (u32)(EBP - 72);  // @284_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 56));  // @285_5d6280
  ecx = (u32)(EBP - 176);  // @286_5d6280
  _mm_store_ss((float *)(u32)(EBP - 184), x0);  // @287_5d6280
  x0 = _mm_load_ss((const float *)(u32)(EBP - 52));  // @288_5d6280
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @289_5d6280
  _mm_store_ss((float *)(u32)(EBP - 180), x0);  // @290_5d6280
  eax = ext_43e920_fastcall3(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @291_5d6280
  ecx = edx = 0;  // @292_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @293_5d6280
  edx = (u32)(EBP - 188);  // @294_5d6280
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @295_5d6280
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, 4); }  // @296_5d6280
  { u32 v = (u32)((u32)(-1)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, 4); }  // @297_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @298_5d6280
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 308), &v, 4); }  // @299_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 312), &v, 4); }  // @300_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 316), &v, 4); }  // @301_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @302_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @303_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @304_5d6280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 312), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 308), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @305_5d6280
  ecx = edx = 0;  // @306_5d6280
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5d6753;  // @307_5d6280
  x0 = _mm_setzero_ps();  // @308_5d6280
  _mm_store_ss((float *)(u32)(EBP - 228), x0);  // @309_5d6280
  goto L5d6759;  // @310_5d6280
  L5d6753:;
  x0 = _mm_load_ss((const float *)(u32)(EBP - 228));  // @312_5d6280
  L5d6759:;
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(edi + 94)));  // @314_5d6280
  esi = (u32)(edi + 94);  // @315_5d6280
  if (!(fa_ > fb_)) goto L5d677c;  // @316_5d6280
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 228));  // @317_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @318_5d6280
  _mm_storeu_ps((float *)(u32)(esi), x0);  // @319_5d6280
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 212)));  // @320_5d6280
  _mm_storel_epi64((__m128i *)(u32)(esi + 16), _mm_castps_si128(x0));  // @321_5d6280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @322_5d6280
  L5d677c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @324_5d6280
  edx = (u32)(EBP - 264);  // @325_5d6280
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @326_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @327_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @328_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @329_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @330_5d6280
  ecx = edx = 0;  // @331_5d6280
  edx = eax;  // @332_5d6280
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; }) != (u32)(0)) goto L5d63c4;  // @333_5d6280
  L5d679c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @335_5d6280
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @336_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @337_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @338_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @339_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @340_5d6280
  ecx = edx = 0;  // @341_5d6280
  if ((eax & eax) == 0) goto L5d67c7;  // @342_5d6280
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @343_5d6280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @344_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, 4); }  // @345_5d6280
  { u32 v = (u32)((u32)(esi)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, 4); }  // @346_5d6280
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, 4); }  // @347_5d6280
  ecx = eax;  // @348_5d6280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 312)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), 4); v; }));  // @349_5d6280
  ecx = edx = 0;  // @350_5d6280
  L5d67c7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 0), sizeof v); (u32)v; });  // @352_5d6280
  ecx = (ecx ^ (u32)(EBP - 284));  // @353_5d6280
  eax = ext_633654_thiscall1(ecx);  // @354_5d6280
  ecx = edx = 0;  // @355_5d6280
  __asm__ volatile("" :: "Yz"(x0));  // @356_5d6280
  return eax;  // @357_5d6280
}
PCREG(5d6280, lifted_5d6280);

extern "C" u32 THISCALL lifted_6119e0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x600] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x500);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x500 + 8, &a0, 4);
  __builtin_memcpy(F + 0x500 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_6119e0
  eax = (eax ^ (u32)(EBP - 432));  // @1_6119e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 0), &v, sizeof v); }  // @2_6119e0
  __builtin_memcpy((void *)(u32)(EBP - 440), &SENT_EBX, 4);  // @3_6119e0
  __builtin_memcpy((void *)(u32)(EBP - 444), &SENT_ESI, 4);  // @4_6119e0
  esi = ecx;  // @5_6119e0
  __builtin_memcpy((void *)(u32)(EBP - 448), &SENT_EDI, 4);  // @6_6119e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @8_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_6119e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L611f2a;  // @10_6119e0
  { u32 v = (u32)((u32)(259)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @11_6119e0
  { u32 v = (u32)((u32)(24)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @12_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @13_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @14_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @15_6119e0
  ecx = edx = 0;  // @16_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @17_6119e0
  { u32 v = (u32)((u32)(131072)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @18_6119e0
  { u32 v = (u32)((u32)(11)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @19_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @20_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @22_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @23_6119e0
  ecx = edx = 0;  // @24_6119e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 272), sizeof v); (u32)v; });  // @25_6119e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489608), sizeof v); (u32)v; }) == edx) goto L611a61;  // @26_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @27_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @28_6119e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7489608), &v, sizeof v); }  // @29_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @30_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @32_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 244)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @33_6119e0
  ecx = edx = 0;  // @34_6119e0
  L611a61:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4847), sizeof v); (u32)v; }) & (u32)(8)) == 0) goto L611aa6;  // @36_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @37_6119e0
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @38_6119e0
  { u32 v = (u32)((u32)(13)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @39_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @40_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @42_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @43_6119e0
  ecx = edx = 0;  // @44_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @45_6119e0
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @46_6119e0
  { u32 v = (u32)((u32)(14)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @47_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @48_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @49_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @50_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @51_6119e0
  ecx = edx = 0;  // @52_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @53_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @54_6119e0
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @55_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @56_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @58_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @59_6119e0
  ecx = edx = 0;  // @60_6119e0
  L611aa6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @62_6119e0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @63_6119e0
  edx = (u32)(2);  // @64_6119e0
  ecx = 0;  // @65_6119e0
  eax = ext_60ff30_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @66_6119e0
  ecx = edx = 0;  // @67_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @68_6119e0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @69_6119e0
  edx = (u32)(1);  // @70_6119e0
  ecx = 0;  // @71_6119e0
  eax = ext_60feb0_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @72_6119e0
  ecx = edx = 0;  // @73_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @74_6119e0
  edx = (u32)(1);  // @75_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @76_6119e0
  ecx = edx;  // @77_6119e0
  eax = ext_60ff30_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @78_6119e0
  ecx = edx = 0;  // @79_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @80_6119e0
  edx = (u32)(1);  // @81_6119e0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @82_6119e0
  ecx = edx;  // @83_6119e0
  eax = ext_60feb0_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @84_6119e0
  ecx = edx = 0;  // @85_6119e0
  ecx = (u32)(EBP - 36);  // @86_6119e0
  ebx = (u32)(edi + 16);  // @87_6119e0
  eax = ext_4de7a0_thiscall1(ecx);  // @88_6119e0
  ecx = edx = 0;  // @89_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 39), sizeof v); (u32)v; });  // @90_6119e0
  edx = (u32)(EBP - 48);  // @91_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @92_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @93_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @94_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @96_6119e0
  edx = (u32)(EBP - 36);  // @97_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @98_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 148)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @99_6119e0
  ecx = edx = 0;  // @100_6119e0
  eax = (u32)(EBP - 48);  // @101_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @102_6119e0
  edx = (u32)(EBP - 36);  // @103_6119e0
  ecx = (u32)(EBP - 428);  // @104_6119e0
  eax = ext_60f040_fastcall3(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @105_6119e0
  ecx = edx = 0;  // @106_6119e0
  edx = (u32)(EBP - 428);  // @107_6119e0
  ecx = (u32)(EBP - 196);  // @108_6119e0
  eax = ext_60f0b0_fastcall2(ecx, edx);  // @109_6119e0
  ecx = edx = 0;  // @110_6119e0
  ecx = (u32)(EBP - 364);  // @111_6119e0
  eax = ext_609a70_thiscall1(ecx);  // @112_6119e0
  ecx = edx = 0;  // @113_6119e0
  eax = (u32)(EBP - 364);  // @114_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @115_6119e0
  { u32 v = (u32)((u32)(ebx)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @116_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @117_6119e0
  eax = ext_410f26_stdcall3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @118_6119e0
  ecx = edx = 0;  // @119_6119e0
  eax = (u32)(EBP - 364);  // @120_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @121_6119e0
  eax = (u32)(edi + 80);  // @122_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @123_6119e0
  eax = (u32)(EBP - 364);  // @124_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @125_6119e0
  eax = ext_410f26_stdcall3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @126_6119e0
  ecx = edx = 0;  // @127_6119e0
  eax = (u32)(EBP - 364);  // @128_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @129_6119e0
  eax = (u32)(edi + 144);  // @130_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @131_6119e0
  eax = (u32)(EBP - 364);  // @132_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @133_6119e0
  eax = ext_410f26_stdcall3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @134_6119e0
  ecx = edx = 0;  // @135_6119e0
  eax = (u32)(EBP - 364);  // @136_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @137_6119e0
  eax = (u32)(EBP - 196);  // @138_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @139_6119e0
  eax = (u32)(EBP - 364);  // @140_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @141_6119e0
  eax = ext_410f26_stdcall3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @142_6119e0
  ecx = edx = 0;  // @143_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @144_6119e0
  edx = (u32)(EBP - 364);  // @145_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @146_6119e0
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @147_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @148_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @149_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @150_6119e0
  ecx = edx = 0;  // @151_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @152_6119e0
  { u32 v = (u32)((u32)(259)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @153_6119e0
  { u32 v = (u32)((u32)(24)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @154_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @155_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @156_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @157_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @158_6119e0
  ecx = edx = 0;  // @159_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @160_6119e0
  { u32 v = (u32)((u32)(131073)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @161_6119e0
  { u32 v = (u32)((u32)(11)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @162_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @163_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @164_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @165_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @166_6119e0
  ecx = edx = 0;  // @167_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490192), sizeof v); (u32)v; });  // @168_6119e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489612), sizeof v); (u32)v; }) == ecx) goto L611c19;  // @169_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @170_6119e0
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @171_6119e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7489612), &v, sizeof v); }  // @172_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @173_6119e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @174_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @175_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 244)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @176_6119e0
  ecx = edx = 0;  // @177_6119e0
  L611c19:;
  edx = (u32)(4);  // @179_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @180_6119e0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @181_6119e0
  ecx = (u32)(edx - 3);  // @182_6119e0
  eax = ext_60ff30_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @183_6119e0
  ecx = edx = 0;  // @184_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @185_6119e0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @186_6119e0
  { u32 v = (u32)((u32)(13)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @187_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @188_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @189_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @190_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @191_6119e0
  ecx = edx = 0;  // @192_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @193_6119e0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @194_6119e0
  { u32 v = (u32)((u32)(14)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @195_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @196_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @197_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @198_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @199_6119e0
  ecx = edx = 0;  // @200_6119e0
  ecx = (u32)(EBP - 364);  // @201_6119e0
  eax = ext_609a70_thiscall1(ecx);  // @202_6119e0
  ecx = edx = 0;  // @203_6119e0
  eax = (u32)(EBP - 364);  // @204_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @205_6119e0
  { u32 v = (u32)((u32)(ebx)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @206_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @207_6119e0
  eax = ext_410f26_stdcall3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @208_6119e0
  ecx = edx = 0;  // @209_6119e0
  eax = (u32)(EBP - 364);  // @210_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @211_6119e0
  eax = (u32)(edi + 208);  // @212_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @213_6119e0
  eax = (u32)(EBP - 364);  // @214_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @215_6119e0
  eax = ext_410f26_stdcall3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @216_6119e0
  ecx = edx = 0;  // @217_6119e0
  eax = (u32)(EBP - 364);  // @218_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @219_6119e0
  eax = (u32)(EBP - 196);  // @220_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @221_6119e0
  eax = (u32)(EBP - 364);  // @222_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @223_6119e0
  eax = ext_410f26_stdcall3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @224_6119e0
  ecx = edx = 0;  // @225_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @226_6119e0
  edx = (u32)(EBP - 364);  // @227_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @228_6119e0
  { u32 v = (u32)((u32)(17)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @229_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @230_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @231_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @232_6119e0
  ecx = edx = 0;  // @233_6119e0
  x0 = _mm_load_ss((const float *)(u32)(edi + 292));  // @234_6119e0
  edx = (u32)(EBP - 60);  // @235_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 39), sizeof v); (u32)v; });  // @236_6119e0
  _mm_store_ss((float *)(u32)(EBP - 60), x0);  // @237_6119e0
  x0 = _mm_load_ss((const float *)(u32)(edi + 296));  // @238_6119e0
  _mm_store_ss((float *)(u32)(EBP - 56), x0);  // @239_6119e0
  x0 = _mm_load_ss((const float *)(u32)(edi + 300));  // @240_6119e0
  _mm_store_ss((float *)(u32)(EBP - 52), x0);  // @241_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @242_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @243_6119e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @244_6119e0
  ecx = edx = 0;  // @245_6119e0
  x1 = _mm_load_ss((const float *)(u32)(EBP - 56));  // @246_6119e0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 60));  // @247_6119e0
  x0 = _mm_mul_ss(x0, x0);  // @248_6119e0
  x1 = _mm_mul_ss(x1, x1);  // @249_6119e0
  x1 = _mm_add_ss(x1, x0);  // @250_6119e0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 52));  // @251_6119e0
  x0 = _mm_mul_ss(x0, x0);  // @252_6119e0
  x1 = _mm_add_ss(x1, x0);  // @253_6119e0
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x1));  // @254_6119e0
  eax = ext_634d7c_cdecl0();  // @255_6119e0
  ecx = edx = 0;  // @256_6119e0
  x1 = _mm_load_ss((const float *)(u32)(6803812));  // @257_6119e0
  x0 = _mm_cvtsd_ss(x0, _mm_castps_pd(x0));  // @258_6119e0
  x1 = _mm_sub_ss(x1, x0);  // @259_6119e0
  x0 = _mm_setzero_ps();  // @260_6119e0
  x1 = _mm_div_ss(x1, _mm_load_ss((const float *)(u32)(6860572)));  // @261_6119e0
  x0 = _mm_max_ss(x0, x1);  // @262_6119e0
  _mm_store_ss((float *)(u32)(EBP - 432), x0);  // @263_6119e0
  x0 = _mm_load_ss((const float *)(u32)(6785112));  // @264_6119e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 253), sizeof v); (u32)v; }) == (u32)(0)) goto L611d63;  // @265_6119e0
  _mm_store_ss((float *)(u32)(EBP - 432), x0);  // @266_6119e0
  L611d63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @268_6119e0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @269_6119e0
  edx = (u32)(4);  // @270_6119e0
  ecx = 0;  // @271_6119e0
  eax = ext_60ff30_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @272_6119e0
  ecx = edx = 0;  // @273_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @274_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @275_6119e0
  { u32 v = (u32)((u32)(141)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @276_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @277_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @278_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @279_6119e0
  ecx = edx = 0;  // @280_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @281_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @282_6119e0
  { u32 v = (u32)((u32)(145)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @283_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @284_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @285_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @286_6119e0
  ecx = edx = 0;  // @287_6119e0
  { u32 v = (u32)((u32)(68)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @288_6119e0
  eax = (u32)(EBP - 132);  // @289_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @290_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @291_6119e0
  eax = ext_634d10_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @292_6119e0
  ecx = edx = 0;  // @293_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @294_6119e0
  edx = (u32)(EBP - 132);  // @295_6119e0
  x0 = _mm_loadu_ps((const float *)(u32)(6879520));  // @296_6119e0
  _mm_storeu_ps((float *)(u32)(EBP - 132), x0);  // @297_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @298_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @299_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @300_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 168)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @301_6119e0
  ecx = edx = 0;  // @302_6119e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489864), sizeof v); (u32)v; }) == (u32)(1)) goto L611e01;  // @303_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @304_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @305_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7489864), &v, sizeof v); }  // @306_6119e0
  { u32 v = (u32)((u32)(137)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @307_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @308_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @309_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @310_6119e0
  ecx = edx = 0;  // @311_6119e0
  L611e01:;
  { u32 v = (u32)((u32)(104)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @313_6119e0
  eax = (u32)(EBP - 300);  // @314_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @315_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @316_6119e0
  eax = ext_634d10_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @317_6119e0
  ecx = edx = 0;  // @318_6119e0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 432));  // @319_6119e0
  edx = (u32)(EBP - 248);  // @320_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 39), sizeof v); (u32)v; });  // @321_6119e0
  _mm_store_ss((float *)(u32)(EBP - 296), x0);  // @322_6119e0
  _mm_store_ss((float *)(u32)(EBP - 292), x0);  // @323_6119e0
  _mm_store_ss((float *)(u32)(EBP - 288), x0);  // @324_6119e0
  x0 = _mm_load_ss((const float *)(u32)(edi + 304));  // @325_6119e0
  _mm_store_ss((float *)(u32)(EBP - 224), x0);  // @326_6119e0
  x0 = _mm_load_ss((const float *)(u32)(edi + 280));  // @327_6119e0
  _mm_store_ss((float *)(u32)(EBP - 248), x0);  // @328_6119e0
  x0 = _mm_load_ss((const float *)(u32)(edi + 284));  // @329_6119e0
  _mm_store_ss((float *)(u32)(EBP - 244), x0);  // @330_6119e0
  x0 = _mm_load_ss((const float *)(u32)(edi + 288));  // @331_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @332_6119e0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @333_6119e0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 216), &v, sizeof v); }  // @334_6119e0
  _mm_store_ss((float *)(u32)(EBP - 240), x0);  // @335_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @336_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @337_6119e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @338_6119e0
  ecx = edx = 0;  // @339_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @340_6119e0
  edx = (u32)(EBP - 300);  // @341_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @342_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @343_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @344_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @345_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 176)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @346_6119e0
  ecx = edx = 0;  // @347_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @348_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @349_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @350_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @351_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @352_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 184)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @353_6119e0
  ecx = edx = 0;  // @354_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @355_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @356_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @357_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @358_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @359_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 184)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @360_6119e0
  ecx = edx = 0;  // @361_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @362_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @363_6119e0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @364_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @365_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @366_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 184)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @367_6119e0
  ecx = edx = 0;  // @368_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @369_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @370_6119e0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @371_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @372_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @373_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 184)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @374_6119e0
  ecx = edx = 0;  // @375_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 0), sizeof v); (u32)v; });  // @376_6119e0
  ecx = (ecx ^ (u32)(EBP - 432));  // @377_6119e0
  eax = ext_633654_thiscall1(ecx);  // @378_6119e0
  ecx = edx = 0;  // @379_6119e0
  __asm__ volatile("" :: "Yz"(x0));  // @380_6119e0
  return eax;  // @381_6119e0
  L611f2a:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @383_6119e0
  { u32 v = (u32)((u32)(24)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @384_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @385_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @386_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @387_6119e0
  ecx = edx = 0;  // @388_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @389_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @390_6119e0
  { u32 v = (u32)((u32)(11)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @391_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @392_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @393_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @394_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @395_6119e0
  ecx = edx = 0;  // @396_6119e0
  ecx = (u32)(EBP - 196);  // @397_6119e0
  eax = ext_609a70_thiscall1(ecx);  // @398_6119e0
  ecx = edx = 0;  // @399_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @400_6119e0
  edx = (u32)(EBP - 196);  // @401_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @402_6119e0
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @403_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @404_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @405_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @406_6119e0
  ecx = edx = 0;  // @407_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @408_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @409_6119e0
  { u32 v = (u32)((u32)(24)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @410_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @411_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @412_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @413_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @414_6119e0
  ecx = edx = 0;  // @415_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @416_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @417_6119e0
  { u32 v = (u32)((u32)(11)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @418_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @419_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @420_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, 4); }  // @421_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 252)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @422_6119e0
  ecx = edx = 0;  // @423_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @424_6119e0
  edx = (u32)(EBP - 196);  // @425_6119e0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @426_6119e0
  { u32 v = (u32)((u32)(17)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @427_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @428_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @429_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @430_6119e0
  ecx = edx = 0;  // @431_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @432_6119e0
  edx = (u32)(1);  // @433_6119e0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @434_6119e0
  ecx = edx;  // @435_6119e0
  eax = ext_60ff30_fastcall4(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @436_6119e0
  ecx = edx = 0;  // @437_6119e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489864), sizeof v); (u32)v; }) == (u32)(0)) goto L611fec;  // @438_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @439_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @440_6119e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489864), &v, sizeof v); }  // @441_6119e0
  { u32 v = (u32)((u32)(137)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @442_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @443_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @444_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @445_6119e0
  ecx = edx = 0;  // @446_6119e0
  L611fec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @448_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @449_6119e0
  { u32 v = (u32)((u32)(141)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @450_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @451_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @452_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @453_6119e0
  ecx = edx = 0;  // @454_6119e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4983), sizeof v); (u32)v; });  // @455_6119e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 448), &v, 4); }  // @456_6119e0
  { u32 v = (u32)((u32)(145)); __builtin_memcpy((void *)(u32)(EBP - 452), &v, 4); }  // @457_6119e0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, 4); }  // @458_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @459_6119e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), 4); v; }));  // @460_6119e0
  ecx = edx = 0;  // @461_6119e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 0), sizeof v); (u32)v; });  // @462_6119e0
  ecx = (ecx ^ (u32)(EBP - 432));  // @463_6119e0
  eax = ext_633654_thiscall1(ecx);  // @464_6119e0
  ecx = edx = 0;  // @465_6119e0
  __asm__ volatile("" :: "Yz"(x0));  // @466_6119e0
  return eax;  // @467_6119e0
}
PCREG(6119e0, lifted_6119e0);

extern "C" u32 THISCALL lifted_53bfd0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_53bfd0
  eax = (eax ^ (u32)(EBP - 48));  // @1_53bfd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 0), &v, sizeof v); }  // @2_53bfd0
  eax = ecx;  // @3_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_53bfd0
  __builtin_memcpy((void *)(u32)(EBP - 56), &SENT_EBX, 4);  // @5_53bfd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @6_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @7_53bfd0
  __builtin_memcpy((void *)(u32)(EBP - 60), &SENT_ESI, 4);  // @8_53bfd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @9_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @10_53bfd0
  __builtin_memcpy((void *)(u32)(EBP - 64), &SENT_EDI, 4);  // @11_53bfd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_53bfd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @13_53bfd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @14_53bfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4597), sizeof v); (u32)v; }) == (u32)(0)) goto L53c1d2;  // @15_53bfd0
  x0 = _mm_load_ss((const float *)(u32)(6802756));  // @16_53bfd0
  ebx = 0;  // @17_53bfd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 164), sizeof v); (u32)v; });  // @18_53bfd0
  _mm_store_ss((float *)(u32)(EBP - 48), x0);  // @19_53bfd0
  if ((edi & edi) == 0) goto L53c1d2;  // @20_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @21_53bfd0
  ecx = (u32)(EBP - 24);  // @22_53bfd0
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @23_53bfd0
  ecx = edi;  // @24_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @25_53bfd0
  ecx = edx = 0;  // @26_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_53bfd0
  ecx = (u32)(EBP - 24);  // @28_53bfd0
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @29_53bfd0
  ecx = edi;  // @30_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @31_53bfd0
  ecx = edx = 0;  // @32_53bfd0
  edx = eax;  // @33_53bfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == ebx) goto L53c1d2;  // @34_53bfd0
  L53c060:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_53bfd0
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @37_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @38_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @40_53bfd0
  ecx = edx = 0;  // @41_53bfd0
  esi = eax;  // @42_53bfd0
  if ((esi & esi) == 0) goto L53c0ed;  // @43_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_53bfd0
  { u32 v = (u32)((u32)(esi)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @45_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @46_53bfd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @48_53bfd0
  ecx = edx = 0;  // @49_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_53bfd0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @51_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @52_53bfd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @54_53bfd0
  ecx = edx = 0;  // @55_53bfd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @56_53bfd0
  ecx = (u32)(EBP - 12);  // @57_53bfd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @58_53bfd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @59_53bfd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_53bfd0
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @61_53bfd0
  ecx = eax;  // @62_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @63_53bfd0
  ecx = edx = 0;  // @64_53bfd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @65_53bfd0
  ecx = (u32)(EBP - 12);  // @66_53bfd0
  T[0] = ext_4e0830_fastcall2_f(ecx, edx);  // @67_53bfd0
  ecx = edx = 0;  // @68_53bfd0
  x1 = _mm_load_ss((const float *)(u32)(EBP - 48));  // @69_53bfd0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 40), &v, 4); }  // @70_53bfd0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 40));  // @71_53bfd0
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x0);  // @72_53bfd0
  if (!(fa_ > fb_)) goto L53c0ed;  // @73_53bfd0
  _mm_store_ss((float *)(u32)(EBP - 48), x0);  // @74_53bfd0
  ebx = esi;  // @75_53bfd0
  L53c0ed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @77_53bfd0
  ecx = (u32)(EBP - 24);  // @78_53bfd0
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @79_53bfd0
  ecx = edi;  // @80_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @81_53bfd0
  ecx = edx = 0;  // @82_53bfd0
  edx = eax;  // @83_53bfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L53c060;  // @84_53bfd0
  if ((ebx & ebx) == 0) goto L53c1d2;  // @85_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @86_53bfd0
  ecx = ebx;  // @87_53bfd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 560)))(ecx);  // @88_53bfd0
  ecx = edx = 0;  // @89_53bfd0
  ecx = eax;  // @90_53bfd0
  if ((ecx & ecx) == 0) goto L53c1d2;  // @91_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_53bfd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @93_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @94_53bfd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @95_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @97_53bfd0
  ecx = edx = 0;  // @98_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_53bfd0
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, 4); }  // @100_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @101_53bfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), 4); v; }));  // @102_53bfd0
  ecx = edx = 0;  // @103_53bfd0
  ecx = eax;  // @104_53bfd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @105_53bfd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @106_53bfd0
  ecx = edx = 0;  // @107_53bfd0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 48));  // @108_53bfd0
  esi = eax;  // @109_53bfd0
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @110_53bfd0
  eax = ext_634d7c_cdecl0();  // @111_53bfd0
  ecx = edx = 0;  // @112_53bfd0
  x0 = _mm_castpd_ps(_mm_div_sd(_mm_castps_pd(x0), _mm_load_sd((const double *)(u32)(6896992))));  // @113_53bfd0
  x2 = _mm_load_ss((const float *)(u32)(6792876));  // @114_53bfd0
  x1 = _mm_setzero_ps();  // @115_53bfd0
  x1 = _mm_cvtsd_ss(x1, _mm_castps_pd(x0));  // @116_53bfd0
  x0 = _mm_load_ss((const float *)(u32)(6785112));  // @117_53bfd0
  x1 = _mm_mul_ss(x1, x2);  // @118_53bfd0
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x0);  // @119_53bfd0
  if (fa_ > fb_) goto L53c1d2;  // @120_53bfd0
  ecx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @121_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @122_53bfd0
  x1 = _mm_mul_ss(x1, x1);  // @123_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4601), sizeof v); (u32)v; });  // @124_53bfd0
  x0 = _mm_sub_ss(x0, x1);  // @125_53bfd0
  x0 = _mm_mul_ss(x0, x2);  // @126_53bfd0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(ecx + eax + 8)));  // @127_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @128_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @129_53bfd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @130_53bfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @131_53bfd0
  _mm_store_ss((float *)(u32)(eax), x0);  // @132_53bfd0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @133_53bfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 0), sizeof v); (u32)v; });  // @134_53bfd0
  ecx = (ecx ^ (u32)(EBP - 48));  // @135_53bfd0
  eax = ext_633654_thiscall1(ecx);  // @136_53bfd0
  ecx = edx = 0;  // @137_53bfd0
  __asm__ volatile("" :: "Yz"(x0));  // @138_53bfd0
  return eax;  // @139_53bfd0
  L53c1d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 0), sizeof v); (u32)v; });  // @141_53bfd0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @142_53bfd0
  ecx = (ecx ^ (u32)(EBP - 48));  // @143_53bfd0
  eax = ext_633654_thiscall1(ecx);  // @144_53bfd0
  ecx = edx = 0;  // @145_53bfd0
  __asm__ volatile("" :: "Yz"(x0));  // @146_53bfd0
  return eax;  // @147_53bfd0
}
PCREG(53bfd0, lifted_53bfd0);

