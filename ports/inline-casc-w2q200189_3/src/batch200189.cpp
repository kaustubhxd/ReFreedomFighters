// batch200189.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_42afb0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42afb0");
extern "C" u32 FASTCALL ext_42b080_fastcall3(u32, u32, u32) __asm__("ext_42b080");
extern "C" u32 FASTCALL ext_42b160_fastcall4(u32, u32, u32, u32) __asm__("ext_42b160");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_421ed0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_421ed0");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cbf30_thiscall2(u32, u32) __asm__("ext_4cbf30");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2d60_thiscall3(u32, u32, u32) __asm__("ext_5f2d60");
extern "C" u32 THISCALL ext_616490_thiscall4(u32, u32, u32, u32) __asm__("ext_616490");
extern "C" u32 THISCALL ext_616580_thiscall4(u32, u32, u32, u32) __asm__("ext_616580");
extern "C" u32 THISCALL ext_616620_thiscall4(u32, u32, u32, u32) __asm__("ext_616620");
extern "C" u32 THISCALL ext_617360_thiscall1(u32) __asm__("ext_617360");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 THISCALL ext_658db0_thiscall1(u32) __asm__("ext_658db0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_617150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e6f4);  // @h_617150
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_EBX, 4);  // @0_617150
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_ESI, 4);  // @1_617150
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_EDI, 4);  // @2_617150
  ebx = ecx;  // @3_617150
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @5_617150
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(16)) == 0) goto L617221;  // @6_617150
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) == (u32)(0)) goto L617221;  // @7_617150
  eax = ext_41e290_cdecl1((u32)(12));  // @8_617150
  ecx = edx = 0;  // @9_617150
  esi = eax;  // @10_617150
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @11_617150
  reg.state = (s32)((u32)(0));  // @12_617150
  if ((esi & esi) == 0) goto L617209;  // @13_617150
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @14_617150
  ecx = ebx;  // @15_617150
  reg.state = (s32)((u32)(1));  // @16_617150
  { u32 v = (u32)((u32)(7068864)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @17_617150
  eax = ext_617360_thiscall1(ecx);  // @18_617150
  ecx = edx = 0;  // @19_617150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @20_617150
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(16)) != 0) goto L6171e8;  // @21_617150
  p0_ = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(16));  // @22_617150
  ecx = 0;  // @23_617150
  eax = ext_658db0_thiscall1(ecx);  // @24_617150
  ecx = edx = 0;  // @25_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @26_617150
  eax = esi;  // @27_617150
  SEH_LEAVE();  // @28_617150
  return eax;  // @29_617150
  L6171e8:;
  p1_ = ecx;  // @31_617150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @32_617150
  eax = ext_658db0_thiscall1(ecx);  // @33_617150
  ecx = edx = 0;  // @34_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @35_617150
  eax = esi;  // @36_617150
  SEH_LEAVE();  // @37_617150
  return eax;  // @38_617150
  L617209:;
  esi = 0;  // @40_617150
  eax = esi;  // @41_617150
  SEH_LEAVE();  // @42_617150
  return eax;  // @43_617150
  L617221:;
  p2_ = esi;  // @45_617150
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @46_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47524), sizeof v); (u32)v; });  // @47_617150
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5104), sizeof v); (u32)v; })) & 0xff);  // @48_617150
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L61726e;  // @49_617150
  eax = ext_41e290_cdecl1((u32)(20));  // @50_617150
  ecx = edx = 0;  // @51_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @52_617150
  reg.state = (s32)((u32)(2));  // @53_617150
  if ((eax & eax) == 0) goto L617345;  // @54_617150
  p3_ = esi;  // @55_617150
  p4_ = edi;  // @56_617150
  p5_ = ebx;  // @57_617150
  ecx = eax;  // @58_617150
  eax = ext_616490_thiscall4(ecx, (u32)(p5_), (u32)(p4_), (u32)(p3_));  // @59_617150
  ecx = edx = 0;  // @60_617150
  SEH_LEAVE();  // @61_617150
  return eax;  // @62_617150
  L61726e:;
  p6_ = (eax & eax);  // @64_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_617150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @66_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @67_617150
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @68_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @69_617150
  x0 = _mm_load_ss((const float *)(u32)(edx + 84));  // @70_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @71_617150
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @72_617150
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6785112)));  // @73_617150
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @74_617150
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L61729b;  // @75_617150
  p7_ = (((eax >> 8) & 0xff) & (u32)(68));  // @76_617150
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @77_617150
  L61729b:;
  x0 = _mm_load_ss((const float *)(u32)(edx + 88));  // @79_617150
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6784464)));  // @80_617150
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @81_617150
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L6172af;  // @82_617150
  p8_ = (((eax >> 8) & 0xff) & (u32)(68));  // @83_617150
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @84_617150
  L6172af:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @86_617150
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @87_617150
  p9_ = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; }) & (u32)(4352));  // @88_617150
  edx = (u32)(1);  // @89_617150
  x0 = _mm_load_ss((const float *)(u32)(6818400));  // @90_617150
  eax = (eax & 0xff);  // @91_617150
  if (p9_ == 0) edx = eax;  // @92_617150
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(ecx + 16)));  // @93_617150
  if (fa_ > fb_) goto L61730f;  // @94_617150
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L61730f;  // @95_617150
  eax = ext_41e290_cdecl1((u32)(20));  // @96_617150
  ecx = edx = 0;  // @97_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @98_617150
  reg.state = (s32)((u32)(3));  // @99_617150
  if ((eax & eax) == 0) goto L617345;  // @100_617150
  p10_ = esi;  // @101_617150
  p11_ = edi;  // @102_617150
  p12_ = ebx;  // @103_617150
  ecx = eax;  // @104_617150
  eax = ext_616580_thiscall4(ecx, (u32)(p12_), (u32)(p11_), (u32)(p10_));  // @105_617150
  ecx = edx = 0;  // @106_617150
  SEH_LEAVE();  // @107_617150
  __asm__ volatile("" :: "Yz"(x0));  // @108_617150
  return eax;  // @109_617150
  L61730f:;
  eax = ext_41e290_cdecl1((u32)(20));  // @111_617150
  ecx = edx = 0;  // @112_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @113_617150
  reg.state = (s32)((u32)(4));  // @114_617150
  if ((eax & eax) == 0) goto L617345;  // @115_617150
  p13_ = esi;  // @116_617150
  p14_ = edi;  // @117_617150
  p15_ = ebx;  // @118_617150
  ecx = eax;  // @119_617150
  eax = ext_616620_thiscall4(ecx, (u32)(p15_), (u32)(p14_), (u32)(p13_));  // @120_617150
  ecx = edx = 0;  // @121_617150
  SEH_LEAVE();  // @122_617150
  __asm__ volatile("" :: "Yz"(x0));  // @123_617150
  return eax;  // @124_617150
  L617345:;
  p16_ = (eax & eax);  // @126_617150
  eax = 0;  // @127_617150
  SEH_LEAVE();  // @128_617150
  __asm__ volatile("" :: "Yz"(x0));  // @129_617150
  return eax;  // @130_617150
}
PCREG(617150, lifted_617150);

