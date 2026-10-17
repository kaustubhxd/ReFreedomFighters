// batch242013.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4e0ab0_fastcall3(u32, u32, u32) __asm__("ext_4e0ab0");
extern "C" u32 THISCALL ext_4ff4a0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4ff4a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4fed00(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ecx;  // @0_4fed00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @1_4fed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4fed00
  edx = (u32)(EBP - 28);  // @3_4fed00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @4_4fed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_4fed00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @6_4fed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @7_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @8_4fed00
  X0[1] = 0;  // @9_4fed00
  X0[2] = 0;  // @10_4fed00
  X0[3] = 0;  // @11_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X0[0], 4);  // @12_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @13_4fed00
  X0[1] = 0;  // @14_4fed00
  X0[2] = 0;  // @15_4fed00
  X0[3] = 0;  // @16_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 152) + 0), &X0[0], 4);  // @17_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @18_4fed00
  X0[1] = 0;  // @19_4fed00
  X0[2] = 0;  // @20_4fed00
  X0[3] = 0;  // @21_4fed00
  eax = (u32)(EBP - 156);  // @22_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 148) + 0), &X0[0], 4);  // @23_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @24_4fed00
  X0[1] = 0;  // @25_4fed00
  X0[2] = 0;  // @26_4fed00
  X0[3] = 0;  // @27_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @28_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; });  // @29_4fed00
  X0[1] = 0;  // @30_4fed00
  X0[2] = 0;  // @31_4fed00
  X0[3] = 0;  // @32_4fed00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @34_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; });  // @35_4fed00
  X0[1] = 0;  // @36_4fed00
  X0[2] = 0;  // @37_4fed00
  X0[3] = 0;  // @38_4fed00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @39_4fed00
  ecx = (u32)(EBP - 16);  // @40_4fed00
  PV[0] = (u32)(eax);  // @41_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @42_4fed00
  eax = ext_43e920_fastcall3(ecx, edx, PV[0]);  // @43_4fed00
  ecx = edx = 0;  // @44_4fed00
  edx = (u32)(EBP - 16);  // @45_4fed00
  ecx = (u32)(EBP - 76);  // @46_4fed00
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @47_4fed00
  ecx = edx = 0;  // @48_4fed00
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @49_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @50_4fed00
  X0[1] = 0;  // @51_4fed00
  X0[2] = 0;  // @52_4fed00
  X0[3] = 0;  // @53_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @54_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @55_4fed00
  X0[1] = 0;  // @56_4fed00
  X0[2] = 0;  // @57_4fed00
  X0[3] = 0;  // @58_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @59_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @60_4fed00
  X0[1] = 0;  // @61_4fed00
  X0[2] = 0;  // @62_4fed00
  X0[3] = 0;  // @63_4fed00
  PV[1] = (u32)(ecx);  // @64_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @65_4fed00
  ecx = (u32)(EBP - 16);  // @66_4fed00
  if (FL[0] == FL[1]) goto L4fedc2;  // @67_4fed00
  goto L4fedc9;  // @68_4fed00
  L4fedc2:;
  L4fedc9:;
  eax = ext_4e0d00_thiscall2(ecx, ((u8)a4 == 0) ? (u32)0xc2480000u : (u32)0x42480000u);   // hand fix: the lifter kept only one arm of the `mov [esp], +-50.0f` diamond  // @71_4fed00
    // @72_4fed00
  eax = (u32)(EBP - 16);  // @73_4fed00
  PV[2] = (u32)(eax);  // @74_4fed00
  edx = (u32)(EBP - 156);  // @75_4fed00
  ecx = (u32)(EBP - 132);  // @76_4fed00
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[2]);  // @77_4fed00
  ecx = edx = 0;  // @78_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @79_4fed00
  X0[1] = 0;  // @80_4fed00
  X0[2] = 0;  // @81_4fed00
  X0[3] = 0;  // @82_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @83_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @84_4fed00
  X0[1] = 0;  // @85_4fed00
  X0[2] = 0;  // @86_4fed00
  X0[3] = 0;  // @87_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @88_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @89_4fed00
  X0[1] = 0;  // @90_4fed00
  X0[2] = 0;  // @91_4fed00
  X0[3] = 0;  // @92_4fed00
  PV[3] = (u32)(ecx);  // @93_4fed00
  ecx = (u32)(EBP - 16);  // @94_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @95_4fed00
  eax = ext_4e0d00_thiscall2(ecx, (u32)(3256877056));  // @96_4fed00
    // @97_4fed00
  edx = (u32)(EBP - 16);  // @98_4fed00
  ecx = (u32)(EBP - 132);  // @99_4fed00
  eax = ext_441940_fastcall2(ecx, edx);  // @100_4fed00
  ecx = edx = 0;  // @101_4fed00
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @102_4fed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @103_4fed00
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 92) + 0), 4); v; });  // @104_4fed00
  X1[1] = 0;  // @105_4fed00
  X1[2] = 0;  // @106_4fed00
  X1[3] = 0;  // @107_4fed00
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791816) + 0), 4); v; })));  // @108_4fed00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @109_4fed00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @110_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @111_4fed00
  if (FL[0] == FL[1]) goto L4fee54;  // @112_4fed00
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @113_4fed00
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @114_4fed00
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @115_4fed00
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @116_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @117_4fed00
  L4fee54:;
  eax = (u32)(EBP - 132);  // @119_4fed00
  PV[4] = (u32)(eax);  // @120_4fed00
  edx = (u32)(EBP - 28);  // @121_4fed00
  ecx = (u32)(EBP - 88);  // @122_4fed00
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @123_4fed00
  ecx = edx = 0;  // @124_4fed00
  eax = (u32)(EBP - 16);  // @125_4fed00
  PV[5] = (u32)(eax);  // @126_4fed00
  edx = (u32)(EBP - 88);  // @127_4fed00
  ecx = (u32)(EBP - 28);  // @128_4fed00
  eax = ext_4e0ab0_fastcall3(ecx, edx, PV[5]);  // @129_4fed00
  ecx = edx = 0;  // @130_4fed00
  edx = (u32)(EBP - 132);  // @131_4fed00
  ecx = (u32)(EBP - 28);  // @132_4fed00
  eax = ext_441940_fastcall2(ecx, edx);  // @133_4fed00
  ecx = edx = 0;  // @134_4fed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @135_4fed00
  edx = (u32)(EBP - 168);  // @136_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 132) + 0), 4); v; });  // @137_4fed00
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 132) + 4), 4); v; });  // @138_4fed00
  X0[2] = 0;  // @139_4fed00
  X0[3] = 0;  // @140_4fed00
  ecx = (u32)(EBP - 100);  // @141_4fed00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @142_4fed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @143_4fed00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @144_4fed00
  eax = (u32)(EBP - 144);  // @145_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 144) + 0), &X0[0], 4);  // @146_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 144) + 4), &X0[1], 4);  // @147_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @148_4fed00
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @149_4fed00
  X0[2] = 0;  // @150_4fed00
  X0[3] = 0;  // @151_4fed00
  PV[6] = (u32)(eax);  // @152_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 168) + 0), &X0[0], 4);  // @153_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 168) + 4), &X0[1], 4);  // @154_4fed00
  eax = ext_43e920_fastcall3(ecx, edx, PV[6]);  // @155_4fed00
  ecx = edx = 0;  // @156_4fed00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @157_4fed00
  edx = (u32)(EBP - 100);  // @158_4fed00
  ecx = esi;  // @159_4fed00
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @160_4fed00
  ecx = edx = 0;  // @161_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 144) + 0), 4); v; });  // @162_4fed00
  X0[1] = 0;  // @163_4fed00
  X0[2] = 0;  // @164_4fed00
  X0[3] = 0;  // @165_4fed00
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @166_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @167_4fed00
  X0[1] = 0;  // @168_4fed00
  X0[2] = 0;  // @169_4fed00
  X0[3] = 0;  // @170_4fed00
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X0[0], 4);  // @171_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 136) + 0), 4); v; });  // @172_4fed00
  X0[1] = 0;  // @173_4fed00
  X0[2] = 0;  // @174_4fed00
  X0[3] = 0;  // @175_4fed00
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @176_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @177_4fed00
  X0[1] = 0;  // @178_4fed00
  X0[2] = 0;  // @179_4fed00
  X0[3] = 0;  // @180_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @181_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @182_4fed00
  X0[1] = 0;  // @183_4fed00
  X0[2] = 0;  // @184_4fed00
  X0[3] = 0;  // @185_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @186_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @187_4fed00
  X0[1] = 0;  // @188_4fed00
  X0[2] = 0;  // @189_4fed00
  X0[3] = 0;  // @190_4fed00
  PV[7] = (u32)(ecx);  // @191_4fed00
  ecx = (u32)(EBP - 40);  // @192_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @193_4fed00
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1092616192));  // @194_4fed00
    // @195_4fed00
  esi = 0;  // @196_4fed00
  FL[3] = esi;  // @197_4fed00
  L4fef30:;
  PV[8] = (u32)(ecx);  // @199_4fed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @200_4fed00
  eax = (u32)(EBP - 180);  // @201_4fed00
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @202_4fed00
  PV[10] = (u32)(edi);  // @203_4fed00
  PV[11] = (u32)(eax);  // @204_4fed00
  eax = ext_4ff4a0_thiscall5(ecx, PV[11], PV[10], PV[9], (u32)(1092616192));   // hand fix: ecx = this  // @205_4fed00
  ecx = edx = 0;  // @206_4fed00
  PV[12] = (u32)(ecx);  // @207_4fed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @208_4fed00
  eax = (u32)(EBP - 180);  // @209_4fed00
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @210_4fed00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 104)) :: "st");  // @211_4fed00
  PV[14] = (u32)(edi);  // @212_4fed00
  PV[15] = (u32)(eax);  // @213_4fed00
  eax = ext_4ff4a0_thiscall5(ecx, PV[15], PV[14], PV[13], (u32)(1092616192));   // hand fix: ecx = this  // @214_4fed00
  ecx = edx = 0;  // @215_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 104) + 0), 4); v; });  // @216_4fed00
  X0[1] = 0;  // @217_4fed00
  X0[2] = 0;  // @218_4fed00
  X0[3] = 0;  // @219_4fed00
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @220_4fed00
  X1[1] = 0;  // @221_4fed00
  X1[2] = 0;  // @222_4fed00
  X1[3] = 0;  // @223_4fed00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @224_4fed00
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @225_4fed00
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @226_4fed00
  if (!__builtin_parity(FL[2] & 0xff)) goto L4fef90;  // @227_4fed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @228_4fed00
  X0[1] = 0;  // @229_4fed00
  X0[2] = 0;  // @230_4fed00
  X0[3] = 0;  // @231_4fed00
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @232_4fed00
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @233_4fed00
  if (__builtin_parity(FL[2] & 0xff)) goto L4fefa0;  // @234_4fed00
  L4fef90:;
  edx = (u32)(EBP - 40);  // @236_4fed00
  ecx = edi;  // @237_4fed00
  eax = ext_441940_fastcall2(ecx, edx);  // @238_4fed00
  ecx = edx = 0;  // @239_4fed00
  esi = (esi + 1);  // @240_4fed00
  FL[3] = esi;  // @241_4fed00
  FL[0] = esi; FL[1] = (u32)(5);  // @242_4fed00
  if (FL[0] != FL[1]) goto L4fef30;  // @243_4fed00
  L4fefa0:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; });  // @245_4fed00
  X1[1] = 0;  // @246_4fed00
  X1[2] = 0;  // @247_4fed00
  X1[3] = 0;  // @248_4fed00
  eax = (u32)(esi + esi*4);  // @249_4fed00
  eax = (eax + eax);  // @250_4fed00
  FL[3] = eax;  // @251_4fed00
  ext_633654(G(u32, 0x6f5630));  // @252_4fed00
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @253_4fed00
  X0[0] = F2U((float)(s32)X0[0]);  // @254_4fed00
  X0[1] = F2U((float)(s32)X0[1]);  // @255_4fed00
  X0[2] = F2U((float)(s32)X0[2]);  // @256_4fed00
  X0[3] = F2U((float)(s32)X0[3]);  // @257_4fed00
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @258_4fed00
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; })));  // @259_4fed00
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X1[0], 4);  // @260_4fed00
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 108)) : "st");  // @261_4fed00
  return eax;  // @262_4fed00
}
PCREG(4fed00, lifted_4fed00);

