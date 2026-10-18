// batch200165.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 STDCALL ext_42da80_stdcall1(u32) __asm__("ext_42da80");
extern "C" u32 THISCALL ext_4b3270_thiscall1(u32) __asm__("ext_4b3270");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4d3e00_thiscall1(u32) __asm__("ext_4d3e00");
extern "C" u32 THISCALL ext_4da2f0_thiscall3(u32, u32, u32) __asm__("ext_4da2f0");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 THISCALL ext_633c90_thiscall1(u32) __asm__("ext_633c90");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42abee_cdecl3(...) __asm__("ext_42abee");
extern "C" u32 ext_42ac56_cdecl2(...) __asm__("ext_42ac56");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4d6520(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_4d6520
  eax = (eax ^ EBP);  // @1_4d6520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4d6520
  __builtin_memcpy((void *)(u32)(EBP - 88), &SENT_EBX, 4);  // @4_4d6520
  __builtin_memcpy((void *)(u32)(EBP - 92), &SENT_ESI, 4);  // @5_4d6520
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_4d6520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @7_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @8_4d6520
  __builtin_memcpy((void *)(u32)(EBP - 96), &SENT_EDI, 4);  // @9_4d6520
  edi = ecx;  // @10_4d6520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @11_4d6520
  eax = (u32)(65540);  // @12_4d6520
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @13_4d6520
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @14_4d6520
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 49), &v, sizeof v); }  // @15_4d6520
  eax = ext_633c90_thiscall1(ecx);  // @16_4d6520
  ecx = edx = 0;  // @17_4d6520
  eax = (u32)(65540);  // @18_4d6520
  { u32 v = (u32)((u32)(EBP + 4)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @19_4d6520
  eax = ext_633c90_thiscall1(ecx);  // @20_4d6520
  ecx = edx = 0;  // @21_4d6520
  eax = (u32)(65540);  // @22_4d6520
  { u32 v = (u32)((u32)(EBP + 4)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @23_4d6520
  eax = ext_633c90_thiscall1(ecx);  // @24_4d6520
  ecx = edx = 0;  // @25_4d6520
  ebx = 0;  // @26_4d6520
  { u32 v = (u32)((u32)(EBP + 4)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @27_4d6520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (ebx & 0xff)) goto L4d65a4;  // @28_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @29_4d6520
  eax = (eax - esi);  // @30_4d6520
  edi = eax;  // @31_4d6520
  L4d6582:;
  esi = (u32)(esi + 1);  // @33_4d6520
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi - 1), sizeof v); (u32)v; });  // @34_4d6520
  edx = (u32)(47);  // @35_4d6520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(92)) edx = eax;  // @36_4d6520
  ebx = (ebx + 1);  // @37_4d6520
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(edi + esi - 1), &v, sizeof v); }  // @38_4d6520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L4d6582;  // @39_4d6520
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @40_4d6520
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @41_4d6520
  L4d65a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @43_4d6520
  p0_ = esi;  // @44_4d6520
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + eax), &v, sizeof v); }  // @45_4d6520
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))((u32)(p0_), (u32)(42));  // @46_4d6520
  ecx = edx = 0;  // @47_4d6520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @48_4d6520
  if ((eax & eax) != 0) goto L4d6601;  // @49_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @50_4d6520
  if ((ecx & ecx) == 0) goto L4d6601;  // @51_4d6520
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; }) != eax) goto L4d6601;  // @52_4d6520
  edx = (u32)(EBP - 64);  // @53_4d6520
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @54_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4d6520
  p1_ = edx;  // @56_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @57_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }), (u32)(p1_));  // @58_4d6520
  ecx = edx = 0;  // @59_4d6520
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4d6818;  // @60_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @61_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; }), (u32)(0));  // @63_4d6520
  ecx = edx = 0;  // @64_4d6520
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @65_4d6520
  goto L4d681a;  // @66_4d6520
  L4d6601:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @68_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_4d6520
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; }) == (u32)(0)) goto L4d6613;  // @70_4d6520
  goto L4d6616;  // @71_4d6520
  L4d6613:;
  L4d6616:;
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 46), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; }), (u32)(0));  // @74_4d6520
  ecx = edx = 0;  // @75_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @76_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_4d6520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @78_4d6520
  ecx = edx = 0;  // @79_4d6520
  if ((eax & eax) != 0) goto L4d6818;  // @80_4d6520
  L4d6630:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @82_4d6520
  edx = (u32)(EBP - 68);  // @83_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_4d6520
  p2_ = edx;  // @85_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(p2_), (u32)(4), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @86_4d6520
  ecx = edx = 0;  // @87_4d6520
  if (eax == (u32)(4)) goto L4d6654;  // @88_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @89_4d6520
  if ((eax & eax) == 0) goto L4d6653;  // @90_4d6520
  eax = ((u32(STDCALL *)(void))(eax))();  // @91_4d6520
  ecx = edx = 0;  // @92_4d6520
  goto L4d6654;  // @93_4d6520
  L4d6653:;
  __builtin_trap();  // @95_4d6520
  L4d6654:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @97_4d6520
  if (eax == (u32)(33639248)) goto L4d66ad;  // @98_4d6520
  if (eax == (u32)(101010256)) goto L4d6818;  // @99_4d6520
  if (eax == (u32)(1383427685)) goto L4d6818;  // @100_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @101_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6908196), (u32)(693));  // @103_4d6520
  ecx = edx = 0;  // @104_4d6520
  p3_ = eax;  // @105_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @106_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p3_), (u32)(6908380));  // @107_4d6520
  ecx = edx = 0;  // @108_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @109_4d6520
  if ((eax & eax) == 0) goto L4d66a7;  // @110_4d6520
  eax = ((u32(STDCALL *)(void))(eax))();  // @111_4d6520
  ecx = edx = 0;  // @112_4d6520
  goto L4d6805;  // @113_4d6520
  L4d66a7:;
  __builtin_trap();  // @115_4d6520
  L4d66ad:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @117_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_4d6520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @119_4d6520
  ecx = edx = 0;  // @120_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @121_4d6520
  esi = eax;  // @122_4d6520
  eax = (u32)(EBP - 48);  // @123_4d6520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_4d6520
  p4_ = eax;  // @125_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(p4_), (u32)(42), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @126_4d6520
  ecx = edx = 0;  // @127_4d6520
  if (eax == (u32)(42)) goto L4d66de;  // @128_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @129_4d6520
  if ((eax & eax) == 0) goto L4d66dd;  // @130_4d6520
  eax = ((u32(STDCALL *)(void))(eax))();  // @131_4d6520
  ecx = edx = 0;  // @132_4d6520
  goto L4d66de;  // @133_4d6520
  L4d66dd:;
  __builtin_trap();  // @135_4d6520
  L4d66de:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) & 0xffff);  // @137_4d6520
  if (((eax & 0xffff) & (eax & 0xffff)) == 0) goto L4d679a;  // @138_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @139_4d6520
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @140_4d6520
  eax = (eax & 0xffff);  // @141_4d6520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @142_4d6520
  p5_ = eax;  // @143_4d6520
  p6_ = ebx;  // @144_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(p6_), (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @145_4d6520
  ecx = edx = 0;  // @146_4d6520
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @147_4d6520
  if (eax == ecx) goto L4d6714;  // @148_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @149_4d6520
  if ((eax & eax) == 0) goto L4d6713;  // @150_4d6520
  eax = ((u32(STDCALL *)(void))(eax))();  // @151_4d6520
  ecx = edx = 0;  // @152_4d6520
  goto L4d6714;  // @153_4d6520
  L4d6713:;
  __builtin_trap();  // @155_4d6520
  L4d6714:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @157_4d6520
  ecx = 0;  // @158_4d6520
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ebx), &v, sizeof v); }  // @159_4d6520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @160_4d6520
  if ((edx & edx) == 0) goto L4d6734;  // @161_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; });  // @162_4d6520
  L4d6728:;
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L4d679a;  // @164_4d6520
  ecx = (ecx + 1);  // @165_4d6520
  eax = (eax + (u32)(4));  // @166_4d6520
  if (ecx < edx) goto L4d6728;  // @167_4d6520
  L4d6734:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; }) == (u32)(0)) goto L4d674d;  // @169_4d6520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @170_4d6520
  ecx = ebx;  // @171_4d6520
  eax = ext_4cc850_fastcall2(ecx, edx);  // @172_4d6520
  ecx = edx = 0;  // @173_4d6520
  if ((eax & eax) != 0) goto L4d679a;  // @174_4d6520
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @175_4d6520
  goto L4d677b;  // @176_4d6520
  L4d674d:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @178_4d6520
  ecx = ebx;  // @179_4d6520
  edx = (u32)(ecx + 1);  // @180_4d6520
  L4d6755:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @182_4d6520
  ecx = (ecx + 1);  // @183_4d6520
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d6755;  // @184_4d6520
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @185_4d6520
  ecx = (ecx - edx);  // @186_4d6520
  if (ecx != eax) goto L4d679a;  // @187_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @188_4d6520
  p7_ = ebx;  // @189_4d6520
  p8_ = ecx;  // @190_4d6520
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676414))((u32)(p8_), (u32)(p7_));  // @191_4d6520
  ecx = edx = 0;  // @192_4d6520
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @193_4d6520
  if ((eax & eax) != 0) goto L4d679d;  // @194_4d6520
  L4d677b:;
  x0 = _mm_loadu_ps((const float *)(u32)(EBP - 46));  // @196_4d6520
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 22), sizeof v); (u32)v; })) & 0xffff);  // @197_4d6520
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 49), &v, sizeof v); }  // @198_4d6520
  _mm_storeu_ps((float *)(u32)(ebx), x0);  // @199_4d6520
  x0 = _mm_castsi128_ps(_mm_loadl_epi64((const __m128i *)(u32)(EBP - 30)));  // @200_4d6520
  _mm_storel_epi64((__m128i *)(u32)(ebx + 16), _mm_castps_si128(x0));  // @201_4d6520
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @202_4d6520
  goto L4d679d;  // @203_4d6520
  L4d679a:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @205_4d6520
  L4d679d:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 22), sizeof v); (u32)v; })) & 0xffff);  // @207_4d6520
  if (((eax & 0xffff) & (eax & 0xffff)) == 0) goto L4d67ce;  // @208_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @209_4d6520
  eax = (eax & 0xffff);  // @210_4d6520
  p9_ = eax;  // @211_4d6520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @212_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; }), (u32)(p9_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @213_4d6520
  ecx = edx = 0;  // @214_4d6520
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 22), sizeof v); (u32)v; });  // @215_4d6520
  if (eax == ecx) goto L4d67ce;  // @216_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @217_4d6520
  if ((eax & eax) == 0) goto L4d67cd;  // @218_4d6520
  eax = ((u32(STDCALL *)(void))(eax))();  // @219_4d6520
  ecx = edx = 0;  // @220_4d6520
  goto L4d67ce;  // @221_4d6520
  L4d67cd:;
  __builtin_trap();  // @223_4d6520
  L4d67ce:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; })) & 0xffff);  // @225_4d6520
  if (((eax & 0xffff) & (eax & 0xffff)) == 0) goto L4d67ff;  // @226_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @227_4d6520
  eax = (eax & 0xffff);  // @228_4d6520
  p10_ = eax;  // @229_4d6520
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @230_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; }), (u32)(p10_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @231_4d6520
  ecx = edx = 0;  // @232_4d6520
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @233_4d6520
  if (eax == ecx) goto L4d67ff;  // @234_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @235_4d6520
  if ((eax & eax) == 0) goto L4d67fe;  // @236_4d6520
  eax = ((u32(STDCALL *)(void))(eax))();  // @237_4d6520
  ecx = edx = 0;  // @238_4d6520
  goto L4d67ff;  // @239_4d6520
  L4d67fe:;
  __builtin_trap();  // @241_4d6520
  L4d67ff:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 49), sizeof v); (u32)v; }) != (u32)(0)) goto L4d6830;  // @243_4d6520
  L4d6805:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @245_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @246_4d6520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @247_4d6520
  ecx = edx = 0;  // @248_4d6520
  if ((eax & eax) == 0) goto L4d6630;  // @249_4d6520
  L4d6818:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @251_4d6520
  L4d681a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @253_4d6520
  ecx = (ecx ^ EBP);  // @254_4d6520
  eax = ext_633654_thiscall1(ecx);  // @255_4d6520
  ecx = edx = 0;  // @256_4d6520
  __asm__ volatile("" :: "Yz"(x0));  // @257_4d6520
  return eax;  // @258_4d6520
  L4d6830:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @260_4d6520
  if ((eax & eax) == 0) goto L4d6839;  // @261_4d6520
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @262_4d6520
  L4d6839:;
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @264_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @265_4d6520
  edx = (edx + (u32)(30));  // @266_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 10), sizeof v); (u32)v; });  // @267_4d6520
  eax = (eax + edx);  // @268_4d6520
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @269_4d6520
  p11_ = eax;  // @270_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }), (u32)(p11_), (u32)(0));  // @271_4d6520
  ecx = edx = 0;  // @272_4d6520
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @273_4d6520
  if ((esi & esi) == 0) goto L4d6872;  // @274_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @275_4d6520
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @276_4d6520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @277_4d6520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; }));  // @278_4d6520
  ecx = edx = 0;  // @279_4d6520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @280_4d6520
  p12_ = eax;  // @281_4d6520
  p13_ = ebx;  // @282_4d6520
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; }), (u32)(p13_), (u32)(p12_));  // @283_4d6520
  ecx = edx = 0;  // @284_4d6520
  L4d6872:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @286_4d6520
  goto L4d681a;  // @287_4d6520
}
PCREG(4d6520, lifted_4d6520);

