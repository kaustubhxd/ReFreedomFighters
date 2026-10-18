// batch244022.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4cc500_fastcall2(u32, u32) __asm__("ext_4cc500");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de4b0_fastcall3(u32, u32, u32) __asm__("ext_4de4b0");
extern "C" u32 FASTCALL ext_4e0be0_fastcall2(u32, u32) __asm__("ext_4e0be0");
extern "C" u32 THISCALL ext_421080_thiscall1(u32) __asm__("ext_421080");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4dda90_thiscall3(u32, u32, u32) __asm__("ext_4dda90");
extern "C" u32 THISCALL ext_4f12e0_thiscall2(u32, u32) __asm__("ext_4f12e0");
extern "C" u32 THISCALL ext_64a410_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_64a410");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42ac56_cdecl4(...) __asm__("ext_42ac56");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 FASTCALL lifted_4fd2a0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_4fd2a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @1_4fd2a0
  X6[0] = 0;  // @2_4fd2a0
  X6[1] = 0;  // @3_4fd2a0
  X6[2] = 0;  // @4_4fd2a0
  X6[3] = 0;  // @5_4fd2a0
  eax = (u32)(EBP - 48);  // @6_4fd2a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @7_4fd2a0
  X7[0] = X6[0];  // @8_4fd2a0
  X7[1] = X6[1];  // @9_4fd2a0
  X7[2] = X6[2];  // @10_4fd2a0
  X7[3] = X6[3];  // @11_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @12_4fd2a0
  X0[1] = 0;  // @13_4fd2a0
  X0[2] = 0;  // @14_4fd2a0
  X0[3] = 0;  // @15_4fd2a0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @16_4fd2a0
  X5[1] = 0;  // @17_4fd2a0
  X5[2] = 0;  // @18_4fd2a0
  X5[3] = 0;  // @19_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @20_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X7[0], 4);  // @21_4fd2a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X6[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X6[0]) != U2F(X6[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X6[0])) || (U2F(X0[0]) > U2F(X6[0])))) ? 0x40 : 0)) << 8);  // @22_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X5[0], 4);  // @23_4fd2a0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X6[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X6[0]) != U2F(X6[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X6[0])) || (U2F(X0[0]) > U2F(X6[0])))) ? 0x40 : 0)) & 68);  // @24_4fd2a0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4fd2ed;  // @25_4fd2a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X5[0]) >= U2F(X6[0])) ? 1 : 0) | (((U2F(X5[0]) != U2F(X5[0])) || (U2F(X6[0]) != U2F(X6[0]))) ? 4 : 0) | ((!((U2F(X5[0]) < U2F(X6[0])) || (U2F(X5[0]) > U2F(X6[0])))) ? 0x40 : 0)) << 8);  // @26_4fd2a0
  FL[2] = ((u32)(0x02 | (!(U2F(X5[0]) >= U2F(X6[0])) ? 1 : 0) | (((U2F(X5[0]) != U2F(X5[0])) || (U2F(X6[0]) != U2F(X6[0]))) ? 4 : 0) | ((!((U2F(X5[0]) < U2F(X6[0])) || (U2F(X5[0]) > U2F(X6[0])))) ? 0x40 : 0)) & 68);  // @27_4fd2a0
  if (__builtin_parity(FL[2] & 0xff)) goto L4fd338;  // @28_4fd2a0
  L4fd2ed:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @30_4fd2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @31_4fd2a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @32_4fd2a0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @33_4fd2a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @34_4fd2a0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @35_4fd2a0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @36_4fd2a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @37_4fd2a0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @38_4fd2a0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @39_4fd2a0
  __asm__ volatile("fsqrt" ::: "st");  // @40_4fd2a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 20)) : "st");  // @41_4fd2a0
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @42_4fd2a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @43_4fd2a0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @44_4fd2a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @45_4fd2a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @46_4fd2a0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @47_4fd2a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @48_4fd2a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @49_4fd2a0
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @50_4fd2a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @51_4fd2a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @52_4fd2a0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @53_4fd2a0
  X5[1] = 0;  // @54_4fd2a0
  X5[2] = 0;  // @55_4fd2a0
  X5[3] = 0;  // @56_4fd2a0
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @57_4fd2a0
  X7[1] = 0;  // @58_4fd2a0
  X7[2] = 0;  // @59_4fd2a0
  X7[3] = 0;  // @60_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @61_4fd2a0
  X0[1] = 0;  // @62_4fd2a0
  X0[2] = 0;  // @63_4fd2a0
  X0[3] = 0;  // @64_4fd2a0
  L4fd338:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @66_4fd2a0
  X4[1] = 0;  // @67_4fd2a0
  X4[2] = 0;  // @68_4fd2a0
  X4[3] = 0;  // @69_4fd2a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @70_4fd2a0
  X1[1] = 0;  // @71_4fd2a0
  X1[2] = 0;  // @72_4fd2a0
  X1[3] = 0;  // @73_4fd2a0
  X3[0] = X4[0];  // @74_4fd2a0
  X3[1] = X4[1];  // @75_4fd2a0
  X3[2] = X4[2];  // @76_4fd2a0
  X3[3] = X4[3];  // @77_4fd2a0
  X3[0] = F2U(U2F(X3[0]) * U2F(X0[0]));  // @78_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @79_4fd2a0
  X0[1] = 0;  // @80_4fd2a0
  X0[2] = 0;  // @81_4fd2a0
  X0[3] = 0;  // @82_4fd2a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X7[0]));  // @83_4fd2a0
  X4[0] = F2U(U2F(X4[0]) * U2F(X6[0]));  // @84_4fd2a0
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @85_4fd2a0
  X0[0] = X1[0];  // @86_4fd2a0
  X0[1] = X1[1];  // @87_4fd2a0
  X0[2] = X1[2];  // @88_4fd2a0
  X0[3] = X1[3];  // @89_4fd2a0
  X1[0] = F2U(U2F(X1[0]) * U2F(X6[0]));  // @90_4fd2a0
  X4[0] = F2U(U2F(X4[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @91_4fd2a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @92_4fd2a0
  X4[0] = F2U(U2F(X4[0]) + U2F(X1[0]));  // @93_4fd2a0
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @94_4fd2a0
  PV[0] = X4[0];  // @95_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X4[0], 4);  // @96_4fd2a0
  PV[1] = X3[0];  // @97_4fd2a0
  eax = ext_4dda90_thiscall3(ecx, PV[1], PV[0]);  // @98_4fd2a0
  ecx = edx = 0;  // @99_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @100_4fd2a0
  X0[1] = 0;  // @101_4fd2a0
  X0[2] = 0;  // @102_4fd2a0
  X0[3] = 0;  // @103_4fd2a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @104_4fd2a0
  PV[2] = X0[0];  // @105_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @106_4fd2a0
  X0[1] = 0;  // @107_4fd2a0
  X0[2] = 0;  // @108_4fd2a0
  X0[3] = 0;  // @109_4fd2a0
  PV[3] = X0[0];  // @110_4fd2a0
  eax = ext_4dda90_thiscall3(ecx, PV[3], PV[2]);  // @111_4fd2a0
  ecx = edx = 0;  // @112_4fd2a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 28)) :: "st");  // @113_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @114_4fd2a0
  X0[1] = 0;  // @115_4fd2a0
  X0[2] = 0;  // @116_4fd2a0
  X0[3] = 0;  // @117_4fd2a0
  edx = (u32)(EBP - 16);  // @118_4fd2a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @119_4fd2a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @120_4fd2a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @121_4fd2a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @122_4fd2a0
  ecx = esi;  // @123_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @124_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @125_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @126_4fd2a0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @127_4fd2a0
  ecx = edx = 0;  // @128_4fd2a0
  X0[0] = 0;  // @129_4fd2a0
  X0[1] = 0;  // @130_4fd2a0
  X0[2] = 0;  // @131_4fd2a0
  X0[3] = 0;  // @132_4fd2a0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; }))))))) goto L4fd3fa;  // @133_4fd2a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6931948) + 0), 4); v; });  // @134_4fd2a0
  X1[1] = 0;  // @135_4fd2a0
  X1[2] = 0;  // @136_4fd2a0
  X1[3] = 0;  // @137_4fd2a0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @138_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X1[0], 4);  // @139_4fd2a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6931952) + 0), 4); v; });  // @140_4fd2a0
  X1[1] = 0;  // @141_4fd2a0
  X1[2] = 0;  // @142_4fd2a0
  X1[3] = 0;  // @143_4fd2a0
  goto L4fd414;  // @144_4fd2a0
  L4fd3fa:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6931956) + 0), 4); v; });  // @146_4fd2a0
  X1[1] = 0;  // @147_4fd2a0
  X1[2] = 0;  // @148_4fd2a0
  X1[3] = 0;  // @149_4fd2a0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @150_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X1[0], 4);  // @151_4fd2a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6931944) + 0), 4); v; });  // @152_4fd2a0
  X1[1] = 0;  // @153_4fd2a0
  X1[2] = 0;  // @154_4fd2a0
  X1[3] = 0;  // @155_4fd2a0
  L4fd414:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @157_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @158_4fd2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @159_4fd2a0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @160_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @161_4fd2a0
  X0[1] = 0;  // @162_4fd2a0
  X0[2] = 0;  // @163_4fd2a0
  X0[3] = 0;  // @164_4fd2a0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @165_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @166_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X1[0], 4);  // @167_4fd2a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; })));  // @168_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 188), sizeof v); (u32)v; });  // @169_4fd2a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @170_4fd2a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @171_4fd2a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @172_4fd2a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @173_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @174_4fd2a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @175_4fd2a0
  ecx = edx = 0;  // @176_4fd2a0
  ecx = eax;  // @177_4fd2a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @178_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 184), sizeof v); (u32)v; });  // @179_4fd2a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @180_4fd2a0
  ecx = edx = 0;  // @181_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @182_4fd2a0
  X0[1] = 0;  // @183_4fd2a0
  X0[2] = 0;  // @184_4fd2a0
  X0[3] = 0;  // @185_4fd2a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @186_4fd2a0
  if (FL[2] == 0) goto L4fd46f;  // @187_4fd2a0
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @188_4fd2a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @189_4fd2a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @190_4fd2a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @191_4fd2a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @192_4fd2a0
  L4fd46f:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @194_4fd2a0
  X1[1] = 0;  // @195_4fd2a0
  X1[2] = 0;  // @196_4fd2a0
  X1[3] = 0;  // @197_4fd2a0
  edx = (u32)(EBP - 16);  // @198_4fd2a0
  { float a_ = U2F(X1[0]), b_ = U2F(X0[0]); X1[0] = (a_ > b_) ? X1[0] : F2U(b_); }  // @199_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @200_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @201_4fd2a0
  X0[1] = 0;  // @202_4fd2a0
  X0[2] = 0;  // @203_4fd2a0
  X0[3] = 0;  // @204_4fd2a0
  ecx = esi;  // @205_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @206_4fd2a0
  { float a_ = U2F(X0[0]), b_ = U2F(X1[0]); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @207_4fd2a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @208_4fd2a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @209_4fd2a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @210_4fd2a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @211_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @212_4fd2a0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @213_4fd2a0
  ecx = edx = 0;  // @214_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @215_4fd2a0
  X0[1] = 0;  // @216_4fd2a0
  X0[2] = 0;  // @217_4fd2a0
  X0[3] = 0;  // @218_4fd2a0
  edx = (u32)(EBP - 16);  // @219_4fd2a0
  ecx = esi;  // @220_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @221_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @222_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @223_4fd2a0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @224_4fd2a0
  ecx = edx = 0;  // @225_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @226_4fd2a0
  edx = (u32)(EBP - 16);  // @227_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @228_4fd2a0
  X0[1] = 0;  // @229_4fd2a0
  X0[2] = 0;  // @230_4fd2a0
  X0[3] = 0;  // @231_4fd2a0
  ecx = esi;  // @232_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @233_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @234_4fd2a0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @235_4fd2a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; })));  // @236_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @237_4fd2a0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @238_4fd2a0
  ecx = edx = 0;  // @239_4fd2a0
  ext_633654(G(u32, 0x6f5630));  // @240_4fd2a0
  return eax;  // @241_4fd2a0
}
PCREG(4fd2a0, lifted_4fd2a0);

