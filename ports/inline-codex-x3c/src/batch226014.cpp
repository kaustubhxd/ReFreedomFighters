// batch226014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_471b50_thiscall4(u32, u32, u32, u32) __asm__("ext_471b50");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4d8180_thiscall3(u32, u32, u32) __asm__("ext_4d8180");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_480a40(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x667403);  // @h_480a40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edi = ecx;  // @0_480a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_480a40
  eax = ext_471b50_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_480a40
  ecx = edx = 0;  // @3_480a40
  { u32 v = (u32)((u32)(6862416)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @4_480a40
  eax = (u32)(edi + 1117);  // @5_480a40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1059), &v, sizeof v); }  // @6_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1069), &v, sizeof v); }  // @7_480a40
  { u32 v = (u32)((u32)(3223742054)); __builtin_memcpy((void *)(u32)(edi + 1073), &v, sizeof v); }  // @8_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1077), &v, sizeof v); }  // @9_480a40
  PS[2] = eax;  // @10_480a40
  reg.state = (s32)((u32)(0));  // @11_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1113), &v, sizeof v); }  // @12_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1109), &v, sizeof v); }  // @13_480a40
  eax = ext_634d10_cdecl3((u32)(PS[2]), (u32)(0), (u32)(128));  // @14_480a40
  ecx = edx = 0;  // @15_480a40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1068), &v, sizeof v); }  // @16_480a40
  ebx = (u32)(edi + 1537);  // @17_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1546), &v, sizeof v); }  // @18_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1542), &v, sizeof v); }  // @19_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1538), &v, sizeof v); }  // @20_480a40
  { u16 v = (u16)((u32)(257)); __builtin_memcpy((void *)(u32)(edi + 1535), &v, sizeof v); }  // @21_480a40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @22_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1430), &v, sizeof v); }  // @23_480a40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1534), &v, sizeof v); }  // @24_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1060), &v, sizeof v); }  // @25_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1093), &v, sizeof v); }  // @26_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1097), &v, sizeof v); }  // @27_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1101), &v, sizeof v); }  // @28_480a40
  { u32 v = (u32)((u32)(256)); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @29_480a40
  eax = ext_41e290_cdecl1((u32)(40));  // @30_480a40
  ecx = edx = 0;  // @31_480a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @32_480a40
  reg.state = (s32)((u32)(1));  // @33_480a40
  if ((eax & eax) == 0) goto L480b6e;  // @34_480a40
  ecx = eax;  // @35_480a40
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(3));  // @36_480a40
  ecx = edx = 0;  // @37_480a40
  goto L480b70;  // @38_480a40
  L480b6e:;
  eax = 0;  // @40_480a40
  L480b70:;
  ecx = (u32)(edi + 1434);  // @42_480a40
  reg.state = (s32)((u32)(0));  // @43_480a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1562), &v, sizeof v); }  // @44_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1430), &v, sizeof v); }  // @45_480a40
  eax = ext_4de7a0_thiscall1(ecx);  // @46_480a40
  ecx = edx = 0;  // @47_480a40
  ecx = (u32)(edi + 1269);  // @48_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1470), &v, sizeof v); }  // @49_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1474), &v, sizeof v); }  // @50_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1478), &v, sizeof v); }  // @51_480a40
  eax = ext_4de7a0_thiscall1(ecx);  // @52_480a40
  ecx = edx = 0;  // @53_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1305), &v, sizeof v); }  // @54_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1309), &v, sizeof v); }  // @55_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1313), &v, sizeof v); }  // @56_480a40
  { u32 v = (u32)((u32)(1108082688)); __builtin_memcpy((void *)(u32)(edi + 1081), &v, sizeof v); }  // @57_480a40
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 1085), &v, sizeof v); }  // @58_480a40
  { u32 v = (u32)((u32)(1108082688)); __builtin_memcpy((void *)(u32)(edi + 1089), &v, sizeof v); }  // @59_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1482), &v, sizeof v); }  // @60_480a40
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 1105), &v, sizeof v); }  // @61_480a40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1042), &v, sizeof v); }  // @62_480a40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1610), &v, sizeof v); }  // @63_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @64_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @65_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_480a40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6864104), (u32)(0), (u32)(6864060), (u32)(145));  // @67_480a40
  ecx = edx = 0;  // @68_480a40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 1566), &v, sizeof v); }  // @69_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_480a40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6864120), (u32)(0), (u32)(6864060), (u32)(146));  // @73_480a40
  ecx = edx = 0;  // @74_480a40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 1568), &v, sizeof v); }  // @75_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @76_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @77_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_480a40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6864136), (u32)(0), (u32)(6864060), (u32)(147));  // @79_480a40
  ecx = edx = 0;  // @80_480a40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 1570), &v, sizeof v); }  // @81_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @83_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_480a40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6864152), (u32)(0), (u32)(6864060), (u32)(148));  // @85_480a40
  ecx = edx = 0;  // @86_480a40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 1572), &v, sizeof v); }  // @87_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @89_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_480a40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6864172), (u32)(0), (u32)(6864060), (u32)(149));  // @91_480a40
  ecx = edx = 0;  // @92_480a40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 1574), &v, sizeof v); }  // @93_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @94_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @95_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_480a40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6864192), (u32)(0), (u32)(6864060), (u32)(150));  // @97_480a40
  ecx = edx = 0;  // @98_480a40
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 1576), &v, sizeof v); }  // @99_480a40
  eax = ext_41e290_cdecl1((u32)(264));  // @100_480a40
  ecx = edx = 0;  // @101_480a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @102_480a40
  reg.state = (s32)((u32)(2));  // @103_480a40
  if ((eax & eax) == 0) goto L480d4a;  // @104_480a40
  ecx = eax;  // @105_480a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(6864236), (u32)(6864208), (u32)(7338592));  // @106_480a40
  ecx = edx = 0;  // @107_480a40
  edx = eax;  // @108_480a40
  goto L480d4c;  // @109_480a40
  L480d4a:;
  edx = 0;  // @111_480a40
  L480d4c:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 1586), &v, sizeof v); }  // @113_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @114_480a40
  PS[0] = edx;  // @115_480a40
  reg.state = (s32)((u32)(0));  // @116_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_480a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @118_480a40
  ecx = edx = 0;  // @119_480a40
  eax = ext_41e290_cdecl1((u32)(264));  // @120_480a40
  ecx = edx = 0;  // @121_480a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @122_480a40
  reg.state = (s32)((u32)(3));  // @123_480a40
  if ((eax & eax) == 0) goto L480d97;  // @124_480a40
  ecx = eax;  // @125_480a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(6864280), (u32)(6864240), (u32)(7338596));  // @126_480a40
  ecx = edx = 0;  // @127_480a40
  edx = eax;  // @128_480a40
  goto L480d99;  // @129_480a40
  L480d97:;
  edx = 0;  // @131_480a40
  L480d99:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 1582), &v, sizeof v); }  // @133_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_480a40
  PS[0] = edx;  // @135_480a40
  reg.state = (s32)((u32)(0));  // @136_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_480a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @138_480a40
  ecx = edx = 0;  // @139_480a40
  eax = ext_41e290_cdecl1((u32)(264));  // @140_480a40
  ecx = edx = 0;  // @141_480a40
  esi = eax;  // @142_480a40
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @143_480a40
  reg.state = (s32)((u32)(4));  // @144_480a40
  if ((esi & esi) == 0) goto L480deb;  // @145_480a40
  ecx = esi;  // @146_480a40
  eax = ext_4d8180_thiscall3(ecx, (u32)(6864336), (u32)(6864300));  // @147_480a40
  ecx = edx = 0;  // @148_480a40
  { u32 v = (u32)((u32)(6862392)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @149_480a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 260), &v, sizeof v); }  // @150_480a40
  goto L480ded;  // @151_480a40
  L480deb:;
  esi = 0;  // @153_480a40
  L480ded:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 1590), &v, sizeof v); }  // @155_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_480a40
  PS[0] = esi;  // @157_480a40
  reg.state = (s32)((u32)(0));  // @158_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_480a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @160_480a40
  ecx = edx = 0;  // @161_480a40
  eax = ext_41e290_cdecl1((u32)(264));  // @162_480a40
  ecx = edx = 0;  // @163_480a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @164_480a40
  reg.state = (s32)((u32)(5));  // @165_480a40
  if ((eax & eax) == 0) goto L480e3a;  // @166_480a40
  ecx = (u32)(edi + 1610);  // @167_480a40
  PS[0] = ecx;  // @168_480a40
  ecx = eax;  // @169_480a40
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6864420), (u32)(6864344), (u32)(PS[0]));  // @170_480a40
  ecx = edx = 0;  // @171_480a40
  edx = eax;  // @172_480a40
  goto L480e3c;  // @173_480a40
  L480e3a:;
  edx = 0;  // @175_480a40
  L480e3c:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 1594), &v, sizeof v); }  // @177_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @178_480a40
  PS[0] = edx;  // @179_480a40
  reg.state = (s32)((u32)(0));  // @180_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @181_480a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @182_480a40
  ecx = edx = 0;  // @183_480a40
  eax = ext_41e290_cdecl1((u32)(264));  // @184_480a40
  ecx = edx = 0;  // @185_480a40
  esi = eax;  // @186_480a40
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @187_480a40
  reg.state = (s32)((u32)(6));  // @188_480a40
  if ((esi & esi) == 0) goto L480e8e;  // @189_480a40
  ecx = esi;  // @190_480a40
  eax = ext_4d8180_thiscall3(ecx, (u32)(6864476), (u32)(6864436));  // @191_480a40
  ecx = edx = 0;  // @192_480a40
  { u32 v = (u32)((u32)(6864028)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @193_480a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 260), &v, sizeof v); }  // @194_480a40
  goto L480e90;  // @195_480a40
  L480e8e:;
  esi = 0;  // @197_480a40
  L480e90:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 1578), &v, sizeof v); }  // @199_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @200_480a40
  PS[0] = esi;  // @201_480a40
  reg.state = (s32)((u32)(0));  // @202_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @203_480a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @204_480a40
  ecx = edx = 0;  // @205_480a40
  eax = ext_41e290_cdecl1((u32)(264));  // @206_480a40
  ecx = edx = 0;  // @207_480a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @208_480a40
  reg.state = (s32)((u32)(7));  // @209_480a40
  if ((eax & eax) == 0) goto L480ed7;  // @210_480a40
  PS[0] = ebx;  // @211_480a40
  ecx = eax;  // @212_480a40
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6864512), (u32)(6864484), (u32)(PS[0]));  // @213_480a40
  ecx = edx = 0;  // @214_480a40
  edx = eax;  // @215_480a40
  goto L480ed9;  // @216_480a40
  L480ed7:;
  edx = 0;  // @218_480a40
  L480ed9:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 1598), &v, sizeof v); }  // @220_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @221_480a40
  PS[0] = edx;  // @222_480a40
  reg.state = (s32)((u32)(0));  // @223_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_480a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @225_480a40
  ecx = edx = 0;  // @226_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @227_480a40
  if ((eax & (u32)(6144)) == 0) goto L480f5d;  // @228_480a40
  eax = (eax & (u32)(4294961151));  // @229_480a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @230_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @231_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @232_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @233_480a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1043), sizeof v); (u32)v; }));  // @234_480a40
  ecx = edx = 0;  // @235_480a40
  ebx = eax;  // @236_480a40
  if ((ebx & ebx) == 0) goto L480f5d;  // @237_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @238_480a40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @239_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @240_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @241_480a40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6864604), (u32)(0), (u32)(6864060), (u32)(640), (u32)(0), (u32)(0));  // @242_480a40
  ecx = edx = 0;  // @243_480a40
  eax = (eax & 0xffff);  // @244_480a40
  ecx = ebx;  // @245_480a40
  PS[0] = eax;  // @246_480a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, (u32)(PS[0]));  // @247_480a40
  ecx = edx = 0;  // @248_480a40
  L480f5d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1043), &v, sizeof v); }  // @250_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1550), &v, sizeof v); }  // @251_480a40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1558), &v, sizeof v); }  // @252_480a40
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 324), &v, sizeof v); }  // @253_480a40
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 326), &v, sizeof v); }  // @254_480a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @255_480a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1032), sizeof v); (u32)v; });  // @256_480a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 1036), &v, sizeof v); }  // @257_480a40
  eax = edi;  // @258_480a40
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1032), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 1032), &v, sizeof v); }  // @259_480a40
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(edi + 1245), &v, sizeof v); }  // @260_480a40
  SEH_LEAVE();  // @261_480a40
  return eax;  // @262_480a40
}
PCREG(480a40, lifted_480a40);

