// batch236003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 STDCALL ext_477620_stdcall1(u32) __asm__("ext_477620");
extern "C" u32 THISCALL ext_440530_thiscall1(u32) __asm__("ext_440530");
extern "C" u32 THISCALL ext_441730_thiscall1(u32) __asm__("ext_441730");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_465fb0_thiscall1(u32) __asm__("ext_465fb0");
extern "C" u32 THISCALL ext_479090_thiscall1(u32) __asm__("ext_479090");
extern "C" u32 THISCALL ext_47b290_thiscall2(u32, u32) __asm__("ext_47b290");
extern "C" u32 THISCALL ext_47d290_thiscall1(u32) __asm__("ext_47d290");
extern "C" u32 THISCALL ext_47e5e0_thiscall1(u32) __asm__("ext_47e5e0");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e0d80_thiscall2(u32, u32) __asm__("ext_4e0d80");
extern "C" u32 THISCALL ext_4fc190_thiscall1(u32) __asm__("ext_4fc190");
extern "C" u32 THISCALL ext_4fdac0_thiscall1(u32) __asm__("ext_4fdac0");
extern "C" u32 ext_634dc4_cdecl3(...) __asm__("ext_634dc4");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4fdd20(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4fdd20
  edi = ecx;  // @1_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @2_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @4_4fdd20
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6931312), (u32)(0));  // @5_4fdd20
  ecx = edx = 0;  // @6_4fdd20
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @7_4fdd20
  if (FL[2] == 0) goto L4fdd55;  // @8_4fdd20
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; }) ^ (u32)(1))); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @9_4fdd20
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @10_4fdd20
  L4fdd55:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; })) & 0xff);  // @12_4fdd20
  ecx = edi;  // @13_4fdd20
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 69), &v, sizeof v); }  // @14_4fdd20
  eax = ext_4fc190_thiscall1(ecx);  // @15_4fdd20
  ecx = edx = 0;  // @16_4fdd20
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @17_4fdd20
  if (FL[2] != 0) goto L4fe022;  // @18_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @19_4fdd20
  ecx = edi;  // @20_4fdd20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 140)))(ecx);  // @21_4fdd20
  ecx = edx = 0;  // @22_4fdd20
  ebx = eax;  // @23_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 334), sizeof v); (u32)v; });  // @24_4fdd20
  FL[2] = (eax & eax);  // @25_4fdd20
  if (FL[2] == 0) goto L4fdda9;  // @26_4fdd20
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @27_4fdd20
  if (FL[0] != FL[1]) goto L4fdda9;  // @28_4fdd20
  FL[2] = (ebx & ebx);  // @29_4fdd20
  if (FL[2] == 0) goto L4fdd9f;  // @30_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @31_4fdd20
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @32_4fdd20
  PV[0] = (u32)(eax);  // @33_4fdd20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_4fdd20
  PV[1] = (u32)(ebx);  // @35_4fdd20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[1], PV[0], (u32)(0));  // @36_4fdd20
  ecx = edx = 0;  // @37_4fdd20
  L4fdd9f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 334), &v, sizeof v); }  // @39_4fdd20
  L4fdda9:;
  FL[2] = (ebx & ebx);  // @41_4fdd20
  if (FL[2] == 0) goto L4fe06f;  // @42_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @43_4fdd20
  ecx = (u32)(EBP - 32);  // @44_4fdd20
  PV[2] = (u32)(ecx);  // @45_4fdd20
  ecx = (u32)(EBP - 68);  // @46_4fdd20
  PV[3] = (u32)(ecx);  // @47_4fdd20
  ecx = ebx;  // @48_4fdd20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[3], PV[2]);  // @49_4fdd20
  ecx = edx = 0;  // @50_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @51_4fdd20
  edx = (u32)(EBP - 32);  // @52_4fdd20
  PV[4] = (u32)(edx);  // @53_4fdd20
  edx = (u32)(EBP - 68);  // @54_4fdd20
  PV[5] = (u32)(edx);  // @55_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_4fdd20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[5], PV[4]);  // @57_4fdd20
  ecx = edx = 0;  // @58_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @59_4fdd20
  ecx = (u32)(EBP - 20);  // @60_4fdd20
  PV[6] = (u32)(ecx);  // @61_4fdd20
  ecx = ebx;  // @62_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[6]);  // @63_4fdd20
  ecx = edx = 0;  // @64_4fdd20
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 86) + 0), 4); v; });  // @65_4fdd20
  X5[1] = 0;  // @66_4fdd20
  X5[2] = 0;  // @67_4fdd20
  X5[3] = 0;  // @68_4fdd20
  edx = (u32)(EBP - 20);  // @69_4fdd20
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 78) + 0), 4); v; });  // @70_4fdd20
  X1[1] = 0;  // @71_4fdd20
  X1[2] = 0;  // @72_4fdd20
  X1[3] = 0;  // @73_4fdd20
  X0[0] = X5[0];  // @74_4fdd20
  X0[1] = X5[1];  // @75_4fdd20
  X0[2] = X5[2];  // @76_4fdd20
  X0[3] = X5[3];  // @77_4fdd20
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @78_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @79_4fdd20
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @80_4fdd20
  PV[7] = (u32)(edx);  // @81_4fdd20
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 90) + 0), 4); v; });  // @82_4fdd20
  X3[1] = 0;  // @83_4fdd20
  X3[2] = 0;  // @84_4fdd20
  X3[3] = 0;  // @85_4fdd20
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @86_4fdd20
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @87_4fdd20
  X0[0] = X3[0];  // @88_4fdd20
  X0[1] = X3[1];  // @89_4fdd20
  X0[2] = X3[2];  // @90_4fdd20
  X0[3] = X3[3];  // @91_4fdd20
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @92_4fdd20
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @93_4fdd20
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @94_4fdd20
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 82) + 0), 4); v; });  // @95_4fdd20
  X1[1] = 0;  // @96_4fdd20
  X1[2] = 0;  // @97_4fdd20
  X1[3] = 0;  // @98_4fdd20
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @99_4fdd20
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X5[0], 4);  // @100_4fdd20
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X3[0], 4);  // @101_4fdd20
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @102_4fdd20
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X1[0], 4);  // @103_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 398), sizeof v); (u32)v; });  // @104_4fdd20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 398), &v, sizeof v); }  // @105_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 389), sizeof v); (u32)v; });  // @106_4fdd20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 389), &v, sizeof v); }  // @107_4fdd20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 397), sizeof v); (u32)v; })) & 0xff);  // @108_4fdd20
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 397), &v, sizeof v); }  // @109_4fdd20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 397), &v, sizeof v); }  // @110_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @111_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[7]);  // @113_4fdd20
  ecx = edx = 0;  // @114_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @115_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; });  // @116_4fdd20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 48), &v, sizeof v); }  // @117_4fdd20
  ecx = ebx;  // @118_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @119_4fdd20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @120_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @121_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 584), sizeof v); (u32)v; });  // @122_4fdd20
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @123_4fdd20
  ecx = edx = 0;  // @124_4fdd20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 86) + 0), 4); v; });  // @125_4fdd20
  X0[1] = 0;  // @126_4fdd20
  X0[2] = 0;  // @127_4fdd20
  X0[3] = 0;  // @128_4fdd20
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 90) + 0), 4); v; })));  // @129_4fdd20
  PV[8] = (u32)(ecx);  // @130_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @131_4fdd20
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @132_4fdd20
  __asm__ volatile("fdivs %0" :: "m"(*(float *)(u32)(EBP - 76)) : "st");  // @133_4fdd20
  { float f_; __asm__ volatile("fstps %0" : "=m"(f_) :: "st"); PV[9] = F2U(f_); }  // @134_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 580)))(ecx, PV[9]);  // @135_4fdd20
  ecx = edx = 0;  // @136_4fdd20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 92) + 0), 4); v; });  // @137_4fdd20
  X0[1] = 0;  // @138_4fdd20
  X0[2] = 0;  // @139_4fdd20
  X0[3] = 0;  // @140_4fdd20
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806056) + 0), 4); v; })));  // @141_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @142_4fdd20
  PV[10] = (u32)(ecx);  // @143_4fdd20
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @144_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_4fdd20
  PV[11] = X0[0];  // @146_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 548)))(ecx, PV[11]);  // @147_4fdd20
  ecx = edx = 0;  // @148_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @149_4fdd20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 100) + 0), 4); v; });  // @150_4fdd20
  X0[1] = 0;  // @151_4fdd20
  X0[2] = 0;  // @152_4fdd20
  X0[3] = 0;  // @153_4fdd20
  PV[12] = (u32)(ecx);  // @154_4fdd20
  PV[13] = X0[0];  // @155_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @156_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 532)))(ecx, PV[13]);  // @157_4fdd20
  ecx = edx = 0;  // @158_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @159_4fdd20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 94) + 0), 4); v; });  // @160_4fdd20
  X0[1] = 0;  // @161_4fdd20
  X0[2] = 0;  // @162_4fdd20
  X0[3] = 0;  // @163_4fdd20
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 104) + 0), 4); v; })));  // @164_4fdd20
  PV[14] = (u32)(ecx);  // @165_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @166_4fdd20
  PV[15] = X0[0];  // @167_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[15]);  // @168_4fdd20
  ecx = edx = 0;  // @169_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @170_4fdd20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; }) & (u32)(4293328895))); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @171_4fdd20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; });  // @172_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @173_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @174_4fdd20
  eax = (eax & (u32)(1638400));  // @175_4fdd20
  FL[3] = eax;  // @176_4fdd20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 72), sizeof v); (u32)v; }) | eax)); __builtin_memcpy((void *)(u32)(ecx + 72), &v, sizeof v); }  // @177_4fdd20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 72), sizeof v); (u32)v; });  // @178_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @179_4fdd20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 368), sizeof v); (u32)v; })) & 0xff);  // @180_4fdd20
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 368), &v, sizeof v); }  // @181_4fdd20
  ecx = ebx;  // @182_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @183_4fdd20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 648)))(ecx);  // @184_4fdd20
  ecx = edx = 0;  // @185_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @186_4fdd20
  PV[16] = (u32)(eax);  // @187_4fdd20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @188_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 644)))(ecx, PV[16]);  // @189_4fdd20
  ecx = edx = 0;  // @190_4fdd20
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 69), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @191_4fdd20
  if (FL[0] != FL[1]) goto L4fdf4e;  // @192_4fdd20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 74), sizeof v); (u32)v; })) & 0xff);  // @193_4fdd20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @194_4fdd20
  FL[3] = (eax & 0xff);  // @195_4fdd20
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 69), &v, sizeof v); }  // @196_4fdd20
  L4fdf4e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @198_4fdd20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; });  // @199_4fdd20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 76), sizeof v); (u32)v; }); FL[1] = edx;  // @200_4fdd20
  if (FL[0] == FL[1]) goto L4fdf6e;  // @201_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_4fdd20
  X0[0] = edx; X0[1] = X0[2] = X0[3] = 0;  // @203_4fdd20
  X0[0] = F2U((float)(s32)X0[0]);  // @204_4fdd20
  X0[1] = F2U((float)(s32)X0[1]);  // @205_4fdd20
  X0[2] = F2U((float)(s32)X0[2]);  // @206_4fdd20
  X0[3] = F2U((float)(s32)X0[3]);  // @207_4fdd20
  PV[17] = (u32)(ecx);  // @208_4fdd20
  PV[18] = X0[0];  // @209_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 640)))(ecx, PV[18]);  // @210_4fdd20
  ecx = edx = 0;  // @211_4fdd20
  L4fdf6e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @213_4fdd20
  edx = (u32)(6801640);  // @214_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 338), sizeof v); (u32)v; });  // @215_4fdd20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 108), &v, sizeof v); }  // @216_4fdd20
  ecx = edx;  // @217_4fdd20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @218_4fdd20
  FL[2] = (esi & esi);  // @219_4fdd20
  if (FL[2] != 0) ecx = esi;  // @220_4fdd20
  eax = (u32)(ecx + 1);  // @221_4fdd20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @222_4fdd20
  L4fdf90:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @224_4fdd20
  ecx = (ecx + 1);  // @225_4fdd20
  FL[3] = ecx;  // @226_4fdd20
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @227_4fdd20
  if (FL[2] != 0) goto L4fdf90;  // @228_4fdd20
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; }));  // @229_4fdd20
  FL[3] = ecx;  // @230_4fdd20
  FL[0] = ecx; FL[1] = (u32)(16);  // @231_4fdd20
  if ((s32)FL[0] < (s32)FL[1]) goto L4fdfc7;  // @232_4fdd20
  FL[2] = (esi & esi);  // @233_4fdd20
  if (FL[2] != 0) edx = esi;  // @234_4fdd20
  eax = (u32)(edx - 16);  // @235_4fdd20
  eax = (eax + ecx);  // @236_4fdd20
  FL[3] = eax;  // @237_4fdd20
  PV[19] = (u32)(eax);  // @238_4fdd20
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x67640c))(PV[19], (u32)(6931924), (u32)(16));  // @239_4fdd20
  ecx = edx = 0;  // @240_4fdd20
  FL[2] = (eax & eax);  // @241_4fdd20
  if (FL[2] != 0) goto L4fdfc7;  // @242_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @243_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @244_4fdd20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 108), &v, sizeof v); }  // @245_4fdd20
  L4fdfc7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @247_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @248_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @249_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @250_4fdd20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @251_4fdd20
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @252_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 840)))(ecx, PV[20]);  // @253_4fdd20
  ecx = edx = 0;  // @254_4fdd20
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 112) + 0), 4); v; });  // @255_4fdd20
  X2[1] = 0;  // @256_4fdd20
  X2[2] = 0;  // @257_4fdd20
  X2[3] = 0;  // @258_4fdd20
  X1[0] = 0;  // @259_4fdd20
  X1[1] = 0;  // @260_4fdd20
  X1[2] = 0;  // @261_4fdd20
  X1[3] = 0;  // @262_4fdd20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @263_4fdd20
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @264_4fdd20
  if (!__builtin_parity(FL[2] & 0xff)) goto L4fe00f;  // @265_4fdd20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 116) + 0), 4); v; });  // @266_4fdd20
  X0[1] = 0;  // @267_4fdd20
  X0[2] = 0;  // @268_4fdd20
  X0[3] = 0;  // @269_4fdd20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @270_4fdd20
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @271_4fdd20
  if (!__builtin_parity(FL[2] & 0xff)) goto L4fe00f;  // @272_4fdd20
  ecx = edi;  // @273_4fdd20
  eax = ext_4fdac0_thiscall1(ecx);  // @274_4fdd20
  ecx = edx = 0;  // @275_4fdd20
  goto L4fe02f;  // @276_4fdd20
  L4fe00f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @278_4fdd20
  __builtin_memcpy((void *)((u32)(eax + 112) + 0), &X2[0], 4);  // @279_4fdd20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @280_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 116), sizeof v); (u32)v; });  // @281_4fdd20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 116), &v, sizeof v); }  // @282_4fdd20
  goto L4fe02f;  // @283_4fdd20
  L4fe022:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @285_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @286_4fdd20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, (u32)(0));  // @287_4fdd20
  ecx = edx = 0;  // @288_4fdd20
  L4fe02f:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 69), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @290_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @291_4fdd20
  if (FL[0] == FL[1]) goto L4fe041;  // @292_4fdd20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; }) | (u32)(65536))); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @293_4fdd20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; });  // @294_4fdd20
  goto L4fe048;  // @295_4fdd20
  L4fe041:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; }) & (u32)(4294901759))); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @297_4fdd20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; });  // @298_4fdd20
  L4fe048:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 77), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @300_4fdd20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @301_4fdd20
  if (FL[0] == FL[1]) goto L4fe068;  // @302_4fdd20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; }) | (u32)(4194304))); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @303_4fdd20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; });  // @304_4fdd20
  ext_633654(G(u32, 0x6f5630));  // @305_4fdd20
  return eax;  // @306_4fdd20
  L4fe068:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; }) & (u32)(4290772991))); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @308_4fdd20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; });  // @309_4fdd20
  L4fe06f:;
  ext_633654(G(u32, 0x6f5630));  // @311_4fdd20
  return eax;  // @312_4fdd20
}
PCREG(4fdd20, lifted_4fdd20);

