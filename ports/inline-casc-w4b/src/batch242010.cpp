// batch242010.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d70_dbl(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d76_dbl(double) __asm__("ext_634d76");
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4dffe0_fastcall3(u32, u32, u32) __asm__("ext_4dffe0");
extern "C" u32 FASTCALL ext_4e0980_fastcall2(u32, u32) __asm__("ext_4e0980");
extern "C" u32 FASTCALL ext_4e0be0_fastcall2(u32, u32) __asm__("ext_4e0be0");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 THISCALL ext_445e10_thiscall2(u32, u32) __asm__("ext_445e10");
extern "C" u32 THISCALL ext_459c40_thiscall2(u32, u32) __asm__("ext_459c40");
extern "C" u32 THISCALL ext_45dc90_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_45dc90");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4db2a0_thiscall2(u32, u32) __asm__("ext_4db2a0");
extern "C" u32 THISCALL ext_4db2c0_thiscall3(u32, u32, u32) __asm__("ext_4db2c0");
extern "C" u32 THISCALL ext_4db2f0_thiscall2(u32, u32) __asm__("ext_4db2f0");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4dffb0_thiscall2(u32, u32) __asm__("ext_4dffb0");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e0a10_thiscall1(u32) __asm__("ext_4e0a10");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 ext_63452b_cdecl1(...) __asm__("ext_63452b");
extern "C" u32 ext_63456a_cdecl1(...) __asm__("ext_63456a");
extern "C" double VECTORCALL ext_634db2_dbl2(double, double) __asm__("ext_634db2");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c3f40(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4c3f40
  esi = ecx;  // @1_4c3f40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 138), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_4c3f40
  edi = (u32)(esi + 138);  // @3_4c3f40
  if (FL[0] != FL[1]) goto L4c3f85;  // @4_4c3f40
  eax = (u32)(edx + 64);  // @5_4c3f40
  FL[0] = edi; FL[1] = eax;  // @6_4c3f40
  if (FL[0] == FL[1]) goto L4c3f85;  // @7_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_4c3f40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @9_4c3f40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_4c3f40
  L4c3f85:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 146) + 0), 4); v; });  // @12_4c3f40
  X2[1] = 0;  // @13_4c3f40
  X2[2] = 0;  // @14_4c3f40
  X2[3] = 0;  // @15_4c3f40
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; });  // @16_4c3f40
  X1[1] = 0;  // @17_4c3f40
  X1[2] = 0;  // @18_4c3f40
  X1[3] = 0;  // @19_4c3f40
  X0[0] = X2[0];  // @20_4c3f40
  X0[1] = X2[1];  // @21_4c3f40
  X0[2] = X2[2];  // @22_4c3f40
  X0[3] = X2[3];  // @23_4c3f40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @24_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @25_4c3f40
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @26_4c3f40
  FL[0] = eax; FL[1] = ebx;  // @27_4c3f40
  if ((s32)FL[0] > (s32)FL[1]) goto L4c44d9;  // @28_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 78) + 0), 4); v; });  // @29_4c3f40
  X0[1] = 0;  // @30_4c3f40
  X0[2] = 0;  // @31_4c3f40
  X0[3] = 0;  // @32_4c3f40
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @33_4c3f40
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @34_4c3f40
  if (__builtin_parity(FL[2] & 0xff)) goto L4c4020;  // @35_4c3f40
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @36_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @37_4c3f40
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @38_4c3f40
  FL[0] = eax; FL[1] = ebx;  // @39_4c3f40
  if ((s32)FL[0] >= (s32)FL[1]) goto L4c4020;  // @40_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_4c3f40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @42_4c3f40
  ecx = edx = 0;  // @43_4c3f40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 121), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @44_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @45_4c3f40
  if (FL[0] == FL[1]) goto L4c3ff9;  // @46_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4c3f40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @48_4c3f40
  ecx = edx = 0;  // @49_4c3f40
  ext_633654(G(u32, 0x6f5630));  // @50_4c3f40
  return eax;  // @51_4c3f40
  L4c3ff9:;
  FL[2] = (ecx & ecx);  // @53_4c3f40
  if (FL[2] == 0) goto L4c44d9;  // @54_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4c3f40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @56_4c3f40
  ecx = edx = 0;  // @57_4c3f40
  ext_633654(G(u32, 0x6f5630));  // @58_4c3f40
  return eax;  // @59_4c3f40
  L4c4020:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 72) + 0), 4); v; });  // @61_4c3f40
  X0[1] = 0;  // @62_4c3f40
  X0[2] = 0;  // @63_4c3f40
  X0[3] = 0;  // @64_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 24) + 0), &X0[0], 4);  // @66_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 74) + 0), 4); v; });  // @67_4c3f40
  X0[1] = 0;  // @68_4c3f40
  X0[2] = 0;  // @69_4c3f40
  X0[3] = 0;  // @70_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @71_4c3f40
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @72_4c3f40
  ecx = (ecx - eax);  // @73_4c3f40
  FL[3] = ecx;  // @74_4c3f40
  FL[0] = ecx; FL[1] = ebx;  // @75_4c3f40
  if ((s32)FL[0] > (s32)FL[1]) goto L4c44d9;  // @76_4c3f40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @77_4c3f40
  if (FL[0] != FL[1]) goto L4c4061;  // @78_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @79_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @80_4c3f40
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(4096));  // @81_4c3f40
  if (FL[2] == 0) goto L4c44d9;  // @82_4c3f40
  L4c4061:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @84_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 162) + 0), 4); v; });  // @85_4c3f40
  X0[1] = 0;  // @86_4c3f40
  X0[2] = 0;  // @87_4c3f40
  X0[3] = 0;  // @88_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @89_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @90_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @91_4c3f40
  eax = (eax >> (u32)(21));  // @92_4c3f40
  FL[3] = eax;  // @93_4c3f40
  eax = (eax & (u32)(4294967041));  // @94_4c3f40
  FL[3] = eax;  // @95_4c3f40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 224) + 12), &v, sizeof v); }  // @96_4c3f40
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @97_4c3f40
  ebx = (ebx - eax);  // @98_4c3f40
  FL[3] = ebx;  // @99_4c3f40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = ebx;  // @100_4c3f40
  if ((s32)FL[0] >= (s32)FL[1]) goto L4c40a6;  // @101_4c3f40
  eax = (u32)((EBP - 224) + 48);  // @102_4c3f40
  FL[0] = edi; FL[1] = eax;  // @103_4c3f40
  if (FL[0] == FL[1]) goto L4c4096;  // @104_4c3f40
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @105_4c3f40
  L4c4096:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 142), &v, sizeof v); }  // @107_4c3f40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_4c3f40
  L4c40a6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 155), sizeof v); (u32)v; });  // @110_4c3f40
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 130), sizeof v); (u32)v; });  // @111_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4c3f40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @113_4c3f40
  ecx = edx = 0;  // @114_4c3f40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 224) + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @115_4c3f40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 224) + 44), &v, sizeof v); }  // @116_4c3f40
  if (FL[0] == FL[1]) goto L4c40fd;  // @117_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @118_4c3f40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4c3f40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @120_4c3f40
  ecx = edx = 0;  // @121_4c3f40
  ecx = eax;  // @122_4c3f40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @123_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @124_4c3f40
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050577));  // @125_4c3f40
  ecx = edx = 0;  // @126_4c3f40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @127_4c3f40
  if (FL[2] == 0) goto L4c40fd;  // @128_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @129_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_4c3f40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @131_4c3f40
  ecx = edx = 0;  // @132_4c3f40
  ecx = (u32)((EBP - 224) + 64);  // @133_4c3f40
  PV[1] = (u32)(ecx);  // @134_4c3f40
  ecx = (u32)((EBP - 228) + 116);  // @135_4c3f40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @136_4c3f40
  PV[2] = (u32)(ecx);  // @137_4c3f40
  ecx = eax;  // @138_4c3f40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 712)))(ecx, PV[2], PV[1]);  // @139_4c3f40
  ecx = edx = 0;  // @140_4c3f40
  goto L4c4112;  // @141_4c3f40
  L4c40fd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @143_4c3f40
  edx = (u32)((EBP - 224) + 64);  // @144_4c3f40
  PV[3] = (u32)(edx);  // @145_4c3f40
  edx = (u32)((EBP - 228) + 116);  // @146_4c3f40
  PV[4] = (u32)(edx);  // @147_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_4c3f40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[4], PV[3]);  // @149_4c3f40
  ecx = edx = 0;  // @150_4c3f40
  L4c4112:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @152_4c3f40
  X2[0] = 0;  // @153_4c3f40
  X2[1] = 0;  // @154_4c3f40
  X2[2] = 0;  // @155_4c3f40
  X2[3] = 0;  // @156_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @157_4c3f40
  ebx = 0;  // @158_4c3f40
  FL[3] = ebx;  // @159_4c3f40
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @160_4c3f40
  X3[1] = 0;  // @161_4c3f40
  X3[2] = 0;  // @162_4c3f40
  X3[3] = 0;  // @163_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 142) + 0), 4); v; });  // @164_4c3f40
  X0[1] = 0;  // @165_4c3f40
  X0[2] = 0;  // @166_4c3f40
  X0[3] = 0;  // @167_4c3f40
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }));  // @168_4c3f40
  FL[3] = ecx;  // @169_4c3f40
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @170_4c3f40
  X1[0] = F2U((float)(s32)X1[0]);  // @171_4c3f40
  X1[1] = F2U((float)(s32)X1[1]);  // @172_4c3f40
  X1[2] = F2U((float)(s32)X1[2]);  // @173_4c3f40
  X1[3] = F2U((float)(s32)X1[3]);  // @174_4c3f40
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @175_4c3f40
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @176_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 20) + 0), &X1[0], 4);  // @177_4c3f40
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L4c4442;  // @178_4c3f40
  L4c4150:;
  X2[0] = X1[0];  // @180_4c3f40
  X2[1] = X1[1];  // @181_4c3f40
  X2[2] = X1[2];  // @182_4c3f40
  X2[3] = X1[3];  // @183_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 64) + 0), 4); v; });  // @184_4c3f40
  X0[1] = 0;  // @185_4c3f40
  X0[2] = 0;  // @186_4c3f40
  X0[3] = 0;  // @187_4c3f40
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 24) + 0), 4); v; })));  // @188_4c3f40
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 150) + 0), 4); v; });  // @189_4c3f40
  X1[1] = 0;  // @190_4c3f40
  X1[2] = 0;  // @191_4c3f40
  X1[3] = 0;  // @192_4c3f40
  ecx = (u32)((EBP - 224) + 52);  // @193_4c3f40
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @194_4c3f40
  X2[0] = F2U(U2F(X2[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 24) + 0), 4); v; })));  // @195_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @196_4c3f40
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @197_4c3f40
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 154) + 0), 4); v; });  // @198_4c3f40
  X1[1] = 0;  // @199_4c3f40
  X1[2] = 0;  // @200_4c3f40
  X1[3] = 0;  // @201_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 88) + 0), &X0[0], 4);  // @202_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 68) + 0), 4); v; });  // @203_4c3f40
  X0[1] = 0;  // @204_4c3f40
  X0[2] = 0;  // @205_4c3f40
  X0[3] = 0;  // @206_4c3f40
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @207_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @208_4c3f40
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @209_4c3f40
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 158) + 0), 4); v; });  // @210_4c3f40
  X1[1] = 0;  // @211_4c3f40
  X1[2] = 0;  // @212_4c3f40
  X1[3] = 0;  // @213_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 92) + 0), &X0[0], 4);  // @214_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 72) + 0), 4); v; });  // @215_4c3f40
  X0[1] = 0;  // @216_4c3f40
  X0[2] = 0;  // @217_4c3f40
  X0[3] = 0;  // @218_4c3f40
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @219_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @220_4c3f40
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @221_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 96) + 0), &X0[0], 4);  // @222_4c3f40
  eax = ext_4e0a10_thiscall1(ecx);  // @223_4c3f40
  ecx = edx = 0;  // @224_4c3f40
  edx = (u32)(esi + 82);  // @225_4c3f40
  ecx = (u32)((EBP - 224) + 52);  // @226_4c3f40
  eax = ext_4e0980_fastcall2(ecx, edx);  // @227_4c3f40
    // @228_4c3f40
  edx = (u32)((EBP - 224) + 112);  // @229_4c3f40
  ecx = (u32)((EBP - 224) + 52);  // @230_4c3f40
  eax = ext_4419f0_fastcall2(ecx, edx);  // @231_4c3f40
  ecx = edx = 0;  // @232_4c3f40
  edx = (u32)((EBP - 224) + 52);  // @233_4c3f40
  ecx = (u32)((EBP - 224) + 88);  // @234_4c3f40
  eax = ext_441940_fastcall2(ecx, edx);  // @235_4c3f40
  ecx = edx = 0;  // @236_4c3f40
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 106) + 0), 4); v; });  // @237_4c3f40
  X1[1] = 0;  // @238_4c3f40
  X1[2] = 0;  // @239_4c3f40
  X1[3] = 0;  // @240_4c3f40
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 102) + 0), 4); v; });  // @241_4c3f40
  X2[1] = 0;  // @242_4c3f40
  X2[2] = 0;  // @243_4c3f40
  X2[3] = 0;  // @244_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 110) + 0), 4); v; });  // @245_4c3f40
  X0[1] = 0;  // @246_4c3f40
  X0[2] = 0;  // @247_4c3f40
  X0[3] = 0;  // @248_4c3f40
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @249_4c3f40
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @250_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @251_4c3f40
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @252_4c3f40
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @253_4c3f40
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @254_4c3f40
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @255_4c3f40
  ecx = edx = 0;  // @256_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @257_4c3f40
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @258_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @259_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 232) + 24) + 0), &X0[0], 4);  // @260_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @261_4c3f40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6897740), (u32)(323));  // @262_4c3f40
  ecx = edx = 0;  // @263_4c3f40
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @264_4c3f40
  X1[1] = 0;  // @265_4c3f40
  X1[2] = 0;  // @266_4c3f40
  X1[3] = 0;  // @267_4c3f40
  eax = (u32)((EBP - 224) + 112);  // @268_4c3f40
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 224) + 12)) :: "st");  // @269_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 12) + 0), 4); v; });  // @270_4c3f40
  X0[1] = 0;  // @271_4c3f40
  X0[2] = 0;  // @272_4c3f40
  X0[3] = 0;  // @273_4c3f40
  edx = (u32)(esi + 102);  // @274_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 114) + 0), 4); v; })));  // @275_4c3f40
  ecx = (u32)((EBP - 224) + 100);  // @276_4c3f40
  PV[5] = (u32)(eax);  // @277_4c3f40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 228) + 80), &v, sizeof v); }  // @278_4c3f40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 228) + 84), &v, sizeof v); }  // @279_4c3f40
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @280_4c3f40
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 228) + 20) + 0), 4); v; })));  // @281_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 228) + 88) + 0), &X1[0], 4);  // @282_4c3f40
  eax = ext_441970_fastcall3(ecx, edx, PV[5]);  // @283_4c3f40
  ecx = edx = 0;  // @284_4c3f40
  edx = (u32)((EBP - 228) + 104);  // @285_4c3f40
  ecx = (u32)((EBP - 228) + 188);  // @286_4c3f40
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @287_4c3f40
  ecx = edx = 0;  // @288_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @289_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 94) + 0), 4); v; });  // @290_4c3f40
  X0[1] = 0;  // @291_4c3f40
  X0[2] = 0;  // @292_4c3f40
  X0[3] = 0;  // @293_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 32) + 0), &X0[0], 4);  // @294_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 98) + 0), 4); v; });  // @295_4c3f40
  X0[1] = 0;  // @296_4c3f40
  X0[2] = 0;  // @297_4c3f40
  X0[3] = 0;  // @298_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @299_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 232) + 36) + 0), &X0[0], 4);  // @300_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @301_4c3f40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6897740), (u32)(336));  // @302_4c3f40
  ecx = edx = 0;  // @303_4c3f40
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6818400)) : "st");  // @304_4c3f40
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6806040)) : "st");  // @305_4c3f40
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 224) + 16)) :: "st");  // @306_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @307_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @308_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @309_4c3f40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6897740), (u32)(337));  // @310_4c3f40
  ecx = edx = 0;  // @311_4c3f40
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 28) + 0), 4); v; });  // @312_4c3f40
  X1[1] = 0;  // @313_4c3f40
  X1[2] = 0;  // @314_4c3f40
  X1[3] = 0;  // @315_4c3f40
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 32) + 0), 4); v; })));  // @316_4c3f40
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 224) + 12)) :: "st");  // @317_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 12) + 0), 4); v; });  // @318_4c3f40
  X0[1] = 0;  // @319_4c3f40
  X0[2] = 0;  // @320_4c3f40
  X0[3] = 0;  // @321_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @322_4c3f40
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 32) + 0), 4); v; })));  // @323_4c3f40
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @324_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 32) + 0), &X0[0], 4);  // @325_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 32) + 4), &X0[1], 4);  // @326_4c3f40
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @327_4c3f40
  ecx = edx = 0;  // @328_4c3f40
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @329_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 12) + 0), &X0[0], 4);  // @330_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 16) + 0), 4); v; });  // @331_4c3f40
  X0[1] = 0;  // @332_4c3f40
  X0[2] = 0;  // @333_4c3f40
  X0[3] = 0;  // @334_4c3f40
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @335_4c3f40
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @336_4c3f40
  ecx = edx = 0;  // @337_4c3f40
  X1[0] = 0;  // @338_4c3f40
  X1[1] = 0;  // @339_4c3f40
  X1[2] = 0;  // @340_4c3f40
  X1[3] = 0;  // @341_4c3f40
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @342_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 16) + 0), 4); v; });  // @343_4c3f40
  X0[1] = 0;  // @344_4c3f40
  X0[2] = 0;  // @345_4c3f40
  X0[3] = 0;  // @346_4c3f40
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 12) + 0), 4); v; })));  // @347_4c3f40
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @348_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 52) + 0), &X1[0], 4);  // @349_4c3f40
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @350_4c3f40
  ecx = edx = 0;  // @351_4c3f40
  X1[0] = 0;  // @352_4c3f40
  X1[1] = 0;  // @353_4c3f40
  X1[2] = 0;  // @354_4c3f40
  X1[3] = 0;  // @355_4c3f40
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @356_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 32) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 32) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @357_4c3f40
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 12) + 0), 4); v; })));  // @358_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 56) + 0), &X1[0], 4);  // @359_4c3f40
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @360_4c3f40
  ecx = edx = 0;  // @361_4c3f40
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @362_4c3f40
  edx = (u32)((EBP - 228) + 56);  // @363_4c3f40
  ecx = (u32)((EBP - 228) + 152);  // @364_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 228) + 64) + 0), &X0[0], 4);  // @365_4c3f40
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @366_4c3f40
  ecx = edx = 0;  // @367_4c3f40
  edx = (u32)((EBP - 224) + 148);  // @368_4c3f40
  ecx = (u32)((EBP - 224) + 76);  // @369_4c3f40
  eax = ext_4419f0_fastcall2(ecx, edx);  // @370_4c3f40
  ecx = edx = 0;  // @371_4c3f40
  edx = (u32)((EBP - 224) + 184);  // @372_4c3f40
  ecx = (u32)((EBP - 224) + 76);  // @373_4c3f40
  eax = ext_4419f0_fastcall2(ecx, edx);  // @374_4c3f40
  ecx = edx = 0;  // @375_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 20) + 0), 4); v; });  // @376_4c3f40
  X0[1] = 0;  // @377_4c3f40
  X0[2] = 0;  // @378_4c3f40
  X0[3] = 0;  // @379_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @380_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @381_4c3f40
  PV[6] = (u32)(ecx);  // @382_4c3f40
  edx = 0;  // @383_4c3f40
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @384_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @385_4c3f40
  eax = (eax - ecx);  // @386_4c3f40
  FL[3] = eax;  // @387_4c3f40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 228) + 48), sizeof v); (u32)v; });  // @388_4c3f40
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @389_4c3f40
  X0[0] = F2U((float)(s32)X0[0]);  // @390_4c3f40
  X0[1] = F2U((float)(s32)X0[1]);  // @391_4c3f40
  X0[2] = F2U((float)(s32)X0[2]);  // @392_4c3f40
  X0[3] = F2U((float)(s32)X0[3]);  // @393_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @394_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @395_4c3f40
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @396_4c3f40
  PV[7] = eax;  // @397_4c3f40
  edx = (u32)((EBP - 228) + 80);  // @398_4c3f40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @399_4c3f40
  PV[8] = (u32)(edx);  // @400_4c3f40
  edx = (u32)((EBP - 232) + 96);  // @401_4c3f40
  PV[9] = (u32)(edx);  // @402_4c3f40
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 134), sizeof v); (u32)v; });  // @403_4c3f40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[10], PV[9], PV[8], PV[7]);  // @404_4c3f40
  ecx = edx = 0;  // @405_4c3f40
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 20) + 0), 4); v; });  // @406_4c3f40
  X1[1] = 0;  // @407_4c3f40
  X1[2] = 0;  // @408_4c3f40
  X1[3] = 0;  // @409_4c3f40
  X2[0] = 0;  // @410_4c3f40
  X2[1] = 0;  // @411_4c3f40
  X2[2] = 0;  // @412_4c3f40
  X2[3] = 0;  // @413_4c3f40
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 74) + 0), 4); v; })));  // @414_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 142) + 0), 4); v; });  // @415_4c3f40
  X0[1] = 0;  // @416_4c3f40
  X0[2] = 0;  // @417_4c3f40
  X0[3] = 0;  // @418_4c3f40
  ebx = (ebx + 1);  // @419_4c3f40
  FL[3] = ebx;  // @420_4c3f40
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @421_4c3f40
  __builtin_memcpy((void *)((u32)((EBP - 224) + 20) + 0), &X1[0], 4);  // @422_4c3f40
  if ((!(!(U2F(X2[0]) >= U2F(X0[0]))) && !(!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L4c4150;  // @423_4c3f40
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @424_4c3f40
  X3[1] = 0;  // @425_4c3f40
  X3[2] = 0;  // @426_4c3f40
  X3[3] = 0;  // @427_4c3f40
  edi = (u32)(esi + 138);  // @428_4c3f40
  L4c4442:;
  X0[0] = ebx; X0[1] = X0[2] = X0[3] = 0;  // @430_4c3f40
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @431_4c3f40
  ebx = (ebx >> (u32)(31));  // @432_4c3f40
  FL[3] = ebx;  // @433_4c3f40
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 4), 4); v; })));  // @434_4c3f40
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @435_4c3f40
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 74) + 0), 4); v; })));  // @436_4c3f40
  X0[0] = X1[0];  // @437_4c3f40
  X0[1] = X1[1];  // @438_4c3f40
  X0[2] = X1[2];  // @439_4c3f40
  X0[3] = X1[3];  // @440_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @441_4c3f40
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @442_4c3f40
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @443_4c3f40
  X0[0] = F2U((float)(s32)X0[0]);  // @444_4c3f40
  X0[1] = F2U((float)(s32)X0[1]);  // @445_4c3f40
  X0[2] = F2U((float)(s32)X0[2]);  // @446_4c3f40
  X0[3] = F2U((float)(s32)X0[3]);  // @447_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @448_4c3f40
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @449_4c3f40
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 142) + 0), 4); v; })));  // @450_4c3f40
  X0[0] = X1[0];  // @451_4c3f40
  X0[1] = X1[1];  // @452_4c3f40
  X0[2] = X1[2];  // @453_4c3f40
  X0[3] = X1[3];  // @454_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @455_4c3f40
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @456_4c3f40
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @457_4c3f40
  eax = (eax + ecx);  // @458_4c3f40
  FL[3] = eax;  // @459_4c3f40
  X0[0] = F2U((float)(s32)X0[0]);  // @460_4c3f40
  X0[1] = F2U((float)(s32)X0[1]);  // @461_4c3f40
  X0[2] = F2U((float)(s32)X0[2]);  // @462_4c3f40
  X0[3] = F2U((float)(s32)X0[3]);  // @463_4c3f40
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @464_4c3f40
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @465_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 64) + 0), 4); v; });  // @466_4c3f40
  X0[1] = 0;  // @467_4c3f40
  X0[2] = 0;  // @468_4c3f40
  X0[3] = 0;  // @469_4c3f40
  __builtin_memcpy((void *)((u32)(esi + 142) + 0), &X1[0], 4);  // @470_4c3f40
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @471_4c3f40
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @472_4c3f40
  __builtin_memcpy((void *)((u32)(esi + 150) + 0), &X0[0], 4);  // @473_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 68) + 0), 4); v; });  // @474_4c3f40
  X0[1] = 0;  // @475_4c3f40
  X0[2] = 0;  // @476_4c3f40
  X0[3] = 0;  // @477_4c3f40
  __builtin_memcpy((void *)((u32)(esi + 154) + 0), &X0[0], 4);  // @478_4c3f40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 224) + 72) + 0), 4); v; });  // @479_4c3f40
  X0[1] = 0;  // @480_4c3f40
  X0[2] = 0;  // @481_4c3f40
  X0[3] = 0;  // @482_4c3f40
  __builtin_memcpy((void *)((u32)(esi + 158) + 0), &X0[0], 4);  // @483_4c3f40
  L4c44d9:;
  ext_633654(G(u32, 0x6f5630));  // @485_4c3f40
  return eax;  // @486_4c3f40
}
PCREG(4c3f40, lifted_4c3f40);

