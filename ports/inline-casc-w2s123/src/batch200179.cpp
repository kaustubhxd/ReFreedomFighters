// batch200179.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double FASTCALL ext_4e0830_fastcall2_f(u32, u32) __asm__("ext_4e0830");
extern "C" double FASTCALL ext_53bec0_fastcall2_f(u32, u32) __asm__("ext_53bec0");
extern "C" u32 FASTCALL ext_430620_fastcall4(u32, u32, u32, u32) __asm__("ext_430620");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_421ed0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_421ed0");
extern "C" u32 THISCALL ext_430010_thiscall2(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_45f3c0_thiscall2(u32, u32) __asm__("ext_45f3c0");
extern "C" u32 THISCALL ext_4634f0_thiscall2(u32, u32) __asm__("ext_4634f0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_616490_thiscall4(u32, u32, u32, u32) __asm__("ext_616490");
extern "C" u32 THISCALL ext_616580_thiscall4(u32, u32, u32, u32) __asm__("ext_616580");
extern "C" u32 THISCALL ext_616620_thiscall4(u32, u32, u32, u32) __asm__("ext_616620");
extern "C" u32 THISCALL ext_617360_thiscall1(u32) __asm__("ext_617360");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 THISCALL ext_63cc50_thiscall3(u32, u32, u32) __asm__("ext_63cc50");
extern "C" u32 THISCALL ext_63ead0_thiscall2(u32, u32) __asm__("ext_63ead0");
extern "C" u32 THISCALL ext_6500b0_thiscall1(u32) __asm__("ext_6500b0");
extern "C" u32 THISCALL ext_651180_thiscall1(u32) __asm__("ext_651180");
extern "C" u32 THISCALL ext_658db0_thiscall1(u32) __asm__("ext_658db0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

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

extern "C" u32 THISCALL lifted_430a20(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66534c);  // @h_430a20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_EBX, 4);  // @0_430a20
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_ESI, 4);  // @1_430a20
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_EDI, 4);  // @2_430a20
  edi = ecx;  // @3_430a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_430a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_430a20
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5), sizeof v); (u32)v; })) goto L430a98;  // @7_430a20
  if (esi != edx) goto L430a98;  // @8_430a20
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L430b52;  // @9_430a20
  eax = ext_430010_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; }));  // @10_430a20
  ecx = edx = 0;  // @11_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_430a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @13_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_430a20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @15_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_430a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @17_430a20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @18_430a20
  SEH_LEAVE();  // @19_430a20
  return eax;  // @20_430a20
  L430a98:;
  if (eax == esi) goto L430b52;  // @22_430a20
  L430aa0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; });  // @24_430a20
  esi = eax;  // @25_430a20
  if ((ecx & ecx) == 0) goto L430abf;  // @26_430a20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @27_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5), sizeof v); (u32)v; });  // @28_430a20
  if ((eax & eax) == 0) goto L430add;  // @29_430a20
  L430ab3:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @31_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5), sizeof v); (u32)v; });  // @32_430a20
  if ((eax & eax) != 0) goto L430ab3;  // @33_430a20
  goto L430add;  // @34_430a20
  L430abf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @36_430a20
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; })) goto L430ad4;  // @37_430a20
  L430ac7:;
  eax = ecx;  // @39_430a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @40_430a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @41_430a20
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; })) goto L430ac7;  // @42_430a20
  L430ad4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; }) != ecx) eax = ecx;  // @44_430a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @45_430a20
  L430add:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_430a20
  ecx = esi;  // @48_430a20
  eax = (u32)(edx + 9);  // @49_430a20
  p0_ = eax;  // @50_430a20
  eax = (u32)(edx + 5);  // @51_430a20
  edx = (edx + 1);  // @52_430a20
  p1_ = eax;  // @53_430a20
  eax = ext_430620_fastcall4(ecx, edx, (u32)(p1_), (u32)(p0_));  // @54_430a20
  ecx = edx = 0;  // @55_430a20
  ebx = eax;  // @56_430a20
  ecx = (u32)(ebx + 25);  // @57_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_430a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @59_430a20
  edx = (edx - eax);  // @60_430a20
  reg.state = (s32)((u32)(0));  // @61_430a20
  if ((eax & eax) == 0) goto L430b11;  // @62_430a20
  if ((edx & edx) == 0) goto L430b11;  // @63_430a20
  p2_ = edx;  // @64_430a20
  p3_ = eax;  // @65_430a20
  eax = ext_54f870_stdcall2((u32)(p3_), (u32)(p2_));  // @66_430a20
  ecx = edx = 0;  // @67_430a20
  L430b11:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 13), sizeof v); (u32)v; });  // @69_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21), sizeof v); (u32)v; });  // @70_430a20
  eax = (eax - edx);  // @71_430a20
  reg.state = (s32)((u32)(1));  // @72_430a20
  if ((edx & edx) == 0) goto L430b32;  // @73_430a20
  if ((eax & eax) == 0) goto L430b32;  // @74_430a20
  p4_ = eax;  // @75_430a20
  p5_ = edx;  // @76_430a20
  ecx = (u32)(ebx + 13);  // @77_430a20
  eax = ext_54f870_stdcall2((u32)(p5_), (u32)(p4_));  // @78_430a20
  ecx = edx = 0;  // @79_430a20
  L430b32:;
  p6_ = ebx;  // @81_430a20
  ecx = edi;  // @82_430a20
  reg.state = (s32)((u32)(4294967295));  // @83_430a20
  eax = ext_54f870_stdcall2((u32)(p6_), (u32)(37));  // @84_430a20
  ecx = edx = 0;  // @85_430a20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @86_430a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @87_430a20
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; })) goto L430aa0;  // @88_430a20
  L430b52:;
  SEH_LEAVE();  // @90_430a20
  return eax;  // @91_430a20
}
PCREG(430a20, lifted_430a20);

