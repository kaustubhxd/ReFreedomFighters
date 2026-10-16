// batch226026.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_45d3a0_thiscall1(u32) __asm__("ext_45d3a0");
extern "C" u32 THISCALL ext_48fa10_thiscall1(u32) __asm__("ext_48fa10");
extern "C" u32 THISCALL ext_48fa70_thiscall1(u32) __asm__("ext_48fa70");
extern "C" u32 THISCALL ext_4958e0_thiscall1(u32) __asm__("ext_4958e0");
extern "C" u32 THISCALL ext_497990_thiscall2(u32, u32) __asm__("ext_497990");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_49a790_thiscall3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b2e0_thiscall2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_49b340_thiscall3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_49b680_thiscall1(u32) __asm__("ext_49b680");
extern "C" u32 THISCALL ext_49d6c0_thiscall1(u32) __asm__("ext_49d6c0");
extern "C" u32 THISCALL ext_49df00_thiscall1(u32) __asm__("ext_49df00");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4dc030_thiscall1(u32) __asm__("ext_4dc030");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_5626d0_thiscall2(u32, u32) __asm__("ext_5626d0");
extern "C" u32 THISCALL ext_57c6f0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_57c6f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_476720(u32 ecx_in) {
  SEH_ENTER(0x66713b);  // @h_476720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  ebx = ecx;  // @0_476720
  eax = ext_45d3a0_thiscall1(ecx);  // @1_476720
  ecx = edx = 0;  // @2_476720
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 114), sizeof v); (u32)v; }) != (u32)(0)) goto L47694b;  // @3_476720
  edi = 0;  // @4_476720
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; }) <= (s32)edi) goto L47694b;  // @5_476720
  L476770:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; });  // @7_476720
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @8_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @9_476720
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L476941;  // @10_476720
  ecx = (u32)(EBP - 188);  // @11_476720
  eax = ext_4ccba0_thiscall1(ecx);  // @12_476720
  ecx = edx = 0;  // @13_476720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @14_476720
  reg.state = (s32)((u32)(0));  // @15_476720
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @16_476720
  if ((edx & edx) == 0) goto L4767e5;  // @17_476720
  L4767b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_476720
  PS[0] = edx;  // @20_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @23_476720
  ecx = edx = 0;  // @24_476720
  PS[0] = eax;  // @25_476720
  ecx = (u32)(EBP - 188);  // @26_476720
  eax = ext_4cd540_thiscall2(ecx, (u32)(PS[0]));  // @27_476720
  ecx = edx = 0;  // @28_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @29_476720
  ecx = (u32)(EBP - 192);  // @30_476720
  PS[0] = ecx;  // @31_476720
  ecx = esi;  // @32_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @33_476720
  ecx = edx = 0;  // @34_476720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @35_476720
  if ((edx & edx) != 0) goto L4767b0;  // @36_476720
  L4767e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_476720
  PS[0] = esi;  // @39_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @40_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @42_476720
  ecx = edx = 0;  // @43_476720
  eax = (u32)(EBP - 204);  // @44_476720
  PS[0] = eax;  // @45_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @46_476720
  ecx = (u32)(EBP - 188);  // @47_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @48_476720
  ecx = edx = 0;  // @49_476720
  eax = (u32)(EBP - 204);  // @50_476720
  PS[0] = eax;  // @51_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @52_476720
  ecx = (u32)(EBP - 188);  // @53_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @54_476720
  ecx = edx = 0;  // @55_476720
  esi = eax;  // @56_476720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) == (u32)(0)) goto L47692f;  // @57_476720
  L476831:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_476720
  PS[0] = esi;  // @60_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @61_476720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(PS[0]));  // @63_476720
  ecx = edx = 0;  // @64_476720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @65_476720
  if ((eax & eax) == 0) goto L47690a;  // @66_476720
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L47690a;  // @67_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @68_476720
  if ((ecx & ecx) == 0) goto L47686d;  // @69_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_476720
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @71_476720
  ecx = edx = 0;  // @72_476720
  L47686d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_476720
  PS[0] = esi;  // @75_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @76_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(PS[0]));  // @78_476720
  ecx = edx = 0;  // @79_476720
  if ((eax & eax) == 0) goto L47690a;  // @80_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @81_476720
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @82_476720
  ecx = edx = 0;  // @83_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_476720
  PS[0] = esi;  // @85_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @86_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(PS[0]));  // @88_476720
  ecx = edx = 0;  // @89_476720
  if ((eax & eax) == 0) goto L47690a;  // @90_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @91_476720
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @92_476720
  ecx = edx = 0;  // @93_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @94_476720
  PS[0] = esi;  // @95_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @96_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(PS[0]));  // @98_476720
  ecx = edx = 0;  // @99_476720
  if ((eax & eax) == 0) goto L47690a;  // @100_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @101_476720
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @102_476720
  ecx = edx = 0;  // @103_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @104_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @105_476720
  if ((ecx & ecx) == 0) goto L476903;  // @106_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_476720
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @108_476720
  ecx = edx = 0;  // @109_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @110_476720
  L476903:;
  ecx = eax;  // @112_476720
  eax = ext_4dc030_thiscall1(ecx);  // @113_476720
  ecx = edx = 0;  // @114_476720
  L47690a:;
  eax = (u32)(EBP - 204);  // @116_476720
  PS[0] = eax;  // @117_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @118_476720
  ecx = (u32)(EBP - 188);  // @119_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @120_476720
  ecx = edx = 0;  // @121_476720
  esi = eax;  // @122_476720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) != (u32)(0)) goto L476831;  // @123_476720
  L47692f:;
  ecx = (u32)(EBP - 188);  // @125_476720
  reg.state = (s32)((u32)(4294967295));  // @126_476720
  eax = ext_4ccf60_thiscall1(ecx);  // @127_476720
  ecx = edx = 0;  // @128_476720
  L476941:;
  edi = (edi + 1);  // @130_476720
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; })) goto L476770;  // @131_476720
  L47694b:;
  SEH_LEAVE();  // @133_476720
  ext_633654(G(u32, 0x6f5630));  // @134_476720
  return eax;  // @135_476720
}
PCREG(476720, lifted_476720);

