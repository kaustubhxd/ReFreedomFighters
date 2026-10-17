// batch200164.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 THISCALL ext_64a880_thiscall1(u32) __asm__("ext_64a880");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_556780(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_556780
  eax = (eax ^ EBP);  // @1_556780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_556780
  __builtin_memcpy((void *)(u32)(EBP - 56), &SENT_ESI, 4);  // @4_556780
  __builtin_memcpy((void *)(u32)(EBP - 60), &SENT_EDI, 4);  // @5_556780
  edi = ecx;  // @6_556780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @7_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @8_556780
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @9_556780
  ecx = edx = 0;  // @10_556780
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @11_556780
  ecx = (ecx - (u32)(3));  // @12_556780
  if (ecx == 0) goto L5567fd;  // @13_556780
  ecx = (ecx - (u32)(1));  // @14_556780
  if (ecx == 0) goto L5567f0;  // @15_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @16_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @18_556780
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(273));  // @19_556780
  ecx = edx = 0;  // @20_556780
  p0_ = eax;  // @21_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @22_556780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(6932144), (u32)(6932912));  // @23_556780
  ecx = edx = 0;  // @24_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @25_556780
  if ((eax & eax) == 0) goto L5567eb;  // @26_556780
  eax = ((u32(STDCALL *)(void))(eax))();  // @27_556780
  ecx = edx = 0;  // @28_556780
  esi = 0;  // @29_556780
  goto L5567ff;  // @30_556780
  L5567eb:;
  __builtin_trap();  // @32_556780
  L5567f0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @36_556780
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @37_556780
  ecx = edx = 0;  // @38_556780
  esi = eax;  // @39_556780
  goto L5567ff;  // @40_556780
  L5567fd:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @42_556780
  L5567ff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @44_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @45_556780
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @46_556780
  ecx = edx = 0;  // @47_556780
  ecx = eax;  // @48_556780
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @49_556780
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; })) & 0xff);  // @50_556780
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L556855;  // @51_556780
  if ((ecx & 0xff) == (u32)(1)) goto L556855;  // @52_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @53_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @55_556780
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(260));  // @56_556780
  ecx = edx = 0;  // @57_556780
  p1_ = eax;  // @58_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @59_556780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p1_), (u32)(6932144), (u32)(6932792));  // @60_556780
  ecx = edx = 0;  // @61_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @62_556780
  if ((eax & eax) == 0) goto L556854;  // @63_556780
  eax = ((u32(STDCALL *)(void))(eax))();  // @64_556780
  ecx = edx = 0;  // @65_556780
  goto L556855;  // @66_556780
  L556854:;
  __builtin_trap();  // @68_556780
  L556855:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @70_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @71_556780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @72_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @73_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @74_556780
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @75_556780
  ecx = edx = 0;  // @76_556780
  ecx = eax;  // @77_556780
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @78_556780
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; })) & 0xff);  // @79_556780
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L5568b3;  // @80_556780
  if ((ecx & 0xff) == (u32)(1)) goto L5568b3;  // @81_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @82_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @84_556780
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(260));  // @85_556780
  ecx = edx = 0;  // @86_556780
  p2_ = eax;  // @87_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_556780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p2_), (u32)(6932144), (u32)(6932792));  // @89_556780
  ecx = edx = 0;  // @90_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @91_556780
  if ((eax & eax) == 0) goto L5568b2;  // @92_556780
  eax = ((u32(STDCALL *)(void))(eax))();  // @93_556780
  ecx = edx = 0;  // @94_556780
  goto L5568b3;  // @95_556780
  L5568b2:;
  __builtin_trap();  // @97_556780
  L5568b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @99_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @100_556780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @101_556780
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }) == (u32)(0)) goto L556a68;  // @102_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @103_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @104_556780
  p3_ = esi;  // @105_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @107_556780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(p3_), (u32)(0), (u32)(6969340), (u32)(1282));  // @108_556780
  ecx = edx = 0;  // @109_556780
  eax = (eax & 0xffff);  // @110_556780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @111_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @112_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @113_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @114_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @115_556780
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @116_556780
  ecx = edx = 0;  // @117_556780
  esi = eax;  // @118_556780
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @119_556780
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) != (u32)(0)) goto L55693b;  // @120_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @121_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @122_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; });  // @123_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 604), sizeof v); (u32)v; });  // @125_556780
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6840132), (u32)(0));  // @126_556780
  ecx = edx = 0;  // @127_556780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @128_556780
  if ((eax & eax) == 0) goto L556a68;  // @129_556780
  L55693b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @131_556780
  eax = (u32)(EBP - 28);  // @132_556780
  p4_ = eax;  // @133_556780
  eax = ext_4db7c0_thiscall2(ecx, (u32)(p4_));  // @134_556780
  ecx = edx = 0;  // @135_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @136_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @137_556780
  if ((ecx & ecx) == 0) goto L556a68;  // @138_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_556780
  edx = (u32)(EBP - 52);  // @140_556780
  p5_ = edx;  // @141_556780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p5_));  // @142_556780
  ecx = edx = 0;  // @143_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @144_556780
  edx = (u32)(EBP - 52);  // @145_556780
  p6_ = edx;  // @146_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @147_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @149_556780
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p6_));  // @150_556780
  ecx = edx = 0;  // @151_556780
  edx = eax;  // @152_556780
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; }) == (u32)(0)) goto L556a68;  // @153_556780
  L556980:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @155_556780
  p7_ = edx;  // @156_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @157_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @158_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @159_556780
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p7_));  // @160_556780
  ecx = edx = 0;  // @161_556780
  esi = eax;  // @162_556780
  ecx = esi;  // @163_556780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @164_556780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; });  // @165_556780
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @166_556780
  ecx = edx = 0;  // @167_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @168_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @169_556780
  ecx = (ecx >> (u32)(10));  // @170_556780
  ecx = (ecx & 0xffffff00u) | (((~(ecx & 0xff))) & 0xff);  // @171_556780
  if (((ecx & 0xff) & (u32)(1)) == 0) goto L556a4b;  // @172_556780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @173_556780
  ecx = (u32)(EBP - 16);  // @174_556780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @175_556780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @176_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_556780
  p8_ = ecx;  // @178_556780
  ecx = esi;  // @179_556780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p8_));  // @180_556780
  ecx = edx = 0;  // @181_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @182_556780
  edx = (u32)(EBP - 16);  // @183_556780
  p9_ = edx;  // @184_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @185_556780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, (u32)(p9_));  // @186_556780
  ecx = edx = 0;  // @187_556780
  x1 = _mm_load_ss((const float *)(u32)(EBP - 16));  // @188_556780
  x0 = _mm_load_ss((const float *)(u32)(EBP - 28));  // @189_556780
  x2 = _mm_castpd_ps(_mm_load_sd((const double *)(u32)(6802768)));  // @190_556780
  x1 = _mm_castpd_ps(_mm_cvtps_pd(x1));  // @191_556780
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @192_556780
  x1 = _mm_and_ps(x1, x2);  // @193_556780
  fa_ = _mm_cvtsd_f64(_mm_castps_pd(x0)); fb_ = _mm_cvtsd_f64(_mm_castps_pd(x1));  // @194_556780
  if (!(fa_ > fb_)) goto L556a4b;  // @195_556780
  x1 = _mm_load_ss((const float *)(u32)(EBP - 12));  // @196_556780
  x0 = _mm_load_ss((const float *)(u32)(EBP - 24));  // @197_556780
  x1 = _mm_castpd_ps(_mm_cvtps_pd(x1));  // @198_556780
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @199_556780
  x1 = _mm_and_ps(x1, x2);  // @200_556780
  fa_ = _mm_cvtsd_f64(_mm_castps_pd(x0)); fb_ = _mm_cvtsd_f64(_mm_castps_pd(x1));  // @201_556780
  if (!(fa_ > fb_)) goto L556a4b;  // @202_556780
  x1 = _mm_load_ss((const float *)(u32)(EBP - 8));  // @203_556780
  x0 = _mm_load_ss((const float *)(u32)(EBP - 20));  // @204_556780
  x1 = _mm_castpd_ps(_mm_cvtps_pd(x1));  // @205_556780
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @206_556780
  x1 = _mm_and_ps(x1, x2);  // @207_556780
  fa_ = _mm_cvtsd_f64(_mm_castps_pd(x0)); fb_ = _mm_cvtsd_f64(_mm_castps_pd(x1));  // @208_556780
  if (!(fa_ > fb_)) goto L556a4b;  // @209_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @210_556780
  ecx = (u32)(EBP - 40);  // @211_556780
  p10_ = ecx;  // @212_556780
  ecx = esi;  // @213_556780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 296)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }), (u32)(p10_), (u32)(0));  // @214_556780
  ecx = edx = 0;  // @215_556780
  L556a4b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @217_556780
  edx = (u32)(EBP - 52);  // @218_556780
  p11_ = edx;  // @219_556780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @220_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @221_556780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @222_556780
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p11_));  // @223_556780
  ecx = edx = 0;  // @224_556780
  edx = eax;  // @225_556780
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; }) != (u32)(0)) goto L556980;  // @226_556780
  L556a68:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @228_556780
  ecx = (ecx ^ EBP);  // @229_556780
  eax = ext_633654_thiscall1(ecx);  // @230_556780
  ecx = edx = 0;  // @231_556780
  __asm__ volatile("" :: "Yz"(x0));  // @232_556780
  return eax;  // @233_556780
}
PCREG(556780, lifted_556780);

