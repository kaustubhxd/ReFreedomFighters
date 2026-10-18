// batch262004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 FASTCALL ext_4e08d0_fastcall2(u32, u32) __asm__("ext_4e08d0");
extern "C" u32 FASTCALL ext_4e0900_fastcall2(u32, u32) __asm__("ext_4e0900");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_546d70_fastcall2(u32, u32) __asm__("ext_546d70");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4ea300_thiscall2(u32, u32) __asm__("ext_4ea300");
extern "C" u32 THISCALL ext_4eb020_thiscall4(u32, u32, u32, u32) __asm__("ext_4eb020");
extern "C" u32 THISCALL ext_53d230_thiscall3(u32, u32, u32) __asm__("ext_53d230");
extern "C" u32 THISCALL ext_5407c0_thiscall1(u32) __asm__("ext_5407c0");
extern "C" u32 THISCALL ext_545cb0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_545cb0");
extern "C" u32 THISCALL ext_546860_thiscall2(u32, u32) __asm__("ext_546860");
extern "C" u32 THISCALL ext_6353d0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_6353d0");
extern "C" u32 THISCALL ext_635eb0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_635eb0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_53fe30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66aae5);  // @h_53fe30
  u32 w4i_pp = 0;
  u8 F[0x102e0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x101e0);
  u32 PV[69], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x101e0 + 8, &a0, 4);
  esi = ecx;  // @0_53fe30
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 271), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_53fe30
  if (FL[0] == FL[1]) goto L53fe89;  // @2_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 247), sizeof v); (u32)v; });  // @3_53fe30
  FL[2] = (eax & eax);  // @4_53fe30
  if ((s32)FL[2] <= 0) goto L53fe90;  // @5_53fe30
  eax = (eax + (u32)(-1));  // @6_53fe30
  FL[3] = eax;  // @7_53fe30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 247), &v, sizeof v); }  // @8_53fe30
  if (FL[3] != 0) goto L53fe90;  // @9_53fe30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 271), &v, sizeof v); }  // @10_53fe30
  L53fe89:;
  __asm__ volatile("fldz" ::: "st");  // @12_53fe30
  goto L5403ce;  // @13_53fe30
  L53fe90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @15_53fe30
  edx = (u32)(esi + 259);  // @16_53fe30
  PV[0] = (u32)(edx);  // @17_53fe30
  ebx = (u32)(esi + 211);  // @18_53fe30
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 65904), &v, sizeof v); }  // @19_53fe30
  PV[1] = (u32)(ebx);  // @20_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_53fe30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[1], PV[0]);  // @22_53fe30
  ecx = edx = 0;  // @23_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @24_53fe30
  X0[1] = 0;  // @25_53fe30
  X0[2] = 0;  // @26_53fe30
  X0[3] = 0;  // @27_53fe30
  PV[2] = (u32)(ecx);  // @28_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @29_53fe30
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(EBP - 65916), &v, sizeof v); }  // @30_53fe30
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(EBP - 65912), &v, sizeof v); }  // @31_53fe30
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(EBP - 65908), &v, sizeof v); }  // @32_53fe30
  PV[3] = X0[0];  // @33_53fe30
  eax = ext_546860_thiscall2(ecx, PV[3]);  // @34_53fe30
  ecx = edx = 0;  // @35_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @36_53fe30
  eax = (u32)(EBP - 65744);  // @37_53fe30
  PV[4] = (u32)(eax);  // @38_53fe30
  eax = (u32)(EBP - 65920);  // @39_53fe30
  { u32 v = (u32)((u32)(1343554297)); __builtin_memcpy((void *)(u32)(EBP - 65564), &v, sizeof v); }  // @40_53fe30
  PV[5] = (u32)(eax);  // @41_53fe30
  eax = (u32)(EBP - 65792);  // @42_53fe30
  { u32 v = (u32)((u32)(1343554297)); __builtin_memcpy((void *)(u32)(EBP - 65560), &v, sizeof v); }  // @43_53fe30
  PV[6] = (u32)(eax);  // @44_53fe30
  eax = (u32)(EBP - 65684);  // @45_53fe30
  { u32 v = (u32)((u32)(1343554297)); __builtin_memcpy((void *)(u32)(EBP - 65556), &v, sizeof v); }  // @46_53fe30
  PV[7] = (u32)(eax);  // @47_53fe30
  { u32 v = (u32)((u32)(3491037945)); __builtin_memcpy((void *)(u32)(EBP - 65576), &v, sizeof v); }  // @48_53fe30
  { u32 v = (u32)((u32)(3491037945)); __builtin_memcpy((void *)(u32)(EBP - 65572), &v, sizeof v); }  // @49_53fe30
  { u32 v = (u32)((u32)(3491037945)); __builtin_memcpy((void *)(u32)(EBP - 65568), &v, sizeof v); }  // @50_53fe30
  eax = ext_545cb0_thiscall6(ecx, (u32)(1), PV[7], PV[6], PV[5], PV[4]);  // @51_53fe30
  ecx = edx = 0;  // @52_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @53_53fe30
  eax = (u32)(EBP - 65732);  // @54_53fe30
  PV[8] = (u32)(eax);  // @55_53fe30
  eax = (u32)(EBP - 65924);  // @56_53fe30
  PV[9] = (u32)(eax);  // @57_53fe30
  eax = (u32)(EBP - 65804);  // @58_53fe30
  PV[10] = (u32)(eax);  // @59_53fe30
  eax = (u32)(EBP - 65696);  // @60_53fe30
  PV[11] = (u32)(eax);  // @61_53fe30
  eax = ext_545cb0_thiscall6(ecx, (u32)(2), PV[11], PV[10], PV[9], PV[8]);  // @62_53fe30
  ecx = edx = 0;  // @63_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @64_53fe30
  eax = (u32)(EBP - 65756);  // @65_53fe30
  PV[12] = (u32)(eax);  // @66_53fe30
  eax = (u32)(EBP - 65928);  // @67_53fe30
  PV[13] = (u32)(eax);  // @68_53fe30
  eax = (u32)(EBP - 65816);  // @69_53fe30
  PV[14] = (u32)(eax);  // @70_53fe30
  eax = (u32)(EBP - 65708);  // @71_53fe30
  PV[15] = (u32)(eax);  // @72_53fe30
  eax = ext_545cb0_thiscall6(ecx, (u32)(3), PV[15], PV[14], PV[13], PV[12]);  // @73_53fe30
  ecx = edx = 0;  // @74_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @75_53fe30
  eax = (u32)(EBP - 65768);  // @76_53fe30
  PV[16] = (u32)(eax);  // @77_53fe30
  eax = (u32)(EBP - 65932);  // @78_53fe30
  PV[17] = (u32)(eax);  // @79_53fe30
  eax = (u32)(EBP - 65828);  // @80_53fe30
  PV[18] = (u32)(eax);  // @81_53fe30
  eax = (u32)(EBP - 65720);  // @82_53fe30
  PV[19] = (u32)(eax);  // @83_53fe30
  eax = ext_545cb0_thiscall6(ecx, (u32)(4), PV[19], PV[18], PV[17], PV[16]);  // @84_53fe30
  ecx = edx = 0;  // @85_53fe30
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @86_53fe30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 309), sizeof v); (u32)v; });  // @87_53fe30
  if ((s32)FL[0] <= (s32)FL[1]) goto L54010a;  // @88_53fe30
  ebx = 0;  // @89_53fe30
  FL[3] = ebx;  // @90_53fe30
  L53ffd5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @92_53fe30
  X0[1] = 0;  // @93_53fe30
  X0[2] = 0;  // @94_53fe30
  X0[3] = 0;  // @95_53fe30
  edx = (u32)(EBP - 65684);  // @96_53fe30
  PV[20] = (u32)(ecx);  // @97_53fe30
  ecx = (u32)(EBP - 65612);  // @98_53fe30
  PV[21] = X0[0];  // @99_53fe30
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[21]);  // @100_53fe30
    // @101_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @102_53fe30
  X0[1] = 0;  // @103_53fe30
  X0[2] = 0;  // @104_53fe30
  X0[3] = 0;  // @105_53fe30
  edx = (u32)(EBP - 65696);  // @106_53fe30
  PV[22] = (u32)(ecx);  // @107_53fe30
  ecx = (u32)(EBP - 65612);  // @108_53fe30
  PV[23] = X0[0];  // @109_53fe30
  eax = ext_451890_fastcall3(ecx, edx, PV[23]);  // @110_53fe30
  ecx = 0;  // @111_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @112_53fe30
  X0[1] = 0;  // @113_53fe30
  X0[2] = 0;  // @114_53fe30
  X0[3] = 0;  // @115_53fe30
  edx = (u32)(EBP - 65708);  // @116_53fe30
  PV[24] = (u32)(ecx);  // @117_53fe30
  ecx = (u32)(EBP - 65612);  // @118_53fe30
  PV[25] = X0[0];  // @119_53fe30
  eax = ext_451890_fastcall3(ecx, edx, PV[25]);  // @120_53fe30
  ecx = 0;  // @121_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @122_53fe30
  X0[1] = 0;  // @123_53fe30
  X0[2] = 0;  // @124_53fe30
  X0[3] = 0;  // @125_53fe30
  edx = (u32)(EBP - 65720);  // @126_53fe30
  PV[26] = (u32)(ecx);  // @127_53fe30
  ecx = (u32)(EBP - 65612);  // @128_53fe30
  PV[27] = X0[0];  // @129_53fe30
  eax = ext_451890_fastcall3(ecx, edx, PV[27]);  // @130_53fe30
  ecx = 0;  // @131_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @132_53fe30
  X0[1] = 0;  // @133_53fe30
  X0[2] = 0;  // @134_53fe30
  X0[3] = 0;  // @135_53fe30
  edx = (u32)(EBP - 65744);  // @136_53fe30
  PV[28] = (u32)(ecx);  // @137_53fe30
  ecx = (u32)(EBP - 65588);  // @138_53fe30
  PV[29] = X0[0];  // @139_53fe30
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[29]);  // @140_53fe30
    // @141_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @142_53fe30
  X0[1] = 0;  // @143_53fe30
  X0[2] = 0;  // @144_53fe30
  X0[3] = 0;  // @145_53fe30
  edx = (u32)(EBP - 65732);  // @146_53fe30
  PV[30] = (u32)(ecx);  // @147_53fe30
  ecx = (u32)(EBP - 65588);  // @148_53fe30
  PV[31] = X0[0];  // @149_53fe30
  eax = ext_451890_fastcall3(ecx, edx, PV[31]);  // @150_53fe30
  ecx = 0;  // @151_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @152_53fe30
  X0[1] = 0;  // @153_53fe30
  X0[2] = 0;  // @154_53fe30
  X0[3] = 0;  // @155_53fe30
  edx = (u32)(EBP - 65756);  // @156_53fe30
  PV[32] = (u32)(ecx);  // @157_53fe30
  ecx = (u32)(EBP - 65588);  // @158_53fe30
  PV[33] = X0[0];  // @159_53fe30
  eax = ext_451890_fastcall3(ecx, edx, PV[33]);  // @160_53fe30
  ecx = 0;  // @161_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @162_53fe30
  X0[1] = 0;  // @163_53fe30
  X0[2] = 0;  // @164_53fe30
  X0[3] = 0;  // @165_53fe30
  edx = (u32)(EBP - 65768);  // @166_53fe30
  PV[34] = (u32)(ecx);  // @167_53fe30
  ecx = (u32)(EBP - 65588);  // @168_53fe30
  PV[35] = X0[0];  // @169_53fe30
  eax = ext_451890_fastcall3(ecx, edx, PV[35]);  // @170_53fe30
  ecx = 0;  // @171_53fe30
  edx = (u32)(EBP - 65612);  // @172_53fe30
  ecx = (u32)(EBP - 65576);  // @173_53fe30
  eax = ext_4e08d0_fastcall2(ecx, edx);  // @174_53fe30
    // @175_53fe30
  edx = (u32)(EBP - 65612);  // @176_53fe30
  ecx = (u32)(EBP - 65564);  // @177_53fe30
  eax = ext_4e0900_fastcall2(ecx, edx);  // @178_53fe30
    // @179_53fe30
  edx = (u32)(EBP - 65588);  // @180_53fe30
  ecx = (u32)(EBP - 65576);  // @181_53fe30
  eax = ext_4e08d0_fastcall2(ecx, edx);  // @182_53fe30
    // @183_53fe30
  edx = (u32)(EBP - 65588);  // @184_53fe30
  ecx = (u32)(EBP - 65564);  // @185_53fe30
  eax = ext_4e0900_fastcall2(ecx, edx);  // @186_53fe30
    // @187_53fe30
  ebx = (ebx + 1);  // @188_53fe30
  FL[3] = ebx;  // @189_53fe30
  edi = (u32)(edi + 20);  // @190_53fe30
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 102), sizeof v); (u32)v; });  // @191_53fe30
  if ((s32)FL[0] < (s32)FL[1]) goto L53ffd5;  // @192_53fe30
  ebx = (u32)(esi + 211);  // @193_53fe30
  L54010a:;
  eax = (u32)(EBP - 65576);  // @195_53fe30
  PV[36] = (u32)(eax);  // @196_53fe30
  edx = (u32)(EBP - 65564);  // @197_53fe30
  ecx = (u32)(EBP - 65660);  // @198_53fe30
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[36]);  // @199_53fe30
  ecx = edx = 0;  // @200_53fe30
  PV[37] = (u32)(ecx);  // @201_53fe30
  ecx = (u32)(EBP - 65660);  // @202_53fe30
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @203_53fe30
    // @204_53fe30
  eax = (u32)(EBP - 65564);  // @205_53fe30
  PV[38] = (u32)(eax);  // @206_53fe30
  edx = (u32)(EBP - 65576);  // @207_53fe30
  ecx = (u32)(EBP - 65672);  // @208_53fe30
  eax = ext_43e920_fastcall3(ecx, edx, PV[38]);  // @209_53fe30
  ecx = edx = 0;  // @210_53fe30
  PV[39] = (u32)(ecx);  // @211_53fe30
  ecx = (u32)(EBP - 65672);  // @212_53fe30
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @213_53fe30
    // @214_53fe30
  edx = (u32)(EBP - 65916);  // @215_53fe30
  ecx = (u32)(EBP - 65600);  // @216_53fe30
  eax = ext_441940_fastcall2(ecx, edx);  // @217_53fe30
  ecx = edx = 0;  // @218_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65660) + 0), 4); v; });  // @219_53fe30
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65660) + 4), 4); v; });  // @220_53fe30
  X0[2] = 0;  // @221_53fe30
  X0[3] = 0;  // @222_53fe30
  edi = 0;  // @223_53fe30
  FL[3] = edi;  // @224_53fe30
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 342), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @225_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65652), sizeof v); (u32)v; });  // @226_53fe30
  __builtin_memcpy((void *)((u32)(EBP - 65624) + 0), &X0[0], 4);  // @227_53fe30
  __builtin_memcpy((void *)((u32)(EBP - 65624) + 4), &X0[1], 4);  // @228_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65672) + 0), 4); v; });  // @229_53fe30
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65672) + 4), 4); v; });  // @230_53fe30
  X0[2] = 0;  // @231_53fe30
  X0[3] = 0;  // @232_53fe30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65616), &v, sizeof v); }  // @233_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65664), sizeof v); (u32)v; });  // @234_53fe30
  __builtin_memcpy((void *)((u32)(EBP - 65600) + 0), &X0[0], 4);  // @235_53fe30
  __builtin_memcpy((void *)((u32)(EBP - 65600) + 4), &X0[1], 4);  // @236_53fe30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65592), &v, sizeof v); }  // @237_53fe30
  if (FL[0] == FL[1]) goto L54023b;  // @238_53fe30
  ecx = (u32)(EBP - 65864);  // @239_53fe30
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 98), sizeof v); (u32)v; }); FL[1] = edi;  // @240_53fe30
  if (FL[0] != FL[1]) goto L54021b;  // @241_53fe30
  eax = ext_4de7a0_thiscall1(ecx);  // @242_53fe30
    // @243_53fe30
  eax = ext_41e290_cdecl1((u32)(147));  // @244_53fe30
  ecx = edx = 0;  // @245_53fe30
  ecx = eax;  // @246_53fe30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 65936), &v, sizeof v); }  // @247_53fe30
  reg.state = (s32)(edi);  // @248_53fe30
  FL[2] = (ecx & ecx);  // @249_53fe30
  if (FL[2] == 0) goto L540207;  // @250_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @251_53fe30
  PV[40] = (u32)(edi);  // @252_53fe30
  PV[41] = (u32)(ecx);  // @253_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @254_53fe30
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @255_53fe30
  eax = ext_6353d0_thiscall5(ecx, PV[42], (u32)(1092616192), (u32)(32), PV[40]);  // @256_53fe30
  ecx = edx = 0;  // @257_53fe30
  goto L540209;  // @258_53fe30
  L540207:;
  eax = 0;  // @260_53fe30
  FL[3] = eax;  // @261_53fe30
  L540209:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 98), &v, sizeof v); }  // @263_53fe30
  reg.state = (s32)((u32)(4294967295));  // @264_53fe30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 111), &v, sizeof v); }  // @265_53fe30
  w4i_pp = 1;   // w4i: `push 1` of the allocate path (the lifter kept one constant for both paths)
  goto L540222;  // @266_53fe30
  L54021b:;
  eax = ext_4de7a0_thiscall1(ecx);  // @268_53fe30
    // @269_53fe30
  L540222:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 98), sizeof v); (u32)v; });  // @271_53fe30
  eax = (u32)(EBP - 65600);  // @272_53fe30
  PV[43] = (u32)(eax);  // @273_53fe30
  PV[44] = (u32)(ebx);  // @274_53fe30
  eax = (u32)(EBP - 65624);  // @275_53fe30
  PV[45] = (u32)(eax);  // @276_53fe30
  eax = ext_635eb0_thiscall5(ecx, PV[45], PV[44], PV[43], w4i_pp);  // @277_53fe30
  ecx = edx = 0;  // @278_53fe30
  goto L54027b;  // @279_53fe30
  L54023b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @281_53fe30
  edx = (u32)(EBP - 65552);  // @282_53fe30
  PV[46] = (u32)(edx);  // @283_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @284_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @285_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @286_53fe30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[46], (u32)(65536));   // w4i: the exe pushes 2 args (the `push 1` belongs to the other path)  // @287_53fe30
  ecx = edx = 0;  // @288_53fe30
  edi = eax;  // @289_53fe30
  eax = (u32)(EBP - 65600);  // @290_53fe30
  PV[47] = (u32)(eax);  // @291_53fe30
  eax = (u32)(EBP - 65624);  // @292_53fe30
  ecx = edi;  // @293_53fe30
  PV[48] = (u32)(eax);  // @294_53fe30
  PV[49] = (u32)(ebx);  // @295_53fe30
  eax = ext_4eb020_thiscall4(ecx, PV[49], PV[48], PV[47]);  // @296_53fe30
  ecx = edx = 0;  // @297_53fe30
  ecx = edi;  // @298_53fe30
  eax = ext_4ea300_thiscall2(ecx, (u32)(32));  // @299_53fe30
  ecx = edx = 0;  // @300_53fe30
  L54027b:;
  PV[50] = (u32)(edi);  // @302_53fe30
  ecx = esi;  // @303_53fe30
  eax = ext_53d230_thiscall3(ecx, PV[50], (u32)(1));  // @304_53fe30
  ecx = edx = 0;  // @305_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @306_53fe30
  eax = ext_546d70_fastcall2(ecx, edx);  // @307_53fe30
  ecx = edx = 0;  // @308_53fe30
  PV[51] = (u32)(edi);  // @309_53fe30
  ecx = esi;  // @310_53fe30
  eax = ext_53d230_thiscall3(ecx, PV[51], (u32)(0));  // @311_53fe30
  ecx = edx = 0;  // @312_53fe30
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 342), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @313_53fe30
  if (FL[0] != FL[1]) goto L5402b7;  // @314_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @315_53fe30
  PV[52] = (u32)(edi);  // @316_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @317_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @318_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @319_53fe30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[52]);  // @320_53fe30
  ecx = edx = 0;  // @321_53fe30
  L5402b7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @323_53fe30
  edx = (u32)(EBP - 65780);  // @324_53fe30
  PV[53] = (u32)(edx);  // @325_53fe30
  edx = (u32)(EBP - 65900);  // @326_53fe30
  PV[54] = (u32)(edx);  // @327_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @328_53fe30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[54], PV[53]);  // @329_53fe30
  ecx = edx = 0;  // @330_53fe30
  ecx = esi;  // @331_53fe30
  eax = ext_5407c0_thiscall1(ecx);  // @332_53fe30
  ecx = edx = 0;  // @333_53fe30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @334_53fe30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65904), sizeof v); (u32)v; });  // @335_53fe30
  PV[55] = (u32)(esi);  // @336_53fe30
  PV[56] = (u32)(ebx);  // @337_53fe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @338_53fe30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[56], PV[55]);  // @339_53fe30
  ecx = edx = 0;  // @340_53fe30
  PV[57] = (u32)(esi);  // @341_53fe30
  edx = (u32)(EBP - 65780);  // @342_53fe30
  ecx = (u32)(EBP - 65948);  // @343_53fe30
  eax = ext_43e920_fastcall3(ecx, edx, PV[57]);  // @344_53fe30
  ecx = edx = 0;  // @345_53fe30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956280) + 0), 4); v; });  // @346_53fe30
  X0[1] = 0;  // @347_53fe30
  X0[2] = 0;  // @348_53fe30
  X0[3] = 0;  // @349_53fe30
  FC0 = U2F(X0[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65680) + 0), 4); v; }));  // @350_53fe30
  if ((!(!(FC0 >= FC1)) && !(!((FC0 < FC1) || (FC0 > FC1))))) goto L53fe89;  // @351_53fe30
  eax = (u32)(EBP - 65696);  // @352_53fe30
  PV[58] = (u32)(eax);  // @353_53fe30
  edx = (u32)(EBP - 65684);  // @354_53fe30
  ecx = (u32)(EBP - 65648);  // @355_53fe30
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[58]);  // @356_53fe30
  ecx = edx = 0;  // @357_53fe30
  edx = (u32)(EBP - 65708);  // @358_53fe30
  ecx = (u32)(EBP - 65648);  // @359_53fe30
  eax = ext_441940_fastcall2(ecx, edx);  // @360_53fe30
  ecx = edx = 0;  // @361_53fe30
  edx = (u32)(EBP - 65720);  // @362_53fe30
  ecx = (u32)(EBP - 65648);  // @363_53fe30
  eax = ext_441940_fastcall2(ecx, edx);  // @364_53fe30
  ecx = edx = 0;  // @365_53fe30
  eax = (u32)(EBP - 65732);  // @366_53fe30
  PV[59] = (u32)(eax);  // @367_53fe30
  edx = (u32)(EBP - 65744);  // @368_53fe30
  ecx = (u32)(EBP - 65636);  // @369_53fe30
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[59]);  // @370_53fe30
  ecx = edx = 0;  // @371_53fe30
  edx = (u32)(EBP - 65756);  // @372_53fe30
  ecx = (u32)(EBP - 65636);  // @373_53fe30
  eax = ext_441940_fastcall2(ecx, edx);  // @374_53fe30
  ecx = edx = 0;  // @375_53fe30
  edx = (u32)(EBP - 65768);  // @376_53fe30
  ecx = (u32)(EBP - 65636);  // @377_53fe30
  eax = ext_441940_fastcall2(ecx, edx);  // @378_53fe30
  ecx = edx = 0;  // @379_53fe30
  PV[60] = (u32)(ecx);  // @380_53fe30
  ecx = (u32)(EBP - 65648);  // @381_53fe30
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1048576000));  // @382_53fe30
    // @383_53fe30
  PV[61] = (u32)(ecx);  // @384_53fe30
  ecx = (u32)(EBP - 65636);  // @385_53fe30
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1048576000));  // @386_53fe30
    // @387_53fe30
  edx = (u32)(EBP - 65636);  // @388_53fe30
  ecx = (u32)(EBP - 65648);  // @389_53fe30
  eax = ext_4e0870_fastcall2(ecx, edx);  // @390_53fe30
  ecx = edx = 0;  // @391_53fe30
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(6784464)) : "st");  // @392_53fe30
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 8)) : "st");  // @393_53fe30
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(6912128)) : "st");  // @394_53fe30
  __asm__ volatile(".byte 0xd8, 0xf9" ::: "st");  // @395_53fe30
  __asm__ volatile(".byte 0xde, 0xc9" ::: "st");  // @396_53fe30
  __asm__ volatile(".byte 0xde, 0xf9" ::: "st");  // @397_53fe30
  L5403ce:;
  SEH_LEAVE();  // @399_53fe30
  ext_633654(G(u32, 0x6f5630));  // @400_53fe30
  return eax;  // @401_53fe30
}
PCREG(53fe30, lifted_53fe30);

