// batch252017.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" s32 VECTORCALL ext_633910(float f);
extern "C" u32 FASTCALL ext_52d250_fastcall4(u32, u32, u32, u32) __asm__("ext_52d250");
extern "C" u32 STDCALL ext_532730_stdcall1(u32) __asm__("ext_532730");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_530a40_thiscall1(u32) __asm__("ext_530a40");
extern "C" u32 THISCALL ext_531740_thiscall3(u32, u32, u32) __asm__("ext_531740");
extern "C" u32 THISCALL ext_5ac660_thiscall3(u32, u32, u32) __asm__("ext_5ac660");
extern "C" u32 THISCALL ext_5ebde0_thiscall2(u32, u32) __asm__("ext_5ebde0");
extern "C" u32 THISCALL ext_5ec2b0_thiscall3(u32, u32, u32) __asm__("ext_5ec2b0");
extern "C" u32 THISCALL ext_5ec5a0_thiscall2(u32, u32) __asm__("ext_5ec5a0");
extern "C" u32 THISCALL ext_6361e0_thiscall1(u32) __asm__("ext_6361e0");
extern "C" u32 THISCALL ext_6363a0_thiscall1(u32) __asm__("ext_6363a0");
extern "C" u32 THISCALL ext_637a30_thiscall3(u32, u32, u32) __asm__("ext_637a30");
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

