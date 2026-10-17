// batch234006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d70_dbl(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d76_dbl(double) __asm__("ext_634d76");
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" long double FASTCALL ext_44e630_fastcall2_ld(u32, u32) __asm__("ext_44e630");
extern "C" long double FASTCALL ext_4e0830_fastcall2_ld(u32, u32) __asm__("ext_4e0830");
extern "C" long double THISCALL ext_44ae20_thiscall2_ld(u32, u32) __asm__("ext_44ae20");
extern "C" long double THISCALL ext_44aed0_thiscall5_ld(u32, u32, u32, u32, u32) __asm__("ext_44aed0");
extern "C" long double THISCALL ext_589c40_thiscall3_ld(u32, u32, u32) __asm__("ext_589c40");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_460af0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_460af0");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 STDCALL ext_514890_stdcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_514890");
extern "C" u32 STDCALL ext_5941d0_stdcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5941d0");
extern "C" u32 THISCALL ext_44ad50_thiscall3(u32, u32, u32) __asm__("ext_44ad50");
extern "C" u32 THISCALL ext_44aed0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_44aed0");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_460b60_thiscall3(u32, u32, u32) __asm__("ext_460b60");
extern "C" u32 THISCALL ext_475820_thiscall3(u32, u32, u32) __asm__("ext_475820");
extern "C" u32 THISCALL ext_482480_thiscall1(u32) __asm__("ext_482480");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 FASTCALL ext_4e0130_fastcall4(u32, u32, u32, u32) __asm__("ext_4e0130");   // w3g hand fix: the callee passes the incoming EDX on to 0x44e630 (fastcall, not thiscall)
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e0d80_thiscall2(u32, u32) __asm__("ext_4e0d80");
extern "C" u32 THISCALL ext_4f2f60_thiscall2(u32, u32) __asm__("ext_4f2f60");
extern "C" u32 THISCALL ext_51d6f0_thiscall1(u32) __asm__("ext_51d6f0");
extern "C" u32 THISCALL ext_589c20_thiscall2(u32, u32) __asm__("ext_589c20");
extern "C" u32 THISCALL ext_592350_thiscall2(u32, u32) __asm__("ext_592350");
extern "C" u32 THISCALL ext_592580_thiscall1(u32) __asm__("ext_592580");
extern "C" u32 THISCALL ext_592850_thiscall1(u32) __asm__("ext_592850");
extern "C" u32 THISCALL ext_595100_thiscall1(u32) __asm__("ext_595100");
extern "C" u32 THISCALL ext_596d00_thiscall2(u32, u32) __asm__("ext_596d00");
extern "C" u32 THISCALL ext_596d30_thiscall2(u32, u32) __asm__("ext_596d30");
extern "C" u32 THISCALL ext_598eb0_thiscall2(u32, u32) __asm__("ext_598eb0");
extern "C" u32 THISCALL ext_5cf690_thiscall2(u32, u32) __asm__("ext_5cf690");
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

extern "C" u32 THISCALL lifted_51d120(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @1_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @2_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @3_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1021), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 534) + 0), 4); v; });  // @5_51d120
  X0[1] = 0;  // @6_51d120
  X0[2] = 0;  // @7_51d120
  X0[3] = 0;  // @8_51d120
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @9_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 538) + 0), 4); v; });  // @10_51d120
  X0[1] = 0;  // @11_51d120
  X0[2] = 0;  // @12_51d120
  X0[3] = 0;  // @13_51d120
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @14_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 542) + 0), 4); v; });  // @15_51d120
  X0[1] = 0;  // @16_51d120
  X0[2] = 0;  // @17_51d120
  X0[3] = 0;  // @18_51d120
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @19_51d120
  if (FL[0] == FL[1]) goto L51d1bd;  // @20_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1117) + 0), 4); v; });  // @21_51d120
  X0[1] = 0;  // @22_51d120
  X0[2] = 0;  // @23_51d120
  X0[3] = 0;  // @24_51d120
  ecx = (u32)(EBP - 16);  // @25_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_51d120
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @27_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1121) + 0), 4); v; });  // @28_51d120
  X0[1] = 0;  // @29_51d120
  X0[2] = 0;  // @30_51d120
  X0[3] = 0;  // @31_51d120
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @32_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1125) + 0), 4); v; });  // @33_51d120
  X0[1] = 0;  // @34_51d120
  X0[2] = 0;  // @35_51d120
  X0[3] = 0;  // @36_51d120
  PV[0] = (u32)(ecx);  // @37_51d120
  ecx = edi;  // @38_51d120
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @39_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[0]);  // @40_51d120
  ecx = edx = 0;  // @41_51d120
  eax = (u32)(EBP - 16);  // @42_51d120
  PV[1] = (u32)(eax);  // @43_51d120
  edx = (u32)(EBP - 40);  // @44_51d120
  ecx = (u32)(EBP - 28);  // @45_51d120
  eax = ext_43e920_fastcall3(ecx, edx, PV[1]);  // @46_51d120
  ecx = edx = 0;  // @47_51d120
  L51d1bd:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1029), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @49_51d120
  if (FL[0] == FL[1]) goto L51d20d;  // @50_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_51d120
  ecx = (u32)(EBP - 28);  // @52_51d120
  PV[2] = (u32)(ecx);  // @53_51d120
  ecx = edi;  // @54_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[2]);  // @55_51d120
  ecx = edx = 0;  // @56_51d120
  edx = (u32)(EBP - 28);  // @57_51d120
  ecx = (u32)(EBP - 76);  // @58_51d120
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @59_51d120
  ecx = edx = 0;  // @60_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @61_51d120
  ecx = edi;  // @62_51d120
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @63_51d120
  eax = (eax & 0xff);  // @64_51d120
  PV[3] = (u32)(eax);  // @65_51d120
  eax = (u32)(edi + 1117);  // @66_51d120
  PV[4] = (u32)(eax);  // @67_51d120
  eax = (u32)(EBP - 76);  // @68_51d120
  PV[5] = (u32)(eax);  // @69_51d120
  eax = (u32)(EBP - 40);  // @70_51d120
  PV[6] = (u32)(eax);  // @71_51d120
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1029), sizeof v); (u32)v; });  // @72_51d120
  eax = ext_514890_stdcall6(PV[7], PV[6], PV[5], PV[4], PV[3], (u32)(1));  // @73_51d120
  ecx = edx = 0;  // @74_51d120
  L51d20d:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1033), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @76_51d120
  if (FL[0] != FL[1]) goto L51d21f;  // @77_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1037), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @78_51d120
  if (FL[0] == FL[1]) goto L51d226;  // @79_51d120
  L51d21f:;
  ecx = edi;  // @81_51d120
  eax = ext_51d6f0_thiscall1(ecx);  // @82_51d120
  ecx = edx = 0;  // @83_51d120
  L51d226:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @85_51d120
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; });  // @86_51d120
  X1[1] = 0;  // @87_51d120
  X1[2] = 0;  // @88_51d120
  X1[3] = 0;  // @89_51d120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_51d120
  if (FL[0] == FL[1]) goto L51d6d2;  // @91_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1137) + 0), 4); v; });  // @92_51d120
  X0[1] = 0;  // @93_51d120
  X0[2] = 0;  // @94_51d120
  X0[3] = 0;  // @95_51d120
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @96_51d120
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @97_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; }); FL[1] = eax;  // @98_51d120
  if ((s32)FL[0] <= (s32)FL[1]) goto L51d3b0;  // @99_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; });  // @100_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1041), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @101_51d120
  if (FL[0] == FL[1]) goto L51d36d;  // @102_51d120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1021), sizeof v); (u32)v; });  // @103_51d120
  FL[2] = (edx & edx);  // @104_51d120
  if (FL[2] == 0) goto L51d31a;  // @105_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @106_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @107_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @108_51d120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @109_51d120
  PV[8] = (u32)(edx);  // @110_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @111_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[8]);  // @112_51d120
  ecx = edx = 0;  // @113_51d120
  ecx = (u32)(EBP - 16);  // @114_51d120
  PV[9] = (u32)(ecx);  // @115_51d120
  ecx = eax;  // @116_51d120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @117_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[9]);  // @118_51d120
  ecx = edx = 0;  // @119_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @120_51d120
  ecx = (u32)(EBP - 16);  // @121_51d120
  PV[10] = (u32)(ecx);  // @122_51d120
  ecx = edi;  // @123_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[10]);  // @124_51d120
  ecx = edx = 0;  // @125_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; });  // @126_51d120
  ecx = (u32)(EBP - 16);  // @127_51d120
  PV[11] = (u32)(ecx);  // @128_51d120
  ecx = edi;  // @129_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1041), sizeof v); (u32)v; });  // @130_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @131_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 36) + 0), 4); v; });  // @132_51d120
  X0[1] = 0;  // @133_51d120
  X0[2] = 0;  // @134_51d120
  X0[3] = 0;  // @135_51d120
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @136_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @137_51d120
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @138_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[11]);  // @139_51d120
  ecx = edx = 0;  // @140_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @141_51d120
  X0[1] = 0;  // @142_51d120
  X0[2] = 0;  // @143_51d120
  X0[3] = 0;  // @144_51d120
  eax = (u32)(EBP - 16);  // @145_51d120
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818444) + 0), 4); v; })));  // @146_51d120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @147_51d120
  ecx = edi;  // @148_51d120
  PV[12] = (u32)(eax);  // @149_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; });  // @150_51d120
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @151_51d120
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1041), sizeof v); (u32)v; });  // @152_51d120
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 900)))(ecx, PV[13], (u32)(1), PV[12]);  // @153_51d120
  ecx = edx = 0;  // @154_51d120
  goto L51d365;  // @155_51d120
  L51d31a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @157_51d120
  ecx = (u32)(EBP - 28);  // @158_51d120
  PV[14] = (u32)(ecx);  // @159_51d120
  ecx = edi;  // @160_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[14]);  // @161_51d120
  ecx = edx = 0;  // @162_51d120
  edx = (u32)(EBP - 28);  // @163_51d120
  ecx = (u32)(EBP - 76);  // @164_51d120
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @165_51d120
  ecx = edx = 0;  // @166_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @167_51d120
  ecx = edi;  // @168_51d120
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @169_51d120
  eax = (eax & 0xff);  // @170_51d120
  PV[15] = (u32)(eax);  // @171_51d120
  eax = (u32)(EBP - 28);  // @172_51d120
  PV[16] = (u32)(eax);  // @173_51d120
  eax = (u32)(EBP - 76);  // @174_51d120
  PV[17] = (u32)(eax);  // @175_51d120
  eax = (u32)(EBP - 16);  // @176_51d120
  PV[18] = (u32)(eax);  // @177_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; });  // @178_51d120
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1041), sizeof v); (u32)v; });  // @179_51d120
  eax = ext_514890_stdcall6(PV[19], PV[18], PV[17], PV[16], PV[15], (u32)(0));  // @180_51d120
  ecx = edx = 0;  // @181_51d120
  L51d365:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; });  // @183_51d120
  X1[1] = 0;  // @184_51d120
  X1[2] = 0;  // @185_51d120
  X1[3] = 0;  // @186_51d120
  L51d36d:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 1109), &v, sizeof v); }  // @188_51d120
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; });  // @189_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; }); FL[1] = (u32)(5);  // @190_51d120
  if ((s32)FL[0] < (s32)FL[1]) goto L51d386;  // @191_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1109), &v, sizeof v); }  // @192_51d120
  L51d386:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @195_51d120
  eax = (eax + (u32)(184));  // @196_51d120
  FL[3] = eax;  // @197_51d120
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @198_51d120
  X0[0] = F2U((float)(s32)X0[0]);  // @199_51d120
  X0[1] = F2U((float)(s32)X0[1]);  // @200_51d120
  X0[2] = F2U((float)(s32)X0[2]);  // @201_51d120
  X0[3] = F2U((float)(s32)X0[3]);  // @202_51d120
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @203_51d120
  __builtin_memcpy((void *)((u32)(edi + 1137) + 0), &X0[0], 4);  // @204_51d120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @205_51d120
  L51d3b0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @207_51d120
  if (FL[0] == FL[1]) goto L51d6d2;  // @208_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1133) + 0), 4); v; });  // @209_51d120
  X0[1] = 0;  // @210_51d120
  X0[2] = 0;  // @211_51d120
  X0[3] = 0;  // @212_51d120
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @213_51d120
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @214_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; }); FL[1] = eax;  // @215_51d120
  if ((s32)FL[0] <= (s32)FL[1]) goto L51d550;  // @216_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1113), sizeof v); (u32)v; });  // @217_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1061), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @218_51d120
  if (FL[0] == FL[1]) goto L51d4e1;  // @219_51d120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1021), sizeof v); (u32)v; });  // @220_51d120
  FL[2] = (edx & edx);  // @221_51d120
  if (FL[2] == 0) goto L51d496;  // @222_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @223_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @224_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @225_51d120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @226_51d120
  PV[20] = (u32)(edx);  // @227_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @228_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[20]);  // @229_51d120
  ecx = edx = 0;  // @230_51d120
  ecx = (u32)(EBP - 16);  // @231_51d120
  PV[21] = (u32)(ecx);  // @232_51d120
  ecx = eax;  // @233_51d120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @234_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[21]);  // @235_51d120
  ecx = edx = 0;  // @236_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @237_51d120
  ecx = (u32)(EBP - 16);  // @238_51d120
  PV[22] = (u32)(ecx);  // @239_51d120
  ecx = edi;  // @240_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[22]);  // @241_51d120
  ecx = edx = 0;  // @242_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1113), sizeof v); (u32)v; });  // @243_51d120
  ecx = (u32)(EBP - 16);  // @244_51d120
  PV[23] = (u32)(ecx);  // @245_51d120
  ecx = edi;  // @246_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1061), sizeof v); (u32)v; });  // @247_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @248_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 36) + 0), 4); v; });  // @249_51d120
  X0[1] = 0;  // @250_51d120
  X0[2] = 0;  // @251_51d120
  X0[3] = 0;  // @252_51d120
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @253_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @254_51d120
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @255_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[23]);  // @256_51d120
  ecx = edx = 0;  // @257_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @258_51d120
  X0[1] = 0;  // @259_51d120
  X0[2] = 0;  // @260_51d120
  X0[3] = 0;  // @261_51d120
  eax = (u32)(EBP - 16);  // @262_51d120
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818444) + 0), 4); v; })));  // @263_51d120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @264_51d120
  ecx = edi;  // @265_51d120
  PV[24] = (u32)(eax);  // @266_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1113), sizeof v); (u32)v; });  // @267_51d120
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @268_51d120
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1061), sizeof v); (u32)v; });  // @269_51d120
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 900)))(ecx, PV[25], (u32)(1), PV[24]);  // @270_51d120
  ecx = edx = 0;  // @271_51d120
  goto L51d4e1;  // @272_51d120
  L51d496:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @274_51d120
  ecx = (u32)(EBP - 28);  // @275_51d120
  PV[26] = (u32)(ecx);  // @276_51d120
  ecx = edi;  // @277_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[26]);  // @278_51d120
  ecx = edx = 0;  // @279_51d120
  edx = (u32)(EBP - 28);  // @280_51d120
  ecx = (u32)(EBP - 76);  // @281_51d120
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @282_51d120
  ecx = edx = 0;  // @283_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @284_51d120
  ecx = edi;  // @285_51d120
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @286_51d120
  eax = (eax & 0xff);  // @287_51d120
  PV[27] = (u32)(eax);  // @288_51d120
  eax = (u32)(EBP - 28);  // @289_51d120
  PV[28] = (u32)(eax);  // @290_51d120
  eax = (u32)(EBP - 76);  // @291_51d120
  PV[29] = (u32)(eax);  // @292_51d120
  eax = (u32)(EBP - 16);  // @293_51d120
  PV[30] = (u32)(eax);  // @294_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1113), sizeof v); (u32)v; });  // @295_51d120
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1061), sizeof v); (u32)v; });  // @296_51d120
  eax = ext_514890_stdcall6(PV[31], PV[30], PV[29], PV[28], PV[27], (u32)(0));  // @297_51d120
  ecx = edx = 0;  // @298_51d120
  L51d4e1:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1113), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 1113), &v, sizeof v); }  // @300_51d120
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1113), sizeof v); (u32)v; });  // @301_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1113), sizeof v); (u32)v; }); FL[1] = (u32)(5);  // @302_51d120
  if ((s32)FL[0] < (s32)FL[1]) goto L51d4fa;  // @303_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1113), &v, sizeof v); }  // @304_51d120
  L51d4fa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @306_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @307_51d120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; });  // @308_51d120
  esi = (esi + (u32)(184));  // @309_51d120
  FL[3] = esi;  // @310_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @311_51d120
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6944952), (u32)(867));  // @312_51d120
  ecx = edx = 0;  // @313_51d120
  FS[0] = (FS[0] * LDF((u32)(6945228)));  // @314_51d120
  FS[0] = (FS[0] * LDF((u32)(6784556)));  // @315_51d120
  STF((u32)(EBP - 80), FS[0]);  // @316_51d120
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @317_51d120
  esi = (esi - eax);  // @318_51d120
  FL[3] = esi;  // @319_51d120
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @320_51d120
  X0[0] = F2U((float)(s32)X0[0]);  // @321_51d120
  X0[1] = F2U((float)(s32)X0[1]);  // @322_51d120
  X0[2] = F2U((float)(s32)X0[2]);  // @323_51d120
  X0[3] = F2U((float)(s32)X0[3]);  // @324_51d120
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @325_51d120
  __builtin_memcpy((void *)((u32)(edi + 1133) + 0), &X0[0], 4);  // @326_51d120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @327_51d120
  L51d550:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @329_51d120
  if (FL[0] == FL[1]) goto L51d6d2;  // @330_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1081), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @331_51d120
  if (FL[0] == FL[1]) goto L51d6d2;  // @332_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1141) + 0), 4); v; });  // @333_51d120
  X0[1] = 0;  // @334_51d120
  X0[2] = 0;  // @335_51d120
  X0[3] = 0;  // @336_51d120
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @337_51d120
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @338_51d120
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; }); FL[1] = eax;  // @339_51d120
  if ((s32)FL[0] <= (s32)FL[1]) goto L51d6d2;  // @340_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @341_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @342_51d120
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6944952), (u32)(870));  // @343_51d120
  ecx = edx = 0;  // @344_51d120
  FS[0] = (FS[0] * LDF((u32)(6806044)));  // @345_51d120
  STF((u32)(EBP - 80), FS[0]);  // @346_51d120
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @347_51d120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 1081), sizeof v); (u32)v; });  // @348_51d120
  ecx = esi;  // @349_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @350_51d120
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 860)))(ecx);  // @351_51d120
  ecx = edx = 0;  // @352_51d120
  FL[2] = (eax & eax);  // @353_51d120
  if (FL[2] != 0) goto L51d5ca;  // @354_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @355_51d120
  ecx = esi;  // @356_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 864)))(ecx, (u32)(100));  // @357_51d120
  ecx = edx = 0;  // @358_51d120
  L51d5ca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @360_51d120
  ecx = esi;  // @361_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 852), sizeof v); (u32)v; });  // @362_51d120
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @363_51d120
  ecx = edx = 0;  // @364_51d120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @365_51d120
  if (FL[2] != 0) goto L51d5f6;  // @366_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @367_51d120
  ecx = esi;  // @368_51d120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(6), (u32)(0));  // @369_51d120
  ecx = edx = 0;  // @370_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @371_51d120
  ecx = esi;  // @372_51d120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(0), (u32)(0));  // @373_51d120
  ecx = edx = 0;  // @374_51d120
  L51d5f6:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1021), sizeof v); (u32)v; });  // @376_51d120
  FL[2] = (edx & edx);  // @377_51d120
  if (FL[2] == 0) goto L51d66b;  // @378_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @379_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @380_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @381_51d120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @382_51d120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @383_51d120
  PV[32] = (u32)(edx);  // @384_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @385_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[32]);  // @386_51d120
  ecx = edx = 0;  // @387_51d120
  ecx = (u32)(EBP - 16);  // @388_51d120
  PV[33] = (u32)(ecx);  // @389_51d120
  ecx = eax;  // @390_51d120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @391_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[33]);  // @392_51d120
  ecx = edx = 0;  // @393_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @394_51d120
  ecx = (u32)(EBP - 16);  // @395_51d120
  PV[34] = (u32)(ecx);  // @396_51d120
  ecx = edi;  // @397_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[34]);  // @398_51d120
  ecx = edx = 0;  // @399_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @400_51d120
  ecx = (u32)(EBP - 16);  // @401_51d120
  PV[35] = (u32)(ecx);  // @402_51d120
  ecx = edi;  // @403_51d120
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 36) + 0), 4); v; });  // @404_51d120
  X0[1] = 0;  // @405_51d120
  X0[2] = 0;  // @406_51d120
  X0[3] = 0;  // @407_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @408_51d120
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @409_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[35]);  // @410_51d120
  ecx = edx = 0;  // @411_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @412_51d120
  ecx = (u32)(EBP - 16);  // @413_51d120
  PV[36] = (u32)(ecx);  // @414_51d120
  ecx = esi;  // @415_51d120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 812)))(ecx, PV[36]);  // @416_51d120
  ecx = edx = 0;  // @417_51d120
  L51d66b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @419_51d120
  ecx = esi;  // @420_51d120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(3), (u32)(0));  // @421_51d120
  ecx = edx = 0;  // @422_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @423_51d120
  ecx = esi;  // @424_51d120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(0), (u32)(0));  // @425_51d120
  ecx = edx = 0;  // @426_51d120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @427_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @428_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @429_51d120
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6944952), (u32)(893));  // @430_51d120
  ecx = edx = 0;  // @431_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @432_51d120
  FS[0] = (FS[0] + FS[0]);  // @433_51d120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @434_51d120
  FS[0] = (FS[0] * LDF((u32)(6784544)));  // @435_51d120
  STF((u32)(EBP - 80), FS[0]);  // @436_51d120
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @437_51d120
  eax = (eax + ecx);  // @438_51d120
  FL[3] = eax;  // @439_51d120
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @440_51d120
  X0[0] = F2U((float)(s32)X0[0]);  // @441_51d120
  X0[1] = F2U((float)(s32)X0[1]);  // @442_51d120
  X0[2] = F2U((float)(s32)X0[2]);  // @443_51d120
  X0[3] = F2U((float)(s32)X0[3]);  // @444_51d120
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @445_51d120
  __builtin_memcpy((void *)((u32)(edi + 1141) + 0), &X0[0], 4);  // @446_51d120
  L51d6d2:;
  ext_633654(G(u32, 0x6f5630));  // @448_51d120
  return eax;  // @449_51d120
}
PCREG(51d120, lifted_51d120);

