// batch226012.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_598440(u32 ecx_in) {
  SEH_ENTER(0x66bb65);  // @h_598440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_598440
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_598440
  eax = ext_469870_thiscall1(ecx);  // @2_598440
  ecx = edx = 0;  // @3_598440
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_598440
  { u32 v = (u32)((u32)(7001516)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_598440
  reg.state = (s32)((u32)(0));  // @7_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7586), &v, sizeof v); }  // @8_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7590), &v, sizeof v); }  // @9_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7594), &v, sizeof v); }  // @10_598440
  eax = (u32)(esi + 7598);  // @11_598440
  reg.state = (s32)((u32)(1));  // @12_598440
  PS[2] = eax;  // @13_598440
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 8923), &v, sizeof v); }  // @14_598440
  eax = ext_634d10_cdecl3((u32)(PS[2]), (u32)(0), (u32)(512));  // @15_598440
  ecx = edx = 0;  // @16_598440
  eax = (u32)(esi + 230);  // @17_598440
  PS[2] = eax;  // @18_598440
  eax = ext_634d10_cdecl3((u32)(PS[2]), (u32)(0), (u32)(512));  // @19_598440
  ecx = edx = 0;  // @20_598440
  ebx = (u32)(esi + 109);  // @21_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8919), &v, sizeof v); }  // @22_598440
  edi = (u32)(esi + 105);  // @23_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7569), &v, sizeof v); }  // @24_598440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @25_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7439), &v, sizeof v); }  // @26_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1267), &v, sizeof v); }  // @27_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1271), &v, sizeof v); }  // @28_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @29_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7565), &v, sizeof v); }  // @30_598440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 7564), &v, sizeof v); }  // @31_598440
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 7560), &v, sizeof v); }  // @32_598440
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 7552), &v, sizeof v); }  // @33_598440
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 7556), &v, sizeof v); }  // @34_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8114), &v, sizeof v); }  // @35_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8110), &v, sizeof v); }  // @36_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 746), &v, sizeof v); }  // @37_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 742), &v, sizeof v); }  // @38_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1263), &v, sizeof v); }  // @39_598440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 7503), &v, sizeof v); }  // @40_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7491), &v, sizeof v); }  // @41_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7487), &v, sizeof v); }  // @42_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7483), &v, sizeof v); }  // @43_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @44_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7443), &v, sizeof v); }  // @45_598440
  { u32 v = (u32)((u32)(1161527296)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @46_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @47_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8118), &v, sizeof v); }  // @48_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8122), &v, sizeof v); }  // @49_598440
  { u32 v = (u32)((u32)(12)); __builtin_memcpy((void *)(u32)(esi + 8126), &v, sizeof v); }  // @50_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7423), &v, sizeof v); }  // @51_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @52_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @53_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8898), &v, sizeof v); }  // @54_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8911), &v, sizeof v); }  // @55_598440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8910), &v, sizeof v); }  // @56_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8915), &v, sizeof v); }  // @57_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8927), &v, sizeof v); }  // @58_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 226), &v, sizeof v); }  // @59_598440
  eax = ext_41e290_cdecl1((u32)(264));  // @60_598440
  ecx = edx = 0;  // @61_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @62_598440
  reg.state = (s32)((u32)(2));  // @63_598440
  if ((eax & eax) == 0) goto L59865f;  // @64_598440
  PS[0] = ebx;  // @65_598440
  ecx = eax;  // @66_598440
  eax = ext_4d8330_thiscall4(ecx, (u32)(7001700), (u32)(7001664), (u32)(PS[0]));  // @67_598440
  ecx = edx = 0;  // @68_598440
  edx = eax;  // @69_598440
  goto L598661;  // @70_598440
  L59865f:;
  edx = 0;  // @72_598440
  L598661:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @74_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_598440
  PS[0] = edx;  // @76_598440
  reg.state = (s32)((u32)(1));  // @77_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_598440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @79_598440
  ecx = edx = 0;  // @80_598440
  eax = ext_41e290_cdecl1((u32)(264));  // @81_598440
  ecx = edx = 0;  // @82_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @83_598440
  reg.state = (s32)((u32)(3));  // @84_598440
  ebx = (u32)(esi + 84);  // @85_598440
  if ((eax & eax) == 0) goto L5986a8;  // @86_598440
  PS[0] = ebx;  // @87_598440
  ecx = eax;  // @88_598440
  eax = ext_4d8330_thiscall4(ecx, (u32)(7001744), (u32)(7001712), (u32)(PS[0]));  // @89_598440
  ecx = edx = 0;  // @90_598440
  edx = eax;  // @91_598440
  goto L5986aa;  // @92_598440
  L5986a8:;
  edx = 0;  // @94_598440
  L5986aa:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @96_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @97_598440
  PS[0] = edx;  // @98_598440
  reg.state = (s32)((u32)(1));  // @99_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_598440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @101_598440
  ecx = edx = 0;  // @102_598440
  eax = ext_41e290_cdecl1((u32)(264));  // @103_598440
  ecx = edx = 0;  // @104_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @105_598440
  reg.state = (s32)((u32)(4));  // @106_598440
  if ((eax & eax) == 0) goto L5986ee;  // @107_598440
  PS[0] = edi;  // @108_598440
  ecx = eax;  // @109_598440
  eax = ext_4d8330_thiscall4(ecx, (u32)(7001796), (u32)(7001756), (u32)(PS[0]));  // @110_598440
  ecx = edx = 0;  // @111_598440
  edx = eax;  // @112_598440
  goto L5986f0;  // @113_598440
  L5986ee:;
  edx = 0;  // @115_598440
  L5986f0:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @117_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @118_598440
  PS[0] = edx;  // @119_598440
  reg.state = (s32)((u32)(1));  // @120_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @121_598440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @122_598440
  ecx = edx = 0;  // @123_598440
  eax = ext_41e290_cdecl1((u32)(264));  // @124_598440
  ecx = edx = 0;  // @125_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @126_598440
  reg.state = (s32)((u32)(5));  // @127_598440
  if ((eax & eax) == 0) goto L598734;  // @128_598440
  PS[0] = edi;  // @129_598440
  ecx = eax;  // @130_598440
  eax = ext_4d8330_thiscall4(ecx, (u32)(7001800), (u32)(7001756), (u32)(PS[0]));  // @131_598440
  ecx = edx = 0;  // @132_598440
  edx = eax;  // @133_598440
  goto L598736;  // @134_598440
  L598734:;
  edx = 0;  // @136_598440
  L598736:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @138_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @139_598440
  PS[0] = edx;  // @140_598440
  reg.state = (s32)((u32)(1));  // @141_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @142_598440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @143_598440
  ecx = edx = 0;  // @144_598440
  eax = ext_41e290_cdecl1((u32)(264));  // @145_598440
  ecx = edx = 0;  // @146_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @147_598440
  reg.state = (s32)((u32)(6));  // @148_598440
  if ((eax & eax) == 0) goto L59877d;  // @149_598440
  ecx = (u32)(esi + 101);  // @150_598440
  PS[0] = ecx;  // @151_598440
  ecx = eax;  // @152_598440
  eax = ext_4d8330_thiscall4(ecx, (u32)(7001852), (u32)(7001808), (u32)(PS[0]));  // @153_598440
  ecx = edx = 0;  // @154_598440
  edx = eax;  // @155_598440
  goto L59877f;  // @156_598440
  L59877d:;
  edx = 0;  // @158_598440
  L59877f:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @160_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @161_598440
  PS[0] = edx;  // @162_598440
  reg.state = (s32)((u32)(1));  // @163_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_598440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @165_598440
  ecx = edx = 0;  // @166_598440
  eax = ext_41e290_cdecl1((u32)(264));  // @167_598440
  ecx = edx = 0;  // @168_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @169_598440
  reg.state = (s32)((u32)(7));  // @170_598440
  if ((eax & eax) == 0) goto L5987c9;  // @171_598440
  ecx = (u32)(esi + 8931);  // @172_598440
  PS[0] = ecx;  // @173_598440
  ecx = eax;  // @174_598440
  eax = ext_4d8330_thiscall4(ecx, (u32)(7001920), (u32)(7001856), (u32)(PS[0]));  // @175_598440
  ecx = edx = 0;  // @176_598440
  edx = eax;  // @177_598440
  goto L5987cb;  // @178_598440
  L5987c9:;
  edx = 0;  // @180_598440
  L5987cb:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @182_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @183_598440
  PS[0] = edx;  // @184_598440
  reg.state = (s32)((u32)(1));  // @185_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @186_598440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @187_598440
  ecx = edx = 0;  // @188_598440
  eax = ext_41e290_cdecl1((u32)(264));  // @189_598440
  ecx = edx = 0;  // @190_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @191_598440
  reg.state = (s32)((u32)(8));  // @192_598440
  if ((eax & eax) == 0) goto L598815;  // @193_598440
  ecx = (u32)(esi + 8902);  // @194_598440
  PS[0] = ecx;  // @195_598440
  ecx = eax;  // @196_598440
  eax = ext_4d8330_thiscall4(ecx, (u32)(7001952), (u32)(7001932), (u32)(PS[0]));  // @197_598440
  ecx = edx = 0;  // @198_598440
  edx = eax;  // @199_598440
  goto L598817;  // @200_598440
  L598815:;
  edx = 0;  // @202_598440
  L598817:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 125), &v, sizeof v); }  // @204_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @205_598440
  PS[0] = edx;  // @206_598440
  reg.state = (s32)((u32)(1));  // @207_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @208_598440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @209_598440
  ecx = edx = 0;  // @210_598440
  eax = ext_41e290_cdecl1((u32)(264));  // @211_598440
  ecx = edx = 0;  // @212_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @213_598440
  reg.state = (s32)((u32)(9));  // @214_598440
  if ((eax & eax) == 0) goto L598861;  // @215_598440
  ecx = (u32)(esi + 8906);  // @216_598440
  PS[0] = ecx;  // @217_598440
  ecx = eax;  // @218_598440
  eax = ext_4d8330_thiscall4(ecx, (u32)(7001984), (u32)(7001960), (u32)(PS[0]));  // @219_598440
  ecx = edx = 0;  // @220_598440
  edx = eax;  // @221_598440
  goto L598863;  // @222_598440
  L598861:;
  edx = 0;  // @224_598440
  L598863:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 129), &v, sizeof v); }  // @226_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @227_598440
  PS[0] = edx;  // @228_598440
  reg.state = (s32)((u32)(1));  // @229_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @230_598440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @231_598440
  ecx = edx = 0;  // @232_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8902), &v, sizeof v); }  // @233_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8931), &v, sizeof v); }  // @234_598440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @235_598440
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 8906), &v, sizeof v); }  // @236_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @237_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @238_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @239_598440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6883888), (u32)(0), (u32)(7001988), (u32)(126));  // @240_598440
  ecx = edx = 0;  // @241_598440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 7467), &v, sizeof v); }  // @242_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @243_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @244_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @245_598440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6900844), (u32)(0), (u32)(7001988), (u32)(127));  // @246_598440
  ecx = edx = 0;  // @247_598440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 7469), &v, sizeof v); }  // @248_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @249_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @250_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @251_598440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6998032), (u32)(0), (u32)(7001988), (u32)(128));  // @252_598440
  ecx = edx = 0;  // @253_598440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 7471), &v, sizeof v); }  // @254_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @255_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @256_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @257_598440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7002036), (u32)(0), (u32)(7001988), (u32)(129));  // @258_598440
  ecx = edx = 0;  // @259_598440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 7473), &v, sizeof v); }  // @260_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @261_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @262_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @263_598440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7002052), (u32)(0), (u32)(7001988), (u32)(130));  // @264_598440
  ecx = edx = 0;  // @265_598440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 7475), &v, sizeof v); }  // @266_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @267_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @268_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @269_598440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7002068), (u32)(0), (u32)(7001988), (u32)(131));  // @270_598440
  ecx = edx = 0;  // @271_598440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 7477), &v, sizeof v); }  // @272_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @273_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @274_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @275_598440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7002084), (u32)(0), (u32)(7001988), (u32)(132));  // @276_598440
  ecx = edx = 0;  // @277_598440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 7479), &v, sizeof v); }  // @278_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @279_598440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @280_598440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @281_598440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7002100), (u32)(0), (u32)(7001988), (u32)(133));  // @282_598440
  ecx = edx = 0;  // @283_598440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 7481), &v, sizeof v); }  // @284_598440
  eax = ext_41e290_cdecl1((u32)(28));  // @285_598440
  ecx = edx = 0;  // @286_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @287_598440
  reg.state = (s32)((u32)(10));  // @288_598440
  if ((eax & eax) == 0) goto L598a2c;  // @289_598440
  ecx = eax;  // @290_598440
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(0));  // @291_598440
  ecx = edx = 0;  // @292_598440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @293_598440
  eax = esi;  // @294_598440
  SEH_LEAVE();  // @295_598440
  return eax;  // @296_598440
  L598a2c:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @298_598440
  eax = esi;  // @299_598440
  SEH_LEAVE();  // @300_598440
  return eax;  // @301_598440
}
PCREG(598440, lifted_598440);

