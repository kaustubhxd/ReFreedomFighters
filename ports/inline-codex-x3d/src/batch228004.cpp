// batch228004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_5b6d00_thiscall1(u32) __asm__("ext_5b6d00");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5b6e20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c39e);  // @h_5b6e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, outer_count_cmp = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @1_5b6e20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @2_5b6e20
  eax = ext_5b6d00_thiscall1(ecx);  // @3_5b6e20
  ecx = edx = 0;  // @4_5b6e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_5b6e20
  ecx = (u32)(EBP - 24);  // @6_5b6e20
  PV[0] = (u32)(ecx);  // @7_5b6e20
  ecx = esi;  // @8_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[0], (u32)(4));  // @10_5b6e20
  ecx = edx = 0;  // @11_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @12_5b6e20
  if ((eax & eax) == 0) goto L5b7078;  // @13_5b6e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @14_5b6e20
  if ((s32)(eax & eax) <= 0) goto L5b7078;  // @15_5b6e20
  L5b6e80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_5b6e20
  ecx = (u32)(EBP - 28);  // @18_5b6e20
  PV[1] = (u32)(ecx);  // @19_5b6e20
  ecx = esi;  // @20_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[1], (u32)(4));  // @21_5b6e20
  ecx = edx = 0;  // @22_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @23_5b6e20
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @24_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[2]);  // @26_5b6e20
  ecx = edx = 0;  // @27_5b6e20
  edi = eax;  // @28_5b6e20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @29_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @30_5b6e20
  ecx = edx = 0;  // @31_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @32_5b6e20
  reg.state = (s32)((u32)(0));  // @33_5b6e20
  if ((eax & eax) == 0) goto L5b6ec2;  // @34_5b6e20
  ecx = eax;  // @35_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(29));  // @36_5b6e20
  ecx = edx = 0;  // @37_5b6e20
  goto L5b6ec4;  // @38_5b6e20
  L5b6ec2:;
  eax = 0;  // @40_5b6e20
  L5b6ec4:;
  reg.state = (s32)((u32)(4294967295));  // @42_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @43_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @44_5b6e20
  ecx = edx = 0;  // @45_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @46_5b6e20
  reg.state = (s32)((u32)(1));  // @47_5b6e20
  if ((eax & eax) == 0) goto L5b6ef2;  // @48_5b6e20
  ecx = eax;  // @49_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(32));  // @50_5b6e20
  ecx = edx = 0;  // @51_5b6e20
  goto L5b6ef4;  // @52_5b6e20
  L5b6ef2:;
  eax = 0;  // @54_5b6e20
  L5b6ef4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @56_5b6e20
  ecx = esi;  // @57_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_5b6e20
  eax = (u32)(edi + 56);  // @59_5b6e20
  PV[3] = (u32)(eax);  // @60_5b6e20
  reg.state = (s32)((u32)(4294967295));  // @61_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[3], (u32)(4));  // @62_5b6e20
  ecx = edx = 0;  // @63_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_5b6e20
  eax = (u32)(edi + 96);  // @65_5b6e20
  PV[4] = (u32)(eax);  // @66_5b6e20
  ecx = esi;  // @67_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[4], (u32)(36));  // @68_5b6e20
  ecx = edx = 0;  // @69_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_5b6e20
  eax = (u32)(edi + 72);  // @71_5b6e20
  PV[5] = (u32)(eax);  // @72_5b6e20
  ecx = esi;  // @73_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[5], (u32)(12));  // @74_5b6e20
  ecx = edx = 0;  // @75_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_5b6e20
  eax = (u32)(edi + 84);  // @77_5b6e20
  PV[6] = (u32)(eax);  // @78_5b6e20
  ecx = esi;  // @79_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[6], (u32)(12));  // @80_5b6e20
  ecx = edx = 0;  // @81_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_5b6e20
  eax = (u32)(edi + 60);  // @83_5b6e20
  PV[7] = (u32)(eax);  // @84_5b6e20
  ecx = esi;  // @85_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[7], (u32)(12));  // @86_5b6e20
  ecx = edx = 0;  // @87_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_5b6e20
  eax = (u32)(edi + 8);  // @89_5b6e20
  PV[8] = (u32)(eax);  // @90_5b6e20
  ecx = esi;  // @91_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[8], (u32)(48));  // @92_5b6e20
  ecx = edx = 0;  // @93_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @94_5b6e20
  eax = (u32)(edi + 132);  // @95_5b6e20
  PV[9] = (u32)(eax);  // @96_5b6e20
  ecx = esi;  // @97_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[9], (u32)(4));  // @98_5b6e20
  ecx = edx = 0;  // @99_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_5b6e20
  eax = (u32)(edi + 136);  // @101_5b6e20
  PV[10] = (u32)(eax);  // @102_5b6e20
  ecx = esi;  // @103_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[10], (u32)(4));  // @104_5b6e20
  ecx = edx = 0;  // @105_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_5b6e20
  eax = (u32)(edi + 140);  // @107_5b6e20
  PV[11] = (u32)(eax);  // @108_5b6e20
  ecx = esi;  // @109_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[11], (u32)(1));  // @110_5b6e20
  ecx = edx = 0;  // @111_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @112_5b6e20
  ecx = (u32)(EBP + 8);  // @113_5b6e20
  PV[12] = (u32)(ecx);  // @114_5b6e20
  ecx = esi;  // @115_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[12], (u32)(4));  // @116_5b6e20
  ecx = edx = 0;  // @117_5b6e20
  ebx = 0;  // @118_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b6ffd;  // @119_5b6e20
  L5b6f90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_5b6e20
  ecx = (u32)(EBP - 32);  // @122_5b6e20
  PV[13] = (u32)(ecx);  // @123_5b6e20
  ecx = esi;  // @124_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[13], (u32)(4));  // @125_5b6e20
  ecx = edx = 0;  // @126_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @127_5b6e20
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @128_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[14]);  // @130_5b6e20
  ecx = edx = 0;  // @131_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_5b6e20
  edi = eax;  // @133_5b6e20
  PV[15] = (u32)(edi);  // @134_5b6e20
  ecx = esi;  // @135_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[15], (u32)(4));  // @136_5b6e20
  ecx = edx = 0;  // @137_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_5b6e20
  ecx = (u32)(edi + 4);  // @139_5b6e20
  PV[16] = (u32)(ecx);  // @140_5b6e20
  ecx = esi;  // @141_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[16], (u32)(4));  // @142_5b6e20
  ecx = edx = 0;  // @143_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_5b6e20
  eax = (u32)(edi + 8);  // @145_5b6e20
  PV[17] = (u32)(eax);  // @146_5b6e20
  ecx = esi;  // @147_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[17], (u32)(4));  // @148_5b6e20
  ecx = edx = 0;  // @149_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @150_5b6e20
  eax = (u32)(edi + 12);  // @151_5b6e20
  PV[18] = (u32)(eax);  // @152_5b6e20
  ecx = esi;  // @153_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[18], (u32)(1));  // @154_5b6e20
  ecx = edx = 0;  // @155_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_5b6e20
  eax = (u32)(edi + 13);  // @157_5b6e20
  PV[19] = (u32)(eax);  // @158_5b6e20
  ecx = esi;  // @159_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[19], (u32)(4));  // @160_5b6e20
  ecx = edx = 0;  // @161_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @162_5b6e20
  eax = (u32)(edi + 17);  // @163_5b6e20
  PV[20] = (u32)(eax);  // @164_5b6e20
  ecx = esi;  // @165_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[20], (u32)(12));  // @166_5b6e20
  ecx = edx = 0;  // @167_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @168_5b6e20
  ebx = (ebx + 1);  // @169_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b6f90;  // @170_5b6e20
  L5b6ffd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @172_5b6e20
  ecx = (u32)(EBP + 8);  // @173_5b6e20
  PV[21] = (u32)(ecx);  // @174_5b6e20
  ecx = esi;  // @175_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[21], (u32)(4));  // @176_5b6e20
  ecx = edx = 0;  // @177_5b6e20
  ebx = 0;  // @178_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b7065;  // @179_5b6e20
  L5b7011:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @181_5b6e20
  ecx = (u32)(EBP - 36);  // @182_5b6e20
  PV[22] = (u32)(ecx);  // @183_5b6e20
  ecx = esi;  // @184_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[22], (u32)(4));  // @185_5b6e20
  ecx = edx = 0;  // @186_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @187_5b6e20
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @188_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @189_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[23]);  // @190_5b6e20
  ecx = edx = 0;  // @191_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @192_5b6e20
  edi = eax;  // @193_5b6e20
  PV[24] = (u32)(edi);  // @194_5b6e20
  ecx = esi;  // @195_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[24], (u32)(12));  // @196_5b6e20
  ecx = edx = 0;  // @197_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_5b6e20
  ecx = (u32)(edi + 12);  // @199_5b6e20
  PV[25] = (u32)(ecx);  // @200_5b6e20
  ecx = esi;  // @201_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[25], (u32)(12));  // @202_5b6e20
  ecx = edx = 0;  // @203_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @204_5b6e20
  eax = (u32)(edi + 28);  // @205_5b6e20
  PV[26] = (u32)(eax);  // @206_5b6e20
  ecx = esi;  // @207_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[26], (u32)(4));  // @208_5b6e20
  ecx = edx = 0;  // @209_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @210_5b6e20
  eax = (u32)(edi + 24);  // @211_5b6e20
  PV[27] = (u32)(eax);  // @212_5b6e20
  ecx = esi;  // @213_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[27], (u32)(4));  // @214_5b6e20
  ecx = edx = 0;  // @215_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @216_5b6e20
  ebx = (ebx + 1);  // @217_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b7011;  // @218_5b6e20
  L5b7065:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @220_5b6e20
  ebx = (ebx + 1);  // @221_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @222_5b6e20
  outer_count_cmp = ebx;  // preserve flags across the following mov
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @223_5b6e20
  if ((s32)outer_count_cmp < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) goto L5b6e80;  // @224_5b6e20
  L5b7078:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @226_5b6e20
  SEH_LEAVE();  // @227_5b6e20
  return eax;  // @228_5b6e20
}
PCREG(5b6e20, lifted_5b6e20);