extern "C" u32 THISCALL lifted_4895e0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4895e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_4895e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4895e0
  edi = ecx;  // @3_4895e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 112) + 12), &v, sizeof v); }  // @4_4895e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 112) + 32), &v, sizeof v); }  // @5_4895e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 112) + 16), &v, sizeof v); }  // @6_4895e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 112) + 24), &v, sizeof v); }  // @7_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @8_4895e0
  FL[2] = (ecx & ecx);  // @9_4895e0
  if (FL[2] == 0) goto L489ce2;  // @10_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @11_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1047), sizeof v); (u32)v; });  // @12_4895e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 112) + 20), &v, sizeof v); }  // @13_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @14_4895e0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @15_4895e0
  X3[1] = 0;  // @16_4895e0
  X3[2] = 0;  // @17_4895e0
  X3[3] = 0;  // @18_4895e0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @19_4895e0
  X2[1] = 0;  // @20_4895e0
  X2[2] = 0;  // @21_4895e0
  X2[3] = 0;  // @22_4895e0
  X0[0] = X3[0];  // @23_4895e0
  X0[1] = X3[1];  // @24_4895e0
  X0[2] = X3[2];  // @25_4895e0
  X0[3] = X3[3];  // @26_4895e0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @27_4895e0
  X4[1] = 0;  // @28_4895e0
  X4[2] = 0;  // @29_4895e0
  X4[3] = 0;  // @30_4895e0
  X1[0] = X2[0];  // @31_4895e0
  X1[1] = X2[1];  // @32_4895e0
  X1[2] = X2[2];  // @33_4895e0
  X1[3] = X2[3];  // @34_4895e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @35_4895e0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @36_4895e0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @37_4895e0
  X0[0] = X4[0];  // @38_4895e0
  X0[1] = X4[1];  // @39_4895e0
  X0[2] = X4[2];  // @40_4895e0
  X0[3] = X4[3];  // @41_4895e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @42_4895e0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @43_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; });  // @44_4895e0
  X0[1] = 0;  // @45_4895e0
  X0[2] = 0;  // @46_4895e0
  X0[3] = 0;  // @47_4895e0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @48_4895e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L48968c;  // @49_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 877) + 0), 4); v; });  // @50_4895e0
  X0[1] = 0;  // @51_4895e0
  X0[2] = 0;  // @52_4895e0
  X0[3] = 0;  // @53_4895e0
  eax = (u32)((EBP - 112) + 36);  // @54_4895e0
  PV[0] = (u32)(ecx);  // @55_4895e0
  PV[1] = X0[0];  // @56_4895e0
  ecx = (ecx + (u32)(28));  // @57_4895e0
  FL[3] = ecx;  // @58_4895e0
  PV[2] = (u32)(eax);  // @59_4895e0
  eax = (u32)((EBP - 120) + 80);  // @60_4895e0
  PV[3] = (u32)(eax);  // @61_4895e0
  eax = ext_460af0_fastcall5(ecx, edx, PV[3], PV[2], PV[1]);  // @62_4895e0
  ecx = edx = 0;  // @63_4895e0
  goto L489754;  // @64_4895e0
  L48968c:;
  __builtin_memcpy((void *)((u32)((EBP - 112) + 48) + 0), &X2[0], 4);  // @66_4895e0
  edx = (u32)((EBP - 112) + 48);  // @67_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 52) + 0), &X3[0], 4);  // @68_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 56) + 0), &X4[0], 4);  // @69_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_4895e0
  PV[4] = (u32)(edx);  // @71_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[4]);  // @72_4895e0
  ecx = edx = 0;  // @73_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 877) + 0), 4); v; });  // @74_4895e0
  X0[1] = 0;  // @75_4895e0
  X0[2] = 0;  // @76_4895e0
  X0[3] = 0;  // @77_4895e0
  eax = (u32)((EBP - 112) + 48);  // @78_4895e0
  PV[5] = (u32)(eax);  // @79_4895e0
  PV[6] = (u32)(ecx);  // @80_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @81_4895e0
  eax = (u32)((EBP - 120) + 44);  // @82_4895e0
  PV[7] = X0[0];  // @83_4895e0
  PV[8] = (u32)(eax);  // @84_4895e0
  eax = (u32)((EBP - 124) + 84);  // @85_4895e0
  PV[9] = (u32)(eax);  // @86_4895e0
  FS[0] = ext_44aed0_thiscall5_ld(ecx, PV[9], PV[8], PV[7], PV[5]);  // @87_4895e0
  ecx = edx = 0;  // @88_4895e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 36) + 0), 4); v; });  // @89_4895e0
  X1[1] = 0;  // @90_4895e0
  X1[2] = 0;  // @91_4895e0
  X1[3] = 0;  // @92_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 40) + 0), 4); v; });  // @93_4895e0
  X0[1] = 0;  // @94_4895e0
  X0[2] = 0;  // @95_4895e0
  X0[3] = 0;  // @96_4895e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @97_4895e0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @98_4895e0
  STF((u32)(edi + 877), FS[0]);  // @99_4895e0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @100_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 44) + 0), 4); v; });  // @101_4895e0
  X0[1] = 0;  // @102_4895e0
  X0[2] = 0;  // @103_4895e0
  X0[3] = 0;  // @104_4895e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @105_4895e0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @106_4895e0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @107_4895e0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @108_4895e0
  ecx = edx = 0;  // @109_4895e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; });  // @110_4895e0
  X1[1] = 0;  // @111_4895e0
  X1[2] = 0;  // @112_4895e0
  X1[3] = 0;  // @113_4895e0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @114_4895e0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @115_4895e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L489754;  // @116_4895e0
  eax = (u32)((EBP - 112) + 48);  // @117_4895e0
  PV[10] = (u32)(eax);  // @118_4895e0
  PV[11] = (u32)(ecx);  // @119_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @120_4895e0
  eax = (u32)((EBP - 120) + 44);  // @121_4895e0
  PV[12] = (u32)(eax);  // @122_4895e0
  eax = (u32)((EBP - 124) + 84);  // @123_4895e0
  PV[13] = (u32)(eax);  // @124_4895e0
  eax = ext_44aed0_thiscall5(ecx, PV[13], PV[12], (u32)(1065353216), PV[10]);  // @125_4895e0
  ecx = edx = 0;  // @126_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @127_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 112) + 36), &v, sizeof v); }  // @128_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 112) + 40), &v, sizeof v); }  // @129_4895e0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 112) + 44), &v, sizeof v); }  // @130_4895e0
  L489754:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @132_4895e0
  edx = (u32)((EBP - 112) + 72);  // @133_4895e0
  PV[14] = (u32)(edx);  // @134_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[14]);  // @136_4895e0
  ecx = edx = 0;  // @137_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 24), sizeof v); (u32)v; });  // @138_4895e0
  edx = (u32)((EBP - 112) + 36);  // @139_4895e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 76) + 0), 4); v; });  // @140_4895e0
  X1[1] = 0;  // @141_4895e0
  X1[2] = 0;  // @142_4895e0
  X1[3] = 0;  // @143_4895e0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6870108) + 0), 4); v; })));  // @144_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 72) + 0), 4); v; });  // @145_4895e0
  X0[1] = 0;  // @146_4895e0
  X0[2] = 0;  // @147_4895e0
  X0[3] = 0;  // @148_4895e0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @149_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 80) + 0), 4); v; });  // @150_4895e0
  X0[1] = 0;  // @151_4895e0
  X0[2] = 0;  // @152_4895e0
  X0[3] = 0;  // @153_4895e0
  __builtin_memcpy((void *)((u32)(eax + 8) + 0), &X0[0], 4);  // @154_4895e0
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X1[0], 4);  // @155_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @156_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 76) + 0), &X1[0], 4);  // @157_4895e0
  PV[15] = (u32)(edx);  // @158_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[15]);  // @160_4895e0
  ecx = edx = 0;  // @161_4895e0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 12), sizeof v); (u32)v; });  // @162_4895e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 116) + 28), sizeof v); (u32)v; });  // @163_4895e0
  ecx = (u32)((EBP - 116) + 88);  // @164_4895e0
  eax = ext_43e920_fastcall3(ecx, edx, PV[16]);  // @165_4895e0
  ecx = edx = 0;  // @166_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 84) + 0), 4); v; });  // @167_4895e0
  X0[1] = 0;  // @168_4895e0
  X0[2] = 0;  // @169_4895e0
  X0[3] = 0;  // @170_4895e0
  eax = (u32)((EBP - 112) + 84);  // @171_4895e0
  X2[0] = 0;  // @172_4895e0
  X2[1] = 0;  // @173_4895e0
  X2[2] = 0;  // @174_4895e0
  X2[3] = 0;  // @175_4895e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 112) + 28), &v, sizeof v); }  // @176_4895e0
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @177_4895e0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @178_4895e0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @179_4895e0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4897f5;  // @180_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 88) + 0), 4); v; });  // @181_4895e0
  X0[1] = 0;  // @182_4895e0
  X0[2] = 0;  // @183_4895e0
  X0[3] = 0;  // @184_4895e0
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @185_4895e0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @186_4895e0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @187_4895e0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4897f5;  // @188_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 92) + 0), 4); v; });  // @189_4895e0
  X0[1] = 0;  // @190_4895e0
  X0[2] = 0;  // @191_4895e0
  X0[3] = 0;  // @192_4895e0
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @193_4895e0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @194_4895e0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @195_4895e0
  if (__builtin_parity(FL[2] & 0xff)) goto L489835;  // @196_4895e0
  L4897f5:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 112) + 12), &v, sizeof v); }  // @198_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 28), sizeof v); (u32)v; });  // @199_4895e0
  FS[0] = LDF((u32)(ecx));  // @200_4895e0
  FS[0] = (FS[0] * FS[0]);  // @201_4895e0
  FS[1] = LDF((u32)(ecx + 4));  // @202_4895e0
  FS[1] = (FS[1] * FS[1]);  // @203_4895e0
  FS[0] = (FS[0] + FS[1]);  // @204_4895e0
  FS[1] = LDF((u32)(ecx + 8));  // @205_4895e0
  FS[1] = (FS[1] * FS[1]);  // @206_4895e0
  FS[0] = (FS[0] + FS[1]);  // @207_4895e0
  FSQRT(FS[0]);  // @208_4895e0
  FS[1] = LDF((u32)((EBP - 112) + 12));  // @209_4895e0
  FS[1] = (FS[1] / FS[0]);  // @210_4895e0
  FS[2] = LDF((u32)(ecx));  // @211_4895e0
  FS[2] = (FS[2] * FS[1]);  // @212_4895e0
  STF((u32)(ecx), FS[2]);  // @213_4895e0
  FS[2] = LDF((u32)(ecx + 4));  // @214_4895e0
  FS[2] = (FS[2] * FS[1]);  // @215_4895e0
  STF((u32)(ecx + 4), FS[2]);  // @216_4895e0
  FS[2] = LDF((u32)(ecx + 8));  // @217_4895e0
  FS[1] = (FS[1] * FS[2]);  // @218_4895e0
  STF((u32)(ecx + 8), FS[1]);  // @219_4895e0
  STF((u32)((EBP - 112) + 12), FS[0]);  // @220_4895e0
  L489835:;
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 36) + 0), 4); v; });  // @222_4895e0
  X5[1] = 0;  // @223_4895e0
  X5[2] = 0;  // @224_4895e0
  X5[3] = 0;  // @225_4895e0
  eax = (u32)((EBP - 112) + 36);  // @226_4895e0
  FA = U2F(X5[0]); FB = U2F(X2[0]);  // @227_4895e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 112) + 28), &v, sizeof v); }  // @228_4895e0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @229_4895e0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @230_4895e0
  if (!__builtin_parity(FL[2] & 0xff)) goto L48986a;  // @231_4895e0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 40) + 0), 4); v; });  // @232_4895e0
  X3[1] = 0;  // @233_4895e0
  X3[2] = 0;  // @234_4895e0
  X3[3] = 0;  // @235_4895e0
  FA = U2F(X3[0]); FB = U2F(X2[0]);  // @236_4895e0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @237_4895e0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @238_4895e0
  if (!__builtin_parity(FL[2] & 0xff)) goto L48986a;  // @239_4895e0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 44) + 0), 4); v; });  // @240_4895e0
  X4[1] = 0;  // @241_4895e0
  X4[2] = 0;  // @242_4895e0
  X4[3] = 0;  // @243_4895e0
  FA = U2F(X4[0]); FB = U2F(X2[0]);  // @244_4895e0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @245_4895e0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @246_4895e0
  if (__builtin_parity(FL[2] & 0xff)) goto L4898bc;  // @247_4895e0
  L48986a:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 112) + 12), &v, sizeof v); }  // @249_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 28), sizeof v); (u32)v; });  // @250_4895e0
  FS[0] = LDF((u32)(ecx));  // @251_4895e0
  FS[0] = (FS[0] * FS[0]);  // @252_4895e0
  FS[1] = LDF((u32)(ecx + 4));  // @253_4895e0
  FS[1] = (FS[1] * FS[1]);  // @254_4895e0
  FS[0] = (FS[0] + FS[1]);  // @255_4895e0
  FS[1] = LDF((u32)(ecx + 8));  // @256_4895e0
  FS[1] = (FS[1] * FS[1]);  // @257_4895e0
  FS[0] = (FS[0] + FS[1]);  // @258_4895e0
  FSQRT(FS[0]);  // @259_4895e0
  FS[1] = LDF((u32)((EBP - 112) + 12));  // @260_4895e0
  FS[1] = (FS[1] / FS[0]);  // @261_4895e0
  FS[2] = LDF((u32)(ecx));  // @262_4895e0
  FS[2] = (FS[2] * FS[1]);  // @263_4895e0
  STF((u32)(ecx), FS[2]);  // @264_4895e0
  FS[2] = LDF((u32)(ecx + 4));  // @265_4895e0
  FS[2] = (FS[2] * FS[1]);  // @266_4895e0
  STF((u32)(ecx + 4), FS[2]);  // @267_4895e0
  FS[2] = LDF((u32)(ecx + 8));  // @268_4895e0
  FS[1] = (FS[1] * FS[2]);  // @269_4895e0
  STF((u32)(ecx + 8), FS[1]);  // @270_4895e0
  STF((u32)((EBP - 112) + 12), FS[0]);  // @271_4895e0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 44) + 0), 4); v; });  // @272_4895e0
  X4[1] = 0;  // @273_4895e0
  X4[2] = 0;  // @274_4895e0
  X4[3] = 0;  // @275_4895e0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 40) + 0), 4); v; });  // @276_4895e0
  X3[1] = 0;  // @277_4895e0
  X3[2] = 0;  // @278_4895e0
  X3[3] = 0;  // @279_4895e0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 36) + 0), 4); v; });  // @280_4895e0
  X5[1] = 0;  // @281_4895e0
  X5[2] = 0;  // @282_4895e0
  X5[3] = 0;  // @283_4895e0
  L4898bc:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6870096) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6870096) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @285_4895e0
  { double a_ = (double)U2F(X3[0]), b_ = (double)U2F(X3[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @286_4895e0
  X1[0] = X1[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @287_4895e0
  X1[1] = X1[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @288_4895e0
  X1[2] = X1[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @289_4895e0
  X1[3] = X1[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @290_4895e0
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @291_4895e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L489a6a;  // @292_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 88) + 0), 4); v; });  // @293_4895e0
  X0[1] = 0;  // @294_4895e0
  X0[2] = 0;  // @295_4895e0
  X0[3] = 0;  // @296_4895e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 84) + 0), 4); v; });  // @297_4895e0
  X1[1] = 0;  // @298_4895e0
  X1[2] = 0;  // @299_4895e0
  X1[3] = 0;  // @300_4895e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @301_4895e0
  X1[0] = F2U(U2F(X1[0]) * U2F(X5[0]));  // @302_4895e0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @303_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 92) + 0), 4); v; });  // @304_4895e0
  X0[1] = 0;  // @305_4895e0
  X0[2] = 0;  // @306_4895e0
  X0[3] = 0;  // @307_4895e0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @308_4895e0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @309_4895e0
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @310_4895e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L48990c;  // @311_4895e0
  ecx = (u32)((EBP - 112) + 36);  // @312_4895e0
  eax = ext_4e09b0_thiscall1(ecx);  // @313_4895e0
    // @314_4895e0
  L48990c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @316_4895e0
  edx = (u32)((EBP - 112) + 84);  // @317_4895e0
  PV[17] = (u32)(edx);  // @318_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @319_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[17]);  // @320_4895e0
  ecx = edx = 0;  // @321_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 877) + 0), 4); v; });  // @322_4895e0
  X0[1] = 0;  // @323_4895e0
  X0[2] = 0;  // @324_4895e0
  X0[3] = 0;  // @325_4895e0
  eax = (u32)((EBP - 112) + 84);  // @326_4895e0
  PV[18] = (u32)(eax);  // @327_4895e0
  PV[19] = (u32)(ecx);  // @328_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @329_4895e0
  eax = (u32)((EBP - 120) + 56);  // @330_4895e0
  PV[20] = X0[0];  // @331_4895e0
  PV[21] = (u32)(eax);  // @332_4895e0
  eax = (u32)((EBP - 124) + 84);  // @333_4895e0
  PV[22] = (u32)(eax);  // @334_4895e0
  eax = ext_44aed0_thiscall5(ecx, PV[22], PV[21], PV[20], PV[18]);  // @335_4895e0
  ecx = edx = 0;  // @336_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @337_4895e0
  edx = (u32)((EBP - 112) + 48);  // @338_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @339_4895e0
  PV[23] = (u32)(edx);  // @340_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @341_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[23]);  // @342_4895e0
  ecx = edx = 0;  // @343_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @344_4895e0
  edx = (u32)((EBP - 112) + 72);  // @345_4895e0
  PV[24] = (u32)(edx);  // @346_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @347_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[24]);  // @348_4895e0
  ecx = edx = 0;  // @349_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 76) + 0), 4); v; });  // @350_4895e0
  X0[1] = 0;  // @351_4895e0
  X0[2] = 0;  // @352_4895e0
  X0[3] = 0;  // @353_4895e0
  ecx = (u32)((EBP - 112) + 48);  // @354_4895e0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6870108) + 0), 4); v; })));  // @355_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 76) + 0), &X0[0], 4);  // @356_4895e0
  eax = ext_44c840_thiscall1(ecx);  // @357_4895e0
  ecx = 0;  // @358_4895e0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 20), sizeof v); (u32)v; }) & (u32)(3));  // @359_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @360_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @361_4895e0
  X0[1] = 0;  // @362_4895e0
  X0[2] = 0;  // @363_4895e0
  X0[3] = 0;  // @364_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 60) + 0), &X0[0], 4);  // @365_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @366_4895e0
  X0[1] = 0;  // @367_4895e0
  X0[2] = 0;  // @368_4895e0
  X0[3] = 0;  // @369_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 64) + 0), &X0[0], 4);  // @370_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @371_4895e0
  X0[1] = 0;  // @372_4895e0
  X0[2] = 0;  // @373_4895e0
  X0[3] = 0;  // @374_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 68) + 0), &X0[0], 4);  // @375_4895e0
  if (FL[2] == 0) goto L489a5e;  // @376_4895e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 942), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @377_4895e0
  if (FL[0] != FL[1]) goto L4899dc;  // @378_4895e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 941), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @379_4895e0
  if (FL[0] == FL[1]) goto L489a5e;  // @380_4895e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 958), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @381_4895e0
  if (FL[0] == FL[1]) goto L489a5e;  // @382_4895e0
  L4899dc:;
  ecx = (u32)((EBP - 112) + 36);  // @384_4895e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 942), &v, sizeof v); }  // @385_4895e0
  eax = ext_4e09b0_thiscall1(ecx);  // @386_4895e0
    // @387_4895e0
  PV[25] = (u32)(ecx);  // @388_4895e0
  eax = (u32)((EBP - 116) + 40);  // @389_4895e0
  PV[26] = (u32)(eax);  // @390_4895e0
  edx = (u32)((EBP - 120) + 68);  // @391_4895e0
  ecx = (u32)((EBP - 120) + 56);  // @392_4895e0
  eax = ext_4e0130_fastcall4(ecx, edx, PV[26], (u32)(1043511491));  // @393_4895e0
  ecx = edx = 0;  // @394_4895e0
  edx = (u32)((EBP - 112) + 48);  // @395_4895e0
  ecx = esi;  // @396_4895e0
  eax = ext_44e630_fastcall2(ecx, edx);  // @397_4895e0
  ecx = edx = 0;  // @398_4895e0
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 16), sizeof v); (u32)v; });  // @399_4895e0
  edi = (u32)(esi + 12);  // @400_4895e0
  esi = (esi + (u32)(24));  // @401_4895e0
  FL[3] = esi;  // @402_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @403_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @404_4895e0
  edx = edi;  // @405_4895e0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @406_4895e0
  ecx = esi;  // @407_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @408_4895e0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[27]);  // @409_4895e0
  ecx = edx = 0;  // @410_4895e0
  ecx = esi;  // @411_4895e0
  eax = ext_44c840_thiscall1(ecx);  // @412_4895e0
  ecx = 0;  // @413_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 16), sizeof v); (u32)v; });  // @414_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @415_4895e0
  PV[28] = (u32)(edi);  // @416_4895e0
  edx = esi;  // @417_4895e0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[28]);  // @418_4895e0
  ecx = edx = 0;  // @419_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 16), sizeof v); (u32)v; });  // @420_4895e0
  eax = ext_44c840_thiscall1(ecx);  // @421_4895e0
  ecx = 0;  // @422_4895e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 32), sizeof v); (u32)v; });  // @423_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @424_4895e0
  L489a5e:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 941), &v, sizeof v); }  // @426_4895e0
  goto L489c46;  // @427_4895e0
  L489a6a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 877) + 0), 4); v; });  // @429_4895e0
  X0[1] = 0;  // @430_4895e0
  X0[2] = 0;  // @431_4895e0
  X0[3] = 0;  // @432_4895e0
  PV[29] = (u32)(ecx);  // @433_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @434_4895e0
  PV[30] = X0[0];  // @435_4895e0
  eax = ext_44ad50_thiscall3(ecx, PV[30], (u32)(0));  // @436_4895e0
  ecx = edx = 0;  // @437_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @438_4895e0
  edx = (u32)((EBP - 112) + 48);  // @439_4895e0
  esi = eax;  // @440_4895e0
  PV[31] = (u32)(edx);  // @441_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; });  // @442_4895e0
  X0[1] = 0;  // @443_4895e0
  X0[2] = 0;  // @444_4895e0
  X0[3] = 0;  // @445_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 116) + 52) + 0), &X0[0], 4);  // @446_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 40) + 0), 4); v; });  // @447_4895e0
  X0[1] = 0;  // @448_4895e0
  X0[2] = 0;  // @449_4895e0
  X0[3] = 0;  // @450_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 116) + 56) + 0), &X0[0], 4);  // @451_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 44) + 0), 4); v; });  // @452_4895e0
  X0[1] = 0;  // @453_4895e0
  X0[2] = 0;  // @454_4895e0
  X0[3] = 0;  // @455_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 116) + 60) + 0), &X0[0], 4);  // @456_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @457_4895e0
  X0[1] = 0;  // @458_4895e0
  X0[2] = 0;  // @459_4895e0
  X0[3] = 0;  // @460_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 116) + 64) + 0), &X0[0], 4);  // @461_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @462_4895e0
  X0[1] = 0;  // @463_4895e0
  X0[2] = 0;  // @464_4895e0
  X0[3] = 0;  // @465_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 116) + 68) + 0), &X0[0], 4);  // @466_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @467_4895e0
  X0[1] = 0;  // @468_4895e0
  X0[2] = 0;  // @469_4895e0
  X0[3] = 0;  // @470_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 116) + 72) + 0), &X0[0], 4);  // @471_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @472_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[31]);  // @473_4895e0
  ecx = edx = 0;  // @474_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @475_4895e0
  edx = (u32)((EBP - 112) + 60);  // @476_4895e0
  PV[32] = (u32)(edx);  // @477_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @478_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[32]);  // @479_4895e0
  ecx = edx = 0;  // @480_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @481_4895e0
  PV[33] = (u32)(esi);  // @482_4895e0
  FS[0] = ext_44ae20_thiscall2_ld(ecx, PV[33]);  // @483_4895e0
  ecx = edx = 0;  // @484_4895e0
  STF((u32)((EBP - 112) + 20), FS[0]);  // @485_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 20) + 0), 4); v; });  // @486_4895e0
  X0[1] = 0;  // @487_4895e0
  X0[2] = 0;  // @488_4895e0
  X0[3] = 0;  // @489_4895e0
  eax = (u32)((EBP - 112) + 36);  // @490_4895e0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; })));  // @491_4895e0
  PV[34] = (u32)(ecx);  // @492_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @493_4895e0
  ecx = (ecx + (u32)(28));  // @494_4895e0
  FL[3] = ecx;  // @495_4895e0
  PV[35] = X0[0];  // @496_4895e0
  PV[36] = (u32)(eax);  // @497_4895e0
  eax = ext_460b60_thiscall3(ecx, PV[36], PV[35]);  // @498_4895e0
  ecx = edx = 0;  // @499_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 881), sizeof v); (u32)v; });  // @500_4895e0
  edx = (u32)((EBP - 112) + 36);  // @501_4895e0
  PV[37] = (u32)(edx);  // @502_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @503_4895e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[37]);  // @504_4895e0
  ecx = edx = 0;  // @505_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 52) + 0), 4); v; });  // @506_4895e0
  X0[1] = 0;  // @507_4895e0
  X0[2] = 0;  // @508_4895e0
  X0[3] = 0;  // @509_4895e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 64) + 0), 4); v; });  // @510_4895e0
  X1[1] = 0;  // @511_4895e0
  X1[2] = 0;  // @512_4895e0
  X1[3] = 0;  // @513_4895e0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @514_4895e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L489b80;  // @515_4895e0
  ecx = (u32)((EBP - 112) + 36);  // @516_4895e0
  eax = ext_4e09b0_thiscall1(ecx);  // @517_4895e0
    // @518_4895e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 48) + 0), 4); v; });  // @519_4895e0
  X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 48) + 4), 4); v; });  // @520_4895e0
  X1[2] = 0;  // @521_4895e0
  X1[3] = 0;  // @522_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 60) + 0), 4); v; });  // @523_4895e0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 60) + 4), 4); v; });  // @524_4895e0
  X0[2] = 0;  // @525_4895e0
  X0[3] = 0;  // @526_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 56), sizeof v); (u32)v; });  // @527_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 68), sizeof v); (u32)v; });  // @528_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 60) + 0), &X1[0], 4);  // @529_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 60) + 4), &X1[1], 4);  // @530_4895e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 64) + 0), 4); v; });  // @531_4895e0
  X1[1] = 0;  // @532_4895e0
  X1[2] = 0;  // @533_4895e0
  X1[3] = 0;  // @534_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 48) + 0), &X0[0], 4);  // @535_4895e0
  __builtin_memcpy((void *)((u32)((EBP - 112) + 48) + 4), &X0[1], 4);  // @536_4895e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 112) + 56), &v, sizeof v); }  // @537_4895e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 112) + 68), &v, sizeof v); }  // @538_4895e0
  L489b80:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 60) + 0), 4); v; });  // @540_4895e0
  X0[1] = 0;  // @541_4895e0
  X0[2] = 0;  // @542_4895e0
  X0[3] = 0;  // @543_4895e0
  eax = (u32)((EBP - 112) + 36);  // @544_4895e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 16), sizeof v); (u32)v; });  // @545_4895e0
  edx = esi;  // @546_4895e0
  __builtin_memcpy((void *)((u32)(edi + 889) + 0), &X0[0], 4);  // @547_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 68) + 0), 4); v; });  // @548_4895e0
  X0[1] = 0;  // @549_4895e0
  X0[2] = 0;  // @550_4895e0
  X0[3] = 0;  // @551_4895e0
  __builtin_memcpy((void *)((u32)(edi + 897) + 0), &X0[0], 4);  // @552_4895e0
  X0[0] = X1[0];  // @553_4895e0
  X0[1] = X1[1];  // @554_4895e0
  X0[2] = X1[2];  // @555_4895e0
  X0[3] = X1[3];  // @556_4895e0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6870108) + 0), 4); v; })));  // @557_4895e0
  PV[38] = (u32)(ecx);  // @558_4895e0
  ecx = (u32)((EBP - 116) + 100);  // @559_4895e0
  PV[39] = (u32)(eax);  // @560_4895e0
  __builtin_memcpy((void *)((u32)(edi + 893) + 0), &X0[0], 4);  // @561_4895e0
  eax = ext_4e0130_fastcall4(ecx, edx, PV[39], (u32)(1043511491));  // @562_4895e0
  ecx = edx = 0;  // @563_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 96) + 0), 4); v; });  // @564_4895e0
  X0[1] = 0;  // @565_4895e0
  X0[2] = 0;  // @566_4895e0
  X0[3] = 0;  // @567_4895e0
  ecx = esi;  // @568_4895e0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @569_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 100) + 0), 4); v; });  // @570_4895e0
  X0[1] = 0;  // @571_4895e0
  X0[2] = 0;  // @572_4895e0
  X0[3] = 0;  // @573_4895e0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @574_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 104) + 0), 4); v; });  // @575_4895e0
  X0[1] = 0;  // @576_4895e0
  X0[2] = 0;  // @577_4895e0
  X0[3] = 0;  // @578_4895e0
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @579_4895e0
  eax = ext_44c840_thiscall1(ecx);  // @580_4895e0
  ecx = 0;  // @581_4895e0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 16), sizeof v); (u32)v; });  // @582_4895e0
  edi = (u32)(esi + 12);  // @583_4895e0
  esi = (esi + (u32)(24));  // @584_4895e0
  FL[3] = esi;  // @585_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @586_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @587_4895e0
  edx = edi;  // @588_4895e0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @589_4895e0
  ecx = esi;  // @590_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @591_4895e0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[40]);  // @592_4895e0
  ecx = edx = 0;  // @593_4895e0
  ecx = esi;  // @594_4895e0
  eax = ext_44c840_thiscall1(ecx);  // @595_4895e0
  ecx = 0;  // @596_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 16), sizeof v); (u32)v; });  // @597_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @598_4895e0
  PV[41] = (u32)(edi);  // @599_4895e0
  edx = esi;  // @600_4895e0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[41]);  // @601_4895e0
  ecx = edx = 0;  // @602_4895e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 16), sizeof v); (u32)v; });  // @603_4895e0
  eax = ext_44c840_thiscall1(ecx);  // @604_4895e0
  ecx = 0;  // @605_4895e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 32), sizeof v); (u32)v; });  // @606_4895e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @607_4895e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 941), &v, sizeof v); }  // @608_4895e0
  L489c46:;
  esi = (u32)(edi + 901);  // @610_4895e0
  edx = esi;  // @611_4895e0
  ecx = (u32)((EBP - 112) + 36);  // @612_4895e0
  FS[0] = ext_44e630_fastcall2_ld(ecx, edx);  // @613_4895e0
  ecx = edx = 0;  // @614_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; });  // @615_4895e0
  X0[1] = 0;  // @616_4895e0
  X0[2] = 0;  // @617_4895e0
  X0[3] = 0;  // @618_4895e0
  STF((u32)((EBP - 112) + 20), FS[0]);  // @619_4895e0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 112) + 20) + 0), 4); v; }));  // @620_4895e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L489c80;  // @621_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @622_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @623_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @624_4895e0
  goto L489c93;  // @625_4895e0
  L489c80:;
  PV[42] = (u32)(ecx);  // @627_4895e0
  edx = (u32)((EBP - 116) + 40);  // @628_4895e0
  ecx = esi;  // @629_4895e0
  eax = ext_451890_fastcall3(ecx, edx, (u32)(3221225472));  // @630_4895e0
  ecx = 0;  // @631_4895e0
  L489c93:;
  edx = esi;  // @633_4895e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 112) + 24), sizeof v); (u32)v; });  // @634_4895e0
  ecx = esi;  // @635_4895e0
  eax = ext_441940_fastcall2(ecx, edx);  // @636_4895e0
  ecx = edx = 0;  // @637_4895e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @638_4895e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 1085) + 0), 4); v; });  // @639_4895e0
  X0[1] = 0;  // @640_4895e0
  X0[2] = 0;  // @641_4895e0
  X0[3] = 0;  // @642_4895e0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @643_4895e0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @644_4895e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 877) + 0), 4); v; });  // @645_4895e0
  X1[1] = 0;  // @646_4895e0
  X1[2] = 0;  // @647_4895e0
  X1[3] = 0;  // @648_4895e0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @649_4895e0
  if ((!(!(FA >= FB)))) goto L489cce;  // @650_4895e0
  X0[0] = 0;  // @651_4895e0
  X0[1] = 0;  // @652_4895e0
  X0[2] = 0;  // @653_4895e0
  X0[3] = 0;  // @654_4895e0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @655_4895e0
  if ((!(FA >= FB))) goto L489ce2;  // @656_4895e0
  L489cce:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 877), &v, sizeof v); }  // @658_4895e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 881), &v, sizeof v); }  // @659_4895e0
  L489ce2:;
  ext_633654(G(u32, 0x6f5630));  // @661_4895e0
  return eax;  // @662_4895e0
}
PCREG(4895e0, lifted_4895e0);

