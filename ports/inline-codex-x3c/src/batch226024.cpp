// batch226024.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_42da80_stdcall1(u32) __asm__("ext_42da80");
extern "C" u32 THISCALL ext_42de30_thiscall1(u32) __asm__("ext_42de30");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4402a0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x66c60b);  // @h_4402a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  ebx = ecx;  // @0_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @2_4402a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_4402a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_4402a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @6_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @7_4402a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @8_4402a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; })) & 0xff);  // @9_4402a0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @10_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_4402a0
  PS[1] = edx;  // @12_4402a0
  PS[2] = esi;  // @13_4402a0
  PS[3] = edi;  // @14_4402a0
  PS[4] = ecx;  // @15_4402a0
  ecx = ebx;  // @16_4402a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 448)))(ecx, (u32)(PS[4]), (u32)(PS[3]), (u32)(PS[2]), (u32)(PS[1]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; }));  // @17_4402a0
  ecx = edx = 0;  // @18_4402a0
  edi = eax;  // @19_4402a0
  if ((edi & edi) == 0) goto L440506;  // @20_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4402a0
  PS[0] = edi;  // @22_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @25_4402a0
  ecx = edx = 0;  // @26_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @27_4402a0
  ebx = eax;  // @28_4402a0
  if ((ecx & ecx) == 0) goto L440345;  // @29_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @30_4402a0
  if ((eax & eax) == 0) goto L440345;  // @31_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_4402a0
  PS[0] = eax;  // @33_4402a0
  PS[1] = ecx;  // @34_4402a0
  ecx = edi;  // @35_4402a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @36_4402a0
  ecx = edx = 0;  // @37_4402a0
  L440345:;
  ecx = (u32)(EBP - 188);  // @39_4402a0
  eax = ext_4ccba0_thiscall1(ecx);  // @40_4402a0
  ecx = edx = 0;  // @41_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @42_4402a0
  reg.state = (s32)((u32)(0));  // @43_4402a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @44_4402a0
  if ((edx & edx) == 0) goto L440399;  // @45_4402a0
  L440364:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_4402a0
  PS[0] = edx;  // @48_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @49_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @51_4402a0
  ecx = edx = 0;  // @52_4402a0
  PS[0] = eax;  // @53_4402a0
  ecx = (u32)(EBP - 188);  // @54_4402a0
  eax = ext_4cd540_thiscall2(ecx, (u32)(PS[0]));  // @55_4402a0
  ecx = edx = 0;  // @56_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @57_4402a0
  ecx = (u32)(EBP - 192);  // @58_4402a0
  PS[0] = ecx;  // @59_4402a0
  ecx = edi;  // @60_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @61_4402a0
  ecx = edx = 0;  // @62_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @63_4402a0
  if ((edx & edx) != 0) goto L440364;  // @64_4402a0
  L440399:;
  eax = (u32)(EBP - 212);  // @66_4402a0
  PS[0] = eax;  // @67_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @68_4402a0
  ecx = (u32)(EBP - 188);  // @69_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @70_4402a0
  ecx = edx = 0;  // @71_4402a0
  eax = (u32)(EBP - 212);  // @72_4402a0
  PS[0] = eax;  // @73_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @74_4402a0
  ecx = (u32)(EBP - 188);  // @75_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @76_4402a0
  ecx = edx = 0;  // @77_4402a0
  esi = eax;  // @78_4402a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }) == (u32)(0)) goto L4404e2;  // @79_4402a0
  L4403e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_4402a0
  PS[0] = esi;  // @82_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @83_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(PS[0]));  // @85_4402a0
  ecx = edx = 0;  // @86_4402a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @87_4402a0
  if ((eax & eax) == 0) goto L4404bd;  // @88_4402a0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L4404bd;  // @89_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @90_4402a0
  if ((ecx & ecx) == 0) goto L44041c;  // @91_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_4402a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @93_4402a0
  ecx = edx = 0;  // @94_4402a0
  L44041c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_4402a0
  PS[0] = esi;  // @97_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @98_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(PS[0]));  // @100_4402a0
  ecx = edx = 0;  // @101_4402a0
  if ((eax & eax) == 0) goto L4404bd;  // @102_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @103_4402a0
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @104_4402a0
  ecx = edx = 0;  // @105_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_4402a0
  PS[0] = esi;  // @107_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @108_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(PS[0]));  // @110_4402a0
  ecx = edx = 0;  // @111_4402a0
  if ((eax & eax) == 0) goto L4404bd;  // @112_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @113_4402a0
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @114_4402a0
  ecx = edx = 0;  // @115_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_4402a0
  PS[0] = esi;  // @117_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @118_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(PS[0]));  // @120_4402a0
  ecx = edx = 0;  // @121_4402a0
  if ((eax & eax) == 0) goto L4404bd;  // @122_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @123_4402a0
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @124_4402a0
  ecx = edx = 0;  // @125_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @126_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @127_4402a0
  if ((ecx & ecx) == 0) goto L4404ac;  // @128_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_4402a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @130_4402a0
  ecx = edx = 0;  // @131_4402a0
  L4404ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @133_4402a0
  PS[0] = esi;  // @134_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @135_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(PS[0]));  // @137_4402a0
  ecx = edx = 0;  // @138_4402a0
  L4404bd:;
  eax = (u32)(EBP - 212);  // @140_4402a0
  PS[0] = eax;  // @141_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @142_4402a0
  ecx = (u32)(EBP - 188);  // @143_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @144_4402a0
  ecx = edx = 0;  // @145_4402a0
  esi = eax;  // @146_4402a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }) != (u32)(0)) goto L4403e0;  // @147_4402a0
  L4404e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_4402a0
  PS[0] = ebx;  // @150_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @151_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(PS[0]));  // @153_4402a0
  ecx = edx = 0;  // @154_4402a0
  CF = (eax != 0); eax = (u32)(0 - eax);  // @155_4402a0
  ecx = (u32)(EBP - 188);  // @156_4402a0
  esi = (u32)(0 - CF);  // @157_4402a0
  esi = (esi & edi);  // @158_4402a0
  eax = ext_4ccf60_thiscall1(ecx);  // @159_4402a0
  ecx = edx = 0;  // @160_4402a0
  eax = esi;  // @161_4402a0
  L440506:;
  SEH_LEAVE();  // @163_4402a0
  ext_633654(G(u32, 0x6f5630));  // @164_4402a0
  return eax;  // @165_4402a0
}
PCREG(4402a0, lifted_4402a0);

