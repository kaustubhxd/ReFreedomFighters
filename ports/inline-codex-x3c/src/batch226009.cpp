// batch226009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_496530_fastcall2(u32, u32) __asm__("ext_496530");
extern "C" u32 FASTCALL ext_497470_fastcall3(u32, u32, u32) __asm__("ext_497470");
extern "C" u32 STDCALL ext_496620_stdcall1(u32) __asm__("ext_496620");
extern "C" u32 THISCALL ext_496160_thiscall2(u32, u32) __asm__("ext_496160");
extern "C" u32 THISCALL ext_496690_thiscall2(u32, u32) __asm__("ext_496690");
extern "C" u32 THISCALL ext_496700_thiscall2(u32, u32) __asm__("ext_496700");
extern "C" u32 THISCALL ext_497fe0_thiscall2(u32, u32) __asm__("ext_497fe0");
extern "C" u32 THISCALL ext_498270_thiscall2(u32, u32) __asm__("ext_498270");
extern "C" u32 THISCALL ext_498430_thiscall2(u32, u32) __asm__("ext_498430");
extern "C" u32 THISCALL ext_498650_thiscall2(u32, u32) __asm__("ext_498650");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cdb90_thiscall1(u32) __asm__("ext_4cdb90");
extern "C" u32 THISCALL ext_4dbbc0_thiscall1(u32) __asm__("ext_4dbbc0");
extern "C" u32 THISCALL ext_4dbbd0_thiscall1(u32) __asm__("ext_4dbbd0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_497990(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6681bb);  // @h_497990
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_497990
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_497990
  ecx = edi;  // @2_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(14));  // @4_497990
  ecx = edx = 0;  // @5_497990
  esi = 0;  // @6_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; }) == esi) goto L4979ea;  // @7_497990
  L4979d3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @9_497990
  ecx = edi;  // @10_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_497990
  eax = (u32)(eax + esi*8);  // @12_497990
  eax = (eax + (u32)(4));  // @13_497990
  PS[0] = eax;  // @14_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(PS[0]));  // @15_497990
  ecx = edx = 0;  // @16_497990
  esi = (esi + 1);  // @17_497990
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; })) goto L4979d3;  // @18_497990
  L4979ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_497990
  ecx = edi;  // @21_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(13));  // @22_497990
  ecx = edx = 0;  // @23_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @24_497990
  ecx = (u32)(EBP - 220);  // @25_497990
  PS[1] = ecx;  // @26_497990
  ecx = edi;  // @27_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @28_497990
  ecx = edx = 0;  // @29_497990
  PS[0] = edi;  // @30_497990
  ecx = ebx;  // @31_497990
  eax = ext_496620_stdcall1((u32)(PS[0]));  // @32_497990
  ecx = edx = 0;  // @33_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_497990
  ecx = edi;  // @35_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(9));  // @36_497990
  ecx = edx = 0;  // @37_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @38_497990
  ecx = (u32)(EBP - 212);  // @39_497990
  PS[1] = ecx;  // @40_497990
  ecx = edi;  // @41_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @42_497990
  ecx = edx = 0;  // @43_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_497990
  ecx = (u32)(EBP - 216);  // @45_497990
  PS[1] = ecx;  // @46_497990
  ecx = edi;  // @47_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @48_497990
  ecx = edx = 0;  // @49_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }) != (u32)(13)) goto L497f9a;  // @50_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; }) != (u32)(8192)) goto L497f9a;  // @51_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_497990
  ecx = edi;  // @53_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7));  // @54_497990
  ecx = edx = 0;  // @55_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_497990
  eax = (u32)(ebx + 32);  // @57_497990
  PS[1] = eax;  // @58_497990
  ecx = edi;  // @59_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @60_497990
  ecx = edx = 0;  // @61_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_497990
  eax = (u32)(ebx + 40);  // @63_497990
  PS[1] = eax;  // @64_497990
  ecx = edi;  // @65_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @66_497990
  ecx = edx = 0;  // @67_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @68_497990
  eax = (u32)(ebx + 36);  // @69_497990
  PS[1] = eax;  // @70_497990
  ecx = edi;  // @71_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @72_497990
  ecx = edx = 0;  // @73_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @74_497990
  eax = (u32)(ebx + 80);  // @75_497990
  PS[1] = eax;  // @76_497990
  ecx = edi;  // @77_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(PS[1]), (u32)(1));  // @78_497990
  ecx = edx = 0;  // @79_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @80_497990
  eax = (u32)(ebx + 97);  // @81_497990
  PS[1] = eax;  // @82_497990
  ecx = edi;  // @83_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @84_497990
  ecx = edx = 0;  // @85_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @86_497990
  ecx = (u32)(EBP - 260);  // @87_497990
  PS[1] = ecx;  // @88_497990
  ecx = edi;  // @89_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @90_497990
  ecx = edx = 0;  // @91_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @92_497990
  ecx = edi;  // @93_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(8));  // @94_497990
  ecx = edx = 0;  // @95_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @96_497990
  ecx = (u32)(EBP - 264);  // @97_497990
  PS[1] = ecx;  // @98_497990
  ecx = edi;  // @99_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @100_497990
  ecx = edx = 0;  // @101_497990
  ecx = (u32)(EBP - 188);  // @102_497990
  eax = ext_4ccba0_thiscall1(ecx);  // @103_497990
  ecx = edx = 0;  // @104_497990
  eax = (u32)(EBP - 188);  // @105_497990
  reg.state = (s32)((u32)(0));  // @106_497990
  PS[0] = eax;  // @107_497990
  ecx = ebx;  // @108_497990
  eax = ext_497470_fastcall3(ecx, edx, (u32)(PS[0]));  // @109_497990
  ecx = edx = 0;  // @110_497990
  eax = (u32)(EBP - 204);  // @111_497990
  PS[0] = eax;  // @112_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @113_497990
  ecx = (u32)(EBP - 188);  // @114_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @115_497990
  ecx = edx = 0;  // @116_497990
  eax = (u32)(EBP - 204);  // @117_497990
  PS[0] = eax;  // @118_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @119_497990
  ecx = (u32)(EBP - 188);  // @120_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @121_497990
  ecx = edx = 0;  // @122_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) == (u32)(0)) goto L497b62;  // @123_497990
  L497b20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @125_497990
  if ((ecx & ecx) == 0) goto L497b2f;  // @126_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @127_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @128_497990
  goto L497b34;  // @129_497990
  L497b2f:;
  eax = (u32)(2097154);  // @131_497990
  L497b34:;
  if ((eax & (u32)(1048576)) == 0) goto L497b43;  // @133_497990
  PS[0] = ecx;  // @134_497990
  ecx = ebx;  // @135_497990
  eax = ext_496700_thiscall2(ecx, (u32)(PS[0]));  // @136_497990
  ecx = edx = 0;  // @137_497990
  L497b43:;
  eax = (u32)(EBP - 204);  // @139_497990
  PS[0] = eax;  // @140_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @141_497990
  ecx = (u32)(EBP - 188);  // @142_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @143_497990
  ecx = edx = 0;  // @144_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) != (u32)(0)) goto L497b20;  // @145_497990
  L497b62:;
  PS[0] = edi;  // @147_497990
  ecx = ebx;  // @148_497990
  eax = ext_496690_thiscall2(ecx, (u32)(PS[0]));  // @149_497990
  ecx = edx = 0;  // @150_497990
  ecx = ebx;  // @151_497990
  eax = ext_496530_fastcall2(ecx, edx);  // @152_497990
  ecx = edx = 0;  // @153_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @154_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(5177423));  // @156_497990
  ecx = edx = 0;  // @157_497990
  PS[0] = edi;  // @158_497990
  ecx = ebx;  // @159_497990
  esi = eax;  // @160_497990
  eax = ext_498270_thiscall2(ecx, (u32)(PS[0]));  // @161_497990
  ecx = edx = 0;  // @162_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @163_497990
  PS[0] = esi;  // @164_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(PS[0]));  // @166_497990
  ecx = edx = 0;  // @167_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @168_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @169_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @170_497990
  ecx = edx = 0;  // @171_497990
  PS[0] = edi;  // @172_497990
  ecx = ebx;  // @173_497990
  eax = ext_498430_thiscall2(ecx, (u32)(PS[0]));  // @174_497990
  ecx = edx = 0;  // @175_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @176_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @178_497990
  ecx = edx = 0;  // @179_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @180_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @181_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @182_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @183_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @184_497990
  ecx = edx = 0;  // @185_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @186_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @187_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @188_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 116)))(ecx);  // @189_497990
  ecx = edx = 0;  // @190_497990
  PS[0] = edi;  // @191_497990
  ecx = ebx;  // @192_497990
  eax = ext_498650_thiscall2(ecx, (u32)(PS[0]));  // @193_497990
  ecx = edx = 0;  // @194_497990
  PS[0] = edi;  // @195_497990
  ecx = ebx;  // @196_497990
  eax = ext_496160_thiscall2(ecx, (u32)(PS[0]));  // @197_497990
  ecx = edx = 0;  // @198_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @199_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @200_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @201_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 120)))(ecx);  // @202_497990
  ecx = edx = 0;  // @203_497990
  PS[0] = edi;  // @204_497990
  ecx = ebx;  // @205_497990
  eax = ext_497fe0_thiscall2(ecx, (u32)(PS[0]));  // @206_497990
  ecx = edx = 0;  // @207_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @208_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @209_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @210_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 116)))(ecx);  // @211_497990
  ecx = edx = 0;  // @212_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @213_497990
  ecx = (u32)(EBP - 188);  // @214_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @215_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @216_497990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @217_497990
  eax = ext_4cdb90_thiscall1(ecx);  // @218_497990
  ecx = edx = 0;  // @219_497990
  eax = (u32)(EBP - 188);  // @220_497990
  ecx = ebx;  // @221_497990
  PS[0] = eax;  // @222_497990
  eax = ext_497470_fastcall3(ecx, edx, (u32)(PS[0]));  // @223_497990
  ecx = edx = 0;  // @224_497990
  edi = 0;  // @225_497990
  L497c40:;
  eax = (u32)(EBP - 244);  // @227_497990
  PS[0] = eax;  // @228_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @229_497990
  ecx = (u32)(EBP - 188);  // @230_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @231_497990
  ecx = edx = 0;  // @232_497990
  eax = (u32)(EBP - 244);  // @233_497990
  PS[0] = eax;  // @234_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @235_497990
  ecx = (u32)(EBP - 188);  // @236_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @237_497990
  ecx = edx = 0;  // @238_497990
  esi = eax;  // @239_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 244), sizeof v); (u32)v; }) == (u32)(0)) goto L497d0c;  // @240_497990
  L497c80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @242_497990
  if ((ecx & ecx) == 0) goto L497c8f;  // @243_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @244_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @245_497990
  goto L497c94;  // @246_497990
  L497c8f:;
  eax = (u32)(2097154);  // @248_497990
  L497c94:;
  if ((eax & (u32)(1048576)) == 0) goto L497cd5;  // @250_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @251_497990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @252_497990
  if ((eax & eax) == 0) goto L497ce7;  // @253_497990
  L497ca8:;
  ecx = eax;  // @255_497990
  if ((edi & edi) == 0) goto L497cb5;  // @256_497990
  eax = ext_4dbbd0_thiscall1(ecx);  // @257_497990
  ecx = edx = 0;  // @258_497990
  goto L497cba;  // @259_497990
  L497cb5:;
  eax = ext_4dbbc0_thiscall1(ecx);  // @261_497990
  ecx = edx = 0;  // @262_497990
  L497cba:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @264_497990
  edx = (u32)(EBP - 208);  // @265_497990
  PS[0] = edx;  // @266_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @267_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @268_497990
  ecx = edx = 0;  // @269_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @270_497990
  if ((eax & eax) != 0) goto L497ca8;  // @271_497990
  goto L497ce7;  // @272_497990
  L497cd5:;
  ecx = esi;  // @274_497990
  if ((edi & edi) == 0) goto L497ce2;  // @275_497990
  eax = ext_4dbbd0_thiscall1(ecx);  // @276_497990
  ecx = edx = 0;  // @277_497990
  goto L497ce7;  // @278_497990
  L497ce2:;
  eax = ext_4dbbc0_thiscall1(ecx);  // @280_497990
  ecx = edx = 0;  // @281_497990
  L497ce7:;
  eax = (u32)(EBP - 244);  // @283_497990
  PS[0] = eax;  // @284_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @285_497990
  ecx = (u32)(EBP - 188);  // @286_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @287_497990
  ecx = edx = 0;  // @288_497990
  esi = eax;  // @289_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 244), sizeof v); (u32)v; }) != (u32)(0)) goto L497c80;  // @290_497990
  L497d0c:;
  eax = (u32)(EBP - 256);  // @292_497990
  PS[0] = eax;  // @293_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @294_497990
  ecx = (u32)(EBP - 188);  // @295_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @296_497990
  ecx = edx = 0;  // @297_497990
  eax = (u32)(EBP - 256);  // @298_497990
  PS[0] = eax;  // @299_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @300_497990
  ecx = (u32)(EBP - 188);  // @301_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @302_497990
  ecx = edx = 0;  // @303_497990
  ebx = eax;  // @304_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; }) == (u32)(0)) goto L497f3c;  // @305_497990
  L497d47:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @307_497990
  if ((ecx & ecx) == 0) goto L497d56;  // @308_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @309_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @310_497990
  goto L497d5b;  // @311_497990
  L497d56:;
  eax = (u32)(2097154);  // @313_497990
  L497d5b:;
  if ((eax & (u32)(1048576)) == 0) goto L497e66;  // @315_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @316_497990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @317_497990
  if ((eax & eax) == 0) goto L497f17;  // @318_497990
  L497d80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @320_497990
  if ((eax & eax) == 0) goto L497e44;  // @321_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @322_497990
  if ((ecx & ecx) == 0) goto L497e44;  // @323_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @324_497990
  if ((ecx & ecx) == 0) goto L497e44;  // @325_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @326_497990
  edx = (u32)(EBP - 232);  // @327_497990
  PS[0] = edx;  // @328_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @329_497990
  ecx = edx = 0;  // @330_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @331_497990
  edx = (u32)(EBP - 232);  // @332_497990
  PS[0] = edx;  // @333_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @334_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @335_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @336_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @337_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @338_497990
  ecx = edx = 0;  // @339_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; }) == (u32)(0)) goto L497e44;  // @340_497990
  L497dd1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @342_497990
  PS[0] = eax;  // @343_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @344_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(PS[0]));  // @345_497990
  ecx = edx = 0;  // @346_497990
  esi = eax;  // @347_497990
  if ((esi & esi) != 0) goto L497e03;  // @348_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @349_497990
  edx = (u32)(EBP - 232);  // @350_497990
  PS[0] = edx;  // @351_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @352_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @353_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @354_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @355_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(PS[0]));  // @356_497990
  ecx = edx = 0;  // @357_497990
  goto L497e20;  // @358_497990
  L497e03:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(128)) == 0) goto L497e20;  // @360_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @361_497990
  ecx = esi;  // @362_497990
  if ((edi & edi) == 0) goto L497e1d;  // @363_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @364_497990
  ecx = edx = 0;  // @365_497990
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967167))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @366_497990
  goto L497e20;  // @367_497990
  L497e1d:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @369_497990
  ecx = edx = 0;  // @370_497990
  L497e20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @372_497990
  edx = (u32)(EBP - 232);  // @373_497990
  PS[0] = edx;  // @374_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @375_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @376_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @377_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @378_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @379_497990
  ecx = edx = 0;  // @380_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; }) != (u32)(0)) goto L497dd1;  // @381_497990
  L497e44:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @383_497990
  edx = (u32)(EBP - 192);  // @384_497990
  PS[0] = edx;  // @385_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @386_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @387_497990
  ecx = edx = 0;  // @388_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @389_497990
  if ((eax & eax) != 0) goto L497d80;  // @390_497990
  goto L497f17;  // @391_497990
  L497e66:;
  if ((ecx & ecx) == 0) goto L497f17;  // @393_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @394_497990
  if ((ecx & ecx) == 0) goto L497f17;  // @395_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @396_497990
  if ((ecx & ecx) == 0) goto L497f17;  // @397_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @398_497990
  edx = (u32)(EBP - 204);  // @399_497990
  PS[0] = edx;  // @400_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @401_497990
  ecx = edx = 0;  // @402_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @403_497990
  edx = (u32)(EBP - 204);  // @404_497990
  PS[0] = edx;  // @405_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @406_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @407_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @408_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @409_497990
  ecx = edx = 0;  // @410_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) == (u32)(0)) goto L497f17;  // @411_497990
  L497eb0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @413_497990
  PS[0] = eax;  // @414_497990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @415_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(PS[0]));  // @416_497990
  ecx = edx = 0;  // @417_497990
  esi = eax;  // @418_497990
  if ((esi & esi) != 0) goto L497edc;  // @419_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @420_497990
  edx = (u32)(EBP - 204);  // @421_497990
  PS[0] = edx;  // @422_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @423_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @424_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @425_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(PS[0]));  // @426_497990
  ecx = edx = 0;  // @427_497990
  goto L497ef9;  // @428_497990
  L497edc:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(128)) == 0) goto L497ef9;  // @430_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @431_497990
  ecx = esi;  // @432_497990
  if ((edi & edi) == 0) goto L497ef6;  // @433_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @434_497990
  ecx = edx = 0;  // @435_497990
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967167))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @436_497990
  goto L497ef9;  // @437_497990
  L497ef6:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @439_497990
  ecx = edx = 0;  // @440_497990
  L497ef9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @442_497990
  edx = (u32)(EBP - 204);  // @443_497990
  PS[0] = edx;  // @444_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @445_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @446_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @447_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @448_497990
  ecx = edx = 0;  // @449_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) != (u32)(0)) goto L497eb0;  // @450_497990
  L497f17:;
  eax = (u32)(EBP - 256);  // @452_497990
  PS[0] = eax;  // @453_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @454_497990
  ecx = (u32)(EBP - 188);  // @455_497990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @456_497990
  ecx = edx = 0;  // @457_497990
  ebx = eax;  // @458_497990
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; }) != (u32)(0)) goto L497d47;  // @459_497990
  L497f3c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @461_497990
  edi = (edi + 1);  // @462_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @463_497990
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 3008), &v, sizeof v); }  // @464_497990
  if ((s32)edi <= (s32)(u32)(1)) goto L497c40;  // @465_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @466_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @467_497990
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 3008), &v, sizeof v); }  // @468_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @469_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @470_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @471_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @472_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @473_497990
  ecx = edx = 0;  // @474_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @475_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @476_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @477_497990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 120)))(ecx);  // @478_497990
  ecx = edx = 0;  // @479_497990
  ecx = (u32)(EBP - 188);  // @480_497990
  eax = ext_4ccf60_thiscall1(ecx);  // @481_497990
  ecx = edx = 0;  // @482_497990
  goto L497fbd;  // @483_497990
  L497f9a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @485_497990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @486_497990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6873964), (u32)(1125));  // @487_497990
  ecx = edx = 0;  // @488_497990
  PS[1] = eax;  // @489_497990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @490_497990
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(PS[1]), (u32)(6874072));  // @491_497990
  ecx = edx = 0;  // @492_497990
  L497fbd:;
  SEH_LEAVE();  // @494_497990
  ext_633654(G(u32, 0x6f5630));  // @495_497990
  return eax;  // @496_497990
}
PCREG(497990, lifted_497990);

