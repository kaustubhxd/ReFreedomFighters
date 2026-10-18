// batch234025.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" long double FASTCALL ext_4e0870_fastcall2_ld(u32, u32) __asm__("ext_4e0870");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 FASTCALL ext_596680_fastcall2(u32, u32) __asm__("ext_596680");
extern "C" u32 THISCALL ext_467410_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_467410");
extern "C" u32 THISCALL ext_482370_thiscall1(u32) __asm__("ext_482370");
extern "C" u32 THISCALL ext_58ff30_thiscall1(u32) __asm__("ext_58ff30");
extern "C" u32 THISCALL ext_590240_thiscall1(u32) __asm__("ext_590240");
extern "C" u32 THISCALL ext_591190_thiscall1(u32) __asm__("ext_591190");
extern "C" u32 THISCALL ext_591d80_thiscall1(u32) __asm__("ext_591d80");
extern "C" u32 THISCALL ext_591e50_thiscall2(u32, u32) __asm__("ext_591e50");
extern "C" u32 THISCALL ext_592410_thiscall2(u32, u32) __asm__("ext_592410");
extern "C" u32 THISCALL ext_593cc0_thiscall1(u32) __asm__("ext_593cc0");
extern "C" u32 THISCALL ext_595250_thiscall1(u32) __asm__("ext_595250");
extern "C" u32 THISCALL ext_595440_thiscall3(u32, u32, u32) __asm__("ext_595440");
extern "C" u32 THISCALL ext_595800_thiscall1(u32) __asm__("ext_595800");
extern "C" u32 THISCALL ext_596cf0_thiscall1(u32) __asm__("ext_596cf0");
extern "C" u32 THISCALL ext_597720_thiscall2(u32, u32) __asm__("ext_597720");
extern "C" u32 THISCALL ext_59c420_thiscall1(u32) __asm__("ext_59c420");
extern "C" u32 THISCALL ext_59ffc0_thiscall1(u32) __asm__("ext_59ffc0");
extern "C" u32 THISCALL ext_5ab070_thiscall1(u32) __asm__("ext_5ab070");
extern "C" u32 THISCALL ext_5cdb70_thiscall1(u32) __asm__("ext_5cdb70");
extern "C" u32 THISCALL ext_5d2e60_thiscall1(u32) __asm__("ext_5d2e60");
extern "C" u32 THISCALL ext_6474d0_thiscall3(u32, u32, u32) __asm__("ext_6474d0");
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