extern "C" u32 THISCALL lifted_42a820(u32 ecx_in) {
  SEH_ENTER(0x66496c);  // @h_42a820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  edi = ecx;  // @0_42a820
  eax = ext_42de30_thiscall1(ecx);  // @1_42a820
  ecx = edx = 0;  // @2_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_42a820
  edx = (u32)(EBP - 276);  // @4_42a820
  PS[0] = edx;  // @5_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @7_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783396), (u32)(PS[0]));  // @8_42a820
  ecx = edx = 0;  // @9_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a875;  // @10_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @11_42a820
  L42a875:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_42a820
  edx = (u32)(EBP - 276);  // @14_42a820
  PS[0] = edx;  // @15_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @17_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783568), (u32)(PS[0]));  // @18_42a820
  ecx = edx = 0;  // @19_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a8da;  // @20_42a820
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7003), sizeof v); (u32)v; }) == (u32)(0)) goto L42a8c9;  // @21_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @22_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6788896), (u32)(80));  // @24_42a820
  ecx = edx = 0;  // @25_42a820
  PS[1] = eax;  // @26_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(PS[1]), (u32)(6783580));  // @28_42a820
  ecx = edx = 0;  // @29_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_42a820
  if ((eax & eax) == 0) goto L42a8c8;  // @31_42a820
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_42a820
  ecx = edx = 0;  // @33_42a820
  goto L42a8c9;  // @34_42a820
  L42a8c8:;
  __builtin_trap();  // @36_42a820
  L42a8c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @38_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_42a820
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 120)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @40_42a820
  ecx = edx = 0;  // @41_42a820
  L42a8da:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_42a820
  edx = (u32)(EBP - 276);  // @44_42a820
  PS[0] = edx;  // @45_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @47_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783656), (u32)(PS[0]));  // @48_42a820
  ecx = edx = 0;  // @49_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a933;  // @50_42a820
  ecx = (u32)(EBP - 144);  // @51_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @52_42a820
  ecx = edx = 0;  // @53_42a820
  eax = (u32)(EBP - 144);  // @54_42a820
  reg.state = (s32)((u32)(0));  // @55_42a820
  PS[0] = eax;  // @56_42a820
  ecx = (u32)(edi + 7153);  // @57_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @58_42a820
  ecx = edx = 0;  // @59_42a820
  ecx = (u32)(EBP - 144);  // @60_42a820
  reg.state = (s32)((u32)(4294967295));  // @61_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @62_42a820
  ecx = edx = 0;  // @63_42a820
  L42a933:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_42a820
  edx = (u32)(EBP - 276);  // @66_42a820
  PS[0] = edx;  // @67_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @69_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783668), (u32)(PS[0]));  // @70_42a820
  ecx = edx = 0;  // @71_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a99a;  // @72_42a820
  ecx = (u32)(EBP - 144);  // @73_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @74_42a820
  ecx = edx = 0;  // @75_42a820
  eax = (u32)(EBP - 144);  // @76_42a820
  reg.state = (s32)((u32)(1));  // @77_42a820
  esi = (u32)(edi + 7025);  // @78_42a820
  PS[0] = eax;  // @79_42a820
  ecx = esi;  // @80_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @81_42a820
  ecx = edx = 0;  // @82_42a820
  ecx = (u32)(EBP - 144);  // @83_42a820
  reg.state = (s32)((u32)(4294967295));  // @84_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @85_42a820
  ecx = edx = 0;  // @86_42a820
  PS[0] = esi;  // @87_42a820
  ecx = edi;  // @88_42a820
  eax = ext_42da80_stdcall1((u32)(PS[0]));  // @89_42a820
  ecx = edx = 0;  // @90_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @91_42a820
  L42a99a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_42a820
  edx = (u32)(EBP - 276);  // @94_42a820
  PS[0] = edx;  // @95_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @97_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783676), (u32)(PS[0]));  // @98_42a820
  ecx = edx = 0;  // @99_42a820
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42a9f1;  // @100_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_42a820
  edx = (u32)(EBP - 276);  // @102_42a820
  PS[0] = edx;  // @103_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @105_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783684), (u32)(PS[0]));  // @106_42a820
  ecx = edx = 0;  // @107_42a820
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42a9f1;  // @108_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_42a820
  edx = (u32)(EBP - 276);  // @110_42a820
  PS[0] = edx;  // @111_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @113_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783696), (u32)(PS[0]));  // @114_42a820
  ecx = edx = 0;  // @115_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42aa3b;  // @116_42a820
  L42a9f1:;
  ecx = (u32)(EBP - 144);  // @118_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @119_42a820
  ecx = edx = 0;  // @120_42a820
  eax = (u32)(EBP - 144);  // @121_42a820
  reg.state = (s32)((u32)(2));  // @122_42a820
  esi = (u32)(edi + 7025);  // @123_42a820
  PS[0] = eax;  // @124_42a820
  ecx = esi;  // @125_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @126_42a820
  ecx = edx = 0;  // @127_42a820
  ecx = (u32)(EBP - 144);  // @128_42a820
  reg.state = (s32)((u32)(4294967295));  // @129_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @130_42a820
  ecx = edx = 0;  // @131_42a820
  PS[0] = esi;  // @132_42a820
  ecx = edi;  // @133_42a820
  eax = ext_42da80_stdcall1((u32)(PS[0]));  // @134_42a820
  ecx = edx = 0;  // @135_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @136_42a820
  L42aa3b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @138_42a820
  edx = (u32)(EBP - 276);  // @139_42a820
  PS[0] = edx;  // @140_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @142_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783708), (u32)(PS[0]));  // @143_42a820
  ecx = edx = 0;  // @144_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42aaa2;  // @145_42a820
  ecx = (u32)(EBP - 272);  // @146_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @147_42a820
  ecx = edx = 0;  // @148_42a820
  eax = (u32)(EBP - 272);  // @149_42a820
  reg.state = (s32)((u32)(3));  // @150_42a820
  esi = (u32)(edi + 7025);  // @151_42a820
  PS[0] = eax;  // @152_42a820
  ecx = esi;  // @153_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @154_42a820
  ecx = edx = 0;  // @155_42a820
  ecx = (u32)(EBP - 272);  // @156_42a820
  reg.state = (s32)((u32)(4294967295));  // @157_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @158_42a820
  ecx = edx = 0;  // @159_42a820
  PS[0] = esi;  // @160_42a820
  ecx = edi;  // @161_42a820
  eax = ext_42da80_stdcall1((u32)(PS[0]));  // @162_42a820
  ecx = edx = 0;  // @163_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @164_42a820
  L42aaa2:;
  SEH_LEAVE();  // @166_42a820
  ext_633654(G(u32, 0x6f5630));  // @167_42a820
  return eax;  // @168_42a820
}
PCREG(42a820, lifted_42a820);

