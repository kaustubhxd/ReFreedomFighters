// batch228001.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d8180_thiscall3(u32, u32, u32) __asm__("ext_4d8180");
extern "C" u32 THISCALL ext_561020_thiscall1(u32) __asm__("ext_561020");
extern "C" u32 THISCALL ext_561160_thiscall1(u32) __asm__("ext_561160");
extern "C" u32 THISCALL ext_564460_thiscall1(u32) __asm__("ext_564460");
extern "C" u32 THISCALL ext_565840_thiscall1(u32) __asm__("ext_565840");
extern "C" u32 THISCALL ext_565870_thiscall1(u32) __asm__("ext_565870");
extern "C" u32 THISCALL ext_565b90_thiscall1(u32) __asm__("ext_565b90");
extern "C" u32 THISCALL ext_566bc0_thiscall1(u32) __asm__("ext_566bc0");
extern "C" u32 THISCALL ext_566c90_thiscall1(u32) __asm__("ext_566c90");
extern "C" u32 THISCALL ext_567720_thiscall1(u32) __asm__("ext_567720");
extern "C" u32 THISCALL ext_569380_thiscall1(u32) __asm__("ext_569380");
extern "C" u32 THISCALL ext_5696b0_thiscall1(u32) __asm__("ext_5696b0");
extern "C" u32 THISCALL ext_569730_thiscall1(u32) __asm__("ext_569730");
extern "C" u32 THISCALL ext_56ad80_thiscall1(u32) __asm__("ext_56ad80");
extern "C" u32 THISCALL ext_56b2d0_thiscall1(u32) __asm__("ext_56b2d0");
extern "C" u32 THISCALL ext_56c810_thiscall1(u32) __asm__("ext_56c810");
extern "C" u32 THISCALL ext_56db70_thiscall1(u32) __asm__("ext_56db70");
extern "C" u32 THISCALL ext_56e990_thiscall1(u32) __asm__("ext_56e990");
extern "C" u32 THISCALL ext_56fea0_thiscall1(u32) __asm__("ext_56fea0");
extern "C" u32 THISCALL ext_571960_thiscall1(u32) __asm__("ext_571960");
extern "C" u32 THISCALL ext_572360_thiscall1(u32) __asm__("ext_572360");
extern "C" u32 THISCALL ext_572e40_thiscall1(u32) __asm__("ext_572e40");
extern "C" u32 THISCALL ext_573590_thiscall1(u32) __asm__("ext_573590");
extern "C" u32 THISCALL ext_573650_thiscall4(u32, u32, u32, u32) __asm__("ext_573650");
extern "C" u32 THISCALL ext_574c60_thiscall1(u32) __asm__("ext_574c60");
extern "C" u32 THISCALL ext_575d50_thiscall1(u32) __asm__("ext_575d50");
extern "C" u32 THISCALL ext_5773f0_thiscall1(u32) __asm__("ext_5773f0");
extern "C" u32 THISCALL ext_577830_thiscall1(u32) __asm__("ext_577830");
extern "C" u32 THISCALL ext_578560_thiscall1(u32) __asm__("ext_578560");
extern "C" u32 THISCALL ext_578710_thiscall1(u32) __asm__("ext_578710");
extern "C" u32 THISCALL ext_57a100_thiscall1(u32) __asm__("ext_57a100");
extern "C" u32 THISCALL ext_57a3b0_thiscall1(u32) __asm__("ext_57a3b0");
extern "C" u32 THISCALL ext_57a440_thiscall1(u32) __asm__("ext_57a440");
extern "C" u32 THISCALL ext_57abc0_thiscall1(u32) __asm__("ext_57abc0");
extern "C" u32 THISCALL ext_57aea0_thiscall1(u32) __asm__("ext_57aea0");
extern "C" u32 THISCALL ext_57baa0_thiscall1(u32) __asm__("ext_57baa0");
extern "C" u32 THISCALL ext_57bd90_thiscall1(u32) __asm__("ext_57bd90");
extern "C" u32 THISCALL ext_57c100_thiscall1(u32) __asm__("ext_57c100");
extern "C" u32 THISCALL ext_57c460_thiscall1(u32) __asm__("ext_57c460");
extern "C" u32 THISCALL ext_57c7c0_thiscall1(u32) __asm__("ext_57c7c0");
extern "C" u32 THISCALL ext_57f1b0_thiscall1(u32) __asm__("ext_57f1b0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_48aba0(u32 ecx_in) {
  SEH_ENTER(0x6678fa);  // @h_48aba0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @1_48aba0
  ecx = edx = 0;  // @2_48aba0
  edi = eax;  // @3_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_48aba0
  reg.state = (s32)((u32)(0));  // @5_48aba0
  if ((edi & edi) == 0) goto L48ac03;  // @6_48aba0
  ecx = edi;  // @7_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871588), (u32)(6871552));  // @8_48aba0
  ecx = edx = 0;  // @9_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @10_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @11_48aba0
  goto L48ac05;  // @12_48aba0
  L48ac03:;
  edi = 0;  // @14_48aba0
  L48ac05:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23885), &v, sizeof v); }  // @16_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_48aba0
  PV[0] = (u32)(edi);  // @18_48aba0
  reg.state = (s32)((u32)(4294967295));  // @19_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[0]);  // @21_48aba0
  ecx = edx = 0;  // @22_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @23_48aba0
  ecx = edx = 0;  // @24_48aba0
  edi = eax;  // @25_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @26_48aba0
  reg.state = (s32)((u32)(1));  // @27_48aba0
  if ((edi & edi) == 0) goto L48ac5d;  // @28_48aba0
  ecx = edi;  // @29_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871612), (u32)(6871596));  // @30_48aba0
  ecx = edx = 0;  // @31_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @32_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @33_48aba0
  goto L48ac5f;  // @34_48aba0
  L48ac5d:;
  edi = 0;  // @36_48aba0
  L48ac5f:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23889), &v, sizeof v); }  // @38_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_48aba0
  PV[1] = (u32)(edi);  // @40_48aba0
  reg.state = (s32)((u32)(4294967295));  // @41_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[1]);  // @43_48aba0
  ecx = edx = 0;  // @44_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @45_48aba0
  ecx = edx = 0;  // @46_48aba0
  edi = eax;  // @47_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @48_48aba0
  reg.state = (s32)((u32)(2));  // @49_48aba0
  if ((edi & edi) == 0) goto L48acb7;  // @50_48aba0
  ecx = edi;  // @51_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871660), (u32)(6871624));  // @52_48aba0
  ecx = edx = 0;  // @53_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @54_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @55_48aba0
  goto L48acb9;  // @56_48aba0
  L48acb7:;
  edi = 0;  // @58_48aba0
  L48acb9:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23893), &v, sizeof v); }  // @60_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_48aba0
  PV[2] = (u32)(edi);  // @62_48aba0
  reg.state = (s32)((u32)(4294967295));  // @63_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[2]);  // @65_48aba0
  ecx = edx = 0;  // @66_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @67_48aba0
  ecx = edx = 0;  // @68_48aba0
  edi = eax;  // @69_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @70_48aba0
  reg.state = (s32)((u32)(3));  // @71_48aba0
  if ((edi & edi) == 0) goto L48ad11;  // @72_48aba0
  ecx = edi;  // @73_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6842260), (u32)(6871676));  // @74_48aba0
  ecx = edx = 0;  // @75_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @76_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @77_48aba0
  goto L48ad13;  // @78_48aba0
  L48ad11:;
  edi = 0;  // @80_48aba0
  L48ad13:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23881), &v, sizeof v); }  // @82_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @83_48aba0
  PV[3] = (u32)(edi);  // @84_48aba0
  reg.state = (s32)((u32)(4294967295));  // @85_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[3]);  // @87_48aba0
  ecx = edx = 0;  // @88_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @89_48aba0
  ecx = edx = 0;  // @90_48aba0
  edi = eax;  // @91_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @92_48aba0
  reg.state = (s32)((u32)(4));  // @93_48aba0
  if ((edi & edi) == 0) goto L48ad68;  // @94_48aba0
  ecx = edi;  // @95_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871700), (u32)(0));  // @96_48aba0
  ecx = edx = 0;  // @97_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @98_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @99_48aba0
  goto L48ad6a;  // @100_48aba0
  L48ad68:;
  edi = 0;  // @102_48aba0
  L48ad6a:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23897), &v, sizeof v); }  // @104_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @105_48aba0
  PV[4] = (u32)(edi);  // @106_48aba0
  reg.state = (s32)((u32)(4294967295));  // @107_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[4]);  // @109_48aba0
  ecx = edx = 0;  // @110_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @111_48aba0
  ecx = edx = 0;  // @112_48aba0
  edi = eax;  // @113_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @114_48aba0
  reg.state = (s32)((u32)(5));  // @115_48aba0
  if ((edi & edi) == 0) goto L48adc2;  // @116_48aba0
  ecx = edi;  // @117_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871760), (u32)(6871716));  // @118_48aba0
  ecx = edx = 0;  // @119_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @120_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @121_48aba0
  goto L48adc4;  // @122_48aba0
  L48adc2:;
  edi = 0;  // @124_48aba0
  L48adc4:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23901), &v, sizeof v); }  // @126_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @127_48aba0
  PV[5] = (u32)(edi);  // @128_48aba0
  reg.state = (s32)((u32)(4294967295));  // @129_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[5]);  // @131_48aba0
  ecx = edx = 0;  // @132_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @133_48aba0
  ecx = edx = 0;  // @134_48aba0
  edi = eax;  // @135_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @136_48aba0
  reg.state = (s32)((u32)(6));  // @137_48aba0
  if ((edi & edi) == 0) goto L48ae1c;  // @138_48aba0
  ecx = edi;  // @139_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871812), (u32)(6871768));  // @140_48aba0
  ecx = edx = 0;  // @141_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @142_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @143_48aba0
  goto L48ae1e;  // @144_48aba0
  L48ae1c:;
  edi = 0;  // @146_48aba0
  L48ae1e:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23905), &v, sizeof v); }  // @148_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_48aba0
  PV[6] = (u32)(edi);  // @150_48aba0
  reg.state = (s32)((u32)(4294967295));  // @151_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[6]);  // @153_48aba0
  ecx = edx = 0;  // @154_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @155_48aba0
  ecx = edx = 0;  // @156_48aba0
  edi = eax;  // @157_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @158_48aba0
  reg.state = (s32)((u32)(7));  // @159_48aba0
  if ((edi & edi) == 0) goto L48ae73;  // @160_48aba0
  ecx = edi;  // @161_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871824), (u32)(0));  // @162_48aba0
  ecx = edx = 0;  // @163_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @164_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @165_48aba0
  goto L48ae75;  // @166_48aba0
  L48ae73:;
  edi = 0;  // @168_48aba0
  L48ae75:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23909), &v, sizeof v); }  // @170_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @171_48aba0
  PV[7] = (u32)(edi);  // @172_48aba0
  reg.state = (s32)((u32)(4294967295));  // @173_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @174_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[7]);  // @175_48aba0
  ecx = edx = 0;  // @176_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @177_48aba0
  ecx = edx = 0;  // @178_48aba0
  edi = eax;  // @179_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @180_48aba0
  reg.state = (s32)((u32)(8));  // @181_48aba0
  if ((edi & edi) == 0) goto L48aeca;  // @182_48aba0
  ecx = edi;  // @183_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871828), (u32)(0));  // @184_48aba0
  ecx = edx = 0;  // @185_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @186_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @187_48aba0
  goto L48aecc;  // @188_48aba0
  L48aeca:;
  edi = 0;  // @190_48aba0
  L48aecc:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23913), &v, sizeof v); }  // @192_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @193_48aba0
  PV[8] = (u32)(edi);  // @194_48aba0
  reg.state = (s32)((u32)(4294967295));  // @195_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @196_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[8]);  // @197_48aba0
  ecx = edx = 0;  // @198_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @199_48aba0
  ecx = edx = 0;  // @200_48aba0
  edi = eax;  // @201_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @202_48aba0
  reg.state = (s32)((u32)(9));  // @203_48aba0
  if ((edi & edi) == 0) goto L48af24;  // @204_48aba0
  ecx = edi;  // @205_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871868), (u32)(6871836));  // @206_48aba0
  ecx = edx = 0;  // @207_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @208_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @209_48aba0
  goto L48af26;  // @210_48aba0
  L48af24:;
  edi = 0;  // @212_48aba0
  L48af26:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23917), &v, sizeof v); }  // @214_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @215_48aba0
  PV[9] = (u32)(edi);  // @216_48aba0
  reg.state = (s32)((u32)(4294967295));  // @217_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @218_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[9]);  // @219_48aba0
  ecx = edx = 0;  // @220_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @221_48aba0
  ecx = edx = 0;  // @222_48aba0
  edi = eax;  // @223_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @224_48aba0
  reg.state = (s32)((u32)(10));  // @225_48aba0
  if ((edi & edi) == 0) goto L48af7b;  // @226_48aba0
  ecx = edi;  // @227_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871872), (u32)(0));  // @228_48aba0
  ecx = edx = 0;  // @229_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @230_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @231_48aba0
  goto L48af7d;  // @232_48aba0
  L48af7b:;
  edi = 0;  // @234_48aba0
  L48af7d:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23921), &v, sizeof v); }  // @236_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @237_48aba0
  PV[10] = (u32)(edi);  // @238_48aba0
  reg.state = (s32)((u32)(4294967295));  // @239_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @240_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[10]);  // @241_48aba0
  ecx = edx = 0;  // @242_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @243_48aba0
  ecx = edx = 0;  // @244_48aba0
  edi = eax;  // @245_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @246_48aba0
  reg.state = (s32)((u32)(11));  // @247_48aba0
  if ((edi & edi) == 0) goto L48afd5;  // @248_48aba0
  ecx = edi;  // @249_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871912), (u32)(6871884));  // @250_48aba0
  ecx = edx = 0;  // @251_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @252_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @253_48aba0
  goto L48afd7;  // @254_48aba0
  L48afd5:;
  edi = 0;  // @256_48aba0
  L48afd7:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23925), &v, sizeof v); }  // @258_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @259_48aba0
  PV[11] = (u32)(edi);  // @260_48aba0
  reg.state = (s32)((u32)(4294967295));  // @261_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @262_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[11]);  // @263_48aba0
  ecx = edx = 0;  // @264_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @265_48aba0
  ecx = edx = 0;  // @266_48aba0
  edi = eax;  // @267_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @268_48aba0
  reg.state = (s32)((u32)(12));  // @269_48aba0
  if ((edi & edi) == 0) goto L48b02c;  // @270_48aba0
  ecx = edi;  // @271_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871920), (u32)(0));  // @272_48aba0
  ecx = edx = 0;  // @273_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @274_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @275_48aba0
  goto L48b02e;  // @276_48aba0
  L48b02c:;
  edi = 0;  // @278_48aba0
  L48b02e:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23929), &v, sizeof v); }  // @280_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @281_48aba0
  PV[12] = (u32)(edi);  // @282_48aba0
  reg.state = (s32)((u32)(4294967295));  // @283_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @284_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[12]);  // @285_48aba0
  ecx = edx = 0;  // @286_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @287_48aba0
  ecx = edx = 0;  // @288_48aba0
  edi = eax;  // @289_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @290_48aba0
  reg.state = (s32)((u32)(13));  // @291_48aba0
  if ((edi & edi) == 0) goto L48b086;  // @292_48aba0
  ecx = edi;  // @293_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871956), (u32)(6871928));  // @294_48aba0
  ecx = edx = 0;  // @295_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @296_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @297_48aba0
  goto L48b088;  // @298_48aba0
  L48b086:;
  edi = 0;  // @300_48aba0
  L48b088:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23933), &v, sizeof v); }  // @302_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @303_48aba0
  PV[13] = (u32)(edi);  // @304_48aba0
  reg.state = (s32)((u32)(4294967295));  // @305_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @306_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[13]);  // @307_48aba0
  ecx = edx = 0;  // @308_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @309_48aba0
  ecx = edx = 0;  // @310_48aba0
  edi = eax;  // @311_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @312_48aba0
  reg.state = (s32)((u32)(14));  // @313_48aba0
  if ((edi & edi) == 0) goto L48b0e0;  // @314_48aba0
  ecx = edi;  // @315_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6871976), (u32)(6871964));  // @316_48aba0
  ecx = edx = 0;  // @317_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @318_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @319_48aba0
  goto L48b0e2;  // @320_48aba0
  L48b0e0:;
  edi = 0;  // @322_48aba0
  L48b0e2:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23945), &v, sizeof v); }  // @324_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @325_48aba0
  PV[14] = (u32)(edi);  // @326_48aba0
  reg.state = (s32)((u32)(4294967295));  // @327_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @328_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[14]);  // @329_48aba0
  ecx = edx = 0;  // @330_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @331_48aba0
  ecx = edx = 0;  // @332_48aba0
  edi = eax;  // @333_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @334_48aba0
  reg.state = (s32)((u32)(15));  // @335_48aba0
  if ((edi & edi) == 0) goto L48b13a;  // @336_48aba0
  ecx = edi;  // @337_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6872000), (u32)(6871988));  // @338_48aba0
  ecx = edx = 0;  // @339_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @340_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @341_48aba0
  goto L48b13c;  // @342_48aba0
  L48b13a:;
  edi = 0;  // @344_48aba0
  L48b13c:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23941), &v, sizeof v); }  // @346_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @347_48aba0
  PV[15] = (u32)(edi);  // @348_48aba0
  reg.state = (s32)((u32)(4294967295));  // @349_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @350_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[15]);  // @351_48aba0
  ecx = edx = 0;  // @352_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @353_48aba0
  ecx = edx = 0;  // @354_48aba0
  edi = eax;  // @355_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @356_48aba0
  reg.state = (s32)((u32)(16));  // @357_48aba0
  if ((edi & edi) == 0) goto L48b194;  // @358_48aba0
  ecx = edi;  // @359_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6872068), (u32)(6872012));  // @360_48aba0
  ecx = edx = 0;  // @361_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @362_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @363_48aba0
  goto L48b196;  // @364_48aba0
  L48b194:;
  edi = 0;  // @366_48aba0
  L48b196:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23949), &v, sizeof v); }  // @368_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @369_48aba0
  PV[16] = (u32)(edi);  // @370_48aba0
  reg.state = (s32)((u32)(4294967295));  // @371_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @372_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[16]);  // @373_48aba0
  ecx = edx = 0;  // @374_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @375_48aba0
  ecx = edx = 0;  // @376_48aba0
  edi = eax;  // @377_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @378_48aba0
  reg.state = (s32)((u32)(17));  // @379_48aba0
  if ((edi & edi) == 0) goto L48b1ee;  // @380_48aba0
  ecx = edi;  // @381_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6872140), (u32)(6872080));  // @382_48aba0
  ecx = edx = 0;  // @383_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @384_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @385_48aba0
  goto L48b1f0;  // @386_48aba0
  L48b1ee:;
  edi = 0;  // @388_48aba0
  L48b1f0:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23953), &v, sizeof v); }  // @390_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @391_48aba0
  PV[17] = (u32)(edi);  // @392_48aba0
  reg.state = (s32)((u32)(4294967295));  // @393_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @394_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[17]);  // @395_48aba0
  ecx = edx = 0;  // @396_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @397_48aba0
  ecx = edx = 0;  // @398_48aba0
  edi = eax;  // @399_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @400_48aba0
  reg.state = (s32)((u32)(18));  // @401_48aba0
  if ((edi & edi) == 0) goto L48b248;  // @402_48aba0
  ecx = edi;  // @403_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6872212), (u32)(6872152));  // @404_48aba0
  ecx = edx = 0;  // @405_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @406_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @407_48aba0
  goto L48b24a;  // @408_48aba0
  L48b248:;
  edi = 0;  // @410_48aba0
  L48b24a:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23957), &v, sizeof v); }  // @412_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @413_48aba0
  PV[18] = (u32)(edi);  // @414_48aba0
  reg.state = (s32)((u32)(4294967295));  // @415_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @416_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[18]);  // @417_48aba0
  ecx = edx = 0;  // @418_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @419_48aba0
  ecx = edx = 0;  // @420_48aba0
  edi = eax;  // @421_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @422_48aba0
  reg.state = (s32)((u32)(19));  // @423_48aba0
  if ((edi & edi) == 0) goto L48b2a2;  // @424_48aba0
  ecx = edi;  // @425_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6872252), (u32)(6872228));  // @426_48aba0
  ecx = edx = 0;  // @427_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @428_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @429_48aba0
  goto L48b2a4;  // @430_48aba0
  L48b2a2:;
  edi = 0;  // @432_48aba0
  L48b2a4:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23961), &v, sizeof v); }  // @434_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @435_48aba0
  PV[19] = (u32)(edi);  // @436_48aba0
  reg.state = (s32)((u32)(4294967295));  // @437_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @438_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[19]);  // @439_48aba0
  ecx = edx = 0;  // @440_48aba0
  eax = ext_41e290_cdecl1((u32)(264));  // @441_48aba0
  ecx = edx = 0;  // @442_48aba0
  edi = eax;  // @443_48aba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @444_48aba0
  reg.state = (s32)((u32)(20));  // @445_48aba0
  if ((edi & edi) == 0) goto L48b2fc;  // @446_48aba0
  ecx = edi;  // @447_48aba0
  eax = ext_4d8180_thiscall3(ecx, (u32)(6872296), (u32)(6872268));  // @448_48aba0
  ecx = edx = 0;  // @449_48aba0
  { u32 v = (u32)((u32)(6870912)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @450_48aba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @451_48aba0
  goto L48b2fe;  // @452_48aba0
  L48b2fc:;
  edi = 0;  // @454_48aba0
  L48b2fe:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 23965), &v, sizeof v); }  // @456_48aba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @457_48aba0
  PV[20] = (u32)(edi);  // @458_48aba0
  reg.state = (s32)((u32)(4294967295));  // @459_48aba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @460_48aba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[20]);  // @461_48aba0
  ecx = edx = 0;  // @462_48aba0
  SEH_LEAVE();  // @463_48aba0
  return eax;  // @464_48aba0
}
PCREG(48aba0, lifted_48aba0);

