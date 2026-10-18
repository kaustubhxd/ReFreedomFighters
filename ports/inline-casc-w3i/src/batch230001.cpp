// batch230001.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5d18a0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[132], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d18a0
  edi = ecx;  // @1_5d18a0
  PV[0] = (u32)(ecx);  // @2_5d18a0
  ecx = esi;  // @3_5d18a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @4_5d18a0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @5_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2644) + 0), 4); v; });  // @7_5d18a0
  X0[1] = 0;  // @8_5d18a0
  X0[2] = 0;  // @9_5d18a0
  X0[3] = 0;  // @10_5d18a0
  PV[1] = X0[0];  // @11_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @12_5d18a0
  ecx = edx = 0;  // @13_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2648) + 0), 4); v; });  // @15_5d18a0
  X0[1] = 0;  // @16_5d18a0
  X0[2] = 0;  // @17_5d18a0
  X0[3] = 0;  // @18_5d18a0
  PV[2] = (u32)(ecx);  // @19_5d18a0
  ecx = esi;  // @20_5d18a0
  PV[3] = X0[0];  // @21_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @22_5d18a0
  ecx = edx = 0;  // @23_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2652) + 0), 4); v; });  // @25_5d18a0
  X0[1] = 0;  // @26_5d18a0
  X0[2] = 0;  // @27_5d18a0
  X0[3] = 0;  // @28_5d18a0
  PV[4] = (u32)(ecx);  // @29_5d18a0
  ecx = esi;  // @30_5d18a0
  PV[5] = X0[0];  // @31_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[5]);  // @32_5d18a0
  ecx = edx = 0;  // @33_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2656) + 0), 4); v; });  // @35_5d18a0
  X0[1] = 0;  // @36_5d18a0
  X0[2] = 0;  // @37_5d18a0
  X0[3] = 0;  // @38_5d18a0
  PV[6] = (u32)(ecx);  // @39_5d18a0
  ecx = esi;  // @40_5d18a0
  PV[7] = X0[0];  // @41_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @42_5d18a0
  ecx = edx = 0;  // @43_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @44_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2660) + 0), 4); v; });  // @45_5d18a0
  X0[1] = 0;  // @46_5d18a0
  X0[2] = 0;  // @47_5d18a0
  X0[3] = 0;  // @48_5d18a0
  PV[8] = (u32)(ecx);  // @49_5d18a0
  ecx = esi;  // @50_5d18a0
  PV[9] = X0[0];  // @51_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[9]);  // @52_5d18a0
  ecx = edx = 0;  // @53_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2664) + 0), 4); v; });  // @55_5d18a0
  X0[1] = 0;  // @56_5d18a0
  X0[2] = 0;  // @57_5d18a0
  X0[3] = 0;  // @58_5d18a0
  PV[10] = (u32)(ecx);  // @59_5d18a0
  ecx = esi;  // @60_5d18a0
  PV[11] = X0[0];  // @61_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[11]);  // @62_5d18a0
  ecx = edx = 0;  // @63_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2668) + 0), 4); v; });  // @65_5d18a0
  X0[1] = 0;  // @66_5d18a0
  X0[2] = 0;  // @67_5d18a0
  X0[3] = 0;  // @68_5d18a0
  PV[12] = (u32)(ecx);  // @69_5d18a0
  ecx = esi;  // @70_5d18a0
  PV[13] = X0[0];  // @71_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @72_5d18a0
  ecx = edx = 0;  // @73_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_5d18a0
  ecx = esi;  // @75_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2672), sizeof v); (u32)v; });  // @76_5d18a0
  PV[14] = (u32)(eax);  // @77_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[14]);  // @78_5d18a0
  ecx = edx = 0;  // @79_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_5d18a0
  ecx = esi;  // @81_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2673), sizeof v); (u32)v; });  // @82_5d18a0
  PV[15] = (u32)(eax);  // @83_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[15]);  // @84_5d18a0
  ecx = edx = 0;  // @85_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_5d18a0
  eax = (u32)(edi + 2674);  // @87_5d18a0
  PV[16] = (u32)(eax);  // @88_5d18a0
  ecx = esi;  // @89_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[16]);  // @90_5d18a0
  ecx = edx = 0;  // @91_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_5d18a0
  eax = (u32)(edi + 2686);  // @93_5d18a0
  PV[17] = (u32)(eax);  // @94_5d18a0
  ecx = esi;  // @95_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[17]);  // @96_5d18a0
  ecx = edx = 0;  // @97_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_5d18a0
  eax = (u32)(edi + 2698);  // @99_5d18a0
  PV[18] = (u32)(eax);  // @100_5d18a0
  ecx = esi;  // @101_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[18]);  // @102_5d18a0
  ecx = edx = 0;  // @103_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2710) + 0), 4); v; });  // @105_5d18a0
  X0[1] = 0;  // @106_5d18a0
  X0[2] = 0;  // @107_5d18a0
  X0[3] = 0;  // @108_5d18a0
  PV[19] = (u32)(ecx);  // @109_5d18a0
  ecx = esi;  // @110_5d18a0
  PV[20] = X0[0];  // @111_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[20]);  // @112_5d18a0
  ecx = edx = 0;  // @113_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2714) + 0), 4); v; });  // @115_5d18a0
  X0[1] = 0;  // @116_5d18a0
  X0[2] = 0;  // @117_5d18a0
  X0[3] = 0;  // @118_5d18a0
  PV[21] = (u32)(ecx);  // @119_5d18a0
  ecx = esi;  // @120_5d18a0
  PV[22] = X0[0];  // @121_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[22]);  // @122_5d18a0
  ecx = edx = 0;  // @123_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2718) + 0), 4); v; });  // @125_5d18a0
  X0[1] = 0;  // @126_5d18a0
  X0[2] = 0;  // @127_5d18a0
  X0[3] = 0;  // @128_5d18a0
  PV[23] = (u32)(ecx);  // @129_5d18a0
  ecx = esi;  // @130_5d18a0
  PV[24] = X0[0];  // @131_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[24]);  // @132_5d18a0
  ecx = edx = 0;  // @133_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @134_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2722) + 0), 4); v; });  // @135_5d18a0
  X0[1] = 0;  // @136_5d18a0
  X0[2] = 0;  // @137_5d18a0
  X0[3] = 0;  // @138_5d18a0
  PV[25] = (u32)(ecx);  // @139_5d18a0
  ecx = esi;  // @140_5d18a0
  PV[26] = X0[0];  // @141_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[26]);  // @142_5d18a0
  ecx = edx = 0;  // @143_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2734) + 0), 4); v; });  // @145_5d18a0
  X0[1] = 0;  // @146_5d18a0
  X0[2] = 0;  // @147_5d18a0
  X0[3] = 0;  // @148_5d18a0
  PV[27] = (u32)(ecx);  // @149_5d18a0
  ecx = esi;  // @150_5d18a0
  PV[28] = X0[0];  // @151_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[28]);  // @152_5d18a0
  ecx = edx = 0;  // @153_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @154_5d18a0
  ecx = esi;  // @155_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2742), sizeof v); (u32)v; });  // @156_5d18a0
  PV[29] = (u32)(eax);  // @157_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[29]);  // @158_5d18a0
  ecx = edx = 0;  // @159_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_5d18a0
  ecx = esi;  // @161_5d18a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2773), sizeof v); (u32)v; });  // @162_5d18a0
  PV[30] = (u32)(eax);  // @163_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[30]);  // @164_5d18a0
  ecx = edx = 0;  // @165_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @166_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2777) + 0), 4); v; });  // @167_5d18a0
  X0[1] = 0;  // @168_5d18a0
  X0[2] = 0;  // @169_5d18a0
  X0[3] = 0;  // @170_5d18a0
  PV[31] = (u32)(ecx);  // @171_5d18a0
  ecx = esi;  // @172_5d18a0
  PV[32] = X0[0];  // @173_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[32]);  // @174_5d18a0
  ecx = edx = 0;  // @175_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @176_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2781) + 0), 4); v; });  // @177_5d18a0
  X0[1] = 0;  // @178_5d18a0
  X0[2] = 0;  // @179_5d18a0
  X0[3] = 0;  // @180_5d18a0
  PV[33] = (u32)(ecx);  // @181_5d18a0
  ecx = esi;  // @182_5d18a0
  PV[34] = X0[0];  // @183_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[34]);  // @184_5d18a0
  ecx = edx = 0;  // @185_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @186_5d18a0
  ecx = esi;  // @187_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2772), sizeof v); (u32)v; });  // @188_5d18a0
  PV[35] = (u32)(eax);  // @189_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[35]);  // @190_5d18a0
  ecx = edx = 0;  // @191_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @192_5d18a0
  ecx = esi;  // @193_5d18a0
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2785), sizeof v); (u32)v; });  // @194_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[36]);  // @195_5d18a0
  ecx = edx = 0;  // @196_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @197_5d18a0
  ecx = esi;  // @198_5d18a0
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2789), sizeof v); (u32)v; });  // @199_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[37]);  // @200_5d18a0
  ecx = edx = 0;  // @201_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @202_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2793) + 0), 4); v; });  // @203_5d18a0
  X0[1] = 0;  // @204_5d18a0
  X0[2] = 0;  // @205_5d18a0
  X0[3] = 0;  // @206_5d18a0
  PV[38] = (u32)(ecx);  // @207_5d18a0
  ecx = esi;  // @208_5d18a0
  PV[39] = X0[0];  // @209_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[39]);  // @210_5d18a0
  ecx = edx = 0;  // @211_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @212_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2797) + 0), 4); v; });  // @213_5d18a0
  X0[1] = 0;  // @214_5d18a0
  X0[2] = 0;  // @215_5d18a0
  X0[3] = 0;  // @216_5d18a0
  PV[40] = (u32)(ecx);  // @217_5d18a0
  ecx = esi;  // @218_5d18a0
  PV[41] = X0[0];  // @219_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[41]);  // @220_5d18a0
  ecx = edx = 0;  // @221_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @222_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2801) + 0), 4); v; });  // @223_5d18a0
  X0[1] = 0;  // @224_5d18a0
  X0[2] = 0;  // @225_5d18a0
  X0[3] = 0;  // @226_5d18a0
  PV[42] = (u32)(ecx);  // @227_5d18a0
  ecx = esi;  // @228_5d18a0
  PV[43] = X0[0];  // @229_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[43]);  // @230_5d18a0
  ecx = edx = 0;  // @231_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @232_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2805) + 0), 4); v; });  // @233_5d18a0
  X0[1] = 0;  // @234_5d18a0
  X0[2] = 0;  // @235_5d18a0
  X0[3] = 0;  // @236_5d18a0
  PV[44] = (u32)(ecx);  // @237_5d18a0
  ecx = esi;  // @238_5d18a0
  PV[45] = X0[0];  // @239_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[45]);  // @240_5d18a0
  ecx = edx = 0;  // @241_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2809) + 0), 4); v; });  // @243_5d18a0
  X0[1] = 0;  // @244_5d18a0
  X0[2] = 0;  // @245_5d18a0
  X0[3] = 0;  // @246_5d18a0
  PV[46] = (u32)(ecx);  // @247_5d18a0
  ecx = esi;  // @248_5d18a0
  PV[47] = X0[0];  // @249_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[47]);  // @250_5d18a0
  ecx = edx = 0;  // @251_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @252_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2813) + 0), 4); v; });  // @253_5d18a0
  X0[1] = 0;  // @254_5d18a0
  X0[2] = 0;  // @255_5d18a0
  X0[3] = 0;  // @256_5d18a0
  PV[48] = (u32)(ecx);  // @257_5d18a0
  ecx = esi;  // @258_5d18a0
  PV[49] = X0[0];  // @259_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[49]);  // @260_5d18a0
  ecx = edx = 0;  // @261_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @262_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2817) + 0), 4); v; });  // @263_5d18a0
  X0[1] = 0;  // @264_5d18a0
  X0[2] = 0;  // @265_5d18a0
  X0[3] = 0;  // @266_5d18a0
  PV[50] = (u32)(ecx);  // @267_5d18a0
  ecx = esi;  // @268_5d18a0
  PV[51] = X0[0];  // @269_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[51]);  // @270_5d18a0
  ecx = edx = 0;  // @271_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @272_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2821) + 0), 4); v; });  // @273_5d18a0
  X0[1] = 0;  // @274_5d18a0
  X0[2] = 0;  // @275_5d18a0
  X0[3] = 0;  // @276_5d18a0
  PV[52] = (u32)(ecx);  // @277_5d18a0
  ecx = esi;  // @278_5d18a0
  PV[53] = X0[0];  // @279_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[53]);  // @280_5d18a0
  ecx = edx = 0;  // @281_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @282_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2825) + 0), 4); v; });  // @283_5d18a0
  X0[1] = 0;  // @284_5d18a0
  X0[2] = 0;  // @285_5d18a0
  X0[3] = 0;  // @286_5d18a0
  PV[54] = (u32)(ecx);  // @287_5d18a0
  ecx = esi;  // @288_5d18a0
  PV[55] = X0[0];  // @289_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[55]);  // @290_5d18a0
  ecx = edx = 0;  // @291_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @292_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2829) + 0), 4); v; });  // @293_5d18a0
  X0[1] = 0;  // @294_5d18a0
  X0[2] = 0;  // @295_5d18a0
  X0[3] = 0;  // @296_5d18a0
  PV[56] = (u32)(ecx);  // @297_5d18a0
  ecx = esi;  // @298_5d18a0
  PV[57] = X0[0];  // @299_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[57]);  // @300_5d18a0
  ecx = edx = 0;  // @301_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @302_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2833) + 0), 4); v; });  // @303_5d18a0
  X0[1] = 0;  // @304_5d18a0
  X0[2] = 0;  // @305_5d18a0
  X0[3] = 0;  // @306_5d18a0
  PV[58] = (u32)(ecx);  // @307_5d18a0
  ecx = esi;  // @308_5d18a0
  PV[59] = X0[0];  // @309_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[59]);  // @310_5d18a0
  ecx = edx = 0;  // @311_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @312_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2837) + 0), 4); v; });  // @313_5d18a0
  X0[1] = 0;  // @314_5d18a0
  X0[2] = 0;  // @315_5d18a0
  X0[3] = 0;  // @316_5d18a0
  PV[60] = (u32)(ecx);  // @317_5d18a0
  ecx = esi;  // @318_5d18a0
  PV[61] = X0[0];  // @319_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[61]);  // @320_5d18a0
  ecx = edx = 0;  // @321_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @322_5d18a0
  ecx = esi;  // @323_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2841), sizeof v); (u32)v; });  // @324_5d18a0
  PV[62] = (u32)(eax);  // @325_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[62]);  // @326_5d18a0
  ecx = edx = 0;  // @327_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @328_5d18a0
  ecx = esi;  // @329_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2842), sizeof v); (u32)v; });  // @330_5d18a0
  PV[63] = (u32)(eax);  // @331_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[63]);  // @332_5d18a0
  ecx = edx = 0;  // @333_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @334_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2847) + 0), 4); v; });  // @335_5d18a0
  X0[1] = 0;  // @336_5d18a0
  X0[2] = 0;  // @337_5d18a0
  X0[3] = 0;  // @338_5d18a0
  PV[64] = (u32)(ecx);  // @339_5d18a0
  ecx = esi;  // @340_5d18a0
  PV[65] = X0[0];  // @341_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[65]);  // @342_5d18a0
  ecx = edx = 0;  // @343_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @344_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2851) + 0), 4); v; });  // @345_5d18a0
  X0[1] = 0;  // @346_5d18a0
  X0[2] = 0;  // @347_5d18a0
  X0[3] = 0;  // @348_5d18a0
  PV[66] = (u32)(ecx);  // @349_5d18a0
  ecx = esi;  // @350_5d18a0
  PV[67] = X0[0];  // @351_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[67]);  // @352_5d18a0
  ecx = edx = 0;  // @353_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @354_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2855) + 0), 4); v; });  // @355_5d18a0
  X0[1] = 0;  // @356_5d18a0
  X0[2] = 0;  // @357_5d18a0
  X0[3] = 0;  // @358_5d18a0
  PV[68] = (u32)(ecx);  // @359_5d18a0
  ecx = esi;  // @360_5d18a0
  PV[69] = X0[0];  // @361_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[69]);  // @362_5d18a0
  ecx = edx = 0;  // @363_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @364_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2859) + 0), 4); v; });  // @365_5d18a0
  X0[1] = 0;  // @366_5d18a0
  X0[2] = 0;  // @367_5d18a0
  X0[3] = 0;  // @368_5d18a0
  PV[70] = (u32)(ecx);  // @369_5d18a0
  ecx = esi;  // @370_5d18a0
  PV[71] = X0[0];  // @371_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[71]);  // @372_5d18a0
  ecx = edx = 0;  // @373_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @374_5d18a0
  ecx = esi;  // @375_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2863), sizeof v); (u32)v; });  // @376_5d18a0
  PV[72] = (u32)(eax);  // @377_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[72]);  // @378_5d18a0
  ecx = edx = 0;  // @379_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @380_5d18a0
  ecx = esi;  // @381_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2864), sizeof v); (u32)v; });  // @382_5d18a0
  PV[73] = (u32)(eax);  // @383_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[73]);  // @384_5d18a0
  ecx = edx = 0;  // @385_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @386_5d18a0
  ecx = esi;  // @387_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2865), sizeof v); (u32)v; });  // @388_5d18a0
  PV[74] = (u32)(eax);  // @389_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[74]);  // @390_5d18a0
  ecx = edx = 0;  // @391_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @392_5d18a0
  ecx = esi;  // @393_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2866), sizeof v); (u32)v; });  // @394_5d18a0
  PV[75] = (u32)(eax);  // @395_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[75]);  // @396_5d18a0
  ecx = edx = 0;  // @397_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @398_5d18a0
  ecx = esi;  // @399_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2867), sizeof v); (u32)v; });  // @400_5d18a0
  PV[76] = (u32)(eax);  // @401_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[76]);  // @402_5d18a0
  ecx = edx = 0;  // @403_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @404_5d18a0
  ecx = esi;  // @405_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2868), sizeof v); (u32)v; });  // @406_5d18a0
  PV[77] = (u32)(eax);  // @407_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[77]);  // @408_5d18a0
  ecx = edx = 0;  // @409_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @410_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2869) + 0), 4); v; });  // @411_5d18a0
  X0[1] = 0;  // @412_5d18a0
  X0[2] = 0;  // @413_5d18a0
  X0[3] = 0;  // @414_5d18a0
  PV[78] = (u32)(ecx);  // @415_5d18a0
  ecx = esi;  // @416_5d18a0
  PV[79] = X0[0];  // @417_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[79]);  // @418_5d18a0
  ecx = edx = 0;  // @419_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @420_5d18a0
  eax = (u32)(edi + 2873);  // @421_5d18a0
  PV[80] = (u32)(eax);  // @422_5d18a0
  ecx = esi;  // @423_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[80]);  // @424_5d18a0
  ecx = edx = 0;  // @425_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @426_5d18a0
  ecx = esi;  // @427_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2885), sizeof v); (u32)v; });  // @428_5d18a0
  PV[81] = (u32)(eax);  // @429_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[81]);  // @430_5d18a0
  ecx = edx = 0;  // @431_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @432_5d18a0
  ecx = esi;  // @433_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2887), sizeof v); (u32)v; });  // @434_5d18a0
  PV[82] = (u32)(eax);  // @435_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[82]);  // @436_5d18a0
  ecx = edx = 0;  // @437_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @438_5d18a0
  ecx = esi;  // @439_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2888), sizeof v); (u32)v; });  // @440_5d18a0
  PV[83] = (u32)(eax);  // @441_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[83]);  // @442_5d18a0
  ecx = edx = 0;  // @443_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @444_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2889) + 0), 4); v; });  // @445_5d18a0
  X0[1] = 0;  // @446_5d18a0
  X0[2] = 0;  // @447_5d18a0
  X0[3] = 0;  // @448_5d18a0
  PV[84] = (u32)(ecx);  // @449_5d18a0
  ecx = esi;  // @450_5d18a0
  PV[85] = X0[0];  // @451_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[85]);  // @452_5d18a0
  ecx = edx = 0;  // @453_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @454_5d18a0
  ecx = esi;  // @455_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2893), sizeof v); (u32)v; });  // @456_5d18a0
  PV[86] = (u32)(eax);  // @457_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[86]);  // @458_5d18a0
  ecx = edx = 0;  // @459_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @460_5d18a0
  ecx = esi;  // @461_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2895), sizeof v); (u32)v; });  // @462_5d18a0
  PV[87] = (u32)(eax);  // @463_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[87]);  // @464_5d18a0
  ecx = edx = 0;  // @465_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @466_5d18a0
  ecx = esi;  // @467_5d18a0
  PV[88] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2896), sizeof v); (u32)v; });  // @468_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[88]);  // @469_5d18a0
  ecx = edx = 0;  // @470_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @471_5d18a0
  ecx = esi;  // @472_5d18a0
  PV[89] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3181), sizeof v); (u32)v; });  // @473_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[89]);  // @474_5d18a0
  ecx = edx = 0;  // @475_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @476_5d18a0
  eax = (u32)(edi + 3185);  // @477_5d18a0
  ecx = esi;  // @478_5d18a0
  PV[90] = (u32)(eax);  // @479_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[90]);  // @480_5d18a0
  ecx = edx = 0;  // @481_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @482_5d18a0
  eax = (u32)(edi + 3197);  // @483_5d18a0
  PV[91] = (u32)(eax);  // @484_5d18a0
  ecx = esi;  // @485_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[91]);  // @486_5d18a0
  ecx = edx = 0;  // @487_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @488_5d18a0
  eax = (u32)(edi + 3209);  // @489_5d18a0
  PV[92] = (u32)(eax);  // @490_5d18a0
  ecx = esi;  // @491_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[92]);  // @492_5d18a0
  ecx = edx = 0;  // @493_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @494_5d18a0
  eax = (u32)(edi + 3245);  // @495_5d18a0
  PV[93] = (u32)(eax);  // @496_5d18a0
  ecx = esi;  // @497_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[93]);  // @498_5d18a0
  ecx = edx = 0;  // @499_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @500_5d18a0
  eax = (u32)(edi + 3257);  // @501_5d18a0
  PV[94] = (u32)(eax);  // @502_5d18a0
  ecx = esi;  // @503_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[94]);  // @504_5d18a0
  ecx = edx = 0;  // @505_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @506_5d18a0
  eax = (u32)(edi + 3293);  // @507_5d18a0
  PV[95] = (u32)(eax);  // @508_5d18a0
  ecx = esi;  // @509_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[95]);  // @510_5d18a0
  ecx = edx = 0;  // @511_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @512_5d18a0
  eax = (u32)(edi + 3329);  // @513_5d18a0
  PV[96] = (u32)(eax);  // @514_5d18a0
  ecx = esi;  // @515_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[96]);  // @516_5d18a0
  ecx = edx = 0;  // @517_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @518_5d18a0
  ecx = esi;  // @519_5d18a0
  PV[97] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3341), sizeof v); (u32)v; });  // @520_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[97]);  // @521_5d18a0
  ecx = edx = 0;  // @522_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @523_5d18a0
  ecx = esi;  // @524_5d18a0
  PV[98] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3345), sizeof v); (u32)v; });  // @525_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[98]);  // @526_5d18a0
  ecx = edx = 0;  // @527_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @528_5d18a0
  eax = (u32)(edi + 3349);  // @529_5d18a0
  PV[99] = (u32)(eax);  // @530_5d18a0
  ecx = esi;  // @531_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[99]);  // @532_5d18a0
  ecx = edx = 0;  // @533_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @534_5d18a0
  ecx = esi;  // @535_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3361), sizeof v); (u32)v; });  // @536_5d18a0
  PV[100] = (u32)(eax);  // @537_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[100]);  // @538_5d18a0
  ecx = edx = 0;  // @539_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @540_5d18a0
  eax = (u32)(edi + 3362);  // @541_5d18a0
  PV[101] = (u32)(eax);  // @542_5d18a0
  ecx = esi;  // @543_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[101]);  // @544_5d18a0
  ecx = edx = 0;  // @545_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @546_5d18a0
  ecx = esi;  // @547_5d18a0
  PV[102] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3374), sizeof v); (u32)v; });  // @548_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[102]);  // @549_5d18a0
  ecx = edx = 0;  // @550_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @551_5d18a0
  ecx = esi;  // @552_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3378), sizeof v); (u32)v; });  // @553_5d18a0
  PV[103] = (u32)(eax);  // @554_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[103]);  // @555_5d18a0
  ecx = edx = 0;  // @556_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @557_5d18a0
  ecx = esi;  // @558_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3379), sizeof v); (u32)v; });  // @559_5d18a0
  PV[104] = (u32)(eax);  // @560_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[104]);  // @561_5d18a0
  ecx = edx = 0;  // @562_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @563_5d18a0
  ecx = esi;  // @564_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3380), sizeof v); (u32)v; });  // @565_5d18a0
  PV[105] = (u32)(eax);  // @566_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[105]);  // @567_5d18a0
  ecx = edx = 0;  // @568_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @569_5d18a0
  ecx = esi;  // @570_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3381), sizeof v); (u32)v; });  // @571_5d18a0
  PV[106] = (u32)(eax);  // @572_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[106]);  // @573_5d18a0
  ecx = edx = 0;  // @574_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @575_5d18a0
  ecx = esi;  // @576_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3544), sizeof v); (u32)v; });  // @577_5d18a0
  PV[107] = (u32)(eax);  // @578_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[107]);  // @579_5d18a0
  ecx = edx = 0;  // @580_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @581_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3573) + 0), 4); v; });  // @582_5d18a0
  X0[1] = 0;  // @583_5d18a0
  X0[2] = 0;  // @584_5d18a0
  X0[3] = 0;  // @585_5d18a0
  PV[108] = (u32)(ecx);  // @586_5d18a0
  ecx = esi;  // @587_5d18a0
  PV[109] = X0[0];  // @588_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[109]);  // @589_5d18a0
  ecx = edx = 0;  // @590_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @591_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3577) + 0), 4); v; });  // @592_5d18a0
  X0[1] = 0;  // @593_5d18a0
  X0[2] = 0;  // @594_5d18a0
  X0[3] = 0;  // @595_5d18a0
  PV[110] = (u32)(ecx);  // @596_5d18a0
  ecx = esi;  // @597_5d18a0
  PV[111] = X0[0];  // @598_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[111]);  // @599_5d18a0
  ecx = edx = 0;  // @600_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @601_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3581) + 0), 4); v; });  // @602_5d18a0
  X0[1] = 0;  // @603_5d18a0
  X0[2] = 0;  // @604_5d18a0
  X0[3] = 0;  // @605_5d18a0
  PV[112] = (u32)(ecx);  // @606_5d18a0
  ecx = esi;  // @607_5d18a0
  PV[113] = X0[0];  // @608_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[113]);  // @609_5d18a0
  ecx = edx = 0;  // @610_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @611_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3585) + 0), 4); v; });  // @612_5d18a0
  X0[1] = 0;  // @613_5d18a0
  X0[2] = 0;  // @614_5d18a0
  X0[3] = 0;  // @615_5d18a0
  PV[114] = (u32)(ecx);  // @616_5d18a0
  ecx = esi;  // @617_5d18a0
  PV[115] = X0[0];  // @618_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[115]);  // @619_5d18a0
  ecx = edx = 0;  // @620_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @621_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3589) + 0), 4); v; });  // @622_5d18a0
  X0[1] = 0;  // @623_5d18a0
  X0[2] = 0;  // @624_5d18a0
  X0[3] = 0;  // @625_5d18a0
  PV[116] = (u32)(ecx);  // @626_5d18a0
  ecx = esi;  // @627_5d18a0
  PV[117] = X0[0];  // @628_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[117]);  // @629_5d18a0
  ecx = edx = 0;  // @630_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @631_5d18a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3593) + 0), 4); v; });  // @632_5d18a0
  X0[1] = 0;  // @633_5d18a0
  X0[2] = 0;  // @634_5d18a0
  X0[3] = 0;  // @635_5d18a0
  PV[118] = (u32)(ecx);  // @636_5d18a0
  ecx = esi;  // @637_5d18a0
  PV[119] = X0[0];  // @638_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[119]);  // @639_5d18a0
  ecx = edx = 0;  // @640_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @641_5d18a0
  ecx = esi;  // @642_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3597), sizeof v); (u32)v; });  // @643_5d18a0
  PV[120] = (u32)(eax);  // @644_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[120]);  // @645_5d18a0
  ecx = edx = 0;  // @646_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @647_5d18a0
  ecx = esi;  // @648_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3598), sizeof v); (u32)v; });  // @649_5d18a0
  PV[121] = (u32)(eax);  // @650_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[121]);  // @651_5d18a0
  ecx = edx = 0;  // @652_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @653_5d18a0
  ecx = esi;  // @654_5d18a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3607), sizeof v); (u32)v; });  // @655_5d18a0
  PV[122] = (u32)(eax);  // @656_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[122]);  // @657_5d18a0
  ecx = edx = 0;  // @658_5d18a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @659_5d18a0
  ecx = esi;  // @660_5d18a0
  PV[123] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3608), sizeof v); (u32)v; });  // @661_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[123]);  // @662_5d18a0
  ecx = edx = 0;  // @663_5d18a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @664_5d18a0
  ecx = esi;  // @665_5d18a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3612), sizeof v); (u32)v; });  // @666_5d18a0
  PV[124] = (u32)(eax);  // @667_5d18a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[124]);  // @668_5d18a0
  ecx = edx = 0;  // @669_5d18a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @670_5d18a0
  return eax;  // @671_5d18a0
}
PCREG(5d18a0, lifted_5d18a0);

