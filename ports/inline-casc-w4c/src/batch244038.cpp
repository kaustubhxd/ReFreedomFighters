// batch244038.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc500_fastcall2(u32, u32) __asm__("ext_4cc500");
extern "C" u32 FASTCALL ext_4f9350_fastcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_4f9350");
extern "C" u32 THISCALL ext_4ee640_thiscall4(u32, u32, u32, u32) __asm__("ext_4ee640");
extern "C" u32 THISCALL ext_5348e0_thiscall3(u32, u32, u32) __asm__("ext_5348e0");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_534570(u32 ecx_in, u32 a0) {
  u8 F[0x1160] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x1060);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x1060 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_534570
  esi = ecx;  // @1_534570
  ecx = ebx;  // @2_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_534570
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4112), &v, sizeof v); }  // @4_534570
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4108), sizeof v); (u32)v; });  // @5_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[0]);  // @6_534570
  ecx = edx = 0;  // @7_534570
  eax = (u32)(EBP - 4100);  // @8_534570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4108), &v, sizeof v); }  // @9_534570
  PV[1] = (u32)(eax);  // @10_534570
  eax = ext_634d10_cdecl3(PV[1], (u32)(0), (u32)(4096));  // @11_534570
    // @12_534570
  edi = 0;  // @13_534570
  FL[3] = edi;  // @14_534570
  L5345d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @16_534570
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4104), &v, sizeof v); }  // @17_534570
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @18_534570
  if (FL[0] == FL[1]) goto L534850;  // @19_534570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx + 64), sizeof v); (u32)v; });  // @20_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @21_534570
  esi = (esi & (u32)(4294967231));  // @22_534570
  FL[3] = esi;  // @23_534570
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx), sizeof v); (u32)v; });  // @24_534570
  ecx = ebx;  // @25_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[2]);  // @26_534570
  ecx = edx = 0;  // @27_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4104), sizeof v); (u32)v; });  // @28_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_534570
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx + 16), sizeof v); (u32)v; });  // @30_534570
  ecx = ebx;  // @31_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[3]);  // @32_534570
  ecx = edx = 0;  // @33_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4104), sizeof v); (u32)v; });  // @34_534570
  ecx = ebx;  // @35_534570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @36_534570
  eax = (eax + (u32)(20));  // @37_534570
  FL[3] = eax;  // @38_534570
  eax = (eax + edi);  // @39_534570
  FL[3] = eax;  // @40_534570
  PV[4] = (u32)(eax);  // @41_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[4]);  // @42_534570
  ecx = edx = 0;  // @43_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4104), sizeof v); (u32)v; });  // @44_534570
  ecx = ebx;  // @45_534570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @46_534570
  eax = (eax + (u32)(32));  // @47_534570
  FL[3] = eax;  // @48_534570
  eax = (eax + edi);  // @49_534570
  FL[3] = eax;  // @50_534570
  PV[5] = (u32)(eax);  // @51_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[5]);  // @52_534570
  ecx = edx = 0;  // @53_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4104), sizeof v); (u32)v; });  // @54_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_534570
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx + 44), sizeof v); (u32)v; });  // @56_534570
  ecx = ebx;  // @57_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[6]);  // @58_534570
  ecx = edx = 0;  // @59_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4104), sizeof v); (u32)v; });  // @60_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @61_534570
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx + 60), sizeof v); (u32)v; });  // @62_534570
  ecx = ebx;  // @63_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[7]);  // @64_534570
  ecx = edx = 0;  // @65_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @66_534570
  ecx = ebx;  // @67_534570
  PV[8] = (u32)(esi);  // @68_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[8]);  // @69_534570
  ecx = edx = 0;  // @70_534570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4104), sizeof v); (u32)v; });  // @71_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @72_534570
  PV[9] = (u32)(ecx);  // @73_534570
  ecx = ebx;  // @74_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 68) + 0), 4); v; });  // @75_534570
  X0[1] = 0;  // @76_534570
  X0[2] = 0;  // @77_534570
  X0[3] = 0;  // @78_534570
  PV[10] = X0[0];  // @79_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[10]);  // @80_534570
  ecx = edx = 0;  // @81_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @82_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 72) + 0), 4); v; });  // @83_534570
  X0[1] = 0;  // @84_534570
  X0[2] = 0;  // @85_534570
  X0[3] = 0;  // @86_534570
  PV[11] = (u32)(ecx);  // @87_534570
  ecx = ebx;  // @88_534570
  PV[12] = X0[0];  // @89_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[12]);  // @90_534570
  ecx = edx = 0;  // @91_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @92_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 76) + 0), 4); v; });  // @93_534570
  X0[1] = 0;  // @94_534570
  X0[2] = 0;  // @95_534570
  X0[3] = 0;  // @96_534570
  PV[13] = (u32)(ecx);  // @97_534570
  ecx = ebx;  // @98_534570
  PV[14] = X0[0];  // @99_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @100_534570
  ecx = edx = 0;  // @101_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @102_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 80) + 0), 4); v; });  // @103_534570
  X0[1] = 0;  // @104_534570
  X0[2] = 0;  // @105_534570
  X0[3] = 0;  // @106_534570
  PV[15] = (u32)(ecx);  // @107_534570
  ecx = ebx;  // @108_534570
  PV[16] = X0[0];  // @109_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[16]);  // @110_534570
  ecx = edx = 0;  // @111_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @112_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 84) + 0), 4); v; });  // @113_534570
  X0[1] = 0;  // @114_534570
  X0[2] = 0;  // @115_534570
  X0[3] = 0;  // @116_534570
  PV[17] = (u32)(ecx);  // @117_534570
  ecx = ebx;  // @118_534570
  PV[18] = X0[0];  // @119_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[18]);  // @120_534570
  ecx = edx = 0;  // @121_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @122_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 92) + 0), 4); v; });  // @123_534570
  X0[1] = 0;  // @124_534570
  X0[2] = 0;  // @125_534570
  X0[3] = 0;  // @126_534570
  PV[19] = (u32)(ecx);  // @127_534570
  ecx = ebx;  // @128_534570
  PV[20] = X0[0];  // @129_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[20]);  // @130_534570
  ecx = edx = 0;  // @131_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @132_534570
  ecx = ebx;  // @133_534570
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 96), sizeof v); (u32)v; });  // @134_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[21]);  // @135_534570
  ecx = edx = 0;  // @136_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @137_534570
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 100), sizeof v); (u32)v; });  // @138_534570
  ecx = ebx;  // @139_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[22]);  // @140_534570
  ecx = edx = 0;  // @141_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @142_534570
  ecx = ebx;  // @143_534570
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 104), sizeof v); (u32)v; });  // @144_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[23]);  // @145_534570
  ecx = edx = 0;  // @146_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @147_534570
  ecx = ebx;  // @148_534570
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 4), sizeof v); (u32)v; });  // @149_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[24]);  // @150_534570
  ecx = edx = 0;  // @151_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @152_534570
  ecx = ebx;  // @153_534570
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 8), sizeof v); (u32)v; });  // @154_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[25]);  // @155_534570
  ecx = edx = 0;  // @156_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @157_534570
  PV[26] = (u32)(ecx);  // @158_534570
  ecx = 0;  // @159_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @160_534570
  PV[27] = eax;  // @161_534570
  ecx = ebx;  // @162_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @163_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[27]);  // @164_534570
  ecx = edx = 0;  // @165_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @166_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @167_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4104), sizeof v); (u32)v; });  // @168_534570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @169_534570
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax + 124), sizeof v); (u32)v; });  // @170_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 64)))(ecx, PV[28]);  // @171_534570
  ecx = edx = 0;  // @172_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @173_534570
  PV[29] = (u32)(eax);  // @174_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @175_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 476)))(ecx, PV[29]);  // @176_534570
  ecx = edx = 0;  // @177_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @178_534570
  PV[30] = (u32)(eax);  // @179_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @180_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @181_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @182_534570
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[30]);  // @183_534570
  ecx = edx = 0;  // @184_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @185_534570
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 4116)) :: "st");  // @186_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4116) + 0), 4); v; });  // @187_534570
  X0[1] = 0;  // @188_534570
  X0[2] = 0;  // @189_534570
  X0[3] = 0;  // @190_534570
  PV[31] = (u32)(ecx);  // @191_534570
  ecx = ebx;  // @192_534570
  PV[32] = X0[0];  // @193_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[32]);  // @194_534570
  ecx = edx = 0;  // @195_534570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4104), sizeof v); (u32)v; });  // @196_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @197_534570
  PV[33] = (u32)(ecx);  // @198_534570
  ecx = ebx;  // @199_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 120) + 0), 4); v; });  // @200_534570
  X0[1] = 0;  // @201_534570
  X0[2] = 0;  // @202_534570
  X0[3] = 0;  // @203_534570
  PV[34] = X0[0];  // @204_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[34]);  // @205_534570
  ecx = edx = 0;  // @206_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @207_534570
  ecx = ebx;  // @208_534570
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 124), sizeof v); (u32)v; });  // @209_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[35]);  // @210_534570
  ecx = edx = 0;  // @211_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @212_534570
  ecx = ebx;  // @213_534570
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 128), sizeof v); (u32)v; });  // @214_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[36]);  // @215_534570
  ecx = edx = 0;  // @216_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @217_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 132) + 0), 4); v; });  // @218_534570
  X0[1] = 0;  // @219_534570
  X0[2] = 0;  // @220_534570
  X0[3] = 0;  // @221_534570
  PV[37] = (u32)(ecx);  // @222_534570
  ecx = ebx;  // @223_534570
  PV[38] = X0[0];  // @224_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[38]);  // @225_534570
  ecx = edx = 0;  // @226_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @227_534570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + esi + 136) + 0), 4); v; });  // @228_534570
  X0[1] = 0;  // @229_534570
  X0[2] = 0;  // @230_534570
  X0[3] = 0;  // @231_534570
  PV[39] = (u32)(ecx);  // @232_534570
  ecx = ebx;  // @233_534570
  PV[40] = X0[0];  // @234_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[40]);  // @235_534570
  ecx = edx = 0;  // @236_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @237_534570
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 48), sizeof v); (u32)v; });  // @238_534570
  PV[42] = (u32)(ebx);  // @239_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @240_534570
  ecx = (ecx + (u32)(4255));  // @241_534570
  FL[3] = ecx;  // @242_534570
  eax = ext_5348e0_thiscall3(ecx, PV[42], PV[41]);  // @243_534570
  ecx = edx = 0;  // @244_534570
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 52), sizeof v); (u32)v; });  // @245_534570
  PV[44] = (u32)(ebx);  // @246_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @247_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @248_534570
  ecx = (ecx + (u32)(4255));  // @249_534570
  FL[3] = ecx;  // @250_534570
  eax = ext_5348e0_thiscall3(ecx, PV[44], PV[43]);  // @251_534570
  ecx = edx = 0;  // @252_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @253_534570
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 56), sizeof v); (u32)v; });  // @254_534570
  PV[46] = (u32)(ebx);  // @255_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @256_534570
  ecx = (ecx + (u32)(4255));  // @257_534570
  FL[3] = ecx;  // @258_534570
  eax = ext_5348e0_thiscall3(ecx, PV[46], PV[45]);  // @259_534570
  ecx = edx = 0;  // @260_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4112), sizeof v); (u32)v; });  // @261_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @262_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4108), sizeof v); (u32)v; });  // @263_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @264_534570
  eax = (eax & ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 16), sizeof v); (u32)v; }));  // @265_534570
  FL[3] = eax;  // @266_534570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4112), sizeof v); (u32)v; });  // @267_534570
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + eax*4 - 4100), &v, sizeof v); }  // @268_534570
  ecx = (ecx + 1);  // @269_534570
  FL[3] = ecx;  // @270_534570
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4108), &v, sizeof v); }  // @271_534570
  L534850:;
  edi = (edi + (u32)(253));  // @273_534570
  FL[3] = edi;  // @274_534570
  FL[0] = edi; FL[1] = (u32)(259072);  // @275_534570
  if ((s32)FL[0] < (s32)FL[1]) goto L5345d0;  // @276_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @277_534570
  ecx = ebx;  // @278_534570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @279_534570
  PV[47] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @280_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[47]);  // @281_534570
  ecx = edx = 0;  // @282_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @283_534570
  ecx = ebx;  // @284_534570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @285_534570
  PV[48] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @286_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[48]);  // @287_534570
  ecx = edx = 0;  // @288_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @289_534570
  ecx = ebx;  // @290_534570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @291_534570
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @292_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[49]);  // @293_534570
  ecx = edx = 0;  // @294_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @295_534570
  ecx = ebx;  // @296_534570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @297_534570
  PV[50] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @298_534570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[50]);  // @299_534570
  ecx = edx = 0;  // @300_534570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @301_534570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @302_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @303_534570
  eax = (u32)(eax*4 + 4);  // @304_534570
  PV[51] = (u32)(eax);  // @305_534570
  PV[52] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @306_534570
  ecx = ebx;  // @307_534570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[52], PV[51]);  // @308_534570
  ecx = edx = 0;  // @309_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @310_534570
  ecx = ebx;  // @311_534570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @312_534570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @313_534570
  eax = (u32)(eax*4 + 4);  // @314_534570
  PV[53] = (u32)(eax);  // @315_534570
  eax = (u32)(EBP - 4100);  // @316_534570
  PV[54] = (u32)(eax);  // @317_534570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[54], PV[53]);  // @318_534570
  ecx = edx = 0;  // @319_534570
  ext_633654(G(u32, 0x6f5630));  // @320_534570
  return eax;  // @321_534570
}
PCREG(534570, lifted_534570);