extern "C" u32 THISCALL lifted_58df40(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 PSTR = 0;   // w3g hand fix: the string pushed before the shared tail L58e4f4 depends on the path
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_58df40
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @1_58df40
  eax = ext_482480_thiscall1(ecx);  // @2_58df40
  ecx = edx = 0;  // @3_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @7_58df40
  ecx = edx = 0;  // @8_58df40
  ecx = (u32)(EBP - 12);  // @9_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @10_58df40
  PV[0] = (u32)(ecx);  // @11_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_58df40
  ecx = eax;  // @13_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998220), PV[0]);  // @14_58df40
  ecx = edx = 0;  // @15_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @16_58df40
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @17_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[1]);  // @19_58df40
  ecx = edx = 0;  // @20_58df40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @21_58df40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 2093), &v, sizeof v); }  // @22_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_58df40
  PV[2] = (u32)(ebx);  // @24_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_58df40
  esi = ecx;  // @26_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @28_58df40
  ecx = edx = 0;  // @29_58df40
  PV[3] = (u32)(eax);  // @30_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_58df40
  ecx = esi;  // @32_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6881912), (u32)(0), (u32)(6997712), (u32)(385), PV[3]);  // @33_58df40
  ecx = edx = 0;  // @34_58df40
  eax = (eax & 0xffff);  // @35_58df40
  ecx = ebx;  // @36_58df40
  PV[4] = (u32)(eax);  // @37_58df40
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1654), sizeof v); (u32)v; });  // @38_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, PV[5], PV[4]);  // @39_58df40
  ecx = edx = 0;  // @40_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @41_58df40
  ecx = ebx;  // @42_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @43_58df40
  ecx = edx = 0;  // @44_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @45_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @46_58df40
  eax = (eax >> (u32)(10));  // @47_58df40
  FL[3] = eax;  // @48_58df40
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @49_58df40
  FL[2] = ((eax & 0xff) & (u32)(1));  // @50_58df40
  if (FL[2] == 0) goto L58e064;  // @51_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @53_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @55_58df40
  ecx = edx = 0;  // @56_58df40
  ecx = (u32)(EBP - 12);  // @57_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @58_58df40
  PV[6] = (u32)(ecx);  // @59_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_58df40
  ecx = eax;  // @61_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6879068), PV[6]);  // @62_58df40
  ecx = edx = 0;  // @63_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @64_58df40
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @65_58df40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @66_58df40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @67_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @68_58df40
  esi = ecx;  // @69_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @71_58df40
  ecx = edx = 0;  // @72_58df40
  PV[8] = (u32)(eax);  // @73_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_58df40
  ecx = esi;  // @75_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6879092), (u32)(0), (u32)(6997712), (u32)(390), PV[8]);  // @76_58df40
  ecx = edx = 0;  // @77_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @78_58df40
  eax = (eax & 0xffff);  // @79_58df40
  PV[9] = (u32)(eax);  // @80_58df40
  PV[10] = (u32)(edi);  // @81_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ebx + 300)))(ecx, PV[10], PV[9]);  // @82_58df40
  ecx = edx = 0;  // @83_58df40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @84_58df40
  L58e064:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @86_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @87_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @89_58df40
  ecx = edx = 0;  // @90_58df40
  ecx = (u32)(EBP - 1);  // @91_58df40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @92_58df40
  PV[11] = (u32)(ecx);  // @93_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @94_58df40
  ecx = eax;  // @95_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6859220), PV[11]);  // @96_58df40
  ecx = edx = 0;  // @97_58df40
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; })) & 0xff);  // @98_58df40
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 2535), &v, sizeof v); }  // @99_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @100_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @101_58df40
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @102_58df40
  FL[3] = (eax & 0xff);  // @103_58df40
  eax = (eax & 0xff);  // @104_58df40
  PV[12] = (u32)(eax);  // @105_58df40
  eax = ext_589c20_thiscall2(ecx, PV[12]);  // @106_58df40
    // @107_58df40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 2130), &v, sizeof v); }  // @108_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @109_58df40
  eax = (eax - (u32)(2));  // @110_58df40
  FL[3] = eax;  // @111_58df40
  if (FL[3] == 0) goto L58e3f0;  // @112_58df40
  eax = (eax - (u32)(1));  // @113_58df40
  FL[3] = eax;  // @114_58df40
  if (FL[3] == 0) goto L58e2e7;  // @115_58df40
  eax = (eax - (u32)(1));  // @116_58df40
  FL[3] = eax;  // @117_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @118_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @119_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_58df40
  if (FL[3] == 0) goto L58e1eb;  // @121_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @122_58df40
  ecx = edx = 0;  // @123_58df40
  ecx = (u32)(EBP - 12);  // @124_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @125_58df40
  PV[13] = (u32)(ecx);  // @126_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @127_58df40
  ecx = eax;  // @128_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6978836), PV[13]);  // @129_58df40
  ecx = edx = 0;  // @130_58df40
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @131_58df40
  ecx = ebx;  // @132_58df40
  eax = ext_592350_thiscall2(ecx, PV[14]);  // @133_58df40
  ecx = edx = 0;  // @134_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_58df40
  PV[15] = (u32)(eax);  // @136_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @137_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @138_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[15]);  // @139_58df40
  ecx = edx = 0;  // @140_58df40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 3822), &v, sizeof v); }  // @141_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @142_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @143_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @145_58df40
  ecx = edx = 0;  // @146_58df40
  ecx = (u32)(EBP - 12);  // @147_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @148_58df40
  PV[16] = (u32)(ecx);  // @149_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @150_58df40
  ecx = eax;  // @151_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998376), PV[16]);  // @152_58df40
  ecx = edx = 0;  // @153_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @154_58df40
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1654), sizeof v); (u32)v; });  // @155_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @156_58df40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @157_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @158_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6998244), (u32)(0), (u32)(6997712), (u32)(466), PV[17]);  // @160_58df40
  ecx = edx = 0;  // @161_58df40
  eax = (eax & 0xffff);  // @162_58df40
  ecx = ebx;  // @163_58df40
  PV[18] = (u32)(eax);  // @164_58df40
  PV[19] = (u32)(esi);  // @165_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, PV[19], PV[18]);  // @166_58df40
  ecx = edx = 0;  // @167_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @168_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @169_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @171_58df40
  ecx = edx = 0;  // @172_58df40
  ecx = (u32)(EBP - 12);  // @173_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @174_58df40
  PV[20] = (u32)(ecx);  // @175_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @176_58df40
  ecx = eax;  // @177_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998400), PV[20]);  // @178_58df40
  ecx = edx = 0;  // @179_58df40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @180_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @181_58df40
  if (FL[0] == FL[1]) goto L58e513;  // @182_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @183_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @184_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @185_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @186_58df40
  ecx = edx = 0;  // @187_58df40
  ecx = (u32)(EBP - 12);  // @188_58df40
  PV[21] = (u32)(ecx);  // @189_58df40
  PSTR = 6978868; goto L58e4f4;  // @190_58df40
  L58e1eb:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);   // w3g hand fix: stale pending pushes from a jumped-over path were attached  // @192_58df40
  ecx = edx = 0;  // @193_58df40
  ecx = (u32)(EBP - 12);  // @194_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @195_58df40
  PV[22] = (u32)(ecx);  // @196_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @197_58df40
  ecx = eax;  // @198_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6979100), PV[22]);  // @199_58df40
  ecx = edx = 0;  // @200_58df40
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @201_58df40
  ecx = ebx;  // @202_58df40
  eax = ext_592350_thiscall2(ecx, PV[23]);  // @203_58df40
  ecx = edx = 0;  // @204_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @205_58df40
  PV[24] = (u32)(eax);  // @206_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @207_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @208_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[24]);  // @209_58df40
  ecx = edx = 0;  // @210_58df40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 3822), &v, sizeof v); }  // @211_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @212_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @213_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @214_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @215_58df40
  ecx = edx = 0;  // @216_58df40
  ecx = (u32)(EBP - 12);  // @217_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @218_58df40
  PV[25] = (u32)(ecx);  // @219_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @220_58df40
  ecx = eax;  // @221_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998340), PV[25]);  // @222_58df40
  ecx = edx = 0;  // @223_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @224_58df40
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1654), sizeof v); (u32)v; });  // @225_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @226_58df40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @227_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @228_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @229_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6998244), (u32)(0), (u32)(6997712), (u32)(449), PV[26]);  // @230_58df40
  ecx = edx = 0;  // @231_58df40
  eax = (eax & 0xffff);  // @232_58df40
  ecx = ebx;  // @233_58df40
  PV[27] = (u32)(eax);  // @234_58df40
  PV[28] = (u32)(esi);  // @235_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, PV[28], PV[27]);  // @236_58df40
  ecx = edx = 0;  // @237_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @238_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @239_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @240_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @241_58df40
  ecx = edx = 0;  // @242_58df40
  ecx = (u32)(EBP - 12);  // @243_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @244_58df40
  PV[29] = (u32)(ecx);  // @245_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @246_58df40
  ecx = eax;  // @247_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998364), PV[29]);  // @248_58df40
  ecx = edx = 0;  // @249_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @250_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @251_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @252_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @253_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @254_58df40
  ecx = edx = 0;  // @255_58df40
  ecx = (u32)(EBP - 12);  // @256_58df40
  PV[30] = (u32)(ecx);  // @257_58df40
  PSTR = 6979132; goto L58e4f4;  // @258_58df40
  L58e2e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @260_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @261_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @262_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);   // w3g hand fix: stale pending pushes from a jumped-over path were attached  // @263_58df40
  ecx = edx = 0;  // @264_58df40
  ecx = (u32)(EBP - 12);  // @265_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @266_58df40
  PV[31] = (u32)(ecx);  // @267_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @268_58df40
  ecx = eax;  // @269_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6979012), PV[31]);  // @270_58df40
  ecx = edx = 0;  // @271_58df40
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @272_58df40
  ecx = ebx;  // @273_58df40
  eax = ext_592350_thiscall2(ecx, PV[32]);  // @274_58df40
  ecx = edx = 0;  // @275_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @276_58df40
  PV[33] = (u32)(eax);  // @277_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @278_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @279_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[33]);  // @280_58df40
  ecx = edx = 0;  // @281_58df40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 3822), &v, sizeof v); }  // @282_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @283_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @284_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @285_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @286_58df40
  ecx = edx = 0;  // @287_58df40
  ecx = (u32)(EBP - 12);  // @288_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @289_58df40
  PV[34] = (u32)(ecx);  // @290_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @291_58df40
  ecx = eax;  // @292_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998304), PV[34]);  // @293_58df40
  ecx = edx = 0;  // @294_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @295_58df40
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1654), sizeof v); (u32)v; });  // @296_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @297_58df40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @298_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @299_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @300_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6998244), (u32)(0), (u32)(6997712), (u32)(433), PV[35]);  // @301_58df40
  ecx = edx = 0;  // @302_58df40
  eax = (eax & 0xffff);  // @303_58df40
  ecx = ebx;  // @304_58df40
  PV[36] = (u32)(eax);  // @305_58df40
  PV[37] = (u32)(esi);  // @306_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, PV[37], PV[36]);  // @307_58df40
  ecx = edx = 0;  // @308_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @309_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @310_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @311_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @312_58df40
  ecx = edx = 0;  // @313_58df40
  ecx = (u32)(EBP - 12);  // @314_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @315_58df40
  PV[38] = (u32)(ecx);  // @316_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @317_58df40
  ecx = eax;  // @318_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998328), PV[38]);  // @319_58df40
  ecx = edx = 0;  // @320_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @321_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @322_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @323_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @324_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @325_58df40
  ecx = edx = 0;  // @326_58df40
  ecx = (u32)(EBP - 12);  // @327_58df40
  PV[39] = (u32)(ecx);  // @328_58df40
  PSTR = 6979044; goto L58e4f4;  // @329_58df40
  L58e3f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @331_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @332_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @333_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);   // w3g hand fix: stale pending pushes from a jumped-over path were attached  // @334_58df40
  ecx = edx = 0;  // @335_58df40
  ecx = (u32)(EBP - 12);  // @336_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @337_58df40
  PV[40] = (u32)(ecx);  // @338_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @339_58df40
  ecx = eax;  // @340_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6978924), PV[40]);  // @341_58df40
  ecx = edx = 0;  // @342_58df40
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @343_58df40
  ecx = ebx;  // @344_58df40
  eax = ext_592350_thiscall2(ecx, PV[41]);  // @345_58df40
  ecx = edx = 0;  // @346_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @347_58df40
  PV[42] = (u32)(eax);  // @348_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @349_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @350_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[42]);  // @351_58df40
  ecx = edx = 0;  // @352_58df40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 3822), &v, sizeof v); }  // @353_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @354_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @355_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @356_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @357_58df40
  ecx = edx = 0;  // @358_58df40
  ecx = (u32)(EBP - 12);  // @359_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @360_58df40
  PV[43] = (u32)(ecx);  // @361_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @362_58df40
  ecx = eax;  // @363_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998268), PV[43]);  // @364_58df40
  ecx = edx = 0;  // @365_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @366_58df40
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1654), sizeof v); (u32)v; });  // @367_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @368_58df40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @369_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @370_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @371_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6998244), (u32)(0), (u32)(6997712), (u32)(417), PV[44]);  // @372_58df40
  ecx = edx = 0;  // @373_58df40
  eax = (eax & 0xffff);  // @374_58df40
  ecx = ebx;  // @375_58df40
  PV[45] = (u32)(eax);  // @376_58df40
  PV[46] = (u32)(esi);  // @377_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, PV[46], PV[45]);  // @378_58df40
  ecx = edx = 0;  // @379_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @380_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @381_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @382_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @383_58df40
  ecx = edx = 0;  // @384_58df40
  ecx = (u32)(EBP - 12);  // @385_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @386_58df40
  PV[47] = (u32)(ecx);  // @387_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @388_58df40
  ecx = eax;  // @389_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998292), PV[47]);  // @390_58df40
  ecx = edx = 0;  // @391_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @392_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @393_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @394_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @395_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @396_58df40
  ecx = edx = 0;  // @397_58df40
  ecx = (u32)(EBP - 12);  // @398_58df40
  PV[48] = (u32)(ecx);  // @399_58df40
  PSTR = 6978956;
  L58e4f4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @401_58df40
  ecx = eax;  // @402_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @403_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PSTR, PV[48]);  // @404_58df40
  ecx = edx = 0;  // @405_58df40
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @406_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2130), sizeof v); (u32)v; });  // @407_58df40
  eax = ext_596d30_thiscall2(ecx, PV[49]);  // @408_58df40
  ecx = edx = 0;  // @409_58df40
  L58e513:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2130), sizeof v); (u32)v; });  // @411_58df40
  PV[50] = (u32)(ebx);  // @412_58df40
  eax = ext_598eb0_thiscall2(ecx, PV[50]);  // @413_58df40
  ecx = edx = 0;  // @414_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @415_58df40
  PV[51] = (u32)(esi);  // @416_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @417_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @418_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[51]);  // @419_58df40
  ecx = edx = 0;  // @420_58df40
  FL[2] = (eax & eax);  // @421_58df40
  if (FL[2] == 0) goto L58e541;  // @422_58df40
  PV[52] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1668), sizeof v); (u32)v; });  // @423_58df40
  ecx = eax;  // @424_58df40
  eax = ext_4f2f60_thiscall2(ecx, PV[52]);  // @425_58df40
  ecx = edx = 0;  // @426_58df40
  L58e541:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @428_58df40
  if (FL[0] == FL[1]) goto L58e557;  // @429_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2130), sizeof v); (u32)v; });  // @430_58df40
  eax = ext_596d00_thiscall2(ecx, (u32)(0));  // @431_58df40
  ecx = 0;  // @432_58df40
  L58e557:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @434_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @435_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @436_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @437_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @438_58df40
  ecx = edx = 0;  // @439_58df40
  esi = eax;  // @440_58df40
  FL[2] = (esi & esi);  // @441_58df40
  if (FL[2] == 0) goto L58e5bc;  // @442_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @443_58df40
  ecx = esi;  // @444_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 256)))(ecx, (u32)(6970608));  // @445_58df40
  ecx = edx = 0;  // @446_58df40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 2536), &v, sizeof v); }  // @447_58df40
  FL[2] = (eax & eax);  // @448_58df40
  if (FL[2] != 0) goto L58e5bc;  // @449_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @450_58df40
  ecx = esi;  // @451_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 268)))(ecx, (u32)(6998412), (u32)(-1));  // @452_58df40
  ecx = edx = 0;  // @453_58df40
  esi = eax;  // @454_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @455_58df40
  ecx = esi;  // @456_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(1), (u32)(0), (u32)(0));  // @457_58df40
  ecx = edx = 0;  // @458_58df40
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 2536), &v, sizeof v); }  // @459_58df40
  L58e5bc:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @461_58df40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1105) + 0), 4); v; });  // @462_58df40
  X0[1] = 0;  // @463_58df40
  X0[2] = 0;  // @464_58df40
  X0[3] = 0;  // @465_58df40
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000592) + 0), 4); v; })));  // @466_58df40
  __builtin_memcpy((void *)((u32)(ebx + 2079) + 0), &X0[0], 4);  // @467_58df40
  if (FL[0] != FL[1]) goto L58e694;  // @468_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @469_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @470_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @471_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @472_58df40
  ecx = edx = 0;  // @473_58df40
  ecx = (u32)(EBP - 12);  // @474_58df40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @475_58df40
  PV[53] = (u32)(ecx);  // @476_58df40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @477_58df40
  ecx = eax;  // @478_58df40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6970440), PV[53]);  // @479_58df40
  ecx = edx = 0;  // @480_58df40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @481_58df40
  if (FL[0] == FL[1]) goto L58e66c;  // @482_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @483_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 11285), sizeof v); (u32)v; });  // @484_58df40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 74), sizeof v); (u32)v; }); FL[1] = (u32)(49);  // @485_58df40
  if (FL[0] != FL[1]) goto L58e642;  // @486_58df40
  FS[0] = ext_589c40_thiscall3_ld(ecx, (u32)(6984888), (u32)(0));  // @487_58df40
  ecx = edx = 0;  // @488_58df40
  FS[0] = (FS[0] * LDF((u32)(6802752)));  // @489_58df40
  STF((u32)(EBP - 12), FS[0]);  // @490_58df40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @491_58df40
  X0[1] = 0;  // @492_58df40
  X0[2] = 0;  // @493_58df40
  X0[3] = 0;  // @494_58df40
  goto L58e65c;  // @495_58df40
  L58e642:;
  FS[0] = ext_589c40_thiscall3_ld(ecx, (u32)(6984888), (u32)(-1));  // @497_58df40
  ecx = edx = 0;  // @498_58df40
  FS[0] = (FS[0] * LDF((u32)(6802752)));  // @499_58df40
  STF((u32)(EBP - 12), FS[0]);  // @500_58df40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @501_58df40
  X0[1] = 0;  // @502_58df40
  X0[2] = 0;  // @503_58df40
  X0[3] = 0;  // @504_58df40
  L58e65c:;
  __builtin_memcpy((void *)((u32)(ebx + 2043) + 0), &X0[0], 4);  // @506_58df40
  __builtin_memcpy((void *)((u32)(ebx + 2047) + 0), &X0[0], 4);  // @507_58df40
  L58e66c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @509_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11285), sizeof v); (u32)v; });  // @510_58df40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 74), sizeof v); (u32)v; }); FL[1] = (u32)(48);  // @511_58df40
  if (FL[0] == FL[1]) goto L58e6e6;  // @512_58df40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @513_58df40
  ecx = ebx;  // @514_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1004)))(ecx, (u32)(29));  // @515_58df40
  ecx = edx = 0;  // @516_58df40
  PV[54] = (u32)(eax);  // @517_58df40
  ecx = ebx;  // @518_58df40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 984)))(ecx, PV[54]);  // @519_58df40
  ecx = edx = 0;  // @520_58df40
  goto L58e6e6;  // @521_58df40
  L58e694:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @523_58df40
  FS[0] = ext_589c40_thiscall3_ld(ecx, (u32)(6995848), (u32)(-1));  // @524_58df40
  ecx = edx = 0;  // @525_58df40
  FS[0] = (FS[0] * LDF((u32)(6802752)));  // @526_58df40
  PV[55] = (u32)(ecx);  // @527_58df40
  ecx = ebx;  // @528_58df40
  STF((u32)(EBP - 12), FS[0]);  // @529_58df40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @530_58df40
  X0[1] = 0;  // @531_58df40
  X0[2] = 0;  // @532_58df40
  X0[3] = 0;  // @533_58df40
  __builtin_memcpy((void *)((u32)(ebx + 2047) + 0), &X0[0], 4);  // @534_58df40
  __builtin_memcpy((void *)((u32)(ebx + 2043) + 0), &X0[0], 4);  // @535_58df40
  eax = ext_475820_thiscall3(ecx, (u32)(2), (u32)(1084227584));  // @536_58df40
    // @537_58df40
  PV[56] = (u32)(ecx);  // @538_58df40
  ecx = ebx;  // @539_58df40
  eax = ext_475820_thiscall3(ecx, (u32)(3), (u32)(1084227584));  // @540_58df40
    // @541_58df40
  L58e6e6:;
  ecx = ebx;  // @543_58df40
  eax = ext_595100_thiscall1(ecx);  // @544_58df40
  ecx = edx = 0;  // @545_58df40
  ecx = ebx;  // @546_58df40
  eax = ext_592580_thiscall1(ecx);  // @547_58df40
  ecx = edx = 0;  // @548_58df40
  ecx = ebx;  // @549_58df40
  eax = ext_592850_thiscall1(ecx);  // @550_58df40
  ecx = edx = 0;  // @551_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @552_58df40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @553_58df40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @554_58df40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 148)))(ecx);  // @555_58df40
  ecx = edx = 0;  // @556_58df40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @557_58df40
  return eax;  // @558_58df40
}
PCREG(58df40, lifted_58df40);

