// batch200187.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_42afb0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42afb0");
extern "C" u32 FASTCALL ext_42b080_fastcall3(u32, u32, u32) __asm__("ext_42b080");
extern "C" u32 FASTCALL ext_42b160_fastcall4(u32, u32, u32, u32) __asm__("ext_42b160");
extern "C" u32 FASTCALL ext_54f2b0_fastcall2(u32, u32) __asm__("ext_54f2b0");
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
extern "C" u32 THISCALL ext_4cc500_thiscall1(u32) __asm__("ext_4cc500");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4f12e0_thiscall2(u32, u32) __asm__("ext_4f12e0");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_54d760_thiscall3(u32, u32, u32) __asm__("ext_54d760");
extern "C" u32 THISCALL ext_54e9d0_thiscall1(u32) __asm__("ext_54e9d0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2d60_thiscall3(u32, u32, u32) __asm__("ext_5f2d60");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_42ed30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_42ed30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 152), &SENT_ESI, 4);  // @0_42ed30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42ed30
  ecx = (ecx + (u32)(291));  // @2_42ed30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3_42ed30
  eax = ext_4cc1d0_thiscall1(ecx);  // @4_42ed30
  ecx = edx = 0;  // @5_42ed30
  p0_ = eax;  // @6_42ed30
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @7_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))((u32)(p0_), (u32)(58));  // @8_42ed30
  *(volatile u32 *)0x8140f4 = 0;  // @9_42ed30
  ecx = edx = 0;  // @10_42ed30
  if ((eax & eax) != 0) goto L42ed92;  // @11_42ed30
  L42ed84:;
  ecx = esi;  // @13_42ed30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @14_42ed30
  ecx = edx = 0;  // @15_42ed30
  goto L42edf9;  // @16_42ed30
  L42ed92:;
  p1_ = eax;  // @18_42ed30
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @19_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p1_), (u32)(92));  // @20_42ed30
  *(volatile u32 *)0x8140f4 = 0;  // @21_42ed30
  ecx = edx = 0;  // @22_42ed30
  if ((eax & eax) == 0) goto L42ed84;  // @23_42ed30
  eax = (eax + 1);  // @24_42ed30
  ecx = (u32)(EBP - 144);  // @25_42ed30
  p2_ = eax;  // @26_42ed30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p2_));  // @27_42ed30
  ecx = edx = 0;  // @28_42ed30
  ecx = (u32)(EBP - 144);  // @29_42ed30
  reg.state = (s32)((u32)(0));  // @30_42ed30
  eax = ext_4cc1d0_thiscall1(ecx);  // @31_42ed30
  ecx = edx = 0;  // @32_42ed30
  p3_ = eax;  // @33_42ed30
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @34_42ed30
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p3_), (u32)(92));  // @35_42ed30
  *(volatile u32 *)0x8140f4 = 0;  // @36_42ed30
  ecx = edx = 0;  // @37_42ed30
  ecx = esi;  // @38_42ed30
  if ((eax & eax) != 0) goto L42eddf;  // @39_42ed30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @40_42ed30
  ecx = edx = 0;  // @41_42ed30
  goto L42edee;  // @42_42ed30
  L42eddf:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @44_42ed30
  eax = (u32)(EBP - 144);  // @45_42ed30
  p4_ = eax;  // @46_42ed30
  eax = ext_4cbe50_thiscall2(ecx, (u32)(p4_));  // @47_42ed30
  ecx = edx = 0;  // @48_42ed30
  L42edee:;
  ecx = (u32)(EBP - 144);  // @50_42ed30
  eax = ext_4cbec0_thiscall1(ecx);  // @51_42ed30
  ecx = edx = 0;  // @52_42ed30
  L42edf9:;
  eax = esi;  // @54_42ed30
  SEH_LEAVE();  // @55_42ed30
  ext_633654(G(u32, 0x6f5630));  // @56_42ed30
  return eax;  // @57_42ed30
}
PCREG(42ed30, lifted_42ed30);

