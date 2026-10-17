// batch218036.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4733d0_thiscall2(u32, u32) __asm__("ext_4733d0");
extern "C" u32 THISCALL ext_5df5f0_thiscall4(u32, u32, u32, u32) __asm__("ext_5df5f0");
extern "C" u32 THISCALL ext_5df620_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5df620");
extern "C" u32 THISCALL ext_5df650_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5df650");
extern "C" u32 THISCALL ext_5df690_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5df690");
extern "C" u32 THISCALL ext_5df6c0_thiscall4(u32, u32, u32, u32) __asm__("ext_5df6c0");
extern "C" u32 THISCALL ext_5df6f0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5df6f0");
extern "C" u32 THISCALL ext_5df720_thiscall4(u32, u32, u32, u32) __asm__("ext_5df720");
extern "C" u32 THISCALL ext_5df750_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5df750");
extern "C" u32 THISCALL ext_5df790_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5df790");
extern "C" u32 THISCALL ext_5df7c0_thiscall4(u32, u32, u32, u32) __asm__("ext_5df7c0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_590820(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b8b2);  // @h_590820
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_590820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_590820
  eax = (u32)(ecx - 4);  // @2_590820
  FL[0] = eax; FL[1] = (u32)(25);  // @3_590820
  if (FL[0] > FL[1]) goto L590c52;  // @4_590820
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5835948), sizeof v); (u32)v; });  // @5_590820
  switch (eax) {  // @6_590820
  case 0: goto L590863;  // @7_590820
  case 1: goto L5908ba;  // @8_590820
  case 2: goto L5908fb;  // @9_590820
  case 3: goto L590936;  // @10_590820
  case 4: goto L590982;  // @11_590820
  case 5: goto L5909ce;  // @12_590820
  case 6: goto L590a1a;  // @13_590820
  case 7: goto L590a66;  // @14_590820
  case 8: goto L590ab2;  // @15_590820
  case 9: goto L590afe;  // @16_590820
  case 10: goto L590b3e;  // @17_590820
  case 11: goto L590b85;  // @18_590820
  case 12: goto L590bcc;  // @19_590820
  case 13: goto L590c13;  // @20_590820
  case 14: goto L590c52;  // @21_590820
  default: __builtin_trap(); }  // @22_590820
  L590863:;
  eax = ext_41e290_cdecl1((u32)(20));  // @24_590820
  ecx = edx = 0;  // @25_590820
  edi = eax;  // @26_590820
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @27_590820
  reg.state = (s32)((u32)(0));  // @28_590820
  FL[2] = (edi & edi);  // @29_590820
  if (FL[2] == 0) goto L5908a5;  // @30_590820
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_590820
  ecx = esi;  // @32_590820
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 1272)))(ecx);  // @33_590820
  ecx = edx = 0;  // @34_590820
  PV[0] = (u32)(eax);  // @35_590820
  PV[1] = (u32)(esi);  // @36_590820
  ecx = edi;  // @37_590820
  eax = ext_5df6c0_thiscall4(ecx, (u32)(4), PV[1], PV[0]);  // @38_590820
  ecx = edx = 0;  // @39_590820
  SEH_LEAVE();  // @40_590820
  return eax;  // @41_590820
  L5908a5:;
  eax = 0;  // @43_590820
  FL[3] = eax;  // @44_590820
  SEH_LEAVE();  // @45_590820
  return eax;  // @46_590820
  L5908ba:;
  eax = ext_41e290_cdecl1((u32)(34));  // @48_590820
  ecx = edx = 0;  // @49_590820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @50_590820
  reg.state = (s32)((u32)(1));  // @51_590820
  FL[2] = (eax & eax);  // @52_590820
  if (FL[2] == 0) goto L5908a5;  // @53_590820
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1924), sizeof v); (u32)v; });  // @54_590820
  ecx = eax;  // @55_590820
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1920), sizeof v); (u32)v; });  // @56_590820
  PV[4] = (u32)(esi);  // @57_590820
  eax = ext_5df750_thiscall5(ecx, (u32)(17), PV[4], PV[3], PV[2]);  // @58_590820
  ecx = edx = 0;  // @59_590820
  SEH_LEAVE();  // @60_590820
  return eax;  // @61_590820
  L5908fb:;
  eax = ext_41e290_cdecl1((u32)(16));  // @63_590820
  ecx = edx = 0;  // @64_590820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @65_590820
  reg.state = (s32)((u32)(2));  // @66_590820
  FL[2] = (eax & eax);  // @67_590820
  if (FL[2] == 0) goto L5908a5;  // @68_590820
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1928), sizeof v); (u32)v; });  // @69_590820
  ecx = eax;  // @70_590820
  PV[6] = (u32)(esi);  // @71_590820
  eax = ext_5df720_thiscall4(ecx, (u32)(18), PV[6], PV[5]);  // @72_590820
  ecx = edx = 0;  // @73_590820
  SEH_LEAVE();  // @74_590820
  return eax;  // @75_590820
  L590936:;
  eax = ext_41e290_cdecl1((u32)(20));  // @77_590820
  ecx = edx = 0;  // @78_590820
  edi = eax;  // @79_590820
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @80_590820
  reg.state = (s32)((u32)(3));  // @81_590820
  FL[2] = (edi & edi);  // @82_590820
  if (FL[2] == 0) goto L5908a5;  // @83_590820
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_590820
  ecx = esi;  // @85_590820
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1848), sizeof v); (u32)v; });  // @86_590820
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 1272)))(ecx);  // @87_590820
  ecx = edx = 0;  // @88_590820
  PV[8] = (u32)(eax);  // @89_590820
  PV[9] = (u32)(esi);  // @90_590820
  ecx = edi;  // @91_590820
  eax = ext_5df620_thiscall5(ecx, (u32)(19), PV[9], PV[8], PV[7]);  // @92_590820
  ecx = edx = 0;  // @93_590820
  SEH_LEAVE();  // @94_590820
  return eax;  // @95_590820
  L590982:;
  eax = ext_41e290_cdecl1((u32)(24));  // @97_590820
  ecx = edx = 0;  // @98_590820
  edi = eax;  // @99_590820
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @100_590820
  reg.state = (s32)((u32)(4));  // @101_590820
  FL[2] = (edi & edi);  // @102_590820
  if (FL[2] == 0) goto L5908a5;  // @103_590820
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_590820
  ecx = esi;  // @105_590820
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1844), sizeof v); (u32)v; });  // @106_590820
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 1272)))(ecx);  // @107_590820
  ecx = edx = 0;  // @108_590820
  PV[11] = (u32)(eax);  // @109_590820
  PV[12] = (u32)(esi);  // @110_590820
  ecx = edi;  // @111_590820
  eax = ext_5df790_thiscall5(ecx, (u32)(20), PV[12], PV[11], PV[10]);  // @112_590820
  ecx = edx = 0;  // @113_590820
  SEH_LEAVE();  // @114_590820
  return eax;  // @115_590820
  L5909ce:;
  eax = ext_41e290_cdecl1((u32)(24));  // @117_590820
  ecx = edx = 0;  // @118_590820
  edi = eax;  // @119_590820
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @120_590820
  reg.state = (s32)((u32)(5));  // @121_590820
  FL[2] = (edi & edi);  // @122_590820
  if (FL[2] == 0) goto L5908a5;  // @123_590820
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_590820
  ecx = esi;  // @125_590820
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1844), sizeof v); (u32)v; });  // @126_590820
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 1272)))(ecx);  // @127_590820
  ecx = edx = 0;  // @128_590820
  PV[14] = (u32)(eax);  // @129_590820
  PV[15] = (u32)(esi);  // @130_590820
  ecx = edi;  // @131_590820
  eax = ext_5df790_thiscall5(ecx, (u32)(21), PV[15], PV[14], PV[13]);  // @132_590820
  ecx = edx = 0;  // @133_590820
  SEH_LEAVE();  // @134_590820
  return eax;  // @135_590820
  L590a1a:;
  eax = ext_41e290_cdecl1((u32)(24));  // @137_590820
  ecx = edx = 0;  // @138_590820
  edi = eax;  // @139_590820
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @140_590820
  reg.state = (s32)((u32)(6));  // @141_590820
  FL[2] = (edi & edi);  // @142_590820
  if (FL[2] == 0) goto L5908a5;  // @143_590820
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_590820
  ecx = esi;  // @145_590820
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1844), sizeof v); (u32)v; });  // @146_590820
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 1272)))(ecx);  // @147_590820
  ecx = edx = 0;  // @148_590820
  PV[17] = (u32)(eax);  // @149_590820
  PV[18] = (u32)(esi);  // @150_590820
  ecx = edi;  // @151_590820
  eax = ext_5df790_thiscall5(ecx, (u32)(22), PV[18], PV[17], PV[16]);  // @152_590820
  ecx = edx = 0;  // @153_590820
  SEH_LEAVE();  // @154_590820
  return eax;  // @155_590820
  L590a66:;
  eax = ext_41e290_cdecl1((u32)(20));  // @157_590820
  ecx = edx = 0;  // @158_590820
  edi = eax;  // @159_590820
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @160_590820
  reg.state = (s32)((u32)(7));  // @161_590820
  FL[2] = (edi & edi);  // @162_590820
  if (FL[2] == 0) goto L5908a5;  // @163_590820
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @164_590820
  ecx = esi;  // @165_590820
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1836), sizeof v); (u32)v; });  // @166_590820
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 1272)))(ecx);  // @167_590820
  ecx = edx = 0;  // @168_590820
  PV[20] = (u32)(eax);  // @169_590820
  PV[21] = (u32)(esi);  // @170_590820
  ecx = edi;  // @171_590820
  eax = ext_5df6f0_thiscall5(ecx, (u32)(23), PV[21], PV[20], PV[19]);  // @172_590820
  ecx = edx = 0;  // @173_590820
  SEH_LEAVE();  // @174_590820
  return eax;  // @175_590820
  L590ab2:;
  eax = ext_41e290_cdecl1((u32)(20));  // @177_590820
  ecx = edx = 0;  // @178_590820
  edi = eax;  // @179_590820
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @180_590820
  reg.state = (s32)((u32)(8));  // @181_590820
  FL[2] = (edi & edi);  // @182_590820
  if (FL[2] == 0) goto L5908a5;  // @183_590820
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @184_590820
  ecx = esi;  // @185_590820
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1840), sizeof v); (u32)v; });  // @186_590820
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 1272)))(ecx);  // @187_590820
  ecx = edx = 0;  // @188_590820
  PV[23] = (u32)(eax);  // @189_590820
  PV[24] = (u32)(esi);  // @190_590820
  ecx = edi;  // @191_590820
  eax = ext_5df690_thiscall5(ecx, (u32)(24), PV[24], PV[23], PV[22]);  // @192_590820
  ecx = edx = 0;  // @193_590820
  SEH_LEAVE();  // @194_590820
  return eax;  // @195_590820
  L590afe:;
  eax = ext_41e290_cdecl1((u32)(16));  // @197_590820
  ecx = edx = 0;  // @198_590820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @199_590820
  reg.state = (s32)((u32)(9));  // @200_590820
  FL[2] = (eax & eax);  // @201_590820
  if (FL[2] == 0) goto L5908a5;  // @202_590820
  ecx = (u32)(esi + 1916);  // @203_590820
  PV[25] = (u32)(ecx);  // @204_590820
  PV[26] = (u32)(esi);  // @205_590820
  ecx = eax;  // @206_590820
  eax = ext_5df7c0_thiscall4(ecx, (u32)(25), PV[26], PV[25]);  // @207_590820
  ecx = edx = 0;  // @208_590820
  SEH_LEAVE();  // @209_590820
  return eax;  // @210_590820
  L590b3e:;
  eax = ext_41e290_cdecl1((u32)(21));  // @212_590820
  ecx = edx = 0;  // @213_590820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @214_590820
  reg.state = (s32)((u32)(10));  // @215_590820
  FL[2] = (eax & eax);  // @216_590820
  if (FL[2] == 0) goto L5908a5;  // @217_590820
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1888), sizeof v); (u32)v; });  // @218_590820
  ecx = eax;  // @219_590820
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1900), sizeof v); (u32)v; });  // @220_590820
  PV[29] = (u32)(esi);  // @221_590820
  eax = ext_5df650_thiscall6(ecx, (u32)(26), PV[29], PV[28], PV[27], (u32)(1));  // @222_590820
  ecx = edx = 0;  // @223_590820
  SEH_LEAVE();  // @224_590820
  return eax;  // @225_590820
  L590b85:;
  eax = ext_41e290_cdecl1((u32)(21));  // @227_590820
  ecx = edx = 0;  // @228_590820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @229_590820
  reg.state = (s32)((u32)(11));  // @230_590820
  FL[2] = (eax & eax);  // @231_590820
  if (FL[2] == 0) goto L5908a5;  // @232_590820
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1892), sizeof v); (u32)v; });  // @233_590820
  ecx = eax;  // @234_590820
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1904), sizeof v); (u32)v; });  // @235_590820
  PV[32] = (u32)(esi);  // @236_590820
  eax = ext_5df650_thiscall6(ecx, (u32)(27), PV[32], PV[31], PV[30], (u32)(0));  // @237_590820
  ecx = edx = 0;  // @238_590820
  SEH_LEAVE();  // @239_590820
  return eax;  // @240_590820
  L590bcc:;
  eax = ext_41e290_cdecl1((u32)(21));  // @242_590820
  ecx = edx = 0;  // @243_590820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @244_590820
  reg.state = (s32)((u32)(12));  // @245_590820
  FL[2] = (eax & eax);  // @246_590820
  if (FL[2] == 0) goto L5908a5;  // @247_590820
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1896), sizeof v); (u32)v; });  // @248_590820
  ecx = eax;  // @249_590820
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1908), sizeof v); (u32)v; });  // @250_590820
  PV[35] = (u32)(esi);  // @251_590820
  eax = ext_5df650_thiscall6(ecx, (u32)(28), PV[35], PV[34], PV[33], (u32)(0));  // @252_590820
  ecx = edx = 0;  // @253_590820
  SEH_LEAVE();  // @254_590820
  return eax;  // @255_590820
  L590c13:;
  eax = ext_41e290_cdecl1((u32)(16));  // @257_590820
  ecx = edx = 0;  // @258_590820
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @259_590820
  reg.state = (s32)((u32)(13));  // @260_590820
  FL[2] = (eax & eax);  // @261_590820
  if (FL[2] == 0) goto L5908a5;  // @262_590820
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1912), sizeof v); (u32)v; });  // @263_590820
  ecx = eax;  // @264_590820
  PV[37] = (u32)(esi);  // @265_590820
  eax = ext_5df5f0_thiscall4(ecx, (u32)(29), PV[37], PV[36]);  // @266_590820
  ecx = edx = 0;  // @267_590820
  SEH_LEAVE();  // @268_590820
  return eax;  // @269_590820
  L590c52:;
  PV[38] = (u32)(ecx);  // @271_590820
  ecx = esi;  // @272_590820
  eax = ext_4733d0_thiscall2(ecx, PV[38]);  // @273_590820
  ecx = edx = 0;  // @274_590820
  SEH_LEAVE();  // @275_590820
  return eax;  // @276_590820
}
PCREG(590820, lifted_590820);

