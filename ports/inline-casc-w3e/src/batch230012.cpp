// batch230012.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_44f550_fastcall2(u32, u32) __asm__("ext_44f550");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4de4f0_fastcall2(u32, u32) __asm__("ext_4de4f0");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_5af130_fastcall3(u32, u32, u32) __asm__("ext_5af130");
extern "C" u32 THISCALL ext_44ef80_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_44ef80");
extern "C" u32 THISCALL ext_44f0f0_thiscall3(u32, u32, u32) __asm__("ext_44f0f0");
extern "C" u32 THISCALL ext_44f8b0_thiscall4(u32, u32, u32, u32) __asm__("ext_44f8b0");
extern "C" u32 THISCALL ext_450fc0_thiscall3(u32, u32, u32) __asm__("ext_450fc0");
extern "C" u32 THISCALL ext_46abf0_thiscall2(u32, u32) __asm__("ext_46abf0");
extern "C" u32 THISCALL ext_470550_thiscall2(u32, u32) __asm__("ext_470550");
extern "C" u32 THISCALL ext_4730b0_thiscall2(u32, u32) __asm__("ext_4730b0");
extern "C" u32 THISCALL ext_48aad0_thiscall1(u32) __asm__("ext_48aad0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_516b60_thiscall4(u32, u32, u32, u32) __asm__("ext_516b60");
extern "C" u32 THISCALL ext_516f40_thiscall2(u32, u32) __asm__("ext_516f40");
extern "C" u32 THISCALL ext_589c20_thiscall2(u32, u32) __asm__("ext_589c20");
extern "C" u32 THISCALL ext_591080_thiscall1(u32) __asm__("ext_591080");
extern "C" u32 THISCALL ext_591e50_thiscall2(u32, u32) __asm__("ext_591e50");
extern "C" u32 THISCALL ext_594540_thiscall2(u32, u32) __asm__("ext_594540");
extern "C" u32 THISCALL ext_594e30_thiscall2(u32, u32) __asm__("ext_594e30");
extern "C" u32 THISCALL ext_5966e0_thiscall2(u32, u32) __asm__("ext_5966e0");
extern "C" u32 THISCALL ext_596710_thiscall2(u32, u32) __asm__("ext_596710");
extern "C" u32 THISCALL ext_59a580_thiscall4(u32, u32, u32, u32) __asm__("ext_59a580");
extern "C" u32 THISCALL ext_5aeff0_thiscall2(u32, u32) __asm__("ext_5aeff0");
extern "C" u32 THISCALL ext_5afc70_thiscall2(u32, u32) __asm__("ext_5afc70");
extern "C" u32 THISCALL ext_5afd00_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5afd00");
extern "C" u32 THISCALL ext_5afdd0_thiscall2(u32, u32) __asm__("ext_5afdd0");
extern "C" u32 THISCALL ext_5afe20_thiscall2(u32, u32) __asm__("ext_5afe20");
extern "C" u32 THISCALL ext_5e93f0_thiscall3(u32, u32, u32) __asm__("ext_5e93f0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5d99b0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_5d99b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 111), sizeof v); (u32)v; }); X2[1] = X2[2] = X2[3] = 0;  // @2_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 115), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @3_5d99b0
  X2[0] = F2U((float)(s32)X2[0]);  // @4_5d99b0
  X2[1] = F2U((float)(s32)X2[1]);  // @5_5d99b0
  X2[2] = F2U((float)(s32)X2[2]);  // @6_5d99b0
  X2[3] = F2U((float)(s32)X2[3]);  // @7_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @8_5d99b0
  X0[0] = F2U((float)(s32)X0[0]);  // @9_5d99b0
  X0[1] = F2U((float)(s32)X0[1]);  // @10_5d99b0
  X0[2] = F2U((float)(s32)X0[2]);  // @11_5d99b0
  X0[3] = F2U((float)(s32)X0[3]);  // @12_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X2[0], 4);  // @13_5d99b0
  X1[0] = X2[0];  // @14_5d99b0
  X1[1] = X2[1];  // @15_5d99b0
  X1[2] = X2[2];  // @16_5d99b0
  X1[3] = X2[3];  // @17_5d99b0
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6973584) + 0), 4); v; })));  // @18_5d99b0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7038236) + 0), 4); v; })));  // @19_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X1[0], 4);  // @20_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @21_5d99b0
  FL[2] = (eax & eax);  // @22_5d99b0
  if (FL[2] == 0) goto L5d9a10;  // @23_5d99b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @24_5d99b0
  if (FL[0] != FL[1]) goto L5d9a4b;  // @25_5d99b0
  L5d9a10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @27_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5d99b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @29_5d99b0
  ecx = edx = 0;  // @30_5d99b0
  ecx = (u32)(EBP - 29);  // @31_5d99b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 29), &v, sizeof v); }  // @32_5d99b0
  PV[0] = (u32)(ecx);  // @33_5d99b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_5d99b0
  ecx = eax;  // @35_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6805980), PV[0]);  // @36_5d99b0
  ecx = edx = 0;  // @37_5d99b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 29), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @38_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_5d99b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @40_5d99b0
  X1[1] = 0;  // @41_5d99b0
  X1[2] = 0;  // @42_5d99b0
  X1[3] = 0;  // @43_5d99b0
  if (FL[0] == FL[1]) goto L5d9a65;  // @44_5d99b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @45_5d99b0
  X2[1] = 0;  // @46_5d99b0
  X2[2] = 0;  // @47_5d99b0
  X2[3] = 0;  // @48_5d99b0
  L5d9a4b:;
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6835428) + 0), 4); v; })));  // @50_5d99b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6835428) + 0), 4); v; })));  // @51_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X2[0], 4);  // @52_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X1[0], 4);  // @53_5d99b0
  L5d9a65:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @55_5d99b0
  X0[1] = 0;  // @56_5d99b0
  X0[2] = 0;  // @57_5d99b0
  X0[3] = 0;  // @58_5d99b0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @59_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X1[0], 4);  // @60_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @61_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @62_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @64_5d99b0
  ecx = edx = 0;  // @65_5d99b0
  esi = eax;  // @66_5d99b0
  X1[0] = 0;  // @67_5d99b0
  X1[1] = 0;  // @68_5d99b0
  X1[2] = 0;  // @69_5d99b0
  X1[3] = 0;  // @70_5d99b0
  FL[2] = (esi & esi);  // @71_5d99b0
  if (FL[2] == 0) goto L5d9ad9;  // @72_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @73_5d99b0
  X0[1] = 0;  // @74_5d99b0
  X0[2] = 0;  // @75_5d99b0
  X0[3] = 0;  // @76_5d99b0
  ecx = (u32)(EBP - 16);  // @77_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @78_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @79_5d99b0
  X0[1] = 0;  // @80_5d99b0
  X0[2] = 0;  // @81_5d99b0
  X0[3] = 0;  // @82_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7038216) + 0), 4); v; })));  // @83_5d99b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @84_5d99b0
  PV[2] = (u32)(ecx);  // @85_5d99b0
  ecx = esi;  // @86_5d99b0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @87_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @88_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @89_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[2]);  // @90_5d99b0
  ecx = edx = 0;  // @91_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_5d99b0
  ecx = (u32)(EBP - 52);  // @93_5d99b0
  PV[3] = (u32)(ecx);  // @94_5d99b0
  ecx = esi;  // @95_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[3], (u32)(0));  // @96_5d99b0
  ecx = edx = 0;  // @97_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_5d99b0
  ecx = esi;  // @99_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @100_5d99b0
  ecx = edx = 0;  // @101_5d99b0
  L5d9ad9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @103_5d99b0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 112), sizeof v); (u32)v; });  // @104_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @105_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[4]);  // @107_5d99b0
  ecx = edx = 0;  // @108_5d99b0
  esi = eax;  // @109_5d99b0
  FL[2] = (esi & esi);  // @110_5d99b0
  if (FL[2] == 0) goto L5d9b43;  // @111_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @112_5d99b0
  X0[1] = 0;  // @113_5d99b0
  X0[2] = 0;  // @114_5d99b0
  X0[3] = 0;  // @115_5d99b0
  ecx = (u32)(EBP - 16);  // @116_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860556) + 0), 4); v; })));  // @117_5d99b0
  X1[0] = 0;  // @118_5d99b0
  X1[1] = 0;  // @119_5d99b0
  X1[2] = 0;  // @120_5d99b0
  X1[3] = 0;  // @121_5d99b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @122_5d99b0
  PV[5] = (u32)(ecx);  // @123_5d99b0
  ecx = esi;  // @124_5d99b0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @125_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @126_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @127_5d99b0
  X0[1] = 0;  // @128_5d99b0
  X0[2] = 0;  // @129_5d99b0
  X0[3] = 0;  // @130_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7038212) + 0), 4); v; })));  // @131_5d99b0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @132_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @133_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @134_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[5]);  // @135_5d99b0
  ecx = edx = 0;  // @136_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_5d99b0
  ecx = (u32)(EBP - 52);  // @138_5d99b0
  PV[6] = (u32)(ecx);  // @139_5d99b0
  ecx = esi;  // @140_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[6], (u32)(0));  // @141_5d99b0
  ecx = edx = 0;  // @142_5d99b0
  L5d9b43:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @144_5d99b0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @145_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @146_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @147_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[7]);  // @148_5d99b0
  ecx = edx = 0;  // @149_5d99b0
  esi = eax;  // @150_5d99b0
  FL[2] = (esi & esi);  // @151_5d99b0
  if (FL[2] == 0) goto L5d9baf;  // @152_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @153_5d99b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @154_5d99b0
  X1[1] = 0;  // @155_5d99b0
  X1[2] = 0;  // @156_5d99b0
  X1[3] = 0;  // @157_5d99b0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @158_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 115), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @159_5d99b0
  ecx = (u32)(EBP - 16);  // @160_5d99b0
  X0[0] = F2U((float)(s32)X0[0]);  // @161_5d99b0
  X0[1] = F2U((float)(s32)X0[1]);  // @162_5d99b0
  X0[2] = F2U((float)(s32)X0[2]);  // @163_5d99b0
  X0[3] = F2U((float)(s32)X0[3]);  // @164_5d99b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @165_5d99b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @166_5d99b0
  PV[8] = (u32)(ecx);  // @167_5d99b0
  ecx = esi;  // @168_5d99b0
  SD(&X1[0], U2D(X1[0], X1[1]) + U2D(X1[0], X1[1]));  // @169_5d99b0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @170_5d99b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(X1[0], X1[1]));  // @171_5d99b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @172_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @173_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @174_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[8]);  // @175_5d99b0
  ecx = edx = 0;  // @176_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_5d99b0
  ecx = (u32)(EBP - 52);  // @178_5d99b0
  PV[9] = (u32)(ecx);  // @179_5d99b0
  ecx = esi;  // @180_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[9], (u32)(0));  // @181_5d99b0
  ecx = edx = 0;  // @182_5d99b0
  L5d9baf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @184_5d99b0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 88), sizeof v); (u32)v; });  // @185_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @186_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @187_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[10]);  // @188_5d99b0
  ecx = edx = 0;  // @189_5d99b0
  esi = eax;  // @190_5d99b0
  FL[2] = (esi & esi);  // @191_5d99b0
  if (FL[2] == 0) goto L5d9c24;  // @192_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @193_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @194_5d99b0
  X0[1] = 0;  // @195_5d99b0
  X0[2] = 0;  // @196_5d99b0
  X0[3] = 0;  // @197_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @198_5d99b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 115), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @199_5d99b0
  ecx = (u32)(EBP - 16);  // @200_5d99b0
  X1[0] = F2U((float)(s32)X1[0]);  // @201_5d99b0
  X1[1] = F2U((float)(s32)X1[1]);  // @202_5d99b0
  X1[2] = F2U((float)(s32)X1[2]);  // @203_5d99b0
  X1[3] = F2U((float)(s32)X1[3]);  // @204_5d99b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @205_5d99b0
  PV[11] = (u32)(ecx);  // @206_5d99b0
  ecx = esi;  // @207_5d99b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @208_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @209_5d99b0
  X0[1] = 0;  // @210_5d99b0
  X0[2] = 0;  // @211_5d99b0
  X0[3] = 0;  // @212_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @213_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @214_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @215_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[11]);  // @216_5d99b0
  ecx = edx = 0;  // @217_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @218_5d99b0
  ecx = (u32)(EBP - 52);  // @219_5d99b0
  PV[12] = (u32)(ecx);  // @220_5d99b0
  ecx = esi;  // @221_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[12], (u32)(0));  // @222_5d99b0
  ecx = edx = 0;  // @223_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @224_5d99b0
  ecx = esi;  // @225_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @226_5d99b0
  ecx = edx = 0;  // @227_5d99b0
  L5d9c24:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @229_5d99b0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; });  // @230_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @231_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @232_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[13]);  // @233_5d99b0
  ecx = edx = 0;  // @234_5d99b0
  esi = eax;  // @235_5d99b0
  FL[2] = (esi & esi);  // @236_5d99b0
  if (FL[2] == 0) goto L5d9cb4;  // @237_5d99b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @238_5d99b0
  ecx = esi;  // @239_5d99b0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; });  // @240_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 648)))(ecx, PV[14], (u32)(7038148));  // @241_5d99b0
  ecx = edx = 0;  // @242_5d99b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @243_5d99b0
  X1[1] = 0;  // @244_5d99b0
  X1[2] = 0;  // @245_5d99b0
  X1[3] = 0;  // @246_5d99b0
  ecx = (u32)(EBP - 16);  // @247_5d99b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7038228) + 0), 4); v; })));  // @248_5d99b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @249_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @250_5d99b0
  X0[1] = 0;  // @251_5d99b0
  X0[2] = 0;  // @252_5d99b0
  X0[3] = 0;  // @253_5d99b0
  PV[15] = (u32)(ecx);  // @254_5d99b0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @255_5d99b0
  ecx = esi;  // @256_5d99b0
  X1[0] = 0;  // @257_5d99b0
  X1[1] = 0;  // @258_5d99b0
  X1[2] = 0;  // @259_5d99b0
  X1[3] = 0;  // @260_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @261_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @262_5d99b0
  X0[1] = 0;  // @263_5d99b0
  X0[2] = 0;  // @264_5d99b0
  X0[3] = 0;  // @265_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7038224) + 0), 4); v; })));  // @266_5d99b0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @267_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @268_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @269_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[15]);  // @270_5d99b0
  ecx = edx = 0;  // @271_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @272_5d99b0
  ecx = (u32)(EBP - 52);  // @273_5d99b0
  PV[16] = (u32)(ecx);  // @274_5d99b0
  ecx = esi;  // @275_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[16], (u32)(0));  // @276_5d99b0
  ecx = edx = 0;  // @277_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @278_5d99b0
  ecx = esi;  // @279_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @280_5d99b0
  ecx = edx = 0;  // @281_5d99b0
  L5d9cb4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @283_5d99b0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; });  // @284_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @285_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @286_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[17]);  // @287_5d99b0
  ecx = edx = 0;  // @288_5d99b0
  esi = eax;  // @289_5d99b0
  FL[2] = (esi & esi);  // @290_5d99b0
  if (FL[2] == 0) goto L5d9d44;  // @291_5d99b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @292_5d99b0
  ecx = esi;  // @293_5d99b0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; });  // @294_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 648)))(ecx, PV[18], (u32)(7038160));  // @295_5d99b0
  ecx = edx = 0;  // @296_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @297_5d99b0
  X0[1] = 0;  // @298_5d99b0
  X0[2] = 0;  // @299_5d99b0
  X0[3] = 0;  // @300_5d99b0
  ecx = (u32)(EBP - 16);  // @301_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7038228) + 0), 4); v; })));  // @302_5d99b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @303_5d99b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @304_5d99b0
  X1[1] = 0;  // @305_5d99b0
  X1[2] = 0;  // @306_5d99b0
  X1[3] = 0;  // @307_5d99b0
  PV[19] = (u32)(ecx);  // @308_5d99b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @309_5d99b0
  ecx = esi;  // @310_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @311_5d99b0
  X0[1] = 0;  // @312_5d99b0
  X0[2] = 0;  // @313_5d99b0
  X0[3] = 0;  // @314_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7038220) + 0), 4); v; })));  // @315_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X1[0], 4);  // @316_5d99b0
  X1[0] = 0;  // @317_5d99b0
  X1[1] = 0;  // @318_5d99b0
  X1[2] = 0;  // @319_5d99b0
  X1[3] = 0;  // @320_5d99b0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @321_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @322_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @323_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[19]);  // @324_5d99b0
  ecx = edx = 0;  // @325_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_5d99b0
  ecx = (u32)(EBP - 52);  // @327_5d99b0
  PV[20] = (u32)(ecx);  // @328_5d99b0
  ecx = esi;  // @329_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[20], (u32)(0));  // @330_5d99b0
  ecx = edx = 0;  // @331_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @332_5d99b0
  ecx = esi;  // @333_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @334_5d99b0
  ecx = edx = 0;  // @335_5d99b0
  L5d9d44:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 116), sizeof v); (u32)v; });  // @337_5d99b0
  esi = 0;  // @338_5d99b0
  FL[3] = esi;  // @339_5d99b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @340_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 120), sizeof v); (u32)v; });  // @341_5d99b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @342_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 124), sizeof v); (u32)v; });  // @343_5d99b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @344_5d99b0
  L5d9d60:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @346_5d99b0
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 28), sizeof v); (u32)v; });  // @347_5d99b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @348_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @349_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[21]);  // @350_5d99b0
  ecx = edx = 0;  // @351_5d99b0
  edi = eax;  // @352_5d99b0
  FL[2] = (edi & edi);  // @353_5d99b0
  if (FL[2] == 0) goto L5d9df7;  // @354_5d99b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @355_5d99b0
  ecx = edi;  // @356_5d99b0
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; });  // @357_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 648)))(ecx, PV[22], (u32)(6790764));  // @358_5d99b0
  ecx = edx = 0;  // @359_5d99b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @360_5d99b0
  X0[1] = 0;  // @361_5d99b0
  X0[2] = 0;  // @362_5d99b0
  X0[3] = 0;  // @363_5d99b0
  ecx = (u32)(EBP - 16);  // @364_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7038232) + 0), 4); v; })));  // @365_5d99b0
  X1[0] = 0;  // @366_5d99b0
  X1[1] = 0;  // @367_5d99b0
  X1[2] = 0;  // @368_5d99b0
  X1[3] = 0;  // @369_5d99b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @370_5d99b0
  PV[23] = (u32)(ecx);  // @371_5d99b0
  ecx = edi;  // @372_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @373_5d99b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @374_5d99b0
  X0[0] = F2U((float)(s32)X0[0]);  // @375_5d99b0
  X0[1] = F2U((float)(s32)X0[1]);  // @376_5d99b0
  X0[2] = F2U((float)(s32)X0[2]);  // @377_5d99b0
  X0[3] = F2U((float)(s32)X0[3]);  // @378_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @379_5d99b0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6866764) + 0), 4); v; })));  // @380_5d99b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @381_5d99b0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @382_5d99b0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @383_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @384_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[23]);  // @385_5d99b0
  ecx = edx = 0;  // @386_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @387_5d99b0
  ecx = (u32)(EBP - 52);  // @388_5d99b0
  PV[24] = (u32)(ecx);  // @389_5d99b0
  ecx = edi;  // @390_5d99b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[24], (u32)(0));  // @391_5d99b0
  ecx = edx = 0;  // @392_5d99b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @393_5d99b0
  ecx = edi;  // @394_5d99b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @395_5d99b0
  ecx = edx = 0;  // @396_5d99b0
  L5d9df7:;
  esi = (esi + 1);  // @398_5d99b0
  FL[3] = esi;  // @399_5d99b0
  FL[0] = esi; FL[1] = (u32)(3);  // @400_5d99b0
  if ((s32)FL[0] < (s32)FL[1]) goto L5d9d60;  // @401_5d99b0
  ext_633654(G(u32, 0x6f5630));  // @402_5d99b0
  return eax;  // @403_5d99b0
}
PCREG(5d99b0, lifted_5d99b0);