extern "C" u32 THISCALL lifted_4593a0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x4a0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x3a0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x3a0 + 8, &a0, 4);
  __builtin_memcpy(F + 0x3a0 + 12, &a1, 4);
  __builtin_memcpy(F + 0x3a0 + 16, &a2, 4);
  __builtin_memcpy(F + 0x3a0 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_4593a0
  eax = ecx;  // @1_4593a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_4593a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4593a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 740), &v, sizeof v); }  // @4_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; });  // @5_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 736), &v, sizeof v); }  // @6_4593a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 744), &v, sizeof v); }  // @7_4593a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_4593a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 776), &v, sizeof v); }  // @9_4593a0
  FL[2] = (edx & edx);  // @10_4593a0
  if (FL[2] != 0) goto L459404;  // @11_4593a0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 740), sizeof v); (u32)v; });  // @12_4593a0
  PV[1] = (u32)(ecx);  // @13_4593a0
  PV[2] = (u32)(esi);  // @14_4593a0
  PV[3] = (u32)(edi);  // @15_4593a0
  ecx = eax;  // @16_4593a0
  eax = ext_45dc90_thiscall5(ecx, PV[3], PV[2], PV[1], PV[0]);  // @17_4593a0
  ecx = edx = 0;  // @18_4593a0
  ext_633654(G(u32, 0x6f5630));  // @19_4593a0
  return eax;  // @20_4593a0
  L459404:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_4593a0
  PV[4] = (u32)(edx);  // @23_4593a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @26_4593a0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[4]);  // @27_4593a0
  ecx = edx = 0;  // @28_4593a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4593a0
  edi = eax;  // @30_4593a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 756), &v, sizeof v); }  // @31_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 60) + 0), 4); v; });  // @33_4593a0
  X0[1] = 0;  // @34_4593a0
  X0[2] = 0;  // @35_4593a0
  X0[3] = 0;  // @36_4593a0
  __builtin_memcpy((void *)((u32)(EBP - 772) + 0), &X0[0], 4);  // @37_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 188), sizeof v); (u32)v; });  // @38_4593a0
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @39_4593a0
  ecx = edx = 0;  // @40_4593a0
  ecx = eax;  // @41_4593a0
  FL[2] = (ecx & ecx);  // @42_4593a0
  if (FL[2] == 0) goto L459488;  // @43_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_4593a0
  PV[5] = (u32)(ecx);  // @45_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @46_4593a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6829860), (u32)(1065353216));  // @47_4593a0
  ecx = edx = 0;  // @48_4593a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 748)) :: "st");  // @49_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 748) + 0), 4); v; });  // @50_4593a0
  X0[1] = 0;  // @51_4593a0
  X0[2] = 0;  // @52_4593a0
  X0[3] = 0;  // @53_4593a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @54_4593a0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @55_4593a0
  if (__builtin_parity(FL[2] & 0xff)) goto L459966;  // @56_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @58_4593a0
  __builtin_memcpy((void *)((u32)(eax + 4749) + 0), &X0[0], 4);  // @59_4593a0
  L459488:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @62_4593a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }); FL[1] = eax;  // @63_4593a0
  if (FL[0] == FL[1]) goto L4594b7;  // @64_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @65_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_4593a0
  PV[6] = (u32)(ecx);  // @67_4593a0
  ecx = edi;  // @68_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @69_4593a0
  X0[1] = 0;  // @70_4593a0
  X0[2] = 0;  // @71_4593a0
  X0[3] = 0;  // @72_4593a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @73_4593a0
  PV[7] = X0[0];  // @74_4593a0
  eax = ext_459c40_thiscall2(ecx, PV[7]);  // @75_4593a0
  ecx = edx = 0;  // @76_4593a0
  L4594b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @78_4593a0
  ecx = (u32)(esi + 120);  // @79_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @80_4593a0
  X0[1] = 0;  // @81_4593a0
  X0[2] = 0;  // @82_4593a0
  X0[3] = 0;  // @83_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 748), &v, sizeof v); }  // @84_4593a0
  eax = (u32)(EBP - 208);  // @85_4593a0
  PV[8] = (u32)(eax);  // @86_4593a0
  __builtin_memcpy((void *)((u32)(EBP - 784) + 0), &X0[0], 4);  // @87_4593a0
  eax = ext_445e10_thiscall2(ecx, PV[8]);  // @88_4593a0
  edx = 0;  // @89_4593a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @90_4593a0
  edx = eax;  // @91_4593a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 752), &v, sizeof v); }  // @92_4593a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 88), &v, sizeof v); }  // @93_4593a0
  eax = (u32)(ecx + 92);  // @94_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 760), &v, sizeof v); }  // @95_4593a0
  esi = eax;  // @96_4593a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 728), &v, sizeof v); }  // @97_4593a0
  eax = (u32)(ecx + 88);  // @98_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 780), &v, sizeof v); }  // @99_4593a0
  FL[2] = (edx & edx);  // @100_4593a0
  if (FL[2] == 0) goto L459685;  // @101_4593a0
  edi = (u32)(EBP - 204);  // @102_4593a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 724), &v, sizeof v); }  // @103_4593a0
  L459520:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi - 4) + 0), 4); v; });  // @105_4593a0
  X0[1] = 0;  // @106_4593a0
  X0[2] = 0;  // @107_4593a0
  X0[3] = 0;  // @108_4593a0
  X1[0] = 0;  // @109_4593a0
  X1[1] = 0;  // @110_4593a0
  X1[2] = 0;  // @111_4593a0
  X1[3] = 0;  // @112_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @113_4593a0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @114_4593a0
  X2[1] = 0;  // @115_4593a0
  X2[2] = 0;  // @116_4593a0
  X2[3] = 0;  // @117_4593a0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @118_4593a0
  X3[1] = 0;  // @119_4593a0
  X3[2] = 0;  // @120_4593a0
  X3[3] = 0;  // @121_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @122_4593a0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @123_4593a0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X2[0], 4);  // @124_4593a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @125_4593a0
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X3[0], 4);  // @126_4593a0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @127_4593a0
  if (!__builtin_parity(FL[2] & 0xff)) goto L459560;  // @128_4593a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @129_4593a0
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @130_4593a0
  if (!__builtin_parity(FL[2] & 0xff)) goto L459560;  // @131_4593a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @132_4593a0
  FL[2] = ((u32)(0x02 | (!(U2F(X3[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X3[0]) != U2F(X3[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @133_4593a0
  if (__builtin_parity(FL[2] & 0xff)) goto L4595a8;  // @134_4593a0
  L459560:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 732), &v, sizeof v); }  // @136_4593a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 728), sizeof v); (u32)v; });  // @137_4593a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @138_4593a0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @139_4593a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @140_4593a0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @141_4593a0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @142_4593a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @143_4593a0
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @144_4593a0
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @145_4593a0
  __asm__ volatile("fsqrt" ::: "st");  // @146_4593a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 732)) : "st");  // @147_4593a0
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @148_4593a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @149_4593a0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @150_4593a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @151_4593a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @152_4593a0
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @153_4593a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @154_4593a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @155_4593a0
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @156_4593a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @157_4593a0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 732)) :: "st");  // @158_4593a0
  L4595a8:;
  ecx = esi;  // @160_4593a0
  eax = ext_4e09b0_thiscall1(ecx);  // @161_4593a0
    // @162_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @163_4593a0
  X0[1] = 0;  // @164_4593a0
  X0[2] = 0;  // @165_4593a0
  X0[3] = 0;  // @166_4593a0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829932) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829932) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829932) + 0), 4); v; }))))))) goto L4595ca;  // @167_4593a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 772) + 0), 4); v; });  // @168_4593a0
  X1[1] = 0;  // @169_4593a0
  X1[2] = 0;  // @170_4593a0
  X1[3] = 0;  // @171_4593a0
  __builtin_memcpy((void *)((u32)(esi + 12) + 0), &X1[0], 4);  // @172_4593a0
  L4595ca:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6829944) + 0), 4); v; });  // @174_4593a0
  X1[1] = 0;  // @175_4593a0
  X1[2] = 0;  // @176_4593a0
  X1[3] = 0;  // @177_4593a0
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4595de;  // @178_4593a0
  { u32 v = (u32)((u32)(3276275712)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @179_4593a0
  L4595de:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @181_4593a0
  X0[1] = 0;  // @182_4593a0
  X0[2] = 0;  // @183_4593a0
  X0[3] = 0;  // @184_4593a0
  edx = esi;  // @185_4593a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @186_4593a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @187_4593a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @188_4593a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @189_4593a0
  __builtin_memcpy((void *)((u32)(esi + 12) + 0), &X0[0], 4);  // @190_4593a0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @191_4593a0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @192_4593a0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @193_4593a0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @194_4593a0
  PV[9] = (u32)(ecx);  // @195_4593a0
  ecx = (u32)(EBP - 16);  // @196_4593a0
  PV[10] = X0[0];  // @197_4593a0
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[10]);  // @198_4593a0
    // @199_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 740), sizeof v); (u32)v; });  // @200_4593a0
  ecx = (u32)(EBP - 16);  // @201_4593a0
  eax = ext_43e960_fastcall2(ecx, edx);  // @202_4593a0
  ecx = edx = 0;  // @203_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 744), sizeof v); (u32)v; });  // @204_4593a0
  ecx = esi;  // @205_4593a0
  eax = ext_441a60_fastcall2(ecx, edx);  // @206_4593a0
  ecx = edx = 0;  // @207_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 744), sizeof v); (u32)v; });  // @208_4593a0
  ecx = (u32)(EBP - 16);  // @209_4593a0
  eax = ext_441a60_fastcall2(ecx, edx);  // @210_4593a0
  ecx = edx = 0;  // @211_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @212_4593a0
  X0[1] = 0;  // @213_4593a0
  X0[2] = 0;  // @214_4593a0
  X0[3] = 0;  // @215_4593a0
  edi = (edi + (u32)(16));  // @216_4593a0
  FL[3] = edi;  // @217_4593a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; })));  // @218_4593a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @219_4593a0
  X1[1] = 0;  // @220_4593a0
  X1[2] = 0;  // @221_4593a0
  X1[3] = 0;  // @222_4593a0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; })));  // @223_4593a0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @224_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @225_4593a0
  X0[1] = 0;  // @226_4593a0
  X0[2] = 0;  // @227_4593a0
  X0[3] = 0;  // @228_4593a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @229_4593a0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @230_4593a0
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @231_4593a0
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @232_4593a0
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @233_4593a0
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @234_4593a0
  __builtin_memcpy((void *)((u32)(esi + 12) + 0), &X1[0], 4);  // @235_4593a0
  esi = (esi + (u32)(16));  // @236_4593a0
  FL[3] = esi;  // @237_4593a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 724), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 724), &v, sizeof v); }  // @238_4593a0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 724), sizeof v); (u32)v; });  // @239_4593a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 728), &v, sizeof v); }  // @240_4593a0
  if (FL[3] != 0) goto L459520;  // @241_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 752), sizeof v); (u32)v; });  // @242_4593a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @243_4593a0
  L459685:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 80), sizeof v); (u32)v; });  // @245_4593a0
  esi = 0;  // @246_4593a0
  FL[3] = esi;  // @247_4593a0
  edi = 0;  // @248_4593a0
  FL[3] = edi;  // @249_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 724), &v, sizeof v); }  // @250_4593a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 728), &v, sizeof v); }  // @251_4593a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 732), &v, sizeof v); }  // @252_4593a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; }); FL[1] = esi;  // @253_4593a0
  if (FL[0] == FL[1]) goto L4597ec;  // @254_4593a0
  L4596b0:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @256_4593a0
  X2[1] = 0;  // @257_4593a0
  X2[2] = 0;  // @258_4593a0
  X2[3] = 0;  // @259_4593a0
  ecx = 0;  // @260_4593a0
  FL[3] = ecx;  // @261_4593a0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X2[0], 4);  // @262_4593a0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @263_4593a0
  X3[1] = 0;  // @264_4593a0
  X3[2] = 0;  // @265_4593a0
  X3[3] = 0;  // @266_4593a0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X3[0], 4);  // @267_4593a0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @268_4593a0
  X4[1] = 0;  // @269_4593a0
  X4[2] = 0;  // @270_4593a0
  X4[3] = 0;  // @271_4593a0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X4[0], 4);  // @272_4593a0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 12) + 0), 4); v; });  // @273_4593a0
  X5[1] = 0;  // @274_4593a0
  X5[2] = 0;  // @275_4593a0
  X5[3] = 0;  // @276_4593a0
  FL[2] = (edx & edx);  // @277_4593a0
  if (FL[2] == 0) goto L459725;  // @278_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 760), sizeof v); (u32)v; });  // @279_4593a0
  eax = (eax + (u32)(8));  // @280_4593a0
  FL[3] = eax;  // @281_4593a0
  L4596e1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 4) + 0), 4); v; });  // @283_4593a0
  X0[1] = 0;  // @284_4593a0
  X0[2] = 0;  // @285_4593a0
  X0[3] = 0;  // @286_4593a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 8) + 0), 4); v; });  // @287_4593a0
  X1[1] = 0;  // @288_4593a0
  X1[2] = 0;  // @289_4593a0
  X1[3] = 0;  // @290_4593a0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @291_4593a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @292_4593a0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @293_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @294_4593a0
  X0[1] = 0;  // @295_4593a0
  X0[2] = 0;  // @296_4593a0
  X0[3] = 0;  // @297_4593a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @298_4593a0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @299_4593a0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @300_4593a0
  if ((!(!(U2F(X1[0]) >= U2F(X5[0]))) && !(!((U2F(X1[0]) < U2F(X5[0])) || (U2F(X1[0]) > U2F(X5[0])))))) goto L459717;  // @301_4593a0
  ecx = (ecx + 1);  // @302_4593a0
  FL[3] = ecx;  // @303_4593a0
  eax = (eax + (u32)(16));  // @304_4593a0
  FL[3] = eax;  // @305_4593a0
  FL[0] = ecx; FL[1] = edx;  // @306_4593a0
  if (FL[0] != FL[1]) goto L4596e1;  // @307_4593a0
  goto L45971f;  // @308_4593a0
  L459717:;
  FL[0] = ecx; FL[1] = edx;  // @310_4593a0
  if (FL[0] != FL[1]) goto L4597c7;  // @311_4593a0
  L45971f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 724), sizeof v); (u32)v; });  // @313_4593a0
  L459725:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 760), sizeof v); (u32)v; });  // @315_4593a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 768), &v, sizeof v); }  // @316_4593a0
  FL[2] = (edx & edx);  // @317_4593a0
  if (FL[2] == 0) goto L459855;  // @318_4593a0
  L459740:;
  eax = (eax + (u32)(16));  // @320_4593a0
  FL[3] = eax;  // @321_4593a0
  edi = 0;  // @322_4593a0
  FL[3] = edi;  // @323_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 764), &v, sizeof v); }  // @324_4593a0
  L459750:;
  ecx = (u32)(EBP - 16);  // @326_4593a0
  edx = eax;  // @327_4593a0
  PV[11] = (u32)(ecx);  // @328_4593a0
  ecx = (u32)(EBP - 796);  // @329_4593a0
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[11]);  // @330_4593a0
  ecx = edx = 0;  // @331_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @332_4593a0
  X0[1] = 0;  // @333_4593a0
  X0[2] = 0;  // @334_4593a0
  X0[3] = 0;  // @335_4593a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 796) + 0), 4); v; })));  // @336_4593a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @337_4593a0
  X1[1] = 0;  // @338_4593a0
  X1[2] = 0;  // @339_4593a0
  X1[3] = 0;  // @340_4593a0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 792) + 0), 4); v; })));  // @341_4593a0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @342_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @343_4593a0
  X0[1] = 0;  // @344_4593a0
  X0[2] = 0;  // @345_4593a0
  X0[3] = 0;  // @346_4593a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 788) + 0), 4); v; })));  // @347_4593a0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @348_4593a0
  X0[0] = 0;  // @349_4593a0
  X0[1] = 0;  // @350_4593a0
  X0[2] = 0;  // @351_4593a0
  X0[3] = 0;  // @352_4593a0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; })));  // @353_4593a0
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L45982b;  // @354_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 764), sizeof v); (u32)v; });  // @355_4593a0
  edi = (edi + 1);  // @356_4593a0
  FL[3] = edi;  // @357_4593a0
  eax = (eax + (u32)(12));  // @358_4593a0
  FL[3] = eax;  // @359_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 764), &v, sizeof v); }  // @360_4593a0
  FL[0] = edi; FL[1] = (u32)(8);  // @361_4593a0
  if (FL[0] != FL[1]) goto L459750;  // @362_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 752), sizeof v); (u32)v; });  // @363_4593a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 728), sizeof v); (u32)v; });  // @364_4593a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 732), sizeof v); (u32)v; });  // @365_4593a0
  L4597c7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @367_4593a0
  esi = (esi + 1);  // @368_4593a0
  FL[3] = esi;  // @369_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 724), sizeof v); (u32)v; });  // @370_4593a0
  eax = (eax + (u32)(112));  // @371_4593a0
  FL[3] = eax;  // @372_4593a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 732), &v, sizeof v); }  // @373_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 724), &v, sizeof v); }  // @374_4593a0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @375_4593a0
  if (FL[0] != FL[1]) goto L4596b0;  // @376_4593a0
  L4597ec:;
  edx = 0;  // @378_4593a0
  FL[3] = edx;  // @379_4593a0
  esi = 0;  // @380_4593a0
  FL[3] = esi;  // @381_4593a0
  FL[2] = (edi & edi);  // @382_4593a0
  if (FL[2] == 0) goto L459966;  // @383_4593a0
  ecx = 0;  // @384_4593a0
  FL[3] = ecx;  // @385_4593a0
  L459800:;
  edi = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 720), sizeof v); (u32)v; }) * (s32)(u32)(112));  // @387_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @388_4593a0
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; }));  // @389_4593a0
  FL[3] = edi;  // @390_4593a0
  FL[0] = edx; FL[1] = (u32)(32);  // @391_4593a0
  if (FL[0] == FL[1]) goto L45987a;  // @392_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @393_4593a0
  eax = (eax - 1);  // @394_4593a0
  FL[3] = eax;  // @395_4593a0
  FL[0] = esi; FL[1] = eax;  // @396_4593a0
  if (FL[0] == FL[1]) goto L45987a;  // @397_4593a0
  FL[2] = (edx & edx);  // @398_4593a0
  if (FL[2] != 0) goto L45992b;  // @399_4593a0
  goto L4598a9;  // @400_4593a0
  L45982b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 768), sizeof v); (u32)v; });  // @402_4593a0
  esi = (esi + (u32)(16));  // @403_4593a0
  FL[3] = esi;  // @404_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 752), sizeof v); (u32)v; });  // @405_4593a0
  ecx = (ecx + 1);  // @406_4593a0
  FL[3] = ecx;  // @407_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 724), sizeof v); (u32)v; });  // @408_4593a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 768), &v, sizeof v); }  // @409_4593a0
  FL[0] = ecx; FL[1] = edx;  // @410_4593a0
  if (FL[0] != FL[1]) goto L459740;  // @411_4593a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 728), sizeof v); (u32)v; });  // @412_4593a0
  L459855:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 732), sizeof v); (u32)v; });  // @414_4593a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + edi*4 - 720), &v, sizeof v); }  // @415_4593a0
  edi = (edi + 1);  // @416_4593a0
  FL[3] = edi;  // @417_4593a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 728), &v, sizeof v); }  // @418_4593a0
  FL[0] = edi; FL[1] = (u32)(128);  // @419_4593a0
  if (FL[0] == FL[1]) goto L4597ec;  // @420_4593a0
  goto L4597c7;  // @421_4593a0
  L45987a:;
  FL[2] = (edx & edx);  // @423_4593a0
  if (FL[2] == 0) goto L459966;  // @424_4593a0
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 740), sizeof v); (u32)v; });  // @425_4593a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @426_4593a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 776), sizeof v); (u32)v; });  // @427_4593a0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 744), sizeof v); (u32)v; });  // @428_4593a0
  PV[14] = (u32)(ecx);  // @429_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @430_4593a0
  ecx = edx;  // @431_4593a0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 748), sizeof v); (u32)v; });  // @432_4593a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[15], PV[14], PV[13], PV[12], (u32)(0));  // @433_4593a0
  ecx = edx = 0;  // @434_4593a0
  edx = 0;  // @435_4593a0
  FL[3] = edx;  // @436_4593a0
  L4598a9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 756), sizeof v); (u32)v; });  // @438_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @439_4593a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @440_4593a0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @441_4593a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 756), sizeof v); (u32)v; });  // @442_4593a0
  if (FL[0] == FL[1]) goto L4598d6;  // @443_4593a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @444_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @445_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @446_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @447_4593a0
  goto L4598d9;  // @448_4593a0
  L4598d6:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @450_4593a0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @451_4593a0
  L4598d9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @453_4593a0
  FL[0] = eax; FL[1] = (u32)(4);  // @454_4593a0
  if (FL[0] >= FL[1]) goto L459966;  // @455_4593a0
  eax = (u32)(eax + eax*4);  // @456_4593a0
  ecx = (ecx + (u32)(212));  // @457_4593a0
  FL[3] = ecx;  // @458_4593a0
  eax = (eax << (u32)(5));  // @459_4593a0
  FL[3] = eax;  // @460_4593a0
  ecx = (ecx + eax);  // @461_4593a0
  FL[3] = ecx;  // @462_4593a0
  if (FL[3] == 0) goto L459966;  // @463_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 780), sizeof v); (u32)v; });  // @464_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 772) + 0), 4); v; });  // @465_4593a0
  X0[1] = 0;  // @466_4593a0
  X0[2] = 0;  // @467_4593a0
  X0[3] = 0;  // @468_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @469_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @470_4593a0
  __builtin_memcpy((void *)((u32)(ecx + 12) + 0), &X0[0], 4);  // @471_4593a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 784) + 0), 4); v; });  // @472_4593a0
  X0[1] = 0;  // @473_4593a0
  X0[2] = 0;  // @474_4593a0
  X0[3] = 0;  // @475_4593a0
  { u32 v = (u32)((u32)(1128792064)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @476_4593a0
  __builtin_memcpy((void *)((u32)(ecx + 24) + 0), &X0[0], 4);  // @477_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @478_4593a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @479_4593a0
  L45992b:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + edx*4 + 32), &v, sizeof v); }  // @481_4593a0
  esi = (esi + 1);  // @482_4593a0
  FL[3] = esi;  // @483_4593a0
  edx = (edx + 1);  // @484_4593a0
  FL[3] = edx;  // @485_4593a0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 728), sizeof v); (u32)v; });  // @486_4593a0
  if (FL[0] != FL[1]) goto L459800;  // @487_4593a0
  FL[2] = (edx & edx);  // @488_4593a0
  if (FL[2] == 0) goto L459966;  // @489_4593a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 776), sizeof v); (u32)v; });  // @490_4593a0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 740), sizeof v); (u32)v; });  // @491_4593a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @492_4593a0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 744), sizeof v); (u32)v; });  // @493_4593a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @494_4593a0
  PV[18] = (u32)(ecx);  // @495_4593a0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 748), sizeof v); (u32)v; });  // @496_4593a0
  ecx = edi;  // @497_4593a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[19], PV[18], PV[17], PV[16], (u32)(0));  // @498_4593a0
  ecx = edx = 0;  // @499_4593a0
  L459966:;
  ext_633654(G(u32, 0x6f5630));  // @501_4593a0
  return eax;  // @502_4593a0
}
PCREG(4593a0, lifted_4593a0);

