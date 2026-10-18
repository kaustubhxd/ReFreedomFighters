// batch252012.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" long double FASTCALL ext_44e630_fastcall2_ld(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_54f2b0_fastcall2(u32, u32) __asm__("ext_54f2b0");
extern "C" u32 STDCALL ext_54a0e0_stdcall2(u32, u32) __asm__("ext_54a0e0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_610f20_thiscall2(u32, u32) __asm__("ext_610f20");
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

extern "C" u32 THISCALL lifted_54c4b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_54c4b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_54c4b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @2_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @3_54c4b0
  eax = (eax + (u32)(32873));  // @4_54c4b0
  FL[3] = eax;  // @5_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @6_54c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_54c4b0
  FL[2] = (ecx & ecx);  // @8_54c4b0
  if (FL[2] == 0) goto L54c643;  // @9_54c4b0
  ebx = 0;  // @10_54c4b0
  FL[3] = ebx;  // @11_54c4b0
  FL[2] = (ecx & ecx);  // @12_54c4b0
  if ((s32)FL[2] <= 0) goto L54c636;  // @13_54c4b0
  edi = (u32)(eax + 16);  // @14_54c4b0
  L54c4f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @16_54c4b0
  eax = (eax - (u32)(2));  // @17_54c4b0
  FL[3] = eax;  // @18_54c4b0
  if (FL[3] == 0) goto L54c606;  // @19_54c4b0
  eax = (eax - (u32)(1));  // @20_54c4b0
  FL[3] = eax;  // @21_54c4b0
  if (FL[3] == 0) goto L54c520;  // @22_54c4b0
  eax = (eax - (u32)(2));  // @23_54c4b0
  FL[3] = eax;  // @24_54c4b0
  if (FL[3] != 0) goto L54c623;  // @25_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @26_54c4b0
  FL[2] = (eax & eax);  // @27_54c4b0
  if (FL[2] == 0) goto L54c51a;  // @28_54c4b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @29_54c4b0
  ecx = edx = 0;  // @30_54c4b0
  goto L54c623;  // @31_54c4b0
  L54c51a:;
  __builtin_trap();  // @33_54c4b0
  L54c520:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @35_54c4b0
  FL[2] = (eax & eax);  // @36_54c4b0
  if (FL[2] == 0) goto L54c606;  // @37_54c4b0
  { u32 v = (u32)((u32)(17)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @38_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @39_54c4b0
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @40_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @41_54c4b0
  { u32 v = (u32)((u32)(1049247089)); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @42_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @43_54c4b0
  { u32 v = (u32)((u32)(4294966296)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @44_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @45_54c4b0
  { u32 v = (u32)((u32)(4294964796)); __builtin_memcpy((void *)(u32)(eax + 32), &v, sizeof v); }  // @46_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @47_54c4b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 36), &v, sizeof v); }  // @48_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @49_54c4b0
  { u32 v = (u32)((u32)(1062836634)); __builtin_memcpy((void *)(u32)(eax + 40), &v, sizeof v); }  // @50_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @51_54c4b0
  { u32 v = (u32)((u32)(1045891645)); __builtin_memcpy((void *)(u32)(eax + 44), &v, sizeof v); }  // @52_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @53_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @54_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @55_54c4b0
  { u32 v = (u32)((u32)(4294964516)); __builtin_memcpy((void *)(u32)(eax + 52), &v, sizeof v); }  // @56_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @57_54c4b0
  { u32 v = (u32)((u32)(1050253722)); __builtin_memcpy((void *)(u32)(eax + 56), &v, sizeof v); }  // @58_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @59_54c4b0
  { u32 v = (u32)((u32)(4294965862)); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @60_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @61_54c4b0
  { u32 v = (u32)((u32)(1036831949)); __builtin_memcpy((void *)(u32)(eax + 76), &v, sizeof v); }  // @62_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @63_54c4b0
  { u32 v = (u32)((u32)(1048576000)); __builtin_memcpy((void *)(u32)(eax + 92), &v, sizeof v); }  // @64_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @65_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 96), &v, sizeof v); }  // @66_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @67_54c4b0
  { u32 v = (u32)((u32)(1048576000)); __builtin_memcpy((void *)(u32)(eax + 100), &v, sizeof v); }  // @68_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @69_54c4b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 104), &v, sizeof v); }  // @70_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @71_54c4b0
  { u32 v = (u32)((u32)(3231711232)); __builtin_memcpy((void *)(u32)(eax + 108), &v, sizeof v); }  // @72_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @73_54c4b0
  { u32 v = (u32)((u32)(1167867904)); __builtin_memcpy((void *)(u32)(eax + 112), &v, sizeof v); }  // @74_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @75_54c4b0
  { u32 v = (u32)((u32)(1132068864)); __builtin_memcpy((void *)(u32)(eax + 116), &v, sizeof v); }  // @76_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @77_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 120), &v, sizeof v); }  // @78_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @79_54c4b0
  { u32 v = (u32)((u32)(31)); __builtin_memcpy((void *)(u32)(eax + 124), &v, sizeof v); }  // @80_54c4b0
  goto L54c623;  // @81_54c4b0
  L54c606:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @83_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_54c4b0
  FL[2] = (ecx & ecx);  // @85_54c4b0
  if (FL[2] == 0) goto L54c623;  // @86_54c4b0
  FL[2] = (eax & eax);  // @87_54c4b0
  if (FL[2] == 0) goto L54c623;  // @88_54c4b0
  eax = (eax + (u32)(12));  // @89_54c4b0
  FL[3] = eax;  // @90_54c4b0
  PV[0] = (u32)(eax);  // @91_54c4b0
  eax = (u32)(ecx + 16);  // @92_54c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @93_54c4b0
  PV[1] = (u32)(eax);  // @94_54c4b0
  eax = ext_54a0e0_stdcall2(PV[1], PV[0]);  // @95_54c4b0
  ecx = edx = 0;  // @96_54c4b0
  L54c623:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @98_54c4b0
  ebx = (ebx + 1);  // @99_54c4b0
  FL[3] = ebx;  // @100_54c4b0
  edi = (edi + (u32)(8));  // @101_54c4b0
  FL[3] = edi;  // @102_54c4b0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @103_54c4b0
  if ((s32)FL[0] < (s32)FL[1]) goto L54c4f0;  // @104_54c4b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @105_54c4b0
  L54c636:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @107_54c4b0
  FL[2] = (ecx & ecx);  // @108_54c4b0
  if (FL[2] == 0) goto L54c643;  // @109_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_54c4b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @111_54c4b0
  ecx = edx = 0;  // @112_54c4b0
  L54c643:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @114_54c4b0
  edx = (u32)(EBP - 68);  // @115_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @116_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @117_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @118_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @119_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @120_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @121_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @122_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @123_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @124_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @125_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @126_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @127_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @128_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @129_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @130_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @131_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @132_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @133_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @134_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @135_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @136_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @137_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @138_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @139_54c4b0
  X0[1] = 0;  // @140_54c4b0
  X0[2] = 0;  // @141_54c4b0
  X0[3] = 0;  // @142_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @143_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @144_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @145_54c4b0
  X0[1] = 0;  // @146_54c4b0
  X0[2] = 0;  // @147_54c4b0
  X0[3] = 0;  // @148_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @149_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @150_54c4b0
  X0[1] = 0;  // @151_54c4b0
  X0[2] = 0;  // @152_54c4b0
  X0[3] = 0;  // @153_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @154_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 32) + 0), 4); v; });  // @155_54c4b0
  X0[1] = 0;  // @156_54c4b0
  X0[2] = 0;  // @157_54c4b0
  X0[3] = 0;  // @158_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @159_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; });  // @160_54c4b0
  X0[1] = 0;  // @161_54c4b0
  X0[2] = 0;  // @162_54c4b0
  X0[3] = 0;  // @163_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @164_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 40) + 0), 4); v; });  // @165_54c4b0
  X0[1] = 0;  // @166_54c4b0
  X0[2] = 0;  // @167_54c4b0
  X0[3] = 0;  // @168_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @169_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 0), 4); v; });  // @170_54c4b0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 4), 4); v; });  // @171_54c4b0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 8), 4); v; });  // @172_54c4b0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 12), 4); v; });  // @173_54c4b0
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @174_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @175_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 4), &X0[1], 4);  // @176_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 8), &X0[2], 4);  // @177_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 12), &X0[3], 4);  // @178_54c4b0
  { u32 v = (u32)((u32)(1008981770)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @179_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 60) + 0), 4); v; });  // @180_54c4b0
  X0[1] = 0;  // @181_54c4b0
  X0[2] = 0;  // @182_54c4b0
  X0[3] = 0;  // @183_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @184_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 64) + 0), 4); v; });  // @185_54c4b0
  X0[1] = 0;  // @186_54c4b0
  X0[2] = 0;  // @187_54c4b0
  X0[3] = 0;  // @188_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @189_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @190_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @191_54c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @192_54c4b0
  PV[2] = (u32)(edx);  // @193_54c4b0
  PV[3] = (u32)(eax);  // @194_54c4b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, PV[3], PV[2], (u32)(1));  // @195_54c4b0
  ecx = edx = 0;  // @196_54c4b0
  FL[2] = (eax & eax);  // @197_54c4b0
  if (FL[2] == 0) goto L54c719;  // @198_54c4b0
  edx = (u32)(6961668);  // @199_54c4b0
  goto L54c72b;  // @200_54c4b0
  L54c719:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @202_54c4b0
  PV[4] = (u32)(eax);  // @203_54c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @204_54c4b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(ecx + 68)))(ecx, PV[4]);  // @205_54c4b0
  ecx = edx = 0;  // @206_54c4b0
  FL[2] = (eax & eax);  // @207_54c4b0
  if (FL[2] == 0) goto L54c732;  // @208_54c4b0
  edx = (u32)(6961704);  // @209_54c4b0
  L54c72b:;
  ecx = eax;  // @211_54c4b0
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @212_54c4b0
  ecx = edx = 0;  // @213_54c4b0
  L54c732:;
  ext_633654(G(u32, 0x6f5630));  // @215_54c4b0
  return eax;  // @216_54c4b0
}
PCREG(54c4b0, lifted_54c4b0);

extern "C" u32 THISCALL lifted_610430(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_610430
  edx = (u32)(7273616);  // @1_610430
  ebx = ecx;  // @2_610430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @3_610430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_610430
  ecx = (u32)(ebx + 5226);  // @5_610430
  edi = (u32)(60);  // @6_610430
  L610460:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_610430
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @9_610430
  if (FL[0] != FL[1]) goto L610473;  // @10_610430
  ecx = (ecx + (u32)(4));  // @11_610430
  FL[3] = ecx;  // @12_610430
  edx = (edx + (u32)(4));  // @13_610430
  FL[3] = edx;  // @14_610430
  edi = (edi - (u32)(4));  // @15_610430
  FL[3] = edi;  // @16_610430
  if (edi < 0xfffffffcu) goto L610460;  // @17_610430
  goto L6104b6;  // @18_610430
  L610473:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 0), 4); v; });  // @20_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 4), 4); v; });  // @21_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 8), 4); v; });  // @22_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 12), 4); v; });  // @23_610430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4983), sizeof v); (u32)v; });  // @24_610430
  edx = (u32)(ebx + 5226);  // @25_610430
  PV[0] = (u32)(edx);  // @26_610430
  __builtin_memcpy((void *)((u32)(edx) + 0), &X0[0], 4);  // @27_610430
  __builtin_memcpy((void *)((u32)(edx) + 4), &X0[1], 4);  // @28_610430
  __builtin_memcpy((void *)((u32)(edx) + 8), &X0[2], 4);  // @29_610430
  __builtin_memcpy((void *)((u32)(edx) + 12), &X0[3], 4);  // @30_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 0), 4); v; });  // @31_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 4), 4); v; });  // @32_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 8), 4); v; });  // @33_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 12), 4); v; });  // @34_610430
  PV[1] = (u32)(eax);  // @35_610430
  __builtin_memcpy((void *)((u32)(edx + 16) + 0), &X0[0], 4);  // @36_610430
  __builtin_memcpy((void *)((u32)(edx + 16) + 4), &X0[1], 4);  // @37_610430
  __builtin_memcpy((void *)((u32)(edx + 16) + 8), &X0[2], 4);  // @38_610430
  __builtin_memcpy((void *)((u32)(edx + 16) + 12), &X0[3], 4);  // @39_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 0), 4); v; });  // @40_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 4), 4); v; });  // @41_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 8), 4); v; });  // @42_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 12), 4); v; });  // @43_610430
  __builtin_memcpy((void *)((u32)(edx + 32) + 0), &X0[0], 4);  // @44_610430
  __builtin_memcpy((void *)((u32)(edx + 32) + 4), &X0[1], 4);  // @45_610430
  __builtin_memcpy((void *)((u32)(edx + 32) + 8), &X0[2], 4);  // @46_610430
  __builtin_memcpy((void *)((u32)(edx + 32) + 12), &X0[3], 4);  // @47_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 0), 4); v; });  // @48_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 4), 4); v; });  // @49_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 8), 4); v; });  // @50_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 12), 4); v; });  // @51_610430
  __builtin_memcpy((void *)((u32)(edx + 48) + 0), &X0[0], 4);  // @52_610430
  __builtin_memcpy((void *)((u32)(edx + 48) + 4), &X0[1], 4);  // @53_610430
  __builtin_memcpy((void *)((u32)(edx + 48) + 8), &X0[2], 4);  // @54_610430
  __builtin_memcpy((void *)((u32)(edx + 48) + 12), &X0[3], 4);  // @55_610430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @56_610430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, PV[1], (u32)(2), PV[0]);  // @57_610430
  ecx = edx = 0;  // @58_610430
  L6104b6:;
  FL[2] = (esi & esi);  // @60_610430
  if (FL[2] == 0) goto L610634;  // @61_610430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @62_610430
  FL[2] = (ecx & ecx);  // @63_610430
  if (FL[2] == 0) goto L610634;  // @64_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @65_610430
  X0[1] = 0;  // @66_610430
  X0[2] = 0;  // @67_610430
  X0[3] = 0;  // @68_610430
  X1[0] = 0;  // @69_610430
  X1[1] = 0;  // @70_610430
  X1[2] = 0;  // @71_610430
  X1[3] = 0;  // @72_610430
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @73_610430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @74_610430
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @75_610430
  if (__builtin_parity(FL[2] & 0xff)) goto L610504;  // @76_610430
  edx = ecx;  // @77_610430
  ecx = (u32)(EBP - 20);  // @78_610430
  FS[0] = ext_44e630_fastcall2_ld(ecx, edx);  // @79_610430
  ecx = edx = 0;  // @80_610430
  STF((u32)(EBP - 72), FS[0]);  // @81_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @82_610430
  X0[1] = 0;  // @83_610430
  X0[2] = 0;  // @84_610430
  X0[3] = 0;  // @85_610430
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; })));  // @86_610430
  PV[2] = (u32)(ecx);  // @87_610430
  ecx = (u32)(EBP - 20);  // @88_610430
  PV[3] = X0[0];  // @89_610430
  eax = ext_4e0d00_thiscall2(ecx, PV[3]);  // @90_610430
    // @91_610430
  X1[0] = 0;  // @92_610430
  X1[1] = 0;  // @93_610430
  X1[2] = 0;  // @94_610430
  X1[3] = 0;  // @95_610430
  goto L610521;  // @96_610430
  L610504:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @98_610430
  X0[1] = 0;  // @99_610430
  X0[2] = 0;  // @100_610430
  X0[3] = 0;  // @101_610430
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @102_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; });  // @103_610430
  X0[1] = 0;  // @104_610430
  X0[2] = 0;  // @105_610430
  X0[3] = 0;  // @106_610430
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @107_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; });  // @108_610430
  X0[1] = 0;  // @109_610430
  X0[2] = 0;  // @110_610430
  X0[3] = 0;  // @111_610430
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @112_610430
  L610521:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4807), sizeof v); (u32)v; }) & (u32)(16384));  // @114_610430
  if (FL[2] != 0) goto L6105a1;  // @115_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 5362) + 0), 4); v; });  // @116_610430
  X0[1] = 0;  // @117_610430
  X0[2] = 0;  // @118_610430
  X0[3] = 0;  // @119_610430
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @120_610430
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @121_610430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @122_610430
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @123_610430
  if (__builtin_parity(FL[2] & 0xff)) goto L6105a1;  // @124_610430
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @125_610430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @126_610430
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @127_610430
  if (__builtin_parity(FL[2] & 0xff)) goto L6105a1;  // @128_610430
  PV[4] = (u32)(ecx);  // @129_610430
  edx = (u32)(esi + 24);  // @130_610430
  PV[5] = X0[0];  // @131_610430
  ecx = (u32)(EBP - 68);  // @132_610430
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[5]);  // @133_610430
    // @134_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @135_610430
  X0[1] = 0;  // @136_610430
  X0[2] = 0;  // @137_610430
  X0[3] = 0;  // @138_610430
  edx = (u32)(esi + 12);  // @139_610430
  PV[6] = (u32)(ecx);  // @140_610430
  ecx = (u32)(EBP - 52);  // @141_610430
  PV[7] = X0[0];  // @142_610430
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[7]);  // @143_610430
    // @144_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @145_610430
  X0[1] = 0;  // @146_610430
  X0[2] = 0;  // @147_610430
  X0[3] = 0;  // @148_610430
  edx = esi;  // @149_610430
  PV[8] = (u32)(ecx);  // @150_610430
  ecx = (u32)(EBP - 36);  // @151_610430
  PV[9] = X0[0];  // @152_610430
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[9]);  // @153_610430
    // @154_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @155_610430
  X0[1] = 0;  // @156_610430
  X0[2] = 0;  // @157_610430
  X0[3] = 0;  // @158_610430
  PV[10] = (u32)(ecx);  // @159_610430
  ecx = (u32)(EBP - 20);  // @160_610430
  PV[11] = X0[0];  // @161_610430
  eax = ext_4e0d00_thiscall2(ecx, PV[11]);  // @162_610430
    // @163_610430
  goto L6105fa;  // @164_610430
  L6105a1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @166_610430
  X0[1] = 0;  // @167_610430
  X0[2] = 0;  // @168_610430
  X0[3] = 0;  // @169_610430
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @170_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @171_610430
  X0[1] = 0;  // @172_610430
  X0[2] = 0;  // @173_610430
  X0[3] = 0;  // @174_610430
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @175_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 32) + 0), 4); v; });  // @176_610430
  X0[1] = 0;  // @177_610430
  X0[2] = 0;  // @178_610430
  X0[3] = 0;  // @179_610430
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @180_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @181_610430
  X0[1] = 0;  // @182_610430
  X0[2] = 0;  // @183_610430
  X0[3] = 0;  // @184_610430
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @185_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @186_610430
  X0[1] = 0;  // @187_610430
  X0[2] = 0;  // @188_610430
  X0[3] = 0;  // @189_610430
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @190_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @191_610430
  X0[1] = 0;  // @192_610430
  X0[2] = 0;  // @193_610430
  X0[3] = 0;  // @194_610430
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @195_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @196_610430
  X0[1] = 0;  // @197_610430
  X0[2] = 0;  // @198_610430
  X0[3] = 0;  // @199_610430
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @200_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @201_610430
  X0[1] = 0;  // @202_610430
  X0[2] = 0;  // @203_610430
  X0[3] = 0;  // @204_610430
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @205_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @206_610430
  X0[1] = 0;  // @207_610430
  X0[2] = 0;  // @208_610430
  X0[3] = 0;  // @209_610430
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @210_610430
  L6105fa:;
  eax = (u32)(EBP - 68);  // @212_610430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @213_610430
  PV[12] = (u32)(eax);  // @214_610430
  ecx = ebx;  // @215_610430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @216_610430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @217_610430
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @218_610430
  eax = ext_610f20_thiscall2(ecx, PV[12]);  // @219_610430
  ecx = edx = 0;  // @220_610430
  ext_633654(G(u32, 0x6f5630));  // @221_610430
  return eax;  // @222_610430
  L610634:;
  edi = (u32)(ebx + 5290);  // @224_610430
  edx = (u32)(7273616);  // @225_610430
  ecx = edi;  // @226_610430
  esi = (u32)(60);  // @227_610430
  L610646:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @229_610430
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @230_610430
  if (FL[0] != FL[1]) goto L61066a;  // @231_610430
  ecx = (ecx + (u32)(4));  // @232_610430
  FL[3] = ecx;  // @233_610430
  edx = (edx + (u32)(4));  // @234_610430
  FL[3] = edx;  // @235_610430
  esi = (esi - (u32)(4));  // @236_610430
  FL[3] = esi;  // @237_610430
  if (esi < 0xfffffffcu) goto L610646;  // @238_610430
  ext_633654(G(u32, 0x6f5630));  // @239_610430
  return eax;  // @240_610430
  L61066a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 0), 4); v; });  // @242_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 4), 4); v; });  // @243_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 8), 4); v; });  // @244_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 12), 4); v; });  // @245_610430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4983), sizeof v); (u32)v; });  // @246_610430
  PV[13] = (u32)(edi);  // @247_610430
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @248_610430
  __builtin_memcpy((void *)((u32)(edi) + 4), &X0[1], 4);  // @249_610430
  __builtin_memcpy((void *)((u32)(edi) + 8), &X0[2], 4);  // @250_610430
  __builtin_memcpy((void *)((u32)(edi) + 12), &X0[3], 4);  // @251_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 0), 4); v; });  // @252_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 4), 4); v; });  // @253_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 8), 4); v; });  // @254_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 12), 4); v; });  // @255_610430
  PV[14] = (u32)(eax);  // @256_610430
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @257_610430
  __builtin_memcpy((void *)((u32)(edi + 16) + 4), &X0[1], 4);  // @258_610430
  __builtin_memcpy((void *)((u32)(edi + 16) + 8), &X0[2], 4);  // @259_610430
  __builtin_memcpy((void *)((u32)(edi + 16) + 12), &X0[3], 4);  // @260_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 0), 4); v; });  // @261_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 4), 4); v; });  // @262_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 8), 4); v; });  // @263_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 12), 4); v; });  // @264_610430
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X0[0], 4);  // @265_610430
  __builtin_memcpy((void *)((u32)(edi + 32) + 4), &X0[1], 4);  // @266_610430
  __builtin_memcpy((void *)((u32)(edi + 32) + 8), &X0[2], 4);  // @267_610430
  __builtin_memcpy((void *)((u32)(edi + 32) + 12), &X0[3], 4);  // @268_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 0), 4); v; });  // @269_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 4), 4); v; });  // @270_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 8), 4); v; });  // @271_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 12), 4); v; });  // @272_610430
  __builtin_memcpy((void *)((u32)(edi + 48) + 0), &X0[0], 4);  // @273_610430
  __builtin_memcpy((void *)((u32)(edi + 48) + 4), &X0[1], 4);  // @274_610430
  __builtin_memcpy((void *)((u32)(edi + 48) + 8), &X0[2], 4);  // @275_610430
  __builtin_memcpy((void *)((u32)(edi + 48) + 12), &X0[3], 4);  // @276_610430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @277_610430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, PV[14], (u32)(256), PV[13]);  // @278_610430
  ecx = edx = 0;  // @279_610430
  ext_633654(G(u32, 0x6f5630));  // @280_610430
  return eax;  // @281_610430
}
PCREG(610430, lifted_610430);

