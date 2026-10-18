// batch200137.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4dac50_fastcall2(u32, u32) __asm__("ext_4dac50");
extern "C" u32 FASTCALL ext_4db070_fastcall4(u32, u32, u32, u32) __asm__("ext_4db070");
extern "C" u32 FASTCALL ext_4dba00_fastcall3(u32, u32, u32) __asm__("ext_4dba00");
extern "C" u32 STDCALL ext_5618b0_stdcall2(u32, u32) __asm__("ext_5618b0");
extern "C" u32 STDCALL ext_565190_stdcall4(u32, u32, u32, u32) __asm__("ext_565190");
extern "C" u32 THISCALL ext_4dafb0_thiscall1(u32) __asm__("ext_4dafb0");
extern "C" u32 THISCALL ext_4db1f0_thiscall2(u32, u32) __asm__("ext_4db1f0");
extern "C" u32 THISCALL ext_4db270_thiscall2(u32, u32) __asm__("ext_4db270");
extern "C" u32 THISCALL ext_4db2f0_thiscall2(u32, u32) __asm__("ext_4db2f0");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_4db600_thiscall3(u32, u32, u32) __asm__("ext_4db600");
extern "C" u32 THISCALL ext_4db670_thiscall2(u32, u32) __asm__("ext_4db670");
extern "C" u32 THISCALL ext_4db780_thiscall2(u32, u32) __asm__("ext_4db780");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_563710_thiscall3(u32, u32, u32) __asm__("ext_563710");
extern "C" u32 THISCALL ext_565240_thiscall4(u32, u32, u32, u32) __asm__("ext_565240");
extern "C" u32 THISCALL ext_565760_thiscall2(u32, u32) __asm__("ext_565760");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 ext_42ab62_cdecl1(...) __asm__("ext_42ab62");
extern "C" u32 ext_42abee_cdecl3(...) __asm__("ext_42abee");
extern "C" u32 ext_5fa630_cdecl0(void) __asm__("ext_5fa630");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_601c80(u32 a0, u32 a1, u32 a2) {
  u8 F[0x1220] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x1120);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x1120 + 8, &a0, 4);
  __builtin_memcpy(F + 0x1120 + 12, &a1, 4);
  __builtin_memcpy(F + 0x1120 + 16, &a2, 4);
  eax = (u32)(4100);  // @0_601c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @1_601c80
  eax = (eax ^ EBP);  // @2_601c80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_601c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_601c80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }) == (u32)(0)) goto L601cd6;  // @5_601c80
  eax = (u32)(EBP + 16);  // @6_601c80
  p0_ = eax;  // @7_601c80
  eax = (u32)(EBP - 4100);  // @8_601c80
  p1_ = eax;  // @9_601c80
  eax = ext_42abee_cdecl3((u32)(p1_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p0_));  // @10_601c80
  ecx = edx = 0;  // @11_601c80
  eax = (u32)(EBP - 4100);  // @12_601c80
  p2_ = eax;  // @13_601c80
  eax = ext_42ab62_cdecl1((u32)(p2_));  // @14_601c80
  ecx = edx = 0;  // @15_601c80
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x6763b4))();  // @16_601c80
  ecx = edx = 0;  // @17_601c80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @18_601c80
  ecx = (ecx ^ EBP);  // @19_601c80
  eax = ext_633654_thiscall1(ecx);  // @20_601c80
  ecx = edx = 0;  // @21_601c80
  return eax;  // @22_601c80
  L601cd6:;
  eax = ext_5fa630_cdecl0();  // @24_601c80
  ecx = edx = 0;  // @25_601c80
  edx = (u32)(EBP + 16);  // @26_601c80
  p3_ = edx;  // @27_601c80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_601c80
  edx = (u32)(EBP - 4100);  // @29_601c80
  p4_ = edx;  // @30_601c80
  p5_ = eax;  // @31_601c80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 16)))(ecx, (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p3_));  // @32_601c80
  ecx = edx = 0;  // @33_601c80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @34_601c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_601c80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051316), (u32)(146));  // @36_601c80
  ecx = edx = 0;  // @37_601c80
  edx = (u32)(EBP - 4100);  // @38_601c80
  p6_ = edx;  // @39_601c80
  p7_ = eax;  // @40_601c80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_601c80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p7_), (u32)(p6_));  // @42_601c80
  ecx = edx = 0;  // @43_601c80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @44_601c80
  ecx = (ecx ^ EBP);  // @45_601c80
  eax = ext_633654_thiscall1(ecx);  // @46_601c80
  ecx = edx = 0;  // @47_601c80
  return eax;  // @48_601c80
}
PCREG(601c80, lifted_601c80);

