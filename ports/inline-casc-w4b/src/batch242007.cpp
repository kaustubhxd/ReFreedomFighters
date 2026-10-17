// batch242007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d76_dbl(double) __asm__("ext_634d76");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4dfd80_fastcall2(u32, u32) __asm__("ext_4dfd80");
extern "C" u32 FASTCALL ext_4e0940_fastcall3(u32, u32, u32) __asm__("ext_4e0940");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_53fd10_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_53fd10");
extern "C" u32 FASTCALL ext_547860_fastcall3(u32, u32, u32) __asm__("ext_547860");
extern "C" u32 THISCALL ext_4c7ca0_thiscall1(u32) __asm__("ext_4c7ca0");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db2c0_thiscall3(u32, u32, u32) __asm__("ext_4db2c0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_5407c0_thiscall1(u32) __asm__("ext_5407c0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4bd4a0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4bd4a0
  edi = ecx;  // @1_4bd4a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_4bd4a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_4bd4a0
  if (FL[0] == FL[1]) goto L4bd71b;  // @4_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 124) + 0), 4); v; });  // @5_4bd4a0
  X0[1] = 0;  // @6_4bd4a0
  X0[2] = 0;  // @7_4bd4a0
  X0[3] = 0;  // @8_4bd4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @9_4bd4a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @10_4bd4a0
  ecx = edx;  // @11_4bd4a0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @12_4bd4a0
  X2[1] = 0;  // @13_4bd4a0
  X2[2] = 0;  // @14_4bd4a0
  X2[3] = 0;  // @15_4bd4a0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @16_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 128) + 0), 4); v; });  // @17_4bd4a0
  X0[1] = 0;  // @18_4bd4a0
  X0[2] = 0;  // @19_4bd4a0
  X0[3] = 0;  // @20_4bd4a0
  ecx = (ecx - eax);  // @21_4bd4a0
  FL[3] = ecx;  // @22_4bd4a0
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @23_4bd4a0
  X1[0] = F2U((float)(s32)X1[0]);  // @24_4bd4a0
  X1[1] = F2U((float)(s32)X1[1]);  // @25_4bd4a0
  X1[2] = F2U((float)(s32)X1[2]);  // @26_4bd4a0
  X1[3] = F2U((float)(s32)X1[3]);  // @27_4bd4a0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @28_4bd4a0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @29_4bd4a0
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))))) goto L4bd71b;  // @30_4bd4a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 120), sizeof v); (u32)v; });  // @31_4bd4a0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 132) + 0), 4); v; });  // @32_4bd4a0
  X3[1] = 0;  // @33_4bd4a0
  X3[2] = 0;  // @34_4bd4a0
  X3[3] = 0;  // @35_4bd4a0
  X0[0] = edx; X0[1] = X0[2] = X0[3] = 0;  // @36_4bd4a0
  X0[0] = F2U((float)(s32)X0[0]);  // @37_4bd4a0
  X0[1] = F2U((float)(s32)X0[1]);  // @38_4bd4a0
  X0[2] = F2U((float)(s32)X0[2]);  // @39_4bd4a0
  X0[3] = F2U((float)(s32)X0[3]);  // @40_4bd4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @41_4bd4a0
  __builtin_memcpy((void *)((u32)(edi + 124) + 0), &X0[0], 4);  // @42_4bd4a0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @43_4bd4a0
  X0[0] = F2U((float)(s32)X0[0]);  // @44_4bd4a0
  X0[1] = F2U((float)(s32)X0[1]);  // @45_4bd4a0
  X0[2] = F2U((float)(s32)X0[2]);  // @46_4bd4a0
  X0[3] = F2U((float)(s32)X0[3]);  // @47_4bd4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @48_4bd4a0
  if ((!(U2F(X3[0]) >= U2F(X0[0])))) goto L4bd64c;  // @49_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @50_4bd4a0
  eax = (eax - (u32)(0));  // @51_4bd4a0
  FL[3] = eax;  // @52_4bd4a0
  if (FL[3] == 0) goto L4bd575;  // @53_4bd4a0
  eax = (eax - (u32)(1));  // @54_4bd4a0
  FL[3] = eax;  // @55_4bd4a0
  if (FL[3] != 0) goto L4bd5a1;  // @56_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @57_4bd4a0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 92) + 0), 4); v; });  // @58_4bd4a0
  X2[1] = 0;  // @59_4bd4a0
  X2[2] = 0;  // @60_4bd4a0
  X2[3] = 0;  // @61_4bd4a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 96) + 0), 4); v; });  // @62_4bd4a0
  X1[1] = 0;  // @63_4bd4a0
  X1[2] = 0;  // @64_4bd4a0
  X1[3] = 0;  // @65_4bd4a0
  X0[0] = F2U((float)(s32)X0[0]);  // @66_4bd4a0
  X0[1] = F2U((float)(s32)X0[1]);  // @67_4bd4a0
  X0[2] = F2U((float)(s32)X0[2]);  // @68_4bd4a0
  X0[3] = F2U((float)(s32)X0[3]);  // @69_4bd4a0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @70_4bd4a0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @71_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @72_4bd4a0
  X0[0] = F2U((float)(s32)X0[0]);  // @73_4bd4a0
  X0[1] = F2U((float)(s32)X0[1]);  // @74_4bd4a0
  X0[2] = F2U((float)(s32)X0[2]);  // @75_4bd4a0
  X0[3] = F2U((float)(s32)X0[3]);  // @76_4bd4a0
  X1[0] = F2U(U2F(X1[0]) / U2F(X3[0]));  // @77_4bd4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @78_4bd4a0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @79_4bd4a0
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @80_4bd4a0
  __builtin_memcpy((void *)((u32)(edi + 92) + 0), &X2[0], 4);  // @81_4bd4a0
  goto L4bd5a1;  // @82_4bd4a0
  L4bd575:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @84_4bd4a0
  X1[0] = F2U((float)(s32)X1[0]);  // @85_4bd4a0
  X1[1] = F2U((float)(s32)X1[1]);  // @86_4bd4a0
  X1[2] = F2U((float)(s32)X1[2]);  // @87_4bd4a0
  X1[3] = F2U((float)(s32)X1[3]);  // @88_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @89_4bd4a0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 92) + 0), 4); v; })));  // @90_4bd4a0
  X0[0] = F2U((float)(s32)X0[0]);  // @91_4bd4a0
  X0[1] = F2U((float)(s32)X0[1]);  // @92_4bd4a0
  X0[2] = F2U((float)(s32)X0[2]);  // @93_4bd4a0
  X0[3] = F2U((float)(s32)X0[3]);  // @94_4bd4a0
  X1[0] = F2U(U2F(X1[0]) / U2F(X3[0]));  // @95_4bd4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @96_4bd4a0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @97_4bd4a0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 92) + 0), 4); v; })));  // @98_4bd4a0
  __builtin_memcpy((void *)((u32)(edi + 92) + 0), &X1[0], 4);  // @99_4bd4a0
  L4bd5a1:;
  eax = (u32)(ecx + 1);  // @101_4bd4a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 120), &v, sizeof v); }  // @102_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @103_4bd4a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @104_4bd4a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @105_4bd4a0
  FL[2] = (esi & esi);  // @106_4bd4a0
  if (FL[2] == 0) goto L4bd64b;  // @107_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_4bd4a0
  ecx = esi;  // @109_4bd4a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @110_4bd4a0
  ecx = edx = 0;  // @111_4bd4a0
  FL[2] = (eax & eax);  // @112_4bd4a0
  if (FL[2] == 0) goto L4bd64b;  // @113_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 88) + 0), 4); v; });  // @114_4bd4a0
  X0[1] = 0;  // @115_4bd4a0
  X0[2] = 0;  // @116_4bd4a0
  X0[3] = 0;  // @117_4bd4a0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 92) + 0), 4); v; })));  // @118_4bd4a0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @119_4bd4a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @120_4bd4a0
  FL[2] = (eax & eax);  // @121_4bd4a0
  if (FL[2] == 0) goto L4bd64b;  // @122_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @123_4bd4a0
  ecx = (u32)(EBP - 28);  // @124_4bd4a0
  PV[0] = (u32)(ecx);  // @125_4bd4a0
  ecx = esi;  // @126_4bd4a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @127_4bd4a0
  ecx = edx = 0;  // @128_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @129_4bd4a0
  ecx = (u32)(EBP - 28);  // @130_4bd4a0
  PV[1] = (u32)(ecx);  // @131_4bd4a0
  ecx = esi;  // @132_4bd4a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @133_4bd4a0
  ecx = edx = 0;  // @134_4bd4a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @135_4bd4a0
  if (FL[0] == FL[1]) goto L4bd645;  // @136_4bd4a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @137_4bd4a0
  L4bd600:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @139_4bd4a0
  PV[2] = (u32)(eax);  // @140_4bd4a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @141_4bd4a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @142_4bd4a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[2]);  // @143_4bd4a0
  ecx = edx = 0;  // @144_4bd4a0
  ebx = eax;  // @145_4bd4a0
  FL[2] = (ebx & ebx);  // @146_4bd4a0
  if (FL[2] == 0) goto L4bd630;  // @147_4bd4a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @148_4bd4a0
  ecx = ebx;  // @149_4bd4a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(esi + 552)))(ecx);  // @150_4bd4a0
  ecx = edx = 0;  // @151_4bd4a0
  eax = (eax + edi);  // @152_4bd4a0
  FL[3] = eax;  // @153_4bd4a0
  ecx = ebx;  // @154_4bd4a0
  PV[3] = (u32)(eax);  // @155_4bd4a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 536)))(ecx, PV[3]);  // @156_4bd4a0
  ecx = edx = 0;  // @157_4bd4a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @158_4bd4a0
  L4bd630:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_4bd4a0
  ecx = (u32)(EBP - 28);  // @161_4bd4a0
  PV[4] = (u32)(ecx);  // @162_4bd4a0
  ecx = esi;  // @163_4bd4a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @164_4bd4a0
  ecx = edx = 0;  // @165_4bd4a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @166_4bd4a0
  if (FL[0] != FL[1]) goto L4bd600;  // @167_4bd4a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @168_4bd4a0
  L4bd645:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @170_4bd4a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 88), &v, sizeof v); }  // @171_4bd4a0
  L4bd64b:;
  L4bd64c:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @174_4bd4a0
  X0[0] = F2U((float)(s32)X0[0]);  // @175_4bd4a0
  X0[1] = F2U((float)(s32)X0[1]);  // @176_4bd4a0
  X0[2] = F2U((float)(s32)X0[2]);  // @177_4bd4a0
  X0[3] = F2U((float)(s32)X0[3]);  // @178_4bd4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @179_4bd4a0
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 100) + 0), 4); v; }))))) goto L4bd718;  // @180_4bd4a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 116), &v, sizeof v); }  // @181_4bd4a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @182_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @183_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @184_4bd4a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6896704), (u32)(4294));  // @185_4bd4a0
  ecx = edx = 0;  // @186_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 104) + 0), 4); v; });  // @187_4bd4a0
  X0[1] = 0;  // @188_4bd4a0
  X0[2] = 0;  // @189_4bd4a0
  X0[3] = 0;  // @190_4bd4a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @191_4bd4a0
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; }))))) goto L4bd718;  // @192_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 108) + 0), 4); v; });  // @193_4bd4a0
  X0[1] = 0;  // @194_4bd4a0
  X0[2] = 0;  // @195_4bd4a0
  X0[3] = 0;  // @196_4bd4a0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 120), &v, sizeof v); }  // @197_4bd4a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @198_4bd4a0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @199_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @200_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @201_4bd4a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6896704), (u32)(4297));  // @202_4bd4a0
  ecx = edx = 0;  // @203_4bd4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 112) + 0), 4); v; });  // @204_4bd4a0
  X0[1] = 0;  // @205_4bd4a0
  X0[2] = 0;  // @206_4bd4a0
  X0[3] = 0;  // @207_4bd4a0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @208_4bd4a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @209_4bd4a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @210_4bd4a0
  X1[1] = 0;  // @211_4bd4a0
  X1[2] = 0;  // @212_4bd4a0
  X1[3] = 0;  // @213_4bd4a0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @214_4bd4a0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @215_4bd4a0
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @216_4bd4a0
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @217_4bd4a0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @218_4bd4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @219_4bd4a0
  X0[0] = F2U((float)(s32)X0[0]);  // @220_4bd4a0
  X0[1] = F2U((float)(s32)X0[1]);  // @221_4bd4a0
  X0[2] = F2U((float)(s32)X0[2]);  // @222_4bd4a0
  X0[3] = F2U((float)(s32)X0[3]);  // @223_4bd4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; })));  // @224_4bd4a0
  __builtin_memcpy((void *)((u32)(edi + 132) + 0), &X0[0], 4);  // @225_4bd4a0
  eax = (eax - (u32)(0));  // @226_4bd4a0
  FL[3] = eax;  // @227_4bd4a0
  if (FL[3] == 0) goto L4bd711;  // @228_4bd4a0
  eax = (eax - (u32)(1));  // @229_4bd4a0
  FL[3] = eax;  // @230_4bd4a0
  if (FL[3] != 0) goto L4bd718;  // @231_4bd4a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 116), &v, sizeof v); }  // @232_4bd4a0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; });  // @233_4bd4a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @234_4bd4a0
  return eax;  // @235_4bd4a0
  L4bd711:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @237_4bd4a0
  L4bd718:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 116), &v, sizeof v); }  // @239_4bd4a0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 116), sizeof v); (u32)v; });  // @240_4bd4a0
  L4bd71b:;
  return eax;  // @242_4bd4a0
}
PCREG(4bd4a0, lifted_4bd4a0);

