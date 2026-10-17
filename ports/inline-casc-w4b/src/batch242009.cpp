// batch242009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634db8_dbl(double) __asm__("ext_634db8");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de440_fastcall3(u32, u32, u32) __asm__("ext_4de440");
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 FASTCALL ext_4dfd10_fastcall2(u32, u32) __asm__("ext_4dfd10");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_4e2560_fastcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_4e2560");
extern "C" u32 THISCALL ext_451ba0_thiscall3(u32, u32, u32) __asm__("ext_451ba0");
extern "C" u32 THISCALL ext_4526a0_thiscall3(u32, u32, u32) __asm__("ext_4526a0");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4522d0_thiscall3(u32, u32, u32) __asm__("ext_4522d0");
extern "C" u32 THISCALL ext_4569b0_thiscall1(u32) __asm__("ext_4569b0");
extern "C" u32 THISCALL ext_456b70_thiscall3(u32, u32, u32) __asm__("ext_456b70");
extern "C" u32 THISCALL ext_4daa70_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_4daa70");
extern "C" u32 FASTCALL ext_4e2220_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_4e2220");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5e80_thiscall1(u32) __asm__("ext_4e5e80");
extern "C" u32 THISCALL ext_4fed00_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_4fed00");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" double VECTORCALL ext_634db2_dbl2(double, double) __asm__("ext_634db2");
extern "C" double VECTORCALL ext_634dd6_dbl(double) __asm__("ext_634dd6");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c1a00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c1a00
  esi = ecx;  // @1_4c1a00
  ecx = edi;  // @2_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @3_4c1a00
  ecx = edx = 0;  // @4_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 84)) :: "st");  // @5_4c1a00
  ecx = edi;  // @6_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @7_4c1a00
  ecx = edx = 0;  // @8_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 88)) :: "st");  // @9_4c1a00
  ecx = edi;  // @10_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @11_4c1a00
  ecx = edx = 0;  // @12_4c1a00
  ecx = edi;  // @13_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 92)) :: "st");  // @14_4c1a00
  eax = ext_4e5e60_thiscall1(ecx);  // @15_4c1a00
  ecx = edx = 0;  // @16_4c1a00
  ecx = edi;  // @17_4c1a00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @18_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @19_4c1a00
  ecx = edx = 0;  // @20_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @21_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @22_4c1a00
  X0[1] = 0;  // @23_4c1a00
  X0[2] = 0;  // @24_4c1a00
  X0[3] = 0;  // @25_4c1a00
  X1[0] = 0;  // @26_4c1a00
  X1[1] = 0;  // @27_4c1a00
  X1[2] = 0;  // @28_4c1a00
  X1[3] = 0;  // @29_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 116) + 0), &X0[0], 4);  // @30_4c1a00
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4c1a5a;  // @31_4c1a00
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @32_4c1a00
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @33_4c1a00
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @34_4c1a00
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @35_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 116) + 0), &X0[0], 4);  // @36_4c1a00
  L4c1a5a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 116) + 0), 4); v; });  // @38_4c1a00
  X1[1] = 0;  // @39_4c1a00
  X1[2] = 0;  // @40_4c1a00
  X1[3] = 0;  // @41_4c1a00
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; })));  // @42_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891408) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891408) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @43_4c1a00
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @44_4c1a00
  { double r_ = ext_634db2_dbl2(U2D(X0[0], X0[1]), U2D(X1[0], X1[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @45_4c1a00   hand fix: pow(xmm0, xmm1) SSE2 libm convention
    // @46_4c1a00
  X1[0] = 0;  // @47_4c1a00
  X1[1] = 0;  // @48_4c1a00
  X1[2] = 0;  // @49_4c1a00
  X1[3] = 0;  // @50_4c1a00
  ecx = edi;  // @51_4c1a00
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @52_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @53_4c1a00
  X0[1] = 0;  // @54_4c1a00
  X0[2] = 0;  // @55_4c1a00
  X0[3] = 0;  // @56_4c1a00
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @57_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 116) + 0), &X0[0], 4);  // @58_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @59_4c1a00
  ecx = edx = 0;  // @60_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @61_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @62_4c1a00
  X0[1] = 0;  // @63_4c1a00
  X0[2] = 0;  // @64_4c1a00
  X0[3] = 0;  // @65_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 120) + 0), &X0[0], 4);  // @66_4c1a00
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @67_4c1a00
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @68_4c1a00
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c1ab7;  // @69_4c1a00
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @70_4c1a00
  L4c1ab7:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; });  // @72_4c1a00
  X0[1] = 0;  // @73_4c1a00
  X0[2] = 0;  // @74_4c1a00
  X0[3] = 0;  // @75_4c1a00
  ecx = edi;  // @76_4c1a00
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @77_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 120) + 0), &X0[0], 4);  // @78_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @79_4c1a00
  ecx = edx = 0;  // @80_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @81_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @82_4c1a00
  X0[1] = 0;  // @83_4c1a00
  X0[2] = 0;  // @84_4c1a00
  X0[3] = 0;  // @85_4c1a00
  X1[0] = 0;  // @86_4c1a00
  X1[1] = 0;  // @87_4c1a00
  X1[2] = 0;  // @88_4c1a00
  X1[3] = 0;  // @89_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 128) + 0), &X0[0], 4);  // @90_4c1a00
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4c1af7;  // @91_4c1a00
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @92_4c1a00
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @93_4c1a00
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @94_4c1a00
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @95_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 128) + 0), &X0[0], 4);  // @96_4c1a00
  L4c1af7:;
  ecx = edi;  // @98_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @99_4c1a00
  ecx = edx = 0;  // @100_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @101_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @102_4c1a00
  X0[1] = 0;  // @103_4c1a00
  X0[2] = 0;  // @104_4c1a00
  X0[3] = 0;  // @105_4c1a00
  X1[0] = 0;  // @106_4c1a00
  X1[1] = 0;  // @107_4c1a00
  X1[2] = 0;  // @108_4c1a00
  X1[3] = 0;  // @109_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 132) + 0), &X0[0], 4);  // @110_4c1a00
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4c1b25;  // @111_4c1a00
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @112_4c1a00
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @113_4c1a00
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @114_4c1a00
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @115_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 132) + 0), &X0[0], 4);  // @116_4c1a00
  L4c1b25:;
  ecx = edi;  // @118_4c1a00
  eax = ext_4e5e60_thiscall1(ecx);  // @119_4c1a00
  ecx = edx = 0;  // @120_4c1a00
  ecx = edi;  // @121_4c1a00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 136), &v, sizeof v); }  // @122_4c1a00
  eax = ext_4e5e60_thiscall1(ecx);  // @123_4c1a00
  ecx = edx = 0;  // @124_4c1a00
  ecx = edi;  // @125_4c1a00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @126_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @127_4c1a00
  ecx = edx = 0;  // @128_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 144)) :: "st");  // @129_4c1a00
  ecx = edi;  // @130_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @131_4c1a00
  ecx = edx = 0;  // @132_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 148)) :: "st");  // @133_4c1a00
  ecx = edi;  // @134_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @135_4c1a00
  ecx = edx = 0;  // @136_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; });  // @137_4c1a00
  X0[1] = 0;  // @138_4c1a00
  X0[2] = 0;  // @139_4c1a00
  X0[3] = 0;  // @140_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @141_4c1a00
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @142_4c1a00
  X1[1] = 0;  // @143_4c1a00
  X1[2] = 0;  // @144_4c1a00
  X1[3] = 0;  // @145_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 160) + 0), &X1[0], 4);  // @146_4c1a00
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4c1b87;  // @147_4c1a00
  { u32 v = (u32)((u32)(1036831949)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @148_4c1a00
  L4c1b87:;
  ecx = edi;  // @150_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @151_4c1a00
  ecx = edx = 0;  // @152_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 152)) :: "st");  // @153_4c1a00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @154_4c1a00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @155_4c1a00
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @156_4c1a00
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @157_4c1a00
  if (FL[0] == FL[1]) goto L4c1bb3;  // @158_4c1a00
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @159_4c1a00
  FL[3] = (eax & 0xff);  // @160_4c1a00
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @161_4c1a00
  if (FL[0] != FL[1]) goto L4c1bb3;  // @162_4c1a00
  ecx = edi;  // @163_4c1a00
  eax = ext_4e5e80_thiscall1(ecx);  // @164_4c1a00
  ecx = edx = 0;  // @165_4c1a00
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 124)) :: "st");  // @166_4c1a00
  L4c1bb3:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 152) + 0), 4); v; });  // @168_4c1a00
  X1[1] = 0;  // @169_4c1a00
  X1[2] = 0;  // @170_4c1a00
  X1[3] = 0;  // @171_4c1a00
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; });  // @172_4c1a00
  X2[1] = 0;  // @173_4c1a00
  X2[2] = 0;  // @174_4c1a00
  X2[3] = 0;  // @175_4c1a00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @176_4c1a00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @177_4c1a00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @178_4c1a00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 172), &v, sizeof v); }  // @179_4c1a00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 213), &v, sizeof v); }  // @180_4c1a00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 209), &v, sizeof v); }  // @181_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 160) + 0), 4); v; });  // @182_4c1a00
  X0[1] = 0;  // @183_4c1a00
  X0[2] = 0;  // @184_4c1a00
  X0[3] = 0;  // @185_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 184) + 0), &X0[0], 4);  // @186_4c1a00
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4c1c1a;  // @187_4c1a00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 172), &v, sizeof v); }  // @188_4c1a00
  goto L4c1c3a;  // @189_4c1a00
  L4c1c1a:;
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @191_4c1a00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 172), &v, sizeof v); }  // @192_4c1a00
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @193_4c1a00
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @194_4c1a00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @195_4c1a00
  L4c1c3a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 192), &v, sizeof v); }  // @197_4c1a00
  X1[0] = 0;  // @198_4c1a00
  X1[1] = 0;  // @199_4c1a00
  X1[2] = 0;  // @200_4c1a00
  X1[3] = 0;  // @201_4c1a00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 188), &v, sizeof v); }  // @202_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 84) + 0), 4); v; });  // @203_4c1a00
  X0[1] = 0;  // @204_4c1a00
  X0[2] = 0;  // @205_4c1a00
  X0[3] = 0;  // @206_4c1a00
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4c1c67;  // @207_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 192) + 0), &X0[0], 4);  // @208_4c1a00
  edx = 0;  // @209_4c1a00
  FL[3] = edx;  // @210_4c1a00
  goto L4c1c6a;  // @211_4c1a00
  L4c1c67:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @213_4c1a00
  L4c1c6a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; });  // @215_4c1a00
  X0[1] = 0;  // @216_4c1a00
  X0[2] = 0;  // @217_4c1a00
  X0[3] = 0;  // @218_4c1a00
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 192) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 192) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 192) + 0), 4); v; }))))))) goto L4c1c85;  // @219_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 192) + 0), &X0[0], 4);  // @220_4c1a00
  edx = (u32)(1);  // @221_4c1a00
  L4c1c85:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 92) + 0), 4); v; });  // @223_4c1a00
  X0[1] = 0;  // @224_4c1a00
  X0[2] = 0;  // @225_4c1a00
  X0[3] = 0;  // @226_4c1a00
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 192) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 192) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 192) + 0), 4); v; }))))))) goto L4c1ca0;  // @227_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 192) + 0), &X0[0], 4);  // @228_4c1a00
  edx = (u32)(2);  // @229_4c1a00
  L4c1ca0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 84) + 0), 4); v; });  // @231_4c1a00
  X0[1] = 0;  // @232_4c1a00
  X0[2] = 0;  // @233_4c1a00
  X0[3] = 0;  // @234_4c1a00
  ecx = 0;  // @235_4c1a00
  FL[3] = ecx;  // @236_4c1a00
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @237_4c1a00
  eax = 0;  // @238_4c1a00
  FL[3] = eax;  // @239_4c1a00
  FL[2] = (edx & edx);  // @240_4c1a00
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @241_4c1a00
  FL[2] = (eax & ecx);  // @242_4c1a00
  if (FL[2] == 0) goto L4c1cc0;  // @243_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 188) + 0), &X0[0], 4);  // @244_4c1a00
  L4c1cc0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; });  // @246_4c1a00
  X0[1] = 0;  // @247_4c1a00
  X0[2] = 0;  // @248_4c1a00
  X0[3] = 0;  // @249_4c1a00
  ecx = 0;  // @250_4c1a00
  FL[3] = ecx;  // @251_4c1a00
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 188) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 188) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 188) + 0), 4); v; }))))))) ? 1 : 0)) & 0xff);  // @252_4c1a00
  eax = 0;  // @253_4c1a00
  FL[3] = eax;  // @254_4c1a00
  FL[0] = edx; FL[1] = (u32)(1);  // @255_4c1a00
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @256_4c1a00
  FL[2] = (eax & ecx);  // @257_4c1a00
  if (FL[2] == 0) goto L4c1ce5;  // @258_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 188) + 0), &X0[0], 4);  // @259_4c1a00
  L4c1ce5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 92) + 0), 4); v; });  // @261_4c1a00
  X0[1] = 0;  // @262_4c1a00
  X0[2] = 0;  // @263_4c1a00
  X0[3] = 0;  // @264_4c1a00
  ecx = 0;  // @265_4c1a00
  FL[3] = ecx;  // @266_4c1a00
  ecx = (ecx & 0xffffff00u) | (((((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 188) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 188) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 188) + 0), 4); v; }))))))) ? 1 : 0)) & 0xff);  // @267_4c1a00
  eax = 0;  // @268_4c1a00
  FL[3] = eax;  // @269_4c1a00
  FL[0] = edx; FL[1] = (u32)(2);  // @270_4c1a00
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @271_4c1a00
  FL[2] = (eax & ecx);  // @272_4c1a00
  if (FL[2] == 0) goto L4c1d0a;  // @273_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 188) + 0), &X0[0], 4);  // @274_4c1a00
  L4c1d0a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 188) + 0), 4); v; });  // @276_4c1a00
  X0[1] = 0;  // @277_4c1a00
  X0[2] = 0;  // @278_4c1a00
  X0[3] = 0;  // @279_4c1a00
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @280_4c1a00
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; })));  // @281_4c1a00
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; })));  // @282_4c1a00
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @283_4c1a00
  { double r_ = ext_634dd6_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @284_4c1a00   hand fix: log10(xmm0)
    // @285_4c1a00
  SD(&X0[0], U2D(X0[0], X0[1]) / U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 4), 4); v; })));  // @286_4c1a00
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @287_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 200) + 0), &X0[0], 4);  // @288_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 192) + 0), 4); v; });  // @289_4c1a00
  X0[1] = 0;  // @290_4c1a00
  X0[2] = 0;  // @291_4c1a00
  X0[3] = 0;  // @292_4c1a00
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @293_4c1a00
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; })));  // @294_4c1a00
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; })));  // @295_4c1a00
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @296_4c1a00
  { double r_ = ext_634dd6_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @297_4c1a00   hand fix: log10(xmm0)
    // @298_4c1a00
  SD(&X0[0], U2D(X0[0], X0[1]) / U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 4), 4); v; })));  // @299_4c1a00
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @300_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 204) + 0), &X0[0], 4);  // @301_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 124) + 0), 4); v; });  // @302_4c1a00
  X0[1] = 0;  // @303_4c1a00
  X0[2] = 0;  // @304_4c1a00
  X0[3] = 0;  // @305_4c1a00
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @306_4c1a00
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @307_4c1a00
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c1dd7;  // @308_4c1a00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; });  // @309_4c1a00
  X0[1] = 0;  // @310_4c1a00
  X0[2] = 0;  // @311_4c1a00
  X0[3] = 0;  // @312_4c1a00
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @313_4c1a00
  X1[1] = 0;  // @314_4c1a00
  X1[2] = 0;  // @315_4c1a00
  X1[3] = 0;  // @316_4c1a00
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L4c1da3;  // @317_4c1a00
  { u32 v = (u32)((u32)(1153957888)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @318_4c1a00
  goto L4c1dd7;  // @319_4c1a00
  L4c1da3:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806044) + 0), 4); v; });  // @321_4c1a00
  X1[1] = 0;  // @322_4c1a00
  X1[2] = 0;  // @323_4c1a00
  X1[3] = 0;  // @324_4c1a00
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 128) + 0), 4); v; })));  // @325_4c1a00
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; })));  // @326_4c1a00
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @327_4c1a00
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @328_4c1a00
  { double r_ = ext_634db2_dbl2(U2D(X0[0], X0[1]), U2D(X1[0], X1[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @329_4c1a00   hand fix: pow(xmm0, xmm1) SSE2 libm convention
    // @330_4c1a00
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896992) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896992) + 4), 4); v; })));  // @331_4c1a00
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @332_4c1a00
  __builtin_memcpy((void *)((u32)(esi + 124) + 0), &X0[0], 4);  // @333_4c1a00
  L4c1dd7:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @335_4c1a00
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @336_4c1a00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @337_4c1a00
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 208), &v, sizeof v); }  // @338_4c1a00
  return eax;  // @339_4c1a00
}
PCREG(4c1a00, lifted_4c1a00);

