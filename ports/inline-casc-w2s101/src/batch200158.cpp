// batch200158.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_61bac0_stdcall2(u32, u32) __asm__("ext_61bac0");
extern "C" u32 THISCALL ext_4321c0_thiscall2(u32, u32) __asm__("ext_4321c0");
extern "C" u32 THISCALL ext_43b820_thiscall2(u32, u32) __asm__("ext_43b820");
extern "C" u32 THISCALL ext_43b9a0_thiscall2(u32, u32) __asm__("ext_43b9a0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_5875c0_thiscall4(u32, u32, u32, u32) __asm__("ext_5875c0");
extern "C" u32 THISCALL ext_602cd0_thiscall2(u32, u32) __asm__("ext_602cd0");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cbec0_cdecl1(...) __asm__("ext_4cbec0");
extern "C" u32 ext_4cc5f0_cdecl1(...) __asm__("ext_4cc5f0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_5530a0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_5530a0
  eax = (eax ^ EBP);  // @1_5530a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_5530a0
  __builtin_memcpy((void *)(u32)(EBP - 28), &SENT_EBX, 4);  // @3_5530a0
  __builtin_memcpy((void *)(u32)(EBP - 32), &SENT_ESI, 4);  // @4_5530a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_5530a0
  __builtin_memcpy((void *)(u32)(EBP - 36), &SENT_EDI, 4);  // @6_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @7_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @8_5530a0
  ecx = edx = 0;  // @9_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @10_5530a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @11_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @12_5530a0
  ecx = edx = 0;  // @13_5530a0
  edi = eax;  // @14_5530a0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @15_5530a0
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L553110;  // @16_5530a0
  if ((ecx & 0xff) == (u32)(2)) goto L553110;  // @17_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @18_5530a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @20_5530a0
  ecx = edx = 0;  // @21_5530a0
  p0_ = eax;  // @22_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @23_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(6932144), (u32)(6932792));  // @24_5530a0
  ecx = edx = 0;  // @25_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @26_5530a0
  if ((eax & eax) == 0) goto L55310f;  // @27_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @28_5530a0
  ecx = edx = 0;  // @29_5530a0
  goto L553110;  // @30_5530a0
  L55310f:;
  __builtin_trap();  // @32_5530a0
  L553110:;
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @34_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @35_5530a0
  _mm_store_ss((float *)(u32)(EBP - 24), x0);  // @36_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @37_5530a0
  ecx = edx = 0;  // @38_5530a0
  edi = eax;  // @39_5530a0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @40_5530a0
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L553167;  // @41_5530a0
  if ((ecx & 0xff) == (u32)(2)) goto L553167;  // @42_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @43_5530a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @45_5530a0
  ecx = edx = 0;  // @46_5530a0
  p1_ = eax;  // @47_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p1_), (u32)(6932144), (u32)(6932792));  // @49_5530a0
  ecx = edx = 0;  // @50_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @51_5530a0
  if ((eax & eax) == 0) goto L553166;  // @52_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @53_5530a0
  ecx = edx = 0;  // @54_5530a0
  goto L553167;  // @55_5530a0
  L553166:;
  __builtin_trap();  // @57_5530a0
  L553167:;
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @59_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @60_5530a0
  _mm_store_ss((float *)(u32)(EBP - 20), x0);  // @61_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @62_5530a0
  ecx = edx = 0;  // @63_5530a0
  edi = eax;  // @64_5530a0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @65_5530a0
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L5531be;  // @66_5530a0
  if ((ecx & 0xff) == (u32)(2)) goto L5531be;  // @67_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @68_5530a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @70_5530a0
  ecx = edx = 0;  // @71_5530a0
  p2_ = eax;  // @72_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @73_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p2_), (u32)(6932144), (u32)(6932792));  // @74_5530a0
  ecx = edx = 0;  // @75_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @76_5530a0
  if ((eax & eax) == 0) goto L5531bd;  // @77_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @78_5530a0
  ecx = edx = 0;  // @79_5530a0
  goto L5531be;  // @80_5530a0
  L5531bd:;
  __builtin_trap();  // @82_5530a0
  L5531be:;
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @84_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @85_5530a0
  _mm_store_ss((float *)(u32)(EBP - 16), x0);  // @86_5530a0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 20));  // @87_5530a0
  _mm_store_ss((float *)(u32)(EBP - 12), x0);  // @88_5530a0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 24));  // @89_5530a0
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @90_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(4));  // @91_5530a0
  ecx = edx = 0;  // @92_5530a0
  edi = eax;  // @93_5530a0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @94_5530a0
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L553229;  // @95_5530a0
  if ((ecx & 0xff) == (u32)(2)) goto L553229;  // @96_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @97_5530a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @99_5530a0
  ecx = edx = 0;  // @100_5530a0
  p3_ = eax;  // @101_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @102_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p3_), (u32)(6932144), (u32)(6932792));  // @103_5530a0
  ecx = edx = 0;  // @104_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @105_5530a0
  if ((eax & eax) == 0) goto L553228;  // @106_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @107_5530a0
  ecx = edx = 0;  // @108_5530a0
  goto L553229;  // @109_5530a0
  L553228:;
  __builtin_trap();  // @111_5530a0
  L553229:;
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @113_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @114_5530a0
  _mm_store_ss((float *)(u32)(EBP - 24), x0);  // @115_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @116_5530a0
  ecx = edx = 0;  // @117_5530a0
  edi = eax;  // @118_5530a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @119_5530a0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L55327f;  // @120_5530a0
  if ((eax & 0xff) == (u32)(2)) goto L55327f;  // @121_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @122_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @124_5530a0
  ecx = edx = 0;  // @125_5530a0
  p4_ = eax;  // @126_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @127_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p4_), (u32)(6932144), (u32)(6932792));  // @128_5530a0
  ecx = edx = 0;  // @129_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @130_5530a0
  if ((eax & eax) == 0) goto L55327e;  // @131_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @132_5530a0
  ecx = edx = 0;  // @133_5530a0
  goto L55327f;  // @134_5530a0
  L55327e:;
  __builtin_trap();  // @136_5530a0
  L55327f:;
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @138_5530a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @139_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @140_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @141_5530a0
  ecx = edx = 0;  // @142_5530a0
  edi = eax;  // @143_5530a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @144_5530a0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5532d6;  // @145_5530a0
  if ((eax & 0xff) == (u32)(2)) goto L5532d6;  // @146_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @147_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @149_5530a0
  ecx = edx = 0;  // @150_5530a0
  p5_ = eax;  // @151_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @152_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p5_), (u32)(6932144), (u32)(6932792));  // @153_5530a0
  ecx = edx = 0;  // @154_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @155_5530a0
  if ((eax & eax) == 0) goto L5532d5;  // @156_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @157_5530a0
  ecx = edx = 0;  // @158_5530a0
  goto L5532d6;  // @159_5530a0
  L5532d5:;
  __builtin_trap();  // @161_5530a0
  L5532d6:;
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @163_5530a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @164_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @165_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @166_5530a0
  ecx = edx = 0;  // @167_5530a0
  edi = eax;  // @168_5530a0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @169_5530a0
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L55332e;  // @170_5530a0
  if ((ecx & 0xff) == (u32)(2)) goto L55332e;  // @171_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @172_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @173_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @174_5530a0
  ecx = edx = 0;  // @175_5530a0
  p6_ = eax;  // @176_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @177_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p6_), (u32)(6932144), (u32)(6932792));  // @178_5530a0
  ecx = edx = 0;  // @179_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @180_5530a0
  if ((eax & eax) == 0) goto L55332d;  // @181_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @182_5530a0
  ecx = edx = 0;  // @183_5530a0
  goto L55332e;  // @184_5530a0
  L55332d:;
  __builtin_trap();  // @186_5530a0
  L55332e:;
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @188_5530a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @189_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @190_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @191_5530a0
  ecx = edx = 0;  // @192_5530a0
  ecx = eax;  // @193_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(-1));  // @194_5530a0
  ecx = edx = 0;  // @195_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @196_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(4));  // @197_5530a0
  ecx = edx = 0;  // @198_5530a0
  ecx = eax;  // @199_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @200_5530a0
  ecx = edx = 0;  // @201_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @202_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(5));  // @203_5530a0
  ecx = edx = 0;  // @204_5530a0
  ecx = eax;  // @205_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @206_5530a0
  ecx = edx = 0;  // @207_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @208_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(6));  // @209_5530a0
  ecx = edx = 0;  // @210_5530a0
  ecx = eax;  // @211_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @212_5530a0
  ecx = edx = 0;  // @213_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @214_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(7));  // @215_5530a0
  ecx = edx = 0;  // @216_5530a0
  edi = eax;  // @217_5530a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @218_5530a0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5533d1;  // @219_5530a0
  if ((eax & 0xff) == (u32)(2)) goto L5533d1;  // @220_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @221_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @222_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @223_5530a0
  ecx = edx = 0;  // @224_5530a0
  p7_ = eax;  // @225_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @226_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p7_), (u32)(6932144), (u32)(6932792));  // @227_5530a0
  ecx = edx = 0;  // @228_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @229_5530a0
  if ((eax & eax) == 0) goto L5533d0;  // @230_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @231_5530a0
  ecx = edx = 0;  // @232_5530a0
  goto L5533d1;  // @233_5530a0
  L5533d0:;
  __builtin_trap();  // @235_5530a0
  L5533d1:;
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @237_5530a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @238_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @239_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(8));  // @240_5530a0
  ecx = edx = 0;  // @241_5530a0
  edi = eax;  // @242_5530a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @243_5530a0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L553428;  // @244_5530a0
  if ((eax & 0xff) == (u32)(2)) goto L553428;  // @245_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @246_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @247_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @248_5530a0
  ecx = edx = 0;  // @249_5530a0
  p8_ = eax;  // @250_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @251_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p8_), (u32)(6932144), (u32)(6932792));  // @252_5530a0
  ecx = edx = 0;  // @253_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @254_5530a0
  if ((eax & eax) == 0) goto L553427;  // @255_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @256_5530a0
  ecx = edx = 0;  // @257_5530a0
  goto L553428;  // @258_5530a0
  L553427:;
  __builtin_trap();  // @260_5530a0
  L553428:;
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @262_5530a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @263_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @264_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(9));  // @265_5530a0
  ecx = edx = 0;  // @266_5530a0
  edi = eax;  // @267_5530a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @268_5530a0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L55347f;  // @269_5530a0
  if ((eax & 0xff) == (u32)(2)) goto L55347f;  // @270_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @271_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @272_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @273_5530a0
  ecx = edx = 0;  // @274_5530a0
  p9_ = eax;  // @275_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @276_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p9_), (u32)(6932144), (u32)(6932792));  // @277_5530a0
  ecx = edx = 0;  // @278_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @279_5530a0
  if ((eax & eax) == 0) goto L55347e;  // @280_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @281_5530a0
  ecx = edx = 0;  // @282_5530a0
  goto L55347f;  // @283_5530a0
  L55347e:;
  __builtin_trap();  // @285_5530a0
  L55347f:;
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @287_5530a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @288_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @289_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(10));  // @290_5530a0
  ecx = edx = 0;  // @291_5530a0
  ecx = eax;  // @292_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @293_5530a0
  ecx = edx = 0;  // @294_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @295_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(11));  // @296_5530a0
  ecx = edx = 0;  // @297_5530a0
  edi = eax;  // @298_5530a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @299_5530a0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5534e9;  // @300_5530a0
  if ((eax & 0xff) == (u32)(2)) goto L5534e9;  // @301_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @302_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @303_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @304_5530a0
  ecx = edx = 0;  // @305_5530a0
  p10_ = eax;  // @306_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @307_5530a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p10_), (u32)(6932144), (u32)(6932792));  // @308_5530a0
  ecx = edx = 0;  // @309_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @310_5530a0
  if ((eax & eax) == 0) goto L5534e8;  // @311_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @312_5530a0
  ecx = edx = 0;  // @313_5530a0
  goto L5534e9;  // @314_5530a0
  L5534e8:;
  __builtin_trap();  // @316_5530a0
  L5534e9:;
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @318_5530a0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @319_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @320_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11293), sizeof v); (u32)v; });  // @321_5530a0
  if ((ecx & ecx) == 0) goto L55367d;  // @322_5530a0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 24));  // @323_5530a0
  eax = (u32)(EBP - 16);  // @324_5530a0
  p11_ = ecx;  // @325_5530a0
  p12_ = eax;  // @326_5530a0
  p13_ = ebx;  // @327_5530a0
  eax = ext_5875c0_thiscall4(ecx, (u32)(p13_), (u32)(p12_), (u32)_mm_cvtsi128_si32(_mm_castps_si128(x0)));  // @328_5530a0
  ecx = edx = 0;  // @329_5530a0
  edi = eax;  // @330_5530a0
  if ((s32)(edi & edi) < 0) goto L55367d;  // @331_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @332_5530a0
  ebx = (u32)(edi + edi*8);  // @333_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 11293), sizeof v); (u32)v; });  // @334_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 95), sizeof v); (u32)v; });  // @335_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @336_5530a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @337_5530a0
  eax = (u32)(eax + ebx*8);  // @338_5530a0
  eax = (eax + (u32)(16));  // @339_5530a0
  p14_ = eax;  // @340_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @341_5530a0
  ecx = edx = 0;  // @342_5530a0
  ecx = eax;  // @343_5530a0
  eax = ext_602cd0_thiscall2(ecx, (u32)(p14_));  // @344_5530a0
  ecx = edx = 0;  // @345_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @346_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @347_5530a0
  eax = (eax + (u32)(20));  // @348_5530a0
  eax = (u32)(eax + ebx*8);  // @349_5530a0
  p15_ = eax;  // @350_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @351_5530a0
  ecx = edx = 0;  // @352_5530a0
  ecx = eax;  // @353_5530a0
  eax = ext_602cd0_thiscall2(ecx, (u32)(p15_));  // @354_5530a0
  ecx = edx = 0;  // @355_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @356_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @357_5530a0
  eax = (eax + (u32)(24));  // @358_5530a0
  eax = (u32)(eax + ebx*8);  // @359_5530a0
  p16_ = eax;  // @360_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @361_5530a0
  ecx = edx = 0;  // @362_5530a0
  ecx = eax;  // @363_5530a0
  eax = ext_602cd0_thiscall2(ecx, (u32)(p16_));  // @364_5530a0
  ecx = edx = 0;  // @365_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @366_5530a0
  p17_ = edi;  // @367_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @368_5530a0
  ecx = edx = 0;  // @369_5530a0
  ecx = eax;  // @370_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(p17_));  // @371_5530a0
  ecx = edx = 0;  // @372_5530a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @373_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*8 + 52), sizeof v); (u32)v; });  // @374_5530a0
  if (((eax & 0xff) & (u32)(1)) != 0) goto L5535c9;  // @375_5530a0
  if (((eax & 0xff) & (u32)(2)) == 0) goto L5535b0;  // @376_5530a0
  eax = (u32)(1);  // @377_5530a0
  goto L5535cb;  // @378_5530a0
  L5535b0:;
  if (((eax & 0xff) & (u32)(4)) == 0) goto L5535bb;  // @380_5530a0
  eax = (u32)(2);  // @381_5530a0
  goto L5535cb;  // @382_5530a0
  L5535bb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @384_5530a0
  if ((eax & eax) == 0) goto L5535c8;  // @385_5530a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @386_5530a0
  ecx = edx = 0;  // @387_5530a0
  goto L5535c9;  // @388_5530a0
  L5535c8:;
  __builtin_trap();  // @390_5530a0
  L5535c9:;
  eax = 0;  // @392_5530a0
  L5535cb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @394_5530a0
  p18_ = eax;  // @395_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(4));  // @396_5530a0
  ecx = edx = 0;  // @397_5530a0
  ecx = eax;  // @398_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(p18_));  // @399_5530a0
  ecx = edx = 0;  // @400_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*8 + 52), sizeof v); (u32)v; });  // @401_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @402_5530a0
  eax = (eax >> (u32)(3));  // @403_5530a0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @404_5530a0
  eax = (eax & 0xff);  // @405_5530a0
  p19_ = eax;  // @406_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(5));  // @407_5530a0
  ecx = edx = 0;  // @408_5530a0
  ecx = eax;  // @409_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(p19_));  // @410_5530a0
  ecx = edx = 0;  // @411_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*8 + 52), sizeof v); (u32)v; });  // @412_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @413_5530a0
  eax = (eax >> (u32)(4));  // @414_5530a0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @415_5530a0
  eax = (eax & 0xff);  // @416_5530a0
  p20_ = eax;  // @417_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(6));  // @418_5530a0
  ecx = edx = 0;  // @419_5530a0
  ecx = eax;  // @420_5530a0
  eax = ext_5002f0_thiscall2(ecx, (u32)(p20_));  // @421_5530a0
  ecx = edx = 0;  // @422_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @423_5530a0
  eax = (u32)(edi + 40);  // @424_5530a0
  eax = (u32)(eax + ebx*8);  // @425_5530a0
  p21_ = eax;  // @426_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(7));  // @427_5530a0
  ecx = edx = 0;  // @428_5530a0
  ecx = eax;  // @429_5530a0
  eax = ext_602cd0_thiscall2(ecx, (u32)(p21_));  // @430_5530a0
  ecx = edx = 0;  // @431_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @432_5530a0
  eax = (u32)(edi + 44);  // @433_5530a0
  eax = (u32)(eax + ebx*8);  // @434_5530a0
  p22_ = eax;  // @435_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(8));  // @436_5530a0
  ecx = edx = 0;  // @437_5530a0
  ecx = eax;  // @438_5530a0
  eax = ext_602cd0_thiscall2(ecx, (u32)(p22_));  // @439_5530a0
  ecx = edx = 0;  // @440_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @441_5530a0
  eax = (u32)(edi + 48);  // @442_5530a0
  eax = (u32)(eax + ebx*8);  // @443_5530a0
  p23_ = eax;  // @444_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(9));  // @445_5530a0
  ecx = edx = 0;  // @446_5530a0
  ecx = eax;  // @447_5530a0
  eax = ext_602cd0_thiscall2(ecx, (u32)(p23_));  // @448_5530a0
  ecx = edx = 0;  // @449_5530a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @450_5530a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @451_5530a0
  eax = ext_5003d0_thiscall2(ecx, (u32)(10));  // @452_5530a0
  ecx = edx = 0;  // @453_5530a0
  ecx = eax;  // @454_5530a0
  eax = ext_5002f0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11301), sizeof v); (u32)v; }));  // @455_5530a0
  ecx = edx = 0;  // @456_5530a0
  L55367d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @458_5530a0
  ecx = (ecx ^ EBP);  // @459_5530a0
  eax = ext_633654_thiscall1(ecx);  // @460_5530a0
  ecx = edx = 0;  // @461_5530a0
  __asm__ volatile("" :: "Yz"(x0));  // @462_5530a0
  return eax;  // @463_5530a0
}
PCREG(5530a0, lifted_5530a0);

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
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @9_555570
  ecx = edx = 0;  // @10_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @11_555570
  esi = eax;  // @12_555570
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @13_555570
  ecx = edx = 0;  // @14_555570
  ecx = eax;  // @15_555570
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @16_555570
  ecx = edx = 0;  // @17_555570
  if ((esi & esi) != 0) goto L5555fe;  // @18_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @19_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_555570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(732));  // @21_555570
  ecx = edx = 0;  // @22_555570
  p0_ = eax;  // @23_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_555570
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6969672));  // @25_555570
  ecx = edx = 0;  // @26_555570
  goto L555688;  // @27_555570
  L5555fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @29_555570
  ecx = esi;  // @30_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @31_555570
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097268));  // @32_555570
  ecx = edx = 0;  // @33_555570
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L555667;  // @34_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @35_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_555570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(736));  // @37_555570
  ecx = edx = 0;  // @38_555570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_555570
  edi = eax;  // @40_555570
  eax = (u32)(EBP - 144);  // @41_555570
  ecx = esi;  // @42_555570
  p1_ = eax;  // @43_555570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p1_), (u32)(1));  // @44_555570
  ecx = edx = 0;  // @45_555570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_555570
  ecx = eax;  // @47_555570
  reg.state = (s32)((u32)(0));  // @48_555570
  eax = ext_4cc1d0_thiscall1(ecx);  // @49_555570
  ecx = edx = 0;  // @50_555570
  p2_ = eax;  // @51_555570
  p3_ = edi;  // @52_555570
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p3_), (u32)(6969720), (u32)(p2_));  // @53_555570
  ecx = edx = 0;  // @54_555570
  ecx = (u32)(EBP - 144);  // @55_555570
  eax = ext_4cbec0_thiscall1(ecx);  // @56_555570
  ecx = edx = 0;  // @57_555570
  goto L555688;  // @58_555570
  L555667:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_555570
  ecx = esi;  // @61_555570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @62_555570
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @63_555570
  ecx = edx = 0;  // @64_555570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @65_555570
  eax = (eax & 0xff);  // @66_555570
  p4_ = eax;  // @67_555570
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @68_555570
  ecx = edx = 0;  // @69_555570
  ecx = eax;  // @70_555570
  eax = ext_5002f0_thiscall2(ecx, (u32)(p4_));  // @71_555570
  ecx = edx = 0;  // @72_555570
  L555688:;
  SEH_LEAVE();  // @74_555570
  ext_633654(G(u32, 0x6f5630));  // @75_555570
  return eax;  // @76_555570
}
PCREG(555570, lifted_555570);