extern "C" u32 THISCALL lifted_4923e0(u32 ecx_in) {
  SEH_ENTER(0x667d9b);  // @h_4923e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4923e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }) == (u32)(0)) goto L492497;  // @2_4923e0
  eax = ext_41e290_cdecl1((u32)(10000000));  // @3_4923e0
  ecx = edx = 0;  // @4_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_4923e0
  edi = eax;  // @6_4923e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_4923e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 20)))(ecx);  // @8_4923e0
  ecx = edx = 0;  // @9_4923e0
  PS[1] = edi;  // @10_4923e0
  ecx = (u32)(EBP - 332);  // @11_4923e0
  eax = ext_499880_thiscall3(ecx, (u32)(PS[1]), (u32)(10000000));  // @12_4923e0
  ecx = edx = 0;  // @13_4923e0
  ecx = (u32)(EBP - 332);  // @14_4923e0
  reg.state = (s32)((u32)(0));  // @15_4923e0
  eax = ext_49b340_thiscall3(ecx, (u32)(5), (u32)(21));  // @16_4923e0
  ecx = edx = 0;  // @17_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_4923e0
  ecx = (u32)(EBP - 332);  // @19_4923e0
  eax = ext_49a790_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }), (u32)(3));  // @20_4923e0
  ecx = edx = 0;  // @21_4923e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4924b2;  // @22_4923e0
  PS[1] = edi;  // @23_4923e0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @24_4923e0
  ecx = edx = 0;  // @25_4923e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2994), &v, sizeof v); }  // @26_4923e0
  L49248c:;
  ecx = (u32)(EBP - 332);  // @28_4923e0
  eax = ext_499970_thiscall1(ecx);  // @29_4923e0
  ecx = edx = 0;  // @30_4923e0
  L492497:;
  SEH_LEAVE();  // @32_4923e0
  ext_633654(G(u32, 0x6f5630));  // @33_4923e0
  return eax;  // @34_4923e0
  L4924b2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @37_4923e0
  if ((ecx & ecx) == 0) goto L4924d2;  // @38_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4923e0
  edx = (u32)(EBP - 332);  // @40_4923e0
  PS[0] = edx;  // @41_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(PS[0]));  // @42_4923e0
  ecx = edx = 0;  // @43_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_4923e0
  L4924d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @46_4923e0
  if ((ecx & ecx) == 0) goto L4924eb;  // @47_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_4923e0
  edx = (u32)(EBP - 332);  // @49_4923e0
  PS[0] = edx;  // @50_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(PS[0]));  // @51_4923e0
  ecx = edx = 0;  // @52_4923e0
  L4924eb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @54_4923e0
  eax = (u32)(EBP - 332);  // @55_4923e0
  PS[0] = eax;  // @56_4923e0
  eax = ext_497990_thiscall2(ecx, (u32)(PS[0]));  // @57_4923e0
  ecx = edx = 0;  // @58_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @60_4923e0
  if ((ecx & ecx) == 0) goto L492515;  // @61_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4923e0
  edx = (u32)(EBP - 332);  // @63_4923e0
  PS[0] = edx;  // @64_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(PS[0]));  // @65_4923e0
  ecx = edx = 0;  // @66_4923e0
  L492515:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @68_4923e0
  if ((ecx & ecx) == 0) goto L49252e;  // @69_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_4923e0
  edx = (u32)(EBP - 332);  // @71_4923e0
  PS[0] = edx;  // @72_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 212)))(ecx, (u32)(PS[0]));  // @73_4923e0
  ecx = edx = 0;  // @74_4923e0
  L49252e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; }) == (u32)(0)) goto L492556;  // @76_4923e0
  ecx = (u32)(EBP - 332);  // @77_4923e0
  eax = ext_49b2e0_thiscall2(ecx, (u32)(21));  // @78_4923e0
  ecx = edx = 0;  // @79_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @80_4923e0
  edx = (u32)(EBP - 332);  // @81_4923e0
  PS[0] = edx;  // @82_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(PS[0]));  // @84_4923e0
  ecx = edx = 0;  // @85_4923e0
  L492556:;
  ecx = (u32)(EBP - 332);  // @87_4923e0
  eax = ext_49b2e0_thiscall2(ecx, (u32)(10));  // @88_4923e0
  ecx = edx = 0;  // @89_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_4923e0
  edx = (u32)(EBP - 332);  // @91_4923e0
  PS[0] = edx;  // @92_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @93_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(PS[0]));  // @95_4923e0
  ecx = edx = 0;  // @96_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @97_4923e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 6827), &v, sizeof v); }  // @98_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_4923e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @101_4923e0
  ecx = edx = 0;  // @102_4923e0
  PS[1] = edi;  // @103_4923e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3008), &v, sizeof v); }  // @104_4923e0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @105_4923e0
  ecx = edx = 0;  // @106_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 200), sizeof v); (u32)v; });  // @107_4923e0
  eax = ext_49d6c0_thiscall1(ecx);  // @108_4923e0
  ecx = edx = 0;  // @109_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @111_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @112_4923e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @113_4923e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @114_4923e0
  if ((edx & edx) == 0) goto L49248c;  // @115_4923e0
  L4925e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @117_4923e0
  eax = (eax & (u32)(289792));  // @118_4923e0
  if (eax != (u32)(278528)) goto L492606;  // @119_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @120_4923e0
  PS[0] = edx;  // @121_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23857), sizeof v); (u32)v; });  // @122_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(PS[0]));  // @124_4923e0
  ecx = edx = 0;  // @125_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @126_4923e0
  L492606:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @128_4923e0
  edx = (u32)(EBP - 336);  // @129_4923e0
  PS[0] = edx;  // @130_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @131_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @133_4923e0
  ecx = edx = 0;  // @134_4923e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 336), sizeof v); (u32)v; });  // @135_4923e0
  if ((edx & edx) == 0) goto L49248c;  // @136_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @137_4923e0
  goto L4925e0;  // @138_4923e0
}
PCREG(4923e0, lifted_4923e0);

