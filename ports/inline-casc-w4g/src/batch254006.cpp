// batch254006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_65a630(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @0_65a630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_65a630
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_65a630
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 88) + 24), &v, sizeof v); }  // @3_65a630
  if (FL[0] <= FL[1]) goto L65ae3c;  // @4_65a630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @5_65a630
  esi = (esi + (u32)(524));  // @6_65a630
  FL[3] = esi;  // @7_65a630
  L65a663:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 108), sizeof v); (u32)v; });  // @9_65a630
  FL[0] = eax; FL[1] = (u32)(3);  // @10_65a630
  if (FL[0] > FL[1]) goto L65ae2c;  // @11_65a630
  switch (eax) {  // @12_65a630
  case 0: goto L65a7ea;  // @13_65a630
  case 1: goto L65a676;  // @14_65a630
  case 2: goto L65aba7;  // @15_65a630
  case 3: goto L65a9e9;  // @16_65a630
  default: __builtin_trap(); }  // @17_65a630
  L65a676:;
  FL[2] = (ecx & (u32)(8192));  // @19_65a630
  if (FL[2] == 0) goto L65a688;  // @20_65a630
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi - 104), sizeof v); (u32)v; }) & (u32)(1));  // @21_65a630
  if (FL[2] == 0) goto L65ae2c;  // @22_65a630
  L65a688:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @24_65a630
  FL[2] = (edx & edx);  // @25_65a630
  if (FL[2] == 0) goto L65ae2c;  // @26_65a630
  ecx = (u32)(edi + 20);  // @27_65a630
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 88) + 16), &v, sizeof v); }  // @28_65a630
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 88) + 8), &v, sizeof v); }  // @29_65a630
  edi = 0;  // @30_65a630
  FL[3] = edi;  // @31_65a630
  L65a6a0:;
  eax = (u32)(esi - 100);  // @33_65a630
  edx = (u32)(ecx - 20);  // @34_65a630
  PV[0] = (u32)(eax);  // @35_65a630
  ecx = (u32)((EBP - 92) + 52);  // @36_65a630
  eax = ext_43e920_fastcall3(ecx, edx, PV[0]);  // @37_65a630
  ecx = edx = 0;  // @38_65a630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 8), sizeof v); (u32)v; });  // @39_65a630
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 48) + 0), 4); v; });  // @40_65a630
  X1[1] = 0;  // @41_65a630
  X1[2] = 0;  // @42_65a630
  X1[3] = 0;  // @43_65a630
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 52) + 0), 4); v; });  // @44_65a630
  X3[1] = 0;  // @45_65a630
  X3[2] = 0;  // @46_65a630
  X3[3] = 0;  // @47_65a630
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 56) + 0), 4); v; });  // @48_65a630
  X4[1] = 0;  // @49_65a630
  X4[2] = 0;  // @50_65a630
  X4[3] = 0;  // @51_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx - 4) + 0), 4); v; });  // @52_65a630
  X0[1] = 0;  // @53_65a630
  X0[2] = 0;  // @54_65a630
  X0[3] = 0;  // @55_65a630
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx - 8) + 0), 4); v; });  // @56_65a630
  X2[1] = 0;  // @57_65a630
  X2[2] = 0;  // @58_65a630
  X2[3] = 0;  // @59_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @60_65a630
  X2[0] = F2U(U2F(X2[0]) * U2F(X1[0]));  // @61_65a630
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @62_65a630
  X0[0] = X4[0];  // @63_65a630
  X0[1] = X4[1];  // @64_65a630
  X0[2] = X4[2];  // @65_65a630
  X0[3] = X4[3];  // @66_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; })));  // @67_65a630
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @68_65a630
  FC0 = U2F(X2[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @69_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 12) + 0), &X2[0], 4);  // @70_65a630
  if ((!(!(FC0 >= FC1)))) goto L65a7d0;  // @71_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @72_65a630
  X3[0] = F2U(U2F(X3[0]) * U2F(X3[0]));  // @73_65a630
  X4[0] = F2U(U2F(X4[0]) * U2F(X4[0]));  // @74_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X3[0]));  // @75_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X4[0]));  // @76_65a630
  FC0 = U2F(X1[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; }));  // @77_65a630
  if ((!(!(FC0 >= FC1)) && !(!((FC0 < FC1) || (FC0 > FC1))))) goto L65a7d0;  // @78_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 8) + 0), 4); v; });  // @79_65a630
  X0[1] = 0;  // @80_65a630
  X0[2] = 0;  // @81_65a630
  X0[3] = 0;  // @82_65a630
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @83_65a630
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @84_65a630
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L65a73a;  // @85_65a630
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @86_65a630
  ecx = edx = 0;  // @87_65a630
  X2[0] = 0;  // @88_65a630
  X2[1] = 0;  // @89_65a630
  X2[2] = 0;  // @90_65a630
  X2[3] = 0;  // @91_65a630
  X2[0] = F2U((float)U2D(X0[0], X0[1]));  // @92_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @93_65a630
  X0[1] = 0;  // @94_65a630
  X0[2] = 0;  // @95_65a630
  X0[3] = 0;  // @96_65a630
  goto L65a754;  // @97_65a630
  L65a73a:;
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @99_65a630
  ecx = edx = 0;  // @100_65a630
  X2[0] = 0;  // @101_65a630
  X2[1] = 0;  // @102_65a630
  X2[2] = 0;  // @103_65a630
  X2[3] = 0;  // @104_65a630
  X2[0] = F2U((float)U2D(X0[0], X0[1]));  // @105_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 4) + 0), 4); v; });  // @106_65a630
  X0[1] = 0;  // @107_65a630
  X0[2] = 0;  // @108_65a630
  X0[3] = 0;  // @109_65a630
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @110_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @111_65a630
  L65a754:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 12) + 0), 4); v; });  // @113_65a630
  X1[1] = 0;  // @114_65a630
  X1[2] = 0;  // @115_65a630
  X1[3] = 0;  // @116_65a630
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @117_65a630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 8), sizeof v); (u32)v; });  // @118_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @119_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463424) + 0), 4); v; });  // @120_65a630
  X0[1] = 0;  // @121_65a630
  X0[2] = 0;  // @122_65a630
  X0[3] = 0;  // @123_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 52) + 0), 4); v; })));  // @124_65a630
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @125_65a630
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @126_65a630
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @127_65a630
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @128_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @129_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463936) + 0), 4); v; })));  // @130_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463936) + 0), &X0[0], 4);  // @131_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463428) + 0), 4); v; });  // @132_65a630
  X0[1] = 0;  // @133_65a630
  X0[2] = 0;  // @134_65a630
  X0[3] = 0;  // @135_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 48) + 0), 4); v; })));  // @136_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @137_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463940) + 0), 4); v; })));  // @138_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463940) + 0), &X0[0], 4);  // @139_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463432) + 0), 4); v; });  // @140_65a630
  X0[1] = 0;  // @141_65a630
  X0[2] = 0;  // @142_65a630
  X0[3] = 0;  // @143_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 44) + 0), 4); v; })));  // @144_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @145_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463944) + 0), 4); v; })));  // @146_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463944) + 0), &X0[0], 4);  // @147_65a630
  L65a7d0:;
  ecx = (ecx + (u32)(36));  // @149_65a630
  FL[3] = ecx;  // @150_65a630
  edi = (edi + (u32)(16));  // @151_65a630
  FL[3] = edi;  // @152_65a630
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 16), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)((EBP - 88) + 16), &v, sizeof v); }  // @153_65a630
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 16), sizeof v); (u32)v; });  // @154_65a630
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 88) + 8), &v, sizeof v); }  // @155_65a630
  if (FL[3] != 0) goto L65a6a0;  // @156_65a630
  goto L65ae25;  // @157_65a630
  L65a7ea:;
  FL[2] = (ecx & (u32)(8192));  // @159_65a630
  if (FL[2] == 0) goto L65a7fc;  // @160_65a630
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi - 104), sizeof v); (u32)v; }) & (u32)(1));  // @161_65a630
  if (FL[2] == 0) goto L65ae2c;  // @162_65a630
  L65a7fc:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @164_65a630
  FL[2] = (edx & edx);  // @165_65a630
  if (FL[2] == 0) goto L65ae2c;  // @166_65a630
  ecx = (u32)(edi + 20);  // @167_65a630
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 88) + 12), &v, sizeof v); }  // @168_65a630
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 88) + 8), &v, sizeof v); }  // @169_65a630
  edi = 0;  // @170_65a630
  FL[3] = edi;  // @171_65a630
  L65a814:;
  eax = (u32)(esi - 100);  // @173_65a630
  edx = (u32)(ecx - 20);  // @174_65a630
  PV[1] = (u32)(eax);  // @175_65a630
  ecx = (u32)((EBP - 92) + 76);  // @176_65a630
  eax = ext_43e920_fastcall3(ecx, edx, PV[1]);  // @177_65a630
  ecx = edx = 0;  // @178_65a630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 8), sizeof v); (u32)v; });  // @179_65a630
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 72) + 0), 4); v; });  // @180_65a630
  X1[1] = 0;  // @181_65a630
  X1[2] = 0;  // @182_65a630
  X1[3] = 0;  // @183_65a630
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 76) + 0), 4); v; });  // @184_65a630
  X3[1] = 0;  // @185_65a630
  X3[2] = 0;  // @186_65a630
  X3[3] = 0;  // @187_65a630
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 80) + 0), 4); v; });  // @188_65a630
  X4[1] = 0;  // @189_65a630
  X4[2] = 0;  // @190_65a630
  X4[3] = 0;  // @191_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx - 4) + 0), 4); v; });  // @192_65a630
  X0[1] = 0;  // @193_65a630
  X0[2] = 0;  // @194_65a630
  X0[3] = 0;  // @195_65a630
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx - 8) + 0), 4); v; });  // @196_65a630
  X2[1] = 0;  // @197_65a630
  X2[2] = 0;  // @198_65a630
  X2[3] = 0;  // @199_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @200_65a630
  X2[0] = F2U(U2F(X2[0]) * U2F(X1[0]));  // @201_65a630
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @202_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @203_65a630
  X0[1] = 0;  // @204_65a630
  X0[2] = 0;  // @205_65a630
  X0[3] = 0;  // @206_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @207_65a630
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @208_65a630
  FC0 = U2F(X2[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @209_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 28) + 0), &X2[0], 4);  // @210_65a630
  if ((!(!(FC0 >= FC1)))) goto L65a9cf;  // @211_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @212_65a630
  X3[0] = F2U(U2F(X3[0]) * U2F(X3[0]));  // @213_65a630
  X4[0] = F2U(U2F(X4[0]) * U2F(X4[0]));  // @214_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X3[0]));  // @215_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X4[0]));  // @216_65a630
  FC0 = U2F(X1[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; }));  // @217_65a630
  if ((!(!(FC0 >= FC1)))) goto L65a9cf;  // @218_65a630
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @219_65a630
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @220_65a630
  ecx = edx = 0;  // @221_65a630
  X1[0] = 0;  // @222_65a630
  X1[1] = 0;  // @223_65a630
  X1[2] = 0;  // @224_65a630
  X1[3] = 0;  // @225_65a630
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @226_65a630
  FC0 = U2F(X1[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 12) + 0), 4); v; }));  // @227_65a630
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L65a8bf;  // @228_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 4) + 0), 4); v; });  // @229_65a630
  X0[1] = 0;  // @230_65a630
  X0[2] = 0;  // @231_65a630
  X0[3] = 0;  // @232_65a630
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @233_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @234_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 16) + 0), &X0[0], 4);  // @235_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @236_65a630
  X0[1] = 0;  // @237_65a630
  X0[2] = 0;  // @238_65a630
  X0[3] = 0;  // @239_65a630
  goto L65a8cd;  // @240_65a630
  L65a8bf:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @242_65a630
  X0[1] = 0;  // @243_65a630
  X0[2] = 0;  // @244_65a630
  X0[3] = 0;  // @245_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 16) + 0), &X0[0], 4);  // @246_65a630
  L65a8cd:;
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @248_65a630
  PV[2] = (u32)(ecx);  // @249_65a630
  ecx = (u32)((EBP - 92) + 76);  // @250_65a630
  __builtin_memcpy((void *)((u32)((EBP - 92) + 48) + 0), &X0[0], 4);  // @251_65a630
  PV[3] = X0[0];  // @252_65a630
  eax = ext_4e0d00_thiscall2(ecx, PV[3]);  // @253_65a630
    // @254_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 84) + 0), 4); v; });  // @255_65a630
  X0[1] = 0;  // @256_65a630
  X0[2] = 0;  // @257_65a630
  X0[3] = 0;  // @258_65a630
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 88) + 0), 4); v; });  // @259_65a630
  X2[1] = 0;  // @260_65a630
  X2[2] = 0;  // @261_65a630
  X2[3] = 0;  // @262_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 76) + 0), 4); v; })));  // @263_65a630
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 72) + 0), 4); v; })));  // @264_65a630
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @265_65a630
  X1[1] = 0;  // @266_65a630
  X1[2] = 0;  // @267_65a630
  X1[3] = 0;  // @268_65a630
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @269_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 80) + 0), 4); v; });  // @270_65a630
  X0[1] = 0;  // @271_65a630
  X0[2] = 0;  // @272_65a630
  X0[3] = 0;  // @273_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 80) + 0), 4); v; })));  // @274_65a630
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @275_65a630
  FC0 = U2F(X1[0]); FC1 = U2F(X2[0]);  // @276_65a630
  if ((!(!(FC0 >= FC1)) && !(!((FC0 < FC1) || (FC0 > FC1))))) goto L65a9cb;  // @277_65a630
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 44) + 0), 4); v; });  // @278_65a630
  X3[1] = 0;  // @279_65a630
  X3[2] = 0;  // @280_65a630
  X3[3] = 0;  // @281_65a630
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 28) + 0), 4); v; })));  // @282_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @283_65a630
  X0[1] = 0;  // @284_65a630
  X0[2] = 0;  // @285_65a630
  X0[3] = 0;  // @286_65a630
  FC0 = U2F(X0[0]); FC1 = U2F(X2[0]);  // @287_65a630
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 16) + 0), 4); v; })));  // @288_65a630
  X3[0] = X3[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @289_65a630
  X3[1] = X3[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @290_65a630
  X3[2] = X3[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @291_65a630
  X3[3] = X3[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @292_65a630
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L65a968;  // @293_65a630
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @294_65a630
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; });  // @295_65a630
  X1[1] = 0;  // @296_65a630
  X1[2] = 0;  // @297_65a630
  X1[3] = 0;  // @298_65a630
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; })));  // @299_65a630
  X0[0] = X2[0];  // @300_65a630
  X0[1] = X2[1];  // @301_65a630
  X0[2] = X2[2];  // @302_65a630
  X0[3] = X2[3];  // @303_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @304_65a630
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @305_65a630
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @306_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @307_65a630
  X3[0] = F2U(U2F(X3[0]) * U2F(X1[0]));  // @308_65a630
  L65a968:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463424) + 0), 4); v; });  // @310_65a630
  X0[1] = 0;  // @311_65a630
  X0[2] = 0;  // @312_65a630
  X0[3] = 0;  // @313_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 52) + 0), 4); v; })));  // @314_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @315_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463936) + 0), 4); v; })));  // @316_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463936) + 0), &X0[0], 4);  // @317_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463428) + 0), 4); v; });  // @318_65a630
  X0[1] = 0;  // @319_65a630
  X0[2] = 0;  // @320_65a630
  X0[3] = 0;  // @321_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 48) + 0), 4); v; })));  // @322_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @323_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463940) + 0), 4); v; })));  // @324_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463940) + 0), &X0[0], 4);  // @325_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463432) + 0), 4); v; });  // @326_65a630
  X0[1] = 0;  // @327_65a630
  X0[2] = 0;  // @328_65a630
  X0[3] = 0;  // @329_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 44) + 0), 4); v; })));  // @330_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @331_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463944) + 0), 4); v; })));  // @332_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463944) + 0), &X0[0], 4);  // @333_65a630
  L65a9cb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 8), sizeof v); (u32)v; });  // @335_65a630
  L65a9cf:;
  ecx = (ecx + (u32)(36));  // @337_65a630
  FL[3] = ecx;  // @338_65a630
  edi = (edi + (u32)(16));  // @339_65a630
  FL[3] = edi;  // @340_65a630
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 12), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)((EBP - 88) + 12), &v, sizeof v); }  // @341_65a630
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 12), sizeof v); (u32)v; });  // @342_65a630
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 88) + 8), &v, sizeof v); }  // @343_65a630
  if (FL[3] != 0) goto L65a814;  // @344_65a630
  goto L65ae25;  // @345_65a630
  L65a9e9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @347_65a630
  FL[2] = (ecx & (u32)(8192));  // @348_65a630
  if (FL[2] == 0) goto L65aa48;  // @349_65a630
  FL[2] = (edx & edx);  // @350_65a630
  if (FL[2] == 0) goto L65ae2c;  // @351_65a630
  eax = (u32)(8463940);  // @352_65a630
  ecx = edx;  // @353_65a630
  L65aa10:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 52) + 0), 4); v; });  // @355_65a630
  X0[1] = 0;  // @356_65a630
  X0[2] = 0;  // @357_65a630
  X0[3] = 0;  // @358_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 4) + 0), 4); v; })));  // @359_65a630
  __builtin_memcpy((void *)((u32)(eax - 4) + 0), &X0[0], 4);  // @360_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 48) + 0), 4); v; });  // @361_65a630
  X0[1] = 0;  // @362_65a630
  X0[2] = 0;  // @363_65a630
  X0[3] = 0;  // @364_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @365_65a630
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @366_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 44) + 0), 4); v; });  // @367_65a630
  X0[1] = 0;  // @368_65a630
  X0[2] = 0;  // @369_65a630
  X0[3] = 0;  // @370_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @371_65a630
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X0[0], 4);  // @372_65a630
  eax = (eax + (u32)(16));  // @373_65a630
  FL[3] = eax;  // @374_65a630
  ecx = (ecx - (u32)(1));  // @375_65a630
  FL[3] = ecx;  // @376_65a630
  if (FL[3] != 0) goto L65aa10;  // @377_65a630
  goto L65ae29;  // @378_65a630
  L65aa48:;
  FL[2] = (ecx & (u32)(16777216));  // @380_65a630
  if (FL[2] == 0) goto L65aac4;  // @381_65a630
  FL[2] = (edx & edx);  // @382_65a630
  if (FL[2] == 0) goto L65ae2c;  // @383_65a630
  eax = 0;  // @384_65a630
  FL[3] = eax;  // @385_65a630
  ecx = edx;  // @386_65a630
  L65aa60:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8463424) + 0), 4); v; });  // @388_65a630
  X0[1] = 0;  // @389_65a630
  X0[2] = 0;  // @390_65a630
  X0[3] = 0;  // @391_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 52) + 0), 4); v; })));  // @392_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8463936) + 0), 4); v; })));  // @393_65a630
  __builtin_memcpy((void *)((u32)(eax + 8463936) + 0), &X0[0], 4);  // @394_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8463428) + 0), 4); v; });  // @395_65a630
  X0[1] = 0;  // @396_65a630
  X0[2] = 0;  // @397_65a630
  X0[3] = 0;  // @398_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 48) + 0), 4); v; })));  // @399_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8463940) + 0), 4); v; })));  // @400_65a630
  __builtin_memcpy((void *)((u32)(eax + 8463940) + 0), &X0[0], 4);  // @401_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8463432) + 0), 4); v; });  // @402_65a630
  X0[1] = 0;  // @403_65a630
  X0[2] = 0;  // @404_65a630
  X0[3] = 0;  // @405_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 44) + 0), 4); v; })));  // @406_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8463944) + 0), 4); v; })));  // @407_65a630
  __builtin_memcpy((void *)((u32)(eax + 8463944) + 0), &X0[0], 4);  // @408_65a630
  eax = (eax + (u32)(16));  // @409_65a630
  FL[3] = eax;  // @410_65a630
  ecx = (ecx - (u32)(1));  // @411_65a630
  FL[3] = ecx;  // @412_65a630
  if (FL[3] != 0) goto L65aa60;  // @413_65a630
  goto L65ae29;  // @414_65a630
  L65aac4:;
  FL[2] = (edx & edx);  // @416_65a630
  if (FL[2] == 0) goto L65ae2c;  // @417_65a630
  eax = (u32)(edi + 20);  // @418_65a630
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 88) + 16), &v, sizeof v); }  // @419_65a630
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 88) + 12), &v, sizeof v); }  // @420_65a630
  edi = 0;  // @421_65a630
  FL[3] = edi;  // @422_65a630
  L65aae0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 84) + 0), 4); v; });  // @424_65a630
  X0[1] = 0;  // @425_65a630
  X0[2] = 0;  // @426_65a630
  X0[3] = 0;  // @427_65a630
  edx = (u32)(esi - 52);  // @428_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 4) + 0), 4); v; })));  // @429_65a630
  PV[4] = (u32)(ecx);  // @430_65a630
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 88) + 0), 4); v; });  // @431_65a630
  X1[1] = 0;  // @432_65a630
  X1[2] = 0;  // @433_65a630
  X1[3] = 0;  // @434_65a630
  ecx = (u32)((EBP - 92) + 64);  // @435_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 8) + 0), 4); v; })));  // @436_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @437_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 80) + 0), 4); v; });  // @438_65a630
  X0[1] = 0;  // @439_65a630
  X0[2] = 0;  // @440_65a630
  X0[3] = 0;  // @441_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @442_65a630
  eax = (u32)(esi - 40);  // @443_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @444_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @445_65a630
  X0[1] = 0;  // @446_65a630
  X0[2] = 0;  // @447_65a630
  X0[3] = 0;  // @448_65a630
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @449_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @450_65a630
  PV[5] = X0[0];  // @451_65a630
  PV[6] = (u32)(eax);  // @452_65a630
  eax = ext_443ef0_fastcall4(ecx, edx, PV[6], PV[5]);  // @453_65a630
  ecx = edx = 0;  // @454_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463424) + 0), 4); v; });  // @455_65a630
  X0[1] = 0;  // @456_65a630
  X0[2] = 0;  // @457_65a630
  X0[3] = 0;  // @458_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 60) + 0), 4); v; })));  // @459_65a630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 12), sizeof v); (u32)v; });  // @460_65a630
  eax = (eax + (u32)(36));  // @461_65a630
  FL[3] = eax;  // @462_65a630
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 88) + 12), &v, sizeof v); }  // @463_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463936) + 0), 4); v; })));  // @464_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463936) + 0), &X0[0], 4);  // @465_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463428) + 0), 4); v; });  // @466_65a630
  X0[1] = 0;  // @467_65a630
  X0[2] = 0;  // @468_65a630
  X0[3] = 0;  // @469_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 64) + 0), 4); v; })));  // @470_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463940) + 0), 4); v; })));  // @471_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463940) + 0), &X0[0], 4);  // @472_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463432) + 0), 4); v; });  // @473_65a630
  X0[1] = 0;  // @474_65a630
  X0[2] = 0;  // @475_65a630
  X0[3] = 0;  // @476_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 68) + 0), 4); v; })));  // @477_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463944) + 0), 4); v; })));  // @478_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463944) + 0), &X0[0], 4);  // @479_65a630
  edi = (edi + (u32)(16));  // @480_65a630
  FL[3] = edi;  // @481_65a630
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 16), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)((EBP - 88) + 16), &v, sizeof v); }  // @482_65a630
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 16), sizeof v); (u32)v; });  // @483_65a630
  if (FL[3] != 0) goto L65aae0;  // @484_65a630
  goto L65ae25;  // @485_65a630
  L65aba7:;
  FL[2] = (ecx & (u32)(8192));  // @487_65a630
  if (FL[2] == 0) goto L65abb9;  // @488_65a630
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi - 104), sizeof v); (u32)v; }) & (u32)(1));  // @489_65a630
  if (FL[2] == 0) goto L65ae2c;  // @490_65a630
  L65abb9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @492_65a630
  FL[2] = (edx & edx);  // @493_65a630
  if (FL[2] == 0) goto L65ae2c;  // @494_65a630
  eax = (u32)(edi + 20);  // @495_65a630
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 88) + 12), &v, sizeof v); }  // @496_65a630
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 88) + 8), &v, sizeof v); }  // @497_65a630
  edi = 0;  // @498_65a630
  FL[3] = edi;  // @499_65a630
  L65abd1:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 8), sizeof v); (u32)v; });  // @501_65a630
  eax = (u32)(esi - 100);  // @502_65a630
  PV[7] = (u32)(eax);  // @503_65a630
  ecx = (u32)((EBP - 92) + 36);  // @504_65a630
  edx = (u32)(edx - 20);  // @505_65a630
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @506_65a630
  ecx = edx = 0;  // @507_65a630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 8), sizeof v); (u32)v; });  // @508_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 4) + 0), 4); v; });  // @509_65a630
  X0[1] = 0;  // @510_65a630
  X0[2] = 0;  // @511_65a630
  X0[3] = 0;  // @512_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 36) + 0), 4); v; })));  // @513_65a630
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 8) + 0), 4); v; });  // @514_65a630
  X1[1] = 0;  // @515_65a630
  X1[2] = 0;  // @516_65a630
  X1[3] = 0;  // @517_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 32) + 0), 4); v; })));  // @518_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @519_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @520_65a630
  X0[1] = 0;  // @521_65a630
  X0[2] = 0;  // @522_65a630
  X0[3] = 0;  // @523_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 40) + 0), 4); v; })));  // @524_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @525_65a630
  X0[0] = 0;  // @526_65a630
  X0[1] = 0;  // @527_65a630
  X0[2] = 0;  // @528_65a630
  X0[3] = 0;  // @529_65a630
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @530_65a630
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @531_65a630
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @532_65a630
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @533_65a630
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @534_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 28) + 0), &X1[0], 4);  // @535_65a630
  if ((!(!(FC0 >= FC1)))) goto L65ae10;  // @536_65a630
  edx = (u32)(esi - 88);  // @537_65a630
  ecx = (u32)((EBP - 88) + 32);  // @538_65a630
  eax = ext_441a60_fastcall2(ecx, edx);  // @539_65a630
  ecx = edx = 0;  // @540_65a630
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 40) + 0), 4); v; });  // @541_65a630
  X2[1] = 0;  // @542_65a630
  X2[2] = 0;  // @543_65a630
  X2[3] = 0;  // @544_65a630
  X0[0] = 0;  // @545_65a630
  X0[1] = 0;  // @546_65a630
  X0[2] = 0;  // @547_65a630
  X0[3] = 0;  // @548_65a630
  FC0 = U2F(X0[0]); FC1 = U2F(X2[0]);  // @549_65a630
  if ((!(!(FC0 >= FC1)))) goto L65ae0c;  // @550_65a630
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 32) + 0), 4); v; });  // @551_65a630
  X1[1] = 0;  // @552_65a630
  X1[2] = 0;  // @553_65a630
  X1[3] = 0;  // @554_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 36) + 0), 4); v; });  // @555_65a630
  X0[1] = 0;  // @556_65a630
  X0[2] = 0;  // @557_65a630
  X0[3] = 0;  // @558_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @559_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @560_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @561_65a630
  X0[0] = X2[0];  // @562_65a630
  X0[1] = X2[1];  // @563_65a630
  X0[2] = X2[2];  // @564_65a630
  X0[3] = X2[3];  // @565_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @566_65a630
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @567_65a630
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @568_65a630
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @569_65a630
  ecx = edx = 0;  // @570_65a630
  X1[0] = 0;  // @571_65a630
  X1[1] = 0;  // @572_65a630
  X1[2] = 0;  // @573_65a630
  X1[3] = 0;  // @574_65a630
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @575_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 4) + 0), 4); v; });  // @576_65a630
  X0[1] = 0;  // @577_65a630
  X0[2] = 0;  // @578_65a630
  X0[3] = 0;  // @579_65a630
  FC0 = U2F(X1[0]); FC1 = U2F(X0[0]);  // @580_65a630
  if ((!(!(FC0 >= FC1)) && !(!((FC0 < FC1) || (FC0 > FC1))))) goto L65ae0c;  // @581_65a630
  FC0 = U2F(X1[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 12) + 0), 4); v; }));  // @582_65a630
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L65ac99;  // @583_65a630
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @584_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @585_65a630
  goto L65aca1;  // @586_65a630
  L65ac99:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @588_65a630
  X0[1] = 0;  // @589_65a630
  X0[2] = 0;  // @590_65a630
  X0[3] = 0;  // @591_65a630
  L65aca1:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 28) + 0), 4); v; });  // @593_65a630
  X3[1] = 0;  // @594_65a630
  X3[2] = 0;  // @595_65a630
  X3[3] = 0;  // @596_65a630
  X3[0] = F2U(U2F(X3[0]) / U2F(X1[0]));  // @597_65a630
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @598_65a630
  X4[1] = 0;  // @599_65a630
  X4[2] = 0;  // @600_65a630
  X4[3] = 0;  // @601_65a630
  X3[0] = F2U(U2F(X3[0]) * U2F(X0[0]));  // @602_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @603_65a630
  X0[1] = 0;  // @604_65a630
  X0[2] = 0;  // @605_65a630
  X0[3] = 0;  // @606_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 32) + 0), 4); v; })));  // @607_65a630
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 40) + 0), 4); v; })));  // @608_65a630
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @609_65a630
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @610_65a630
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @611_65a630
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @612_65a630
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @613_65a630
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @614_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @615_65a630
  X0[1] = 0;  // @616_65a630
  X0[2] = 0;  // @617_65a630
  X0[3] = 0;  // @618_65a630
  FC0 = U2F(X1[0]); FC1 = U2F(X4[0]);  // @619_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 36) + 0), 4); v; })));  // @620_65a630
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 40) + 0), 4); v; })));  // @621_65a630
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @622_65a630
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @623_65a630
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @624_65a630
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @625_65a630
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @626_65a630
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @627_65a630
  if ((!(!(FC0 >= FC1)) && !(!((FC0 < FC1) || (FC0 > FC1))))) goto L65ae0c;  // @628_65a630
  FC0 = U2F(X0[0]); FC1 = U2F(X4[0]);  // @629_65a630
  if ((!(!(FC0 >= FC1)) && !(!((FC0 < FC1) || (FC0 > FC1))))) goto L65ae0c;  // @630_65a630
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 32) + 0), 4); v; });  // @631_65a630
  X2[1] = 0;  // @632_65a630
  X2[2] = 0;  // @633_65a630
  X2[3] = 0;  // @634_65a630
  eax = 0;  // @635_65a630
  FL[3] = eax;  // @636_65a630
  FC0 = U2F(X1[0]); FC1 = U2F(X2[0]);  // @637_65a630
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L65ad21;  // @638_65a630
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @639_65a630
  eax = (u32)(1);  // @640_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; })));  // @641_65a630
  L65ad21:;
  FC0 = U2F(X0[0]); FC1 = U2F(X2[0]);  // @643_65a630
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L65ad32;  // @644_65a630
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @645_65a630
  eax = (eax | (u32)(2));  // @646_65a630
  FL[3] = eax;  // @647_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; })));  // @648_65a630
  L65ad32:;
  FL[0] = eax; FL[1] = (u32)(3);  // @650_65a630
  if (FL[0] > FL[1]) goto L65ad81;  // @651_65a630
  switch (eax) {  // @652_65a630
  case 0: goto L65ad3e;  // @653_65a630
  case 1: goto L65ad49;  // @654_65a630
  case 2: goto L65ad58;  // @655_65a630
  case 3: goto L65ad67;  // @656_65a630
  default: __builtin_trap(); }  // @657_65a630
  L65ad3e:;
  X2[0] = X4[0];  // @659_65a630
  X2[1] = X4[1];  // @660_65a630
  X2[2] = X4[2];  // @661_65a630
  X2[3] = X4[3];  // @662_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 20) + 0), &X2[0], 4);  // @663_65a630
  goto L65ad87;  // @664_65a630
  L65ad49:;
  X2[0] = X4[0];  // @666_65a630
  X2[1] = X4[1];  // @667_65a630
  X2[2] = X4[2];  // @668_65a630
  X2[3] = X4[3];  // @669_65a630
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @670_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 20) + 0), &X2[0], 4);  // @671_65a630
  goto L65ad87;  // @672_65a630
  L65ad58:;
  X2[0] = X4[0];  // @674_65a630
  X2[1] = X4[1];  // @675_65a630
  X2[2] = X4[2];  // @676_65a630
  X2[3] = X4[3];  // @677_65a630
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @678_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 20) + 0), &X2[0], 4);  // @679_65a630
  goto L65ad87;  // @680_65a630
  L65ad67:;
  X2[0] = X4[0];  // @682_65a630
  X2[1] = X4[1];  // @683_65a630
  X2[2] = X4[2];  // @684_65a630
  X2[3] = X4[3];  // @685_65a630
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @686_65a630
  X0[0] = X4[0];  // @687_65a630
  X0[1] = X4[1];  // @688_65a630
  X0[2] = X4[2];  // @689_65a630
  X0[3] = X4[3];  // @690_65a630
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @691_65a630
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @692_65a630
  __builtin_memcpy((void *)((u32)((EBP - 88) + 20) + 0), &X2[0], 4);  // @693_65a630
  goto L65ad87;  // @694_65a630
  L65ad81:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 88) + 20) + 0), 4); v; });  // @696_65a630
  X2[1] = 0;  // @697_65a630
  X2[2] = 0;  // @698_65a630
  X2[3] = 0;  // @699_65a630
  L65ad87:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; });  // @701_65a630
  X1[1] = 0;  // @702_65a630
  X1[2] = 0;  // @703_65a630
  X1[3] = 0;  // @704_65a630
  X0[0] = X2[0];  // @705_65a630
  X0[1] = X2[1];  // @706_65a630
  X0[2] = X2[2];  // @707_65a630
  X0[3] = X2[3];  // @708_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @709_65a630
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @710_65a630
  X0[0] = X2[0];  // @711_65a630
  X0[1] = X2[1];  // @712_65a630
  X0[2] = X2[2];  // @713_65a630
  X0[3] = X2[3];  // @714_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @715_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @716_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463424) + 0), 4); v; });  // @717_65a630
  X0[1] = 0;  // @718_65a630
  X0[2] = 0;  // @719_65a630
  X0[3] = 0;  // @720_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 52) + 0), 4); v; })));  // @721_65a630
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @722_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @723_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463936) + 0), 4); v; })));  // @724_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463936) + 0), &X0[0], 4);  // @725_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463428) + 0), 4); v; });  // @726_65a630
  X0[1] = 0;  // @727_65a630
  X0[2] = 0;  // @728_65a630
  X0[3] = 0;  // @729_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 48) + 0), 4); v; })));  // @730_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @731_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463940) + 0), 4); v; })));  // @732_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463940) + 0), &X0[0], 4);  // @733_65a630
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463432) + 0), 4); v; });  // @734_65a630
  X0[1] = 0;  // @735_65a630
  X0[2] = 0;  // @736_65a630
  X0[3] = 0;  // @737_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi - 44) + 0), 4); v; })));  // @738_65a630
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @739_65a630
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8463944) + 0), 4); v; })));  // @740_65a630
  __builtin_memcpy((void *)((u32)(edi + 8463944) + 0), &X0[0], 4);  // @741_65a630
  L65ae0c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 8), sizeof v); (u32)v; });  // @743_65a630
  L65ae10:;
  eax = (eax + (u32)(36));  // @745_65a630
  FL[3] = eax;  // @746_65a630
  edi = (edi + (u32)(16));  // @747_65a630
  FL[3] = edi;  // @748_65a630
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 12), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)((EBP - 88) + 12), &v, sizeof v); }  // @749_65a630
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 12), sizeof v); (u32)v; });  // @750_65a630
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 88) + 8), &v, sizeof v); }  // @751_65a630
  if (FL[3] != 0) goto L65abd1;  // @752_65a630
  L65ae25:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 24), sizeof v); (u32)v; });  // @754_65a630
  L65ae29:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @756_65a630
  L65ae2c:;
  esi = (esi + (u32)(576));  // @758_65a630
  FL[3] = esi;  // @759_65a630
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @760_65a630
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @761_65a630
  if (FL[3] != 0) goto L65a663;  // @762_65a630
  L65ae3c:;
  ext_633654(G(u32, 0x6f5630));  // @764_65a630
  return eax;  // @765_65a630
}
PCREG(65a630, lifted_65a630);