extern "C" u32 STDCALL lifted_5b6110(u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5b6110
  X1[0] = 0;  // @1_5b6110
  X1[1] = 0;  // @2_5b6110
  X1[2] = 0;  // @3_5b6110
  X1[3] = 0;  // @4_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @5_5b6110
  X0[1] = 0;  // @6_5b6110
  X0[2] = 0;  // @7_5b6110
  X0[3] = 0;  // @8_5b6110
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @10_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @11_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @12_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b618d;  // @13_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @14_5b6110
  X0[1] = 0;  // @15_5b6110
  X0[2] = 0;  // @16_5b6110
  X0[3] = 0;  // @17_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @18_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @19_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @20_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b618d;  // @21_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @23_5b6110
  { u64 r_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r_; edx = (u32)(r_ >> 32); }  // @24_5b6110   // w3g hand fix: the call returns edx:eax
  ecx = 0;  // @25_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_5b6110
  PV[0] = (u32)(edx);  // @27_5b6110
  PV[1] = (u32)(eax);  // @28_5b6110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_5b6110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[1], PV[0], (u32)(7021216));  // @30_5b6110
  ecx = edx = 0;  // @31_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_5b6110
  X1[0] = 0;  // @33_5b6110
  X1[1] = 0;  // @34_5b6110
  X1[2] = 0;  // @35_5b6110
  X1[3] = 0;  // @36_5b6110
  L5b618d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @38_5b6110
  X0[1] = 0;  // @39_5b6110
  X0[2] = 0;  // @40_5b6110
  X0[3] = 0;  // @41_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @42_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @43_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @44_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b61d8;  // @45_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @46_5b6110
  X0[1] = 0;  // @47_5b6110
  X0[2] = 0;  // @48_5b6110
  X0[3] = 0;  // @49_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @50_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @51_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @52_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b61d8;  // @53_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @55_5b6110
  { u64 r_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r_; edx = (u32)(r_ >> 32); }  // @56_5b6110   // w3g hand fix: the call returns edx:eax
  ecx = 0;  // @57_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_5b6110
  PV[2] = (u32)(edx);  // @59_5b6110
  PV[3] = (u32)(eax);  // @60_5b6110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_5b6110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[3], PV[2], (u32)(7021236));  // @62_5b6110
  ecx = edx = 0;  // @63_5b6110
  L5b61d8:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 144), sizeof v); (u32)v; });  // @65_5b6110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @66_5b6110
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 144), &v, sizeof v); }  // @67_5b6110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @68_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_5b6110
  PV[4] = (u32)(edx);  // @70_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_5b6110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[4]);  // @73_5b6110
  ecx = edx = 0;  // @74_5b6110
  ebx = eax;  // @75_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 116), &v, sizeof v); }  // @76_5b6110
  ecx = (u32)((EBP - 264) + 152);  // @77_5b6110
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @78_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 120), &v, sizeof v); }  // @79_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 124), &v, sizeof v); }  // @80_5b6110
  eax = ext_4de7a0_thiscall1(ecx);  // @81_5b6110
    // @82_5b6110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @83_5b6110
  eax = (u32)((EBP - 264) + 116);  // @84_5b6110
  PV[5] = (u32)(eax);  // @85_5b6110
  eax = (u32)((EBP - 268) + 156);  // @86_5b6110
  ecx = ebx;  // @87_5b6110
  PV[6] = (u32)(eax);  // @88_5b6110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[6], PV[5]);  // @89_5b6110
  ecx = edx = 0;  // @90_5b6110
  eax = (u32)(edi + 76);  // @91_5b6110
  PV[7] = (u32)(eax);  // @92_5b6110
  edx = (u32)((EBP - 268) + 120);  // @93_5b6110
  ecx = (u32)((EBP - 268) + 52);  // @94_5b6110
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @95_5b6110
  ecx = edx = 0;  // @96_5b6110
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 48) + 0), 4); v; });  // @97_5b6110
  X1[1] = 0;  // @98_5b6110
  X1[2] = 0;  // @99_5b6110
  X1[3] = 0;  // @100_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 52) + 0), 4); v; });  // @101_5b6110
  X0[1] = 0;  // @102_5b6110
  X0[2] = 0;  // @103_5b6110
  X0[3] = 0;  // @104_5b6110
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @105_5b6110
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @106_5b6110
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @107_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 56) + 0), 4); v; });  // @108_5b6110
  X0[1] = 0;  // @109_5b6110
  X0[2] = 0;  // @110_5b6110
  X0[3] = 0;  // @111_5b6110
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @112_5b6110
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @113_5b6110
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @114_5b6110
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @115_5b6110
  ecx = edx = 0;  // @116_5b6110
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @117_5b6110
  eax = (u32)((EBP - 264) + 116);  // @118_5b6110
  PV[8] = (u32)(eax);  // @119_5b6110
  edx = (u32)(edi + 64);  // @120_5b6110
  ecx = (u32)((EBP - 268) + 40);  // @121_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 268) + 16) + 0), &X0[0], 4);  // @122_5b6110
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @123_5b6110
  ecx = edx = 0;  // @124_5b6110
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_5b6110
  X1[0] = 0;  // @126_5b6110
  X1[1] = 0;  // @127_5b6110
  X1[2] = 0;  // @128_5b6110
  X1[3] = 0;  // @129_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; });  // @130_5b6110
  X0[1] = 0;  // @131_5b6110
  X0[2] = 0;  // @132_5b6110
  X0[3] = 0;  // @133_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @134_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @135_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @136_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b62ee;  // @137_5b6110
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 36) + 0), 4); v; });  // @138_5b6110
  X1[1] = 0;  // @139_5b6110
  X1[2] = 0;  // @140_5b6110
  X1[3] = 0;  // @141_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 40) + 0), 4); v; });  // @142_5b6110
  X0[1] = 0;  // @143_5b6110
  X0[2] = 0;  // @144_5b6110
  X0[3] = 0;  // @145_5b6110
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @146_5b6110
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @147_5b6110
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @148_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; });  // @149_5b6110
  X0[1] = 0;  // @150_5b6110
  X0[2] = 0;  // @151_5b6110
  X0[3] = 0;  // @152_5b6110
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @153_5b6110
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @154_5b6110
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @155_5b6110
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @156_5b6110
  ecx = edx = 0;  // @157_5b6110
  X2[0] = 0;  // @158_5b6110
  X2[1] = 0;  // @159_5b6110
  X2[2] = 0;  // @160_5b6110
  X2[3] = 0;  // @161_5b6110
  X1[0] = 0;  // @162_5b6110
  X1[1] = 0;  // @163_5b6110
  X1[2] = 0;  // @164_5b6110
  X1[3] = 0;  // @165_5b6110
  X2[0] = F2U((float)U2D(X0[0], X0[1]));  // @166_5b6110
  X2[0] = F2U(U2F(X2[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; })));  // @167_5b6110
  goto L5b62f1;  // @168_5b6110
  L5b62ee:;
  X2[0] = X1[0];  // @170_5b6110
  X2[1] = X1[1];  // @171_5b6110
  X2[2] = X1[2];  // @172_5b6110
  X2[3] = X1[3];  // @173_5b6110
  L5b62f1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 116) + 0), 4); v; });  // @175_5b6110
  X0[1] = 0;  // @176_5b6110
  X0[2] = 0;  // @177_5b6110
  X0[3] = 0;  // @178_5b6110
  FA = U2F(X2[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; }));  // @179_5b6110
  __builtin_memcpy((void *)((u32)(edi + 64) + 0), &X0[0], 4);  // @180_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 120) + 0), 4); v; });  // @181_5b6110
  X0[1] = 0;  // @182_5b6110
  X0[2] = 0;  // @183_5b6110
  X0[3] = 0;  // @184_5b6110
  __builtin_memcpy((void *)((u32)(edi + 68) + 0), &X0[0], 4);  // @185_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 124) + 0), 4); v; });  // @186_5b6110
  X0[1] = 0;  // @187_5b6110
  X0[2] = 0;  // @188_5b6110
  X0[3] = 0;  // @189_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 16) + 0), &X2[0], 4);  // @190_5b6110
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 12) + 0), 4); v; });  // @191_5b6110
  X2[1] = 0;  // @192_5b6110
  X2[2] = 0;  // @193_5b6110
  X2[3] = 0;  // @194_5b6110
  __builtin_memcpy((void *)((u32)(edi + 72) + 0), &X0[0], 4);  // @195_5b6110
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5b6376;  // @196_5b6110
  FA = U2F(X2[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; }));  // @197_5b6110
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5b6376;  // @198_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 140) + 0), 4); v; });  // @199_5b6110
  X0[1] = 0;  // @200_5b6110
  X0[2] = 0;  // @201_5b6110
  X0[3] = 0;  // @202_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @203_5b6110
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b635b;  // @204_5b6110
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; })));  // @205_5b6110
  X2[0] = X1[0];  // @206_5b6110
  X2[1] = X1[1];  // @207_5b6110
  X2[2] = X1[2];  // @208_5b6110
  X2[3] = X1[3];  // @209_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 16) + 0), &X1[0], 4);  // @210_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 12) + 0), &X2[0], 4);  // @211_5b6110
  __builtin_memcpy((void *)((u32)(edi + 140) + 0), &X0[0], 4);  // @212_5b6110
  goto L5b639a;  // @213_5b6110
  L5b635b:;
  X2[0] = X1[0];  // @215_5b6110
  X2[1] = X1[1];  // @216_5b6110
  X2[2] = X1[2];  // @217_5b6110
  X2[3] = X1[3];  // @218_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 136), &v, sizeof v); }  // @219_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 12) + 0), &X2[0], 4);  // @220_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 16) + 0), &X1[0], 4);  // @221_5b6110
  goto L5b639a;  // @222_5b6110
  L5b6376:;
  { u32 v = (u32)((u32)(1077936128)); __builtin_memcpy((void *)(u32)(edi + 140), &v, sizeof v); }  // @224_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @225_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @226_5b6110
  X0[1] = 0;  // @227_5b6110
  X0[2] = 0;  // @228_5b6110
  X0[3] = 0;  // @229_5b6110
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 136) + 0), 4); v; })));  // @230_5b6110
  __builtin_memcpy((void *)((u32)(edi + 136) + 0), &X0[0], 4);  // @231_5b6110
  L5b639a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 136) + 0), 4); v; });  // @233_5b6110
  X0[1] = 0;  // @234_5b6110
  X0[2] = 0;  // @235_5b6110
  X0[3] = 0;  // @236_5b6110
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @237_5b6110
  if ((!(FA >= FB))) goto L5b63d7;  // @238_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 140) + 0), 4); v; });  // @239_5b6110
  X0[1] = 0;  // @240_5b6110
  X0[2] = 0;  // @241_5b6110
  X0[3] = 0;  // @242_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @243_5b6110
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi + 136), &v, sizeof v); }  // @244_5b6110
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b63cd;  // @245_5b6110
  ebx = (u32)(1);  // @246_5b6110
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @247_5b6110
  goto L5b63db;  // @248_5b6110
  L5b63cd:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 136), &v, sizeof v); }  // @250_5b6110
  L5b63d7:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @252_5b6110
  L5b63db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 24), sizeof v); (u32)v; });  // @254_5b6110
  ecx = 0;  // @255_5b6110
  FL[3] = ecx;  // @256_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1047), sizeof v); (u32)v; });  // @257_5b6110
  FL[2] = ((eax & 0xff) & (u32)(1));  // @258_5b6110
  if (FL[2] == 0) goto L5b63f2;  // @259_5b6110
  ecx = (u32)(2);  // @260_5b6110
  goto L5b63fc;  // @261_5b6110
  L5b63f2:;
  FL[2] = ((eax & 0xff) & (u32)(2));  // @263_5b6110
  eax = (u32)(1);  // @264_5b6110
  if (FL[2] != 0) ecx = eax;  // @265_5b6110
  L5b63fc:;
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @267_5b6110
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 28), &v, sizeof v); }  // @268_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @269_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @270_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b6410;  // @271_5b6110
  ecx = (ecx + (u32)(2));  // @272_5b6110
  FL[3] = ecx;  // @273_5b6110
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 28), &v, sizeof v); }  // @274_5b6110
  L5b6410:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @276_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @277_5b6110
  X0[1] = 0;  // @278_5b6110
  X0[2] = 0;  // @279_5b6110
  X0[3] = 0;  // @280_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @281_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @282_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @283_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b646a;  // @284_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @285_5b6110
  X0[1] = 0;  // @286_5b6110
  X0[2] = 0;  // @287_5b6110
  X0[3] = 0;  // @288_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @289_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @290_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @291_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b646a;  // @292_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @293_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @294_5b6110
  { u64 r_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r_; edx = (u32)(r_ >> 32); }  // @295_5b6110   // w3g hand fix: the call returns edx:eax
  ecx = 0;  // @296_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @297_5b6110
  PV[9] = (u32)(edx);  // @298_5b6110
  PV[10] = (u32)(eax);  // @299_5b6110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @300_5b6110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[10], PV[9], (u32)(7021236));  // @301_5b6110
  ecx = edx = 0;  // @302_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @303_5b6110
  X1[0] = 0;  // @304_5b6110
  X1[1] = 0;  // @305_5b6110
  X1[2] = 0;  // @306_5b6110
  X1[3] = 0;  // @307_5b6110
  L5b646a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @309_5b6110
  X0[1] = 0;  // @310_5b6110
  X0[2] = 0;  // @311_5b6110
  X0[3] = 0;  // @312_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @313_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @314_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @315_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b64be;  // @316_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @317_5b6110
  X0[1] = 0;  // @318_5b6110
  X0[2] = 0;  // @319_5b6110
  X0[3] = 0;  // @320_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @321_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @322_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @323_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b64be;  // @324_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @325_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @326_5b6110
  { u64 r_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r_; edx = (u32)(r_ >> 32); }  // @327_5b6110   // w3g hand fix: the call returns edx:eax
  ecx = 0;  // @328_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @329_5b6110
  PV[11] = (u32)(edx);  // @330_5b6110
  PV[12] = (u32)(eax);  // @331_5b6110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @332_5b6110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[12], PV[11], (u32)(7021248));  // @333_5b6110
  ecx = edx = 0;  // @334_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @335_5b6110
  X1[0] = 0;  // @336_5b6110
  X1[1] = 0;  // @337_5b6110
  X1[2] = 0;  // @338_5b6110
  X1[3] = 0;  // @339_5b6110
  L5b64be:;
  FL[2] = (ebx & ebx);  // @341_5b6110
  if (FL[2] == 0) goto L5b6518;  // @342_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 116) + 0), 4); v; });  // @343_5b6110
  X0[1] = 0;  // @344_5b6110
  X0[2] = 0;  // @345_5b6110
  X0[3] = 0;  // @346_5b6110
  ecx = (u32)(edi + 100);  // @347_5b6110
  __builtin_memcpy((void *)((u32)(edi + 76) + 0), &X0[0], 4);  // @348_5b6110
  edx = (u32)((EBP - 264) + 152);  // @349_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 120) + 0), 4); v; });  // @350_5b6110
  X0[1] = 0;  // @351_5b6110
  X0[2] = 0;  // @352_5b6110
  X0[3] = 0;  // @353_5b6110
  __builtin_memcpy((void *)((u32)(edi + 80) + 0), &X0[0], 4);  // @354_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 124) + 0), 4); v; });  // @355_5b6110
  X0[1] = 0;  // @356_5b6110
  X0[2] = 0;  // @357_5b6110
  X0[3] = 0;  // @358_5b6110
  __builtin_memcpy((void *)((u32)(edi + 84) + 0), &X0[0], 4);  // @359_5b6110
  eax = ext_4de420_fastcall2(ecx, edx);  // @360_5b6110
    // @361_5b6110
  edx = (u32)((EBP - 264) + 36);  // @362_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 40), &v, sizeof v); }  // @363_5b6110
  ecx = (u32)(edi + 88);  // @364_5b6110
  eax = ext_44e630_fastcall2(ecx, edx);  // @365_5b6110
  ecx = edx = 0;  // @366_5b6110
  ecx = (u32)(edi + 88);  // @367_5b6110
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @368_5b6110
  eax = ext_4e09b0_thiscall1(ecx);  // @369_5b6110
    // @370_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @371_5b6110
  goto L5b6524;  // @372_5b6110
  L5b6518:;
  __builtin_memcpy((void *)((u32)((EBP - 264) + 12) + 0), &X1[0], 4);  // @374_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 16) + 0), &X1[0], 4);  // @375_5b6110
  L5b6524:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @377_5b6110
  FL[2] = (edx & edx);  // @378_5b6110
  if (FL[2] == 0) goto L5b6976;  // @379_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @380_5b6110
  ecx = (u32)((EBP - 264) + 72);  // @381_5b6110
  PV[13] = (u32)(ecx);  // @382_5b6110
  ecx = edx;  // @383_5b6110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @384_5b6110
  ecx = edx = 0;  // @385_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @386_5b6110
  edx = (u32)((EBP - 264) + 72);  // @387_5b6110
  PV[14] = (u32)(edx);  // @388_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @389_5b6110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[14]);  // @390_5b6110
  ecx = edx = 0;  // @391_5b6110
  esi = eax;  // @392_5b6110
  FL[2] = (esi & esi);  // @393_5b6110
  if (FL[2] == 0) goto L5b6970;  // @394_5b6110
  L5b6552:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @396_5b6110
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @397_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @398_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @399_5b6110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[15]);  // @400_5b6110
  ecx = edx = 0;  // @401_5b6110
  ecx = (u32)((EBP - 264) + 188);  // @402_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 140), &v, sizeof v); }  // @403_5b6110
  ebx = eax;  // @404_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 144), &v, sizeof v); }  // @405_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 148), &v, sizeof v); }  // @406_5b6110
  eax = ext_4de7a0_thiscall1(ecx);  // @407_5b6110
    // @408_5b6110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @409_5b6110
  eax = (u32)((EBP - 264) + 140);  // @410_5b6110
  PV[16] = (u32)(eax);  // @411_5b6110
  eax = (u32)((EBP - 268) + 192);  // @412_5b6110
  ecx = ebx;  // @413_5b6110
  PV[17] = (u32)(eax);  // @414_5b6110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[17], PV[16]);  // @415_5b6110
  ecx = edx = 0;  // @416_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @417_5b6110
  PV[18] = (u32)(ecx);  // @418_5b6110
  ecx = (u32)((EBP - 268) + 88);  // @419_5b6110
  eax = (u32)(eax + eax*2);  // @420_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 7268872) + 0), 4); v; });  // @421_5b6110
  X0[1] = 0;  // @422_5b6110
  X0[2] = 0;  // @423_5b6110
  X0[3] = 0;  // @424_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 268) + 88) + 0), &X0[0], 4);  // @425_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 7268876) + 0), 4); v; });  // @426_5b6110
  X0[1] = 0;  // @427_5b6110
  X0[2] = 0;  // @428_5b6110
  X0[3] = 0;  // @429_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 268) + 92) + 0), &X0[0], 4);  // @430_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 7268880) + 0), 4); v; });  // @431_5b6110
  X0[1] = 0;  // @432_5b6110
  X0[2] = 0;  // @433_5b6110
  X0[3] = 0;  // @434_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 268) + 96) + 0), &X0[0], 4);  // @435_5b6110
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1067450368));  // @436_5b6110
    // @437_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @438_5b6110
  X0[1] = 0;  // @439_5b6110
  X0[2] = 0;  // @440_5b6110
  X0[3] = 0;  // @441_5b6110
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 16) + 0), 4); v; }));  // @442_5b6110
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b6653;  // @443_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 88) + 0), 4); v; });  // @444_5b6110
  X0[1] = 0;  // @445_5b6110
  X0[2] = 0;  // @446_5b6110
  X0[3] = 0;  // @447_5b6110
  edx = (u32)(edi + 88);  // @448_5b6110
  X1[0] = 0;  // @449_5b6110
  X1[1] = 0;  // @450_5b6110
  X1[2] = 0;  // @451_5b6110
  X1[3] = 0;  // @452_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @453_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @454_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @455_5b6110
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b6635;  // @456_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 4) + 0), 4); v; });  // @457_5b6110
  X0[1] = 0;  // @458_5b6110
  X0[2] = 0;  // @459_5b6110
  X0[3] = 0;  // @460_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @461_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @462_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @463_5b6110
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b6635;  // @464_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 8) + 0), 4); v; });  // @465_5b6110
  X0[1] = 0;  // @466_5b6110
  X0[2] = 0;  // @467_5b6110
  X0[3] = 0;  // @468_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @469_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @470_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @471_5b6110
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b6635;  // @472_5b6110
  edx = (u32)(edi + 100);  // @473_5b6110
  goto L5b664a;  // @474_5b6110
  L5b6635:;
  ecx = (u32)((EBP - 268) + 228);  // @476_5b6110
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @477_5b6110
  ecx = edx = 0;  // @478_5b6110
  edx = (u32)((EBP - 264) + 224);  // @479_5b6110
  L5b664a:;
  ecx = (u32)((EBP - 264) + 84);  // @481_5b6110
  eax = ext_4419f0_fastcall2(ecx, edx);  // @482_5b6110
  ecx = edx = 0;  // @483_5b6110
  L5b6653:;
  edx = (u32)(edi + 76);  // @485_5b6110
  ecx = (u32)((EBP - 264) + 84);  // @486_5b6110
  eax = ext_441940_fastcall2(ecx, edx);  // @487_5b6110
  ecx = edx = 0;  // @488_5b6110
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 12) + 0), 4); v; });  // @489_5b6110
  X1[1] = 0;  // @490_5b6110
  X1[2] = 0;  // @491_5b6110
  X1[3] = 0;  // @492_5b6110
  X0[0] = 0;  // @493_5b6110
  X0[1] = 0;  // @494_5b6110
  X0[2] = 0;  // @495_5b6110
  X0[3] = 0;  // @496_5b6110
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @497_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @498_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @499_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b6768;  // @500_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 84) + 0), 4); v; });  // @501_5b6110
  X0[1] = 0;  // @502_5b6110
  X0[2] = 0;  // @503_5b6110
  X0[3] = 0;  // @504_5b6110
  edx = (u32)((EBP - 264) + 140);  // @505_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 0), &X0[0], 4);  // @506_5b6110
  ecx = (u32)((EBP - 264) + 128);  // @507_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; });  // @508_5b6110
  X0[1] = 0;  // @509_5b6110
  X0[2] = 0;  // @510_5b6110
  X0[3] = 0;  // @511_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 132) + 0), &X0[0], 4);  // @512_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 92) + 0), 4); v; });  // @513_5b6110
  X0[1] = 0;  // @514_5b6110
  X0[2] = 0;  // @515_5b6110
  X0[3] = 0;  // @516_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 136) + 0), &X0[0], 4);  // @517_5b6110
  eax = ext_43e960_fastcall2(ecx, edx);  // @518_5b6110
  ecx = edx = 0;  // @519_5b6110
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 128) + 0), 4); v; });  // @520_5b6110
  X2[1] = 0;  // @521_5b6110
  X2[2] = 0;  // @522_5b6110
  X2[3] = 0;  // @523_5b6110
  X0[0] = 0;  // @524_5b6110
  X0[1] = 0;  // @525_5b6110
  X0[2] = 0;  // @526_5b6110
  X0[3] = 0;  // @527_5b6110
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 136) + 0), 4); v; });  // @528_5b6110
  X1[1] = 0;  // @529_5b6110
  X1[2] = 0;  // @530_5b6110
  X1[3] = 0;  // @531_5b6110
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @532_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 132), &v, sizeof v); }  // @533_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @534_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @535_5b6110
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b66e7;  // @536_5b6110
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @537_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @538_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @539_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b6758;  // @540_5b6110
  L5b66e7:;
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @542_5b6110
  eax = (u32)((EBP - 264) + 128);  // @543_5b6110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 32), &v, sizeof v); }  // @544_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @545_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @546_5b6110
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b6704;  // @547_5b6110
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @548_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @549_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @550_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b6744;  // @551_5b6110
  L5b6704:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @553_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @554_5b6110
  FS[0] = LDF((u32)(ecx));  // @555_5b6110
  FS[0] = (FS[0] * FS[0]);  // @556_5b6110
  FS[1] = LDF((u32)(ecx + 4));  // @557_5b6110
  FS[1] = (FS[1] * FS[1]);  // @558_5b6110
  FS[0] = (FS[0] + FS[1]);  // @559_5b6110
  FS[1] = LDF((u32)(ecx + 8));  // @560_5b6110
  FS[1] = (FS[1] * FS[1]);  // @561_5b6110
  FS[0] = (FS[0] + FS[1]);  // @562_5b6110
  FSQRT(FS[0]);  // @563_5b6110
  FS[1] = LDF((u32)((EBP - 264) + 24));  // @564_5b6110
  FS[1] = (FS[1] / FS[0]);  // @565_5b6110
  FS[2] = LDF((u32)(ecx));  // @566_5b6110
  FS[2] = (FS[2] * FS[1]);  // @567_5b6110
  STF((u32)(ecx), FS[2]);  // @568_5b6110
  FS[2] = LDF((u32)(ecx + 4));  // @569_5b6110
  FS[2] = (FS[2] * FS[1]);  // @570_5b6110
  STF((u32)(ecx + 4), FS[2]);  // @571_5b6110
  FS[2] = LDF((u32)(ecx + 8));  // @572_5b6110
  FS[1] = (FS[1] * FS[2]);  // @573_5b6110
  STF((u32)(ecx + 8), FS[1]);  // @574_5b6110
  STF((u32)((EBP - 264) + 24), FS[0]);  // @575_5b6110
  L5b6744:;
  PV[19] = (u32)(ecx);  // @577_5b6110
  ecx = (u32)((EBP - 268) + 132);  // @578_5b6110
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1128792064));  // @579_5b6110
    // @580_5b6110
  L5b6758:;
  edx = (u32)((EBP - 264) + 128);  // @582_5b6110
  ecx = (u32)((EBP - 264) + 84);  // @583_5b6110
  eax = ext_441940_fastcall2(ecx, edx);  // @584_5b6110
  ecx = edx = 0;  // @585_5b6110
  L5b6768:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1681), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @587_5b6110
  if ((s32)FL[0] > (s32)FL[1]) goto L5b6959;  // @588_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @589_5b6110
  ecx = ebx;  // @590_5b6110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1488)))(ecx);  // @591_5b6110
  ecx = edx = 0;  // @592_5b6110
  FL[2] = (eax & eax);  // @593_5b6110
  if (FL[2] == 0) goto L5b6816;  // @594_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @595_5b6110
  ecx = ebx;  // @596_5b6110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1488)))(ecx);  // @597_5b6110
  ecx = edx = 0;  // @598_5b6110
  ecx = (u32)((EBP - 264) + 84);  // @599_5b6110
  PV[20] = (u32)(ecx);  // @600_5b6110
  ecx = eax;  // @601_5b6110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @602_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 544), sizeof v); (u32)v; });  // @603_5b6110
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[20]);  // @604_5b6110
  ecx = edx = 0;  // @605_5b6110
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @606_5b6110
  if (FL[2] != 0) goto L5b6816;  // @607_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @608_5b6110
  eax = (u32)(ecx + 1);  // @609_5b6110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @610_5b6110
  FL[0] = ecx; FL[1] = (u32)(3);  // @611_5b6110
  if ((s32)FL[0] < (s32)FL[1]) goto L5b6959;  // @612_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @613_5b6110
  eax = 0;  // @614_5b6110
  FL[3] = eax;  // @615_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @616_5b6110
  FL[0] = ecx; FL[1] = (u32)(12);  // @617_5b6110
  if ((s32)FL[0] >= (s32)FL[1]) goto L5b67fd;  // @618_5b6110
  edx = (u32)(edi + 12);  // @619_5b6110
  edx = (u32)(edx + ecx*4);  // @620_5b6110
  L5b67d0:;
  FL[2] = (eax & eax);  // @622_5b6110
  if (FL[2] != 0) goto L5b67fa;  // @623_5b6110
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = eax;  // @624_5b6110
  if (FL[0] != FL[1]) goto L5b67f1;  // @625_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @626_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + eax*4 + 12), &v, sizeof v); }  // @627_5b6110
  eax = (u32)(1);  // @628_5b6110
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @629_5b6110
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @630_5b6110
  L5b67f1:;
  ecx = (ecx + 1);  // @632_5b6110
  FL[3] = ecx;  // @633_5b6110
  edx = (edx + (u32)(4));  // @634_5b6110
  FL[3] = edx;  // @635_5b6110
  FL[0] = ecx; FL[1] = (u32)(12);  // @636_5b6110
  if ((s32)FL[0] < (s32)FL[1]) goto L5b67d0;  // @637_5b6110
  L5b67fa:;
  FL[0] = ecx; FL[1] = (u32)(12);  // @639_5b6110
  L5b67fd:;
  if (FL[0] != FL[1]) goto L5b680b;  // @641_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @642_5b6110
  goto L5b6959;  // @643_5b6110
  L5b680b:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @645_5b6110
  FL[2] = (eax & eax);  // @646_5b6110
  if (FL[2] != 0) goto L5b6959;  // @647_5b6110
  L5b6816:;
  eax = (u32)((EBP - 264) + 140);  // @649_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @650_5b6110
  PV[21] = (u32)(eax);  // @651_5b6110
  edx = (u32)((EBP - 268) + 88);  // @652_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @653_5b6110
  ecx = (u32)((EBP - 268) + 64);  // @654_5b6110
  eax = ext_43e920_fastcall3(ecx, edx, PV[21]);  // @655_5b6110
  ecx = edx = 0;  // @656_5b6110
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 60) + 0), 4); v; });  // @657_5b6110
  X1[1] = 0;  // @658_5b6110
  X1[2] = 0;  // @659_5b6110
  X1[3] = 0;  // @660_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 64) + 0), 4); v; });  // @661_5b6110
  X0[1] = 0;  // @662_5b6110
  X0[2] = 0;  // @663_5b6110
  X0[3] = 0;  // @664_5b6110
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @665_5b6110
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @666_5b6110
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @667_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 68) + 0), 4); v; });  // @668_5b6110
  X0[1] = 0;  // @669_5b6110
  X0[2] = 0;  // @670_5b6110
  X0[3] = 0;  // @671_5b6110
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @672_5b6110
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @673_5b6110
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @674_5b6110
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @675_5b6110
  ecx = edx = 0;  // @676_5b6110
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @677_5b6110
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @678_5b6110
  __builtin_memcpy((void *)((u32)((EBP - 264) + 108) + 0), &X0[0], 4);  // @679_5b6110
  if (FL[0] != FL[1]) goto L5b6884;  // @680_5b6110
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @681_5b6110
  goto L5b6959;  // @682_5b6110
  L5b6884:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @684_5b6110
  X1[1] = 0;  // @685_5b6110
  X1[2] = 0;  // @686_5b6110
  X1[3] = 0;  // @687_5b6110
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @688_5b6110
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b689d;  // @689_5b6110
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @690_5b6110
  goto L5b6959;  // @691_5b6110
  L5b689d:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 17) + 0), 4); v; });  // @693_5b6110
  X1[1] = 0;  // @694_5b6110
  X1[2] = 0;  // @695_5b6110
  X1[3] = 0;  // @696_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @697_5b6110
  X0[0] = X1[0];  // @698_5b6110
  X0[1] = X1[1];  // @699_5b6110
  X0[2] = X1[2];  // @700_5b6110
  X0[3] = X1[3];  // @701_5b6110
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @702_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @703_5b6110
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @704_5b6110
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @705_5b6110
  FL[0] = ecx; FL[1] = eax;  // @706_5b6110
  if ((s32)FL[0] >= (s32)FL[1]) goto L5b68d1;  // @707_5b6110
  X0[0] = 0;  // @708_5b6110
  X0[1] = 0;  // @709_5b6110
  X0[2] = 0;  // @710_5b6110
  X0[3] = 0;  // @711_5b6110
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @712_5b6110
  if ((!(!(FA >= FB)))) goto L5b6959;  // @713_5b6110
  L5b68d1:;
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @715_5b6110
  X0[0] = F2U((float)(s32)X0[0]);  // @716_5b6110
  X0[1] = F2U((float)(s32)X0[1]);  // @717_5b6110
  X0[2] = F2U((float)(s32)X0[2]);  // @718_5b6110
  X0[3] = F2U((float)(s32)X0[3]);  // @719_5b6110
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @720_5b6110
  __builtin_memcpy((void *)((u32)(esi + 17) + 0), &X0[0], 4);  // @721_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @722_5b6110
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @723_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @724_5b6110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[22]);  // @725_5b6110
  ecx = edx = 0;  // @726_5b6110
  FL[2] = (eax & eax);  // @727_5b6110
  if (FL[2] != 0) goto L5b6905;  // @728_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @729_5b6110
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @730_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @731_5b6110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[23]);  // @732_5b6110
  ecx = edx = 0;  // @733_5b6110
  esi = eax;  // @734_5b6110
  FL[2] = (esi & esi);  // @735_5b6110
  if (FL[2] == 0) goto L5b6959;  // @736_5b6110
  goto L5b6908;  // @737_5b6110
  L5b6905:;
  esi = (u32)(eax + 4);  // @739_5b6110
  L5b6908:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 84) + 0), 4); v; });  // @741_5b6110
  X0[1] = 0;  // @742_5b6110
  X0[2] = 0;  // @743_5b6110
  X0[3] = 0;  // @744_5b6110
  ecx = (u32)(esi + 12);  // @745_5b6110
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @746_5b6110
  edx = (u32)(edi + 100);  // @747_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; });  // @748_5b6110
  X0[1] = 0;  // @749_5b6110
  X0[2] = 0;  // @750_5b6110
  X0[3] = 0;  // @751_5b6110
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @752_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 92) + 0), 4); v; });  // @753_5b6110
  X0[1] = 0;  // @754_5b6110
  X0[2] = 0;  // @755_5b6110
  X0[3] = 0;  // @756_5b6110
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @757_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 108) + 0), 4); v; });  // @758_5b6110
  X0[1] = 0;  // @759_5b6110
  X0[2] = 0;  // @760_5b6110
  X0[3] = 0;  // @761_5b6110
  __builtin_memcpy((void *)((u32)(esi + 24) + 0), &X0[0], 4);  // @762_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @763_5b6110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @764_5b6110
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @765_5b6110
  eax = ext_4419f0_fastcall2(ecx, edx);  // @766_5b6110
  ecx = edx = 0;  // @767_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 28), sizeof v); (u32)v; });  // @768_5b6110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @769_5b6110
  L5b6959:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @771_5b6110
  edx = (u32)((EBP - 264) + 72);  // @772_5b6110
  PV[24] = (u32)(edx);  // @773_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @774_5b6110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[24]);  // @775_5b6110
  ecx = edx = 0;  // @776_5b6110
  esi = eax;  // @777_5b6110
  FL[2] = (esi & esi);  // @778_5b6110
  if (FL[2] != 0) goto L5b6552;  // @779_5b6110
  L5b6970:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @781_5b6110
  L5b6976:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @783_5b6110
  X0[1] = 0;  // @784_5b6110
  X0[2] = 0;  // @785_5b6110
  X0[3] = 0;  // @786_5b6110
  X1[0] = 0;  // @787_5b6110
  X1[1] = 0;  // @788_5b6110
  X1[2] = 0;  // @789_5b6110
  X1[3] = 0;  // @790_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @791_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @792_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @793_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b69cd;  // @794_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @795_5b6110
  X0[1] = 0;  // @796_5b6110
  X0[2] = 0;  // @797_5b6110
  X0[3] = 0;  // @798_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @799_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @800_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @801_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b69cd;  // @802_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @803_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @804_5b6110
  { u64 r_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r_; edx = (u32)(r_ >> 32); }  // @805_5b6110   // w3g hand fix: the call returns edx:eax
  ecx = 0;  // @806_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @807_5b6110
  PV[25] = (u32)(edx);  // @808_5b6110
  PV[26] = (u32)(eax);  // @809_5b6110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @810_5b6110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[26], PV[25], (u32)(7021248));  // @811_5b6110
  ecx = edx = 0;  // @812_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @813_5b6110
  X1[0] = 0;  // @814_5b6110
  X1[1] = 0;  // @815_5b6110
  X1[2] = 0;  // @816_5b6110
  X1[3] = 0;  // @817_5b6110
  L5b69cd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @819_5b6110
  X0[1] = 0;  // @820_5b6110
  X0[2] = 0;  // @821_5b6110
  X0[3] = 0;  // @822_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @823_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @824_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @825_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b6a18;  // @826_5b6110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @827_5b6110
  X0[1] = 0;  // @828_5b6110
  X0[2] = 0;  // @829_5b6110
  X0[3] = 0;  // @830_5b6110
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @831_5b6110
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @832_5b6110
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @833_5b6110
  if (__builtin_parity(FL[2] & 0xff)) goto L5b6a18;  // @834_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @835_5b6110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @836_5b6110
  { u64 r_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r_; edx = (u32)(r_ >> 32); }  // @837_5b6110   // w3g hand fix: the call returns edx:eax
  ecx = 0;  // @838_5b6110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @839_5b6110
  PV[27] = (u32)(edx);  // @840_5b6110
  PV[28] = (u32)(eax);  // @841_5b6110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @842_5b6110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[28], PV[27], (u32)(7021216));  // @843_5b6110
  ecx = edx = 0;  // @844_5b6110
  L5b6a18:;
  ext_633654(G(u32, 0x6f5630));  // @846_5b6110
  return eax;  // @847_5b6110
}
PCREG(5b6110, lifted_5b6110);

