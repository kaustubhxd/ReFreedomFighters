// batch242012.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_459fc0_fastcall3(u32, u32, u32) __asm__("ext_459fc0");
extern "C" u32 FASTCALL ext_4cc7f0_fastcall2(u32, u32) __asm__("ext_4cc7f0");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4dfd80_fastcall2(u32, u32) __asm__("ext_4dfd80");
extern "C" u32 FASTCALL ext_4dfde0_fastcall2(u32, u32) __asm__("ext_4dfde0");
extern "C" u32 FASTCALL ext_4dfe20_fastcall2(u32, u32) __asm__("ext_4dfe20");
extern "C" u32 FASTCALL ext_4dfe60_fastcall2(u32, u32) __asm__("ext_4dfe60");
extern "C" u32 FASTCALL ext_4e0030_fastcall2(u32, u32) __asm__("ext_4e0030");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_4e1b80_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_4e1b80");
extern "C" u32 FASTCALL ext_53d160_fastcall4(u32, u32, u32, u32) __asm__("ext_53d160");
extern "C" u32 STDCALL ext_5403f0_stdcall10(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5403f0");
extern "C" u32 THISCALL ext_43ec00_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_43ec00");
extern "C" u32 THISCALL ext_440530_thiscall1(u32) __asm__("ext_440530");
extern "C" u32 THISCALL ext_441730_thiscall1(u32) __asm__("ext_441730");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_457960_thiscall3(u32, u32, u32) __asm__("ext_457960");
extern "C" u32 THISCALL ext_459f40_thiscall3(u32, u32, u32) __asm__("ext_459f40");
extern "C" u32 THISCALL ext_45dc90_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_45dc90");
extern "C" u32 THISCALL ext_460aa0_thiscall3(u32, u32, u32) __asm__("ext_460aa0");
extern "C" u32 THISCALL ext_48aad0_thiscall1(u32) __asm__("ext_48aad0");
extern "C" u32 THISCALL ext_4bf520_thiscall2(u32, u32) __asm__("ext_4bf520");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4dff10_thiscall1(u32) __asm__("ext_4dff10");
extern "C" u32 THISCALL ext_4dffb0_thiscall2(u32, u32) __asm__("ext_4dffb0");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5e80_thiscall1(u32) __asm__("ext_4e5e80");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e8c80_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4e8c80");
extern "C" u32 THISCALL ext_4ea280_thiscall3(u32, u32, u32) __asm__("ext_4ea280");
extern "C" u32 THISCALL ext_4ea2b0_thiscall3(u32, u32, u32) __asm__("ext_4ea2b0");
extern "C" u32 THISCALL ext_4ea2e0_thiscall2(u32, u32) __asm__("ext_4ea2e0");
extern "C" u32 THISCALL ext_545cb0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_545cb0");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634db2_cdecl0(void) __asm__("ext_634db2");
extern "C" u32 ext_634db2_cdecl2(...) __asm__("ext_634db2");
extern "C" u32 ext_634dd6_cdecl0(void) __asm__("ext_634dd6");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4b7940(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4b7940
  edi = ecx;  // @1_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_4b7940
  ecx = edx = 0;  // @5_4b7940
  ecx = (u32)(EBP - 8);  // @6_4b7940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @7_4b7940
  PV[0] = (u32)(ecx);  // @8_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_4b7940
  ecx = eax;  // @10_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6838796), PV[0]);  // @11_4b7940
  ecx = edx = 0;  // @12_4b7940
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; })) & 0xff);  // @13_4b7940
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @14_4b7940
  if (FL[2] == 0) goto L4b7ebc;  // @15_4b7940
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @16_4b7940
  FL[2] = (ebx & ebx);  // @17_4b7940
  if (FL[2] == 0) goto L4b7d6f;  // @18_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 132), sizeof v); (u32)v; });  // @19_4b7940
  FL[2] = (eax & eax);  // @20_4b7940
  if (FL[2] == 0) goto L4b79af;  // @21_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @22_4b7940
  PV[1] = (u32)(eax);  // @23_4b7940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 114), sizeof v); (u32)v; });  // @24_4b7940
  PV[2] = (u32)(eax);  // @25_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4b7940
  PV[3] = (u32)(ebx);  // @27_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, PV[3], PV[2], PV[1]);  // @28_4b7940
  ecx = edx = 0;  // @29_4b7940
  goto L4b79d7;  // @30_4b7940
  L4b79af:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @33_4b7940
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 253), &v, sizeof v); }  // @34_4b7940
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; });  // @35_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @37_4b7940
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 161), sizeof v); (u32)v; })) & 0xff);  // @38_4b7940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 257), &v, sizeof v); }  // @39_4b7940
  L4b79d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @42_4b7940
  PV[4] = (u32)(edx);  // @43_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @44_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[4]);  // @46_4b7940
  ecx = edx = 0;  // @47_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_4b7940
  esi = eax;  // @49_4b7940
  PV[5] = (u32)(ebx);  // @50_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @51_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[5]);  // @53_4b7940
  ecx = edx = 0;  // @54_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_4b7940
  ebx = eax;  // @56_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @57_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 312)))(ecx);  // @59_4b7940
  ecx = edx = 0;  // @60_4b7940
  ecx = (u32)(EBP - 12);  // @61_4b7940
  PV[6] = (u32)(ecx);  // @62_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @63_4b7940
  ecx = eax;  // @64_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, (u32)(6890172), PV[6]);  // @65_4b7940
  ecx = edx = 0;  // @66_4b7940
  FL[2] = (eax & eax);  // @67_4b7940
  if (FL[2] == 0) goto L4b7a41;  // @68_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @69_4b7940
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @70_4b7940
  X0[1] = 0;  // @71_4b7940
  X0[2] = 0;  // @72_4b7940
  X0[3] = 0;  // @73_4b7940
  PV[7] = (u32)(ecx);  // @74_4b7940
  ecx = esi;  // @75_4b7940
  PV[8] = X0[0];  // @76_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 532)))(ecx, PV[8]);  // @77_4b7940
  ecx = edx = 0;  // @78_4b7940
  L4b7a41:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @80_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @81_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @83_4b7940
  ecx = edx = 0;  // @84_4b7940
  ecx = (u32)(EBP - 4);  // @85_4b7940
  PV[9] = (u32)(ecx);  // @86_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @87_4b7940
  ecx = eax;  // @88_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, (u32)(6890184), PV[9]);  // @89_4b7940
  ecx = edx = 0;  // @90_4b7940
  FL[2] = (eax & eax);  // @91_4b7940
  if (FL[2] == 0) goto L4b7ab9;  // @92_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_4b7940
  edx = (u32)(EBP - 16);  // @94_4b7940
  PV[10] = (u32)(edx);  // @95_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @97_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6890196), PV[10]);  // @98_4b7940
  ecx = edx = 0;  // @99_4b7940
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @100_4b7940
  if (FL[2] == 0) goto L4b7aa4;  // @101_4b7940
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @102_4b7940
  X0[1] = 0;  // @103_4b7940
  X0[2] = 0;  // @104_4b7940
  X0[3] = 0;  // @105_4b7940
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @106_4b7940
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @107_4b7940
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @108_4b7940
  __builtin_memcpy((void *)((u32)(EBP - 24) + 4), &X0[1], 4);  // @109_4b7940
  { long double r_ = ((long double (__attribute__((cdecl)) *)(u32))(*(u32 *)0x6762d4))(PV[11]); double d_; __builtin_memcpy(&d_, (void *)(u32)(EBP - 24), 8); float f_ = (float)((long double)d_ / r_); __builtin_memcpy((void *)(u32)(EBP - 4), &f_, 4); }  // @110_4b7940 hand fix: atof is cdecl and returns on the x87 stack; fdivr m64 = m64 / st0
  ecx = edx = 0;  // @111_4b7940
  ;  // @112_4b7940 (folded into @110)
  ;  // @113_4b7940 (folded into @110)
  L4b7aa4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_4b7940
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @116_4b7940
  X0[1] = 0;  // @117_4b7940
  X0[2] = 0;  // @118_4b7940
  X0[3] = 0;  // @119_4b7940
  PV[12] = (u32)(ecx);  // @120_4b7940
  ecx = esi;  // @121_4b7940
  PV[13] = X0[0];  // @122_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[13]);  // @123_4b7940
  ecx = edx = 0;  // @124_4b7940
  L4b7ab9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @126_4b7940
  ecx = (u32)(6801640);  // @127_4b7940
  FL[2] = (eax & eax);  // @128_4b7940
  edx = (u32)(6890212);  // @129_4b7940
  if (FL[2] != 0) ecx = eax;  // @130_4b7940
  eax = ext_4cc850_fastcall2(ecx, edx);  // @131_4b7940
  ecx = edx = 0;  // @132_4b7940
  FL[2] = (eax & eax);  // @133_4b7940
  if (FL[2] == 0) goto L4b7aff;  // @134_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @135_4b7940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @136_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 112), sizeof v); (u32)v; });  // @137_4b7940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @138_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 116), sizeof v); (u32)v; });  // @139_4b7940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @140_4b7940
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }) & (u32)(524288));  // @141_4b7940
  if (FL[2] == 0) goto L4b7af8;  // @142_4b7940
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }) | (u32)(524288))); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @143_4b7940
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @144_4b7940
  goto L4b7aff;  // @145_4b7940
  L4b7af8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }) & (u32)(4294443007))); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @147_4b7940
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @148_4b7940
  L4b7aff:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @150_4b7940
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @151_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @152_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @153_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @154_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 840)))(ecx, PV[14]);  // @155_4b7940
  ecx = edx = 0;  // @156_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @157_4b7940
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @158_4b7940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; });  // @159_4b7940
  PV[15] = (u32)(ebx);  // @160_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_4b7940
  PV[16] = (u32)(eax);  // @162_4b7940
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @163_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, PV[17], PV[16], PV[15]);  // @164_4b7940
  ecx = edx = 0;  // @165_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @166_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @167_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @168_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @169_4b7940
  ecx = edx = 0;  // @170_4b7940
  ecx = (u32)(EBP - 8);  // @171_4b7940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @172_4b7940
  PV[18] = (u32)(ecx);  // @173_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @174_4b7940
  ecx = eax;  // @175_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6890232), PV[18]);  // @176_4b7940
  ecx = edx = 0;  // @177_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @178_4b7940
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; });  // @179_4b7940
  PV[19] = (u32)(eax);  // @180_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @181_4b7940
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @182_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, PV[20], PV[19], (u32)(0));  // @183_4b7940
  ecx = edx = 0;  // @184_4b7940
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @185_4b7940
  if (FL[0] != FL[1]) goto L4b7d60;  // @186_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @187_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @188_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @189_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886624), (u32)(1));  // @190_4b7940
  ecx = edx = 0;  // @191_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @192_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @193_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @194_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886640), (u32)(1));  // @195_4b7940
  ecx = edx = 0;  // @196_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @197_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @198_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @199_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886660), (u32)(1));  // @200_4b7940
  ecx = edx = 0;  // @201_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @202_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @203_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @204_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886700), (u32)(1));  // @205_4b7940
  ecx = edx = 0;  // @206_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @207_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @208_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @210_4b7940
  ecx = edx = 0;  // @211_4b7940
  ecx = (u32)(EBP - 8);  // @212_4b7940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @213_4b7940
  PV[21] = (u32)(ecx);  // @214_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @215_4b7940
  ecx = eax;  // @216_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6864536), PV[21]);  // @217_4b7940
  ecx = edx = 0;  // @218_4b7940
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @219_4b7940
  FL[2] = (ebx & ebx);  // @220_4b7940
  if (FL[2] == 0) goto L4b7c56;  // @221_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @222_4b7940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @223_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @224_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @225_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @226_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6890248), (u32)(0), (u32)(6889180), (u32)(1140));  // @227_4b7940
  ecx = edx = 0;  // @228_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @229_4b7940
  eax = (eax & 0xffff);  // @230_4b7940
  PV[22] = (u32)(eax);  // @231_4b7940
  PV[23] = (u32)(ebx);  // @232_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 300)))(ecx, PV[23], PV[22], (u32)(0));  // @233_4b7940
  ecx = edx = 0;  // @234_4b7940
  L4b7c56:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @236_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @237_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @238_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @239_4b7940
  ecx = edx = 0;  // @240_4b7940
  ecx = (u32)(EBP - 8);  // @241_4b7940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @242_4b7940
  PV[24] = (u32)(ecx);  // @243_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @244_4b7940
  ecx = eax;  // @245_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), PV[24]);  // @246_4b7940
  ecx = edx = 0;  // @247_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @248_4b7940
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @249_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @250_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @251_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[25]);  // @252_4b7940
  ecx = edx = 0;  // @253_4b7940
  ebx = eax;  // @254_4b7940
  FL[2] = (ebx & ebx);  // @255_4b7940
  if (FL[2] == 0) goto L4b7cfb;  // @256_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @257_4b7940
  ecx = ebx;  // @258_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 872)))(ecx);  // @259_4b7940
  ecx = edx = 0;  // @260_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @261_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @262_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @263_4b7940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @264_4b7940
  ecx = ebx;  // @265_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1280)))(ecx);  // @266_4b7940
  ecx = edx = 0;  // @267_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @268_4b7940
  PV[26] = (u32)(eax);  // @269_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @270_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[26]);  // @271_4b7940
  ecx = edx = 0;  // @272_4b7940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 120), &v, sizeof v); }  // @273_4b7940
  ecx = ebx;  // @274_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @275_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @276_4b7940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @277_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @278_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1284)))(ecx);  // @279_4b7940
  ecx = edx = 0;  // @280_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @281_4b7940
  PV[27] = (u32)(eax);  // @282_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @283_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[27]);  // @284_4b7940
  ecx = edx = 0;  // @285_4b7940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 124), &v, sizeof v); }  // @286_4b7940
  L4b7cfb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @288_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @289_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @290_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @291_4b7940
  ecx = edx = 0;  // @292_4b7940
  ecx = (u32)(EBP - 8);  // @293_4b7940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @294_4b7940
  PV[28] = (u32)(ecx);  // @295_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @296_4b7940
  ecx = eax;  // @297_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6890260), PV[28]);  // @298_4b7940
  ecx = edx = 0;  // @299_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @300_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @301_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @302_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @303_4b7940
  ecx = edx = 0;  // @304_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @305_4b7940
  ecx = (ecx + 1);  // @306_4b7940
  FL[3] = ecx;  // @307_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @308_4b7940
  PV[29] = (u32)(ecx);  // @309_4b7940
  ecx = eax;  // @310_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6890260), PV[29], (u32)(2));  // @311_4b7940
  ecx = edx = 0;  // @312_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @313_4b7940
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 132), &v, sizeof v); }  // @314_4b7940
  return eax;  // @315_4b7940
  L4b7d60:;
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 132), &v, sizeof v); }  // @317_4b7940
  return eax;  // @318_4b7940
  L4b7d6f:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @320_4b7940
  if (FL[2] == 0) goto L4b7ebc;  // @321_4b7940
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @322_4b7940
  if (FL[0] != FL[1]) goto L4b7da8;  // @323_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @324_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @325_4b7940
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 253), &v, sizeof v); }  // @326_4b7940
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; });  // @327_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @328_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @329_4b7940
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 161), sizeof v); (u32)v; })) & 0xff);  // @330_4b7940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 257), &v, sizeof v); }  // @331_4b7940
  L4b7da8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @333_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @334_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @335_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 152)))(ecx);  // @336_4b7940
  ecx = edx = 0;  // @337_4b7940
  ebx = eax;  // @338_4b7940
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @339_4b7940
  FL[2] = (ebx & ebx);  // @340_4b7940
  if (FL[2] == 0) goto L4b7ebc;  // @341_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @342_4b7940
  eax = (u32)(EBP - 28);  // @343_4b7940
  PV[30] = (u32)(eax);  // @344_4b7940
  ecx = ebx;  // @345_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[30]);  // @346_4b7940
  ecx = edx = 0;  // @347_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @348_4b7940
  ecx = (u32)(EBP - 28);  // @349_4b7940
  PV[31] = (u32)(ecx);  // @350_4b7940
  ecx = ebx;  // @351_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[31]);  // @352_4b7940
  ecx = edx = 0;  // @353_4b7940
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @354_4b7940
  edx = eax;  // @355_4b7940
  if (FL[0] == FL[1]) goto L4b7ebc;  // @356_4b7940
  L4b7df0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @358_4b7940
  PV[32] = (u32)(edx);  // @359_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @360_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @361_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[32]);  // @362_4b7940
  ecx = edx = 0;  // @363_4b7940
  esi = eax;  // @364_4b7940
  FL[2] = (esi & esi);  // @365_4b7940
  if (FL[2] == 0) goto L4b7ea5;  // @366_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @367_4b7940
  edx = (u32)(6801640);  // @368_4b7940
  FL[2] = (ecx & ecx);  // @369_4b7940
  if (FL[2] != 0) edx = ecx;  // @370_4b7940
  PV[33] = (u32)(edx);  // @371_4b7940
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[33], (u32)(6890276));  // @372_4b7940
  ecx = edx = 0;  // @373_4b7940
  FL[2] = (eax & eax);  // @374_4b7940
  if (FL[2] == 0) goto L4b7ea5;  // @375_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @376_4b7940
  ecx = (u32)(6801640);  // @377_4b7940
  FL[2] = (eax & eax);  // @378_4b7940
  if (FL[2] != 0) ecx = eax;  // @379_4b7940
  PV[34] = (u32)(ecx);  // @380_4b7940
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[34], (u32)(6890288));  // @381_4b7940
  ecx = edx = 0;  // @382_4b7940
  FL[2] = (eax & eax);  // @383_4b7940
  if (FL[2] == 0) goto L4b7ea5;  // @384_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @385_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @386_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @387_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 176)))(ecx);  // @388_4b7940
  ecx = edx = 0;  // @389_4b7940
  edx = (u32)(6890304);  // @390_4b7940
  ecx = eax;  // @391_4b7940
  eax = ext_4cc7f0_fastcall2(ecx, edx);  // @392_4b7940
  ecx = edx = 0;  // @393_4b7940
  FL[2] = (eax & eax);  // @394_4b7940
  ecx = (u32)(6801640);  // @395_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @396_4b7940
  ebx = (ebx & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @397_4b7940
  FL[2] = (eax & eax);  // @398_4b7940
  if (FL[2] != 0) ecx = eax;  // @399_4b7940
  PV[35] = (u32)(ecx);  // @400_4b7940
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[35], (u32)(6890328));  // @401_4b7940
  ecx = edx = 0;  // @402_4b7940
  FL[2] = (eax & eax);  // @403_4b7940
  eax = (eax & 0xffffff00u) | ((((FL[2] == 0) ? 1 : 0)) & 0xff);  // @404_4b7940
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @405_4b7940
  if (FL[2] == 0) goto L4b7e98;  // @406_4b7940
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @407_4b7940
  if (FL[2] != 0) goto L4b7ea2;  // @408_4b7940
  L4b7e98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @410_4b7940
  ecx = esi;  // @411_4b7940
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 596)))(ecx);  // @412_4b7940
  ecx = edx = 0;  // @413_4b7940
  L4b7ea2:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @415_4b7940
  L4b7ea5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @417_4b7940
  ecx = (u32)(EBP - 28);  // @418_4b7940
  PV[36] = (u32)(ecx);  // @419_4b7940
  ecx = ebx;  // @420_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[36]);  // @421_4b7940
  ecx = edx = 0;  // @422_4b7940
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @423_4b7940
  edx = eax;  // @424_4b7940
  if (FL[0] != FL[1]) goto L4b7df0;  // @425_4b7940
  L4b7ebc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @427_4b7940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @428_4b7940
  PV[37] = (u32)(esi);  // @429_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @430_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @431_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[37]);  // @432_4b7940
  ecx = edx = 0;  // @433_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @434_4b7940
  ebx = eax;  // @435_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @436_4b7940
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @437_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; });  // @438_4b7940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @439_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 840)))(ecx, PV[38]);  // @440_4b7940
  ecx = edx = 0;  // @441_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @442_4b7940
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }) & (u32)(4194304));  // @443_4b7940
  if (FL[2] == 0) goto L4b7f74;  // @444_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @445_4b7940
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @446_4b7940
  X0[0] = F2U((float)(s32)X0[0]);  // @447_4b7940
  X0[1] = F2U((float)(s32)X0[1]);  // @448_4b7940
  X0[2] = F2U((float)(s32)X0[2]);  // @449_4b7940
  X0[3] = F2U((float)(s32)X0[3]);  // @450_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @451_4b7940
  PV[39] = (u32)(ecx);  // @452_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @453_4b7940
  PV[40] = X0[0];  // @454_4b7940
  PV[41] = (u32)(ebx);  // @455_4b7940
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[41], PV[40]);  // @456_4b7940
  ecx = edx = 0;  // @457_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @458_4b7940
  PV[42] = (u32)(ebx);  // @459_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @460_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @461_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 176)))(ecx, PV[42]);  // @462_4b7940
  ecx = edx = 0;  // @463_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @464_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @465_4b7940
  FL[2] = (eax & eax);  // @466_4b7940
  if (FL[2] == 0) goto L4b7f74;  // @467_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @468_4b7940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @469_4b7940
  PV[43] = (u32)(ebx);  // @470_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @471_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[43]);  // @472_4b7940
  ecx = edx = 0;  // @473_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @474_4b7940
  PV[44] = (u32)(eax);  // @475_4b7940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @476_4b7940
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 188)))(ecx, PV[44]);  // @477_4b7940
  ecx = edx = 0;  // @478_4b7940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @479_4b7940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 132), &v, sizeof v); }  // @480_4b7940
  return eax;  // @481_4b7940
  L4b7f74:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 132), &v, sizeof v); }  // @483_4b7940
  return eax;  // @484_4b7940
}
PCREG(4b7940, lifted_4b7940);








