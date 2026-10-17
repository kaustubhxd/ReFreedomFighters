// batch234030.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d70_dbl(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" long double STDCALL ext_477620_stdcall1_ld(u32) __asm__("ext_477620");
extern "C" long double STDCALL ext_478420_stdcall3_ld(u32, u32, u32) __asm__("ext_478420");
extern "C" long double THISCALL ext_47eba0_thiscall4_ld(u32, u32, u32, u32) __asm__("ext_47eba0");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_47ca20_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_47ca20");
extern "C" u32 FASTCALL ext_47f680_fastcall2(u32, u32) __asm__("ext_47f680");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 FASTCALL ext_4e09e0_fastcall2(u32, u32) __asm__("ext_4e09e0");
extern "C" u32 FASTCALL ext_4e0ab0_fastcall3(u32, u32, u32) __asm__("ext_4e0ab0");
extern "C" u32 FASTCALL ext_4e0be0_fastcall2(u32, u32) __asm__("ext_4e0be0");
extern "C" u32 STDCALL ext_479060_stdcall1(u32) __asm__("ext_479060");
extern "C" u32 THISCALL ext_477580_thiscall2(u32, u32) __asm__("ext_477580");
extern "C" u32 THISCALL ext_477740_thiscall3(u32, u32, u32) __asm__("ext_477740");
extern "C" u32 THISCALL ext_478a80_thiscall1(u32) __asm__("ext_478a80");
extern "C" u32 THISCALL ext_478ea0_thiscall3(u32, u32, u32) __asm__("ext_478ea0");
extern "C" u32 THISCALL ext_47aad0_thiscall3(u32, u32, u32) __asm__("ext_47aad0");
extern "C" u32 THISCALL ext_47c540_thiscall1(u32) __asm__("ext_47c540");
extern "C" u32 THISCALL ext_47c690_thiscall2(u32, u32) __asm__("ext_47c690");
extern "C" u32 THISCALL ext_47cdf0_thiscall3(u32, u32, u32) __asm__("ext_47cdf0");
extern "C" u32 THISCALL ext_47ce80_thiscall1(u32) __asm__("ext_47ce80");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
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