extern "C" u32 THISCALL lifted_58d000(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[86], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0d0d0d0d, esi = 0x0d0d0d0d, edi = 0x0d0d0d0d;
  { u8 *d_ = (u8 *)((EBP - 144) + 8); const u8 *s_ = (const u8 *)(0x20201000 + 8); u32 n_ = (0x80 - 8) / 4; __asm__ volatile("rep movsl" : "+D"(d_), "+S"(s_), "+c"(n_) : : "memory"); }   // w3i: same per-case garbage as the exe frame (spec fills both)
  edi = ecx;  // @0_58d000
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 144) + 16), &v, sizeof v); }  // @1_58d000
  { u32 v = (u32)((u32)(1045220557)); __builtin_memcpy((void *)(u32)(edi + 2089), &v, sizeof v); }  // @2_58d000
  eax = ext_595800_thiscall1(ecx);  // @3_58d000
  ecx = edx = 0;  // @4_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2087), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @5_58d000
  if (FL[0] == FL[1]) goto L58d041;  // @6_58d000
  ecx = edi;  // @7_58d000
  eax = ext_593cc0_thiscall1(ecx);  // @8_58d000
  ecx = edx = 0;  // @9_58d000
  L58d041:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2138), sizeof v); (u32)v; });  // @11_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @12_58d000
  if (FL[0] == FL[1]) goto L58d061;  // @13_58d000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(2097152))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @14_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @15_58d000
  { u8 v = (u8)((u32)(255)); __builtin_memcpy((void *)(u32)((EBP - 144) + 20), &v, sizeof v); }  // @16_58d000
  goto L58d070;  // @17_58d000
  L58d061:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(4292870143))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @19_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @20_58d000
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 144) + 20), &v, sizeof v); }  // @21_58d000
  L58d070:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_58d000
  ecx = edi;  // @24_58d000
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 20), sizeof v); (u32)v; });  // @25_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 588), sizeof v); (u32)v; });  // @26_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @27_58d000
  ecx = edx = 0;  // @28_58d000
  ecx = eax;  // @29_58d000
  eax = ext_6474d0_thiscall3(ecx, (u32)(1), PV[0]);  // @30_58d000
    // @31_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_58d000
  ecx = edi;  // @33_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @34_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @35_58d000
  ecx = edx = 0;  // @36_58d000
  ecx = edi;  // @37_58d000
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @38_58d000
  if (FL[2] != 0) goto L58d0a2;  // @39_58d000
  eax = ext_482370_thiscall1(ecx);  // @40_58d000
  ecx = edx = 0;  // @41_58d000
  goto L58d0aa;  // @42_58d000
  L58d0a2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_58d000
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1516)))(ecx);  // @45_58d000
  ecx = edx = 0;  // @46_58d000
  L58d0aa:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(4227858431))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @48_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @49_58d000
  ecx = edi;  // @50_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @53_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @54_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1064), sizeof v); (u32)v; });  // @55_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @56_58d000
  ecx = edx = 0;  // @57_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_58d000
  PV[1] = (u32)(eax);  // @59_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @60_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @61_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[1]);  // @62_58d000
  ecx = edx = 0;  // @63_58d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 144) + 12), &v, sizeof v); }  // @64_58d000
  esi = (u32)(6801640);  // @65_58d000
  FL[2] = (eax & eax);  // @66_58d000
  if (FL[2] == 0) goto L58d153;  // @67_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @68_58d000
  ecx = esi;  // @69_58d000
  FL[2] = (edx & edx);  // @70_58d000
  if (FL[2] != 0) ecx = edx;  // @71_58d000
  edx = (u32)(6998720);  // @72_58d000
  eax = ext_4cc850_fastcall2(ecx, edx);  // @73_58d000
  ecx = edx = 0;  // @74_58d000
  FL[2] = (eax & eax);  // @75_58d000
  if (FL[2] != 0) goto L58d110;  // @76_58d000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(67108864))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @77_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @78_58d000
  goto L58d153;  // @79_58d000
  L58d110:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 12), sizeof v); (u32)v; });  // @81_58d000
  ecx = esi;  // @82_58d000
  edx = (u32)(6998732);  // @83_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @84_58d000
  FL[2] = (eax & eax);  // @85_58d000
  if (FL[2] != 0) ecx = eax;  // @86_58d000
  eax = ext_4cc850_fastcall2(ecx, edx);  // @87_58d000
  ecx = edx = 0;  // @88_58d000
  FL[2] = (eax & eax);  // @89_58d000
  if (FL[2] != 0) goto L58d153;  // @90_58d000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) | (u32)(134217728))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @91_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @92_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @94_58d000
  X0[0] = F2U((float)(s32)X0[0]);  // @95_58d000
  X0[1] = F2U((float)(s32)X0[1]);  // @96_58d000
  X0[2] = F2U((float)(s32)X0[2]);  // @97_58d000
  X0[3] = F2U((float)(s32)X0[3]);  // @98_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @99_58d000
  __builtin_memcpy((void *)((u32)(edi + 2550) + 0), &X0[0], 4);  // @100_58d000
  L58d153:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2550) + 0), 4); v; });  // @102_58d000
  X0[1] = 0;  // @103_58d000
  X0[2] = 0;  // @104_58d000
  X0[3] = 0;  // @105_58d000
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @106_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @107_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @108_58d000
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @109_58d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @110_58d000
  if ((s32)FL[0] >= (s32)FL[1]) goto L58d183;  // @111_58d000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(4160749567))); __builtin_memcpy((void *)(u32)(edi + 1047), &v, sizeof v); }  // @112_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @113_58d000
  L58d183:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(134217728));  // @115_58d000
  if (FL[2] == 0) goto L58d19c;  // @116_58d000
  ecx = edi;  // @117_58d000
  eax = ext_595440_thiscall3(ecx, (u32)(1), (u32)(1));  // @118_58d000
  ecx = edx = 0;  // @119_58d000
  goto L58d1e7;  // @120_58d000
  L58d19c:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2102), sizeof v); (u32)v; }) & (u32)(4294967294))); __builtin_memcpy((void *)(u32)(edi + 2102), &v, sizeof v); }  // @122_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2102), sizeof v); (u32)v; });  // @123_58d000
  if (FL[3] == 0) goto L58d1ba;  // @124_58d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2098), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @125_58d000
  if (FL[0] != FL[1]) goto L58d1e7;  // @126_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @127_58d000
  ecx = edi;  // @128_58d000
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1284)))(ecx);  // @129_58d000
  ecx = edx = 0;  // @130_58d000
  goto L58d1e7;  // @131_58d000
  L58d1ba:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2098), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @133_58d000
  if (FL[0] == FL[1]) goto L58d1e7;  // @134_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @135_58d000
  ecx = edi;  // @136_58d000
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 988)))(ecx);  // @137_58d000
  ecx = edx = 0;  // @138_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @139_58d000
  ecx = edi;  // @140_58d000
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2098), sizeof v); (u32)v; });  // @141_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1152)))(ecx, PV[2]);  // @142_58d000
  ecx = edx = 0;  // @143_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2098), &v, sizeof v); }  // @144_58d000
  L58d1e7:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(4194304));  // @146_58d000
  if (FL[2] == 0) goto L58d203;  // @147_58d000
  ecx = edi;  // @148_58d000
  eax = ext_595440_thiscall3(ecx, (u32)(1), (u32)(128));  // @149_58d000
  ecx = edx = 0;  // @150_58d000
  goto L58d251;  // @151_58d000
  L58d203:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2102), sizeof v); (u32)v; }) & (u32)(4294967167))); __builtin_memcpy((void *)(u32)(edi + 2102), &v, sizeof v); }  // @153_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2102), sizeof v); (u32)v; });  // @154_58d000
  if (FL[3] == 0) goto L58d224;  // @155_58d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2098), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @156_58d000
  if (FL[0] != FL[1]) goto L58d251;  // @157_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @158_58d000
  ecx = edi;  // @159_58d000
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1284)))(ecx);  // @160_58d000
  ecx = edx = 0;  // @161_58d000
  goto L58d251;  // @162_58d000
  L58d224:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2098), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @164_58d000
  if (FL[0] == FL[1]) goto L58d251;  // @165_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_58d000
  ecx = edi;  // @167_58d000
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 988)))(ecx);  // @168_58d000
  ecx = edx = 0;  // @169_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @170_58d000
  ecx = edi;  // @171_58d000
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2098), sizeof v); (u32)v; });  // @172_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1152)))(ecx, PV[3]);  // @173_58d000
  ecx = edx = 0;  // @174_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2098), &v, sizeof v); }  // @175_58d000
  L58d251:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @177_58d000
  ecx = edi;  // @178_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @179_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @180_58d000
  ecx = edx = 0;  // @181_58d000
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @182_58d000
  if (FL[2] != 0) goto L58db82;  // @183_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 16), sizeof v); (u32)v; });  // @184_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @185_58d000
  edi = (edi + (u32)(2182));  // @186_58d000
  FL[3] = edi;  // @187_58d000
  PV[4] = (u32)(edi);  // @188_58d000
  eax = (u32)(ecx + 2146);  // @189_58d000
  PV[5] = (u32)(eax);  // @190_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 936), sizeof v); (u32)v; });  // @191_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[5], PV[4]);  // @192_58d000
  ecx = edx = 0;  // @193_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 24), sizeof v); (u32)v; });  // @194_58d000
  PV[6] = (u32)(eax);  // @195_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[6]);  // @196_58d000
  ecx = edx = 0;  // @197_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 16), sizeof v); (u32)v; });  // @198_58d000
  PV[7] = (u32)(edi);  // @199_58d000
  edi = ecx;  // @200_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @201_58d000
  ecx = (u32)(edi + 2146);  // @202_58d000
  PV[8] = (u32)(ecx);  // @203_58d000
  ecx = edi;  // @204_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[8], PV[7]);  // @205_58d000
  ecx = edx = 0;  // @206_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @207_58d000
  eax = (u32)(edi + 2230);  // @208_58d000
  PV[9] = (u32)(eax);  // @209_58d000
  eax = (u32)(edi + 2194);  // @210_58d000
  ecx = edi;  // @211_58d000
  PV[10] = (u32)(eax);  // @212_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[10], PV[9]);  // @213_58d000
  ecx = edx = 0;  // @214_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @215_58d000
  ecx = edi;  // @216_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1284), sizeof v); (u32)v; });  // @217_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @218_58d000
  ecx = edx = 0;  // @219_58d000
  FL[2] = (eax & eax);  // @220_58d000
  if (FL[2] != 0) goto L58d35d;  // @221_58d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2102), sizeof v); (u32)v; }); FL[1] = eax;  // @222_58d000
  if (FL[0] != FL[1]) goto L58d35d;  // @223_58d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2098), sizeof v); (u32)v; }); FL[1] = eax;  // @224_58d000
  if (FL[0] != FL[1]) goto L58d35d;  // @225_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @226_58d000
  ecx = edi;  // @227_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1008), sizeof v); (u32)v; });  // @228_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @229_58d000
  ecx = edx = 0;  // @230_58d000
  FL[2] = (eax & eax);  // @231_58d000
  if (FL[2] != 0) goto L58d35d;  // @232_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @233_58d000
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2106), sizeof v); (u32)v; });  // @234_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @235_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @236_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @237_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[11]);  // @238_58d000
  ecx = edx = 0;  // @239_58d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 144) + 12), &v, sizeof v); }  // @240_58d000
  FL[2] = (eax & eax);  // @241_58d000
  if (FL[2] == 0) goto L58d324;  // @242_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @243_58d000
  ecx = eax;  // @244_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 756), sizeof v); (u32)v; });  // @245_58d000
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @246_58d000
  ecx = edx = 0;  // @247_58d000
  FL[0] = eax; FL[1] = edi;  // @248_58d000
  if (FL[0] == FL[1]) goto L58d331;  // @249_58d000
  L58d324:;
  ecx = edi;  // @251_58d000
  eax = ext_591e50_thiscall2(ecx, (u32)(1));  // @252_58d000
  ecx = edx = 0;  // @253_58d000
  edx = eax;  // @254_58d000
  goto L58d335;  // @255_58d000
  L58d331:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 12), sizeof v); (u32)v; });  // @257_58d000
  L58d335:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @259_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @260_58d000
  PV[12] = (u32)(edx);  // @261_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @262_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @263_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; });  // @264_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[12]);  // @265_58d000
  ecx = edx = 0;  // @266_58d000
  PV[13] = (u32)(eax);  // @267_58d000
  ecx = edi;  // @268_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1152)))(ecx, PV[13]);  // @269_58d000
  ecx = edx = 0;  // @270_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2106), &v, sizeof v); }  // @271_58d000
  L58d35d:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(262144));  // @273_58d000
  if (FL[2] == 0) goto L58d36f;  // @274_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @275_58d000
  if (FL[0] == FL[1]) goto L58d3b0;  // @276_58d000
  L58d36f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @278_58d000
  ecx = edi;  // @279_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1616), sizeof v); (u32)v; });  // @280_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @281_58d000
  ecx = edx = 0;  // @282_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @283_58d000
  esi = eax;  // @284_58d000
  PV[14] = (u32)(esi);  // @285_58d000
  ecx = edi;  // @286_58d000
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 148) + 16), &v, sizeof v); }  // @287_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 1644)))(ecx, PV[14]);  // @288_58d000
  ecx = edx = 0;  // @289_58d000
  FL[2] = (esi & esi);  // @290_58d000
  if (FL[2] == 0) goto L58d3b0;  // @291_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @292_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @293_58d000
  PV[15] = (u32)(edi);  // @294_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @295_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @296_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; });  // @297_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[15]);  // @298_58d000
  ecx = edx = 0;  // @299_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 12), sizeof v); (u32)v; });  // @300_58d000
  PV[16] = (u32)(eax);  // @301_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 144)))(ecx, PV[16]);  // @302_58d000
  ecx = edx = 0;  // @303_58d000
  L58d3b0:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(268435456));  // @305_58d000
  if (FL[2] != 0) goto L58d3ce;  // @306_58d000
  ecx = edi;  // @307_58d000
  eax = ext_58ff30_thiscall1(ecx);  // @308_58d000
  ecx = edx = 0;  // @309_58d000
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @310_58d000
  if (FL[2] != 0) goto L58d3ce;  // @311_58d000
  ecx = edi;  // @312_58d000
  eax = ext_590240_thiscall1(ecx);  // @313_58d000
  ecx = edx = 0;  // @314_58d000
  L58d3ce:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @316_58d000
  ecx = edi;  // @317_58d000
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1040)))(ecx);  // @318_58d000
  ecx = edx = 0;  // @319_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2110), sizeof v); (u32)v; });  // @320_58d000
  FL[2] = (edx & edx);  // @321_58d000
  if (FL[2] == 0) goto L58d48a;  // @322_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @323_58d000
  PV[17] = (u32)(edx);  // @324_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @325_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @326_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @327_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[17]);  // @328_58d000
  ecx = edx = 0;  // @329_58d000
  ecx = eax;  // @330_58d000
  FL[2] = (ecx & ecx);  // @331_58d000
  if (FL[2] == 0) goto L58d48a;  // @332_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @333_58d000
  edx = (u32)((EBP - 144) + 52);  // @334_58d000
  PV[18] = (u32)(edx);  // @335_58d000
  edx = (u32)((EBP - 148) + 108);  // @336_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 56), &v, sizeof v); }  // @337_58d000
  PV[19] = (u32)(edx);  // @338_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 152) + 64), &v, sizeof v); }  // @339_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 152) + 68), &v, sizeof v); }  // @340_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 152) + 72), &v, sizeof v); }  // @341_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 152) + 76), &v, sizeof v); }  // @342_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 152) + 80), &v, sizeof v); }  // @343_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 708)))(ecx, PV[19], PV[18]);  // @344_58d000
  ecx = edx = 0;  // @345_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @346_58d000
  ecx = (u32)((EBP - 144) + 64);  // @347_58d000
  PV[20] = (u32)(ecx);  // @348_58d000
  ecx = edi;  // @349_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[20]);  // @350_58d000
  ecx = edx = 0;  // @351_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 68) + 0), 4); v; });  // @352_58d000
  X0[1] = 0;  // @353_58d000
  X0[2] = 0;  // @354_58d000
  X0[3] = 0;  // @355_58d000
  edx = (u32)((EBP - 144) + 64);  // @356_58d000
  ecx = (u32)((EBP - 144) + 52);  // @357_58d000
  __builtin_memcpy((void *)((u32)((EBP - 144) + 56) + 0), &X0[0], 4);  // @358_58d000
  FS[0] = ext_4e0870_fastcall2_ld(ecx, edx);  // @359_58d000
  ecx = edx = 0;  // @360_58d000
  STF((u32)((EBP - 144) + 12), FS[0]);  // @361_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 12) + 0), 4); v; });  // @362_58d000
  X0[1] = 0;  // @363_58d000
  X0[2] = 0;  // @364_58d000
  X0[3] = 0;  // @365_58d000
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860564) + 0), 4); v; }));  // @366_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d48a;  // @367_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2110), &v, sizeof v); }  // @368_58d000
  L58d48a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2138), sizeof v); (u32)v; });  // @370_58d000
  FL[2] = (ecx & ecx);  // @371_58d000
  if (FL[2] == 0) goto L58d499;  // @372_58d000
  eax = ext_5d2e60_thiscall1(ecx);  // @373_58d000
    // @374_58d000
  L58d499:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @376_58d000
  ecx = edi;  // @377_58d000
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1192)))(ecx);  // @378_58d000
  ecx = edx = 0;  // @379_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @380_58d000
  ecx = (u32)((EBP - 144) + 76);  // @381_58d000
  PV[21] = (u32)(ecx);  // @382_58d000
  ecx = edi;  // @383_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 80), &v, sizeof v); }  // @384_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 84), &v, sizeof v); }  // @385_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 88), &v, sizeof v); }  // @386_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[21]);  // @387_58d000
  ecx = edx = 0;  // @388_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @389_58d000
  eax = (u32)((EBP - 144) + 32);  // @390_58d000
  PV[22] = (u32)(eax);  // @391_58d000
  eax = ext_597720_thiscall2(ecx, PV[22]);  // @392_58d000
  ecx = edx = 0;  // @393_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; });  // @394_58d000
  X0[1] = 0;  // @395_58d000
  X0[2] = 0;  // @396_58d000
  X0[3] = 0;  // @397_58d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 144) + 20), &v, sizeof v); }  // @398_58d000
  FL[2] = (eax & eax);  // @399_58d000
  if (FL[2] == 0) goto L58d60d;  // @400_58d000
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 32) + 0), 4); v; });  // @401_58d000
  X1[1] = 0;  // @402_58d000
  X1[2] = 0;  // @403_58d000
  X1[3] = 0;  // @404_58d000
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @405_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d52b;  // @406_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2523) + 0), 4); v; });  // @407_58d000
  X0[1] = 0;  // @408_58d000
  X0[2] = 0;  // @409_58d000
  X0[3] = 0;  // @410_58d000
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @411_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d60d;  // @412_58d000
  __builtin_memcpy((void *)((u32)(edi + 2523) + 0), &X1[0], 4);  // @413_58d000
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(edi + 2519), &v, sizeof v); }  // @414_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2527), &v, sizeof v); }  // @415_58d000
  goto L58d60d;  // @416_58d000
  L58d52b:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3821), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @418_58d000
  if (FL[0] == FL[1]) goto L58d60d;  // @419_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6993888) + 0), 4); v; });  // @420_58d000
  X0[1] = 0;  // @421_58d000
  X0[2] = 0;  // @422_58d000
  X0[3] = 0;  // @423_58d000
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @424_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d60d;  // @425_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @426_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @427_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @428_58d000
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6997712), (u32)(2114));  // @429_58d000
  ecx = edx = 0;  // @430_58d000
  STF((u32)((EBP - 144) + 12), FS[0]);  // @431_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 12) + 0), 4); v; });  // @432_58d000
  X0[1] = 0;  // @433_58d000
  X0[2] = 0;  // @434_58d000
  X0[3] = 0;  // @435_58d000
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829928) + 0), 4); v; }));  // @436_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d60d;  // @437_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @438_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8110), sizeof v); (u32)v; });  // @439_58d000
  eax = ext_596cf0_thiscall1(ecx);  // @440_58d000
    // @441_58d000
  FL[0] = esi; FL[1] = eax;  // @442_58d000
  if ((s32)FL[0] >= (s32)FL[1]) goto L58d60d;  // @443_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @444_58d000
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 20), sizeof v); (u32)v; });  // @445_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @446_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @447_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @448_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[23]);  // @449_58d000
  ecx = edx = 0;  // @450_58d000
  esi = eax;  // @451_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 144) + 64), &v, sizeof v); }  // @452_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 144) + 68), &v, sizeof v); }  // @453_58d000
  eax = (u32)((EBP - 144) + 64);  // @454_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 144) + 72), &v, sizeof v); }  // @455_58d000
  ecx = esi;  // @456_58d000
  PV[24] = (u32)(eax);  // @457_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @458_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[24]);  // @459_58d000
  ecx = edx = 0;  // @460_58d000
  eax = (u32)((EBP - 144) + 64);  // @461_58d000
  PV[25] = (u32)(eax);  // @462_58d000
  edx = (u32)((EBP - 148) + 80);  // @463_58d000
  ecx = (u32)((EBP - 148) + 92);  // @464_58d000
  eax = ext_43e920_fastcall3(ecx, edx, PV[25]);  // @465_58d000
  ecx = edx = 0;  // @466_58d000
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 92) + 0), 4); v; });  // @467_58d000
  X1[1] = 0;  // @468_58d000
  X1[2] = 0;  // @469_58d000
  X1[3] = 0;  // @470_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000584) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000584) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @471_58d000
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @472_58d000
  X1[0] = X1[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @473_58d000
  X1[1] = X1[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @474_58d000
  X1[2] = X1[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @475_58d000
  X1[3] = X1[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @476_58d000
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @477_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d60d;  // @478_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @479_58d000
  ecx = esi;  // @480_58d000
  PV[26] = (u32)(edi);  // @481_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1768)))(ecx, (u32)(31), (u32)(1), PV[26]);  // @482_58d000
  ecx = edx = 0;  // @483_58d000
  L58d60d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2536), sizeof v); (u32)v; });  // @485_58d000
  FL[2] = (ecx & ecx);  // @486_58d000
  if (FL[2] == 0) goto L58da55;  // @487_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @488_58d000
  edx = (u32)(4);  // @489_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6994864) + 0), 4); v; });  // @490_58d000
  X0[1] = 0;  // @491_58d000
  X0[2] = 0;  // @492_58d000
  X0[3] = 0;  // @493_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2540), &v, sizeof v); }  // @494_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2544), &v, sizeof v); }  // @495_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @496_58d000
  edx = (edx | (1u << (eax & 31)));  // @497_58d000
  PV[27] = (u32)(edx);  // @498_58d000
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 148) + 40), &v, sizeof v); }  // @499_58d000
  edx = (u32)((EBP - 148) + 16);  // @500_58d000
  PV[28] = (u32)(edx);  // @501_58d000
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)((EBP - 152) + 20), &v, sizeof v); }  // @502_58d000
  edx = (u32)((EBP - 152) + 84);  // @503_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @504_58d000
  PV[29] = (u32)(ecx);  // @505_58d000
  PV[30] = (u32)(edx);  // @506_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 132), sizeof v); (u32)v; });  // @507_58d000
  __builtin_memcpy((void *)((u32)((EBP - 160) + 44) + 0), &X0[0], 4);  // @508_58d000
  __builtin_memcpy((void *)((u32)((EBP - 160) + 36) + 0), &X0[0], 4);  // @509_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[30], (u32)(1128792064), PV[28], PV[27]);  // @510_58d000
  ecx = edx = 0;  // @511_58d000
  esi = eax;  // @512_58d000
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 144) + 16), &v, sizeof v); }  // @513_58d000
  FL[2] = (esi & esi);  // @514_58d000
  if (FL[2] == 0) goto L58d7e9;  // @515_58d000
  L58d690:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @517_58d000
  ecx = esi;  // @518_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @519_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2099193));  // @520_58d000
  ecx = edx = 0;  // @521_58d000
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @522_58d000
  if (FL[2] == 0) goto L58d7b5;  // @523_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @524_58d000
  ecx = esi;  // @525_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @526_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @527_58d000
  ecx = edx = 0;  // @528_58d000
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @529_58d000
  if (FL[2] != 0) goto L58d7b5;  // @530_58d000
  ecx = esi;  // @531_58d000
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)((EBP - 144) + 11), &v, sizeof v); }  // @532_58d000
  eax = ext_59ffc0_thiscall1(ecx);  // @533_58d000
    // @534_58d000
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 11), sizeof v); (u32)v; });  // @535_58d000
  FL[0] = eax; FL[1] = (u32)(5);  // @536_58d000
  eax = (u32)(1);  // @537_58d000
  if (FL[0] == FL[1]) ecx = eax;  // @538_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @539_58d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 144) + 24), &v, sizeof v); }  // @540_58d000
  ecx = esi;  // @541_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1704), sizeof v); (u32)v; });  // @542_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @543_58d000
  ecx = edx = 0;  // @544_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 16), sizeof v); (u32)v; });  // @545_58d000
  esi = eax;  // @546_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @547_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1652), sizeof v); (u32)v; });  // @548_58d000
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @549_58d000
  ecx = edx = 0;  // @550_58d000
  FL[0] = eax; FL[1] = esi;  // @551_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 16), sizeof v); (u32)v; });  // @552_58d000
  if ((s32)FL[0] >= (s32)FL[1]) goto L58d710;  // @553_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @554_58d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @555_58d000
  if (FL[0] != FL[1]) goto L58d710;  // @556_58d000
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 144) + 24), &v, sizeof v); }  // @557_58d000
  goto L58d724;  // @558_58d000
  L58d710:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @560_58d000
  if (FL[0] != FL[1]) goto L58d724;  // @561_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2336), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @562_58d000
  if (FL[0] == FL[1]) goto L58d7b5;  // @563_58d000
  L58d724:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @565_58d000
  ecx = (u32)((EBP - 144) + 52);  // @566_58d000
  PV[31] = (u32)(ecx);  // @567_58d000
  ecx = esi;  // @568_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 56), &v, sizeof v); }  // @569_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 60), &v, sizeof v); }  // @570_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 64), &v, sizeof v); }  // @571_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[31]);  // @572_58d000
  ecx = edx = 0;  // @573_58d000
  edx = (u32)((EBP - 144) + 76);  // @574_58d000
  ecx = (u32)((EBP - 144) + 52);  // @575_58d000
  eax = ext_43e960_fastcall2(ecx, edx);  // @576_58d000
  ecx = edx = 0;  // @577_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @578_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 52) + 0), 4); v; });  // @579_58d000
  X0[1] = 0;  // @580_58d000
  X0[2] = 0;  // @581_58d000
  X0[3] = 0;  // @582_58d000
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 56) + 0), 4); v; });  // @583_58d000
  X1[1] = 0;  // @584_58d000
  X1[2] = 0;  // @585_58d000
  X1[3] = 0;  // @586_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @587_58d000
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @588_58d000
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @589_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 60) + 0), 4); v; });  // @590_58d000
  X0[1] = 0;  // @591_58d000
  X0[2] = 0;  // @592_58d000
  X0[3] = 0;  // @593_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @594_58d000
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @595_58d000
  if (FL[0] == FL[1]) goto L58d79e;  // @596_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 20) + 0), 4); v; });  // @597_58d000
  X0[1] = 0;  // @598_58d000
  X0[2] = 0;  // @599_58d000
  X0[3] = 0;  // @600_58d000
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @601_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d7b5;  // @602_58d000
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 2544), &v, sizeof v); }  // @603_58d000
  __builtin_memcpy((void *)((u32)((EBP - 144) + 20) + 0), &X1[0], 4);  // @604_58d000
  goto L58d7b5;  // @605_58d000
  L58d79e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 28) + 0), 4); v; });  // @607_58d000
  X0[1] = 0;  // @608_58d000
  X0[2] = 0;  // @609_58d000
  X0[3] = 0;  // @610_58d000
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @611_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d7b5;  // @612_58d000
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 2540), &v, sizeof v); }  // @613_58d000
  __builtin_memcpy((void *)((u32)((EBP - 144) + 28) + 0), &X1[0], 4);  // @614_58d000
  L58d7b5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2536), sizeof v); (u32)v; });  // @616_58d000
  edx = (u32)((EBP - 144) + 12);  // @617_58d000
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 36), sizeof v); (u32)v; });  // @618_58d000
  PV[33] = (u32)(edx);  // @619_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @620_58d000
  edx = (u32)((EBP - 152) + 84);  // @621_58d000
  PV[34] = (u32)(ecx);  // @622_58d000
  PV[35] = (u32)(edx);  // @623_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 132), sizeof v); (u32)v; });  // @624_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[35], (u32)(1128792064), PV[33], PV[32]);  // @625_58d000
  ecx = edx = 0;  // @626_58d000
  esi = eax;  // @627_58d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 144) + 16), &v, sizeof v); }  // @628_58d000
  FL[2] = (esi & esi);  // @629_58d000
  if (FL[2] != 0) goto L58d690;  // @630_58d000
  L58d7e9:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2540), sizeof v); (u32)v; });  // @632_58d000
  FL[2] = (esi & esi);  // @633_58d000
  if (FL[2] == 0) goto L58d858;  // @634_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 28) + 0), 4); v; });  // @635_58d000
  X0[1] = 0;  // @636_58d000
  X0[2] = 0;  // @637_58d000
  X0[3] = 0;  // @638_58d000
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @639_58d000
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @640_58d000
  ecx = edx = 0;  // @641_58d000
  X1[0] = 0;  // @642_58d000
  X1[1] = 0;  // @643_58d000
  X1[2] = 0;  // @644_58d000
  X1[3] = 0;  // @645_58d000
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @646_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2523) + 0), 4); v; });  // @647_58d000
  X0[1] = 0;  // @648_58d000
  X0[2] = 0;  // @649_58d000
  X0[3] = 0;  // @650_58d000
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @651_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d831;  // @652_58d000
  __builtin_memcpy((void *)((u32)(edi + 2523) + 0), &X1[0], 4);  // @653_58d000
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(edi + 2519), &v, sizeof v); }  // @654_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2527), &v, sizeof v); }  // @655_58d000
  L58d831:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2515), sizeof v); (u32)v; }); FL[1] = (u32)(7);  // @657_58d000
  if (FL[0] != FL[1]) goto L58d858;  // @658_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1644), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @659_58d000
  if (FL[0] == FL[1]) goto L58d858;  // @660_58d000
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2012), sizeof v); (u32)v; });  // @661_58d000
  ecx = edi;  // @662_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @663_58d000
  PV[36] = (u32)(eax);  // @664_58d000
  PV[37] = (u32)(esi);  // @665_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[37], PV[36], (u32)(0));  // @666_58d000
  ecx = edx = 0;  // @667_58d000
  L58d858:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2544), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @669_58d000
  if (FL[0] == FL[1]) goto L58da55;  // @670_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @671_58d000
  ecx = edi;  // @672_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1284), sizeof v); (u32)v; });  // @673_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @674_58d000
  ecx = edx = 0;  // @675_58d000
  esi = eax;  // @676_58d000
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @677_58d000
  FL[3] = (eax & 0xff);  // @678_58d000
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)((EBP - 144) + 11), &v, sizeof v); }  // @679_58d000
  FL[2] = (esi & esi);  // @680_58d000
  if (FL[2] == 0) goto L58d8d1;  // @681_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @682_58d000
  ecx = esi;  // @683_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 744), sizeof v); (u32)v; });  // @684_58d000
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @685_58d000
  ecx = edx = 0;  // @686_58d000
  ecx = (u32)(6801640);  // @687_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @688_58d000
  FL[2] = (eax & eax);  // @689_58d000
  if (FL[2] != 0) ecx = eax;  // @690_58d000
  eax = (u32)(6998788);  // @691_58d000
  L58d8a0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @693_58d000
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @694_58d000
  if (FL[0] != FL[1]) goto L58d8c0;  // @695_58d000
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @696_58d000
  if (FL[2] == 0) goto L58d8bc;  // @697_58d000
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @698_58d000
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @699_58d000
  if (FL[0] != FL[1]) goto L58d8c0;  // @700_58d000
  ecx = (ecx + (u32)(2));  // @701_58d000
  FL[3] = ecx;  // @702_58d000
  eax = (eax + (u32)(2));  // @703_58d000
  FL[3] = eax;  // @704_58d000
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @705_58d000
  if (FL[2] != 0) goto L58d8a0;  // @706_58d000
  L58d8bc:;
  eax = 0;  // @708_58d000
  FL[3] = eax;  // @709_58d000
  goto L58d8c5;  // @710_58d000
  L58d8c0:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @712_58d000
  eax = (eax | (u32)(1));  // @713_58d000
  FL[3] = eax;  // @714_58d000
  L58d8c5:;
  FL[2] = (eax & eax);  // @716_58d000
  if (FL[2] != 0) goto L58d8d1;  // @717_58d000
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @718_58d000
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)((EBP - 144) + 11), &v, sizeof v); }  // @719_58d000
  goto L58d8de;  // @720_58d000
  L58d8d1:;
  ecx = edi;  // @722_58d000
  eax = ext_591d80_thiscall1(ecx);  // @723_58d000
  ecx = edx = 0;  // @724_58d000
  esi = eax;  // @725_58d000
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 11), sizeof v); (u32)v; })) & 0xff);  // @726_58d000
  L58d8de:;
  FL[2] = (esi & esi);  // @728_58d000
  if (FL[2] != 0) goto L58d8f2;  // @729_58d000
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @730_58d000
  if (FL[2] != 0) goto L58d8f2;  // @731_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2548), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @732_58d000
  if (FL[0] == FL[1]) goto L58da55;  // @733_58d000
  L58d8f2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 20) + 0), 4); v; });  // @735_58d000
  X0[1] = 0;  // @736_58d000
  X0[2] = 0;  // @737_58d000
  X0[3] = 0;  // @738_58d000
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @739_58d000
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @740_58d000
  ecx = edx = 0;  // @741_58d000
  X1[0] = 0;  // @742_58d000
  X1[1] = 0;  // @743_58d000
  X1[2] = 0;  // @744_58d000
  X1[3] = 0;  // @745_58d000
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @746_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2523) + 0), 4); v; });  // @747_58d000
  X0[1] = 0;  // @748_58d000
  X0[2] = 0;  // @749_58d000
  X0[3] = 0;  // @750_58d000
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @751_58d000
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58d930;  // @752_58d000
  __builtin_memcpy((void *)((u32)(edi + 2523) + 0), &X1[0], 4);  // @753_58d000
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(edi + 2519), &v, sizeof v); }  // @754_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2527), &v, sizeof v); }  // @755_58d000
  L58d930:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2515), sizeof v); (u32)v; }); FL[1] = (u32)(15);  // @757_58d000
  if (FL[0] != FL[1]) goto L58da55;  // @758_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1644), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @759_58d000
  if (FL[0] == FL[1]) goto L58da55;  // @760_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @761_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 7439), sizeof v); (u32)v; });  // @762_58d000
  eax = ext_5ab070_thiscall1(ecx);  // @763_58d000
    // @764_58d000
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 11), sizeof v); (u32)v; })) & 0xff);  // @765_58d000
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @766_58d000
  if (FL[2] == 0) goto L58d9f3;  // @767_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 160) + 104), &v, sizeof v); }  // @768_58d000
  eax = 0;  // @769_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 160) + 108), &v, sizeof v); }  // @770_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 160) + 112), &v, sizeof v); }  // @771_58d000
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)((EBP - 160) + 116), &v, sizeof v); }  // @772_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 160) + 104) + 0), 4); v; });  // @773_58d000
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 160) + 104) + 4), 4); v; });  // @774_58d000
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 160) + 104) + 8), 4); v; });  // @775_58d000
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 160) + 104) + 12), 4); v; });  // @776_58d000
  PV[38] = (u32)(ecx);  // @777_58d000
  ecx = edi;  // @778_58d000
  PV[39] = X0[0];  // @779_58d000
  PV[40] = X0[1];  // @780_58d000
  PV[41] = X0[2];  // @781_58d000
  PV[42] = X0[3];  // @782_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @783_58d000
  PV[43] = (u32)(edi);  // @784_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1272), sizeof v); (u32)v; });  // @785_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @786_58d000
  ecx = edx = 0;  // @787_58d000
  ecx = (u32)(eax + 4);  // @788_58d000
  eax = ext_467410_thiscall7(ecx, PV[43], (u32)(0), PV[39], PV[40], PV[41], PV[42]);  // @789_58d000
  ecx = edx = 0;  // @790_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @791_58d000
  ecx = edi;  // @792_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1272), sizeof v); (u32)v; });  // @793_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @794_58d000
  ecx = edx = 0;  // @795_58d000
  PV[44] = (u32)(edi);  // @796_58d000
  ecx = eax;  // @797_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @798_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 8)))(ecx, PV[44], (u32)(0));  // @799_58d000
  ecx = edx = 0;  // @800_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @801_58d000
  ecx = esi;  // @802_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(3), (u32)(0));  // @803_58d000
  ecx = edx = 0;  // @804_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @805_58d000
  ecx = esi;  // @806_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 752)))(ecx, (u32)(0), (u32)(0), (u32)(1));  // @807_58d000
  ecx = edx = 0;  // @808_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @809_58d000
  ecx = esi;  // @810_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @811_58d000
  ecx = edx = 0;  // @812_58d000
  goto L58da41;  // @813_58d000
  L58d9f3:;
  FL[2] = (esi & esi);  // @815_58d000
  if (FL[2] == 0) goto L58da41;  // @816_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @817_58d000
  PV[45] = (u32)(esi);  // @818_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @819_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @820_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; });  // @821_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[45]);  // @822_58d000
  ecx = edx = 0;  // @823_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @824_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @825_58d000
  PV[46] = (u32)(eax);  // @826_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @827_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @828_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @829_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, (u32)(6850920), (u32)(0), (u32)(6997712), (u32)(2246), PV[46]);  // @830_58d000
  ecx = edx = 0;  // @831_58d000
  eax = (eax & 0xffff);  // @832_58d000
  ecx = edi;  // @833_58d000
  PV[47] = (u32)(eax);  // @834_58d000
  PV[48] = (u32)(edi);  // @835_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, PV[48], PV[47]);  // @836_58d000
  ecx = edx = 0;  // @837_58d000
  L58da41:;
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2544), sizeof v); (u32)v; });  // @839_58d000
  ecx = edi;  // @840_58d000
  eax = ext_592410_thiscall2(ecx, PV[49]);  // @841_58d000
  ecx = edx = 0;  // @842_58d000
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1643), &v, sizeof v); }  // @843_58d000
  L58da55:;
  ecx = edi;  // @845_58d000
  eax = ext_591190_thiscall1(ecx);  // @846_58d000
  ecx = edx = 0;  // @847_58d000
  ecx = edi;  // @848_58d000
  eax = ext_596680_fastcall2(ecx, edx);  // @849_58d000
  ecx = edx = 0;  // @850_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @851_58d000
  edx = (u32)(edi + 2362);  // @852_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @853_58d000
  ecx = (ecx + (u32)(64));  // @854_58d000
  FL[3] = ecx;  // @855_58d000
  eax = (eax + (u32)(102));  // @856_58d000
  FL[3] = eax;  // @857_58d000
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @858_58d000
  if ((s32)FL[0] >= (s32)FL[1]) goto L58df0a;  // @859_58d000
  FL[0] = edx; FL[1] = ecx;  // @860_58d000
  if (FL[0] == FL[1]) goto L58da87;  // @861_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @862_58d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @863_58d000
  L58da87:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @865_58d000
  ecx = (u32)((EBP - 144) + 52);  // @866_58d000
  PV[50] = (u32)(ecx);  // @867_58d000
  ecx = edi;  // @868_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 64), &v, sizeof v); }  // @869_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 60), &v, sizeof v); }  // @870_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 56), &v, sizeof v); }  // @871_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[50]);  // @872_58d000
  ecx = edx = 0;  // @873_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2366), sizeof v); (u32)v; });  // @874_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 52) + 0), 4); v; });  // @875_58d000
  X0[1] = 0;  // @876_58d000
  X0[2] = 0;  // @877_58d000
  X0[3] = 0;  // @878_58d000
  ecx = (u32)(eax + eax*2);  // @879_58d000
  eax = (eax + 1);  // @880_58d000
  FL[3] = eax;  // @881_58d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2366), &v, sizeof v); }  // @882_58d000
  __builtin_memcpy((void *)((u32)(edi + ecx*4 + 2242) + 0), &X0[0], 4);  // @883_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 56) + 0), 4); v; });  // @884_58d000
  X0[1] = 0;  // @885_58d000
  X0[2] = 0;  // @886_58d000
  X0[3] = 0;  // @887_58d000
  __builtin_memcpy((void *)((u32)(edi + ecx*4 + 2246) + 0), &X0[0], 4);  // @888_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 60) + 0), 4); v; });  // @889_58d000
  X0[1] = 0;  // @890_58d000
  X0[2] = 0;  // @891_58d000
  X0[3] = 0;  // @892_58d000
  __builtin_memcpy((void *)((u32)(edi + ecx*4 + 2250) + 0), &X0[0], 4);  // @893_58d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2366), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @894_58d000
  if (FL[0] != FL[1]) goto L58dafe;  // @895_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2366), &v, sizeof v); }  // @896_58d000
  L58dafe:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2370), &v, sizeof v); }  // @898_58d000
  edx = (u32)(edi + 2242);  // @899_58d000
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)((EBP - 144) + 12), &v, sizeof v); }  // @900_58d000
  L58db16:;
  esi = (u32)(edx + 12);  // @902_58d000
  PV[51] = (u32)(esi);  // @903_58d000
  ecx = (u32)((EBP - 148) + 56);  // @904_58d000
  eax = ext_43e920_fastcall3(ecx, edx, PV[51]);  // @905_58d000
  ecx = edx = 0;  // @906_58d000
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 52) + 0), 4); v; });  // @907_58d000
  X1[1] = 0;  // @908_58d000
  X1[2] = 0;  // @909_58d000
  X1[3] = 0;  // @910_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 56) + 0), 4); v; });  // @911_58d000
  X0[1] = 0;  // @912_58d000
  X0[2] = 0;  // @913_58d000
  X0[3] = 0;  // @914_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @915_58d000
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @916_58d000
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @917_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 60) + 0), 4); v; });  // @918_58d000
  X0[1] = 0;  // @919_58d000
  X0[2] = 0;  // @920_58d000
  X0[3] = 0;  // @921_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @922_58d000
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @923_58d000
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @924_58d000
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @925_58d000
  ecx = edx = 0;  // @926_58d000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 12), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)((EBP - 144) + 12), &v, sizeof v); }  // @927_58d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 12), sizeof v); (u32)v; });  // @928_58d000
  edx = esi;  // @929_58d000
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @930_58d000
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2370) + 0), 4); v; })));  // @931_58d000
  __builtin_memcpy((void *)((u32)(edi + 2370) + 0), &X0[0], 4);  // @932_58d000
  if (FL[3] != 0) goto L58db16;  // @933_58d000
  ext_633654(G(u32, 0x6f5630));  // @934_58d000
  return eax;  // @935_58d000
  L58db82:;
  ecx = edi;  // @937_58d000
  eax = ext_595250_thiscall1(ecx);  // @938_58d000
  ecx = edx = 0;  // @939_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @940_58d000
  ecx = edi;  // @941_58d000
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 840)))(ecx);  // @942_58d000
  ecx = edx = 0;  // @943_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @944_58d000
  ecx = (u32)((EBP - 144) + 88);  // @945_58d000
  PV[52] = (u32)(ecx);  // @946_58d000
  ecx = (u32)((EBP - 148) + 108);  // @947_58d000
  PV[53] = (u32)(ecx);  // @948_58d000
  ecx = edi;  // @949_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 900)))(ecx, PV[53], PV[52]);  // @950_58d000
  ecx = edx = 0;  // @951_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @952_58d000
  X0[1] = 0;  // @953_58d000
  X0[2] = 0;  // @954_58d000
  X0[3] = 0;  // @955_58d000
  edx = (u32)((EBP - 144) + 104);  // @956_58d000
  __builtin_memcpy((void *)((u32)((EBP - 144) + 40) + 0), &X0[0], 4);  // @957_58d000
  ecx = (u32)((EBP - 144) + 40);  // @958_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; });  // @959_58d000
  X0[1] = 0;  // @960_58d000
  X0[2] = 0;  // @961_58d000
  X0[3] = 0;  // @962_58d000
  __builtin_memcpy((void *)((u32)((EBP - 144) + 44) + 0), &X0[0], 4);  // @963_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 80) + 0), 4); v; });  // @964_58d000
  X0[1] = 0;  // @965_58d000
  X0[2] = 0;  // @966_58d000
  X0[3] = 0;  // @967_58d000
  __builtin_memcpy((void *)((u32)((EBP - 144) + 48) + 0), &X0[0], 4);  // @968_58d000
  eax = ext_4419f0_fastcall2(ecx, edx);  // @969_58d000
  ecx = edx = 0;  // @970_58d000
  edx = (u32)((EBP - 144) + 40);  // @971_58d000
  ecx = (u32)((EBP - 144) + 88);  // @972_58d000
  eax = ext_441940_fastcall2(ecx, edx);  // @973_58d000
  ecx = edx = 0;  // @974_58d000
  edx = (u32)(edi + 36);  // @975_58d000
  ecx = (u32)((EBP - 144) + 104);  // @976_58d000
  eax = ext_4de480_fastcall2(ecx, edx);  // @977_58d000
  ecx = edx = 0;  // @978_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @979_58d000
  ecx = (u32)((EBP - 144) + 88);  // @980_58d000
  PV[54] = (u32)(ecx);  // @981_58d000
  ecx = (u32)((EBP - 148) + 108);  // @982_58d000
  PV[55] = (u32)(ecx);  // @983_58d000
  ecx = edi;  // @984_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1520)))(ecx, PV[55], PV[54]);  // @985_58d000
  ecx = edx = 0;  // @986_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 16), sizeof v); (u32)v; });  // @987_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @988_58d000
  edi = (edi + (u32)(2182));  // @989_58d000
  FL[3] = edi;  // @990_58d000
  PV[56] = (u32)(edi);  // @991_58d000
  eax = (u32)(ecx + 2146);  // @992_58d000
  PV[57] = (u32)(eax);  // @993_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 936), sizeof v); (u32)v; });  // @994_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[57], PV[56]);  // @995_58d000
  ecx = edx = 0;  // @996_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 24), sizeof v); (u32)v; });  // @997_58d000
  PV[58] = (u32)(eax);  // @998_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[58]);  // @999_58d000
  ecx = edx = 0;  // @1000_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 16), sizeof v); (u32)v; });  // @1001_58d000
  PV[59] = (u32)(edi);  // @1002_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1003_58d000
  ecx = (u32)(esi + 2146);  // @1004_58d000
  PV[60] = (u32)(ecx);  // @1005_58d000
  ecx = esi;  // @1006_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[60], PV[59]);  // @1007_58d000
  ecx = edx = 0;  // @1008_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1009_58d000
  eax = (u32)(esi + 2230);  // @1010_58d000
  PV[61] = (u32)(eax);  // @1011_58d000
  eax = (u32)(esi + 2194);  // @1012_58d000
  ecx = esi;  // @1013_58d000
  PV[62] = (u32)(eax);  // @1014_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[62], PV[61]);  // @1015_58d000
  ecx = edx = 0;  // @1016_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2138), sizeof v); (u32)v; });  // @1017_58d000
  FL[2] = (ecx & ecx);  // @1018_58d000
  if (FL[2] == 0) goto L58dc71;  // @1019_58d000
  eax = ext_5d2e60_thiscall1(ecx);  // @1020_58d000
    // @1021_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2138), sizeof v); (u32)v; });  // @1022_58d000
  eax = ext_5cdb70_thiscall1(ecx);  // @1023_58d000
  ecx = edx = 0;  // @1024_58d000
  L58dc71:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2071) + 0), 4); v; });  // @1026_58d000
  X1[1] = 0;  // @1027_58d000
  X1[2] = 0;  // @1028_58d000
  X1[3] = 0;  // @1029_58d000
  X0[0] = 0;  // @1030_58d000
  X0[1] = 0;  // @1031_58d000
  X0[2] = 0;  // @1032_58d000
  X0[3] = 0;  // @1033_58d000
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @1034_58d000
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1035_58d000
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1036_58d000
  if (__builtin_parity(FL[2] & 0xff)) goto L58df0a;  // @1037_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2075) + 0), 4); v; });  // @1038_58d000
  X0[1] = 0;  // @1039_58d000
  X0[2] = 0;  // @1040_58d000
  X0[3] = 0;  // @1041_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1042_58d000
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @1043_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @1044_58d000
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @1045_58d000
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; });  // @1046_58d000
  if ((s32)FL[0] >= (s32)FL[1]) goto L58df0a;  // @1047_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @1048_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1049_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 308), sizeof v); (u32)v; });  // @1050_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @1051_58d000
  ecx = edx = 0;  // @1052_58d000
  ecx = (u32)((EBP - 144) + 11);  // @1053_58d000
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 144) + 11), &v, sizeof v); }  // @1054_58d000
  PV[63] = (u32)(ecx);  // @1055_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1056_58d000
  ecx = eax;  // @1057_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6859220), PV[63]);  // @1058_58d000
  ecx = edx = 0;  // @1059_58d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 11), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1060_58d000
  if (FL[0] == FL[1]) goto L58dd30;  // @1061_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1062_58d000
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1063_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1064_58d000
  esi = ecx;  // @1065_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1066_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @1067_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, (u32)(6998744), (u32)(0), (u32)(6997712), (u32)(1995), (u32)(0));  // @1068_58d000
  ecx = edx = 0;  // @1069_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 20), sizeof v); (u32)v; });  // @1070_58d000
  eax = (eax & 0xffff);  // @1071_58d000
  PV[64] = (u32)(eax);  // @1072_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1073_58d000
  PV[65] = (u32)(ecx);  // @1074_58d000
  ecx = esi;  // @1075_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; });  // @1076_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[65], PV[64]);  // @1077_58d000
  ecx = edx = 0;  // @1078_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 24), sizeof v); (u32)v; });  // @1079_58d000
  ecx = esi;  // @1080_58d000
  PV[66] = (u32)(eax);  // @1081_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 300)))(ecx, PV[66]);  // @1082_58d000
  ecx = edx = 0;  // @1083_58d000
  goto L58df00;  // @1084_58d000
  L58dd30:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2536), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1086_58d000
  if (FL[0] == FL[1]) goto L58de82;  // @1087_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1088_58d000
  ecx = (u32)((EBP - 144) + 64);  // @1089_58d000
  PV[67] = (u32)(ecx);  // @1090_58d000
  ecx = esi;  // @1091_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 68), &v, sizeof v); }  // @1092_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 72), &v, sizeof v); }  // @1093_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 148) + 76), &v, sizeof v); }  // @1094_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[67]);  // @1095_58d000
  ecx = edx = 0;  // @1096_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2536), sizeof v); (u32)v; });  // @1097_58d000
  edx = (u32)((EBP - 144) + 12);  // @1098_58d000
  PV[68] = (u32)(edx);  // @1099_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 152) + 60), &v, sizeof v); }  // @1100_58d000
  edx = (u32)((EBP - 152) + 72);  // @1101_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 152) + 64), &v, sizeof v); }  // @1102_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 152) + 68), &v, sizeof v); }  // @1103_58d000
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)((EBP - 152) + 20), &v, sizeof v); }  // @1104_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1105_58d000
  PV[69] = (u32)(ecx);  // @1106_58d000
  PV[70] = (u32)(edx);  // @1107_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 132), sizeof v); (u32)v; });  // @1108_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[70], (u32)(1150681088), PV[68], (u32)(1));  // @1109_58d000
  ecx = edx = 0;  // @1110_58d000
  edi = eax;  // @1111_58d000
  FL[2] = (edi & edi);  // @1112_58d000
  if (FL[2] == 0) goto L58de82;  // @1113_58d000
  L58ddb2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1115_58d000
  ecx = edi;  // @1116_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @1117_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2099193));  // @1118_58d000
  ecx = edx = 0;  // @1119_58d000
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1120_58d000
  if (FL[2] == 0) goto L58de16;  // @1121_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1122_58d000
  ecx = (u32)((EBP - 144) + 52);  // @1123_58d000
  PV[71] = (u32)(ecx);  // @1124_58d000
  ecx = edi;  // @1125_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[71]);  // @1126_58d000
  ecx = edx = 0;  // @1127_58d000
  edx = (u32)((EBP - 144) + 64);  // @1128_58d000
  ecx = (u32)((EBP - 144) + 52);  // @1129_58d000
  eax = ext_43e960_fastcall2(ecx, edx);  // @1130_58d000
  ecx = edx = 0;  // @1131_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 52) + 0), 4); v; });  // @1132_58d000
  X0[1] = 0;  // @1133_58d000
  X0[2] = 0;  // @1134_58d000
  X0[3] = 0;  // @1135_58d000
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 56) + 0), 4); v; });  // @1136_58d000
  X1[1] = 0;  // @1137_58d000
  X1[2] = 0;  // @1138_58d000
  X1[3] = 0;  // @1139_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @1140_58d000
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @1141_58d000
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @1142_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 144) + 60) + 0), 4); v; });  // @1143_58d000
  X0[1] = 0;  // @1144_58d000
  X0[2] = 0;  // @1145_58d000
  X0[3] = 0;  // @1146_58d000
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @1147_58d000
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @1148_58d000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000620) + 0), 4); v; });  // @1149_58d000
  X0[1] = 0;  // @1150_58d000
  X0[2] = 0;  // @1151_58d000
  X0[3] = 0;  // @1152_58d000
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1153_58d000
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L58de46;  // @1154_58d000
  L58de16:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2536), sizeof v); (u32)v; });  // @1156_58d000
  edx = (u32)((EBP - 144) + 12);  // @1157_58d000
  PV[72] = (u32)(edx);  // @1158_58d000
  PV[73] = (u32)(ecx);  // @1159_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1160_58d000
  edx = (u32)((EBP - 156) + 76);  // @1161_58d000
  PV[74] = (u32)(edx);  // @1162_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 132), sizeof v); (u32)v; });  // @1163_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[74], (u32)(1150681088), PV[72], (u32)(1));  // @1164_58d000
  ecx = edx = 0;  // @1165_58d000
  edi = eax;  // @1166_58d000
  FL[2] = (edi & edi);  // @1167_58d000
  if (FL[2] != 0) goto L58ddb2;  // @1168_58d000
  goto L58de82;  // @1169_58d000
  L58de46:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1171_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1172_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1173_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1174_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @1175_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, (u32)(6998756), (u32)(0), (u32)(6997712), (u32)(2020), (u32)(0), (u32)(0));  // @1176_58d000
  ecx = edx = 0;  // @1177_58d000
  eax = (eax & 0xffff);  // @1178_58d000
  ecx = edi;  // @1179_58d000
  PV[75] = (u32)(eax);  // @1180_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[75]);  // @1181_58d000
  ecx = edx = 0;  // @1182_58d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 16), sizeof v); (u32)v; });  // @1183_58d000
  L58de82:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1185_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1186_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1187_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 312), sizeof v); (u32)v; });  // @1188_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @1189_58d000
  ecx = edx = 0;  // @1190_58d000
  ecx = (u32)((EBP - 144) + 12);  // @1191_58d000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 144) + 12), &v, sizeof v); }  // @1192_58d000
  PV[76] = (u32)(ecx);  // @1193_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1194_58d000
  ecx = eax;  // @1195_58d000
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6998776), PV[76]);  // @1196_58d000
  ecx = edx = 0;  // @1197_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1198_58d000
  PV[77] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 144) + 12), sizeof v); (u32)v; });  // @1199_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1200_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1201_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @1202_58d000
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[77]);  // @1203_58d000
  ecx = edx = 0;  // @1204_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1205_58d000
  edi = eax;  // @1206_58d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 11285), sizeof v); (u32)v; });  // @1207_58d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4164), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @1208_58d000
  if (FL[0] != FL[1]) goto L58dee5;  // @1209_58d000
  eax = ext_59c420_thiscall1(ecx);  // @1210_58d000
  ecx = edx = 0;  // @1211_58d000
  L58dee5:;
  FL[2] = (edi & edi);  // @1213_58d000
  if (FL[2] == 0) goto L58df00;  // @1214_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1215_58d000
  ecx = edi;  // @1216_58d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 708), sizeof v); (u32)v; });  // @1217_58d000
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @1218_58d000
  ecx = edx = 0;  // @1219_58d000
  PV[78] = (u32)(edi);  // @1220_58d000
  ecx = eax;  // @1221_58d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1222_58d000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 764)))(ecx, PV[78]);  // @1223_58d000
  ecx = edx = 0;  // @1224_58d000
  L58df00:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2071), &v, sizeof v); }  // @1226_58d000
  L58df0a:;
  ext_633654(G(u32, 0x6f5630));  // @1228_58d000
  return eax;  // @1229_58d000
}
PCREG(58d000, lifted_58d000);