extern "C" u32 lifted_425d30(u32 a0, u32 a1, u32 a2) {
  u8 F[0x2250] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x2150);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x2150 + 8, &a0, 4);
  __builtin_memcpy(F + 0x2150 + 12, &a1, 4);
  __builtin_memcpy(F + 0x2150 + 16, &a2, 4);
  eax = (u32)(8212);  // @0_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @1_425d30
  eax = (eax ^ EBP);  // @2_425d30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_425d30
  __builtin_memcpy((void *)(u32)(EBP - 8216), &SENT_ESI, 4);  // @4_425d30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_425d30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L425f55;  // @6_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @7_425d30
  if ((eax & eax) == 0) goto L425d90;  // @8_425d30
  eax = (eax - 1);  // @9_425d30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 19), &v, sizeof v); }  // @10_425d30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @11_425d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_425d30
  if ((ecx & ecx) == 0) goto L425d90;  // @13_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_425d30
  edx = (u32)(EBP - 8212);  // @15_425d30
  p0_ = edx;  // @16_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @17_425d30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6784780), (u32)(p0_));  // @18_425d30
  ecx = edx = 0;  // @19_425d30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L425d90;  // @20_425d30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 19), &v, sizeof v); }  // @21_425d30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @22_425d30
  L425d90:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; }) != (u32)(0)) goto L425d90;  // @24_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_425d30
  ecx = (u32)(EBP - 8196);  // @26_425d30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @27_425d30
  p1_ = ecx;  // @28_425d30
  p2_ = esi;  // @29_425d30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(p2_), (u32)(p1_), (u32)(6784796), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }));  // @30_425d30
  ecx = edx = 0;  // @31_425d30
  ecx = (u32)(EBP - 8196);  // @32_425d30
  edx = (u32)(ecx + 1);  // @33_425d30
  L425dc0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @35_425d30
  ecx = (ecx + 1);  // @36_425d30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L425dc0;  // @37_425d30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @38_425d30
  ecx = (ecx - edx);  // @39_425d30
  edx = edi;  // @40_425d30
  ebx = (u32)(edx + 1);  // @41_425d30
  L425dd3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @43_425d30
  edx = (edx + 1);  // @44_425d30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L425dd3;  // @45_425d30
  edx = (edx - ebx);  // @46_425d30
  ebx = (u32)(EBP - 8196);  // @47_425d30
  ebx = (ebx + ecx);  // @48_425d30
  eax = (u32)(edx + ecx);  // @49_425d30
  if (eax >= (u32)(8192)) goto L425dfd;  // @50_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_425d30
  ecx = (u32)(EBP + 16);  // @52_425d30
  p3_ = ecx;  // @53_425d30
  p4_ = edi;  // @54_425d30
  p5_ = ebx;  // @55_425d30
  ecx = esi;  // @56_425d30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p5_), (u32)(p4_), (u32)(p3_));  // @57_425d30
  ecx = edx = 0;  // @58_425d30
  goto L425e19;  // @59_425d30
  L425dfd:;
  x0 = _mm_loadu_ps((const float *)(u32)(6784804));  // @61_425d30
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784820), sizeof v); (u32)v; })) & 0xffff);  // @62_425d30
  _mm_storeu_ps((float *)(u32)(ebx), x0);  // @63_425d30
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 16), &v, sizeof v); }  // @64_425d30
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6784822), sizeof v); (u32)v; })) & 0xff);  // @65_425d30
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 18), &v, sizeof v); }  // @66_425d30
  L425e19:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) != (u32)(40)) goto L425e3d;  // @68_425d30
  edx = (u32)(EBP - 8196);  // @69_425d30
  ecx = ebx;  // @70_425d30
  edx = (edx - ebx);  // @71_425d30
  L425e30:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @73_425d30
  ecx = (u32)(ecx + 1);  // @74_425d30
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @75_425d30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L425e30;  // @76_425d30
  L425e3d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8196), sizeof v); (u32)v; }) != (u32)(0)) goto L425e5c;  // @78_425d30
  edi = (u32)(EBP - 8196);  // @79_425d30
  edi = (edi - 1);  // @80_425d30
  L425e50:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @82_425d30
  edi = (u32)(edi + 1);  // @83_425d30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L425e50;  // @84_425d30
  goto L425e8a;  // @85_425d30
  L425e5c:;
  ecx = (u32)(EBP - 8196);  // @87_425d30
  edx = (u32)(ecx + 1);  // @88_425d30
  L425e65:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @90_425d30
  ecx = (ecx + 1);  // @91_425d30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L425e65;  // @92_425d30
  ecx = (ecx - edx);  // @93_425d30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ecx - 8197), sizeof v); (u32)v; }) == (u32)(10)) goto L425e93;  // @94_425d30
  edi = (u32)(EBP - 8196);  // @95_425d30
  edi = (edi - 1);  // @96_425d30
  L425e80:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @98_425d30
  edi = (u32)(edi + 1);  // @99_425d30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L425e80;  // @100_425d30
  L425e8a:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6777860), sizeof v); (u32)v; })) & 0xffff);  // @102_425d30
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @103_425d30
  L425e93:;
  eax = (u32)(EBP - 8196);  // @105_425d30
  p6_ = eax;  // @106_425d30
  eax = ext_42ab62_cdecl1((u32)(p6_));  // @107_425d30
  ecx = edx = 0;  // @108_425d30
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763c8))((u32)(1));  // @109_425d30
  ecx = edx = 0;  // @110_425d30
  p7_ = eax;  // @111_425d30
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6763c4))((u32)(p7_));  // @112_425d30
  ecx = edx = 0;  // @113_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @114_425d30
  if ((eax & eax) == 0) goto L425ef4;  // @115_425d30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 77), sizeof v); (u32)v; }) == (u32)(0)) goto L425ef4;  // @116_425d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @117_425d30
  if ((ecx & ecx) == 0) goto L425ef4;  // @118_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_425d30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 432)))(ecx);  // @120_425d30
  ecx = edx = 0;  // @121_425d30
  if ((eax & eax) == 0) goto L425ef4;  // @122_425d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @123_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_425d30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 432)))(ecx);  // @125_425d30
  ecx = edx = 0;  // @126_425d30
  edx = (u32)(EBP - 8196);  // @127_425d30
  p8_ = edx;  // @128_425d30
  p9_ = eax;  // @129_425d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @130_425d30
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 4)))((u32)(p9_), (u32)(p8_));  // @131_425d30
  ecx = edx = 0;  // @132_425d30
  L425ef4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @134_425d30
  if ((edx & edx) == 0) goto L425f42;  // @135_425d30
  ecx = (u32)(EBP - 8196);  // @136_425d30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8208), &v, sizeof v); }  // @137_425d30
  edi = (u32)(ecx + 1);  // @138_425d30
  L425f10:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @140_425d30
  ecx = (ecx + 1);  // @141_425d30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L425f10;  // @142_425d30
  ecx = (ecx - edi);  // @143_425d30
  eax = (u32)(ecx + 1);  // @144_425d30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8204), &v, sizeof v); }  // @145_425d30
  eax = (u32)(EBP - 8196);  // @146_425d30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8200), &v, sizeof v); }  // @147_425d30
  eax = (u32)(EBP - 8208);  // @148_425d30
  p10_ = eax;  // @149_425d30
  p11_ = edx;  // @150_425d30
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x67621c))((u32)(p11_), (u32)(74), (u32)(0), (u32)(p10_));  // @151_425d30
  ecx = edx = 0;  // @152_425d30
  goto L425f4f;  // @153_425d30
  L425f42:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 19), sizeof v); (u32)v; }) == (u32)(0)) goto L425f4f;  // @155_425d30
  p12_ = ebx;  // @156_425d30
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676098))((u32)(p12_));  // @157_425d30
  ecx = edx = 0;  // @158_425d30
  L425f4f:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @160_425d30
  L425f55:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @162_425d30
  ecx = (ecx ^ EBP);  // @163_425d30
  eax = ext_633654_thiscall1(ecx);  // @164_425d30
  ecx = edx = 0;  // @165_425d30
  __asm__ volatile("" :: "Yz"(x0));  // @166_425d30
  return eax;  // @167_425d30
}
PCREG(425d30, lifted_425d30);

extern "C" u32 STDCALL lifted_657590(u32 a0, u32 a1) {
  u8 F[0x13ac0] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x139c0);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x139c0 + 8, &a0, 4);
  __builtin_memcpy(F + 0x139c0 + 12, &a1, 4);
  eax = (u32)(80024);  // @0_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @1_657590
  eax = (eax ^ EBP);  // @2_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_657590
  __builtin_memcpy((void *)(u32)(EBP - 80028), &SENT_EBX, 4);  // @4_657590
  __builtin_memcpy((void *)(u32)(EBP - 80032), &SENT_ESI, 4);  // @5_657590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_657590
  ebx = ecx;  // @7_657590
  __builtin_memcpy((void *)(u32)(EBP - 80036), &SENT_EDI, 4);  // @8_657590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_657590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80024), &v, sizeof v); }  // @10_657590
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; }) != (u32)(0)) goto L657800;  // @11_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @12_657590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }));  // @13_657590
  ecx = edx = 0;  // @14_657590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @15_657590
  edi = eax;  // @16_657590
  ecx = ebx;  // @17_657590
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_657590
  edi = (edi + (u32)(2));  // @19_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80020), &v, sizeof v); }  // @20_657590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }));  // @21_657590
  ecx = edx = 0;  // @22_657590
  edx = eax;  // @23_657590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 80008), &v, sizeof v); }  // @24_657590
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80020), sizeof v); (u32)v; }) <= (u32)(0)) goto L657800;  // @25_657590
  L657600:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @27_657590
  esi = (u32)(1);  // @28_657590
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_657590
  edi = (edi + (u32)(4));  // @30_657590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80016), &v, sizeof v); }  // @31_657590
  eax = (u32)(eax + eax*8);  // @32_657590
  x0 = _mm_load_ss((const float *)(u32)(edx + eax*4));  // @33_657590
  _mm_store_ss((float *)(u32)(EBP - 80004), x0);  // @34_657590
  x0 = _mm_load_ss((const float *)(u32)(edx + eax*4 + 4));  // @35_657590
  _mm_store_ss((float *)(u32)(EBP - 80000), x0);  // @36_657590
  x0 = _mm_load_ss((const float *)(u32)(edx + eax*4 + 8));  // @37_657590
  _mm_store_ss((float *)(u32)(EBP - 79996), x0);  // @38_657590
  if (ecx <= esi) goto L6577ed;  // @39_657590
  ebx = (u32)(ecx - 1);  // @40_657590
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 80012), &v, sizeof v); }  // @41_657590
  L657652:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @43_657590
  ecx = esi;  // @44_657590
  ecx = (ecx + ecx);  // @45_657590
  edi = (edi + (u32)(2));  // @46_657590
  esi = (esi + 1);  // @47_657590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80016), &v, sizeof v); }  // @48_657590
  edx = (u32)(eax + eax*8);  // @49_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80008), sizeof v); (u32)v; });  // @50_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @51_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + ecx*8 - 80004), &v, sizeof v); }  // @52_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80008), sizeof v); (u32)v; });  // @53_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4 + 4), sizeof v); (u32)v; });  // @54_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + ecx*8 - 80000), &v, sizeof v); }  // @55_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80008), sizeof v); (u32)v; });  // @56_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4 + 8), sizeof v); (u32)v; });  // @57_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + ecx*8 - 79996), &v, sizeof v); }  // @58_657590
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @59_657590
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi - 2), sizeof v); (u32)v; })) goto L657741;  // @60_657590
  if (esi <= (u32)(2)) goto L65773f;  // @61_657590
  edi = (u32)(esi - 2);  // @62_657590
  ebx = 0;  // @63_657590
  if ((edi & edi) == 0) goto L657733;  // @64_657590
  esi = (u32)(EBP - 79980);  // @65_657590
  L6576c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80024), sizeof v); (u32)v; });  // @67_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_657590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @69_657590
  ecx = edx = 0;  // @70_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 24), sizeof v); (u32)v; });  // @71_657590
  edx = eax;  // @72_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 8), sizeof v); (u32)v; });  // @73_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @74_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 20), sizeof v); (u32)v; });  // @75_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @76_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 16), sizeof v); (u32)v; });  // @77_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @78_657590
  if (((ebx & 0xff) & (u32)(1)) == 0) goto L65770c;  // @79_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @80_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @81_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @82_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @83_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @84_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @85_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @86_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @87_657590
  esi = (esi + (u32)(16));  // @88_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @89_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @91_657590
  goto L65772e;  // @92_657590
  L65770c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @94_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @95_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @96_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @98_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @99_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @100_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @101_657590
  esi = (esi + (u32)(16));  // @102_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @103_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @105_657590
  L65772e:;
  ebx = (ebx + 1);  // @107_657590
  if (ebx != edi) goto L6576c0;  // @108_657590
  L657733:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80016), sizeof v); (u32)v; });  // @110_657590
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80012), sizeof v); (u32)v; });  // @111_657590
  L65773f:;
  esi = 0;  // @113_657590
  L657741:;
  ebx = (ebx - (u32)(1));  // @115_657590
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 80012), &v, sizeof v); }  // @116_657590
  if (ebx != 0) goto L657652;  // @117_657590
  if (esi <= (u32)(2)) goto L6577e7;  // @118_657590
  eax = (u32)(esi - 2);  // @119_657590
  ebx = 0;  // @120_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80012), &v, sizeof v); }  // @121_657590
  if ((eax & eax) == 0) goto L6577e7;  // @122_657590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80024), sizeof v); (u32)v; });  // @123_657590
  esi = (u32)(EBP - 79980);  // @124_657590
  L657774:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @126_657590
  ecx = edi;  // @127_657590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @128_657590
  ecx = edx = 0;  // @129_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 24), sizeof v); (u32)v; });  // @130_657590
  edx = eax;  // @131_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 8), sizeof v); (u32)v; });  // @132_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @133_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 20), sizeof v); (u32)v; });  // @134_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @135_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 16), sizeof v); (u32)v; });  // @136_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @137_657590
  if (((ebx & 0xff) & (u32)(1)) == 0) goto L6577bc;  // @138_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @139_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @140_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @141_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @143_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @144_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @145_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @146_657590
  esi = (esi + (u32)(16));  // @147_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @148_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @149_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @150_657590
  goto L6577de;  // @151_657590
  L6577bc:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @153_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @154_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @155_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @157_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @158_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @159_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @160_657590
  esi = (esi + (u32)(16));  // @161_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @162_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @163_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @164_657590
  L6577de:;
  ebx = (ebx + 1);  // @166_657590
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80012), sizeof v); (u32)v; })) goto L657774;  // @167_657590
  L6577e7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80008), sizeof v); (u32)v; });  // @169_657590
  L6577ed:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80020), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 80020), &v, sizeof v); }  // @171_657590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80016), sizeof v); (u32)v; });  // @172_657590
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80020), sizeof v); (u32)v; }) != 0) goto L657600;  // @173_657590
  L657800:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @175_657590
  ecx = (ecx ^ EBP);  // @176_657590
  eax = ext_633654_thiscall1(ecx);  // @177_657590
  ecx = edx = 0;  // @178_657590
  __asm__ volatile("" :: "Yz"(x0));  // @179_657590
  return eax;  // @180_657590
}
PCREG(657590, lifted_657590);

