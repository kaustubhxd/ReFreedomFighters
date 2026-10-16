// batch220009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_61c660_cdecl5(...) __asm__("ext_61c660");
extern "C" u32 ext_61c790_cdecl6(...) __asm__("ext_61c790");
extern "C" u32 ext_61f5a0_cdecl4(...) __asm__("ext_61f5a0");
extern "C" u32 ext_61fd60_cdecl3(...) __asm__("ext_61fd60");
extern "C" u32 ext_6204f0_cdecl2(...) __asm__("ext_6204f0");
extern "C" u32 ext_6206e0_cdecl1(...) __asm__("ext_6206e0");
extern "C" u32 ext_620840_cdecl4(...) __asm__("ext_620840");
extern "C" u32 ext_6210c0_cdecl2(...) __asm__("ext_6210c0");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_621230(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 STK[61];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_621230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_621230
  ebx = 0;  // @2_621230
  edi = 0;  // @3_621230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @4_621230
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_621230
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_621230
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @7_621230
  if ((eax & eax) == 0) goto L6212cb;  // @8_621230
  STK[0] = ebx;  // @9_621230
  STK[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_621230
  edi = (u32)(esi + 364);  // @11_621230
  STK[2] = edi;  // @12_621230
  eax = ext_61fd60_cdecl3(STK[2], STK[1], STK[0]);  // @13_621230
  ecx = edx = 0;  // @14_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @15_621230
  if ((eax & eax) != 0) goto L6212c5;  // @16_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @17_621230
  STK[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_621230
  eax = (u32)(esi + 424);  // @19_621230
  STK[4] = eax;  // @20_621230
  eax = ext_6204f0_cdecl2(STK[4], STK[3]);  // @21_621230
  ecx = edx = 0;  // @22_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @23_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @24_621230
  if ((eax & eax) != 0) goto L621299;  // @25_621230
  L62128d:;
  eax = (u32)(1);  // @27_621230
  return eax;  // @28_621230
  L621299:;
  STK[5] = (u32)(24);  // @30_621230
  STK[6] = eax;  // @31_621230
  STK[7] = edi;  // @32_621230
  eax = ext_61fd60_cdecl3(STK[7], STK[6], STK[5]);  // @33_621230
  ecx = edx = 0;  // @34_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @35_621230
  if ((eax & eax) == 0) goto L62128d;  // @36_621230
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 232), sizeof v); (u32)v; }) == ebx) goto L6212c5;  // @37_621230
  STK[8] = eax;  // @38_621230
  STK[9] = esi;  // @39_621230
  eax = ext_6210c0_cdecl2(STK[9], STK[8]);  // @40_621230
  ecx = edx = 0;  // @41_621230
  if ((eax & eax) == 0) goto L62128d;  // @42_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @43_621230
  L6212c5:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @45_621230
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @46_621230
  L6212cb:;
  STK[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; });  // @48_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @49_621230
  STK[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 532), sizeof v); (u32)v; });  // @50_621230
  STK[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @51_621230
  STK[13] = eax;  // @52_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; });  // @53_621230
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(eax))(STK[13], STK[12], STK[11], STK[10]);  // @54_621230
  ecx = edx = 0;  // @55_621230
  ecx = eax;  // @56_621230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @57_621230
  ecx = (ecx + edi);  // @58_621230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 532), sizeof v); (u32)v; });  // @59_621230
  if ((s32)ecx <= (s32)edi) goto L621338;  // @60_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @61_621230
  ecx = (ecx + (u32)(16));  // @62_621230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 532), &v, sizeof v); }  // @63_621230
  ecx = (ecx << (u32)(4));  // @64_621230
  STK[14] = ecx;  // @65_621230
  STK[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; });  // @66_621230
  eax = ((u32( *)(u32, u32))(eax))(STK[15], STK[14]);  // @67_621230
  ecx = edx = 0;  // @68_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 544), &v, sizeof v); }  // @69_621230
  if ((eax & eax) == 0) goto L62128d;  // @70_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @71_621230
  if ((s32)ecx <= (s32)edi) goto L621338;  // @72_621230
  STK[16] = eax;  // @73_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @74_621230
  STK[17] = ecx;  // @75_621230
  STK[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @76_621230
  STK[19] = eax;  // @77_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; });  // @78_621230
  eax = ((u32( *)(u32, u32, u32, u32))(eax))(STK[19], STK[18], STK[17], STK[16]);  // @79_621230
  ecx = edx = 0;  // @80_621230
  L621338:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; });  // @82_621230
  ecx = 0;  // @83_621230
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @84_621230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @85_621230
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }) <= (s32)ecx) goto L621510;  // @86_621230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @87_621230
  L621352:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; });  // @89_621230
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @90_621230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @91_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @92_621230
  STK[20] = edi;  // @93_621230
  STK[21] = eax;  // @94_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @95_621230
  eax = ((u32(STDCALL *)(u32, u32))(eax))(STK[21], STK[20]);  // @96_621230
  ecx = edx = 0;  // @97_621230
  eax = (eax + edi);  // @98_621230
  STK[22] = eax;  // @99_621230
  STK[23] = edi;  // @100_621230
  STK[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @101_621230
  STK[25] = esi;  // @102_621230
  eax = ext_61f5a0_cdecl4(STK[25], STK[24], STK[23], STK[22]);  // @103_621230
  ecx = edx = 0;  // @104_621230
  edi = eax;  // @105_621230
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @106_621230
  if ((edi & edi) == 0) goto L62128d;  // @107_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @108_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax - 1), sizeof v); (u32)v; }) != (u32)(0)) goto L621546;  // @109_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @110_621230
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax - 1), &v, sizeof v); }  // @111_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @112_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*4), &v, sizeof v); }  // @113_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; });  // @114_621230
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @115_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @116_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L621473;  // @117_621230
  edx = (u32)(1);  // @118_621230
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @119_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L6213f3;  // @120_621230
  ecx = 0;  // @121_621230
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }) <= (s32)ecx) goto L6213f3;  // @122_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @123_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @124_621230
  L6213d0:;
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L6213df;  // @126_621230
  ecx = (ecx + 1);  // @127_621230
  eax = (eax + (u32)(12));  // @128_621230
  if ((s32)ecx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; })) goto L6213d0;  // @129_621230
  goto L6213f0;  // @130_621230
  L6213df:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @132_621230
  eax = (u32)(ecx + ecx*2);  // @133_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @134_621230
  edx = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4 + 4), sizeof v); (u32)v; }));  // @135_621230
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @136_621230
  L6213f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @138_621230
  L6213f3:;
  edi = (u32)(esi + 556);  // @140_621230
  STK[26] = edi;  // @141_621230
  STK[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @142_621230
  STK[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @143_621230
  STK[29] = edx;  // @144_621230
  STK[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @145_621230
  STK[31] = esi;  // @146_621230
  eax = ext_61c790_cdecl6(STK[31], STK[30], STK[29], STK[28], STK[27], STK[26]);  // @147_621230
  ecx = edx = 0;  // @148_621230
  if ((eax & eax) != 0) goto L6218b5;  // @149_621230
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }) != eax) goto L621430;  // @150_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @151_621230
  eax = ecx;  // @152_621230
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }));  // @153_621230
  if (eax == 0) goto L621430;  // @154_621230
  eax = (u32)(ecx - 1);  // @155_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 1), sizeof v); (u32)v; }) != (u32)(32)) goto L621430;  // @156_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @157_621230
  L621430:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @159_621230
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L621449;  // @160_621230
  STK[32] = edi;  // @161_621230
  eax = ext_6206e0_cdecl1(STK[32]);  // @162_621230
  ecx = edx = 0;  // @163_621230
  if ((eax & eax) == 0) goto L62128d;  // @164_621230
  L621449:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @166_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @167_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @168_621230
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @169_621230
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @170_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 572), sizeof v); (u32)v; });  // @171_621230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @172_621230
  if ((edx & edx) == 0) goto L62146b;  // @173_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*4 + 4), &v, sizeof v); }  // @174_621230
  goto L6214a4;  // @175_621230
  L62146b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @177_621230
  goto L6214b0;  // @178_621230
  L621473:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @180_621230
  if ((edx & edx) == 0) goto L6214b0;  // @181_621230
  STK[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @182_621230
  STK[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @183_621230
  eax = (u32)(esi + 556);  // @184_621230
  STK[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @185_621230
  STK[36] = eax;  // @186_621230
  eax = ext_620840_cdecl4(STK[36], STK[35], STK[34], STK[33]);  // @187_621230
  ecx = edx = 0;  // @188_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @189_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*4 + 4), &v, sizeof v); }  // @190_621230
  if ((eax & eax) == 0) goto L62128d;  // @191_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @192_621230
  L6214a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @194_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @195_621230
  L6214b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @197_621230
  if ((eax & eax) == 0) goto L6214ee;  // @198_621230
  if ((edx & edx) == 0) goto L6214ee;  // @199_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9), sizeof v); (u32)v; }) == (u32)(0)) goto L6214e0;  // @200_621230
  STK[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @201_621230
  STK[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*4 + 4), sizeof v); (u32)v; });  // @202_621230
  STK[39] = edi;  // @203_621230
  STK[40] = eax;  // @204_621230
  STK[41] = esi;  // @205_621230
  eax = ext_61c660_cdecl5(STK[41], STK[40], STK[39], STK[38], STK[37]);  // @206_621230
  ecx = edx = 0;  // @207_621230
  if ((eax & eax) == 0) goto L62128d;  // @208_621230
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @209_621230
  goto L6214f1;  // @210_621230
  L6214e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @212_621230
  ebx = (ebx + (u32)(2));  // @213_621230
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @214_621230
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(eax - 1), &v, sizeof v); }  // @215_621230
  goto L6214f1;  // @216_621230
  L6214ee:;
  ebx = (ebx + (u32)(2));  // @218_621230
  L6214f1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @220_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @221_621230
  eax = (eax + 1);  // @222_621230
  ecx = (ecx + (u32)(16));  // @223_621230
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @224_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @225_621230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @226_621230
  if ((s32)eax < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; })) goto L621352;  // @227_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @228_621230
  L621510:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L621618;  // @230_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @231_621230
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 536), &v, sizeof v); }  // @232_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @233_621230
  if ((ecx & ecx) == 0) goto L621579;  // @234_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @235_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 1), sizeof v); (u32)v; }) == (u32)(0)) goto L621579;  // @236_621230
  eax = 0;  // @237_621230
  if ((s32)(ebx & ebx) <= 0) goto L621583;  // @238_621230
  L621538:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; }) == ecx) goto L621571;  // @240_621230
  eax = (eax + (u32)(2));  // @241_621230
  if ((s32)eax < (s32)ebx) goto L621538;  // @242_621230
  goto L621583;  // @243_621230
  L621546:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @245_621230
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; })) goto L621565;  // @246_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @247_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; });  // @248_621230
  ecx = (ecx + ecx);  // @249_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8), sizeof v); (u32)v; });  // @250_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 280), &v, sizeof v); }  // @251_621230
  L621565:;
  eax = (u32)(8);  // @253_621230
  return eax;  // @254_621230
  L621571:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 540), &v, sizeof v); }  // @256_621230
  goto L621583;  // @257_621230
  L621579:;
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 540), &v, sizeof v); }  // @259_621230
  L621583:;
  edi = 0;  // @261_621230
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }) <= (s32)edi) goto L621611;  // @262_621230
  eax = 0;  // @263_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @264_621230
  L621593:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @266_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @267_621230
  ecx = (ecx + eax);  // @268_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @269_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @270_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx - 1), sizeof v); (u32)v; }) != (u32)(0)) goto L6215ff;  // @271_621230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @272_621230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @273_621230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @274_621230
  if ((esi & esi) == 0) goto L6215ff;  // @275_621230
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L6215e4;  // @276_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; }) == (u32)(0)) goto L6215db;  // @277_621230
  STK[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @278_621230
  STK[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @279_621230
  STK[44] = eax;  // @280_621230
  STK[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @281_621230
  STK[46] = esi;  // @282_621230
  eax = ext_61c660_cdecl5(STK[46], STK[45], STK[44], STK[43], STK[42]);  // @283_621230
  ecx = edx = 0;  // @284_621230
  if ((eax & eax) == 0) goto L62128d;  // @285_621230
  goto L6215ff;  // @286_621230
  L6215db:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @288_621230
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edx - 1), &v, sizeof v); }  // @289_621230
  goto L6215e8;  // @290_621230
  L6215e4:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edx - 1), &v, sizeof v); }  // @292_621230
  L6215e8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @294_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @295_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @296_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ebx*4), &v, sizeof v); }  // @297_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @298_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ebx*4 + 4), &v, sizeof v); }  // @299_621230
  ebx = (ebx + (u32)(2));  // @300_621230
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @301_621230
  L6215ff:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @303_621230
  edi = (edi + 1);  // @304_621230
  eax = (eax + (u32)(12));  // @305_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @306_621230
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; })) goto L621593;  // @307_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @308_621230
  L621611:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + ebx*4), &v, sizeof v); }  // @310_621230
  L621618:;
  edi = 0;  // @312_621230
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @313_621230
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == edi) goto L6217a4;  // @314_621230
  if ((s32)(ebx & ebx) <= 0) goto L6217be;  // @315_621230
  L621630:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi*4), sizeof v); (u32)v; });  // @317_621230
  ecx = (u32)(edx + edi*4);  // @318_621230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @319_621230
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 1), &v, sizeof v); }  // @320_621230
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax - 1), sizeof v); (u32)v; }) != (u32)(2)) goto L621794;  // @321_621230
  STK[47] = (u32)(0);  // @322_621230
  STK[48] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @323_621230
  eax = (u32)(esi + 384);  // @324_621230
  STK[49] = eax;  // @325_621230
  eax = ext_61fd60_cdecl3(STK[49], STK[48], STK[47]);  // @326_621230
  ecx = edx = 0;  // @327_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @328_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @329_621230
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @330_621230
  if ((edx & edx) == 0) goto L62178b;  // @331_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @332_621230
  ebx = 0;  // @333_621230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @334_621230
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) <= (s32)ebx) goto L6216c2;  // @335_621230
  L621680:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @337_621230
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; })) goto L6216a8;  // @338_621230
  eax = (u32)(esi + 556);  // @339_621230
  STK[50] = eax;  // @340_621230
  eax = ext_6206e0_cdecl1(STK[50]);  // @341_621230
  ecx = edx = 0;  // @342_621230
  if ((eax & eax) == 0) goto L62128d;  // @343_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @344_621230
  L6216a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @346_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @347_621230
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + eax), sizeof v); (u32)v; })) & 0xff);  // @348_621230
  ebx = (ebx + 1);  // @349_621230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @350_621230
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @351_621230
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; })) goto L621680;  // @352_621230
  L6216c2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @354_621230
  edi = (edi + 1);  // @355_621230
  if ((eax & 0xff) != (u32)(58)) goto L6216c2;  // @356_621230
  L6216d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @358_621230
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; })) goto L6216f5;  // @359_621230
  eax = (u32)(esi + 556);  // @360_621230
  STK[51] = eax;  // @361_621230
  eax = ext_6206e0_cdecl1(STK[51]);  // @362_621230
  ecx = edx = 0;  // @363_621230
  if ((eax & eax) == 0) goto L62128d;  // @364_621230
  L6216f5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @366_621230
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @367_621230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @368_621230
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @369_621230
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @370_621230
  edi = (edi + 1);  // @371_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @372_621230
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6216d0;  // @373_621230
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 236), sizeof v); (u32)v; }) == (u32)(0)) goto L62176e;  // @374_621230
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 616), sizeof v); (u32)v; })) & 0xff);  // @375_621230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx - 1), &v, sizeof v); }  // @376_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @377_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @378_621230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @379_621230
  L621730:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @381_621230
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; })) goto L621755;  // @382_621230
  eax = (u32)(esi + 556);  // @383_621230
  STK[52] = eax;  // @384_621230
  eax = ext_6206e0_cdecl1(STK[52]);  // @385_621230
  ecx = edx = 0;  // @386_621230
  if ((eax & eax) == 0) goto L62128d;  // @387_621230
  L621755:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @389_621230
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @390_621230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @391_621230
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @392_621230
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @393_621230
  edi = (edi + 1);  // @394_621230
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L621730;  // @395_621230
  L62176e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @397_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 572), sizeof v); (u32)v; });  // @398_621230
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @399_621230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @400_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @401_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @402_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @403_621230
  L62178b:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @405_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @406_621230
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == 0) goto L6217a4;  // @407_621230
  L621794:;
  edi = (edi + (u32)(2));  // @409_621230
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @410_621230
  if ((s32)edi < (s32)ebx) goto L621630;  // @411_621230
  goto L6217be;  // @412_621230
  L6217a4:;
  if ((s32)edi >= (s32)ebx) goto L6217be;  // @414_621230
  L6217b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi*4), sizeof v); (u32)v; });  // @416_621230
  edi = (edi + (u32)(2));  // @417_621230
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 1), &v, sizeof v); }  // @418_621230
  if ((s32)edi < (s32)ebx) goto L6217b0;  // @419_621230
  L6217be:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @421_621230
  if ((edx & edx) == 0) goto L6218b3;  // @422_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @423_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @424_621230
  if ((ecx & ecx) == 0) goto L6217e2;  // @425_621230
  L6217d2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @427_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @428_621230
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 1), &v, sizeof v); }  // @429_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @430_621230
  if ((ecx & ecx) != 0) goto L6217d2;  // @431_621230
  L6217e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @433_621230
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @434_621230
  if ((ebx & ebx) == 0) goto L621809;  // @435_621230
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @436_621230
  if ((ebx & ebx) == 0) goto L6218b3;  // @437_621230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @438_621230
  L621800:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @440_621230
  edi = (edi + 1);  // @441_621230
  if ((eax & 0xff) != (u32)(58)) goto L621800;  // @442_621230
  goto L621819;  // @443_621230
  L621809:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 480), sizeof v); (u32)v; });  // @445_621230
  if ((ebx & ebx) == 0) goto L6218b3;  // @446_621230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @447_621230
  L621819:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @449_621230
  ecx = 0;  // @450_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @451_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @452_621230
  L621824:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx), sizeof v); (u32)v; })) & 0xff);  // @454_621230
  ecx = (ecx + 1);  // @455_621230
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L621824;  // @456_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @457_621230
  eax = (eax + ecx);  // @458_621230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @459_621230
  if ((s32)eax <= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; })) goto L62189a;  // @460_621230
  eax = (eax + (u32)(24));  // @461_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @462_621230
  STK[53] = eax;  // @463_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @464_621230
  eax = ((u32( *)(u32))(eax))(STK[53]);  // @465_621230
  ecx = edx = 0;  // @466_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @467_621230
  if ((eax & eax) == 0) goto L62128d;  // @468_621230
  STK[54] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @469_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @470_621230
  STK[55] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @471_621230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @472_621230
  STK[56] = eax;  // @473_621230
  eax = ext_634d22_cdecl3(STK[56], STK[55], STK[54]);  // @474_621230
  ecx = edx = 0;  // @475_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 516), sizeof v); (u32)v; });  // @476_621230
  if ((ecx & ecx) == 0) goto L621886;  // @477_621230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @478_621230
  L621875:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @480_621230
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; })) goto L621880;  // @481_621230
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @482_621230
  L621880:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @484_621230
  if ((ecx & ecx) != 0) goto L621875;  // @485_621230
  L621886:;
  STK[57] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @487_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @488_621230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, STK[57]);  // @489_621230
  ecx = edx = 0;  // @490_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @491_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @492_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 16), &v, sizeof v); }  // @493_621230
  L62189a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @495_621230
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; }));  // @496_621230
  STK[58] = ecx;  // @497_621230
  STK[59] = edi;  // @498_621230
  STK[60] = eax;  // @499_621230
  eax = ext_634d22_cdecl3(STK[60], STK[59], STK[58]);  // @500_621230
  ecx = edx = 0;  // @501_621230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @502_621230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @503_621230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @504_621230
  L6218b3:;
  eax = 0;  // @506_621230
  L6218b5:;
  return eax;  // @508_621230
}
PCREG(621230, lifted_621230);

