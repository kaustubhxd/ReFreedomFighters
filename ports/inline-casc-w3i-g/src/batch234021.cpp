// batch234021.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" long double FASTCALL ext_532850_fastcall2_ld(u32, u32) __asm__("ext_532850");
extern "C" u32 THISCALL ext_52e320_thiscall2(u32, u32) __asm__("ext_52e320");
extern "C" u32 THISCALL ext_530940_thiscall3(u32, u32, u32) __asm__("ext_530940");
extern "C" u32 THISCALL ext_530a40_thiscall1(u32) __asm__("ext_530a40");
extern "C" u32 THISCALL ext_531070_thiscall2(u32, u32) __asm__("ext_531070");
extern "C" u32 THISCALL ext_531740_thiscall3(u32, u32, u32) __asm__("ext_531740");
extern "C" u32 THISCALL ext_531c40_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_531c40");
extern "C" u32 THISCALL ext_5320b0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5320b0");
extern "C" u32 THISCALL ext_532770_thiscall4(u32, u32, u32, u32) __asm__("ext_532770");
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

extern "C" u32 THISCALL lifted_530130(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
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
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_530130
  ebx = ecx;  // @1_530130
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @2_530130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_530130
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @4_530130
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @5_530130
  FL[2] = (ebx & ebx);  // @6_530130
  if (FL[2] == 0) goto L53016f;  // @7_530130
  eax = (u32)(ebx + 150);  // @8_530130
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @9_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @10_530130
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @11_530130
  L53016f:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_530130
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @14_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @15_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @16_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 74), &v, sizeof v); }  // @17_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @18_530130
  ecx = ebx;  // @19_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @20_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @21_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @22_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @23_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 58), &v, sizeof v); }  // @24_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @25_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @26_530130
  eax = (u32)(EBP - 76);  // @27_530130
  PV[0] = (u32)(esi);  // @28_530130
  PV[1] = (u32)(eax);  // @29_530130
  eax = ext_530940_thiscall3(ecx, PV[1], PV[0]);  // @30_530130
  ecx = edx = 0;  // @31_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @32_530130
  ecx = ebx;  // @33_530130
  PV[2] = (u32)(esi);  // @34_530130
  eax = (u32)(EBP - 60);  // @35_530130
  PV[3] = (u32)(eax);  // @36_530130
  eax = ext_530940_thiscall3(ecx, PV[3], PV[2]);  // @37_530130
  ecx = edx = 0;  // @38_530130
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 56), sizeof v); (u32)v; });  // @39_530130
  edi = (edi - esi);  // @40_530130
  FL[3] = edi;  // @41_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @42_530130
  ecx = edi;  // @43_530130
  if (FL[3] == 0) goto L5301e4;  // @44_530130
  ecx = (ecx - 1);  // @45_530130
  FL[3] = ecx;  // @46_530130
  eax = (u32)(8);  // @47_530130
  eax = (eax << (ecx & 0xff));  // @48_530130
  FL[3] = eax;  // @49_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @50_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @51_530130
  eax = (u32)(1);  // @52_530130
  eax = (eax << (ecx & 0xff));  // @53_530130
  FL[3] = eax;  // @54_530130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @55_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @56_530130
  goto L5301ef;  // @57_530130
  L5301e4:;
  ecx = (u32)(1);  // @59_530130
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @60_530130
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @61_530130
  L5301ef:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @63_530130
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @64_530130
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @65_530130
  eax = (u32)((s32)eax * (s32)ecx);  // @66_530130
  FL[3] = eax;  // @67_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @68_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 74), sizeof v); (u32)v; });  // @69_530130
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @70_530130
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @71_530130
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; }));  // @72_530130
  FL[3] = eax;  // @73_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 74), &v, sizeof v); }  // @74_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @75_530130
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @76_530130
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @77_530130
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }));  // @78_530130
  FL[3] = eax;  // @79_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @80_530130
  FL[2] = (edi & edi);  // @81_530130
  if (FL[2] == 0) goto L53023f;  // @82_530130
  ecx = (u32)(edi - 1);  // @83_530130
  eax = (u32)(8);  // @84_530130
  eax = (eax << (ecx & 0xff));  // @85_530130
  FL[3] = eax;  // @86_530130
  ecx = (u32)(edi - 1);  // @87_530130
  edi = (u32)(1);  // @88_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @89_530130
  edi = (edi << (ecx & 0xff));  // @90_530130
  FL[3] = edi;  // @91_530130
  ecx = eax;  // @92_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @93_530130
  goto L530249;  // @94_530130
  L53023f:;
  ecx = (u32)(1);  // @96_530130
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @97_530130
  edi = ecx;  // @98_530130
  L530249:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @100_530130
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @101_530130
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @102_530130
  eax = (u32)((s32)eax * (s32)ecx);  // @103_530130
  FL[3] = eax;  // @104_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @105_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @106_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 58), sizeof v); (u32)v; });  // @107_530130
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @108_530130
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @109_530130
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }));  // @110_530130
  FL[3] = eax;  // @111_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @112_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 58), &v, sizeof v); }  // @113_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @114_530130
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @115_530130
  { s32 d_ = (s32)(edi); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @116_530130
  eax = (u32)((s32)eax * (s32)edi);  // @117_530130
  FL[3] = eax;  // @118_530130
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @119_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @120_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @121_530130
  FL[2] = (edi & edi);  // @122_530130
  if (FL[2] == 0) goto L53077e;  // @123_530130
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @124_530130
  if (FL[0] == FL[1]) goto L53077e;  // @125_530130
  PV[4] = (u32)(esi);  // @126_530130
  eax = (u32)(EBP - 76);  // @127_530130
  PV[5] = (u32)(eax);  // @128_530130
  ecx = (u32)(EBP - 52);  // @129_530130
  eax = ext_531740_thiscall3(ecx, PV[5], PV[4]);  // @130_530130
  ecx = edx = 0;  // @131_530130
  ecx = (u32)(EBP - 52);  // @132_530130
  eax = ext_530a40_thiscall1(ecx);  // @133_530130
  ecx = edx = 0;  // @134_530130
  ecx = (ecx & 0xffff0000u) | (((eax & 0xffff)) & 0xffff);  // @135_530130
  eax = (u32)(edi - 1);  // @136_530130
  ecx = (ecx & 0xffff0000u) | ((((ecx & 0xffff) + (eax & 0xffff))) & 0xffff);  // @137_530130
  FL[3] = (ecx & 0xffff);  // @138_530130
  eax = (ecx & 0xffff);  // @139_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @140_530130
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @141_530130
  if (FL[2] != 0) goto L5302d4;  // @142_530130
  eax = (u32)(65535);  // @143_530130
  ext_633654(G(u32, 0x6f5630));  // @144_530130
  return eax;  // @145_530130
  L5302d4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @147_530130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @148_530130
  eax = (eax & 0xffff);  // @149_530130
  edi = (u32)((s32)eax * (s32)(u32)(21));  // @150_530130
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; }));  // @151_530130
  FL[3] = edi;  // @152_530130
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 10), &v, sizeof v); }  // @153_530130
  FS[0] = ext_532850_fastcall2_ld(ecx, edx);  // @154_530130
  ecx = edx = 0;  // @155_530130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @156_530130
  eax = 0;  // @157_530130
  FL[3] = eax;  // @158_530130
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @159_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @160_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @161_530130
  STF((u32)(edi + 10), FS[0]);  // @162_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @163_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 38), sizeof v); (u32)v; });  // @164_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 6), &v, sizeof v); }  // @165_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @166_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @167_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30), sizeof v); (u32)v; });  // @168_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @169_530130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @170_530130
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 3), &v, sizeof v); }  // @171_530130
  L530325:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @173_530130
  X1[1] = 0;  // @174_530130
  X1[2] = 0;  // @175_530130
  X1[3] = 0;  // @176_530130
  X0[0] = 0;  // @177_530130
  X0[1] = 0;  // @178_530130
  X0[2] = 0;  // @179_530130
  X0[3] = 0;  // @180_530130
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @181_530130
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @182_530130
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @183_530130
  if (__builtin_parity(FL[2] & 0xff)) goto L530344;  // @184_530130
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 10) + 0), 4); v; });  // @185_530130
  X0[1] = 0;  // @186_530130
  X0[2] = 0;  // @187_530130
  X0[3] = 0;  // @188_530130
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @189_530130
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5305f8;  // @190_530130
  L530344:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @192_530130
  esi = (u32)(edi + 4);  // @193_530130
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (eax & 0xffff);  // @194_530130
  if (FL[0] != FL[1]) goto L53036e;  // @195_530130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @196_530130
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 6), sizeof v); (u32)v; }); FL[1] = (eax & 0xffff);  // @197_530130
  if (FL[0] != FL[1]) goto L53036e;  // @198_530130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @199_530130
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = (eax & 0xffff);  // @200_530130
  if (FL[0] != FL[1]) goto L53036e;  // @201_530130
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3), sizeof v); (u32)v; });  // @202_530130
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @203_530130
  if (FL[0] == FL[1]) goto L530601;  // @204_530130
  L53036e:;
  FL[0] = ecx; FL[1] = (u32)(2);  // @206_530130
  if (FL[0] != FL[1]) goto L53038a;  // @207_530130
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @208_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @209_530130
  ecx = ebx;  // @210_530130
  PV[7] = (u32)(eax);  // @211_530130
  PV[8] = (u32)(esi);  // @212_530130
  eax = ext_532770_thiscall4(ecx, PV[8], PV[7], PV[6]);  // @213_530130
  ecx = edx = 0;  // @214_530130
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @215_530130
  if (FL[2] == 0) goto L5305c9;  // @216_530130
  L53038a:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @218_530130
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @219_530130
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @220_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @221_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @222_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @223_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @224_530130
  eax = (u32)(EBP - 60);  // @225_530130
  PV[9] = (u32)(eax);  // @226_530130
  eax = (u32)(EBP - 52);  // @227_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 26), &v, sizeof v); }  // @228_530130
  PV[10] = (u32)(eax);  // @229_530130
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @230_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @231_530130
  ecx = ebx;  // @232_530130
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @233_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @234_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @235_530130
  eax = ext_531c40_thiscall6(ecx, PV[12], PV[11], PV[10], (u32)(2), PV[9]);  // @236_530130
  ecx = edx = 0;  // @237_530130
  ecx = (u32)(65535);  // @238_530130
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @239_530130
  if (FL[0] == FL[1]) goto L530768;  // @240_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @241_530130
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @242_530130
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @243_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @244_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @245_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @246_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @247_530130
  eax = (u32)(EBP - 60);  // @248_530130
  PV[13] = (u32)(eax);  // @249_530130
  eax = (u32)(EBP - 52);  // @250_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 26), &v, sizeof v); }  // @251_530130
  PV[14] = (u32)(eax);  // @252_530130
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @253_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @254_530130
  ecx = ebx;  // @255_530130
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @256_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @257_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @258_530130
  eax = ext_531c40_thiscall6(ecx, PV[16], PV[15], PV[14], (u32)(3), PV[13]);  // @259_530130
  ecx = edx = 0;  // @260_530130
  ecx = (u32)(65535);  // @261_530130
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @262_530130
  if (FL[0] == FL[1]) goto L530768;  // @263_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @264_530130
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @265_530130
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @266_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @267_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @268_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @269_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @270_530130
  eax = (u32)(EBP - 60);  // @271_530130
  PV[17] = (u32)(eax);  // @272_530130
  eax = (u32)(EBP - 52);  // @273_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 26), &v, sizeof v); }  // @274_530130
  PV[18] = (u32)(eax);  // @275_530130
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @276_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @277_530130
  ecx = ebx;  // @278_530130
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @279_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @280_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @281_530130
  eax = ext_531c40_thiscall6(ecx, PV[20], PV[19], PV[18], (u32)(0), PV[17]);  // @282_530130
  ecx = edx = 0;  // @283_530130
  ecx = (u32)(65535);  // @284_530130
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @285_530130
  if (FL[0] == FL[1]) goto L530768;  // @286_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @287_530130
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @288_530130
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @289_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @290_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @291_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @292_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @293_530130
  eax = (u32)(EBP - 60);  // @294_530130
  PV[21] = (u32)(eax);  // @295_530130
  eax = (u32)(EBP - 52);  // @296_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 26), &v, sizeof v); }  // @297_530130
  PV[22] = (u32)(eax);  // @298_530130
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @299_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @300_530130
  ecx = ebx;  // @301_530130
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @302_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @303_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @304_530130
  eax = ext_531c40_thiscall6(ecx, PV[24], PV[23], PV[22], (u32)(1), PV[21]);  // @305_530130
  ecx = edx = 0;  // @306_530130
  ecx = (u32)(65535);  // @307_530130
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @308_530130
  if (FL[0] == FL[1]) goto L530768;  // @309_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @310_530130
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @311_530130
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @312_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @313_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @314_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @315_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @316_530130
  eax = (u32)(EBP - 60);  // @317_530130
  PV[25] = (u32)(eax);  // @318_530130
  eax = (u32)(EBP - 52);  // @319_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 26), &v, sizeof v); }  // @320_530130
  PV[26] = (u32)(eax);  // @321_530130
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @322_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @323_530130
  ecx = ebx;  // @324_530130
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @325_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @326_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @327_530130
  eax = ext_531c40_thiscall6(ecx, PV[28], PV[27], PV[26], (u32)(4), PV[25]);  // @328_530130
  ecx = edx = 0;  // @329_530130
  ecx = (u32)(65535);  // @330_530130
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @331_530130
  if (FL[0] == FL[1]) goto L530768;  // @332_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @333_530130
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @334_530130
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @335_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @336_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @337_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @338_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @339_530130
  eax = (u32)(EBP - 60);  // @340_530130
  PV[29] = (u32)(eax);  // @341_530130
  eax = (u32)(EBP - 52);  // @342_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 26), &v, sizeof v); }  // @343_530130
  PV[30] = (u32)(eax);  // @344_530130
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @345_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @346_530130
  ecx = ebx;  // @347_530130
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @348_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @349_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @350_530130
  eax = ext_531c40_thiscall6(ecx, PV[32], PV[31], PV[30], (u32)(5), PV[29]);  // @351_530130
  ecx = edx = 0;  // @352_530130
  ecx = (u32)(65535);  // @353_530130
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @354_530130
  if (FL[0] == FL[1]) goto L530768;  // @355_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @356_530130
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @357_530130
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @358_530130
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @359_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @360_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @361_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @362_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @363_530130
  eax = (u32)(EBP - 60);  // @364_530130
  PV[33] = (u32)(eax);  // @365_530130
  eax = (u32)(EBP - 52);  // @366_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 26), &v, sizeof v); }  // @367_530130
  PV[34] = (u32)(eax);  // @368_530130
  PV[35] = (u32)(esi);  // @369_530130
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @370_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @371_530130
  ecx = ebx;  // @372_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @373_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @374_530130
  eax = ext_5320b0_thiscall5(ecx, PV[36], PV[35], PV[34], PV[33]);  // @375_530130
  ecx = edx = 0;  // @376_530130
  ecx = (u32)(65535);  // @377_530130
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @378_530130
  if (FL[0] == FL[1]) goto L530768;  // @379_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; })) & 0xffff);  // @380_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @381_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 58), sizeof v); (u32)v; })) & 0xffff);  // @382_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @383_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; })) & 0xffff);  // @384_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @385_530130
  goto L5305cc;  // @386_530130
  L5305c9:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @388_530130
  L5305cc:;
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @390_530130
  eax = 0;  // @391_530130
  FL[3] = eax;  // @392_530130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @393_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @394_530130
  eax = (edx & 0xffff);  // @395_530130
  edi = (u32)((s32)eax * (s32)(u32)(21));  // @396_530130
  eax = 0;  // @397_530130
  FL[3] = eax;  // @398_530130
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @399_530130
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; }));  // @400_530130
  FL[3] = edi;  // @401_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 18), &v, sizeof v); }  // @402_530130
  FL[2] = ((edx & 0xffff) & (edx & 0xffff));  // @403_530130
  if (FL[2] == 0) goto L53060b;  // @404_530130
  goto L530325;  // @405_530130
  L5305f8:;
  { u32 v = (u32)((u32)(65535)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @407_530130
  goto L53060b;  // @408_530130
  L530601:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @410_530130
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @411_530130
  L53060b:;
  FL[0] = ecx; FL[1] = (u32)(1);  // @413_530130
  if (FL[0] == FL[1]) goto L530619;  // @414_530130
  FL[0] = ecx; FL[1] = (u32)(2);  // @415_530130
  if (FL[0] != FL[1]) goto L530751;  // @416_530130
  L530619:;
  FL[2] = ((edx & 0xffff) & (edx & 0xffff));  // @418_530130
  if (FL[2] == 0) goto L530751;  // @419_530130
  L530622:;
  eax = (edx & 0xffff);  // @421_530130
  edi = (u32)((s32)eax * (s32)(u32)(21));  // @422_530130
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; }));  // @423_530130
  FL[3] = edi;  // @424_530130
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }) & (u32)(1));  // @425_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 14), sizeof v); (u32)v; });  // @426_530130
  if (FL[2] == 0) goto L530643;  // @427_530130
  eax = (eax << (u32)(5));  // @428_530130
  FL[3] = eax;  // @429_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 158), sizeof v); (u32)v; });  // @430_530130
  L530643:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @432_530130
  ecx = 0;  // @433_530130
  FL[3] = ecx;  // @434_530130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 56), sizeof v); (u32)v; });  // @435_530130
  eax = (eax - 1);  // @436_530130
  FL[3] = eax;  // @437_530130
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @438_530130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @439_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @440_530130
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7347036), sizeof v); (u32)v; }); FL[1] = (ecx & 0xff);  // @441_530130
  if (FL[0] != FL[1]) goto L53067a;  // @442_530130
  FL[0] = esi; FL[1] = eax;  // @443_530130
  if (FL[0] != FL[1]) goto L53067a;  // @444_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @445_530130
  edx = (u32)(65535);  // @446_530130
  ecx = (u32)(eax + eax*2);  // @447_530130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 90), sizeof v); (u32)v; });  // @448_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + ecx*4 + 2), &v, sizeof v); }  // @449_530130
  goto L530745;  // @450_530130
  L53067a:;
  eax = (eax | (u32)(4294967295));  // @452_530130
  FL[3] = eax;  // @453_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @454_530130
  L530681:;
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 58), &v, sizeof v); }  // @456_530130
  L530685:;
  esi = (esi & 0xffff0000u) | (((eax & 0xffff)) & 0xffff);  // @458_530130
  { u16 v = (u16)((esi & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @459_530130
  L530690:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @461_530130
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @462_530130
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 6), sizeof v); (u32)v; });  // @463_530130
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @464_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @465_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @466_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xffff);  // @467_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 30), &v, sizeof v); }  // @468_530130
  eax = (u32)(EBP - 60);  // @469_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 26), &v, sizeof v); }  // @470_530130
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @471_530130
  ecx = (u32)(EBP - 52);  // @472_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @473_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @474_530130
  PV[37] = (u32)(eax);  // @475_530130
  if (FL[0] != FL[1]) goto L5306cf;  // @476_530130
  eax = ext_52e320_thiscall2(ecx, PV[37]);  // @477_530130
  ecx = edx = 0;  // @478_530130
  goto L5306d4;  // @479_530130
  L5306cf:;
  eax = ext_531070_thiscall2(ecx, PV[37]);  // @481_530130
  ecx = edx = 0;  // @482_530130
  L5306d4:;
  eax = (eax & 0xffff);  // @484_530130
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @485_530130
  if (FL[2] == 0) goto L530704;  // @486_530130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @487_530130
  edx = (u32)(65535);  // @488_530130
  eax = (eax & 0xffff);  // @489_530130
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }); FL[1] = ecx;  // @490_530130
  if (FL[0] != FL[1]) goto L5306f9;  // @491_530130
  ecx = (u32)(eax + eax*2);  // @492_530130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 90), sizeof v); (u32)v; });  // @493_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + ecx*4 + 2), &v, sizeof v); }  // @494_530130
  goto L530704;  // @495_530130
  L5306f9:;
  ecx = (u32)((s32)eax * (s32)(u32)(22));  // @497_530130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @498_530130
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + eax + 2), &v, sizeof v); }  // @499_530130
  L530704:;
  esi = (esi & 0xffff0000u) | ((((esi & 0xffff) + 1)) & 0xffff);  // @501_530130
  FL[3] = (esi & 0xffff);  // @502_530130
  { u16 v = (u16)((esi & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @503_530130
  FL[0] = (u32)(s32)(s16)((esi & 0xffff)); FL[1] = (u32)(s32)(s16)(2);  // @504_530130
  if ((s32)FL[0] < (s32)FL[1]) goto L530690;  // @505_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 58), sizeof v); (u32)v; })) & 0xffff);  // @506_530130
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) + 1)) & 0xffff);  // @507_530130
  FL[3] = (eax & 0xffff);  // @508_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 58), &v, sizeof v); }  // @509_530130
  FL[0] = (eax & 0xffff); FL[1] = (u32)(2);  // @510_530130
  eax = (u32)(4294967295);  // @511_530130
  if ((s32)FL[0] < (s32)FL[1]) goto L530685;  // @512_530130
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; })) & 0xffff);  // @513_530130
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) + 1)) & 0xffff);  // @514_530130
  FL[3] = (eax & 0xffff);  // @515_530130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @516_530130
  FL[0] = (eax & 0xffff); FL[1] = (u32)(2);  // @517_530130
  eax = (u32)(4294967295);  // @518_530130
  if ((s32)FL[0] < (s32)FL[1]) goto L530681;  // @519_530130
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @520_530130
  L530745:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @522_530130
  FL[2] = ((edx & 0xffff) & (edx & 0xffff));  // @523_530130
  if (FL[2] != 0) goto L530622;  // @524_530130
  L530751:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; })) & 0xffff);  // @526_530130
  ext_633654(G(u32, 0x6f5630));  // @527_530130
  return eax;  // @528_530130
  L530768:;
  eax = (eax & 0xffff0000u) | (((ecx & 0xffff)) & 0xffff);  // @530_530130
  ext_633654(G(u32, 0x6f5630));  // @531_530130
  return eax;  // @532_530130
  L53077e:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7347037), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @534_530130
  if (FL[0] == FL[1]) goto L5307aa;  // @535_530130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @536_530130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @537_530130
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6951992), (u32)(1261));  // @538_530130
  ecx = edx = 0;  // @539_530130
  PV[38] = (u32)(eax);  // @540_530130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @541_530130
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[38], (u32)(6952100));  // @542_530130
  ecx = edx = 0;  // @543_530130
  L5307aa:;
  ext_633654(G(u32, 0x6f5630));  // @545_530130
  eax = 0;  // @546_530130
  FL[3] = eax;  // @547_530130
  return eax;  // @548_530130
}
PCREG(530130, lifted_530130);