extern "C" u32 lifted_4dd0c0(void) {
  u8 F[0x14d0] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x13d0);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(4680);  // @0_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @1_4dd0c0
  eax = (eax ^ EBP);  // @2_4dd0c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4dd0c0
  __builtin_memcpy((void *)(u32)(EBP - 4684), &SENT_EBX, 4);  // @5_4dd0c0
  ebx = ecx;  // @6_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23861), sizeof v); (u32)v; });  // @8_4dd0c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4676), &v, sizeof v); }  // @9_4dd0c0
  if ((ecx & ecx) != 0) goto L4dd112;  // @10_4dd0c0
  L4dd0f5:;
  ecx = ebx;  // @12_4dd0c0
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(33554432));  // @13_4dd0c0
  ecx = edx = 0;  // @14_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @15_4dd0c0
  ecx = (ecx ^ EBP);  // @16_4dd0c0
  eax = ext_633654_thiscall1(ecx);  // @17_4dd0c0
  ecx = edx = 0;  // @18_4dd0c0
  return eax;  // @19_4dd0c0
  L4dd112:;
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 60), sizeof v); (u32)v; }) & (u32)(2097152)) != 0) goto L4dd0f5;  // @21_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4dd0c0
  edx = (u32)(EBP - 4680);  // @23_4dd0c0
  p0_ = edx;  // @24_4dd0c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p0_));  // @25_4dd0c0
  ecx = edx = 0;  // @26_4dd0c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4668), &v, sizeof v); }  // @27_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 60), sizeof v); (u32)v; });  // @28_4dd0c0
  if ((eax & (u32)(1074003968)) == 0) goto L4dd18a;  // @29_4dd0c0
  if ((eax & (u32)(1073741824)) == 0) goto L4dd149;  // @30_4dd0c0
  ecx = ebx;  // @31_4dd0c0
  eax = ext_4dafb0_thiscall1(ecx);  // @32_4dd0c0
  ecx = edx = 0;  // @33_4dd0c0
  goto L4dd14b;  // @34_4dd0c0
  L4dd149:;
  eax = ebx;  // @36_4dd0c0
  L4dd14b:;
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @38_4dd0c0
  if (((edx & 0xffff) & (edx & 0xffff)) == 0) goto L4dd177;  // @39_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4dd0c0
  p1_ = edx;  // @41_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @42_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @43_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_4dd0c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @45_4dd0c0
  ecx = edx = 0;  // @46_4dd0c0
  if ((eax & eax) == 0) goto L4dd177;  // @47_4dd0c0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; })) & 0xff);  // @48_4dd0c0
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L4dd177;  // @49_4dd0c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @50_4dd0c0
  goto L4dd199;  // @51_4dd0c0
  L4dd177:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @54_4dd0c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @55_4dd0c0
  goto L4dd199;  // @56_4dd0c0
  L4dd18a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @58_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @59_4dd0c0
  eax = ext_4db2f0_thiscall2(ecx, (u32)(0));  // @60_4dd0c0
  ecx = edx = 0;  // @61_4dd0c0
  edi = eax;  // @62_4dd0c0
  L4dd199:;
  ecx = (u32)(EBP - 52);  // @64_4dd0c0
  eax = ext_4de7a0_thiscall1(ecx);  // @65_4dd0c0
  ecx = edx = 0;  // @66_4dd0c0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 48));  // @67_4dd0c0
  eax = (u32)(EBP - 16);  // @68_4dd0c0
  _mm_store_ss((float *)(u32)(EBP - 16), x0);  // @69_4dd0c0
  ecx = ebx;  // @70_4dd0c0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 52));  // @71_4dd0c0
  p2_ = eax;  // @72_4dd0c0
  _mm_store_ss((float *)(u32)(EBP - 12), x0);  // @73_4dd0c0
  eax = (u32)(EBP - 52);  // @74_4dd0c0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 56));  // @75_4dd0c0
  p3_ = eax;  // @76_4dd0c0
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @77_4dd0c0
  eax = ext_4db600_thiscall3(ecx, (u32)(p3_), (u32)(p2_));  // @78_4dd0c0
  ecx = edx = 0;  // @79_4dd0c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @80_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @81_4dd0c0
  if ((ecx & ecx) == 0) goto L4dd244;  // @82_4dd0c0
  eax = (u32)(EBP - 16);  // @83_4dd0c0
  p4_ = eax;  // @84_4dd0c0
  eax = ext_4db1f0_thiscall2(ecx, (u32)(p4_));  // @85_4dd0c0
  ecx = edx = 0;  // @86_4dd0c0
  edx = (u32)(esi + 36);  // @87_4dd0c0
  ecx = (u32)(EBP - 16);  // @88_4dd0c0
  eax = ext_43e960_fastcall2(ecx, edx);  // @89_4dd0c0
  ecx = edx = 0;  // @90_4dd0c0
  edx = esi;  // @91_4dd0c0
  ecx = (u32)(EBP - 16);  // @92_4dd0c0
  eax = ext_441a60_fastcall2(ecx, edx);  // @93_4dd0c0
  ecx = edx = 0;  // @94_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @95_4dd0c0
  if ((ecx & ecx) == 0) goto L4dd210;  // @96_4dd0c0
  eax = (u32)(EBP - 28);  // @97_4dd0c0
  p5_ = eax;  // @98_4dd0c0
  eax = ext_4db270_thiscall2(ecx, (u32)(p5_));  // @99_4dd0c0
  ecx = edx = 0;  // @100_4dd0c0
  edx = esi;  // @101_4dd0c0
  ecx = (u32)(EBP - 28);  // @102_4dd0c0
  eax = ext_441a60_fastcall2(ecx, edx);  // @103_4dd0c0
  ecx = edx = 0;  // @104_4dd0c0
  L4dd210:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @106_4dd0c0
  if ((ecx & ecx) == 0) goto L4dd22a;  // @107_4dd0c0
  eax = (u32)(EBP - 40);  // @108_4dd0c0
  p6_ = eax;  // @109_4dd0c0
  eax = ext_4db270_thiscall2(ecx, (u32)(p6_));  // @110_4dd0c0
  ecx = edx = 0;  // @111_4dd0c0
  edx = esi;  // @112_4dd0c0
  ecx = (u32)(EBP - 40);  // @113_4dd0c0
  eax = ext_441a60_fastcall2(ecx, edx);  // @114_4dd0c0
  ecx = edx = 0;  // @115_4dd0c0
  L4dd22a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @117_4dd0c0
  if ((ecx & ecx) == 0) goto L4dd244;  // @118_4dd0c0
  eax = (u32)(EBP - 52);  // @119_4dd0c0
  p7_ = eax;  // @120_4dd0c0
  eax = ext_4db270_thiscall2(ecx, (u32)(p7_));  // @121_4dd0c0
  ecx = edx = 0;  // @122_4dd0c0
  edx = esi;  // @123_4dd0c0
  ecx = (u32)(EBP - 52);  // @124_4dd0c0
  eax = ext_441a60_fastcall2(ecx, edx);  // @125_4dd0c0
  ecx = edx = 0;  // @126_4dd0c0
  L4dd244:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @128_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @129_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @130_4dd0c0
  eax = (u32)(ebx + 64);  // @131_4dd0c0
  p8_ = eax;  // @132_4dd0c0
  eax = (u32)(EBP - 16);  // @133_4dd0c0
  p9_ = eax;  // @134_4dd0c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_4dd0c0
  eax = (u32)(EBP - 52);  // @136_4dd0c0
  p10_ = eax;  // @137_4dd0c0
  p11_ = edi;  // @138_4dd0c0
  eax = (u32)(EBP - 564);  // @139_4dd0c0
  p12_ = eax;  // @140_4dd0c0
  eax = (u32)(EBP - 4660);  // @141_4dd0c0
  p13_ = eax;  // @142_4dd0c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 60)))(ecx, (u32)(p13_), (u32)(p12_), (u32)(p11_), (u32)(1), (u32)(p10_), (u32)(p9_), (u32)(p8_), (u32)(-1), (u32)(1), (u32)(1), (u32)(1));  // @143_4dd0c0
  ecx = edx = 0;  // @144_4dd0c0
  edx = eax;  // @145_4dd0c0
  esi = 0;  // @146_4dd0c0
  edi = 0;  // @147_4dd0c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4664), &v, sizeof v); }  // @148_4dd0c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4672), &v, sizeof v); }  // @149_4dd0c0
  if ((edx & edx) == 0) goto L4dd39c;  // @150_4dd0c0
  L4dd2a0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 4660), sizeof v); (u32)v; });  // @152_4dd0c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @153_4dd0c0
  if ((edx & (u32)(1024)) != 0) goto L4dd340;  // @154_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @155_4dd0c0
  if ((ecx & ecx) == 0) goto L4dd2cc;  // @156_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @157_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @158_4dd0c0
  if (eax == (u32)(8388621)) goto L4dd33a;  // @159_4dd0c0
  goto L4dd2d1;  // @160_4dd0c0
  L4dd2cc:;
  eax = (u32)(2097154);  // @162_4dd0c0
  L4dd2d1:;
  if ((eax & (u32)(8388608)) == 0) goto L4dd30b;  // @164_4dd0c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; }) == (u32)(0)) goto L4dd33a;  // @165_4dd0c0
  edx = (u32)(EBP - 564);  // @166_4dd0c0
  ecx = esi;  // @167_4dd0c0
  eax = ext_4dac50_fastcall2(ecx, edx);  // @168_4dd0c0
  ecx = edx = 0;  // @169_4dd0c0
  ecx = (u32)(EBP - 564);  // @170_4dd0c0
  edx = eax;  // @171_4dd0c0
  p14_ = ecx;  // @172_4dd0c0
  ecx = ebx;  // @173_4dd0c0
  eax = ext_4dba00_fastcall3(ecx, edx, (u32)(p14_));  // @174_4dd0c0
  ecx = edx = 0;  // @175_4dd0c0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4dd33a;  // @176_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4668), sizeof v); (u32)v; });  // @177_4dd0c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + edi*4), &v, sizeof v); }  // @178_4dd0c0
  edi = (edi + 1);  // @179_4dd0c0
  goto L4dd33a;  // @180_4dd0c0
  L4dd30b:;
  if ((edx & (u32)(262144)) == 0) goto L4dd33a;  // @182_4dd0c0
  if ((eax & (u32)(1048576)) == 0) goto L4dd33a;  // @183_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @184_4dd0c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 680)))(ecx);  // @185_4dd0c0
  ecx = edx = 0;  // @186_4dd0c0
  if ((eax & (u32)(65536)) == 0) goto L4dd33a;  // @187_4dd0c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4668), sizeof v); (u32)v; });  // @188_4dd0c0
  ecx = edi;  // @189_4dd0c0
  p15_ = esi;  // @190_4dd0c0
  p16_ = ebx;  // @191_4dd0c0
  eax = ext_4db070_fastcall4(ecx, edx, (u32)(p16_), (u32)(p15_));  // @192_4dd0c0
  ecx = edx = 0;  // @193_4dd0c0
  edi = eax;  // @194_4dd0c0
  L4dd33a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4664), sizeof v); (u32)v; });  // @196_4dd0c0
  L4dd340:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4672), sizeof v); (u32)v; });  // @198_4dd0c0
  esi = (esi + 1);  // @199_4dd0c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4672), &v, sizeof v); }  // @200_4dd0c0
  if (esi < eax) goto L4dd2a0;  // @201_4dd0c0
  if (edi <= (u32)(12)) goto L4dd39c;  // @202_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @203_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @204_4dd0c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909476), (u32)(3341));  // @205_4dd0c0
  ecx = edx = 0;  // @206_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @207_4dd0c0
  esi = eax;  // @208_4dd0c0
  edx = (u32)(6801640);  // @209_4dd0c0
  if ((ecx & ecx) == 0) goto L4dd385;  // @210_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @211_4dd0c0
  if ((ecx & ecx) != 0) edx = ecx;  // @212_4dd0c0
  L4dd385:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @214_4dd0c0
  p17_ = edi;  // @215_4dd0c0
  p18_ = edx;  // @216_4dd0c0
  p19_ = esi;  // @217_4dd0c0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 48)))((u32)(p19_), (u32)(6910032), (u32)(p18_), (u32)(p17_), (u32)(12));  // @218_4dd0c0
  ecx = edx = 0;  // @219_4dd0c0
  edi = (u32)(12);  // @220_4dd0c0
  L4dd39c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4676), sizeof v); (u32)v; });  // @222_4dd0c0
  p20_ = ebx;  // @223_4dd0c0
  p21_ = edi;  // @224_4dd0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @225_4dd0c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(p21_), (u32)(p20_));  // @226_4dd0c0
  ecx = edx = 0;  // @227_4dd0c0
  ecx = ebx;  // @228_4dd0c0
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(33554432));  // @229_4dd0c0
  ecx = edx = 0;  // @230_4dd0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @231_4dd0c0
  ecx = (ecx ^ EBP);  // @232_4dd0c0
  eax = ext_633654_thiscall1(ecx);  // @233_4dd0c0
  ecx = edx = 0;  // @234_4dd0c0
  __asm__ volatile("" :: "Yz"(x0));  // @235_4dd0c0
  return eax;  // @236_4dd0c0
}
PCREG(4dd0c0, lifted_4dd0c0);

