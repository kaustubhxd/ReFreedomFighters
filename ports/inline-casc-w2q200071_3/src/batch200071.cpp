// batch200071.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_440ce0_thiscall2(u32, u32) __asm__("ext_440ce0");
extern "C" u32 THISCALL ext_4444a0_thiscall1(u32) __asm__("ext_4444a0");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_4999c0_thiscall2(u32, u32) __asm__("ext_4999c0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4da770_thiscall2(u32, u32) __asm__("ext_4da770");
extern "C" u32 THISCALL ext_4db2c0_thiscall3(u32, u32, u32) __asm__("ext_4db2c0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e6680_thiscall1(u32) __asm__("ext_4e6680");
extern "C" u32 THISCALL ext_54fd60_thiscall1(u32) __asm__("ext_54fd60");
extern "C" u32 THISCALL ext_557930_thiscall1(u32) __asm__("ext_557930");
extern "C" u32 THISCALL ext_6361e0_thiscall1(u32) __asm__("ext_6361e0");
extern "C" u32 THISCALL ext_6363a0_thiscall1(u32) __asm__("ext_6363a0");
extern "C" u32 THISCALL ext_637a30_thiscall3(u32, u32, u32) __asm__("ext_637a30");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_46f2d0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666e76);  // @h_46f2d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_46f2d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @3_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @6_46f2d0
  ecx = edx = 0;  // @7_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_46f2d0
  edi = eax;  // @9_46f2d0
  ecx = ebx;  // @10_46f2d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 324), &v, sizeof v); }  // @11_46f2d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @12_46f2d0
  ecx = edx = 0;  // @13_46f2d0
  ecx = eax;  // @14_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 796), sizeof v); (u32)v; });  // @16_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(edi));  // @17_46f2d0
  ecx = edx = 0;  // @18_46f2d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L46f3d7;  // @19_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @20_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(3888));  // @22_46f2d0
  ecx = edx = 0;  // @23_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_46f2d0
  edi = eax;  // @25_46f2d0
  eax = (u32)(EBP - 320);  // @26_46f2d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @27_46f2d0
  ecx = ebx;  // @28_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @29_46f2d0
  ecx = edx = 0;  // @30_46f2d0
  ebx = eax;  // @31_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; });  // @32_46f2d0
  ecx = (u32)(EBP - 192);  // @33_46f2d0
  ecx = eax;  // @34_46f2d0
  reg.state = (s32)((u32)(0));  // @35_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(ecx), (u32)(1));  // @37_46f2d0
  ecx = edx = 0;  // @38_46f2d0
  esi = eax;  // @39_46f2d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_46f2d0
  ecx = ebx;  // @41_46f2d0
  reg.state = (s32)((u32)(1));  // @42_46f2d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @43_46f2d0
  ecx = edx = 0;  // @44_46f2d0
  ecx = esi;  // @45_46f2d0
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @46_46f2d0
  ecx = edx = 0;  // @47_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }), (u32)(6852148), (u32)(eax));  // @48_46f2d0
  ecx = edx = 0;  // @49_46f2d0
  ecx = (u32)(EBP - 192);  // @50_46f2d0
  eax = ext_4cbec0_thiscall1(ecx);  // @51_46f2d0
  ecx = edx = 0;  // @52_46f2d0
  ecx = (u32)(EBP - 320);  // @53_46f2d0
  eax = ext_4cbec0_thiscall1(ecx);  // @54_46f2d0
  ecx = edx = 0;  // @55_46f2d0
  goto L46f4e0;  // @56_46f2d0
  L46f3d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_46f2d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @59_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @60_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ebx), (u32)(ebx), (u32)(1));  // @62_46f2d0
  ecx = edx = 0;  // @63_46f2d0
  ecx = edi;  // @64_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 752)))(ecx, (u32)(eax));  // @65_46f2d0
  ecx = edx = 0;  // @66_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @67_46f2d0
  ecx = edi;  // @68_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 768)))(ecx, (u32)(1));  // @69_46f2d0
  ecx = edx = 0;  // @70_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @71_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(3895));  // @73_46f2d0
  ecx = edx = 0;  // @74_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @75_46f2d0
  esi = (u32)(6801640);  // @76_46f2d0
  edx = esi;  // @77_46f2d0
  edi = eax;  // @78_46f2d0
  if ((ecx & ecx) != 0) edx = ecx;  // @79_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; });  // @80_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @81_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @82_46f2d0
  if ((ecx & ecx) != 0) esi = ecx;  // @83_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(edi), (u32)(6852196), (u32)(esi), (u32)(edx));  // @84_46f2d0
  ecx = edx = 0;  // @85_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @86_46f2d0
  ecx = ebx;  // @87_46f2d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @88_46f2d0
  ecx = edx = 0;  // @89_46f2d0
  ecx = eax;  // @90_46f2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @91_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 604)))(ecx, (u32)(6852232), (u32)(0));  // @92_46f2d0
  ecx = edx = 0;  // @93_46f2d0
  if ((eax & eax) == 0) goto L46f477;  // @94_46f2d0
  ecx = (u32)(EBP - 28);  // @95_46f2d0
  ecx = (u32)(EBP - 64);  // @96_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @97_46f2d0
  eax = ext_4db2c0_thiscall3(ecx, (u32)(ecx), (u32)(ecx));  // @98_46f2d0
  ecx = edx = 0;  // @99_46f2d0
  goto L46f494;  // @100_46f2d0
  L46f477:;
  ecx = (u32)(EBP - 64);  // @102_46f2d0
  eax = ext_4de7a0_thiscall1(ecx);  // @103_46f2d0
  ecx = edx = 0;  // @104_46f2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @105_46f2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @106_46f2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @107_46f2d0
  L46f494:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; });  // @109_46f2d0
  edx = (u32)(EBP - 28);  // @110_46f2d0
  edx = (u32)(EBP - 64);  // @111_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 724)))(ecx, (u32)(edx), (u32)(edx));  // @113_46f2d0
  ecx = edx = 0;  // @114_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @115_46f2d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @116_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_46f2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(esi));  // @118_46f2d0
  ecx = edx = 0;  // @119_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @120_46f2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @121_46f2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(3913));  // @122_46f2d0
  ecx = edx = 0;  // @123_46f2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @124_46f2d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6852252), (u32)(esi));  // @125_46f2d0
  ecx = edx = 0;  // @126_46f2d0
  L46f4e0:;
  SEH_LEAVE();  // @128_46f2d0
  ext_633654(G(u32, 0x6f5630));  // @129_46f2d0
  return eax;  // @130_46f2d0
}
PCREG(46f2d0, lifted_46f2d0);

