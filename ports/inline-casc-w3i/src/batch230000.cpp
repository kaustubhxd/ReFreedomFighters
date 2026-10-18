// batch230000.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5d0600(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[96], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5d0600
  edi = ecx;  // @1_5d0600
  ecx = (u32)(EBP - 8);  // @2_5d0600
  PV[0] = (u32)(ecx);  // @3_5d0600
  ecx = esi;  // @4_5d0600
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @5_5d0600
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @6_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[0]);  // @8_5d0600
  ecx = edx = 0;  // @9_5d0600
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @10_5d0600
  X1[1] = 0;  // @11_5d0600
  X1[2] = 0;  // @12_5d0600
  X1[3] = 0;  // @13_5d0600
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @14_5d0600
  X0[1] = 0;  // @15_5d0600
  X0[2] = 0;  // @16_5d0600
  X0[3] = 0;  // @17_5d0600
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; })))) && !(!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; }))))))) goto L5d063f;  // @18_5d0600
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000628) + 0), 4); v; });  // @19_5d0600
  X2[1] = 0;  // @20_5d0600
  X2[2] = 0;  // @21_5d0600
  X2[3] = 0;  // @22_5d0600
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L5d0642;  // @23_5d0600
  L5d063f:;
  X1[0] = X0[0];  // @25_5d0600
  X1[1] = X0[1];  // @26_5d0600
  X1[2] = X0[2];  // @27_5d0600
  X1[3] = X0[3];  // @28_5d0600
  L5d0642:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_5d0600
  ecx = (u32)(EBP - 8);  // @31_5d0600
  PV[1] = (u32)(ecx);  // @32_5d0600
  ecx = esi;  // @33_5d0600
  __builtin_memcpy((void *)((u32)(edi + 2644) + 0), &X1[0], 4);  // @34_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[1]);  // @35_5d0600
  ecx = edx = 0;  // @36_5d0600
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @37_5d0600
  X0[1] = 0;  // @38_5d0600
  X0[2] = 0;  // @39_5d0600
  X0[3] = 0;  // @40_5d0600
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; }))))))) goto L5d0670;  // @41_5d0600
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000628) + 0), 4); v; });  // @42_5d0600
  X1[1] = 0;  // @43_5d0600
  X1[2] = 0;  // @44_5d0600
  X1[3] = 0;  // @45_5d0600
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L5d0678;  // @46_5d0600
  L5d0670:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @48_5d0600
  X0[1] = 0;  // @49_5d0600
  X0[2] = 0;  // @50_5d0600
  X0[3] = 0;  // @51_5d0600
  L5d0678:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_5d0600
  eax = (u32)(edi + 2652);  // @54_5d0600
  PV[2] = (u32)(eax);  // @55_5d0600
  ecx = esi;  // @56_5d0600
  __builtin_memcpy((void *)((u32)(edi + 2648) + 0), &X0[0], 4);  // @57_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[2]);  // @58_5d0600
  ecx = edx = 0;  // @59_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_5d0600
  eax = (u32)(edi + 2656);  // @61_5d0600
  PV[3] = (u32)(eax);  // @62_5d0600
  ecx = esi;  // @63_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[3]);  // @64_5d0600
  ecx = edx = 0;  // @65_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_5d0600
  eax = (u32)(edi + 2660);  // @67_5d0600
  PV[4] = (u32)(eax);  // @68_5d0600
  ecx = esi;  // @69_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[4]);  // @70_5d0600
  ecx = edx = 0;  // @71_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_5d0600
  eax = (u32)(edi + 2664);  // @73_5d0600
  PV[5] = (u32)(eax);  // @74_5d0600
  ecx = esi;  // @75_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[5]);  // @76_5d0600
  ecx = edx = 0;  // @77_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @78_5d0600
  eax = (u32)(edi + 2668);  // @79_5d0600
  PV[6] = (u32)(eax);  // @80_5d0600
  ecx = esi;  // @81_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[6]);  // @82_5d0600
  ecx = edx = 0;  // @83_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_5d0600
  eax = (u32)(edi + 2672);  // @85_5d0600
  PV[7] = (u32)(eax);  // @86_5d0600
  ecx = esi;  // @87_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[7]);  // @88_5d0600
  ecx = edx = 0;  // @89_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_5d0600
  eax = (u32)(edi + 2673);  // @91_5d0600
  PV[8] = (u32)(eax);  // @92_5d0600
  ecx = esi;  // @93_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[8]);  // @94_5d0600
  ecx = edx = 0;  // @95_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @96_5d0600
  eax = (u32)(edi + 2674);  // @97_5d0600
  PV[9] = (u32)(eax);  // @98_5d0600
  ecx = esi;  // @99_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[9]);  // @100_5d0600
  ecx = edx = 0;  // @101_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_5d0600
  eax = (u32)(edi + 2686);  // @103_5d0600
  PV[10] = (u32)(eax);  // @104_5d0600
  ecx = esi;  // @105_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[10]);  // @106_5d0600
  ecx = edx = 0;  // @107_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_5d0600
  eax = (u32)(edi + 2698);  // @109_5d0600
  PV[11] = (u32)(eax);  // @110_5d0600
  ecx = esi;  // @111_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[11]);  // @112_5d0600
  ecx = edx = 0;  // @113_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_5d0600
  eax = (u32)(edi + 2710);  // @115_5d0600
  PV[12] = (u32)(eax);  // @116_5d0600
  ecx = esi;  // @117_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[12]);  // @118_5d0600
  ecx = edx = 0;  // @119_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @120_5d0600
  eax = (u32)(edi + 2714);  // @121_5d0600
  PV[13] = (u32)(eax);  // @122_5d0600
  ecx = esi;  // @123_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[13]);  // @124_5d0600
  ecx = edx = 0;  // @125_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @126_5d0600
  eax = (u32)(edi + 2718);  // @127_5d0600
  PV[14] = (u32)(eax);  // @128_5d0600
  ecx = esi;  // @129_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[14]);  // @130_5d0600
  ecx = edx = 0;  // @131_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_5d0600
  eax = (u32)(edi + 2722);  // @133_5d0600
  PV[15] = (u32)(eax);  // @134_5d0600
  ecx = esi;  // @135_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[15]);  // @136_5d0600
  ecx = edx = 0;  // @137_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_5d0600
  eax = (u32)(edi + 2734);  // @139_5d0600
  PV[16] = (u32)(eax);  // @140_5d0600
  ecx = esi;  // @141_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[16]);  // @142_5d0600
  ecx = edx = 0;  // @143_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_5d0600
  eax = (u32)(edi + 2742);  // @145_5d0600
  PV[17] = (u32)(eax);  // @146_5d0600
  ecx = esi;  // @147_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[17]);  // @148_5d0600
  ecx = edx = 0;  // @149_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @150_5d0600
  ecx = (u32)(EBP + 8);  // @151_5d0600
  PV[18] = (u32)(ecx);  // @152_5d0600
  ecx = esi;  // @153_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[18]);  // @154_5d0600
  ecx = edx = 0;  // @155_5d0600
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @156_5d0600
  ecx = esi;  // @157_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2773), &v, sizeof v); }  // @158_5d0600
  eax = (u32)(edi + 2777);  // @159_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_5d0600
  PV[19] = (u32)(eax);  // @161_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[19]);  // @162_5d0600
  ecx = edx = 0;  // @163_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @164_5d0600
  eax = (u32)(edi + 2781);  // @165_5d0600
  PV[20] = (u32)(eax);  // @166_5d0600
  ecx = esi;  // @167_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[20]);  // @168_5d0600
  ecx = edx = 0;  // @169_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @170_5d0600
  eax = (u32)(edi + 2772);  // @171_5d0600
  PV[21] = (u32)(eax);  // @172_5d0600
  ecx = esi;  // @173_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[21]);  // @174_5d0600
  ecx = edx = 0;  // @175_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @176_5d0600
  eax = (u32)(edi + 2785);  // @177_5d0600
  PV[22] = (u32)(eax);  // @178_5d0600
  ecx = esi;  // @179_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[22]);  // @180_5d0600
  ecx = edx = 0;  // @181_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @182_5d0600
  ecx = (u32)(EBP - 12);  // @183_5d0600
  PV[23] = (u32)(ecx);  // @184_5d0600
  ecx = esi;  // @185_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[23]);  // @186_5d0600
  ecx = edx = 0;  // @187_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_5d0600
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @189_5d0600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @190_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @191_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[24]);  // @192_5d0600
  ecx = edx = 0;  // @193_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2789), &v, sizeof v); }  // @194_5d0600
  ecx = (u32)(EBP - 8);  // @195_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @196_5d0600
  PV[25] = (u32)(ecx);  // @197_5d0600
  ecx = esi;  // @198_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[25]);  // @199_5d0600
  ecx = edx = 0;  // @200_5d0600
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @201_5d0600
  X1[1] = 0;  // @202_5d0600
  X1[2] = 0;  // @203_5d0600
  X1[3] = 0;  // @204_5d0600
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000572) + 0), 4); v; }))))))) goto L5d07f4;  // @205_5d0600
  L5d07ea:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @207_5d0600
  X0[1] = 0;  // @208_5d0600
  X0[2] = 0;  // @209_5d0600
  X0[3] = 0;  // @210_5d0600
  goto L5d0804;  // @211_5d0600
  L5d07f4:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000628) + 0), 4); v; });  // @213_5d0600
  X0[1] = 0;  // @214_5d0600
  X0[2] = 0;  // @215_5d0600
  X0[3] = 0;  // @216_5d0600
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5d07ea;  // @217_5d0600
  X0[0] = X1[0];  // @218_5d0600
  X0[1] = X1[1];  // @219_5d0600
  X0[2] = X1[2];  // @220_5d0600
  X0[3] = X1[3];  // @221_5d0600
  L5d0804:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @223_5d0600
  eax = (u32)(edi + 2797);  // @224_5d0600
  PV[26] = (u32)(eax);  // @225_5d0600
  ecx = esi;  // @226_5d0600
  __builtin_memcpy((void *)((u32)(edi + 2793) + 0), &X0[0], 4);  // @227_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[26]);  // @228_5d0600
  ecx = edx = 0;  // @229_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @230_5d0600
  eax = (u32)(edi + 2801);  // @231_5d0600
  PV[27] = (u32)(eax);  // @232_5d0600
  ecx = esi;  // @233_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[27]);  // @234_5d0600
  ecx = edx = 0;  // @235_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @236_5d0600
  eax = (u32)(edi + 2805);  // @237_5d0600
  PV[28] = (u32)(eax);  // @238_5d0600
  ecx = esi;  // @239_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[28]);  // @240_5d0600
  ecx = edx = 0;  // @241_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_5d0600
  eax = (u32)(edi + 2809);  // @243_5d0600
  PV[29] = (u32)(eax);  // @244_5d0600
  ecx = esi;  // @245_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[29]);  // @246_5d0600
  ecx = edx = 0;  // @247_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @248_5d0600
  eax = (u32)(edi + 2813);  // @249_5d0600
  PV[30] = (u32)(eax);  // @250_5d0600
  ecx = esi;  // @251_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[30]);  // @252_5d0600
  ecx = edx = 0;  // @253_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @254_5d0600
  eax = (u32)(edi + 2817);  // @255_5d0600
  PV[31] = (u32)(eax);  // @256_5d0600
  ecx = esi;  // @257_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[31]);  // @258_5d0600
  ecx = edx = 0;  // @259_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @260_5d0600
  eax = (u32)(edi + 2821);  // @261_5d0600
  PV[32] = (u32)(eax);  // @262_5d0600
  ecx = esi;  // @263_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[32]);  // @264_5d0600
  ecx = edx = 0;  // @265_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @266_5d0600
  eax = (u32)(edi + 2825);  // @267_5d0600
  PV[33] = (u32)(eax);  // @268_5d0600
  ecx = esi;  // @269_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[33]);  // @270_5d0600
  ecx = edx = 0;  // @271_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @272_5d0600
  eax = (u32)(edi + 2829);  // @273_5d0600
  PV[34] = (u32)(eax);  // @274_5d0600
  ecx = esi;  // @275_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[34]);  // @276_5d0600
  ecx = edx = 0;  // @277_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @278_5d0600
  eax = (u32)(edi + 2833);  // @279_5d0600
  PV[35] = (u32)(eax);  // @280_5d0600
  ecx = esi;  // @281_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[35]);  // @282_5d0600
  ecx = edx = 0;  // @283_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @284_5d0600
  eax = (u32)(edi + 2837);  // @285_5d0600
  PV[36] = (u32)(eax);  // @286_5d0600
  ecx = esi;  // @287_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[36]);  // @288_5d0600
  ecx = edx = 0;  // @289_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @290_5d0600
  eax = (u32)(edi + 2841);  // @291_5d0600
  PV[37] = (u32)(eax);  // @292_5d0600
  ecx = esi;  // @293_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[37]);  // @294_5d0600
  ecx = edx = 0;  // @295_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @296_5d0600
  eax = (u32)(edi + 2842);  // @297_5d0600
  PV[38] = (u32)(eax);  // @298_5d0600
  ecx = esi;  // @299_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[38]);  // @300_5d0600
  ecx = edx = 0;  // @301_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @302_5d0600
  eax = (u32)(edi + 2847);  // @303_5d0600
  PV[39] = (u32)(eax);  // @304_5d0600
  ecx = esi;  // @305_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[39]);  // @306_5d0600
  ecx = edx = 0;  // @307_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @308_5d0600
  eax = (u32)(edi + 2851);  // @309_5d0600
  PV[40] = (u32)(eax);  // @310_5d0600
  ecx = esi;  // @311_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[40]);  // @312_5d0600
  ecx = edx = 0;  // @313_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @314_5d0600
  eax = (u32)(edi + 2855);  // @315_5d0600
  PV[41] = (u32)(eax);  // @316_5d0600
  ecx = esi;  // @317_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[41]);  // @318_5d0600
  ecx = edx = 0;  // @319_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @320_5d0600
  eax = (u32)(edi + 2859);  // @321_5d0600
  PV[42] = (u32)(eax);  // @322_5d0600
  ecx = esi;  // @323_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[42]);  // @324_5d0600
  ecx = edx = 0;  // @325_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_5d0600
  eax = (u32)(edi + 2863);  // @327_5d0600
  PV[43] = (u32)(eax);  // @328_5d0600
  ecx = esi;  // @329_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[43]);  // @330_5d0600
  ecx = edx = 0;  // @331_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @332_5d0600
  eax = (u32)(edi + 2864);  // @333_5d0600
  PV[44] = (u32)(eax);  // @334_5d0600
  ecx = esi;  // @335_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[44]);  // @336_5d0600
  ecx = edx = 0;  // @337_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @338_5d0600
  eax = (u32)(edi + 2865);  // @339_5d0600
  PV[45] = (u32)(eax);  // @340_5d0600
  ecx = esi;  // @341_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[45]);  // @342_5d0600
  ecx = edx = 0;  // @343_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @344_5d0600
  eax = (u32)(edi + 2866);  // @345_5d0600
  PV[46] = (u32)(eax);  // @346_5d0600
  ecx = esi;  // @347_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[46]);  // @348_5d0600
  ecx = edx = 0;  // @349_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @350_5d0600
  eax = (u32)(edi + 2867);  // @351_5d0600
  PV[47] = (u32)(eax);  // @352_5d0600
  ecx = esi;  // @353_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[47]);  // @354_5d0600
  ecx = edx = 0;  // @355_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @356_5d0600
  eax = (u32)(edi + 2868);  // @357_5d0600
  PV[48] = (u32)(eax);  // @358_5d0600
  ecx = esi;  // @359_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[48]);  // @360_5d0600
  ecx = edx = 0;  // @361_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @362_5d0600
  eax = (u32)(edi + 2869);  // @363_5d0600
  PV[49] = (u32)(eax);  // @364_5d0600
  ecx = esi;  // @365_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[49]);  // @366_5d0600
  ecx = edx = 0;  // @367_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @368_5d0600
  eax = (u32)(edi + 2873);  // @369_5d0600
  PV[50] = (u32)(eax);  // @370_5d0600
  ecx = esi;  // @371_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[50]);  // @372_5d0600
  ecx = edx = 0;  // @373_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @374_5d0600
  eax = (u32)(edi + 2885);  // @375_5d0600
  PV[51] = (u32)(eax);  // @376_5d0600
  ecx = esi;  // @377_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[51]);  // @378_5d0600
  ecx = edx = 0;  // @379_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @380_5d0600
  eax = (u32)(edi + 2887);  // @381_5d0600
  PV[52] = (u32)(eax);  // @382_5d0600
  ecx = esi;  // @383_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[52]);  // @384_5d0600
  ecx = edx = 0;  // @385_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @386_5d0600
  eax = (u32)(edi + 2888);  // @387_5d0600
  PV[53] = (u32)(eax);  // @388_5d0600
  ecx = esi;  // @389_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[53]);  // @390_5d0600
  ecx = edx = 0;  // @391_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @392_5d0600
  eax = (u32)(edi + 2889);  // @393_5d0600
  PV[54] = (u32)(eax);  // @394_5d0600
  ecx = esi;  // @395_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[54]);  // @396_5d0600
  ecx = edx = 0;  // @397_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @398_5d0600
  eax = (u32)(edi + 2893);  // @399_5d0600
  PV[55] = (u32)(eax);  // @400_5d0600
  ecx = esi;  // @401_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[55]);  // @402_5d0600
  ecx = edx = 0;  // @403_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @404_5d0600
  eax = (u32)(edi + 2895);  // @405_5d0600
  PV[56] = (u32)(eax);  // @406_5d0600
  ecx = esi;  // @407_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[56]);  // @408_5d0600
  ecx = edx = 0;  // @409_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @410_5d0600
  ecx = (u32)(EBP - 16);  // @411_5d0600
  PV[57] = (u32)(ecx);  // @412_5d0600
  ecx = esi;  // @413_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[57]);  // @414_5d0600
  ecx = edx = 0;  // @415_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @416_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2896), &v, sizeof v); }  // @417_5d0600
  ecx = esi;  // @418_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @419_5d0600
  eax = (u32)(edi + 3181);  // @420_5d0600
  PV[58] = (u32)(eax);  // @421_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[58]);  // @422_5d0600
  ecx = edx = 0;  // @423_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @424_5d0600
  eax = (u32)(edi + 3185);  // @425_5d0600
  PV[59] = (u32)(eax);  // @426_5d0600
  ecx = esi;  // @427_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[59]);  // @428_5d0600
  ecx = edx = 0;  // @429_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @430_5d0600
  eax = (u32)(edi + 3197);  // @431_5d0600
  PV[60] = (u32)(eax);  // @432_5d0600
  ecx = esi;  // @433_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[60]);  // @434_5d0600
  ecx = edx = 0;  // @435_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @436_5d0600
  eax = (u32)(edi + 3209);  // @437_5d0600
  PV[61] = (u32)(eax);  // @438_5d0600
  ecx = esi;  // @439_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, PV[61]);  // @440_5d0600
  ecx = edx = 0;  // @441_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @442_5d0600
  eax = (u32)(edi + 3245);  // @443_5d0600
  PV[62] = (u32)(eax);  // @444_5d0600
  ecx = esi;  // @445_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[62]);  // @446_5d0600
  ecx = edx = 0;  // @447_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @448_5d0600
  eax = (u32)(edi + 3257);  // @449_5d0600
  PV[63] = (u32)(eax);  // @450_5d0600
  ecx = esi;  // @451_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, PV[63]);  // @452_5d0600
  ecx = edx = 0;  // @453_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @454_5d0600
  eax = (u32)(edi + 3293);  // @455_5d0600
  PV[64] = (u32)(eax);  // @456_5d0600
  ecx = esi;  // @457_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, PV[64]);  // @458_5d0600
  ecx = edx = 0;  // @459_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @460_5d0600
  eax = (u32)(edi + 3329);  // @461_5d0600
  PV[65] = (u32)(eax);  // @462_5d0600
  ecx = esi;  // @463_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[65]);  // @464_5d0600
  ecx = edx = 0;  // @465_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @466_5d0600
  eax = (u32)(edi + 3341);  // @467_5d0600
  PV[66] = (u32)(eax);  // @468_5d0600
  ecx = esi;  // @469_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[66]);  // @470_5d0600
  ecx = edx = 0;  // @471_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @472_5d0600
  eax = (u32)(edi + 3345);  // @473_5d0600
  PV[67] = (u32)(eax);  // @474_5d0600
  ecx = esi;  // @475_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[67]);  // @476_5d0600
  ecx = edx = 0;  // @477_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @478_5d0600
  eax = (u32)(edi + 3349);  // @479_5d0600
  PV[68] = (u32)(eax);  // @480_5d0600
  ecx = esi;  // @481_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[68]);  // @482_5d0600
  ecx = edx = 0;  // @483_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @484_5d0600
  eax = (u32)(edi + 3361);  // @485_5d0600
  PV[69] = (u32)(eax);  // @486_5d0600
  ecx = esi;  // @487_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[69]);  // @488_5d0600
  ecx = edx = 0;  // @489_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @490_5d0600
  eax = (u32)(edi + 3362);  // @491_5d0600
  PV[70] = (u32)(eax);  // @492_5d0600
  ecx = esi;  // @493_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[70]);  // @494_5d0600
  ecx = edx = 0;  // @495_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @496_5d0600
  eax = (u32)(edi + 3374);  // @497_5d0600
  PV[71] = (u32)(eax);  // @498_5d0600
  ecx = esi;  // @499_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[71]);  // @500_5d0600
  ecx = edx = 0;  // @501_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @502_5d0600
  eax = (u32)(edi + 3378);  // @503_5d0600
  PV[72] = (u32)(eax);  // @504_5d0600
  ecx = esi;  // @505_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[72]);  // @506_5d0600
  ecx = edx = 0;  // @507_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @508_5d0600
  eax = (u32)(edi + 3379);  // @509_5d0600
  PV[73] = (u32)(eax);  // @510_5d0600
  ecx = esi;  // @511_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[73]);  // @512_5d0600
  ecx = edx = 0;  // @513_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @514_5d0600
  eax = (u32)(edi + 3380);  // @515_5d0600
  PV[74] = (u32)(eax);  // @516_5d0600
  ecx = esi;  // @517_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[74]);  // @518_5d0600
  ecx = edx = 0;  // @519_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @520_5d0600
  eax = (u32)(edi + 3381);  // @521_5d0600
  PV[75] = (u32)(eax);  // @522_5d0600
  ecx = esi;  // @523_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[75]);  // @524_5d0600
  ecx = edx = 0;  // @525_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @526_5d0600
  eax = (u32)(edi + 3544);  // @527_5d0600
  PV[76] = (u32)(eax);  // @528_5d0600
  ecx = esi;  // @529_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[76]);  // @530_5d0600
  ecx = edx = 0;  // @531_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @532_5d0600
  eax = (u32)(edi + 3573);  // @533_5d0600
  PV[77] = (u32)(eax);  // @534_5d0600
  ecx = esi;  // @535_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[77]);  // @536_5d0600
  ecx = edx = 0;  // @537_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @538_5d0600
  eax = (u32)(edi + 3577);  // @539_5d0600
  PV[78] = (u32)(eax);  // @540_5d0600
  ecx = esi;  // @541_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[78]);  // @542_5d0600
  ecx = edx = 0;  // @543_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @544_5d0600
  eax = (u32)(edi + 3581);  // @545_5d0600
  PV[79] = (u32)(eax);  // @546_5d0600
  ecx = esi;  // @547_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[79]);  // @548_5d0600
  ecx = edx = 0;  // @549_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @550_5d0600
  eax = (u32)(edi + 3585);  // @551_5d0600
  PV[80] = (u32)(eax);  // @552_5d0600
  ecx = esi;  // @553_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[80]);  // @554_5d0600
  ecx = edx = 0;  // @555_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @556_5d0600
  eax = (u32)(edi + 3589);  // @557_5d0600
  PV[81] = (u32)(eax);  // @558_5d0600
  ecx = esi;  // @559_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[81]);  // @560_5d0600
  ecx = edx = 0;  // @561_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @562_5d0600
  eax = (u32)(edi + 3593);  // @563_5d0600
  PV[82] = (u32)(eax);  // @564_5d0600
  ecx = esi;  // @565_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[82]);  // @566_5d0600
  ecx = edx = 0;  // @567_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @568_5d0600
  eax = (u32)(edi + 3597);  // @569_5d0600
  PV[83] = (u32)(eax);  // @570_5d0600
  ecx = esi;  // @571_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[83]);  // @572_5d0600
  ecx = edx = 0;  // @573_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @574_5d0600
  eax = (u32)(edi + 3598);  // @575_5d0600
  PV[84] = (u32)(eax);  // @576_5d0600
  ecx = esi;  // @577_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[84]);  // @578_5d0600
  ecx = edx = 0;  // @579_5d0600
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @580_5d0600
  eax = (u32)(edi + 3607);  // @581_5d0600
  PV[85] = (u32)(eax);  // @582_5d0600
  ecx = esi;  // @583_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[85]);  // @584_5d0600
  ecx = edx = 0;  // @585_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @586_5d0600
  ecx = (u32)(EBP - 12);  // @587_5d0600
  PV[86] = (u32)(ecx);  // @588_5d0600
  ecx = esi;  // @589_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[86]);  // @590_5d0600
  ecx = edx = 0;  // @591_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @592_5d0600
  PV[87] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @593_5d0600
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @594_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @595_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[87]);  // @596_5d0600
  ecx = edx = 0;  // @597_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 3608), &v, sizeof v); }  // @598_5d0600
  ecx = (u32)(EBP - 4);  // @599_5d0600
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @600_5d0600
  PV[88] = (u32)(ecx);  // @601_5d0600
  ecx = esi;  // @602_5d0600
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[88]);  // @603_5d0600
  ecx = edx = 0;  // @604_5d0600
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @605_5d0600
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 3612), &v, sizeof v); }  // @606_5d0600
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @607_5d0600
  return eax;  // @608_5d0600
}
PCREG(5d0600, lifted_5d0600);

