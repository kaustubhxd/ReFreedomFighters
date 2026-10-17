// batch234000.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d70_dbl(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d76_dbl(double) __asm__("ext_634d76");
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" double VECTORCALL ext_634de2_dbl(double) __asm__("ext_634de2");
extern "C" long double THISCALL ext_44c840_thiscall1_ld(u32) __asm__("ext_44c840");
extern "C" long double THISCALL ext_4dfda0_thiscall1_ld(u32) __asm__("ext_4dfda0");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_459fc0_fastcall3(u32, u32, u32) __asm__("ext_459fc0");
extern "C" u32 FASTCALL ext_4e0be0_fastcall2(u32, u32) __asm__("ext_4e0be0");
extern "C" u32 STDCALL ext_59a7e0_stdcall1(u32) __asm__("ext_59a7e0");
extern "C" u32 STDCALL ext_5dcd10_stdcall2(u32, u32) __asm__("ext_5dcd10");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4dc9c0_thiscall2(u32, u32) __asm__("ext_4dc9c0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4dff10_thiscall1(u32) __asm__("ext_4dff10");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_594ed0_thiscall2(u32, u32) __asm__("ext_594ed0");
extern "C" u32 THISCALL ext_594f10_thiscall2(u32, u32) __asm__("ext_594f10");
extern "C" u32 THISCALL ext_594f40_thiscall2(u32, u32) __asm__("ext_594f40");
extern "C" u32 THISCALL ext_59a720_thiscall2(u32, u32) __asm__("ext_59a720");
extern "C" u32 THISCALL ext_59a7a0_thiscall2(u32, u32) __asm__("ext_59a7a0");
extern "C" u32 THISCALL ext_59a800_thiscall2(u32, u32) __asm__("ext_59a800");
extern "C" u32 THISCALL ext_5b9050_thiscall2(u32, u32) __asm__("ext_5b9050");
extern "C" u32 THISCALL ext_5cca60_thiscall1(u32) __asm__("ext_5cca60");
extern "C" u32 THISCALL ext_5ccaa0_thiscall1(u32) __asm__("ext_5ccaa0");
extern "C" u32 THISCALL ext_5ccae0_thiscall1(u32) __asm__("ext_5ccae0");
extern "C" u32 THISCALL ext_5ccb40_thiscall1(u32) __asm__("ext_5ccb40");
extern "C" u32 THISCALL ext_5ccc80_thiscall1(u32) __asm__("ext_5ccc80");
extern "C" u32 THISCALL ext_5d0ba0_thiscall2(u32, u32) __asm__("ext_5d0ba0");
extern "C" u32 THISCALL ext_5d0c30_thiscall2(u32, u32) __asm__("ext_5d0c30");
extern "C" u32 THISCALL ext_5d0c60_thiscall2(u32, u32) __asm__("ext_5d0c60");
extern "C" u32 THISCALL ext_5d1190_thiscall2(u32, u32) __asm__("ext_5d1190");
extern "C" u32 THISCALL ext_5d1300_thiscall2(u32, u32) __asm__("ext_5d1300");
extern "C" u32 THISCALL ext_5d1350_thiscall2(u32, u32) __asm__("ext_5d1350");
extern "C" u32 THISCALL ext_5d13a0_thiscall2(u32, u32) __asm__("ext_5d13a0");
extern "C" u32 THISCALL ext_5d13f0_thiscall2(u32, u32) __asm__("ext_5d13f0");
extern "C" u32 THISCALL ext_5d24c0_thiscall2(u32, u32) __asm__("ext_5d24c0");
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

extern "C" u32 THISCALL lifted_5b8d80(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5b8d80
  PV[0] = (u32)(ecx);  // @1_5b8d80
  ecx = (u32)(EBP - 16);  // @2_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 138) + 0), 4); v; });  // @3_5b8d80
  X0[1] = 0;  // @4_5b8d80
  X0[2] = 0;  // @5_5b8d80
  X0[3] = 0;  // @6_5b8d80
  edx = (u32)(ebx + 162);  // @7_5b8d80
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @8_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 142) + 0), 4); v; });  // @9_5b8d80
  X0[1] = 0;  // @10_5b8d80
  X0[2] = 0;  // @11_5b8d80
  X0[3] = 0;  // @12_5b8d80
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @13_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 146) + 0), 4); v; });  // @14_5b8d80
  X0[1] = 0;  // @15_5b8d80
  X0[2] = 0;  // @16_5b8d80
  X0[3] = 0;  // @17_5b8d80
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @18_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 88) + 0), 4); v; });  // @19_5b8d80
  X0[1] = 0;  // @20_5b8d80
  X0[2] = 0;  // @21_5b8d80
  X0[3] = 0;  // @22_5b8d80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 179) + 0), 4); v; })));  // @23_5b8d80
  PV[1] = X0[0];  // @24_5b8d80
  eax = ext_451890_fastcall3(ecx, edx, PV[1]);  // @25_5b8d80
  ecx = 0;  // @26_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 126), sizeof v); (u32)v; });  // @27_5b8d80
  edx = (u32)(EBP - 16);  // @28_5b8d80
  PV[2] = (u32)(edx);  // @29_5b8d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5b8d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 120)))(ecx, PV[2]);  // @31_5b8d80
  ecx = edx = 0;  // @32_5b8d80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 222), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @33_5b8d80
  if (FL[0] == FL[1]) goto L5b8e12;  // @34_5b8d80
  eax = (u32)(ebx + 234);  // @35_5b8d80
  PV[3] = (u32)(eax);  // @36_5b8d80
  edx = (u32)(EBP - 16);  // @37_5b8d80
  ecx = (u32)(EBP - 28);  // @38_5b8d80
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[3]);  // @39_5b8d80
  ecx = edx = 0;  // @40_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 230), sizeof v); (u32)v; });  // @41_5b8d80
  edx = (u32)(EBP - 28);  // @42_5b8d80
  PV[4] = (u32)(edx);  // @43_5b8d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_5b8d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 120)))(ecx, PV[4]);  // @45_5b8d80
  ecx = edx = 0;  // @46_5b8d80
  L5b8e12:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 126), sizeof v); (u32)v; });  // @48_5b8d80
  eax = (u32)(EBP - 40);  // @49_5b8d80
  PV[5] = (u32)(eax);  // @50_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @51_5b8d80
  eax = ext_4db7c0_thiscall2(ecx, PV[5]);  // @52_5b8d80
  edx = 0;  // @53_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @54_5b8d80
  X0[1] = 0;  // @55_5b8d80
  X0[2] = 0;  // @56_5b8d80
  X0[3] = 0;  // @57_5b8d80
  edx = (u32)(ebx + 162);  // @58_5b8d80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6892384) + 0), 4); v; })));  // @59_5b8d80
  PV[6] = (u32)(ecx);  // @60_5b8d80
  ecx = (u32)(EBP - 16);  // @61_5b8d80
  PV[7] = X0[0];  // @62_5b8d80
  eax = ext_451890_fastcall3(ecx, edx, PV[7]);  // @63_5b8d80
  ecx = 0;  // @64_5b8d80
  eax = (u32)(EBP - 16);  // @65_5b8d80
  ecx = ebx;  // @66_5b8d80
  PV[8] = (u32)(eax);  // @67_5b8d80
  eax = ext_5b9050_thiscall2(ecx, PV[8]);  // @68_5b8d80
  ecx = edx = 0;  // @69_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; });  // @70_5b8d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_5b8d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @72_5b8d80
  ecx = edx = 0;  // @73_5b8d80
  FL[2] = (eax & eax);  // @74_5b8d80
  if (FL[2] == 0) goto L5b9031;  // @75_5b8d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @76_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; });  // @77_5b8d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @78_5b8d80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_5b8d80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @80_5b8d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(esi + 20)))(ecx);  // @81_5b8d80
  ecx = edx = 0;  // @82_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; });  // @83_5b8d80
  eax = (eax - 1);  // @84_5b8d80
  FL[3] = eax;  // @85_5b8d80
  PV[9] = (u32)(eax);  // @86_5b8d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 48)))(ecx, PV[9]);  // @87_5b8d80
  ecx = edx = 0;  // @88_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_5b8d80
  PV[10] = (u32)(eax);  // @90_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @91_5b8d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 88)))(ecx, PV[10]);  // @92_5b8d80
  ecx = edx = 0;  // @93_5b8d80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @94_5b8d80
  ecx = (u32)(EBP - 28);  // @95_5b8d80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @96_5b8d80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @97_5b8d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @98_5b8d80
  PV[11] = (u32)(ecx);  // @99_5b8d80
  ecx = eax;  // @100_5b8d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[11]);  // @101_5b8d80
  ecx = edx = 0;  // @102_5b8d80
  eax = (u32)(ebx + 138);  // @103_5b8d80
  PV[12] = (u32)(eax);  // @104_5b8d80
  edx = (u32)(ebx + 150);  // @105_5b8d80
  ecx = (u32)(EBP - 72);  // @106_5b8d80
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @107_5b8d80
  ecx = edx = 0;  // @108_5b8d80
  eax = (u32)(EBP - 28);  // @109_5b8d80
  PV[13] = (u32)(eax);  // @110_5b8d80
  edx = (u32)(ebx + 150);  // @111_5b8d80
  ecx = (u32)(EBP - 60);  // @112_5b8d80
  eax = ext_43e920_fastcall3(ecx, edx, PV[13]);  // @113_5b8d80
  ecx = edx = 0;  // @114_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @115_5b8d80
  X0[1] = 0;  // @116_5b8d80
  X0[2] = 0;  // @117_5b8d80
  X0[3] = 0;  // @118_5b8d80
  eax = (u32)(EBP - 72);  // @119_5b8d80
  X1[0] = 0;  // @120_5b8d80
  X1[1] = 0;  // @121_5b8d80
  X1[2] = 0;  // @122_5b8d80
  X1[3] = 0;  // @123_5b8d80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @124_5b8d80
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @125_5b8d80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @126_5b8d80
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @127_5b8d80
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b8f09;  // @128_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @129_5b8d80
  X0[1] = 0;  // @130_5b8d80
  X0[2] = 0;  // @131_5b8d80
  X0[3] = 0;  // @132_5b8d80
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @133_5b8d80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @134_5b8d80
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @135_5b8d80
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b8f09;  // @136_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @137_5b8d80
  X0[1] = 0;  // @138_5b8d80
  X0[2] = 0;  // @139_5b8d80
  X0[3] = 0;  // @140_5b8d80
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @141_5b8d80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @142_5b8d80
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @143_5b8d80
  if (__builtin_parity(FL[2] & 0xff)) goto L5b8f45;  // @144_5b8d80
  L5b8f09:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @146_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @147_5b8d80
  FS[0] = LDF((u32)(ecx));  // @148_5b8d80
  FS[0] = (FS[0] * FS[0]);  // @149_5b8d80
  FS[1] = LDF((u32)(ecx + 4));  // @150_5b8d80
  FS[1] = (FS[1] * FS[1]);  // @151_5b8d80
  FS[0] = (FS[0] + FS[1]);  // @152_5b8d80
  FS[1] = LDF((u32)(ecx + 8));  // @153_5b8d80
  FS[1] = (FS[1] * FS[1]);  // @154_5b8d80
  FS[0] = (FS[0] + FS[1]);  // @155_5b8d80
  FSQRT(FS[0]);  // @156_5b8d80
  FS[1] = LDF((u32)(EBP - 44));  // @157_5b8d80
  FS[1] = (FS[1] / FS[0]);  // @158_5b8d80
  FS[2] = LDF((u32)(ecx));  // @159_5b8d80
  FS[2] = (FS[2] * FS[1]);  // @160_5b8d80
  STF((u32)(ecx), FS[2]);  // @161_5b8d80
  FS[2] = LDF((u32)(ecx + 4));  // @162_5b8d80
  FS[2] = (FS[2] * FS[1]);  // @163_5b8d80
  STF((u32)(ecx + 4), FS[2]);  // @164_5b8d80
  FS[2] = LDF((u32)(ecx + 8));  // @165_5b8d80
  FS[1] = (FS[1] * FS[2]);  // @166_5b8d80
  STF((u32)(ecx + 8), FS[1]);  // @167_5b8d80
  STF((u32)(EBP - 44), FS[0]);  // @168_5b8d80
  L5b8f45:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @170_5b8d80
  X0[1] = 0;  // @171_5b8d80
  X0[2] = 0;  // @172_5b8d80
  X0[3] = 0;  // @173_5b8d80
  eax = (u32)(EBP - 60);  // @174_5b8d80
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @175_5b8d80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @176_5b8d80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @177_5b8d80
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @178_5b8d80
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b8f75;  // @179_5b8d80
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @180_5b8d80
  X2[1] = 0;  // @181_5b8d80
  X2[2] = 0;  // @182_5b8d80
  X2[3] = 0;  // @183_5b8d80
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @184_5b8d80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @185_5b8d80
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @186_5b8d80
  if (!__builtin_parity(FL[2] & 0xff)) goto L5b8f75;  // @187_5b8d80
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @188_5b8d80
  X3[1] = 0;  // @189_5b8d80
  X3[2] = 0;  // @190_5b8d80
  X3[3] = 0;  // @191_5b8d80
  FA = U2F(X3[0]); FB = U2F(X1[0]);  // @192_5b8d80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @193_5b8d80
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @194_5b8d80
  if (__builtin_parity(FL[2] & 0xff)) goto L5b8fc0;  // @195_5b8d80
  L5b8f75:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @197_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @198_5b8d80
  FS[0] = LDF((u32)(ecx));  // @199_5b8d80
  FS[0] = (FS[0] * FS[0]);  // @200_5b8d80
  FS[1] = LDF((u32)(ecx + 4));  // @201_5b8d80
  FS[1] = (FS[1] * FS[1]);  // @202_5b8d80
  FS[0] = (FS[0] + FS[1]);  // @203_5b8d80
  FS[1] = LDF((u32)(ecx + 8));  // @204_5b8d80
  FS[1] = (FS[1] * FS[1]);  // @205_5b8d80
  FS[0] = (FS[0] + FS[1]);  // @206_5b8d80
  FSQRT(FS[0]);  // @207_5b8d80
  FS[1] = LDF((u32)(EBP - 44));  // @208_5b8d80
  FS[1] = (FS[1] / FS[0]);  // @209_5b8d80
  FS[2] = LDF((u32)(ecx));  // @210_5b8d80
  FS[2] = (FS[2] * FS[1]);  // @211_5b8d80
  STF((u32)(ecx), FS[2]);  // @212_5b8d80
  FS[2] = LDF((u32)(ecx + 4));  // @213_5b8d80
  FS[2] = (FS[2] * FS[1]);  // @214_5b8d80
  STF((u32)(ecx + 4), FS[2]);  // @215_5b8d80
  FS[2] = LDF((u32)(ecx + 8));  // @216_5b8d80
  FS[1] = (FS[1] * FS[2]);  // @217_5b8d80
  STF((u32)(ecx + 8), FS[1]);  // @218_5b8d80
  STF((u32)(EBP - 44), FS[0]);  // @219_5b8d80
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @220_5b8d80
  X3[1] = 0;  // @221_5b8d80
  X3[2] = 0;  // @222_5b8d80
  X3[3] = 0;  // @223_5b8d80
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @224_5b8d80
  X2[1] = 0;  // @225_5b8d80
  X2[2] = 0;  // @226_5b8d80
  X2[3] = 0;  // @227_5b8d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @228_5b8d80
  X0[1] = 0;  // @229_5b8d80
  X0[2] = 0;  // @230_5b8d80
  X0[3] = 0;  // @231_5b8d80
  L5b8fc0:;
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; })));  // @233_5b8d80
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; })));  // @234_5b8d80
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; })));  // @235_5b8d80
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @236_5b8d80
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @237_5b8d80
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @238_5b8d80
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b9031;  // @239_5b8d80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 226), sizeof v); (u32)v; });  // @240_5b8d80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 178), &v, sizeof v); }  // @241_5b8d80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 179), &v, sizeof v); }  // @242_5b8d80
  FL[2] = (esi & esi);  // @243_5b8d80
  if (FL[2] == 0) goto L5b9031;  // @244_5b8d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @245_5b8d80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @246_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @247_5b8d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @248_5b8d80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7022324), (u32)(0), (u32)(7022224), (u32)(309), (u32)(0), (u32)(0));  // @249_5b8d80
  ecx = edx = 0;  // @250_5b8d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 226), sizeof v); (u32)v; });  // @251_5b8d80
  eax = (eax & 0xffff);  // @252_5b8d80
  PV[14] = (u32)(eax);  // @253_5b8d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[14]);  // @254_5b8d80
  ecx = edx = 0;  // @255_5b8d80
  L5b9031:;
  ext_633654(G(u32, 0x6f5630));  // @257_5b8d80
  return eax;  // @258_5b8d80
}
PCREG(5b8d80, lifted_5b8d80);