extern "C" u32 STDCALL lifted_565360(u32 a0) {
  u8 F[0x12e0] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x11e0);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x11e0 + 8, &a0, 4);
  eax = (u32)(4148);  // @0_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @1_565360
  eax = (eax ^ EBP);  // @2_565360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_565360
  __builtin_memcpy((void *)(u32)(EBP - 4152), &SENT_EBX, 4);  // @4_565360
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_565360
  eax = (u32)(EBP - 1028);  // @6_565360
  __builtin_memcpy((void *)(u32)(EBP - 4156), &SENT_EDI, 4);  // @7_565360
  edi = ecx;  // @8_565360
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4128), &v, sizeof v); }  // @9_565360
  p0_ = eax;  // @10_565360
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4144), &v, sizeof v); }  // @11_565360
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(1024));  // @12_565360
  ecx = edx = 0;  // @13_565360
  eax = (u32)(EBP - 2052);  // @14_565360
  p1_ = eax;  // @15_565360
  eax = ext_634d10_cdecl3((u32)(p1_), (u32)(0), (u32)(1024));  // @16_565360
  ecx = edx = 0;  // @17_565360
  eax = (u32)(EBP - 4100);  // @18_565360
  p2_ = eax;  // @19_565360
  eax = ext_634d10_cdecl3((u32)(p2_), (u32)(0), (u32)(2048));  // @20_565360
  ecx = edx = 0;  // @21_565360
  eax = (u32)(EBP - 1028);  // @22_565360
  ecx = edi;  // @23_565360
  p3_ = eax;  // @24_565360
  eax = ext_565190_stdcall4((u32)(p3_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }));  // @25_565360
  ecx = edx = 0;  // @26_565360
  eax = (u32)(EBP - 2052);  // @27_565360
  ecx = edi;  // @28_565360
  p4_ = eax;  // @29_565360
  eax = ext_565190_stdcall4((u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }));  // @30_565360
  ecx = edx = 0;  // @31_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_565360
  ecx = edi;  // @33_565360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, (u32)(1));  // @34_565360
  ecx = edx = 0;  // @35_565360
  ecx = (u32)(EBP - 1028);  // @36_565360
  edx = (u32)(ecx + 1);  // @37_565360
  L565408:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @39_565360
  ecx = (ecx + 1);  // @40_565360
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L565408;  // @41_565360
  ecx = (ecx - edx);  // @42_565360
  if (ecx == 0) goto L56574b;  // @43_565360
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 4114), &v, sizeof v); }  // @44_565360
  ebx = (u32)(edi + 3178);  // @45_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4128), sizeof v); (u32)v; });  // @46_565360
  esi = 0;  // @47_565360
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 4132), &v, sizeof v); }  // @48_565360
  eax = (eax + (u32)(8));  // @49_565360
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4116), &v, sizeof v); }  // @50_565360
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4124), &v, sizeof v); }  // @51_565360
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4120), &v, sizeof v); }  // @52_565360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4136), &v, sizeof v); }  // @53_565360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4148), &v, sizeof v); }  // @54_565360
  L565460:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @56_565360
  if ((edx & edx) == 0) goto L565530;  // @57_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_565360
  p5_ = edx;  // @59_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @60_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @61_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_565360
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6974004), (u32)(p5_));  // @63_565360
  ecx = edx = 0;  // @64_565360
  p6_ = eax;  // @65_565360
  ecx = edi;  // @66_565360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4140), &v, sizeof v); }  // @67_565360
  eax = ext_563710_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }), (u32)(p6_));  // @68_565360
  ecx = edx = 0;  // @69_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @70_565360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_565360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(0));  // @72_565360
  ecx = edx = 0;  // @73_565360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4140), sizeof v); (u32)v; });  // @74_565360
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + esi - 4116), &v, sizeof v); }  // @75_565360
  ecx = (u32)(edx + 1);  // @76_565360
  L5654b2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @78_565360
  edx = (edx + 1);  // @79_565360
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5654b2;  // @80_565360
  edx = (edx - ecx);  // @81_565360
  esi = 0;  // @82_565360
  edi = (u32)(1);  // @83_565360
  if ((s32)(edx & edx) <= 0) goto L5654e8;  // @84_565360
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4140), sizeof v); (u32)v; });  // @85_565360
  L5654d0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx), sizeof v); (u32)v; })) & 0xff);  // @87_565360
  ecx = (u32)(edi + 1);  // @88_565360
  esi = (esi + 1);  // @89_565360
  if ((eax & 0xff) != (u32)(10)) ecx = edi;  // @90_565360
  edi = ecx;  // @91_565360
  if ((s32)esi < (s32)edx) goto L5654d0;  // @92_565360
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4120), sizeof v); (u32)v; });  // @93_565360
  L5654e8:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4124), sizeof v); (u32)v; });  // @95_565360
  if ((s32)edi <= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4132), sizeof v); (u32)v; })) goto L5654fc;  // @96_565360
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4132), &v, sizeof v); }  // @97_565360
  L5654fc:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4144), sizeof v); (u32)v; });  // @99_565360
  L565502:;
  if ((esi & esi) == 0) goto L56555a;  // @101_565360
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi - 4116), sizeof v); (u32)v; }) == (u32)(0)) goto L56555a;  // @102_565360
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi - 4117), sizeof v); (u32)v; }) == (u32)(0)) goto L56553e;  // @103_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 4), sizeof v); (u32)v; });  // @104_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_565360
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }), (u32)(2));  // @106_565360
  ecx = edx = 0;  // @107_565360
  goto L565542;  // @108_565360
  L565530:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @110_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @111_565360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 4), sizeof v); (u32)v; }), (u32)(1));  // @112_565360
  ecx = edx = 0;  // @113_565360
  goto L565502;  // @114_565360
  L56553e:;
  L565542:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @117_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_565360
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, (u32)(0), (u32)(1));  // @119_565360
  ecx = edx = 0;  // @120_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @121_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_565360
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, (u32)(0), (u32)(2));  // @123_565360
  ecx = edx = 0;  // @124_565360
  L56555a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4148), sizeof v); (u32)v; });  // @126_565360
  esi = (esi + 1);  // @127_565360
  eax = (eax + (u32)(4));  // @128_565360
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4124), &v, sizeof v); }  // @129_565360
  ebx = (ebx + (u32)(4));  // @130_565360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4148), &v, sizeof v); }  // @131_565360
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4120), &v, sizeof v); }  // @132_565360
  if ((s32)esi < (s32)(u32)(3)) goto L565460;  // @133_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3178), sizeof v); (u32)v; });  // @134_565360
  esi = (u32)(edi + 3178);  // @135_565360
  eax = (u32)(EBP - 4112);  // @136_565360
  p7_ = eax;  // @137_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @138_565360
  eax = ext_4db500_thiscall2(ecx, (u32)(p7_));  // @139_565360
  ecx = edx = 0;  // @140_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3186), sizeof v); (u32)v; });  // @141_565360
  edx = (u32)(EBP - 4112);  // @142_565360
  p8_ = edx;  // @143_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_565360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, (u32)(p8_));  // @145_565360
  ecx = edx = 0;  // @146_565360
  ebx = (u32)(3);  // @147_565360
  L5655b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @149_565360
  ecx = edi;  // @150_565360
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @151_565360
  ecx = edx = 0;  // @152_565360
  ecx = eax;  // @153_565360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @154_565360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @155_565360
  ecx = edx = 0;  // @156_565360
  esi = (u32)(esi + 4);  // @157_565360
  ebx = (ebx - (u32)(1));  // @158_565360
  if (ebx != 0) goto L5655b4;  // @159_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @160_565360
  ecx = edi;  // @161_565360
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @162_565360
  ecx = edx = 0;  // @163_565360
  ecx = eax;  // @164_565360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @165_565360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }));  // @166_565360
  ecx = edx = 0;  // @167_565360
  ecx = edi;  // @168_565360
  eax = ext_5618b0_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3178), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3182), sizeof v); (u32)v; }));  // @169_565360
  ecx = edx = 0;  // @170_565360
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4136), sizeof v); (u32)v; });  // @171_565360
  ecx = edi;  // @172_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @173_565360
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == ebx) goto L56563b;  // @174_565360
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @175_565360
  ecx = edx = 0;  // @176_565360
  ecx = eax;  // @177_565360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @178_565360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3178), sizeof v); (u32)v; }));  // @179_565360
  ecx = edx = 0;  // @180_565360
  ecx = edi;  // @181_565360
  eax = ext_5618b0_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3182), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3186), sizeof v); (u32)v; }));  // @182_565360
  ecx = edx = 0;  // @183_565360
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4128), sizeof v); (u32)v; });  // @184_565360
  goto L565668;  // @185_565360
  L56563b:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4128), sizeof v); (u32)v; });  // @187_565360
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L565655;  // @188_565360
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @189_565360
  ecx = edx = 0;  // @190_565360
  goto L56565e;  // @191_565360
  L565655:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3186), sizeof v); (u32)v; }));  // @193_565360
  ecx = edx = 0;  // @194_565360
  L56565e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @196_565360
  ecx = eax;  // @197_565360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }));  // @198_565360
  ecx = edx = 0;  // @199_565360
  L565668:;
  ecx = (u32)(EBP - 2052);  // @201_565360
  edx = (u32)(ecx + 1);  // @202_565360
  L565671:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @204_565360
  ecx = (ecx + 1);  // @205_565360
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L565671;  // @206_565360
  ecx = (ecx - edx);  // @207_565360
  if (ecx == 0) goto L5656b2;  // @208_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @209_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @210_565360
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @211_565360
  ecx = edx = 0;  // @212_565360
  edx = (u32)(EBP - 2052);  // @213_565360
  p9_ = edx;  // @214_565360
  edx = (u32)(EBP - 1028);  // @215_565360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @216_565360
  p10_ = edx;  // @217_565360
  edx = (u32)(EBP - 4100);  // @218_565360
  p11_ = edx;  // @219_565360
  p12_ = eax;  // @220_565360
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 408)))((u32)(p12_), (u32)(p11_), (u32)(6974020), (u32)(p10_), (u32)(p9_));  // @221_565360
  ecx = edx = 0;  // @222_565360
  goto L5656c9;  // @223_565360
  L5656b2:;
  ecx = 0;  // @225_565360
  L5656b4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ecx - 1028), sizeof v); (u32)v; })) & 0xff);  // @227_565360
  ecx = (u32)(ecx + 1);  // @228_565360
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + ecx - 4101), &v, sizeof v); }  // @229_565360
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5656b4;  // @230_565360
  L5656c9:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L5656e2;  // @232_565360
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L5656e2;  // @233_565360
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4120), &v, sizeof v); }  // @234_565360
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L5656e9;  // @235_565360
  L5656e2:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 4120), &v, sizeof v); }  // @237_565360
  L5656e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4132), sizeof v); (u32)v; });  // @239_565360
  ecx = edi;  // @240_565360
  p13_ = eax;  // @241_565360
  eax = (u32)(EBP - 4100);  // @242_565360
  p14_ = eax;  // @243_565360
  eax = ext_565240_thiscall4(ecx, (u32)(p14_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4120), sizeof v); (u32)v; }), (u32)(p13_));  // @244_565360
  ecx = edx = 0;  // @245_565360
  x0 = _mm_load_ss((const float *)(u32)(ebx + 36));  // @246_565360
  ecx = edi;  // @247_565360
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784556)));  // @248_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @249_565360
  edx = (u32)_mm_cvtss_si32(x0);  // @250_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @251_565360
  eax = (eax - edx);  // @252_565360
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @253_565360
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @254_565360
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(6784484)));  // @255_565360
  _mm_store_ss((float *)(u32)(edi + 3238), x0);  // @256_565360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; });  // @257_565360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 3242), &v, sizeof v); }  // @258_565360
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 40), sizeof v); (u32)v; });  // @259_565360
  p15_ = eax;  // @260_565360
  eax = ext_565760_thiscall2(ecx, (u32)(p15_));  // @261_565360
  ecx = edx = 0;  // @262_565360
  L56574b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @264_565360
  ecx = (ecx ^ EBP);  // @265_565360
  eax = ext_633654_thiscall1(ecx);  // @266_565360
  ecx = edx = 0;  // @267_565360
  __asm__ volatile("" :: "Yz"(x0));  // @268_565360
  return eax;  // @269_565360
}
PCREG(565360, lifted_565360);

