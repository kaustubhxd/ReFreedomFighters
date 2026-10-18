// batch200168.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_42adc0_fastcall2(u32, u32) __asm__("ext_42adc0");
extern "C" u32 FASTCALL ext_42aee0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42aee0");
extern "C" u32 FASTCALL ext_42afb0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42afb0");
extern "C" u32 FASTCALL ext_42b080_fastcall3(u32, u32, u32) __asm__("ext_42b080");
extern "C" u32 FASTCALL ext_42b160_fastcall4(u32, u32, u32, u32) __asm__("ext_42b160");
extern "C" u32 STDCALL ext_4309b0_stdcall1(u32) __asm__("ext_4309b0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_42b0f0_thiscall4(u32, u32, u32, u32) __asm__("ext_42b0f0");
extern "C" u32 THISCALL ext_42b290_thiscall2(u32, u32) __asm__("ext_42b290");
extern "C" u32 THISCALL ext_42b390_thiscall3(u32, u32, u32) __asm__("ext_42b390");
extern "C" u32 THISCALL ext_42ba10_thiscall1(u32) __asm__("ext_42ba10");
extern "C" u32 THISCALL ext_42bdf0_thiscall2(u32, u32) __asm__("ext_42bdf0");
extern "C" u32 THISCALL ext_42be20_thiscall2(u32, u32) __asm__("ext_42be20");
extern "C" u32 THISCALL ext_430a20_thiscall3(u32, u32, u32) __asm__("ext_430a20");
extern "C" u32 THISCALL ext_430cd0_thiscall3(u32, u32, u32) __asm__("ext_430cd0");
extern "C" u32 THISCALL ext_431110_thiscall3(u32, u32, u32) __asm__("ext_431110");
extern "C" u32 THISCALL ext_4311f0_thiscall2(u32, u32) __asm__("ext_4311f0");
extern "C" u32 THISCALL ext_4312f0_thiscall4(u32, u32, u32, u32) __asm__("ext_4312f0");
extern "C" u32 THISCALL ext_431330_thiscall3(u32, u32, u32) __asm__("ext_431330");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc180_thiscall2(u32, u32) __asm__("ext_4cc180");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f2d60_thiscall3(u32, u32, u32) __asm__("ext_5f2d60");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

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

extern "C" u32 THISCALL lifted_42d420(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664e4c);  // @h_42d420
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 52), &SENT_EBX, 4);  // @0_42d420
  __builtin_memcpy((void *)(u32)(EBP - 56), &SENT_ESI, 4);  // @1_42d420
  __builtin_memcpy((void *)(u32)(EBP - 60), &SENT_EDI, 4);  // @2_42d420
  ebx = ecx;  // @3_42d420
  eax = (u32)(EBP - 13);  // @4_42d420
  p0_ = eax;  // @5_42d420
  ecx = (u32)(EBP - 36);  // @6_42d420
  eax = ext_42b390_thiscall3(ecx, (u32)(6781786), (u32)(p0_));  // @7_42d420
  ecx = edx = 0;  // @8_42d420
  eax = (u32)(EBP - 13);  // @9_42d420
  reg.state = (s32)((u32)(0));  // @10_42d420
  p1_ = eax;  // @11_42d420
  ecx = (u32)(EBP - 48);  // @12_42d420
  eax = ext_42b390_thiscall3(ecx, (u32)(6790740), (u32)(p1_));  // @13_42d420
  ecx = edx = 0;  // @14_42d420
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @16_42d420
  reg.state = (s32)((u32)(1));  // @17_42d420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_42d420
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d48c;  // @19_42d420
  eax = (u32)(ecx + 12);  // @20_42d420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @21_42d420
  L42d48c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @23_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @24_42d420
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == eax) goto L42d4c3;  // @25_42d420
  L42d4a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @28_42d420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_42d420
  eax = (eax - edx);  // @30_42d420
  if (eax != (u32)(1)) goto L42d4c3;  // @31_42d420
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(32)) goto L42d4c3;  // @32_42d420
  ecx = (ecx + (u32)(12));  // @33_42d420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @34_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @35_42d420
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d4a0;  // @36_42d420
  L42d4c3:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @39_42d420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_42d420
  eax = (eax - ecx);  // @41_42d420
  if (eax != (u32)(1)) goto L42d4e0;  // @42_42d420
  p2_ = eax;  // @43_42d420
  edx = (u32)(6777860);  // @44_42d420
  eax = ext_4309b0_stdcall1((u32)(p2_));  // @45_42d420
  ecx = edx = 0;  // @46_42d420
  if ((eax & eax) == 0) goto L42d4f6;  // @47_42d420
  L42d4e0:;
  eax = (u32)(EBP - 36);  // @49_42d420
  if (edi == eax) goto L42d4f3;  // @50_42d420
  ecx = eax;  // @51_42d420
  eax = ext_5f2d60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @52_42d420
  ecx = edx = 0;  // @53_42d420
  L42d4f3:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @55_42d420
  L42d4f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @57_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @58_42d420
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == eax) goto L42d526;  // @59_42d420
  L42d503:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @61_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @62_42d420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_42d420
  eax = (eax - edx);  // @64_42d420
  if (eax != (u32)(1)) goto L42d516;  // @65_42d420
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == (u32)(10)) goto L42d526;  // @66_42d420
  L42d516:;
  ecx = (ecx + (u32)(12));  // @68_42d420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @69_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @70_42d420
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d503;  // @71_42d420
  L42d526:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @73_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @74_42d420
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == eax) goto L42d556;  // @75_42d420
  L42d533:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @78_42d420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_42d420
  eax = (eax - edx);  // @80_42d420
  if (eax != (u32)(1)) goto L42d556;  // @81_42d420
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(10)) goto L42d556;  // @82_42d420
  ecx = (ecx + (u32)(12));  // @83_42d420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @84_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @85_42d420
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d533;  // @86_42d420
  L42d556:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7013), sizeof v); (u32)v; });  // @88_42d420
  eax = (u32)(EBP - 36);  // @89_42d420
  p3_ = eax;  // @90_42d420
  eax = (u32)(EBP - 17);  // @91_42d420
  ecx = ebx;  // @92_42d420
  p4_ = eax;  // @93_42d420
  eax = ext_431330_thiscall3(ecx, (u32)(p4_), (u32)(p3_));  // @94_42d420
  ecx = edx = 0;  // @95_42d420
  esi = eax;  // @96_42d420
  ecx = ebx;  // @97_42d420
  eax = (u32)(EBP - 36);  // @98_42d420
  p5_ = eax;  // @99_42d420
  eax = (u32)(EBP - 21);  // @100_42d420
  p6_ = eax;  // @101_42d420
  eax = ext_431110_thiscall3(ecx, (u32)(p6_), (u32)(p5_));  // @102_42d420
  ecx = edx = 0;  // @103_42d420
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_42d420
  ecx = (u32)(EBP + 8);  // @105_42d420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @106_42d420
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @107_42d420
  p7_ = ecx;  // @108_42d420
  eax = (u32)(EBP + 4);  // @109_42d420
  p8_ = ecx;  // @110_42d420
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @111_42d420
  eax = (u32)(EBP + 4);  // @112_42d420
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @113_42d420
  eax = ext_42b0f0_thiscall4(ecx, (u32)(p8_), (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @114_42d420
  ecx = edx = 0;  // @115_42d420
  p9_ = ecx;  // @116_42d420
  eax = (u32)(EBP + 4);  // @117_42d420
  p10_ = ecx;  // @118_42d420
  ecx = ebx;  // @119_42d420
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @120_42d420
  eax = (u32)(EBP + 4);  // @121_42d420
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @122_42d420
  eax = ext_430a20_thiscall3(ecx, (u32)(p10_), (u32)(p9_));  // @123_42d420
  ecx = edx = 0;  // @124_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @125_42d420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @126_42d420
  eax = (eax - ecx);  // @127_42d420
  reg.state = (s32)((u32)(2));  // @128_42d420
  if ((ecx & ecx) == 0) goto L42d5cb;  // @129_42d420
  if ((eax & eax) == 0) goto L42d5cb;  // @130_42d420
  p11_ = eax;  // @131_42d420
  p12_ = ecx;  // @132_42d420
  ecx = (u32)(EBP - 48);  // @133_42d420
  eax = ext_54f870_stdcall2((u32)(p12_), (u32)(p11_));  // @134_42d420
  ecx = edx = 0;  // @135_42d420
  L42d5cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @137_42d420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @138_42d420
  eax = (eax - ecx);  // @139_42d420
  reg.state = (s32)((u32)(3));  // @140_42d420
  if ((ecx & ecx) == 0) goto L42d5ec;  // @141_42d420
  if ((eax & eax) == 0) goto L42d5ec;  // @142_42d420
  p13_ = eax;  // @143_42d420
  p14_ = ecx;  // @144_42d420
  ecx = (u32)(EBP - 36);  // @145_42d420
  eax = ext_54f870_stdcall2((u32)(p14_), (u32)(p13_));  // @146_42d420
  ecx = edx = 0;  // @147_42d420
  L42d5ec:;
  SEH_LEAVE();  // @149_42d420
  return eax;  // @150_42d420
}
PCREG(42d420, lifted_42d420);

extern "C" u32 THISCALL lifted_42d000(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664e0c);  // @h_42d000
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 44), &SENT_EBX, 4);  // @0_42d000
  __builtin_memcpy((void *)(u32)(EBP - 48), &SENT_ESI, 4);  // @1_42d000
  __builtin_memcpy((void *)(u32)(EBP - 52), &SENT_EDI, 4);  // @2_42d000
  edi = ecx;  // @3_42d000
  eax = (u32)(EBP - 13);  // @4_42d000
  p0_ = eax;  // @5_42d000
  ecx = (u32)(EBP - 40);  // @6_42d000
  eax = ext_42b390_thiscall3(ecx, (u32)(6781786), (u32)(p0_));  // @7_42d000
  ecx = edx = 0;  // @8_42d000
  eax = (u32)(EBP - 13);  // @9_42d000
  reg.state = (s32)((u32)(0));  // @10_42d000
  p1_ = eax;  // @11_42d000
  ecx = (u32)(EBP - 28);  // @12_42d000
  eax = ext_42b390_thiscall3(ecx, (u32)(6781786), (u32)(p1_));  // @13_42d000
  ecx = edx = 0;  // @14_42d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @16_42d000
  reg.state = (s32)((u32)(1));  // @17_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_42d000
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d06c;  // @19_42d000
  eax = (u32)(ecx + 12);  // @20_42d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @21_42d000
  L42d06c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @23_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @24_42d000
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == eax) goto L42d0a3;  // @25_42d000
  L42d080:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @28_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_42d000
  eax = (eax - edx);  // @30_42d000
  if (eax != (u32)(1)) goto L42d0a3;  // @31_42d000
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(32)) goto L42d0a3;  // @32_42d000
  ecx = (ecx + (u32)(12));  // @33_42d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @34_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @35_42d000
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d080;  // @36_42d000
  L42d0a3:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @39_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @40_42d000
  eax = (eax - ecx);  // @41_42d000
  if (eax != (u32)(1)) goto L42d0c0;  // @42_42d000
  p2_ = eax;  // @43_42d000
  edx = (u32)(6777860);  // @44_42d000
  eax = ext_4309b0_stdcall1((u32)(p2_));  // @45_42d000
  ecx = edx = 0;  // @46_42d000
  if ((eax & eax) == 0) goto L42d0d6;  // @47_42d000
  L42d0c0:;
  eax = (u32)(EBP - 40);  // @49_42d000
  if (ebx == eax) goto L42d0d3;  // @50_42d000
  ecx = eax;  // @51_42d000
  eax = ext_5f2d60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }));  // @52_42d000
  ecx = edx = 0;  // @53_42d000
  L42d0d3:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @55_42d000
  L42d0d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @57_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @58_42d000
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == eax) goto L42d106;  // @59_42d000
  L42d0e3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @61_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @62_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_42d000
  eax = (eax - edx);  // @64_42d000
  if (eax != (u32)(1)) goto L42d106;  // @65_42d000
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(32)) goto L42d106;  // @66_42d000
  ecx = (ecx + (u32)(12));  // @67_42d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @68_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @69_42d000
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d0e3;  // @70_42d000
  L42d106:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @72_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_42d000
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d190;  // @74_42d000
  L42d113:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @76_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_42d000
  eax = (eax - edx);  // @78_42d000
  if (eax != (u32)(1)) goto L42d124;  // @79_42d000
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == (u32)(10)) goto L42d190;  // @80_42d000
  L42d124:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @82_42d000
  eax = (eax - edx);  // @83_42d000
  if (eax != (u32)(1)) goto L42d133;  // @84_42d000
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == (u32)(32)) goto L42d190;  // @85_42d000
  L42d133:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @87_42d000
  eax = (eax - edx);  // @88_42d000
  if (eax != (u32)(1)) goto L42d174;  // @89_42d000
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(36)) goto L42d174;  // @90_42d000
  eax = (u32)(ecx + 12);  // @91_42d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @92_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @93_42d000
  p3_ = eax;  // @94_42d000
  eax = ext_42be20_thiscall2(ecx, (u32)(p3_));  // @95_42d000
  ecx = edx = 0;  // @96_42d000
  ecx = (u32)(EBP - 28);  // @97_42d000
  eax = ext_5f2c60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @98_42d000
  ecx = edx = 0;  // @99_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @100_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @101_42d000
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d183;  // @102_42d000
  eax = (u32)(ecx + 12);  // @103_42d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @104_42d000
  goto L42d183;  // @105_42d000
  L42d174:;
  ecx = (u32)(EBP - 28);  // @107_42d000
  p4_ = edx;  // @108_42d000
  eax = ext_5f2c60_thiscall3(ecx, (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }));  // @109_42d000
  ecx = edx = 0;  // @110_42d000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @111_42d000
  L42d183:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @113_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_42d000
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d113;  // @115_42d000
  L42d190:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @117_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @118_42d000
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == eax) goto L42d1c3;  // @119_42d000
  L42d1a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @122_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_42d000
  eax = (eax - edx);  // @124_42d000
  if (eax != (u32)(1)) goto L42d1b3;  // @125_42d000
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) == (u32)(10)) goto L42d1c3;  // @126_42d000
  L42d1b3:;
  ecx = (ecx + (u32)(12));  // @128_42d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @129_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @130_42d000
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d1a0;  // @131_42d000
  L42d1c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @133_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @134_42d000
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == eax) goto L42d1f3;  // @135_42d000
  L42d1d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @138_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_42d000
  eax = (eax - edx);  // @140_42d000
  if (eax != (u32)(1)) goto L42d1f3;  // @141_42d000
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(10)) goto L42d1f3;  // @142_42d000
  ecx = (ecx + (u32)(12));  // @143_42d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @144_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @145_42d000
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) goto L42d1d0;  // @146_42d000
  L42d1f3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @148_42d000
  eax = (u32)(EBP - 40);  // @149_42d000
  p5_ = eax;  // @150_42d000
  eax = ext_42be20_thiscall2(ecx, (u32)(p5_));  // @151_42d000
  ecx = edx = 0;  // @152_42d000
  ecx = (u32)(EBP - 28);  // @153_42d000
  if (ecx == eax) goto L42d216;  // @154_42d000
  ecx = eax;  // @155_42d000
  eax = ext_5f2d60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @156_42d000
  ecx = edx = 0;  // @157_42d000
  L42d216:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @159_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @160_42d000
  eax = (eax - ecx);  // @161_42d000
  reg.state = (s32)((u32)(2));  // @162_42d000
  if ((ecx & ecx) == 0) goto L42d234;  // @163_42d000
  if ((eax & eax) == 0) goto L42d234;  // @164_42d000
  p6_ = eax;  // @165_42d000
  p7_ = ecx;  // @166_42d000
  ecx = (u32)(EBP - 28);  // @167_42d000
  eax = ext_54f870_stdcall2((u32)(p7_), (u32)(p6_));  // @168_42d000
  ecx = edx = 0;  // @169_42d000
  L42d234:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @171_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @172_42d000
  eax = (eax - ecx);  // @173_42d000
  reg.state = (s32)((u32)(3));  // @174_42d000
  if ((ecx & ecx) == 0) goto L42d255;  // @175_42d000
  if ((eax & eax) == 0) goto L42d255;  // @176_42d000
  p8_ = eax;  // @177_42d000
  p9_ = ecx;  // @178_42d000
  ecx = (u32)(EBP - 40);  // @179_42d000
  eax = ext_54f870_stdcall2((u32)(p9_), (u32)(p8_));  // @180_42d000
  ecx = edx = 0;  // @181_42d000
  L42d255:;
  SEH_LEAVE();  // @183_42d000
  return eax;  // @184_42d000
}
PCREG(42d000, lifted_42d000);