extern "C" u32 STDCALL lifted_555570(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_555570
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 148), &SENT_ESI, 4);  // @0_555570
  __builtin_memcpy((void *)(u32)(EBP - 152), &SENT_EDI, 4);  // @1_555570
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3_555570
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @4_555570
  ecx = edx = 0;  // @5_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @7_555570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_555570
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @9_555570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @10_555570
  *(volatile u32 *)0x8140f4 = 0;  // @11_555570
  ecx = edx = 0;  // @12_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @13_555570
  esi = eax;  // @14_555570
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @15_555570
  ecx = edx = 0;  // @16_555570
  ecx = eax;  // @17_555570
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @18_555570
  ecx = edx = 0;  // @19_555570
  if ((esi & esi) != 0) goto L5555fe;  // @20_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @21_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_555570
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @23_555570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(732));  // @24_555570
  *(volatile u32 *)0x8140f4 = 0;  // @25_555570
  ecx = edx = 0;  // @26_555570
  p0_ = eax;  // @27_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_555570
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @29_555570
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6969672));  // @30_555570
  *(volatile u32 *)0x8140f4 = 0;  // @31_555570
  ecx = edx = 0;  // @32_555570
  goto L555688;  // @33_555570
  L5555fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_555570
  ecx = esi;  // @36_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @37_555570
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @38_555570
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097268));  // @39_555570
  *(volatile u32 *)0x8140f4 = 0;  // @40_555570
  ecx = edx = 0;  // @41_555570
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L555667;  // @42_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @43_555570
  p1_ = ((eax & 0xff) & (eax & 0xff));  // @44_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_555570
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @46_555570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(736));  // @47_555570
  *(volatile u32 *)0x8140f4 = 0;  // @48_555570
  ecx = edx = 0;  // @49_555570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @50_555570
  edi = eax;  // @51_555570
  eax = (u32)(EBP - 144);  // @52_555570
  ecx = esi;  // @53_555570
  p2_ = eax;  // @54_555570
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @55_555570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p2_), (u32)(1));  // @56_555570
  *(volatile u32 *)0x8140f4 = 0;  // @57_555570
  ecx = edx = 0;  // @58_555570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @59_555570
  ecx = eax;  // @60_555570
  reg.state = (s32)((u32)(0));  // @61_555570
  eax = ext_4cc1d0_thiscall1(ecx);  // @62_555570
  ecx = edx = 0;  // @63_555570
  p3_ = eax;  // @64_555570
  p4_ = edi;  // @65_555570
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @66_555570
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p4_), (u32)(6969720), (u32)(p3_));  // @67_555570
  *(volatile u32 *)0x8140f4 = 0;  // @68_555570
  ecx = edx = 0;  // @69_555570
  ecx = (u32)(EBP - 144);  // @70_555570
  eax = ext_4cbec0_thiscall1(ecx);  // @71_555570
  ecx = edx = 0;  // @72_555570
  goto L555688;  // @73_555570
  L555667:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @75_555570
  ecx = esi;  // @76_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @77_555570
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @78_555570
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @79_555570
  *(volatile u32 *)0x8140f4 = 0;  // @80_555570
  ecx = edx = 0;  // @81_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @82_555570
  eax = (eax & 0xff);  // @83_555570
  p5_ = eax;  // @84_555570
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @85_555570
  ecx = edx = 0;  // @86_555570
  ecx = eax;  // @87_555570
  eax = ext_5002f0_thiscall2(ecx, (u32)(p5_));  // @88_555570
  ecx = edx = 0;  // @89_555570
  L555688:;
  SEH_LEAVE();  // @91_555570
  ext_633654(G(u32, 0x6f5630));  // @92_555570
  return eax;  // @93_555570
}
PCREG(555570, lifted_555570);

extern "C" u32 THISCALL lifted_47ac90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_47ac90
  eax = ecx;  // @1_47ac90
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EBX, 4);  // @2_47ac90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_47ac90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4 + 1178), sizeof v); (u32)v; });  // @5_47ac90
  __builtin_memcpy((void *)(u32)(EBP - 12), &SENT_ESI, 4);  // @6_47ac90
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_EDI, 4);  // @7_47ac90
  if ((eax & eax) == 0) goto L47acd2;  // @8_47ac90
  p0_ = (eax & eax);  // @9_47ac90
  eax = (u32)(eax + ebx*8);  // @10_47ac90
  ecx = 0;  // @11_47ac90
  eax = (eax + (u32)(4));  // @12_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != ecx) ecx = eax;  // @13_47ac90
  if ((ecx & ecx) == 0) goto L47acd2;  // @14_47ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @15_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != esi) goto L47acd5;  // @16_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @17_47ac90
  edi = 0;  // @18_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) == eax) esi = edi;  // @19_47ac90
  goto L47acd5;  // @20_47ac90
  L47acd2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @22_47ac90
  L47acd5:;
  p1_ = eax;  // @24_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @25_47ac90
  edi = 0;  // @26_47ac90
  ecx = 0;  // @27_47ac90
  eax = (eax + (u32)(1206));  // @28_47ac90
  L47ace1:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 4), sizeof v); (u32)v; }) != edx) goto L47acea;  // @30_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == ebx) goto L47acf5;  // @31_47ac90
  L47acea:;
  ecx = (ecx + 1);  // @33_47ac90
  eax = (eax + (u32)(16));  // @34_47ac90
  if (ecx < (u32)(16)) goto L47ace1;  // @35_47ac90
  goto L47acfc;  // @36_47ac90
  L47acf5:;
  edi = (u32)(eax - 4);  // @38_47ac90
  if ((edi & edi) != 0) goto L47ad33;  // @39_47ac90
  L47acfc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @41_47ac90
  ecx = 0;  // @42_47ac90
  L47ad01:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1210), sizeof v); (u32)v; }) == (u32)(0)) goto L47ad15;  // @44_47ac90
  ecx = (ecx + 1);  // @45_47ac90
  eax = (eax + (u32)(16));  // @46_47ac90
  if (ecx < (u32)(16)) goto L47ad01;  // @47_47ac90
  goto L47ad20;  // @48_47ac90
  L47ad15:;
  edi = (u32)(eax + 1202);  // @50_47ac90
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @51_47ac90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @52_47ac90
  L47ad20:;
  if (ecx != (u32)(16)) goto L47ad33;  // @54_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @55_47ac90
  if ((eax & eax) == 0) goto L47ad32;  // @56_47ac90
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @57_47ac90
  eax = ((u32(STDCALL *)(void))(eax))();  // @58_47ac90
  *(volatile u32 *)0x8140f4 = 0;  // @59_47ac90
  ecx = edx = 0;  // @60_47ac90
  goto L47ad33;  // @61_47ac90
  L47ad32:;
  __builtin_trap();  // @63_47ac90
  L47ad33:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @65_47ac90
  p2_ = (eax & eax);  // @66_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @67_47ac90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @68_47ac90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @69_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_47ac90
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @71_47ac90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1452)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1198), sizeof v); (u32)v; }), (u32)(1));  // @72_47ac90
  *(volatile u32 *)0x8140f4 = 0;  // @73_47ac90
  ecx = edx = 0;  // @74_47ac90
  return eax;  // @75_47ac90
}
PCREG(47ac90, lifted_47ac90);

