// batch200177.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_45f3c0_thiscall2(u32, u32) __asm__("ext_45f3c0");
extern "C" u32 THISCALL ext_4634f0_thiscall2(u32, u32) __asm__("ext_4634f0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_616490_thiscall4(u32, u32, u32, u32) __asm__("ext_616490");
extern "C" u32 THISCALL ext_616580_thiscall4(u32, u32, u32, u32) __asm__("ext_616580");
extern "C" u32 THISCALL ext_616620_thiscall4(u32, u32, u32, u32) __asm__("ext_616620");
extern "C" u32 THISCALL ext_617360_thiscall1(u32) __asm__("ext_617360");
extern "C" u32 THISCALL ext_63cc50_thiscall3(u32, u32, u32) __asm__("ext_63cc50");
extern "C" u32 THISCALL ext_63ead0_thiscall2(u32, u32) __asm__("ext_63ead0");
extern "C" u32 THISCALL ext_6500b0_thiscall1(u32) __asm__("ext_6500b0");
extern "C" u32 THISCALL ext_651180_thiscall1(u32) __asm__("ext_651180");
extern "C" u32 THISCALL ext_658db0_thiscall1(u32) __asm__("ext_658db0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_555570(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_555570
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_;
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_555570
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @45_555570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(736));  // @46_555570
  *(volatile u32 *)0x8140f4 = 0;  // @47_555570
  ecx = edx = 0;  // @48_555570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_555570
  edi = eax;  // @50_555570
  eax = (u32)(EBP - 144);  // @51_555570
  ecx = esi;  // @52_555570
  p1_ = eax;  // @53_555570
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @54_555570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p1_), (u32)(1));  // @55_555570
  *(volatile u32 *)0x8140f4 = 0;  // @56_555570
  ecx = edx = 0;  // @57_555570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_555570
  ecx = eax;  // @59_555570
  reg.state = (s32)((u32)(0));  // @60_555570
  eax = ext_4cc1d0_thiscall1(ecx);  // @61_555570
  ecx = edx = 0;  // @62_555570
  p2_ = eax;  // @63_555570
  p3_ = edi;  // @64_555570
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @65_555570
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p3_), (u32)(6969720), (u32)(p2_));  // @66_555570
  *(volatile u32 *)0x8140f4 = 0;  // @67_555570
  ecx = edx = 0;  // @68_555570
  ecx = (u32)(EBP - 144);  // @69_555570
  eax = ext_4cbec0_thiscall1(ecx);  // @70_555570
  ecx = edx = 0;  // @71_555570
  goto L555688;  // @72_555570
  L555667:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_555570
  ecx = esi;  // @75_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @76_555570
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @77_555570
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @78_555570
  *(volatile u32 *)0x8140f4 = 0;  // @79_555570
  ecx = edx = 0;  // @80_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @81_555570
  eax = (eax & 0xff);  // @82_555570
  p4_ = eax;  // @83_555570
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @84_555570
  ecx = edx = 0;  // @85_555570
  ecx = eax;  // @86_555570
  eax = ext_5002f0_thiscall2(ecx, (u32)(p4_));  // @87_555570
  ecx = edx = 0;  // @88_555570
  L555688:;
  SEH_LEAVE();  // @90_555570
  ext_633654(G(u32, 0x6f5630));  // @91_555570
  return eax;  // @92_555570
}
PCREG(555570, lifted_555570);