extern "C" u32 THISCALL lifted_4fe9e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669b4b);  // @h_4fe9e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4fe9e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @1_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_4fe9e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4fe9e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4fe9e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @5_4fe9e0
  ecx = edx = 0;  // @6_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @7_4fe9e0
  eax = (u32)(esi + 72);  // @8_4fe9e0
  ecx = ebx;  // @9_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(1));  // @10_4fe9e0
  ecx = edx = 0;  // @11_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @12_4fe9e0
  eax = (u32)(esi + 95);  // @13_4fe9e0
  ecx = ebx;  // @14_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @15_4fe9e0
  ecx = edx = 0;  // @16_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_4fe9e0
  eax = (u32)(esi + 99);  // @18_4fe9e0
  ecx = ebx;  // @19_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @20_4fe9e0
  ecx = edx = 0;  // @21_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @22_4fe9e0
  eax = (u32)(esi + 103);  // @23_4fe9e0
  ecx = ebx;  // @24_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(1));  // @25_4fe9e0
  ecx = edx = 0;  // @26_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @27_4fe9e0
  eax = (u32)(esi + 104);  // @28_4fe9e0
  ecx = ebx;  // @29_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @30_4fe9e0
  ecx = edx = 0;  // @31_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_4fe9e0
  eax = (u32)(esi + 108);  // @33_4fe9e0
  ecx = ebx;  // @34_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @35_4fe9e0
  ecx = edx = 0;  // @36_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_4fe9e0
  eax = (u32)(esi + 112);  // @38_4fe9e0
  ecx = ebx;  // @39_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @40_4fe9e0
  ecx = edx = 0;  // @41_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_4fe9e0
  eax = (u32)(esi + 228);  // @43_4fe9e0
  ecx = ebx;  // @44_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @45_4fe9e0
  ecx = edx = 0;  // @46_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @47_4fe9e0
  eax = (u32)(esi + 232);  // @48_4fe9e0
  ecx = ebx;  // @49_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @50_4fe9e0
  ecx = edx = 0;  // @51_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @52_4fe9e0
  esi = (u32)(ebx + 36);  // @53_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @54_4fe9e0
  edi = (u32)(EBP - 296);  // @55_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @56_4fe9e0
  ecx = (u32)(69);  // @57_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 324), &v, sizeof v); }  // @58_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @59_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 320), &v, sizeof v); }  // @60_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @61_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 316), &v, sizeof v); }  // @62_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @63_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 312), &v, sizeof v); }  // @64_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @65_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @66_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @67_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @68_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @69_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @70_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 312), sizeof v); (u32)v; });  // @71_4fe9e0
  { u32 v = (u32)((u32)(6875596)); __builtin_memcpy((void *)(u32)(EBP - 332), &v, sizeof v); }  // @72_4fe9e0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @73_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @74_4fe9e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 336), sizeof v); (u32)v; });  // @75_4fe9e0
  ecx = (u32)(EBP - 332);  // @76_4fe9e0
  reg.state = (s32)((u32)(0));  // @77_4fe9e0
  eax = (u32)(ebx + 73);  // @78_4fe9e0
  eax = ext_4999c0_thiscall2(ecx, (u32)(eax));  // @79_4fe9e0
  ecx = edx = 0;  // @80_4fe9e0
  eax = (u32)(ebx + 75);  // @81_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @82_4fe9e0
  ecx = (u32)(EBP - 332);  // @83_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(eax));  // @84_4fe9e0
  ecx = edx = 0;  // @85_4fe9e0
  eax = (u32)(ebx + 77);  // @86_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @87_4fe9e0
  ecx = (u32)(EBP - 332);  // @88_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(eax));  // @89_4fe9e0
  ecx = edx = 0;  // @90_4fe9e0
  eax = (u32)(ebx + 79);  // @91_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @92_4fe9e0
  ecx = (u32)(EBP - 332);  // @93_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(eax));  // @94_4fe9e0
  ecx = edx = 0;  // @95_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_4fe9e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @97_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_4fe9e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @99_4fe9e0
  ecx = edx = 0;  // @100_4fe9e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_4fe9e0
  esi = eax;  // @102_4fe9e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @103_4fe9e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }), (u32)(16));  // @106_4fe9e0
  ecx = edx = 0;  // @107_4fe9e0
  ecx = esi;  // @108_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6891148), (u32)(eax));  // @109_4fe9e0
  ecx = edx = 0;  // @110_4fe9e0
  ecx = (u32)(EBP - 332);  // @111_4fe9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 212), &v, sizeof v); }  // @112_4fe9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 216), &v, sizeof v); }  // @113_4fe9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 220), &v, sizeof v); }  // @114_4fe9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 224), &v, sizeof v); }  // @115_4fe9e0
  eax = ext_499970_thiscall1(ecx);  // @116_4fe9e0
  ecx = edx = 0;  // @117_4fe9e0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @118_4fe9e0
  SEH_LEAVE();  // @119_4fe9e0
  ext_633654(G(u32, 0x6f5630));  // @120_4fe9e0
  return eax;  // @121_4fe9e0
}
PCREG(4fe9e0, lifted_4fe9e0);

