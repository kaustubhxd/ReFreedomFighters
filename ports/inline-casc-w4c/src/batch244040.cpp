// batch244040.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 ext_42aba4_cdecl3(...) __asm__("ext_42aba4");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4274a0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u32 nm_ = 0;
  SEH_ENTER(0x6646ed);  // @h_4274a0
  u8 F[0x19500] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x19400);
  u32 PV[67], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, ebxh = 0, edxh = 0, ecxh = 0, eaxh = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x19400 + 8, &a0, 4);
  __builtin_memcpy(F + 0x19400 + 12, &a1, 4);
  __builtin_memcpy(F + 0x19400 + 16, &a2, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 103332), &v, sizeof v); }  // @0_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4274a0
  ecx = (u32)(EBP - 102804);  // @2_4274a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4274a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_4274a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 103356), &v, sizeof v); }  // @5_4274a0
  eax = ext_4cbeb0_thiscall1(ecx);  // @6_4274a0
    // @7_4274a0
  PV[0] = (u32)(esi);  // @8_4274a0
  reg.state = (s32)((u32)(0));  // @9_4274a0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[0], (u32)(6786256));  // @10_4274a0
  ecx = edx = 0;  // @11_4274a0
  FL[2] = (eax & eax);  // @12_4274a0
  if (FL[2] != 0) goto L42755c;  // @13_4274a0
  eax = (u32)(EBP - 276);  // @14_4274a0
  PV[1] = (u32)(eax);  // @15_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_4274a0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2511), sizeof v); (u32)v; });  // @17_4274a0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67607c))(PV[2], PV[1], (u32)(260));  // @18_4274a0
  ecx = edx = 0;  // @19_4274a0
  eax = (u32)(EBP - 276);  // @20_4274a0
  PV[3] = (u32)(eax);  // @21_4274a0
  ecx = (u32)(EBP - 102932);  // @22_4274a0
  eax = ext_4cbe80_thiscall2(ecx, PV[3]);  // @23_4274a0
  ecx = edx = 0;  // @24_4274a0
  eax = (u32)(EBP - 102932);  // @25_4274a0
  reg.state = (s32)((u32)(1));  // @26_4274a0
  PV[4] = (u32)(eax);  // @27_4274a0
  ecx = (u32)(EBP - 102804);  // @28_4274a0
  eax = ext_4cbee0_thiscall2(ecx, PV[4]);  // @29_4274a0
  ecx = edx = 0;  // @30_4274a0
  ecx = (u32)(EBP - 102932);  // @31_4274a0
  goto L427620;  // @32_4274a0
  L42755c:;
  PV[5] = (u32)(esi);  // @34_4274a0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))(PV[5], (u32)(92));  // @35_4274a0
  ecx = edx = 0;  // @36_4274a0
  ecx = (u32)(EBP - 103060);  // @37_4274a0
  PV[6] = (u32)(esi);  // @38_4274a0
  FL[2] = (eax & eax);  // @39_4274a0
  if (FL[2] != 0) goto L4275ff;  // @40_4274a0
  eax = ext_4cbe80_thiscall2(ecx, PV[6]);  // @41_4274a0
  ecx = edx = 0;  // @42_4274a0
  ecx = (u32)(EBP - 102932);  // @43_4274a0
  reg.state = (s32)((u32)(2));  // @44_4274a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @45_4274a0
  ecx = edx = 0;  // @46_4274a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_4274a0
  eax = (u32)(EBP - 102932);  // @48_4274a0
  PV[7] = (u32)(eax);  // @49_4274a0
  eax = (u32)(EBP - 103316);  // @50_4274a0
  reg.state = (s32)((u32)(3));  // @51_4274a0
  PV[8] = (u32)(eax);  // @52_4274a0
  ecx = (u32)(ecx + 163);  // @53_4274a0
  eax = ext_4cc1e0_thiscall3(ecx, PV[8], PV[7]);  // @54_4274a0
  ecx = edx = 0;  // @55_4274a0
  ecx = (u32)(EBP - 103060);  // @56_4274a0
  reg.state = (s32)((u32)(4));  // @57_4274a0
  PV[9] = (u32)(ecx);  // @58_4274a0
  ecx = (u32)(EBP - 103188);  // @59_4274a0
  PV[10] = (u32)(ecx);  // @60_4274a0
  ecx = eax;  // @61_4274a0
  eax = ext_4cc1e0_thiscall3(ecx, PV[10], PV[9]);  // @62_4274a0
  ecx = edx = 0;  // @63_4274a0
  PV[11] = (u32)(eax);  // @64_4274a0
  ecx = (u32)(EBP - 102804);  // @65_4274a0
  reg.state = (s32)((u32)(5));  // @66_4274a0
  eax = ext_4cbee0_thiscall2(ecx, PV[11]);  // @67_4274a0
  ecx = edx = 0;  // @68_4274a0
  ecx = (u32)(EBP - 103188);  // @69_4274a0
  eax = ext_4cbec0_thiscall1(ecx);  // @70_4274a0
  ecx = edx = 0;  // @71_4274a0
  ecx = (u32)(EBP - 103316);  // @72_4274a0
  eax = ext_4cbec0_thiscall1(ecx);  // @73_4274a0
  ecx = edx = 0;  // @74_4274a0
  ecx = (u32)(EBP - 102932);  // @75_4274a0
  eax = ext_4cbec0_thiscall1(ecx);  // @76_4274a0
  ecx = edx = 0;  // @77_4274a0
  goto L42761a;  // @78_4274a0
  L4275ff:;
  eax = ext_4cbe80_thiscall2(ecx, PV[6]);  // @80_4274a0
  ecx = edx = 0;  // @81_4274a0
  eax = (u32)(EBP - 103060);  // @82_4274a0
  reg.state = (s32)((u32)(6));  // @83_4274a0
  PV[12] = (u32)(eax);  // @84_4274a0
  ecx = (u32)(EBP - 102804);  // @85_4274a0
  eax = ext_4cbee0_thiscall2(ecx, PV[12]);  // @86_4274a0
  ecx = edx = 0;  // @87_4274a0
  L42761a:;
  ecx = (u32)(EBP - 103060);  // @89_4274a0
  L427620:;
  reg.state = (s32)((u32)(0));  // @91_4274a0
  eax = ext_4cbec0_thiscall1(ecx);  // @92_4274a0
  ecx = edx = 0;  // @93_4274a0
  ecx = (u32)(EBP - 102804);  // @94_4274a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @95_4274a0
    // @96_4274a0
  PV[13] = (u32)(eax);  // @97_4274a0
  eax = ((u32(*)(u32, u32))(*(u32 *)0x6763b0))(PV[13], (u32)(6786252));  // @98_4274a0
  ecx = edx = 0;  // @99_4274a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775784), sizeof v); (u32)v; });  // @100_4274a0
  esi = eax;  // @101_4274a0
  PV[14] = (u32)(esi);  // @102_4274a0
  eax = ((u32(*)(u32, u32, u32))(edi))(PV[14], (u32)(60), (u32)(0));  // @103_4274a0
  ecx = edx = 0;  // @104_4274a0
  PV[15] = (u32)(esi);  // @105_4274a0
  eax = (u32)(EBP - 103320);  // @106_4274a0
  PV[16] = (u32)(eax);  // @107_4274a0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[16], (u32)(1), (u32)(4), PV[15]);  // @108_4274a0
  ecx = edx = 0;  // @109_4274a0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103320), sizeof v); (u32)v; });  // @110_4274a0
  PV[18] = (u32)(esi);  // @111_4274a0
  eax = ((u32(*)(u32, u32, u32))(edi))(PV[18], PV[17], (u32)(0));  // @112_4274a0
  ecx = edx = 0;  // @113_4274a0
  PV[19] = (u32)(esi);  // @114_4274a0
  eax = (u32)(EBP - 103352);  // @115_4274a0
  PV[20] = (u32)(eax);  // @116_4274a0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[20], (u32)(1), (u32)(4), PV[19]);  // @117_4274a0
  ecx = edx = 0;  // @118_4274a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103352), sizeof v); (u32)v; }); FL[1] = (u32)(17744);  // @119_4274a0
  if (FL[0] != FL[1]) goto L4278cb;  // @120_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103320), sizeof v); (u32)v; });  // @121_4274a0
  eax = (eax + (u32)(20));  // @122_4274a0
  FL[3] = eax;  // @123_4274a0
  PV[21] = (u32)(eax);  // @124_4274a0
  PV[22] = (u32)(esi);  // @125_4274a0
  eax = ((u32(*)(u32, u32, u32))(edi))(PV[22], PV[21], (u32)(0));  // @126_4274a0
  ecx = edx = 0;  // @127_4274a0
  PV[23] = (u32)(esi);  // @128_4274a0
  eax = (u32)(EBP - 103328);  // @129_4274a0
  PV[24] = (u32)(eax);  // @130_4274a0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[24], (u32)(1), (u32)(2), PV[23]);  // @131_4274a0
  ecx = edx = 0;  // @132_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103320), sizeof v); (u32)v; });  // @133_4274a0
  eax = (eax + (u32)(24));  // @134_4274a0
  FL[3] = eax;  // @135_4274a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 103320), &v, sizeof v); }  // @136_4274a0
  eax = (eax + (u32)(96));  // @137_4274a0
  FL[3] = eax;  // @138_4274a0
  PV[25] = (u32)(eax);  // @139_4274a0
  PV[26] = (u32)(esi);  // @140_4274a0
  eax = ((u32(*)(u32, u32, u32))(edi))(PV[26], PV[25], (u32)(0));  // @141_4274a0
  ecx = edx = 0;  // @142_4274a0
  PV[27] = (u32)(esi);  // @143_4274a0
  eax = (u32)(EBP - 103324);  // @144_4274a0
  PV[28] = (u32)(eax);  // @145_4274a0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[28], (u32)(1), (u32)(4), PV[27]);  // @146_4274a0
  ecx = edx = 0;  // @147_4274a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103324), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @148_4274a0
  if (FL[0] != FL[1]) goto L4276f0;  // @149_4274a0
  eax = ((u32( *)(u32))(*(u32 *)0x676374))((u32)(0));  // @150_4274a0
  ecx = edx = 0;  // @151_4274a0
  L4276f0:;
  PV[29] = (u32)(esi);  // @153_4274a0
  eax = (u32)(EBP - 103360);  // @154_4274a0
  PV[30] = (u32)(eax);  // @155_4274a0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[30], (u32)(1), (u32)(4), PV[29]);  // @156_4274a0
  ecx = edx = 0;  // @157_4274a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103332), sizeof v); (u32)v; });  // @158_4274a0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103328), sizeof v); (u32)v; });  // @159_4274a0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103320), sizeof v); (u32)v; }));  // @160_4274a0
  FL[3] = edx;  // @161_4274a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 103340), &v, sizeof v); }  // @162_4274a0
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103324), sizeof v); (u32)v; });  // @163_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_4274a0
  PV[32] = (u32)(edx);  // @165_4274a0
  PV[33] = (u32)(esi);  // @166_4274a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, PV[33], PV[32], PV[31]);  // @167_4274a0
  ecx = edx = 0;  // @168_4274a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 103324), &v, sizeof v); }  // @169_4274a0
  eax = (eax + (u32)(24));  // @170_4274a0
  FL[3] = eax;  // @171_4274a0
  PV[34] = (u32)(eax);  // @172_4274a0
  PV[35] = (u32)(esi);  // @173_4274a0
  eax = ((u32(*)(u32, u32, u32))(edi))(PV[35], PV[34], (u32)(0));  // @174_4274a0
  ecx = edx = 0;  // @175_4274a0
  PV[36] = (u32)(esi);  // @176_4274a0
  eax = (u32)(EBP - 103348);  // @177_4274a0
  PV[37] = (u32)(eax);  // @178_4274a0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[37], (u32)(1), (u32)(4), PV[36]);  // @179_4274a0
  ecx = edx = 0;  // @180_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103324), sizeof v); (u32)v; });  // @181_4274a0
  eax = (eax + (u32)(32));  // @182_4274a0
  FL[3] = eax;  // @183_4274a0
  PV[38] = (u32)(eax);  // @184_4274a0
  PV[39] = (u32)(esi);  // @185_4274a0
  eax = ((u32(*)(u32, u32, u32))(edi))(PV[39], PV[38], (u32)(0));  // @186_4274a0
  ecx = edx = 0;  // @187_4274a0
  PV[40] = (u32)(esi);  // @188_4274a0
  eax = (u32)(EBP - 103336);  // @189_4274a0
  PV[41] = (u32)(eax);  // @190_4274a0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[41], (u32)(1), (u32)(4), PV[40]);  // @191_4274a0
  ecx = edx = 0;  // @192_4274a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103332), sizeof v); (u32)v; });  // @193_4274a0
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103336), sizeof v); (u32)v; });  // @194_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @195_4274a0
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103340), sizeof v); (u32)v; });  // @196_4274a0
  PV[44] = (u32)(esi);  // @197_4274a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, PV[44], PV[43], PV[42]);  // @198_4274a0
  ecx = edx = 0;  // @199_4274a0
  edi = 0;  // @200_4274a0
  FL[3] = edi;  // @201_4274a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 103336), &v, sizeof v); }  // @202_4274a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103348), sizeof v); (u32)v; }); FL[1] = edi;  // @203_4274a0
  if (FL[0] <= FL[1]) goto L4278cb;  // @204_4274a0
  L4277a2:;
  eax = (u32)(eax + edi*4);  // @206_4274a0
  PV[45] = (u32)(eax);  // @207_4274a0
  PV[46] = (u32)(esi);  // @208_4274a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6763e8))(PV[46], PV[45], (u32)(0));  // @209_4274a0
  ecx = edx = 0;  // @210_4274a0
  PV[47] = (u32)(esi);  // @211_4274a0
  eax = (u32)(EBP - 103344);  // @212_4274a0
  PV[48] = (u32)(eax);  // @213_4274a0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[48], (u32)(1), (u32)(4), PV[47]);  // @214_4274a0
  ecx = edx = 0;  // @215_4274a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103332), sizeof v); (u32)v; });  // @216_4274a0
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103344), sizeof v); (u32)v; });  // @217_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @218_4274a0
  PV[50] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103340), sizeof v); (u32)v; });  // @219_4274a0
  PV[51] = (u32)(esi);  // @220_4274a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, PV[51], PV[50], PV[49]);  // @221_4274a0
  ecx = edx = 0;  // @222_4274a0
  PV[52] = (u32)(eax);  // @223_4274a0
  PV[53] = (u32)(esi);  // @224_4274a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 103344), &v, sizeof v); }  // @225_4274a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6763e8))(PV[53], PV[52], (u32)(0));  // @226_4274a0
  ecx = edx = 0;  // @227_4274a0
  eax = (u32)(EBP - 102676);  // @228_4274a0
  PV[54] = (u32)(eax);  // @229_4274a0
  PV[55] = (u32)(esi);  // @230_4274a0
  eax = ext_42aba4_cdecl3(PV[55], (u32)(6779752), PV[54]);  // @231_4274a0
  ecx = edx = 0;  // @232_4274a0
  eax = (u32)(EBP - 102676);  // @233_4274a0
  PV[56] = (u32)(eax);  // @234_4274a0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))(PV[56], (u32)(64));  // @235_4274a0
  ecx = edx = 0;  // @236_4274a0
  FL[2] = (eax & eax);  // @237_4274a0
  if (FL[2] == 0) goto L42784b;  // @238_4274a0
  ecx = eax;  // @239_4274a0
  edx = (u32)(EBP - 102676);  // @240_4274a0
  ecx = (ecx - edx);  // @241_4274a0
  FL[3] = ecx;  // @242_4274a0
  FL[0] = ecx; FL[1] = (u32)(10);  // @243_4274a0
  if ((s32)FL[0] <= (s32)FL[1]) goto L42784b;  // @244_4274a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 10), sizeof v); (u32)v; }); FL[1] = (u32)(1634485087);  // @245_4274a0
  if (FL[0] != FL[1]) goto L42784b;  // @246_4274a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 6), sizeof v); (u32)v; }); FL[1] = (u32)(1850307443);  // @247_4274a0
  if (FL[0] != FL[1]) goto L42784b;  // @248_4274a0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax - 2), sizeof v); (u32)v; }); FL[1] = (u32)(28518);  // @249_4274a0
  if (FL[0] != FL[1]) goto L42784b;  // @250_4274a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103356), sizeof v); (u32)v; });  // @251_4274a0
  PV[57] = (u32)(edx);  // @252_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @253_4274a0
  nm_ = PV[57]; goto L4278b4;  // @254_4274a0
  L42784b:;
  FL[2] = (ebx & ebx);  // @256_4274a0
  if (FL[2] == 0) goto L4278b7;  // @257_4274a0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 102676), sizeof v); (u32)v; }); FL[1] = (u32)(63);  // @258_4274a0
  if (FL[0] == FL[1]) goto L4278b7;  // @259_4274a0
  eax = (u32)(EBP - 102676);  // @260_4274a0
  edx = (u32)(eax + 1);  // @261_4274a0
  L427861:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @263_4274a0
  eax = (eax + 1);  // @264_4274a0
  FL[3] = eax;  // @265_4274a0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @266_4274a0
  if (FL[2] != 0) goto L427861;  // @267_4274a0
  eax = (eax - edx);  // @268_4274a0
  FL[3] = eax;  // @269_4274a0
  FL[0] = eax; FL[1] = (u32)(8);  // @270_4274a0
  if ((s32)FL[0] < (s32)FL[1]) goto L4278b7;  // @271_4274a0
  ecx = (u32)(6786268);  // @272_4274a0
  eax = (u32)(EBP + eax - 102684);  // @273_4274a0
  L427880:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @275_4274a0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @276_4274a0
  if (FL[0] != FL[1]) goto L4278a0;  // @277_4274a0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @278_4274a0
  if (FL[2] == 0) goto L42789c;  // @279_4274a0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @280_4274a0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @281_4274a0
  if (FL[0] != FL[1]) goto L4278a0;  // @282_4274a0
  eax = (eax + (u32)(2));  // @283_4274a0
  FL[3] = eax;  // @284_4274a0
  ecx = (ecx + (u32)(2));  // @285_4274a0
  FL[3] = ecx;  // @286_4274a0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @287_4274a0
  if (FL[2] != 0) goto L427880;  // @288_4274a0
  L42789c:;
  eax = 0;  // @290_4274a0
  FL[3] = eax;  // @291_4274a0
  goto L4278a5;  // @292_4274a0
  L4278a0:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @294_4274a0
  eax = (eax | (u32)(1));  // @295_4274a0
  FL[3] = eax;  // @296_4274a0
  L4278a5:;
  FL[2] = (eax & eax);  // @298_4274a0
  if (FL[2] != 0) goto L4278b7;  // @299_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @300_4274a0
  ecx = (u32)(EBP - 102676);  // @301_4274a0
  PV[58] = (u32)(ecx); nm_ = PV[58];  // @302_4274a0
  ecx = ebx;  // @303_4274a0
  L4278b4:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, nm_);  // @305_4274a0
  ecx = edx = 0;  // @306_4274a0
  L4278b7:;
  edi = (edi + 1);  // @308_4274a0
  FL[3] = edi;  // @309_4274a0
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103348), sizeof v); (u32)v; });  // @310_4274a0
  if (FL[0] >= FL[1]) goto L4278cb;  // @311_4274a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 103336), sizeof v); (u32)v; });  // @312_4274a0
  goto L4277a2;  // @313_4274a0
  L4278cb:;
  PV[59] = (u32)(esi);  // @315_4274a0
  eax = ((u32( *)(u32))(*(u32 *)0x6763ac))(PV[59]);  // @316_4274a0
  ecx = edx = 0;  // @317_4274a0
  ecx = (u32)(EBP - 102804);  // @318_4274a0
  eax = ext_4cbec0_thiscall1(ecx);  // @319_4274a0
  ecx = edx = 0;  // @320_4274a0
  SEH_LEAVE();  // @321_4274a0
  ext_633654(G(u32, 0x6f5630));  // @322_4274a0
  return eax;  // @323_4274a0
}
PCREG(4274a0, lifted_4274a0);