extern "C" u32 THISCALL lifted_617150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e6f4);  // @h_617150
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
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
  ecx = 0;  // @22_617150
  eax = ext_658db0_thiscall1(ecx);  // @23_617150
  ecx = edx = 0;  // @24_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @25_617150
  eax = esi;  // @26_617150
  SEH_LEAVE();  // @27_617150
  return eax;  // @28_617150
  L6171e8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @30_617150
  eax = ext_658db0_thiscall1(ecx);  // @31_617150
  ecx = edx = 0;  // @32_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @33_617150
  eax = esi;  // @34_617150
  SEH_LEAVE();  // @35_617150
  return eax;  // @36_617150
  L617209:;
  esi = 0;  // @38_617150
  eax = esi;  // @39_617150
  SEH_LEAVE();  // @40_617150
  return eax;  // @41_617150
  L617221:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @43_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47524), sizeof v); (u32)v; });  // @44_617150
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5104), sizeof v); (u32)v; })) & 0xff);  // @45_617150
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L61726e;  // @46_617150
  eax = ext_41e290_cdecl1((u32)(20));  // @47_617150
  ecx = edx = 0;  // @48_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @49_617150
  reg.state = (s32)((u32)(2));  // @50_617150
  if ((eax & eax) == 0) goto L617345;  // @51_617150
  p0_ = esi;  // @52_617150
  p1_ = edi;  // @53_617150
  p2_ = ebx;  // @54_617150
  ecx = eax;  // @55_617150
  eax = ext_616490_thiscall4(ecx, (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @56_617150
  ecx = edx = 0;  // @57_617150
  SEH_LEAVE();  // @58_617150
  return eax;  // @59_617150
  L61726e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_617150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @62_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @63_617150
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @64_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @65_617150
  x0 = _mm_load_ss((const float *)(u32)(edx + 84));  // @66_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @67_617150
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @68_617150
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6785112)));  // @69_617150
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @70_617150
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L61729b;  // @71_617150
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @72_617150
  L61729b:;
  x0 = _mm_load_ss((const float *)(u32)(edx + 88));  // @74_617150
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6784464)));  // @75_617150
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @76_617150
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L6172af;  // @77_617150
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @78_617150
  L6172af:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @80_617150
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @81_617150
  edx = (u32)(1);  // @82_617150
  x0 = _mm_load_ss((const float *)(u32)(6818400));  // @83_617150
  eax = (eax & 0xff);  // @84_617150
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; }) & (u32)(4352)) == 0) edx = eax;  // @85_617150
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(ecx + 16)));  // @86_617150
  if (fa_ > fb_) goto L61730f;  // @87_617150
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L61730f;  // @88_617150
  eax = ext_41e290_cdecl1((u32)(20));  // @89_617150
  ecx = edx = 0;  // @90_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @91_617150
  reg.state = (s32)((u32)(3));  // @92_617150
  if ((eax & eax) == 0) goto L617345;  // @93_617150
  p3_ = esi;  // @94_617150
  p4_ = edi;  // @95_617150
  p5_ = ebx;  // @96_617150
  ecx = eax;  // @97_617150
  eax = ext_616580_thiscall4(ecx, (u32)(p5_), (u32)(p4_), (u32)(p3_));  // @98_617150
  ecx = edx = 0;  // @99_617150
  SEH_LEAVE();  // @100_617150
  __asm__ volatile("" :: "Yz"(x0));  // @101_617150
  return eax;  // @102_617150
  L61730f:;
  eax = ext_41e290_cdecl1((u32)(20));  // @104_617150
  ecx = edx = 0;  // @105_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @106_617150
  reg.state = (s32)((u32)(4));  // @107_617150
  if ((eax & eax) == 0) goto L617345;  // @108_617150
  p6_ = esi;  // @109_617150
  p7_ = edi;  // @110_617150
  p8_ = ebx;  // @111_617150
  ecx = eax;  // @112_617150
  eax = ext_616620_thiscall4(ecx, (u32)(p8_), (u32)(p7_), (u32)(p6_));  // @113_617150
  ecx = edx = 0;  // @114_617150
  SEH_LEAVE();  // @115_617150
  __asm__ volatile("" :: "Yz"(x0));  // @116_617150
  return eax;  // @117_617150
  L617345:;
  eax = 0;  // @119_617150
  SEH_LEAVE();  // @120_617150
  __asm__ volatile("" :: "Yz"(x0));  // @121_617150
  return eax;  // @122_617150
}
PCREG(617150, lifted_617150);