extern "C" u32 THISCALL lifted_57c500(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  SEH_ENTER(0x66b18b);  // @h_57c500
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_57c500
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_57c500
  ecx = (u32)(ebx + 44);  // @3_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @4_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @6_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @7_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @8_57c500
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @9_57c500
  eax = ext_4cbeb0_thiscall1(ecx);  // @10_57c500
  ecx = edx = 0;  // @11_57c500
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_57c500
  ecx = esi;  // @13_57c500
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 224), &v, sizeof v); }  // @14_57c500
  reg.state = (s32)((u32)(0));  // @15_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_57c500
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 708)))(ecx);  // @17_57c500
  ecx = edx = 0;  // @18_57c500
  ecx = eax;  // @19_57c500
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_57c500
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 840)))(ecx);  // @21_57c500
  ecx = edx = 0;  // @22_57c500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L57c6d7;  // @23_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @24_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @25_57c500
  if ((eax & eax) == 0) goto L57c588;  // @26_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @27_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @28_57c500
  L57c588:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_57c500
  ecx = esi;  // @31_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 648)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }), (u32)(0), (u32)(1));  // @32_57c500
  ecx = edx = 0;  // @33_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @34_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_57c500
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 780)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @36_57c500
  ecx = edx = 0;  // @37_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @38_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_57c500
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @40_57c500
  ecx = edx = 0;  // @41_57c500
  edx = 0;  // @42_57c500
  { u32 v = (u32)((u32)(6990944)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @43_57c500
  { u32 v = (u32)((u32)(6990952)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @44_57c500
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @45_57c500
  L57c5c2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @47_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edx*4 - 24), sizeof v); (u32)v; }), (u32)(0));  // @49_57c500
  ecx = edx = 0;  // @50_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_57c500
  esi = eax;  // @52_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @53_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @54_57c500
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @56_57c500
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6990960), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @58_57c500
  ecx = edx = 0;  // @59_57c500
  PS[0] = eax;  // @60_57c500
  ecx = esi;  // @61_57c500
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 644)))(ecx, (u32)(PS[0]));  // @62_57c500
  ecx = edx = 0;  // @63_57c500
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @64_57c500
  edx = (edx + 1);  // @65_57c500
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @66_57c500
  if (edx < (u32)(2)) goto L57c5c2;  // @67_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @68_57c500
  esi = (u32)(ebx + 12);  // @69_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6990976), (u32)(0));  // @71_57c500
  ecx = edx = 0;  // @72_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @73_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @74_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6990984), (u32)(0));  // @76_57c500
  ecx = edx = 0;  // @77_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 16), &v, sizeof v); }  // @78_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @79_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6990992), (u32)(0));  // @81_57c500
  ecx = edx = 0;  // @82_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 20), &v, sizeof v); }  // @83_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @84_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991000), (u32)(0));  // @86_57c500
  ecx = edx = 0;  // @87_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @88_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @89_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991008), (u32)(0));  // @91_57c500
  ecx = edx = 0;  // @92_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @93_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @94_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991016), (u32)(0));  // @96_57c500
  ecx = edx = 0;  // @97_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @98_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @99_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991024), (u32)(0));  // @101_57c500
  ecx = edx = 0;  // @102_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 36), &v, sizeof v); }  // @103_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @104_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991032), (u32)(0));  // @106_57c500
  ecx = edx = 0;  // @107_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 40), &v, sizeof v); }  // @108_57c500
  edi = (u32)(7);  // @109_57c500
  L57c6c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @111_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_57c500
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, (u32)(6781786));  // @113_57c500
  ecx = edx = 0;  // @114_57c500
  esi = (u32)(esi + 4);  // @115_57c500
  edi = (edi - (u32)(1));  // @116_57c500
  if (edi != 0) goto L57c6c0;  // @117_57c500
  L57c6d7:;
  eax = ebx;  // @119_57c500
  SEH_LEAVE();  // @120_57c500
  return eax;  // @121_57c500
}
PCREG(57c500, lifted_57c500);

