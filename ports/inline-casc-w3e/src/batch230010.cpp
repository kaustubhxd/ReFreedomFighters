// batch230010.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d70_dbl(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d76_dbl(double) __asm__("ext_634d76");
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_44f550_fastcall2(u32, u32) __asm__("ext_44f550");
extern "C" u32 FASTCALL ext_459fc0_fastcall3(u32, u32, u32) __asm__("ext_459fc0");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4de4f0_fastcall2(u32, u32) __asm__("ext_4de4f0");
extern "C" u32 FASTCALL ext_4df1e0_fastcall2(u32, u32) __asm__("ext_4df1e0");
extern "C" u32 FASTCALL ext_4e08d0_fastcall2(u32, u32) __asm__("ext_4e08d0");
extern "C" u32 FASTCALL ext_4e0900_fastcall2(u32, u32) __asm__("ext_4e0900");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_4e2c60_fastcall2(u32, u32) __asm__("ext_4e2c60");
extern "C" u32 FASTCALL ext_5af130_fastcall3(u32, u32, u32) __asm__("ext_5af130");
extern "C" u32 THISCALL ext_44ef80_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_44ef80");
extern "C" u32 THISCALL ext_44f0f0_thiscall3(u32, u32, u32) __asm__("ext_44f0f0");
extern "C" u32 THISCALL ext_44f8b0_thiscall4(u32, u32, u32, u32) __asm__("ext_44f8b0");
extern "C" u32 THISCALL ext_450fc0_thiscall3(u32, u32, u32) __asm__("ext_450fc0");
extern "C" u32 THISCALL ext_46abf0_thiscall2(u32, u32) __asm__("ext_46abf0");
extern "C" u32 THISCALL ext_470550_thiscall2(u32, u32) __asm__("ext_470550");
extern "C" u32 THISCALL ext_4730b0_thiscall2(u32, u32) __asm__("ext_4730b0");
extern "C" u32 THISCALL ext_48aad0_thiscall1(u32) __asm__("ext_48aad0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e87b0_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_4e87b0");
extern "C" u32 THISCALL ext_4e89d0_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_4e89d0");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_516b60_thiscall4(u32, u32, u32, u32) __asm__("ext_516b60");
extern "C" u32 THISCALL ext_516f40_thiscall2(u32, u32) __asm__("ext_516f40");
extern "C" u32 THISCALL ext_568dc0_thiscall1(u32) __asm__("ext_568dc0");
extern "C" u32 THISCALL ext_589c20_thiscall2(u32, u32) __asm__("ext_589c20");
extern "C" u32 THISCALL ext_591080_thiscall1(u32) __asm__("ext_591080");
extern "C" u32 THISCALL ext_591e50_thiscall2(u32, u32) __asm__("ext_591e50");
extern "C" u32 THISCALL ext_594540_thiscall2(u32, u32) __asm__("ext_594540");
extern "C" u32 THISCALL ext_594e30_thiscall2(u32, u32) __asm__("ext_594e30");
extern "C" u32 THISCALL ext_5950c0_thiscall4(u32, u32, u32, u32) __asm__("ext_5950c0");
extern "C" u32 THISCALL ext_5966e0_thiscall2(u32, u32) __asm__("ext_5966e0");
extern "C" u32 THISCALL ext_596710_thiscall2(u32, u32) __asm__("ext_596710");
extern "C" u32 THISCALL ext_59a580_thiscall4(u32, u32, u32, u32) __asm__("ext_59a580");
extern "C" u32 THISCALL ext_5a8510_thiscall3(u32, u32, u32) __asm__("ext_5a8510");
extern "C" u32 THISCALL ext_5aeff0_thiscall2(u32, u32) __asm__("ext_5aeff0");
extern "C" u32 THISCALL ext_5af0d0_thiscall2(u32, u32) __asm__("ext_5af0d0");
extern "C" u32 THISCALL ext_5af5b0_thiscall4(u32, u32, u32, u32) __asm__("ext_5af5b0");
extern "C" u32 THISCALL ext_5afbb0_thiscall3(u32, u32, u32) __asm__("ext_5afbb0");
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