extern "C" u32 THISCALL lifted_528260(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_528260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 137), sizeof v); (u32)v; });  // @1_528260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @2_528260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }  // @3_528260
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @4_528260
  FL[2] = (edi & edi);  // @5_528260
  if (FL[2] == 0) goto L528614;  // @6_528260
  L5282a0:;
  ecx = edi;  // @8_528260
  eax = ext_4dc110_thiscall1(ecx);  // @9_528260
  ecx = 0;  // @10_528260
  edx = (u32)(6948984);  // @11_528260
  ecx = eax;  // @12_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @13_528260
  ecx = edx = 0;  // @14_528260
  FL[2] = (eax & eax);  // @15_528260
  if (FL[2] != 0) goto L5282c2;  // @16_528260
  ecx = (u32)(esi + 3701);  // @17_528260
  goto L52839f;  // @18_528260
  L5282c2:;
  ecx = edi;  // @20_528260
  eax = ext_4dc110_thiscall1(ecx);  // @21_528260
  ecx = 0;  // @22_528260
  edx = (u32)(6949000);  // @23_528260
  ecx = eax;  // @24_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @25_528260
  ecx = edx = 0;  // @26_528260
  FL[2] = (eax & eax);  // @27_528260
  if (FL[2] != 0) goto L5282e4;  // @28_528260
  ecx = (u32)(esi + 4008);  // @29_528260
  goto L52839f;  // @30_528260
  L5282e4:;
  ecx = edi;  // @32_528260
  eax = ext_4dc110_thiscall1(ecx);  // @33_528260
  ecx = 0;  // @34_528260
  edx = (u32)(6949016);  // @35_528260
  ecx = eax;  // @36_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @37_528260
  ecx = edx = 0;  // @38_528260
  FL[2] = (eax & eax);  // @39_528260
  if (FL[2] != 0) goto L528306;  // @40_528260
  ecx = (u32)(esi + 4315);  // @41_528260
  goto L52839f;  // @42_528260
  L528306:;
  ecx = edi;  // @44_528260
  eax = ext_4dc110_thiscall1(ecx);  // @45_528260
  ecx = 0;  // @46_528260
  edx = (u32)(6949032);  // @47_528260
  ecx = eax;  // @48_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @49_528260
  ecx = edx = 0;  // @50_528260
  FL[2] = (eax & eax);  // @51_528260
  if (FL[2] != 0) goto L528325;  // @52_528260
  ecx = (u32)(esi + 4622);  // @53_528260
  goto L52839f;  // @54_528260
  L528325:;
  ecx = edi;  // @56_528260
  eax = ext_4dc110_thiscall1(ecx);  // @57_528260
  ecx = 0;  // @58_528260
  edx = (u32)(6949624);  // @59_528260
  ecx = eax;  // @60_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @61_528260
  ecx = edx = 0;  // @62_528260
  FL[2] = (eax & eax);  // @63_528260
  if (FL[2] != 0) goto L528344;  // @64_528260
  ecx = (u32)(esi + 5236);  // @65_528260
  goto L52839f;  // @66_528260
  L528344:;
  ecx = edi;  // @68_528260
  eax = ext_4dc110_thiscall1(ecx);  // @69_528260
  ecx = 0;  // @70_528260
  edx = (u32)(6949640);  // @71_528260
  ecx = eax;  // @72_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @73_528260
  ecx = edx = 0;  // @74_528260
  FL[2] = (eax & eax);  // @75_528260
  if (FL[2] != 0) goto L528363;  // @76_528260
  ecx = (u32)(esi + 4929);  // @77_528260
  goto L52839f;  // @78_528260
  L528363:;
  ecx = edi;  // @80_528260
  eax = ext_4dc110_thiscall1(ecx);  // @81_528260
  ecx = 0;  // @82_528260
  edx = (u32)(6949656);  // @83_528260
  ecx = eax;  // @84_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @85_528260
  ecx = edx = 0;  // @86_528260
  FL[2] = (eax & eax);  // @87_528260
  if (FL[2] != 0) goto L528382;  // @88_528260
  ecx = (u32)(esi + 5850);  // @89_528260
  goto L52839f;  // @90_528260
  L528382:;
  ecx = edi;  // @92_528260
  eax = ext_4dc110_thiscall1(ecx);  // @93_528260
  ecx = 0;  // @94_528260
  edx = (u32)(6949672);  // @95_528260
  ecx = eax;  // @96_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @97_528260
  ecx = edx = 0;  // @98_528260
  FL[2] = (eax & eax);  // @99_528260
  if (FL[2] != 0) goto L5283b9;  // @100_528260
  ecx = (u32)(esi + 5543);  // @101_528260
  L52839f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_528260
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @104_528260
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 137), sizeof v); (u32)v; });  // @105_528260
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[1], PV[0], (u32)(1));  // @106_528260
  ecx = edx = 0;  // @107_528260
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 141), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @108_528260
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 141), sizeof v); (u32)v; });  // @109_528260
  goto L528609;  // @110_528260
  L5283b9:;
  ecx = edi;  // @112_528260
  eax = ext_4dc110_thiscall1(ecx);  // @113_528260
  ecx = 0;  // @114_528260
  edx = (u32)(6949048);  // @115_528260
  ecx = eax;  // @116_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @117_528260
  ecx = edx = 0;  // @118_528260
  FL[2] = (eax & eax);  // @119_528260
  if (FL[2] != 0) goto L5283db;  // @120_528260
  ecx = (u32)(esi + 6157);  // @121_528260
  goto L5284b8;  // @122_528260
  L5283db:;
  ecx = edi;  // @124_528260
  eax = ext_4dc110_thiscall1(ecx);  // @125_528260
  ecx = 0;  // @126_528260
  edx = (u32)(6949064);  // @127_528260
  ecx = eax;  // @128_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @129_528260
  ecx = edx = 0;  // @130_528260
  FL[2] = (eax & eax);  // @131_528260
  if (FL[2] != 0) goto L5283fd;  // @132_528260
  ecx = (u32)(esi + 6464);  // @133_528260
  goto L5284b8;  // @134_528260
  L5283fd:;
  ecx = edi;  // @136_528260
  eax = ext_4dc110_thiscall1(ecx);  // @137_528260
  ecx = 0;  // @138_528260
  edx = (u32)(6949080);  // @139_528260
  ecx = eax;  // @140_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @141_528260
  ecx = edx = 0;  // @142_528260
  FL[2] = (eax & eax);  // @143_528260
  if (FL[2] != 0) goto L52841f;  // @144_528260
  ecx = (u32)(esi + 6771);  // @145_528260
  goto L5284b8;  // @146_528260
  L52841f:;
  ecx = edi;  // @148_528260
  eax = ext_4dc110_thiscall1(ecx);  // @149_528260
  ecx = 0;  // @150_528260
  edx = (u32)(6949096);  // @151_528260
  ecx = eax;  // @152_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @153_528260
  ecx = edx = 0;  // @154_528260
  FL[2] = (eax & eax);  // @155_528260
  if (FL[2] != 0) goto L52843e;  // @156_528260
  ecx = (u32)(esi + 7078);  // @157_528260
  goto L5284b8;  // @158_528260
  L52843e:;
  ecx = edi;  // @160_528260
  eax = ext_4dc110_thiscall1(ecx);  // @161_528260
  ecx = 0;  // @162_528260
  edx = (u32)(6949688);  // @163_528260
  ecx = eax;  // @164_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @165_528260
  ecx = edx = 0;  // @166_528260
  FL[2] = (eax & eax);  // @167_528260
  if (FL[2] != 0) goto L52845d;  // @168_528260
  ecx = (u32)(esi + 7385);  // @169_528260
  goto L5284b8;  // @170_528260
  L52845d:;
  ecx = edi;  // @172_528260
  eax = ext_4dc110_thiscall1(ecx);  // @173_528260
  ecx = 0;  // @174_528260
  edx = (u32)(6949704);  // @175_528260
  ecx = eax;  // @176_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @177_528260
  ecx = edx = 0;  // @178_528260
  FL[2] = (eax & eax);  // @179_528260
  if (FL[2] != 0) goto L52847c;  // @180_528260
  ecx = (u32)(esi + 7692);  // @181_528260
  goto L5284b8;  // @182_528260
  L52847c:;
  ecx = edi;  // @184_528260
  eax = ext_4dc110_thiscall1(ecx);  // @185_528260
  ecx = 0;  // @186_528260
  edx = (u32)(6949720);  // @187_528260
  ecx = eax;  // @188_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @189_528260
  ecx = edx = 0;  // @190_528260
  FL[2] = (eax & eax);  // @191_528260
  if (FL[2] != 0) goto L52849b;  // @192_528260
  ecx = (u32)(esi + 7999);  // @193_528260
  goto L5284b8;  // @194_528260
  L52849b:;
  ecx = edi;  // @196_528260
  eax = ext_4dc110_thiscall1(ecx);  // @197_528260
  ecx = 0;  // @198_528260
  edx = (u32)(6949736);  // @199_528260
  ecx = eax;  // @200_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @201_528260
  ecx = edx = 0;  // @202_528260
  FL[2] = (eax & eax);  // @203_528260
  if (FL[2] != 0) goto L5284d2;  // @204_528260
  ecx = (u32)(esi + 8306);  // @205_528260
  L5284b8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_528260
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @208_528260
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 137), sizeof v); (u32)v; });  // @209_528260
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[3], PV[2], (u32)(1));  // @210_528260
  ecx = edx = 0;  // @211_528260
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 145), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }  // @212_528260
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 145), sizeof v); (u32)v; });  // @213_528260
  goto L528609;  // @214_528260
  L5284d2:;
  ecx = edi;  // @216_528260
  eax = ext_4dc110_thiscall1(ecx);  // @217_528260
  ecx = 0;  // @218_528260
  edx = (u32)(6949752);  // @219_528260
  ecx = eax;  // @220_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @221_528260
  ecx = edx = 0;  // @222_528260
  FL[2] = (eax & eax);  // @223_528260
  if (FL[2] != 0) goto L5284f7;  // @224_528260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @225_528260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8613), &v, sizeof v); }  // @226_528260
  goto L528609;  // @227_528260
  L5284f7:;
  ecx = edi;  // @229_528260
  eax = ext_4dc110_thiscall1(ecx);  // @230_528260
  ecx = 0;  // @231_528260
  edx = (u32)(6949764);  // @232_528260
  ecx = eax;  // @233_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @234_528260
  ecx = edx = 0;  // @235_528260
  FL[2] = (eax & eax);  // @236_528260
  if (FL[2] != 0) goto L52851c;  // @237_528260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @238_528260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8617), &v, sizeof v); }  // @239_528260
  goto L528609;  // @240_528260
  L52851c:;
  ecx = edi;  // @242_528260
  eax = ext_4dc110_thiscall1(ecx);  // @243_528260
  ecx = 0;  // @244_528260
  edx = (u32)(6949112);  // @245_528260
  ecx = eax;  // @246_528260
  eax = ext_4cc850_fastcall2(ecx, edx);  // @247_528260
  ecx = edx = 0;  // @248_528260
  FL[2] = (eax & eax);  // @249_528260
  if (FL[2] != 0) goto L528609;  // @250_528260
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @251_528260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @252_528260
  ecx = (u32)(esi + 8654);  // @253_528260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @254_528260
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) * (s32)(u32)(121));  // @255_528260
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @256_528260
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @257_528260
  ecx = (ecx + eax);  // @258_528260
  FL[3] = ecx;  // @259_528260
  eax = ext_516b60_thiscall4(ecx, PV[5], (u32)(6949124), PV[4]);  // @260_528260
  ecx = edx = 0;  // @261_528260
  eax = (u32)(EBP - 16);  // @262_528260
  PV[6] = (u32)(eax);  // @263_528260
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) * (s32)(u32)(121));  // @264_528260
  ecx = (u32)(esi + 8654);  // @265_528260
  ecx = (ecx + eax);  // @266_528260
  FL[3] = ecx;  // @267_528260
  eax = ext_516f40_thiscall2(ecx, PV[6]);  // @268_528260
  ecx = edx = 0;  // @269_528260
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) * (s32)(u32)(121));  // @270_528260
  ecx = (u32)(esi + 8654);  // @271_528260
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(eax + esi + 8747), &v, sizeof v); }  // @272_528260
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) * (s32)(u32)(121));  // @273_528260
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(eax + esi + 8747), &v, sizeof v); }  // @274_528260
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) * (s32)(u32)(121));  // @275_528260
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(eax + esi + 8751), &v, sizeof v); }  // @276_528260
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) * (s32)(u32)(121));  // @277_528260
  { u32 v = (u32)((u32)(1063675494)); __builtin_memcpy((void *)(u32)(eax + esi + 8674), &v, sizeof v); }  // @278_528260
  eax = (u32)(EBP - 16);  // @279_528260
  PV[7] = (u32)(eax);  // @280_528260
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) * (s32)(u32)(121));  // @281_528260
  ecx = (ecx + eax);  // @282_528260
  FL[3] = ecx;  // @283_528260
  eax = ext_516f40_thiscall2(ecx, PV[7]);  // @284_528260
  ecx = edx = 0;  // @285_528260
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) * (s32)(u32)(121));  // @286_528260
  { u32 v = (u32)((u32)(1051900098)); __builtin_memcpy((void *)(u32)(eax + esi + 8735), &v, sizeof v); }  // @287_528260
  { u32 v = (u32)((u32)(1051900098)); __builtin_memcpy((void *)(u32)(eax + esi + 8739), &v, sizeof v); }  // @288_528260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + esi + 8743), &v, sizeof v); }  // @289_528260
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 8896), &v, sizeof v); }  // @290_528260
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8896), sizeof v); (u32)v; });  // @291_528260
  L528609:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @293_528260
  FL[2] = (edi & edi);  // @294_528260
  if (FL[2] != 0) goto L5282a0;  // @295_528260
  L528614:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 3729) + 0), 4); v; });  // @297_528260
  X0[1] = 0;  // @298_528260
  X0[2] = 0;  // @299_528260
  X0[3] = 0;  // @300_528260
  ecx = 0;  // @301_528260
  FL[3] = ecx;  // @302_528260
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4036) + 0), 4); v; })));  // @303_528260
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @304_528260
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @305_528260
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @306_528260
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @307_528260
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @308_528260
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @309_528260
  __builtin_memcpy((void *)((u32)(esi + 8633) + 0), &X0[0], 4);  // @310_528260
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 3737) + 0), 4); v; });  // @311_528260
  X0[1] = 0;  // @312_528260
  X0[2] = 0;  // @313_528260
  X0[3] = 0;  // @314_528260
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 6193) + 0), 4); v; })));  // @315_528260
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @316_528260
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @317_528260
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @318_528260
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @319_528260
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @320_528260
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X3[0] = F2U(a_); X3[1] = F2U(b_); X3[2] = X3[3] = 0; }  // @321_528260
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8633) + 0), 4); v; });  // @322_528260
  X0[1] = 0;  // @323_528260
  X0[2] = 0;  // @324_528260
  X0[3] = 0;  // @325_528260
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; })));  // @326_528260
  __builtin_memcpy((void *)((u32)(esi + 8637) + 0), &X3[0], 4);  // @327_528260
  X3[0] = F2U(U2F(X3[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; })));  // @328_528260
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(esi + 8645), &v, sizeof v); }  // @329_528260
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @330_528260
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @331_528260
  __builtin_memcpy((void *)((u32)(esi + 8641) + 0), &X0[0], 4);  // @332_528260
  __builtin_memcpy((void *)((u32)(esi + 8649) + 0), &X3[0], 4);  // @333_528260
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 141), sizeof v); (u32)v; }); FL[1] = ecx;  // @334_528260
  if ((s32)FL[0] <= (s32)FL[1]) goto L5286e3;  // @335_528260
  eax = (u32)(esi + 3782);  // @336_528260
  L5286b2:;
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 73), &v, sizeof v); }  // @338_528260
  eax = (u32)(eax + 307);  // @339_528260
  { u32 v = (u32)((u32)(1052938076)); __builtin_memcpy((void *)(u32)(eax - 307), &v, sizeof v); }  // @340_528260
  ecx = (ecx + 1);  // @341_528260
  FL[3] = ecx;  // @342_528260
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(eax - 113), &v, sizeof v); }  // @343_528260
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(eax - 186), &v, sizeof v); }  // @344_528260
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 141), sizeof v); (u32)v; });  // @345_528260
  if ((s32)FL[0] < (s32)FL[1]) goto L5286b2;  // @346_528260
  L5286e3:;
  ecx = 0;  // @348_528260
  FL[3] = ecx;  // @349_528260
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 145), sizeof v); (u32)v; }); FL[1] = ecx;  // @350_528260
  if ((s32)FL[0] <= (s32)FL[1]) goto L528724;  // @351_528260
  eax = (u32)(esi + 6238);  // @352_528260
  L5286f3:;
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 73), &v, sizeof v); }  // @354_528260
  eax = (u32)(eax + 307);  // @355_528260
  { u32 v = (u32)((u32)(1052938076)); __builtin_memcpy((void *)(u32)(eax - 307), &v, sizeof v); }  // @356_528260
  ecx = (ecx + 1);  // @357_528260
  FL[3] = ecx;  // @358_528260
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(eax - 113), &v, sizeof v); }  // @359_528260
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(eax - 186), &v, sizeof v); }  // @360_528260
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 145), sizeof v); (u32)v; });  // @361_528260
  if ((s32)FL[0] < (s32)FL[1]) goto L5286f3;  // @362_528260
  L528724:;
  ext_633654(G(u32, 0x6f5630));  // @364_528260
  return eax;  // @365_528260
}
PCREG(528260, lifted_528260);

