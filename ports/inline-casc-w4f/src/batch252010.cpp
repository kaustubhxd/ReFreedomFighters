// batch252010.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" long double FASTCALL ext_4e0870_fastcall2_ld(u32, u32) __asm__("ext_4e0870");
extern "C" long double THISCALL ext_4dda90_thiscall3_ld(u32, u32, u32) __asm__("ext_4dda90");
extern "C" u32 FASTCALL ext_4e0be0_fastcall2(u32, u32) __asm__("ext_4e0be0");
extern "C" u32 THISCALL ext_421080_thiscall1(u32) __asm__("ext_421080");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e290_cdecl2(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 STDCALL ext_63364e_stdcall4(u32, u32, u32, u32) __asm__("ext_63364e");
extern "C" double VECTORCALL ext_634db2_pow(double, double) __asm__("ext_634db2");
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

extern "C" u32 THISCALL lifted_421080(u32 ecx_in) {
  SEH_ENTER(0x664256);  // @h_421080
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 msgp = 6784320;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  ebx = ecx;  // @0_421080
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @1_421080
  eax = (u32)(EBP - 276);  // @2_421080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @3_421080
  PV[0] = (u32)(eax);  // @4_421080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @5_421080
  eax = ext_63364e_stdcall4((u32)(7083500), (u32)(0), (u32)(0), PV[0]);  // @6_421080
    // @7_421080
  FL[2] = (eax & eax);  // @8_421080
  if (FL[2] == 0) goto L421123;  // @9_421080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_421080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_421080
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6782900), (u32)(3185));  // @12_421080
  ecx = edx = 0;  // @13_421080
  L4210fd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_421080
  PV[1] = (u32)(eax);  // @16_421080
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], msgp);  // @17_421080
  ecx = edx = 0;  // @18_421080
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @19_421080
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676494))(PV[2]);  // @20_421080
  ecx = edx = 0;  // @21_421080
  ecx = ebx;  // @22_421080
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @23_421080
  ecx = edx = 0;  // @24_421080
  goto L421219;  // @25_421080
  L421123:;
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @27_421080
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6760dc))(PV[3], (u32)(0), (u32)(0));  // @28_421080
  ecx = edx = 0;  // @29_421080
  esi = eax;  // @30_421080
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @31_421080
  FL[2] = (esi & esi);  // @32_421080
  if (FL[2] != 0) goto L42115b;  // @33_421080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @34_421080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_421080
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6782900), (u32)(3196));  // @36_421080
  ecx = edx = 0;  // @37_421080
  msgp = 6784368; goto L4210fd;  // @38_421080
  L42115b:;
  ecx = 0;  // @40_421080
  FL[3] = ecx;  // @41_421080
  edx = (u32)(2);  // @42_421080
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @43_421080
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @44_421080
  FL[1] = ecx;  // @45_421080
  ecx = (0u - ecx);  // @46_421080
  ecx = (ecx | eax);  // @47_421080
  FL[3] = ecx;  // @48_421080
  PV[4] = (u32)(ecx);  // @49_421080
  eax = ext_41e290_cdecl1(PV[4]);  // @50_421080
  ecx = edx = 0;  // @51_421080
  edi = eax;  // @52_421080
  PV[5] = (u32)(esi);  // @53_421080
  PV[6] = (u32)(edi);  // @54_421080
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @55_421080
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6760dc))(PV[7], PV[6], PV[5]);  // @56_421080
  ecx = edx = 0;  // @57_421080
  PV[8] = (u32)(esi);  // @58_421080
  eax = ext_41e290_cdecl1(PV[8]);  // @59_421080
  ecx = edx = 0;  // @60_421080
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @61_421080
  esi = eax;  // @62_421080
  PV[10] = (u32)(edi);  // @63_421080
  PV[11] = (u32)(esi);  // @64_421080
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6762dc))(PV[11], PV[10], PV[9]);  // @65_421080
  ecx = edx = 0;  // @66_421080
  ecx = (u32)(EBP - 144);  // @67_421080
  PV[12] = (u32)(esi);  // @68_421080
  eax = ext_4cbe80_thiscall2(ecx, PV[12]);  // @69_421080
  ecx = edx = 0;  // @70_421080
  ecx = (u32)(EBP - 272);  // @71_421080
  reg.state = (s32)((u32)(0));  // @72_421080
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784428));  // @73_421080
  ecx = edx = 0;  // @74_421080
  eax = (u32)(EBP - 272);  // @75_421080
  reg.state = (s32)((u32)(1));  // @76_421080
  PV[13] = (u32)(eax);  // @77_421080
  ecx = (u32)(EBP - 144);  // @78_421080
  eax = ext_4cc2c0_thiscall2(ecx, PV[13]);  // @79_421080
  ecx = edx = 0;  // @80_421080
  ecx = (u32)(EBP - 272);  // @81_421080
  reg.state = (s32)((u32)(0));  // @82_421080
  eax = ext_4cbec0_thiscall1(ecx);  // @83_421080
  ecx = edx = 0;  // @84_421080
  PV[14] = (u32)(edi);  // @85_421080
  eax = ext_41e2c0_cdecl1(PV[14]);  // @86_421080
  ecx = edx = 0;  // @87_421080
  PV[15] = (u32)(esi);  // @88_421080
  eax = ext_41e2c0_cdecl1(PV[15]);  // @89_421080
  ecx = edx = 0;  // @90_421080
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @91_421080
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676494))(PV[16]);  // @92_421080
  ecx = edx = 0;  // @93_421080
  eax = (u32)(EBP - 144);  // @94_421080
  ecx = ebx;  // @95_421080
  PV[17] = (u32)(eax);  // @96_421080
  eax = ext_4cbe50_thiscall2(ecx, PV[17]);  // @97_421080
  ecx = edx = 0;  // @98_421080
  ecx = (u32)(EBP - 144);  // @99_421080
  eax = ext_4cbec0_thiscall1(ecx);  // @100_421080
  ecx = edx = 0;  // @101_421080
  L421219:;
  eax = ebx;  // @103_421080
  SEH_LEAVE();  // @104_421080
  ext_633654(G(u32, 0x6f5630));  // @105_421080
  return eax;  // @106_421080
}
PCREG(421080, lifted_421080);

