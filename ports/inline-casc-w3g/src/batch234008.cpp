// batch234008.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" long double THISCALL ext_58b9c0_thiscall4_ld(u32, u32, u32, u32) __asm__("ext_58b9c0");
extern "C" u32 FASTCALL ext_597e00_fastcall3(u32, u32, u32) __asm__("ext_597e00");
extern "C" u32 THISCALL ext_41e680_thiscall1(u32) __asm__("ext_41e680");
extern "C" u32 THISCALL ext_481e10_thiscall3(u32, u32, u32) __asm__("ext_481e10");
extern "C" u32 THISCALL ext_58b6d0_thiscall2(u32, u32) __asm__("ext_58b6d0");
extern "C" u32 THISCALL ext_595440_thiscall3(u32, u32, u32) __asm__("ext_595440");
extern "C" u32 THISCALL ext_596760_thiscall2(u32, u32) __asm__("ext_596760");
extern "C" u32 THISCALL ext_5967b0_thiscall2(u32, u32) __asm__("ext_5967b0");
extern "C" u32 THISCALL ext_597b50_thiscall1(u32) __asm__("ext_597b50");
extern "C" u32 THISCALL ext_5ab0f0_thiscall1(u32) __asm__("ext_5ab0f0");
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

extern "C" u32 THISCALL lifted_58cab0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_58cab0
  edi = ecx;  // @1_58cab0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(262144));  // @2_58cab0
  if (FL[2] == 0) goto L58caee;  // @3_58cab0
  PV[0] = (u32)(ebx);  // @4_58cab0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_58cab0
  eax = ext_481e10_thiscall3(ecx, PV[1], PV[0]);  // @6_58cab0
  ecx = edx = 0;  // @7_58cab0
  ext_633654(G(u32, 0x6f5630));  // @8_58cab0
  return eax;  // @9_58cab0
  L58caee:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_58cab0
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2004), sizeof v); (u32)v; });  // @12_58cab0
  if (FL[0] != FL[1]) goto L58cb17;  // @13_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @14_58cab0
  eax = ext_597b50_thiscall1(ecx);  // @15_58cab0
  ecx = edx = 0;  // @16_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @17_58cab0
  PV[2] = (u32)(ebx);  // @18_58cab0
  eax = ext_5967b0_thiscall2(ecx, PV[2]);  // @19_58cab0
  ecx = edx = 0;  // @20_58cab0
  goto L58cd3a;  // @21_58cab0
  L58cb17:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2006), sizeof v); (u32)v; });  // @23_58cab0
  if (FL[0] != FL[1]) goto L58cb31;  // @24_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @25_58cab0
  PV[3] = (u32)(ebx);  // @26_58cab0
  eax = ext_597e00_fastcall3(ecx, edx, PV[3]);  // @27_58cab0
  edx = 0;  // @28_58cab0
  goto L58cd3a;  // @29_58cab0
  L58cb31:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2010), sizeof v); (u32)v; });  // @31_58cab0
  if (FL[0] != FL[1]) goto L58cb4b;  // @32_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @33_58cab0
  PV[4] = (u32)(ebx);  // @34_58cab0
  eax = ext_596760_thiscall2(ecx, PV[4]);  // @35_58cab0
  ecx = edx = 0;  // @36_58cab0
  goto L58cd3a;  // @37_58cab0
  L58cb4b:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2002), sizeof v); (u32)v; });  // @39_58cab0
  if (FL[0] != FL[1]) goto L58cd3a;  // @40_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_58cab0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1236)))(ecx);  // @42_58cab0
  ecx = edx = 0;  // @43_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @44_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 7439), sizeof v); (u32)v; });  // @45_58cab0
  eax = ext_5ab0f0_thiscall1(ecx);  // @46_58cab0
    // @47_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_58cab0
  ecx = edi;  // @49_58cab0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1292)))(ecx);  // @50_58cab0
  ecx = edx = 0;  // @51_58cab0
  edx = eax;  // @52_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2138), sizeof v); (u32)v; });  // @53_58cab0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @54_58cab0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @55_58cab0
  if (FL[0] != FL[1]) goto L58cb9c;  // @56_58cab0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2773), sizeof v); (u32)v; }); FL[1] = (u32)(5);  // @57_58cab0
  if (FL[0] != FL[1]) goto L58cca7;  // @58_58cab0
  L58cb9c:;
  FL[2] = (edx & edx);  // @60_58cab0
  if (FL[2] == 0) goto L58cbe3;  // @61_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @62_58cab0
  ecx = edx;  // @63_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 205) + 0), 4); v; });  // @64_58cab0
  X0[1] = 0;  // @65_58cab0
  X0[2] = 0;  // @66_58cab0
  X0[3] = 0;  // @67_58cab0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @68_58cab0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 848)))(ecx);  // @69_58cab0
  ecx = edx = 0;  // @70_58cab0
  ecx = eax;  // @71_58cab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @72_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 848), sizeof v); (u32)v; });  // @73_58cab0
  FS[0] = ((long double(THISCALL *)(u32))(eax))(ecx);  // @74_58cab0
  ecx = edx = 0;  // @75_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @76_58cab0
  X0[1] = 0;  // @77_58cab0
  X0[2] = 0;  // @78_58cab0
  X0[3] = 0;  // @79_58cab0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @80_58cab0
  FS[0] = (FS[0] * LDF((u32)(6806020)));  // @81_58cab0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @82_58cab0
  FS[0] = (FS[0] * LDF((u32)(EBP - 36)));  // @83_58cab0
  STF((u32)(EBP - 32), FS[0]);  // @84_58cab0
  goto L58cbea;  // @85_58cab0
  L58cbe3:;
  { u32 v = (u32)((u32)(1008981770)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @87_58cab0
  L58cbea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @91_58cab0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6997712), (u32)(1142));  // @92_58cab0
  ecx = edx = 0;  // @93_58cab0
  FS[0] = (FS[0] - LDF((u32)(6792876)));  // @94_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_58cab0
  FS[0] = (FS[0] * LDF((u32)(EBP - 32)));  // @96_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @98_58cab0
  STF((u32)(EBP - 36), FS[0]);  // @99_58cab0
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6997712), (u32)(1143));  // @100_58cab0
  ecx = edx = 0;  // @101_58cab0
  FS[0] = (FS[0] - LDF((u32)(6799764)));  // @102_58cab0
  PV[5] = (u32)(ecx);  // @103_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2138), sizeof v); (u32)v; });  // @104_58cab0
  ecx = (ecx + (u32)(2793));  // @105_58cab0
  FL[3] = ecx;  // @106_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @107_58cab0
  X0[1] = 0;  // @108_58cab0
  X0[2] = 0;  // @109_58cab0
  X0[3] = 0;  // @110_58cab0
  FS[0] = (FS[0] * LDF((u32)(EBP - 32)));  // @111_58cab0
  PV[6] = X0[0];  // @112_58cab0
  STF((u32)(EBP - 32), FS[0]);  // @113_58cab0
  eax = ext_58b6d0_thiscall2(ecx, PV[6]);  // @114_58cab0
    // @115_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2138), sizeof v); (u32)v; });  // @116_58cab0
  PV[7] = (u32)(ecx);  // @117_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2797) + 0), 4); v; });  // @118_58cab0
  X0[1] = 0;  // @119_58cab0
  X0[2] = 0;  // @120_58cab0
  X0[3] = 0;  // @121_58cab0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @122_58cab0
  __builtin_memcpy((void *)((u32)(eax + 2797) + 0), &X0[0], 4);  // @123_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2138), sizeof v); (u32)v; });  // @124_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @125_58cab0
  X0[1] = 0;  // @126_58cab0
  X0[2] = 0;  // @127_58cab0
  X0[3] = 0;  // @128_58cab0
  ecx = (ecx + (u32)(2644));  // @129_58cab0
  FL[3] = ecx;  // @130_58cab0
  PV[8] = X0[0];  // @131_58cab0
  eax = ext_58b6d0_thiscall2(ecx, PV[8]);  // @132_58cab0
    // @133_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2138), sizeof v); (u32)v; });  // @134_58cab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @135_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2652) + 0), 4); v; });  // @136_58cab0
  X0[1] = 0;  // @137_58cab0
  X0[2] = 0;  // @138_58cab0
  X0[3] = 0;  // @139_58cab0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @140_58cab0
  __builtin_memcpy((void *)((u32)(eax + 2652) + 0), &X0[0], 4);  // @141_58cab0
  L58cca7:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(33554432));  // @143_58cab0
  if (FL[2] == 0) goto L58cce0;  // @144_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_58cab0
  ecx = (u32)(102);  // @146_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2374) + 0), 4); v; });  // @147_58cab0
  X0[1] = 0;  // @148_58cab0
  X0[2] = 0;  // @149_58cab0
  X0[3] = 0;  // @150_58cab0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @151_58cab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @152_58cab0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @153_58cab0
  ecx = (ecx - eax);  // @154_58cab0
  FL[3] = ecx;  // @155_58cab0
  FL[0] = edx; FL[1] = ecx;  // @156_58cab0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58cd3a;  // @157_58cab0
  X0[0] = edx; X0[1] = X0[2] = X0[3] = 0;  // @158_58cab0
  goto L58cd27;  // @159_58cab0
  L58cce0:;
  FL[2] = (edx & edx);  // @161_58cab0
  if (FL[2] == 0) goto L58cd3a;  // @162_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2374) + 0), 4); v; });  // @163_58cab0
  X0[1] = 0;  // @164_58cab0
  X0[2] = 0;  // @165_58cab0
  X0[3] = 0;  // @166_58cab0
  ecx = (u32)(153);  // @167_58cab0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @168_58cab0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @169_58cab0
  ecx = (ecx - eax);  // @170_58cab0
  FL[3] = ecx;  // @171_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @172_58cab0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); FL[1] = ecx;  // @173_58cab0
  if ((s32)FL[0] <= (s32)FL[1]) goto L58cd3a;  // @174_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @175_58cab0
  ecx = edx;  // @176_58cab0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 848)))(ecx);  // @177_58cab0
  ecx = edx = 0;  // @178_58cab0
  ecx = eax;  // @179_58cab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @180_58cab0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 816)))(ecx);  // @181_58cab0
  ecx = edx = 0;  // @182_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @183_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @184_58cab0
  L58cd27:;
  X0[0] = F2U((float)(s32)X0[0]);  // @186_58cab0
  X0[1] = F2U((float)(s32)X0[1]);  // @187_58cab0
  X0[2] = F2U((float)(s32)X0[2]);  // @188_58cab0
  X0[3] = F2U((float)(s32)X0[3]);  // @189_58cab0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @190_58cab0
  __builtin_memcpy((void *)((u32)(edi + 2374) + 0), &X0[0], 4);  // @191_58cab0
  L58cd3a:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1996), sizeof v); (u32)v; });  // @193_58cab0
  if (FL[0] != FL[1]) goto L58cd6c;  // @194_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2055) + 0), 4); v; });  // @195_58cab0
  X0[1] = 0;  // @196_58cab0
  X0[2] = 0;  // @197_58cab0
  X0[3] = 0;  // @198_58cab0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; })));  // @199_58cab0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2051) + 0), 4); v; });  // @200_58cab0
  X1[1] = 0;  // @201_58cab0
  X1[2] = 0;  // @202_58cab0
  X1[3] = 0;  // @203_58cab0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @204_58cab0
  __builtin_memcpy((void *)((u32)(edi + 2055) + 0), &X0[0], 4);  // @205_58cab0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58cd6c;  // @206_58cab0
  __builtin_memcpy((void *)((u32)(edi + 2055) + 0), &X1[0], 4);  // @207_58cab0
  L58cd6c:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 357), sizeof v); (u32)v; });  // @209_58cab0
  if (FL[0] != FL[1]) goto L58cdc0;  // @210_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @211_58cab0
  PV[9] = (u32)(ebx);  // @212_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @213_58cab0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[9]);  // @214_58cab0
  ecx = edx = 0;  // @215_58cab0
  ebx = eax;  // @216_58cab0
  FL[2] = (ebx & ebx);  // @217_58cab0
  if (FL[2] == 0) goto L58cfcc;  // @218_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @219_58cab0
  ecx = edi;  // @220_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1620), sizeof v); (u32)v; });  // @221_58cab0
  PV[10] = (u32)(ebx);  // @222_58cab0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[10], (u32)(0), (u32)(0), (u32)(0));  // @223_58cab0
  ecx = edx = 0;  // @224_58cab0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @225_58cab0
  if (FL[2] == 0) goto L58cfcc;  // @226_58cab0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @227_58cab0
  ecx = edi;  // @228_58cab0
  eax = ext_41e680_thiscall1(ecx);  // @229_58cab0
  ecx = edx = 0;  // @230_58cab0
  PV[11] = (u32)(eax);  // @231_58cab0
  ecx = ebx;  // @232_58cab0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 148)))(ecx, PV[11]);  // @233_58cab0
  ecx = edx = 0;  // @234_58cab0
  goto L58cfcc;  // @235_58cab0
  L58cdc0:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1980), sizeof v); (u32)v; });  // @237_58cab0
  if (FL[0] != FL[1]) goto L58cddf;  // @238_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @239_58cab0
  FL[2] = (eax & eax);  // @240_58cab0
  if (FL[2] == 0) goto L58cdd9;  // @241_58cab0
  L58cdd2:;
  eax = ((u32(STDCALL *)(void))(eax))();  // @243_58cab0
  ecx = edx = 0;  // @244_58cab0
  goto L58cfcc;  // @245_58cab0
  L58cdd9:;
  __builtin_trap();  // @247_58cab0
  L58cddf:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1982), sizeof v); (u32)v; });  // @249_58cab0
  if (FL[0] != FL[1]) goto L58cdf7;  // @250_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @251_58cab0
  FL[2] = (eax & eax);  // @252_58cab0
  if (FL[2] != 0) goto L58cdd2;  // @253_58cab0
  __builtin_trap();  // @254_58cab0
  L58cdf7:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2000), sizeof v); (u32)v; });  // @256_58cab0
  if (FL[0] != FL[1]) goto L58cea1;  // @257_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @258_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @259_58cab0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6997712), (u32)(1224));  // @260_58cab0
  ecx = edx = 0;  // @261_58cab0
  PV[12] = (u32)(eax);  // @262_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @263_58cab0
  eax = ((u32(*)(u32, u32))(*(u32 *)(ecx + 44)))(PV[12], (u32)(6998476));  // @264_58cab0   (w3g hand fix: cdecl logger, the caller pops 8 bytes)
  ecx = edx = 0;  // @265_58cab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2047) + 0), 4); v; });  // @266_58cab0
  X0[1] = 0;  // @267_58cab0
  X0[2] = 0;  // @268_58cab0
  X0[3] = 0;  // @269_58cab0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806064) + 0), 4); v; })));  // @270_58cab0
  PV[13] = (u32)(ecx);  // @271_58cab0
  ecx = edi;  // @272_58cab0
  PV[14] = X0[0];  // @273_58cab0
  FS[0] = ext_58b9c0_thiscall4_ld(ecx, PV[14], (u32)(0), (u32)(0));  // @274_58cab0
  ecx = edx = 0;  // @275_58cab0
  STF((u32)(EBP - 40), FS[0]);  // @276_58cab0
  X0[0] = 0;  // @277_58cab0
  X0[1] = 0;  // @278_58cab0
  X0[2] = 0;  // @279_58cab0
  X0[3] = 0;  // @280_58cab0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; }));  // @281_58cab0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L58cfcc;  // @282_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @283_58cab0
  PV[15] = (u32)(ecx);  // @284_58cab0
  ecx = (u32)(EBP - 16);  // @285_58cab0
  PV[16] = (u32)(ecx);  // @286_58cab0
  ecx = (u32)(EBP - 28);  // @287_58cab0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @288_58cab0
  PV[17] = (u32)(ecx);  // @289_58cab0
  ecx = edi;  // @290_58cab0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @291_58cab0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @292_58cab0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @293_58cab0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @294_58cab0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @295_58cab0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1468)))(ecx, PV[17], PV[16], (u32)(0));  // @296_58cab0
  ecx = edx = 0;  // @297_58cab0
  goto L58cfcc;  // @298_58cab0
  L58cea1:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1998), sizeof v); (u32)v; });  // @300_58cab0
  if (FL[0] != FL[1]) goto L58cecc;  // @301_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @302_58cab0
  ecx = edi;  // @303_58cab0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @304_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1620), sizeof v); (u32)v; });  // @305_58cab0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[18], (u32)(0), (u32)(0), (u32)(0));  // @306_58cab0
  ecx = edx = 0;  // @307_58cab0
  ecx = 0;  // @308_58cab0
  FL[3] = ecx;  // @309_58cab0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @310_58cab0
  ecx = (ecx & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @311_58cab0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @312_58cab0
  goto L58cfcc;  // @313_58cab0
  L58cecc:;
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1972), sizeof v); (u32)v; });  // @315_58cab0
  FL[0] = (esi & 0xffff); FL[1] = (edx & 0xffff);  // @316_58cab0
  if (FL[0] != FL[1]) goto L58ceff;  // @317_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @318_58cab0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 2039), &v, sizeof v); }  // @319_58cab0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 2035), &v, sizeof v); }  // @320_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @321_58cab0
  PV[19] = (u32)(edx);  // @322_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @323_58cab0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 296)))(ecx, PV[19], (u32)(100), (u32)(0));  // @324_58cab0
  ecx = edx = 0;  // @325_58cab0
  goto L58cfcc;  // @326_58cab0
  L58ceff:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1974), sizeof v); (u32)v; });  // @328_58cab0
  if (FL[0] != FL[1]) goto L58cf18;  // @329_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @330_58cab0
  ecx = edi;  // @331_58cab0
  PV[20] = (u32)(ebx);  // @332_58cab0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1640)))(ecx, PV[20]);  // @333_58cab0
  ecx = edx = 0;  // @334_58cab0
  goto L58cfcc;  // @335_58cab0
  L58cf18:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1976), sizeof v); (u32)v; });  // @337_58cab0
  if (FL[0] != FL[1]) goto L58cf31;  // @338_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @339_58cab0
  ecx = edi;  // @340_58cab0
  PV[21] = (u32)(ebx);  // @341_58cab0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1636)))(ecx, PV[21]);  // @342_58cab0
  ecx = edx = 0;  // @343_58cab0
  goto L58cfcc;  // @344_58cab0
  L58cf31:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1988), sizeof v); (u32)v; });  // @346_58cab0
  if (FL[0] != FL[1]) goto L58cf82;  // @347_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @348_58cab0
  ecx = edi;  // @349_58cab0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 736)))(ecx);  // @350_58cab0
  ecx = edx = 0;  // @351_58cab0
  esi = eax;  // @352_58cab0
  FL[2] = (esi & esi);  // @353_58cab0
  if (FL[2] != 0) goto L58cf5e;  // @354_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @355_58cab0
  ecx = edi;  // @356_58cab0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @357_58cab0
  ecx = edx = 0;  // @358_58cab0
  esi = (u32)(6801640);  // @359_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @360_58cab0
  FL[2] = (eax & eax);  // @361_58cab0
  if (FL[2] != 0) esi = eax;  // @362_58cab0
  L58cf5e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @364_58cab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @365_58cab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @366_58cab0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @367_58cab0
  ecx = edx = 0;  // @368_58cab0
  PV[22] = (u32)(esi);  // @369_58cab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @370_58cab0
  ecx = eax;  // @371_58cab0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(6998492), PV[22], (u32)(12));  // @372_58cab0
  ecx = edx = 0;  // @373_58cab0
  goto L58cfcc;  // @374_58cab0
  L58cf82:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2020), sizeof v); (u32)v; });  // @376_58cab0
  if (FL[0] != FL[1]) goto L58cf98;  // @377_58cab0
  ecx = edi;  // @378_58cab0
  eax = ext_595440_thiscall3(ecx, (u32)(1), (u32)(64));  // @379_58cab0
  ecx = edx = 0;  // @380_58cab0
  goto L58cfcc;  // @381_58cab0
  L58cf98:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2022), sizeof v); (u32)v; });  // @383_58cab0
  if (FL[0] != FL[1]) goto L58cfae;  // @384_58cab0
  ecx = edi;  // @385_58cab0
  eax = ext_595440_thiscall3(ecx, (u32)(0), (u32)(64));  // @386_58cab0
  ecx = edx = 0;  // @387_58cab0
  goto L58cfcc;  // @388_58cab0
  L58cfae:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2018), sizeof v); (u32)v; });  // @390_58cab0
  if (FL[0] != FL[1]) goto L58cfc3;  // @391_58cab0
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 3799), &v, sizeof v); }  // @392_58cab0
  goto L58cfcc;  // @393_58cab0
  L58cfc3:;
  PV[23] = (u32)(ebx);  // @395_58cab0
  PV[24] = (u32)(esi);  // @396_58cab0
  ecx = edi;  // @397_58cab0
  eax = ext_481e10_thiscall3(ecx, PV[24], PV[23]);  // @398_58cab0
  ecx = edx = 0;  // @399_58cab0
  L58cfcc:;
  ext_633654(G(u32, 0x6f5630));  // @401_58cab0
  eax = 0;  // @402_58cab0
  FL[3] = eax;  // @403_58cab0
  return eax;  // @404_58cab0
}
PCREG(58cab0, lifted_58cab0);

