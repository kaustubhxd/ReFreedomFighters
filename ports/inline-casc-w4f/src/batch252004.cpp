// batch252004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_60feb0_fastcall4(u32, u32, u32, u32) __asm__("ext_60feb0");
extern "C" u32 FASTCALL ext_60ff30_fastcall4(u32, u32, u32, u32) __asm__("ext_60ff30");
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

extern "C" u32 THISCALL lifted_608ef0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  edi = ecx;  // @0_608ef0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 380), &v, sizeof v); }  // @1_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_608ef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @3_608ef0
  ecx = edx = 0;  // @4_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_608ef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 432)))(ecx);  // @7_608ef0
  ecx = edx = 0;  // @8_608ef0
  esi = eax;  // @9_608ef0
  ecx = esi;  // @10_608ef0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @11_608ef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_608ef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 56), sizeof v); (u32)v; });  // @13_608ef0
  FS[0] = ((long double(THISCALL *)(u32))(edx))(ecx);  // @14_608ef0
  ecx = edx = 0;  // @15_608ef0
  STF((u32)(EBP - 376), FS[0]);  // @16_608ef0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 376) + 0), 4); v; });  // @17_608ef0
  X1[1] = 0;  // @18_608ef0
  X1[2] = 0;  // @19_608ef0
  X1[3] = 0;  // @20_608ef0
  X0[0] = 0;  // @21_608ef0
  X0[1] = 0;  // @22_608ef0
  X0[2] = 0;  // @23_608ef0
  X0[3] = 0;  // @24_608ef0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @25_608ef0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @26_608ef0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @27_608ef0
  if (__builtin_parity(FL[2] & 0xff)) goto L609781;  // @28_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_608ef0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @30_608ef0
  X0[1] = 0;  // @31_608ef0
  X0[2] = 0;  // @32_608ef0
  X0[3] = 0;  // @33_608ef0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7490364) + 0), 4); v; })));  // @34_608ef0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; }));  // @35_608ef0
  __builtin_memcpy((void *)((u32)(7490364) + 0), &X0[0], 4);  // @36_608ef0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L608f8d;  // @37_608ef0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7490368), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @38_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7490364), &v, sizeof v); }  // @39_608ef0
  { u8 v = (u8)(((FL[0] == FL[1]) ? 1 : 0)); __builtin_memcpy((void *)(u32)(7490368), &v, sizeof v); }  // @40_608ef0
  L608f8d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_608ef0
  ecx = edi;  // @43_608ef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 216)))(ecx);  // @44_608ef0
  ecx = edx = 0;  // @45_608ef0
  ecx = edi;  // @46_608ef0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @47_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_608ef0
  X0[0] = F2U((float)(s32)X0[0]);  // @49_608ef0
  X0[1] = F2U((float)(s32)X0[1]);  // @50_608ef0
  X0[2] = F2U((float)(s32)X0[2]);  // @51_608ef0
  X0[3] = F2U((float)(s32)X0[3]);  // @52_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 388) + 0), &X0[0], 4);  // @53_608ef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @54_608ef0
  ecx = edx = 0;  // @55_608ef0
  ecx = edi;  // @56_608ef0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @57_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_608ef0
  X0[0] = F2U((float)(s32)X0[0]);  // @59_608ef0
  X0[1] = F2U((float)(s32)X0[1]);  // @60_608ef0
  X0[2] = F2U((float)(s32)X0[2]);  // @61_608ef0
  X0[3] = F2U((float)(s32)X0[3]);  // @62_608ef0
  PV[0] = X0[0];  // @63_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 368) + 0), &X0[0], 4);  // @64_608ef0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 388) + 0), 4); v; });  // @65_608ef0
  X0[1] = 0;  // @66_608ef0
  X0[2] = 0;  // @67_608ef0
  X0[3] = 0;  // @68_608ef0
  PV[1] = X0[0];  // @69_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 308)))(ecx, (u32)(0), (u32)(0), PV[1], PV[0]);  // @70_608ef0
  ecx = edx = 0;  // @71_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @72_608ef0
  edx = (u32)(EBP - 364);  // @73_608ef0
  PV[2] = (u32)(edx);  // @74_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @75_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 324), &v, sizeof v); }  // @76_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 344), &v, sizeof v); }  // @77_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 364), &v, sizeof v); }  // @78_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 316), &v, sizeof v); }  // @79_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @80_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @81_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @82_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 312), &v, sizeof v); }  // @83_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @84_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @85_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @86_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @87_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 320), &v, sizeof v); }  // @88_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @89_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 332), &v, sizeof v); }  // @90_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @91_608ef0
  PV[3] = (u32)(eax);  // @92_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, PV[3], (u32)(3), PV[2]);  // @93_608ef0
  ecx = edx = 0;  // @94_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @95_608ef0
  edx = (u32)(EBP - 364);  // @96_608ef0
  PV[4] = (u32)(edx);  // @97_608ef0
  PV[5] = (u32)(eax);  // @98_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @99_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, PV[5], (u32)(2), PV[4]);  // @100_608ef0
  ecx = edx = 0;  // @101_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @102_608ef0
  edx = (u32)(EBP - 364);  // @103_608ef0
  PV[6] = (u32)(edx);  // @104_608ef0
  PV[7] = (u32)(eax);  // @105_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @106_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, PV[7], (u32)(256), PV[6]);  // @107_608ef0
  ecx = edx = 0;  // @108_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @109_608ef0
  edx = (u32)(EBP - 364);  // @110_608ef0
  PV[8] = (u32)(edx);  // @111_608ef0
  PV[9] = (u32)(eax);  // @112_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @113_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, PV[9], (u32)(16), PV[8]);  // @114_608ef0
  ecx = edx = 0;  // @115_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @116_608ef0
  PV[10] = (u32)(eax);  // @117_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @118_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[10], (u32)(8), (u32)(3));  // @119_608ef0
  ecx = edx = 0;  // @120_608ef0
  ebx = (u32)(3);  // @121_608ef0
  ecx = 0;  // @122_608ef0
  FL[3] = ecx;  // @123_608ef0
  edx = ebx;  // @124_608ef0
  eax = ext_60ff30_fastcall4(ecx, edx, (u32)(2), (u32)(0));  // @125_608ef0
  ecx = edx = 0;  // @126_608ef0
  edx = ebx;  // @127_608ef0
  ecx = 0;  // @128_608ef0
  FL[3] = ecx;  // @129_608ef0
  eax = ext_60feb0_fastcall4(ecx, edx, (u32)(2), (u32)(0));  // @130_608ef0
  ecx = edx = 0;  // @131_608ef0
  ebx = (u32)(1);  // @132_608ef0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490056), sizeof v); (u32)v; }); FL[1] = ebx;  // @133_608ef0
  if (FL[0] <= FL[1]) goto L60914a;  // @134_608ef0
  PV[11] = (u32)(ebx);  // @135_608ef0
  edx = ebx;  // @136_608ef0
  ecx = ebx;  // @137_608ef0
  eax = ext_60ff30_fastcall4(ecx, edx, (u32)(2), PV[11]);  // @138_608ef0
  ecx = edx = 0;  // @139_608ef0
  PV[12] = (u32)(ebx);  // @140_608ef0
  edx = ebx;  // @141_608ef0
  ecx = ebx;  // @142_608ef0
  eax = ext_60feb0_fastcall4(ecx, edx, (u32)(2), PV[12]);  // @143_608ef0
  ecx = edx = 0;  // @144_608ef0
  L60914a:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489832), sizeof v); (u32)v; }); FL[1] = (u32)(5);  // @146_608ef0
  if (FL[0] == FL[1]) goto L60916f;  // @147_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @148_608ef0
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(7489832), &v, sizeof v); }  // @149_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @150_608ef0
  PV[13] = (u32)(eax);  // @151_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[13], (u32)(19), (u32)(5));  // @152_608ef0
  ecx = edx = 0;  // @153_608ef0
  L60916f:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489836), sizeof v); (u32)v; }); FL[1] = (u32)(6);  // @155_608ef0
  if (FL[0] == FL[1]) goto L609194;  // @156_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @157_608ef0
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(7489836), &v, sizeof v); }  // @158_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @159_608ef0
  PV[14] = (u32)(eax);  // @160_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[14], (u32)(20), (u32)(6));  // @161_608ef0
  ecx = edx = 0;  // @162_608ef0
  L609194:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489844), sizeof v); (u32)v; }); FL[1] = ebx;  // @164_608ef0
  if (FL[0] == FL[1]) goto L6091b4;  // @165_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @166_608ef0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(7489844), &v, sizeof v); }  // @167_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @168_608ef0
  PV[15] = (u32)(eax);  // @169_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[15], (u32)(27), (u32)(1));  // @170_608ef0
  ecx = edx = 0;  // @171_608ef0
  L6091b4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489852), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @173_608ef0
  if (FL[0] == FL[1]) goto L6091d9;  // @174_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @175_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489852), &v, sizeof v); }  // @176_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @177_608ef0
  PV[16] = (u32)(eax);  // @178_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[16], (u32)(14), (u32)(0));  // @179_608ef0
  ecx = edx = 0;  // @180_608ef0
  L6091d9:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489896), sizeof v); (u32)v; }); FL[1] = (u32)(8);  // @182_608ef0
  if (FL[0] == FL[1]) goto L6091fe;  // @183_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @184_608ef0
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(7489896), &v, sizeof v); }  // @185_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @186_608ef0
  PV[17] = (u32)(eax);  // @187_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[17], (u32)(23), (u32)(8));  // @188_608ef0
  ecx = edx = 0;  // @189_608ef0
  L6091fe:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489856), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @191_608ef0
  if (FL[0] != FL[1]) goto L60922c;  // @192_608ef0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489840), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @193_608ef0
  if (FL[0] == FL[1]) goto L60922c;  // @194_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @195_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489840), &v, sizeof v); }  // @196_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @197_608ef0
  PV[18] = (u32)(eax);  // @198_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[18], (u32)(28), (u32)(0));  // @199_608ef0
  ecx = edx = 0;  // @200_608ef0
  L60922c:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489864), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @202_608ef0
  if (FL[0] == FL[1]) goto L609254;  // @203_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @204_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489864), &v, sizeof v); }  // @205_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @206_608ef0
  PV[19] = (u32)(eax);  // @207_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[19], (u32)(137), (u32)(0));  // @208_608ef0
  ecx = edx = 0;  // @209_608ef0
  L609254:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489608), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @211_608ef0
  if (FL[0] == FL[1]) goto L609279;  // @212_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @213_608ef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489608), &v, sizeof v); }  // @214_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @215_608ef0
  PV[20] = (u32)(eax);  // @216_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 244)))(ecx, PV[20], (u32)(0), (u32)(0));  // @217_608ef0
  ecx = edx = 0;  // @218_608ef0
  L609279:;
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @220_608ef0
  ecx = esi;  // @221_608ef0
  { u32 v = (u32)((u32)(196610)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @222_608ef0
  ebx = (u32)(2);  // @223_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @224_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @225_608ef0
  FS[0] = ((long double(THISCALL *)(u32))(eax))(ecx);  // @226_608ef0
  ecx = edx = 0;  // @227_608ef0
  STF((u32)(EBP - 376), FS[0]);  // @228_608ef0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 376) + 0), 4); v; });  // @229_608ef0
  X0[1] = 0;  // @230_608ef0
  X0[2] = 0;  // @231_608ef0
  X0[3] = 0;  // @232_608ef0
  ecx = (u32)(255);  // @233_608ef0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; })));  // @234_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @235_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @236_608ef0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799784) + 0), 4); v; })));  // @237_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @238_608ef0
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(EBP - 264), &v, sizeof v); }  // @239_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @240_608ef0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @241_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 256), &v, sizeof v); }  // @242_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 228), &v, sizeof v); }  // @243_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 220), &v, sizeof v); }  // @244_608ef0
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @245_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @246_608ef0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @247_608ef0
  X0[1] = 0;  // @248_608ef0
  X0[2] = 0;  // @249_608ef0
  X0[3] = 0;  // @250_608ef0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 376) + 0), 4); v; })));  // @251_608ef0
  FL[0] = eax; FL[1] = ecx;  // @252_608ef0
  if ((s32)FL[0] > (s32)FL[1]) eax = ecx;  // @253_608ef0
  ecx = (u32)(EBP - 12);  // @254_608ef0
  PV[21] = (u32)(ecx);  // @255_608ef0
  eax = (eax << (u32)(24));  // @256_608ef0
  FL[3] = eax;  // @257_608ef0
  ecx = (u32)(EBP - 300);  // @258_608ef0
  eax = (eax + (u32)(2105380));  // @259_608ef0
  FL[3] = eax;  // @260_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 224) + 0), &X0[0], 4);  // @261_608ef0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @262_608ef0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @263_608ef0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @264_608ef0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @265_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @266_608ef0
  PV[22] = (u32)(ecx);  // @267_608ef0
  ecx = edi;  // @268_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 188) + 0), &X0[0], 4);  // @269_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(0), PV[22], (u32)(4), PV[21], (u32)(4));  // @270_608ef0
  ecx = edx = 0;  // @271_608ef0
  PV[23] = (u32)(ebx);  // @272_608ef0
  edx = (u32)(ebx + 2);  // @273_608ef0
  ecx = 0;  // @274_608ef0
  FL[3] = ecx;  // @275_608ef0
  eax = ext_60ff30_fastcall4(ecx, edx, PV[23], (u32)(0));  // @276_608ef0
  ecx = edx = 0;  // @277_608ef0
  PV[24] = (u32)(ebx);  // @278_608ef0
  edx = ebx;  // @279_608ef0
  ecx = 0;  // @280_608ef0
  FL[3] = ecx;  // @281_608ef0
  eax = ext_60feb0_fastcall4(ecx, edx, PV[24], (u32)(1));  // @282_608ef0
  ecx = edx = 0;  // @283_608ef0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489844), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @284_608ef0
  if (FL[0] == FL[1]) goto L6093be;  // @285_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @286_608ef0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7489844), &v, sizeof v); }  // @287_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @288_608ef0
  PV[25] = (u32)(eax);  // @289_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[25], (u32)(27), (u32)(1));  // @290_608ef0
  ecx = edx = 0;  // @291_608ef0
  L6093be:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490120), sizeof v); (u32)v; });  // @293_608ef0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489608), sizeof v); (u32)v; }); FL[1] = edx;  // @294_608ef0
  if (FL[0] == FL[1]) goto L6093e3;  // @295_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @296_608ef0
  PV[26] = (u32)(edx);  // @297_608ef0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7489608), &v, sizeof v); }  // @298_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @299_608ef0
  PV[27] = (u32)(eax);  // @300_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 244)))(ecx, PV[27], (u32)(0), PV[26]);  // @301_608ef0
  ecx = edx = 0;  // @302_608ef0
  L6093e3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @304_608ef0
  ecx = edi;  // @305_608ef0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @306_608ef0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @307_608ef0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @308_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 244), sizeof v); (u32)v; });  // @309_608ef0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @310_608ef0
  FS[0] = ((long double(THISCALL *)(u32))(eax))(ecx);  // @311_608ef0
  ecx = edx = 0;  // @312_608ef0
  FS[0] = (FS[0] * LDF((u32)(6818400)));  // @313_608ef0
  ecx = edi;  // @314_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @315_608ef0
  FS[0] = (FS[0] / LDF((u32)(EBP - 388)));  // @316_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 248), sizeof v); (u32)v; });  // @317_608ef0
  STF((u32)(EBP - 392), FS[0]);  // @318_608ef0
  FS[0] = ((long double(THISCALL *)(u32))(eax))(ecx);  // @319_608ef0
  ecx = edx = 0;  // @320_608ef0
  FS[0] = (FS[0] * LDF((u32)(6818400)));  // @321_608ef0
  ecx = edi;  // @322_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @323_608ef0
  FS[0] = (FS[0] / LDF((u32)(EBP - 368)));  // @324_608ef0
  STF((u32)(EBP - 396), FS[0]);  // @325_608ef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @326_608ef0
  ecx = edx = 0;  // @327_608ef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @328_608ef0
  ecx = edi;  // @329_608ef0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 400), &v, sizeof v); }  // @330_608ef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 240)))(ecx);  // @331_608ef0
  ecx = edx = 0;  // @332_608ef0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @333_608ef0
  X0[1] = 0;  // @334_608ef0
  X0[2] = 0;  // @335_608ef0
  X0[3] = 0;  // @336_608ef0
  ecx = esi;  // @337_608ef0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 368) + 0), 4); v; })));  // @338_608ef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @339_608ef0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 376), &v, sizeof v); }  // @340_608ef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 56), sizeof v); (u32)v; });  // @341_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 372) + 0), &X0[0], 4);  // @342_608ef0
  FS[0] = ((long double(THISCALL *)(u32))(edx))(ecx);  // @343_608ef0
  ecx = edx = 0;  // @344_608ef0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 372) + 0), 4); v; });  // @345_608ef0
  X0[1] = 0;  // @346_608ef0
  X0[2] = 0;  // @347_608ef0
  X0[3] = 0;  // @348_608ef0
  ebx = 0;  // @349_608ef0
  FL[3] = ebx;  // @350_608ef0
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @351_608ef0
  FS[1] = 1.0L;  // @352_608ef0
  FS[0] = (FS[1] - FS[0]);  // @353_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 372) + 0), &X0[0], 4);  // @354_608ef0
  FS[0] = (FS[0] + LDF((u32)(EBP - 372)));  // @355_608ef0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 372), &v, sizeof v); }  // @356_608ef0
  STF((u32)(EBP - 384), FS[0]);  // @357_608ef0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 376), sizeof v); (u32)v; }); FL[1] = ebx;  // @358_608ef0
  if ((s32)FL[0] <= (s32)FL[1]) goto L60976d;  // @359_608ef0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 384) + 0), 4); v; });  // @360_608ef0
  X0[1] = 0;  // @361_608ef0
  X0[2] = 0;  // @362_608ef0
  X0[3] = 0;  // @363_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 368) + 0), &X0[0], 4);  // @364_608ef0
  L6094c7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @366_608ef0
  eax = ebx;  // @367_608ef0
  FL[1] = eax;  // @368_608ef0
  eax = (0u - eax);  // @369_608ef0
  ecx = esi;  // @370_608ef0
  PV[28] = (u32)(eax);  // @371_608ef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 8)))(ecx, PV[28]);  // @372_608ef0
  ecx = edx = 0;  // @373_608ef0
  esi = eax;  // @374_608ef0
  FL[2] = (esi & esi);  // @375_608ef0
  if (FL[2] == 0) goto L60973c;  // @376_608ef0
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 368) + 0), 4); v; });  // @377_608ef0
  X6[1] = 0;  // @378_608ef0
  X6[2] = 0;  // @379_608ef0
  X6[3] = 0;  // @380_608ef0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @381_608ef0
  X0[1] = 0;  // @382_608ef0
  X0[2] = 0;  // @383_608ef0
  X0[3] = 0;  // @384_608ef0
  FA = U2F(X6[0]); FB = U2F(X0[0]);  // @385_608ef0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L60973c;  // @386_608ef0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @387_608ef0
  X5[1] = 0;  // @388_608ef0
  X5[2] = 0;  // @389_608ef0
  X5[3] = 0;  // @390_608ef0
  edi = 0;  // @391_608ef0
  FL[3] = edi;  // @392_608ef0
  X5[0] = F2U(U2F(X5[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 388) + 0), 4); v; })));  // @393_608ef0
  X5[0] = F2U(U2F(X5[0]) + U2F(X5[0]));  // @394_608ef0
  X5[0] = F2U(U2F(X5[0]) - U2F(X0[0]));  // @395_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 384) + 0), &X5[0], 4);  // @396_608ef0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 400), sizeof v); (u32)v; }); FL[1] = edi;  // @397_608ef0
  if ((s32)FL[0] <= (s32)FL[1]) goto L60964f;  // @398_608ef0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 400), sizeof v); (u32)v; });  // @399_608ef0
  L609530:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @401_608ef0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @402_608ef0
  if (FL[2] == 0) goto L609649;  // @403_608ef0
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @404_608ef0
  if (FL[0] == FL[1]) goto L609649;  // @405_608ef0
  FL[0] = (eax & 0xff); FL[1] = (u32)(32);  // @406_608ef0
  if (FL[0] == FL[1]) goto L60962f;  // @407_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 380), sizeof v); (u32)v; });  // @408_608ef0
  edx = (u32)(EBP - 12);  // @409_608ef0
  eax = (u32)(s32)(s8)((eax & 0xff));  // @410_608ef0
  X1[0] = X5[0];  // @411_608ef0
  X1[1] = X5[1];  // @412_608ef0
  X1[2] = X5[2];  // @413_608ef0
  X1[3] = X5[3];  // @414_608ef0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 392) + 0), 4); v; })));  // @415_608ef0
  PV[29] = (u32)(edx);  // @416_608ef0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 8346644) + 0), 4); v; });  // @417_608ef0
  X4[1] = 0;  // @418_608ef0
  X4[2] = 0;  // @419_608ef0
  X4[3] = 0;  // @420_608ef0
  edx = (u32)(EBP - 156);  // @421_608ef0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 8346640) + 0), 4); v; });  // @422_608ef0
  X3[1] = 0;  // @423_608ef0
  X3[2] = 0;  // @424_608ef0
  X3[3] = 0;  // @425_608ef0
  X0[0] = X4[0];  // @426_608ef0
  X0[1] = X4[1];  // @427_608ef0
  X0[2] = X4[2];  // @428_608ef0
  X0[3] = X4[3];  // @429_608ef0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7066988) + 0), 4); v; })));  // @430_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @431_608ef0
  X2[0] = X3[0];  // @432_608ef0
  X2[1] = X3[1];  // @433_608ef0
  X2[2] = X3[2];  // @434_608ef0
  X2[3] = X3[3];  // @435_608ef0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7066984) + 0), 4); v; })));  // @436_608ef0
  PV[30] = (u32)(edx);  // @437_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 124) + 0), &X0[0], 4);  // @438_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 88) + 0), &X0[0], 4);  // @439_608ef0
  X0[0] = X6[0];  // @440_608ef0
  X0[1] = X6[1];  // @441_608ef0
  X0[2] = X6[2];  // @442_608ef0
  X0[3] = X6[3];  // @443_608ef0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 396) + 0), 4); v; })));  // @444_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 128) + 0), &X3[0], 4);  // @445_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X5[0], 4);  // @446_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 152) + 0), &X6[0], 4);  // @447_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @448_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X2[0], 4);  // @449_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 120) + 0), &X1[0], 4);  // @450_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X6[0], 4);  // @451_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @452_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X3[0], 4);  // @453_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X4[0], 4);  // @454_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X5[0], 4);  // @455_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @456_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @457_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X2[0], 4);  // @458_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X4[0], 4);  // @459_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X1[0], 4);  // @460_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @461_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @462_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(0), PV[30], (u32)(4), PV[29], (u32)(4));  // @463_608ef0
  ecx = edx = 0;  // @464_608ef0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 384) + 0), 4); v; });  // @465_608ef0
  X5[1] = 0;  // @466_608ef0
  X5[2] = 0;  // @467_608ef0
  X5[3] = 0;  // @468_608ef0
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 368) + 0), 4); v; });  // @469_608ef0
  X6[1] = 0;  // @470_608ef0
  X6[2] = 0;  // @471_608ef0
  X6[3] = 0;  // @472_608ef0
  L60962f:;
  X5[0] = F2U(U2F(X5[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 392) + 0), 4); v; })));  // @474_608ef0
  edi = (edi + 1);  // @475_608ef0
  FL[3] = edi;  // @476_608ef0
  esi = (esi + 1);  // @477_608ef0
  FL[3] = esi;  // @478_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 384) + 0), &X5[0], 4);  // @479_608ef0
  FL[0] = edi; FL[1] = ebx;  // @480_608ef0
  if ((s32)FL[0] < (s32)FL[1]) goto L609530;  // @481_608ef0
  L609649:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; });  // @483_608ef0
  L60964f:;
  FL[2] = (ebx & ebx);  // @485_608ef0
  if (FL[2] != 0) goto L609736;  // @486_608ef0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7490368), sizeof v); (u32)v; }); FL[1] = (ebx & 0xff);  // @487_608ef0
  if (FL[0] == FL[1]) goto L609736;  // @488_608ef0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(8347404) + 0), 4); v; });  // @489_608ef0
  X4[1] = 0;  // @490_608ef0
  X4[2] = 0;  // @491_608ef0
  X4[3] = 0;  // @492_608ef0
  ecx = (u32)(EBP - 12);  // @493_608ef0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(8347400) + 0), 4); v; });  // @494_608ef0
  X3[1] = 0;  // @495_608ef0
  X3[2] = 0;  // @496_608ef0
  X3[3] = 0;  // @497_608ef0
  X0[0] = X4[0];  // @498_608ef0
  X0[1] = X4[1];  // @499_608ef0
  X0[2] = X4[2];  // @500_608ef0
  X0[3] = X4[3];  // @501_608ef0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7066988) + 0), 4); v; })));  // @502_608ef0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 380), sizeof v); (u32)v; });  // @503_608ef0
  X2[0] = X3[0];  // @504_608ef0
  X2[1] = X3[1];  // @505_608ef0
  X2[2] = X3[2];  // @506_608ef0
  X2[3] = X3[3];  // @507_608ef0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7066984) + 0), 4); v; })));  // @508_608ef0
  PV[31] = (u32)(ecx);  // @509_608ef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @510_608ef0
  ecx = (u32)(EBP - 156);  // @511_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 124) + 0), &X0[0], 4);  // @512_608ef0
  X1[0] = X5[0];  // @513_608ef0
  X1[1] = X5[1];  // @514_608ef0
  X1[2] = X5[2];  // @515_608ef0
  X1[3] = X5[3];  // @516_608ef0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 392) + 0), 4); v; })));  // @517_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 88) + 0), &X0[0], 4);  // @518_608ef0
  X0[0] = X6[0];  // @519_608ef0
  X0[1] = X6[1];  // @520_608ef0
  X0[2] = X6[2];  // @521_608ef0
  X0[3] = X6[3];  // @522_608ef0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 396) + 0), 4); v; })));  // @523_608ef0
  PV[32] = (u32)(ecx);  // @524_608ef0
  PV[33] = (u32)(ebx);  // @525_608ef0
  ecx = edi;  // @526_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 128) + 0), &X3[0], 4);  // @527_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X5[0], 4);  // @528_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 152) + 0), &X6[0], 4);  // @529_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @530_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X2[0], 4);  // @531_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 120) + 0), &X1[0], 4);  // @532_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X6[0], 4);  // @533_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @534_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X3[0], 4);  // @535_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X4[0], 4);  // @536_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X5[0], 4);  // @537_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @538_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @539_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X2[0], 4);  // @540_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X4[0], 4);  // @541_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X1[0], 4);  // @542_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @543_608ef0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @544_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, PV[33], PV[32], (u32)(4), PV[31], (u32)(4));  // @545_608ef0
  ecx = edx = 0;  // @546_608ef0
  goto L60973c;  // @547_608ef0
  L609736:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 380), sizeof v); (u32)v; });  // @549_608ef0
  L60973c:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 368) + 0), 4); v; });  // @551_608ef0
  X0[1] = 0;  // @552_608ef0
  X0[2] = 0;  // @553_608ef0
  X0[3] = 0;  // @554_608ef0
  ebx = (ebx + 1);  // @555_608ef0
  FL[3] = ebx;  // @556_608ef0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 396) + 0), 4); v; })));  // @557_608ef0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @558_608ef0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 372), &v, sizeof v); }  // @559_608ef0
  __builtin_memcpy((void *)((u32)(EBP - 368) + 0), &X0[0], 4);  // @560_608ef0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 376), sizeof v); (u32)v; });  // @561_608ef0
  if ((s32)FL[0] < (s32)FL[1]) goto L6094c7;  // @562_608ef0
  L60976d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @564_608ef0
  PV[34] = (u32)(eax);  // @565_608ef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @566_608ef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[34], (u32)(23), (u32)(4));  // @567_608ef0
  ecx = edx = 0;  // @568_608ef0
  L609781:;
  ext_633654(G(u32, 0x6f5630));  // @570_608ef0
  return eax;  // @571_608ef0
}
PCREG(608ef0, lifted_608ef0);