extern "C" u32 THISCALL lifted_535780(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_535780
  esi = ecx;  // @1_535780
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_535780
  FL[2] = (ebx & ebx);  // @3_535780
  if (FL[2] == 0) goto L535911;  // @4_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_535780
  ecx = (u32)(EBP - 20);  // @6_535780
  PV[0] = (u32)(ecx);  // @7_535780
  ecx = ebx;  // @8_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @9_535780
  ecx = edx = 0;  // @10_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_535780
  ecx = (u32)(EBP - 20);  // @12_535780
  PV[1] = (u32)(ecx);  // @13_535780
  ecx = ebx;  // @14_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @15_535780
  ecx = edx = 0;  // @16_535780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @17_535780
  edx = eax;  // @18_535780
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @19_535780
  if (FL[0] == FL[1]) goto L535911;  // @20_535780
  L5357c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_535780
  PV[2] = (u32)(edx);  // @23_535780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[2]);  // @26_535780
  ecx = edx = 0;  // @27_535780
  edi = eax;  // @28_535780
  FL[2] = (edi & edi);  // @29_535780
  if (FL[2] == 0) goto L5358f6;  // @30_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @31_535780
  FL[2] = (eax & eax);  // @32_535780
  if (FL[2] == 0) goto L5358f6;  // @33_535780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_535780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @35_535780
  PV[3] = (u32)(eax);  // @36_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 64)))(ecx, PV[3]);  // @37_535780
  ecx = edx = 0;  // @38_535780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @39_535780
  PV[4] = (u32)(eax);  // @40_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 476)))(ecx, PV[4]);  // @41_535780
  ecx = edx = 0;  // @42_535780
  FL[2] = (eax & eax);  // @43_535780
  if (FL[2] == 0) goto L5358f3;  // @44_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @45_535780
  eax = (eax + (u32)(-2));  // @46_535780
  FL[3] = eax;  // @47_535780
  FL[0] = eax; FL[1] = (u32)(7);  // @48_535780
  if (FL[0] > FL[1]) goto L535847;  // @49_535780
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5462308), sizeof v); (u32)v; });  // @50_535780
  switch (eax) {  // @51_535780
  case 0: goto L53581a;  // @52_535780
  case 1: goto L535833;  // @53_535780
  default: __builtin_trap(); }  // @54_535780
  L53581a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 132) + 0), 4); v; });  // @56_535780
  X1[1] = 0;  // @57_535780
  X1[2] = 0;  // @58_535780
  X1[3] = 0;  // @59_535780
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @60_535780
  X0[1] = 0;  // @61_535780
  X0[2] = 0;  // @62_535780
  X0[3] = 0;  // @63_535780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @64_535780
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @65_535780
  goto L535895;  // @66_535780
  L535833:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; });  // @68_535780
  X1[1] = 0;  // @69_535780
  X1[2] = 0;  // @70_535780
  X1[3] = 0;  // @71_535780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @72_535780
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @73_535780
  goto L53588d;  // @74_535780
  L535847:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @76_535780
  edx = (u32)(edi + 212);  // @77_535780
  ecx = (u32)(esi + 110);  // @78_535780
  FS[0] = ext_4e0870_fastcall2_ld(ecx, edx);  // @79_535780
  ecx = edx = 0;  // @80_535780
  STF((u32)(EBP - 8), FS[0]);  // @81_535780
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @82_535780
  X0[1] = 0;  // @83_535780
  X0[2] = 0;  // @84_535780
  X0[3] = 0;  // @85_535780
  X1[0] = 0;  // @86_535780
  X1[1] = 0;  // @87_535780
  X1[2] = 0;  // @88_535780
  X1[3] = 0;  // @89_535780
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @90_535780
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @91_535780
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @92_535780
  if (!__builtin_parity(FL[2] & 0xff)) goto L535874;  // @93_535780
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @94_535780
  X0[1] = 0;  // @95_535780
  X0[2] = 0;  // @96_535780
  X0[3] = 0;  // @97_535780
  L535874:;
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 84) + 0), 4); v; })));  // @99_535780
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 136) + 0), 4); v; });  // @100_535780
  X1[1] = 0;  // @101_535780
  X1[2] = 0;  // @102_535780
  X1[3] = 0;  // @103_535780
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 132) + 0), 4); v; })));  // @104_535780
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @105_535780
  L53588d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @107_535780
  X0[1] = 0;  // @108_535780
  X0[2] = 0;  // @109_535780
  X0[3] = 0;  // @110_535780
  L535895:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @112_535780
  FL[0] = eax; FL[1] = (u32)(4);  // @113_535780
  if (FL[0] > FL[1]) goto L5358c6;  // @114_535780
  switch (eax) {  // @115_535780
  case 0: goto L5358a4;  // @116_535780
  case 1: goto L5358ae;  // @117_535780
  case 2: goto L5358c6;  // @118_535780
  case 3: goto L5358b8;  // @119_535780
  case 4: goto L5358c2;  // @120_535780
  default: __builtin_trap(); }  // @121_535780
  L5358a4:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; })));  // @123_535780
  goto L5358c6;  // @124_535780
  L5358ae:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @126_535780
  goto L5358c6;  // @127_535780
  L5358b8:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @129_535780
  goto L5358c6;  // @130_535780
  L5358c2:;
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @132_535780
  L5358c6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @134_535780
  X0[0] = X1[0];  // @135_535780
  X0[1] = X1[1];  // @136_535780
  X0[2] = X1[2];  // @137_535780
  X0[3] = X1[3];  // @138_535780
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @139_535780
  PV[5] = (u32)(ecx);  // @140_535780
  PV[6] = X1[0];  // @141_535780
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @142_535780
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @143_535780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 208), &v, sizeof v); }  // @144_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_535780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[7], PV[6], (u32)(0));  // @146_535780
  ecx = edx = 0;  // @147_535780
  goto L5358f6;  // @148_535780
  L5358f3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @150_535780
  L5358f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @152_535780
  ecx = (u32)(EBP - 20);  // @153_535780
  PV[8] = (u32)(ecx);  // @154_535780
  ecx = ebx;  // @155_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @156_535780
  ecx = edx = 0;  // @157_535780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @158_535780
  edx = eax;  // @159_535780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @160_535780
  if (FL[0] != FL[1]) goto L5357c0;  // @161_535780
  L535911:;
  return eax;  // @163_535780
}
PCREG(535780, lifted_535780);