extern "C" u32 THISCALL lifted_44ff60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_44ff60
  edi = ecx;  // @1_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 184), sizeof v); (u32)v; });  // @4_44ff60
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @5_44ff60
  ecx = edx = 0;  // @6_44ff60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @7_44ff60
  if (FL[2] != 0) goto L45096a;  // @8_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @9_44ff60
  ecx = (u32)((EBP - 296) + 108);  // @10_44ff60
  PV[0] = (u32)(ecx);  // @11_44ff60
  ecx = (u32)((EBP - 300) + 224);  // @12_44ff60
  PV[1] = (u32)(ecx);  // @13_44ff60
  ecx = edi;  // @14_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[1], PV[0]);  // @15_44ff60
  ecx = edx = 0;  // @16_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_44ff60
  ecx = (u32)((EBP - 296) + 48);  // @18_44ff60
  PV[2] = (u32)(ecx);  // @19_44ff60
  ecx = edi;  // @20_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 52), &v, sizeof v); }  // @21_44ff60
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)((EBP - 300) + 56), &v, sizeof v); }  // @22_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 60), &v, sizeof v); }  // @23_44ff60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[2]);  // @24_44ff60
  ecx = edx = 0;  // @25_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @26_44ff60
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @27_44ff60
  X2[1] = 0;  // @28_44ff60
  X2[2] = 0;  // @29_44ff60
  X2[3] = 0;  // @30_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_44ff60
  if (FL[0] != FL[1]) goto L4500a1;  // @32_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; });  // @33_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; });  // @34_44ff60
  X1[1] = 0;  // @35_44ff60
  X1[2] = 0;  // @36_44ff60
  X1[3] = 0;  // @37_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @38_44ff60
  X0[1] = 0;  // @39_44ff60
  X0[2] = 0;  // @40_44ff60
  X0[3] = 0;  // @41_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @42_44ff60
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @43_44ff60
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 68), sizeof v); (u32)v; });  // @44_44ff60
  if ((s32)FL[0] > (s32)FL[1]) goto L45007b;  // @45_44ff60
  esi = 0;  // @46_44ff60
  FL[3] = esi;  // @47_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; }); FL[1] = esi;  // @48_44ff60
  if (FL[0] <= FL[1]) goto L45005f;  // @49_44ff60
  ecx = 0;  // @50_44ff60
  FL[3] = ecx;  // @51_44ff60
  L450020:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @53_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax + 8), sizeof v); (u32)v; });  // @54_44ff60
  FL[2] = (ebx & ebx);  // @55_44ff60
  if (FL[2] == 0) goto L450056;  // @56_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax + 12) + 0), 4); v; });  // @57_44ff60
  X0[1] = 0;  // @58_44ff60
  X0[2] = 0;  // @59_44ff60
  X0[3] = 0;  // @60_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @61_44ff60
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @62_44ff60
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 68), sizeof v); (u32)v; });  // @63_44ff60
  if ((s32)FL[0] >= (s32)FL[1]) goto L450056;  // @64_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 124), &v, sizeof v); }  // @65_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @66_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax + 8), &v, sizeof v); }  // @67_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_44ff60
  L450056:;
  esi = (esi + 1);  // @70_44ff60
  FL[3] = esi;  // @71_44ff60
  ecx = (ecx + (u32)(16));  // @72_44ff60
  FL[3] = ecx;  // @73_44ff60
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @74_44ff60
  if (FL[0] < FL[1]) goto L450020;  // @75_44ff60
  L45005f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @77_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; });  // @78_44ff60
  X0[0] = F2U((float)(s32)X0[0]);  // @79_44ff60
  X0[1] = F2U((float)(s32)X0[1]);  // @80_44ff60
  X0[2] = F2U((float)(s32)X0[2]);  // @81_44ff60
  X0[3] = F2U((float)(s32)X0[3]);  // @82_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @83_44ff60
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @84_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_44ff60
  L45007b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @87_44ff60
  ecx = 0;  // @88_44ff60
  FL[3] = ecx;  // @89_44ff60
  FL[2] = (esi & esi);  // @90_44ff60
  if (FL[2] == 0) goto L4500a1;  // @91_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @92_44ff60
  eax = (u32)(ebx + 8);  // @93_44ff60
  L450090:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @95_44ff60
  if (FL[0] == FL[1]) goto L4502de;  // @96_44ff60
  ecx = (ecx + 1);  // @97_44ff60
  FL[3] = ecx;  // @98_44ff60
  eax = (eax + (u32)(16));  // @99_44ff60
  FL[3] = eax;  // @100_44ff60
  FL[0] = ecx; FL[1] = esi;  // @101_44ff60
  if (FL[0] < FL[1]) goto L450090;  // @102_44ff60
  L4500a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @104_44ff60
  FL[2] = (eax & eax);  // @105_44ff60
  if (FL[2] == 0) goto L45096a;  // @106_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @107_44ff60
  X1[0] = 0;  // @108_44ff60
  X1[1] = 0;  // @109_44ff60
  X1[2] = 0;  // @110_44ff60
  X1[3] = 0;  // @111_44ff60
  X0[0] = F2U((float)(s32)X0[0]);  // @112_44ff60
  X0[1] = F2U((float)(s32)X0[1]);  // @113_44ff60
  X0[2] = F2U((float)(s32)X0[2]);  // @114_44ff60
  X0[3] = F2U((float)(s32)X0[3]);  // @115_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @116_44ff60
  __builtin_memcpy((void *)((u32)(eax + 12) + 0), &X0[0], 4);  // @117_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @118_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @119_44ff60
  X0[1] = 0;  // @120_44ff60
  X0[2] = 0;  // @121_44ff60
  X0[3] = 0;  // @122_44ff60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @123_44ff60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @124_44ff60
  if (__builtin_parity(FL[2] & 0xff)) goto L450111;  // @125_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @126_44ff60
  X0[1] = 0;  // @127_44ff60
  X0[2] = 0;  // @128_44ff60
  X0[3] = 0;  // @129_44ff60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @130_44ff60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @131_44ff60
  if (__builtin_parity(FL[2] & 0xff)) goto L450111;  // @132_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @134_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @135_44ff60
  ecx = edx = 0;  // @136_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @137_44ff60
  PV[3] = (u32)(edx);  // @138_44ff60
  PV[4] = (u32)(eax);  // @139_44ff60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[4], PV[3], (u32)(6820668));  // @141_44ff60
  ecx = edx = 0;  // @142_44ff60
  L450111:;
  ecx = (u32)((EBP - 296) + 256);  // @144_44ff60
  eax = ext_4de7a0_thiscall1(ecx);  // @145_44ff60
    // @146_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @147_44ff60
  edx = (u32)((EBP - 296) + 220);  // @148_44ff60
  ecx = (u32)((EBP - 296) + 24);  // @149_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 0), 4); v; });  // @150_44ff60
  X0[1] = 0;  // @151_44ff60
  X0[2] = 0;  // @152_44ff60
  X0[3] = 0;  // @153_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 24) + 0), &X0[0], 4);  // @154_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 52) + 0), 4); v; });  // @155_44ff60
  X0[1] = 0;  // @156_44ff60
  X0[2] = 0;  // @157_44ff60
  X0[3] = 0;  // @158_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 28) + 0), &X0[0], 4);  // @159_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 56) + 0), 4); v; });  // @160_44ff60
  X0[1] = 0;  // @161_44ff60
  X0[2] = 0;  // @162_44ff60
  X0[3] = 0;  // @163_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 32) + 0), &X0[0], 4);  // @164_44ff60
  eax = ext_4419f0_fastcall2(ecx, edx);  // @165_44ff60
  ecx = edx = 0;  // @166_44ff60
  edx = (u32)((EBP - 296) + 108);  // @167_44ff60
  ecx = (u32)((EBP - 296) + 24);  // @168_44ff60
  eax = ext_441940_fastcall2(ecx, edx);  // @169_44ff60
  ecx = edx = 0;  // @170_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @171_44ff60
  esi = (u32)(edi + 180);  // @172_44ff60
  X1[0] = 0;  // @173_44ff60
  X1[1] = 0;  // @174_44ff60
  X1[2] = 0;  // @175_44ff60
  X1[3] = 0;  // @176_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 76) + 0), 4); v; });  // @177_44ff60
  X0[1] = 0;  // @178_44ff60
  X0[2] = 0;  // @179_44ff60
  X0[3] = 0;  // @180_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 84) + 0), &X0[0], 4);  // @181_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 88) + 0), &X0[0], 4);  // @182_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 92) + 0), &X0[0], 4);  // @183_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @184_44ff60
  X0[1] = 0;  // @185_44ff60
  X0[2] = 0;  // @186_44ff60
  X0[3] = 0;  // @187_44ff60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @188_44ff60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @189_44ff60
  if (!__builtin_parity(FL[2] & 0xff)) goto L4501d0;  // @190_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 184) + 0), 4); v; });  // @191_44ff60
  X0[1] = 0;  // @192_44ff60
  X0[2] = 0;  // @193_44ff60
  X0[3] = 0;  // @194_44ff60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @195_44ff60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @196_44ff60
  if (!__builtin_parity(FL[2] & 0xff)) goto L4501d0;  // @197_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 188) + 0), 4); v; });  // @198_44ff60
  X0[1] = 0;  // @199_44ff60
  X0[2] = 0;  // @200_44ff60
  X0[3] = 0;  // @201_44ff60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @202_44ff60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @203_44ff60
  if (!__builtin_parity(FL[2] & 0xff)) goto L4501d0;  // @204_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 24) + 0), 4); v; });  // @205_44ff60
  X0[1] = 0;  // @206_44ff60
  X0[2] = 0;  // @207_44ff60
  X0[3] = 0;  // @208_44ff60
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @209_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 28) + 0), 4); v; });  // @210_44ff60
  X0[1] = 0;  // @211_44ff60
  X0[2] = 0;  // @212_44ff60
  X0[3] = 0;  // @213_44ff60
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @214_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 32) + 0), 4); v; });  // @215_44ff60
  X0[1] = 0;  // @216_44ff60
  X0[2] = 0;  // @217_44ff60
  X0[3] = 0;  // @218_44ff60
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @219_44ff60
  L4501d0:;
  PV[5] = (u32)(esi);  // @221_44ff60
  edx = (u32)((EBP - 300) + 28);  // @222_44ff60
  ecx = (u32)((EBP - 300) + 40);  // @223_44ff60
  eax = ext_43e920_fastcall3(ecx, edx, PV[5]);  // @224_44ff60
  ecx = edx = 0;  // @225_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 24) + 0), 4); v; });  // @226_44ff60
  X0[1] = 0;  // @227_44ff60
  X0[2] = 0;  // @228_44ff60
  X0[3] = 0;  // @229_44ff60
  edx = (u32)((EBP - 296) + 220);  // @230_44ff60
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @231_44ff60
  ecx = (u32)((EBP - 296) + 36);  // @232_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 28) + 0), 4); v; });  // @233_44ff60
  X0[1] = 0;  // @234_44ff60
  X0[2] = 0;  // @235_44ff60
  X0[3] = 0;  // @236_44ff60
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @237_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 32) + 0), 4); v; });  // @238_44ff60
  X0[1] = 0;  // @239_44ff60
  X0[2] = 0;  // @240_44ff60
  X0[3] = 0;  // @241_44ff60
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @242_44ff60
  eax = ext_441a60_fastcall2(ecx, edx);  // @243_44ff60
  ecx = edx = 0;  // @244_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 40) + 0), 4); v; });  // @245_44ff60
  X0[1] = 0;  // @246_44ff60
  X0[2] = 0;  // @247_44ff60
  X0[3] = 0;  // @248_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 36) + 0), 4); v; });  // @249_44ff60
  X1[1] = 0;  // @250_44ff60
  X1[2] = 0;  // @251_44ff60
  X1[3] = 0;  // @252_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @253_44ff60
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @254_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @255_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 44) + 0), 4); v; });  // @256_44ff60
  X0[1] = 0;  // @257_44ff60
  X0[2] = 0;  // @258_44ff60
  X0[3] = 0;  // @259_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @260_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @261_44ff60
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; }))))))) goto L450339;  // @262_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @263_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @264_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 296) + 36), &v, sizeof v); }  // @265_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 296) + 40), &v, sizeof v); }  // @266_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 296) + 44), &v, sizeof v); }  // @267_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @268_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 296) + 12), &v, sizeof v); }  // @269_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 296) + 20), &v, sizeof v); }  // @270_44ff60
  if (FL[0] <= FL[1]) goto L450373;  // @271_44ff60
  ecx = (u32)(4294967288);  // @272_44ff60
  ebx = (u32)(eax + 8);  // @273_44ff60
  ecx = (ecx - eax);  // @274_44ff60
  FL[3] = ecx;  // @275_44ff60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 296) + 16), &v, sizeof v); }  // @276_44ff60
  L450282:;
  edx = (u32)(ecx + ebx);  // @278_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @279_44ff60
  ebx = (u32)(ebx + 12);  // @280_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @281_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx - 20), &v, sizeof v); }  // @282_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx + 4), sizeof v); (u32)v; });  // @283_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx - 16), &v, sizeof v); }  // @284_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx + 8), sizeof v); (u32)v; });  // @285_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx - 12), &v, sizeof v); }  // @286_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @287_44ff60
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 20), sizeof v); (u32)v; }));  // @288_44ff60
  FL[3] = eax;  // @289_44ff60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @290_44ff60
  esi = (esi + edx);  // @291_44ff60
  FL[3] = esi;  // @292_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 12), sizeof v); (u32)v; });  // @293_44ff60
  ecx = (u32)(eax + eax*2);  // @294_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @295_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4), &v, sizeof v); }  // @296_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @297_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4 + 4), &v, sizeof v); }  // @298_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @299_44ff60
  esi = edx;  // @300_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 20), sizeof v); (u32)v; });  // @301_44ff60
  edx = (edx + 1);  // @302_44ff60
  FL[3] = edx;  // @303_44ff60
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 296) + 20), &v, sizeof v); }  // @304_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx*4 + 8), &v, sizeof v); }  // @305_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 16), sizeof v); (u32)v; });  // @306_44ff60
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @307_44ff60
  if (FL[0] < FL[1]) goto L450282;  // @308_44ff60
  goto L450373;  // @309_44ff60
  L4502de:;
  eax = ecx;  // @311_44ff60
  eax = (eax << (u32)(4));  // @312_44ff60
  FL[3] = eax;  // @313_44ff60
  eax = (eax + ebx);  // @314_44ff60
  FL[3] = eax;  // @315_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 124), &v, sizeof v); }  // @316_44ff60
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @317_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @318_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @319_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @320_44ff60
  X0[0] = F2U((float)(s32)X0[0]);  // @321_44ff60
  X0[1] = F2U((float)(s32)X0[1]);  // @322_44ff60
  X0[2] = F2U((float)(s32)X0[2]);  // @323_44ff60
  X0[3] = F2U((float)(s32)X0[3]);  // @324_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @325_44ff60
  __builtin_memcpy((void *)((u32)(eax + 12) + 0), &X0[0], 4);  // @326_44ff60
  eax = (u32)((EBP - 296) + 48);  // @327_44ff60
  PV[6] = (u32)(eax);  // @328_44ff60
  PV[7] = (u32)(ecx);  // @329_44ff60
  ecx = edi;  // @330_44ff60
  eax = ext_450fc0_thiscall3(ecx, PV[7], PV[6]);  // @331_44ff60
  ecx = edx = 0;  // @332_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @333_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @334_44ff60
  eax = (eax & (u32)(4278190079));  // @335_44ff60
  FL[3] = eax;  // @336_44ff60
  eax = (eax | (u32)(16777216));  // @337_44ff60
  FL[3] = eax;  // @338_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 60), &v, sizeof v); }  // @339_44ff60
  ext_633654(G(u32, 0x6f5630));  // @340_44ff60
  return eax;  // @341_44ff60
  L450339:;
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820732) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820732) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820732) + 0), 4); v; }))))))) goto L450362;  // @343_44ff60
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @344_44ff60
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @345_44ff60
  ecx = edx = 0;  // @346_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 0), 4); v; }); X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 4), 4); v; }); X1[2] = X1[3] = 0;  // @347_44ff60
  SD(&X1[0], U2D(X1[0], X1[1]) / U2D(X0[0], X0[1]));  // @348_44ff60
  PV[8] = (u32)(ecx);  // @349_44ff60
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @350_44ff60
  PV[9] = X0[0];  // @351_44ff60
  goto L45036a;  // @352_44ff60
  L450362:;
  PV[10] = (u32)(ecx);  // @354_44ff60
  L45036a:;
  ecx = (u32)((EBP - 304) + 40);  // @356_44ff60
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1032358025));  // @357_44ff60
    // @358_44ff60
  L450373:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @360_44ff60
  if (FL[0] != FL[1]) goto L45038d;  // @361_44ff60
  PV[11] = (u32)(ecx);  // @362_44ff60
  ecx = (u32)(edi + 40);  // @363_44ff60
  edx = (u32)((EBP - 304) + 40);  // @364_44ff60
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1040187392));  // @365_44ff60
    // @366_44ff60
  L45038d:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 208), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @368_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @369_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820728) + 0), 4); v; });  // @370_44ff60
  X1[1] = 0;  // @371_44ff60
  X1[2] = 0;  // @372_44ff60
  X1[3] = 0;  // @373_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @374_44ff60
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 300) + 20), &v, sizeof v); }  // @375_44ff60
  if (FL[0] == FL[1]) goto L4503c3;  // @376_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @377_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @378_44ff60
  X0[1] = 0;  // @379_44ff60
  X0[2] = 0;  // @380_44ff60
  X0[3] = 0;  // @381_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 204) + 0), 4); v; })));  // @382_44ff60
  __builtin_memcpy((void *)((u32)(edi + 204) + 0), &X0[0], 4);  // @383_44ff60
  goto L4503cd;  // @384_44ff60
  L4503c3:;
  { u32 v = (u32)((u32)(1015580809)); __builtin_memcpy((void *)(u32)(edi + 204), &v, sizeof v); }  // @386_44ff60
  L4503cd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 204) + 0), 4); v; });  // @388_44ff60
  X0[1] = 0;  // @389_44ff60
  X0[2] = 0;  // @390_44ff60
  X0[3] = 0;  // @391_44ff60
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L45083c;  // @392_44ff60
  L4503e0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @394_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 204) + 0), 4); v; });  // @395_44ff60
  X0[1] = 0;  // @396_44ff60
  X0[2] = 0;  // @397_44ff60
  X0[3] = 0;  // @398_44ff60
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @399_44ff60
  PV[12] = (u32)(ecx);  // @400_44ff60
  ecx = edi;  // @401_44ff60
  __builtin_memcpy((void *)((u32)(edi + 204) + 0), &X0[0], 4);  // @402_44ff60
  if (FL[0] == FL[1]) goto L45040b;  // @403_44ff60
  eax = (u32)((EBP - 304) + 40);  // @404_44ff60
  PV[13] = (u32)(eax);  // @405_44ff60
  goto L45040d;  // @406_44ff60
  L45040b:;
  L45040d:;
  eax = (u32)((EBP - 312) + 56);  // @409_44ff60
  PV[14] = (u32)(eax);  // @410_44ff60
  PV[15] = (u32)(ebx);  // @411_44ff60
  eax = ext_44ef80_thiscall5(ecx, PV[15], PV[14], (u32)(0), PV[13]);  // @412_44ff60
  ecx = edx = 0;  // @413_44ff60
  PV[16] = (u32)(ecx);  // @414_44ff60
  ecx = edi;  // @415_44ff60
  PV[17] = (u32)(ebx);  // @416_44ff60
  eax = ext_44f0f0_thiscall3(ecx, PV[17], (u32)(1023969417));  // @417_44ff60
  ecx = edx = 0;  // @418_44ff60
  eax = 0;  // @419_44ff60
  FL[3] = eax;  // @420_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 304) + 12), &v, sizeof v); }  // @421_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }); FL[1] = eax;  // @422_44ff60
  if (FL[0] <= FL[1]) goto L450591;  // @423_44ff60
  L450437:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @425_44ff60
  esi = 0;  // @426_44ff60
  FL[3] = esi;  // @427_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = esi;  // @428_44ff60
  if (FL[0] <= FL[1]) goto L450542;  // @429_44ff60
  L450445:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @431_44ff60
  esi = (esi + 1);  // @432_44ff60
  FL[3] = esi;  // @433_44ff60
  ecx = (u32)(eax + eax*2);  // @434_44ff60
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @435_44ff60
  eax = (u32)(eax + eax*2);  // @436_44ff60
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4) + 0), 4); v; });  // @437_44ff60
  X2[1] = 0;  // @438_44ff60
  X2[2] = 0;  // @439_44ff60
  X2[3] = 0;  // @440_44ff60
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx*4) + 0), 4); v; })));  // @441_44ff60
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4 + 4) + 0), 4); v; });  // @442_44ff60
  X7[1] = 0;  // @443_44ff60
  X7[2] = 0;  // @444_44ff60
  X7[3] = 0;  // @445_44ff60
  X7[0] = F2U(U2F(X7[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx*4 + 4) + 0), 4); v; })));  // @446_44ff60
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4 + 8) + 0), 4); v; });  // @447_44ff60
  X6[1] = 0;  // @448_44ff60
  X6[2] = 0;  // @449_44ff60
  X6[3] = 0;  // @450_44ff60
  X6[0] = F2U(U2F(X6[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx*4 + 8) + 0), 4); v; })));  // @451_44ff60
  X0[0] = X2[0];  // @452_44ff60
  X0[1] = X2[1];  // @453_44ff60
  X0[2] = X2[2];  // @454_44ff60
  X0[3] = X2[3];  // @455_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 304) + 16) + 0), &X2[0], 4);  // @456_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @457_44ff60
  X1[0] = X7[0];  // @458_44ff60
  X1[1] = X7[1];  // @459_44ff60
  X1[2] = X7[2];  // @460_44ff60
  X1[3] = X7[3];  // @461_44ff60
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 4) + 0), 4); v; });  // @462_44ff60
  X2[1] = 0;  // @463_44ff60
  X2[2] = 0;  // @464_44ff60
  X2[3] = 0;  // @465_44ff60
  X1[0] = F2U(U2F(X1[0]) * U2F(X7[0]));  // @466_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @467_44ff60
  X0[0] = X6[0];  // @468_44ff60
  X0[1] = X6[1];  // @469_44ff60
  X0[2] = X6[2];  // @470_44ff60
  X0[3] = X6[3];  // @471_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X6[0]));  // @472_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @473_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 12) + 0), 4); v; });  // @474_44ff60
  X0[1] = 0;  // @475_44ff60
  X0[2] = 0;  // @476_44ff60
  X0[3] = 0;  // @477_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 8) + 0), 4); v; })));  // @478_44ff60
  edx = (edx + (u32)(16));  // @479_44ff60
  FL[3] = edx;  // @480_44ff60
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @481_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @482_44ff60
  X1[1] = 0;  // @483_44ff60
  X1[2] = 0;  // @484_44ff60
  X1[3] = 0;  // @485_44ff60
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @486_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 16) + 0), 4); v; });  // @487_44ff60
  X0[1] = 0;  // @488_44ff60
  X0[2] = 0;  // @489_44ff60
  X0[3] = 0;  // @490_44ff60
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 52) + 0), 4); v; })));  // @491_44ff60
  X2[0] = F2U(U2F(X2[0]) * U2F(X1[0]));  // @492_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @493_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx*4) + 0), 4); v; })));  // @494_44ff60
  __builtin_memcpy((void *)((u32)(ebx + ecx*4) + 0), &X0[0], 4);  // @495_44ff60
  X0[0] = X7[0];  // @496_44ff60
  X0[1] = X7[1];  // @497_44ff60
  X0[2] = X7[2];  // @498_44ff60
  X0[3] = X7[3];  // @499_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @500_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx*4 + 4) + 0), 4); v; })));  // @501_44ff60
  __builtin_memcpy((void *)((u32)(ebx + ecx*4 + 4) + 0), &X0[0], 4);  // @502_44ff60
  X0[0] = X6[0];  // @503_44ff60
  X0[1] = X6[1];  // @504_44ff60
  X0[2] = X6[2];  // @505_44ff60
  X0[3] = X6[3];  // @506_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @507_44ff60
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @508_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx*4 + 8) + 0), 4); v; })));  // @509_44ff60
  X7[0] = F2U(U2F(X7[0]) * U2F(X2[0]));  // @510_44ff60
  X6[0] = F2U(U2F(X6[0]) * U2F(X2[0]));  // @511_44ff60
  __builtin_memcpy((void *)((u32)(ebx + ecx*4 + 8) + 0), &X0[0], 4);  // @512_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 16) + 0), 4); v; });  // @513_44ff60
  X0[1] = 0;  // @514_44ff60
  X0[2] = 0;  // @515_44ff60
  X0[3] = 0;  // @516_44ff60
  X7[0] = F2U(U2F(X7[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4 + 4) + 0), 4); v; })));  // @517_44ff60
  X6[0] = F2U(U2F(X6[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4 + 8) + 0), 4); v; })));  // @518_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @519_44ff60
  __builtin_memcpy((void *)((u32)(ebx + eax*4 + 4) + 0), &X7[0], 4);  // @520_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4) + 0), 4); v; })));  // @521_44ff60
  __builtin_memcpy((void *)((u32)(ebx + eax*4 + 8) + 0), &X6[0], 4);  // @522_44ff60
  __builtin_memcpy((void *)((u32)(ebx + eax*4) + 0), &X0[0], 4);  // @523_44ff60
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @524_44ff60
  if (FL[0] < FL[1]) goto L450445;  // @525_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 12), sizeof v); (u32)v; });  // @526_44ff60
  L450542:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @528_44ff60
  esi = 0;  // @529_44ff60
  FL[3] = esi;  // @530_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; });  // @531_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }); FL[1] = esi;  // @532_44ff60
  if (FL[0] <= FL[1]) goto L45057f;  // @533_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 20), sizeof v); (u32)v; });  // @534_44ff60
  ecx = (ecx + (u32)(8));  // @535_44ff60
  FL[3] = ecx;  // @536_44ff60
  L450556:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @538_44ff60
  ebx = (u32)(ebx + 4);  // @539_44ff60
  FL[2] = (eax & eax);  // @540_44ff60
  if (FL[2] != 0) goto L45056f;  // @541_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @542_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 8), &v, sizeof v); }  // @543_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @544_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @545_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @546_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @547_44ff60
  L45056f:;
  esi = (esi + 1);  // @549_44ff60
  FL[3] = esi;  // @550_44ff60
  ecx = (ecx + (u32)(12));  // @551_44ff60
  FL[3] = ecx;  // @552_44ff60
  edx = (edx + (u32)(12));  // @553_44ff60
  FL[3] = edx;  // @554_44ff60
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @555_44ff60
  if (FL[0] < FL[1]) goto L450556;  // @556_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 12), sizeof v); (u32)v; });  // @557_44ff60
  L45057f:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 20), sizeof v); (u32)v; });  // @559_44ff60
  eax = (eax + 1);  // @560_44ff60
  FL[3] = eax;  // @561_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 304) + 12), &v, sizeof v); }  // @562_44ff60
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @563_44ff60
  if (FL[0] < FL[1]) goto L450437;  // @564_44ff60
  L450591:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @566_44ff60
  eax = (eax - (u32)(1));  // @567_44ff60
  FL[3] = eax;  // @568_44ff60
  if (FL[3] == 0) goto L45070a;  // @569_44ff60
  eax = (eax - (u32)(1));  // @570_44ff60
  FL[3] = eax;  // @571_44ff60
  if (FL[3] != 0) goto L4507e5;  // @572_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @573_44ff60
  edx = (u32)((EBP - 304) + 84);  // @574_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @575_44ff60
  PV[18] = (u32)(edx);  // @576_44ff60
  edx = (u32)((EBP - 324) + 44);  // @577_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @578_44ff60
  PV[19] = (u32)(edx);  // @579_44ff60
  edx = (u32)((EBP - 328) + 280);  // @580_44ff60
  PV[20] = (u32)(edx);  // @581_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @582_44ff60
  edx = (u32)((EBP - 332) + 164);  // @583_44ff60
  PV[21] = (u32)(edx);  // @584_44ff60
  edx = (u32)((EBP - 340) + 156);  // @585_44ff60
  PV[22] = (u32)(edx);  // @586_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 56)))(ecx, PV[22], PV[21], (u32)(0), PV[20], PV[19], PV[18], (u32)(2), (u32)(0), (u32)(1), (u32)(1), (u32)(1023969417), PV[9]);  // @587_44ff60
  ecx = edx = 0;  // @588_44ff60
  esi = 0;  // @589_44ff60
  FL[3] = esi;  // @590_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 296) + 16), &v, sizeof v); }  // @591_44ff60
  FL[2] = (eax & eax);  // @592_44ff60
  if (FL[2] == 0) goto L4507e5;  // @593_44ff60
  ebx = eax;  // @594_44ff60
  L450600:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + esi*4 + 120), sizeof v); (u32)v; });  // @596_44ff60
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2097154));  // @597_44ff60
  ecx = 0;  // @598_44ff60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @599_44ff60
  if (FL[2] == 0) goto L4506f8;  // @600_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + esi*4 + 120), sizeof v); (u32)v; });  // @601_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @602_44ff60
  FL[2] = (ecx & ecx);  // @603_44ff60
  if (FL[2] == 0) goto L4506f8;  // @604_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @605_44ff60
  edx = (u32)((EBP - 296) + 60);  // @606_44ff60
  PV[23] = (u32)(edx);  // @607_44ff60
  edx = (u32)((EBP - 300) + 140);  // @608_44ff60
  PV[24] = (u32)(edx);  // @609_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[24], PV[23]);  // @610_44ff60
  ecx = edx = 0;  // @611_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @612_44ff60
  ecx = (u32)((EBP - 296) + 172);  // @613_44ff60
  PV[25] = (u32)(ecx);  // @614_44ff60
  ecx = (u32)((EBP - 300) + 188);  // @615_44ff60
  PV[26] = (u32)(ecx);  // @616_44ff60
  ecx = edi;  // @617_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[26], PV[25]);  // @618_44ff60
  ecx = edx = 0;  // @619_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @620_44ff60
  edx = (u32)((EBP - 296) + 172);  // @621_44ff60
  ecx = (u32)((EBP - 296) + 60);  // @622_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 76) + 0), 4); v; });  // @623_44ff60
  X0[1] = 0;  // @624_44ff60
  X0[2] = 0;  // @625_44ff60
  X0[3] = 0;  // @626_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @627_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 16) + 0), &X0[0], 4);  // @628_44ff60
  eax = ext_43e960_fastcall2(ecx, edx);  // @629_44ff60
  ecx = edx = 0;  // @630_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 60) + 0), 4); v; });  // @631_44ff60
  X1[1] = 0;  // @632_44ff60
  X1[2] = 0;  // @633_44ff60
  X1[3] = 0;  // @634_44ff60
  X0[0] = 0;  // @635_44ff60
  X0[1] = 0;  // @636_44ff60
  X0[2] = 0;  // @637_44ff60
  X0[3] = 0;  // @638_44ff60
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @639_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @640_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 68) + 0), 4); v; });  // @641_44ff60
  X0[1] = 0;  // @642_44ff60
  X0[2] = 0;  // @643_44ff60
  X0[3] = 0;  // @644_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @645_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @646_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 16) + 0), 4); v; });  // @647_44ff60
  X0[1] = 0;  // @648_44ff60
  X0[2] = 0;  // @649_44ff60
  X0[3] = 0;  // @650_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @651_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 12) + 0), &X1[0], 4);  // @652_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 12), sizeof v); (u32)v; });  // @653_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 16) + 0), &X0[0], 4);  // @654_44ff60
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 16), sizeof v); (u32)v; });  // @655_44ff60
  if ((s32)FL[0] > (s32)FL[1]) goto L4506f8;  // @656_44ff60
  edx = (u32)((EBP - 296) + 184);  // @657_44ff60
  ecx = (u32)((EBP - 296) + 60);  // @658_44ff60
  eax = ext_441a60_fastcall2(ecx, edx);  // @659_44ff60
  ecx = edx = 0;  // @660_44ff60
  edx = (u32)((EBP - 296) + 184);  // @661_44ff60
  ecx = (u32)((EBP - 296) + 136);  // @662_44ff60
  eax = ext_4de4f0_fastcall2(ecx, edx);  // @663_44ff60
  ecx = edx = 0;  // @664_44ff60
  PV[27] = (u32)(ecx);  // @665_44ff60
  eax = (u32)((EBP - 300) + 64);  // @666_44ff60
  PV[28] = (u32)(eax);  // @667_44ff60
  eax = (u32)((EBP - 304) + 144);  // @668_44ff60
  ecx = edi;  // @669_44ff60
  PV[29] = (u32)(eax);  // @670_44ff60
  eax = ext_44f8b0_thiscall4(ecx, PV[29], PV[28], (u32)(1106247680));  // @671_44ff60
  ecx = edx = 0;  // @672_44ff60
  L4506f8:;
  esi = (esi + 1);  // @674_44ff60
  FL[3] = esi;  // @675_44ff60
  FL[0] = esi; FL[1] = ebx;  // @676_44ff60
  if (FL[0] < FL[1]) goto L450600;  // @677_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 20), sizeof v); (u32)v; });  // @678_44ff60
  goto L4507e5;  // @679_44ff60
  L45070a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; });  // @681_44ff60
  FL[2] = (ecx & ecx);  // @682_44ff60
  if (FL[2] == 0) goto L4507e5;  // @683_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @684_44ff60
  edx = (u32)((EBP - 296) + 72);  // @685_44ff60
  PV[30] = (u32)(edx);  // @686_44ff60
  edx = (u32)((EBP - 300) + 188);  // @687_44ff60
  PV[31] = (u32)(edx);  // @688_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[31], PV[30]);  // @689_44ff60
  ecx = edx = 0;  // @690_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @691_44ff60
  ecx = (u32)((EBP - 296) + 96);  // @692_44ff60
  PV[32] = (u32)(ecx);  // @693_44ff60
  ecx = (u32)((EBP - 300) + 140);  // @694_44ff60
  PV[33] = (u32)(ecx);  // @695_44ff60
  ecx = edi;  // @696_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[33], PV[32]);  // @697_44ff60
  ecx = edx = 0;  // @698_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @699_44ff60
  edx = (u32)((EBP - 296) + 96);  // @700_44ff60
  ecx = (u32)((EBP - 296) + 72);  // @701_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 76) + 0), 4); v; });  // @702_44ff60
  X0[1] = 0;  // @703_44ff60
  X0[2] = 0;  // @704_44ff60
  X0[3] = 0;  // @705_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @706_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 16) + 0), &X0[0], 4);  // @707_44ff60
  eax = ext_43e960_fastcall2(ecx, edx);  // @708_44ff60
  ecx = edx = 0;  // @709_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 72) + 0), 4); v; });  // @710_44ff60
  X1[1] = 0;  // @711_44ff60
  X1[2] = 0;  // @712_44ff60
  X1[3] = 0;  // @713_44ff60
  X0[0] = 0;  // @714_44ff60
  X0[1] = 0;  // @715_44ff60
  X0[2] = 0;  // @716_44ff60
  X0[3] = 0;  // @717_44ff60
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @718_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @719_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 80) + 0), 4); v; });  // @720_44ff60
  X0[1] = 0;  // @721_44ff60
  X0[2] = 0;  // @722_44ff60
  X0[3] = 0;  // @723_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @724_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @725_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 16) + 0), 4); v; });  // @726_44ff60
  X0[1] = 0;  // @727_44ff60
  X0[2] = 0;  // @728_44ff60
  X0[3] = 0;  // @729_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @730_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 12) + 0), &X1[0], 4);  // @731_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 12), sizeof v); (u32)v; });  // @732_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 296) + 16) + 0), &X0[0], 4);  // @733_44ff60
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 16), sizeof v); (u32)v; });  // @734_44ff60
  if ((s32)FL[0] > (s32)FL[1]) goto L4507e5;  // @735_44ff60
  edx = (u32)((EBP - 296) + 136);  // @736_44ff60
  ecx = (u32)((EBP - 296) + 72);  // @737_44ff60
  eax = ext_441a60_fastcall2(ecx, edx);  // @738_44ff60
  ecx = edx = 0;  // @739_44ff60
  edx = (u32)((EBP - 296) + 136);  // @740_44ff60
  ecx = (u32)((EBP - 296) + 184);  // @741_44ff60
  eax = ext_4de4f0_fastcall2(ecx, edx);  // @742_44ff60
  ecx = edx = 0;  // @743_44ff60
  PV[34] = (u32)(ecx);  // @744_44ff60
  eax = (u32)((EBP - 300) + 76);  // @745_44ff60
  PV[35] = (u32)(eax);  // @746_44ff60
  eax = (u32)((EBP - 304) + 192);  // @747_44ff60
  ecx = edi;  // @748_44ff60
  PV[36] = (u32)(eax);  // @749_44ff60
  eax = ext_44f8b0_thiscall4(ecx, PV[36], PV[35], (u32)(1106247680));  // @750_44ff60
  ecx = edx = 0;  // @751_44ff60
  L4507e5:;
  ecx = edi;  // @753_44ff60
  eax = ext_44f550_fastcall2(ecx, edx);  // @754_44ff60
  ecx = edx = 0;  // @755_44ff60
  esi = 0;  // @756_44ff60
  FL[3] = esi;  // @757_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }); FL[1] = esi;  // @758_44ff60
  if (FL[0] <= FL[1]) goto L450823;  // @759_44ff60
  L4507f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @761_44ff60
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*2), sizeof v); (u32)v; });  // @762_44ff60
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*2 + 2), sizeof v); (u32)v; });  // @763_44ff60
  esi = (esi + (u32)(2));  // @764_44ff60
  FL[3] = esi;  // @765_44ff60
  edx = (u32)(ecx + ecx*2);  // @766_44ff60
  ecx = (u32)(eax + eax*2);  // @767_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx*4), sizeof v); (u32)v; });  // @768_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + ecx*4), &v, sizeof v); }  // @769_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx*4 + 4), sizeof v); (u32)v; });  // @770_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + ecx*4 + 4), &v, sizeof v); }  // @771_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx*4 + 8), sizeof v); (u32)v; });  // @772_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + ecx*4 + 8), &v, sizeof v); }  // @773_44ff60
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @774_44ff60
  if (FL[0] < FL[1]) goto L4507f3;  // @775_44ff60
  L450823:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 204) + 0), 4); v; });  // @777_44ff60
  X0[1] = 0;  // @778_44ff60
  X0[2] = 0;  // @779_44ff60
  X0[3] = 0;  // @780_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820728) + 0), 4); v; });  // @781_44ff60
  X1[1] = 0;  // @782_44ff60
  X1[2] = 0;  // @783_44ff60
  X1[3] = 0;  // @784_44ff60
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))))) goto L4503e0;  // @785_44ff60
  L45083c:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @787_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @788_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @789_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 296) + 12), &v, sizeof v); }  // @790_44ff60
  if (FL[0] <= FL[1]) goto L4508a3;  // @791_44ff60
  ebx = 0;  // @792_44ff60
  FL[3] = ebx;  // @793_44ff60
  L450850:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @795_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; });  // @796_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @797_44ff60
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx*8 + 4), sizeof v); (u32)v; });  // @798_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx*8), sizeof v); (u32)v; });  // @799_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @800_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @801_44ff60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @802_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @803_44ff60
  eax = (u32)(eax + edx*4);  // @804_44ff60
  PV[38] = (u32)(eax);  // @805_44ff60
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 308) + 24), sizeof v); (u32)v; });  // @806_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 112)))(ecx, PV[39], (u32)(1), PV[38], PV[37]);  // @807_44ff60
  ecx = edx = 0;  // @808_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @809_44ff60
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 300) + 16), sizeof v); (u32)v; });  // @810_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @811_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @812_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @813_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[40], (u32)(1));  // @814_44ff60
  ecx = edx = 0;  // @815_44ff60
  ebx = (ebx + 1);  // @816_44ff60
  FL[3] = ebx;  // @817_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 296) + 12), &v, sizeof v); }  // @818_44ff60
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @819_44ff60
  if (FL[0] < FL[1]) goto L450850;  // @820_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 20), sizeof v); (u32)v; });  // @821_44ff60
  L4508a3:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 144), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @823_44ff60
  if (FL[0] == FL[1]) goto L450903;  // @824_44ff60
  esi = 0;  // @825_44ff60
  FL[3] = esi;  // @826_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 136), sizeof v); (u32)v; }); FL[1] = esi;  // @827_44ff60
  if (FL[0] <= FL[1]) goto L450903;  // @828_44ff60
  L4508c0:;
  eax = (u32)((EBP - 296) + 220);  // @830_44ff60
  PV[41] = (u32)(eax);  // @831_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @832_44ff60
  ecx = (u32)((EBP - 300) + 100);  // @833_44ff60
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*2), sizeof v); (u32)v; });  // @834_44ff60
  eax = (u32)(eax + eax*2);  // @835_44ff60
  edx = (u32)(ebx + eax*4);  // @836_44ff60
  eax = ext_441970_fastcall3(ecx, edx, PV[41]);  // @837_44ff60
  ecx = edx = 0;  // @838_44ff60
  edx = (u32)((EBP - 296) + 108);  // @839_44ff60
  ecx = (u32)((EBP - 296) + 96);  // @840_44ff60
  eax = ext_441940_fastcall2(ecx, edx);  // @841_44ff60
  ecx = edx = 0;  // @842_44ff60
  ecx = (u32)((EBP - 296) + 136);  // @843_44ff60
  eax = ext_4de7a0_thiscall1(ecx);  // @844_44ff60
    // @845_44ff60
  esi = (esi + 1);  // @846_44ff60
  FL[3] = esi;  // @847_44ff60
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 136), sizeof v); (u32)v; });  // @848_44ff60
  if (FL[0] < FL[1]) goto L4508c0;  // @849_44ff60
  L450903:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @851_44ff60
  X1[0] = 0;  // @852_44ff60
  X1[1] = 0;  // @853_44ff60
  X1[2] = 0;  // @854_44ff60
  X1[3] = 0;  // @855_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @856_44ff60
  eax = (eax & (u32)(4278190079));  // @857_44ff60
  FL[3] = eax;  // @858_44ff60
  eax = (eax | (u32)(16777216));  // @859_44ff60
  FL[3] = eax;  // @860_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 60), &v, sizeof v); }  // @861_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @862_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @863_44ff60
  X0[1] = 0;  // @864_44ff60
  X0[2] = 0;  // @865_44ff60
  X0[3] = 0;  // @866_44ff60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @867_44ff60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @868_44ff60
  if (__builtin_parity(FL[2] & 0xff)) goto L45096a;  // @869_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @870_44ff60
  X0[1] = 0;  // @871_44ff60
  X0[2] = 0;  // @872_44ff60
  X0[3] = 0;  // @873_44ff60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @874_44ff60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @875_44ff60
  if (__builtin_parity(FL[2] & 0xff)) goto L45096a;  // @876_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @877_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @878_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @879_44ff60
  ecx = edx = 0;  // @880_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @881_44ff60
  PV[42] = (u32)(edx);  // @882_44ff60
  PV[43] = (u32)(eax);  // @883_44ff60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @884_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[43], PV[42], (u32)(6820668));  // @885_44ff60
  ecx = edx = 0;  // @886_44ff60
  L45096a:;
  ext_633654(G(u32, 0x6f5630));  // @888_44ff60
  return eax;  // @889_44ff60
}
PCREG(44ff60, lifted_44ff60);