extern "C" u32 THISCALL lifted_4c7790(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @3_4c7790
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(89));  // @4_4c7790
  ecx = edx = 0;  // @5_4c7790
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @6_4c7790
  if (FL[2] == 0) goto L4c77d8;  // @7_4c7790
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7340900), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_4c7790
  if (FL[0] != FL[1]) goto L4c77df;  // @9_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @10_4c7790
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(7340900), &v, sizeof v); }  // @11_4c7790
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; }) ^ (u32)(65536))); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @12_4c7790
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; });  // @13_4c7790
  goto L4c77df;  // @14_4c7790
  L4c77d8:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(7340900), &v, sizeof v); }  // @16_4c7790
  L4c77df:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @18_4c7790
  eax = ext_4c7ca0_thiscall1(ecx);  // @19_4c7790
  ecx = edx = 0;  // @20_4c7790
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @21_4c7790
  if (FL[0] == FL[1]) goto L4c79d5;  // @22_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @23_4c7790
  edx = (u32)(EBP - 16);  // @24_4c7790
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 89) + 0), 4); v; });  // @25_4c7790
  X0[1] = 0;  // @26_4c7790
  X0[2] = 0;  // @27_4c7790
  X0[3] = 0;  // @28_4c7790
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @29_4c7790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @30_4c7790
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @31_4c7790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @32_4c7790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @33_4c7790
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @34_4c7790
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @35_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4c7790
  PV[0] = (u32)(edx);  // @37_4c7790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[0]);  // @38_4c7790
  ecx = edx = 0;  // @39_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @40_4c7790
  edx = (u32)(EBP - 28);  // @41_4c7790
  PV[1] = (u32)(edx);  // @42_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_4c7790
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[1]);  // @44_4c7790
  ecx = edx = 0;  // @45_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @48_4c7790
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6900440), (u32)(449));  // @49_4c7790
  ecx = edx = 0;  // @50_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_4c7790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @52_4c7790
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 94), sizeof v); (u32)v; });  // @53_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @54_4c7790
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @55_4c7790
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 93), sizeof v); (u32)v; });  // @56_4c7790
  PV[2] = (u32)(ecx);  // @57_4c7790
  PV[3] = (u32)(eax);  // @58_4c7790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_4c7790
  eax = (u32)(EBP - 28);  // @60_4c7790
  PV[4] = (u32)(eax);  // @61_4c7790
  eax = (u32)(EBP - 16);  // @62_4c7790
  ecx = esi;  // @63_4c7790
  PV[5] = (u32)(eax);  // @64_4c7790
  eax = (u32)(EBP - 112);  // @65_4c7790
  PV[6] = (u32)(eax);  // @66_4c7790
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 48)))(ecx, PV[6], (u32)(0), PV[5], PV[4], (u32)(0), (u32)(-1), PV[3], PV[2]);  // @67_4c7790
  ecx = edx = 0;  // @68_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @71_4c7790
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6900440), (u32)(451));  // @72_4c7790
  ecx = edx = 0;  // @73_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_4c7790
  ebx = eax;  // @75_4c7790
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @76_4c7790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_4c7790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 456), sizeof v); (u32)v; });  // @78_4c7790
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6900440), (u32)(453));  // @79_4c7790
  ecx = edx = 0;  // @80_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_4c7790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @82_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @83_4c7790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @84_4c7790
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 93), sizeof v); (u32)v; });  // @85_4c7790
  PV[7] = (u32)(ecx);  // @86_4c7790
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 94), sizeof v); (u32)v; });  // @87_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @88_4c7790
  PV[8] = (u32)(ecx);  // @89_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @90_4c7790
  ecx = (u32)(EBP - 28);  // @91_4c7790
  PV[9] = (u32)(ecx);  // @92_4c7790
  ecx = (u32)(EBP - 16);  // @93_4c7790
  PV[10] = (u32)(ecx);  // @94_4c7790
  ecx = (u32)(EBP - 112);  // @95_4c7790
  PV[11] = (u32)(ecx);  // @96_4c7790
  ecx = edx;  // @97_4c7790
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[11], (u32)(0), PV[10], PV[9], (u32)(0), (u32)(-1), PV[8], PV[7]);  // @98_4c7790
  ecx = edx = 0;  // @99_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_4c7790
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 113), &v, sizeof v); }  // @101_4c7790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_4c7790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 456), sizeof v); (u32)v; });  // @103_4c7790
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6900440), (u32)(455));  // @104_4c7790
  ecx = edx = 0;  // @105_4c7790
  PV[12] = (u32)(ecx);  // @106_4c7790
  edx = (u32)(EBP - 28);  // @107_4c7790
  ecx = (u32)(EBP - 40);  // @108_4c7790
  esi = eax;  // @109_4c7790
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1065353216));  // @110_4c7790
    // @111_4c7790
  edx = (u32)(EBP - 16);  // @112_4c7790
  ecx = (u32)(EBP - 40);  // @113_4c7790
  eax = ext_441940_fastcall2(ecx, edx);  // @114_4c7790
  ecx = edx = 0;  // @115_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_4c7790
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340904), sizeof v); (u32)v; });  // @117_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @118_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @119_4c7790
  eax = (u32)(4278255360);  // @120_4c7790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @121_4c7790
  FL[2] = (edi & edi);  // @122_4c7790
  if (FL[2] != 0) goto L4c7989;  // @123_4c7790
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 113), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @124_4c7790
  edi = (u32)(4294901760);  // @125_4c7790
  if (FL[0] != FL[1]) eax = edi;  // @126_4c7790
  PV[13] = (u32)(eax);  // @127_4c7790
  eax = (u32)(EBP - 40);  // @128_4c7790
  PV[14] = (u32)(eax);  // @129_4c7790
  eax = (u32)(EBP - 16);  // @130_4c7790
  PV[15] = (u32)(eax);  // @131_4c7790
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 536)))(ecx, PV[15], PV[14], PV[13]);  // @132_4c7790
  ecx = edx = 0;  // @133_4c7790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340904), &v, sizeof v); }  // @134_4c7790
  goto L4c79a8;  // @135_4c7790
  L4c7989:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 113), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @137_4c7790
  { u32 v = (u32)((u32)(4294901760)); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @138_4c7790
  if (FL[0] != FL[1]) eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @139_4c7790
  PV[16] = (u32)(eax);  // @140_4c7790
  eax = (u32)(EBP - 40);  // @141_4c7790
  PV[17] = (u32)(eax);  // @142_4c7790
  eax = (u32)(EBP - 16);  // @143_4c7790
  PV[18] = (u32)(eax);  // @144_4c7790
  PV[19] = (u32)(edi);  // @145_4c7790
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 540)))(ecx, PV[19], PV[18], PV[17], PV[16]);  // @146_4c7790
  ecx = edx = 0;  // @147_4c7790
  L4c79a8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_4c7790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @150_4c7790
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @151_4c7790
  ecx = edx = 0;  // @152_4c7790
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }));  // @153_4c7790
  FL[3] = esi;  // @154_4c7790
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; }));  // @155_4c7790
  FL[3] = ebx;  // @156_4c7790
  PV[20] = (u32)(esi);  // @157_4c7790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @158_4c7790
  PV[21] = (u32)(ebx);  // @159_4c7790
  PV[22] = (u32)(eax);  // @160_4c7790
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[22], (u32)(0), (u32)(5), (u32)(6900484), PV[21], PV[20]);  // @161_4c7790
  ecx = edx = 0;  // @162_4c7790
  L4c79d5:;
  ext_633654(G(u32, 0x6f5630));  // @164_4c7790
  return eax;  // @165_4c7790
}
PCREG(4c7790, lifted_4c7790);