extern "C" u32 THISCALL lifted_4711f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666eeb);  // @h_4711f0
  u8 F[0x4310] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x4210);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
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
  p0_ = eax;  // @11_4711f0
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @12_4711f0
  if (ebx != (u32)(1)) goto L471254;  // @13_4711f0
  if (((ebx & 0xff) & (eax & 0xff)) == 0) goto L47125d;  // @14_4711f0
  p1_ = ((ebx & 0xff) & (eax & 0xff));  // @15_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @17_4711f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @18_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @19_4711f0
  ecx = edx = 0;  // @20_4711f0
  goto L47125d;  // @21_4711f0
  L471254:;
  if (((eax & 0xff) & (u32)(1)) != 0) goto L47125d;  // @23_4711f0
  p2_ = ((eax & 0xff) & (u32)(1));  // @24_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @26_4711f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @27_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @28_4711f0
  ecx = edx = 0;  // @29_4711f0
  L47125d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_4711f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @34_4711f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; }));  // @35_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @36_4711f0
  ecx = edx = 0;  // @37_4711f0
  ecx = eax;  // @38_4711f0
  if ((ecx & ecx) == 0) goto L4712d6;  // @39_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_4711f0
  p3_ = ebx;  // @41_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 756), sizeof v); (u32)v; });  // @42_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @43_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p3_), (u32)(0));  // @44_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @45_4711f0
  ecx = edx = 0;  // @46_4711f0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4712d6;  // @47_4711f0
  ecx = (u32)(EBP - 16596);  // @48_4711f0
  eax = ext_4d2280_thiscall1(ecx);  // @49_4711f0
  ecx = edx = 0;  // @50_4711f0
  p4_ = ((eax & 0xff) & (eax & 0xff));  // @51_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @52_4711f0
  esi = (u32)(EBP - 16596);  // @53_4711f0
  reg.state = (s32)((u32)(0));  // @54_4711f0
  p5_ = ebx;  // @55_4711f0
  if ((eax & eax) != 0) esi = eax;  // @56_4711f0
  ecx = esi;  // @57_4711f0
  p6_ = (eax & eax);  // @58_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @60_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(6850636), (u32)(p5_));  // @61_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @62_4711f0
  ecx = edx = 0;  // @63_4711f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @64_4711f0
  ecx = edi;  // @65_4711f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @66_4711f0
  p7_ = esi;  // @67_4711f0
  p8_ = eax;  // @68_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @69_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(p8_), (u32)(p7_));  // @70_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @71_4711f0
  ecx = edx = 0;  // @72_4711f0
  ecx = (u32)(EBP - 16596);  // @73_4711f0
  eax = ext_4d2330_thiscall1(ecx);  // @74_4711f0
  ecx = edx = 0;  // @75_4711f0
  L4712d2:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @77_4711f0
  goto L4712d8;  // @78_4711f0
  L4712d6:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @80_4711f0
  L4712d8:;
  SEH_LEAVE();  // @82_4711f0
  ext_633654(G(u32, 0x6f5630));  // @83_4711f0
  return eax;  // @84_4711f0
}
PCREG(4711f0, lifted_4711f0);

extern "C" u32 THISCALL lifted_432270(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6686a6);  // @h_432270
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 280), &SENT_EBX, 4);  // @0_432270
  __builtin_memcpy((void *)(u32)(EBP - 284), &SENT_ESI, 4);  // @1_432270
  __builtin_memcpy((void *)(u32)(EBP - 288), &SENT_EDI, 4);  // @2_432270
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @3_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @4_432270
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_432270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_432270
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @7_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6791032), (u32)(1089));  // @8_432270
  *(volatile u32 *)0x8140f4 = 0;  // @9_432270
  ecx = edx = 0;  // @10_432270
  esi = eax;  // @11_432270
  ecx = ebx;  // @12_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @14_432270
  ecx = edx = 0;  // @15_432270
  p0_ = eax;  // @16_432270
  p1_ = esi;  // @17_432270
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @18_432270
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p1_), (u32)(6791656), (u32)(p0_));  // @19_432270
  *(volatile u32 *)0x8140f4 = 0;  // @20_432270
  ecx = edx = 0;  // @21_432270
  ecx = (u32)(EBP - 272);  // @22_432270
  p2_ = ebx;  // @23_432270
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p2_));  // @24_432270
  ecx = edx = 0;  // @25_432270
  ecx = (u32)(EBP - 272);  // @26_432270
  reg.state = (s32)((u32)(0));  // @27_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_432270
  ecx = edx = 0;  // @29_432270
  esi = eax;  // @30_432270
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(0)) goto L432405;  // @31_432270
  L432300:;
  edi = 0;  // @33_432270
  ebx = esi;  // @34_432270
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(59)) goto L43234b;  // @35_432270
  L432310:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @37_432270
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L432328;  // @38_432270
  if ((eax & 0xff) != (u32)(61)) goto L432320;  // @39_432270
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @40_432270
  edi = (u32)(esi + 1);  // @41_432270
  L432320:;
  esi = (esi + 1);  // @43_432270
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(59)) goto L432310;  // @44_432270
  goto L43234b;  // @45_432270
  L432328:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @47_432270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_432270
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @49_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6791032), (u32)(1096));  // @50_432270
  *(volatile u32 *)0x8140f4 = 0;  // @51_432270
  ecx = edx = 0;  // @52_432270
  p3_ = eax;  // @53_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_432270
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @55_432270
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6791696));  // @56_432270
  *(volatile u32 *)0x8140f4 = 0;  // @57_432270
  ecx = edx = 0;  // @58_432270
  L43234b:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @60_432270
  p4_ = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @61_432270
  esi = (esi + 1);  // @62_432270
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(1131574387)) goto L4323fc;  // @63_432270
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @64_432270
  if ((eax & 0xff) != (u32)(67)) goto L4323dd;  // @65_432270
  if ((edi & edi) == 0) goto L4323dd;  // @66_432270
  p5_ = edi;  // @67_432270
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @68_432270
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))((u32)(p5_));  // @69_432270
  *(volatile u32 *)0x8140f4 = 0;  // @70_432270
  ecx = edx = 0;  // @71_432270
  ecx = (u32)(EBP - 144);  // @72_432270
  p6_ = (edi & edi);  // @73_432270
  edi = eax;  // @74_432270
  ebx = (ebx + (u32)(5));  // @75_432270
  eax = ext_4cbeb0_thiscall1(ecx);  // @76_432270
  ecx = edx = 0;  // @77_432270
  p7_ = edi;  // @78_432270
  ecx = (u32)(EBP - 144);  // @79_432270
  reg.state = (s32)((u32)(1));  // @80_432270
  eax = ext_4cbf30_thiscall2(ecx, (u32)(p7_));  // @81_432270
  ecx = edx = 0;  // @82_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @83_432270
  ecx = (u32)(EBP - 144);  // @84_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @86_432270
  ecx = edx = 0;  // @87_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @88_432270
  p8_ = eax;  // @89_432270
  p9_ = ebx;  // @90_432270
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @91_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 104)))(ecx, (u32)(p9_), (u32)(p8_));  // @92_432270
  *(volatile u32 *)0x8140f4 = 0;  // @93_432270
  ecx = edx = 0;  // @94_432270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_432270
  ecx = (u32)(EBP - 144);  // @96_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @97_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @98_432270
  ecx = edx = 0;  // @99_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_432270
  p10_ = eax;  // @101_432270
  p11_ = ebx;  // @102_432270
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @103_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(p11_), (u32)(p10_));  // @104_432270
  *(volatile u32 *)0x8140f4 = 0;  // @105_432270
  ecx = edx = 0;  // @106_432270
  ecx = (u32)(EBP - 144);  // @107_432270
  reg.state = (s32)((u32)(0));  // @108_432270
  eax = ext_4cbec0_thiscall1(ecx);  // @109_432270
  ecx = edx = 0;  // @110_432270
  goto L4323fc;  // @111_432270
  L4323dd:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(1131574387)) goto L4323fc;  // @113_432270
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @114_432270
  if ((eax & 0xff) != (u32)(114)) goto L4323fc;  // @115_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @116_432270
  p12_ = (eax & 0xff);  // @117_432270
  eax = (u32)(ebx + 5);  // @118_432270
  p13_ = eax;  // @119_432270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_432270
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @121_432270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p13_));  // @122_432270
  *(volatile u32 *)0x8140f4 = 0;  // @123_432270
  ecx = edx = 0;  // @124_432270
  L4323fc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L432300;  // @126_432270
  L432405:;
  ecx = (u32)(EBP - 272);  // @128_432270
  eax = ext_4cbec0_thiscall1(ecx);  // @129_432270
  ecx = edx = 0;  // @130_432270
  SEH_LEAVE();  // @131_432270
  ext_633654(G(u32, 0x6f5630));  // @132_432270
  return eax;  // @133_432270
}
PCREG(432270, lifted_432270);

