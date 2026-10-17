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

extern "C" u32 THISCALL lifted_567f70(u32 ecx_in) {
  u8 F[0x9c0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x8c0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_567f70
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 656), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_567f70
  if (FL[0] == FL[1]) goto L568167;  // @2_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @4_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_567f70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6932112));  // @6_567f70
  ecx = edx = 0;  // @7_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 665), &v, sizeof v); }  // @8_567f70
  ecx = eax;  // @9_567f70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_567f70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(6974956));  // @11_567f70
  ecx = edx = 0;  // @12_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @13_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 669), &v, sizeof v); }  // @14_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @15_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 652), &v, sizeof v); }  // @16_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_567f70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1124)))(ecx);  // @18_567f70
  ecx = edx = 0;  // @19_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 648), &v, sizeof v); }  // @20_567f70
  ecx = (u32)(ebx + 636);  // @21_567f70
  eax = (u32)(ebx + 384);  // @22_567f70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 656), &v, sizeof v); }  // @23_567f70
  PV[0] = (u32)(eax);  // @24_567f70
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @25_567f70
  eax = ext_5afbb0_thiscall3(ecx, PV[1], PV[0]);  // @26_567f70
  ecx = edx = 0;  // @27_567f70
  edi = (u32)(ebx + 552);  // @28_567f70
  ecx = edi;  // @29_567f70
  eax = ext_4cc1d0_thiscall1(ecx);  // @30_567f70
    // @31_567f70
  FL[2] = (eax & eax);  // @32_567f70
  if (FL[2] == 0) goto L568167;  // @33_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @36_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_567f70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6976420));  // @38_567f70
  ecx = edx = 0;  // @39_567f70
  edx = (u32)((EBP - 2104) + 56);  // @40_567f70
  edx = (edx - eax);  // @41_567f70
  FL[3] = edx;  // @42_567f70
  L568042:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @44_567f70
  eax = (u32)(eax + 1);  // @45_567f70
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @46_567f70
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @47_567f70
  if (FL[2] != 0) goto L568042;  // @48_567f70
  ecx = (u32)((EBP - 2104) + 56);  // @49_567f70
  ecx = (ecx - 1);  // @50_567f70
  FL[3] = ecx;  // @51_567f70
  L568054:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @53_567f70
  ecx = (u32)(ecx + 1);  // @54_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @55_567f70
  if (FL[2] != 0) goto L568054;  // @56_567f70
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6976432), sizeof v); (u32)v; })) & 0xffff);  // @57_567f70
  esi = 0;  // @58_567f70
  FL[3] = esi;  // @59_567f70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @60_567f70
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6976434), sizeof v); (u32)v; })) & 0xff);  // @61_567f70
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 2), &v, sizeof v); }  // @62_567f70
  ecx = edi;  // @63_567f70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 2104) + 12), &v, sizeof v); }  // @64_567f70
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_567f70
    // @66_567f70
  FL[2] = (eax & eax);  // @67_567f70
  if ((s32)FL[2] <= 0) goto L56814f;  // @68_567f70
  L568084:;
  PV[2] = (u32)(esi);  // @70_567f70
  ecx = edi;  // @71_567f70
  eax = ext_5af0d0_thiscall2(ecx, PV[2]);  // @72_567f70
    // @73_567f70
  edx = (u32)(6801640);  // @74_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @76_567f70
  FL[2] = (eax & eax);  // @77_567f70
  if (FL[2] != 0) edx = eax;  // @78_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_567f70
  PV[3] = (u32)(edx);  // @80_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @81_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @82_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_567f70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6850972), PV[3]);  // @84_567f70
  ecx = edx = 0;  // @85_567f70
  edx = eax;  // @86_567f70
  esi = eax;  // @87_567f70
  L5680c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @89_567f70
  edx = (edx + 1);  // @90_567f70
  FL[3] = edx;  // @91_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @92_567f70
  if (FL[2] != 0) goto L5680c0;  // @93_567f70
  edi = (u32)((EBP - 2104) + 56);  // @94_567f70
  edx = (edx - esi);  // @95_567f70
  FL[3] = edx;  // @96_567f70
  edi = (edi - 1);  // @97_567f70
  FL[3] = edi;  // @98_567f70
  L5680d0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @100_567f70
  edi = (edi + 1);  // @101_567f70
  FL[3] = edi;  // @102_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @103_567f70
  if (FL[2] != 0) goto L5680d0;  // @104_567f70
  ecx = edx;  // @105_567f70
  ecx = (ecx >> (u32)(2));  // @106_567f70
  FL[3] = ecx;  // @107_567f70
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @108_567f70
  ecx = edx;  // @109_567f70
  ecx = (ecx & (u32)(3));  // @110_567f70
  FL[3] = ecx;  // @111_567f70
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @112_567f70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2104) + 12), sizeof v); (u32)v; });  // @113_567f70
  edi = (u32)(ebx + 552);  // @114_567f70
  esi = (esi + 1);  // @115_567f70
  FL[3] = esi;  // @116_567f70
  ecx = edi;  // @117_567f70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 2104) + 12), &v, sizeof v); }  // @118_567f70
  eax = ext_4cc1d0_thiscall1(ecx);  // @119_567f70
    // @120_567f70
  FL[0] = esi; FL[1] = eax;  // @121_567f70
  if ((s32)FL[0] >= (s32)FL[1]) goto L568140;  // @122_567f70
  ecx = (u32)((EBP - 2104) + 56);  // @123_567f70
  ecx = (ecx - 1);  // @124_567f70
  FL[3] = ecx;  // @125_567f70
  L568105:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @127_567f70
  ecx = (u32)(ecx + 1);  // @128_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @129_567f70
  if (FL[2] != 0) goto L568105;  // @130_567f70
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6793336), sizeof v); (u32)v; })) & 0xffff);  // @131_567f70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @132_567f70
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6793338), sizeof v); (u32)v; })) & 0xff);  // @133_567f70
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 2), &v, sizeof v); }  // @134_567f70
  ecx = (u32)((EBP - 2104) + 56);  // @135_567f70
  ecx = (ecx - 1);  // @136_567f70
  FL[3] = ecx;  // @137_567f70
  L568125:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @139_567f70
  ecx = (u32)(ecx + 1);  // @140_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @141_567f70
  if (FL[2] != 0) goto L568125;  // @142_567f70
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6976432), sizeof v); (u32)v; })) & 0xffff);  // @143_567f70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @144_567f70
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6976434), sizeof v); (u32)v; })) & 0xff);  // @145_567f70
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 2), &v, sizeof v); }  // @146_567f70
  L568140:;
  ecx = edi;  // @148_567f70
  eax = ext_4cc1d0_thiscall1(ecx);  // @149_567f70
    // @150_567f70
  FL[0] = esi; FL[1] = eax;  // @151_567f70
  if ((s32)FL[0] < (s32)FL[1]) goto L568084;  // @152_567f70
  L56814f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 652), sizeof v); (u32)v; });  // @154_567f70
  eax = (u32)((EBP - 2104) + 56);  // @155_567f70
  PV[4] = (u32)(eax);  // @156_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 7439), sizeof v); (u32)v; });  // @157_567f70
  eax = ext_5a8510_thiscall3(ecx, PV[4], (u32)(1));  // @158_567f70
  ecx = edx = 0;  // @159_567f70
  L568167:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @161_567f70
  edx = (u32)((EBP - 2104) + 44);  // @162_567f70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; });  // @163_567f70
  X0[1] = 0;  // @164_567f70
  X0[2] = 0;  // @165_567f70
  X0[3] = 0;  // @166_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 657), &v, sizeof v); }  // @167_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2104) + 44), &v, sizeof v); }  // @168_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2104) + 48), &v, sizeof v); }  // @169_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2104) + 52), &v, sizeof v); }  // @170_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @171_567f70
  PV[5] = (u32)(edx);  // @172_567f70
  __builtin_memcpy((void *)((u32)((EBP - 2108) + 16) + 0), &X0[0], 4);  // @173_567f70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[5]);  // @174_567f70
  ecx = edx = 0;  // @175_567f70
  esi = (u32)(ebx + 1006);  // @176_567f70
  edi = (u32)(8);  // @177_567f70
  L5681b5:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @179_567f70
  if (FL[0] == FL[1]) goto L568259;  // @180_567f70
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @181_567f70
  ecx = (u32)(ebx + 468);  // @182_567f70
  eax = ext_5af130_fastcall3(ecx, edx, PV[6]);  // @183_567f70
  edx = 0;  // @184_567f70
  FL[2] = (eax & eax);  // @185_567f70
  if (FL[2] == 0) goto L568259;  // @186_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @187_567f70
  edx = (u32)((EBP - 2104) + 32);  // @188_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2104) + 32), &v, sizeof v); }  // @189_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2104) + 36), &v, sizeof v); }  // @190_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2104) + 40), &v, sizeof v); }  // @191_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_567f70
  PV[7] = (u32)(edx);  // @193_567f70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[7]);  // @194_567f70
  ecx = edx = 0;  // @195_567f70
  eax = (u32)((EBP - 2104) + 32);  // @196_567f70
  PV[8] = (u32)(eax);  // @197_567f70
  edx = (u32)((EBP - 2108) + 48);  // @198_567f70
  ecx = (u32)((EBP - 2108) + 24);  // @199_567f70
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @200_567f70
  ecx = edx = 0;  // @201_567f70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 2104) + 20) + 0), 4); v; });  // @202_567f70
  X1[1] = 0;  // @203_567f70
  X1[2] = 0;  // @204_567f70
  X1[3] = 0;  // @205_567f70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 2104) + 24) + 0), 4); v; });  // @206_567f70
  X0[1] = 0;  // @207_567f70
  X0[2] = 0;  // @208_567f70
  X0[3] = 0;  // @209_567f70
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @210_567f70
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @211_567f70
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @212_567f70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 2104) + 28) + 0), 4); v; });  // @213_567f70
  X0[1] = 0;  // @214_567f70
  X0[2] = 0;  // @215_567f70
  X0[3] = 0;  // @216_567f70
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @217_567f70
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @218_567f70
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @219_567f70
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @220_567f70
  ecx = edx = 0;  // @221_567f70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 2104) + 12) + 0), 4); v; });  // @222_567f70
  X1[1] = 0;  // @223_567f70
  X1[2] = 0;  // @224_567f70
  X1[3] = 0;  // @225_567f70
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @226_567f70
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L568259;  // @227_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @228_567f70
  __builtin_memcpy((void *)((u32)((EBP - 2104) + 12) + 0), &X0[0], 4);  // @229_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 657), &v, sizeof v); }  // @230_567f70
  L568259:;
  esi = (esi + (u32)(8));  // @232_567f70
  FL[3] = esi;  // @233_567f70
  edi = (edi - (u32)(1));  // @234_567f70
  FL[3] = edi;  // @235_567f70
  if (FL[3] != 0) goto L5681b5;  // @236_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 657), sizeof v); (u32)v; });  // @237_567f70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 2104) + 16), &v, sizeof v); }  // @238_567f70
  FL[2] = (eax & eax);  // @239_567f70
  if (FL[2] == 0) goto L5682f2;  // @240_567f70
  PV[9] = (u32)(eax);  // @241_567f70
  ecx = (u32)(ebx + 384);  // @242_567f70
  eax = ext_5af130_fastcall3(ecx, edx, PV[9]);  // @243_567f70
  edx = 0;  // @244_567f70
  ecx = (u32)(ebx + 636);  // @245_567f70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @246_567f70
  eax = (u32)((EBP - 2104) + 12);  // @247_567f70
  if (FL[0] != FL[1]) goto L568297;  // @248_567f70
  goto L568299;  // @249_567f70
  L568297:;
  L568299:;
  PV[10] = (u32)(eax);  // @252_567f70
  eax = (u32)((EBP - 2116) + 24);  // @253_567f70
  PV[11] = (u32)(eax);  // @254_567f70
  eax = ext_5af5b0_thiscall4(ecx, PV[11], PV[10], (u32)(0));  // @255_567f70
  ecx = edx = 0;  // @256_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2108) + 16), sizeof v); (u32)v; });  // @257_567f70
  FL[2] = (eax & eax);  // @258_567f70
  if (FL[2] != 0) goto L5682b5;  // @259_567f70
  ecx = ebx;  // @260_567f70
  eax = ext_568dc0_thiscall1(ecx);  // @261_567f70
  ecx = edx = 0;  // @262_567f70
  goto L5682f2;  // @263_567f70
  L5682b5:;
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 657), sizeof v); (u32)v; });  // @265_567f70
  if (FL[0] == FL[1]) goto L5682f2;  // @266_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @267_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @268_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @269_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @270_567f70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6976444), (u32)(6976436), (u32)(1));  // @271_567f70
  ecx = edx = 0;  // @272_567f70
  PV[12] = (u32)(eax);  // @273_567f70
  PV[13] = (u32)(ecx);  // @274_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @275_567f70
  eax = ext_5950c0_thiscall4(ecx, (u32)(17), (u32)(1133903872), PV[12]);  // @276_567f70
    // @277_567f70
  L5682f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 657), sizeof v); (u32)v; });  // @279_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 661), &v, sizeof v); }  // @280_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @281_567f70
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 669), sizeof v); (u32)v; });  // @282_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @283_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @284_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @285_567f70
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[14], (u32)(0));  // @286_567f70
  ecx = edx = 0;  // @287_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @288_567f70
  if (FL[2] == 0) goto L568333;  // @289_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 657), sizeof v); (u32)v; });  // @290_567f70
  FL[2] = (eax & eax);  // @291_567f70
  if (FL[2] == 0) goto L568333;  // @292_567f70
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2104) + 16), sizeof v); (u32)v; });  // @293_567f70
  if (FL[0] == FL[1]) goto L568333;  // @294_567f70
  ecx = ebx;  // @295_567f70
  eax = ext_568dc0_thiscall1(ecx);  // @296_567f70
  ecx = edx = 0;  // @297_567f70
  L568333:;
  ext_633654(G(u32, 0x6f5630));  // @299_567f70
  return eax;  // @300_567f70
}
PCREG(567f70, lifted_567f70);

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
  ecx = (u32)((EBP - 284) + 108);  // @10_44ff60
  PV[0] = (u32)(ecx);  // @11_44ff60
  ecx = (u32)((EBP - 288) + 224);  // @12_44ff60
  PV[1] = (u32)(ecx);  // @13_44ff60
  ecx = edi;  // @14_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[1], PV[0]);  // @15_44ff60
  ecx = edx = 0;  // @16_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_44ff60
  ecx = (u32)((EBP - 284) + 48);  // @18_44ff60
  PV[2] = (u32)(ecx);  // @19_44ff60
  ecx = edi;  // @20_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 288) + 52), &v, sizeof v); }  // @21_44ff60
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)((EBP - 288) + 56), &v, sizeof v); }  // @22_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 288) + 60), &v, sizeof v); }  // @23_44ff60
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
  ecx = (u32)((EBP - 284) + 256);  // @144_44ff60
  eax = ext_4de7a0_thiscall1(ecx);  // @145_44ff60
    // @146_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @147_44ff60
  edx = (u32)((EBP - 284) + 220);  // @148_44ff60
  ecx = (u32)((EBP - 284) + 24);  // @149_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 0), 4); v; });  // @150_44ff60
  X0[1] = 0;  // @151_44ff60
  X0[2] = 0;  // @152_44ff60
  X0[3] = 0;  // @153_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 24) + 0), &X0[0], 4);  // @154_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 52) + 0), 4); v; });  // @155_44ff60
  X0[1] = 0;  // @156_44ff60
  X0[2] = 0;  // @157_44ff60
  X0[3] = 0;  // @158_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 28) + 0), &X0[0], 4);  // @159_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 56) + 0), 4); v; });  // @160_44ff60
  X0[1] = 0;  // @161_44ff60
  X0[2] = 0;  // @162_44ff60
  X0[3] = 0;  // @163_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 32) + 0), &X0[0], 4);  // @164_44ff60
  eax = ext_4419f0_fastcall2(ecx, edx);  // @165_44ff60
  ecx = edx = 0;  // @166_44ff60
  edx = (u32)((EBP - 284) + 108);  // @167_44ff60
  ecx = (u32)((EBP - 284) + 24);  // @168_44ff60
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
  __builtin_memcpy((void *)((u32)((EBP - 284) + 84) + 0), &X0[0], 4);  // @181_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 88) + 0), &X0[0], 4);  // @182_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 92) + 0), &X0[0], 4);  // @183_44ff60
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
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 24) + 0), 4); v; });  // @205_44ff60
  X0[1] = 0;  // @206_44ff60
  X0[2] = 0;  // @207_44ff60
  X0[3] = 0;  // @208_44ff60
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @209_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 28) + 0), 4); v; });  // @210_44ff60
  X0[1] = 0;  // @211_44ff60
  X0[2] = 0;  // @212_44ff60
  X0[3] = 0;  // @213_44ff60
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @214_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 32) + 0), 4); v; });  // @215_44ff60
  X0[1] = 0;  // @216_44ff60
  X0[2] = 0;  // @217_44ff60
  X0[3] = 0;  // @218_44ff60
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @219_44ff60
  L4501d0:;
  PV[5] = (u32)(esi);  // @221_44ff60
  edx = (u32)((EBP - 288) + 28);  // @222_44ff60
  ecx = (u32)((EBP - 288) + 40);  // @223_44ff60
  eax = ext_43e920_fastcall3(ecx, edx, PV[5]);  // @224_44ff60
  ecx = edx = 0;  // @225_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 24) + 0), 4); v; });  // @226_44ff60
  X0[1] = 0;  // @227_44ff60
  X0[2] = 0;  // @228_44ff60
  X0[3] = 0;  // @229_44ff60
  edx = (u32)((EBP - 284) + 220);  // @230_44ff60
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @231_44ff60
  ecx = (u32)((EBP - 284) + 36);  // @232_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 28) + 0), 4); v; });  // @233_44ff60
  X0[1] = 0;  // @234_44ff60
  X0[2] = 0;  // @235_44ff60
  X0[3] = 0;  // @236_44ff60
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @237_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 32) + 0), 4); v; });  // @238_44ff60
  X0[1] = 0;  // @239_44ff60
  X0[2] = 0;  // @240_44ff60
  X0[3] = 0;  // @241_44ff60
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @242_44ff60
  eax = ext_441a60_fastcall2(ecx, edx);  // @243_44ff60
  ecx = edx = 0;  // @244_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 40) + 0), 4); v; });  // @245_44ff60
  X0[1] = 0;  // @246_44ff60
  X0[2] = 0;  // @247_44ff60
  X0[3] = 0;  // @248_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 36) + 0), 4); v; });  // @249_44ff60
  X1[1] = 0;  // @250_44ff60
  X1[2] = 0;  // @251_44ff60
  X1[3] = 0;  // @252_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @253_44ff60
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @254_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @255_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 44) + 0), 4); v; });  // @256_44ff60
  X0[1] = 0;  // @257_44ff60
  X0[2] = 0;  // @258_44ff60
  X0[3] = 0;  // @259_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @260_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @261_44ff60
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; }))))))) goto L450339;  // @262_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @263_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @264_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 284) + 36), &v, sizeof v); }  // @265_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 284) + 40), &v, sizeof v); }  // @266_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 284) + 44), &v, sizeof v); }  // @267_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @268_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 284) + 12), &v, sizeof v); }  // @269_44ff60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 284) + 20), &v, sizeof v); }  // @270_44ff60
  if (FL[0] <= FL[1]) goto L450373;  // @271_44ff60
  ecx = (u32)(4294967288);  // @272_44ff60
  ebx = (u32)(eax + 8);  // @273_44ff60
  ecx = (ecx - eax);  // @274_44ff60
  FL[3] = ecx;  // @275_44ff60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 284) + 16), &v, sizeof v); }  // @276_44ff60
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
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 20), sizeof v); (u32)v; }));  // @288_44ff60
  FL[3] = eax;  // @289_44ff60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @290_44ff60
  esi = (esi + edx);  // @291_44ff60
  FL[3] = esi;  // @292_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 12), sizeof v); (u32)v; });  // @293_44ff60
  ecx = (u32)(eax + eax*2);  // @294_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @295_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4), &v, sizeof v); }  // @296_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @297_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4 + 4), &v, sizeof v); }  // @298_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @299_44ff60
  esi = edx;  // @300_44ff60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 20), sizeof v); (u32)v; });  // @301_44ff60
  edx = (edx + 1);  // @302_44ff60
  FL[3] = edx;  // @303_44ff60
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 284) + 20), &v, sizeof v); }  // @304_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx*4 + 8), &v, sizeof v); }  // @305_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 16), sizeof v); (u32)v; });  // @306_44ff60
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
  eax = (u32)((EBP - 284) + 48);  // @327_44ff60
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
  ecx = (u32)((EBP - 292) + 40);  // @356_44ff60
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1032358025));  // @357_44ff60
    // @358_44ff60
  L450373:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @360_44ff60
  if (FL[0] != FL[1]) goto L45038d;  // @361_44ff60
  PV[11] = (u32)(ecx);  // @362_44ff60
  ecx = (u32)(edi + 40);  // @363_44ff60
  edx = (u32)((EBP - 292) + 40);  // @364_44ff60
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
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 288) + 20), &v, sizeof v); }  // @375_44ff60
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
  eax = (u32)((EBP - 292) + 40);  // @404_44ff60
  PV[13] = (u32)(eax);  // @405_44ff60
  goto L45040d;  // @406_44ff60
  L45040b:;
  L45040d:;
  eax = (u32)((EBP - 300) + 56);  // @409_44ff60
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
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 292) + 12), &v, sizeof v); }  // @421_44ff60
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
  __builtin_memcpy((void *)((u32)((EBP - 292) + 16) + 0), &X2[0], 4);  // @456_44ff60
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
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 292) + 16) + 0), 4); v; });  // @487_44ff60
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
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 292) + 16) + 0), 4); v; });  // @513_44ff60
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 292) + 12), sizeof v); (u32)v; });  // @526_44ff60
  L450542:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @528_44ff60
  esi = 0;  // @529_44ff60
  FL[3] = esi;  // @530_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; });  // @531_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }); FL[1] = esi;  // @532_44ff60
  if (FL[0] <= FL[1]) goto L45057f;  // @533_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 292) + 20), sizeof v); (u32)v; });  // @534_44ff60
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 292) + 12), sizeof v); (u32)v; });  // @557_44ff60
  L45057f:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 292) + 20), sizeof v); (u32)v; });  // @559_44ff60
  eax = (eax + 1);  // @560_44ff60
  FL[3] = eax;  // @561_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 292) + 12), &v, sizeof v); }  // @562_44ff60
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
  edx = (u32)((EBP - 292) + 84);  // @574_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @575_44ff60
  PV[18] = (u32)(edx);  // @576_44ff60
  edx = (u32)((EBP - 312) + 44);  // @577_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @578_44ff60
  PV[19] = (u32)(edx);  // @579_44ff60
  edx = (u32)((EBP - 316) + 280);  // @580_44ff60
  PV[20] = (u32)(edx);  // @581_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @582_44ff60
  edx = (u32)((EBP - 320) + 164);  // @583_44ff60
  PV[21] = (u32)(edx);  // @584_44ff60
  edx = (u32)((EBP - 328) + 156);  // @585_44ff60
  PV[22] = (u32)(edx);  // @586_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 56)))(ecx, PV[22], PV[21], (u32)(0), PV[20], PV[19], PV[18], (u32)(2), (u32)(0), (u32)(1), (u32)(1), (u32)(1023969417), PV[9]);  // @587_44ff60
  ecx = edx = 0;  // @588_44ff60
  esi = 0;  // @589_44ff60
  FL[3] = esi;  // @590_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 284) + 16), &v, sizeof v); }  // @591_44ff60
  FL[2] = (eax & eax);  // @592_44ff60
  if (FL[2] == 0) goto L4507e5;  // @593_44ff60
  ebx = eax;  // @594_44ff60
  L450600:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + esi*4 + 120), sizeof v); (u32)v; });  // @596_44ff60
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2097154));  // @597_44ff60
  ecx = 0;  // @598_44ff60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @599_44ff60
  if (FL[2] == 0) goto L4506f8;  // @600_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + esi*4 + 120), sizeof v); (u32)v; });  // @601_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @602_44ff60
  FL[2] = (ecx & ecx);  // @603_44ff60
  if (FL[2] == 0) goto L4506f8;  // @604_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @605_44ff60
  edx = (u32)((EBP - 284) + 60);  // @606_44ff60
  PV[23] = (u32)(edx);  // @607_44ff60
  edx = (u32)((EBP - 288) + 140);  // @608_44ff60
  PV[24] = (u32)(edx);  // @609_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[24], PV[23]);  // @610_44ff60
  ecx = edx = 0;  // @611_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @612_44ff60
  ecx = (u32)((EBP - 284) + 172);  // @613_44ff60
  PV[25] = (u32)(ecx);  // @614_44ff60
  ecx = (u32)((EBP - 288) + 188);  // @615_44ff60
  PV[26] = (u32)(ecx);  // @616_44ff60
  ecx = edi;  // @617_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[26], PV[25]);  // @618_44ff60
  ecx = edx = 0;  // @619_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @620_44ff60
  edx = (u32)((EBP - 284) + 172);  // @621_44ff60
  ecx = (u32)((EBP - 284) + 60);  // @622_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 76) + 0), 4); v; });  // @623_44ff60
  X0[1] = 0;  // @624_44ff60
  X0[2] = 0;  // @625_44ff60
  X0[3] = 0;  // @626_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @627_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 16) + 0), &X0[0], 4);  // @628_44ff60
  eax = ext_43e960_fastcall2(ecx, edx);  // @629_44ff60
  ecx = edx = 0;  // @630_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 60) + 0), 4); v; });  // @631_44ff60
  X1[1] = 0;  // @632_44ff60
  X1[2] = 0;  // @633_44ff60
  X1[3] = 0;  // @634_44ff60
  X0[0] = 0;  // @635_44ff60
  X0[1] = 0;  // @636_44ff60
  X0[2] = 0;  // @637_44ff60
  X0[3] = 0;  // @638_44ff60
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @639_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @640_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 68) + 0), 4); v; });  // @641_44ff60
  X0[1] = 0;  // @642_44ff60
  X0[2] = 0;  // @643_44ff60
  X0[3] = 0;  // @644_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @645_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @646_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 16) + 0), 4); v; });  // @647_44ff60
  X0[1] = 0;  // @648_44ff60
  X0[2] = 0;  // @649_44ff60
  X0[3] = 0;  // @650_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @651_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 12) + 0), &X1[0], 4);  // @652_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 12), sizeof v); (u32)v; });  // @653_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 16) + 0), &X0[0], 4);  // @654_44ff60
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 16), sizeof v); (u32)v; });  // @655_44ff60
  if ((s32)FL[0] > (s32)FL[1]) goto L4506f8;  // @656_44ff60
  edx = (u32)((EBP - 284) + 184);  // @657_44ff60
  ecx = (u32)((EBP - 284) + 60);  // @658_44ff60
  eax = ext_441a60_fastcall2(ecx, edx);  // @659_44ff60
  ecx = edx = 0;  // @660_44ff60
  edx = (u32)((EBP - 284) + 184);  // @661_44ff60
  ecx = (u32)((EBP - 284) + 136);  // @662_44ff60
  eax = ext_4de4f0_fastcall2(ecx, edx);  // @663_44ff60
  ecx = edx = 0;  // @664_44ff60
  PV[27] = (u32)(ecx);  // @665_44ff60
  eax = (u32)((EBP - 288) + 64);  // @666_44ff60
  PV[28] = (u32)(eax);  // @667_44ff60
  eax = (u32)((EBP - 292) + 144);  // @668_44ff60
  ecx = edi;  // @669_44ff60
  PV[29] = (u32)(eax);  // @670_44ff60
  eax = ext_44f8b0_thiscall4(ecx, PV[29], PV[28], (u32)(1106247680));  // @671_44ff60
  ecx = edx = 0;  // @672_44ff60
  L4506f8:;
  esi = (esi + 1);  // @674_44ff60
  FL[3] = esi;  // @675_44ff60
  FL[0] = esi; FL[1] = ebx;  // @676_44ff60
  if (FL[0] < FL[1]) goto L450600;  // @677_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 20), sizeof v); (u32)v; });  // @678_44ff60
  goto L4507e5;  // @679_44ff60
  L45070a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; });  // @681_44ff60
  FL[2] = (ecx & ecx);  // @682_44ff60
  if (FL[2] == 0) goto L4507e5;  // @683_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @684_44ff60
  edx = (u32)((EBP - 284) + 72);  // @685_44ff60
  PV[30] = (u32)(edx);  // @686_44ff60
  edx = (u32)((EBP - 288) + 188);  // @687_44ff60
  PV[31] = (u32)(edx);  // @688_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[31], PV[30]);  // @689_44ff60
  ecx = edx = 0;  // @690_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @691_44ff60
  ecx = (u32)((EBP - 284) + 96);  // @692_44ff60
  PV[32] = (u32)(ecx);  // @693_44ff60
  ecx = (u32)((EBP - 288) + 140);  // @694_44ff60
  PV[33] = (u32)(ecx);  // @695_44ff60
  ecx = edi;  // @696_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[33], PV[32]);  // @697_44ff60
  ecx = edx = 0;  // @698_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @699_44ff60
  edx = (u32)((EBP - 284) + 96);  // @700_44ff60
  ecx = (u32)((EBP - 284) + 72);  // @701_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 76) + 0), 4); v; });  // @702_44ff60
  X0[1] = 0;  // @703_44ff60
  X0[2] = 0;  // @704_44ff60
  X0[3] = 0;  // @705_44ff60
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @706_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 16) + 0), &X0[0], 4);  // @707_44ff60
  eax = ext_43e960_fastcall2(ecx, edx);  // @708_44ff60
  ecx = edx = 0;  // @709_44ff60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 72) + 0), 4); v; });  // @710_44ff60
  X1[1] = 0;  // @711_44ff60
  X1[2] = 0;  // @712_44ff60
  X1[3] = 0;  // @713_44ff60
  X0[0] = 0;  // @714_44ff60
  X0[1] = 0;  // @715_44ff60
  X0[2] = 0;  // @716_44ff60
  X0[3] = 0;  // @717_44ff60
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @718_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @719_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 80) + 0), 4); v; });  // @720_44ff60
  X0[1] = 0;  // @721_44ff60
  X0[2] = 0;  // @722_44ff60
  X0[3] = 0;  // @723_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @724_44ff60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @725_44ff60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 16) + 0), 4); v; });  // @726_44ff60
  X0[1] = 0;  // @727_44ff60
  X0[2] = 0;  // @728_44ff60
  X0[3] = 0;  // @729_44ff60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @730_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 12) + 0), &X1[0], 4);  // @731_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 12), sizeof v); (u32)v; });  // @732_44ff60
  __builtin_memcpy((void *)((u32)((EBP - 284) + 16) + 0), &X0[0], 4);  // @733_44ff60
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 16), sizeof v); (u32)v; });  // @734_44ff60
  if ((s32)FL[0] > (s32)FL[1]) goto L4507e5;  // @735_44ff60
  edx = (u32)((EBP - 284) + 136);  // @736_44ff60
  ecx = (u32)((EBP - 284) + 72);  // @737_44ff60
  eax = ext_441a60_fastcall2(ecx, edx);  // @738_44ff60
  ecx = edx = 0;  // @739_44ff60
  edx = (u32)((EBP - 284) + 136);  // @740_44ff60
  ecx = (u32)((EBP - 284) + 184);  // @741_44ff60
  eax = ext_4de4f0_fastcall2(ecx, edx);  // @742_44ff60
  ecx = edx = 0;  // @743_44ff60
  PV[34] = (u32)(ecx);  // @744_44ff60
  eax = (u32)((EBP - 288) + 76);  // @745_44ff60
  PV[35] = (u32)(eax);  // @746_44ff60
  eax = (u32)((EBP - 292) + 192);  // @747_44ff60
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
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 284) + 12), &v, sizeof v); }  // @790_44ff60
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
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 24), sizeof v); (u32)v; });  // @806_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 112)))(ecx, PV[39], (u32)(1), PV[38], PV[37]);  // @807_44ff60
  ecx = edx = 0;  // @808_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @809_44ff60
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 288) + 16), sizeof v); (u32)v; });  // @810_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @811_44ff60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @812_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @813_44ff60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[40], (u32)(1));  // @814_44ff60
  ecx = edx = 0;  // @815_44ff60
  ebx = (ebx + 1);  // @816_44ff60
  FL[3] = ebx;  // @817_44ff60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 284) + 12), &v, sizeof v); }  // @818_44ff60
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @819_44ff60
  if (FL[0] < FL[1]) goto L450850;  // @820_44ff60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 20), sizeof v); (u32)v; });  // @821_44ff60
  L4508a3:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 144), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @823_44ff60
  if (FL[0] == FL[1]) goto L450903;  // @824_44ff60
  esi = 0;  // @825_44ff60
  FL[3] = esi;  // @826_44ff60
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 136), sizeof v); (u32)v; }); FL[1] = esi;  // @827_44ff60
  if (FL[0] <= FL[1]) goto L450903;  // @828_44ff60
  L4508c0:;
  eax = (u32)((EBP - 284) + 220);  // @830_44ff60
  PV[41] = (u32)(eax);  // @831_44ff60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @832_44ff60
  ecx = (u32)((EBP - 288) + 100);  // @833_44ff60
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*2), sizeof v); (u32)v; });  // @834_44ff60
  eax = (u32)(eax + eax*2);  // @835_44ff60
  edx = (u32)(ebx + eax*4);  // @836_44ff60
  eax = ext_441970_fastcall3(ecx, edx, PV[41]);  // @837_44ff60
  ecx = edx = 0;  // @838_44ff60
  edx = (u32)((EBP - 284) + 108);  // @839_44ff60
  ecx = (u32)((EBP - 284) + 96);  // @840_44ff60
  eax = ext_441940_fastcall2(ecx, edx);  // @841_44ff60
  ecx = edx = 0;  // @842_44ff60
  ecx = (u32)((EBP - 284) + 136);  // @843_44ff60
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
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 952) + 36), &v, sizeof v); }  // @3_58ecd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 952) + 16), &v, sizeof v); }  // @4_58ecd0
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
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)((EBP - 952) + 23), &v, sizeof v); }  // @15_58ecd0
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
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 124), &v, sizeof v); }  // @36_58ecd0
  FL[2] = (eax & eax);  // @37_58ecd0
  if (FL[2] == 0) goto L58f607;  // @38_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_58ecd0
  ecx = edi;  // @40_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @41_58ecd0
  ecx = edx = 0;  // @42_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; });  // @43_58ecd0
  esi = eax;  // @44_58ecd0
  PV[0] = (u32)(esi);  // @45_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 960) + 36), &v, sizeof v); }  // @46_58ecd0
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
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 952) + 40), &v, sizeof v); }  // @72_58ecd0
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
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 964) + 52), &v, sizeof v); }  // @94_58ecd0
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @106_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 28), sizeof v); (u32)v; });  // @107_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 40), sizeof v); (u32)v; });  // @108_58ecd0
  L58ee41:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 800)))(ecx);  // @111_58ecd0
  ecx = edx = 0;  // @112_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @113_58ecd0
  ecx = edi;  // @114_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 24), &v, sizeof v); }  // @115_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 860)))(ecx);  // @116_58ecd0
  ecx = edx = 0;  // @117_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 136), &v, sizeof v); }  // @118_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; });  // @119_58ecd0
  ecx = eax;  // @120_58ecd0
  PV[5] = (u32)(esi);  // @121_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 960) + 40), &v, sizeof v); }  // @122_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @123_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 152)))(ecx, PV[5], (u32)(0));  // @124_58ecd0
  ecx = edx = 0;  // @125_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @126_58ecd0
  PV[6] = (u32)(eax);  // @127_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 956) + 128), &v, sizeof v); }  // @128_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @129_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[6]);  // @131_58ecd0
  ecx = edx = 0;  // @132_58ecd0
  FL[2] = (eax & eax);  // @133_58ecd0
  if (FL[2] == 0) goto L58ef02;  // @134_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_58ecd0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; });  // @136_58ecd0
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
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; });  // @156_58ecd0
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
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 32), &v, sizeof v); }  // @167_58ecd0
  L58eefe:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 28), sizeof v); (u32)v; });  // @169_58ecd0
  L58ef02:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 32), sizeof v); (u32)v; });  // @171_58ecd0
  ecx = (u32)(ebx + 2479);  // @172_58ecd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)((EBP - 952) + 24), &v, sizeof v); }  // @173_58ecd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @174_58ecd0
  PV[10] = (u32)(edi);  // @175_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[10]);  // @176_58ecd0
  ecx = edx = 0;  // @177_58ecd0
  PV[11] = (u32)(edi);  // @178_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 956) + 28), sizeof v); (u32)v; }); FL[1] = eax;  // @179_58ecd0
  if (FL[0] >= FL[1]) goto L58f4b0;  // @180_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @181_58ecd0
  eax = ext_470550_thiscall2(ecx, PV[11]);  // @182_58ecd0
  ecx = edx = 0;  // @183_58ecd0
  PV[12] = (u32)(edi);  // @184_58ecd0
  ecx = ebx;  // @185_58ecd0
  eax = ext_594540_thiscall2(ecx, PV[12]);  // @186_58ecd0
  ecx = edx = 0;  // @187_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @188_58ecd0
  ecx = (u32)(ebx + 2479);  // @189_58ecd0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 136), sizeof v); (u32)v; }));  // @190_58ecd0
  FL[3] = eax;  // @191_58ecd0
  PV[13] = (u32)(edi);  // @192_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 956) + 32), &v, sizeof v); }  // @193_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[13]);  // @194_58ecd0
  ecx = edx = 0;  // @195_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 28), sizeof v); (u32)v; }); FL[1] = eax;  // @196_58ecd0
  if (FL[0] >= FL[1]) goto L58ef5b;  // @197_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 28), sizeof v); (u32)v; });  // @198_58ecd0
  goto L58ef6b;  // @199_58ecd0
  L58ef5b:;
  PV[14] = (u32)(edi);  // @201_58ecd0
  ecx = (u32)(ebx + 2479);  // @202_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[14]);  // @203_58ecd0
  ecx = edx = 0;  // @204_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 28), &v, sizeof v); }  // @205_58ecd0
  L58ef6b:;
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; }));  // @207_58ecd0
  FL[3] = eax;  // @208_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 24), &v, sizeof v); }  // @209_58ecd0
  FL[2] = (eax & eax);  // @210_58ecd0
  if ((s32)FL[2] <= 0) goto L58f170;  // @211_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @212_58ecd0
  ecx = esi;  // @213_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 816)))(ecx);  // @214_58ecd0
  ecx = edx = 0;  // @215_58ecd0
  FL[0] = eax; FL[1] = (u32)(12);  // @216_58ecd0
  if (FL[0] != FL[1]) goto L58f022;  // @217_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @218_58ecd0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58efe3;  // @219_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @220_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @221_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @222_58ecd0
  ecx = edx = 0;  // @223_58ecd0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @224_58ecd0
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
  eax = (u32)((EBP - 956) + 192);  // @235_58ecd0
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
  edx = (u32)((EBP - 952) + 184);  // @248_58ecd0
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
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @265_58ecd0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58f054;  // @266_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @267_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @268_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @269_58ecd0
  ecx = edx = 0;  // @270_58ecd0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @271_58ecd0
  goto L58efac;  // @272_58ecd0
  L58f054:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @274_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @275_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @276_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @277_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999796), (u32)(6999776), PV[19]);  // @278_58ecd0
  ecx = edx = 0;  // @279_58ecd0
  edx = (u32)((EBP - 952) + 184);  // @280_58ecd0
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
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @295_58ecd0
  edi = (u32)(6801640);  // @296_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @297_58ecd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @298_58ecd0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58f114;  // @299_58ecd0
  FL[2] = (ecx & ecx);  // @300_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 136), &v, sizeof v); }  // @301_58ecd0
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
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 956) + 28), sizeof v); (u32)v; });  // @313_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @314_58ecd0
  ecx = esi;  // @315_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999816), PV[22], PV[21]);  // @316_58ecd0
  ecx = edx = 0;  // @317_58ecd0
  PV[23] = (u32)(eax);  // @318_58ecd0
  eax = (u32)((EBP - 956) + 196);  // @319_58ecd0
  PV[24] = (u32)(eax);  // @320_58ecd0
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 152), sizeof v); (u32)v; });  // @321_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 408)))(ecx, PV[25], PV[24], PV[23]);  // @322_58ecd0
  ecx = edx = 0;  // @323_58ecd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 56), sizeof v); (u32)v; });  // @324_58ecd0
  goto L58f1b5;  // @325_58ecd0
  L58f114:;
  FL[2] = (ecx & ecx);  // @327_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 136), &v, sizeof v); }  // @328_58ecd0
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
  eax = (u32)((EBP - 956) + 192);  // @345_58ecd0
  PV[29] = (u32)(eax);  // @346_58ecd0
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 148), sizeof v); (u32)v; });  // @347_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 408)))(ecx, PV[30], PV[29], PV[28]);  // @348_58ecd0
  ecx = edx = 0;  // @349_58ecd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 52), sizeof v); (u32)v; });  // @350_58ecd0
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
  eax = (u32)((EBP - 956) + 188);  // @366_58ecd0
  PV[32] = (u32)(eax);  // @367_58ecd0
  PV[33] = (u32)(esi);  // @368_58ecd0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 408)))(PV[33], PV[32], PV[31]);  // @369_58ecd0
  ecx = edx = 0;  // @370_58ecd0
  L58f1b5:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @372_58ecd0
  L58f1b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @374_58ecd0
  ecx = (u32)((EBP - 952) + 184);  // @375_58ecd0
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 40), sizeof v); (u32)v; });  // @387_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 28), sizeof v); (u32)v; });  // @388_58ecd0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 32), sizeof v); (u32)v; }));  // @389_58ecd0
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
  ecx = (u32)((EBP - 952) + 136);  // @406_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 136), &v, sizeof v); }  // @407_58ecd0
  { u32 v = (u32)((u32)(6999856)); __builtin_memcpy((void *)(u32)((EBP - 952) + 140), &v, sizeof v); }  // @408_58ecd0
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
  eax = (u32)((EBP - 952) + 128);  // @473_58ecd0
  PV[40] = (u32)(eax);  // @474_58ecd0
  eax = (u32)((EBP - 956) + 48);  // @475_58ecd0
  PV[41] = (u32)(eax);  // @476_58ecd0
  eax = (u32)((EBP - 960) + 132);  // @477_58ecd0
  PV[42] = (u32)(eax);  // @478_58ecd0
  eax = (u32)((EBP - 964) + 52);  // @479_58ecd0
  PV[43] = (u32)(eax);  // @480_58ecd0
  ecx = (u32)(ebx + 2479);  // @481_58ecd0
  eax = ext_5afd00_thiscall5(ecx, PV[43], PV[42], PV[41], PV[40]);  // @482_58ecd0
  ecx = edx = 0;  // @483_58ecd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @484_58ecd0
  if (FL[2] == 0) goto L58f4af;  // @485_58ecd0
  esi = 0;  // @486_58ecd0
  FL[3] = esi;  // @487_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 952) + 32), &v, sizeof v); }  // @488_58ecd0
  L58f302:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @490_58ecd0
  if (FL[0] == FL[1]) goto L58f442;  // @491_58ecd0
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + esi + 40), sizeof v); (u32)v; });  // @492_58ecd0
  ecx = (u32)(ebx + 2395);  // @493_58ecd0
  eax = ext_5af130_fastcall3(ecx, edx, PV[44]);  // @494_58ecd0
  edx = 0;  // @495_58ecd0
  edi = eax;  // @496_58ecd0
  FL[2] = (edi & edi);  // @497_58ecd0
  if (FL[2] == 0) goto L58f442;  // @498_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @499_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @500_58ecd0
  if (FL[0] <= FL[1]) goto L58f3a8;  // @501_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @502_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 400)))(ecx);  // @503_58ecd0
  ecx = edx = 0;  // @504_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @505_58ecd0
  esi = (u32)(6801640);  // @506_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @507_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 136), &v, sizeof v); }  // @508_58ecd0
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
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 32), sizeof v); (u32)v; });  // @520_58ecd0
  ecx = edi;  // @521_58ecd0
  PV[46] = (u32)(eax);  // @522_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @523_58ecd0
  PV[47] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 956) + esi + 128), sizeof v); (u32)v; });  // @524_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999816), PV[47], PV[46]);  // @525_58ecd0
  ecx = edx = 0;  // @526_58ecd0
  PV[48] = (u32)(eax);  // @527_58ecd0
  eax = (u32)((EBP - 956) + 708);  // @528_58ecd0
  PV[49] = (u32)(eax);  // @529_58ecd0
  PV[50] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 152), sizeof v); (u32)v; });  // @530_58ecd0
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
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 136), &v, sizeof v); }  // @541_58ecd0
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
  eax = (u32)((EBP - 956) + 704);  // @559_58ecd0
  PV[54] = (u32)(eax);  // @560_58ecd0
  PV[55] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 960) + 148), sizeof v); (u32)v; });  // @561_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 408)))(ecx, PV[55], PV[54], PV[53]);  // @562_58ecd0
  ecx = edx = 0;  // @563_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 48), sizeof v); (u32)v; });  // @564_58ecd0
  L58f414:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 36), sizeof v); (u32)v; });  // @566_58ecd0
  ecx = (u32)((EBP - 952) + 696);  // @567_58ecd0
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
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 952) + 32), &v, sizeof v); }  // @583_58ecd0
  FL[0] = esi; FL[1] = (u32)(8);  // @584_58ecd0
  if ((s32)FL[0] < (s32)FL[1]) goto L58f302;  // @585_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @586_58ecd0
  ecx = ebx;  // @587_58ecd0
  PV[58] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3850), sizeof v); (u32)v; });  // @588_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1012)))(ecx, PV[58]);  // @589_58ecd0
  ecx = edx = 0;  // @590_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @591_58ecd0
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
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 952) + 124), &v, sizeof v); }  // @662_58ecd0
  goto L58f535;  // @663_58ecd0
  L58f51a:;
  ecx = (u32)(ebx + 2479);  // @665_58ecd0
  eax = ext_5afe20_thiscall2(ecx, (u32)(13));  // @666_58ecd0
  ecx = edx = 0;  // @667_58ecd0
  esi = eax;  // @668_58ecd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 952) + 124), &v, sizeof v); }  // @669_58ecd0
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
  PV[64] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; });  // @691_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @692_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @693_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @694_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @695_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6973416), (u32)(6999776), PV[64]);  // @696_58ecd0
  ecx = edx = 0;  // @697_58ecd0
  PV[65] = (u32)(eax);  // @698_58ecd0
  eax = (u32)((EBP - 956) + 192);  // @699_58ecd0
  PV[66] = (u32)(eax);  // @700_58ecd0
  PV[67] = (u32)(esi);  // @701_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 408)))(ecx, PV[67], PV[66], PV[65]);  // @702_58ecd0
  ecx = edx = 0;  // @703_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 32), sizeof v); (u32)v; });  // @704_58ecd0
  goto L58f5dd;  // @705_58ecd0
  L58f5a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @707_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @708_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @709_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @710_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6999796));  // @711_58ecd0
  ecx = edx = 0;  // @712_58ecd0
  edx = (u32)((EBP - 952) + 184);  // @713_58ecd0
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
  ecx = (u32)((EBP - 952) + 184);  // @724_58ecd0
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
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 956) + 28), &v, sizeof v); }  // @744_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @745_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @746_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[70]);  // @747_58ecd0
  ecx = edx = 0;  // @748_58ecd0
  ecx = (u32)(ebx + 2479);  // @749_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 32), &v, sizeof v); }  // @750_58ecd0
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
  ecx = (u32)((EBP - 952) + 124);  // @767_58ecd0
  PV[73] = (u32)(ecx);  // @768_58ecd0
  ecx = edi;  // @769_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 956) + 128), &v, sizeof v); }  // @770_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 956) + 132), &v, sizeof v); }  // @771_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 956) + 136), &v, sizeof v); }  // @772_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[73]);  // @773_58ecd0
  ecx = edx = 0;  // @774_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @775_58ecd0
  ecx = (u32)((EBP - 952) + 124);  // @776_58ecd0
  PV[74] = (u32)(ecx);  // @777_58ecd0
  ecx = ebx;  // @778_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[74]);  // @779_58ecd0
  ecx = edx = 0;  // @780_58ecd0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 952) + 124) + 0), 4); v; });  // @781_58ecd0
  X1[1] = 0;  // @782_58ecd0
  X1[2] = 0;  // @783_58ecd0
  X1[3] = 0;  // @784_58ecd0
  X0[0] = 0;  // @785_58ecd0
  X0[1] = 0;  // @786_58ecd0
  X0[2] = 0;  // @787_58ecd0
  X0[3] = 0;  // @788_58ecd0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @789_58ecd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 128), &v, sizeof v); }  // @790_58ecd0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @791_58ecd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 952) + 132) + 0), 4); v; });  // @792_58ecd0
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
  ecx = (u32)((EBP - 952) + 136);  // @827_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 136), &v, sizeof v); }  // @828_58ecd0
  { u32 v = (u32)((u32)(6999856)); __builtin_memcpy((void *)(u32)((EBP - 952) + 140), &v, sizeof v); }  // @829_58ecd0
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
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 23), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @842_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 952) + 15), &v, sizeof v); }  // @843_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 22), &v, sizeof v); }  // @844_58ecd0
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
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 964) + 148), &v, sizeof v); }  // @890_58ecd0
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @903_58ecd0
  L58f826:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @905_58ecd0
  ecx = esi;  // @906_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 800)))(ecx);  // @907_58ecd0
  ecx = edx = 0;  // @908_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @909_58ecd0
  ecx = edi;  // @910_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 136), &v, sizeof v); }  // @911_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 868)))(ecx);  // @912_58ecd0
  ecx = edx = 0;  // @913_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @914_58ecd0
  ecx = edi;  // @915_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 952) + 36), &v, sizeof v); }  // @916_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 860)))(ecx);  // @917_58ecd0
  ecx = edx = 0;  // @918_58ecd0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 36), sizeof v); (u32)v; }));  // @919_58ecd0
  FL[3] = eax;  // @920_58ecd0
  ecx = (u32)(ebx + 2479);  // @921_58ecd0
  PV[80] = (u32)(edi);  // @922_58ecd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 956) + 128), &v, sizeof v); }  // @923_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[80]);  // @924_58ecd0
  ecx = edx = 0;  // @925_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 136), sizeof v); (u32)v; });  // @926_58ecd0
  FL[0] = ecx; FL[1] = eax;  // @927_58ecd0
  if ((s32)FL[0] >= (s32)FL[1]) goto L58f8d5;  // @928_58ecd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; }) + ecx)); __builtin_memcpy((void *)(u32)((EBP - 952) + 124), &v, sizeof v); }  // @929_58ecd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; });  // @930_58ecd0
  ecx = (u32)(ebx + 2479);  // @931_58ecd0
  PV[81] = (u32)(edi);  // @932_58ecd0
  eax = ext_5afc70_thiscall2(ecx, PV[81]);  // @933_58ecd0
  ecx = edx = 0;  // @934_58ecd0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 36), sizeof v); (u32)v; }));  // @935_58ecd0
  FL[3] = eax;  // @936_58ecd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; }); FL[1] = eax;  // @937_58ecd0
  if ((s32)FL[0] >= (s32)FL[1]) goto L58f8a7;  // @938_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 124), sizeof v); (u32)v; });  // @939_58ecd0
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
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 36), sizeof v); (u32)v; }));  // @955_58ecd0
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
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @972_58ecd0
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
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @984_58ecd0
  if (FL[0] == FL[1]) goto L58f9fb;  // @985_58ecd0
  ecx = ebx;  // @986_58ecd0
  eax = ext_591080_thiscall1(ecx);  // @987_58ecd0
  ecx = edx = 0;  // @988_58ecd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @989_58ecd0
  esi = eax;  // @990_58ecd0
  eax = (u32)((EBP - 952) + 136);  // @991_58ecd0
  ecx = ebx;  // @992_58ecd0
  PV[86] = (u32)(eax);  // @993_58ecd0
  eax = (u32)((EBP - 956) + 152);  // @994_58ecd0
  PV[87] = (u32)(eax);  // @995_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[87], PV[86]);  // @996_58ecd0
  ecx = edx = 0;  // @997_58ecd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 952) + 140) + 0), 4); v; });  // @998_58ecd0
  X0[1] = 0;  // @999_58ecd0
  X0[2] = 0;  // @1000_58ecd0
  X0[3] = 0;  // @1001_58ecd0
  ecx = (u32)((EBP - 952) + 136);  // @1002_58ecd0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860564) + 0), 4); v; })));  // @1003_58ecd0
  PV[88] = (u32)(ecx);  // @1004_58ecd0
  ecx = (u32)((EBP - 956) + 152);  // @1005_58ecd0
  PV[89] = (u32)(ecx);  // @1006_58ecd0
  ecx = esi;  // @1007_58ecd0
  __builtin_memcpy((void *)((u32)((EBP - 960) + 148) + 0), &X0[0], 4);  // @1008_58ecd0
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
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @1021_58ecd0
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @1046_58ecd0
  PV[94] = (u32)(eax);  // @1047_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[94]);  // @1048_58ecd0
  ecx = edx = 0;  // @1049_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1050_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1051_58ecd0
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
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 15), &v, sizeof v); }  // @1070_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 952) + 22), &v, sizeof v); }  // @1071_58ecd0
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1118_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 952) + 22), &v, sizeof v); }  // @1119_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 15), &v, sizeof v); }  // @1120_58ecd0
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @1135_58ecd0
  PV[107] = (u32)(eax);  // @1136_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[107]);  // @1137_58ecd0
  ecx = edx = 0;  // @1138_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1139_58ecd0
  ecx = ebx;  // @1140_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1312)))(ecx, (u32)(0));  // @1141_58ecd0
  ecx = edx = 0;  // @1142_58ecd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @1143_58ecd0
  ecx = esi;  // @1144_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1145_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @1146_58ecd0
  ecx = edx = 0;  // @1147_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1148_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1149_58ecd0
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
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 952) + 22), &v, sizeof v); }  // @1168_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 15), &v, sizeof v); }  // @1169_58ecd0
  goto L58fd29;  // @1170_58ecd0
  L58fb0b:;
  PV[112] = (u32)(edi);  // @1172_58ecd0
  ecx = (u32)(ebx + 2395);  // @1173_58ecd0
  eax = ext_5aeff0_thiscall2(ecx, PV[112]);  // @1174_58ecd0
  ecx = edx = 0;  // @1175_58ecd0
  FL[0] = eax; FL[1] = (u32)(3);  // @1176_58ecd0
  if (FL[0] == FL[1]) goto L58fb26;  // @1177_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 23), &v, sizeof v); }  // @1178_58ecd0
  FL[0] = eax; FL[1] = (u32)(4);  // @1179_58ecd0
  if (FL[0] != FL[1]) goto L58fb2b;  // @1180_58ecd0
  L58fb26:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 952) + 23), &v, sizeof v); }  // @1182_58ecd0
  L58fb2b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2130), sizeof v); (u32)v; });  // @1184_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1185_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 144)))(ecx);  // @1186_58ecd0
  ecx = edx = 0;  // @1187_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2130), sizeof v); (u32)v; });  // @1188_58ecd0
  eax = (u32)((EBP - 952) + 48);  // @1189_58ecd0
  PV[113] = (u32)(eax);  // @1190_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 7439), sizeof v); (u32)v; });  // @1191_58ecd0
  eax = ext_596710_thiscall2(ecx, PV[113]);  // @1192_58ecd0
  ecx = edx = 0;  // @1193_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 105), sizeof v); (u32)v; });  // @1194_58ecd0
  FL[2] = (eax & eax);  // @1195_58ecd0
  if (FL[2] == 0) goto L58fbc0;  // @1196_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 23), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1197_58ecd0
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
  ecx = (u32)((EBP - 952) + 136);  // @1209_58ecd0
  PV[114] = (u32)(ecx);  // @1210_58ecd0
  ecx = (u32)((EBP - 956) + 152);  // @1211_58ecd0
  PV[115] = (u32)(ecx);  // @1212_58ecd0
  ecx = ebx;  // @1213_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[115], PV[114]);  // @1214_58ecd0
  ecx = edx = 0;  // @1215_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 105), sizeof v); (u32)v; });  // @1216_58ecd0
  edx = (u32)((EBP - 952) + 136);  // @1217_58ecd0
  PV[116] = (u32)(edx);  // @1218_58ecd0
  edx = (u32)((EBP - 956) + 152);  // @1219_58ecd0
  PV[117] = (u32)(edx);  // @1220_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1221_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[117], PV[116]);  // @1222_58ecd0
  ecx = edx = 0;  // @1223_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1224_58ecd0
  ecx = ebx;  // @1225_58ecd0
  PV[118] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 105), sizeof v); (u32)v; });  // @1226_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1268)))(ecx, PV[118]);  // @1227_58ecd0
  ecx = edx = 0;  // @1228_58ecd0
  PV[119] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 105), sizeof v); (u32)v; });  // @1229_58ecd0
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
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 23), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1246_58ecd0
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1275_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 15), &v, sizeof v); }  // @1276_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 952) + 22), &v, sizeof v); }  // @1277_58ecd0
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @1293_58ecd0
  PV[126] = (u32)(eax);  // @1294_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[126]);  // @1295_58ecd0
  ecx = edx = 0;  // @1296_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1297_58ecd0
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
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 15), &v, sizeof v); }  // @1310_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 952) + 22), &v, sizeof v); }  // @1311_58ecd0
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 24), sizeof v); (u32)v; });  // @1329_58ecd0
  PV[131] = (u32)(eax);  // @1330_58ecd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 752)))(ecx, PV[131]);  // @1331_58ecd0
  ecx = edx = 0;  // @1332_58ecd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1333_58ecd0
  ecx = edi;  // @1334_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1335_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @1336_58ecd0
  ecx = edx = 0;  // @1337_58ecd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 952) + 22), &v, sizeof v); }  // @1338_58ecd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 952) + 15), &v, sizeof v); }  // @1339_58ecd0
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1361_58ecd0
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
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1399_58ecd0
  if (FL[0] != FL[1]) goto L58fd86;  // @1400_58ecd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1401_58ecd0
  if (FL[0] == FL[1]) goto L58f496;  // @1402_58ecd0
  L58fd86:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1404_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1405_58ecd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @1406_58ecd0
  ecx = edx = 0;  // @1407_58ecd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1408_58ecd0
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
  eax = (u32)((EBP - 960) + 192);  // @1426_58ecd0
  PV[138] = (u32)(eax);  // @1427_58ecd0
  PV[139] = (u32)(edi);  // @1428_58ecd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 408)))(ecx, PV[139], PV[138], (u32)(6779752), PV[137]);  // @1429_58ecd0
  ecx = edx = 0;  // @1430_58ecd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @1431_58ecd0
  ecx = (u32)((EBP - 952) + 200);  // @1432_58ecd0
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1444_58ecd0
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
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1506_58ecd0
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
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 952) + 16), sizeof v); (u32)v; });  // @1518_58ecd0
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
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 956) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1538_58ecd0
  if (FL[0] == FL[1]) goto L58f496;  // @1539_58ecd0
  PV[149] = (u32)(edi);  // @1540_58ecd0
  ecx = ebx;  // @1541_58ecd0
  eax = ext_4730b0_thiscall2(ecx, PV[149]);  // @1542_58ecd0
  ecx = edx = 0;  // @1543_58ecd0
  ext_633654(G(u32, 0x6f5630));  // @1544_58ecd0
  return eax;  // @1545_58ecd0
}
PCREG(58ecd0, lifted_58ecd0);