extern "C" u32 FASTCALL lifted_4de7e0(u32 ecx_in, u32 edx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  esi = edx;  // @0_4de7e0
  edi = ecx;  // @1_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @2_4de7e0
  X0[1] = 0;  // @3_4de7e0
  X0[2] = 0;  // @4_4de7e0
  X0[3] = 0;  // @5_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @6_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @7_4de7e0
  ecx = edx = 0;  // @8_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @9_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @10_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @11_4de7e0
  X0[1] = 0;  // @12_4de7e0
  X0[2] = 0;  // @13_4de7e0
  X0[3] = 0;  // @14_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @15_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @16_4de7e0
  ecx = edx = 0;  // @17_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @18_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @19_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @20_4de7e0
  X0[1] = 0;  // @21_4de7e0
  X0[2] = 0;  // @22_4de7e0
  X0[3] = 0;  // @23_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @24_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @25_4de7e0
  ecx = edx = 0;  // @26_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @27_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @28_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @29_4de7e0
  X0[1] = 0;  // @30_4de7e0
  X0[2] = 0;  // @31_4de7e0
  X0[3] = 0;  // @32_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @33_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @34_4de7e0
  ecx = edx = 0;  // @35_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @36_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @37_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @38_4de7e0
  X0[1] = 0;  // @39_4de7e0
  X0[2] = 0;  // @40_4de7e0
  X0[3] = 0;  // @41_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @42_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @43_4de7e0
  ecx = edx = 0;  // @44_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @45_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @46_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @47_4de7e0
  X0[1] = 0;  // @48_4de7e0
  X0[2] = 0;  // @49_4de7e0
  X0[3] = 0;  // @50_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @51_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @52_4de7e0
  ecx = edx = 0;  // @53_4de7e0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @54_4de7e0
  X2[1] = 0;  // @55_4de7e0
  X2[2] = 0;  // @56_4de7e0
  X2[3] = 0;  // @57_4de7e0
  X3[0] = 0;  // @58_4de7e0
  X3[1] = 0;  // @59_4de7e0
  X3[2] = 0;  // @60_4de7e0
  X3[3] = 0;  // @61_4de7e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; });  // @62_4de7e0
  X1[1] = 0;  // @63_4de7e0
  X1[2] = 0;  // @64_4de7e0
  X1[3] = 0;  // @65_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @66_4de7e0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; });  // @67_4de7e0
  X4[1] = 0;  // @68_4de7e0
  X4[2] = 0;  // @69_4de7e0
  X4[3] = 0;  // @70_4de7e0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @71_4de7e0
  X5[1] = 0;  // @72_4de7e0
  X5[2] = 0;  // @73_4de7e0
  X5[3] = 0;  // @74_4de7e0
  X3[0] = F2U((float)U2D(X0[0], X0[1]));  // @75_4de7e0
  X0[0] = X2[0];  // @76_4de7e0
  X0[1] = X2[1];  // @77_4de7e0
  X0[2] = X2[2];  // @78_4de7e0
  X0[3] = X2[3];  // @79_4de7e0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @80_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @81_4de7e0
  X4[0] = F2U(U2F(X4[0]) * U2F(X3[0]));  // @82_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @83_4de7e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @84_4de7e0
  X1[1] = 0;  // @85_4de7e0
  X1[2] = 0;  // @86_4de7e0
  X1[3] = 0;  // @87_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 32) + 0), 4); v; })));  // @88_4de7e0
  X4[0] = F2U(U2F(X4[0]) + U2F(X2[0]));  // @89_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X0[0], 4);  // @90_4de7e0
  X0[0] = X5[0];  // @91_4de7e0
  X0[1] = X5[1];  // @92_4de7e0
  X0[2] = X5[2];  // @93_4de7e0
  X0[3] = X5[3];  // @94_4de7e0
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 32) + 0), 4); v; })));  // @95_4de7e0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @96_4de7e0
  X2[1] = 0;  // @97_4de7e0
  X2[2] = 0;  // @98_4de7e0
  X2[3] = 0;  // @99_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @100_4de7e0
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @101_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @102_4de7e0
  X1[0] = X2[0];  // @103_4de7e0
  X1[1] = X2[1];  // @104_4de7e0
  X1[2] = X2[2];  // @105_4de7e0
  X1[3] = X2[3];  // @106_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @107_4de7e0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @108_4de7e0
  X5[0] = F2U(U2F(X5[0]) + U2F(X4[0]));  // @109_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 28) + 0), &X0[0], 4);  // @110_4de7e0
  X0[0] = X5[0];  // @111_4de7e0
  X0[1] = X5[1];  // @112_4de7e0
  X0[2] = X5[2];  // @113_4de7e0
  X0[3] = X5[3];  // @114_4de7e0
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @115_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @116_4de7e0
  X2[0] = F2U(U2F(X2[0]) + U2F(X5[0]));  // @117_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @118_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X2[0], 4);  // @119_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X0[0], 4);  // @120_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @121_4de7e0
  X0[1] = 0;  // @122_4de7e0
  X0[2] = 0;  // @123_4de7e0
  X0[3] = 0;  // @124_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @125_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @126_4de7e0
  ecx = edx = 0;  // @127_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @128_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @129_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @130_4de7e0
  X0[1] = 0;  // @131_4de7e0
  X0[2] = 0;  // @132_4de7e0
  X0[3] = 0;  // @133_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @134_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @135_4de7e0
  ecx = edx = 0;  // @136_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @137_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @138_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @139_4de7e0
  X0[1] = 0;  // @140_4de7e0
  X0[2] = 0;  // @141_4de7e0
  X0[3] = 0;  // @142_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @143_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @144_4de7e0
  ecx = edx = 0;  // @145_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @146_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @147_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @148_4de7e0
  X0[1] = 0;  // @149_4de7e0
  X0[2] = 0;  // @150_4de7e0
  X0[3] = 0;  // @151_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @152_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @153_4de7e0
  ecx = edx = 0;  // @154_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @155_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @156_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @157_4de7e0
  X0[1] = 0;  // @158_4de7e0
  X0[2] = 0;  // @159_4de7e0
  X0[3] = 0;  // @160_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @161_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @162_4de7e0
  ecx = edx = 0;  // @163_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @164_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @165_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @166_4de7e0
  X0[1] = 0;  // @167_4de7e0
  X0[2] = 0;  // @168_4de7e0
  X0[3] = 0;  // @169_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @170_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @171_4de7e0
  ecx = edx = 0;  // @172_4de7e0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @173_4de7e0
  X2[1] = 0;  // @174_4de7e0
  X2[2] = 0;  // @175_4de7e0
  X2[3] = 0;  // @176_4de7e0
  X3[0] = 0;  // @177_4de7e0
  X3[1] = 0;  // @178_4de7e0
  X3[2] = 0;  // @179_4de7e0
  X3[3] = 0;  // @180_4de7e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 16) + 0), 4); v; });  // @181_4de7e0
  X1[1] = 0;  // @182_4de7e0
  X1[2] = 0;  // @183_4de7e0
  X1[3] = 0;  // @184_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @185_4de7e0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 16) + 0), 4); v; });  // @186_4de7e0
  X4[1] = 0;  // @187_4de7e0
  X4[2] = 0;  // @188_4de7e0
  X4[3] = 0;  // @189_4de7e0
  X3[0] = F2U((float)U2D(X0[0], X0[1]));  // @190_4de7e0
  X0[0] = X2[0];  // @191_4de7e0
  X0[1] = X2[1];  // @192_4de7e0
  X0[2] = X2[2];  // @193_4de7e0
  X0[3] = X2[3];  // @194_4de7e0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @195_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @196_4de7e0
  X4[0] = F2U(U2F(X4[0]) * U2F(X3[0]));  // @197_4de7e0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 20) + 0), 4); v; });  // @198_4de7e0
  X3[1] = 0;  // @199_4de7e0
  X3[2] = 0;  // @200_4de7e0
  X3[3] = 0;  // @201_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @202_4de7e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 20) + 0), 4); v; });  // @203_4de7e0
  X1[1] = 0;  // @204_4de7e0
  X1[2] = 0;  // @205_4de7e0
  X1[3] = 0;  // @206_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @207_4de7e0
  X4[0] = F2U(U2F(X4[0]) + U2F(X2[0]));  // @208_4de7e0
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @209_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X0[0], 4);  // @210_4de7e0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @211_4de7e0
  X2[1] = 0;  // @212_4de7e0
  X2[2] = 0;  // @213_4de7e0
  X2[3] = 0;  // @214_4de7e0
  X0[0] = X4[0];  // @215_4de7e0
  X0[1] = X4[1];  // @216_4de7e0
  X0[2] = X4[2];  // @217_4de7e0
  X0[3] = X4[3];  // @218_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @219_4de7e0
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @220_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @221_4de7e0
  X1[0] = X2[0];  // @222_4de7e0
  X1[1] = X2[1];  // @223_4de7e0
  X1[2] = X2[2];  // @224_4de7e0
  X1[3] = X2[3];  // @225_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @226_4de7e0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @227_4de7e0
  X3[0] = F2U(U2F(X3[0]) + U2F(X4[0]));  // @228_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @229_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @230_4de7e0
  X0[1] = 0;  // @231_4de7e0
  X0[2] = 0;  // @232_4de7e0
  X0[3] = 0;  // @233_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @234_4de7e0
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @235_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @236_4de7e0
  X2[0] = F2U(U2F(X2[0]) + U2F(X3[0]));  // @237_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X0[0], 4);  // @238_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X2[0], 4);  // @239_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @240_4de7e0
  X0[1] = 0;  // @241_4de7e0
  X0[2] = 0;  // @242_4de7e0
  X0[3] = 0;  // @243_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @244_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @245_4de7e0
  ecx = edx = 0;  // @246_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @247_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @248_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @249_4de7e0
  X0[1] = 0;  // @250_4de7e0
  X0[2] = 0;  // @251_4de7e0
  X0[3] = 0;  // @252_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @253_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @254_4de7e0
  ecx = edx = 0;  // @255_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @256_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @257_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @258_4de7e0
  X0[1] = 0;  // @259_4de7e0
  X0[2] = 0;  // @260_4de7e0
  X0[3] = 0;  // @261_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @262_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @263_4de7e0
  ecx = edx = 0;  // @264_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @265_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @266_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @267_4de7e0
  X0[1] = 0;  // @268_4de7e0
  X0[2] = 0;  // @269_4de7e0
  X0[3] = 0;  // @270_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @271_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @272_4de7e0
  ecx = edx = 0;  // @273_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @274_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @275_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @276_4de7e0
  X0[1] = 0;  // @277_4de7e0
  X0[2] = 0;  // @278_4de7e0
  X0[3] = 0;  // @279_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @280_4de7e0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @281_4de7e0
  ecx = edx = 0;  // @282_4de7e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @283_4de7e0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @284_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @285_4de7e0
  X0[1] = 0;  // @286_4de7e0
  X0[2] = 0;  // @287_4de7e0
  X0[3] = 0;  // @288_4de7e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @289_4de7e0
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @290_4de7e0
  ecx = edx = 0;  // @291_4de7e0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @292_4de7e0
  X2[1] = 0;  // @293_4de7e0
  X2[2] = 0;  // @294_4de7e0
  X2[3] = 0;  // @295_4de7e0
  X4[0] = 0;  // @296_4de7e0
  X4[1] = 0;  // @297_4de7e0
  X4[2] = 0;  // @298_4de7e0
  X4[3] = 0;  // @299_4de7e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @300_4de7e0
  X1[1] = 0;  // @301_4de7e0
  X1[2] = 0;  // @302_4de7e0
  X1[3] = 0;  // @303_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; })));  // @304_4de7e0
  X4[0] = F2U((float)U2D(X0[0], X0[1]));  // @305_4de7e0
  X0[0] = X2[0];  // @306_4de7e0
  X0[1] = X2[1];  // @307_4de7e0
  X0[2] = X2[2];  // @308_4de7e0
  X0[3] = X2[3];  // @309_4de7e0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @310_4de7e0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @311_4de7e0
  X5[1] = 0;  // @312_4de7e0
  X5[2] = 0;  // @313_4de7e0
  X5[3] = 0;  // @314_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @315_4de7e0
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; })));  // @316_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @317_4de7e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @318_4de7e0
  X1[1] = 0;  // @319_4de7e0
  X1[2] = 0;  // @320_4de7e0
  X1[3] = 0;  // @321_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; })));  // @322_4de7e0
  X4[0] = F2U(U2F(X4[0]) + U2F(X2[0]));  // @323_4de7e0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @324_4de7e0
  X0[0] = X5[0];  // @325_4de7e0
  X0[1] = X5[1];  // @326_4de7e0
  X0[2] = X5[2];  // @327_4de7e0
  X0[3] = X5[3];  // @328_4de7e0
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; })));  // @329_4de7e0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @330_4de7e0
  X2[1] = 0;  // @331_4de7e0
  X2[2] = 0;  // @332_4de7e0
  X2[3] = 0;  // @333_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @334_4de7e0
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @335_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @336_4de7e0
  X1[0] = X2[0];  // @337_4de7e0
  X1[1] = X2[1];  // @338_4de7e0
  X1[2] = X2[2];  // @339_4de7e0
  X1[3] = X2[3];  // @340_4de7e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @341_4de7e0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @342_4de7e0
  X5[0] = F2U(U2F(X5[0]) + U2F(X4[0]));  // @343_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X0[0], 4);  // @344_4de7e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @345_4de7e0
  X0[1] = 0;  // @346_4de7e0
  X0[2] = 0;  // @347_4de7e0
  X0[3] = 0;  // @348_4de7e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @349_4de7e0
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @350_4de7e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @351_4de7e0
  X2[0] = F2U(U2F(X2[0]) + U2F(X5[0]));  // @352_4de7e0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @353_4de7e0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X2[0], 4);  // @354_4de7e0
  return eax;  // @355_4de7e0
}
PCREG(4de7e0, lifted_4de7e0);