extern "C" u32 THISCALL lifted_5cdc60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5cdc60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @1_5cdc60
  ecx = esi;  // @2_5cdc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_5cdc60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) & (u32)(4294909440))); __builtin_memcpy((void *)(u32)(esi + 1047), &v, sizeof v); }  // @4_5cdc60
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; });  // @5_5cdc60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1608)))(ecx, (u32)(0));  // @6_5cdc60
  ecx = edx = 0;  // @7_5cdc60
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2847) + 0), 4); v; });  // @8_5cdc60
  X3[1] = 0;  // @9_5cdc60
  X3[2] = 0;  // @10_5cdc60
  X3[3] = 0;  // @11_5cdc60
  X2[0] = 0;  // @12_5cdc60
  X2[1] = 0;  // @13_5cdc60
  X2[2] = 0;  // @14_5cdc60
  X2[3] = 0;  // @15_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6866752) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6866752) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @16_5cdc60
  { double a_ = (double)U2F(X3[0]), b_ = (double)U2F(X3[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @17_5cdc60
  X1[0] = X1[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @18_5cdc60
  X1[1] = X1[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @19_5cdc60
  X1[2] = X1[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @20_5cdc60
  X1[3] = X1[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @21_5cdc60
  if (((!(U2D(X0[0], X0[1]) >= U2D(X1[0], X1[1]))) || (!((U2D(X0[0], X0[1]) < U2D(X1[0], X1[1])) || (U2D(X0[0], X0[1]) > U2D(X1[0], X1[1])))))) goto L5cdcb7;  // @22_5cdc60
  X3[0] = X2[0];  // @23_5cdc60
  X3[1] = X2[1];  // @24_5cdc60
  X3[2] = X2[2];  // @25_5cdc60
  X3[3] = X2[3];  // @26_5cdc60
  L5cdcb7:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2855) + 0), 4); v; });  // @28_5cdc60
  X0[1] = 0;  // @29_5cdc60
  X0[2] = 0;  // @30_5cdc60
  X0[3] = 0;  // @31_5cdc60
  ecx = (u32)(edi + 2873);  // @32_5cdc60
  __builtin_memcpy((void *)((u32)(ecx + 8) + 0), &X0[0], 4);  // @33_5cdc60
  X0[0] = X3[0];  // @34_5cdc60
  X0[1] = X3[1];  // @35_5cdc60
  X0[2] = X3[2];  // @36_5cdc60
  X0[3] = X3[3];  // @37_5cdc60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 96) + 12), &v, sizeof v); }  // @38_5cdc60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @39_5cdc60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 96) + 16), &v, sizeof v); }  // @40_5cdc60
  __builtin_memcpy((void *)((u32)(ecx) + 0), &X3[0], 4);  // @41_5cdc60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @42_5cdc60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @43_5cdc60
  if (!__builtin_parity(FL[2] & 0xff)) goto L5cdd0a;  // @44_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; });  // @45_5cdc60
  X0[1] = 0;  // @46_5cdc60
  X0[2] = 0;  // @47_5cdc60
  X0[3] = 0;  // @48_5cdc60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @49_5cdc60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @50_5cdc60
  if (!__builtin_parity(FL[2] & 0xff)) goto L5cdd0a;  // @51_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; });  // @52_5cdc60
  X0[1] = 0;  // @53_5cdc60
  X0[2] = 0;  // @54_5cdc60
  X0[3] = 0;  // @55_5cdc60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @56_5cdc60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @57_5cdc60
  if (!__builtin_parity(FL[2] & 0xff)) goto L5cdd0a;  // @58_5cdc60
  X0[0] = X2[0];  // @59_5cdc60
  X0[1] = X2[1];  // @60_5cdc60
  X0[2] = X2[2];  // @61_5cdc60
  X0[3] = X2[3];  // @62_5cdc60
  goto L5cdd50;  // @63_5cdc60
  L5cdd0a:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 96) + 8), &v, sizeof v); }  // @65_5cdc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 16), sizeof v); (u32)v; });  // @66_5cdc60
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @67_5cdc60
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @68_5cdc60
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @69_5cdc60
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @70_5cdc60
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @71_5cdc60
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @72_5cdc60
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @73_5cdc60
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @74_5cdc60
  __asm__ volatile("fsqrt" ::: "st");  // @75_5cdc60
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 8)) : "st");  // @76_5cdc60
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @77_5cdc60
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @78_5cdc60
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @79_5cdc60
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @80_5cdc60
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @81_5cdc60
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @82_5cdc60
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @83_5cdc60
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @84_5cdc60
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @85_5cdc60
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @86_5cdc60
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 8)) :: "st");  // @87_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 8) + 0), 4); v; });  // @88_5cdc60
  X0[1] = 0;  // @89_5cdc60
  X0[2] = 0;  // @90_5cdc60
  X0[3] = 0;  // @91_5cdc60
  L5cdd50:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2859) + 0), 4); v; });  // @93_5cdc60
  X1[1] = 0;  // @94_5cdc60
  X1[2] = 0;  // @95_5cdc60
  X1[3] = 0;  // @96_5cdc60
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @97_5cdc60
  __builtin_memcpy((void *)((u32)(edi + 2869) + 0), &X0[0], 4);  // @98_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2855) + 0), 4); v; });  // @99_5cdc60
  X0[1] = 0;  // @100_5cdc60
  X0[2] = 0;  // @101_5cdc60
  X0[3] = 0;  // @102_5cdc60
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @103_5cdc60
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @104_5cdc60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @105_5cdc60
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @106_5cdc60
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @107_5cdc60
  ecx = edx = 0;  // @108_5cdc60
  X3[0] = 0;  // @109_5cdc60
  X3[1] = 0;  // @110_5cdc60
  X3[2] = 0;  // @111_5cdc60
  X3[3] = 0;  // @112_5cdc60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2841), &v, sizeof v); }  // @113_5cdc60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1536), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @114_5cdc60
  X3[0] = F2U((float)U2D(X0[0], X0[1]));  // @115_5cdc60
  if (FL[0] == FL[1]) goto L5ce090;  // @116_5cdc60
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) & (u32)(512));  // @117_5cdc60
  if (FL[2] != 0) goto L5ce090;  // @118_5cdc60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1647), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @119_5cdc60
  if (FL[0] == FL[1]) goto L5cdddc;  // @120_5cdc60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2869), &v, sizeof v); }  // @121_5cdc60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2873), &v, sizeof v); }  // @122_5cdc60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2877), &v, sizeof v); }  // @123_5cdc60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2881), &v, sizeof v); }  // @124_5cdc60
  L5cdddc:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2869) + 0), 4); v; });  // @126_5cdc60
  X0[1] = 0;  // @127_5cdc60
  X0[2] = 0;  // @128_5cdc60
  X0[3] = 0;  // @129_5cdc60
  X1[0] = 0;  // @130_5cdc60
  X1[1] = 0;  // @131_5cdc60
  X1[2] = 0;  // @132_5cdc60
  X1[3] = 0;  // @133_5cdc60
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5cde95;  // @134_5cdc60
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 2841), &v, sizeof v); }  // @135_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2059) + 0), 4); v; });  // @136_5cdc60
  X0[1] = 0;  // @137_5cdc60
  X0[2] = 0;  // @138_5cdc60
  X0[3] = 0;  // @139_5cdc60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @140_5cdc60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @141_5cdc60
  if (!__builtin_parity(FL[2] & 0xff)) goto L5cde25;  // @142_5cdc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @143_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @144_5cdc60
  X0[0] = F2U((float)(s32)X0[0]);  // @145_5cdc60
  X0[1] = F2U((float)(s32)X0[1]);  // @146_5cdc60
  X0[2] = F2U((float)(s32)X0[2]);  // @147_5cdc60
  X0[3] = F2U((float)(s32)X0[3]);  // @148_5cdc60
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @149_5cdc60
  __builtin_memcpy((void *)((u32)(esi + 2059) + 0), &X0[0], 4);  // @150_5cdc60
  L5cde25:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2869) + 0), 4); v; });  // @152_5cdc60
  X0[1] = 0;  // @153_5cdc60
  X0[2] = 0;  // @154_5cdc60
  X0[3] = 0;  // @155_5cdc60
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; });  // @156_5cdc60
  X2[1] = 0;  // @157_5cdc60
  X2[2] = 0;  // @158_5cdc60
  X2[3] = 0;  // @159_5cdc60
  if ((!(!(U2F(X0[0]) >= U2F(X2[0]))) && !(!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L5cde3f;  // @160_5cdc60
  if (((!(U2F(X3[0]) >= U2F(X2[0]))) || (!((U2F(X3[0]) < U2F(X2[0])) || (U2F(X3[0]) > U2F(X2[0])))))) goto L5cde57;  // @161_5cdc60
  L5cde3f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; });  // @163_5cdc60
  FL[2] = (eax & (u32)(67108864));  // @164_5cdc60
  if (FL[2] != 0) goto L5cde57;  // @165_5cdc60
  eax = (eax | (u32)(2));  // @166_5cdc60
  FL[3] = eax;  // @167_5cdc60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1047), &v, sizeof v); }  // @168_5cdc60
  goto L5cde5e;  // @169_5cdc60
  L5cde57:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(esi + 1047), &v, sizeof v); }  // @171_5cdc60
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; });  // @172_5cdc60
  L5cde5e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @174_5cdc60
  X0[1] = 0;  // @175_5cdc60
  X0[2] = 0;  // @176_5cdc60
  X0[3] = 0;  // @177_5cdc60
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; }))))))) goto L5cde76;  // @178_5cdc60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 1047), &v, sizeof v); }  // @179_5cdc60
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; });  // @180_5cdc60
  L5cde76:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; });  // @182_5cdc60
  FL[2] = (eax & (u32)(4194304));  // @183_5cdc60
  if (FL[2] == 0) goto L5cde95;  // @184_5cdc60
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; }))))))) goto L5cde95;  // @185_5cdc60
  eax = (eax | (u32)(4));  // @186_5cdc60
  FL[3] = eax;  // @187_5cdc60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1047), &v, sizeof v); }  // @188_5cdc60
  L5cde95:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @190_5cdc60
  ecx = (u32)((EBP - 96) + 80);  // @191_5cdc60
  PV[0] = (u32)(ecx);  // @192_5cdc60
  ecx = (u32)((EBP - 100) + 48);  // @193_5cdc60
  PV[1] = (u32)(ecx);  // @194_5cdc60
  ecx = esi;  // @195_5cdc60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[1], PV[0]);  // @196_5cdc60
  ecx = edx = 0;  // @197_5cdc60
  ecx = (u32)((EBP - 96) + 44);  // @198_5cdc60
  eax = ext_4e09b0_thiscall1(ecx);  // @199_5cdc60
    // @200_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2873) + 0), 4); v; });  // @201_5cdc60
  X0[1] = 0;  // @202_5cdc60
  X0[2] = 0;  // @203_5cdc60
  X0[3] = 0;  // @204_5cdc60
  X1[0] = 0;  // @205_5cdc60
  X1[1] = 0;  // @206_5cdc60
  X1[2] = 0;  // @207_5cdc60
  X1[3] = 0;  // @208_5cdc60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @209_5cdc60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @210_5cdc60
  if (!__builtin_parity(FL[2] & 0xff)) goto L5cdf06;  // @211_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2877) + 0), 4); v; });  // @212_5cdc60
  X0[1] = 0;  // @213_5cdc60
  X0[2] = 0;  // @214_5cdc60
  X0[3] = 0;  // @215_5cdc60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @216_5cdc60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @217_5cdc60
  if (!__builtin_parity(FL[2] & 0xff)) goto L5cdf06;  // @218_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; });  // @219_5cdc60
  X0[1] = 0;  // @220_5cdc60
  X0[2] = 0;  // @221_5cdc60
  X0[3] = 0;  // @222_5cdc60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @223_5cdc60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @224_5cdc60
  if (!__builtin_parity(FL[2] & 0xff)) goto L5cdf06;  // @225_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3209) + 0), 4); v; });  // @226_5cdc60
  X0[1] = 0;  // @227_5cdc60
  X0[2] = 0;  // @228_5cdc60
  X0[3] = 0;  // @229_5cdc60
  __builtin_memcpy((void *)((u32)((EBP - 96) + 32) + 0), &X0[0], 4);  // @230_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3217) + 0), 4); v; });  // @231_5cdc60
  X0[1] = 0;  // @232_5cdc60
  X0[2] = 0;  // @233_5cdc60
  X0[3] = 0;  // @234_5cdc60
  __builtin_memcpy((void *)((u32)((EBP - 96) + 40) + 0), &X0[0], 4);  // @235_5cdc60
  goto L5cdf36;  // @236_5cdc60
  L5cdf06:;
  eax = (u32)(edi + 3209);  // @238_5cdc60
  PV[2] = (u32)(eax);  // @239_5cdc60
  edx = (u32)(edi + 2873);  // @240_5cdc60
  ecx = (u32)((EBP - 100) + 36);  // @241_5cdc60
  eax = ext_441970_fastcall3(ecx, edx, PV[2]);  // @242_5cdc60
  ecx = edx = 0;  // @243_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @244_5cdc60
  X0[1] = 0;  // @245_5cdc60
  X0[2] = 0;  // @246_5cdc60
  X0[3] = 0;  // @247_5cdc60
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2881) + 0), 4); v; }))))))) goto L5cdf36;  // @248_5cdc60
  ecx = (u32)((EBP - 96) + 32);  // @249_5cdc60
  eax = ext_4e09b0_thiscall1(ecx);  // @250_5cdc60
    // @251_5cdc60
  L5cdf36:;
  ecx = (u32)((EBP - 96) + 32);  // @253_5cdc60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 96) + 36), &v, sizeof v); }  // @254_5cdc60
  eax = ext_44c840_thiscall1(ecx);  // @255_5cdc60
  ecx = 0;  // @256_5cdc60
  edx = (u32)(edi + 3209);  // @257_5cdc60
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @258_5cdc60
  ecx = (u32)(edi + 2873);  // @259_5cdc60
  eax = ext_4419f0_fastcall2(ecx, edx);  // @260_5cdc60
  ecx = edx = 0;  // @261_5cdc60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2877), &v, sizeof v); }  // @262_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 2869) + 0), 4); v; });  // @263_5cdc60
  X0[1] = 0;  // @264_5cdc60
  X0[2] = 0;  // @265_5cdc60
  X0[3] = 0;  // @266_5cdc60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 12), sizeof v); (u32)v; });  // @267_5cdc60
  PV[3] = (u32)(ecx);  // @268_5cdc60
  ecx = edi;  // @269_5cdc60
  PV[4] = X0[0];  // @270_5cdc60
  eax = ext_4e0d80_thiscall2(ecx, PV[4]);  // @271_5cdc60
  ecx = edx = 0;  // @272_5cdc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @273_5cdc60
  ecx = esi;  // @274_5cdc60
  PV[5] = (u32)(edi);  // @275_5cdc60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1472)))(ecx, PV[5]);  // @276_5cdc60
  ecx = edx = 0;  // @277_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 44) + 0), 4); v; });  // @278_5cdc60
  X0[1] = 0;  // @279_5cdc60
  X0[2] = 0;  // @280_5cdc60
  X0[3] = 0;  // @281_5cdc60
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 32) + 0), 4); v; })));  // @282_5cdc60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 48) + 0), 4); v; });  // @283_5cdc60
  X1[1] = 0;  // @284_5cdc60
  X1[2] = 0;  // @285_5cdc60
  X1[3] = 0;  // @286_5cdc60
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 36) + 0), 4); v; })));  // @287_5cdc60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @288_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 52) + 0), 4); v; });  // @289_5cdc60
  X0[1] = 0;  // @290_5cdc60
  X0[2] = 0;  // @291_5cdc60
  X0[3] = 0;  // @292_5cdc60
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 40) + 0), 4); v; })));  // @293_5cdc60
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @294_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6816064) + 0), 4); v; });  // @295_5cdc60
  X0[1] = 0;  // @296_5cdc60
  X0[2] = 0;  // @297_5cdc60
  X0[3] = 0;  // @298_5cdc60
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5ce090;  // @299_5cdc60
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) & (u32)(4194304));  // @300_5cdc60
  if (FL[2] != 0) goto L5ce090;  // @301_5cdc60
  PV[6] = (u32)(ecx);  // @302_5cdc60
  PV[7] = X1[0];  // @303_5cdc60
  eax = ext_477620_stdcall1(PV[7]);  // @304_5cdc60
  ecx = edx = 0;  // @305_5cdc60
  eax = (u32)((EBP - 96) + 32);  // @306_5cdc60
  PV[8] = (u32)(eax);  // @307_5cdc60
  edx = (u32)((EBP - 100) + 48);  // @308_5cdc60
  ecx = (u32)((EBP - 100) + 24);  // @309_5cdc60
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 100) + 16)) :: "st");  // @310_5cdc60
  eax = ext_446ee0_fastcall3(ecx, edx, PV[8]);  // @311_5cdc60
  ecx = edx = 0;  // @312_5cdc60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 24) + 0), 4); v; });  // @313_5cdc60
  X0[1] = 0;  // @314_5cdc60
  X0[2] = 0;  // @315_5cdc60
  X0[3] = 0;  // @316_5cdc60
  X1[0] = 0;  // @317_5cdc60
  X1[1] = 0;  // @318_5cdc60
  X1[2] = 0;  // @319_5cdc60
  X1[3] = 0;  // @320_5cdc60
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5ce00d;  // @321_5cdc60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) | (u32)(64))); __builtin_memcpy((void *)(u32)(esi + 1047), &v, sizeof v); }  // @322_5cdc60
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; });  // @323_5cdc60
  goto L5ce014;  // @324_5cdc60
  L5ce00d:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 1047), &v, sizeof v); }  // @326_5cdc60
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; });  // @327_5cdc60
  L5ce014:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; });  // @329_5cdc60
  eax = (eax >> (u32)(27));  // @330_5cdc60
  FL[3] = eax;  // @331_5cdc60
  FL[2] = ((eax & 0xff) & (u32)(1));  // @332_5cdc60
  if (FL[2] == 0) goto L5ce02b;  // @333_5cdc60
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6945228) + 0), 4); v; });  // @334_5cdc60
  X3[1] = 0;  // @335_5cdc60
  X3[2] = 0;  // @336_5cdc60
  X3[3] = 0;  // @337_5cdc60
  goto L5ce033;  // @338_5cdc60
  L5ce02b:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; });  // @340_5cdc60
  X3[1] = 0;  // @341_5cdc60
  X3[2] = 0;  // @342_5cdc60
  X3[3] = 0;  // @343_5cdc60
  L5ce033:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @345_5cdc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @346_5cdc60
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }));  // @347_5cdc60
  FL[3] = ecx;  // @348_5cdc60
  X2[0] = ecx; X2[1] = X2[2] = X2[3] = 0;  // @349_5cdc60
  X2[0] = F2U((float)(s32)X2[0]);  // @350_5cdc60
  X2[1] = F2U((float)(s32)X2[1]);  // @351_5cdc60
  X2[2] = F2U((float)(s32)X2[2]);  // @352_5cdc60
  X2[3] = F2U((float)(s32)X2[3]);  // @353_5cdc60
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @354_5cdc60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @355_5cdc60
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @356_5cdc60
  if (!__builtin_parity(FL[2] & 0xff)) goto L5ce05e;  // @357_5cdc60
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; });  // @358_5cdc60
  X2[1] = 0;  // @359_5cdc60
  X2[2] = 0;  // @360_5cdc60
  X2[3] = 0;  // @361_5cdc60
  L5ce05e:;
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @363_5cdc60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @364_5cdc60
  X1[1] = 0;  // @365_5cdc60
  X1[2] = 0;  // @366_5cdc60
  X1[3] = 0;  // @367_5cdc60
  X3[0] = F2U(U2F(X3[0]) * U2F(X2[0]));  // @368_5cdc60
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @369_5cdc60
  { float a_ = U2F(X1[0]), b_ = U2F(X3[0]); X1[0] = (a_ < b_) ? X1[0] : F2U(b_); }  // @370_5cdc60
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 96) + 12) + 0), 4); v; })));  // @371_5cdc60
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @372_5cdc60
  __builtin_memcpy((void *)((u32)(esi + 2063) + 0), &X1[0], 4);  // @373_5cdc60
  L5ce090:;
  ext_633654(G(u32, 0x6f5630));  // @375_5cdc60
  return eax;  // @376_5cdc60
}
PCREG(5cdc60, lifted_5cdc60);