extern "C" u32 THISCALL lifted_5dc8b0(u32 ecx_in) {
  u8 F[0x650] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x550);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5dc8b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_5dc8b0
  if (FL[0] != FL[1]) goto L5dc8fe;  // @2_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @3_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7040040), (u32)(150));  // @5_5dc8b0
  ecx = edx = 0;  // @6_5dc8b0
  PV[0] = (u32)(eax);  // @7_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_5dc8b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 48)))(PV[0], (u32)(7040152));  // @9_5dc8b0
  ecx = edx = 0;  // @10_5dc8b0
  ext_633654(G(u32, 0x6f5630));  // @11_5dc8b0
  return eax;  // @12_5dc8b0
  L5dc8fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @15_5dc8b0
  X0[1] = 0;  // @16_5dc8b0
  X0[2] = 0;  // @17_5dc8b0
  X0[3] = 0;  // @18_5dc8b0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; })));  // @19_5dc8b0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 76) + 0), 4); v; }));  // @20_5dc8b0
  __builtin_memcpy((void *)((u32)(ebx + 72) + 0), &X0[0], 4);  // @21_5dc8b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5dcc0d;  // @22_5dc8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 88), sizeof v); (u32)v; });  // @23_5dc8b0
  FL[2] = (edx & edx);  // @24_5dc8b0
  if (FL[2] == 0) goto L5dc959;  // @25_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_5dc8b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @27_5dc8b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @28_5dc8b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @29_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_5dc8b0
  PV[1] = (u32)(edx);  // @31_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @33_5dc8b0
  ecx = edx = 0;  // @34_5dc8b0
  ecx = (u32)(EBP - 16);  // @35_5dc8b0
  PV[2] = (u32)(ecx);  // @36_5dc8b0
  ecx = eax;  // @37_5dc8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[2]);  // @39_5dc8b0
  ecx = edx = 0;  // @40_5dc8b0
  goto L5dc965;  // @41_5dc8b0
  L5dc959:;
  eax = (u32)(EBP - 16);  // @43_5dc8b0
  PV[3] = (u32)(eax);  // @44_5dc8b0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @45_5dc8b0
  eax = ext_5dcd10_stdcall2(PV[4], PV[3]);  // @46_5dc8b0
  ecx = edx = 0;  // @47_5dc8b0
  L5dc965:;
  ecx = (u32)(EBP - 64);  // @49_5dc8b0
  eax = ext_4de7a0_thiscall1(ecx);  // @50_5dc8b0
    // @51_5dc8b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @52_5dc8b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1212), &v, sizeof v); }  // @53_5dc8b0
  { u32 v = (u32)((u32)(3296329728)); __builtin_memcpy((void *)(u32)(EBP - 1208), &v, sizeof v); }  // @54_5dc8b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1204), &v, sizeof v); }  // @55_5dc8b0
  if (FL[0] == FL[1]) goto L5dcaa8;  // @56_5dc8b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 88), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @57_5dc8b0
  if (FL[0] != FL[1]) goto L5dcaa8;  // @58_5dc8b0
  ecx = (u32)(EBP - 1200);  // @59_5dc8b0
  eax = ext_4e1b60_thiscall1(ecx);  // @60_5dc8b0
    // @61_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @62_5dc8b0
  X0[1] = 0;  // @63_5dc8b0
  X0[2] = 0;  // @64_5dc8b0
  X0[3] = 0;  // @65_5dc8b0
  edx = (u32)(EBP - 1200);  // @66_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @67_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 1200) + 0), &X0[0], 4);  // @68_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @69_5dc8b0
  X0[1] = 0;  // @70_5dc8b0
  X0[2] = 0;  // @71_5dc8b0
  X0[3] = 0;  // @72_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 1196) + 0), &X0[0], 4);  // @73_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @74_5dc8b0
  X0[1] = 0;  // @75_5dc8b0
  X0[2] = 0;  // @76_5dc8b0
  X0[3] = 0;  // @77_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 1192) + 0), &X0[0], 4);  // @78_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1212) + 0), 4); v; });  // @79_5dc8b0
  X0[1] = 0;  // @80_5dc8b0
  X0[2] = 0;  // @81_5dc8b0
  X0[3] = 0;  // @82_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 1188) + 0), &X0[0], 4);  // @83_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1208) + 0), 4); v; });  // @84_5dc8b0
  X0[1] = 0;  // @85_5dc8b0
  X0[2] = 0;  // @86_5dc8b0
  X0[3] = 0;  // @87_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 1184) + 0), &X0[0], 4);  // @88_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1204) + 0), 4); v; });  // @89_5dc8b0
  X0[1] = 0;  // @90_5dc8b0
  X0[2] = 0;  // @91_5dc8b0
  X0[3] = 0;  // @92_5dc8b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1132), &v, sizeof v); }  // @93_5dc8b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1092), &v, sizeof v); }  // @94_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 1180) + 0), &X0[0], 4);  // @95_5dc8b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 1148), &v, sizeof v); }  // @96_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @97_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @98_5dc8b0
  PV[5] = (u32)(edx);  // @99_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @101_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[5], (u32)(0), (u32)(1), (u32)(1), (u32)(1), (u32)(0));  // @102_5dc8b0
  ecx = edx = 0;  // @103_5dc8b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @104_5dc8b0
  if (FL[2] == 0) goto L5dca9a;  // @105_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1160) + 0), 4); v; });  // @106_5dc8b0
  X0[1] = 0;  // @107_5dc8b0
  X0[2] = 0;  // @108_5dc8b0
  X0[3] = 0;  // @109_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_5dc8b0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1132), sizeof v); (u32)v; });  // @111_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @112_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1156) + 0), 4); v; });  // @113_5dc8b0
  X0[1] = 0;  // @114_5dc8b0
  X0[2] = 0;  // @115_5dc8b0
  X0[3] = 0;  // @116_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @117_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1152) + 0), 4); v; });  // @118_5dc8b0
  X0[1] = 0;  // @119_5dc8b0
  X0[2] = 0;  // @120_5dc8b0
  X0[3] = 0;  // @121_5dc8b0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @122_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @123_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[6]);  // @125_5dc8b0
  ecx = edx = 0;  // @126_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @127_5dc8b0
  eax = ext_4db3b0_thiscall1(ecx);  // @128_5dc8b0
  ecx = edx = 0;  // @129_5dc8b0
  edi = eax;  // @130_5dc8b0
  FL[2] = (edi & edi);  // @131_5dc8b0
  if (FL[2] != 0) goto L5dcaf5;  // @132_5dc8b0
  goto L5dcaa8;  // @133_5dc8b0
  L5dca9a:;
  edx = (u32)(EBP - 1212);  // @135_5dc8b0
  ecx = (u32)(EBP - 16);  // @136_5dc8b0
  eax = ext_441940_fastcall2(ecx, edx);  // @137_5dc8b0
  ecx = edx = 0;  // @138_5dc8b0
  L5dcaa8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @140_5dc8b0
  edx = (u32)(EBP - 28);  // @141_5dc8b0
  PV[7] = (u32)(edx);  // @142_5dc8b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @143_5dc8b0
  edx = (u32)(EBP - 16);  // @144_5dc8b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @145_5dc8b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @146_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @147_5dc8b0
  PV[8] = (u32)(edx);  // @148_5dc8b0
  edx = (u32)(EBP - 64);  // @149_5dc8b0
  PV[9] = (u32)(edx);  // @150_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @151_5dc8b0
  edx = (u32)(EBP - 64);  // @152_5dc8b0
  PV[10] = (u32)(edx);  // @153_5dc8b0
  edx = (u32)(EBP - 1088);  // @154_5dc8b0
  PV[11] = (u32)(edx);  // @155_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @156_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, PV[11], PV[10], PV[9], PV[8], PV[7]);  // @157_5dc8b0
  ecx = edx = 0;  // @158_5dc8b0
  FL[2] = (eax & eax);  // @159_5dc8b0
  if (FL[2] == 0) goto L5dcc0c;  // @160_5dc8b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1088), sizeof v); (u32)v; });  // @161_5dc8b0
  L5dcaf5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @163_5dc8b0
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @164_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @165_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @166_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[12]);  // @167_5dc8b0
  ecx = edx = 0;  // @168_5dc8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @169_5dc8b0
  esi = eax;  // @170_5dc8b0
  eax = (u32)(EBP - 16);  // @171_5dc8b0
  ecx = edi;  // @172_5dc8b0
  PV[13] = (u32)(eax);  // @173_5dc8b0
  eax = (u32)(EBP - 64);  // @174_5dc8b0
  PV[14] = (u32)(eax);  // @175_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 148)))(ecx, PV[14], PV[13]);  // @176_5dc8b0
  ecx = edx = 0;  // @177_5dc8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @178_5dc8b0
  eax = (u32)(EBP - 16);  // @179_5dc8b0
  PV[15] = (u32)(eax);  // @180_5dc8b0
  eax = (u32)(EBP - 64);  // @181_5dc8b0
  ecx = esi;  // @182_5dc8b0
  PV[16] = (u32)(eax);  // @183_5dc8b0
  PV[17] = (u32)(edi);  // @184_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 444)))(ecx, PV[17], PV[16], PV[15], (u32)(0), (u32)(0), (u32)(0), (u32)(1));  // @185_5dc8b0
  ecx = edx = 0;  // @186_5dc8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @187_5dc8b0
  FL[2] = (edx & edx);  // @188_5dc8b0
  if (FL[2] == 0) goto L5dcb77;  // @189_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @190_5dc8b0
  PV[18] = (u32)(edx);  // @191_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @192_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @193_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[18]);  // @194_5dc8b0
  ecx = edx = 0;  // @195_5dc8b0
  esi = eax;  // @196_5dc8b0
  eax = (u32)(EBP - 16);  // @197_5dc8b0
  PV[19] = (u32)(eax);  // @198_5dc8b0
  eax = (u32)(EBP - 64);  // @199_5dc8b0
  ecx = esi;  // @200_5dc8b0
  PV[20] = (u32)(eax);  // @201_5dc8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @202_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[20], PV[19]);  // @203_5dc8b0
  ecx = edx = 0;  // @204_5dc8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @205_5dc8b0
  ecx = esi;  // @206_5dc8b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422864), sizeof v); (u32)v; });  // @207_5dc8b0
  PV[21] = (u32)(eax);  // @208_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[21], (u32)(0), (u32)(0));  // @209_5dc8b0
  ecx = edx = 0;  // @210_5dc8b0
  L5dcb77:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 88), sizeof v); (u32)v; });  // @212_5dc8b0
  FL[2] = (edx & edx);  // @213_5dc8b0
  if (FL[2] == 0) goto L5dcbc8;  // @214_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @215_5dc8b0
  PV[22] = (u32)(edx);  // @216_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @217_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @218_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[22]);  // @219_5dc8b0
  ecx = edx = 0;  // @220_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @221_5dc8b0
  esi = eax;  // @222_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @223_5dc8b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @224_5dc8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @225_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 276)))(ecx, (u32)(6997928), (u32)(0), (u32)(7040040), (u32)(234), (u32)(0), (u32)(0));  // @226_5dc8b0
  ecx = edx = 0;  // @227_5dc8b0
  eax = (eax & 0xffff);  // @228_5dc8b0
  ecx = esi;  // @229_5dc8b0
  PV[23] = (u32)(eax);  // @230_5dc8b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 296)))(ecx, PV[23]);  // @231_5dc8b0
  ecx = edx = 0;  // @232_5dc8b0
  L5dcbc8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @234_5dc8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @235_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @236_5dc8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @237_5dc8b0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7040040), (u32)(133));  // @238_5dc8b0
  ecx = edx = 0;  // @239_5dc8b0
  FS[0] = (FS[0] * LDF((u32)(ebx + 96)));  // @240_5dc8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 92) + 0), 4); v; });  // @241_5dc8b0
  X0[1] = 0;  // @242_5dc8b0
  X0[2] = 0;  // @243_5dc8b0
  X0[3] = 0;  // @244_5dc8b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 88), &v, sizeof v); }  // @245_5dc8b0
  STF((u32)(EBP - 1216), FS[0]);  // @246_5dc8b0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1216) + 0), 4); v; })));  // @247_5dc8b0
  __builtin_memcpy((void *)((u32)(ebx + 76) + 0), &X0[0], 4);  // @248_5dc8b0
  L5dcc0c:;
  L5dcc0d:;
  ext_633654(G(u32, 0x6f5630));  // @251_5dc8b0
  return eax;  // @252_5dc8b0
}
PCREG(5dc8b0, lifted_5dc8b0);