extern "C" u32 FASTCALL lifted_4df330(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_4df330
  eax = ecx;  // @1_4df330
  edi = edx;  // @2_4df330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @3_4df330
  PV[0] = (u32)(eax);  // @4_4df330
  edx = (u32)(esi + 24);  // @5_4df330
  ecx = (u32)(EBP - 44);  // @6_4df330
  eax = ext_459fc0_fastcall3(ecx, edx, PV[0]);  // @7_4df330
  ecx = edx = 0;  // @8_4df330
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @9_4df330
  edx = (u32)(esi + 12);  // @10_4df330
  ecx = (u32)(EBP - 56);  // @11_4df330
  eax = ext_459fc0_fastcall3(ecx, edx, PV[1]);  // @12_4df330
  ecx = edx = 0;  // @13_4df330
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @14_4df330
  edx = esi;  // @15_4df330
  ecx = (u32)(EBP - 68);  // @16_4df330
  eax = ext_459fc0_fastcall3(ecx, edx, PV[2]);  // @17_4df330
  ecx = edx = 0;  // @18_4df330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @19_4df330
  ecx = (u32)(EBP - 32);  // @20_4df330
  PV[3] = (u32)(edi);  // @21_4df330
  eax = ext_43e920_fastcall3(ecx, edx, PV[3]);  // @22_4df330
  ecx = edx = 0;  // @23_4df330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @24_4df330
  ecx = (u32)(EBP - 32);  // @25_4df330
  eax = ext_441a60_fastcall2(ecx, edx);  // @26_4df330
  ecx = edx = 0;  // @27_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @28_4df330
  X0[1] = 0;  // @29_4df330
  X0[2] = 0;  // @30_4df330
  X0[3] = 0;  // @31_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @32_4df330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @33_4df330
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @34_4df330
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X4[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X4[2] = X4[3] = 0;  // @35_4df330
  X0[0] = X0[0] & X4[0];  // @36_4df330
  X0[1] = X0[1] & X4[1];  // @37_4df330
  X0[2] = X0[2] & X4[2];  // @38_4df330
  X0[3] = X0[3] & X4[3];  // @39_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6820720) + 0), 4); v; });  // @40_4df330
  X1[1] = 0;  // @41_4df330
  X1[2] = 0;  // @42_4df330
  X1[3] = 0;  // @43_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X3[0] = F2U(a_); X3[1] = F2U(b_); X3[2] = X3[3] = 0; }  // @44_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @45_4df330
  X0[1] = 0;  // @46_4df330
  X0[2] = 0;  // @47_4df330
  X0[3] = 0;  // @48_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @49_4df330
  X3[0] = F2U(U2F(X3[0]) + U2F(X1[0]));  // @50_4df330
  X0[0] = X0[0] & X4[0];  // @51_4df330
  X0[1] = X0[1] & X4[1];  // @52_4df330
  X0[2] = X0[2] & X4[2];  // @53_4df330
  X0[3] = X0[3] & X4[3];  // @54_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X6[0] = F2U(a_); X6[1] = F2U(b_); X6[2] = X6[3] = 0; }  // @55_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @56_4df330
  X0[1] = 0;  // @57_4df330
  X0[2] = 0;  // @58_4df330
  X0[3] = 0;  // @59_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @60_4df330
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X3[0], 4);  // @61_4df330
  X6[0] = F2U(U2F(X6[0]) + U2F(X1[0]));  // @62_4df330
  X0[0] = X0[0] & X4[0];  // @63_4df330
  X0[1] = X0[1] & X4[1];  // @64_4df330
  X0[2] = X0[2] & X4[2];  // @65_4df330
  X0[3] = X0[3] & X4[3];  // @66_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X5[0] = F2U(a_); X5[1] = F2U(b_); X5[2] = X5[3] = 0; }  // @67_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @68_4df330
  X0[1] = 0;  // @69_4df330
  X0[2] = 0;  // @70_4df330
  X0[3] = 0;  // @71_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @72_4df330
  X5[0] = F2U(U2F(X5[0]) + U2F(X1[0]));  // @73_4df330
  X0[0] = X0[0] & X4[0];  // @74_4df330
  X0[1] = X0[1] & X4[1];  // @75_4df330
  X0[2] = X0[2] & X4[2];  // @76_4df330
  X0[3] = X0[3] & X4[3];  // @77_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @78_4df330
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @79_4df330
  __builtin_memcpy((void *)((u32)(EBP + 12) + 0), &X0[0], 4);  // @80_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @81_4df330
  X0[1] = 0;  // @82_4df330
  X0[2] = 0;  // @83_4df330
  X0[3] = 0;  // @84_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @85_4df330
  X0[0] = X0[0] & X4[0];  // @86_4df330
  X0[1] = X0[1] & X4[1];  // @87_4df330
  X0[2] = X0[2] & X4[2];  // @88_4df330
  X0[3] = X0[3] & X4[3];  // @89_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @90_4df330
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @91_4df330
  __builtin_memcpy((void *)((u32)(EBP + 16) + 0), &X0[0], 4);  // @92_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @93_4df330
  X0[1] = 0;  // @94_4df330
  X0[2] = 0;  // @95_4df330
  X0[3] = 0;  // @96_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @97_4df330
  X0[0] = X0[0] & X4[0];  // @98_4df330
  X0[1] = X0[1] & X4[1];  // @99_4df330
  X0[2] = X0[2] & X4[2];  // @100_4df330
  X0[3] = X0[3] & X4[3];  // @101_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @102_4df330
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @103_4df330
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @104_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @105_4df330
  X0[1] = 0;  // @106_4df330
  X0[2] = 0;  // @107_4df330
  X0[3] = 0;  // @108_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @109_4df330
  X0[0] = X0[0] & X4[0];  // @110_4df330
  X0[1] = X0[1] & X4[1];  // @111_4df330
  X0[2] = X0[2] & X4[2];  // @112_4df330
  X0[3] = X0[3] & X4[3];  // @113_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @114_4df330
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @115_4df330
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @116_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @117_4df330
  X0[1] = 0;  // @118_4df330
  X0[2] = 0;  // @119_4df330
  X0[3] = 0;  // @120_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @121_4df330
  X0[0] = X0[0] & X4[0];  // @122_4df330
  X0[1] = X0[1] & X4[1];  // @123_4df330
  X0[2] = X0[2] & X4[2];  // @124_4df330
  X0[3] = X0[3] & X4[3];  // @125_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @126_4df330
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @127_4df330
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @128_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @129_4df330
  X0[1] = 0;  // @130_4df330
  X0[2] = 0;  // @131_4df330
  X0[3] = 0;  // @132_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @133_4df330
  X0[0] = X0[0] & X4[0];  // @134_4df330
  X0[1] = X0[1] & X4[1];  // @135_4df330
  X0[2] = X0[2] & X4[2];  // @136_4df330
  X0[3] = X0[3] & X4[3];  // @137_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @138_4df330
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @139_4df330
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @140_4df330
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @141_4df330
  X7[1] = 0;  // @142_4df330
  X7[2] = 0;  // @143_4df330
  X7[3] = 0;  // @144_4df330
  ecx = 0;  // @145_4df330
  FL[3] = ecx;  // @146_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @147_4df330
  X1[1] = 0;  // @148_4df330
  X1[2] = 0;  // @149_4df330
  X1[3] = 0;  // @150_4df330
  { double a_ = (double)U2F(X7[0]), b_ = (double)U2F(X7[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @151_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @152_4df330
  X0[0] = X0[0] & X4[0];  // @153_4df330
  X0[1] = X0[1] & X4[1];  // @154_4df330
  X0[2] = X0[2] & X4[2];  // @155_4df330
  X0[3] = X0[3] & X4[3];  // @156_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @157_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @158_4df330
  X0[0] = X6[0];  // @159_4df330
  X0[1] = X6[1];  // @160_4df330
  X0[2] = X6[2];  // @161_4df330
  X0[3] = X6[3];  // @162_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @163_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @164_4df330
  X0[0] = X5[0];  // @165_4df330
  X0[1] = X5[1];  // @166_4df330
  X0[2] = X5[2];  // @167_4df330
  X0[3] = X5[3];  // @168_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @169_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @170_4df330
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @171_4df330
  FL[2] = (ecx & ecx);  // @172_4df330
  if (FL[2] != 0) goto L4df4ad;  // @173_4df330
  L4df4a3:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @175_4df330
  FL[3] = (eax & 0xff);  // @176_4df330
  return eax;  // @177_4df330
  L4df4ad:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @179_4df330
  X3[1] = 0;  // @180_4df330
  X3[2] = 0;  // @181_4df330
  X3[3] = 0;  // @182_4df330
  X0[0] = X7[0];  // @183_4df330
  X0[1] = X7[1];  // @184_4df330
  X0[2] = X7[2];  // @185_4df330
  X0[3] = X7[3];  // @186_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })));  // @187_4df330
  X1[0] = X3[0];  // @188_4df330
  X1[1] = X3[1];  // @189_4df330
  X1[2] = X3[2];  // @190_4df330
  X1[3] = X3[3];  // @191_4df330
  edx = 0;  // @192_4df330
  FL[3] = edx;  // @193_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @194_4df330
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @195_4df330
  X7[1] = 0;  // @196_4df330
  X7[2] = 0;  // @197_4df330
  X7[3] = 0;  // @198_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @199_4df330
  X0[0] = X7[0];  // @200_4df330
  X0[1] = X7[1];  // @201_4df330
  X0[2] = X7[2];  // @202_4df330
  X0[3] = X7[3];  // @203_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @204_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @205_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @206_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @207_4df330
  X1[1] = 0;  // @208_4df330
  X1[2] = 0;  // @209_4df330
  X1[3] = 0;  // @210_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @211_4df330
  X0[0] = X0[0] & X4[0];  // @212_4df330
  X0[1] = X0[1] & X4[1];  // @213_4df330
  X0[2] = X0[2] & X4[2];  // @214_4df330
  X0[3] = X0[3] & X4[3];  // @215_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @216_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @217_4df330
  X0[1] = 0;  // @218_4df330
  X0[2] = 0;  // @219_4df330
  X0[3] = 0;  // @220_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @221_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @222_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @223_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @224_4df330
  X0[1] = 0;  // @225_4df330
  X0[2] = 0;  // @226_4df330
  X0[3] = 0;  // @227_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @228_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @229_4df330
  edx = (edx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @230_4df330
  edx = (edx & ecx);  // @231_4df330
  FL[3] = edx;  // @232_4df330
  if (FL[3] == 0) goto L4df4a3;  // @233_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @234_4df330
  X1[1] = 0;  // @235_4df330
  X1[2] = 0;  // @236_4df330
  X1[3] = 0;  // @237_4df330
  ecx = 0;  // @238_4df330
  FL[3] = ecx;  // @239_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @240_4df330
  { double a_ = (double)U2F(X3[0]), b_ = (double)U2F(X3[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @241_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @242_4df330
  X0[0] = X0[0] & X4[0];  // @243_4df330
  X0[1] = X0[1] & X4[1];  // @244_4df330
  X0[2] = X0[2] & X4[2];  // @245_4df330
  X0[3] = X0[3] & X4[3];  // @246_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @247_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @248_4df330
  X0[1] = 0;  // @249_4df330
  X0[2] = 0;  // @250_4df330
  X0[3] = 0;  // @251_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @252_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @253_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @254_4df330
  X0[1] = 0;  // @255_4df330
  X0[2] = 0;  // @256_4df330
  X0[3] = 0;  // @257_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @258_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @259_4df330
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @260_4df330
  ecx = (ecx & edx);  // @261_4df330
  FL[3] = ecx;  // @262_4df330
  if (FL[3] == 0) goto L4df4a3;  // @263_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @264_4df330
  X1[1] = 0;  // @265_4df330
  X1[2] = 0;  // @266_4df330
  X1[3] = 0;  // @267_4df330
  edx = 0;  // @268_4df330
  FL[3] = edx;  // @269_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @270_4df330
  { double a_ = (double)U2F(X7[0]), b_ = (double)U2F(X7[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @271_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @272_4df330
  X0[0] = X0[0] & X4[0];  // @273_4df330
  X0[1] = X0[1] & X4[1];  // @274_4df330
  X0[2] = X0[2] & X4[2];  // @275_4df330
  X0[3] = X0[3] & X4[3];  // @276_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @277_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @278_4df330
  X0[1] = 0;  // @279_4df330
  X0[2] = 0;  // @280_4df330
  X0[3] = 0;  // @281_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @282_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @283_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @284_4df330
  X0[1] = 0;  // @285_4df330
  X0[2] = 0;  // @286_4df330
  X0[3] = 0;  // @287_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @288_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @289_4df330
  edx = (edx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @290_4df330
  edx = (edx & ecx);  // @291_4df330
  FL[3] = edx;  // @292_4df330
  if (FL[3] == 0) goto L4df4a3;  // @293_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @294_4df330
  X0[1] = 0;  // @295_4df330
  X0[2] = 0;  // @296_4df330
  X0[3] = 0;  // @297_4df330
  X1[0] = X3[0];  // @298_4df330
  X1[1] = X3[1];  // @299_4df330
  X1[2] = X3[2];  // @300_4df330
  X1[3] = X3[3];  // @301_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; })));  // @302_4df330
  ecx = 0;  // @303_4df330
  FL[3] = ecx;  // @304_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; })));  // @305_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @306_4df330
  X0[0] = X7[0];  // @307_4df330
  X0[1] = X7[1];  // @308_4df330
  X0[2] = X7[2];  // @309_4df330
  X0[3] = X7[3];  // @310_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; })));  // @311_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @312_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @313_4df330
  X1[0] = X6[0];  // @314_4df330
  X1[1] = X6[1];  // @315_4df330
  X1[2] = X6[2];  // @316_4df330
  X1[3] = X6[3];  // @317_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @318_4df330
  X0[0] = X0[0] & X4[0];  // @319_4df330
  X0[1] = X0[1] & X4[1];  // @320_4df330
  X0[2] = X0[2] & X4[2];  // @321_4df330
  X0[3] = X0[3] & X4[3];  // @322_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @323_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @324_4df330
  X0[1] = 0;  // @325_4df330
  X0[2] = 0;  // @326_4df330
  X0[3] = 0;  // @327_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @328_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @329_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @330_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @331_4df330
  X0[1] = 0;  // @332_4df330
  X0[2] = 0;  // @333_4df330
  X0[3] = 0;  // @334_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @335_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @336_4df330
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @337_4df330
  ecx = (ecx & edx);  // @338_4df330
  FL[3] = ecx;  // @339_4df330
  if (FL[3] == 0) goto L4df4a3;  // @340_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @341_4df330
  X0[1] = 0;  // @342_4df330
  X0[2] = 0;  // @343_4df330
  X0[3] = 0;  // @344_4df330
  X1[0] = X3[0];  // @345_4df330
  X1[1] = X3[1];  // @346_4df330
  X1[2] = X3[2];  // @347_4df330
  X1[3] = X3[3];  // @348_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; })));  // @349_4df330
  edx = 0;  // @350_4df330
  FL[3] = edx;  // @351_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; })));  // @352_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @353_4df330
  X0[0] = X7[0];  // @354_4df330
  X0[1] = X7[1];  // @355_4df330
  X0[2] = X7[2];  // @356_4df330
  X0[3] = X7[3];  // @357_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; })));  // @358_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @359_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @360_4df330
  X1[0] = X5[0];  // @361_4df330
  X1[1] = X5[1];  // @362_4df330
  X1[2] = X5[2];  // @363_4df330
  X1[3] = X5[3];  // @364_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @365_4df330
  X0[0] = X0[0] & X4[0];  // @366_4df330
  X0[1] = X0[1] & X4[1];  // @367_4df330
  X0[2] = X0[2] & X4[2];  // @368_4df330
  X0[3] = X0[3] & X4[3];  // @369_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @370_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @371_4df330
  X0[1] = 0;  // @372_4df330
  X0[2] = 0;  // @373_4df330
  X0[3] = 0;  // @374_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @375_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @376_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @377_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @378_4df330
  X0[1] = 0;  // @379_4df330
  X0[2] = 0;  // @380_4df330
  X0[3] = 0;  // @381_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @382_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @383_4df330
  edx = (edx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @384_4df330
  edx = (edx & ecx);  // @385_4df330
  FL[3] = edx;  // @386_4df330
  if (FL[3] == 0) goto L4df4a3;  // @387_4df330
  X1[0] = X7[0];  // @388_4df330
  X1[1] = X7[1];  // @389_4df330
  X1[2] = X7[2];  // @390_4df330
  X1[3] = X7[3];  // @391_4df330
  X0[0] = X3[0];  // @392_4df330
  X0[1] = X3[1];  // @393_4df330
  X0[2] = X3[2];  // @394_4df330
  X0[3] = X3[3];  // @395_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @396_4df330
  ecx = 0;  // @397_4df330
  FL[3] = ecx;  // @398_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @399_4df330
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @400_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @401_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @402_4df330
  X1[1] = 0;  // @403_4df330
  X1[2] = 0;  // @404_4df330
  X1[3] = 0;  // @405_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @406_4df330
  X0[0] = X0[0] & X4[0];  // @407_4df330
  X0[1] = X0[1] & X4[1];  // @408_4df330
  X0[2] = X0[2] & X4[2];  // @409_4df330
  X0[3] = X0[3] & X4[3];  // @410_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @411_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @412_4df330
  X0[1] = 0;  // @413_4df330
  X0[2] = 0;  // @414_4df330
  X0[3] = 0;  // @415_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @416_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @417_4df330
  X0[0] = X5[0];  // @418_4df330
  X0[1] = X5[1];  // @419_4df330
  X0[2] = X5[2];  // @420_4df330
  X0[3] = X5[3];  // @421_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @422_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @423_4df330
  X0[0] = X6[0];  // @424_4df330
  X0[1] = X6[1];  // @425_4df330
  X0[2] = X6[2];  // @426_4df330
  X0[3] = X6[3];  // @427_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @428_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @429_4df330
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @430_4df330
  ecx = (ecx & edx);  // @431_4df330
  FL[3] = ecx;  // @432_4df330
  if (FL[3] == 0) goto L4df4a3;  // @433_4df330
  X1[0] = X7[0];  // @434_4df330
  X1[1] = X7[1];  // @435_4df330
  X1[2] = X7[2];  // @436_4df330
  X1[3] = X7[3];  // @437_4df330
  X0[0] = X3[0];  // @438_4df330
  X0[1] = X3[1];  // @439_4df330
  X0[2] = X3[2];  // @440_4df330
  X0[3] = X3[3];  // @441_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; })));  // @442_4df330
  edx = 0;  // @443_4df330
  FL[3] = edx;  // @444_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; })));  // @445_4df330
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @446_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @447_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @448_4df330
  X1[1] = 0;  // @449_4df330
  X1[2] = 0;  // @450_4df330
  X1[3] = 0;  // @451_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @452_4df330
  X0[0] = X0[0] & X4[0];  // @453_4df330
  X0[1] = X0[1] & X4[1];  // @454_4df330
  X0[2] = X0[2] & X4[2];  // @455_4df330
  X0[3] = X0[3] & X4[3];  // @456_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @457_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @458_4df330
  X0[1] = 0;  // @459_4df330
  X0[2] = 0;  // @460_4df330
  X0[3] = 0;  // @461_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @462_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @463_4df330
  X0[0] = X5[0];  // @464_4df330
  X0[1] = X5[1];  // @465_4df330
  X0[2] = X5[2];  // @466_4df330
  X0[3] = X5[3];  // @467_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @468_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @469_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @470_4df330
  X0[1] = 0;  // @471_4df330
  X0[2] = 0;  // @472_4df330
  X0[3] = 0;  // @473_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @474_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @475_4df330
  edx = (edx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @476_4df330
  edx = (edx & ecx);  // @477_4df330
  FL[3] = edx;  // @478_4df330
  if (FL[3] == 0) goto L4df4a3;  // @479_4df330
  X1[0] = X7[0];  // @480_4df330
  X1[1] = X7[1];  // @481_4df330
  X1[2] = X7[2];  // @482_4df330
  X1[3] = X7[3];  // @483_4df330
  X0[0] = X3[0];  // @484_4df330
  X0[1] = X3[1];  // @485_4df330
  X0[2] = X3[2];  // @486_4df330
  X0[3] = X3[3];  // @487_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; })));  // @488_4df330
  ecx = 0;  // @489_4df330
  FL[3] = ecx;  // @490_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; })));  // @491_4df330
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @492_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @493_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @494_4df330
  X1[1] = 0;  // @495_4df330
  X1[2] = 0;  // @496_4df330
  X1[3] = 0;  // @497_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @498_4df330
  X0[0] = X0[0] & X4[0];  // @499_4df330
  X0[1] = X0[1] & X4[1];  // @500_4df330
  X0[2] = X0[2] & X4[2];  // @501_4df330
  X0[3] = X0[3] & X4[3];  // @502_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @503_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @504_4df330
  X0[1] = 0;  // @505_4df330
  X0[2] = 0;  // @506_4df330
  X0[3] = 0;  // @507_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @508_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @509_4df330
  X0[0] = X6[0];  // @510_4df330
  X0[1] = X6[1];  // @511_4df330
  X0[2] = X6[2];  // @512_4df330
  X0[3] = X6[3];  // @513_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @514_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @515_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @516_4df330
  X0[1] = 0;  // @517_4df330
  X0[2] = 0;  // @518_4df330
  X0[3] = 0;  // @519_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @520_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @521_4df330
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @522_4df330
  ecx = (ecx & edx);  // @523_4df330
  FL[3] = ecx;  // @524_4df330
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @525_4df330
  if (FL[3] == 0) goto L4df4a3;  // @526_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @527_4df330
  X1[1] = 0;  // @528_4df330
  X1[2] = 0;  // @529_4df330
  X1[3] = 0;  // @530_4df330
  X0[0] = X7[0];  // @531_4df330
  X0[1] = X7[1];  // @532_4df330
  X0[2] = X7[2];  // @533_4df330
  X0[3] = X7[3];  // @534_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })));  // @535_4df330
  ecx = 0;  // @536_4df330
  FL[3] = ecx;  // @537_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @538_4df330
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @539_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @540_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @541_4df330
  X1[1] = 0;  // @542_4df330
  X1[2] = 0;  // @543_4df330
  X1[3] = 0;  // @544_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @545_4df330
  X0[0] = X0[0] & X4[0];  // @546_4df330
  X0[1] = X0[1] & X4[1];  // @547_4df330
  X0[2] = X0[2] & X4[2];  // @548_4df330
  X0[3] = X0[3] & X4[3];  // @549_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @550_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @551_4df330
  X0[1] = 0;  // @552_4df330
  X0[2] = 0;  // @553_4df330
  X0[3] = 0;  // @554_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @555_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @556_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @557_4df330
  X0[1] = 0;  // @558_4df330
  X0[2] = 0;  // @559_4df330
  X0[3] = 0;  // @560_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @561_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @562_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @563_4df330
  X0[1] = 0;  // @564_4df330
  X0[2] = 0;  // @565_4df330
  X0[3] = 0;  // @566_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @567_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @568_4df330
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @569_4df330
  ecx = (ecx & ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @570_4df330
  FL[3] = ecx;  // @571_4df330
  if (FL[3] == 0) goto L4df4a3;  // @572_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @573_4df330
  X1[1] = 0;  // @574_4df330
  X1[2] = 0;  // @575_4df330
  X1[3] = 0;  // @576_4df330
  X0[0] = X7[0];  // @577_4df330
  X0[1] = X7[1];  // @578_4df330
  X0[2] = X7[2];  // @579_4df330
  X0[3] = X7[3];  // @580_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; })));  // @581_4df330
  edx = 0;  // @582_4df330
  FL[3] = edx;  // @583_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; })));  // @584_4df330
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @585_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @586_4df330
  X1[0] = X6[0];  // @587_4df330
  X1[1] = X6[1];  // @588_4df330
  X1[2] = X6[2];  // @589_4df330
  X1[3] = X6[3];  // @590_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @591_4df330
  X0[0] = X0[0] & X4[0];  // @592_4df330
  X0[1] = X0[1] & X4[1];  // @593_4df330
  X0[2] = X0[2] & X4[2];  // @594_4df330
  X0[3] = X0[3] & X4[3];  // @595_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @596_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @597_4df330
  X0[1] = 0;  // @598_4df330
  X0[2] = 0;  // @599_4df330
  X0[3] = 0;  // @600_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @601_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @602_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @603_4df330
  X0[1] = 0;  // @604_4df330
  X0[2] = 0;  // @605_4df330
  X0[3] = 0;  // @606_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @607_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @608_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @609_4df330
  X0[1] = 0;  // @610_4df330
  X0[2] = 0;  // @611_4df330
  X0[3] = 0;  // @612_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @613_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @614_4df330
  edx = (edx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @615_4df330
  edx = (edx & ecx);  // @616_4df330
  FL[3] = edx;  // @617_4df330
  if (FL[3] == 0) goto L4df4a3;  // @618_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @619_4df330
  X0[1] = 0;  // @620_4df330
  X0[2] = 0;  // @621_4df330
  X0[3] = 0;  // @622_4df330
  X1[0] = X5[0];  // @623_4df330
  X1[1] = X5[1];  // @624_4df330
  X1[2] = X5[2];  // @625_4df330
  X1[3] = X5[3];  // @626_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; })));  // @627_4df330
  ecx = 0;  // @628_4df330
  FL[3] = ecx;  // @629_4df330
  X7[0] = F2U(U2F(X7[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; })));  // @630_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @631_4df330
  X0[0] = F2U(U2F(X0[0]) - U2F(X7[0]));  // @632_4df330
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @633_4df330
  X0[0] = X0[0] & X4[0];  // @634_4df330
  X0[1] = X0[1] & X4[1];  // @635_4df330
  X0[2] = X0[2] & X4[2];  // @636_4df330
  X0[3] = X0[3] & X4[3];  // @637_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @638_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @639_4df330
  X0[1] = 0;  // @640_4df330
  X0[2] = 0;  // @641_4df330
  X0[3] = 0;  // @642_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @643_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @644_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @645_4df330
  X0[1] = 0;  // @646_4df330
  X0[2] = 0;  // @647_4df330
  X0[3] = 0;  // @648_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @649_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @650_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @651_4df330
  X0[1] = 0;  // @652_4df330
  X0[2] = 0;  // @653_4df330
  X0[3] = 0;  // @654_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @655_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @656_4df330
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @657_4df330
  ecx = (ecx & edx);  // @658_4df330
  FL[3] = ecx;  // @659_4df330
  if (FL[3] == 0) goto L4df4a3;  // @660_4df330
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @661_4df330
  X7[1] = 0;  // @662_4df330
  X7[2] = 0;  // @663_4df330
  X7[3] = 0;  // @664_4df330
  X1[0] = X3[0];  // @665_4df330
  X1[1] = X3[1];  // @666_4df330
  X1[2] = X3[2];  // @667_4df330
  X1[3] = X3[3];  // @668_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })));  // @669_4df330
  X0[0] = X7[0];  // @670_4df330
  X0[1] = X7[1];  // @671_4df330
  X0[2] = X7[2];  // @672_4df330
  X0[3] = X7[3];  // @673_4df330
  edx = 0;  // @674_4df330
  FL[3] = edx;  // @675_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @676_4df330
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @677_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @678_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @679_4df330
  X1[1] = 0;  // @680_4df330
  X1[2] = 0;  // @681_4df330
  X1[3] = 0;  // @682_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @683_4df330
  X0[0] = X0[0] & X4[0];  // @684_4df330
  X0[1] = X0[1] & X4[1];  // @685_4df330
  X0[2] = X0[2] & X4[2];  // @686_4df330
  X0[3] = X0[3] & X4[3];  // @687_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @688_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @689_4df330
  X0[1] = 0;  // @690_4df330
  X0[2] = 0;  // @691_4df330
  X0[3] = 0;  // @692_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @693_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @694_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @695_4df330
  X0[1] = 0;  // @696_4df330
  X0[2] = 0;  // @697_4df330
  X0[3] = 0;  // @698_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @699_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @700_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @701_4df330
  X0[1] = 0;  // @702_4df330
  X0[2] = 0;  // @703_4df330
  X0[3] = 0;  // @704_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @705_4df330
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @706_4df330
  edx = (edx & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(X2[0]))))) ? 1 : 0)) & 0xff);  // @707_4df330
  edx = (edx & ecx);  // @708_4df330
  FL[3] = edx;  // @709_4df330
  if (FL[3] == 0) goto L4df4a3;  // @710_4df330
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @711_4df330
  X2[1] = 0;  // @712_4df330
  X2[2] = 0;  // @713_4df330
  X2[3] = 0;  // @714_4df330
  X1[0] = X3[0];  // @715_4df330
  X1[1] = X3[1];  // @716_4df330
  X1[2] = X3[2];  // @717_4df330
  X1[3] = X3[3];  // @718_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; })));  // @719_4df330
  X0[0] = X7[0];  // @720_4df330
  X0[1] = X7[1];  // @721_4df330
  X0[2] = X7[2];  // @722_4df330
  X0[3] = X7[3];  // @723_4df330
  ecx = 0;  // @724_4df330
  FL[3] = ecx;  // @725_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; })));  // @726_4df330
  X6[0] = F2U(U2F(X6[0]) * U2F(X2[0]));  // @727_4df330
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @728_4df330
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @729_4df330
  X0[0] = X0[0] & X4[0];  // @730_4df330
  X0[1] = X0[1] & X4[1];  // @731_4df330
  X0[2] = X0[2] & X4[2];  // @732_4df330
  X0[3] = X0[3] & X4[3];  // @733_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @734_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @735_4df330
  X0[1] = 0;  // @736_4df330
  X0[2] = 0;  // @737_4df330
  X0[3] = 0;  // @738_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @739_4df330
  X6[0] = F2U(U2F(X6[0]) + U2F(X0[0]));  // @740_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @741_4df330
  X0[1] = 0;  // @742_4df330
  X0[2] = 0;  // @743_4df330
  X0[3] = 0;  // @744_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @745_4df330
  X6[0] = F2U(U2F(X6[0]) + U2F(X0[0]));  // @746_4df330
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @747_4df330
  X0[1] = 0;  // @748_4df330
  X0[2] = 0;  // @749_4df330
  X0[3] = 0;  // @750_4df330
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @751_4df330
  X6[0] = F2U(U2F(X6[0]) + U2F(X0[0]));  // @752_4df330
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X6[0]) >= U2F(X1[0]))))) ? 1 : 0)) & 0xff);  // @753_4df330
  ecx = (ecx & edx);  // @754_4df330
  FL[3] = ecx;  // @755_4df330
  if (FL[3] == 0) goto L4df4a3;  // @756_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @757_4df330
  X1[1] = 0;  // @758_4df330
  X1[2] = 0;  // @759_4df330
  X1[3] = 0;  // @760_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @761_4df330
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; })));  // @762_4df330
  X7[0] = F2U(U2F(X7[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; })));  // @763_4df330
  X5[0] = F2U(U2F(X5[0]) * U2F(X2[0]));  // @764_4df330
  X3[0] = F2U(U2F(X3[0]) - U2F(X7[0]));  // @765_4df330
  X5[0] = F2U(U2F(X5[0]) + U2F(X1[0]));  // @766_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @767_4df330
  X1[1] = 0;  // @768_4df330
  X1[2] = 0;  // @769_4df330
  X1[3] = 0;  // @770_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @771_4df330
  { double a_ = (double)U2F(X3[0]), b_ = (double)U2F(X3[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @772_4df330
  X5[0] = F2U(U2F(X5[0]) + U2F(X1[0]));  // @773_4df330
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @774_4df330
  X1[1] = 0;  // @775_4df330
  X1[2] = 0;  // @776_4df330
  X1[3] = 0;  // @777_4df330
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @778_4df330
  X0[0] = X0[0] & X4[0];  // @779_4df330
  X0[1] = X0[1] & X4[1];  // @780_4df330
  X0[2] = X0[2] & X4[2];  // @781_4df330
  X0[3] = X0[3] & X4[3];  // @782_4df330
  eax = 0;  // @783_4df330
  FL[3] = eax;  // @784_4df330
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @785_4df330
  X5[0] = F2U(U2F(X5[0]) + U2F(X1[0]));  // @786_4df330
  eax = (eax & 0xffffff00u) | (((((!(!(U2F(X5[0]) >= U2F(X0[0]))))) ? 1 : 0)) & 0xff);  // @787_4df330
  FL[2] = (ecx & eax);  // @788_4df330
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @789_4df330
  return eax;  // @790_4df330
}
PCREG(4df330, lifted_4df330);



extern "C" u32 THISCALL lifted_506ee0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_506ee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @1_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_506ee0
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @3_506ee0
  ecx = edx = 0;  // @4_506ee0
  edi = eax;  // @5_506ee0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @6_506ee0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @7_506ee0
  if (FL[2] == 0) goto L506f48;  // @8_506ee0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @9_506ee0
  if (FL[0] == FL[1]) goto L506f48;  // @10_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @13_506ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(260));  // @14_506ee0
  ecx = edx = 0;  // @15_506ee0
  PV[0] = (u32)(eax);  // @16_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_506ee0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @18_506ee0
  ecx = edx = 0;  // @19_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_506ee0
  FL[2] = (eax & eax);  // @21_506ee0
  if (FL[2] == 0) goto L506f47;  // @22_506ee0
  eax = ((u32(STDCALL *)(void))(eax))();  // @23_506ee0
  ecx = edx = 0;  // @24_506ee0
  goto L506f48;  // @25_506ee0
  L506f47:;
  __builtin_trap();  // @27_506ee0
  L506f48:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @29_506ee0
  X0[1] = 0;  // @30_506ee0
  X0[2] = 0;  // @31_506ee0
  X0[3] = 0;  // @32_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @33_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @34_506ee0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @35_506ee0
  ecx = edx = 0;  // @36_506ee0
  edi = eax;  // @37_506ee0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @38_506ee0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @39_506ee0
  if (FL[2] == 0) goto L506fa1;  // @40_506ee0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @41_506ee0
  if (FL[0] == FL[1]) goto L506fa1;  // @42_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @43_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @45_506ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(260));  // @46_506ee0
  ecx = edx = 0;  // @47_506ee0
  PV[1] = (u32)(eax);  // @48_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @49_506ee0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6932144), (u32)(6932792));  // @50_506ee0
  ecx = edx = 0;  // @51_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @52_506ee0
  FL[2] = (eax & eax);  // @53_506ee0
  if (FL[2] == 0) goto L506fa0;  // @54_506ee0
  eax = ((u32(STDCALL *)(void))(eax))();  // @55_506ee0
  ecx = edx = 0;  // @56_506ee0
  goto L506fa1;  // @57_506ee0
  L506fa0:;
  __builtin_trap();  // @59_506ee0
  L506fa1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @61_506ee0
  X0[1] = 0;  // @62_506ee0
  X0[2] = 0;  // @63_506ee0
  X0[3] = 0;  // @64_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @65_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @66_506ee0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @67_506ee0
  ecx = edx = 0;  // @68_506ee0
  edi = eax;  // @69_506ee0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @70_506ee0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @71_506ee0
  if (FL[2] == 0) goto L506ffa;  // @72_506ee0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @73_506ee0
  if (FL[0] == FL[1]) goto L506ffa;  // @74_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @75_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @77_506ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(260));  // @78_506ee0
  ecx = edx = 0;  // @79_506ee0
  PV[2] = (u32)(eax);  // @80_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @81_506ee0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6932144), (u32)(6932792));  // @82_506ee0
  ecx = edx = 0;  // @83_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @84_506ee0
  FL[2] = (eax & eax);  // @85_506ee0
  if (FL[2] == 0) goto L506ff9;  // @86_506ee0
  eax = ((u32(STDCALL *)(void))(eax))();  // @87_506ee0
  ecx = edx = 0;  // @88_506ee0
  goto L506ffa;  // @89_506ee0
  L506ff9:;
  __builtin_trap();  // @91_506ee0
  L506ffa:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @93_506ee0
  X0[1] = 0;  // @94_506ee0
  X0[2] = 0;  // @95_506ee0
  X0[3] = 0;  // @96_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @97_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @98_506ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @99_506ee0
  X0[1] = 0;  // @100_506ee0
  X0[2] = 0;  // @101_506ee0
  X0[3] = 0;  // @102_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @103_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @104_506ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @105_506ee0
  X0[1] = 0;  // @106_506ee0
  X0[2] = 0;  // @107_506ee0
  X0[3] = 0;  // @108_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @109_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1488), sizeof v); (u32)v; });  // @111_506ee0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @112_506ee0
  ecx = edx = 0;  // @113_506ee0
  edi = (u32)(1);  // @114_506ee0
  FL[2] = (eax & eax);  // @115_506ee0
  if (FL[2] == 0) goto L5070d4;  // @116_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @117_506ee0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @118_506ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @119_506ee0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @120_506ee0
  X0[2] = 0;  // @121_506ee0
  X0[3] = 0;  // @122_506ee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @123_506ee0
  ecx = (u32)(EBP - 16);  // @124_506ee0
  PV[3] = (u32)(ecx);  // @125_506ee0
  ecx = eax;  // @126_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @127_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 4), &X0[1], 4);  // @128_506ee0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 536)))(ecx, PV[3], (u32)(1092616192), (u32)(1092616192), (u32)(1065353216));  // @129_506ee0
  ecx = edx = 0;  // @130_506ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @131_506ee0
  X0[1] = 0;  // @132_506ee0
  X0[2] = 0;  // @133_506ee0
  X0[3] = 0;  // @134_506ee0
  eax = (u32)(EBP - 16);  // @135_506ee0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @136_506ee0
  PV[4] = (u32)(eax);  // @137_506ee0
  edx = (u32)(EBP - 40);  // @138_506ee0
  ecx = (u32)(EBP - 52);  // @139_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @140_506ee0
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @141_506ee0
  ecx = edx = 0;  // @142_506ee0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @143_506ee0
  X1[1] = 0;  // @144_506ee0
  X1[2] = 0;  // @145_506ee0
  X1[3] = 0;  // @146_506ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @147_506ee0
  X0[1] = 0;  // @148_506ee0
  X0[2] = 0;  // @149_506ee0
  X0[3] = 0;  // @150_506ee0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @151_506ee0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @152_506ee0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })));  // @153_506ee0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @154_506ee0
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; })))) && !(!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; }))))))) goto L5070d2;  // @155_506ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @156_506ee0
  X0[1] = 0;  // @157_506ee0
  X0[2] = 0;  // @158_506ee0
  X0[3] = 0;  // @159_506ee0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @160_506ee0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @161_506ee0
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @162_506ee0
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @163_506ee0
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @164_506ee0
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @165_506ee0
  if (((!(U2D(X0[0], X0[1]) >= U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896992) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896992) + 4), 4); v; })))) || (!((U2D(X0[0], X0[1]) < U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896992) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896992) + 4), 4); v; }))) || (U2D(X0[0], X0[1]) > U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896992) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896992) + 4), 4); v; }))))))) goto L5070d4;  // @166_506ee0
  L5070d2:;
  edi = 0;  // @168_506ee0
  FL[3] = edi;  // @169_506ee0
  L5070d4:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @171_506ee0
  X0[1] = 0;  // @172_506ee0
  X0[2] = 0;  // @173_506ee0
  X0[3] = 0;  // @174_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @175_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @176_506ee0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @177_506ee0
  ecx = edx = 0;  // @178_506ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @179_506ee0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) & 0xff);  // @180_506ee0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @181_506ee0
  if (FL[2] == 0) goto L507132;  // @182_506ee0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @183_506ee0
  if (FL[0] == FL[1]) goto L507132;  // @184_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @185_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @186_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @187_506ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(260));  // @188_506ee0
  ecx = edx = 0;  // @189_506ee0
  PV[5] = (u32)(eax);  // @190_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @191_506ee0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6932144), (u32)(6932792));  // @192_506ee0
  ecx = edx = 0;  // @193_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @194_506ee0
  FL[2] = (eax & eax);  // @195_506ee0
  if (FL[2] == 0) goto L50712e;  // @196_506ee0
  eax = ((u32(STDCALL *)(void))(eax))();  // @197_506ee0
  ecx = edx = 0;  // @198_506ee0
  goto L50712f;  // @199_506ee0
  L50712e:;
  __builtin_trap();  // @201_506ee0
  L50712f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @203_506ee0
  L507132:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @205_506ee0
  X0[1] = 0;  // @206_506ee0
  X0[2] = 0;  // @207_506ee0
  X0[3] = 0;  // @208_506ee0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @209_506ee0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @210_506ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @211_506ee0
  X0[1] = 0;  // @212_506ee0
  X0[2] = 0;  // @213_506ee0
  X0[3] = 0;  // @214_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @215_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @216_506ee0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @217_506ee0
  ecx = edx = 0;  // @218_506ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @219_506ee0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) & 0xff);  // @220_506ee0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @221_506ee0
  if (FL[2] == 0) goto L50719d;  // @222_506ee0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @223_506ee0
  if (FL[0] == FL[1]) goto L50719d;  // @224_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @225_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @226_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @227_506ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(260));  // @228_506ee0
  ecx = edx = 0;  // @229_506ee0
  PV[6] = (u32)(eax);  // @230_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @231_506ee0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[6], (u32)(6932144), (u32)(6932792));  // @232_506ee0
  ecx = edx = 0;  // @233_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @234_506ee0
  FL[2] = (eax & eax);  // @235_506ee0
  if (FL[2] == 0) goto L507199;  // @236_506ee0
  eax = ((u32(STDCALL *)(void))(eax))();  // @237_506ee0
  ecx = edx = 0;  // @238_506ee0
  goto L50719a;  // @239_506ee0
  L507199:;
  __builtin_trap();  // @241_506ee0
  L50719a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @243_506ee0
  L50719d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @245_506ee0
  X0[1] = 0;  // @246_506ee0
  X0[2] = 0;  // @247_506ee0
  X0[3] = 0;  // @248_506ee0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @249_506ee0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @250_506ee0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @251_506ee0
  X0[1] = 0;  // @252_506ee0
  X0[2] = 0;  // @253_506ee0
  X0[3] = 0;  // @254_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @255_506ee0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @256_506ee0
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @257_506ee0
  ecx = edx = 0;  // @258_506ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @259_506ee0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; })) & 0xff);  // @260_506ee0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @261_506ee0
  if (FL[2] == 0) goto L507208;  // @262_506ee0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @263_506ee0
  if (FL[0] == FL[1]) goto L507208;  // @264_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @265_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @266_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @267_506ee0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6932704), (u32)(260));  // @268_506ee0
  ecx = edx = 0;  // @269_506ee0
  PV[7] = (u32)(eax);  // @270_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @271_506ee0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[7], (u32)(6932144), (u32)(6932792));  // @272_506ee0
  ecx = edx = 0;  // @273_506ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @274_506ee0
  FL[2] = (eax & eax);  // @275_506ee0
  if (FL[2] == 0) goto L507204;  // @276_506ee0
  eax = ((u32(STDCALL *)(void))(eax))();  // @277_506ee0
  ecx = edx = 0;  // @278_506ee0
  goto L507205;  // @279_506ee0
  L507204:;
  __builtin_trap();  // @281_506ee0
  L507205:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @283_506ee0
  L507208:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @285_506ee0
  X0[1] = 0;  // @286_506ee0
  X0[2] = 0;  // @287_506ee0
  X0[3] = 0;  // @288_506ee0
  PV[8] = (u32)(edi);  // @289_506ee0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @290_506ee0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @291_506ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @292_506ee0
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @293_506ee0
  ecx = edx = 0;  // @294_506ee0
  ecx = eax;  // @295_506ee0
  eax = ext_5002f0_thiscall2(ecx, PV[8]);  // @296_506ee0
  ecx = edx = 0;  // @297_506ee0
  ext_633654(G(u32, 0x6f5630));  // @298_506ee0
  return eax;  // @299_506ee0
}
PCREG(506ee0, lifted_506ee0);