extern "C" u32 THISCALL lifted_5ab580(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_5ab580
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5ab580
  esi = ecx;  // @2_5ab580
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @3_5ab580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @4_5ab580
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @5_5ab580
  if (FL[0] == FL[1]) goto L5ab911;  // @6_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @7_5ab580
  ecx = ebx;  // @8_5ab580
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @9_5ab580
  ecx = edx = 0;  // @10_5ab580
  ecx = ebx;  // @11_5ab580
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @12_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_5ab580
  X0[0] = F2U((float)(s32)X0[0]);  // @14_5ab580
  X0[1] = F2U((float)(s32)X0[1]);  // @15_5ab580
  X0[2] = F2U((float)(s32)X0[2]);  // @16_5ab580
  X0[3] = F2U((float)(s32)X0[3]);  // @17_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @18_5ab580
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @19_5ab580
  ecx = edx = 0;  // @20_5ab580
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @21_5ab580
  X2[1] = 0;  // @22_5ab580
  X2[2] = 0;  // @23_5ab580
  X2[3] = 0;  // @24_5ab580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @25_5ab580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @26_5ab580
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @27_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @28_5ab580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @29_5ab580
  X1[0] = F2U((float)(s32)X1[0]);  // @30_5ab580
  X1[1] = F2U((float)(s32)X1[1]);  // @31_5ab580
  X1[2] = F2U((float)(s32)X1[2]);  // @32_5ab580
  X1[3] = F2U((float)(s32)X1[3]);  // @33_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X1[0], 4);  // @34_5ab580
  FL[0] = eax; FL[1] = (u32)(3);  // @35_5ab580
  if (FL[0] > FL[1]) goto L5ab6e5;  // @36_5ab580
  switch (eax) {  // @37_5ab580
  case 0: goto L5ab600;  // @38_5ab580
  case 1: goto L5ab622;  // @39_5ab580
  case 2: goto L5ab60c;  // @40_5ab580
  case 3: goto L5ab634;  // @41_5ab580
  default: __builtin_trap(); }  // @42_5ab580
  L5ab600:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @44_5ab580
  goto L5ab6e5;  // @45_5ab580
  L5ab60c:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @47_5ab580
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @48_5ab580
  X1[1] = 0;  // @49_5ab580
  X1[2] = 0;  // @50_5ab580
  X1[3] = 0;  // @51_5ab580
  X0[0] = F2U((float)(s32)X0[0]);  // @52_5ab580
  X0[1] = F2U((float)(s32)X0[1]);  // @53_5ab580
  X0[2] = F2U((float)(s32)X0[2]);  // @54_5ab580
  X0[3] = F2U((float)(s32)X0[3]);  // @55_5ab580
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @56_5ab580
  goto L5ab6db;  // @57_5ab580
  L5ab622:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @59_5ab580
  X0[0] = F2U((float)(s32)X0[0]);  // @60_5ab580
  X0[1] = F2U((float)(s32)X0[1]);  // @61_5ab580
  X0[2] = F2U((float)(s32)X0[2]);  // @62_5ab580
  X0[3] = F2U((float)(s32)X0[3]);  // @63_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @64_5ab580
  goto L5ab6e5;  // @65_5ab580
  L5ab634:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 110), sizeof v); (u32)v; });  // @67_5ab580
  ebx = 0;  // @68_5ab580
  FL[3] = ebx;  // @69_5ab580
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 114), sizeof v); (u32)v; });  // @70_5ab580
  if (FL[0] == FL[1]) goto L5ab6a8;  // @71_5ab580
  L5ab640:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @73_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_5ab580
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 552)))(ecx);  // @75_5ab580
  ecx = edx = 0;  // @76_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @77_5ab580
  eax = (u32)(EBP - 28);  // @78_5ab580
  PV[0] = (u32)(eax);  // @79_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @80_5ab580
  eax = ext_4db7c0_thiscall2(ecx, PV[0]);  // @81_5ab580
  edx = 0;  // @82_5ab580
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @83_5ab580
  X0[1] = 0;  // @84_5ab580
  X0[2] = 0;  // @85_5ab580
  X0[3] = 0;  // @86_5ab580
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })));  // @87_5ab580
  X1[0] = ebx; X1[1] = X1[2] = X1[3] = 0;  // @88_5ab580
  { double a_ = (double)(s32)X1[0], b_ = (double)(s32)X1[1]; SD(&X1[0], a_); SD(&X1[2], b_); }  // @89_5ab580
  ebx = (ebx >> (u32)(31));  // @90_5ab580
  FL[3] = ebx;  // @91_5ab580
  SD(&X1[0], U2D(X1[0], X1[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 4), 4); v; })));  // @92_5ab580
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @93_5ab580
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @94_5ab580
  eax = (u32)ext_633910(U2F(X0[0]));  // @95_5ab580
  ecx = edx = 0;  // @96_5ab580
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @97_5ab580
  ebx = eax;  // @98_5ab580
  if (FL[0] == FL[1]) goto L5ab698;  // @99_5ab580
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @100_5ab580
  if (FL[0] == FL[1]) goto L5ab698;  // @101_5ab580
  ebx = (ebx + (u32)(32));  // @102_5ab580
  FL[3] = ebx;  // @103_5ab580
  L5ab698:;
  edi = (edi + (u32)(16));  // @105_5ab580
  FL[3] = edi;  // @106_5ab580
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 114), sizeof v); (u32)v; });  // @107_5ab580
  if (FL[0] != FL[1]) goto L5ab640;  // @108_5ab580
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @109_5ab580
  X2[1] = 0;  // @110_5ab580
  X2[2] = 0;  // @111_5ab580
  X2[3] = 0;  // @112_5ab580
  L5ab6a8:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @114_5ab580
  X1[1] = 0;  // @115_5ab580
  X1[2] = 0;  // @116_5ab580
  X1[3] = 0;  // @117_5ab580
  ebx = (ebx >> (u32)(1));  // @118_5ab580
  FL[3] = ebx;  // @119_5ab580
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @120_5ab580
  X0[0] = ebx; X0[1] = X0[2] = X0[3] = 0;  // @121_5ab580
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @122_5ab580
  ebx = (ebx >> (u32)(31));  // @123_5ab580
  FL[3] = ebx;  // @124_5ab580
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 4), 4); v; })));  // @125_5ab580
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @126_5ab580
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @127_5ab580
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @128_5ab580
  X0[0] = F2U((float)(s32)X0[0]);  // @129_5ab580
  X0[1] = F2U((float)(s32)X0[1]);  // @130_5ab580
  X0[2] = F2U((float)(s32)X0[2]);  // @131_5ab580
  X0[3] = F2U((float)(s32)X0[3]);  // @132_5ab580
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @133_5ab580
  L5ab6db:;
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X1[0], 4);  // @135_5ab580
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @136_5ab580
  X1[1] = 0;  // @137_5ab580
  X1[2] = 0;  // @138_5ab580
  X1[3] = 0;  // @139_5ab580
  L5ab6e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @141_5ab580
  FL[0] = eax; FL[1] = (u32)(3);  // @142_5ab580
  if (FL[0] > FL[1]) goto L5ab72f;  // @143_5ab580
  switch (eax) {  // @144_5ab580
  case 0: goto L5ab6f4;  // @145_5ab580
  case 1: goto L5ab6fd;  // @146_5ab580
  case 2: goto L5ab707;  // @147_5ab580
  case 3: goto L5ab71a;  // @148_5ab580
  default: __builtin_trap(); }  // @149_5ab580
  L5ab6f4:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @151_5ab580
  goto L5ab72f;  // @152_5ab580
  L5ab6fd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @154_5ab580
  X0[0] = F2U((float)(s32)X0[0]);  // @155_5ab580
  X0[1] = F2U((float)(s32)X0[1]);  // @156_5ab580
  X0[2] = F2U((float)(s32)X0[2]);  // @157_5ab580
  X0[3] = F2U((float)(s32)X0[3]);  // @158_5ab580
  goto L5ab72a;  // @159_5ab580
  L5ab707:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @161_5ab580
  X0[0] = F2U((float)(s32)X0[0]);  // @162_5ab580
  X0[1] = F2U((float)(s32)X0[1]);  // @163_5ab580
  X0[2] = F2U((float)(s32)X0[2]);  // @164_5ab580
  X0[3] = F2U((float)(s32)X0[3]);  // @165_5ab580
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @166_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @167_5ab580
  goto L5ab72f;  // @168_5ab580
  L5ab71a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @170_5ab580
  X0[0] = F2U((float)(s32)X0[0]);  // @171_5ab580
  X0[1] = F2U((float)(s32)X0[1]);  // @172_5ab580
  X0[2] = F2U((float)(s32)X0[2]);  // @173_5ab580
  X0[3] = F2U((float)(s32)X0[3]);  // @174_5ab580
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @175_5ab580
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @176_5ab580
  L5ab72a:;
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @178_5ab580
  L5ab72f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 110), sizeof v); (u32)v; });  // @180_5ab580
  eax = 0;  // @181_5ab580
  FL[3] = eax;  // @182_5ab580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @183_5ab580
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 114), sizeof v); (u32)v; });  // @184_5ab580
  if (FL[0] == FL[1]) goto L5ab8e7;  // @185_5ab580
  L5ab740:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 122) + 0), 4); v; });  // @187_5ab580
  X0[1] = 0;  // @188_5ab580
  X0[2] = 0;  // @189_5ab580
  X0[3] = 0;  // @190_5ab580
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; })));  // @191_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @192_5ab580
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @193_5ab580
  ecx = ebx;  // @194_5ab580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @195_5ab580
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @196_5ab580
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @197_5ab580
  PV[1] = (u32)(eax);  // @198_5ab580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 592)))(ecx, PV[1]);  // @199_5ab580
  ecx = edx = 0;  // @200_5ab580
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 131), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @201_5ab580
  if (FL[0] == FL[1]) goto L5ab778;  // @202_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @203_5ab580
  ecx = ebx;  // @204_5ab580
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 552)))(ecx);  // @205_5ab580
  ecx = edx = 0;  // @206_5ab580
  L5ab778:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @208_5ab580
  ecx = (u32)(EBP - 16);  // @209_5ab580
  PV[2] = (u32)(ecx);  // @210_5ab580
  ecx = (u32)(esi + 132);  // @211_5ab580
  PV[3] = (u32)(ecx);  // @212_5ab580
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @213_5ab580
  ecx = ebx;  // @214_5ab580
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @215_5ab580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 548)))(ecx, PV[5], PV[4], PV[3], PV[2], (u32)(2));  // @216_5ab580
  ecx = edx = 0;  // @217_5ab580
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @218_5ab580
  if (FL[0] == FL[1]) goto L5ab80c;  // @219_5ab580
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 122) + 0), 4); v; });  // @220_5ab580
  X0[1] = 0;  // @221_5ab580
  X0[2] = 0;  // @222_5ab580
  X0[3] = 0;  // @223_5ab580
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; })));  // @224_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @225_5ab580
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @226_5ab580
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @227_5ab580
  PV[6] = (u32)(eax);  // @228_5ab580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 592)))(ecx, PV[6]);  // @229_5ab580
  ecx = edx = 0;  // @230_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @231_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @232_5ab580
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 552)))(ecx);  // @233_5ab580
  ecx = edx = 0;  // @234_5ab580
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @235_5ab580
  X0[1] = 0;  // @236_5ab580
  X0[2] = 0;  // @237_5ab580
  X0[3] = 0;  // @238_5ab580
  edx = (u32)(EBP - 28);  // @239_5ab580
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })));  // @240_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @241_5ab580
  PV[7] = (u32)(edx);  // @242_5ab580
  edx = (u32)(esi + 132);  // @243_5ab580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @244_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @245_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @246_5ab580
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @247_5ab580
  X0[1] = 0;  // @248_5ab580
  X0[2] = 0;  // @249_5ab580
  X0[3] = 0;  // @250_5ab580
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })));  // @251_5ab580
  PV[8] = (u32)(edx);  // @252_5ab580
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @253_5ab580
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @254_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @255_5ab580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 548)))(ecx, PV[10], PV[9], PV[8], PV[7], (u32)(1));  // @256_5ab580
  ecx = edx = 0;  // @257_5ab580
  L5ab80c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @259_5ab580
  eax = (u32)(EBP - 40);  // @260_5ab580
  PV[11] = (u32)(eax);  // @261_5ab580
  eax = ext_4db7c0_thiscall2(ecx, PV[11]);  // @262_5ab580
  edx = 0;  // @263_5ab580
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @264_5ab580
  X0[1] = 0;  // @265_5ab580
  X0[2] = 0;  // @266_5ab580
  X0[3] = 0;  // @267_5ab580
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })));  // @268_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @269_5ab580
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @270_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @271_5ab580
  FL[2] = (ecx & ecx);  // @272_5ab580
  if (FL[2] == 0) goto L5ab8d8;  // @273_5ab580
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @274_5ab580
  if (FL[0] == FL[1]) goto L5ab8d8;  // @275_5ab580
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @276_5ab580
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 122) + 0), 4); v; });  // @277_5ab580
  X0[1] = 0;  // @278_5ab580
  X0[2] = 0;  // @279_5ab580
  X0[3] = 0;  // @280_5ab580
  PV[12] = (u32)(ebx);  // @281_5ab580
  PV[13] = (u32)(ecx);  // @282_5ab580
  PV[14] = X0[0];  // @283_5ab580
  eax = ext_5ec2b0_thiscall3(ecx, PV[14], PV[12]);  // @284_5ab580
  ecx = edx = 0;  // @285_5ab580
  PV[15] = (u32)(ebx);  // @286_5ab580
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @287_5ab580
  ecx = esi;  // @288_5ab580
  eax = ext_5ac660_thiscall3(ecx, PV[16], PV[15]);  // @289_5ab580
  ecx = edx = 0;  // @290_5ab580
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @291_5ab580
  X1[1] = 0;  // @292_5ab580
  X1[2] = 0;  // @293_5ab580
  X1[3] = 0;  // @294_5ab580
  ebx = 0;  // @295_5ab580
  FL[3] = ebx;  // @296_5ab580
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(35);  // @297_5ab580
  if (FL[0] != FL[1]) goto L5ab87f;  // @298_5ab580
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @299_5ab580
  ebx = (u32)(10);  // @300_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X1[0], 4);  // @301_5ab580
  L5ab87f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @303_5ab580
  X0[1] = 0;  // @304_5ab580
  X0[2] = 0;  // @305_5ab580
  X0[3] = 0;  // @306_5ab580
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @307_5ab580
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @308_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @309_5ab580
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @310_5ab580
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @311_5ab580
  PV[18] = (u32)(eax);  // @312_5ab580
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @313_5ab580
  PV[19] = (u32)(eax);  // @314_5ab580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 28)))(ecx, PV[19], PV[18], PV[17]);  // @315_5ab580
  ecx = edx = 0;  // @316_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @317_5ab580
  eax = ext_5ebde0_thiscall2(ecx, (u32)(0));  // @318_5ab580
  ecx = 0;  // @319_5ab580
  eax = (eax + ebx);  // @320_5ab580
  FL[3] = eax;  // @321_5ab580
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @322_5ab580
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @323_5ab580
  eax = (eax >> (u32)(31));  // @324_5ab580
  FL[3] = eax;  // @325_5ab580
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @326_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @327_5ab580
  eax = (eax + 1);  // @328_5ab580
  FL[3] = eax;  // @329_5ab580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @330_5ab580
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @331_5ab580
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @332_5ab580
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @333_5ab580
  goto L5ab8db;  // @334_5ab580
  L5ab8d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @336_5ab580
  L5ab8db:;
  edi = (edi + (u32)(16));  // @338_5ab580
  FL[3] = edi;  // @339_5ab580
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 114), sizeof v); (u32)v; });  // @340_5ab580
  if (FL[0] != FL[1]) goto L5ab740;  // @341_5ab580
  L5ab8e7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @343_5ab580
  FL[2] = (ecx & ecx);  // @344_5ab580
  if (FL[2] == 0) goto L5ab90a;  // @345_5ab580
  PV[20] = (u32)(eax);  // @346_5ab580
  eax = ext_5ec5a0_thiscall2(ecx, PV[20]);  // @347_5ab580
  edx = 0;  // @348_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @349_5ab580
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @350_5ab580
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @351_5ab580
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @352_5ab580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @353_5ab580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @354_5ab580
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[22], PV[21]);  // @355_5ab580
  ecx = edx = 0;  // @356_5ab580
  L5ab90a:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 131), &v, sizeof v); }  // @358_5ab580
  L5ab911:;
  ext_633654(G(u32, 0x6f5630));  // @360_5ab580
  return eax;  // @361_5ab580
}
PCREG(5ab580, lifted_5ab580);

