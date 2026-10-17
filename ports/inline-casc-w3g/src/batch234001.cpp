// batch234001.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634de2_dbl(double) __asm__("ext_634de2");
extern "C" long double FASTCALL ext_4e0030_fastcall2_ld(u32, u32) __asm__("ext_4e0030");
extern "C" long double FASTCALL ext_4e0870_fastcall2_ld(u32, u32) __asm__("ext_4e0870");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_4ddcb0_fastcall3(u32, u32, u32) __asm__("ext_4ddcb0");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_52b390_fastcall3(u32, u32, u32) __asm__("ext_52b390");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_52b0c0_thiscall1(u32) __asm__("ext_52b0c0");
extern "C" u32 THISCALL ext_52b170_thiscall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_52b170");
extern "C" u32 THISCALL ext_52b4e0_thiscall2(u32, u32) __asm__("ext_52b4e0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
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

extern "C" u32 THISCALL lifted_51ddc0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; });  // @1_51ddc0
  X0[1] = 0;  // @2_51ddc0
  X0[2] = 0;  // @3_51ddc0
  X0[3] = 0;  // @4_51ddc0
  edi = ecx;  // @5_51ddc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; }));  // @6_51ddc0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L51e322;  // @7_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 96) + 0), 4); v; });  // @8_51ddc0
  X0[1] = 0;  // @9_51ddc0
  X0[2] = 0;  // @10_51ddc0
  X0[3] = 0;  // @11_51ddc0
  ecx = (u32)(edi + 574);  // @12_51ddc0
  esi = (u32)(edi + 96);  // @13_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 184) + 0), &X0[0], 4);  // @14_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @15_51ddc0
  X0[1] = 0;  // @16_51ddc0
  X0[2] = 0;  // @17_51ddc0
  X0[3] = 0;  // @18_51ddc0
  edx = ecx;  // @19_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 180) + 0), &X0[0], 4);  // @20_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @21_51ddc0
  X0[1] = 0;  // @22_51ddc0
  X0[2] = 0;  // @23_51ddc0
  X0[3] = 0;  // @24_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 176) + 0), &X0[0], 4);  // @25_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @26_51ddc0
  X0[1] = 0;  // @27_51ddc0
  X0[2] = 0;  // @28_51ddc0
  X0[3] = 0;  // @29_51ddc0
  PV[0] = (u32)(ecx);  // @30_51ddc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @31_51ddc0
  ecx = (u32)(EBP - 184);  // @32_51ddc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @33_51ddc0
  PV[1] = X0[0];  // @34_51ddc0
  eax = ext_451890_fastcall3(ecx, edx, PV[1]);  // @35_51ddc0
  ecx = 0;  // @36_51ddc0
  eax = (u32)(edi + 586);  // @37_51ddc0
  ecx = (u32)(EBP - 184);  // @38_51ddc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @39_51ddc0
  PV[2] = (u32)(ecx);  // @40_51ddc0
  edx = eax;  // @41_51ddc0
  ecx = (u32)(EBP - 40);  // @42_51ddc0
  eax = ext_43e920_fastcall3(ecx, edx, PV[2]);  // @43_51ddc0
  ecx = edx = 0;  // @44_51ddc0
  PV[3] = (u32)(ecx);  // @45_51ddc0
  ecx = (u32)(EBP - 40);  // @46_51ddc0
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1008981770));  // @47_51ddc0
    // @48_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_51ddc0
  edx = (u32)(EBP - 40);  // @50_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6941532) + 0), 4); v; });  // @51_51ddc0
  X0[1] = 0;  // @52_51ddc0
  X0[2] = 0;  // @53_51ddc0
  X0[3] = 0;  // @54_51ddc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @55_51ddc0
  { u32 v = (u32)((u32)(1195593728)); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @56_51ddc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @57_51ddc0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @58_51ddc0
  X1[1] = 0;  // @59_51ddc0
  X1[2] = 0;  // @60_51ddc0
  X1[3] = 0;  // @61_51ddc0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @62_51ddc0
  PV[4] = (u32)(ecx);  // @63_51ddc0
  ecx = (u32)(EBP - 172);  // @64_51ddc0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @65_51ddc0
  PV[5] = X0[0];  // @66_51ddc0
  eax = ext_451890_fastcall3(ecx, edx, PV[5]);  // @67_51ddc0
  ecx = 0;  // @68_51ddc0
  edx = (u32)(EBP - 172);  // @69_51ddc0
  ecx = (u32)(EBP - 148);  // @70_51ddc0
  eax = ext_44e630_fastcall2(ecx, edx);  // @71_51ddc0
  ecx = edx = 0;  // @72_51ddc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @73_51ddc0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @74_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @75_51ddc0
  X0[1] = 0;  // @76_51ddc0
  X0[2] = 0;  // @77_51ddc0
  X0[3] = 0;  // @78_51ddc0
  if (FL[0] == FL[1]) goto L51df73;  // @79_51ddc0
  eax = (u32)(edi + 534);  // @80_51ddc0
  PV[6] = (u32)(eax);  // @81_51ddc0
  edx = (u32)(edi + 610);  // @82_51ddc0
  ecx = (u32)(EBP - 88);  // @83_51ddc0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[6]);  // @84_51ddc0
  ecx = edx = 0;  // @85_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1431) + 0), 4); v; });  // @86_51ddc0
  X0[1] = 0;  // @87_51ddc0
  X0[2] = 0;  // @88_51ddc0
  X0[3] = 0;  // @89_51ddc0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6945248) + 0), 4); v; })));  // @90_51ddc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @91_51ddc0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @92_51ddc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @93_51ddc0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @94_51ddc0
  { double r_ = ext_634de2_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @95_51ddc0
  ecx = edx = 0;  // @96_51ddc0
  edx = (u32)(EBP - 28);  // @97_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 136) + 0), &X0[0], 4);  // @98_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 136) + 4), &X0[1], 4);  // @99_51ddc0
  ecx = (u32)(edi + 610);  // @100_51ddc0
  FS[0] = ext_4e0030_fastcall2_ld(ecx, edx);  // @101_51ddc0
  ecx = edx = 0;  // @102_51ddc0
  FS[0] = (LDD((u32)(EBP - 136)) - FS[0]);  // @103_51ddc0
  PV[7] = (u32)(ecx);  // @104_51ddc0
  edx = (u32)(EBP - 88);  // @105_51ddc0
  ecx = (u32)(EBP - 124);  // @106_51ddc0
  STF((u32)(EBP - 128), FS[0]);  // @107_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 128) + 0), 4); v; });  // @108_51ddc0
  X0[1] = 0;  // @109_51ddc0
  X0[2] = 0;  // @110_51ddc0
  X0[3] = 0;  // @111_51ddc0
  PV[8] = X0[0];  // @112_51ddc0
  eax = ext_4ddcb0_fastcall3(ecx, edx, PV[8]);  // @113_51ddc0
  ecx = edx = 0;  // @114_51ddc0
  edx = (u32)(EBP - 124);  // @115_51ddc0
  ecx = (u32)(EBP - 148);  // @116_51ddc0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @117_51ddc0
  ecx = edx = 0;  // @118_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @119_51ddc0
  X0[1] = 0;  // @120_51ddc0
  X0[2] = 0;  // @121_51ddc0
  X0[3] = 0;  // @122_51ddc0
  esi = (u32)(edi + 96);  // @123_51ddc0
  L51df73:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; });  // @125_51ddc0
  X2[1] = 0;  // @126_51ddc0
  X2[2] = 0;  // @127_51ddc0
  X2[3] = 0;  // @128_51ddc0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 144) + 0), 4); v; });  // @129_51ddc0
  X1[1] = 0;  // @130_51ddc0
  X1[2] = 0;  // @131_51ddc0
  X1[3] = 0;  // @132_51ddc0
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @133_51ddc0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L51df8f;  // @134_51ddc0
  X2[0] = X0[0];  // @135_51ddc0
  X2[1] = X0[1];  // @136_51ddc0
  X2[2] = X0[2];  // @137_51ddc0
  X2[3] = X0[3];  // @138_51ddc0
  { float a_ = U2F(X2[0]), b_ = U2F(X1[0]); X2[0] = (a_ < b_) ? X2[0] : F2U(b_); }  // @139_51ddc0
  L51df8f:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 148) + 0), 4); v; });  // @141_51ddc0
  X4[1] = 0;  // @142_51ddc0
  X4[2] = 0;  // @143_51ddc0
  X4[3] = 0;  // @144_51ddc0
  eax = (u32)(EBP - 148);  // @145_51ddc0
  X0[0] = 0;  // @146_51ddc0
  X0[1] = 0;  // @147_51ddc0
  X0[2] = 0;  // @148_51ddc0
  X0[3] = 0;  // @149_51ddc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @150_51ddc0
  FA = U2F(X4[0]); FB = U2F(X0[0]);  // @151_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 144) + 0), &X2[0], 4);  // @152_51ddc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @153_51ddc0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @154_51ddc0
  if (!__builtin_parity(FL[2] & 0xff)) goto L51dfd1;  // @155_51ddc0
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @156_51ddc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @157_51ddc0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @158_51ddc0
  if (!__builtin_parity(FL[2] & 0xff)) goto L51dfd1;  // @159_51ddc0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @160_51ddc0
  X3[1] = 0;  // @161_51ddc0
  X3[2] = 0;  // @162_51ddc0
  X3[3] = 0;  // @163_51ddc0
  FA = U2F(X3[0]); FB = U2F(X0[0]);  // @164_51ddc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @165_51ddc0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @166_51ddc0
  if (__builtin_parity(FL[2] & 0xff)) goto L51e028;  // @167_51ddc0
  L51dfd1:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @169_51ddc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @170_51ddc0
  FS[0] = LDF((u32)(ecx));  // @171_51ddc0
  FS[0] = (FS[0] * FS[0]);  // @172_51ddc0
  FS[1] = LDF((u32)(ecx + 4));  // @173_51ddc0
  FS[1] = (FS[1] * FS[1]);  // @174_51ddc0
  FS[0] = (FS[0] + FS[1]);  // @175_51ddc0
  FS[1] = LDF((u32)(ecx + 8));  // @176_51ddc0
  FS[1] = (FS[1] * FS[1]);  // @177_51ddc0
  FS[0] = (FS[0] + FS[1]);  // @178_51ddc0
  FSQRT(FS[0]);  // @179_51ddc0
  FS[1] = LDF((u32)(EBP - 128));  // @180_51ddc0
  FS[1] = (FS[1] / FS[0]);  // @181_51ddc0
  FS[2] = LDF((u32)(ecx));  // @182_51ddc0
  FS[2] = (FS[2] * FS[1]);  // @183_51ddc0
  STF((u32)(ecx), FS[2]);  // @184_51ddc0
  FS[2] = LDF((u32)(ecx + 4));  // @185_51ddc0
  FS[2] = (FS[2] * FS[1]);  // @186_51ddc0
  STF((u32)(ecx + 4), FS[2]);  // @187_51ddc0
  FS[2] = LDF((u32)(ecx + 8));  // @188_51ddc0
  FS[1] = (FS[1] * FS[2]);  // @189_51ddc0
  STF((u32)(ecx + 8), FS[1]);  // @190_51ddc0
  STF((u32)(EBP - 128), FS[0]);  // @191_51ddc0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @192_51ddc0
  X3[1] = 0;  // @193_51ddc0
  X3[2] = 0;  // @194_51ddc0
  X3[3] = 0;  // @195_51ddc0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 144) + 0), 4); v; });  // @196_51ddc0
  X2[1] = 0;  // @197_51ddc0
  X2[2] = 0;  // @198_51ddc0
  X2[3] = 0;  // @199_51ddc0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 148) + 0), 4); v; });  // @200_51ddc0
  X4[1] = 0;  // @201_51ddc0
  X4[2] = 0;  // @202_51ddc0
  X4[3] = 0;  // @203_51ddc0
  L51e028:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @205_51ddc0
  ecx = (u32)(edi + 610);  // @206_51ddc0
  PV[9] = (u32)(ecx);  // @207_51ddc0
  ecx = edi;  // @208_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @209_51ddc0
  X0[1] = 0;  // @210_51ddc0
  X0[2] = 0;  // @211_51ddc0
  X0[3] = 0;  // @212_51ddc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @213_51ddc0
  X1[0] = X0[0];  // @214_51ddc0
  X1[1] = X0[1];  // @215_51ddc0
  X1[2] = X0[2];  // @216_51ddc0
  X1[3] = X0[3];  // @217_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 132) + 0), &X0[0], 4);  // @218_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1009) + 0), 4); v; });  // @219_51ddc0
  X0[1] = 0;  // @220_51ddc0
  X0[2] = 0;  // @221_51ddc0
  X0[3] = 0;  // @222_51ddc0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788420) + 0), 4); v; })));  // @223_51ddc0
  X4[0] = F2U(U2F(X4[0]) - U2F(X0[0]));  // @224_51ddc0
  X4[0] = F2U(U2F(X4[0]) * U2F(X1[0]));  // @225_51ddc0
  X4[0] = F2U(U2F(X4[0]) + U2F(X0[0]));  // @226_51ddc0
  __builtin_memcpy((void *)((u32)(edi + 1009) + 0), &X4[0], 4);  // @227_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1013) + 0), 4); v; });  // @228_51ddc0
  X0[1] = 0;  // @229_51ddc0
  X0[2] = 0;  // @230_51ddc0
  X0[3] = 0;  // @231_51ddc0
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @232_51ddc0
  X2[0] = F2U(U2F(X2[0]) * U2F(X1[0]));  // @233_51ddc0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @234_51ddc0
  __builtin_memcpy((void *)((u32)(edi + 1013) + 0), &X2[0], 4);  // @235_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1017) + 0), 4); v; });  // @236_51ddc0
  X0[1] = 0;  // @237_51ddc0
  X0[2] = 0;  // @238_51ddc0
  X0[3] = 0;  // @239_51ddc0
  X3[0] = F2U(U2F(X3[0]) - U2F(X0[0]));  // @240_51ddc0
  X3[0] = F2U(U2F(X3[0]) * U2F(X1[0]));  // @241_51ddc0
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @242_51ddc0
  X0[0] = X4[0];  // @243_51ddc0
  X0[1] = X4[1];  // @244_51ddc0
  X0[2] = X4[2];  // @245_51ddc0
  X0[3] = X4[3];  // @246_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @247_51ddc0
  X0[0] = X2[0];  // @248_51ddc0
  X0[1] = X2[1];  // @249_51ddc0
  X0[2] = X2[2];  // @250_51ddc0
  X0[3] = X2[3];  // @251_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @252_51ddc0
  __builtin_memcpy((void *)((u32)(edi + 1017) + 0), &X3[0], 4);  // @253_51ddc0
  X0[0] = X3[0];  // @254_51ddc0
  X0[1] = X3[1];  // @255_51ddc0
  X0[2] = X3[2];  // @256_51ddc0
  X0[3] = X3[3];  // @257_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @258_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @259_51ddc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[9]);  // @260_51ddc0
  ecx = edx = 0;  // @261_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @262_51ddc0
  ecx = (u32)(EBP - 16);  // @263_51ddc0
  PV[10] = (u32)(ecx);  // @264_51ddc0
  ecx = edi;  // @265_51ddc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[10]);  // @266_51ddc0
  ecx = edx = 0;  // @267_51ddc0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 610) + 0), 4); v; });  // @268_51ddc0
  X4[1] = 0;  // @269_51ddc0
  X4[2] = 0;  // @270_51ddc0
  X4[3] = 0;  // @271_51ddc0
  ecx = (u32)(edi + 610);  // @272_51ddc0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @273_51ddc0
  X3[1] = 0;  // @274_51ddc0
  X3[2] = 0;  // @275_51ddc0
  X3[3] = 0;  // @276_51ddc0
  { double a_ = (double)U2F(X3[0]), b_ = (double)U2F(X3[1]); SD(&X2[0], a_); SD(&X2[2], b_); }  // @277_51ddc0
  { double a_ = (double)U2F(X4[0]), b_ = (double)U2F(X4[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @278_51ddc0
  X2[0] = X2[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @279_51ddc0
  X2[1] = X2[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @280_51ddc0
  X2[2] = X2[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @281_51ddc0
  X2[3] = X2[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @282_51ddc0
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @283_51ddc0
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @284_51ddc0
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @285_51ddc0
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @286_51ddc0
  FA = U2D(X2[0], X2[1]); FB = U2D(X0[0], X0[1]);  // @287_51ddc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L51e10f;  // @288_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; });  // @289_51ddc0
  X0[1] = 0;  // @290_51ddc0
  X0[2] = 0;  // @291_51ddc0
  X0[3] = 0;  // @292_51ddc0
  goto L51e117;  // @293_51ddc0
  L51e10f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @295_51ddc0
  X0[1] = 0;  // @296_51ddc0
  X0[2] = 0;  // @297_51ddc0
  X0[3] = 0;  // @298_51ddc0
  L51e117:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 614) + 0), 4); v; });  // @300_51ddc0
  X1[1] = 0;  // @301_51ddc0
  X1[2] = 0;  // @302_51ddc0
  X1[3] = 0;  // @303_51ddc0
  X3[0] = F2U(U2F(X3[0]) - U2F(X4[0]));  // @304_51ddc0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 132) + 0), 4); v; });  // @305_51ddc0
  X2[1] = 0;  // @306_51ddc0
  X2[2] = 0;  // @307_51ddc0
  X2[3] = 0;  // @308_51ddc0
  PV[11] = (u32)(ecx);  // @309_51ddc0
  X3[0] = F2U(U2F(X3[0]) * U2F(X0[0]));  // @310_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @311_51ddc0
  X0[1] = 0;  // @312_51ddc0
  X0[2] = 0;  // @313_51ddc0
  X0[3] = 0;  // @314_51ddc0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @315_51ddc0
  X3[0] = F2U(U2F(X3[0]) * U2F(X2[0]));  // @316_51ddc0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @317_51ddc0
  X3[0] = F2U(U2F(X3[0]) + U2F(X4[0]));  // @318_51ddc0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @319_51ddc0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 618) + 0), 4); v; });  // @320_51ddc0
  X1[1] = 0;  // @321_51ddc0
  X1[2] = 0;  // @322_51ddc0
  X1[3] = 0;  // @323_51ddc0
  __builtin_memcpy((void *)((u32)(ecx) + 0), &X3[0], 4);  // @324_51ddc0
  ecx = edi;  // @325_51ddc0
  __builtin_memcpy((void *)((u32)(edi + 614) + 0), &X0[0], 4);  // @326_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @327_51ddc0
  X0[1] = 0;  // @328_51ddc0
  X0[2] = 0;  // @329_51ddc0
  X0[3] = 0;  // @330_51ddc0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @331_51ddc0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @332_51ddc0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @333_51ddc0
  __builtin_memcpy((void *)((u32)(edi + 618) + 0), &X0[0], 4);  // @334_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @335_51ddc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[11]);  // @336_51ddc0
  ecx = edx = 0;  // @337_51ddc0
  ecx = (u32)(edi + 610);  // @338_51ddc0
  eax = ext_44c840_thiscall1(ecx);  // @339_51ddc0
  ecx = 0;  // @340_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 610) + 0), 4); v; });  // @341_51ddc0
  X0[1] = 0;  // @342_51ddc0
  X0[2] = 0;  // @343_51ddc0
  X0[3] = 0;  // @344_51ddc0
  eax = (u32)(edi + 534);  // @345_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @346_51ddc0
  edx = (u32)(edi + 610);  // @347_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 614) + 0), 4); v; });  // @348_51ddc0
  X0[1] = 0;  // @349_51ddc0
  X0[2] = 0;  // @350_51ddc0
  X0[3] = 0;  // @351_51ddc0
  ecx = (u32)(EBP - 52);  // @352_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @353_51ddc0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @354_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 618) + 0), 4); v; });  // @355_51ddc0
  X0[1] = 0;  // @356_51ddc0
  X0[2] = 0;  // @357_51ddc0
  X0[3] = 0;  // @358_51ddc0
  PV[12] = (u32)(eax);  // @359_51ddc0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @360_51ddc0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[12]);  // @361_51ddc0
  ecx = edx = 0;  // @362_51ddc0
  ecx = (u32)(EBP - 52);  // @363_51ddc0
  eax = ext_44c840_thiscall1(ecx);  // @364_51ddc0
  ecx = 0;  // @365_51ddc0
  eax = (u32)(EBP - 64);  // @366_51ddc0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @367_51ddc0
  PV[13] = (u32)(eax);  // @368_51ddc0
  edx = (u32)(EBP - 52);  // @369_51ddc0
  ecx = (u32)(EBP - 76);  // @370_51ddc0
  eax = ext_446ee0_fastcall3(ecx, edx, PV[13]);  // @371_51ddc0
  ecx = edx = 0;  // @372_51ddc0
  ecx = (u32)(edi + 108);  // @373_51ddc0
  edx = (u32)(EBP - 76);  // @374_51ddc0
  eax = ext_4de420_fastcall2(ecx, edx);  // @375_51ddc0
    // @376_51ddc0
  eax = (u32)(EBP - 196);  // @377_51ddc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @378_51ddc0
  PV[14] = (u32)(eax);  // @379_51ddc0
  edx = (u32)(EBP - 172);  // @380_51ddc0
  { u32 v = (u32)((u32)(3343077376)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @381_51ddc0
  ecx = (u32)(EBP - 208);  // @382_51ddc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @383_51ddc0
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[14]);  // @384_51ddc0
  ecx = edx = 0;  // @385_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @386_51ddc0
  edx = (u32)(EBP - 208);  // @387_51ddc0
  PV[15] = (u32)(ecx);  // @388_51ddc0
  ecx = esi;  // @389_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @390_51ddc0
  X0[1] = 0;  // @391_51ddc0
  X0[2] = 0;  // @392_51ddc0
  X0[3] = 0;  // @393_51ddc0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @394_51ddc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6912128) + 0), 4); v; })));  // @395_51ddc0
  PV[16] = X0[0];  // @396_51ddc0
  eax = ext_451890_fastcall3(ecx, edx, PV[16]);  // @397_51ddc0
  ecx = 0;  // @398_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @399_51ddc0
  edx = (u32)(edi + 574);  // @400_51ddc0
  PV[17] = (u32)(ecx);  // @401_51ddc0
  ecx = esi;  // @402_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @403_51ddc0
  X0[1] = 0;  // @404_51ddc0
  X0[2] = 0;  // @405_51ddc0
  X0[3] = 0;  // @406_51ddc0
  PV[18] = X0[0];  // @407_51ddc0
  eax = ext_451890_fastcall3(ecx, edx, PV[18]);  // @408_51ddc0
  ecx = 0;  // @409_51ddc0
  edx = (u32)(edi + 586);  // @410_51ddc0
  ecx = esi;  // @411_51ddc0
  FS[0] = ext_4e0870_fastcall2_ld(ecx, edx);  // @412_51ddc0
  ecx = edx = 0;  // @413_51ddc0
  STF((u32)(EBP - 132), FS[0]);  // @414_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 132) + 0), 4); v; });  // @415_51ddc0
  X0[1] = 0;  // @416_51ddc0
  X0[2] = 0;  // @417_51ddc0
  X0[3] = 0;  // @418_51ddc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @419_51ddc0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L51e2d4;  // @420_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @421_51ddc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7346384), sizeof v); (u32)v; });  // @422_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @423_51ddc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @424_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @425_51ddc0
  FL[2] = (edx & edx);  // @426_51ddc0
  if (FL[2] != 0) goto L51e2c6;  // @427_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 536), sizeof v); (u32)v; });  // @428_51ddc0
  edx = (u32)(edi + 586);  // @429_51ddc0
  PV[19] = (u32)(edx);  // @430_51ddc0
  PV[20] = (u32)(esi);  // @431_51ddc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[20], PV[19], (u32)(16711680));  // @432_51ddc0
  ecx = edx = 0;  // @433_51ddc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7346384), &v, sizeof v); }  // @434_51ddc0
  goto L51e2d4;  // @435_51ddc0
  L51e2c6:;
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @437_51ddc0
  PV[22] = (u32)(esi);  // @438_51ddc0
  PV[23] = (u32)(edx);  // @439_51ddc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[23], PV[22], PV[21], (u32)(16711680));  // @440_51ddc0   (w3g hand fix: the shared `push 0xff0000` before the test edx,edx diamond)
  ecx = edx = 0;  // @441_51ddc0
  L51e2d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @443_51ddc0
  esi = (u32)(edi + 144);  // @444_51ddc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @445_51ddc0
  edx = edi;  // @446_51ddc0
  PV[24] = (u32)(esi);  // @447_51ddc0
  eax = ext_43e920_fastcall3(ecx, edx, PV[24]);  // @448_51ddc0
  ecx = edx = 0;  // @449_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @450_51ddc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @451_51ddc0
  X0[1] = 0;  // @452_51ddc0
  X0[2] = 0;  // @453_51ddc0
  X0[3] = 0;  // @454_51ddc0
  PV[25] = (u32)(ecx);  // @455_51ddc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @456_51ddc0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @457_51ddc0
  PV[26] = X0[0];  // @458_51ddc0
  eax = ext_4e0d00_thiscall2(ecx, PV[26]);  // @459_51ddc0
    // @460_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @461_51ddc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @462_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @463_51ddc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @464_51ddc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @465_51ddc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @466_51ddc0
  L51e322:;
  ext_633654(G(u32, 0x6f5630));  // @468_51ddc0
  return eax;  // @469_51ddc0
}
PCREG(51ddc0, lifted_51ddc0);

extern "C" u32 THISCALL lifted_52c6e0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_52c6e0
  ebx = ecx;  // @1_52c6e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_52c6e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @3_52c6e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @4_52c6e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @5_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @6_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 77), &v, sizeof v); }  // @7_52c6e0
  if (FL[0] == FL[1]) goto L52c71c;  // @8_52c6e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @9_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 73), &v, sizeof v); }  // @10_52c6e0
  L52c71c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @12_52c6e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 77), &v, sizeof v); }  // @13_52c6e0
  FL[2] = (eax & eax);  // @14_52c6e0
  if (FL[2] == 0) goto L52c744;  // @15_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @16_52c6e0
  if (FL[0] == FL[1]) goto L52c744;  // @17_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @18_52c6e0
  if (FL[0] != FL[1]) goto L52cab6;  // @19_52c6e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 73), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_52c6e0
  if (FL[0] != FL[1]) goto L52cab6;  // @21_52c6e0
  L52c744:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_52c6e0
  if (FL[0] == FL[1]) goto L52c772;  // @24_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @25_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(8979));  // @27_52c6e0
  ecx = edx = 0;  // @28_52c6e0
  PV[0] = (u32)(eax);  // @29_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_52c6e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6950972));  // @31_52c6e0
  ecx = edx = 0;  // @32_52c6e0
  goto L52cab6;  // @33_52c6e0
  L52c772:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7347032), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @35_52c6e0
  if (FL[0] == FL[1]) goto L52c79e;  // @36_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @37_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(8983));  // @39_52c6e0
  ecx = edx = 0;  // @40_52c6e0
  PV[1] = (u32)(eax);  // @41_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @42_52c6e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6951128));  // @43_52c6e0
  ecx = edx = 0;  // @44_52c6e0
  L52c79e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @46_52c6e0
  X0[1] = 0;  // @47_52c6e0
  X0[2] = 0;  // @48_52c6e0
  X0[3] = 0;  // @49_52c6e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @50_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @51_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @52_52c6e0
  X0[1] = 0;  // @53_52c6e0
  X0[2] = 0;  // @54_52c6e0
  X0[3] = 0;  // @55_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @56_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @57_52c6e0
  X0[1] = 0;  // @58_52c6e0
  X0[2] = 0;  // @59_52c6e0
  X0[3] = 0;  // @60_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @61_52c6e0
  FL[2] = (edx & edx);  // @62_52c6e0
  if (FL[2] == 0) goto L52c816;  // @63_52c6e0
  FL[0] = edx; FL[1] = (u32)(-1);  // @64_52c6e0
  if (FL[0] == FL[1]) goto L52c816;  // @65_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_52c6e0
  PV[2] = (u32)(edx);  // @67_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @68_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_52c6e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[2]);  // @70_52c6e0
  ecx = edx = 0;  // @71_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @72_52c6e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @73_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @75_52c6e0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097268));  // @76_52c6e0
  ecx = edx = 0;  // @77_52c6e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @78_52c6e0
  if (FL[2] == 0) goto L52c816;  // @79_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @80_52c6e0
  edx = (u32)(EBP - 16);  // @81_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @82_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @83_52c6e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @84_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_52c6e0
  PV[3] = (u32)(edx);  // @86_52c6e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1584)))(ecx, PV[3]);  // @87_52c6e0
  ecx = edx = 0;  // @88_52c6e0
  L52c816:;
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; });  // @90_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 44) + 0), 4); v; });  // @91_52c6e0
  X0[1] = 0;  // @92_52c6e0
  X0[2] = 0;  // @93_52c6e0
  X0[3] = 0;  // @94_52c6e0
  eax = (u32)(edi + 81);  // @95_52c6e0
  PV[5] = (u32)(eax);  // @96_52c6e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 49), sizeof v); (u32)v; });  // @97_52c6e0
  ecx = (u32)(esi + 20);  // @98_52c6e0
  PV[6] = (u32)(eax);  // @99_52c6e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @100_52c6e0
  PV[7] = (u32)(eax);  // @101_52c6e0
  PV[8] = (u32)(ecx);  // @102_52c6e0
  PV[9] = X0[0];  // @103_52c6e0
  eax = (u32)(EBP - 16);  // @104_52c6e0
  PV[10] = (u32)(ecx);  // @105_52c6e0
  PV[11] = (u32)(eax);  // @106_52c6e0
  ecx = ebx;  // @107_52c6e0
  eax = ext_52b170_thiscall8(ecx, PV[11], PV[10], PV[9], PV[7], PV[6], PV[5], PV[4]);  // @108_52c6e0
  ecx = edx = 0;  // @109_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 153), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @110_52c6e0
  ebx = eax;  // @111_52c6e0
  if (FL[0] != FL[1]) goto L52c8a9;  // @112_52c6e0
  FL[2] = (ebx & ebx);  // @113_52c6e0
  if (FL[2] == 0) goto L52caec;  // @114_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @115_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(9004));  // @117_52c6e0
  ecx = edx = 0;  // @118_52c6e0
  PV[12] = (u32)(eax);  // @119_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @120_52c6e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[12], (u32)(6951152));  // @121_52c6e0
  ecx = edx = 0;  // @122_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @123_52c6e0
  FL[2] = (eax & eax);  // @124_52c6e0
  if (FL[2] == 0) goto L52c895;  // @125_52c6e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @126_52c6e0
  ecx = edx = 0;  // @127_52c6e0
  ext_633654(G(u32, 0x6f5630));  // @128_52c6e0
  return eax;  // @129_52c6e0
  L52c895:;
  __builtin_trap();  // @131_52c6e0
  L52c8a9:;
  FL[2] = (ebx & ebx);  // @133_52c6e0
  if (FL[2] == 0) goto L52c8b8;  // @134_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @135_52c6e0
  PV[13] = (u32)(ebx);  // @136_52c6e0
  eax = ext_52b4e0_thiscall2(ecx, PV[13]);  // @137_52c6e0
  ecx = edx = 0;  // @138_52c6e0
  ebx = eax;  // @139_52c6e0
  L52c8b8:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @141_52c6e0
  FL[2] = (edx & edx);  // @142_52c6e0
  if (FL[2] == 0) goto L52ca9f;  // @143_52c6e0
  FL[0] = edx; FL[1] = (u32)(-1);  // @144_52c6e0
  if (FL[0] == FL[1]) goto L52ca9f;  // @145_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @146_52c6e0
  PV[14] = (u32)(edx);  // @147_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @148_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_52c6e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[14]);  // @150_52c6e0
  ecx = edx = 0;  // @151_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @152_52c6e0
  FL[2] = (eax & eax);  // @153_52c6e0
  if (FL[2] == 0) goto L52ca9f;  // @154_52c6e0
  FL[2] = (ebx & ebx);  // @155_52c6e0
  if (FL[2] == 0) goto L52c9fd;  // @156_52c6e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @157_52c6e0
  if ((s32)FL[0] <= (s32)FL[1]) goto L52c9fd;  // @158_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @159_52c6e0
  X0[1] = 0;  // @160_52c6e0
  X0[2] = 0;  // @161_52c6e0
  X0[3] = 0;  // @162_52c6e0
  ecx = (u32)(EBP - 28);  // @163_52c6e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @164_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @165_52c6e0
  edx = (edx + (u32)(4));  // @166_52c6e0
  FL[3] = edx;  // @167_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @168_52c6e0
  X0[1] = 0;  // @169_52c6e0
  X0[2] = 0;  // @170_52c6e0
  X0[3] = 0;  // @171_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @172_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @173_52c6e0
  X0[1] = 0;  // @174_52c6e0
  X0[2] = 0;  // @175_52c6e0
  X0[3] = 0;  // @176_52c6e0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @177_52c6e0
  FS[0] = ext_4e0870_fastcall2_ld(ecx, edx);  // @178_52c6e0
  ecx = edx = 0;  // @179_52c6e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; });  // @180_52c6e0
  X1[1] = 0;  // @181_52c6e0
  X1[2] = 0;  // @182_52c6e0
  X1[3] = 0;  // @183_52c6e0
  STF((u32)(EBP - 32), FS[0]);  // @184_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @185_52c6e0
  X0[1] = 0;  // @186_52c6e0
  X0[2] = 0;  // @187_52c6e0
  X0[3] = 0;  // @188_52c6e0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @189_52c6e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52c97b;  // @190_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @191_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(9034));  // @193_52c6e0
  ecx = edx = 0;  // @194_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @195_52c6e0
  X0[1] = 0;  // @196_52c6e0
  X0[2] = 0;  // @197_52c6e0
  X0[3] = 0;  // @198_52c6e0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @199_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @200_52c6e0
  __builtin_memcpy((void *)((u32)((EBP - 72)) + 0), &X0[0], 4);  // @201_52c6e0
  __builtin_memcpy((void *)((u32)((EBP - 72)) + 4), &X0[1], 4);  // @202_52c6e0
  PV[15] = (u32)(eax);  // @203_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, PV[15], (u32)(6951192), 0, 0);  // @204_52c6e0
  ecx = edx = 0;  // @205_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @206_52c6e0
  X0[1] = 0;  // @207_52c6e0
  X0[2] = 0;  // @208_52c6e0
  X0[3] = 0;  // @209_52c6e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; });  // @210_52c6e0
  X1[1] = 0;  // @211_52c6e0
  X1[2] = 0;  // @212_52c6e0
  X1[3] = 0;  // @213_52c6e0
  L52c97b:;
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; }));  // @215_52c6e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52c9fd;  // @216_52c6e0
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @217_52c6e0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52c9fd;  // @218_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @219_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @220_52c6e0
  X0[1] = 0;  // @221_52c6e0
  X0[2] = 0;  // @222_52c6e0
  X0[3] = 0;  // @223_52c6e0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @224_52c6e0
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X0[0], 4);  // @225_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @226_52c6e0
  X0[1] = 0;  // @227_52c6e0
  X0[2] = 0;  // @228_52c6e0
  X0[3] = 0;  // @229_52c6e0
  __builtin_memcpy((void *)((u32)(eax + 8) + 0), &X0[0], 4);  // @230_52c6e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @231_52c6e0
  X0[1] = 0;  // @232_52c6e0
  X0[2] = 0;  // @233_52c6e0
  X0[3] = 0;  // @234_52c6e0
  __builtin_memcpy((void *)((u32)(eax + 12) + 0), &X0[0], 4);  // @235_52c6e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @236_52c6e0
  if ((s32)FL[0] <= (s32)FL[1]) goto L52c9ee;  // @237_52c6e0
  edi = (u32)(16);  // @238_52c6e0
  L52c9c0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @240_52c6e0
  edx = (u32)(edi + 4);  // @241_52c6e0
  ecx = (u32)(edi - 12);  // @242_52c6e0
  edx = (edx + esi);  // @243_52c6e0
  FL[3] = edx;  // @244_52c6e0
  ecx = (ecx + esi);  // @245_52c6e0
  FL[3] = ecx;  // @246_52c6e0
  FS[0] = ext_4e0870_fastcall2_ld(ecx, edx);  // @247_52c6e0
  ecx = edx = 0;  // @248_52c6e0
  FS[0] = (FS[0] + LDF((u32)(esi + edi - 16)));  // @249_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @250_52c6e0
  eax = (eax + 1);  // @251_52c6e0
  FL[3] = eax;  // @252_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @253_52c6e0
  STF((u32)(esi + edi), FS[0]);  // @254_52c6e0
  edi = (edi + (u32)(16));  // @255_52c6e0
  FL[3] = edi;  // @256_52c6e0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @257_52c6e0
  if ((s32)FL[0] < (s32)FL[1]) goto L52c9c0;  // @258_52c6e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @259_52c6e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @260_52c6e0
  L52c9ee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @262_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @263_52c6e0
  ecx = (ecx + ecx);  // @264_52c6e0
  FL[3] = ecx;  // @265_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 - 16), sizeof v); (u32)v; });  // @266_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @267_52c6e0
  L52c9fd:;
  eax = ext_41e290_cdecl1((u32)(32));  // @269_52c6e0
  ecx = edx = 0;  // @270_52c6e0
  ecx = eax;  // @271_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @272_52c6e0
  FL[2] = (ecx & ecx);  // @273_52c6e0
  if (FL[2] == 0) goto L52ca1c;  // @274_52c6e0
  X0[0] = 0;  // @275_52c6e0
  X0[1] = 0;  // @276_52c6e0
  X0[2] = 0;  // @277_52c6e0
  X0[3] = 0;  // @278_52c6e0
  __builtin_memcpy((void *)((u32)(ecx) + 0), &X0[0], 4);  // @279_52c6e0
  __builtin_memcpy((void *)((u32)(ecx) + 4), &X0[1], 4);  // @280_52c6e0
  __builtin_memcpy((void *)((u32)(ecx) + 8), &X0[2], 4);  // @281_52c6e0
  __builtin_memcpy((void *)((u32)(ecx) + 12), &X0[3], 4);  // @282_52c6e0
  __builtin_memcpy((void *)((u32)(ecx + 16) + 0), &X0[0], 4);  // @283_52c6e0
  __builtin_memcpy((void *)((u32)(ecx + 16) + 4), &X0[1], 4);  // @284_52c6e0
  __builtin_memcpy((void *)((u32)(ecx + 16) + 8), &X0[2], 4);  // @285_52c6e0
  __builtin_memcpy((void *)((u32)(ecx + 16) + 12), &X0[3], 4);  // @286_52c6e0
  goto L52ca21;  // @287_52c6e0
  L52ca1c:;
  ecx = 0;  // @289_52c6e0
  FL[3] = ecx;  // @290_52c6e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @291_52c6e0
  L52ca21:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @293_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @294_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @295_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @296_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @297_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @298_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @299_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @300_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @301_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @302_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @303_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @304_52c6e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @305_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @306_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @307_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7347032), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @308_52c6e0
  if (FL[0] == FL[1]) goto L52ca7d;  // @309_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @310_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @311_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6950740), (u32)(9055));  // @312_52c6e0
  ecx = edx = 0;  // @313_52c6e0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @314_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @315_52c6e0
  PV[17] = (u32)(eax);  // @316_52c6e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[17], (u32)(6951288), PV[16]);  // @317_52c6e0
  ecx = edx = 0;  // @318_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @319_52c6e0
  L52ca7d:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @321_52c6e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @322_52c6e0
  FL[2] = (ebx & ebx);  // @323_52c6e0
  if (FL[2] == 0) goto L52ca9f;  // @324_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @325_52c6e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @326_52c6e0
  PV[18] = (u32)(ecx);  // @327_52c6e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 149), sizeof v); (u32)v; });  // @328_52c6e0
  ecx = ebx;  // @329_52c6e0
  PV[19] = (u32)(eax);  // @330_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[19], PV[18], (u32)(0));  // @331_52c6e0
  ecx = edx = 0;  // @332_52c6e0
  L52ca9f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @334_52c6e0
  PV[20] = (u32)(esi);  // @335_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 121), sizeof v); (u32)v; });  // @336_52c6e0
  eax = ext_52b390_fastcall3(ecx, edx, PV[20]);  // @337_52c6e0
  ecx = edx = 0;  // @338_52c6e0
  ecx = edi;  // @339_52c6e0
  eax = ext_52b0c0_thiscall1(ecx);  // @340_52c6e0
  ecx = edx = 0;  // @341_52c6e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @342_52c6e0
  if (FL[2] != 0) goto L52caec;  // @343_52c6e0
  L52cab6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @345_52c6e0
  FL[2] = (eax & eax);  // @346_52c6e0
  if (FL[2] == 0) goto L52cae8;  // @347_52c6e0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @348_52c6e0
  if (FL[0] == FL[1]) goto L52cae8;  // @349_52c6e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @350_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @351_52c6e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @352_52c6e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6950568), (u32)(61));  // @353_52c6e0
  ecx = edx = 0;  // @354_52c6e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @355_52c6e0
  ecx = eax;  // @356_52c6e0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @357_52c6e0
  FL[3] = ecx;  // @358_52c6e0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @359_52c6e0
  if (FL[0] <= FL[1]) goto L52cae8;  // @360_52c6e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @361_52c6e0
  L52cae8:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @363_52c6e0
  L52caec:;
  ext_633654(G(u32, 0x6f5630));  // @365_52c6e0
  return eax;  // @366_52c6e0
}
PCREG(52c6e0, lifted_52c6e0);