extern "C" u32 THISCALL lifted_612c00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e338);  // @h_612c00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_612c00
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_612c00
  ecx = (u32)(EBP - 64);  // @2_612c00
  eax = ext_6361e0_thiscall1(ecx);  // @3_612c00
  ecx = edx = 0;  // @4_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_612c00
  ecx = ebx;  // @6_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139296), sizeof v); (u32)v; });  // @7_612c00
  reg.state = (s32)((u32)(0));  // @8_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @9_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @10_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @11_612c00
  ecx = edx = 0;  // @12_612c00
  if (eax != (u32)(1146639409)) goto L612c65;  // @13_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139304), sizeof v); (u32)v; });  // @14_612c00
  goto L612c79;  // @15_612c00
  L612c65:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_612c00
  ecx = ebx;  // @18_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @19_612c00
  ecx = edx = 0;  // @20_612c00
  if (eax != (u32)(1146639411)) goto L612c83;  // @21_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139308), sizeof v); (u32)v; });  // @22_612c00
  L612c79:;
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @24_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @25_612c00
  L612c83:;
  if ((edi & edi) != 0) goto L612c97;  // @27_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139296), sizeof v); (u32)v; });  // @28_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @29_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @30_612c00
  L612c97:;
  if (edi == (u32)(25)) goto L612ca1;  // @32_612c00
  if (edi != (u32)(26)) goto L612ca8;  // @33_612c00
  L612ca1:;
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @35_612c00
  L612ca8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_612c00
  ecx = ebx;  // @38_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @39_612c00
  ecx = edx = 0;  // @40_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @43_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 147), sizeof v); (u32)v; });  // @44_612c00
  ecx = (u32)(eax - 1);  // @45_612c00
  if (ecx < edi) edi = ecx;  // @46_612c00
  ecx = ebx;  // @47_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 56)))(ecx, (u32)(edi));  // @48_612c00
  ecx = edx = 0;  // @49_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @50_612c00
  if (ecx > ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139316), sizeof v); (u32)v; })) goto L612ce4;  // @51_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @52_612c00
  if (eax <= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139320), sizeof v); (u32)v; })) goto L612d24;  // @53_612c00
  L612ce4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; }) != (u32)(1)) goto L612d03;  // @55_612c00
  ecx = (u32)(EBP - 64);  // @56_612c00
  eax = ext_637a30_thiscall3(ecx, (u32)(ebx), (u32)(1));  // @57_612c00
  ecx = edx = 0;  // @58_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @59_612c00
  ebx = (u32)(EBP - 64);  // @60_612c00
  ecx = ebx;  // @61_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @62_612c00
  ecx = edx = 0;  // @63_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @64_612c00
  L612d03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @66_612c00
  ecx = ebx;  // @67_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, (u32)(edi));  // @68_612c00
  ecx = edx = 0;  // @69_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @70_612c00
  if (ecx > ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139316), sizeof v); (u32)v; })) goto L612d21;  // @71_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @72_612c00
  if (eax <= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139320), sizeof v); (u32)v; })) goto L612d24;  // @73_612c00
  L612d21:;
  edi = (edi + 1);  // @75_612c00
  goto L612d03;  // @76_612c00
  L612d24:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @78_612c00
  ecx = ebx;  // @79_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, (u32)(edi));  // @80_612c00
  ecx = edx = 0;  // @81_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139268), sizeof v); (u32)v; });  // @82_612c00
  ecx = (u32)(EBP - 84);  // @83_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @84_612c00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @85_612c00
  ecx = (ecx - edi);  // @86_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 80)))(ecx, (u32)(edx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }), (u32)(ecx), (u32)(0), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }), (u32)(1), (u32)(ecx));  // @87_612c00
  ecx = edx = 0;  // @88_612c00
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; }) != (u32)(32)) goto L612d7a;  // @89_612c00
  { u32 v = (u32)((u32)(4278190080)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @90_612c00
  { u32 v = (u32)((u32)(16711680)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @91_612c00
  { u32 v = (u32)((u32)(65280)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @92_612c00
  { u32 v = (u32)((u32)(255)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @93_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @94_612c00
  goto L612dc1;  // @95_612c00
  L612d7a:;
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @97_612c00
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }) != (u32)(25)) goto L612da5;  // @98_612c00
  { u32 v = (u32)((u32)(32768)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @99_612c00
  { u32 v = (u32)((u32)(31744)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @100_612c00
  { u32 v = (u32)((u32)(992)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @101_612c00
  { u32 v = (u32)((u32)(31)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @102_612c00
  goto L612dc1;  // @103_612c00
  L612da5:;
  { u32 v = (u32)((u32)(61440)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @105_612c00
  { u32 v = (u32)((u32)(3840)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @106_612c00
  { u32 v = (u32)((u32)(240)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @107_612c00
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @108_612c00
  L612dc1:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @110_612c00
  if (edi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; })) goto L612e3e;  // @111_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @112_612c00
  L612dd1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @114_612c00
  ecx = ebx;  // @115_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, (u32)(edi));  // @116_612c00
  ecx = edx = 0;  // @117_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @118_612c00
  esi = eax;  // @119_612c00
  eax = (u32)(EBP - 80);  // @120_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @121_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }), (u32)(eax), (u32)(0), (u32)(0));  // @122_612c00
  ecx = edx = 0;  // @123_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @124_612c00
  ecx = (u32)(EBP - 132);  // @125_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @126_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @127_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @128_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @129_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @130_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @131_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @132_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @133_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @134_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @135_612c00
  ecx = ebx;  // @136_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(ecx), (u32)(edi));  // @137_612c00
  ecx = edx = 0;  // @138_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @139_612c00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @140_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @141_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 68)))(ecx, (u32)(eax), (u32)(esi));  // @142_612c00
  ecx = edx = 0;  // @143_612c00
  edi = (edi + 1);  // @144_612c00
  esi = (esi + 1);  // @145_612c00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @146_612c00
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; })) goto L612dd1;  // @147_612c00
  L612e3e:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @149_612c00
  ecx = (u32)(EBP - 64);  // @150_612c00
  eax = ext_6363a0_thiscall1(ecx);  // @151_612c00
  ecx = edx = 0;  // @152_612c00
  eax = esi;  // @153_612c00
  SEH_LEAVE();  // @154_612c00
  ext_633654(G(u32, 0x6f5630));  // @155_612c00
  return eax;  // @156_612c00
}
PCREG(612c00, lifted_612c00);

extern "C" u32 THISCALL lifted_4af780(u32 ecx_in) {
  SEH_ENTER(0x668936);  // @h_4af780
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4af780
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; }) != (u32)(0)) goto L4af7f8;  // @1_4af780
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; }) != (u32)(0)) goto L4af7f8;  // @2_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @6_4af780
  ecx = edx = 0;  // @7_4af780
  ecx = (u32)(EBP - 276);  // @8_4af780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @9_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_4af780
  ecx = eax;  // @11_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(ecx));  // @12_4af780
  ecx = edx = 0;  // @13_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @14_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @15_4af780
  L4af7f8:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }) != (u32)(0)) goto L4af83a;  // @17_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @21_4af780
  ecx = edx = 0;  // @22_4af780
  ecx = (u32)(EBP - 276);  // @23_4af780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @24_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @25_4af780
  ecx = eax;  // @26_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), (u32)(ecx));  // @27_4af780
  ecx = edx = 0;  // @28_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @29_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @30_4af780
  L4af83a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; }) != (u32)(0)) goto L4af8ac;  // @32_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @35_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @38_4af780
  ecx = edx = 0;  // @39_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @41_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, (u32)(eax));  // @42_4af780
  ecx = edx = 0;  // @43_4af780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @44_4af780
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; }) == (u32)(0)) goto L4af8ac;  // @45_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @46_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(50));  // @48_4af780
  ecx = edx = 0;  // @49_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @50_4af780
  edx = (u32)(6801640);  // @51_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @52_4af780
  if ((ecx & ecx) != 0) edx = ecx;  // @53_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6885096), (u32)(edx));  // @55_4af780
  ecx = edx = 0;  // @56_4af780
  L4af8ac:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; }) == (u32)(0)) goto L4af8bf;  // @58_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @59_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @61_4af780
  ecx = edx = 0;  // @62_4af780
  L4af8bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @64_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @65_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }));  // @67_4af780
  ecx = edx = 0;  // @68_4af780
  if ((eax & eax) != 0) goto L4af93e;  // @69_4af780
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; }) != (eax & 0xff)) goto L4af944;  // @70_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @71_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(58));  // @73_4af780
  ecx = edx = 0;  // @74_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @75_4af780
  edi = eax;  // @76_4af780
  eax = (u32)(EBP - 144);  // @77_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @79_4af780
  ecx = edx = 0;  // @80_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @81_4af780
  ecx = eax;  // @82_4af780
  reg.state = (s32)((u32)(0));  // @83_4af780
  eax = ext_4cc1d0_thiscall1(ecx);  // @84_4af780
  ecx = edx = 0;  // @85_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6885156), (u32)(eax));  // @86_4af780
  ecx = edx = 0;  // @87_4af780
  reg.state = (s32)((u32)(4294967295));  // @88_4af780
  ecx = (u32)(EBP - 144);  // @89_4af780
  eax = ext_4cbec0_thiscall1(ecx);  // @90_4af780
  ecx = edx = 0;  // @91_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @92_4af780
  ecx = ebx;  // @93_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @94_4af780
  ecx = edx = 0;  // @95_4af780
  goto L4af9c8;  // @96_4af780
  L4af93e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; }) == (u32)(0)) goto L4af9bb;  // @98_4af780
  L4af944:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @101_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 88), sizeof v); (u32)v; }));  // @103_4af780
  ecx = edx = 0;  // @104_4af780
  if ((eax & eax) != 0) goto L4af9bb;  // @105_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @106_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6885016), (u32)(65));  // @108_4af780
  ecx = edx = 0;  // @109_4af780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @110_4af780
  edi = eax;  // @111_4af780
  eax = (u32)(EBP - 272);  // @112_4af780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_4af780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @114_4af780
  ecx = edx = 0;  // @115_4af780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @116_4af780
  ecx = eax;  // @117_4af780
  reg.state = (s32)((u32)(1));  // @118_4af780
  eax = ext_4cc1d0_thiscall1(ecx);  // @119_4af780
  ecx = edx = 0;  // @120_4af780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6885216), (u32)(eax));  // @121_4af780
  ecx = edx = 0;  // @122_4af780
  reg.state = (s32)((u32)(4294967295));  // @123_4af780
  ecx = (u32)(EBP - 272);  // @124_4af780
  eax = ext_4cbec0_thiscall1(ecx);  // @125_4af780
  ecx = edx = 0;  // @126_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @127_4af780
  ecx = ebx;  // @128_4af780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @129_4af780
  ecx = edx = 0;  // @130_4af780
  goto L4af9c8;  // @131_4af780
  L4af9bb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @133_4af780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_4af780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(1));  // @135_4af780
  ecx = edx = 0;  // @136_4af780
  L4af9c8:;
  SEH_LEAVE();  // @138_4af780
  ext_633654(G(u32, 0x6f5630));  // @139_4af780
  return eax;  // @140_4af780
}
PCREG(4af780, lifted_4af780);

