// batch244041.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_467060_thiscall4(u32, u32, u32, u32) __asm__("ext_467060");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_49e260_fastcall3(u32, u32, u32) __asm__("ext_49e260");
extern "C" u32 STDCALL ext_467060_stdcall3(u32, u32, u32) __asm__("ext_467060");
extern "C" u32 THISCALL ext_49df60_thiscall3(u32, u32, u32) __asm__("ext_49df60");
extern "C" u32 THISCALL ext_49e0d0_thiscall1(u32) __asm__("ext_49e0d0");
extern "C" u32 THISCALL ext_49e250_thiscall2(u32, u32) __asm__("ext_49e250");
extern "C" u32 THISCALL ext_598e10_thiscall4(u32, u32, u32, u32) __asm__("ext_598e10");
extern "C" u32 THISCALL ext_59a5b0_thiscall4(u32, u32, u32, u32) __asm__("ext_59a5b0");
extern "C" u32 THISCALL ext_59fb50_thiscall1(u32) __asm__("ext_59fb50");
extern "C" u32 THISCALL ext_5da860_thiscall3(u32, u32, u32) __asm__("ext_5da860");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5a1c50(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x5d0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x4d0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, ebxh = 0, edxh = 0, ecxh = 0, eaxh = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4d0 + 8, &a0, 4);
  __builtin_memcpy(F + 0x4d0 + 12, &a1, 4);
  __builtin_memcpy(F + 0x4d0 + 16, &a2, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_5a1c50
  edi = ecx;  // @1_5a1c50
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xff);  // @2_5a1c50
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1072), &v, sizeof v); }  // @3_5a1c50
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1057), &v, sizeof v); }  // @4_5a1c50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2362), sizeof v); (u32)v; });  // @5_5a1c50
  FL[2] = (edx & edx);  // @6_5a1c50
  if (FL[2] == 0) goto L5a20a9;  // @7_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @8_5a1c50
  ecx = (ecx & 0xff);  // @9_5a1c50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1064), &v, sizeof v); }  // @10_5a1c50
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @11_5a1c50
  PV[1] = (u32)(ecx);  // @12_5a1c50
  ecx = edx;  // @13_5a1c50
  eax = ext_5da860_thiscall3(ecx, PV[1], PV[0]);  // @14_5a1c50
  ecx = edx = 0;  // @15_5a1c50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @16_5a1c50
  if (FL[2] == 0) goto L5a20a9;  // @17_5a1c50
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1057), sizeof v); (u32)v; }); FL[1] = (u32)(38);  // @18_5a1c50
  if (FL[0] <= FL[1]) goto L5a1cb6;  // @19_5a1c50
  ecx = edi;  // @20_5a1c50
  eax = ext_59fb50_thiscall1(ecx);  // @21_5a1c50
  ecx = edx = 0;  // @22_5a1c50
  L5a1cb6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2358), sizeof v); (u32)v; });  // @24_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1064), sizeof v); (u32)v; });  // @25_5a1c50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @26_5a1c50
  if (FL[0] == FL[1]) goto L5a20a9;  // @27_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_5a1c50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7005), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @29_5a1c50
  if (FL[0] == FL[1]) goto L5a20a9;  // @30_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2350), sizeof v); (u32)v; });  // @31_5a1c50
  edx = (u32)(EBP - 540);  // @32_5a1c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @33_5a1c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @34_5a1c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @35_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_5a1c50
  PV[2] = (u32)(edx);  // @37_5a1c50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[2]);  // @38_5a1c50
  ecx = edx = 0;  // @39_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_5a1c50
  ecx = (u32)(EBP - 528);  // @41_5a1c50
  PV[3] = (u32)(ecx);  // @42_5a1c50
  ecx = edi;  // @43_5a1c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 528), &v, sizeof v); }  // @44_5a1c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 524), &v, sizeof v); }  // @45_5a1c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @46_5a1c50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[3]);  // @47_5a1c50
  ecx = edx = 0;  // @48_5a1c50
  eax = (u32)(EBP - 528);  // @49_5a1c50
  PV[4] = (u32)(eax);  // @50_5a1c50
  edx = (u32)(EBP - 540);  // @51_5a1c50
  ecx = (u32)(EBP - 1092);  // @52_5a1c50
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @53_5a1c50
  ecx = edx = 0;  // @54_5a1c50
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1088) + 0), 4); v; });  // @55_5a1c50
  X1[1] = 0;  // @56_5a1c50
  X1[2] = 0;  // @57_5a1c50
  X1[3] = 0;  // @58_5a1c50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7008120) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7008120) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @59_5a1c50
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @60_5a1c50
  X1[0] = X1[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @61_5a1c50
  X1[1] = X1[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @62_5a1c50
  X1[2] = X1[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @63_5a1c50
  X1[3] = X1[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @64_5a1c50
  if (((!(U2D(X0[0], X0[1]) >= U2D(X1[0], X1[1]))) || (!((U2D(X0[0], X0[1]) < U2D(X1[0], X1[1])) || (U2D(X0[0], X0[1]) > U2D(X1[0], X1[1])))))) goto L5a20a9;  // @65_5a1c50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1084) + 0), 4); v; });  // @66_5a1c50
  X0[1] = 0;  // @67_5a1c50
  X0[2] = 0;  // @68_5a1c50
  X0[3] = 0;  // @69_5a1c50
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1092) + 0), 4); v; });  // @70_5a1c50
  X1[1] = 0;  // @71_5a1c50
  X1[2] = 0;  // @72_5a1c50
  X1[3] = 0;  // @73_5a1c50
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @74_5a1c50
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @75_5a1c50
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @76_5a1c50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000860) + 0), 4); v; });  // @77_5a1c50
  X0[1] = 0;  // @78_5a1c50
  X0[2] = 0;  // @79_5a1c50
  X0[3] = 0;  // @80_5a1c50
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5a20a9;  // @81_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @82_5a1c50
  ecx = edi;  // @83_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1668), sizeof v); (u32)v; });  // @84_5a1c50
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @85_5a1c50
  ecx = edx = 0;  // @86_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1064), sizeof v); (u32)v; });  // @87_5a1c50
  PV[5] = (u32)(eax);  // @88_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2358), sizeof v); (u32)v; });  // @89_5a1c50
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @90_5a1c50
  ecx = edi;  // @91_5a1c50
  eax = ext_467060_thiscall4(ecx, PV[6], PV[5], (u32)(1));  // @92_5a1c50
  ecx = edx = 0;  // @93_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @94_5a1c50
  PV[7] = (u32)(eax);  // @95_5a1c50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1080), &v, sizeof v); }  // @96_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @97_5a1c50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_5a1c50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 96), sizeof v); (u32)v; });  // @99_5a1c50
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[7]);  // @100_5a1c50
  ecx = edx = 0;  // @101_5a1c50
  edx = eax;  // @102_5a1c50
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 1064), &v, sizeof v); }  // @103_5a1c50
  FL[2] = (edx & edx);  // @104_5a1c50
  if (FL[2] == 0) goto L5a20a9;  // @105_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_5a1c50
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 124), sizeof v); (u32)v; });  // @107_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @108_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @110_5a1c50
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[8]);  // @111_5a1c50
  ecx = edx = 0;  // @112_5a1c50
  edx = eax;  // @113_5a1c50
  FL[2] = (edx & edx);  // @114_5a1c50
  if (FL[2] == 0) goto L5a2063;  // @115_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_5a1c50
  PV[9] = (u32)(edx);  // @117_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @118_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 476), sizeof v); (u32)v; });  // @120_5a1c50
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[9]);  // @121_5a1c50
  ecx = edx = 0;  // @122_5a1c50
  edx = eax;  // @123_5a1c50
  FL[2] = (edx & edx);  // @124_5a1c50
  if (FL[2] == 0) goto L5a2063;  // @125_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @126_5a1c50
  PV[10] = (u32)(edx);  // @127_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @128_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 488), sizeof v); (u32)v; });  // @130_5a1c50
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[10]);  // @131_5a1c50
  ecx = edx = 0;  // @132_5a1c50
  edx = eax;  // @133_5a1c50
  FL[2] = (edx & edx);  // @134_5a1c50
  if (FL[2] == 0) goto L5a2063;  // @135_5a1c50
  ecx = edx;  // @136_5a1c50
  eax = (u32)(ecx + 1);  // @137_5a1c50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1068), &v, sizeof v); }  // @138_5a1c50
  L5a1e64:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @140_5a1c50
  ecx = (ecx + 1);  // @141_5a1c50
  FL[3] = ecx;  // @142_5a1c50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @143_5a1c50
  if (FL[2] != 0) goto L5a1e64;  // @144_5a1c50
  eax = (u32)(0);  // @145_5a1c50
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1068), sizeof v); (u32)v; }));  // @146_5a1c50
  FL[3] = ecx;  // @147_5a1c50
  if (FL[3] == 0) goto L5a1e83;  // @148_5a1c50
  L5a1e78:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @150_5a1c50
  if (FL[0] == FL[1]) goto L5a1e83;  // @151_5a1c50
  eax = (eax + 1);  // @152_5a1c50
  FL[3] = eax;  // @153_5a1c50
  FL[0] = eax; FL[1] = ecx;  // @154_5a1c50
  if (FL[0] < FL[1]) goto L5a1e78;  // @155_5a1c50
  L5a1e83:;
  eax = (eax + 1);  // @157_5a1c50
  FL[3] = eax;  // @158_5a1c50
  FL[0] = eax; FL[1] = ecx;  // @159_5a1c50
  if (FL[0] >= FL[1]) goto L5a1e93;  // @160_5a1c50
  L5a1e88:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @162_5a1c50
  if (FL[0] == FL[1]) goto L5a1e93;  // @163_5a1c50
  eax = (eax + 1);  // @164_5a1c50
  FL[3] = eax;  // @165_5a1c50
  FL[0] = eax; FL[1] = ecx;  // @166_5a1c50
  if (FL[0] < FL[1]) goto L5a1e88;  // @167_5a1c50
  L5a1e93:;
  ecx = (u32)(eax + edx);  // @169_5a1c50
  edx = (u32)(EBP - 260);  // @170_5a1c50
  edx = (edx - ecx);  // @171_5a1c50
  FL[3] = edx;  // @172_5a1c50
  L5a1ea0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @174_5a1c50
  ecx = (u32)(ecx + 1);  // @175_5a1c50
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @176_5a1c50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @177_5a1c50
  if (FL[2] != 0) goto L5a1ea0;  // @178_5a1c50
  ecx = (u32)(EBP - 260);  // @179_5a1c50
  edx = (u32)(ecx + 1);  // @180_5a1c50
  L5a1eb6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @182_5a1c50
  ecx = (ecx + 1);  // @183_5a1c50
  FL[3] = ecx;  // @184_5a1c50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @185_5a1c50
  if (FL[2] != 0) goto L5a1eb6;  // @186_5a1c50
  ecx = (ecx - edx);  // @187_5a1c50
  FL[3] = ecx;  // @188_5a1c50
  ecx = (ecx + (u32)(-4));  // @189_5a1c50
  FL[3] = ecx;  // @190_5a1c50
  FL[0] = ecx; FL[1] = (u32)(256);  // @191_5a1c50
  if (FL[0] >= FL[1]) goto L5a20bd;  // @192_5a1c50
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + ecx - 260), &v, sizeof v); }  // @193_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @195_5a1c50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @196_5a1c50
  if (FL[0] == FL[1]) goto L5a2063;  // @197_5a1c50
  ecx = (u32)(EBP - 1056);  // @198_5a1c50
  eax = ext_49e250_thiscall2(ecx, (u32)(6781786));  // @199_5a1c50
    // @200_5a1c50
  ecx = (u32)(EBP - 1056);  // @201_5a1c50
  eax = ext_49e260_fastcall3(ecx, edx, (u32)(6781786));  // @202_5a1c50
  ecx = edx = 0;  // @203_5a1c50
  eax = (u32)(EBP - 1056);  // @204_5a1c50
  PV[11] = (u32)(eax);  // @205_5a1c50
  eax = (u32)(EBP - 260);  // @206_5a1c50
  PV[12] = (u32)(eax);  // @207_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @208_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @209_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @210_5a1c50
  eax = ext_49df60_thiscall3(ecx, PV[12], PV[11]);  // @211_5a1c50
  ecx = edx = 0;  // @212_5a1c50
  FL[2] = (eax & eax);  // @213_5a1c50
  if (FL[2] == 0) goto L5a207b;  // @214_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1064), sizeof v); (u32)v; });  // @215_5a1c50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 112) + 0), 4); v; });  // @216_5a1c50
  X0[1] = 0;  // @217_5a1c50
  X0[2] = 0;  // @218_5a1c50
  X0[3] = 0;  // @219_5a1c50
  ecx = eax;  // @220_5a1c50
  __builtin_memcpy((void *)((u32)(EBP - 1068) + 0), &X0[0], 4);  // @221_5a1c50
  eax = ext_49e0d0_thiscall1(ecx);  // @222_5a1c50
    // @223_5a1c50
  edx = eax;  // @224_5a1c50
  eax = 0;  // @225_5a1c50
  FL[3] = eax;  // @226_5a1c50
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 1064), &v, sizeof v); }  // @227_5a1c50
  FL[2] = (esi & esi);  // @228_5a1c50
  if (FL[2] == 0) goto L5a2016;  // @229_5a1c50
  PV[13] = (u32)(eax);  // @230_5a1c50
  eax = (u32)(EBP - 516);  // @231_5a1c50
  PV[14] = (u32)(eax);  // @232_5a1c50
  eax = ext_634d10_cdecl3(PV[14], PV[13], (u32)(256));  // @233_5a1c50
    // @234_5a1c50
  ecx = (u32)(EBP - 516);  // @235_5a1c50
  ecx = (ecx - 1);  // @236_5a1c50
  FL[3] = ecx;  // @237_5a1c50
  L5a1f81:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @239_5a1c50
  ecx = (u32)(ecx + 1);  // @240_5a1c50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @241_5a1c50
  if (FL[2] != 0) goto L5a1f81;  // @242_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7007524), sizeof v); (u32)v; });  // @243_5a1c50
  edx = esi;  // @244_5a1c50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @245_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7007528), sizeof v); (u32)v; });  // @246_5a1c50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @247_5a1c50
  L5a1fa0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @249_5a1c50
  esi = (esi + 1);  // @250_5a1c50
  FL[3] = esi;  // @251_5a1c50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @252_5a1c50
  if (FL[2] != 0) goto L5a1fa0;  // @253_5a1c50
  edi = (u32)(EBP - 516);  // @254_5a1c50
  esi = (esi - edx);  // @255_5a1c50
  FL[3] = esi;  // @256_5a1c50
  edi = (edi - 1);  // @257_5a1c50
  FL[3] = edi;  // @258_5a1c50
  L5a1fb0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @260_5a1c50
  edi = (edi + 1);  // @261_5a1c50
  FL[3] = edi;  // @262_5a1c50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @263_5a1c50
  if (FL[2] != 0) goto L5a1fb0;  // @264_5a1c50
  ecx = esi;  // @265_5a1c50
  eax = (u32)(EBP - 1056);  // @266_5a1c50
  ecx = (ecx >> (u32)(2));  // @267_5a1c50
  FL[3] = ecx;  // @268_5a1c50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 1076), &v, sizeof v); }  // @269_5a1c50
  esi = edx;  // @270_5a1c50
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @271_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1076), sizeof v); (u32)v; });  // @272_5a1c50
  PV[15] = (u32)(eax);  // @273_5a1c50
  eax = (u32)(EBP - 516);  // @274_5a1c50
  ecx = (ecx & (u32)(3));  // @275_5a1c50
  FL[3] = ecx;  // @276_5a1c50
  PV[16] = (u32)(eax);  // @277_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @278_5a1c50
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @279_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @280_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @281_5a1c50
  eax = ext_49df60_thiscall3(ecx, PV[16], PV[15]);  // @282_5a1c50
  ecx = edx = 0;  // @283_5a1c50
  FL[2] = (eax & eax);  // @284_5a1c50
  if (FL[2] == 0) goto L5a2005;  // @285_5a1c50
  ecx = eax;  // @286_5a1c50
  eax = ext_49e0d0_thiscall1(ecx);  // @287_5a1c50
    // @288_5a1c50
  FL[2] = (eax & eax);  // @289_5a1c50
  if (FL[2] != 0) goto L5a200a;  // @290_5a1c50
  L5a2005:;
  eax = (u32)(6836920);  // @292_5a1c50
  L5a200a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1064), sizeof v); (u32)v; });  // @294_5a1c50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1072), sizeof v); (u32)v; });  // @295_5a1c50
  L5a2016:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2350), sizeof v); (u32)v; });  // @297_5a1c50
  FL[2] = (ecx & ecx);  // @298_5a1c50
  if (FL[2] == 0) goto L5a2063;  // @299_5a1c50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1068) + 0), 4); v; });  // @300_5a1c50
  X0[1] = 0;  // @301_5a1c50
  X0[2] = 0;  // @302_5a1c50
  X0[3] = 0;  // @303_5a1c50
  PV[17] = (u32)(ecx);  // @304_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @305_5a1c50
  PV[18] = X0[0];  // @306_5a1c50
  PV[19] = (u32)(edx);  // @307_5a1c50
  PV[20] = (u32)(eax);  // @308_5a1c50
  eax = ext_59a5b0_thiscall4(ecx, PV[20], PV[19], PV[18]);  // @309_5a1c50
  ecx = edx = 0;  // @310_5a1c50
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @311_5a1c50
  if (FL[0] == FL[1]) goto L5a2063;  // @312_5a1c50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1068) + 0), 4); v; });  // @313_5a1c50
  X0[1] = 0;  // @314_5a1c50
  X0[2] = 0;  // @315_5a1c50
  X0[3] = 0;  // @316_5a1c50
  PV[21] = (u32)(ecx);  // @317_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2350), sizeof v); (u32)v; });  // @318_5a1c50
  PV[22] = X0[0];  // @319_5a1c50
  PV[23] = (u32)(edi);  // @320_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @321_5a1c50
  eax = ext_598e10_thiscall4(ecx, PV[23], (u32)(1), PV[22]);  // @322_5a1c50
  ecx = edx = 0;  // @323_5a1c50
  L5a2063:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1080), sizeof v); (u32)v; });  // @325_5a1c50
  ext_633654(G(u32, 0x6f5630));  // @326_5a1c50
  return eax;  // @327_5a1c50
  L5a207b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @329_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @330_5a1c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @331_5a1c50
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7005856), (u32)(2721));  // @332_5a1c50
  ecx = edx = 0;  // @333_5a1c50
  edx = (u32)(EBP - 260);  // @334_5a1c50
  PV[24] = (u32)(edx);  // @335_5a1c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @336_5a1c50
  PV[25] = (u32)(eax);  // @337_5a1c50
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[25], (u32)(7007536), PV[24]);  // @338_5a1c50
  ecx = edx = 0;  // @339_5a1c50
  goto L5a2063;  // @340_5a1c50
  L5a20a9:;
  ext_633654(G(u32, 0x6f5630));  // @342_5a1c50
  eax = 0;  // @343_5a1c50
  FL[3] = eax;  // @344_5a1c50
  return eax;  // @345_5a1c50
  L5a20bd:;
  eax = ext_634047_cdecl0();  // @347_5a1c50
  ecx = edx = 0;  // @348_5a1c50
}
PCREG(5a1c50, lifted_5a1c50);

