// batch242035.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_459fc0_fastcall3(u32, u32, u32) __asm__("ext_459fc0");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4dfd80_fastcall2(u32, u32) __asm__("ext_4dfd80");
extern "C" u32 FASTCALL ext_4dfde0_fastcall2(u32, u32) __asm__("ext_4dfde0");
extern "C" u32 FASTCALL ext_4dfe20_fastcall2(u32, u32) __asm__("ext_4dfe20");
extern "C" u32 FASTCALL ext_4dfe60_fastcall2(u32, u32) __asm__("ext_4dfe60");
extern "C" u32 FASTCALL ext_4e1b80_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_4e1b80");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_457960_thiscall3(u32, u32, u32) __asm__("ext_457960");
extern "C" u32 THISCALL ext_459f40_thiscall3(u32, u32, u32) __asm__("ext_459f40");
extern "C" u32 THISCALL ext_45dc90_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_45dc90");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4dff10_thiscall1(u32) __asm__("ext_4dff10");
extern "C" u32 THISCALL ext_4dffb0_thiscall2(u32, u32) __asm__("ext_4dffb0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_458ae0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_458ae0
  esi = ecx;  // @2_458ae0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 216), &v, sizeof v); }  // @3_458ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_458ae0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_458ae0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @6_458ae0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 212), &v, sizeof v); }  // @7_458ae0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @8_458ae0
  if (FL[0] != FL[1]) goto L458b3b;  // @9_458ae0
  PV[0] = (u32)(ecx);  // @10_458ae0
  PV[1] = (u32)(eax);  // @11_458ae0
  PV[2] = (u32)(edi);  // @12_458ae0
  PV[3] = (u32)(edx);  // @13_458ae0
  ecx = esi;  // @14_458ae0
  eax = ext_45dc90_thiscall5(ecx, PV[3], PV[2], PV[1], PV[0]);  // @15_458ae0
  ecx = edx = 0;  // @16_458ae0
  ext_633654(G(u32, 0x6f5630));  // @17_458ae0
  return eax;  // @18_458ae0
  L458b3b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 188), sizeof v); (u32)v; });  // @22_458ae0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @23_458ae0
  ecx = edx = 0;  // @24_458ae0
  ecx = eax;  // @25_458ae0
  FL[2] = (ecx & ecx);  // @26_458ae0
  if (FL[2] == 0) goto L458b96;  // @27_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_458ae0
  PV[4] = (u32)(ecx);  // @29_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @30_458ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6829860), (u32)(1065353216));  // @31_458ae0
  ecx = edx = 0;  // @32_458ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 152)) :: "st");  // @33_458ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; });  // @34_458ae0
  X1[1] = 0;  // @35_458ae0
  X1[2] = 0;  // @36_458ae0
  X1[3] = 0;  // @37_458ae0
  X0[0] = 0;  // @38_458ae0
  X0[1] = 0;  // @39_458ae0
  X0[2] = 0;  // @40_458ae0
  X0[3] = 0;  // @41_458ae0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(X0[0])) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(X0[0]) != U2F(X0[0]))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))) ? 0x40 : 0)) << 8);  // @42_458ae0
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(X0[0])) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(X0[0]) != U2F(X0[0]))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))) ? 0x40 : 0)) & 68);  // @43_458ae0
  if (__builtin_parity(FL[2] & 0xff)) goto L459382;  // @44_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @46_458ae0
  __builtin_memcpy((void *)((u32)(eax + 4749) + 0), &X1[0], 4);  // @47_458ae0
  L458b96:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_458ae0
  PV[5] = (u32)(ecx);  // @50_458ae0
  ecx = esi;  // @51_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @52_458ae0
  X0[1] = 0;  // @53_458ae0
  X0[2] = 0;  // @54_458ae0
  X0[3] = 0;  // @55_458ae0
  eax = (u32)(EBP - 228);  // @56_458ae0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @57_458ae0
  PV[6] = X0[0];  // @58_458ae0
  PV[7] = (u32)(eax);  // @59_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X0[0], 4);  // @60_458ae0
  eax = ext_459f40_thiscall3(ecx, PV[7], PV[6]);  // @61_458ae0
  ecx = edx = 0;  // @62_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @63_458ae0
  ecx = (u32)(EBP - 28);  // @64_458ae0
  PV[8] = (u32)(ecx);  // @65_458ae0
  ecx = (u32)(EBP - 100);  // @66_458ae0
  PV[9] = (u32)(ecx);  // @67_458ae0
  ecx = edi;  // @68_458ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[9], PV[8]);  // @69_458ae0
  ecx = edx = 0;  // @70_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @71_458ae0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @72_458ae0
  X0[2] = 0;  // @73_458ae0
  X0[3] = 0;  // @74_458ae0
  ecx = (u32)(EBP - 16);  // @75_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @76_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @77_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 4), &X0[1], 4);  // @78_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 100) + 0), 4); v; });  // @79_458ae0
  X0[1] = 0;  // @80_458ae0
  X0[2] = 0;  // @81_458ae0
  X0[3] = 0;  // @82_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @83_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 96) + 0), 4); v; });  // @84_458ae0
  X0[1] = 0;  // @85_458ae0
  X0[2] = 0;  // @86_458ae0
  X0[3] = 0;  // @87_458ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @88_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @89_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @90_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @91_458ae0
  X0[1] = 0;  // @92_458ae0
  X0[2] = 0;  // @93_458ae0
  X0[3] = 0;  // @94_458ae0
  PV[10] = (u32)(ecx);  // @95_458ae0
  ecx = esi;  // @96_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @97_458ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[10]);  // @98_458ae0
  ecx = edx = 0;  // @99_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_458ae0
  ecx = (u32)(EBP - 64);  // @101_458ae0
  PV[11] = (u32)(ecx);  // @102_458ae0
  ecx = esi;  // @103_458ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[11]);  // @104_458ae0
  ecx = edx = 0;  // @105_458ae0
  eax = (u32)(EBP - 64);  // @106_458ae0
  ecx = esi;  // @107_458ae0
  PV[12] = (u32)(eax);  // @108_458ae0
  eax = (u32)(EBP - 16);  // @109_458ae0
  PV[13] = (u32)(eax);  // @110_458ae0
  eax = ext_457960_thiscall3(ecx, PV[13], PV[12]);  // @111_458ae0
  ecx = edx = 0;  // @112_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 96) + 0), 4); v; });  // @113_458ae0
  X0[1] = 0;  // @114_458ae0
  X0[2] = 0;  // @115_458ae0
  X0[3] = 0;  // @116_458ae0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @117_458ae0
  X3[1] = 0;  // @118_458ae0
  X3[2] = 0;  // @119_458ae0
  X3[3] = 0;  // @120_458ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @121_458ae0
  X1[1] = 0;  // @122_458ae0
  X1[2] = 0;  // @123_458ae0
  X1[3] = 0;  // @124_458ae0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829936) + 0), 4); v; });  // @125_458ae0
  X2[1] = 0;  // @126_458ae0
  X2[2] = 0;  // @127_458ae0
  X2[3] = 0;  // @128_458ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 152)) :: "st");  // @129_458ae0
  if (((!(U2F(X0[0]) >= U2F(X3[0]))) || (!((U2F(X0[0]) < U2F(X3[0])) || (U2F(X0[0]) > U2F(X3[0])))))) goto L458c5f;  // @130_458ae0
  X1[0] = 0;  // @131_458ae0
  X1[1] = 0;  // @132_458ae0
  X1[2] = 0;  // @133_458ae0
  X1[3] = 0;  // @134_458ae0
  X0[0] = X1[0];  // @135_458ae0
  X0[1] = X1[1];  // @136_458ae0
  X0[2] = X1[2];  // @137_458ae0
  X0[3] = X1[3];  // @138_458ae0
  goto L458cc2;  // @139_458ae0
  L458c5f:;
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L458c9e;  // @141_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @142_458ae0
  X0[1] = 0;  // @143_458ae0
  X0[2] = 0;  // @144_458ae0
  X0[3] = 0;  // @145_458ae0
  X1[0] = 0;  // @146_458ae0
  X1[1] = 0;  // @147_458ae0
  X1[2] = 0;  // @148_458ae0
  X1[3] = 0;  // @149_458ae0
  L458c6f:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 152) + 0), 4); v; });  // @151_458ae0
  X4[1] = 0;  // @152_458ae0
  X4[2] = 0;  // @153_458ae0
  X4[3] = 0;  // @154_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @155_458ae0
  if (((!(U2F(X0[0]) >= U2F(X4[0]))) || (!((U2F(X0[0]) < U2F(X4[0])) || (U2F(X0[0]) > U2F(X4[0])))))) goto L458cf4;  // @156_458ae0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 156) + 0), 4); v; });  // @157_458ae0
  X2[1] = 0;  // @158_458ae0
  X2[2] = 0;  // @159_458ae0
  X2[3] = 0;  // @160_458ae0
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L458cf1;  // @161_458ae0
  X1[0] = X0[0];  // @162_458ae0
  X1[1] = X0[1];  // @163_458ae0
  X1[2] = X0[2];  // @164_458ae0
  X1[3] = X0[3];  // @165_458ae0
  X2[0] = F2U(U2F(X2[0]) - U2F(X4[0]));  // @166_458ae0
  X1[0] = F2U(U2F(X1[0]) - U2F(X4[0]));  // @167_458ae0
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @168_458ae0
  goto L458cf4;  // @169_458ae0
  L458c9e:;
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @171_458ae0
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @172_458ae0
  ecx = edx = 0;  // @173_458ae0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829936) + 0), 4); v; });  // @174_458ae0
  X2[1] = 0;  // @175_458ae0
  X2[2] = 0;  // @176_458ae0
  X2[3] = 0;  // @177_458ae0
  X1[0] = 0;  // @178_458ae0
  X1[1] = 0;  // @179_458ae0
  X1[2] = 0;  // @180_458ae0
  X1[3] = 0;  // @181_458ae0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @182_458ae0
  X3[1] = 0;  // @183_458ae0
  X3[2] = 0;  // @184_458ae0
  X3[3] = 0;  // @185_458ae0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @186_458ae0
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L458c6f;  // @187_458ae0
  L458cc2:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 144) + 0), 4); v; });  // @189_458ae0
  X4[1] = 0;  // @190_458ae0
  X4[2] = 0;  // @191_458ae0
  X4[3] = 0;  // @192_458ae0
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @193_458ae0
  if (((!(U2F(X2[0]) >= U2F(X4[0]))) || (!((U2F(X2[0]) < U2F(X4[0])) || (U2F(X2[0]) > U2F(X4[0])))))) goto L458cf4;  // @194_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 148) + 0), 4); v; });  // @195_458ae0
  X0[1] = 0;  // @196_458ae0
  X0[2] = 0;  // @197_458ae0
  X0[3] = 0;  // @198_458ae0
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L458cf1;  // @199_458ae0
  X1[0] = X2[0];  // @200_458ae0
  X1[1] = X2[1];  // @201_458ae0
  X1[2] = X2[2];  // @202_458ae0
  X1[3] = X2[3];  // @203_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X4[0]));  // @204_458ae0
  X1[0] = F2U(U2F(X1[0]) - U2F(X4[0]));  // @205_458ae0
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @206_458ae0
  goto L458cf4;  // @207_458ae0
  L458cf1:;
  X1[0] = X3[0];  // @209_458ae0
  X1[1] = X3[1];  // @210_458ae0
  X1[2] = X3[2];  // @211_458ae0
  X1[3] = X3[3];  // @212_458ae0
  L458cf4:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; });  // @214_458ae0
  X0[1] = 0;  // @215_458ae0
  X0[2] = 0;  // @216_458ae0
  X0[3] = 0;  // @217_458ae0
  X1[0] = F2U(U2F(X1[0]) - U2F(X3[0]));  // @218_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @219_458ae0
  ecx = (u32)(16777215);  // @220_458ae0
  edi = (u32)(esi + 68);  // @221_458ae0
  edx = (u32)(esi + 104);  // @222_458ae0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @223_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 116) + 0), 4); v; });  // @224_458ae0
  X0[1] = 0;  // @225_458ae0
  X0[2] = 0;  // @226_458ae0
  X0[3] = 0;  // @227_458ae0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829948) + 0), 4); v; })));  // @228_458ae0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @229_458ae0
  eax = (eax << (u32)(24));  // @230_458ae0
  FL[3] = eax;  // @231_458ae0
  ecx = (ecx - eax);  // @232_458ae0
  FL[3] = ecx;  // @233_458ae0
  PV[14] = (u32)(ecx);  // @234_458ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @235_458ae0
  ecx = (u32)(EBP - 16);  // @236_458ae0
  PV[15] = X0[0];  // @237_458ae0
  PV[16] = (u32)(edi);  // @238_458ae0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[16], PV[15]);  // @239_458ae0
  ecx = edx = 0;  // @240_458ae0
  eax = (u32)(EBP - 52);  // @241_458ae0
  ecx = edi;  // @242_458ae0
  PV[17] = (u32)(eax);  // @243_458ae0
  eax = (u32)(EBP - 100);  // @244_458ae0
  PV[18] = (u32)(eax);  // @245_458ae0
  eax = (u32)(EBP - 28);  // @246_458ae0
  PV[19] = (u32)(eax);  // @247_458ae0
  edx = (u32)(EBP - 16);  // @248_458ae0
  eax = ext_4e1b80_fastcall6(ecx, edx, PV[19], PV[18], PV[17], (u32)(1));  // @249_458ae0
  ecx = 0;  // @250_458ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 152)) :: "st");  // @251_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; });  // @252_458ae0
  X0[1] = 0;  // @253_458ae0
  X0[2] = 0;  // @254_458ae0
  X0[3] = 0;  // @255_458ae0
  X1[0] = 0;  // @256_458ae0
  X1[1] = 0;  // @257_458ae0
  X1[2] = 0;  // @258_458ae0
  X1[3] = 0;  // @259_458ae0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @260_458ae0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @261_458ae0
  if (!__builtin_parity(FL[2] & 0xff)) goto L458def;  // @262_458ae0
  edx = (u32)(EBP - 100);  // @263_458ae0
  ecx = edi;  // @264_458ae0
  eax = ext_4de420_fastcall2(ecx, edx);  // @265_458ae0
    // @266_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @267_458ae0
  X0[1] = 0;  // @268_458ae0
  X0[2] = 0;  // @269_458ae0
  X0[3] = 0;  // @270_458ae0
  edx = (u32)(esi + 104);  // @271_458ae0
  __builtin_memcpy((void *)((u32)(esi + 104) + 0), &X0[0], 4);  // @272_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @273_458ae0
  X0[1] = 0;  // @274_458ae0
  X0[2] = 0;  // @275_458ae0
  X0[3] = 0;  // @276_458ae0
  __builtin_memcpy((void *)((u32)(esi + 108) + 0), &X0[0], 4);  // @277_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @278_458ae0
  X0[1] = 0;  // @279_458ae0
  X0[2] = 0;  // @280_458ae0
  X0[3] = 0;  // @281_458ae0
  PV[20] = (u32)(ecx);  // @282_458ae0
  __builtin_memcpy((void *)((u32)(esi + 112) + 0), &X0[0], 4);  // @283_458ae0
  ecx = (u32)(EBP - 16);  // @284_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 116) + 0), 4); v; });  // @285_458ae0
  X0[1] = 0;  // @286_458ae0
  X0[2] = 0;  // @287_458ae0
  X0[3] = 0;  // @288_458ae0
  PV[21] = X0[0];  // @289_458ae0
  PV[22] = (u32)(edi);  // @290_458ae0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[22], PV[21]);  // @291_458ae0
  ecx = edx = 0;  // @292_458ae0
  eax = (u32)(EBP - 52);  // @293_458ae0
  ecx = edi;  // @294_458ae0
  PV[23] = (u32)(eax);  // @295_458ae0
  eax = (u32)(EBP - 100);  // @296_458ae0
  PV[24] = (u32)(eax);  // @297_458ae0
  eax = (u32)(EBP - 28);  // @298_458ae0
  PV[25] = (u32)(eax);  // @299_458ae0
  edx = (u32)(EBP - 16);  // @300_458ae0
  eax = ext_4e1b80_fastcall6(ecx, edx, PV[25], PV[24], PV[23], (u32)(1));  // @301_458ae0
  ecx = 0;  // @302_458ae0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 152)) :: "st");  // @303_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; });  // @304_458ae0
  X0[1] = 0;  // @305_458ae0
  X0[2] = 0;  // @306_458ae0
  X0[3] = 0;  // @307_458ae0
  X1[0] = 0;  // @308_458ae0
  X1[1] = 0;  // @309_458ae0
  X1[2] = 0;  // @310_458ae0
  X1[3] = 0;  // @311_458ae0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @312_458ae0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @313_458ae0
  if (!__builtin_parity(FL[2] & 0xff)) goto L458def;  // @314_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @315_458ae0
  FL[2] = (eax & eax);  // @316_458ae0
  if (FL[2] == 0) goto L458dee;  // @317_458ae0
  eax = ((u32(STDCALL *)(void))(eax))();  // @318_458ae0
  ecx = edx = 0;  // @319_458ae0
  goto L458def;  // @320_458ae0
  L458dee:;
  __builtin_trap();  // @322_458ae0
  L458def:;
  edx = (u32)(esi + 104);  // @324_458ae0
  ecx = (u32)(EBP - 52);  // @325_458ae0
  eax = ext_43e960_fastcall2(ecx, edx);  // @326_458ae0
  ecx = edx = 0;  // @327_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 156) + 0), 4); v; });  // @328_458ae0
  X0[1] = 0;  // @329_458ae0
  X0[2] = 0;  // @330_458ae0
  X0[3] = 0;  // @331_458ae0
  edx = (u32)(EBP - 228);  // @332_458ae0
  PV[26] = (u32)(ecx);  // @333_458ae0
  ecx = (u32)(EBP - 52);  // @334_458ae0
  PV[27] = X0[0];  // @335_458ae0
  eax = ext_451890_fastcall3(ecx, edx, PV[27]);  // @336_458ae0
  ecx = 0;  // @337_458ae0
  edx = edi;  // @338_458ae0
  ecx = (u32)(EBP - 52);  // @339_458ae0
  eax = ext_441a60_fastcall2(ecx, edx);  // @340_458ae0
  ecx = edx = 0;  // @341_458ae0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 188), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @342_458ae0
  if (FL[0] == FL[1]) goto L458ec7;  // @343_458ae0
  edx = (u32)(EBP - 228);  // @344_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @345_458ae0
  ecx = (u32)(EBP - 16);  // @346_458ae0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @347_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @348_458ae0
  eax = ext_44e630_fastcall2(ecx, edx);  // @349_458ae0
  ecx = edx = 0;  // @350_458ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @351_458ae0
  X1[1] = 0;  // @352_458ae0
  X1[2] = 0;  // @353_458ae0
  X1[3] = 0;  // @354_458ae0
  ecx = (u32)(EBP - 40);  // @355_458ae0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @356_458ae0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 189) + 0), 4); v; });  // @357_458ae0
  X2[1] = 0;  // @358_458ae0
  X2[2] = 0;  // @359_458ae0
  X2[3] = 0;  // @360_458ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @361_458ae0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @362_458ae0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @363_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X1[0], 4);  // @364_458ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @365_458ae0
  X1[1] = 0;  // @366_458ae0
  X1[2] = 0;  // @367_458ae0
  X1[3] = 0;  // @368_458ae0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @369_458ae0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @370_458ae0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @371_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X1[0], 4);  // @372_458ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @373_458ae0
  X1[1] = 0;  // @374_458ae0
  X1[2] = 0;  // @375_458ae0
  X1[3] = 0;  // @376_458ae0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @377_458ae0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @378_458ae0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @379_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X1[0], 4);  // @380_458ae0
  eax = ext_44c840_thiscall1(ecx);  // @381_458ae0
  ecx = 0;  // @382_458ae0
  edx = (u32)(EBP - 100);  // @383_458ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @384_458ae0
  ecx = (u32)(EBP - 40);  // @385_458ae0
  eax = ext_441a60_fastcall2(ecx, edx);  // @386_458ae0
  ecx = edx = 0;  // @387_458ae0
  ecx = (u32)(esi + 209);  // @388_458ae0
  edx = (u32)(EBP - 40);  // @389_458ae0
  eax = ext_4dfe60_fastcall2(ecx, edx);  // @390_458ae0
  ecx = edx = 0;  // @391_458ae0
  goto L458f18;  // @392_458ae0
  L458ec7:;
  PV[28] = (u32)(edi);  // @394_458ae0
  edx = (u32)(EBP - 76);  // @395_458ae0
  ecx = (u32)(EBP - 112);  // @396_458ae0
  eax = ext_459fc0_fastcall3(ecx, edx, PV[28]);  // @397_458ae0
  ecx = edx = 0;  // @398_458ae0
  PV[29] = (u32)(edi);  // @399_458ae0
  edx = (u32)(EBP - 88);  // @400_458ae0
  ecx = (u32)(EBP - 124);  // @401_458ae0
  eax = ext_459fc0_fastcall3(ecx, edx, PV[29]);  // @402_458ae0
  ecx = edx = 0;  // @403_458ae0
  edx = (u32)(EBP - 112);  // @404_458ae0
  ecx = (u32)(EBP - 136);  // @405_458ae0
  eax = ext_4dfe60_fastcall2(ecx, edx);  // @406_458ae0
  ecx = edx = 0;  // @407_458ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @408_458ae0
  edx = (u32)(EBP - 124);  // @409_458ae0
  ecx = (u32)(EBP - 128);  // @410_458ae0
  eax = ext_4dfe60_fastcall2(ecx, edx);  // @411_458ae0
  ecx = edx = 0;  // @412_458ae0
  edx = (u32)(EBP - 136);  // @413_458ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @414_458ae0
  ecx = (u32)(esi + 209);  // @415_458ae0
  eax = ext_4dfe20_fastcall2(ecx, edx);  // @416_458ae0
    // @417_458ae0
  ecx = (u32)(esi + 209);  // @418_458ae0
  eax = ext_4dff10_thiscall1(ecx);  // @419_458ae0
  ecx = edx = 0;  // @420_458ae0
  L458f18:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 213), sizeof v); (u32)v; });  // @422_458ae0
  edi = (u32)(esi + 201);  // @423_458ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @424_458ae0
  edx = (u32)(EBP - 100);  // @425_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 209) + 0), 4); v; });  // @426_458ae0
  X0[1] = 0;  // @427_458ae0
  X0[2] = 0;  // @428_458ae0
  X0[3] = 0;  // @429_458ae0
  ecx = (u32)(esi + 68);  // @430_458ae0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @431_458ae0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @432_458ae0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @433_458ae0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @434_458ae0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @435_458ae0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @436_458ae0
  __builtin_memcpy((void *)((u32)(esi + 205) + 0), &X0[0], 4);  // @437_458ae0
  eax = ext_4de420_fastcall2(ecx, edx);  // @438_458ae0
    // @439_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @440_458ae0
  X0[1] = 0;  // @441_458ae0
  X0[2] = 0;  // @442_458ae0
  X0[3] = 0;  // @443_458ae0
  edx = (u32)(EBP - 16);  // @444_458ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @445_458ae0
  __builtin_memcpy((void *)((u32)(esi + 104) + 0), &X0[0], 4);  // @446_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @447_458ae0
  X0[1] = 0;  // @448_458ae0
  X0[2] = 0;  // @449_458ae0
  X0[3] = 0;  // @450_458ae0
  __builtin_memcpy((void *)((u32)(esi + 108) + 0), &X0[0], 4);  // @451_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @452_458ae0
  X0[1] = 0;  // @453_458ae0
  X0[2] = 0;  // @454_458ae0
  X0[3] = 0;  // @455_458ae0
  __builtin_memcpy((void *)((u32)(esi + 112) + 0), &X0[0], 4);  // @456_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @457_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 116) + 0), 4); v; });  // @458_458ae0
  X0[1] = 0;  // @459_458ae0
  X0[2] = 0;  // @460_458ae0
  X0[3] = 0;  // @461_458ae0
  PV[30] = (u32)(edx);  // @462_458ae0
  edx = (u32)(EBP - 148);  // @463_458ae0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @464_458ae0
  PV[31] = (u32)(edx);  // @465_458ae0
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @466_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @467_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @468_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @469_458ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 628)))(ecx, PV[31], PV[30]);  // @470_458ae0
  ecx = edx = 0;  // @471_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @472_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 148) + 0), 4); v; });  // @473_458ae0
  X0[1] = 0;  // @474_458ae0
  X0[2] = 0;  // @475_458ae0
  X0[3] = 0;  // @476_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 204) + 0), &X0[0], 4);  // @477_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 144) + 0), 4); v; });  // @478_458ae0
  X0[1] = 0;  // @479_458ae0
  X0[2] = 0;  // @480_458ae0
  X0[3] = 0;  // @481_458ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @482_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 208) + 0), &X0[0], 4);  // @483_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @484_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 216), sizeof v); (u32)v; });  // @485_458ae0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @486_458ae0
  ecx = edx = 0;  // @487_458ae0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @488_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @489_458ae0
  X0[0] = F2U((float)(s32)X0[0]);  // @490_458ae0
  X0[1] = F2U((float)(s32)X0[1]);  // @491_458ae0
  X0[2] = F2U((float)(s32)X0[2]);  // @492_458ae0
  X0[3] = F2U((float)(s32)X0[3]);  // @493_458ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @494_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 152) + 0), &X0[0], 4);  // @495_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @496_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 220), sizeof v); (u32)v; });  // @497_458ae0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @498_458ae0
  ecx = edx = 0;  // @499_458ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; });  // @500_458ae0
  X1[1] = 0;  // @501_458ae0
  X1[2] = 0;  // @502_458ae0
  X1[3] = 0;  // @503_458ae0
  edx = (u32)(EBP - 148);  // @504_458ae0
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; })));  // @505_458ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @506_458ae0
  PV[32] = (u32)(edx);  // @507_458ae0
  edx = (u32)(EBP - 16);  // @508_458ae0
  PV[33] = (u32)(edx);  // @509_458ae0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @510_458ae0
  X0[0] = F2U((float)(s32)X0[0]);  // @511_458ae0
  X0[1] = F2U((float)(s32)X0[1]);  // @512_458ae0
  X0[2] = F2U((float)(s32)X0[2]);  // @513_458ae0
  X0[3] = F2U((float)(s32)X0[3]);  // @514_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @515_458ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @516_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @517_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 192) + 0), &X1[0], 4);  // @518_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X0[0], 4);  // @519_458ae0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 124) + 0), 4); v; })));  // @520_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 196) + 0), &X0[0], 4);  // @521_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @522_458ae0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 4), 4); v; });  // @523_458ae0
  X0[2] = 0;  // @524_458ae0
  X0[3] = 0;  // @525_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 148) + 0), &X0[0], 4);  // @526_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 148) + 4), &X0[1], 4);  // @527_458ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 624)))(ecx, PV[33], PV[32]);  // @528_458ae0
  ecx = edx = 0;  // @529_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 156) + 0), 4); v; });  // @530_458ae0
  X0[1] = 0;  // @531_458ae0
  X0[2] = 0;  // @532_458ae0
  X0[3] = 0;  // @533_458ae0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; })));  // @534_458ae0
  PV[34] = (u32)(ecx);  // @535_458ae0
  ecx = (u32)(EBP - 16);  // @536_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X0[0], 4);  // @537_458ae0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @538_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @539_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @540_458ae0
  X0[1] = 0;  // @541_458ae0
  X0[2] = 0;  // @542_458ae0
  X0[3] = 0;  // @543_458ae0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 184) + 0), 4); v; })));  // @544_458ae0
  PV[35] = X0[0];  // @545_458ae0
  eax = ext_4dffb0_thiscall2(ecx, PV[35]);  // @546_458ae0
    // @547_458ae0
  edx = edi;  // @548_458ae0
  ecx = (u32)(EBP - 16);  // @549_458ae0
  eax = ext_4dfde0_fastcall2(ecx, edx);  // @550_458ae0
    // @551_458ae0
  eax = (u32)(esi + 193);  // @552_458ae0
  edx = (u32)(EBP - 16);  // @553_458ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @554_458ae0
  ecx = eax;  // @555_458ae0
  eax = ext_4dfd80_fastcall2(ecx, edx);  // @556_458ae0
    // @557_458ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 156) + 0), 4); v; });  // @558_458ae0
  X1[1] = 0;  // @559_458ae0
  X1[2] = 0;  // @560_458ae0
  X1[3] = 0;  // @561_458ae0
  X0[0] = X1[0];  // @562_458ae0
  X0[1] = X1[1];  // @563_458ae0
  X0[2] = X1[2];  // @564_458ae0
  X0[3] = X1[3];  // @565_458ae0
  { u32 v = (u32)((u32)(3204448256)); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @566_458ae0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @567_458ae0
  PV[36] = (u32)(ecx);  // @568_458ae0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; })));  // @569_458ae0
  ecx = (u32)(EBP - 168);  // @570_458ae0
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @571_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 164) + 0), &X0[0], 4);  // @572_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @573_458ae0
  X0[1] = 0;  // @574_458ae0
  X0[2] = 0;  // @575_458ae0
  X0[3] = 0;  // @576_458ae0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 184) + 0), 4); v; })));  // @577_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 172) + 0), &X1[0], 4);  // @578_458ae0
  PV[37] = X0[0];  // @579_458ae0
  eax = ext_4dffb0_thiscall2(ecx, PV[37]);  // @580_458ae0
    // @581_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @582_458ae0
  X0[1] = 0;  // @583_458ae0
  X0[2] = 0;  // @584_458ae0
  X0[3] = 0;  // @585_458ae0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 184) + 0), 4); v; })));  // @586_458ae0
  PV[38] = (u32)(ecx);  // @587_458ae0
  ecx = (u32)(EBP - 176);  // @588_458ae0
  PV[39] = X0[0];  // @589_458ae0
  eax = ext_4dffb0_thiscall2(ecx, PV[39]);  // @590_458ae0
    // @591_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @592_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @593_458ae0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @594_458ae0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @595_458ae0
  if (FL[0] == FL[1]) goto L459322;  // @596_458ae0
  edi = (edi + (u32)(16));  // @597_458ae0
  FL[3] = edi;  // @598_458ae0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @599_458ae0
  L459180:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 168) + 0), 4); v; });  // @601_458ae0
  X0[1] = 0;  // @602_458ae0
  X0[2] = 0;  // @603_458ae0
  X0[3] = 0;  // @604_458ae0
  eax = (u32)(edi + 36);  // @605_458ae0
  __builtin_memcpy((void *)((u32)(edi - 4) + 0), &X0[0], 4);  // @606_458ae0
  esi = (u32)(edi - 4);  // @607_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @608_458ae0
  X0[1] = 0;  // @609_458ae0
  X0[2] = 0;  // @610_458ae0
  X0[3] = 0;  // @611_458ae0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @612_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 176) + 0), 4); v; });  // @613_458ae0
  X0[1] = 0;  // @614_458ae0
  X0[2] = 0;  // @615_458ae0
  X0[3] = 0;  // @616_458ae0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X0[0], 4);  // @617_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @618_458ae0
  X0[1] = 0;  // @619_458ae0
  X0[2] = 0;  // @620_458ae0
  X0[3] = 0;  // @621_458ae0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @622_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 176) + 0), 4); v; });  // @623_458ae0
  X0[1] = 0;  // @624_458ae0
  X0[2] = 0;  // @625_458ae0
  X0[3] = 0;  // @626_458ae0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X0[0], 4);  // @627_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 172) + 0), 4); v; });  // @628_458ae0
  X0[1] = 0;  // @629_458ae0
  X0[2] = 0;  // @630_458ae0
  X0[3] = 0;  // @631_458ae0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @632_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 168) + 0), 4); v; });  // @633_458ae0
  X0[1] = 0;  // @634_458ae0
  X0[2] = 0;  // @635_458ae0
  X0[3] = 0;  // @636_458ae0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X0[0], 4);  // @637_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 172) + 0), 4); v; });  // @638_458ae0
  X0[1] = 0;  // @639_458ae0
  X0[2] = 0;  // @640_458ae0
  X0[3] = 0;  // @641_458ae0
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X0[0], 4);  // @642_458ae0
  edi = eax;  // @643_458ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @644_458ae0
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @645_458ae0
  L459200:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @647_458ae0
  ecx = esi;  // @648_458ae0
  eax = ext_4dfde0_fastcall2(ecx, edx);  // @649_458ae0
    // @650_458ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @651_458ae0
  ecx = esi;  // @652_458ae0
  eax = ext_4dfd80_fastcall2(ecx, edx);  // @653_458ae0
    // @654_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @655_458ae0
  X0[1] = 0;  // @656_458ae0
  X0[2] = 0;  // @657_458ae0
  X0[3] = 0;  // @658_458ae0
  edi = (u32)(edi + 4);  // @659_458ae0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 192) + 0), 4); v; })));  // @660_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @661_458ae0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @662_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 196) + 0), 4); v; });  // @663_458ae0
  X0[1] = 0;  // @664_458ae0
  X0[2] = 0;  // @665_458ae0
  X0[3] = 0;  // @666_458ae0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @667_458ae0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @668_458ae0
  esi = (esi + (u32)(8));  // @669_458ae0
  FL[3] = esi;  // @670_458ae0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @671_458ae0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @672_458ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 4), &v, sizeof v); }  // @673_458ae0
  if (FL[3] != 0) goto L459200;  // @674_458ae0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @675_458ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @676_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 4) + 0), 4); v; });  // @677_458ae0
  X0[1] = 0;  // @678_458ae0
  X0[2] = 0;  // @679_458ae0
  X0[3] = 0;  // @680_458ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @681_458ae0
  X1[1] = 0;  // @682_458ae0
  X1[2] = 0;  // @683_458ae0
  X1[3] = 0;  // @684_458ae0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @685_458ae0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @686_458ae0
  X3[0] = eax; X3[1] = X3[2] = X3[3] = 0;  // @687_458ae0
  X3[0] = F2U((float)(s32)X3[0]);  // @688_458ae0
  X3[1] = F2U((float)(s32)X3[1]);  // @689_458ae0
  X3[2] = F2U((float)(s32)X3[2]);  // @690_458ae0
  X3[3] = F2U((float)(s32)X3[3]);  // @691_458ae0
  X2[0] = ecx; X2[1] = X2[2] = X2[3] = 0;  // @692_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @693_458ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @694_458ae0
  X2[0] = F2U((float)(s32)X2[0]);  // @695_458ae0
  X2[1] = F2U((float)(s32)X2[1]);  // @696_458ae0
  X2[2] = F2U((float)(s32)X2[2]);  // @697_458ae0
  X2[3] = F2U((float)(s32)X2[3]);  // @698_458ae0
  ecx = (ecx + 1);  // @699_458ae0
  FL[3] = ecx;  // @700_458ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @701_458ae0
  __builtin_memcpy((void *)((u32)(edi - 4) + 0), &X0[0], 4);  // @702_458ae0
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @703_458ae0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X1[0], 4);  // @704_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @705_458ae0
  X0[1] = 0;  // @706_458ae0
  X0[2] = 0;  // @707_458ae0
  X0[3] = 0;  // @708_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @709_458ae0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X0[0], 4);  // @710_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @711_458ae0
  X0[1] = 0;  // @712_458ae0
  X0[2] = 0;  // @713_458ae0
  X0[3] = 0;  // @714_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @715_458ae0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @716_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @717_458ae0
  X0[1] = 0;  // @718_458ae0
  X0[2] = 0;  // @719_458ae0
  X0[3] = 0;  // @720_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @721_458ae0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X0[0], 4);  // @722_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 16) + 0), 4); v; });  // @723_458ae0
  X0[1] = 0;  // @724_458ae0
  X0[2] = 0;  // @725_458ae0
  X0[3] = 0;  // @726_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @727_458ae0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @728_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 20) + 0), 4); v; });  // @729_458ae0
  X0[1] = 0;  // @730_458ae0
  X0[2] = 0;  // @731_458ae0
  X0[3] = 0;  // @732_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @733_458ae0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X0[0], 4);  // @734_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @735_458ae0
  X0[1] = 0;  // @736_458ae0
  X0[2] = 0;  // @737_458ae0
  X0[3] = 0;  // @738_458ae0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @739_458ae0
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X0[0], 4);  // @740_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 204) + 0), 4); v; });  // @741_458ae0
  X0[1] = 0;  // @742_458ae0
  X0[2] = 0;  // @743_458ae0
  X0[3] = 0;  // @744_458ae0
  __builtin_memcpy((void *)((u32)(edi + 28) + 0), &X0[0], 4);  // @745_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 208) + 0), 4); v; });  // @746_458ae0
  X0[1] = 0;  // @747_458ae0
  X0[2] = 0;  // @748_458ae0
  X0[3] = 0;  // @749_458ae0
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X0[0], 4);  // @750_458ae0
  edi = (edi + (u32)(68));  // @751_458ae0
  FL[3] = edi;  // @752_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @753_458ae0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @754_458ae0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @755_458ae0
  if (FL[0] != FL[1]) goto L459180;  // @756_458ae0
  L459322:;
  ecx = (u32)(EBP - 100);  // @758_458ae0
  eax = ext_4de7a0_thiscall1(ecx);  // @759_458ae0
    // @760_458ae0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @761_458ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @762_458ae0
  edx = (u32)(EBP - 16);  // @763_458ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 116) + 0), 4); v; });  // @764_458ae0
  X0[1] = 0;  // @765_458ae0
  X0[2] = 0;  // @766_458ae0
  X0[3] = 0;  // @767_458ae0
  PV[41] = (u32)(ecx);  // @768_458ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @769_458ae0
  PV[42] = (u32)(edx);  // @770_458ae0
  edx = (u32)(EBP - 28);  // @771_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @772_458ae0
  PV[43] = (u32)(edx);  // @773_458ae0
  edx = (u32)(EBP - 100);  // @774_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @775_458ae0
  PV[44] = (u32)(edx);  // @776_458ae0
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; });  // @777_458ae0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @778_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @779_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @780_458ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @781_458ae0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[45], PV[44], PV[43], PV[42], (u32)(2123789977), PV[40]);  // @782_458ae0
  ecx = edx = 0;  // @783_458ae0
  L459382:;
  ext_633654(G(u32, 0x6f5630));  // @785_458ae0
  return eax;  // @786_458ae0
}
PCREG(458ae0, lifted_458ae0);

