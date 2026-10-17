// batch234018.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_589c20_thiscall2(u32, u32) __asm__("ext_589c20");
extern "C" u32 THISCALL ext_597720_thiscall2(u32, u32) __asm__("ext_597720");
extern "C" u32 THISCALL ext_5b5370_thiscall2(u32, u32) __asm__("ext_5b5370");
extern "C" u32 THISCALL ext_5f0380_thiscall1(u32) __asm__("ext_5f0380");
extern "C" u32 THISCALL ext_5f04a0_thiscall1(u32) __asm__("ext_5f04a0");
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

extern "C" u32 THISCALL lifted_5b4160(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @1_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @2_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1668), sizeof v); (u32)v; });  // @3_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @4_5b4160
  FL[3] = (eax & 0xff);  // @5_5b4160
  eax = (eax & 0xff);  // @6_5b4160
  PV[0] = (u32)(eax);  // @7_5b4160
  eax = ext_589c20_thiscall2(ecx, PV[0]);  // @8_5b4160
    // @9_5b4160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 91), &v, sizeof v); }  // @10_5b4160
  FL[2] = (eax & eax);  // @11_5b4160
  if (FL[2] == 0) goto L5b4b33;  // @12_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @14_5b4160
  if (FL[0] == FL[1]) goto L5b42e9;  // @15_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6407), sizeof v); (u32)v; });  // @16_5b4160
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 203), sizeof v); (u32)v; });  // @17_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @19_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[1], (u32)(0));  // @20_5b4160
  ecx = edx = 0;  // @21_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @22_5b4160
  if (FL[2] == 0) goto L5b41cf;  // @23_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 87), sizeof v); (u32)v; });  // @24_5b4160
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 203), sizeof v); (u32)v; });  // @25_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @27_5b4160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[2]);  // @28_5b4160
  ecx = edx = 0;  // @29_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 375), &v, sizeof v); }  // @30_5b4160
  goto L5b41d6;  // @31_5b4160
  L5b41cf:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 375), &v, sizeof v); }  // @33_5b4160
  L5b41d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_5b4160
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @36_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @37_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @39_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[3], (u32)(0));  // @40_5b4160
  ecx = edx = 0;  // @41_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @42_5b4160
  if (FL[2] == 0) goto L5b420c;  // @43_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 87), sizeof v); (u32)v; });  // @44_5b4160
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 207), sizeof v); (u32)v; });  // @45_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @47_5b4160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[4]);  // @48_5b4160
  ecx = edx = 0;  // @49_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 376), &v, sizeof v); }  // @50_5b4160
  goto L5b4213;  // @51_5b4160
  L5b420c:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 376), &v, sizeof v); }  // @53_5b4160
  L5b4213:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_5b4160
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 211), sizeof v); (u32)v; });  // @56_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @57_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @59_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[5], (u32)(0));  // @60_5b4160
  ecx = edx = 0;  // @61_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @62_5b4160
  if (FL[2] == 0) goto L5b4249;  // @63_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 87), sizeof v); (u32)v; });  // @64_5b4160
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 211), sizeof v); (u32)v; });  // @65_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @67_5b4160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[6]);  // @68_5b4160
  ecx = edx = 0;  // @69_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 377), &v, sizeof v); }  // @70_5b4160
  goto L5b4250;  // @71_5b4160
  L5b4249:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 377), &v, sizeof v); }  // @73_5b4160
  L5b4250:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_5b4160
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 215), sizeof v); (u32)v; });  // @76_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @77_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @79_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[7], (u32)(0));  // @80_5b4160
  ecx = edx = 0;  // @81_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @82_5b4160
  if (FL[2] == 0) goto L5b4286;  // @83_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 87), sizeof v); (u32)v; });  // @84_5b4160
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 215), sizeof v); (u32)v; });  // @85_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @87_5b4160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[8]);  // @88_5b4160
  ecx = edx = 0;  // @89_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 378), &v, sizeof v); }  // @90_5b4160
  goto L5b428d;  // @91_5b4160
  L5b4286:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 378), &v, sizeof v); }  // @93_5b4160
  L5b428d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_5b4160
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 219), sizeof v); (u32)v; });  // @96_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @97_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @99_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[9], (u32)(0));  // @100_5b4160
  ecx = edx = 0;  // @101_5b4160
  FL[1] = (eax & 0xff);  // @102_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @103_5b4160
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 223), sizeof v); (u32)v; });  // @104_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @105_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @106_5b4160
  FL[3] = (eax & 0xff);  // @107_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 379), &v, sizeof v); }  // @108_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @110_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @111_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @112_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[10], (u32)(0));  // @113_5b4160
  ecx = edx = 0;  // @114_5b4160
  FL[1] = (eax & 0xff);  // @115_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @116_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @117_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @118_5b4160
  FL[3] = (eax & 0xff);  // @119_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 380), &v, sizeof v); }  // @120_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @121_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @122_5b4160
  if (FL[0] != FL[1]) goto L5b43c0;  // @123_5b4160
  L5b42e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 188), sizeof v); (u32)v; });  // @126_5b4160
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @127_5b4160
  ecx = edx = 0;  // @128_5b4160
  ecx = eax;  // @129_5b4160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @130_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 168), sizeof v); (u32)v; });  // @131_5b4160
  FS[0] = ((long double(THISCALL *)(u32))(eax))(ecx);  // @132_5b4160
  ecx = edx = 0;  // @133_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @134_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_5b4160
  FS[0] = (FS[0] * LDF((u32)(6806016)));  // @136_5b4160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @137_5b4160
  X1[1] = 0;  // @138_5b4160
  X1[2] = 0;  // @139_5b4160
  X1[3] = 0;  // @140_5b4160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2547) + 0), 4); v; });  // @141_5b4160
  X0[1] = 0;  // @142_5b4160
  X0[2] = 0;  // @143_5b4160
  X0[3] = 0;  // @144_5b4160
  STF((u32)(EBP - 16), FS[0]);  // @145_5b4160
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @146_5b4160
  __builtin_memcpy((void *)((u32)(esi + 395) + 0), &X0[0], 4);  // @147_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @148_5b4160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2551) + 0), 4); v; });  // @149_5b4160
  X0[1] = 0;  // @150_5b4160
  X0[2] = 0;  // @151_5b4160
  X0[3] = 0;  // @152_5b4160
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @153_5b4160
  __builtin_memcpy((void *)((u32)(esi + 399) + 0), &X0[0], 4);  // @154_5b4160
  if (FL[0] == FL[1]) goto L5b4355;  // @155_5b4160
  X0[0] = X0[0] ^ X1[0];  // @156_5b4160
  X0[1] = X0[1] ^ X1[1];  // @157_5b4160
  X0[2] = X0[2] ^ X1[2];  // @158_5b4160
  X0[3] = X0[3] ^ X1[3];  // @159_5b4160
  __builtin_memcpy((void *)((u32)(esi + 399) + 0), &X0[0], 4);  // @160_5b4160
  L5b4355:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 86), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @162_5b4160
  if (FL[0] == FL[1]) goto L5b436e;  // @163_5b4160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 395) + 0), 4); v; });  // @164_5b4160
  X0[1] = 0;  // @165_5b4160
  X0[2] = 0;  // @166_5b4160
  X0[3] = 0;  // @167_5b4160
  X0[0] = X0[0] ^ X1[0];  // @168_5b4160
  X0[1] = X0[1] ^ X1[1];  // @169_5b4160
  X0[2] = X0[2] ^ X1[2];  // @170_5b4160
  X0[3] = X0[3] ^ X1[3];  // @171_5b4160
  __builtin_memcpy((void *)((u32)(esi + 395) + 0), &X0[0], 4);  // @172_5b4160
  L5b436e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @174_5b4160
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 235), sizeof v); (u32)v; });  // @175_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @176_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @178_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[11], (u32)(0));  // @179_5b4160
  ecx = edx = 0;  // @180_5b4160
  FL[1] = (eax & 0xff);  // @181_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @182_5b4160
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 239), sizeof v); (u32)v; });  // @183_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @184_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @185_5b4160
  FL[3] = (eax & 0xff);  // @186_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 383), &v, sizeof v); }  // @187_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @189_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @190_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @191_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[12], (u32)(0));  // @192_5b4160
  ecx = edx = 0;  // @193_5b4160
  FL[1] = (eax & 0xff);  // @194_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @195_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @196_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @197_5b4160
  FL[3] = (eax & 0xff);  // @198_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @199_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @200_5b4160
  L5b43c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6407), sizeof v); (u32)v; });  // @202_5b4160
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 199), sizeof v); (u32)v; });  // @203_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @204_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @205_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[13], (u32)(0));  // @206_5b4160
  ecx = edx = 0;  // @207_5b4160
  FL[1] = (eax & 0xff);  // @208_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @209_5b4160
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 191), sizeof v); (u32)v; });  // @210_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @211_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @212_5b4160
  FL[3] = (eax & 0xff);  // @213_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 374), &v, sizeof v); }  // @214_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @215_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @216_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @217_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @218_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[14], (u32)(0));  // @219_5b4160
  ecx = edx = 0;  // @220_5b4160
  FL[1] = (eax & 0xff);  // @221_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @222_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @223_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @224_5b4160
  FL[3] = (eax & 0xff);  // @225_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 373), &v, sizeof v); }  // @226_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @227_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @228_5b4160
  if (FL[0] != FL[1]) goto L5b4440;  // @229_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @230_5b4160
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 283), sizeof v); (u32)v; });  // @231_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @232_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @233_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @234_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[15], (u32)(0));  // @235_5b4160
  ecx = edx = 0;  // @236_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @237_5b4160
  if (FL[2] == 0) goto L5b4440;  // @238_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @239_5b4160
  FL[2] = (ecx & ecx);  // @240_5b4160
  if (FL[2] == 0) goto L5b4440;  // @241_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @242_5b4160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1624)))(ecx);  // @243_5b4160
  ecx = edx = 0;  // @244_5b4160
  L5b4440:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @246_5b4160
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 187), sizeof v); (u32)v; });  // @247_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @248_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @249_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @250_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[16], (u32)(0));  // @251_5b4160
  ecx = edx = 0;  // @252_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @253_5b4160
  if (FL[2] == 0) goto L5b4478;  // @254_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @255_5b4160
  if (FL[0] != FL[1]) goto L5b4478;  // @256_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 600), sizeof v); (u32)v; });  // @257_5b4160
  eax = ext_5f04a0_thiscall1(ecx);  // @258_5b4160
  ecx = edx = 0;  // @259_5b4160
  ecx = esi;  // @260_5b4160
  eax = ext_5b5370_thiscall2(ecx, (u32)(3));  // @261_5b4160
  ecx = edx = 0;  // @262_5b4160
  L5b4478:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @264_5b4160
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 183), sizeof v); (u32)v; });  // @265_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @266_5b4160
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6980), sizeof v); (u32)v; });  // @267_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @268_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @269_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[17], (u32)(0));  // @270_5b4160
  ecx = edx = 0;  // @271_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @272_5b4160
  if (FL[2] != 0) goto L5b44a1;  // @273_5b4160
  FL[2] = (edi & edi);  // @274_5b4160
  if (FL[2] != 0) goto L5b44c6;  // @275_5b4160
  L5b44a1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @277_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @278_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @279_5b4160
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @280_5b4160
  ecx = edx = 0;  // @281_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @282_5b4160
  if (FL[2] != 0) goto L5b44c6;  // @283_5b4160
  ecx = esi;  // @284_5b4160
  eax = ext_5b5370_thiscall2(ecx, (u32)(4));  // @285_5b4160
  ecx = edx = 0;  // @286_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 596), sizeof v); (u32)v; });  // @287_5b4160
  eax = ext_5f0380_thiscall1(ecx);  // @288_5b4160
  ecx = edx = 0;  // @289_5b4160
  L5b44c6:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @291_5b4160
  if (FL[0] != FL[1]) goto L5b4568;  // @292_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @293_5b4160
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 147), sizeof v); (u32)v; });  // @294_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @295_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @296_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @297_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[18], (u32)(0));  // @298_5b4160
  ecx = edx = 0;  // @299_5b4160
  FL[1] = (eax & 0xff);  // @300_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @301_5b4160
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 151), sizeof v); (u32)v; });  // @302_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @303_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @304_5b4160
  FL[3] = (eax & 0xff);  // @305_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 361), &v, sizeof v); }  // @306_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @307_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @308_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @309_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @310_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[19], (u32)(0));  // @311_5b4160
  ecx = edx = 0;  // @312_5b4160
  FL[1] = (eax & 0xff);  // @313_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @314_5b4160
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 143), sizeof v); (u32)v; });  // @315_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @316_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @317_5b4160
  FL[3] = (eax & 0xff);  // @318_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 362), &v, sizeof v); }  // @319_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @320_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @321_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @322_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @323_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[20], (u32)(0));  // @324_5b4160
  ecx = edx = 0;  // @325_5b4160
  FL[1] = (eax & 0xff);  // @326_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @327_5b4160
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 155), sizeof v); (u32)v; });  // @328_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @329_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @330_5b4160
  FL[3] = (eax & 0xff);  // @331_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 364), &v, sizeof v); }  // @332_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @333_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @334_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @335_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @336_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[21], (u32)(0));  // @337_5b4160
  ecx = edx = 0;  // @338_5b4160
  FL[1] = (eax & 0xff);  // @339_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @340_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @341_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @342_5b4160
  FL[3] = (eax & 0xff);  // @343_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 363), &v, sizeof v); }  // @344_5b4160
  L5b4568:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @346_5b4160
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @347_5b4160
  if (FL[0] != FL[1]) goto L5b45a5;  // @348_5b4160
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2098), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @349_5b4160
  if (FL[0] != FL[1]) goto L5b45a5;  // @350_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @351_5b4160
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 167), sizeof v); (u32)v; });  // @352_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @353_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @354_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @355_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[22], (u32)(0));  // @356_5b4160
  ecx = edx = 0;  // @357_5b4160
  FL[1] = (eax & 0xff);  // @358_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @359_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @360_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @361_5b4160
  FL[3] = (eax & 0xff);  // @362_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 360), &v, sizeof v); }  // @363_5b4160
  goto L5b45ac;  // @364_5b4160
  L5b45a5:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 360), &v, sizeof v); }  // @366_5b4160
  L5b45ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @368_5b4160
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; });  // @369_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @370_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @371_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @372_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[23], (u32)(0));  // @373_5b4160
  ecx = edx = 0;  // @374_5b4160
  FL[1] = (eax & 0xff);  // @375_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @376_5b4160
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 171), sizeof v); (u32)v; });  // @377_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @378_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @379_5b4160
  FL[3] = (eax & 0xff);  // @380_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 420), &v, sizeof v); }  // @381_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @382_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @383_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @384_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @385_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[24], (u32)(0));  // @386_5b4160
  ecx = edx = 0;  // @387_5b4160
  FL[1] = (eax & 0xff);  // @388_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @389_5b4160
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 175), sizeof v); (u32)v; });  // @390_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @391_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @392_5b4160
  FL[3] = (eax & 0xff);  // @393_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 366), &v, sizeof v); }  // @394_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @395_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @396_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @397_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @398_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[25], (u32)(0));  // @399_5b4160
  ecx = edx = 0;  // @400_5b4160
  FL[1] = (eax & 0xff);  // @401_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @402_5b4160
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 179), sizeof v); (u32)v; });  // @403_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @404_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @405_5b4160
  FL[3] = (eax & 0xff);  // @406_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 367), &v, sizeof v); }  // @407_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @408_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @409_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @410_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @411_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[26], (u32)(0));  // @412_5b4160
  ecx = edx = 0;  // @413_5b4160
  FL[1] = (eax & 0xff);  // @414_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @415_5b4160
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 159), sizeof v); (u32)v; });  // @416_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @417_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @418_5b4160
  FL[3] = (eax & 0xff);  // @419_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 368), &v, sizeof v); }  // @420_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @421_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @422_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @423_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @424_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[27], (u32)(0));  // @425_5b4160
  ecx = edx = 0;  // @426_5b4160
  FL[1] = (eax & 0xff);  // @427_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (eax & 0xff))) & 0xff);  // @428_5b4160
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 107), sizeof v); (u32)v; });  // @429_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffu) != 0))) & 0xff);  // @430_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @431_5b4160
  FL[3] = (eax & 0xff);  // @432_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 436), &v, sizeof v); }  // @433_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @434_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @435_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @436_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @437_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[28], (u32)(0));  // @438_5b4160
  ecx = edx = 0;  // @439_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @440_5b4160
  if (FL[2] == 0) goto L5b469a;  // @441_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 87), sizeof v); (u32)v; });  // @442_5b4160
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 107), sizeof v); (u32)v; });  // @443_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @444_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @445_5b4160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[29]);  // @446_5b4160
  ecx = edx = 0;  // @447_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 369), &v, sizeof v); }  // @448_5b4160
  goto L5b46b5;  // @449_5b4160
  L5b469a:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 444), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @451_5b4160
  if (FL[0] == FL[1]) goto L5b46ae;  // @452_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @453_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @454_5b4160
  if (FL[0] == FL[1]) goto L5b46b5;  // @455_5b4160
  L5b46ae:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 369), &v, sizeof v); }  // @457_5b4160
  L5b46b5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @459_5b4160
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 111), sizeof v); (u32)v; });  // @460_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @461_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @462_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @463_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[30], (u32)(0));  // @464_5b4160
  ecx = edx = 0;  // @465_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @466_5b4160
  if (FL[2] == 0) goto L5b46e5;  // @467_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 87), sizeof v); (u32)v; });  // @468_5b4160
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 111), sizeof v); (u32)v; });  // @469_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @470_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @471_5b4160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[31]);  // @472_5b4160
  ecx = edx = 0;  // @473_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 370), &v, sizeof v); }  // @474_5b4160
  goto L5b4700;  // @475_5b4160
  L5b46e5:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 444), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @477_5b4160
  if (FL[0] == FL[1]) goto L5b46f9;  // @478_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @479_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @480_5b4160
  if (FL[0] == FL[1]) goto L5b4700;  // @481_5b4160
  L5b46f9:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 370), &v, sizeof v); }  // @483_5b4160
  L5b4700:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @485_5b4160
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 115), sizeof v); (u32)v; });  // @486_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @487_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @488_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @489_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[32], (u32)(0));  // @490_5b4160
  ecx = edx = 0;  // @491_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @492_5b4160
  if (FL[2] == 0) goto L5b4730;  // @493_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 87), sizeof v); (u32)v; });  // @494_5b4160
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 115), sizeof v); (u32)v; });  // @495_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @496_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @497_5b4160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[33]);  // @498_5b4160
  ecx = edx = 0;  // @499_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 371), &v, sizeof v); }  // @500_5b4160
  goto L5b474b;  // @501_5b4160
  L5b4730:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 444), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @503_5b4160
  if (FL[0] == FL[1]) goto L5b4744;  // @504_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @505_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @506_5b4160
  if (FL[0] == FL[1]) goto L5b474b;  // @507_5b4160
  L5b4744:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 371), &v, sizeof v); }  // @509_5b4160
  L5b474b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @511_5b4160
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; });  // @512_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @513_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @514_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @515_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[34], (u32)(0));  // @516_5b4160
  ecx = edx = 0;  // @517_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @518_5b4160
  if (FL[2] == 0) goto L5b477b;  // @519_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 87), sizeof v); (u32)v; });  // @520_5b4160
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; });  // @521_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @522_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @523_5b4160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[35]);  // @524_5b4160
  ecx = edx = 0;  // @525_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 372), &v, sizeof v); }  // @526_5b4160
  goto L5b4796;  // @527_5b4160
  L5b477b:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 444), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @529_5b4160
  if (FL[0] == FL[1]) goto L5b478f;  // @530_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @531_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @532_5b4160
  if (FL[0] == FL[1]) goto L5b4796;  // @533_5b4160
  L5b478f:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 372), &v, sizeof v); }  // @535_5b4160
  L5b4796:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @537_5b4160
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @538_5b4160
  if (FL[0] != FL[1]) goto L5b4a33;  // @539_5b4160
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2098), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @540_5b4160
  if (FL[0] != FL[1]) goto L5b4a33;  // @541_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 360), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @542_5b4160
  if (FL[0] != FL[1]) goto L5b4a33;  // @543_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @544_5b4160
  edi = 0;  // @545_5b4160
  FL[3] = edi;  // @546_5b4160
  PV[36] = (u32)(edi);  // @547_5b4160
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @548_5b4160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @549_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @550_5b4160
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @551_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @552_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @553_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[37], PV[36]);  // @554_5b4160
  ecx = edx = 0;  // @555_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @556_5b4160
  if (FL[2] == 0) goto L5b47ef;  // @557_5b4160
  { u32 v = (u32)((u32)(127)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @558_5b4160
  goto L5b4813;  // @559_5b4160
  L5b47ef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @561_5b4160
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 127), sizeof v); (u32)v; });  // @562_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @563_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @564_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @565_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[38], (u32)(0));  // @566_5b4160
  ecx = edx = 0;  // @567_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @568_5b4160
  eax = (u32)(127);  // @569_5b4160
  if (FL[2] != 0) edi = eax;  // @570_5b4160
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @571_5b4160
  L5b4813:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @573_5b4160
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 131), sizeof v); (u32)v; });  // @574_5b4160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @575_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @576_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @577_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @578_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[39], (u32)(0));  // @579_5b4160
  ecx = edx = 0;  // @580_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @581_5b4160
  if (FL[2] == 0) goto L5b4843;  // @582_5b4160
  { u32 v = (u32)((u32)(127)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @583_5b4160
  edx = 0;  // @584_5b4160
  FL[3] = edx;  // @585_5b4160
  goto L5b4869;  // @586_5b4160
  L5b4843:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @588_5b4160
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 135), sizeof v); (u32)v; });  // @589_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @590_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @591_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @592_5b4160
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[40], (u32)(0));  // @593_5b4160
  ecx = edx = 0;  // @594_5b4160
  edx = 0;  // @595_5b4160
  FL[3] = edx;  // @596_5b4160
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @597_5b4160
  eax = (u32)(127);  // @598_5b4160
  if (FL[2] != 0) edx = eax;  // @599_5b4160
  L5b4869:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @601_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @602_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @603_5b4160
  if (FL[0] == FL[1]) goto L5b489f;  // @604_5b4160
  edi = (u32)(EBP - 12);  // @605_5b4160
  { u32 v = (u32)((u32)(127)); __builtin_memcpy((void *)(u32)(esi + 527), &v, sizeof v); }  // @606_5b4160
  ecx = (u32)(esi + 523);  // @607_5b4160
  FL[0] = ecx; FL[1] = edi;  // @608_5b4160
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @609_5b4160
  if (FL[0] == FL[1]) goto L5b4893;  // @610_5b4160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @611_5b4160
  L5b4893:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 535), &v, sizeof v); }  // @613_5b4160
  goto L5b48bf;  // @614_5b4160
  L5b489f:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 527), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @616_5b4160
  if (FL[0] == FL[1]) goto L5b48bf;  // @617_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 523), sizeof v); (u32)v; });  // @618_5b4160
  ecx = (ecx + (u32)(102));  // @619_5b4160
  FL[3] = ecx;  // @620_5b4160
  FL[0] = ecx; FL[1] = eax;  // @621_5b4160
  if ((s32)FL[0] >= (s32)FL[1]) goto L5b48bf;  // @622_5b4160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 527), &v, sizeof v); }  // @623_5b4160
  L5b48bf:;
  FL[2] = (edi & edi);  // @625_5b4160
  if (FL[2] == 0) goto L5b48e8;  // @626_5b4160
  ecx = (u32)(esi + 531);  // @627_5b4160
  { u32 v = (u32)((u32)(127)); __builtin_memcpy((void *)(u32)(esi + 535), &v, sizeof v); }  // @628_5b4160
  edi = (u32)(EBP - 12);  // @629_5b4160
  FL[0] = ecx; FL[1] = edi;  // @630_5b4160
  if (FL[0] == FL[1]) goto L5b48dc;  // @631_5b4160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @632_5b4160
  L5b48dc:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 527), &v, sizeof v); }  // @634_5b4160
  goto L5b4908;  // @635_5b4160
  L5b48e8:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @637_5b4160
  if (FL[0] == FL[1]) goto L5b4908;  // @638_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 531), sizeof v); (u32)v; });  // @639_5b4160
  ecx = (ecx + (u32)(102));  // @640_5b4160
  FL[3] = ecx;  // @641_5b4160
  FL[0] = ecx; FL[1] = eax;  // @642_5b4160
  if ((s32)FL[0] >= (s32)FL[1]) goto L5b4908;  // @643_5b4160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 535), &v, sizeof v); }  // @644_5b4160
  L5b4908:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @646_5b4160
  if (FL[0] == FL[1]) goto L5b4933;  // @647_5b4160
  ecx = (u32)(esi + 539);  // @648_5b4160
  { u32 v = (u32)((u32)(127)); __builtin_memcpy((void *)(u32)(esi + 543), &v, sizeof v); }  // @649_5b4160
  edi = (u32)(EBP - 12);  // @650_5b4160
  FL[0] = ecx; FL[1] = edi;  // @651_5b4160
  if (FL[0] == FL[1]) goto L5b4927;  // @652_5b4160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @653_5b4160
  L5b4927:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 551), &v, sizeof v); }  // @655_5b4160
  goto L5b4953;  // @656_5b4160
  L5b4933:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 543), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @658_5b4160
  if (FL[0] == FL[1]) goto L5b4953;  // @659_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 539), sizeof v); (u32)v; });  // @660_5b4160
  ecx = (ecx + (u32)(102));  // @661_5b4160
  FL[3] = ecx;  // @662_5b4160
  FL[0] = ecx; FL[1] = eax;  // @663_5b4160
  if ((s32)FL[0] >= (s32)FL[1]) goto L5b4953;  // @664_5b4160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 543), &v, sizeof v); }  // @665_5b4160
  L5b4953:;
  FL[2] = (edx & edx);  // @667_5b4160
  if (FL[2] == 0) goto L5b497c;  // @668_5b4160
  ecx = (u32)(esi + 547);  // @669_5b4160
  { u32 v = (u32)((u32)(127)); __builtin_memcpy((void *)(u32)(esi + 551), &v, sizeof v); }  // @670_5b4160
  edi = (u32)(EBP - 12);  // @671_5b4160
  FL[0] = ecx; FL[1] = edi;  // @672_5b4160
  if (FL[0] == FL[1]) goto L5b4970;  // @673_5b4160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @674_5b4160
  L5b4970:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 543), &v, sizeof v); }  // @676_5b4160
  goto L5b499c;  // @677_5b4160
  L5b497c:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 551), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @679_5b4160
  if (FL[0] == FL[1]) goto L5b499c;  // @680_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 547), sizeof v); (u32)v; });  // @681_5b4160
  ecx = (ecx + (u32)(102));  // @682_5b4160
  FL[3] = ecx;  // @683_5b4160
  FL[0] = ecx; FL[1] = eax;  // @684_5b4160
  if ((s32)FL[0] >= (s32)FL[1]) goto L5b499c;  // @685_5b4160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 551), &v, sizeof v); }  // @686_5b4160
  L5b499c:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @688_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @689_5b4160
  if (FL[0] != FL[1]) goto L5b49d4;  // @690_5b4160
  FL[2] = (eax & eax);  // @691_5b4160
  if (FL[2] != 0) goto L5b49d4;  // @692_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @693_5b4160
  FL[2] = (ecx & ecx);  // @694_5b4160
  if (FL[2] != 0) goto L5b49e8;  // @695_5b4160
  FL[2] = (edx & edx);  // @696_5b4160
  if (FL[2] != 0) goto L5b49e8;  // @697_5b4160
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 527), &v, sizeof v); }  // @698_5b4160
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 535), &v, sizeof v); }  // @699_5b4160
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 543), &v, sizeof v); }  // @700_5b4160
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 551), &v, sizeof v); }  // @701_5b4160
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 360), &v, sizeof v); }  // @702_5b4160
  goto L5b4a33;  // @703_5b4160
  L5b49d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 543), sizeof v); (u32)v; });  // @705_5b4160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 551), sizeof v); (u32)v; });  // @706_5b4160
  FL[2] = (ecx & ecx);  // @707_5b4160
  if (FL[2] != 0) goto L5b49e8;  // @708_5b4160
  FL[2] = (edx & edx);  // @709_5b4160
  if (FL[2] == 0) goto L5b49ff;  // @710_5b4160
  L5b49e8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 527), sizeof v); (u32)v; });  // @712_5b4160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @713_5b4160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 535), sizeof v); (u32)v; });  // @714_5b4160
  FL[2] = (ecx & ecx);  // @715_5b4160
  if (FL[2] != 0) goto L5b4a11;  // @716_5b4160
  FL[2] = (edx & edx);  // @717_5b4160
  if (FL[2] != 0) goto L5b4a11;  // @718_5b4160
  L5b49ff:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @720_5b4160
  if (FL[0] != FL[1]) goto L5b4a11;  // @721_5b4160
  FL[2] = (eax & eax);  // @722_5b4160
  if (FL[2] != 0) goto L5b4a11;  // @723_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 360), &v, sizeof v); }  // @724_5b4160
  goto L5b4a33;  // @725_5b4160
  L5b4a11:;
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 371), &v, sizeof v); }  // @727_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @728_5b4160
  { u8 v = (u8)((u32)(127)); __builtin_memcpy((void *)(u32)(esi + 360), &v, sizeof v); }  // @729_5b4160
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 372), &v, sizeof v); }  // @730_5b4160
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 369), &v, sizeof v); }  // @731_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 370), &v, sizeof v); }  // @732_5b4160
  L5b4a33:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 369), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @734_5b4160
  if (FL[0] != FL[1]) goto L5b4a5e;  // @735_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 370), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @736_5b4160
  if (FL[0] != FL[1]) goto L5b4a5e;  // @737_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 372), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @738_5b4160
  if (FL[0] != FL[1]) goto L5b4a5e;  // @739_5b4160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 371), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @740_5b4160
  if (FL[0] != FL[1]) goto L5b4a5e;  // @741_5b4160
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 437), &v, sizeof v); }  // @742_5b4160
  L5b4a5e:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 437), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @744_5b4160
  if (FL[0] == FL[1]) goto L5b4a71;  // @745_5b4160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 369), &v, sizeof v); }  // @746_5b4160
  L5b4a71:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 439), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @748_5b4160
  if (FL[0] == FL[1]) goto L5b4a84;  // @749_5b4160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 369), &v, sizeof v); }  // @750_5b4160
  L5b4a84:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 91), sizeof v); (u32)v; });  // @752_5b4160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 568) + 0), 4); v; });  // @753_5b4160
  X0[1] = 0;  // @754_5b4160
  X0[2] = 0;  // @755_5b4160
  X0[3] = 0;  // @756_5b4160
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @757_5b4160
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 742), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @758_5b4160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @759_5b4160
  X1[1] = 0;  // @760_5b4160
  X1[2] = 0;  // @761_5b4160
  X1[3] = 0;  // @762_5b4160
  eax = (eax & 0xffffff00u) | (((((s32)FL[0] <= (s32)FL[1]) ? 1 : 0)) & 0xff);  // @763_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @764_5b4160
  FL[3] = (eax & 0xff);  // @765_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @766_5b4160
  FL[3] = (eax & 0xff);  // @767_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 557), &v, sizeof v); }  // @768_5b4160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @769_5b4160
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @770_5b4160
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @771_5b4160
  FL[0] = eax; FL[1] = edi;  // @772_5b4160
  if ((s32)FL[0] >= (s32)FL[1]) goto L5b4afe;  // @773_5b4160
  eax = (u32)(edi + 1024);  // @774_5b4160
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @775_5b4160
  X0[0] = F2U((float)(s32)X0[0]);  // @776_5b4160
  X0[1] = F2U((float)(s32)X0[1]);  // @777_5b4160
  X0[2] = F2U((float)(s32)X0[2]);  // @778_5b4160
  X0[3] = F2U((float)(s32)X0[3]);  // @779_5b4160
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @780_5b4160
  __builtin_memcpy((void *)((u32)(esi + 568) + 0), &X0[0], 4);  // @781_5b4160
  eax = ext_597720_thiscall2(ecx, (u32)(0));  // @782_5b4160
  ecx = edx = 0;  // @783_5b4160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @784_5b4160
  X1[1] = 0;  // @785_5b4160
  X1[2] = 0;  // @786_5b4160
  X1[3] = 0;  // @787_5b4160
  FL[1] = eax;  // @788_5b4160
  eax = (0u - eax);  // @789_5b4160
  eax = (eax & 0xffffff00u) | (((0u - (u32)((FL[1] & 0xffffffffu) != 0))) & 0xff);  // @790_5b4160
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(127))) & 0xff);  // @791_5b4160
  FL[3] = (eax & 0xff);  // @792_5b4160
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 555), &v, sizeof v); }  // @793_5b4160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @794_5b4160
  L5b4afe:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 568) + 0), 4); v; });  // @796_5b4160
  X0[1] = 0;  // @797_5b4160
  X0[2] = 0;  // @798_5b4160
  X0[3] = 0;  // @799_5b4160
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @800_5b4160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @801_5b4160
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @802_5b4160
  FL[0] = eax; FL[1] = ecx;  // @803_5b4160
  if ((s32)FL[0] >= (s32)FL[1]) goto L5b4b33;  // @804_5b4160
  eax = (u32)(ecx + 1024);  // @805_5b4160
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @806_5b4160
  X0[0] = F2U((float)(s32)X0[0]);  // @807_5b4160
  X0[1] = F2U((float)(s32)X0[1]);  // @808_5b4160
  X0[2] = F2U((float)(s32)X0[2]);  // @809_5b4160
  X0[3] = F2U((float)(s32)X0[3]);  // @810_5b4160
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @811_5b4160
  __builtin_memcpy((void *)((u32)(esi + 568) + 0), &X0[0], 4);  // @812_5b4160
  L5b4b33:;
  return eax;  // @814_5b4160
}
PCREG(5b4160, lifted_5b4160);