extern "C" u32 THISCALL lifted_468570(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_468570
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_468570
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @2_468570
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 229), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_468570
  if (FL[0] == FL[1]) goto L4685a3;  // @4_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @5_468570
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(4096));  // @6_468570
  if (FL[2] == 0) goto L4689c8;  // @7_468570
  L4685a3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_468570
  X1[0] = 0;  // @10_468570
  X1[1] = 0;  // @11_468570
  X1[2] = 0;  // @12_468570
  X1[3] = 0;  // @13_468570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @14_468570
  X0[1] = 0;  // @15_468570
  X0[2] = 0;  // @16_468570
  X0[3] = 0;  // @17_468570
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @18_468570
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @19_468570
  if (__builtin_parity(FL[2] & 0xff)) goto L4685f8;  // @20_468570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @21_468570
  X0[1] = 0;  // @22_468570
  X0[2] = 0;  // @23_468570
  X0[3] = 0;  // @24_468570
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @25_468570
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @26_468570
  if (__builtin_parity(FL[2] & 0xff)) goto L4685f8;  // @27_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @29_468570
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @30_468570
  ecx = edx = 0;  // @31_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_468570
  PV[0] = (u32)(edx);  // @33_468570
  PV[1] = (u32)(eax);  // @34_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_468570
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[1], PV[0], (u32)(6852512));  // @36_468570
  ecx = edx = 0;  // @37_468570
  L4685f8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_468570
  ecx = edi;  // @40_468570
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 756)))(ecx);  // @41_468570
  ecx = edx = 0;  // @42_468570
  eax = 0;  // @43_468570
  FL[3] = eax;  // @44_468570
  ecx = ebx;  // @45_468570
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @46_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @47_468570
  PV[2] = (u32)(edi);  // @48_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[2]);  // @49_468570
  ecx = edx = 0;  // @50_468570
  esi = eax;  // @51_468570
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @52_468570
  FL[2] = (esi & esi);  // @53_468570
  if (FL[2] == 0) goto L468623;  // @54_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @55_468570
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @56_468570
  goto L468629;  // @57_468570
  L468623:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @59_468570
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @60_468570
  L468629:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_468570
  ecx = esi;  // @63_468570
  edi = 0;  // @64_468570
  FL[3] = edi;  // @65_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @66_468570
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050579));  // @67_468570
  ecx = edx = 0;  // @68_468570
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @69_468570
  if (FL[2] == 0) goto L468665;  // @70_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_468570
  ecx = esi;  // @72_468570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @74_468570
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @75_468570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 708)))(ecx, PV[3], (u32)(1230259533));  // @76_468570
  ecx = edx = 0;  // @77_468570
  goto L468740;  // @78_468570
  L468665:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 83), sizeof v); (u32)v; });  // @80_468570
  FL[2] = (eax & eax);  // @81_468570
  if (FL[2] != 0) goto L4686d9;  // @82_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @83_468570
  ecx = (u32)(6801640);  // @84_468570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @85_468570
  FL[2] = (eax & eax);  // @86_468570
  if (FL[2] != 0) ecx = eax;  // @87_468570
  PV[4] = (u32)(ecx);  // @88_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @89_468570
  ecx = edx;  // @90_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 780)))(ecx, PV[4]);  // @91_468570
  ecx = edx = 0;  // @92_468570
  edi = eax;  // @93_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @94_468570
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }) & (u32)(1048576));  // @95_468570
  if (FL[2] == 0) goto L4686a7;  // @96_468570
  FL[2] = (edi & edi);  // @97_468570
  if (FL[2] == 0) goto L4686ab;  // @98_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @99_468570
  ecx = edi;  // @100_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @101_468570
  ecx = edx = 0;  // @102_468570
  goto L4686ab;  // @103_468570
  L4686a7:;
  FL[2] = (edi & edi);  // @105_468570
  if (FL[2] != 0) goto L4686cc;  // @106_468570
  L4686ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @109_468570
  PV[5] = (u32)(ecx);  // @110_468570
  ecx = esi;  // @111_468570
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 440)))(ecx, PV[5], (u32)(0), (u32)(0), (u32)(0), (u32)(1));  // @112_468570
  ecx = edx = 0;  // @113_468570
  edi = eax;  // @114_468570
  ecx = edi;  // @115_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @116_468570
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @117_468570
  ecx = edx = 0;  // @118_468570
  goto L468742;  // @119_468570
  L4686cc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @121_468570
  ecx = edi;  // @122_468570
  PV[6] = (u32)(esi);  // @123_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, PV[6]);  // @124_468570
  ecx = edx = 0;  // @125_468570
  goto L468742;  // @126_468570
  L4686d9:;
  FL[0] = eax; FL[1] = (u32)(1);  // @128_468570
  if (FL[0] != FL[1]) goto L4686fb;  // @129_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @130_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @131_468570
  PV[7] = (u32)(eax);  // @132_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_468570
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @134_468570  hand fix: slot 0x20 takes no args, the pushes belong to slot 0x1b8
  ecx = edx = 0;  // @135_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @136_468570
  PV[8] = (u32)(eax);  // @137_468570
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 440)))(ecx, PV[8], (u32)(0), (u32)(0), (u32)(0), PV[7]);  // @138_468570  hand fix
  ecx = edx = 0;  // @139_468570
  goto L468740;  // @140_468570
  L4686fb:;
  FL[0] = eax; FL[1] = (u32)(2);  // @142_468570
  if (FL[0] != FL[1]) goto L468718;  // @143_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @144_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @145_468570
  eax = ext_4db2f0_thiscall2(ecx, (u32)(0));  // @146_468570
  ecx = edx = 0;  // @147_468570
  PV[10] = (u32)(eax);  // @148_468570
  goto L468736;  // @149_468570
  L468718:;
  FL[0] = eax; FL[1] = (u32)(3);  // @151_468570
  if (FL[0] != FL[1]) goto L468742;  // @152_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @153_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @154_468570
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @155_468570
  L468736:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @157_468570
  ecx = esi;  // @158_468570
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 440)))(ecx, PV[10], (u32)(0), (u32)(0), (u32)(0), (u32)(1));  // @159_468570  hand fix: one 5-arg call for both paths
  ecx = edx = 0;  // @160_468570
  L468740:;
  edi = eax;  // @162_468570
  L468742:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @164_468570
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(8388608));  // @165_468570
  ecx = edx = 0;  // @166_468570
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 83), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @167_468570
  if (FL[0] == FL[1]) goto L46875e;  // @168_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @169_468570
  ecx = edi;  // @170_468570
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @171_468570
  ecx = edx = 0;  // @172_468570
  L46875e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @174_468570
  ecx = edi;  // @175_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6850644));  // @176_468570
  ecx = edx = 0;  // @177_468570
  FL[2] = (eax & eax);  // @178_468570
  if (FL[2] == 0) goto L468779;  // @179_468570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @180_468570
  ecx = eax;  // @181_468570
  PV[11] = (u32)(edi);  // @182_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[11]);  // @183_468570
  ecx = edx = 0;  // @184_468570
  L468779:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @186_468570
  FL[2] = (eax & eax);  // @187_468570
  if (FL[2] == 0) goto L46878d;  // @188_468570
  ecx = (u32)(EBP - 16);  // @189_468570
  PV[12] = (u32)(ecx);  // @190_468570
  ecx = (u32)(EBP - 52);  // @191_468570
  PV[13] = (u32)(ecx);  // @192_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @193_468570
  goto L468798;  // @194_468570
  L46878d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @196_468570
  eax = (u32)(EBP - 16);  // @197_468570
  PV[14] = (u32)(eax);  // @198_468570
  eax = (u32)(EBP - 52);  // @199_468570
  PV[15] = (u32)(eax);  // @200_468570
  L468798:;
  PV[14] = (u32)(EBP - 16); PV[15] = (u32)(EBP - 52);  // hand fix: both branches push the same two stack addresses
  eax = ext_4db2c0_thiscall3(ecx, PV[15], PV[14]);  // @202_468570
  ecx = edx = 0;  // @203_468570
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @204_468570
  if (FL[0] == FL[1]) goto L4687c3;  // @205_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @206_468570
  PV[16] = (u32)(edi);  // @207_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @208_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @209_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @210_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @211_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[16]);  // @212_468570
  ecx = edx = 0;  // @213_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @214_468570
  PV[17] = (u32)(eax);  // @215_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 728)))(ecx, PV[17]);  // @216_468570
  ecx = edx = 0;  // @217_468570
  L4687c3:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 83), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @219_468570
  ecx = (u32)(EBP - 16);  // @220_468570
  PV[18] = (u32)(ecx);  // @221_468570
  ecx = (u32)(EBP - 52);  // @222_468570
  PV[19] = (u32)(ecx);  // @223_468570
  if (FL[0] == FL[1]) goto L4687ef;  // @224_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @225_468570
  ecx = esi;  // @226_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @227_468570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[19], PV[18]);  // @228_468570
  ecx = edx = 0;  // @229_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @230_468570
  ecx = (u32)(EBP - 16);  // @231_468570
  PV[20] = (u32)(ecx);  // @232_468570
  ecx = (u32)(EBP - 52);  // @233_468570
  PV[21] = (u32)(ecx);  // @234_468570
  ecx = edi;  // @235_468570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[21], PV[20]);  // @236_468570
  ecx = edx = 0;  // @237_468570
  goto L4687f9;  // @238_468570
  L4687ef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @240_468570
  ecx = edi;  // @241_468570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 116)))(ecx, PV[19], PV[18]);  // @242_468570
  ecx = edx = 0;  // @243_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @244_468570
  L4687f9:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @246_468570
  if (FL[0] == FL[1]) goto L46881f;  // @247_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @248_468570
  PV[22] = (u32)(edi);  // @249_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @250_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @251_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @252_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @253_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[22]);  // @254_468570
  ecx = edx = 0;  // @255_468570
  PV[23] = (u32)(eax);  // @256_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @257_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @258_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, PV[23]);  // @259_468570
  ecx = edx = 0;  // @260_468570
  L46881f:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 95), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @262_468570
  if (FL[0] == FL[1]) goto L468848;  // @263_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @264_468570
  PV[24] = (u32)(edi);  // @265_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 112), sizeof v); (u32)v; });  // @266_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @267_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @268_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @269_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @270_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[24]);  // @271_468570
  ecx = edx = 0;  // @272_468570
  PV[25] = (u32)(eax);  // @273_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @274_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 112), sizeof v); (u32)v; });  // @275_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, PV[25]);  // @276_468570
  ecx = edx = 0;  // @277_468570
  L468848:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @279_468570
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @280_468570
  FL[2] = (ecx & ecx);  // @281_468570
  if (FL[2] == 0) goto L46891c;  // @282_468570
  L468860:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(8388608));  // @284_468570
  if (FL[2] != 0) goto L4688ed;  // @285_468570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @286_468570
  FL[2] = (edx & edx);  // @287_468570
  if (FL[2] == 0) goto L468881;  // @288_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @289_468570
  ecx = edx;  // @290_468570
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @291_468570
  ecx = edx = 0;  // @292_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @293_468570
  L468881:;
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @295_468570
  ecx = edx = 0;  // @296_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @297_468570
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @298_468570
  ecx = 0;  // @299_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @300_468570
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @301_468570
  ecx = 0;  // @302_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @303_468570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @304_468570
  FL[2] = (edx & edx);  // @305_468570
  if (FL[2] == 0) goto L4688c4;  // @306_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @307_468570
  ecx = edx;  // @308_468570
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @309_468570
  ecx = edx = 0;  // @310_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @311_468570
  L4688c4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @313_468570
  FL[2] = (edx & edx);  // @314_468570
  if (FL[2] == 0) goto L4688d3;  // @315_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @316_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @317_468570
  goto L4688d8;  // @318_468570
  L4688d3:;
  eax = (u32)(2097154);  // @320_468570
  L4688d8:;
  FL[2] = (eax & (u32)(4194304));  // @322_468570
  if (FL[2] == 0) goto L4688ed;  // @323_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @324_468570
  ecx = ebx;  // @325_468570
  PV[26] = (u32)(edx);  // @326_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 148)))(ecx, PV[26]);  // @327_468570
  ecx = edx = 0;  // @328_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @329_468570
  L4688ed:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @331_468570
  FL[2] = (ecx & ecx);  // @332_468570
  if (FL[2] == 0) goto L468906;  // @333_468570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @334_468570
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @335_468570
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @336_468570
  PV[28] = (u32)(eax);  // @337_468570
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[28], PV[27], (u32)(0));  // @338_468570
  ecx = edx = 0;  // @339_468570
  L468906:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @341_468570
  ecx = (u32)(EBP - 60);  // @342_468570
  PV[29] = (u32)(ecx);  // @343_468570
  ecx = edi;  // @344_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[29]);  // @345_468570
  ecx = edx = 0;  // @346_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @347_468570
  FL[2] = (ecx & ecx);  // @348_468570
  if (FL[2] != 0) goto L468860;  // @349_468570
  L46891c:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 91) + 0), 4); v; });  // @351_468570
  X0[1] = 0;  // @352_468570
  X0[2] = 0;  // @353_468570
  X0[3] = 0;  // @354_468570
  X1[0] = 0;  // @355_468570
  X1[1] = 0;  // @356_468570
  X1[2] = 0;  // @357_468570
  X1[3] = 0;  // @358_468570
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @359_468570
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @360_468570
  if (__builtin_parity(FL[2] & 0xff)) goto L468976;  // @361_468570
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @362_468570
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @363_468570
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @364_468570
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @365_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @366_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @367_468570
  eax = (eax - ecx);  // @368_468570
  FL[3] = eax;  // @369_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 155), sizeof v); (u32)v; });  // @370_468570
  PV[30] = (u32)(ecx);  // @371_468570
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @372_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @373_468570
  X0[0] = F2U((float)(s32)X0[0]);  // @374_468570
  X0[1] = F2U((float)(s32)X0[1]);  // @375_468570
  X0[2] = F2U((float)(s32)X0[2]);  // @376_468570
  X0[3] = F2U((float)(s32)X0[3]);  // @377_468570
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @378_468570
  PV[31] = X0[0];  // @379_468570
  PV[32] = (u32)(edi);  // @380_468570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[32]);  // @381_468570
  ecx = edx = 0;  // @382_468570
  PV[33] = (u32)(eax);  // @383_468570
  ecx = ebx;  // @384_468570
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 788)))(ecx, PV[33], PV[31]);  // @385_468570
  ecx = edx = 0;  // @386_468570
  X1[0] = 0;  // @387_468570
  X1[1] = 0;  // @388_468570
  X1[2] = 0;  // @389_468570
  X1[3] = 0;  // @390_468570
  L468976:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @392_468570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @393_468570
  X0[1] = 0;  // @394_468570
  X0[2] = 0;  // @395_468570
  X0[3] = 0;  // @396_468570
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @397_468570
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @398_468570
  if (__builtin_parity(FL[2] & 0xff)) goto L4689c7;  // @399_468570
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @400_468570
  X0[1] = 0;  // @401_468570
  X0[2] = 0;  // @402_468570
  X0[3] = 0;  // @403_468570
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @404_468570
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @405_468570
  if (__builtin_parity(FL[2] & 0xff)) goto L4689c7;  // @406_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @407_468570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @408_468570
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @409_468570
  ecx = edx = 0;  // @410_468570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @411_468570
  PV[34] = (u32)(edx);  // @412_468570
  PV[35] = (u32)(eax);  // @413_468570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @414_468570
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[35], PV[34], (u32)(6852512));  // @415_468570
  ecx = edx = 0;  // @416_468570
  L4689c7:;
  L4689c8:;
  ext_633654(G(u32, 0x6f5630));  // @419_468570
  return eax;  // @420_468570
}
PCREG(468570, lifted_468570);

