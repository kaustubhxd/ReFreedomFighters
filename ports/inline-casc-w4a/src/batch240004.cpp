// batch240004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_663d90(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @0_663d90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_663d90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 12) + 0), 4); v; });  // @2_663d90
  X0[1] = 0;  // @3_663d90
  X0[2] = 0;  // @4_663d90
  X0[3] = 0;  // @5_663d90
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; });  // @6_663d90
  X5[1] = 0;  // @7_663d90
  X5[2] = 0;  // @8_663d90
  X5[3] = 0;  // @9_663d90
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 20) + 0), 4); v; });  // @10_663d90
  X4[1] = 0;  // @11_663d90
  X4[2] = 0;  // @12_663d90
  X4[3] = 0;  // @13_663d90
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + eax*4) + 0), 4); v; });  // @14_663d90
  X3[1] = 0;  // @15_663d90
  X3[2] = 0;  // @16_663d90
  X3[3] = 0;  // @17_663d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_663d90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 44) + 0), 4); v; });  // @19_663d90
  X1[1] = 0;  // @20_663d90
  X1[2] = 0;  // @21_663d90
  X1[3] = 0;  // @22_663d90
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @23_663d90
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + eax*4) + 0), 4); v; })));  // @24_663d90
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + eax*4) + 0), 4); v; })));  // @25_663d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @26_663d90
  X5[0] = F2U(U2F(X5[0]) + U2F(X0[0]));  // @27_663d90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 24) + 0), 4); v; });  // @28_663d90
  X0[1] = 0;  // @29_663d90
  X0[2] = 0;  // @30_663d90
  X0[3] = 0;  // @31_663d90
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @32_663d90
  X5[0] = F2U(U2F(X5[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 16) + 0), 4); v; })));  // @33_663d90
  X4[0] = F2U(U2F(X4[0]) + U2F(X0[0]));  // @34_663d90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 52) + 0), 4); v; });  // @35_663d90
  X0[1] = 0;  // @36_663d90
  X0[2] = 0;  // @37_663d90
  X0[3] = 0;  // @38_663d90
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 32) + 0), 4); v; })));  // @39_663d90
  X4[0] = F2U(U2F(X4[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 28) + 0), 4); v; })));  // @40_663d90
  X1[0] = F2U(U2F(X1[0]) * U2F(X5[0]));  // @41_663d90
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 32) + 0), 4); v; })));  // @42_663d90
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 36) + 0), 4); v; })));  // @43_663d90
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @44_663d90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @45_663d90
  __builtin_memcpy((void *)((u32)(eax) + 0), &X1[0], 4);  // @46_663d90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 48) + 0), 4); v; });  // @47_663d90
  X1[1] = 0;  // @48_663d90
  X1[2] = 0;  // @49_663d90
  X1[3] = 0;  // @50_663d90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 56) + 0), 4); v; });  // @51_663d90
  X0[1] = 0;  // @52_663d90
  X0[2] = 0;  // @53_663d90
  X0[3] = 0;  // @54_663d90
  X1[0] = F2U(U2F(X1[0]) * U2F(X5[0]));  // @55_663d90
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @56_663d90
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 40) + 0), 4); v; })));  // @57_663d90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @58_663d90
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X1[0], 4);  // @59_663d90
  return eax;  // @60_663d90
}
PCREG(663d90, lifted_663d90);

