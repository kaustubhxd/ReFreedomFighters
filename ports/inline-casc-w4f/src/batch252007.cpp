// batch252007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" long double THISCALL ext_4dda90_thiscall3_ld(u32, u32, u32) __asm__("ext_4dda90");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 FASTCALL ext_4df1e0_fastcall2(u32, u32) __asm__("ext_4df1e0");
extern "C" u32 FASTCALL ext_4dfd10_fastcall2(u32, u32) __asm__("ext_4dfd10");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 STDCALL ext_645c90_stdcall4(u32, u32, u32, u32) __asm__("ext_645c90");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_646220_thiscall3(u32, u32, u32) __asm__("ext_646220");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
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

extern "C" u32 THISCALL lifted_646430(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
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
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 657), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @0_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @2_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @5_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @6_646430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @8_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @9_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @10_646430
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @11_646430
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @12_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @13_646430
  if (FL[0] != FL[1]) goto L646f11;  // @14_646430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 661), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @15_646430
  if (FL[0] != FL[1]) goto L646f11;  // @16_646430
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 17), sizeof v); (u32)v; }) * (s32)(u32)(29));  // @17_646430
  PV[0] = (u32)(eax);  // @18_646430
  PV[1] = (u32)(esi);  // @19_646430
  eax = ext_634d10_cdecl3(PV[1], (u32)(0), PV[0]);  // @20_646430
    // @21_646430
  PV[2] = (u32)(esi);  // @22_646430
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @23_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @24_646430
  ecx = esi;  // @25_646430
  eax = ext_646220_thiscall3(ecx, PV[3], PV[2]);  // @26_646430
  ecx = edx = 0;  // @27_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @28_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 764), sizeof v); (u32)v; });  // @30_646430
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @31_646430
  ecx = edx = 0;  // @32_646430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @33_646430
  if (FL[2] == 0) goto L646500;  // @34_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @35_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 593), &v, sizeof v); }  // @36_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 557), &v, sizeof v); }  // @37_646430
  ext_633654(G(u32, 0x6f5630));  // @38_646430
  return eax;  // @39_646430
  L646500:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @42_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 184), sizeof v); (u32)v; });  // @44_646430
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @45_646430
  ecx = edx = 0;  // @46_646430
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @47_646430
  if (FL[2] == 0) goto L646531;  // @48_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 573), sizeof v); (u32)v; });  // @49_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 557), &v, sizeof v); }  // @50_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 589), sizeof v); (u32)v; });  // @51_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 593), &v, sizeof v); }  // @52_646430
  L646531:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @54_646430
  esi = (esi + (u32)(21));  // @55_646430
  FL[3] = esi;  // @56_646430
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @57_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @58_646430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 101), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @59_646430
  if (FL[0] == FL[1]) goto L6466ec;  // @60_646430
  L646554:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) & (u32)(1));  // @62_646430
  if (FL[2] != 0) goto L6466e6;  // @63_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @64_646430
  ecx = edi;  // @65_646430
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @67_646430
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[4]);  // @68_646430
  ecx = edx = 0;  // @69_646430
  ecx = 0;  // @70_646430
  FL[3] = ecx;  // @71_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @72_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @73_646430
  FL[2] = (eax & eax);  // @74_646430
  if (FL[2] == 0) goto L64662a;  // @75_646430
  L646580:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @77_646430
  PV[5] = (u32)(ecx);  // @78_646430
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @79_646430
  ecx = edi;  // @80_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @81_646430
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[6], PV[5]);  // @82_646430
  ecx = edx = 0;  // @83_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_646430
  ecx = edi;  // @85_646430
  PV[7] = (u32)(eax);  // @86_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @87_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @88_646430
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[7]);  // @89_646430
  ecx = edx = 0;  // @90_646430
  ecx = (eax & 0xff);  // @91_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @92_646430
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; })) & 0xff);  // @93_646430
  FL[0] = (ecx & 0xff); FL[1] = (u32)(255);  // @94_646430
  if (FL[0] == FL[1]) goto L646611;  // @95_646430
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @96_646430
  if (FL[2] == 0) goto L646611;  // @97_646430
  edx = (ecx & 0xff);  // @98_646430
  ecx = (u32)((s32)edx * (s32)(u32)(29));  // @99_646430
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; }));  // @100_646430
  FL[3] = ecx;  // @101_646430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @102_646430
  if (FL[0] != FL[1]) goto L646611;  // @103_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @104_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @105_646430
  FL[2] = (eax & eax);  // @106_646430
  if (FL[2] == 0) goto L6465e9;  // @107_646430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @108_646430
  eax = (u32)(edx*8);  // @109_646430
  eax = (eax - edx);  // @110_646430
  FL[3] = eax;  // @111_646430
  eax = (u32)(edi + eax*4);  // @112_646430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @113_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @114_646430
  L6465e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @116_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @117_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @118_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @119_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @120_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @121_646430
  ecx = (u32)(edx + edx*2);  // @122_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @123_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @124_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx*8 + 16), &v, sizeof v); }  // @125_646430
  L646611:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @127_646430
  ecx = (ecx + 1);  // @128_646430
  FL[3] = ecx;  // @129_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @130_646430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @131_646430
  if (FL[0] != FL[1]) goto L646580;  // @132_646430
  L64662a:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) & (u32)(4));  // @134_646430
  if (FL[2] == 0) goto L6466c7;  // @135_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @136_646430
  esi = (esi + (u32)(20));  // @137_646430
  FL[3] = esi;  // @138_646430
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @139_646430
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @140_646430
  ecx = edi;  // @141_646430
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @143_646430
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[8]);  // @144_646430
  ecx = edx = 0;  // @145_646430
  ecx = 0;  // @146_646430
  FL[3] = ecx;  // @147_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @148_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @149_646430
  FL[2] = (eax & eax);  // @150_646430
  if (FL[2] == 0) goto L6466c7;  // @151_646430
  L646660:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @153_646430
  PV[9] = (u32)(ecx);  // @154_646430
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @155_646430
  ecx = edi;  // @156_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @157_646430
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[10], PV[9]);  // @158_646430
  ecx = edx = 0;  // @159_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @160_646430
  ecx = edi;  // @161_646430
  PV[11] = (u32)(eax);  // @162_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @163_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @164_646430
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[11]);  // @165_646430
  ecx = edx = 0;  // @166_646430
  ecx = (eax & 0xff);  // @167_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @168_646430
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; })) & 0xff);  // @169_646430
  FL[0] = (ecx & 0xff); FL[1] = (u32)(255);  // @170_646430
  if (FL[0] == FL[1]) goto L6466b2;  // @171_646430
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @172_646430
  if (FL[2] == 0) goto L6466b2;  // @173_646430
  eax = (ecx & 0xff);  // @174_646430
  ecx = (u32)((s32)eax * (s32)(u32)(29));  // @175_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @176_646430
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; }));  // @177_646430
  FL[3] = ecx;  // @178_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @179_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @180_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @181_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @182_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @183_646430
  L6466b2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @185_646430
  ecx = (ecx + 1);  // @186_646430
  FL[3] = ecx;  // @187_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @188_646430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @189_646430
  if (FL[0] != FL[1]) goto L646660;  // @190_646430
  L6466c7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @192_646430
  esi = (esi + (u32)(20));  // @193_646430
  FL[3] = esi;  // @194_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @195_646430
  ecx = (ecx + 1);  // @196_646430
  FL[3] = ecx;  // @197_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @198_646430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 101), sizeof v); (u32)v; });  // @199_646430
  if (FL[0] != FL[1]) goto L646554;  // @200_646430
  L6466e6:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @202_646430
  L6466ec:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 593) + 0), 4); v; });  // @204_646430
  X0[1] = 0;  // @205_646430
  X0[2] = 0;  // @206_646430
  X0[3] = 0;  // @207_646430
  X1[0] = 0;  // @208_646430
  X1[1] = 0;  // @209_646430
  X1[2] = 0;  // @210_646430
  X1[3] = 0;  // @211_646430
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @212_646430
  __builtin_memcpy((void *)((u32)(EBP - 148) + 0), &X1[0], 4);  // @213_646430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @214_646430
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @215_646430
  if (__builtin_parity(FL[2] & 0xff)) goto L646e25;  // @216_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @217_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @218_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1176), sizeof v); (u32)v; });  // @219_646430
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @220_646430
  ecx = edx = 0;  // @221_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @222_646430
  FL[2] = (eax & eax);  // @223_646430
  if (FL[2] == 0) goto L646e25;  // @224_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @225_646430
  ecx = esi;  // @226_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @227_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1180), sizeof v); (u32)v; });  // @228_646430
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @229_646430
  ecx = edx = 0;  // @230_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @231_646430
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @232_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 108), sizeof v); (u32)v; });  // @233_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @234_646430
  PV[12] = (u32)(edx);  // @235_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @236_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @237_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @238_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 192), sizeof v); (u32)v; });  // @239_646430
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[12]);  // @240_646430
  ecx = edx = 0;  // @241_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @242_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @243_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 108), sizeof v); (u32)v; });  // @244_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @245_646430
  PV[13] = (u32)(esi);  // @246_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @247_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @248_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @249_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 200), sizeof v); (u32)v; });  // @250_646430
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[13]);  // @251_646430
  ecx = edx = 0;  // @252_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @253_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @254_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @255_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 108), sizeof v); (u32)v; });  // @256_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @257_646430
  PV[14] = (u32)(esi);  // @258_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @259_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @260_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @261_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 184), sizeof v); (u32)v; });  // @262_646430
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[14]);  // @263_646430
  ecx = edx = 0;  // @264_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @265_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @266_646430
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 124), sizeof v); (u32)v; }) & (u32)(16));  // @267_646430
  if (FL[2] == 0) goto L6469a3;  // @268_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; });  // @269_646430
  eax = (u32)(EBP - 136);  // @270_646430
  ecx = (u32)(esi + 29);  // @271_646430
  PV[15] = (u32)(ecx);  // @272_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @273_646430
  PV[16] = (u32)(edi);  // @274_646430
  ecx = (ecx + (u32)(36));  // @275_646430
  FL[3] = ecx;  // @276_646430
  PV[17] = (u32)(ecx);  // @277_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @278_646430
  PV[18] = (u32)(eax);  // @279_646430
  eax = ext_645c90_stdcall4(PV[18], PV[17], PV[16], PV[15]);  // @280_646430
  ecx = edx = 0;  // @281_646430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 153), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @282_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 100) + 0), 4); v; });  // @283_646430
  X0[1] = 0;  // @284_646430
  X0[2] = 0;  // @285_646430
  X0[3] = 0;  // @286_646430
  __builtin_memcpy((void *)((u32)(EBP - 212) + 0), &X0[0], 4);  // @287_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 96) + 0), 4); v; });  // @288_646430
  X0[1] = 0;  // @289_646430
  X0[2] = 0;  // @290_646430
  X0[3] = 0;  // @291_646430
  __builtin_memcpy((void *)((u32)(EBP - 208) + 0), &X0[0], 4);  // @292_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @293_646430
  X0[1] = 0;  // @294_646430
  X0[2] = 0;  // @295_646430
  X0[3] = 0;  // @296_646430
  __builtin_memcpy((void *)((u32)(EBP - 204) + 0), &X0[0], 4);  // @297_646430
  if (FL[0] == FL[1]) goto L64687b;  // @298_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @299_646430
  eax = ext_4de7a0_thiscall1(ecx);  // @300_646430
    // @301_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @302_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 44), &v, sizeof v); }  // @303_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 40), &v, sizeof v); }  // @304_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 36), &v, sizeof v); }  // @305_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @306_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 28) + 0), 4); v; });  // @307_646430
  X0[1] = 0;  // @308_646430
  X0[2] = 0;  // @309_646430
  X0[3] = 0;  // @310_646430
  __builtin_memcpy((void *)((u32)(EBP - 136) + 0), &X0[0], 4);  // @311_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 0), 4); v; });  // @312_646430
  X0[1] = 0;  // @313_646430
  X0[2] = 0;  // @314_646430
  X0[3] = 0;  // @315_646430
  __builtin_memcpy((void *)((u32)(EBP - 132) + 0), &X0[0], 4);  // @316_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 36) + 0), 4); v; });  // @317_646430
  X0[1] = 0;  // @318_646430
  X0[2] = 0;  // @319_646430
  X0[3] = 0;  // @320_646430
  __builtin_memcpy((void *)((u32)(EBP - 128) + 0), &X0[0], 4);  // @321_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 40) + 0), 4); v; });  // @322_646430
  X0[1] = 0;  // @323_646430
  X0[2] = 0;  // @324_646430
  X0[3] = 0;  // @325_646430
  __builtin_memcpy((void *)((u32)(EBP - 124) + 0), &X0[0], 4);  // @326_646430
  L64687b:;
  edx = (u32)(EBP - 136);  // @328_646430
  ecx = (u32)(EBP - 52);  // @329_646430
  eax = ext_4df1e0_fastcall2(ecx, edx);  // @330_646430
    // @331_646430
  edx = (u32)(EBP - 52);  // @332_646430
  ecx = (u32)(EBP - 88);  // @333_646430
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @334_646430
    // @335_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @336_646430
  ecx = (u32)(EBP - 88);  // @337_646430
  edx = (u32)(edx + 36);  // @338_646430
  eax = ext_4de480_fastcall2(ecx, edx);  // @339_646430
  ecx = edx = 0;  // @340_646430
  edx = (u32)(EBP - 88);  // @341_646430
  ecx = (u32)(EBP - 52);  // @342_646430
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @343_646430
    // @344_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @345_646430
  ecx = (u32)(EBP - 52);  // @346_646430
  eax = ext_4de480_fastcall2(ecx, edx);  // @347_646430
  ecx = edx = 0;  // @348_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @349_646430
  ecx = (u32)(EBP - 212);  // @350_646430
  eax = ext_4419f0_fastcall2(ecx, edx);  // @351_646430
  ecx = edx = 0;  // @352_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @353_646430
  ecx = (u32)(EBP - 212);  // @354_646430
  edx = (u32)(edx + 36);  // @355_646430
  eax = ext_441940_fastcall2(ecx, edx);  // @356_646430
  ecx = edx = 0;  // @357_646430
  PV[19] = (u32)(ecx);  // @358_646430
  edx = (u32)(EBP - 52);  // @359_646430
  ecx = (u32)(EBP - 16);  // @360_646430
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1113325568));  // @361_646430
    // @362_646430
  edx = (u32)(EBP - 16);  // @363_646430
  ecx = (u32)(EBP - 212);  // @364_646430
  eax = ext_441940_fastcall2(ecx, edx);  // @365_646430
  ecx = edx = 0;  // @366_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @367_646430
  eax = (u32)(EBP - 212);  // @368_646430
  PV[20] = (u32)(eax);  // @369_646430
  ecx = (u32)(EBP - 16);  // @370_646430
  edx = (u32)(edx + 601);  // @371_646430
  eax = ext_43e920_fastcall3(ecx, edx, PV[20]);  // @372_646430
  ecx = edx = 0;  // @373_646430
  ecx = (u32)(EBP - 16);  // @374_646430
  eax = ext_44c840_thiscall1(ecx);  // @375_646430
  ecx = 0;  // @376_646430
  edx = (u32)(EBP - 52);  // @377_646430
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @378_646430
  ecx = (u32)(EBP - 16);  // @379_646430
  eax = ext_441a60_fastcall2(ecx, edx);  // @380_646430
  ecx = edx = 0;  // @381_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @382_646430
  X0[1] = 0;  // @383_646430
  X0[2] = 0;  // @384_646430
  X0[3] = 0;  // @385_646430
  PV[21] = X0[0];  // @386_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @387_646430
  X0[1] = 0;  // @388_646430
  X0[2] = 0;  // @389_646430
  X0[3] = 0;  // @390_646430
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @391_646430
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @392_646430
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @393_646430
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @394_646430
  PV[22] = X0[0];  // @395_646430
  FS[0] = ext_4dda90_thiscall3_ld(ecx, PV[22], PV[21]);  // @396_646430
  ecx = edx = 0;  // @397_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @398_646430
  X0[1] = 0;  // @399_646430
  X0[2] = 0;  // @400_646430
  X0[3] = 0;  // @401_646430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @402_646430
  X1[1] = 0;  // @403_646430
  X1[2] = 0;  // @404_646430
  X1[3] = 0;  // @405_646430
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @406_646430
  STF((u32)(EBP - 140), FS[0]);  // @407_646430
  __builtin_memcpy((void *)((u32)(EBP - 144) + 0), &X0[0], 4);  // @408_646430
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L646a76;  // @409_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @410_646430
  X0[1] = 0;  // @411_646430
  X0[2] = 0;  // @412_646430
  X0[3] = 0;  // @413_646430
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @414_646430
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L646996;  // @415_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @416_646430
  X0[1] = 0;  // @417_646430
  X0[2] = 0;  // @418_646430
  X0[3] = 0;  // @419_646430
  goto L646a6e;  // @420_646430
  L646996:;
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @422_646430
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @423_646430
  ecx = edx = 0;  // @424_646430
  goto L646a6a;  // @425_646430
  L6469a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @427_646430
  ecx = (u32)(EBP - 16);  // @428_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 609) + 0), 4); v; });  // @429_646430
  X0[1] = 0;  // @430_646430
  X0[2] = 0;  // @431_646430
  X0[3] = 0;  // @432_646430
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @433_646430
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @434_646430
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @435_646430
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @436_646430
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @437_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 601) + 0), 4); v; });  // @438_646430
  X0[1] = 0;  // @439_646430
  X0[2] = 0;  // @440_646430
  X0[3] = 0;  // @441_646430
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @442_646430
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @443_646430
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @444_646430
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @445_646430
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @446_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 605) + 0), 4); v; });  // @447_646430
  X0[1] = 0;  // @448_646430
  X0[2] = 0;  // @449_646430
  X0[3] = 0;  // @450_646430
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7088832) + 0), 4); v; })));  // @451_646430
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @452_646430
  eax = ext_44c840_thiscall1(ecx);  // @453_646430
  ecx = 0;  // @454_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @455_646430
  X0[1] = 0;  // @456_646430
  X0[2] = 0;  // @457_646430
  X0[3] = 0;  // @458_646430
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @459_646430
  PV[23] = X0[0];  // @460_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @461_646430
  X0[1] = 0;  // @462_646430
  X0[2] = 0;  // @463_646430
  X0[3] = 0;  // @464_646430
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @465_646430
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @466_646430
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @467_646430
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @468_646430
  PV[24] = X0[0];  // @469_646430
  FS[0] = ext_4dda90_thiscall3_ld(ecx, PV[24], PV[23]);  // @470_646430
  ecx = edx = 0;  // @471_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @472_646430
  X0[1] = 0;  // @473_646430
  X0[2] = 0;  // @474_646430
  X0[3] = 0;  // @475_646430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @476_646430
  X1[1] = 0;  // @477_646430
  X1[2] = 0;  // @478_646430
  X1[3] = 0;  // @479_646430
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @480_646430
  STF((u32)(EBP - 140), FS[0]);  // @481_646430
  __builtin_memcpy((void *)((u32)(EBP - 144) + 0), &X0[0], 4);  // @482_646430
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L646a3f;  // @483_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; });  // @484_646430
  X0[0] = 0;  // @485_646430
  X0[1] = 0;  // @486_646430
  X0[2] = 0;  // @487_646430
  X0[3] = 0;  // @488_646430
  goto L646a6e;  // @489_646430
  L646a3f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @491_646430
  X0[1] = 0;  // @492_646430
  X0[2] = 0;  // @493_646430
  X0[3] = 0;  // @494_646430
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @495_646430
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L646a5c;  // @496_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @497_646430
  X0[1] = 0;  // @498_646430
  X0[2] = 0;  // @499_646430
  X0[3] = 0;  // @500_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; });  // @501_646430
  goto L646a6e;  // @502_646430
  L646a5c:;
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @504_646430
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @505_646430
  ecx = edx = 0;  // @506_646430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; });  // @507_646430
  L646a6a:;
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @509_646430
  L646a6e:;
  __builtin_memcpy((void *)((u32)(EBP - 148) + 0), &X0[0], 4);  // @511_646430
  L646a76:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @513_646430
  X0[1] = 0;  // @514_646430
  X0[2] = 0;  // @515_646430
  X0[3] = 0;  // @516_646430
  ecx = edi;  // @517_646430
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; })));  // @518_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @519_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @520_646430
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @521_646430
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6823372) + 0), 4); v; })));  // @522_646430
  __builtin_memcpy((void *)((u32)(EBP - 164) + 0), &X0[0], 4);  // @523_646430
  __builtin_memcpy((void *)((u32)(EBP - 176) + 0), &X0[0], 4);  // @524_646430
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[25]);  // @525_646430
  ecx = edx = 0;  // @526_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @527_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @528_646430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 613), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @529_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 597) + 0), 4); v; });  // @530_646430
  X0[1] = 0;  // @531_646430
  X0[2] = 0;  // @532_646430
  X0[3] = 0;  // @533_646430
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @534_646430
  if (FL[0] == FL[1]) goto L646ae2;  // @535_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; });  // @536_646430
  X0[1] = 0;  // @537_646430
  X0[2] = 0;  // @538_646430
  X0[3] = 0;  // @539_646430
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @540_646430
  L646ae2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @542_646430
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @543_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @544_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 648), sizeof v); (u32)v; });  // @545_646430
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[26]);  // @546_646430
  ecx = edx = 0;  // @547_646430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 153), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @548_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @549_646430
  if (FL[0] == FL[1]) goto L646bf1;  // @550_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 148) + 0), 4); v; });  // @551_646430
  X0[1] = 0;  // @552_646430
  X0[2] = 0;  // @553_646430
  X0[3] = 0;  // @554_646430
  ecx = 0;  // @555_646430
  FL[3] = ecx;  // @556_646430
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7088824) + 0), 4); v; })));  // @557_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @558_646430
  __builtin_memcpy((void *)((u32)(EBP - 148) + 0), &X0[0], 4);  // @559_646430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; }); FL[1] = ecx;  // @560_646430
  if (FL[0] == FL[1]) goto L646e1f;  // @561_646430
  L646b37:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @563_646430
  PV[27] = (u32)(ecx);  // @564_646430
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @565_646430
  ecx = edi;  // @566_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @567_646430
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[28], PV[27]);  // @568_646430
  ecx = edx = 0;  // @569_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @570_646430
  ecx = edi;  // @571_646430
  PV[29] = (u32)(eax);  // @572_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @573_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @574_646430
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[29]);  // @575_646430
  ecx = edx = 0;  // @576_646430
  ecx = (eax & 0xff);  // @577_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @578_646430
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; })) & 0xff);  // @579_646430
  FL[0] = (ecx & 0xff); FL[1] = (u32)(255);  // @580_646430
  if (FL[0] == FL[1]) goto L646bd3;  // @581_646430
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @582_646430
  if (FL[2] == 0) goto L646bd3;  // @583_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @584_646430
  edx = (ecx & 0xff);  // @585_646430
  ecx = (u32)((s32)edx * (s32)(u32)(29));  // @586_646430
  ecx = (ecx + esi);  // @587_646430
  FL[3] = ecx;  // @588_646430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 613), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @589_646430
  if (FL[0] != FL[1]) goto L646bc6;  // @590_646430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @591_646430
  if (FL[0] == FL[1]) goto L646ba3;  // @592_646430
  eax = (u32)(edx*8);  // @593_646430
  eax = (eax - edx);  // @594_646430
  FL[3] = eax;  // @595_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @596_646430
  eax = (u32)(edx + eax*4);  // @597_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @598_646430
  goto L646baa;  // @599_646430
  L646ba3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @601_646430
  L646baa:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 148) + 0), 4); v; });  // @603_646430
  X0[1] = 0;  // @604_646430
  X0[2] = 0;  // @605_646430
  X0[3] = 0;  // @606_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @607_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @608_646430
  __builtin_memcpy((void *)((u32)(ecx + 4) + 0), &X0[0], 4);  // @609_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @610_646430
  L646bc6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @612_646430
  X0[1] = 0;  // @613_646430
  X0[2] = 0;  // @614_646430
  X0[3] = 0;  // @615_646430
  __builtin_memcpy((void *)((u32)(ecx + 8) + 0), &X0[0], 4);  // @616_646430
  L646bd3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @618_646430
  ecx = (ecx + 1);  // @619_646430
  FL[3] = ecx;  // @620_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @621_646430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @622_646430
  if (FL[0] != FL[1]) goto L646b37;  // @623_646430
  goto L646e1f;  // @624_646430
  L646bf1:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7088820) + 0), 4); v; });  // @626_646430
  X3[1] = 0;  // @627_646430
  X3[2] = 0;  // @628_646430
  X3[3] = 0;  // @629_646430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 148) + 0), 4); v; });  // @630_646430
  X1[1] = 0;  // @631_646430
  X1[2] = 0;  // @632_646430
  X1[3] = 0;  // @633_646430
  FA = U2F(X1[0]); FB = U2F(X3[0]);  // @634_646430
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7088816) + 0), 4); v; });  // @635_646430
  X4[1] = 0;  // @636_646430
  X4[2] = 0;  // @637_646430
  X4[3] = 0;  // @638_646430
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L646c16;  // @639_646430
  X0[0] = X3[0];  // @640_646430
  X0[1] = X3[1];  // @641_646430
  X0[2] = X3[2];  // @642_646430
  X0[3] = X3[3];  // @643_646430
  goto L646ca8;  // @644_646430
  L646c16:;
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6945236) + 0), 4); v; });  // @646_646430
  X5[1] = 0;  // @647_646430
  X5[2] = 0;  // @648_646430
  X5[3] = 0;  // @649_646430
  X0[0] = X5[0];  // @650_646430
  X0[1] = X5[1];  // @651_646430
  X0[2] = X5[2];  // @652_646430
  X0[3] = X5[3];  // @653_646430
  { float a_ = U2F(X0[0]), b_ = U2F(X1[0]); X0[0] = (a_ > b_) ? X0[0] : F2U(b_); }  // @654_646430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829936) + 0), 4); v; });  // @655_646430
  X1[1] = 0;  // @656_646430
  X1[2] = 0;  // @657_646430
  X1[3] = 0;  // @658_646430
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @659_646430
  if ((!(FA >= FB))) goto L646c64;  // @660_646430
  FA = U2F(X4[0]); FB = U2F(X0[0]);  // @661_646430
  if ((!(FA >= FB))) goto L646c64;  // @662_646430
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @663_646430
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @664_646430
  X2[1] = 0;  // @665_646430
  X2[2] = 0;  // @666_646430
  X2[3] = 0;  // @667_646430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @668_646430
  X1[1] = 0;  // @669_646430
  X1[2] = 0;  // @670_646430
  X1[3] = 0;  // @671_646430
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6971560) + 0), 4); v; })));  // @672_646430
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6943136) + 0), 4); v; })));  // @673_646430
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @674_646430
  goto L646d2b;  // @675_646430
  L646c64:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6943136) + 0), 4); v; });  // @677_646430
  X2[1] = 0;  // @678_646430
  X2[2] = 0;  // @679_646430
  X2[3] = 0;  // @680_646430
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @681_646430
  if ((!(FA >= FB))) goto L646c9e;  // @682_646430
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @683_646430
  if ((!(FA >= FB))) goto L646c9e;  // @684_646430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @685_646430
  X1[1] = 0;  // @686_646430
  X1[2] = 0;  // @687_646430
  X1[3] = 0;  // @688_646430
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000596) + 0), 4); v; })));  // @689_646430
  __builtin_memcpy((void *)((u32)(EBP - 176) + 0), &X1[0], 4);  // @690_646430
  X1[0] = X0[0];  // @691_646430
  X1[1] = X0[1];  // @692_646430
  X1[2] = X0[2];  // @693_646430
  X1[3] = X0[3];  // @694_646430
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @695_646430
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @696_646430
  goto L646d33;  // @697_646430
  L646c9e:;
  FA = U2F(X0[0]); FB = U2F(X4[0]);  // @699_646430
  if ((!(FA >= FB))) goto L646cea;  // @700_646430
  FA = U2F(X3[0]); FB = U2F(X0[0]);  // @701_646430
  if ((!(FA >= FB))) goto L646cea;  // @702_646430
  L646ca8:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @704_646430
  X2[1] = 0;  // @705_646430
  X2[2] = 0;  // @706_646430
  X2[3] = 0;  // @707_646430
  X0[0] = F2U(U2F(X0[0]) - U2F(X4[0]));  // @708_646430
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6971560) + 0), 4); v; })));  // @709_646430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @710_646430
  X1[1] = 0;  // @711_646430
  X1[2] = 0;  // @712_646430
  X1[3] = 0;  // @713_646430
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6949832) + 0), 4); v; })));  // @714_646430
  __builtin_memcpy((void *)((u32)(EBP - 164) + 0), &X2[0], 4);  // @715_646430
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 176) + 0), 4); v; });  // @716_646430
  X2[1] = 0;  // @717_646430
  X2[2] = 0;  // @718_646430
  X2[3] = 0;  // @719_646430
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @720_646430
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7088840) + 0), 4); v; })));  // @721_646430
  goto L646d2b;  // @722_646430
  L646cea:;
  FA = U2F(X0[0]); FB = U2F(X5[0]);  // @724_646430
  if ((!(FA >= FB))) goto L646d3b;  // @725_646430
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @726_646430
  if ((!(FA >= FB))) goto L646d3b;  // @727_646430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @728_646430
  X1[1] = 0;  // @729_646430
  X1[2] = 0;  // @730_646430
  X1[3] = 0;  // @731_646430
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000596) + 0), 4); v; })));  // @732_646430
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 176) + 0), 4); v; });  // @733_646430
  X2[1] = 0;  // @734_646430
  X2[2] = 0;  // @735_646430
  X2[3] = 0;  // @736_646430
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7088836) + 0), 4); v; })));  // @737_646430
  __builtin_memcpy((void *)((u32)(EBP - 164) + 0), &X1[0], 4);  // @738_646430
  X1[0] = X0[0];  // @739_646430
  X1[1] = X0[1];  // @740_646430
  X1[2] = X0[2];  // @741_646430
  X1[3] = X0[3];  // @742_646430
  X1[0] = F2U(U2F(X1[0]) - U2F(X5[0]));  // @743_646430
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6949832) + 0), 4); v; })));  // @744_646430
  L646d2b:;
  __builtin_memcpy((void *)((u32)(EBP - 176) + 0), &X2[0], 4);  // @746_646430
  L646d33:;
  __builtin_memcpy((void *)((u32)(EBP - 144) + 0), &X1[0], 4);  // @748_646430
  L646d3b:;
  ecx = 0;  // @750_646430
  FL[3] = ecx;  // @751_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @752_646430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; }); FL[1] = ecx;  // @753_646430
  if (FL[0] == FL[1]) goto L646e1f;  // @754_646430
  L646d50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @756_646430
  PV[30] = (u32)(ecx);  // @757_646430
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @758_646430
  ecx = edi;  // @759_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @760_646430
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[31], PV[30]);  // @761_646430
  ecx = edx = 0;  // @762_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @763_646430
  ecx = edi;  // @764_646430
  PV[32] = (u32)(eax);  // @765_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @766_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @767_646430
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[32]);  // @768_646430
  ecx = edx = 0;  // @769_646430
  ecx = (eax & 0xff);  // @770_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @771_646430
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; })) & 0xff);  // @772_646430
  FL[0] = (ecx & 0xff); FL[1] = (u32)(255);  // @773_646430
  if (FL[0] == FL[1]) goto L646e06;  // @774_646430
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @775_646430
  if (FL[2] == 0) goto L646e06;  // @776_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @777_646430
  edx = (ecx & 0xff);  // @778_646430
  ecx = (u32)((s32)edx * (s32)(u32)(29));  // @779_646430
  ecx = (ecx + esi);  // @780_646430
  FL[3] = ecx;  // @781_646430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 613), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @782_646430
  if (FL[0] != FL[1]) goto L646df9;  // @783_646430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @784_646430
  if (FL[0] == FL[1]) goto L646dc0;  // @785_646430
  eax = (u32)(edx*8);  // @786_646430
  eax = (eax - edx);  // @787_646430
  FL[3] = eax;  // @788_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @789_646430
  eax = (u32)(edx + eax*4);  // @790_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @791_646430
  goto L646dc7;  // @792_646430
  L646dc0:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @794_646430
  L646dc7:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 176) + 0), 4); v; });  // @796_646430
  X0[1] = 0;  // @797_646430
  X0[2] = 0;  // @798_646430
  X0[3] = 0;  // @799_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @800_646430
  __builtin_memcpy((void *)((u32)(ecx + 4) + 0), &X0[0], 4);  // @801_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @802_646430
  X0[1] = 0;  // @803_646430
  X0[2] = 0;  // @804_646430
  X0[3] = 0;  // @805_646430
  __builtin_memcpy((void *)((u32)(ecx + 20) + 0), &X0[0], 4);  // @806_646430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 144) + 0), 4); v; });  // @807_646430
  X0[1] = 0;  // @808_646430
  X0[2] = 0;  // @809_646430
  X0[3] = 0;  // @810_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @811_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @812_646430
  __builtin_memcpy((void *)((u32)(ecx + 16) + 0), &X0[0], 4);  // @813_646430
  L646df9:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @815_646430
  X0[1] = 0;  // @816_646430
  X0[2] = 0;  // @817_646430
  X0[3] = 0;  // @818_646430
  __builtin_memcpy((void *)((u32)(ecx + 8) + 0), &X0[0], 4);  // @819_646430
  L646e06:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @821_646430
  ecx = (ecx + 1);  // @822_646430
  FL[3] = ecx;  // @823_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @824_646430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @825_646430
  if (FL[0] != FL[1]) goto L646d50;  // @826_646430
  L646e1f:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @828_646430
  L646e25:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @830_646430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @831_646430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 101), sizeof v); (u32)v; });  // @832_646430
  if (FL[0] == FL[1]) goto L646f11;  // @833_646430
  esi = (esi + (u32)(4));  // @834_646430
  FL[3] = esi;  // @835_646430
  L646e40:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @837_646430
  ecx = edi;  // @838_646430
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @839_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @840_646430
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[33]);  // @841_646430
  ecx = edx = 0;  // @842_646430
  ecx = 0;  // @843_646430
  FL[3] = ecx;  // @844_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @845_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @846_646430
  FL[2] = (eax & eax);  // @847_646430
  if (FL[2] == 0) goto L646ef2;  // @848_646430
  L646e62:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @850_646430
  PV[34] = (u32)(ecx);  // @851_646430
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @852_646430
  ecx = edi;  // @853_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @854_646430
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[35], PV[34]);  // @855_646430
  ecx = edx = 0;  // @856_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @857_646430
  ecx = edi;  // @858_646430
  PV[36] = (u32)(eax);  // @859_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @860_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @861_646430
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[36]);  // @862_646430
  ecx = edx = 0;  // @863_646430
  ecx = (eax & 0xff);  // @864_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @865_646430
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; })) & 0xff);  // @866_646430
  FL[0] = (ecx & 0xff); FL[1] = (u32)(255);  // @867_646430
  if (FL[0] == FL[1]) goto L646ed9;  // @868_646430
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @869_646430
  if (FL[2] == 0) goto L646ed9;  // @870_646430
  edx = (ecx & 0xff);  // @871_646430
  ecx = (u32)((s32)edx * (s32)(u32)(29));  // @872_646430
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 180), sizeof v); (u32)v; }));  // @873_646430
  FL[3] = ecx;  // @874_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @875_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @876_646430
  FL[2] = (eax & eax);  // @877_646430
  if (FL[2] == 0) goto L646ebe;  // @878_646430
  eax = (u32)(edx*8);  // @879_646430
  eax = (eax - edx);  // @880_646430
  FL[3] = eax;  // @881_646430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @882_646430
  eax = (u32)(edx + eax*4);  // @883_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @884_646430
  L646ebe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @886_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @887_646430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @888_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @889_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @890_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @891_646430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @892_646430
  L646ed9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @894_646430
  ecx = (ecx + 1);  // @895_646430
  FL[3] = ecx;  // @896_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @897_646430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @898_646430
  if (FL[0] != FL[1]) goto L646e62;  // @899_646430
  L646ef2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 184), sizeof v); (u32)v; });  // @901_646430
  esi = (esi + (u32)(20));  // @902_646430
  FL[3] = esi;  // @903_646430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @904_646430
  ecx = (ecx + 1);  // @905_646430
  FL[3] = ecx;  // @906_646430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @907_646430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 101), sizeof v); (u32)v; });  // @908_646430
  if (FL[0] != FL[1]) goto L646e40;  // @909_646430
  L646f11:;
  ext_633654(G(u32, 0x6f5630));  // @911_646430
  return eax;  // @912_646430
}
PCREG(646430, lifted_646430);

