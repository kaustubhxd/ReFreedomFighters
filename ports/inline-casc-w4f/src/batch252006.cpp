// batch252006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634dac_dbl(double) __asm__("ext_634dac");
extern "C" double VECTORCALL ext_634de2_dbl(double) __asm__("ext_634de2");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de4b0_fastcall3(u32, u32, u32) __asm__("ext_4de4b0");
extern "C" u32 FASTCALL ext_4e09e0_fastcall2(u32, u32) __asm__("ext_4e09e0");
extern "C" u32 FASTCALL ext_65da70_fastcall4(u32, u32, u32, u32) __asm__("ext_65da70");
extern "C" u32 STDCALL ext_640c90_stdcall1(u32) __asm__("ext_640c90");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4db1f0_thiscall2(u32, u32) __asm__("ext_4db1f0");
extern "C" u32 THISCALL ext_4db600_thiscall3(u32, u32, u32) __asm__("ext_4db600");
extern "C" u32 THISCALL ext_4db670_thiscall2(u32, u32) __asm__("ext_4db670");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_640c10_thiscall2(u32, u32) __asm__("ext_640c10");
extern "C" u32 THISCALL ext_65c990_thiscall2(u32, u32) __asm__("ext_65c990");
extern "C" u32 THISCALL ext_65ca80_thiscall2(u32, u32) __asm__("ext_65ca80");
extern "C" u32 THISCALL ext_65cb00_thiscall2(u32, u32) __asm__("ext_65cb00");
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