extern "C" u32 THISCALL lifted_4302d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665320);  // @h_4302d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 36), &SENT_EBX, 4);  // @0_4302d0
  __builtin_memcpy((void *)(u32)(EBP - 40), &SENT_ESI, 4);  // @1_4302d0
  __builtin_memcpy((void *)(u32)(EBP - 44), &SENT_EDI, 4);  // @2_4302d0
  esi = ecx;  // @3_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @4_4302d0
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L4303a7;  // @5_4302d0
  eax = (u32)(ecx - 12);  // @6_4302d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_4302d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @8_4302d0
  reg.state = (s32)((u32)(0));  // @9_4302d0
  if ((ecx & ecx) == 0) goto L430320;  // @10_4302d0
  p0_ = eax;  // @11_4302d0
  eax = ext_5f10c0_thiscall2(ecx, (u32)(p0_));  // @12_4302d0
  ecx = edx = 0;  // @13_4302d0
  L430320:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @15_4302d0
  ecx = (u32)(EBP - 32);  // @16_4302d0
  reg.state = (s32)((u32)(4294967295));  // @17_4302d0
  eax = ext_5f10c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @18_4302d0
  ecx = edx = 0;  // @19_4302d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @20_4302d0
  p1_ = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @21_4302d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_4302d0
  ecx = (u32)(eax - 12);  // @23_4302d0
  reg.state = (s32)((u32)(1));  // @24_4302d0
  p2_ = ecx;  // @25_4302d0
  edx = (u32)(eax - 24);  // @26_4302d0
  ecx = esi;  // @27_4302d0
  eax = ext_42afb0_fastcall5(ecx, edx, (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(0));  // @28_4302d0
  ecx = edx = 0;  // @29_4302d0
  eax = (u32)(EBP - 32);  // @30_4302d0
  if (eax == esi) goto L43036a;  // @31_4302d0
  ecx = esi;  // @32_4302d0
  eax = ext_5f2d60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @33_4302d0
  ecx = edx = 0;  // @34_4302d0
  L43036a:;
  p3_ = eax;  // @36_4302d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @37_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @38_4302d0
  eax = (eax - ecx);  // @39_4302d0
  reg.state = (s32)((u32)(2));  // @40_4302d0
  if ((ecx & ecx) == 0) goto L430465;  // @41_4302d0
  if ((eax & eax) == 0) goto L430465;  // @42_4302d0
  p4_ = eax;  // @43_4302d0
  p5_ = ecx;  // @44_4302d0
  ecx = (u32)(EBP - 32);  // @45_4302d0
  eax = ext_54f870_stdcall2((u32)(p5_), (u32)(p4_));  // @46_4302d0
  ecx = edx = 0;  // @47_4302d0
  SEH_LEAVE();  // @48_4302d0
  return eax;  // @49_4302d0
  L4303a7:;
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @51_4302d0
  eax = (u32)(715827883);  // @52_4302d0
  { long long t_ = (long long)(s32)eax * (long long)(s32)ecx; eax = (u32)t_; edx = (u32)((u64)t_ >> 32); }  // @53_4302d0
  p6_ = ((long long)(s32)eax != (((long long)(s32)edx << 32) | (u32)eax));  // @54_4302d0
  edx = (u32)((s32)edx >> (u32)(1));  // @55_4302d0
  edi = edx;  // @56_4302d0
  edi = (edi >> (u32)(31));  // @57_4302d0
  p7_ = edi;  // @58_4302d0
  edi = (edi + edx);  // @59_4302d0
  if (edi == 0) goto L4303c3;  // @60_4302d0
  p8_ = edi;  // @61_4302d0
  edi = (edi + edi);  // @62_4302d0
  if (edi != 0) goto L4303c8;  // @63_4302d0
  ebx = 0;  // @64_4302d0
  goto L4303d8;  // @65_4302d0
  L4303c3:;
  edi = (u32)(1);  // @67_4302d0
  L4303c8:;
  eax = (u32)(edi + edi*2);  // @69_4302d0
  ecx = esi;  // @70_4302d0
  eax = (eax << (u32)(2));  // @71_4302d0
  p9_ = eax;  // @72_4302d0
  eax = ext_6014a0_stdcall1((u32)(p9_));  // @73_4302d0
  ecx = edx = 0;  // @74_4302d0
  ebx = eax;  // @75_4302d0
  L4303d8:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @77_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @78_4302d0
  p10_ = ebx;  // @79_4302d0
  eax = ext_42b160_fastcall4(ecx, edx, (u32)(p10_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @80_4302d0
  ecx = edx = 0;  // @81_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @82_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @83_4302d0
  reg.state = (s32)((u32)(3));  // @84_4302d0
  if ((eax & eax) == 0) goto L430404;  // @85_4302d0
  ecx = eax;  // @86_4302d0
  eax = ext_5f10c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @87_4302d0
  ecx = edx = 0;  // @88_4302d0
  p11_ = (eax & eax);  // @89_4302d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @90_4302d0
  L430404:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @92_4302d0
  eax = (eax + (u32)(12));  // @93_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @94_4302d0
  p12_ = eax;  // @95_4302d0
  reg.state = (s32)((u32)(4294967295));  // @96_4302d0
  eax = ext_42b160_fastcall4(ecx, edx, (u32)(p12_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @97_4302d0
  ecx = edx = 0;  // @98_4302d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @99_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @101_4302d0
  eax = ext_42b080_fastcall3(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @102_4302d0
  ecx = edx = 0;  // @103_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @104_4302d0
  p13_ = eax;  // @105_4302d0
  eax = (u32)(715827883);  // @106_4302d0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @107_4302d0
  { long long t_ = (long long)(s32)eax * (long long)(s32)ecx; eax = (u32)t_; edx = (u32)((u64)t_ >> 32); }  // @108_4302d0
  p14_ = ((long long)(s32)eax != (((long long)(s32)edx << 32) | (u32)eax));  // @109_4302d0
  edx = (u32)((s32)edx >> (u32)(1));  // @110_4302d0
  eax = edx;  // @111_4302d0
  eax = (eax >> (u32)(31));  // @112_4302d0
  p15_ = eax;  // @113_4302d0
  eax = (eax + edx);  // @114_4302d0
  if (eax == 0) goto L430454;  // @115_4302d0
  p16_ = eax;  // @116_4302d0
  eax = (u32)(eax + eax*2);  // @117_4302d0
  ecx = esi;  // @118_4302d0
  eax = (eax << (u32)(2));  // @119_4302d0
  p17_ = eax;  // @120_4302d0
  eax = ext_54f870_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(p17_));  // @121_4302d0
  ecx = edx = 0;  // @122_4302d0
  L430454:;
  p18_ = eax;  // @124_4302d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @125_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @126_4302d0
  eax = (u32)(edi + edi*2);  // @127_4302d0
  eax = (u32)(ebx + eax*4);  // @128_4302d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @129_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @130_4302d0
  L430465:;
  SEH_LEAVE();  // @132_4302d0
  return eax;  // @133_4302d0
}
PCREG(4302d0, lifted_4302d0);

extern "C" u32 THISCALL lifted_42c9a0(u32 ecx_in) {
  SEH_ENTER(0x664dc6);  // @h_42c9a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 280), &SENT_EBX, 4);  // @0_42c9a0
  __builtin_memcpy((void *)(u32)(EBP - 284), &SENT_ESI, 4);  // @1_42c9a0
  __builtin_memcpy((void *)(u32)(EBP - 288), &SENT_EDI, 4);  // @2_42c9a0
  edi = ecx;  // @3_42c9a0
  ebx = (u32)(edi + 1187);  // @4_42c9a0
  ecx = ebx;  // @5_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @6_42c9a0
  ecx = edx = 0;  // @7_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(37)) goto L42cb07;  // @8_42c9a0
  ecx = ebx;  // @9_42c9a0
  esi = (u32)(1);  // @10_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @11_42c9a0
  ecx = edx = 0;  // @12_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }) == (u32)(37)) goto L42ca06;  // @13_42c9a0
  L42c9f8:;
  ecx = ebx;  // @15_42c9a0
  esi = (esi + 1);  // @16_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @17_42c9a0
  ecx = edx = 0;  // @18_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(37)) goto L42c9f8;  // @19_42c9a0
  L42ca06:;
  ecx = ebx;  // @21_42c9a0
  p0_ = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; });  // @22_42c9a0
  esi = (esi + 1);  // @23_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_42c9a0
  ecx = edx = 0;  // @25_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) == (u32)(92)) goto L42ca06;  // @26_42c9a0
  ecx = ebx;  // @27_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_42c9a0
  ecx = edx = 0;  // @29_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) == (u32)(47)) goto L42ca06;  // @30_42c9a0
  ecx = ebx;  // @31_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @32_42c9a0
  ecx = edx = 0;  // @33_42c9a0
  p1_ = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; });  // @34_42c9a0
  eax = (eax + 1);  // @35_42c9a0
  p2_ = eax;  // @36_42c9a0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @37_42c9a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676410))((u32)(p2_), (u32)(6790792), (u32)(7));  // @38_42c9a0
  *(volatile u32 *)0x8140f4 = 0;  // @39_42c9a0
  ecx = edx = 0;  // @40_42c9a0
  if ((eax & eax) != 0) goto L42cb07;  // @41_42c9a0
  eax = ext_41e290_cdecl1((u32)(260));  // @42_42c9a0
  ecx = edx = 0;  // @43_42c9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_42c9a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @45_42c9a0
  ecx = edi;  // @46_42c9a0
  p3_ = (eax & eax);  // @47_42c9a0
  eax = (u32)(EBP - 272);  // @48_42c9a0
  p4_ = eax;  // @49_42c9a0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @50_42c9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 412)))(ecx, (u32)(p4_));  // @51_42c9a0
  *(volatile u32 *)0x8140f4 = 0;  // @52_42c9a0
  ecx = edx = 0;  // @53_42c9a0
  ecx = eax;  // @54_42c9a0
  reg.state = (s32)((u32)(0));  // @55_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @56_42c9a0
  ecx = edx = 0;  // @57_42c9a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @58_42c9a0
  edx = edi;  // @59_42c9a0
  edx = (edx - eax);  // @60_42c9a0
  L42ca80:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @62_42c9a0
  eax = (u32)(eax + 1);  // @63_42c9a0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @64_42c9a0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L42ca80;  // @65_42c9a0
  p5_ = ((ecx & 0xff) & (ecx & 0xff));  // @66_42c9a0
  ecx = (u32)(EBP - 272);  // @67_42c9a0
  reg.state = (s32)((u32)(4294967295));  // @68_42c9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @69_42c9a0
  ecx = edx = 0;  // @70_42c9a0
  ecx = ebx;  // @71_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @72_42c9a0
  ecx = edx = 0;  // @73_42c9a0
  edx = (u32)(esi + eax);  // @74_42c9a0
  esi = edx;  // @75_42c9a0
  L42cab0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @77_42c9a0
  edx = (edx + 1);  // @78_42c9a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42cab0;  // @79_42c9a0
  edx = (edx - esi);  // @80_42c9a0
  edi = (edi - 1);  // @81_42c9a0
  L42cac0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @83_42c9a0
  p6_ = edi;  // @84_42c9a0
  edi = (edi + 1);  // @85_42c9a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42cac0;  // @86_42c9a0
  ecx = edx;  // @87_42c9a0
  ecx = (ecx >> (u32)(2));  // @88_42c9a0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @89_42c9a0
  p7_ = ecx;  // @90_42c9a0
  ecx = edx;  // @91_42c9a0
  ecx = (ecx & (u32)(3));  // @92_42c9a0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 1); esi += 1; edi += 1; ecx--; }  // @93_42c9a0
  p8_ = ecx;  // @94_42c9a0
  ecx = (u32)(EBP - 144);  // @95_42c9a0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @96_42c9a0
  ecx = edx = 0;  // @97_42c9a0
  eax = (u32)(EBP - 144);  // @98_42c9a0
  reg.state = (s32)((u32)(1));  // @99_42c9a0
  p9_ = eax;  // @100_42c9a0
  ecx = ebx;  // @101_42c9a0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p9_));  // @102_42c9a0
  ecx = edx = 0;  // @103_42c9a0
  ecx = (u32)(EBP - 144);  // @104_42c9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @105_42c9a0
  ecx = edx = 0;  // @106_42c9a0
  L42cb07:;
  SEH_LEAVE();  // @108_42c9a0
  ext_633654(G(u32, 0x6f5630));  // @109_42c9a0
  return eax;  // @110_42c9a0
}
PCREG(42c9a0, lifted_42c9a0);