extern "C" u32 THISCALL lifted_53f980(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(EBP - 76);  // @0_53f980
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_53f980
  PV[0] = (u32)(eax);  // @2_53f980
  edi = ecx;  // @3_53f980
  { u32 v = (u32)((u32)(3248704672)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @4_53f980
  eax = (u32)(EBP - 64);  // @5_53f980
  { u32 v = (u32)((u32)(3253137579)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @6_53f980
  PV[1] = (u32)(eax);  // @7_53f980
  eax = (u32)(EBP - 52);  // @8_53f980
  { u32 v = (u32)((u32)(3259498496)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @9_53f980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @10_53f980
  edx = (u32)(EBP - 16);  // @11_53f980
  PV[2] = (u32)(eax);  // @12_53f980
  { u32 v = (u32)((u32)(3248704672)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @13_53f980
  { u32 v = (u32)((u32)(3253137579)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @14_53f980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @15_53f980
  { u32 v = (u32)((u32)(3248704672)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @16_53f980
  { u32 v = (u32)((u32)(1114042539)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @17_53f980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @18_53f980
  { u32 v = (u32)((u32)(1114960625)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @19_53f980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @20_53f980
  eax = ext_53fd10_fastcall5(ecx, edx, PV[2], PV[1], PV[0]);  // @21_53f980
  ecx = edx = 0;  // @22_53f980
  eax = (u32)(EBP - 16);  // @23_53f980
  PV[3] = (u32)(eax);  // @24_53f980
  edx = (u32)(EBP - 52);  // @25_53f980
  ecx = (u32)(EBP - 112);  // @26_53f980
  eax = ext_43e920_fastcall3(ecx, edx, PV[3]);  // @27_53f980
  ecx = edx = 0;  // @28_53f980
  eax = (u32)(EBP - 16);  // @29_53f980
  PV[4] = (u32)(eax);  // @30_53f980
  edx = (u32)(EBP - 64);  // @31_53f980
  ecx = (u32)(EBP - 100);  // @32_53f980
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @33_53f980
  ecx = edx = 0;  // @34_53f980
  eax = (u32)(EBP - 16);  // @35_53f980
  PV[5] = (u32)(eax);  // @36_53f980
  edx = (u32)(EBP - 76);  // @37_53f980
  ecx = (u32)(EBP - 88);  // @38_53f980
  eax = ext_43e920_fastcall3(ecx, edx, PV[5]);  // @39_53f980
  ecx = edx = 0;  // @40_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 338), sizeof v); (u32)v; });  // @41_53f980
  ecx = 0;  // @42_53f980
  FL[3] = ecx;  // @43_53f980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 102), &v, sizeof v); }  // @44_53f980
  edx = (u32)(20);  // @45_53f980
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @46_53f980
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @47_53f980
  FL[1] = ecx;  // @48_53f980
  ecx = (0u - ecx);  // @49_53f980
  ecx = (ecx | eax);  // @50_53f980
  FL[3] = ecx;  // @51_53f980
  PV[6] = (u32)(ecx);  // @52_53f980
  eax = ext_41e290_cdecl1(PV[6]);  // @53_53f980
  ecx = edx = 0;  // @54_53f980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 309), &v, sizeof v); }  // @55_53f980
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 338), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @56_53f980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @57_53f980
  if ((s32)FL[0] <= (s32)FL[1]) goto L53fb84;  // @58_53f980
  esi = 0;  // @59_53f980
  FL[3] = esi;  // @60_53f980
  ecx = (u32)(edi + 285);  // @61_53f980
  ebx = 0;  // @62_53f980
  FL[3] = ebx;  // @63_53f980
  L53fa80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 334), sizeof v); (u32)v; });  // @65_53f980
  edx = ecx;  // @66_53f980
  ecx = (u32)(EBP - 40);  // @67_53f980
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ebx) + 0), 4); v; });  // @68_53f980
  X0[1] = 0;  // @69_53f980
  X0[2] = 0;  // @70_53f980
  X0[3] = 0;  // @71_53f980
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @72_53f980
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ebx + 4) + 0), 4); v; });  // @73_53f980
  X0[1] = 0;  // @74_53f980
  X0[2] = 0;  // @75_53f980
  X0[3] = 0;  // @76_53f980
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @77_53f980
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ebx + 8) + 0), 4); v; });  // @78_53f980
  X0[1] = 0;  // @79_53f980
  X0[2] = 0;  // @80_53f980
  X0[3] = 0;  // @81_53f980
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @82_53f980
  eax = ext_43e960_fastcall2(ecx, edx);  // @83_53f980
  ecx = edx = 0;  // @84_53f980
  edx = (u32)(EBP - 16);  // @85_53f980
  ecx = (u32)(EBP - 40);  // @86_53f980
  eax = ext_43e960_fastcall2(ecx, edx);  // @87_53f980
  ecx = edx = 0;  // @88_53f980
  eax = (u32)(EBP - 28);  // @89_53f980
  PV[7] = (u32)(eax);  // @90_53f980
  edx = (u32)(EBP - 40);  // @91_53f980
  ecx = (u32)(EBP - 112);  // @92_53f980
  eax = ext_547860_fastcall3(ecx, edx, PV[7]);  // @93_53f980
    // @94_53f980
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @95_53f980
  X0[1] = 0;  // @96_53f980
  X0[2] = 0;  // @97_53f980
  X0[3] = 0;  // @98_53f980
  ecx = (u32)(edi + 285);  // @99_53f980
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; })));  // @100_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 309), sizeof v); (u32)v; });  // @101_53f980
  ebx = (ebx + (u32)(12));  // @102_53f980
  FL[3] = ebx;  // @103_53f980
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @104_53f980
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @105_53f980
  __builtin_memcpy((void *)((u32)(esi + eax) + 0), &X0[0], 4);  // @106_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 309), sizeof v); (u32)v; });  // @107_53f980
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @108_53f980
  X0[1] = 0;  // @109_53f980
  X0[2] = 0;  // @110_53f980
  X0[3] = 0;  // @111_53f980
  __builtin_memcpy((void *)((u32)(esi + eax + 4) + 0), &X0[0], 4);  // @112_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 309), sizeof v); (u32)v; });  // @113_53f980
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @114_53f980
  X0[1] = 0;  // @115_53f980
  X0[2] = 0;  // @116_53f980
  X0[3] = 0;  // @117_53f980
  __builtin_memcpy((void *)((u32)(esi + eax + 8) + 0), &X0[0], 4);  // @118_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 309), sizeof v); (u32)v; });  // @119_53f980
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @120_53f980
  X0[1] = 0;  // @121_53f980
  X0[2] = 0;  // @122_53f980
  X0[3] = 0;  // @123_53f980
  __builtin_memcpy((void *)((u32)(esi + eax + 12) + 0), &X0[0], 4);  // @124_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 309), sizeof v); (u32)v; });  // @125_53f980
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 4) + 0), 4); v; });  // @126_53f980
  X1[1] = 0;  // @127_53f980
  X1[2] = 0;  // @128_53f980
  X1[3] = 0;  // @129_53f980
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax) + 0), 4); v; });  // @130_53f980
  X3[1] = 0;  // @131_53f980
  X3[2] = 0;  // @132_53f980
  X3[3] = 0;  // @133_53f980
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 8) + 0), 4); v; });  // @134_53f980
  X0[1] = 0;  // @135_53f980
  X0[2] = 0;  // @136_53f980
  X0[3] = 0;  // @137_53f980
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + eax + 12) + 0), 4); v; });  // @138_53f980
  X2[1] = 0;  // @139_53f980
  X2[2] = 0;  // @140_53f980
  X2[3] = 0;  // @141_53f980
  X3[0] = F2U(U2F(X3[0]) * U2F(X3[0]));  // @142_53f980
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @143_53f980
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @144_53f980
  X3[0] = F2U(U2F(X3[0]) + U2F(X1[0]));  // @145_53f980
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @146_53f980
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @147_53f980
  X3[0] = F2U(U2F(X3[0]) + U2F(X2[0]));  // @148_53f980
  __builtin_memcpy((void *)((u32)(esi + eax + 16) + 0), &X3[0], 4);  // @149_53f980
  esi = (esi + (u32)(20));  // @150_53f980
  FL[3] = esi;  // @151_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @152_53f980
  eax = (eax + 1);  // @153_53f980
  FL[3] = eax;  // @154_53f980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @155_53f980
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 338), sizeof v); (u32)v; });  // @156_53f980
  if ((s32)FL[0] < (s32)FL[1]) goto L53fa80;  // @157_53f980
  L53fb84:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @159_53f980
  eax = (u32)(EBP - 124);  // @160_53f980
  PV[8] = (u32)(eax);  // @161_53f980
  eax = (u32)(EBP - 160);  // @162_53f980
  PV[9] = (u32)(eax);  // @163_53f980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @164_53f980
  eax = ext_4db2c0_thiscall3(ecx, PV[9], PV[8]);  // @165_53f980
  ecx = edx = 0;  // @166_53f980
  ecx = edi;  // @167_53f980
  eax = ext_5407c0_thiscall1(ecx);  // @168_53f980
  ecx = edx = 0;  // @169_53f980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @170_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @171_53f980
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @172_53f980
  ecx = edx = 0;  // @173_53f980
  FL[2] = (eax & eax);  // @174_53f980
  if (FL[2] == 0) goto L53fc11;  // @175_53f980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @176_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_53f980
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @178_53f980
  ecx = edx = 0;  // @179_53f980
  ecx = (u32)(edi + 259);  // @180_53f980
  PV[10] = (u32)(ecx);  // @181_53f980
  ecx = eax;  // @182_53f980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @183_53f980
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[10]);  // @184_53f980
  ecx = edx = 0;  // @185_53f980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @186_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @187_53f980
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @188_53f980
  ecx = edx = 0;  // @189_53f980
  ecx = (u32)(edi + 235);  // @190_53f980
  PV[11] = (u32)(ecx);  // @191_53f980
  ecx = eax;  // @192_53f980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @193_53f980
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 144)))(ecx, PV[11]);  // @194_53f980
  ecx = edx = 0;  // @195_53f980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @196_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @197_53f980
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @198_53f980
  ecx = edx = 0;  // @199_53f980
  ecx = (u32)(edi + 223);  // @200_53f980
  PV[12] = (u32)(ecx);  // @201_53f980
  ecx = eax;  // @202_53f980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @203_53f980
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 144)))(ecx, PV[12]);  // @204_53f980
  ecx = edx = 0;  // @205_53f980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @206_53f980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_53f980
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @208_53f980
  ecx = edx = 0;  // @209_53f980
  edx = (u32)(edi + 211);  // @210_53f980
  ecx = eax;  // @211_53f980
  PV[13] = (u32)(edx);  // @212_53f980
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @213_53f980
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 144)))(ecx, PV[13]);  // @214_53f980
  ecx = edx = 0;  // @215_53f980
  L53fc11:;
  ecx = edi;  // @217_53f980
  eax = ext_5407c0_thiscall1(ecx);  // @218_53f980
  ecx = edx = 0;  // @219_53f980
  ext_633654(G(u32, 0x6f5630));  // @220_53f980
  return eax;  // @221_53f980
}
PCREG(53f980, lifted_53f980);