extern "C" u32 THISCALL lifted_60d610(u32 ecx_in) {
  SEH_ENTER(0x66e252);  // @h_60d610
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_60d610
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5106), sizeof v); (u32)v; });  // @1_60d610
  FL[2] = (edi & edi);  // @2_60d610
  if (FL[2] == 0) goto L60d685;  // @3_60d610
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4_60d610
  reg.state = (s32)((u32)(0));  // @5_60d610
  if (FL[0] == FL[1]) goto L60d65d;  // @6_60d610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_60d610
  FL[2] = (ecx & ecx);  // @8_60d610
  if (FL[2] == 0) goto L60d669;  // @9_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_60d610
  PV[0] = (u32)(ecx);  // @11_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[0]);  // @12_60d610
  ecx = edx = 0;  // @13_60d610
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @14_60d610
  L60d65d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_60d610
  FL[2] = (ecx & ecx);  // @17_60d610
  if (FL[2] == 0) goto L60d669;  // @18_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_60d610
  PV[1] = (u32)(ecx);  // @20_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[1]);  // @21_60d610
  ecx = edx = 0;  // @22_60d610
  L60d669:;
  PV[2] = (u32)(edi);  // @24_60d610
  reg.state = (s32)((u32)(4294967295));  // @25_60d610
  eax = ext_634273_cdecl2(PV[2], (u32)(42));  // @26_60d610
  ecx = edx = 0;  // @27_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5106), &v, sizeof v); }  // @28_60d610
  L60d685:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5130), sizeof v); (u32)v; });  // @30_60d610
  FL[2] = (ecx & ecx);  // @31_60d610
  if (FL[2] == 0) goto L60d69f;  // @32_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @34_60d610
  ecx = edx = 0;  // @35_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5130), &v, sizeof v); }  // @36_60d610
  L60d69f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5110), sizeof v); (u32)v; });  // @38_60d610
  FL[2] = (edi & edi);  // @39_60d610
  if (FL[2] == 0) goto L60d6ee;  // @40_60d610
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @41_60d610
  reg.state = (s32)((u32)(1));  // @42_60d610
  if (FL[0] == FL[1]) goto L60d6c6;  // @43_60d610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_60d610
  FL[2] = (ecx & ecx);  // @45_60d610
  if (FL[2] == 0) goto L60d6d2;  // @46_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_60d610
  PV[3] = (u32)(ecx);  // @48_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[3]);  // @49_60d610
  ecx = edx = 0;  // @50_60d610
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @51_60d610
  L60d6c6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @53_60d610
  FL[2] = (ecx & ecx);  // @54_60d610
  if (FL[2] == 0) goto L60d6d2;  // @55_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_60d610
  PV[4] = (u32)(ecx);  // @57_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[4]);  // @58_60d610
  ecx = edx = 0;  // @59_60d610
  L60d6d2:;
  PV[5] = (u32)(edi);  // @61_60d610
  reg.state = (s32)((u32)(4294967295));  // @62_60d610
  eax = ext_634273_cdecl2(PV[5], (u32)(34));  // @63_60d610
  ecx = edx = 0;  // @64_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5110), &v, sizeof v); }  // @65_60d610
  L60d6ee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5114), sizeof v); (u32)v; });  // @67_60d610
  FL[2] = (ecx & ecx);  // @68_60d610
  if (FL[2] == 0) goto L60d708;  // @69_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @71_60d610
  ecx = edx = 0;  // @72_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5114), &v, sizeof v); }  // @73_60d610
  L60d708:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5118), sizeof v); (u32)v; });  // @75_60d610
  FL[2] = (ecx & ecx);  // @76_60d610
  if (FL[2] == 0) goto L60d722;  // @77_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @79_60d610
  ecx = edx = 0;  // @80_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5118), &v, sizeof v); }  // @81_60d610
  L60d722:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5122), sizeof v); (u32)v; });  // @83_60d610
  FL[2] = (ecx & ecx);  // @84_60d610
  if (FL[2] == 0) goto L60d73c;  // @85_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @87_60d610
  ecx = edx = 0;  // @88_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5122), &v, sizeof v); }  // @89_60d610
  L60d73c:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5126), sizeof v); (u32)v; });  // @91_60d610
  FL[2] = (edi & edi);  // @92_60d610
  if (FL[2] == 0) goto L60d78b;  // @93_60d610
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @94_60d610
  reg.state = (s32)((u32)(2));  // @95_60d610
  if (FL[0] == FL[1]) goto L60d763;  // @96_60d610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @97_60d610
  FL[2] = (ecx & ecx);  // @98_60d610
  if (FL[2] == 0) goto L60d76f;  // @99_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_60d610
  PV[6] = (u32)(ecx);  // @101_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[6]);  // @102_60d610
  ecx = edx = 0;  // @103_60d610
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @104_60d610
  L60d763:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @106_60d610
  FL[2] = (ecx & ecx);  // @107_60d610
  if (FL[2] == 0) goto L60d76f;  // @108_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_60d610
  PV[7] = (u32)(ecx);  // @110_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[7]);  // @111_60d610
  ecx = edx = 0;  // @112_60d610
  L60d76f:;
  PV[8] = (u32)(edi);  // @114_60d610
  reg.state = (s32)((u32)(4294967295));  // @115_60d610
  eax = ext_634273_cdecl2(PV[8], (u32)(42));  // @116_60d610
  ecx = edx = 0;  // @117_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5126), &v, sizeof v); }  // @118_60d610
  L60d78b:;
  esi = (esi + (u32)(5134));  // @120_60d610
  FL[3] = esi;  // @121_60d610
  edi = (u32)(2);  // @122_60d610
  L60d796:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_60d610
  FL[2] = (ecx & ecx);  // @125_60d610
  if (FL[2] == 0) goto L60d7a8;  // @126_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @128_60d610
  ecx = edx = 0;  // @129_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @130_60d610
  L60d7a8:;
  esi = (esi + (u32)(4));  // @132_60d610
  FL[3] = esi;  // @133_60d610
  edi = (edi - (u32)(1));  // @134_60d610
  FL[3] = edi;  // @135_60d610
  if (FL[3] != 0) goto L60d796;  // @136_60d610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490120), sizeof v); (u32)v; });  // @137_60d610
  FL[2] = (ecx & ecx);  // @138_60d610
  if (FL[2] == 0) goto L60d7c6;  // @139_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_60d610
  PV[9] = (u32)(ecx);  // @141_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[9]);  // @142_60d610
  ecx = edx = 0;  // @143_60d610
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(7490120), &v, sizeof v); }  // @144_60d610
  L60d7c6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490192), sizeof v); (u32)v; });  // @146_60d610
  FL[2] = (ecx & ecx);  // @147_60d610
  if (FL[2] == 0) goto L60d7e0;  // @148_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_60d610
  PV[10] = (u32)(ecx);  // @150_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[10]);  // @151_60d610
  ecx = edx = 0;  // @152_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7490192), &v, sizeof v); }  // @153_60d610
  L60d7e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490336), sizeof v); (u32)v; });  // @155_60d610
  FL[2] = (ecx & ecx);  // @156_60d610
  if (FL[2] == 0) goto L60d7fa;  // @157_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @158_60d610
  PV[11] = (u32)(ecx);  // @159_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[11]);  // @160_60d610
  ecx = edx = 0;  // @161_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7490336), &v, sizeof v); }  // @162_60d610
  L60d7fa:;
  SEH_LEAVE();  // @164_60d610
  return eax;  // @165_60d610
}
PCREG(60d610, lifted_60d610);