extern "C" u32 THISCALL lifted_47ca20(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_47ca20
  X2[0] = 0;  // @1_47ca20
  X2[1] = 0;  // @2_47ca20
  X2[2] = 0;  // @3_47ca20
  X2[3] = 0;  // @4_47ca20
  esi = ecx;  // @5_47ca20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @6_47ca20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_47ca20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @8_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 1604) + 0), 4); v; });  // @9_47ca20
  X0[1] = 0;  // @10_47ca20
  X0[2] = 0;  // @11_47ca20
  X0[3] = 0;  // @12_47ca20
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @13_47ca20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @14_47ca20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @15_47ca20
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); edx = (u32)r_; }  // @16_47ca20
  eax = (eax - edx);  // @17_47ca20
  FL[3] = eax;  // @18_47ca20
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @19_47ca20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @20_47ca20
  X1[0] = F2U((float)(s32)X1[0]);  // @21_47ca20
  X1[1] = F2U((float)(s32)X1[1]);  // @22_47ca20
  X1[2] = F2U((float)(s32)X1[2]);  // @23_47ca20
  X1[3] = F2U((float)(s32)X1[3]);  // @24_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @25_47ca20
  X0[1] = 0;  // @26_47ca20
  X0[2] = 0;  // @27_47ca20
  X0[3] = 0;  // @28_47ca20
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @29_47ca20
  X3[1] = 0;  // @30_47ca20
  X3[2] = 0;  // @31_47ca20
  X3[3] = 0;  // @32_47ca20
  eax = (u32)(EBP - 16);  // @33_47ca20
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @34_47ca20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @35_47ca20
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @36_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X1[0], 4);  // @37_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @38_47ca20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @39_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X3[0], 4);  // @40_47ca20
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @41_47ca20
  if (!__builtin_parity(FL[2] & 0xff)) goto L47caa7;  // @42_47ca20
  FA = U2F(X3[0]); FB = U2F(X2[0]);  // @43_47ca20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @44_47ca20
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @45_47ca20
  if (__builtin_parity(FL[2] & 0xff)) goto L47caf1;  // @46_47ca20
  L47caa7:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @48_47ca20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @49_47ca20
  FS[0] = LDF((u32)(ecx));  // @50_47ca20
  FS[0] = (FS[0] * FS[0]);  // @51_47ca20
  FS[1] = LDF((u32)(ecx + 4));  // @52_47ca20
  FS[1] = (FS[1] * FS[1]);  // @53_47ca20
  FS[0] = (FS[0] + FS[1]);  // @54_47ca20
  FS[1] = LDF((u32)(ecx + 8));  // @55_47ca20
  FS[1] = (FS[1] * FS[1]);  // @56_47ca20
  FS[0] = (FS[0] + FS[1]);  // @57_47ca20
  FSQRT(FS[0]);  // @58_47ca20
  FS[1] = LDF((u32)(EBP - 32));  // @59_47ca20
  FS[1] = (FS[1] / FS[0]);  // @60_47ca20
  FS[2] = LDF((u32)(ecx));  // @61_47ca20
  FS[2] = (FS[2] * FS[1]);  // @62_47ca20
  STF((u32)(ecx), FS[2]);  // @63_47ca20
  FS[2] = LDF((u32)(ecx + 4));  // @64_47ca20
  FS[2] = (FS[2] * FS[1]);  // @65_47ca20
  STF((u32)(ecx + 4), FS[2]);  // @66_47ca20
  FS[2] = LDF((u32)(ecx + 8));  // @67_47ca20
  FS[1] = (FS[1] * FS[2]);  // @68_47ca20
  STF((u32)(ecx + 8), FS[1]);  // @69_47ca20
  STF((u32)(EBP - 32), FS[0]);  // @70_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @71_47ca20
  X0[1] = 0;  // @72_47ca20
  X0[2] = 0;  // @73_47ca20
  X0[3] = 0;  // @74_47ca20
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @75_47ca20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @76_47ca20
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @77_47ca20
  if (!__builtin_parity(FL[2] & 0xff)) goto L47cb10;  // @78_47ca20
  L47caf1:;
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @80_47ca20
  X5[1] = 0;  // @81_47ca20
  X5[2] = 0;  // @82_47ca20
  X5[3] = 0;  // @83_47ca20
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @84_47ca20
  X3[1] = 0;  // @85_47ca20
  X3[2] = 0;  // @86_47ca20
  X3[3] = 0;  // @87_47ca20
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @88_47ca20
  X4[1] = 0;  // @89_47ca20
  X4[2] = 0;  // @90_47ca20
  X4[3] = 0;  // @91_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X5[0], 4);  // @92_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X3[0], 4);  // @93_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X4[0], 4);  // @94_47ca20
  goto L47cb1f;  // @95_47ca20
  L47cb10:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @97_47ca20
  X4[1] = 0;  // @98_47ca20
  X4[2] = 0;  // @99_47ca20
  X4[3] = 0;  // @100_47ca20
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @101_47ca20
  X3[1] = 0;  // @102_47ca20
  X3[2] = 0;  // @103_47ca20
  X3[3] = 0;  // @104_47ca20
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @105_47ca20
  X5[1] = 0;  // @106_47ca20
  X5[2] = 0;  // @107_47ca20
  X5[3] = 0;  // @108_47ca20
  L47cb1f:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1876), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @110_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X5[0], 4);  // @111_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X3[0], 4);  // @112_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X4[0], 4);  // @113_47ca20
  if (FL[0] == FL[1]) goto L47cb65;  // @114_47ca20
  ecx = (u32)(EBP - 16);  // @115_47ca20
  eax = ext_4e09b0_thiscall1(ecx);  // @116_47ca20
    // @117_47ca20
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @118_47ca20
  X4[1] = 0;  // @119_47ca20
  X4[2] = 0;  // @120_47ca20
  X4[3] = 0;  // @121_47ca20
  X2[0] = 0;  // @122_47ca20
  X2[1] = 0;  // @123_47ca20
  X2[2] = 0;  // @124_47ca20
  X2[3] = 0;  // @125_47ca20
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @126_47ca20
  X3[1] = 0;  // @127_47ca20
  X3[2] = 0;  // @128_47ca20
  X3[3] = 0;  // @129_47ca20
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @130_47ca20
  X5[1] = 0;  // @131_47ca20
  X5[2] = 0;  // @132_47ca20
  X5[3] = 0;  // @133_47ca20
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @134_47ca20
  X1[1] = 0;  // @135_47ca20
  X1[2] = 0;  // @136_47ca20
  X1[3] = 0;  // @137_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X4[0], 4);  // @138_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X3[0], 4);  // @139_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X5[0], 4);  // @140_47ca20
  L47cb65:;
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @142_47ca20
  X6[1] = 0;  // @143_47ca20
  X6[2] = 0;  // @144_47ca20
  X6[3] = 0;  // @145_47ca20
  FA = U2F(X6[0]); FB = U2F(X5[0]);  // @146_47ca20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @147_47ca20
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @148_47ca20
  if (!__builtin_parity(FL[2] & 0xff)) goto L47cbfd;  // @149_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @150_47ca20
  X0[1] = 0;  // @151_47ca20
  X0[2] = 0;  // @152_47ca20
  X0[3] = 0;  // @153_47ca20
  FA = U2F(X0[0]); FB = U2F(X3[0]);  // @154_47ca20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @155_47ca20
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @156_47ca20
  if (!__builtin_parity(FL[2] & 0xff)) goto L47cbfd;  // @157_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @158_47ca20
  X0[1] = 0;  // @159_47ca20
  X0[2] = 0;  // @160_47ca20
  X0[3] = 0;  // @161_47ca20
  FA = U2F(X0[0]); FB = U2F(X4[0]);  // @162_47ca20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @163_47ca20
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @164_47ca20
  if (!__builtin_parity(FL[2] & 0xff)) goto L47cbfd;  // @165_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 1901) + 0), 4); v; });  // @166_47ca20
  X0[1] = 0;  // @167_47ca20
  X0[2] = 0;  // @168_47ca20
  X0[3] = 0;  // @169_47ca20
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @170_47ca20
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cbb5;  // @171_47ca20
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; })));  // @172_47ca20
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @173_47ca20
  __builtin_memcpy((void *)((u32)(esi + 1901) + 0), &X0[0], 4);  // @174_47ca20
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @175_47ca20
  goto L47cbce;  // @176_47ca20
  L47cbb5:;
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @178_47ca20
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cbda;  // @179_47ca20
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; })));  // @180_47ca20
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @181_47ca20
  __builtin_memcpy((void *)((u32)(esi + 1901) + 0), &X1[0], 4);  // @182_47ca20
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @183_47ca20
  L47cbce:;
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cbda;  // @185_47ca20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1901), &v, sizeof v); }  // @186_47ca20
  L47cbda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @188_47ca20
  __builtin_memcpy((void *)((u32)(eax) + 0), &X5[0], 4);  // @189_47ca20
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X3[0], 4);  // @190_47ca20
  __builtin_memcpy((void *)((u32)(eax + 8) + 0), &X4[0], 4);  // @191_47ca20
  ext_633654(G(u32, 0x6f5630));  // @192_47ca20
  return eax;  // @193_47ca20
  L47cbfd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @195_47ca20
  X0[1] = 0;  // @196_47ca20
  X0[2] = 0;  // @197_47ca20
  X0[3] = 0;  // @198_47ca20
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @199_47ca20
  X6[0] = F2U(U2F(X6[0]) * U2F(X5[0]));  // @200_47ca20
  X6[0] = F2U(U2F(X6[0]) + U2F(X0[0]));  // @201_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @202_47ca20
  X0[1] = 0;  // @203_47ca20
  X0[2] = 0;  // @204_47ca20
  X0[3] = 0;  // @205_47ca20
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @206_47ca20
  X6[0] = F2U(U2F(X6[0]) + U2F(X0[0]));  // @207_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860520) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860520) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @208_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X6[0], 4);  // @209_47ca20
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @210_47ca20
  ecx = edx = 0;  // @211_47ca20
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @212_47ca20
  X2[1] = 0;  // @213_47ca20
  X2[2] = 0;  // @214_47ca20
  X2[3] = 0;  // @215_47ca20
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @216_47ca20
  X3[1] = 0;  // @217_47ca20
  X3[2] = 0;  // @218_47ca20
  X3[3] = 0;  // @219_47ca20
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @220_47ca20
  FA = U2D(X1[0], X1[1]); FB = U2D(X0[0], X0[1]);  // @221_47ca20
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @222_47ca20
  X1[1] = 0;  // @223_47ca20
  X1[2] = 0;  // @224_47ca20
  X1[3] = 0;  // @225_47ca20
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cc70;  // @226_47ca20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @227_47ca20
  X0[0] = 0;  // @228_47ca20
  X0[1] = 0;  // @229_47ca20
  X0[2] = 0;  // @230_47ca20
  X0[3] = 0;  // @231_47ca20
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @232_47ca20
  X2[1] = 0;  // @233_47ca20
  X2[2] = 0;  // @234_47ca20
  X2[3] = 0;  // @235_47ca20
  __builtin_memcpy((void *)((u32)(eax) + 0), &X2[0], 4);  // @236_47ca20
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @237_47ca20
  X2[1] = 0;  // @238_47ca20
  X2[2] = 0;  // @239_47ca20
  X2[3] = 0;  // @240_47ca20
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X2[0], 4);  // @241_47ca20
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @242_47ca20
  X2[1] = 0;  // @243_47ca20
  X2[2] = 0;  // @244_47ca20
  X2[3] = 0;  // @245_47ca20
  __builtin_memcpy((void *)((u32)(eax + 8) + 0), &X2[0], 4);  // @246_47ca20
  goto L47cd5c;  // @247_47ca20
  L47cc70:;
  FA = U2F(X2[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @249_47ca20
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cc7e;  // @250_47ca20
  X2[0] = 0;  // @251_47ca20
  X2[1] = 0;  // @252_47ca20
  X2[2] = 0;  // @253_47ca20
  X2[3] = 0;  // @254_47ca20
  goto L47cca1;  // @255_47ca20
  L47cc7e:;
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @257_47ca20
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cc8d;  // @258_47ca20
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @259_47ca20
  X2[1] = 0;  // @260_47ca20
  X2[2] = 0;  // @261_47ca20
  X2[3] = 0;  // @262_47ca20
  goto L47cca1;  // @263_47ca20
  L47cc8d:;
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @265_47ca20
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @266_47ca20
  ecx = edx = 0;  // @267_47ca20
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @268_47ca20
  X3[1] = 0;  // @269_47ca20
  X3[2] = 0;  // @270_47ca20
  X3[3] = 0;  // @271_47ca20
  X2[0] = 0;  // @272_47ca20
  X2[1] = 0;  // @273_47ca20
  X2[2] = 0;  // @274_47ca20
  X2[3] = 0;  // @275_47ca20
  X2[0] = F2U((float)U2D(X0[0], X0[1]));  // @276_47ca20
  L47cca1:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 1901) + 0), 4); v; });  // @278_47ca20
  X1[1] = 0;  // @279_47ca20
  X1[2] = 0;  // @280_47ca20
  X1[3] = 0;  // @281_47ca20
  edx = (u32)(EBP - 16);  // @282_47ca20
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @283_47ca20
  PV[0] = (u32)(edi);  // @284_47ca20
  ecx = (u32)(EBP - 64);  // @285_47ca20
  { double a_ = (double)U2F(X3[0]), b_ = (double)U2F(X3[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @286_47ca20
  X1[0] = X1[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @287_47ca20
  X1[1] = X1[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @288_47ca20
  X1[2] = X1[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @289_47ca20
  X1[3] = X1[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @290_47ca20
  SD(&X1[0], U2D(X1[0], X1[1]) * U2D(X0[0], X0[1]));  // @291_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @292_47ca20
  X0[1] = 0;  // @293_47ca20
  X0[2] = 0;  // @294_47ca20
  X0[3] = 0;  // @295_47ca20
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @296_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X2[0], 4);  // @297_47ca20
  SD(&X1[0], U2D(X1[0], X1[1]) * U2D(X0[0], X0[1]));  // @298_47ca20
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @299_47ca20
  X1[0] = X2[0];  // @300_47ca20
  X1[1] = X2[1];  // @301_47ca20
  X1[2] = X2[2];  // @302_47ca20
  X1[3] = X2[3];  // @303_47ca20
  { float a_ = U2F(X1[0]), b_ = U2F(X0[0]); X1[0] = (a_ < b_) ? X1[0] : F2U(b_); }  // @304_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X1[0], 4);  // @305_47ca20
  eax = ext_446ee0_fastcall3(ecx, edx, PV[0]);  // @306_47ca20
  ecx = edx = 0;  // @307_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @308_47ca20
  X0[1] = 0;  // @309_47ca20
  X0[2] = 0;  // @310_47ca20
  X0[3] = 0;  // @311_47ca20
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @312_47ca20
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cd17;  // @313_47ca20
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @314_47ca20
  X1[1] = 0;  // @315_47ca20
  X1[2] = 0;  // @316_47ca20
  X1[3] = 0;  // @317_47ca20
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @318_47ca20
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @319_47ca20
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @320_47ca20
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @321_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X1[0], 4);  // @322_47ca20
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @323_47ca20
  X1[1] = 0;  // @324_47ca20
  X1[2] = 0;  // @325_47ca20
  X1[3] = 0;  // @326_47ca20
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @327_47ca20
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @328_47ca20
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @329_47ca20
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @330_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X1[0], 4);  // @331_47ca20
  L47cd17:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @333_47ca20
  edx = (u32)(EBP - 28);  // @334_47ca20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @335_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @336_47ca20
  X0[1] = 0;  // @337_47ca20
  X0[2] = 0;  // @338_47ca20
  X0[3] = 0;  // @339_47ca20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @340_47ca20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @341_47ca20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @342_47ca20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @343_47ca20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @344_47ca20
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @345_47ca20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @346_47ca20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @347_47ca20
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @348_47ca20
  ecx = edx = 0;  // @349_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @350_47ca20
  X0[1] = 0;  // @351_47ca20
  X0[2] = 0;  // @352_47ca20
  X0[3] = 0;  // @353_47ca20
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @354_47ca20
  X1[1] = 0;  // @355_47ca20
  X1[2] = 0;  // @356_47ca20
  X1[3] = 0;  // @357_47ca20
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @358_47ca20
  X3[1] = 0;  // @359_47ca20
  X3[2] = 0;  // @360_47ca20
  X3[3] = 0;  // @361_47ca20
  L47cd5c:;
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @363_47ca20
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @364_47ca20
  X2[1] = 0;  // @365_47ca20
  X2[2] = 0;  // @366_47ca20
  X2[3] = 0;  // @367_47ca20
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @368_47ca20
  { float a_ = U2F(X2[0]), b_ = U2F(X0[0]); X2[0] = (a_ < b_) ? X2[0] : F2U(b_); }  // @369_47ca20
  { float a_ = U2F(X1[0]), b_ = U2F(X2[0]); X1[0] = (a_ > b_) ? X1[0] : F2U(b_); }  // @370_47ca20
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 1901) + 0), 4); v; });  // @371_47ca20
  X2[1] = 0;  // @372_47ca20
  X2[2] = 0;  // @373_47ca20
  X2[3] = 0;  // @374_47ca20
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @375_47ca20
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cd9f;  // @376_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @377_47ca20
  X0[1] = 0;  // @378_47ca20
  X0[2] = 0;  // @379_47ca20
  X0[3] = 0;  // @380_47ca20
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @381_47ca20
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @382_47ca20
  __builtin_memcpy((void *)((u32)(esi + 1901) + 0), &X0[0], 4);  // @383_47ca20
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @384_47ca20
  goto L47cdbc;  // @385_47ca20
  L47cd9f:;
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @387_47ca20
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cdc6;  // @388_47ca20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @389_47ca20
  X0[1] = 0;  // @390_47ca20
  X0[2] = 0;  // @391_47ca20
  X0[3] = 0;  // @392_47ca20
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @393_47ca20
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @394_47ca20
  __builtin_memcpy((void *)((u32)(esi + 1901) + 0), &X2[0], 4);  // @395_47ca20
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @396_47ca20
  L47cdbc:;
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L47cdc6;  // @398_47ca20
  __builtin_memcpy((void *)((u32)(esi + 1901) + 0), &X1[0], 4);  // @399_47ca20
  L47cdc6:;
  ext_633654(G(u32, 0x6f5630));  // @401_47ca20
  return eax;  // @402_47ca20
}
PCREG(47ca20, lifted_47ca20);