extern "C" u32 THISCALL lifted_426d60(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66466b);  // @h_426d60
  u8 F[0x420] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x320);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x320 + 8, &a0, 4);
  __builtin_memcpy(F + 0x320 + 12, &a1, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 728), &v, sizeof v); }  // @0_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_426d60
  ecx = (u32)(EBP - 724);  // @2_426d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_426d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 732), &v, sizeof v); }  // @4_426d60
  eax = ext_421080_thiscall1(ecx);  // @5_426d60
  ecx = edx = 0;  // @6_426d60
  ecx = eax;  // @7_426d60
  reg.state = (s32)((u32)(0));  // @8_426d60
  eax = ext_4cc1d0_thiscall1(ecx);  // @9_426d60
    // @10_426d60
  edx = (u32)(EBP - 276);  // @11_426d60
  edx = (edx - eax);  // @12_426d60
  FL[3] = edx;  // @13_426d60
  L426dc1:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @15_426d60
  eax = (u32)(eax + 1);  // @16_426d60
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @17_426d60
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @18_426d60
  if (FL[2] != 0) goto L426dc1;  // @19_426d60
  ecx = (u32)(EBP - 724);  // @20_426d60
  reg.state = (s32)((u32)(4294967295));  // @21_426d60
  eax = ext_4cbec0_thiscall1(ecx);  // @22_426d60
  ecx = edx = 0;  // @23_426d60
  esi = ebx;  // @24_426d60
  L426de2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) & 0xff);  // @26_426d60
  ebx = (ebx + 1);  // @27_426d60
  FL[3] = ebx;  // @28_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @29_426d60
  if (FL[2] != 0) goto L426de2;  // @30_426d60
  edi = (u32)(EBP - 276);  // @31_426d60
  ebx = (ebx - esi);  // @32_426d60
  FL[3] = ebx;  // @33_426d60
  edi = (edi - 1);  // @34_426d60
  FL[3] = edi;  // @35_426d60
  L426df2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @37_426d60
  edi = (edi + 1);  // @38_426d60
  FL[3] = edi;  // @39_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @40_426d60
  if (FL[2] != 0) goto L426df2;  // @41_426d60
  ecx = ebx;  // @42_426d60
  ecx = (ecx >> (u32)(2));  // @43_426d60
  FL[3] = ecx;  // @44_426d60
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @45_426d60
  ecx = ebx;  // @46_426d60
  ecx = (ecx & (u32)(3));  // @47_426d60
  FL[3] = ecx;  // @48_426d60
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @49_426d60
  edi = (u32)(EBP - 276);  // @50_426d60
  edi = (edi - 1);  // @51_426d60
  FL[3] = edi;  // @52_426d60
  L426e10:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @54_426d60
  edi = (u32)(edi + 1);  // @55_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @56_426d60
  if (FL[2] != 0) goto L426e10;  // @57_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @58_426d60
  edx = (u32)(EBP - 276);  // @59_426d60
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @60_426d60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @61_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_426d60
  PV[0] = (u32)(edx);  // @63_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @64_426d60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[0], (u32)(0));  // @65_426d60
  ecx = edx = 0;  // @66_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @67_426d60
  if (FL[2] != 0) goto L426e4f;  // @68_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 728), sizeof v); (u32)v; });  // @69_426d60
  edx = (u32)(EBP - 276);  // @70_426d60
  PV[1] = (u32)(edx);  // @71_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_426d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @73_426d60
  ecx = edx = 0;  // @74_426d60
  L426e4f:;
  edi = (u32)(EBP - 276);  // @76_426d60
  edi = (edi - 1);  // @77_426d60
  FL[3] = edi;  // @78_426d60
  L426e56:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @80_426d60
  edi = (u32)(edi + 1);  // @81_426d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @82_426d60
  if (FL[2] != 0) goto L426e56;  // @83_426d60
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6786308), sizeof v); (u32)v; })) & 0xffff);  // @84_426d60
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @85_426d60
  eax = (u32)(EBP - 596);  // @86_426d60
  PV[2] = (u32)(eax);  // @87_426d60
  eax = (u32)(EBP - 276);  // @88_426d60
  PV[3] = (u32)(eax);  // @89_426d60
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67610c))(PV[3], PV[2]);  // @90_426d60
  ecx = edx = 0;  // @91_426d60
  esi = eax;  // @92_426d60
  FL[0] = esi; FL[1] = (u32)(-1);  // @93_426d60
  if (FL[0] == FL[1]) goto L426f32;  // @94_426d60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775056), sizeof v); (u32)v; });  // @95_426d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @96_426d60
  L426e94:;
  eax = (u32)(EBP - 552);  // @98_426d60
  PV[4] = (u32)(eax);  // @99_426d60
  eax = ((u32( *)(u32, u32))(ebx))(PV[4], (u32)(46));  // @100_426d60
  ecx = edx = 0;  // @101_426d60
  FL[2] = (eax & eax);  // @102_426d60
  if (FL[2] == 0) goto L426edd;  // @103_426d60
  ecx = (u32)(6786312);  // @104_426d60
  L426eb0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @106_426d60
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_426d60
  if (FL[0] != FL[1]) goto L426ed0;  // @108_426d60
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @109_426d60
  if (FL[2] == 0) goto L426ecc;  // @110_426d60
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @111_426d60
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @112_426d60
  if (FL[0] != FL[1]) goto L426ed0;  // @113_426d60
  eax = (eax + (u32)(2));  // @114_426d60
  FL[3] = eax;  // @115_426d60
  ecx = (ecx + (u32)(2));  // @116_426d60
  FL[3] = ecx;  // @117_426d60
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @118_426d60
  if (FL[2] != 0) goto L426eb0;  // @119_426d60
  L426ecc:;
  eax = 0;  // @121_426d60
  FL[3] = eax;  // @122_426d60
  goto L426ed5;  // @123_426d60
  L426ed0:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @125_426d60
  eax = (eax | (u32)(1));  // @126_426d60
  FL[3] = eax;  // @127_426d60
  L426ed5:;
  FL[2] = (eax & eax);  // @129_426d60
  if (FL[2] != 0) goto L426edd;  // @130_426d60
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @131_426d60
  goto L426edf;  // @132_426d60
  L426edd:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @134_426d60
  FL[3] = (eax & 0xff);  // @135_426d60
  L426edf:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 552), sizeof v); (u32)v; }); FL[1] = (u32)(46);  // @137_426d60
  if (FL[0] != FL[1]) goto L426f00;  // @138_426d60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 551), sizeof v); (u32)v; })) & 0xff);  // @139_426d60
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @140_426d60
  if (FL[2] == 0) goto L426f19;  // @141_426d60
  FL[0] = (ecx & 0xff); FL[1] = (u32)(46);  // @142_426d60
  if (FL[0] != FL[1]) goto L426f00;  // @143_426d60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 550), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @144_426d60
  if (FL[0] == FL[1]) goto L426f19;  // @145_426d60
  L426f00:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @147_426d60
  if (FL[2] == 0) goto L426f19;  // @148_426d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 732), sizeof v); (u32)v; });  // @149_426d60
  edx = (u32)(EBP - 552);  // @150_426d60
  PV[5] = (u32)(edx);  // @151_426d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_426d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[5]);  // @153_426d60
  ecx = edx = 0;  // @154_426d60
  L426f19:;
  eax = (u32)(EBP - 596);  // @156_426d60
  PV[6] = (u32)(eax);  // @157_426d60
  PV[7] = (u32)(esi);  // @158_426d60
  eax = ((u32(STDCALL *)(u32, u32))(edi))(PV[7], PV[6]);  // @159_426d60
  ecx = edx = 0;  // @160_426d60
  FL[2] = (eax & eax);  // @161_426d60
  if (FL[2] != 0) goto L426e94;  // @162_426d60
  PV[8] = (u32)(esi);  // @163_426d60
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676108))(PV[8]);  // @164_426d60
  ecx = edx = 0;  // @165_426d60
  L426f32:;
  SEH_LEAVE();  // @167_426d60
  ext_633654(G(u32, 0x6f5630));  // @168_426d60
  return eax;  // @169_426d60
}
PCREG(426d60, lifted_426d60);