extern "C" u32 THISCALL lifted_616150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e688);  // @h_616150
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EBX, 4);  // @0_616150
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_ESI, 4);  // @1_616150
  __builtin_memcpy((void *)(u32)(EBP - 28), &SENT_EDI, 4);  // @2_616150
  ebx = ecx;  // @3_616150
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_616150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_616150
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @7_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @8_616150
  { u32 v = (u32)((u32)(7069032)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @9_616150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @10_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 47524), sizeof v); (u32)v; });  // @11_616150
  reg.state = (s32)((u32)(0));  // @12_616150
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4758), sizeof v); (u32)v; }) == (u32)(0)) goto L6162d1;  // @13_616150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @14_616150
  edx = (u32)(64);  // @15_616150
  p0_ = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4758), sizeof v); (u32)v; });  // @16_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_616150
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; });  // @18_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @19_616150
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @20_616150
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @21_616150
  eax = esi;  // @22_616150
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; }));  // @23_616150
  ecx = 0;  // @24_616150
  { u64 t_ = (u64)eax * (u64)(edx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @25_616150
  ecx = (ecx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @26_616150
  ecx = (0u - ecx);  // @27_616150
  p1_ = ecx;  // @28_616150
  ecx = (ecx | eax);  // @29_616150
  p2_ = ecx;  // @30_616150
  eax = ext_41e290_cdecl1((u32)(p2_));  // @31_616150
  ecx = edx = 0;  // @32_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @33_616150
  if ((esi & esi) == 0) goto L6162d1;  // @34_616150
  x1 = _mm_load_ss((const float *)(u32)(6785112));  // @35_616150
  p3_ = (esi & esi);  // @36_616150
  esi = (u32)(eax + 8);  // @37_616150
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @38_616150
  edi = (edi + (u32)(8));  // @39_616150
  L616200:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 8), sizeof v); (u32)v; });  // @41_616150
  x0 = x1;  // @42_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 8), &v, sizeof v); }  // @43_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; });  // @44_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 4), &v, sizeof v); }  // @45_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @47_616150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @48_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @49_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @50_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @51_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @52_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @53_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @54_616150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @55_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @56_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @57_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @58_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @59_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @60_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @61_616150
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(edi + 4)));  // @62_616150
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(edi + 8)));  // @63_616150
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(edi + 12)));  // @64_616150
  _mm_store_ss((float *)(u32)(esi + 36), x0);  // @65_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @66_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @67_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @68_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @69_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @70_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @71_616150
  eax = (u32)(2863311531);  // @72_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @73_616150
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @74_616150
  eax = (u32)(2863311531);  // @75_616150
  p4_ = (edx != 0);  // @76_616150
  edx = (edx >> (u32)(1));  // @77_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @78_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; });  // @79_616150
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @80_616150
  eax = (u32)(2863311531);  // @81_616150
  p5_ = (edx != 0);  // @82_616150
  edx = (edx >> (u32)(1));  // @83_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 53), &v, sizeof v); }  // @84_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 18), sizeof v); (u32)v; });  // @85_616150
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @86_616150
  eax = (u32)(2863311531);  // @87_616150
  p6_ = (edx != 0);  // @88_616150
  edx = (edx >> (u32)(1));  // @89_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 54), &v, sizeof v); }  // @90_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 19), sizeof v); (u32)v; });  // @91_616150
  edi = (edi + (u32)(52));  // @92_616150
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @93_616150
  p7_ = (edx != 0);  // @94_616150
  edx = (edx >> (u32)(1));  // @95_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 55), &v, sizeof v); }  // @96_616150
  esi = (esi + (u32)(64));  // @97_616150
  ebx = (ebx - (u32)(1));  // @98_616150
  if (ebx != 0) goto L616200;  // @99_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @100_616150
  SEH_LEAVE();  // @101_616150
  __asm__ volatile("" :: "Yz"(x0));  // @102_616150
  return eax;  // @103_616150
  L6162d1:;
  eax = ebx;  // @105_616150
  SEH_LEAVE();  // @106_616150
  __asm__ volatile("" :: "Yz"(x0));  // @107_616150
  return eax;  // @108_616150
}
PCREG(616150, lifted_616150);