extern "C" u32 THISCALL lifted_47c160(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
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
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_47c160
  edi = ecx;  // @1_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 764), sizeof v); (u32)v; });  // @3_47c160
  eax = ((u32(THISCALL *)(u32))(eax))(edi);  // @4_47c160   (w3g hand fix: register call with the entry ecx = this)
  ecx = edx = 0;  // @5_47c160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @6_47c160
  if (FL[2] != 0) goto L47c4c3;  // @7_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @8_47c160
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(4096));  // @9_47c160
  if (FL[2] != 0) goto L47c1a2;  // @10_47c160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @11_47c160
  if (FL[0] == FL[1]) goto L47c4c3;  // @12_47c160
  L47c1a2:;
  ebx = 0;  // @14_47c160
  FL[3] = ebx;  // @15_47c160
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @16_47c160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1790), sizeof v); (u32)v; }); FL[1] = (ebx & 0xff);  // @17_47c160
  if (FL[0] == FL[1]) goto L47c3f7;  // @18_47c160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @19_47c160
  X1[1] = 0;  // @20_47c160
  X1[2] = 0;  // @21_47c160
  X1[3] = 0;  // @22_47c160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @23_47c160
  X0[1] = 0;  // @24_47c160
  X0[2] = 0;  // @25_47c160
  X0[3] = 0;  // @26_47c160
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @27_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_47c160
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @29_47c160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @30_47c160
  X0[1] = 0;  // @31_47c160
  X0[2] = 0;  // @32_47c160
  X0[3] = 0;  // @33_47c160
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @34_47c160
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @35_47c160
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @36_47c160
  { u32 v = (u32)((u32)(3279552512)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @37_47c160
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @38_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @39_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @40_47c160
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1796), sizeof v); (u32)v; });  // @41_47c160
  PV[0] = (u32)(eax);  // @42_47c160
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1791), sizeof v); (u32)v; });  // @43_47c160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_47c160
  eax = (u32)(EBP - 28);  // @45_47c160
  PV[2] = (u32)(eax);  // @46_47c160
  eax = (u32)(EBP - 16);  // @47_47c160
  PV[3] = (u32)(eax);  // @48_47c160
  PV[4] = (u32)(ebx);  // @49_47c160
  eax = (u32)(EBP - 112);  // @50_47c160
  PV[5] = (u32)(eax);  // @51_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 48), sizeof v); (u32)v; });  // @52_47c160
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[5], PV[4], PV[3], PV[2], (u32)(1), PV[1], (u32)(1), PV[0]);  // @53_47c160
  ecx = edx = 0;  // @54_47c160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @55_47c160
  if (FL[2] != 0) goto L47c343;  // @56_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 452), sizeof v); (u32)v; });  // @59_47c160
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6858692), (u32)(1765));  // @60_47c160
  ecx = edx = 0;  // @61_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_47c160
  STF((u32)(EBP - 124), FS[0]);  // @63_47c160
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @64_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 452), sizeof v); (u32)v; });  // @66_47c160
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6858692), (u32)(1765));  // @67_47c160
  ecx = edx = 0;  // @68_47c160
  STF((u32)(EBP - 116), FS[0]);  // @69_47c160
  ecx = (u32)(EBP - 124);  // @70_47c160
  FS[0] = ext_44c840_thiscall1_ld(ecx);  // @71_47c160
  ecx = 0;  // @72_47c160
  STF((u32)(EBP - 128), FS[0]);  // @73_47c160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 128) + 0), 4); v; });  // @74_47c160
  X0[1] = 0;  // @75_47c160
  X0[2] = 0;  // @76_47c160
  X0[3] = 0;  // @77_47c160
  X1[0] = 0;  // @78_47c160
  X1[1] = 0;  // @79_47c160
  X1[2] = 0;  // @80_47c160
  X1[3] = 0;  // @81_47c160
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @82_47c160
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @83_47c160
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @84_47c160
  if (!__builtin_parity(FL[2] & 0xff)) goto L47c28c;  // @85_47c160
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @86_47c160
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @87_47c160
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @88_47c160
  L47c28c:;
  PV[6] = (u32)(ecx);  // @90_47c160
  edx = (u32)(EBP - 124);  // @91_47c160
  ecx = (u32)(EBP - 16);  // @92_47c160
  eax = ext_451890_fastcall3(ecx, edx, (u32)(1092616192));  // @93_47c160
  ecx = 0;  // @94_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @96_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @97_47c160
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1796), sizeof v); (u32)v; });  // @98_47c160
  PV[7] = (u32)(eax);  // @99_47c160
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1791), sizeof v); (u32)v; });  // @100_47c160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @101_47c160
  eax = (u32)(EBP - 28);  // @102_47c160
  PV[9] = (u32)(eax);  // @103_47c160
  eax = (u32)(EBP - 16);  // @104_47c160
  PV[10] = (u32)(eax);  // @105_47c160
  eax = (u32)(EBP - 112);  // @106_47c160
  PV[11] = (u32)(eax);  // @107_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 48), sizeof v); (u32)v; });  // @108_47c160
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[11], (u32)(0), PV[10], PV[9], (u32)(1), PV[8], (u32)(1), PV[7]);  // @109_47c160
  ecx = edx = 0;  // @110_47c160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @111_47c160
  if (FL[2] != 0) goto L47c343;  // @112_47c160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @113_47c160
  X1[1] = 0;  // @114_47c160
  X1[2] = 0;  // @115_47c160
  X1[3] = 0;  // @116_47c160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @117_47c160
  X0[1] = 0;  // @118_47c160
  X0[2] = 0;  // @119_47c160
  X0[3] = 0;  // @120_47c160
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @121_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @122_47c160
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @123_47c160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @124_47c160
  X0[1] = 0;  // @125_47c160
  X0[2] = 0;  // @126_47c160
  X0[3] = 0;  // @127_47c160
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @128_47c160
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @129_47c160
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @130_47c160
  { u32 v = (u32)((u32)(3315351552)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @131_47c160
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @132_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @133_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @134_47c160
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1796), sizeof v); (u32)v; });  // @135_47c160
  PV[12] = (u32)(eax);  // @136_47c160
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1791), sizeof v); (u32)v; });  // @137_47c160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @138_47c160
  eax = (u32)(EBP - 28);  // @139_47c160
  PV[14] = (u32)(eax);  // @140_47c160
  eax = (u32)(EBP - 16);  // @141_47c160
  PV[15] = (u32)(eax);  // @142_47c160
  eax = (u32)(EBP - 112);  // @143_47c160
  PV[16] = (u32)(eax);  // @144_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 48), sizeof v); (u32)v; });  // @145_47c160
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[16], (u32)(0), PV[15], PV[14], (u32)(1), PV[13], (u32)(1), PV[12]);  // @146_47c160
  ecx = edx = 0;  // @147_47c160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @148_47c160
  if (FL[2] == 0) goto L47c36d;  // @149_47c160
  L47c343:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 104) + 0), 4); v; });  // @151_47c160
  X0[1] = 0;  // @152_47c160
  X0[2] = 0;  // @153_47c160
  X0[3] = 0;  // @154_47c160
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @155_47c160
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @156_47c160
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(edi + 1795), &v, sizeof v); }  // @157_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @158_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @159_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @160_47c160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[17]);  // @161_47c160
  ecx = edx = 0;  // @162_47c160
  ebx = eax;  // @163_47c160
  goto L47c3f7;  // @164_47c160
  L47c36d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338568) + 0), 4); v; });  // @166_47c160
  X0[1] = 0;  // @167_47c160
  X0[2] = 0;  // @168_47c160
  X0[3] = 0;  // @169_47c160
  X1[0] = 0;  // @170_47c160
  X1[1] = 0;  // @171_47c160
  X1[2] = 0;  // @172_47c160
  X1[3] = 0;  // @173_47c160
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @174_47c160
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @175_47c160
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @176_47c160
  if (__builtin_parity(FL[2] & 0xff)) goto L47c3f0;  // @177_47c160
  eax = (u32)(EBP - 28);  // @178_47c160
  PV[18] = (u32)(eax);  // @179_47c160
  edx = (u32)(EBP - 16);  // @180_47c160
  ecx = (u32)(EBP - 40);  // @181_47c160
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[18]);  // @182_47c160
  ecx = edx = 0;  // @183_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @184_47c160
  edx = (u32)(EBP - 40);  // @185_47c160
  PV[19] = (u32)(edx);  // @186_47c160
  edx = (u32)(EBP - 16);  // @187_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @188_47c160
  PV[20] = (u32)(edx);  // @189_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @190_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @191_47c160
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[20], PV[19], (u32)(16711680));  // @192_47c160
  ecx = edx = 0;  // @193_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @194_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @195_47c160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6858692), (u32)(1787));  // @196_47c160
  ecx = edx = 0;  // @197_47c160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @198_47c160
  ecx = edi;  // @199_47c160
  esi = eax;  // @200_47c160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @201_47c160
  ecx = edx = 0;  // @202_47c160
  edx = (u32)(6801640);  // @203_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @204_47c160
  FL[2] = (ecx & ecx);  // @205_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @206_47c160
  if (FL[2] != 0) edx = ecx;  // @207_47c160
  PV[21] = (u32)(edx);  // @208_47c160
  PV[22] = (u32)(esi);  // @209_47c160
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(eax + 44)))(PV[22], (u32)(6859732), PV[21]);  // @210_47c160
  ecx = edx = 0;  // @211_47c160
  L47c3f0:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1795), &v, sizeof v); }  // @213_47c160
  L47c3f7:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @215_47c160
  if (FL[0] == FL[1]) goto L47c4c2;  // @216_47c160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1795), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @217_47c160
  if (FL[0] != FL[1]) goto L47c4c2;  // @218_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @219_47c160
  PV[23] = (u32)(ebx);  // @220_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @221_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @222_47c160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[23]);  // @223_47c160
  ecx = edx = 0;  // @224_47c160
  FL[2] = (eax & eax);  // @225_47c160
  if (FL[2] == 0) goto L47c4c2;  // @226_47c160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @227_47c160
  ecx = eax;  // @228_47c160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @229_47c160
  ecx = edx = 0;  // @230_47c160
  esi = eax;  // @231_47c160
  FL[2] = (esi & esi);  // @232_47c160
  if (FL[2] == 0) goto L47c45f;  // @233_47c160
  L47c434:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @235_47c160
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }); FL[1] = (u32)(1048609);  // @236_47c160
  if (FL[0] == FL[1]) goto L47c44f;  // @237_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @238_47c160
  ecx = esi;  // @239_47c160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @240_47c160
  ecx = edx = 0;  // @241_47c160
  esi = eax;  // @242_47c160
  FL[2] = (esi & esi);  // @243_47c160
  if (FL[2] != 0) goto L47c434;  // @244_47c160
  goto L47c45f;  // @245_47c160
  L47c44f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @247_47c160
  ecx = edi;  // @248_47c160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @249_47c160
  ecx = edx = 0;  // @250_47c160
  PV[24] = (u32)(esi);  // @251_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @252_47c160
  eax = ext_4dc9c0_thiscall2(ecx, PV[24]);  // @253_47c160
  ecx = edx = 0;  // @254_47c160
  L47c45f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @256_47c160
  edx = (u32)(EBP - 48);  // @257_47c160
  PV[25] = (u32)(edx);  // @258_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @259_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @260_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @261_47c160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, PV[25]);  // @262_47c160
  ecx = edx = 0;  // @263_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @264_47c160
  PV[26] = (u32)(eax);  // @265_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @266_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @267_47c160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @268_47c160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, PV[26]);  // @269_47c160
  ecx = edx = 0;  // @270_47c160
  FL[2] = (eax & eax);  // @271_47c160
  if (FL[2] == 0) goto L47c4c2;  // @272_47c160
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; })) & 0xff);  // @273_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @274_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @275_47c160
  eax = (edx & 0xff);  // @276_47c160
  PV[27] = (u32)(eax);  // @277_47c160
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @278_47c160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 352)))(ecx, PV[27]);  // @279_47c160
  ecx = edx = 0;  // @280_47c160
  FL[2] = (eax & eax);  // @281_47c160
  if (FL[2] == 0) goto L47c4c2;  // @282_47c160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; });  // @283_47c160
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 331), &v, sizeof v); }  // @284_47c160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @285_47c160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 349), &v, sizeof v); }  // @286_47c160
  L47c4c2:;
  L47c4c3:;
  ext_633654(G(u32, 0x6f5630));  // @289_47c160
  return eax;  // @290_47c160
}
PCREG(47c160, lifted_47c160);

