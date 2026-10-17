// batch234026.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" long double THISCALL ext_44c840_thiscall1_ld(u32) __asm__("ext_44c840");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4de7e0_fastcall2(u32, u32) __asm__("ext_4de7e0");
extern "C" u32 FASTCALL ext_4e0980_fastcall2(u32, u32) __asm__("ext_4e0980");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 THISCALL ext_43ec00_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_43ec00");
extern "C" u32 THISCALL ext_45bfd0_thiscall2(u32, u32) __asm__("ext_45bfd0");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 THISCALL ext_4db780_thiscall2(u32, u32) __asm__("ext_4db780");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e71b0_thiscall3(u32, u32, u32) __asm__("ext_4e71b0");
extern "C" u32 THISCALL ext_4e7240_thiscall4(u32, u32, u32, u32) __asm__("ext_4e7240");
extern "C" u32 THISCALL ext_4e7330_thiscall3(u32, u32, u32) __asm__("ext_4e7330");
extern "C" u32 THISCALL ext_4e73b0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_4e73b0");
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

extern "C" u32 THISCALL lifted_4a6610_w3gold(u32 ecx_in) {
  u32 TPX = 0;
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[75], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4a6610
  ebx = ecx;  // @1_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @2_4a6610
  X0[0] = F2U((float)(s32)X0[0]);  // @3_4a6610
  X0[1] = F2U((float)(s32)X0[1]);  // @4_4a6610
  X0[2] = F2U((float)(s32)X0[2]);  // @5_4a6610
  X0[3] = F2U((float)(s32)X0[3]);  // @6_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 246), sizeof v); (u32)v; });  // @7_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @8_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 24) + 0), &X0[0], 4);  // @9_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @10_4a6610
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); edx = (u32)r_; }  // @11_4a6610
  FL[0] = ecx; FL[1] = edx;  // @12_4a6610
  if (FL[0] == FL[1]) goto L4a71d2;  // @13_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 180) + 0), 4); v; });  // @14_4a6610
  X1[1] = 0;  // @15_4a6610
  X1[2] = 0;  // @16_4a6610
  X1[3] = 0;  // @17_4a6610
  X0[0] = 0;  // @18_4a6610
  X0[1] = 0;  // @19_4a6610
  X0[2] = 0;  // @20_4a6610
  X0[3] = 0;  // @21_4a6610
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @22_4a6610
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @23_4a6610
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @24_4a6610
  if (__builtin_parity(FL[2] & 0xff)) goto L4a6727;  // @25_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @26_4a6610
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @27_4a6610
  ecx = (ecx - eax);  // @28_4a6610
  FL[3] = ecx;  // @29_4a6610
  FL[0] = ecx; FL[1] = edx;  // @30_4a6610
  if ((s32)FL[0] >= (s32)FL[1]) goto L4a6727;  // @31_4a6610
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 271), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @32_4a6610
  if (FL[0] == FL[1]) goto L4a66da;  // @33_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @34_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4a6610
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @36_4a6610
  ecx = edx = 0;  // @37_4a6610
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @38_4a6610
  if (FL[0] != FL[1]) goto L4a66da;  // @39_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @40_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_4a6610
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @42_4a6610
  ecx = edx = 0;  // @43_4a6610
  FL[2] = (eax & eax);  // @44_4a6610
  if (FL[2] == 0) goto L4a71d2;  // @45_4a6610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @46_4a6610
  ecx = eax;  // @47_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @48_4a6610
  ecx = edx = 0;  // @49_4a6610
  ext_633654(G(u32, 0x6f5630));  // @50_4a6610
  return eax;  // @51_4a6610
  L4a66da:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 272), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @53_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @54_4a6610
  if (FL[0] == FL[1]) goto L4a6700;  // @55_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_4a6610
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @57_4a6610
  ecx = edx = 0;  // @58_4a6610
  ext_633654(G(u32, 0x6f5630));  // @59_4a6610
  return eax;  // @60_4a6610
  L4a6700:;
  FL[2] = (ecx & ecx);  // @62_4a6610
  if (FL[2] == 0) goto L4a71d2;  // @63_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @65_4a6610
  ecx = edx = 0;  // @66_4a6610
  ext_633654(G(u32, 0x6f5630));  // @67_4a6610
  return eax;  // @68_4a6610
  L4a6727:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 270), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @70_4a6610
  if (FL[0] != FL[1]) goto L4a71d2;  // @71_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @72_4a6610
  edx = (u32)((EBP - 280) + 192);  // @73_4a6610
  PV[0] = (u32)(edx);  // @74_4a6610
  edx = (u32)((EBP - 284) + 244);  // @75_4a6610
  PV[1] = (u32)(edx);  // @76_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_4a6610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[1], PV[0]);  // @78_4a6610
  ecx = edx = 0;  // @79_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 186) + 0), 4); v; });  // @80_4a6610
  X0[1] = 0;  // @81_4a6610
  X0[2] = 0;  // @82_4a6610
  X0[3] = 0;  // @83_4a6610
  X1[0] = 0;  // @84_4a6610
  X1[1] = 0;  // @85_4a6610
  X1[2] = 0;  // @86_4a6610
  X1[3] = 0;  // @87_4a6610
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_4a6610
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @89_4a6610
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @90_4a6610
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @91_4a6610
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @92_4a6610
  if (!__builtin_parity(FL[2] & 0xff)) goto L4a678e;  // @93_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 190) + 0), 4); v; });  // @94_4a6610
  X0[1] = 0;  // @95_4a6610
  X0[2] = 0;  // @96_4a6610
  X0[3] = 0;  // @97_4a6610
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @98_4a6610
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @99_4a6610
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @100_4a6610
  if (!__builtin_parity(FL[2] & 0xff)) goto L4a678e;  // @101_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 194) + 0), 4); v; });  // @102_4a6610
  X0[1] = 0;  // @103_4a6610
  X0[2] = 0;  // @104_4a6610
  X0[3] = 0;  // @105_4a6610
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @106_4a6610
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @107_4a6610
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @108_4a6610
  if (__builtin_parity(FL[2] & 0xff)) goto L4a67b1;  // @109_4a6610
  L4a678e:;
  edx = (u32)(ebx + 198);  // @111_4a6610
  ecx = (u32)(ebx + 186);  // @112_4a6610
  eax = ext_4e0980_fastcall2(ecx, edx);  // @113_4a6610
    // @114_4a6610
  edx = (u32)(ebx + 186);  // @115_4a6610
  ecx = (u32)((EBP - 280) + 240);  // @116_4a6610
  eax = ext_4de7e0_fastcall2(ecx, edx);  // @117_4a6610
  ecx = edx = 0;  // @118_4a6610
  L4a67b1:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 184), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @120_4a6610
  if (FL[0] != FL[1]) goto L4a68d1;  // @121_4a6610
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 185), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @122_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 24) + 0), 4); v; });  // @123_4a6610
  X0[1] = 0;  // @124_4a6610
  X0[2] = 0;  // @125_4a6610
  X0[3] = 0;  // @126_4a6610
  PV[2] = (u32)(ecx);  // @127_4a6610
  ecx = (u32)(ebx + 72);  // @128_4a6610
  PV[3] = X0[0];  // @129_4a6610
  if (FL[0] != FL[1]) goto L4a67e8;  // @130_4a6610
  eax = (u32)((EBP - 284) + 208);  // @131_4a6610
  PV[4] = (u32)(eax);  // @132_4a6610
  eax = ext_4e71b0_thiscall3(ecx, PV[4], PV[3]);  // @133_4a6610
  ecx = edx = 0;  // @134_4a6610
  goto L4a71ba;  // @135_4a6610
  L4a67e8:;
  eax = (u32)((EBP - 280) + 184);  // @137_4a6610
  PV[5] = (u32)(eax);  // @138_4a6610
  eax = (u32)((EBP - 284) + 212);  // @139_4a6610
  PV[6] = (u32)(eax);  // @140_4a6610
  eax = ext_4e7240_thiscall4(ecx, PV[6], PV[5], PV[3]);  // @141_4a6610
  ecx = edx = 0;  // @142_4a6610
  ecx = (u32)((EBP - 280) + 180);  // @143_4a6610
  FS[0] = ext_44c840_thiscall1_ld(ecx);  // @144_4a6610
  ecx = 0;  // @145_4a6610
  FS[0] = (FS[0] * LDF((u32)(6823364)));  // @146_4a6610
  ecx = (u32)((EBP - 280) + 180);  // @147_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @148_4a6610
  X0[1] = 0;  // @149_4a6610
  X0[2] = 0;  // @150_4a6610
  X0[3] = 0;  // @151_4a6610
  STF((u32)((EBP - 280) + 28), FS[0]);  // @152_4a6610
  { float a_ = U2F(X0[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 28) + 0), 4); v; })); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @153_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 28) + 0), &X0[0], 4);  // @154_4a6610
  eax = ext_4e09b0_thiscall1(ecx);  // @155_4a6610
    // @156_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 180) + 0), 4); v; });  // @157_4a6610
  X1[1] = 0;  // @158_4a6610
  X1[2] = 0;  // @159_4a6610
  X1[3] = 0;  // @160_4a6610
  eax = (u32)((EBP - 280) + 252);  // @161_4a6610
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 240) + 0), 4); v; })));  // @162_4a6610
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 28) + 0), 4); v; });  // @163_4a6610
  X2[1] = 0;  // @164_4a6610
  X2[2] = 0;  // @165_4a6610
  X2[3] = 0;  // @166_4a6610
  edx = (u32)((EBP - 280) + 180);  // @167_4a6610
  PV[7] = (u32)(eax);  // @168_4a6610
  ecx = (u32)((EBP - 284) + 244);  // @169_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @170_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 244) + 0), 4); v; })));  // @171_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 184) + 0), &X1[0], 4);  // @172_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 188) + 0), 4); v; });  // @173_4a6610
  X1[1] = 0;  // @174_4a6610
  X1[2] = 0;  // @175_4a6610
  X1[3] = 0;  // @176_4a6610
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 248) + 0), 4); v; })));  // @177_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @178_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 248) + 0), 4); v; })));  // @179_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 188) + 0), &X1[0], 4);  // @180_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 192) + 0), 4); v; });  // @181_4a6610
  X1[1] = 0;  // @182_4a6610
  X1[2] = 0;  // @183_4a6610
  X1[3] = 0;  // @184_4a6610
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 252) + 0), 4); v; })));  // @185_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @186_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 252) + 0), 4); v; })));  // @187_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 192) + 0), &X1[0], 4);  // @188_4a6610
  eax = ext_4de040_fastcall3(ecx, edx, PV[7]);  // @189_4a6610
  ecx = edx = 0;  // @190_4a6610
  goto L4a71ba;  // @191_4a6610
  L4a68d1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 273), sizeof v); (u32)v; });  // @193_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 52), &v, sizeof v); }  // @194_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 279), sizeof v); (u32)v; });  // @195_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 36), &v, sizeof v); }  // @196_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 250), sizeof v); (u32)v; });  // @197_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 28), &v, sizeof v); }  // @198_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @199_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @200_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @201_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 288) + 68), &v, sizeof v); }  // @202_4a6610
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(1));  // @203_4a6610
  ecx = edx = 0;  // @204_4a6610
  L4a6910:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 185), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @206_4a6610
  edi = (u32)(ebx + 72);  // @207_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 24) + 0), 4); v; });  // @208_4a6610
  X0[1] = 0;  // @209_4a6610
  X0[2] = 0;  // @210_4a6610
  X0[3] = 0;  // @211_4a6610
  PV[8] = (u32)(ecx);  // @212_4a6610
  ecx = edi;  // @213_4a6610
  PV[9] = X0[0];  // @214_4a6610
  if (FL[0] != FL[1]) goto L4a693c;  // @215_4a6610
  eax = (u32)((EBP - 284) + 208);  // @216_4a6610
  PV[10] = (u32)(eax);  // @217_4a6610
  eax = ext_4e71b0_thiscall3(ecx, PV[10], PV[9]);  // @218_4a6610
  ecx = edx = 0;  // @219_4a6610
  goto L4a6a20;  // @220_4a6610
  L4a693c:;
  eax = (u32)((EBP - 280) + 220);  // @222_4a6610
  PV[11] = (u32)(eax);  // @223_4a6610
  eax = (u32)((EBP - 284) + 212);  // @224_4a6610
  PV[12] = (u32)(eax);  // @225_4a6610
  eax = ext_4e7240_thiscall4(ecx, PV[12], PV[11], PV[9]);  // @226_4a6610
  ecx = edx = 0;  // @227_4a6610
  ecx = (u32)((EBP - 280) + 216);  // @228_4a6610
  FS[0] = ext_44c840_thiscall1_ld(ecx);  // @229_4a6610
  ecx = 0;  // @230_4a6610
  FS[0] = (FS[0] * LDF((u32)(6823364)));  // @231_4a6610
  ecx = (u32)((EBP - 280) + 216);  // @232_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @233_4a6610
  X0[1] = 0;  // @234_4a6610
  X0[2] = 0;  // @235_4a6610
  X0[3] = 0;  // @236_4a6610
  STF((u32)((EBP - 280) + 16), FS[0]);  // @237_4a6610
  { float a_ = U2F(X0[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 16) + 0), 4); v; })); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @238_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 16) + 0), &X0[0], 4);  // @239_4a6610
  eax = ext_4e09b0_thiscall1(ecx);  // @240_4a6610
    // @241_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 216) + 0), 4); v; });  // @242_4a6610
  X1[1] = 0;  // @243_4a6610
  X1[2] = 0;  // @244_4a6610
  X1[3] = 0;  // @245_4a6610
  eax = (u32)((EBP - 280) + 252);  // @246_4a6610
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 240) + 0), 4); v; })));  // @247_4a6610
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 16) + 0), 4); v; });  // @248_4a6610
  X2[1] = 0;  // @249_4a6610
  X2[2] = 0;  // @250_4a6610
  X2[3] = 0;  // @251_4a6610
  edx = (u32)((EBP - 280) + 216);  // @252_4a6610
  PV[13] = (u32)(eax);  // @253_4a6610
  ecx = (u32)((EBP - 284) + 244);  // @254_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @255_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 244) + 0), 4); v; })));  // @256_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 220) + 0), &X1[0], 4);  // @257_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 224) + 0), 4); v; });  // @258_4a6610
  X1[1] = 0;  // @259_4a6610
  X1[2] = 0;  // @260_4a6610
  X1[3] = 0;  // @261_4a6610
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 248) + 0), 4); v; })));  // @262_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @263_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 248) + 0), 4); v; })));  // @264_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 224) + 0), &X1[0], 4);  // @265_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 228) + 0), 4); v; });  // @266_4a6610
  X1[1] = 0;  // @267_4a6610
  X1[2] = 0;  // @268_4a6610
  X1[3] = 0;  // @269_4a6610
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 252) + 0), 4); v; })));  // @270_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @271_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 252) + 0), 4); v; })));  // @272_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 228) + 0), &X1[0], 4);  // @273_4a6610
  eax = ext_4de040_fastcall3(ecx, edx, PV[13]);  // @274_4a6610
  ecx = edx = 0;  // @275_4a6610
  L4a6a20:;
  ecx = (u32)((EBP - 280) + 64);  // @277_4a6610
  eax = ext_4e1b60_thiscall1(ecx);  // @278_4a6610
    // @279_4a6610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 254), sizeof v); (u32)v; });  // @280_4a6610
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 172), &v, sizeof v); }  // @281_4a6610
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 23), &v, sizeof v); }  // @282_4a6610
  FL[2] = (edx & edx);  // @283_4a6610
  if (FL[2] == 0) goto L4a6b8a;  // @284_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @285_4a6610
  PV[14] = (u32)(edx);  // @286_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @287_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @288_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[14]);  // @289_4a6610
  ecx = edx = 0;  // @290_4a6610
  FL[2] = (eax & eax);  // @291_4a6610
  if (FL[2] == 0) goto L4a6b8a;  // @292_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 258) + 0), 4); v; });  // @293_4a6610
  X0[1] = 0;  // @294_4a6610
  X0[2] = 0;  // @295_4a6610
  X0[3] = 0;  // @296_4a6610
  eax = (u32)((EBP - 280) + 192);  // @297_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 180) + 0), &X0[0], 4);  // @298_4a6610
  edx = (u32)((EBP - 280) + 204);  // @299_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 262) + 0), 4); v; });  // @300_4a6610
  X0[1] = 0;  // @301_4a6610
  X0[2] = 0;  // @302_4a6610
  X0[3] = 0;  // @303_4a6610
  ecx = (u32)((EBP - 280) + 40);  // @304_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 184) + 0), &X0[0], 4);  // @305_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 266) + 0), 4); v; });  // @306_4a6610
  X0[1] = 0;  // @307_4a6610
  X0[2] = 0;  // @308_4a6610
  X0[3] = 0;  // @309_4a6610
  PV[15] = (u32)(eax);  // @310_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 192) + 0), &X0[0], 4);  // @311_4a6610
  eax = ext_43e920_fastcall3(ecx, edx, PV[15]);  // @312_4a6610
  ecx = edx = 0;  // @313_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 40) + 0), 4); v; });  // @314_4a6610
  X0[1] = 0;  // @315_4a6610
  X0[2] = 0;  // @316_4a6610
  X0[3] = 0;  // @317_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 180) + 0), 4); v; })));  // @318_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 44) + 0), 4); v; });  // @319_4a6610
  X1[1] = 0;  // @320_4a6610
  X1[2] = 0;  // @321_4a6610
  X1[3] = 0;  // @322_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 184) + 0), 4); v; })));  // @323_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @324_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 48) + 0), 4); v; });  // @325_4a6610
  X0[1] = 0;  // @326_4a6610
  X0[2] = 0;  // @327_4a6610
  X0[3] = 0;  // @328_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 188) + 0), 4); v; })));  // @329_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @330_4a6610
  X0[0] = 0;  // @331_4a6610
  X0[1] = 0;  // @332_4a6610
  X0[2] = 0;  // @333_4a6610
  X0[3] = 0;  // @334_4a6610
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @335_4a6610
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4a6b80;  // @336_4a6610
  PV[16] = (u32)(ecx);  // @337_4a6610
  edx = (u32)((EBP - 284) + 184);  // @338_4a6610
  PV[17] = X1[0];  // @339_4a6610
  ecx = (u32)((EBP - 284) + 232);  // @340_4a6610
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[17]);  // @341_4a6610
    // @342_4a6610
  edx = (u32)((EBP - 280) + 228);  // @343_4a6610
  ecx = (u32)((EBP - 280) + 40);  // @344_4a6610
  eax = ext_43e960_fastcall2(ecx, edx);  // @345_4a6610
  ecx = edx = 0;  // @346_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 44) + 0), 4); v; });  // @347_4a6610
  X0[1] = 0;  // @348_4a6610
  X0[2] = 0;  // @349_4a6610
  X0[3] = 0;  // @350_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 40) + 0), 4); v; });  // @351_4a6610
  X1[1] = 0;  // @352_4a6610
  X1[2] = 0;  // @353_4a6610
  X1[3] = 0;  // @354_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @355_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @356_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @357_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 48) + 0), 4); v; });  // @358_4a6610
  X0[1] = 0;  // @359_4a6610
  X0[2] = 0;  // @360_4a6610
  X0[3] = 0;  // @361_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @362_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @363_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; });  // @364_4a6610
  X0[1] = 0;  // @365_4a6610
  X0[2] = 0;  // @366_4a6610
  X0[3] = 0;  // @367_4a6610
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @368_4a6610
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L4a70e5;  // @369_4a6610
  PV[18] = (u32)(ecx);  // @370_4a6610
  edx = (u32)((EBP - 284) + 184);  // @371_4a6610
  ecx = (u32)((EBP - 284) + 44);  // @372_4a6610
  eax = ext_451890_fastcall3(ecx, edx, (u32)(981668463));  // @373_4a6610
  ecx = 0;  // @374_4a6610
  eax = (u32)((EBP - 280) + 40);  // @375_4a6610
  PV[19] = (u32)(eax);  // @376_4a6610
  edx = (u32)((EBP - 284) + 196);  // @377_4a6610
  ecx = (u32)((EBP - 284) + 208);  // @378_4a6610
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[19]);  // @379_4a6610
  ecx = edx = 0;  // @380_4a6610
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 280) + 23), &v, sizeof v); }  // @381_4a6610
  goto L4a6b8a;  // @382_4a6610
  L4a6b80:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 254), &v, sizeof v); }  // @384_4a6610
  L4a6b8a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 192) + 0), 4); v; });  // @386_4a6610
  X0[1] = 0;  // @387_4a6610
  X0[2] = 0;  // @388_4a6610
  X0[3] = 0;  // @389_4a6610
  eax = (u32)((EBP - 280) + 192);  // @390_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 64) + 0), &X0[0], 4);  // @391_4a6610
  edx = (u32)((EBP - 280) + 204);  // @392_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 196) + 0), 4); v; });  // @393_4a6610
  X0[1] = 0;  // @394_4a6610
  X0[2] = 0;  // @395_4a6610
  X0[3] = 0;  // @396_4a6610
  ecx = (u32)((EBP - 280) + 76);  // @397_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 68) + 0), &X0[0], 4);  // @398_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 200) + 0), 4); v; });  // @399_4a6610
  X0[1] = 0;  // @400_4a6610
  X0[2] = 0;  // @401_4a6610
  X0[3] = 0;  // @402_4a6610
  PV[20] = (u32)(eax);  // @403_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 76) + 0), &X0[0], 4);  // @404_4a6610
  eax = ext_43e920_fastcall3(ecx, edx, PV[20]);  // @405_4a6610
  ecx = edx = 0;  // @406_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @407_4a6610
  edx = (u32)((EBP - 280) + 64);  // @408_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @409_4a6610
  PV[21] = (u32)(edx);  // @410_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @411_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @412_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @413_4a6610
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[21], (u32)(0), (u32)(1), (u32)(2097152), (u32)(1), (u32)(0));  // @414_4a6610
  ecx = edx = 0;  // @415_4a6610
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @416_4a6610
  if (FL[2] == 0) goto L4a7164;  // @417_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @418_4a6610
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 132), sizeof v); (u32)v; });  // @419_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @420_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @421_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[22]);  // @422_4a6610
  ecx = edx = 0;  // @423_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 132), sizeof v); (u32)v; });  // @424_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 32), &v, sizeof v); }  // @425_4a6610
  eax = (u32)((EBP - 280) + 180);  // @426_4a6610
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 254), &v, sizeof v); }  // @427_4a6610
  ecx = (u32)((EBP - 280) + 64);  // @428_4a6610
  PV[23] = (u32)(eax);  // @429_4a6610
  eax = ext_45bfd0_thiscall2(ecx, PV[23]);  // @430_4a6610
  ecx = edx = 0;  // @431_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 32), sizeof v); (u32)v; });  // @432_4a6610
  eax = (u32)((EBP - 280) + 180);  // @433_4a6610
  PV[24] = (u32)(eax);  // @434_4a6610
  eax = ext_4db780_thiscall2(ecx, PV[24]);  // @435_4a6610
  ecx = edx = 0;  // @436_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 180) + 0), 4); v; });  // @437_4a6610
  X0[1] = 0;  // @438_4a6610
  X0[2] = 0;  // @439_4a6610
  X0[3] = 0;  // @440_4a6610
  edx = esi;  // @441_4a6610
  __builtin_memcpy((void *)((u32)(ebx + 258) + 0), &X0[0], 4);  // @442_4a6610
  FL[1] = edx;  // @443_4a6610
  edx = (0u - edx);  // @444_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 184) + 0), 4); v; });  // @445_4a6610
  X0[1] = 0;  // @446_4a6610
  X0[2] = 0;  // @447_4a6610
  X0[3] = 0;  // @448_4a6610
  __builtin_memcpy((void *)((u32)(ebx + 262) + 0), &X0[0], 4);  // @449_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 188) + 0), 4); v; });  // @450_4a6610
  X0[1] = 0;  // @451_4a6610
  X0[2] = 0;  // @452_4a6610
  X0[3] = 0;  // @453_4a6610
  __builtin_memcpy((void *)((u32)(ebx + 266) + 0), &X0[0], 4);  // @454_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 116) + 0), 4); v; });  // @455_4a6610
  X0[1] = 0;  // @456_4a6610
  X0[2] = 0;  // @457_4a6610
  X0[3] = 0;  // @458_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @459_4a6610
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @460_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 24) + 0), 4); v; });  // @461_4a6610
  X0[1] = 0;  // @462_4a6610
  X0[2] = 0;  // @463_4a6610
  X0[3] = 0;  // @464_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @465_4a6610
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @466_4a6610
  edx = (edx - ecx);  // @467_4a6610
  FL[3] = edx;  // @468_4a6610
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @469_4a6610
  PV[25] = (u32)(ecx);  // @470_4a6610
  eax = ((eax >> 10) | (edx << 22));  // @471_4a6610
  ecx = edi;  // @472_4a6610
  esi = (esi + eax);  // @473_4a6610
  FL[3] = esi;  // @474_4a6610
  edx = (u32)((s32)edx >> (u32)(10));  // @475_4a6610
  FL[3] = edx;  // @476_4a6610
  eax = (u32)(ebx + 210);  // @477_4a6610
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @478_4a6610
  X0[0] = F2U((float)(s32)X0[0]);  // @479_4a6610
  X0[1] = F2U((float)(s32)X0[1]);  // @480_4a6610
  X0[2] = F2U((float)(s32)X0[2]);  // @481_4a6610
  X0[3] = F2U((float)(s32)X0[3]);  // @482_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @483_4a6610
  PV[26] = X0[0];  // @484_4a6610
  PV[27] = (u32)(eax);  // @485_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 288) + 64) + 0), &X0[0], 4);  // @486_4a6610
  eax = ext_4e7330_thiscall3(ecx, PV[27], PV[26]);  // @487_4a6610
  ecx = edx = 0;  // @488_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 180) + 0), 4); v; });  // @489_4a6610
  X0[1] = 0;  // @490_4a6610
  X0[2] = 0;  // @491_4a6610
  X0[3] = 0;  // @492_4a6610
  edx = (u32)((EBP - 280) + 180);  // @493_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 210) + 0), 4); v; })));  // @494_4a6610
  PV[28] = (u32)(ecx);  // @495_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 214) + 0), 4); v; });  // @496_4a6610
  X1[1] = 0;  // @497_4a6610
  X1[2] = 0;  // @498_4a6610
  X1[3] = 0;  // @499_4a6610
  ecx = (u32)((EBP - 284) + 196);  // @500_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 188) + 0), 4); v; })));  // @501_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @502_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 218) + 0), 4); v; });  // @503_4a6610
  X0[1] = 0;  // @504_4a6610
  X0[2] = 0;  // @505_4a6610
  X0[3] = 0;  // @506_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 192) + 0), 4); v; })));  // @507_4a6610
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @508_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 108) + 0), 4); v; });  // @509_4a6610
  X0[1] = 0;  // @510_4a6610
  X0[2] = 0;  // @511_4a6610
  X0[3] = 0;  // @512_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 196) + 0), &X0[0], 4);  // @513_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 112) + 0), 4); v; });  // @514_4a6610
  X0[1] = 0;  // @515_4a6610
  X0[2] = 0;  // @516_4a6610
  X0[3] = 0;  // @517_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 200) + 0), &X0[0], 4);  // @518_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 284) + 116) + 0), 4); v; });  // @519_4a6610
  X0[1] = 0;  // @520_4a6610
  X0[2] = 0;  // @521_4a6610
  X0[3] = 0;  // @522_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 20) + 0), &X1[0], 4);  // @523_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 284) + 204) + 0), &X0[0], 4);  // @524_4a6610
  eax = ext_451890_fastcall3(ecx, edx, (u32)(981668463));  // @525_4a6610
  ecx = 0;  // @526_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 16) + 0), 4); v; });  // @527_4a6610
  X0[1] = 0;  // @528_4a6610
  X0[2] = 0;  // @529_4a6610
  X0[3] = 0;  // @530_4a6610
  edx = (u32)((EBP - 280) + 180);  // @531_4a6610
  PV[29] = (u32)(ecx);  // @532_4a6610
  ecx = (u32)((EBP - 284) + 232);  // @533_4a6610
  PV[30] = X0[0];  // @534_4a6610
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[30]);  // @535_4a6610
    // @536_4a6610
  edx = (u32)((EBP - 280) + 228);  // @537_4a6610
  ecx = (u32)(ebx + 210);  // @538_4a6610
  eax = ext_43e960_fastcall2(ecx, edx);  // @539_4a6610
  ecx = edx = 0;  // @540_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 238) + 0), 4); v; });  // @541_4a6610
  X0[1] = 0;  // @542_4a6610
  X0[2] = 0;  // @543_4a6610
  X0[3] = 0;  // @544_4a6610
  PV[31] = (u32)(ecx);  // @545_4a6610
  ecx = (u32)(ebx + 210);  // @546_4a6610
  PV[32] = X0[0];  // @547_4a6610
  eax = ext_4e0d00_thiscall2(ecx, PV[32]);  // @548_4a6610
    // @549_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 242) + 0), 4); v; });  // @550_4a6610
  X0[1] = 0;  // @551_4a6610
  X0[2] = 0;  // @552_4a6610
  X0[3] = 0;  // @553_4a6610
  PV[33] = (u32)(ecx);  // @554_4a6610
  ecx = (u32)((EBP - 284) + 232);  // @555_4a6610
  PV[34] = X0[0];  // @556_4a6610
  eax = ext_4e0d00_thiscall2(ecx, PV[34]);  // @557_4a6610
    // @558_4a6610
  ecx = (u32)((EBP - 280) + 228);  // @559_4a6610
  eax = ext_4e09b0_thiscall1(ecx);  // @560_4a6610
    // @561_4a6610
  edx = (u32)((EBP - 280) + 228);  // @562_4a6610
  ecx = (u32)(ebx + 210);  // @563_4a6610
  eax = ext_441940_fastcall2(ecx, edx);  // @564_4a6610
  ecx = edx = 0;  // @565_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 214) + 0), 4); v; });  // @566_4a6610
  X1[1] = 0;  // @567_4a6610
  X1[2] = 0;  // @568_4a6610
  X1[3] = 0;  // @569_4a6610
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 210) + 0), 4); v; });  // @570_4a6610
  X2[1] = 0;  // @571_4a6610
  X2[2] = 0;  // @572_4a6610
  X2[3] = 0;  // @573_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 218) + 0), 4); v; });  // @574_4a6610
  X0[1] = 0;  // @575_4a6610
  X0[2] = 0;  // @576_4a6610
  X0[3] = 0;  // @577_4a6610
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @578_4a6610
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @579_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @580_4a6610
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @581_4a6610
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @582_4a6610
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @583_4a6610
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @584_4a6610
  ecx = edx = 0;  // @585_4a6610
  X1[0] = 0;  // @586_4a6610
  X1[1] = 0;  // @587_4a6610
  X1[2] = 0;  // @588_4a6610
  X1[3] = 0;  // @589_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 52), sizeof v); (u32)v; });  // @590_4a6610
  X2[0] = 0;  // @591_4a6610
  X2[1] = 0;  // @592_4a6610
  X2[2] = 0;  // @593_4a6610
  X2[3] = 0;  // @594_4a6610
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @595_4a6610
  X0[0] = X2[0];  // @596_4a6610
  X0[1] = X2[1];  // @597_4a6610
  X0[2] = X2[2];  // @598_4a6610
  X0[3] = X2[3];  // @599_4a6610
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788420) + 0), 4); v; })));  // @600_4a6610
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; })));  // @601_4a6610
  { float a_ = U2F(X0[0]), b_ = U2F(X1[0]); X0[0] = (a_ > b_) ? X0[0] : F2U(b_); }  // @602_4a6610
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @603_4a6610
  X1[1] = 0;  // @604_4a6610
  X1[2] = 0;  // @605_4a6610
  X1[3] = 0;  // @606_4a6610
  { float a_ = U2F(X1[0]), b_ = U2F(X0[0]); X1[0] = (a_ < b_) ? X1[0] : F2U(b_); }  // @607_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 16) + 0), &X1[0], 4);  // @608_4a6610
  FL[2] = (ecx & ecx);  // @609_4a6610
  if (FL[2] == 0) goto L4a6f04;  // @610_4a6610
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @611_4a6610
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @612_4a6610
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @613_4a6610
  if (__builtin_parity(FL[2] & 0xff)) goto L4a6f04;  // @614_4a6610
  PV[35] = (u32)(ecx);  // @615_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 48), sizeof v); (u32)v; });  // @616_4a6610
  eax = (u32)((EBP - 296) + 120);  // @617_4a6610
  PV[36] = (u32)(eax);  // @618_4a6610
  eax = (u32)((EBP - 300) + 260);  // @619_4a6610
  PV[37] = (u32)(eax);  // @620_4a6610
  eax = ext_4db3b0_thiscall1(ecx);  // @621_4a6610
  ecx = edx = 0;  // @622_4a6610
  ecx = eax;  // @623_4a6610
  eax = ext_43ec00_thiscall7(ecx, PV[37], PV[36], PV[35], (u32)(0), (u32)(0), (u32)(0));  // @624_4a6610
  ecx = edx = 0;  // @625_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @626_4a6610
  PV[38] = (u32)(eax);  // @627_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @628_4a6610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @629_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[38]);  // @630_4a6610
  ecx = edx = 0;  // @631_4a6610
  edi = eax;  // @632_4a6610
  FL[2] = (edi & edi);  // @633_4a6610
  if (FL[2] == 0) goto L4a6ef7;  // @634_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 16) + 0), 4); v; });  // @635_4a6610
  X0[1] = 0;  // @636_4a6610
  X0[2] = 0;  // @637_4a6610
  X0[3] = 0;  // @638_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })));  // @639_4a6610
  __builtin_memcpy((void *)((u32)(edi + 132) + 0), &X0[0], 4);  // @640_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @641_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @642_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @643_4a6610
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6881476), (u32)(373));  // @644_4a6610
  ecx = edx = 0;  // @645_4a6610
  FS[0] = (FS[0] - LDF((u32)(6792876)));  // @646_4a6610
  FS[0] = (FS[0] * LDF((u32)(6835440)));  // @647_4a6610
  STF((u32)((EBP - 280) + 16), FS[0]);  // @648_4a6610
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 16) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @649_4a6610
  eax = ecx;  // @650_4a6610
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; }));  // @651_4a6610
  FL[3] = eax;  // @652_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 96), &v, sizeof v); }  // @653_4a6610
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 100), &v, sizeof v); }  // @654_4a6610
  L4a6ef7:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 52), &v, sizeof v); }  // @656_4a6610
  goto L4a7074;  // @657_4a6610
  L4a6f04:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @659_4a6610
  if (FL[0] == FL[1]) goto L4a7077;  // @660_4a6610
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @661_4a6610
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @662_4a6610
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @663_4a6610
  if (__builtin_parity(FL[2] & 0xff)) goto L4a7077;  // @664_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @665_4a6610
  edx = (u32)((EBP - 280) + 124);  // @666_4a6610
  PV[39] = (u32)(edx);  // @667_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @668_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @669_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @670_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, PV[39]);  // @671_4a6610
  ecx = edx = 0;  // @672_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @673_4a6610
  PV[40] = (u32)(eax);  // @674_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @675_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @676_4a6610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @677_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, PV[40]);  // @678_4a6610
  ecx = edx = 0;  // @679_4a6610
  edi = 0;  // @680_4a6610
  FL[3] = edi;  // @681_4a6610
  FL[2] = (eax & eax);  // @682_4a6610
  if (FL[2] == 0) goto L4a6f6e;  // @683_4a6610
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; })) & 0xff);  // @684_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @685_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @686_4a6610
  eax = (edx & 0xff);  // @687_4a6610
  PV[41] = (u32)(eax);  // @688_4a6610
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @689_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 352)))(ecx, PV[41]);  // @690_4a6610
  ecx = edx = 0;  // @691_4a6610
  edi = eax;  // @692_4a6610
  L4a6f6e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @694_4a6610
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 132), sizeof v); (u32)v; });  // @695_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @696_4a6610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @697_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[42]);  // @698_4a6610
  ecx = edx = 0;  // @699_4a6610
  FL[2] = (eax & eax);  // @700_4a6610
  if (FL[2] == 0) goto L4a7074;  // @701_4a6610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @702_4a6610
  ecx = eax;  // @703_4a6610
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @704_4a6610
  ecx = edx = 0;  // @705_4a6610
  FL[2] = (eax & eax);  // @706_4a6610
  if (FL[2] == 0) goto L4a706c;  // @707_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @708_4a6610
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @709_4a6610
  if (FL[0] == FL[1]) goto L4a706c;  // @710_4a6610
  FL[2] = (edi & edi);  // @711_4a6610
  if (FL[2] == 0) goto L4a6fb9;  // @712_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @713_4a6610
  goto L4a6fcf;  // @714_4a6610
  L4a6fb9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @716_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @717_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(6840316));  // @718_4a6610
  ecx = edx = 0;  // @719_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @720_4a6610
  L4a6fcf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @722_4a6610
  PV[43] = (u32)(eax);  // @723_4a6610
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 284) + 40), sizeof v); (u32)v; });  // @724_4a6610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @725_4a6610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[44], PV[43]);  // @726_4a6610
  ecx = edx = 0;  // @727_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 32), sizeof v); (u32)v; });  // @728_4a6610
  PV[45] = (u32)(eax);  // @729_4a6610
  eax = (u32)((EBP - 296) + 120);  // @730_4a6610
  PV[46] = (u32)(eax);  // @731_4a6610
  eax = (u32)((EBP - 300) + 260);  // @732_4a6610
  PV[47] = (u32)(eax);  // @733_4a6610
  eax = ext_4db3b0_thiscall1(ecx);  // @734_4a6610
  ecx = edx = 0;  // @735_4a6610
  ecx = eax;  // @736_4a6610
  eax = ext_43ec00_thiscall7(ecx, PV[47], PV[46], PV[45], (u32)(0), (u32)(0), (u32)(0));  // @737_4a6610
  ecx = edx = 0;  // @738_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @739_4a6610
  PV[48] = (u32)(eax);  // @740_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @741_4a6610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @742_4a6610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[48]);  // @743_4a6610
  ecx = edx = 0;  // @744_4a6610
  edi = eax;  // @745_4a6610
  FL[2] = (edi & edi);  // @746_4a6610
  if (FL[2] == 0) goto L4a706c;  // @747_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 16) + 0), 4); v; });  // @748_4a6610
  X0[1] = 0;  // @749_4a6610
  X0[2] = 0;  // @750_4a6610
  X0[3] = 0;  // @751_4a6610
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })));  // @752_4a6610
  __builtin_memcpy((void *)((u32)(edi + 132) + 0), &X0[0], 4);  // @753_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @754_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @755_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @756_4a6610
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6881476), (u32)(403));  // @757_4a6610
  ecx = edx = 0;  // @758_4a6610
  FS[0] = (FS[0] - LDF((u32)(6792876)));  // @759_4a6610
  FS[0] = (FS[0] * LDF((u32)(6835440)));  // @760_4a6610
  STF((u32)((EBP - 280) + 16), FS[0]);  // @761_4a6610
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 16) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @762_4a6610
  eax = ecx;  // @763_4a6610
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; }));  // @764_4a6610
  FL[3] = eax;  // @765_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 96), &v, sizeof v); }  // @766_4a6610
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 100), &v, sizeof v); }  // @767_4a6610
  L4a706c:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 280) + 36), &v, sizeof v); }  // @769_4a6610
  L4a7074:;
  edi = (u32)(ebx + 72);  // @771_4a6610
  L4a7077:;
  PV[49] = (u32)(ecx);  // @773_4a6610
  edx = (u32)((EBP - 284) + 184);  // @774_4a6610
  ecx = (u32)(ebx + 210);  // @775_4a6610
  eax = ext_451890_fastcall3(ecx, edx, (u32)(981668463));  // @776_4a6610
  ecx = 0;  // @777_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 116) + 0), 4); v; });  // @778_4a6610
  X0[1] = 0;  // @779_4a6610
  X0[2] = 0;  // @780_4a6610
  X0[3] = 0;  // @781_4a6610
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6816064) + 0), 4); v; }));  // @782_4a6610
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L4a7111;  // @783_4a6610
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 28), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)((EBP - 280) + 28), &v, sizeof v); }  // @784_4a6610
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 28), sizeof v); (u32)v; });  // @785_4a6610
  if (FL[3] == 0) goto L4a7111;  // @786_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 56) + 0), 4); v; });  // @787_4a6610
  X0[1] = 0;  // @788_4a6610
  X0[2] = 0;  // @789_4a6610
  X0[3] = 0;  // @790_4a6610
  eax = (u32)(ebx + 222);  // @791_4a6610
  ecx = edi;  // @792_4a6610
  PV[50] = X0[0];  // @793_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 234) + 0), 4); v; });  // @794_4a6610
  X0[1] = 0;  // @795_4a6610
  X0[2] = 0;  // @796_4a6610
  X0[3] = 0;  // @797_4a6610
  PV[51] = X0[0];  // @798_4a6610
  PV[52] = (u32)(eax);  // @799_4a6610
  eax = (u32)(ebx + 210);  // @800_4a6610
  PV[53] = (u32)(eax);  // @801_4a6610
  eax = (u32)((EBP - 296) + 208);  // @802_4a6610
  PV[54] = (u32)(eax);  // @803_4a6610
  eax = ext_4e73b0_thiscall6(ecx, PV[54], PV[53], PV[52], PV[51], PV[50]);  // @804_4a6610
  ecx = edx = 0;  // @805_4a6610
  goto L4a6910;  // @806_4a6610
  L4a70e5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 192) + 0), 4); v; });  // @808_4a6610
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 192) + 4), 4); v; });  // @809_4a6610
  X0[2] = 0;  // @810_4a6610
  X0[3] = 0;  // @811_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 200), sizeof v); (u32)v; });  // @812_4a6610
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 270), &v, sizeof v); }  // @813_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 204) + 0), &X0[0], 4);  // @814_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 280) + 204) + 4), &X0[1], 4);  // @815_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 280) + 212), &v, sizeof v); }  // @816_4a6610
  goto L4a71a5;  // @817_4a6610
  L4a7111:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 192) + 0), 4); v; });  // @819_4a6610
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 280) + 192) + 4), 4); v; });  // @820_4a6610
  X0[2] = 0;  // @821_4a6610
  X0[3] = 0;  // @822_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 288) + 208), sizeof v); (u32)v; });  // @823_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 288) + 212) + 0), &X0[0], 4);  // @824_4a6610
  __builtin_memcpy((void *)((u32)((EBP - 288) + 212) + 4), &X0[1], 4);  // @825_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 288) + 32) + 0), 4); v; });  // @826_4a6610
  X0[1] = 0;  // @827_4a6610
  X0[2] = 0;  // @828_4a6610
  X0[3] = 0;  // @829_4a6610
  PV[55] = X0[0];  // @830_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 234) + 0), 4); v; });  // @831_4a6610
  X0[1] = 0;  // @832_4a6610
  X0[2] = 0;  // @833_4a6610
  X0[3] = 0;  // @834_4a6610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 288) + 220), &v, sizeof v); }  // @835_4a6610
  eax = (u32)(ebx + 222);  // @836_4a6610
  PV[56] = X0[0];  // @837_4a6610
  PV[57] = (u32)(eax);  // @838_4a6610
  eax = (u32)(ebx + 210);  // @839_4a6610
  PV[58] = (u32)(eax);  // @840_4a6610
  eax = (u32)((EBP - 296) + 208);  // @841_4a6610
  TPX = 1; PV[59] = PV[55]; PV[60] = PV[56]; PV[61] = PV[57]; PV[62] = PV[58];   /* w3g: this arm's five pushes feed the shared call at L4a719c, which was lifted with the other arm's PV numbers */
  goto L4a719c;  // @842_4a6610
  L4a7164:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 23), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @844_4a6610
  if (FL[0] == FL[1]) goto L4a71a5;  // @845_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 24) + 0), 4); v; });  // @846_4a6610
  X0[1] = 0;  // @847_4a6610
  X0[2] = 0;  // @848_4a6610
  X0[3] = 0;  // @849_4a6610
  eax = (u32)(ebx + 222);  // @850_4a6610
  PV[59] = X0[0];  // @851_4a6610
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 234) + 0), 4); v; });  // @852_4a6610
  X0[1] = 0;  // @853_4a6610
  X0[2] = 0;  // @854_4a6610
  X0[3] = 0;  // @855_4a6610
  PV[60] = X0[0];  // @856_4a6610
  PV[61] = (u32)(eax);  // @857_4a6610
  eax = (u32)(ebx + 210);  // @858_4a6610
  PV[62] = (u32)(eax);  // @859_4a6610
  eax = (u32)((EBP - 312) + 220);  // @860_4a6610
  L4a719c:;
  PV[63] = (u32)(eax);  // @862_4a6610
  ecx = (u32)(ebx + 72);  // @863_4a6610
  eax = ext_4e73b0_thiscall6(ecx, PV[63], PV[62], PV[61], PV[60], PV[59]);  // @864_4a6610
  ecx = edx = 0;  // @865_4a6610
  L4a71a5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 280) + 60), sizeof v); (u32)v; });  // @867_4a6610 (w3g: all pushes consumed here)
  eax = ecx;  // @868_4a6610
  eax = (~eax);  // @869_4a6610
  PV[64] = (u32)(eax);  // @870_4a6610
  PV[65] = (u32)(ecx);  // @871_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @872_4a6610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @873_4a6610
  eax = ext_4dc630_thiscall3(ecx, PV[65], PV[64]);  // @874_4a6610
  ecx = edx = 0;  // @875_4a6610
  L4a71ba:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @877_4a6610
  edx = (u32)((EBP - 280) + 204);  // @878_4a6610 (w3g experiment: TPX = 1 on the arm that comes through L4a7111)
  PV[66] = (u32)(edx);  // @879_4a6610
  edx = (u32)((EBP - 280 - 4 * TPX) + 244);  // @880_4a6610 (w3g)
  PV[67] = (u32)(edx);  // @881_4a6610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @882_4a6610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[67], PV[66]);  /* w3g: the call takes 2 stack arguments, the other four were stale pushes of other arms */  // @883_4a6610
  ecx = edx = 0;  // @884_4a6610
  L4a71d2:;
  ext_633654(G(u32, 0x6f5630));  // @886_4a6610
  return eax;  // @887_4a6610
}
// w3g-disabled: PCREG(4a6610, lifted_4a6610_w3gold);