extern "C" u32 lifted_4dd3d0(void) {
  u8 F[0x1520] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x1420);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(4704);  // @0_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @1_4dd3d0
  eax = (eax ^ EBP);  // @2_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4dd3d0
  __builtin_memcpy((void *)(u32)(EBP - 4708), &SENT_EBX, 4);  // @5_4dd3d0
  __builtin_memcpy((void *)(u32)(EBP - 4712), &SENT_ESI, 4);  // @6_4dd3d0
  ebx = ecx;  // @7_4dd3d0
  esi = 0;  // @8_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @9_4dd3d0
  __builtin_memcpy((void *)(u32)(EBP - 4716), &SENT_EDI, 4);  // @10_4dd3d0
  edi = 0;  // @11_4dd3d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4696), &v, sizeof v); }  // @12_4dd3d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4676), &v, sizeof v); }  // @13_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23861), sizeof v); (u32)v; });  // @14_4dd3d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4688), &v, sizeof v); }  // @15_4dd3d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4700), &v, sizeof v); }  // @16_4dd3d0
  if ((ecx & ecx) == 0) goto L4dd8a3;  // @17_4dd3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; }) != esi) goto L4dd45a;  // @18_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @19_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4dd3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909476), (u32)(3107));  // @21_4dd3d0
  ecx = edx = 0;  // @22_4dd3d0
  p0_ = eax;  // @23_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_4dd3d0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 48)))((u32)(p0_), (u32)(6909952));  // @25_4dd3d0
  ecx = edx = 0;  // @26_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @27_4dd3d0
  ecx = (ecx ^ EBP);  // @28_4dd3d0
  eax = ext_633654_thiscall1(ecx);  // @29_4dd3d0
  ecx = edx = 0;  // @30_4dd3d0
  return eax;  // @31_4dd3d0
  L4dd45a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_4dd3d0
  edx = (u32)(EBP - 4704);  // @34_4dd3d0
  p1_ = edx;  // @35_4dd3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p1_));  // @36_4dd3d0
  ecx = edx = 0;  // @37_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 60), sizeof v); (u32)v; });  // @38_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4692), &v, sizeof v); }  // @39_4dd3d0
  if ((ecx & (u32)(1074003968)) == 0) goto L4dd4ea;  // @40_4dd3d0
  if ((ecx & (u32)(1073741824)) == 0) goto L4dd488;  // @41_4dd3d0
  ecx = ebx;  // @42_4dd3d0
  eax = ext_4dafb0_thiscall1(ecx);  // @43_4dd3d0
  ecx = edx = 0;  // @44_4dd3d0
  goto L4dd48a;  // @45_4dd3d0
  L4dd488:;
  eax = ebx;  // @47_4dd3d0
  L4dd48a:;
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @49_4dd3d0
  if (((edx & 0xffff) & (edx & 0xffff)) == 0) goto L4dd4b1;  // @50_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_4dd3d0
  p2_ = edx;  // @52_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @53_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @54_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4dd3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p2_));  // @56_4dd3d0
  ecx = edx = 0;  // @57_4dd3d0
  edi = eax;  // @58_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4676), &v, sizeof v); }  // @59_4dd3d0
  goto L4dd4b9;  // @60_4dd3d0
  L4dd4b1:;
  edi = 0;  // @62_4dd3d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4676), &v, sizeof v); }  // @63_4dd3d0
  L4dd4b9:;
  if ((edi & edi) == 0) goto L4dd4cf;  // @65_4dd3d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; })) & 0xff);  // @66_4dd3d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4dd4cf;  // @67_4dd3d0
  eax = (eax & 0xff);  // @68_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4684), &v, sizeof v); }  // @69_4dd3d0
  goto L4dd507;  // @70_4dd3d0
  L4dd4cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @72_4dd3d0
  edi = 0;  // @73_4dd3d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4676), &v, sizeof v); }  // @74_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @75_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @76_4dd3d0
  goto L4dd4f7;  // @77_4dd3d0
  L4dd4ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @79_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @80_4dd3d0
  eax = ext_4db2f0_thiscall2(ecx, (u32)(0));  // @81_4dd3d0
  ecx = edx = 0;  // @82_4dd3d0
  L4dd4f7:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 4684), &v, sizeof v); }  // @84_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4668), &v, sizeof v); }  // @85_4dd3d0
  L4dd507:;
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 60), sizeof v); (u32)v; }) & (u32)(16384)) != 0) goto L4dd51d;  // @87_4dd3d0
  edx = (u32)(EBP - 564);  // @88_4dd3d0
  ecx = ebx;  // @89_4dd3d0
  eax = ext_4dac50_fastcall2(ecx, edx);  // @90_4dd3d0
  ecx = edx = 0;  // @91_4dd3d0
  L4dd51d:;
  ecx = (u32)(EBP - 52);  // @93_4dd3d0
  eax = ext_4de7a0_thiscall1(ecx);  // @94_4dd3d0
  ecx = edx = 0;  // @95_4dd3d0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 48));  // @96_4dd3d0
  eax = (u32)(EBP - 16);  // @97_4dd3d0
  _mm_store_ss((float *)(u32)(EBP - 16), x0);  // @98_4dd3d0
  ecx = ebx;  // @99_4dd3d0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 52));  // @100_4dd3d0
  p3_ = eax;  // @101_4dd3d0
  _mm_store_ss((float *)(u32)(EBP - 12), x0);  // @102_4dd3d0
  eax = (u32)(EBP - 52);  // @103_4dd3d0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 56));  // @104_4dd3d0
  p4_ = eax;  // @105_4dd3d0
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @106_4dd3d0
  eax = ext_4db600_thiscall3(ecx, (u32)(p4_), (u32)(p3_));  // @107_4dd3d0
  ecx = edx = 0;  // @108_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @110_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @111_4dd3d0
  if ((edi & edi) == 0) goto L4dd5f1;  // @112_4dd3d0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @113_4dd3d0
  eax = (u32)(ebx + 64);  // @114_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4664), &v, sizeof v); }  // @115_4dd3d0
  esi = (u32)(EBP - 16);  // @116_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_4dd3d0
  p5_ = esi;  // @118_4dd3d0
  esi = (u32)(EBP - 52);  // @119_4dd3d0
  p6_ = esi;  // @120_4dd3d0
  p7_ = edx;  // @121_4dd3d0
  p8_ = edi;  // @122_4dd3d0
  edx = (u32)(EBP - 564);  // @123_4dd3d0
  p9_ = edx;  // @124_4dd3d0
  edx = (u32)(EBP - 4660);  // @125_4dd3d0
  p10_ = edx;  // @126_4dd3d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, (u32)(p10_), (u32)(p9_), (u32)(0), (u32)(p8_), (u32)(p7_), (u32)(p6_), (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4664), sizeof v); (u32)v; }), (u32)(-1), (u32)(1));  // @127_4dd3d0
  ecx = edx = 0;  // @128_4dd3d0
  edi = eax;  // @129_4dd3d0
  ecx = 0;  // @130_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4676), sizeof v); (u32)v; });  // @131_4dd3d0
  esi = ecx;  // @132_4dd3d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4664), &v, sizeof v); }  // @133_4dd3d0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @134_4dd3d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4680), &v, sizeof v); }  // @135_4dd3d0
  if ((edx & edx) == 0) goto L4dd63d;  // @136_4dd3d0
  edi = eax;  // @137_4dd3d0
  eax = (u32)(EBP - 564);  // @138_4dd3d0
  edi = (edi - eax);  // @139_4dd3d0
  if (ecx >= edx) goto L4dd5db;  // @140_4dd3d0
  L4dd5cf:;
  eax = (u32)(edi + ecx*4);  // @142_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax - 564), sizeof v); (u32)v; });  // @143_4dd3d0
  goto L4dd5dd;  // @144_4dd3d0
  L4dd5db:;
  eax = 0;  // @146_4dd3d0
  L4dd5dd:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + ecx*4 - 564), &v, sizeof v); }  // @148_4dd3d0
  ecx = (ecx + 1);  // @149_4dd3d0
  if (ecx < edx) goto L4dd5cf;  // @150_4dd3d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4664), sizeof v); (u32)v; });  // @151_4dd3d0
  goto L4dd63d;  // @152_4dd3d0
  L4dd5f1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @154_4dd3d0
  edx = (u32)(ebx + 64);  // @155_4dd3d0
  p11_ = edx;  // @156_4dd3d0
  edx = (u32)(EBP - 16);  // @157_4dd3d0
  p12_ = edx;  // @158_4dd3d0
  edx = (u32)(EBP - 52);  // @159_4dd3d0
  p13_ = edx;  // @160_4dd3d0
  edx = (u32)(EBP - 4668);  // @161_4dd3d0
  p14_ = edx;  // @162_4dd3d0
  edx = (u32)(EBP - 564);  // @163_4dd3d0
  p15_ = edx;  // @164_4dd3d0
  edx = (u32)(EBP - 4660);  // @165_4dd3d0
  p16_ = edx;  // @166_4dd3d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, (u32)(p16_), (u32)(p15_), (u32)(0), (u32)(p14_), (u32)(1), (u32)(p13_), (u32)(p12_), (u32)(p11_));  // @167_4dd3d0
  ecx = edx = 0;  // @168_4dd3d0
  edi = eax;  // @169_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4664), &v, sizeof v); }  // @170_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4668), sizeof v); (u32)v; });  // @171_4dd3d0
  edx = (u32)(1);  // @172_4dd3d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4680), &v, sizeof v); }  // @173_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 564), &v, sizeof v); }  // @174_4dd3d0
  L4dd63d:;
  eax = 0;  // @176_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4672), &v, sizeof v); }  // @177_4dd3d0
  if ((edi & edi) == 0) goto L4dd6c7;  // @178_4dd3d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4664), sizeof v); (u32)v; });  // @179_4dd3d0
  L4dd653:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax*4 - 4660), sizeof v); (u32)v; });  // @181_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @182_4dd3d0
  if ((ecx & ecx) == 0) goto L4dd66f;  // @183_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @184_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @185_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4672), sizeof v); (u32)v; });  // @186_4dd3d0
  goto L4dd674;  // @187_4dd3d0
  L4dd66f:;
  ecx = (u32)(2097154);  // @189_4dd3d0
  L4dd674:;
  if ((ecx & (u32)(8388608)) != 0) goto L4dd6aa;  // @191_4dd3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; }) == (u32)(0)) goto L4dd6aa;  // @192_4dd3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; }) == (u32)(0)) goto L4dd6aa;  // @193_4dd3d0
  eax = (u32)(EBP - 564);  // @194_4dd3d0
  ecx = edi;  // @195_4dd3d0
  p17_ = eax;  // @196_4dd3d0
  eax = ext_4dba00_fastcall3(ecx, edx, (u32)(p17_));  // @197_4dd3d0
  ecx = edx = 0;  // @198_4dd3d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4dd6a4;  // @199_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4692), sizeof v); (u32)v; });  // @200_4dd3d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + esi*4), &v, sizeof v); }  // @201_4dd3d0
  esi = (esi + 1);  // @202_4dd3d0
  L4dd6a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4672), sizeof v); (u32)v; });  // @204_4dd3d0
  L4dd6aa:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4680), sizeof v); (u32)v; });  // @206_4dd3d0
  eax = (eax + 1);  // @207_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4672), &v, sizeof v); }  // @208_4dd3d0
  if (eax < ebx) goto L4dd653;  // @209_4dd3d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4696), sizeof v); (u32)v; });  // @210_4dd3d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4688), &v, sizeof v); }  // @211_4dd3d0
  L4dd6c7:;
  ecx = 0;  // @213_4dd3d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4664), &v, sizeof v); }  // @214_4dd3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4684), sizeof v); (u32)v; }) <= ecx) goto L4dd897;  // @215_4dd3d0
  L4dd6e0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4676), sizeof v); (u32)v; });  // @217_4dd3d0
  if ((edx & edx) == 0) goto L4dd70f;  // @218_4dd3d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @219_4dd3d0
  if (ecx >= eax) goto L4dd6f7;  // @220_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @221_4dd3d0
  goto L4dd6f9;  // @222_4dd3d0
  L4dd6f7:;
  eax = 0;  // @224_4dd3d0
  L4dd6f9:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4668), &v, sizeof v); }  // @226_4dd3d0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 4680), &v, sizeof v); }  // @227_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 564), &v, sizeof v); }  // @228_4dd3d0
  L4dd70f:;
  ecx = (u32)(EBP - 52);  // @230_4dd3d0
  eax = ext_4de7a0_thiscall1(ecx);  // @231_4dd3d0
  ecx = edx = 0;  // @232_4dd3d0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 48));  // @233_4dd3d0
  _mm_store_ss((float *)(u32)(EBP - 16), x0);  // @234_4dd3d0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 52));  // @235_4dd3d0
  _mm_store_ss((float *)(u32)(EBP - 12), x0);  // @236_4dd3d0
  x0 = _mm_load_ss((const float *)(u32)(ebx + 56));  // @237_4dd3d0
  _mm_store_ss((float *)(u32)(EBP - 8), x0);  // @238_4dd3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L4dd7ae;  // @239_4dd3d0
  edx = ebx;  // @240_4dd3d0
  ecx = (u32)(EBP - 16);  // @241_4dd3d0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @242_4dd3d0
  ecx = edx = 0;  // @243_4dd3d0
  edx = (u32)(ebx + 36);  // @244_4dd3d0
  ecx = (u32)(EBP - 16);  // @245_4dd3d0
  eax = ext_441940_fastcall2(ecx, edx);  // @246_4dd3d0
  ecx = edx = 0;  // @247_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @248_4dd3d0
  if ((ecx & ecx) == 0) goto L4dd760;  // @249_4dd3d0
  eax = (u32)(EBP - 16);  // @250_4dd3d0
  p18_ = eax;  // @251_4dd3d0
  eax = ext_4db670_thiscall2(ecx, (u32)(p18_));  // @252_4dd3d0
  ecx = edx = 0;  // @253_4dd3d0
  L4dd760:;
  edx = ebx;  // @255_4dd3d0
  ecx = (u32)(EBP - 28);  // @256_4dd3d0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @257_4dd3d0
  ecx = edx = 0;  // @258_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @259_4dd3d0
  if ((ecx & ecx) == 0) goto L4dd77a;  // @260_4dd3d0
  eax = (u32)(EBP - 28);  // @261_4dd3d0
  p19_ = eax;  // @262_4dd3d0
  eax = ext_4db780_thiscall2(ecx, (u32)(p19_));  // @263_4dd3d0
  ecx = edx = 0;  // @264_4dd3d0
  L4dd77a:;
  edx = ebx;  // @266_4dd3d0
  ecx = (u32)(EBP - 40);  // @267_4dd3d0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @268_4dd3d0
  ecx = edx = 0;  // @269_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @270_4dd3d0
  if ((ecx & ecx) == 0) goto L4dd794;  // @271_4dd3d0
  eax = (u32)(EBP - 40);  // @272_4dd3d0
  p20_ = eax;  // @273_4dd3d0
  eax = ext_4db780_thiscall2(ecx, (u32)(p20_));  // @274_4dd3d0
  ecx = edx = 0;  // @275_4dd3d0
  L4dd794:;
  edx = ebx;  // @277_4dd3d0
  ecx = (u32)(EBP - 52);  // @278_4dd3d0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @279_4dd3d0
  ecx = edx = 0;  // @280_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @281_4dd3d0
  if ((ecx & ecx) == 0) goto L4dd7ae;  // @282_4dd3d0
  eax = (u32)(EBP - 52);  // @283_4dd3d0
  p21_ = eax;  // @284_4dd3d0
  eax = ext_4db780_thiscall2(ecx, (u32)(p21_));  // @285_4dd3d0
  ecx = edx = 0;  // @286_4dd3d0
  L4dd7ae:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4668), sizeof v); (u32)v; });  // @288_4dd3d0
  edx = (u32)(EBP - 16);  // @289_4dd3d0
  p22_ = edx;  // @290_4dd3d0
  edx = (u32)(EBP - 52);  // @291_4dd3d0
  p23_ = edx;  // @292_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @293_4dd3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 148)))(ecx, (u32)(p23_), (u32)(p22_));  // @294_4dd3d0
  ecx = edx = 0;  // @295_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @296_4dd3d0
  edx = (u32)(ebx + 64);  // @297_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @298_4dd3d0
  p24_ = edx;  // @299_4dd3d0
  edx = (u32)(EBP - 16);  // @300_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @301_4dd3d0
  p25_ = edx;  // @302_4dd3d0
  edx = (u32)(EBP - 52);  // @303_4dd3d0
  p26_ = edx;  // @304_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @305_4dd3d0
  edx = (u32)(EBP - 564);  // @306_4dd3d0
  p27_ = edx;  // @307_4dd3d0
  edx = (u32)(EBP - 4660);  // @308_4dd3d0
  p28_ = edx;  // @309_4dd3d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(p28_), (u32)(p27_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4668), sizeof v); (u32)v; }), (u32)(0), (u32)(p26_), (u32)(p25_), (u32)(p24_), (u32)(-1), (u32)(1), (u32)(0), (u32)(1));  // @310_4dd3d0
  ecx = edx = 0;  // @311_4dd3d0
  edi = 0;  // @312_4dd3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4672), &v, sizeof v); }  // @313_4dd3d0
  if ((eax & eax) == 0) goto L4dd878;  // @314_4dd3d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4688), sizeof v); (u32)v; });  // @315_4dd3d0
  L4dd813:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edi*4 - 4660), sizeof v); (u32)v; });  // @317_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @318_4dd3d0
  if ((eax & eax) == 0) goto L4dd829;  // @319_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @320_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @321_4dd3d0
  goto L4dd82e;  // @322_4dd3d0
  L4dd829:;
  eax = (u32)(2097154);  // @324_4dd3d0
  L4dd82e:;
  if ((eax & (u32)(8388608)) != 0) goto L4dd863;  // @326_4dd3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; }) == (u32)(0)) goto L4dd863;  // @327_4dd3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; }) == (u32)(0)) goto L4dd863;  // @328_4dd3d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4680), sizeof v); (u32)v; });  // @329_4dd3d0
  eax = (u32)(EBP - 564);  // @330_4dd3d0
  p29_ = eax;  // @331_4dd3d0
  ecx = esi;  // @332_4dd3d0
  eax = ext_4dba00_fastcall3(ecx, edx, (u32)(p29_));  // @333_4dd3d0
  ecx = edx = 0;  // @334_4dd3d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4dd863;  // @335_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4692), sizeof v); (u32)v; });  // @336_4dd3d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + ebx*4), &v, sizeof v); }  // @337_4dd3d0
  ebx = (ebx + 1);  // @338_4dd3d0
  L4dd863:;
  edi = (edi + 1);  // @340_4dd3d0
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4672), sizeof v); (u32)v; })) goto L4dd813;  // @341_4dd3d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4688), &v, sizeof v); }  // @342_4dd3d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4696), sizeof v); (u32)v; });  // @343_4dd3d0
  L4dd878:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4664), sizeof v); (u32)v; });  // @345_4dd3d0
  ecx = (ecx + 1);  // @346_4dd3d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4664), &v, sizeof v); }  // @347_4dd3d0
  if ((s32)ecx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4684), sizeof v); (u32)v; })) goto L4dd6e0;  // @348_4dd3d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4688), sizeof v); (u32)v; });  // @349_4dd3d0
  L4dd897:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4700), sizeof v); (u32)v; });  // @351_4dd3d0
  p30_ = ebx;  // @352_4dd3d0
  p31_ = esi;  // @353_4dd3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @354_4dd3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(p31_), (u32)(p30_));  // @355_4dd3d0
  ecx = edx = 0;  // @356_4dd3d0
  L4dd8a3:;
  ecx = ebx;  // @358_4dd3d0
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(33554432));  // @359_4dd3d0
  ecx = edx = 0;  // @360_4dd3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @361_4dd3d0
  ecx = (ecx ^ EBP);  // @362_4dd3d0
  eax = ext_633654_thiscall1(ecx);  // @363_4dd3d0
  ecx = edx = 0;  // @364_4dd3d0
  __asm__ volatile("" :: "Yz"(x0));  // @365_4dd3d0
  return eax;  // @366_4dd3d0
}
PCREG(4dd3d0, lifted_4dd3d0);