extern "C" u32 FASTCALL lifted_4e0390(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx) + 0), 4); v; });  // @0_4e0390
  X2[1] = 0;  // @1_4e0390
  X2[2] = 0;  // @2_4e0390
  X2[3] = 0;  // @3_4e0390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 4) + 0), 4); v; });  // @4_4e0390
  X1[1] = 0;  // @5_4e0390
  X1[2] = 0;  // @6_4e0390
  X1[3] = 0;  // @7_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 8) + 0), 4); v; });  // @8_4e0390
  X0[1] = 0;  // @9_4e0390
  X0[2] = 0;  // @10_4e0390
  X0[3] = 0;  // @11_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 112) + 44) + 0), &X1[0], 4);  // @12_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 112) + 40) + 0), &X2[0], 4);  // @13_4e0390
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @14_4e0390
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @15_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 120) + 56) + 0), &X0[0], 4);  // @16_4e0390
  edi = ecx;  // @17_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @18_4e0390
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @19_4e0390
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @20_4e0390
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @21_4e0390
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @22_4e0390
  ecx = edx = 0;  // @23_4e0390
  X1[0] = 0;  // @24_4e0390
  X1[1] = 0;  // @25_4e0390
  X1[2] = 0;  // @26_4e0390
  X1[3] = 0;  // @27_4e0390
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @28_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6910148) + 0), 4); v; });  // @29_4e0390
  X0[1] = 0;  // @30_4e0390
  X0[2] = 0;  // @31_4e0390
  X0[3] = 0;  // @32_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @33_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @34_4e0390
  X0[1] = 0;  // @35_4e0390
  X0[2] = 0;  // @36_4e0390
  X0[3] = 0;  // @37_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 120) + 16) + 0), &X1[0], 4);  // @38_4e0390
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4e0419;  // @39_4e0390
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 120) + 48), &v, sizeof v); }  // @40_4e0390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 120) + 52), &v, sizeof v); }  // @41_4e0390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 120) + 56), &v, sizeof v); }  // @42_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 120) + 16) + 0), &X0[0], 4);  // @43_4e0390
  L4e0419:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @45_4e0390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @46_4e0390
  X1[1] = 0;  // @47_4e0390
  X1[2] = 0;  // @48_4e0390
  X1[3] = 0;  // @49_4e0390
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @50_4e0390
  X2[1] = 0;  // @51_4e0390
  X2[2] = 0;  // @52_4e0390
  X2[3] = 0;  // @53_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @54_4e0390
  X0[1] = 0;  // @55_4e0390
  X0[2] = 0;  // @56_4e0390
  X0[3] = 0;  // @57_4e0390
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @58_4e0390
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @59_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @60_4e0390
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @61_4e0390
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @62_4e0390
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @63_4e0390
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @64_4e0390
  ecx = edx = 0;  // @65_4e0390
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @66_4e0390
  edx = esi;  // @67_4e0390
  ecx = (u32)((EBP - 120) + 108);  // @68_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 120) + 32) + 0), &X0[0], 4);  // @69_4e0390
  eax = ext_44e630_fastcall2(ecx, edx);  // @70_4e0390
  ecx = edx = 0;  // @71_4e0390
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @72_4e0390
  edx = (u32)((EBP - 120) + 48);  // @73_4e0390
  ecx = (u32)((EBP - 120) + 72);  // @74_4e0390
  eax = ext_44e630_fastcall2(ecx, edx);  // @75_4e0390
  ecx = edx = 0;  // @76_4e0390
  eax = (u32)((EBP - 120) + 108);  // @77_4e0390
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @78_4e0390
  PV[0] = (u32)(eax);  // @79_4e0390
  edx = (u32)((EBP - 124) + 76);  // @80_4e0390
  ecx = (u32)((EBP - 124) + 100);  // @81_4e0390
  eax = ext_446ee0_fastcall3(ecx, edx, PV[0]);  // @82_4e0390
  ecx = edx = 0;  // @83_4e0390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 96) + 0), 4); v; });  // @84_4e0390
  X1[1] = 0;  // @85_4e0390
  X1[2] = 0;  // @86_4e0390
  X1[3] = 0;  // @87_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 100) + 0), 4); v; });  // @88_4e0390
  X0[1] = 0;  // @89_4e0390
  X0[2] = 0;  // @90_4e0390
  X0[3] = 0;  // @91_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @92_4e0390
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @93_4e0390
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @94_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 104) + 0), 4); v; });  // @95_4e0390
  X0[1] = 0;  // @96_4e0390
  X0[2] = 0;  // @97_4e0390
  X0[3] = 0;  // @98_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @99_4e0390
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @100_4e0390
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @101_4e0390
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @102_4e0390
  ecx = edx = 0;  // @103_4e0390
  X1[0] = 0;  // @104_4e0390
  X1[1] = 0;  // @105_4e0390
  X1[2] = 0;  // @106_4e0390
  X1[3] = 0;  // @107_4e0390
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @108_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; });  // @109_4e0390
  X0[1] = 0;  // @110_4e0390
  X0[2] = 0;  // @111_4e0390
  X0[3] = 0;  // @112_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @113_4e0390
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4e0530;  // @114_4e0390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 108) + 0), 4); v; });  // @115_4e0390
  X1[1] = 0;  // @116_4e0390
  X1[2] = 0;  // @117_4e0390
  X1[3] = 0;  // @118_4e0390
  X2[0] = 0;  // @119_4e0390
  X2[1] = 0;  // @120_4e0390
  X2[2] = 0;  // @121_4e0390
  X2[3] = 0;  // @122_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 116) + 0), 4); v; });  // @123_4e0390
  X0[1] = 0;  // @124_4e0390
  X0[2] = 0;  // @125_4e0390
  X0[3] = 0;  // @126_4e0390
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @127_4e0390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 120) + 60), &v, sizeof v); }  // @128_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @129_4e0390
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 120) + 64), &v, sizeof v); }  // @130_4e0390
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 112) + 0), 4); v; })));  // @131_4e0390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 120) + 68), &v, sizeof v); }  // @132_4e0390
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @133_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; });  // @134_4e0390
  X0[1] = 0;  // @135_4e0390
  X0[2] = 0;  // @136_4e0390
  X0[3] = 0;  // @137_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @138_4e0390
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4e051e;  // @139_4e0390
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 120) + 60), &v, sizeof v); }  // @140_4e0390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 120) + 64), &v, sizeof v); }  // @141_4e0390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 120) + 68), &v, sizeof v); }  // @142_4e0390
  L4e051e:;
  eax = (u32)((EBP - 120) + 108);  // @144_4e0390
  PV[1] = (u32)(eax);  // @145_4e0390
  edx = (u32)((EBP - 124) + 64);  // @146_4e0390
  ecx = (u32)((EBP - 124) + 100);  // @147_4e0390
  eax = ext_446ee0_fastcall3(ecx, edx, PV[1]);  // @148_4e0390
  ecx = edx = 0;  // @149_4e0390
  L4e0530:;
  eax = (u32)((EBP - 120) + 108);  // @151_4e0390
  PV[2] = (u32)(eax);  // @152_4e0390
  edx = (u32)((EBP - 124) + 100);  // @153_4e0390
  ecx = (u32)((EBP - 124) + 88);  // @154_4e0390
  eax = ext_446ee0_fastcall3(ecx, edx, PV[2]);  // @155_4e0390
  ecx = edx = 0;  // @156_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 96) + 0), 4); v; });  // @157_4e0390
  X0[1] = 0;  // @158_4e0390
  X0[2] = 0;  // @159_4e0390
  X0[3] = 0;  // @160_4e0390
  eax = (u32)((EBP - 120) + 96);  // @161_4e0390
  X1[0] = 0;  // @162_4e0390
  X1[1] = 0;  // @163_4e0390
  X1[2] = 0;  // @164_4e0390
  X1[3] = 0;  // @165_4e0390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 120) + 20), &v, sizeof v); }  // @166_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @167_4e0390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @168_4e0390
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @169_4e0390
  if (!__builtin_parity(FL[2] & 0xff)) goto L4e057a;  // @170_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 100) + 0), 4); v; });  // @171_4e0390
  X0[1] = 0;  // @172_4e0390
  X0[2] = 0;  // @173_4e0390
  X0[3] = 0;  // @174_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @175_4e0390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @176_4e0390
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @177_4e0390
  if (!__builtin_parity(FL[2] & 0xff)) goto L4e057a;  // @178_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 104) + 0), 4); v; });  // @179_4e0390
  X0[1] = 0;  // @180_4e0390
  X0[2] = 0;  // @181_4e0390
  X0[3] = 0;  // @182_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @183_4e0390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @184_4e0390
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @185_4e0390
  if (__builtin_parity(FL[2] & 0xff)) goto L4e05ba;  // @186_4e0390
  L4e057a:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 120) + 12), &v, sizeof v); }  // @188_4e0390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 120) + 20), sizeof v); (u32)v; });  // @189_4e0390
  FS[0] = LDF((u32)(ecx));  // @190_4e0390
  FS[0] = (FS[0] * FS[0]);  // @191_4e0390
  FS[1] = LDF((u32)(ecx + 4));  // @192_4e0390
  FS[1] = (FS[1] * FS[1]);  // @193_4e0390
  FS[0] = (FS[0] + FS[1]);  // @194_4e0390
  FS[1] = LDF((u32)(ecx + 8));  // @195_4e0390
  FS[1] = (FS[1] * FS[1]);  // @196_4e0390
  FS[0] = (FS[0] + FS[1]);  // @197_4e0390
  FSQRT(FS[0]);  // @198_4e0390
  FS[1] = LDF((u32)((EBP - 120) + 12));  // @199_4e0390
  FS[1] = (FS[1] / FS[0]);  // @200_4e0390
  FS[2] = LDF((u32)(ecx));  // @201_4e0390
  FS[2] = (FS[2] * FS[1]);  // @202_4e0390
  STF((u32)(ecx), FS[2]);  // @203_4e0390
  FS[2] = LDF((u32)(ecx + 4));  // @204_4e0390
  FS[2] = (FS[2] * FS[1]);  // @205_4e0390
  STF((u32)(ecx + 4), FS[2]);  // @206_4e0390
  FS[2] = LDF((u32)(ecx + 8));  // @207_4e0390
  FS[1] = (FS[1] * FS[2]);  // @208_4e0390
  STF((u32)(ecx + 8), FS[1]);  // @209_4e0390
  STF((u32)((EBP - 120) + 12), FS[0]);  // @210_4e0390
  L4e05ba:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 84) + 0), 4); v; });  // @212_4e0390
  X0[1] = 0;  // @213_4e0390
  X0[2] = 0;  // @214_4e0390
  X0[3] = 0;  // @215_4e0390
  eax = (u32)((EBP - 120) + 84);  // @216_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @217_4e0390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 120) + 20), &v, sizeof v); }  // @218_4e0390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @219_4e0390
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @220_4e0390
  if (!__builtin_parity(FL[2] & 0xff)) goto L4e05ef;  // @221_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 88) + 0), 4); v; });  // @222_4e0390
  X0[1] = 0;  // @223_4e0390
  X0[2] = 0;  // @224_4e0390
  X0[3] = 0;  // @225_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @226_4e0390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @227_4e0390
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @228_4e0390
  if (!__builtin_parity(FL[2] & 0xff)) goto L4e05ef;  // @229_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 92) + 0), 4); v; });  // @230_4e0390
  X0[1] = 0;  // @231_4e0390
  X0[2] = 0;  // @232_4e0390
  X0[3] = 0;  // @233_4e0390
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @234_4e0390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @235_4e0390
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @236_4e0390
  if (__builtin_parity(FL[2] & 0xff)) goto L4e062f;  // @237_4e0390
  L4e05ef:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 120) + 12), &v, sizeof v); }  // @239_4e0390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 120) + 20), sizeof v); (u32)v; });  // @240_4e0390
  FS[0] = LDF((u32)(ecx));  // @241_4e0390
  FS[0] = (FS[0] * FS[0]);  // @242_4e0390
  FS[1] = LDF((u32)(ecx + 4));  // @243_4e0390
  FS[1] = (FS[1] * FS[1]);  // @244_4e0390
  FS[0] = (FS[0] + FS[1]);  // @245_4e0390
  FS[1] = LDF((u32)(ecx + 8));  // @246_4e0390
  FS[1] = (FS[1] * FS[1]);  // @247_4e0390
  FS[0] = (FS[0] + FS[1]);  // @248_4e0390
  FSQRT(FS[0]);  // @249_4e0390
  FS[1] = LDF((u32)((EBP - 120) + 12));  // @250_4e0390
  FS[1] = (FS[1] / FS[0]);  // @251_4e0390
  FS[2] = LDF((u32)(ecx));  // @252_4e0390
  FS[2] = (FS[2] * FS[1]);  // @253_4e0390
  STF((u32)(ecx), FS[2]);  // @254_4e0390
  FS[2] = LDF((u32)(ecx + 4));  // @255_4e0390
  FS[2] = (FS[2] * FS[1]);  // @256_4e0390
  STF((u32)(ecx + 4), FS[2]);  // @257_4e0390
  FS[2] = LDF((u32)(ecx + 8));  // @258_4e0390
  FS[1] = (FS[1] * FS[2]);  // @259_4e0390
  STF((u32)(ecx + 8), FS[1]);  // @260_4e0390
  STF((u32)((EBP - 120) + 12), FS[0]);  // @261_4e0390
  L4e062f:;
  eax = (u32)((EBP - 120) + 84);  // @263_4e0390
  PV[3] = (u32)(eax);  // @264_4e0390
  edx = (u32)((EBP - 124) + 76);  // @265_4e0390
  ecx = (u32)((EBP - 124) + 40);  // @266_4e0390
  eax = ext_459fc0_fastcall3(ecx, edx, PV[3]);  // @267_4e0390
  ecx = edx = 0;  // @268_4e0390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 36) + 0), 4); v; });  // @269_4e0390
  X1[1] = 0;  // @270_4e0390
  X1[2] = 0;  // @271_4e0390
  X1[3] = 0;  // @272_4e0390
  X2[0] = 0;  // @273_4e0390
  X2[1] = 0;  // @274_4e0390
  X2[2] = 0;  // @275_4e0390
  X2[3] = 0;  // @276_4e0390
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; });  // @277_4e0390
  X4[1] = 0;  // @278_4e0390
  X4[2] = 0;  // @279_4e0390
  X4[3] = 0;  // @280_4e0390
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @281_4e0390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @282_4e0390
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @283_4e0390
  if (!__builtin_parity(FL[2] & 0xff)) goto L4e0682;  // @284_4e0390
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 44) + 0), 4); v; });  // @285_4e0390
  X3[1] = 0;  // @286_4e0390
  X3[2] = 0;  // @287_4e0390
  X3[3] = 0;  // @288_4e0390
  FA = U2F(X3[0]); FB = U2F(X2[0]);  // @289_4e0390
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @290_4e0390
  X2[1] = 0;  // @291_4e0390
  X2[2] = 0;  // @292_4e0390
  X2[3] = 0;  // @293_4e0390
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4e0678;  // @294_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829936) + 0), 4); v; });  // @295_4e0390
  X0[1] = 0;  // @296_4e0390
  X0[2] = 0;  // @297_4e0390
  X0[3] = 0;  // @298_4e0390
  goto L4e06c3;  // @299_4e0390
  L4e0678:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6910168) + 0), 4); v; });  // @301_4e0390
  X0[1] = 0;  // @302_4e0390
  X0[2] = 0;  // @303_4e0390
  X0[3] = 0;  // @304_4e0390
  goto L4e06c3;  // @305_4e0390
  L4e0682:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 44) + 0), 4); v; });  // @307_4e0390
  X0[1] = 0;  // @308_4e0390
  X0[2] = 0;  // @309_4e0390
  X0[3] = 0;  // @310_4e0390
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @311_4e0390
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @312_4e0390
  { double r_ = ext_634de2_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @313_4e0390
  ecx = edx = 0;  // @314_4e0390
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @315_4e0390
  X2[1] = 0;  // @316_4e0390
  X2[2] = 0;  // @317_4e0390
  X2[3] = 0;  // @318_4e0390
  X1[0] = 0;  // @319_4e0390
  X1[1] = 0;  // @320_4e0390
  X1[2] = 0;  // @321_4e0390
  X1[3] = 0;  // @322_4e0390
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 36) + 0), 4); v; }));  // @323_4e0390
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @324_4e0390
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4e080c;  // @325_4e0390
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @326_4e0390
  L4e06b2:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; });  // @328_4e0390
  X4[1] = 0;  // @329_4e0390
  X4[2] = 0;  // @330_4e0390
  X4[3] = 0;  // @331_4e0390
  L4e06ba:;
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @333_4e0390
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4e06c3;  // @334_4e0390
  X0[0] = F2U(U2F(X0[0]) + U2F(X4[0]));  // @335_4e0390
  L4e06c3:;
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @337_4e0390
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4e06cc;  // @338_4e0390
  X0[0] = F2U(U2F(X0[0]) - U2F(X4[0]));  // @339_4e0390
  L4e06cc:;
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; })));  // @341_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 120) + 12) + 0), &X0[0], 4);  // @342_4e0390
  X0[0] = 0;  // @343_4e0390
  X0[1] = 0;  // @344_4e0390
  X0[2] = 0;  // @345_4e0390
  X0[3] = 0;  // @346_4e0390
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @347_4e0390
  ecx = edx = 0;  // @348_4e0390
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @349_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 120) + 24) + 0), &X0[0], 4);  // @350_4e0390
  X0[0] = 0;  // @351_4e0390
  X0[1] = 0;  // @352_4e0390
  X0[2] = 0;  // @353_4e0390
  X0[3] = 0;  // @354_4e0390
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @355_4e0390
  ecx = edx = 0;  // @356_4e0390
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @357_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 120) + 20) + 0), &X0[0], 4);  // @358_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 12) + 0), 4); v; });  // @359_4e0390
  X0[1] = 0;  // @360_4e0390
  X0[2] = 0;  // @361_4e0390
  X0[3] = 0;  // @362_4e0390
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @363_4e0390
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @364_4e0390
  ecx = edx = 0;  // @365_4e0390
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @366_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 120) + 28) + 0), &X0[0], 4);  // @367_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 12) + 0), 4); v; });  // @368_4e0390
  X0[1] = 0;  // @369_4e0390
  X0[2] = 0;  // @370_4e0390
  X0[3] = 0;  // @371_4e0390
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @372_4e0390
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @373_4e0390
  ecx = edx = 0;  // @374_4e0390
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 20) + 0), 4); v; });  // @375_4e0390
  X6[1] = 0;  // @376_4e0390
  X6[2] = 0;  // @377_4e0390
  X6[3] = 0;  // @378_4e0390
  eax = (u32)((EBP - 120) + 84);  // @379_4e0390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 36) + 0), 4); v; });  // @380_4e0390
  X1[1] = 0;  // @381_4e0390
  X1[2] = 0;  // @382_4e0390
  X1[3] = 0;  // @383_4e0390
  edx = (u32)((EBP - 120) + 36);  // @384_4e0390
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 40) + 0), 4); v; });  // @385_4e0390
  X2[1] = 0;  // @386_4e0390
  X2[2] = 0;  // @387_4e0390
  X2[3] = 0;  // @388_4e0390
  X4[0] = 0;  // @389_4e0390
  X4[1] = 0;  // @390_4e0390
  X4[2] = 0;  // @391_4e0390
  X4[3] = 0;  // @392_4e0390
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 24) + 0), 4); v; });  // @393_4e0390
  X5[1] = 0;  // @394_4e0390
  X5[2] = 0;  // @395_4e0390
  X5[3] = 0;  // @396_4e0390
  X3[0] = X6[0];  // @397_4e0390
  X3[1] = X6[1];  // @398_4e0390
  X3[2] = X6[2];  // @399_4e0390
  X3[3] = X6[3];  // @400_4e0390
  X4[0] = F2U((float)U2D(X0[0], X0[1]));  // @401_4e0390
  PV[4] = (u32)(eax);  // @402_4e0390
  ecx = edi;  // @403_4e0390
  X3[0] = F2U(U2F(X3[0]) * U2F(X1[0]));  // @404_4e0390
  X0[0] = X2[0];  // @405_4e0390
  X0[1] = X2[1];  // @406_4e0390
  X0[2] = X2[2];  // @407_4e0390
  X0[3] = X2[3];  // @408_4e0390
  X1[0] = F2U(U2F(X1[0]) * U2F(X5[0]));  // @409_4e0390
  X2[0] = F2U(U2F(X2[0]) * U2F(X6[0]));  // @410_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @411_4e0390
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @412_4e0390
  X3[0] = F2U(U2F(X3[0]) - U2F(X0[0]));  // @413_4e0390
  X0[0] = X5[0];  // @414_4e0390
  X0[1] = X5[1];  // @415_4e0390
  X0[2] = X5[2];  // @416_4e0390
  X0[3] = X5[3];  // @417_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 124) + 48) + 0), 4); v; })));  // @418_4e0390
  X1[0] = X2[0];  // @419_4e0390
  X1[1] = X2[1];  // @420_4e0390
  X1[2] = X2[2];  // @421_4e0390
  X1[3] = X2[3];  // @422_4e0390
  X2[0] = F2U(U2F(X2[0]) * U2F(X5[0]));  // @423_4e0390
  X1[0] = F2U(U2F(X1[0]) * U2F(X6[0]));  // @424_4e0390
  X6[0] = F2U(U2F(X6[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 124) + 48) + 0), 4); v; })));  // @425_4e0390
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @426_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 124) + 32) + 0), 4); v; });  // @427_4e0390
  X0[1] = 0;  // @428_4e0390
  X0[2] = 0;  // @429_4e0390
  X0[3] = 0;  // @430_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @431_4e0390
  X6[0] = F2U(U2F(X6[0]) + U2F(X2[0]));  // @432_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 124) + 44) + 0), &X1[0], 4);  // @433_4e0390
  X1[0] = X4[0];  // @434_4e0390
  X1[1] = X4[1];  // @435_4e0390
  X1[2] = X4[2];  // @436_4e0390
  X1[3] = X4[3];  // @437_4e0390
  X4[0] = F2U(U2F(X4[0]) * U2F(X3[0]));  // @438_4e0390
  X1[0] = F2U(U2F(X1[0]) * U2F(X6[0]));  // @439_4e0390
  X6[0] = F2U(U2F(X6[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 124) + 32) + 0), 4); v; })));  // @440_4e0390
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @441_4e0390
  X4[0] = F2U(U2F(X4[0]) + U2F(X6[0]));  // @442_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 124) + 48) + 0), &X1[0], 4);  // @443_4e0390
  __builtin_memcpy((void *)((u32)((EBP - 124) + 40) + 0), &X4[0], 4);  // @444_4e0390
  eax = ext_441970_fastcall3(ecx, edx, PV[4]);  // @445_4e0390
  ecx = edx = 0;  // @446_4e0390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 32) + 0), 4); v; });  // @447_4e0390
  X1[1] = 0;  // @448_4e0390
  X1[2] = 0;  // @449_4e0390
  X1[3] = 0;  // @450_4e0390
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 16) + 0), 4); v; })));  // @451_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @452_4e0390
  X0[1] = 0;  // @453_4e0390
  X0[2] = 0;  // @454_4e0390
  X0[3] = 0;  // @455_4e0390
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; })));  // @456_4e0390
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 16) + 0), 4); v; })));  // @457_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @458_4e0390
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @459_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @460_4e0390
  X0[1] = 0;  // @461_4e0390
  X0[2] = 0;  // @462_4e0390
  X0[3] = 0;  // @463_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @464_4e0390
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X0[0], 4);  // @465_4e0390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @466_4e0390
  X0[1] = 0;  // @467_4e0390
  X0[2] = 0;  // @468_4e0390
  X0[3] = 0;  // @469_4e0390
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @470_4e0390
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @471_4e0390
  return eax;  // @472_4e0390
  L4e080c:;
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 120) + 44) + 0), 4); v; }));  // @474_4e0390
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4e06b2;  // @475_4e0390
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; });  // @476_4e0390
  X4[1] = 0;  // @477_4e0390
  X4[2] = 0;  // @478_4e0390
  X4[3] = 0;  // @479_4e0390
  X0[0] = F2U(U2F(X0[0]) + U2F(X4[0]));  // @480_4e0390
  goto L4e06ba;  // @481_4e0390
}
PCREG(4e0390, lifted_4e0390);