extern "C" u32 THISCALL lifted_54afd0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66ac9f);  // @h_54afd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 88), &SENT_ESI, 4);  // @0_54afd0
  __builtin_memcpy((void *)(u32)(EBP - 92), &SENT_EDI, 4);  // @1_54afd0
  edi = ecx;  // @2_54afd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_54afd0
  p0_ = esi;  // @4_54afd0
  eax = ext_54d760_thiscall3(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @5_54afd0
  ecx = edx = 0;  // @6_54afd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @7_54afd0
  eax = 0;  // @8_54afd0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @9_54afd0
  x0 = _mm_setzero_ps();  // @10_54afd0
  _mm_storeu_ps((float *)(u32)(EBP - 36), x0);  // @11_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @12_54afd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 25563), &v, sizeof v); }  // @13_54afd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 25564), &v, sizeof v); }  // @14_54afd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 93), &v, sizeof v); }  // @15_54afd0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; })) & 0xffff);  // @16_54afd0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) + (eax & 0xffff))) & 0xffff);  // @17_54afd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 73), &v, sizeof v); }  // @18_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @19_54afd0
  eax = (eax & 0xffff);  // @20_54afd0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }));  // @21_54afd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 74), &v, sizeof v); }  // @22_54afd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @23_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @24_54afd0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @25_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @26_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @27_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @28_54afd0
  eax = (u32)(16);  // @29_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 22), &v, sizeof v); }  // @30_54afd0
  eax = (u32)(1);  // @31_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @32_54afd0
  _mm_storeu_ps((float *)(u32)(EBP - 72), x0);  // @33_54afd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @34_54afd0
  _mm_storeu_ps((float *)(u32)(EBP - 56), x0);  // @35_54afd0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 41596), sizeof v); (u32)v; }) == (u32)(0)) goto L54b09a;  // @36_54afd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 117), sizeof v); (u32)v; }) == (u32)(3)) goto L54b09a;  // @37_54afd0
  ecx = (u32)(164);  // @38_54afd0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 74), &v, sizeof v); }  // @39_54afd0
  goto L54b09f;  // @40_54afd0
  L54b09a:;
  ecx = (u32)(160);  // @42_54afd0
  L54b09f:;
  eax = (u32)(65600);  // @44_54afd0
  esi = (u32)(196624);  // @45_54afd0
  { u32 v = (u32)((u32)(36)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @46_54afd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 57), sizeof v); (u32)v; }) == (u32)(1)) eax = esi;  // @47_54afd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @48_54afd0
  ecx = (ecx | eax);  // @49_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @50_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @51_54afd0
  eax = (u32)(EBP - 36);  // @52_54afd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @53_54afd0
  ecx = edx;  // @54_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @55_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @56_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 200), sizeof v); (u32)v; });  // @57_54afd0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @58_54afd0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @59_54afd0
  *(volatile u32 *)0x8140f4 = 0;  // @60_54afd0
  ecx = edx = 0;  // @61_54afd0
  esi = (u32)(edi + 25580);  // @62_54afd0
  p1_ = esi;  // @63_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @64_54afd0
  edx = (u32)(EBP - 72);  // @65_54afd0
  p2_ = edx;  // @66_54afd0
  p3_ = eax;  // @67_54afd0
  *(volatile u32 *)0x8140f4 = 0x80000010;  // @68_54afd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 12)))(ecx, (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(0));  // @69_54afd0
  *(volatile u32 *)0x8140f4 = 0;  // @70_54afd0
  ecx = edx = 0;  // @71_54afd0
  if ((eax & eax) == 0) goto L54b105;  // @72_54afd0
  edx = (u32)(6961276);  // @73_54afd0
  ecx = eax;  // @74_54afd0
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @75_54afd0
  ecx = edx = 0;  // @76_54afd0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @77_54afd0
  goto L54b1cc;  // @78_54afd0
  L54b105:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 57), sizeof v); (u32)v; }) != (u32)(1)) goto L54b14b;  // @80_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @81_54afd0
  eax = (u32)(edi + 25584);  // @82_54afd0
  p4_ = eax;  // @83_54afd0
  p5_ = ecx;  // @84_54afd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_54afd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 73), &v, sizeof v); }  // @86_54afd0
  *(volatile u32 *)0x8140f4 = 0x8000000c;  // @87_54afd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(p5_), (u32)(7070112), (u32)(p4_));  // @88_54afd0
  *(volatile u32 *)0x8140f4 = 0;  // @89_54afd0
  ecx = edx = 0;  // @90_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @91_54afd0
  if ((eax & eax) == 0) goto L54b14b;  // @92_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_54afd0
  p6_ = ecx;  // @94_54afd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_54afd0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @96_54afd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 8)))(ecx, (u32)(p6_));  // @97_54afd0
  *(volatile u32 *)0x8140f4 = 0;  // @98_54afd0
  ecx = edx = 0;  // @99_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @100_54afd0
  edx = (u32)(6961300);  // @101_54afd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @102_54afd0
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @103_54afd0
  ecx = edx = 0;  // @104_54afd0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @105_54afd0
  goto L54b1cc;  // @106_54afd0
  L54b14b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @108_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 204), sizeof v); (u32)v; });  // @110_54afd0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @111_54afd0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @112_54afd0
  *(volatile u32 *)0x8140f4 = 0;  // @113_54afd0
  ecx = edx = 0;  // @114_54afd0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L54b1ca;  // @115_54afd0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 73), sizeof v); (u32)v; }) == (u32)(0)) goto L54b1ca;  // @116_54afd0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 74), sizeof v); (u32)v; }) == (u32)(0)) goto L54b1ca;  // @117_54afd0
  eax = ext_41e290_cdecl1((u32)(80));  // @118_54afd0
  ecx = edx = 0;  // @119_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @120_54afd0
  reg.state = (s32)((u32)(0));  // @121_54afd0
  if ((eax & eax) == 0) goto L54b18b;  // @122_54afd0
  ecx = eax;  // @123_54afd0
  eax = ext_54e9d0_thiscall1(ecx);  // @124_54afd0
  ecx = edx = 0;  // @125_54afd0
  ecx = eax;  // @126_54afd0
  goto L54b18d;  // @127_54afd0
  L54b18b:;
  ecx = 0;  // @129_54afd0
  L54b18d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 25588), &v, sizeof v); }  // @131_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_54afd0
  reg.state = (s32)((u32)(4294967295));  // @133_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @134_54afd0
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @135_54afd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(1));  // @136_54afd0
  *(volatile u32 *)0x8140f4 = 0;  // @137_54afd0
  ecx = edx = 0;  // @138_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25588), sizeof v); (u32)v; });  // @139_54afd0
  if ((eax & eax) != 0) goto L54b1c5;  // @140_54afd0
  if ((ecx & ecx) == 0) goto L54b1b9;  // @141_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @142_54afd0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @143_54afd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @144_54afd0
  *(volatile u32 *)0x8140f4 = 0;  // @145_54afd0
  ecx = edx = 0;  // @146_54afd0
  L54b1b9:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 25588), &v, sizeof v); }  // @148_54afd0
  goto L54b1ca;  // @149_54afd0
  L54b1c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_54afd0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @152_54afd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @153_54afd0
  *(volatile u32 *)0x8140f4 = 0;  // @154_54afd0
  ecx = edx = 0;  // @155_54afd0
  L54b1ca:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @157_54afd0
  L54b1cc:;
  SEH_LEAVE();  // @159_54afd0
  ext_633654(G(u32, 0x6f5630));  // @160_54afd0
  __asm__ volatile("" :: "Yz"(x0));  // @161_54afd0
  return eax;  // @162_54afd0
}
PCREG(54afd0, lifted_54afd0);

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
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @9_4f4790
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @10_4f4790
  *(volatile u32 *)0x8140f4 = 0;  // @11_4f4790
  ecx = edx = 0;  // @12_4f4790
  ecx = (u32)(EBP - 24);  // @13_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @14_4f4790
  p0_ = ecx;  // @15_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_4f4790
  ecx = eax;  // @17_4f4790
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @18_4f4790
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6918004), (u32)(p0_));  // @19_4f4790
  *(volatile u32 *)0x8140f4 = 0;  // @20_4f4790
  ecx = edx = 0;  // @21_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4f4790
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @25_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @26_4f4790
  *(volatile u32 *)0x8140f4 = 0;  // @27_4f4790
  ecx = edx = 0;  // @28_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @29_4f4790
  edx = 0;  // @30_4f4790
  esi = 0;  // @31_4f4790
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 176), sizeof v); (u32)v; })));  // @32_4f4790
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @33_4f4790
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(eax + 155)));  // @34_4f4790
  eax = (u32)_mm_cvtss_si32(x0);  // @35_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @36_4f4790
  L4f4823:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; });  // @38_4f4790
  edi = 0;  // @39_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @40_4f4790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @41_4f4790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @42_4f4790
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) == (u32)(0)) goto L4f48fb;  // @43_4f4790
  L4f4840:;
  ecx = (u32)(EBP - 20);  // @45_4f4790
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @46_4f4790
  eax = ext_4cc500_thiscall1(ecx);  // @47_4f4790
  ecx = edx = 0;  // @48_4f4790
  edx = eax;  // @49_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @50_4f4790
  eax = (eax - ebx);  // @51_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @52_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @53_4f4790
  if (edx != (u32)(10)) goto L4f4866;  // @54_4f4790
  ecx = 0;  // @55_4f4790
  edi = 0;  // @56_4f4790
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @57_4f4790
  goto L4f48ad;  // @58_4f4790
  L4f4866:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @60_4f4790
  p1_ = edx;  // @61_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 159), sizeof v); (u32)v; });  // @62_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_4f4790
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @64_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 640)))(ecx, (u32)(p1_));  // @65_4f4790
  *(volatile u32 *)0x8140f4 = 0;  // @66_4f4790
  ecx = edx = 0;  // @67_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @68_4f4790
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }));  // @69_4f4790
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @70_4f4790
  ecx = (ecx + eax);  // @71_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @72_4f4790
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @73_4f4790
  if (eax == (u32)(32)) goto L4f4894;  // @74_4f4790
  if (eax != (u32)(9)) goto L4f48aa;  // @75_4f4790
  L4f4894:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @77_4f4790
  edi = ebx;  // @78_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @79_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @80_4f4790
  if ((edx & edx) != 0) edi = esi;  // @81_4f4790
  goto L4f48b0;  // @82_4f4790
  L4f48aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @84_4f4790
  L4f48ad:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @86_4f4790
  L4f48b0:;
  if ((s32)ecx > (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; })) goto L4f48cf;  // @88_4f4790
  if ((edx & edx) == 0) goto L4f48c7;  // @89_4f4790
  p2_ = eax;  // @90_4f4790
  p3_ = ebx;  // @91_4f4790
  p4_ = esi;  // @92_4f4790
  eax = ext_634d22_cdecl3((u32)(p4_), (u32)(p3_), (u32)(p2_));  // @93_4f4790
  ecx = edx = 0;  // @94_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @95_4f4790
  L4f48c7:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @97_4f4790
  esi = (esi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @98_4f4790
  goto L4f48ef;  // @99_4f4790
  L4f48cf:;
  if ((edi & edi) == 0) goto L4f48e0;  // @101_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @102_4f4790
  { u8 v = (u8)((u32)(10)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @103_4f4790
  edi = 0;  // @104_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @105_4f4790
  goto L4f48ef;  // @106_4f4790
  L4f48e0:;
  if ((edx & edx) == 0) goto L4f48e7;  // @108_4f4790
  { u8 v = (u8)((u32)(10)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @109_4f4790
  L4f48e7:;
  esi = (esi + 1);  // @111_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @112_4f4790
  L4f48ef:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(0)) goto L4f4840;  // @114_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @115_4f4790
  L4f48fb:;
  if ((edx & edx) != 0) goto L4f493d;  // @117_4f4790
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; }));  // @118_4f4790
  if (esi == ebx) goto L4f492b;  // @119_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @120_4f4790
  eax = (u32)(esi + 1);  // @121_4f4790
  p5_ = eax;  // @122_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_4f4790
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @124_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, (u32)(p5_));  // @125_4f4790
  *(volatile u32 *)0x8140f4 = 0;  // @126_4f4790
  ecx = edx = 0;  // @127_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @128_4f4790
  edx = eax;  // @129_4f4790
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + edx), &v, sizeof v); }  // @130_4f4790
  esi = edx;  // @131_4f4790
  goto L4f4823;  // @132_4f4790
  L4f492b:;
  eax = ext_4f12e0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; }));  // @134_4f4790
  ecx = edx = 0;  // @135_4f4790
  __asm__ volatile("" :: "Yz"(x0));  // @136_4f4790
  return eax;  // @137_4f4790
  L4f493d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 151), sizeof v); (u32)v; });  // @139_4f4790
  if ((esi & esi) == 0) goto L4f495c;  // @140_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @141_4f4790
  p6_ = esi;  // @142_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_4f4790
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @144_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, (u32)(p6_));  // @145_4f4790
  *(volatile u32 *)0x8140f4 = 0;  // @146_4f4790
  ecx = edx = 0;  // @147_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @148_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @149_4f4790
  L4f495c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 151), &v, sizeof v); }  // @152_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 632), sizeof v); (u32)v; });  // @153_4f4790
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @154_4f4790
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @155_4f4790
  *(volatile u32 *)0x8140f4 = 0;  // @156_4f4790
  ecx = edx = 0;  // @157_4f4790
  __asm__ volatile("" :: "Yz"(x0));  // @158_4f4790
  return eax;  // @159_4f4790
  L4f4973:;
  ecx = eax;  // @161_4f4790
  eax = ext_4f12e0_thiscall2(ecx, (u32)(6781786));  // @162_4f4790
  ecx = edx = 0;  // @163_4f4790
  __asm__ volatile("" :: "Yz"(x0));  // @164_4f4790
  return eax;  // @165_4f4790
}
PCREG(4f4790, lifted_4f4790);