extern "C" u32 FASTCALL lifted_4e2220(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2) {   // hand fix: edx is an incoming register (passed on to 0x4e2560, which reads [edx+4], [edx+8])
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = (u32)(EBP - 4);  // @0_4e2220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4e2220
  esi = ecx;  // @2_4e2220
  PV[0] = (u32)(eax);  // @3_4e2220
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_4e2220
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_4e2220
  PV[3] = (u32)(edi);  // @6_4e2220
  eax = ext_4e2560_fastcall7(ecx, edx, PV[3], PV[2], PV[1], PV[0], (u32)(1));  // @7_4e2220
    // @8_4e2220
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @9_4e2220
  if (FL[2] == 0) goto L4e226a;  // @10_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @11_4e2220
  X0[1] = 0;  // @12_4e2220
  X0[2] = 0;  // @13_4e2220
  X0[3] = 0;  // @14_4e2220
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @15_4e2220
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @16_4e2220
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @17_4e2220
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @18_4e2220
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @19_4e2220
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @20_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @21_4e2220
  __builtin_memcpy((void *)((u32)(EBP + 12) + 0), &X0[0], 4);  // @22_4e2220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 12)) : "st");  // @23_4e2220
  return eax;  // @24_4e2220
  L4e226a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802756) + 0), 4); v; });  // @26_4e2220
  X0[1] = 0;  // @27_4e2220
  X0[2] = 0;  // @28_4e2220
  X0[3] = 0;  // @29_4e2220
  ecx = (u32)(EBP - 16);  // @30_4e2220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_4e2220
  PV[4] = (u32)(edi);  // @32_4e2220
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @33_4e2220
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @34_4e2220
  ecx = edx = 0;  // @35_4e2220
  PV[5] = (u32)(edi);  // @36_4e2220
  edx = esi;  // @37_4e2220
  ecx = (u32)(EBP - 28);  // @38_4e2220
  eax = ext_43e920_fastcall3(ecx, edx, PV[5]);  // @39_4e2220
  ecx = edx = 0;  // @40_4e2220
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @41_4e2220
  edx = esi;  // @42_4e2220
  ecx = (u32)(EBP - 40);  // @43_4e2220
  eax = ext_43e920_fastcall3(ecx, edx, PV[6]);  // @44_4e2220
  ecx = edx = 0;  // @45_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @46_4e2220
  X0[1] = 0;  // @47_4e2220
  X0[2] = 0;  // @48_4e2220
  X0[3] = 0;  // @49_4e2220
  X2[0] = 0;  // @50_4e2220
  X2[1] = 0;  // @51_4e2220
  X2[2] = 0;  // @52_4e2220
  X2[3] = 0;  // @53_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @54_4e2220
  X1[1] = 0;  // @55_4e2220
  X1[2] = 0;  // @56_4e2220
  X1[3] = 0;  // @57_4e2220
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @58_4e2220
  X3[1] = 0;  // @59_4e2220
  X3[2] = 0;  // @60_4e2220
  X3[3] = 0;  // @61_4e2220
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @62_4e2220
  X4[1] = 0;  // @63_4e2220
  X4[2] = 0;  // @64_4e2220
  X4[3] = 0;  // @65_4e2220
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @66_4e2220
  X5[1] = 0;  // @67_4e2220
  X5[2] = 0;  // @68_4e2220
  X5[3] = 0;  // @69_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @70_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @71_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @72_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @73_4e2220
  X0[1] = 0;  // @74_4e2220
  X0[2] = 0;  // @75_4e2220
  X0[3] = 0;  // @76_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @77_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @78_4e2220
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L4e233e;  // @79_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @80_4e2220
  X0[1] = 0;  // @81_4e2220
  X0[2] = 0;  // @82_4e2220
  X0[3] = 0;  // @83_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @84_4e2220
  X1[1] = 0;  // @85_4e2220
  X1[2] = 0;  // @86_4e2220
  X1[3] = 0;  // @87_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @88_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @89_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @90_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @91_4e2220
  X0[1] = 0;  // @92_4e2220
  X0[2] = 0;  // @93_4e2220
  X0[3] = 0;  // @94_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @95_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @96_4e2220
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4e233e;  // @97_4e2220
  ecx = (u32)(EBP - 16);  // @98_4e2220
  eax = ext_44c840_thiscall1(ecx);  // @99_4e2220
  ecx = 0;  // @100_4e2220
  eax = (u32)(EBP - 16);  // @101_4e2220
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @102_4e2220
  PV[7] = (u32)(eax);  // @103_4e2220
  edx = (u32)(EBP - 28);  // @104_4e2220
  ecx = (u32)(EBP - 52);  // @105_4e2220
  eax = ext_446ee0_fastcall3(ecx, edx, PV[7]);  // @106_4e2220
  ecx = edx = 0;  // @107_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @108_4e2220
  X0[1] = 0;  // @109_4e2220
  X0[2] = 0;  // @110_4e2220
  X0[3] = 0;  // @111_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @112_4e2220
  X1[1] = 0;  // @113_4e2220
  X1[2] = 0;  // @114_4e2220
  X1[3] = 0;  // @115_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @116_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @117_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @118_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @119_4e2220
  X0[1] = 0;  // @120_4e2220
  X0[2] = 0;  // @121_4e2220
  X0[3] = 0;  // @122_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @123_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @124_4e2220
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X1[0], 4);  // @125_4e2220
  L4e233e:;
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @127_4e2220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @128_4e2220
  ecx = (u32)(EBP - 16);  // @129_4e2220
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @130_4e2220
  ecx = edx = 0;  // @131_4e2220
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @132_4e2220
  edx = esi;  // @133_4e2220
  ecx = (u32)(EBP - 28);  // @134_4e2220
  eax = ext_43e920_fastcall3(ecx, edx, PV[9]);  // @135_4e2220
  ecx = edx = 0;  // @136_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @137_4e2220
  X0[1] = 0;  // @138_4e2220
  X0[2] = 0;  // @139_4e2220
  X0[3] = 0;  // @140_4e2220
  X2[0] = 0;  // @141_4e2220
  X2[1] = 0;  // @142_4e2220
  X2[2] = 0;  // @143_4e2220
  X2[3] = 0;  // @144_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @145_4e2220
  X1[1] = 0;  // @146_4e2220
  X1[2] = 0;  // @147_4e2220
  X1[3] = 0;  // @148_4e2220
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @149_4e2220
  X3[1] = 0;  // @150_4e2220
  X3[2] = 0;  // @151_4e2220
  X3[3] = 0;  // @152_4e2220
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @153_4e2220
  X4[1] = 0;  // @154_4e2220
  X4[2] = 0;  // @155_4e2220
  X4[3] = 0;  // @156_4e2220
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @157_4e2220
  X5[1] = 0;  // @158_4e2220
  X5[2] = 0;  // @159_4e2220
  X5[3] = 0;  // @160_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @161_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @162_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @163_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @164_4e2220
  X0[1] = 0;  // @165_4e2220
  X0[2] = 0;  // @166_4e2220
  X0[3] = 0;  // @167_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @168_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @169_4e2220
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L4e2401;  // @170_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @171_4e2220
  X0[1] = 0;  // @172_4e2220
  X0[2] = 0;  // @173_4e2220
  X0[3] = 0;  // @174_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @175_4e2220
  X1[1] = 0;  // @176_4e2220
  X1[2] = 0;  // @177_4e2220
  X1[3] = 0;  // @178_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @179_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @180_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @181_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @182_4e2220
  X0[1] = 0;  // @183_4e2220
  X0[2] = 0;  // @184_4e2220
  X0[3] = 0;  // @185_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @186_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @187_4e2220
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4e2401;  // @188_4e2220
  ecx = (u32)(EBP - 16);  // @189_4e2220
  eax = ext_44c840_thiscall1(ecx);  // @190_4e2220
  ecx = 0;  // @191_4e2220
  eax = (u32)(EBP - 16);  // @192_4e2220
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @193_4e2220
  PV[10] = (u32)(eax);  // @194_4e2220
  edx = (u32)(EBP - 40);  // @195_4e2220
  ecx = (u32)(EBP - 52);  // @196_4e2220
  eax = ext_446ee0_fastcall3(ecx, edx, PV[10]);  // @197_4e2220
  ecx = edx = 0;  // @198_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @199_4e2220
  X0[1] = 0;  // @200_4e2220
  X0[2] = 0;  // @201_4e2220
  X0[3] = 0;  // @202_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @203_4e2220
  X1[1] = 0;  // @204_4e2220
  X1[2] = 0;  // @205_4e2220
  X1[3] = 0;  // @206_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @207_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @208_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @209_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @210_4e2220
  X0[1] = 0;  // @211_4e2220
  X0[2] = 0;  // @212_4e2220
  X0[3] = 0;  // @213_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @214_4e2220
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @215_4e2220
  { float a_ = U2F(X0[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @216_4e2220
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @217_4e2220
  L4e2401:;
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @219_4e2220
  edx = edi;  // @220_4e2220
  ecx = (u32)(EBP - 16);  // @221_4e2220
  eax = ext_43e920_fastcall3(ecx, edx, PV[11]);  // @222_4e2220
  ecx = edx = 0;  // @223_4e2220
  PV[12] = (u32)(edi);  // @224_4e2220
  edx = esi;  // @225_4e2220
  ecx = (u32)(EBP - 40);  // @226_4e2220
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @227_4e2220
  ecx = edx = 0;  // @228_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @229_4e2220
  X0[1] = 0;  // @230_4e2220
  X0[2] = 0;  // @231_4e2220
  X0[3] = 0;  // @232_4e2220
  X2[0] = 0;  // @233_4e2220
  X2[1] = 0;  // @234_4e2220
  X2[2] = 0;  // @235_4e2220
  X2[3] = 0;  // @236_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @237_4e2220
  X1[1] = 0;  // @238_4e2220
  X1[2] = 0;  // @239_4e2220
  X1[3] = 0;  // @240_4e2220
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @241_4e2220
  X3[1] = 0;  // @242_4e2220
  X3[2] = 0;  // @243_4e2220
  X3[3] = 0;  // @244_4e2220
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @245_4e2220
  X4[1] = 0;  // @246_4e2220
  X4[2] = 0;  // @247_4e2220
  X4[3] = 0;  // @248_4e2220
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @249_4e2220
  X5[1] = 0;  // @250_4e2220
  X5[2] = 0;  // @251_4e2220
  X5[3] = 0;  // @252_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @253_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @254_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @255_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @256_4e2220
  X0[1] = 0;  // @257_4e2220
  X0[2] = 0;  // @258_4e2220
  X0[3] = 0;  // @259_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @260_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @261_4e2220
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L4e24c1;  // @262_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @263_4e2220
  X0[1] = 0;  // @264_4e2220
  X0[2] = 0;  // @265_4e2220
  X0[3] = 0;  // @266_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @267_4e2220
  X1[1] = 0;  // @268_4e2220
  X1[2] = 0;  // @269_4e2220
  X1[3] = 0;  // @270_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @271_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @272_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @273_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @274_4e2220
  X0[1] = 0;  // @275_4e2220
  X0[2] = 0;  // @276_4e2220
  X0[3] = 0;  // @277_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @278_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @279_4e2220
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4e24c1;  // @280_4e2220
  ecx = (u32)(EBP - 16);  // @281_4e2220
  eax = ext_44c840_thiscall1(ecx);  // @282_4e2220
  ecx = 0;  // @283_4e2220
  eax = (u32)(EBP - 16);  // @284_4e2220
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @285_4e2220
  PV[13] = (u32)(eax);  // @286_4e2220
  edx = (u32)(EBP - 28);  // @287_4e2220
  ecx = (u32)(EBP - 52);  // @288_4e2220
  eax = ext_446ee0_fastcall3(ecx, edx, PV[13]);  // @289_4e2220
  ecx = edx = 0;  // @290_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @291_4e2220
  X0[1] = 0;  // @292_4e2220
  X0[2] = 0;  // @293_4e2220
  X0[3] = 0;  // @294_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @295_4e2220
  X1[1] = 0;  // @296_4e2220
  X1[2] = 0;  // @297_4e2220
  X1[3] = 0;  // @298_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @299_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @300_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @301_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @302_4e2220
  X0[1] = 0;  // @303_4e2220
  X0[2] = 0;  // @304_4e2220
  X0[3] = 0;  // @305_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @306_4e2220
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @307_4e2220
  { float a_ = U2F(X0[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @308_4e2220
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @309_4e2220
  L4e24c1:;
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @311_4e2220
  edx = esi;  // @312_4e2220
  ecx = (u32)(EBP - 16);  // @313_4e2220
  eax = ext_43e920_fastcall3(ecx, edx, PV[14]);  // @314_4e2220
  ecx = edx = 0;  // @315_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @316_4e2220
  X1[1] = 0;  // @317_4e2220
  X1[2] = 0;  // @318_4e2220
  X1[3] = 0;  // @319_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @320_4e2220
  X0[1] = 0;  // @321_4e2220
  X0[2] = 0;  // @322_4e2220
  X0[3] = 0;  // @323_4e2220
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @324_4e2220
  X2[1] = 0;  // @325_4e2220
  X2[2] = 0;  // @326_4e2220
  X2[3] = 0;  // @327_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @328_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @329_4e2220
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @330_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @331_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @332_4e2220
  X0[1] = 0;  // @333_4e2220
  X0[2] = 0;  // @334_4e2220
  X0[3] = 0;  // @335_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @336_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @337_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @338_4e2220
  X0[1] = 0;  // @339_4e2220
  X0[2] = 0;  // @340_4e2220
  X0[3] = 0;  // @341_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @342_4e2220
  { float a_ = U2F(X1[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })); X1[0] = (a_ < b_) ? X1[0] : F2U(b_); }  // @343_4e2220
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @344_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @345_4e2220
  X0[1] = 0;  // @346_4e2220
  X0[2] = 0;  // @347_4e2220
  X0[3] = 0;  // @348_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @349_4e2220
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @350_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @351_4e2220
  X0[1] = 0;  // @352_4e2220
  X0[2] = 0;  // @353_4e2220
  X0[3] = 0;  // @354_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @355_4e2220
  { float a_ = U2F(X2[0]), b_ = U2F(X1[0]); X2[0] = (a_ < b_) ? X2[0] : F2U(b_); }  // @356_4e2220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @357_4e2220
  X1[1] = 0;  // @358_4e2220
  X1[2] = 0;  // @359_4e2220
  X1[3] = 0;  // @360_4e2220
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @361_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @362_4e2220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @363_4e2220
  X0[1] = 0;  // @364_4e2220
  X0[2] = 0;  // @365_4e2220
  X0[3] = 0;  // @366_4e2220
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @367_4e2220
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @368_4e2220
  { float a_ = U2F(X1[0]), b_ = U2F(X2[0]); X1[0] = (a_ < b_) ? X1[0] : F2U(b_); }  // @369_4e2220
  __builtin_memcpy((void *)((u32)(EBP + 12) + 0), &X1[0], 4);  // @370_4e2220
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP + 12)) : "st");  // @371_4e2220
  return eax;  // @372_4e2220
}
PCREG(4e2220, lifted_4e2220);

extern "C" u32 THISCALL lifted_451fc0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x480] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x380);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x380 + 8, &a0, 4);
  __builtin_memcpy(F + 0x380 + 12, &a1, 4);
  __builtin_memcpy(F + 0x380 + 16, &a2, 4);
  __builtin_memcpy(F + 0x380 + 20, &a3, 4);
  __builtin_memcpy(F + 0x380 + 24, &a4, 4);
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 24) + 0), 4); v; });  // @0_451fc0
  X0[1] = 0;  // @1_451fc0
  X0[2] = 0;  // @2_451fc0
  X0[3] = 0;  // @3_451fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_451fc0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_451fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @6_451fc0
  edi = ecx;  // @7_451fc0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @8_451fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 764) + 40), &v, sizeof v); }  // @9_451fc0
  eax = 0;  // @10_451fc0
  FL[3] = eax;  // @11_451fc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 764) + 28), &v, sizeof v); }  // @12_451fc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 764) + 20), &v, sizeof v); }  // @13_451fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @14_451fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 764) + 12), &v, sizeof v); }  // @15_451fc0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 764) + 16), &v, sizeof v); }  // @16_451fc0
  __builtin_memcpy((void *)((u32)((EBP - 764) + 44) + 0), &X0[0], 4);  // @17_451fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 764) + 32), &v, sizeof v); }  // @18_451fc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; }); FL[1] = eax;  // @19_451fc0
  if (FL[0] == FL[1]) goto L452284;  // @20_451fc0
  X2[0] = 0;  // @21_451fc0
  X2[1] = 0;  // @22_451fc0
  X2[2] = 0;  // @23_451fc0
  X2[3] = 0;  // @24_451fc0
  ecx = 0;  // @25_451fc0
  FL[3] = ecx;  // @26_451fc0
  L452022:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; }) & (u32)(128));  // @28_451fc0
  if (FL[2] == 0) goto L45226f;  // @29_451fc0
  X3[0] = X2[0];  // @30_451fc0
  X3[1] = X2[1];  // @31_451fc0
  X3[2] = X2[2];  // @32_451fc0
  X3[3] = X2[3];  // @33_451fc0
  eax = (u32)(edx + 28);  // @34_451fc0
  ecx = (u32)(8);  // @35_451fc0
  L452040:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @37_451fc0
  X2[1] = 0;  // @38_451fc0
  X2[2] = 0;  // @39_451fc0
  X2[3] = 0;  // @40_451fc0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @41_451fc0
  X1[1] = 0;  // @42_451fc0
  X1[2] = 0;  // @43_451fc0
  X1[3] = 0;  // @44_451fc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @45_451fc0
  X0[1] = 0;  // @46_451fc0
  X0[2] = 0;  // @47_451fc0
  X0[3] = 0;  // @48_451fc0
  eax = (eax + (u32)(12));  // @49_451fc0
  FL[3] = eax;  // @50_451fc0
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @51_451fc0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @52_451fc0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @53_451fc0
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @54_451fc0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @55_451fc0
  { float a_ = U2F(X2[0]), b_ = U2F(X3[0]); X2[0] = (a_ > b_) ? X2[0] : F2U(b_); }  // @56_451fc0
  X3[0] = X2[0];  // @57_451fc0
  X3[1] = X2[1];  // @58_451fc0
  X3[2] = X2[2];  // @59_451fc0
  X3[3] = X2[3];  // @60_451fc0
  ecx = (ecx - (u32)(1));  // @61_451fc0
  FL[3] = ecx;  // @62_451fc0
  if (FL[3] != 0) goto L452040;  // @63_451fc0
  edx = (edx + (u32)(16));  // @64_451fc0
  FL[3] = edx;  // @65_451fc0
  __builtin_memcpy((void *)((u32)((EBP - 764) + 36) + 0), &X3[0], 4);  // @66_451fc0
  ecx = esi;  // @67_451fc0
  eax = ext_4e0870_fastcall2(ecx, edx);  // @68_451fc0
  ecx = edx = 0;  // @69_451fc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 36) + 0), 4); v; });  // @70_451fc0
  X0[1] = 0;  // @71_451fc0
  X0[2] = 0;  // @72_451fc0
  X0[3] = 0;  // @73_451fc0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @74_451fc0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 764) + 24)) :: "st");  // @75_451fc0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @76_451fc0
  ecx = edx = 0;  // @77_451fc0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @78_451fc0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 24) + 0), 4); v; })));  // @79_451fc0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 24) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 24) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 24) + 0), 4); v; }))))))) goto L45224f;  // @80_451fc0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 16), sizeof v); (u32)v; });  // @81_451fc0
  eax = (u32)((EBP - 768) + 92);  // @82_451fc0
  ecx = edi;  // @83_451fc0
  PV[1] = (u32)(eax);  // @84_451fc0
  eax = ext_4526a0_thiscall3(ecx, PV[1], PV[0]);   // hand fix: ecx = this (edi)  // @85_451fc0
  ecx = edx = 0;  // @86_451fc0
  esi = (u32)((EBP - 764) + 88);  // @87_451fc0
  edi = 0;  // @88_451fc0
  FL[3] = edi;  // @89_451fc0
  L4520c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 28), sizeof v); (u32)v; });  // @91_451fc0
  PV[2] = (u32)(esi);  // @92_451fc0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 768) + 24), sizeof v); (u32)v; });  // @93_451fc0
  eax = ext_451ba0_thiscall3(ecx, PV[3], PV[2]);   // hand fix: ecx = this  // @94_451fc0
  ecx = edx = 0;  // @95_451fc0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @96_451fc0
  if (FL[2] != 0) goto L4522a5;  // @97_451fc0
  edi = (edi + 1);  // @98_451fc0
  FL[3] = edi;  // @99_451fc0
  esi = (esi + (u32)(48));  // @100_451fc0
  FL[3] = esi;  // @101_451fc0
  FL[0] = edi; FL[1] = (u32)(5);  // @102_451fc0
  if (FL[0] != FL[1]) goto L4520c0;  // @103_451fc0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 16), sizeof v); (u32)v; });  // @104_451fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 768) + 32), sizeof v); (u32)v; });  // @105_451fc0
  eax = (u32)((EBP - 768) + 332);  // @106_451fc0
  PV[5] = (u32)(eax);  // @107_451fc0
  eax = ext_4522d0_thiscall3(ecx, PV[5], PV[4]);  // @108_451fc0
  ecx = edx = 0;  // @109_451fc0
  edi = 0;  // @110_451fc0
  FL[3] = edi;  // @111_451fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 764) + 48), &v, sizeof v); }  // @112_451fc0
  esi = (u32)((EBP - 764) + 328);  // @113_451fc0
  FL[2] = (eax & eax);  // @114_451fc0
  if (FL[2] == 0) goto L452258;  // @115_451fc0
  L452110:;
  edx = (u32)(esi + 12);  // @117_451fc0
  PV[6] = (u32)(esi);  // @118_451fc0
  ecx = (u32)((EBP - 768) + 56);  // @119_451fc0
  eax = ext_43e920_fastcall3(ecx, edx, PV[6]);  // @120_451fc0
  ecx = edx = 0;  // @121_451fc0
  edx = (u32)(esi + 24);  // @122_451fc0
  PV[7] = (u32)(esi);  // @123_451fc0
  ecx = (u32)((EBP - 768) + 68);  // @124_451fc0
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @125_451fc0
  ecx = edx = 0;  // @126_451fc0
  eax = (u32)((EBP - 764) + 64);  // @127_451fc0
  PV[8] = (u32)(eax);  // @128_451fc0
  edx = (u32)((EBP - 768) + 56);  // @129_451fc0
  ecx = (u32)((EBP - 768) + 80);  // @130_451fc0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[8]);  // @131_451fc0
  ecx = edx = 0;  // @132_451fc0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 20), sizeof v); (u32)v; });  // @133_451fc0
  edx = esi;  // @134_451fc0
  ecx = (u32)((EBP - 768) + 56);  // @135_451fc0
  eax = ext_43e920_fastcall3(ecx, edx, PV[9]);  // @136_451fc0
  ecx = edx = 0;  // @137_451fc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 56) + 0), 4); v; });  // @138_451fc0
  X0[1] = 0;  // @139_451fc0
  X0[2] = 0;  // @140_451fc0
  X0[3] = 0;  // @141_451fc0
  X2[0] = 0;  // @142_451fc0
  X2[1] = 0;  // @143_451fc0
  X2[2] = 0;  // @144_451fc0
  X2[3] = 0;  // @145_451fc0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 52) + 0), 4); v; });  // @146_451fc0
  X1[1] = 0;  // @147_451fc0
  X1[2] = 0;  // @148_451fc0
  X1[3] = 0;  // @149_451fc0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 76) + 0), 4); v; });  // @150_451fc0
  X3[1] = 0;  // @151_451fc0
  X3[2] = 0;  // @152_451fc0
  X3[3] = 0;  // @153_451fc0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 80) + 0), 4); v; });  // @154_451fc0
  X4[1] = 0;  // @155_451fc0
  X4[2] = 0;  // @156_451fc0
  X4[3] = 0;  // @157_451fc0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 84) + 0), 4); v; });  // @158_451fc0
  X5[1] = 0;  // @159_451fc0
  X5[2] = 0;  // @160_451fc0
  X5[3] = 0;  // @161_451fc0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @162_451fc0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @163_451fc0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @164_451fc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 60) + 0), 4); v; });  // @165_451fc0
  X0[1] = 0;  // @166_451fc0
  X0[2] = 0;  // @167_451fc0
  X0[3] = 0;  // @168_451fc0
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @169_451fc0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @170_451fc0
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L45223b;  // @171_451fc0
  eax = (u32)((EBP - 764) + 76);  // @172_451fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 764) + 24), &v, sizeof v); }  // @173_451fc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X2[0])) || (U2F(X3[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @174_451fc0
  FL[2] = ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X2[0])) || (U2F(X3[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @175_451fc0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4521b2;  // @176_451fc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X4[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X4[0]) != U2F(X4[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X4[0]) < U2F(X2[0])) || (U2F(X4[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @177_451fc0
  FL[2] = ((u32)(0x02 | (!(U2F(X4[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X4[0]) != U2F(X4[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X4[0]) < U2F(X2[0])) || (U2F(X4[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @178_451fc0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4521b2;  // @179_451fc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X5[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X5[0]) != U2F(X5[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X5[0]) < U2F(X2[0])) || (U2F(X5[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @180_451fc0
  FL[2] = ((u32)(0x02 | (!(U2F(X5[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X5[0]) != U2F(X5[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X5[0]) < U2F(X2[0])) || (U2F(X5[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @181_451fc0
  if (__builtin_parity(FL[2] & 0xff)) goto L4521f2;  // @182_451fc0
  L4521b2:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 764) + 36), &v, sizeof v); }  // @184_451fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 24), sizeof v); (u32)v; });  // @185_451fc0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @186_451fc0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @187_451fc0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @188_451fc0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @189_451fc0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @190_451fc0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @191_451fc0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @192_451fc0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @193_451fc0
  __asm__ volatile("fsqrt" ::: "st");  // @194_451fc0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 764) + 36)) : "st");  // @195_451fc0
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @196_451fc0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @197_451fc0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @198_451fc0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @199_451fc0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @200_451fc0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @201_451fc0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @202_451fc0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @203_451fc0
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @204_451fc0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @205_451fc0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 764) + 36)) :: "st");  // @206_451fc0
  L4521f2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 20), sizeof v); (u32)v; });  // @208_451fc0
  eax = (u32)(esi + 24);  // @209_451fc0
  PV[10] = (u32)(eax);  // @210_451fc0
  eax = (u32)(esi + 12);  // @211_451fc0
  PV[11] = (u32)(eax);  // @212_451fc0
  PV[12] = (u32)(esi);  // @213_451fc0
  edx = (u32)((EBP - 776) + 88);  // @214_451fc0
  eax = ext_4e2220_fastcall5(ecx, edx, PV[12], PV[11], PV[10]);   // hand fix: fastcall (edx = &vec)  // @215_451fc0
  ecx = edx = 0;  // @216_451fc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 44) + 0), 4); v; });  // @217_451fc0
  X0[1] = 0;  // @218_451fc0
  X0[2] = 0;  // @219_451fc0
  X0[3] = 0;  // @220_451fc0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 764) + 24)) :: "st");  // @221_451fc0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 24) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 24) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 764) + 24) + 0), 4); v; }))))))) goto L452238;  // @222_451fc0
  edx = esi;  // @223_451fc0
  ecx = ebx;  // @224_451fc0
  eax = ext_4de420_fastcall2(ecx, edx);  // @225_451fc0
    // @226_451fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 12), sizeof v); (u32)v; });  // @227_451fc0
  eax = (eax + 1);  // @228_451fc0
  FL[3] = eax;  // @229_451fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 764) + 12), &v, sizeof v); }  // @230_451fc0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @231_451fc0
  if (FL[0] == FL[1]) goto L452284;  // @232_451fc0
  ebx = (ebx + (u32)(36));  // @233_451fc0
  FL[3] = ebx;  // @234_451fc0
  X2[0] = 0;  // @235_451fc0
  X2[1] = 0;  // @236_451fc0
  X2[2] = 0;  // @237_451fc0
  X2[3] = 0;  // @238_451fc0
  goto L45223f;  // @239_451fc0
  L452238:;
  X2[0] = 0;  // @241_451fc0
  X2[1] = 0;  // @242_451fc0
  X2[2] = 0;  // @243_451fc0
  X2[3] = 0;  // @244_451fc0
  L45223b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 12), sizeof v); (u32)v; });  // @246_451fc0
  L45223f:;
  edi = (edi + 1);  // @248_451fc0
  FL[3] = edi;  // @249_451fc0
  esi = (esi + (u32)(36));  // @250_451fc0
  FL[3] = esi;  // @251_451fc0
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 48), sizeof v); (u32)v; });  // @252_451fc0
  if (FL[0] != FL[1]) goto L452110;  // @253_451fc0
  goto L45225f;  // @254_451fc0
  L45224f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 12), sizeof v); (u32)v; });  // @256_451fc0
  X2[0] = 0;  // @257_451fc0
  X2[1] = 0;  // @258_451fc0
  X2[2] = 0;  // @259_451fc0
  X2[3] = 0;  // @260_451fc0
  goto L452267;  // @261_451fc0
  L452258:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 12), sizeof v); (u32)v; });  // @263_451fc0
  X2[0] = 0;  // @264_451fc0
  X2[1] = 0;  // @265_451fc0
  X2[2] = 0;  // @266_451fc0
  X2[3] = 0;  // @267_451fc0
  L45225f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 28), sizeof v); (u32)v; });  // @269_451fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 20), sizeof v); (u32)v; });  // @270_451fc0
  L452267:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 16), sizeof v); (u32)v; });  // @272_451fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 32), sizeof v); (u32)v; });  // @273_451fc0
  L45226f:;
  ecx = (ecx + 1);  // @275_451fc0
  FL[3] = ecx;  // @276_451fc0
  edx = (edx + (u32)(124));  // @277_451fc0
  FL[3] = edx;  // @278_451fc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 764) + 32), &v, sizeof v); }  // @279_451fc0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 764) + 16), &v, sizeof v); }  // @280_451fc0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @281_451fc0
  if (FL[0] != FL[1]) goto L452022;  // @282_451fc0
  L452284:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 40), sizeof v); (u32)v; });  // @284_451fc0
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @285_451fc0
  ext_633654(G(u32, 0x6f5630));  // @286_451fc0
  return eax;  // @287_451fc0
  L4522a5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 764) + 40), sizeof v); (u32)v; });  // @289_451fc0
  eax = 0;  // @290_451fc0
  FL[3] = eax;  // @291_451fc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @292_451fc0
  ext_633654(G(u32, 0x6f5630));  // @293_451fc0
  return eax;  // @294_451fc0
}
PCREG(451fc0, lifted_451fc0);