extern "C" u32 THISCALL lifted_57db50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b342);  // @h_57db50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_57db50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_57db50
  PS[0] = ebx;  // @2_57db50
  eax = ext_5626d0_thiscall2(ecx, (u32)(PS[0]));  // @3_57db50
  ecx = edx = 0;  // @4_57db50
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L57db9b;  // @5_57db50
  SEH_LEAVE();  // @6_57db50
  return eax;  // @7_57db50
  L57db9b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_57db50
  esi = (u32)(edi + 612);  // @10_57db50
  PS[0] = esi;  // @11_57db50
  ecx = ebx;  // @12_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, (u32)(PS[0]));  // @13_57db50
  ecx = edx = 0;  // @14_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @15_57db50
  ecx = (u32)(EBP - 16);  // @16_57db50
  PS[0] = ecx;  // @17_57db50
  ecx = ebx;  // @18_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @19_57db50
  ecx = edx = 0;  // @20_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_57db50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @22_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @24_57db50
  ecx = edx = 0;  // @25_57db50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 784), &v, sizeof v); }  // @26_57db50
  ecx = (u32)(EBP - 16);  // @27_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @28_57db50
  PS[0] = ecx;  // @29_57db50
  ecx = ebx;  // @30_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @31_57db50
  ecx = edx = 0;  // @32_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_57db50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @36_57db50
  ecx = edx = 0;  // @37_57db50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 788), &v, sizeof v); }  // @38_57db50
  if ((esi & esi) == 0) goto L57dcf5;  // @39_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_57db50
  ecx = (u32)(EBP - 32);  // @41_57db50
  PS[0] = ecx;  // @42_57db50
  ecx = esi;  // @43_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @44_57db50
  ecx = edx = 0;  // @45_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_57db50
  ecx = (u32)(EBP - 32);  // @47_57db50
  PS[0] = ecx;  // @48_57db50
  ecx = esi;  // @49_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @50_57db50
  ecx = edx = 0;  // @51_57db50
  edx = eax;  // @52_57db50
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @53_57db50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }) == (u32)(0)) goto L57dcf5;  // @54_57db50
  ebx = (u32)(6990032);  // @55_57db50
  L57dc23:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_57db50
  PS[0] = edx;  // @58_57db50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @59_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(PS[0]));  // @61_57db50
  ecx = edx = 0;  // @62_57db50
  eax = ext_41e290_cdecl1((u32)(225));  // @63_57db50
  ecx = edx = 0;  // @64_57db50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @65_57db50
  reg.state = (s32)((u32)(0));  // @66_57db50
  if ((eax & eax) == 0) goto L57dc6a;  // @67_57db50
  ecx = eax;  // @68_57db50
  PS[2] = ebx;  // @69_57db50
  eax = ext_57c6f0_thiscall5(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 784), sizeof v); (u32)v; }), (u32)(PS[2]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 796), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @70_57db50
  ecx = edx = 0;  // @71_57db50
  esi = eax;  // @72_57db50
  goto L57dc6c;  // @73_57db50
  L57dc6a:;
  esi = 0;  // @75_57db50
  L57dc6c:;
  reg.state = (s32)((u32)(4294967295));  // @77_57db50
  if ((esi & esi) != 0) goto L57dc7b;  // @78_57db50
  ecx = 0;  // @79_57db50
  goto L57dcc0;  // @80_57db50
  L57dc7b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @82_57db50
  PS[0] = esi;  // @83_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(PS[0]));  // @85_57db50
  ecx = edx = 0;  // @86_57db50
  if ((eax & eax) == 0) goto L57dc8f;  // @87_57db50
  ecx = 0;  // @88_57db50
  goto L57dcc0;  // @89_57db50
  L57dc8f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @91_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @92_57db50
  if ((eax & eax) == 0) goto L57dcae;  // @93_57db50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L57dcae;  // @94_57db50
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L57dcae;  // @95_57db50
  ecx = esi;  // @96_57db50
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @97_57db50
  ecx = edx = 0;  // @98_57db50
  ecx = eax;  // @99_57db50
  goto L57dcc0;  // @100_57db50
  L57dcae:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L57dcbd;  // @102_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_57db50
  PS[0] = esi;  // @104_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(PS[0]));  // @105_57db50
  ecx = edx = 0;  // @106_57db50
  L57dcbd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @108_57db50
  L57dcc0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 572), sizeof v); (u32)v; });  // @110_57db50
  PS[0] = ecx;  // @111_57db50
  ecx = (u32)(edi + 572);  // @112_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @113_57db50
  ecx = edx = 0;  // @114_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 612), sizeof v); (u32)v; });  // @115_57db50
  ecx = (u32)(edi + 612);  // @116_57db50
  edx = (u32)(EBP - 32);  // @117_57db50
  ebx = (ebx + (u32)(8));  // @118_57db50
  PS[0] = edx;  // @119_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @120_57db50
  ecx = edx = 0;  // @121_57db50
  edx = eax;  // @122_57db50
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @123_57db50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }) != (u32)(0)) goto L57dc23;  // @124_57db50
  L57dcf5:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @126_57db50
  SEH_LEAVE();  // @127_57db50
  return eax;  // @128_57db50
}
PCREG(57db50, lifted_57db50);

