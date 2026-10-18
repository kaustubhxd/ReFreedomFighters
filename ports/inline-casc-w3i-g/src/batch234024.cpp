// batch234024.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 THISCALL ext_478ea0_thiscall3(u32, u32, u32) __asm__("ext_478ea0");
extern "C" u32 THISCALL ext_478f90_thiscall2(u32, u32) __asm__("ext_478f90");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }
static inline long double LDF(u32 a) { float f; __builtin_memcpy(&f, (void *)a, 4); return f; }
static inline long double LDD(u32 a) { double d; __builtin_memcpy(&d, (void *)a, 8); return d; }
static inline long double LDI16(u32 a) { short v; __builtin_memcpy(&v, (void *)a, 2); return v; }
static inline long double LDI32(u32 a) { int v; __builtin_memcpy(&v, (void *)a, 4); return v; }
static inline long double LDI64(u32 a) { long long v; __builtin_memcpy(&v, (void *)a, 8); return v; }
static inline void STF(u32 a, long double x) { float f = (float)x; __builtin_memcpy((void *)a, &f, 4); }
static inline void STD(u32 a, long double x) { double d = (double)x; __builtin_memcpy((void *)a, &d, 8); }
static inline void STI16(u32 a, long double x) { short v; __asm__ volatile("fistps %0" : "=m"(v) : "t"(x) : "st"); __builtin_memcpy((void *)a, &v, 2); }
static inline void STI32(u32 a, long double x) { int v; __asm__ volatile("fistpl %0" : "=m"(v) : "t"(x) : "st"); __builtin_memcpy((void *)a, &v, 4); }
static inline void STI64(u32 a, long double x) { long long v; __asm__ volatile("fistpll %0" : "=m"(v) : "t"(x) : "st"); __builtin_memcpy((void *)a, &v, 8); }
static inline void FSQRT(long double &x) { __asm__("fsqrt" : "+t"(x)); }
static inline void FSIN(long double &x) { __asm__("fsin" : "+t"(x)); }
static inline void FCOS(long double &x) { __asm__("fcos" : "+t"(x)); }
static inline void FRNDINT(long double &x) { __asm__("frndint" : "+t"(x)); }
static inline void F2XM1(long double &x) { __asm__("f2xm1" : "+t"(x)); }
static inline void FABS(long double &x) { __asm__("fabs" : "+t"(x)); }
static inline u32 FCMPSW(long double a, long double b) { return (a != a || b != b) ? 0x4500u : (a < b ? 0x100u : (a == b ? 0x4000u : 0u)); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" float THISCALL lifted_47eba0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {   /* w3g: returns a float in st0 */
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0d0d0d0d, esi = 0x0d0d0d0d, edi = 0x0d0d0d0d;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_47eba0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_47eba0
  edi = ecx;  // @2_47eba0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 280) + 24), &v, sizeof v); }  // @3_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 20), &v, sizeof v); }  // @4_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @5_47eba0
  FL[2] = (ecx & ecx);  // @6_47eba0
  if (FL[2] == 0) goto L47f31a;  // @7_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @8_47eba0
  X0[1] = 0;  // @9_47eba0
  X0[2] = 0;  // @10_47eba0
  X0[3] = 0;  // @11_47eba0
  PV[0] = (u32)(ecx);  // @12_47eba0
  PV[1] = X0[0];  // @13_47eba0
  eax = ext_478f90_thiscall2(ecx, PV[1]);  // @14_47eba0
  edx = 0;  // @15_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @16_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @17_47eba0
  X0[1] = 0;  // @18_47eba0
  X0[2] = 0;  // @19_47eba0
  X0[3] = 0;  // @20_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 12), &v, sizeof v); }  // @21_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; }));  // @22_47eba0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L47ed3a;  // @23_47eba0
  L47ec10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @25_47eba0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @26_47eba0
  X1[1] = 0;  // @27_47eba0
  X1[2] = 0;  // @28_47eba0
  X1[3] = 0;  // @29_47eba0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @30_47eba0
  if ((s32)FL[0] <= (s32)FL[1]) goto L47ec3f;  // @31_47eba0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @32_47eba0
  L47ec26:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_47eba0
  eax = edx;  // @35_47eba0
  eax = (eax + eax);  // @36_47eba0
  FL[3] = eax;  // @37_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax*8) + 0), 4); v; });  // @38_47eba0
  X0[1] = 0;  // @39_47eba0
  X0[2] = 0;  // @40_47eba0
  X0[3] = 0;  // @41_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @42_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47ec3f;  // @43_47eba0
  eax = (u32)(edx - 1);  // @44_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @45_47eba0
  FL[2] = (eax & eax);  // @46_47eba0
  if ((s32)FL[2] > 0) goto L47ec26;  // @47_47eba0
  L47ec3f:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @49_47eba0
  esi = (esi - 1);  // @50_47eba0
  FL[3] = esi;  // @51_47eba0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = esi;  // @52_47eba0
  if ((s32)FL[0] >= (s32)FL[1]) goto L47ec69;  // @53_47eba0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @54_47eba0
  L47ec50:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_47eba0
  eax = edx;  // @57_47eba0
  eax = (eax + eax);  // @58_47eba0
  FL[3] = eax;  // @59_47eba0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*8) + 0), 4); v; }));  // @60_47eba0
  if ((!(FA >= FB))) goto L47ec65;  // @61_47eba0
  eax = (u32)(edx + 1);  // @62_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @63_47eba0
  FL[0] = eax; FL[1] = esi;  // @64_47eba0
  if ((s32)FL[0] < (s32)FL[1]) goto L47ec50;  // @65_47eba0
  L47ec65:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 24), sizeof v); (u32)v; });  // @67_47eba0
  L47ec69:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 12), sizeof v); (u32)v; });  // @69_47eba0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = eax;  // @70_47eba0
  if (FL[0] != FL[1]) goto L47ed3a;  // @71_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @72_47eba0
  X0[1] = 0;  // @73_47eba0
  X0[2] = 0;  // @74_47eba0
  X0[3] = 0;  // @75_47eba0
  PV[2] = (u32)(ecx);  // @76_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @77_47eba0
  PV[3] = X0[0];  // @78_47eba0
  PV[4] = (u32)(ebx);  // @79_47eba0
  eax = ext_478ea0_thiscall3(ecx, PV[4], PV[3]);  // @80_47eba0
  ecx = edx = 0;  // @81_47eba0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 20), sizeof v); (u32)v; });  // @82_47eba0
  edx = ebx;  // @83_47eba0
  ecx = (u32)((EBP - 284) + 68);  // @84_47eba0
  eax = ext_43e920_fastcall3(ecx, edx, PV[5]);  // @85_47eba0
  ecx = edx = 0;  // @86_47eba0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 64) + 0), 4); v; });  // @87_47eba0
  X1[1] = 0;  // @88_47eba0
  X1[2] = 0;  // @89_47eba0
  X1[3] = 0;  // @90_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 72) + 0), 4); v; });  // @91_47eba0
  X0[1] = 0;  // @92_47eba0
  X0[2] = 0;  // @93_47eba0
  X0[3] = 0;  // @94_47eba0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @95_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 68), &v, sizeof v); }  // @96_47eba0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @97_47eba0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })));  // @98_47eba0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @99_47eba0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @100_47eba0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @101_47eba0
  ecx = edx = 0;  // @102_47eba0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; });  // @103_47eba0
  X2[1] = 0;  // @104_47eba0
  X2[2] = 0;  // @105_47eba0
  X2[3] = 0;  // @106_47eba0
  X1[0] = 0;  // @107_47eba0
  X1[1] = 0;  // @108_47eba0
  X1[2] = 0;  // @109_47eba0
  X1[3] = 0;  // @110_47eba0
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @111_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1656) + 0), 4); v; });  // @112_47eba0
  X0[1] = 0;  // @113_47eba0
  X0[2] = 0;  // @114_47eba0
  X0[3] = 0;  // @115_47eba0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @116_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @117_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47ed14;  // @118_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @119_47eba0
  X0[1] = 0;  // @120_47eba0
  X0[2] = 0;  // @121_47eba0
  X0[3] = 0;  // @122_47eba0
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @123_47eba0
  __builtin_memcpy((void *)((u32)(edi + 1826) + 0), &X0[0], 4);  // @124_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @125_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; }));  // @126_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47ec10;  // @127_47eba0
  goto L47ed3a;  // @128_47eba0
  L47ed14:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1656) + 0), 4); v; });  // @130_47eba0
  X0[1] = 0;  // @131_47eba0
  X0[2] = 0;  // @132_47eba0
  X0[3] = 0;  // @133_47eba0
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @134_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @135_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47ed3a;  // @136_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @137_47eba0
  X0[1] = 0;  // @138_47eba0
  X0[2] = 0;  // @139_47eba0
  X0[3] = 0;  // @140_47eba0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; })));  // @141_47eba0
  __builtin_memcpy((void *)((u32)(edi + 1826) + 0), &X0[0], 4);  // @142_47eba0
  L47ed3a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @144_47eba0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @145_47eba0
  X1[1] = 0;  // @146_47eba0
  X1[2] = 0;  // @147_47eba0
  X1[3] = 0;  // @148_47eba0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @149_47eba0
  if ((s32)FL[0] <= (s32)FL[1]) goto L47ed69;  // @150_47eba0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @151_47eba0
  L47ed50:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_47eba0
  eax = edx;  // @154_47eba0
  eax = (eax + eax);  // @155_47eba0
  FL[3] = eax;  // @156_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax*8) + 0), 4); v; });  // @157_47eba0
  X0[1] = 0;  // @158_47eba0
  X0[2] = 0;  // @159_47eba0
  X0[3] = 0;  // @160_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @161_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47ed69;  // @162_47eba0
  eax = (u32)(edx - 1);  // @163_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @164_47eba0
  FL[2] = (eax & eax);  // @165_47eba0
  if ((s32)FL[2] > 0) goto L47ed50;  // @166_47eba0
  L47ed69:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @168_47eba0
  esi = (esi - 1);  // @169_47eba0
  FL[3] = esi;  // @170_47eba0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = esi;  // @171_47eba0
  if ((s32)FL[0] >= (s32)FL[1]) goto L47ed89;  // @172_47eba0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @173_47eba0
  L47ed74:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_47eba0
  eax = edx;  // @176_47eba0
  eax = (eax + eax);  // @177_47eba0
  FL[3] = eax;  // @178_47eba0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*8) + 0), 4); v; }));  // @179_47eba0
  if ((!(FA >= FB))) goto L47ed89;  // @180_47eba0
  eax = (u32)(edx + 1);  // @181_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @182_47eba0
  FL[0] = eax; FL[1] = esi;  // @183_47eba0
  if ((s32)FL[0] < (s32)FL[1]) goto L47ed74;  // @184_47eba0
  L47ed89:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @186_47eba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 12), sizeof v); (u32)v; });  // @187_47eba0
  FL[0] = edx; FL[1] = ebx;  // @188_47eba0
  if (FL[0] == FL[1]) goto L47f181;  // @189_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @190_47eba0
  esi = ebx;  // @191_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 40), &v, sizeof v); }  // @192_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 44), &v, sizeof v); }  // @193_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 48), &v, sizeof v); }  // @194_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 52), &v, sizeof v); }  // @195_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 56), &v, sizeof v); }  // @196_47eba0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 280) + 60), &v, sizeof v); }  // @197_47eba0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 280) + 28), &v, sizeof v); }  // @198_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 32), &v, sizeof v); }  // @199_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 36), &v, sizeof v); }  // @200_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @201_47eba0
  esi = (esi << (u32)(4));  // @202_47eba0
  FL[3] = esi;  // @203_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + esi + 4) + 0), 4); v; });  // @204_47eba0
  X0[1] = 0;  // @205_47eba0
  X0[2] = 0;  // @206_47eba0
  X0[3] = 0;  // @207_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 280) + 40) + 0), &X0[0], 4);  // @208_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + esi + 8) + 0), 4); v; });  // @209_47eba0
  X0[1] = 0;  // @210_47eba0
  X0[2] = 0;  // @211_47eba0
  X0[3] = 0;  // @212_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 280) + 44) + 0), &X0[0], 4);  // @213_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + esi + 12) + 0), 4); v; });  // @214_47eba0
  X0[1] = 0;  // @215_47eba0
  X0[2] = 0;  // @216_47eba0
  X0[3] = 0;  // @217_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 280) + 48) + 0), &X0[0], 4);  // @218_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @219_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @220_47eba0
  eax = (eax - 1);  // @221_47eba0
  FL[3] = eax;  // @222_47eba0
  FL[0] = edx; FL[1] = eax;  // @223_47eba0
  if (FL[0] == FL[1]) goto L47ee27;  // @224_47eba0
  edx = (edx << (u32)(4));  // @225_47eba0
  FL[3] = edx;  // @226_47eba0
  eax = (u32)(edx + 4);  // @227_47eba0
  edx = (edx + (u32)(20));  // @228_47eba0
  FL[3] = edx;  // @229_47eba0
  goto L47ee30;  // @230_47eba0
  L47ee27:;
  edx = (edx << (u32)(4));  // @232_47eba0
  FL[3] = edx;  // @233_47eba0
  eax = (u32)(edx - 12);  // @234_47eba0
  edx = (edx + (u32)(4));  // @235_47eba0
  FL[3] = edx;  // @236_47eba0
  L47ee30:;
  eax = (eax + ecx);  // @238_47eba0
  FL[3] = eax;  // @239_47eba0
  edx = (edx + ecx);  // @240_47eba0
  FL[3] = edx;  // @241_47eba0
  PV[6] = (u32)(eax);  // @242_47eba0
  ecx = (u32)((EBP - 284) + 56);  // @243_47eba0
  eax = ext_43e920_fastcall3(ecx, edx, PV[6]);  // @244_47eba0
  ecx = edx = 0;  // @245_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @246_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @247_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @248_47eba0
  eax = (eax - 1);  // @249_47eba0
  FL[3] = eax;  // @250_47eba0
  FL[0] = ebx; FL[1] = eax;  // @251_47eba0
  if (FL[0] == FL[1]) goto L47ee57;  // @252_47eba0
  eax = (u32)(ecx + 4);  // @253_47eba0
  edx = (u32)(ecx + 20);  // @254_47eba0
  goto L47ee5d;  // @255_47eba0
  L47ee57:;
  eax = (u32)(ecx - 12);  // @257_47eba0
  edx = (u32)(ecx + 4);  // @258_47eba0
  L47ee5d:;
  eax = (eax + esi);  // @260_47eba0
  FL[3] = eax;  // @261_47eba0
  ecx = (u32)((EBP - 280) + 28);  // @262_47eba0
  PV[7] = (u32)(eax);  // @263_47eba0
  edx = (edx + esi);  // @264_47eba0
  FL[3] = edx;  // @265_47eba0
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @266_47eba0
  ecx = edx = 0;  // @267_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 52) + 0), 4); v; });  // @268_47eba0
  X0[1] = 0;  // @269_47eba0
  X0[2] = 0;  // @270_47eba0
  X0[3] = 0;  // @271_47eba0
  eax = (u32)((EBP - 280) + 52);  // @272_47eba0
  X1[0] = 0;  // @273_47eba0
  X1[1] = 0;  // @274_47eba0
  X1[2] = 0;  // @275_47eba0
  X1[3] = 0;  // @276_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 16), &v, sizeof v); }  // @277_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @278_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 56), &v, sizeof v); }  // @279_47eba0
  X2[0] = X1[0];  // @280_47eba0
  X2[1] = X1[1];  // @281_47eba0
  X2[2] = X1[2];  // @282_47eba0
  X2[3] = X1[3];  // @283_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 280) + 32) + 0), &X2[0], 4);  // @284_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @285_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @286_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47eea5;  // @287_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 60) + 0), 4); v; });  // @288_47eba0
  X0[1] = 0;  // @289_47eba0
  X0[2] = 0;  // @290_47eba0
  X0[3] = 0;  // @291_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @292_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @293_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @294_47eba0
  if (__builtin_parity(FL[2] & 0xff)) goto L47eeeb;  // @295_47eba0
  L47eea5:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 280) + 12), &v, sizeof v); }  // @297_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 16), sizeof v); (u32)v; });  // @298_47eba0
  FS[0] = LDF((u32)(ecx));  // @299_47eba0
  FS[0] = (FS[0] * FS[0]);  // @300_47eba0
  FS[1] = LDF((u32)(ecx + 4));  // @301_47eba0
  FS[1] = (FS[1] * FS[1]);  // @302_47eba0
  FS[0] = (FS[0] + FS[1]);  // @303_47eba0
  FS[1] = LDF((u32)(ecx + 8));  // @304_47eba0
  FS[1] = (FS[1] * FS[1]);  // @305_47eba0
  FS[0] = (FS[0] + FS[1]);  // @306_47eba0
  FSQRT(FS[0]);  // @307_47eba0
  FS[1] = LDF((u32)((EBP - 280) + 12));  // @308_47eba0
  FS[1] = (FS[1] / FS[0]);  // @309_47eba0
  FS[2] = LDF((u32)(ecx));  // @310_47eba0
  FS[2] = (FS[2] * FS[1]);  // @311_47eba0
  STF((u32)(ecx), FS[2]);  // @312_47eba0
  FS[2] = LDF((u32)(ecx + 4));  // @313_47eba0
  FS[2] = (FS[2] * FS[1]);  // @314_47eba0
  STF((u32)(ecx + 4), FS[2]);  // @315_47eba0
  FS[2] = LDF((u32)(ecx + 8));  // @316_47eba0
  FS[1] = (FS[1] * FS[2]);  // @317_47eba0
  STF((u32)(ecx + 8), FS[1]);  // @318_47eba0
  STF((u32)((EBP - 280) + 12), FS[0]);  // @319_47eba0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 32) + 0), 4); v; });  // @320_47eba0
  X2[1] = 0;  // @321_47eba0
  X2[2] = 0;  // @322_47eba0
  X2[3] = 0;  // @323_47eba0
  L47eeeb:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 28) + 0), 4); v; });  // @325_47eba0
  X0[1] = 0;  // @326_47eba0
  X0[2] = 0;  // @327_47eba0
  X0[3] = 0;  // @328_47eba0
  eax = (u32)((EBP - 280) + 28);  // @329_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @330_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 16), &v, sizeof v); }  // @331_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @332_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @333_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47ef1a;  // @334_47eba0
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @335_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @336_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @337_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47ef1a;  // @338_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 36) + 0), 4); v; });  // @339_47eba0
  X0[1] = 0;  // @340_47eba0
  X0[2] = 0;  // @341_47eba0
  X0[3] = 0;  // @342_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @343_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @344_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @345_47eba0
  if (__builtin_parity(FL[2] & 0xff)) goto L47ef5a;  // @346_47eba0
  L47ef1a:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 280) + 12), &v, sizeof v); }  // @348_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 16), sizeof v); (u32)v; });  // @349_47eba0
  FS[0] = LDF((u32)(ecx));  // @350_47eba0
  FS[0] = (FS[0] * FS[0]);  // @351_47eba0
  FS[1] = LDF((u32)(ecx + 4));  // @352_47eba0
  FS[1] = (FS[1] * FS[1]);  // @353_47eba0
  FS[0] = (FS[0] + FS[1]);  // @354_47eba0
  FS[1] = LDF((u32)(ecx + 8));  // @355_47eba0
  FS[1] = (FS[1] * FS[1]);  // @356_47eba0
  FS[0] = (FS[0] + FS[1]);  // @357_47eba0
  FSQRT(FS[0]);  // @358_47eba0
  FS[1] = LDF((u32)((EBP - 280) + 12));  // @359_47eba0
  FS[1] = (FS[1] / FS[0]);  // @360_47eba0
  FS[2] = LDF((u32)(ecx));  // @361_47eba0
  FS[2] = (FS[2] * FS[1]);  // @362_47eba0
  STF((u32)(ecx), FS[2]);  // @363_47eba0
  FS[2] = LDF((u32)(ecx + 4));  // @364_47eba0
  FS[2] = (FS[2] * FS[1]);  // @365_47eba0
  STF((u32)(ecx + 4), FS[2]);  // @366_47eba0
  FS[2] = LDF((u32)(ecx + 8));  // @367_47eba0
  FS[1] = (FS[1] * FS[2]);  // @368_47eba0
  STF((u32)(ecx + 8), FS[1]);  // @369_47eba0
  STF((u32)((EBP - 280) + 12), FS[0]);  // @370_47eba0
  L47ef5a:;
  eax = (u32)((EBP - 280) + 28);  // @372_47eba0
  PV[8] = (u32)(eax);  // @373_47eba0
  edx = (u32)((EBP - 284) + 56);  // @374_47eba0
  ecx = (u32)((EBP - 284) + 208);  // @375_47eba0
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[8]);  // @376_47eba0
  ecx = edx = 0;  // @377_47eba0
  eax = (u32)((EBP - 280) + 52);  // @378_47eba0
  PV[9] = (u32)(eax);  // @379_47eba0
  edx = (u32)((EBP - 284) + 32);  // @380_47eba0
  ecx = (u32)((EBP - 284) + 80);  // @381_47eba0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[9]);  // @382_47eba0
  ecx = edx = 0;  // @383_47eba0
  eax = (u32)((EBP - 280) + 76);  // @384_47eba0
  edx = (u32)((EBP - 280) + 204);  // @385_47eba0
  PV[10] = (u32)(eax);  // @386_47eba0
  ecx = edx;  // @387_47eba0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[10]);  // @388_47eba0
  ecx = edx = 0;  // @389_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 204) + 0), 4); v; });  // @390_47eba0
  X0[1] = 0;  // @391_47eba0
  X0[2] = 0;  // @392_47eba0
  X0[3] = 0;  // @393_47eba0
  eax = (u32)((EBP - 280) + 204);  // @394_47eba0
  X1[0] = 0;  // @395_47eba0
  X1[1] = 0;  // @396_47eba0
  X1[2] = 0;  // @397_47eba0
  X1[3] = 0;  // @398_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 16), &v, sizeof v); }  // @399_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @400_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @401_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @402_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47efd8;  // @403_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 208) + 0), 4); v; });  // @404_47eba0
  X0[1] = 0;  // @405_47eba0
  X0[2] = 0;  // @406_47eba0
  X0[3] = 0;  // @407_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @408_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @409_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @410_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47efd8;  // @411_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 212) + 0), 4); v; });  // @412_47eba0
  X0[1] = 0;  // @413_47eba0
  X0[2] = 0;  // @414_47eba0
  X0[3] = 0;  // @415_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @416_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @417_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @418_47eba0
  if (__builtin_parity(FL[2] & 0xff)) goto L47f018;  // @419_47eba0
  L47efd8:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 280) + 12), &v, sizeof v); }  // @421_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 16), sizeof v); (u32)v; });  // @422_47eba0
  FS[0] = LDF((u32)(ecx));  // @423_47eba0
  FS[0] = (FS[0] * FS[0]);  // @424_47eba0
  FS[1] = LDF((u32)(ecx + 4));  // @425_47eba0
  FS[1] = (FS[1] * FS[1]);  // @426_47eba0
  FS[0] = (FS[0] + FS[1]);  // @427_47eba0
  FS[1] = LDF((u32)(ecx + 8));  // @428_47eba0
  FS[1] = (FS[1] * FS[1]);  // @429_47eba0
  FS[0] = (FS[0] + FS[1]);  // @430_47eba0
  FSQRT(FS[0]);  // @431_47eba0
  FS[1] = LDF((u32)((EBP - 280) + 12));  // @432_47eba0
  FS[1] = (FS[1] / FS[0]);  // @433_47eba0
  FS[2] = LDF((u32)(ecx));  // @434_47eba0
  FS[2] = (FS[2] * FS[1]);  // @435_47eba0
  STF((u32)(ecx), FS[2]);  // @436_47eba0
  FS[2] = LDF((u32)(ecx + 4));  // @437_47eba0
  FS[2] = (FS[2] * FS[1]);  // @438_47eba0
  STF((u32)(ecx + 4), FS[2]);  // @439_47eba0
  FS[2] = LDF((u32)(ecx + 8));  // @440_47eba0
  FS[1] = (FS[1] * FS[2]);  // @441_47eba0
  STF((u32)(ecx + 8), FS[1]);  // @442_47eba0
  STF((u32)((EBP - 280) + 12), FS[0]);  // @443_47eba0
  L47f018:;
  ecx = (u32)((EBP - 280) + 88);  // @445_47eba0
  eax = ext_4e1b60_thiscall1(ecx);  // @446_47eba0
    // @447_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 40) + 0), 4); v; });  // @448_47eba0
  X0[1] = 0;  // @449_47eba0
  X0[2] = 0;  // @450_47eba0
  X0[3] = 0;  // @451_47eba0
  edx = (u32)((EBP - 280) + 204);  // @452_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 280) + 88) + 0), &X0[0], 4);  // @453_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 48) + 0), 4); v; });  // @454_47eba0
  X0[1] = 0;  // @455_47eba0
  X0[2] = 0;  // @456_47eba0
  X0[3] = 0;  // @457_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 280) + 96) + 0), &X0[0], 4);  // @458_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 44) + 0), 4); v; });  // @459_47eba0
  X0[1] = 0;  // @460_47eba0
  X0[2] = 0;  // @461_47eba0
  X0[3] = 0;  // @462_47eba0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @463_47eba0
  PV[11] = (u32)(ecx);  // @464_47eba0
  ecx = (u32)((EBP - 284) + 104);  // @465_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 284) + 96) + 0), &X0[0], 4);  // @466_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1822) + 0), 4); v; });  // @467_47eba0
  X0[1] = 0;  // @468_47eba0
  X0[2] = 0;  // @469_47eba0
  X0[3] = 0;  // @470_47eba0
  PV[12] = X0[0];  // @471_47eba0
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[12]);  // @472_47eba0
    // @473_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @474_47eba0
  edx = (u32)((EBP - 280) + 88);  // @475_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @476_47eba0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @477_47eba0
  FL[3] = (ebx & 0xff);  // @478_47eba0
  PV[13] = (u32)(edx);  // @479_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @480_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @481_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @482_47eba0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[13], (u32)(0), (u32)(1), (u32)(-1), (u32)(1), (u32)(0));  // @483_47eba0
  ecx = edx = 0;  // @484_47eba0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @485_47eba0
  if (FL[2] == 0) goto L47f0b8;  // @486_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 140) + 0), 4); v; });  // @487_47eba0
  X0[1] = 0;  // @488_47eba0
  X0[2] = 0;  // @489_47eba0
  X0[3] = 0;  // @490_47eba0
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @491_47eba0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @492_47eba0
  __builtin_memcpy((void *)((u32)(edi + 1656) + 0), &X0[0], 4);  // @493_47eba0
  goto L47f0c2;  // @494_47eba0
  L47f0b8:;
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 1656), &v, sizeof v); }  // @496_47eba0
  L47f0c2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; });  // @498_47eba0
  X0[1] = 0;  // @499_47eba0
  X0[2] = 0;  // @500_47eba0
  X0[3] = 0;  // @501_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1656) + 0), 4); v; }));  // @502_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47f0dd;  // @503_47eba0
  { u32 v = (u32)((u32)(1101004800)); __builtin_memcpy((void *)(u32)(edi + 1656), &v, sizeof v); }  // @504_47eba0
  L47f0dd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338568) + 0), 4); v; });  // @506_47eba0
  X0[1] = 0;  // @507_47eba0
  X0[2] = 0;  // @508_47eba0
  X0[3] = 0;  // @509_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @510_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @511_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @512_47eba0
  if (__builtin_parity(FL[2] & 0xff)) goto L47f181;  // @513_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 40) + 0), 4); v; });  // @514_47eba0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 40) + 4), 4); v; });  // @515_47eba0
  X0[2] = 0;  // @516_47eba0
  X0[3] = 0;  // @517_47eba0
  edx = (u32)((EBP - 280) + 40);  // @518_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 48), sizeof v); (u32)v; });  // @519_47eba0
  PV[14] = (u32)(ecx);  // @520_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 284) + 220) + 0), &X0[0], 4);  // @521_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 284) + 220) + 4), &X0[1], 4);  // @522_47eba0
  ecx = (u32)((EBP - 284) + 232);  // @523_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1656) + 0), 4); v; });  // @524_47eba0
  X0[1] = 0;  // @525_47eba0
  X0[2] = 0;  // @526_47eba0
  X0[3] = 0;  // @527_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 284) + 228), &v, sizeof v); }  // @528_47eba0
  eax = (u32)((EBP - 284) + 208);  // @529_47eba0
  PV[15] = X0[0];  // @530_47eba0
  PV[16] = (u32)(eax);  // @531_47eba0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[16], PV[15]);  // @532_47eba0
  ecx = edx = 0;  // @533_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @534_47eba0
  edx = (u32)((EBP - 280) + 228);  // @535_47eba0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @536_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @537_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @538_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @539_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @540_47eba0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @541_47eba0
  if (FL[2] == 0) goto L47f163;  // @542_47eba0
  goto L47f168;  // @543_47eba0
  L47f163:;
  L47f168:;
  PV[17] = (u32)(edx);  // @546_47eba0
  edx = (u32)((EBP - 288) + 224);  // @547_47eba0 (w3g: two pushes pending, the colour and edx)
  PV[18] = (u32)(edx);  // @548_47eba0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[18], PV[17], (FL[2] == 0 ? (u32)(65280) : (u32)(16711680)));  /* w3g: one colour push per arm */  // @549_47eba0
  ecx = edx = 0;  // @550_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @551_47eba0
  PV[19] = (u32)(eax);  // @552_47eba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, PV[19]);  // @553_47eba0
  ecx = edx = 0;  // @554_47eba0
  L47f181:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @556_47eba0
  X0[1] = 0;  // @557_47eba0
  X0[2] = 0;  // @558_47eba0
  X0[3] = 0;  // @559_47eba0
  eax = (u32)(edi + 1632);  // @560_47eba0
  PV[20] = (u32)(ecx);  // @561_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @562_47eba0
  PV[21] = X0[0];  // @563_47eba0
  PV[22] = (u32)(eax);  // @564_47eba0
  eax = ext_478ea0_thiscall3(ecx, PV[22], PV[21]);  // @565_47eba0
  ecx = edx = 0;  // @566_47eba0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @567_47eba0
  X1[1] = 0;  // @568_47eba0
  X1[2] = 0;  // @569_47eba0
  X1[3] = 0;  // @570_47eba0
  esi = (u32)(edi + 1644);  // @571_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @572_47eba0
  X0[0] = 0;  // @573_47eba0
  X0[1] = 0;  // @574_47eba0
  X0[2] = 0;  // @575_47eba0
  X0[3] = 0;  // @576_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @577_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47f1c8;  // @578_47eba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @579_47eba0
  eax = (u32)(edx + 4);  // @580_47eba0
  edx = (edx + (u32)(20));  // @581_47eba0
  FL[3] = edx;  // @582_47eba0
  goto L47f235;  // @583_47eba0
  L47f1c8:;
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; }));  // @585_47eba0
  if ((!(FA >= FB))) goto L47f1dc;  // @586_47eba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @587_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @588_47eba0
  eax = (u32)(ecx - 28);  // @589_47eba0
  ecx = (ecx + (u32)(-12));  // @590_47eba0
  FL[3] = ecx;  // @591_47eba0
  goto L47f22e;  // @592_47eba0
  L47f1dc:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @594_47eba0
  if ((s32)FL[0] <= (s32)FL[1]) goto L47f1fd;  // @595_47eba0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @596_47eba0
  L47f1e4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @598_47eba0
  eax = edx;  // @599_47eba0
  eax = (eax + eax);  // @600_47eba0
  FL[3] = eax;  // @601_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*8) + 0), 4); v; });  // @602_47eba0
  X0[1] = 0;  // @603_47eba0
  X0[2] = 0;  // @604_47eba0
  X0[3] = 0;  // @605_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @606_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47f1fd;  // @607_47eba0
  eax = (u32)(edx - 1);  // @608_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @609_47eba0
  FL[2] = (eax & eax);  // @610_47eba0
  if ((s32)FL[2] > 0) goto L47f1e4;  // @611_47eba0
  L47f1fd:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @613_47eba0
  ebx = (ebx - 1);  // @614_47eba0
  FL[3] = ebx;  // @615_47eba0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = ebx;  // @616_47eba0
  if ((s32)FL[0] >= (s32)FL[1]) goto L47f223;  // @617_47eba0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @618_47eba0
  L47f208:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @620_47eba0
  eax = edx;  // @621_47eba0
  eax = (eax + eax);  // @622_47eba0
  FL[3] = eax;  // @623_47eba0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax*8) + 0), 4); v; }));  // @624_47eba0
  if ((!(FA >= FB))) goto L47f21d;  // @625_47eba0
  eax = (u32)(edx + 1);  // @626_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @627_47eba0
  FL[0] = eax; FL[1] = ebx;  // @628_47eba0
  if ((s32)FL[0] < (s32)FL[1]) goto L47f208;  // @629_47eba0
  L47f21d:;
  esi = (u32)(edi + 1644);  // @631_47eba0
  L47f223:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @633_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @634_47eba0
  eax = (u32)(ecx - 12);  // @635_47eba0
  ecx = (ecx + (u32)(4));  // @636_47eba0
  FL[3] = ecx;  // @637_47eba0
  L47f22e:;
  edx = (edx << (u32)(4));  // @639_47eba0
  FL[3] = edx;  // @640_47eba0
  eax = (eax + edx);  // @641_47eba0
  FL[3] = eax;  // @642_47eba0
  edx = (edx + ecx);  // @643_47eba0
  FL[3] = edx;  // @644_47eba0
  L47f235:;
  PV[23] = (u32)(eax);  // @646_47eba0
  ecx = esi;  // @647_47eba0
  eax = ext_43e920_fastcall3(ecx, edx, PV[23]);  // @648_47eba0
  ecx = edx = 0;  // @649_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @650_47eba0
  X0[1] = 0;  // @651_47eba0
  X0[2] = 0;  // @652_47eba0
  X0[3] = 0;  // @653_47eba0
  X1[0] = 0;  // @654_47eba0
  X1[1] = 0;  // @655_47eba0
  X1[2] = 0;  // @656_47eba0
  X1[3] = 0;  // @657_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @658_47eba0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 280) + 16), &v, sizeof v); }  // @659_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @660_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @661_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47f26d;  // @662_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @663_47eba0
  X0[1] = 0;  // @664_47eba0
  X0[2] = 0;  // @665_47eba0
  X0[3] = 0;  // @666_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @667_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @668_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @669_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47f26d;  // @670_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @671_47eba0
  X0[1] = 0;  // @672_47eba0
  X0[2] = 0;  // @673_47eba0
  X0[3] = 0;  // @674_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @675_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @676_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @677_47eba0
  if (__builtin_parity(FL[2] & 0xff)) goto L47f2ad;  // @678_47eba0
  L47f26d:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 280) + 12), &v, sizeof v); }  // @680_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 16), sizeof v); (u32)v; });  // @681_47eba0
  FS[0] = LDF((u32)(ecx));  // @682_47eba0
  FS[0] = (FS[0] * FS[0]);  // @683_47eba0
  FS[1] = LDF((u32)(ecx + 4));  // @684_47eba0
  FS[1] = (FS[1] * FS[1]);  // @685_47eba0
  FS[0] = (FS[0] + FS[1]);  // @686_47eba0
  FS[1] = LDF((u32)(ecx + 8));  // @687_47eba0
  FS[1] = (FS[1] * FS[1]);  // @688_47eba0
  FS[0] = (FS[0] + FS[1]);  // @689_47eba0
  FSQRT(FS[0]);  // @690_47eba0
  FS[1] = LDF((u32)((EBP - 280) + 12));  // @691_47eba0
  FS[1] = (FS[1] / FS[0]);  // @692_47eba0
  FS[2] = LDF((u32)(ecx));  // @693_47eba0
  FS[2] = (FS[2] * FS[1]);  // @694_47eba0
  STF((u32)(ecx), FS[2]);  // @695_47eba0
  FS[2] = LDF((u32)(ecx + 4));  // @696_47eba0
  FS[2] = (FS[2] * FS[1]);  // @697_47eba0
  STF((u32)(ecx + 4), FS[2]);  // @698_47eba0
  FS[2] = LDF((u32)(ecx + 8));  // @699_47eba0
  FS[1] = (FS[1] * FS[2]);  // @700_47eba0
  STF((u32)(ecx + 8), FS[1]);  // @701_47eba0
  STF((u32)((EBP - 280) + 12), FS[0]);  // @702_47eba0
  L47f2ad:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1839), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @704_47eba0
  if (FL[0] != FL[1]) goto L47f2e5;  // @705_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @706_47eba0
  X0[1] = 0;  // @707_47eba0
  X0[2] = 0;  // @708_47eba0
  X0[3] = 0;  // @709_47eba0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; })));  // @710_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @711_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; }));  // @712_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47f2e5;  // @713_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @714_47eba0
  ecx = edi;  // @715_47eba0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1839), &v, sizeof v); }  // @716_47eba0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1596)))(ecx, (u32)(1));  // @717_47eba0
  ecx = edx = 0;  // @718_47eba0
  L47f2e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @720_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @721_47eba0
  X0[1] = 0;  // @722_47eba0
  X0[2] = 0;  // @723_47eba0
  X0[3] = 0;  // @724_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; }));  // @725_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47f31a;  // @726_47eba0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1733), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @727_47eba0
  ecx = edi;  // @728_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @729_47eba0
  if (FL[0] == FL[1]) goto L47f30e;  // @730_47eba0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1576)))(ecx, (u32)(2), (u32)(3), (u32)(0));  // w3g: arm pushes 0, 3, 2
  ecx = edx = 0;
  goto L47f31a;
  L47f30e:;
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1576)))(ecx, (u32)(1), (u32)(3), (u32)(1));  // w3g: arm pushes 1, 3, 1
  ecx = edx = 0;
  L47f31a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 20), sizeof v); (u32)v; });  // @737_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @738_47eba0
  X0[1] = 0;  // @739_47eba0
  X0[2] = 0;  // @740_47eba0
  X0[3] = 0;  // @741_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1632) + 0), 4); v; }));  // @742_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @743_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @744_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47f34c;  // @745_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; });  // @746_47eba0
  X0[1] = 0;  // @747_47eba0
  X0[2] = 0;  // @748_47eba0
  X0[3] = 0;  // @749_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1640) + 0), 4); v; }));  // @750_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @751_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @752_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47f34c;  // @753_47eba0
  X1[0] = 0;  // @754_47eba0
  X1[1] = 0;  // @755_47eba0
  X1[2] = 0;  // @756_47eba0
  X1[3] = 0;  // @757_47eba0
  X0[0] = X1[0];  // @758_47eba0
  X0[1] = X1[1];  // @759_47eba0
  X0[2] = X1[2];  // @760_47eba0
  X0[3] = X1[3];  // @761_47eba0
  goto L47f3e9;  // @762_47eba0
  L47f34c:;
  ebx = (u32)(edi + 1660);  // @764_47eba0
  PV[24] = (u32)(ecx);  // @765_47eba0
  edx = (u32)(edi + 1632);  // @766_47eba0
  ecx = ebx;  // @767_47eba0
  eax = ext_43e920_fastcall3(ecx, edx, PV[24]);  // @768_47eba0
  ecx = edx = 0;  // @769_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1664), &v, sizeof v); }  // @770_47eba0
  X1[0] = 0;  // @771_47eba0
  X1[1] = 0;  // @772_47eba0
  X1[2] = 0;  // @773_47eba0
  X1[3] = 0;  // @774_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @775_47eba0
  X0[1] = 0;  // @776_47eba0
  X0[2] = 0;  // @777_47eba0
  X0[3] = 0;  // @778_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @779_47eba0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 280) + 16), &v, sizeof v); }  // @780_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @781_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @782_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47f39f;  // @783_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @784_47eba0
  X0[1] = 0;  // @785_47eba0
  X0[2] = 0;  // @786_47eba0
  X0[3] = 0;  // @787_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @788_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @789_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @790_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47f39f;  // @791_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @792_47eba0
  X0[1] = 0;  // @793_47eba0
  X0[2] = 0;  // @794_47eba0
  X0[3] = 0;  // @795_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @796_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @797_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @798_47eba0
  if (!__builtin_parity(FL[2] & 0xff)) goto L47f39f;  // @799_47eba0
  X0[0] = X1[0];  // @800_47eba0
  X0[1] = X1[1];  // @801_47eba0
  X0[2] = X1[2];  // @802_47eba0
  X0[3] = X1[3];  // @803_47eba0
  goto L47f3e5;  // @804_47eba0
  L47f39f:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 280) + 12), &v, sizeof v); }  // @806_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 16), sizeof v); (u32)v; });  // @807_47eba0
  FS[0] = LDF((u32)(ecx));  // @808_47eba0
  FS[0] = (FS[0] * FS[0]);  // @809_47eba0
  FS[1] = LDF((u32)(ecx + 4));  // @810_47eba0
  FS[1] = (FS[1] * FS[1]);  // @811_47eba0
  FS[0] = (FS[0] + FS[1]);  // @812_47eba0
  FS[1] = LDF((u32)(ecx + 8));  // @813_47eba0
  FS[1] = (FS[1] * FS[1]);  // @814_47eba0
  FS[0] = (FS[0] + FS[1]);  // @815_47eba0
  FSQRT(FS[0]);  // @816_47eba0
  FS[1] = LDF((u32)((EBP - 280) + 12));  // @817_47eba0
  FS[1] = (FS[1] / FS[0]);  // @818_47eba0
  FS[2] = LDF((u32)(ecx));  // @819_47eba0
  FS[2] = (FS[2] * FS[1]);  // @820_47eba0
  STF((u32)(ecx), FS[2]);  // @821_47eba0
  FS[2] = LDF((u32)(ecx + 4));  // @822_47eba0
  FS[2] = (FS[2] * FS[1]);  // @823_47eba0
  STF((u32)(ecx + 4), FS[2]);  // @824_47eba0
  FS[2] = LDF((u32)(ecx + 8));  // @825_47eba0
  FS[1] = (FS[1] * FS[2]);  // @826_47eba0
  STF((u32)(ecx + 8), FS[1]);  // @827_47eba0
  STF((u32)((EBP - 280) + 12), FS[0]);  // @828_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 12) + 0), 4); v; });  // @829_47eba0
  X0[1] = 0;  // @830_47eba0
  X0[2] = 0;  // @831_47eba0
  X0[3] = 0;  // @832_47eba0
  L47f3e5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 20), sizeof v); (u32)v; });  // @834_47eba0
  L47f3e9:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @836_47eba0
  X1[1] = 0;  // @837_47eba0
  X1[2] = 0;  // @838_47eba0
  X1[3] = 0;  // @839_47eba0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @840_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 280) + 12) + 0), &X0[0], 4);  // @841_47eba0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47f424;  // @842_47eba0
  PV[25] = (u32)(ecx);  // @843_47eba0
  eax = (u32)(edi + 1660);  // @844_47eba0
  PV[26] = X1[0];  // @845_47eba0
  edx = ecx;  // @846_47eba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 28), sizeof v); (u32)v; });  // @847_47eba0
  PV[27] = (u32)(eax);  // @848_47eba0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[27], PV[26]);  // @849_47eba0
  ecx = edx = 0;  // @850_47eba0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 12) + 0), 4); v; });  // @851_47eba0
  X0[1] = 0;  // @852_47eba0
  X0[2] = 0;  // @853_47eba0
  X0[3] = 0;  // @854_47eba0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; })));  // @855_47eba0
  __builtin_memcpy((void *)((u32)((EBP - 280) + 12) + 0), &X0[0], 4);  // @856_47eba0
  goto L47f44a;  // @857_47eba0
  L47f424:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 24), sizeof v); (u32)v; });  // @859_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1632), sizeof v); (u32)v; });  // @860_47eba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 12), &v, sizeof v); }  // @861_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @862_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1636), sizeof v); (u32)v; });  // @863_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @864_47eba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1640), sizeof v); (u32)v; });  // @865_47eba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @866_47eba0
  L47f44a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338568) + 0), 4); v; });  // @868_47eba0
  X0[1] = 0;  // @869_47eba0
  X0[2] = 0;  // @870_47eba0
  X0[3] = 0;  // @871_47eba0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @872_47eba0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @873_47eba0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @874_47eba0
  if (__builtin_parity(FL[2] & 0xff)) goto L47f473;  // @875_47eba0
  edx = (u32)(edi + 1644);  // @876_47eba0
  ecx = (u32)((EBP - 284) + 244);  // @877_47eba0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @878_47eba0
  ecx = edx = 0;  // @879_47eba0
  L47f473:;
  ext_633654(G(u32, 0x6f5630));  // @881_47eba0
  FS[0] = LDF((u32)((EBP - 280) + 12));  // @882_47eba0
  return (float)FS[0];  // @883_47eba0 (w3g)
}
PCREG(47eba0, lifted_47eba0);