extern "C" u32 THISCALL lifted_477a30(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_477a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @1_477a30
  eax = ext_4db3b0_thiscall1(ecx);  // @2_477a30
  ecx = edx = 0;  // @3_477a30
  FL[2] = (eax & eax);  // @4_477a30
  if (FL[2] == 0) goto L477a63;  // @5_477a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_477a30
  PV[0] = (u32)(eax);  // @7_477a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @8_477a30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[0]);  // @10_477a30
  ecx = edx = 0;  // @11_477a30
  goto L477a79;  // @12_477a30
  L477a63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_477a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_477a30
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; });  // @17_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @18_477a30
  ecx = edx = 0;  // @19_477a30
  L477a79:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1846), &v, sizeof v); }  // @21_477a30
  ecx = edi;  // @22_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; });  // @23_477a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 101), &v, sizeof v); }  // @24_477a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 593), &v, sizeof v); }  // @25_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 764), sizeof v); (u32)v; });  // @27_477a30
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @28_477a30
  ecx = edx = 0;  // @29_477a30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @30_477a30
  if (FL[2] != 0) goto L477d8e;  // @31_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_477a30
  ecx = edi;  // @33_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1416)))(ecx);  // @34_477a30
  ecx = edx = 0;  // @35_477a30
  FL[2] = (eax & eax);  // @36_477a30
  if (FL[2] == 0) goto L477d8e;  // @37_477a30
  ecx = (u32)(6856872);  // @38_477a30
  eax = ext_441730_thiscall1(ecx);  // @39_477a30
  ecx = edx = 0;  // @40_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @41_477a30
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @42_477a30
  X1[1] = 0;  // @43_477a30
  X1[2] = 0;  // @44_477a30
  X1[3] = 0;  // @45_477a30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @46_477a30
  esi = edx;  // @47_477a30
  esi = (esi & (u32)(2048));  // @48_477a30
  FL[3] = esi;  // @49_477a30
  if (FL[3] == 0) goto L477b2a;  // @50_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_477a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338580) + 0), 4); v; });  // @52_477a30
  X0[1] = 0;  // @53_477a30
  X0[2] = 0;  // @54_477a30
  X0[3] = 0;  // @55_477a30
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @56_477a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @57_477a30
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @58_477a30
  FL[0] = eax; FL[1] = ecx;  // @59_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338576), sizeof v); (u32)v; });  // @60_477a30
  if (FL[0] == FL[1]) goto L477b22;  // @61_477a30
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @62_477a30
  eax = (eax + 1);  // @63_477a30
  FL[3] = eax;  // @64_477a30
  X0[0] = F2U((float)(s32)X0[0]);  // @65_477a30
  X0[1] = F2U((float)(s32)X0[1]);  // @66_477a30
  X0[2] = F2U((float)(s32)X0[2]);  // @67_477a30
  X0[3] = F2U((float)(s32)X0[3]);  // @68_477a30
  ecx = 0;  // @69_477a30
  FL[3] = ecx;  // @70_477a30
  FL[0] = eax; FL[1] = (u32)(8);  // @71_477a30
  if (FL[0] == FL[1]) eax = ecx;  // @72_477a30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7338576), &v, sizeof v); }  // @73_477a30
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @74_477a30
  __builtin_memcpy((void *)((u32)(7338580) + 0), &X0[0], 4);  // @75_477a30
  L477b22:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1486), sizeof v); (u32)v; }); FL[1] = eax;  // @77_477a30
  FL[2] = (FL[0] == FL[1]) ? 0 : 1; goto L477b8c;  // @78_477a30 (w3h hand fix: the je at 477b8c tests the cmp flags of 477b22 on this path)
  L477b2a:;
  FL[2] = (edx & (u32)(4096));  // @80_477a30
  if (FL[2] != 0) goto L477ba8;  // @81_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_477a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338588) + 0), 4); v; });  // @83_477a30
  X0[1] = 0;  // @84_477a30
  X0[2] = 0;  // @85_477a30
  X0[3] = 0;  // @86_477a30
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @87_477a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @88_477a30
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @89_477a30
  FL[0] = eax; FL[1] = ecx;  // @90_477a30
  if (FL[0] == FL[1]) goto L477b7c;  // @91_477a30
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @92_477a30
  eax = 0;  // @93_477a30
  FL[3] = eax;  // @94_477a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338584), sizeof v); (u32)v; });  // @95_477a30
  X0[0] = F2U((float)(s32)X0[0]);  // @96_477a30
  X0[1] = F2U((float)(s32)X0[1]);  // @97_477a30
  X0[2] = F2U((float)(s32)X0[2]);  // @98_477a30
  X0[3] = F2U((float)(s32)X0[3]);  // @99_477a30
  ecx = (ecx + 1);  // @100_477a30
  FL[3] = ecx;  // @101_477a30
  FL[0] = ecx; FL[1] = (u32)(8);  // @102_477a30
  if (FL[0] == FL[1]) ecx = eax;  // @103_477a30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7338584), &v, sizeof v); }  // @104_477a30
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @105_477a30
  __builtin_memcpy((void *)((u32)(7338588) + 0), &X0[0], 4);  // @106_477a30
  goto L477b82;  // @107_477a30
  L477b7c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338584), sizeof v); (u32)v; });  // @109_477a30
  L477b82:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1486), sizeof v); (u32)v; });  // @111_477a30
  eax = (eax ^ ecx);  // @112_477a30
  FL[3] = eax;  // @113_477a30
  FL[2] = ((eax & 0xff) & (u32)(1));  // @114_477a30
  L477b8c:;
  if (FL[2] == 0) goto L477ba8;  // @116_477a30
  ecx = (u32)(6856872);  // @117_477a30
  eax = ext_440530_thiscall1(ecx);  // @118_477a30
  ecx = edx = 0;  // @119_477a30
  ext_633654(G(u32, 0x6f5630));  // @120_477a30
  return eax;  // @121_477a30
  L477ba8:;
  FL[2] = (esi & esi);  // @123_477a30
  if (FL[2] != 0) goto L477bb9;  // @124_477a30
  FL[2] = (edx & (u32)(4096));  // @125_477a30
  if (FL[2] == 0) goto L477bb9;  // @126_477a30
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @127_477a30
  goto L477bbb;  // @128_477a30
  L477bb9:;
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @130_477a30
  FL[3] = (ebx & 0xff);  // @131_477a30
  L477bbb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @133_477a30
  ecx = edi;  // @134_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 840)))(ecx);  // @135_477a30
  ecx = edx = 0;  // @136_477a30
  ecx = edi;  // @137_477a30
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @138_477a30
  if (FL[2] == 0) goto L477bd2;  // @139_477a30
  eax = ext_47d290_thiscall1(ecx);  // @140_477a30
  ecx = edx = 0;  // @141_477a30
  goto L477bd7;  // @142_477a30
  L477bd2:;
  eax = ext_47e5e0_thiscall1(ecx);  // @144_477a30
  ecx = edx = 0;  // @145_477a30
  L477bd7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @147_477a30
  ecx = edi;  // @148_477a30
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 8)) :: "st");  // @149_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 992)))(ecx);  // @150_477a30
  ecx = edx = 0;  // @151_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @152_477a30
  ecx = edi;  // @153_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1040)))(ecx);  // @154_477a30
  ecx = edx = 0;  // @155_477a30
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1830), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @156_477a30
  if (FL[0] == FL[1]) goto L477c3b;  // @157_477a30
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1722) + 0), 4); v; });  // @158_477a30
  X2[1] = 0;  // @159_477a30
  X2[2] = 0;  // @160_477a30
  X2[3] = 0;  // @161_477a30
  X1[0] = 0;  // @162_477a30
  X1[1] = 0;  // @163_477a30
  X1[2] = 0;  // @164_477a30
  X1[3] = 0;  // @165_477a30
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L477c3b;  // @166_477a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1826) + 0), 4); v; });  // @167_477a30
  X0[1] = 0;  // @168_477a30
  X0[2] = 0;  // @169_477a30
  X0[3] = 0;  // @170_477a30
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @171_477a30
  { float a_ = U2F(X1[0]), b_ = U2F(X0[0]); X1[0] = (a_ > b_) ? X1[0] : F2U(b_); }  // @172_477a30
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L477c3b;  // @173_477a30
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1726), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @174_477a30
  if (FL[0] == FL[1]) goto L477c31;  // @175_477a30
  ecx = edi;  // @176_477a30
  eax = ext_479090_thiscall1(ecx);  // @177_477a30
  ecx = edx = 0;  // @178_477a30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @179_477a30
  if (FL[2] == 0) goto L477c3b;  // @180_477a30
  L477c31:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @182_477a30
  ecx = edi;  // @183_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1616)))(ecx);  // @184_477a30
  ecx = edx = 0;  // @185_477a30
  L477c3b:;
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @187_477a30
  if (FL[2] == 0) goto L477d46;  // @188_477a30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1608), sizeof v); (u32)v; });  // @189_477a30
  FL[2] = (edx & edx);  // @190_477a30
  if (FL[2] == 0) goto L477cd9;  // @191_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @192_477a30
  PV[2] = (u32)(edx);  // @193_477a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @194_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @195_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[2]);  // @196_477a30
  ecx = edx = 0;  // @197_477a30
  ebx = eax;  // @198_477a30
  FL[2] = (ebx & ebx);  // @199_477a30
  if (FL[2] == 0) goto L477cd9;  // @200_477a30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @201_477a30
  ecx = ebx;  // @202_477a30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @203_477a30
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2097191));  // @204_477a30
  ecx = edx = 0;  // @205_477a30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @206_477a30
  if (FL[2] == 0) goto L477c9a;  // @207_477a30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @208_477a30
  eax = (u32)(EBP - 16);  // @209_477a30
  PV[3] = (u32)(eax);  // @210_477a30
  eax = (u32)(EBP - 52);  // @211_477a30
  ecx = ebx;  // @212_477a30
  PV[4] = (u32)(eax);  // @213_477a30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 928)))(ecx, PV[4], PV[3]);  // @214_477a30
  ecx = edx = 0;  // @215_477a30
  PV[5] = (u32)(eax);  // @216_477a30
  ecx = ebx;  // @217_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[5]);  // @218_477a30
  ecx = edx = 0;  // @219_477a30
  goto L477caf;  // @220_477a30
  L477c9a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @222_477a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @223_477a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @224_477a30
  L477caf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @226_477a30
  ecx = (u32)(EBP - 16);  // @227_477a30
  PV[6] = (u32)(ecx);  // @228_477a30
  ecx = ebx;  // @229_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[6]);  // @230_477a30
  ecx = edx = 0;  // @231_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @232_477a30
  ecx = (u32)(EBP - 16);  // @233_477a30
  PV[7] = (u32)(ecx);  // @234_477a30
  ecx = edi;  // @235_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[7]);  // @236_477a30
  ecx = edx = 0;  // @237_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @238_477a30
  ecx = (u32)(EBP - 16);  // @239_477a30
  PV[8] = (u32)(ecx);  // @240_477a30
  ecx = edi;  // @241_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 924)))(ecx, PV[8]);  // @242_477a30
  ecx = edx = 0;  // @243_477a30
  L477cd9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @245_477a30
  ecx = edi;  // @246_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1008)))(ecx);  // @247_477a30
  ecx = edx = 0;  // @248_477a30
  FL[2] = (eax & eax);  // @249_477a30
  if (FL[2] != 0) goto L477d46;  // @250_477a30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @251_477a30
  ecx = edi;  // @252_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(esi + 1280)))(ecx);  // @253_477a30
  ecx = edx = 0;  // @254_477a30
  PV[9] = (u32)(eax);  // @255_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @256_477a30
  ecx = edi;  // @257_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1284)))(ecx, PV[9]);  // @258_477a30
  ecx = edx = 0;  // @259_477a30
  PV[10] = (u32)(eax);  // @260_477a30
  ecx = edi;  // @261_477a30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1688)))(ecx, PV[10]);  // @262_477a30
  ecx = edx = 0;  // @263_477a30
  ebx = eax;  // @264_477a30
  FL[2] = (ebx & ebx);  // @265_477a30
  if (FL[2] == 0) goto L477d46;  // @266_477a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1877) + 0), 4); v; });  // @267_477a30
  X0[1] = 0;  // @268_477a30
  X0[2] = 0;  // @269_477a30
  X0[3] = 0;  // @270_477a30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @271_477a30
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @272_477a30
  PV[11] = (u32)(ecx);  // @273_477a30
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @274_477a30
  __builtin_memcpy((void *)((u32)(EBP - 12) + 4), &X0[1], 4);  // @275_477a30
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 12)) : "st");  // @276_477a30
  __asm__ volatile("fld1" ::: "st");  // @277_477a30
  __asm__ volatile("call *%0" :: "m"(*(u32 *)0x676358) : "eax", "ecx", "edx", "memory", "st");  // @278_477a30 (w3h hand fix: _CIpow takes st(1), st(0) in x87 registers, the three pushes belong to the slot +0x244 call)
    // @279_477a30
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 8)) :: "st");  // @280_477a30
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 8)) : "st");  // @281_477a30
  PV[12] = (u32)(ecx);  // @282_477a30
  { float f_; __asm__ volatile("fstps %0" : "=m"(f_) :: "st"); PV[13] = F2U(f_); }  // @283_477a30
  PV[14] = (u32)(ebx);  // @284_477a30
  ecx = edi;  // @285_477a30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 580)))(ecx, PV[14], PV[13], (u32)(0x3f800000), (u32)(0), (u32)(1));  // @286_477a30 (w3h hand fix: 5 stack args)
  ecx = edx = 0;  // @287_477a30
  L477d46:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1876), &v, sizeof v); }  // @289_477a30
  ecx = (u32)(6856872);  // @290_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @291_477a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @292_477a30
  X0[0] = F2U((float)(s32)X0[0]);  // @293_477a30
  X0[1] = F2U((float)(s32)X0[1]);  // @294_477a30
  X0[2] = F2U((float)(s32)X0[2]);  // @295_477a30
  X0[3] = F2U((float)(s32)X0[3]);  // @296_477a30
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @297_477a30
  __builtin_memcpy((void *)((u32)(edi + 1604) + 0), &X0[0], 4);  // @298_477a30
  eax = ext_440530_thiscall1(ecx);  // @299_477a30
  ecx = edx = 0;  // @300_477a30
  ecx = edi;  // @301_477a30
  eax = ext_47b290_thiscall2(ecx, (u32)(0));  // @302_477a30
  ecx = edx = 0;  // @303_477a30
  ext_633654(G(u32, 0x6f5630));  // @304_477a30
  return eax;  // @305_477a30
  L477d8e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @307_477a30
  ecx = edi;  // @308_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 868)))(ecx);  // @309_477a30
  ecx = edx = 0;  // @310_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @311_477a30
  ecx = edi;  // @312_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1416)))(ecx);  // @313_477a30
  ecx = edx = 0;  // @314_477a30
  ecx = edi;  // @315_477a30
  FL[2] = (eax & eax);  // @316_477a30
  if (FL[2] != 0) goto L477dc8;  // @317_477a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @318_477a30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 840)))(ecx);  // @319_477a30
  ecx = edx = 0;  // @320_477a30
  ecx = edi;  // @321_477a30
  eax = ext_47d290_thiscall1(ecx);  // @322_477a30
  ecx = edx = 0;  // @323_477a30
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @324_477a30
  ext_633654(G(u32, 0x6f5630));  // @325_477a30
  return eax;  // @326_477a30
  L477dc8:;
  eax = ext_465fb0_thiscall1(ecx);  // @328_477a30
  ecx = edx = 0;  // @329_477a30
  ext_633654(G(u32, 0x6f5630));  // @330_477a30
  return eax;  // @331_477a30
}
PCREG(477a30, lifted_477a30);