extern "C" u32 THISCALL lifted_422ba0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_;
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_422ba0
  __builtin_memcpy((void *)(u32)(EBP - 52), &SENT_ESI, 4);  // @4_422ba0
  esi = ecx;  // @5_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @6_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @7_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @8_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @9_422ba0
  __builtin_memcpy((void *)(u32)(EBP - 56), &SENT_EDI, 4);  // @10_422ba0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @11_422ba0
  ecx = (u32)(esi + 9179);  // @12_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @13_422ba0
  eax = ext_4cc5f0_thiscall1(ecx);  // @14_422ba0
  ecx = edx = 0;  // @15_422ba0
  if ((eax & eax) == 0) goto L422e44;  // @16_422ba0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9692), sizeof v); (u32)v; }) != (u32)(0)) goto L422c08;  // @17_422ba0
  eax = ext_41e290_cdecl1((u32)(500000000));  // @18_422ba0
  ecx = edx = 0;  // @19_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9692), &v, sizeof v); }  // @20_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @21_422ba0
  { u32 v = (u32)((u32)(500000000)); __builtin_memcpy((void *)(u32)(esi + 9700), &v, sizeof v); }  // @22_422ba0
  L422c08:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @24_422ba0
  eax = (u32)(edi + 1008);  // @25_422ba0
  ecx = ebx;  // @26_422ba0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @27_422ba0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9692), sizeof v); (u32)v; }));  // @28_422ba0
  eax = (eax + ecx);  // @29_422ba0
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9700), sizeof v); (u32)v; })) goto L422c45;  // @30_422ba0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 9700), &v, sizeof v); }  // @31_422ba0
  eax = 0;  // @32_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @33_422ba0
  ecx = (ecx ^ EBP);  // @34_422ba0
  eax = ext_633654_thiscall1(ecx);  // @35_422ba0
  ecx = edx = 0;  // @36_422ba0
  return eax;  // @37_422ba0
  L422c45:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @39_422ba0
  x0 = _mm_setzero_ps();  // @40_422ba0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @41_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @42_422ba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @43_422ba0
  eax = (eax + (u32)(4));  // @44_422ba0
  ecx = edx;  // @45_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @46_422ba0
  _mm_storeu_ps((float *)(u32)(EBP - 20), x0);  // @47_422ba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @48_422ba0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @49_422ba0
  eax = (u32)(ecx + 1);  // @50_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @51_422ba0
  L422c74:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @53_422ba0
  ecx = (ecx + 1);  // @54_422ba0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L422c74;  // @55_422ba0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @56_422ba0
  eax = (u32)(15);  // @57_422ba0
  if (ecx > eax) ecx = eax;  // @58_422ba0
  eax = (u32)(edx + 1);  // @59_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @60_422ba0
  L422c90:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @62_422ba0
  edx = (edx + 1);  // @63_422ba0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L422c90;  // @64_422ba0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @65_422ba0
  eax = (u32)(ecx + 1);  // @66_422ba0
  p0_ = eax;  // @67_422ba0
  edx = (edx - ecx);  // @68_422ba0
  eax = (u32)(EBP - 20);  // @69_422ba0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }));  // @70_422ba0
  p1_ = edx;  // @71_422ba0
  p2_ = eax;  // @72_422ba0
  eax = ext_634d22_cdecl3((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @73_422ba0
  ecx = edx = 0;  // @74_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @75_422ba0
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 20));  // @76_422ba0
  p3_ = edi;  // @77_422ba0
  _mm_storeu_ps((float *)(u32)(eax), x0);  // @78_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @79_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @80_422ba0
  ecx = (ecx + (u32)(16));  // @81_422ba0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @82_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @83_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @84_422ba0
  eax = (eax + (u32)(4));  // @85_422ba0
  p4_ = eax;  // @86_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @87_422ba0
  eax = ext_634d22_cdecl3((u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; }), (u32)(p3_));  // @88_422ba0
  ecx = edx = 0;  // @89_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @90_422ba0
  eax = (eax + edi);  // @91_422ba0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @92_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @93_422ba0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi*8 + 9707), sizeof v); (u32)v; }) != (u32)(0)) goto L422d45;  // @94_422ba0
  eax = (eax - ebx);  // @95_422ba0
  p5_ = eax;  // @96_422ba0
  eax = ext_41e290_cdecl1((u32)(p5_));  // @97_422ba0
  ecx = edx = 0;  // @98_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi*8 + 9707), &v, sizeof v); }  // @99_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @100_422ba0
  ecx = (ecx - ebx);  // @101_422ba0
  p6_ = ecx;  // @102_422ba0
  p7_ = eax;  // @103_422ba0
  eax = ext_634d10_cdecl3((u32)(p7_), (u32)(0), (u32)(p6_));  // @104_422ba0
  ecx = edx = 0;  // @105_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @106_422ba0
  eax = (eax - ebx);  // @107_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi*8 + 9711), &v, sizeof v); }  // @108_422ba0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi*8 + 9707), sizeof v); (u32)v; }) == (u32)(0)) goto L422df6;  // @109_422ba0
  L422d45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @111_422ba0
  edx = 0;  // @112_422ba0
  eax = (eax - ebx);  // @113_422ba0
  if (eax == 0) goto L422d6e;  // @114_422ba0
  L422d51:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi*8 + 9707), sizeof v); (u32)v; });  // @116_422ba0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx), sizeof v); (u32)v; })) & 0xff);  // @117_422ba0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }))) & 0xff);  // @118_422ba0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @119_422ba0
  edx = (edx + 1);  // @120_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @121_422ba0
  eax = (eax - ebx);  // @122_422ba0
  if (edx != eax) goto L422d51;  // @123_422ba0
  L422d6e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @125_422ba0
  eax = (eax - ebx);  // @126_422ba0
  edi = (u32)(eax*4 + 100);  // @127_422ba0
  p8_ = edi;  // @128_422ba0
  eax = ext_41e290_cdecl1((u32)(p8_));  // @129_422ba0
  ecx = edx = 0;  // @130_422ba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @131_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @132_422ba0
  ebx = eax;  // @133_422ba0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @134_422ba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*8 + 9707), sizeof v); (u32)v; });  // @135_422ba0
  ecx = (ecx + edx);  // @136_422ba0
  p9_ = ecx;  // @137_422ba0
  p10_ = edx;  // @138_422ba0
  ecx = (u32)(ebx + edi);  // @139_422ba0
  p11_ = ecx;  // @140_422ba0
  p12_ = ebx;  // @141_422ba0
  ecx = (u32)(EBP - 29);  // @142_422ba0
  eax = ext_421ed0_thiscall5(ecx, (u32)(p12_), (u32)(p11_), (u32)(p10_), (u32)(p9_));  // @143_422ba0
  ecx = edx = 0;  // @144_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @145_422ba0
  edi = eax;  // @146_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @147_422ba0
  ecx = (ecx - eax);  // @148_422ba0
  p13_ = ecx;  // @149_422ba0
  p14_ = eax;  // @150_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @151_422ba0
  eax = ext_634d22_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*8 + 9707), sizeof v); (u32)v; }), (u32)(p14_), (u32)(p13_));  // @152_422ba0
  ecx = edx = 0;  // @153_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @154_422ba0
  p15_ = edi;  // @155_422ba0
  p16_ = ebx;  // @156_422ba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @157_422ba0
  eax = (eax + (u32)(4));  // @158_422ba0
  p17_ = eax;  // @159_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @160_422ba0
  eax = ext_634d22_cdecl3((u32)(p17_), (u32)(p16_), (u32)(p15_));  // @161_422ba0
  ecx = edx = 0;  // @162_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @163_422ba0
  eax = (eax + edi);  // @164_422ba0
  p18_ = ebx;  // @165_422ba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 9696), &v, sizeof v); }  // @166_422ba0
  eax = ext_634273_cdecl2((u32)(p18_), (u32)(1));  // @167_422ba0
  ecx = edx = 0;  // @168_422ba0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @169_422ba0
  L422df6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9691), sizeof v); (u32)v; }) == (u32)(0)) goto L422e25;  // @171_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @172_422ba0
  ecx = (u32)(esi + 9179);  // @173_422ba0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @174_422ba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @175_422ba0
  eax = (eax - ebx);  // @176_422ba0
  p19_ = eax;  // @177_422ba0
  p20_ = ebx;  // @178_422ba0
  eax = ext_4cc1d0_cdecl2((u32)(p20_), (u32)(p19_));  // @179_422ba0
  ecx = edx = 0;  // @180_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @181_422ba0
  p21_ = eax;  // @182_422ba0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @183_422ba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 104)))(ecx, (u32)(p21_));  // @184_422ba0
  *(volatile u32 *)0x8140f4 = 0;  // @185_422ba0
  ecx = edx = 0;  // @186_422ba0
  L422e25:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9696), sizeof v); (u32)v; });  // @188_422ba0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9692), sizeof v); (u32)v; }));  // @189_422ba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @190_422ba0
  ecx = (ecx ^ EBP);  // @191_422ba0
  eax = ext_633654_thiscall1(ecx);  // @192_422ba0
  ecx = edx = 0;  // @193_422ba0
  __asm__ volatile("" :: "Yz"(x0));  // @194_422ba0
  return eax;  // @195_422ba0
  L422e44:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @197_422ba0
  eax = 0;  // @198_422ba0
  ecx = (ecx ^ EBP);  // @199_422ba0
  eax = ext_633654_thiscall1(ecx);  // @200_422ba0
  ecx = edx = 0;  // @201_422ba0
  __asm__ volatile("" :: "Yz"(x0));  // @202_422ba0
  return eax;  // @203_422ba0
}
PCREG(422ba0, lifted_422ba0);

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
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @15_4711f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @16_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @17_4711f0
  ecx = edx = 0;  // @18_4711f0
  goto L47125d;  // @19_4711f0
  L471254:;
  if (((eax & 0xff) & (u32)(1)) != 0) goto L47125d;  // @21_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @23_4711f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @24_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @25_4711f0
  ecx = edx = 0;  // @26_4711f0
  L47125d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4711f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @31_4711f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; }));  // @32_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @33_4711f0
  ecx = edx = 0;  // @34_4711f0
  ecx = eax;  // @35_4711f0
  if ((ecx & ecx) == 0) goto L4712d6;  // @36_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4711f0
  p0_ = ebx;  // @38_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 756), sizeof v); (u32)v; });  // @39_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @40_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p0_), (u32)(0));  // @41_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @42_4711f0
  ecx = edx = 0;  // @43_4711f0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4712d6;  // @44_4711f0
  ecx = (u32)(EBP - 16596);  // @45_4711f0
  eax = ext_4d2280_thiscall1(ecx);  // @46_4711f0
  ecx = edx = 0;  // @47_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @48_4711f0
  esi = (u32)(EBP - 16596);  // @49_4711f0
  reg.state = (s32)((u32)(0));  // @50_4711f0
  p1_ = ebx;  // @51_4711f0
  if ((eax & eax) != 0) esi = eax;  // @52_4711f0
  ecx = esi;  // @53_4711f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @55_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(6850636), (u32)(p1_));  // @56_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @57_4711f0
  ecx = edx = 0;  // @58_4711f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @59_4711f0
  ecx = edi;  // @60_4711f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @61_4711f0
  p2_ = esi;  // @62_4711f0
  p3_ = eax;  // @63_4711f0
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @64_4711f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(p3_), (u32)(p2_));  // @65_4711f0
  *(volatile u32 *)0x8140f4 = 0;  // @66_4711f0
  ecx = edx = 0;  // @67_4711f0
  ecx = (u32)(EBP - 16596);  // @68_4711f0
  eax = ext_4d2330_thiscall1(ecx);  // @69_4711f0
  ecx = edx = 0;  // @70_4711f0
  L4712d2:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @72_4711f0
  goto L4712d8;  // @73_4711f0
  L4712d6:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @75_4711f0
  L4712d8:;
  SEH_LEAVE();  // @77_4711f0
  ext_633654(G(u32, 0x6f5630));  // @78_4711f0
  return eax;  // @79_4711f0
}
PCREG(4711f0, lifted_4711f0);