extern "C" u32 THISCALL lifted_42f320(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66519e);  // @h_42f320
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 204), &SENT_EBX, 4);  // @0_42f320
  __builtin_memcpy((void *)(u32)(EBP - 208), &SENT_ESI, 4);  // @1_42f320
  __builtin_memcpy((void *)(u32)(EBP - 212), &SENT_EDI, 4);  // @2_42f320
  edi = ecx;  // @3_42f320
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_42f320
  ecx = (u32)(EBP - 156);  // @5_42f320
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @6_42f320
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @7_42f320
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @8_42f320
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @9_42f320
  eax = ext_6014a0_stdcall1((u32)(8));  // @10_42f320
  ecx = edx = 0;  // @11_42f320
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @12_42f320
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @13_42f320
  ecx = (u32)(eax + 8);  // @14_42f320
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @15_42f320
  if ((eax & eax) == 0) goto L42f3a0;  // @16_42f320
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @17_42f320
  L42f3a0:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @19_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_42f320
  ecx = (u32)(EBP - 156);  // @21_42f320
  p0_ = ecx;  // @22_42f320
  p1_ = ebx;  // @23_42f320
  ecx = edi;  // @24_42f320
  reg.state = (s32)((u32)(0));  // @25_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, (u32)(p1_), (u32)(p0_));  // @26_42f320
  ecx = edx = 0;  // @27_42f320
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @28_42f320
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @29_42f320
  if (esi == ebx) goto L42f68f;  // @30_42f320
  ebx = (ebx - esi);  // @31_42f320
  if (ebx != (u32)(2)) goto L42f410;  // @32_42f320
  p2_ = ebx;  // @33_42f320
  edx = (u32)(6790724);  // @34_42f320
  ecx = esi;  // @35_42f320
  eax = ext_4309b0_stdcall1((u32)(p2_));  // @36_42f320
  ecx = edx = 0;  // @37_42f320
  if ((eax & eax) != 0) goto L42f410;  // @38_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_42f320
  ecx = (u32)(EBP - 156);  // @40_42f320
  p3_ = ecx;  // @41_42f320
  ecx = edi;  // @42_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }), (u32)(p3_));  // @43_42f320
  ecx = edx = 0;  // @44_42f320
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7017), sizeof v); (u32)v; });  // @45_42f320
  eax = (u32)(EBP - 156);  // @46_42f320
  p4_ = eax;  // @47_42f320
  eax = ext_4311f0_thiscall2(ecx, (u32)(p4_));  // @48_42f320
  ecx = edx = 0;  // @49_42f320
  goto L42f689;  // @50_42f320
  L42f410:;
  if (ebx != (u32)(8)) goto L42f42a;  // @52_42f320
  p5_ = ebx;  // @53_42f320
  edx = (u32)(6790472);  // @54_42f320
  ecx = esi;  // @55_42f320
  eax = ext_4309b0_stdcall1((u32)(p5_));  // @56_42f320
  ecx = edx = 0;  // @57_42f320
  if ((eax & eax) == 0) goto L42f68f;  // @58_42f320
  L42f42a:;
  if (ebx != (u32)(2)) goto L42f48b;  // @60_42f320
  p6_ = ebx;  // @61_42f320
  edx = (u32)(6790728);  // @62_42f320
  ecx = esi;  // @63_42f320
  eax = ext_4309b0_stdcall1((u32)(p6_));  // @64_42f320
  ecx = edx = 0;  // @65_42f320
  if ((eax & eax) != 0) goto L42f48b;  // @66_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @67_42f320
  ecx = (u32)(EBP - 156);  // @68_42f320
  p7_ = ecx;  // @69_42f320
  ecx = edi;  // @70_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }), (u32)(p7_));  // @71_42f320
  ecx = edx = 0;  // @72_42f320
  ecx = (u32)(EBP - 144);  // @73_42f320
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; }));  // @74_42f320
  ecx = edx = 0;  // @75_42f320
  eax = (u32)(EBP - 144);  // @76_42f320
  reg.state = (s32)((u32)(1));  // @77_42f320
  p8_ = eax;  // @78_42f320
  ecx = (u32)(edi + 6679);  // @79_42f320
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p8_));  // @80_42f320
  ecx = edx = 0;  // @81_42f320
  ecx = (u32)(EBP - 144);  // @82_42f320
  eax = ext_4cbec0_thiscall1(ecx);  // @83_42f320
  ecx = edx = 0;  // @84_42f320
  goto L42f689;  // @85_42f320
  L42f48b:;
  edx = (u32)(6790732);  // @87_42f320
  ecx = (u32)(EBP - 156);  // @88_42f320
  eax = ext_42adc0_fastcall2(ecx, edx);  // @89_42f320
  ecx = edx = 0;  // @90_42f320
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42f543;  // @91_42f320
  edx = (u32)(6790736);  // @92_42f320
  ecx = (u32)(EBP - 156);  // @93_42f320
  eax = ext_42adc0_fastcall2(ecx, edx);  // @94_42f320
  ecx = edx = 0;  // @95_42f320
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42f543;  // @96_42f320
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(64)) goto L42f515;  // @97_42f320
  eax = (u32)(ebx - 1);  // @98_42f320
  p9_ = eax;  // @99_42f320
  eax = (u32)(EBP - 188);  // @100_42f320
  p10_ = eax;  // @101_42f320
  ecx = (u32)(EBP - 156);  // @102_42f320
  eax = ext_4312f0_thiscall4(ecx, (u32)(p10_), (u32)(1), (u32)(p9_));  // @103_42f320
  ecx = edx = 0;  // @104_42f320
  ecx = (u32)(EBP - 144);  // @105_42f320
  reg.state = (s32)((u32)(6));  // @106_42f320
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @107_42f320
  ecx = edx = 0;  // @108_42f320
  eax = (u32)(EBP - 144);  // @109_42f320
  reg.state = (s32)((u32)(7));  // @110_42f320
  p11_ = eax;  // @111_42f320
  ecx = (u32)(edi + 6679);  // @112_42f320
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p11_));  // @113_42f320
  ecx = edx = 0;  // @114_42f320
  ecx = (u32)(EBP - 144);  // @115_42f320
  eax = ext_4cbec0_thiscall1(ecx);  // @116_42f320
  ecx = edx = 0;  // @117_42f320
  ecx = (u32)(EBP - 188);  // @118_42f320
  goto L42f684;  // @119_42f320
  L42f515:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @121_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(1091));  // @123_42f320
  ecx = edx = 0;  // @124_42f320
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @125_42f320
  p12_ = eax;  // @126_42f320
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p12_), (u32)(6790744), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; }));  // @127_42f320
  ecx = edx = 0;  // @128_42f320
  goto L42f689;  // @129_42f320
  L42f543:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @131_42f320
  ecx = (u32)(EBP - 156);  // @132_42f320
  p13_ = ecx;  // @133_42f320
  ecx = edi;  // @134_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }), (u32)(p13_));  // @135_42f320
  ecx = edx = 0;  // @136_42f320
  ecx = (u32)(EBP - 156);  // @137_42f320
  eax = ext_430cd0_thiscall3(ecx, (u32)(61), (u32)(0));  // @138_42f320
  ecx = edx = 0;  // @139_42f320
  esi = eax;  // @140_42f320
  if (esi != (u32)(-1)) goto L42f590;  // @141_42f320
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @142_42f320
  eax = (u32)(EBP - 156);  // @143_42f320
  p14_ = eax;  // @144_42f320
  eax = ext_42be20_thiscall2(ecx, (u32)(p14_));  // @145_42f320
  ecx = edx = 0;  // @146_42f320
  ecx = eax;  // @147_42f320
  eax = ext_42bdf0_thiscall2(ecx, (u32)(6790740));  // @148_42f320
  ecx = edx = 0;  // @149_42f320
  goto L42f689;  // @150_42f320
  L42f590:;
  eax = (u32)(EBP - 157);  // @152_42f320
  p15_ = eax;  // @153_42f320
  ecx = (u32)(EBP - 200);  // @154_42f320
  eax = ext_42b290_thiscall2(ecx, (u32)(p15_));  // @155_42f320
  ecx = edx = 0;  // @156_42f320
  eax = (u32)(EBP - 157);  // @157_42f320
  reg.state = (s32)((u32)(2));  // @158_42f320
  p16_ = eax;  // @159_42f320
  ecx = (u32)(EBP - 176);  // @160_42f320
  eax = ext_42b290_thiscall2(ecx, (u32)(p16_));  // @161_42f320
  ecx = edx = 0;  // @162_42f320
  p17_ = esi;  // @163_42f320
  eax = (u32)(EBP - 188);  // @164_42f320
  reg.state = (s32)((u32)(3));  // @165_42f320
  p18_ = eax;  // @166_42f320
  ecx = (u32)(EBP - 156);  // @167_42f320
  eax = ext_4312f0_thiscall4(ecx, (u32)(p18_), (u32)(0), (u32)(p17_));  // @168_42f320
  ecx = edx = 0;  // @169_42f320
  ecx = (u32)(EBP - 200);  // @170_42f320
  reg.state = (s32)((u32)(4));  // @171_42f320
  if (eax == ecx) goto L42f5e9;  // @172_42f320
  eax = ext_5f2d60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @173_42f320
  ecx = edx = 0;  // @174_42f320
  L42f5e9:;
  ecx = (u32)(EBP - 188);  // @176_42f320
  reg.state = (s32)((u32)(3));  // @177_42f320
  eax = ext_42ba10_thiscall1(ecx);  // @178_42f320
  ecx = edx = 0;  // @179_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @180_42f320
  ecx = (u32)(EBP - 156);  // @181_42f320
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; }));  // @182_42f320
  eax = (eax - esi);  // @183_42f320
  p19_ = eax;  // @184_42f320
  eax = (u32)(esi + 1);  // @185_42f320
  p20_ = eax;  // @186_42f320
  eax = (u32)(EBP - 188);  // @187_42f320
  p21_ = eax;  // @188_42f320
  eax = ext_4312f0_thiscall4(ecx, (u32)(p21_), (u32)(p20_), (u32)(p19_));  // @189_42f320
  ecx = edx = 0;  // @190_42f320
  ecx = (u32)(EBP - 176);  // @191_42f320
  reg.state = (s32)((u32)(5));  // @192_42f320
  if (eax == ecx) goto L42f635;  // @193_42f320
  eax = ext_5f2d60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @194_42f320
  ecx = edx = 0;  // @195_42f320
  L42f635:;
  ecx = (u32)(EBP - 188);  // @197_42f320
  reg.state = (s32)((u32)(3));  // @198_42f320
  eax = ext_42ba10_thiscall1(ecx);  // @199_42f320
  ecx = edx = 0;  // @200_42f320
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @201_42f320
  eax = (u32)(EBP - 200);  // @202_42f320
  p22_ = eax;  // @203_42f320
  eax = ext_42be20_thiscall2(ecx, (u32)(p22_));  // @204_42f320
  ecx = edx = 0;  // @205_42f320
  ecx = (u32)(EBP - 176);  // @206_42f320
  if (ecx == eax) goto L42f673;  // @207_42f320
  ecx = eax;  // @208_42f320
  eax = ext_5f2d60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; }));  // @209_42f320
  ecx = edx = 0;  // @210_42f320
  L42f673:;
  ecx = (u32)(EBP - 176);  // @212_42f320
  eax = ext_42ba10_thiscall1(ecx);  // @213_42f320
  ecx = edx = 0;  // @214_42f320
  ecx = (u32)(EBP - 200);  // @215_42f320
  L42f684:;
  eax = ext_42ba10_thiscall1(ecx);  // @217_42f320
  ecx = edx = 0;  // @218_42f320
  L42f689:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @220_42f320
  L42f68f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @222_42f320
  eax = (eax - esi);  // @223_42f320
  reg.state = (s32)((u32)(8));  // @224_42f320
  if ((esi & esi) == 0) goto L42f6b3;  // @225_42f320
  if ((eax & eax) == 0) goto L42f6b3;  // @226_42f320
  p23_ = eax;  // @227_42f320
  p24_ = esi;  // @228_42f320
  ecx = (u32)(EBP - 156);  // @229_42f320
  eax = ext_54f870_stdcall2((u32)(p24_), (u32)(p23_));  // @230_42f320
  ecx = edx = 0;  // @231_42f320
  L42f6b3:;
  SEH_LEAVE();  // @233_42f320
  ext_633654(G(u32, 0x6f5630));  // @234_42f320
  return eax;  // @235_42f320
}
PCREG(42f320, lifted_42f320);

