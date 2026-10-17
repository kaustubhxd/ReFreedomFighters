// batch244035.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_655510(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_655510
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_655510
  esi = ecx;  // @2_655510
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_655510
  FL[0] = eax; FL[1] = (u32)(256);  // @4_655510
  if (FL[0] > FL[1]) goto L6555fa;  // @5_655510
  if (FL[0] == FL[1]) goto L65561c;  // @6_655510
  eax = (eax - 1);  // @7_655510
  FL[3] = eax;  // @8_655510
  FL[0] = eax; FL[1] = (u32)(159);  // @9_655510
  if (FL[0] > FL[1]) goto L6558d2;  // @10_655510
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6641940), sizeof v); (u32)v; });  // @11_655510
  switch (eax) {  // @12_655510
  case 0: goto L65554c;  // @13_655510
  case 1: goto L6558d2;  // @14_655510
  case 2: goto L6555b4;  // @15_655510
  case 3: goto L655589;  // @16_655510
  case 4: goto L655596;  // @17_655510
  case 5: goto L6555e7;  // @18_655510
  case 6: goto L65555a;  // @19_655510
  case 7: goto L6555a3;  // @20_655510
  case 8: goto L6555cb;  // @21_655510
  case 9: goto L6558d2;  // @22_655510
  default: __builtin_trap(); }  // @23_655510
  L65554c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_655510
  PV[0] = (u32)(ebx);  // @26_655510
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 516)))(ecx, PV[0]);  // @27_655510
  ecx = edx = 0;  // @28_655510
  goto L6558d2;  // @29_655510
  L65555a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_655510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_655510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @33_655510
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7093004), (u32)(0));  // @34_655510
  ecx = edx = 0;  // @35_655510
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @36_655510
  if (FL[2] != 0) goto L6556a1;  // @37_655510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_655510
  ecx = esi;  // @39_655510
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 520)))(ecx);  // @40_655510
  ecx = edx = 0;  // @41_655510
  eax = 0;  // @42_655510
  FL[3] = eax;  // @43_655510
  return eax;  // @44_655510
  L655589:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_655510
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 572)))(ecx);  // @47_655510
  ecx = edx = 0;  // @48_655510
  goto L6558d2;  // @49_655510
  L655596:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_655510
  L655598:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 576)))(ecx);  // @53_655510
  ecx = edx = 0;  // @54_655510
  goto L6558d2;  // @55_655510
  L6555a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_655510
  FL[2] = (edi & edi);  // @58_655510
  if (FL[2] == 0) goto L655598;  // @59_655510
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 572)))(ecx);  // @60_655510
  ecx = edx = 0;  // @61_655510
  goto L6558d2;  // @62_655510
  L6555b4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_655510
  eax = ebx;  // @65_655510
  eax = (eax >> (u32)(16));  // @66_655510
  FL[3] = eax;  // @67_655510
  PV[1] = (u32)(eax);  // @68_655510
  eax = (ebx & 0xffff);  // @69_655510
  PV[2] = (u32)(eax);  // @70_655510
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 584)))(ecx, PV[2], PV[1]);  // @71_655510
  ecx = edx = 0;  // @72_655510
  goto L6558d2;  // @73_655510
  L6555cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @75_655510
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 568)))(ecx);  // @76_655510
  ecx = edx = 0;  // @77_655510
  FL[2] = (eax & eax);  // @78_655510
  if (FL[2] == 0) goto L6558d2;  // @79_655510
  eax = (u32)(1);  // @80_655510
  return eax;  // @81_655510
  L6555e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @83_655510
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4589), sizeof v); (u32)v; });  // @84_655510
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 580)))(ecx, PV[3]);  // @85_655510
  ecx = edx = 0;  // @86_655510
  goto L6558d2;  // @87_655510
  L6555fa:;
  FL[0] = eax; FL[1] = (u32)(274);  // @89_655510
  if (FL[0] > FL[1]) goto L6556aa;  // @90_655510
  if (FL[0] == FL[1]) goto L655663;  // @91_655510
  eax = (eax + (u32)(4294967039));  // @92_655510
  FL[3] = eax;  // @93_655510
  FL[0] = eax; FL[1] = (u32)(4);  // @94_655510
  if (FL[0] > FL[1]) goto L6558d2;  // @95_655510
  switch (eax) {  // @96_655510
  case 0: goto L655647;  // @97_655510
  case 1: goto L655638;  // @98_655510
  case 2: goto L6558d2;  // @99_655510
  case 3: goto L65561c;  // @100_655510
  case 4: goto L655647;  // @101_655510
  default: __builtin_trap(); }  // @102_655510
  L65561c:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @104_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @105_655510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_655510
  PV[4] = (u32)(ebx);  // @107_655510
  PV[5] = (u32)(edi);  // @108_655510
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 524)))(ecx, PV[5], PV[4]);  // @109_655510
  ecx = edx = 0;  // @110_655510
  goto L6558d2;  // @111_655510
  L655638:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @113_655510
  PV[6] = (u32)(ebx);  // @114_655510
  PV[7] = (u32)(edi);  // @115_655510
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 588)))(ecx, PV[7], PV[6]);  // @116_655510
  ecx = edx = 0;  // @117_655510
  goto L6558d2;  // @118_655510
  L655647:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @120_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @121_655510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @122_655510
  PV[8] = (u32)(ebx);  // @123_655510
  PV[9] = (u32)(edi);  // @124_655510
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 528)))(ecx, PV[9], PV[8]);  // @125_655510
  ecx = edx = 0;  // @126_655510
  goto L6558d2;  // @127_655510
  L655663:;
  FL[0] = edi; FL[1] = (u32)(61488);  // @129_655510
  if (FL[0] > FL[1]) goto L655680;  // @130_655510
  if (FL[0] == FL[1]) goto L655692;  // @131_655510
  eax = edi;  // @132_655510
  eax = (eax - (u32)(61440));  // @133_655510
  FL[3] = eax;  // @134_655510
  if (FL[3] == 0) goto L655692;  // @135_655510
  eax = (eax - (u32)(16));  // @136_655510
  FL[3] = eax;  // @137_655510
  if (FL[3] == 0) goto L655692;  // @138_655510
  goto L6558d2;  // @139_655510
  L655680:;
  eax = edi;  // @141_655510
  eax = (eax - (u32)(61760));  // @142_655510
  FL[3] = eax;  // @143_655510
  if (FL[3] == 0) goto L655692;  // @144_655510
  eax = (eax - (u32)(48));  // @145_655510
  FL[3] = eax;  // @146_655510
  if (FL[3] != 0) goto L6558d2;  // @147_655510
  L655692:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 99), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @150_655510
  if (FL[0] == FL[1]) goto L6558d2;  // @151_655510
  L6556a1:;
  eax = 0;  // @153_655510
  FL[3] = eax;  // @154_655510
  return eax;  // @155_655510
  L6556aa:;
  FL[0] = eax; FL[1] = (u32)(2019);  // @157_655510
  if (FL[0] > FL[1]) goto L6558b0;  // @158_655510
  if (FL[0] == FL[1]) goto L65586f;  // @159_655510
  eax = (eax + (u32)(4294966784));  // @160_655510
  FL[3] = eax;  // @161_655510
  FL[0] = eax; FL[1] = (u32)(24);  // @162_655510
  if (FL[0] > FL[1]) goto L6558d2;  // @163_655510
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6642164), sizeof v); (u32)v; });  // @164_655510
  switch (eax) {  // @165_655510
  case 0: goto L6558d2;  // @166_655510
  case 1: goto L65576d;  // @167_655510
  case 2: goto L6557a2;  // @168_655510
  case 3: goto L6557d7;  // @169_655510
  case 4: goto L65580c;  // @170_655510
  case 5: goto L655841;  // @171_655510
  case 6: goto L655703;  // @172_655510
  case 7: goto L655738;  // @173_655510
  case 8: goto L6556e3;  // @174_655510
  case 9: goto L6556d7;  // @175_655510
  case 10: goto L6558d2;  // @176_655510
  default: __builtin_trap(); }  // @177_655510
  L6556d7:;
  eax = (u32)(1112363332);  // @179_655510
  return eax;  // @180_655510
  L6556e3:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @182_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @183_655510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @184_655510
  eax = edi;  // @185_655510
  eax = (eax >> (u32)(16));  // @186_655510
  FL[3] = eax;  // @187_655510
  PV[10] = (u32)(eax);  // @188_655510
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 564)))(ecx, PV[10]);  // @189_655510
  ecx = edx = 0;  // @190_655510
  goto L6558d2;  // @191_655510
  L655703:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @193_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @194_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @195_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @196_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @197_655510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_655510
  eax = ebx;  // @199_655510
  eax = (eax >> (u32)(16));  // @200_655510
  FL[3] = eax;  // @201_655510
  eax = (u32)(s32)(s16)(eax & 0xffff);  // @202_655510
  PV[11] = (u32)(eax);  // @203_655510
  eax = (u32)(s32)(s16)((ebx & 0xffff));  // @204_655510
  PV[12] = (u32)(eax);  // @205_655510
  PV[13] = (u32)(edi);  // @206_655510
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 552)))(ecx, PV[13], PV[12], PV[11]);  // @207_655510
  ecx = edx = 0;  // @208_655510
  goto L6558d2;  // @209_655510
  L655738:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @211_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @212_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @213_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @214_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @215_655510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @216_655510
  eax = ebx;  // @217_655510
  eax = (eax >> (u32)(16));  // @218_655510
  FL[3] = eax;  // @219_655510
  eax = (u32)(s32)(s16)(eax & 0xffff);  // @220_655510
  PV[14] = (u32)(eax);  // @221_655510
  eax = (u32)(s32)(s16)((ebx & 0xffff));  // @222_655510
  PV[15] = (u32)(eax);  // @223_655510
  PV[16] = (u32)(edi);  // @224_655510
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 556)))(ecx, PV[16], PV[15], PV[14]);  // @225_655510
  ecx = edx = 0;  // @226_655510
  goto L6558d2;  // @227_655510
  L65576d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @229_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @230_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @231_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @232_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @233_655510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @234_655510
  eax = ebx;  // @235_655510
  eax = (eax >> (u32)(16));  // @236_655510
  FL[3] = eax;  // @237_655510
  eax = (u32)(s32)(s16)(eax & 0xffff);  // @238_655510
  PV[17] = (u32)(eax);  // @239_655510
  eax = (u32)(s32)(s16)((ebx & 0xffff));  // @240_655510
  PV[18] = (u32)(eax);  // @241_655510
  PV[19] = (u32)(edi);  // @242_655510
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 532)))(ecx, PV[19], PV[18], PV[17]);  // @243_655510
  ecx = edx = 0;  // @244_655510
  goto L6558d2;  // @245_655510
  L6557a2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @247_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @248_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @249_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @250_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @251_655510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @252_655510
  eax = ebx;  // @253_655510
  eax = (eax >> (u32)(16));  // @254_655510
  FL[3] = eax;  // @255_655510
  eax = (u32)(s32)(s16)(eax & 0xffff);  // @256_655510
  PV[20] = (u32)(eax);  // @257_655510
  eax = (u32)(s32)(s16)((ebx & 0xffff));  // @258_655510
  PV[21] = (u32)(eax);  // @259_655510
  PV[22] = (u32)(edi);  // @260_655510
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 536)))(ecx, PV[22], PV[21], PV[20]);  // @261_655510
  ecx = edx = 0;  // @262_655510
  goto L6558d2;  // @263_655510
  L6557d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @265_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @266_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @267_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @268_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @269_655510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @270_655510
  eax = ebx;  // @271_655510
  eax = (eax >> (u32)(16));  // @272_655510
  FL[3] = eax;  // @273_655510
  eax = (u32)(s32)(s16)(eax & 0xffff);  // @274_655510
  PV[23] = (u32)(eax);  // @275_655510
  eax = (u32)(s32)(s16)((ebx & 0xffff));  // @276_655510
  PV[24] = (u32)(eax);  // @277_655510
  PV[25] = (u32)(edi);  // @278_655510
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 540)))(ecx, PV[25], PV[24], PV[23]);  // @279_655510
  ecx = edx = 0;  // @280_655510
  goto L6558d2;  // @281_655510
  L65580c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @283_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @284_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @285_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @286_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @287_655510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @288_655510
  eax = ebx;  // @289_655510
  eax = (eax >> (u32)(16));  // @290_655510
  FL[3] = eax;  // @291_655510
  eax = (u32)(s32)(s16)(eax & 0xffff);  // @292_655510
  PV[26] = (u32)(eax);  // @293_655510
  eax = (u32)(s32)(s16)((ebx & 0xffff));  // @294_655510
  PV[27] = (u32)(eax);  // @295_655510
  PV[28] = (u32)(edi);  // @296_655510
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 544)))(ecx, PV[28], PV[27], PV[26]);  // @297_655510
  ecx = edx = 0;  // @298_655510
  goto L6558d2;  // @299_655510
  L655841:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @301_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @302_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @303_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4518), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @304_655510
  if (FL[0] != FL[1]) goto L6558d2;  // @305_655510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @306_655510
  eax = ebx;  // @307_655510
  eax = (eax >> (u32)(16));  // @308_655510
  FL[3] = eax;  // @309_655510
  eax = (u32)(s32)(s16)(eax & 0xffff);  // @310_655510
  PV[29] = (u32)(eax);  // @311_655510
  eax = (u32)(s32)(s16)((ebx & 0xffff));  // @312_655510
  PV[30] = (u32)(eax);  // @313_655510
  PV[31] = (u32)(edi);  // @314_655510
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 548)))(ecx, PV[31], PV[30], PV[29]);  // @315_655510
  ecx = edx = 0;  // @316_655510
  goto L6558d2;  // @317_655510
  L65586f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @319_655510
  FL[2] = (eax & eax);  // @320_655510
  if (FL[2] == 0) goto L655885;  // @321_655510
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6809), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @322_655510
  if (FL[0] != FL[1]) goto L6556a1;  // @323_655510
  L655885:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @325_655510
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 200)))(ecx);  // @326_655510
  ecx = edx = 0;  // @327_655510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @328_655510
  ecx = esi;  // @329_655510
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 200)))(ecx);  // @330_655510
  ecx = edx = 0;  // @331_655510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @332_655510
  ecx = esi;  // @333_655510
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4589), sizeof v); (u32)v; });  // @334_655510
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 580)))(ecx, PV[32]);  // @335_655510
  ecx = edx = 0;  // @336_655510
  eax = 0;  // @337_655510
  FL[3] = eax;  // @338_655510
  return eax;  // @339_655510
  L6558b0:;
  eax = (eax - (u32)(2030));  // @341_655510
  FL[3] = eax;  // @342_655510
  if (FL[3] == 0) goto L6558c7;  // @343_655510
  eax = (eax - (u32)(1));  // @344_655510
  FL[3] = eax;  // @345_655510
  if (FL[3] != 0) goto L6558d2;  // @346_655510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @347_655510
  PV[33] = (u32)(edi);  // @348_655510
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 636)))(ecx, PV[33]);  // @349_655510
  ecx = edx = 0;  // @350_655510
  goto L6558d2;  // @351_655510
  L6558c7:;
  FL[2] = (edi & edi);  // @353_655510
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @354_655510
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 4518), &v, sizeof v); }  // @355_655510
  L6558d2:;
  PV[34] = (u32)(ebx);  // @357_655510
  PV[35] = (u32)(edi);  // @358_655510
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @359_655510
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 307), sizeof v); (u32)v; });  // @360_655510
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x676200))(PV[37], PV[36], PV[35], PV[34]);  // @361_655510
  ecx = edx = 0;  // @362_655510
  return eax;  // @363_655510
}
PCREG(655510, lifted_655510);