extern "C" u32 THISCALL lifted_426d60(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66466b);  // @h_426d60
  u8 F[0x420] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x320);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x320 + 8, &a0, 4);
  __builtin_memcpy(F + 0x320 + 12, &a1, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 728), &v, sizeof v); }  // @0_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_426d60
  ecx = (u32)(EBP - 724);  // @2_426d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_426d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 732), &v, sizeof v); }  // @4_426d60
  eax = ext_421080_thiscall1(ecx);  // @5_426d60
  ecx = edx = 0;  // @6_426d60
  ecx = eax;  // @7_426d60
  reg.state = (s32)((u32)(0));  // @8_426d60
  eax = ext_4cc1d0_thiscall1(ecx);  // @9_426d60
    // @10_426d60
  edx = (u32)(EBP - 276);  // @11_426d60
  edx = (edx - eax);  // @12_426d60
  FL[3] = edx;  // @13_426d60
  L426dc1:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @15_426d60
  eax = (u32)(eax + 1);  // @16_426d60
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @17_426d60
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @18_426d60
  if (FL[2] != 0) goto L426dc1;  // @19_426d60
  ecx = (u32)(EBP - 724);  // @20_426d60
  reg.state = (s32)((u32)(4294967295));  // @21_426d60
  eax = ext_4cbec0_thiscall1(ecx);  // @22_426d60
  ecx = edx = 0;  // @23_426d60
  esi = ebx;  // @24_426d60
  L426de2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) & 0xff);  // @26_426d60
  ebx = (ebx + 1);  // @27_426d60
  FL[3] = ebx;  // @28_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @29_426d60
  if (FL[2] != 0) goto L426de2;  // @30_426d60
  edi = (u32)(EBP - 276);  // @31_426d60
  ebx = (ebx - esi);  // @32_426d60
  FL[3] = ebx;  // @33_426d60
  edi = (edi - 1);  // @34_426d60
  FL[3] = edi;  // @35_426d60
  L426df2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @37_426d60
  edi = (edi + 1);  // @38_426d60
  FL[3] = edi;  // @39_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @40_426d60
  if (FL[2] != 0) goto L426df2;  // @41_426d60
  ecx = ebx;  // @42_426d60
  ecx = (ecx >> (u32)(2));  // @43_426d60
  FL[3] = ecx;  // @44_426d60
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @45_426d60
  ecx = ebx;  // @46_426d60
  ecx = (ecx & (u32)(3));  // @47_426d60
  FL[3] = ecx;  // @48_426d60
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @49_426d60
  edi = (u32)(EBP - 276);  // @50_426d60
  edi = (edi - 1);  // @51_426d60
  FL[3] = edi;  // @52_426d60
  L426e10:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @54_426d60
  edi = (u32)(edi + 1);  // @55_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @56_426d60
  if (FL[2] != 0) goto L426e10;  // @57_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @58_426d60
  edx = (u32)(EBP - 276);  // @59_426d60
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @60_426d60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @61_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_426d60
  PV[0] = (u32)(edx);  // @63_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @64_426d60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[0], (u32)(0));  // @65_426d60
  ecx = edx = 0;  // @66_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @67_426d60
  if (FL[2] != 0) goto L426e4f;  // @68_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 728), sizeof v); (u32)v; });  // @69_426d60
  edx = (u32)(EBP - 276);  // @70_426d60
  PV[1] = (u32)(edx);  // @71_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_426d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @73_426d60
  ecx = edx = 0;  // @74_426d60
  L426e4f:;
  edi = (u32)(EBP - 276);  // @76_426d60
  edi = (edi - 1);  // @77_426d60
  FL[3] = edi;  // @78_426d60
  L426e56:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @80_426d60
  edi = (u32)(edi + 1);  // @81_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @82_426d60
  if (FL[2] != 0) goto L426e56;  // @83_426d60
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6786308), sizeof v); (u32)v; })) & 0xffff);  // @84_426d60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @85_426d60
  eax = (u32)(EBP - 596);  // @86_426d60
  PV[2] = (u32)(eax);  // @87_426d60
  eax = (u32)(EBP - 276);  // @88_426d60
  PV[3] = (u32)(eax);  // @89_426d60
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67610c))(PV[3], PV[2]);  // @90_426d60
  ecx = edx = 0;  // @91_426d60
  esi = eax;  // @92_426d60
  FL[0] = esi; FL[1] = (u32)(-1);  // @93_426d60
  if (FL[0] == FL[1]) goto L426f32;  // @94_426d60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775056), sizeof v); (u32)v; });  // @95_426d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @96_426d60
  L426e94:;
  eax = (u32)(EBP - 552);  // @98_426d60
  PV[4] = (u32)(eax);  // @99_426d60
  eax = ((u32( *)(u32, u32))(ebx))(PV[4], (u32)(46));  // @100_426d60
  ecx = edx = 0;  // @101_426d60
  FL[2] = (eax & eax);  // @102_426d60
  if (FL[2] == 0) goto L426edd;  // @103_426d60
  ecx = (u32)(6786312);  // @104_426d60
  L426eb0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @106_426d60
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_426d60
  if (FL[0] != FL[1]) goto L426ed0;  // @108_426d60
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @109_426d60
  if (FL[2] == 0) goto L426ecc;  // @110_426d60
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @111_426d60
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @112_426d60
  if (FL[0] != FL[1]) goto L426ed0;  // @113_426d60
  eax = (eax + (u32)(2));  // @114_426d60
  FL[3] = eax;  // @115_426d60
  ecx = (ecx + (u32)(2));  // @116_426d60
  FL[3] = ecx;  // @117_426d60
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @118_426d60
  if (FL[2] != 0) goto L426eb0;  // @119_426d60
  L426ecc:;
  eax = 0;  // @121_426d60
  FL[3] = eax;  // @122_426d60
  goto L426ed5;  // @123_426d60
  L426ed0:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @125_426d60
  eax = (eax | (u32)(1));  // @126_426d60
  FL[3] = eax;  // @127_426d60
  L426ed5:;
  FL[2] = (eax & eax);  // @129_426d60
  if (FL[2] != 0) goto L426edd;  // @130_426d60
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @131_426d60
  goto L426edf;  // @132_426d60
  L426edd:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @134_426d60
  FL[3] = (eax & 0xff);  // @135_426d60
  L426edf:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 552), sizeof v); (u32)v; }); FL[1] = (u32)(46);  // @137_426d60
  if (FL[0] != FL[1]) goto L426f00;  // @138_426d60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 551), sizeof v); (u32)v; })) & 0xff);  // @139_426d60
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @140_426d60
  if (FL[2] == 0) goto L426f19;  // @141_426d60
  FL[0] = (ecx & 0xff); FL[1] = (u32)(46);  // @142_426d60
  if (FL[0] != FL[1]) goto L426f00;  // @143_426d60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 550), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @144_426d60
  if (FL[0] == FL[1]) goto L426f19;  // @145_426d60
  L426f00:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @147_426d60
  if (FL[2] == 0) goto L426f19;  // @148_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 732), sizeof v); (u32)v; });  // @149_426d60
  edx = (u32)(EBP - 552);  // @150_426d60
  PV[5] = (u32)(edx);  // @151_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_426d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[5]);  // @153_426d60
  ecx = edx = 0;  // @154_426d60
  L426f19:;
  eax = (u32)(EBP - 596);  // @156_426d60
  PV[6] = (u32)(eax);  // @157_426d60
  PV[7] = (u32)(esi);  // @158_426d60
  eax = ((u32(STDCALL *)(u32, u32))(edi))(PV[7], PV[6]);  // @159_426d60
  ecx = edx = 0;  // @160_426d60
  FL[2] = (eax & eax);  // @161_426d60
  if (FL[2] != 0) goto L426e94;  // @162_426d60
  PV[8] = (u32)(esi);  // @163_426d60
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676108))(PV[8]);  // @164_426d60
  ecx = edx = 0;  // @165_426d60
  L426f32:;
  SEH_LEAVE();  // @167_426d60
  ext_633654(G(u32, 0x6f5630));  // @168_426d60
  return eax;  // @169_426d60
}
PCREG(426d60, lifted_426d60);