extern "C" u32 THISCALL lifted_4c9b80(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4c9b80
  eax = (u32)(EBP - 112);  // @1_4c9b80
  PV[0] = (u32)(eax);  // @2_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @3_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @4_4c9b80
  eax = ext_4db500_thiscall2(ecx, PV[0]);  // @5_4c9b80
  edx = 0;  // @6_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @7_4c9b80
  eax = (u32)(EBP - 100);  // @8_4c9b80
  PV[1] = (u32)(eax);  // @9_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @10_4c9b80
  eax = ext_4db2a0_thiscall2(ecx, PV[1]);  // @11_4c9b80
  ecx = edx = 0;  // @12_4c9b80
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; });  // @13_4c9b80
  X2[1] = 0;  // @14_4c9b80
  X2[2] = 0;  // @15_4c9b80
  X2[3] = 0;  // @16_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7240060) + 0), 4); v; });  // @17_4c9b80
  X0[1] = 0;  // @18_4c9b80
  X0[2] = 0;  // @19_4c9b80
  X0[3] = 0;  // @20_4c9b80
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L4c9bd4;  // @21_4c9b80
  X0[0] = 0;  // @22_4c9b80
  X0[1] = 0;  // @23_4c9b80
  X0[2] = 0;  // @24_4c9b80
  X0[3] = 0;  // @25_4c9b80
  __builtin_memcpy((void *)((u32)(7240060) + 0), &X0[0], 4);  // @26_4c9b80
  L4c9bd4:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7240064) + 0), 4); v; });  // @28_4c9b80
  X1[1] = 0;  // @29_4c9b80
  X1[2] = 0;  // @30_4c9b80
  X1[3] = 0;  // @31_4c9b80
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4c9bec;  // @32_4c9b80
  X1[0] = 0;  // @33_4c9b80
  X1[1] = 0;  // @34_4c9b80
  X1[2] = 0;  // @35_4c9b80
  X1[3] = 0;  // @36_4c9b80
  __builtin_memcpy((void *)((u32)(7240064) + 0), &X1[0], 4);  // @37_4c9b80
  L4c9bec:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788420) + 0), 4); v; })));  // @39_4c9b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4c9b80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @41_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 124) + 0), &X1[0], 4);  // @42_4c9b80
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 72) + 0), 4); v; });  // @43_4c9b80
  X2[1] = 0;  // @44_4c9b80
  X2[2] = 0;  // @45_4c9b80
  X2[3] = 0;  // @46_4c9b80
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @47_4c9b80
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @48_4c9b80
  X1[1] = 0;  // @49_4c9b80
  X1[2] = 0;  // @50_4c9b80
  X1[3] = 0;  // @51_4c9b80
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; })));  // @52_4c9b80
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @53_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 128) + 0), &X0[0], 4);  // @54_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6903048) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6903048) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @55_4c9b80
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @56_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 120) + 0), &X2[0], 4);  // @57_4c9b80
  { double r_ = ext_634db2_dbl2(U2D(X0[0], X0[1]), U2D(X1[0], X1[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @58_4c9b80   hand fix: pow(xmm0, xmm1) SSE2 libm convention
    // @59_4c9b80
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 4), 4); v; })));  // @60_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @61_4c9b80
  ecx = esi;  // @62_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @63_4c9b80
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @64_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X0[0], 4);  // @65_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(81));  // @66_4c9b80
  ecx = edx = 0;  // @67_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @68_4c9b80
  if (FL[2] == 0) goto L4c9c85;  // @69_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7240064) + 0), 4); v; });  // @70_4c9b80
  X0[1] = 0;  // @71_4c9b80
  X0[2] = 0;  // @72_4c9b80
  X0[3] = 0;  // @73_4c9b80
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; }))))))) goto L4c9c85;  // @74_4c9b80
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @75_4c9b80
  __builtin_memcpy((void *)((u32)(7240064) + 0), &X0[0], 4);  // @76_4c9b80
  L4c9c85:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @80_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(87));  // @81_4c9b80
  ecx = edx = 0;  // @82_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @83_4c9b80
  if (FL[2] == 0) goto L4c9cbd;  // @84_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7240064) + 0), 4); v; });  // @85_4c9b80
  X0[1] = 0;  // @86_4c9b80
  X0[2] = 0;  // @87_4c9b80
  X0[3] = 0;  // @88_4c9b80
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; });  // @89_4c9b80
  X1[1] = 0;  // @90_4c9b80
  X1[2] = 0;  // @91_4c9b80
  X1[3] = 0;  // @92_4c9b80
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4c9cbd;  // @93_4c9b80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @94_4c9b80
  __builtin_memcpy((void *)((u32)(7240064) + 0), &X0[0], 4);  // @95_4c9b80
  L4c9cbd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @97_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @99_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(69));  // @100_4c9b80
  ecx = edx = 0;  // @101_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @102_4c9b80
  if (FL[2] == 0) goto L4c9cf1;  // @103_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7240060) + 0), 4); v; });  // @104_4c9b80
  X0[1] = 0;  // @105_4c9b80
  X0[2] = 0;  // @106_4c9b80
  X0[3] = 0;  // @107_4c9b80
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; }))))))) goto L4c9cf1;  // @108_4c9b80
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @109_4c9b80
  __builtin_memcpy((void *)((u32)(7240060) + 0), &X0[0], 4);  // @110_4c9b80
  L4c9cf1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @112_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @114_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(82));  // @115_4c9b80
  ecx = edx = 0;  // @116_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @117_4c9b80
  if (FL[2] == 0) goto L4c9d29;  // @118_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7240060) + 0), 4); v; });  // @119_4c9b80
  X0[1] = 0;  // @120_4c9b80
  X0[2] = 0;  // @121_4c9b80
  X0[3] = 0;  // @122_4c9b80
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; });  // @123_4c9b80
  X1[1] = 0;  // @124_4c9b80
  X1[2] = 0;  // @125_4c9b80
  X1[3] = 0;  // @126_4c9b80
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4c9d29;  // @127_4c9b80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @128_4c9b80
  __builtin_memcpy((void *)((u32)(7240060) + 0), &X0[0], 4);  // @129_4c9b80
  L4c9d29:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; });  // @131_4c9b80
  X0[1] = 0;  // @132_4c9b80
  X0[2] = 0;  // @133_4c9b80
  X0[3] = 0;  // @134_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_4c9b80
  X1[0] = X0[0];  // @136_4c9b80
  X1[1] = X0[1];  // @137_4c9b80
  X1[2] = X0[2];  // @138_4c9b80
  X1[3] = X0[3];  // @139_4c9b80
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })));  // @140_4c9b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @141_4c9b80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 128) + 0), 4); v; })));  // @142_4c9b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @143_4c9b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @144_4c9b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @145_4c9b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @146_4c9b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @147_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X1[0], 4);  // @149_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 120) + 0), &X0[0], 4);  // @150_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @151_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(18));  // @152_4c9b80
  ecx = edx = 0;  // @153_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @154_4c9b80
  if (FL[2] != 0) goto L4c9e51;  // @155_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @157_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @158_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(17));  // @159_4c9b80
  ecx = edx = 0;  // @160_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @161_4c9b80
  if (FL[2] != 0) goto L4c9e51;  // @162_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @163_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @165_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(16));  // @166_4c9b80
  ecx = edx = 0;  // @167_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @168_4c9b80
  if (FL[2] != 0) goto L4c9e51;  // @169_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @170_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @171_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @172_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(38));  // @173_4c9b80
  ecx = edx = 0;  // @174_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @175_4c9b80
  if (FL[2] == 0) goto L4c9de2;  // @176_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @177_4c9b80
  X0[1] = 0;  // @178_4c9b80
  X0[2] = 0;  // @179_4c9b80
  X0[3] = 0;  // @180_4c9b80
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @181_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @182_4c9b80
  L4c9de2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @184_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @185_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @186_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(40));  // @187_4c9b80
  ecx = edx = 0;  // @188_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @189_4c9b80
  if (FL[2] == 0) goto L4c9e07;  // @190_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @191_4c9b80
  X0[1] = 0;  // @192_4c9b80
  X0[2] = 0;  // @193_4c9b80
  X0[3] = 0;  // @194_4c9b80
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @195_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @196_4c9b80
  L4c9e07:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @198_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @199_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @200_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(37));  // @201_4c9b80
  ecx = edx = 0;  // @202_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @203_4c9b80
  if (FL[2] == 0) goto L4c9e2c;  // @204_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @205_4c9b80
  X0[1] = 0;  // @206_4c9b80
  X0[2] = 0;  // @207_4c9b80
  X0[3] = 0;  // @208_4c9b80
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @209_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @210_4c9b80
  L4c9e2c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @212_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @213_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @214_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(39));  // @215_4c9b80
  ecx = edx = 0;  // @216_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @217_4c9b80
  if (FL[2] == 0) goto L4c9e51;  // @218_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @219_4c9b80
  X0[1] = 0;  // @220_4c9b80
  X0[2] = 0;  // @221_4c9b80
  X0[3] = 0;  // @222_4c9b80
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @223_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @224_4c9b80
  L4c9e51:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @226_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @227_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @228_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(17));  // @229_4c9b80
  ecx = edx = 0;  // @230_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @231_4c9b80
  if (FL[2] == 0) goto L4c9f19;  // @232_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @233_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @234_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @235_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(16));  // @236_4c9b80
  ecx = edx = 0;  // @237_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @238_4c9b80
  if (FL[2] != 0) goto L4c9f19;  // @239_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @240_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @241_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @242_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(38));  // @243_4c9b80
  ecx = edx = 0;  // @244_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @245_4c9b80
  if (FL[2] == 0) goto L4c9eaa;  // @246_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @247_4c9b80
  X0[1] = 0;  // @248_4c9b80
  X0[2] = 0;  // @249_4c9b80
  X0[3] = 0;  // @250_4c9b80
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @251_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @252_4c9b80
  L4c9eaa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @254_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @255_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @256_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(40));  // @257_4c9b80
  ecx = edx = 0;  // @258_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @259_4c9b80
  if (FL[2] == 0) goto L4c9ecf;  // @260_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @261_4c9b80
  X0[1] = 0;  // @262_4c9b80
  X0[2] = 0;  // @263_4c9b80
  X0[3] = 0;  // @264_4c9b80
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @265_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @266_4c9b80
  L4c9ecf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @268_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @269_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @270_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(37));  // @271_4c9b80
  ecx = edx = 0;  // @272_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @273_4c9b80
  if (FL[2] == 0) goto L4c9ef4;  // @274_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @275_4c9b80
  X0[1] = 0;  // @276_4c9b80
  X0[2] = 0;  // @277_4c9b80
  X0[3] = 0;  // @278_4c9b80
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @279_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @280_4c9b80
  L4c9ef4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @282_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @283_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @284_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(39));  // @285_4c9b80
  ecx = edx = 0;  // @286_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @287_4c9b80
  if (FL[2] == 0) goto L4c9f19;  // @288_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @289_4c9b80
  X0[1] = 0;  // @290_4c9b80
  X0[2] = 0;  // @291_4c9b80
  X0[3] = 0;  // @292_4c9b80
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @293_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @294_4c9b80
  L4c9f19:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @296_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @297_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @298_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(17));  // @299_4c9b80
  ecx = edx = 0;  // @300_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @301_4c9b80
  if (FL[2] != 0) goto L4c9fe3;  // @302_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @303_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @304_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @305_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(16));  // @306_4c9b80
  ecx = edx = 0;  // @307_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @308_4c9b80
  if (FL[2] == 0) goto L4c9fe3;  // @309_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @310_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @311_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @312_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(38));  // @313_4c9b80
  ecx = edx = 0;  // @314_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @315_4c9b80
  if (FL[2] == 0) goto L4c9f72;  // @316_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @317_4c9b80
  X0[1] = 0;  // @318_4c9b80
  X0[2] = 0;  // @319_4c9b80
  X0[3] = 0;  // @320_4c9b80
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @321_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @322_4c9b80
  L4c9f72:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @324_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @325_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @326_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(40));  // @327_4c9b80
  ecx = edx = 0;  // @328_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @329_4c9b80
  if (FL[2] == 0) goto L4c9f97;  // @330_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @331_4c9b80
  X0[1] = 0;  // @332_4c9b80
  X0[2] = 0;  // @333_4c9b80
  X0[3] = 0;  // @334_4c9b80
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @335_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @336_4c9b80
  L4c9f97:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @338_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @339_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @340_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(37));  // @341_4c9b80
  ecx = edx = 0;  // @342_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @343_4c9b80
  if (FL[2] == 0) goto L4c9fbc;  // @344_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @345_4c9b80
  X0[1] = 0;  // @346_4c9b80
  X0[2] = 0;  // @347_4c9b80
  X0[3] = 0;  // @348_4c9b80
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @349_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @350_4c9b80
  L4c9fbc:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @352_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @353_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @354_4c9b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(39));  // @355_4c9b80
  ecx = edx = 0;  // @356_4c9b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @357_4c9b80
  if (FL[2] == 0) goto L4c9fe3;  // @358_4c9b80
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @359_4c9b80
  X2[1] = 0;  // @360_4c9b80
  X2[2] = 0;  // @361_4c9b80
  X2[3] = 0;  // @362_4c9b80
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @363_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X2[0], 4);  // @364_4c9b80
  goto L4c9fe8;  // @365_4c9b80
  L4c9fe3:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @367_4c9b80
  X2[1] = 0;  // @368_4c9b80
  X2[2] = 0;  // @369_4c9b80
  X2[3] = 0;  // @370_4c9b80
  L4c9fe8:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @372_4c9b80
  X0[1] = 0;  // @373_4c9b80
  X0[2] = 0;  // @374_4c9b80
  X0[3] = 0;  // @375_4c9b80
  X1[0] = 0;  // @376_4c9b80
  X1[1] = 0;  // @377_4c9b80
  X1[2] = 0;  // @378_4c9b80
  X1[3] = 0;  // @379_4c9b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @380_4c9b80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @381_4c9b80
  if (!__builtin_parity(FL[2] & 0xff)) goto L4ca03e;  // @382_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @383_4c9b80
  X0[1] = 0;  // @384_4c9b80
  X0[2] = 0;  // @385_4c9b80
  X0[3] = 0;  // @386_4c9b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @387_4c9b80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @388_4c9b80
  if (!__builtin_parity(FL[2] & 0xff)) goto L4ca03e;  // @389_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @390_4c9b80
  X0[1] = 0;  // @391_4c9b80
  X0[2] = 0;  // @392_4c9b80
  X0[3] = 0;  // @393_4c9b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @394_4c9b80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @395_4c9b80
  if (!__builtin_parity(FL[2] & 0xff)) goto L4ca03e;  // @396_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @397_4c9b80
  X0[1] = 0;  // @398_4c9b80
  X0[2] = 0;  // @399_4c9b80
  X0[3] = 0;  // @400_4c9b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @401_4c9b80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @402_4c9b80
  if (!__builtin_parity(FL[2] & 0xff)) goto L4ca03e;  // @403_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @404_4c9b80
  X0[1] = 0;  // @405_4c9b80
  X0[2] = 0;  // @406_4c9b80
  X0[3] = 0;  // @407_4c9b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @408_4c9b80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @409_4c9b80
  if (!__builtin_parity(FL[2] & 0xff)) goto L4ca03e;  // @410_4c9b80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @411_4c9b80
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @412_4c9b80
  if (__builtin_parity(FL[2] & 0xff)) goto L4ca149;  // @413_4c9b80
  L4ca03e:;
  PV[2] = (u32)(ecx);  // @415_4c9b80
  ecx = (u32)(EBP - 16);  // @416_4c9b80
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1082130432));  // @417_4c9b80
    // @418_4c9b80
  edx = (u32)(EBP - 100);  // @419_4c9b80
  ecx = (u32)(EBP - 16);  // @420_4c9b80
  eax = ext_4419f0_fastcall2(ecx, edx);  // @421_4c9b80
  ecx = edx = 0;  // @422_4c9b80
  edx = (u32)(EBP - 16);  // @423_4c9b80
  ecx = (u32)(EBP - 112);  // @424_4c9b80
  eax = ext_441940_fastcall2(ecx, edx);  // @425_4c9b80
  ecx = edx = 0;  // @426_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @427_4c9b80
  X0[1] = 0;  // @428_4c9b80
  X0[2] = 0;  // @429_4c9b80
  X0[3] = 0;  // @430_4c9b80
  edx = (u32)(EBP - 28);  // @431_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @432_4c9b80
  ecx = (u32)(EBP - 40);  // @433_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; });  // @434_4c9b80
  X0[1] = 0;  // @435_4c9b80
  X0[2] = 0;  // @436_4c9b80
  X0[3] = 0;  // @437_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @438_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 100) + 0), 4); v; });  // @439_4c9b80
  X0[1] = 0;  // @440_4c9b80
  X0[2] = 0;  // @441_4c9b80
  X0[3] = 0;  // @442_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @443_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @444_4c9b80
  X0[1] = 0;  // @445_4c9b80
  X0[2] = 0;  // @446_4c9b80
  X0[3] = 0;  // @447_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @448_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 84) + 0), 4); v; });  // @449_4c9b80
  X0[1] = 0;  // @450_4c9b80
  X0[2] = 0;  // @451_4c9b80
  X0[3] = 0;  // @452_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @453_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 96) + 0), 4); v; });  // @454_4c9b80
  X0[1] = 0;  // @455_4c9b80
  X0[2] = 0;  // @456_4c9b80
  X0[3] = 0;  // @457_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @458_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @459_4c9b80
  X0[1] = 0;  // @460_4c9b80
  X0[2] = 0;  // @461_4c9b80
  X0[3] = 0;  // @462_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @463_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @464_4c9b80
  X0[1] = 0;  // @465_4c9b80
  X0[2] = 0;  // @466_4c9b80
  X0[3] = 0;  // @467_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @468_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @469_4c9b80
  X0[1] = 0;  // @470_4c9b80
  X0[2] = 0;  // @471_4c9b80
  X0[3] = 0;  // @472_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @473_4c9b80
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @474_4c9b80
  ecx = edx = 0;  // @475_4c9b80
  edx = (u32)(EBP - 28);  // @476_4c9b80
  ecx = (u32)(EBP - 52);  // @477_4c9b80
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @478_4c9b80
  ecx = edx = 0;  // @479_4c9b80
  edx = (u32)(EBP - 28);  // @480_4c9b80
  ecx = (u32)(EBP - 64);  // @481_4c9b80
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @482_4c9b80
  ecx = edx = 0;  // @483_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @484_4c9b80
  X0[1] = 0;  // @485_4c9b80
  X0[2] = 0;  // @486_4c9b80
  X0[3] = 0;  // @487_4c9b80
  edx = (u32)(EBP - 112);  // @488_4c9b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @489_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @490_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @491_4c9b80
  X0[1] = 0;  // @492_4c9b80
  X0[2] = 0;  // @493_4c9b80
  X0[3] = 0;  // @494_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @495_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @496_4c9b80
  X0[1] = 0;  // @497_4c9b80
  X0[2] = 0;  // @498_4c9b80
  X0[3] = 0;  // @499_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @500_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @501_4c9b80
  X0[1] = 0;  // @502_4c9b80
  X0[2] = 0;  // @503_4c9b80
  X0[3] = 0;  // @504_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 88) + 0), &X0[0], 4);  // @505_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @506_4c9b80
  X0[1] = 0;  // @507_4c9b80
  X0[2] = 0;  // @508_4c9b80
  X0[3] = 0;  // @509_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X0[0], 4);  // @510_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @511_4c9b80
  X0[1] = 0;  // @512_4c9b80
  X0[2] = 0;  // @513_4c9b80
  X0[3] = 0;  // @514_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @515_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @516_4c9b80
  X0[1] = 0;  // @517_4c9b80
  X0[2] = 0;  // @518_4c9b80
  X0[3] = 0;  // @519_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 100) + 0), &X0[0], 4);  // @520_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @521_4c9b80
  X0[1] = 0;  // @522_4c9b80
  X0[2] = 0;  // @523_4c9b80
  X0[3] = 0;  // @524_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 96) + 0), &X0[0], 4);  // @525_4c9b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @526_4c9b80
  X0[1] = 0;  // @527_4c9b80
  X0[2] = 0;  // @528_4c9b80
  X0[3] = 0;  // @529_4c9b80
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X0[0], 4);  // @530_4c9b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @531_4c9b80
  PV[3] = (u32)(edx);  // @532_4c9b80
  edx = (u32)(EBP - 100);  // @533_4c9b80
  PV[4] = (u32)(edx);  // @534_4c9b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 116)))(ecx, PV[4], PV[3]);  // @535_4c9b80
  ecx = edx = 0;  // @536_4c9b80
  L4ca149:;
  ext_633654(G(u32, 0x6f5630));  // @538_4c9b80
  return eax;  // @539_4c9b80
}
PCREG(4c9b80, lifted_4c9b80);

