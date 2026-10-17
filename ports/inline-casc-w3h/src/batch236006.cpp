// batch236006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_4e0830_fastcall2(u32, u32) __asm__("ext_4e0830");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e0d80_thiscall2(u32, u32) __asm__("ext_4e0d80");
extern "C" u32 THISCALL ext_5cf690_thiscall2(u32, u32) __asm__("ext_5cf690");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5ce0b0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 xc_ = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5ce0b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 236) + 40), &v, sizeof v); }  // @1_5ce0b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @2_5ce0b0
  ecx = edi;  // @3_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @4_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 236) + 48), &v, sizeof v); }  // @5_5ce0b0
  eax = (eax & (u32)(4294909440));  // @6_5ce0b0
  FL[3] = eax;  // @7_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @8_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @9_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1608)))(ecx, (u32)(0));  // @10_5ce0b0
  ecx = edx = 0;  // @11_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2855) + 0), 4); v; });  // @12_5ce0b0
  X0[1] = 0;  // @13_5ce0b0
  X0[2] = 0;  // @14_5ce0b0
  X0[3] = 0;  // @15_5ce0b0
  ebx = (u32)(esi + 2873);  // @16_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2859), sizeof v); (u32)v; });  // @17_5ce0b0
  X1[0] = 0;  // @18_5ce0b0
  X1[1] = 0;  // @19_5ce0b0
  X1[2] = 0;  // @20_5ce0b0
  X1[3] = 0;  // @21_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @22_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @23_5ce0b0
  __builtin_memcpy((void *)((u32)(ebx + 8) + 0), &X0[0], 4);  // @24_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @25_5ce0b0
  X0[1] = 0;  // @26_5ce0b0
  X0[2] = 0;  // @27_5ce0b0
  X0[3] = 0;  // @28_5ce0b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 232) + 40), &v, sizeof v); }  // @29_5ce0b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 232) + 20), &v, sizeof v); }  // @30_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @31_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @32_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce14d;  // @33_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @34_5ce0b0
  X0[1] = 0;  // @35_5ce0b0
  X0[2] = 0;  // @36_5ce0b0
  X0[3] = 0;  // @37_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @38_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @39_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce14d;  // @40_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @41_5ce0b0
  X0[1] = 0;  // @42_5ce0b0
  X0[2] = 0;  // @43_5ce0b0
  X0[3] = 0;  // @44_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @45_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @46_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce193;  // @47_5ce0b0
  L5ce14d:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 232) + 16), &v, sizeof v); }  // @49_5ce0b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 20), sizeof v); (u32)v; });  // @50_5ce0b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @51_5ce0b0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @52_5ce0b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @53_5ce0b0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @54_5ce0b0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @55_5ce0b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @56_5ce0b0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @57_5ce0b0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @58_5ce0b0
  __asm__ volatile("fsqrt" ::: "st");  // @59_5ce0b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 232) + 16)) : "st");  // @60_5ce0b0
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @61_5ce0b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @62_5ce0b0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @63_5ce0b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @64_5ce0b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @65_5ce0b0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @66_5ce0b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @67_5ce0b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @68_5ce0b0
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @69_5ce0b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @70_5ce0b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 232) + 16)) :: "st");  // @71_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; });  // @72_5ce0b0
  X1[1] = 0;  // @73_5ce0b0
  X1[2] = 0;  // @74_5ce0b0
  X1[3] = 0;  // @75_5ce0b0
  L5ce193:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @77_5ce0b0
  __builtin_memcpy((void *)((u32)(esi + 2869) + 0), &X1[0], 4);  // @78_5ce0b0
  if (FL[0] == FL[1]) goto L5ce1c3;  // @79_5ce0b0
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; }))))))) goto L5ce1b9;  // @80_5ce0b0
  { u32 v = (u32)((u32)(1050253722)); __builtin_memcpy((void *)(u32)(esi + 2869), &v, sizeof v); }  // @81_5ce0b0
  goto L5ce1c3;  // @82_5ce0b0
  L5ce1b9:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2869), &v, sizeof v); }  // @84_5ce0b0
  L5ce1c3:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2841), &v, sizeof v); }  // @86_5ce0b0
  ecx = edi;  // @87_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1232), sizeof v); (u32)v; });  // @89_5ce0b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @90_5ce0b0
  ecx = edx = 0;  // @91_5ce0b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @92_5ce0b0
  if (FL[2] != 0) goto L5ce1ff;  // @93_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @94_5ce0b0
  ecx = edi;  // @95_5ce0b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1008)))(ecx);  // @96_5ce0b0
  ecx = edx = 0;  // @97_5ce0b0
  FL[0] = eax; FL[1] = (u32)(17);  // @98_5ce0b0
  if (FL[0] == FL[1]) goto L5ce1ff;  // @99_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @100_5ce0b0
  if (FL[0] != FL[1]) goto L5ce1ff;  // @101_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2382), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @102_5ce0b0
  if (FL[0] != FL[1]) goto L5ce1ff;  // @103_5ce0b0
  ecx = (ecx & 0xffffff00u) | ((0) & 0xff);  // @104_5ce0b0
  FL[3] = (ecx & 0xff);  // @105_5ce0b0
  goto L5ce201;  // @106_5ce0b0
  L5ce1ff:;
  ecx = (ecx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @108_5ce0b0
  L5ce201:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1536), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @110_5ce0b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)((EBP - 232) + 15), &v, sizeof v); }  // @111_5ce0b0
  if (FL[0] == FL[1]) goto L5ceb19;  // @112_5ce0b0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(512));  // @113_5ce0b0
  if (FL[2] != 0) goto L5ceb19;  // @114_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1647), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @115_5ce0b0
  if (FL[0] == FL[1]) goto L5ce249;  // @116_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2869), &v, sizeof v); }  // @117_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @118_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @119_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @120_5ce0b0
  L5ce249:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @122_5ce0b0
  X0[1] = 0;  // @123_5ce0b0
  X0[2] = 0;  // @124_5ce0b0
  X0[3] = 0;  // @125_5ce0b0
  X1[0] = 0;  // @126_5ce0b0
  X1[1] = 0;  // @127_5ce0b0
  X1[2] = 0;  // @128_5ce0b0
  X1[3] = 0;  // @129_5ce0b0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5ce2fd;  // @130_5ce0b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2841), &v, sizeof v); }  // @131_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2059) + 0), 4); v; });  // @132_5ce0b0
  X0[1] = 0;  // @133_5ce0b0
  X0[2] = 0;  // @134_5ce0b0
  X0[3] = 0;  // @135_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @136_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @137_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce292;  // @138_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @139_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @140_5ce0b0
  X0[0] = F2U((float)(s32)X0[0]);  // @141_5ce0b0
  X0[1] = F2U((float)(s32)X0[1]);  // @142_5ce0b0
  X0[2] = F2U((float)(s32)X0[2]);  // @143_5ce0b0
  X0[3] = F2U((float)(s32)X0[3]);  // @144_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @145_5ce0b0
  __builtin_memcpy((void *)((u32)(edi + 2059) + 0), &X0[0], 4);  // @146_5ce0b0
  L5ce292:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @148_5ce0b0
  X0[1] = 0;  // @149_5ce0b0
  X0[2] = 0;  // @150_5ce0b0
  X0[3] = 0;  // @151_5ce0b0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; }))))))) goto L5ce2bb;  // @152_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @153_5ce0b0
  FL[2] = (eax & (u32)(67108864));  // @154_5ce0b0
  if (FL[2] != 0) goto L5ce2bb;  // @155_5ce0b0
  eax = (eax | (u32)(2));  // @156_5ce0b0
  FL[3] = eax;  // @157_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @158_5ce0b0
  goto L5ce2c2;  // @159_5ce0b0
  L5ce2bb:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @161_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @162_5ce0b0
  L5ce2c2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @164_5ce0b0
  X0[1] = 0;  // @165_5ce0b0
  X0[2] = 0;  // @166_5ce0b0
  X0[3] = 0;  // @167_5ce0b0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }))))))) goto L5ce2de;  // @168_5ce0b0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @169_5ce0b0
  if (FL[2] == 0) goto L5ce2de;  // @170_5ce0b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @171_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @172_5ce0b0
  L5ce2de:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @174_5ce0b0
  FL[2] = (eax & (u32)(4194304));  // @175_5ce0b0
  if (FL[2] == 0) goto L5ce2fd;  // @176_5ce0b0
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }))))))) goto L5ce2fd;  // @177_5ce0b0
  eax = (eax | (u32)(4));  // @178_5ce0b0
  FL[3] = eax;  // @179_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @180_5ce0b0
  L5ce2fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @182_5ce0b0
  ecx = (u32)((EBP - 232) + 72);  // @183_5ce0b0
  PV[0] = (u32)(ecx);  // @184_5ce0b0
  ecx = (u32)((EBP - 236) + 100);  // @185_5ce0b0
  PV[1] = (u32)(ecx);  // @186_5ce0b0
  ecx = edi;  // @187_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[1], PV[0]);  // @188_5ce0b0
  ecx = edx = 0;  // @189_5ce0b0
  ecx = (u32)((EBP - 232) + 96);  // @190_5ce0b0
  eax = ext_4e09b0_thiscall1(ecx);  // @191_5ce0b0
    // @192_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @193_5ce0b0
  ecx = (u32)((EBP - 232) + 180);  // @194_5ce0b0
  PV[2] = (u32)(ecx);  // @195_5ce0b0
  ecx = (u32)((EBP - 236) + 136);  // @196_5ce0b0
  PV[3] = (u32)(ecx);  // @197_5ce0b0
  ecx = esi;  // @198_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[3], PV[2]);  // @199_5ce0b0
  ecx = edx = 0;  // @200_5ce0b0
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 2833), &v, sizeof v); }  // @201_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @202_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 48), &v, sizeof v); }  // @203_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 52), &v, sizeof v); }  // @204_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 56), &v, sizeof v); }  // @205_5ce0b0
  FL[2] = (eax & (u32)(268435456));  // @206_5ce0b0
  if (FL[2] == 0) goto L5ce6c0;  // @207_5ce0b0
  FL[2] = ((eax & 0xff) & (u32)(2));  // @208_5ce0b0
  if (FL[2] == 0) goto L5ce377;  // @209_5ce0b0
  eax = (eax & (u32)(4294967293));  // @210_5ce0b0
  FL[3] = eax;  // @211_5ce0b0
  eax = (eax | (u32)(1));  // @212_5ce0b0
  FL[3] = eax;  // @213_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @214_5ce0b0
  L5ce377:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @216_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @217_5ce0b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @218_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @219_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @220_5ce0b0
  ecx = edx = 0;  // @221_5ce0b0
  ecx = eax;  // @222_5ce0b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @223_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 256)))(ecx, (u32)(6970608));  // @224_5ce0b0
  ecx = edx = 0;  // @225_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 232) + 16), &v, sizeof v); }  // @226_5ce0b0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)((EBP - 232) + 20), &v, sizeof v); }  // @227_5ce0b0
  FL[2] = (eax & eax);  // @228_5ce0b0
  if (FL[2] == 0) goto L5ce513;  // @229_5ce0b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @230_5ce0b0
  ecx = (u32)((EBP - 232) + 20);  // @231_5ce0b0
  PV[4] = (u32)(ecx);  // @232_5ce0b0
  PV[5] = (u32)(ecx);  // @233_5ce0b0
  ecx = (u32)((EBP - 244) + 84);  // @234_5ce0b0
  PV[6] = (u32)(ecx);  // @235_5ce0b0
  ecx = eax;  // @236_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[6], (u32)(1140457472), PV[4], (u32)(-1));  // @237_5ce0b0
  ecx = edx = 0;  // @238_5ce0b0
  ebx = eax;  // @239_5ce0b0
  FL[2] = (ebx & ebx);  // @240_5ce0b0
  if (FL[2] == 0) goto L5ce50d;  // @241_5ce0b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 16), sizeof v); (u32)v; });  // @242_5ce0b0
  L5ce3e6:;
  FL[0] = ebx; FL[1] = edi;  // @244_5ce0b0
  if (FL[0] == FL[1]) goto L5ce4db;  // @245_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @246_5ce0b0
  ecx = ebx;  // @247_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @248_5ce0b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @249_5ce0b0
  ecx = edx = 0;  // @250_5ce0b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @251_5ce0b0
  if (FL[2] != 0) goto L5ce4db;  // @252_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @253_5ce0b0
  ecx = (u32)((EBP - 232) + 60);  // @254_5ce0b0
  PV[7] = (u32)(ecx);  // @255_5ce0b0
  ecx = ebx;  // @256_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 236) + 64), &v, sizeof v); }  // @257_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 236) + 68), &v, sizeof v); }  // @258_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 236) + 72), &v, sizeof v); }  // @259_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[7]);  // @260_5ce0b0
  ecx = edx = 0;  // @261_5ce0b0
  edx = (u32)((EBP - 232) + 60);  // @262_5ce0b0
  ecx = (u32)((EBP - 232) + 72);  // @263_5ce0b0
  eax = ext_4e0830_fastcall2(ecx, edx);  // @264_5ce0b0
  ecx = edx = 0;  // @265_5ce0b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 232) + 16)) :: "st");  // @266_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; });  // @267_5ce0b0
  X0[1] = 0;  // @268_5ce0b0
  X0[2] = 0;  // @269_5ce0b0
  X0[3] = 0;  // @270_5ce0b0
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7032776) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7032776) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7032776) + 0), 4); v; }))))))) goto L5ce4db;  // @271_5ce0b0
  eax = (u32)((EBP - 232) + 72);  // @272_5ce0b0
  PV[8] = (u32)(eax);  // @273_5ce0b0
  edx = (u32)((EBP - 236) + 64);  // @274_5ce0b0
  ecx = (u32)((EBP - 236) + 28);  // @275_5ce0b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @276_5ce0b0
  ecx = edx = 0;  // @277_5ce0b0
  ecx = (u32)((EBP - 232) + 24);  // @278_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @279_5ce0b0
  ecx = 0;  // @280_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 100) + 0), 4); v; });  // @281_5ce0b0
  X0[1] = 0;  // @282_5ce0b0
  X0[2] = 0;  // @283_5ce0b0
  X0[3] = 0;  // @284_5ce0b0
  eax = (u32)((EBP - 232) + 96);  // @285_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 96) + 0), 4); v; });  // @286_5ce0b0
  X1[1] = 0;  // @287_5ce0b0
  X1[2] = 0;  // @288_5ce0b0
  X1[3] = 0;  // @289_5ce0b0
  edx = (u32)((EBP - 232) + 24);  // @290_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 28) + 0), 4); v; })));  // @291_5ce0b0
  ecx = (u32)((EBP - 232) + 84);  // @292_5ce0b0
  PV[9] = (u32)(eax);  // @293_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 236) + 28) + 0), 4); v; })));  // @294_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @295_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @296_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 236) + 108) + 0), 4); v; });  // @297_5ce0b0
  X0[1] = 0;  // @298_5ce0b0
  X0[2] = 0;  // @299_5ce0b0
  X0[3] = 0;  // @300_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 236) + 36) + 0), 4); v; })));  // @301_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @302_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 236) + 20) + 0), &X1[0], 4);  // @303_5ce0b0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[9]);  // @304_5ce0b0
  ecx = edx = 0;  // @305_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; });  // @306_5ce0b0
  X1[1] = 0;  // @307_5ce0b0
  X1[2] = 0;  // @308_5ce0b0
  X1[3] = 0;  // @309_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @310_5ce0b0
  X0[1] = 0;  // @311_5ce0b0
  X0[2] = 0;  // @312_5ce0b0
  X0[3] = 0;  // @313_5ce0b0
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5ce4db;  // @314_5ce0b0
  X0[0] = 0;  // @315_5ce0b0
  X0[1] = 0;  // @316_5ce0b0
  X0[2] = 0;  // @317_5ce0b0
  X0[3] = 0;  // @318_5ce0b0
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5ce4db;  // @319_5ce0b0
  eax = (u32)((EBP - 232) + 72);  // @320_5ce0b0
  PV[10] = (u32)(eax);  // @321_5ce0b0
  edx = (u32)((EBP - 236) + 64);  // @322_5ce0b0
  ecx = (u32)((EBP - 236) + 52);  // @323_5ce0b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[10]);  // @324_5ce0b0
  ecx = edx = 0;  // @325_5ce0b0
  L5ce4db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @327_5ce0b0
  ecx = (u32)((EBP - 232) + 20);  // @328_5ce0b0
  PV[11] = (u32)(ecx);  // @329_5ce0b0
  PV[12] = (u32)(ecx);  // @330_5ce0b0
  ecx = (u32)((EBP - 244) + 84);  // @331_5ce0b0
  PV[13] = (u32)(ecx);  // @332_5ce0b0
  ecx = esi;  // @333_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[13], (u32)(1140457472), PV[11], (u32)(-1));  // @334_5ce0b0
  ecx = edx = 0;  // @335_5ce0b0
  ebx = eax;  // @336_5ce0b0
  FL[2] = (ebx & ebx);  // @337_5ce0b0
  if (FL[2] != 0) goto L5ce3e6;  // @338_5ce0b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 36), sizeof v); (u32)v; });  // @339_5ce0b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 40), sizeof v); (u32)v; });  // @340_5ce0b0
  goto L5ce513;  // @341_5ce0b0
  L5ce50d:;
  ebx = (u32)(esi + 2873);  // @343_5ce0b0
  L5ce513:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @345_5ce0b0
  X0[1] = 0;  // @346_5ce0b0
  X0[2] = 0;  // @347_5ce0b0
  X0[3] = 0;  // @348_5ce0b0
  X1[0] = 0;  // @349_5ce0b0
  X1[1] = 0;  // @350_5ce0b0
  X1[2] = 0;  // @351_5ce0b0
  X1[3] = 0;  // @352_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @353_5ce0b0
  X3[1] = 0;  // @354_5ce0b0
  X3[2] = 0;  // @355_5ce0b0
  X3[3] = 0;  // @356_5ce0b0
  xc_ = X0[0];   // w3h hand fix: ucomiss xmm0(x),xmm1 is evaluated by the later lahf, after xmm0 was reloaded with y
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @357_5ce0b0
  X0[1] = 0;  // @358_5ce0b0
  X0[2] = 0;  // @359_5ce0b0
  X0[3] = 0;  // @360_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(xc_) >= U2F(X1[0])) ? 1 : 0) | (((U2F(xc_) != U2F(xc_)) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(xc_) < U2F(X1[0])) || (U2F(xc_) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @361_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(xc_) >= U2F(X1[0])) ? 1 : 0) | (((U2F(xc_) != U2F(xc_)) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(xc_) < U2F(X1[0])) || (U2F(xc_) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @362_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce543;  // @363_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @364_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @365_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce543;  // @366_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @367_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @368_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce586;  // @369_5ce0b0
  L5ce543:;
  X1[0] = X0[0];  // @371_5ce0b0
  X1[1] = X0[1];  // @372_5ce0b0
  X1[2] = X0[2];  // @373_5ce0b0
  X1[3] = X0[3];  // @374_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @375_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @376_5ce0b0
  X0[1] = 0;  // @377_5ce0b0
  X0[2] = 0;  // @378_5ce0b0
  X0[3] = 0;  // @379_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @380_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @381_5ce0b0
  X0[0] = X3[0];  // @382_5ce0b0
  X0[1] = X3[1];  // @383_5ce0b0
  X0[2] = X3[2];  // @384_5ce0b0
  X0[3] = X3[3];  // @385_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @386_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @387_5ce0b0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @388_5ce0b0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @389_5ce0b0
  ecx = edx = 0;  // @390_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @391_5ce0b0
  X3[1] = 0;  // @392_5ce0b0
  X3[2] = 0;  // @393_5ce0b0
  X3[3] = 0;  // @394_5ce0b0
  X1[0] = 0;  // @395_5ce0b0
  X1[1] = 0;  // @396_5ce0b0
  X1[2] = 0;  // @397_5ce0b0
  X1[3] = 0;  // @398_5ce0b0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @399_5ce0b0
  __builtin_memcpy((void *)((u32)(esi + 2833) + 0), &X0[0], 4);  // @400_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @401_5ce0b0
  X0[1] = 0;  // @402_5ce0b0
  X0[2] = 0;  // @403_5ce0b0
  X0[3] = 0;  // @404_5ce0b0
  L5ce586:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @406_5ce0b0
  X2[1] = 0;  // @407_5ce0b0
  X2[2] = 0;  // @408_5ce0b0
  X2[3] = 0;  // @409_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @410_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @411_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce5ab;  // @412_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @413_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @414_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce5ab;  // @415_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @416_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @417_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce691;  // @418_5ce0b0
  L5ce5ab:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @420_5ce0b0
  X0[1] = 0;  // @421_5ce0b0
  X0[2] = 0;  // @422_5ce0b0
  X0[3] = 0;  // @423_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @424_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @425_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce68b;  // @426_5ce0b0
  eax = (u32)((EBP - 232) + 132);  // @427_5ce0b0
  edx = ebx;  // @428_5ce0b0
  PV[14] = (u32)(eax);  // @429_5ce0b0
  ecx = (u32)((EBP - 236) + 64);  // @430_5ce0b0
  eax = ext_441970_fastcall3(ecx, edx, PV[14]);  // @431_5ce0b0
  ecx = edx = 0;  // @432_5ce0b0
  ecx = (u32)((EBP - 232) + 60);  // @433_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 64), &v, sizeof v); }  // @434_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @435_5ce0b0
  ecx = 0;  // @436_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @437_5ce0b0
  ecx = (u32)((EBP - 232) + 48);  // @438_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @439_5ce0b0
  ecx = 0;  // @440_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 60) + 0), 4); v; });  // @441_5ce0b0
  X0[1] = 0;  // @442_5ce0b0
  X0[2] = 0;  // @443_5ce0b0
  X0[3] = 0;  // @444_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @445_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 64) + 0), 4); v; });  // @446_5ce0b0
  X1[1] = 0;  // @447_5ce0b0
  X1[2] = 0;  // @448_5ce0b0
  X1[3] = 0;  // @449_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; })));  // @450_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; })));  // @451_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @452_5ce0b0
  X3[1] = 0;  // @453_5ce0b0
  X3[2] = 0;  // @454_5ce0b0
  X3[3] = 0;  // @455_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @456_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 68) + 0), 4); v; });  // @457_5ce0b0
  X0[1] = 0;  // @458_5ce0b0
  X0[2] = 0;  // @459_5ce0b0
  X0[3] = 0;  // @460_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @461_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @462_5ce0b0
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000568) + 0), 4); v; })))) && !(!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000568) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000568) + 0), 4); v; }))))))) goto L5ce67a;  // @463_5ce0b0
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000624) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000624) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000624) + 0), 4); v; }))))))) goto L5ce673;  // @464_5ce0b0
  eax = (u32)((EBP - 232) + 48);  // @465_5ce0b0
  PV[15] = (u32)(eax);  // @466_5ce0b0
  edx = (u32)((EBP - 236) + 64);  // @467_5ce0b0
  ecx = (u32)((EBP - 236) + 88);  // @468_5ce0b0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[15]);  // @469_5ce0b0
  ecx = edx = 0;  // @470_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @471_5ce0b0
  X0[1] = 0;  // @472_5ce0b0
  X0[2] = 0;  // @473_5ce0b0
  X0[3] = 0;  // @474_5ce0b0
  X1[0] = 0;  // @475_5ce0b0
  X1[1] = 0;  // @476_5ce0b0
  X1[2] = 0;  // @477_5ce0b0
  X1[3] = 0;  // @478_5ce0b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @479_5ce0b0
  X2[1] = 0;  // @480_5ce0b0
  X2[2] = 0;  // @481_5ce0b0
  X2[3] = 0;  // @482_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @483_5ce0b0
  X3[1] = 0;  // @484_5ce0b0
  X3[2] = 0;  // @485_5ce0b0
  X3[3] = 0;  // @486_5ce0b0
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 88) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 88) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 88) + 0), 4); v; }))))))) goto L5ce66a;  // @487_5ce0b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(16))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @488_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @489_5ce0b0
  goto L5ce697;  // @490_5ce0b0
  L5ce66a:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @492_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @493_5ce0b0
  goto L5ce697;  // @494_5ce0b0
  L5ce673:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @496_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @497_5ce0b0
  L5ce67a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @499_5ce0b0
  X0[1] = 0;  // @500_5ce0b0
  X0[2] = 0;  // @501_5ce0b0
  X0[3] = 0;  // @502_5ce0b0
  X1[0] = 0;  // @503_5ce0b0
  X1[1] = 0;  // @504_5ce0b0
  X1[2] = 0;  // @505_5ce0b0
  X1[3] = 0;  // @506_5ce0b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @507_5ce0b0
  X2[1] = 0;  // @508_5ce0b0
  X2[2] = 0;  // @509_5ce0b0
  X2[3] = 0;  // @510_5ce0b0
  goto L5ce697;  // @511_5ce0b0
  L5ce68b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @513_5ce0b0
  X0[1] = 0;  // @514_5ce0b0
  X0[2] = 0;  // @515_5ce0b0
  X0[3] = 0;  // @516_5ce0b0
  L5ce691:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @518_5ce0b0
  X3[1] = 0;  // @519_5ce0b0
  X3[2] = 0;  // @520_5ce0b0
  X3[3] = 0;  // @521_5ce0b0
  L5ce697:;
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @523_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @524_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce7f9;  // @525_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @526_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @527_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce7f9;  // @528_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @529_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @530_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce7f9;  // @531_5ce0b0
  goto L5ce6c3;  // @532_5ce0b0
  L5ce6c0:;
  X1[0] = 0;  // @534_5ce0b0
  X1[1] = 0;  // @535_5ce0b0
  X1[2] = 0;  // @536_5ce0b0
  X1[3] = 0;  // @537_5ce0b0
  L5ce6c3:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @539_5ce0b0
  X0[1] = 0;  // @540_5ce0b0
  X0[2] = 0;  // @541_5ce0b0
  X0[3] = 0;  // @542_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @543_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @544_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce73b;  // @545_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @546_5ce0b0
  if (FL[0] == FL[1]) goto L5ce6fa;  // @547_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 132) + 0), 4); v; });  // @548_5ce0b0
  X0[1] = 0;  // @549_5ce0b0
  X0[2] = 0;  // @550_5ce0b0
  X0[3] = 0;  // @551_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 48) + 0), &X0[0], 4);  // @552_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 140) + 0), 4); v; });  // @553_5ce0b0
  X0[1] = 0;  // @554_5ce0b0
  X0[2] = 0;  // @555_5ce0b0
  X0[3] = 0;  // @556_5ce0b0
  goto L5ce7f3;  // @557_5ce0b0
  L5ce6fa:;
  eax = (u32)((EBP - 232) + 132);  // @559_5ce0b0
  edx = ebx;  // @560_5ce0b0
  PV[16] = (u32)(eax);  // @561_5ce0b0
  ecx = (u32)((EBP - 236) + 52);  // @562_5ce0b0
  eax = ext_441970_fastcall3(ecx, edx, PV[16]);  // @563_5ce0b0
  ecx = edx = 0;  // @564_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @565_5ce0b0
  X0[1] = 0;  // @566_5ce0b0
  X0[2] = 0;  // @567_5ce0b0
  X0[3] = 0;  // @568_5ce0b0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }))))))) goto L5ce7f9;  // @569_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @570_5ce0b0
  if (FL[0] == FL[1]) goto L5ce7f9;  // @571_5ce0b0
  ecx = (u32)((EBP - 232) + 48);  // @572_5ce0b0
  eax = ext_4e09b0_thiscall1(ecx);  // @573_5ce0b0
    // @574_5ce0b0
  goto L5ce7f9;  // @575_5ce0b0
  L5ce73b:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @577_5ce0b0
  if (FL[0] == FL[1]) goto L5ce7e1;  // @578_5ce0b0
  eax = (u32)((EBP - 232) + 60);  // @579_5ce0b0
  ecx = esi;  // @580_5ce0b0
  PV[17] = (u32)(eax);  // @581_5ce0b0
  eax = ext_5cf690_thiscall2(ecx, PV[17]);  // @582_5ce0b0
  ecx = edx = 0;  // @583_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 72) + 0), 4); v; });  // @584_5ce0b0
  X0[1] = 0;  // @585_5ce0b0
  X0[2] = 0;  // @586_5ce0b0
  X0[3] = 0;  // @587_5ce0b0
  eax = (u32)((EBP - 232) + 24);  // @588_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 24) + 0), &X0[0], 4);  // @589_5ce0b0
  edx = (u32)((EBP - 232) + 60);  // @590_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 80) + 0), 4); v; });  // @591_5ce0b0
  X0[1] = 0;  // @592_5ce0b0
  X0[2] = 0;  // @593_5ce0b0
  X0[3] = 0;  // @594_5ce0b0
  ecx = (u32)((EBP - 232) + 48);  // @595_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 32) + 0), &X0[0], 4);  // @596_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 76) + 0), 4); v; });  // @597_5ce0b0
  X0[1] = 0;  // @598_5ce0b0
  X0[2] = 0;  // @599_5ce0b0
  X0[3] = 0;  // @600_5ce0b0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806056) + 0), 4); v; })));  // @601_5ce0b0
  PV[18] = (u32)(eax);  // @602_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 236) + 32) + 0), &X0[0], 4);  // @603_5ce0b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[18]);  // @604_5ce0b0
  ecx = edx = 0;  // @605_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 132) + 0), 4); v; });  // @606_5ce0b0
  X0[1] = 0;  // @607_5ce0b0
  X0[2] = 0;  // @608_5ce0b0
  X0[3] = 0;  // @609_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; })));  // @610_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 136) + 0), 4); v; });  // @611_5ce0b0
  X1[1] = 0;  // @612_5ce0b0
  X1[2] = 0;  // @613_5ce0b0
  X1[3] = 0;  // @614_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; })));  // @615_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @616_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 140) + 0), 4); v; });  // @617_5ce0b0
  X0[1] = 0;  // @618_5ce0b0
  X0[2] = 0;  // @619_5ce0b0
  X0[3] = 0;  // @620_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; })));  // @621_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @622_5ce0b0
  X0[0] = 0;  // @623_5ce0b0
  X0[1] = 0;  // @624_5ce0b0
  X0[2] = 0;  // @625_5ce0b0
  X0[3] = 0;  // @626_5ce0b0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5ce7f9;  // @627_5ce0b0
  eax = (u32)((EBP - 232) + 72);  // @628_5ce0b0
  PV[19] = (u32)(eax);  // @629_5ce0b0
  edx = (u32)((EBP - 236) + 64);  // @630_5ce0b0
  ecx = (u32)((EBP - 236) + 52);  // @631_5ce0b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[19]);  // @632_5ce0b0
  ecx = edx = 0;  // @633_5ce0b0
  goto L5ce7f9;  // @634_5ce0b0
  L5ce7e1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 96) + 0), 4); v; });  // @636_5ce0b0
  X0[1] = 0;  // @637_5ce0b0
  X0[2] = 0;  // @638_5ce0b0
  X0[3] = 0;  // @639_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 48) + 0), &X0[0], 4);  // @640_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 104) + 0), 4); v; });  // @641_5ce0b0
  X0[1] = 0;  // @642_5ce0b0
  X0[2] = 0;  // @643_5ce0b0
  X0[3] = 0;  // @644_5ce0b0
  L5ce7f3:;
  __builtin_memcpy((void *)((u32)((EBP - 232) + 56) + 0), &X0[0], 4);  // @646_5ce0b0
  L5ce7f9:;
  ecx = (u32)((EBP - 232) + 48);  // @648_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 52), &v, sizeof v); }  // @649_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @650_5ce0b0
  ecx = 0;  // @651_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @652_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @653_5ce0b0
  eax = (eax ^ ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 44), sizeof v); (u32)v; }));  // @654_5ce0b0
  FL[3] = eax;  // @655_5ce0b0
  FL[2] = ((eax & 0xff) & (u32)(3));  // @656_5ce0b0
  if (FL[2] == 0) goto L5ce824;  // @657_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2089), &v, sizeof v); }  // @658_5ce0b0
  L5ce824:;
  edx = (u32)((EBP - 232) + 132);  // @660_5ce0b0
  ecx = ebx;  // @661_5ce0b0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @662_5ce0b0
  ecx = edx = 0;  // @663_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2877), &v, sizeof v); }  // @664_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @665_5ce0b0
  X0[1] = 0;  // @666_5ce0b0
  X0[2] = 0;  // @667_5ce0b0
  X0[3] = 0;  // @668_5ce0b0
  PV[20] = (u32)(ecx);  // @669_5ce0b0
  ecx = ebx;  // @670_5ce0b0
  PV[21] = X0[0];  // @671_5ce0b0
  eax = ext_4e0d80_thiscall2(ecx, PV[21]);  // @672_5ce0b0
  ecx = edx = 0;  // @673_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @674_5ce0b0
  ecx = edi;  // @675_5ce0b0
  PV[22] = (u32)(ebx);  // @676_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1472)))(ecx, PV[22]);  // @677_5ce0b0
  ecx = edx = 0;  // @678_5ce0b0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(4194304));  // @679_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 96) + 0), 4); v; });  // @680_5ce0b0
  X0[1] = 0;  // @681_5ce0b0
  X0[2] = 0;  // @682_5ce0b0
  X0[3] = 0;  // @683_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 100) + 0), 4); v; });  // @684_5ce0b0
  X1[1] = 0;  // @685_5ce0b0
  X1[2] = 0;  // @686_5ce0b0
  X1[3] = 0;  // @687_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; })));  // @688_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; })));  // @689_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @690_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 104) + 0), 4); v; });  // @691_5ce0b0
  X0[1] = 0;  // @692_5ce0b0
  X0[2] = 0;  // @693_5ce0b0
  X0[3] = 0;  // @694_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; })));  // @695_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @696_5ce0b0
  if (FL[2] != 0) goto L5ce9e1;  // @697_5ce0b0
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))))) goto L5ce8a6;  // @698_5ce0b0
  X0[0] = 0;  // @699_5ce0b0
  X0[1] = 0;  // @700_5ce0b0
  X0[2] = 0;  // @701_5ce0b0
  X0[3] = 0;  // @702_5ce0b0
  goto L5ce8c9;  // @703_5ce0b0
  L5ce8a6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @705_5ce0b0
  X0[1] = 0;  // @706_5ce0b0
  X0[2] = 0;  // @707_5ce0b0
  X0[3] = 0;  // @708_5ce0b0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5ce8bd;  // @709_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @710_5ce0b0
  X0[1] = 0;  // @711_5ce0b0
  X0[2] = 0;  // @712_5ce0b0
  X0[3] = 0;  // @713_5ce0b0
  goto L5ce8c9;  // @714_5ce0b0
  L5ce8bd:;
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @716_5ce0b0
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @717_5ce0b0
  ecx = edx = 0;  // @718_5ce0b0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @719_5ce0b0
  L5ce8c9:;
  eax = (u32)((EBP - 232) + 48);  // @721_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 16) + 0), &X0[0], 4);  // @722_5ce0b0
  PV[23] = (u32)(eax);  // @723_5ce0b0
  edx = (u32)((EBP - 236) + 100);  // @724_5ce0b0
  ecx = (u32)((EBP - 236) + 88);  // @725_5ce0b0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[23]);  // @726_5ce0b0
  ecx = edx = 0;  // @727_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 88) + 0), 4); v; });  // @728_5ce0b0
  X0[1] = 0;  // @729_5ce0b0
  X0[2] = 0;  // @730_5ce0b0
  X0[3] = 0;  // @731_5ce0b0
  X1[0] = 0;  // @732_5ce0b0
  X1[1] = 0;  // @733_5ce0b0
  X1[2] = 0;  // @734_5ce0b0
  X1[3] = 0;  // @735_5ce0b0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5ce8f8;  // @736_5ce0b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(64))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @737_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @738_5ce0b0
  goto L5ce8ff;  // @739_5ce0b0
  L5ce8f8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @741_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @742_5ce0b0
  L5ce8ff:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @744_5ce0b0
  ebx = (ebx >> (u32)(27));  // @745_5ce0b0
  FL[3] = ebx;  // @746_5ce0b0
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(1))) & 0xff);  // @747_5ce0b0
  FL[3] = (ebx & 0xff);  // @748_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @749_5ce0b0
  if (FL[0] == FL[1]) goto L5ce939;  // @750_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @751_5ce0b0
  X0[1] = 0;  // @752_5ce0b0
  X0[2] = 0;  // @753_5ce0b0
  X0[3] = 0;  // @754_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @755_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @756_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce939;  // @757_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; });  // @758_5ce0b0
  X0[1] = 0;  // @759_5ce0b0
  X0[2] = 0;  // @760_5ce0b0
  X0[3] = 0;  // @761_5ce0b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 232) + 20), &v, sizeof v); }  // @762_5ce0b0
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; }))))))) goto L5ce93e;  // @763_5ce0b0
  L5ce939:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 20), &v, sizeof v); }  // @765_5ce0b0
  L5ce93e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @767_5ce0b0
  ecx = edi;  // @768_5ce0b0
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 20), sizeof v); (u32)v; });  // @769_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1608)))(ecx, PV[24]);  // @770_5ce0b0
  ecx = edx = 0;  // @771_5ce0b0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @772_5ce0b0
  if (FL[2] == 0) goto L5ce95a;  // @773_5ce0b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6945228) + 0), 4); v; });  // @774_5ce0b0
  X2[1] = 0;  // @775_5ce0b0
  X2[2] = 0;  // @776_5ce0b0
  X2[3] = 0;  // @777_5ce0b0
  goto L5ce962;  // @778_5ce0b0
  L5ce95a:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; });  // @780_5ce0b0
  X2[1] = 0;  // @781_5ce0b0
  X2[2] = 0;  // @782_5ce0b0
  X2[3] = 0;  // @783_5ce0b0
  L5ce962:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @785_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @786_5ce0b0
  X3[1] = 0;  // @787_5ce0b0
  X3[2] = 0;  // @788_5ce0b0
  X3[3] = 0;  // @789_5ce0b0
  if (FL[0] == FL[1]) goto L5ce974;  // @790_5ce0b0
  X2[0] = X3[0];  // @791_5ce0b0
  X2[1] = X3[1];  // @792_5ce0b0
  X2[2] = X3[2];  // @793_5ce0b0
  X2[3] = X3[3];  // @794_5ce0b0
  L5ce974:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @796_5ce0b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @797_5ce0b0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }));  // @798_5ce0b0
  FL[3] = ecx;  // @799_5ce0b0
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @800_5ce0b0
  X1[0] = F2U((float)(s32)X1[0]);  // @801_5ce0b0
  X1[1] = F2U((float)(s32)X1[1]);  // @802_5ce0b0
  X1[2] = F2U((float)(s32)X1[2]);  // @803_5ce0b0
  X1[3] = F2U((float)(s32)X1[3]);  // @804_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @805_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @806_5ce0b0
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @807_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce9a3;  // @808_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; });  // @809_5ce0b0
  X1[1] = 0;  // @810_5ce0b0
  X1[2] = 0;  // @811_5ce0b0
  X1[3] = 0;  // @812_5ce0b0
  L5ce9a3:;
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @814_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; });  // @815_5ce0b0
  X0[1] = 0;  // @816_5ce0b0
  X0[2] = 0;  // @817_5ce0b0
  X0[3] = 0;  // @818_5ce0b0
  X2[0] = F2U(U2F(X2[0]) * U2F(X1[0]));  // @819_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @820_5ce0b0
  { float a_ = U2F(X3[0]), b_ = U2F(X2[0]); X3[0] = (a_ < b_) ? X3[0] : F2U(b_); }  // @821_5ce0b0
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; })));  // @822_5ce0b0
  X3[0] = F2U(U2F(X3[0]) / U2F(X1[0]));  // @823_5ce0b0
  __builtin_memcpy((void *)((u32)(edi + 2063) + 0), &X3[0], 4);  // @824_5ce0b0
  if (((!(U2F(X0[0]) >= U2F(X3[0]))) || (!((U2F(X0[0]) < U2F(X3[0])) || (U2F(X0[0]) > U2F(X3[0])))))) goto L5ce9e1;  // @825_5ce0b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2382), &v, sizeof v); }  // @826_5ce0b0
  L5ce9e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @828_5ce0b0
  ecx = edi;  // @829_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1232), sizeof v); (u32)v; });  // @830_5ce0b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @831_5ce0b0
  ecx = edx = 0;  // @832_5ce0b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @833_5ce0b0
  if (FL[2] != 0) goto L5ceb19;  // @834_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @835_5ce0b0
  ecx = edi;  // @836_5ce0b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1488)))(ecx);  // @837_5ce0b0
  ecx = edx = 0;  // @838_5ce0b0
  FL[0] = eax; FL[1] = (u32)(16);  // @839_5ce0b0
  if (FL[0] == FL[1]) goto L5ceb19;  // @840_5ce0b0
  FL[0] = eax; FL[1] = (u32)(17);  // @841_5ce0b0
  if (FL[0] == FL[1]) goto L5ceb19;  // @842_5ce0b0
  FL[0] = eax; FL[1] = (u32)(15);  // @843_5ce0b0
  if (FL[0] == FL[1]) goto L5ceb19;  // @844_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 132) + 0), 4); v; });  // @845_5ce0b0
  X0[1] = 0;  // @846_5ce0b0
  X0[2] = 0;  // @847_5ce0b0
  X0[3] = 0;  // @848_5ce0b0
  ecx = (u32)((EBP - 232) + 60);  // @849_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 60) + 0), &X0[0], 4);  // @850_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 140) + 0), 4); v; });  // @851_5ce0b0
  X0[1] = 0;  // @852_5ce0b0
  X0[2] = 0;  // @853_5ce0b0
  X0[3] = 0;  // @854_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 68) + 0), &X0[0], 4);  // @855_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 64), &v, sizeof v); }  // @856_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @857_5ce0b0
  ecx = 0;  // @858_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 64) + 0), 4); v; });  // @859_5ce0b0
  X0[1] = 0;  // @860_5ce0b0
  X0[2] = 0;  // @861_5ce0b0
  X0[3] = 0;  // @862_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @863_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 60) + 0), 4); v; });  // @864_5ce0b0
  X1[1] = 0;  // @865_5ce0b0
  X1[2] = 0;  // @866_5ce0b0
  X1[3] = 0;  // @867_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 100) + 0), 4); v; })));  // @868_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 96) + 0), 4); v; })));  // @869_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @870_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 68) + 0), 4); v; });  // @871_5ce0b0
  X0[1] = 0;  // @872_5ce0b0
  X0[2] = 0;  // @873_5ce0b0
  X0[3] = 0;  // @874_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 104) + 0), 4); v; })));  // @875_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @876_5ce0b0
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000624) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000624) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000624) + 0), 4); v; }))))))) goto L5ceb19;  // @877_5ce0b0
  PV[25] = (u32)(ecx);  // @878_5ce0b0
  eax = (u32)((EBP - 236) + 136);  // @879_5ce0b0
  PV[26] = (u32)(eax);  // @880_5ce0b0
  edx = (u32)((EBP - 240) + 104);  // @881_5ce0b0
  ecx = (u32)((EBP - 240) + 32);  // @882_5ce0b0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[26], (u32)(1073741824));  // @883_5ce0b0
  ecx = edx = 0;  // @884_5ce0b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @885_5ce0b0
  eax = (u32)((EBP - 232) + 168);  // @886_5ce0b0
  PV[27] = (u32)(eax);  // @887_5ce0b0
  eax = (u32)((EBP - 236) + 196);  // @888_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 236) + 32), &v, sizeof v); }  // @889_5ce0b0
  PV[28] = (u32)(eax);  // @890_5ce0b0
  ecx = edi;  // @891_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 928)))(ecx, PV[28], PV[27]);  // @892_5ce0b0
  ecx = edx = 0;  // @893_5ce0b0
  PV[29] = (u32)(eax);  // @894_5ce0b0
  ecx = edi;  // @895_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[29]);  // @896_5ce0b0
  ecx = edx = 0;  // @897_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @898_5ce0b0
  ecx = (u32)((EBP - 232) + 168);  // @899_5ce0b0
  PV[30] = (u32)(ecx);  // @900_5ce0b0
  ecx = edi;  // @901_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[30]);  // @902_5ce0b0
  ecx = edx = 0;  // @903_5ce0b0
  PV[31] = (u32)(ecx);  // @904_5ce0b0
  eax = (u32)((EBP - 236) + 28);  // @905_5ce0b0
  PV[32] = (u32)(eax);  // @906_5ce0b0
  edx = (u32)((EBP - 240) + 176);  // @907_5ce0b0
  ecx = (u32)((EBP - 240) + 92);  // @908_5ce0b0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[32], (u32)(1120403456));  // @909_5ce0b0
  ecx = edx = 0;  // @910_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @911_5ce0b0
  ecx = (u32)((EBP - 232) + 84);  // @912_5ce0b0
  PV[33] = (u32)(ecx);  // @913_5ce0b0
  ecx = edi;  // @914_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[33]);  // @915_5ce0b0
  ecx = edx = 0;  // @916_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @917_5ce0b0
  ecx = (u32)((EBP - 232) + 84);  // @918_5ce0b0
  PV[34] = (u32)(ecx);  // @919_5ce0b0
  ecx = edi;  // @920_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 924)))(ecx, PV[34]);  // @921_5ce0b0
  ecx = edx = 0;  // @922_5ce0b0
  L5ceb19:;
  ext_633654(G(u32, 0x6f5630));  // @924_5ce0b0
  return eax;  // @925_5ce0b0
}
PCREG(5ce0b0, lifted_5ce0b0);