extern "C" u32 THISCALL lifted_5ec8b0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
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
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @0_5ec8b0
  X2[1] = 0;  // @1_5ec8b0
  X2[2] = 0;  // @2_5ec8b0
  X2[3] = 0;  // @3_5ec8b0
  ebx = ecx;  // @4_5ec8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 98), sizeof v); (u32)v; });  // @6_5ec8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @7_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 203), sizeof v); (u32)v; });  // @8_5ec8b0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 12) + 0), 4); v; });  // @9_5ec8b0
  X4[1] = 0;  // @10_5ec8b0
  X4[2] = 0;  // @11_5ec8b0
  X4[3] = 0;  // @12_5ec8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @13_5ec8b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @14_5ec8b0
  edi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @15_5ec8b0
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @16_5ec8b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 8) + 0), 4); v; });  // @17_5ec8b0
  X3[1] = 0;  // @18_5ec8b0
  X3[2] = 0;  // @19_5ec8b0
  X3[3] = 0;  // @20_5ec8b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @21_5ec8b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 6), sizeof v); (u32)v; });  // @22_5ec8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @23_5ec8b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @24_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; }));  // @25_5ec8b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @26_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @27_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X4[0], 4);  // @28_5ec8b0
  FL[0] = eax; FL[1] = (u32)(3);  // @29_5ec8b0
  if (FL[0] > FL[1]) goto L5ecaad;  // @30_5ec8b0
  switch (eax) {  // @31_5ec8b0
  case 0: goto L5ec916;  // @32_5ec8b0
  case 1: goto L5ec96d;  // @33_5ec8b0
  case 2: goto L5ec9c5;  // @34_5ec8b0
  case 3: goto L5eca45;  // @35_5ec8b0
  default: __builtin_trap(); }  // @36_5ec8b0
  L5ec916:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; });  // @38_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @39_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @40_5ec8b0
  eax = (eax >> (u32)(31));  // @41_5ec8b0
  FL[3] = eax;  // @42_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @43_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }));  // @44_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @45_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @46_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @47_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @48_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @49_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @50_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @51_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @52_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @53_5ec8b0
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @54_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @55_5ec8b0
  edi = (edi >> (u32)(31));  // @56_5ec8b0
  FL[3] = edi;  // @57_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @58_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @59_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @60_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @61_5ec8b0
  goto L5ecab7;  // @62_5ec8b0
  L5ec96d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; });  // @64_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @65_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @66_5ec8b0
  eax = (eax >> (u32)(31));  // @67_5ec8b0
  FL[3] = eax;  // @68_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @69_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }));  // @70_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @71_5ec8b0
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @72_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @73_5ec8b0
  edi = (edi >> (u32)(31));  // @74_5ec8b0
  FL[3] = edi;  // @75_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @76_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @77_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @78_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @79_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @80_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @81_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @82_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @83_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @84_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @85_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @86_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @87_5ec8b0
  goto L5ecab7;  // @88_5ec8b0
  L5ec9c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; });  // @90_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @91_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @92_5ec8b0
  eax = (eax >> (u32)(31));  // @93_5ec8b0
  FL[3] = eax;  // @94_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @95_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @96_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @97_5ec8b0
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @98_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @99_5ec8b0
  edi = (edi >> (u32)(31));  // @100_5ec8b0
  FL[3] = edi;  // @101_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @102_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @103_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @104_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @105_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 195) + 0), 4); v; })));  // @106_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @107_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @108_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @109_5ec8b0
  eax = (eax >> (u32)(31));  // @110_5ec8b0
  FL[3] = eax;  // @111_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @112_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }));  // @113_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @114_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @115_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @116_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @117_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @118_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @119_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @120_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @121_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @122_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @123_5ec8b0
  goto L5ecab7;  // @124_5ec8b0
  L5eca45:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 195) + 0), 4); v; });  // @126_5ec8b0
  X1[1] = 0;  // @127_5ec8b0
  X1[2] = 0;  // @128_5ec8b0
  X1[3] = 0;  // @129_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }));  // @130_5ec8b0
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @131_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @132_5ec8b0
  edi = (edi >> (u32)(31));  // @133_5ec8b0
  FL[3] = edi;  // @134_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @135_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @136_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @137_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @138_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @139_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; });  // @140_5ec8b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @141_5ec8b0
  FL[3] = eax;  // @142_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @143_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @144_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @145_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @146_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @147_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @148_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @149_5ec8b0
  eax = (eax >> (u32)(31));  // @150_5ec8b0
  FL[3] = eax;  // @151_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @152_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @153_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @154_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @155_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @156_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @157_5ec8b0
  goto L5ecab7;  // @158_5ec8b0
  L5ecaad:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @160_5ec8b0
  X0[1] = 0;  // @161_5ec8b0
  X0[2] = 0;  // @162_5ec8b0
  X0[3] = 0;  // @163_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @164_5ec8b0
  L5ecab7:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @166_5ec8b0
  FL[0] = edx; FL[1] = (u32)(3);  // @167_5ec8b0
  if (FL[0] > FL[1]) goto L5ecc7a;  // @168_5ec8b0
  switch (edx) {  // @169_5ec8b0
  case 0: goto L5ecaca;  // @170_5ec8b0
  case 1: goto L5ecb22;  // @171_5ec8b0
  case 2: goto L5ecb77;  // @172_5ec8b0
  case 3: goto L5ecbf7;  // @173_5ec8b0
  default: __builtin_trap(); }  // @174_5ec8b0
  L5ecaca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @176_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @177_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @178_5ec8b0
  eax = (eax >> (u32)(31));  // @179_5ec8b0
  FL[3] = eax;  // @180_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @181_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; }));  // @182_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @183_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @184_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @185_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @186_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @187_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @188_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @189_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @190_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @191_5ec8b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @192_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @193_5ec8b0
  esi = (esi >> (u32)(31));  // @194_5ec8b0
  FL[3] = esi;  // @195_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @196_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @197_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @198_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X1[0], 4);  // @199_5ec8b0
  goto L5ecc84;  // @200_5ec8b0
  L5ecb22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @202_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @203_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @204_5ec8b0
  eax = (eax >> (u32)(31));  // @205_5ec8b0
  FL[3] = eax;  // @206_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @207_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @208_5ec8b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @209_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @210_5ec8b0
  esi = (esi >> (u32)(31));  // @211_5ec8b0
  FL[3] = esi;  // @212_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @213_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @214_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @215_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @216_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @217_5ec8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @218_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @219_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @220_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @221_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @222_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @223_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X1[0], 4);  // @224_5ec8b0
  goto L5ecc84;  // @225_5ec8b0
  L5ecb77:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @227_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @228_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @229_5ec8b0
  eax = (eax >> (u32)(31));  // @230_5ec8b0
  FL[3] = eax;  // @231_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @232_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @233_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @234_5ec8b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @235_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @236_5ec8b0
  esi = (esi >> (u32)(31));  // @237_5ec8b0
  FL[3] = esi;  // @238_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @239_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @240_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @241_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @242_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 199) + 0), 4); v; })));  // @243_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @244_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @245_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @246_5ec8b0
  eax = (eax >> (u32)(31));  // @247_5ec8b0
  FL[3] = eax;  // @248_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @249_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @250_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @251_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @252_5ec8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @253_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @254_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @255_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @256_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @257_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @258_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X1[0], 4);  // @259_5ec8b0
  goto L5ecc84;  // @260_5ec8b0
  L5ecbf7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @262_5ec8b0
  ecx = edi;  // @263_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @264_5ec8b0
  FS[0] = ((long double(THISCALL *)(u32))(eax))(ecx);  // @265_5ec8b0
  ecx = edx = 0;  // @266_5ec8b0
  FS[1] = 1.0L;  // @267_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @268_5ec8b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @269_5ec8b0
  FL[3] = eax;  // @270_5ec8b0
  FS[0] = (FS[1] / FS[0]);  // @271_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @272_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @273_5ec8b0
  eax = (eax >> (u32)(31));  // @274_5ec8b0
  FL[3] = eax;  // @275_5ec8b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @276_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @277_5ec8b0
  X1[0] = F2U((float)(s32)X1[0]);  // @278_5ec8b0
  X1[1] = F2U((float)(s32)X1[1]);  // @279_5ec8b0
  X1[2] = F2U((float)(s32)X1[2]);  // @280_5ec8b0
  X1[3] = F2U((float)(s32)X1[3]);  // @281_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @282_5ec8b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @283_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @284_5ec8b0
  esi = (esi >> (u32)(31));  // @285_5ec8b0
  FL[3] = esi;  // @286_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @287_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @288_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @289_5ec8b0
  STF((u32)(EBP + 8), FS[0]);  // @290_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @291_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @292_5ec8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 199) + 0), 4); v; });  // @293_5ec8b0
  X0[1] = 0;  // @294_5ec8b0
  X0[2] = 0;  // @295_5ec8b0
  X0[3] = 0;  // @296_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @297_5ec8b0
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @298_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })));  // @299_5ec8b0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @300_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X2[0], 4);  // @301_5ec8b0
  goto L5ecc84;  // @302_5ec8b0
  L5ecc7a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @304_5ec8b0
  X0[1] = 0;  // @305_5ec8b0
  X0[2] = 0;  // @306_5ec8b0
  X0[3] = 0;  // @307_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @308_5ec8b0
  L5ecc84:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @310_5ec8b0
  ecx = edi;  // @311_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @312_5ec8b0
  FS[0] = ((long double(THISCALL *)(u32))(eax))(ecx);  // @313_5ec8b0
  ecx = edx = 0;  // @314_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @315_5ec8b0
  ecx = edi;  // @316_5ec8b0
  STF((u32)(EBP - 16), FS[0]);  // @317_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @318_5ec8b0
  FS[0] = ((long double(THISCALL *)(u32))(eax))(ecx);  // @319_5ec8b0
  ecx = edx = 0;  // @320_5ec8b0
  FS[1] = 1.0L;  // @321_5ec8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @322_5ec8b0
  X0[1] = 0;  // @323_5ec8b0
  X0[2] = 0;  // @324_5ec8b0
  X0[3] = 0;  // @325_5ec8b0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @326_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @327_5ec8b0
  ecx = (u32)(eax + eax*4);  // @328_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 58), sizeof v); (u32)v; });  // @329_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @330_5ec8b0
  FS[0] = (FS[1] / FS[0]);  // @331_5ec8b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @332_5ec8b0
  X2[1] = 0;  // @333_5ec8b0
  X2[2] = 0;  // @334_5ec8b0
  X2[3] = 0;  // @335_5ec8b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @336_5ec8b0
  X1[1] = 0;  // @337_5ec8b0
  X1[2] = 0;  // @338_5ec8b0
  X1[3] = 0;  // @339_5ec8b0
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @340_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @341_5ec8b0
  STF((u32)(EBP - 12), FS[0]);  // @342_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 179) + 0), 4); v; })));  // @343_5ec8b0
  X0[0] = X1[0];  // @344_5ec8b0
  X0[1] = X1[1];  // @345_5ec8b0
  X0[2] = X1[2];  // @346_5ec8b0
  X0[3] = X1[3];  // @347_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @348_5ec8b0
  __builtin_memcpy((void *)((u32)(eax + ecx*8) + 0), &X2[0], 4);  // @349_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 183) + 0), 4); v; })));  // @350_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 58), sizeof v); (u32)v; });  // @351_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @352_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @353_5ec8b0
  __builtin_memcpy((void *)((u32)(eax + ecx*8 + 4) + 0), &X0[0], 4);  // @354_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 58), sizeof v); (u32)v; });  // @355_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 183) + 0), 4); v; })));  // @356_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @357_5ec8b0
  __builtin_memcpy((void *)((u32)(eax + ecx*8 + 4) + 0), &X1[0], 4);  // @358_5ec8b0
  return eax;  // @359_5ec8b0
}
PCREG(5ec8b0, lifted_5ec8b0);