extern "C" u32 THISCALL lifted_4ca2d0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4ca2d0
  ebx = ecx;  // @1_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @2_4ca2d0
  X0[1] = 0;  // @3_4ca2d0
  X0[2] = 0;  // @4_4ca2d0
  X0[3] = 0;  // @5_4ca2d0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @6_4ca2d0
  PV[0] = (u32)(ecx);  // @7_4ca2d0
  edx = (u32)(ebx + 108);  // @8_4ca2d0
  ecx = (u32)(EBP - 100);  // @9_4ca2d0
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @10_4ca2d0
  PV[1] = X0[0];  // @11_4ca2d0
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[1]);  // @12_4ca2d0
    // @13_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @14_4ca2d0
  X0[1] = 0;  // @15_4ca2d0
  X0[2] = 0;  // @16_4ca2d0
  X0[3] = 0;  // @17_4ca2d0
  edx = (u32)(ebx + 120);  // @18_4ca2d0
  PV[2] = (u32)(ecx);  // @19_4ca2d0
  ecx = (u32)(EBP - 88);  // @20_4ca2d0
  PV[3] = X0[0];  // @21_4ca2d0
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[3]);  // @22_4ca2d0
    // @23_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @24_4ca2d0
  X0[1] = 0;  // @25_4ca2d0
  X0[2] = 0;  // @26_4ca2d0
  X0[3] = 0;  // @27_4ca2d0
  edx = (u32)(ebx + 132);  // @28_4ca2d0
  PV[4] = (u32)(ecx);  // @29_4ca2d0
  ecx = (u32)(EBP - 76);  // @30_4ca2d0
  PV[5] = X0[0];  // @31_4ca2d0
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[5]);  // @32_4ca2d0
    // @33_4ca2d0
  edx = (u32)(EBP - 100);  // @34_4ca2d0
  ecx = (u32)(ebx + 72);  // @35_4ca2d0
  eax = ext_4dfd80_fastcall2(ecx, edx);  // @36_4ca2d0
    // @37_4ca2d0
  edx = (u32)(EBP - 88);  // @38_4ca2d0
  ecx = (u32)(ebx + 84);  // @39_4ca2d0
  eax = ext_4dfd80_fastcall2(ecx, edx);  // @40_4ca2d0
    // @41_4ca2d0
  edx = (u32)(EBP - 76);  // @42_4ca2d0
  ecx = (u32)(ebx + 96);  // @43_4ca2d0
  eax = ext_4dfd80_fastcall2(ecx, edx);  // @44_4ca2d0
    // @45_4ca2d0
  eax = ebx;  // @46_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 76) + 0), 4); v; });  // @47_4ca2d0
  X0[1] = 0;  // @48_4ca2d0
  X0[2] = 0;  // @49_4ca2d0
  X0[3] = 0;  // @50_4ca2d0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @51_4ca2d0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @52_4ca2d0
  ecx = edx = 0;  // @53_4ca2d0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @54_4ca2d0
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @55_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; });  // @56_4ca2d0
  X0[1] = 0;  // @57_4ca2d0
  X0[2] = 0;  // @58_4ca2d0
  X0[3] = 0;  // @59_4ca2d0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @60_4ca2d0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @61_4ca2d0
  ecx = edx = 0;  // @62_4ca2d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @63_4ca2d0
  X1[1] = 0;  // @64_4ca2d0
  X1[2] = 0;  // @65_4ca2d0
  X1[3] = 0;  // @66_4ca2d0
  esi = ebx;  // @67_4ca2d0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @68_4ca2d0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @69_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; });  // @70_4ca2d0
  X0[1] = 0;  // @71_4ca2d0
  X0[2] = 0;  // @72_4ca2d0
  X0[3] = 0;  // @73_4ca2d0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @74_4ca2d0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X1[0], 4);  // @75_4ca2d0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @76_4ca2d0
  ecx = edx = 0;  // @77_4ca2d0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @78_4ca2d0
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @79_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 84) + 0), 4); v; });  // @80_4ca2d0
  X0[1] = 0;  // @81_4ca2d0
  X0[2] = 0;  // @82_4ca2d0
  X0[3] = 0;  // @83_4ca2d0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @84_4ca2d0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @85_4ca2d0
  ecx = edx = 0;  // @86_4ca2d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @87_4ca2d0
  X1[1] = 0;  // @88_4ca2d0
  X1[2] = 0;  // @89_4ca2d0
  X1[3] = 0;  // @90_4ca2d0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @91_4ca2d0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @92_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 100) + 0), 4); v; });  // @93_4ca2d0
  X0[1] = 0;  // @94_4ca2d0
  X0[2] = 0;  // @95_4ca2d0
  X0[3] = 0;  // @96_4ca2d0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @97_4ca2d0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X1[0], 4);  // @98_4ca2d0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @99_4ca2d0
  ecx = edx = 0;  // @100_4ca2d0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @101_4ca2d0
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @102_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 96) + 0), 4); v; });  // @103_4ca2d0
  X0[1] = 0;  // @104_4ca2d0
  X0[2] = 0;  // @105_4ca2d0
  X0[3] = 0;  // @106_4ca2d0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @107_4ca2d0
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @108_4ca2d0
  ecx = edx = 0;  // @109_4ca2d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @110_4ca2d0
  X1[1] = 0;  // @111_4ca2d0
  X1[2] = 0;  // @112_4ca2d0
  X1[3] = 0;  // @113_4ca2d0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @114_4ca2d0
  PV[6] = (u32)(ecx);  // @115_4ca2d0
  ecx = (u32)(EBP - 28);  // @116_4ca2d0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @117_4ca2d0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @118_4ca2d0
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @119_4ca2d0
    // @120_4ca2d0
  eax = (u32)(EBP - 28);  // @121_4ca2d0
  PV[7] = (u32)(eax);  // @122_4ca2d0
  edx = (u32)(esi + 144);  // @123_4ca2d0
  ecx = (u32)(EBP - 16);  // @124_4ca2d0
  eax = ext_4e0940_fastcall3(ecx, edx, PV[7]);  // @125_4ca2d0
    // @126_4ca2d0
  edx = (u32)(esi + 173);  // @127_4ca2d0
  ecx = (u32)(EBP - 16);  // @128_4ca2d0
  eax = ext_441940_fastcall2(ecx, edx);  // @129_4ca2d0
  ecx = edx = 0;  // @130_4ca2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @131_4ca2d0
  edx = (u32)(EBP - 16);  // @132_4ca2d0
  PV[8] = (u32)(edx);  // @133_4ca2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_4ca2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[8]);  // @135_4ca2d0
  ecx = edx = 0;  // @136_4ca2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 157), sizeof v); (u32)v; });  // @137_4ca2d0
  FL[2] = (edx & edx);  // @138_4ca2d0
  if (FL[2] == 0) goto L4ca504;  // @139_4ca2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @140_4ca2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @141_4ca2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @142_4ca2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @143_4ca2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @144_4ca2d0
  PV[9] = (u32)(edx);  // @145_4ca2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_4ca2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[9]);  // @147_4ca2d0
  ecx = edx = 0;  // @148_4ca2d0
  edi = eax;  // @149_4ca2d0
  FL[2] = (edi & edi);  // @150_4ca2d0
  if (FL[2] == 0) goto L4ca55d;  // @151_4ca2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @152_4ca2d0
  eax = (u32)(EBP - 64);  // @153_4ca2d0
  PV[10] = (u32)(eax);  // @154_4ca2d0
  eax = ext_4daf90_thiscall2(ecx, PV[10]);  // @155_4ca2d0
  edx = 0;  // @156_4ca2d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @157_4ca2d0
  eax = (u32)(EBP - 64);  // @158_4ca2d0
  PV[11] = (u32)(eax);  // @159_4ca2d0
  ecx = edi;  // @160_4ca2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[11]);  // @161_4ca2d0
  ecx = edx = 0;  // @162_4ca2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @163_4ca2d0
  edx = (u32)(EBP - 40);  // @164_4ca2d0
  PV[12] = (u32)(edx);  // @165_4ca2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @166_4ca2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[12]);  // @167_4ca2d0
  ecx = edx = 0;  // @168_4ca2d0
  eax = (u32)(EBP - 16);  // @169_4ca2d0
  PV[13] = (u32)(eax);  // @170_4ca2d0
  edx = (u32)(EBP - 64);  // @171_4ca2d0
  ecx = (u32)(EBP - 52);  // @172_4ca2d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[13]);  // @173_4ca2d0
  ecx = edx = 0;  // @174_4ca2d0
  edx = (u32)(EBP - 52);  // @175_4ca2d0
  ecx = (u32)(EBP - 136);  // @176_4ca2d0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @177_4ca2d0
  ecx = edx = 0;  // @178_4ca2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @179_4ca2d0
  edx = (u32)(EBP - 16);  // @180_4ca2d0
  PV[14] = (u32)(edx);  // @181_4ca2d0
  edx = (u32)(EBP - 136);  // @182_4ca2d0
  PV[15] = (u32)(edx);  // @183_4ca2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @184_4ca2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[15], PV[14]);  // @185_4ca2d0
  ecx = edx = 0;  // @186_4ca2d0
  ext_633654(G(u32, 0x6f5630));  // @187_4ca2d0
  return eax;  // @188_4ca2d0
  L4ca504:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 156), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @190_4ca2d0
  if (FL[0] == FL[1]) goto L4ca55d;  // @191_4ca2d0
  esi = (esi + (u32)(161));  // @192_4ca2d0
  FL[3] = esi;  // @193_4ca2d0
  edx = (u32)(EBP - 16);  // @194_4ca2d0
  PV[16] = (u32)(esi);  // @195_4ca2d0
  ecx = (u32)(EBP - 52);  // @196_4ca2d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[16]);  // @197_4ca2d0
  ecx = edx = 0;  // @198_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @199_4ca2d0
  X0[1] = 0;  // @200_4ca2d0
  X0[2] = 0;  // @201_4ca2d0
  X0[3] = 0;  // @202_4ca2d0
  edx = (u32)(EBP - 52);  // @203_4ca2d0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @204_4ca2d0
  ecx = (u32)(EBP - 136);  // @205_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @206_4ca2d0
  X0[1] = 0;  // @207_4ca2d0
  X0[2] = 0;  // @208_4ca2d0
  X0[3] = 0;  // @209_4ca2d0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @210_4ca2d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @211_4ca2d0
  X0[1] = 0;  // @212_4ca2d0
  X0[2] = 0;  // @213_4ca2d0
  X0[3] = 0;  // @214_4ca2d0
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @215_4ca2d0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @216_4ca2d0
  ecx = edx = 0;  // @217_4ca2d0
  eax = ebx;  // @218_4ca2d0
  edx = (u32)(EBP - 136);  // @219_4ca2d0
  PV[17] = (u32)(edx);  // @220_4ca2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @221_4ca2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @222_4ca2d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[17]);  // @223_4ca2d0
  ecx = edx = 0;  // @224_4ca2d0
  L4ca55d:;
  ext_633654(G(u32, 0x6f5630));  // @226_4ca2d0
  return eax;  // @227_4ca2d0
}
PCREG(4ca2d0, lifted_4ca2d0);