extern "C" u32 THISCALL lifted_4f4790(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ecx;  // @0_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @1_4f4790
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 176), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_4f4790
  if (FL[0] == FL[1]) goto L4f4973;  // @3_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 172), sizeof v); (u32)v; });  // @4_4f4790
  FL[2] = (ecx & ecx);  // @5_4f4790
  if (FL[2] == 0) goto L4f4973;  // @6_4f4790
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @7_4f4790
  if (FL[0] == FL[1]) goto L4f4973;  // @8_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4f4790
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @12_4f4790
  ecx = edx = 0;  // @13_4f4790
  ecx = (u32)(EBP - 24);  // @14_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @15_4f4790
  PV[0] = (u32)(ecx);  // @16_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_4f4790
  ecx = eax;  // @18_4f4790
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6918004), PV[0]);  // @19_4f4790
  ecx = edx = 0;  // @20_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4f4790
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @22_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @25_4f4790
  ecx = edx = 0;  // @26_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @27_4f4790
  edx = 0;  // @28_4f4790
  FL[3] = edx;  // @29_4f4790
  esi = 0;  // @30_4f4790
  FL[3] = esi;  // @31_4f4790
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 176), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @32_4f4790
  X0[0] = F2U((float)(s32)X0[0]);  // @33_4f4790
  X0[1] = F2U((float)(s32)X0[1]);  // @34_4f4790
  X0[2] = F2U((float)(s32)X0[2]);  // @35_4f4790
  X0[3] = F2U((float)(s32)X0[3]);  // @36_4f4790
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 155) + 0), 4); v; })));  // @37_4f4790
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @38_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @39_4f4790
  L4f4823:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; });  // @41_4f4790
  edi = 0;  // @42_4f4790
  FL[3] = edi;  // @43_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @44_4f4790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @45_4f4790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @46_4f4790
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @47_4f4790
  if (FL[0] == FL[1]) goto L4f48fb;  // @48_4f4790
  L4f4840:;
  ecx = (u32)(EBP - 20);  // @50_4f4790
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @51_4f4790
  eax = ext_4cc500_fastcall2(ecx, edx);  // @52_4f4790
  ecx = edx = 0;  // @53_4f4790
  edx = eax;  // @54_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @55_4f4790
  eax = (eax - ebx);  // @56_4f4790
  FL[3] = eax;  // @57_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @58_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @59_4f4790
  FL[0] = edx; FL[1] = (u32)(10);  // @60_4f4790
  if (FL[0] != FL[1]) goto L4f4866;  // @61_4f4790
  ecx = 0;  // @62_4f4790
  FL[3] = ecx;  // @63_4f4790
  edi = 0;  // @64_4f4790
  FL[3] = edi;  // @65_4f4790
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @66_4f4790
  goto L4f48ad;  // @67_4f4790
  L4f4866:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @69_4f4790
  PV[2] = (u32)(edx);  // @70_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 159), sizeof v); (u32)v; });  // @71_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 640)))(ecx, PV[2]);  // @73_4f4790
  ecx = edx = 0;  // @74_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @75_4f4790
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }));  // @76_4f4790
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @77_4f4790
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @78_4f4790
  ecx = (ecx + eax);  // @79_4f4790
  FL[3] = ecx;  // @80_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @81_4f4790
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @82_4f4790
  FL[0] = eax; FL[1] = (u32)(32);  // @83_4f4790
  if (FL[0] == FL[1]) goto L4f4894;  // @84_4f4790
  FL[0] = eax; FL[1] = (u32)(9);  // @85_4f4790
  if (FL[0] != FL[1]) goto L4f48aa;  // @86_4f4790
  L4f4894:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @88_4f4790
  edi = ebx;  // @89_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @90_4f4790
  FL[2] = (edx & edx);  // @91_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @92_4f4790
  if (FL[2] != 0) edi = esi;  // @93_4f4790
  goto L4f48b0;  // @94_4f4790
  L4f48aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @96_4f4790
  L4f48ad:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @98_4f4790
  L4f48b0:;
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @100_4f4790
  if ((s32)FL[0] > (s32)FL[1]) goto L4f48cf;  // @101_4f4790
  FL[2] = (edx & edx);  // @102_4f4790
  if (FL[2] == 0) goto L4f48c7;  // @103_4f4790
  PV[3] = (u32)(eax);  // @104_4f4790
  PV[4] = (u32)(ebx);  // @105_4f4790
  PV[5] = (u32)(esi);  // @106_4f4790
  eax = ext_634d22_cdecl3(PV[5], PV[4], PV[3]);  // @107_4f4790
    // @108_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @109_4f4790
  L4f48c7:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @111_4f4790
  esi = (esi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @112_4f4790
  FL[3] = esi;  // @113_4f4790
  goto L4f48ef;  // @114_4f4790
  L4f48cf:;
  FL[2] = (edi & edi);  // @116_4f4790
  if (FL[2] == 0) goto L4f48e0;  // @117_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @118_4f4790
  { u8 v = (u8)((u32)(10)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @119_4f4790
  edi = 0;  // @120_4f4790
  FL[3] = edi;  // @121_4f4790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @122_4f4790
  goto L4f48ef;  // @123_4f4790
  L4f48e0:;
  FL[2] = (edx & edx);  // @125_4f4790
  if (FL[2] == 0) goto L4f48e7;  // @126_4f4790
  { u8 v = (u8)((u32)(10)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @127_4f4790
  L4f48e7:;
  esi = (esi + 1);  // @129_4f4790
  FL[3] = esi;  // @130_4f4790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @131_4f4790
  L4f48ef:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @133_4f4790
  if (FL[0] != FL[1]) goto L4f4840;  // @134_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @135_4f4790
  L4f48fb:;
  FL[2] = (edx & edx);  // @137_4f4790
  if (FL[2] != 0) goto L4f493d;  // @138_4f4790
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; }));  // @139_4f4790
  FL[3] = ebx;  // @140_4f4790
  FL[0] = esi; FL[1] = ebx;  // @141_4f4790
  if (FL[0] == FL[1]) goto L4f492b;  // @142_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @143_4f4790
  eax = (u32)(esi + 1);  // @144_4f4790
  PV[6] = (u32)(eax);  // @145_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, PV[6]);  // @147_4f4790
  ecx = edx = 0;  // @148_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @149_4f4790
  edx = eax;  // @150_4f4790
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + edx), &v, sizeof v); }  // @151_4f4790
  esi = edx;  // @152_4f4790
  goto L4f4823;  // @153_4f4790
  L4f492b:;
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 172), sizeof v); (u32)v; });  // @155_4f4790
  eax = ext_4f12e0_thiscall2(ecx, PV[7]);  // @156_4f4790
  ecx = edx = 0;  // @157_4f4790
  return eax;  // @158_4f4790
  L4f493d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 151), sizeof v); (u32)v; });  // @160_4f4790
  FL[2] = (esi & esi);  // @161_4f4790
  if (FL[2] == 0) goto L4f495c;  // @162_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @163_4f4790
  PV[8] = (u32)(esi);  // @164_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_4f4790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, PV[8]);  // @166_4f4790
  ecx = edx = 0;  // @167_4f4790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @168_4f4790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @169_4f4790
  L4f495c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @171_4f4790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 151), &v, sizeof v); }  // @172_4f4790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 632), sizeof v); (u32)v; });  // @173_4f4790
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @174_4f4790
  ecx = edx = 0;  // @175_4f4790
  return eax;  // @176_4f4790
  L4f4973:;
  ecx = eax;  // @178_4f4790
  eax = ext_4f12e0_thiscall2(ecx, (u32)(6781786));  // @179_4f4790
  ecx = edx = 0;  // @180_4f4790
  return eax;  // @181_4f4790
}
PCREG(4f4790, lifted_4f4790);