extern "C" u32 THISCALL lifted_612c00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e338);  // @h_612c00
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_612c00
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_612c00
  ecx = (u32)(EBP - 64);  // @2_612c00
  eax = ext_6361e0_thiscall1(ecx);  // @3_612c00
    // @4_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_612c00
  ecx = ebx;  // @6_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139296), sizeof v); (u32)v; });  // @7_612c00
  reg.state = (s32)((u32)(0));  // @8_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @9_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @10_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @11_612c00
  ecx = edx = 0;  // @12_612c00
  FL[0] = eax; FL[1] = (u32)(1146639409);  // @13_612c00
  if (FL[0] != FL[1]) goto L612c65;  // @14_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139304), sizeof v); (u32)v; });  // @15_612c00
  goto L612c79;  // @16_612c00
  L612c65:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @18_612c00
  ecx = ebx;  // @19_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @20_612c00
  ecx = edx = 0;  // @21_612c00
  FL[0] = eax; FL[1] = (u32)(1146639411);  // @22_612c00
  if (FL[0] != FL[1]) goto L612c83;  // @23_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139308), sizeof v); (u32)v; });  // @24_612c00
  L612c79:;
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @26_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @27_612c00
  L612c83:;
  FL[2] = (edi & edi);  // @29_612c00
  if (FL[2] != 0) goto L612c97;  // @30_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139296), sizeof v); (u32)v; });  // @31_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @32_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @33_612c00
  L612c97:;
  FL[0] = edi; FL[1] = (u32)(25);  // @35_612c00
  if (FL[0] == FL[1]) goto L612ca1;  // @36_612c00
  FL[0] = edi; FL[1] = (u32)(26);  // @37_612c00
  if (FL[0] != FL[1]) goto L612ca8;  // @38_612c00
  L612ca1:;
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @40_612c00
  L612ca8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_612c00
  ecx = ebx;  // @43_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @44_612c00
  ecx = edx = 0;  // @45_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @47_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @48_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 147), sizeof v); (u32)v; });  // @49_612c00
  ecx = (u32)(eax - 1);  // @50_612c00
  FL[0] = ecx; FL[1] = edi;  // @51_612c00
  if (FL[0] < FL[1]) edi = ecx;  // @52_612c00
  ecx = ebx;  // @53_612c00
  PV[0] = (u32)(edi);  // @54_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 56)))(ecx, PV[0]);  // @55_612c00
  ecx = edx = 0;  // @56_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @57_612c00
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139316), sizeof v); (u32)v; });  // @58_612c00
  if (FL[0] > FL[1]) goto L612ce4;  // @59_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @60_612c00
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139320), sizeof v); (u32)v; });  // @61_612c00
  if (FL[0] <= FL[1]) goto L612d24;  // @62_612c00
  L612ce4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @64_612c00
  if (FL[0] != FL[1]) goto L612d03;  // @65_612c00
  PV[1] = (u32)(ebx);  // @66_612c00
  ecx = (u32)(EBP - 64);  // @67_612c00
  eax = ext_637a30_thiscall3(ecx, PV[1], (u32)(1));  // @68_612c00
  ecx = edx = 0;  // @69_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @70_612c00
  ebx = (u32)(EBP - 64);  // @71_612c00
  ecx = ebx;  // @72_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @73_612c00
  ecx = edx = 0;  // @74_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @75_612c00
  L612d03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @77_612c00
  ecx = ebx;  // @78_612c00
  PV[2] = (u32)(edi);  // @79_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, PV[2]);  // @80_612c00
  ecx = edx = 0;  // @81_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @82_612c00
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139316), sizeof v); (u32)v; });  // @83_612c00
  if (FL[0] > FL[1]) goto L612d21;  // @84_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @85_612c00
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139320), sizeof v); (u32)v; });  // @86_612c00
  if (FL[0] <= FL[1]) goto L612d24;  // @87_612c00
  L612d21:;
  edi = (edi + 1);  // @89_612c00
  FL[3] = edi;  // @90_612c00
  goto L612d03;  // @91_612c00
  L612d24:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @93_612c00
  ecx = ebx;  // @94_612c00
  PV[3] = (u32)(edi);  // @95_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, PV[3]);  // @96_612c00
  ecx = edx = 0;  // @97_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139268), sizeof v); (u32)v; });  // @98_612c00
  ecx = (u32)(EBP - 84);  // @99_612c00
  PV[4] = (u32)(ecx);  // @100_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @101_612c00
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @102_612c00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @103_612c00
  ecx = (ecx - edi);  // @104_612c00
  FL[3] = ecx;  // @105_612c00
  PV[6] = (u32)(ecx);  // @106_612c00
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @107_612c00
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @108_612c00
  PV[9] = (u32)(edx);  // @109_612c00
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 80)))(PV[9], PV[8], PV[7], PV[6], (u32)(0), PV[5], (u32)(1), PV[4]);  // @110_612c00
  ecx = edx = 0;  // @111_612c00
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @112_612c00
  if (FL[0] != FL[1]) goto L612d7a;  // @113_612c00
  { u32 v = (u32)((u32)(4278190080)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @114_612c00
  { u32 v = (u32)((u32)(16711680)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @115_612c00
  { u32 v = (u32)((u32)(65280)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @116_612c00
  { u32 v = (u32)((u32)(255)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @117_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @118_612c00
  goto L612dc1;  // @119_612c00
  L612d7a:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }); FL[1] = (u32)(25);  // @121_612c00
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @122_612c00
  if (FL[0] != FL[1]) goto L612da5;  // @123_612c00
  { u32 v = (u32)((u32)(32768)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @124_612c00
  { u32 v = (u32)((u32)(31744)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @125_612c00
  { u32 v = (u32)((u32)(992)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @126_612c00
  { u32 v = (u32)((u32)(31)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @127_612c00
  goto L612dc1;  // @128_612c00
  L612da5:;
  { u32 v = (u32)((u32)(61440)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @130_612c00
  { u32 v = (u32)((u32)(3840)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @131_612c00
  { u32 v = (u32)((u32)(240)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @132_612c00
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @133_612c00
  L612dc1:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @135_612c00
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @136_612c00
  if (FL[0] >= FL[1]) goto L612e3e;  // @137_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @138_612c00
  L612dd1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @140_612c00
  ecx = ebx;  // @141_612c00
  PV[10] = (u32)(edi);  // @142_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, PV[10]);  // @143_612c00
  ecx = edx = 0;  // @144_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @145_612c00
  esi = eax;  // @146_612c00
  eax = (u32)(EBP - 80);  // @147_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_612c00
  PV[11] = (u32)(eax);  // @149_612c00
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @150_612c00
  PV[13] = (u32)(ecx);  // @151_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[13], PV[12], PV[11], (u32)(0), (u32)(0));  // @152_612c00
  ecx = edx = 0;  // @153_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @154_612c00
  ecx = (u32)(EBP - 132);  // @155_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @156_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @157_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @158_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @159_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @160_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @161_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @162_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @163_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @164_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @165_612c00
  PV[14] = (u32)(edi);  // @166_612c00
  PV[15] = (u32)(ecx);  // @167_612c00
  ecx = ebx;  // @168_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[15], PV[14]);  // @169_612c00
  ecx = edx = 0;  // @170_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @171_612c00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @172_612c00
  PV[16] = (u32)(esi);  // @173_612c00
  PV[17] = (u32)(eax);  // @174_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @175_612c00
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)(ecx + 68)))(PV[17], PV[16]);  // @176_612c00
  ecx = edx = 0;  // @177_612c00
  edi = (edi + 1);  // @178_612c00
  FL[3] = edi;  // @179_612c00
  esi = (esi + 1);  // @180_612c00
  FL[3] = esi;  // @181_612c00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @182_612c00
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @183_612c00
  if (FL[0] < FL[1]) goto L612dd1;  // @184_612c00
  L612e3e:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @186_612c00
  ecx = (u32)(EBP - 64);  // @187_612c00
  eax = ext_6363a0_thiscall1(ecx);  // @188_612c00
  ecx = edx = 0;  // @189_612c00
  eax = esi;  // @190_612c00
  SEH_LEAVE();  // @191_612c00
  ext_633654(G(u32, 0x6f5630));  // @192_612c00
  return eax;  // @193_612c00
}
PCREG(612c00, lifted_612c00);

extern "C" u32 THISCALL lifted_532420(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_532420
  eax = (eax & 0xffff);  // @1_532420
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @2_532420
  edi = ecx;  // @3_532420
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; }));  // @4_532420
  FL[3] = eax;  // @5_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_532420
  ecx = (u32)(eax + eax*2);  // @8_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 90), sizeof v); (u32)v; });  // @9_532420
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @10_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @11_532420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 120), sizeof v); (u32)v; });  // @12_532420
  esi = (u32)(edx + edx*4);  // @13_532420
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax), sizeof v); (u32)v; })) & 0xff);  // @14_532420
  ebx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi*2 + 8), sizeof v); (u32)v; });  // @15_532420
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @16_532420
  if (FL[2] == 0) goto L53270e;  // @17_532420
  eax = (edx & 0xff);  // @18_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @19_532420
  eax = ebx;  // @20_532420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @21_532420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @22_532420
  ecx = (u32)(eax + eax*4);  // @23_532420
  ecx = (ecx + ecx);  // @24_532420
  FL[3] = ecx;  // @25_532420
  eax = 0;  // @26_532420
  FL[3] = eax;  // @27_532420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @28_532420
  L532480:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; });  // @30_532420
  ebx = (ebx + ecx);  // @31_532420
  FL[3] = ebx;  // @32_532420
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @33_532420
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @34_532420
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @35_532420
  if (FL[2] == 0) goto L5326f9;  // @36_532420
  edx = 0;  // @37_532420
  FL[3] = edx;  // @38_532420
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @39_532420
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @40_532420
  eax = ecx;  // @41_532420
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @42_532420
  if ((s16)FL[2] >= 0) goto L5324ba;  // @43_532420
  FL[1] = eax;  // @44_532420
  eax = (0u - eax);  // @45_532420
  edx = (u32)(1);  // @46_532420
  esi = 0;  // @47_532420
  FL[3] = esi;  // @48_532420
  eax = (eax & 0xffff);  // @49_532420
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @50_532420
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @51_532420
  L5324ba:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @53_532420
  edx = (u32)(edx + edx*2);  // @54_532420
  eax = (eax & 0xffff);  // @55_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @56_532420
  ecx = (u32)(eax + eax*2);  // @57_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 136), sizeof v); (u32)v; });  // @58_532420
  ecx = (u32)(eax + ecx*4);  // @59_532420
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xffff);  // @60_532420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @61_532420
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2), sizeof v); (u32)v; });  // @62_532420
  if (FL[0] != FL[1]) goto L5326f3;  // @63_532420
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; })) & 0xffff);  // @64_532420
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 2), sizeof v); (u32)v; });  // @65_532420
  if (FL[0] != FL[1]) goto L5326f3;  // @66_532420
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) & 0xffff);  // @67_532420
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 4), sizeof v); (u32)v; });  // @68_532420
  if (FL[0] != FL[1]) goto L5326f3;  // @69_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @70_532420
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 56), sizeof v); (u32)v; });  // @71_532420
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @72_532420
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @73_532420
  edx = (u32)(eax + eax*2);  // @74_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2), sizeof v); (u32)v; });  // @75_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @76_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 2), sizeof v); (u32)v; });  // @77_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 50), &v, sizeof v); }  // @78_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 4), sizeof v); (u32)v; });  // @79_532420
  ecx = (u32)(EBP - 100);  // @80_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @81_532420
  eax = (u32)(edi + 150);  // @82_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @83_532420
  eax = (u32)(EBP - 52);  // @84_532420
  PV[1] = (u32)(eax);  // @85_532420
  eax = ext_531740_thiscall3(ecx, PV[1], PV[0]);  // @86_532420
  ecx = edx = 0;  // @87_532420
  eax = (eax & 0xffff);  // @88_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @89_532420
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @90_532420
  if (FL[2] == 0) goto L5326f3;  // @91_532420
  ecx = (u32)(EBP - 100);  // @92_532420
  eax = ext_530a40_thiscall1(ecx);  // @93_532420
  ecx = edx = 0;  // @94_532420
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; });  // @95_532420
  ecx = (ecx & 0xffff0000u) | ((((ecx & 0xffff) - 1)) & 0xffff);  // @96_532420
  FL[3] = (ecx & 0xffff);  // @97_532420
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) + (ecx & 0xffff))) & 0xffff);  // @98_532420
  FL[3] = (eax & 0xffff);  // @99_532420
  eax = (eax & 0xffff);  // @100_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @101_532420
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @102_532420
  if (FL[2] == 0) goto L53271c;  // @103_532420
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 10) + 0), 4); v; });  // @104_532420
  X2[1] = 0;  // @105_532420
  X2[2] = 0;  // @106_532420
  X2[3] = 0;  // @107_532420
  X0[0] = 0;  // @108_532420
  X0[1] = 0;  // @109_532420
  X0[2] = 0;  // @110_532420
  X0[3] = 0;  // @111_532420
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @112_532420
  eax = (eax & 0xffff);  // @113_532420
  ebx = (u32)((s32)eax * (s32)(u32)(21));  // @114_532420
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @115_532420
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; }));  // @116_532420
  FL[3] = ebx;  // @117_532420
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6866736) + 0), 4); v; })));  // @118_532420
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 10) + 0), 4); v; });  // @119_532420
  X0[1] = 0;  // @120_532420
  X0[2] = 0;  // @121_532420
  X0[3] = 0;  // @122_532420
  X1[0] = X2[0];  // @123_532420
  X1[1] = X2[1];  // @124_532420
  X1[2] = X2[2];  // @125_532420
  X1[3] = X2[3];  // @126_532420
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @127_532420
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @128_532420
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5326f3;  // @129_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @130_532420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @131_532420
  __builtin_memcpy((void *)((u32)(ebx + 10) + 0), &X2[0], 4);  // @132_532420
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; });  // @133_532420
  esi = (esi << (u32)(5));  // @134_532420
  FL[3] = esi;  // @135_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + edi + 158), &v, sizeof v); }  // @136_532420
  eax = 0;  // @137_532420
  FL[3] = eax;  // @138_532420
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + edi + 186), &v, sizeof v); }  // @139_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + edi + 160), &v, sizeof v); }  // @140_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 170), &v, sizeof v); }  // @141_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 166), &v, sizeof v); }  // @142_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 162), &v, sizeof v); }  // @143_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 182), &v, sizeof v); }  // @144_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 178), &v, sizeof v); }  // @145_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 174), &v, sizeof v); }  // @146_532420
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @147_532420
  if (FL[0] == FL[1]) goto L53269e;  // @148_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @149_532420
  ecx = (u32)(eax + edx*2);  // @150_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @151_532420
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*2), sizeof v); (u32)v; })) & 0xffff);  // @152_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + edi + 160), &v, sizeof v); }  // @153_532420
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @154_532420
  if (FL[0] == FL[1]) goto L53268a;  // @155_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 144), sizeof v); (u32)v; });  // @156_532420
  ecx = (u32)(edx + edx*2);  // @157_532420
  edx = (u32)(eax + ecx*8);  // @158_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @159_532420
  ecx = (u32)(eax + eax*2);  // @160_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @161_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 162), &v, sizeof v); }  // @162_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 4), sizeof v); (u32)v; });  // @163_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 166), &v, sizeof v); }  // @164_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 8), sizeof v); (u32)v; });  // @165_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 170), &v, sizeof v); }  // @166_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @167_532420
  ecx = (u32)(eax + eax*2);  // @168_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @169_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 174), &v, sizeof v); }  // @170_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 4), sizeof v); (u32)v; });  // @171_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 178), &v, sizeof v); }  // @172_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 8), sizeof v); (u32)v; });  // @173_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 182), &v, sizeof v); }  // @174_532420
  L53268a:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi + 160), sizeof v); (u32)v; });  // @176_532420
  ecx = edi;  // @177_532420
  PV[2] = (u32)(eax);  // @178_532420
  eax = ext_532730_stdcall1(PV[2]);  // @179_532420
  ecx = 0;  // @180_532420
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @181_532420
  if (FL[2] == 0) goto L5326f3;  // @182_532420
  L53269e:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; });  // @184_532420
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(ebx + 20), &v, sizeof v); }  // @185_532420
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @186_532420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @187_532420
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @188_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 14), &v, sizeof v); }  // @189_532420
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 156), &v, sizeof v); }  // @190_532420
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; });  // @191_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @192_532420
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @193_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @194_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @195_532420
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @196_532420
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 3), &v, sizeof v); }  // @197_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @198_532420
  edx = (u32)(eax + eax*2);  // @199_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2), sizeof v); (u32)v; });  // @200_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @201_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 2), sizeof v); (u32)v; });  // @202_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 6), &v, sizeof v); }  // @203_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 4), sizeof v); (u32)v; });  // @204_532420
  ecx = edi;  // @205_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @206_532420
  eax = ext_52d250_fastcall4(ecx, edx, PV[4], PV[3]);  // @207_532420
  ecx = edx = 0;  // @208_532420
  L5326f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @210_532420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @211_532420
  L5326f9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @213_532420
  eax = (eax + 1);  // @214_532420
  FL[3] = eax;  // @215_532420
  ecx = (ecx + (u32)(10));  // @216_532420
  FL[3] = ecx;  // @217_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @218_532420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @219_532420
  FL[0] = eax; FL[1] = edx;  // @220_532420
  if ((s32)FL[0] < (s32)FL[1]) goto L532480;  // @221_532420
  L53270e:;
  eax = (u32)(1);  // @223_532420
  return eax;  // @224_532420
  L53271c:;
  eax = (u32)(65535);  // @226_532420
  return eax;  // @227_532420
}
PCREG(532420, lifted_532420);

