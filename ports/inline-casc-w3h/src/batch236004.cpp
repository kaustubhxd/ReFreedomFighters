// batch236004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_585a40_thiscall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_585a40");
extern "C" u32 ext_634da6_cdecl2(...) __asm__("ext_634da6");
extern "C" u32 ext_634dca_cdecl2(...) __asm__("ext_634dca");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_585f90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
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
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_585f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_585f90
  edi = ecx;  // @2_585f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 248) + 24), &v, sizeof v); }  // @3_585f90
  PV[0] = (u32)(eax);  // @4_585f90
  ecx = (u32)((EBP - 252) + 32);  // @5_585f90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 252) + 44), &v, sizeof v); }  // @6_585f90
  eax = ext_43e920_fastcall3(ecx, edx, PV[0]);  // @7_585f90
  ecx = edx = 0;  // @8_585f90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 28) + 0), 4); v; });  // @9_585f90
  X1[1] = 0;  // @10_585f90
  X1[2] = 0;  // @11_585f90
  X1[3] = 0;  // @12_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 32) + 0), 4); v; });  // @13_585f90
  X0[1] = 0;  // @14_585f90
  X0[2] = 0;  // @15_585f90
  X0[3] = 0;  // @16_585f90
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @17_585f90
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @18_585f90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @19_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 36) + 0), 4); v; });  // @20_585f90
  X0[1] = 0;  // @21_585f90
  X0[2] = 0;  // @22_585f90
  X0[3] = 0;  // @23_585f90
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @24_585f90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @25_585f90
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @26_585f90
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @27_585f90
  ecx = edx = 0;  // @28_585f90
  X1[0] = 0;  // @29_585f90
  X1[1] = 0;  // @30_585f90
  X1[2] = 0;  // @31_585f90
  X1[3] = 0;  // @32_585f90
  eax = (u32)((EBP - 248) + 28);  // @33_585f90
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @34_585f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 248) + 20), &v, sizeof v); }  // @35_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 28) + 0), 4); v; });  // @36_585f90
  X0[1] = 0;  // @37_585f90
  X0[2] = 0;  // @38_585f90
  X0[3] = 0;  // @39_585f90
  X2[0] = 0;  // @40_585f90
  X2[1] = 0;  // @41_585f90
  X2[2] = 0;  // @42_585f90
  X2[3] = 0;  // @43_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 16) + 0), &X1[0], 4);  // @44_585f90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @45_585f90
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @46_585f90
  if (!__builtin_parity(FL[2] & 0xff)) goto L586039;  // @47_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 32) + 0), 4); v; });  // @48_585f90
  X0[1] = 0;  // @49_585f90
  X0[2] = 0;  // @50_585f90
  X0[3] = 0;  // @51_585f90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @52_585f90
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @53_585f90
  if (!__builtin_parity(FL[2] & 0xff)) goto L586039;  // @54_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 36) + 0), 4); v; });  // @55_585f90
  X0[1] = 0;  // @56_585f90
  X0[2] = 0;  // @57_585f90
  X0[3] = 0;  // @58_585f90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @59_585f90
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @60_585f90
  if (__builtin_parity(FL[2] & 0xff)) goto L586079;  // @61_585f90
  L586039:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 248) + 12), &v, sizeof v); }  // @63_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 20), sizeof v); (u32)v; });  // @64_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @65_585f90
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @66_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @67_585f90
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @68_585f90
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @69_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @70_585f90
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @71_585f90
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @72_585f90
  __asm__ volatile("fsqrt" ::: "st");  // @73_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 248) + 12)) : "st");  // @74_585f90
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @75_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @76_585f90
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @77_585f90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @78_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @79_585f90
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @80_585f90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @81_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @82_585f90
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @83_585f90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @84_585f90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 248) + 12)) :: "st");  // @85_585f90
  L586079:;
  X0[0] = X1[0];  // @87_585f90
  X0[1] = X1[1];  // @88_585f90
  X0[2] = X1[2];  // @89_585f90
  X0[3] = X1[3];  // @90_585f90
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818444) + 0), 4); v; })));  // @91_585f90
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @92_585f90
  __builtin_memcpy((void *)((u32)((EBP - 256) + 184) + 0), &X0[0], 4);  // @93_585f90
  __builtin_memcpy((void *)((u32)((EBP - 256) + 184) + 4), &X0[1], 4);  // @94_585f90
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 256) + 184)) : "st");  // @95_585f90
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[1] = (u32)v_; PV[2] = (u32)(v_ >> 32); }  // @96_585f90
  eax = ext_634dca_cdecl2(PV[1], PV[2]);  // @97_585f90
    // @98_585f90
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 248) + 184)) :: "st");  // @99_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 184) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 184) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @100_585f90
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @101_585f90
  eax = (u32)(1);  // @102_585f90
  edx = eax;  // @103_585f90
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @104_585f90
  FL[2] = (ecx & ecx);  // @105_585f90
  esi = ecx;  // @106_585f90
  ecx = (u32)((EBP - 248) + 232);  // @107_585f90
  if (FL[2] == 0) esi = eax;  // @108_585f90
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @109_585f90
  if (FL[2] != 0) edx = eax;  // @110_585f90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 248) + 20), &v, sizeof v); }  // @111_585f90
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 248) + 176), &v, sizeof v); }  // @112_585f90
  edx = (u32)((EBP - 248) + 28);  // @113_585f90
  eax = ext_44e630_fastcall2(ecx, edx);  // @114_585f90
  ecx = edx = 0;  // @115_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 240) + 0), 4); v; });  // @116_585f90
  X0[1] = 0;  // @117_585f90
  X0[2] = 0;  // @118_585f90
  X0[3] = 0;  // @119_585f90
  eax = (u32)((EBP - 248) + 208);  // @120_585f90
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @121_585f90
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @122_585f90
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @123_585f90
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @124_585f90
  X1[0] = 0;  // @125_585f90
  X1[1] = 0;  // @126_585f90
  X1[2] = 0;  // @127_585f90
  X1[3] = 0;  // @128_585f90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 232) + 0), 4); v; });  // @129_585f90
  X2[1] = 0;  // @130_585f90
  X2[2] = 0;  // @131_585f90
  X2[3] = 0;  // @132_585f90
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @133_585f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 248) + 44), &v, sizeof v); }  // @134_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 248) + 212), &v, sizeof v); }  // @135_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 208) + 0), &X0[0], 4);  // @136_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 216) + 0), &X2[0], 4);  // @137_585f90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @138_585f90
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @139_585f90
  if (!__builtin_parity(FL[2] & 0xff)) goto L586145;  // @140_585f90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @141_585f90
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @142_585f90
  if (__builtin_parity(FL[2] & 0xff)) goto L586185;  // @143_585f90
  L586145:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 248) + 12), &v, sizeof v); }  // @145_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 44), sizeof v); (u32)v; });  // @146_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @147_585f90
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @148_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @149_585f90
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @150_585f90
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @151_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @152_585f90
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @153_585f90
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @154_585f90
  __asm__ volatile("fsqrt" ::: "st");  // @155_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 248) + 12)) : "st");  // @156_585f90
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @157_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @158_585f90
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @159_585f90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @160_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @161_585f90
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @162_585f90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @163_585f90
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @164_585f90
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @165_585f90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @166_585f90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 248) + 12)) :: "st");  // @167_585f90
  L586185:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @169_585f90
  ecx = (u32)((EBP - 248) + 220);  // @170_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 248) + 228), &v, sizeof v); }  // @171_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 248) + 224), &v, sizeof v); }  // @172_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 248) + 220), &v, sizeof v); }  // @173_585f90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @174_585f90
  edx = (edx + (u32)(48));  // @175_585f90
  FL[3] = edx;  // @176_585f90
  eax = ext_441940_fastcall2(ecx, edx);  // @177_585f90
  ecx = edx = 0;  // @178_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @179_585f90
  edx = (u32)((EBP - 248) + 220);  // @180_585f90
  PV[3] = (u32)(edx);  // @181_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @182_585f90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[3]);  // @183_585f90
  ecx = edx = 0;  // @184_585f90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 176), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @185_585f90
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @186_585f90
  X0[0] = F2U((float)(s32)X0[0]);  // @187_585f90
  X0[1] = F2U((float)(s32)X0[1]);  // @188_585f90
  X0[2] = F2U((float)(s32)X0[2]);  // @189_585f90
  X0[3] = F2U((float)(s32)X0[3]);  // @190_585f90
  if (FL[0] == FL[1]) goto L586397;  // @191_585f90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818444) + 0), 4); v; });  // @192_585f90
  X2[1] = 0;  // @193_585f90
  X2[2] = 0;  // @194_585f90
  X2[3] = 0;  // @195_585f90
  esi = 0;  // @196_585f90
  FL[3] = esi;  // @197_585f90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 16) + 0), 4); v; });  // @198_585f90
  X1[1] = 0;  // @199_585f90
  X1[2] = 0;  // @200_585f90
  X1[3] = 0;  // @201_585f90
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @202_585f90
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @203_585f90
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @204_585f90
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6994848) + 0), 4); v; })));  // @205_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 16) + 0), &X1[0], 4);  // @206_585f90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 20), sizeof v); (u32)v; }); FL[1] = esi;  // @207_585f90
  if ((s32)FL[0] <= (s32)FL[1]) goto L586749;  // @208_585f90
  L586220:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 24), sizeof v); (u32)v; });  // @210_585f90
  eax = (u32)((EBP - 248) + 28);  // @211_585f90
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @212_585f90
  X0[0] = F2U((float)(s32)X0[0]);  // @213_585f90
  X0[1] = F2U((float)(s32)X0[1]);  // @214_585f90
  X0[2] = F2U((float)(s32)X0[2]);  // @215_585f90
  X0[3] = F2U((float)(s32)X0[3]);  // @216_585f90
  PV[4] = (u32)(ecx);  // @217_585f90
  ecx = (u32)((EBP - 252) + 168);  // @218_585f90
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @219_585f90
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @220_585f90
  PV[5] = X0[0];  // @221_585f90
  PV[6] = (u32)(eax);  // @222_585f90
  eax = ext_443ef0_fastcall4(ecx, edx, PV[6], PV[5]);  // @223_585f90
  ecx = edx = 0;  // @224_585f90
  PV[7] = (u32)(ecx);  // @225_585f90
  edx = (u32)((EBP - 252) + 212);  // @226_585f90
  ecx = (u32)((EBP - 252) + 168);  // @227_585f90
  eax = ext_451890_fastcall3(ecx, edx, (u32)(3264610304));  // @228_585f90
  ecx = 0;  // @229_585f90
  ecx = (u32)((EBP - 248) + 48);  // @230_585f90
  eax = ext_4e1b60_thiscall1(ecx);  // @231_585f90
    // @232_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @233_585f90
  X0[1] = 0;  // @234_585f90
  X0[2] = 0;  // @235_585f90
  X0[3] = 0;  // @236_585f90
  PV[8] = (u32)(ecx);  // @237_585f90
  ecx = (u32)((EBP - 252) + 180);  // @238_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 252) + 180), &v, sizeof v); }  // @239_585f90
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)((EBP - 252) + 184), &v, sizeof v); }  // @240_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 252) + 188), &v, sizeof v); }  // @241_585f90
  PV[9] = X0[0];  // @242_585f90
  eax = ext_4e0d00_thiscall2(ecx, PV[9]);  // @243_585f90
    // @244_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 164) + 0), 4); v; });  // @245_585f90
  X0[1] = 0;  // @246_585f90
  X0[2] = 0;  // @247_585f90
  X0[3] = 0;  // @248_585f90
  edx = (u32)((EBP - 248) + 48);  // @249_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @250_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 48) + 0), &X0[0], 4);  // @251_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 168) + 0), 4); v; });  // @252_585f90
  X0[1] = 0;  // @253_585f90
  X0[2] = 0;  // @254_585f90
  X0[3] = 0;  // @255_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 52) + 0), &X0[0], 4);  // @256_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 172) + 0), 4); v; });  // @257_585f90
  X0[1] = 0;  // @258_585f90
  X0[2] = 0;  // @259_585f90
  X0[3] = 0;  // @260_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 56) + 0), &X0[0], 4);  // @261_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 176) + 0), 4); v; });  // @262_585f90
  X0[1] = 0;  // @263_585f90
  X0[2] = 0;  // @264_585f90
  X0[3] = 0;  // @265_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 60) + 0), &X0[0], 4);  // @266_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 180) + 0), 4); v; });  // @267_585f90
  X0[1] = 0;  // @268_585f90
  X0[2] = 0;  // @269_585f90
  X0[3] = 0;  // @270_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 64) + 0), &X0[0], 4);  // @271_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 184) + 0), 4); v; });  // @272_585f90
  X0[1] = 0;  // @273_585f90
  X0[2] = 0;  // @274_585f90
  X0[3] = 0;  // @275_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 68) + 0), &X0[0], 4);  // @276_585f90
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 248) + 156), &v, sizeof v); }  // @277_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @278_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @279_585f90
  PV[10] = (u32)(edx);  // @280_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @281_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @282_585f90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[10], (u32)(0), (u32)(1), (u32)(2097152), (u32)(1), (u32)(0));  // @283_585f90
  ecx = edx = 0;  // @284_585f90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @285_585f90
  if (FL[2] == 0) goto L586368;  // @286_585f90
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @287_585f90
  eax = (u32)((EBP - 252) + 212);  // @288_585f90
  ecx = edi;  // @289_585f90
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @290_585f90
  PV[13] = (u32)(eax);  // @291_585f90
  eax = (u32)((EBP - 264) + 248);  // @292_585f90
  PV[14] = (u32)(eax);  // @293_585f90
  eax = (u32)((EBP - 268) + 184);  // @294_585f90
  PV[15] = (u32)(eax);  // @295_585f90
  eax = (u32)((EBP - 272) + 244);  // @296_585f90
  PV[16] = (u32)(eax);  // @297_585f90
  eax = ext_585a40_thiscall8(ecx, PV[16], PV[15], PV[14], PV[13], (u32)(1), PV[12], PV[11]);  // @298_585f90
  ecx = edx = 0;  // @299_585f90
  L586368:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 16) + 0), 4); v; });  // @301_585f90
  X1[1] = 0;  // @302_585f90
  X1[2] = 0;  // @303_585f90
  X1[3] = 0;  // @304_585f90
  esi = (esi + 1);  // @305_585f90
  FL[3] = esi;  // @306_585f90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818444) + 0), 4); v; });  // @307_585f90
  X2[1] = 0;  // @308_585f90
  X2[2] = 0;  // @309_585f90
  X2[3] = 0;  // @310_585f90
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 20), sizeof v); (u32)v; });  // @311_585f90
  if ((s32)FL[0] < (s32)FL[1]) goto L586220;  // @312_585f90
  ext_633654(G(u32, 0x6f5630));  // @313_585f90
  return eax;  // @314_585f90
  L586397:;
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @316_585f90
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @317_585f90
  __builtin_memcpy((void *)((u32)((EBP - 256) + 184) + 0), &X0[0], 4);  // @318_585f90
  __builtin_memcpy((void *)((u32)((EBP - 256) + 184) + 4), &X0[1], 4);  // @319_585f90
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)((EBP - 256) + 184)) : "st");  // @320_585f90
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[17] = (u32)v_; PV[18] = (u32)(v_ >> 32); }  // @321_585f90
  eax = ext_634da6_cdecl2(PV[17], PV[18]);  // @322_585f90
    // @323_585f90
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)((EBP - 248) + 184)) :: "st");  // @324_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 184) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 184) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @325_585f90
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @326_585f90
  edx = (u32)(1);  // @327_585f90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818444) + 0), 4); v; });  // @328_585f90
  X2[1] = 0;  // @329_585f90
  X2[2] = 0;  // @330_585f90
  X2[3] = 0;  // @331_585f90
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); edi = (u32)r_; }  // @332_585f90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 16) + 0), 4); v; });  // @333_585f90
  X1[1] = 0;  // @334_585f90
  X1[2] = 0;  // @335_585f90
  X1[3] = 0;  // @336_585f90
  FL[2] = (edi & edi);  // @337_585f90
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6994848) + 0), 4); v; });  // @338_585f90
  X3[1] = 0;  // @339_585f90
  X3[2] = 0;  // @340_585f90
  X3[3] = 0;  // @341_585f90
  if (FL[2] == 0) edi = edx;  // @342_585f90
  ecx = (ecx & 0xffffff00u) | ((0) & 0xff);  // @343_585f90
  FL[3] = (ecx & 0xff);  // @344_585f90
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)((EBP - 248) + 12), &v, sizeof v); }  // @345_585f90
  eax = (u32)(edi + edi);  // @346_585f90
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @347_585f90
  X0[0] = F2U((float)(s32)X0[0]);  // @348_585f90
  X0[1] = F2U((float)(s32)X0[1]);  // @349_585f90
  X0[2] = F2U((float)(s32)X0[2]);  // @350_585f90
  X0[3] = F2U((float)(s32)X0[3]);  // @351_585f90
  eax = (ecx & 0xff);  // @352_585f90
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @353_585f90
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) eax = edx;  // @354_585f90
  esi = 0;  // @355_585f90
  FL[3] = esi;  // @356_585f90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 248) + 176), &v, sizeof v); }  // @357_585f90
  FL[2] = (edi & edi);  // @358_585f90
  if ((s32)FL[2] <= 0) goto L5865b5;  // @359_585f90
  L586430:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 24), sizeof v); (u32)v; });  // @361_585f90
  eax = (u32)((EBP - 248) + 28);  // @362_585f90
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @363_585f90
  X0[0] = F2U((float)(s32)X0[0]);  // @364_585f90
  X0[1] = F2U((float)(s32)X0[1]);  // @365_585f90
  X0[2] = F2U((float)(s32)X0[2]);  // @366_585f90
  X0[3] = F2U((float)(s32)X0[3]);  // @367_585f90
  PV[19] = (u32)(ecx);  // @368_585f90
  ecx = (u32)((EBP - 252) + 200);  // @369_585f90
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @370_585f90
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @371_585f90
  PV[20] = X0[0];  // @372_585f90
  PV[21] = (u32)(eax);  // @373_585f90
  eax = ext_443ef0_fastcall4(ecx, edx, PV[21], PV[20]);  // @374_585f90
  ecx = edx = 0;  // @375_585f90
  PV[22] = (u32)(ecx);  // @376_585f90
  edx = (u32)((EBP - 252) + 212);  // @377_585f90
  ecx = (u32)((EBP - 252) + 200);  // @378_585f90
  eax = ext_451890_fastcall3(ecx, edx, (u32)(3264610304));  // @379_585f90
  ecx = 0;  // @380_585f90
  ecx = (u32)((EBP - 248) + 48);  // @381_585f90
  eax = ext_4e1b60_thiscall1(ecx);  // @382_585f90
    // @383_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @384_585f90
  X0[1] = 0;  // @385_585f90
  X0[2] = 0;  // @386_585f90
  X0[3] = 0;  // @387_585f90
  PV[23] = (u32)(ecx);  // @388_585f90
  ecx = (u32)((EBP - 252) + 168);  // @389_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 252) + 168), &v, sizeof v); }  // @390_585f90
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)((EBP - 252) + 172), &v, sizeof v); }  // @391_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 252) + 176), &v, sizeof v); }  // @392_585f90
  PV[24] = X0[0];  // @393_585f90
  eax = ext_4e0d00_thiscall2(ecx, PV[24]);  // @394_585f90
    // @395_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 196) + 0), 4); v; });  // @396_585f90
  X0[1] = 0;  // @397_585f90
  X0[2] = 0;  // @398_585f90
  X0[3] = 0;  // @399_585f90
  edx = (u32)((EBP - 248) + 48);  // @400_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @401_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 48) + 0), &X0[0], 4);  // @402_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 200) + 0), 4); v; });  // @403_585f90
  X0[1] = 0;  // @404_585f90
  X0[2] = 0;  // @405_585f90
  X0[3] = 0;  // @406_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 52) + 0), &X0[0], 4);  // @407_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 204) + 0), 4); v; });  // @408_585f90
  X0[1] = 0;  // @409_585f90
  X0[2] = 0;  // @410_585f90
  X0[3] = 0;  // @411_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 56) + 0), &X0[0], 4);  // @412_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 164) + 0), 4); v; });  // @413_585f90
  X0[1] = 0;  // @414_585f90
  X0[2] = 0;  // @415_585f90
  X0[3] = 0;  // @416_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 60) + 0), &X0[0], 4);  // @417_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 168) + 0), 4); v; });  // @418_585f90
  X0[1] = 0;  // @419_585f90
  X0[2] = 0;  // @420_585f90
  X0[3] = 0;  // @421_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 64) + 0), &X0[0], 4);  // @422_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 172) + 0), 4); v; });  // @423_585f90
  X0[1] = 0;  // @424_585f90
  X0[2] = 0;  // @425_585f90
  X0[3] = 0;  // @426_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 68) + 0), &X0[0], 4);  // @427_585f90
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 248) + 156), &v, sizeof v); }  // @428_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @429_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @430_585f90
  PV[25] = (u32)(edx);  // @431_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @432_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @433_585f90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[25], (u32)(0), (u32)(1), (u32)(2097152), (u32)(1), (u32)(0));  // @434_585f90
  ecx = edx = 0;  // @435_585f90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @436_585f90
  if (FL[2] == 0) goto L586596;  // @437_585f90
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @438_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 252) + 44), sizeof v); (u32)v; });  // @439_585f90
  eax = (u32)((EBP - 252) + 212);  // @440_585f90
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @441_585f90
  PV[28] = (u32)(eax);  // @442_585f90
  eax = (u32)((EBP - 264) + 248);  // @443_585f90
  PV[29] = (u32)(eax);  // @444_585f90
  eax = (u32)((EBP - 268) + 216);  // @445_585f90
  PV[30] = (u32)(eax);  // @446_585f90
  eax = (u32)((EBP - 272) + 244);  // @447_585f90
  PV[31] = (u32)(eax);  // @448_585f90
  eax = ext_585a40_thiscall8(ecx, PV[31], PV[30], PV[29], PV[28], (u32)(1), PV[27], PV[26]);  // @449_585f90
  ecx = edx = 0;  // @450_585f90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @451_585f90
  if (FL[2] == 0) goto L586596;  // @452_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 12), sizeof v); (u32)v; });  // @453_585f90
  eax = (u32)(edi - 1);  // @454_585f90
  FL[0] = esi; FL[1] = eax;  // @455_585f90
  ecx = (ecx & 0xff);  // @456_585f90
  eax = (u32)(1);  // @457_585f90
  if (FL[0] == FL[1]) ecx = eax;  // @458_585f90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 248) + 12), &v, sizeof v); }  // @459_585f90
  L586596:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818444) + 0), 4); v; });  // @461_585f90
  X2[1] = 0;  // @462_585f90
  X2[2] = 0;  // @463_585f90
  X2[3] = 0;  // @464_585f90
  esi = (esi + 1);  // @465_585f90
  FL[3] = esi;  // @466_585f90
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6994848) + 0), 4); v; });  // @467_585f90
  X3[1] = 0;  // @468_585f90
  X3[2] = 0;  // @469_585f90
  X3[3] = 0;  // @470_585f90
  FL[0] = esi; FL[1] = edi;  // @471_585f90
  if ((s32)FL[0] < (s32)FL[1]) goto L586430;  // @472_585f90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 16) + 0), 4); v; });  // @473_585f90
  X1[1] = 0;  // @474_585f90
  X1[2] = 0;  // @475_585f90
  X1[3] = 0;  // @476_585f90
  L5865b5:;
  esi = 0;  // @478_585f90
  FL[3] = esi;  // @479_585f90
  FL[2] = (edi & edi);  // @480_585f90
  if ((s32)FL[2] <= 0) goto L586749;  // @481_585f90
  X1[0] = F2U(U2F(X1[0]) - U2F(X3[0]));  // @482_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 16) + 0), &X1[0], 4);  // @483_585f90
  L5865d0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 24), sizeof v); (u32)v; });  // @485_585f90
  eax = (u32)((EBP - 248) + 28);  // @486_585f90
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @487_585f90
  X0[0] = F2U((float)(s32)X0[0]);  // @488_585f90
  X0[1] = F2U((float)(s32)X0[1]);  // @489_585f90
  X0[2] = F2U((float)(s32)X0[2]);  // @490_585f90
  X0[3] = F2U((float)(s32)X0[3]);  // @491_585f90
  PV[32] = (u32)(ecx);  // @492_585f90
  ecx = (u32)((EBP - 252) + 200);  // @493_585f90
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @494_585f90
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @495_585f90
  PV[33] = X1[0];  // @496_585f90
  PV[34] = (u32)(eax);  // @497_585f90
  eax = ext_443ef0_fastcall4(ecx, edx, PV[34], PV[33]);  // @498_585f90
  ecx = edx = 0;  // @499_585f90
  PV[35] = (u32)(ecx);  // @500_585f90
  edx = (u32)((EBP - 252) + 212);  // @501_585f90
  ecx = (u32)((EBP - 252) + 200);  // @502_585f90
  eax = ext_451890_fastcall3(ecx, edx, (u32)(3264610304));  // @503_585f90
  ecx = 0;  // @504_585f90
  ecx = (u32)((EBP - 248) + 48);  // @505_585f90
  eax = ext_4e1b60_thiscall1(ecx);  // @506_585f90
    // @507_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @508_585f90
  X0[1] = 0;  // @509_585f90
  X0[2] = 0;  // @510_585f90
  X0[3] = 0;  // @511_585f90
  PV[36] = (u32)(ecx);  // @512_585f90
  ecx = (u32)((EBP - 252) + 168);  // @513_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 252) + 168), &v, sizeof v); }  // @514_585f90
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)((EBP - 252) + 172), &v, sizeof v); }  // @515_585f90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 252) + 176), &v, sizeof v); }  // @516_585f90
  PV[37] = X0[0];  // @517_585f90
  eax = ext_4e0d00_thiscall2(ecx, PV[37]);  // @518_585f90
    // @519_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 196) + 0), 4); v; });  // @520_585f90
  X0[1] = 0;  // @521_585f90
  X0[2] = 0;  // @522_585f90
  X0[3] = 0;  // @523_585f90
  edx = (u32)((EBP - 248) + 48);  // @524_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @525_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 48) + 0), &X0[0], 4);  // @526_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 200) + 0), 4); v; });  // @527_585f90
  X0[1] = 0;  // @528_585f90
  X0[2] = 0;  // @529_585f90
  X0[3] = 0;  // @530_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 52) + 0), &X0[0], 4);  // @531_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 204) + 0), 4); v; });  // @532_585f90
  X0[1] = 0;  // @533_585f90
  X0[2] = 0;  // @534_585f90
  X0[3] = 0;  // @535_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 56) + 0), &X0[0], 4);  // @536_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 164) + 0), 4); v; });  // @537_585f90
  X0[1] = 0;  // @538_585f90
  X0[2] = 0;  // @539_585f90
  X0[3] = 0;  // @540_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 60) + 0), &X0[0], 4);  // @541_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 168) + 0), 4); v; });  // @542_585f90
  X0[1] = 0;  // @543_585f90
  X0[2] = 0;  // @544_585f90
  X0[3] = 0;  // @545_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 64) + 0), &X0[0], 4);  // @546_585f90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 172) + 0), 4); v; });  // @547_585f90
  X0[1] = 0;  // @548_585f90
  X0[2] = 0;  // @549_585f90
  X0[3] = 0;  // @550_585f90
  __builtin_memcpy((void *)((u32)((EBP - 248) + 68) + 0), &X0[0], 4);  // @551_585f90
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 248) + 156), &v, sizeof v); }  // @552_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @553_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @554_585f90
  PV[38] = (u32)(edx);  // @555_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @556_585f90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @557_585f90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[38], (u32)(0), (u32)(1), (u32)(2097152), (u32)(1), (u32)(0));  // @558_585f90
  ecx = edx = 0;  // @559_585f90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @560_585f90
  if (FL[2] == 0) goto L586732;  // @561_585f90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 176), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @562_585f90
  if (FL[0] == FL[1]) goto L586701;  // @563_585f90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 248) + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @564_585f90
  if (FL[0] == FL[1]) goto L586701;  // @565_585f90
  eax = (u32)(edi - 1);  // @566_585f90
  FL[0] = esi; FL[1] = eax;  // @567_585f90
  if (FL[0] == FL[1]) goto L586749;  // @568_585f90
  L586701:;
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @570_585f90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 252) + 44), sizeof v); (u32)v; });  // @571_585f90
  eax = (u32)((EBP - 252) + 212);  // @572_585f90
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @573_585f90
  PV[41] = (u32)(eax);  // @574_585f90
  eax = (u32)((EBP - 264) + 248);  // @575_585f90
  PV[42] = (u32)(eax);  // @576_585f90
  eax = (u32)((EBP - 268) + 216);  // @577_585f90
  PV[43] = (u32)(eax);  // @578_585f90
  eax = (u32)((EBP - 272) + 244);  // @579_585f90
  PV[44] = (u32)(eax);  // @580_585f90
  eax = ext_585a40_thiscall8(ecx, PV[44], PV[43], PV[42], PV[41], (u32)(1), PV[40], PV[39]);  // @581_585f90
  ecx = edx = 0;  // @582_585f90
  L586732:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 248) + 16) + 0), 4); v; });  // @584_585f90
  X1[1] = 0;  // @585_585f90
  X1[2] = 0;  // @586_585f90
  X1[3] = 0;  // @587_585f90
  esi = (esi + 1);  // @588_585f90
  FL[3] = esi;  // @589_585f90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818444) + 0), 4); v; });  // @590_585f90
  X2[1] = 0;  // @591_585f90
  X2[2] = 0;  // @592_585f90
  X2[3] = 0;  // @593_585f90
  FL[0] = esi; FL[1] = edi;  // @594_585f90
  if ((s32)FL[0] < (s32)FL[1]) goto L5865d0;  // @595_585f90
  L586749:;
  ext_633654(G(u32, 0x6f5630));  // @597_585f90
  return eax;  // @598_585f90
}
PCREG(585f90, lifted_585f90);