extern "C" u32 THISCALL lifted_42ee70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665118);  // @h_42ee70
  u8 F[0x4260] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x4160);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4160 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 16316), &SENT_EBX, 4);  // @0_42ee70
  __builtin_memcpy((void *)(u32)(EBP - 16320), &SENT_ESI, 4);  // @1_42ee70
  __builtin_memcpy((void *)(u32)(EBP - 16324), &SENT_EDI, 4);  // @2_42ee70
  ebx = ecx;  // @3_42ee70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16308), &v, sizeof v); }  // @4_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_42ee70
  ecx = (u32)(EBP - 16272);  // @6_42ee70
  p0_ = eax;  // @7_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16292), &v, sizeof v); }  // @8_42ee70
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @9_42ee70
  ecx = edx = 0;  // @10_42ee70
  ecx = (u32)(EBP - 16272);  // @11_42ee70
  reg.state = (s32)((u32)(0));  // @12_42ee70
  eax = ext_4cc1d0_thiscall1(ecx);  // @13_42ee70
  ecx = edx = 0;  // @14_42ee70
  ecx = (u32)(EBP - 16144);  // @15_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16288), &v, sizeof v); }  // @16_42ee70
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @17_42ee70
  ecx = edx = 0;  // @18_42ee70
  eax = (u32)(ebx + 6679);  // @19_42ee70
  reg.state = (s32)((u32)(1));  // @20_42ee70
  ecx = (u32)(EBP - 16144);  // @21_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16312), &v, sizeof v); }  // @22_42ee70
  p1_ = ecx;  // @23_42ee70
  ecx = eax;  // @24_42ee70
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @25_42ee70
  ecx = edx = 0;  // @26_42ee70
  ecx = (u32)(EBP - 16144);  // @27_42ee70
  reg.state = (s32)((u32)(0));  // @28_42ee70
  eax = ext_4cbec0_thiscall1(ecx);  // @29_42ee70
  ecx = edx = 0;  // @30_42ee70
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7017), sizeof v); (u32)v; });  // @31_42ee70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @32_42ee70
  edx = edi;  // @33_42ee70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @34_42ee70
  ecx = edi;  // @35_42ee70
  p2_ = esi;  // @36_42ee70
  eax = ext_42aee0_fastcall5(ecx, edx, (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16292), sizeof v); (u32)v; }), (u32)(0));  // @37_42ee70
  ecx = edx = 0;  // @38_42ee70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @39_42ee70
  ecx = eax;  // @40_42ee70
  eax = ext_42b080_fastcall3(ecx, edx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16292), sizeof v); (u32)v; }));  // @41_42ee70
  ecx = edx = 0;  // @42_42ee70
  edi = (edi - esi);  // @43_42ee70
  ecx = (u32)(EBP - 16304);  // @44_42ee70
  eax = (u32)(3579139413);  // @45_42ee70
  { long long t_ = (long long)(s32)eax * (long long)(s32)edi; eax = (u32)t_; edx = (u32)((u64)t_ >> 32); }  // @46_42ee70
  edx = (u32)((s32)edx >> (u32)(1));  // @47_42ee70
  eax = edx;  // @48_42ee70
  eax = (eax >> (u32)(31));  // @49_42ee70
  eax = (eax + edx);  // @50_42ee70
  eax = (u32)(eax + eax*2);  // @51_42ee70
  eax = (eax << (u32)(2));  // @52_42ee70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @53_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16304), &v, sizeof v); }  // @54_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16300), &v, sizeof v); }  // @55_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16296), &v, sizeof v); }  // @56_42ee70
  eax = ext_6014a0_stdcall1((u32)(8));  // @57_42ee70
  ecx = edx = 0;  // @58_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16304), &v, sizeof v); }  // @59_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16300), &v, sizeof v); }  // @60_42ee70
  ecx = (u32)(eax + 8);  // @61_42ee70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16296), &v, sizeof v); }  // @62_42ee70
  if ((eax & eax) == 0) goto L42efa3;  // @63_42ee70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @64_42ee70
  L42efa3:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @66_42ee70
  ecx = (u32)(EBP - 16284);  // @67_42ee70
  reg.state = (s32)((u32)(2));  // @68_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16284), &v, sizeof v); }  // @69_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16280), &v, sizeof v); }  // @70_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16276), &v, sizeof v); }  // @71_42ee70
  eax = ext_6014a0_stdcall1((u32)(8));  // @72_42ee70
  ecx = edx = 0;  // @73_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16284), &v, sizeof v); }  // @74_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16280), &v, sizeof v); }  // @75_42ee70
  ecx = (u32)(eax + 8);  // @76_42ee70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16276), &v, sizeof v); }  // @77_42ee70
  if ((eax & eax) == 0) goto L42eff1;  // @78_42ee70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @79_42ee70
  L42eff1:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @81_42ee70
  eax = (u32)(EBP - 16016);  // @82_42ee70
  reg.state = (s32)((u32)(3));  // @83_42ee70
  p3_ = eax;  // @84_42ee70
  eax = ext_634d10_cdecl3((u32)(p3_), (u32)(0), (u32)(16000));  // @85_42ee70
  ecx = edx = 0;  // @86_42ee70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16312), sizeof v); (u32)v; });  // @87_42ee70
  ecx = esi;  // @88_42ee70
  eax = ext_4cc180_thiscall2(ecx, (u32)(6781786));  // @89_42ee70
  ecx = edx = 0;  // @90_42ee70
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16308), sizeof v); (u32)v; });  // @91_42ee70
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42f051;  // @92_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @93_42ee70
  ecx = ebx;  // @94_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 116), sizeof v); (u32)v; });  // @95_42ee70
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @96_42ee70
  ecx = edx = 0;  // @97_42ee70
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42f051;  // @98_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @99_42ee70
  p4_ = eax;  // @100_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @101_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 52)))((u32)(p4_), (u32)(6790432));  // @102_42ee70
  ecx = edx = 0;  // @103_42ee70
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @104_42ee70
  goto L42f212;  // @105_42ee70
  L42f051:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16288), sizeof v); (u32)v; });  // @107_42ee70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L42f079;  // @108_42ee70
  L42f060:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @110_42ee70
  ecx = (u32)(EBP - 16288);  // @111_42ee70
  p5_ = ecx;  // @112_42ee70
  ecx = ebx;  // @113_42ee70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(p5_));  // @114_42ee70
  ecx = edx = 0;  // @115_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16288), sizeof v); (u32)v; });  // @116_42ee70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L42f060;  // @117_42ee70
  L42f079:;
  ecx = esi;  // @119_42ee70
  eax = ext_4cc1d0_thiscall1(ecx);  // @120_42ee70
  ecx = edx = 0;  // @121_42ee70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @122_42ee70
  ecx = ebx;  // @123_42ee70
  p6_ = eax;  // @124_42ee70
  eax = (u32)(EBP - 16016);  // @125_42ee70
  p7_ = eax;  // @126_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 112)))(ecx, (u32)(p7_), (u32)(p6_));  // @127_42ee70
  ecx = edx = 0;  // @128_42ee70
  eax = (u32)(EBP - 16016);  // @129_42ee70
  edx = (u32)(eax + 1);  // @130_42ee70
  L42f098:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @132_42ee70
  eax = (eax + 1);  // @133_42ee70
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L42f098;  // @134_42ee70
  eax = (eax - edx);  // @135_42ee70
  ecx = (u32)(EBP - 16016);  // @136_42ee70
  eax = (eax + ecx);  // @137_42ee70
  p8_ = eax;  // @138_42ee70
  eax = ecx;  // @139_42ee70
  ecx = (u32)(EBP - 16284);  // @140_42ee70
  p9_ = eax;  // @141_42ee70
  eax = ext_5f2d60_thiscall3(ecx, (u32)(p9_), (u32)(p8_));  // @142_42ee70
  ecx = edx = 0;  // @143_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @144_42ee70
  ecx = (u32)(EBP - 16284);  // @145_42ee70
  p10_ = ecx;  // @146_42ee70
  ecx = ebx;  // @147_42ee70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 176)))(ecx, (u32)(p10_));  // @148_42ee70
  ecx = edx = 0;  // @149_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)0x67625c))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16292), sizeof v); (u32)v; }), (u32)(6790472));  // @150_42ee70
  ecx = edx = 0;  // @151_42ee70
  if ((eax & eax) == 0) goto L42f1e0;  // @152_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @153_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @154_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(889));  // @155_42ee70
  ecx = edx = 0;  // @156_42ee70
  p11_ = eax;  // @157_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @158_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p11_), (u32)(6790484));  // @159_42ee70
  ecx = edx = 0;  // @160_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @161_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @162_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(890));  // @163_42ee70
  ecx = edx = 0;  // @164_42ee70
  p12_ = eax;  // @165_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @166_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p12_), (u32)(6790524));  // @167_42ee70
  ecx = edx = 0;  // @168_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @169_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(891));  // @171_42ee70
  ecx = edx = 0;  // @172_42ee70
  p13_ = eax;  // @173_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @174_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p13_), (u32)(6790548));  // @175_42ee70
  ecx = edx = 0;  // @176_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @177_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(892));  // @179_42ee70
  ecx = edx = 0;  // @180_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @181_42ee70
  p14_ = eax;  // @182_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p14_), (u32)(6777880), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16284), sizeof v); (u32)v; }));  // @183_42ee70
  ecx = edx = 0;  // @184_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @185_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @186_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(893));  // @187_42ee70
  ecx = edx = 0;  // @188_42ee70
  p15_ = eax;  // @189_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @190_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p15_), (u32)(6790548));  // @191_42ee70
  ecx = edx = 0;  // @192_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @193_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @194_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(894));  // @195_42ee70
  ecx = edx = 0;  // @196_42ee70
  p16_ = eax;  // @197_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @198_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p16_), (u32)(6790584));  // @199_42ee70
  ecx = edx = 0;  // @200_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @201_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(895));  // @203_42ee70
  ecx = edx = 0;  // @204_42ee70
  p17_ = eax;  // @205_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @206_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p17_), (u32)(6790616));  // @207_42ee70
  ecx = edx = 0;  // @208_42ee70
  L42f1e0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16284), sizeof v); (u32)v; });  // @210_42ee70
  esi = (u32)(EBP - 16016);  // @211_42ee70
  esi = (esi - edx);  // @212_42ee70
  L42f1f0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @214_42ee70
  edx = (u32)(edx + 1);  // @215_42ee70
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + edx - 1), &v, sizeof v); }  // @216_42ee70
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42f1f0;  // @217_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @218_42ee70
  ecx = (u32)(EBP - 16016);  // @219_42ee70
  p18_ = ecx;  // @220_42ee70
  ecx = ebx;  // @221_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 180), sizeof v); (u32)v; });  // @222_42ee70
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p18_));  // @223_42ee70
  ecx = edx = 0;  // @224_42ee70
  ebx = (ebx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @225_42ee70
  L42f212:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16276), sizeof v); (u32)v; });  // @227_42ee70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16284), sizeof v); (u32)v; });  // @228_42ee70
  ecx = (ecx - edx);  // @229_42ee70
  reg.state = (s32)((u32)(4));  // @230_42ee70
  if ((edx & edx) == 0) goto L42f239;  // @231_42ee70
  if ((ecx & ecx) == 0) goto L42f239;  // @232_42ee70
  p19_ = ecx;  // @233_42ee70
  p20_ = edx;  // @234_42ee70
  ecx = (u32)(EBP - 16284);  // @235_42ee70
  eax = ext_54f870_stdcall2((u32)(p20_), (u32)(p19_));  // @236_42ee70
  ecx = edx = 0;  // @237_42ee70
  L42f239:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16296), sizeof v); (u32)v; });  // @239_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16304), sizeof v); (u32)v; });  // @240_42ee70
  eax = (eax - ecx);  // @241_42ee70
  reg.state = (s32)((u32)(5));  // @242_42ee70
  if ((ecx & ecx) == 0) goto L42f260;  // @243_42ee70
  if ((eax & eax) == 0) goto L42f260;  // @244_42ee70
  p21_ = eax;  // @245_42ee70
  p22_ = ecx;  // @246_42ee70
  ecx = (u32)(EBP - 16304);  // @247_42ee70
  eax = ext_54f870_stdcall2((u32)(p22_), (u32)(p21_));  // @248_42ee70
  ecx = edx = 0;  // @249_42ee70
  L42f260:;
  ecx = (u32)(EBP - 16272);  // @251_42ee70
  eax = ext_4cbec0_thiscall1(ecx);  // @252_42ee70
  ecx = edx = 0;  // @253_42ee70
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @254_42ee70
  SEH_LEAVE();  // @255_42ee70
  ext_633654(G(u32, 0x6f5630));  // @256_42ee70
  return eax;  // @257_42ee70
}
PCREG(42ee70, lifted_42ee70);