extern "C" u32 THISCALL lifted_432270(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6686a6);  // @h_432270
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
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
  esi = (esi + 1);  // @61_432270
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(1131574387)) goto L4323fc;  // @62_432270
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @63_432270
  if ((eax & 0xff) != (u32)(67)) goto L4323dd;  // @64_432270
  if ((edi & edi) == 0) goto L4323dd;  // @65_432270
  p4_ = edi;  // @66_432270
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @67_432270
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))((u32)(p4_));  // @68_432270
  *(volatile u32 *)0x8140f4 = 0;  // @69_432270
  ecx = edx = 0;  // @70_432270
  ecx = (u32)(EBP - 144);  // @71_432270
  edi = eax;  // @72_432270
  ebx = (ebx + (u32)(5));  // @73_432270
  eax = ext_4cbeb0_thiscall1(ecx);  // @74_432270
  ecx = edx = 0;  // @75_432270
  p5_ = edi;  // @76_432270
  ecx = (u32)(EBP - 144);  // @77_432270
  reg.state = (s32)((u32)(1));  // @78_432270
  eax = ext_4cbf30_thiscall2(ecx, (u32)(p5_));  // @79_432270
  ecx = edx = 0;  // @80_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @81_432270
  ecx = (u32)(EBP - 144);  // @82_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @83_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @84_432270
  ecx = edx = 0;  // @85_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @86_432270
  p6_ = eax;  // @87_432270
  p7_ = ebx;  // @88_432270
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @89_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 104)))(ecx, (u32)(p7_), (u32)(p6_));  // @90_432270
  *(volatile u32 *)0x8140f4 = 0;  // @91_432270
  ecx = edx = 0;  // @92_432270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_432270
  ecx = (u32)(EBP - 144);  // @94_432270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @95_432270
  eax = ext_4cc1d0_thiscall1(ecx);  // @96_432270
  ecx = edx = 0;  // @97_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @98_432270
  p8_ = eax;  // @99_432270
  p9_ = ebx;  // @100_432270
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @101_432270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(p9_), (u32)(p8_));  // @102_432270
  *(volatile u32 *)0x8140f4 = 0;  // @103_432270
  ecx = edx = 0;  // @104_432270
  ecx = (u32)(EBP - 144);  // @105_432270
  reg.state = (s32)((u32)(0));  // @106_432270
  eax = ext_4cbec0_thiscall1(ecx);  // @107_432270
  ecx = edx = 0;  // @108_432270
  goto L4323fc;  // @109_432270
  L4323dd:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(1131574387)) goto L4323fc;  // @111_432270
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @112_432270
  if ((eax & 0xff) != (u32)(114)) goto L4323fc;  // @113_432270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @114_432270
  eax = (u32)(ebx + 5);  // @115_432270
  p10_ = eax;  // @116_432270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_432270
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @118_432270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(p10_));  // @119_432270
  *(volatile u32 *)0x8140f4 = 0;  // @120_432270
  ecx = edx = 0;  // @121_432270
  L4323fc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L432300;  // @123_432270
  L432405:;
  ecx = (u32)(EBP - 272);  // @125_432270
  eax = ext_4cbec0_thiscall1(ecx);  // @126_432270
  ecx = edx = 0;  // @127_432270
  SEH_LEAVE();  // @128_432270
  ext_633654(G(u32, 0x6f5630));  // @129_432270
  return eax;  // @130_432270
}
PCREG(432270, lifted_432270);