extern "C" u32 THISCALL lifted_46f9d0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
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
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_46f9d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @1_46f9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @2_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_46f9d0
  edi = ecx;  // @4_46f9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @5_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @6_46f9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @7_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @8_46f9d0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(11264));  // @9_46f9d0
  if (FL[2] != 0) goto L46fd7c;  // @10_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_46f9d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 732)))(ecx);  // @12_46f9d0
  ecx = edx = 0;  // @13_46f9d0
  esi = eax;  // @14_46f9d0
  ecx = (u32)(EBP - 76);  // @15_46f9d0
  FL[2] = (esi & esi);  // @16_46f9d0
  if (FL[2] == 0) esi = edi;  // @17_46f9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @18_46f9d0
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @19_46f9d0
    // @20_46f9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @21_46f9d0
  ecx = (u32)(EBP - 76);  // @22_46f9d0
  eax = ext_4de480_fastcall2(ecx, edx);  // @23_46f9d0
  ecx = edx = 0;  // @24_46f9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @25_46f9d0
  eax = (u32)(EBP - 76);  // @26_46f9d0
  PV[0] = (u32)(eax);  // @27_46f9d0
  edx = (edx + (u32)(36));  // @28_46f9d0
  FL[3] = edx;  // @29_46f9d0
  ecx = (u32)(EBP - 40);  // @30_46f9d0
  eax = ext_441970_fastcall3(ecx, edx, PV[0]);  // @31_46f9d0
  ecx = edx = 0;  // @32_46f9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @33_46f9d0
  eax = (u32)(EBP - 40);  // @34_46f9d0
  PV[1] = (u32)(eax);  // @35_46f9d0
  ecx = (u32)(EBP - 164);  // @36_46f9d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[1]);  // @37_46f9d0
  ecx = edx = 0;  // @38_46f9d0
  FL[2] = (ebx & ebx);  // @39_46f9d0
  if (FL[2] == 0) goto L46fc00;  // @40_46f9d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(11);  // @41_46f9d0
  if (FL[0] != FL[1]) goto L46fc00;  // @42_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 130) + 0), 4); v; });  // @43_46f9d0
  X0[1] = 0;  // @44_46f9d0
  X0[2] = 0;  // @45_46f9d0
  X0[3] = 0;  // @46_46f9d0
  esi = (u32)(edi + 130);  // @47_46f9d0
  X1[0] = 0;  // @48_46f9d0
  X1[1] = 0;  // @49_46f9d0
  X1[2] = 0;  // @50_46f9d0
  X1[3] = 0;  // @51_46f9d0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @52_46f9d0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @53_46f9d0
  if (!__builtin_parity(FL[2] & 0xff)) goto L46fad5;  // @54_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @55_46f9d0
  X0[1] = 0;  // @56_46f9d0
  X0[2] = 0;  // @57_46f9d0
  X0[3] = 0;  // @58_46f9d0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @59_46f9d0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @60_46f9d0
  if (!__builtin_parity(FL[2] & 0xff)) goto L46fad5;  // @61_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @62_46f9d0
  X0[1] = 0;  // @63_46f9d0
  X0[2] = 0;  // @64_46f9d0
  X0[3] = 0;  // @65_46f9d0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @66_46f9d0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @67_46f9d0
  if (!__builtin_parity(FL[2] & 0xff)) goto L46fad5;  // @68_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @69_46f9d0
  X0[1] = 0;  // @70_46f9d0
  X0[2] = 0;  // @71_46f9d0
  X0[3] = 0;  // @72_46f9d0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @73_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; });  // @74_46f9d0
  X0[1] = 0;  // @75_46f9d0
  X0[2] = 0;  // @76_46f9d0
  X0[3] = 0;  // @77_46f9d0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @78_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 156) + 0), 4); v; });  // @79_46f9d0
  X0[1] = 0;  // @80_46f9d0
  X0[2] = 0;  // @81_46f9d0
  X0[3] = 0;  // @82_46f9d0
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @83_46f9d0
  goto L46faf2;  // @84_46f9d0
  L46fad5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @86_46f9d0
  X0[1] = 0;  // @87_46f9d0
  X0[2] = 0;  // @88_46f9d0
  X0[3] = 0;  // @89_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @90_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @91_46f9d0
  X0[1] = 0;  // @92_46f9d0
  X0[2] = 0;  // @93_46f9d0
  X0[3] = 0;  // @94_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @95_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @96_46f9d0
  X0[1] = 0;  // @97_46f9d0
  X0[2] = 0;  // @98_46f9d0
  X0[3] = 0;  // @99_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @100_46f9d0
  L46faf2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @102_46f9d0
  ecx = (u32)(EBP - 28);  // @103_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @104_46f9d0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 4), 4); v; });  // @105_46f9d0
  X0[2] = 0;  // @106_46f9d0
  X0[3] = 0;  // @107_46f9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @108_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @109_46f9d0
  PV[2] = (u32)(ecx);  // @110_46f9d0
  ecx = ebx;  // @111_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @112_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @113_46f9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[2]);  // @114_46f9d0
  ecx = edx = 0;  // @115_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @116_46f9d0
  X0[1] = 0;  // @117_46f9d0
  X0[2] = 0;  // @118_46f9d0
  X0[3] = 0;  // @119_46f9d0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; });  // @120_46f9d0
  X3[1] = 0;  // @121_46f9d0
  X3[2] = 0;  // @122_46f9d0
  X3[3] = 0;  // @123_46f9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @124_46f9d0
  X1[1] = 0;  // @125_46f9d0
  X1[2] = 0;  // @126_46f9d0
  X1[3] = 0;  // @127_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @128_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @129_46f9d0
  X0[1] = 0;  // @130_46f9d0
  X0[2] = 0;  // @131_46f9d0
  X0[3] = 0;  // @132_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @133_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @134_46f9d0
  X0[1] = 0;  // @135_46f9d0
  X0[2] = 0;  // @136_46f9d0
  X0[3] = 0;  // @137_46f9d0
  X2[0] = X0[0];  // @138_46f9d0
  X2[1] = X0[1];  // @139_46f9d0
  X2[2] = X0[2];  // @140_46f9d0
  X2[3] = X0[3];  // @141_46f9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(X3[0]));  // @142_46f9d0
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L46fb50;  // @143_46f9d0
  X1[0] = X2[0];  // @144_46f9d0
  X1[1] = X2[1];  // @145_46f9d0
  X1[2] = X2[2];  // @146_46f9d0
  X1[3] = X2[3];  // @147_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @148_46f9d0
  L46fb50:;
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @150_46f9d0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L46fb5e;  // @151_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @152_46f9d0
  L46fb5e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @154_46f9d0
  ecx = (u32)(EBP - 16);  // @155_46f9d0
  PV[3] = (u32)(ecx);  // @156_46f9d0
  ecx = ebx;  // @157_46f9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[3]);  // @158_46f9d0
  ecx = edx = 0;  // @159_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @160_46f9d0
  X0[1] = 0;  // @161_46f9d0
  X0[2] = 0;  // @162_46f9d0
  X0[3] = 0;  // @163_46f9d0
  ecx = ebx;  // @164_46f9d0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @165_46f9d0
  X4[1] = 0;  // @166_46f9d0
  X4[2] = 0;  // @167_46f9d0
  X4[3] = 0;  // @168_46f9d0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; });  // @169_46f9d0
  X3[1] = 0;  // @170_46f9d0
  X3[2] = 0;  // @171_46f9d0
  X3[3] = 0;  // @172_46f9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 156) + 0), 4); v; });  // @173_46f9d0
  X1[1] = 0;  // @174_46f9d0
  X1[2] = 0;  // @175_46f9d0
  X1[3] = 0;  // @176_46f9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @177_46f9d0
  X2[1] = 0;  // @178_46f9d0
  X2[2] = 0;  // @179_46f9d0
  X2[3] = 0;  // @180_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @181_46f9d0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @182_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @183_46f9d0
  X0[1] = 0;  // @184_46f9d0
  X0[2] = 0;  // @185_46f9d0
  X0[3] = 0;  // @186_46f9d0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @187_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @188_46f9d0
  X0[1] = 0;  // @189_46f9d0
  X0[2] = 0;  // @190_46f9d0
  X0[3] = 0;  // @191_46f9d0
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @192_46f9d0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @193_46f9d0
  X4[0] = F2U(U2F(X4[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @194_46f9d0
  X3[0] = F2U(U2F(X3[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @195_46f9d0
  PV[4] = (u32)(esi);  // @196_46f9d0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @197_46f9d0
  X4[0] = F2U(U2F(X4[0]) * U2F(X2[0]));  // @198_46f9d0
  X3[0] = F2U(U2F(X3[0]) * U2F(X2[0]));  // @199_46f9d0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @200_46f9d0
  X4[0] = F2U(U2F(X4[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @201_46f9d0
  X3[0] = F2U(U2F(X3[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @202_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X1[0], 4);  // @203_46f9d0
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X1[0], 4);  // @204_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 164) + 0), &X4[0], 4);  // @205_46f9d0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X4[0], 4);  // @206_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 160) + 0), &X3[0], 4);  // @207_46f9d0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X3[0], 4);  // @208_46f9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[4]);  // @209_46f9d0
  ecx = edx = 0;  // @210_46f9d0
  L46fc00:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @212_46f9d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @213_46f9d0
  FL[2] = (ecx & ecx);  // @214_46f9d0
  if (FL[2] == 0) goto L46fd7b;  // @215_46f9d0
  L46fc11:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @217_46f9d0
  if (FL[0] == FL[1]) goto L46fc22;  // @218_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @219_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @220_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @221_46f9d0
  goto L46fc27;  // @222_46f9d0
  L46fc22:;
  eax = (u32)(2097154);  // @224_46f9d0
  L46fc27:;
  FL[2] = (eax & (u32)(1048576));  // @226_46f9d0
  if (FL[2] != 0) goto L46fd5f;  // @227_46f9d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @228_46f9d0
  if (FL[0] == FL[1]) goto L46fd5f;  // @229_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @230_46f9d0
  FL[2] = (eax & (u32)(11264));  // @231_46f9d0
  if (FL[2] != 0) goto L46fd5f;  // @232_46f9d0
  FL[2] = (eax & (u32)(2097152));  // @233_46f9d0
  if (FL[2] != 0) goto L46fc65;  // @234_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @235_46f9d0
  FL[2] = (eax & eax);  // @236_46f9d0
  if (FL[2] == 0) goto L46fc5e;  // @237_46f9d0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @238_46f9d0
  ecx = edx = 0;  // @239_46f9d0
  goto L46fc5f;  // @240_46f9d0
  L46fc5e:;
  __builtin_trap();  // @242_46f9d0
  L46fc5f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @244_46f9d0
  L46fc65:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 80), sizeof v); (u32)v; });  // @246_46f9d0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @247_46f9d0
  if (FL[0] == FL[1]) goto L46fce9;  // @248_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 36) + 0), 4); v; });  // @249_46f9d0
  X0[1] = 0;  // @250_46f9d0
  X0[2] = 0;  // @251_46f9d0
  X0[3] = 0;  // @252_46f9d0
  edx = ecx;  // @253_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @254_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 40) + 0), 4); v; });  // @255_46f9d0
  X0[1] = 0;  // @256_46f9d0
  X0[2] = 0;  // @257_46f9d0
  X0[3] = 0;  // @258_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @259_46f9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 44) + 0), 4); v; });  // @260_46f9d0
  X0[1] = 0;  // @261_46f9d0
  X0[2] = 0;  // @262_46f9d0
  X0[3] = 0;  // @263_46f9d0
  ecx = (u32)(EBP - 112);  // @264_46f9d0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @265_46f9d0
  eax = ext_4de420_fastcall2(ecx, edx);  // @266_46f9d0
    // @267_46f9d0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @268_46f9d0
  if (FL[0] == FL[1]) goto L46fcc7;  // @269_46f9d0
  L46fca0:;
  edx = esi;  // @271_46f9d0
  ecx = (u32)(EBP - 28);  // @272_46f9d0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @273_46f9d0
  ecx = edx = 0;  // @274_46f9d0
  edx = (u32)(esi + 36);  // @275_46f9d0
  ecx = (u32)(EBP - 28);  // @276_46f9d0
  eax = ext_441940_fastcall2(ecx, edx);  // @277_46f9d0
  ecx = edx = 0;  // @278_46f9d0
  edx = esi;  // @279_46f9d0
  ecx = (u32)(EBP - 112);  // @280_46f9d0
  eax = ext_4de480_fastcall2(ecx, edx);  // @281_46f9d0
  ecx = edx = 0;  // @282_46f9d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @283_46f9d0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @284_46f9d0
  if (FL[0] != FL[1]) goto L46fca0;  // @285_46f9d0
  L46fcc7:;
  eax = (u32)(EBP - 76);  // @287_46f9d0
  PV[5] = (u32)(eax);  // @288_46f9d0
  edx = (u32)(EBP - 28);  // @289_46f9d0
  ecx = (u32)(EBP - 40);  // @290_46f9d0
  eax = ext_441970_fastcall3(ecx, edx, PV[5]);  // @291_46f9d0
  ecx = edx = 0;  // @292_46f9d0
  edx = (u32)(EBP - 164);  // @293_46f9d0
  ecx = (u32)(EBP - 40);  // @294_46f9d0
  eax = ext_441940_fastcall2(ecx, edx);  // @295_46f9d0
  ecx = edx = 0;  // @296_46f9d0
  edx = (u32)(EBP - 112);  // @297_46f9d0
  goto L46fd0c;  // @298_46f9d0
  L46fce9:;
  eax = (u32)(EBP - 76);  // @300_46f9d0
  edx = (u32)(ecx + 36);  // @301_46f9d0
  PV[6] = (u32)(eax);  // @302_46f9d0
  ecx = (u32)(EBP - 40);  // @303_46f9d0
  eax = ext_441970_fastcall3(ecx, edx, PV[6]);  // @304_46f9d0
  ecx = edx = 0;  // @305_46f9d0
  edx = (u32)(EBP - 164);  // @306_46f9d0
  ecx = (u32)(EBP - 40);  // @307_46f9d0
  eax = ext_441940_fastcall2(ecx, edx);  // @308_46f9d0
  ecx = edx = 0;  // @309_46f9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @310_46f9d0
  L46fd0c:;
  eax = (u32)(EBP - 76);  // @312_46f9d0
  PV[7] = (u32)(eax);  // @313_46f9d0
  ecx = (u32)(EBP - 148);  // @314_46f9d0
  eax = ext_4de440_fastcall3(ecx, edx, PV[7]);  // @315_46f9d0
  ecx = edx = 0;  // @316_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @317_46f9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @318_46f9d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; });  // @319_46f9d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 104), &v, sizeof v); }  // @320_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @321_46f9d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(eax + 104), &v, sizeof v); }  // @322_46f9d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; });  // @323_46f9d0
  eax = (u32)(EBP - 40);  // @324_46f9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @325_46f9d0
  PV[8] = (u32)(eax);  // @326_46f9d0
  eax = (u32)(EBP - 148);  // @327_46f9d0
  PV[9] = (u32)(eax);  // @328_46f9d0
  PV[10] = (u32)(ebx);  // @329_46f9d0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @330_46f9d0
  eax = ext_4daa70_thiscall6(ecx, PV[11], PV[10], PV[9], PV[8], (u32)(0));  // @331_46f9d0
  ecx = edx = 0;  // @332_46f9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @333_46f9d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 104), &v, sizeof v); }  // @334_46f9d0
  L46fd5f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @336_46f9d0
  ecx = (u32)(EBP - 152);  // @337_46f9d0
  PV[12] = (u32)(ecx);  // @338_46f9d0
  ecx = edi;  // @339_46f9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[12]);  // @340_46f9d0
  ecx = edx = 0;  // @341_46f9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @342_46f9d0
  FL[2] = (ecx & ecx);  // @343_46f9d0
  if (FL[2] != 0) goto L46fc11;  // @344_46f9d0
  L46fd7b:;
  L46fd7c:;
  ext_633654(G(u32, 0x6f5630));  // @347_46f9d0
  return eax;  // @348_46f9d0
}
PCREG(46f9d0, lifted_46f9d0);

extern "C" u32 THISCALL lifted_4b5fe0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4b5fe0
  esi = ecx;  // @1_4b5fe0
  ecx = edi;  // @2_4b5fe0
  eax = ext_4e5e60_thiscall1(ecx);  // @3_4b5fe0
  ecx = edx = 0;  // @4_4b5fe0
  FL[2] = (eax & eax);  // @5_4b5fe0
  ecx = edi;  // @6_4b5fe0
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @7_4b5fe0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @8_4b5fe0
  eax = ext_4e5e60_thiscall1(ecx);  // @9_4b5fe0
  ecx = edx = 0;  // @10_4b5fe0
  FL[2] = (eax & eax);  // @11_4b5fe0
  ecx = edi;  // @12_4b5fe0
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @13_4b5fe0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 153), &v, sizeof v); }  // @14_4b5fe0
  eax = ext_4e5e60_thiscall1(ecx);  // @15_4b5fe0
  ecx = edx = 0;  // @16_4b5fe0
  FL[2] = (eax & eax);  // @17_4b5fe0
  ecx = edi;  // @18_4b5fe0
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @19_4b5fe0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 154), &v, sizeof v); }  // @20_4b5fe0
  eax = ext_4e5e60_thiscall1(ecx);  // @21_4b5fe0
  ecx = edx = 0;  // @22_4b5fe0
  ecx = edi;  // @23_4b5fe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @24_4b5fe0
  eax = ext_4e5e60_thiscall1(ecx);  // @25_4b5fe0
  ecx = edx = 0;  // @26_4b5fe0
  FL[2] = (eax & eax);  // @27_4b5fe0
  ecx = edi;  // @28_4b5fe0
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @29_4b5fe0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @30_4b5fe0
  eax = ext_4e5e60_thiscall1(ecx);  // @31_4b5fe0
  ecx = edx = 0;  // @32_4b5fe0
  FL[2] = (eax & eax);  // @33_4b5fe0
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @34_4b5fe0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @35_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_4b5fe0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @37_4b5fe0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @38_4b5fe0
  if (FL[0] == FL[1]) goto L4b606e;  // @39_4b5fe0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @40_4b5fe0
  FL[3] = (eax & 0xff);  // @41_4b5fe0
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @42_4b5fe0
  if (FL[0] != FL[1]) goto L4b606e;  // @43_4b5fe0
  ecx = edi;  // @44_4b5fe0
  eax = ext_4e5e60_thiscall1(ecx);  // @45_4b5fe0
  ecx = edx = 0;  // @46_4b5fe0
  FL[2] = (eax & eax);  // @47_4b5fe0
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @48_4b5fe0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 161), &v, sizeof v); }  // @49_4b5fe0
  L4b606e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_4b5fe0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @52_4b5fe0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @53_4b5fe0
  if (FL[0] == FL[1]) goto L4b6089;  // @54_4b5fe0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @55_4b5fe0
  FL[3] = (eax & 0xff);  // @56_4b5fe0
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @57_4b5fe0
  if (FL[0] != FL[1]) goto L4b6089;  // @58_4b5fe0
  ecx = edi;  // @59_4b5fe0
  eax = ext_4e5e80_thiscall1(ecx);  // @60_4b5fe0
  ecx = edx = 0;  // @61_4b5fe0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 162)) :: "st");  // @62_4b5fe0
  L4b6089:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @64_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @66_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889280), (u32)(0), (u32)(6889180), (u32)(356));  // @68_4b5fe0
  ecx = edx = 0;  // @69_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 78), &v, sizeof v); }  // @70_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @72_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6840116), (u32)(0), (u32)(6889180), (u32)(357));  // @74_4b5fe0
  ecx = edx = 0;  // @75_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @76_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @78_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889300), (u32)(0), (u32)(6889180), (u32)(358));  // @80_4b5fe0
  ecx = edx = 0;  // @81_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @82_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @83_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @84_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889320), (u32)(0), (u32)(6889180), (u32)(359));  // @86_4b5fe0
  ecx = edx = 0;  // @87_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @88_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @90_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889228), (u32)(0), (u32)(6889180), (u32)(360));  // @92_4b5fe0
  ecx = edx = 0;  // @93_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 86), &v, sizeof v); }  // @94_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @96_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889344), (u32)(0), (u32)(6889180), (u32)(361));  // @98_4b5fe0
  ecx = edx = 0;  // @99_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @100_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6851600), (u32)(0), (u32)(6889180), (u32)(362));  // @104_4b5fe0
  ecx = edx = 0;  // @105_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @106_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @107_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @108_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6851612), (u32)(0), (u32)(6889180), (u32)(363));  // @110_4b5fe0
  ecx = edx = 0;  // @111_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @112_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @113_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @114_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6827544), (u32)(0), (u32)(6889180), (u32)(364));  // @116_4b5fe0
  ecx = edx = 0;  // @117_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @118_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @119_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @120_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @121_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6796552), (u32)(0), (u32)(6889180), (u32)(365));  // @122_4b5fe0
  ecx = edx = 0;  // @123_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @124_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @126_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6879720), (u32)(0), (u32)(6889180), (u32)(366));  // @128_4b5fe0
  ecx = edx = 0;  // @129_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 98), &v, sizeof v); }  // @130_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @131_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @132_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889368), (u32)(0), (u32)(6889180), (u32)(367));  // @134_4b5fe0
  ecx = edx = 0;  // @135_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @136_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @137_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @138_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889392), (u32)(0), (u32)(6889180), (u32)(368));  // @140_4b5fe0
  ecx = edx = 0;  // @141_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 102), &v, sizeof v); }  // @142_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @143_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @144_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889416), (u32)(0), (u32)(6889180), (u32)(369));  // @146_4b5fe0
  ecx = edx = 0;  // @147_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @148_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @150_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6852500), (u32)(0), (u32)(6889180), (u32)(370));  // @152_4b5fe0
  ecx = edx = 0;  // @153_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 106), &v, sizeof v); }  // @154_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @155_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @156_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @157_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889436), (u32)(0), (u32)(6889180), (u32)(371));  // @158_4b5fe0
  ecx = edx = 0;  // @159_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @160_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @161_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @162_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @163_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889456), (u32)(0), (u32)(6889180), (u32)(372));  // @164_4b5fe0
  ecx = edx = 0;  // @165_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @166_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @167_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @168_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @169_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889472), (u32)(0), (u32)(6889180), (u32)(373));  // @170_4b5fe0
  ecx = edx = 0;  // @171_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @172_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @173_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @174_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889508), (u32)(0), (u32)(6889180), (u32)(374));  // @176_4b5fe0
  ecx = edx = 0;  // @177_4b5fe0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @178_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @179_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @180_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @181_4b5fe0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @182_4b5fe0
  ecx = edx = 0;  // @183_4b5fe0
  PV[0] = (u32)(eax);  // @184_4b5fe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 238), &v, sizeof v); }  // @185_4b5fe0
  eax = ext_41e290_cdecl1(PV[0]);  // @186_4b5fe0
  ecx = edx = 0;  // @187_4b5fe0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 238), sizeof v); (u32)v; });  // @188_4b5fe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @189_4b5fe0
  eax = ext_41e290_cdecl1(PV[1]);  // @190_4b5fe0
  ecx = edx = 0;  // @191_4b5fe0
  ecx = 0;  // @192_4b5fe0
  FL[3] = ecx;  // @193_4b5fe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @194_4b5fe0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 238), sizeof v); (u32)v; }); FL[1] = ecx;  // @195_4b5fe0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4b63ed;  // @196_4b5fe0
  L4b63d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 144), sizeof v); (u32)v; });  // @198_4b5fe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @199_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 148), sizeof v); (u32)v; });  // @200_4b5fe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @201_4b5fe0
  ecx = (ecx + 1);  // @202_4b5fe0
  FL[3] = ecx;  // @203_4b5fe0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 238), sizeof v); (u32)v; });  // @204_4b5fe0
  if ((s32)FL[0] < (s32)FL[1]) goto L4b63d0;  // @205_4b5fe0
  L4b63ed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @207_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @208_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_4b5fe0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @210_4b5fe0
  ecx = edx = 0;  // @211_4b5fe0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; });  // @212_4b5fe0
  ecx = eax;  // @213_4b5fe0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @214_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6889544), PV[2], (u32)(2));  // @215_4b5fe0
  ecx = edx = 0;  // @216_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @217_4b5fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @218_4b5fe0
  FL[2] = (ecx & ecx);  // @219_4b5fe0
  if (FL[2] == 0) goto L4b6436;  // @220_4b5fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @221_4b5fe0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7235664), (u32)(6889556), (u32)(0));  // @222_4b5fe0
  ecx = edx = 0;  // @223_4b5fe0
  L4b6436:;
  return eax;  // @225_4b5fe0
}
PCREG(4b5fe0, lifted_4b5fe0);