extern "C" u32 THISCALL lifted_5879e0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5879e0
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_ESI, 4);  // @1_5879e0
  esi = ecx;  // @2_5879e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_5879e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5879e0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @5_5879e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @6_5879e0
  *(volatile u32 *)0x8140f4 = 0;  // @7_5879e0
  ecx = edx = 0;  // @8_5879e0
  ecx = (u32)(EBP - 4);  // @9_5879e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @10_5879e0
  p0_ = ecx;  // @11_5879e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_5879e0
  ecx = eax;  // @13_5879e0
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @14_5879e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(p0_));  // @15_5879e0
  *(volatile u32 *)0x8140f4 = 0;  // @16_5879e0
  ecx = edx = 0;  // @17_5879e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_5879e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_5879e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5879e0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @21_5879e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @22_5879e0
  *(volatile u32 *)0x8140f4 = 0;  // @23_5879e0
  ecx = edx = 0;  // @24_5879e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 111), &v, sizeof v); }  // @25_5879e0
  return eax;  // @26_5879e0
}
PCREG(5879e0, lifted_5879e0);

extern "C" u32 THISCALL lifted_5d4770(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ecx;  // @0_5d4770
  ecx = (u32)(EBP + 8);  // @1_5d4770
  __builtin_memcpy((void *)(u32)(EBP - 12), &SENT_EDI, 4);  // @2_5d4770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_5d4770
  p0_ = ecx;  // @4_5d4770
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @5_5d4770
  ecx = edi;  // @6_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @8_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p0_));  // @9_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @10_5d4770
  ecx = edx = 0;  // @11_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_5d4770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @15_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @16_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @17_5d4770
  ecx = edx = 0;  // @18_5d4770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @19_5d4770
  ecx = edi;  // @20_5d4770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @21_5d4770
  eax = (u32)(esi + 86);  // @22_5d4770
  p1_ = eax;  // @23_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @24_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p1_));  // @25_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @26_5d4770
  ecx = edx = 0;  // @27_5d4770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_5d4770
  eax = (u32)(esi + 90);  // @29_5d4770
  p2_ = eax;  // @30_5d4770
  ecx = edi;  // @31_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @32_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p2_));  // @33_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @34_5d4770
  ecx = edx = 0;  // @35_5d4770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_5d4770
  eax = (u32)(esi + 91);  // @37_5d4770
  p3_ = eax;  // @38_5d4770
  ecx = edi;  // @39_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @40_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p3_));  // @41_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @42_5d4770
  ecx = edx = 0;  // @43_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_5d4770
  ecx = (u32)(EBP + 8);  // @45_5d4770
  p4_ = ecx;  // @46_5d4770
  ecx = edi;  // @47_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @48_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p4_));  // @49_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @50_5d4770
  ecx = edx = 0;  // @51_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_5d4770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @53_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @55_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @56_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @57_5d4770
  ecx = edx = 0;  // @58_5d4770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 99), &v, sizeof v); }  // @59_5d4770
  ecx = (u32)(EBP + 8);  // @60_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @61_5d4770
  p5_ = ecx;  // @62_5d4770
  ecx = edi;  // @63_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @64_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p5_));  // @65_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @66_5d4770
  ecx = edx = 0;  // @67_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_5d4770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @69_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @71_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @72_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @73_5d4770
  ecx = edx = 0;  // @74_5d4770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 107), &v, sizeof v); }  // @75_5d4770
  ecx = (u32)(EBP - 4);  // @76_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @77_5d4770
  p6_ = ecx;  // @78_5d4770
  ecx = edi;  // @79_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @80_5d4770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p6_));  // @81_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @82_5d4770
  ecx = edx = 0;  // @83_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_5d4770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @85_5d4770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @87_5d4770
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @88_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @89_5d4770
  ecx = edx = 0;  // @90_5d4770
  ecx = eax;  // @91_5d4770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @92_5d4770
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @93_5d4770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(7033548), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @94_5d4770
  *(volatile u32 *)0x8140f4 = 0;  // @95_5d4770
  ecx = edx = 0;  // @96_5d4770
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @97_5d4770
  return eax;  // @98_5d4770
}
PCREG(5d4770, lifted_5d4770);