extern "C" u32 THISCALL lifted_656260(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_656260
  eax = (eax ^ EBP);  // @1_656260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_656260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_656260
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EBX, 4);  // @4_656260
  __builtin_memcpy((void *)(u32)(EBP - 12), &SENT_ESI, 4);  // @5_656260
  ebx = 0;  // @6_656260
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_EDI, 4);  // @7_656260
  edi = ecx;  // @8_656260
  if (eax > (u32)(3)) goto L6562b6;  // @9_656260
  switch (eax) { case 0: goto L656290; case 1: goto L656284; case 2: goto L65629c; case 3: goto L6562a8; default: __builtin_trap(); }  // @10_656260
  L656284:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_656260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 280)))(ecx);  // @13_656260
  ecx = edx = 0;  // @14_656260
  ebx = eax;  // @15_656260
  goto L6562b6;  // @16_656260
  L656290:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_656260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 284)))(ecx);  // @19_656260
  ecx = edx = 0;  // @20_656260
  ebx = eax;  // @21_656260
  goto L6562b6;  // @22_656260
  L65629c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @24_656260
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 288)))(ecx);  // @25_656260
  ecx = edx = 0;  // @26_656260
  ebx = eax;  // @27_656260
  goto L6562b6;  // @28_656260
  L6562a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_656260
  if ((eax & eax) == 0) goto L6562b5;  // @31_656260
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_656260
  ecx = edx = 0;  // @33_656260
  goto L6562b6;  // @34_656260
  L6562b5:;
  __builtin_trap();  // @36_656260
  L6562b6:;
  eax = ebx;  // @38_656260
  eax = ext_633c90_thiscall1(ecx);  // @39_656260
  ecx = edx = 0;  // @40_656260
  esi = (u32)(EBP + 4);  // @41_656260
  p0_ = ebx;  // @42_656260
  p1_ = esi;  // @43_656260
  eax = ext_634d10_cdecl3((u32)(p1_), (u32)(0), (u32)(p0_));  // @44_656260
  ecx = edx = 0;  // @45_656260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_656260
  ecx = edi;  // @47_656260
  p2_ = ebx;  // @48_656260
  p3_ = esi;  // @49_656260
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(p3_), (u32)(p2_));  // @50_656260
  ecx = edx = 0;  // @51_656260
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_656260
  esi = eax;  // @53_656260
  p4_ = esi;  // @54_656260
  ecx = edi;  // @55_656260
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 12)))(ecx, (u32)(p4_));  // @56_656260
  ecx = edx = 0;  // @57_656260
  ecx = (u32)(6);  // @58_656260
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 2), &v, sizeof v); }  // @59_656260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @60_656260
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @61_656260
  eax = esi;  // @62_656260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @63_656260
  ecx = (ecx ^ EBP);  // @64_656260
  eax = ext_633654_thiscall1(ecx);  // @65_656260
  ecx = edx = 0;  // @66_656260
  return eax;  // @67_656260
}
PCREG(656260, lifted_656260);

