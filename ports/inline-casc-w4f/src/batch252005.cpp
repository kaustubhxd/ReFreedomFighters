// batch252005.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" s32 VECTORCALL ext_633910(float f);
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 THISCALL ext_44d520_thiscall2(u32, u32) __asm__("ext_44d520");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
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

extern "C" u32 THISCALL lifted_44dc90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_44dc90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1_44dc90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @2_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 300) + 20), &v, sizeof v); }  // @3_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_44dc90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 300) + 32), &v, sizeof v); }  // @5_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 300) + 60), &v, sizeof v); }  // @6_44dc90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 300) + 36), &v, sizeof v); }  // @7_44dc90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 300) + 48), &v, sizeof v); }  // @8_44dc90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @9_44dc90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 304) + 28), &v, sizeof v); }  // @10_44dc90
  FL[2] = (esi & esi);  // @11_44dc90
  if (FL[2] == 0) goto L44e570;  // @12_44dc90
  ecx = (u32)((EBP - 304) + 156);  // @13_44dc90
  { u32 v = (u32)((u32)(1097859072)); __builtin_memcpy((void *)(u32)((EBP - 304) + 84), &v, sizeof v); }  // @14_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 88), &v, sizeof v); }  // @15_44dc90
  { u32 v = (u32)((u32)(1082130432)); __builtin_memcpy((void *)(u32)((EBP - 304) + 92), &v, sizeof v); }  // @16_44dc90
  eax = ext_4de7a0_thiscall1(ecx);  // @17_44dc90
    // @18_44dc90
  edx = ebx;  // @19_44dc90
  ecx = (u32)((EBP - 304) + 84);  // @20_44dc90
  eax = ext_4419f0_fastcall2(ecx, edx);  // @21_44dc90
  ecx = edx = 0;  // @22_44dc90
  edx = edi;  // @23_44dc90
  ecx = (u32)((EBP - 304) + 84);  // @24_44dc90
  eax = ext_441940_fastcall2(ecx, edx);  // @25_44dc90
  ecx = edx = 0;  // @26_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @27_44dc90
  X0[1] = 0;  // @28_44dc90
  X0[2] = 0;  // @29_44dc90
  X0[3] = 0;  // @30_44dc90
  ecx = (u32)((EBP - 304) + 84);  // @31_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 304) + 156) + 0), &X0[0], 4);  // @33_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @34_44dc90
  X0[1] = 0;  // @35_44dc90
  X0[2] = 0;  // @36_44dc90
  X0[3] = 0;  // @37_44dc90
  PV[0] = (u32)(ecx);  // @38_44dc90
  ecx = (u32)((EBP - 308) + 160);  // @39_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 308) + 164) + 0), &X0[0], 4);  // @40_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @41_44dc90
  X0[1] = 0;  // @42_44dc90
  X0[2] = 0;  // @43_44dc90
  X0[3] = 0;  // @44_44dc90
  PV[1] = (u32)(ecx);  // @45_44dc90
  ecx = esi;  // @46_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 312) + 172) + 0), &X0[0], 4);  // @47_44dc90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[1], PV[0]);  // @48_44dc90
  ecx = edx = 0;  // @49_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 36), sizeof v); (u32)v; });  // @50_44dc90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 24), sizeof v); (u32)v; });  // @51_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @52_44dc90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @53_44dc90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @54_44dc90
  if (FL[0] == FL[1]) goto L44e027;  // @55_44dc90
  L44dd70:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @57_44dc90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @58_44dc90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @59_44dc90
  FL[0] = esi; FL[1] = (u32)(4);  // @60_44dc90
  if (FL[0] > FL[1]) goto L44e011;  // @61_44dc90
  ebx = (u32)(esi + 4);  // @62_44dc90
  X0[0] = 0;  // @63_44dc90
  X0[1] = 0;  // @64_44dc90
  X0[2] = 0;  // @65_44dc90
  X0[3] = 0;  // @66_44dc90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @67_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_44dc90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 312) + 40), &v, sizeof v); }  // @69_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 312) + 56) + 0), &X0[0], 4);  // @71_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @72_44dc90
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(137));  // @73_44dc90
  ecx = edx = 0;  // @74_44dc90
  STF((u32)((EBP - 304) + 16), FS[0]);  // @75_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 16) + 0), 4); v; });  // @76_44dc90
  X0[1] = 0;  // @77_44dc90
  X0[2] = 0;  // @78_44dc90
  X0[3] = 0;  // @79_44dc90
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791816) + 0), 4); v; }));  // @80_44dc90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L44ddcd;  // @81_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818452) + 0), 4); v; });  // @82_44dc90
  X0[1] = 0;  // @83_44dc90
  X0[2] = 0;  // @84_44dc90
  X0[3] = 0;  // @85_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 304) + 48) + 0), &X0[0], 4);  // @86_44dc90
  L44ddcd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @90_44dc90
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(138));  // @91_44dc90
  ecx = edx = 0;  // @92_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_44dc90
  eax = (eax + (u32)(64));  // @94_44dc90
  FL[3] = eax;  // @95_44dc90
  STF((u32)((EBP - 304) + 56), FS[0]);  // @96_44dc90
  FL[0] = edi; FL[1] = eax;  // @97_44dc90
  if (FL[0] == FL[1]) goto L44ddfb;  // @98_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @99_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @100_44dc90
  L44ddfb:;
  FL[0] = esi; FL[1] = ebx;  // @102_44dc90
  if (FL[0] >= FL[1]) goto L44e011;  // @103_44dc90
  ebx = (u32)(esi + esi*2);  // @104_44dc90
  eax = (u32)(esi + esi*2);  // @105_44dc90
  ebx = (ebx << (u32)(4));  // @106_44dc90
  FL[3] = ebx;  // @107_44dc90
  eax = (eax << (u32)(3));  // @108_44dc90
  FL[3] = eax;  // @109_44dc90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 32), sizeof v); (u32)v; }) - esi)); __builtin_memcpy((void *)(u32)((EBP - 304) + 32), &v, sizeof v); }  // @110_44dc90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 32), sizeof v); (u32)v; });  // @111_44dc90
  esi = eax;  // @112_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 304) + 16), &v, sizeof v); }  // @113_44dc90
  L44de20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @115_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 84) + 0), 4); v; });  // @116_44dc90
  X0[1] = 0;  // @117_44dc90
  X0[2] = 0;  // @118_44dc90
  X0[3] = 0;  // @119_44dc90
  __builtin_memcpy((void *)((u32)(ebx + eax + 36) + 0), &X0[0], 4);  // @120_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 312) + 96) + 0), 4); v; });  // @121_44dc90
  X0[1] = 0;  // @122_44dc90
  X0[2] = 0;  // @123_44dc90
  X0[3] = 0;  // @124_44dc90
  __builtin_memcpy((void *)((u32)(ebx + eax + 40) + 0), &X0[0], 4);  // @125_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 312) + 100) + 0), 4); v; });  // @126_44dc90
  X0[1] = 0;  // @127_44dc90
  X0[2] = 0;  // @128_44dc90
  X0[3] = 0;  // @129_44dc90
  __builtin_memcpy((void *)((u32)(ebx + eax + 44) + 0), &X0[0], 4);  // @130_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @131_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + eax), &v, sizeof v); }  // @132_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @133_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + eax + 16), &v, sizeof v); }  // @134_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @137_44dc90
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(144));  // @138_44dc90
  ecx = edx = 0;  // @139_44dc90
  FS[0] = (FS[0] + LDF((u32)(6791812)));  // @140_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @141_44dc90
  STF((u32)((EBP - 312) + 28), FS[0]);  // @142_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 312) + 28) + 0), 4); v; });  // @143_44dc90
  X0[1] = 0;  // @144_44dc90
  X0[2] = 0;  // @145_44dc90
  X0[3] = 0;  // @146_44dc90
  __builtin_memcpy((void *)((u32)(esi + eax + 12) + 0), &X0[0], 4);  // @147_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @148_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @149_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + esi + 4), &v, sizeof v); }  // @150_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + esi + 8), &v, sizeof v); }  // @151_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @152_44dc90
  { u32 v = (u32)((u32)(1115422720)); __builtin_memcpy((void *)(u32)(ebx + eax + 4), &v, sizeof v); }  // @153_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @154_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @156_44dc90
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(147));  // @157_44dc90
  ecx = edx = 0;  // @158_44dc90
  FS[1] = LDF((u32)(6791816));  // @159_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });  // @160_44dc90
  FS[0] = (FS[0] * FS[1]);  // @161_44dc90
  FS[0] = (FS[0] + FS[1]);  // @162_44dc90
  STF((u32)((EBP - 312) + 28), FS[0]);  // @163_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 312) + 28) + 0), 4); v; });  // @164_44dc90
  X0[1] = 0;  // @165_44dc90
  X0[2] = 0;  // @166_44dc90
  X0[3] = 0;  // @167_44dc90
  __builtin_memcpy((void *)((u32)(ebx + eax + 8) + 0), &X0[0], 4);  // @168_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @169_44dc90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @170_44dc90
  esi = (esi + (u32)(12));  // @171_44dc90
  FL[3] = esi;  // @172_44dc90
  esi = (esi + ebx);  // @173_44dc90
  FL[3] = esi;  // @174_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @176_44dc90
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(151));  // @177_44dc90
  ecx = edx = 0;  // @178_44dc90
  FS[0] = (FS[0] * LDF((u32)(6818396)));  // @179_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @180_44dc90
  FS[0] = (FS[0] + LDF((u32)((EBP - 312) + 64)));  // @181_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @182_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @183_44dc90
  STF((u32)((EBP - 312) + 68), FS[0]);  // @184_44dc90
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(152));  // @185_44dc90
  ecx = edx = 0;  // @186_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @187_44dc90
  STF((u32)((EBP - 304) + 20), FS[0]);  // @188_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 20) + 0), 4); v; });  // @189_44dc90
  X0[1] = 0;  // @190_44dc90
  X0[2] = 0;  // @191_44dc90
  X0[3] = 0;  // @192_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })));  // @193_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @194_44dc90
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @195_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @196_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818388) + 0), 4); v; })));  // @197_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 312) + 52) + 0), &X0[0], 4);  // @198_44dc90
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(153));  // @199_44dc90
  ecx = edx = 0;  // @200_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 60) + 0), 4); v; });  // @201_44dc90
  X0[1] = 0;  // @202_44dc90
  X0[2] = 0;  // @203_44dc90
  X0[3] = 0;  // @204_44dc90
  STF((u32)((EBP - 304) + 20), FS[0]);  // @205_44dc90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 20) + 0), 4); v; });  // @206_44dc90
  X1[1] = 0;  // @207_44dc90
  X1[2] = 0;  // @208_44dc90
  X1[3] = 0;  // @209_44dc90
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })));  // @210_44dc90
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @211_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 44) + 0), 4); v; });  // @212_44dc90
  X0[1] = 0;  // @213_44dc90
  X0[2] = 0;  // @214_44dc90
  X0[3] = 0;  // @215_44dc90
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @216_44dc90
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @217_44dc90
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806028) + 0), 4); v; })));  // @218_44dc90
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 48) + 0), 4); v; })));  // @219_44dc90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 52), sizeof v); (u32)v; });  // @220_44dc90
  ecx = esi;  // @221_44dc90
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X1[0], 4);  // @222_44dc90
  eax = ext_4419f0_fastcall2(ecx, edx);  // @223_44dc90
  ecx = edx = 0;  // @224_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 40), sizeof v); (u32)v; });  // @225_44dc90
  PV[2] = (u32)(esi);  // @226_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @227_44dc90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[2]);  // @228_44dc90
  ecx = edx = 0;  // @229_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @230_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 84) + 0), 4); v; });  // @231_44dc90
  X0[1] = 0;  // @232_44dc90
  X0[2] = 0;  // @233_44dc90
  X0[3] = 0;  // @234_44dc90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 16), sizeof v); (u32)v; });  // @235_44dc90
  esi = (esi + (u32)(24));  // @236_44dc90
  FL[3] = esi;  // @237_44dc90
  __builtin_memcpy((void *)((u32)(ebx + eax + 24) + 0), &X0[0], 4);  // @238_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 88) + 0), 4); v; });  // @239_44dc90
  X0[1] = 0;  // @240_44dc90
  X0[2] = 0;  // @241_44dc90
  X0[3] = 0;  // @242_44dc90
  __builtin_memcpy((void *)((u32)(ebx + eax + 28) + 0), &X0[0], 4);  // @243_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 92) + 0), 4); v; });  // @244_44dc90
  X0[1] = 0;  // @245_44dc90
  X0[2] = 0;  // @246_44dc90
  X0[3] = 0;  // @247_44dc90
  __builtin_memcpy((void *)((u32)(ebx + eax + 32) + 0), &X0[0], 4);  // @248_44dc90
  ebx = (ebx + (u32)(48));  // @249_44dc90
  FL[3] = ebx;  // @250_44dc90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 32), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)((EBP - 304) + 32), &v, sizeof v); }  // @251_44dc90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 32), sizeof v); (u32)v; });  // @252_44dc90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 304) + 16), &v, sizeof v); }  // @253_44dc90
  if (FL[3] != 0) goto L44de20;  // @254_44dc90
  L44e011:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @256_44dc90
  if (FL[0] != FL[1]) goto L44dd70;  // @257_44dc90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 52), sizeof v); (u32)v; });  // @258_44dc90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 40), sizeof v); (u32)v; });  // @259_44dc90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 24), sizeof v); (u32)v; });  // @260_44dc90
  L44e027:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @262_44dc90
  ecx = (u32)(edi + 24);  // @263_44dc90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 304) + 44), &v, sizeof v); }  // @264_44dc90
  if (FL[0] != FL[1]) goto L44e03e;  // @265_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 36), sizeof v); (u32)v; });  // @266_44dc90
  PV[3] = (u32)(edx);  // @267_44dc90
  eax = ext_44d520_thiscall2(ecx, PV[3]);  // @268_44dc90
  ecx = edx = 0;  // @269_44dc90
  L44e03e:;
  ecx = (u32)((EBP - 304) + 192);  // @271_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 120), &v, sizeof v); }  // @272_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 124), &v, sizeof v); }  // @273_44dc90
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 304) + 128), &v, sizeof v); }  // @274_44dc90
  eax = ext_4de7a0_thiscall1(ecx);  // @275_44dc90
    // @276_44dc90
  edx = ebx;  // @277_44dc90
  ecx = (u32)((EBP - 304) + 120);  // @278_44dc90
  eax = ext_4419f0_fastcall2(ecx, edx);  // @279_44dc90
  ecx = edx = 0;  // @280_44dc90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 28), sizeof v); (u32)v; });  // @281_44dc90
  ecx = (u32)((EBP - 304) + 120);  // @282_44dc90
  eax = ext_441940_fastcall2(ecx, edx);  // @283_44dc90
  ecx = edx = 0;  // @284_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @285_44dc90
  X0[1] = 0;  // @286_44dc90
  X0[2] = 0;  // @287_44dc90
  X0[3] = 0;  // @288_44dc90
  ecx = (u32)((EBP - 304) + 120);  // @289_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @290_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 304) + 192) + 0), &X0[0], 4);  // @291_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @292_44dc90
  X0[1] = 0;  // @293_44dc90
  X0[2] = 0;  // @294_44dc90
  X0[3] = 0;  // @295_44dc90
  PV[4] = (u32)(ecx);  // @296_44dc90
  ecx = (u32)((EBP - 308) + 196);  // @297_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 308) + 200) + 0), &X0[0], 4);  // @298_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @299_44dc90
  X0[1] = 0;  // @300_44dc90
  X0[2] = 0;  // @301_44dc90
  X0[3] = 0;  // @302_44dc90
  PV[5] = (u32)(ecx);  // @303_44dc90
  ecx = esi;  // @304_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 312) + 208) + 0), &X0[0], 4);  // @305_44dc90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[5], PV[4]);  // @306_44dc90
  ecx = edx = 0;  // @307_44dc90
  ecx = (u32)((EBP - 304) + 228);  // @308_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 108), &v, sizeof v); }  // @309_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 112), &v, sizeof v); }  // @310_44dc90
  { u32 v = (u32)((u32)(3259498496)); __builtin_memcpy((void *)(u32)((EBP - 304) + 116), &v, sizeof v); }  // @311_44dc90
  eax = ext_4de7a0_thiscall1(ecx);  // @312_44dc90
    // @313_44dc90
  edx = ebx;  // @314_44dc90
  ecx = (u32)((EBP - 304) + 108);  // @315_44dc90
  eax = ext_4419f0_fastcall2(ecx, edx);  // @316_44dc90
  ecx = edx = 0;  // @317_44dc90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 28), sizeof v); (u32)v; });  // @318_44dc90
  ecx = (u32)((EBP - 304) + 108);  // @319_44dc90
  eax = ext_441940_fastcall2(ecx, edx);  // @320_44dc90
  ecx = edx = 0;  // @321_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @322_44dc90
  X0[1] = 0;  // @323_44dc90
  X0[2] = 0;  // @324_44dc90
  X0[3] = 0;  // @325_44dc90
  ecx = (u32)((EBP - 304) + 108);  // @326_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @327_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 304) + 228) + 0), &X0[0], 4);  // @328_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @329_44dc90
  X0[1] = 0;  // @330_44dc90
  X0[2] = 0;  // @331_44dc90
  X0[3] = 0;  // @332_44dc90
  PV[6] = (u32)(ecx);  // @333_44dc90
  ecx = (u32)((EBP - 308) + 232);  // @334_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 308) + 236) + 0), &X0[0], 4);  // @335_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @336_44dc90
  X0[1] = 0;  // @337_44dc90
  X0[2] = 0;  // @338_44dc90
  X0[3] = 0;  // @339_44dc90
  PV[7] = (u32)(ecx);  // @340_44dc90
  ecx = esi;  // @341_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 312) + 244) + 0), &X0[0], 4);  // @342_44dc90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[7], PV[6]);  // @343_44dc90
  ecx = edx = 0;  // @344_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @345_44dc90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 36), sizeof v); (u32)v; });  // @346_44dc90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @347_44dc90
  X2[1] = 0;  // @348_44dc90
  X2[2] = 0;  // @349_44dc90
  X2[3] = 0;  // @350_44dc90
  edx = (edx + (u32)(36));  // @351_44dc90
  FL[3] = edx;  // @352_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @353_44dc90
  X0[1] = 0;  // @354_44dc90
  X0[2] = 0;  // @355_44dc90
  X0[3] = 0;  // @356_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @357_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @358_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @359_44dc90
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @360_44dc90
  ecx = (ecx - eax);  // @361_44dc90
  FL[3] = ecx;  // @362_44dc90
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @363_44dc90
  X1[0] = F2U((float)(s32)X1[0]);  // @364_44dc90
  X1[1] = F2U((float)(s32)X1[1]);  // @365_44dc90
  X1[2] = F2U((float)(s32)X1[2]);  // @366_44dc90
  X1[3] = F2U((float)(s32)X1[3]);  // @367_44dc90
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @368_44dc90
  X0[0] = X1[0];  // @369_44dc90
  X0[1] = X1[1];  // @370_44dc90
  X0[2] = X1[2];  // @371_44dc90
  X0[3] = X1[3];  // @372_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 304) + 24) + 0), &X1[0], 4);  // @373_44dc90
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @374_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @375_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @376_44dc90
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @377_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 304) + 28) + 0), &X0[0], 4);  // @378_44dc90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L44e1a3;  // @379_44dc90
  __builtin_memcpy((void *)((u32)((EBP - 304) + 28) + 0), &X1[0], 4);  // @380_44dc90
  L44e1a3:;
  eax = (u32)((EBP - 304) + 68);  // @382_44dc90
  FL[0] = edx; FL[1] = eax;  // @383_44dc90
  if (FL[0] == FL[1]) goto L44e1c8;  // @384_44dc90
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @385_44dc90
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @386_44dc90
  X0[0] = F2U((float)(s32)X0[0]);  // @387_44dc90
  X0[1] = F2U((float)(s32)X0[1]);  // @388_44dc90
  X0[2] = F2U((float)(s32)X0[2]);  // @389_44dc90
  X0[3] = F2U((float)(s32)X0[3]);  // @390_44dc90
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @391_44dc90
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @392_44dc90
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @393_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @394_44dc90
  L44e1c8:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @396_44dc90
  edx = (u32)(edi + 24);  // @397_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 16), &v, sizeof v); }  // @398_44dc90
  if (FL[0] <= FL[1]) goto L44e4d1;  // @399_44dc90
  esi = 0;  // @400_44dc90
  FL[3] = esi;  // @401_44dc90
  ebx = 0;  // @402_44dc90
  FL[3] = ebx;  // @403_44dc90
  L44e1e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @405_44dc90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @406_44dc90
  if (FL[0] != FL[1]) goto L44e222;  // @407_44dc90
  eax = (eax + (u32)(36));  // @408_44dc90
  FL[3] = eax;  // @409_44dc90
  edx = (u32)((EBP - 304) + 84);  // @410_44dc90
  eax = (eax + esi);  // @411_44dc90
  FL[3] = eax;  // @412_44dc90
  ecx = (u32)((EBP - 304) + 72);  // @413_44dc90
  PV[8] = (u32)(eax);  // @414_44dc90
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @415_44dc90
  ecx = edx = 0;  // @416_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @417_44dc90
  edx = (u32)((EBP - 304) + 72);  // @418_44dc90
  ecx = (ecx + (u32)(12));  // @419_44dc90
  FL[3] = ecx;  // @420_44dc90
  ecx = (ecx + esi);  // @421_44dc90
  FL[3] = ecx;  // @422_44dc90
  eax = ext_441940_fastcall2(ecx, edx);  // @423_44dc90
  ecx = edx = 0;  // @424_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @425_44dc90
  edx = (u32)((EBP - 304) + 72);  // @426_44dc90
  ecx = (ecx + (u32)(24));  // @427_44dc90
  FL[3] = ecx;  // @428_44dc90
  ecx = (ecx + esi);  // @429_44dc90
  FL[3] = ecx;  // @430_44dc90
  eax = ext_441940_fastcall2(ecx, edx);  // @431_44dc90
  ecx = edx = 0;  // @432_44dc90
  edx = (u32)(edi + 24);  // @433_44dc90
  L44e222:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @435_44dc90
  X1[0] = 0;  // @436_44dc90
  X1[1] = 0;  // @437_44dc90
  X1[2] = 0;  // @438_44dc90
  X1[3] = 0;  // @439_44dc90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + eax), &v, sizeof v); }  // @440_44dc90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; });  // @441_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @442_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 4) + 0), 4); v; });  // @443_44dc90
  X0[1] = 0;  // @444_44dc90
  X0[2] = 0;  // @445_44dc90
  X0[3] = 0;  // @446_44dc90
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @447_44dc90
  if ((!(FA >= FB))) goto L44e28d;  // @448_44dc90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @449_44dc90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @450_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @451_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @452_44dc90
  eax = (u32)(eax + eax*2);  // @453_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 0), 4); v; });  // @454_44dc90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 4), 4); v; });  // @455_44dc90
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 8), 4); v; });  // @456_44dc90
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 12), 4); v; });  // @457_44dc90
  __builtin_memcpy((void *)((u32)(ebx + ecx) + 0), &X0[0], 4);  // @458_44dc90
  __builtin_memcpy((void *)((u32)(ebx + ecx) + 4), &X0[1], 4);  // @459_44dc90
  __builtin_memcpy((void *)((u32)(ebx + ecx) + 8), &X0[2], 4);  // @460_44dc90
  __builtin_memcpy((void *)((u32)(ebx + ecx) + 12), &X0[3], 4);  // @461_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 0), 4); v; });  // @462_44dc90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 4), 4); v; });  // @463_44dc90
  X0[2] = 0;  // @464_44dc90
  X0[3] = 0;  // @465_44dc90
  __builtin_memcpy((void *)((u32)(ebx + ecx + 16) + 0), &X0[0], 4);  // @466_44dc90
  __builtin_memcpy((void *)((u32)(ebx + ecx + 16) + 4), &X0[1], 4);  // @467_44dc90
  ebx = (ebx - (u32)(24));  // @468_44dc90
  FL[3] = ebx;  // @469_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @470_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @471_44dc90
  eax = (u32)(eax + eax*2);  // @472_44dc90
  eax = (eax + eax);  // @473_44dc90
  FL[3] = eax;  // @474_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 0), 4); v; });  // @475_44dc90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 4), 4); v; });  // @476_44dc90
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 8), 4); v; });  // @477_44dc90
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 12), 4); v; });  // @478_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx) + 0), &X0[0], 4);  // @479_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx) + 4), &X0[1], 4);  // @480_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx) + 8), &X0[2], 4);  // @481_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx) + 12), &X0[3], 4);  // @482_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 0), 4); v; });  // @483_44dc90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 4), 4); v; });  // @484_44dc90
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 8), 4); v; });  // @485_44dc90
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 12), 4); v; });  // @486_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx + 16) + 0), &X0[0], 4);  // @487_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx + 16) + 4), &X0[1], 4);  // @488_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx + 16) + 8), &X0[2], 4);  // @489_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx + 16) + 12), &X0[3], 4);  // @490_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 32) + 0), 4); v; });  // @491_44dc90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 32) + 4), 4); v; });  // @492_44dc90
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 32) + 8), 4); v; });  // @493_44dc90
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 32) + 12), 4); v; });  // @494_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 16), sizeof v); (u32)v; });  // @495_44dc90
  eax = (eax - 1);  // @496_44dc90
  FL[3] = eax;  // @497_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx + 32) + 0), &X0[0], 4);  // @498_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx + 32) + 4), &X0[1], 4);  // @499_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx + 32) + 8), &X0[2], 4);  // @500_44dc90
  __builtin_memcpy((void *)((u32)(esi + ecx + 32) + 12), &X0[3], 4);  // @501_44dc90
  esi = (esi - (u32)(48));  // @502_44dc90
  FL[3] = esi;  // @503_44dc90
  goto L44e4ba;  // @504_44dc90
  L44e28d:;
  eax = (u32)ext_633910(U2F(X0[0]));  // @506_44dc90
  ecx = edx = 0;  // @507_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @508_44dc90
  edx = eax;  // @509_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @510_44dc90
  edx = (edx << (u32)(26));  // @511_44dc90
  FL[3] = edx;  // @512_44dc90
  edx = (edx | (u32)(16777215));  // @513_44dc90
  FL[3] = edx;  // @514_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 8) + 0), 4); v; });  // @515_44dc90
  X0[1] = 0;  // @516_44dc90
  X0[2] = 0;  // @517_44dc90
  X0[3] = 0;  // @518_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 24) + 0), 4); v; })));  // @519_44dc90
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx + 12) + 0), 4); v; })));  // @520_44dc90
  __builtin_memcpy((void *)((u32)(ebx + ecx + 12) + 0), &X0[0], 4);  // @521_44dc90
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 24) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @522_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @523_44dc90
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + eax + 20), &v, sizeof v); }  // @524_44dc90
  FL[0] = ecx; FL[1] = (u32)(1);  // @525_44dc90
  if ((s32)FL[0] < (s32)FL[1]) goto L44e335;  // @526_44dc90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818392) + 0), 4); v; });  // @527_44dc90
  X1[1] = 0;  // @528_44dc90
  X1[2] = 0;  // @529_44dc90
  X1[3] = 0;  // @530_44dc90
  L44e2e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @532_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 12) + 0), 4); v; });  // @533_44dc90
  X0[1] = 0;  // @534_44dc90
  X0[2] = 0;  // @535_44dc90
  X0[3] = 0;  // @536_44dc90
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 24) + 0), 4); v; })));  // @537_44dc90
  __builtin_memcpy((void *)((u32)(esi + eax + 24) + 0), &X0[0], 4);  // @538_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @539_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 12) + 0), 4); v; });  // @540_44dc90
  X0[1] = 0;  // @541_44dc90
  X0[2] = 0;  // @542_44dc90
  X0[3] = 0;  // @543_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @544_44dc90
  __builtin_memcpy((void *)((u32)(esi + eax + 12) + 0), &X0[0], 4);  // @545_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @546_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 20) + 0), 4); v; });  // @547_44dc90
  X0[1] = 0;  // @548_44dc90
  X0[2] = 0;  // @549_44dc90
  X0[3] = 0;  // @550_44dc90
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 32) + 0), 4); v; })));  // @551_44dc90
  __builtin_memcpy((void *)((u32)(esi + eax + 32) + 0), &X0[0], 4);  // @552_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @553_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 20) + 0), 4); v; });  // @554_44dc90
  X0[1] = 0;  // @555_44dc90
  X0[2] = 0;  // @556_44dc90
  X0[3] = 0;  // @557_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @558_44dc90
  __builtin_memcpy((void *)((u32)(esi + eax + 20) + 0), &X0[0], 4);  // @559_44dc90
  ecx = (ecx - (u32)(1));  // @560_44dc90
  FL[3] = ecx;  // @561_44dc90
  if (FL[3] != 0) goto L44e2e0;  // @562_44dc90
  L44e335:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @564_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 28) + 0), 4); v; });  // @565_44dc90
  X0[1] = 0;  // @566_44dc90
  X0[2] = 0;  // @567_44dc90
  X0[3] = 0;  // @568_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818384) + 0), 4); v; })));  // @569_44dc90
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 16) + 0), 4); v; })));  // @570_44dc90
  __builtin_memcpy((void *)((u32)(esi + eax + 16) + 0), &X0[0], 4);  // @571_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @572_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 16) + 0), 4); v; });  // @573_44dc90
  X0[1] = 0;  // @574_44dc90
  X0[2] = 0;  // @575_44dc90
  X0[3] = 0;  // @576_44dc90
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 28) + 0), 4); v; })));  // @577_44dc90
  __builtin_memcpy((void *)((u32)(esi + eax + 28) + 0), &X0[0], 4);  // @578_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @579_44dc90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @580_44dc90
  if ((s32)FL[0] <= (s32)FL[1]) goto L44e481;  // @581_44dc90
  eax = (eax + (u32)(24));  // @582_44dc90
  FL[3] = eax;  // @583_44dc90
  edx = (u32)((EBP - 304) + 108);  // @584_44dc90
  eax = (eax + esi);  // @585_44dc90
  FL[3] = eax;  // @586_44dc90
  ecx = (u32)((EBP - 304) + 96);  // @587_44dc90
  PV[9] = (u32)(eax);  // @588_44dc90
  eax = ext_43e920_fastcall3(ecx, edx, PV[9]);  // @589_44dc90
  ecx = edx = 0;  // @590_44dc90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 96) + 0), 4); v; });  // @591_44dc90
  X1[1] = 0;  // @592_44dc90
  X1[2] = 0;  // @593_44dc90
  X1[3] = 0;  // @594_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 100) + 0), 4); v; });  // @595_44dc90
  X0[1] = 0;  // @596_44dc90
  X0[2] = 0;  // @597_44dc90
  X0[3] = 0;  // @598_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @599_44dc90
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @600_44dc90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @601_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 104) + 0), 4); v; });  // @602_44dc90
  X0[1] = 0;  // @603_44dc90
  X0[2] = 0;  // @604_44dc90
  X0[3] = 0;  // @605_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @606_44dc90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @607_44dc90
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @608_44dc90
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @609_44dc90
  ecx = edx = 0;  // @610_44dc90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; });  // @611_44dc90
  X2[1] = 0;  // @612_44dc90
  X2[2] = 0;  // @613_44dc90
  X2[3] = 0;  // @614_44dc90
  X1[0] = 0;  // @615_44dc90
  X1[1] = 0;  // @616_44dc90
  X1[2] = 0;  // @617_44dc90
  X1[3] = 0;  // @618_44dc90
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @619_44dc90
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @620_44dc90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L44e3f9;  // @621_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818440) + 0), 4); v; });  // @622_44dc90
  X0[1] = 0;  // @623_44dc90
  X0[2] = 0;  // @624_44dc90
  X0[3] = 0;  // @625_44dc90
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @626_44dc90
  PV[10] = (u32)(ecx);  // @627_44dc90
  ecx = (u32)((EBP - 308) + 100);  // @628_44dc90
  X0[0] = F2U(U2F(X0[0]) / U2F(X2[0]));  // @629_44dc90
  PV[11] = X0[0];  // @630_44dc90
  eax = ext_4e0d00_thiscall2(ecx, PV[11]);  // @631_44dc90
    // @632_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @633_44dc90
  edx = (u32)((EBP - 304) + 96);  // @634_44dc90
  ecx = (ecx + (u32)(24));  // @635_44dc90
  FL[3] = ecx;  // @636_44dc90
  ecx = (ecx + esi);  // @637_44dc90
  FL[3] = ecx;  // @638_44dc90
  eax = ext_43e960_fastcall2(ecx, edx);  // @639_44dc90
  ecx = edx = 0;  // @640_44dc90
  L44e3f9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @642_44dc90
  edx = (u32)((EBP - 304) + 120);  // @643_44dc90
  eax = (eax + (u32)(24));  // @644_44dc90
  FL[3] = eax;  // @645_44dc90
  ecx = (u32)((EBP - 304) + 96);  // @646_44dc90
  eax = (eax + esi);  // @647_44dc90
  FL[3] = eax;  // @648_44dc90
  PV[12] = (u32)(eax);  // @649_44dc90
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @650_44dc90
  ecx = edx = 0;  // @651_44dc90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 96) + 0), 4); v; });  // @652_44dc90
  X1[1] = 0;  // @653_44dc90
  X1[2] = 0;  // @654_44dc90
  X1[3] = 0;  // @655_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 100) + 0), 4); v; });  // @656_44dc90
  X0[1] = 0;  // @657_44dc90
  X0[2] = 0;  // @658_44dc90
  X0[3] = 0;  // @659_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @660_44dc90
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @661_44dc90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @662_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 104) + 0), 4); v; });  // @663_44dc90
  X0[1] = 0;  // @664_44dc90
  X0[2] = 0;  // @665_44dc90
  X0[3] = 0;  // @666_44dc90
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @667_44dc90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @668_44dc90
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @669_44dc90
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @670_44dc90
  ecx = edx = 0;  // @671_44dc90
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818424) + 0), 4); v; });  // @672_44dc90
  X2[1] = 0;  // @673_44dc90
  X2[2] = 0;  // @674_44dc90
  X2[3] = 0;  // @675_44dc90
  X1[0] = 0;  // @676_44dc90
  X1[1] = 0;  // @677_44dc90
  X1[2] = 0;  // @678_44dc90
  X1[3] = 0;  // @679_44dc90
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @680_44dc90
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @681_44dc90
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L44e481;  // @682_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818428) + 0), 4); v; });  // @683_44dc90
  X0[1] = 0;  // @684_44dc90
  X0[2] = 0;  // @685_44dc90
  X0[3] = 0;  // @686_44dc90
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @687_44dc90
  PV[13] = (u32)(ecx);  // @688_44dc90
  ecx = (u32)((EBP - 308) + 100);  // @689_44dc90
  X0[0] = F2U(U2F(X0[0]) / U2F(X2[0]));  // @690_44dc90
  PV[14] = X0[0];  // @691_44dc90
  eax = ext_4e0d00_thiscall2(ecx, PV[14]);  // @692_44dc90
    // @693_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @694_44dc90
  edx = (u32)((EBP - 304) + 96);  // @695_44dc90
  ecx = (ecx + (u32)(24));  // @696_44dc90
  FL[3] = ecx;  // @697_44dc90
  ecx = (ecx + esi);  // @698_44dc90
  FL[3] = ecx;  // @699_44dc90
  eax = ext_43e960_fastcall2(ecx, edx);  // @700_44dc90
  ecx = edx = 0;  // @701_44dc90
  L44e481:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @703_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @704_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx + 24), sizeof v); (u32)v; });  // @705_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx), &v, sizeof v); }  // @706_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx + 28), sizeof v); (u32)v; });  // @707_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx + 4), &v, sizeof v); }  // @708_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx + 32), sizeof v); (u32)v; });  // @709_44dc90
  edx = (u32)(edi + 24);  // @710_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx + 8), &v, sizeof v); }  // @711_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @712_44dc90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 4) + 0), 4); v; });  // @713_44dc90
  X0[1] = 0;  // @714_44dc90
  X0[2] = 0;  // @715_44dc90
  X0[3] = 0;  // @716_44dc90
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 304) + 24) + 0), 4); v; })));  // @717_44dc90
  __builtin_memcpy((void *)((u32)(esi + eax + 4) + 0), &X0[0], 4);  // @718_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 16), sizeof v); (u32)v; });  // @719_44dc90
  L44e4ba:;
  eax = (eax + 1);  // @721_44dc90
  FL[3] = eax;  // @722_44dc90
  ebx = (ebx + (u32)(24));  // @723_44dc90
  FL[3] = ebx;  // @724_44dc90
  esi = (esi + (u32)(48));  // @725_44dc90
  FL[3] = esi;  // @726_44dc90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 304) + 16), &v, sizeof v); }  // @727_44dc90
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @728_44dc90
  if (FL[0] < FL[1]) goto L44e1e1;  // @729_44dc90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 40), sizeof v); (u32)v; });  // @730_44dc90
  L44e4d1:;
  ecx = (u32)((EBP - 304) + 264);  // @732_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 144), &v, sizeof v); }  // @733_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 148), &v, sizeof v); }  // @734_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 304) + 152), &v, sizeof v); }  // @735_44dc90
  eax = ext_4de7a0_thiscall1(ecx);  // @736_44dc90
    // @737_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @738_44dc90
  ecx = (u32)((EBP - 304) + 132);  // @739_44dc90
  PV[15] = (u32)(ecx);  // @740_44dc90
  ecx = (u32)((EBP - 308) + 268);  // @741_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 308) + 136), &v, sizeof v); }  // @742_44dc90
  PV[16] = (u32)(ecx);  // @743_44dc90
  ecx = esi;  // @744_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 312) + 144), &v, sizeof v); }  // @745_44dc90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 312) + 148), &v, sizeof v); }  // @746_44dc90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 148)))(ecx, PV[16], PV[15]);  // @747_44dc90
  ecx = edx = 0;  // @748_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 44), sizeof v); (u32)v; });  // @749_44dc90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 304) + 64), sizeof v); (u32)v; });  // @750_44dc90
  PV[17] = (u32)(ecx);  // @751_44dc90
  PV[18] = (u32)(ecx);  // @752_44dc90
  ecx = (u32)((EBP - 312) + 152);  // @753_44dc90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @754_44dc90
  PV[19] = (u32)(ecx);  // @755_44dc90
  ecx = (u32)((EBP - 316) + 144);  // @756_44dc90
  PV[20] = (u32)(ecx);  // @757_44dc90
  ecx = (u32)((EBP - 320) + 280);  // @758_44dc90
  PV[21] = (u32)(ecx);  // @759_44dc90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 324) + 56), sizeof v); (u32)v; });  // @760_44dc90
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @761_44dc90
  ecx = edx;  // @762_44dc90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, PV[22], PV[21], PV[20], PV[19], (u32)(1343554297), PV[17]);  // @763_44dc90
  ecx = edx = 0;  // @764_44dc90
  L44e570:;
  ext_633654(G(u32, 0x6f5630));  // @766_44dc90
  return eax;  // @767_44dc90
}
PCREG(44dc90, lifted_44dc90);