extern "C" u32 THISCALL lifted_663bf0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_663bf0
  edx = ecx;  // @1_663bf0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X3[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X3[2] = X3[3] = 0;  // @2_663bf0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @3_663bf0
  X1[1] = 0;  // @4_663bf0
  X1[2] = 0;  // @5_663bf0
  X1[3] = 0;  // @6_663bf0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @7_663bf0
  X2[1] = 0;  // @8_663bf0
  X2[2] = 0;  // @9_663bf0
  X2[3] = 0;  // @10_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @11_663bf0
  X0[1] = 0;  // @12_663bf0
  X0[2] = 0;  // @13_663bf0
  X0[3] = 0;  // @14_663bf0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @15_663bf0
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X2[0], a_); SD(&X2[2], b_); }  // @16_663bf0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @17_663bf0
  X1[0] = X1[0] & X3[0];  // @18_663bf0
  X1[1] = X1[1] & X3[1];  // @19_663bf0
  X1[2] = X1[2] & X3[2];  // @20_663bf0
  X1[3] = X1[3] & X3[3];  // @21_663bf0
  X2[0] = X2[0] & X3[0];  // @22_663bf0
  X2[1] = X2[1] & X3[1];  // @23_663bf0
  X2[2] = X2[2] & X3[2];  // @24_663bf0
  X2[3] = X2[3] & X3[3];  // @25_663bf0
  X0[0] = X0[0] & X3[0];  // @26_663bf0
  X0[1] = X0[1] & X3[1];  // @27_663bf0
  X0[2] = X0[2] & X3[2];  // @28_663bf0
  X0[3] = X0[3] & X3[3];  // @29_663bf0
  if (((!(U2D(X1[0], X1[1]) >= U2D(X2[0], X2[1]))) || (!((U2D(X1[0], X1[1]) < U2D(X2[0], X2[1])) || (U2D(X1[0], X1[1]) > U2D(X2[0], X2[1])))))) goto L663c36;  // @30_663bf0
  if (((!(U2D(X1[0], X1[1]) >= U2D(X0[0], X0[1]))) || (!((U2D(X1[0], X1[1]) < U2D(X0[0], X0[1])) || (U2D(X1[0], X1[1]) > U2D(X0[0], X0[1])))))) goto L663c43;  // @31_663bf0
  eax = (u32)(1);  // @32_663bf0
  ecx = (u32)(eax + 1);  // @33_663bf0
  goto L663c4a;  // @34_663bf0
  L663c36:;
  if (((!(U2D(X2[0], X2[1]) >= U2D(X0[0], X0[1]))) || (!((U2D(X2[0], X2[1]) < U2D(X0[0], X0[1])) || (U2D(X2[0], X2[1]) > U2D(X0[0], X0[1])))))) goto L663c43;  // @36_663bf0
  eax = 0;  // @37_663bf0
  FL[3] = eax;  // @38_663bf0
  ecx = (u32)(eax + 2);  // @39_663bf0
  goto L663c4a;  // @40_663bf0
  L663c43:;
  ecx = (u32)(1);  // @42_663bf0
  eax = 0;  // @43_663bf0
  FL[3] = eax;  // @44_663bf0
  L663c4a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @46_663bf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @47_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836856) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836856) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @48_663bf0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx*4) + 0), 4); v; });  // @49_663bf0
  X2[1] = 0;  // @50_663bf0
  X2[2] = 0;  // @51_663bf0
  X2[3] = 0;  // @52_663bf0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + ecx*4) + 0), 4); v; });  // @53_663bf0
  X1[1] = 0;  // @54_663bf0
  X1[2] = 0;  // @55_663bf0
  X1[3] = 0;  // @56_663bf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @57_663bf0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + ecx*4) + 0), 4); v; });  // @58_663bf0
  X4[1] = 0;  // @59_663bf0
  X4[2] = 0;  // @60_663bf0
  X4[3] = 0;  // @61_663bf0
  X4[0] = F2U(U2F(X4[0]) - U2F(X1[0]));  // @62_663bf0
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @63_663bf0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + ecx*4) + 0), 4); v; })));  // @64_663bf0
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax*4) + 0), 4); v; })));  // @65_663bf0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4) + 0), 4); v; })));  // @66_663bf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @67_663bf0
  X4[0] = F2U(U2F(X4[0]) + U2F(X1[0]));  // @68_663bf0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4) + 0), 4); v; })));  // @69_663bf0
  X4[0] = F2U(U2F(X4[0]) + U2F(X2[0]));  // @70_663bf0
  { double a_ = (double)U2F(X4[0]), b_ = (double)U2F(X4[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @71_663bf0
  X1[0] = X1[0] & X3[0];  // @72_663bf0
  X1[1] = X1[1] & X3[1];  // @73_663bf0
  X1[2] = X1[2] & X3[2];  // @74_663bf0
  X1[3] = X1[3] & X3[3];  // @75_663bf0
  if (((!(U2D(X0[0], X0[1]) >= U2D(X1[0], X1[1]))) || (!((U2D(X0[0], X0[1]) < U2D(X1[0], X1[1])) || (U2D(X0[0], X0[1]) > U2D(X1[0], X1[1])))))) goto L663ca8;  // @76_663bf0
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @77_663bf0
  goto L663cb9;  // @78_663bf0
  L663ca8:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @80_663bf0
  X0[1] = 0;  // @81_663bf0
  X0[2] = 0;  // @82_663bf0
  X0[3] = 0;  // @83_663bf0
  X0[0] = F2U(U2F(X0[0]) / U2F(X4[0]));  // @84_663bf0
  __builtin_memcpy((void *)((u32)(edx + 32) + 0), &X0[0], 4);  // @85_663bf0
  L663cb9:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + ecx*4) + 0), 4); v; });  // @87_663bf0
  X0[1] = 0;  // @88_663bf0
  X0[2] = 0;  // @89_663bf0
  X0[3] = 0;  // @90_663bf0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx*4) + 0), 4); v; })));  // @91_663bf0
  __builtin_memcpy((void *)((u32)(edx + 8) + 0), &X0[0], 4);  // @92_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax*4) + 0), 4); v; });  // @93_663bf0
  X0[1] = 0;  // @94_663bf0
  X0[2] = 0;  // @95_663bf0
  X0[3] = 0;  // @96_663bf0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4) + 0), 4); v; })));  // @97_663bf0
  __builtin_memcpy((void *)((u32)(edx + 12) + 0), &X0[0], 4);  // @98_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax*4) + 0), 4); v; });  // @99_663bf0
  X0[1] = 0;  // @100_663bf0
  X0[2] = 0;  // @101_663bf0
  X0[3] = 0;  // @102_663bf0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + ecx*4) + 0), 4); v; })));  // @103_663bf0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx*4) + 0), 4); v; });  // @104_663bf0
  X1[1] = 0;  // @105_663bf0
  X1[2] = 0;  // @106_663bf0
  X1[3] = 0;  // @107_663bf0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4) + 0), 4); v; })));  // @108_663bf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @109_663bf0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @110_663bf0
  __builtin_memcpy((void *)((u32)(edx + 16) + 0), &X1[0], 4);  // @111_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx*4) + 0), 4); v; });  // @112_663bf0
  X0[1] = 0;  // @113_663bf0
  X0[2] = 0;  // @114_663bf0
  X0[3] = 0;  // @115_663bf0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + ecx*4) + 0), 4); v; })));  // @116_663bf0
  __builtin_memcpy((void *)((u32)(edx + 20) + 0), &X0[0], 4);  // @117_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4) + 0), 4); v; });  // @118_663bf0
  X0[1] = 0;  // @119_663bf0
  X0[2] = 0;  // @120_663bf0
  X0[3] = 0;  // @121_663bf0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax*4) + 0), 4); v; })));  // @122_663bf0
  __builtin_memcpy((void *)((u32)(edx + 24) + 0), &X0[0], 4);  // @123_663bf0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax*4) + 0), 4); v; });  // @124_663bf0
  X1[1] = 0;  // @125_663bf0
  X1[2] = 0;  // @126_663bf0
  X1[3] = 0;  // @127_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx*4) + 0), 4); v; });  // @128_663bf0
  X0[1] = 0;  // @129_663bf0
  X0[2] = 0;  // @130_663bf0
  X0[3] = 0;  // @131_663bf0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4) + 0), 4); v; })));  // @132_663bf0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + ecx*4) + 0), 4); v; })));  // @133_663bf0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @134_663bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @135_663bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @136_663bf0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @137_663bf0
  __builtin_memcpy((void *)((u32)(edx + 28) + 0), &X1[0], 4);  // @138_663bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @139_663bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 36), &v, sizeof v); }  // @140_663bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @141_663bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 40), &v, sizeof v); }  // @142_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @143_663bf0
  X0[1] = 0;  // @144_663bf0
  X0[2] = 0;  // @145_663bf0
  X0[3] = 0;  // @146_663bf0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; })));  // @147_663bf0
  __builtin_memcpy((void *)((u32)(edx + 44) + 0), &X0[0], 4);  // @148_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; });  // @149_663bf0
  X0[1] = 0;  // @150_663bf0
  X0[2] = 0;  // @151_663bf0
  X0[3] = 0;  // @152_663bf0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 12) + 0), 4); v; })));  // @153_663bf0
  __builtin_memcpy((void *)((u32)(edx + 48) + 0), &X0[0], 4);  // @154_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 16) + 0), 4); v; });  // @155_663bf0
  X0[1] = 0;  // @156_663bf0
  X0[2] = 0;  // @157_663bf0
  X0[3] = 0;  // @158_663bf0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; })));  // @159_663bf0
  __builtin_memcpy((void *)((u32)(edx + 52) + 0), &X0[0], 4);  // @160_663bf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 20) + 0), 4); v; });  // @161_663bf0
  X0[1] = 0;  // @162_663bf0
  X0[2] = 0;  // @163_663bf0
  X0[3] = 0;  // @164_663bf0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 12) + 0), 4); v; })));  // @165_663bf0
  __builtin_memcpy((void *)((u32)(edx + 56) + 0), &X0[0], 4);  // @166_663bf0
  return eax;  // @167_663bf0
}
PCREG(663bf0, lifted_663bf0);