extern "C" u32 STDCALL lifted_4261c0(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_4261c0
  eax = (eax ^ EBP);  // @1_4261c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_4261c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4261c0
  eax = 0;  // @4_4261c0
  __builtin_memcpy((void *)(u32)(EBP - 36), &SENT_EBX, 4);  // @5_4261c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_4261c0
  ecx = edx;  // @7_4261c0
  __builtin_memcpy((void *)(u32)(EBP - 40), &SENT_ESI, 4);  // @8_4261c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @9_4261c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @10_4261c0
  __builtin_memcpy((void *)(u32)(EBP - 44), &SENT_EDI, 4);  // @11_4261c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @12_4261c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == (eax & 0xff)) goto L42629d;  // @13_4261c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @14_4261c0
  L4261f1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(37)) goto L42628d;  // @16_4261c0
  esi = (u32)(edx + 1);  // @17_4261c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @18_4261c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; }) != (u32)(37)) goto L42620e;  // @19_4261c0
  edx = (edx + (u32)(2));  // @20_4261c0
  goto L42628e;  // @21_4261c0
  L42620e:;
  ecx = 0;  // @23_4261c0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @24_4261c0
  edi = 0;  // @25_4261c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 6), &v, sizeof v); }  // @26_4261c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @27_4261c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @28_4261c0
  L426220:;
  edi = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @30_4261c0
  eax = (u32)(edi - 46);  // @31_4261c0
  if (eax > (u32)(72)) goto L426276;  // @32_4261c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4350908), sizeof v); (u32)v; });  // @33_4261c0
  switch (eax) { case 0: goto L426264; case 1: goto L426239; case 2: goto L426273; case 3: goto L4262c3; case 4: goto L426276; default: __builtin_trap(); }  // @34_4261c0
  L426239:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 6), sizeof v); (u32)v; }) == (u32)(0)) goto L426250;  // @36_4261c0
  eax = (u32)(ecx + ecx*4);  // @37_4261c0
  ecx = (u32)(eax - 24);  // @38_4261c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 5), sizeof v); (u32)v; })) & 0xff);  // @39_4261c0
  ecx = (u32)(edi + ecx*2);  // @40_4261c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @41_4261c0
  goto L42627b;  // @42_4261c0
  L426250:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @44_4261c0
  eax = (u32)(eax + eax*4);  // @45_4261c0
  eax = (u32)(eax - 24);  // @46_4261c0
  eax = (u32)(edi + eax*2);  // @47_4261c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @48_4261c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 5), sizeof v); (u32)v; })) & 0xff);  // @49_4261c0
  goto L42627b;  // @50_4261c0
  L426264:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 6), sizeof v); (u32)v; }) != (u32)(0)) goto L426276;  // @52_4261c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 5), sizeof v); (u32)v; })) & 0xff);  // @53_4261c0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 6), &v, sizeof v); }  // @54_4261c0
  goto L42627b;  // @55_4261c0
  L426273:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @57_4261c0
  L426276:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @59_4261c0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @60_4261c0
  L42627b:;
  esi = (esi + 1);  // @62_4261c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @63_4261c0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L426220;  // @64_4261c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @65_4261c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @66_4261c0
  L426289:;
  eax = (eax + 1);  // @68_4261c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @69_4261c0
  L42628d:;
  edx = (edx + 1);  // @71_4261c0
  L42628e:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @73_4261c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(0)) goto L4261f1;  // @74_4261c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @75_4261c0
  L42629d:;
  { u32 v = (u32)((u32)(eax)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @77_4261c0
  { u32 v = (u32)((u32)(ecx)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, 4); }  // @78_4261c0
  { u32 v = (u32)((u32)(ebx)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, 4); }  // @79_4261c0
  eax = ext_42abee_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }));  // @80_4261c0
  ecx = edx = 0;  // @81_4261c0
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @82_4261c0
  eax = (eax + ebx);  // @83_4261c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @84_4261c0
  ecx = (ecx ^ EBP);  // @85_4261c0
  eax = ext_633654_thiscall1(ecx);  // @86_4261c0
  ecx = edx = 0;  // @87_4261c0
  return eax;  // @88_4261c0
  L4262c3:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 6), sizeof v); (u32)v; }) == (u32)(0)) goto L4262d4;  // @90_4261c0
  eax = ecx;  // @91_4261c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @92_4261c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @93_4261c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @94_4261c0
  L4262d4:;
  esi = edx;  // @96_4261c0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @97_4261c0
  eax = (u32)(esi + 1);  // @98_4261c0
  eax = ext_633c90_thiscall1(ecx);  // @99_4261c0
  ecx = edx = 0;  // @100_4261c0
  edi = (u32)(EBP + 4);  // @101_4261c0
  { u32 v = (u32)((u32)(esi)); __builtin_memcpy((void *)(u32)(EBP + 0), &v, 4); }  // @102_4261c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @103_4261c0
  { u32 v = (u32)((u32)(esi)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, 4); }  // @104_4261c0
  { u32 v = (u32)((u32)(edi)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @105_4261c0
  eax = ext_634d22_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 0), 4); v; }));  // @106_4261c0
  ecx = edx = 0;  // @107_4261c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @108_4261c0
  eax = edi;  // @109_4261c0
  eax = (eax - esi);  // @110_4261c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @111_4261c0
  { u32 v = (u32)((u32)(esi)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @112_4261c0
  { u32 v = (u32)((u32)(edi)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, 4); }  // @113_4261c0
  { u32 v = (u32)((u32)(ebx)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, 4); }  // @114_4261c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx), &v, sizeof v); }  // @115_4261c0
  eax = ext_42abee_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }));  // @116_4261c0
  ecx = edx = 0;  // @117_4261c0
  ebx = (ebx + eax);  // @118_4261c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @119_4261c0
  ecx = (u32)(1);  // @120_4261c0
  edx = (u32)(3);  // @121_4261c0
  esi = (u32)(esi + eax*4);  // @122_4261c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @123_4261c0
  esi = (esi + (u32)(4));  // @124_4261c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @125_4261c0
  if ((eax & eax) == 0) eax = ecx;  // @126_4261c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @127_4261c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @128_4261c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @129_4261c0
  if ((ecx & ecx) == 0) ecx = edx;  // @130_4261c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @131_4261c0
  if ((s32)(eax & eax) <= 0) goto L426392;  // @132_4261c0
  L426340:;
  { u8 v = (u8)((u32)(91)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @134_4261c0
  esi = ecx;  // @135_4261c0
  ebx = (ebx + 1);  // @136_4261c0
  if ((s32)(ecx & ecx) <= 0) goto L426386;  // @137_4261c0
  L426350:;
  x0 = _mm_load_ss((const float *)(u32)(edi));  // @139_4261c0
  x0 = _mm_castpd_ps(_mm_cvtps_pd(x0));  // @140_4261c0
  _mm_store_sd((double *)(u32)(EBP - 4), _mm_castps_pd(x0));  // @141_4261c0
  { u32 v = (u32)((u32)(6784772)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, 4); }  // @142_4261c0
  { u32 v = (u32)((u32)(ebx)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, 4); }  // @143_4261c0
  eax = ext_42ac56_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), 4); v; }));  // @144_4261c0
  ecx = edx = 0;  // @145_4261c0
  ebx = (ebx + eax);  // @146_4261c0
  edi = (edi + (u32)(4));  // @147_4261c0
  if ((s32)esi <= (s32)(u32)(1)) goto L42637b;  // @148_4261c0
  { u8 v = (u8)((u32)(44)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @149_4261c0
  ebx = (ebx + 1);  // @150_4261c0
  L42637b:;
  esi = (esi - 1);  // @152_4261c0
  if ((s32)(esi & esi) > 0) goto L426350;  // @153_4261c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @154_4261c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @155_4261c0
  L426386:;
  eax = (eax - 1);  // @157_4261c0
  { u8 v = (u8)((u32)(93)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @158_4261c0
  ebx = (ebx + 1);  // @159_4261c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @160_4261c0
  if ((s32)(eax & eax) > 0) goto L426340;  // @161_4261c0
  L426392:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @163_4261c0
  eax = (eax | (u32)(4294967295));  // @164_4261c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @165_4261c0
  ecx = (u32)(edx + 1);  // @166_4261c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @167_4261c0
  goto L426289;  // @168_4261c0
}
PCREG(4261c0, lifted_4261c0);

extern "C" u32 THISCALL lifted_4b34d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x668ac6);  // @h_4b34d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 204), &SENT_EBX, 4);  // @0_4b34d0
  __builtin_memcpy((void *)(u32)(EBP - 208), &SENT_ESI, 4);  // @1_4b34d0
  __builtin_memcpy((void *)(u32)(EBP - 212), &SENT_EDI, 4);  // @2_4b34d0
  ebx = ecx;  // @3_4b34d0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xffff);  // @4_4b34d0
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 78), sizeof v); (u32)v; })) goto L4b397b;  // @5_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4b34d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @9_4b34d0
  ecx = edx = 0;  // @10_4b34d0
  ecx = (u32)(EBP - 196);  // @11_4b34d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @12_4b34d0
  p0_ = ecx;  // @13_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_4b34d0
  ecx = eax;  // @15_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6890544), (u32)(p0_));  // @16_4b34d0
  ecx = edx = 0;  // @17_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @18_4b34d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @19_4b34d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @22_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6890532), (u32)(0), (u32)(6889180), (u32)(2004), (u32)(-1));  // @24_4b34d0
  ecx = edx = 0;  // @25_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @26_4b34d0
  eax = (eax & 0xffff);  // @27_4b34d0
  p1_ = eax;  // @28_4b34d0
  p2_ = edi;  // @29_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 300)))(ecx, (u32)(p2_), (u32)(p1_));  // @30_4b34d0
  ecx = edx = 0;  // @31_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_4b34d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @35_4b34d0
  ecx = edx = 0;  // @36_4b34d0
  ecx = (u32)(EBP - 196);  // @37_4b34d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @38_4b34d0
  p3_ = ecx;  // @39_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @40_4b34d0
  ecx = eax;  // @41_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(p3_));  // @42_4b34d0
  ecx = edx = 0;  // @43_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; }));  // @47_4b34d0
  ecx = edx = 0;  // @48_4b34d0
  esi = eax;  // @49_4b34d0
  if ((esi & esi) == 0) goto L4b35f0;  // @50_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_4b34d0
  ecx = esi;  // @52_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @53_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2149580820));  // @54_4b34d0
  ecx = edx = 0;  // @55_4b34d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4b35f0;  // @56_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_4b34d0
  ecx = esi;  // @58_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1428)))(ecx, (u32)(0));  // @59_4b34d0
  ecx = edx = 0;  // @60_4b34d0
  L4b35f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @62_4b34d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 136), &v, sizeof v); }  // @63_4b34d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; }) != (u32)(0)) goto L4b39d8;  // @64_4b34d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 77), &v, sizeof v); }  // @65_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_4b34d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @69_4b34d0
  ecx = edx = 0;  // @70_4b34d0
  if ((eax & eax) == 0) goto L4b3632;  // @71_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @72_4b34d0
  ecx = eax;  // @73_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6890560), (u32)(6790740));  // @74_4b34d0
  ecx = edx = 0;  // @75_4b34d0
  L4b3632:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @78_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_4b34d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @80_4b34d0
  ecx = edx = 0;  // @81_4b34d0
  ecx = (u32)(EBP - 196);  // @82_4b34d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @83_4b34d0
  p4_ = ecx;  // @84_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @85_4b34d0
  ecx = eax;  // @86_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6890260), (u32)(p4_));  // @87_4b34d0
  ecx = edx = 0;  // @88_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_4b34d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; }) != (u32)(0)) goto L4b388b;  // @90_4b34d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; }) == (u32)(0)) goto L4b3694;  // @91_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @92_4b34d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; }) != (u32)(0)) goto L4b388b;  // @93_4b34d0
  L4b3694:;
  edx = (u32)(ebx + 218);  // @95_4b34d0
  eax = (u32)(EBP - 200);  // @96_4b34d0
  if (edx == eax) goto L4b36a9;  // @97_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; });  // @98_4b34d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @99_4b34d0
  L4b36a9:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 214), &v, sizeof v); }  // @101_4b34d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 230), &v, sizeof v); }  // @102_4b34d0
  { u16 v = (u16)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 158), &v, sizeof v); }  // @103_4b34d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 166), &v, sizeof v); }  // @104_4b34d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 154), sizeof v); (u32)v; }) != (u32)(0)) goto L4b36e6;  // @105_4b34d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 128), sizeof v); (u32)v; }) == (u32)(0)) goto L4b3808;  // @106_4b34d0
  L4b36e6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @109_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 116), sizeof v); (u32)v; }));  // @111_4b34d0
  ecx = edx = 0;  // @112_4b34d0
  esi = eax;  // @113_4b34d0
  if ((esi & esi) != 0) goto L4b37f4;  // @114_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @115_4b34d0
  p5_ = esi;  // @116_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @117_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @118_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6890660), (u32)(p5_));  // @120_4b34d0
  ecx = edx = 0;  // @121_4b34d0
  esi = eax;  // @122_4b34d0
  if ((esi & esi) != 0) goto L4b37f4;  // @123_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @124_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2078));  // @126_4b34d0
  ecx = edx = 0;  // @127_4b34d0
  p6_ = eax;  // @128_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @129_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p6_), (u32)(6890676));  // @130_4b34d0
  ecx = edx = 0;  // @131_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @132_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @133_4b34d0
  p7_ = esi;  // @134_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @135_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 660)))(ecx, (u32)(6890660), (u32)(6801632), (u32)(p7_), (u32)(1));  // @137_4b34d0
  ecx = edx = 0;  // @138_4b34d0
  esi = eax;  // @139_4b34d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 128), sizeof v); (u32)v; }) == (u32)(0)) goto L4b37de;  // @140_4b34d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 154), &v, sizeof v); }  // @141_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @142_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2088));  // @144_4b34d0
  ecx = edx = 0;  // @145_4b34d0
  p8_ = eax;  // @146_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @147_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p8_), (u32)(6890704));  // @148_4b34d0
  ecx = edx = 0;  // @149_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @150_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @151_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 128), sizeof v); (u32)v; }));  // @153_4b34d0
  ecx = edx = 0;  // @154_4b34d0
  ecx = (u32)(EBP - 28);  // @155_4b34d0
  p9_ = ecx;  // @156_4b34d0
  ecx = (u32)(EBP - 64);  // @157_4b34d0
  p10_ = ecx;  // @158_4b34d0
  ecx = eax;  // @159_4b34d0
  eax = ext_4db6c0_thiscall3(ecx, (u32)(p10_), (u32)(p9_));  // @160_4b34d0
  ecx = edx = 0;  // @161_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @162_4b34d0
  ecx = (u32)(EBP - 28);  // @163_4b34d0
  p11_ = ecx;  // @164_4b34d0
  ecx = (u32)(EBP - 64);  // @165_4b34d0
  p12_ = ecx;  // @166_4b34d0
  ecx = esi;  // @167_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(p12_), (u32)(p11_));  // @168_4b34d0
  ecx = edx = 0;  // @169_4b34d0
  L4b37de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @171_4b34d0
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @172_4b34d0
  ecx = edx = 0;  // @173_4b34d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @174_4b34d0
  L4b37f4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @176_4b34d0
  p13_ = esi;  // @177_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @178_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @179_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p13_));  // @180_4b34d0
  ecx = edx = 0;  // @181_4b34d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 116), &v, sizeof v); }  // @182_4b34d0
  L4b3808:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @184_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @185_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @186_4b34d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @187_4b34d0
  ecx = edx = 0;  // @188_4b34d0
  esi = eax;  // @189_4b34d0
  ecx = esi;  // @190_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @191_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 168)))(ecx, (u32)(6890468));  // @192_4b34d0
  ecx = edx = 0;  // @193_4b34d0
  edi = eax;  // @194_4b34d0
  edi = (edi >> (u32)(2));  // @195_4b34d0
  eax = (u32)(edi*4 + 4);  // @196_4b34d0
  eax = ext_633c90_thiscall1(ecx);  // @197_4b34d0
  ecx = edx = 0;  // @198_4b34d0
  ecx = (u32)(EBP + 4);  // @199_4b34d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @200_4b34d0
  if ((edi & edi) == 0) goto L4b3859;  // @201_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @202_4b34d0
  p14_ = ecx;  // @203_4b34d0
  ecx = esi;  // @204_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(6890468), (u32)(p14_));  // @205_4b34d0
  ecx = edx = 0;  // @206_4b34d0
  L4b3859:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @208_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @209_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @210_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }));  // @211_4b34d0
  ecx = edx = 0;  // @212_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @213_4b34d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edi*4), &v, sizeof v); }  // @214_4b34d0
  eax = (u32)(edi + 1);  // @215_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @216_4b34d0
  p15_ = eax;  // @217_4b34d0
  p16_ = ecx;  // @218_4b34d0
  ecx = esi;  // @219_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 40)))(ecx, (u32)(6890468), (u32)(p16_), (u32)(p15_));  // @220_4b34d0
  ecx = edx = 0;  // @221_4b34d0
  goto L4b39d8;  // @222_4b34d0
  L4b388b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @224_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @225_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }));  // @226_4b34d0
  ecx = edx = 0;  // @227_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; });  // @228_4b34d0
  p17_ = eax;  // @229_4b34d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @230_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @231_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(p17_));  // @232_4b34d0
  ecx = edx = 0;  // @233_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @234_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @235_4b34d0
  if ((eax & eax) != 0) goto L4b392e;  // @236_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2037));  // @237_4b34d0
  ecx = edx = 0;  // @238_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @239_4b34d0
  edi = eax;  // @240_4b34d0
  eax = (u32)(EBP - 192);  // @241_4b34d0
  p18_ = eax;  // @242_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @243_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p18_), (u32)(0));  // @244_4b34d0
  ecx = edx = 0;  // @245_4b34d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @246_4b34d0
  ecx = eax;  // @247_4b34d0
  reg.state = (s32)((u32)(0));  // @248_4b34d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @249_4b34d0
  ecx = edx = 0;  // @250_4b34d0
  p19_ = eax;  // @251_4b34d0
  p20_ = edi;  // @252_4b34d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p20_), (u32)(6890588), (u32)(p19_));  // @253_4b34d0
  ecx = edx = 0;  // @254_4b34d0
  reg.state = (s32)((u32)(4294967295));  // @255_4b34d0
  ecx = (u32)(EBP - 192);  // @256_4b34d0
  eax = ext_4cbec0_thiscall1(ecx);  // @257_4b34d0
  ecx = edx = 0;  // @258_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; });  // @259_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @260_4b34d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; }));  // @261_4b34d0
  ecx = edx = 0;  // @262_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 136), sizeof v); (u32)v; });  // @263_4b34d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @264_4b34d0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 78), sizeof v); (u32)v; });  // @265_4b34d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @266_4b34d0
  goto L4b39d8;  // @267_4b34d0
  L4b392e:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2043));  // @269_4b34d0
  ecx = edx = 0;  // @270_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @271_4b34d0
  edi = eax;  // @272_4b34d0
  eax = (u32)(EBP - 192);  // @273_4b34d0
  p21_ = eax;  // @274_4b34d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @275_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p21_), (u32)(0));  // @276_4b34d0
  ecx = edx = 0;  // @277_4b34d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @278_4b34d0
  ecx = eax;  // @279_4b34d0
  reg.state = (s32)((u32)(1));  // @280_4b34d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @281_4b34d0
  ecx = edx = 0;  // @282_4b34d0
  p22_ = eax;  // @283_4b34d0
  p23_ = edi;  // @284_4b34d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p23_), (u32)(6890612), (u32)(p22_));  // @285_4b34d0
  ecx = edx = 0;  // @286_4b34d0
  ecx = (u32)(EBP - 192);  // @287_4b34d0
  eax = ext_4cbec0_thiscall1(ecx);  // @288_4b34d0
  ecx = edx = 0;  // @289_4b34d0
  goto L4b39d8;  // @290_4b34d0
  L4b397b:;
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; })) goto L4b398c;  // @292_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @293_4b34d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 128), &v, sizeof v); }  // @294_4b34d0
  goto L4b39d8;  // @295_4b34d0
  L4b398c:;
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; })) goto L4b3999;  // @297_4b34d0
  goto L4b39a4;  // @298_4b34d0
  L4b3999:;
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 98), sizeof v); (u32)v; })) goto L4b39c4;  // @300_4b34d0
  L4b39a4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @302_4b34d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @303_4b34d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2129), (u32)(2123));  // @304_4b34d0
  ecx = edx = 0;  // @305_4b34d0
  p24_ = eax;  // @306_4b34d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @307_4b34d0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p24_), (u32)(6889252));  // @308_4b34d0
  ecx = edx = 0;  // @309_4b34d0
  goto L4b39d8;  // @310_4b34d0
  L4b39c4:;
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; })) goto L4b39d8;  // @312_4b34d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; }) == (u32)(0)) goto L4b39d8;  // @313_4b34d0
  eax = ext_4b3270_thiscall1(ecx);  // @314_4b34d0
  ecx = edx = 0;  // @315_4b34d0
  L4b39d8:;
  eax = 0;  // @317_4b34d0
  SEH_LEAVE();  // @318_4b34d0
  ext_633654(G(u32, 0x6f5630));  // @319_4b34d0
  return eax;  // @320_4b34d0
}
PCREG(4b34d0, lifted_4b34d0);