extern "C" u32 THISCALL lifted_422ba0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_422ba0
  eax = (eax ^ EBP);  // @1_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_422ba0
  p0_ = eax;  // @3_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_422ba0
  __builtin_memcpy((void *)(u32)(EBP - 52), &SENT_ESI, 4);  // @5_422ba0
  esi = ecx;  // @6_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @7_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @8_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @9_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @10_422ba0
  __builtin_memcpy((void *)(u32)(EBP - 56), &SENT_EDI, 4);  // @11_422ba0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @12_422ba0
  ecx = (u32)(esi + 9179);  // @13_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @14_422ba0
  eax = ext_4cc5f0_thiscall1(ecx);  // @15_422ba0
  ecx = edx = 0;  // @16_422ba0
  if ((eax & eax) == 0) goto L422e44;  // @17_422ba0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9692), sizeof v); (u32)v; }) != (u32)(0)) goto L422c08;  // @18_422ba0
  eax = ext_41e290_cdecl1((u32)(500000000));  // @19_422ba0
  ecx = edx = 0;  // @20_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9692), &v, sizeof v); }  // @21_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @22_422ba0
  { u32 v = (u32)((u32)(500000000)); __builtin_memcpy((void *)(u32)(esi + 9700), &v, sizeof v); }  // @23_422ba0
  L422c08:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @25_422ba0
  eax = (u32)(edi + 1008);  // @26_422ba0
  ecx = ebx;  // @27_422ba0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @28_422ba0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9692), sizeof v); (u32)v; }));  // @29_422ba0
  eax = (eax + ecx);  // @30_422ba0
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9700), sizeof v); (u32)v; })) goto L422c45;  // @31_422ba0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 9700), &v, sizeof v); }  // @32_422ba0
  p1_ = eax;  // @33_422ba0
  eax = 0;  // @34_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @35_422ba0
  ecx = (ecx ^ EBP);  // @36_422ba0
  eax = ext_633654_thiscall1(ecx);  // @37_422ba0
  ecx = edx = 0;  // @38_422ba0
  return eax;  // @39_422ba0
  L422c45:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @41_422ba0
  x0 = _mm_setzero_ps();  // @42_422ba0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @43_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @44_422ba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @45_422ba0
  eax = (eax + (u32)(4));  // @46_422ba0
  ecx = edx;  // @47_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @48_422ba0
  _mm_storeu_ps((float *)(u32)(EBP - 20), x0);  // @49_422ba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @50_422ba0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @51_422ba0
  eax = (u32)(ecx + 1);  // @52_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @53_422ba0
  L422c74:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @55_422ba0
  ecx = (ecx + 1);  // @56_422ba0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L422c74;  // @57_422ba0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @58_422ba0
  eax = (u32)(15);  // @59_422ba0
  if (ecx > eax) ecx = eax;  // @60_422ba0
  p2_ = eax;  // @61_422ba0
  eax = (u32)(edx + 1);  // @62_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @63_422ba0
  L422c90:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @65_422ba0
  edx = (edx + 1);  // @66_422ba0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L422c90;  // @67_422ba0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @68_422ba0
  eax = (u32)(ecx + 1);  // @69_422ba0
  p3_ = eax;  // @70_422ba0
  p4_ = edx;  // @71_422ba0
  edx = (edx - ecx);  // @72_422ba0
  eax = (u32)(EBP - 20);  // @73_422ba0
  p5_ = edx;  // @74_422ba0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }));  // @75_422ba0
  p6_ = edx;  // @76_422ba0
  p7_ = eax;  // @77_422ba0
  eax = ext_634d22_cdecl3((u32)(p7_), (u32)(p6_), (u32)(p3_));  // @78_422ba0
  ecx = edx = 0;  // @79_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @80_422ba0
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 20));  // @81_422ba0
  p8_ = edi;  // @82_422ba0
  _mm_storeu_ps((float *)(u32)(eax), x0);  // @83_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @84_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @85_422ba0
  ecx = (ecx + (u32)(16));  // @86_422ba0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @87_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @88_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @89_422ba0
  eax = (eax + (u32)(4));  // @90_422ba0
  p9_ = eax;  // @91_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @92_422ba0
  eax = ext_634d22_cdecl3((u32)(p9_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; }), (u32)(p8_));  // @93_422ba0
  ecx = edx = 0;  // @94_422ba0
  p10_ = eax;  // @95_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @96_422ba0
  eax = (eax + edi);  // @97_422ba0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @98_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @99_422ba0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi*8 + 9707), sizeof v); (u32)v; }) != (u32)(0)) goto L422d45;  // @100_422ba0
  eax = (eax - ebx);  // @101_422ba0
  p11_ = eax;  // @102_422ba0
  eax = ext_41e290_cdecl1((u32)(p11_));  // @103_422ba0
  ecx = edx = 0;  // @104_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi*8 + 9707), &v, sizeof v); }  // @105_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @106_422ba0
  ecx = (ecx - ebx);  // @107_422ba0
  p12_ = ecx;  // @108_422ba0
  p13_ = eax;  // @109_422ba0
  eax = ext_634d10_cdecl3((u32)(p13_), (u32)(0), (u32)(p12_));  // @110_422ba0
  ecx = edx = 0;  // @111_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @112_422ba0
  eax = (eax - ebx);  // @113_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi*8 + 9711), &v, sizeof v); }  // @114_422ba0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi*8 + 9707), sizeof v); (u32)v; }) == (u32)(0)) goto L422df6;  // @115_422ba0
  L422d45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @117_422ba0
  edx = 0;  // @118_422ba0
  eax = (eax - ebx);  // @119_422ba0
  if (eax == 0) goto L422d6e;  // @120_422ba0
  L422d51:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi*8 + 9707), sizeof v); (u32)v; });  // @122_422ba0
  p14_ = eax;  // @123_422ba0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx), sizeof v); (u32)v; })) & 0xff);  // @124_422ba0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }))) & 0xff);  // @125_422ba0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @126_422ba0
  edx = (edx + 1);  // @127_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @128_422ba0
  eax = (eax - ebx);  // @129_422ba0
  if (edx != eax) goto L422d51;  // @130_422ba0
  L422d6e:;
  p15_ = eax;  // @132_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @133_422ba0
  eax = (eax - ebx);  // @134_422ba0
  edi = (u32)(eax*4 + 100);  // @135_422ba0
  p16_ = edi;  // @136_422ba0
  eax = ext_41e290_cdecl1((u32)(p16_));  // @137_422ba0
  ecx = edx = 0;  // @138_422ba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @139_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @140_422ba0
  ebx = eax;  // @141_422ba0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @142_422ba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*8 + 9707), sizeof v); (u32)v; });  // @143_422ba0
  p17_ = ecx;  // @144_422ba0
  ecx = (ecx + edx);  // @145_422ba0
  p18_ = ecx;  // @146_422ba0
  p19_ = edx;  // @147_422ba0
  p20_ = ecx;  // @148_422ba0
  ecx = (u32)(ebx + edi);  // @149_422ba0
  p21_ = ecx;  // @150_422ba0
  p22_ = ebx;  // @151_422ba0
  ecx = (u32)(EBP - 29);  // @152_422ba0
  eax = ext_421ed0_thiscall5(ecx, (u32)(p22_), (u32)(p21_), (u32)(p19_), (u32)(p18_));  // @153_422ba0
  ecx = edx = 0;  // @154_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @155_422ba0
  edi = eax;  // @156_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @157_422ba0
  ecx = (ecx - eax);  // @158_422ba0
  p23_ = ecx;  // @159_422ba0
  p24_ = eax;  // @160_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @161_422ba0
  eax = ext_634d22_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*8 + 9707), sizeof v); (u32)v; }), (u32)(p24_), (u32)(p23_));  // @162_422ba0
  ecx = edx = 0;  // @163_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @164_422ba0
  p25_ = edi;  // @165_422ba0
  p26_ = ebx;  // @166_422ba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @167_422ba0
  eax = (eax + (u32)(4));  // @168_422ba0
  p27_ = eax;  // @169_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @170_422ba0
  eax = ext_634d22_cdecl3((u32)(p27_), (u32)(p26_), (u32)(p25_));  // @171_422ba0
  ecx = edx = 0;  // @172_422ba0
  p28_ = eax;  // @173_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @174_422ba0
  eax = (eax + edi);  // @175_422ba0
  p29_ = ebx;  // @176_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @177_422ba0
  eax = ext_634273_cdecl2((u32)(p29_), (u32)(1));  // @178_422ba0
  ecx = edx = 0;  // @179_422ba0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @180_422ba0
  L422df6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9691), sizeof v); (u32)v; }) == (u32)(0)) goto L422e25;  // @182_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @183_422ba0
  ecx = (u32)(esi + 9179);  // @184_422ba0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @185_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @186_422ba0
  eax = (eax - ebx);  // @187_422ba0
  p30_ = eax;  // @188_422ba0
  p31_ = ebx;  // @189_422ba0
  eax = ext_4cc1d0_cdecl2((u32)(p31_), (u32)(p30_));  // @190_422ba0
  ecx = edx = 0;  // @191_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @192_422ba0
  p32_ = eax;  // @193_422ba0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @194_422ba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 104)))(ecx, (u32)(p32_));  // @195_422ba0
  *(volatile u32 *)0x8140f4 = 0;  // @196_422ba0
  ecx = edx = 0;  // @197_422ba0
  L422e25:;
  p33_ = eax;  // @199_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @200_422ba0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9692), sizeof v); (u32)v; }));  // @201_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @202_422ba0
  ecx = (ecx ^ EBP);  // @203_422ba0
  eax = ext_633654_thiscall1(ecx);  // @204_422ba0
  ecx = edx = 0;  // @205_422ba0
  __asm__ volatile("" :: "Yz"(x0));  // @206_422ba0
  return eax;  // @207_422ba0
  L422e44:;
  p34_ = ecx;  // @209_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @210_422ba0
  eax = 0;  // @211_422ba0
  ecx = (ecx ^ EBP);  // @212_422ba0
  eax = ext_633654_thiscall1(ecx);  // @213_422ba0
  ecx = edx = 0;  // @214_422ba0
  __asm__ volatile("" :: "Yz"(x0));  // @215_422ba0
  return eax;  // @216_422ba0
}
PCREG(422ba0, lifted_422ba0);