extern "C" u32 THISCALL lifted_537500(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_537500
  eax = (eax ^ EBP);  // @1_537500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_537500
  __builtin_memcpy((void *)(u32)(EBP - 56), &SENT_EBX, 4);  // @3_537500
  __builtin_memcpy((void *)(u32)(EBP - 60), &SENT_EDI, 4);  // @4_537500
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_537500
  ebx = ecx;  // @6_537500
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @7_537500
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @8_537500
  if ((edi & edi) != 0) goto L537535;  // @9_537500
  L537521:;
  eax = 0;  // @11_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @12_537500
  ecx = (ecx ^ EBP);  // @13_537500
  eax = ext_633654_thiscall1(ecx);  // @14_537500
  ecx = edx = 0;  // @15_537500
  return eax;  // @16_537500
  L537535:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21250), sizeof v); (u32)v; });  // @18_537500
  if ((edx & edx) == 0) goto L537521;  // @19_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @20_537500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L53754e;  // @21_537500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; }) == (u32)(0)) goto L537521;  // @22_537500
  L53754e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; });  // @24_537500
  esi = (u32)(edx + edi);  // @25_537500
  ecx = (ecx - 1);  // @26_537500
  if (ecx > (u32)(15)) goto L537652;  // @27_537500
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5470044), sizeof v); (u32)v; });  // @28_537500
  switch (ecx) { case 0: goto L537731; case 1: goto L53758e; case 2: goto L537652; case 3: goto L53756d; case 4: goto L537652; default: __builtin_trap(); }  // @29_537500
  L53756d:;
  eax = (u32)(esi + 8);  // @31_537500
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_537500
  esi = (esi + edx);  // @33_537500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(2)) goto L537597;  // @34_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @36_537500
  ecx = (ecx ^ EBP);  // @37_537500
  eax = ext_633654_thiscall1(ecx);  // @38_537500
  ecx = edx = 0;  // @39_537500
  return eax;  // @40_537500
  L53758e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(2)) goto L537731;  // @42_537500
  L537597:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(1)) goto L537731;  // @44_537500
  ebx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @45_537500
  if (((ebx & 0xffff) & (ebx & 0xffff)) == 0) goto L537652;  // @46_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @47_537500
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 10), sizeof v); (u32)v; });  // @48_537500
  ecx = (ecx + edx);  // @49_537500
  edx = 0;  // @50_537500
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @51_537500
  if (((eax & 0xffff) & (eax & 0xffff)) != 0) goto L5375dc;  // @52_537500
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @53_537500
  ecx = (u32)(edx + 1);  // @54_537500
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @55_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @56_537500
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @57_537500
  if (ecx < ebx) goto L537620;  // @58_537500
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @59_537500
  goto L537620;  // @60_537500
  L5375dc:;
  if (eax != (u32)(1)) goto L537667;  // @62_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @65_537500
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @66_537500
  T[0] = ((double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6954540), (u32)(1081));  // @67_537500
  *(volatile u32 *)0x8140f4 = 0;  // @68_537500
  ecx = edx = 0;  // @69_537500
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @70_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @71_537500
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @72_537500
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @73_537500
  _mm_store_ss((float *)(u32)(EBP - 40), x0);  // @74_537500
  T[0] = (T[0] * ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), 4); (double)v; }));  // @75_537500
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 40), &v, 4); }  // @76_537500
  edx = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(EBP - 40)));  // @77_537500
  L53761d:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @79_537500
  L537620:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @81_537500
  if ((s32)edx < (s32)eax) goto L53762b;  // @82_537500
  edx = (u32)(eax - 1);  // @83_537500
  L53762b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4), sizeof v); (u32)v; });  // @85_537500
  if ((eax & eax) == 0) goto L537652;  // @86_537500
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21250), sizeof v); (u32)v; });  // @87_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; });  // @88_537500
  esi = (u32)(eax + edx);  // @89_537500
  if (ecx != (u32)(3)) goto L537723;  // @90_537500
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L537728;  // @91_537500
  L537652:;
  eax = 0;  // @93_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @94_537500
  ecx = (ecx ^ EBP);  // @95_537500
  eax = ext_633654_thiscall1(ecx);  // @96_537500
  ecx = edx = 0;  // @97_537500
  __asm__ volatile("" :: "Yz"(x0));  // @98_537500
  return eax;  // @99_537500
  L537667:;
  if (eax != (u32)(2)) goto L53761d;  // @101_537500
  edx = ebx;  // @102_537500
  edi = 0;  // @103_537500
  eax = 0;  // @104_537500
  if ((s32)(edx & edx) <= 0) goto L5376cf;  // @105_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @106_537500
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @107_537500
  ecx = (ecx + (u32)(20679));  // @108_537500
  L537682:;
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) & ebx) != 0) goto L53768b;  // @110_537500
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + edi - 36), &v, sizeof v); }  // @111_537500
  edi = (edi + 1);  // @112_537500
  L53768b:;
  eax = (eax + 1);  // @114_537500
  ecx = (ecx + (u32)(4));  // @115_537500
  if ((s32)eax < (s32)edx) goto L537682;  // @116_537500
  if ((edi & edi) == 0) goto L5376cf;  // @117_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @118_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @120_537500
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @121_537500
  T[0] = ((double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6954540), (u32)(1108));  // @122_537500
  *(volatile u32 *)0x8140f4 = 0;  // @123_537500
  ecx = edx = 0;  // @124_537500
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)edi));  // @125_537500
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @126_537500
  _mm_store_ss((float *)(u32)(EBP - 40), x0);  // @127_537500
  T[0] = (T[0] * ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), 4); (double)v; }));  // @128_537500
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 40), &v, 4); }  // @129_537500
  eax = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(EBP - 40)));  // @130_537500
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax - 36), sizeof v); (u32)v; });  // @131_537500
  goto L53770b;  // @132_537500
  L5376cf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @134_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @137_537500
  *(volatile u32 *)0x8140f4 = 0x80000008;  // @138_537500
  T[0] = ((double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6954540), (u32)(1105));  // @139_537500
  *(volatile u32 *)0x8140f4 = 0;  // @140_537500
  ecx = edx = 0;  // @141_537500
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @142_537500
  x0 = _mm_castsi128_ps(_mm_cvtsi32_si128((int)eax));  // @143_537500
  x0 = _mm_cvtepi32_ps(_mm_castps_si128(x0));  // @144_537500
  _mm_store_ss((float *)(u32)(EBP - 40), x0);  // @145_537500
  T[0] = (T[0] * ({ float v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), 4); (double)v; }));  // @146_537500
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 40), &v, 4); }  // @147_537500
  edx = (u32)_mm_cvtss_si32(_mm_load_ss((const float *)(u32)(EBP - 40)));  // @148_537500
  L53770b:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @150_537500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @151_537500
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @152_537500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx*4 + 20679), sizeof v); (u32)v; });  // @153_537500
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) | eax)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @154_537500
  goto L537620;  // @155_537500
  L537723:;
  edi = eax;  // @157_537500
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @158_537500
  L537728:;
  if (ecx != (u32)(2)) goto L537597;  // @160_537500
  L537731:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @162_537500
  eax = edi;  // @163_537500
  ecx = (ecx ^ EBP);  // @164_537500
  eax = ext_633654_thiscall1(ecx);  // @165_537500
  ecx = edx = 0;  // @166_537500
  __asm__ volatile("" :: "Yz"(x0));  // @167_537500
  return eax;  // @168_537500
}
PCREG(537500, lifted_537500);

