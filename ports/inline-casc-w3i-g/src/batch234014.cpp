// batch234014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_5b7c70_thiscall2(u32, u32) __asm__("ext_5b7c70");
extern "C" u32 THISCALL ext_5b7eb0_thiscall2(u32, u32) __asm__("ext_5b7eb0");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5ea470(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[80], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_5ea470
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5ea470
  ecx = edi;  // @2_5ea470
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_5ea470
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @4_5ea470
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @5_5ea470
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8118), sizeof v); (u32)v; });  // @6_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[0]);  // @8_5ea470
  ecx = edx = 0;  // @9_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_5ea470
  ecx = edi;  // @11_5ea470
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8122), sizeof v); (u32)v; });  // @12_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[1]);  // @13_5ea470
  ecx = edx = 0;  // @14_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_5ea470
  ecx = edi;  // @16_5ea470
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8126), sizeof v); (u32)v; });  // @17_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[2]);  // @18_5ea470
  ecx = edx = 0;  // @19_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_5ea470
  ecx = edi;  // @21_5ea470
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7423), sizeof v); (u32)v; });  // @22_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[3]);  // @23_5ea470
  ecx = edx = 0;  // @24_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_5ea470
  ecx = edi;  // @26_5ea470
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8898), sizeof v); (u32)v; });  // @27_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[4]);  // @28_5ea470
  ecx = edx = 0;  // @29_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_5ea470
  ecx = edi;  // @31_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8910), sizeof v); (u32)v; });  // @32_5ea470
  PV[5] = (u32)(eax);  // @33_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[5]);  // @34_5ea470
  ecx = edx = 0;  // @35_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8911) + 0), 4); v; });  // @37_5ea470
  X0[1] = 0;  // @38_5ea470
  X0[2] = 0;  // @39_5ea470
  X0[3] = 0;  // @40_5ea470
  PV[6] = (u32)(ecx);  // @41_5ea470
  ecx = edi;  // @42_5ea470
  PV[7] = X0[0];  // @43_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @44_5ea470
  ecx = edx = 0;  // @45_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_5ea470
  ecx = edi;  // @47_5ea470
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8114), sizeof v); (u32)v; });  // @48_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[8]);  // @49_5ea470
  ecx = edx = 0;  // @50_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_5ea470
  ecx = edi;  // @52_5ea470
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8110), sizeof v); (u32)v; });  // @53_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[9]);  // @54_5ea470
  ecx = edx = 0;  // @55_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_5ea470
  ecx = edi;  // @57_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7573), sizeof v); (u32)v; });  // @58_5ea470
  PV[10] = (u32)(eax);  // @59_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[10]);  // @60_5ea470
  ecx = edx = 0;  // @61_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 7569) + 0), 4); v; });  // @63_5ea470
  X0[1] = 0;  // @64_5ea470
  X0[2] = 0;  // @65_5ea470
  X0[3] = 0;  // @66_5ea470
  PV[11] = (u32)(ecx);  // @67_5ea470
  ecx = edi;  // @68_5ea470
  PV[12] = X0[0];  // @69_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[12]);  // @70_5ea470
  ecx = edx = 0;  // @71_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @72_5ea470
  eax = (u32)(ebx + 7574);  // @73_5ea470
  PV[13] = (u32)(eax);  // @74_5ea470
  ecx = edi;  // @75_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[13]);  // @76_5ea470
  ecx = edx = 0;  // @77_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_5ea470
  ecx = edi;  // @79_5ea470
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7499), sizeof v); (u32)v; });  // @80_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[14]);  // @81_5ea470
  ecx = edx = 0;  // @82_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @83_5ea470
  ecx = edi;  // @84_5ea470
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7495), sizeof v); (u32)v; });  // @85_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[15]);  // @86_5ea470
  ecx = edx = 0;  // @87_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 7447) + 0), 4); v; });  // @89_5ea470
  X0[1] = 0;  // @90_5ea470
  X0[2] = 0;  // @91_5ea470
  X0[3] = 0;  // @92_5ea470
  PV[16] = (u32)(ecx);  // @93_5ea470
  ecx = edi;  // @94_5ea470
  PV[17] = X0[0];  // @95_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[17]);  // @96_5ea470
  ecx = edx = 0;  // @97_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @98_5ea470
  ecx = edi;  // @99_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 750), sizeof v); (u32)v; });  // @100_5ea470
  PV[18] = (u32)(eax);  // @101_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[18]);  // @102_5ea470
  ecx = edx = 0;  // @103_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @104_5ea470
  ecx = edi;  // @105_5ea470
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 746), sizeof v); (u32)v; });  // @106_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[19]);  // @107_5ea470
  ecx = edx = 0;  // @108_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @109_5ea470
  ecx = edi;  // @110_5ea470
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 742), sizeof v); (u32)v; });  // @111_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[20]);  // @112_5ea470
  ecx = edx = 0;  // @113_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @114_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 109) + 0), 4); v; });  // @115_5ea470
  X0[1] = 0;  // @116_5ea470
  X0[2] = 0;  // @117_5ea470
  X0[3] = 0;  // @118_5ea470
  PV[21] = (u32)(ecx);  // @119_5ea470
  ecx = edi;  // @120_5ea470
  PV[22] = X0[0];  // @121_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[22]);  // @122_5ea470
  ecx = edx = 0;  // @123_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @124_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 105) + 0), 4); v; });  // @125_5ea470
  X0[1] = 0;  // @126_5ea470
  X0[2] = 0;  // @127_5ea470
  X0[3] = 0;  // @128_5ea470
  PV[23] = (u32)(ecx);  // @129_5ea470
  ecx = edi;  // @130_5ea470
  PV[24] = X0[0];  // @131_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[24]);  // @132_5ea470
  ecx = edx = 0;  // @133_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @134_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 101) + 0), 4); v; });  // @135_5ea470
  X0[1] = 0;  // @136_5ea470
  X0[2] = 0;  // @137_5ea470
  X0[3] = 0;  // @138_5ea470
  PV[25] = (u32)(ecx);  // @139_5ea470
  ecx = edi;  // @140_5ea470
  PV[26] = X0[0];  // @141_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[26]);  // @142_5ea470
  ecx = edx = 0;  // @143_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @144_5ea470
  ecx = edi;  // @145_5ea470
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1263), sizeof v); (u32)v; });  // @146_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[27]);  // @147_5ea470
  ecx = edx = 0;  // @148_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @149_5ea470
  eax = (u32)(ebx + 8130);  // @150_5ea470
  PV[28] = (u32)(eax);  // @151_5ea470
  ecx = edi;  // @152_5ea470
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[28], (u32)(768));  // @153_5ea470
  ecx = edx = 0;  // @154_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @155_5ea470
  eax = (u32)(ebx + 1279);  // @156_5ea470
  PV[29] = (u32)(eax);  // @157_5ea470
  ecx = edi;  // @158_5ea470
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[29], (u32)(6144));  // @159_5ea470
  ecx = edx = 0;  // @160_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @161_5ea470
  eax = (u32)(ebx + 751);  // @162_5ea470
  PV[30] = (u32)(eax);  // @163_5ea470
  ecx = edi;  // @164_5ea470
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[30], (u32)(512));  // @165_5ea470
  ecx = edx = 0;  // @166_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @167_5ea470
  eax = (u32)(ebx + 230);  // @168_5ea470
  PV[31] = (u32)(eax);  // @169_5ea470
  ecx = edi;  // @170_5ea470
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[31], (u32)(512));  // @171_5ea470
  ecx = edx = 0;  // @172_5ea470
  esi = (u32)(ebx + 7598);  // @173_5ea470
  ebx = (u32)(128);  // @174_5ea470
  L5ea626:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @176_5ea470
  ecx = edi;  // @177_5ea470
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @178_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[32]);  // @179_5ea470
  ecx = edx = 0;  // @180_5ea470
  esi = (u32)(esi + 4);  // @181_5ea470
  ebx = (ebx - (u32)(1));  // @182_5ea470
  FL[3] = ebx;  // @183_5ea470
  if (FL[3] != 0) goto L5ea626;  // @184_5ea470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @185_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @186_5ea470
  PV[33] = (u32)(ecx);  // @187_5ea470
  ecx = edi;  // @188_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 84) + 0), 4); v; });  // @189_5ea470
  X0[1] = 0;  // @190_5ea470
  X0[2] = 0;  // @191_5ea470
  X0[3] = 0;  // @192_5ea470
  PV[34] = X0[0];  // @193_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[34]);  // @194_5ea470
  ecx = edx = 0;  // @195_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @196_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 109) + 0), 4); v; });  // @197_5ea470
  X0[1] = 0;  // @198_5ea470
  X0[2] = 0;  // @199_5ea470
  X0[3] = 0;  // @200_5ea470
  PV[35] = (u32)(ecx);  // @201_5ea470
  ecx = edi;  // @202_5ea470
  PV[36] = X0[0];  // @203_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[36]);  // @204_5ea470
  ecx = edx = 0;  // @205_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @206_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7451) + 0), 4); v; });  // @207_5ea470
  X0[1] = 0;  // @208_5ea470
  X0[2] = 0;  // @209_5ea470
  X0[3] = 0;  // @210_5ea470
  PV[37] = (u32)(ecx);  // @211_5ea470
  ecx = edi;  // @212_5ea470
  PV[38] = X0[0];  // @213_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[38]);  // @214_5ea470
  ecx = edx = 0;  // @215_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @216_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7455) + 0), 4); v; });  // @217_5ea470
  X0[1] = 0;  // @218_5ea470
  X0[2] = 0;  // @219_5ea470
  X0[3] = 0;  // @220_5ea470
  PV[39] = (u32)(ecx);  // @221_5ea470
  ecx = edi;  // @222_5ea470
  PV[40] = X0[0];  // @223_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[40]);  // @224_5ea470
  ecx = edx = 0;  // @225_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @226_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7459) + 0), 4); v; });  // @227_5ea470
  X0[1] = 0;  // @228_5ea470
  X0[2] = 0;  // @229_5ea470
  X0[3] = 0;  // @230_5ea470
  PV[41] = (u32)(ecx);  // @231_5ea470
  ecx = edi;  // @232_5ea470
  PV[42] = X0[0];  // @233_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[42]);  // @234_5ea470
  ecx = edx = 0;  // @235_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @236_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7463) + 0), 4); v; });  // @237_5ea470
  X0[1] = 0;  // @238_5ea470
  X0[2] = 0;  // @239_5ea470
  X0[3] = 0;  // @240_5ea470
  PV[43] = (u32)(ecx);  // @241_5ea470
  ecx = edi;  // @242_5ea470
  PV[44] = X0[0];  // @243_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[44]);  // @244_5ea470
  ecx = edx = 0;  // @245_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @246_5ea470
  ecx = edi;  // @247_5ea470
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7435), sizeof v); (u32)v; });  // @248_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[45]);  // @249_5ea470
  ecx = edx = 0;  // @250_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @251_5ea470
  ecx = edi;  // @252_5ea470
  PV[46] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7431), sizeof v); (u32)v; });  // @253_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[46]);  // @254_5ea470
  ecx = edx = 0;  // @255_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @256_5ea470
  ecx = edi;  // @257_5ea470
  PV[47] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1267), sizeof v); (u32)v; });  // @258_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[47]);  // @259_5ea470
  ecx = edx = 0;  // @260_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @261_5ea470
  ecx = edi;  // @262_5ea470
  PV[48] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 97), sizeof v); (u32)v; });  // @263_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[48]);  // @264_5ea470
  ecx = edx = 0;  // @265_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @266_5ea470
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 7443) + 0), 4); v; });  // @267_5ea470
  X0[1] = 0;  // @268_5ea470
  X0[2] = 0;  // @269_5ea470
  X0[3] = 0;  // @270_5ea470
  PV[49] = (u32)(ecx);  // @271_5ea470
  ecx = edi;  // @272_5ea470
  PV[50] = X0[0];  // @273_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[50]);  // @274_5ea470
  ecx = edx = 0;  // @275_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @276_5ea470
  ecx = edi;  // @277_5ea470
  PV[51] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7483), sizeof v); (u32)v; });  // @278_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[51]);  // @279_5ea470
  ecx = edx = 0;  // @280_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @281_5ea470
  ecx = edi;  // @282_5ea470
  PV[52] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7487), sizeof v); (u32)v; });  // @283_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[52]);  // @284_5ea470
  ecx = edx = 0;  // @285_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @286_5ea470
  ecx = edi;  // @287_5ea470
  PV[53] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7491), sizeof v); (u32)v; });  // @288_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[53]);  // @289_5ea470
  ecx = edx = 0;  // @290_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @291_5ea470
  ecx = edi;  // @292_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @293_5ea470
  PV[54] = (u32)(eax);  // @294_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[54]);  // @295_5ea470
  ecx = edx = 0;  // @296_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @297_5ea470
  ecx = edi;  // @298_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7503), sizeof v); (u32)v; });  // @299_5ea470
  PV[55] = (u32)(eax);  // @300_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[55]);  // @301_5ea470
  ecx = edx = 0;  // @302_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @303_5ea470
  eax = (u32)(esi + 7504);  // @304_5ea470
  PV[56] = (u32)(eax);  // @305_5ea470
  ecx = edi;  // @306_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[56]);  // @307_5ea470
  ecx = edx = 0;  // @308_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @309_5ea470
  eax = (u32)(esi + 7516);  // @310_5ea470
  PV[57] = (u32)(eax);  // @311_5ea470
  ecx = edi;  // @312_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[57]);  // @313_5ea470
  ecx = edx = 0;  // @314_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @315_5ea470
  eax = (u32)(esi + 7528);  // @316_5ea470
  PV[58] = (u32)(eax);  // @317_5ea470
  ecx = edi;  // @318_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[58]);  // @319_5ea470
  ecx = edx = 0;  // @320_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @321_5ea470
  eax = (u32)(esi + 7540);  // @322_5ea470
  PV[59] = (u32)(eax);  // @323_5ea470
  ecx = edi;  // @324_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[59]);  // @325_5ea470
  ecx = edx = 0;  // @326_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @327_5ea470
  ecx = edi;  // @328_5ea470
  PV[60] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7552), sizeof v); (u32)v; });  // @329_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[60]);  // @330_5ea470
  ecx = edx = 0;  // @331_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @332_5ea470
  ecx = edi;  // @333_5ea470
  PV[61] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7556), sizeof v); (u32)v; });  // @334_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[61]);  // @335_5ea470
  ecx = edx = 0;  // @336_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @337_5ea470
  ecx = edi;  // @338_5ea470
  PV[62] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7560), sizeof v); (u32)v; });  // @339_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[62]);  // @340_5ea470
  ecx = edx = 0;  // @341_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @342_5ea470
  ecx = edi;  // @343_5ea470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7564), sizeof v); (u32)v; });  // @344_5ea470
  PV[63] = (u32)(eax);  // @345_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[63]);  // @346_5ea470
  ecx = edx = 0;  // @347_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @348_5ea470
  ecx = edi;  // @349_5ea470
  PV[64] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7565), sizeof v); (u32)v; });  // @350_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[64]);  // @351_5ea470
  ecx = edx = 0;  // @352_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @353_5ea470
  ecx = edi;  // @354_5ea470
  PV[65] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7439), sizeof v); (u32)v; });  // @355_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[65]);  // @356_5ea470
  ecx = edx = 0;  // @357_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; });  // @358_5ea470
  ecx = edi;  // @359_5ea470
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7586), sizeof v); (u32)v; }));  // @360_5ea470
  FL[3] = eax;  // @361_5ea470
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @362_5ea470
  eax = (u32)((s32)eax >> (u32)(2));  // @363_5ea470
  FL[3] = eax;  // @364_5ea470
  PV[66] = (u32)(eax);  // @365_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[66]);  // @366_5ea470
  ecx = edx = 0;  // @367_5ea470
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7586), sizeof v); (u32)v; });  // @368_5ea470
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; });  // @369_5ea470
  if (FL[0] == FL[1]) goto L5ea824;  // @370_5ea470
  L5ea7e7:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @372_5ea470
  ecx = edi;  // @373_5ea470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @374_5ea470
  PV[67] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @375_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[67]);  // @376_5ea470
  ecx = edx = 0;  // @377_5ea470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @378_5ea470
  PV[68] = (u32)(edi);  // @379_5ea470
  eax = ext_5b7eb0_thiscall2(ecx, PV[68]);  // @380_5ea470
  ecx = edx = 0;  // @381_5ea470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @382_5ea470
  PV[69] = (u32)(edi);  // @383_5ea470
  eax = ext_5b7c70_thiscall2(ecx, PV[69]);  // @384_5ea470
  ecx = edx = 0;  // @385_5ea470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @386_5ea470
  PV[70] = (u32)(edi);  // @387_5ea470
  eax = ext_5b7c70_thiscall2(ecx, PV[70]);  // @388_5ea470
  ecx = edx = 0;  // @389_5ea470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @390_5ea470
  PV[71] = (u32)(edi);  // @391_5ea470
  eax = ext_5b7c70_thiscall2(ecx, PV[71]);  // @392_5ea470
  ecx = edx = 0;  // @393_5ea470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @394_5ea470
  ebx = (ebx + (u32)(4));  // @395_5ea470
  FL[3] = ebx;  // @396_5ea470
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; });  // @397_5ea470
  if (FL[0] != FL[1]) goto L5ea7e7;  // @398_5ea470
  L5ea824:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @400_5ea470
  ecx = edi;  // @401_5ea470
  PV[72] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8927), sizeof v); (u32)v; });  // @402_5ea470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[72]);  // @403_5ea470
  ecx = edx = 0;  // @404_5ea470
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @405_5ea470
  return eax;  // @406_5ea470
}
PCREG(5ea470, lifted_5ea470);