extern "C" u32 THISCALL lifted_47ac90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  eax = (u32)(eax + ebx*8);  // @9_47ac90
  ecx = 0;  // @10_47ac90
  eax = (eax + (u32)(4));  // @11_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != ecx) ecx = eax;  // @12_47ac90
  if ((ecx & ecx) == 0) goto L47acd2;  // @13_47ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @14_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != esi) goto L47acd5;  // @15_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @16_47ac90
  edi = 0;  // @17_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) == eax) esi = edi;  // @18_47ac90
  goto L47acd5;  // @19_47ac90
  L47acd2:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @21_47ac90
  L47acd5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @23_47ac90
  edi = 0;  // @24_47ac90
  ecx = 0;  // @25_47ac90
  eax = (eax + (u32)(1206));  // @26_47ac90
  L47ace1:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 4), sizeof v); (u32)v; }) != edx) goto L47acea;  // @28_47ac90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == ebx) goto L47acf5;  // @29_47ac90
  L47acea:;
  ecx = (ecx + 1);  // @31_47ac90
  eax = (eax + (u32)(16));  // @32_47ac90
  if (ecx < (u32)(16)) goto L47ace1;  // @33_47ac90
  goto L47acfc;  // @34_47ac90
  L47acf5:;
  edi = (u32)(eax - 4);  // @36_47ac90
  if ((edi & edi) != 0) goto L47ad33;  // @37_47ac90
  L47acfc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @39_47ac90
  ecx = 0;  // @40_47ac90
  L47ad01:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1210), sizeof v); (u32)v; }) == (u32)(0)) goto L47ad15;  // @42_47ac90
  ecx = (ecx + 1);  // @43_47ac90
  eax = (eax + (u32)(16));  // @44_47ac90
  if (ecx < (u32)(16)) goto L47ad01;  // @45_47ac90
  goto L47ad20;  // @46_47ac90
  L47ad15:;
  edi = (u32)(eax + 1202);  // @48_47ac90
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @49_47ac90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @50_47ac90
  L47ad20:;
  if (ecx != (u32)(16)) goto L47ad33;  // @52_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @53_47ac90
  if ((eax & eax) == 0) goto L47ad32;  // @54_47ac90
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @55_47ac90
  eax = ((u32(STDCALL *)(void))(eax))();  // @56_47ac90
  *(volatile u32 *)0x8140f4 = 0;  // @57_47ac90
  ecx = edx = 0;  // @58_47ac90
  goto L47ad33;  // @59_47ac90
  L47ad32:;
  __builtin_trap();  // @61_47ac90
  L47ad33:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @63_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @64_47ac90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @65_47ac90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @66_47ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_47ac90
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @68_47ac90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1452)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1198), sizeof v); (u32)v; }), (u32)(1));  // @69_47ac90
  *(volatile u32 *)0x8140f4 = 0;  // @70_47ac90
  ecx = edx = 0;  // @71_47ac90
  return eax;  // @72_47ac90
}
PCREG(47ac90, lifted_47ac90);

extern "C" u32 THISCALL lifted_63d910(u32 ecx_in) {
  SEH_ENTER(0x66e878);  // @h_63d910
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 56), &SENT_EBX, 4);  // @0_63d910
  __builtin_memcpy((void *)(u32)(EBP - 60), &SENT_ESI, 4);  // @1_63d910
  __builtin_memcpy((void *)(u32)(EBP - 64), &SENT_EDI, 4);  // @2_63d910
  ebx = ecx;  // @3_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @5_63d910
  eax = (eax - (u32)(8));  // @6_63d910
  p0_ = eax;  // @7_63d910
  eax = ext_63cc50_thiscall3(ecx, (u32)(400000), (u32)(p0_));  // @8_63d910
  ecx = edx = 0;  // @9_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @11_63d910
  eax = ext_651180_thiscall1(ecx);  // @12_63d910
  ecx = edx = 0;  // @13_63d910
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L63da34;  // @14_63d910
  esi = 0;  // @15_63d910
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; }) == esi) goto L63d993;  // @16_63d910
  edi = (u32)(ebx + 240);  // @17_63d910
  L63d980:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @19_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_63d910
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @21_63d910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @22_63d910
  *(volatile u32 *)0x8140f4 = 0;  // @23_63d910
  ecx = edx = 0;  // @24_63d910
  esi = (esi + 1);  // @25_63d910
  edi = (u32)(edi + 4);  // @26_63d910
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; })) goto L63d980;  // @27_63d910
  L63d993:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @30_63d910
  eax = ext_6500b0_thiscall1(ecx);  // @31_63d910
  ecx = edx = 0;  // @32_63d910
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L63da34;  // @33_63d910
  ecx = (u32)(EBP - 52);  // @34_63d910
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(1));  // @35_63d910
  ecx = edx = 0;  // @36_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; });  // @37_63d910
  eax = (u32)(EBP - 52);  // @38_63d910
  p1_ = eax;  // @39_63d910
  reg.state = (s32)((u32)(0));  // @40_63d910
  eax = ext_63ead0_thiscall2(ecx, (u32)(p1_));  // @41_63d910
  ecx = edx = 0;  // @42_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @43_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_63d910
  *(volatile u32 *)0x8140f4 = 0x8000000c;  // @45_63d910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 80)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; }), (u32)(12611839));  // @46_63d910
  *(volatile u32 *)0x8140f4 = 0;  // @47_63d910
  ecx = edx = 0;  // @48_63d910
  eax = (u32)(EBP - 24);  // @49_63d910
  p2_ = eax;  // @50_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @51_63d910
  ecx = (u32)(EBP - 52);  // @52_63d910
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @53_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @54_63d910
  *(volatile u32 *)0x8140f4 = 0;  // @55_63d910
  ecx = edx = 0;  // @56_63d910
  eax = (u32)(EBP - 24);  // @57_63d910
  p3_ = eax;  // @58_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @59_63d910
  ecx = (u32)(EBP - 52);  // @60_63d910
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @61_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @62_63d910
  *(volatile u32 *)0x8140f4 = 0;  // @63_63d910
  ecx = edx = 0;  // @64_63d910
  if ((eax & eax) == 0) goto L63da2c;  // @65_63d910
  L63da02:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @67_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @68_63d910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_63d910
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }));  // @70_63d910
  p4_ = eax;  // @71_63d910
  *(volatile u32 *)0x8140f4 = 0x8000000c;  // @72_63d910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }), (u32)(8405232));  // @73_63d910
  *(volatile u32 *)0x8140f4 = 0;  // @74_63d910
  ecx = edx = 0;  // @75_63d910
  eax = (u32)(EBP - 24);  // @76_63d910
  p5_ = eax;  // @77_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @78_63d910
  ecx = (u32)(EBP - 52);  // @79_63d910
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @80_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p5_));  // @81_63d910
  *(volatile u32 *)0x8140f4 = 0;  // @82_63d910
  ecx = edx = 0;  // @83_63d910
  if ((eax & eax) != 0) goto L63da02;  // @84_63d910
  L63da2c:;
  ecx = (u32)(EBP - 52);  // @86_63d910
  eax = ext_4ccfe0_thiscall1(ecx);  // @87_63d910
  ecx = edx = 0;  // @88_63d910
  L63da34:;
  SEH_LEAVE();  // @90_63d910
  return eax;  // @91_63d910
}
PCREG(63d910, lifted_63d910);