extern "C" u32 THISCALL lifted_5398f0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956288) + 0), 4); v; });  // @0_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956288) + 4), 4); v; });  // @1_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956288) + 8), 4); v; });  // @2_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956288) + 12), 4); v; });  // @3_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 408) + 0), &X0[0], 4);  // @4_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 408) + 4), &X0[1], 4);  // @5_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 408) + 8), &X0[2], 4);  // @6_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 408) + 12), &X0[3], 4);  // @7_5398f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @8_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956304) + 0), 4); v; });  // @9_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956304) + 4), 4); v; });  // @10_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956304) + 8), 4); v; });  // @11_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956304) + 12), 4); v; });  // @12_5398f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @13_5398f0
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @14_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 392) + 0), &X0[0], 4);  // @15_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 392) + 4), &X0[1], 4);  // @16_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 392) + 8), &X0[2], 4);  // @17_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 392) + 12), &X0[3], 4);  // @18_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956320) + 0), 4); v; });  // @19_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956320) + 4), 4); v; });  // @20_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956320) + 8), 4); v; });  // @21_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956320) + 12), 4); v; });  // @22_5398f0
  ebx = ecx;  // @23_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 376) + 0), &X0[0], 4);  // @24_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 376) + 4), &X0[1], 4);  // @25_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 376) + 8), &X0[2], 4);  // @26_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 376) + 12), &X0[3], 4);  // @27_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956336) + 0), 4); v; });  // @28_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956336) + 4), 4); v; });  // @29_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956336) + 8), 4); v; });  // @30_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956336) + 12), 4); v; });  // @31_5398f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @32_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 360) + 0), &X0[0], 4);  // @33_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 360) + 4), &X0[1], 4);  // @34_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 360) + 8), &X0[2], 4);  // @35_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 360) + 12), &X0[3], 4);  // @36_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956352) + 0), 4); v; });  // @37_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956352) + 4), 4); v; });  // @38_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956352) + 8), 4); v; });  // @39_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956352) + 12), 4); v; });  // @40_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 344) + 0), &X0[0], 4);  // @41_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 344) + 4), &X0[1], 4);  // @42_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 344) + 8), &X0[2], 4);  // @43_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 344) + 12), &X0[3], 4);  // @44_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956368) + 0), 4); v; });  // @45_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956368) + 4), 4); v; });  // @46_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956368) + 8), 4); v; });  // @47_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956368) + 12), 4); v; });  // @48_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 328) + 0), &X0[0], 4);  // @49_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 328) + 4), &X0[1], 4);  // @50_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 328) + 8), &X0[2], 4);  // @51_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 328) + 12), &X0[3], 4);  // @52_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956384) + 0), 4); v; });  // @53_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956384) + 4), 4); v; });  // @54_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956384) + 8), 4); v; });  // @55_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956384) + 12), 4); v; });  // @56_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 312) + 0), &X0[0], 4);  // @57_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 312) + 4), &X0[1], 4);  // @58_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 312) + 8), &X0[2], 4);  // @59_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 312) + 12), &X0[3], 4);  // @60_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956400) + 0), 4); v; });  // @61_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956400) + 4), 4); v; });  // @62_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956400) + 8), 4); v; });  // @63_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956400) + 12), 4); v; });  // @64_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 296) + 0), &X0[0], 4);  // @65_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 296) + 4), &X0[1], 4);  // @66_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 296) + 8), &X0[2], 4);  // @67_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 296) + 12), &X0[3], 4);  // @68_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956416) + 0), 4); v; });  // @69_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956416) + 4), 4); v; });  // @70_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956416) + 8), 4); v; });  // @71_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956416) + 12), 4); v; });  // @72_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 280) + 0), &X0[0], 4);  // @73_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 280) + 4), &X0[1], 4);  // @74_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 280) + 8), &X0[2], 4);  // @75_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 280) + 12), &X0[3], 4);  // @76_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956432) + 0), 4); v; });  // @77_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956432) + 4), 4); v; });  // @78_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956432) + 8), 4); v; });  // @79_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956432) + 12), 4); v; });  // @80_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 264) + 0), &X0[0], 4);  // @81_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 264) + 4), &X0[1], 4);  // @82_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 264) + 8), &X0[2], 4);  // @83_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 264) + 12), &X0[3], 4);  // @84_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956448) + 0), 4); v; });  // @85_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956448) + 4), 4); v; });  // @86_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956448) + 8), 4); v; });  // @87_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956448) + 12), 4); v; });  // @88_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 248) + 0), &X0[0], 4);  // @89_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 248) + 4), &X0[1], 4);  // @90_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 248) + 8), &X0[2], 4);  // @91_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 248) + 12), &X0[3], 4);  // @92_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956464) + 0), 4); v; });  // @93_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956464) + 4), 4); v; });  // @94_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956464) + 8), 4); v; });  // @95_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956464) + 12), 4); v; });  // @96_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 232) + 0), &X0[0], 4);  // @97_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 232) + 4), &X0[1], 4);  // @98_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 232) + 8), &X0[2], 4);  // @99_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 232) + 12), &X0[3], 4);  // @100_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956480) + 0), 4); v; });  // @101_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956480) + 4), 4); v; });  // @102_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956480) + 8), 4); v; });  // @103_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956480) + 12), 4); v; });  // @104_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 216) + 0), &X0[0], 4);  // @105_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 216) + 4), &X0[1], 4);  // @106_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 216) + 8), &X0[2], 4);  // @107_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 216) + 12), &X0[3], 4);  // @108_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956496) + 0), 4); v; });  // @109_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956496) + 4), 4); v; });  // @110_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956496) + 8), 4); v; });  // @111_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956496) + 12), 4); v; });  // @112_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 200) + 0), &X0[0], 4);  // @113_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 200) + 4), &X0[1], 4);  // @114_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 200) + 8), &X0[2], 4);  // @115_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 200) + 12), &X0[3], 4);  // @116_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956512) + 0), 4); v; });  // @117_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956512) + 4), 4); v; });  // @118_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956512) + 8), 4); v; });  // @119_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956512) + 12), 4); v; });  // @120_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 184) + 0), &X0[0], 4);  // @121_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 184) + 4), &X0[1], 4);  // @122_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 184) + 8), &X0[2], 4);  // @123_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 184) + 12), &X0[3], 4);  // @124_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956528) + 0), 4); v; });  // @125_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956528) + 4), 4); v; });  // @126_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956528) + 8), 4); v; });  // @127_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956528) + 12), 4); v; });  // @128_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 168) + 0), &X0[0], 4);  // @129_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 168) + 4), &X0[1], 4);  // @130_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 168) + 8), &X0[2], 4);  // @131_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 168) + 12), &X0[3], 4);  // @132_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956544) + 0), 4); v; });  // @133_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956544) + 4), 4); v; });  // @134_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956544) + 8), 4); v; });  // @135_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956544) + 12), 4); v; });  // @136_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 152) + 0), &X0[0], 4);  // @137_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 152) + 4), &X0[1], 4);  // @138_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 152) + 8), &X0[2], 4);  // @139_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 152) + 12), &X0[3], 4);  // @140_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956560) + 0), 4); v; });  // @141_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956560) + 4), 4); v; });  // @142_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956560) + 8), 4); v; });  // @143_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956560) + 12), 4); v; });  // @144_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 136) + 0), &X0[0], 4);  // @145_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 136) + 4), &X0[1], 4);  // @146_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 136) + 8), &X0[2], 4);  // @147_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 136) + 12), &X0[3], 4);  // @148_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956576) + 0), 4); v; });  // @149_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956576) + 4), 4); v; });  // @150_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956576) + 8), 4); v; });  // @151_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956576) + 12), 4); v; });  // @152_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 120) + 0), &X0[0], 4);  // @153_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 120) + 4), &X0[1], 4);  // @154_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 120) + 8), &X0[2], 4);  // @155_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 120) + 12), &X0[3], 4);  // @156_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956592) + 0), 4); v; });  // @157_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956592) + 4), 4); v; });  // @158_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956592) + 8), 4); v; });  // @159_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956592) + 12), 4); v; });  // @160_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 104) + 0), &X0[0], 4);  // @161_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 104) + 4), &X0[1], 4);  // @162_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 104) + 8), &X0[2], 4);  // @163_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 104) + 12), &X0[3], 4);  // @164_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956608) + 0), 4); v; });  // @165_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956608) + 4), 4); v; });  // @166_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956608) + 8), 4); v; });  // @167_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956608) + 12), 4); v; });  // @168_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 88) + 0), &X0[0], 4);  // @169_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 88) + 4), &X0[1], 4);  // @170_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 88) + 8), &X0[2], 4);  // @171_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 88) + 12), &X0[3], 4);  // @172_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956624) + 0), 4); v; });  // @173_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956624) + 4), 4); v; });  // @174_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956624) + 8), 4); v; });  // @175_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956624) + 12), 4); v; });  // @176_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @177_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 4), &X0[1], 4);  // @178_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 8), &X0[2], 4);  // @179_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 12), &X0[3], 4);  // @180_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956640) + 0), 4); v; });  // @181_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956640) + 4), 4); v; });  // @182_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956640) + 8), 4); v; });  // @183_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956640) + 12), 4); v; });  // @184_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @185_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 4), &X0[1], 4);  // @186_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 8), &X0[2], 4);  // @187_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 12), &X0[3], 4);  // @188_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956656) + 0), 4); v; });  // @189_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956656) + 4), 4); v; });  // @190_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956656) + 8), 4); v; });  // @191_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956656) + 12), 4); v; });  // @192_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @193_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 4), &X0[1], 4);  // @194_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 8), &X0[2], 4);  // @195_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 12), &X0[3], 4);  // @196_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956672) + 0), 4); v; });  // @197_5398f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956672) + 4), 4); v; });  // @198_5398f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956672) + 8), 4); v; });  // @199_5398f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956672) + 12), 4); v; });  // @200_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @201_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 4), &X0[1], 4);  // @202_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 8), &X0[2], 4);  // @203_5398f0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 12), &X0[3], 4);  // @204_5398f0
  X0[0] = 0;  // @205_5398f0
  X0[1] = 0;  // @206_5398f0
  X0[2] = 0;  // @207_5398f0
  X0[3] = 0;  // @208_5398f0
  X1[0] = F2U((float)(s32)X1[0]);  // @209_5398f0
  X1[1] = F2U((float)(s32)X1[1]);  // @210_5398f0
  X1[2] = F2U((float)(s32)X1[2]);  // @211_5398f0
  X1[3] = F2U((float)(s32)X1[3]);  // @212_5398f0
  FL[0] = eax; FL[1] = (u32)(1);  // @213_5398f0
  if (FL[0] != FL[1]) goto L539aab;  // @214_5398f0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @215_5398f0
  X2[1] = 0;  // @216_5398f0
  X2[2] = 0;  // @217_5398f0
  X2[3] = 0;  // @218_5398f0
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @219_5398f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @220_5398f0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @221_5398f0
  if (__builtin_parity(FL[2] & 0xff)) goto L539ad2;  // @222_5398f0
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @223_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891408) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891408) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @224_5398f0
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; })));  // @225_5398f0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @226_5398f0
  { double r_ = ext_634db2_pow(U2D(X0[0], X0[1]), U2D(X1[0], X1[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @227_5398f0
    // @228_5398f0
  X1[0] = 0;  // @229_5398f0
  X1[1] = 0;  // @230_5398f0
  X1[2] = 0;  // @231_5398f0
  X1[3] = 0;  // @232_5398f0
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @233_5398f0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @234_5398f0
  goto L539acf;  // @235_5398f0
  L539aab:;
  FL[0] = eax; FL[1] = (u32)(2);  // @237_5398f0
  if (FL[0] != FL[1]) goto L539ad2;  // @238_5398f0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @239_5398f0
  if ((!(FA >= FB))) goto L539ad2;  // @240_5398f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @241_5398f0
  X0[1] = 0;  // @242_5398f0
  X0[2] = 0;  // @243_5398f0
  X0[3] = 0;  // @244_5398f0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @245_5398f0
  if ((!(FA >= FB))) goto L539acf;  // @246_5398f0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @247_5398f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + eax*4 - 408) + 0), 4); v; });  // @248_5398f0
  X1[1] = 0;  // @249_5398f0
  X1[2] = 0;  // @250_5398f0
  X1[3] = 0;  // @251_5398f0
  L539acf:;
  X0[0] = 0;  // @253_5398f0
  X0[1] = 0;  // @254_5398f0
  X0[2] = 0;  // @255_5398f0
  X0[3] = 0;  // @256_5398f0
  L539ad2:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; })));  // @258_5398f0
  FL[0] = edi; FL[1] = (u32)(3);  // @259_5398f0
  if (FL[0] > FL[1]) goto L539b02;  // @260_5398f0
  switch (edi) {  // @261_5398f0
  case 0: goto L539ae6;  // @262_5398f0
  case 1: goto L539af0;  // @263_5398f0
  case 2: goto L539afa;  // @264_5398f0
  case 3: goto L539b02;  // @265_5398f0
  default: __builtin_trap(); }  // @266_5398f0
  L539ae6:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956252) + 0), 4); v; })));  // @268_5398f0
  goto L539b02;  // @269_5398f0
  L539af0:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956248) + 0), 4); v; })));  // @271_5398f0
  goto L539b02;  // @272_5398f0
  L539afa:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956256) + 0), 4); v; })));  // @274_5398f0
  L539b02:;
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @276_5398f0
  eax = (u32)(ebx + edi*8);  // @277_5398f0
  __builtin_memcpy((void *)((u32)(edi + eax + 20825) + 0), &X1[0], 4);  // @278_5398f0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L539ba7;  // @279_5398f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax + 20829), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @280_5398f0
  if (FL[0] != FL[1]) goto L539b9d;  // @281_5398f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20649), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @282_5398f0
  if (FL[0] != FL[1]) goto L539b9d;  // @283_5398f0
  esi = (u32)(ebx + 21426);  // @284_5398f0
  FL[2] = (esi & esi);  // @285_5398f0
  if (FL[2] == 0) goto L539b9c;  // @286_5398f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @287_5398f0
  ecx = (u32)(EBP - 420);  // @288_5398f0
  PV[0] = (u32)(ecx);  // @289_5398f0
  ecx = esi;  // @290_5398f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @291_5398f0
  ecx = edx = 0;  // @292_5398f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @293_5398f0
  ecx = (u32)(EBP - 420);  // @294_5398f0
  PV[1] = (u32)(ecx);  // @295_5398f0
  ecx = esi;  // @296_5398f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @297_5398f0
  ecx = edx = 0;  // @298_5398f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @299_5398f0
  if (FL[0] == FL[1]) goto L539b99;  // @300_5398f0
  L539b60:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @302_5398f0
  PV[2] = (u32)(eax);  // @303_5398f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @304_5398f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @305_5398f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[2]);  // @306_5398f0
  ecx = edx = 0;  // @307_5398f0
  FL[2] = (eax & eax);  // @308_5398f0
  if (FL[2] == 0) goto L539b82;  // @309_5398f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; }); FL[1] = edi;  // @310_5398f0
  if (FL[0] != FL[1]) goto L539b82;  // @311_5398f0
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @312_5398f0
  L539b82:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @314_5398f0
  ecx = (u32)(EBP - 420);  // @315_5398f0
  PV[3] = (u32)(ecx);  // @316_5398f0
  ecx = esi;  // @317_5398f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @318_5398f0
  ecx = edx = 0;  // @319_5398f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @320_5398f0
  if (FL[0] != FL[1]) goto L539b60;  // @321_5398f0
  L539b99:;
  eax = (u32)(ebx + edi*8);  // @323_5398f0
  L539b9c:;
  L539b9d:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + eax + 20829), &v, sizeof v); }  // @326_5398f0
  goto L539baf;  // @327_5398f0
  L539ba7:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + eax + 20829), &v, sizeof v); }  // @329_5398f0
  L539baf:;
  ext_633654(G(u32, 0x6f5630));  // @331_5398f0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 20807), &v, sizeof v); }  // @332_5398f0
  return eax;  // @333_5398f0
}
PCREG(5398f0, lifted_5398f0);