extern "C" u32 THISCALL lifted_58ecd0(u32 ecx_in, u32 a0) {
  u8 F[0x540] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x440);
  u32 PV[157], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x440 + 8, &a0, 4);
  ebx = ecx;  // @0_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2034), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_58ecd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 960) + 36), &v, sizeof v); }  // @3_58ecd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 960) + 16), &v, sizeof v); }  // @4_58ecd0
  if (FL[0] == FL[1]) goto L58f496;  // @5_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @6_58ecd0
  if (FL[0] != FL[1]) goto L58f496;  // @7_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2098), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_58ecd0
  if (FL[0] != FL[1]) goto L58f496;  // @9_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_58ecd0
  ecx = edi;  // @11_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @12_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050578));  // @13_58ecd0
  ecx = edx = 0;  // @14_58ecd0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)((EBP - 960) + 23), &v, sizeof v); }  // @15_58ecd0
  esi = (u32)(6801640);  // @16_58ecd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @17_58ecd0
  if (FL[2] == 0) goto L58f276;  // @18_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @19_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @20_58ecd0
  ecx = (ecx >> (u32)(10));  // @21_58ecd0
  FL[3] = ecx;  // @22_58ecd0
  ecx = (ecx & 0xffffff00u) | (((~(ecx & 0xff))) & 0xff);  // @23_58ecd0
  FL[2] = ((ecx & 0xff) & (u32)(1));  // @24_58ecd0
  if (FL[2] == 0) goto L58f496;  // @25_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_58ecd0
  ecx = edi;  // @27_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 808)))(ecx);  // @28_58ecd0
  ecx = edx = 0;  // @29_58ecd0
  FL[2] = (eax & eax);  // @30_58ecd0
  if (FL[2] == 0) goto L58f607;  // @31_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_58ecd0
  ecx = ebx;  // @33_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1124)))(ecx);  // @34_58ecd0
  ecx = edx = 0;  // @35_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 124), &v, sizeof v); }  // @36_58ecd0
  FL[2] = (eax & eax);  // @37_58ecd0
  if (FL[2] == 0) goto L58f607;  // @38_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_58ecd0
  ecx = edi;  // @40_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @41_58ecd0
  ecx = edx = 0;  // @42_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; });  // @43_58ecd0
  esi = eax;  // @44_58ecd0
  PV[0] = (u32)(esi);  // @45_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 968) + 36), &v, sizeof v); }  // @46_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 152)))(ecx, PV[0], (u32)(0));  // @48_58ecd0
  ecx = edx = 0;  // @49_58ecd0
  FL[2] = (eax & eax);  // @50_58ecd0
  if (FL[2] == 0) goto L58f607;  // @51_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_58ecd0
  ecx = esi;  // @53_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 804), sizeof v); (u32)v; });  // @54_58ecd0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @55_58ecd0
  ecx = edx = 0;  // @56_58ecd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @57_58ecd0
  if (FL[2] != 0) goto L58edc9;  // @58_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_58ecd0
  ecx = esi;  // @60_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 816)))(ecx);  // @61_58ecd0
  ecx = edx = 0;  // @62_58ecd0
  FL[0] = eax; FL[1] = (u32)(7);  // @63_58ecd0
  if (FL[0] != FL[1]) goto L58f607;  // @64_58ecd0
  L58edc9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @66_58ecd0
  ecx = ebx;  // @67_58ecd0
  PV[1] = (u32)(edi);  // @68_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1372)))(ecx, PV[1]);  // @69_58ecd0
  ecx = edx = 0;  // @70_58ecd0
  ecx = eax;  // @71_58ecd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 960) + 40), &v, sizeof v); }  // @72_58ecd0
  FL[2] = (ecx & ecx);  // @73_58ecd0
  if (FL[2] != 0) goto L58ee41;  // @74_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_58ecd0
  ecx = edi;  // @76_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 808)))(ecx);  // @77_58ecd0
  ecx = edx = 0;  // @78_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @79_58ecd0
  esi = eax;  // @80_58ecd0
  ecx = ebx;  // @81_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(1230259533));  // @83_58ecd0
  ecx = edx = 0;  // @84_58ecd0
  PV[2] = (u32)(eax);  // @85_58ecd0
  ecx = esi;  // @86_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 708)))(ecx, PV[2]);  // @87_58ecd0
  ecx = edx = 0;  // @88_58ecd0
  edi = eax;  // @89_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_58ecd0
  PV[3] = (u32)(ebx);  // @91_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @92_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @93_58ecd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 972) + 52), &v, sizeof v); }  // @94_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3], (u32)(0), (u32)(1));  // @96_58ecd0
  ecx = edx = 0;  // @97_58ecd0
  PV[4] = (u32)(eax);  // @98_58ecd0
  ecx = edi;  // @99_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 752)))(ecx, PV[4]);  // @100_58ecd0
  ecx = edx = 0;  // @101_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @102_58ecd0
  ecx = edi;  // @103_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @104_58ecd0
  ecx = edx = 0;  // @105_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @106_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 28), sizeof v); (u32)v; });  // @107_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 40), sizeof v); (u32)v; });  // @108_58ecd0
  L58ee41:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 800)))(ecx);  // @111_58ecd0
  ecx = edx = 0;  // @112_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @113_58ecd0
  ecx = edi;  // @114_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 24), &v, sizeof v); }  // @115_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 860)))(ecx);  // @116_58ecd0
  ecx = edx = 0;  // @117_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 136), &v, sizeof v); }  // @118_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; });  // @119_58ecd0
  ecx = eax;  // @120_58ecd0
  PV[5] = (u32)(esi);  // @121_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 968) + 40), &v, sizeof v); }  // @122_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @123_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 152)))(ecx, PV[5], (u32)(0));  // @124_58ecd0
  ecx = edx = 0;  // @125_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @126_58ecd0
  PV[6] = (u32)(eax);  // @127_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 964) + 128), &v, sizeof v); }  // @128_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @129_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[6]);  // @131_58ecd0
  ecx = edx = 0;  // @132_58ecd0
  FL[2] = (eax & eax);  // @133_58ecd0
  if (FL[2] == 0) goto L58ef02;  // @134_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_58ecd0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; });  // @136_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @137_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @138_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[7]);  // @139_58ecd0
  ecx = edx = 0;  // @140_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @141_58ecd0
  esi = eax;  // @142_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @143_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 340)))(ecx, (u32)(6842300), (u32)(0));  // @145_58ecd0
  ecx = edx = 0;  // @146_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @147_58ecd0
  ecx = esi;  // @148_58ecd0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @149_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @150_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[8]);  // @151_58ecd0
  ecx = edx = 0;  // @152_58ecd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @153_58ecd0
  if (FL[2] == 0) goto L58eefe;  // @154_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @155_58ecd0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; });  // @156_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @157_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @158_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[9]);  // @159_58ecd0
  ecx = edx = 0;  // @160_58ecd0
  FL[2] = (eax & eax);  // @161_58ecd0
  if (FL[2] == 0) goto L58eefe;  // @162_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @163_58ecd0
  ecx = eax;  // @164_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 860)))(ecx);  // @165_58ecd0
  ecx = edx = 0;  // @166_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 32), &v, sizeof v); }  // @167_58ecd0
  L58eefe:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 28), sizeof v); (u32)v; });  // @169_58ecd0
  L58ef02:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 32), sizeof v); (u32)v; });  // @171_58ecd0
  ecx = (u32)(ebx + 2479);  // @172_58ecd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)((EBP - 960) + 24), &v, sizeof v); }  // @173_58ecd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @174_58ecd0
  PV[10] = (u32)(edi);  // @175_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[10]);  // @176_58ecd0
  ecx = edx = 0;  // @177_58ecd0
  PV[11] = (u32)(edi);  // @178_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 964) + 28), sizeof v); (u32)v; }); FL[1] = eax;  // @179_58ecd0
  if (FL[0] >= FL[1]) goto L58f4b0;  // @180_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @181_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[11]);  // @182_58ecd0
  ecx = edx = 0;  // @183_58ecd0
  PV[12] = (u32)(edi);  // @184_58ecd0
  ecx = ebx;  // @185_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[12]);  // @186_58ecd0
  ecx = edx = 0;  // @187_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @188_58ecd0
  ecx = (u32)(ebx + 2479);  // @189_58ecd0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 136), sizeof v); (u32)v; }));  // @190_58ecd0
  FL[3] = eax;  // @191_58ecd0
  PV[13] = (u32)(edi);  // @192_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 964) + 32), &v, sizeof v); }  // @193_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[13]);  // @194_58ecd0
  ecx = edx = 0;  // @195_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 28), sizeof v); (u32)v; }); FL[1] = eax;  // @196_58ecd0
  if (FL[0] >= FL[1]) goto L58ef5b;  // @197_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 28), sizeof v); (u32)v; });  // @198_58ecd0
  goto L58ef6b;  // @199_58ecd0
  L58ef5b:;
  PV[14] = (u32)(edi);  // @201_58ecd0
  ecx = (u32)(ebx + 2479);  // @202_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[14]);  // @203_58ecd0
  ecx = edx = 0;  // @204_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 28), &v, sizeof v); }  // @205_58ecd0
  L58ef6b:;
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; }));  // @207_58ecd0
  FL[3] = eax;  // @208_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 24), &v, sizeof v); }  // @209_58ecd0
  FL[2] = (eax & eax);  // @210_58ecd0
  if ((s32)FL[2] <= 0) goto L58f170;  // @211_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @212_58ecd0
  ecx = esi;  // @213_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 816)))(ecx);  // @214_58ecd0
  ecx = edx = 0;  // @215_58ecd0
  FL[0] = eax; FL[1] = (u32)(12);  // @216_58ecd0
  if (FL[0] != FL[1]) goto L58f022;  // @217_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @218_58ecd0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58efe3;  // @219_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @220_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @221_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @222_58ecd0
  ecx = edx = 0;  // @223_58ecd0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @224_58ecd0
  L58efac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @226_58ecd0
  esi = eax;  // @227_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @228_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @229_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @230_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @231_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6973416), (u32)(6999736), PV[15]);  // @232_58ecd0
  ecx = edx = 0;  // @233_58ecd0
  PV[16] = (u32)(eax);  // @234_58ecd0
  eax = (u32)((EBP - 964) + 192);  // @235_58ecd0
  PV[17] = (u32)(eax);  // @236_58ecd0
  PV[18] = (u32)(esi);  // @237_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 408)))(ecx, PV[18], PV[17], PV[16]);  // @238_58ecd0
  ecx = edx = 0;  // @239_58ecd0
  goto L58f1b5;  // @240_58ecd0
  L58efe3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @242_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @243_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @244_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @245_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999756));  // @246_58ecd0
  ecx = edx = 0;  // @247_58ecd0
  edx = (u32)((EBP - 960) + 184);  // @248_58ecd0
  edx = (edx - eax);  // @249_58ecd0
  FL[3] = edx;  // @250_58ecd0
  L58f010:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @252_58ecd0
  eax = (u32)(eax + 1);  // @253_58ecd0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + edx - 1), &v, sizeof v); }  // @254_58ecd0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @255_58ecd0
  if (FL[2] != 0) goto L58f010;  // @256_58ecd0
  goto L58f1b9;  // @257_58ecd0
  L58f022:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @259_58ecd0
  ecx = esi;  // @260_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 816)))(ecx);  // @261_58ecd0
  ecx = edx = 0;  // @262_58ecd0
  FL[0] = eax; FL[1] = (u32)(11);  // @263_58ecd0
  if (FL[0] != FL[1]) goto L58f092;  // @264_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @265_58ecd0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58f054;  // @266_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @267_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @268_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @269_58ecd0
  ecx = edx = 0;  // @270_58ecd0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @271_58ecd0
  goto L58efac;  // @272_58ecd0
  L58f054:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @274_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @275_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @276_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @277_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999796), (u32)(6999776), PV[19]);  // @278_58ecd0
  ecx = edx = 0;  // @279_58ecd0
  edx = (u32)((EBP - 960) + 184);  // @280_58ecd0
  edx = (edx - eax);  // @281_58ecd0
  FL[3] = edx;  // @282_58ecd0
  L58f080:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @284_58ecd0
  eax = (u32)(eax + 1);  // @285_58ecd0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + edx - 1), &v, sizeof v); }  // @286_58ecd0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @287_58ecd0
  if (FL[2] != 0) goto L58f080;  // @288_58ecd0
  goto L58f1b9;  // @289_58ecd0
  L58f092:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @291_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @292_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @293_58ecd0
  ecx = edx = 0;  // @294_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @295_58ecd0
  edi = (u32)(6801640);  // @296_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @297_58ecd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @298_58ecd0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58f114;  // @299_58ecd0
  FL[2] = (ecx & ecx);  // @300_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 136), &v, sizeof v); }  // @301_58ecd0
  if (FL[2] != 0) edi = ecx;  // @302_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @303_58ecd0
  PV[20] = (u32)(edi);  // @304_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @305_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @306_58ecd0
  ecx = edx;  // @307_58ecd0
  esi = edx;  // @308_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @309_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6850972), PV[20]);  // @310_58ecd0
  ecx = edx = 0;  // @311_58ecd0
  PV[21] = (u32)(eax);  // @312_58ecd0
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 964) + 28), sizeof v); (u32)v; });  // @313_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @314_58ecd0
  ecx = esi;  // @315_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999816), PV[22], PV[21]);  // @316_58ecd0
  ecx = edx = 0;  // @317_58ecd0
  PV[23] = (u32)(eax);  // @318_58ecd0
  eax = (u32)((EBP - 964) + 196);  // @319_58ecd0
  PV[24] = (u32)(eax);  // @320_58ecd0
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 968) + 152), sizeof v); (u32)v; });  // @321_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 408)))(ecx, PV[25], PV[24], PV[23]);  // @322_58ecd0
  ecx = edx = 0;  // @323_58ecd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 56), sizeof v); (u32)v; });  // @324_58ecd0
  goto L58f1b5;  // @325_58ecd0
  L58f114:;
  FL[2] = (ecx & ecx);  // @327_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 136), &v, sizeof v); }  // @328_58ecd0
  if (FL[2] != 0) edi = ecx;  // @329_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @330_58ecd0
  PV[26] = (u32)(edi);  // @331_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @332_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @333_58ecd0
  ecx = edx;  // @334_58ecd0
  esi = edx;  // @335_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @336_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6850972), PV[26]);  // @337_58ecd0
  ecx = edx = 0;  // @338_58ecd0
  PV[27] = (u32)(eax);  // @339_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @340_58ecd0
  ecx = esi;  // @341_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999836), PV[27]);  // @342_58ecd0
  ecx = edx = 0;  // @343_58ecd0
  PV[28] = (u32)(eax);  // @344_58ecd0
  eax = (u32)((EBP - 964) + 192);  // @345_58ecd0
  PV[29] = (u32)(eax);  // @346_58ecd0
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 968) + 148), sizeof v); (u32)v; });  // @347_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 408)))(ecx, PV[30], PV[29], PV[28]);  // @348_58ecd0
  ecx = edx = 0;  // @349_58ecd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 52), sizeof v); (u32)v; });  // @350_58ecd0
  goto L58f1b5;  // @351_58ecd0
  L58f170:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @353_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @354_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @355_58ecd0
  ecx = edx = 0;  // @356_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @357_58ecd0
  esi = eax;  // @358_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @359_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @360_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @361_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @362_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6973416), (u32)(6999720));  // @363_58ecd0
  ecx = edx = 0;  // @364_58ecd0
  PV[31] = (u32)(eax);  // @365_58ecd0
  eax = (u32)((EBP - 964) + 188);  // @366_58ecd0
  PV[32] = (u32)(eax);  // @367_58ecd0
  PV[33] = (u32)(esi);  // @368_58ecd0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 408)))(PV[33], PV[32], PV[31]);  // @369_58ecd0
  ecx = edx = 0;  // @370_58ecd0
  L58f1b5:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @372_58ecd0
  L58f1b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @374_58ecd0
  ecx = (u32)((EBP - 960) + 184);  // @375_58ecd0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @376_58ecd0
  FL[3] = (eax & 0xff);  // @377_58ecd0
  PV[34] = (u32)(ecx);  // @378_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @379_58ecd0
  eax = (eax & 0xff);  // @380_58ecd0
  PV[35] = (u32)(eax);  // @381_58ecd0
  eax = ext_589c20_thiscall2(ecx, PV[35]);  // @382_58ecd0
    // @383_58ecd0
  ecx = eax;  // @384_58ecd0
  eax = ext_59a580_thiscall4(ecx, PV[34], (u32)(-1), (u32)(0));  // @385_58ecd0
  ecx = edx = 0;  // @386_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 40), sizeof v); (u32)v; });  // @387_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 28), sizeof v); (u32)v; });  // @388_58ecd0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 32), sizeof v); (u32)v; }));  // @389_58ecd0
  FL[3] = edx;  // @390_58ecd0
  PV[36] = (u32)(edx);  // @391_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @392_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 804)))(ecx, PV[36]);  // @393_58ecd0
  ecx = edx = 0;  // @394_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @395_58ecd0
  ecx = edi;  // @396_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 752)))(ecx, (u32)(0), (u32)(0), (u32)(1));  // @397_58ecd0
  ecx = edx = 0;  // @398_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @399_58ecd0
  if (FL[0] == FL[1]) goto L58f24c;  // @400_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @401_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @402_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @403_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @404_58ecd0
  ecx = edx = 0;  // @405_58ecd0
  ecx = (u32)((EBP - 960) + 136);  // @406_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 136), &v, sizeof v); }  // @407_58ecd0
  { u32 v = (u32)((u32)(6999856)); __builtin_memcpy((void *)(u32)((EBP - 960) + 140), &v, sizeof v); }  // @408_58ecd0
  eax = ext_48aad0_thiscall1(ecx);  // @409_58ecd0
  ecx = edx = 0;  // @410_58ecd0
  PV[37] = (u32)(edi);  // @411_58ecd0
  ecx = eax;  // @412_58ecd0
  eax = ext_5e93f0_thiscall3(ecx, PV[37], (u32)(0));  // @413_58ecd0
  ecx = edx = 0;  // @414_58ecd0
  L58f24c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @416_58ecd0
  ecx = edi;  // @417_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 848)))(ecx);  // @418_58ecd0
  ecx = edx = 0;  // @419_58ecd0
  PV[38] = (u32)(edi);  // @420_58ecd0
  ecx = eax;  // @421_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @422_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 796)))(ecx, PV[38]);  // @423_58ecd0
  ecx = edx = 0;  // @424_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @425_58ecd0
  ecx = ebx;  // @426_58ecd0
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3850), sizeof v); (u32)v; });  // @427_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1012)))(ecx, PV[39]);  // @428_58ecd0
  ecx = edx = 0;  // @429_58ecd0
  goto L58f496;  // @430_58ecd0
  L58f276:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @432_58ecd0
  ecx = edi;  // @433_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @434_58ecd0
  ecx = edx = 0;  // @435_58ecd0
  FL[0] = eax; FL[1] = (u32)(3);  // @436_58ecd0
  if (FL[0] == FL[1]) goto L58f496;  // @437_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @438_58ecd0
  ecx = edi;  // @439_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @440_58ecd0
  ecx = edx = 0;  // @441_58ecd0
  ecx = esi;  // @442_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @443_58ecd0
  FL[2] = (eax & eax);  // @444_58ecd0
  if (FL[2] != 0) ecx = eax;  // @445_58ecd0
  eax = (u32)(6999876);  // @446_58ecd0
  L58f2a2:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @448_58ecd0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @449_58ecd0
  if (FL[0] != FL[1]) goto L58f2c2;  // @450_58ecd0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @451_58ecd0
  if (FL[2] == 0) goto L58f2be;  // @452_58ecd0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @453_58ecd0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @454_58ecd0
  if (FL[0] != FL[1]) goto L58f2c2;  // @455_58ecd0
  ecx = (ecx + (u32)(2));  // @456_58ecd0
  FL[3] = ecx;  // @457_58ecd0
  eax = (eax + (u32)(2));  // @458_58ecd0
  FL[3] = eax;  // @459_58ecd0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @460_58ecd0
  if (FL[2] != 0) goto L58f2a2;  // @461_58ecd0
  L58f2be:;
  eax = 0;  // @463_58ecd0
  FL[3] = eax;  // @464_58ecd0
  goto L58f2c7;  // @465_58ecd0
  L58f2c2:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @467_58ecd0
  eax = (eax | (u32)(1));  // @468_58ecd0
  FL[3] = eax;  // @469_58ecd0
  L58f2c7:;
  FL[2] = (eax & eax);  // @471_58ecd0
  if (FL[2] != 0) goto L58f4b9;  // @472_58ecd0
  eax = (u32)((EBP - 960) + 128);  // @473_58ecd0
  PV[40] = (u32)(eax);  // @474_58ecd0
  eax = (u32)((EBP - 964) + 48);  // @475_58ecd0
  PV[41] = (u32)(eax);  // @476_58ecd0
  eax = (u32)((EBP - 968) + 132);  // @477_58ecd0
  PV[42] = (u32)(eax);  // @478_58ecd0
  eax = (u32)((EBP - 972) + 52);  // @479_58ecd0
  PV[43] = (u32)(eax);  // @480_58ecd0
  ecx = (u32)(ebx + 2479);  // @481_58ecd0
  eax = ext_5afd00_thiscall5(ecx, PV[43], PV[42], PV[41], PV[40]);  // @482_58ecd0
  ecx = edx = 0;  // @483_58ecd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @484_58ecd0
  if (FL[2] == 0) goto L58f4af;  // @485_58ecd0
  esi = 0;  // @486_58ecd0
  FL[3] = esi;  // @487_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 960) + 32), &v, sizeof v); }  // @488_58ecd0
  L58f302:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @490_58ecd0
  if (FL[0] == FL[1]) goto L58f442;  // @491_58ecd0
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + esi + 40), sizeof v); (u32)v; });  // @492_58ecd0
  ecx = (u32)(ebx + 2395);  // @493_58ecd0
  eax = ext_5af130_fastcall3(ecx, edx, PV[44]);  // @494_58ecd0
  edx = 0;  // @495_58ecd0
  edi = eax;  // @496_58ecd0
  FL[2] = (edi & edi);  // @497_58ecd0
  if (FL[2] == 0) goto L58f442;  // @498_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @499_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @500_58ecd0
  if (FL[0] <= FL[1]) goto L58f3a8;  // @501_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @502_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 400)))(ecx);  // @503_58ecd0
  ecx = edx = 0;  // @504_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @505_58ecd0
  esi = (u32)(6801640);  // @506_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @507_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 136), &v, sizeof v); }  // @508_58ecd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @509_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @510_58ecd0
  FL[2] = (ecx & ecx);  // @511_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 155), sizeof v); (u32)v; });  // @512_58ecd0
  if (FL[2] != 0) esi = ecx;  // @513_58ecd0
  PV[45] = (u32)(esi);  // @514_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @515_58ecd0
  edi = ecx;  // @516_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @517_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6850972), PV[45]);  // @518_58ecd0
  ecx = edx = 0;  // @519_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 32), sizeof v); (u32)v; });  // @520_58ecd0
  ecx = edi;  // @521_58ecd0
  PV[46] = (u32)(eax);  // @522_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @523_58ecd0
  PV[47] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 964) + esi + 128), sizeof v); (u32)v; });  // @524_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999816), PV[47], PV[46]);  // @525_58ecd0
  ecx = edx = 0;  // @526_58ecd0
  PV[48] = (u32)(eax);  // @527_58ecd0
  eax = (u32)((EBP - 964) + 708);  // @528_58ecd0
  PV[49] = (u32)(eax);  // @529_58ecd0
  PV[50] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 968) + 152), sizeof v); (u32)v; });  // @530_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 408)))(ecx, PV[50], PV[49], PV[48]);  // @531_58ecd0
  ecx = edx = 0;  // @532_58ecd0
  goto L58f414;  // @533_58ecd0
  L58f3a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @535_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @536_58ecd0
  ecx = edx = 0;  // @537_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @538_58ecd0
  edi = (u32)(6801640);  // @539_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @540_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 136), &v, sizeof v); }  // @541_58ecd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @542_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @543_58ecd0
  FL[2] = (ecx & ecx);  // @544_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 155), sizeof v); (u32)v; });  // @545_58ecd0
  if (FL[2] != 0) edi = ecx;  // @546_58ecd0
  PV[51] = (u32)(edi);  // @547_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @548_58ecd0
  esi = ecx;  // @549_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @550_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6850972), PV[51]);  // @551_58ecd0
  ecx = edx = 0;  // @552_58ecd0
  PV[52] = (u32)(eax);  // @553_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @554_58ecd0
  ecx = esi;  // @555_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999836), PV[52]);  // @556_58ecd0
  ecx = edx = 0;  // @557_58ecd0
  PV[53] = (u32)(eax);  // @558_58ecd0
  eax = (u32)((EBP - 964) + 704);  // @559_58ecd0
  PV[54] = (u32)(eax);  // @560_58ecd0
  PV[55] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 968) + 148), sizeof v); (u32)v; });  // @561_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 408)))(ecx, PV[55], PV[54], PV[53]);  // @562_58ecd0
  ecx = edx = 0;  // @563_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 48), sizeof v); (u32)v; });  // @564_58ecd0
  L58f414:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 36), sizeof v); (u32)v; });  // @566_58ecd0
  ecx = (u32)((EBP - 960) + 696);  // @567_58ecd0
  PV[56] = (u32)(ecx);  // @568_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @569_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @570_58ecd0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @571_58ecd0
  FL[3] = (eax & 0xff);  // @572_58ecd0
  eax = (eax & 0xff);  // @573_58ecd0
  PV[57] = (u32)(eax);  // @574_58ecd0
  eax = ext_589c20_thiscall2(ecx, PV[57]);  // @575_58ecd0
    // @576_58ecd0
  ecx = eax;  // @577_58ecd0
  eax = ext_59a580_thiscall4(ecx, PV[56], (u32)(-1), (u32)(0));  // @578_58ecd0
  ecx = edx = 0;  // @579_58ecd0
  L58f442:;
  esi = (esi + (u32)(4));  // @581_58ecd0
  FL[3] = esi;  // @582_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 960) + 32), &v, sizeof v); }  // @583_58ecd0
  FL[0] = esi; FL[1] = (u32)(8);  // @584_58ecd0
  if ((s32)FL[0] < (s32)FL[1]) goto L58f302;  // @585_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @586_58ecd0
  ecx = ebx;  // @587_58ecd0
  PV[58] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3850), sizeof v); (u32)v; });  // @588_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1012)))(ecx, PV[58]);  // @589_58ecd0
  ecx = edx = 0;  // @590_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @591_58ecd0
  ecx = esi;  // @592_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @593_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 752)))(ecx, (u32)(0), (u32)(0), (u32)(1));  // @594_58ecd0
  ecx = edx = 0;  // @595_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @596_58ecd0
  PV[59] = (u32)(esi);  // @597_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[59]);  // @598_58ecd0
  ecx = edx = 0;  // @599_58ecd0
  PV[60] = (u32)(esi);  // @600_58ecd0
  ecx = ebx;  // @601_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[60]);  // @602_58ecd0
  ecx = edx = 0;  // @603_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @604_58ecd0
  ecx = esi;  // @605_58ecd0
  L58f490:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @607_58ecd0
  ecx = edx = 0;  // @608_58ecd0
  L58f496:;
  eax = 0;  // @610_58ecd0
  FL[3] = eax;  // @611_58ecd0
  ext_633654(G(u32, 0x6f5630));  // @612_58ecd0
  return eax;  // @613_58ecd0
  L58f4af:;
  PV[61] = (u32)(edi);  // @615_58ecd0
  L58f4b0:;
  ecx = ebx;  // @617_58ecd0
  eax = ext_594e30_thiscall2(ecx, PV[61]);  // @618_58ecd0
  ecx = edx = 0;  // @619_58ecd0
  goto L58f496;  // @620_58ecd0
  L58f4b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @622_58ecd0
  ecx = edi;  // @623_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @624_58ecd0
  ecx = edx = 0;  // @625_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @626_58ecd0
  FL[2] = (eax & eax);  // @627_58ecd0
  if (FL[2] != 0) esi = eax;  // @628_58ecd0
  eax = (u32)(6999888);  // @629_58ecd0
  L58f4d0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @631_58ecd0
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @632_58ecd0
  if (FL[0] != FL[1]) goto L58f4f0;  // @633_58ecd0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @634_58ecd0
  if (FL[2] == 0) goto L58f4ec;  // @635_58ecd0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @636_58ecd0
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @637_58ecd0
  if (FL[0] != FL[1]) goto L58f4f0;  // @638_58ecd0
  esi = (esi + (u32)(2));  // @639_58ecd0
  FL[3] = esi;  // @640_58ecd0
  eax = (eax + (u32)(2));  // @641_58ecd0
  FL[3] = eax;  // @642_58ecd0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @643_58ecd0
  if (FL[2] != 0) goto L58f4d0;  // @644_58ecd0
  L58f4ec:;
  eax = 0;  // @646_58ecd0
  FL[3] = eax;  // @647_58ecd0
  goto L58f4f5;  // @648_58ecd0
  L58f4f0:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @650_58ecd0
  eax = (eax | (u32)(1));  // @651_58ecd0
  FL[3] = eax;  // @652_58ecd0
  L58f4f5:;
  FL[2] = (eax & eax);  // @654_58ecd0
  if (FL[2] != 0) goto L58f607;  // @655_58ecd0
  ecx = (u32)(ebx + 2479);  // @656_58ecd0
  eax = ext_5afe20_thiscall2(ecx, (u32)(13));  // @657_58ecd0
  ecx = edx = 0;  // @658_58ecd0
  FL[0] = eax; FL[1] = (u32)(5);  // @659_58ecd0
  if (FL[0] <= FL[1]) goto L58f51a;  // @660_58ecd0
  esi = (u32)(5);  // @661_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 960) + 124), &v, sizeof v); }  // @662_58ecd0
  goto L58f535;  // @663_58ecd0
  L58f51a:;
  ecx = (u32)(ebx + 2479);  // @665_58ecd0
  eax = ext_5afe20_thiscall2(ecx, (u32)(13));  // @666_58ecd0
  ecx = edx = 0;  // @667_58ecd0
  esi = eax;  // @668_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 960) + 124), &v, sizeof v); }  // @669_58ecd0
  FL[2] = (esi & esi);  // @670_58ecd0
  if (FL[2] == 0) goto L58f891;  // @671_58ecd0
  L58f535:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @673_58ecd0
  ecx = ebx;  // @674_58ecd0
  PV[62] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3850), sizeof v); (u32)v; });  // @675_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 1012)))(ecx, PV[62]);  // @676_58ecd0
  ecx = edx = 0;  // @677_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @678_58ecd0
  ecx = edi;  // @679_58ecd0
  PV[63] = (u32)(esi);  // @680_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 804)))(ecx, PV[63]);  // @681_58ecd0
  ecx = edx = 0;  // @682_58ecd0
  FL[0] = esi; FL[1] = (u32)(1);  // @683_58ecd0
  if (FL[0] <= FL[1]) goto L58f5a4;  // @684_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @685_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @686_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @687_58ecd0
  ecx = edx = 0;  // @688_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @689_58ecd0
  esi = eax;  // @690_58ecd0
  PV[64] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; });  // @691_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @692_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @693_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @694_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @695_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6973416), (u32)(6999776), PV[64]);  // @696_58ecd0
  ecx = edx = 0;  // @697_58ecd0
  PV[65] = (u32)(eax);  // @698_58ecd0
  eax = (u32)((EBP - 964) + 192);  // @699_58ecd0
  PV[66] = (u32)(eax);  // @700_58ecd0
  PV[67] = (u32)(esi);  // @701_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 408)))(ecx, PV[67], PV[66], PV[65]);  // @702_58ecd0
  ecx = edx = 0;  // @703_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 32), sizeof v); (u32)v; });  // @704_58ecd0
  goto L58f5dd;  // @705_58ecd0
  L58f5a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @707_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @708_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @709_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @710_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999796));  // @711_58ecd0
  ecx = edx = 0;  // @712_58ecd0
  edx = (u32)((EBP - 960) + 184);  // @713_58ecd0
  edx = (edx - eax);  // @714_58ecd0
  FL[3] = edx;  // @715_58ecd0
  L58f5d0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @717_58ecd0
  eax = (u32)(eax + 1);  // @718_58ecd0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + edx - 1), &v, sizeof v); }  // @719_58ecd0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @720_58ecd0
  if (FL[2] != 0) goto L58f5d0;  // @721_58ecd0
  L58f5dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @723_58ecd0
  ecx = (u32)((EBP - 960) + 184);  // @724_58ecd0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @725_58ecd0
  FL[3] = (eax & 0xff);  // @726_58ecd0
  PV[68] = (u32)(ecx);  // @727_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @728_58ecd0
  eax = (eax & 0xff);  // @729_58ecd0
  PV[69] = (u32)(eax);  // @730_58ecd0
  eax = ext_589c20_thiscall2(ecx, PV[69]);  // @731_58ecd0
    // @732_58ecd0
  ecx = eax;  // @733_58ecd0
  eax = ext_59a580_thiscall4(ecx, PV[68], (u32)(-1), (u32)(0));  // @734_58ecd0
  ecx = edx = 0;  // @735_58ecd0
  L58f607:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @737_58ecd0
  ecx = ebx;  // @738_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1284)))(ecx);  // @739_58ecd0
  ecx = edx = 0;  // @740_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @741_58ecd0
  esi = eax;  // @742_58ecd0
  PV[70] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2114), sizeof v); (u32)v; });  // @743_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 964) + 28), &v, sizeof v); }  // @744_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @745_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @746_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[70]);  // @747_58ecd0
  ecx = edx = 0;  // @748_58ecd0
  ecx = (u32)(ebx + 2479);  // @749_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 32), &v, sizeof v); }  // @750_58ecd0
  PV[71] = (u32)(edi);  // @751_58ecd0
  eax = ext_5afdd0_thiscall2(ecx, PV[71]);  // @752_58ecd0
  ecx = edx = 0;  // @753_58ecd0
  FL[2] = (eax & eax);  // @754_58ecd0
  if (FL[2] != 0) goto L58f770;  // @755_58ecd0
  PV[72] = (u32)(edi);  // @756_58ecd0
  ecx = (u32)(ebx + 2395);  // @757_58ecd0
  eax = ext_5aeff0_thiscall2(ecx, PV[72]);  // @758_58ecd0
  ecx = edx = 0;  // @759_58ecd0
  FL[0] = eax; FL[1] = (u32)(14);  // @760_58ecd0
  if (FL[0] == FL[1]) goto L58f4af;  // @761_58ecd0
  FL[0] = eax; FL[1] = (u32)(15);  // @762_58ecd0
  if (FL[0] == FL[1]) goto L58f4af;  // @763_58ecd0
  FL[0] = eax; FL[1] = (u32)(16);  // @764_58ecd0
  if (FL[0] == FL[1]) goto L58f4af;  // @765_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @766_58ecd0
  ecx = (u32)((EBP - 960) + 124);  // @767_58ecd0
  PV[73] = (u32)(ecx);  // @768_58ecd0
  ecx = edi;  // @769_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 964) + 128), &v, sizeof v); }  // @770_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 964) + 132), &v, sizeof v); }  // @771_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 964) + 136), &v, sizeof v); }  // @772_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[73]);  // @773_58ecd0
  ecx = edx = 0;  // @774_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @775_58ecd0
  ecx = (u32)((EBP - 960) + 124);  // @776_58ecd0
  PV[74] = (u32)(ecx);  // @777_58ecd0
  ecx = ebx;  // @778_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[74]);  // @779_58ecd0
  ecx = edx = 0;  // @780_58ecd0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 960) + 124) + 0), 4); v; });  // @781_58ecd0
  X1[1] = 0;  // @782_58ecd0
  X1[2] = 0;  // @783_58ecd0
  X1[3] = 0;  // @784_58ecd0
  X0[0] = 0;  // @785_58ecd0
  X0[1] = 0;  // @786_58ecd0
  X0[2] = 0;  // @787_58ecd0
  X0[3] = 0;  // @788_58ecd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @789_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 128), &v, sizeof v); }  // @790_58ecd0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @791_58ecd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 960) + 132) + 0), 4); v; });  // @792_58ecd0
  X0[1] = 0;  // @793_58ecd0
  X0[2] = 0;  // @794_58ecd0
  X0[3] = 0;  // @795_58ecd0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @796_58ecd0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @797_58ecd0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @798_58ecd0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @799_58ecd0
  ecx = edx = 0;  // @800_58ecd0
  X1[0] = 0;  // @801_58ecd0
  X1[1] = 0;  // @802_58ecd0
  X1[2] = 0;  // @803_58ecd0
  X1[3] = 0;  // @804_58ecd0
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @805_58ecd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 2523) + 0), 4); v; });  // @806_58ecd0
  X0[1] = 0;  // @807_58ecd0
  X0[2] = 0;  // @808_58ecd0
  X0[3] = 0;  // @809_58ecd0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L58f711;  // @810_58ecd0
  __builtin_memcpy((void *)((u32)(ebx + 2523) + 0), &X1[0], 4);  // @811_58ecd0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 2519), &v, sizeof v); }  // @812_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 2527), &v, sizeof v); }  // @813_58ecd0
  L58f711:;
  ecx = ebx;  // @815_58ecd0
  eax = ext_5966e0_thiscall2(ecx, (u32)(1));  // @816_58ecd0
    // @817_58ecd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @818_58ecd0
  if (FL[2] == 0) goto L58f496;  // @819_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @820_58ecd0
  if (FL[0] == FL[1]) goto L58f766;  // @821_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @822_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @823_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @824_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @825_58ecd0
  ecx = edx = 0;  // @826_58ecd0
  ecx = (u32)((EBP - 960) + 136);  // @827_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 136), &v, sizeof v); }  // @828_58ecd0
  { u32 v = (u32)((u32)(6999856)); __builtin_memcpy((void *)(u32)((EBP - 960) + 140), &v, sizeof v); }  // @829_58ecd0
  eax = ext_48aad0_thiscall1(ecx);  // @830_58ecd0
  ecx = edx = 0;  // @831_58ecd0
  PV[75] = (u32)(edi);  // @832_58ecd0
  ecx = eax;  // @833_58ecd0
  eax = ext_5e93f0_thiscall3(ecx, PV[75], (u32)(0));  // @834_58ecd0
  ecx = edx = 0;  // @835_58ecd0
  L58f766:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @837_58ecd0
  ecx = ebx;  // @838_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 988)))(ecx);  // @839_58ecd0
  ecx = edx = 0;  // @840_58ecd0
  L58f770:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 23), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @842_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 960) + 15), &v, sizeof v); }  // @843_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 22), &v, sizeof v); }  // @844_58ecd0
  if (FL[0] == FL[1]) goto L58f8d9;  // @845_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @846_58ecd0
  ecx = edi;  // @847_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 868)))(ecx);  // @848_58ecd0
  ecx = edx = 0;  // @849_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @850_58ecd0
  ecx = edi;  // @851_58ecd0
  esi = eax;  // @852_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 860)))(ecx);  // @853_58ecd0
  ecx = edx = 0;  // @854_58ecd0
  FL[0] = eax; FL[1] = esi;  // @855_58ecd0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58f8d5;  // @856_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @857_58ecd0
  ecx = edi;  // @858_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 808)))(ecx);  // @859_58ecd0
  ecx = edx = 0;  // @860_58ecd0
  FL[2] = (eax & eax);  // @861_58ecd0
  if (FL[2] == 0) goto L58f8d5;  // @862_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @863_58ecd0
  ecx = ebx;  // @864_58ecd0
  PV[76] = (u32)(edi);  // @865_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1372)))(ecx, PV[76]);  // @866_58ecd0
  ecx = edx = 0;  // @867_58ecd0
  esi = eax;  // @868_58ecd0
  FL[2] = (esi & esi);  // @869_58ecd0
  if (FL[2] != 0) goto L58f826;  // @870_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @871_58ecd0
  ecx = edi;  // @872_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 808)))(ecx);  // @873_58ecd0
  ecx = edx = 0;  // @874_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @875_58ecd0
  esi = eax;  // @876_58ecd0
  ecx = ebx;  // @877_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @878_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(1230259533));  // @879_58ecd0
  ecx = edx = 0;  // @880_58ecd0
  PV[77] = (u32)(eax);  // @881_58ecd0
  ecx = esi;  // @882_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 708)))(ecx, PV[77]);  // @883_58ecd0
  ecx = edx = 0;  // @884_58ecd0
  edi = eax;  // @885_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @886_58ecd0
  PV[78] = (u32)(ebx);  // @887_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @888_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @889_58ecd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 972) + 148), &v, sizeof v); }  // @890_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @891_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[78], (u32)(0), (u32)(1));  // @892_58ecd0
  ecx = edx = 0;  // @893_58ecd0
  PV[79] = (u32)(eax);  // @894_58ecd0
  ecx = edi;  // @895_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 752)))(ecx, PV[79]);  // @896_58ecd0
  ecx = edx = 0;  // @897_58ecd0
  esi = edi;  // @898_58ecd0
  ecx = esi;  // @899_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @900_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @901_58ecd0
  ecx = edx = 0;  // @902_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @903_58ecd0
  L58f826:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @905_58ecd0
  ecx = esi;  // @906_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 800)))(ecx);  // @907_58ecd0
  ecx = edx = 0;  // @908_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @909_58ecd0
  ecx = edi;  // @910_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 136), &v, sizeof v); }  // @911_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 868)))(ecx);  // @912_58ecd0
  ecx = edx = 0;  // @913_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @914_58ecd0
  ecx = edi;  // @915_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 960) + 36), &v, sizeof v); }  // @916_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 860)))(ecx);  // @917_58ecd0
  ecx = edx = 0;  // @918_58ecd0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 36), sizeof v); (u32)v; }));  // @919_58ecd0
  FL[3] = eax;  // @920_58ecd0
  ecx = (u32)(ebx + 2479);  // @921_58ecd0
  PV[80] = (u32)(edi);  // @922_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 964) + 128), &v, sizeof v); }  // @923_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[80]);  // @924_58ecd0
  ecx = edx = 0;  // @925_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 136), sizeof v); (u32)v; });  // @926_58ecd0
  FL[0] = ecx; FL[1] = eax;  // @927_58ecd0
  if ((s32)FL[0] >= (s32)FL[1]) goto L58f8d5;  // @928_58ecd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; }) + ecx)); __builtin_memcpy((void *)(u32)((EBP - 960) + 124), &v, sizeof v); }  // @929_58ecd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; });  // @930_58ecd0
  ecx = (u32)(ebx + 2479);  // @931_58ecd0
  PV[81] = (u32)(edi);  // @932_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[81]);  // @933_58ecd0
  ecx = edx = 0;  // @934_58ecd0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 36), sizeof v); (u32)v; }));  // @935_58ecd0
  FL[3] = eax;  // @936_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; }); FL[1] = eax;  // @937_58ecd0
  if ((s32)FL[0] >= (s32)FL[1]) goto L58f8a7;  // @938_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 124), sizeof v); (u32)v; });  // @939_58ecd0
  goto L58f8b7;  // @940_58ecd0
  L58f891:;
  ecx = ebx;  // @942_58ecd0
  eax = ext_591e50_thiscall2(ecx, (u32)(13));  // @943_58ecd0
  ecx = edx = 0;  // @944_58ecd0
  PV[82] = (u32)(eax);  // @945_58ecd0
  ecx = ebx;  // @946_58ecd0
  eax = ext_594e30_thiscall2(ecx, PV[82]);  // @947_58ecd0
  ecx = edx = 0;  // @948_58ecd0
  goto L58f496;  // @949_58ecd0
  L58f8a7:;
  PV[83] = (u32)(edi);  // @951_58ecd0
  ecx = (u32)(ebx + 2479);  // @952_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[83]);  // @953_58ecd0
  ecx = edx = 0;  // @954_58ecd0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 36), sizeof v); (u32)v; }));  // @955_58ecd0
  FL[3] = eax;  // @956_58ecd0
  L58f8b7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @958_58ecd0
  ecx = esi;  // @959_58ecd0
  PV[84] = (u32)(eax);  // @960_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 804)))(ecx, PV[84]);  // @961_58ecd0
  ecx = edx = 0;  // @962_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @963_58ecd0
  ecx = edi;  // @964_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(esi + 868)))(ecx);  // @965_58ecd0
  ecx = edx = 0;  // @966_58ecd0
  PV[85] = (u32)(eax);  // @967_58ecd0
  ecx = edi;  // @968_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 864)))(ecx, PV[85]);  // @969_58ecd0
  ecx = edx = 0;  // @970_58ecd0
  L58f8d5:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @972_58ecd0
  L58f8d9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @974_58ecd0
  ecx = edi;  // @975_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @976_58ecd0
  ecx = edx = 0;  // @977_58ecd0
  ecx = eax;  // @978_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @979_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 776)))(ecx);  // @980_58ecd0
  ecx = edx = 0;  // @981_58ecd0
  FL[0] = eax; FL[1] = (u32)(1);  // @982_58ecd0
  if (FL[0] != FL[1]) goto L58fb0b;  // @983_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @984_58ecd0
  if (FL[0] == FL[1]) goto L58f9fb;  // @985_58ecd0
  ecx = ebx;  // @986_58ecd0
  eax = ext_591080_thiscall1(ecx);  // @987_58ecd0
  ecx = edx = 0;  // @988_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @989_58ecd0
  esi = eax;  // @990_58ecd0
  eax = (u32)((EBP - 960) + 136);  // @991_58ecd0
  ecx = ebx;  // @992_58ecd0
  PV[86] = (u32)(eax);  // @993_58ecd0
  eax = (u32)((EBP - 964) + 152);  // @994_58ecd0
  PV[87] = (u32)(eax);  // @995_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[87], PV[86]);  // @996_58ecd0
  ecx = edx = 0;  // @997_58ecd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 960) + 140) + 0), 4); v; });  // @998_58ecd0
  X0[1] = 0;  // @999_58ecd0
  X0[2] = 0;  // @1000_58ecd0
  X0[3] = 0;  // @1001_58ecd0
  ecx = (u32)((EBP - 960) + 136);  // @1002_58ecd0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860564) + 0), 4); v; })));  // @1003_58ecd0
  PV[88] = (u32)(ecx);  // @1004_58ecd0
  ecx = (u32)((EBP - 964) + 152);  // @1005_58ecd0
  PV[89] = (u32)(ecx);  // @1006_58ecd0
  ecx = esi;  // @1007_58ecd0
  __builtin_memcpy((void *)((u32)((EBP - 968) + 148) + 0), &X0[0], 4);  // @1008_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1009_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[89], PV[88]);  // @1010_58ecd0
  ecx = edx = 0;  // @1011_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1012_58ecd0
  ecx = ebx;  // @1013_58ecd0
  PV[90] = (u32)(esi);  // @1014_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1268)))(ecx, PV[90]);  // @1015_58ecd0
  ecx = edx = 0;  // @1016_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1017_58ecd0
  PV[91] = (u32)(esi);  // @1018_58ecd0
  eax = ext_46abf0_thiscall2(ecx, PV[91]);  // @1019_58ecd0
  ecx = edx = 0;  // @1020_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @1021_58ecd0
  FL[2] = (esi & esi);  // @1022_58ecd0
  if (FL[2] == 0) goto L58f98e;  // @1023_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1024_58ecd0
  ecx = ebx;  // @1025_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1312)))(ecx, (u32)(0));  // @1026_58ecd0
  ecx = edx = 0;  // @1027_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1028_58ecd0
  ecx = esi;  // @1029_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @1030_58ecd0
  ecx = edx = 0;  // @1031_58ecd0
  L58f98e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1033_58ecd0
  ecx = ebx;  // @1034_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1035_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1036_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1037_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(1));  // @1038_58ecd0
  ecx = edx = 0;  // @1039_58ecd0
  PV[92] = (u32)(eax);  // @1040_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1041_58ecd0
  ecx = esi;  // @1042_58ecd0
  PV[93] = (u32)(ebx);  // @1043_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[93], PV[92]);  // @1044_58ecd0
  ecx = edx = 0;  // @1045_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @1046_58ecd0
  PV[94] = (u32)(eax);  // @1047_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[94]);  // @1048_58ecd0
  ecx = edx = 0;  // @1049_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1050_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1051_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1052_58ecd0
  PV[95] = (u32)(edi);  // @1053_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1054_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1055_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[95]);  // @1056_58ecd0
  ecx = edx = 0;  // @1057_58ecd0
  PV[96] = (u32)(eax);  // @1058_58ecd0
  ecx = ebx;  // @1059_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1312)))(ecx, PV[96]);  // @1060_58ecd0
  ecx = edx = 0;  // @1061_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1062_58ecd0
  PV[97] = (u32)(edi);  // @1063_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[97]);  // @1064_58ecd0
  ecx = edx = 0;  // @1065_58ecd0
  PV[98] = (u32)(edi);  // @1066_58ecd0
  ecx = ebx;  // @1067_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[98]);  // @1068_58ecd0
  ecx = edx = 0;  // @1069_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 15), &v, sizeof v); }  // @1070_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 960) + 22), &v, sizeof v); }  // @1071_58ecd0
  goto L58fd29;  // @1072_58ecd0
  L58f9fb:;
  FL[2] = (esi & esi);  // @1074_58ecd0
  if (FL[2] == 0) goto L58fcf5;  // @1075_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1076_58ecd0
  ecx = esi;  // @1077_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @1078_58ecd0
  ecx = edx = 0;  // @1079_58ecd0
  ecx = eax;  // @1080_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1081_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 776)))(ecx);  // @1082_58ecd0
  ecx = edx = 0;  // @1083_58ecd0
  ecx = ebx;  // @1084_58ecd0
  FL[0] = eax; FL[1] = (u32)(1);  // @1085_58ecd0
  if (FL[0] != FL[1]) goto L58fa82;  // @1086_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1087_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1312)))(ecx, (u32)(0));  // @1088_58ecd0
  ecx = edx = 0;  // @1089_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1090_58ecd0
  ecx = ebx;  // @1091_58ecd0
  PV[99] = (u32)(esi);  // @1092_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1268)))(ecx, PV[99]);  // @1093_58ecd0
  ecx = edx = 0;  // @1094_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1095_58ecd0
  PV[100] = (u32)(esi);  // @1096_58ecd0
  eax = ext_46abf0_thiscall2(ecx, PV[100]);  // @1097_58ecd0
  ecx = edx = 0;  // @1098_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1099_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1100_58ecd0
  PV[101] = (u32)(edi);  // @1101_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1102_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1103_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[101]);  // @1104_58ecd0
  ecx = edx = 0;  // @1105_58ecd0
  PV[102] = (u32)(eax);  // @1106_58ecd0
  ecx = ebx;  // @1107_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1312)))(ecx, PV[102]);  // @1108_58ecd0
  ecx = edx = 0;  // @1109_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1110_58ecd0
  PV[103] = (u32)(edi);  // @1111_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[103]);  // @1112_58ecd0
  ecx = edx = 0;  // @1113_58ecd0
  PV[104] = (u32)(edi);  // @1114_58ecd0
  ecx = ebx;  // @1115_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[104]);  // @1116_58ecd0
  ecx = edx = 0;  // @1117_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1118_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 960) + 22), &v, sizeof v); }  // @1119_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 15), &v, sizeof v); }  // @1120_58ecd0
  goto L58fd29;  // @1121_58ecd0
  L58fa82:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1123_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1124_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1125_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1126_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(1));  // @1127_58ecd0
  ecx = edx = 0;  // @1128_58ecd0
  PV[105] = (u32)(eax);  // @1129_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1130_58ecd0
  ecx = esi;  // @1131_58ecd0
  PV[106] = (u32)(ebx);  // @1132_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[106], PV[105]);  // @1133_58ecd0
  ecx = edx = 0;  // @1134_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @1135_58ecd0
  PV[107] = (u32)(eax);  // @1136_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[107]);  // @1137_58ecd0
  ecx = edx = 0;  // @1138_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1139_58ecd0
  ecx = ebx;  // @1140_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1312)))(ecx, (u32)(0));  // @1141_58ecd0
  ecx = edx = 0;  // @1142_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @1143_58ecd0
  ecx = esi;  // @1144_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1145_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @1146_58ecd0
  ecx = edx = 0;  // @1147_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1148_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1149_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1150_58ecd0
  PV[108] = (u32)(edi);  // @1151_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1152_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1153_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[108]);  // @1154_58ecd0
  ecx = edx = 0;  // @1155_58ecd0
  PV[109] = (u32)(eax);  // @1156_58ecd0
  ecx = ebx;  // @1157_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1312)))(ecx, PV[109]);  // @1158_58ecd0
  ecx = edx = 0;  // @1159_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1160_58ecd0
  PV[110] = (u32)(edi);  // @1161_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[110]);  // @1162_58ecd0
  ecx = edx = 0;  // @1163_58ecd0
  PV[111] = (u32)(edi);  // @1164_58ecd0
  ecx = ebx;  // @1165_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[111]);  // @1166_58ecd0
  ecx = edx = 0;  // @1167_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 960) + 22), &v, sizeof v); }  // @1168_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 15), &v, sizeof v); }  // @1169_58ecd0
  goto L58fd29;  // @1170_58ecd0
  L58fb0b:;
  PV[112] = (u32)(edi);  // @1172_58ecd0
  ecx = (u32)(ebx + 2395);  // @1173_58ecd0
  eax = ext_5aeff0_thiscall2(ecx, PV[112]);  // @1174_58ecd0
  ecx = edx = 0;  // @1175_58ecd0
  FL[0] = eax; FL[1] = (u32)(3);  // @1176_58ecd0
  if (FL[0] == FL[1]) goto L58fb26;  // @1177_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 23), &v, sizeof v); }  // @1178_58ecd0
  FL[0] = eax; FL[1] = (u32)(4);  // @1179_58ecd0
  if (FL[0] != FL[1]) goto L58fb2b;  // @1180_58ecd0
  L58fb26:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 960) + 23), &v, sizeof v); }  // @1182_58ecd0
  L58fb2b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2130), sizeof v); (u32)v; });  // @1184_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1185_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 144)))(ecx);  // @1186_58ecd0
  ecx = edx = 0;  // @1187_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2130), sizeof v); (u32)v; });  // @1188_58ecd0
  eax = (u32)((EBP - 960) + 48);  // @1189_58ecd0
  PV[113] = (u32)(eax);  // @1190_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 7439), sizeof v); (u32)v; });  // @1191_58ecd0
  eax = ext_596710_thiscall2(ecx, PV[113]);  // @1192_58ecd0
  ecx = edx = 0;  // @1193_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 105), sizeof v); (u32)v; });  // @1194_58ecd0
  FL[2] = (eax & eax);  // @1195_58ecd0
  if (FL[2] == 0) goto L58fbc0;  // @1196_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 23), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1197_58ecd0
  if (FL[0] == FL[1]) goto L58fbc0;  // @1198_58ecd0
  FL[0] = esi; FL[1] = eax;  // @1199_58ecd0
  if (FL[0] != FL[1]) goto L58fb70;  // @1200_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1201_58ecd0
  ecx = ebx;  // @1202_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1312)))(ecx, (u32)(0));  // @1203_58ecd0
  ecx = edx = 0;  // @1204_58ecd0
  esi = 0;  // @1205_58ecd0
  FL[3] = esi;  // @1206_58ecd0
  L58fb70:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1208_58ecd0
  ecx = (u32)((EBP - 960) + 136);  // @1209_58ecd0
  PV[114] = (u32)(ecx);  // @1210_58ecd0
  ecx = (u32)((EBP - 964) + 152);  // @1211_58ecd0
  PV[115] = (u32)(ecx);  // @1212_58ecd0
  ecx = ebx;  // @1213_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[115], PV[114]);  // @1214_58ecd0
  ecx = edx = 0;  // @1215_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 105), sizeof v); (u32)v; });  // @1216_58ecd0
  edx = (u32)((EBP - 960) + 136);  // @1217_58ecd0
  PV[116] = (u32)(edx);  // @1218_58ecd0
  edx = (u32)((EBP - 964) + 152);  // @1219_58ecd0
  PV[117] = (u32)(edx);  // @1220_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1221_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[117], PV[116]);  // @1222_58ecd0
  ecx = edx = 0;  // @1223_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1224_58ecd0
  ecx = ebx;  // @1225_58ecd0
  PV[118] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 105), sizeof v); (u32)v; });  // @1226_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1268)))(ecx, PV[118]);  // @1227_58ecd0
  ecx = edx = 0;  // @1228_58ecd0
  PV[119] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 105), sizeof v); (u32)v; });  // @1229_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1230_58ecd0
  eax = ext_46abf0_thiscall2(ecx, PV[119]);  // @1231_58ecd0
  ecx = edx = 0;  // @1232_58ecd0
  L58fbc0:;
  FL[2] = (esi & esi);  // @1234_58ecd0
  if (FL[2] == 0) goto L58fca4;  // @1235_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1236_58ecd0
  ecx = esi;  // @1237_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @1238_58ecd0
  ecx = edx = 0;  // @1239_58ecd0
  ecx = eax;  // @1240_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1241_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 776)))(ecx);  // @1242_58ecd0
  ecx = edx = 0;  // @1243_58ecd0
  FL[0] = eax; FL[1] = (u32)(1);  // @1244_58ecd0
  if (FL[0] == FL[1]) goto L58fc45;  // @1245_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 23), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1246_58ecd0
  if (FL[0] == FL[1]) goto L58fc45;  // @1247_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1248_58ecd0
  ecx = ebx;  // @1249_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1312)))(ecx, (u32)(0));  // @1250_58ecd0
  ecx = edx = 0;  // @1251_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1252_58ecd0
  ecx = esi;  // @1253_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @1254_58ecd0
  ecx = edx = 0;  // @1255_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1256_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1257_58ecd0
  PV[120] = (u32)(edi);  // @1258_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1259_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1260_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[120]);  // @1261_58ecd0
  ecx = edx = 0;  // @1262_58ecd0
  PV[121] = (u32)(eax);  // @1263_58ecd0
  ecx = ebx;  // @1264_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1312)))(ecx, PV[121]);  // @1265_58ecd0
  ecx = edx = 0;  // @1266_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1267_58ecd0
  PV[122] = (u32)(edi);  // @1268_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[122]);  // @1269_58ecd0
  ecx = edx = 0;  // @1270_58ecd0
  PV[123] = (u32)(edi);  // @1271_58ecd0
  ecx = ebx;  // @1272_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[123]);  // @1273_58ecd0
  ecx = edx = 0;  // @1274_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1275_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 15), &v, sizeof v); }  // @1276_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 960) + 22), &v, sizeof v); }  // @1277_58ecd0
  goto L58fd29;  // @1278_58ecd0
  L58fc45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1280_58ecd0
  ecx = ebx;  // @1281_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1282_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1283_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1284_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(1));  // @1285_58ecd0
  ecx = edx = 0;  // @1286_58ecd0
  PV[124] = (u32)(eax);  // @1287_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1288_58ecd0
  ecx = esi;  // @1289_58ecd0
  PV[125] = (u32)(ebx);  // @1290_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[125], PV[124]);  // @1291_58ecd0
  ecx = edx = 0;  // @1292_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @1293_58ecd0
  PV[126] = (u32)(eax);  // @1294_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[126]);  // @1295_58ecd0
  ecx = edx = 0;  // @1296_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1297_58ecd0
  ecx = edi;  // @1298_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1299_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @1300_58ecd0
  ecx = edx = 0;  // @1301_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1302_58ecd0
  PV[127] = (u32)(edi);  // @1303_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[127]);  // @1304_58ecd0
  ecx = edx = 0;  // @1305_58ecd0
  PV[128] = (u32)(edi);  // @1306_58ecd0
  ecx = ebx;  // @1307_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[128]);  // @1308_58ecd0
  ecx = edx = 0;  // @1309_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 15), &v, sizeof v); }  // @1310_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 960) + 22), &v, sizeof v); }  // @1311_58ecd0
  goto L58fd29;  // @1312_58ecd0
  L58fca4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1314_58ecd0
  if (FL[0] == FL[1]) goto L58fcf5;  // @1315_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1316_58ecd0
  ecx = ebx;  // @1317_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1318_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1319_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1320_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(1));  // @1321_58ecd0
  ecx = edx = 0;  // @1322_58ecd0
  PV[129] = (u32)(eax);  // @1323_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1324_58ecd0
  ecx = esi;  // @1325_58ecd0
  PV[130] = (u32)(ebx);  // @1326_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[130], PV[129]);  // @1327_58ecd0
  ecx = edx = 0;  // @1328_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 24), sizeof v); (u32)v; });  // @1329_58ecd0
  PV[131] = (u32)(eax);  // @1330_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[131]);  // @1331_58ecd0
  ecx = edx = 0;  // @1332_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1333_58ecd0
  ecx = edi;  // @1334_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1335_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @1336_58ecd0
  ecx = edx = 0;  // @1337_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 960) + 22), &v, sizeof v); }  // @1338_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 15), &v, sizeof v); }  // @1339_58ecd0
  goto L58fd29;  // @1340_58ecd0
  L58fcf5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1342_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1343_58ecd0
  PV[132] = (u32)(edi);  // @1344_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1345_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1346_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[132]);  // @1347_58ecd0
  ecx = edx = 0;  // @1348_58ecd0
  PV[133] = (u32)(eax);  // @1349_58ecd0
  ecx = ebx;  // @1350_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1312)))(ecx, PV[133]);  // @1351_58ecd0
  ecx = edx = 0;  // @1352_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1353_58ecd0
  PV[134] = (u32)(edi);  // @1354_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[134]);  // @1355_58ecd0
  ecx = edx = 0;  // @1356_58ecd0
  PV[135] = (u32)(edi);  // @1357_58ecd0
  ecx = ebx;  // @1358_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[135]);  // @1359_58ecd0
  ecx = edx = 0;  // @1360_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1361_58ecd0
  L58fd29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1363_58ecd0
  ecx = edi;  // @1364_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @1365_58ecd0
  ecx = edx = 0;  // @1366_58ecd0
  esi = (u32)(6801640);  // @1367_58ecd0
  ecx = esi;  // @1368_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @1369_58ecd0
  FL[2] = (eax & eax);  // @1370_58ecd0
  if (FL[2] != 0) ecx = eax;  // @1371_58ecd0
  eax = (u32)(6999888);  // @1372_58ecd0
  L58fd47:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @1374_58ecd0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1375_58ecd0
  if (FL[0] != FL[1]) goto L58fd67;  // @1376_58ecd0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @1377_58ecd0
  if (FL[2] == 0) goto L58fd63;  // @1378_58ecd0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @1379_58ecd0
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @1380_58ecd0
  if (FL[0] != FL[1]) goto L58fd67;  // @1381_58ecd0
  ecx = (ecx + (u32)(2));  // @1382_58ecd0
  FL[3] = ecx;  // @1383_58ecd0
  eax = (eax + (u32)(2));  // @1384_58ecd0
  FL[3] = eax;  // @1385_58ecd0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @1386_58ecd0
  if (FL[2] != 0) goto L58fd47;  // @1387_58ecd0
  L58fd63:;
  eax = 0;  // @1389_58ecd0
  FL[3] = eax;  // @1390_58ecd0
  goto L58fd6c;  // @1391_58ecd0
  L58fd67:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @1393_58ecd0
  eax = (eax | (u32)(1));  // @1394_58ecd0
  FL[3] = eax;  // @1395_58ecd0
  L58fd6c:;
  FL[2] = (eax & eax);  // @1397_58ecd0
  if (FL[2] == 0) goto L58fef9;  // @1398_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1399_58ecd0
  if (FL[0] != FL[1]) goto L58fd86;  // @1400_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1401_58ecd0
  if (FL[0] == FL[1]) goto L58f496;  // @1402_58ecd0
  L58fd86:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1404_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1405_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @1406_58ecd0
  ecx = edx = 0;  // @1407_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1408_58ecd0
  edi = eax;  // @1409_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1410_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @1411_58ecd0
  ecx = edx = 0;  // @1412_58ecd0
  edx = esi;  // @1413_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1414_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @1415_58ecd0
  FL[2] = (ecx & ecx);  // @1416_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1417_58ecd0
  if (FL[2] != 0) edx = ecx;  // @1418_58ecd0
  PV[136] = (u32)(edx);  // @1419_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1420_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @1421_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1422_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6850972), PV[136]);  // @1423_58ecd0
  ecx = edx = 0;  // @1424_58ecd0
  PV[137] = (u32)(eax);  // @1425_58ecd0
  eax = (u32)((EBP - 968) + 192);  // @1426_58ecd0
  PV[138] = (u32)(eax);  // @1427_58ecd0
  PV[139] = (u32)(edi);  // @1428_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 408)))(ecx, PV[139], PV[138], (u32)(6779752), PV[137]);  // @1429_58ecd0
  ecx = edx = 0;  // @1430_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @1431_58ecd0
  ecx = (u32)((EBP - 960) + 200);  // @1432_58ecd0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @1433_58ecd0
  FL[3] = (eax & 0xff);  // @1434_58ecd0
  eax = (eax & 0xff);  // @1435_58ecd0
  PV[140] = (u32)(ecx);  // @1436_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1437_58ecd0
  PV[141] = (u32)(eax);  // @1438_58ecd0
  eax = ext_589c20_thiscall2(ecx, PV[141]);  // @1439_58ecd0
    // @1440_58ecd0
  ecx = eax;  // @1441_58ecd0
  eax = ext_59a580_thiscall4(ecx, PV[140], (u32)(-1), (u32)(0));  // @1442_58ecd0
  ecx = edx = 0;  // @1443_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1444_58ecd0
  ecx = edi;  // @1445_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1446_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @1447_58ecd0
  ecx = edx = 0;  // @1448_58ecd0
  esi = (u32)(6801640);  // @1449_58ecd0
  ecx = esi;  // @1450_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @1451_58ecd0
  FL[2] = (eax & eax);  // @1452_58ecd0
  if (FL[2] != 0) ecx = eax;  // @1453_58ecd0
  PV[142] = (u32)(ecx);  // @1454_58ecd0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676410))(PV[142], (u32)(6999904), (u32)(5));  // @1455_58ecd0
  ecx = edx = 0;  // @1456_58ecd0
  ecx = ebx;  // @1457_58ecd0
  FL[2] = (eax & eax);  // @1458_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1459_58ecd0
  if (FL[2] != 0) goto L58fe49;  // @1460_58ecd0
  PV[143] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3854), sizeof v); (u32)v; });  // @1461_58ecd0
  goto L58fe4f;  // @1462_58ecd0
  L58fe49:;
  PV[144] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3858), sizeof v); (u32)v; });  // @1464_58ecd0
  L58fe4f:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1012)))(ecx, PV[144], PV[143]);  // @1466_58ecd0
  ecx = edx = 0;  // @1467_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1468_58ecd0
  ecx = edi;  // @1469_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @1470_58ecd0
  ecx = edx = 0;  // @1471_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @1472_58ecd0
  FL[2] = (eax & eax);  // @1473_58ecd0
  if (FL[2] != 0) esi = eax;  // @1474_58ecd0
  eax = (u32)(6999888);  // @1475_58ecd0
  L58fe70:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @1477_58ecd0
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1478_58ecd0
  if (FL[0] != FL[1]) goto L58fe90;  // @1479_58ecd0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @1480_58ecd0
  if (FL[2] == 0) goto L58fe8c;  // @1481_58ecd0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @1482_58ecd0
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @1483_58ecd0
  if (FL[0] != FL[1]) goto L58fe90;  // @1484_58ecd0
  esi = (esi + (u32)(2));  // @1485_58ecd0
  FL[3] = esi;  // @1486_58ecd0
  eax = (eax + (u32)(2));  // @1487_58ecd0
  FL[3] = eax;  // @1488_58ecd0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @1489_58ecd0
  if (FL[2] != 0) goto L58fe70;  // @1490_58ecd0
  L58fe8c:;
  eax = 0;  // @1492_58ecd0
  FL[3] = eax;  // @1493_58ecd0
  goto L58fe95;  // @1494_58ecd0
  L58fe90:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @1496_58ecd0
  eax = (eax | (u32)(1));  // @1497_58ecd0
  FL[3] = eax;  // @1498_58ecd0
  L58fe95:;
  FL[2] = (eax & eax);  // @1500_58ecd0
  if (FL[2] != 0) goto L58fef9;  // @1501_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1502_58ecd0
  ecx = ebx;  // @1503_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1124)))(ecx);  // @1504_58ecd0
  ecx = edx = 0;  // @1505_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1506_58ecd0
  esi = eax;  // @1507_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1508_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1509_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 744)))(ecx, (u32)(0));  // @1510_58ecd0
  ecx = edx = 0;  // @1511_58ecd0
  PV[145] = (u32)(eax);  // @1512_58ecd0
  ecx = esi;  // @1513_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 152)))(ecx, PV[145]);  // @1514_58ecd0
  ecx = edx = 0;  // @1515_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1516_58ecd0
  esi = eax;  // @1517_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 16), sizeof v); (u32)v; });  // @1518_58ecd0
  PV[146] = (u32)(edi);  // @1519_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @1520_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1521_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[146]);  // @1522_58ecd0
  ecx = edx = 0;  // @1523_58ecd0
  FL[0] = esi; FL[1] = eax;  // @1524_58ecd0
  if (FL[0] == FL[1]) goto L58fef9;  // @1525_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1526_58ecd0
  PV[147] = (u32)(edi);  // @1527_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[147]);  // @1528_58ecd0
  ecx = edx = 0;  // @1529_58ecd0
  PV[148] = (u32)(edi);  // @1530_58ecd0
  ecx = ebx;  // @1531_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[148]);  // @1532_58ecd0
  ecx = edx = 0;  // @1533_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1534_58ecd0
  ecx = edi;  // @1535_58ecd0
  goto L58f490;  // @1536_58ecd0
  L58fef9:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 964) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1538_58ecd0
  if (FL[0] == FL[1]) goto L58f496;  // @1539_58ecd0
  PV[149] = (u32)(edi);  // @1540_58ecd0
  ecx = ebx;  // @1541_58ecd0
  eax = ext_4730b0_thiscall2(ecx, PV[149]);  // @1542_58ecd0
  ecx = edx = 0;  // @1543_58ecd0
  ext_633654(G(u32, 0x6f5630));  // @1544_58ecd0
  return eax;  // @1545_58ecd0
}
PCREG(58ecd0, lifted_58ecd0);