extern "C" u32 THISCALL lifted_463620(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6669ef);  // @h_463620
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 28), &SENT_EBX, 4);  // @0_463620
  __builtin_memcpy((void *)(u32)(EBP - 32), &SENT_ESI, 4);  // @1_463620
  __builtin_memcpy((void *)(u32)(EBP - 36), &SENT_EDI, 4);  // @2_463620
  ebx = ecx;  // @3_463620
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_463620
  p0_ = esi;  // @5_463620
  eax = ext_45f3c0_thiscall2(ecx, (u32)(p0_));  // @6_463620
  ecx = edx = 0;  // @7_463620
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L46366b;  // @8_463620
  SEH_LEAVE();  // @9_463620
  return eax;  // @10_463620
  L46366b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @12_463620
  ecx = ebx;  // @13_463620
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @14_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 532)))(ecx);  // @15_463620
  *(volatile u32 *)0x8140f4 = 0;  // @16_463620
  ecx = edx = 0;  // @17_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_463620
  eax = (u32)(ebx + 112);  // @19_463620
  p1_ = eax;  // @20_463620
  ecx = esi;  // @21_463620
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @22_463620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p1_), (u32)(1));  // @23_463620
  *(volatile u32 *)0x8140f4 = 0;  // @24_463620
  ecx = edx = 0;  // @25_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_463620
  eax = (u32)(ebx + 113);  // @27_463620
  p2_ = eax;  // @28_463620
  ecx = esi;  // @29_463620
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @30_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(p2_));  // @31_463620
  *(volatile u32 *)0x8140f4 = 0;  // @32_463620
  ecx = edx = 0;  // @33_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_463620
  ecx = esi;  // @35_463620
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @36_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @37_463620
  *(volatile u32 *)0x8140f4 = 0;  // @38_463620
  ecx = edx = 0;  // @39_463620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @40_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 88), &v, sizeof v); }  // @41_463620
  p3_ = esi;  // @42_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_463620
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @44_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(p3_));  // @45_463620
  *(volatile u32 *)0x8140f4 = 0;  // @46_463620
  ecx = edx = 0;  // @47_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @48_463620
  ecx = 0;  // @49_463620
  edx = (u32)(24);  // @50_463620
  { u64 t_ = (u64)eax * (u64)(edx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @51_463620
  ecx = (ecx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @52_463620
  ecx = (0u - ecx);  // @53_463620
  ecx = (ecx | eax);  // @54_463620
  p4_ = ecx;  // @55_463620
  eax = ext_41e290_cdecl1((u32)(p4_));  // @56_463620
  ecx = edx = 0;  // @57_463620
  edi = eax;  // @58_463620
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @59_463620
  eax = (u32)(EBP + 8);  // @60_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @61_463620
  ecx = esi;  // @62_463620
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @63_463620
  p5_ = eax;  // @64_463620
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @65_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p5_));  // @66_463620
  *(volatile u32 *)0x8140f4 = 0;  // @67_463620
  ecx = edx = 0;  // @68_463620
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L46373a;  // @69_463620
  eax = ext_41e290_cdecl1((u32)(40));  // @70_463620
  ecx = edx = 0;  // @71_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @72_463620
  reg.state = (s32)((u32)(0));  // @73_463620
  if ((eax & eax) == 0) goto L4636f9;  // @74_463620
  ecx = eax;  // @75_463620
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(30));  // @76_463620
  ecx = edx = 0;  // @77_463620
  goto L4636fb;  // @78_463620
  L4636f9:;
  eax = 0;  // @80_463620
  L4636fb:;
  edi = 0;  // @82_463620
  reg.state = (s32)((u32)(4294967295));  // @83_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @84_463620
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == edi) goto L463737;  // @85_463620
  L463710:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @87_463620
  ecx = (u32)(EBP - 20);  // @88_463620
  p6_ = ecx;  // @89_463620
  ecx = esi;  // @90_463620
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @91_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p6_));  // @92_463620
  *(volatile u32 *)0x8140f4 = 0;  // @93_463620
  ecx = edx = 0;  // @94_463620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @95_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_463620
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @97_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @98_463620
  *(volatile u32 *)0x8140f4 = 0;  // @99_463620
  ecx = edx = 0;  // @100_463620
  p7_ = esi;  // @101_463620
  ecx = eax;  // @102_463620
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax + 116), &v, sizeof v); }  // @103_463620
  eax = ext_4634f0_thiscall2(ecx, (u32)(p7_));  // @104_463620
  ecx = edx = 0;  // @105_463620
  edi = (edi + 1);  // @106_463620
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L463710;  // @107_463620
  L463737:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @109_463620
  L46373a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @111_463620
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) == (u32)(0)) goto L4637a9;  // @112_463620
  edi = (edi + (u32)(20));  // @113_463620
  L463750:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_463620
  eax = (u32)(edi - 20);  // @116_463620
  p8_ = eax;  // @117_463620
  ecx = esi;  // @118_463620
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @119_463620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p8_), (u32)(16));  // @120_463620
  *(volatile u32 *)0x8140f4 = 0;  // @121_463620
  ecx = edx = 0;  // @122_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @123_463620
  ecx = esi;  // @124_463620
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @125_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @126_463620
  *(volatile u32 *)0x8140f4 = 0;  // @127_463620
  ecx = edx = 0;  // @128_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 4), &v, sizeof v); }  // @129_463620
  ecx = esi;  // @130_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @131_463620
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @132_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @133_463620
  *(volatile u32 *)0x8140f4 = 0;  // @134_463620
  ecx = edx = 0;  // @135_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 8), &v, sizeof v); }  // @136_463620
  ecx = (u32)(EBP - 24);  // @137_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_463620
  p9_ = ecx;  // @139_463620
  ecx = esi;  // @140_463620
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @141_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p9_));  // @142_463620
  *(volatile u32 *)0x8140f4 = 0;  // @143_463620
  ecx = edx = 0;  // @144_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @145_463620
  if ((eax & eax) == 0) goto L463794;  // @146_463620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @147_463620
  eax = (eax - 1);  // @148_463620
  p10_ = eax;  // @149_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @150_463620
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @151_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, (u32)(p10_));  // @152_463620
  *(volatile u32 *)0x8140f4 = 0;  // @153_463620
  ecx = edx = 0;  // @154_463620
  eax = (eax + (u32)(4));  // @155_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @156_463620
  goto L46379a;  // @157_463620
  L463794:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @159_463620
  L46379a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @161_463620
  edi = (edi + (u32)(24));  // @162_463620
  eax = (eax + 1);  // @163_463620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @164_463620
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; })) goto L463750;  // @165_463620
  L4637a9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @167_463620
  eax = (u32)(ebx + 130);  // @168_463620
  p11_ = eax;  // @169_463620
  ecx = esi;  // @170_463620
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @171_463620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p11_), (u32)(48));  // @172_463620
  *(volatile u32 *)0x8140f4 = 0;  // @173_463620
  ecx = edx = 0;  // @174_463620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @175_463620
  eax = (u32)(ebx + 278);  // @176_463620
  p12_ = eax;  // @177_463620
  ecx = esi;  // @178_463620
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @179_463620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p12_));  // @180_463620
  *(volatile u32 *)0x8140f4 = 0;  // @181_463620
  ecx = edx = 0;  // @182_463620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @183_463620
  ecx = ebx;  // @184_463620
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @185_463620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 608)))(ecx);  // @186_463620
  *(volatile u32 *)0x8140f4 = 0;  // @187_463620
  ecx = edx = 0;  // @188_463620
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @189_463620
  SEH_LEAVE();  // @190_463620
  return eax;  // @191_463620
}
PCREG(463620, lifted_463620);

