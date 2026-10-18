// batch244034.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_4ec040(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @0_4ec040
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @1_4ec040
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 156) + 80), &v, sizeof v); }  // @3_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @4_4ec040
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 156) + 60), &v, sizeof v); }  // @5_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 156) + 32), &v, sizeof v); }  // @6_4ec040
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_4ec040
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 156) + 56), &v, sizeof v); }  // @8_4ec040
  FL[2] = (esi & esi);  // @9_4ec040
  if (FL[2] == 0) goto L4ec08f;  // @10_4ec040
  FL[2] = (edx & edx);  // @11_4ec040
  if (FL[2] == 0) goto L4ec08f;  // @12_4ec040
  ecx = edx;  // @13_4ec040
  eax = 0;  // @14_4ec040
  FL[3] = eax;  // @15_4ec040
  edi = esi;  // @16_4ec040
  while (ecx) { __builtin_memcpy((void *)edi, &eax, 4); edi += 4; ecx--; }  // @17_4ec040
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 56), sizeof v); (u32)v; });  // @18_4ec040
  L4ec08f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 156) + 36), &v, sizeof v); }  // @20_4ec040
  FL[2] = (edx & edx);  // @21_4ec040
  if (FL[2] == 0) goto L4ec5ed;  // @22_4ec040
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 32), sizeof v); (u32)v; });  // @23_4ec040
  ecx = edi;  // @24_4ec040
  ecx = (ecx - edx);  // @25_4ec040
  FL[3] = ecx;  // @26_4ec040
  eax = esi;  // @27_4ec040
  edx = (edx - esi);  // @28_4ec040
  FL[3] = edx;  // @29_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 156) + 24), &v, sizeof v); }  // @30_4ec040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 156) + 40), &v, sizeof v); }  // @31_4ec040
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 156) + 92), &v, sizeof v); }  // @32_4ec040
  L4ec0b7:;
  esi = (u32)(edx + eax);  // @34_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @35_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + ecx), sizeof v); (u32)v; });  // @36_4ec040
  edx = (u32)((EBP - 156) + 144);  // @37_4ec040
  PV[0] = (u32)(edx);  // @38_4ec040
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 160) + 24), &v, sizeof v); }  // @39_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @40_4ec040
  X0[1] = 0;  // @41_4ec040
  X0[2] = 0;  // @42_4ec040
  X0[3] = 0;  // @43_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 160) + 148) + 0), &X0[0], 4);  // @44_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @45_4ec040
  X0[1] = 0;  // @46_4ec040
  X0[2] = 0;  // @47_4ec040
  X0[3] = 0;  // @48_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 160) + 152) + 0), &X0[0], 4);  // @49_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @50_4ec040
  X0[1] = 0;  // @51_4ec040
  X0[2] = 0;  // @52_4ec040
  X0[3] = 0;  // @53_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 160) + 156) + 0), &X0[0], 4);  // @54_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4ec040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[0]);  // @56_4ec040
  ecx = edx = 0;  // @57_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 80), sizeof v); (u32)v; });  // @59_4ec040
  ecx = (u32)(ecx + eax*4);  // @60_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 156) + 28), &v, sizeof v); }  // @62_4ec040
  FL[2] = (eax & eax);  // @63_4ec040
  if (FL[2] == 0) goto L4ec5c8;  // @64_4ec040
  L4ec114:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @66_4ec040
  ecx = (ecx + (u32)(4));  // @67_4ec040
  FL[3] = ecx;  // @68_4ec040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 156) + 88), &v, sizeof v); }  // @69_4ec040
  ecx = esi;  // @70_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @71_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 564), sizeof v); (u32)v; });  // @72_4ec040
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @73_4ec040
  ecx = edx = 0;  // @74_4ec040
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @75_4ec040
  if (FL[2] == 0) goto L4ec5b6;  // @76_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_4ec040
  ecx = esi;  // @78_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 560), sizeof v); (u32)v; });  // @79_4ec040
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @80_4ec040
  ecx = edx = 0;  // @81_4ec040
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_4ec040
  ecx = esi;  // @83_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 156) + 64), &v, sizeof v); }  // @84_4ec040
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 580), sizeof v); (u32)v; });  // @85_4ec040
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @86_4ec040
  ecx = edx = 0;  // @87_4ec040
  esi = eax;  // @88_4ec040
  edx = esi;  // @89_4ec040
  ecx = (u32)(esi + 12);  // @90_4ec040
  PV[1] = (u32)(ecx);  // @91_4ec040
  ecx = (u32)((EBP - 160) + 124);  // @92_4ec040
  eax = ext_43e920_fastcall3(ecx, edx, PV[1]);  // @93_4ec040
  ecx = edx = 0;  // @94_4ec040
  ecx = (u32)(esi + 36);  // @95_4ec040
  edx = esi;  // @96_4ec040
  PV[2] = (u32)(ecx);  // @97_4ec040
  ecx = (u32)((EBP - 160) + 136);  // @98_4ec040
  eax = ext_43e920_fastcall3(ecx, edx, PV[2]);  // @99_4ec040
  ecx = edx = 0;  // @100_4ec040
  PV[3] = (u32)(ecx);  // @101_4ec040
  ecx = (u32)((EBP - 160) + 124);  // @102_4ec040
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @103_4ec040
    // @104_4ec040
  PV[4] = (u32)(ecx);  // @105_4ec040
  ecx = (u32)((EBP - 160) + 136);  // @106_4ec040
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @107_4ec040
    // @108_4ec040
  eax = (u32)((EBP - 156) + 132);  // @109_4ec040
  PV[5] = (u32)(eax);  // @110_4ec040
  edx = (u32)((EBP - 160) + 124);  // @111_4ec040
  ecx = (u32)((EBP - 160) + 72);  // @112_4ec040
  eax = ext_446ee0_fastcall3(ecx, edx, PV[5]);  // @113_4ec040
  ecx = edx = 0;  // @114_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 68) + 0), 4); v; });  // @115_4ec040
  X0[1] = 0;  // @116_4ec040
  X0[2] = 0;  // @117_4ec040
  X0[3] = 0;  // @118_4ec040
  eax = (u32)((EBP - 156) + 68);  // @119_4ec040
  X1[0] = 0;  // @120_4ec040
  X1[1] = 0;  // @121_4ec040
  X1[2] = 0;  // @122_4ec040
  X1[3] = 0;  // @123_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 156) + 16), &v, sizeof v); }  // @124_4ec040
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @125_4ec040
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @126_4ec040
  if (!__builtin_parity(FL[2] & 0xff)) goto L4ec1e3;  // @127_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 72) + 0), 4); v; });  // @128_4ec040
  X0[1] = 0;  // @129_4ec040
  X0[2] = 0;  // @130_4ec040
  X0[3] = 0;  // @131_4ec040
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @132_4ec040
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @133_4ec040
  if (!__builtin_parity(FL[2] & 0xff)) goto L4ec1e3;  // @134_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 76) + 0), 4); v; });  // @135_4ec040
  X0[1] = 0;  // @136_4ec040
  X0[2] = 0;  // @137_4ec040
  X0[3] = 0;  // @138_4ec040
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @139_4ec040
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @140_4ec040
  if (__builtin_parity(FL[2] & 0xff)) goto L4ec223;  // @141_4ec040
  L4ec1e3:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 156) + 12), &v, sizeof v); }  // @143_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 16), sizeof v); (u32)v; });  // @144_4ec040
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @145_4ec040
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @146_4ec040
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @147_4ec040
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @148_4ec040
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @149_4ec040
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @150_4ec040
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @151_4ec040
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @152_4ec040
  __asm__ volatile("fsqrt" ::: "st");  // @153_4ec040
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 156) + 12)) : "st");  // @154_4ec040
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @155_4ec040
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @156_4ec040
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @157_4ec040
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @158_4ec040
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @159_4ec040
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @160_4ec040
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @161_4ec040
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @162_4ec040
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @163_4ec040
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @164_4ec040
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 156) + 12)) :: "st");  // @165_4ec040
  L4ec223:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 28), sizeof v); (u32)v; });  // @167_4ec040
  edx = (u32)((EBP - 156) + 144);  // @168_4ec040
  ecx = (u32)((EBP - 156) + 108);  // @169_4ec040
  eax = (u32)(esi + 36);  // @170_4ec040
  PV[6] = (u32)(eax);  // @171_4ec040
  eax = ext_43e920_fastcall3(ecx, edx, PV[6]);  // @172_4ec040
  ecx = edx = 0;  // @173_4ec040
  edx = esi;  // @174_4ec040
  ecx = (u32)((EBP - 156) + 108);  // @175_4ec040
  eax = ext_441a60_fastcall2(ecx, edx);  // @176_4ec040
  ecx = edx = 0;  // @177_4ec040
  eax = (u32)(esi + 48);  // @178_4ec040
  PV[7] = (u32)(eax);  // @179_4ec040
  edx = (u32)((EBP - 160) + 112);  // @180_4ec040
  ecx = (u32)((EBP - 160) + 48);  // @181_4ec040
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @182_4ec040
  ecx = edx = 0;  // @183_4ec040
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 72) + 0), 4); v; });  // @184_4ec040
  X1[1] = 0;  // @185_4ec040
  X1[2] = 0;  // @186_4ec040
  X1[3] = 0;  // @187_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 44) + 0), 4); v; });  // @188_4ec040
  X0[1] = 0;  // @189_4ec040
  X0[2] = 0;  // @190_4ec040
  X0[3] = 0;  // @191_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 68) + 0), 4); v; })));  // @192_4ec040
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 48) + 0), 4); v; })));  // @193_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @194_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 52) + 0), 4); v; });  // @195_4ec040
  X0[1] = 0;  // @196_4ec040
  X0[2] = 0;  // @197_4ec040
  X0[3] = 0;  // @198_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 76) + 0), 4); v; })));  // @199_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @200_4ec040
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @201_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 156) + 84) + 0), &X1[0], 4);  // @202_4ec040
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @203_4ec040
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @204_4ec040
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @205_4ec040
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @206_4ec040
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6912136) + 0), 4); v; }); X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6912136) + 4), 4); v; }); X1[2] = X1[3] = 0;  // @207_4ec040
  if (((!(U2D(X1[0], X1[1]) >= U2D(X0[0], X0[1]))) || (!((U2D(X1[0], X1[1]) < U2D(X0[0], X0[1])) || (U2D(X1[0], X1[1]) > U2D(X0[0], X0[1])))))) goto L4ec5b6;  // @208_4ec040
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 120) + 0), 4); v; });  // @209_4ec040
  X1[1] = 0;  // @210_4ec040
  X1[2] = 0;  // @211_4ec040
  X1[3] = 0;  // @212_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 124) + 0), 4); v; });  // @213_4ec040
  X0[1] = 0;  // @214_4ec040
  X0[2] = 0;  // @215_4ec040
  X0[3] = 0;  // @216_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @217_4ec040
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @218_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @219_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 128) + 0), 4); v; });  // @220_4ec040
  X0[1] = 0;  // @221_4ec040
  X0[2] = 0;  // @222_4ec040
  X0[3] = 0;  // @223_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @224_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @225_4ec040
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @226_4ec040
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @227_4ec040
  ecx = edx = 0;  // @228_4ec040
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @229_4ec040
  X1[1] = 0;  // @230_4ec040
  X1[2] = 0;  // @231_4ec040
  X1[3] = 0;  // @232_4ec040
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @233_4ec040
  PV[8] = (u32)(ecx);  // @234_4ec040
  ecx = (u32)((EBP - 160) + 124);  // @235_4ec040
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @236_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 160) + 20) + 0), &X0[0], 4);  // @237_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 160) + 32) + 0), &X1[0], 4);  // @238_4ec040
  PV[9] = X1[0];  // @239_4ec040
  eax = ext_4e0d00_thiscall2(ecx, PV[9]);  // @240_4ec040
    // @241_4ec040
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 120) + 0), 4); v; });  // @242_4ec040
  X1[1] = 0;  // @243_4ec040
  X1[2] = 0;  // @244_4ec040
  X1[3] = 0;  // @245_4ec040
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 44) + 0), 4); v; })));  // @246_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 124) + 0), 4); v; });  // @247_4ec040
  X0[1] = 0;  // @248_4ec040
  X0[2] = 0;  // @249_4ec040
  X0[3] = 0;  // @250_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 48) + 0), 4); v; })));  // @251_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @252_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 128) + 0), 4); v; });  // @253_4ec040
  X0[1] = 0;  // @254_4ec040
  X0[2] = 0;  // @255_4ec040
  X0[3] = 0;  // @256_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 52) + 0), 4); v; })));  // @257_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @258_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 16) + 0), 4); v; });  // @259_4ec040
  X0[1] = 0;  // @260_4ec040
  X0[2] = 0;  // @261_4ec040
  X0[3] = 0;  // @262_4ec040
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @263_4ec040
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @264_4ec040
  X1[0] = X1[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @265_4ec040
  X1[1] = X1[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @266_4ec040
  X1[2] = X1[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @267_4ec040
  X1[3] = X1[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @268_4ec040
  SD(&X1[0], U2D(X1[0], X1[1]) - U2D(X0[0], X0[1]));  // @269_4ec040
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @270_4ec040
  X1[0] = 0;  // @271_4ec040
  X1[1] = 0;  // @272_4ec040
  X1[2] = 0;  // @273_4ec040
  X1[3] = 0;  // @274_4ec040
  { float a_ = U2F(X1[0]), b_ = U2F(X0[0]); X1[0] = (a_ > b_) ? X1[0] : F2U(b_); }  // @275_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836848) + 0), 4); v; });  // @276_4ec040
  X0[1] = 0;  // @277_4ec040
  X0[2] = 0;  // @278_4ec040
  X0[3] = 0;  // @279_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 156) + 12) + 0), &X1[0], 4);  // @280_4ec040
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4ec5b6;  // @281_4ec040
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 132) + 0), 4); v; });  // @282_4ec040
  X1[1] = 0;  // @283_4ec040
  X1[2] = 0;  // @284_4ec040
  X1[3] = 0;  // @285_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 136) + 0), 4); v; });  // @286_4ec040
  X0[1] = 0;  // @287_4ec040
  X0[2] = 0;  // @288_4ec040
  X0[3] = 0;  // @289_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @290_4ec040
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @291_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @292_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 140) + 0), 4); v; });  // @293_4ec040
  X0[1] = 0;  // @294_4ec040
  X0[2] = 0;  // @295_4ec040
  X0[3] = 0;  // @296_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @297_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @298_4ec040
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @299_4ec040
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @300_4ec040
  ecx = edx = 0;  // @301_4ec040
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @302_4ec040
  PV[10] = (u32)(ecx);  // @303_4ec040
  ecx = (u32)((EBP - 160) + 136);  // @304_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 160) + 20) + 0), &X0[0], 4);  // @305_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 160) + 32) + 0), 4); v; });  // @306_4ec040
  X0[1] = 0;  // @307_4ec040
  X0[2] = 0;  // @308_4ec040
  X0[3] = 0;  // @309_4ec040
  PV[11] = X0[0];  // @310_4ec040
  eax = ext_4e0d00_thiscall2(ecx, PV[11]);  // @311_4ec040
    // @312_4ec040
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 132) + 0), 4); v; });  // @313_4ec040
  X1[1] = 0;  // @314_4ec040
  X1[2] = 0;  // @315_4ec040
  X1[3] = 0;  // @316_4ec040
  X4[0] = 0;  // @317_4ec040
  X4[1] = 0;  // @318_4ec040
  X4[2] = 0;  // @319_4ec040
  X4[3] = 0;  // @320_4ec040
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 44) + 0), 4); v; })));  // @321_4ec040
  X3[0] = X4[0];  // @322_4ec040
  X3[1] = X4[1];  // @323_4ec040
  X3[2] = X4[2];  // @324_4ec040
  X3[3] = X4[3];  // @325_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 136) + 0), 4); v; });  // @326_4ec040
  X0[1] = 0;  // @327_4ec040
  X0[2] = 0;  // @328_4ec040
  X0[3] = 0;  // @329_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 48) + 0), 4); v; })));  // @330_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @331_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 140) + 0), 4); v; });  // @332_4ec040
  X0[1] = 0;  // @333_4ec040
  X0[2] = 0;  // @334_4ec040
  X0[3] = 0;  // @335_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 52) + 0), 4); v; })));  // @336_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @337_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 16) + 0), 4); v; });  // @338_4ec040
  X0[1] = 0;  // @339_4ec040
  X0[2] = 0;  // @340_4ec040
  X0[3] = 0;  // @341_4ec040
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @342_4ec040
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @343_4ec040
  X1[0] = X1[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @344_4ec040
  X1[1] = X1[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @345_4ec040
  X1[2] = X1[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @346_4ec040
  X1[3] = X1[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @347_4ec040
  SD(&X1[0], U2D(X1[0], X1[1]) - U2D(X0[0], X0[1]));  // @348_4ec040
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @349_4ec040
  { float a_ = U2F(X3[0]), b_ = U2F(X0[0]); X3[0] = (a_ > b_) ? X3[0] : F2U(b_); }  // @350_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836848) + 0), 4); v; });  // @351_4ec040
  X0[1] = 0;  // @352_4ec040
  X0[2] = 0;  // @353_4ec040
  X0[3] = 0;  // @354_4ec040
  if (((!(U2F(X0[0]) >= U2F(X3[0]))) || (!((U2F(X0[0]) < U2F(X3[0])) || (U2F(X0[0]) > U2F(X3[0])))))) goto L4ec5b6;  // @355_4ec040
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 84) + 0), 4); v; });  // @356_4ec040
  X2[1] = 0;  // @357_4ec040
  X2[2] = 0;  // @358_4ec040
  X2[3] = 0;  // @359_4ec040
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6912128) + 0), 4); v; })));  // @360_4ec040
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 12) + 0), 4); v; });  // @361_4ec040
  X1[1] = 0;  // @362_4ec040
  X1[2] = 0;  // @363_4ec040
  X1[3] = 0;  // @364_4ec040
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6840448) + 0), 4); v; })));  // @365_4ec040
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6840448) + 0), 4); v; })));  // @366_4ec040
  X0[0] = X2[0];  // @367_4ec040
  X0[1] = X2[1];  // @368_4ec040
  X0[2] = X2[2];  // @369_4ec040
  X0[3] = X2[3];  // @370_4ec040
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @371_4ec040
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @372_4ec040
  X3[0] = F2U(U2F(X3[0]) * U2F(X3[0]));  // @373_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @374_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @375_4ec040
  X0[1] = 0;  // @376_4ec040
  X0[2] = 0;  // @377_4ec040
  X0[3] = 0;  // @378_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X3[0]));  // @379_4ec040
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @380_4ec040
  if (((!(U2F(X4[0]) >= U2F(X2[0]))) || (!((U2F(X4[0]) < U2F(X2[0])) || (U2F(X4[0]) > U2F(X2[0])))))) goto L4ec480;  // @381_4ec040
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @382_4ec040
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @383_4ec040
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @384_4ec040
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @385_4ec040
  L4ec480:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 64), sizeof v); (u32)v; });  // @387_4ec040
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @388_4ec040
  __builtin_memcpy((void *)((u32)((EBP - 156) + 12) + 0), &X1[0], 4);  // @389_4ec040
  FL[2] = (esi & esi);  // @390_4ec040
  if (FL[2] == 0) goto L4ec5b6;  // @391_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @392_4ec040
  ecx = (u32)((EBP - 156) + 96);  // @393_4ec040
  PV[12] = (u32)(ecx);  // @394_4ec040
  ecx = esi;  // @395_4ec040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[12]);  // @396_4ec040
  ecx = edx = 0;  // @397_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @398_4ec040
  ecx = (u32)((EBP - 156) + 96);  // @399_4ec040
  PV[13] = (u32)(ecx);  // @400_4ec040
  ecx = esi;  // @401_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @402_4ec040
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[13]);  // @403_4ec040
  ecx = edx = 0;  // @404_4ec040
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @405_4ec040
  edx = eax;  // @406_4ec040
  if (FL[0] == FL[1]) goto L4ec5b6;  // @407_4ec040
  L4ec4c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @409_4ec040
  PV[14] = (u32)(edx);  // @410_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @411_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @412_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @413_4ec040
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[14]);  // @414_4ec040
  ecx = edx = 0;  // @415_4ec040
  ecx = eax;  // @416_4ec040
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @417_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; });  // @418_4ec040
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @419_4ec040
  ecx = edx = 0;  // @420_4ec040
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @421_4ec040
  edx = (edx | (u32)(4294967295));  // @422_4ec040
  FL[3] = edx;  // @423_4ec040
  ecx = 0;  // @424_4ec040
  FL[3] = ecx;  // @425_4ec040
  L4ec4e5:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx*4), sizeof v); (u32)v; }); FL[1] = eax;  // @427_4ec040
  if (FL[0] == FL[1]) goto L4ec4f1;  // @428_4ec040
  ecx = (ecx + 1);  // @429_4ec040
  FL[3] = ecx;  // @430_4ec040
  FL[0] = ecx; FL[1] = esi;  // @431_4ec040
  if (FL[0] != FL[1]) goto L4ec4e5;  // @432_4ec040
  goto L4ec4f3;  // @433_4ec040
  L4ec4f1:;
  edx = ecx;  // @435_4ec040
  L4ec4f3:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 156) + 12) + 0), 4); v; });  // @437_4ec040
  X1[1] = 0;  // @438_4ec040
  X1[2] = 0;  // @439_4ec040
  X1[3] = 0;  // @440_4ec040
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @441_4ec040
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @442_4ec040
  if (__builtin_parity(FL[2] & 0xff)) goto L4ec599;  // @443_4ec040
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 60), sizeof v); (u32)v; });  // @444_4ec040
  FL[2] = (esi & esi);  // @445_4ec040
  if (FL[2] == 0) goto L4ec538;  // @446_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 24), sizeof v); (u32)v; });  // @447_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @448_4ec040
  X0[1] = 0;  // @449_4ec040
  X0[2] = 0;  // @450_4ec040
  X0[3] = 0;  // @451_4ec040
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @452_4ec040
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @453_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @454_4ec040
  X0[1] = 0;  // @455_4ec040
  X0[2] = 0;  // @456_4ec040
  X0[3] = 0;  // @457_4ec040
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @458_4ec040
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + edx*4) + 0), 4); v; })));  // @459_4ec040
  __builtin_memcpy((void *)((u32)(esi + edx*4) + 0), &X0[0], 4);  // @460_4ec040
  L4ec538:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @462_4ec040
  X0[1] = 0;  // @463_4ec040
  X0[2] = 0;  // @464_4ec040
  X0[3] = 0;  // @465_4ec040
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4ec599;  // @466_4ec040
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 36), sizeof v); (u32)v; }); FL[1] = edx;  // @467_4ec040
  if (FL[0] >= FL[1]) goto L4ec599;  // @468_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 20), sizeof v); (u32)v; });  // @469_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 40), sizeof v); (u32)v; });  // @470_4ec040
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 20), sizeof v); (u32)v; });  // @471_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; });  // @472_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx*4), sizeof v); (u32)v; });  // @473_4ec040
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 40), sizeof v); (u32)v; });  // @474_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @475_4ec040
  eax = esi;  // @476_4ec040
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 56), sizeof v); (u32)v; });  // @477_4ec040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + edx*4), &v, sizeof v); }  // @478_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @479_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 32), sizeof v); (u32)v; });  // @480_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @481_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @482_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 32), sizeof v); (u32)v; });  // @483_4ec040
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 60), sizeof v); (u32)v; });  // @484_4ec040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + edx*4), &v, sizeof v); }  // @485_4ec040
  FL[2] = (esi & esi);  // @486_4ec040
  if (FL[2] == 0) goto L4ec599;  // @487_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 24), sizeof v); (u32)v; });  // @488_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*4), sizeof v); (u32)v; });  // @489_4ec040
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @490_4ec040
  X0[1] = 0;  // @491_4ec040
  X0[2] = 0;  // @492_4ec040
  X0[3] = 0;  // @493_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @494_4ec040
  __builtin_memcpy((void *)((u32)(esi + edx*4) + 0), &X0[0], 4);  // @495_4ec040
  L4ec599:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 64), sizeof v); (u32)v; });  // @497_4ec040
  edx = (u32)((EBP - 156) + 96);  // @498_4ec040
  PV[15] = (u32)(edx);  // @499_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @500_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @501_4ec040
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[15]);  // @502_4ec040
  ecx = edx = 0;  // @503_4ec040
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @504_4ec040
  edx = eax;  // @505_4ec040
  if (FL[0] != FL[1]) goto L4ec4c0;  // @506_4ec040
  L4ec5b6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 88), sizeof v); (u32)v; });  // @508_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @509_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 156) + 28), &v, sizeof v); }  // @510_4ec040
  FL[2] = (eax & eax);  // @511_4ec040
  if (FL[2] != 0) goto L4ec114;  // @512_4ec040
  L4ec5c8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 36), sizeof v); (u32)v; });  // @514_4ec040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 24), sizeof v); (u32)v; });  // @515_4ec040
  ecx = (ecx + 1);  // @516_4ec040
  FL[3] = ecx;  // @517_4ec040
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 92), sizeof v); (u32)v; });  // @518_4ec040
  eax = (eax + (u32)(4));  // @519_4ec040
  FL[3] = eax;  // @520_4ec040
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @521_4ec040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 156) + 36), &v, sizeof v); }  // @522_4ec040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 156) + 40), sizeof v); (u32)v; });  // @523_4ec040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 156) + 24), &v, sizeof v); }  // @524_4ec040
  if (FL[0] < FL[1]) goto L4ec0b7;  // @525_4ec040
  L4ec5ed:;
  ext_633654(G(u32, 0x6f5630));  // @527_4ec040
  return eax;  // @528_4ec040
}
PCREG(4ec040, lifted_4ec040);