extern "C" long double THISCALL lifted_47d290(u32 ecx_in) {  // w3i: returns the x87 value (fld [esp+8] at the end)
  u32 W3I_A = 0;
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[65], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  edi = ecx;  // @0_47d290
  ecx = (u32)((EBP - 184) + 84);  // @1_47d290
  PV[0] = (u32)(ecx);  // @2_47d290
  ecx = (u32)((EBP - 188) + 112);  // @3_47d290
  PV[1] = (u32)(ecx);  // @4_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_47d290
  ecx = edi;  // @6_47d290
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1404)))(ecx, PV[1], PV[0]);  // @7_47d290
  ecx = edx = 0;  // @8_47d290
  edx = (u32)((EBP - 184) + 108);  // @9_47d290
  ecx = (u32)((EBP - 184) + 48);  // @10_47d290
  eax = ext_4e09e0_fastcall2(ecx, edx);  // @11_47d290
    // @12_47d290
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1830), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @13_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 8), &v, sizeof v); }  // @14_47d290
  if (FL[0] == FL[1]) goto L47e31d;  // @15_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_47d290
  ecx = edi;  // @17_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1416), sizeof v); (u32)v; });  // @18_47d290
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @19_47d290
  ecx = edx = 0;  // @20_47d290
  FL[2] = (eax & eax);  // @21_47d290
  if (FL[2] != 0) goto L47d390;  // @22_47d290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @23_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @25_47d290
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6858692), (u32)(2598));  // @26_47d290
  ecx = edx = 0;  // @27_47d290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_47d290
  ecx = edi;  // @29_47d290
  esi = eax;  // @30_47d290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; });  // @31_47d290
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @32_47d290
  ecx = edx = 0;  // @33_47d290
  edx = (u32)(6801640);  // @34_47d290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @35_47d290
  FL[2] = (ecx & ecx);  // @36_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_47d290
  if (FL[2] != 0) edx = ecx;  // @38_47d290
  PV[2] = (u32)(edx);  // @39_47d290
  PV[3] = (u32)(esi);  // @40_47d290
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(eax + 44)))(PV[3], (u32)(6859792), PV[2]);  // @41_47d290
  ecx = edx = 0;  // @42_47d290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @43_47d290
  FL[2] = (ecx & ecx);  // @44_47d290
  if (FL[2] == 0) goto L47d351;  // @45_47d290
  eax = ext_477580_thiscall2(ecx, (u32)(1));  // @46_47d290
  ecx = edx = 0;  // @47_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1685), &v, sizeof v); }  // @48_47d290
  L47d351:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1612), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @50_47d290
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1830), &v, sizeof v); }  // @51_47d290
  if (FL[0] != FL[1]) goto L47d386;  // @52_47d290
  PV[4] = (u32)(edi);  // @53_47d290
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1742), sizeof v); (u32)v; });  // @54_47d290
  ecx = (u32)(7338432);  // @55_47d290
  eax = ext_47aad0_thiscall3(ecx, PV[5], PV[4]);  // @56_47d290
  ecx = edx = 0;  // @57_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1742), &v, sizeof v); }  // @58_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @59_47d290
  L47d386:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1681), &v, sizeof v); }  // @61_47d290
  L47d390:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1830), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @63_47d290
  if (FL[0] == FL[1]) goto L47e31d;  // @64_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_47d290
  ecx = edi;  // @66_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 600), sizeof v); (u32)v; });  // @67_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(0));  // @68_47d290
  ecx = edx = 0;  // @69_47d290
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @70_47d290
  if (FL[2] != 0) goto L47e31d;  // @71_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1604) + 0), 4); v; });  // @72_47d290
  X0[1] = 0;  // @73_47d290
  X0[2] = 0;  // @74_47d290
  X0[3] = 0;  // @75_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @76_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_47d290
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 184) + 19), &v, sizeof v); }  // @78_47d290
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @79_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @80_47d290
  eax = (eax - ecx);  // @81_47d290
  FL[3] = eax;  // @82_47d290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @83_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1616), sizeof v); (u32)v; });  // @84_47d290
  X0[0] = F2U((float)(s32)X0[0]);  // @85_47d290
  X0[1] = F2U((float)(s32)X0[1]);  // @86_47d290
  X0[2] = F2U((float)(s32)X0[2]);  // @87_47d290
  X0[3] = F2U((float)(s32)X0[3]);  // @88_47d290
  eax = (eax + (u32)(-2));  // @89_47d290
  FL[3] = eax;  // @90_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @91_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 20) + 0), &X0[0], 4);  // @92_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 24) + 0), &X0[0], 4);  // @93_47d290
  FL[0] = eax; FL[1] = (u32)(10);  // @94_47d290
  if (FL[0] > FL[1]) goto L47d4a8;  // @95_47d290
  switch (eax) {  // @96_47d290
  case 0: goto L47d40a;  // @97_47d290
  case 1: goto L47d46d;  // @98_47d290
  case 2: goto L47d46d;  // @99_47d290
  case 3: goto L47d46d;  // @100_47d290
  case 4: goto L47d44f;  // @101_47d290
  case 5: goto L47d44f;  // @102_47d290
  case 6: goto L47d423;  // @103_47d290
  case 7: goto L47d423;  // @104_47d290
  case 8: goto L47d423;  // @105_47d290
  case 9: goto L47d40a;  // @106_47d290
  case 10: goto L47d439;  // @107_47d290
  default: __builtin_trap(); }  // @108_47d290
  L47d40a:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1885) + 0), 4); v; });  // @110_47d290
  X2[1] = 0;  // @111_47d290
  X2[2] = 0;  // @112_47d290
  X2[3] = 0;  // @113_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; })));  // @114_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @115_47d290
  goto L47d4ab;  // @116_47d290
  L47d423:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1885) + 0), 4); v; });  // @118_47d290
  X2[1] = 0;  // @119_47d290
  X2[2] = 0;  // @120_47d290
  X2[3] = 0;  // @121_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @122_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1672) + 0), 4); v; })));  // @123_47d290
  goto L47d4ab;  // @124_47d290
  L47d439:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1893) + 0), 4); v; });  // @126_47d290
  X2[1] = 0;  // @127_47d290
  X2[2] = 0;  // @128_47d290
  X2[3] = 0;  // @129_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @130_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1672) + 0), 4); v; })));  // @131_47d290
  goto L47d4ab;  // @132_47d290
  L47d44f:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1885) + 0), 4); v; });  // @134_47d290
  X2[1] = 0;  // @135_47d290
  X2[2] = 0;  // @136_47d290
  X2[3] = 0;  // @137_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @138_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1672) + 0), 4); v; })));  // @139_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @140_47d290
  goto L47d4ab;  // @141_47d290
  L47d46d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; });  // @143_47d290
  X0[1] = 0;  // @144_47d290
  X0[2] = 0;  // @145_47d290
  X0[3] = 0;  // @146_47d290
  PV[6] = X0[0];  // @147_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1885) + 0), 4); v; });  // @148_47d290
  X0[1] = 0;  // @149_47d290
  X0[2] = 0;  // @150_47d290
  X0[3] = 0;  // @151_47d290
  PV[7] = X0[0];  // @152_47d290
  FS[0] = ext_478420_stdcall3_ld((u32)(1065353216), PV[7], PV[6]);  // @153_47d290
    // @154_47d290
  FS[0] = (FS[0] * LDF((u32)((EBP - 184) + 24)));  // @155_47d290
  STF((u32)((EBP - 184) + 24), FS[0]);  // @156_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 24) + 0), 4); v; });  // @157_47d290
  X2[1] = 0;  // @158_47d290
  X2[2] = 0;  // @159_47d290
  X2[3] = 0;  // @160_47d290
  goto L47d4ab;  // @161_47d290
  L47d4a8:;
  X2[0] = 0;  // @163_47d290
  X2[1] = 0;  // @164_47d290
  X2[2] = 0;  // @165_47d290
  X2[3] = 0;  // @166_47d290
  L47d4ab:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 0), 4); v; });  // @168_47d290
  X0[1] = 0;  // @169_47d290
  X0[2] = 0;  // @170_47d290
  X0[3] = 0;  // @171_47d290
  eax = (u32)((EBP - 184) + 84);  // @172_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1644) + 0), 4); v; })));  // @173_47d290
  PV[8] = (u32)(ecx);  // @174_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1648) + 0), 4); v; });  // @175_47d290
  X1[1] = 0;  // @176_47d290
  X1[2] = 0;  // @177_47d290
  X1[3] = 0;  // @178_47d290
  ecx = edi;  // @179_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 188) + 56) + 0), 4); v; })));  // @180_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @181_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1652) + 0), 4); v; });  // @182_47d290
  X0[1] = 0;  // @183_47d290
  X0[2] = 0;  // @184_47d290
  X0[3] = 0;  // @185_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 188) + 60) + 0), 4); v; })));  // @186_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @187_47d290
  X0[0] = 0;  // @188_47d290
  X0[1] = 0;  // @189_47d290
  X0[2] = 0;  // @190_47d290
  X0[3] = 0;  // @191_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @192_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @193_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @194_47d290
  { float a_ = U2F(X0[0]), b_ = U2F(X1[0]); X0[0] = (a_ > b_) ? X0[0] : F2U(b_); }  // @195_47d290
  PV[9] = X0[0];  // @196_47d290
  PV[10] = (u32)(eax);  // @197_47d290
  eax = (u32)((EBP - 192) + 44);  // @198_47d290
  __builtin_memcpy((void *)((u32)((EBP - 192) + 32) + 0), &X0[0], 4);  // @199_47d290
  PV[11] = (u32)(eax);  // @200_47d290
  FS[0] = ext_47eba0_thiscall4_ld(ecx, PV[11], PV[10], PV[9]);  // @201_47d290
  ecx = edx = 0;  // @202_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1644) + 0), 4); v; });  // @203_47d290
  X0[1] = 0;  // @204_47d290
  X0[2] = 0;  // @205_47d290
  X0[3] = 0;  // @206_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 0), 4); v; });  // @207_47d290
  X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 4), 4); v; });  // @208_47d290
  X1[2] = 0;  // @209_47d290
  X1[3] = 0;  // @210_47d290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1612), sizeof v); (u32)v; });  // @211_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 56), sizeof v); (u32)v; });  // @212_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 60) + 0), &X0[0], 4);  // @213_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1648) + 0), 4); v; });  // @214_47d290
  X0[1] = 0;  // @215_47d290
  X0[2] = 0;  // @216_47d290
  X0[3] = 0;  // @217_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 64) + 0), &X0[0], 4);  // @218_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1652) + 0), 4); v; });  // @219_47d290
  X0[1] = 0;  // @220_47d290
  X0[2] = 0;  // @221_47d290
  X0[3] = 0;  // @222_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 0), &X1[0], 4);  // @223_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 4), &X1[1], 4);  // @224_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 80), &v, sizeof v); }  // @225_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 68) + 0), &X0[0], 4);  // @226_47d290
  STF((u32)((EBP - 184) + 8), FS[0]);  // @227_47d290
  FL[0] = ecx; FL[1] = (u32)(11);  // @228_47d290
  if (FL[0] > FL[1]) goto L47e0df;  // @229_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; });  // @230_47d290
  X0[1] = 0;  // @231_47d290
  X0[2] = 0;  // @232_47d290
  X0[3] = 0;  // @233_47d290
  switch (ecx) {  // @234_47d290
  case 0: goto L47d575;  // @235_47d290
  case 1: goto L47e0df;  // @236_47d290
  case 2: goto L47d602;  // @237_47d290
  case 3: goto L47d628;  // @238_47d290
  case 4: goto L47d7cc;  // @239_47d290
  case 5: goto L47d7d6;  // @240_47d290
  case 6: goto L47d859;  // @241_47d290
  case 7: goto L47daad;  // @242_47d290
  case 8: goto L47dc43;  // @243_47d290
  case 9: goto L47dcd4;  // @244_47d290
  case 10: goto L47de02;  // @245_47d290
  case 11: goto L47e0c1;  // @246_47d290
  default: __builtin_trap(); }  // @247_47d290
  L47d575:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 8) + 0), 4); v; });  // @249_47d290
  X1[1] = 0;  // @250_47d290
  X1[2] = 0;  // @251_47d290
  X1[3] = 0;  // @252_47d290
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @253_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47d58f;  // @254_47d290
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @255_47d290
  goto L47e0e5;  // @256_47d290
  L47d58f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @258_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @259_47d290
  X0[1] = 0;  // @260_47d290
  X0[2] = 0;  // @261_47d290
  X0[3] = 0;  // @262_47d290
  FL[2] = (eax & eax);  // @263_47d290
  if (FL[2] == 0) goto L47d5ab;  // @264_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; }));  // @265_47d290
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L47d5b0;  // @266_47d290
  FL[2] = (eax & eax);  // @267_47d290
  if (FL[2] != 0) goto L47d5de;  // @268_47d290
  L47d5ab:;
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @270_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47d5de;  // @271_47d290
  L47d5b0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1198), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @273_47d290
  if (FL[0] != FL[1]) goto L47d5c7;  // @274_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @275_47d290
  ecx = edi;  // @276_47d290
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1452)))(ecx, (u32)(1), (u32)(0));  // @277_47d290
  ecx = edx = 0;  // @278_47d290
  L47d5c7:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1198), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @280_47d290
  if (FL[0] != FL[1]) goto L47d5de;  // @281_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @282_47d290
  ecx = edi;  // @283_47d290
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1452)))(ecx, (u32)(4), (u32)(0));  // @284_47d290
  ecx = edx = 0;  // @285_47d290
  L47d5de:;
  ecx = edi;  // @287_47d290
  eax = ext_477740_thiscall3(ecx, (u32)(2), (u32)(0));  // @288_47d290
  ecx = edx = 0;  // @289_47d290
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @290_47d290
  if (FL[2] != 0) goto L47d5f8;  // @291_47d290
  ecx = edi;  // @292_47d290
  eax = ext_477740_thiscall3(ecx, (u32)(8), (u32)(0));  // @293_47d290
  ecx = edx = 0;  // @294_47d290
  L47d5f8:;
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @296_47d290
  L47d602:;
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1616), sizeof v); (u32)v; });  // @298_47d290
  ecx = edi;  // @299_47d290
  eax = ext_479060_stdcall1(PV[12]);  // @300_47d290
    // @301_47d290
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @302_47d290
  if (FL[2] != 0) goto L47d61e;  // @303_47d290
  ecx = edi;  // @304_47d290
  eax = ext_477740_thiscall3(ecx, (u32)(8), (u32)(0));  // @305_47d290
  ecx = edx = 0;  // @306_47d290
  L47d61e:;
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @308_47d290
  L47d628:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1664) + 0), 4); v; });  // @310_47d290
  X1[1] = 0;  // @311_47d290
  X1[2] = 0;  // @312_47d290
  X1[3] = 0;  // @313_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 0), 4); v; });  // @314_47d290
  X0[1] = 0;  // @315_47d290
  X0[2] = 0;  // @316_47d290
  X0[3] = 0;  // @317_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1660) + 0), 4); v; })));  // @318_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 52) + 0), 4); v; })));  // @319_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @320_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1668) + 0), 4); v; });  // @321_47d290
  X0[1] = 0;  // @322_47d290
  X0[2] = 0;  // @323_47d290
  X0[3] = 0;  // @324_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 56) + 0), 4); v; })));  // @325_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @326_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860528) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860528) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @327_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 12) + 0), &X1[0], 4);  // @328_47d290
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @329_47d290
  ecx = edx = 0;  // @330_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 12) + 0), 4); v; });  // @331_47d290
  X2[1] = 0;  // @332_47d290
  X2[2] = 0;  // @333_47d290
  X2[3] = 0;  // @334_47d290
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @335_47d290
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @336_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47d6d2;  // @337_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @338_47d290
  ecx = edi;  // @339_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1448), sizeof v); (u32)v; });  // @340_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(11));  // @341_47d290
  ecx = edx = 0;  // @342_47d290
  FL[2] = (eax & eax);  // @343_47d290
  if (FL[2] == 0) goto L47d6d2;  // @344_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 0), 4); v; });  // @345_47d290
  X0[1] = 0;  // @346_47d290
  X0[2] = 0;  // @347_47d290
  X0[3] = 0;  // @348_47d290
  ecx = edi;  // @349_47d290
  __builtin_memcpy((void *)((u32)(edi + 1702) + 0), &X0[0], 4);  // @350_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 52) + 0), 4); v; });  // @351_47d290
  X0[1] = 0;  // @352_47d290
  X0[2] = 0;  // @353_47d290
  X0[3] = 0;  // @354_47d290
  __builtin_memcpy((void *)((u32)(edi + 1706) + 0), &X0[0], 4);  // @355_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 56) + 0), 4); v; });  // @356_47d290
  X0[1] = 0;  // @357_47d290
  X0[2] = 0;  // @358_47d290
  X0[3] = 0;  // @359_47d290
  __builtin_memcpy((void *)((u32)(edi + 1710) + 0), &X0[0], 4);  // @360_47d290
  eax = ext_477740_thiscall3(ecx, (u32)(11), (u32)(0));  // @361_47d290
  ecx = edx = 0;  // @362_47d290
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @363_47d290
  goto L47e0df;  // @364_47d290
  L47d6d2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1885) + 0), 4); v; });  // @366_47d290
  X0[1] = 0;  // @367_47d290
  X0[2] = 0;  // @368_47d290
  X0[3] = 0;  // @369_47d290
  eax = (u32)((EBP - 184) + 60);  // @370_47d290
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6835440) + 0), 4); v; })));  // @371_47d290
  PV[13] = (u32)(ecx);  // @372_47d290
  ecx = edi;  // @373_47d290
  PV[14] = X0[0];  // @374_47d290
  PV[15] = (u32)(eax);  // @375_47d290
  eax = (u32)((EBP - 192) + 56);  // @376_47d290
  PV[16] = (u32)(eax);  // @377_47d290
  eax = (u32)((EBP - 196) + 84);  // @378_47d290
  PV[17] = (u32)(eax);  // @379_47d290
  eax = ext_47ca20_fastcall6(ecx, edx, PV[17], PV[16], PV[15], PV[14]);  // @380_47d290
  ecx = edx = 0;  // @381_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1672) + 0), 4); v; });  // @382_47d290
  X0[1] = 0;  // @383_47d290
  X0[2] = 0;  // @384_47d290
  X0[3] = 0;  // @385_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 20) + 0), 4); v; })));  // @386_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 8) + 0), 4); v; });  // @387_47d290
  X1[1] = 0;  // @388_47d290
  X1[2] = 0;  // @389_47d290
  X1[3] = 0;  // @390_47d290
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1881) + 0), 4); v; })));  // @391_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; })));  // @392_47d290
  __builtin_memcpy((void *)((u32)(edi + 1877) + 0), &X0[0], 4);  // @393_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1822) + 0), 4); v; });  // @394_47d290
  X0[1] = 0;  // @395_47d290
  X0[2] = 0;  // @396_47d290
  X0[3] = 0;  // @397_47d290
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @398_47d290
  if ((!(FA >= FB))) goto L47d7ac;  // @399_47d290
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @400_47d290
  if (FL[0] != FL[1]) goto L47d7ac;  // @401_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @402_47d290
  esi = (u32)(3);  // @403_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1810) + 0), 4); v; });  // @404_47d290
  X0[1] = 0;  // @405_47d290
  X0[2] = 0;  // @406_47d290
  X0[3] = 0;  // @407_47d290
  ecx = edi;  // @408_47d290
  PV[18] = (u32)(esi);  // @409_47d290
  __builtin_memcpy((void *)((u32)((EBP - 188) + 16) + 0), &X0[0], 4);  // @410_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1448), sizeof v); (u32)v; });  // @411_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[18]);  // @412_47d290
  ecx = edx = 0;  // @413_47d290
  FL[2] = (eax & eax);  // @414_47d290
  if (FL[2] != 0) goto L47d781;  // @415_47d290
  { u32 v = (u32)((u32)(1101004800)); __builtin_memcpy((void *)(u32)(edi + 1810), &v, sizeof v); }  // @416_47d290
  esi = (u32)(eax + 8);  // @417_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1877), &v, sizeof v); }  // @418_47d290
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi + 1881), &v, sizeof v); }  // @419_47d290
  L47d781:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 8) + 0), 4); v; });  // @421_47d290
  X1[1] = 0;  // @422_47d290
  X1[2] = 0;  // @423_47d290
  X1[3] = 0;  // @424_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 12) + 0), 4); v; });  // @425_47d290
  X0[1] = 0;  // @426_47d290
  X0[2] = 0;  // @427_47d290
  X0[3] = 0;  // @428_47d290
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @429_47d290
  if ((!(FA >= FB))) goto L47d7ac;  // @430_47d290
  PV[19] = (u32)(esi);  // @431_47d290
  ecx = edi;  // @432_47d290
  eax = ext_477740_thiscall3(ecx, PV[19], (u32)(0));  // @433_47d290
  ecx = edx = 0;  // @434_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 8) + 0), 4); v; });  // @435_47d290
  X1[1] = 0;  // @436_47d290
  X1[2] = 0;  // @437_47d290
  X1[3] = 0;  // @438_47d290
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @439_47d290
  L47d7ac:;
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @441_47d290
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @442_47d290
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @443_47d290
  if (!__builtin_parity(FL[2] & 0xff)) goto L47e0e5;  // @444_47d290
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @445_47d290
  goto L47e0e5;  // @446_47d290
  L47d7cc:;
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @448_47d290
  L47d7d6:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @450_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 20) + 0), 4); v; });  // @451_47d290
  X2[1] = 0;  // @452_47d290
  X2[2] = 0;  // @453_47d290
  X2[3] = 0;  // @454_47d290
  X2[0] = F2U(U2F(X2[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1881) + 0), 4); v; })));  // @455_47d290
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; })));  // @456_47d290
  __builtin_memcpy((void *)((u32)(edi + 1877) + 0), &X2[0], 4);  // @457_47d290
  if (FL[0] == FL[1]) goto L47d80c;  // @458_47d290
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @459_47d290
  goto L47e0df;  // @460_47d290
  L47d80c:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @462_47d290
  X0[1] = 0;  // @463_47d290
  X0[2] = 0;  // @464_47d290
  X0[3] = 0;  // @465_47d290
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @466_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47d84f;  // @467_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 8) + 0), 4); v; });  // @468_47d290
  X0[1] = 0;  // @469_47d290
  X0[2] = 0;  // @470_47d290
  X0[3] = 0;  // @471_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @472_47d290
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @473_47d290
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @474_47d290
  if (__builtin_parity(FL[2] & 0xff)) goto L47d84f;  // @475_47d290
  PV[20] = (u32)(ecx);  // @476_47d290
  eax = (u32)((EBP - 188) + 64);  // @477_47d290
  PV[21] = (u32)(eax);  // @478_47d290
  eax = (u32)((EBP - 192) + 56);  // @479_47d290
  ecx = edi;  // @480_47d290
  PV[22] = (u32)(eax);  // @481_47d290
  eax = (u32)((EBP - 196) + 84);  // @482_47d290
  PV[23] = (u32)(eax);  // @483_47d290
  eax = ext_47ca20_fastcall6(ecx, edx, PV[23], PV[22], PV[21], (u32)(1078530011));  // @484_47d290
  ecx = edx = 0;  // @485_47d290
  goto L47e0df;  // @486_47d290
  L47d84f:;
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @488_47d290
  L47d859:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1689), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @490_47d290
  if (FL[0] == FL[1]) goto L47da74;  // @491_47d290
  edx = (u32)(edi + 1690);  // @492_47d290
  ecx = (u32)((EBP - 184) + 48);  // @493_47d290
  eax = ext_47f680_fastcall2(ecx, edx);  // @494_47d290
    // @495_47d290
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @496_47d290
  if (FL[2] != 0) goto L47da74;  // @497_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 0), 4); v; });  // @498_47d290
  X0[1] = 0;  // @499_47d290
  X0[2] = 0;  // @500_47d290
  X0[3] = 0;  // @501_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1694) + 0), 4); v; });  // @502_47d290
  X1[1] = 0;  // @503_47d290
  X1[2] = 0;  // @504_47d290
  X1[3] = 0;  // @505_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1690) + 0), 4); v; })));  // @506_47d290
  PV[24] = (u32)(ecx);  // @507_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 188) + 56) + 0), 4); v; })));  // @508_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @509_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1698) + 0), 4); v; });  // @510_47d290
  X0[1] = 0;  // @511_47d290
  X0[2] = 0;  // @512_47d290
  X0[3] = 0;  // @513_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 188) + 60) + 0), 4); v; })));  // @514_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @515_47d290
  PV[25] = X1[0];  // @516_47d290
  FS[0] = ext_477620_stdcall1_ld(PV[25]);  // @517_47d290
  ecx = edx = 0;  // @518_47d290
  eax = (u32)((EBP - 184) + 48);  // @519_47d290
  PV[26] = (u32)(eax);  // @520_47d290
  edx = (u32)(edi + 1690);  // @521_47d290
  ecx = (u32)((EBP - 188) + 100);  // @522_47d290
  STF((u32)((EBP - 188) + 24), FS[0]);  // @523_47d290
  eax = ext_446ee0_fastcall3(ecx, edx, PV[26]);  // @524_47d290
  ecx = edx = 0;  // @525_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 100) + 0), 4); v; });  // @526_47d290
  X0[1] = 0;  // @527_47d290
  X0[2] = 0;  // @528_47d290
  X0[3] = 0;  // @529_47d290
  ecx = (u32)(7233048);  // @530_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @531_47d290
  eax = (u32)(7233080);  // @532_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860600) + 0), 4); v; });  // @533_47d290
  X2[1] = 0;  // @534_47d290
  X2[2] = 0;  // @535_47d290
  X2[3] = 0;  // @536_47d290
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 20) + 0), 4); v; });  // @537_47d290
  X4[1] = 0;  // @538_47d290
  X4[2] = 0;  // @539_47d290
  X4[3] = 0;  // @540_47d290
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X5[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X5[2] = X5[3] = 0;  // @541_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) ecx = eax;  // @542_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @543_47d290
  X0[1] = 0;  // @544_47d290
  X0[2] = 0;  // @545_47d290
  X0[3] = 0;  // @546_47d290
  edx = 0;  // @547_47d290
  FL[3] = edx;  // @548_47d290
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806056) + 0), 4); v; });  // @549_47d290
  X3[1] = 0;  // @550_47d290
  X3[2] = 0;  // @551_47d290
  X3[3] = 0;  // @552_47d290
  esi = 0;  // @553_47d290
  FL[3] = esi;  // @554_47d290
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 184) + 28), &v, sizeof v); }  // @555_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 32) + 0), &X2[0], 4);  // @556_47d290
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 184) + 12), &v, sizeof v); }  // @557_47d290
  L47d924:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + esi*8) + 0), 4); v; });  // @559_47d290
  X1[1] = 0;  // @560_47d290
  X1[2] = 0;  // @561_47d290
  X1[3] = 0;  // @562_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @563_47d290
  X0[0] = X4[0];  // @564_47d290
  X0[1] = X4[1];  // @565_47d290
  X0[2] = X4[2];  // @566_47d290
  X0[3] = X4[3];  // @567_47d290
  X1[0] = F2U(U2F(X1[0]) / U2F(X3[0]));  // @568_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @569_47d290
  X1[0] = 0;  // @570_47d290
  X1[1] = 0;  // @571_47d290
  X1[2] = 0;  // @572_47d290
  X1[3] = 0;  // @573_47d290
  SD(&X1[0], (double)U2F(X0[0]));  // @574_47d290
  X0[0] = X4[0];  // @575_47d290
  X0[1] = X4[1];  // @576_47d290
  X0[2] = X4[2];  // @577_47d290
  X0[3] = X4[3];  // @578_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @579_47d290
  X1[0] = X1[0] & X5[0];  // @580_47d290
  X1[1] = X1[1] & X5[1];  // @581_47d290
  X1[2] = X1[2] & X5[2];  // @582_47d290
  X1[3] = X1[3] & X5[3];  // @583_47d290
  SD(&X0[0], (double)U2F(X0[0]));  // @584_47d290
  X0[0] = X0[0] & X5[0];  // @585_47d290
  X0[1] = X0[1] & X5[1];  // @586_47d290
  X0[2] = X0[2] & X5[2];  // @587_47d290
  X0[3] = X0[3] & X5[3];  // @588_47d290
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @589_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47d9b5;  // @590_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @591_47d290
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi*8 + 4), sizeof v); (u32)v; });  // @592_47d290
  ecx = edi;  // @593_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1448), sizeof v); (u32)v; });  // @594_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[27]);  // @595_47d290
  ecx = edx = 0;  // @596_47d290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 28), sizeof v); (u32)v; });  // @597_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @598_47d290
  X0[1] = 0;  // @599_47d290
  X0[2] = 0;  // @600_47d290
  X0[3] = 0;  // @601_47d290
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806056) + 0), 4); v; });  // @602_47d290
  X3[1] = 0;  // @603_47d290
  X3[2] = 0;  // @604_47d290
  X3[3] = 0;  // @605_47d290
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 20) + 0), 4); v; });  // @606_47d290
  X4[1] = 0;  // @607_47d290
  X4[2] = 0;  // @608_47d290
  X4[3] = 0;  // @609_47d290
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X5[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X5[2] = X5[3] = 0;  // @610_47d290
  FL[2] = (eax & eax);  // @611_47d290
  if (FL[2] == 0) goto L47d9a9;  // @612_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + esi*8) + 0), 4); v; });  // @613_47d290
  X2[1] = 0;  // @614_47d290
  X2[2] = 0;  // @615_47d290
  X2[3] = 0;  // @616_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @617_47d290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi*8 + 4), sizeof v); (u32)v; });  // @618_47d290
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 184) + 12), &v, sizeof v); }  // @619_47d290
  X2[0] = F2U(U2F(X2[0]) / U2F(X3[0]));  // @620_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 32) + 0), &X2[0], 4);  // @621_47d290
  goto L47d9bd;  // @622_47d290
  L47d9a9:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 32) + 0), 4); v; });  // @624_47d290
  X2[1] = 0;  // @625_47d290
  X2[2] = 0;  // @626_47d290
  X2[3] = 0;  // @627_47d290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 12), sizeof v); (u32)v; });  // @628_47d290
  goto L47d9bd;  // @629_47d290
  L47d9b5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @631_47d290
  X0[1] = 0;  // @632_47d290
  X0[2] = 0;  // @633_47d290
  X0[3] = 0;  // @634_47d290
  L47d9bd:;
  esi = (esi + 1);  // @636_47d290
  FL[3] = esi;  // @637_47d290
  FL[0] = esi; FL[1] = (u32)(3);  // @638_47d290
  if ((s32)FL[0] < (s32)FL[1]) goto L47d924;  // @639_47d290
  FL[2] = (edx & edx);  // @640_47d290
  if (FL[2] == 0) goto L47da74;  // @641_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 84) + 0), 4); v; });  // @642_47d290
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 84) + 4), 4); v; });  // @643_47d290
  X0[2] = 0;  // @644_47d290
  X0[3] = 0;  // @645_47d290
  ecx = edi;  // @646_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 92), sizeof v); (u32)v; });  // @647_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @648_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 4), &X0[1], 4);  // @649_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 0), 4); v; });  // @650_47d290
  X0[1] = 0;  // @651_47d290
  X0[2] = 0;  // @652_47d290
  X0[3] = 0;  // @653_47d290
  __builtin_memcpy((void *)((u32)(edi + 1702) + 0), &X0[0], 4);  // @654_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 52) + 0), 4); v; });  // @655_47d290
  X0[1] = 0;  // @656_47d290
  X0[2] = 0;  // @657_47d290
  X0[3] = 0;  // @658_47d290
  __builtin_memcpy((void *)((u32)(edi + 1706) + 0), &X0[0], 4);  // @659_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 56) + 0), 4); v; });  // @660_47d290
  X0[1] = 0;  // @661_47d290
  X0[2] = 0;  // @662_47d290
  X0[3] = 0;  // @663_47d290
  __builtin_memcpy((void *)((u32)(edi + 1710) + 0), &X0[0], 4);  // @664_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 84) + 0), 4); v; });  // @665_47d290
  X0[1] = 0;  // @666_47d290
  X0[2] = 0;  // @667_47d290
  X0[3] = 0;  // @668_47d290
  __builtin_memcpy((void *)((u32)(edi + 1754) + 0), &X0[0], 4);  // @669_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 88) + 0), 4); v; });  // @670_47d290
  X0[1] = 0;  // @671_47d290
  X0[2] = 0;  // @672_47d290
  X0[3] = 0;  // @673_47d290
  __builtin_memcpy((void *)((u32)(edi + 1758) + 0), &X0[0], 4);  // @674_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 92) + 0), 4); v; });  // @675_47d290
  X0[1] = 0;  // @676_47d290
  X0[2] = 0;  // @677_47d290
  X0[3] = 0;  // @678_47d290
  __builtin_memcpy((void *)((u32)(edi + 1762) + 0), &X0[0], 4);  // @679_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 44), &v, sizeof v); }  // @680_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1632), sizeof v); (u32)v; });  // @681_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1766), &v, sizeof v); }  // @682_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1636), sizeof v); (u32)v; });  // @683_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1770), &v, sizeof v); }  // @684_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1640), sizeof v); (u32)v; });  // @685_47d290
  PV[28] = (u32)(edx);  // @686_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1774), &v, sizeof v); }  // @687_47d290
  eax = ext_477740_thiscall3(ecx, PV[28], (u32)(0));  // @688_47d290
  ecx = edx = 0;  // @689_47d290
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @690_47d290
  goto L47e0df;  // @691_47d290
  L47da74:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1632) + 0), 4); v; });  // @693_47d290
  X0[1] = 0;  // @694_47d290
  X0[2] = 0;  // @695_47d290
  X0[3] = 0;  // @696_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @697_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1636) + 0), 4); v; });  // @698_47d290
  X0[1] = 0;  // @699_47d290
  X0[2] = 0;  // @700_47d290
  X0[3] = 0;  // @701_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X0[0], 4);  // @702_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1640) + 0), 4); v; });  // @703_47d290
  X0[1] = 0;  // @704_47d290
  X0[2] = 0;  // @705_47d290
  X0[3] = 0;  // @706_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 44) + 0), &X0[0], 4);  // @707_47d290
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @708_47d290
  goto L47e0df;  // @709_47d290
  L47daad:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @711_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 20) + 0), 4); v; });  // @712_47d290
  X0[1] = 0;  // @713_47d290
  X0[2] = 0;  // @714_47d290
  X0[3] = 0;  // @715_47d290
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1881) + 0), 4); v; })));  // @716_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; })));  // @717_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 20) + 0), &X0[0], 4);  // @718_47d290
  __builtin_memcpy((void *)((u32)(edi + 1877) + 0), &X0[0], 4);  // @719_47d290
  if (FL[0] == FL[1]) goto L47dae9;  // @720_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @721_47d290
  goto L47e0df;  // @722_47d290
  L47dae9:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @724_47d290
  X3[1] = 0;  // @725_47d290
  X3[2] = 0;  // @726_47d290
  X3[3] = 0;  // @727_47d290
  FA = U2F(X3[0]); FB = U2F(X0[0]);  // @728_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47dc39;  // @729_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1694) + 0), 4); v; });  // @730_47d290
  X1[1] = 0;  // @731_47d290
  X1[2] = 0;  // @732_47d290
  X1[3] = 0;  // @733_47d290
  edx = (u32)(edi + 1690);  // @734_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1706) + 0), 4); v; })));  // @735_47d290
  esi = (u32)(edi + 1702);  // @736_47d290
  ecx = (u32)((EBP - 184) + 96);  // @737_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 28) + 0), &X0[0], 4);  // @738_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx) + 0), 4); v; });  // @739_47d290
  X0[1] = 0;  // @740_47d290
  X0[2] = 0;  // @741_47d290
  X0[3] = 0;  // @742_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @743_47d290
  PV[29] = (u32)(esi);  // @744_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @745_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 8) + 0), 4); v; });  // @746_47d290
  X0[1] = 0;  // @747_47d290
  X0[2] = 0;  // @748_47d290
  X0[3] = 0;  // @749_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; })));  // @750_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @751_47d290
  __builtin_memcpy((void *)((u32)((EBP - 188) + 16) + 0), &X1[0], 4);  // @752_47d290
  eax = ext_446ee0_fastcall3(ecx, edx, PV[29]);  // @753_47d290
  ecx = edx = 0;  // @754_47d290
  X0[0] = 0;  // @755_47d290
  X0[1] = 0;  // @756_47d290
  X0[2] = 0;  // @757_47d290
  X0[3] = 0;  // @758_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 60), &v, sizeof v); }  // @759_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 100) + 0), 4); v; }));  // @760_47d290
  PV[30] = (u32)(ecx);  // @761_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 188) + 16) + 0), 4); v; });  // @762_47d290
  X0[1] = 0;  // @763_47d290
  X0[2] = 0;  // @764_47d290
  X0[3] = 0;  // @765_47d290
  PV[31] = X0[0];  // @766_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47db73;  // @767_47d290
  FS[0] = ext_477620_stdcall1_ld(PV[31]);  // @768_47d290
  ecx = edx = 0;  // @769_47d290
  FS[0] = (FS[0] * LDF((u32)((EBP - 184) + 28)));  // @770_47d290
  STF((u32)((EBP - 184) + 64), FS[0]);  // @771_47d290
  goto L47db93;  // @772_47d290
  L47db73:;
  FS[0] = ext_477620_stdcall1_ld(PV[31]);  // @774_47d290
  ecx = edx = 0;  // @775_47d290
  FS[0] = (FS[0] * LDF((u32)((EBP - 184) + 28)));  // @776_47d290
  STF((u32)((EBP - 184) + 12), FS[0]);  // @777_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 12) + 0), 4); v; });  // @778_47d290
  X0[1] = 0;  // @779_47d290
  X0[2] = 0;  // @780_47d290
  X0[3] = 0;  // @781_47d290
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @782_47d290
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @783_47d290
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @784_47d290
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @785_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 64) + 0), &X0[0], 4);  // @786_47d290
  L47db93:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1754) + 0), 4); v; });  // @788_47d290
  X1[1] = 0;  // @789_47d290
  X1[2] = 0;  // @790_47d290
  X1[3] = 0;  // @791_47d290
  edx = (u32)((EBP - 184) + 60);  // @792_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1766) + 0), 4); v; });  // @793_47d290
  X0[1] = 0;  // @794_47d290
  X0[2] = 0;  // @795_47d290
  X0[3] = 0;  // @796_47d290
  ecx = (u32)((EBP - 184) + 72);  // @797_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 20) + 0), 4); v; });  // @798_47d290
  X2[1] = 0;  // @799_47d290
  X2[2] = 0;  // @800_47d290
  X2[3] = 0;  // @801_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @802_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 68), &v, sizeof v); }  // @803_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @804_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @805_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1758) + 0), 4); v; });  // @806_47d290
  X1[1] = 0;  // @807_47d290
  X1[2] = 0;  // @808_47d290
  X1[3] = 0;  // @809_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @810_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1770) + 0), 4); v; });  // @811_47d290
  X0[1] = 0;  // @812_47d290
  X0[2] = 0;  // @813_47d290
  X0[3] = 0;  // @814_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @815_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @816_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @817_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1762) + 0), 4); v; });  // @818_47d290
  X1[1] = 0;  // @819_47d290
  X1[2] = 0;  // @820_47d290
  X1[3] = 0;  // @821_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X0[0], 4);  // @822_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1774) + 0), 4); v; });  // @823_47d290
  X0[1] = 0;  // @824_47d290
  X0[2] = 0;  // @825_47d290
  X0[3] = 0;  // @826_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @827_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @828_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @829_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 44) + 0), &X0[0], 4);  // @830_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @831_47d290
  X0[1] = 0;  // @832_47d290
  X0[2] = 0;  // @833_47d290
  X0[3] = 0;  // @834_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 0), &X0[0], 4);  // @835_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @836_47d290
  X0[1] = 0;  // @837_47d290
  X0[2] = 0;  // @838_47d290
  X0[3] = 0;  // @839_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 76) + 0), &X0[0], 4);  // @840_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @841_47d290
  X0[1] = 0;  // @842_47d290
  X0[2] = 0;  // @843_47d290
  X0[3] = 0;  // @844_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 80) + 0), &X0[0], 4);  // @845_47d290
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @846_47d290
  ecx = edx = 0;  // @847_47d290
  goto L47e0df;  // @848_47d290
  L47dc39:;
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @850_47d290
  L47dc43:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @852_47d290
  if (FL[0] == FL[1]) goto L47dc5b;  // @853_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @854_47d290
  goto L47e0df;  // @855_47d290
  L47dc5b:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1689), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @857_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1632) + 0), 4); v; });  // @858_47d290
  X0[1] = 0;  // @859_47d290
  X0[2] = 0;  // @860_47d290
  X0[3] = 0;  // @861_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @862_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1636) + 0), 4); v; });  // @863_47d290
  X0[1] = 0;  // @864_47d290
  X0[2] = 0;  // @865_47d290
  X0[3] = 0;  // @866_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X0[0], 4);  // @867_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1640) + 0), 4); v; });  // @868_47d290
  X0[1] = 0;  // @869_47d290
  X0[2] = 0;  // @870_47d290
  X0[3] = 0;  // @871_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 44) + 0), &X0[0], 4);  // @872_47d290
  if (FL[0] == FL[1]) goto L47dcb8;  // @873_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1690) + 0), 4); v; });  // @874_47d290
  X0[1] = 0;  // @875_47d290
  X0[2] = 0;  // @876_47d290
  X0[3] = 0;  // @877_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 0), &X0[0], 4);  // @878_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1694) + 0), 4); v; });  // @879_47d290
  X0[1] = 0;  // @880_47d290
  X0[2] = 0;  // @881_47d290
  X0[3] = 0;  // @882_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 76) + 0), &X0[0], 4);  // @883_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1698) + 0), 4); v; });  // @884_47d290
  X0[1] = 0;  // @885_47d290
  X0[2] = 0;  // @886_47d290
  X0[3] = 0;  // @887_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 80) + 0), &X0[0], 4);  // @888_47d290
  L47dcb8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @890_47d290
  ecx = edi;  // @891_47d290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1580)))(ecx, (u32)(0));  // @892_47d290
  ecx = edx = 0;  // @893_47d290
  ecx = edi;  // @894_47d290
  eax = ext_477740_thiscall3(ecx, (u32)(1), (u32)(0));  // @895_47d290
  ecx = edx = 0;  // @896_47d290
  goto L47e0df;  // @897_47d290
  L47dcd4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @899_47d290
  ecx = edi;  // @900_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1448), sizeof v); (u32)v; });  // @901_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(11));  // @902_47d290
  ecx = edx = 0;  // @903_47d290
  FL[2] = (eax & eax);  // @904_47d290
  if (FL[2] != 0) goto L47dcf5;  // @905_47d290
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @906_47d290
  goto L47e0df;  // @907_47d290
  L47dcf5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1672) + 0), 4); v; });  // @909_47d290
  X0[1] = 0;  // @910_47d290
  X0[2] = 0;  // @911_47d290
  X0[3] = 0;  // @912_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 20) + 0), 4); v; })));  // @913_47d290
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1881) + 0), 4); v; })));  // @914_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; })));  // @915_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @916_47d290
  __builtin_memcpy((void *)((u32)(edi + 1877) + 0), &X0[0], 4);  // @917_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47dd3e;  // @918_47d290
  ecx = edi;  // @919_47d290
  eax = ext_477740_thiscall3(ecx, (u32)(8), (u32)(0));  // @920_47d290
  ecx = edx = 0;  // @921_47d290
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @922_47d290
  goto L47e0df;  // @923_47d290
  L47dd3e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1660) + 0), 4); v; });  // @925_47d290
  X0[1] = 0;  // @926_47d290
  X0[2] = 0;  // @927_47d290
  X0[3] = 0;  // @928_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1664) + 0), 4); v; });  // @929_47d290
  X1[1] = 0;  // @930_47d290
  X1[2] = 0;  // @931_47d290
  X1[3] = 0;  // @932_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1702) + 0), 4); v; })));  // @933_47d290
  PV[32] = (u32)(ecx);  // @934_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1706) + 0), 4); v; })));  // @935_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @936_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1668) + 0), 4); v; });  // @937_47d290
  X0[1] = 0;  // @938_47d290
  X0[2] = 0;  // @939_47d290
  X0[3] = 0;  // @940_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1710) + 0), 4); v; })));  // @941_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @942_47d290
  PV[33] = X1[0];  // @943_47d290
  FS[0] = ext_477620_stdcall1_ld(PV[33]);  // @944_47d290
  ecx = edx = 0;  // @945_47d290
  eax = (u32)(edi + 1702);  // @946_47d290
  PV[34] = (u32)(eax);  // @947_47d290
  edx = (u32)(edi + 1660);  // @948_47d290
  ecx = (u32)((EBP - 188) + 100);  // @949_47d290
  STF((u32)((EBP - 188) + 16), FS[0]);  // @950_47d290
  eax = ext_446ee0_fastcall3(ecx, edx, PV[34]);  // @951_47d290
  ecx = edx = 0;  // @952_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 100) + 0), 4); v; });  // @953_47d290
  X0[1] = 0;  // @954_47d290
  X0[2] = 0;  // @955_47d290
  X0[3] = 0;  // @956_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @957_47d290
  if ((!(FA >= FB))) goto L47ddba;  // @958_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; });  // @959_47d290
  X1[1] = 0;  // @960_47d290
  X1[2] = 0;  // @961_47d290
  X1[3] = 0;  // @962_47d290
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 12) + 0), 4); v; })));  // @963_47d290
  goto L47ddc0;  // @964_47d290
  L47ddba:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 12) + 0), 4); v; });  // @966_47d290
  X1[1] = 0;  // @967_47d290
  X1[2] = 0;  // @968_47d290
  X1[3] = 0;  // @969_47d290
  L47ddc0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; });  // @971_47d290
  X0[1] = 0;  // @972_47d290
  X0[2] = 0;  // @973_47d290
  X0[3] = 0;  // @974_47d290
  eax = (u32)((EBP - 184) + 60);  // @975_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @976_47d290
  edx = (u32)(edi + 1702);  // @977_47d290
  PV[35] = (u32)(eax);  // @978_47d290
  ecx = (u32)((EBP - 188) + 76);  // @979_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 188) + 64), &v, sizeof v); }  // @980_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 188) + 72), &v, sizeof v); }  // @981_47d290
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @982_47d290
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @983_47d290
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @984_47d290
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @985_47d290
  __builtin_memcpy((void *)((u32)((EBP - 188) + 68) + 0), &X0[0], 4);  // @986_47d290
  eax = ext_4e0ab0_fastcall3(ecx, edx, PV[35]);  // @987_47d290
  ecx = edx = 0;  // @988_47d290
  goto L47e0df;  // @989_47d290
  L47de02:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1778) + 0), 4); v; });  // @991_47d290
  X0[1] = 0;  // @992_47d290
  X0[2] = 0;  // @993_47d290
  X0[3] = 0;  // @994_47d290
  eax = (u32)((EBP - 184) + 60);  // @995_47d290
  PV[36] = (u32)(ecx);  // @996_47d290
  ecx = edi;  // @997_47d290
  PV[37] = (u32)(eax);  // @998_47d290
  __builtin_memcpy((void *)((u32)((EBP - 192) + 68) + 0), &X0[0], 4);  // @999_47d290
  eax = (u32)((EBP - 192) + 56);  // @1000_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1782) + 0), 4); v; });  // @1001_47d290
  X0[1] = 0;  // @1002_47d290
  X0[2] = 0;  // @1003_47d290
  X0[3] = 0;  // @1004_47d290
  PV[38] = (u32)(eax);  // @1005_47d290
  __builtin_memcpy((void *)((u32)((EBP - 196) + 76) + 0), &X0[0], 4);  // @1006_47d290
  eax = (u32)((EBP - 196) + 84);  // @1007_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1786) + 0), 4); v; });  // @1008_47d290
  X0[1] = 0;  // @1009_47d290
  X0[2] = 0;  // @1010_47d290
  X0[3] = 0;  // @1011_47d290
  PV[39] = (u32)(eax);  // @1012_47d290
  __builtin_memcpy((void *)((u32)((EBP - 200) + 84) + 0), &X0[0], 4);  // @1013_47d290
  eax = ext_47ca20_fastcall6(ecx, edx, PV[39], PV[38], PV[37], (u32)(1086918619));  // @1014_47d290
  ecx = edx = 0;  // @1015_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1672) + 0), 4); v; });  // @1016_47d290
  X0[1] = 0;  // @1017_47d290
  X0[2] = 0;  // @1018_47d290
  X0[3] = 0;  // @1019_47d290
  ecx = edi;  // @1020_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 20) + 0), 4); v; });  // @1021_47d290
  X2[1] = 0;  // @1022_47d290
  X2[2] = 0;  // @1023_47d290
  X2[3] = 0;  // @1024_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @1025_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1026_47d290
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1616), sizeof v); (u32)v; });  // @1027_47d290
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1881) + 0), 4); v; })));  // @1028_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1448), sizeof v); (u32)v; });  // @1029_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; })));  // @1030_47d290
  __builtin_memcpy((void *)((u32)(edi + 1877) + 0), &X0[0], 4);  // @1031_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[40]);  // @1032_47d290
  ecx = edx = 0;  // @1033_47d290
  esi = eax;  // @1034_47d290
  ecx = esi;  // @1035_47d290
  eax = ext_478a80_thiscall1(ecx);  // @1036_47d290
  ecx = 0;  // @1037_47d290
  ecx = esi;  // @1038_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 96), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @1039_47d290
  X0[0] = F2U((float)(s32)X0[0]);  // @1040_47d290
  X0[1] = F2U((float)(s32)X0[1]);  // @1041_47d290
  X0[2] = F2U((float)(s32)X0[2]);  // @1042_47d290
  X0[3] = F2U((float)(s32)X0[3]);  // @1043_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 12) + 0), &X0[0], 4);  // @1044_47d290
  eax = ext_478a80_thiscall1(ecx);  // @1045_47d290
  ecx = 0;  // @1046_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 12) + 0), 4); v; });  // @1047_47d290
  X1[1] = 0;  // @1048_47d290
  X1[2] = 0;  // @1049_47d290
  X1[3] = 0;  // @1050_47d290
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; });  // @1051_47d290
  X4[1] = 0;  // @1052_47d290
  X4[2] = 0;  // @1053_47d290
  X4[3] = 0;  // @1054_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 100), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @1055_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1616), sizeof v); (u32)v; });  // @1056_47d290
  X0[0] = F2U((float)(s32)X0[0]);  // @1057_47d290
  X0[1] = F2U((float)(s32)X0[1]);  // @1058_47d290
  X0[2] = F2U((float)(s32)X0[2]);  // @1059_47d290
  X0[3] = F2U((float)(s32)X0[3]);  // @1060_47d290
  eax = (eax + (u32)(-20));  // @1061_47d290
  FL[3] = eax;  // @1062_47d290
  X2[0] = X0[0];  // @1063_47d290
  X2[1] = X0[1];  // @1064_47d290
  X2[2] = X0[2];  // @1065_47d290
  X2[3] = X0[3];  // @1066_47d290
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @1067_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(X4[0]));  // @1068_47d290
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @1069_47d290
  FL[0] = eax; FL[1] = (u32)(6);  // @1070_47d290
  if (FL[0] > FL[1]) goto L47df48;  // @1071_47d290
  switch (eax) {  // @1072_47d290
  case 0: goto L47dede;  // @1073_47d290
  case 1: goto L47def0;  // @1074_47d290
  case 2: goto L47dede;  // @1075_47d290
  case 3: goto L47df02;  // @1076_47d290
  case 4: goto L47df14;  // @1077_47d290
  case 5: goto L47df26;  // @1078_47d290
  case 6: goto L47df38;  // @1079_47d290
  default: __builtin_trap(); }  // @1080_47d290
  L47dede:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6823368) + 0), 4); v; });  // @1082_47d290
  X1[1] = 0;  // @1083_47d290
  X1[2] = 0;  // @1084_47d290
  X1[3] = 0;  // @1085_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860548) + 0), 4); v; });  // @1086_47d290
  X0[1] = 0;  // @1087_47d290
  X0[2] = 0;  // @1088_47d290
  X0[3] = 0;  // @1089_47d290
  goto L47df48;  // @1090_47d290
  L47def0:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; });  // @1092_47d290
  X1[1] = 0;  // @1093_47d290
  X1[2] = 0;  // @1094_47d290
  X1[3] = 0;  // @1095_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806044) + 0), 4); v; });  // @1096_47d290
  X0[1] = 0;  // @1097_47d290
  X0[2] = 0;  // @1098_47d290
  X0[3] = 0;  // @1099_47d290
  goto L47df48;  // @1100_47d290
  L47df02:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806044) + 0), 4); v; });  // @1102_47d290
  X1[1] = 0;  // @1103_47d290
  X1[2] = 0;  // @1104_47d290
  X1[3] = 0;  // @1105_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860540) + 0), 4); v; });  // @1106_47d290
  X0[1] = 0;  // @1107_47d290
  X0[2] = 0;  // @1108_47d290
  X0[3] = 0;  // @1109_47d290
  goto L47df48;  // @1110_47d290
  L47df14:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860544) + 0), 4); v; });  // @1112_47d290
  X1[1] = 0;  // @1113_47d290
  X1[2] = 0;  // @1114_47d290
  X1[3] = 0;  // @1115_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; });  // @1116_47d290
  X0[1] = 0;  // @1117_47d290
  X0[2] = 0;  // @1118_47d290
  X0[3] = 0;  // @1119_47d290
  goto L47df48;  // @1120_47d290
  L47df26:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; });  // @1122_47d290
  X1[1] = 0;  // @1123_47d290
  X1[2] = 0;  // @1124_47d290
  X1[3] = 0;  // @1125_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860544) + 0), 4); v; });  // @1126_47d290
  X0[1] = 0;  // @1127_47d290
  X0[2] = 0;  // @1128_47d290
  X0[3] = 0;  // @1129_47d290
  goto L47df48;  // @1130_47d290
  L47df38:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860552) + 0), 4); v; });  // @1132_47d290
  X1[1] = 0;  // @1133_47d290
  X1[2] = 0;  // @1134_47d290
  X1[3] = 0;  // @1135_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860556) + 0), 4); v; });  // @1136_47d290
  X0[1] = 0;  // @1137_47d290
  X0[2] = 0;  // @1138_47d290
  X0[3] = 0;  // @1139_47d290
  L47df48:;
  FA = U2F(X4[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @1141_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47dfd6;  // @1142_47d290
  PV[41] = (u32)(edi);  // @1143_47d290
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1742), sizeof v); (u32)v; });  // @1144_47d290
  ecx = (u32)(7338432);  // @1145_47d290
  eax = ext_47aad0_thiscall3(ecx, PV[42], PV[41]);  // @1146_47d290
  ecx = edx = 0;  // @1147_47d290
  ecx = edi;  // @1148_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1742), &v, sizeof v); }  // @1149_47d290
  eax = ext_477740_thiscall3(ecx, (u32)(8), (u32)(0));  // @1150_47d290
  ecx = edx = 0;  // @1151_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 88) + 0), 4); v; });  // @1152_47d290
  X0[1] = 0;  // @1153_47d290
  X0[2] = 0;  // @1154_47d290
  X0[3] = 0;  // @1155_47d290
  ecx = edi;  // @1156_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1157_47d290
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @1158_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1806), &v, sizeof v); }  // @1159_47d290
  __builtin_memcpy((void *)((u32)(edi + 1802) + 0), &X0[0], 4);  // @1160_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1766) + 0), 4); v; });  // @1161_47d290
  X0[1] = 0;  // @1162_47d290
  X0[2] = 0;  // @1163_47d290
  X0[3] = 0;  // @1164_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @1165_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1770) + 0), 4); v; });  // @1166_47d290
  X0[1] = 0;  // @1167_47d290
  X0[2] = 0;  // @1168_47d290
  X0[3] = 0;  // @1169_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X0[0], 4);  // @1170_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1774) + 0), 4); v; });  // @1171_47d290
  X0[1] = 0;  // @1172_47d290
  X0[2] = 0;  // @1173_47d290
  X0[3] = 0;  // @1174_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 44) + 0), &X0[0], 4);  // @1175_47d290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1528)))(ecx);  // @1176_47d290
  ecx = edx = 0;  // @1177_47d290
  goto L47e0df;  // @1178_47d290
  L47dfd6:;
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @1180_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47e00f;  // @1181_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1754) + 0), 4); v; });  // @1182_47d290
  X0[1] = 0;  // @1183_47d290
  X0[2] = 0;  // @1184_47d290
  X0[3] = 0;  // @1185_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @1186_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1758) + 0), 4); v; });  // @1187_47d290
  X0[1] = 0;  // @1188_47d290
  X0[2] = 0;  // @1189_47d290
  X0[3] = 0;  // @1190_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X0[0], 4);  // @1191_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1762) + 0), 4); v; });  // @1192_47d290
  X0[1] = 0;  // @1193_47d290
  X0[2] = 0;  // @1194_47d290
  X0[3] = 0;  // @1195_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 44) + 0), &X0[0], 4);  // @1196_47d290
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 19), &v, sizeof v); }  // @1197_47d290
  goto L47e0df;  // @1198_47d290
  L47e00f:;
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @1200_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47e048;  // @1201_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1766) + 0), 4); v; });  // @1202_47d290
  X0[1] = 0;  // @1203_47d290
  X0[2] = 0;  // @1204_47d290
  X0[3] = 0;  // @1205_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @1206_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1770) + 0), 4); v; });  // @1207_47d290
  X0[1] = 0;  // @1208_47d290
  X0[2] = 0;  // @1209_47d290
  X0[3] = 0;  // @1210_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X0[0], 4);  // @1211_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1774) + 0), 4); v; });  // @1212_47d290
  X0[1] = 0;  // @1213_47d290
  X0[2] = 0;  // @1214_47d290
  X0[3] = 0;  // @1215_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 44) + 0), &X0[0], 4);  // @1216_47d290
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 19), &v, sizeof v); }  // @1217_47d290
  goto L47e0df;  // @1218_47d290
  L47e048:;
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @1220_47d290
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 19), &v, sizeof v); }  // @1221_47d290
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @1222_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1754) + 0), 4); v; });  // @1223_47d290
  X1[1] = 0;  // @1224_47d290
  X1[2] = 0;  // @1225_47d290
  X1[3] = 0;  // @1226_47d290
  X2[0] = F2U(U2F(X2[0]) / U2F(X0[0]));  // @1227_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1766) + 0), 4); v; });  // @1228_47d290
  X0[1] = 0;  // @1229_47d290
  X0[2] = 0;  // @1230_47d290
  X0[3] = 0;  // @1231_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @1232_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @1233_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @1234_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1758) + 0), 4); v; });  // @1235_47d290
  X1[1] = 0;  // @1236_47d290
  X1[2] = 0;  // @1237_47d290
  X1[3] = 0;  // @1238_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @1239_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1770) + 0), 4); v; });  // @1240_47d290
  X0[1] = 0;  // @1241_47d290
  X0[2] = 0;  // @1242_47d290
  X0[3] = 0;  // @1243_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @1244_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @1245_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @1246_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1762) + 0), 4); v; });  // @1247_47d290
  X1[1] = 0;  // @1248_47d290
  X1[2] = 0;  // @1249_47d290
  X1[3] = 0;  // @1250_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X0[0], 4);  // @1251_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1774) + 0), 4); v; });  // @1252_47d290
  X0[1] = 0;  // @1253_47d290
  X0[2] = 0;  // @1254_47d290
  X0[3] = 0;  // @1255_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @1256_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @1257_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @1258_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 44) + 0), &X0[0], 4);  // @1259_47d290
  goto L47e0df;  // @1260_47d290
  L47e0c1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 84) + 0), 4); v; });  // @1262_47d290
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 84) + 4), 4); v; });  // @1263_47d290
  X0[2] = 0;  // @1264_47d290
  X0[3] = 0;  // @1265_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 80), &v, sizeof v); }  // @1266_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 92), sizeof v); (u32)v; });  // @1267_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 0), &X1[0], 4);  // @1268_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 4), &X1[1], 4);  // @1269_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @1270_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 4), &X0[1], 4);  // @1271_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 44), &v, sizeof v); }  // @1272_47d290
  L47e0df:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 8) + 0), 4); v; });  // @1274_47d290
  X1[1] = 0;  // @1275_47d290
  X1[2] = 0;  // @1276_47d290
  X1[3] = 0;  // @1277_47d290
  L47e0e5:;
  PV[43] = (u32)(ecx);  // @1279_47d290
  ecx = edi;  // @1280_47d290
  PV[44] = X1[0];  // @1281_47d290
  eax = ext_47c690_thiscall2(ecx, PV[44]);  // @1282_47d290
  ecx = edx = 0;  // @1283_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1806) + 0), 4); v; });  // @1284_47d290
  X0[1] = 0;  // @1285_47d290
  X0[2] = 0;  // @1286_47d290
  X0[3] = 0;  // @1287_47d290
  X1[0] = 0;  // @1288_47d290
  X1[1] = 0;  // @1289_47d290
  X1[2] = 0;  // @1290_47d290
  X1[3] = 0;  // @1291_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 24) + 0), 4); v; })));  // @1292_47d290
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836848) + 0), 4); v; });  // @1293_47d290
  X3[1] = 0;  // @1294_47d290
  X3[2] = 0;  // @1295_47d290
  X3[3] = 0;  // @1296_47d290
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @1297_47d290
  __builtin_memcpy((void *)((u32)(edi + 1806) + 0), &X0[0], 4);  // @1298_47d290
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L47e12e;  // @1299_47d290
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1795), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1300_47d290
  if (FL[0] != FL[1]) goto L47e12e;  // @1301_47d290
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1797), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1302_47d290
  if (FL[0] == FL[1]) goto L47e1fe;  // @1303_47d290
  L47e12e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @1305_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1802), sizeof v); (u32)v; });  // @1306_47d290
  { u32 v = (u32)((u32)(1103626240)); __builtin_memcpy((void *)(u32)(edi + 1806), &v, sizeof v); }  // @1307_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1798), &v, sizeof v); }  // @1308_47d290
  FL[2] = (ecx & ecx);  // @1309_47d290
  if (FL[2] == 0) goto L47e280;  // @1310_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @1311_47d290
  X0[1] = 0;  // @1312_47d290
  X0[2] = 0;  // @1313_47d290
  X0[3] = 0;  // @1314_47d290
  eax = (u32)((EBP - 184) + 96);  // @1315_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 8) + 0), 4); v; })));  // @1316_47d290
  PV[45] = (u32)(ecx);  // @1317_47d290
  PV[46] = X0[0];  // @1318_47d290
  PV[47] = (u32)(eax);  // @1319_47d290
  eax = ext_478ea0_thiscall3(ecx, PV[47], PV[46]);  // @1320_47d290
  ecx = edx = 0;  // @1321_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 104), sizeof v); (u32)v; });  // @1322_47d290
  ecx = (u32)((EBP - 184) + 60);  // @1323_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 96) + 0), 4); v; });  // @1324_47d290
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 96) + 4), 4); v; });  // @1325_47d290
  X0[2] = 0;  // @1326_47d290
  X0[3] = 0;  // @1327_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 188) + 72), &v, sizeof v); }  // @1328_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1329_47d290
  PV[48] = (u32)(ecx);  // @1330_47d290
  ecx = edi;  // @1331_47d290
  __builtin_memcpy((void *)((u32)((EBP - 196) + 72) + 0), &X0[0], 4);  // @1332_47d290
  __builtin_memcpy((void *)((u32)((EBP - 196) + 72) + 4), &X0[1], 4);  // @1333_47d290
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1568)))(ecx, PV[48], (u32)(0), (u32)(0));  // @1334_47d290
  ecx = edx = 0;  // @1335_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 64) + 0), 4); v; });  // @1336_47d290
  X0[1] = 0;  // @1337_47d290
  X0[2] = 0;  // @1338_47d290
  X0[3] = 0;  // @1339_47d290
  __builtin_memcpy((void *)((u32)(edi + 1802) + 0), &X0[0], 4);  // @1340_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338568) + 0), 4); v; });  // @1341_47d290
  X0[1] = 0;  // @1342_47d290
  X0[2] = 0;  // @1343_47d290
  X0[3] = 0;  // @1344_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @1345_47d290
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1346_47d290
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1347_47d290
  if (__builtin_parity(FL[2] & 0xff)) goto L47e1f6;  // @1348_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @1349_47d290
  edx = (u32)((EBP - 184) + 60);  // @1350_47d290
  PV[49] = (u32)(edx);  // @1351_47d290
  edx = (u32)((EBP - 192) + 104);  // @1352_47d290
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1353_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1354_47d290
  PV[50] = (u32)(edx);  // @1355_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1356_47d290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @1357_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1358_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 536), sizeof v); (u32)v; });  // @1359_47d290
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[50], PV[49], (u32)(16711680));  // @1360_47d290
  ecx = edx = 0;  // @1361_47d290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @1362_47d290
  PV[51] = (u32)(eax);  // @1363_47d290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, PV[51]);  // @1364_47d290
  ecx = edx = 0;  // @1365_47d290
  L47e1f6:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836848) + 0), 4); v; });  // @1367_47d290
  X3[1] = 0;  // @1368_47d290
  X3[2] = 0;  // @1369_47d290
  X3[3] = 0;  // @1370_47d290
  L47e1fe:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 19), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1372_47d290
  if (FL[0] == FL[1]) goto L47e236;  // @1373_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1798) + 0), 4); v; });  // @1374_47d290
  X2[1] = 0;  // @1375_47d290
  X2[2] = 0;  // @1376_47d290
  X2[3] = 0;  // @1377_47d290
  X0[0] = X3[0];  // @1378_47d290
  X0[1] = X3[1];  // @1379_47d290
  X0[2] = X3[2];  // @1380_47d290
  X0[3] = X3[3];  // @1381_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1802) + 0), 4); v; });  // @1382_47d290
  X1[1] = 0;  // @1383_47d290
  X1[2] = 0;  // @1384_47d290
  X1[3] = 0;  // @1385_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1806) + 0), 4); v; })));  // @1386_47d290
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @1387_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @1388_47d290
  X1[0] = F2U(U2F(X1[0]) / U2F(X3[0]));  // @1389_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @1390_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X1[0], 4);  // @1391_47d290
  L47e236:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1393_47d290
  ecx = edi;  // @1394_47d290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1448)))(ecx, (u32)(12));  // @1395_47d290
  ecx = edx = 0;  // @1396_47d290
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1612), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @1397_47d290
  if (FL[0] != FL[1]) goto L47e2f2;  // @1398_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1802) + 0), 4); v; });  // @1399_47d290
  X0[1] = 0;  // @1400_47d290
  X0[2] = 0;  // @1401_47d290
  X0[3] = 0;  // @1402_47d290
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @1403_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1798) + 0), 4); v; }));  // @1404_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47e291;  // @1405_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1406_47d290
  ecx = edi;  // @1407_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1448), sizeof v); (u32)v; });  // @1408_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(6));  // @1409_47d290
  ecx = edx = 0;  // @1410_47d290
  FL[2] = (eax & eax);  // @1411_47d290
  if (FL[2] == 0) goto L47e291;  // @1412_47d290
  W3I_A = 6; goto L47e2eb;  // @1413_47d290 (w3i: the converging push chains pass 6 / 7 / 12 / 8 to 0x477740)
  L47e280:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1636), sizeof v); (u32)v; });  // @1415_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1802), &v, sizeof v); }  // @1416_47d290
  goto L47e1fe;  // @1417_47d290
  L47e291:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1802) + 0), 4); v; });  // @1419_47d290
  X1[1] = 0;  // @1420_47d290
  X1[2] = 0;  // @1421_47d290
  X1[3] = 0;  // @1422_47d290
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @1423_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1798) + 0), 4); v; });  // @1424_47d290
  X0[1] = 0;  // @1425_47d290
  X0[2] = 0;  // @1426_47d290
  X0[3] = 0;  // @1427_47d290
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1428_47d290
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47e2c6;  // @1429_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1430_47d290
  ecx = edi;  // @1431_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1448), sizeof v); (u32)v; });  // @1432_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(7));  // @1433_47d290 (w3i: lifter passed stale pushes 6, 0; real call has one argument)
  ecx = edx = 0;  // @1434_47d290
  FL[2] = (eax & eax);  // @1435_47d290
  if (FL[2] == 0) goto L47e2c6;  // @1436_47d290
  W3I_A = 7; goto L47e2eb;  // @1437_47d290
  L47e2c6:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1876), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1439_47d290
  if (FL[0] == FL[1]) goto L47e2e7;  // @1440_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1441_47d290
  ecx = edi;  // @1442_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1448), sizeof v); (u32)v; });  // @1443_47d290
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(12));  // @1444_47d290 (w3i: stale pushes removed)
  ecx = edx = 0;  // @1445_47d290
  FL[2] = (eax & eax);  // @1446_47d290
  if (FL[2] == 0) goto L47e2e7;  // @1447_47d290
  W3I_A = 12; goto L47e2eb;  // @1448_47d290
  L47e2e7:;
  W3I_A = 8;
  L47e2eb:;
  ecx = edi;  // @1451_47d290
  eax = ext_477740_thiscall3(ecx, W3I_A, (u32)(0));  // @1452_47d290
  ecx = edx = 0;  // @1453_47d290
  L47e2f2:;
  ecx = edi;  // @1455_47d290
  eax = ext_47c540_thiscall1(ecx);  // @1456_47d290
  ecx = edx = 0;  // @1457_47d290
  ecx = edi;  // @1458_47d290
  eax = ext_47ce80_thiscall1(ecx);  // @1459_47d290
  ecx = edx = 0;  // @1460_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 24) + 0), 4); v; });  // @1461_47d290 (w3i: read happens before the push, depth 0)
  X0[1] = 0;  // @1462_47d290
  X0[2] = 0;  // @1463_47d290
  X0[3] = 0;  // @1464_47d290
  eax = (u32)((EBP - 184) + 36);  // @1465_47d290 (w3i: lea precedes the pushes, depth 0)
  PV[52] = (u32)(ecx);  // @1466_47d290
  PV[53] = X0[0];  // @1467_47d290
  ecx = edi;  // @1468_47d290
  PV[54] = (u32)(eax);  // @1469_47d290
  eax = ext_47cdf0_thiscall3(ecx, PV[54], PV[53]);  // @1470_47d290
  ecx = edx = 0;  // @1471_47d290
  goto L47e512;  // @1472_47d290
  L47e31d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1474_47d290
  ecx = edi;  // @1475_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 596), sizeof v); (u32)v; });  // @1476_47d290
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @1477_47d290 (w3i: slot 0x254 takes no argument; stale pushes removed)
  ecx = edx = 0;  // @1478_47d290
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1479_47d290
  if (FL[2] != 0) goto L47e3fa;  // @1480_47d290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; });  // @1481_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1482_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @1483_47d290
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @1484_47d290
  ecx = edx = 0;  // @1485_47d290
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1486_47d290
  if (FL[2] != 0) goto L47e3fa;  // @1487_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1488_47d290
  ecx = edi;  // @1489_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1416), sizeof v); (u32)v; });  // @1490_47d290
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @1491_47d290
  ecx = edx = 0;  // @1492_47d290
  FL[2] = (eax & eax);  // @1493_47d290
  if (FL[2] == 0) goto L47e3cd;  // @1494_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1495_47d290
  ecx = edi;  // @1496_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @1497_47d290
  X0[1] = 0;  // @1498_47d290
  X0[2] = 0;  // @1499_47d290
  X0[3] = 0;  // @1500_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1501_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 24) + 0), &X0[0], 4);  // @1502_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1464), sizeof v); (u32)v; });  // @1503_47d290
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @1504_47d290
  ecx = edx = 0;  // @1505_47d290
  FL[0] = eax; FL[1] = (u32)(1);  // @1506_47d290
  if (FL[0] == FL[1]) goto L47e37f;  // @1507_47d290
  ecx = edi;  // @1508_47d290
  eax = ext_477740_thiscall3(ecx, (u32)(1), (u32)(0));  // @1509_47d290
  ecx = edx = 0;  // @1510_47d290
  L47e37f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1881) + 0), 4); v; });  // @1512_47d290
  X0[1] = 0;  // @1513_47d290
  X0[2] = 0;  // @1514_47d290
  X0[3] = 0;  // @1515_47d290
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @1516_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 24) + 0), 4); v; });  // @1517_47d290
  X1[1] = 0;  // @1518_47d290
  X1[2] = 0;  // @1519_47d290
  X1[3] = 0;  // @1520_47d290
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1521_47d290
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1522_47d290
  if (!__builtin_parity(FL[2] & 0xff)) goto L47e3a2;  // @1523_47d290
  __builtin_memcpy((void *)((u32)(edi + 1881) + 0), &X1[0], 4);  // @1524_47d290
  L47e3a2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1672) + 0), 4); v; });  // @1526_47d290
  X0[1] = 0;  // @1527_47d290
  X0[2] = 0;  // @1528_47d290
  X0[3] = 0;  // @1529_47d290
  ecx = edi;  // @1530_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @1531_47d290
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1881) + 0), 4); v; })));  // @1532_47d290
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; })));  // @1533_47d290
  __builtin_memcpy((void *)((u32)(edi + 1877) + 0), &X0[0], 4);  // @1534_47d290
  eax = ext_47c540_thiscall1(ecx);  // @1535_47d290
  ecx = edx = 0;  // @1536_47d290
  L47e3cd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 0), 4); v; });  // @1538_47d290
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 4), 4); v; });  // @1539_47d290
  X0[2] = 0;  // @1540_47d290
  X0[3] = 0;  // @1541_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 56), sizeof v); (u32)v; });  // @1542_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 0), &X0[0], 4);  // @1543_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 4), &X0[1], 4);  // @1544_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 84) + 0), 4); v; });  // @1545_47d290
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 84) + 4), 4); v; });  // @1546_47d290
  X0[2] = 0;  // @1547_47d290
  X0[3] = 0;  // @1548_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 80), &v, sizeof v); }  // @1549_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 92), sizeof v); (u32)v; });  // @1550_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @1551_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 4), &X0[1], 4);  // @1552_47d290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 44), &v, sizeof v); }  // @1553_47d290
  goto L47e512;  // @1554_47d290
  L47e3fa:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @1556_47d290
  X0[1] = 0;  // @1557_47d290
  X0[2] = 0;  // @1558_47d290
  X0[3] = 0;  // @1559_47d290
  edx = (u32)((EBP - 184) + 108);  // @1560_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 36) + 0), &X0[0], 4);  // @1561_47d290
  ecx = (u32)((EBP - 184) + 36);  // @1562_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; });  // @1563_47d290
  X0[1] = 0;  // @1564_47d290
  X0[2] = 0;  // @1565_47d290
  X0[3] = 0;  // @1566_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X0[0], 4);  // @1567_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 80) + 0), 4); v; });  // @1568_47d290
  X0[1] = 0;  // @1569_47d290
  X0[2] = 0;  // @1570_47d290
  X0[3] = 0;  // @1571_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 44) + 0), &X0[0], 4);  // @1572_47d290
  eax = ext_4419f0_fastcall2(ecx, edx);  // @1573_47d290
  ecx = edx = 0;  // @1574_47d290
  edx = (u32)((EBP - 184) + 84);  // @1575_47d290
  ecx = (u32)((EBP - 184) + 36);  // @1576_47d290
  eax = ext_441940_fastcall2(ecx, edx);  // @1577_47d290
  ecx = edx = 0;  // @1578_47d290
  edx = (u32)(edi + 36);  // @1579_47d290
  ecx = (u32)((EBP - 184) + 108);  // @1580_47d290
  eax = ext_4de480_fastcall2(ecx, edx);  // @1581_47d290
  ecx = edx = 0;  // @1582_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 108) + 0), 4); v; });  // @1583_47d290
  X0[1] = 0;  // @1584_47d290
  X0[2] = 0;  // @1585_47d290
  X0[3] = 0;  // @1586_47d290
  ecx = (u32)((EBP - 184) + 72);  // @1587_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 72) + 0), &X0[0], 4);  // @1588_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 112) + 0), 4); v; });  // @1589_47d290
  X0[1] = 0;  // @1590_47d290
  X0[2] = 0;  // @1591_47d290
  X0[3] = 0;  // @1592_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 76) + 0), &X0[0], 4);  // @1593_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 116) + 0), 4); v; });  // @1594_47d290
  X0[1] = 0;  // @1595_47d290
  X0[2] = 0;  // @1596_47d290
  X0[3] = 0;  // @1597_47d290
  __builtin_memcpy((void *)((u32)((EBP - 184) + 80) + 0), &X0[0], 4);  // @1598_47d290
  eax = ext_4e09b0_thiscall1(ecx);  // @1599_47d290
    // @1600_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1601_47d290
  ecx = edi;  // @1602_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1416), sizeof v); (u32)v; });  // @1603_47d290
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @1604_47d290
  ecx = edx = 0;  // @1605_47d290
  FL[2] = (eax & eax);  // @1606_47d290
  if (FL[2] == 0) goto L47e512;  // @1607_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; });  // @1608_47d290
  X1[1] = 0;  // @1609_47d290
  X1[2] = 0;  // @1610_47d290
  X1[3] = 0;  // @1611_47d290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @1612_47d290
  X2[1] = 0;  // @1613_47d290
  X2[2] = 0;  // @1614_47d290
  X2[3] = 0;  // @1615_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 80) + 0), 4); v; });  // @1616_47d290
  X0[1] = 0;  // @1617_47d290
  X0[2] = 0;  // @1618_47d290
  X0[3] = 0;  // @1619_47d290
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @1620_47d290
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @1621_47d290
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @1622_47d290
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @1623_47d290
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @1624_47d290
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @1625_47d290
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @1626_47d290
  ecx = edx = 0;  // @1627_47d290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1806) + 0), 4); v; });  // @1628_47d290
  X1[1] = 0;  // @1629_47d290
  X1[2] = 0;  // @1630_47d290
  X1[3] = 0;  // @1631_47d290
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @1632_47d290
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @1633_47d290
  X0[0] = 0;  // @1634_47d290
  X0[1] = 0;  // @1635_47d290
  X0[2] = 0;  // @1636_47d290
  X0[3] = 0;  // @1637_47d290
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1638_47d290
  __builtin_memcpy((void *)((u32)(edi + 1806) + 0), &X1[0], 4);  // @1639_47d290
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L47e4df;  // @1640_47d290
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1795), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1641_47d290
  if (FL[0] != FL[1]) goto L47e4df;  // @1642_47d290
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1797), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1643_47d290
  if (FL[0] == FL[1]) goto L47e512;  // @1644_47d290
  L47e4df:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1646_47d290
  ecx = (u32)((EBP - 184) + 36);  // @1647_47d290
  PV[55] = (u32)(ecx);  // @1648_47d290
  ecx = edi;  // @1649_47d290
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1568)))(ecx, PV[55], (u32)(1), (u32)(1));  // @1650_47d290
  ecx = edx = 0;  // @1651_47d290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 40) + 0), 4); v; });  // @1652_47d290
  X0[1] = 0;  // @1653_47d290
  X0[2] = 0;  // @1654_47d290
  X0[3] = 0;  // @1655_47d290
  __builtin_memcpy((void *)((u32)(edi + 1802) + 0), &X0[0], 4);  // @1656_47d290
  __builtin_memcpy((void *)((u32)(edi + 1798) + 0), &X0[0], 4);  // @1657_47d290
  { u32 v = (u32)((u32)(1103626240)); __builtin_memcpy((void *)(u32)(edi + 1806), &v, sizeof v); }  // @1658_47d290
  L47e512:;
  ecx = (u32)((EBP - 184) + 72);  // @1660_47d290
  eax = ext_4e09b0_thiscall1(ecx);  // @1661_47d290
    // @1662_47d290
  edx = (u32)((EBP - 188) + 76);  // @1663_47d290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 188) + 80), &v, sizeof v); }  // @1664_47d290
  ecx = (u32)((EBP - 188) + 148);  // @1665_47d290
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @1666_47d290
  ecx = edx = 0;  // @1667_47d290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1668_47d290
  edx = (u32)((EBP - 184) + 36);  // @1669_47d290
  PV[56] = (u32)(edx);  // @1670_47d290
  edx = (u32)((EBP - 188) + 148);  // @1671_47d290
  ecx = edi;  // @1672_47d290
  PV[57] = (u32)(edx);  // @1673_47d290
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1400)))(ecx, PV[57], PV[56]);  // @1674_47d290
  ecx = edx = 0;  // @1675_47d290
  ext_633654(G(u32, 0x6f5630));  // @1676_47d290
  FS[0] = LDF((u32)((EBP - 184) + 8));  // @1677_47d290
  return FS[0];  // @1678_47d290
}
PCREG(47d290, lifted_47d290);