extern "C" u32 THISCALL lifted_491b70(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_491b70
  ebx = ecx;  // @1_491b70
  __builtin_memcpy((void *)(u32)(EBP - 36), &SENT_EDI, 4);  // @2_491b70
  ecx = esi;  // @3_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @5_491b70
  ecx = edx = 0;  // @6_491b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_491b70
  eax = (eax + eax);  // @8_491b70
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 23853), sizeof v); (u32)v; }));  // @9_491b70
  edi = 0;  // @10_491b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @11_491b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @12_491b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; });  // @13_491b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 340)))(ecx);  // @15_491b70
  ecx = edx = 0;  // @16_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_491b70
  ecx = (u32)(EBP - 24);  // @18_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @19_491b70
  ecx = esi;  // @20_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @21_491b70
  ecx = edx = 0;  // @22_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_491b70
  ecx = (u32)(EBP - 24);  // @24_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @25_491b70
  ecx = esi;  // @26_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @27_491b70
  ecx = edx = 0;  // @28_491b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @29_491b70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == edi) goto L491c3a;  // @30_491b70
  x1 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; })));  // @31_491b70
  x1 = _mm_cvtepi32_ps(_mm_castps_si128(x1));  // @32_491b70
  _mm_store_ss((float *)(u32)(EBP - 12), x1);  // @33_491b70
  L491bd7:;
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)edi));  // @35_491b70
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @36_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @38_491b70
  ecx = ebx;  // @39_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @40_491b70
  x0 = _mm_div_ss(x0, x1);  // @41_491b70
  _mm_store_ss((float *)(u32)(EBP - 4), x0);  // @42_491b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @43_491b70
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @44_491b70
  T[0] = ((double(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @45_491b70
  ecx = edx = 0;  // @46_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_491b70
  T[0] = T[0];  // @48_491b70
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @49_491b70
  edi = (edi + 1);  // @50_491b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @51_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @53_491b70
  ecx = edx = 0;  // @54_491b70
  if ((eax & eax) == 0) goto L491c21;  // @55_491b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @56_491b70
  if ((ecx & ecx) == 0) goto L491c21;  // @57_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @59_491b70
  ecx = edx = 0;  // @60_491b70
  L491c21:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_491b70
  ecx = (u32)(EBP - 24);  // @63_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @64_491b70
  ecx = esi;  // @65_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @66_491b70
  ecx = edx = 0;  // @67_491b70
  x1 = _mm_load_ss((const float *)(u32)(EBP - 12));  // @68_491b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @69_491b70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L491bd7;  // @70_491b70
  L491c3a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 23849), sizeof v); (u32)v; });  // @72_491b70
  if ((esi & esi) == 0) goto L491ced;  // @73_491b70
  L491c48:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @75_491b70
  edi = (edi + 1);  // @76_491b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @77_491b70
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L491ce3;  // @78_491b70
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; })));  // @79_491b70
  x1 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)edi));  // @80_491b70
  x1 = _mm_cvtepi32_ps(_mm_castps_si128(x1));  // @81_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @82_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @83_491b70
  ecx = ebx;  // @84_491b70
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @85_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @86_491b70
  x1 = _mm_div_ss(x1, x0);  // @87_491b70
  _mm_store_ss((float *)(u32)(EBP - 4), x1);  // @88_491b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @89_491b70
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @90_491b70
  T[0] = ((double(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @91_491b70
  ecx = edx = 0;  // @92_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @93_491b70
  T[0] = T[0];  // @94_491b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @95_491b70
  if ((eax & eax) == 0) goto L491ce0;  // @96_491b70
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(512)) != 0) goto L491ca6;  // @97_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @98_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @99_491b70
  eax = (eax >> (u32)(10));  // @100_491b70
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @101_491b70
  if (((eax & 0xff) & (u32)(1)) == 0) goto L491cd5;  // @102_491b70
  L491ca6:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) != 0) goto L491cbd;  // @104_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_491b70
  ecx = esi;  // @106_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @107_491b70
  ecx = edx = 0;  // @108_491b70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @109_491b70
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L491cd5;  // @110_491b70
  L491cbd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @112_491b70
  ecx = esi;  // @113_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 76)))(ecx);  // @114_491b70
  ecx = edx = 0;  // @115_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_491b70
  ecx = esi;  // @117_491b70
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @118_491b70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(256))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @119_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @120_491b70
  ecx = edx = 0;  // @121_491b70
  L491cd5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @123_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 488)))(ecx);  // @125_491b70
  ecx = edx = 0;  // @126_491b70
  L491ce0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @128_491b70
  L491ce3:;
  esi = eax;  // @130_491b70
  if ((eax & eax) != 0) goto L491c48;  // @131_491b70
  L491ced:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 23849), sizeof v); (u32)v; });  // @133_491b70
  if ((esi & esi) == 0) goto L491d93;  // @134_491b70
  L491d00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @136_491b70
  edi = (edi + 1);  // @137_491b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @138_491b70
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L491d86;  // @139_491b70
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; })));  // @140_491b70
  x1 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)edi));  // @141_491b70
  x1 = _mm_cvtepi32_ps(_mm_castps_si128(x1));  // @142_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @143_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @144_491b70
  ecx = ebx;  // @145_491b70
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @146_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @147_491b70
  x1 = _mm_div_ss(x1, x0);  // @148_491b70
  _mm_store_ss((float *)(u32)(EBP - 4), x1);  // @149_491b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @150_491b70
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @151_491b70
  T[0] = ((double(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @152_491b70
  ecx = edx = 0;  // @153_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @154_491b70
  T[0] = T[0];  // @155_491b70
  if ((eax & eax) == 0) goto L491d86;  // @156_491b70
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(512)) != 0) goto L491d57;  // @157_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @158_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @159_491b70
  eax = (eax >> (u32)(10));  // @160_491b70
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @161_491b70
  if (((eax & 0xff) & (u32)(1)) == 0) goto L491d86;  // @162_491b70
  L491d57:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) != 0) goto L491d6e;  // @164_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @165_491b70
  ecx = esi;  // @166_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @167_491b70
  ecx = edx = 0;  // @168_491b70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @169_491b70
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L491d86;  // @170_491b70
  L491d6e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @172_491b70
  ecx = esi;  // @173_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 76)))(ecx);  // @174_491b70
  ecx = edx = 0;  // @175_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @176_491b70
  ecx = esi;  // @177_491b70
  { u32 v = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; })); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @178_491b70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(256))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @179_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @180_491b70
  ecx = edx = 0;  // @181_491b70
  L491d86:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @183_491b70
  eax = esi;  // @184_491b70
  if ((eax & eax) != 0) goto L491d00;  // @185_491b70
  L491d93:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @187_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @188_491b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @189_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @190_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @191_491b70
  ecx = edx = 0;  // @192_491b70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @193_491b70
  ecx = (u32)(EBP - 24);  // @194_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @195_491b70
  ecx = esi;  // @196_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @197_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @198_491b70
  ecx = edx = 0;  // @199_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_491b70
  ecx = (u32)(EBP - 24);  // @201_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @202_491b70
  ecx = esi;  // @203_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @204_491b70
  ecx = edx = 0;  // @205_491b70
  esi = eax;  // @206_491b70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L491e51;  // @207_491b70
  x1 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; })));  // @208_491b70
  x1 = _mm_cvtepi32_ps(_mm_castps_si128(x1));  // @209_491b70
  _mm_store_ss((float *)(u32)(EBP - 12), x1);  // @210_491b70
  L491de0:;
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)edi));  // @212_491b70
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @213_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @214_491b70
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @215_491b70
  ecx = ebx;  // @216_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @217_491b70
  x0 = _mm_div_ss(x0, x1);  // @218_491b70
  _mm_store_ss((float *)(u32)(EBP - 4), x0);  // @219_491b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @220_491b70
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @221_491b70
  T[0] = ((double(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @222_491b70
  ecx = edx = 0;  // @223_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @224_491b70
  T[0] = T[0];  // @225_491b70
  { u32 v = (u32)((u32)(esi)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @226_491b70
  edi = (edi + 1);  // @227_491b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @228_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @229_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @230_491b70
  ecx = edx = 0;  // @231_491b70
  esi = eax;  // @232_491b70
  if ((esi & esi) == 0) goto L491e38;  // @233_491b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @234_491b70
  { u32 v = (u32)((u32)(8388608)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @235_491b70
  ecx = esi;  // @236_491b70
  eax = ext_4dc630_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @237_491b70
  ecx = edx = 0;  // @238_491b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @239_491b70
  if ((ecx & ecx) == 0) goto L491e38;  // @240_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @241_491b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @242_491b70
  ecx = edx = 0;  // @243_491b70
  L491e38:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @245_491b70
  edx = (u32)(EBP - 24);  // @246_491b70
  { u32 v = (u32)((u32)(edx)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @247_491b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @248_491b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }));  // @249_491b70
  ecx = edx = 0;  // @250_491b70
  esi = eax;  // @251_491b70
  x1 = _mm_load_ss((const float *)(u32)(EBP - 12));  // @252_491b70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L491de0;  // @253_491b70
  L491e51:;
  __asm__ volatile("" :: "Yz"(x0));  // @255_491b70
  return eax;  // @256_491b70
}
PCREG(491b70, lifted_491b70);

extern "C" u32 THISCALL lifted_6159f0(u32 ecx_in) {
  SEH_ENTER(0x66e59e);  // @h_6159f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EBX, 4);  // @0_6159f0
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_ESI, 4);  // @1_6159f0
  esi = ecx;  // @2_6159f0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65621), sizeof v); (u32)v; })) & 0xff);  // @3_6159f0
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) + 1)) & 0xff);  // @4_6159f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65885), sizeof v); (u32)v; }) != (u32)(0)) goto L615a70;  // @5_6159f0
  eax = ext_41e290_cdecl1((u32)(20));  // @6_6159f0
  ecx = edx = 0;  // @7_6159f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @8_6159f0
  if ((eax & eax) == 0) goto L615a61;  // @9_6159f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @10_6159f0
  ecx = (ecx + (u32)(568));  // @11_6159f0
  { u32 v = (u32)((u32)(7068576)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @12_6159f0
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @13_6159f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @14_6159f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @15_6159f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @16_6159f0
  goto L615a63;  // @17_6159f0
  L615a61:;
  eax = 0;  // @19_6159f0
  L615a63:;
  reg.state = (s32)((u32)(4294967295));  // @21_6159f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65885), &v, sizeof v); }  // @22_6159f0
  L615a70:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65873), sizeof v); (u32)v; }) != (u32)(0)) goto L615ac1;  // @24_6159f0
  eax = ext_41e290_cdecl1((u32)(20));  // @25_6159f0
  ecx = edx = 0;  // @26_6159f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @27_6159f0
  if ((eax & eax) == 0) goto L615ab2;  // @28_6159f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @29_6159f0
  ecx = (ecx + (u32)(568));  // @30_6159f0
  { u32 v = (u32)((u32)(7068636)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @31_6159f0
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @32_6159f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @33_6159f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @34_6159f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @35_6159f0
  goto L615ab4;  // @36_6159f0
  L615ab2:;
  eax = 0;  // @38_6159f0
  L615ab4:;
  reg.state = (s32)((u32)(4294967295));  // @40_6159f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65873), &v, sizeof v); }  // @41_6159f0
  L615ac1:;
  ecx = esi;  // @43_6159f0
  eax = ext_64a880_thiscall1(ecx);  // @44_6159f0
  ecx = edx = 0;  // @45_6159f0
  SEH_LEAVE();  // @46_6159f0
  return eax;  // @47_6159f0
}
PCREG(6159f0, lifted_6159f0);

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

