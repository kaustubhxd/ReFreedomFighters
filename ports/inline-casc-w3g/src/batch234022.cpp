// batch234022.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" long double FASTCALL ext_4e0830_fastcall2_ld(u32, u32) __asm__("ext_4e0830");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e0d80_thiscall2(u32, u32) __asm__("ext_4e0d80");
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

extern "C" u32 THISCALL lifted_5ce0b0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0d0d0d0d, esi = 0x0d0d0d0d, edi = 0x0d0d0d0d;
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
PCREG(5ce0b0, lifted_5ce0b0);