extern "C" u32 THISCALL lifted_48a880(u32 ecx_in) {
  SEH_ENTER(0x667760);  // @h_48a880
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_48a880
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2788), sizeof v); (u32)v; });  // @1_48a880
  { u32 v = (u32)((u32)(6870332)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_48a880
  if ((edi & edi) == 0) goto L48a8cb;  // @3_48a880
  ecx = edi;  // @4_48a880
  eax = ext_49df00_thiscall1(ecx);  // @5_48a880
  ecx = edx = 0;  // @6_48a880
  PS[1] = edi;  // @7_48a880
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(8));  // @8_48a880
  ecx = edx = 0;  // @9_48a880
  L48a8cb:;
  ecx = esi;  // @11_48a880
  eax = ext_48fa70_thiscall1(ecx);  // @12_48a880
  ecx = edx = 0;  // @13_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2796), sizeof v); (u32)v; });  // @14_48a880
  if ((eax & eax) == 0) goto L48a8f1;  // @15_48a880
  PS[1] = eax;  // @16_48a880
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(0));  // @17_48a880
  ecx = edx = 0;  // @18_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2796), &v, sizeof v); }  // @19_48a880
  L48a8f1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2780), sizeof v); (u32)v; });  // @21_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2792), &v, sizeof v); }  // @22_48a880
  if ((ecx & ecx) == 0) goto L48a919;  // @23_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @25_48a880
  ecx = edx = 0;  // @26_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2780), &v, sizeof v); }  // @27_48a880
  L48a919:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @29_48a880
  if ((edi & edi) == 0) goto L48a939;  // @30_48a880
  ecx = edi;  // @31_48a880
  eax = ext_4958e0_thiscall1(ecx);  // @32_48a880
  ecx = edx = 0;  // @33_48a880
  PS[1] = edi;  // @34_48a880
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(105));  // @35_48a880
  ecx = edx = 0;  // @36_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @37_48a880
  L48a939:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 23861), sizeof v); (u32)v; });  // @39_48a880
  if ((edi & edi) == 0) goto L48a95f;  // @40_48a880
  ecx = edi;  // @41_48a880
  eax = ext_49b680_thiscall1(ecx);  // @42_48a880
  ecx = edx = 0;  // @43_48a880
  PS[1] = edi;  // @44_48a880
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(65));  // @45_48a880
  ecx = edx = 0;  // @46_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 23861), &v, sizeof v); }  // @47_48a880
  L48a95f:;
  edi = (u32)(esi + 28);  // @49_48a880
  if ((edi & edi) == 0) goto L48a99f;  // @50_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_48a880
  ecx = (u32)(EBP - 24);  // @52_48a880
  PS[0] = ecx;  // @53_48a880
  ecx = edi;  // @54_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @55_48a880
  ecx = edx = 0;  // @56_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @57_48a880
  ecx = (u32)(EBP - 24);  // @58_48a880
  PS[0] = ecx;  // @59_48a880
  ecx = edi;  // @60_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @61_48a880
  ecx = edx = 0;  // @62_48a880
  if ((eax & eax) == 0) goto L48a99f;  // @63_48a880
  L48a980:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @65_48a880
  if ((ecx & ecx) == 0) goto L48a990;  // @66_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @68_48a880
  ecx = edx = 0;  // @69_48a880
  L48a990:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @71_48a880
  ecx = (u32)(EBP - 24);  // @72_48a880
  PS[0] = ecx;  // @73_48a880
  ecx = edi;  // @74_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @75_48a880
  ecx = edx = 0;  // @76_48a880
  if ((eax & eax) != 0) goto L48a980;  // @77_48a880
  L48a99f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7261), sizeof v); (u32)v; });  // @79_48a880
  if ((eax & eax) == 0) goto L48a9be;  // @80_48a880
  PS[1] = eax;  // @81_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7261), &v, sizeof v); }  // @82_48a880
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(0));  // @83_48a880
  ecx = edx = 0;  // @84_48a880
  L48a9be:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @86_48a880
  if ((eax & eax) == 0) goto L48a9d0;  // @87_48a880
  PS[1] = eax;  // @88_48a880
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(24));  // @89_48a880
  ecx = edx = 0;  // @90_48a880
  L48a9d0:;
  ecx = esi;  // @92_48a880
  eax = ext_48fa10_thiscall1(ecx);  // @93_48a880
  ecx = edx = 0;  // @94_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2999), sizeof v); (u32)v; });  // @95_48a880
  if ((eax & eax) == 0) goto L48a9f6;  // @96_48a880
  PS[1] = eax;  // @97_48a880
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @98_48a880
  ecx = edx = 0;  // @99_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2999), &v, sizeof v); }  // @100_48a880
  L48a9f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3003), sizeof v); (u32)v; });  // @102_48a880
  if ((eax & eax) == 0) goto L48aa15;  // @103_48a880
  PS[1] = eax;  // @104_48a880
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @105_48a880
  ecx = edx = 0;  // @106_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3003), &v, sizeof v); }  // @107_48a880
  L48aa15:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338648), sizeof v); (u32)v; }));  // @111_48a880
  ecx = edx = 0;  // @112_48a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338648), sizeof v); (u32)v; });  // @113_48a880
  if ((ecx & ecx) == 0) goto L48aa39;  // @114_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @116_48a880
  ecx = edx = 0;  // @117_48a880
  L48aa39:;
  ecx = (u32)(esi + 7265);  // @119_48a880
  eax = ext_4d2330_thiscall1(ecx);  // @120_48a880
  ecx = edx = 0;  // @121_48a880
  ecx = (u32)(esi + 3021);  // @122_48a880
  eax = ext_4cbec0_thiscall1(ecx);  // @123_48a880
  ecx = edx = 0;  // @124_48a880
  ecx = (u32)(esi + 2816);  // @125_48a880
  eax = ext_4ccf60_thiscall1(ecx);  // @126_48a880
  ecx = edx = 0;  // @127_48a880
  ecx = edi;  // @128_48a880
  eax = ext_4cce40_thiscall1(ecx);  // @129_48a880
  ecx = edx = 0;  // @130_48a880
  SEH_LEAVE();  // @131_48a880
  return eax;  // @132_48a880
}
PCREG(48a880, lifted_48a880);