extern "C" u32 THISCALL lifted_5b2e90(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 PA0 = 0, PA1 = 0, PA2 = 0;   // w3g hand fix: `push 0` / `push 1` chosen per path before one shared call
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @1_5b2e90
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 439), &v, sizeof v); }  // @2_5b2e90
  FL[2] = (ecx & ecx);  // @3_5b2e90
  if (FL[2] == 0) goto L5b30c3;  // @4_5b2e90
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 360), sizeof v); (u32)v; });  // @5_5b2e90
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 444), sizeof v); (u32)v; }) & (eax & 0xff));  // @6_5b2e90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_5b2e90
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @8_5b2e90
  eax = (eax & 0xff);  // @9_5b2e90
  PV[0] = (u32)(eax);  // @10_5b2e90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[0]);  // @11_5b2e90
  ecx = edx = 0;  // @12_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 445), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @13_5b2e90
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 360), sizeof v); (u32)v; });  // @14_5b2e90
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 444), &v, sizeof v); }  // @15_5b2e90
  if (FL[0] == FL[1]) goto L5b2eea;  // @16_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @17_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5b2e90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(1));  // @19_5b2e90
  ecx = edx = 0;  // @20_5b2e90
  L5b2eea:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 444), sizeof v); (u32)v; })) & 0xff);  // @22_5b2e90
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @23_5b2e90
  if (FL[2] == 0) goto L5b2f49;  // @24_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_5b2e90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @26_5b2e90
  X0[0] = F2U((float)(s32)X0[0]);  // @27_5b2e90
  X0[1] = F2U((float)(s32)X0[1]);  // @28_5b2e90
  X0[2] = F2U((float)(s32)X0[2]);  // @29_5b2e90
  X0[3] = F2U((float)(s32)X0[3]);  // @30_5b2e90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @31_5b2e90
  __builtin_memcpy((void *)((u32)(esi + 440) + 0), &X0[0], 4);  // @32_5b2e90
  L5b2f11:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 371), sizeof v); (u32)v; })) & 0xff);  // @34_5b2e90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795056) + 0), 4); v; });  // @35_5b2e90
  X2[1] = 0;  // @36_5b2e90
  X2[2] = 0;  // @37_5b2e90
  X2[3] = 0;  // @38_5b2e90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795040) + 0), 4); v; });  // @39_5b2e90
  X1[1] = 0;  // @40_5b2e90
  X1[2] = 0;  // @41_5b2e90
  X1[3] = 0;  // @42_5b2e90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @43_5b2e90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @44_5b2e90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @45_5b2e90
  if (FL[2] == 0) goto L5b2f88;  // @46_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @47_5b2e90
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @48_5b2e90
  X0[0] = F2U((float)(s32)X0[0]);  // @49_5b2e90
  X0[1] = F2U((float)(s32)X0[1]);  // @50_5b2e90
  X0[2] = F2U((float)(s32)X0[2]);  // @51_5b2e90
  X0[3] = F2U((float)(s32)X0[3]);  // @52_5b2e90
  X0[0] = F2U(U2F(X0[0]) / U2F(X2[0]));  // @53_5b2e90
  goto L5b2fa0;  // @54_5b2e90
  L5b2f49:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 445), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @56_5b2e90
  if (FL[0] != FL[1]) goto L5b2f11;  // @57_5b2e90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 440) + 0), 4); v; });  // @58_5b2e90
  X0[1] = 0;  // @59_5b2e90
  X0[2] = 0;  // @60_5b2e90
  X0[3] = 0;  // @61_5b2e90
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; })));  // @62_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_5b2e90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @64_5b2e90
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @65_5b2e90
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @66_5b2e90
  if ((s32)FL[0] <= (s32)FL[1]) goto L5b30b0;  // @67_5b2e90
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 439), &v, sizeof v); }  // @68_5b2e90
  goto L5b30b0;  // @69_5b2e90
  L5b2f88:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 372), sizeof v); (u32)v; })) & 0xff);  // @71_5b2e90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @72_5b2e90
  if (FL[2] == 0) goto L5b2fa5;  // @73_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @74_5b2e90
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @75_5b2e90
  X0[0] = F2U((float)(s32)X0[0]);  // @76_5b2e90
  X0[1] = F2U((float)(s32)X0[1]);  // @77_5b2e90
  X0[2] = F2U((float)(s32)X0[2]);  // @78_5b2e90
  X0[3] = F2U((float)(s32)X0[3]);  // @79_5b2e90
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @80_5b2e90
  L5b2fa0:;
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @82_5b2e90
  L5b2fa5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 369), sizeof v); (u32)v; })) & 0xff);  // @84_5b2e90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @85_5b2e90
  if (FL[2] == 0) goto L5b2fbf;  // @86_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @87_5b2e90
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @88_5b2e90
  X0[0] = F2U((float)(s32)X0[0]);  // @89_5b2e90
  X0[1] = F2U((float)(s32)X0[1]);  // @90_5b2e90
  X0[2] = F2U((float)(s32)X0[2]);  // @91_5b2e90
  X0[3] = F2U((float)(s32)X0[3]);  // @92_5b2e90
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @93_5b2e90
  goto L5b2fd7;  // @94_5b2e90
  L5b2fbf:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 370), sizeof v); (u32)v; })) & 0xff);  // @96_5b2e90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @97_5b2e90
  if (FL[2] == 0) goto L5b2fdc;  // @98_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @99_5b2e90
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @100_5b2e90
  X0[0] = F2U((float)(s32)X0[0]);  // @101_5b2e90
  X0[1] = F2U((float)(s32)X0[1]);  // @102_5b2e90
  X0[2] = F2U((float)(s32)X0[2]);  // @103_5b2e90
  X0[3] = F2U((float)(s32)X0[3]);  // @104_5b2e90
  X0[0] = F2U(U2F(X0[0]) / U2F(X2[0]));  // @105_5b2e90
  L5b2fd7:;
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @107_5b2e90
  L5b2fdc:;
  ecx = (u32)(EBP - 12);  // @109_5b2e90
  FS[0] = ext_4dfda0_thiscall1_ld(ecx);  // @110_5b2e90
  ecx = edx = 0;  // @111_5b2e90
  STF((u32)(EBP - 4), FS[0]);  // @112_5b2e90
  ecx = (u32)(EBP - 12);  // @113_5b2e90
  eax = ext_4dff10_thiscall1(ecx);  // @114_5b2e90
  ecx = edx = 0;  // @115_5b2e90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @116_5b2e90
  X0[1] = 0;  // @117_5b2e90
  X0[2] = 0;  // @118_5b2e90
  X0[3] = 0;  // @119_5b2e90
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @120_5b2e90
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @121_5b2e90
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @122_5b2e90
  ecx = edx = 0;  // @123_5b2e90
  X3[0] = 0;  // @124_5b2e90
  X3[1] = 0;  // @125_5b2e90
  X3[2] = 0;  // @126_5b2e90
  X3[3] = 0;  // @127_5b2e90
  X1[0] = 0;  // @128_5b2e90
  X1[1] = 0;  // @129_5b2e90
  X1[2] = 0;  // @130_5b2e90
  X1[3] = 0;  // @131_5b2e90
  FA = U2F(X3[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; }));  // @132_5b2e90
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @133_5b2e90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b3015;  // @134_5b2e90
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @135_5b2e90
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @136_5b2e90
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @137_5b2e90
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @138_5b2e90
  L5b3015:;
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7020836) + 0), 4); v; })));  // @140_5b2e90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; });  // @141_5b2e90
  X2[1] = 0;  // @142_5b2e90
  X2[2] = 0;  // @143_5b2e90
  X2[3] = 0;  // @144_5b2e90
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; }));  // @145_5b2e90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b3034;  // @146_5b2e90
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @147_5b2e90
  goto L5b3045;  // @148_5b2e90
  L5b3034:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000632) + 0), 4); v; });  // @150_5b2e90
  X0[1] = 0;  // @151_5b2e90
  X0[2] = 0;  // @152_5b2e90
  X0[3] = 0;  // @153_5b2e90
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @154_5b2e90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b3045;  // @155_5b2e90
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @156_5b2e90
  L5b3045:;
  FA = U2F(X3[0]); FB = U2F(X1[0]);  // @158_5b2e90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b304e;  // @159_5b2e90
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @160_5b2e90
  L5b304e:;
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @162_5b2e90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; });  // @163_5b2e90
  X0[1] = 0;  // @164_5b2e90
  X0[2] = 0;  // @165_5b2e90
  X0[3] = 0;  // @166_5b2e90
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; }));  // @167_5b2e90
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818412) + 0), 4); v; })));  // @168_5b2e90
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @169_5b2e90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5b307b;  // @170_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @171_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7439), sizeof v); (u32)v; });  // @172_5b2e90
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 962), sizeof v); (u32)v; })) & 0xff);  // @173_5b2e90
  L5b307b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @175_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @176_5b2e90
  PV[1] = (u32)(eax);  // @177_5b2e90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_5b2e90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[1]);  // @179_5b2e90
  ecx = edx = 0;  // @180_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 445), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @181_5b2e90
  if (FL[0] == FL[1]) goto L5b30b0;  // @182_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @183_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7439), sizeof v); (u32)v; });  // @184_5b2e90
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 892), &v, sizeof v); }  // @185_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @186_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @187_5b2e90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(0));  // @188_5b2e90
  ecx = edx = 0;  // @189_5b2e90
  L5b30b0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 419), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @191_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @192_5b2e90
  ecx = (ecx & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @193_5b2e90
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 7573), &v, sizeof v); }  // @194_5b2e90
  L5b30c3:;
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 411), sizeof v); (u32)v; }));  // @196_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @197_5b2e90
  PV[2] = (u32)(eax);  // @198_5b2e90
  eax = ext_5d13f0_thiscall2(ecx, PV[2]);  // @199_5b2e90
  edx = 0;  // @200_5b2e90
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 412), sizeof v); (u32)v; }));  // @201_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @202_5b2e90
  PV[3] = (u32)(eax);  // @203_5b2e90
  eax = ext_5d1300_thiscall2(ecx, PV[3]);  // @204_5b2e90
  edx = 0;  // @205_5b2e90
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 413), sizeof v); (u32)v; }));  // @206_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @207_5b2e90
  PV[4] = (u32)(eax);  // @208_5b2e90
  eax = ext_5d1350_thiscall2(ecx, PV[4]);  // @209_5b2e90
  edx = 0;  // @210_5b2e90
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 414), sizeof v); (u32)v; }));  // @211_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @212_5b2e90
  PV[5] = (u32)(eax);  // @213_5b2e90
  eax = ext_5d13a0_thiscall2(ecx, PV[5]);  // @214_5b2e90
  edx = 0;  // @215_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @216_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 395), sizeof v); (u32)v; });  // @217_5b2e90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 3599), &v, sizeof v); }  // @218_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @219_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 399), sizeof v); (u32)v; });  // @220_5b2e90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 3603), &v, sizeof v); }  // @221_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 360), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @222_5b2e90
  if (FL[0] != FL[1]) goto L5b3186;  // @223_5b2e90
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 415), sizeof v); (u32)v; })) & 0xff);  // @224_5b2e90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @225_5b2e90
  if (FL[2] == 0) goto L5b3142;  // @226_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @227_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @228_5b2e90
  PV[6] = (u32)(eax);  // @229_5b2e90
  eax = ext_5d0c30_thiscall2(ecx, PV[6]);  // @230_5b2e90
    // @231_5b2e90
  goto L5b3158;  // @232_5b2e90
  L5b3142:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 416), sizeof v); (u32)v; })) & 0xff);  // @234_5b2e90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @235_5b2e90
  if (FL[2] == 0) goto L5b3158;  // @236_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @237_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @238_5b2e90
  PV[7] = (u32)(eax);  // @239_5b2e90
  eax = ext_5d0ba0_thiscall2(ecx, PV[7]);  // @240_5b2e90
    // @241_5b2e90
  L5b3158:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 417), sizeof v); (u32)v; })) & 0xff);  // @243_5b2e90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @244_5b2e90
  if (FL[2] == 0) goto L5b3170;  // @245_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @246_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @247_5b2e90
  PV[8] = (u32)(eax);  // @248_5b2e90
  eax = ext_5d0c60_thiscall2(ecx, PV[8]);  // @249_5b2e90
    // @250_5b2e90
  goto L5b3186;  // @251_5b2e90
  L5b3170:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 418), sizeof v); (u32)v; })) & 0xff);  // @253_5b2e90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @254_5b2e90
  if (FL[2] == 0) goto L5b3186;  // @255_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @256_5b2e90
  eax = (u32)(s32)(s8)((eax & 0xff));  // @257_5b2e90
  PV[9] = (u32)(eax);  // @258_5b2e90
  eax = ext_5d1190_thiscall2(ecx, PV[9]);  // @259_5b2e90
    // @260_5b2e90
  L5b3186:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 365), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @262_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @263_5b2e90
  ecx = (ecx & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @264_5b2e90
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 1645), &v, sizeof v); }  // @265_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @266_5b2e90
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1047), sizeof v); (u32)v; }) & (u32)(268435456));  // @267_5b2e90
  if (FL[2] == 0) goto L5b31ba;  // @268_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 433), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @269_5b2e90
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @270_5b2e90
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 1646), &v, sizeof v); }  // @271_5b2e90
  goto L5b31e3;  // @272_5b2e90
  L5b31ba:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 433), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @274_5b2e90
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @275_5b2e90
  eax = (eax & 0xff);  // @276_5b2e90
  PV[10] = (u32)(eax);  // @277_5b2e90
  eax = ext_594f40_thiscall2(ecx, PV[10]);  // @278_5b2e90
    // @279_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 434), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @280_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @281_5b2e90
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @282_5b2e90
  eax = (eax & 0xff);  // @283_5b2e90
  PV[11] = (u32)(eax);  // @284_5b2e90
  eax = ext_594ed0_thiscall2(ecx, PV[11]);  // @285_5b2e90
    // @286_5b2e90
  L5b31e3:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 422), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @288_5b2e90
  if (FL[0] == FL[1]) goto L5b31f4;  // @289_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @290_5b2e90
  eax = ext_5ccae0_thiscall1(ecx);  // @291_5b2e90
  edx = 0;  // @292_5b2e90
  L5b31f4:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 423), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @294_5b2e90
  if (FL[0] == FL[1]) goto L5b3205;  // @295_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @296_5b2e90
  eax = ext_5ccb40_thiscall1(ecx);  // @297_5b2e90
  edx = 0;  // @298_5b2e90
  L5b3205:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 424), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @300_5b2e90
  if (FL[0] == FL[1]) goto L5b3216;  // @301_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @302_5b2e90
  eax = ext_5cca60_thiscall1(ecx);  // @303_5b2e90
    // @304_5b2e90
  L5b3216:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 425), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @306_5b2e90
  if (FL[0] == FL[1]) goto L5b3227;  // @307_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @308_5b2e90
  eax = ext_5ccaa0_thiscall1(ecx);  // @309_5b2e90
    // @310_5b2e90
  L5b3227:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 419), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @312_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @313_5b2e90
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @314_5b2e90
  eax = (eax & 0xff);  // @315_5b2e90
  PV[12] = (u32)(eax);  // @316_5b2e90
  eax = ext_5d24c0_thiscall2(ecx, PV[12]);  // @317_5b2e90
  ecx = edx = 0;  // @318_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 426), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @319_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 99), sizeof v); (u32)v; });  // @320_5b2e90
  ecx = (ecx & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @321_5b2e90
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 3016), &v, sizeof v); }  // @322_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 360), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @323_5b2e90
  if (FL[0] == FL[1]) goto L5b3269;  // @324_5b2e90
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 361), &v, sizeof v); }  // @325_5b2e90
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 363), &v, sizeof v); }  // @326_5b2e90
  L5b3269:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 361), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @328_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @329_5b2e90
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @330_5b2e90
  eax = (eax & 0xff);  // @331_5b2e90
  PV[13] = (u32)(eax);  // @332_5b2e90
  eax = ext_594f10_thiscall2(ecx, PV[13]);  // @333_5b2e90
    // @334_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 362), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @335_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @336_5b2e90
  ecx = (ecx & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @337_5b2e90
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 1642), &v, sizeof v); }  // @338_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 363), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @339_5b2e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @340_5b2e90
  if (FL[0] == FL[1]) goto L5b32a7;  // @341_5b2e90
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 1644), &v, sizeof v); }  // @342_5b2e90
  goto L5b32ae;  // @343_5b2e90
  L5b32a7:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1644), &v, sizeof v); }  // @345_5b2e90
  L5b32ae:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 429), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @347_5b2e90
  if (FL[0] == FL[1]) goto L5b32bb;  // @348_5b2e90
  PA0 = 0; goto L5b32c6;  // @349_5b2e90
  L5b32bb:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 432), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @351_5b2e90
  if (FL[0] == FL[1]) goto L5b32ce;  // @352_5b2e90
  PA0 = 1;
  L5b32c6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @354_5b2e90
  eax = ext_59a800_thiscall2(ecx, PA0);  // @355_5b2e90
  ecx = edx = 0;  // @356_5b2e90
  L5b32ce:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 427), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @358_5b2e90
  if (FL[0] == FL[1]) goto L5b32db;  // @359_5b2e90
  PA1 = 0; goto L5b32e6;  // @360_5b2e90
  L5b32db:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 430), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @362_5b2e90
  if (FL[0] == FL[1]) goto L5b32ee;  // @363_5b2e90
  PA1 = 1;
  L5b32e6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @365_5b2e90
  eax = ext_59a7a0_thiscall2(ecx, PA1);  // @366_5b2e90
  ecx = edx = 0;  // @367_5b2e90
  L5b32ee:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 428), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @369_5b2e90
  if (FL[0] == FL[1]) goto L5b32fb;  // @370_5b2e90
  PA2 = 0; goto L5b3306;  // @371_5b2e90
  L5b32fb:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 431), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @373_5b2e90
  if (FL[0] == FL[1]) goto L5b330e;  // @374_5b2e90
  PA2 = 1;
  L5b3306:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @376_5b2e90
  eax = ext_59a720_thiscall2(ecx, PA2);  // @377_5b2e90
  ecx = edx = 0;  // @378_5b2e90
  L5b330e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @380_5b2e90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2515), sizeof v); (u32)v; }); FL[1] = (u32)(6);  // @381_5b2e90
  if (FL[0] != FL[1]) goto L5b332d;  // @382_5b2e90
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1644), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @383_5b2e90
  if (FL[0] == FL[1]) goto L5b332d;  // @384_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @385_5b2e90
  eax = ext_59a7e0_stdcall1((u32)(0));  // @386_5b2e90
  ecx = edx = 0;  // @387_5b2e90
  L5b332d:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 433), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @389_5b2e90
  if (FL[0] == FL[1]) goto L5b333e;  // @390_5b2e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @391_5b2e90
  eax = ext_5ccc80_thiscall1(ecx);  // @392_5b2e90
  ecx = edx = 0;  // @393_5b2e90
  L5b333e:;
  return eax;  // @395_5b2e90
}
PCREG(5b2e90, lifted_5b2e90);