extern "C" u32 THISCALL lifted_54b1f0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_54b1f0
  esi = 0;  // @1_54b1f0
  FL[3] = esi;  // @2_54b1f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 552), &v, sizeof v); }  // @3_54b1f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @4_54b1f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32869), sizeof v); (u32)v; }); FL[1] = esi;  // @5_54b1f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L54b402;  // @6_54b1f0
  ebx = (u32)(edi + 32881);  // @7_54b1f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @8_54b1f0
  L54b230:;
  eax = (u32)(EBP - 536);  // @10_54b1f0
  PV[0] = (u32)(eax);  // @11_54b1f0
  eax = ext_634d10_cdecl3(PV[0], (u32)(0), (u32)(512));  // @12_54b1f0
    // @13_54b1f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_54b1f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @16_54b1f0
  ecx = edx = 0;  // @17_54b1f0
  PV[1] = (u32)(esi);  // @18_54b1f0
  edx = (u32)(EBP - 536);  // @19_54b1f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_54b1f0
  PV[2] = (u32)(edx);  // @21_54b1f0
  PV[3] = (u32)(eax);  // @22_54b1f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[3], PV[2], (u32)(6960268), PV[1]);  // @23_54b1f0
  ecx = edx = 0;  // @24_54b1f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 544), &v, sizeof v); }  // @25_54b1f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @26_54b1f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L54b3b2;  // @27_54b1f0
  ebx = (ebx + (u32)(8));  // @28_54b1f0
  FL[3] = ebx;  // @29_54b1f0
  L54b283:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @31_54b1f0
  eax = (eax - (u32)(1));  // @32_54b1f0
  FL[3] = eax;  // @33_54b1f0
  if (FL[3] == 0) goto L54b311;  // @34_54b1f0
  ecx = (u32)(EBP - 536);  // @35_54b1f0
  eax = (eax - (u32)(1));  // @36_54b1f0
  FL[3] = eax;  // @37_54b1f0
  if (FL[3] == 0) goto L54b2f5;  // @38_54b1f0
  eax = (eax - (u32)(1));  // @39_54b1f0
  FL[3] = eax;  // @40_54b1f0
  if (FL[3] == 0) goto L54b2c6;  // @41_54b1f0
  ecx = (ecx - 1);  // @42_54b1f0
  FL[3] = ecx;  // @43_54b1f0
  L54b2a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @45_54b1f0
  ecx = (u32)(ecx + 1);  // @46_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @47_54b1f0
  if (FL[2] != 0) goto L54b2a0;  // @48_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960312), sizeof v); (u32)v; });  // @49_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @50_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960316), sizeof v); (u32)v; });  // @51_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @52_54b1f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6960320), sizeof v); (u32)v; })) & 0xff);  // @53_54b1f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @54_54b1f0
  goto L54b386;  // @55_54b1f0
  L54b2c6:;
  ecx = (ecx - 1);  // @57_54b1f0
  FL[3] = ecx;  // @58_54b1f0
  L54b2c7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @60_54b1f0
  ecx = (u32)(ecx + 1);  // @61_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @62_54b1f0
  if (FL[2] != 0) goto L54b2c7;  // @63_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960296), sizeof v); (u32)v; });  // @64_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @65_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960300), sizeof v); (u32)v; });  // @66_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @67_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960304), sizeof v); (u32)v; });  // @68_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @69_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960308), sizeof v); (u32)v; });  // @70_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @71_54b1f0
  goto L54b386;  // @72_54b1f0
  L54b2f5:;
  ecx = (ecx - 1);  // @74_54b1f0
  FL[3] = ecx;  // @75_54b1f0
  L54b2f6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @77_54b1f0
  ecx = (u32)(ecx + 1);  // @78_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @79_54b1f0
  if (FL[2] != 0) goto L54b2f6;  // @80_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960280), sizeof v); (u32)v; });  // @81_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @82_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960284), sizeof v); (u32)v; });  // @83_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @84_54b1f0
  goto L54b386;  // @85_54b1f0
  L54b311:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_54b1f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 12) + 0), 4); v; });  // @88_54b1f0
  X0[1] = 0;  // @89_54b1f0
  X0[2] = 0;  // @90_54b1f0
  X0[3] = 0;  // @91_54b1f0
  eax = (u32)(EBP - 24);  // @92_54b1f0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @93_54b1f0
  PV[4] = X0[0]; PV[5] = X0[1];  // @94_54b1f0
  PV[6] = (u32)(eax);  // @95_54b1f0
  eax = ext_42ac56_cdecl4(PV[6], (u32)(6955596), PV[4], PV[5]);  // @96_54b1f0
  ecx = edx = 0;  // @97_54b1f0
  ecx = (u32)(EBP - 536);  // @98_54b1f0
  ecx = (ecx - 1);  // @99_54b1f0
  FL[3] = ecx;  // @100_54b1f0
  L54b340:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @102_54b1f0
  ecx = (u32)(ecx + 1);  // @103_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @104_54b1f0
  if (FL[2] != 0) goto L54b340;  // @105_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960288), sizeof v); (u32)v; });  // @106_54b1f0
  edx = (u32)(EBP - 24);  // @107_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @108_54b1f0
  esi = edx;  // @109_54b1f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6960292), sizeof v); (u32)v; })) & 0xffff);  // @110_54b1f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @111_54b1f0
  L54b360:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @113_54b1f0
  edx = (edx + 1);  // @114_54b1f0
  FL[3] = edx;  // @115_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @116_54b1f0
  if (FL[2] != 0) goto L54b360;  // @117_54b1f0
  edi = (u32)(EBP - 536);  // @118_54b1f0
  edx = (edx - esi);  // @119_54b1f0
  FL[3] = edx;  // @120_54b1f0
  edi = (edi - 1);  // @121_54b1f0
  FL[3] = edi;  // @122_54b1f0
  L54b370:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @124_54b1f0
  edi = (edi + 1);  // @125_54b1f0
  FL[3] = edi;  // @126_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @127_54b1f0
  if (FL[2] != 0) goto L54b370;  // @128_54b1f0
  ecx = edx;  // @129_54b1f0
  ecx = (ecx >> (u32)(2));  // @130_54b1f0
  FL[3] = ecx;  // @131_54b1f0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @132_54b1f0
  ecx = edx;  // @133_54b1f0
  ecx = (ecx & (u32)(3));  // @134_54b1f0
  FL[3] = ecx;  // @135_54b1f0
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @136_54b1f0
  L54b386:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 544), sizeof v); (u32)v; });  // @138_54b1f0
  ebx = (ebx + (u32)(8));  // @139_54b1f0
  FL[3] = ebx;  // @140_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @141_54b1f0
  ecx = (ecx + 1);  // @142_54b1f0
  FL[3] = ecx;  // @143_54b1f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 544), &v, sizeof v); }  // @144_54b1f0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @145_54b1f0
  if ((s32)FL[0] < (s32)FL[1]) goto L54b283;  // @146_54b1f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 548), sizeof v); (u32)v; });  // @147_54b1f0
  ebx = eax;  // @148_54b1f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 552), sizeof v); (u32)v; });  // @149_54b1f0
  L54b3b2:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 41581), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @151_54b1f0
  if (FL[0] == FL[1]) goto L54b3e2;  // @152_54b1f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @153_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @154_54b1f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @155_54b1f0
  ecx = edx = 0;  // @156_54b1f0
  ecx = (u32)(EBP - 536);  // @157_54b1f0
  PV[7] = (u32)(ecx);  // @158_54b1f0
  ecx = (u32)(esi + 40);  // @159_54b1f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @160_54b1f0
  PV[8] = (u32)(ecx);  // @161_54b1f0
  PV[9] = (u32)(eax);  // @162_54b1f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[9], (u32)(30), PV[8], PV[7]);  // @163_54b1f0
  ecx = edx = 0;  // @164_54b1f0
  L54b3e2:;
  esi = (esi + 1);  // @166_54b1f0
  FL[3] = esi;  // @167_54b1f0
  ebx = (ebx + (u32)(272));  // @168_54b1f0
  FL[3] = ebx;  // @169_54b1f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @170_54b1f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @171_54b1f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32869), sizeof v); (u32)v; });  // @172_54b1f0
  if ((s32)FL[0] < (s32)FL[1]) goto L54b230;  // @173_54b1f0
  L54b402:;
  ext_633654(G(u32, 0x6f5630));  // @175_54b1f0
  return eax;  // @176_54b1f0
}
PCREG(54b1f0, lifted_54b1f0);