extern "C" u32 lifted_560580(void) {
  SEH_ENTER(0x66b0c0);  // @h_560580
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 404);  // @0_560580
  eax = ext_561020_thiscall1(ecx);  // @1_560580
  ecx = edx = 0;  // @2_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @3_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @4_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_560580
  edx = (u32)(EBP - 404);  // @6_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @7_560580
  PV[0] = (u32)(edx);  // @8_560580
  reg.state = (s32)((u32)(0));  // @9_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[0]);  // @12_560580
  ecx = edx = 0;  // @13_560580
  ecx = (u32)(EBP - 3268);  // @14_560580
  reg.state = (s32)((u32)(4294967295));  // @15_560580
  eax = ext_565840_thiscall1(ecx);  // @16_560580
  ecx = edx = 0;  // @17_560580
  ecx = (u32)(EBP - 3268);  // @18_560580
  eax = ext_565870_thiscall1(ecx);  // @19_560580
  ecx = edx = 0;  // @20_560580
  ecx = (u32)(EBP - 2616);  // @21_560580
  eax = ext_565b90_thiscall1(ecx);  // @22_560580
  ecx = edx = 0;  // @23_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 2548), &v, sizeof v); }  // @24_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 2568), &v, sizeof v); }  // @25_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_560580
  edx = (u32)(EBP - 2616);  // @27_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 2616), &v, sizeof v); }  // @28_560580
  PV[1] = (u32)(edx);  // @29_560580
  reg.state = (s32)((u32)(1));  // @30_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[1]);  // @33_560580
  ecx = edx = 0;  // @34_560580
  ecx = (u32)(EBP - 436);  // @35_560580
  reg.state = (s32)((u32)(4294967295));  // @36_560580
  eax = ext_566bc0_thiscall1(ecx);  // @37_560580
  ecx = edx = 0;  // @38_560580
  ecx = (u32)(EBP - 436);  // @39_560580
  eax = ext_566c90_thiscall1(ecx);  // @40_560580
  ecx = edx = 0;  // @41_560580
  ecx = (u32)(EBP - 404);  // @42_560580
  eax = ext_561160_thiscall1(ecx);  // @43_560580
  ecx = edx = 0;  // @44_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @45_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @46_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_560580
  edx = (u32)(EBP - 404);  // @48_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @49_560580
  PV[2] = (u32)(edx);  // @50_560580
  reg.state = (s32)((u32)(2));  // @51_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[2]);  // @54_560580
  ecx = edx = 0;  // @55_560580
  ecx = (u32)(EBP - 3264);  // @56_560580
  reg.state = (s32)((u32)(4294967295));  // @57_560580
  eax = ext_564460_thiscall1(ecx);  // @58_560580
  ecx = edx = 0;  // @59_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3196), &v, sizeof v); }  // @60_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3216), &v, sizeof v); }  // @61_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_560580
  edx = (u32)(EBP - 3264);  // @63_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3264), &v, sizeof v); }  // @64_560580
  PV[3] = (u32)(edx);  // @65_560580
  reg.state = (s32)((u32)(3));  // @66_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[3]);  // @69_560580
  ecx = edx = 0;  // @70_560580
  ecx = (u32)(EBP - 1088);  // @71_560580
  reg.state = (s32)((u32)(4294967295));  // @72_560580
  eax = ext_567720_thiscall1(ecx);  // @73_560580
  ecx = edx = 0;  // @74_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1020), &v, sizeof v); }  // @75_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1040), &v, sizeof v); }  // @76_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_560580
  edx = (u32)(EBP - 1088);  // @78_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 1088), &v, sizeof v); }  // @79_560580
  PV[4] = (u32)(edx);  // @80_560580
  reg.state = (s32)((u32)(4));  // @81_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @82_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[4]);  // @84_560580
  ecx = edx = 0;  // @85_560580
  ecx = (u32)(EBP - 408);  // @86_560580
  reg.state = (s32)((u32)(4294967295));  // @87_560580
  eax = ext_569380_thiscall1(ecx);  // @88_560580
  ecx = edx = 0;  // @89_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @90_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @91_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_560580
  edx = (u32)(EBP - 408);  // @93_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @94_560580
  PV[5] = (u32)(edx);  // @95_560580
  reg.state = (s32)((u32)(5));  // @96_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @97_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[5]);  // @99_560580
  ecx = edx = 0;  // @100_560580
  ecx = (u32)(EBP - 480);  // @101_560580
  reg.state = (s32)((u32)(4294967295));  // @102_560580
  eax = ext_5696b0_thiscall1(ecx);  // @103_560580
  ecx = edx = 0;  // @104_560580
  ecx = (u32)(EBP - 480);  // @105_560580
  eax = ext_569730_thiscall1(ecx);  // @106_560580
  ecx = edx = 0;  // @107_560580
  ecx = (u32)(EBP - 3821);  // @108_560580
  eax = ext_56ad80_thiscall1(ecx);  // @109_560580
  ecx = edx = 0;  // @110_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3753), &v, sizeof v); }  // @111_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3773), &v, sizeof v); }  // @112_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @113_560580
  edx = (u32)(EBP - 3821);  // @114_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3821), &v, sizeof v); }  // @115_560580
  PV[6] = (u32)(edx);  // @116_560580
  reg.state = (s32)((u32)(6));  // @117_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @118_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[6]);  // @120_560580
  ecx = edx = 0;  // @121_560580
  ecx = (u32)(EBP - 3332);  // @122_560580
  reg.state = (s32)((u32)(4294967295));  // @123_560580
  eax = ext_56b2d0_thiscall1(ecx);  // @124_560580
  ecx = edx = 0;  // @125_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3264), &v, sizeof v); }  // @126_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3284), &v, sizeof v); }  // @127_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @128_560580
  edx = (u32)(EBP - 3332);  // @129_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3332), &v, sizeof v); }  // @130_560580
  PV[7] = (u32)(edx);  // @131_560580
  reg.state = (s32)((u32)(7));  // @132_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @133_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[7]);  // @135_560580
  ecx = edx = 0;  // @136_560580
  ecx = (u32)(EBP - 508);  // @137_560580
  reg.state = (s32)((u32)(4294967295));  // @138_560580
  eax = ext_56c810_thiscall1(ecx);  // @139_560580
  ecx = edx = 0;  // @140_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 440), &v, sizeof v); }  // @141_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @142_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @143_560580
  edx = (u32)(EBP - 508);  // @144_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 508), &v, sizeof v); }  // @145_560580
  PV[8] = (u32)(edx);  // @146_560580
  reg.state = (s32)((u32)(8));  // @147_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @148_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[8]);  // @150_560580
  ecx = edx = 0;  // @151_560580
  ecx = (u32)(EBP - 548);  // @152_560580
  reg.state = (s32)((u32)(4294967295));  // @153_560580
  eax = ext_56db70_thiscall1(ecx);  // @154_560580
  ecx = edx = 0;  // @155_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 480), &v, sizeof v); }  // @156_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 500), &v, sizeof v); }  // @157_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @158_560580
  edx = (u32)(EBP - 548);  // @159_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @160_560580
  PV[9] = (u32)(edx);  // @161_560580
  reg.state = (s32)((u32)(9));  // @162_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @163_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[9]);  // @165_560580
  ecx = edx = 0;  // @166_560580
  ecx = (u32)(EBP - 1528);  // @167_560580
  reg.state = (s32)((u32)(4294967295));  // @168_560580
  eax = ext_56e990_thiscall1(ecx);  // @169_560580
  ecx = edx = 0;  // @170_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1460), &v, sizeof v); }  // @171_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1480), &v, sizeof v); }  // @172_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @173_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 1528), &v, sizeof v); }  // @174_560580
  reg.state = (s32)((u32)(10));  // @175_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @176_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_560580
  edx = (u32)(EBP - 1528);  // @178_560580
  PV[10] = (u32)(edx);  // @179_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[10]);  // @180_560580
  ecx = edx = 0;  // @181_560580
  ecx = (u32)(EBP - 588);  // @182_560580
  reg.state = (s32)((u32)(4294967295));  // @183_560580
  eax = ext_56fea0_thiscall1(ecx);  // @184_560580
  ecx = edx = 0;  // @185_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @186_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @187_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_560580
  edx = (u32)(EBP - 588);  // @189_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 588), &v, sizeof v); }  // @190_560580
  PV[11] = (u32)(edx);  // @191_560580
  reg.state = (s32)((u32)(11));  // @192_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @193_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @194_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[11]);  // @195_560580
  ecx = edx = 0;  // @196_560580
  ecx = (u32)(EBP - 428);  // @197_560580
  reg.state = (s32)((u32)(4294967295));  // @198_560580
  eax = ext_571960_thiscall1(ecx);  // @199_560580
  ecx = edx = 0;  // @200_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @201_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 380), &v, sizeof v); }  // @202_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @203_560580
  edx = (u32)(EBP - 428);  // @204_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @205_560580
  PV[12] = (u32)(edx);  // @206_560580
  reg.state = (s32)((u32)(12));  // @207_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @208_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[12]);  // @210_560580
  ecx = edx = 0;  // @211_560580
  ecx = (u32)(EBP - 2196);  // @212_560580
  reg.state = (s32)((u32)(4294967295));  // @213_560580
  eax = ext_572360_thiscall1(ecx);  // @214_560580
  ecx = edx = 0;  // @215_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 2128), &v, sizeof v); }  // @216_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 2148), &v, sizeof v); }  // @217_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @218_560580
  edx = (u32)(EBP - 2196);  // @219_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 2196), &v, sizeof v); }  // @220_560580
  PV[13] = (u32)(edx);  // @221_560580
  reg.state = (s32)((u32)(13));  // @222_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @223_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[13]);  // @225_560580
  ecx = edx = 0;  // @226_560580
  ecx = (u32)(EBP - 404);  // @227_560580
  reg.state = (s32)((u32)(4294967295));  // @228_560580
  eax = ext_572e40_thiscall1(ecx);  // @229_560580
  ecx = edx = 0;  // @230_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @231_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @232_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @233_560580
  edx = (u32)(EBP - 404);  // @234_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @235_560580
  PV[14] = (u32)(edx);  // @236_560580
  reg.state = (s32)((u32)(14));  // @237_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @238_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @239_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[14]);  // @240_560580
  ecx = edx = 0;  // @241_560580
  ecx = (u32)(EBP - 536);  // @242_560580
  reg.state = (s32)((u32)(4294967295));  // @243_560580
  eax = ext_573590_thiscall1(ecx);  // @244_560580
  ecx = edx = 0;  // @245_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 468), &v, sizeof v); }  // @246_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 488), &v, sizeof v); }  // @247_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @248_560580
  edx = (u32)(EBP - 536);  // @249_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @250_560580
  PV[15] = (u32)(edx);  // @251_560580
  reg.state = (s32)((u32)(15));  // @252_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @253_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @254_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[15]);  // @255_560580
  ecx = edx = 0;  // @256_560580
  ecx = (u32)(EBP - 752);  // @257_560580
  reg.state = (s32)((u32)(4294967295));  // @258_560580
  eax = ext_574c60_thiscall1(ecx);  // @259_560580
  ecx = edx = 0;  // @260_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 684), &v, sizeof v); }  // @261_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 704), &v, sizeof v); }  // @262_560580
  reg.state = (s32)((u32)(16));  // @263_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 752), &v, sizeof v); }  // @264_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @265_560580
  edx = (u32)(EBP - 752);  // @266_560580
  PV[16] = (u32)(edx);  // @267_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @268_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @269_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[16]);  // @270_560580
  ecx = edx = 0;  // @271_560580
  ecx = (u32)(EBP - 580);  // @272_560580
  reg.state = (s32)((u32)(4294967295));  // @273_560580
  eax = ext_575d50_thiscall1(ecx);  // @274_560580
  ecx = edx = 0;  // @275_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 512), &v, sizeof v); }  // @276_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @277_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @278_560580
  edx = (u32)(EBP - 580);  // @279_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 580), &v, sizeof v); }  // @280_560580
  PV[17] = (u32)(edx);  // @281_560580
  reg.state = (s32)((u32)(17));  // @282_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @283_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @284_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[17]);  // @285_560580
  ecx = edx = 0;  // @286_560580
  ecx = (u32)(EBP - 404);  // @287_560580
  reg.state = (s32)((u32)(4294967295));  // @288_560580
  eax = ext_5773f0_thiscall1(ecx);  // @289_560580
  ecx = edx = 0;  // @290_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @291_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @292_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @293_560580
  edx = (u32)(EBP - 404);  // @294_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @295_560580
  PV[18] = (u32)(edx);  // @296_560580
  reg.state = (s32)((u32)(18));  // @297_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @298_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @299_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[18]);  // @300_560580
  ecx = edx = 0;  // @301_560580
  ecx = (u32)(EBP - 568);  // @302_560580
  reg.state = (s32)((u32)(4294967295));  // @303_560580
  eax = ext_577830_thiscall1(ecx);  // @304_560580
  ecx = edx = 0;  // @305_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 500), &v, sizeof v); }  // @306_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @307_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @308_560580
  edx = (u32)(EBP - 568);  // @309_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 568), &v, sizeof v); }  // @310_560580
  PV[19] = (u32)(edx);  // @311_560580
  reg.state = (s32)((u32)(19));  // @312_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @313_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @314_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[19]);  // @315_560580
  ecx = edx = 0;  // @316_560580
  ecx = (u32)(EBP - 460);  // @317_560580
  reg.state = (s32)((u32)(4294967295));  // @318_560580
  eax = ext_578560_thiscall1(ecx);  // @319_560580
  ecx = edx = 0;  // @320_560580
  ecx = (u32)(EBP - 460);  // @321_560580
  eax = ext_578710_thiscall1(ecx);  // @322_560580
  ecx = edx = 0;  // @323_560580
  ecx = (u32)(EBP - 3820);  // @324_560580
  eax = ext_57a100_thiscall1(ecx);  // @325_560580
  ecx = edx = 0;  // @326_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3752), &v, sizeof v); }  // @327_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3772), &v, sizeof v); }  // @328_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @329_560580
  edx = (u32)(EBP - 3820);  // @330_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3820), &v, sizeof v); }  // @331_560580
  PV[20] = (u32)(edx);  // @332_560580
  reg.state = (s32)((u32)(20));  // @333_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @334_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @335_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[20]);  // @336_560580
  ecx = edx = 0;  // @337_560580
  ecx = (u32)(EBP - 404);  // @338_560580
  reg.state = (s32)((u32)(4294967295));  // @339_560580
  eax = ext_57a3b0_thiscall1(ecx);  // @340_560580
  ecx = edx = 0;  // @341_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @342_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @343_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @344_560580
  edx = (u32)(EBP - 404);  // @345_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @346_560580
  PV[21] = (u32)(edx);  // @347_560580
  reg.state = (s32)((u32)(21));  // @348_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @349_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @350_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[21]);  // @351_560580
  ecx = edx = 0;  // @352_560580
  reg.state = (s32)((u32)(4294967295));  // @353_560580
  ecx = (u32)(EBP - 428);  // @354_560580
  eax = ext_57a440_thiscall1(ecx);  // @355_560580
  ecx = edx = 0;  // @356_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @357_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 380), &v, sizeof v); }  // @358_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @359_560580
  edx = (u32)(EBP - 428);  // @360_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @361_560580
  PV[22] = (u32)(edx);  // @362_560580
  reg.state = (s32)((u32)(22));  // @363_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @364_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @365_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[22]);  // @366_560580
  ecx = edx = 0;  // @367_560580
  ecx = (u32)(EBP - 408);  // @368_560580
  reg.state = (s32)((u32)(4294967295));  // @369_560580
  eax = ext_57abc0_thiscall1(ecx);  // @370_560580
  ecx = edx = 0;  // @371_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @372_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @373_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @374_560580
  edx = (u32)(EBP - 408);  // @375_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @376_560580
  PV[23] = (u32)(edx);  // @377_560580
  reg.state = (s32)((u32)(23));  // @378_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @379_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @380_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[23]);  // @381_560580
  ecx = edx = 0;  // @382_560580
  ecx = (u32)(EBP - 3272);  // @383_560580
  reg.state = (s32)((u32)(4294967295));  // @384_560580
  eax = ext_57baa0_thiscall1(ecx);  // @385_560580
  ecx = edx = 0;  // @386_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3204), &v, sizeof v); }  // @387_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3224), &v, sizeof v); }  // @388_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @389_560580
  edx = (u32)(EBP - 3272);  // @390_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3272), &v, sizeof v); }  // @391_560580
  PV[24] = (u32)(edx);  // @392_560580
  reg.state = (s32)((u32)(24));  // @393_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @394_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @395_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[24]);  // @396_560580
  ecx = edx = 0;  // @397_560580
  ecx = (u32)(EBP - 3865);  // @398_560580
  reg.state = (s32)((u32)(4294967295));  // @399_560580
  eax = ext_573650_thiscall4(ecx, (u32)(0), (u32)(0), (u32)(0));  // @400_560580
  ecx = edx = 0;  // @401_560580
  ecx = (u32)(EBP - 3865);  // @402_560580
  eax = ext_43de70_thiscall1(ecx);  // @403_560580
  ecx = edx = 0;  // @404_560580
  ecx = (u32)(EBP - 404);  // @405_560580
  eax = ext_57bd90_thiscall1(ecx);  // @406_560580
  ecx = edx = 0;  // @407_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @408_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @409_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @410_560580
  edx = (u32)(EBP - 404);  // @411_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @412_560580
  PV[25] = (u32)(edx);  // @413_560580
  reg.state = (s32)((u32)(25));  // @414_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @415_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @416_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[25]);  // @417_560580
  ecx = edx = 0;  // @418_560580
  ecx = (u32)(EBP - 408);  // @419_560580
  reg.state = (s32)((u32)(4294967295));  // @420_560580
  eax = ext_57c100_thiscall1(ecx);  // @421_560580
  ecx = edx = 0;  // @422_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @423_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @424_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @425_560580
  edx = (u32)(EBP - 408);  // @426_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @427_560580
  PV[26] = (u32)(edx);  // @428_560580
  reg.state = (s32)((u32)(26));  // @429_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @430_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @431_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[26]);  // @432_560580
  ecx = edx = 0;  // @433_560580
  ecx = (u32)(EBP - 404);  // @434_560580
  reg.state = (s32)((u32)(4294967295));  // @435_560580
  eax = ext_57c460_thiscall1(ecx);  // @436_560580
  ecx = edx = 0;  // @437_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @438_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @439_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @440_560580
  edx = (u32)(EBP - 404);  // @441_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @442_560580
  PV[27] = (u32)(edx);  // @443_560580
  reg.state = (s32)((u32)(27));  // @444_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @445_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @446_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[27]);  // @447_560580
  ecx = edx = 0;  // @448_560580
  ecx = (u32)(EBP - 876);  // @449_560580
  reg.state = (s32)((u32)(4294967295));  // @450_560580
  eax = ext_57c7c0_thiscall1(ecx);  // @451_560580
  ecx = edx = 0;  // @452_560580
  ecx = (u32)(EBP - 264);  // @453_560580
  eax = ext_4ccf60_thiscall1(ecx);  // @454_560580
  ecx = edx = 0;  // @455_560580
  ecx = (u32)(EBP - 304);  // @456_560580
  eax = ext_4cce40_thiscall1(ecx);  // @457_560580
  ecx = edx = 0;  // @458_560580
  ecx = (u32)(EBP - 476);  // @459_560580
  eax = ext_4ccf60_thiscall1(ecx);  // @460_560580
  ecx = edx = 0;  // @461_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 808), &v, sizeof v); }  // @462_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 828), &v, sizeof v); }  // @463_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @464_560580
  edx = (u32)(EBP - 876);  // @465_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 876), &v, sizeof v); }  // @466_560580
  PV[28] = (u32)(edx);  // @467_560580
  reg.state = (s32)((u32)(28));  // @468_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @469_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @470_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[28]);  // @471_560580
  ecx = edx = 0;  // @472_560580
  ecx = (u32)(EBP - 416);  // @473_560580
  reg.state = (s32)((u32)(4294967295));  // @474_560580
  eax = ext_57f1b0_thiscall1(ecx);  // @475_560580
  ecx = edx = 0;  // @476_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @477_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @478_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @479_560580
  edx = (u32)(EBP - 416);  // @480_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 416), &v, sizeof v); }  // @481_560580
  PV[29] = (u32)(edx);  // @482_560580
  reg.state = (s32)((u32)(29));  // @483_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @484_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @485_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[29]);  // @486_560580
  ecx = edx = 0;  // @487_560580
  ecx = (u32)(EBP - 456);  // @488_560580
  reg.state = (s32)((u32)(4294967295));  // @489_560580
  eax = ext_57aea0_thiscall1(ecx);  // @490_560580
  ecx = edx = 0;  // @491_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 388), &v, sizeof v); }  // @492_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @493_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @494_560580
  edx = (u32)(EBP - 456);  // @495_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @496_560580
  PV[30] = (u32)(edx);  // @497_560580
  reg.state = (s32)((u32)(30));  // @498_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @499_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @500_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[30]);  // @501_560580
  ecx = edx = 0;  // @502_560580
  ecx = (u32)(EBP - 3724);  // @503_560580
  reg.state = (s32)((u32)(4294967295));  // @504_560580
  eax = ext_57c100_thiscall1(ecx);  // @505_560580
  ecx = edx = 0;  // @506_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3656), &v, sizeof v); }  // @507_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3676), &v, sizeof v); }  // @508_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @509_560580
  edx = (u32)(EBP - 3724);  // @510_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3724), &v, sizeof v); }  // @511_560580
  PV[31] = (u32)(edx);  // @512_560580
  reg.state = (s32)((u32)(31));  // @513_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @514_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @515_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[31]);  // @516_560580
  ecx = edx = 0;  // @517_560580
  SEH_LEAVE();  // @518_560580
  ext_633654(G(u32, 0x6f5630));  // @519_560580
  return eax;  // @520_560580
}
PCREG(560580, lifted_560580);