extern "C" u32 THISCALL lifted_4302d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665320);  // @h_4302d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
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
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_4302d0
  ecx = (u32)(eax - 12);  // @22_4302d0
  reg.state = (s32)((u32)(1));  // @23_4302d0
  p1_ = ecx;  // @24_4302d0
  edx = (u32)(eax - 24);  // @25_4302d0
  ecx = esi;  // @26_4302d0
  eax = ext_42afb0_fastcall5(ecx, edx, (u32)(p1_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(0));  // @27_4302d0
  ecx = edx = 0;  // @28_4302d0
  eax = (u32)(EBP - 32);  // @29_4302d0
  if (eax == esi) goto L43036a;  // @30_4302d0
  ecx = esi;  // @31_4302d0
  eax = ext_5f2d60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @32_4302d0
  ecx = edx = 0;  // @33_4302d0
  L43036a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @35_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @36_4302d0
  eax = (eax - ecx);  // @37_4302d0
  reg.state = (s32)((u32)(2));  // @38_4302d0
  if ((ecx & ecx) == 0) goto L430465;  // @39_4302d0
  if ((eax & eax) == 0) goto L430465;  // @40_4302d0
  p2_ = eax;  // @41_4302d0
  p3_ = ecx;  // @42_4302d0
  ecx = (u32)(EBP - 32);  // @43_4302d0
  eax = ext_54f870_stdcall2((u32)(p3_), (u32)(p2_));  // @44_4302d0
  ecx = edx = 0;  // @45_4302d0
  SEH_LEAVE();  // @46_4302d0
  return eax;  // @47_4302d0
  L4303a7:;
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @49_4302d0
  eax = (u32)(715827883);  // @50_4302d0
  { long long t_ = (long long)(s32)eax * (long long)(s32)ecx; eax = (u32)t_; edx = (u32)((u64)t_ >> 32); }  // @51_4302d0
  edx = (u32)((s32)edx >> (u32)(1));  // @52_4302d0
  edi = edx;  // @53_4302d0
  edi = (edi >> (u32)(31));  // @54_4302d0
  edi = (edi + edx);  // @55_4302d0
  if (edi == 0) goto L4303c3;  // @56_4302d0
  edi = (edi + edi);  // @57_4302d0
  if (edi != 0) goto L4303c8;  // @58_4302d0
  ebx = 0;  // @59_4302d0
  goto L4303d8;  // @60_4302d0
  L4303c3:;
  edi = (u32)(1);  // @62_4302d0
  L4303c8:;
  eax = (u32)(edi + edi*2);  // @64_4302d0
  ecx = esi;  // @65_4302d0
  eax = (eax << (u32)(2));  // @66_4302d0
  p4_ = eax;  // @67_4302d0
  eax = ext_6014a0_stdcall1((u32)(p4_));  // @68_4302d0
  ecx = edx = 0;  // @69_4302d0
  ebx = eax;  // @70_4302d0
  L4303d8:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @72_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_4302d0
  p5_ = ebx;  // @74_4302d0
  eax = ext_42b160_fastcall4(ecx, edx, (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @75_4302d0
  ecx = edx = 0;  // @76_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @77_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @78_4302d0
  reg.state = (s32)((u32)(3));  // @79_4302d0
  if ((eax & eax) == 0) goto L430404;  // @80_4302d0
  ecx = eax;  // @81_4302d0
  eax = ext_5f10c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @82_4302d0
  ecx = edx = 0;  // @83_4302d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @84_4302d0
  L430404:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @86_4302d0
  eax = (eax + (u32)(12));  // @87_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @88_4302d0
  p6_ = eax;  // @89_4302d0
  reg.state = (s32)((u32)(4294967295));  // @90_4302d0
  eax = ext_42b160_fastcall4(ecx, edx, (u32)(p6_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @91_4302d0
  ecx = edx = 0;  // @92_4302d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @93_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @94_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @95_4302d0
  eax = ext_42b080_fastcall3(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @96_4302d0
  ecx = edx = 0;  // @97_4302d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @98_4302d0
  eax = (u32)(715827883);  // @99_4302d0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @100_4302d0
  { long long t_ = (long long)(s32)eax * (long long)(s32)ecx; eax = (u32)t_; edx = (u32)((u64)t_ >> 32); }  // @101_4302d0
  edx = (u32)((s32)edx >> (u32)(1));  // @102_4302d0
  eax = edx;  // @103_4302d0
  eax = (eax >> (u32)(31));  // @104_4302d0
  eax = (eax + edx);  // @105_4302d0
  if (eax == 0) goto L430454;  // @106_4302d0
  eax = (u32)(eax + eax*2);  // @107_4302d0
  ecx = esi;  // @108_4302d0
  eax = (eax << (u32)(2));  // @109_4302d0
  p7_ = eax;  // @110_4302d0
  eax = ext_54f870_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(p7_));  // @111_4302d0
  ecx = edx = 0;  // @112_4302d0
  L430454:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @114_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @115_4302d0
  eax = (u32)(edi + edi*2);  // @116_4302d0
  eax = (u32)(ebx + eax*4);  // @117_4302d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @118_4302d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @119_4302d0
  L430465:;
  SEH_LEAVE();  // @121_4302d0
  return eax;  // @122_4302d0
}
PCREG(4302d0, lifted_4302d0);

extern "C" u32 THISCALL lifted_42c9a0(u32 ecx_in) {
  SEH_ENTER(0x664dc6);  // @h_42c9a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_;
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
  esi = (esi + 1);  // @22_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @23_42c9a0
  ecx = edx = 0;  // @24_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) == (u32)(92)) goto L42ca06;  // @25_42c9a0
  ecx = ebx;  // @26_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @27_42c9a0
  ecx = edx = 0;  // @28_42c9a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) == (u32)(47)) goto L42ca06;  // @29_42c9a0
  ecx = ebx;  // @30_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @31_42c9a0
  ecx = edx = 0;  // @32_42c9a0
  eax = (eax + 1);  // @33_42c9a0
  p0_ = eax;  // @34_42c9a0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @35_42c9a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676410))((u32)(p0_), (u32)(6790792), (u32)(7));  // @36_42c9a0
  *(volatile u32 *)0x8140f4 = 0;  // @37_42c9a0
  ecx = edx = 0;  // @38_42c9a0
  if ((eax & eax) != 0) goto L42cb07;  // @39_42c9a0
  eax = ext_41e290_cdecl1((u32)(260));  // @40_42c9a0
  ecx = edx = 0;  // @41_42c9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_42c9a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @43_42c9a0
  ecx = edi;  // @44_42c9a0
  eax = (u32)(EBP - 272);  // @45_42c9a0
  p1_ = eax;  // @46_42c9a0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @47_42c9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 412)))(ecx, (u32)(p1_));  // @48_42c9a0
  *(volatile u32 *)0x8140f4 = 0;  // @49_42c9a0
  ecx = edx = 0;  // @50_42c9a0
  ecx = eax;  // @51_42c9a0
  reg.state = (s32)((u32)(0));  // @52_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @53_42c9a0
  ecx = edx = 0;  // @54_42c9a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @55_42c9a0
  edx = edi;  // @56_42c9a0
  edx = (edx - eax);  // @57_42c9a0
  L42ca80:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @59_42c9a0
  eax = (u32)(eax + 1);  // @60_42c9a0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @61_42c9a0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L42ca80;  // @62_42c9a0
  ecx = (u32)(EBP - 272);  // @63_42c9a0
  reg.state = (s32)((u32)(4294967295));  // @64_42c9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @65_42c9a0
  ecx = edx = 0;  // @66_42c9a0
  ecx = ebx;  // @67_42c9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @68_42c9a0
  ecx = edx = 0;  // @69_42c9a0
  edx = (u32)(esi + eax);  // @70_42c9a0
  esi = edx;  // @71_42c9a0
  L42cab0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @73_42c9a0
  edx = (edx + 1);  // @74_42c9a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42cab0;  // @75_42c9a0
  edx = (edx - esi);  // @76_42c9a0
  edi = (edi - 1);  // @77_42c9a0
  L42cac0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @79_42c9a0
  edi = (edi + 1);  // @80_42c9a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42cac0;  // @81_42c9a0
  ecx = edx;  // @82_42c9a0
  ecx = (ecx >> (u32)(2));  // @83_42c9a0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @84_42c9a0
  ecx = edx;  // @85_42c9a0
  ecx = (ecx & (u32)(3));  // @86_42c9a0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 1); esi += 1; edi += 1; ecx--; }  // @87_42c9a0
  ecx = (u32)(EBP - 144);  // @88_42c9a0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @89_42c9a0
  ecx = edx = 0;  // @90_42c9a0
  eax = (u32)(EBP - 144);  // @91_42c9a0
  reg.state = (s32)((u32)(1));  // @92_42c9a0
  p2_ = eax;  // @93_42c9a0
  ecx = ebx;  // @94_42c9a0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @95_42c9a0
  ecx = edx = 0;  // @96_42c9a0
  ecx = (u32)(EBP - 144);  // @97_42c9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @98_42c9a0
  ecx = edx = 0;  // @99_42c9a0
  L42cb07:;
  SEH_LEAVE();  // @101_42c9a0
  ext_633654(G(u32, 0x6f5630));  // @102_42c9a0
  return eax;  // @103_42c9a0
}
PCREG(42c9a0, lifted_42c9a0);

extern "C" u32 THISCALL lifted_616150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e688);  // @h_616150
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_616150
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; });  // @17_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @18_616150
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @19_616150
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @20_616150
  eax = esi;  // @21_616150
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; }));  // @22_616150
  ecx = 0;  // @23_616150
  { u64 t_ = (u64)eax * (u64)(edx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @24_616150
  ecx = (ecx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @25_616150
  ecx = (0u - ecx);  // @26_616150
  ecx = (ecx | eax);  // @27_616150
  p0_ = ecx;  // @28_616150
  eax = ext_41e290_cdecl1((u32)(p0_));  // @29_616150
  ecx = edx = 0;  // @30_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @31_616150
  if ((esi & esi) == 0) goto L6162d1;  // @32_616150
  x1 = _mm_load_ss((const float *)(u32)(6785112));  // @33_616150
  esi = (u32)(eax + 8);  // @34_616150
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @35_616150
  edi = (edi + (u32)(8));  // @36_616150
  L616200:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 8), sizeof v); (u32)v; });  // @38_616150
  x0 = x1;  // @39_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 8), &v, sizeof v); }  // @40_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; });  // @41_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 4), &v, sizeof v); }  // @42_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @43_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @44_616150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @45_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @46_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @47_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @48_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @49_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @50_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @51_616150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @52_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @53_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @54_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @55_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @56_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @57_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @58_616150
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(edi + 4)));  // @59_616150
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(edi + 8)));  // @60_616150
  x0 = _mm_sub_ss(x0, _mm_load_ss((const float *)(u32)(edi + 12)));  // @61_616150
  _mm_store_ss((float *)(u32)(esi + 36), x0);  // @62_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @63_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @64_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @65_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @66_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @67_616150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @68_616150
  eax = (u32)(2863311531);  // @69_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @70_616150
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @71_616150
  eax = (u32)(2863311531);  // @72_616150
  edx = (edx >> (u32)(1));  // @73_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @74_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; });  // @75_616150
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @76_616150
  eax = (u32)(2863311531);  // @77_616150
  edx = (edx >> (u32)(1));  // @78_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 53), &v, sizeof v); }  // @79_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 18), sizeof v); (u32)v; });  // @80_616150
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @81_616150
  eax = (u32)(2863311531);  // @82_616150
  edx = (edx >> (u32)(1));  // @83_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 54), &v, sizeof v); }  // @84_616150
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 19), sizeof v); (u32)v; });  // @85_616150
  edi = (edi + (u32)(52));  // @86_616150
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @87_616150
  edx = (edx >> (u32)(1));  // @88_616150
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 55), &v, sizeof v); }  // @89_616150
  esi = (esi + (u32)(64));  // @90_616150
  ebx = (ebx - (u32)(1));  // @91_616150
  if (ebx != 0) goto L616200;  // @92_616150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @93_616150
  SEH_LEAVE();  // @94_616150
  __asm__ volatile("" :: "Yz"(x0));  // @95_616150
  return eax;  // @96_616150
  L6162d1:;
  eax = ebx;  // @98_616150
  SEH_LEAVE();  // @99_616150
  __asm__ volatile("" :: "Yz"(x0));  // @100_616150
  return eax;  // @101_616150
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