extern "C" u32 THISCALL lifted_4c7ca0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c7ca0
  eax = (u32)(EBP - 112);  // @1_4c7ca0
  PV[0] = (u32)(eax);  // @2_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @3_4c7ca0
  eax = ext_4db500_thiscall2(ecx, PV[0]);  // @4_4c7ca0
  edx = 0;  // @5_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @6_4c7ca0
  eax = (u32)(EBP - 100);  // @7_4c7ca0
  PV[1] = (u32)(eax);  // @8_4c7ca0
  eax = ext_4db2a0_thiscall2(ecx, PV[1]);  // @9_4c7ca0
  ecx = edx = 0;  // @10_4c7ca0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; });  // @11_4c7ca0
  X2[1] = 0;  // @12_4c7ca0
  X2[2] = 0;  // @13_4c7ca0
  X2[3] = 0;  // @14_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7239492) + 0), 4); v; });  // @15_4c7ca0
  X0[1] = 0;  // @16_4c7ca0
  X0[2] = 0;  // @17_4c7ca0
  X0[3] = 0;  // @18_4c7ca0
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L4c7cee;  // @19_4c7ca0
  X0[0] = X2[0];  // @20_4c7ca0
  X0[1] = X2[1];  // @21_4c7ca0
  X0[2] = X2[2];  // @22_4c7ca0
  X0[3] = X2[3];  // @23_4c7ca0
  __builtin_memcpy((void *)((u32)(7239492) + 0), &X0[0], 4);  // @24_4c7ca0
  L4c7cee:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7239496) + 0), 4); v; });  // @26_4c7ca0
  X1[1] = 0;  // @27_4c7ca0
  X1[2] = 0;  // @28_4c7ca0
  X1[3] = 0;  // @29_4c7ca0
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4c7d06;  // @30_4c7ca0
  X1[0] = X2[0];  // @31_4c7ca0
  X1[1] = X2[1];  // @32_4c7ca0
  X1[2] = X2[2];  // @33_4c7ca0
  X1[3] = X2[3];  // @34_4c7ca0
  __builtin_memcpy((void *)((u32)(7239496) + 0), &X1[0], 4);  // @35_4c7ca0
  L4c7d06:;
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @37_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_4c7ca0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788420) + 0), 4); v; })));  // @39_4c7ca0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; })));  // @40_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @42_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X1[0], 4);  // @43_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @44_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(81));  // @45_4c7ca0
  ecx = edx = 0;  // @46_4c7ca0
  FL[0] = (eax & 0xff); FL[1] = (u32)(1);  // @47_4c7ca0
  if (FL[0] != FL[1]) goto L4c7d59;  // @48_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7239496) + 0), 4); v; });  // @49_4c7ca0
  X0[1] = 0;  // @50_4c7ca0
  X0[2] = 0;  // @51_4c7ca0
  X0[3] = 0;  // @52_4c7ca0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6901004) + 0), 4); v; })));  // @53_4c7ca0
  __builtin_memcpy((void *)((u32)(7239496) + 0), &X0[0], 4);  // @54_4c7ca0
  L4c7d59:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @58_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(87));  // @59_4c7ca0
  ecx = edx = 0;  // @60_4c7ca0
  FL[0] = (eax & 0xff); FL[1] = (u32)(1);  // @61_4c7ca0
  if (FL[0] != FL[1]) goto L4c7d87;  // @62_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7239496) + 0), 4); v; });  // @63_4c7ca0
  X0[1] = 0;  // @64_4c7ca0
  X0[2] = 0;  // @65_4c7ca0
  X0[3] = 0;  // @66_4c7ca0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6901004) + 0), 4); v; })));  // @67_4c7ca0
  __builtin_memcpy((void *)((u32)(7239496) + 0), &X0[0], 4);  // @68_4c7ca0
  L4c7d87:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @72_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(69));  // @73_4c7ca0
  ecx = edx = 0;  // @74_4c7ca0
  FL[0] = (eax & 0xff); FL[1] = (u32)(1);  // @75_4c7ca0
  if (FL[0] != FL[1]) goto L4c7db5;  // @76_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7239492) + 0), 4); v; });  // @77_4c7ca0
  X0[1] = 0;  // @78_4c7ca0
  X0[2] = 0;  // @79_4c7ca0
  X0[3] = 0;  // @80_4c7ca0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6901004) + 0), 4); v; })));  // @81_4c7ca0
  __builtin_memcpy((void *)((u32)(7239492) + 0), &X0[0], 4);  // @82_4c7ca0
  L4c7db5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 228), sizeof v); (u32)v; });  // @86_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(82));  // @87_4c7ca0
  ecx = edx = 0;  // @88_4c7ca0
  FL[0] = (eax & 0xff); FL[1] = (u32)(1);  // @89_4c7ca0
  if (FL[0] != FL[1]) goto L4c7de3;  // @90_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7239492) + 0), 4); v; });  // @91_4c7ca0
  X0[1] = 0;  // @92_4c7ca0
  X0[2] = 0;  // @93_4c7ca0
  X0[3] = 0;  // @94_4c7ca0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6901004) + 0), 4); v; })));  // @95_4c7ca0
  __builtin_memcpy((void *)((u32)(7239492) + 0), &X0[0], 4);  // @96_4c7ca0
  L4c7de3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @98_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 52) + 0), 4); v; });  // @99_4c7ca0
  X0[1] = 0;  // @100_4c7ca0
  X0[2] = 0;  // @101_4c7ca0
  X0[3] = 0;  // @102_4c7ca0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @103_4c7ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @104_4c7ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @105_4c7ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @106_4c7ca0
  X1[0] = X0[0];  // @107_4c7ca0
  X1[1] = X0[1];  // @108_4c7ca0
  X1[2] = X0[2];  // @109_4c7ca0
  X1[3] = X0[3];  // @110_4c7ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @111_4c7ca0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @112_4c7ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @113_4c7ca0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; })));  // @114_4c7ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @115_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 120) + 0), &X1[0], 4);  // @117_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X0[0], 4);  // @118_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @119_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(18));  // @120_4c7ca0
  ecx = edx = 0;  // @121_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @122_4c7ca0
  if (FL[2] != 0) goto L4c7f16;  // @123_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @126_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(17));  // @127_4c7ca0
  ecx = edx = 0;  // @128_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @129_4c7ca0
  if (FL[2] != 0) goto L4c7f16;  // @130_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @131_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @133_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(16));  // @134_4c7ca0
  ecx = edx = 0;  // @135_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @136_4c7ca0
  if (FL[2] != 0) goto L4c7f16;  // @137_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @138_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @140_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(38));  // @141_4c7ca0
  ecx = edx = 0;  // @142_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @143_4c7ca0
  if (FL[2] == 0) goto L4c7ea7;  // @144_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @145_4c7ca0
  X0[1] = 0;  // @146_4c7ca0
  X0[2] = 0;  // @147_4c7ca0
  X0[3] = 0;  // @148_4c7ca0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @149_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @150_4c7ca0
  L4c7ea7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @152_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @154_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(40));  // @155_4c7ca0
  ecx = edx = 0;  // @156_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @157_4c7ca0
  if (FL[2] == 0) goto L4c7ecc;  // @158_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @159_4c7ca0
  X0[1] = 0;  // @160_4c7ca0
  X0[2] = 0;  // @161_4c7ca0
  X0[3] = 0;  // @162_4c7ca0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @163_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @164_4c7ca0
  L4c7ecc:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @166_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @167_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @168_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(37));  // @169_4c7ca0
  ecx = edx = 0;  // @170_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @171_4c7ca0
  if (FL[2] == 0) goto L4c7ef1;  // @172_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @173_4c7ca0
  X0[1] = 0;  // @174_4c7ca0
  X0[2] = 0;  // @175_4c7ca0
  X0[3] = 0;  // @176_4c7ca0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @177_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @178_4c7ca0
  L4c7ef1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @180_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @181_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @182_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(39));  // @183_4c7ca0
  ecx = edx = 0;  // @184_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @185_4c7ca0
  if (FL[2] == 0) goto L4c7f16;  // @186_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @187_4c7ca0
  X0[1] = 0;  // @188_4c7ca0
  X0[2] = 0;  // @189_4c7ca0
  X0[3] = 0;  // @190_4c7ca0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @191_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @192_4c7ca0
  L4c7f16:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @195_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @196_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(17));  // @197_4c7ca0
  ecx = edx = 0;  // @198_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @199_4c7ca0
  if (FL[2] == 0) goto L4c7fde;  // @200_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @201_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @203_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(16));  // @204_4c7ca0
  ecx = edx = 0;  // @205_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @206_4c7ca0
  if (FL[2] != 0) goto L4c7fde;  // @207_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @208_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @210_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(38));  // @211_4c7ca0
  ecx = edx = 0;  // @212_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @213_4c7ca0
  if (FL[2] == 0) goto L4c7f6f;  // @214_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @215_4c7ca0
  X0[1] = 0;  // @216_4c7ca0
  X0[2] = 0;  // @217_4c7ca0
  X0[3] = 0;  // @218_4c7ca0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @219_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @220_4c7ca0
  L4c7f6f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @222_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @223_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @224_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(40));  // @225_4c7ca0
  ecx = edx = 0;  // @226_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @227_4c7ca0
  if (FL[2] == 0) goto L4c7f94;  // @228_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @229_4c7ca0
  X0[1] = 0;  // @230_4c7ca0
  X0[2] = 0;  // @231_4c7ca0
  X0[3] = 0;  // @232_4c7ca0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @233_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @234_4c7ca0
  L4c7f94:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @236_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @237_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @238_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(37));  // @239_4c7ca0
  ecx = edx = 0;  // @240_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @241_4c7ca0
  if (FL[2] == 0) goto L4c7fb9;  // @242_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @243_4c7ca0
  X0[1] = 0;  // @244_4c7ca0
  X0[2] = 0;  // @245_4c7ca0
  X0[3] = 0;  // @246_4c7ca0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @247_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @248_4c7ca0
  L4c7fb9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @250_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @251_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @252_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(39));  // @253_4c7ca0
  ecx = edx = 0;  // @254_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @255_4c7ca0
  if (FL[2] == 0) goto L4c7fde;  // @256_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @257_4c7ca0
  X0[1] = 0;  // @258_4c7ca0
  X0[2] = 0;  // @259_4c7ca0
  X0[3] = 0;  // @260_4c7ca0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; })));  // @261_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @262_4c7ca0
  L4c7fde:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @264_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @265_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @266_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(17));  // @267_4c7ca0
  ecx = edx = 0;  // @268_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @269_4c7ca0
  if (FL[2] != 0) goto L4c80a6;  // @270_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @271_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @272_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @273_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(16));  // @274_4c7ca0
  ecx = edx = 0;  // @275_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @276_4c7ca0
  if (FL[2] == 0) goto L4c80a6;  // @277_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @278_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @279_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @280_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(38));  // @281_4c7ca0
  ecx = edx = 0;  // @282_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @283_4c7ca0
  if (FL[2] == 0) goto L4c8037;  // @284_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @285_4c7ca0
  X0[1] = 0;  // @286_4c7ca0
  X0[2] = 0;  // @287_4c7ca0
  X0[3] = 0;  // @288_4c7ca0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @289_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @290_4c7ca0
  L4c8037:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @292_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @293_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @294_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(40));  // @295_4c7ca0
  ecx = edx = 0;  // @296_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @297_4c7ca0
  if (FL[2] == 0) goto L4c805c;  // @298_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @299_4c7ca0
  X0[1] = 0;  // @300_4c7ca0
  X0[2] = 0;  // @301_4c7ca0
  X0[3] = 0;  // @302_4c7ca0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @303_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @304_4c7ca0
  L4c805c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @306_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @307_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @308_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(37));  // @309_4c7ca0
  ecx = edx = 0;  // @310_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @311_4c7ca0
  if (FL[2] == 0) goto L4c8081;  // @312_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @313_4c7ca0
  X0[1] = 0;  // @314_4c7ca0
  X0[2] = 0;  // @315_4c7ca0
  X0[3] = 0;  // @316_4c7ca0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @317_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @318_4c7ca0
  L4c8081:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @320_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @321_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 212), sizeof v); (u32)v; });  // @322_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(39));  // @323_4c7ca0
  ecx = edx = 0;  // @324_4c7ca0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @325_4c7ca0
  if (FL[2] == 0) goto L4c80a6;  // @326_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @327_4c7ca0
  X0[1] = 0;  // @328_4c7ca0
  X0[2] = 0;  // @329_4c7ca0
  X0[3] = 0;  // @330_4c7ca0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; })));  // @331_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @332_4c7ca0
  L4c80a6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @334_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7493588), sizeof v); (u32)v; });  // @335_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2535) + 0), 4); v; });  // @336_4c7ca0
  X0[1] = 0;  // @337_4c7ca0
  X0[2] = 0;  // @338_4c7ca0
  X0[3] = 0;  // @339_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 136) + 0), &X0[0], 4);  // @340_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2539) + 0), 4); v; });  // @341_4c7ca0
  X0[1] = 0;  // @342_4c7ca0
  X0[2] = 0;  // @343_4c7ca0
  X0[3] = 0;  // @344_4c7ca0
  { u32 v; asm volatile("movl %%fs:0x2c, %0" : "=r"(v)); eax = v; }  // @345_4c7ca0   hand fix: fs:[0x2c] (TLS array pointer)
  __builtin_memcpy((void *)((u32)(EBP - 132) + 0), &X0[0], 4);  // @346_4c7ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @347_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340896), sizeof v); (u32)v; });  // @348_4c7ca0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @349_4c7ca0
  if ((s32)FL[0] > (s32)FL[1]) goto L4c82e2;  // @350_4c7ca0
  L4c80eb:;
  edx = (u32)(EBP - 136);  // @352_4c7ca0
  ecx = (u32)(EBP - 128);  // @353_4c7ca0
  eax = ext_4dffe0_fastcall3(ecx, edx, (u32)(7340888));  // @354_4c7ca0
    // @355_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @356_4c7ca0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340888), &v, sizeof v); }  // @357_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @358_4c7ca0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340892), &v, sizeof v); }  // @359_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @360_4c7ca0
  PV[2] = (u32)(ecx);  // @361_4c7ca0
  ecx = (u32)(EBP - 128);  // @362_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 0), 4); v; });  // @363_4c7ca0
  X0[1] = 0;  // @364_4c7ca0
  X0[2] = 0;  // @365_4c7ca0
  X0[3] = 0;  // @366_4c7ca0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; })));  // @367_4c7ca0
  PV[3] = X0[0];  // @368_4c7ca0
  eax = ext_4dffb0_thiscall2(ecx, PV[3]);  // @369_4c7ca0
    // @370_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @371_4c7ca0
  X0[1] = 0;  // @372_4c7ca0
  X0[2] = 0;  // @373_4c7ca0
  X0[3] = 0;  // @374_4c7ca0
  X1[0] = 0;  // @375_4c7ca0
  X1[1] = 0;  // @376_4c7ca0
  X1[2] = 0;  // @377_4c7ca0
  X1[3] = 0;  // @378_4c7ca0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @379_4c7ca0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @380_4c7ca0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c81ab;  // @381_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @382_4c7ca0
  X0[1] = 0;  // @383_4c7ca0
  X0[2] = 0;  // @384_4c7ca0
  X0[3] = 0;  // @385_4c7ca0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @386_4c7ca0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @387_4c7ca0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c81ab;  // @388_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @389_4c7ca0
  X0[1] = 0;  // @390_4c7ca0
  X0[2] = 0;  // @391_4c7ca0
  X0[3] = 0;  // @392_4c7ca0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @393_4c7ca0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @394_4c7ca0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c81ab;  // @395_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @396_4c7ca0
  X0[1] = 0;  // @397_4c7ca0
  X0[2] = 0;  // @398_4c7ca0
  X0[3] = 0;  // @399_4c7ca0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @400_4c7ca0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @401_4c7ca0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c81ab;  // @402_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @403_4c7ca0
  X0[1] = 0;  // @404_4c7ca0
  X0[2] = 0;  // @405_4c7ca0
  X0[3] = 0;  // @406_4c7ca0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @407_4c7ca0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @408_4c7ca0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c81ab;  // @409_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @410_4c7ca0
  X0[1] = 0;  // @411_4c7ca0
  X0[2] = 0;  // @412_4c7ca0
  X0[3] = 0;  // @413_4c7ca0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @414_4c7ca0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @415_4c7ca0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c81ab;  // @416_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 128) + 0), 4); v; });  // @417_4c7ca0
  X0[1] = 0;  // @418_4c7ca0
  X0[2] = 0;  // @419_4c7ca0
  X0[3] = 0;  // @420_4c7ca0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @421_4c7ca0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @422_4c7ca0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4c81ab;  // @423_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @424_4c7ca0
  X0[1] = 0;  // @425_4c7ca0
  X0[2] = 0;  // @426_4c7ca0
  X0[3] = 0;  // @427_4c7ca0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @428_4c7ca0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @429_4c7ca0
  if (__builtin_parity(FL[2] & 0xff)) goto L4c82c4;  // @430_4c7ca0
  L4c81ab:;
  PV[4] = (u32)(ecx);  // @432_4c7ca0
  ecx = (u32)(EBP - 28);  // @433_4c7ca0
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1082130432));  // @434_4c7ca0
    // @435_4c7ca0
  edx = (u32)(EBP - 100);  // @436_4c7ca0
  ecx = (u32)(EBP - 28);  // @437_4c7ca0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @438_4c7ca0
  ecx = edx = 0;  // @439_4c7ca0
  edx = (u32)(EBP - 28);  // @440_4c7ca0
  ecx = (u32)(EBP - 112);  // @441_4c7ca0
  eax = ext_441940_fastcall2(ecx, edx);  // @442_4c7ca0
  ecx = edx = 0;  // @443_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @444_4c7ca0
  X0[1] = 0;  // @445_4c7ca0
  X0[2] = 0;  // @446_4c7ca0
  X0[3] = 0;  // @447_4c7ca0
  edx = (u32)(EBP - 16);  // @448_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @449_4c7ca0
  ecx = (u32)(EBP - 40);  // @450_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; });  // @451_4c7ca0
  X0[1] = 0;  // @452_4c7ca0
  X0[2] = 0;  // @453_4c7ca0
  X0[3] = 0;  // @454_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @455_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 100) + 0), 4); v; });  // @456_4c7ca0
  X0[1] = 0;  // @457_4c7ca0
  X0[2] = 0;  // @458_4c7ca0
  X0[3] = 0;  // @459_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @460_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @461_4c7ca0
  X0[1] = 0;  // @462_4c7ca0
  X0[2] = 0;  // @463_4c7ca0
  X0[3] = 0;  // @464_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @465_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 84) + 0), 4); v; });  // @466_4c7ca0
  X0[1] = 0;  // @467_4c7ca0
  X0[2] = 0;  // @468_4c7ca0
  X0[3] = 0;  // @469_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @470_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 96) + 0), 4); v; });  // @471_4c7ca0
  X0[1] = 0;  // @472_4c7ca0
  X0[2] = 0;  // @473_4c7ca0
  X0[3] = 0;  // @474_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @475_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @476_4c7ca0
  X0[1] = 0;  // @477_4c7ca0
  X0[2] = 0;  // @478_4c7ca0
  X0[3] = 0;  // @479_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @480_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @481_4c7ca0
  X0[1] = 0;  // @482_4c7ca0
  X0[2] = 0;  // @483_4c7ca0
  X0[3] = 0;  // @484_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @485_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @486_4c7ca0
  X0[1] = 0;  // @487_4c7ca0
  X0[2] = 0;  // @488_4c7ca0
  X0[3] = 0;  // @489_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @490_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @491_4c7ca0
  X0[1] = 0;  // @492_4c7ca0
  X0[2] = 0;  // @493_4c7ca0
  X0[3] = 0;  // @494_4c7ca0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })));  // @495_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @496_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @497_4c7ca0
  X0[1] = 0;  // @498_4c7ca0
  X0[2] = 0;  // @499_4c7ca0
  X0[3] = 0;  // @500_4c7ca0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 128) + 0), 4); v; })));  // @501_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @502_4c7ca0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @503_4c7ca0
  ecx = edx = 0;  // @504_4c7ca0
  edx = (u32)(EBP - 16);  // @505_4c7ca0
  ecx = (u32)(EBP - 52);  // @506_4c7ca0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @507_4c7ca0
  ecx = edx = 0;  // @508_4c7ca0
  edx = (u32)(EBP - 16);  // @509_4c7ca0
  ecx = (u32)(EBP - 64);  // @510_4c7ca0
  eax = ext_4e0be0_fastcall2(ecx, edx);  // @511_4c7ca0
  ecx = edx = 0;  // @512_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @513_4c7ca0
  X0[1] = 0;  // @514_4c7ca0
  X0[2] = 0;  // @515_4c7ca0
  X0[3] = 0;  // @516_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @517_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @518_4c7ca0
  X0[1] = 0;  // @519_4c7ca0
  X0[2] = 0;  // @520_4c7ca0
  X0[3] = 0;  // @521_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @522_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @523_4c7ca0
  X0[1] = 0;  // @524_4c7ca0
  X0[2] = 0;  // @525_4c7ca0
  X0[3] = 0;  // @526_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @527_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @528_4c7ca0
  X0[1] = 0;  // @529_4c7ca0
  X0[2] = 0;  // @530_4c7ca0
  X0[3] = 0;  // @531_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 88) + 0), &X0[0], 4);  // @532_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @533_4c7ca0
  X0[1] = 0;  // @534_4c7ca0
  X0[2] = 0;  // @535_4c7ca0
  X0[3] = 0;  // @536_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X0[0], 4);  // @537_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @538_4c7ca0
  X0[1] = 0;  // @539_4c7ca0
  X0[2] = 0;  // @540_4c7ca0
  X0[3] = 0;  // @541_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @542_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @543_4c7ca0
  X0[1] = 0;  // @544_4c7ca0
  X0[2] = 0;  // @545_4c7ca0
  X0[3] = 0;  // @546_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 100) + 0), &X0[0], 4);  // @547_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @548_4c7ca0
  X0[1] = 0;  // @549_4c7ca0
  X0[2] = 0;  // @550_4c7ca0
  X0[3] = 0;  // @551_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 96) + 0), &X0[0], 4);  // @552_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @553_4c7ca0
  X0[1] = 0;  // @554_4c7ca0
  X0[2] = 0;  // @555_4c7ca0
  X0[3] = 0;  // @556_4c7ca0
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X0[0], 4);  // @557_4c7ca0
  L4c82c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @559_4c7ca0
  ecx = (u32)(EBP - 112);  // @560_4c7ca0
  PV[5] = (u32)(ecx);  // @561_4c7ca0
  ecx = (u32)(EBP - 100);  // @562_4c7ca0
  PV[6] = (u32)(ecx);  // @563_4c7ca0
  ecx = esi;  // @564_4c7ca0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 116)))(ecx, PV[6], PV[5]);  // @565_4c7ca0
  ecx = edx = 0;  // @566_4c7ca0
  ext_633654(G(u32, 0x6f5630));  // @567_4c7ca0
  return eax;  // @568_4c7ca0
  L4c82e2:;
  eax = ext_63456a_cdecl1((u32)(7340896));  // @570_4c7ca0
  ecx = edx = 0;  // @571_4c7ca0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340896), sizeof v); (u32)v; }); FL[1] = (u32)(-1);  // @572_4c7ca0
  if (FL[0] != FL[1]) goto L4c80eb;  // @573_4c7ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @574_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2535) + 0), 4); v; });  // @575_4c7ca0
  X0[1] = 0;  // @576_4c7ca0
  X0[2] = 0;  // @577_4c7ca0
  X0[3] = 0;  // @578_4c7ca0
  __builtin_memcpy((void *)((u32)(7340888) + 0), &X0[0], 4);  // @579_4c7ca0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2539) + 0), 4); v; });  // @580_4c7ca0
  X0[1] = 0;  // @581_4c7ca0
  X0[2] = 0;  // @582_4c7ca0
  X0[3] = 0;  // @583_4c7ca0
  __builtin_memcpy((void *)((u32)(7340892) + 0), &X0[0], 4);  // @584_4c7ca0
  eax = ext_63452b_cdecl1((u32)(7340896));  // @585_4c7ca0
  ecx = edx = 0;  // @586_4c7ca0
  goto L4c80eb;  // @587_4c7ca0
}
PCREG(4c7ca0, lifted_4c7ca0);