extern "C" u32 THISCALL lifted_444530(u32 ecx_in) {
  SEH_ENTER(0x665f5b);  // @h_444530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @1_444530
  eax = ext_4444a0_thiscall1(ecx);  // @2_444530
  ecx = edx = 0;  // @3_444530
  ecx = (u32)(EBP - 188);  // @4_444530
  eax = ext_4ccba0_thiscall1(ecx);  // @5_444530
  ecx = edx = 0;  // @6_444530
  ecx = (u32)(EBP - 220);  // @7_444530
  reg.state = (s32)((u32)(0));  // @8_444530
  eax = ext_440ce0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 184), sizeof v); (u32)v; }));  // @9_444530
  ecx = edx = 0;  // @10_444530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @11_444530
  if ((ebx & ebx) == 0) goto L444636;  // @12_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @13_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @14_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @15_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @16_444530
  L4445b4:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @18_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @19_444530
  edi = (edi & (u32)(4294967288));  // @20_444530
  eax = (eax & (u32)(4294967288));  // @21_444530
  ebx = (ebx + (u32)(8));  // @22_444530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @23_444530
  if (edi > eax) goto L4445ef;  // @24_444530
  esi = eax;  // @25_444530
  L4445d0:;
  ecx = (u32)(EBP - 188);  // @27_444530
  eax = ext_4cd540_thiscall2(ecx, (u32)(edi));  // @28_444530
  ecx = edx = 0;  // @29_444530
  edi = (edi + (u32)(112));  // @30_444530
  if (edi <= esi) goto L4445d0;  // @31_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @32_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @33_444530
  L4445ef:;
  if (ebx != ecx) goto L44462c;  // @35_444530
  if ((esi & esi) == 0) goto L444630;  // @36_444530
  L4445f7:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L444630;  // @38_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @39_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @40_444530
  if ((esi & esi) == 0) goto L444630;  // @41_444530
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) < (u32)(2)) goto L4445f7;  // @42_444530
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) & 0xff);  // @43_444530
  ebx = (u32)(esi + 12);  // @44_444530
  if (((eax & 0xff) & (u32)(1)) == 0) goto L44461d;  // @45_444530
  ebx = (ebx + (u32)(4));  // @46_444530
  L44461d:;
  ecx = (eax & 0xff);  // @48_444530
  ecx = (ecx + (u32)(3));  // @49_444530
  ecx = (u32)(esi + ecx*4);  // @50_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @51_444530
  L44462c:;
  if ((ebx & ebx) != 0) goto L4445b4;  // @53_444530
  L444630:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @55_444530
  L444636:;
  ecx = (u32)(EBP - 220);  // @57_444530
  eax = ext_440ce0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 180), sizeof v); (u32)v; }));  // @58_444530
  ecx = edx = 0;  // @59_444530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @60_444530
  if ((ebx & ebx) == 0) goto L4446f6;  // @61_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @62_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @63_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @64_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @65_444530
  L444670:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @67_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @68_444530
  edi = (edi & (u32)(4294967288));  // @69_444530
  eax = (eax & (u32)(4294967288));  // @70_444530
  ebx = (ebx + (u32)(8));  // @71_444530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @72_444530
  if (edi > eax) goto L4446af;  // @73_444530
  esi = eax;  // @74_444530
  L444690:;
  ecx = (u32)(EBP - 188);  // @76_444530
  eax = ext_4cd540_thiscall2(ecx, (u32)(edi));  // @77_444530
  ecx = edx = 0;  // @78_444530
  edi = (edi + (u32)(112));  // @79_444530
  if (edi <= esi) goto L444690;  // @80_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @81_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @82_444530
  L4446af:;
  if (ebx != ecx) goto L4446ec;  // @84_444530
  if ((esi & esi) == 0) goto L4446f0;  // @85_444530
  L4446b7:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4446f0;  // @87_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @88_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @89_444530
  if ((esi & esi) == 0) goto L4446f0;  // @90_444530
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) < (u32)(2)) goto L4446b7;  // @91_444530
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) & 0xff);  // @92_444530
  ebx = (u32)(esi + 12);  // @93_444530
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4446dd;  // @94_444530
  ebx = (ebx + (u32)(4));  // @95_444530
  L4446dd:;
  ecx = (eax & 0xff);  // @97_444530
  ecx = (ecx + (u32)(3));  // @98_444530
  ecx = (u32)(esi + ecx*4);  // @99_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @100_444530
  L4446ec:;
  if ((ebx & ebx) != 0) goto L444670;  // @102_444530
  L4446f0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @104_444530
  L4446f6:;
  ecx = (u32)(EBP - 220);  // @106_444530
  eax = ext_440ce0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 188), sizeof v); (u32)v; }));  // @107_444530
  ecx = edx = 0;  // @108_444530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @109_444530
  if ((ebx & ebx) == 0) goto L4447b6;  // @110_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @111_444530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @112_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @113_444530
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @114_444530
  L444730:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @116_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @117_444530
  esi = (esi & (u32)(4294967288));  // @118_444530
  eax = (eax & (u32)(4294967288));  // @119_444530
  ebx = (ebx + (u32)(8));  // @120_444530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @121_444530
  if (esi > eax) goto L44476f;  // @122_444530
  edi = eax;  // @123_444530
  L444750:;
  ecx = (u32)(EBP - 188);  // @125_444530
  eax = ext_4cd540_thiscall2(ecx, (u32)(esi));  // @126_444530
  ecx = edx = 0;  // @127_444530
  esi = (esi + (u32)(112));  // @128_444530
  if (esi <= edi) goto L444750;  // @129_444530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @130_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @131_444530
  L44476f:;
  if (ebx != ecx) goto L4447ac;  // @133_444530
  if ((edi & edi) == 0) goto L4447b0;  // @134_444530
  L444777:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4447b0;  // @136_444530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @137_444530
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @138_444530
  if ((edi & edi) == 0) goto L4447b0;  // @139_444530
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) < (u32)(2)) goto L444777;  // @140_444530
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) & 0xff);  // @141_444530
  ebx = (u32)(edi + 12);  // @142_444530
  if (((eax & 0xff) & (u32)(1)) == 0) goto L44479d;  // @143_444530
  ebx = (ebx + (u32)(4));  // @144_444530
  L44479d:;
  ecx = (eax & 0xff);  // @146_444530
  ecx = (ecx + (u32)(3));  // @147_444530
  ecx = (u32)(edi + ecx*4);  // @148_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @149_444530
  L4447ac:;
  if ((ebx & ebx) != 0) goto L444730;  // @151_444530
  L4447b0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @153_444530
  L4447b6:;
  eax = (u32)(EBP - 232);  // @155_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @156_444530
  ecx = (u32)(EBP - 188);  // @157_444530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(eax));  // @158_444530
  ecx = edx = 0;  // @159_444530
  eax = (u32)(EBP - 232);  // @160_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @161_444530
  ecx = (u32)(EBP - 188);  // @162_444530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @163_444530
  ecx = edx = 0;  // @164_444530
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; }) == (u32)(0)) goto L444817;  // @165_444530
  L4447f0:;
  ecx = eax;  // @167_444530
  eax = ext_4da770_thiscall2(ecx, (u32)(esi));  // @168_444530
  ecx = edx = 0;  // @169_444530
  eax = (u32)(EBP - 232);  // @170_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @171_444530
  ecx = (u32)(EBP - 188);  // @172_444530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @173_444530
  ecx = edx = 0;  // @174_444530
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; }) != (u32)(0)) goto L4447f0;  // @175_444530
  L444817:;
  ecx = (u32)(EBP - 188);  // @177_444530
  eax = ext_4ccf60_thiscall1(ecx);  // @178_444530
  ecx = edx = 0;  // @179_444530
  SEH_LEAVE();  // @180_444530
  ext_633654(G(u32, 0x6f5630));  // @181_444530
  return eax;  // @182_444530
}
PCREG(444530, lifted_444530);