extern "C" u32 THISCALL lifted_634e90(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_634e90
  esi = ecx;  // @1_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @2_634e90
  eax = (~eax);  // @3_634e90
  eax = (eax & (u32)(344));  // @4_634e90
  FL[3] = eax;  // @5_634e90
  ebx = (ebx & eax);  // @6_634e90
  FL[3] = ebx;  // @7_634e90
  if (FL[3] == 0) goto L634f82;  // @8_634e90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) | ebx)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @9_634e90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @10_634e90
  eax = 0;  // @11_634e90
  FL[3] = eax;  // @12_634e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @13_634e90
  FL[2] = (ecx & ecx);  // @14_634e90
  if (FL[2] == 0) goto L634ebe;  // @15_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @16_634e90
  goto L634ed6;  // @17_634e90
  L634ebe:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @19_634e90
  FL[2] = (edx & edx);  // @20_634e90
  if (FL[2] == 0) goto L634ed6;  // @21_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_634e90
  PV[0] = (u32)(edx);  // @23_634e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_634e90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[0]);  // @26_634e90
  ecx = edx = 0;  // @27_634e90
  L634ed6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @29_634e90
  eax = (eax >> (u32)(10));  // @30_634e90
  FL[3] = eax;  // @31_634e90
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @32_634e90
  FL[2] = ((eax & 0xff) & (u32)(1));  // @33_634e90
  if (FL[2] == 0) goto L634f82;  // @34_634e90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) | ebx)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @35_634e90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @36_634e90
  FL[2] = ((ebx & 0xff) & (u32)(8));  // @37_634e90
  if (FL[2] == 0) goto L634f6d;  // @38_634e90
  edx = (u32)(esi + 16);  // @39_634e90
  eax = (u32)(EBP - 4);  // @40_634e90
  FL[0] = edx; FL[1] = eax;  // @41_634e90
  if (FL[0] == FL[1]) goto L634f24;  // @42_634e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @44_634e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; });  // @45_634e90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2784) + 0), 4); v; });  // @46_634e90
  X0[1] = 0;  // @47_634e90
  X0[2] = 0;  // @48_634e90
  X0[3] = 0;  // @49_634e90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; })));  // @50_634e90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @51_634e90
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @52_634e90
  ecx = (ecx - eax);  // @53_634e90
  FL[3] = ecx;  // @54_634e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @55_634e90
  L634f24:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @58_634e90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2784) + 0), 4); v; });  // @59_634e90
  X0[1] = 0;  // @60_634e90
  X0[2] = 0;  // @61_634e90
  X0[3] = 0;  // @62_634e90
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @63_634e90
  __builtin_memcpy((void *)((u32)(eax + 2784) + 0), &X0[0], 4);  // @64_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @66_634e90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2784) + 0), 4); v; });  // @67_634e90
  X0[1] = 0;  // @68_634e90
  X0[2] = 0;  // @69_634e90
  X0[3] = 0;  // @70_634e90
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))) goto L634f6d;  // @71_634e90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 2784), &v, sizeof v); }  // @72_634e90
  L634f6d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_634e90
  PV[1] = (u32)(ebx);  // @75_634e90
  PV[2] = (u32)(esi);  // @76_634e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @77_634e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_634e90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 332)))(ecx, PV[2], PV[1]);  // @79_634e90
  ecx = edx = 0;  // @80_634e90
  L634f82:;
  return eax;  // @82_634e90
}
PCREG(634e90, lifted_634e90);