extern "C" u32 THISCALL lifted_64a410(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_64a410
  ebx = ecx;  // @1_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 448), &v, sizeof v); }  // @2_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_64a410
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @5_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @6_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @7_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @8_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @9_64a410
  edx = (u32)(edi + 44);  // @10_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @11_64a410
  eax = (u32)(ebx + 98845);  // @12_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 432), &v, sizeof v); }  // @13_64a410
  ecx = (u32)(EBP - 16);  // @14_64a410
  PV[0] = (u32)(eax);  // @15_64a410
  eax = ext_43e920_fastcall3(ecx, edx, PV[0]);  // @16_64a410
  ecx = edx = 0;  // @17_64a410
  esi = (u32)(ebx + 98809);  // @18_64a410
  edx = esi;  // @19_64a410
  ecx = (u32)(EBP - 16);  // @20_64a410
  eax = ext_441a60_fastcall2(ecx, edx);  // @21_64a410
  ecx = edx = 0;  // @22_64a410
  PV[1] = (u32)(esi);  // @23_64a410
  edx = (u32)(edi + 8);  // @24_64a410
  ecx = (u32)(EBP - 68);  // @25_64a410
  eax = ext_4de4b0_fastcall3(ecx, edx, PV[1]);  // @26_64a410
  ecx = edx = 0;  // @27_64a410
  edx = (u32)(EBP - 68);  // @28_64a410
  ecx = (u32)(EBP - 116);  // @29_64a410
  eax = ext_4de420_fastcall2(ecx, edx);  // @30_64a410
    // @31_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @32_64a410
  esi = 0;  // @33_64a410
  FL[3] = esi;  // @34_64a410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @35_64a410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @36_64a410
  X0[2] = 0;  // @37_64a410
  X0[3] = 0;  // @38_64a410
  edi = 0;  // @39_64a410
  FL[3] = edi;  // @40_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @41_64a410
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @42_64a410
  __builtin_memcpy((void *)((u32)(EBP - 32) + 4), &X0[1], 4);  // @43_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @44_64a410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 436), &v, sizeof v); }  // @45_64a410
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @46_64a410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 444), &v, sizeof v); }  // @47_64a410
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 140), sizeof v); (u32)v; }); FL[1] = esi;  // @48_64a410
  if ((s32)FL[0] <= (s32)FL[1]) goto L64a60b;  // @49_64a410
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @50_64a410
  L64a4e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 144), sizeof v); (u32)v; });  // @52_64a410
  ecx = (ecx + edi);  // @53_64a410
  FL[3] = ecx;  // @54_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 440), &v, sizeof v); }  // @55_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @56_64a410
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 135), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @57_64a410
  if (FL[0] != FL[1]) goto L64a5dd;  // @58_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @59_64a410
  PV[2] = (u32)(ecx);  // @60_64a410
  ecx = (u32)(EBP - 32);  // @61_64a410
  PV[3] = (u32)(ecx);  // @62_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 100), sizeof v); (u32)v; });  // @63_64a410
  ecx = (u32)(EBP - 116);  // @64_64a410
  PV[4] = (u32)(ecx);  // @65_64a410
  ecx = (u32)(EBP - 164);  // @66_64a410
  PV[5] = (u32)(ecx);  // @67_64a410
  ecx = (u32)(EBP - 20);  // @68_64a410
  PV[6] = (u32)(ecx);  // @69_64a410
  ecx = ebx;  // @70_64a410
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[6], PV[5], PV[4], PV[3], PV[2]);  // @71_64a410
  ecx = edx = 0;  // @72_64a410
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @73_64a410
  if (FL[2] == 0) goto L64a5dd;  // @74_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @75_64a410
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @76_64a410
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @77_64a410
  if (FL[0] == FL[1]) goto L64a5d7;  // @78_64a410
  L64a535:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @80_64a410
  ecx = (u32)(EBP - 164);  // @81_64a410
  PV[7] = (u32)(edi);  // @82_64a410
  PV[8] = (u32)(ecx);  // @83_64a410
  ecx = (u32)(EBP - 80);  // @84_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; });  // @85_64a410
  PV[9] = (u32)(ecx);  // @86_64a410
  ecx = ebx;  // @87_64a410
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[9], PV[8], PV[7]);  // @88_64a410
  ecx = edx = 0;  // @89_64a410
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @90_64a410
  if (FL[2] == 0) goto L64a5cb;  // @91_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; });  // @92_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @93_64a410
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 436), sizeof v); (u32)v; }); FL[1] = ecx;  // @94_64a410
  if (FL[0] == FL[1]) goto L64a5ac;  // @95_64a410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 136), sizeof v); (u32)v; });  // @96_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 436), &v, sizeof v); }  // @97_64a410
  FL[2] = (esi & esi);  // @98_64a410
  if (FL[2] != 0) goto L64a58e;  // @99_64a410
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @100_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @101_64a410
  PV[11] = (u32)(ecx);  // @102_64a410
  ecx = ebx;  // @103_64a410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[11], PV[10]);  // @104_64a410
  ecx = edx = 0;  // @105_64a410
  esi = eax;  // @106_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; });  // @107_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @108_64a410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 136), &v, sizeof v); }  // @109_64a410
  L64a58e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @111_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @112_64a410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + eax*8 - 420), &v, sizeof v); }  // @113_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + eax*8 - 416), &v, sizeof v); }  // @114_64a410
  eax = (eax + 1);  // @115_64a410
  FL[3] = eax;  // @116_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @117_64a410
  L64a5ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @119_64a410
  ecx = ebx;  // @120_64a410
  PV[12] = (u32)(esi);  // @121_64a410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[12]);  // @122_64a410
  ecx = edx = 0;  // @123_64a410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @124_64a410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 4), 4); v; });  // @125_64a410
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 8), 4); v; });  // @126_64a410
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 12), 4); v; });  // @127_64a410
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @128_64a410
  __builtin_memcpy((void *)((u32)(eax) + 4), &X0[1], 4);  // @129_64a410
  __builtin_memcpy((void *)((u32)(eax) + 8), &X0[2], 4);  // @130_64a410
  __builtin_memcpy((void *)((u32)(eax) + 12), &X0[3], 4);  // @131_64a410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @132_64a410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 4), 4); v; });  // @133_64a410
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 8), 4); v; });  // @134_64a410
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 12), 4); v; });  // @135_64a410
  __builtin_memcpy((void *)((u32)(eax + 16) + 0), &X0[0], 4);  // @136_64a410
  __builtin_memcpy((void *)((u32)(eax + 16) + 4), &X0[1], 4);  // @137_64a410
  __builtin_memcpy((void *)((u32)(eax + 16) + 8), &X0[2], 4);  // @138_64a410
  __builtin_memcpy((void *)((u32)(eax + 16) + 12), &X0[3], 4);  // @139_64a410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @140_64a410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 4), 4); v; });  // @141_64a410
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 8), 4); v; });  // @142_64a410
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 12), 4); v; });  // @143_64a410
  __builtin_memcpy((void *)((u32)(eax + 32) + 0), &X0[0], 4);  // @144_64a410
  __builtin_memcpy((void *)((u32)(eax + 32) + 4), &X0[1], 4);  // @145_64a410
  __builtin_memcpy((void *)((u32)(eax + 32) + 8), &X0[2], 4);  // @146_64a410
  __builtin_memcpy((void *)((u32)(eax + 32) + 12), &X0[3], 4);  // @147_64a410
  L64a5cb:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @149_64a410
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @150_64a410
  if (FL[0] != FL[1]) goto L64a535;  // @151_64a410
  L64a5d7:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @153_64a410
  L64a5dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @155_64a410
  edi = (edi + (u32)(52));  // @156_64a410
  FL[3] = edi;  // @157_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @158_64a410
  eax = (eax + 1);  // @159_64a410
  FL[3] = eax;  // @160_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 444), &v, sizeof v); }  // @161_64a410
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @162_64a410
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 140), sizeof v); (u32)v; });  // @163_64a410
  if ((s32)FL[0] < (s32)FL[1]) goto L64a4e0;  // @164_64a410
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @165_64a410
  L64a60b:;
  esi = 0;  // @167_64a410
  FL[3] = esi;  // @168_64a410
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + 135), &v, sizeof v); }  // @169_64a410
  FL[2] = (edi & edi);  // @170_64a410
  if ((s32)FL[2] <= 0) goto L64a654;  // @171_64a410
  L64a620:;
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; });  // @173_64a410
  ecx = ebx;  // @174_64a410
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), sizeof v); (u32)v; });  // @175_64a410
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @176_64a410
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*8 - 416), sizeof v); (u32)v; });  // @177_64a410
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*8 - 420), sizeof v); (u32)v; });  // @178_64a410
  eax = ext_64a410_thiscall7(ecx, PV[17], PV[16], PV[15], PV[14], PV[13], (u32)(0));  // @179_64a410
  ecx = edx = 0;  // @180_64a410
  esi = (esi + 1);  // @181_64a410
  FL[3] = esi;  // @182_64a410
  FL[0] = esi; FL[1] = edi;  // @183_64a410
  if ((s32)FL[0] < (s32)FL[1]) goto L64a620;  // @184_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @185_64a410
  L64a654:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; })) & 0xff);  // @187_64a410
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 135), &v, sizeof v); }  // @188_64a410
  ext_633654(G(u32, 0x6f5630));  // @189_64a410
  return eax;  // @190_64a410
}
PCREG(64a410, lifted_64a410);

