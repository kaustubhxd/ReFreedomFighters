// batch200188.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_616490_thiscall4(u32, u32, u32, u32) __asm__("ext_616490");
extern "C" u32 THISCALL ext_616580_thiscall4(u32, u32, u32, u32) __asm__("ext_616580");
extern "C" u32 THISCALL ext_616620_thiscall4(u32, u32, u32, u32) __asm__("ext_616620");
extern "C" u32 THISCALL ext_617360_thiscall1(u32) __asm__("ext_617360");
extern "C" u32 THISCALL ext_658db0_thiscall1(u32) __asm__("ext_658db0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

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
  __asm__ volatile("" ::: "memory");
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) == (u32)(0)) goto L617221;  // @7_617150
  __asm__ volatile("" ::: "memory");
  eax = ext_41e290_cdecl1((u32)(12));  // @8_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @9_617150
  esi = eax;  // @10_617150
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @11_617150
  reg.state = (s32)((u32)(0));  // @12_617150
  if ((esi & esi) == 0) goto L617209;  // @13_617150
  __asm__ volatile("" ::: "memory");
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @14_617150
  ecx = ebx;  // @15_617150
  reg.state = (s32)((u32)(1));  // @16_617150
  { u32 v = (u32)((u32)(7068864)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @17_617150
  eax = ext_617360_thiscall1(ecx);  // @18_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @19_617150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @20_617150
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(16)) != 0) goto L6171e8;  // @21_617150
  __asm__ volatile("" ::: "memory");
  ecx = 0;  // @22_617150
  eax = ext_658db0_thiscall1(ecx);  // @23_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @24_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @25_617150
  eax = esi;  // @26_617150
  SEH_LEAVE();  // @27_617150
  return eax;  // @28_617150
  L6171e8:;
  __asm__ volatile("" ::: "memory");
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @30_617150
  eax = ext_658db0_thiscall1(ecx);  // @31_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @32_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @33_617150
  eax = esi;  // @34_617150
  SEH_LEAVE();  // @35_617150
  return eax;  // @36_617150
  L617209:;
  __asm__ volatile("" ::: "memory");
  esi = 0;  // @38_617150
  eax = esi;  // @39_617150
  SEH_LEAVE();  // @40_617150
  return eax;  // @41_617150
  L617221:;
  __asm__ volatile("" ::: "memory");
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @43_617150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47524), sizeof v); (u32)v; });  // @44_617150
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5104), sizeof v); (u32)v; })) & 0xff);  // @45_617150
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L61726e;  // @46_617150
  __asm__ volatile("" ::: "memory");
  eax = ext_41e290_cdecl1((u32)(20));  // @47_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @48_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @49_617150
  reg.state = (s32)((u32)(2));  // @50_617150
  if ((eax & eax) == 0) goto L617345;  // @51_617150
  __asm__ volatile("" ::: "memory");
  p0_ = esi;  // @52_617150
  p1_ = edi;  // @53_617150
  p2_ = ebx;  // @54_617150
  ecx = eax;  // @55_617150
  eax = ext_616490_thiscall4(ecx, (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @56_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @57_617150
  SEH_LEAVE();  // @58_617150
  return eax;  // @59_617150
  L61726e:;
  __asm__ volatile("" ::: "memory");
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
  __asm__ volatile("" ::: "memory");
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @72_617150
  L61729b:;
  __asm__ volatile("" ::: "memory");
  x0 = _mm_load_ss((const float *)(u32)(edx + 88));  // @74_617150
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(6784464)));  // @75_617150
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @76_617150
  if (__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L6172af;  // @77_617150
  __asm__ volatile("" ::: "memory");
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @78_617150
  L6172af:;
  __asm__ volatile("" ::: "memory");
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @80_617150
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @81_617150
  edx = (u32)(1);  // @82_617150
  x0 = _mm_load_ss((const float *)(u32)(6818400));  // @83_617150
  eax = (eax & 0xff);  // @84_617150
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; }) & (u32)(4352)) == 0) edx = eax;  // @85_617150
  __asm__ volatile("" ::: "memory");
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(ecx + 16)));  // @86_617150
  if (fa_ > fb_) goto L61730f;  // @87_617150
  __asm__ volatile("" ::: "memory");
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L61730f;  // @88_617150
  __asm__ volatile("" ::: "memory");
  eax = ext_41e290_cdecl1((u32)(20));  // @89_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @90_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @91_617150
  reg.state = (s32)((u32)(3));  // @92_617150
  if ((eax & eax) == 0) goto L617345;  // @93_617150
  __asm__ volatile("" ::: "memory");
  p3_ = esi;  // @94_617150
  p4_ = edi;  // @95_617150
  p5_ = ebx;  // @96_617150
  ecx = eax;  // @97_617150
  eax = ext_616580_thiscall4(ecx, (u32)(p5_), (u32)(p4_), (u32)(p3_));  // @98_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @99_617150
  SEH_LEAVE();  // @100_617150
  __asm__ volatile("" :: "Yz"(x0));  // @101_617150
  return eax;  // @102_617150
  L61730f:;
  __asm__ volatile("" ::: "memory");
  eax = ext_41e290_cdecl1((u32)(20));  // @104_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @105_617150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @106_617150
  reg.state = (s32)((u32)(4));  // @107_617150
  if ((eax & eax) == 0) goto L617345;  // @108_617150
  __asm__ volatile("" ::: "memory");
  p6_ = esi;  // @109_617150
  p7_ = edi;  // @110_617150
  p8_ = ebx;  // @111_617150
  ecx = eax;  // @112_617150
  eax = ext_616620_thiscall4(ecx, (u32)(p8_), (u32)(p7_), (u32)(p6_));  // @113_617150
  __asm__ volatile("" ::: "memory");
  ecx = edx = 0;  // @114_617150
  SEH_LEAVE();  // @115_617150
  __asm__ volatile("" :: "Yz"(x0));  // @116_617150
  return eax;  // @117_617150
  L617345:;
  __asm__ volatile("" ::: "memory");
  eax = 0;  // @119_617150
  SEH_LEAVE();  // @120_617150
  __asm__ volatile("" :: "Yz"(x0));  // @121_617150
  return eax;  // @122_617150
}
PCREG(617150, lifted_617150);