extern "C" u32 STDCALL lifted_555d10(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_555d10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 148), &SENT_ESI, 4);  // @0_555d10
  __builtin_memcpy((void *)(u32)(EBP - 152), &SENT_EDI, 4);  // @1_555d10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_555d10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3_555d10
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @4_555d10
  ecx = edx = 0;  // @5_555d10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_555d10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @7_555d10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_555d10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @9_555d10
  ecx = edx = 0;  // @10_555d10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @11_555d10
  esi = eax;  // @12_555d10
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @13_555d10
  ecx = edx = 0;  // @14_555d10
  ecx = eax;  // @15_555d10
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @16_555d10
  ecx = edx = 0;  // @17_555d10
  if ((esi & esi) != 0) goto L555d9e;  // @18_555d10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @19_555d10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_555d10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(769));  // @21_555d10
  ecx = edx = 0;  // @22_555d10
  p0_ = eax;  // @23_555d10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_555d10
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6969956));  // @25_555d10
  ecx = edx = 0;  // @26_555d10
  goto L555e56;  // @27_555d10
  L555d9e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @29_555d10
  ecx = esi;  // @30_555d10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @31_555d10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2099193));  // @32_555d10
  ecx = edx = 0;  // @33_555d10
  ecx = esi;  // @34_555d10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_555d10
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L555dde;  // @36_555d10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1652)))(ecx);  // @37_555d10
  ecx = edx = 0;  // @38_555d10
  if ((eax & eax) == 0) goto L555dd6;  // @39_555d10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_555d10
  ecx = esi;  // @41_555d10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1648), sizeof v); (u32)v; });  // @42_555d10
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @43_555d10
  ecx = edx = 0;  // @44_555d10
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L555dd6;  // @45_555d10
  eax = 0;  // @46_555d10
  p1_ = eax;  // @47_555d10
  goto L555df1;  // @48_555d10
  L555dd6:;
  eax = (u32)(1);  // @50_555d10
  p2_ = eax;  // @51_555d10
  goto L555df1;  // @52_555d10
  L555dde:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @54_555d10
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))((u32)(2098152), (u32)(p2_), (u32)(p1_));  // @55_555d10
  ecx = edx = 0;  // @56_555d10
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L555e04;  // @57_555d10
  L555df1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @59_555d10
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @60_555d10
  ecx = edx = 0;  // @61_555d10
  ecx = eax;  // @62_555d10
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @63_555d10
  ecx = edx = 0;  // @64_555d10
  goto L555e56;  // @65_555d10
  L555e04:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @67_555d10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_555d10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(781));  // @69_555d10
  ecx = edx = 0;  // @70_555d10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @71_555d10
  edi = eax;  // @72_555d10
  eax = (u32)(EBP - 144);  // @73_555d10
  ecx = esi;  // @74_555d10
  p3_ = eax;  // @75_555d10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p3_), (u32)(1));  // @76_555d10
  ecx = edx = 0;  // @77_555d10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_555d10
  ecx = eax;  // @79_555d10
  reg.state = (s32)((u32)(0));  // @80_555d10
  eax = ext_4cc1d0_thiscall1(ecx);  // @81_555d10
  ecx = edx = 0;  // @82_555d10
  p4_ = eax;  // @83_555d10
  p5_ = edi;  // @84_555d10
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p5_), (u32)(6970008), (u32)(p4_));  // @85_555d10
  ecx = edx = 0;  // @86_555d10
  ecx = (u32)(EBP - 144);  // @87_555d10
  eax = ext_4cbec0_thiscall1(ecx);  // @88_555d10
  ecx = edx = 0;  // @89_555d10
  L555e56:;
  SEH_LEAVE();  // @91_555d10
  ext_633654(G(u32, 0x6f5630));  // @92_555d10
  return eax;  // @93_555d10
}
PCREG(555d10, lifted_555d10);