extern "C" u32 THISCALL lifted_45c910(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6665e6);  // @h_45c910
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_45c910
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_45c910
  esi = (u32)(6781786);  // @3_45c910
  FL[2] = (eax & eax);  // @4_45c910
  if (FL[2] != 0) esi = eax;  // @5_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @6_45c910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @7_45c910
  ecx = edx = 0;  // @8_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @9_45c910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @10_45c910
  if (FL[0] != FL[1]) goto L45c98f;  // @11_45c910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @12_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(28));  // @14_45c910
  ecx = edx = 0;  // @15_45c910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @16_45c910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @17_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @18_45c910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @19_45c910
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @20_45c910
  reg.state = (s32)((u32)(0));  // @21_45c910
  FL[2] = (ecx & ecx);  // @22_45c910
  if (FL[2] == 0) goto L45c988;  // @23_45c910
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(4), (u32)(5));  // @24_45c910
  ecx = edx = 0;  // @25_45c910
  L45c988:;
  reg.state = (s32)((u32)(4294967295));  // @27_45c910
  L45c98f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @29_45c910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @30_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @32_45c910
  ecx = edx = 0;  // @33_45c910
  ebx = eax;  // @34_45c910
  eax = esi;  // @35_45c910
  edx = (u32)(eax + 1);  // @36_45c910
  L45c9a3:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @38_45c910
  eax = (eax + 1);  // @39_45c910
  FL[3] = eax;  // @40_45c910
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @41_45c910
  if (FL[2] != 0) goto L45c9a3;  // @42_45c910
  eax = (eax - edx);  // @43_45c910
  FL[3] = eax;  // @44_45c910
  eax = (eax + 1);  // @45_45c910
  FL[3] = eax;  // @46_45c910
  PV[0] = (u32)(eax);  // @47_45c910
  eax = ext_41e290_cdecl1(PV[0]);  // @48_45c910
  ecx = edx = 0;  // @49_45c910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @50_45c910
  eax = ext_41e290_cdecl1((u32)(40));  // @51_45c910
  ecx = edx = 0;  // @52_45c910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @53_45c910
  reg.state = (s32)((u32)(1));  // @54_45c910
  FL[2] = (eax & eax);  // @55_45c910
  if (FL[2] == 0) goto L45c9db;  // @56_45c910
  ecx = eax;  // @57_45c910
  eax = ext_4cca60_thiscall3(ecx, (u32)(16), (u32)(0));  // @58_45c910
  ecx = edx = 0;  // @59_45c910
  goto L45c9dd;  // @60_45c910
  L45c9db:;
  eax = 0;  // @62_45c910
  FL[3] = eax;  // @63_45c910
  L45c9dd:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @65_45c910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 16), &v, sizeof v); }  // @66_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @67_45c910
  reg.state = (s32)((u32)(4294967295));  // @68_45c910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @69_45c910
  eax = (u32)(1);  // @70_45c910
  X0[0] = F2U((float)(s32)X0[0]);  // @71_45c910
  X0[1] = F2U((float)(s32)X0[1]);  // @72_45c910
  X0[2] = F2U((float)(s32)X0[2]);  // @73_45c910
  X0[3] = F2U((float)(s32)X0[3]);  // @74_45c910
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @75_45c910
  __builtin_memcpy((void *)((u32)(ebx + 4) + 0), &X0[0], 4);  // @76_45c910
  FL[2] = (edi & edi);  // @77_45c910
  if (FL[2] == 0) goto L45ca46;  // @78_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @79_45c910
  ecx = (u32)(EBP - 28);  // @80_45c910
  PV[1] = (u32)(ecx);  // @81_45c910
  ecx = edi;  // @82_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @83_45c910
  ecx = edx = 0;  // @84_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_45c910
  ecx = (u32)(EBP - 28);  // @86_45c910
  PV[2] = (u32)(ecx);  // @87_45c910
  ecx = edi;  // @88_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[2]);  // @89_45c910
  ecx = edx = 0;  // @90_45c910
  FL[2] = (eax & eax);  // @91_45c910
  if (FL[2] == 0) goto L45ca41;  // @92_45c910
  L45ca27:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @94_45c910
  ecx = (u32)(EBP - 28);  // @95_45c910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @96_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @97_45c910
  PV[3] = (u32)(ecx);  // @98_45c910
  ecx = edi;  // @99_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[3]);  // @100_45c910
  ecx = edx = 0;  // @101_45c910
  FL[2] = (eax & eax);  // @102_45c910
  if (FL[2] != 0) goto L45ca27;  // @103_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @104_45c910
  goto L45ca46;  // @105_45c910
  L45ca41:;
  eax = (u32)(1);  // @107_45c910
  L45ca46:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836848) + 0), 4); v; });  // @109_45c910
  X1[1] = 0;  // @110_45c910
  X1[2] = 0;  // @111_45c910
  X1[3] = 0;  // @112_45c910
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @113_45c910
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @114_45c910
  eax = (eax >> (u32)(31));  // @115_45c910
  FL[3] = eax;  // @116_45c910
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @117_45c910
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @118_45c910
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @119_45c910
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @120_45c910
  __builtin_memcpy((void *)((u32)(ebx) + 0), &X1[0], 4);  // @121_45c910
  FL[2] = (edi & edi);  // @122_45c910
  if (FL[2] == 0) goto L45caac;  // @123_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @124_45c910
  ecx = (u32)(EBP - 40);  // @125_45c910
  PV[4] = (u32)(ecx);  // @126_45c910
  ecx = edi;  // @127_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @128_45c910
  ecx = edx = 0;  // @129_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @130_45c910
  ecx = (u32)(EBP - 40);  // @131_45c910
  PV[5] = (u32)(ecx);  // @132_45c910
  ecx = edi;  // @133_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @134_45c910
  ecx = edx = 0;  // @135_45c910
  FL[2] = (eax & eax);  // @136_45c910
  if (FL[2] == 0) goto L45caac;  // @137_45c910
  L45ca93:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @139_45c910
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @140_45c910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[6]);  // @142_45c910
  ecx = edx = 0;  // @143_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @144_45c910
  ecx = (u32)(EBP - 40);  // @145_45c910
  PV[7] = (u32)(ecx);  // @146_45c910
  ecx = edi;  // @147_45c910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[7]);  // @148_45c910
  ecx = edx = 0;  // @149_45c910
  FL[2] = (eax & eax);  // @150_45c910
  if (FL[2] != 0) goto L45ca93;  // @151_45c910
  L45caac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @153_45c910
  L45cab0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @155_45c910
  esi = (u32)(esi + 1);  // @156_45c910
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @157_45c910
  ecx = (u32)(ecx + 1);  // @158_45c910
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @159_45c910
  if (FL[2] != 0) goto L45cab0;  // @160_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @161_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @162_45c910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @163_45c910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_45c910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @165_45c910
  ecx = edx = 0;  // @166_45c910
  SEH_LEAVE();  // @167_45c910
  return eax;  // @168_45c910
}
PCREG(45c910, lifted_45c910);