extern "C" u32 THISCALL lifted_54f890(u32 ecx_in) {
  SEH_ENTER(0x66ae28);  // @h_54f890
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_54f890
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_54f890
  eax = ext_4e6680_thiscall1(ecx);  // @2_54f890
  ecx = edx = 0;  // @3_54f890
  reg.state = (s32)((u32)(0));  // @4_54f890
  { u32 v = (u32)((u32)(6965892)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @5_54f890
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @6_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @7_54f890
  ecx = edx = 0;  // @8_54f890
  if ((eax & eax) == 0) goto L54f8e5;  // @9_54f890
  { u32 v = (u32)((u32)(6966180)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @10_54f890
  goto L54f8e7;  // @11_54f890
  L54f8e5:;
  eax = 0;  // @13_54f890
  L54f8e7:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @15_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @16_54f890
  ecx = edx = 0;  // @17_54f890
  if ((eax & eax) == 0) goto L54f900;  // @18_54f890
  { u32 v = (u32)((u32)(6965956)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @19_54f890
  goto L54f902;  // @20_54f890
  L54f900:;
  eax = 0;  // @22_54f890
  L54f902:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @24_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @25_54f890
  ecx = edx = 0;  // @26_54f890
  if ((eax & eax) == 0) goto L54f91b;  // @27_54f890
  { u32 v = (u32)((u32)(6965972)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @28_54f890
  goto L54f91d;  // @29_54f890
  L54f91b:;
  eax = 0;  // @31_54f890
  L54f91d:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @33_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @34_54f890
  ecx = edx = 0;  // @35_54f890
  if ((eax & eax) == 0) goto L54f936;  // @36_54f890
  { u32 v = (u32)((u32)(6965964)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_54f890
  goto L54f938;  // @38_54f890
  L54f936:;
  eax = 0;  // @40_54f890
  L54f938:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @42_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @43_54f890
  ecx = edx = 0;  // @44_54f890
  if ((eax & eax) == 0) goto L54f951;  // @45_54f890
  { u32 v = (u32)((u32)(6932296)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_54f890
  goto L54f953;  // @47_54f890
  L54f951:;
  eax = 0;  // @49_54f890
  L54f953:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @51_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @52_54f890
  ecx = edx = 0;  // @53_54f890
  if ((eax & eax) == 0) goto L54f96c;  // @54_54f890
  { u32 v = (u32)((u32)(6965980)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @55_54f890
  goto L54f96e;  // @56_54f890
  L54f96c:;
  eax = 0;  // @58_54f890
  L54f96e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 37), &v, sizeof v); }  // @60_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @61_54f890
  ecx = edx = 0;  // @62_54f890
  if ((eax & eax) == 0) goto L54f987;  // @63_54f890
  { u32 v = (u32)((u32)(6965988)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @64_54f890
  goto L54f989;  // @65_54f890
  L54f987:;
  eax = 0;  // @67_54f890
  L54f989:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 41), &v, sizeof v); }  // @69_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @70_54f890
  ecx = edx = 0;  // @71_54f890
  if ((eax & eax) == 0) goto L54f9a2;  // @72_54f890
  { u32 v = (u32)((u32)(6965996)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @73_54f890
  goto L54f9a4;  // @74_54f890
  L54f9a2:;
  eax = 0;  // @76_54f890
  L54f9a4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 45), &v, sizeof v); }  // @78_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @79_54f890
  ecx = edx = 0;  // @80_54f890
  if ((eax & eax) == 0) goto L54f9bd;  // @81_54f890
  { u32 v = (u32)((u32)(6966028)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @82_54f890
  goto L54f9bf;  // @83_54f890
  L54f9bd:;
  eax = 0;  // @85_54f890
  L54f9bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 61), &v, sizeof v); }  // @87_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @88_54f890
  ecx = edx = 0;  // @89_54f890
  if ((eax & eax) == 0) goto L54f9d8;  // @90_54f890
  { u32 v = (u32)((u32)(6966004)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @91_54f890
  goto L54f9da;  // @92_54f890
  L54f9d8:;
  eax = 0;  // @94_54f890
  L54f9da:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 49), &v, sizeof v); }  // @96_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @97_54f890
  ecx = edx = 0;  // @98_54f890
  if ((eax & eax) == 0) goto L54f9f3;  // @99_54f890
  { u32 v = (u32)((u32)(6966012)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @100_54f890
  goto L54f9f5;  // @101_54f890
  L54f9f3:;
  eax = 0;  // @103_54f890
  L54f9f5:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 53), &v, sizeof v); }  // @105_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @106_54f890
  ecx = edx = 0;  // @107_54f890
  if ((eax & eax) == 0) goto L54fa0e;  // @108_54f890
  { u32 v = (u32)((u32)(6966020)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @109_54f890
  goto L54fa10;  // @110_54f890
  L54fa0e:;
  eax = 0;  // @112_54f890
  L54fa10:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 57), &v, sizeof v); }  // @114_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @115_54f890
  ecx = edx = 0;  // @116_54f890
  if ((eax & eax) == 0) goto L54fa29;  // @117_54f890
  { u32 v = (u32)((u32)(6966036)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @118_54f890
  goto L54fa2b;  // @119_54f890
  L54fa29:;
  eax = 0;  // @121_54f890
  L54fa2b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65), &v, sizeof v); }  // @123_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @124_54f890
  ecx = edx = 0;  // @125_54f890
  if ((eax & eax) == 0) goto L54fa44;  // @126_54f890
  { u32 v = (u32)((u32)(6966044)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @127_54f890
  goto L54fa46;  // @128_54f890
  L54fa44:;
  eax = 0;  // @130_54f890
  L54fa46:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @132_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @133_54f890
  ecx = edx = 0;  // @134_54f890
  if ((eax & eax) == 0) goto L54fa5f;  // @135_54f890
  { u32 v = (u32)((u32)(6966052)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @136_54f890
  goto L54fa61;  // @137_54f890
  L54fa5f:;
  eax = 0;  // @139_54f890
  L54fa61:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 73), &v, sizeof v); }  // @141_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @142_54f890
  ecx = edx = 0;  // @143_54f890
  if ((eax & eax) == 0) goto L54fa7a;  // @144_54f890
  { u32 v = (u32)((u32)(6966060)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @145_54f890
  goto L54fa7c;  // @146_54f890
  L54fa7a:;
  eax = 0;  // @148_54f890
  L54fa7c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 77), &v, sizeof v); }  // @150_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @151_54f890
  ecx = edx = 0;  // @152_54f890
  if ((eax & eax) == 0) goto L54fa95;  // @153_54f890
  { u32 v = (u32)((u32)(6966092)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @154_54f890
  goto L54fa97;  // @155_54f890
  L54fa95:;
  eax = 0;  // @157_54f890
  L54fa97:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 81), &v, sizeof v); }  // @159_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @160_54f890
  ecx = edx = 0;  // @161_54f890
  if ((eax & eax) == 0) goto L54fab0;  // @162_54f890
  { u32 v = (u32)((u32)(6966100)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @163_54f890
  goto L54fab2;  // @164_54f890
  L54fab0:;
  eax = 0;  // @166_54f890
  L54fab2:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 85), &v, sizeof v); }  // @168_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @169_54f890
  ecx = edx = 0;  // @170_54f890
  if ((eax & eax) == 0) goto L54facb;  // @171_54f890
  { u32 v = (u32)((u32)(6966108)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @172_54f890
  goto L54facd;  // @173_54f890
  L54facb:;
  eax = 0;  // @175_54f890
  L54facd:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @177_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @178_54f890
  ecx = edx = 0;  // @179_54f890
  if ((eax & eax) == 0) goto L54fae6;  // @180_54f890
  { u32 v = (u32)((u32)(6966116)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @181_54f890
  goto L54fae8;  // @182_54f890
  L54fae6:;
  eax = 0;  // @184_54f890
  L54fae8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @186_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @187_54f890
  ecx = edx = 0;  // @188_54f890
  if ((eax & eax) == 0) goto L54fb01;  // @189_54f890
  { u32 v = (u32)((u32)(6966084)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @190_54f890
  goto L54fb03;  // @191_54f890
  L54fb01:;
  eax = 0;  // @193_54f890
  L54fb03:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @195_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @196_54f890
  ecx = edx = 0;  // @197_54f890
  if ((eax & eax) == 0) goto L54fb1c;  // @198_54f890
  { u32 v = (u32)((u32)(6966076)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @199_54f890
  goto L54fb1e;  // @200_54f890
  L54fb1c:;
  eax = 0;  // @202_54f890
  L54fb1e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @204_54f890
  eax = ext_41e290_cdecl1((u32)(4));  // @205_54f890
  ecx = edx = 0;  // @206_54f890
  if ((eax & eax) == 0) goto L54fb37;  // @207_54f890
  { u32 v = (u32)((u32)(6966068)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @208_54f890
  goto L54fb39;  // @209_54f890
  L54fb37:;
  eax = 0;  // @211_54f890
  L54fb39:;
  ecx = 0;  // @213_54f890
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }  // @214_54f890
  eax = ext_557930_thiscall1(ecx);  // @215_54f890
  ecx = edx = 0;  // @216_54f890
  ecx = esi;  // @217_54f890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @218_54f890
  eax = ext_54fd60_thiscall1(ecx);  // @219_54f890
  ecx = edx = 0;  // @220_54f890
  eax = esi;  // @221_54f890
  SEH_LEAVE();  // @222_54f890
  return eax;  // @223_54f890
}
PCREG(54f890, lifted_54f890);

