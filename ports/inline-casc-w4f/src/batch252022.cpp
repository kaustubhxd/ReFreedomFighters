// batch252022.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" long double THISCALL ext_522f60_thiscall3_ld(u32, u32, u32) __asm__("ext_522f60");
extern "C" u32 THISCALL ext_441890_thiscall2(u32, u32) __asm__("ext_441890");
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

extern "C" u32 THISCALL lifted_518bc0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_518bc0
  edi = ecx;  // @1_518bc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_518bc0
  if (FL[0] == FL[1]) goto L519270;  // @3_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @4_518bc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 53), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @5_518bc0
  if (FL[0] != FL[1]) goto L518c5b;  // @6_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; });  // @7_518bc0
  X0[1] = 0;  // @8_518bc0
  X0[2] = 0;  // @9_518bc0
  X0[3] = 0;  // @10_518bc0
  PV[0] = X0[0];  // @11_518bc0
  FS[0] = ext_522f60_thiscall3_ld(ecx, PV[0], (u32)(1112014848));  // @12_518bc0
  ecx = edx = 0;  // @13_518bc0
  STF((u32)(EBP - 4), FS[0]);  // @14_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @15_518bc0
  X0[1] = 0;  // @16_518bc0
  X0[2] = 0;  // @17_518bc0
  X0[3] = 0;  // @18_518bc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; }));  // @19_518bc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L518c3c;  // @20_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_518bc0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @23_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @24_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[1], (u32)(6942984));  // @26_518bc0
  ecx = edx = 0;  // @27_518bc0
  PV[2] = (u32)(eax);  // @28_518bc0
  ecx = edi;  // @29_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[2]);  // @30_518bc0
  ecx = edx = 0;  // @31_518bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 5665), &v, sizeof v); }  // @32_518bc0
  goto L518c5b;  // @33_518bc0
  L518c3c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5665), sizeof v); (u32)v; });  // @35_518bc0
  FL[2] = (ecx & ecx);  // @36_518bc0
  if (FL[2] == 0) goto L518c5b;  // @37_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @38_518bc0
  PV[3] = (u32)(ecx);  // @39_518bc0
  ecx = edi;  // @40_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 748)))(ecx, PV[3]);  // @41_518bc0
  ecx = edx = 0;  // @42_518bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5665), &v, sizeof v); }  // @43_518bc0
  L518c5b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @45_518bc0
  X1[0] = 0;  // @46_518bc0
  X1[1] = 0;  // @47_518bc0
  X1[2] = 0;  // @48_518bc0
  X1[3] = 0;  // @49_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 40) + 0), 4); v; });  // @50_518bc0
  X0[1] = 0;  // @51_518bc0
  X0[2] = 0;  // @52_518bc0
  X0[3] = 0;  // @53_518bc0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @54_518bc0
  if ((!(FA >= FB))) goto L518c72;  // @55_518bc0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 5705), &v, sizeof v); }  // @56_518bc0
  L518c72:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5705), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @58_518bc0
  if (FL[0] == FL[1]) goto L518ead;  // @59_518bc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; }));  // @60_518bc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L518d89;  // @61_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @63_518bc0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @64_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @65_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[4], (u32)(6942992));  // @67_518bc0
  ecx = edx = 0;  // @68_518bc0
  PV[5] = (u32)(eax);  // @69_518bc0
  ecx = edi;  // @70_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[5]);  // @71_518bc0
  ecx = edx = 0;  // @72_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_518bc0
  PV[6] = (u32)(eax);  // @74_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @75_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[6]);  // @77_518bc0
  ecx = edx = 0;  // @78_518bc0
  edx = eax;  // @79_518bc0
  FL[2] = (edx & edx);  // @80_518bc0
  if (FL[2] == 0) goto L518cf1;  // @81_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 481) + 0), 4); v; });  // @82_518bc0
  X0[1] = 0;  // @83_518bc0
  X0[2] = 0;  // @84_518bc0
  X0[3] = 0;  // @85_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @86_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @87_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 36) + 0), 4); v; })));  // @88_518bc0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @89_518bc0
  eax = ecx;  // @90_518bc0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 100), sizeof v); (u32)v; }));  // @91_518bc0
  FL[3] = eax;  // @92_518bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 96), &v, sizeof v); }  // @93_518bc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 100), &v, sizeof v); }  // @94_518bc0
  L518cf1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @98_518bc0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6942712), (u32)(681));  // @99_518bc0
  ecx = edx = 0;  // @100_518bc0
  STF((u32)(EBP - 4), FS[0]);  // @101_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @102_518bc0
  X0[1] = 0;  // @103_518bc0
  X0[2] = 0;  // @104_518bc0
  X0[3] = 0;  // @105_518bc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; }));  // @106_518bc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L518ea3;  // @107_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @109_518bc0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @110_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @111_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[7], (u32)(6943012));  // @113_518bc0
  ecx = edx = 0;  // @114_518bc0
  PV[8] = (u32)(eax);  // @115_518bc0
  ecx = edi;  // @116_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[8]);  // @117_518bc0
  ecx = edx = 0;  // @118_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @119_518bc0
  PV[9] = (u32)(eax);  // @120_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @121_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[9]);  // @123_518bc0
  ecx = edx = 0;  // @124_518bc0
  esi = eax;  // @125_518bc0
  FL[2] = (esi & esi);  // @126_518bc0
  if (FL[2] == 0) goto L518ea3;  // @127_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @128_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 448), sizeof v); (u32)v; });  // @130_518bc0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6942712), (u32)(686));  // @131_518bc0
  ecx = edx = 0;  // @132_518bc0
  STF((u32)(EBP - 4), FS[0]);  // @133_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @134_518bc0
  X0[1] = 0;  // @135_518bc0
  X0[2] = 0;  // @136_518bc0
  X0[3] = 0;  // @137_518bc0
  goto L518e86;  // @138_518bc0
  L518d89:;
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; }));  // @140_518bc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L518ead;  // @141_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @142_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @143_518bc0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @144_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @145_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[10], (u32)(6943020));  // @147_518bc0
  ecx = edx = 0;  // @148_518bc0
  PV[11] = (u32)(eax);  // @149_518bc0
  ecx = edi;  // @150_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[11]);  // @151_518bc0
  ecx = edx = 0;  // @152_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @153_518bc0
  PV[12] = (u32)(eax);  // @154_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @155_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @156_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[12]);  // @157_518bc0
  ecx = edx = 0;  // @158_518bc0
  edx = eax;  // @159_518bc0
  FL[2] = (edx & edx);  // @160_518bc0
  if (FL[2] == 0) goto L518dfb;  // @161_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 481) + 0), 4); v; });  // @162_518bc0
  X0[1] = 0;  // @163_518bc0
  X0[2] = 0;  // @164_518bc0
  X0[3] = 0;  // @165_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @166_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @167_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 36) + 0), 4); v; })));  // @168_518bc0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @169_518bc0
  eax = ecx;  // @170_518bc0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 100), sizeof v); (u32)v; }));  // @171_518bc0
  FL[3] = eax;  // @172_518bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 96), &v, sizeof v); }  // @173_518bc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 100), &v, sizeof v); }  // @174_518bc0
  L518dfb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @176_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @178_518bc0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6942712), (u32)(699));  // @179_518bc0
  ecx = edx = 0;  // @180_518bc0
  STF((u32)(EBP - 4), FS[0]);  // @181_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @182_518bc0
  X0[1] = 0;  // @183_518bc0
  X0[2] = 0;  // @184_518bc0
  X0[3] = 0;  // @185_518bc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; }));  // @186_518bc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L518ea3;  // @187_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @189_518bc0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @190_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @191_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[13], (u32)(6943012));  // @193_518bc0
  ecx = edx = 0;  // @194_518bc0
  PV[14] = (u32)(eax);  // @195_518bc0
  ecx = edi;  // @196_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[14]);  // @197_518bc0
  ecx = edx = 0;  // @198_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @199_518bc0
  PV[15] = (u32)(eax);  // @200_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @201_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[15]);  // @203_518bc0
  ecx = edx = 0;  // @204_518bc0
  esi = eax;  // @205_518bc0
  FL[2] = (esi & esi);  // @206_518bc0
  if (FL[2] == 0) goto L518ea3;  // @207_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @208_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 448), sizeof v); (u32)v; });  // @210_518bc0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6942712), (u32)(704));  // @211_518bc0
  ecx = edx = 0;  // @212_518bc0
  STF((u32)(EBP - 4), FS[0]);  // @213_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @214_518bc0
  X0[1] = 0;  // @215_518bc0
  X0[2] = 0;  // @216_518bc0
  X0[3] = 0;  // @217_518bc0
  L518e86:;
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; })));  // @219_518bc0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818448) + 0), 4); v; })));  // @220_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; })));  // @221_518bc0
  __builtin_memcpy((void *)((u32)(esi + 120) + 0), &X0[0], 4);  // @222_518bc0
  L518ea3:;
  X1[0] = 0;  // @224_518bc0
  X1[1] = 0;  // @225_518bc0
  X1[2] = 0;  // @226_518bc0
  X1[3] = 0;  // @227_518bc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5705), &v, sizeof v); }  // @228_518bc0
  L518ead:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6943140) + 0), 4); v; });  // @230_518bc0
  X0[1] = 0;  // @231_518bc0
  X0[2] = 0;  // @232_518bc0
  X0[3] = 0;  // @233_518bc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 703) + 0), 4); v; }));  // @234_518bc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L518f20;  // @235_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @236_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 36) + 0), 4); v; });  // @237_518bc0
  X0[1] = 0;  // @238_518bc0
  X0[2] = 0;  // @239_518bc0
  X0[3] = 0;  // @240_518bc0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @241_518bc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @242_518bc0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @243_518bc0
  if (__builtin_parity(FL[2] & 0xff)) goto L518f20;  // @244_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @245_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @246_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @247_518bc0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6942712), (u32)(712));  // @248_518bc0
  ecx = edx = 0;  // @249_518bc0
  STF((u32)(EBP - 4), FS[0]);  // @250_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @251_518bc0
  X0[1] = 0;  // @252_518bc0
  X0[2] = 0;  // @253_518bc0
  X0[3] = 0;  // @254_518bc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6835428) + 0), 4); v; }));  // @255_518bc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L518f20;  // @256_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @257_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @258_518bc0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @259_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @260_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @261_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[16], (u32)(6943044));  // @262_518bc0
  ecx = edx = 0;  // @263_518bc0
  PV[17] = (u32)(eax);  // @264_518bc0
  ecx = edi;  // @265_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[17]);  // @266_518bc0
  ecx = edx = 0;  // @267_518bc0
  L518f20:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5643), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @269_518bc0
  if (FL[0] == FL[1]) goto L519032;  // @270_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5693) + 0), 4); v; });  // @271_518bc0
  X0[1] = 0;  // @272_518bc0
  X0[2] = 0;  // @273_518bc0
  X0[3] = 0;  // @274_518bc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @275_518bc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @276_518bc0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @277_518bc0
  if (__builtin_parity(FL[2] & 0xff)) goto L519032;  // @278_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5689), sizeof v); (u32)v; });  // @279_518bc0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5701), sizeof v); (u32)v; });  // @280_518bc0
  if ((s32)FL[0] > (s32)FL[1]) goto L519032;  // @281_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @282_518bc0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @283_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @284_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @285_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[18], (u32)(6943052));  // @286_518bc0
  ecx = edx = 0;  // @287_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @288_518bc0
  ecx = edi;  // @289_518bc0
  PV[19] = (u32)(eax);  // @290_518bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 5681), &v, sizeof v); }  // @291_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 744)))(ecx, PV[19]);  // @292_518bc0
  ecx = edx = 0;  // @293_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @294_518bc0
  PV[20] = (u32)(eax);  // @295_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @296_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @297_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[20]);  // @298_518bc0
  ecx = edx = 0;  // @299_518bc0
  esi = eax;  // @300_518bc0
  FL[2] = (esi & esi);  // @301_518bc0
  if (FL[2] == 0) goto L51902c;  // @302_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @303_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 497) + 0), 4); v; });  // @304_518bc0
  X0[1] = 0;  // @305_518bc0
  X0[2] = 0;  // @306_518bc0
  X0[3] = 0;  // @307_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5693) + 0), 4); v; })));  // @308_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @309_518bc0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @310_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @311_518bc0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6942712), (u32)(729));  // @312_518bc0
  ecx = edx = 0;  // @313_518bc0
  FS[0] = (FS[0] * LDF((u32)(6791816)));  // @314_518bc0
  FS[0] = (LDF((u32)(EBP - 4)) - FS[0]);  // @315_518bc0
  STF((u32)(esi + 132), FS[0]);  // @316_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @317_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @318_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @319_518bc0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6942712), (u32)(730));  // @320_518bc0
  ecx = edx = 0;  // @321_518bc0
  FS[0] = (FS[0] - LDF((u32)(6835428)));  // @322_518bc0
  FS[0] = (FS[0] * LDF((u32)(6802752)));  // @323_518bc0
  STF((u32)(EBP - 4), FS[0]);  // @324_518bc0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @325_518bc0
  eax = ecx;  // @326_518bc0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; }));  // @327_518bc0
  FL[3] = eax;  // @328_518bc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @329_518bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @330_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 5697) + 0), 4); v; });  // @331_518bc0
  X0[1] = 0;  // @332_518bc0
  X0[2] = 0;  // @333_518bc0
  X0[3] = 0;  // @334_518bc0
  PV[21] = (u32)(ecx);  // @335_518bc0
  ecx = esi;  // @336_518bc0
  PV[22] = X0[0];  // @337_518bc0
  eax = ext_441890_thiscall2(ecx, PV[22]);  // @338_518bc0
    // @339_518bc0
  L51902c:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5689), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 5689), &v, sizeof v); }  // @341_518bc0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5689), sizeof v); (u32)v; });  // @342_518bc0
  L519032:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5635), sizeof v); (u32)v; });  // @344_518bc0
  eax = (eax - (u32)(0));  // @345_518bc0
  FL[3] = eax;  // @346_518bc0
  if (FL[3] == 0) goto L519212;  // @347_518bc0
  eax = (eax - (u32)(1));  // @348_518bc0
  FL[3] = eax;  // @349_518bc0
  if (FL[3] == 0) goto L519195;  // @350_518bc0
  eax = (eax - (u32)(1));  // @351_518bc0
  FL[3] = eax;  // @352_518bc0
  if (FL[3] != 0) goto L51926f;  // @353_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5669), sizeof v); (u32)v; });  // @354_518bc0
  FL[2] = (ecx & ecx);  // @355_518bc0
  if (FL[2] == 0) goto L519072;  // @356_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @357_518bc0
  PV[23] = (u32)(ecx);  // @358_518bc0
  ecx = edi;  // @359_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 748)))(ecx, PV[23]);  // @360_518bc0
  ecx = edx = 0;  // @361_518bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5669), &v, sizeof v); }  // @362_518bc0
  L519072:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5673), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @364_518bc0
  if (FL[0] != FL[1]) goto L5190a7;  // @365_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @366_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @367_518bc0
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @368_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @369_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @370_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[24], (u32)(6943076));  // @371_518bc0
  ecx = edx = 0;  // @372_518bc0
  PV[25] = (u32)(eax);  // @373_518bc0
  ecx = edi;  // @374_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[25]);  // @375_518bc0
  ecx = edx = 0;  // @376_518bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 5673), &v, sizeof v); }  // @377_518bc0
  L5190a7:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5677), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @379_518bc0
  if (FL[0] != FL[1]) goto L5190dc;  // @380_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @381_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @382_518bc0
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @383_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @384_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @385_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[26], (u32)(6943084));  // @386_518bc0
  ecx = edx = 0;  // @387_518bc0
  PV[27] = (u32)(eax);  // @388_518bc0
  ecx = edi;  // @389_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[27]);  // @390_518bc0
  ecx = edx = 0;  // @391_518bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 5677), &v, sizeof v); }  // @392_518bc0
  L5190dc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @394_518bc0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @395_518bc0
  X1[1] = 0;  // @396_518bc0
  X1[2] = 0;  // @397_518bc0
  X1[3] = 0;  // @398_518bc0
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5673), sizeof v); (u32)v; });  // @399_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 36) + 0), 4); v; });  // @400_518bc0
  X0[1] = 0;  // @401_518bc0
  X0[2] = 0;  // @402_518bc0
  X0[3] = 0;  // @403_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @404_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; })));  // @405_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @406_518bc0
  { float a_ = U2F(X1[0]), b_ = U2F(X0[0]); X1[0] = (a_ < b_) ? X1[0] : F2U(b_); }  // @407_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @408_518bc0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @409_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[28]);  // @410_518bc0
  ecx = edx = 0;  // @411_518bc0
  FL[2] = (eax & eax);  // @412_518bc0
  if (FL[2] == 0) goto L519144;  // @413_518bc0
  { u32 v = (u32)((u32)(1050253722)); __builtin_memcpy((void *)(u32)(eax + 120), &v, sizeof v); }  // @414_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5685), sizeof v); (u32)v; });  // @415_518bc0
  ecx = edx;  // @416_518bc0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 100), sizeof v); (u32)v; }));  // @417_518bc0
  FL[3] = ecx;  // @418_518bc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 96), &v, sizeof v); }  // @419_518bc0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 100), &v, sizeof v); }  // @420_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 497) + 0), 4); v; });  // @421_518bc0
  X0[1] = 0;  // @422_518bc0
  X0[2] = 0;  // @423_518bc0
  X0[3] = 0;  // @424_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @425_518bc0
  __builtin_memcpy((void *)((u32)(eax + 132) + 0), &X0[0], 4);  // @426_518bc0
  L519144:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @428_518bc0
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5677), sizeof v); (u32)v; });  // @429_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @430_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @431_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[29]);  // @432_518bc0
  ecx = edx = 0;  // @433_518bc0
  FL[2] = (eax & eax);  // @434_518bc0
  if (FL[2] == 0) goto L51926f;  // @435_518bc0
  { u32 v = (u32)((u32)(1028443341)); __builtin_memcpy((void *)(u32)(eax + 120), &v, sizeof v); }  // @436_518bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5685), sizeof v); (u32)v; });  // @437_518bc0
  ecx = edx;  // @438_518bc0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 100), sizeof v); (u32)v; }));  // @439_518bc0
  FL[3] = ecx;  // @440_518bc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 96), &v, sizeof v); }  // @441_518bc0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 100), &v, sizeof v); }  // @442_518bc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 497) + 0), 4); v; });  // @443_518bc0
  X0[1] = 0;  // @444_518bc0
  X0[2] = 0;  // @445_518bc0
  X0[3] = 0;  // @446_518bc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @447_518bc0
  __builtin_memcpy((void *)((u32)(eax + 132) + 0), &X0[0], 4);  // @448_518bc0
  return eax;  // @449_518bc0
  L519195:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5673), sizeof v); (u32)v; });  // @451_518bc0
  FL[2] = (ecx & ecx);  // @452_518bc0
  if (FL[2] == 0) goto L5191b4;  // @453_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @454_518bc0
  PV[30] = (u32)(ecx);  // @455_518bc0
  ecx = edi;  // @456_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 748)))(ecx, PV[30]);  // @457_518bc0
  ecx = edx = 0;  // @458_518bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5673), &v, sizeof v); }  // @459_518bc0
  L5191b4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5677), sizeof v); (u32)v; });  // @461_518bc0
  FL[2] = (ecx & ecx);  // @462_518bc0
  if (FL[2] == 0) goto L5191d3;  // @463_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @464_518bc0
  PV[31] = (u32)(ecx);  // @465_518bc0
  ecx = edi;  // @466_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 748)))(ecx, PV[31]);  // @467_518bc0
  ecx = edx = 0;  // @468_518bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5677), &v, sizeof v); }  // @469_518bc0
  L5191d3:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5669), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @471_518bc0
  if (FL[0] != FL[1]) goto L51926f;  // @472_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @473_518bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @474_518bc0
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 303), sizeof v); (u32)v; });  // @475_518bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @476_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @477_518bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[32], (u32)(6943064));  // @478_518bc0
  ecx = edx = 0;  // @479_518bc0
  PV[33] = (u32)(eax);  // @480_518bc0
  ecx = edi;  // @481_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 744)))(ecx, PV[33]);  // @482_518bc0
  ecx = edx = 0;  // @483_518bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 5669), &v, sizeof v); }  // @484_518bc0
  return eax;  // @485_518bc0
  L519212:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5669), sizeof v); (u32)v; });  // @487_518bc0
  FL[2] = (ecx & ecx);  // @488_518bc0
  if (FL[2] == 0) goto L519231;  // @489_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @490_518bc0
  PV[34] = (u32)(ecx);  // @491_518bc0
  ecx = edi;  // @492_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 748)))(ecx, PV[34]);  // @493_518bc0
  ecx = edx = 0;  // @494_518bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5669), &v, sizeof v); }  // @495_518bc0
  L519231:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5673), sizeof v); (u32)v; });  // @497_518bc0
  FL[2] = (ecx & ecx);  // @498_518bc0
  if (FL[2] == 0) goto L519250;  // @499_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @500_518bc0
  PV[35] = (u32)(ecx);  // @501_518bc0
  ecx = edi;  // @502_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 748)))(ecx, PV[35]);  // @503_518bc0
  ecx = edx = 0;  // @504_518bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5673), &v, sizeof v); }  // @505_518bc0
  L519250:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5677), sizeof v); (u32)v; });  // @507_518bc0
  FL[2] = (ecx & ecx);  // @508_518bc0
  if (FL[2] == 0) goto L51926f;  // @509_518bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @510_518bc0
  PV[36] = (u32)(ecx);  // @511_518bc0
  ecx = edi;  // @512_518bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 748)))(ecx, PV[36]);  // @513_518bc0
  ecx = edx = 0;  // @514_518bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 5677), &v, sizeof v); }  // @515_518bc0
  L51926f:;
  L519270:;
  return eax;  // @518_518bc0
}
PCREG(518bc0, lifted_518bc0);