extern "C" u32 THISCALL lifted_53c5b0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  double T[8]; double fa_ = 0, fb_ = 0;
  __m128 x0 = _mm_setzero_ps(), x1 = _mm_setzero_ps(), x2 = _mm_setzero_ps(), x3 = _mm_setzero_ps(), x4 = _mm_setzero_ps(), x5 = _mm_setzero_ps(), x6 = _mm_setzero_ps(), x7 = _mm_setzero_ps();
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_53c5b0
  eax = (eax ^ EBP);  // @1_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_53c5b0
  __builtin_memcpy((void *)(u32)(EBP - 136), &SENT_ESI, 4);  // @3_53c5b0
  __builtin_memcpy((void *)(u32)(EBP - 140), &SENT_EDI, 4);  // @4_53c5b0
  esi = ecx;  // @5_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @6_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_53c5b0
  x2 = _mm_setzero_ps();  // @8_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_53c5b0
  x0 = x2;  // @10_53c5b0
  x1 = _mm_load_ss((const float *)(u32)(6802756));  // @11_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @12_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @13_53c5b0
  eax = (eax | (u32)(4294967295));  // @14_53c5b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @15_53c5b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @16_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @17_53c5b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @18_53c5b0
  ecx = (ecx & 0xffffff00u) | ((0) & 0xff);  // @19_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @20_53c5b0
  eax = (eax | eax);  // @21_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @22_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @23_53c5b0
  edi = 0;  // @24_53c5b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @25_53c5b0
  edx = 0;  // @26_53c5b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 57), &v, sizeof v); }  // @27_53c5b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @28_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @29_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @30_53c5b0
  _mm_store_ss((float *)(u32)(EBP - 92), x1);  // @31_53c5b0
  L53c623:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edx*4 - 56), sizeof v); (u32)v; });  // @33_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edx*4 - 52), sizeof v); (u32)v; });  // @34_53c5b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @35_53c5b0
  if (eax == (u32)(-1)) goto L53c734;  // @36_53c5b0
  if (ecx == (u32)(-1)) goto L53c734;  // @37_53c5b0
  if (ecx >= eax) goto L53c64c;  // @38_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @39_53c5b0
  eax = ecx;  // @40_53c5b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @41_53c5b0
  L53c64c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4609), sizeof v); (u32)v; });  // @43_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*8), sizeof v); (u32)v; });  // @44_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*8 + 4), sizeof v); (u32)v; });  // @45_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @46_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4613), sizeof v); (u32)v; });  // @47_53c5b0
  edi = (u32)(eax + ecx*4);  // @48_53c5b0
  if ((esi & esi) == 0) goto L53c6a6;  // @49_53c5b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 - 2), sizeof v); (u32)v; });  // @50_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @51_53c5b0
  eax = (eax & (u32)(16383));  // @52_53c5b0
  if (ecx > eax) goto L53c6a6;  // @53_53c5b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @54_53c5b0
  eax = (eax & (u32)(16383));  // @55_53c5b0
  if (ecx < eax) goto L53c6a6;  // @56_53c5b0
  ecx = 0;  // @57_53c5b0
  if ((esi & esi) == 0) goto L53c6a6;  // @58_53c5b0
  L53c690:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @60_53c5b0
  eax = (eax & (u32)(16383));  // @61_53c5b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; }) == eax) goto L53c6ba;  // @62_53c5b0
  ecx = (ecx + 1);  // @63_53c5b0
  edi = (edi + (u32)(4));  // @64_53c5b0
  if (ecx < esi) goto L53c690;  // @65_53c5b0
  L53c6a6:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @67_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @68_53c5b0
  ecx = (ecx ^ EBP);  // @69_53c5b0
  eax = ext_633654_thiscall1(ecx);  // @70_53c5b0
  ecx = edx = 0;  // @71_53c5b0
  __asm__ volatile("" :: "Yz"(x0));  // @72_53c5b0
  return eax;  // @73_53c5b0
  L53c6ba:;
  esi = (esi - ecx);  // @75_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @76_53c5b0
  if (esi == 0) goto L53c6a6;  // @77_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @78_53c5b0
  esi = 0;  // @79_53c5b0
  x0 = x2;  // @80_53c5b0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @81_53c5b0
  _mm_store_ss((float *)(u32)(EBP - 64), x0);  // @82_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @83_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 37), &v, sizeof v); }  // @84_53c5b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; }) <= esi) goto L53c731;  // @85_53c5b0
  L53c6e4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4), sizeof v); (u32)v; });  // @87_53c5b0
  eax = (ecx & 0xffff);  // @88_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @89_53c5b0
  eax = ecx;  // @90_53c5b0
  eax = (eax >> (u32)(16));  // @91_53c5b0
  eax = (eax & (u32)(16383));  // @92_53c5b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; }) != eax) goto L53c72e;  // @93_53c5b0
  ecx = (ecx >> (u32)(30));  // @94_53c5b0
  ecx = (ecx - (u32)(0));  // @95_53c5b0
  if (ecx == 0) goto L53c88e;  // @96_53c5b0
  ecx = (ecx - (u32)(1));  // @97_53c5b0
  if (ecx == 0) goto L53c77a;  // @98_53c5b0
  ecx = (ecx - (u32)(1));  // @99_53c5b0
  if (ecx == 0) goto L53c725;  // @100_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @101_53c5b0
  if ((eax & eax) == 0) goto L53c777;  // @102_53c5b0
  *(volatile u32 *)0x8140f4 = 0x80000000;  // @103_53c5b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @104_53c5b0
  *(volatile u32 *)0x8140f4 = 0;  // @105_53c5b0
  ecx = edx = 0;  // @106_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @107_53c5b0
  L53c720:;
  x0 = _mm_load_ss((const float *)(u32)(EBP - 64));  // @109_53c5b0
  L53c725:;
  esi = (esi + 1);  // @111_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @112_53c5b0
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; })) goto L53c6e4;  // @113_53c5b0
  L53c72e:;
  x2 = _mm_setzero_ps();  // @115_53c5b0
  L53c731:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @117_53c5b0
  L53c734:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @119_53c5b0
  eax = (eax - 1);  // @120_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @121_53c5b0
  if ((eax & eax) != 0) goto L53c623;  // @122_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @123_53c5b0
  if (eax == (u32)(-1)) goto L53ca35;  // @124_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @125_53c5b0
  edx = (edx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @126_53c5b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(x2);  // @127_53c5b0
  eax = (ecx & 0xffff);  // @128_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @129_53c5b0
  eax = (eax & 0xffff00ffu) | ((((u32)((!(fa_ >= fb_) ? 1 : 0) | ((fa_ != fa_ || fb_ != fb_) ? 4 : 0) | (!(fa_ < fb_ || fa_ > fb_) ? 0x40 : 0) | 2)) & 0xff) << 8);  // @130_53c5b0
  if (!__builtin_parity((u32)((((eax >> 8) & 0xff) & (u32)(68))) & 0xff)) goto L53c92f;  // @131_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @132_53c5b0
  edx = (edx & 0xffffff00u) | ((0) & 0xff);  // @133_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @134_53c5b0
  edi = (ecx & 0xffff);  // @135_53c5b0
  goto L53c932;  // @136_53c5b0
  L53c777:;
  __builtin_trap();  // @138_53c5b0
  L53c77a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @140_53c5b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 57), &v, sizeof v); }  // @141_53c5b0
  edx = (u32)(eax + eax*2);  // @142_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @143_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4605), sizeof v); (u32)v; });  // @144_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4601), sizeof v); (u32)v; });  // @145_53c5b0
  esi = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @146_53c5b0
  esi = (esi + eax);  // @147_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @148_53c5b0
  esi = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4 + 4), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @149_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @150_53c5b0
  esi = (esi + eax);  // @151_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @152_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @153_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @154_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @156_53c5b0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @157_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @158_53c5b0
  *(volatile u32 *)0x8140f4 = 0;  // @159_53c5b0
  ecx = edx = 0;  // @160_53c5b0
  ecx = eax;  // @161_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @162_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @163_53c5b0
  edx = (u32)(EBP - 16);  // @164_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @165_53c5b0
  p0_ = edx;  // @166_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @167_53c5b0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @168_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p0_));  // @169_53c5b0
  *(volatile u32 *)0x8140f4 = 0;  // @170_53c5b0
  ecx = edx = 0;  // @171_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @172_53c5b0
  ecx = (u32)(EBP - 16);  // @173_53c5b0
  T[0] = ext_4e0830_fastcall2_f(ecx, edx);  // @174_53c5b0
  ecx = edx = 0;  // @175_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @176_53c5b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 124), &v, 4); }  // @177_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @178_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @179_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @180_53c5b0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @181_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @182_53c5b0
  *(volatile u32 *)0x8140f4 = 0;  // @183_53c5b0
  ecx = edx = 0;  // @184_53c5b0
  ecx = eax;  // @185_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @186_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @187_53c5b0
  edx = (u32)(EBP - 28);  // @188_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @189_53c5b0
  p1_ = edx;  // @190_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @191_53c5b0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @192_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p1_));  // @193_53c5b0
  *(volatile u32 *)0x8140f4 = 0;  // @194_53c5b0
  ecx = edx = 0;  // @195_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @196_53c5b0
  ecx = (u32)(EBP - 28);  // @197_53c5b0
  T[0] = ext_4e0830_fastcall2_f(ecx, edx);  // @198_53c5b0
  ecx = edx = 0;  // @199_53c5b0
  x2 = _mm_load_ss((const float *)(u32)(EBP - 92));  // @200_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @201_53c5b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 132), &v, 4); }  // @202_53c5b0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 132));  // @203_53c5b0
  x0 = _mm_min_ss(x0, _mm_load_ss((const float *)(u32)(EBP - 124)));  // @204_53c5b0
  fa_ = _mm_cvtss_f32(x2); fb_ = _mm_cvtss_f32(x0);  // @205_53c5b0
  if (!(fa_ > fb_)) goto L53c85e;  // @206_53c5b0
  _mm_store_ss((float *)(u32)(EBP - 92), x0);  // @207_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @208_53c5b0
  L53c85e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @210_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @211_53c5b0
  edx = (edx + (u32)(2));  // @212_53c5b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @213_53c5b0
  x0 = _mm_load_ss((const float *)(u32)(eax + 8));  // @214_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @215_53c5b0
  x0 = _mm_mul_ss(x0, _mm_load_ss((const float *)(u32)(eax + 8)));  // @216_53c5b0
  fa_ = _mm_cvtss_f32(x0); fb_ = _mm_cvtss_f32(_mm_load_ss((const float *)(u32)(EBP - 64)));  // @217_53c5b0
  if (!(fa_ >= fb_)) goto L53c720;  // @218_53c5b0
  _mm_store_ss((float *)(u32)(EBP - 64), x0);  // @219_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @220_53c5b0
  goto L53c725;  // @221_53c5b0
  L53c88e:;
  edx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @223_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @224_53c5b0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4601), sizeof v); (u32)v; }));  // @225_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @226_53c5b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @227_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @228_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @229_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @230_53c5b0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @231_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @232_53c5b0
  *(volatile u32 *)0x8140f4 = 0;  // @233_53c5b0
  ecx = edx = 0;  // @234_53c5b0
  ecx = eax;  // @235_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @236_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @237_53c5b0
  edx = (u32)(EBP - 40);  // @238_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @239_53c5b0
  p2_ = edx;  // @240_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @241_53c5b0
  *(volatile u32 *)0x8140f4 = 0x80000004;  // @242_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p2_));  // @243_53c5b0
  *(volatile u32 *)0x8140f4 = 0;  // @244_53c5b0
  ecx = edx = 0;  // @245_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @246_53c5b0
  ecx = (u32)(EBP - 40);  // @247_53c5b0
  T[0] = ext_4e0830_fastcall2_f(ecx, edx);  // @248_53c5b0
  ecx = edx = 0;  // @249_53c5b0
  x2 = _mm_load_ss((const float *)(u32)(EBP - 92));  // @250_53c5b0
  { float v = (float)T[0]; __builtin_memcpy((void *)(u32)(EBP - 112), &v, 4); }  // @251_53c5b0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 112));  // @252_53c5b0
  fa_ = _mm_cvtss_f32(x2); fb_ = _mm_cvtss_f32(x0);  // @253_53c5b0
  if (!(fa_ > fb_)) goto L53c900;  // @254_53c5b0
  x1 = x0;  // @255_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @256_53c5b0
  _mm_store_ss((float *)(u32)(EBP - 92), x1);  // @257_53c5b0
  L53c900:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @259_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @260_53c5b0
  x0 = _mm_load_ss((const float *)(u32)(EBP - 64));  // @261_53c5b0
  edx = (edx + (u32)(2));  // @262_53c5b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @263_53c5b0
  x1 = _mm_load_ss((const float *)(u32)(eax + 8));  // @264_53c5b0
  fa_ = _mm_cvtss_f32(x1); fb_ = _mm_cvtss_f32(x0);  // @265_53c5b0
  if (!(fa_ >= fb_)) goto L53c926;  // @266_53c5b0
  x0 = x1;  // @267_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @268_53c5b0
  _mm_store_ss((float *)(u32)(EBP - 64), x0);  // @269_53c5b0
  L53c926:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 57), &v, sizeof v); }  // @271_53c5b0
  goto L53c725;  // @272_53c5b0
  L53c92f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @274_53c5b0
  L53c932:;
  ecx = (ecx >> (u32)(30));  // @276_53c5b0
  ecx = (ecx - (u32)(0));  // @277_53c5b0
  if (ecx == 0) goto L53c9b2;  // @278_53c5b0
  ecx = (ecx - (u32)(1));  // @279_53c5b0
  if (ecx != 0) goto L53ca35;  // @280_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @281_53c5b0
  esi = (u32)(edi + edi*2);  // @282_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @283_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @284_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @285_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4605), sizeof v); (u32)v; });  // @286_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @287_53c5b0
  eax = (u32)(eax + eax*2);  // @288_53c5b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 45), &v, sizeof v); }  // @289_53c5b0
  esi = (u32)(edi + edi*2);  // @290_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @291_53c5b0
  ecx = (u32)(eax + eax*2);  // @292_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4), sizeof v); (u32)v; });  // @293_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @294_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx*4 + 41), &v, sizeof v); }  // @295_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @296_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @297_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 5), &v, sizeof v); }  // @298_53c5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @299_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @300_53c5b0
  eax = (u32)(eax + eax*2);  // @301_53c5b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 45), &v, sizeof v); }  // @302_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @303_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @304_53c5b0
  ecx = (u32)(eax + eax*2);  // @305_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4 + 4), sizeof v); (u32)v; });  // @306_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @307_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4 + 41), &v, sizeof v); }  // @308_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @309_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @310_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx + eax*4 + 5), &v, sizeof v); }  // @311_53c5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @312_53c5b0
  goto L53ca35;  // @313_53c5b0
  L53c9b2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @315_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @316_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @317_53c5b0
  eax = (u32)(eax + eax*2);  // @318_53c5b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 45), &v, sizeof v); }  // @319_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @320_53c5b0
  eax = (u32)(eax + eax*2);  // @321_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 41), &v, sizeof v); }  // @322_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @323_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 5), &v, sizeof v); }  // @324_53c5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @325_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @326_53c5b0
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L53ca35;  // @327_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @328_53c5b0
  edx = (u32)((s32)edi * (s32)(u32)(164));  // @329_53c5b0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4601), sizeof v); (u32)v; }));  // @330_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @331_53c5b0
  T[0] = ext_53bec0_fastcall2_f(ecx, edx);  // @332_53c5b0
  ecx = edx = 0;  // @333_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @334_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @335_53c5b0
  { double v = (double)T[0]; __builtin_memcpy((void *)(u32)(EBP - 116), &v, 8); }  // @336_53c5b0
  x0 = _mm_castpd_ps(_mm_load_sd((const double *)(u32)(EBP - 116)));  // @337_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @338_53c5b0
  x0 = _mm_and_ps(x0, _mm_loadu_ps((const float *)(u32)(6802768)));  // @339_53c5b0
  x0 = _mm_cvtpd_ps(_mm_castps_pd(x0));  // @340_53c5b0
  eax = (u32)(eax + eax*2);  // @341_53c5b0
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 45), &v, sizeof v); }  // @342_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @343_53c5b0
  eax = (u32)(eax + eax*2);  // @344_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 41), &v, sizeof v); }  // @345_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @346_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + ecx*4 + 5), &v, sizeof v); }  // @347_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @348_53c5b0
  ecx = (u32)(ecx + ecx*2);  // @349_53c5b0
  _mm_store_ss((float *)(u32)(esi + ecx*4 + 49), x0);  // @350_53c5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @351_53c5b0
  L53ca35:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @353_53c5b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 57), sizeof v); (u32)v; })) & 0xff);  // @354_53c5b0
  ecx = (ecx ^ EBP);  // @355_53c5b0
  eax = ext_633654_thiscall1(ecx);  // @356_53c5b0
  ecx = edx = 0;  // @357_53c5b0
  __asm__ volatile("" :: "Yz"(x0));  // @358_53c5b0
  return eax;  // @359_53c5b0
}
PCREG(53c5b0, lifted_53c5b0);

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