extern "C" u32 THISCALL lifted_657590(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x139e0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x138e0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x138e0 + 8, &a0, 4);
  __builtin_memcpy(F + 0x138e0 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_657590
  ebx = ecx;  // @1_657590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_657590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80024), &v, sizeof v); }  // @3_657590
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4_657590
  if (FL[0] != FL[1]) goto L657800;  // @5_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @6_657590
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @7_657590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[0]);  // @8_657590
  ecx = edx = 0;  // @9_657590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_657590
  edi = eax;  // @11_657590
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @12_657590
  ecx = ebx;  // @13_657590
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_657590
  edi = (edi + (u32)(2));  // @15_657590
  FL[3] = edi;  // @16_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80020), &v, sizeof v); }  // @17_657590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 12)))(ecx, PV[1]);  // @18_657590
  ecx = edx = 0;  // @19_657590
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80020), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_657590
  edx = eax;  // @21_657590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 80008), &v, sizeof v); }  // @22_657590
  if (FL[0] <= FL[1]) goto L657800;  // @23_657590
  L657600:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @25_657590
  esi = (u32)(1);  // @26_657590
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_657590
  edi = (edi + (u32)(4));  // @28_657590
  FL[3] = edi;  // @29_657590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80016), &v, sizeof v); }  // @30_657590
  eax = (u32)(eax + eax*8);  // @31_657590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + eax*4) + 0), 4); v; });  // @32_657590
  X0[1] = 0;  // @33_657590
  X0[2] = 0;  // @34_657590
  X0[3] = 0;  // @35_657590
  __builtin_memcpy((void *)((u32)(EBP - 80004) + 0), &X0[0], 4);  // @36_657590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + eax*4 + 4) + 0), 4); v; });  // @37_657590
  X0[1] = 0;  // @38_657590
  X0[2] = 0;  // @39_657590
  X0[3] = 0;  // @40_657590
  __builtin_memcpy((void *)((u32)(EBP - 80000) + 0), &X0[0], 4);  // @41_657590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + eax*4 + 8) + 0), 4); v; });  // @42_657590
  X0[1] = 0;  // @43_657590
  X0[2] = 0;  // @44_657590
  X0[3] = 0;  // @45_657590
  __builtin_memcpy((void *)((u32)(EBP - 79996) + 0), &X0[0], 4);  // @46_657590
  FL[0] = ecx; FL[1] = esi;  // @47_657590
  if (FL[0] <= FL[1]) goto L6577ed;  // @48_657590
  ebx = (u32)(ecx - 1);  // @49_657590
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 80012), &v, sizeof v); }  // @50_657590
  L657652:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_657590
  ecx = esi;  // @53_657590
  ecx = (ecx + ecx);  // @54_657590
  FL[3] = ecx;  // @55_657590
  edi = (edi + (u32)(2));  // @56_657590
  FL[3] = edi;  // @57_657590
  esi = (esi + 1);  // @58_657590
  FL[3] = esi;  // @59_657590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80016), &v, sizeof v); }  // @60_657590
  edx = (u32)(eax + eax*8);  // @61_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80008), sizeof v); (u32)v; });  // @62_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @63_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + ecx*8 - 80004), &v, sizeof v); }  // @64_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80008), sizeof v); (u32)v; });  // @65_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4 + 4), sizeof v); (u32)v; });  // @66_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + ecx*8 - 80000), &v, sizeof v); }  // @67_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80008), sizeof v); (u32)v; });  // @68_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4 + 8), sizeof v); (u32)v; });  // @69_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + ecx*8 - 79996), &v, sizeof v); }  // @70_657590
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @71_657590
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi - 2), sizeof v); (u32)v; });  // @72_657590
  if (FL[0] != FL[1]) goto L657741;  // @73_657590
  FL[0] = esi; FL[1] = (u32)(2);  // @74_657590
  if (FL[0] <= FL[1]) goto L65773f;  // @75_657590
  edi = (u32)(esi - 2);  // @76_657590
  ebx = 0;  // @77_657590
  FL[3] = ebx;  // @78_657590
  FL[2] = (edi & edi);  // @79_657590
  if (FL[2] == 0) goto L657733;  // @80_657590
  esi = (u32)(EBP - 79980);  // @81_657590
  L6576c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80024), sizeof v); (u32)v; });  // @83_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_657590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @85_657590
  ecx = edx = 0;  // @86_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 24), sizeof v); (u32)v; });  // @87_657590
  edx = eax;  // @88_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 8), sizeof v); (u32)v; });  // @89_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @90_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 20), sizeof v); (u32)v; });  // @91_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @92_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 16), sizeof v); (u32)v; });  // @93_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @94_657590
  FL[2] = ((ebx & 0xff) & (u32)(1));  // @95_657590
  if (FL[2] == 0) goto L65770c;  // @96_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @97_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @98_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @99_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @101_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @102_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @103_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @104_657590
  esi = (esi + (u32)(16));  // @105_657590
  FL[3] = esi;  // @106_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @107_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @109_657590
  goto L65772e;  // @110_657590
  L65770c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @112_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @113_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @114_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @116_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @117_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @118_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @119_657590
  esi = (esi + (u32)(16));  // @120_657590
  FL[3] = esi;  // @121_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @122_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @123_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @124_657590
  L65772e:;
  ebx = (ebx + 1);  // @126_657590
  FL[3] = ebx;  // @127_657590
  FL[0] = ebx; FL[1] = edi;  // @128_657590
  if (FL[0] != FL[1]) goto L6576c0;  // @129_657590
  L657733:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80016), sizeof v); (u32)v; });  // @131_657590
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80012), sizeof v); (u32)v; });  // @132_657590
  L65773f:;
  esi = 0;  // @134_657590
  FL[3] = esi;  // @135_657590
  L657741:;
  ebx = (ebx - (u32)(1));  // @137_657590
  FL[3] = ebx;  // @138_657590
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 80012), &v, sizeof v); }  // @139_657590
  if (FL[3] != 0) goto L657652;  // @140_657590
  FL[0] = esi; FL[1] = (u32)(2);  // @141_657590
  if (FL[0] <= FL[1]) goto L6577e7;  // @142_657590
  eax = (u32)(esi - 2);  // @143_657590
  ebx = 0;  // @144_657590
  FL[3] = ebx;  // @145_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80012), &v, sizeof v); }  // @146_657590
  FL[2] = (eax & eax);  // @147_657590
  if (FL[2] == 0) goto L6577e7;  // @148_657590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80024), sizeof v); (u32)v; });  // @149_657590
  esi = (u32)(EBP - 79980);  // @150_657590
  L657774:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @152_657590
  ecx = edi;  // @153_657590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @154_657590
  ecx = edx = 0;  // @155_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 24), sizeof v); (u32)v; });  // @156_657590
  edx = eax;  // @157_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 8), sizeof v); (u32)v; });  // @158_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @159_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 20), sizeof v); (u32)v; });  // @160_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @161_657590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 16), sizeof v); (u32)v; });  // @162_657590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @163_657590
  FL[2] = ((ebx & 0xff) & (u32)(1));  // @164_657590
  if (FL[2] == 0) goto L6577bc;  // @165_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @166_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @167_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @168_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @169_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @170_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @171_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @172_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @173_657590
  esi = (esi + (u32)(16));  // @174_657590
  FL[3] = esi;  // @175_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @176_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @178_657590
  goto L6577de;  // @179_657590
  L6577bc:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @181_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @182_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @183_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @184_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @185_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @186_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @187_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @188_657590
  esi = (esi + (u32)(16));  // @189_657590
  FL[3] = esi;  // @190_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @191_657590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @192_657590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @193_657590
  L6577de:;
  ebx = (ebx + 1);  // @195_657590
  FL[3] = ebx;  // @196_657590
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80012), sizeof v); (u32)v; });  // @197_657590
  if (FL[0] != FL[1]) goto L657774;  // @198_657590
  L6577e7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80008), sizeof v); (u32)v; });  // @200_657590
  L6577ed:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80020), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 80020), &v, sizeof v); }  // @202_657590
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80020), sizeof v); (u32)v; });  // @203_657590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80016), sizeof v); (u32)v; });  // @204_657590
  if (FL[3] != 0) goto L657600;  // @205_657590
  L657800:;
  ext_633654(G(u32, 0x6f5630));  // @207_657590
  return eax;  // @208_657590
}
PCREG(657590, lifted_657590);