extern "C" u32 THISCALL lifted_456590(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_456590
  eax = ecx;  // @1_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @2_456590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @3_456590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @4_456590
  ecx = (u32)(eax + 29);  // @5_456590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @6_456590
  L4565c0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_456590
  FL[2] = (edx & edx);  // @9_456590
  if (FL[2] == 0) goto L456984;  // @10_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @11_456590
  FL[2] = (ecx & ecx);  // @12_456590
  if (FL[2] == 0) goto L456968;  // @13_456590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2077), sizeof v); (u32)v; });  // @14_456590
  ecx = (u32)((s32)ecx * (s32)(u32)(2380));  // @15_456590
  edi = (edi + (u32)(4294964916));  // @16_456590
  FL[3] = edi;  // @17_456590
  edi = (edi + ecx);  // @18_456590
  FL[3] = edi;  // @19_456590
  if (FL[3] == 0) goto L456965;  // @20_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_456590
  PV[0] = (u32)(edx);  // @22_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @25_456590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[0]);  // @26_456590
  ecx = edx = 0;  // @27_456590
  edx = eax;  // @28_456590
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 81), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @29_456590
  if (FL[0] == FL[1]) goto L456965;  // @30_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 89) + 0), 4); v; });  // @31_456590
  X0[1] = 0;  // @32_456590
  X0[2] = 0;  // @33_456590
  X0[3] = 0;  // @34_456590
  eax = (u32)(edx + 225);  // @35_456590
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 36) + 0), 4); v; });  // @36_456590
  X1[1] = 0;  // @37_456590
  X1[2] = 0;  // @38_456590
  X1[3] = 0;  // @39_456590
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 73), sizeof v); (u32)v; });  // @40_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @41_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_456590
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @43_456590
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X1[0], 4);  // @44_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @47_456590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[1]);  // @48_456590
  ecx = edx = 0;  // @49_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @50_456590
  FL[2] = (eax & eax);  // @51_456590
  if (FL[2] == 0) goto L45665f;  // @52_456590
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 237), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @53_456590
  if (FL[0] != FL[1]) goto L45665f;  // @54_456590
  ecx = (u32)(EBP - 76);  // @55_456590
  PV[2] = (u32)(ecx);  // @56_456590
  ecx = (u32)(EBP - 60);  // @57_456590
  PV[3] = (u32)(ecx);  // @58_456590
  ecx = eax;  // @59_456590
  eax = ext_456b70_thiscall3(ecx, PV[3], PV[2]);  // @60_456590
  ecx = edx = 0;  // @61_456590
  L45665f:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; });  // @63_456590
  X1[1] = 0;  // @64_456590
  X1[2] = 0;  // @65_456590
  X1[3] = 0;  // @66_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @67_456590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @68_456590
  L456671:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @70_456590
  X4[1] = 0;  // @71_456590
  X4[2] = 0;  // @72_456590
  X4[3] = 0;  // @73_456590
  X0[0] = X4[0];  // @74_456590
  X0[1] = X4[1];  // @75_456590
  X0[2] = X4[2];  // @76_456590
  X0[3] = X4[3];  // @77_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @78_456590
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @79_456590
  FL[0] = eax; FL[1] = esi;  // @80_456590
  if ((s32)FL[0] >= (s32)FL[1]) goto L4568ab;  // @81_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2328) + 0), 4); v; });  // @82_456590
  X0[1] = 0;  // @83_456590
  X0[2] = 0;  // @84_456590
  X0[3] = 0;  // @85_456590
  ecx = esi;  // @86_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @87_456590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @88_456590
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @89_456590
  X5[1] = 0;  // @90_456590
  X5[2] = 0;  // @91_456590
  X5[3] = 0;  // @92_456590
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @93_456590
  ecx = (ecx - eax);  // @94_456590
  FL[3] = ecx;  // @95_456590
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @96_456590
  X4[0] = ecx; X4[1] = X4[2] = X4[3] = 0;  // @97_456590
  X4[0] = F2U((float)(s32)X4[0]);  // @98_456590
  X4[1] = F2U((float)(s32)X4[1]);  // @99_456590
  X4[2] = F2U((float)(s32)X4[2]);  // @100_456590
  X4[3] = F2U((float)(s32)X4[3]);  // @101_456590
  X4[0] = F2U(U2F(X4[0]) * U2F(X5[0]));  // @102_456590
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X4[0], 4);  // @103_456590
  if (FL[0] <= FL[1]) goto L4568ab;  // @104_456590
  edx = (u32)(edi + 24);  // @105_456590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @106_456590
  L4566d0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 12) + 0), 4); v; });  // @108_456590
  X0[1] = 0;  // @109_456590
  X0[2] = 0;  // @110_456590
  X0[3] = 0;  // @111_456590
  ecx = esi;  // @112_456590
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 16) + 0), 4); v; });  // @113_456590
  X3[1] = 0;  // @114_456590
  X3[2] = 0;  // @115_456590
  X3[3] = 0;  // @116_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @117_456590
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @118_456590
  X0[0] = X3[0];  // @119_456590
  X0[1] = X3[1];  // @120_456590
  X0[2] = X3[2];  // @121_456590
  X0[3] = X3[3];  // @122_456590
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 12) + 0), 4); v; })));  // @123_456590
  ecx = (ecx - eax);  // @124_456590
  FL[3] = ecx;  // @125_456590
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @126_456590
  X1[0] = F2U((float)(s32)X1[0]);  // @127_456590
  X1[1] = F2U((float)(s32)X1[1]);  // @128_456590
  X1[2] = F2U((float)(s32)X1[2]);  // @129_456590
  X1[3] = F2U((float)(s32)X1[3]);  // @130_456590
  X1[0] = F2U(U2F(X1[0]) * U2F(X5[0]));  // @131_456590
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L45687e;  // @132_456590
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @133_456590
  if (FL[0] == FL[1]) goto L456853;  // @134_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @137_456590
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6827288), (u32)(661));  // @138_456590
  ecx = edx = 0;  // @139_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @140_456590
  X0[1] = 0;  // @141_456590
  X0[2] = 0;  // @142_456590
  X0[3] = 0;  // @143_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @144_456590
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 44)) :: "st");  // @145_456590
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; }))))))) goto L456846;  // @146_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 12) + 0), 4); v; });  // @147_456590
  X0[1] = 0;  // @148_456590
  X0[2] = 0;  // @149_456590
  X0[3] = 0;  // @150_456590
  ecx = esi;  // @151_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @152_456590
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @153_456590
  X1[1] = 0;  // @154_456590
  X1[2] = 0;  // @155_456590
  X1[3] = 0;  // @156_456590
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @157_456590
  ecx = (ecx - eax);  // @158_456590
  FL[3] = ecx;  // @159_456590
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @160_456590
  X0[0] = F2U((float)(s32)X0[0]);  // @161_456590
  X0[1] = F2U((float)(s32)X0[1]);  // @162_456590
  X0[2] = F2U((float)(s32)X0[2]);  // @163_456590
  X0[3] = F2U((float)(s32)X0[3]);  // @164_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @165_456590
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @166_456590
  if ((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; }))))) goto L4567d9;  // @167_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @168_456590
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @169_456590
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @170_456590
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @171_456590
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @172_456590
  SD(&X0[0], (double)U2F(X0[0]));  // @173_456590
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @174_456590
  ecx = edx = 0;  // @175_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @176_456590
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @177_456590
  PV[4] = (u32)(ecx);  // @178_456590
  ecx = (u32)(EBP - 16);  // @179_456590
  edx = (u32)(eax - 12);  // @180_456590
  PV[5] = X0[0];  // @181_456590
  PV[6] = (u32)(eax);  // @182_456590
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @183_456590
  eax = ext_443ef0_fastcall4(ecx, edx, PV[6], PV[5]);  // @184_456590
  ecx = edx = 0;  // @185_456590
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @186_456590
  X1[1] = 0;  // @187_456590
  X1[2] = 0;  // @188_456590
  X1[3] = 0;  // @189_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @190_456590
  PV[7] = (u32)(ecx);  // @191_456590
  ecx = (u32)(EBP - 16);  // @192_456590
  PV[8] = X1[0];  // @193_456590
  eax = ext_451890_fastcall3(ecx, edx, PV[8]);  // @194_456590
  ecx = 0;  // @195_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @196_456590
  X0[1] = 0;  // @197_456590
  X0[2] = 0;  // @198_456590
  X0[3] = 0;  // @199_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; })));  // @200_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @201_456590
  PV[9] = (u32)(ecx);  // @202_456590
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @203_456590
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @204_456590
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @205_456590
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @206_456590
  PV[10] = X0[0];  // @207_456590
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @208_456590
  goto L45681a;  // @209_456590
  L4567d9:;
  PV[12] = (u32)(ecx);  // @211_456590
  PV[13] = X0[0];  // @212_456590
  ecx = (u32)(EBP - 16);  // @213_456590
  PV[14] = (u32)(edx);  // @214_456590
  edx = (edx + (u32)(-12));  // @215_456590
  FL[3] = edx;  // @216_456590
  eax = ext_443ef0_fastcall4(ecx, edx, PV[14], PV[13]);  // @217_456590
  ecx = edx = 0;  // @218_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @219_456590
  X0[1] = 0;  // @220_456590
  X0[2] = 0;  // @221_456590
  X0[3] = 0;  // @222_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @223_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @224_456590
  PV[15] = (u32)(ecx);  // @225_456590
  ecx = (u32)(EBP - 16);  // @226_456590
  PV[16] = X0[0];  // @227_456590
  eax = ext_451890_fastcall3(ecx, edx, PV[16]);  // @228_456590
  ecx = 0;  // @229_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @230_456590
  X0[1] = 0;  // @231_456590
  X0[2] = 0;  // @232_456590
  X0[3] = 0;  // @233_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @234_456590
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @235_456590
  PV[17] = (u32)(ecx);  // @236_456590
  PV[18] = X0[0];  // @237_456590
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @238_456590
  L45681a:;
  ecx = (u32)(EBP - 28);  // @240_456590
  eax = ext_443ef0_fastcall4(ecx, edx, PV[19], PV[18]);  // @241_456590
  ecx = edx = 0;  // @242_456590
  PV[20] = (u32)(ecx);  // @243_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @244_456590
  edx = (u32)(EBP - 28);  // @245_456590
  eax = 0;  // @246_456590
  PV[21] = (u32)(edx);  // @247_456590
  edx = (u32)(EBP - 16);  // @248_456590
  PV[22] = (u32)(edx);  // @249_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @250_456590
  PV[23] = esi;  // @251_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @252_456590
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 237), sizeof v); (u32)v; });  // @253_456590
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[24], PV[22], PV[21], PV[23], PV[11], PV[10]);  // @254_456590
  ecx = edx = 0;  // @255_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @256_456590
  L456846:;
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @258_456590
  X5[1] = 0;  // @259_456590
  X5[2] = 0;  // @260_456590
  X5[3] = 0;  // @261_456590
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @262_456590
  X4[1] = 0;  // @263_456590
  X4[2] = 0;  // @264_456590
  X4[3] = 0;  // @265_456590
  L456853:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @267_456590
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @268_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @269_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @270_456590
  FL[0] = ecx; FL[1] = eax;  // @271_456590
  if (FL[0] == FL[1]) goto L456897;  // @272_456590
  eax = (u32)(eax + eax*8);  // @273_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4 + 12) + 0), 4); v; });  // @274_456590
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4 + 12) + 4), 4); v; });  // @275_456590
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4 + 12) + 8), 4); v; });  // @276_456590
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4 + 12) + 12), 4); v; });  // @277_456590
  __builtin_memcpy((void *)((u32)(edx - 12) + 0), &X0[0], 4);  // @278_456590
  __builtin_memcpy((void *)((u32)(edx - 12) + 4), &X0[1], 4);  // @279_456590
  __builtin_memcpy((void *)((u32)(edx - 12) + 8), &X0[2], 4);  // @280_456590
  __builtin_memcpy((void *)((u32)(edx - 12) + 12), &X0[3], 4);  // @281_456590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4 + 28) + 0), 4); v; });  // @282_456590
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4 + 28) + 4), 4); v; });  // @283_456590
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4 + 28) + 8), 4); v; });  // @284_456590
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4 + 28) + 12), 4); v; });  // @285_456590
  __builtin_memcpy((void *)((u32)(edx + 4) + 0), &X0[0], 4);  // @286_456590
  __builtin_memcpy((void *)((u32)(edx + 4) + 4), &X0[1], 4);  // @287_456590
  __builtin_memcpy((void *)((u32)(edx + 4) + 8), &X0[2], 4);  // @288_456590
  __builtin_memcpy((void *)((u32)(edx + 4) + 12), &X0[3], 4);  // @289_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 44), sizeof v); (u32)v; });  // @290_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @291_456590
  goto L456897;  // @292_456590
  L45687e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @294_456590
  { float a_ = U2F(X3[0]), b_ = U2F(X4[0]); X3[0] = (a_ < b_) ? X3[0] : F2U(b_); }  // @295_456590
  ecx = (ecx + 1);  // @296_456590
  FL[3] = ecx;  // @297_456590
  edx = (edx + (u32)(36));  // @298_456590
  FL[3] = edx;  // @299_456590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @300_456590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @301_456590
  X4[0] = X3[0];  // @302_456590
  X4[1] = X3[1];  // @303_456590
  X4[2] = X3[2];  // @304_456590
  X4[3] = X3[3];  // @305_456590
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X4[0], 4);  // @306_456590
  L456897:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; });  // @308_456590
  X1[1] = 0;  // @309_456590
  X1[2] = 0;  // @310_456590
  X1[3] = 0;  // @311_456590
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @312_456590
  if (FL[0] < FL[1]) goto L4566d0;  // @313_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @314_456590
  L4568ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @316_456590
  FL[2] = (eax & eax);  // @317_456590
  if (FL[2] == 0) goto L4568f7;  // @318_456590
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @319_456590
  X0[0] = F2U((float)(s32)X0[0]);  // @320_456590
  X0[1] = F2U((float)(s32)X0[1]);  // @321_456590
  X0[2] = F2U((float)(s32)X0[2]);  // @322_456590
  X0[3] = F2U((float)(s32)X0[3]);  // @323_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2316), &v, sizeof v); }  // @324_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @325_456590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @326_456590
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X4[0], 4);  // @327_456590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @328_456590
  __builtin_memcpy((void *)((u32)(edi + 2324) + 0), &X0[0], 4);  // @329_456590
  FL[2] = (eax & eax);  // @330_456590
  if (FL[2] == 0) goto L456965;  // @331_456590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2077), sizeof v); (u32)v; });  // @332_456590
  ecx = (u32)((s32)eax * (s32)(u32)(2380));  // @333_456590
  edi = (edi + (u32)(4294964916));  // @334_456590
  FL[3] = edi;  // @335_456590
  edi = (edi + ecx);  // @336_456590
  FL[3] = edi;  // @337_456590
  goto L45695d;  // @338_456590
  L4568f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @340_456590
  edx = edi;  // @341_456590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @342_456590
  FL[2] = (eax & eax);  // @343_456590
  if (FL[2] == 0) goto L456915;  // @344_456590
  ecx = (u32)((s32)eax * (s32)(u32)(2380));  // @345_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2077), sizeof v); (u32)v; });  // @346_456590
  eax = (eax + (u32)(4294964916));  // @347_456590
  FL[3] = eax;  // @348_456590
  eax = (eax + ecx);  // @349_456590
  FL[3] = eax;  // @350_456590
  L456915:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @352_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @353_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @354_456590
  FL[2] = (ecx & ecx);  // @355_456590
  if (FL[2] == 0) goto L456925;  // @356_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @357_456590
  goto L45692b;  // @358_456590
  L456925:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @360_456590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @361_456590
  L45692b:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2077), sizeof v); (u32)v; });  // @363_456590
  eax = (u32)(1847918703);  // @364_456590
  edx = (edx - edi);  // @365_456590
  FL[3] = edx;  // @366_456590
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @367_456590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152576), sizeof v); (u32)v; });  // @368_456590
  edx = (u32)((s32)edx >> (u32)(10));  // @369_456590
  FL[3] = edx;  // @370_456590
  ecx = edx;  // @371_456590
  ecx = (ecx >> (u32)(31));  // @372_456590
  FL[3] = ecx;  // @373_456590
  ecx = (ecx + edx);  // @374_456590
  FL[3] = ecx;  // @375_456590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @376_456590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + eax*4 + 152320), &v, sizeof v); }  // @377_456590
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152576), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 152576), &v, sizeof v); }  // @378_456590
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152576), sizeof v); (u32)v; });  // @379_456590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @380_456590
  L45695d:;
  FL[2] = (edi & edi);  // @382_456590
  if (FL[2] != 0) goto L456671;  // @383_456590
  L456965:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @385_456590
  L456968:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @387_456590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @388_456590
  edx = (edx + 1);  // @389_456590
  FL[3] = edx;  // @390_456590
  ecx = (ecx + (u32)(8));  // @391_456590
  FL[3] = ecx;  // @392_456590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @393_456590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @394_456590
  FL[0] = edx; FL[1] = (u32)(256);  // @395_456590
  if (FL[0] < FL[1]) goto L4565c0;  // @396_456590
  L456984:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @398_456590
  if (FL[0] == FL[1]) goto L456991;  // @399_456590
  ecx = eax;  // @400_456590
  eax = ext_4569b0_thiscall1(ecx);  // @401_456590
  ecx = edx = 0;  // @402_456590
  L456991:;
  ext_633654(G(u32, 0x6f5630));  // @404_456590
  return eax;  // @405_456590
}
PCREG(456590, lifted_456590);