extern "C" u32 THISCALL lifted_533520(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_533520
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @1_533520
  edi = ecx;  // @2_533520
  if ((ebx & ebx) != 0) goto L53353d;  // @3_533520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_533520
  p0_ = ebx;  // @5_533520
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @6_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(p0_));  // @7_533520
  *(volatile u32 *)0x8140f4 = 0;  // @8_533520
  ecx = edx = 0;  // @9_533520
  return eax;  // @10_533520
  L53353d:;
  esi = 0;  // @12_533520
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21614), sizeof v); (u32)v; }) <= (s32)esi) goto L53356e;  // @13_533520
  L533548:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_533520
  ecx = edi;  // @16_533520
  p1_ = ebx;  // @17_533520
  p2_ = esi;  // @18_533520
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @19_533520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(p2_), (u32)(p1_));  // @20_533520
  *(volatile u32 *)0x8140f4 = 0;  // @21_533520
  ecx = edx = 0;  // @22_533520
  eax = (eax + (u32)(4));  // @23_533520
  p3_ = eax;  // @24_533520
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @25_533520
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676414))((u32)(p3_));  // @26_533520
  *(volatile u32 *)0x8140f4 = 0;  // @27_533520
  ecx = edx = 0;  // @28_533520
  if ((eax & eax) == 0) goto L533581;  // @29_533520
  esi = (esi + 1);  // @30_533520
  if ((s32)esi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21614), sizeof v); (u32)v; })) goto L533548;  // @31_533520
  L53356e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @33_533520
  ecx = edi;  // @34_533520
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @35_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(0));  // @36_533520
  *(volatile u32 *)0x8140f4 = 0;  // @37_533520
  ecx = edx = 0;  // @38_533520
  return eax;  // @39_533520
  L533581:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_533520
  ecx = edi;  // @42_533520
  p4_ = esi;  // @43_533520
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @44_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(p4_));  // @45_533520
  *(volatile u32 *)0x8140f4 = 0;  // @46_533520
  ecx = edx = 0;  // @47_533520
  return eax;  // @48_533520
}
PCREG(533520, lifted_533520);