extern "C" u32 STDCALL lifted_5556b0(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_5556b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 148), &SENT_ESI, 4);  // @0_5556b0
  __builtin_memcpy((void *)(u32)(EBP - 152), &SENT_EDI, 4);  // @1_5556b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3_5556b0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @4_5556b0
  ecx = edx = 0;  // @5_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @7_5556b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5556b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @9_5556b0
  ecx = edx = 0;  // @10_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @11_5556b0
  esi = eax;  // @12_5556b0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @13_5556b0
  ecx = edx = 0;  // @14_5556b0
  ecx = eax;  // @15_5556b0
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @16_5556b0
  ecx = edx = 0;  // @17_5556b0
  if ((esi & esi) != 0) goto L55573e;  // @18_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @19_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5556b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(747));  // @21_5556b0
  ecx = edx = 0;  // @22_5556b0
  p0_ = eax;  // @23_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_5556b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6969796));  // @25_5556b0
  ecx = edx = 0;  // @26_5556b0
  goto L555812;  // @27_5556b0
  L55573e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @29_5556b0
  ecx = esi;  // @30_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @31_5556b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2099193));  // @32_5556b0
  ecx = edx = 0;  // @33_5556b0
  ecx = esi;  // @34_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_5556b0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L55578c;  // @36_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @37_5556b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @38_5556b0
  ecx = edx = 0;  // @39_5556b0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L555785;  // @40_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_5556b0
  ecx = esi;  // @42_5556b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1652)))(ecx);  // @43_5556b0
  ecx = edx = 0;  // @44_5556b0
  if ((eax & eax) == 0) goto L555785;  // @45_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_5556b0
  ecx = esi;  // @47_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1648), sizeof v); (u32)v; });  // @48_5556b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @49_5556b0
  ecx = edx = 0;  // @50_5556b0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L555785;  // @51_5556b0
  eax = 0;  // @52_5556b0
  goto L5557ac;  // @53_5556b0
  L555785:;
  eax = (u32)(1);  // @55_5556b0
  goto L5557ac;  // @56_5556b0
  L55578c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @58_5556b0
  eax = ((u32(STDCALL *)(u32))(eax))((u32)(2098152));  // @59_5556b0
  ecx = edx = 0;  // @60_5556b0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5557c0;  // @61_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_5556b0
  ecx = esi;  // @63_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @64_5556b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @65_5556b0
  ecx = edx = 0;  // @66_5556b0
  eax = (eax & 0xff);  // @67_5556b0
  L5557ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @69_5556b0
  p1_ = eax;  // @70_5556b0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @71_5556b0
  ecx = edx = 0;  // @72_5556b0
  ecx = eax;  // @73_5556b0
  eax = ext_5002f0_thiscall2(ecx, (u32)(p1_));  // @74_5556b0
  ecx = edx = 0;  // @75_5556b0
  goto L555812;  // @76_5556b0
  L5557c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @78_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_5556b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(760));  // @80_5556b0
  ecx = edx = 0;  // @81_5556b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_5556b0
  edi = eax;  // @83_5556b0
  eax = (u32)(EBP - 144);  // @84_5556b0
  ecx = esi;  // @85_5556b0
  p2_ = eax;  // @86_5556b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p2_), (u32)(1));  // @87_5556b0
  ecx = edx = 0;  // @88_5556b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @89_5556b0
  ecx = eax;  // @90_5556b0
  reg.state = (s32)((u32)(0));  // @91_5556b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @92_5556b0
  ecx = edx = 0;  // @93_5556b0
  p3_ = eax;  // @94_5556b0
  p4_ = edi;  // @95_5556b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p4_), (u32)(6969856), (u32)(p3_));  // @96_5556b0
  ecx = edx = 0;  // @97_5556b0
  ecx = (u32)(EBP - 144);  // @98_5556b0
  eax = ext_4cbec0_thiscall1(ecx);  // @99_5556b0
  ecx = edx = 0;  // @100_5556b0
  L555812:;
  SEH_LEAVE();  // @102_5556b0
  ext_633654(G(u32, 0x6f5630));  // @103_5556b0
  return eax;  // @104_5556b0
}
PCREG(5556b0, lifted_5556b0);

