// batch252008.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" long double STDCALL ext_477620_stdcall1_ld(u32) __asm__("ext_477620");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_4de1d0_fastcall2(u32, u32) __asm__("ext_4de1d0");
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 FASTCALL ext_4de520_fastcall4(u32, u32, u32, u32) __asm__("ext_4de520");
extern "C" u32 FASTCALL ext_4dec90_fastcall2(u32, u32) __asm__("ext_4dec90");
extern "C" u32 FASTCALL ext_4df1e0_fastcall2(u32, u32) __asm__("ext_4df1e0");
extern "C" u32 FASTCALL ext_4dfd10_fastcall2(u32, u32) __asm__("ext_4dfd10");
extern "C" u32 FASTCALL ext_4e1f00_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_4e1f00");
extern "C" u32 STDCALL ext_647430_stdcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_647430");
extern "C" u32 STDCALL ext_6474f0_stdcall4(u32, u32, u32, u32) __asm__("ext_6474f0");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 FASTCALL ext_4e0130_fastcall4(u32, u32, u32, u32) __asm__("ext_4e0130");
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

extern "C" u32 THISCALL lifted_647870(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x1450] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x1350);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x1350 + 8, &a0, 4);
  __builtin_memcpy(F + 0x1350 + 12, &a1, 4);
  __builtin_memcpy(F + 0x1350 + 16, &a2, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_647870
  X1[0] = 0;  // @1_647870
  X1[1] = 0;  // @2_647870
  X1[2] = 0;  // @3_647870
  X1[3] = 0;  // @4_647870
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_647870
  edi = ecx;  // @6_647870
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4836), &v, sizeof v); }  // @7_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @8_647870
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4820), &v, sizeof v); }  // @9_647870
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4832), &v, sizeof v); }  // @10_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 593) + 0), 4); v; });  // @11_647870
  X0[1] = 0;  // @12_647870
  X0[2] = 0;  // @13_647870
  X0[3] = 0;  // @14_647870
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @15_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @16_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @17_647870
  if (__builtin_parity(FL[2] & 0xff)) goto L647907;  // @18_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1180), sizeof v); (u32)v; });  // @20_647870
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @21_647870
  ecx = edx = 0;  // @22_647870
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @23_647870
  if (FL[2] == 0) goto L6478fe;  // @24_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_647870
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4820), sizeof v); (u32)v; });  // @26_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @27_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @28_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 184), sizeof v); (u32)v; });  // @30_647870
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[0]);  // @31_647870
  ecx = edx = 0;  // @32_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @33_647870
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @34_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @35_647870
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @36_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @37_647870
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @38_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; });  // @39_647870
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @40_647870
  L6478fe:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4820), sizeof v); (u32)v; });  // @42_647870
  X1[0] = 0;  // @43_647870
  X1[1] = 0;  // @44_647870
  X1[2] = 0;  // @45_647870
  X1[3] = 0;  // @46_647870
  L647907:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 557) + 0), 4); v; });  // @48_647870
  X0[1] = 0;  // @49_647870
  X0[2] = 0;  // @50_647870
  X0[3] = 0;  // @51_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 593), sizeof v); (u32)v; });  // @52_647870
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @53_647870
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 589), &v, sizeof v); }  // @54_647870
  __builtin_memcpy((void *)((u32)(edi + 573) + 0), &X0[0], 4);  // @55_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @56_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @57_647870
  if (__builtin_parity(FL[2] & 0xff)) goto L647f35;  // @58_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_647870
  PV[1] = (u32)(edx);  // @60_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @61_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @62_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 200), sizeof v); (u32)v; });  // @64_647870
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[1]);  // @65_647870
  ecx = edx = 0;  // @66_647870
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @67_647870
  ecx = eax;  // @68_647870
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4844), &v, sizeof v); }  // @69_647870
  if (FL[0] == FL[1]) goto L647adf;  // @70_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 593) + 0), 4); v; });  // @71_647870
  X0[1] = 0;  // @72_647870
  X0[2] = 0;  // @73_647870
  X0[3] = 0;  // @74_647870
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @75_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @76_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @77_647870
  if (!__builtin_parity(FL[2] & 0xff)) goto L647adf;  // @78_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 561) + 0), 4); v; });  // @79_647870
  X0[1] = 0;  // @80_647870
  X0[2] = 0;  // @81_647870
  X0[3] = 0;  // @82_647870
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @83_647870
  ecx = (u32)(EBP - 4856);  // @84_647870
  __builtin_memcpy((void *)((u32)(EBP - 4856) + 0), &X0[0], 4);  // @85_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 569) + 0), 4); v; });  // @86_647870
  X0[1] = 0;  // @87_647870
  X0[2] = 0;  // @88_647870
  X0[3] = 0;  // @89_647870
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4840), &v, sizeof v); }  // @90_647870
  __builtin_memcpy((void *)((u32)(EBP - 4848) + 0), &X0[0], 4);  // @91_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4852), &v, sizeof v); }  // @92_647870
  eax = ext_44c840_thiscall1(ecx);  // @93_647870
  ecx = 0;  // @94_647870
  edx = esi;  // @95_647870
  ecx = (u32)(EBP - 4856);  // @96_647870
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @97_647870
  eax = ext_441a60_fastcall2(ecx, edx);  // @98_647870
  ecx = edx = 0;  // @99_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4832), sizeof v); (u32)v; });  // @100_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4848) + 0), 4); v; });  // @101_647870
  X0[1] = 0;  // @102_647870
  X0[2] = 0;  // @103_647870
  X0[3] = 0;  // @104_647870
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @105_647870
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @106_647870
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @107_647870
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @108_647870
  PV[2] = (u32)(ecx);  // @109_647870
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @110_647870
  PV[3] = X0[0];  // @111_647870
  if (FL[2] == 0) goto L6479f6;  // @112_647870
  FS[0] = ext_477620_stdcall1_ld(PV[3]);  // @113_647870
  ecx = edx = 0;  // @114_647870
  FS[0] = (FS[0] * LDF((u32)(6795036)));  // @115_647870
  goto L647a01;  // @116_647870
  L6479f6:;
  FS[0] = ext_477620_stdcall1_ld(PV[3]);  // @118_647870
  ecx = edx = 0;  // @119_647870
  FS[0] = (FS[0] * LDF((u32)(6870072)));  // @120_647870
  L647a01:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4856) + 0), 4); v; });  // @122_647870
  X0[1] = 0;  // @123_647870
  X0[2] = 0;  // @124_647870
  X0[3] = 0;  // @125_647870
  X1[0] = 0;  // @126_647870
  X1[1] = 0;  // @127_647870
  X1[2] = 0;  // @128_647870
  X1[3] = 0;  // @129_647870
  STF((u32)(EBP - 4824), FS[0]);  // @130_647870
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @131_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4824) + 0), 4); v; });  // @132_647870
  X0[1] = 0;  // @133_647870
  X0[2] = 0;  // @134_647870
  X0[3] = 0;  // @135_647870
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L647a26;  // @136_647870
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @137_647870
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @138_647870
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @139_647870
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @140_647870
  L647a26:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4852) + 0), 4); v; });  // @142_647870
  X2[1] = 0;  // @143_647870
  X2[2] = 0;  // @144_647870
  X2[3] = 0;  // @145_647870
  FA = U2F(X2[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @146_647870
  __builtin_memcpy((void *)((u32)(EBP - 4828) + 0), &X0[0], 4);  // @147_647870
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L647a44;  // @148_647870
  X0[0] = X1[0];  // @149_647870
  X0[1] = X1[1];  // @150_647870
  X0[2] = X1[2];  // @151_647870
  X0[3] = X1[3];  // @152_647870
  goto L647a6a;  // @153_647870
  L647a44:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @155_647870
  X0[1] = 0;  // @156_647870
  X0[2] = 0;  // @157_647870
  X0[3] = 0;  // @158_647870
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @159_647870
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L647a5b;  // @160_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @161_647870
  X0[1] = 0;  // @162_647870
  X0[2] = 0;  // @163_647870
  X0[3] = 0;  // @164_647870
  goto L647a6a;  // @165_647870
  L647a5b:;
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @167_647870
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @168_647870
  ecx = edx = 0;  // @169_647870
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @170_647870
  X1[0] = 0;  // @171_647870
  X1[1] = 0;  // @172_647870
  X1[2] = 0;  // @173_647870
  X1[3] = 0;  // @174_647870
  L647a6a:;
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829936) + 0), 4); v; })));  // @176_647870
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4828) + 0), 4); v; });  // @177_647870
  X2[1] = 0;  // @178_647870
  X2[2] = 0;  // @179_647870
  X2[3] = 0;  // @180_647870
  X2[0] = X2[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @181_647870
  X2[1] = X2[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @182_647870
  X2[2] = X2[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @183_647870
  X2[3] = X2[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @184_647870
  PV[4] = (u32)(ecx);  // @185_647870
  ecx = (u32)(EBP - 64);  // @186_647870
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X2[0], 4);  // @187_647870
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @188_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @189_647870
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @190_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 557) + 0), 4); v; });  // @191_647870
  X0[1] = 0;  // @192_647870
  X0[2] = 0;  // @193_647870
  X0[3] = 0;  // @194_647870
  PV[5] = X0[0];  // @195_647870
  eax = ext_4e0d00_thiscall2(ecx, PV[5]);  // @196_647870
    // @197_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4840), sizeof v); (u32)v; });  // @198_647870
  ecx = (u32)(EBP - 52);  // @199_647870
  eax = (u32)(eax + eax*2);  // @200_647870
  eax = (eax << (u32)(4));  // @201_647870
  FL[3] = eax;  // @202_647870
  esi = (esi + eax);  // @203_647870
  FL[3] = esi;  // @204_647870
  edx = esi;  // @205_647870
  eax = ext_4df1e0_fastcall2(ecx, edx);  // @206_647870
    // @207_647870
  edx = (u32)(EBP - 64);  // @208_647870
  ecx = (u32)(EBP - 52);  // @209_647870
  eax = ext_4dec90_fastcall2(ecx, edx);  // @210_647870
  ecx = edx = 0;  // @211_647870
  edx = (u32)(EBP - 52);  // @212_647870
  ecx = esi;  // @213_647870
  eax = ext_4de1d0_fastcall2(ecx, edx);  // @214_647870
  ecx = edx = 0;  // @215_647870
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4836), sizeof v); (u32)v; });  // @216_647870
  L647adf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4832), sizeof v); (u32)v; });  // @218_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @219_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 716), sizeof v); (u32)v; });  // @220_647870
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @221_647870
  ecx = edx = 0;  // @222_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @223_647870
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4820), sizeof v); (u32)v; });  // @224_647870
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4828), &v, sizeof v); }  // @225_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @226_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @227_647870
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @228_647870
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 192), sizeof v); (u32)v; });  // @229_647870
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[6]);  // @230_647870
  ecx = edx = 0;  // @231_647870
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4828), sizeof v); (u32)v; });  // @232_647870
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4824), &v, sizeof v); }  // @233_647870
  ecx = edi;  // @234_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4844), sizeof v); (u32)v; });  // @235_647870
  PV[8] = (u32)(esi);  // @236_647870
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23), sizeof v); (u32)v; });  // @237_647870
  esi = eax;  // @238_647870
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4820), &v, sizeof v); }  // @239_647870
  PV[9] = (u32)(esi);  // @240_647870
  eax = (u32)(EBP - 4816);  // @241_647870
  PV[10] = (u32)(eax);  // @242_647870
  eax = ext_6474f0_stdcall4(PV[10], PV[9], PV[8], PV[7]);  // @243_647870
  ecx = edx = 0;  // @244_647870
  eax = (u32)(esi + esi*2);  // @245_647870
  eax = (eax << (u32)(4));  // @246_647870
  FL[3] = eax;  // @247_647870
  edx = (u32)(EBP - 4816);  // @248_647870
  edx = (edx + eax);  // @249_647870
  FL[3] = edx;  // @250_647870
  ecx = (u32)(EBP - 52);  // @251_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + eax - 4780) + 0), 4); v; });  // @252_647870
  X0[1] = 0;  // @253_647870
  X0[2] = 0;  // @254_647870
  X0[3] = 0;  // @255_647870
  __builtin_memcpy((void *)((u32)(EBP - 4868) + 0), &X0[0], 4);  // @256_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + eax - 4776) + 0), 4); v; });  // @257_647870
  X0[1] = 0;  // @258_647870
  X0[2] = 0;  // @259_647870
  X0[3] = 0;  // @260_647870
  __builtin_memcpy((void *)((u32)(EBP - 4864) + 0), &X0[0], 4);  // @261_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + eax - 4772) + 0), 4); v; });  // @262_647870
  X0[1] = 0;  // @263_647870
  X0[2] = 0;  // @264_647870
  X0[3] = 0;  // @265_647870
  __builtin_memcpy((void *)((u32)(EBP - 4860) + 0), &X0[0], 4);  // @266_647870
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @267_647870
    // @268_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4824), sizeof v); (u32)v; });  // @269_647870
  eax = (u32)(esi + esi*8);  // @270_647870
  edx = (u32)(ecx + eax*4);  // @271_647870
  ecx = (u32)(EBP - 52);  // @272_647870
  eax = ext_4de480_fastcall2(ecx, edx);  // @273_647870
  ecx = edx = 0;  // @274_647870
  edx = (u32)(EBP - 52);  // @275_647870
  ecx = (u32)(EBP - 172);  // @276_647870
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @277_647870
    // @278_647870
  eax = (u32)(EBP - 4868);  // @279_647870
  PV[11] = (u32)(eax);  // @280_647870
  edx = (u32)(edi + 561);  // @281_647870
  ecx = (u32)(EBP - 16);  // @282_647870
  eax = ext_43e920_fastcall3(ecx, edx, PV[11]);  // @283_647870
  ecx = edx = 0;  // @284_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @285_647870
  X0[1] = 0;  // @286_647870
  X0[2] = 0;  // @287_647870
  X0[3] = 0;  // @288_647870
  eax = (u32)(EBP - 16);  // @289_647870
  X1[0] = 0;  // @290_647870
  X1[1] = 0;  // @291_647870
  X1[2] = 0;  // @292_647870
  X1[3] = 0;  // @293_647870
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4840), &v, sizeof v); }  // @294_647870
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @295_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @296_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @297_647870
  if (!__builtin_parity(FL[2] & 0xff)) goto L647bf8;  // @298_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @299_647870
  X0[1] = 0;  // @300_647870
  X0[2] = 0;  // @301_647870
  X0[3] = 0;  // @302_647870
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @303_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @304_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @305_647870
  if (!__builtin_parity(FL[2] & 0xff)) goto L647bf8;  // @306_647870
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @307_647870
  X2[1] = 0;  // @308_647870
  X2[2] = 0;  // @309_647870
  X2[3] = 0;  // @310_647870
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @311_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @312_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @313_647870
  if (__builtin_parity(FL[2] & 0xff)) goto L647c45;  // @314_647870
  L647bf8:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 4832), &v, sizeof v); }  // @316_647870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4840), sizeof v); (u32)v; });  // @317_647870
  FS[0] = LDF((u32)(ecx));  // @318_647870
  FS[0] = (FS[0] * FS[0]);  // @319_647870
  FS[1] = LDF((u32)(ecx + 4));  // @320_647870
  FS[1] = (FS[1] * FS[1]);  // @321_647870
  FS[0] = (FS[0] + FS[1]);  // @322_647870
  FS[1] = LDF((u32)(ecx + 8));  // @323_647870
  FS[1] = (FS[1] * FS[1]);  // @324_647870
  FS[0] = (FS[0] + FS[1]);  // @325_647870
  FSQRT(FS[0]);  // @326_647870
  FS[1] = LDF((u32)(EBP - 4832));  // @327_647870
  FS[1] = (FS[1] / FS[0]);  // @328_647870
  FS[2] = LDF((u32)(ecx));  // @329_647870
  FS[2] = (FS[2] * FS[1]);  // @330_647870
  STF((u32)(ecx), FS[2]);  // @331_647870
  FS[2] = LDF((u32)(ecx + 4));  // @332_647870
  FS[2] = (FS[2] * FS[1]);  // @333_647870
  STF((u32)(ecx + 4), FS[2]);  // @334_647870
  FS[2] = LDF((u32)(ecx + 8));  // @335_647870
  FS[1] = (FS[1] * FS[2]);  // @336_647870
  STF((u32)(ecx + 8), FS[1]);  // @337_647870
  STF((u32)(EBP - 4832), FS[0]);  // @338_647870
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @339_647870
  X2[1] = 0;  // @340_647870
  X2[2] = 0;  // @341_647870
  X2[3] = 0;  // @342_647870
  L647c45:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 577) + 0), 4); v; });  // @344_647870
  X0[1] = 0;  // @345_647870
  X0[2] = 0;  // @346_647870
  X0[3] = 0;  // @347_647870
  esi = (u32)(edi + 577);  // @348_647870
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @349_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @350_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @351_647870
  if (!__builtin_parity(FL[2] & 0xff)) goto L647c78;  // @352_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @353_647870
  X0[1] = 0;  // @354_647870
  X0[2] = 0;  // @355_647870
  X0[3] = 0;  // @356_647870
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @357_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @358_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @359_647870
  if (!__builtin_parity(FL[2] & 0xff)) goto L647c78;  // @360_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @361_647870
  X0[1] = 0;  // @362_647870
  X0[2] = 0;  // @363_647870
  X0[3] = 0;  // @364_647870
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @365_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @366_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @367_647870
  if (__builtin_parity(FL[2] & 0xff)) goto L647ca5;  // @368_647870
  L647c78:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @370_647870
  edx = esi;  // @371_647870
  PV[12] = (u32)(ecx);  // @372_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @373_647870
  X0[1] = 0;  // @374_647870
  X0[2] = 0;  // @375_647870
  X0[3] = 0;  // @376_647870
  eax = (u32)(EBP - 16);  // @377_647870
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7088828) + 0), 4); v; })));  // @378_647870
  ecx = eax;  // @379_647870
  PV[13] = X0[0];  // @380_647870
  PV[14] = (u32)(eax);  // @381_647870
  eax = ext_4e0130_fastcall4(ecx, edx, PV[14], PV[13]);  // @382_647870
  ecx = edx = 0;  // @383_647870
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @384_647870
  X2[1] = 0;  // @385_647870
  X2[2] = 0;  // @386_647870
  X2[3] = 0;  // @387_647870
  X1[0] = 0;  // @388_647870
  X1[1] = 0;  // @389_647870
  X1[2] = 0;  // @390_647870
  X1[3] = 0;  // @391_647870
  L647ca5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @393_647870
  X0[1] = 0;  // @394_647870
  X0[2] = 0;  // @395_647870
  X0[3] = 0;  // @396_647870
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @397_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @398_647870
  X0[1] = 0;  // @399_647870
  X0[2] = 0;  // @400_647870
  X0[3] = 0;  // @401_647870
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @402_647870
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X2[0], 4);  // @403_647870
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @404_647870
  if (FL[0] == FL[1]) goto L647e07;  // @405_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4844), sizeof v); (u32)v; });  // @406_647870
  edx = (u32)(EBP - 4816);  // @407_647870
  ecx = (u32)(EBP - 136);  // @408_647870
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 22), sizeof v); (u32)v; });  // @409_647870
  eax = (u32)(esi + esi*2);  // @410_647870
  eax = (eax << (u32)(4));  // @411_647870
  FL[3] = eax;  // @412_647870
  edx = (edx + eax);  // @413_647870
  FL[3] = edx;  // @414_647870
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @415_647870
    // @416_647870
  eax = (u32)(esi + esi*8);  // @417_647870
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4824), sizeof v); (u32)v; });  // @418_647870
  ecx = (u32)(EBP - 136);  // @419_647870
  edx = (u32)(esi + eax*4);  // @420_647870
  eax = ext_4de480_fastcall2(ecx, edx);  // @421_647870
  ecx = edx = 0;  // @422_647870
  edx = (u32)(EBP - 136);  // @423_647870
  ecx = (u32)(EBP - 52);  // @424_647870
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @425_647870
    // @426_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799772) + 0), 4); v; });  // @427_647870
  X0[1] = 0;  // @428_647870
  X0[2] = 0;  // @429_647870
  X0[3] = 0;  // @430_647870
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @431_647870
  X2[1] = 0;  // @432_647870
  X2[2] = 0;  // @433_647870
  X2[3] = 0;  // @434_647870
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @435_647870
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L647d48;  // @436_647870
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; })));  // @437_647870
  X1[0] = 0;  // @438_647870
  X1[1] = 0;  // @439_647870
  X1[2] = 0;  // @440_647870
  X1[3] = 0;  // @441_647870
  { float a_ = U2F(X1[0]), b_ = U2F(X2[0]); X1[0] = (a_ > b_) ? X1[0] : F2U(b_); }  // @442_647870
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; })));  // @443_647870
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 557) + 0), 4); v; })));  // @444_647870
  __builtin_memcpy((void *)((u32)(edi + 557) + 0), &X1[0], 4);  // @445_647870
  L647d48:;
  eax = (u32)(EBP - 40);  // @447_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @448_647870
  PV[15] = (u32)(eax);  // @449_647870
  edx = (u32)(EBP - 28);  // @450_647870
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @451_647870
  ecx = (u32)(EBP - 52);  // @452_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @453_647870
  eax = ext_446ee0_fastcall3(ecx, edx, PV[15]);  // @454_647870
  ecx = edx = 0;  // @455_647870
  edx = (u32)(EBP - 52);  // @456_647870
  ecx = (u32)(EBP - 28);  // @457_647870
  eax = ext_44e630_fastcall2(ecx, edx);  // @458_647870
  ecx = edx = 0;  // @459_647870
  eax = (u32)(EBP - 40);  // @460_647870
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @461_647870
  PV[16] = (u32)(eax);  // @462_647870
  edx = (u32)(EBP - 28);  // @463_647870
  ecx = (u32)(EBP - 52);  // @464_647870
  eax = ext_446ee0_fastcall3(ecx, edx, PV[16]);  // @465_647870
  ecx = edx = 0;  // @466_647870
  edx = (u32)(EBP - 52);  // @467_647870
  ecx = (u32)(EBP - 16);  // @468_647870
  eax = ext_441a60_fastcall2(ecx, edx);  // @469_647870
  ecx = edx = 0;  // @470_647870
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @471_647870
  X2[1] = 0;  // @472_647870
  X2[2] = 0;  // @473_647870
  X2[3] = 0;  // @474_647870
  X0[0] = 0;  // @475_647870
  X0[1] = 0;  // @476_647870
  X0[2] = 0;  // @477_647870
  X0[3] = 0;  // @478_647870
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @479_647870
  X1[1] = 0;  // @480_647870
  X1[2] = 0;  // @481_647870
  X1[3] = 0;  // @482_647870
  X2[0] = X2[0] ^ X1[0];  // @483_647870
  X2[1] = X2[1] ^ X1[1];  // @484_647870
  X2[2] = X2[2] ^ X1[2];  // @485_647870
  X2[3] = X2[3] ^ X1[3];  // @486_647870
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @487_647870
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @488_647870
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L647db8;  // @489_647870
  X2[0] = X2[0] ^ X1[0];  // @490_647870
  X2[1] = X2[1] ^ X1[1];  // @491_647870
  X2[2] = X2[2] ^ X1[2];  // @492_647870
  X2[3] = X2[3] ^ X1[3];  // @493_647870
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @494_647870
  L647db8:;
  ecx = (u32)(EBP - 16);  // @496_647870
  edx = 0;  // @497_647870
  FL[3] = edx;  // @498_647870
  eax = ext_4e1f00_fastcall6(ecx, edx, (u32)(1067213227), (u32)(1065749138), (u32)(1067213227), (u32)(1060288707));  // @499_647870
  ecx = edx = 0;  // @500_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @501_647870
  X0[1] = 0;  // @502_647870
  X0[2] = 0;  // @503_647870
  X0[3] = 0;  // @504_647870
  edx = (u32)(EBP - 52);  // @505_647870
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @506_647870
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @507_647870
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @508_647870
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @509_647870
  ecx = (u32)(EBP - 16);  // @510_647870
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @511_647870
  eax = ext_4419f0_fastcall2(ecx, edx);  // @512_647870
  ecx = edx = 0;  // @513_647870
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @514_647870
  X1[1] = 0;  // @515_647870
  X1[2] = 0;  // @516_647870
  X1[3] = 0;  // @517_647870
  goto L647e67;  // @518_647870
  L647e07:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @520_647870
  X0[1] = 0;  // @521_647870
  X0[2] = 0;  // @522_647870
  X0[3] = 0;  // @523_647870
  X2[0] = X2[0] ^ X0[0];  // @524_647870
  X2[1] = X2[1] ^ X0[1];  // @525_647870
  X2[2] = X2[2] ^ X0[2];  // @526_647870
  X2[3] = X2[3] ^ X0[3];  // @527_647870
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @528_647870
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @529_647870
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L647e24;  // @530_647870
  X2[0] = X2[0] ^ X0[0];  // @531_647870
  X2[1] = X2[1] ^ X0[1];  // @532_647870
  X2[2] = X2[2] ^ X0[2];  // @533_647870
  X2[3] = X2[3] ^ X0[3];  // @534_647870
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @535_647870
  L647e24:;
  ecx = (u32)(EBP - 16);  // @537_647870
  edx = 0;  // @538_647870
  FL[3] = edx;  // @539_647870
  eax = ext_4e1f00_fastcall6(ecx, edx, (u32)(1067213227), (u32)(1065749138), (u32)(1067213227), (u32)(1060288707));  // @540_647870
  ecx = edx = 0;  // @541_647870
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @542_647870
  X1[1] = 0;  // @543_647870
  X1[2] = 0;  // @544_647870
  X1[3] = 0;  // @545_647870
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @546_647870
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @547_647870
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @548_647870
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @549_647870
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4824), sizeof v); (u32)v; });  // @550_647870
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X1[0], 4);  // @551_647870
  L647e67:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @553_647870
  X0[1] = 0;  // @554_647870
  X0[2] = 0;  // @555_647870
  X0[3] = 0;  // @556_647870
  eax = (u32)(EBP - 76);  // @557_647870
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @558_647870
  edx = (u32)(EBP - 100);  // @559_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @560_647870
  X0[1] = 0;  // @561_647870
  X0[2] = 0;  // @562_647870
  X0[3] = 0;  // @563_647870
  ecx = (u32)(EBP - 88);  // @564_647870
  PV[17] = (u32)(eax);  // @565_647870
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @566_647870
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X1[0], 4);  // @567_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @568_647870
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @569_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @570_647870
  eax = ext_446ee0_fastcall3(ecx, edx, PV[17]);  // @571_647870
  ecx = edx = 0;  // @572_647870
  ecx = (u32)(EBP - 88);  // @573_647870
  eax = ext_44c840_thiscall1(ecx);  // @574_647870
  ecx = 0;  // @575_647870
  eax = (u32)(EBP - 88);  // @576_647870
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @577_647870
  PV[18] = (u32)(eax);  // @578_647870
  edx = (u32)(EBP - 76);  // @579_647870
  ecx = (u32)(EBP - 100);  // @580_647870
  eax = ext_446ee0_fastcall3(ecx, edx, PV[18]);  // @581_647870
  ecx = edx = 0;  // @582_647870
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 557) + 0), 4); v; });  // @583_647870
  X0[1] = 0;  // @584_647870
  X0[2] = 0;  // @585_647870
  X0[3] = 0;  // @586_647870
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @587_647870
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @588_647870
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @589_647870
  if (!__builtin_parity(FL[2] & 0xff)) goto L647ede;  // @590_647870
  eax = (u32)(EBP - 4868);  // @591_647870
  PV[19] = (u32)(eax);  // @592_647870
  eax = (u32)(EBP - 100);  // @593_647870
  goto L647f06;  // @594_647870
  L647ede:;
  PV[20] = (u32)(ecx);  // @596_647870
  eax = (u32)(EBP - 100);  // @597_647870
  PV[21] = X0[0];  // @598_647870
  PV[22] = (u32)(eax);  // @599_647870
  edx = (u32)(EBP - 172);  // @600_647870
  ecx = (u32)(EBP - 208);  // @601_647870
  eax = ext_4de520_fastcall4(ecx, edx, PV[22], PV[21]);  // @602_647870
  ecx = edx = 0;  // @603_647870
  eax = (u32)(EBP - 4868);  // @604_647870
  PV[23] = (u32)(eax);  // @605_647870
  eax = (u32)(EBP - 208);  // @606_647870
  L647f06:;
  PV[24] = (u32)(eax);  // @608_647870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4820), sizeof v); (u32)v; });  // @609_647870
  ecx = edi;  // @610_647870
  PV[25] = (u32)(eax);  // @611_647870
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4828), sizeof v); (u32)v; });  // @612_647870
  eax = (u32)(EBP - 4816);  // @613_647870
  PV[27] = (u32)(esi);  // @614_647870
  PV[28] = (u32)(eax);  // @615_647870
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4836), sizeof v); (u32)v; });  // @616_647870
  eax = ext_647430_stdcall7(PV[29], PV[28], PV[27], PV[26], PV[25], PV[24], PV[23]);  // @617_647870
  ecx = edx = 0;  // @618_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 557), &v, sizeof v); }  // @619_647870
  goto L647f53;  // @620_647870
  L647f35:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 577), &v, sizeof v); }  // @622_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 581), &v, sizeof v); }  // @623_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 585), &v, sizeof v); }  // @624_647870
  L647f53:;
  ext_633654(G(u32, 0x6f5630));  // @626_647870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 593), &v, sizeof v); }  // @627_647870
  return eax;  // @628_647870
}
PCREG(647870, lifted_647870);