extern "C" u32 THISCALL lifted_4e7530(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4e7530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_4e7530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; });  // @2_4e7530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 212), &v, sizeof v); }  // @3_4e7530
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @4_4e7530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_4e7530
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @6_4e7530
  FL[2] = (esi & esi);  // @7_4e7530
  if (FL[2] != 0) goto L4e7589;  // @8_4e7530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @9_4e7530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @10_4e7530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @11_4e7530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @12_4e7530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @13_4e7530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @14_4e7530
  ext_633654(G(u32, 0x6f5630));  // @15_4e7530
  return eax;  // @16_4e7530
  L4e7589:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @18_4e7530
  ecx = (ecx & (u32)(3221225472));  // @19_4e7530
  FL[3] = ecx;  // @20_4e7530
  FL[0] = ecx; FL[1] = (u32)(1073741824);  // @21_4e7530
  if (FL[0] == FL[1]) goto L4e75b0;  // @22_4e7530
  FL[0] = ecx; FL[1] = (u32)(2147483648);  // @23_4e7530
  if (FL[0] == FL[1]) goto L4e75b0;  // @24_4e7530
  ebx = (u32)(8);  // @25_4e7530
  FL[0] = ecx; FL[1] = (u32)(3221225472);  // @26_4e7530
  if (FL[0] != FL[1]) goto L4e75b3;  // @27_4e7530
  L4e75b0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @29_4e7530
  L4e75b3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi), sizeof v); (u32)v; });  // @31_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @32_4e7530
  FL[2] = (ecx & ecx);  // @33_4e7530
  if (FL[2] != 0) goto L4e75e3;  // @34_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @35_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @36_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @37_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @38_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @39_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @40_4e7530
  ext_633654(G(u32, 0x6f5630));  // @41_4e7530
  return eax;  // @42_4e7530
  L4e75e3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_4e7530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_4e7530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4e7530
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 380)))(ecx);  // @47_4e7530
  ecx = edx = 0;  // @48_4e7530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi + 24), sizeof v); (u32)v; });  // @49_4e7530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi + 20), sizeof v); (u32)v; });  // @50_4e7530
  ecx = (ecx + eax);  // @51_4e7530
  FL[3] = ecx;  // @52_4e7530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi + 28), sizeof v); (u32)v; });  // @53_4e7530
  edi = (edi + eax);  // @54_4e7530
  FL[3] = edi;  // @55_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @56_4e7530
  edx = (edx + eax);  // @57_4e7530
  FL[3] = edx;  // @58_4e7530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi + 16), sizeof v); (u32)v; });  // @59_4e7530
  ecx = (ecx + eax);  // @60_4e7530
  FL[3] = ecx;  // @61_4e7530
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @62_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @63_4e7530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi + 36), sizeof v); (u32)v; });  // @64_4e7530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi + 32), sizeof v); (u32)v; });  // @65_4e7530
  ecx = (ecx + eax);  // @66_4e7530
  FL[3] = ecx;  // @67_4e7530
  ebx = (ebx + eax);  // @68_4e7530
  FL[3] = ebx;  // @69_4e7530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @70_4e7530
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @71_4e7530
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @72_4e7530
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @73_4e7530
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @74_4e7530
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @75_4e7530
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @76_4e7530
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @77_4e7530
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @78_4e7530
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @79_4e7530
  if (FL[0] == FL[1]) goto L4e76c6;  // @80_4e7530
  PV[0] = (u32)(ecx);  // @81_4e7530
  PV[1] = (u32)(ebx);  // @82_4e7530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @83_4e7530
  eax = (u32)(EBP - 52);  // @84_4e7530
  PV[2] = (u32)(edx);  // @85_4e7530
  PV[3] = (u32)(ebx);  // @86_4e7530
  PV[4] = (u32)(ecx);  // @87_4e7530
  ecx = (u32)(EBP - 169);  // @88_4e7530
  PV[5] = (u32)(eax);  // @89_4e7530
  eax = ext_4e89d0_thiscall7(ecx, PV[5], (u32)(0), PV[3], PV[2], PV[1], PV[0]);  // @90_4e7530
  ecx = edx = 0;  // @91_4e7530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; });  // @92_4e7530
  eax = (u32)(EBP - 80);  // @93_4e7530
  PV[6] = (u32)(esi);  // @94_4e7530
  PV[7] = (u32)(edi);  // @95_4e7530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @96_4e7530
  PV[8] = (u32)(edi);  // @97_4e7530
  PV[9] = (u32)(ebx);  // @98_4e7530
  PV[10] = (u32)(ecx);  // @99_4e7530
  ecx = (u32)(EBP - 169);  // @100_4e7530
  PV[11] = (u32)(eax);  // @101_4e7530
  eax = ext_4e87b0_thiscall7(ecx, PV[11], (u32)(0), PV[9], PV[8], PV[7], PV[6]);  // @102_4e7530
  ecx = edx = 0;  // @103_4e7530
  edx = (u32)(EBP - 80);  // @104_4e7530
  ecx = (u32)(EBP - 168);  // @105_4e7530
  eax = ext_4df1e0_fastcall2(ecx, edx);  // @106_4e7530
    // @107_4e7530
  goto L4e76f8;  // @108_4e7530
  L4e76c6:;
  ecx = (u32)(EBP - 168);  // @110_4e7530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @111_4e7530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @112_4e7530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @113_4e7530
  eax = ext_4de7a0_thiscall1(ecx);  // @114_4e7530
    // @115_4e7530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @116_4e7530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; });  // @117_4e7530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @118_4e7530
  L4e76f8:;
  eax = 0;  // @120_4e7530
  FL[3] = eax;  // @121_4e7530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @122_4e7530
  L4e7700:;
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @124_4e7530
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @125_4e7530
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @126_4e7530
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @127_4e7530
  eax = (eax >> (u32)(31));  // @128_4e7530
  FL[3] = eax;  // @129_4e7530
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @130_4e7530
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @131_4e7530
  PV[15] = (u32)(ebx);  // @132_4e7530
  PV[16] = (u32)(ecx);  // @133_4e7530
  eax = (u32)(EBP - 28);  // @134_4e7530
  ecx = (u32)(EBP - 169);  // @135_4e7530
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @136_4e7530
  PV[17] = X0[0];  // @137_4e7530
  PV[18] = (u32)(eax);  // @138_4e7530
  __builtin_memcpy((void *)((u32)(EBP - 180) + 0), &X0[0], 4);  // @139_4e7530
  eax = ext_4e89d0_thiscall7(ecx, PV[18], PV[17], PV[15], PV[14], PV[13], PV[12]);  // @140_4e7530
  ecx = edx = 0;  // @141_4e7530
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 180) + 0), 4); v; });  // @142_4e7530
  X0[1] = 0;  // @143_4e7530
  X0[2] = 0;  // @144_4e7530
  X0[3] = 0;  // @145_4e7530
  eax = (u32)(EBP - 132);  // @146_4e7530
  PV[19] = (u32)(esi);  // @147_4e7530
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @148_4e7530
  PV[21] = (u32)(edi);  // @149_4e7530
  PV[22] = (u32)(ebx);  // @150_4e7530
  PV[23] = (u32)(ecx);  // @151_4e7530
  PV[24] = X0[0];  // @152_4e7530
  ecx = (u32)(EBP - 169);  // @153_4e7530
  PV[25] = (u32)(eax);  // @154_4e7530
  eax = ext_4e87b0_thiscall7(ecx, PV[25], PV[24], PV[22], PV[21], PV[20], PV[19]);  // @155_4e7530
  ecx = edx = 0;  // @156_4e7530
  edx = (u32)(EBP - 132);  // @157_4e7530
  ecx = (u32)(EBP - 116);  // @158_4e7530
  eax = ext_4df1e0_fastcall2(ecx, edx);  // @159_4e7530
    // @160_4e7530
  edx = (u32)(EBP - 52);  // @161_4e7530
  ecx = (u32)(EBP - 28);  // @162_4e7530
  eax = ext_43e960_fastcall2(ecx, edx);  // @163_4e7530
  ecx = edx = 0;  // @164_4e7530
  edx = (u32)(EBP - 168);  // @165_4e7530
  ecx = (u32)(EBP - 116);  // @166_4e7530
  eax = ext_4de4f0_fastcall2(ecx, edx);  // @167_4e7530
  ecx = edx = 0;  // @168_4e7530
  ecx = (u32)(EBP - 116);  // @169_4e7530
  eax = ext_4de7a0_thiscall1(ecx);  // @170_4e7530
    // @171_4e7530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @172_4e7530
  eax = (u32)(EBP - 116);  // @173_4e7530
  PV[26] = (u32)(eax);  // @174_4e7530
  ecx = (u32)(EBP - 76);  // @175_4e7530
  eax = ext_441970_fastcall3(ecx, edx, PV[26]);  // @176_4e7530
  ecx = edx = 0;  // @177_4e7530
  edx = (u32)(EBP - 76);  // @178_4e7530
  ecx = (u32)(EBP - 28);  // @179_4e7530
  eax = ext_441940_fastcall2(ecx, edx);  // @180_4e7530
  ecx = edx = 0;  // @181_4e7530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @182_4e7530
  edx = (u32)(EBP - 16);  // @183_4e7530
  ecx = (u32)(EBP - 116);  // @184_4e7530
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @185_4e7530
  X0[1] = 0;  // @186_4e7530
  X0[2] = 0;  // @187_4e7530
  X0[3] = 0;  // @188_4e7530
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @189_4e7530
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @190_4e7530
  X0[1] = 0;  // @191_4e7530
  X0[2] = 0;  // @192_4e7530
  X0[3] = 0;  // @193_4e7530
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @194_4e7530
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @195_4e7530
  X0[1] = 0;  // @196_4e7530
  X0[2] = 0;  // @197_4e7530
  X0[3] = 0;  // @198_4e7530
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @199_4e7530
  eax = ext_4e2c60_fastcall2(ecx, edx);  // @200_4e7530
    // @201_4e7530
  eax = (u32)(EBP - 16);  // @202_4e7530
  PV[27] = (u32)(eax);  // @203_4e7530
  edx = (u32)(EBP - 28);  // @204_4e7530
  ecx = (u32)(EBP - 76);  // @205_4e7530
  eax = ext_43e920_fastcall3(ecx, edx, PV[27]);  // @206_4e7530
  ecx = edx = 0;  // @207_4e7530
  edx = (u32)(EBP - 16);  // @208_4e7530
  ecx = (u32)(EBP - 28);  // @209_4e7530
  eax = ext_441940_fastcall2(ecx, edx);  // @210_4e7530
  ecx = edx = 0;  // @211_4e7530
  edx = (u32)(EBP - 28);  // @212_4e7530
  ecx = (u32)(EBP - 40);  // @213_4e7530
  eax = ext_4e08d0_fastcall2(ecx, edx);  // @214_4e7530
    // @215_4e7530
  edx = (u32)(EBP - 76);  // @216_4e7530
  ecx = (u32)(EBP - 64);  // @217_4e7530
  eax = ext_4e0900_fastcall2(ecx, edx);  // @218_4e7530
    // @219_4e7530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @220_4e7530
  eax = (eax + 1);  // @221_4e7530
  FL[3] = eax;  // @222_4e7530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @223_4e7530
  FL[0] = eax; FL[1] = ebx;  // @224_4e7530
  if (FL[0] != FL[1]) goto L4e7700;  // @225_4e7530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @226_4e7530
  eax = (u32)(EBP - 64);  // @227_4e7530
  PV[28] = (u32)(eax);  // @228_4e7530
  edx = (u32)(EBP - 40);  // @229_4e7530
  ecx = edi;  // @230_4e7530
  eax = ext_43e920_fastcall3(ecx, edx, PV[28]);  // @231_4e7530
  ecx = edx = 0;  // @232_4e7530
  PV[29] = (u32)(ecx);  // @233_4e7530
  ecx = edi;  // @234_4e7530
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @235_4e7530
    // @236_4e7530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @237_4e7530
  edx = (u32)(EBP - 40);  // @238_4e7530
  PV[30] = (u32)(edi);  // @239_4e7530
  eax = ext_43e920_fastcall3(ecx, edx, PV[30]);  // @240_4e7530
  ecx = edx = 0;  // @241_4e7530
  ext_633654(G(u32, 0x6f5630));  // @242_4e7530
  return eax;  // @243_4e7530
}
PCREG(4e7530, lifted_4e7530);