extern "C" u32 THISCALL lifted_43c210(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665d9e);  // @h_43c210
  u8 F[0x450] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x350);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_, p35_, p36_, p37_, p38_, p39_, p40_, p41_, p42_, p43_, p44_, p45_, p46_, p47_, p48_, p49_, p50_, p51_, p52_, p53_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x350 + 8, &a0, 4);
  __builtin_memcpy(F + 0x350 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 284), &SENT_EBX, 4);  // @0_43c210
  __builtin_memcpy((void *)(u32)(EBP - 288), &SENT_ESI, 4);  // @1_43c210
  __builtin_memcpy((void *)(u32)(EBP - 292), &SENT_EDI, 4);  // @2_43c210
  ebx = ecx;  // @3_43c210
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @4_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @5_43c210
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_43c210
  if (eax > (u32)(12)) goto L43ceaa;  // @7_43c210
  switch (eax) { case 0: goto L43c25c; case 1: goto L43c359; case 2: goto L43c90c; case 3: goto L43ccee; case 4: goto L43ceaa; case 5: goto L43ceaa; case 6: goto L43ce92; case 7: goto L43cea0; case 8: goto L43cea0; case 9: goto L43ceaa; case 10: goto L43ceaa; case 11: goto L43cdeb; case 12: goto L43ce99; default: __builtin_trap(); }  // @8_43c210
  L43c25c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_43c210
  edx = (u32)(6791420);  // @11_43c210
  eax = ecx;  // @12_43c210
  L43c266:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @14_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @15_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @16_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) goto L43c2a8;  // @17_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) == (u32)(0)) goto L43c2a4;  // @18_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @19_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @20_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @21_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) goto L43c2a8;  // @22_43c210
  eax = (eax + (u32)(2));  // @23_43c210
  edx = (edx + (u32)(2));  // @24_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) != (u32)(0)) goto L43c266;  // @25_43c210
  L43c2a4:;
  eax = 0;  // @27_43c210
  goto L43c2ad;  // @28_43c210
  L43c2a8:;
  eax = 0;  // @30_43c210
  eax = (eax | (u32)(1));  // @31_43c210
  L43c2ad:;
  if ((eax & eax) == 0) goto L43c8f6;  // @33_43c210
  edx = (u32)(6798800);  // @34_43c210
  eax = ecx;  // @35_43c210
  L43c2c0:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @37_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @38_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @39_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) goto L43c302;  // @40_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) == (u32)(0)) goto L43c2fe;  // @41_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @42_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @43_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @44_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) goto L43c302;  // @45_43c210
  eax = (eax + (u32)(2));  // @46_43c210
  edx = (edx + (u32)(2));  // @47_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) != (u32)(0)) goto L43c2c0;  // @48_43c210
  L43c2fe:;
  eax = 0;  // @50_43c210
  goto L43c307;  // @51_43c210
  L43c302:;
  eax = 0;  // @53_43c210
  eax = (eax | (u32)(1));  // @54_43c210
  L43c307:;
  if ((eax & eax) != 0) goto L43c317;  // @56_43c210
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @57_43c210
  goto L43ceaa;  // @58_43c210
  L43c317:;
  eax = (u32)(6791400);  // @60_43c210
  L43c320:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @62_43c210
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L43c340;  // @63_43c210
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L43c33c;  // @64_43c210
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @65_43c210
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L43c340;  // @66_43c210
  ecx = (ecx + (u32)(2));  // @67_43c210
  eax = (eax + (u32)(2));  // @68_43c210
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L43c320;  // @69_43c210
  L43c33c:;
  eax = 0;  // @71_43c210
  goto L43c345;  // @72_43c210
  L43c340:;
  eax = 0;  // @74_43c210
  eax = (eax | (u32)(1));  // @75_43c210
  L43c345:;
  if ((eax & eax) == 0) goto L43ceaa;  // @77_43c210
  ecx = ebx;  // @78_43c210
  goto L43cea5;  // @79_43c210
  L43c359:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @81_43c210
  ecx = (u32)(6791432);  // @82_43c210
  eax = edx;  // @83_43c210
  L43c363:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @85_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @86_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @87_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43c3a5;  // @88_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) == (u32)(0)) goto L43c3a1;  // @89_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @90_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @91_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @92_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43c3a5;  // @93_43c210
  eax = (eax + (u32)(2));  // @94_43c210
  ecx = (ecx + (u32)(2));  // @95_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) != (u32)(0)) goto L43c363;  // @96_43c210
  L43c3a1:;
  eax = 0;  // @98_43c210
  goto L43c3aa;  // @99_43c210
  L43c3a5:;
  eax = 0;  // @101_43c210
  eax = (eax | (u32)(1));  // @102_43c210
  L43c3aa:;
  if ((eax & eax) != 0) goto L43c48b;  // @104_43c210
  p0_ = esi;  // @105_43c210
  ecx = ebx;  // @106_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 144), &v, sizeof v); }  // @107_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @108_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 148), &v, sizeof v); }  // @109_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 164), &v, sizeof v); }  // @110_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @111_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 168), &v, sizeof v); }  // @112_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @113_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 172), &v, sizeof v); }  // @114_43c210
  eax = ext_61bac0_stdcall2((u32)(p0_), (u32)(6791440));  // @115_43c210
  ecx = edx = 0;  // @116_43c210
  p1_ = eax;  // @117_43c210
  ecx = (u32)(EBP - 144);  // @118_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @119_43c210
  ecx = edx = 0;  // @120_43c210
  eax = (u32)(EBP - 144);  // @121_43c210
  reg.state = (s32)((u32)(0));  // @122_43c210
  p2_ = eax;  // @123_43c210
  ecx = (u32)(ebx + 16);  // @124_43c210
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @125_43c210
  ecx = edx = 0;  // @126_43c210
  ecx = (u32)(EBP - 144);  // @127_43c210
  reg.state = (s32)((u32)(4294967295));  // @128_43c210
  eax = ext_4cbec0_cdecl1((u32)(6798808));  // @129_43c210
  ecx = edx = 0;  // @130_43c210
  p3_ = esi;  // @131_43c210
  ecx = ebx;  // @132_43c210
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 181), &v, sizeof v); }  // @133_43c210
  eax = ext_61bac0_stdcall2((u32)(p3_), (u32)(6791460));  // @134_43c210
  ecx = edx = 0;  // @135_43c210
  if ((eax & eax) == 0) goto L43c478;  // @136_43c210
  p4_ = eax;  // @137_43c210
  ecx = ebx;  // @138_43c210
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 176), &v, sizeof v); }  // @139_43c210
  eax = ext_43b820_thiscall2(ecx, (u32)(p4_));  // @140_43c210
  ecx = edx = 0;  // @141_43c210
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @142_43c210
  goto L43ceaa;  // @143_43c210
  L43c478:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 176), &v, sizeof v); }  // @145_43c210
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @146_43c210
  goto L43ceaa;  // @147_43c210
  L43c48b:;
  ecx = (u32)(6798828);  // @149_43c210
  eax = edx;  // @150_43c210
  L43c492:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @152_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @153_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @154_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43c4d4;  // @155_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) == (u32)(0)) goto L43c4d0;  // @156_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @157_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @158_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @159_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43c4d4;  // @160_43c210
  eax = (eax + (u32)(2));  // @161_43c210
  ecx = (ecx + (u32)(2));  // @162_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) != (u32)(0)) goto L43c492;  // @163_43c210
  L43c4d0:;
  eax = 0;  // @165_43c210
  goto L43c4d9;  // @166_43c210
  L43c4d4:;
  eax = 0;  // @168_43c210
  eax = (eax | (u32)(1));  // @169_43c210
  L43c4d9:;
  if ((eax & eax) != 0) goto L43c59e;  // @171_43c210
  p5_ = esi;  // @172_43c210
  ecx = ebx;  // @173_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 144), &v, sizeof v); }  // @174_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @175_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 148), &v, sizeof v); }  // @176_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 164), &v, sizeof v); }  // @177_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @178_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 168), &v, sizeof v); }  // @179_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @180_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 172), &v, sizeof v); }  // @181_43c210
  eax = ext_61bac0_stdcall2((u32)(p5_), (u32)(6798836));  // @182_43c210
  ecx = edx = 0;  // @183_43c210
  p6_ = eax;  // @184_43c210
  ecx = (u32)(EBP - 144);  // @185_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p6_));  // @186_43c210
  ecx = edx = 0;  // @187_43c210
  eax = (u32)(EBP - 144);  // @188_43c210
  reg.state = (s32)((u32)(1));  // @189_43c210
  p7_ = eax;  // @190_43c210
  ecx = (u32)(ebx + 16);  // @191_43c210
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p7_));  // @192_43c210
  ecx = edx = 0;  // @193_43c210
  ecx = (u32)(EBP - 144);  // @194_43c210
  reg.state = (s32)((u32)(4294967295));  // @195_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @196_43c210
  ecx = edx = 0;  // @197_43c210
  ecx = (u32)(EBP - 144);  // @198_43c210
  { u16 v = (u16)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 181), &v, sizeof v); }  // @199_43c210
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @200_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @201_43c210
  ecx = edx = 0;  // @202_43c210
  reg.state = (s32)((u32)(2));  // @203_43c210
  goto L43c6ac;  // @204_43c210
  L43c59e:;
  ecx = (u32)(6798844);  // @206_43c210
  eax = edx;  // @207_43c210
  L43c5a5:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @209_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @210_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @211_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43c5e7;  // @212_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) == (u32)(0)) goto L43c5e3;  // @213_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @214_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @215_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @216_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43c5e7;  // @217_43c210
  eax = (eax + (u32)(2));  // @218_43c210
  ecx = (ecx + (u32)(2));  // @219_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) != (u32)(0)) goto L43c5a5;  // @220_43c210
  L43c5e3:;
  eax = 0;  // @222_43c210
  goto L43c5ec;  // @223_43c210
  L43c5e7:;
  eax = 0;  // @225_43c210
  eax = (eax | (u32)(1));  // @226_43c210
  L43c5ec:;
  if ((eax & eax) != 0) goto L43c6ce;  // @228_43c210
  p8_ = esi;  // @229_43c210
  ecx = ebx;  // @230_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 144), &v, sizeof v); }  // @231_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @232_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 148), &v, sizeof v); }  // @233_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 164), &v, sizeof v); }  // @234_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @235_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 168), &v, sizeof v); }  // @236_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @237_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 172), &v, sizeof v); }  // @238_43c210
  eax = ext_61bac0_stdcall2((u32)(p8_), (u32)(6798836));  // @239_43c210
  ecx = edx = 0;  // @240_43c210
  p9_ = eax;  // @241_43c210
  ecx = (u32)(EBP - 144);  // @242_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p9_));  // @243_43c210
  ecx = edx = 0;  // @244_43c210
  eax = (u32)(EBP - 144);  // @245_43c210
  reg.state = (s32)((u32)(3));  // @246_43c210
  p10_ = eax;  // @247_43c210
  ecx = (u32)(ebx + 16);  // @248_43c210
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p10_));  // @249_43c210
  ecx = edx = 0;  // @250_43c210
  ecx = (u32)(EBP - 144);  // @251_43c210
  reg.state = (s32)((u32)(4294967295));  // @252_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @253_43c210
  ecx = edx = 0;  // @254_43c210
  ecx = (u32)(EBP - 144);  // @255_43c210
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx + 181), &v, sizeof v); }  // @256_43c210
  { u32 v = (u32)((u32)(11)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @257_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @258_43c210
  ecx = edx = 0;  // @259_43c210
  reg.state = (s32)((u32)(4));  // @260_43c210
  L43c6ac:;
  eax = (u32)(EBP - 144);  // @262_43c210
  p11_ = eax;  // @263_43c210
  ecx = (u32)(ebx + 451);  // @264_43c210
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p11_));  // @265_43c210
  ecx = edx = 0;  // @266_43c210
  ecx = (u32)(EBP - 144);  // @267_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @268_43c210
  ecx = edx = 0;  // @269_43c210
  goto L43ceaa;  // @270_43c210
  L43c6ce:;
  ecx = (u32)(6791488);  // @272_43c210
  eax = edx;  // @273_43c210
  L43c6d5:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @275_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @276_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @277_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43c717;  // @278_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) == (u32)(0)) goto L43c713;  // @279_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @280_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @281_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @282_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43c717;  // @283_43c210
  eax = (eax + (u32)(2));  // @284_43c210
  ecx = (ecx + (u32)(2));  // @285_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; }) != (u32)(0)) goto L43c6d5;  // @286_43c210
  L43c713:;
  eax = 0;  // @288_43c210
  goto L43c71c;  // @289_43c210
  L43c717:;
  eax = 0;  // @291_43c210
  eax = (eax | (u32)(1));  // @292_43c210
  L43c71c:;
  if ((eax & eax) != 0) goto L43c82f;  // @294_43c210
  p12_ = esi;  // @295_43c210
  ecx = ebx;  // @296_43c210
  eax = ext_61bac0_stdcall2((u32)(p12_), (u32)(6798836));  // @297_43c210
  ecx = edx = 0;  // @298_43c210
  p13_ = esi;  // @299_43c210
  ecx = ebx;  // @300_43c210
  edi = eax;  // @301_43c210
  eax = ext_61bac0_stdcall2((u32)(p13_), (u32)(6798856));  // @302_43c210
  ecx = edx = 0;  // @303_43c210
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @304_43c210
  p14_ = eax;  // @305_43c210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @306_43c210
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @307_43c210
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @308_43c210
  eax = ((u32( *)(u32, u32))(esi))((u32)(p14_), (u32)(6793420));  // @309_43c210
  ecx = edx = 0;  // @310_43c210
  if ((eax & eax) != 0) goto L43c779;  // @311_43c210
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 273), &v, sizeof v); }  // @312_43c210
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @313_43c210
  goto L43c7a0;  // @314_43c210
  L43c779:;
  eax = ((u32(STDCALL *)(u32, u32))(esi))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }), (u32)(6793428));  // @316_43c210
  ecx = edx = 0;  // @317_43c210
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; });  // @318_43c210
  edx = (u32)(1);  // @319_43c210
  if ((eax & eax) == 0) ecx = edx;  // @320_43c210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @321_43c210
  L43c7a0:;
  p15_ = edi;  // @323_43c210
  eax = ((u32( *)(u32, u32))(esi))((u32)(p15_), (u32)(6798864));  // @324_43c210
  ecx = edx = 0;  // @325_43c210
  if ((eax & eax) != 0) goto L43c7c5;  // @326_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }) == (eax & 0xff)) goto L43c7c5;  // @327_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @328_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; })) & 0xff);  // @329_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 108), &v, sizeof v); }  // @330_43c210
  L43c7c5:;
  p16_ = edi;  // @332_43c210
  eax = ((u32( *)(u32, u32))(esi))((u32)(p16_), (u32)(6791600));  // @333_43c210
  ecx = edx = 0;  // @334_43c210
  if ((eax & eax) != 0) goto L43c7ea;  // @335_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }) == (eax & 0xff)) goto L43c7ea;  // @336_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @337_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; })) & 0xff);  // @338_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 109), &v, sizeof v); }  // @339_43c210
  L43c7ea:;
  p17_ = edi;  // @341_43c210
  eax = ((u32( *)(u32, u32))(esi))((u32)(p17_), (u32)(6791588));  // @342_43c210
  ecx = edx = 0;  // @343_43c210
  if ((eax & eax) != 0) goto L43c80f;  // @344_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }) == (eax & 0xff)) goto L43c823;  // @345_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @346_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 273), sizeof v); (u32)v; })) & 0xff);  // @347_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 110), &v, sizeof v); }  // @348_43c210
  L43c80f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }) == (u32)(0)) goto L43c823;  // @350_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340960), sizeof v); (u32)v; });  // @351_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @352_43c210
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @353_43c210
  ecx = edx = 0;  // @354_43c210
  L43c823:;
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @356_43c210
  goto L43ceaa;  // @357_43c210
  L43c82f:;
  eax = (u32)(6798876);  // @359_43c210
  L43c834:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @361_43c210
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L43c854;  // @362_43c210
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L43c850;  // @363_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @364_43c210
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L43c854;  // @365_43c210
  edx = (edx + (u32)(2));  // @366_43c210
  eax = (eax + (u32)(2));  // @367_43c210
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L43c834;  // @368_43c210
  L43c850:;
  eax = 0;  // @370_43c210
  goto L43c859;  // @371_43c210
  L43c854:;
  eax = 0;  // @373_43c210
  eax = (eax | (u32)(1));  // @374_43c210
  L43c859:;
  ecx = ebx;  // @376_43c210
  if ((eax & eax) != 0) goto L43c902;  // @377_43c210
  p18_ = esi;  // @378_43c210
  eax = ext_61bac0_stdcall2((u32)(p18_), (u32)(6798836));  // @379_43c210
  ecx = edx = 0;  // @380_43c210
  if ((eax & eax) == 0) goto L43c887;  // @381_43c210
  p19_ = eax;  // @382_43c210
  ecx = (u32)(EBP - 144);  // @383_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p19_));  // @384_43c210
  ecx = edx = 0;  // @385_43c210
  reg.state = (s32)((u32)(5));  // @386_43c210
  goto L43c8c3;  // @387_43c210
  L43c887:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @389_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @390_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(231));  // @391_43c210
  ecx = edx = 0;  // @392_43c210
  p20_ = eax;  // @393_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @394_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p20_), (u32)(6798888), (u32)(0));  // @395_43c210
  ecx = edx = 0;  // @396_43c210
  ecx = (u32)(EBP - 144);  // @397_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @398_43c210
  ecx = edx = 0;  // @399_43c210
  reg.state = (s32)((u32)(6));  // @400_43c210
  L43c8c3:;
  eax = (u32)(EBP - 144);  // @402_43c210
  esi = (u32)(ebx + 195);  // @403_43c210
  p21_ = eax;  // @404_43c210
  ecx = esi;  // @405_43c210
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p21_));  // @406_43c210
  ecx = edx = 0;  // @407_43c210
  ecx = (u32)(EBP - 144);  // @408_43c210
  reg.state = (s32)((u32)(4294967295));  // @409_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @410_43c210
  ecx = edx = 0;  // @411_43c210
  ecx = esi;  // @412_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @413_43c210
  ecx = edx = 0;  // @414_43c210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 191), &v, sizeof v); }  // @415_43c210
  L43c8f6:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @417_43c210
  goto L43ceaa;  // @418_43c210
  L43c902:;
  goto L43cea5;  // @420_43c210
  L43c90c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @422_43c210
  ecx = (u32)(6799020);  // @423_43c210
  eax = edx;  // @424_43c210
  L43c916:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @426_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @427_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @428_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43c958;  // @429_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }) == (u32)(0)) goto L43c954;  // @430_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @431_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @432_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @433_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43c958;  // @434_43c210
  eax = (eax + (u32)(2));  // @435_43c210
  ecx = (ecx + (u32)(2));  // @436_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }) != (u32)(0)) goto L43c916;  // @437_43c210
  L43c954:;
  eax = 0;  // @439_43c210
  goto L43c95d;  // @440_43c210
  L43c958:;
  eax = 0;  // @442_43c210
  eax = (eax | (u32)(1));  // @443_43c210
  L43c95d:;
  if ((eax & eax) != 0) goto L43ca34;  // @445_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; });  // @446_43c210
  ecx = ebx;  // @447_43c210
  p22_ = esi;  // @448_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 144), &v, sizeof v); }  // @449_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; });  // @450_43c210
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 160), &v, sizeof v); }  // @451_43c210
  eax = ext_61bac0_stdcall2((u32)(p22_), (u32)(6791480));  // @452_43c210
  ecx = edx = 0;  // @453_43c210
  esi = eax;  // @454_43c210
  if ((esi & esi) == 0) goto L43ccd8;  // @455_43c210
  p23_ = esi;  // @456_43c210
  ecx = ebx;  // @457_43c210
  eax = ext_4321c0_thiscall2(ecx, (u32)(p23_));  // @458_43c210
  ecx = edx = 0;  // @459_43c210
  ecx = eax;  // @460_43c210
  if (ecx != (u32)(-1)) goto L43c9d6;  // @461_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @462_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @463_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(266), (u32)(6798976));  // @464_43c210
  ecx = edx = 0;  // @465_43c210
  p24_ = esi;  // @466_43c210
  p25_ = eax;  // @467_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @468_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p25_), (u32)(6799024), (u32)(p24_));  // @469_43c210
  ecx = edx = 0;  // @470_43c210
  goto L43ceaa;  // @471_43c210
  L43c9d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; });  // @473_43c210
  if ((s32)eax >= (s32)(u32)(4)) goto L43c9fa;  // @474_43c210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 144), &v, sizeof v); }  // @475_43c210
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 579), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 579), &v, sizeof v); }  // @476_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @477_43c210
  goto L43ceaa;  // @478_43c210
  L43c9fa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @480_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @481_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(277));  // @482_43c210
  ecx = edx = 0;  // @483_43c210
  esi = eax;  // @484_43c210
  ecx = (u32)(ebx + 16);  // @485_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @486_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @487_43c210
  ecx = edx = 0;  // @488_43c210
  p26_ = eax;  // @489_43c210
  p27_ = esi;  // @490_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p27_), (u32)(6799084), (u32)(p26_));  // @491_43c210
  ecx = edx = 0;  // @492_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @493_43c210
  goto L43ceaa;  // @494_43c210
  L43ca34:;
  ecx = (u32)(6799128);  // @496_43c210
  eax = edx;  // @497_43c210
  L43ca40:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @499_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @500_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @501_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43ca82;  // @502_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }) == (u32)(0)) goto L43ca7e;  // @503_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @504_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @505_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @506_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43ca82;  // @507_43c210
  eax = (eax + (u32)(2));  // @508_43c210
  ecx = (ecx + (u32)(2));  // @509_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }) != (u32)(0)) goto L43ca40;  // @510_43c210
  L43ca7e:;
  eax = 0;  // @512_43c210
  goto L43ca87;  // @513_43c210
  L43ca82:;
  eax = 0;  // @515_43c210
  eax = (eax | (u32)(1));  // @516_43c210
  L43ca87:;
  if ((eax & eax) != 0) goto L43cb46;  // @518_43c210
  p28_ = esi;  // @519_43c210
  ecx = ebx;  // @520_43c210
  eax = ext_61bac0_stdcall2((u32)(p28_), (u32)(6791480));  // @521_43c210
  ecx = edx = 0;  // @522_43c210
  esi = eax;  // @523_43c210
  if ((esi & esi) == 0) goto L43ccd8;  // @524_43c210
  p29_ = esi;  // @525_43c210
  ecx = ebx;  // @526_43c210
  eax = ext_4321c0_thiscall2(ecx, (u32)(p29_));  // @527_43c210
  ecx = edx = 0;  // @528_43c210
  ecx = eax;  // @529_43c210
  if (ecx != (u32)(-1)) goto L43cae8;  // @530_43c210
  p30_ = esi;  // @531_43c210
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6762d8))((u32)(p30_));  // @532_43c210
  ecx = edx = 0;  // @533_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @534_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @535_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(296));  // @536_43c210
  ecx = edx = 0;  // @537_43c210
  p31_ = esi;  // @538_43c210
  p32_ = eax;  // @539_43c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @540_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p32_), (u32)(6799024), (u32)(p31_));  // @541_43c210
  ecx = edx = 0;  // @542_43c210
  goto L43ceaa;  // @543_43c210
  L43cae8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 583), sizeof v); (u32)v; });  // @545_43c210
  if ((s32)eax >= (s32)(u32)(4)) goto L43cb0c;  // @546_43c210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + eax*4 + 160), &v, sizeof v); }  // @547_43c210
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 583), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 583), &v, sizeof v); }  // @548_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @549_43c210
  goto L43ceaa;  // @550_43c210
  L43cb0c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @552_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @553_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(307));  // @554_43c210
  ecx = edx = 0;  // @555_43c210
  esi = eax;  // @556_43c210
  ecx = (u32)(ebx + 16);  // @557_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @558_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @559_43c210
  ecx = edx = 0;  // @560_43c210
  p33_ = eax;  // @561_43c210
  p34_ = esi;  // @562_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p34_), (u32)(6799084), (u32)(p33_));  // @563_43c210
  ecx = edx = 0;  // @564_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @565_43c210
  goto L43ceaa;  // @566_43c210
  L43cb46:;
  ecx = (u32)(6791440);  // @568_43c210
  eax = edx;  // @569_43c210
  L43cb50:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @571_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @572_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @573_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43cb92;  // @574_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }) == (u32)(0)) goto L43cb8e;  // @575_43c210
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @576_43c210
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 274), &v, sizeof v); }  // @577_43c210
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @578_43c210
  if ((ebx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43cb92;  // @579_43c210
  eax = (eax + (u32)(2));  // @580_43c210
  ecx = (ecx + (u32)(2));  // @581_43c210
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 274), sizeof v); (u32)v; }) != (u32)(0)) goto L43cb50;  // @582_43c210
  L43cb8e:;
  eax = 0;  // @584_43c210
  goto L43cb97;  // @585_43c210
  L43cb92:;
  eax = 0;  // @587_43c210
  eax = (eax | (u32)(1));  // @588_43c210
  L43cb97:;
  if ((eax & eax) != 0) goto L43cc26;  // @590_43c210
  p35_ = esi;  // @591_43c210
  ecx = ebx;  // @592_43c210
  eax = ext_61bac0_stdcall2((u32)(p35_), (u32)(6791500));  // @593_43c210
  ecx = edx = 0;  // @594_43c210
  esi = eax;  // @595_43c210
  if ((esi & esi) == 0) goto L43cbec;  // @596_43c210
  ecx = esi;  // @597_43c210
  edx = (u32)(ecx + 1);  // @598_43c210
  L43cbb7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @600_43c210
  ecx = (ecx + 1);  // @601_43c210
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L43cbb7;  // @602_43c210
  ecx = (ecx - edx);  // @603_43c210
  eax = (u32)(ecx + 1);  // @604_43c210
  p36_ = eax;  // @605_43c210
  eax = ext_41e290_cdecl1((u32)(p36_));  // @606_43c210
  ecx = edx = 0;  // @607_43c210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 183), &v, sizeof v); }  // @608_43c210
  L43cbd2:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @610_43c210
  esi = (u32)(esi + 1);  // @611_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @612_43c210
  eax = (u32)(eax + 1);  // @613_43c210
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L43cbd2;  // @614_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @615_43c210
  goto L43ceaa;  // @616_43c210
  L43cbec:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @618_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @619_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(326));  // @620_43c210
  ecx = edx = 0;  // @621_43c210
  esi = eax;  // @622_43c210
  ecx = (u32)(ebx + 16);  // @623_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @624_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @625_43c210
  ecx = edx = 0;  // @626_43c210
  p37_ = eax;  // @627_43c210
  p38_ = esi;  // @628_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p38_), (u32)(6799136), (u32)(p37_));  // @629_43c210
  ecx = edx = 0;  // @630_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @631_43c210
  goto L43ceaa;  // @632_43c210
  L43cc26:;
  eax = (u32)(6791508);  // @634_43c210
  L43cc30:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @636_43c210
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L43cc50;  // @637_43c210
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L43cc4c;  // @638_43c210
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @639_43c210
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L43cc50;  // @640_43c210
  edx = (edx + (u32)(2));  // @641_43c210
  eax = (eax + (u32)(2));  // @642_43c210
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L43cc30;  // @643_43c210
  L43cc4c:;
  eax = 0;  // @645_43c210
  goto L43cc55;  // @646_43c210
  L43cc50:;
  eax = 0;  // @648_43c210
  eax = (eax | (u32)(1));  // @649_43c210
  L43cc55:;
  ecx = ebx;  // @651_43c210
  if ((eax & eax) != 0) goto L43cce4;  // @652_43c210
  p39_ = esi;  // @653_43c210
  eax = ext_61bac0_stdcall2((u32)(p39_), (u32)(6791500));  // @654_43c210
  ecx = edx = 0;  // @655_43c210
  esi = eax;  // @656_43c210
  if ((esi & esi) == 0) goto L43ccaa;  // @657_43c210
  ecx = esi;  // @658_43c210
  edx = (u32)(ecx + 1);  // @659_43c210
  L43cc75:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @661_43c210
  ecx = (ecx + 1);  // @662_43c210
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L43cc75;  // @663_43c210
  ecx = (ecx - edx);  // @664_43c210
  eax = (u32)(ecx + 1);  // @665_43c210
  p40_ = eax;  // @666_43c210
  eax = ext_41e290_cdecl1((u32)(p40_));  // @667_43c210
  ecx = edx = 0;  // @668_43c210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 187), &v, sizeof v); }  // @669_43c210
  L43cc90:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @671_43c210
  esi = (u32)(esi + 1);  // @672_43c210
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @673_43c210
  eax = (u32)(eax + 1);  // @674_43c210
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L43cc90;  // @675_43c210
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @676_43c210
  goto L43ceaa;  // @677_43c210
  L43ccaa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @679_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @680_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(343));  // @681_43c210
  ecx = edx = 0;  // @682_43c210
  esi = eax;  // @683_43c210
  ecx = (u32)(ebx + 16);  // @684_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @685_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @686_43c210
  ecx = edx = 0;  // @687_43c210
  p41_ = eax;  // @688_43c210
  p42_ = esi;  // @689_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p42_), (u32)(6799136), (u32)(p41_));  // @690_43c210
  ecx = edx = 0;  // @691_43c210
  L43ccd8:;
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @693_43c210
  goto L43ceaa;  // @694_43c210
  L43cce4:;
  goto L43cea5;  // @696_43c210
  L43ccee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @698_43c210
  ecx = (u32)(6791440);  // @699_43c210
  L43ccf6:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @701_43c210
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43cd16;  // @702_43c210
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L43cd12;  // @703_43c210
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @704_43c210
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43cd16;  // @705_43c210
  eax = (eax + (u32)(2));  // @706_43c210
  ecx = (ecx + (u32)(2));  // @707_43c210
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L43ccf6;  // @708_43c210
  L43cd12:;
  eax = 0;  // @710_43c210
  goto L43cd1b;  // @711_43c210
  L43cd16:;
  eax = 0;  // @713_43c210
  eax = (eax | (u32)(1));  // @714_43c210
  L43cd1b:;
  if ((eax & eax) != 0) goto L43cdb8;  // @716_43c210
  p43_ = esi;  // @717_43c210
  ecx = ebx;  // @718_43c210
  eax = ext_61bac0_stdcall2((u32)(p43_), (u32)(6798836));  // @719_43c210
  ecx = edx = 0;  // @720_43c210
  ecx = (u32)(ebx + 451);  // @721_43c210
  edi = eax;  // @722_43c210
  eax = ext_4cc5f0_cdecl1((u32)(6799176));  // @723_43c210
  ecx = edx = 0;  // @724_43c210
  if ((eax & eax) == 0) goto L43cd7c;  // @725_43c210
  ecx = (u32)(EBP - 144);  // @726_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6799224));  // @727_43c210
  ecx = edx = 0;  // @728_43c210
  eax = (u32)(EBP - 144);  // @729_43c210
  reg.state = (s32)((u32)(7));  // @730_43c210
  p44_ = eax;  // @731_43c210
  ecx = (u32)(ebx + 451);  // @732_43c210
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p44_));  // @733_43c210
  ecx = edx = 0;  // @734_43c210
  ecx = (u32)(EBP - 144);  // @735_43c210
  reg.state = (s32)((u32)(4294967295));  // @736_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @737_43c210
  ecx = edx = 0;  // @738_43c210
  L43cd7c:;
  p45_ = edi;  // @740_43c210
  ecx = (u32)(EBP - 144);  // @741_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p45_));  // @742_43c210
  ecx = edx = 0;  // @743_43c210
  eax = (u32)(EBP - 144);  // @744_43c210
  reg.state = (s32)((u32)(8));  // @745_43c210
  p46_ = eax;  // @746_43c210
  ecx = (u32)(ebx + 451);  // @747_43c210
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p46_));  // @748_43c210
  ecx = edx = 0;  // @749_43c210
  ecx = (u32)(EBP - 144);  // @750_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @751_43c210
  ecx = edx = 0;  // @752_43c210
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @753_43c210
  goto L43ceaa;  // @754_43c210
  L43cdb8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @756_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @757_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(370));  // @758_43c210
  ecx = edx = 0;  // @759_43c210
  esi = eax;  // @760_43c210
  ecx = (u32)(ebx + 16);  // @761_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @762_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @763_43c210
  ecx = edx = 0;  // @764_43c210
  p47_ = eax;  // @765_43c210
  p48_ = esi;  // @766_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p48_), (u32)(6799228), (u32)(p47_));  // @767_43c210
  ecx = edx = 0;  // @768_43c210
  goto L43ceaa;  // @769_43c210
  L43cdeb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @771_43c210
  ecx = (u32)(6799288);  // @772_43c210
  L43cdf3:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @774_43c210
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L43ce13;  // @775_43c210
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L43ce0f;  // @776_43c210
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @777_43c210
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L43ce13;  // @778_43c210
  eax = (eax + (u32)(2));  // @779_43c210
  ecx = (ecx + (u32)(2));  // @780_43c210
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L43cdf3;  // @781_43c210
  L43ce0f:;
  eax = 0;  // @783_43c210
  goto L43ce18;  // @784_43c210
  L43ce13:;
  eax = 0;  // @786_43c210
  eax = (eax | (u32)(1));  // @787_43c210
  L43ce18:;
  if ((eax & eax) != 0) goto L43ce62;  // @789_43c210
  p49_ = esi;  // @790_43c210
  ecx = ebx;  // @791_43c210
  eax = ext_61bac0_stdcall2((u32)(p49_), (u32)(6791480));  // @792_43c210
  ecx = edx = 0;  // @793_43c210
  p50_ = eax;  // @794_43c210
  ecx = (u32)(EBP - 272);  // @795_43c210
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p50_));  // @796_43c210
  ecx = edx = 0;  // @797_43c210
  eax = (u32)(EBP - 272);  // @798_43c210
  reg.state = (s32)((u32)(9));  // @799_43c210
  p51_ = eax;  // @800_43c210
  ecx = (u32)(ebx + 451);  // @801_43c210
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p51_));  // @802_43c210
  ecx = edx = 0;  // @803_43c210
  ecx = (u32)(EBP - 272);  // @804_43c210
  eax = ext_4cbec0_thiscall1(ecx);  // @805_43c210
  ecx = edx = 0;  // @806_43c210
  { u32 v = (u32)((u32)(12)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @807_43c210
  goto L43ceaa;  // @808_43c210
  L43ce62:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @810_43c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @811_43c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(387));  // @812_43c210
  ecx = edx = 0;  // @813_43c210
  esi = eax;  // @814_43c210
  ecx = (u32)(ebx + 16);  // @815_43c210
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @816_43c210
  eax = ext_4cc1d0_thiscall1(ecx);  // @817_43c210
  ecx = edx = 0;  // @818_43c210
  p52_ = eax;  // @819_43c210
  p53_ = esi;  // @820_43c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(p53_), (u32)(6799296), (u32)(p52_));  // @821_43c210
  ecx = edx = 0;  // @822_43c210
  goto L43ceaa;  // @823_43c210
  L43ce92:;
  goto L43cea5;  // @825_43c210
  L43ce99:;
  goto L43cea5;  // @827_43c210
  L43cea0:;
  L43cea5:;
  eax = ext_43b9a0_thiscall2(ecx, (u32)(6799440));  // @830_43c210
  ecx = edx = 0;  // @831_43c210
  L43ceaa:;
  SEH_LEAVE();  // @833_43c210
  ext_633654(G(u32, 0x6f5630));  // @834_43c210
  return eax;  // @835_43c210
}
PCREG(43c210, lifted_43c210);