extern "C" u32 THISCALL lifted_5ce0b0_w3gold(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
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
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @29_5ce0b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 232) + 40), &v, sizeof v); }  // @30_5ce0b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 232) + 20), &v, sizeof v); }  // @31_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @32_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @33_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce14d;  // @34_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @35_5ce0b0
  X0[1] = 0;  // @36_5ce0b0
  X0[2] = 0;  // @37_5ce0b0
  X0[3] = 0;  // @38_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @39_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @40_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @41_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce14d;  // @42_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @43_5ce0b0
  X0[1] = 0;  // @44_5ce0b0
  X0[2] = 0;  // @45_5ce0b0
  X0[3] = 0;  // @46_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @47_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @48_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @49_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce193;  // @50_5ce0b0
  L5ce14d:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 232) + 16), &v, sizeof v); }  // @52_5ce0b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 20), sizeof v); (u32)v; });  // @53_5ce0b0
  FS[0] = LDF((u32)(ecx));  // @54_5ce0b0
  FS[0] = (FS[0] * FS[0]);  // @55_5ce0b0
  FS[1] = LDF((u32)(ecx + 4));  // @56_5ce0b0
  FS[1] = (FS[1] * FS[1]);  // @57_5ce0b0
  FS[0] = (FS[0] + FS[1]);  // @58_5ce0b0
  FS[1] = LDF((u32)(ecx + 8));  // @59_5ce0b0
  FS[1] = (FS[1] * FS[1]);  // @60_5ce0b0
  FS[0] = (FS[0] + FS[1]);  // @61_5ce0b0
  FSQRT(FS[0]);  // @62_5ce0b0
  FS[1] = LDF((u32)((EBP - 232) + 16));  // @63_5ce0b0
  FS[1] = (FS[1] / FS[0]);  // @64_5ce0b0
  FS[2] = LDF((u32)(ecx));  // @65_5ce0b0
  FS[2] = (FS[2] * FS[1]);  // @66_5ce0b0
  STF((u32)(ecx), FS[2]);  // @67_5ce0b0
  FS[2] = LDF((u32)(ecx + 4));  // @68_5ce0b0
  FS[2] = (FS[2] * FS[1]);  // @69_5ce0b0
  STF((u32)(ecx + 4), FS[2]);  // @70_5ce0b0
  FS[2] = LDF((u32)(ecx + 8));  // @71_5ce0b0
  FS[1] = (FS[1] * FS[2]);  // @72_5ce0b0
  STF((u32)(ecx + 8), FS[1]);  // @73_5ce0b0
  STF((u32)((EBP - 232) + 16), FS[0]);  // @74_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; });  // @75_5ce0b0
  X1[1] = 0;  // @76_5ce0b0
  X1[2] = 0;  // @77_5ce0b0
  X1[3] = 0;  // @78_5ce0b0
  L5ce193:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @80_5ce0b0
  __builtin_memcpy((void *)((u32)(esi + 2869) + 0), &X1[0], 4);  // @81_5ce0b0
  if (FL[0] == FL[1]) goto L5ce1c3;  // @82_5ce0b0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; }));  // @83_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce1b9;  // @84_5ce0b0
  { u32 v = (u32)((u32)(1050253722)); __builtin_memcpy((void *)(u32)(esi + 2869), &v, sizeof v); }  // @85_5ce0b0
  goto L5ce1c3;  // @86_5ce0b0
  L5ce1b9:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2869), &v, sizeof v); }  // @88_5ce0b0
  L5ce1c3:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2841), &v, sizeof v); }  // @90_5ce0b0
  ecx = edi;  // @91_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @92_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1232), sizeof v); (u32)v; });  // @93_5ce0b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @94_5ce0b0
  ecx = edx = 0;  // @95_5ce0b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @96_5ce0b0
  if (FL[2] != 0) goto L5ce1ff;  // @97_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @98_5ce0b0
  ecx = edi;  // @99_5ce0b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1008)))(ecx);  // @100_5ce0b0
  ecx = edx = 0;  // @101_5ce0b0
  FL[0] = eax; FL[1] = (u32)(17);  // @102_5ce0b0
  if (FL[0] == FL[1]) goto L5ce1ff;  // @103_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @104_5ce0b0
  if (FL[0] != FL[1]) goto L5ce1ff;  // @105_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2382), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @106_5ce0b0
  if (FL[0] != FL[1]) goto L5ce1ff;  // @107_5ce0b0
  ecx = (ecx & 0xffffff00u) | ((0) & 0xff);  // @108_5ce0b0
  FL[3] = (ecx & 0xff);  // @109_5ce0b0
  goto L5ce201;  // @110_5ce0b0
  L5ce1ff:;
  ecx = (ecx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @112_5ce0b0
  L5ce201:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1536), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @114_5ce0b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)((EBP - 232) + 15), &v, sizeof v); }  // @115_5ce0b0
  if (FL[0] == FL[1]) goto L5ceb19;  // @116_5ce0b0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(512));  // @117_5ce0b0
  if (FL[2] != 0) goto L5ceb19;  // @118_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1647), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @119_5ce0b0
  if (FL[0] == FL[1]) goto L5ce249;  // @120_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2869), &v, sizeof v); }  // @121_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @122_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @123_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @124_5ce0b0
  L5ce249:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @126_5ce0b0
  X0[1] = 0;  // @127_5ce0b0
  X0[2] = 0;  // @128_5ce0b0
  X0[3] = 0;  // @129_5ce0b0
  X1[0] = 0;  // @130_5ce0b0
  X1[1] = 0;  // @131_5ce0b0
  X1[2] = 0;  // @132_5ce0b0
  X1[3] = 0;  // @133_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @134_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce2fd;  // @135_5ce0b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2841), &v, sizeof v); }  // @136_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2059) + 0), 4); v; });  // @137_5ce0b0
  X0[1] = 0;  // @138_5ce0b0
  X0[2] = 0;  // @139_5ce0b0
  X0[3] = 0;  // @140_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @141_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @142_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @143_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce292;  // @144_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @146_5ce0b0
  X0[0] = F2U((float)(s32)X0[0]);  // @147_5ce0b0
  X0[1] = F2U((float)(s32)X0[1]);  // @148_5ce0b0
  X0[2] = F2U((float)(s32)X0[2]);  // @149_5ce0b0
  X0[3] = F2U((float)(s32)X0[3]);  // @150_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @151_5ce0b0
  __builtin_memcpy((void *)((u32)(edi + 2059) + 0), &X0[0], 4);  // @152_5ce0b0
  L5ce292:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @154_5ce0b0
  X0[1] = 0;  // @155_5ce0b0
  X0[2] = 0;  // @156_5ce0b0
  X0[3] = 0;  // @157_5ce0b0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; }));  // @158_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce2bb;  // @159_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @160_5ce0b0
  FL[2] = (eax & (u32)(67108864));  // @161_5ce0b0
  if (FL[2] != 0) goto L5ce2bb;  // @162_5ce0b0
  eax = (eax | (u32)(2));  // @163_5ce0b0
  FL[3] = eax;  // @164_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @165_5ce0b0
  goto L5ce2c2;  // @166_5ce0b0
  L5ce2bb:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @168_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @169_5ce0b0
  L5ce2c2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @171_5ce0b0
  X0[1] = 0;  // @172_5ce0b0
  X0[2] = 0;  // @173_5ce0b0
  X0[3] = 0;  // @174_5ce0b0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }));  // @175_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce2de;  // @176_5ce0b0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @177_5ce0b0
  if (FL[2] == 0) goto L5ce2de;  // @178_5ce0b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @179_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @180_5ce0b0
  L5ce2de:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @182_5ce0b0
  FL[2] = (eax & (u32)(4194304));  // @183_5ce0b0
  if (FL[2] == 0) goto L5ce2fd;  // @184_5ce0b0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }));  // @185_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce2fd;  // @186_5ce0b0
  eax = (eax | (u32)(4));  // @187_5ce0b0
  FL[3] = eax;  // @188_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @189_5ce0b0
  L5ce2fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @191_5ce0b0
  ecx = (u32)((EBP - 232) + 72);  // @192_5ce0b0
  PV[0] = (u32)(ecx);  // @193_5ce0b0
  ecx = (u32)((EBP - 236) + 100);  // @194_5ce0b0
  PV[1] = (u32)(ecx);  // @195_5ce0b0
  ecx = edi;  // @196_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[1], PV[0]);  // @197_5ce0b0
  ecx = edx = 0;  // @198_5ce0b0
  ecx = (u32)((EBP - 232) + 96);  // @199_5ce0b0
  eax = ext_4e09b0_thiscall1(ecx);  // @200_5ce0b0
    // @201_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @202_5ce0b0
  ecx = (u32)((EBP - 232) + 180);  // @203_5ce0b0
  PV[2] = (u32)(ecx);  // @204_5ce0b0
  ecx = (u32)((EBP - 236) + 136);  // @205_5ce0b0
  PV[3] = (u32)(ecx);  // @206_5ce0b0
  ecx = esi;  // @207_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[3], PV[2]);  // @208_5ce0b0
  ecx = edx = 0;  // @209_5ce0b0
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 2833), &v, sizeof v); }  // @210_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @211_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 48), &v, sizeof v); }  // @212_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 52), &v, sizeof v); }  // @213_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 56), &v, sizeof v); }  // @214_5ce0b0
  FL[2] = (eax & (u32)(268435456));  // @215_5ce0b0
  if (FL[2] == 0) goto L5ce6c0;  // @216_5ce0b0
  FL[2] = ((eax & 0xff) & (u32)(2));  // @217_5ce0b0
  if (FL[2] == 0) goto L5ce377;  // @218_5ce0b0
  eax = (eax & (u32)(4294967293));  // @219_5ce0b0
  FL[3] = eax;  // @220_5ce0b0
  eax = (eax | (u32)(1));  // @221_5ce0b0
  FL[3] = eax;  // @222_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @223_5ce0b0
  L5ce377:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @225_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @226_5ce0b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @227_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @228_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @229_5ce0b0
  ecx = edx = 0;  // @230_5ce0b0
  ecx = eax;  // @231_5ce0b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @232_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 256)))(ecx, (u32)(6970608));  // @233_5ce0b0
  ecx = edx = 0;  // @234_5ce0b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 232) + 16), &v, sizeof v); }  // @235_5ce0b0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)((EBP - 232) + 20), &v, sizeof v); }  // @236_5ce0b0
  FL[2] = (eax & eax);  // @237_5ce0b0
  if (FL[2] == 0) goto L5ce513;  // @238_5ce0b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @239_5ce0b0
  ecx = (u32)((EBP - 232) + 20);  // @240_5ce0b0
  PV[4] = (u32)(ecx);  // @241_5ce0b0
  PV[5] = (u32)(ecx);  // @242_5ce0b0
  ecx = (u32)((EBP - 244) + 84);  // @243_5ce0b0
  PV[6] = (u32)(ecx);  // @244_5ce0b0
  ecx = eax;  // @245_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[6], (u32)(1140457472), PV[4], (u32)(-1));  // @246_5ce0b0
  ecx = edx = 0;  // @247_5ce0b0
  ebx = eax;  // @248_5ce0b0
  FL[2] = (ebx & ebx);  // @249_5ce0b0
  if (FL[2] == 0) goto L5ce50d;  // @250_5ce0b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 16), sizeof v); (u32)v; });  // @251_5ce0b0
  L5ce3e6:;
  FL[0] = ebx; FL[1] = edi;  // @253_5ce0b0
  if (FL[0] == FL[1]) goto L5ce4db;  // @254_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @255_5ce0b0
  ecx = ebx;  // @256_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @257_5ce0b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @258_5ce0b0
  ecx = edx = 0;  // @259_5ce0b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @260_5ce0b0
  if (FL[2] != 0) goto L5ce4db;  // @261_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @262_5ce0b0
  ecx = (u32)((EBP - 232) + 60);  // @263_5ce0b0
  PV[7] = (u32)(ecx);  // @264_5ce0b0
  ecx = ebx;  // @265_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 236) + 64), &v, sizeof v); }  // @266_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 236) + 68), &v, sizeof v); }  // @267_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 236) + 72), &v, sizeof v); }  // @268_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[7]);  // @269_5ce0b0
  ecx = edx = 0;  // @270_5ce0b0
  edx = (u32)((EBP - 232) + 60);  // @271_5ce0b0
  ecx = (u32)((EBP - 232) + 72);  // @272_5ce0b0
  FS[0] = ext_4e0830_fastcall2_ld(ecx, edx);  // @273_5ce0b0
  ecx = edx = 0;  // @274_5ce0b0
  STF((u32)((EBP - 232) + 16), FS[0]);  // @275_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; });  // @276_5ce0b0
  X0[1] = 0;  // @277_5ce0b0
  X0[2] = 0;  // @278_5ce0b0
  X0[3] = 0;  // @279_5ce0b0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7032776) + 0), 4); v; }));  // @280_5ce0b0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5ce4db;  // @281_5ce0b0
  eax = (u32)((EBP - 232) + 72);  // @282_5ce0b0
  PV[8] = (u32)(eax);  // @283_5ce0b0
  edx = (u32)((EBP - 236) + 64);  // @284_5ce0b0
  ecx = (u32)((EBP - 236) + 28);  // @285_5ce0b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @286_5ce0b0
  ecx = edx = 0;  // @287_5ce0b0
  ecx = (u32)((EBP - 232) + 24);  // @288_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @289_5ce0b0
  ecx = 0;  // @290_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 100) + 0), 4); v; });  // @291_5ce0b0
  X0[1] = 0;  // @292_5ce0b0
  X0[2] = 0;  // @293_5ce0b0
  X0[3] = 0;  // @294_5ce0b0
  eax = (u32)((EBP - 232) + 96);  // @295_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 96) + 0), 4); v; });  // @296_5ce0b0
  X1[1] = 0;  // @297_5ce0b0
  X1[2] = 0;  // @298_5ce0b0
  X1[3] = 0;  // @299_5ce0b0
  edx = (u32)((EBP - 232) + 24);  // @300_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 28) + 0), 4); v; })));  // @301_5ce0b0
  ecx = (u32)((EBP - 232) + 84);  // @302_5ce0b0
  PV[9] = (u32)(eax);  // @303_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 236) + 28) + 0), 4); v; })));  // @304_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @305_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @306_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 236) + 108) + 0), 4); v; });  // @307_5ce0b0
  X0[1] = 0;  // @308_5ce0b0
  X0[2] = 0;  // @309_5ce0b0
  X0[3] = 0;  // @310_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 236) + 36) + 0), 4); v; })));  // @311_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @312_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 236) + 20) + 0), &X1[0], 4);  // @313_5ce0b0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[9]);  // @314_5ce0b0
  ecx = edx = 0;  // @315_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; });  // @316_5ce0b0
  X1[1] = 0;  // @317_5ce0b0
  X1[2] = 0;  // @318_5ce0b0
  X1[3] = 0;  // @319_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @320_5ce0b0
  X0[1] = 0;  // @321_5ce0b0
  X0[2] = 0;  // @322_5ce0b0
  X0[3] = 0;  // @323_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @324_5ce0b0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5ce4db;  // @325_5ce0b0
  X0[0] = 0;  // @326_5ce0b0
  X0[1] = 0;  // @327_5ce0b0
  X0[2] = 0;  // @328_5ce0b0
  X0[3] = 0;  // @329_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @330_5ce0b0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5ce4db;  // @331_5ce0b0
  eax = (u32)((EBP - 232) + 72);  // @332_5ce0b0
  PV[10] = (u32)(eax);  // @333_5ce0b0
  edx = (u32)((EBP - 236) + 64);  // @334_5ce0b0
  ecx = (u32)((EBP - 236) + 52);  // @335_5ce0b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[10]);  // @336_5ce0b0
  ecx = edx = 0;  // @337_5ce0b0
  L5ce4db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @339_5ce0b0
  ecx = (u32)((EBP - 232) + 20);  // @340_5ce0b0
  PV[11] = (u32)(ecx);  // @341_5ce0b0
  PV[12] = (u32)(ecx);  // @342_5ce0b0
  ecx = (u32)((EBP - 244) + 84);  // @343_5ce0b0
  PV[13] = (u32)(ecx);  // @344_5ce0b0
  ecx = esi;  // @345_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[13], (u32)(1140457472), PV[11], (u32)(-1));  // @346_5ce0b0
  ecx = edx = 0;  // @347_5ce0b0
  ebx = eax;  // @348_5ce0b0
  FL[2] = (ebx & ebx);  // @349_5ce0b0
  if (FL[2] != 0) goto L5ce3e6;  // @350_5ce0b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 36), sizeof v); (u32)v; });  // @351_5ce0b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 40), sizeof v); (u32)v; });  // @352_5ce0b0
  goto L5ce513;  // @353_5ce0b0
  L5ce50d:;
  ebx = (u32)(esi + 2873);  // @355_5ce0b0
  L5ce513:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @357_5ce0b0
  X0[1] = 0;  // @358_5ce0b0
  X0[2] = 0;  // @359_5ce0b0
  X0[3] = 0;  // @360_5ce0b0
  X1[0] = 0;  // @361_5ce0b0
  X1[1] = 0;  // @362_5ce0b0
  X1[2] = 0;  // @363_5ce0b0
  X1[3] = 0;  // @364_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @365_5ce0b0
  X3[1] = 0;  // @366_5ce0b0
  X3[2] = 0;  // @367_5ce0b0
  X3[3] = 0;  // @368_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @369_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @370_5ce0b0
  X0[1] = 0;  // @371_5ce0b0
  X0[2] = 0;  // @372_5ce0b0
  X0[3] = 0;  // @373_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @374_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @375_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce543;  // @376_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @377_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @378_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @379_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce543;  // @380_5ce0b0
  FA = U2F(X3[0]); FB = U2F(X1[0]);  // @381_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @382_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @383_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce586;  // @384_5ce0b0
  L5ce543:;
  X1[0] = X0[0];  // @386_5ce0b0
  X1[1] = X0[1];  // @387_5ce0b0
  X1[2] = X0[2];  // @388_5ce0b0
  X1[3] = X0[3];  // @389_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @390_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @391_5ce0b0
  X0[1] = 0;  // @392_5ce0b0
  X0[2] = 0;  // @393_5ce0b0
  X0[3] = 0;  // @394_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @395_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @396_5ce0b0
  X0[0] = X3[0];  // @397_5ce0b0
  X0[1] = X3[1];  // @398_5ce0b0
  X0[2] = X3[2];  // @399_5ce0b0
  X0[3] = X3[3];  // @400_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @401_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @402_5ce0b0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @403_5ce0b0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @404_5ce0b0
  ecx = edx = 0;  // @405_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @406_5ce0b0
  X3[1] = 0;  // @407_5ce0b0
  X3[2] = 0;  // @408_5ce0b0
  X3[3] = 0;  // @409_5ce0b0
  X1[0] = 0;  // @410_5ce0b0
  X1[1] = 0;  // @411_5ce0b0
  X1[2] = 0;  // @412_5ce0b0
  X1[3] = 0;  // @413_5ce0b0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @414_5ce0b0
  __builtin_memcpy((void *)((u32)(esi + 2833) + 0), &X0[0], 4);  // @415_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @416_5ce0b0
  X0[1] = 0;  // @417_5ce0b0
  X0[2] = 0;  // @418_5ce0b0
  X0[3] = 0;  // @419_5ce0b0
  L5ce586:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @421_5ce0b0
  X2[1] = 0;  // @422_5ce0b0
  X2[2] = 0;  // @423_5ce0b0
  X2[3] = 0;  // @424_5ce0b0
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @425_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @426_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @427_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce5ab;  // @428_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @429_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @430_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @431_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce5ab;  // @432_5ce0b0
  FA = U2F(X3[0]); FB = U2F(X1[0]);  // @433_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @434_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @435_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce691;  // @436_5ce0b0
  L5ce5ab:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @438_5ce0b0
  X0[1] = 0;  // @439_5ce0b0
  X0[2] = 0;  // @440_5ce0b0
  X0[3] = 0;  // @441_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @442_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @443_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @444_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce68b;  // @445_5ce0b0
  eax = (u32)((EBP - 232) + 132);  // @446_5ce0b0
  edx = ebx;  // @447_5ce0b0
  PV[14] = (u32)(eax);  // @448_5ce0b0
  ecx = (u32)((EBP - 236) + 64);  // @449_5ce0b0
  eax = ext_441970_fastcall3(ecx, edx, PV[14]);  // @450_5ce0b0
  ecx = edx = 0;  // @451_5ce0b0
  ecx = (u32)((EBP - 232) + 60);  // @452_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 64), &v, sizeof v); }  // @453_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @454_5ce0b0
  ecx = 0;  // @455_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @456_5ce0b0
  ecx = (u32)((EBP - 232) + 48);  // @457_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @458_5ce0b0
  ecx = 0;  // @459_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 60) + 0), 4); v; });  // @460_5ce0b0
  X0[1] = 0;  // @461_5ce0b0
  X0[2] = 0;  // @462_5ce0b0
  X0[3] = 0;  // @463_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @464_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 64) + 0), 4); v; });  // @465_5ce0b0
  X1[1] = 0;  // @466_5ce0b0
  X1[2] = 0;  // @467_5ce0b0
  X1[3] = 0;  // @468_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; })));  // @469_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; })));  // @470_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @471_5ce0b0
  X3[1] = 0;  // @472_5ce0b0
  X3[2] = 0;  // @473_5ce0b0
  X3[3] = 0;  // @474_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @475_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 68) + 0), 4); v; });  // @476_5ce0b0
  X0[1] = 0;  // @477_5ce0b0
  X0[2] = 0;  // @478_5ce0b0
  X0[3] = 0;  // @479_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @480_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @481_5ce0b0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000568) + 0), 4); v; }));  // @482_5ce0b0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5ce67a;  // @483_5ce0b0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000624) + 0), 4); v; }));  // @484_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce673;  // @485_5ce0b0
  eax = (u32)((EBP - 232) + 48);  // @486_5ce0b0
  PV[15] = (u32)(eax);  // @487_5ce0b0
  edx = (u32)((EBP - 236) + 64);  // @488_5ce0b0
  ecx = (u32)((EBP - 236) + 88);  // @489_5ce0b0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[15]);  // @490_5ce0b0
  ecx = edx = 0;  // @491_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @492_5ce0b0
  X0[1] = 0;  // @493_5ce0b0
  X0[2] = 0;  // @494_5ce0b0
  X0[3] = 0;  // @495_5ce0b0
  X1[0] = 0;  // @496_5ce0b0
  X1[1] = 0;  // @497_5ce0b0
  X1[2] = 0;  // @498_5ce0b0
  X1[3] = 0;  // @499_5ce0b0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 88) + 0), 4); v; }));  // @500_5ce0b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @501_5ce0b0
  X2[1] = 0;  // @502_5ce0b0
  X2[2] = 0;  // @503_5ce0b0
  X2[3] = 0;  // @504_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @505_5ce0b0
  X3[1] = 0;  // @506_5ce0b0
  X3[2] = 0;  // @507_5ce0b0
  X3[3] = 0;  // @508_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce66a;  // @509_5ce0b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(16))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @510_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @511_5ce0b0
  goto L5ce697;  // @512_5ce0b0
  L5ce66a:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @514_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @515_5ce0b0
  goto L5ce697;  // @516_5ce0b0
  L5ce673:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @518_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @519_5ce0b0
  L5ce67a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @521_5ce0b0
  X0[1] = 0;  // @522_5ce0b0
  X0[2] = 0;  // @523_5ce0b0
  X0[3] = 0;  // @524_5ce0b0
  X1[0] = 0;  // @525_5ce0b0
  X1[1] = 0;  // @526_5ce0b0
  X1[2] = 0;  // @527_5ce0b0
  X1[3] = 0;  // @528_5ce0b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; });  // @529_5ce0b0
  X2[1] = 0;  // @530_5ce0b0
  X2[2] = 0;  // @531_5ce0b0
  X2[3] = 0;  // @532_5ce0b0
  goto L5ce697;  // @533_5ce0b0
  L5ce68b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; });  // @535_5ce0b0
  X0[1] = 0;  // @536_5ce0b0
  X0[2] = 0;  // @537_5ce0b0
  X0[3] = 0;  // @538_5ce0b0
  L5ce691:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; });  // @540_5ce0b0
  X3[1] = 0;  // @541_5ce0b0
  X3[2] = 0;  // @542_5ce0b0
  X3[3] = 0;  // @543_5ce0b0
  L5ce697:;
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @545_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @546_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @547_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce7f9;  // @548_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @549_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @550_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @551_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce7f9;  // @552_5ce0b0
  FA = U2F(X3[0]); FB = U2F(X1[0]);  // @553_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @554_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @555_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce7f9;  // @556_5ce0b0
  goto L5ce6c3;  // @557_5ce0b0
  L5ce6c0:;
  X1[0] = 0;  // @559_5ce0b0
  X1[1] = 0;  // @560_5ce0b0
  X1[2] = 0;  // @561_5ce0b0
  X1[3] = 0;  // @562_5ce0b0
  L5ce6c3:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @564_5ce0b0
  X0[1] = 0;  // @565_5ce0b0
  X0[2] = 0;  // @566_5ce0b0
  X0[3] = 0;  // @567_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @568_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @569_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @570_5ce0b0
  if (__builtin_parity(FL[2] & 0xff)) goto L5ce73b;  // @571_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @572_5ce0b0
  if (FL[0] == FL[1]) goto L5ce6fa;  // @573_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 132) + 0), 4); v; });  // @574_5ce0b0
  X0[1] = 0;  // @575_5ce0b0
  X0[2] = 0;  // @576_5ce0b0
  X0[3] = 0;  // @577_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 48) + 0), &X0[0], 4);  // @578_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 140) + 0), 4); v; });  // @579_5ce0b0
  X0[1] = 0;  // @580_5ce0b0
  X0[2] = 0;  // @581_5ce0b0
  X0[3] = 0;  // @582_5ce0b0
  goto L5ce7f3;  // @583_5ce0b0
  L5ce6fa:;
  eax = (u32)((EBP - 232) + 132);  // @585_5ce0b0
  edx = ebx;  // @586_5ce0b0
  PV[16] = (u32)(eax);  // @587_5ce0b0
  ecx = (u32)((EBP - 236) + 52);  // @588_5ce0b0
  eax = ext_441970_fastcall3(ecx, edx, PV[16]);  // @589_5ce0b0
  ecx = edx = 0;  // @590_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @591_5ce0b0
  X0[1] = 0;  // @592_5ce0b0
  X0[2] = 0;  // @593_5ce0b0
  X0[3] = 0;  // @594_5ce0b0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2881) + 0), 4); v; }));  // @595_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce7f9;  // @596_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @597_5ce0b0
  if (FL[0] == FL[1]) goto L5ce7f9;  // @598_5ce0b0
  ecx = (u32)((EBP - 232) + 48);  // @599_5ce0b0
  eax = ext_4e09b0_thiscall1(ecx);  // @600_5ce0b0
    // @601_5ce0b0
  goto L5ce7f9;  // @602_5ce0b0
  L5ce73b:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @604_5ce0b0
  if (FL[0] == FL[1]) goto L5ce7e1;  // @605_5ce0b0
  eax = (u32)((EBP - 232) + 60);  // @606_5ce0b0
  ecx = esi;  // @607_5ce0b0
  PV[17] = (u32)(eax);  // @608_5ce0b0
  eax = ext_5cf690_thiscall2(ecx, PV[17]);  // @609_5ce0b0
  ecx = edx = 0;  // @610_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 72) + 0), 4); v; });  // @611_5ce0b0
  X0[1] = 0;  // @612_5ce0b0
  X0[2] = 0;  // @613_5ce0b0
  X0[3] = 0;  // @614_5ce0b0
  eax = (u32)((EBP - 232) + 24);  // @615_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 24) + 0), &X0[0], 4);  // @616_5ce0b0
  edx = (u32)((EBP - 232) + 60);  // @617_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 80) + 0), 4); v; });  // @618_5ce0b0
  X0[1] = 0;  // @619_5ce0b0
  X0[2] = 0;  // @620_5ce0b0
  X0[3] = 0;  // @621_5ce0b0
  ecx = (u32)((EBP - 232) + 48);  // @622_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 32) + 0), &X0[0], 4);  // @623_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 76) + 0), 4); v; });  // @624_5ce0b0
  X0[1] = 0;  // @625_5ce0b0
  X0[2] = 0;  // @626_5ce0b0
  X0[3] = 0;  // @627_5ce0b0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806056) + 0), 4); v; })));  // @628_5ce0b0
  PV[18] = (u32)(eax);  // @629_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 236) + 32) + 0), &X0[0], 4);  // @630_5ce0b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[18]);  // @631_5ce0b0
  ecx = edx = 0;  // @632_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 132) + 0), 4); v; });  // @633_5ce0b0
  X0[1] = 0;  // @634_5ce0b0
  X0[2] = 0;  // @635_5ce0b0
  X0[3] = 0;  // @636_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; })));  // @637_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 136) + 0), 4); v; });  // @638_5ce0b0
  X1[1] = 0;  // @639_5ce0b0
  X1[2] = 0;  // @640_5ce0b0
  X1[3] = 0;  // @641_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; })));  // @642_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @643_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 140) + 0), 4); v; });  // @644_5ce0b0
  X0[1] = 0;  // @645_5ce0b0
  X0[2] = 0;  // @646_5ce0b0
  X0[3] = 0;  // @647_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; })));  // @648_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @649_5ce0b0
  X0[0] = 0;  // @650_5ce0b0
  X0[1] = 0;  // @651_5ce0b0
  X0[2] = 0;  // @652_5ce0b0
  X0[3] = 0;  // @653_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @654_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce7f9;  // @655_5ce0b0
  eax = (u32)((EBP - 232) + 72);  // @656_5ce0b0
  PV[19] = (u32)(eax);  // @657_5ce0b0
  edx = (u32)((EBP - 236) + 64);  // @658_5ce0b0
  ecx = (u32)((EBP - 236) + 52);  // @659_5ce0b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[19]);  // @660_5ce0b0
  ecx = edx = 0;  // @661_5ce0b0
  goto L5ce7f9;  // @662_5ce0b0
  L5ce7e1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 96) + 0), 4); v; });  // @664_5ce0b0
  X0[1] = 0;  // @665_5ce0b0
  X0[2] = 0;  // @666_5ce0b0
  X0[3] = 0;  // @667_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 48) + 0), &X0[0], 4);  // @668_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 104) + 0), 4); v; });  // @669_5ce0b0
  X0[1] = 0;  // @670_5ce0b0
  X0[2] = 0;  // @671_5ce0b0
  X0[3] = 0;  // @672_5ce0b0
  L5ce7f3:;
  __builtin_memcpy((void *)((u32)((EBP - 232) + 56) + 0), &X0[0], 4);  // @674_5ce0b0
  L5ce7f9:;
  ecx = (u32)((EBP - 232) + 48);  // @676_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 52), &v, sizeof v); }  // @677_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @678_5ce0b0
  ecx = 0;  // @679_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @680_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @681_5ce0b0
  eax = (eax ^ ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 44), sizeof v); (u32)v; }));  // @682_5ce0b0
  FL[3] = eax;  // @683_5ce0b0
  FL[2] = ((eax & 0xff) & (u32)(3));  // @684_5ce0b0
  if (FL[2] == 0) goto L5ce824;  // @685_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2089), &v, sizeof v); }  // @686_5ce0b0
  L5ce824:;
  edx = (u32)((EBP - 232) + 132);  // @688_5ce0b0
  ecx = ebx;  // @689_5ce0b0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @690_5ce0b0
  ecx = edx = 0;  // @691_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2877), &v, sizeof v); }  // @692_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @693_5ce0b0
  X0[1] = 0;  // @694_5ce0b0
  X0[2] = 0;  // @695_5ce0b0
  X0[3] = 0;  // @696_5ce0b0
  PV[20] = (u32)(ecx);  // @697_5ce0b0
  ecx = ebx;  // @698_5ce0b0
  PV[21] = X0[0];  // @699_5ce0b0
  eax = ext_4e0d80_thiscall2(ecx, PV[21]);  // @700_5ce0b0
  ecx = edx = 0;  // @701_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @702_5ce0b0
  ecx = edi;  // @703_5ce0b0
  PV[22] = (u32)(ebx);  // @704_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1472)))(ecx, PV[22]);  // @705_5ce0b0
  ecx = edx = 0;  // @706_5ce0b0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(4194304));  // @707_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 96) + 0), 4); v; });  // @708_5ce0b0
  X0[1] = 0;  // @709_5ce0b0
  X0[2] = 0;  // @710_5ce0b0
  X0[3] = 0;  // @711_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 100) + 0), 4); v; });  // @712_5ce0b0
  X1[1] = 0;  // @713_5ce0b0
  X1[2] = 0;  // @714_5ce0b0
  X1[3] = 0;  // @715_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 48) + 0), 4); v; })));  // @716_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 52) + 0), 4); v; })));  // @717_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @718_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 104) + 0), 4); v; });  // @719_5ce0b0
  X0[1] = 0;  // @720_5ce0b0
  X0[2] = 0;  // @721_5ce0b0
  X0[3] = 0;  // @722_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 56) + 0), 4); v; })));  // @723_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @724_5ce0b0
  if (FL[2] != 0) goto L5ce9e1;  // @725_5ce0b0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @726_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce8a6;  // @727_5ce0b0
  X0[0] = 0;  // @728_5ce0b0
  X0[1] = 0;  // @729_5ce0b0
  X0[2] = 0;  // @730_5ce0b0
  X0[3] = 0;  // @731_5ce0b0
  goto L5ce8c9;  // @732_5ce0b0
  L5ce8a6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @734_5ce0b0
  X0[1] = 0;  // @735_5ce0b0
  X0[2] = 0;  // @736_5ce0b0
  X0[3] = 0;  // @737_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @738_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce8bd;  // @739_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @740_5ce0b0
  X0[1] = 0;  // @741_5ce0b0
  X0[2] = 0;  // @742_5ce0b0
  X0[3] = 0;  // @743_5ce0b0
  goto L5ce8c9;  // @744_5ce0b0
  L5ce8bd:;
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @746_5ce0b0
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @747_5ce0b0
  ecx = edx = 0;  // @748_5ce0b0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @749_5ce0b0
  L5ce8c9:;
  eax = (u32)((EBP - 232) + 48);  // @751_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 16) + 0), &X0[0], 4);  // @752_5ce0b0
  PV[23] = (u32)(eax);  // @753_5ce0b0
  edx = (u32)((EBP - 236) + 100);  // @754_5ce0b0
  ecx = (u32)((EBP - 236) + 88);  // @755_5ce0b0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[23]);  // @756_5ce0b0
  ecx = edx = 0;  // @757_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 88) + 0), 4); v; });  // @758_5ce0b0
  X0[1] = 0;  // @759_5ce0b0
  X0[2] = 0;  // @760_5ce0b0
  X0[3] = 0;  // @761_5ce0b0
  X1[0] = 0;  // @762_5ce0b0
  X1[1] = 0;  // @763_5ce0b0
  X1[2] = 0;  // @764_5ce0b0
  X1[3] = 0;  // @765_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @766_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce8f8;  // @767_5ce0b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(64))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @768_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @769_5ce0b0
  goto L5ce8ff;  // @770_5ce0b0
  L5ce8f8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @772_5ce0b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @773_5ce0b0
  L5ce8ff:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @775_5ce0b0
  ebx = (ebx >> (u32)(27));  // @776_5ce0b0
  FL[3] = ebx;  // @777_5ce0b0
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(1))) & 0xff);  // @778_5ce0b0
  FL[3] = (ebx & 0xff);  // @779_5ce0b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @780_5ce0b0
  if (FL[0] == FL[1]) goto L5ce939;  // @781_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2869) + 0), 4); v; });  // @782_5ce0b0
  X0[1] = 0;  // @783_5ce0b0
  X0[2] = 0;  // @784_5ce0b0
  X0[3] = 0;  // @785_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @786_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @787_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @788_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce939;  // @789_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; });  // @790_5ce0b0
  X0[1] = 0;  // @791_5ce0b0
  X0[2] = 0;  // @792_5ce0b0
  X0[3] = 0;  // @793_5ce0b0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; }));  // @794_5ce0b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 232) + 20), &v, sizeof v); }  // @795_5ce0b0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5ce93e;  // @796_5ce0b0
  L5ce939:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 20), &v, sizeof v); }  // @798_5ce0b0
  L5ce93e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @800_5ce0b0
  ecx = edi;  // @801_5ce0b0
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 20), sizeof v); (u32)v; });  // @802_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1608)))(ecx, PV[24]);  // @803_5ce0b0
  ecx = edx = 0;  // @804_5ce0b0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @805_5ce0b0
  if (FL[2] == 0) goto L5ce95a;  // @806_5ce0b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6945228) + 0), 4); v; });  // @807_5ce0b0
  X2[1] = 0;  // @808_5ce0b0
  X2[2] = 0;  // @809_5ce0b0
  X2[3] = 0;  // @810_5ce0b0
  goto L5ce962;  // @811_5ce0b0
  L5ce95a:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; });  // @813_5ce0b0
  X2[1] = 0;  // @814_5ce0b0
  X2[2] = 0;  // @815_5ce0b0
  X2[3] = 0;  // @816_5ce0b0
  L5ce962:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 232) + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @818_5ce0b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @819_5ce0b0
  X3[1] = 0;  // @820_5ce0b0
  X3[2] = 0;  // @821_5ce0b0
  X3[3] = 0;  // @822_5ce0b0
  if (FL[0] == FL[1]) goto L5ce974;  // @823_5ce0b0
  X2[0] = X3[0];  // @824_5ce0b0
  X2[1] = X3[1];  // @825_5ce0b0
  X2[2] = X3[2];  // @826_5ce0b0
  X2[3] = X3[3];  // @827_5ce0b0
  L5ce974:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @829_5ce0b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @830_5ce0b0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }));  // @831_5ce0b0
  FL[3] = ecx;  // @832_5ce0b0
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @833_5ce0b0
  X1[0] = F2U((float)(s32)X1[0]);  // @834_5ce0b0
  X1[1] = F2U((float)(s32)X1[1]);  // @835_5ce0b0
  X1[2] = F2U((float)(s32)X1[2]);  // @836_5ce0b0
  X1[3] = F2U((float)(s32)X1[3]);  // @837_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @838_5ce0b0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @839_5ce0b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @840_5ce0b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @841_5ce0b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce9a3;  // @842_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; });  // @843_5ce0b0
  X1[1] = 0;  // @844_5ce0b0
  X1[2] = 0;  // @845_5ce0b0
  X1[3] = 0;  // @846_5ce0b0
  L5ce9a3:;
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @848_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; });  // @849_5ce0b0
  X0[1] = 0;  // @850_5ce0b0
  X0[2] = 0;  // @851_5ce0b0
  X0[3] = 0;  // @852_5ce0b0
  X2[0] = F2U(U2F(X2[0]) * U2F(X1[0]));  // @853_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @854_5ce0b0
  { float a_ = U2F(X3[0]), b_ = U2F(X2[0]); X3[0] = (a_ < b_) ? X3[0] : F2U(b_); }  // @855_5ce0b0
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 16) + 0), 4); v; })));  // @856_5ce0b0
  X3[0] = F2U(U2F(X3[0]) / U2F(X1[0]));  // @857_5ce0b0
  FA = U2F(X0[0]); FB = U2F(X3[0]);  // @858_5ce0b0
  __builtin_memcpy((void *)((u32)(edi + 2063) + 0), &X3[0], 4);  // @859_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ce9e1;  // @860_5ce0b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2382), &v, sizeof v); }  // @861_5ce0b0
  L5ce9e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @863_5ce0b0
  ecx = edi;  // @864_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1232), sizeof v); (u32)v; });  // @865_5ce0b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @866_5ce0b0
  ecx = edx = 0;  // @867_5ce0b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @868_5ce0b0
  if (FL[2] != 0) goto L5ceb19;  // @869_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @870_5ce0b0
  ecx = edi;  // @871_5ce0b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1488)))(ecx);  // @872_5ce0b0
  ecx = edx = 0;  // @873_5ce0b0
  FL[0] = eax; FL[1] = (u32)(16);  // @874_5ce0b0
  if (FL[0] == FL[1]) goto L5ceb19;  // @875_5ce0b0
  FL[0] = eax; FL[1] = (u32)(17);  // @876_5ce0b0
  if (FL[0] == FL[1]) goto L5ceb19;  // @877_5ce0b0
  FL[0] = eax; FL[1] = (u32)(15);  // @878_5ce0b0
  if (FL[0] == FL[1]) goto L5ceb19;  // @879_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 132) + 0), 4); v; });  // @880_5ce0b0
  X0[1] = 0;  // @881_5ce0b0
  X0[2] = 0;  // @882_5ce0b0
  X0[3] = 0;  // @883_5ce0b0
  ecx = (u32)((EBP - 232) + 60);  // @884_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 60) + 0), &X0[0], 4);  // @885_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 140) + 0), 4); v; });  // @886_5ce0b0
  X0[1] = 0;  // @887_5ce0b0
  X0[2] = 0;  // @888_5ce0b0
  X0[3] = 0;  // @889_5ce0b0
  __builtin_memcpy((void *)((u32)((EBP - 232) + 68) + 0), &X0[0], 4);  // @890_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 232) + 64), &v, sizeof v); }  // @891_5ce0b0
  eax = ext_44c840_thiscall1(ecx);  // @892_5ce0b0
  ecx = 0;  // @893_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 64) + 0), 4); v; });  // @894_5ce0b0
  X0[1] = 0;  // @895_5ce0b0
  X0[2] = 0;  // @896_5ce0b0
  X0[3] = 0;  // @897_5ce0b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @898_5ce0b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 60) + 0), 4); v; });  // @899_5ce0b0
  X1[1] = 0;  // @900_5ce0b0
  X1[2] = 0;  // @901_5ce0b0
  X1[3] = 0;  // @902_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 100) + 0), 4); v; })));  // @903_5ce0b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 96) + 0), 4); v; })));  // @904_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @905_5ce0b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 68) + 0), 4); v; });  // @906_5ce0b0
  X0[1] = 0;  // @907_5ce0b0
  X0[2] = 0;  // @908_5ce0b0
  X0[3] = 0;  // @909_5ce0b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 232) + 104) + 0), 4); v; })));  // @910_5ce0b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @911_5ce0b0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000624) + 0), 4); v; }));  // @912_5ce0b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5ceb19;  // @913_5ce0b0
  PV[25] = (u32)(ecx);  // @914_5ce0b0
  eax = (u32)((EBP - 236) + 136);  // @915_5ce0b0
  PV[26] = (u32)(eax);  // @916_5ce0b0
  edx = (u32)((EBP - 240) + 104);  // @917_5ce0b0
  ecx = (u32)((EBP - 240) + 32);  // @918_5ce0b0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[26], (u32)(1073741824));  // @919_5ce0b0
  ecx = edx = 0;  // @920_5ce0b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @921_5ce0b0
  eax = (u32)((EBP - 232) + 168);  // @922_5ce0b0
  PV[27] = (u32)(eax);  // @923_5ce0b0
  eax = (u32)((EBP - 236) + 196);  // @924_5ce0b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 236) + 32), &v, sizeof v); }  // @925_5ce0b0
  PV[28] = (u32)(eax);  // @926_5ce0b0
  ecx = edi;  // @927_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 928)))(ecx, PV[28], PV[27]);  // @928_5ce0b0
  ecx = edx = 0;  // @929_5ce0b0
  PV[29] = (u32)(eax);  // @930_5ce0b0
  ecx = edi;  // @931_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[29]);  // @932_5ce0b0
  ecx = edx = 0;  // @933_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @934_5ce0b0
  ecx = (u32)((EBP - 232) + 168);  // @935_5ce0b0
  PV[30] = (u32)(ecx);  // @936_5ce0b0
  ecx = edi;  // @937_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[30]);  // @938_5ce0b0
  ecx = edx = 0;  // @939_5ce0b0
  PV[31] = (u32)(ecx);  // @940_5ce0b0
  eax = (u32)((EBP - 236) + 28);  // @941_5ce0b0
  PV[32] = (u32)(eax);  // @942_5ce0b0
  edx = (u32)((EBP - 240) + 176);  // @943_5ce0b0
  ecx = (u32)((EBP - 240) + 92);  // @944_5ce0b0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[32], (u32)(1120403456));  // @945_5ce0b0
  ecx = edx = 0;  // @946_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @947_5ce0b0
  ecx = (u32)((EBP - 232) + 84);  // @948_5ce0b0
  PV[33] = (u32)(ecx);  // @949_5ce0b0
  ecx = edi;  // @950_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[33]);  // @951_5ce0b0
  ecx = edx = 0;  // @952_5ce0b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @953_5ce0b0
  ecx = (u32)((EBP - 232) + 84);  // @954_5ce0b0
  PV[34] = (u32)(ecx);  // @955_5ce0b0
  ecx = edi;  // @956_5ce0b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 924)))(ecx, PV[34]);  // @957_5ce0b0
  ecx = edx = 0;  // @958_5ce0b0
  L5ceb19:;
  ext_633654(G(u32, 0x6f5630));  // @960_5ce0b0
  return eax;  // @961_5ce0b0
}
// w3g-disabled: PCREG(5ce0b0, lifted_5ce0b0_w3gold);