extern "C" u32 THISCALL lifted_4b3a70(u32 ecx_in) {
  SEH_ENTER(0x668afb);  // @h_4b3a70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 176), &SENT_EBX, 4);  // @0_4b3a70
  __builtin_memcpy((void *)(u32)(EBP - 180), &SENT_ESI, 4);  // @1_4b3a70
  __builtin_memcpy((void *)(u32)(EBP - 184), &SENT_EDI, 4);  // @2_4b3a70
  ebx = ecx;  // @3_4b3a70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 132), sizeof v); (u32)v; }) == (u32)(0)) goto L4b4014;  // @4_4b3a70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 159), sizeof v); (u32)v; }) != (u32)(0)) goto L4b3b1e;  // @5_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @7_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886624), (u32)(0));  // @9_4b3a70
  ecx = edx = 0;  // @10_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @12_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886640), (u32)(0));  // @14_4b3a70
  ecx = edx = 0;  // @15_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @17_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886660), (u32)(0));  // @19_4b3a70
  ecx = edx = 0;  // @20_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @22_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886700), (u32)(0));  // @24_4b3a70
  ecx = edx = 0;  // @25_4b3a70
  L4b3b1e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @30_4b3a70
  ecx = edx = 0;  // @31_4b3a70
  ecx = (u32)(EBP - 148);  // @32_4b3a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @33_4b3a70
  p0_ = ecx;  // @34_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_4b3a70
  ecx = eax;  // @36_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6838796), (u32)(p0_));  // @37_4b3a70
  ecx = edx = 0;  // @38_4b3a70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; }) == (u32)(0)) goto L4b3d73;  // @39_4b3a70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @40_4b3a70
  if ((esi & esi) == 0) goto L4b3d73;  // @41_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @43_4b3a70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; }) == (u32)(0)) goto L4b3b9f;  // @44_4b3a70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 253), &v, sizeof v); }  // @45_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @47_4b3a70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 257), &v, sizeof v); }  // @48_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_4b3a70
  L4b3b9f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @51_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @53_4b3a70
  ecx = edx = 0;  // @54_4b3a70
  ecx = (u32)(EBP - 148);  // @55_4b3a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @56_4b3a70
  p1_ = ecx;  // @57_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @58_4b3a70
  ecx = eax;  // @59_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6890232), (u32)(p1_));  // @60_4b3a70
  ecx = edx = 0;  // @61_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @62_4b3a70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 102), sizeof v); (u32)v; });  // @63_4b3a70
  p2_ = eax;  // @64_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }), (u32)(p2_), (u32)(1));  // @66_4b3a70
  ecx = edx = 0;  // @67_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @68_4b3a70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 114), sizeof v); (u32)v; });  // @69_4b3a70
  p3_ = eax;  // @70_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_4b3a70
  p4_ = esi;  // @72_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, (u32)(p4_), (u32)(p3_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 132), sizeof v); (u32)v; }));  // @73_4b3a70
  ecx = edx = 0;  // @74_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @76_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @78_4b3a70
  ecx = edx = 0;  // @79_4b3a70
  ecx = (u32)(EBP - 148);  // @80_4b3a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @81_4b3a70
  p5_ = ecx;  // @82_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @83_4b3a70
  ecx = eax;  // @84_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6864536), (u32)(p5_));  // @85_4b3a70
  ecx = edx = 0;  // @86_4b3a70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }) == (u32)(0)) goto L4b3c75;  // @87_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_4b3a70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @89_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @90_4b3a70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @91_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6890456), (u32)(0), (u32)(6889180), (u32)(1450), (u32)(0));  // @93_4b3a70
  ecx = edx = 0;  // @94_4b3a70
  eax = (eax & 0xffff);  // @95_4b3a70
  ecx = esi;  // @96_4b3a70
  p6_ = eax;  // @97_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }), (u32)(p6_));  // @98_4b3a70
  ecx = edx = 0;  // @99_4b3a70
  L4b3c75:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @104_4b3a70
  ecx = edx = 0;  // @105_4b3a70
  ecx = (u32)(EBP - 148);  // @106_4b3a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @107_4b3a70
  p7_ = ecx;  // @108_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @109_4b3a70
  ecx = eax;  // @110_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(p7_));  // @111_4b3a70
  ecx = edx = 0;  // @112_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @113_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @114_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @116_4b3a70
  ecx = edx = 0;  // @117_4b3a70
  if ((eax & eax) == 0) goto L4b3d12;  // @118_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @119_4b3a70
  ecx = eax;  // @120_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 876)))(ecx);  // @121_4b3a70
  ecx = edx = 0;  // @122_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @123_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @124_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 120), sizeof v); (u32)v; }));  // @126_4b3a70
  ecx = edx = 0;  // @127_4b3a70
  if ((eax & eax) == 0) goto L4b3cef;  // @128_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @129_4b3a70
  ecx = eax;  // @130_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(0));  // @131_4b3a70
  ecx = edx = 0;  // @132_4b3a70
  L4b3cef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @135_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 124), sizeof v); (u32)v; }));  // @137_4b3a70
  ecx = edx = 0;  // @138_4b3a70
  if ((eax & eax) == 0) goto L4b3d12;  // @139_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @140_4b3a70
  ecx = eax;  // @141_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(0));  // @142_4b3a70
  ecx = edx = 0;  // @143_4b3a70
  L4b3d12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @146_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @147_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @148_4b3a70
  ecx = edx = 0;  // @149_4b3a70
  ecx = (u32)(EBP - 148);  // @150_4b3a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @151_4b3a70
  p8_ = ecx;  // @152_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @153_4b3a70
  ecx = eax;  // @154_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6890260), (u32)(p8_));  // @155_4b3a70
  ecx = edx = 0;  // @156_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @157_4b3a70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @158_4b3a70
  esi = (esi - 1);  // @159_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @160_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @162_4b3a70
  ecx = edx = 0;  // @163_4b3a70
  p9_ = esi;  // @164_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @165_4b3a70
  ecx = eax;  // @166_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6890260), (u32)(p9_), (u32)(2));  // @167_4b3a70
  ecx = edx = 0;  // @168_4b3a70
  goto L4b3e49;  // @169_4b3a70
  L4b3d73:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @171_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @172_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @173_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 132), sizeof v); (u32)v; }));  // @174_4b3a70
  ecx = edx = 0;  // @175_4b3a70
  edx = eax;  // @176_4b3a70
  if ((edx & edx) == 0) goto L4b3db0;  // @177_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @178_4b3a70
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }) & (u32)(4194304)) == 0) goto L4b3db0;  // @179_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @180_4b3a70
  p10_ = edx;  // @181_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @182_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @183_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 184)))(ecx, (u32)(p10_));  // @184_4b3a70
  ecx = edx = 0;  // @185_4b3a70
  L4b3db0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; }) == (u32)(0)) goto L4b3e49;  // @187_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @189_4b3a70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 253), &v, sizeof v); }  // @190_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @191_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @192_4b3a70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 257), &v, sizeof v); }  // @193_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @195_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @196_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 152)))(ecx);  // @197_4b3a70
  ecx = edx = 0;  // @198_4b3a70
  esi = eax;  // @199_4b3a70
  if ((esi & esi) == 0) goto L4b3e49;  // @200_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @201_4b3a70
  eax = (u32)(EBP - 172);  // @202_4b3a70
  p11_ = eax;  // @203_4b3a70
  ecx = esi;  // @204_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(p11_));  // @205_4b3a70
  ecx = edx = 0;  // @206_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @207_4b3a70
  ecx = (u32)(EBP - 172);  // @208_4b3a70
  p12_ = ecx;  // @209_4b3a70
  ecx = esi;  // @210_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p12_));  // @211_4b3a70
  ecx = edx = 0;  // @212_4b3a70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; }) == (u32)(0)) goto L4b3e49;  // @213_4b3a70
  L4b3e20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @215_4b3a70
  p13_ = eax;  // @216_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @217_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @218_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(p13_));  // @219_4b3a70
  ecx = edx = 0;  // @220_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_4b3a70
  ecx = (u32)(EBP - 172);  // @222_4b3a70
  p14_ = ecx;  // @223_4b3a70
  ecx = esi;  // @224_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p14_));  // @225_4b3a70
  ecx = edx = 0;  // @226_4b3a70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; }) != (u32)(0)) goto L4b3e20;  // @227_4b3a70
  L4b3e49:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @229_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @230_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @231_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @232_4b3a70
  ecx = edx = 0;  // @233_4b3a70
  esi = eax;  // @234_4b3a70
  ecx = esi;  // @235_4b3a70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @236_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @237_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 168)))(ecx, (u32)(6890468));  // @238_4b3a70
  ecx = edx = 0;  // @239_4b3a70
  eax = (eax >> (u32)(2));  // @240_4b3a70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @241_4b3a70
  if ((eax & eax) == 0) goto L4b3f06;  // @242_4b3a70
  eax = (eax << (u32)(2));  // @243_4b3a70
  eax = ext_633c90_thiscall1(ecx);  // @244_4b3a70
  ecx = edx = 0;  // @245_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @246_4b3a70
  edi = (u32)(EBP + 4);  // @247_4b3a70
  p15_ = edi;  // @248_4b3a70
  ecx = esi;  // @249_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(6890468), (u32)(p15_));  // @250_4b3a70
  ecx = edx = 0;  // @251_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @252_4b3a70
  esi = 0;  // @253_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @254_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @255_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }));  // @256_4b3a70
  ecx = edx = 0;  // @257_4b3a70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @258_4b3a70
  ecx = 0;  // @259_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @260_4b3a70
  if ((eax & eax) == 0) goto L4b3ef1;  // @261_4b3a70
  L4b3ec5:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx*4), sizeof v); (u32)v; });  // @263_4b3a70
  if (edx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; })) goto L4b3ed4;  // @264_4b3a70
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + esi*4), &v, sizeof v); }  // @265_4b3a70
  esi = (esi + 1);  // @266_4b3a70
  L4b3ed4:;
  ecx = (ecx + 1);  // @268_4b3a70
  if ((s32)ecx < (s32)eax) goto L4b3ec5;  // @269_4b3a70
  if ((esi & esi) == 0) goto L4b3ef1;  // @270_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @271_4b3a70
  p16_ = esi;  // @272_4b3a70
  p17_ = edi;  // @273_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @274_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(6890468), (u32)(p17_), (u32)(p16_));  // @275_4b3a70
  ecx = edx = 0;  // @276_4b3a70
  goto L4b3f06;  // @277_4b3a70
  L4b3ef1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @279_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @280_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 160)))(ecx, (u32)(6890468), (u32)(0));  // @281_4b3a70
  ecx = edx = 0;  // @282_4b3a70
  L4b3f06:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @284_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @285_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @286_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @287_4b3a70
  ecx = edx = 0;  // @288_4b3a70
  ecx = (u32)(EBP - 148);  // @289_4b3a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @290_4b3a70
  p18_ = ecx;  // @291_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @292_4b3a70
  ecx = eax;  // @293_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6889544), (u32)(p18_));  // @294_4b3a70
  ecx = edx = 0;  // @295_4b3a70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @296_4b3a70
  ecx = edi;  // @297_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @298_4b3a70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @299_4b3a70
  ecx = edx = 0;  // @300_4b3a70
  if ((eax & eax) == 0) goto L4b400a;  // @301_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @302_4b3a70
  ecx = edi;  // @303_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(0));  // @304_4b3a70
  ecx = edx = 0;  // @305_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @306_4b3a70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @307_4b3a70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @308_4b3a70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @309_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @310_4b3a70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @311_4b3a70
  ecx = edi;  // @312_4b3a70
  p19_ = esi;  // @313_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(p19_));  // @314_4b3a70
  ecx = edx = 0;  // @315_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @316_4b3a70
  p20_ = esi;  // @317_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @318_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @319_4b3a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(p20_));  // @320_4b3a70
  ecx = edx = 0;  // @321_4b3a70
  esi = eax;  // @322_4b3a70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @323_4b3a70
  if ((esi & esi) == 0) goto L4b400a;  // @324_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @325_4b3a70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @326_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6889180), (u32)(1520));  // @327_4b3a70
  ecx = edx = 0;  // @328_4b3a70
  edi = eax;  // @329_4b3a70
  ecx = esi;  // @330_4b3a70
  eax = (u32)(EBP - 144);  // @331_4b3a70
  p21_ = eax;  // @332_4b3a70
  eax = ext_4da2f0_thiscall3(ecx, (u32)(p21_), (u32)(0));  // @333_4b3a70
  ecx = edx = 0;  // @334_4b3a70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @335_4b3a70
  ecx = eax;  // @336_4b3a70
  reg.state = (s32)((u32)(0));  // @337_4b3a70
  eax = ext_4cc1d0_thiscall1(ecx);  // @338_4b3a70
  ecx = edx = 0;  // @339_4b3a70
  p22_ = eax;  // @340_4b3a70
  p23_ = edi;  // @341_4b3a70
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p23_), (u32)(6890488), (u32)(p22_));  // @342_4b3a70
  ecx = edx = 0;  // @343_4b3a70
  reg.state = (s32)((u32)(4294967295));  // @344_4b3a70
  ecx = (u32)(EBP - 144);  // @345_4b3a70
  eax = ext_4cbec0_thiscall1(ecx);  // @346_4b3a70
  ecx = edx = 0;  // @347_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @348_4b3a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @349_4b3a70
  if ((ecx & ecx) == 0) goto L4b400a;  // @350_4b3a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @351_4b3a70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 296)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }), (u32)(0));  // @352_4b3a70
  ecx = edx = 0;  // @353_4b3a70
  L4b400a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 132), &v, sizeof v); }  // @355_4b3a70
  L4b4014:;
  SEH_LEAVE();  // @357_4b3a70
  ext_633654(G(u32, 0x6f5630));  // @358_4b3a70
  return eax;  // @359_4b3a70
}
PCREG(4b3a70, lifted_4b3a70);