extern "C" u32 THISCALL lifted_65d070(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_65d070
  edi = ecx;  // @1_65d070
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @2_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_65d070
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 90), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4_65d070
  if (FL[0] != FL[1]) goto L65d0df;  // @5_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @6_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @8_65d070
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7096360), (u32)(465));  // @9_65d070
  ecx = edx = 0;  // @10_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 352), sizeof v); (u32)v; });  // @11_65d070
  esi = eax;  // @12_65d070
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_65d070
  eax = ext_4dc110_thiscall1(ecx);  // @14_65d070
  ecx = 0;  // @15_65d070
  PV[0] = (u32)(eax);  // @16_65d070
  PV[1] = (u32)(esi);  // @17_65d070
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[1], (u32)(7096440), PV[0]);  // @18_65d070
  ecx = edx = 0;  // @19_65d070
  ext_633654(G(u32, 0x6f5630));  // @20_65d070
  return eax;  // @21_65d070
  L65d0df:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 143), sizeof v); (u32)v; });  // @24_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 364), &v, sizeof v); }  // @25_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @26_65d070
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }) & (u32)(3));  // @27_65d070
  if (FL[2] != 0) goto L65da16;  // @28_65d070
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(65536));  // @29_65d070
  if (FL[2] == 0) goto L65da16;  // @30_65d070
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; });  // @31_65d070
  FL[2] = (edx & edx);  // @32_65d070
  if (FL[2] == 0) goto L65da16;  // @33_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_65d070
  PV[2] = (u32)(edx);  // @35_65d070
  edx = (u32)(EBP - 376);  // @36_65d070
  PV[3] = (u32)(edx);  // @37_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @38_65d070
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[3], PV[2]);  // @39_65d070
  ecx = edx = 0;  // @40_65d070
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1048), &v, sizeof v); }  // @41_65d070
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1044), &v, sizeof v); }  // @42_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_65d070
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @44_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 380), &v, sizeof v); }  // @45_65d070
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @46_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @47_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @48_65d070
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 344), &v, sizeof v); }  // @49_65d070
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx + 12), sizeof v); (u32)v; })) & 0xff);  // @50_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @51_65d070
  if (FL[2] == 0) goto L65d16c;  // @52_65d070
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @53_65d070
  if (FL[0] != FL[1]) goto L65d2ab;  // @54_65d070
  L65d16c:;
  eax = (u32)(EBP - 196);  // @56_65d070
  ecx = esi;  // @57_65d070
  PV[4] = (u32)(eax);  // @58_65d070
  eax = (u32)(EBP - 304);  // @59_65d070
  PV[5] = (u32)(eax);  // @60_65d070
  eax = ext_4db6c0_thiscall3(ecx, PV[5], PV[4]);  // @61_65d070
  ecx = edx = 0;  // @62_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @63_65d070
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @64_65d070
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx + 12), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @65_65d070
  if (FL[0] != FL[1]) goto L65d218;  // @66_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + edx + 44) + 0), 4); v; });  // @67_65d070
  X0[1] = 0;  // @68_65d070
  X0[2] = 0;  // @69_65d070
  X0[3] = 0;  // @70_65d070
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @71_65d070
  { double r_ = ext_634dac_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @72_65d070
  ecx = edx = 0;  // @73_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @74_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @75_65d070
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @76_65d070
  __builtin_memcpy((void *)((u32)(EBP - 356) + 0), &X0[0], 4);  // @77_65d070
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 56) + 0), 4); v; })));  // @78_65d070
  SD(&X0[0], (double)U2F(X0[0]));  // @79_65d070
  { double r_ = ext_634de2_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @80_65d070
  ecx = edx = 0;  // @81_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @82_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @83_65d070
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @84_65d070
  __builtin_memcpy((void *)((u32)(EBP - 360) + 0), &X0[0], 4);  // @85_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 356) + 0), 4); v; });  // @86_65d070
  X0[1] = 0;  // @87_65d070
  X0[2] = 0;  // @88_65d070
  X0[3] = 0;  // @89_65d070
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 56) + 0), 4); v; })));  // @90_65d070
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @91_65d070
  { double r_ = ext_634de2_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @92_65d070
  ecx = edx = 0;  // @93_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @94_65d070
  X3[0] = 0;  // @95_65d070
  X3[1] = 0;  // @96_65d070
  X3[2] = 0;  // @97_65d070
  X3[3] = 0;  // @98_65d070
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @99_65d070
  X3[0] = F2U((float)U2D(X0[0], X0[1]));  // @100_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 360) + 0), 4); v; });  // @101_65d070
  X0[1] = 0;  // @102_65d070
  X0[2] = 0;  // @103_65d070
  X0[3] = 0;  // @104_65d070
  goto L65d223;  // @105_65d070
  L65d218:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; });  // @107_65d070
  X0[1] = 0;  // @108_65d070
  X0[2] = 0;  // @109_65d070
  X0[3] = 0;  // @110_65d070
  X3[0] = X0[0];  // @111_65d070
  X3[1] = X0[1];  // @112_65d070
  X3[2] = X0[2];  // @113_65d070
  X3[3] = X0[3];  // @114_65d070
  L65d223:;
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + edx + 28) + 0), 4); v; });  // @116_65d070
  X5[1] = 0;  // @117_65d070
  X5[2] = 0;  // @118_65d070
  X5[3] = 0;  // @119_65d070
  X4[0] = X5[0];  // @120_65d070
  X4[1] = X5[1];  // @121_65d070
  X4[2] = X5[2];  // @122_65d070
  X4[3] = X5[3];  // @123_65d070
  __builtin_memcpy((void *)((u32)(EBP - 384) + 0), &X5[0], 4);  // @124_65d070
  X2[0] = X5[0];  // @125_65d070
  X2[1] = X5[1];  // @126_65d070
  X2[2] = X5[2];  // @127_65d070
  X2[3] = X5[3];  // @128_65d070
  X4[0] = F2U(U2F(X4[0]) * U2F(X0[0]));  // @129_65d070
  X2[0] = F2U(U2F(X2[0]) * U2F(X3[0]));  // @130_65d070
  X1[0] = X4[0];  // @131_65d070
  X1[1] = X4[1];  // @132_65d070
  X1[2] = X4[2];  // @133_65d070
  X1[3] = X4[3];  // @134_65d070
  __builtin_memcpy((void *)((u32)(EBP - 396) + 0), &X5[0], 4);  // @135_65d070
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @136_65d070
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @137_65d070
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @138_65d070
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @139_65d070
  X3[0] = X2[0];  // @140_65d070
  X3[1] = X2[1];  // @141_65d070
  X3[2] = X2[2];  // @142_65d070
  X3[3] = X2[3];  // @143_65d070
  __builtin_memcpy((void *)((u32)(EBP - 392) + 0), &X1[0], 4);  // @144_65d070
  X3[0] = X3[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @145_65d070
  X3[1] = X3[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @146_65d070
  X3[2] = X3[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @147_65d070
  X3[3] = X3[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @148_65d070
  __builtin_memcpy((void *)((u32)(EBP - 388) + 0), &X3[0], 4);  // @149_65d070
  __builtin_memcpy((void *)((u32)(EBP - 404) + 0), &X1[0], 4);  // @150_65d070
  __builtin_memcpy((void *)((u32)(EBP - 400) + 0), &X2[0], 4);  // @151_65d070
  __builtin_memcpy((void *)((u32)(EBP - 416) + 0), &X4[0], 4);  // @152_65d070
  __builtin_memcpy((void *)((u32)(EBP - 412) + 0), &X2[0], 4);  // @153_65d070
  __builtin_memcpy((void *)((u32)(EBP - 408) + 0), &X5[0], 4);  // @154_65d070
  __builtin_memcpy((void *)((u32)(EBP - 428) + 0), &X4[0], 4);  // @155_65d070
  __builtin_memcpy((void *)((u32)(EBP - 424) + 0), &X3[0], 4);  // @156_65d070
  __builtin_memcpy((void *)((u32)(EBP - 420) + 0), &X5[0], 4);  // @157_65d070
  L65d2ab:;
  eax = 0;  // @159_65d070
  FL[3] = eax;  // @160_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @161_65d070
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 376), sizeof v); (u32)v; }); FL[1] = eax;  // @162_65d070
  if (FL[0] <= FL[1]) goto L65d60f;  // @163_65d070
  L65d2c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 380), sizeof v); (u32)v; });  // @165_65d070
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4), sizeof v); (u32)v; });  // @166_65d070
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(65536));  // @167_65d070
  if (FL[2] == 0) goto L65d5ac;  // @168_65d070
  ecx = esi;  // @169_65d070
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2097191));  // @170_65d070
  ecx = 0;  // @171_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @172_65d070
  if (FL[2] == 0) goto L65d5ac;  // @173_65d070
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 364), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @174_65d070
  if (FL[0] != FL[1]) goto L65d318;  // @175_65d070
  ecx = esi;  // @176_65d070
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2097268));  // @177_65d070
  ecx = 0;  // @178_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @179_65d070
  if (FL[2] == 0) goto L65d318;  // @180_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @181_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @182_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1056), sizeof v); (u32)v; });  // @183_65d070
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @184_65d070
  ecx = edx = 0;  // @185_65d070
  FL[2] = (eax & eax);  // @186_65d070
  if (FL[2] != 0) goto L65d5ac;  // @187_65d070
  L65d318:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @189_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @190_65d070
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 12), sizeof v); (u32)v; })) & 0xff);  // @191_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @192_65d070
  if (FL[2] == 0) goto L65d33d;  // @193_65d070
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @194_65d070
  if (FL[0] == FL[1]) goto L65d33d;  // @195_65d070
  PV[6] = (u32)(esi);  // @196_65d070
  ecx = edi;  // @197_65d070
  eax = ext_65c990_thiscall2(ecx, PV[6]);  // @198_65d070
  edx = 0;  // @199_65d070
  goto L65d5ac;  // @200_65d070
  L65d33d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 48) + 0), 4); v; });  // @202_65d070
  X0[1] = 0;  // @203_65d070
  X0[2] = 0;  // @204_65d070
  X0[3] = 0;  // @205_65d070
  ecx = (u32)(EBP - 268);  // @206_65d070
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @207_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 52) + 0), 4); v; });  // @208_65d070
  X0[1] = 0;  // @209_65d070
  X0[2] = 0;  // @210_65d070
  X0[3] = 0;  // @211_65d070
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @212_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; });  // @213_65d070
  X0[1] = 0;  // @214_65d070
  X0[2] = 0;  // @215_65d070
  X0[3] = 0;  // @216_65d070
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @217_65d070
  eax = ext_4de7a0_thiscall1(ecx);  // @218_65d070
    // @219_65d070
  eax = (u32)(EBP - 40);  // @220_65d070
  ecx = esi;  // @221_65d070
  PV[7] = (u32)(eax);  // @222_65d070
  eax = (u32)(EBP - 268);  // @223_65d070
  PV[8] = (u32)(eax);  // @224_65d070
  eax = ext_4db600_thiscall3(ecx, PV[8], PV[7]);  // @225_65d070
  ecx = edx = 0;  // @226_65d070
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 68) + 0), 4); v; });  // @227_65d070
  X1[1] = 0;  // @228_65d070
  X1[2] = 0;  // @229_65d070
  X1[3] = 0;  // @230_65d070
  eax = (u32)(EBP - 40);  // @231_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 64) + 0), 4); v; });  // @232_65d070
  X0[1] = 0;  // @233_65d070
  X0[2] = 0;  // @234_65d070
  X0[3] = 0;  // @235_65d070
  edx = (u32)(EBP - 196);  // @236_65d070
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @237_65d070
  ecx = (u32)(EBP - 28);  // @238_65d070
  PV[9] = (u32)(eax);  // @239_65d070
  __builtin_memcpy((void *)((u32)(EBP - 372) + 0), &X1[0], 4);  // @240_65d070
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 72) + 0), 4); v; });  // @241_65d070
  X1[1] = 0;  // @242_65d070
  X1[2] = 0;  // @243_65d070
  X1[3] = 0;  // @244_65d070
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @245_65d070
  __builtin_memcpy((void *)((u32)(EBP - 360) + 0), &X0[0], 4);  // @246_65d070
  __builtin_memcpy((void *)((u32)(EBP - 368) + 0), &X1[0], 4);  // @247_65d070
  eax = ext_43e920_fastcall3(ecx, edx, PV[9]);  // @248_65d070
  ecx = edx = 0;  // @249_65d070
  edx = (u32)(EBP - 268);  // @250_65d070
  ecx = (u32)(EBP - 28);  // @251_65d070
  eax = ext_441a60_fastcall2(ecx, edx);  // @252_65d070
  ecx = edx = 0;  // @253_65d070
  eax = (u32)(EBP - 268);  // @254_65d070
  PV[10] = (u32)(eax);  // @255_65d070
  edx = (u32)(EBP - 304);  // @256_65d070
  ecx = (u32)(EBP - 340);  // @257_65d070
  eax = ext_4de4b0_fastcall3(ecx, edx, PV[10]);  // @258_65d070
  ecx = edx = 0;  // @259_65d070
  edx = (u32)(EBP - 340);  // @260_65d070
  ecx = (u32)(EBP - 232);  // @261_65d070
  eax = ext_4de420_fastcall2(ecx, edx);  // @262_65d070
    // @263_65d070
  eax = (u32)(EBP - 232);  // @264_65d070
  PV[11] = (u32)(eax);  // @265_65d070
  edx = (u32)(EBP - 392);  // @266_65d070
  ecx = (u32)(EBP - 100);  // @267_65d070
  eax = ext_441970_fastcall3(ecx, edx, PV[11]);  // @268_65d070
  ecx = edx = 0;  // @269_65d070
  eax = (u32)(EBP - 232);  // @270_65d070
  PV[12] = (u32)(eax);  // @271_65d070
  edx = (u32)(EBP - 404);  // @272_65d070
  ecx = (u32)(EBP - 112);  // @273_65d070
  eax = ext_441970_fastcall3(ecx, edx, PV[12]);  // @274_65d070
  ecx = edx = 0;  // @275_65d070
  eax = (u32)(EBP - 232);  // @276_65d070
  PV[13] = (u32)(eax);  // @277_65d070
  edx = (u32)(EBP - 416);  // @278_65d070
  ecx = (u32)(EBP - 124);  // @279_65d070
  eax = ext_441970_fastcall3(ecx, edx, PV[13]);  // @280_65d070
  ecx = edx = 0;  // @281_65d070
  eax = (u32)(EBP - 232);  // @282_65d070
  PV[14] = (u32)(eax);  // @283_65d070
  edx = (u32)(EBP - 428);  // @284_65d070
  ecx = (u32)(EBP - 76);  // @285_65d070
  eax = ext_441970_fastcall3(ecx, edx, PV[14]);  // @286_65d070
  ecx = edx = 0;  // @287_65d070
  eax = (u32)(EBP - 112);  // @288_65d070
  PV[15] = (u32)(eax);  // @289_65d070
  edx = (u32)(EBP - 100);  // @290_65d070
  ecx = (u32)(EBP - 184);  // @291_65d070
  eax = ext_446ee0_fastcall3(ecx, edx, PV[15]);  // @292_65d070
  ecx = edx = 0;  // @293_65d070
  eax = (u32)(EBP - 76);  // @294_65d070
  PV[16] = (u32)(eax);  // @295_65d070
  edx = (u32)(EBP - 124);  // @296_65d070
  ecx = (u32)(EBP - 172);  // @297_65d070
  eax = ext_446ee0_fastcall3(ecx, edx, PV[16]);  // @298_65d070
  ecx = edx = 0;  // @299_65d070
  eax = (u32)(EBP - 124);  // @300_65d070
  PV[17] = (u32)(eax);  // @301_65d070
  edx = (u32)(EBP - 112);  // @302_65d070
  ecx = (u32)(EBP - 160);  // @303_65d070
  eax = ext_446ee0_fastcall3(ecx, edx, PV[17]);  // @304_65d070
  ecx = edx = 0;  // @305_65d070
  eax = (u32)(EBP - 100);  // @306_65d070
  PV[18] = (u32)(eax);  // @307_65d070
  edx = (u32)(EBP - 76);  // @308_65d070
  ecx = (u32)(EBP - 148);  // @309_65d070
  eax = ext_446ee0_fastcall3(ecx, edx, PV[18]);  // @310_65d070
  ecx = edx = 0;  // @311_65d070
  ecx = (u32)(EBP - 184);  // @312_65d070
  eax = ext_44c840_thiscall1(ecx);  // @313_65d070
  ecx = 0;  // @314_65d070
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @315_65d070
  ecx = (u32)(EBP - 172);  // @316_65d070
  eax = ext_44c840_thiscall1(ecx);  // @317_65d070
  ecx = 0;  // @318_65d070
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @319_65d070
  ecx = (u32)(EBP - 160);  // @320_65d070
  eax = ext_44c840_thiscall1(ecx);  // @321_65d070
  ecx = 0;  // @322_65d070
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @323_65d070
  ecx = (u32)(EBP - 148);  // @324_65d070
  eax = ext_44c840_thiscall1(ecx);  // @325_65d070
  ecx = 0;  // @326_65d070
  edx = (u32)(EBP - 304);  // @327_65d070
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @328_65d070
  ecx = (u32)(EBP - 136);  // @329_65d070
  eax = ext_4e09e0_fastcall2(ecx, edx);  // @330_65d070
    // @331_65d070
  edx = (u32)(EBP - 268);  // @332_65d070
  ecx = (u32)(EBP - 136);  // @333_65d070
  eax = ext_441a60_fastcall2(ecx, edx);  // @334_65d070
  ecx = edx = 0;  // @335_65d070
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X5[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X5[2] = X5[3] = 0;  // @336_65d070
  eax = (u32)(EBP - 184);  // @337_65d070
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 360) + 0), 4); v; });  // @338_65d070
  X6[1] = 0;  // @339_65d070
  X6[2] = 0;  // @340_65d070
  X6[3] = 0;  // @341_65d070
  ecx = 0;  // @342_65d070
  FL[3] = ecx;  // @343_65d070
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 368) + 0), 4); v; });  // @344_65d070
  X7[1] = 0;  // @345_65d070
  X7[2] = 0;  // @346_65d070
  X7[3] = 0;  // @347_65d070
  L65d510:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @349_65d070
  X2[1] = 0;  // @350_65d070
  X2[2] = 0;  // @351_65d070
  X2[3] = 0;  // @352_65d070
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @353_65d070
  X1[1] = 0;  // @354_65d070
  X1[2] = 0;  // @355_65d070
  X1[3] = 0;  // @356_65d070
  X0[0] = X2[0];  // @357_65d070
  X0[1] = X2[1];  // @358_65d070
  X0[2] = X2[2];  // @359_65d070
  X0[3] = X2[3];  // @360_65d070
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @361_65d070
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; })));  // @362_65d070
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @363_65d070
  X4[1] = 0;  // @364_65d070
  X4[2] = 0;  // @365_65d070
  X4[3] = 0;  // @366_65d070
  X0[0] = F2U(U2F(X0[0]) * U2F(X6[0]));  // @367_65d070
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @368_65d070
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X3[0], a_); SD(&X3[2], b_); }  // @369_65d070
  X0[0] = X4[0];  // @370_65d070
  X0[1] = X4[1];  // @371_65d070
  X0[2] = X4[2];  // @372_65d070
  X0[3] = X4[3];  // @373_65d070
  X4[0] = F2U(U2F(X4[0]) * U2F(X7[0]));  // @374_65d070
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @375_65d070
  X3[0] = X3[0] & X5[0];  // @376_65d070
  X3[1] = X3[1] & X5[1];  // @377_65d070
  X3[2] = X3[2] & X5[2];  // @378_65d070
  X3[3] = X3[3] & X5[3];  // @379_65d070
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @380_65d070
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @381_65d070
  SD(&X3[0], U2D(X3[0], X3[1]) + U2D(X0[0], X0[1]));  // @382_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @383_65d070
  X0[1] = 0;  // @384_65d070
  X0[2] = 0;  // @385_65d070
  X0[3] = 0;  // @386_65d070
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 372) + 0), 4); v; })));  // @387_65d070
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @388_65d070
  X0[0] = X0[0] & X5[0];  // @389_65d070
  X0[1] = X0[1] & X5[1];  // @390_65d070
  X0[2] = X0[2] & X5[2];  // @391_65d070
  X0[3] = X0[3] & X5[3];  // @392_65d070
  SD(&X3[0], U2D(X3[0], X3[1]) + U2D(X0[0], X0[1]));  // @393_65d070
  { double a_ = (double)U2F(X4[0]), b_ = (double)U2F(X4[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @394_65d070
  X0[0] = X0[0] & X5[0];  // @395_65d070
  X0[1] = X0[1] & X5[1];  // @396_65d070
  X0[2] = X0[2] & X5[2];  // @397_65d070
  X0[3] = X0[3] & X5[3];  // @398_65d070
  SD(&X3[0], U2D(X3[0], X3[1]) + U2D(X0[0], X0[1]));  // @399_65d070
  X0[0] = 0;  // @400_65d070
  X0[1] = 0;  // @401_65d070
  X0[2] = 0;  // @402_65d070
  X0[3] = 0;  // @403_65d070
  FA = U2D(X0[0], X0[1]); FB = U2D(X3[0], X3[1]);  // @404_65d070
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L65d5f0;  // @405_65d070
  ecx = (ecx + 1);  // @406_65d070
  FL[3] = ecx;  // @407_65d070
  eax = (eax + (u32)(12));  // @408_65d070
  FL[3] = eax;  // @409_65d070
  FL[0] = ecx; FL[1] = (u32)(5);  // @410_65d070
  if ((s32)FL[0] < (s32)FL[1]) goto L65d510;  // @411_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1044), sizeof v); (u32)v; });  // @412_65d070
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + eax*4 + 512), &v, sizeof v); }  // @413_65d070
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1044), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 1044), &v, sizeof v); }  // @414_65d070
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1044), sizeof v); (u32)v; });  // @415_65d070
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1044), sizeof v); (u32)v; }); FL[1] = (u32)(128);  // @416_65d070
  if ((s32)FL[0] < (s32)FL[1]) goto L65d5ac;  // @417_65d070
  { u32 v = (u32)((u32)(127)); __builtin_memcpy((void *)(u32)(edi + 1044), &v, sizeof v); }  // @418_65d070
  L65d5ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @420_65d070
  eax = (eax & (u32)(135168));  // @421_65d070
  FL[3] = eax;  // @422_65d070
  FL[0] = eax; FL[1] = (u32)(135168);  // @423_65d070
  if (FL[0] != FL[1]) goto L65d5f0;  // @424_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1060), sizeof v); (u32)v; });  // @425_65d070
  PV[19] = (u32)(esi);  // @426_65d070
  eax = ext_640c90_stdcall1(PV[19]);  // @427_65d070
    // @428_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @429_65d070
  if (FL[2] == 0) goto L65d5f0;  // @430_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1048), sizeof v); (u32)v; });  // @431_65d070
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + eax*4), &v, sizeof v); }  // @432_65d070
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1048), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 1048), &v, sizeof v); }  // @433_65d070
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1048), sizeof v); (u32)v; });  // @434_65d070
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1048), sizeof v); (u32)v; }); FL[1] = (u32)(128);  // @435_65d070
  if ((s32)FL[0] < (s32)FL[1]) goto L65d5f0;  // @436_65d070
  { u32 v = (u32)((u32)(127)); __builtin_memcpy((void *)(u32)(edi + 1048), &v, sizeof v); }  // @437_65d070
  L65d5f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; });  // @439_65d070
  eax = (eax + 1);  // @440_65d070
  FL[3] = eax;  // @441_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @442_65d070
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 376), sizeof v); (u32)v; });  // @443_65d070
  if (FL[0] < FL[1]) goto L65d2c0;  // @444_65d070
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 352), sizeof v); (u32)v; });  // @445_65d070
  L65d60f:;
  PV[20] = (u32)(esi);  // @447_65d070
  ecx = edi;  // @448_65d070
  eax = ext_65cb00_thiscall2(ecx, PV[20]);  // @449_65d070
  ecx = edx = 0;  // @450_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @451_65d070
  if (FL[2] == 0) goto L65da16;  // @452_65d070
  eax = (u32)(EBP - 28);  // @453_65d070
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @454_65d070
  PV[21] = (u32)(eax);  // @455_65d070
  ecx = esi;  // @456_65d070
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @457_65d070
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @458_65d070
  eax = ext_4db670_thiscall2(ecx, PV[21]);  // @459_65d070
  ecx = edx = 0;  // @460_65d070
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1044), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @461_65d070
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @462_65d070
  if ((s32)FL[0] <= (s32)FL[1]) goto L65d9e2;  // @463_65d070
  ecx = (u32)(edi + 512);  // @464_65d070
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 344), &v, sizeof v); }  // @465_65d070
  L65d662:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @467_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1060), sizeof v); (u32)v; });  // @468_65d070
  PV[22] = (u32)(esi);  // @469_65d070
  eax = ext_640c10_thiscall2(ecx, PV[22]);  // @470_65d070
  ecx = edx = 0;  // @471_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @472_65d070
  if (FL[2] == 0) goto L65d9ba;  // @473_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 48) + 0), 4); v; });  // @474_65d070
  X0[1] = 0;  // @475_65d070
  X0[2] = 0;  // @476_65d070
  X0[3] = 0;  // @477_65d070
  eax = (u32)(EBP - 52);  // @478_65d070
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @479_65d070
  ecx = esi;  // @480_65d070
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 52) + 0), 4); v; });  // @481_65d070
  X1[1] = 0;  // @482_65d070
  X1[2] = 0;  // @483_65d070
  X1[3] = 0;  // @484_65d070
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X1[0], 4);  // @485_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; });  // @486_65d070
  X0[1] = 0;  // @487_65d070
  X0[2] = 0;  // @488_65d070
  X0[3] = 0;  // @489_65d070
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @490_65d070
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 68) + 0), 4); v; })));  // @491_65d070
  PV[23] = (u32)(eax);  // @492_65d070
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X1[0], 4);  // @493_65d070
  eax = ext_4db670_thiscall2(ecx, PV[23]);  // @494_65d070
  ecx = edx = 0;  // @495_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 48) + 0), 4); v; });  // @496_65d070
  X0[1] = 0;  // @497_65d070
  X0[2] = 0;  // @498_65d070
  X0[3] = 0;  // @499_65d070
  eax = (u32)(EBP - 64);  // @500_65d070
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @501_65d070
  ecx = esi;  // @502_65d070
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 52) + 0), 4); v; });  // @503_65d070
  X1[1] = 0;  // @504_65d070
  X1[2] = 0;  // @505_65d070
  X1[3] = 0;  // @506_65d070
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X1[0], 4);  // @507_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; });  // @508_65d070
  X0[1] = 0;  // @509_65d070
  X0[2] = 0;  // @510_65d070
  X0[3] = 0;  // @511_65d070
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @512_65d070
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 68) + 0), 4); v; })));  // @513_65d070
  PV[24] = (u32)(eax);  // @514_65d070
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X1[0], 4);  // @515_65d070
  eax = ext_4db670_thiscall2(ecx, PV[24]);  // @516_65d070
  ecx = edx = 0;  // @517_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 48) + 0), 4); v; });  // @518_65d070
  X0[1] = 0;  // @519_65d070
  X0[2] = 0;  // @520_65d070
  X0[3] = 0;  // @521_65d070
  eax = (u32)(EBP - 100);  // @522_65d070
  __builtin_memcpy((void *)((u32)(EBP - 100) + 0), &X0[0], 4);  // @523_65d070
  ecx = esi;  // @524_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 52) + 0), 4); v; });  // @525_65d070
  X0[1] = 0;  // @526_65d070
  X0[2] = 0;  // @527_65d070
  X0[3] = 0;  // @528_65d070
  __builtin_memcpy((void *)((u32)(EBP - 96) + 0), &X0[0], 4);  // @529_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; });  // @530_65d070
  X0[1] = 0;  // @531_65d070
  X0[2] = 0;  // @532_65d070
  X0[3] = 0;  // @533_65d070
  PV[25] = (u32)(eax);  // @534_65d070
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X0[0], 4);  // @535_65d070
  eax = ext_4db670_thiscall2(ecx, PV[25]);  // @536_65d070
  ecx = edx = 0;  // @537_65d070
  PV[26] = (u32)(esi);  // @538_65d070
  ecx = edi;  // @539_65d070
  eax = ext_65ca80_thiscall2(ecx, PV[26]);  // @540_65d070
  ecx = edx = 0;  // @541_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @542_65d070
  if (FL[2] == 0) goto L65d9ba;  // @543_65d070
  eax = 0;  // @544_65d070
  FL[3] = eax;  // @545_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @546_65d070
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1048), sizeof v); (u32)v; }); FL[1] = eax;  // @547_65d070
  if ((s32)FL[0] <= (s32)FL[1]) goto L65d99e;  // @548_65d070
  ecx = (u32)(EBP - 16);  // @549_65d070
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 372), &v, sizeof v); }  // @550_65d070
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @551_65d070
  L65d740:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @553_65d070
  edx = (u32)(EBP - 52);  // @554_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @555_65d070
  ecx = (u32)(EBP - 16);  // @556_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @557_65d070
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 4), 4); v; });  // @558_65d070
  X0[2] = 0;  // @559_65d070
  X0[3] = 0;  // @560_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @561_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @562_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @563_65d070
  eax = (u32)(EBP - 28);  // @564_65d070
  __builtin_memcpy((void *)((u32)(EBP - 88) + 0), &X0[0], 4);  // @565_65d070
  __builtin_memcpy((void *)((u32)(EBP - 88) + 4), &X0[1], 4);  // @566_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @567_65d070
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 4), 4); v; });  // @568_65d070
  X0[2] = 0;  // @569_65d070
  X0[3] = 0;  // @570_65d070
  PV[27] = (u32)(eax);  // @571_65d070
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 364), &v, sizeof v); }  // @572_65d070
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @573_65d070
  __builtin_memcpy((void *)((u32)(EBP - 40) + 4), &X0[1], 4);  // @574_65d070
  eax = ext_43e920_fastcall3(ecx, edx, PV[27]);  // @575_65d070
  ecx = edx = 0;  // @576_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @577_65d070
  X0[1] = 0;  // @578_65d070
  X0[2] = 0;  // @579_65d070
  X0[3] = 0;  // @580_65d070
  X1[0] = 0;  // @581_65d070
  X1[1] = 0;  // @582_65d070
  X1[2] = 0;  // @583_65d070
  X1[3] = 0;  // @584_65d070
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @585_65d070
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @586_65d070
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @587_65d070
  if (!__builtin_parity(FL[2] & 0xff)) goto L65d7a5;  // @588_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @589_65d070
  X0[1] = 0;  // @590_65d070
  X0[2] = 0;  // @591_65d070
  X0[3] = 0;  // @592_65d070
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @593_65d070
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @594_65d070
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @595_65d070
  if (!__builtin_parity(FL[2] & 0xff)) goto L65d7a5;  // @596_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @597_65d070
  X0[1] = 0;  // @598_65d070
  X0[2] = 0;  // @599_65d070
  X0[3] = 0;  // @600_65d070
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @601_65d070
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @602_65d070
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @603_65d070
  if (__builtin_parity(FL[2] & 0xff)) goto L65d7ed;  // @604_65d070
  L65d7a5:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @606_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; });  // @607_65d070
  FS[0] = LDF((u32)(ecx));  // @608_65d070
  FS[0] = (FS[0] * FS[0]);  // @609_65d070
  FS[1] = LDF((u32)(ecx + 4));  // @610_65d070
  FS[1] = (FS[1] * FS[1]);  // @611_65d070
  FS[0] = (FS[0] + FS[1]);  // @612_65d070
  FS[1] = LDF((u32)(ecx + 8));  // @613_65d070
  FS[1] = (FS[1] * FS[1]);  // @614_65d070
  FS[0] = (FS[0] + FS[1]);  // @615_65d070
  FSQRT(FS[0]);  // @616_65d070
  FS[1] = LDF((u32)(EBP - 352));  // @617_65d070
  FS[1] = (FS[1] / FS[0]);  // @618_65d070
  FS[2] = LDF((u32)(ecx));  // @619_65d070
  FS[2] = (FS[2] * FS[1]);  // @620_65d070
  STF((u32)(ecx), FS[2]);  // @621_65d070
  FS[2] = LDF((u32)(ecx + 4));  // @622_65d070
  FS[2] = (FS[2] * FS[1]);  // @623_65d070
  STF((u32)(ecx + 4), FS[2]);  // @624_65d070
  FS[2] = LDF((u32)(ecx + 8));  // @625_65d070
  FS[1] = (FS[1] * FS[2]);  // @626_65d070
  STF((u32)(ecx + 8), FS[1]);  // @627_65d070
  STF((u32)(EBP - 352), FS[0]);  // @628_65d070
  L65d7ed:;
  PV[28] = (u32)(ecx);  // @630_65d070
  ecx = (u32)(EBP - 16);  // @631_65d070
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1148846080));  // @632_65d070
    // @633_65d070
  eax = (u32)(EBP - 16);  // @634_65d070
  PV[29] = (u32)(eax);  // @635_65d070
  edx = (u32)(EBP - 88);  // @636_65d070
  ecx = (u32)(EBP - 112);  // @637_65d070
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[29]);  // @638_65d070
  ecx = edx = 0;  // @639_65d070
  eax = (u32)(EBP - 28);  // @640_65d070
  PV[30] = (u32)(eax);  // @641_65d070
  edx = (u32)(EBP - 64);  // @642_65d070
  ecx = (u32)(EBP - 16);  // @643_65d070
  eax = ext_43e920_fastcall3(ecx, edx, PV[30]);  // @644_65d070
  ecx = edx = 0;  // @645_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @646_65d070
  X0[1] = 0;  // @647_65d070
  X0[2] = 0;  // @648_65d070
  X0[3] = 0;  // @649_65d070
  X1[0] = 0;  // @650_65d070
  X1[1] = 0;  // @651_65d070
  X1[2] = 0;  // @652_65d070
  X1[3] = 0;  // @653_65d070
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @654_65d070
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @655_65d070
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @656_65d070
  if (!__builtin_parity(FL[2] & 0xff)) goto L65d848;  // @657_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @658_65d070
  X0[1] = 0;  // @659_65d070
  X0[2] = 0;  // @660_65d070
  X0[3] = 0;  // @661_65d070
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @662_65d070
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @663_65d070
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @664_65d070
  if (!__builtin_parity(FL[2] & 0xff)) goto L65d848;  // @665_65d070
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @666_65d070
  X0[1] = 0;  // @667_65d070
  X0[2] = 0;  // @668_65d070
  X0[3] = 0;  // @669_65d070
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @670_65d070
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @671_65d070
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @672_65d070
  if (__builtin_parity(FL[2] & 0xff)) goto L65d890;  // @673_65d070
  L65d848:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @675_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 368), sizeof v); (u32)v; });  // @676_65d070
  FS[0] = LDF((u32)(ecx));  // @677_65d070
  FS[0] = (FS[0] * FS[0]);  // @678_65d070
  FS[1] = LDF((u32)(ecx + 4));  // @679_65d070
  FS[1] = (FS[1] * FS[1]);  // @680_65d070
  FS[0] = (FS[0] + FS[1]);  // @681_65d070
  FS[1] = LDF((u32)(ecx + 8));  // @682_65d070
  FS[1] = (FS[1] * FS[1]);  // @683_65d070
  FS[0] = (FS[0] + FS[1]);  // @684_65d070
  FSQRT(FS[0]);  // @685_65d070
  FS[1] = LDF((u32)(EBP - 352));  // @686_65d070
  FS[1] = (FS[1] / FS[0]);  // @687_65d070
  FS[2] = LDF((u32)(ecx));  // @688_65d070
  FS[2] = (FS[2] * FS[1]);  // @689_65d070
  STF((u32)(ecx), FS[2]);  // @690_65d070
  FS[2] = LDF((u32)(ecx + 4));  // @691_65d070
  FS[2] = (FS[2] * FS[1]);  // @692_65d070
  STF((u32)(ecx + 4), FS[2]);  // @693_65d070
  FS[2] = LDF((u32)(ecx + 8));  // @694_65d070
  FS[1] = (FS[1] * FS[2]);  // @695_65d070
  STF((u32)(ecx + 8), FS[1]);  // @696_65d070
  STF((u32)(EBP - 352), FS[0]);  // @697_65d070
  L65d890:;
  PV[31] = (u32)(ecx);  // @699_65d070
  ecx = (u32)(EBP - 16);  // @700_65d070
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1148846080));  // @701_65d070
    // @702_65d070
  eax = (u32)(EBP - 16);  // @703_65d070
  PV[32] = (u32)(eax);  // @704_65d070
  edx = (u32)(EBP - 40);  // @705_65d070
  ecx = (u32)(EBP - 76);  // @706_65d070
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[32]);  // @707_65d070
  ecx = edx = 0;  // @708_65d070
  eax = (u32)(EBP - 88);  // @709_65d070
  ecx = esi;  // @710_65d070
  PV[33] = (u32)(eax);  // @711_65d070
  eax = ext_4db1f0_thiscall2(ecx, PV[33]);  // @712_65d070
  ecx = edx = 0;  // @713_65d070
  eax = (u32)(EBP - 40);  // @714_65d070
  ecx = esi;  // @715_65d070
  PV[34] = (u32)(eax);  // @716_65d070
  eax = ext_4db1f0_thiscall2(ecx, PV[34]);  // @717_65d070
  ecx = edx = 0;  // @718_65d070
  eax = (u32)(EBP - 76);  // @719_65d070
  ecx = esi;  // @720_65d070
  PV[35] = (u32)(eax);  // @721_65d070
  eax = ext_4db1f0_thiscall2(ecx, PV[35]);  // @722_65d070
  ecx = edx = 0;  // @723_65d070
  eax = (u32)(EBP - 112);  // @724_65d070
  ecx = esi;  // @725_65d070
  PV[36] = (u32)(eax);  // @726_65d070
  eax = ext_4db1f0_thiscall2(ecx, PV[36]);  // @727_65d070
  ecx = edx = 0;  // @728_65d070
  esi = (esi + (u32)(48));  // @729_65d070
  FL[3] = esi;  // @730_65d070
  ecx = (u32)(EBP - 88);  // @731_65d070
  edx = esi;  // @732_65d070
  eax = ext_43e960_fastcall2(ecx, edx);  // @733_65d070
  ecx = edx = 0;  // @734_65d070
  edx = esi;  // @735_65d070
  ecx = (u32)(EBP - 40);  // @736_65d070
  eax = ext_43e960_fastcall2(ecx, edx);  // @737_65d070
  ecx = edx = 0;  // @738_65d070
  edx = esi;  // @739_65d070
  ecx = (u32)(EBP - 76);  // @740_65d070
  eax = ext_43e960_fastcall2(ecx, edx);  // @741_65d070
  ecx = edx = 0;  // @742_65d070
  edx = esi;  // @743_65d070
  ecx = (u32)(EBP - 112);  // @744_65d070
  eax = ext_43e960_fastcall2(ecx, edx);  // @745_65d070
  ecx = edx = 0;  // @746_65d070
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 364), sizeof v); (u32)v; });  // @747_65d070
  eax = (u32)(EBP - 124);  // @748_65d070
  PV[37] = (u32)(eax);  // @749_65d070
  ecx = esi;  // @750_65d070
  eax = ext_4db7c0_thiscall2(ecx, PV[37]);  // @751_65d070
  edx = 0;  // @752_65d070
  PV[38] = (u32)(ecx);  // @753_65d070
  ecx = (u32)(EBP - 124);  // @754_65d070
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1067030938));  // @755_65d070
    // @756_65d070
  eax = (u32)(EBP - 76);  // @757_65d070
  PV[39] = (u32)(eax);  // @758_65d070
  eax = (u32)(EBP - 40);  // @759_65d070
  PV[40] = (u32)(eax);  // @760_65d070
  edx = (u32)(EBP - 88);  // @761_65d070
  ecx = (u32)(EBP - 124);  // @762_65d070
  eax = ext_65da70_fastcall4(ecx, edx, PV[40], PV[39]);  // @763_65d070
  ecx = edx = 0;  // @764_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @765_65d070
  if (FL[2] != 0) goto L65d955;  // @766_65d070
  eax = (u32)(EBP - 112);  // @767_65d070
  PV[41] = (u32)(eax);  // @768_65d070
  eax = (u32)(EBP - 76);  // @769_65d070
  PV[42] = (u32)(eax);  // @770_65d070
  edx = (u32)(EBP - 88);  // @771_65d070
  ecx = (u32)(EBP - 124);  // @772_65d070
  eax = ext_65da70_fastcall4(ecx, edx, PV[42], PV[41]);  // @773_65d070
  ecx = edx = 0;  // @774_65d070
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @775_65d070
  if (FL[2] == 0) goto L65d985;  // @776_65d070
  L65d955:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1052), sizeof v); (u32)v; });  // @778_65d070
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1056), sizeof v); (u32)v; });  // @779_65d070
  if (FL[0] >= FL[1]) goto L65d985;  // @780_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1036), sizeof v); (u32)v; });  // @781_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @782_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1028), sizeof v); (u32)v; });  // @783_65d070
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @784_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1036), sizeof v); (u32)v; });  // @785_65d070
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @786_65d070
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @787_65d070
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1052), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 1052), &v, sizeof v); }  // @788_65d070
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1052), sizeof v); (u32)v; });  // @789_65d070
  L65d985:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; });  // @791_65d070
  eax = (eax + 1);  // @792_65d070
  FL[3] = eax;  // @793_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @794_65d070
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1048), sizeof v); (u32)v; });  // @795_65d070
  if ((s32)FL[0] < (s32)FL[1]) goto L65d740;  // @796_65d070
  L65d99e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1036), sizeof v); (u32)v; });  // @798_65d070
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @799_65d070
  if (FL[0] != FL[1]) goto L65d9ba;  // @800_65d070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1032), sizeof v); (u32)v; });  // @801_65d070
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1052), sizeof v); (u32)v; }) + (u32)(-8))); __builtin_memcpy((void *)(u32)(edi + 1052), &v, sizeof v); }  // @802_65d070
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1052), sizeof v); (u32)v; });  // @803_65d070
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @804_65d070
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @805_65d070
  L65d9ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @807_65d070
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @808_65d070
  eax = (eax + 1);  // @809_65d070
  FL[3] = eax;  // @810_65d070
  ecx = (ecx + (u32)(4));  // @811_65d070
  FL[3] = ecx;  // @812_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @813_65d070
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 344), &v, sizeof v); }  // @814_65d070
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1044), sizeof v); (u32)v; });  // @815_65d070
  if ((s32)FL[0] < (s32)FL[1]) goto L65d662;  // @816_65d070
  L65d9e2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1032), sizeof v); (u32)v; });  // @818_65d070
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @819_65d070
  if (FL[0] != FL[1]) goto L65da0d;  // @820_65d070
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1052), sizeof v); (u32)v; }) + (u32)(-12))); __builtin_memcpy((void *)(u32)(edi + 1052), &v, sizeof v); }  // @821_65d070
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1052), sizeof v); (u32)v; });  // @822_65d070
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1040), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 1040), &v, sizeof v); }  // @823_65d070
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1040), sizeof v); (u32)v; });  // @824_65d070
  ext_633654(G(u32, 0x6f5630));  // @825_65d070
  return eax;  // @826_65d070
  L65da0d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1052), sizeof v); (u32)v; });  // @828_65d070
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @829_65d070
  L65da16:;
  ext_633654(G(u32, 0x6f5630));  // @831_65d070
  return eax;  // @832_65d070
}
PCREG(65d070, lifted_65d070);

