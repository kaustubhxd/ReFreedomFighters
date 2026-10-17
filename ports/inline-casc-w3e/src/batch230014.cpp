// batch230014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_4e0030_fastcall2(u32, u32) __asm__("ext_4e0030");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_515930_thiscall3(u32, u32, u32) __asm__("ext_515930");
extern "C" u32 THISCALL ext_523330_thiscall2(u32, u32) __asm__("ext_523330");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_517670(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @0_517670
  X0[1] = 0;  // @1_517670
  X0[2] = 0;  // @2_517670
  X0[3] = 0;  // @3_517670
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_517670
  esi = ecx;  // @5_517670
  PV[1] = (u32)(ecx);  // @6_517670
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 28), &v, sizeof v); }  // @7_517670
  PV[2] = X0[0];  // @8_517670
  eax = ext_515930_thiscall3(ecx, PV[2], PV[0]);  // @9_517670
  ecx = edx = 0;  // @10_517670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @11_517670
  eax = (u32)((EBP - 88) + 72);  // @12_517670
  PV[3] = (u32)(eax);  // @13_517670
  eax = ext_523330_thiscall2(ecx, PV[3]);  // @14_517670
  ecx = edx = 0;  // @15_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 5599) + 0), 4); v; });  // @16_517670
  X0[1] = 0;  // @17_517670
  X0[2] = 0;  // @18_517670
  X0[3] = 0;  // @19_517670
  eax = (u32)(esi + 5599);  // @20_517670
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 72) + 0), 4); v; })));  // @21_517670
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @22_517670
  X1[1] = 0;  // @23_517670
  X1[2] = 0;  // @24_517670
  X1[3] = 0;  // @25_517670
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 76) + 0), 4); v; })));  // @26_517670
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @27_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @28_517670
  X0[1] = 0;  // @29_517670
  X0[2] = 0;  // @30_517670
  X0[3] = 0;  // @31_517670
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 80) + 0), 4); v; })));  // @32_517670
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @33_517670
  X0[0] = 0;  // @34_517670
  X0[1] = 0;  // @35_517670
  X0[2] = 0;  // @36_517670
  X0[3] = 0;  // @37_517670
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L51771f;  // @38_517670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @39_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @41_517670
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6942712), (u32)(415));  // @42_517670
  ecx = edx = 0;  // @43_517670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @44_517670
  edx = (u32)(6801640);  // @45_517670
  FL[2] = (ecx & ecx);  // @46_517670
  if (FL[2] != 0) edx = ecx;  // @47_517670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_517670
  PV[4] = (u32)(edx);  // @49_517670
  PV[5] = (u32)(eax);  // @50_517670
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6942912), PV[4]);  // @51_517670
  ecx = edx = 0;  // @52_517670
  eax = (u32)(esi + 5599);  // @53_517670
  L51771f:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5712), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @55_517670
  if (FL[0] != FL[1]) goto L5179aa;  // @56_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 892) + 0), 4); v; });  // @57_517670
  X0[1] = 0;  // @58_517670
  X0[2] = 0;  // @59_517670
  X0[3] = 0;  // @60_517670
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @61_517670
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @62_517670
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @63_517670
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @64_517670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @65_517670
  PV[6] = (u32)(ecx);  // @66_517670
  PV[7] = X0[0];  // @67_517670
  ecx = (u32)((EBP - 92) + 40);  // @68_517670
  PV[8] = (u32)(eax);  // @69_517670
  edx = (edx + (u32)(36));  // @70_517670
  FL[3] = edx;  // @71_517670
  eax = ext_443ef0_fastcall4(ecx, edx, PV[8], PV[7]);  // @72_517670
  ecx = edx = 0;  // @73_517670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @74_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 892) + 0), 4); v; });  // @75_517670
  X0[1] = 0;  // @76_517670
  X0[2] = 0;  // @77_517670
  X0[3] = 0;  // @78_517670
  __builtin_memcpy((void *)((u32)((EBP - 88) + 12) + 0), &X0[0], 4);  // @79_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 888) + 0), 4); v; });  // @80_517670
  X0[1] = 0;  // @81_517670
  X0[2] = 0;  // @82_517670
  X0[3] = 0;  // @83_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_517670
  __builtin_memcpy((void *)((u32)((EBP - 88) + 16) + 0), &X0[0], 4);  // @85_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @86_517670
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @87_517670
  ecx = edx = 0;  // @88_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 16) + 0), 4); v; });  // @89_517670
  X0[1] = 0;  // @90_517670
  X0[2] = 0;  // @91_517670
  X0[3] = 0;  // @92_517670
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 12) + 0), 4); v; })));  // @93_517670
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @94_517670
  PV[9] = (u32)(ecx);  // @95_517670
  ecx = esi;  // @96_517670
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_517670
  __builtin_memcpy((void *)((u32)((EBP - 92) + 16) + 0), &X0[0], 4);  // @98_517670
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)((EBP - 92) + 16)) : "st");  // @99_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @100_517670
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 92) + 16)) :: "st");  // @101_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 92) + 16) + 0), 4); v; });  // @102_517670
  X0[1] = 0;  // @103_517670
  X0[2] = 0;  // @104_517670
  X0[3] = 0;  // @105_517670
  PV[10] = X0[0];  // @106_517670
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[10]);  // @107_517670
  ecx = edx = 0;  // @108_517670
  PV[11] = (u32)(ecx);  // @109_517670
  ecx = esi;  // @110_517670
  { float f_; __asm__ volatile("fstps %0" : "=m"(f_) :: "st"); PV[12] = F2U(f_); }  // @111_517670
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 32)))(ecx, PV[12]);  // @112_517670
  ecx = edx = 0;  // @113_517670
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 20), sizeof v); (u32)v; });  // @114_517670
  edx = (u32)((EBP - 88) + 36);  // @115_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @116_517670
  ecx = (u32)(edi + 5611);  // @117_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @118_517670
  X0[1] = 0;  // @119_517670
  X0[2] = 0;  // @120_517670
  X0[3] = 0;  // @121_517670
  __builtin_memcpy((void *)((u32)((EBP - 88) + 24) + 0), &X0[0], 4);  // @122_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 12) + 0), 4); v; });  // @123_517670
  X0[1] = 0;  // @124_517670
  X0[2] = 0;  // @125_517670
  X0[3] = 0;  // @126_517670
  __builtin_memcpy((void *)((u32)((EBP - 88) + 28) + 0), &X0[0], 4);  // @127_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 0), 4); v; });  // @128_517670
  X0[1] = 0;  // @129_517670
  X0[2] = 0;  // @130_517670
  X0[3] = 0;  // @131_517670
  eax = (u32)((EBP - 88) + 24);  // @132_517670
  PV[13] = (u32)(eax);  // @133_517670
  __builtin_memcpy((void *)((u32)((EBP - 92) + 36) + 0), &X0[0], 4);  // @134_517670
  eax = ext_43e920_fastcall3(ecx, edx, PV[13]);  // @135_517670
  ecx = edx = 0;  // @136_517670
  eax = (u32)((EBP - 88) + 60);  // @137_517670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5615), &v, sizeof v); }  // @138_517670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @139_517670
  PV[14] = (u32)(eax);  // @140_517670
  eax = ext_523330_thiscall2(ecx, PV[14]);  // @141_517670
  ecx = edx = 0;  // @142_517670
  PV[15] = (u32)(ecx);  // @143_517670
  ecx = (u32)((EBP - 92) + 64);  // @144_517670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 92) + 68), &v, sizeof v); }  // @145_517670
  eax = ext_4e0d00_thiscall2(ecx, (u32)(3212836864));  // @146_517670
    // @147_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 60) + 0), 4); v; });  // @148_517670
  X0[1] = 0;  // @149_517670
  X0[2] = 0;  // @150_517670
  X0[3] = 0;  // @151_517670
  eax = (u32)((EBP - 88) + 60);  // @152_517670
  X1[0] = 0;  // @153_517670
  X1[1] = 0;  // @154_517670
  X1[2] = 0;  // @155_517670
  X1[3] = 0;  // @156_517670
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 88) + 20), &v, sizeof v); }  // @157_517670
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @158_517670
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @159_517670
  if (!__builtin_parity(FL[2] & 0xff)) goto L517856;  // @160_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 64) + 0), 4); v; });  // @161_517670
  X0[1] = 0;  // @162_517670
  X0[2] = 0;  // @163_517670
  X0[3] = 0;  // @164_517670
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @165_517670
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @166_517670
  if (!__builtin_parity(FL[2] & 0xff)) goto L517856;  // @167_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 68) + 0), 4); v; });  // @168_517670
  X0[1] = 0;  // @169_517670
  X0[2] = 0;  // @170_517670
  X0[3] = 0;  // @171_517670
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @172_517670
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @173_517670
  if (__builtin_parity(FL[2] & 0xff)) goto L517896;  // @174_517670
  L517856:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 88) + 16), &v, sizeof v); }  // @176_517670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 20), sizeof v); (u32)v; });  // @177_517670
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @178_517670
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @179_517670
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @180_517670
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @181_517670
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @182_517670
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @183_517670
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @184_517670
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @185_517670
  __asm__ volatile("fsqrt" ::: "st");  // @186_517670
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 88) + 16)) : "st");  // @187_517670
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @188_517670
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @189_517670
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @190_517670
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @191_517670
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @192_517670
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @193_517670
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @194_517670
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @195_517670
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @196_517670
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @197_517670
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 88) + 16)) :: "st");  // @198_517670
  L517896:;
  esi = (u32)(edi + 5599);  // @200_517670
  edx = esi;  // @201_517670
  ecx = (u32)((EBP - 88) + 60);  // @202_517670
  eax = ext_4e0030_fastcall2(ecx, edx);  // @203_517670
  ecx = edx = 0;  // @204_517670
  PV[16] = (u32)(esi);  // @205_517670
  edx = (u32)((EBP - 92) + 64);  // @206_517670
  ecx = (u32)((EBP - 92) + 52);  // @207_517670
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + 5623)) :: "st");  // @208_517670
  eax = ext_446ee0_fastcall3(ecx, edx, PV[16]);  // @209_517670
  ecx = edx = 0;  // @210_517670
  X0[0] = 0;  // @211_517670
  X0[1] = 0;  // @212_517670
  X0[2] = 0;  // @213_517670
  X0[3] = 0;  // @214_517670
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 52) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 52) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 52) + 0), 4); v; }))))))) goto L5178dc;  // @215_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5623) + 0), 4); v; });  // @216_517670
  X0[1] = 0;  // @217_517670
  X0[2] = 0;  // @218_517670
  X0[3] = 0;  // @219_517670
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @220_517670
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @221_517670
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @222_517670
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @223_517670
  __builtin_memcpy((void *)((u32)(edi + 5623) + 0), &X0[0], 4);  // @224_517670
  L5178dc:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi + 5627), &v, sizeof v); }  // @226_517670
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 5712), &v, sizeof v); }  // @227_517670
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5615) + 0), 4); v; });  // @228_517670
  X1[1] = 0;  // @229_517670
  X1[2] = 0;  // @230_517670
  X1[3] = 0;  // @231_517670
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5611) + 0), 4); v; });  // @232_517670
  X2[1] = 0;  // @233_517670
  X2[2] = 0;  // @234_517670
  X2[3] = 0;  // @235_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5619) + 0), 4); v; });  // @236_517670
  X0[1] = 0;  // @237_517670
  X0[2] = 0;  // @238_517670
  X0[3] = 0;  // @239_517670
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @240_517670
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @241_517670
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @242_517670
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @243_517670
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @244_517670
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @245_517670
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @246_517670
  ecx = edx = 0;  // @247_517670
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @248_517670
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; }))))))) goto L5179aa;  // @249_517670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @250_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @251_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @252_517670
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6942712), (u32)(449));  // @253_517670
  ecx = edx = 0;  // @254_517670
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5615) + 0), 4); v; });  // @255_517670
  X1[1] = 0;  // @256_517670
  X1[2] = 0;  // @257_517670
  X1[3] = 0;  // @258_517670
  esi = eax;  // @259_517670
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5611) + 0), 4); v; });  // @260_517670
  X2[1] = 0;  // @261_517670
  X2[2] = 0;  // @262_517670
  X2[3] = 0;  // @263_517670
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5619) + 0), 4); v; });  // @264_517670
  X0[1] = 0;  // @265_517670
  X0[2] = 0;  // @266_517670
  X0[3] = 0;  // @267_517670
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @268_517670
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @269_517670
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @270_517670
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @271_517670
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @272_517670
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @273_517670
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @274_517670
  ecx = edx = 0;  // @275_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @276_517670
  ecx = (u32)(6801640);  // @277_517670
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @278_517670
  FL[2] = (eax & eax);  // @279_517670
  if (FL[2] != 0) ecx = eax;  // @280_517670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @281_517670
  SD(&X0[0], (double)U2F(X0[0]));  // @282_517670
  PV[17] = X0[0]; PV[18] = X0[1];  // @283_517670
  PV[19] = (u32)(ecx);  // @284_517670
  PV[20] = (u32)(esi);  // @285_517670
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 44)))(PV[20], (u32)(6942840), PV[19], PV[17], PV[18]);  // @286_517670
  ecx = edx = 0;  // @287_517670
  L5179aa:;
  ext_633654(G(u32, 0x6f5630));  // @289_517670
  return eax;  // @290_517670
}
PCREG(517670, lifted_517670);