extern "C" u32 lifted_6332d0(void) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @0_6332d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @2_6332d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3_6332d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @4_6332d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @5_6332d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 52), sizeof v); (u32)v; });  // @6_6332d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @7_6332d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @8_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @9_6332d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @10_6332d0
  FL[0] = edi; FL[1] = edx;  // @11_6332d0
  if (FL[0] >= FL[1]) goto L633305;  // @12_6332d0
  edx = (edx - edi);  // @13_6332d0
  FL[3] = edx;  // @14_6332d0
  edx = (edx - 1);  // @15_6332d0
  FL[3] = edx;  // @16_6332d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @17_6332d0
  goto L63330d;  // @18_6332d0
  L633305:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @20_6332d0
  ecx = (ecx - edi);  // @21_6332d0
  FL[3] = ecx;  // @22_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @23_6332d0
  L63330d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx*4 + 7296488), sizeof v); (u32)v; });  // @26_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @27_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @28_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx*4 + 7296488), sizeof v); (u32)v; });  // @29_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @30_6332d0
  L633327:;
  FL[0] = eax; FL[1] = (u32)(20);  // @32_6332d0
  if (FL[0] >= FL[1]) goto L63334c;  // @33_6332d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @34_6332d0
  L633330:;
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @36_6332d0
  ecx = eax;  // @37_6332d0
  edx = (edx << (ecx & 0xff));  // @38_6332d0
  FL[3] = edx;  // @39_6332d0
  eax = (eax + (u32)(8));  // @40_6332d0
  FL[3] = eax;  // @41_6332d0
  edi = (edi - 1);  // @42_6332d0
  FL[3] = edi;  // @43_6332d0
  esi = (esi | edx);  // @44_6332d0
  FL[3] = esi;  // @45_6332d0
  ebx = (ebx + 1);  // @46_6332d0
  FL[3] = ebx;  // @47_6332d0
  FL[0] = eax; FL[1] = (u32)(20);  // @48_6332d0
  if (FL[0] < FL[1]) goto L633330;  // @49_6332d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @50_6332d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @51_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @52_6332d0
  L63334c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @54_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @55_6332d0
  ecx = (ecx & esi);  // @56_6332d0
  FL[3] = ecx;  // @57_6332d0
  ecx = (u32)(edx + ecx*8);  // @58_6332d0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @60_6332d0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @61_6332d0
  esi = (esi >> (ecx & 0xff));  // @62_6332d0
  FL[3] = esi;  // @63_6332d0
  eax = (eax - ecx);  // @64_6332d0
  FL[3] = eax;  // @65_6332d0
  FL[2] = (edx & edx);  // @66_6332d0
  if (FL[2] != 0) goto L63337e;  // @67_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @68_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @69_6332d0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; })) & 0xff);  // @70_6332d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @71_6332d0
  edi = (edi + 1);  // @72_6332d0
  FL[3] = edi;  // @73_6332d0
  edx = (edx - 1);  // @74_6332d0
  FL[3] = edx;  // @75_6332d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @76_6332d0
  goto L633539;  // @77_6332d0
  L63337e:;
  FL[2] = ((edx & 0xff) & (u32)(16));  // @79_6332d0
  if (FL[2] != 0) goto L6333bc;  // @80_6332d0
  L633383:;
  FL[2] = ((edx & 0xff) & (u32)(64));  // @82_6332d0
  if (FL[2] != 0) goto L633598;  // @83_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7296488), sizeof v); (u32)v; });  // @84_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @85_6332d0
  ecx = (ecx & esi);  // @86_6332d0
  FL[3] = ecx;  // @87_6332d0
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @88_6332d0
  FL[3] = ecx;  // @89_6332d0
  edx = (u32)(edx + ecx*8);  // @90_6332d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @91_6332d0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @92_6332d0
  FL[2] = (edx & edx);  // @93_6332d0
  if (FL[2] == 0) goto L6334d4;  // @94_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @95_6332d0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @96_6332d0
  esi = (esi >> (ecx & 0xff));  // @97_6332d0
  FL[3] = esi;  // @98_6332d0
  eax = (eax - ecx);  // @99_6332d0
  FL[3] = eax;  // @100_6332d0
  FL[2] = ((edx & 0xff) & (u32)(16));  // @101_6332d0
  if (FL[2] == 0) goto L633383;  // @102_6332d0
  L6333bc:;
  edx = (edx & (u32)(15));  // @104_6332d0
  FL[3] = edx;  // @105_6332d0
  eax = (eax - edx);  // @106_6332d0
  FL[3] = eax;  // @107_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7296488), sizeof v); (u32)v; });  // @108_6332d0
  ecx = (ecx & esi);  // @109_6332d0
  FL[3] = ecx;  // @110_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @111_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @112_6332d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @113_6332d0
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }));  // @114_6332d0
  FL[3] = ebx;  // @115_6332d0
  ecx = edx;  // @116_6332d0
  esi = (esi >> (ecx & 0xff));  // @117_6332d0
  FL[3] = esi;  // @118_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @119_6332d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @120_6332d0
  FL[0] = eax; FL[1] = (u32)(15);  // @121_6332d0
  if (FL[0] >= FL[1]) goto L633404;  // @122_6332d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @123_6332d0
  L6333e8:;
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @125_6332d0
  ecx = eax;  // @126_6332d0
  edx = (edx << (ecx & 0xff));  // @127_6332d0
  FL[3] = edx;  // @128_6332d0
  eax = (eax + (u32)(8));  // @129_6332d0
  FL[3] = eax;  // @130_6332d0
  edi = (edi - 1);  // @131_6332d0
  FL[3] = edi;  // @132_6332d0
  esi = (esi | edx);  // @133_6332d0
  FL[3] = esi;  // @134_6332d0
  ebx = (ebx + 1);  // @135_6332d0
  FL[3] = ebx;  // @136_6332d0
  FL[0] = eax; FL[1] = (u32)(15);  // @137_6332d0
  if (FL[0] < FL[1]) goto L6333e8;  // @138_6332d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @139_6332d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @140_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @141_6332d0
  L633404:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @143_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @144_6332d0
  ecx = (ecx & esi);  // @145_6332d0
  FL[3] = ecx;  // @146_6332d0
  ecx = (u32)(edx + ecx*8);  // @147_6332d0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @149_6332d0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @150_6332d0
  esi = (esi >> (ecx & 0xff));  // @151_6332d0
  FL[3] = esi;  // @152_6332d0
  eax = (eax - ecx);  // @153_6332d0
  FL[3] = eax;  // @154_6332d0
  FL[2] = ((edx & 0xff) & (u32)(16));  // @155_6332d0
  if (FL[2] != 0) goto L633453;  // @156_6332d0
  L633422:;
  FL[2] = ((edx & 0xff) & (u32)(64));  // @158_6332d0
  if (FL[2] != 0) goto L633639;  // @159_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7296488), sizeof v); (u32)v; });  // @160_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @161_6332d0
  ecx = (ecx & esi);  // @162_6332d0
  FL[3] = ecx;  // @163_6332d0
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @164_6332d0
  FL[3] = ecx;  // @165_6332d0
  edx = (u32)(edx + ecx*8);  // @166_6332d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @167_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @168_6332d0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @169_6332d0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @170_6332d0
  esi = (esi >> (ecx & 0xff));  // @171_6332d0
  FL[3] = esi;  // @172_6332d0
  eax = (eax - ecx);  // @173_6332d0
  FL[3] = eax;  // @174_6332d0
  FL[2] = ((edx & 0xff) & (u32)(16));  // @175_6332d0
  if (FL[2] == 0) goto L633422;  // @176_6332d0
  L633453:;
  edx = (edx & (u32)(15));  // @178_6332d0
  FL[3] = edx;  // @179_6332d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @180_6332d0
  FL[0] = eax; FL[1] = edx;  // @181_6332d0
  if (FL[0] >= FL[1]) goto L63347e;  // @182_6332d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @183_6332d0
  L633460:;
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @185_6332d0
  ecx = eax;  // @186_6332d0
  edx = (edx << (ecx & 0xff));  // @187_6332d0
  FL[3] = edx;  // @188_6332d0
  eax = (eax + (u32)(8));  // @189_6332d0
  FL[3] = eax;  // @190_6332d0
  esi = (esi | edx);  // @191_6332d0
  FL[3] = esi;  // @192_6332d0
  edi = (edi - 1);  // @193_6332d0
  FL[3] = edi;  // @194_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @195_6332d0
  ebx = (ebx + 1);  // @196_6332d0
  FL[3] = ebx;  // @197_6332d0
  FL[0] = eax; FL[1] = edx;  // @198_6332d0
  if (FL[0] < FL[1]) goto L633460;  // @199_6332d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @200_6332d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @201_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @202_6332d0
  L63347e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7296488), sizeof v); (u32)v; });  // @204_6332d0
  eax = (eax - edx);  // @205_6332d0
  FL[3] = eax;  // @206_6332d0
  ecx = (ecx & esi);  // @207_6332d0
  FL[3] = ecx;  // @208_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @209_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @210_6332d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @211_6332d0
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }));  // @212_6332d0
  FL[3] = ebx;  // @213_6332d0
  ecx = edx;  // @214_6332d0
  esi = (esi >> (ecx & 0xff));  // @215_6332d0
  FL[3] = esi;  // @216_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @217_6332d0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @218_6332d0
  FL[3] = ecx;  // @219_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @220_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @221_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @222_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @223_6332d0
  ecx = edi;  // @224_6332d0
  ecx = (ecx - edx);  // @225_6332d0
  FL[3] = ecx;  // @226_6332d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @227_6332d0
  edx = ebx;  // @228_6332d0
  FL[0] = ecx; FL[1] = edx;  // @229_6332d0
  if (FL[0] < FL[1]) goto L6334ee;  // @230_6332d0
  edx = edi;  // @231_6332d0
  edx = (edx - ebx);  // @232_6332d0
  FL[3] = edx;  // @233_6332d0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @234_6332d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @235_6332d0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @236_6332d0
  edx = (edx + (u32)(2));  // @237_6332d0
  FL[3] = edx;  // @238_6332d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi + 1), &v, sizeof v); }  // @239_6332d0
  edi = (edi + (u32)(2));  // @240_6332d0
  FL[3] = edi;  // @241_6332d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) - (u32)(2))); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @242_6332d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @243_6332d0
  goto L633523;  // @244_6332d0
  L6334d4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @246_6332d0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @247_6332d0
  esi = (esi >> (ecx & 0xff));  // @248_6332d0
  FL[3] = esi;  // @249_6332d0
  eax = (eax - ecx);  // @250_6332d0
  FL[3] = eax;  // @251_6332d0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; })) & 0xff);  // @252_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @253_6332d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @254_6332d0
  edi = (edi + 1);  // @255_6332d0
  FL[3] = edi;  // @256_6332d0
  edx = (edx - 1);  // @257_6332d0
  FL[3] = edx;  // @258_6332d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @259_6332d0
  goto L633539;  // @260_6332d0
  L6334ee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @262_6332d0
  ecx = (ecx - edi);  // @263_6332d0
  FL[3] = ecx;  // @264_6332d0
  ecx = (ecx + edx);  // @265_6332d0
  FL[3] = ecx;  // @266_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @267_6332d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @268_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 44), sizeof v); (u32)v; });  // @269_6332d0
  edx = (edx - ecx);  // @270_6332d0
  FL[3] = edx;  // @271_6332d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = ecx;  // @272_6332d0
  if (FL[0] <= FL[1]) goto L633523;  // @273_6332d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) - ecx)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @274_6332d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @275_6332d0
  ebx = ecx;  // @276_6332d0
  L633510:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @278_6332d0
  edx = (u32)(edx + 1);  // @279_6332d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @280_6332d0
  edi = (edi + 1);  // @281_6332d0
  FL[3] = edi;  // @282_6332d0
  ebx = (ebx - (u32)(1));  // @283_6332d0
  FL[3] = ebx;  // @284_6332d0
  if (FL[3] != 0) goto L633510;  // @285_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @286_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @287_6332d0
  L633523:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @289_6332d0
  edx = (edx - edi);  // @290_6332d0
  FL[3] = edx;  // @291_6332d0
  L633528:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + edi), sizeof v); (u32)v; })) & 0xff);  // @293_6332d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @294_6332d0
  edi = (edi + 1);  // @295_6332d0
  FL[3] = edi;  // @296_6332d0
  ebx = (ebx - (u32)(1));  // @297_6332d0
  FL[3] = ebx;  // @298_6332d0
  if (FL[3] != 0) goto L633528;  // @299_6332d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @300_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @301_6332d0
  L633539:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @303_6332d0
  FL[0] = edx; FL[1] = (u32)(258);  // @304_6332d0
  if (FL[0] < FL[1]) goto L63354e;  // @305_6332d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @306_6332d0
  if (FL[0] >= FL[1]) goto L633327;  // @307_6332d0
  L63354e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @309_6332d0
  edx = eax;  // @310_6332d0
  edx = (edx >> (u32)(3));  // @311_6332d0
  FL[3] = edx;  // @312_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @313_6332d0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @314_6332d0
  FL[3] = ecx;  // @315_6332d0
  FL[0] = edx; FL[1] = ecx;  // @316_6332d0
  if (FL[0] >= FL[1]) edx = ecx;  // @317_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @318_6332d0
  ebx = (ebx - edx);  // @319_6332d0
  FL[3] = ebx;  // @320_6332d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @321_6332d0
  ecx = (u32)(edx*8);  // @322_6332d0
  eax = (eax - ecx);  // @323_6332d0
  FL[3] = eax;  // @324_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @325_6332d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @326_6332d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @327_6332d0
  eax = (eax + edx);  // @328_6332d0
  FL[3] = eax;  // @329_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @330_6332d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @331_6332d0
  eax = ebx;  // @332_6332d0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @333_6332d0
  FL[3] = eax;  // @334_6332d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @335_6332d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @336_6332d0
  eax = 0;  // @337_6332d0
  FL[3] = eax;  // @338_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @339_6332d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @340_6332d0
  return eax;  // @341_6332d0
  L633598:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @343_6332d0
  FL[2] = ((edx & 0xff) & (u32)(32));  // @344_6332d0
  edx = eax;  // @345_6332d0
  if (FL[2] == 0) goto L6335ea;  // @346_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @347_6332d0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @348_6332d0
  FL[3] = ecx;  // @349_6332d0
  edx = (edx >> (u32)(3));  // @350_6332d0
  FL[3] = edx;  // @351_6332d0
  FL[0] = edx; FL[1] = ecx;  // @352_6332d0
  if (FL[0] >= FL[1]) edx = ecx;  // @353_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @354_6332d0
  ebx = (ebx - edx);  // @355_6332d0
  FL[3] = ebx;  // @356_6332d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @357_6332d0
  ecx = (u32)(edx*8);  // @358_6332d0
  eax = (eax - ecx);  // @359_6332d0
  FL[3] = eax;  // @360_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @361_6332d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @362_6332d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @363_6332d0
  eax = (eax + edx);  // @364_6332d0
  FL[3] = eax;  // @365_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @366_6332d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @367_6332d0
  eax = ebx;  // @368_6332d0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @369_6332d0
  FL[3] = eax;  // @370_6332d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @371_6332d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @372_6332d0
  eax = (u32)(1);  // @373_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @374_6332d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @375_6332d0
  return eax;  // @376_6332d0
  L6335ea:;
  { u32 v = (u32)((u32)(7083448)); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @378_6332d0
  L6335f1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @380_6332d0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @381_6332d0
  FL[3] = ecx;  // @382_6332d0
  edx = (edx >> (u32)(3));  // @383_6332d0
  FL[3] = edx;  // @384_6332d0
  FL[0] = edx; FL[1] = ecx;  // @385_6332d0
  if (FL[0] >= FL[1]) edx = ecx;  // @386_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @387_6332d0
  ebx = (ebx - edx);  // @388_6332d0
  FL[3] = ebx;  // @389_6332d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @390_6332d0
  ecx = (u32)(edx*8);  // @391_6332d0
  eax = (eax - ecx);  // @392_6332d0
  FL[3] = eax;  // @393_6332d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @394_6332d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @395_6332d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @396_6332d0
  eax = (eax + edx);  // @397_6332d0
  FL[3] = eax;  // @398_6332d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @399_6332d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @400_6332d0
  eax = ebx;  // @401_6332d0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @402_6332d0
  FL[3] = eax;  // @403_6332d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @404_6332d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @405_6332d0
  eax = (u32)(4294967293);  // @406_6332d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @407_6332d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @408_6332d0
  return eax;  // @409_6332d0
  L633639:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @411_6332d0
  edx = eax;  // @412_6332d0
  { u32 v = (u32)((u32)(7083476)); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @413_6332d0
  goto L6335f1;  // @414_6332d0
}
// PCREG removed: the hand port in batch240025.cpp registers 0x6332d0