extern "C" u32 THISCALL lifted_42de30(u32 ecx_in) {
  SEH_ENTER(0x665035);  // @h_42de30
  u8 F[0x490] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x390);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_, p35_, p36_, p37_, p38_, p39_, p40_, p41_, p42_, p43_, p44_, p45_, p46_, p47_, p48_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  double T[8]; double fa_ = 0, fb_ = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 284), &SENT_EBX, 4);  // @0_42de30
  __builtin_memcpy((void *)(u32)(EBP - 288), &SENT_ESI, 4);  // @1_42de30
  __builtin_memcpy((void *)(u32)(EBP - 292), &SENT_EDI, 4);  // @2_42de30
  edi = ecx;  // @3_42de30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_42de30
  edx = (u32)(EBP - 276);  // @5_42de30
  p0_ = edx;  // @6_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @8_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790096), (u32)(p0_));  // @9_42de30
  ecx = edx = 0;  // @10_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42de84;  // @11_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 2489), &v, sizeof v); }  // @12_42de30
  L42de84:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_42de30
  edx = (u32)(EBP - 276);  // @15_42de30
  p1_ = edx;  // @16_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @18_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790112), (u32)(p1_));  // @19_42de30
  ecx = edx = 0;  // @20_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42deb3;  // @21_42de30
  T[0] = ((double(STDCALL *)(u32))(*(u32 *)0x6762d4))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @22_42de30
  ecx = edx = 0;  // @23_42de30
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(edi + 92), &v, 4); }  // @24_42de30
  L42deb3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_42de30
  edx = (u32)(EBP - 276);  // @27_42de30
  p2_ = edx;  // @28_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @30_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790124), (u32)(p2_));  // @31_42de30
  ecx = edx = 0;  // @32_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42df16;  // @33_42de30
  ecx = (u32)(EBP - 144);  // @34_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @35_42de30
  ecx = edx = 0;  // @36_42de30
  eax = (u32)(EBP - 144);  // @37_42de30
  reg.state = (s32)((u32)(0));  // @38_42de30
  p3_ = eax;  // @39_42de30
  ecx = (u32)(edi + 1187);  // @40_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p3_));  // @41_42de30
  ecx = edx = 0;  // @42_42de30
  ecx = (u32)(EBP - 144);  // @43_42de30
  reg.state = (s32)((u32)(4294967295));  // @44_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @45_42de30
  ecx = edx = 0;  // @46_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_42de30
  ecx = edi;  // @48_42de30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 416)))(ecx);  // @49_42de30
  ecx = edx = 0;  // @50_42de30
  L42df16:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_42de30
  edx = (u32)(EBP - 276);  // @53_42de30
  p4_ = edx;  // @54_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @56_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790136), (u32)(p4_));  // @57_42de30
  ecx = edx = 0;  // @58_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42dfda;  // @59_42de30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @60_42de30
  ebx = ecx;  // @61_42de30
  edx = (u32)(ebx + 1);  // @62_42de30
  L42df42:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) & 0xff);  // @64_42de30
  ebx = (ebx + 1);  // @65_42de30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42df42;  // @66_42de30
  ebx = (ebx - edx);  // @67_42de30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(34)) goto L42dfa3;  // @68_42de30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx - 1), sizeof v); (u32)v; }) != (u32)(34)) goto L42dfa3;  // @69_42de30
  eax = (u32)(ecx + 1);  // @70_42de30
  p5_ = eax;  // @71_42de30
  ecx = (u32)(EBP - 144);  // @72_42de30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p5_));  // @73_42de30
  ecx = edx = 0;  // @74_42de30
  eax = (u32)(EBP - 144);  // @75_42de30
  reg.state = (s32)((u32)(1));  // @76_42de30
  p6_ = eax;  // @77_42de30
  ecx = (u32)(edi + 675);  // @78_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p6_));  // @79_42de30
  ecx = edx = 0;  // @80_42de30
  ecx = (u32)(EBP - 144);  // @81_42de30
  reg.state = (s32)((u32)(4294967295));  // @82_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @83_42de30
  ecx = edx = 0;  // @84_42de30
  ecx = (u32)(edi + 675);  // @85_42de30
  eax = ext_4cc1d0_thiscall1(ecx);  // @86_42de30
  ecx = edx = 0;  // @87_42de30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ebx - 2), &v, sizeof v); }  // @88_42de30
  goto L42dfda;  // @89_42de30
  L42dfa3:;
  p7_ = ecx;  // @91_42de30
  ecx = (u32)(EBP - 144);  // @92_42de30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p7_));  // @93_42de30
  ecx = edx = 0;  // @94_42de30
  eax = (u32)(EBP - 144);  // @95_42de30
  reg.state = (s32)((u32)(2));  // @96_42de30
  p8_ = eax;  // @97_42de30
  ecx = (u32)(edi + 675);  // @98_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p8_));  // @99_42de30
  ecx = edx = 0;  // @100_42de30
  ecx = (u32)(EBP - 144);  // @101_42de30
  reg.state = (s32)((u32)(4294967295));  // @102_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @103_42de30
  ecx = edx = 0;  // @104_42de30
  L42dfda:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_42de30
  edx = (u32)(EBP - 276);  // @107_42de30
  p9_ = edx;  // @108_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @110_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6789968), (u32)(p9_));  // @111_42de30
  ecx = edx = 0;  // @112_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e034;  // @113_42de30
  eax = ext_41e290_cdecl1((u32)(4340));  // @114_42de30
  ecx = edx = 0;  // @115_42de30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @116_42de30
  reg.state = (s32)((u32)(3));  // @117_42de30
  if ((eax & eax) == 0) goto L42e020;  // @118_42de30
  ecx = eax;  // @119_42de30
  eax = ext_4d3e00_thiscall1(ecx);  // @120_42de30
  ecx = edx = 0;  // @121_42de30
  ecx = eax;  // @122_42de30
  goto L42e022;  // @123_42de30
  L42e020:;
  ecx = 0;  // @125_42de30
  L42e022:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @127_42de30
  p10_ = ecx;  // @128_42de30
  ecx = edi;  // @129_42de30
  reg.state = (s32)((u32)(4294967295));  // @130_42de30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 436)))(ecx, (u32)(p10_));  // @131_42de30
  ecx = edx = 0;  // @132_42de30
  L42e034:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_42de30
  edx = (u32)(EBP - 276);  // @135_42de30
  p11_ = edx;  // @136_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @138_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6789920), (u32)(p11_));  // @139_42de30
  ecx = edx = 0;  // @140_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e05f;  // @141_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 102), &v, sizeof v); }  // @142_42de30
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi + 2503), &v, sizeof v); }  // @143_42de30
  L42e05f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_42de30
  edx = (u32)(EBP - 276);  // @146_42de30
  p12_ = edx;  // @147_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @149_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6789940), (u32)(p12_));  // @150_42de30
  ecx = edx = 0;  // @151_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e083;  // @152_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 2488), &v, sizeof v); }  // @153_42de30
  L42e083:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @155_42de30
  edx = (u32)(EBP - 276);  // @156_42de30
  p13_ = edx;  // @157_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @158_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @159_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6789984), (u32)(p13_));  // @160_42de30
  ecx = edx = 0;  // @161_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e0a7;  // @162_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 6812), &v, sizeof v); }  // @163_42de30
  L42e0a7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @165_42de30
  edx = (u32)(EBP - 276);  // @166_42de30
  p14_ = edx;  // @167_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @168_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @169_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790152), (u32)(p14_));  // @170_42de30
  ecx = edx = 0;  // @171_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e0c8;  // @172_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 100), &v, sizeof v); }  // @173_42de30
  L42e0c8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @175_42de30
  edx = (u32)(EBP - 276);  // @176_42de30
  p15_ = edx;  // @177_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @179_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790168), (u32)(p15_));  // @180_42de30
  ecx = edx = 0;  // @181_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e0fa;  // @182_42de30
  eax = ((u32( *)(u32))(*(u32 *)0x6762e0))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @183_42de30
  ecx = edx = 0;  // @184_42de30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2467), &v, sizeof v); }  // @185_42de30
  L42e0fa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @187_42de30
  edx = (u32)(EBP - 276);  // @188_42de30
  p16_ = edx;  // @189_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @190_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @191_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790184), (u32)(p16_));  // @192_42de30
  ecx = edx = 0;  // @193_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e120;  // @194_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340960), sizeof v); (u32)v; });  // @195_42de30
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 116), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(eax + 116), &v, sizeof v); }  // @196_42de30
  L42e120:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @198_42de30
  edx = (u32)(EBP - 276);  // @199_42de30
  p17_ = edx;  // @200_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @201_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @202_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790196), (u32)(p17_));  // @203_42de30
  ecx = edx = 0;  // @204_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e179;  // @205_42de30
  ecx = (u32)(EBP - 144);  // @206_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @207_42de30
  ecx = edx = 0;  // @208_42de30
  eax = (u32)(EBP - 144);  // @209_42de30
  reg.state = (s32)((u32)(4));  // @210_42de30
  p18_ = eax;  // @211_42de30
  ecx = (u32)(edi + 2211);  // @212_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p18_));  // @213_42de30
  ecx = edx = 0;  // @214_42de30
  ecx = (u32)(EBP - 144);  // @215_42de30
  reg.state = (s32)((u32)(4294967295));  // @216_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @217_42de30
  ecx = edx = 0;  // @218_42de30
  L42e179:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @220_42de30
  edx = (u32)(EBP - 276);  // @221_42de30
  p19_ = edx;  // @222_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @223_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @224_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790208), (u32)(p19_));  // @225_42de30
  ecx = edx = 0;  // @226_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e1d2;  // @227_42de30
  ecx = (u32)(EBP - 144);  // @228_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @229_42de30
  ecx = edx = 0;  // @230_42de30
  eax = (u32)(EBP - 144);  // @231_42de30
  reg.state = (s32)((u32)(5));  // @232_42de30
  p20_ = eax;  // @233_42de30
  ecx = (u32)(edi + 1955);  // @234_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p20_));  // @235_42de30
  ecx = edx = 0;  // @236_42de30
  ecx = (u32)(EBP - 144);  // @237_42de30
  reg.state = (s32)((u32)(4294967295));  // @238_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @239_42de30
  ecx = edx = 0;  // @240_42de30
  L42e1d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @242_42de30
  edx = (u32)(EBP - 276);  // @243_42de30
  p21_ = edx;  // @244_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @245_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @246_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790224), (u32)(p21_));  // @247_42de30
  ecx = edx = 0;  // @248_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e22b;  // @249_42de30
  ecx = (u32)(EBP - 144);  // @250_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @251_42de30
  ecx = edx = 0;  // @252_42de30
  eax = (u32)(EBP - 144);  // @253_42de30
  reg.state = (s32)((u32)(6));  // @254_42de30
  p22_ = eax;  // @255_42de30
  ecx = (u32)(edi + 2083);  // @256_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p22_));  // @257_42de30
  ecx = edx = 0;  // @258_42de30
  ecx = (u32)(EBP - 144);  // @259_42de30
  reg.state = (s32)((u32)(4294967295));  // @260_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @261_42de30
  ecx = edx = 0;  // @262_42de30
  L42e22b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @264_42de30
  edx = (u32)(EBP - 276);  // @265_42de30
  p23_ = edx;  // @266_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @267_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @268_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790240), (u32)(p23_));  // @269_42de30
  ecx = edx = 0;  // @270_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e284;  // @271_42de30
  ecx = (u32)(EBP - 144);  // @272_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @273_42de30
  ecx = edx = 0;  // @274_42de30
  eax = (u32)(EBP - 144);  // @275_42de30
  reg.state = (s32)((u32)(7));  // @276_42de30
  p24_ = eax;  // @277_42de30
  ecx = (u32)(edi + 1827);  // @278_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p24_));  // @279_42de30
  ecx = edx = 0;  // @280_42de30
  ecx = (u32)(EBP - 144);  // @281_42de30
  reg.state = (s32)((u32)(4294967295));  // @282_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @283_42de30
  ecx = edx = 0;  // @284_42de30
  L42e284:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @286_42de30
  edx = (u32)(EBP - 276);  // @287_42de30
  p25_ = edx;  // @288_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @289_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @290_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790252), (u32)(p25_));  // @291_42de30
  ecx = edx = 0;  // @292_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e2dd;  // @293_42de30
  ecx = (u32)(EBP - 144);  // @294_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @295_42de30
  ecx = edx = 0;  // @296_42de30
  eax = (u32)(EBP - 144);  // @297_42de30
  reg.state = (s32)((u32)(8));  // @298_42de30
  p26_ = eax;  // @299_42de30
  ecx = (u32)(edi + 6423);  // @300_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p26_));  // @301_42de30
  ecx = edx = 0;  // @302_42de30
  ecx = (u32)(EBP - 144);  // @303_42de30
  reg.state = (s32)((u32)(4294967295));  // @304_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @305_42de30
  ecx = edx = 0;  // @306_42de30
  L42e2dd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @308_42de30
  edx = (u32)(EBP - 276);  // @309_42de30
  p27_ = edx;  // @310_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @311_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @312_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790268), (u32)(p27_));  // @313_42de30
  ecx = edx = 0;  // @314_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e2fe;  // @315_42de30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 104), &v, sizeof v); }  // @316_42de30
  L42e2fe:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @318_42de30
  edx = (u32)(EBP - 276);  // @319_42de30
  p28_ = edx;  // @320_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @321_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @322_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790276), (u32)(p28_));  // @323_42de30
  ecx = edx = 0;  // @324_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e445;  // @325_42de30
  ecx = (u32)(EBP - 144);  // @326_42de30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @327_42de30
  ecx = edx = 0;  // @328_42de30
  eax = (u32)(EBP - 144);  // @329_42de30
  reg.state = (s32)((u32)(9));  // @330_42de30
  p29_ = eax;  // @331_42de30
  ecx = (u32)(edi + 675);  // @332_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p29_));  // @333_42de30
  ecx = edx = 0;  // @334_42de30
  ecx = (u32)(EBP - 144);  // @335_42de30
  reg.state = (s32)((u32)(4294967295));  // @336_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @337_42de30
  ecx = edx = 0;  // @338_42de30
  ecx = (u32)(EBP - 144);  // @339_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @340_42de30
  ecx = edx = 0;  // @341_42de30
  eax = (u32)(EBP - 144);  // @342_42de30
  reg.state = (s32)((u32)(10));  // @343_42de30
  esi = (u32)(edi + 803);  // @344_42de30
  p30_ = eax;  // @345_42de30
  ecx = esi;  // @346_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p30_));  // @347_42de30
  ecx = edx = 0;  // @348_42de30
  ecx = (u32)(EBP - 144);  // @349_42de30
  reg.state = (s32)((u32)(4294967295));  // @350_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @351_42de30
  ecx = edx = 0;  // @352_42de30
  ecx = esi;  // @353_42de30
  eax = ext_4cc1d0_thiscall1(ecx);  // @354_42de30
  ecx = edx = 0;  // @355_42de30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(34)) goto L42e445;  // @356_42de30
  ecx = esi;  // @357_42de30
  eax = ext_4cc1d0_thiscall1(ecx);  // @358_42de30
  ecx = edx = 0;  // @359_42de30
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775380), sizeof v); (u32)v; });  // @360_42de30
  p31_ = eax;  // @361_42de30
  eax = ((u32( *)(u32, u32))(ebx))((u32)(p31_), (u32)(34));  // @362_42de30
  ecx = edx = 0;  // @363_42de30
  if ((eax & eax) == 0) goto L42e445;  // @364_42de30
  ecx = esi;  // @365_42de30
  eax = ext_4cc5f0_thiscall1(ecx);  // @366_42de30
  ecx = edx = 0;  // @367_42de30
  eax = ext_633c90_thiscall1(ecx);  // @368_42de30
  ecx = edx = 0;  // @369_42de30
  ecx = esi;  // @370_42de30
  { u32 v = (u32)((u32)(EBP + 4)); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @371_42de30
  eax = ext_4cc1d0_thiscall1(ecx);  // @372_42de30
  ecx = edx = 0;  // @373_42de30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @374_42de30
  ecx = (u32)(eax + 1);  // @375_42de30
  edx = (edx - ecx);  // @376_42de30
  L42e3f0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @378_42de30
  ecx = (u32)(ecx + 1);  // @379_42de30
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @380_42de30
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42e3f0;  // @381_42de30
  eax = ((u32( *)(u32, u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }), (u32)(34));  // @382_42de30
  ecx = edx = 0;  // @383_42de30
  ecx = (u32)(EBP - 144);  // @384_42de30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @385_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }));  // @386_42de30
  ecx = edx = 0;  // @387_42de30
  eax = (u32)(EBP - 144);  // @388_42de30
  reg.state = (s32)((u32)(11));  // @389_42de30
  p32_ = eax;  // @390_42de30
  ecx = esi;  // @391_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p32_));  // @392_42de30
  ecx = edx = 0;  // @393_42de30
  ecx = (u32)(EBP - 144);  // @394_42de30
  reg.state = (s32)((u32)(4294967295));  // @395_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @396_42de30
  ecx = edx = 0;  // @397_42de30
  L42e445:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @399_42de30
  edx = (u32)(EBP - 276);  // @400_42de30
  p33_ = edx;  // @401_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @402_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @403_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790288), (u32)(p33_));  // @404_42de30
  ecx = edx = 0;  // @405_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e4df;  // @406_42de30
  ecx = (u32)(EBP - 144);  // @407_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @408_42de30
  ecx = edx = 0;  // @409_42de30
  eax = (u32)(EBP - 144);  // @410_42de30
  reg.state = (s32)((u32)(12));  // @411_42de30
  esi = (u32)(edi + 291);  // @412_42de30
  p34_ = eax;  // @413_42de30
  ecx = esi;  // @414_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p34_));  // @415_42de30
  ecx = edx = 0;  // @416_42de30
  ecx = (u32)(EBP - 144);  // @417_42de30
  reg.state = (s32)((u32)(4294967295));  // @418_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @419_42de30
  ecx = edx = 0;  // @420_42de30
  p35_ = esi;  // @421_42de30
  ecx = edi;  // @422_42de30
  eax = ext_42da80_stdcall1((u32)(p35_));  // @423_42de30
  ecx = edx = 0;  // @424_42de30
  ecx = (u32)(EBP - 144);  // @425_42de30
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6790300));  // @426_42de30
  ecx = edx = 0;  // @427_42de30
  eax = (u32)(EBP - 144);  // @428_42de30
  reg.state = (s32)((u32)(13));  // @429_42de30
  p36_ = eax;  // @430_42de30
  ecx = esi;  // @431_42de30
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(p36_));  // @432_42de30
  ecx = edx = 0;  // @433_42de30
  ecx = (u32)(EBP - 144);  // @434_42de30
  reg.state = (s32)((u32)(4294967295));  // @435_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @436_42de30
  ecx = edx = 0;  // @437_42de30
  L42e4df:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @439_42de30
  edx = (u32)(EBP - 276);  // @440_42de30
  p37_ = edx;  // @441_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @442_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @443_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790308), (u32)(p37_));  // @444_42de30
  ecx = edx = 0;  // @445_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e549;  // @446_42de30
  ecx = (u32)(EBP - 144);  // @447_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @448_42de30
  ecx = edx = 0;  // @449_42de30
  eax = (u32)(EBP - 144);  // @450_42de30
  reg.state = (s32)((u32)(14));  // @451_42de30
  esi = (u32)(edi + 291);  // @452_42de30
  p38_ = eax;  // @453_42de30
  ecx = esi;  // @454_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p38_));  // @455_42de30
  ecx = edx = 0;  // @456_42de30
  ecx = (u32)(EBP - 144);  // @457_42de30
  reg.state = (s32)((u32)(4294967295));  // @458_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @459_42de30
  ecx = edx = 0;  // @460_42de30
  p39_ = esi;  // @461_42de30
  ecx = edi;  // @462_42de30
  eax = ext_42da80_stdcall1((u32)(p39_));  // @463_42de30
  ecx = edx = 0;  // @464_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 7003), &v, sizeof v); }  // @465_42de30
  L42e549:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @467_42de30
  edx = (u32)(EBP - 276);  // @468_42de30
  p40_ = edx;  // @469_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @470_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @471_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790324), (u32)(p40_));  // @472_42de30
  ecx = edx = 0;  // @473_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e5a2;  // @474_42de30
  ecx = (u32)(EBP - 144);  // @475_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @476_42de30
  ecx = edx = 0;  // @477_42de30
  eax = (u32)(EBP - 144);  // @478_42de30
  reg.state = (s32)((u32)(15));  // @479_42de30
  p41_ = eax;  // @480_42de30
  ecx = (u32)(edi + 419);  // @481_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p41_));  // @482_42de30
  ecx = edx = 0;  // @483_42de30
  ecx = (u32)(EBP - 144);  // @484_42de30
  reg.state = (s32)((u32)(4294967295));  // @485_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @486_42de30
  ecx = edx = 0;  // @487_42de30
  L42e5a2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @489_42de30
  edx = (u32)(EBP - 276);  // @490_42de30
  p42_ = edx;  // @491_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @492_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @493_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783552), (u32)(p42_));  // @494_42de30
  ecx = edx = 0;  // @495_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e5f5;  // @496_42de30
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @497_42de30
  ecx = edx = 0;  // @498_42de30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 151), &v, sizeof v); }  // @499_42de30
  if ((s32)(eax & eax) >= 0) goto L42e5e2;  // @500_42de30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 151), &v, sizeof v); }  // @501_42de30
  L42e5e2:;
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 151), sizeof v); (u32)v; }) <= (s32)(u32)(2)) goto L42e5f5;  // @503_42de30
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 151), &v, sizeof v); }  // @504_42de30
  L42e5f5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @506_42de30
  edx = (u32)(EBP - 276);  // @507_42de30
  p43_ = edx;  // @508_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @509_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @510_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790336), (u32)(p43_));  // @511_42de30
  ecx = edx = 0;  // @512_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e61b;  // @513_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @514_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 78), &v, sizeof v); }  // @515_42de30
  L42e61b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @517_42de30
  edx = (u32)(EBP - 276);  // @518_42de30
  p44_ = edx;  // @519_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @520_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @521_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790348), (u32)(p44_));  // @522_42de30
  ecx = edx = 0;  // @523_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e63f;  // @524_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 6973), &v, sizeof v); }  // @525_42de30
  L42e63f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @527_42de30
  edx = (u32)(EBP - 276);  // @528_42de30
  p45_ = edx;  // @529_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @530_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @531_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790368), (u32)(p45_));  // @532_42de30
  ecx = edx = 0;  // @533_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e663;  // @534_42de30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 6971), &v, sizeof v); }  // @535_42de30
  L42e663:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @537_42de30
  edx = (u32)(EBP - 276);  // @538_42de30
  p46_ = edx;  // @539_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @540_42de30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @541_42de30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790392), (u32)(p46_));  // @542_42de30
  ecx = edx = 0;  // @543_42de30
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42e6c6;  // @544_42de30
  ecx = (u32)(EBP - 272);  // @545_42de30
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @546_42de30
  ecx = edx = 0;  // @547_42de30
  eax = (u32)(EBP - 272);  // @548_42de30
  reg.state = (s32)((u32)(16));  // @549_42de30
  esi = (u32)(edi + 547);  // @550_42de30
  p47_ = eax;  // @551_42de30
  ecx = esi;  // @552_42de30
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p47_));  // @553_42de30
  ecx = edx = 0;  // @554_42de30
  ecx = (u32)(EBP - 272);  // @555_42de30
  reg.state = (s32)((u32)(4294967295));  // @556_42de30
  eax = ext_4cbec0_thiscall1(ecx);  // @557_42de30
  ecx = edx = 0;  // @558_42de30
  p48_ = esi;  // @559_42de30
  ecx = edi;  // @560_42de30
  eax = ext_42da80_stdcall1((u32)(p48_));  // @561_42de30
  ecx = edx = 0;  // @562_42de30
  L42e6c6:;
  SEH_LEAVE();  // @564_42de30
  ext_633654(G(u32, 0x6f5630));  // @565_42de30
  return eax;  // @566_42de30
}
PCREG(42de30, lifted_42de30);

