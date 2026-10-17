// batch234023.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d70_dbl(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d76_dbl(double) __asm__("ext_634d76");
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" long double FASTCALL ext_4e0830_fastcall2_ld(u32, u32) __asm__("ext_4e0830");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 STDCALL ext_5941d0_stdcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5941d0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
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

extern "C" u32 THISCALL lifted_595800(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0d0d0d0d, esi = 0x0d0d0d0d, edi = 0x0d0d0d0d;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; });  // @0_595800
  X0[1] = 0;  // @1_595800
  X0[2] = 0;  // @2_595800
  X0[3] = 0;  // @3_595800
  edi = ecx;  // @4_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_595800
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @6_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; }));  // @7_595800
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L596663;  // @8_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @9_595800
  X0[1] = 0;  // @10_595800
  X0[2] = 0;  // @11_595800
  X0[3] = 0;  // @12_595800
  X1[0] = 0;  // @13_595800
  X1[1] = 0;  // @14_595800
  X1[2] = 0;  // @15_595800
  X1[3] = 0;  // @16_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @17_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @18_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @19_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59588e;  // @20_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @21_595800
  X0[1] = 0;  // @22_595800
  X0[2] = 0;  // @23_595800
  X0[3] = 0;  // @24_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @25_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @26_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @27_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59588e;  // @28_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @30_595800
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @31_595800 edx:eax result (w3g)
  ecx = 0;  // @32_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_595800
  PV[0] = (u32)(edx);  // @34_595800
  PV[1] = (u32)(eax);  // @35_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[1], PV[0], (u32)(6998696));  // @37_595800
  ecx = edx = 0;  // @38_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_595800
  L59588e:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @41_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3803) + 0), 4); v; });  // @42_595800
  X1[1] = 0;  // @43_595800
  X1[2] = 0;  // @44_595800
  X1[3] = 0;  // @45_595800
  if (FL[2] == 0) goto L5958aa;  // @46_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })));  // @47_595800
  L5958aa:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @49_595800
  X2[1] = 0;  // @50_595800
  X2[2] = 0;  // @51_595800
  X2[3] = 0;  // @52_595800
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @53_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @54_595800
  X3[1] = 0;  // @55_595800
  X3[2] = 0;  // @56_595800
  X3[3] = 0;  // @57_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5958dd;  // @58_595800
  X0[0] = X1[0];  // @59_595800
  X0[1] = X1[1];  // @60_595800
  X0[2] = X1[2];  // @61_595800
  X0[3] = X1[3];  // @62_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @63_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; })));  // @64_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @65_595800
  __builtin_memcpy((void *)((u32)(edi + 3799) + 0), &X0[0], 4);  // @66_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @67_595800
  L5958dd:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @69_595800
  X2[1] = 0;  // @70_595800
  X2[2] = 0;  // @71_595800
  X2[3] = 0;  // @72_595800
  X0[0] = X1[0];  // @73_595800
  X0[1] = X1[1];  // @74_595800
  X0[2] = X1[2];  // @75_595800
  X0[3] = X1[3];  // @76_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @77_595800
  FA = U2F(X2[0]); FB = U2F(X0[0]);  // @78_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L59590a;  // @79_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @80_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; })));  // @81_595800
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @82_595800
  __builtin_memcpy((void *)((u32)(edi + 3799) + 0), &X2[0], 4);  // @83_595800
  L59590a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_595800
  ecx = (u32)((EBP - 264) + 104);  // @86_595800
  PV[2] = (u32)(ecx);  // @87_595800
  ecx = (u32)((EBP - 268) + 192);  // @88_595800
  PV[3] = (u32)(ecx);  // @89_595800
  ecx = edi;  // @90_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[3], PV[2]);  // @91_595800
  ecx = edx = 0;  // @92_595800
  esi = (u32)(edi + 3763);  // @93_595800
  PV[4] = (u32)(esi);  // @94_595800
  edx = (u32)((EBP - 268) + 108);  // @95_595800
  ecx = (u32)((EBP - 268) + 180);  // @96_595800
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @97_595800
  ecx = edx = 0;  // @98_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @100_595800
  X0[1] = 0;  // @101_595800
  X0[2] = 0;  // @102_595800
  X0[3] = 0;  // @103_595800
  PV[5] = (u32)(ecx);  // @104_595800
  ecx = (u32)((EBP - 268) + 180);  // @105_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @106_595800
  PV[6] = X0[0];  // @107_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[6]);  // @108_595800
    // @109_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_595800
  PV[7] = (u32)(ecx);  // @111_595800
  ecx = (u32)((EBP - 268) + 180);  // @112_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @113_595800
  X0[1] = 0;  // @114_595800
  X0[2] = 0;  // @115_595800
  X0[3] = 0;  // @116_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @117_595800
  PV[8] = X0[0];  // @118_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[8]);  // @119_595800
    // @120_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @121_595800
  ecx = (u32)(edi + 3775);  // @122_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @123_595800
  X1[1] = 0;  // @124_595800
  X1[2] = 0;  // @125_595800
  X1[3] = 0;  // @126_595800
  PV[9] = (u32)(ecx);  // @127_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @128_595800
  X0[1] = 0;  // @129_595800
  X0[2] = 0;  // @130_595800
  X0[3] = 0;  // @131_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @132_595800
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @133_595800
  PV[10] = X1[0];  // @134_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[10]);  // @135_595800
    // @136_595800
  edx = (u32)((EBP - 264) + 176);  // @137_595800
  ecx = (u32)(edi + 3775);  // @138_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @139_595800
  ecx = edx = 0;  // @140_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 104) + 0), 4); v; });  // @141_595800
  X0[1] = 0;  // @142_595800
  X0[2] = 0;  // @143_595800
  X0[3] = 0;  // @144_595800
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @145_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 108) + 0), 4); v; });  // @146_595800
  X0[1] = 0;  // @147_595800
  X0[2] = 0;  // @148_595800
  X0[3] = 0;  // @149_595800
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @150_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 112) + 0), 4); v; });  // @151_595800
  X0[1] = 0;  // @152_595800
  X0[2] = 0;  // @153_595800
  X0[3] = 0;  // @154_595800
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @155_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3775) + 0), 4); v; });  // @156_595800
  X2[1] = 0;  // @157_595800
  X2[2] = 0;  // @158_595800
  X2[3] = 0;  // @159_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; })));  // @160_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 52), &v, sizeof v); }  // @161_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3783) + 0), 4); v; });  // @162_595800
  X1[1] = 0;  // @163_595800
  X1[2] = 0;  // @164_595800
  X1[3] = 0;  // @165_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; })));  // @166_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 48) + 0), &X2[0], 4);  // @167_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @168_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 56) + 0), &X1[0], 4);  // @169_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @170_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })));  // @171_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @172_595800
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @173_595800
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @174_595800
  ecx = edx = 0;  // @175_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 188) + 0), 4); v; });  // @176_595800
  X1[1] = 0;  // @177_595800
  X1[2] = 0;  // @178_595800
  X1[3] = 0;  // @179_595800
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @180_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @181_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 44) + 0), &X0[0], 4);  // @182_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 108) + 0), 4); v; });  // @183_595800
  X0[1] = 0;  // @184_595800
  X0[2] = 0;  // @185_595800
  X0[3] = 0;  // @186_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; })));  // @187_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 108) + 0), &X0[0], 4);  // @188_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595a69;  // @189_595800
  X0[0] = 0;  // @190_595800
  X0[1] = 0;  // @191_595800
  X0[2] = 0;  // @192_595800
  X0[3] = 0;  // @193_595800
  X1[0] = X0[0];  // @194_595800
  X1[1] = X0[1];  // @195_595800
  X1[2] = X0[2];  // @196_595800
  X1[3] = X0[3];  // @197_595800
  goto L595a92;  // @198_595800
  L595a69:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @200_595800
  X0[1] = 0;  // @201_595800
  X0[2] = 0;  // @202_595800
  X0[3] = 0;  // @203_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @204_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595a80;  // @205_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @206_595800
  X1[1] = 0;  // @207_595800
  X1[2] = 0;  // @208_595800
  X1[3] = 0;  // @209_595800
  goto L595a8f;  // @210_595800
  L595a80:;
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @212_595800
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @213_595800
  ecx = edx = 0;  // @214_595800
  X1[0] = 0;  // @215_595800
  X1[1] = 0;  // @216_595800
  X1[2] = 0;  // @217_595800
  X1[3] = 0;  // @218_595800
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @219_595800
  L595a8f:;
  X0[0] = 0;  // @221_595800
  X0[1] = 0;  // @222_595800
  X0[2] = 0;  // @223_595800
  X0[3] = 0;  // @224_595800
  L595a92:;
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 212) + 0), 4); v; }));  // @226_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; });  // @227_595800
  X2[1] = 0;  // @228_595800
  X2[2] = 0;  // @229_595800
  X2[3] = 0;  // @230_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595aae;  // @231_595800
  X0[0] = X2[0];  // @232_595800
  X0[1] = X2[1];  // @233_595800
  X0[2] = X2[2];  // @234_595800
  X0[3] = X2[3];  // @235_595800
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @236_595800
  X1[0] = X0[0];  // @237_595800
  X1[1] = X0[1];  // @238_595800
  X1[2] = X0[2];  // @239_595800
  X1[3] = X0[3];  // @240_595800
  L595aae:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @242_595800
  eax = (u32)(6);  // @243_595800
  FL[0] = esi; FL[1] = eax;  // @244_595800
  if ((s32)FL[0] < (s32)FL[1]) esi = eax;  // @245_595800
  ecx = 0;  // @246_595800
  FL[3] = ecx;  // @247_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 32), &v, sizeof v); }  // @248_595800
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @249_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @250_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @251_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @252_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @253_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @254_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(X2[0]));  // @255_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @256_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @257_595800
  FL[0] = eax; FL[1] = esi;  // @258_595800
  if ((s32)FL[0] < (s32)FL[1]) ecx = eax;  // @259_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 40), &v, sizeof v); }  // @260_595800
  ecx = (u32)((EBP - 264) + 224);  // @261_595800
  eax = ext_4de7a0_thiscall1(ecx);  // @262_595800
    // @263_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @264_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3795) + 0), 4); v; });  // @265_595800
  X3[1] = 0;  // @266_595800
  X3[2] = 0;  // @267_595800
  X3[3] = 0;  // @268_595800
  X3[0] = F2U(U2F(X3[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @269_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 164), &v, sizeof v); }  // @270_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 168), &v, sizeof v); }  // @271_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 172), &v, sizeof v); }  // @272_595800
  X3[0] = F2U(U2F(X3[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; })));  // @273_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X3[0], 4);  // @274_595800
  if (FL[2] == 0) goto L595b4b;  // @275_595800
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })));  // @276_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X3[0], 4);  // @277_595800
  L595b4b:;
  eax = 0;  // @279_595800
  FL[3] = eax;  // @280_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @281_595800
  FL[2] = (esi & esi);  // @282_595800
  if ((s32)FL[2] <= 0) goto L595ec7;  // @283_595800
  esi = (u32)(edi + 3423);  // @284_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @285_595800
  L595b63:;
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @287_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @288_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @289_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @290_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @291_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @292_595800
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @293_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @294_595800
  X1[0] = F2U((float)(s32)X1[0]);  // @295_595800
  X1[1] = F2U((float)(s32)X1[1]);  // @296_595800
  X1[2] = F2U((float)(s32)X1[2]);  // @297_595800
  X1[3] = F2U((float)(s32)X1[3]);  // @298_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @299_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @300_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @301_595800
  X1[1] = 0;  // @302_595800
  X1[2] = 0;  // @303_595800
  X1[3] = 0;  // @304_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @305_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X2[0], a_); SD(&X2[2], b_); }  // @306_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @307_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X2[0], 4);  // @308_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 4), &X2[1], 4);  // @309_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X0[0], 4);  // @310_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 4), &X0[1], 4);  // @311_595800
  X0[0] = X2[0];  // @312_595800
  X0[1] = X2[1];  // @313_595800
  X0[2] = X2[2];  // @314_595800
  X0[3] = X2[3];  // @315_595800
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @316_595800
  ecx = edx = 0;  // @317_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; })));  // @318_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @319_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 36) + 0), &X0[0], 4);  // @320_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @321_595800
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @322_595800
  ecx = edx = 0;  // @323_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; })));  // @324_595800
  edx = (u32)((EBP - 264) + 104);  // @325_595800
  ecx = (u32)((EBP - 264) + 116);  // @326_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 120), &v, sizeof v); }  // @327_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 36) + 0), 4); v; });  // @328_595800
  X1[1] = 0;  // @329_595800
  X1[2] = 0;  // @330_595800
  X1[3] = 0;  // @331_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 116) + 0), &X1[0], 4);  // @332_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @333_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 124) + 0), &X0[0], 4);  // @334_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @335_595800
  ecx = edx = 0;  // @336_595800
  edx = (u32)((EBP - 264) + 48);  // @337_595800
  ecx = (u32)((EBP - 264) + 116);  // @338_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @339_595800
  ecx = edx = 0;  // @340_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3787), sizeof v); (u32)v; });  // @341_595800
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 15), &v, sizeof v); }  // @342_595800
  FL[2] = (ecx & ecx);  // @343_595800
  if (FL[2] == 0) goto L595c32;  // @344_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @345_595800
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @346_595800
  if (FL[0] != FL[1]) goto L595c32;  // @347_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @348_595800
  edx = (u32)((EBP - 264) + 116);  // @349_595800
  PV[11] = (u32)(edx);  // @350_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 544), sizeof v); (u32)v; });  // @351_595800
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[11]);  // @352_595800
  ecx = edx = 0;  // @353_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @354_595800
  if (FL[2] == 0) goto L595dba;  // @355_595800
  L595c32:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @357_595800
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @358_595800
  if (FL[0] != FL[1]) goto L595d4a;  // @359_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @360_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1052), sizeof v); (u32)v; });  // @361_595800
  edx = (u32)(ecx + 1056);  // @362_595800
  eax = (eax + (u32)(264));  // @363_595800
  FL[3] = eax;  // @364_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 36), &v, sizeof v); }  // @365_595800
  eax = (u32)(ecx + eax*4);  // @366_595800
  FL[0] = edx; FL[1] = eax;  // @367_595800
  if (FL[0] == FL[1]) goto L595d4a;  // @368_595800
  L595c70:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @370_595800
  FL[2] = (esi & esi);  // @371_595800
  if (FL[2] == 0) goto L595d29;  // @372_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @373_595800
  ecx = esi;  // @374_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @375_595800
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1051586));  // @376_595800
  ecx = edx = 0;  // @377_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @378_595800
  if (FL[2] != 0) goto L595d1f;  // @379_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @380_595800
  edx = (u32)((EBP - 264) + 116);  // @381_595800
  eax = (eax + (u32)(36));  // @382_595800
  FL[3] = eax;  // @383_595800
  ecx = (u32)((EBP - 264) + 128);  // @384_595800
  PV[12] = (u32)(eax);  // @385_595800
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @386_595800
  ecx = edx = 0;  // @387_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @388_595800
  ecx = (u32)((EBP - 264) + 128);  // @389_595800
  eax = ext_441a60_fastcall2(ecx, edx);  // @390_595800
  ecx = edx = 0;  // @391_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @392_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 128) + 0), 4); v; });  // @393_595800
  X1[1] = 0;  // @394_595800
  X1[2] = 0;  // @395_595800
  X1[3] = 0;  // @396_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X2[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X2[2] = X2[3] = 0;  // @397_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @398_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @399_595800
  X0[1] = 0;  // @400_595800
  X0[2] = 0;  // @401_595800
  X0[3] = 0;  // @402_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @403_595800
  X1[0] = X1[0] & X2[0];  // @404_595800
  X1[1] = X1[1] & X2[1];  // @405_595800
  X1[2] = X1[2] & X2[2];  // @406_595800
  X1[3] = X1[3] & X2[3];  // @407_595800
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @408_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595d1f;  // @409_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 132) + 0), 4); v; });  // @410_595800
  X1[1] = 0;  // @411_595800
  X1[2] = 0;  // @412_595800
  X1[3] = 0;  // @413_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @414_595800
  X0[1] = 0;  // @415_595800
  X0[2] = 0;  // @416_595800
  X0[3] = 0;  // @417_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @418_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @419_595800
  X1[0] = X1[0] & X2[0];  // @420_595800
  X1[1] = X1[1] & X2[1];  // @421_595800
  X1[2] = X1[2] & X2[2];  // @422_595800
  X1[3] = X1[3] & X2[3];  // @423_595800
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @424_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595d1f;  // @425_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 136) + 0), 4); v; });  // @426_595800
  X1[1] = 0;  // @427_595800
  X1[2] = 0;  // @428_595800
  X1[3] = 0;  // @429_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @430_595800
  X0[1] = 0;  // @431_595800
  X0[2] = 0;  // @432_595800
  X0[3] = 0;  // @433_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @434_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @435_595800
  X1[0] = X1[0] & X2[0];  // @436_595800
  X1[1] = X1[1] & X2[1];  // @437_595800
  X1[2] = X1[2] & X2[2];  // @438_595800
  X1[3] = X1[3] & X2[3];  // @439_595800
  FA = U2D(X0[0], X0[1]); FB = U2D(X1[0], X1[1]);  // @440_595800
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L595db6;  // @441_595800
  L595d1f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @443_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 36), sizeof v); (u32)v; });  // @444_595800
  L595d29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1052), sizeof v); (u32)v; });  // @446_595800
  edx = (edx + (u32)(4));  // @447_595800
  FL[3] = edx;  // @448_595800
  eax = (eax + (u32)(264));  // @449_595800
  FL[3] = eax;  // @450_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 36), &v, sizeof v); }  // @451_595800
  eax = (u32)(ecx + eax*4);  // @452_595800
  FL[0] = edx; FL[1] = eax;  // @453_595800
  if (FL[0] != FL[1]) goto L595c70;  // @454_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @455_595800
  L595d4a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @457_595800
  X1[1] = 0;  // @458_595800
  X1[2] = 0;  // @459_595800
  X1[3] = 0;  // @460_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @461_595800
  X0[1] = 0;  // @462_595800
  X0[2] = 0;  // @463_595800
  X0[3] = 0;  // @464_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @465_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595d75;  // @466_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @467_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @468_595800
  X0[1] = 0;  // @469_595800
  X0[2] = 0;  // @470_595800
  X0[3] = 0;  // @471_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; })));  // @472_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @473_595800
  L595d71:;
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @475_595800
  L595d75:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3816) + 0), 4); v; });  // @477_595800
  X0[1] = 0;  // @478_595800
  X0[2] = 0;  // @479_595800
  X0[3] = 0;  // @480_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }));  // @481_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @482_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @483_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L595e53;  // @484_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @485_595800
  if (FL[0] == FL[1]) goto L595e14;  // @486_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @487_595800
  if (FL[0] == FL[1]) goto L595dd6;  // @488_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; });  // @489_595800
  edx = (u32)(65280);  // @490_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; }); FL[1] = eax;  // @491_595800
  eax = (u32)(16777215);  // @492_595800
  if (FL[0] == FL[1]) edx = eax;  // @493_595800
  goto L595ddb;  // @494_595800
  L595db6:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @496_595800
  L595dba:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @498_595800
  X0[1] = 0;  // @499_595800
  X0[2] = 0;  // @500_595800
  X0[3] = 0;  // @501_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; }));  // @502_595800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 15), &v, sizeof v); }  // @503_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L595d75;  // @504_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799784) + 0), 4); v; })));  // @505_595800
  goto L595d71;  // @506_595800
  L595dd6:;
  edx = (u32)(16711680);  // @508_595800
  L595ddb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @510_595800
  PV[13] = (u32)(edx);  // @511_595800
  edx = (u32)((EBP - 272) + 172);  // @512_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @513_595800
  PV[14] = (u32)(edx);  // @514_595800
  edx = (u32)((EBP - 276) + 128);  // @515_595800
  PV[15] = (u32)(edx);  // @516_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @517_595800
  edx = (u32)((EBP - 280) + 240);  // @518_595800
  PV[16] = (u32)(edx);  // @519_595800
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; });  // @520_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @521_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[17], PV[16], PV[15], PV[14], PV[13], (u32)(0));  // @522_595800
  ecx = edx = 0;  // @523_595800
  goto L595e7b;  // @524_595800
  L595e14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @526_595800
  edx = (u32)((EBP - 264) + 164);  // @527_595800
  PV[18] = (u32)(edx);  // @528_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @529_595800
  edx = (u32)((EBP - 276) + 128);  // @530_595800
  PV[19] = (u32)(edx);  // @531_595800
  edx = (u32)((EBP - 280) + 240);  // @532_595800
  PV[20] = (u32)(edx);  // @533_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @534_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @535_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 568), sizeof v); (u32)v; });  // @536_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[20], PV[19], PV[18], (u32)(16711680), (u32)(0));  // @537_595800
  ecx = edx = 0;  // @538_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 17), &v, sizeof v); }  // @539_595800
  goto L595e7b;  // @540_595800
  L595e53:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; });  // @542_595800
  FL[2] = (edx & edx);  // @543_595800
  if (FL[2] == 0) goto L595e7b;  // @544_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @545_595800
  PV[21] = (u32)(edx);  // @546_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @547_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @548_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @549_595800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[21]);  // @550_595800
  ecx = edx = 0;  // @551_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi - 17), &v, sizeof v); }  // @552_595800
  L595e7b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 116) + 0), 4); v; });  // @554_595800
  X0[1] = 0;  // @555_595800
  X0[2] = 0;  // @556_595800
  X0[3] = 0;  // @557_595800
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 15), sizeof v); (u32)v; })) & 0xff);  // @558_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @559_595800
  X3[1] = 0;  // @560_595800
  X3[2] = 0;  // @561_595800
  X3[3] = 0;  // @562_595800
  __builtin_memcpy((void *)((u32)(esi - 13) + 0), &X0[0], 4);  // @563_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 120) + 0), 4); v; });  // @564_595800
  X0[1] = 0;  // @565_595800
  X0[2] = 0;  // @566_595800
  X0[3] = 0;  // @567_595800
  __builtin_memcpy((void *)((u32)(esi - 9) + 0), &X0[0], 4);  // @568_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 124) + 0), 4); v; });  // @569_595800
  X0[1] = 0;  // @570_595800
  X0[2] = 0;  // @571_595800
  X0[3] = 0;  // @572_595800
  __builtin_memcpy((void *)((u32)(esi - 5) + 0), &X0[0], 4);  // @573_595800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi - 1), &v, sizeof v); }  // @574_595800
  esi = (esi + (u32)(21));  // @575_595800
  FL[3] = esi;  // @576_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @577_595800
  eax = (eax + 1);  // @578_595800
  FL[3] = eax;  // @579_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @580_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @581_595800
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @582_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L595b63;  // @583_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @584_595800
  L595ec7:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 3807), &v, sizeof v); }  // @586_595800
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @587_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; }); FL[1] = esi;  // @588_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L595edf;  // @589_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3807), &v, sizeof v); }  // @590_595800
  L595edf:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3816) + 0), 4); v; });  // @592_595800
  X0[1] = 0;  // @593_595800
  X0[2] = 0;  // @594_595800
  X0[3] = 0;  // @595_595800
  X1[0] = 0;  // @596_595800
  X1[1] = 0;  // @597_595800
  X1[2] = 0;  // @598_595800
  X1[3] = 0;  // @599_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @600_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @601_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @602_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59605a;  // @603_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @604_595800
  X0[1] = 0;  // @605_595800
  X0[2] = 0;  // @606_595800
  X0[3] = 0;  // @607_595800
  edx = (u32)((EBP - 264) + 104);  // @608_595800
  ecx = (u32)((EBP - 264) + 128);  // @609_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 0), &X0[0], 4);  // @610_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 132), &v, sizeof v); }  // @611_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 136), &v, sizeof v); }  // @612_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @613_595800
  ecx = edx = 0;  // @614_595800
  esi = (u32)(1);  // @615_595800
  L595f33:;
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @617_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @618_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @619_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @620_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @621_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @622_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @623_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @624_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @625_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X0[0], 4);  // @626_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 4), &X0[1], 4);  // @627_595800
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @628_595800
  ecx = edx = 0;  // @629_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @630_595800
  X1[1] = 0;  // @631_595800
  X1[2] = 0;  // @632_595800
  X1[3] = 0;  // @633_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @634_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @635_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @636_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X0[0], 4);  // @637_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @638_595800
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @639_595800
  ecx = edx = 0;  // @640_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @641_595800
  X1[1] = 0;  // @642_595800
  X1[2] = 0;  // @643_595800
  X1[3] = 0;  // @644_595800
  edx = (u32)((EBP - 264) + 104);  // @645_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @646_595800
  ecx = (u32)((EBP - 264) + 88);  // @647_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 92), &v, sizeof v); }  // @648_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @649_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @650_595800
  X1[1] = 0;  // @651_595800
  X1[2] = 0;  // @652_595800
  X1[3] = 0;  // @653_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X1[0], 4);  // @654_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @655_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 96) + 0), &X0[0], 4);  // @656_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @657_595800
  ecx = edx = 0;  // @658_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422624), sizeof v); (u32)v; });  // @659_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 28), &v, sizeof v); }  // @660_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7422628), sizeof v); (u32)v; });  // @661_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @662_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @663_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @664_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @665_595800
  FL[2] = (edx & edx);  // @666_595800
  if (FL[2] != 0) goto L596008;  // @667_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 536), sizeof v); (u32)v; });  // @668_595800
  edx = (u32)((EBP - 268) + 92);  // @669_595800
  PV[22] = (u32)(edx);  // @670_595800
  edx = (u32)((EBP - 272) + 136);  // @671_595800
  PV[23] = (u32)(edx);  // @672_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[23], PV[22], (u32)(16711680));  // @673_595800
  ecx = edx = 0;  // @674_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 28), sizeof v); (u32)v; });  // @675_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx*4 + 7422628), &v, sizeof v); }  // @676_595800
  goto L596020;  // @677_595800
  L596008:;
  edi = (u32)((EBP - 268) + 92);  // @679_595800 (w3g: one push pending: 0xff0000)
  PV[24] = (u32)(edi);  // @680_595800
  edi = (u32)((EBP - 272) + 136);  // @681_595800 (w3g: two pushes pending)
  PV[25] = (u32)(edi);  // @682_595800
  PV[26] = (u32)(edx);  // @683_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[26], PV[25], PV[24], (u32)(16711680));  /* w3g: the 0xff0000 pushed at 0x595fc3 before the diamond belongs to both arms */  // @684_595800
  ecx = edx = 0;  // @685_595800
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 24), sizeof v); (u32)v; });  // @686_595800
  L596020:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422624), sizeof v); (u32)v; });  // @688_595800
  ecx = (u32)(10);  // @689_595800
  eax = (eax + 1);  // @690_595800
  FL[3] = eax;  // @691_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; });  // @692_595800
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; });  // @693_595800
  X0[2] = 0;  // @694_595800
  X0[3] = 0;  // @695_595800
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @696_595800
  esi = (esi + 1);  // @697_595800
  FL[3] = esi;  // @698_595800
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @699_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 96), sizeof v); (u32)v; });  // @700_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7422624), &v, sizeof v); }  // @701_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 0), &X0[0], 4);  // @702_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 4), &X0[1], 4);  // @703_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 136), &v, sizeof v); }  // @704_595800
  FL[0] = esi; FL[1] = ecx;  // @705_595800
  if ((s32)FL[0] <= (s32)FL[1]) goto L595f33;  // @706_595800
  X1[0] = 0;  // @707_595800
  X1[1] = 0;  // @708_595800
  X1[2] = 0;  // @709_595800
  X1[3] = 0;  // @710_595800
  L59605a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @712_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @713_595800
  X0[1] = 0;  // @714_595800
  X0[2] = 0;  // @715_595800
  X0[3] = 0;  // @716_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @717_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @718_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @719_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L5960ab;  // @720_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @721_595800
  X0[1] = 0;  // @722_595800
  X0[2] = 0;  // @723_595800
  X0[3] = 0;  // @724_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @725_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @726_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @727_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L5960ab;  // @728_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @729_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @730_595800
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @731_595800 edx:eax result (w3g)
  ecx = 0;  // @732_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @733_595800
  PV[27] = (u32)(edx);  // @734_595800
  PV[28] = (u32)(eax);  // @735_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @736_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[28], PV[27], (u32)(6998704));  // @737_595800
  ecx = edx = 0;  // @738_595800
  L5960ab:;
  eax = 0;  // @740_595800
  FL[3] = eax;  // @741_595800
  edx = (u32)((EBP - 264) + 104);  // @742_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @743_595800
  ecx = (u32)((EBP - 264) + 60);  // @744_595800
  eax = (u32)((EBP - 264) + 48);  // @745_595800
  PV[29] = (u32)(eax);  // @746_595800
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[29]);  // @747_595800
  ecx = edx = 0;  // @748_595800
  eax = (u32)(edi + 2586);  // @749_595800
  esi = eax;  // @750_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @751_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @752_595800
  eax = (u32)(eax + eax*2);  // @753_595800
  eax = (eax << (u32)(4));  // @754_595800
  FL[3] = eax;  // @755_595800
  eax = (eax + (u32)(2586));  // @756_595800
  FL[3] = eax;  // @757_595800
  eax = (eax + edi);  // @758_595800
  FL[3] = eax;  // @759_595800
  FL[0] = esi; FL[1] = eax;  // @760_595800
  if (FL[0] == FL[1]) goto L5961cc;  // @761_595800
  L5960f0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @763_595800
  edx = (u32)(esi + 32);  // @764_595800
  PV[30] = (u32)(edx);  // @765_595800
  edx = (u32)((EBP - 268) + 132);  // @766_595800
  PV[31] = (u32)(edx);  // @767_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @768_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1404)))(ecx, PV[31], PV[30]);  // @769_595800
  ecx = edx = 0;  // @770_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @771_595800
  X0[1] = 0;  // @772_595800
  X0[2] = 0;  // @773_595800
  X0[3] = 0;  // @774_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @775_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @776_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @777_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @778_595800
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @779_595800
  if ((s32)FL[0] >= (s32)FL[1]) goto L59617a;  // @780_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; });  // @781_595800
  X0[1] = 0;  // @782_595800
  X0[2] = 0;  // @783_595800
  X0[3] = 0;  // @784_595800
  eax = (u32)((EBP - 264) + 188);  // @785_595800
  PV[32] = (u32)(ecx);  // @786_595800
  PV[33] = X0[0];  // @787_595800
  ecx = edi;  // @788_595800
  PV[34] = (u32)(eax);  // @789_595800
  eax = (u32)((EBP - 272) + 112);  // @790_595800
  PV[35] = (u32)(eax);  // @791_595800
  eax = (u32)((EBP - 276) + 72);  // @792_595800
  PV[36] = (u32)(eax);  // @793_595800
  eax = (u32)(esi + 32);  // @794_595800
  PV[37] = (u32)(eax);  // @795_595800
  eax = (u32)((EBP - 284) + 148);  // @796_595800
  PV[38] = (u32)(eax);  // @797_595800
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @798_595800
  eax = ext_5941d0_stdcall7(PV[39], PV[38], PV[37], PV[36], PV[35], PV[34], PV[33]);  // @799_595800
  ecx = edx = 0;  // @800_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @801_595800
  if (FL[2] == 0) goto L59617a;  // @802_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @803_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @804_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @805_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @806_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @807_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @808_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @809_595800
  __builtin_memcpy((void *)((u32)(esi + 20) + 0), &X0[0], 4);  // @810_595800
  L59617a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; });  // @812_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @813_595800
  eax = (eax + ecx);  // @814_595800
  FL[3] = eax;  // @815_595800
  if ((s32)FL[3] >= 0) goto L59618c;  // @816_595800
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; }));  // @817_595800
  FL[3] = eax;  // @818_595800
  goto L596196;  // @819_595800
  L59618c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @821_595800
  FL[0] = eax; FL[1] = edx;  // @822_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L596196;  // @823_595800
  eax = (eax - edx);  // @824_595800
  FL[3] = eax;  // @825_595800
  L596196:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @827_595800
  FL[2] = (ecx & ecx);  // @828_595800
  if ((s32)FL[2] >= 0) goto L5961a5;  // @829_595800
  FL[1] = ecx;  // @830_595800
  ecx = (0u - ecx);  // @831_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @832_595800
  goto L5961ae;  // @833_595800
  L5961a5:;
  eax = (eax | (u32)(4294967295));  // @835_595800
  FL[3] = eax;  // @836_595800
  eax = (eax - ecx);  // @837_595800
  FL[3] = eax;  // @838_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @839_595800
  L5961ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @841_595800
  esi = (esi + (u32)(48));  // @842_595800
  FL[3] = esi;  // @843_595800
  eax = (u32)(eax + eax*2);  // @844_595800
  eax = (eax << (u32)(4));  // @845_595800
  FL[3] = eax;  // @846_595800
  eax = (eax + (u32)(2586));  // @847_595800
  FL[3] = eax;  // @848_595800
  eax = (eax + edi);  // @849_595800
  FL[3] = eax;  // @850_595800
  FL[0] = esi; FL[1] = eax;  // @851_595800
  if (FL[0] != FL[1]) goto L5960f0;  // @852_595800
  L5961cc:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @854_595800
  X1[0] = 0;  // @855_595800
  X1[1] = 0;  // @856_595800
  X1[2] = 0;  // @857_595800
  X1[3] = 0;  // @858_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @859_595800
  X0[1] = 0;  // @860_595800
  X0[2] = 0;  // @861_595800
  X0[3] = 0;  // @862_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @863_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @864_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @865_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59622b;  // @866_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @867_595800
  X0[1] = 0;  // @868_595800
  X0[2] = 0;  // @869_595800
  X0[3] = 0;  // @870_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @871_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @872_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @873_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59622b;  // @874_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @875_595800
  ecx = edx;  // @876_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @877_595800
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @878_595800 edx:eax result (w3g)
  ecx = 0;  // @879_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @880_595800
  PV[40] = (u32)(edx);  // @881_595800
  PV[41] = (u32)(eax);  // @882_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @883_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[41], PV[40], (u32)(6998704));  // @884_595800
  ecx = edx = 0;  // @885_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @886_595800
  X1[0] = 0;  // @887_595800
  X1[1] = 0;  // @888_595800
  X1[2] = 0;  // @889_595800
  X1[3] = 0;  // @890_595800
  L59622b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @892_595800
  X0[1] = 0;  // @893_595800
  X0[2] = 0;  // @894_595800
  X0[3] = 0;  // @895_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @896_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @897_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @898_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59627e;  // @899_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @900_595800
  X0[1] = 0;  // @901_595800
  X0[2] = 0;  // @902_595800
  X0[3] = 0;  // @903_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @904_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @905_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @906_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59627e;  // @907_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @908_595800
  ecx = edx;  // @909_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @910_595800
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @911_595800 edx:eax result (w3g)
  ecx = 0;  // @912_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @913_595800
  PV[42] = (u32)(edx);  // @914_595800
  PV[43] = (u32)(eax);  // @915_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @916_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[43], PV[42], (u32)(6998712));  // @917_595800
  ecx = edx = 0;  // @918_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @919_595800
  L59627e:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3779) + 0), 4); v; });  // @921_595800
  X1[1] = 0;  // @922_595800
  X1[2] = 0;  // @923_595800
  X1[3] = 0;  // @924_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3775) + 0), 4); v; });  // @925_595800
  X2[1] = 0;  // @926_595800
  X2[2] = 0;  // @927_595800
  X2[3] = 0;  // @928_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3783) + 0), 4); v; });  // @929_595800
  X0[1] = 0;  // @930_595800
  X0[2] = 0;  // @931_595800
  X0[3] = 0;  // @932_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @933_595800
  ecx = eax;  // @934_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @935_595800
  ecx = (ecx >> (u32)(1));  // @936_595800
  FL[3] = ecx;  // @937_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @938_595800
  ecx = (ecx & (u32)(4294967041));  // @939_595800
  FL[3] = ecx;  // @940_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 40), &v, sizeof v); }  // @941_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @942_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @943_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @944_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X2[0], 4);  // @945_595800
  FL[2] = (eax & (u32)(1024));  // @946_595800
  if (FL[2] == 0) goto L5962db;  // @947_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000612) + 0), 4); v; });  // @948_595800
  X1[1] = 0;  // @949_595800
  X1[2] = 0;  // @950_595800
  X1[3] = 0;  // @951_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 20) + 0), &X1[0], 4);  // @952_595800
  goto L5962e9;  // @953_595800
  L5962db:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000616) + 0), 4); v; });  // @955_595800
  X0[1] = 0;  // @956_595800
  X0[2] = 0;  // @957_595800
  X0[3] = 0;  // @958_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 20) + 0), &X0[0], 4);  // @959_595800
  L5962e9:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3795) + 0), 4); v; });  // @961_595800
  X0[1] = 0;  // @962_595800
  X0[2] = 0;  // @963_595800
  X0[3] = 0;  // @964_595800
  ecx = (u32)(edi + 2586);  // @965_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @966_595800
  X1[0] = X0[0];  // @967_595800
  X1[1] = X0[1];  // @968_595800
  X1[2] = X0[2];  // @969_595800
  X1[3] = X0[3];  // @970_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000564) + 0), 4); v; })));  // @971_595800
  eax = (u32)(eax + eax*2);  // @972_595800
  eax = (eax << (u32)(4));  // @973_595800
  FL[3] = eax;  // @974_595800
  eax = (eax + (u32)(2586));  // @975_595800
  FL[3] = eax;  // @976_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @977_595800
  eax = (eax + edi);  // @978_595800
  FL[3] = eax;  // @979_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 44) + 0), &X1[0], 4);  // @980_595800
  FL[0] = ecx; FL[1] = eax;  // @981_595800
  if (FL[0] == FL[1]) goto L5965bd;  // @982_595800
  esi = (u32)(ecx + 12);  // @983_595800
  L596330:;
  edx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }) * (s32)(u32)(21));  // @985_595800
  ecx = (u32)(esi - 8);  // @986_595800
  edx = (edx + (u32)(3410));  // @987_595800
  FL[3] = edx;  // @988_595800
  edx = (edx + edi);  // @989_595800
  FL[3] = edx;  // @990_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 28), &v, sizeof v); }  // @991_595800
  FS[0] = ext_4e0830_fastcall2_ld(ecx, edx);  // @992_595800
  ecx = edx = 0;  // @993_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @994_595800
  X0[1] = 0;  // @995_595800
  X0[2] = 0;  // @996_595800
  X0[3] = 0;  // @997_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @998_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @999_595800
  STF((u32)((EBP - 264) + 24), FS[0]);  // @1000_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; });  // @1001_595800
  X1[1] = 0;  // @1002_595800
  X1[2] = 0;  // @1003_595800
  X1[3] = 0;  // @1004_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @1005_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @1006_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 32) + 0), &X1[0], 4);  // @1007_595800
  eax = (eax - ecx);  // @1008_595800
  FL[3] = eax;  // @1009_595800
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; }));  // @1010_595800
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @1011_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @1012_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @1013_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @1014_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @1015_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @1016_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 36) + 0), &X0[0], 4);  // @1017_595800
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5963ae;  // @1018_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @1019_595800
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L5963ae;  // @1020_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @1021_595800
  if (FL[0] != FL[1]) goto L596594;  // @1022_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1023_595800
  if (FL[0] != FL[1]) goto L596594;  // @1024_595800
  L5963ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 28), sizeof v); (u32)v; });  // @1026_595800
  ecx = (u32)(esi + 20);  // @1027_595800
  edx = (u32)((EBP - 264) + 104);  // @1028_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1029_595800
  X0[1] = 0;  // @1030_595800
  X0[2] = 0;  // @1031_595800
  X0[3] = 0;  // @1032_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X0[0], 4);  // @1033_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @1034_595800
  X0[1] = 0;  // @1035_595800
  X0[2] = 0;  // @1036_595800
  X0[3] = 0;  // @1037_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 76) + 0), &X0[0], 4);  // @1038_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @1039_595800
  X0[1] = 0;  // @1040_595800
  X0[2] = 0;  // @1041_595800
  X0[3] = 0;  // @1042_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 80) + 0), &X0[0], 4);  // @1043_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @1044_595800
  X0[1] = 0;  // @1045_595800
  X0[2] = 0;  // @1046_595800
  X0[3] = 0;  // @1047_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X0[0], 4);  // @1048_595800
  FS[0] = ext_4e0830_fastcall2_ld(ecx, edx);  // @1049_595800
  ecx = edx = 0;  // @1050_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @1051_595800
  X1[1] = 0;  // @1052_595800
  X1[2] = 0;  // @1053_595800
  X1[3] = 0;  // @1054_595800
  eax = 0;  // @1055_595800
  FL[3] = eax;  // @1056_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @1057_595800
  STF((u32)((EBP - 264) + 24), FS[0]);  // @1058_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; });  // @1059_595800
  X0[1] = 0;  // @1060_595800
  X0[2] = 0;  // @1061_595800
  X0[3] = 0;  // @1062_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1063_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; });  // @1064_595800
  X0[1] = 0;  // @1065_595800
  X0[2] = 0;  // @1066_595800
  X0[3] = 0;  // @1067_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 136) + 0), &X0[0], 4);  // @1068_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 76) + 0), 4); v; });  // @1069_595800
  X0[1] = 0;  // @1070_595800
  X0[2] = 0;  // @1071_595800
  X0[3] = 0;  // @1072_595800
  eax = (eax & 0xffffff00u) | (((((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) ? 1 : 0)) & 0xff);  // @1073_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1074_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 140) + 0), &X0[0], 4);  // @1075_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 80) + 0), 4); v; });  // @1076_595800
  X0[1] = 0;  // @1077_595800
  X0[2] = 0;  // @1078_595800
  X0[3] = 0;  // @1079_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 132), &v, sizeof v); }  // @1080_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 144) + 0), &X0[0], 4);  // @1081_595800
  if (FL[0] != FL[1]) goto L596452;  // @1082_595800
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1083_595800
  FL[2] = (eax & eax);  // @1084_595800
  if (FL[2] == 0) goto L59645d;  // @1085_595800
  L596452:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1087_595800
  L59645d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 36) + 0), 4); v; });  // @1089_595800
  X0[1] = 0;  // @1090_595800
  X0[2] = 0;  // @1091_595800
  X0[3] = 0;  // @1092_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 32) + 0), 4); v; });  // @1093_595800
  X1[1] = 0;  // @1094_595800
  X1[2] = 0;  // @1095_595800
  X1[3] = 0;  // @1096_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @1097_595800
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @1098_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 20) + 0), 4); v; });  // @1099_595800
  X0[1] = 0;  // @1100_595800
  X0[2] = 0;  // @1101_595800
  X0[3] = 0;  // @1102_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1103_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5964b2;  // @1104_595800
  edx = (u32)((EBP - 264) + 72);  // @1105_595800
  ecx = (u32)(esi + 20);  // @1106_595800
  FS[0] = ext_4e0830_fastcall2_ld(ecx, edx);  // @1107_595800
  ecx = edx = 0;  // @1108_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 20) + 0), 4); v; });  // @1109_595800
  X0[1] = 0;  // @1110_595800
  X0[2] = 0;  // @1111_595800
  X0[3] = 0;  // @1112_595800
  STF((u32)((EBP - 264) + 24), FS[0]);  // @1113_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; }));  // @1114_595800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5964b2;  // @1115_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; });  // @1116_595800
  X0[1] = 0;  // @1117_595800
  X0[2] = 0;  // @1118_595800
  X0[3] = 0;  // @1119_595800
  eax = 0;  // @1120_595800
  FL[3] = eax;  // @1121_595800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }));  // @1122_595800
  eax = (eax & 0xffffff00u) | ((((((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) ? 1 : 0)) & 0xff);  // @1123_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1124_595800
  L5964b2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1126_595800
  eax = (u32)((EBP - 264) + 128);  // @1127_595800
  PV[44] = (u32)(eax);  // @1128_595800
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2024), sizeof v); (u32)v; });  // @1129_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1130_595800
  PV[45] = (u32)(eax);  // @1131_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1132_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[45], PV[44], (u32)(0));  // @1133_595800
  ecx = edx = 0;  // @1134_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; });  // @1135_595800
  X0[1] = 0;  // @1136_595800
  X0[2] = 0;  // @1137_595800
  X0[3] = 0;  // @1138_595800
  X1[0] = 0;  // @1139_595800
  X1[1] = 0;  // @1140_595800
  X1[2] = 0;  // @1141_595800
  X1[3] = 0;  // @1142_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 128), sizeof v); (u32)v; });  // @1143_595800
  __builtin_memcpy((void *)((u32)(esi - 8) + 0), &X0[0], 4);  // @1144_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 76) + 0), 4); v; });  // @1145_595800
  X0[1] = 0;  // @1146_595800
  X0[2] = 0;  // @1147_595800
  X0[3] = 0;  // @1148_595800
  __builtin_memcpy((void *)((u32)(esi - 4) + 0), &X0[0], 4);  // @1149_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 80) + 0), 4); v; });  // @1150_595800
  X0[1] = 0;  // @1151_595800
  X0[2] = 0;  // @1152_595800
  X0[3] = 0;  // @1153_595800
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @1154_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1155_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1156_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @1157_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @1158_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @1159_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @1160_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @1161_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @1162_595800
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @1163_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @1164_595800
  X0[1] = 0;  // @1165_595800
  X0[2] = 0;  // @1166_595800
  X0[3] = 0;  // @1167_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1168_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1169_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1170_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596544;  // @1171_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @1172_595800
  if (FL[2] != 0) goto L596544;  // @1173_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @1174_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @1175_595800
  goto L596568;  // @1176_595800
  L596544:;
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1178_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1179_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1180_595800
  if (!__builtin_parity(FL[2] & 0xff)) goto L59658e;  // @1181_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @1182_595800
  if (FL[2] == 0) goto L59658e;  // @1183_595800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @1184_595800
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @1185_595800
  L596568:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3811), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1187_595800
  if (FL[0] == FL[1]) goto L59658e;  // @1188_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1189_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1190_595800
  eax = (u32)((EBP - 268) + 28);  // @1191_595800
  PV[46] = (u32)(eax);  // @1192_595800
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2026), sizeof v); (u32)v; });  // @1193_595800
  PV[47] = (u32)(eax);  // @1194_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1195_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[47], PV[46], (u32)(0));  // @1196_595800
  ecx = edx = 0;  // @1197_595800
  L59658e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1199_595800
  L596594:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @1201_595800
  esi = (esi + (u32)(48));  // @1202_595800
  FL[3] = esi;  // @1203_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1204_595800
  ecx = (ecx + (u32)(48));  // @1205_595800
  FL[3] = ecx;  // @1206_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @1207_595800
  eax = (u32)(eax + eax*2);  // @1208_595800
  eax = (eax << (u32)(4));  // @1209_595800
  FL[3] = eax;  // @1210_595800
  eax = (eax + (u32)(2586));  // @1211_595800
  FL[3] = eax;  // @1212_595800
  eax = (eax + edi);  // @1213_595800
  FL[3] = eax;  // @1214_595800
  FL[0] = ecx; FL[1] = eax;  // @1215_595800
  if (FL[0] != FL[1]) goto L596330;  // @1216_595800
  L5965bd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @1218_595800
  X0[1] = 0;  // @1219_595800
  X0[2] = 0;  // @1220_595800
  X0[3] = 0;  // @1221_595800
  X1[0] = 0;  // @1222_595800
  X1[1] = 0;  // @1223_595800
  X1[2] = 0;  // @1224_595800
  X1[3] = 0;  // @1225_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1226_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1227_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1228_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596616;  // @1229_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @1230_595800
  X0[1] = 0;  // @1231_595800
  X0[2] = 0;  // @1232_595800
  X0[3] = 0;  // @1233_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1234_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1235_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1236_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596616;  // @1237_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1238_595800
  ecx = edx;  // @1239_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @1240_595800
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @1241_595800 edx:eax result (w3g)
  ecx = 0;  // @1242_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1243_595800
  PV[48] = (u32)(edx);  // @1244_595800
  PV[49] = (u32)(eax);  // @1245_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1246_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[49], PV[48], (u32)(6998712));  // @1247_595800
  ecx = edx = 0;  // @1248_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1249_595800
  X1[0] = 0;  // @1250_595800
  X1[1] = 0;  // @1251_595800
  X1[2] = 0;  // @1252_595800
  X1[3] = 0;  // @1253_595800
  L596616:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @1255_595800
  X0[1] = 0;  // @1256_595800
  X0[2] = 0;  // @1257_595800
  X0[3] = 0;  // @1258_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1259_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1260_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1261_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596663;  // @1262_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @1263_595800
  X0[1] = 0;  // @1264_595800
  X0[2] = 0;  // @1265_595800
  X0[3] = 0;  // @1266_595800
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1267_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @1268_595800
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @1269_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596663;  // @1270_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1271_595800
  ecx = edx;  // @1272_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @1273_595800
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @1274_595800 edx:eax result (w3g)
  ecx = 0;  // @1275_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1276_595800
  PV[50] = (u32)(edx);  // @1277_595800
  PV[51] = (u32)(eax);  // @1278_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1279_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[51], PV[50], (u32)(6998696));  // @1280_595800
  ecx = edx = 0;  // @1281_595800
  L596663:;
  ext_633654(G(u32, 0x6f5630));  // @1283_595800
  return eax;  // @1284_595800
}
PCREG(595800, lifted_595800);

