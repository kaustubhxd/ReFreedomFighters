// batch234029.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" long double FASTCALL ext_532850_fastcall2_ld(u32, u32) __asm__("ext_532850");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_52d250_fastcall4(u32, u32, u32, u32) __asm__("ext_52d250");
extern "C" u32 THISCALL ext_52b080_thiscall1(u32) __asm__("ext_52b080");
extern "C" u32 THISCALL ext_52b0c0_thiscall1(u32) __asm__("ext_52b0c0");
extern "C" u32 THISCALL ext_52e320_thiscall2(u32, u32) __asm__("ext_52e320");
extern "C" u32 THISCALL ext_530a40_thiscall1(u32) __asm__("ext_530a40");
extern "C" u32 THISCALL ext_531070_thiscall2(u32, u32) __asm__("ext_531070");
extern "C" u32 THISCALL ext_531740_thiscall3(u32, u32, u32) __asm__("ext_531740");
extern "C" u32 THISCALL ext_5318a0_thiscall2(u32, u32) __asm__("ext_5318a0");
extern "C" u32 THISCALL ext_531b40_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_531b40");
extern "C" u32 THISCALL ext_532420_thiscall3(u32, u32, u32) __asm__("ext_532420");
extern "C" u32 THISCALL ext_532770_thiscall4(u32, u32, u32, u32) __asm__("ext_532770");
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