extern "C" u32 THISCALL lifted_4fefe0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4fefe0
  ebx = ecx;  // @1_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4fefe0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 95), sizeof v); (u32)v; });  // @3_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @5_4fefe0
  ecx = edx = 0;  // @6_4fefe0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 99), sizeof v); (u32)v; });  // @7_4fefe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 104), &v, sizeof v); }  // @8_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @12_4fefe0
  ecx = edx = 0;  // @13_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @14_4fefe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 108), &v, sizeof v); }  // @15_4fefe0
  FL[2] = (ecx & ecx);  // @16_4fefe0
  if (FL[2] == 0) goto L4ff48a;  // @17_4fefe0
  FL[2] = (eax & eax);  // @18_4fefe0
  if (FL[2] == 0) goto L4ff48a;  // @19_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @21_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097191));  // @22_4fefe0
  ecx = edx = 0;  // @23_4fefe0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @24_4fefe0
  if (FL[2] == 0) goto L4ff48a;  // @25_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @26_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @28_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097191));  // @29_4fefe0
  ecx = edx = 0;  // @30_4fefe0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @31_4fefe0
  if (FL[2] == 0) goto L4ff48a;  // @32_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @33_4fefe0
  eax = (u32)(EBP - 16);  // @34_4fefe0
  PV[2] = (u32)(eax);  // @35_4fefe0
  eax = (u32)(EBP - 280);  // @36_4fefe0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4fefe0
  PV[3] = (u32)(eax);  // @38_4fefe0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 932)))(ecx, PV[3], PV[2]);  // @39_4fefe0
  ecx = edx = 0;  // @40_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @41_4fefe0
  PV[4] = (u32)(eax);  // @42_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[4]);  // @43_4fefe0
  ecx = edx = 0;  // @44_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @45_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @46_4fefe0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_4fefe0
  eax = (u32)(EBP - 28);  // @48_4fefe0
  PV[5] = (u32)(eax);  // @49_4fefe0
  eax = (u32)(EBP - 316);  // @50_4fefe0
  PV[6] = (u32)(eax);  // @51_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4fefe0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 932)))(ecx, PV[6], PV[5]);  // @53_4fefe0
  ecx = edx = 0;  // @54_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @55_4fefe0
  PV[7] = (u32)(eax);  // @56_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[7]);  // @57_4fefe0
  ecx = edx = 0;  // @58_4fefe0
  edx = (u32)(EBP - 348);  // @59_4fefe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @60_4fefe0
  ecx = (u32)(EBP - 16);  // @61_4fefe0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(EBP - 344), &v, sizeof v); }  // @62_4fefe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @63_4fefe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @64_4fefe0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @65_4fefe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @66_4fefe0
  eax = ext_441940_fastcall2(ecx, edx);  // @67_4fefe0
  ecx = edx = 0;  // @68_4fefe0
  edx = (u32)(EBP - 360);  // @69_4fefe0
  ecx = (u32)(EBP - 28);  // @70_4fefe0
  eax = ext_441940_fastcall2(ecx, edx);  // @71_4fefe0
  ecx = edx = 0;  // @72_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @73_4fefe0
  edx = (u32)(EBP - 16);  // @74_4fefe0
  PV[8] = (u32)(edx);  // @75_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[8]);  // @77_4fefe0
  ecx = edx = 0;  // @78_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @79_4fefe0
  edx = (u32)(EBP - 28);  // @80_4fefe0
  PV[9] = (u32)(edx);  // @81_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[9]);  // @83_4fefe0
  ecx = edx = 0;  // @84_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_4fefe0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 232), sizeof v); (u32)v; });  // @86_4fefe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @87_4fefe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @88_4fefe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @89_4fefe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @90_4fefe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[10]);  // @92_4fefe0
  ecx = edx = 0;  // @93_4fefe0
  ecx = (u32)(EBP - 64);  // @94_4fefe0
  PV[11] = (u32)(ecx);  // @95_4fefe0
  ecx = eax;  // @96_4fefe0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @97_4fefe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[11]);  // @98_4fefe0
  ecx = edx = 0;  // @99_4fefe0
  eax = (u32)(EBP - 16);  // @100_4fefe0
  PV[12] = (u32)(eax);  // @101_4fefe0
  edx = (u32)(EBP - 28);  // @102_4fefe0
  ecx = (u32)(EBP - 52);  // @103_4fefe0
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @104_4fefe0
  ecx = edx = 0;  // @105_4fefe0
  edx = (u32)(EBP - 52);  // @106_4fefe0
  ecx = (u32)(EBP - 100);  // @107_4fefe0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @108_4fefe0
  ecx = edx = 0;  // @109_4fefe0
  eax = (u32)(EBP - 16);  // @110_4fefe0
  PV[13] = (u32)(eax);  // @111_4fefe0
  edx = (u32)(EBP - 64);  // @112_4fefe0
  ecx = (u32)(EBP - 52);  // @113_4fefe0
  eax = ext_43e920_fastcall3(ecx, edx, PV[13]);  // @114_4fefe0
  ecx = edx = 0;  // @115_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @116_4fefe0
  X0[1] = 0;  // @117_4fefe0
  X0[2] = 0;  // @118_4fefe0
  X0[3] = 0;  // @119_4fefe0
  X2[0] = 0;  // @120_4fefe0
  X2[1] = 0;  // @121_4fefe0
  X2[2] = 0;  // @122_4fefe0
  X2[3] = 0;  // @123_4fefe0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @124_4fefe0
  X1[1] = 0;  // @125_4fefe0
  X1[2] = 0;  // @126_4fefe0
  X1[3] = 0;  // @127_4fefe0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; })));  // @128_4fefe0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; })));  // @129_4fefe0
  __builtin_memcpy((void *)((u32)(EBP - 332) + 0), &X2[0], 4);  // @130_4fefe0
  __builtin_memcpy((void *)((u32)(EBP - 328) + 0), &X2[0], 4);  // @131_4fefe0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @132_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @133_4fefe0
  X0[1] = 0;  // @134_4fefe0
  X0[2] = 0;  // @135_4fefe0
  X0[3] = 0;  // @136_4fefe0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })));  // @137_4fefe0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @138_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @139_4fefe0
  X0[1] = 0;  // @140_4fefe0
  X0[2] = 0;  // @141_4fefe0
  X0[3] = 0;  // @142_4fefe0
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4ff1d6;  // @143_4fefe0
  __builtin_memcpy((void *)((u32)(EBP - 332) + 0), &X0[0], 4);  // @144_4fefe0
  goto L4ff1de;  // @145_4fefe0
  L4ff1d6:;
  __builtin_memcpy((void *)((u32)(EBP - 328) + 0), &X0[0], 4);  // @147_4fefe0
  L4ff1de:;
  eax = (u32)(EBP - 28);  // @149_4fefe0
  ecx = ebx;  // @150_4fefe0
  PV[14] = (u32)(eax);  // @151_4fefe0
  eax = (u32)(EBP - 16);  // @152_4fefe0
  PV[15] = (u32)(eax);  // @153_4fefe0
  eax = (u32)(EBP - 172);  // @154_4fefe0
  PV[16] = (u32)(eax);  // @155_4fefe0
  eax = (u32)(EBP - 384);  // @156_4fefe0
  PV[17] = (u32)(eax);  // @157_4fefe0
  eax = ext_4fed00_thiscall6(ecx, PV[17], PV[16], PV[15], PV[14], (u32)(1));  // @158_4fefe0
  ecx = edx = 0;  // @159_4fefe0
  eax = (u32)(EBP - 16);  // @160_4fefe0
  ecx = ebx;  // @161_4fefe0
  PV[18] = (u32)(eax);  // @162_4fefe0
  eax = (u32)(EBP - 28);  // @163_4fefe0
  PV[19] = (u32)(eax);  // @164_4fefe0
  eax = (u32)(EBP - 136);  // @165_4fefe0
  PV[20] = (u32)(eax);  // @166_4fefe0
  eax = (u32)(EBP - 372);  // @167_4fefe0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 324)) :: "st");  // @168_4fefe0
  PV[21] = (u32)(eax);  // @169_4fefe0
  eax = ext_4fed00_thiscall6(ecx, PV[21], PV[20], PV[19], PV[18], (u32)(0));  // @170_4fefe0
  ecx = edx = 0;  // @171_4fefe0
  eax = (u32)(EBP - 28);  // @172_4fefe0
  ecx = ebx;  // @173_4fefe0
  PV[22] = (u32)(eax);  // @174_4fefe0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 320)) :: "st");  // @175_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 320) + 0), 4); v; });  // @176_4fefe0
  X0[1] = 0;  // @177_4fefe0
  X0[2] = 0;  // @178_4fefe0
  X0[3] = 0;  // @179_4fefe0
  eax = (u32)(EBP - 16);  // @180_4fefe0
  { float a_ = U2F(X0[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 324) + 0), 4); v; })); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @181_4fefe0
  PV[23] = (u32)(eax);  // @182_4fefe0
  eax = (u32)(EBP - 244);  // @183_4fefe0
  PV[24] = (u32)(eax);  // @184_4fefe0
  eax = (u32)(EBP - 408);  // @185_4fefe0
  PV[25] = (u32)(eax);  // @186_4fefe0
  __builtin_memcpy((void *)((u32)(EBP - 336) + 0), &X0[0], 4);  // @187_4fefe0
  eax = ext_4fed00_thiscall6(ecx, PV[25], PV[24], PV[23], PV[22], (u32)(0));  // @188_4fefe0
  ecx = edx = 0;  // @189_4fefe0
  eax = (u32)(EBP - 16);  // @190_4fefe0
  ecx = ebx;  // @191_4fefe0
  PV[26] = (u32)(eax);  // @192_4fefe0
  eax = (u32)(EBP - 28);  // @193_4fefe0
  PV[27] = (u32)(eax);  // @194_4fefe0
  eax = (u32)(EBP - 208);  // @195_4fefe0
  PV[28] = (u32)(eax);  // @196_4fefe0
  eax = (u32)(EBP - 396);  // @197_4fefe0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 320)) :: "st");  // @198_4fefe0
  PV[29] = (u32)(eax);  // @199_4fefe0
  eax = ext_4fed00_thiscall6(ecx, PV[29], PV[28], PV[27], PV[26], (u32)(1));  // @200_4fefe0
  ecx = edx = 0;  // @201_4fefe0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 336) + 0), 4); v; });  // @202_4fefe0
  X1[1] = 0;  // @203_4fefe0
  X1[2] = 0;  // @204_4fefe0
  X1[3] = 0;  // @205_4fefe0
  X2[0] = 0;  // @206_4fefe0
  X2[1] = 0;  // @207_4fefe0
  X2[2] = 0;  // @208_4fefe0
  X2[3] = 0;  // @209_4fefe0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 324)) :: "st");  // @210_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 324) + 0), 4); v; });  // @211_4fefe0
  X0[1] = 0;  // @212_4fefe0
  X0[2] = 0;  // @213_4fefe0
  X0[3] = 0;  // @214_4fefe0
  { float a_ = U2F(X0[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 320) + 0), 4); v; })); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @215_4fefe0
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4ff391;  // @216_4fefe0
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L4ff391;  // @217_4fefe0
  eax = (u32)(EBP - 28);  // @218_4fefe0
  PV[30] = (u32)(eax);  // @219_4fefe0
  edx = (u32)(EBP - 16);  // @220_4fefe0
  ecx = (u32)(EBP - 40);  // @221_4fefe0
  eax = ext_43e920_fastcall3(ecx, edx, PV[30]);  // @222_4fefe0
  ecx = edx = 0;  // @223_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @224_4fefe0
  X0[1] = 0;  // @225_4fefe0
  X0[2] = 0;  // @226_4fefe0
  X0[3] = 0;  // @227_4fefe0
  edx = (u32)(EBP - 40);  // @228_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 116) + 0), &X0[0], 4);  // @229_4fefe0
  ecx = (u32)(ebx + 128);  // @230_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @231_4fefe0
  X0[1] = 0;  // @232_4fefe0
  X0[2] = 0;  // @233_4fefe0
  X0[3] = 0;  // @234_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 120) + 0), &X0[0], 4);  // @235_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @236_4fefe0
  X0[1] = 0;  // @237_4fefe0
  X0[2] = 0;  // @238_4fefe0
  X0[3] = 0;  // @239_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 124) + 0), &X0[0], 4);  // @240_4fefe0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @241_4fefe0
  ecx = edx = 0;  // @242_4fefe0
  PV[31] = (u32)(ecx);  // @243_4fefe0
  edx = (u32)(ebx + 128);  // @244_4fefe0
  ecx = (u32)(EBP - 40);  // @245_4fefe0
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1101004800));  // @246_4fefe0
    // @247_4fefe0
  edx = (u32)(EBP - 40);  // @248_4fefe0
  ecx = (u32)(ebx + 116);  // @249_4fefe0
  eax = ext_441940_fastcall2(ecx, edx);  // @250_4fefe0
  ecx = edx = 0;  // @251_4fefe0
  eax = (u32)(EBP - 16);  // @252_4fefe0
  PV[32] = (u32)(eax);  // @253_4fefe0
  edx = (u32)(EBP - 28);  // @254_4fefe0
  ecx = (u32)(EBP - 40);  // @255_4fefe0
  eax = ext_43e920_fastcall3(ecx, edx, PV[32]);  // @256_4fefe0
  ecx = edx = 0;  // @257_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @258_4fefe0
  X0[1] = 0;  // @259_4fefe0
  X0[2] = 0;  // @260_4fefe0
  X0[3] = 0;  // @261_4fefe0
  edx = (u32)(EBP - 40);  // @262_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 164) + 0), &X0[0], 4);  // @263_4fefe0
  ecx = (u32)(ebx + 176);  // @264_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @265_4fefe0
  X0[1] = 0;  // @266_4fefe0
  X0[2] = 0;  // @267_4fefe0
  X0[3] = 0;  // @268_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 168) + 0), &X0[0], 4);  // @269_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @270_4fefe0
  X0[1] = 0;  // @271_4fefe0
  X0[2] = 0;  // @272_4fefe0
  X0[3] = 0;  // @273_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 172) + 0), &X0[0], 4);  // @274_4fefe0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @275_4fefe0
  ecx = edx = 0;  // @276_4fefe0
  PV[33] = (u32)(ecx);  // @277_4fefe0
  edx = (u32)(ebx + 176);  // @278_4fefe0
  ecx = (u32)(EBP - 40);  // @279_4fefe0
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1101004800));  // @280_4fefe0
    // @281_4fefe0
  edx = (u32)(EBP - 40);  // @282_4fefe0
  ecx = (u32)(ebx + 164);  // @283_4fefe0
  eax = ext_441940_fastcall2(ecx, edx);  // @284_4fefe0
  ecx = edx = 0;  // @285_4fefe0
  ext_633654(G(u32, 0x6f5630));  // @286_4fefe0
  return eax;  // @287_4fefe0
  L4ff391:;
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 328) + 0), 4); v; })));  // @289_4fefe0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 332) + 0), 4); v; })));  // @290_4fefe0
  ecx = (u32)(ebx + 128);  // @291_4fefe0
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4ff416;  // @292_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 384) + 0), 4); v; });  // @293_4fefe0
  X0[1] = 0;  // @294_4fefe0
  X0[2] = 0;  // @295_4fefe0
  X0[3] = 0;  // @296_4fefe0
  edx = (u32)(EBP - 172);  // @297_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 116) + 0), &X0[0], 4);  // @298_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 380) + 0), 4); v; });  // @299_4fefe0
  X0[1] = 0;  // @300_4fefe0
  X0[2] = 0;  // @301_4fefe0
  X0[3] = 0;  // @302_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 120) + 0), &X0[0], 4);  // @303_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 376) + 0), 4); v; });  // @304_4fefe0
  X0[1] = 0;  // @305_4fefe0
  X0[2] = 0;  // @306_4fefe0
  X0[3] = 0;  // @307_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 124) + 0), &X0[0], 4);  // @308_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 372) + 0), 4); v; });  // @309_4fefe0
  X0[1] = 0;  // @310_4fefe0
  X0[2] = 0;  // @311_4fefe0
  X0[3] = 0;  // @312_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 164) + 0), &X0[0], 4);  // @313_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 368) + 0), 4); v; });  // @314_4fefe0
  X0[1] = 0;  // @315_4fefe0
  X0[2] = 0;  // @316_4fefe0
  X0[3] = 0;  // @317_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 168) + 0), &X0[0], 4);  // @318_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 364) + 0), 4); v; });  // @319_4fefe0
  X0[1] = 0;  // @320_4fefe0
  X0[2] = 0;  // @321_4fefe0
  X0[3] = 0;  // @322_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 172) + 0), &X0[0], 4);  // @323_4fefe0
  eax = ext_4de420_fastcall2(ecx, edx);  // @324_4fefe0
    // @325_4fefe0
  edx = (u32)(EBP - 136);  // @326_4fefe0
  goto L4ff47e;  // @327_4fefe0
  L4ff416:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 408) + 0), 4); v; });  // @329_4fefe0
  X0[1] = 0;  // @330_4fefe0
  X0[2] = 0;  // @331_4fefe0
  X0[3] = 0;  // @332_4fefe0
  edx = (u32)(EBP - 244);  // @333_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 116) + 0), &X0[0], 4);  // @334_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 404) + 0), 4); v; });  // @335_4fefe0
  X0[1] = 0;  // @336_4fefe0
  X0[2] = 0;  // @337_4fefe0
  X0[3] = 0;  // @338_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 120) + 0), &X0[0], 4);  // @339_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 400) + 0), 4); v; });  // @340_4fefe0
  X0[1] = 0;  // @341_4fefe0
  X0[2] = 0;  // @342_4fefe0
  X0[3] = 0;  // @343_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 124) + 0), &X0[0], 4);  // @344_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 396) + 0), 4); v; });  // @345_4fefe0
  X0[1] = 0;  // @346_4fefe0
  X0[2] = 0;  // @347_4fefe0
  X0[3] = 0;  // @348_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 164) + 0), &X0[0], 4);  // @349_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 392) + 0), 4); v; });  // @350_4fefe0
  X0[1] = 0;  // @351_4fefe0
  X0[2] = 0;  // @352_4fefe0
  X0[3] = 0;  // @353_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 168) + 0), &X0[0], 4);  // @354_4fefe0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 388) + 0), 4); v; });  // @355_4fefe0
  X0[1] = 0;  // @356_4fefe0
  X0[2] = 0;  // @357_4fefe0
  X0[3] = 0;  // @358_4fefe0
  __builtin_memcpy((void *)((u32)(ebx + 172) + 0), &X0[0], 4);  // @359_4fefe0
  eax = ext_4de420_fastcall2(ecx, edx);  // @360_4fefe0
    // @361_4fefe0
  edx = (u32)(EBP - 208);  // @362_4fefe0
  L4ff47e:;
  ecx = (u32)(ebx + 176);  // @364_4fefe0
  eax = ext_4de420_fastcall2(ecx, edx);  // @365_4fefe0
    // @366_4fefe0
  L4ff48a:;
  ext_633654(G(u32, 0x6f5630));  // @368_4fefe0
  return eax;  // @369_4fefe0
}
PCREG(4fefe0, lifted_4fefe0);