extern "C" u32 THISCALL lifted_4ef880(u32 ecx_in) {
  u8 F[0x9db0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x9cb0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4ef880
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 159), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4ef880
  if (FL[0] != FL[1]) goto L4ef8b4;  // @2_4ef880
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @3_4ef880
  FL[3] = (eax & 0xff);  // @4_4ef880
  ext_633654(G(u32, 0x6f5630));  // @5_4ef880
  return eax;  // @6_4ef880
  L4ef8b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @8_4ef880
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 560)))(ecx);  // @9_4ef880
  ecx = edx = 0;  // @10_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 151), sizeof v); (u32)v; });  // @11_4ef880
  ecx = (u32)(EBP - 40020);  // @12_4ef880
  esi = 0;  // @13_4ef880
  FL[3] = esi;  // @14_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40020), &v, sizeof v); }  // @15_4ef880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40040), &v, sizeof v); }  // @16_4ef880
  eax = ext_4cc500_fastcall2(ecx, edx);  // @17_4ef880
  ecx = edx = 0;  // @18_4ef880
  FL[2] = (eax & eax);  // @19_4ef880
  if (FL[2] == 0) goto L4ef90a;  // @20_4ef880
  L4ef8e0:;
  FL[0] = eax; FL[1] = (u32)(10);  // @22_4ef880
  if (FL[0] == FL[1]) goto L4ef8f5;  // @23_4ef880
  FL[0] = eax; FL[1] = (u32)(13);  // @24_4ef880
  if (FL[0] == FL[1]) goto L4ef8f5;  // @25_4ef880
  FL[0] = eax; FL[1] = (u32)(32);  // @26_4ef880
  if (FL[0] == FL[1]) goto L4ef8f5;  // @27_4ef880
  FL[0] = eax; FL[1] = (u32)(9);  // @28_4ef880
  if (FL[0] == FL[1]) goto L4ef8f5;  // @29_4ef880
  esi = (esi + 1);  // @30_4ef880
  FL[3] = esi;  // @31_4ef880
  L4ef8f5:;
  ecx = (u32)(EBP - 40020);  // @33_4ef880
  eax = ext_4cc500_fastcall2(ecx, edx);  // @34_4ef880
  ecx = edx = 0;  // @35_4ef880
  FL[2] = (eax & eax);  // @36_4ef880
  if (FL[2] != 0) goto L4ef8e0;  // @37_4ef880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40040), &v, sizeof v); }  // @38_4ef880
  L4ef90a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 42), &v, sizeof v); }  // @40_4ef880
  FL[2] = (esi & esi);  // @41_4ef880
  if (FL[2] == 0) goto L4ef969;  // @42_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4ef880
  PV[0] = (u32)(esi);  // @44_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @45_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @46_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @48_4ef880
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[0]);  // @49_4ef880
  ecx = edx = 0;  // @50_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 42), &v, sizeof v); }  // @51_4ef880
  FL[2] = (eax & eax);  // @52_4ef880
  if (FL[2] != 0) goto L4ef969;  // @53_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @54_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @56_4ef880
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6912796), (u32)(1433));  // @57_4ef880
  ecx = edx = 0;  // @58_4ef880
  PV[1] = (u32)(eax);  // @59_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_4ef880
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6915284));  // @61_4ef880
  ecx = edx = 0;  // @62_4ef880
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @63_4ef880
  FL[3] = (eax & 0xff);  // @64_4ef880
  ext_633654(G(u32, 0x6f5630));  // @65_4ef880
  return eax;  // @66_4ef880
  L4ef969:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 159), sizeof v); (u32)v; });  // @68_4ef880
  eax = (u32)(EBP - 40004);  // @69_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40028), &v, sizeof v); }  // @70_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 628), sizeof v); (u32)v; });  // @72_4ef880
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @73_4ef880
  ecx = edx = 0;  // @74_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 159), sizeof v); (u32)v; });  // @75_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @76_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 640), sizeof v); (u32)v; });  // @78_4ef880
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(32));  // @79_4ef880
  ecx = edx = 0;  // @80_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 151), sizeof v); (u32)v; });  // @81_4ef880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40020), &v, sizeof v); }  // @82_4ef880
  ecx = 0;  // @83_4ef880
  FL[3] = ecx;  // @84_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40036), &v, sizeof v); }  // @85_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @86_4ef880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40016), &v, sizeof v); }  // @87_4ef880
  ecx = (u32)(EBP - 40020);  // @88_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40012), &v, sizeof v); }  // @89_4ef880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40008), &v, sizeof v); }  // @90_4ef880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40032), &v, sizeof v); }  // @91_4ef880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40024), &v, sizeof v); }  // @92_4ef880
  eax = ext_4cc500_fastcall2(ecx, edx);  // @93_4ef880
  ecx = edx = 0;  // @94_4ef880
  esi = eax;  // @95_4ef880
  FL[2] = (esi & esi);  // @96_4ef880
  if (FL[2] == 0) goto L4efc5a;  // @97_4ef880
  L4ef9f0:;
  eax = (u32)(esi - 9);  // @99_4ef880
  FL[0] = eax; FL[1] = (u32)(23);  // @100_4ef880
  if (FL[0] > FL[1]) goto L4efac1;  // @101_4ef880
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5176532), sizeof v); (u32)v; });  // @102_4ef880
  switch (eax) {  // @103_4ef880
  case 0: goto L4efa99;  // @104_4ef880
  case 1: goto L4efa0a;  // @105_4ef880
  case 2: goto L4efa6f;  // @106_4ef880
  case 3: goto L4efa7c;  // @107_4ef880
  case 4: goto L4efac1;  // @108_4ef880
  default: __builtin_trap(); }  // @109_4ef880
  L4efa0a:;
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40012), sizeof v); (u32)v; });  // @111_4ef880
  ecx = edi;  // @112_4ef880
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40024), sizeof v); (u32)v; });  // @113_4ef880
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; });  // @114_4ef880
  eax = ext_4ee640_thiscall4(ecx, PV[4], PV[3], PV[2]);  // @115_4ef880
  ecx = edx = 0;  // @116_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40036), sizeof v); (u32)v; });  // @117_4ef880
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40032), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @118_4ef880
  X0[0] = F2U((float)(s32)X0[0]);  // @119_4ef880
  X0[1] = F2U((float)(s32)X0[1]);  // @120_4ef880
  X0[2] = F2U((float)(s32)X0[2]);  // @121_4ef880
  X0[3] = F2U((float)(s32)X0[3]);  // @122_4ef880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40024), &v, sizeof v); }  // @123_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 21), sizeof v); (u32)v; }));  // @124_4ef880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40008), &v, sizeof v); }  // @125_4ef880
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @126_4ef880
  X1[0] = F2U((float)(s32)X1[0]);  // @127_4ef880
  X1[1] = F2U((float)(s32)X1[1]);  // @128_4ef880
  X1[2] = F2U((float)(s32)X1[2]);  // @129_4ef880
  X1[3] = F2U((float)(s32)X1[3]);  // @130_4ef880
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818396) + 0), 4); v; })));  // @131_4ef880
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @132_4ef880
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @133_4ef880
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 147), sizeof v); (u32)v; }));  // @134_4ef880
  FL[3] = eax;  // @135_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40032), &v, sizeof v); }  // @136_4ef880
  L4efa6f:;
  ecx = 0;  // @138_4ef880
  FL[3] = ecx;  // @139_4ef880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40016), &v, sizeof v); }  // @140_4ef880
  goto L4efc45;  // @141_4ef880
  L4efa7c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40036), sizeof v); (u32)v; });  // @143_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }));  // @144_4ef880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP - 40008), &v, sizeof v); }  // @145_4ef880
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; });  // @146_4ef880
  ecx = 0;  // @147_4ef880
  FL[3] = ecx;  // @148_4ef880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40016), &v, sizeof v); }  // @149_4ef880
  goto L4efc45;  // @150_4ef880
  L4efa99:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; });  // @152_4ef880
  eax = esi;  // @153_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 163), sizeof v); (u32)v; });  // @154_4ef880
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @155_4ef880
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @156_4ef880
  ecx = (ecx - edx);  // @157_4ef880
  FL[3] = ecx;  // @158_4ef880
  esi = (esi + ecx);  // @159_4ef880
  FL[3] = esi;  // @160_4ef880
  ecx = 0;  // @161_4ef880
  FL[3] = ecx;  // @162_4ef880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40008), &v, sizeof v); }  // @163_4ef880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40016), &v, sizeof v); }  // @164_4ef880
  goto L4efc45;  // @165_4ef880
  L4efac1:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40024), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 40024), &v, sizeof v); }  // @167_4ef880
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40024), sizeof v); (u32)v; });  // @168_4ef880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40016), sizeof v); (u32)v; });  // @169_4ef880
  FL[2] = (edx & edx);  // @170_4ef880
  if (FL[2] == 0) goto L4efae9;  // @171_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 159), sizeof v); (u32)v; });  // @172_4ef880
  PV[5] = (u32)(esi);  // @173_4ef880
  PV[6] = (u32)(edx);  // @174_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 652), sizeof v); (u32)v; });  // @176_4ef880
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[6], PV[5]);  // @177_4ef880
  ecx = edx = 0;  // @178_4ef880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; }) - eax)); __builtin_memcpy((void *)(u32)(EBP - 40008), &v, sizeof v); }  // @179_4ef880
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; });  // @180_4ef880
  L4efae9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 159), sizeof v); (u32)v; });  // @182_4ef880
  PV[7] = (u32)(esi);  // @183_4ef880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40016), &v, sizeof v); }  // @184_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @185_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 640), sizeof v); (u32)v; });  // @186_4ef880
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[7]);  // @187_4ef880
  ecx = edx = 0;  // @188_4ef880
  esi = eax;  // @189_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40028), sizeof v); (u32)v; });  // @190_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @191_4ef880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @192_4ef880
  eax = (u32)(1717986919);  // @193_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40012), sizeof v); (u32)v; });  // @194_4ef880
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; }));  // @195_4ef880
  FL[3] = ecx;  // @196_4ef880
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @197_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40028), sizeof v); (u32)v; });  // @198_4ef880
  edx = (u32)((s32)edx >> (u32)(4));  // @199_4ef880
  FL[3] = edx;  // @200_4ef880
  eax = edx;  // @201_4ef880
  eax = (eax >> (u32)(31));  // @202_4ef880
  FL[3] = eax;  // @203_4ef880
  eax = (eax + edx);  // @204_4ef880
  FL[3] = eax;  // @205_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @206_4ef880
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @207_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40012), sizeof v); (u32)v; });  // @208_4ef880
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @209_4ef880
  X0[0] = F2U((float)(s32)X0[0]);  // @210_4ef880
  X0[1] = F2U((float)(s32)X0[1]);  // @211_4ef880
  X0[2] = F2U((float)(s32)X0[2]);  // @212_4ef880
  X0[3] = F2U((float)(s32)X0[3]);  // @213_4ef880
  __builtin_memcpy((void *)((u32)(ecx + 28) + 0), &X0[0], 4);  // @214_4ef880
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @215_4ef880
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @216_4ef880
  X0[0] = F2U((float)(s32)X0[0]);  // @217_4ef880
  X0[1] = F2U((float)(s32)X0[1]);  // @218_4ef880
  X0[2] = F2U((float)(s32)X0[2]);  // @219_4ef880
  X0[3] = F2U((float)(s32)X0[3]);  // @220_4ef880
  __builtin_memcpy((void *)((u32)(ecx + 32) + 0), &X0[0], 4);  // @221_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 14), sizeof v); (u32)v; }));  // @222_4ef880
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; }));  // @223_4ef880
  FL[3] = eax;  // @224_4ef880
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 28) + 0), 4); v; });  // @225_4ef880
  X0[1] = 0;  // @226_4ef880
  X0[2] = 0;  // @227_4ef880
  X0[3] = 0;  // @228_4ef880
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @229_4ef880
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @230_4ef880
  X1[0] = F2U((float)(s32)X1[0]);  // @231_4ef880
  X1[1] = F2U((float)(s32)X1[1]);  // @232_4ef880
  X1[2] = F2U((float)(s32)X1[2]);  // @233_4ef880
  X1[3] = F2U((float)(s32)X1[3]);  // @234_4ef880
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @235_4ef880
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 32) + 0), 4); v; });  // @236_4ef880
  X0[1] = 0;  // @237_4ef880
  X0[2] = 0;  // @238_4ef880
  X0[3] = 0;  // @239_4ef880
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @240_4ef880
  __builtin_memcpy((void *)((u32)(ecx) + 0), &X1[0], 4);  // @241_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 15), sizeof v); (u32)v; }));  // @242_4ef880
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40032), sizeof v); (u32)v; }));  // @243_4ef880
  FL[3] = eax;  // @244_4ef880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @245_4ef880
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @246_4ef880
  X1[0] = F2U((float)(s32)X1[0]);  // @247_4ef880
  X1[1] = F2U((float)(s32)X1[1]);  // @248_4ef880
  X1[2] = F2U((float)(s32)X1[2]);  // @249_4ef880
  X1[3] = F2U((float)(s32)X1[3]);  // @250_4ef880
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @251_4ef880
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @252_4ef880
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @253_4ef880
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @254_4ef880
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @255_4ef880
  __builtin_memcpy((void *)((u32)(ecx + 4) + 0), &X1[0], 4);  // @256_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }));  // @257_4ef880
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6912148) + 0), 4); v; });  // @258_4ef880
  X1[1] = 0;  // @259_4ef880
  X1[2] = 0;  // @260_4ef880
  X1[3] = 0;  // @261_4ef880
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @262_4ef880
  X0[0] = F2U((float)(s32)X0[0]);  // @263_4ef880
  X0[1] = F2U((float)(s32)X0[1]);  // @264_4ef880
  X0[2] = F2U((float)(s32)X0[2]);  // @265_4ef880
  X0[3] = F2U((float)(s32)X0[3]);  // @266_4ef880
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @267_4ef880
  __builtin_memcpy((void *)((u32)(ecx + 12) + 0), &X0[0], 4);  // @268_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 11), sizeof v); (u32)v; }));  // @269_4ef880
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @270_4ef880
  X0[0] = F2U((float)(s32)X0[0]);  // @271_4ef880
  X0[1] = F2U((float)(s32)X0[1]);  // @272_4ef880
  X0[2] = F2U((float)(s32)X0[2]);  // @273_4ef880
  X0[3] = F2U((float)(s32)X0[3]);  // @274_4ef880
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @275_4ef880
  __builtin_memcpy((void *)((u32)(ecx + 20) + 0), &X0[0], 4);  // @276_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 10), sizeof v); (u32)v; }));  // @277_4ef880
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @278_4ef880
  X0[0] = F2U((float)(s32)X0[0]);  // @279_4ef880
  X0[1] = F2U((float)(s32)X0[1]);  // @280_4ef880
  X0[2] = F2U((float)(s32)X0[2]);  // @281_4ef880
  X0[3] = F2U((float)(s32)X0[3]);  // @282_4ef880
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @283_4ef880
  __builtin_memcpy((void *)((u32)(ecx + 16) + 0), &X0[0], 4);  // @284_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }));  // @285_4ef880
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @286_4ef880
  X0[0] = F2U((float)(s32)X0[0]);  // @287_4ef880
  X0[1] = F2U((float)(s32)X0[1]);  // @288_4ef880
  X0[2] = F2U((float)(s32)X0[2]);  // @289_4ef880
  X0[3] = F2U((float)(s32)X0[3]);  // @290_4ef880
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @291_4ef880
  __builtin_memcpy((void *)((u32)(ecx + 24) + 0), &X0[0], 4);  // @292_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @293_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @294_4ef880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @295_4ef880
  eax = (u32)(edi + 24);  // @296_4ef880
  PV[8] = (u32)(eax);  // @297_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40012), sizeof v); (u32)v; });  // @298_4ef880
  eax = (eax + (u32)(36));  // @299_4ef880
  FL[3] = eax;  // @300_4ef880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @301_4ef880
  PV[9] = (u32)(eax);  // @302_4ef880
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, PV[9], PV[8]);  // @303_4ef880
  ecx = edx = 0;  // @304_4ef880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40012), sizeof v); (u32)v; }) + (u32)(40))); __builtin_memcpy((void *)(u32)(EBP - 40012), &v, sizeof v); }  // @305_4ef880
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40012), sizeof v); (u32)v; });  // @306_4ef880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40028), sizeof v); (u32)v; }) + (u32)(8))); __builtin_memcpy((void *)(u32)(EBP - 40028), &v, sizeof v); }  // @307_4ef880
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40028), sizeof v); (u32)v; });  // @308_4ef880
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @309_4ef880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP - 40008), &v, sizeof v); }  // @310_4ef880
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; });  // @311_4ef880
  L4efc45:;
  ecx = (u32)(EBP - 40020);  // @313_4ef880
  eax = ext_4cc500_fastcall2(ecx, edx);  // @314_4ef880
  ecx = edx = 0;  // @315_4ef880
  esi = eax;  // @316_4ef880
  FL[2] = (esi & esi);  // @317_4ef880
  if (FL[2] != 0) goto L4ef9f0;  // @318_4ef880
  L4efc5a:;
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40012), sizeof v); (u32)v; });  // @320_4ef880
  ecx = edi;  // @321_4ef880
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40024), sizeof v); (u32)v; });  // @322_4ef880
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40008), sizeof v); (u32)v; });  // @323_4ef880
  eax = ext_4ee640_thiscall4(ecx, PV[12], PV[11], PV[10]);  // @324_4ef880
  ecx = edx = 0;  // @325_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40040), sizeof v); (u32)v; });  // @326_4ef880
  ecx = (u32)(EBP - 40004);  // @327_4ef880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @328_4ef880
  PV[13] = (u32)(edi);  // @329_4ef880
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @330_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 46), &v, sizeof v); }  // @331_4ef880
  PV[15] = (u32)(eax);  // @332_4ef880
  eax = (u32)(edi + 58);  // @333_4ef880
  PV[16] = (u32)(eax);  // @334_4ef880
  eax = (u32)(edi + 54);  // @335_4ef880
  PV[17] = (u32)(eax);  // @336_4ef880
  eax = ext_4f9350_fastcall7(ecx, edx, PV[17], PV[16], PV[15], PV[14], PV[13]);  // @337_4ef880
  ecx = edx = 0;  // @338_4ef880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 50), &v, sizeof v); }  // @339_4ef880
  ecx = edi;  // @340_4ef880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @341_4ef880
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 552)))(ecx);  // @342_4ef880
  ecx = edx = 0;  // @343_4ef880
  ext_633654(G(u32, 0x6f5630));  // @344_4ef880
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @345_4ef880
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 144), &v, sizeof v); }  // @346_4ef880
  return eax;  // @347_4ef880
}
PCREG(4ef880, lifted_4ef880);