extern "C" u32 THISCALL lifted_595800_w3gold(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; });  // @0_595800
  X0[1] = 0;  // @1_595800
  X0[2] = 0;  // @2_595800
  X0[3] = 0;  // @3_595800
  edi = ecx;  // @4_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_595800
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @6_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; }));  // @7_595800
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L596663;  // @8_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @9_595800
  X0[1] = 0;  // @10_595800
  X0[2] = 0;  // @11_595800
  X0[3] = 0;  // @12_595800
  X1[0] = 0;  // @13_595800
  X1[1] = 0;  // @14_595800
  X1[2] = 0;  // @15_595800
  X1[3] = 0;  // @16_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @17_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @18_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @19_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59588e;  // @20_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @21_595800
  X0[1] = 0;  // @22_595800
  X0[2] = 0;  // @23_595800
  X0[3] = 0;  // @24_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @25_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @26_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @27_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59588e;  // @28_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @30_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @31_595800
  ecx = edx = 0;  // @32_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_595800
  PV[0] = (u32)(edx);  // @34_595800
  PV[1] = (u32)(eax);  // @35_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[1], PV[0], (u32)(6998696));  // @37_595800
  ecx = edx = 0;  // @38_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_595800
  L59588e:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @41_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3803) + 0), 4); v; });  // @42_595800
  X1[1] = 0;  // @43_595800
  X1[2] = 0;  // @44_595800
  X1[3] = 0;  // @45_595800
  if (FL[2] == 0) goto L5958aa;  // @46_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })));  // @47_595800
  L5958aa:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @49_595800
  X2[1] = 0;  // @50_595800
  X2[2] = 0;  // @51_595800
  X2[3] = 0;  // @52_595800
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @53_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @54_595800
  X3[1] = 0;  // @55_595800
  X3[2] = 0;  // @56_595800
  X3[3] = 0;  // @57_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5958dd;  // @58_595800
  X0[0] = X1[0];  // @59_595800
  X0[1] = X1[1];  // @60_595800
  X0[2] = X1[2];  // @61_595800
  X0[3] = X1[3];  // @62_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @63_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; })));  // @64_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @65_595800
  __builtin_memcpy((void *)((u32)(edi + 3799) + 0), &X0[0], 4);  // @66_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @67_595800
  L5958dd:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @69_595800
  X2[1] = 0;  // @70_595800
  X2[2] = 0;  // @71_595800
  X2[3] = 0;  // @72_595800
  X0[0] = X1[0];  // @73_595800
  X0[1] = X1[1];  // @74_595800
  X0[2] = X1[2];  // @75_595800
  X0[3] = X1[3];  // @76_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @77_595800
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @78_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L59590a;  // @79_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @80_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; })));  // @81_595800
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @82_595800
  __builtin_memcpy((void *)((u32)(edi + 3799) + 0), &X2[0], 4);  // @83_595800
  L59590a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_595800
  ecx = (u32)((EBP - 264) + 104);  // @86_595800
  PV[2] = (u32)(ecx);  // @87_595800
  ecx = (u32)((EBP - 268) + 192);  // @88_595800
  PV[3] = (u32)(ecx);  // @89_595800
  ecx = edi;  // @90_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[3], PV[2]);  // @91_595800
  ecx = edx = 0;  // @92_595800
  esi = (u32)(edi + 3763);  // @93_595800
  PV[4] = (u32)(esi);  // @94_595800
  edx = (u32)((EBP - 268) + 108);  // @95_595800
  ecx = (u32)((EBP - 268) + 180);  // @96_595800
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @97_595800
  ecx = edx = 0;  // @98_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @100_595800
  X0[1] = 0;  // @101_595800
  X0[2] = 0;  // @102_595800
  X0[3] = 0;  // @103_595800
  PV[5] = (u32)(ecx);  // @104_595800
  ecx = (u32)((EBP - 268) + 180);  // @105_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @106_595800
  PV[6] = X0[0];  // @107_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[6]);  // @108_595800
    // @109_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_595800
  PV[7] = (u32)(ecx);  // @111_595800
  ecx = (u32)((EBP - 268) + 180);  // @112_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @113_595800
  X0[1] = 0;  // @114_595800
  X0[2] = 0;  // @115_595800
  X0[3] = 0;  // @116_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @117_595800
  PV[8] = X0[0];  // @118_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[8]);  // @119_595800
    // @120_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @121_595800
  ecx = (u32)(edi + 3775);  // @122_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @123_595800
  X1[1] = 0;  // @124_595800
  X1[2] = 0;  // @125_595800
  X1[3] = 0;  // @126_595800
  PV[9] = (u32)(ecx);  // @127_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @128_595800
  X0[1] = 0;  // @129_595800
  X0[2] = 0;  // @130_595800
  X0[3] = 0;  // @131_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @132_595800
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @133_595800
  PV[10] = X1[0];  // @134_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[10]);  // @135_595800
    // @136_595800
  edx = (u32)((EBP - 264) + 176);  // @137_595800
  ecx = (u32)(edi + 3775);  // @138_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @139_595800
  ecx = edx = 0;  // @140_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 104) + 0), 4); v; });  // @141_595800
  X0[1] = 0;  // @142_595800
  X0[2] = 0;  // @143_595800
  X0[3] = 0;  // @144_595800
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @145_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 108) + 0), 4); v; });  // @146_595800
  X0[1] = 0;  // @147_595800
  X0[2] = 0;  // @148_595800
  X0[3] = 0;  // @149_595800
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @150_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 112) + 0), 4); v; });  // @151_595800
  X0[1] = 0;  // @152_595800
  X0[2] = 0;  // @153_595800
  X0[3] = 0;  // @154_595800
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @155_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3775) + 0), 4); v; });  // @156_595800
  X2[1] = 0;  // @157_595800
  X2[2] = 0;  // @158_595800
  X2[3] = 0;  // @159_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; })));  // @160_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 52), &v, sizeof v); }  // @161_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3783) + 0), 4); v; });  // @162_595800
  X1[1] = 0;  // @163_595800
  X1[2] = 0;  // @164_595800
  X1[3] = 0;  // @165_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; })));  // @166_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 48) + 0), &X2[0], 4);  // @167_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @168_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 56) + 0), &X1[0], 4);  // @169_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @170_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })));  // @171_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @172_595800
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @173_595800
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @174_595800
  ecx = edx = 0;  // @175_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 188) + 0), 4); v; });  // @176_595800
  X1[1] = 0;  // @177_595800
  X1[2] = 0;  // @178_595800
  X1[3] = 0;  // @179_595800
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @180_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @181_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 44) + 0), &X0[0], 4);  // @182_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 108) + 0), 4); v; });  // @183_595800
  X0[1] = 0;  // @184_595800
  X0[2] = 0;  // @185_595800
  X0[3] = 0;  // @186_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; })));  // @187_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 108) + 0), &X0[0], 4);  // @188_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595a69;  // @189_595800
  X0[0] = 0;  // @190_595800
  X0[1] = 0;  // @191_595800
  X0[2] = 0;  // @192_595800
  X0[3] = 0;  // @193_595800
  X1[0] = X0[0];  // @194_595800
  X1[1] = X0[1];  // @195_595800
  X1[2] = X0[2];  // @196_595800
  X1[3] = X0[3];  // @197_595800
  goto L595a92;  // @198_595800
  L595a69:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @200_595800
  X0[1] = 0;  // @201_595800
  X0[2] = 0;  // @202_595800
  X0[3] = 0;  // @203_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @204_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595a80;  // @205_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @206_595800
  X1[1] = 0;  // @207_595800
  X1[2] = 0;  // @208_595800
  X1[3] = 0;  // @209_595800
  goto L595a8f;  // @210_595800
  L595a80:;
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @212_595800
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @213_595800
  ecx = edx = 0;  // @214_595800
  X1[0] = 0;  // @215_595800
  X1[1] = 0;  // @216_595800
  X1[2] = 0;  // @217_595800
  X1[3] = 0;  // @218_595800
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @219_595800
  L595a8f:;
  X0[0] = 0;  // @221_595800
  X0[1] = 0;  // @222_595800
  X0[2] = 0;  // @223_595800
  X0[3] = 0;  // @224_595800
  L595a92:;
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 212) + 0), 4); v; }));  // @226_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; });  // @227_595800
  X2[1] = 0;  // @228_595800
  X2[2] = 0;  // @229_595800
  X2[3] = 0;  // @230_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595aae;  // @231_595800
  X0[0] = X2[0];  // @232_595800
  X0[1] = X2[1];  // @233_595800
  X0[2] = X2[2];  // @234_595800
  X0[3] = X2[3];  // @235_595800
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @236_595800
  X1[0] = X0[0];  // @237_595800
  X1[1] = X0[1];  // @238_595800
  X1[2] = X0[2];  // @239_595800
  X1[3] = X0[3];  // @240_595800
  L595aae:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @242_595800
  eax = (u32)(6);  // @243_595800
  FL[0] = esi; FL[1] = eax;  // @244_595800
  if ((s32)FL[0] < (s32)FL[1]) esi = eax;  // @245_595800
  ecx = 0;  // @246_595800
  FL[3] = ecx;  // @247_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 32), &v, sizeof v); }  // @248_595800
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @249_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @250_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @251_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @252_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @253_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @254_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(X2[0]));  // @255_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @256_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @257_595800
  FL[0] = eax; FL[1] = esi;  // @258_595800
  if ((s32)FL[0] < (s32)FL[1]) ecx = eax;  // @259_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 40), &v, sizeof v); }  // @260_595800
  ecx = (u32)((EBP - 264) + 224);  // @261_595800
  eax = ext_4de7a0_thiscall1(ecx);  // @262_595800
    // @263_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @264_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3795) + 0), 4); v; });  // @265_595800
  X3[1] = 0;  // @266_595800
  X3[2] = 0;  // @267_595800
  X3[3] = 0;  // @268_595800
  X3[0] = F2U(U2F(X3[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @269_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 164), &v, sizeof v); }  // @270_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 168), &v, sizeof v); }  // @271_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 172), &v, sizeof v); }  // @272_595800
  X3[0] = F2U(U2F(X3[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; })));  // @273_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X3[0], 4);  // @274_595800
  if (FL[2] == 0) goto L595b4b;  // @275_595800
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })));  // @276_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X3[0], 4);  // @277_595800
  L595b4b:;
  eax = 0;  // @279_595800
  FL[3] = eax;  // @280_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @281_595800
  FL[2] = (esi & esi);  // @282_595800
  if ((s32)FL[2] <= 0) goto L595ec7;  // @283_595800
  esi = (u32)(edi + 3423);  // @284_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @285_595800
  L595b63:;
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @287_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @288_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @289_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @290_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @291_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @292_595800
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @293_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @294_595800
  X1[0] = F2U((float)(s32)X1[0]);  // @295_595800
  X1[1] = F2U((float)(s32)X1[1]);  // @296_595800
  X1[2] = F2U((float)(s32)X1[2]);  // @297_595800
  X1[3] = F2U((float)(s32)X1[3]);  // @298_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @299_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @300_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @301_595800
  X1[1] = 0;  // @302_595800
  X1[2] = 0;  // @303_595800
  X1[3] = 0;  // @304_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @305_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X2[0], a_); SD(&X2[2], b_); }  // @306_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @307_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X2[0], 4);  // @308_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 4), &X2[1], 4);  // @309_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X0[0], 4);  // @310_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 4), &X0[1], 4);  // @311_595800
  X0[0] = X2[0];  // @312_595800
  X0[1] = X2[1];  // @313_595800
  X0[2] = X2[2];  // @314_595800
  X0[3] = X2[3];  // @315_595800
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @316_595800
  ecx = edx = 0;  // @317_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; })));  // @318_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @319_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 36) + 0), &X0[0], 4);  // @320_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @321_595800
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @322_595800
  ecx = edx = 0;  // @323_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; })));  // @324_595800
  edx = (u32)((EBP - 264) + 104);  // @325_595800
  ecx = (u32)((EBP - 264) + 116);  // @326_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 120), &v, sizeof v); }  // @327_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 36) + 0), 4); v; });  // @328_595800
  X1[1] = 0;  // @329_595800
  X1[2] = 0;  // @330_595800
  X1[3] = 0;  // @331_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 116) + 0), &X1[0], 4);  // @332_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @333_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 124) + 0), &X0[0], 4);  // @334_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @335_595800
  ecx = edx = 0;  // @336_595800
  edx = (u32)((EBP - 264) + 48);  // @337_595800
  ecx = (u32)((EBP - 264) + 116);  // @338_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @339_595800
  ecx = edx = 0;  // @340_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3787), sizeof v); (u32)v; });  // @341_595800
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 15), &v, sizeof v); }  // @342_595800
  FL[2] = (ecx & ecx);  // @343_595800
  if (FL[2] == 0) goto L595c32;  // @344_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @345_595800
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @346_595800
  if (FL[0] != FL[1]) goto L595c32;  // @347_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @348_595800
  edx = (u32)((EBP - 264) + 116);  // @349_595800
  PV[11] = (u32)(edx);  // @350_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 544), sizeof v); (u32)v; });  // @351_595800
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[11]);  // @352_595800
  ecx = edx = 0;  // @353_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @354_595800
  if (FL[2] == 0) goto L595dba;  // @355_595800
  L595c32:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @357_595800
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @358_595800
  if (FL[0] != FL[1]) goto L595d4a;  // @359_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @360_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1052), sizeof v); (u32)v; });  // @361_595800
  edx = (u32)(ecx + 1056);  // @362_595800
  eax = (eax + (u32)(264));  // @363_595800
  FL[3] = eax;  // @364_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 36), &v, sizeof v); }  // @365_595800
  eax = (u32)(ecx + eax*4);  // @366_595800
  FL[0] = edx; FL[1] = eax;  // @367_595800
  if (FL[0] == FL[1]) goto L595d4a;  // @368_595800
  L595c70:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @370_595800
  FL[2] = (esi & esi);  // @371_595800
  if (FL[2] == 0) goto L595d29;  // @372_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @373_595800
  ecx = esi;  // @374_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @375_595800
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1051586));  // @376_595800
  ecx = edx = 0;  // @377_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @378_595800
  if (FL[2] != 0) goto L595d1f;  // @379_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @380_595800
  edx = (u32)((EBP - 264) + 116);  // @381_595800
  eax = (eax + (u32)(36));  // @382_595800
  FL[3] = eax;  // @383_595800
  ecx = (u32)((EBP - 264) + 128);  // @384_595800
  PV[12] = (u32)(eax);  // @385_595800
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @386_595800
  ecx = edx = 0;  // @387_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @388_595800
  ecx = (u32)((EBP - 264) + 128);  // @389_595800
  eax = ext_441a60_fastcall2(ecx, edx);  // @390_595800
  ecx = edx = 0;  // @391_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @392_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 128) + 0), 4); v; });  // @393_595800
  X1[1] = 0;  // @394_595800
  X1[2] = 0;  // @395_595800
  X1[3] = 0;  // @396_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X2[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X2[2] = X2[3] = 0;  // @397_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @398_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @399_595800
  X0[1] = 0;  // @400_595800
  X0[2] = 0;  // @401_595800
  X0[3] = 0;  // @402_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @403_595800
  X1[0] = X1[0] & X2[0];  // @404_595800
  X1[1] = X1[1] & X2[1];  // @405_595800
  X1[2] = X1[2] & X2[2];  // @406_595800
  X1[3] = X1[3] & X2[3];  // @407_595800
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @408_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595d1f;  // @409_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 132) + 0), 4); v; });  // @410_595800
  X1[1] = 0;  // @411_595800
  X1[2] = 0;  // @412_595800
  X1[3] = 0;  // @413_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @414_595800
  X0[1] = 0;  // @415_595800
  X0[2] = 0;  // @416_595800
  X0[3] = 0;  // @417_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @418_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @419_595800
  X1[0] = X1[0] & X2[0];  // @420_595800
  X1[1] = X1[1] & X2[1];  // @421_595800
  X1[2] = X1[2] & X2[2];  // @422_595800
  X1[3] = X1[3] & X2[3];  // @423_595800
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @424_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595d1f;  // @425_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 136) + 0), 4); v; });  // @426_595800
  X1[1] = 0;  // @427_595800
  X1[2] = 0;  // @428_595800
  X1[3] = 0;  // @429_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @430_595800
  X0[1] = 0;  // @431_595800
  X0[2] = 0;  // @432_595800
  X0[3] = 0;  // @433_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @434_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @435_595800
  X1[0] = X1[0] & X2[0];  // @436_595800
  X1[1] = X1[1] & X2[1];  // @437_595800
  X1[2] = X1[2] & X2[2];  // @438_595800
  X1[3] = X1[3] & X2[3];  // @439_595800
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @440_595800
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L595db6;  // @441_595800
  L595d1f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @443_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 36), sizeof v); (u32)v; });  // @444_595800
  L595d29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1052), sizeof v); (u32)v; });  // @446_595800
  edx = (edx + (u32)(4));  // @447_595800
  FL[3] = edx;  // @448_595800
  eax = (eax + (u32)(264));  // @449_595800
  FL[3] = eax;  // @450_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 36), &v, sizeof v); }  // @451_595800
  eax = (u32)(ecx + eax*4);  // @452_595800
  FL[0] = edx; FL[1] = eax;  // @453_595800
  if (FL[0] != FL[1]) goto L595c70;  // @454_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @455_595800
  L595d4a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @457_595800
  X1[1] = 0;  // @458_595800
  X1[2] = 0;  // @459_595800
  X1[3] = 0;  // @460_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @461_595800
  X0[1] = 0;  // @462_595800
  X0[2] = 0;  // @463_595800
  X0[3] = 0;  // @464_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @465_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595d75;  // @466_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @467_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @468_595800
  X0[1] = 0;  // @469_595800
  X0[2] = 0;  // @470_595800
  X0[3] = 0;  // @471_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; })));  // @472_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @473_595800
  L595d71:;
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @475_595800
  L595d75:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3816) + 0), 4); v; });  // @477_595800
  X0[1] = 0;  // @478_595800
  X0[2] = 0;  // @479_595800
  X0[3] = 0;  // @480_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @481_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @482_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @483_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L595e53;  // @484_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @485_595800
  if (FL[0] == FL[1]) goto L595e14;  // @486_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @487_595800
  if (FL[0] == FL[1]) goto L595dd6;  // @488_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; });  // @489_595800
  edx = (u32)(65280);  // @490_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; }); FL[1] = eax;  // @491_595800
  eax = (u32)(16777215);  // @492_595800
  if (FL[0] == FL[1]) edx = eax;  // @493_595800
  goto L595ddb;  // @494_595800
  L595db6:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @496_595800
  L595dba:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @498_595800
  X0[1] = 0;  // @499_595800
  X0[2] = 0;  // @500_595800
  X0[3] = 0;  // @501_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; }));  // @502_595800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 15), &v, sizeof v); }  // @503_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595d75;  // @504_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799784) + 0), 4); v; })));  // @505_595800
  goto L595d71;  // @506_595800
  L595dd6:;
  edx = (u32)(16711680);  // @508_595800
  L595ddb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @510_595800
  PV[13] = (u32)(edx);  // @511_595800
  edx = (u32)((EBP - 272) + 172);  // @512_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @513_595800
  PV[14] = (u32)(edx);  // @514_595800
  edx = (u32)((EBP - 276) + 128);  // @515_595800
  PV[15] = (u32)(edx);  // @516_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @517_595800
  edx = (u32)((EBP - 280) + 240);  // @518_595800
  PV[16] = (u32)(edx);  // @519_595800
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; });  // @520_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @521_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[17], PV[16], PV[15], PV[14], PV[13], (u32)(0));  // @522_595800
  ecx = edx = 0;  // @523_595800
  goto L595e7b;  // @524_595800
  L595e14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @526_595800
  edx = (u32)((EBP - 264) + 164);  // @527_595800
  PV[18] = (u32)(edx);  // @528_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @529_595800
  edx = (u32)((EBP - 276) + 128);  // @530_595800
  PV[19] = (u32)(edx);  // @531_595800
  edx = (u32)((EBP - 280) + 240);  // @532_595800
  PV[20] = (u32)(edx);  // @533_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @534_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @535_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 568), sizeof v); (u32)v; });  // @536_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[20], PV[19], PV[18], (u32)(16711680), (u32)(0));  // @537_595800
  ecx = edx = 0;  // @538_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 17), &v, sizeof v); }  // @539_595800
  goto L595e7b;  // @540_595800
  L595e53:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; });  // @542_595800
  FL[2] = (edx & edx);  // @543_595800
  if (FL[2] == 0) goto L595e7b;  // @544_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @545_595800
  PV[21] = (u32)(edx);  // @546_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @547_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @548_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @549_595800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[21]);  // @550_595800
  ecx = edx = 0;  // @551_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi - 17), &v, sizeof v); }  // @552_595800
  L595e7b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 116) + 0), 4); v; });  // @554_595800
  X0[1] = 0;  // @555_595800
  X0[2] = 0;  // @556_595800
  X0[3] = 0;  // @557_595800
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 15), sizeof v); (u32)v; })) & 0xff);  // @558_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @559_595800
  X3[1] = 0;  // @560_595800
  X3[2] = 0;  // @561_595800
  X3[3] = 0;  // @562_595800
  __builtin_memcpy((void *)((u32)(esi - 13) + 0), &X0[0], 4);  // @563_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 120) + 0), 4); v; });  // @564_595800
  X0[1] = 0;  // @565_595800
  X0[2] = 0;  // @566_595800
  X0[3] = 0;  // @567_595800
  __builtin_memcpy((void *)((u32)(esi - 9) + 0), &X0[0], 4);  // @568_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 124) + 0), 4); v; });  // @569_595800
  X0[1] = 0;  // @570_595800
  X0[2] = 0;  // @571_595800
  X0[3] = 0;  // @572_595800
  __builtin_memcpy((void *)((u32)(esi - 5) + 0), &X0[0], 4);  // @573_595800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi - 1), &v, sizeof v); }  // @574_595800
  esi = (esi + (u32)(21));  // @575_595800
  FL[3] = esi;  // @576_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @577_595800
  eax = (eax + 1);  // @578_595800
  FL[3] = eax;  // @579_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @580_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @581_595800
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @582_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L595b63;  // @583_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @584_595800
  L595ec7:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 3807), &v, sizeof v); }  // @586_595800
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @587_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; }); FL[1] = esi;  // @588_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L595edf;  // @589_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3807), &v, sizeof v); }  // @590_595800
  L595edf:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3816) + 0), 4); v; });  // @592_595800
  X0[1] = 0;  // @593_595800
  X0[2] = 0;  // @594_595800
  X0[3] = 0;  // @595_595800
  X1[0] = 0;  // @596_595800
  X1[1] = 0;  // @597_595800
  X1[2] = 0;  // @598_595800
  X1[3] = 0;  // @599_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @600_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @601_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @602_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59605a;  // @603_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @604_595800
  X0[1] = 0;  // @605_595800
  X0[2] = 0;  // @606_595800
  X0[3] = 0;  // @607_595800
  edx = (u32)((EBP - 264) + 104);  // @608_595800
  ecx = (u32)((EBP - 264) + 128);  // @609_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 0), &X0[0], 4);  // @610_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 132), &v, sizeof v); }  // @611_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 136), &v, sizeof v); }  // @612_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @613_595800
  ecx = edx = 0;  // @614_595800
  esi = (u32)(1);  // @615_595800
  L595f33:;
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @617_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @618_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @619_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @620_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @621_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @622_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @623_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @624_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @625_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X0[0], 4);  // @626_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 4), &X0[1], 4);  // @627_595800
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @628_595800
  ecx = edx = 0;  // @629_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @630_595800
  X1[1] = 0;  // @631_595800
  X1[2] = 0;  // @632_595800
  X1[3] = 0;  // @633_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @634_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @635_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @636_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X0[0], 4);  // @637_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @638_595800
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @639_595800
  ecx = edx = 0;  // @640_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @641_595800
  X1[1] = 0;  // @642_595800
  X1[2] = 0;  // @643_595800
  X1[3] = 0;  // @644_595800
  edx = (u32)((EBP - 264) + 104);  // @645_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @646_595800
  ecx = (u32)((EBP - 264) + 88);  // @647_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 92), &v, sizeof v); }  // @648_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @649_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @650_595800
  X1[1] = 0;  // @651_595800
  X1[2] = 0;  // @652_595800
  X1[3] = 0;  // @653_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X1[0], 4);  // @654_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @655_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 96) + 0), &X0[0], 4);  // @656_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @657_595800
  ecx = edx = 0;  // @658_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422624), sizeof v); (u32)v; });  // @659_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 28), &v, sizeof v); }  // @660_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7422628), sizeof v); (u32)v; });  // @661_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @662_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @663_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @664_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @665_595800
  FL[2] = (edx & edx);  // @666_595800
  if (FL[2] != 0) goto L596008;  // @667_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 536), sizeof v); (u32)v; });  // @668_595800
  edx = (u32)((EBP - 268) + 92);  // @669_595800
  PV[22] = (u32)(edx);  // @670_595800
  edx = (u32)((EBP - 272) + 136);  // @671_595800
  PV[23] = (u32)(edx);  // @672_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[23], PV[22], (u32)(16711680));  // @673_595800
  ecx = edx = 0;  // @674_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 28), sizeof v); (u32)v; });  // @675_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx*4 + 7422628), &v, sizeof v); }  // @676_595800
  goto L596020;  // @677_595800
  L596008:;
  edi = (u32)((EBP - 264) + 92);  // @679_595800
  PV[24] = (u32)(edi);  // @680_595800
  edi = (u32)((EBP - 268) + 136);  // @681_595800
  PV[25] = (u32)(edi);  // @682_595800
  PV[26] = (u32)(edx);  // @683_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[26], PV[25], PV[24]);  // @684_595800
  ecx = edx = 0;  // @685_595800
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 24), sizeof v); (u32)v; });  // @686_595800
  L596020:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422624), sizeof v); (u32)v; });  // @688_595800
  ecx = (u32)(10);  // @689_595800
  eax = (eax + 1);  // @690_595800
  FL[3] = eax;  // @691_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; });  // @692_595800
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; });  // @693_595800
  X0[2] = 0;  // @694_595800
  X0[3] = 0;  // @695_595800
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @696_595800
  esi = (esi + 1);  // @697_595800
  FL[3] = esi;  // @698_595800
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @699_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 96), sizeof v); (u32)v; });  // @700_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7422624), &v, sizeof v); }  // @701_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 0), &X0[0], 4);  // @702_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 4), &X0[1], 4);  // @703_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 136), &v, sizeof v); }  // @704_595800
  FL[0] = esi; FL[1] = ecx;  // @705_595800
  if ((s32)FL[0] <= (s32)FL[1]) goto L595f33;  // @706_595800
  X1[0] = 0;  // @707_595800
  X1[1] = 0;  // @708_595800
  X1[2] = 0;  // @709_595800
  X1[3] = 0;  // @710_595800
  L59605a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @712_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @713_595800
  X0[1] = 0;  // @714_595800
  X0[2] = 0;  // @715_595800
  X0[3] = 0;  // @716_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @717_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @718_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @719_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L5960ab;  // @720_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @721_595800
  X0[1] = 0;  // @722_595800
  X0[2] = 0;  // @723_595800
  X0[3] = 0;  // @724_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @725_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @726_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @727_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L5960ab;  // @728_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @729_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @730_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @731_595800
  ecx = edx = 0;  // @732_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @733_595800
  PV[27] = (u32)(edx);  // @734_595800
  PV[28] = (u32)(eax);  // @735_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @736_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[28], PV[27], (u32)(6998704));  // @737_595800
  ecx = edx = 0;  // @738_595800
  L5960ab:;
  eax = 0;  // @740_595800
  FL[3] = eax;  // @741_595800
  edx = (u32)((EBP - 264) + 104);  // @742_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @743_595800
  ecx = (u32)((EBP - 264) + 60);  // @744_595800
  eax = (u32)((EBP - 264) + 48);  // @745_595800
  PV[29] = (u32)(eax);  // @746_595800
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[29]);  // @747_595800
  ecx = edx = 0;  // @748_595800
  eax = (u32)(edi + 2586);  // @749_595800
  esi = eax;  // @750_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @751_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @752_595800
  eax = (u32)(eax + eax*2);  // @753_595800
  eax = (eax << (u32)(4));  // @754_595800
  FL[3] = eax;  // @755_595800
  eax = (eax + (u32)(2586));  // @756_595800
  FL[3] = eax;  // @757_595800
  eax = (eax + edi);  // @758_595800
  FL[3] = eax;  // @759_595800
  FL[0] = esi; FL[1] = eax;  // @760_595800
  if (FL[0] == FL[1]) goto L5961cc;  // @761_595800
  L5960f0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @763_595800
  edx = (u32)(esi + 32);  // @764_595800
  PV[30] = (u32)(edx);  // @765_595800
  edx = (u32)((EBP - 268) + 132);  // @766_595800
  PV[31] = (u32)(edx);  // @767_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @768_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1404)))(ecx, PV[31], PV[30]);  // @769_595800
  ecx = edx = 0;  // @770_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @771_595800
  X0[1] = 0;  // @772_595800
  X0[2] = 0;  // @773_595800
  X0[3] = 0;  // @774_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @775_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @776_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @777_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @778_595800
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @779_595800
  if ((s32)FL[0] >= (s32)FL[1]) goto L59617a;  // @780_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; });  // @781_595800
  X0[1] = 0;  // @782_595800
  X0[2] = 0;  // @783_595800
  X0[3] = 0;  // @784_595800
  eax = (u32)((EBP - 264) + 188);  // @785_595800
  PV[32] = (u32)(ecx);  // @786_595800
  PV[33] = X0[0];  // @787_595800
  ecx = edi;  // @788_595800
  PV[34] = (u32)(eax);  // @789_595800
  eax = (u32)((EBP - 272) + 112);  // @790_595800
  PV[35] = (u32)(eax);  // @791_595800
  eax = (u32)((EBP - 276) + 72);  // @792_595800
  PV[36] = (u32)(eax);  // @793_595800
  eax = (u32)(esi + 32);  // @794_595800
  PV[37] = (u32)(eax);  // @795_595800
  eax = (u32)((EBP - 284) + 148);  // @796_595800
  PV[38] = (u32)(eax);  // @797_595800
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @798_595800
  eax = ext_5941d0_stdcall7(PV[39], PV[38], PV[37], PV[36], PV[35], PV[34], PV[33]);  // @799_595800
  ecx = edx = 0;  // @800_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @801_595800
  if (FL[2] == 0) goto L59617a;  // @802_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @803_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @804_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @805_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @806_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @807_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @808_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @809_595800
  __builtin_memcpy((void *)((u32)(esi + 20) + 0), &X0[0], 4);  // @810_595800
  L59617a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; });  // @812_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @813_595800
  eax = (eax + ecx);  // @814_595800
  FL[3] = eax;  // @815_595800
  if ((s32)FL[3] >= 0) goto L59618c;  // @816_595800
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; }));  // @817_595800
  FL[3] = eax;  // @818_595800
  goto L596196;  // @819_595800
  L59618c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @821_595800
  FL[0] = eax; FL[1] = edx;  // @822_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L596196;  // @823_595800
  eax = (eax - edx);  // @824_595800
  FL[3] = eax;  // @825_595800
  L596196:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @827_595800
  FL[2] = (ecx & ecx);  // @828_595800
  if ((s32)FL[2] >= 0) goto L5961a5;  // @829_595800
  FL[1] = ecx;  // @830_595800
  ecx = (0u - ecx);  // @831_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @832_595800
  goto L5961ae;  // @833_595800
  L5961a5:;
  eax = (eax | (u32)(4294967295));  // @835_595800
  FL[3] = eax;  // @836_595800
  eax = (eax - ecx);  // @837_595800
  FL[3] = eax;  // @838_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @839_595800
  L5961ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @841_595800
  esi = (esi + (u32)(48));  // @842_595800
  FL[3] = esi;  // @843_595800
  eax = (u32)(eax + eax*2);  // @844_595800
  eax = (eax << (u32)(4));  // @845_595800
  FL[3] = eax;  // @846_595800
  eax = (eax + (u32)(2586));  // @847_595800
  FL[3] = eax;  // @848_595800
  eax = (eax + edi);  // @849_595800
  FL[3] = eax;  // @850_595800
  FL[0] = esi; FL[1] = eax;  // @851_595800
  if (FL[0] != FL[1]) goto L5960f0;  // @852_595800
  L5961cc:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @854_595800
  X1[0] = 0;  // @855_595800
  X1[1] = 0;  // @856_595800
  X1[2] = 0;  // @857_595800
  X1[3] = 0;  // @858_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @859_595800
  X0[1] = 0;  // @860_595800
  X0[2] = 0;  // @861_595800
  X0[3] = 0;  // @862_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @863_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @864_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @865_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59622b;  // @866_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @867_595800
  X0[1] = 0;  // @868_595800
  X0[2] = 0;  // @869_595800
  X0[3] = 0;  // @870_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @871_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @872_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @873_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59622b;  // @874_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @875_595800
  ecx = edx;  // @876_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @877_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @878_595800
  ecx = edx = 0;  // @879_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @880_595800
  PV[40] = (u32)(edx);  // @881_595800
  PV[41] = (u32)(eax);  // @882_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @883_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[41], PV[40], (u32)(6998704));  // @884_595800
  ecx = edx = 0;  // @885_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @886_595800
  X1[0] = 0;  // @887_595800
  X1[1] = 0;  // @888_595800
  X1[2] = 0;  // @889_595800
  X1[3] = 0;  // @890_595800
  L59622b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @892_595800
  X0[1] = 0;  // @893_595800
  X0[2] = 0;  // @894_595800
  X0[3] = 0;  // @895_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @896_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @897_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @898_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59627e;  // @899_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @900_595800
  X0[1] = 0;  // @901_595800
  X0[2] = 0;  // @902_595800
  X0[3] = 0;  // @903_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @904_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @905_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @906_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59627e;  // @907_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @908_595800
  ecx = edx;  // @909_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @910_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @911_595800
  ecx = edx = 0;  // @912_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @913_595800
  PV[42] = (u32)(edx);  // @914_595800
  PV[43] = (u32)(eax);  // @915_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @916_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[43], PV[42], (u32)(6998712));  // @917_595800
  ecx = edx = 0;  // @918_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @919_595800
  L59627e:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3779) + 0), 4); v; });  // @921_595800
  X1[1] = 0;  // @922_595800
  X1[2] = 0;  // @923_595800
  X1[3] = 0;  // @924_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3775) + 0), 4); v; });  // @925_595800
  X2[1] = 0;  // @926_595800
  X2[2] = 0;  // @927_595800
  X2[3] = 0;  // @928_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3783) + 0), 4); v; });  // @929_595800
  X0[1] = 0;  // @930_595800
  X0[2] = 0;  // @931_595800
  X0[3] = 0;  // @932_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @933_595800
  ecx = eax;  // @934_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @935_595800
  ecx = (ecx >> (u32)(1));  // @936_595800
  FL[3] = ecx;  // @937_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @938_595800
  ecx = (ecx & (u32)(4294967041));  // @939_595800
  FL[3] = ecx;  // @940_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 40), &v, sizeof v); }  // @941_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @942_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @943_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @944_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X2[0], 4);  // @945_595800
  FL[2] = (eax & (u32)(1024));  // @946_595800
  if (FL[2] == 0) goto L5962db;  // @947_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000612) + 0), 4); v; });  // @948_595800
  X1[1] = 0;  // @949_595800
  X1[2] = 0;  // @950_595800
  X1[3] = 0;  // @951_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 20) + 0), &X1[0], 4);  // @952_595800
  goto L5962e9;  // @953_595800
  L5962db:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000616) + 0), 4); v; });  // @955_595800
  X0[1] = 0;  // @956_595800
  X0[2] = 0;  // @957_595800
  X0[3] = 0;  // @958_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 20) + 0), &X0[0], 4);  // @959_595800
  L5962e9:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3795) + 0), 4); v; });  // @961_595800
  X0[1] = 0;  // @962_595800
  X0[2] = 0;  // @963_595800
  X0[3] = 0;  // @964_595800
  ecx = (u32)(edi + 2586);  // @965_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @966_595800
  X1[0] = X0[0];  // @967_595800
  X1[1] = X0[1];  // @968_595800
  X1[2] = X0[2];  // @969_595800
  X1[3] = X0[3];  // @970_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000564) + 0), 4); v; })));  // @971_595800
  eax = (u32)(eax + eax*2);  // @972_595800
  eax = (eax << (u32)(4));  // @973_595800
  FL[3] = eax;  // @974_595800
  eax = (eax + (u32)(2586));  // @975_595800
  FL[3] = eax;  // @976_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @977_595800
  eax = (eax + edi);  // @978_595800
  FL[3] = eax;  // @979_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 44) + 0), &X1[0], 4);  // @980_595800
  FL[0] = ecx; FL[1] = eax;  // @981_595800
  if (FL[0] == FL[1]) goto L5965bd;  // @982_595800
  esi = (u32)(ecx + 12);  // @983_595800
  L596330:;
  edx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }) * (s32)(u32)(21));  // @985_595800
  ecx = (u32)(esi - 8);  // @986_595800
  edx = (edx + (u32)(3410));  // @987_595800
  FL[3] = edx;  // @988_595800
  edx = (edx + edi);  // @989_595800
  FL[3] = edx;  // @990_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 28), &v, sizeof v); }  // @991_595800
  FS[0] = ext_4e0830_fastcall2_ld(ecx, edx);  // @992_595800
  ecx = edx = 0;  // @993_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @994_595800
  X0[1] = 0;  // @995_595800
  X0[2] = 0;  // @996_595800
  X0[3] = 0;  // @997_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @998_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @999_595800
  STF((u32)((EBP - 264) + 24), FS[0]);  // @1000_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; });  // @1001_595800
  X1[1] = 0;  // @1002_595800
  X1[2] = 0;  // @1003_595800
  X1[3] = 0;  // @1004_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @1005_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @1006_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 32) + 0), &X1[0], 4);  // @1007_595800
  eax = (eax - ecx);  // @1008_595800
  FL[3] = eax;  // @1009_595800
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; }));  // @1010_595800
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @1011_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @1012_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @1013_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @1014_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @1015_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @1016_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 36) + 0), &X0[0], 4);  // @1017_595800
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5963ae;  // @1018_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @1019_595800
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5963ae;  // @1020_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @1021_595800
  if (FL[0] != FL[1]) goto L596594;  // @1022_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1023_595800
  if (FL[0] != FL[1]) goto L596594;  // @1024_595800
  L5963ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 28), sizeof v); (u32)v; });  // @1026_595800
  ecx = (u32)(esi + 20);  // @1027_595800
  edx = (u32)((EBP - 264) + 104);  // @1028_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1029_595800
  X0[1] = 0;  // @1030_595800
  X0[2] = 0;  // @1031_595800
  X0[3] = 0;  // @1032_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X0[0], 4);  // @1033_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @1034_595800
  X0[1] = 0;  // @1035_595800
  X0[2] = 0;  // @1036_595800
  X0[3] = 0;  // @1037_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 76) + 0), &X0[0], 4);  // @1038_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @1039_595800
  X0[1] = 0;  // @1040_595800
  X0[2] = 0;  // @1041_595800
  X0[3] = 0;  // @1042_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 80) + 0), &X0[0], 4);  // @1043_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @1044_595800
  X0[1] = 0;  // @1045_595800
  X0[2] = 0;  // @1046_595800
  X0[3] = 0;  // @1047_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X0[0], 4);  // @1048_595800
  FS[0] = ext_4e0830_fastcall2_ld(ecx, edx);  // @1049_595800
  ecx = edx = 0;  // @1050_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @1051_595800
  X1[1] = 0;  // @1052_595800
  X1[2] = 0;  // @1053_595800
  X1[3] = 0;  // @1054_595800
  eax = 0;  // @1055_595800
  FL[3] = eax;  // @1056_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @1057_595800
  STF((u32)((EBP - 264) + 24), FS[0]);  // @1058_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; });  // @1059_595800
  X0[1] = 0;  // @1060_595800
  X0[2] = 0;  // @1061_595800
  X0[3] = 0;  // @1062_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1063_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; });  // @1064_595800
  X0[1] = 0;  // @1065_595800
  X0[2] = 0;  // @1066_595800
  X0[3] = 0;  // @1067_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 136) + 0), &X0[0], 4);  // @1068_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 76) + 0), 4); v; });  // @1069_595800
  X0[1] = 0;  // @1070_595800
  X0[2] = 0;  // @1071_595800
  X0[3] = 0;  // @1072_595800
  eax = (eax & 0xffffff00u) | (((((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) ? 1 : 0)) & 0xff);  // @1073_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1074_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 140) + 0), &X0[0], 4);  // @1075_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 80) + 0), 4); v; });  // @1076_595800
  X0[1] = 0;  // @1077_595800
  X0[2] = 0;  // @1078_595800
  X0[3] = 0;  // @1079_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 132), &v, sizeof v); }  // @1080_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 144) + 0), &X0[0], 4);  // @1081_595800
  if (FL[0] != FL[1]) goto L596452;  // @1082_595800
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1083_595800
  FL[2] = (eax & eax);  // @1084_595800
  if (FL[2] == 0) goto L59645d;  // @1085_595800
  L596452:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1087_595800
  L59645d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 36) + 0), 4); v; });  // @1089_595800
  X0[1] = 0;  // @1090_595800
  X0[2] = 0;  // @1091_595800
  X0[3] = 0;  // @1092_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 32) + 0), 4); v; });  // @1093_595800
  X1[1] = 0;  // @1094_595800
  X1[2] = 0;  // @1095_595800
  X1[3] = 0;  // @1096_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @1097_595800
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @1098_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 20) + 0), 4); v; });  // @1099_595800
  X0[1] = 0;  // @1100_595800
  X0[2] = 0;  // @1101_595800
  X0[3] = 0;  // @1102_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1103_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5964b2;  // @1104_595800
  edx = (u32)((EBP - 264) + 72);  // @1105_595800
  ecx = (u32)(esi + 20);  // @1106_595800
  FS[0] = ext_4e0830_fastcall2_ld(ecx, edx);  // @1107_595800
  ecx = edx = 0;  // @1108_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 20) + 0), 4); v; });  // @1109_595800
  X0[1] = 0;  // @1110_595800
  X0[2] = 0;  // @1111_595800
  X0[3] = 0;  // @1112_595800
  STF((u32)((EBP - 264) + 24), FS[0]);  // @1113_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; }));  // @1114_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5964b2;  // @1115_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; });  // @1116_595800
  X0[1] = 0;  // @1117_595800
  X0[2] = 0;  // @1118_595800
  X0[3] = 0;  // @1119_595800
  eax = 0;  // @1120_595800
  FL[3] = eax;  // @1121_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }));  // @1122_595800
  eax = (eax & 0xffffff00u) | ((((((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) ? 1 : 0)) & 0xff);  // @1123_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1124_595800
  L5964b2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1126_595800
  eax = (u32)((EBP - 264) + 128);  // @1127_595800
  PV[44] = (u32)(eax);  // @1128_595800
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2024), sizeof v); (u32)v; });  // @1129_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1130_595800
  PV[45] = (u32)(eax);  // @1131_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1132_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[45], PV[44], (u32)(0));  // @1133_595800
  ecx = edx = 0;  // @1134_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; });  // @1135_595800
  X0[1] = 0;  // @1136_595800
  X0[2] = 0;  // @1137_595800
  X0[3] = 0;  // @1138_595800
  X1[0] = 0;  // @1139_595800
  X1[1] = 0;  // @1140_595800
  X1[2] = 0;  // @1141_595800
  X1[3] = 0;  // @1142_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 128), sizeof v); (u32)v; });  // @1143_595800
  __builtin_memcpy((void *)((u32)(esi - 8) + 0), &X0[0], 4);  // @1144_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 76) + 0), 4); v; });  // @1145_595800
  X0[1] = 0;  // @1146_595800
  X0[2] = 0;  // @1147_595800
  X0[3] = 0;  // @1148_595800
  __builtin_memcpy((void *)((u32)(esi - 4) + 0), &X0[0], 4);  // @1149_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 80) + 0), 4); v; });  // @1150_595800
  X0[1] = 0;  // @1151_595800
  X0[2] = 0;  // @1152_595800
  X0[3] = 0;  // @1153_595800
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @1154_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1155_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1156_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @1157_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @1158_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @1159_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @1160_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @1161_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @1162_595800
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @1163_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @1164_595800
  X0[1] = 0;  // @1165_595800
  X0[2] = 0;  // @1166_595800
  X0[3] = 0;  // @1167_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1168_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1169_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1170_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596544;  // @1171_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @1172_595800
  if (FL[2] != 0) goto L596544;  // @1173_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @1174_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @1175_595800
  goto L596568;  // @1176_595800
  L596544:;
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1178_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1179_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1180_595800
  if (!__builtin_parity(FL[2] & 0xff)) goto L59658e;  // @1181_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @1182_595800
  if (FL[2] == 0) goto L59658e;  // @1183_595800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @1184_595800
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @1185_595800
  L596568:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3811), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1187_595800
  if (FL[0] == FL[1]) goto L59658e;  // @1188_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1189_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1190_595800
  eax = (u32)((EBP - 268) + 28);  // @1191_595800
  PV[46] = (u32)(eax);  // @1192_595800
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2026), sizeof v); (u32)v; });  // @1193_595800
  PV[47] = (u32)(eax);  // @1194_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1195_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[47], PV[46], (u32)(0));  // @1196_595800
  ecx = edx = 0;  // @1197_595800
  L59658e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1199_595800
  L596594:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @1201_595800
  esi = (esi + (u32)(48));  // @1202_595800
  FL[3] = esi;  // @1203_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1204_595800
  ecx = (ecx + (u32)(48));  // @1205_595800
  FL[3] = ecx;  // @1206_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @1207_595800
  eax = (u32)(eax + eax*2);  // @1208_595800
  eax = (eax << (u32)(4));  // @1209_595800
  FL[3] = eax;  // @1210_595800
  eax = (eax + (u32)(2586));  // @1211_595800
  FL[3] = eax;  // @1212_595800
  eax = (eax + edi);  // @1213_595800
  FL[3] = eax;  // @1214_595800
  FL[0] = ecx; FL[1] = eax;  // @1215_595800
  if (FL[0] != FL[1]) goto L596330;  // @1216_595800
  L5965bd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @1218_595800
  X0[1] = 0;  // @1219_595800
  X0[2] = 0;  // @1220_595800
  X0[3] = 0;  // @1221_595800
  X1[0] = 0;  // @1222_595800
  X1[1] = 0;  // @1223_595800
  X1[2] = 0;  // @1224_595800
  X1[3] = 0;  // @1225_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1226_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1227_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1228_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596616;  // @1229_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @1230_595800
  X0[1] = 0;  // @1231_595800
  X0[2] = 0;  // @1232_595800
  X0[3] = 0;  // @1233_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1234_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1235_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1236_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596616;  // @1237_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1238_595800
  ecx = edx;  // @1239_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @1240_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @1241_595800
  ecx = edx = 0;  // @1242_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1243_595800
  PV[48] = (u32)(edx);  // @1244_595800
  PV[49] = (u32)(eax);  // @1245_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1246_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[49], PV[48], (u32)(6998712));  // @1247_595800
  ecx = edx = 0;  // @1248_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1249_595800
  X1[0] = 0;  // @1250_595800
  X1[1] = 0;  // @1251_595800
  X1[2] = 0;  // @1252_595800
  X1[3] = 0;  // @1253_595800
  L596616:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @1255_595800
  X0[1] = 0;  // @1256_595800
  X0[2] = 0;  // @1257_595800
  X0[3] = 0;  // @1258_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1259_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1260_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1261_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596663;  // @1262_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @1263_595800
  X0[1] = 0;  // @1264_595800
  X0[2] = 0;  // @1265_595800
  X0[3] = 0;  // @1266_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1267_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1268_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1269_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596663;  // @1270_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1271_595800
  ecx = edx;  // @1272_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @1273_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @1274_595800
  ecx = edx = 0;  // @1275_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1276_595800
  PV[50] = (u32)(edx);  // @1277_595800
  PV[51] = (u32)(eax);  // @1278_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1279_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[51], PV[50], (u32)(6998696));  // @1280_595800
  ecx = edx = 0;  // @1281_595800
  L596663:;
  ext_633654(G(u32, 0x6f5630));  // @1283_595800
  return eax;  // @1284_595800
}
// w3g-disabled: PCREG(595800, lifted_595800_w3gold);