extern "C" u32 FASTCALL lifted_4fd2a0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_4fd2a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @1_4fd2a0
  X6[0] = 0;  // @2_4fd2a0
  X6[1] = 0;  // @3_4fd2a0
  X6[2] = 0;  // @4_4fd2a0
  X6[3] = 0;  // @5_4fd2a0
  eax = (u32)(EBP - 48);  // @6_4fd2a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @7_4fd2a0
  X7[0] = X6[0];  // @8_4fd2a0
  X7[1] = X6[1];  // @9_4fd2a0
  X7[2] = X6[2];  // @10_4fd2a0
  X7[3] = X6[3];  // @11_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @12_4fd2a0
  X0[1] = 0;  // @13_4fd2a0
  X0[2] = 0;  // @14_4fd2a0
  X0[3] = 0;  // @15_4fd2a0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @16_4fd2a0
  X5[1] = 0;  // @17_4fd2a0
  X5[2] = 0;  // @18_4fd2a0
  X5[3] = 0;  // @19_4fd2a0
  FA = U2F(X0[0]); FB = U2F(X6[0]);  // @20_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @21_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X7[0], 4);  // @22_4fd2a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @23_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X5[0], 4);  // @24_4fd2a0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @25_4fd2a0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4fd2ed;  // @26_4fd2a0
  FA = U2F(X5[0]); FB = U2F(X6[0]);  // @27_4fd2a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @28_4fd2a0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @29_4fd2a0
  if (__builtin_parity(FL[2] & 0xff)) goto L4fd338;  // @30_4fd2a0
  L4fd2ed:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @32_4fd2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @33_4fd2a0
  FS[0] = LDF((u32)(ecx));  // @34_4fd2a0
  FS[0] = (FS[0] * FS[0]);  // @35_4fd2a0
  FS[1] = LDF((u32)(ecx + 4));  // @36_4fd2a0
  FS[1] = (FS[1] * FS[1]);  // @37_4fd2a0
  FS[0] = (FS[0] + FS[1]);  // @38_4fd2a0
  FS[1] = LDF((u32)(ecx + 8));  // @39_4fd2a0
  FS[1] = (FS[1] * FS[1]);  // @40_4fd2a0
  FS[0] = (FS[0] + FS[1]);  // @41_4fd2a0
  FSQRT(FS[0]);  // @42_4fd2a0
  FS[1] = LDF((u32)(EBP - 20));  // @43_4fd2a0
  FS[1] = (FS[1] / FS[0]);  // @44_4fd2a0
  FS[2] = LDF((u32)(ecx));  // @45_4fd2a0
  FS[2] = (FS[2] * FS[1]);  // @46_4fd2a0
  STF((u32)(ecx), FS[2]);  // @47_4fd2a0
  FS[2] = LDF((u32)(ecx + 4));  // @48_4fd2a0
  FS[2] = (FS[2] * FS[1]);  // @49_4fd2a0
  STF((u32)(ecx + 4), FS[2]);  // @50_4fd2a0
  FS[2] = LDF((u32)(ecx + 8));  // @51_4fd2a0
  FS[1] = (FS[1] * FS[2]);  // @52_4fd2a0
  STF((u32)(ecx + 8), FS[1]);  // @53_4fd2a0
  STF((u32)(EBP - 20), FS[0]);  // @54_4fd2a0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @55_4fd2a0
  X5[1] = 0;  // @56_4fd2a0
  X5[2] = 0;  // @57_4fd2a0
  X5[3] = 0;  // @58_4fd2a0
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @59_4fd2a0
  X7[1] = 0;  // @60_4fd2a0
  X7[2] = 0;  // @61_4fd2a0
  X7[3] = 0;  // @62_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @63_4fd2a0
  X0[1] = 0;  // @64_4fd2a0
  X0[2] = 0;  // @65_4fd2a0
  X0[3] = 0;  // @66_4fd2a0
  L4fd338:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @68_4fd2a0
  X4[1] = 0;  // @69_4fd2a0
  X4[2] = 0;  // @70_4fd2a0
  X4[3] = 0;  // @71_4fd2a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @72_4fd2a0
  X1[1] = 0;  // @73_4fd2a0
  X1[2] = 0;  // @74_4fd2a0
  X1[3] = 0;  // @75_4fd2a0
  X3[0] = X4[0];  // @76_4fd2a0
  X3[1] = X4[1];  // @77_4fd2a0
  X3[2] = X4[2];  // @78_4fd2a0
  X3[3] = X4[3];  // @79_4fd2a0
  X3[0] = F2U(U2F(X3[0]) * U2F(X0[0]));  // @80_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @81_4fd2a0
  X0[1] = 0;  // @82_4fd2a0
  X0[2] = 0;  // @83_4fd2a0
  X0[3] = 0;  // @84_4fd2a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X7[0]));  // @85_4fd2a0
  X4[0] = F2U(U2F(X4[0]) * U2F(X6[0]));  // @86_4fd2a0
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @87_4fd2a0
  X0[0] = X1[0];  // @88_4fd2a0
  X0[1] = X1[1];  // @89_4fd2a0
  X0[2] = X1[2];  // @90_4fd2a0
  X0[3] = X1[3];  // @91_4fd2a0
  X1[0] = F2U(U2F(X1[0]) * U2F(X6[0]));  // @92_4fd2a0
  X4[0] = F2U(U2F(X4[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @93_4fd2a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @94_4fd2a0
  X4[0] = F2U(U2F(X4[0]) + U2F(X1[0]));  // @95_4fd2a0
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @96_4fd2a0
  PV[0] = X4[0];  // @97_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X4[0], 4);  // @98_4fd2a0
  PV[1] = X3[0];  // @99_4fd2a0
  FS[0] = ext_4dda90_thiscall3_ld(ecx, PV[1], PV[0]);  // @100_4fd2a0
  ecx = edx = 0;  // @101_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @102_4fd2a0
  X0[1] = 0;  // @103_4fd2a0
  X0[2] = 0;  // @104_4fd2a0
  X0[3] = 0;  // @105_4fd2a0
  STF((u32)(EBP - 20), FS[0]);  // @106_4fd2a0
  PV[2] = X0[0];  // @107_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @108_4fd2a0
  X0[1] = 0;  // @109_4fd2a0
  X0[2] = 0;  // @110_4fd2a0
  X0[3] = 0;  // @111_4fd2a0
  PV[3] = X0[0];  // @112_4fd2a0
  FS[0] = ext_4dda90_thiscall3_ld(ecx, PV[3], PV[2]);  // @113_4fd2a0
  ecx = edx = 0;  // @114_4fd2a0
  STF((u32)(EBP - 28), FS[0]);  // @115_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @116_4fd2a0
  X0[1] = 0;  // @117_4fd2a0
  X0[2] = 0;  // @118_4fd2a0
  X0[3] = 0;  // @119_4fd2a0
  edx = (u32)(EBP - 16);  // @120_4fd2a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @121_4fd2a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @122_4fd2a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @123_4fd2a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @124_4fd2a0
  ecx = esi;  // @125_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @126_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @127_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @128_4fd2a0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @129_4fd2a0
  ecx = edx = 0;  // @130_4fd2a0
  X0[0] = 0;  // @131_4fd2a0
  X0[1] = 0;  // @132_4fd2a0
  X0[2] = 0;  // @133_4fd2a0
  X0[3] = 0;  // @134_4fd2a0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; }));  // @135_4fd2a0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4fd3fa;  // @136_4fd2a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6931948) + 0), 4); v; });  // @137_4fd2a0
  X1[1] = 0;  // @138_4fd2a0
  X1[2] = 0;  // @139_4fd2a0
  X1[3] = 0;  // @140_4fd2a0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @141_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X1[0], 4);  // @142_4fd2a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6931952) + 0), 4); v; });  // @143_4fd2a0
  X1[1] = 0;  // @144_4fd2a0
  X1[2] = 0;  // @145_4fd2a0
  X1[3] = 0;  // @146_4fd2a0
  goto L4fd414;  // @147_4fd2a0
  L4fd3fa:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6931956) + 0), 4); v; });  // @149_4fd2a0
  X1[1] = 0;  // @150_4fd2a0
  X1[2] = 0;  // @151_4fd2a0
  X1[3] = 0;  // @152_4fd2a0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @153_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X1[0], 4);  // @154_4fd2a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6931944) + 0), 4); v; });  // @155_4fd2a0
  X1[1] = 0;  // @156_4fd2a0
  X1[2] = 0;  // @157_4fd2a0
  X1[3] = 0;  // @158_4fd2a0
  L4fd414:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @160_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @161_4fd2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @162_4fd2a0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @163_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @164_4fd2a0
  X0[1] = 0;  // @165_4fd2a0
  X0[2] = 0;  // @166_4fd2a0
  X0[3] = 0;  // @167_4fd2a0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @168_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @169_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X1[0], 4);  // @170_4fd2a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; })));  // @171_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 188), sizeof v); (u32)v; });  // @172_4fd2a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @173_4fd2a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @174_4fd2a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @175_4fd2a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @176_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @177_4fd2a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @178_4fd2a0
  ecx = edx = 0;  // @179_4fd2a0
  ecx = eax;  // @180_4fd2a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @181_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 184), sizeof v); (u32)v; });  // @182_4fd2a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @183_4fd2a0
  ecx = edx = 0;  // @184_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @185_4fd2a0
  X0[1] = 0;  // @186_4fd2a0
  X0[2] = 0;  // @187_4fd2a0
  X0[3] = 0;  // @188_4fd2a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @189_4fd2a0
  if (FL[2] == 0) goto L4fd46f;  // @190_4fd2a0
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @191_4fd2a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @192_4fd2a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @193_4fd2a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @194_4fd2a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @195_4fd2a0
  L4fd46f:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @197_4fd2a0
  X1[1] = 0;  // @198_4fd2a0
  X1[2] = 0;  // @199_4fd2a0
  X1[3] = 0;  // @200_4fd2a0
  edx = (u32)(EBP - 16);  // @201_4fd2a0
  { float a_ = U2F(X1[0]), b_ = U2F(X0[0]); X1[0] = (a_ > b_) ? X1[0] : F2U(b_); }  // @202_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @203_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @204_4fd2a0
  X0[1] = 0;  // @205_4fd2a0
  X0[2] = 0;  // @206_4fd2a0
  X0[3] = 0;  // @207_4fd2a0
  ecx = esi;  // @208_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @209_4fd2a0
  { float a_ = U2F(X0[0]), b_ = U2F(X1[0]); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @210_4fd2a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @211_4fd2a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @212_4fd2a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @213_4fd2a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @214_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @215_4fd2a0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @216_4fd2a0
  ecx = edx = 0;  // @217_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @218_4fd2a0
  X0[1] = 0;  // @219_4fd2a0
  X0[2] = 0;  // @220_4fd2a0
  X0[3] = 0;  // @221_4fd2a0
  edx = (u32)(EBP - 16);  // @222_4fd2a0
  ecx = esi;  // @223_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @224_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @225_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @226_4fd2a0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @227_4fd2a0
  ecx = edx = 0;  // @228_4fd2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @229_4fd2a0
  edx = (u32)(EBP - 16);  // @230_4fd2a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @231_4fd2a0
  X0[1] = 0;  // @232_4fd2a0
  X0[2] = 0;  // @233_4fd2a0
  X0[3] = 0;  // @234_4fd2a0
  ecx = esi;  // @235_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @236_4fd2a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @237_4fd2a0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @238_4fd2a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; })));  // @239_4fd2a0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @240_4fd2a0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @241_4fd2a0
  ecx = edx = 0;  // @242_4fd2a0
  ext_633654(G(u32, 0x6f5630));  // @243_4fd2a0
  return eax;  // @244_4fd2a0
}
PCREG(4fd2a0, lifted_4fd2a0);