extern "C" u32 THISCALL lifted_52f2b0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
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
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @0_52f2b0
  esi = ecx;  // @1_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_52f2b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_52f2b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 77), &v, sizeof v); }  // @4_52f2b0
  if (FL[0] == FL[1]) goto L52f2d9;  // @5_52f2b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @6_52f2b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 73), &v, sizeof v); }  // @7_52f2b0
  L52f2d9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @9_52f2b0
  ecx = (u32)(ebx + 89);  // @10_52f2b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 77), &v, sizeof v); }  // @11_52f2b0
  edi = (u32)(ebx + 101);  // @12_52f2b0
  edx = (u32)(1);  // @13_52f2b0
  FL[2] = (eax & eax);  // @14_52f2b0
  if (FL[2] == 0) goto L52f304;  // @15_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @16_52f2b0
  if (FL[0] == FL[1]) goto L52f304;  // @17_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @18_52f2b0
  if (FL[0] != FL[1]) goto L52f371;  // @19_52f2b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_52f2b0
  if (FL[0] != FL[1]) goto L52f371;  // @21_52f2b0
  L52f304:;
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @23_52f2b0
  eax = (u32)(esi + 150);  // @24_52f2b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_52f2b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @26_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @27_52f2b0
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @28_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @29_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @30_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @31_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 2), &v, sizeof v); }  // @32_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @33_52f2b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @34_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @35_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @36_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 95), &v, sizeof v); }  // @37_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @38_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 97), &v, sizeof v); }  // @39_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @40_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 99), &v, sizeof v); }  // @41_52f2b0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @42_52f2b0
  PV[1] = (u32)(ecx);  // @43_52f2b0
  ecx = edi;  // @44_52f2b0
  eax = ext_531740_thiscall3(ecx, PV[1], PV[0]);  // @45_52f2b0
  ecx = edx = 0;  // @46_52f2b0
  ecx = ebx;  // @47_52f2b0
  eax = ext_52b0c0_thiscall1(ecx);  // @48_52f2b0
  ecx = edx = 0;  // @49_52f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @50_52f2b0
  if (FL[2] == 0) goto L52f371;  // @51_52f2b0
  L52f366:;
  eax = 0;  // @53_52f2b0
  FL[3] = eax;  // @54_52f2b0
  return eax;  // @55_52f2b0
  L52f371:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; });  // @57_52f2b0
  eax = (u32)(ecx + 1);  // @58_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 77), &v, sizeof v); }  // @59_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @60_52f2b0
  FL[2] = (eax & eax);  // @61_52f2b0
  if (FL[2] == 0) goto L52f392;  // @62_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @63_52f2b0
  if (FL[0] == FL[1]) goto L52f392;  // @64_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @65_52f2b0
  if (FL[0] != FL[1]) goto L52f3b1;  // @66_52f2b0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; });  // @67_52f2b0
  if (FL[0] != FL[1]) goto L52f3b1;  // @68_52f2b0
  L52f392:;
  ecx = edi;  // @70_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @71_52f2b0
  ecx = edx = 0;  // @72_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 81), &v, sizeof v); }  // @73_52f2b0
  ecx = ebx;  // @74_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @75_52f2b0
  if (FL[2] == 0) goto L52ff59;  // @76_52f2b0
  eax = ext_52b0c0_thiscall1(ecx);  // @77_52f2b0
  ecx = edx = 0;  // @78_52f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @79_52f2b0
  if (FL[2] != 0) goto L52f366;  // @80_52f2b0
  L52f3b1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; });  // @82_52f2b0
  eax = (u32)(ecx + 1);  // @83_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 77), &v, sizeof v); }  // @84_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @85_52f2b0
  FL[2] = (eax & eax);  // @86_52f2b0
  if (FL[2] == 0) goto L52f3d2;  // @87_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @88_52f2b0
  if (FL[0] == FL[1]) goto L52f3d2;  // @89_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @90_52f2b0
  if (FL[0] != FL[1]) goto L52f441;  // @91_52f2b0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; });  // @92_52f2b0
  if (FL[0] != FL[1]) goto L52f441;  // @93_52f2b0
  L52f3d2:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @95_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @96_52f2b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @97_52f2b0
  esi = (u32)((s32)eax * (s32)(u32)(21));  // @98_52f2b0
  esi = (esi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 152), sizeof v); (u32)v; }));  // @99_52f2b0
  FL[3] = esi;  // @100_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @101_52f2b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 85), &v, sizeof v); }  // @102_52f2b0
  FS[0] = ext_532850_fastcall2_ld(ecx, edx);  // @103_52f2b0
  ecx = edx = 0;  // @104_52f2b0
  STF((u32)(esi + 10), FS[0]);  // @105_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @106_52f2b0
  ecx = 0;  // @107_52f2b0
  FL[3] = ecx;  // @108_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 14), &v, sizeof v); }  // @109_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @110_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @111_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @112_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 18), &v, sizeof v); }  // @113_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @114_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @115_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @116_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @117_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @118_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @119_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 14), sizeof v); (u32)v; });  // @120_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 6), &v, sizeof v); }  // @121_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @122_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @123_52f2b0
  ecx = ebx;  // @124_52f2b0
  eax = ext_52b0c0_thiscall1(ecx);  // @125_52f2b0
  ecx = edx = 0;  // @126_52f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @127_52f2b0
  if (FL[2] != 0) goto L52f366;  // @128_52f2b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @129_52f2b0
  L52f441:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; });  // @131_52f2b0
  eax = (u32)(ecx + 1);  // @132_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 77), &v, sizeof v); }  // @133_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @134_52f2b0
  FL[2] = (eax & eax);  // @135_52f2b0
  if (FL[2] == 0) goto L52f46a;  // @136_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @137_52f2b0
  if (FL[0] == FL[1]) goto L52f46a;  // @138_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @139_52f2b0
  if (FL[0] != FL[1]) goto L53005c;  // @140_52f2b0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; });  // @141_52f2b0
  if (FL[0] != FL[1]) goto L53005c;  // @142_52f2b0
  L52f46a:;
  eax = 0;  // @144_52f2b0
  FL[3] = eax;  // @145_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 83), &v, sizeof v); }  // @146_52f2b0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; }); FL[1] = (eax & 0xffff);  // @147_52f2b0
  if (FL[0] == FL[1]) goto L53004d;  // @148_52f2b0
  L52f47a:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @150_52f2b0
  X2[0] = 0;  // @151_52f2b0
  X2[1] = 0;  // @152_52f2b0
  X2[2] = 0;  // @153_52f2b0
  X2[3] = 0;  // @154_52f2b0
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 83), sizeof v); (u32)v; });  // @155_52f2b0
  if (FL[0] <= FL[1]) goto L52f48b;  // @156_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 83), &v, sizeof v); }  // @157_52f2b0
  L52f48b:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @159_52f2b0
  X1[1] = 0;  // @160_52f2b0
  X1[2] = 0;  // @161_52f2b0
  X1[3] = 0;  // @162_52f2b0
  FA = U2F(X1[0]); FB = U2F(X2[0]);  // @163_52f2b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @164_52f2b0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @165_52f2b0
  if (__builtin_parity(FL[2] & 0xff)) goto L52f4aa;  // @166_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @167_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 10) + 0), 4); v; });  // @168_52f2b0
  X0[1] = 0;  // @169_52f2b0
  X0[2] = 0;  // @170_52f2b0
  X0[3] = 0;  // @171_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @172_52f2b0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) goto L52ff57;  // @173_52f2b0
  L52f4aa:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @175_52f2b0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xffff);  // @176_52f2b0
  edx = (u32)(esi + 4);  // @177_52f2b0
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 95), sizeof v); (u32)v; });  // @178_52f2b0
  if (FL[0] != FL[1]) goto L52f4d2;  // @179_52f2b0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; })) & 0xffff);  // @180_52f2b0
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 97), sizeof v); (u32)v; });  // @181_52f2b0
  if (FL[0] != FL[1]) goto L52f4d2;  // @182_52f2b0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) & 0xffff);  // @183_52f2b0
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 99), sizeof v); (u32)v; });  // @184_52f2b0
  if (FL[0] == FL[1]) goto L530017;  // @185_52f2b0
  L52f4d2:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @187_52f2b0
  if (FL[0] != FL[1]) goto L52f4f3;  // @188_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @189_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @190_52f2b0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 56), sizeof v); (u32)v; });  // @191_52f2b0
  PV[3] = (u32)(eax);  // @192_52f2b0
  PV[4] = (u32)(edx);  // @193_52f2b0
  eax = ext_532770_thiscall4(ecx, PV[4], PV[3], PV[2]);  // @194_52f2b0
  ecx = edx = 0;  // @195_52f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @196_52f2b0
  if (FL[2] == 0) goto L52ff6c;  // @197_52f2b0
  edx = (u32)(esi + 4);  // @198_52f2b0
  L52f4f3:;
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @201_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @202_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @203_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @204_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @205_52f2b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @206_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @207_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @208_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @209_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @210_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @211_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @212_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @213_52f2b0
  eax = (u32)(ebx + 95);  // @214_52f2b0
  PV[5] = (u32)(eax);  // @215_52f2b0
  PV[6] = (u32)(ecx);  // @216_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @217_52f2b0
  ecx = esi;  // @218_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @219_52f2b0
  PV[7] = (u32)(edi);  // @220_52f2b0
  PV[8] = (u32)(eax);  // @221_52f2b0
  eax = ext_531b40_thiscall6(ecx, PV[8], PV[7], (u32)(0), (u32)(1065353216), PV[5]);  // @222_52f2b0
  ecx = edx = 0;  // @223_52f2b0
  eax = (eax & 0xffff);  // @224_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @225_52f2b0
  FL[0] = eax; FL[1] = (u32)(65535);  // @226_52f2b0
  if (FL[0] == FL[1]) goto L52ff57;  // @227_52f2b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @228_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @229_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @230_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @231_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @232_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @233_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @234_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @235_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @236_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @237_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @238_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @239_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @240_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @241_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @242_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @243_52f2b0
  if (FL[0] != FL[1]) goto L52f774;  // @244_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @245_52f2b0
  eax = (u32)(1);  // @246_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @247_52f2b0
  ecx = edi;  // @248_52f2b0
  eax = (u32)(EBP - 12);  // @249_52f2b0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @250_52f2b0
  PV[9] = (u32)(eax);  // @251_52f2b0
  if (FL[0] != FL[1]) goto L52f5be;  // @252_52f2b0
  eax = ext_52e320_thiscall2(ecx, PV[9]);  // @253_52f2b0
  ecx = edx = 0;  // @254_52f2b0
  goto L52f5c3;  // @255_52f2b0
  L52f5be:;
  eax = ext_531070_thiscall2(ecx, PV[9]);  // @257_52f2b0
  ecx = edx = 0;  // @258_52f2b0
  L52f5c3:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @260_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @261_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @262_52f2b0
  if (FL[0] != FL[1]) goto L52f5dd;  // @263_52f2b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @264_52f2b0
  goto L52f66e;  // @265_52f2b0
  L52f5dd:;
  ecx = edi;  // @267_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @268_52f2b0
  ecx = edx = 0;  // @269_52f2b0
  eax = (eax & 0xffff);  // @270_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @271_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @272_52f2b0
  if (FL[2] == 0) goto L52ff57;  // @273_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @274_52f2b0
  eax = (eax & 0xffff);  // @275_52f2b0
  edx = (u32)((s32)eax * (s32)(u32)(21));  // @276_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @277_52f2b0
  edx = (edx + ecx);  // @278_52f2b0
  FL[3] = edx;  // @279_52f2b0
  eax = (eax & 0xffff);  // @280_52f2b0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @281_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 10) + 0), 4); v; });  // @282_52f2b0
  X0[1] = 0;  // @283_52f2b0
  X0[2] = 0;  // @284_52f2b0
  X0[3] = 0;  // @285_52f2b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 10) + 0), 4); v; });  // @286_52f2b0
  X2[1] = 0;  // @287_52f2b0
  X2[2] = 0;  // @288_52f2b0
  X2[3] = 0;  // @289_52f2b0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6952324) + 0), 4); v; })));  // @290_52f2b0
  X1[0] = X2[0];  // @291_52f2b0
  X1[1] = X2[1];  // @292_52f2b0
  X1[2] = X2[2];  // @293_52f2b0
  X1[3] = X2[3];  // @294_52f2b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @295_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @296_52f2b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52f667;  // @297_52f2b0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @298_52f2b0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @299_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @300_52f2b0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @301_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 14), &v, sizeof v); }  // @302_52f2b0
  __builtin_memcpy((void *)((u32)(edx + 10) + 0), &X2[0], 4);  // @303_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @304_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @305_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @306_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @307_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 26), sizeof v); (u32)v; });  // @308_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @309_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @310_52f2b0
  PV[11] = (u32)(ecx);  // @311_52f2b0
  ecx = esi;  // @312_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @313_52f2b0
  eax = ext_52d250_fastcall4(ecx, edx, PV[11], PV[10]);  // @314_52f2b0
  ecx = edx = 0;  // @315_52f2b0
  L52f667:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @317_52f2b0
  L52f66e:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @319_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @320_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @321_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @322_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @323_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @324_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @325_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @326_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @327_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @328_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @329_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @330_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @331_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @332_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @333_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @334_52f2b0
  if (FL[0] != FL[1]) goto L52f774;  // @335_52f2b0
  eax = (eax | (u32)(4294967295));  // @336_52f2b0
  FL[3] = eax;  // @337_52f2b0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @338_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @339_52f2b0
  ecx = edi;  // @340_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @341_52f2b0
  eax = (u32)(EBP - 12);  // @342_52f2b0
  PV[12] = (u32)(eax);  // @343_52f2b0
  if (FL[0] != FL[1]) goto L52f6d3;  // @344_52f2b0
  eax = ext_52e320_thiscall2(ecx, PV[12]);  // @345_52f2b0
  ecx = edx = 0;  // @346_52f2b0
  goto L52f6d8;  // @347_52f2b0
  L52f6d3:;
  eax = ext_531070_thiscall2(ecx, PV[12]);  // @349_52f2b0
  ecx = edx = 0;  // @350_52f2b0
  L52f6d8:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @352_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @353_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @354_52f2b0
  if (FL[0] == FL[1]) goto L52f774;  // @355_52f2b0
  ecx = edi;  // @356_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @357_52f2b0
  ecx = edx = 0;  // @358_52f2b0
  eax = (eax & 0xffff);  // @359_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @360_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @361_52f2b0
  if (FL[2] == 0) goto L52ff57;  // @362_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @363_52f2b0
  eax = (eax & 0xffff);  // @364_52f2b0
  edx = (u32)((s32)eax * (s32)(u32)(21));  // @365_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @366_52f2b0
  edx = (edx + ecx);  // @367_52f2b0
  FL[3] = edx;  // @368_52f2b0
  eax = (eax & 0xffff);  // @369_52f2b0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @370_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 10) + 0), 4); v; });  // @371_52f2b0
  X0[1] = 0;  // @372_52f2b0
  X0[2] = 0;  // @373_52f2b0
  X0[3] = 0;  // @374_52f2b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 10) + 0), 4); v; });  // @375_52f2b0
  X2[1] = 0;  // @376_52f2b0
  X2[2] = 0;  // @377_52f2b0
  X2[3] = 0;  // @378_52f2b0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6952324) + 0), 4); v; })));  // @379_52f2b0
  X1[0] = X2[0];  // @380_52f2b0
  X1[1] = X2[1];  // @381_52f2b0
  X1[2] = X2[2];  // @382_52f2b0
  X1[3] = X2[3];  // @383_52f2b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @384_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @385_52f2b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52f774;  // @386_52f2b0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @387_52f2b0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @388_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @389_52f2b0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @390_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 14), &v, sizeof v); }  // @391_52f2b0
  __builtin_memcpy((void *)((u32)(edx + 10) + 0), &X2[0], 4);  // @392_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @393_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @394_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @395_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @396_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 26), sizeof v); (u32)v; });  // @397_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @398_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @399_52f2b0
  PV[14] = (u32)(ecx);  // @400_52f2b0
  ecx = esi;  // @401_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @402_52f2b0
  eax = ext_52d250_fastcall4(ecx, edx, PV[14], PV[13]);  // @403_52f2b0
  ecx = edx = 0;  // @404_52f2b0
  L52f774:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @406_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @407_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @408_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @409_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @410_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @411_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @412_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @413_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @414_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @415_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @416_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @417_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @418_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @419_52f2b0
  eax = (u32)(ebx + 95);  // @420_52f2b0
  PV[15] = (u32)(eax);  // @421_52f2b0
  PV[16] = (u32)(ecx);  // @422_52f2b0
  ecx = esi;  // @423_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @424_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @425_52f2b0
  PV[17] = (u32)(edi);  // @426_52f2b0
  PV[18] = (u32)(eax);  // @427_52f2b0
  eax = ext_531b40_thiscall6(ecx, PV[18], PV[17], (u32)(1), (u32)(1065353216), PV[15]);  // @428_52f2b0
  ecx = edx = 0;  // @429_52f2b0
  eax = (eax & 0xffff);  // @430_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @431_52f2b0
  FL[0] = eax; FL[1] = (u32)(65535);  // @432_52f2b0
  if (FL[0] == FL[1]) goto L52ff57;  // @433_52f2b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @434_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @435_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @436_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @437_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @438_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @439_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @440_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @441_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @442_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @443_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @444_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @445_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @446_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @447_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @448_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @449_52f2b0
  if (FL[0] != FL[1]) goto L52fa00;  // @450_52f2b0
  eax = 0;  // @451_52f2b0
  FL[3] = eax;  // @452_52f2b0
  ecx = edi;  // @453_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @454_52f2b0
  eax = (eax | (u32)(4294967295));  // @455_52f2b0
  FL[3] = eax;  // @456_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @457_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 10), &v, sizeof v); }  // @458_52f2b0
  eax = (u32)(1);  // @459_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @460_52f2b0
  eax = (u32)(EBP - 12);  // @461_52f2b0
  PV[19] = (u32)(eax);  // @462_52f2b0
  if (FL[0] != FL[1]) goto L52f847;  // @463_52f2b0
  eax = ext_52e320_thiscall2(ecx, PV[19]);  // @464_52f2b0
  ecx = edx = 0;  // @465_52f2b0
  goto L52f84c;  // @466_52f2b0
  L52f847:;
  eax = ext_531070_thiscall2(ecx, PV[19]);  // @468_52f2b0
  ecx = edx = 0;  // @469_52f2b0
  L52f84c:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @471_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @472_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @473_52f2b0
  if (FL[0] != FL[1]) goto L52f866;  // @474_52f2b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @475_52f2b0
  goto L52f8f7;  // @476_52f2b0
  L52f866:;
  ecx = edi;  // @478_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @479_52f2b0
  ecx = edx = 0;  // @480_52f2b0
  eax = (eax & 0xffff);  // @481_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @482_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @483_52f2b0
  if (FL[2] == 0) goto L52ff57;  // @484_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @485_52f2b0
  eax = (eax & 0xffff);  // @486_52f2b0
  edx = (u32)((s32)eax * (s32)(u32)(21));  // @487_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @488_52f2b0
  edx = (edx + ecx);  // @489_52f2b0
  FL[3] = edx;  // @490_52f2b0
  eax = (eax & 0xffff);  // @491_52f2b0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @492_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 10) + 0), 4); v; });  // @493_52f2b0
  X0[1] = 0;  // @494_52f2b0
  X0[2] = 0;  // @495_52f2b0
  X0[3] = 0;  // @496_52f2b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 10) + 0), 4); v; });  // @497_52f2b0
  X2[1] = 0;  // @498_52f2b0
  X2[2] = 0;  // @499_52f2b0
  X2[3] = 0;  // @500_52f2b0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6952324) + 0), 4); v; })));  // @501_52f2b0
  X1[0] = X2[0];  // @502_52f2b0
  X1[1] = X2[1];  // @503_52f2b0
  X1[2] = X2[2];  // @504_52f2b0
  X1[3] = X2[3];  // @505_52f2b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @506_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @507_52f2b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52f8f0;  // @508_52f2b0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @509_52f2b0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @510_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @511_52f2b0
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @512_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 14), &v, sizeof v); }  // @513_52f2b0
  __builtin_memcpy((void *)((u32)(edx + 10) + 0), &X2[0], 4);  // @514_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @515_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @516_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @517_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @518_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 26), sizeof v); (u32)v; });  // @519_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @520_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @521_52f2b0
  PV[21] = (u32)(ecx);  // @522_52f2b0
  ecx = esi;  // @523_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @524_52f2b0
  eax = ext_52d250_fastcall4(ecx, edx, PV[21], PV[20]);  // @525_52f2b0
  ecx = edx = 0;  // @526_52f2b0
  L52f8f0:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @528_52f2b0
  L52f8f7:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @530_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @531_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @532_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @533_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @534_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @535_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @536_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @537_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @538_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @539_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @540_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @541_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @542_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @543_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @544_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @545_52f2b0
  if (FL[0] != FL[1]) goto L52fa00;  // @546_52f2b0
  eax = 0;  // @547_52f2b0
  FL[3] = eax;  // @548_52f2b0
  ecx = edi;  // @549_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @550_52f2b0
  eax = (eax | (u32)(4294967295));  // @551_52f2b0
  FL[3] = eax;  // @552_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @553_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 10), &v, sizeof v); }  // @554_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @555_52f2b0
  eax = (u32)(EBP - 12);  // @556_52f2b0
  PV[22] = (u32)(eax);  // @557_52f2b0
  if (FL[0] != FL[1]) goto L52f95f;  // @558_52f2b0
  eax = ext_52e320_thiscall2(ecx, PV[22]);  // @559_52f2b0
  ecx = edx = 0;  // @560_52f2b0
  goto L52f964;  // @561_52f2b0
  L52f95f:;
  eax = ext_531070_thiscall2(ecx, PV[22]);  // @563_52f2b0
  ecx = edx = 0;  // @564_52f2b0
  L52f964:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @566_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @567_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @568_52f2b0
  if (FL[0] == FL[1]) goto L52fa00;  // @569_52f2b0
  ecx = edi;  // @570_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @571_52f2b0
  ecx = edx = 0;  // @572_52f2b0
  eax = (eax & 0xffff);  // @573_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @574_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @575_52f2b0
  if (FL[2] == 0) goto L52ff57;  // @576_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @577_52f2b0
  eax = (eax & 0xffff);  // @578_52f2b0
  edx = (u32)((s32)eax * (s32)(u32)(21));  // @579_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @580_52f2b0
  edx = (edx + ecx);  // @581_52f2b0
  FL[3] = edx;  // @582_52f2b0
  eax = (eax & 0xffff);  // @583_52f2b0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @584_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 10) + 0), 4); v; });  // @585_52f2b0
  X0[1] = 0;  // @586_52f2b0
  X0[2] = 0;  // @587_52f2b0
  X0[3] = 0;  // @588_52f2b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 10) + 0), 4); v; });  // @589_52f2b0
  X2[1] = 0;  // @590_52f2b0
  X2[2] = 0;  // @591_52f2b0
  X2[3] = 0;  // @592_52f2b0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6952324) + 0), 4); v; })));  // @593_52f2b0
  X1[0] = X2[0];  // @594_52f2b0
  X1[1] = X2[1];  // @595_52f2b0
  X1[2] = X2[2];  // @596_52f2b0
  X1[3] = X2[3];  // @597_52f2b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @598_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @599_52f2b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52fa00;  // @600_52f2b0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @601_52f2b0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @602_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @603_52f2b0
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @604_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 14), &v, sizeof v); }  // @605_52f2b0
  __builtin_memcpy((void *)((u32)(edx + 10) + 0), &X2[0], 4);  // @606_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @607_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @608_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @609_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @610_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 26), sizeof v); (u32)v; });  // @611_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @612_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @613_52f2b0
  PV[24] = (u32)(ecx);  // @614_52f2b0
  ecx = esi;  // @615_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @616_52f2b0
  eax = ext_52d250_fastcall4(ecx, edx, PV[24], PV[23]);  // @617_52f2b0
  ecx = edx = 0;  // @618_52f2b0
  L52fa00:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @620_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @621_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @622_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @623_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @624_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @625_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @626_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @627_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @628_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @629_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @630_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @631_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @632_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @633_52f2b0
  eax = (u32)(ebx + 95);  // @634_52f2b0
  PV[25] = (u32)(eax);  // @635_52f2b0
  PV[26] = (u32)(ecx);  // @636_52f2b0
  ecx = esi;  // @637_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @638_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @639_52f2b0
  PV[27] = (u32)(edi);  // @640_52f2b0
  PV[28] = (u32)(eax);  // @641_52f2b0
  eax = ext_531b40_thiscall6(ecx, PV[28], PV[27], (u32)(2), (u32)(1065353216), PV[25]);  // @642_52f2b0
  ecx = edx = 0;  // @643_52f2b0
  eax = (eax & 0xffff);  // @644_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @645_52f2b0
  FL[0] = eax; FL[1] = (u32)(65535);  // @646_52f2b0
  if (FL[0] == FL[1]) goto L52ff57;  // @647_52f2b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @648_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @649_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @650_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @651_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @652_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @653_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @654_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @655_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @656_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @657_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @658_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @659_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @660_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @661_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @662_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @663_52f2b0
  if (FL[0] != FL[1]) goto L52fc7f;  // @664_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @665_52f2b0
  eax = (u32)(EBP - 12);  // @666_52f2b0
  ecx = (u32)(1);  // @667_52f2b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @668_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @669_52f2b0
  ecx = edi;  // @670_52f2b0
  PV[29] = (u32)(eax);  // @671_52f2b0
  if (FL[0] != FL[1]) goto L52fac9;  // @672_52f2b0
  eax = ext_52e320_thiscall2(ecx, PV[29]);  // @673_52f2b0
  ecx = edx = 0;  // @674_52f2b0
  goto L52face;  // @675_52f2b0
  L52fac9:;
  eax = ext_531070_thiscall2(ecx, PV[29]);  // @677_52f2b0
  ecx = edx = 0;  // @678_52f2b0
  L52face:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @680_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @681_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @682_52f2b0
  if (FL[0] != FL[1]) goto L52fae8;  // @683_52f2b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @684_52f2b0
  goto L52fb79;  // @685_52f2b0
  L52fae8:;
  ecx = edi;  // @687_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @688_52f2b0
  ecx = edx = 0;  // @689_52f2b0
  eax = (eax & 0xffff);  // @690_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @691_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @692_52f2b0
  if (FL[2] == 0) goto L52ff57;  // @693_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @694_52f2b0
  eax = (eax & 0xffff);  // @695_52f2b0
  edx = (u32)((s32)eax * (s32)(u32)(21));  // @696_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @697_52f2b0
  edx = (edx + ecx);  // @698_52f2b0
  FL[3] = edx;  // @699_52f2b0
  eax = (eax & 0xffff);  // @700_52f2b0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @701_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 10) + 0), 4); v; });  // @702_52f2b0
  X0[1] = 0;  // @703_52f2b0
  X0[2] = 0;  // @704_52f2b0
  X0[3] = 0;  // @705_52f2b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 10) + 0), 4); v; });  // @706_52f2b0
  X2[1] = 0;  // @707_52f2b0
  X2[2] = 0;  // @708_52f2b0
  X2[3] = 0;  // @709_52f2b0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6952324) + 0), 4); v; })));  // @710_52f2b0
  X1[0] = X2[0];  // @711_52f2b0
  X1[1] = X2[1];  // @712_52f2b0
  X1[2] = X2[2];  // @713_52f2b0
  X1[3] = X2[3];  // @714_52f2b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @715_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @716_52f2b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52fb72;  // @717_52f2b0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @718_52f2b0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @719_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @720_52f2b0
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @721_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 14), &v, sizeof v); }  // @722_52f2b0
  __builtin_memcpy((void *)((u32)(edx + 10) + 0), &X2[0], 4);  // @723_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @724_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @725_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @726_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @727_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 26), sizeof v); (u32)v; });  // @728_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @729_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @730_52f2b0
  PV[31] = (u32)(ecx);  // @731_52f2b0
  ecx = esi;  // @732_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @733_52f2b0
  eax = ext_52d250_fastcall4(ecx, edx, PV[31], PV[30]);  // @734_52f2b0
  ecx = edx = 0;  // @735_52f2b0
  L52fb72:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @737_52f2b0
  L52fb79:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @739_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @740_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @741_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @742_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @743_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @744_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @745_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @746_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @747_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @748_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @749_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @750_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @751_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @752_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @753_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @754_52f2b0
  if (FL[0] != FL[1]) goto L52fc7f;  // @755_52f2b0
  eax = (eax | (u32)(4294967295));  // @756_52f2b0
  FL[3] = eax;  // @757_52f2b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @758_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @759_52f2b0
  ecx = edi;  // @760_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @761_52f2b0
  eax = (u32)(EBP - 12);  // @762_52f2b0
  PV[32] = (u32)(eax);  // @763_52f2b0
  if (FL[0] != FL[1]) goto L52fbde;  // @764_52f2b0
  eax = ext_52e320_thiscall2(ecx, PV[32]);  // @765_52f2b0
  ecx = edx = 0;  // @766_52f2b0
  goto L52fbe3;  // @767_52f2b0
  L52fbde:;
  eax = ext_531070_thiscall2(ecx, PV[32]);  // @769_52f2b0
  ecx = edx = 0;  // @770_52f2b0
  L52fbe3:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @772_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @773_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @774_52f2b0
  if (FL[0] == FL[1]) goto L52fc7f;  // @775_52f2b0
  ecx = edi;  // @776_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @777_52f2b0
  ecx = edx = 0;  // @778_52f2b0
  eax = (eax & 0xffff);  // @779_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @780_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @781_52f2b0
  if (FL[2] == 0) goto L52ff57;  // @782_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @783_52f2b0
  eax = (eax & 0xffff);  // @784_52f2b0
  edx = (u32)((s32)eax * (s32)(u32)(21));  // @785_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @786_52f2b0
  edx = (edx + ecx);  // @787_52f2b0
  FL[3] = edx;  // @788_52f2b0
  eax = (eax & 0xffff);  // @789_52f2b0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @790_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 10) + 0), 4); v; });  // @791_52f2b0
  X0[1] = 0;  // @792_52f2b0
  X0[2] = 0;  // @793_52f2b0
  X0[3] = 0;  // @794_52f2b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 10) + 0), 4); v; });  // @795_52f2b0
  X2[1] = 0;  // @796_52f2b0
  X2[2] = 0;  // @797_52f2b0
  X2[3] = 0;  // @798_52f2b0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6952324) + 0), 4); v; })));  // @799_52f2b0
  X1[0] = X2[0];  // @800_52f2b0
  X1[1] = X2[1];  // @801_52f2b0
  X1[2] = X2[2];  // @802_52f2b0
  X1[3] = X2[3];  // @803_52f2b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @804_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @805_52f2b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52fc7f;  // @806_52f2b0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @807_52f2b0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @808_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @809_52f2b0
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @810_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 14), &v, sizeof v); }  // @811_52f2b0
  __builtin_memcpy((void *)((u32)(edx + 10) + 0), &X2[0], 4);  // @812_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @813_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @814_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @815_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @816_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 26), sizeof v); (u32)v; });  // @817_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @818_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @819_52f2b0
  PV[34] = (u32)(ecx);  // @820_52f2b0
  ecx = esi;  // @821_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @822_52f2b0
  eax = ext_52d250_fastcall4(ecx, edx, PV[34], PV[33]);  // @823_52f2b0
  ecx = edx = 0;  // @824_52f2b0
  L52fc7f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @826_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @827_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @828_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @829_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @830_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @831_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @832_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @833_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @834_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @835_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @836_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @837_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @838_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @839_52f2b0
  eax = (u32)(ebx + 95);  // @840_52f2b0
  PV[35] = (u32)(eax);  // @841_52f2b0
  PV[36] = (u32)(ecx);  // @842_52f2b0
  ecx = esi;  // @843_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @844_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @845_52f2b0
  PV[37] = (u32)(edi);  // @846_52f2b0
  PV[38] = (u32)(eax);  // @847_52f2b0
  eax = ext_531b40_thiscall6(ecx, PV[38], PV[37], (u32)(3), (u32)(1065353216), PV[35]);  // @848_52f2b0
  ecx = edx = 0;  // @849_52f2b0
  eax = (eax & 0xffff);  // @850_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @851_52f2b0
  FL[0] = eax; FL[1] = (u32)(65535);  // @852_52f2b0
  if (FL[0] == FL[1]) goto L52ff57;  // @853_52f2b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @854_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @855_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @856_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @857_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @858_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @859_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @860_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @861_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @862_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @863_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @864_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @865_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @866_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @867_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @868_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @869_52f2b0
  if (FL[0] != FL[1]) goto L52ff03;  // @870_52f2b0
  eax = (eax | (u32)(4294967295));  // @871_52f2b0
  FL[3] = eax;  // @872_52f2b0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(EBP - 10), &v, sizeof v); }  // @873_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @874_52f2b0
  ecx = edi;  // @875_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @876_52f2b0
  eax = (u32)(EBP - 12);  // @877_52f2b0
  PV[39] = (u32)(eax);  // @878_52f2b0
  if (FL[0] != FL[1]) goto L52fd4a;  // @879_52f2b0
  eax = ext_52e320_thiscall2(ecx, PV[39]);  // @880_52f2b0
  ecx = edx = 0;  // @881_52f2b0
  goto L52fd4f;  // @882_52f2b0
  L52fd4a:;
  eax = ext_531070_thiscall2(ecx, PV[39]);  // @884_52f2b0
  ecx = edx = 0;  // @885_52f2b0
  L52fd4f:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @887_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @888_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @889_52f2b0
  if (FL[0] != FL[1]) goto L52fd69;  // @890_52f2b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @891_52f2b0
  goto L52fdfa;  // @892_52f2b0
  L52fd69:;
  ecx = edi;  // @894_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @895_52f2b0
  ecx = edx = 0;  // @896_52f2b0
  eax = (eax & 0xffff);  // @897_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @898_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @899_52f2b0
  if (FL[2] == 0) goto L52ff57;  // @900_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @901_52f2b0
  eax = (eax & 0xffff);  // @902_52f2b0
  edx = (u32)((s32)eax * (s32)(u32)(21));  // @903_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @904_52f2b0
  edx = (edx + ecx);  // @905_52f2b0
  FL[3] = edx;  // @906_52f2b0
  eax = (eax & 0xffff);  // @907_52f2b0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @908_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 10) + 0), 4); v; });  // @909_52f2b0
  X0[1] = 0;  // @910_52f2b0
  X0[2] = 0;  // @911_52f2b0
  X0[3] = 0;  // @912_52f2b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 10) + 0), 4); v; });  // @913_52f2b0
  X2[1] = 0;  // @914_52f2b0
  X2[2] = 0;  // @915_52f2b0
  X2[3] = 0;  // @916_52f2b0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6952324) + 0), 4); v; })));  // @917_52f2b0
  X1[0] = X2[0];  // @918_52f2b0
  X1[1] = X2[1];  // @919_52f2b0
  X1[2] = X2[2];  // @920_52f2b0
  X1[3] = X2[3];  // @921_52f2b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @922_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @923_52f2b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52fdf3;  // @924_52f2b0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @925_52f2b0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @926_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @927_52f2b0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @928_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 14), &v, sizeof v); }  // @929_52f2b0
  __builtin_memcpy((void *)((u32)(edx + 10) + 0), &X2[0], 4);  // @930_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @931_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @932_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @933_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @934_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 26), sizeof v); (u32)v; });  // @935_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @936_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @937_52f2b0
  PV[41] = (u32)(ecx);  // @938_52f2b0
  ecx = esi;  // @939_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @940_52f2b0
  eax = ext_52d250_fastcall4(ecx, edx, PV[41], PV[40]);  // @941_52f2b0
  ecx = edx = 0;  // @942_52f2b0
  L52fdf3:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @944_52f2b0
  L52fdfa:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @946_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @947_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @948_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @949_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @950_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @951_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @952_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @953_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @954_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @955_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @956_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @957_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @958_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @959_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @960_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @961_52f2b0
  if (FL[0] != FL[1]) goto L52ff03;  // @962_52f2b0
  eax = 0;  // @963_52f2b0
  FL[3] = eax;  // @964_52f2b0
  ecx = (ecx | (u32)(4294967295));  // @965_52f2b0
  FL[3] = ecx;  // @966_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @967_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 10), &v, sizeof v); }  // @968_52f2b0
  eax = (u32)(EBP - 12);  // @969_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @970_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @971_52f2b0
  ecx = edi;  // @972_52f2b0
  PV[42] = (u32)(eax);  // @973_52f2b0
  if (FL[0] != FL[1]) goto L52fe62;  // @974_52f2b0
  eax = ext_52e320_thiscall2(ecx, PV[42]);  // @975_52f2b0
  ecx = edx = 0;  // @976_52f2b0
  goto L52fe67;  // @977_52f2b0
  L52fe62:;
  eax = ext_531070_thiscall2(ecx, PV[42]);  // @979_52f2b0
  ecx = edx = 0;  // @980_52f2b0
  L52fe67:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @982_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @983_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @984_52f2b0
  if (FL[0] == FL[1]) goto L52ff03;  // @985_52f2b0
  ecx = edi;  // @986_52f2b0
  eax = ext_530a40_thiscall1(ecx);  // @987_52f2b0
  ecx = edx = 0;  // @988_52f2b0
  eax = (eax & 0xffff);  // @989_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @990_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @991_52f2b0
  if (FL[2] == 0) goto L52ff57;  // @992_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @993_52f2b0
  eax = (eax & 0xffff);  // @994_52f2b0
  edx = (u32)((s32)eax * (s32)(u32)(21));  // @995_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @996_52f2b0
  edx = (edx + ecx);  // @997_52f2b0
  FL[3] = edx;  // @998_52f2b0
  eax = (eax & 0xffff);  // @999_52f2b0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @1000_52f2b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 10) + 0), 4); v; });  // @1001_52f2b0
  X0[1] = 0;  // @1002_52f2b0
  X0[2] = 0;  // @1003_52f2b0
  X0[3] = 0;  // @1004_52f2b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 10) + 0), 4); v; });  // @1005_52f2b0
  X2[1] = 0;  // @1006_52f2b0
  X2[2] = 0;  // @1007_52f2b0
  X2[3] = 0;  // @1008_52f2b0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6952324) + 0), 4); v; })));  // @1009_52f2b0
  X1[0] = X2[0];  // @1010_52f2b0
  X1[1] = X2[1];  // @1011_52f2b0
  X1[2] = X2[2];  // @1012_52f2b0
  X1[3] = X2[3];  // @1013_52f2b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @1014_52f2b0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @1015_52f2b0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52ff03;  // @1016_52f2b0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @1017_52f2b0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @1018_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1019_52f2b0
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1020_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 14), &v, sizeof v); }  // @1021_52f2b0
  __builtin_memcpy((void *)((u32)(edx + 10) + 0), &X2[0], 4);  // @1022_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 22), sizeof v); (u32)v; });  // @1023_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @1024_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @1025_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @1026_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 26), sizeof v); (u32)v; });  // @1027_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @1028_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @1029_52f2b0
  PV[44] = (u32)(ecx);  // @1030_52f2b0
  ecx = esi;  // @1031_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @1032_52f2b0
  eax = ext_52d250_fastcall4(ecx, edx, PV[44], PV[43]);  // @1033_52f2b0
  ecx = edx = 0;  // @1034_52f2b0
  L52ff03:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @1036_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @1037_52f2b0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1038_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @1039_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @1040_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 26), &v, sizeof v); }  // @1041_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @1042_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @1043_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @1044_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @1045_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @1046_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @1047_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @1048_52f2b0
  ecx = (u32)(ebx + 95);  // @1049_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @1050_52f2b0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @1051_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @1052_52f2b0
  PV[45] = (u32)(ecx);  // @1053_52f2b0
  PV[46] = (u32)(eax);  // @1054_52f2b0
  ecx = esi;  // @1055_52f2b0
  eax = ext_532420_thiscall3(ecx, PV[46], PV[45]);  // @1056_52f2b0
  ecx = edx = 0;  // @1057_52f2b0
  ecx = (u32)(65535);  // @1058_52f2b0
  FL[0] = (eax & 0xffff); FL[1] = (ecx & 0xffff);  // @1059_52f2b0
  if (FL[0] != FL[1]) goto L52ff6f;  // @1060_52f2b0
  L52ff57:;
  ecx = ebx;  // @1062_52f2b0
  L52ff59:;
  eax = ext_52b080_thiscall1(ecx);  // @1064_52f2b0
  ecx = edx = 0;  // @1065_52f2b0
  eax = (u32)(65535);  // @1066_52f2b0
  return eax;  // @1067_52f2b0
  L52ff6c:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @1069_52f2b0
  L52ff6f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @1071_52f2b0
  ecx = 0;  // @1072_52f2b0
  FL[3] = ecx;  // @1073_52f2b0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; })) & 0xffff);  // @1074_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 81), &v, sizeof v); }  // @1075_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 85), sizeof v); (u32)v; });  // @1076_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @1077_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @1078_52f2b0
  ecx = (u32)((s32)eax * (s32)(u32)(21));  // @1079_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @1080_52f2b0
  eax = (eax + ecx);  // @1081_52f2b0
  FL[3] = eax;  // @1082_52f2b0
  ecx = 0;  // @1083_52f2b0
  FL[3] = ecx;  // @1084_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 85), &v, sizeof v); }  // @1085_52f2b0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 18), &v, sizeof v); }  // @1086_52f2b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(ebx + 73), &v, sizeof v); }  // @1087_52f2b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; });  // @1088_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1089_52f2b0
  FL[2] = (eax & eax);  // @1090_52f2b0
  if (FL[2] == 0) goto L52fffe;  // @1091_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (ecx & 0xff);  // @1092_52f2b0
  if (FL[0] == FL[1]) goto L52fffe;  // @1093_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1094_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1095_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @1096_52f2b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6950568), (u32)(61));  // @1097_52f2b0
  ecx = edx = 0;  // @1098_52f2b0
  ecx = eax;  // @1099_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1100_52f2b0
  edx = ecx;  // @1101_52f2b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @1102_52f2b0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @1103_52f2b0
  FL[3] = edx;  // @1104_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @1105_52f2b0
  FL[0] = edx; FL[1] = ecx;  // @1106_52f2b0
  eax = (eax & 0xffffff00u) | ((((FL[0] > FL[1]) ? 1 : 0)) & 0xff);  // @1107_52f2b0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @1108_52f2b0
  FL[0] = edx; FL[1] = ecx;  // @1109_52f2b0
  if (FL[0] <= FL[1]) goto L52ffe4;  // @1110_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1111_52f2b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1112_52f2b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1113_52f2b0
  L52ffe4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1115_52f2b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @1116_52f2b0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @1117_52f2b0
  if (FL[0] >= FL[1]) goto L52fffe;  // @1118_52f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1119_52f2b0
  if (FL[2] == 0) goto L530000;  // @1120_52f2b0
  eax = (u32)(edx + 1);  // @1121_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @1122_52f2b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; })) & 0xff);  // @1123_52f2b0
  goto L530000;  // @1124_52f2b0
  L52fffe:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @1126_52f2b0
  FL[3] = (eax & 0xff);  // @1127_52f2b0
  L530000:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 73), &v, sizeof v); }  // @1129_52f2b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; });  // @1130_52f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1131_52f2b0
  if (FL[2] != 0) goto L52f366;  // @1132_52f2b0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1133_52f2b0
  if (FL[0] == FL[1]) goto L53001a;  // @1134_52f2b0
  goto L52f47a;  // @1135_52f2b0
  L530017:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @1137_52f2b0
  L53001a:;
  eax = (u32)(20000);  // @1139_52f2b0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 83), sizeof v); (u32)v; }); FL[1] = (eax & 0xffff);  // @1140_52f2b0
  if (FL[0] <= FL[1]) goto L53004d;  // @1141_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @1142_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1143_52f2b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6951992), (u32)(1576));  // @1144_52f2b0
  ecx = edx = 0;  // @1145_52f2b0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 83), sizeof v); (u32)v; });  // @1146_52f2b0
  PV[47] = (u32)(ecx);  // @1147_52f2b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1148_52f2b0
  PV[48] = (u32)(eax);  // @1149_52f2b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edx + 44)))(PV[48], (u32)(6952148), PV[47]);  // @1150_52f2b0
  ecx = edx = 0;  // @1151_52f2b0
  L53004d:;
  ecx = ebx;  // @1153_52f2b0
  eax = ext_52b0c0_thiscall1(ecx);  // @1154_52f2b0
  ecx = edx = 0;  // @1155_52f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1156_52f2b0
  if (FL[2] != 0) goto L52f366;  // @1157_52f2b0
  L53005c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; });  // @1159_52f2b0
  eax = (u32)(ecx + 1);  // @1160_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 77), &v, sizeof v); }  // @1161_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1162_52f2b0
  FL[2] = (eax & eax);  // @1163_52f2b0
  if (FL[2] == 0) goto L53007d;  // @1164_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1165_52f2b0
  if (FL[0] == FL[1]) goto L53007d;  // @1166_52f2b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1167_52f2b0
  if (FL[0] != FL[1]) goto L530098;  // @1168_52f2b0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; });  // @1169_52f2b0
  if (FL[0] != FL[1]) goto L530098;  // @1170_52f2b0
  L53007d:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @1172_52f2b0
  ecx = esi;  // @1173_52f2b0
  PV[49] = (u32)(eax);  // @1174_52f2b0
  eax = ext_5318a0_thiscall2(ecx, PV[49]);  // @1175_52f2b0
  ecx = edx = 0;  // @1176_52f2b0
  ecx = ebx;  // @1177_52f2b0
  eax = ext_52b0c0_thiscall1(ecx);  // @1178_52f2b0
  ecx = edx = 0;  // @1179_52f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1180_52f2b0
  if (FL[2] != 0) goto L52f366;  // @1181_52f2b0
  L530098:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @1183_52f2b0
  edx = (edx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @1184_52f2b0
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @1185_52f2b0
  ecx = eax;  // @1186_52f2b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @1187_52f2b0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1188_52f2b0
  if (FL[2] == 0) goto L530114;  // @1189_52f2b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @1190_52f2b0
  esi = (esi + (u32)(18));  // @1191_52f2b0
  FL[3] = esi;  // @1192_52f2b0
  edi = (edi + (u32)(6));  // @1193_52f2b0
  FL[3] = edi;  // @1194_52f2b0
  L5300b4:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; });  // @1196_52f2b0
  ecx = (u32)((s32)eax * (s32)(u32)(21));  // @1197_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @1198_52f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 152), sizeof v); (u32)v; });  // @1199_52f2b0
  eax = (eax + ecx);  // @1200_52f2b0
  FL[3] = eax;  // @1201_52f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 85), &v, sizeof v); }  // @1202_52f2b0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 14), sizeof v); (u32)v; });  // @1203_52f2b0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; }) & (u32)(1));  // @1204_52f2b0
  eax = ecx;  // @1205_52f2b0
  if (FL[2] == 0) goto L5300e3;  // @1206_52f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @1207_52f2b0
  eax = (eax << (u32)(5));  // @1208_52f2b0
  FL[3] = eax;  // @1209_52f2b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 158), sizeof v); (u32)v; });  // @1210_52f2b0
  L5300e3:;
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @1212_52f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 81), &v, sizeof v); }  // @1213_52f2b0
  PV[50] = (u32)(edi);  // @1214_52f2b0
  edx = esi;  // @1215_52f2b0
  if (FL[2] == 0) goto L5300f7;  // @1216_52f2b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @1217_52f2b0
  ecx = (u32)(EBP - 16);  // @1218_52f2b0
  goto L530105;  // @1219_52f2b0
  L5300f7:;
  ecx = (u32)(EBP - 28);  // @1221_52f2b0
  eax = ext_43e920_fastcall3(ecx, edx, PV[50]);  // @1222_52f2b0
  ecx = edx = 0;  // @1223_52f2b0
  PV[51] = (u32)(edi);  // @1224_52f2b0
  edx = esi;  // @1225_52f2b0
  ecx = (u32)(EBP - 40);  // @1226_52f2b0
  L530105:;
  eax = ext_43e920_fastcall3(ecx, edx, PV[51]);  // @1228_52f2b0
  ecx = edx = 0;  // @1229_52f2b0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 81), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1230_52f2b0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; })) & 0xff);  // @1231_52f2b0
  if (FL[0] != FL[1]) goto L5300b4;  // @1232_52f2b0
  L530114:;
  ecx = ebx;  // @1234_52f2b0
  eax = ext_52b080_thiscall1(ecx);  // @1235_52f2b0
  ecx = edx = 0;  // @1236_52f2b0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xffff);  // @1237_52f2b0
  return eax;  // @1238_52f2b0
}
PCREG(52f2b0, lifted_52f2b0);

