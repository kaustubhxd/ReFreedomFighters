// batch252001.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634db8_dbl(double) __asm__("ext_634db8");
extern "C" double VECTORCALL ext_634de8_dbl(double) __asm__("ext_634de8");
extern "C" u32 THISCALL ext_539ca0_thiscall1(u32) __asm__("ext_539ca0");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 FASTCALL lifted_539eb0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @0_539eb0
  edi = edx;  // @1_539eb0
  ebx = ecx;  // @2_539eb0
  if (FL[0] == FL[1]) goto L539ee5;  // @3_539eb0
  eax = ext_539ca0_thiscall1(ecx);  // @4_539eb0
    // @5_539eb0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @6_539eb0
  if (FL[2] != 0) goto L539eda;  // @7_539eb0
  L539ecf:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @9_539eb0
  FL[3] = (eax & 0xff);  // @10_539eb0
  return eax;  // @11_539eb0
  L539eda:;
  ecx = edi;  // @13_539eb0
  eax = ext_539ca0_thiscall1(ecx);  // @14_539eb0
    // @15_539eb0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @16_539eb0
  if (FL[2] == 0) goto L539ecf;  // @17_539eb0
  L539ee5:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @19_539eb0
  X1[1] = 0;  // @20_539eb0
  X1[2] = 0;  // @21_539eb0
  X1[3] = 0;  // @22_539eb0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @23_539eb0
  X3[1] = 0;  // @24_539eb0
  X3[2] = 0;  // @25_539eb0
  X3[3] = 0;  // @26_539eb0
  FA = U2F(X3[0]); FB = U2F(X1[0]);  // @27_539eb0
  if ((!(FA >= FB))) goto L539f0e;  // @28_539eb0
  esi = edi;  // @29_539eb0
  ecx = (u32)(28);  // @30_539eb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_539eb0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @32_539eb0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @33_539eb0
  return eax;  // @34_539eb0
  L539f0e:;
  X0[0] = 0;  // @36_539eb0
  X0[1] = 0;  // @37_539eb0
  X0[2] = 0;  // @38_539eb0
  X0[3] = 0;  // @39_539eb0
  FA = U2F(X0[0]); FB = U2F(X3[0]);  // @40_539eb0
  if ((!(FA >= FB))) goto L539f2d;  // @41_539eb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @42_539eb0
  ecx = (u32)(28);  // @43_539eb0
  esi = ebx;  // @44_539eb0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @45_539eb0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @46_539eb0
  return eax;  // @47_539eb0
  L539f2d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @49_539eb0
  X2[0] = X1[0];  // @50_539eb0
  X2[1] = X1[1];  // @51_539eb0
  X2[2] = X1[2];  // @52_539eb0
  X2[3] = X1[3];  // @53_539eb0
  X2[0] = F2U(U2F(X2[0]) - U2F(X3[0]));  // @54_539eb0
  { u32 v = (u32)((u32)(26)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @55_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @56_539eb0
  X0[1] = 0;  // @57_539eb0
  X0[2] = 0;  // @58_539eb0
  X0[3] = 0;  // @59_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; }));  // @60_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 12) + 0), &X2[0], 4);  // @61_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @62_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @63_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L539fa0;  // @64_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @65_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @66_539eb0
  ecx = edx = 0;  // @67_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @68_539eb0
  X1[1] = 0;  // @69_539eb0
  X1[2] = 0;  // @70_539eb0
  X1[3] = 0;  // @71_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @72_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @73_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @74_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @75_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @76_539eb0
  X0[1] = 0;  // @77_539eb0
  X0[2] = 0;  // @78_539eb0
  X0[3] = 0;  // @79_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @80_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @81_539eb0
  ecx = edx = 0;  // @82_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @83_539eb0
  X1[1] = 0;  // @84_539eb0
  X1[2] = 0;  // @85_539eb0
  X1[3] = 0;  // @86_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @87_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @88_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @89_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @90_539eb0
  ecx = edx = 0;  // @91_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @92_539eb0
  X2[1] = 0;  // @93_539eb0
  X2[2] = 0;  // @94_539eb0
  X2[3] = 0;  // @95_539eb0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @96_539eb0
  X3[1] = 0;  // @97_539eb0
  X3[2] = 0;  // @98_539eb0
  X3[3] = 0;  // @99_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @100_539eb0
  L539fa0:;
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @102_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @103_539eb0
  X0[1] = 0;  // @104_539eb0
  X0[2] = 0;  // @105_539eb0
  X0[3] = 0;  // @106_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @107_539eb0
  X1[1] = 0;  // @108_539eb0
  X1[2] = 0;  // @109_539eb0
  X1[3] = 0;  // @110_539eb0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @111_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @112_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @113_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L539fc4;  // @114_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @115_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @116_539eb0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @117_539eb0
  L539fc4:;
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @119_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @120_539eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @121_539eb0
  FL[0] = eax; FL[1] = ecx;  // @122_539eb0
  if (FL[0] == FL[1]) goto L539ff1;  // @123_539eb0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @124_539eb0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @125_539eb0
  X1[0] = F2U((float)(s32)X1[0]);  // @126_539eb0
  X1[1] = F2U((float)(s32)X1[1]);  // @127_539eb0
  X1[2] = F2U((float)(s32)X1[2]);  // @128_539eb0
  X1[3] = F2U((float)(s32)X1[3]);  // @129_539eb0
  X0[0] = F2U((float)(s32)X0[0]);  // @130_539eb0
  X0[1] = F2U((float)(s32)X0[1]);  // @131_539eb0
  X0[2] = F2U((float)(s32)X0[2]);  // @132_539eb0
  X0[3] = F2U((float)(s32)X0[3]);  // @133_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @134_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @135_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @136_539eb0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @137_539eb0
  L539ff1:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @139_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @140_539eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @141_539eb0
  FL[0] = eax; FL[1] = ecx;  // @142_539eb0
  if (FL[0] == FL[1]) goto L53a01c;  // @143_539eb0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @144_539eb0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @145_539eb0
  X1[0] = F2U((float)(s32)X1[0]);  // @146_539eb0
  X1[1] = F2U((float)(s32)X1[1]);  // @147_539eb0
  X1[2] = F2U((float)(s32)X1[2]);  // @148_539eb0
  X1[3] = F2U((float)(s32)X1[3]);  // @149_539eb0
  X0[0] = F2U((float)(s32)X0[0]);  // @150_539eb0
  X0[1] = F2U((float)(s32)X0[1]);  // @151_539eb0
  X0[2] = F2U((float)(s32)X0[2]);  // @152_539eb0
  X0[3] = F2U((float)(s32)X0[3]);  // @153_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @154_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @155_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @156_539eb0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @157_539eb0
  L53a01c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @159_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @160_539eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @161_539eb0
  FL[0] = eax; FL[1] = ecx;  // @162_539eb0
  if (FL[0] == FL[1]) goto L53a047;  // @163_539eb0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @164_539eb0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @165_539eb0
  X1[0] = F2U((float)(s32)X1[0]);  // @166_539eb0
  X1[1] = F2U((float)(s32)X1[1]);  // @167_539eb0
  X1[2] = F2U((float)(s32)X1[2]);  // @168_539eb0
  X1[3] = F2U((float)(s32)X1[3]);  // @169_539eb0
  X0[0] = F2U((float)(s32)X0[0]);  // @170_539eb0
  X0[1] = F2U((float)(s32)X0[1]);  // @171_539eb0
  X0[2] = F2U((float)(s32)X0[2]);  // @172_539eb0
  X0[3] = F2U((float)(s32)X0[3]);  // @173_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @174_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @175_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @176_539eb0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @177_539eb0
  L53a047:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @179_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 24) + 0), 4); v; });  // @180_539eb0
  X0[1] = 0;  // @181_539eb0
  X0[2] = 0;  // @182_539eb0
  X0[3] = 0;  // @183_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; }));  // @184_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @185_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @186_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a09c;  // @187_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @188_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @189_539eb0
  ecx = edx = 0;  // @190_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @191_539eb0
  X1[1] = 0;  // @192_539eb0
  X1[2] = 0;  // @193_539eb0
  X1[3] = 0;  // @194_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @195_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @196_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @197_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @198_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @199_539eb0
  X0[1] = 0;  // @200_539eb0
  X0[2] = 0;  // @201_539eb0
  X0[3] = 0;  // @202_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @203_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @204_539eb0
  ecx = edx = 0;  // @205_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @206_539eb0
  X1[1] = 0;  // @207_539eb0
  X1[2] = 0;  // @208_539eb0
  X1[3] = 0;  // @209_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @210_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @211_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @212_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @213_539eb0
  ecx = edx = 0;  // @214_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @215_539eb0
  L53a09c:;
  __builtin_memcpy((void *)((u32)(esi + 24) + 0), &X0[0], 4);  // @217_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 28) + 0), 4); v; });  // @218_539eb0
  X0[1] = 0;  // @219_539eb0
  X0[2] = 0;  // @220_539eb0
  X0[3] = 0;  // @221_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; }));  // @222_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @223_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @224_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a0f3;  // @225_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @226_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @227_539eb0
  ecx = edx = 0;  // @228_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @229_539eb0
  X1[1] = 0;  // @230_539eb0
  X1[2] = 0;  // @231_539eb0
  X1[3] = 0;  // @232_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @233_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @234_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @235_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @236_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; });  // @237_539eb0
  X0[1] = 0;  // @238_539eb0
  X0[2] = 0;  // @239_539eb0
  X0[3] = 0;  // @240_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @241_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @242_539eb0
  ecx = edx = 0;  // @243_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @244_539eb0
  X1[1] = 0;  // @245_539eb0
  X1[2] = 0;  // @246_539eb0
  X1[3] = 0;  // @247_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @248_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @249_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @250_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @251_539eb0
  ecx = edx = 0;  // @252_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @253_539eb0
  L53a0f3:;
  __builtin_memcpy((void *)((u32)(esi + 28) + 0), &X0[0], 4);  // @255_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 32) + 0), 4); v; });  // @256_539eb0
  X0[1] = 0;  // @257_539eb0
  X0[2] = 0;  // @258_539eb0
  X0[3] = 0;  // @259_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 32) + 0), 4); v; }));  // @260_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @261_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @262_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a14a;  // @263_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @264_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @265_539eb0
  ecx = edx = 0;  // @266_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @267_539eb0
  X1[1] = 0;  // @268_539eb0
  X1[2] = 0;  // @269_539eb0
  X1[3] = 0;  // @270_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @271_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @272_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @273_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @274_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 32) + 0), 4); v; });  // @275_539eb0
  X0[1] = 0;  // @276_539eb0
  X0[2] = 0;  // @277_539eb0
  X0[3] = 0;  // @278_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @279_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @280_539eb0
  ecx = edx = 0;  // @281_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @282_539eb0
  X1[1] = 0;  // @283_539eb0
  X1[2] = 0;  // @284_539eb0
  X1[3] = 0;  // @285_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @286_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @287_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @288_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @289_539eb0
  ecx = edx = 0;  // @290_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @291_539eb0
  L53a14a:;
  __builtin_memcpy((void *)((u32)(esi + 32) + 0), &X0[0], 4);  // @293_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; });  // @294_539eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @295_539eb0
  FL[0] = eax; FL[1] = ecx;  // @296_539eb0
  if (FL[0] == FL[1]) goto L53a17a;  // @297_539eb0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @298_539eb0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @299_539eb0
  X1[0] = F2U((float)(s32)X1[0]);  // @300_539eb0
  X1[1] = F2U((float)(s32)X1[1]);  // @301_539eb0
  X1[2] = F2U((float)(s32)X1[2]);  // @302_539eb0
  X1[3] = F2U((float)(s32)X1[3]);  // @303_539eb0
  X0[0] = F2U((float)(s32)X0[0]);  // @304_539eb0
  X0[1] = F2U((float)(s32)X0[1]);  // @305_539eb0
  X0[2] = F2U((float)(s32)X0[2]);  // @306_539eb0
  X0[3] = F2U((float)(s32)X0[3]);  // @307_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; })));  // @308_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })));  // @309_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @310_539eb0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @311_539eb0
  L53a17a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @313_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 40) + 0), 4); v; });  // @314_539eb0
  X0[1] = 0;  // @315_539eb0
  X0[2] = 0;  // @316_539eb0
  X0[3] = 0;  // @317_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 40) + 0), 4); v; }));  // @318_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @319_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @320_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a1df;  // @321_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @322_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957816) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957816) + 4), 4); v; })));  // @323_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @324_539eb0
  ecx = edx = 0;  // @325_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @326_539eb0
  X1[1] = 0;  // @327_539eb0
  X1[2] = 0;  // @328_539eb0
  X1[3] = 0;  // @329_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @330_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @331_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @332_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @333_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 40) + 0), 4); v; });  // @334_539eb0
  X0[1] = 0;  // @335_539eb0
  X0[2] = 0;  // @336_539eb0
  X0[3] = 0;  // @337_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @338_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957816) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957816) + 4), 4); v; })));  // @339_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @340_539eb0
  ecx = edx = 0;  // @341_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @342_539eb0
  X1[1] = 0;  // @343_539eb0
  X1[2] = 0;  // @344_539eb0
  X1[3] = 0;  // @345_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @346_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @347_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @348_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @349_539eb0
  ecx = edx = 0;  // @350_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @351_539eb0
  L53a1df:;
  __builtin_memcpy((void *)((u32)(esi + 40) + 0), &X0[0], 4);  // @353_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 44) + 0), 4); v; });  // @354_539eb0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 44) + 4), 4); v; });  // @355_539eb0
  X0[2] = 0;  // @356_539eb0
  X0[3] = 0;  // @357_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 52), sizeof v); (u32)v; });  // @358_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 44) + 0), &X0[0], 4);  // @359_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 44) + 4), &X0[1], 4);  // @360_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 0), 4); v; });  // @361_539eb0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 4), 4); v; });  // @362_539eb0
  X0[2] = 0;  // @363_539eb0
  X0[3] = 0;  // @364_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 44) + 0), 4); v; });  // @365_539eb0
  X2[1] = 0;  // @366_539eb0
  X2[2] = 0;  // @367_539eb0
  X2[3] = 0;  // @368_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 32) + 0), &X0[0], 4);  // @369_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 32) + 4), &X0[1], 4);  // @370_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 48) + 0), 4); v; });  // @371_539eb0
  X0[1] = 0;  // @372_539eb0
  X0[2] = 0;  // @373_539eb0
  X0[3] = 0;  // @374_539eb0
  X1[0] = X0[0];  // @375_539eb0
  X1[1] = X0[1];  // @376_539eb0
  X1[2] = X0[2];  // @377_539eb0
  X1[3] = X0[3];  // @378_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 20) + 0), &X0[0], 4);  // @379_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @380_539eb0
  X0[0] = X2[0];  // @381_539eb0
  X0[1] = X2[1];  // @382_539eb0
  X0[2] = X2[2];  // @383_539eb0
  X0[3] = X2[3];  // @384_539eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 56) + 52), &v, sizeof v); }  // @385_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @386_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @387_539eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 56) + 40), &v, sizeof v); }  // @388_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 16) + 0), &X2[0], 4);  // @389_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 52) + 0), 4); v; });  // @390_539eb0
  X2[1] = 0;  // @391_539eb0
  X2[2] = 0;  // @392_539eb0
  X2[3] = 0;  // @393_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @394_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X2[0], 4);  // @395_539eb0
  X0[0] = X2[0];  // @396_539eb0
  X0[1] = X2[1];  // @397_539eb0
  X0[2] = X2[2];  // @398_539eb0
  X0[3] = X2[3];  // @399_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @400_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @401_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @402_539eb0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @403_539eb0
  ecx = edx = 0;  // @404_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @405_539eb0
  X1[1] = 0;  // @406_539eb0
  X1[2] = 0;  // @407_539eb0
  X1[3] = 0;  // @408_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @409_539eb0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @410_539eb0
  if ((!(!(FA >= FB)))) goto L53a299;  // @411_539eb0
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @412_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 44) + 0), 4); v; });  // @413_539eb0
  X2[1] = 0;  // @414_539eb0
  X2[2] = 0;  // @415_539eb0
  X2[3] = 0;  // @416_539eb0
  X0[0] = X1[0];  // @417_539eb0
  X0[1] = X1[1];  // @418_539eb0
  X0[2] = X1[2];  // @419_539eb0
  X0[3] = X1[3];  // @420_539eb0
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @421_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 16) + 0), &X2[0], 4);  // @422_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 48) + 0), 4); v; });  // @423_539eb0
  X2[1] = 0;  // @424_539eb0
  X2[2] = 0;  // @425_539eb0
  X2[3] = 0;  // @426_539eb0
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @427_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 52) + 0), 4); v; });  // @428_539eb0
  X0[1] = 0;  // @429_539eb0
  X0[2] = 0;  // @430_539eb0
  X0[3] = 0;  // @431_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @432_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 20) + 0), &X2[0], 4);  // @433_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @434_539eb0
  L53a299:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 36) + 0), 4); v; });  // @436_539eb0
  X1[1] = 0;  // @437_539eb0
  X1[2] = 0;  // @438_539eb0
  X1[3] = 0;  // @439_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 32) + 0), 4); v; });  // @440_539eb0
  X0[1] = 0;  // @441_539eb0
  X0[2] = 0;  // @442_539eb0
  X0[3] = 0;  // @443_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @444_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @445_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @446_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 40) + 0), 4); v; });  // @447_539eb0
  X0[1] = 0;  // @448_539eb0
  X0[2] = 0;  // @449_539eb0
  X0[3] = 0;  // @450_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @451_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @452_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @453_539eb0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @454_539eb0
  ecx = edx = 0;  // @455_539eb0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 36) + 0), 4); v; });  // @456_539eb0
  X3[1] = 0;  // @457_539eb0
  X3[2] = 0;  // @458_539eb0
  X3[3] = 0;  // @459_539eb0
  X2[0] = 0;  // @460_539eb0
  X2[1] = 0;  // @461_539eb0
  X2[2] = 0;  // @462_539eb0
  X2[3] = 0;  // @463_539eb0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 40) + 0), 4); v; });  // @464_539eb0
  X4[1] = 0;  // @465_539eb0
  X4[2] = 0;  // @466_539eb0
  X4[3] = 0;  // @467_539eb0
  X2[0] = F2U((float)U2D(X0[0], X0[1]));  // @468_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @469_539eb0
  X0[1] = 0;  // @470_539eb0
  X0[2] = 0;  // @471_539eb0
  X0[3] = 0;  // @472_539eb0
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @473_539eb0
  if ((!(!(FA >= FB)))) goto L53a304;  // @474_539eb0
  X1[0] = X0[0];  // @475_539eb0
  X1[1] = X0[1];  // @476_539eb0
  X1[2] = X0[2];  // @477_539eb0
  X1[3] = X0[3];  // @478_539eb0
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @479_539eb0
  X2[0] = X1[0];  // @480_539eb0
  X2[1] = X1[1];  // @481_539eb0
  X2[2] = X1[2];  // @482_539eb0
  X2[3] = X1[3];  // @483_539eb0
  X4[0] = F2U(U2F(X4[0]) * U2F(X1[0]));  // @484_539eb0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 32) + 0), 4); v; })));  // @485_539eb0
  X0[0] = X1[0];  // @486_539eb0
  X0[1] = X1[1];  // @487_539eb0
  X0[2] = X1[2];  // @488_539eb0
  X0[3] = X1[3];  // @489_539eb0
  X3[0] = F2U(U2F(X3[0]) * U2F(X0[0]));  // @490_539eb0
  goto L53a30a;  // @491_539eb0
  L53a304:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 32) + 0), 4); v; });  // @493_539eb0
  X2[1] = 0;  // @494_539eb0
  X2[2] = 0;  // @495_539eb0
  X2[3] = 0;  // @496_539eb0
  L53a30a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 44) + 0), 4); v; });  // @498_539eb0
  X0[1] = 0;  // @499_539eb0
  X0[2] = 0;  // @500_539eb0
  X0[3] = 0;  // @501_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 0), 4); v; }));  // @502_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @503_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @504_539eb0
  if (!__builtin_parity(FL[2] & 0xff)) goto L53a326;  // @505_539eb0
  __builtin_memcpy((void *)((u32)(esi + 44) + 0), &X0[0], 4);  // @506_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @507_539eb0
  X0[1] = 0;  // @508_539eb0
  X0[2] = 0;  // @509_539eb0
  X0[3] = 0;  // @510_539eb0
  goto L53a343;  // @511_539eb0
  L53a326:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 16) + 0), 4); v; });  // @513_539eb0
  X1[1] = 0;  // @514_539eb0
  X1[2] = 0;  // @515_539eb0
  X1[3] = 0;  // @516_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @517_539eb0
  X0[1] = 0;  // @518_539eb0
  X0[2] = 0;  // @519_539eb0
  X0[3] = 0;  // @520_539eb0
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @521_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @522_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @523_539eb0
  __builtin_memcpy((void *)((u32)(esi + 44) + 0), &X1[0], 4);  // @524_539eb0
  L53a343:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 48) + 0), 4); v; });  // @526_539eb0
  X1[1] = 0;  // @527_539eb0
  X1[2] = 0;  // @528_539eb0
  X1[3] = 0;  // @529_539eb0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 48) + 0), 4); v; }));  // @530_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @531_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @532_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a364;  // @533_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 20) + 0), 4); v; });  // @534_539eb0
  X1[1] = 0;  // @535_539eb0
  X1[2] = 0;  // @536_539eb0
  X1[3] = 0;  // @537_539eb0
  X1[0] = F2U(U2F(X1[0]) - U2F(X3[0]));  // @538_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @539_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X3[0]));  // @540_539eb0
  L53a364:;
  __builtin_memcpy((void *)((u32)(esi + 48) + 0), &X1[0], 4);  // @542_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 52) + 0), 4); v; });  // @543_539eb0
  X1[1] = 0;  // @544_539eb0
  X1[2] = 0;  // @545_539eb0
  X1[3] = 0;  // @546_539eb0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 52) + 0), 4); v; }));  // @547_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @548_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @549_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a38a;  // @550_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; });  // @551_539eb0
  X1[1] = 0;  // @552_539eb0
  X1[2] = 0;  // @553_539eb0
  X1[3] = 0;  // @554_539eb0
  X1[0] = F2U(U2F(X1[0]) - U2F(X4[0]));  // @555_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @556_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X4[0]));  // @557_539eb0
  L53a38a:;
  __builtin_memcpy((void *)((u32)(esi + 52) + 0), &X1[0], 4);  // @559_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 56), sizeof v); (u32)v; });  // @560_539eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 56), sizeof v); (u32)v; });  // @561_539eb0
  FL[0] = eax; FL[1] = ecx;  // @562_539eb0
  if (FL[0] == FL[1]) goto L53a3b8;  // @563_539eb0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @564_539eb0
  X1[0] = F2U((float)(s32)X1[0]);  // @565_539eb0
  X1[1] = F2U((float)(s32)X1[1]);  // @566_539eb0
  X1[2] = F2U((float)(s32)X1[2]);  // @567_539eb0
  X1[3] = F2U((float)(s32)X1[3]);  // @568_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @569_539eb0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @570_539eb0
  X0[0] = F2U((float)(s32)X0[0]);  // @571_539eb0
  X0[1] = F2U((float)(s32)X0[1]);  // @572_539eb0
  X0[2] = F2U((float)(s32)X0[2]);  // @573_539eb0
  X0[3] = F2U((float)(s32)X0[3]);  // @574_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })));  // @575_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @576_539eb0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @577_539eb0
  L53a3b8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @579_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 60) + 0), 4); v; });  // @580_539eb0
  X0[1] = 0;  // @581_539eb0
  X0[2] = 0;  // @582_539eb0
  X0[3] = 0;  // @583_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 60) + 0), 4); v; }));  // @584_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @585_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @586_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a41d;  // @587_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @588_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957816) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957816) + 4), 4); v; })));  // @589_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @590_539eb0
  ecx = edx = 0;  // @591_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @592_539eb0
  X1[1] = 0;  // @593_539eb0
  X1[2] = 0;  // @594_539eb0
  X1[3] = 0;  // @595_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @596_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @597_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @598_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @599_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 60) + 0), 4); v; });  // @600_539eb0
  X0[1] = 0;  // @601_539eb0
  X0[2] = 0;  // @602_539eb0
  X0[3] = 0;  // @603_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @604_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957816) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957816) + 4), 4); v; })));  // @605_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @606_539eb0
  ecx = edx = 0;  // @607_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @608_539eb0
  X1[1] = 0;  // @609_539eb0
  X1[2] = 0;  // @610_539eb0
  X1[3] = 0;  // @611_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @612_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @613_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @614_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @615_539eb0
  ecx = edx = 0;  // @616_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @617_539eb0
  L53a41d:;
  __builtin_memcpy((void *)((u32)(esi + 60) + 0), &X0[0], 4);  // @619_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 64) + 0), 4); v; });  // @620_539eb0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 64) + 4), 4); v; });  // @621_539eb0
  X0[2] = 0;  // @622_539eb0
  X0[3] = 0;  // @623_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @624_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 44) + 0), &X0[0], 4);  // @625_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 44) + 4), &X0[1], 4);  // @626_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 64) + 0), 4); v; });  // @627_539eb0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 64) + 4), 4); v; });  // @628_539eb0
  X0[2] = 0;  // @629_539eb0
  X0[3] = 0;  // @630_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 44) + 0), 4); v; });  // @631_539eb0
  X2[1] = 0;  // @632_539eb0
  X2[2] = 0;  // @633_539eb0
  X2[3] = 0;  // @634_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 32) + 0), &X0[0], 4);  // @635_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 32) + 4), &X0[1], 4);  // @636_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 48) + 0), 4); v; });  // @637_539eb0
  X0[1] = 0;  // @638_539eb0
  X0[2] = 0;  // @639_539eb0
  X0[3] = 0;  // @640_539eb0
  X1[0] = X0[0];  // @641_539eb0
  X1[1] = X0[1];  // @642_539eb0
  X1[2] = X0[2];  // @643_539eb0
  X1[3] = X0[3];  // @644_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 20) + 0), &X0[0], 4);  // @645_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @646_539eb0
  X0[0] = X2[0];  // @647_539eb0
  X0[1] = X2[1];  // @648_539eb0
  X0[2] = X2[2];  // @649_539eb0
  X0[3] = X2[3];  // @650_539eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 56) + 52), &v, sizeof v); }  // @651_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @652_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @653_539eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 56) + 40), &v, sizeof v); }  // @654_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X2[0], 4);  // @655_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 52) + 0), 4); v; });  // @656_539eb0
  X2[1] = 0;  // @657_539eb0
  X2[2] = 0;  // @658_539eb0
  X2[3] = 0;  // @659_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @660_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 16) + 0), &X2[0], 4);  // @661_539eb0
  X0[0] = X2[0];  // @662_539eb0
  X0[1] = X2[1];  // @663_539eb0
  X0[2] = X2[2];  // @664_539eb0
  X0[3] = X2[3];  // @665_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @666_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @667_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @668_539eb0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @669_539eb0
  ecx = edx = 0;  // @670_539eb0
  X2[0] = 0;  // @671_539eb0
  X2[1] = 0;  // @672_539eb0
  X2[2] = 0;  // @673_539eb0
  X2[3] = 0;  // @674_539eb0
  X2[0] = F2U((float)U2D(X0[0], X0[1]));  // @675_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @676_539eb0
  X0[1] = 0;  // @677_539eb0
  X0[2] = 0;  // @678_539eb0
  X0[3] = 0;  // @679_539eb0
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @680_539eb0
  if ((!(!(FA >= FB)))) goto L53a4dd;  // @681_539eb0
  X1[0] = X0[0];  // @682_539eb0
  X1[1] = X0[1];  // @683_539eb0
  X1[2] = X0[2];  // @684_539eb0
  X1[3] = X0[3];  // @685_539eb0
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @686_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 44) + 0), 4); v; });  // @687_539eb0
  X2[1] = 0;  // @688_539eb0
  X2[2] = 0;  // @689_539eb0
  X2[3] = 0;  // @690_539eb0
  X0[0] = X1[0];  // @691_539eb0
  X0[1] = X1[1];  // @692_539eb0
  X0[2] = X1[2];  // @693_539eb0
  X0[3] = X1[3];  // @694_539eb0
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @695_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X2[0], 4);  // @696_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 48) + 0), 4); v; });  // @697_539eb0
  X2[1] = 0;  // @698_539eb0
  X2[2] = 0;  // @699_539eb0
  X2[3] = 0;  // @700_539eb0
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @701_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 52) + 0), 4); v; });  // @702_539eb0
  X0[1] = 0;  // @703_539eb0
  X0[2] = 0;  // @704_539eb0
  X0[3] = 0;  // @705_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @706_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 20) + 0), &X2[0], 4);  // @707_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 16) + 0), &X0[0], 4);  // @708_539eb0
  L53a4dd:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 36) + 0), 4); v; });  // @710_539eb0
  X1[1] = 0;  // @711_539eb0
  X1[2] = 0;  // @712_539eb0
  X1[3] = 0;  // @713_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 32) + 0), 4); v; });  // @714_539eb0
  X0[1] = 0;  // @715_539eb0
  X0[2] = 0;  // @716_539eb0
  X0[3] = 0;  // @717_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 40) + 0), 4); v; });  // @718_539eb0
  X2[1] = 0;  // @719_539eb0
  X2[2] = 0;  // @720_539eb0
  X2[3] = 0;  // @721_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @722_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @723_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @724_539eb0
  X0[0] = X2[0];  // @725_539eb0
  X0[1] = X2[1];  // @726_539eb0
  X0[2] = X2[2];  // @727_539eb0
  X0[3] = X2[3];  // @728_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @729_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @730_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @731_539eb0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @732_539eb0
  ecx = edx = 0;  // @733_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @734_539eb0
  X1[1] = 0;  // @735_539eb0
  X1[2] = 0;  // @736_539eb0
  X1[3] = 0;  // @737_539eb0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 36) + 0), 4); v; });  // @738_539eb0
  X3[1] = 0;  // @739_539eb0
  X3[2] = 0;  // @740_539eb0
  X3[3] = 0;  // @741_539eb0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 40) + 0), 4); v; });  // @742_539eb0
  X4[1] = 0;  // @743_539eb0
  X4[2] = 0;  // @744_539eb0
  X4[3] = 0;  // @745_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @746_539eb0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @747_539eb0
  if ((!(!(FA >= FB)))) goto L53a545;  // @748_539eb0
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @749_539eb0
  X2[0] = X1[0];  // @750_539eb0
  X2[1] = X1[1];  // @751_539eb0
  X2[2] = X1[2];  // @752_539eb0
  X2[3] = X1[3];  // @753_539eb0
  X4[0] = F2U(U2F(X4[0]) * U2F(X1[0]));  // @754_539eb0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 32) + 0), 4); v; })));  // @755_539eb0
  X0[0] = X1[0];  // @756_539eb0
  X0[1] = X1[1];  // @757_539eb0
  X0[2] = X1[2];  // @758_539eb0
  X0[3] = X1[3];  // @759_539eb0
  X3[0] = F2U(U2F(X3[0]) * U2F(X0[0]));  // @760_539eb0
  goto L53a54b;  // @761_539eb0
  L53a545:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 32) + 0), 4); v; });  // @763_539eb0
  X2[1] = 0;  // @764_539eb0
  X2[2] = 0;  // @765_539eb0
  X2[3] = 0;  // @766_539eb0
  L53a54b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 64) + 0), 4); v; });  // @768_539eb0
  X0[1] = 0;  // @769_539eb0
  X0[2] = 0;  // @770_539eb0
  X0[3] = 0;  // @771_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 64) + 0), 4); v; }));  // @772_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @773_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @774_539eb0
  if (!__builtin_parity(FL[2] & 0xff)) goto L53a567;  // @775_539eb0
  __builtin_memcpy((void *)((u32)(esi + 64) + 0), &X0[0], 4);  // @776_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @777_539eb0
  X0[1] = 0;  // @778_539eb0
  X0[2] = 0;  // @779_539eb0
  X0[3] = 0;  // @780_539eb0
  goto L53a584;  // @781_539eb0
  L53a567:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; });  // @783_539eb0
  X1[1] = 0;  // @784_539eb0
  X1[2] = 0;  // @785_539eb0
  X1[3] = 0;  // @786_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @787_539eb0
  X0[1] = 0;  // @788_539eb0
  X0[2] = 0;  // @789_539eb0
  X0[3] = 0;  // @790_539eb0
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @791_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @792_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @793_539eb0
  __builtin_memcpy((void *)((u32)(esi + 64) + 0), &X1[0], 4);  // @794_539eb0
  L53a584:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 68) + 0), 4); v; });  // @796_539eb0
  X1[1] = 0;  // @797_539eb0
  X1[2] = 0;  // @798_539eb0
  X1[3] = 0;  // @799_539eb0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 68) + 0), 4); v; }));  // @800_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @801_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @802_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a5a5;  // @803_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 20) + 0), 4); v; });  // @804_539eb0
  X1[1] = 0;  // @805_539eb0
  X1[2] = 0;  // @806_539eb0
  X1[3] = 0;  // @807_539eb0
  X1[0] = F2U(U2F(X1[0]) - U2F(X3[0]));  // @808_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @809_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X3[0]));  // @810_539eb0
  L53a5a5:;
  __builtin_memcpy((void *)((u32)(esi + 68) + 0), &X1[0], 4);  // @812_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; });  // @813_539eb0
  X1[1] = 0;  // @814_539eb0
  X1[2] = 0;  // @815_539eb0
  X1[3] = 0;  // @816_539eb0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; }));  // @817_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @818_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @819_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a5cb;  // @820_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 16) + 0), 4); v; });  // @821_539eb0
  X1[1] = 0;  // @822_539eb0
  X1[2] = 0;  // @823_539eb0
  X1[3] = 0;  // @824_539eb0
  X1[0] = F2U(U2F(X1[0]) - U2F(X4[0]));  // @825_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @826_539eb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X4[0]));  // @827_539eb0
  L53a5cb:;
  __builtin_memcpy((void *)((u32)(esi + 72) + 0), &X1[0], 4);  // @829_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 76) + 0), 4); v; });  // @830_539eb0
  X0[1] = 0;  // @831_539eb0
  X0[2] = 0;  // @832_539eb0
  X0[3] = 0;  // @833_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; }));  // @834_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @835_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @836_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a622;  // @837_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @838_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @839_539eb0
  ecx = edx = 0;  // @840_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @841_539eb0
  X1[1] = 0;  // @842_539eb0
  X1[2] = 0;  // @843_539eb0
  X1[3] = 0;  // @844_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @845_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @846_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @847_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @848_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; });  // @849_539eb0
  X0[1] = 0;  // @850_539eb0
  X0[2] = 0;  // @851_539eb0
  X0[3] = 0;  // @852_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @853_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @854_539eb0
  ecx = edx = 0;  // @855_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @856_539eb0
  X1[1] = 0;  // @857_539eb0
  X1[2] = 0;  // @858_539eb0
  X1[3] = 0;  // @859_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @860_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @861_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @862_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @863_539eb0
  ecx = edx = 0;  // @864_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @865_539eb0
  L53a622:;
  __builtin_memcpy((void *)((u32)(esi + 76) + 0), &X0[0], 4);  // @867_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 80) + 0), 4); v; });  // @868_539eb0
  X0[1] = 0;  // @869_539eb0
  X0[2] = 0;  // @870_539eb0
  X0[3] = 0;  // @871_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 80) + 0), 4); v; });  // @872_539eb0
  X1[1] = 0;  // @873_539eb0
  X1[2] = 0;  // @874_539eb0
  X1[3] = 0;  // @875_539eb0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @876_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @877_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @878_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a649;  // @879_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; })));  // @880_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })));  // @881_539eb0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @882_539eb0
  L53a649:;
  __builtin_memcpy((void *)((u32)(esi + 80) + 0), &X0[0], 4);  // @884_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 84) + 0), 4); v; });  // @885_539eb0
  X0[1] = 0;  // @886_539eb0
  X0[2] = 0;  // @887_539eb0
  X0[3] = 0;  // @888_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 84) + 0), 4); v; }));  // @889_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @890_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @891_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a6a0;  // @892_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @893_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @894_539eb0
  ecx = edx = 0;  // @895_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @896_539eb0
  X1[1] = 0;  // @897_539eb0
  X1[2] = 0;  // @898_539eb0
  X1[3] = 0;  // @899_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @900_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @901_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @902_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @903_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 84) + 0), 4); v; });  // @904_539eb0
  X0[1] = 0;  // @905_539eb0
  X0[2] = 0;  // @906_539eb0
  X0[3] = 0;  // @907_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @908_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @909_539eb0
  ecx = edx = 0;  // @910_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @911_539eb0
  X1[1] = 0;  // @912_539eb0
  X1[2] = 0;  // @913_539eb0
  X1[3] = 0;  // @914_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @915_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @916_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @917_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @918_539eb0
  ecx = edx = 0;  // @919_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @920_539eb0
  L53a6a0:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @922_539eb0
  X1[1] = 0;  // @923_539eb0
  X1[2] = 0;  // @924_539eb0
  X1[3] = 0;  // @925_539eb0
  __builtin_memcpy((void *)((u32)(esi + 84) + 0), &X0[0], 4);  // @926_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 88) + 0), 4); v; });  // @927_539eb0
  X2[1] = 0;  // @928_539eb0
  X2[2] = 0;  // @929_539eb0
  X2[3] = 0;  // @930_539eb0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 88) + 0), 4); v; });  // @931_539eb0
  X3[1] = 0;  // @932_539eb0
  X3[2] = 0;  // @933_539eb0
  X3[3] = 0;  // @934_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @935_539eb0
  X0[1] = 0;  // @936_539eb0
  X0[2] = 0;  // @937_539eb0
  X0[3] = 0;  // @938_539eb0
  FA = U2F(X2[0]); FB = U2F(X3[0]);  // @939_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @940_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @941_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a6cf;  // @942_539eb0
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @943_539eb0
  X3[0] = F2U(U2F(X3[0]) * U2F(X1[0]));  // @944_539eb0
  X2[0] = F2U(U2F(X2[0]) + U2F(X3[0]));  // @945_539eb0
  L53a6cf:;
  __builtin_memcpy((void *)((u32)(esi + 88) + 0), &X2[0], 4);  // @947_539eb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 92) + 0), 4); v; });  // @948_539eb0
  X2[1] = 0;  // @949_539eb0
  X2[2] = 0;  // @950_539eb0
  X2[3] = 0;  // @951_539eb0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 92) + 0), 4); v; });  // @952_539eb0
  X3[1] = 0;  // @953_539eb0
  X3[2] = 0;  // @954_539eb0
  X3[3] = 0;  // @955_539eb0
  FA = U2F(X2[0]); FB = U2F(X3[0]);  // @956_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @957_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @958_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a6f3;  // @959_539eb0
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @960_539eb0
  X3[0] = F2U(U2F(X3[0]) * U2F(X1[0]));  // @961_539eb0
  X2[0] = F2U(U2F(X2[0]) + U2F(X3[0]));  // @962_539eb0
  L53a6f3:;
  __builtin_memcpy((void *)((u32)(esi + 92) + 0), &X2[0], 4);  // @964_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 96) + 0), 4); v; });  // @965_539eb0
  X0[1] = 0;  // @966_539eb0
  X0[2] = 0;  // @967_539eb0
  X0[3] = 0;  // @968_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 96) + 0), 4); v; }));  // @969_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @970_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @971_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a74a;  // @972_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @973_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @974_539eb0
  ecx = edx = 0;  // @975_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @976_539eb0
  X1[1] = 0;  // @977_539eb0
  X1[2] = 0;  // @978_539eb0
  X1[3] = 0;  // @979_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @980_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @981_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @982_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @983_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 96) + 0), 4); v; });  // @984_539eb0
  X0[1] = 0;  // @985_539eb0
  X0[2] = 0;  // @986_539eb0
  X0[3] = 0;  // @987_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @988_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @989_539eb0
  ecx = edx = 0;  // @990_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @991_539eb0
  X1[1] = 0;  // @992_539eb0
  X1[2] = 0;  // @993_539eb0
  X1[3] = 0;  // @994_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @995_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @996_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @997_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @998_539eb0
  ecx = edx = 0;  // @999_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @1000_539eb0
  L53a74a:;
  __builtin_memcpy((void *)((u32)(esi + 96) + 0), &X0[0], 4);  // @1002_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 100) + 0), 4); v; });  // @1003_539eb0
  X0[1] = 0;  // @1004_539eb0
  X0[2] = 0;  // @1005_539eb0
  X0[3] = 0;  // @1006_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 100) + 0), 4); v; }));  // @1007_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1008_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1009_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a7a1;  // @1010_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @1011_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @1012_539eb0
  ecx = edx = 0;  // @1013_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; });  // @1014_539eb0
  X1[1] = 0;  // @1015_539eb0
  X1[2] = 0;  // @1016_539eb0
  X1[3] = 0;  // @1017_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @1018_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @1019_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 0), &X0[0], 4);  // @1020_539eb0
  __builtin_memcpy((void *)((u32)((EBP - 56) + 24) + 4), &X0[1], 4);  // @1021_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 100) + 0), 4); v; });  // @1022_539eb0
  X0[1] = 0;  // @1023_539eb0
  X0[2] = 0;  // @1024_539eb0
  X0[3] = 0;  // @1025_539eb0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @1026_539eb0
  { double r_ = ext_634de8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @1027_539eb0
  ecx = edx = 0;  // @1028_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @1029_539eb0
  X1[1] = 0;  // @1030_539eb0
  X1[2] = 0;  // @1031_539eb0
  X1[3] = 0;  // @1032_539eb0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @1033_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @1034_539eb0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 4), 4); v; })));  // @1035_539eb0
  { double r_ = ext_634db8_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @1036_539eb0
  ecx = edx = 0;  // @1037_539eb0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @1038_539eb0
  L53a7a1:;
  __builtin_memcpy((void *)((u32)(esi + 100) + 0), &X0[0], 4);  // @1040_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 104) + 0), 4); v; });  // @1041_539eb0
  X0[1] = 0;  // @1042_539eb0
  X0[2] = 0;  // @1043_539eb0
  X0[3] = 0;  // @1044_539eb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 104) + 0), 4); v; });  // @1045_539eb0
  X1[1] = 0;  // @1046_539eb0
  X1[2] = 0;  // @1047_539eb0
  X1[3] = 0;  // @1048_539eb0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1049_539eb0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1050_539eb0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1051_539eb0
  if (__builtin_parity(FL[2] & 0xff)) goto L53a7c8;  // @1052_539eb0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 12) + 0), 4); v; })));  // @1053_539eb0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })));  // @1054_539eb0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @1055_539eb0
  L53a7c8:;
  __builtin_memcpy((void *)((u32)(esi + 104) + 0), &X0[0], 4);  // @1057_539eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @1058_539eb0
  eax = (eax & ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; }));  // @1059_539eb0
  FL[3] = eax;  // @1060_539eb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 40) + 0), 4); v; });  // @1061_539eb0
  X0[1] = 0;  // @1062_539eb0
  X0[2] = 0;  // @1063_539eb0
  X0[3] = 0;  // @1064_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; }));  // @1065_539eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @1066_539eb0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L53a7eb;  // @1067_539eb0
  { u32 v = (u32)((u32)(1050253722)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @1068_539eb0
  L53a7eb:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 60) + 0), 4); v; });  // @1070_539eb0
  X0[1] = 0;  // @1071_539eb0
  X0[2] = 0;  // @1072_539eb0
  X0[3] = 0;  // @1073_539eb0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; }));  // @1074_539eb0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L53a800;  // @1075_539eb0
  { u32 v = (u32)((u32)(1036831949)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @1076_539eb0
  L53a800:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @1078_539eb0
  return eax;  // @1079_539eb0
}
PCREG(539eb0, lifted_539eb0);

