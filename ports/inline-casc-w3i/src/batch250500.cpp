// batch250500.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_500360_thiscall2(u32, u32) __asm__("ext_500360");
extern "C" u32 THISCALL ext_50d7b0_thiscall2(u32, u32) __asm__("ext_50d7b0");
extern "C" u32 THISCALL ext_5f3440_thiscall4(u32, u32, u32, u32) __asm__("ext_5f3440");
extern "C" u32 THISCALL ext_5f3bf0_thiscall2(u32, u32) __asm__("ext_5f3bf0");
extern "C" u32 THISCALL ext_5f3c40_thiscall1(u32) __asm__("ext_5f3c40");
extern "C" u32 THISCALL ext_5f3d40_thiscall2(u32, u32) __asm__("ext_5f3d40");
extern "C" u32 THISCALL ext_5f3db0_thiscall2(u32, u32) __asm__("ext_5f3db0");
extern "C" u32 THISCALL ext_5f3fc0_thiscall2(u32, u32) __asm__("ext_5f3fc0");
extern "C" u32 THISCALL ext_5f40b0_thiscall2(u32, u32) __asm__("ext_5f40b0");
extern "C" u32 THISCALL ext_5f4110_thiscall2(u32, u32) __asm__("ext_5f4110");
extern "C" u32 THISCALL ext_5f4390_thiscall1(u32) __asm__("ext_5f4390");
extern "C" u32 THISCALL ext_5f4a00_thiscall2(u32, u32) __asm__("ext_5f4a00");
extern "C" u32 THISCALL ext_5f4a80_thiscall2(u32, u32) __asm__("ext_5f4a80");
extern "C" u32 THISCALL ext_5f4ac0_thiscall1(u32) __asm__("ext_5f4ac0");
extern "C" u32 THISCALL ext_5f4d80_thiscall2(u32, u32) __asm__("ext_5f4d80");
extern "C" u32 THISCALL ext_5f4dc0_thiscall2(u32, u32) __asm__("ext_5f4dc0");
extern "C" u32 THISCALL ext_5f4e00_thiscall2(u32, u32) __asm__("ext_5f4e00");
extern "C" u32 THISCALL ext_5f4e60_thiscall2(u32, u32) __asm__("ext_5f4e60");
extern "C" u32 THISCALL ext_5f4ec0_thiscall2(u32, u32) __asm__("ext_5f4ec0");
extern "C" u32 THISCALL ext_5f4f00_thiscall2(u32, u32) __asm__("ext_5f4f00");
extern "C" u32 THISCALL ext_5f4f70_thiscall1(u32) __asm__("ext_5f4f70");
extern "C" u32 THISCALL ext_5f4fb0_thiscall2(u32, u32) __asm__("ext_5f4fb0");
extern "C" u32 THISCALL ext_5f4ff0_thiscall1(u32) __asm__("ext_5f4ff0");
extern "C" u32 THISCALL ext_5f5020_thiscall1(u32) __asm__("ext_5f5020");
extern "C" u32 THISCALL ext_5f51e0_thiscall2(u32, u32) __asm__("ext_5f51e0");
extern "C" u32 THISCALL ext_5f5250_thiscall2(u32, u32) __asm__("ext_5f5250");
extern "C" u32 THISCALL ext_5f52f0_thiscall2(u32, u32) __asm__("ext_5f52f0");
extern "C" u32 THISCALL ext_5f5390_thiscall2(u32, u32) __asm__("ext_5f5390");
extern "C" u32 THISCALL ext_5f53f0_thiscall2(u32, u32) __asm__("ext_5f53f0");
extern "C" u32 THISCALL ext_5f5490_thiscall3(u32, u32, u32) __asm__("ext_5f5490");
extern "C" u32 THISCALL ext_5f5520_thiscall3(u32, u32, u32) __asm__("ext_5f5520");
extern "C" u32 THISCALL ext_5f5620_thiscall2(u32, u32) __asm__("ext_5f5620");
extern "C" u32 THISCALL ext_5f5680_thiscall2(u32, u32) __asm__("ext_5f5680");
extern "C" u32 THISCALL ext_5f9010_thiscall1(u32) __asm__("ext_5f9010");
extern "C" u32 THISCALL ext_5f90a0_thiscall1(u32) __asm__("ext_5f90a0");
extern "C" u32 THISCALL ext_5f9130_thiscall3(u32, u32, u32) __asm__("ext_5f9130");
extern "C" u32 THISCALL ext_5f9260_thiscall1(u32) __asm__("ext_5f9260");
extern "C" u32 THISCALL ext_5fbb00_thiscall3(u32, u32, u32) __asm__("ext_5fbb00");
extern "C" u32 THISCALL ext_5ffb00_thiscall2(u32, u32) __asm__("ext_5ffb00");
extern "C" u32 THISCALL ext_600800_thiscall1(u32) __asm__("ext_600800");
extern "C" u32 THISCALL ext_602cd0_thiscall2(u32, u32) __asm__("ext_602cd0");
extern "C" u32 ext_5fa630_cdecl0(void) __asm__("ext_5fa630");
extern "C" u32 ext_5fa630_cdecl1(...) __asm__("ext_5fa630");
extern "C" u32 ext_5fa630_cdecl4(...) __asm__("ext_5fa630");
extern "C" u32 ext_634670_cdecl0(void) __asm__("ext_634670");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5f56f0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  { u8 *d_ = (u8 *)(EBP - 0x11c); const u8 *s_ = (const u8 *)0x20201000; u32 n_ = 0x114 / 4; __asm__ volatile("rep movsl" : "+D"(d_), "+S"(s_), "+c"(n_) : : "memory"); }   // w3i: same per-case garbage as the exe frame (spec fills both)
  u32 PV[311], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5f56f0
  eax = (u32)(34816);  // @1_5f56f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @2_5f56f0
  esi = (u32)(65521);  // @3_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @4_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @5_5f56f0
  if (FL[2] != 0) goto L5f579a;  // @6_5f56f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xff);  // @7_5f56f0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(15))) & 0xff);  // @8_5f56f0
  FL[3] = (eax & 0xff);  // @9_5f56f0
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @10_5f56f0
  if (FL[0] == FL[1]) goto L5f8be6;  // @11_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @12_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 10) + 0), 4); v; });  // @13_5f56f0
  X0[1] = 0;  // @14_5f56f0
  X0[2] = 0;  // @15_5f56f0
  X0[3] = 0;  // @16_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @17_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @18_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @20_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @21_5f56f0
  ecx = edx = 0;  // @22_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @23_5f56f0
  X0[1] = 0;  // @24_5f56f0
  X0[2] = 0;  // @25_5f56f0
  X0[3] = 0;  // @26_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 128)) :: "st");  // @27_5f56f0
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 128) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 128) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 128) + 0), 4); v; }))))))) goto L5f8be6;  // @28_5f56f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xff);  // @29_5f56f0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(15))) & 0xff);  // @30_5f56f0
  FL[3] = (eax & 0xff);  // @31_5f56f0
  FL[0] = (eax & 0xff); FL[1] = (u32)(5);  // @32_5f56f0
  if (FL[0] != FL[1]) goto L5f5781;  // @33_5f56f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xffff);  // @34_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (esi & 0xffff))) & 0xffff);  // @35_5f56f0
  FL[3] = (eax & 0xffff);  // @36_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(1))) & 0xffff);  // @37_5f56f0
  FL[3] = (eax & 0xffff);  // @38_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @39_5f56f0
  L5f5781:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @41_5f56f0
  if (FL[0] == FL[1]) goto L5f578e;  // @42_5f56f0
  ecx = edi;  // @43_5f56f0
  eax = ext_5f4ac0_thiscall1(ecx);  // @44_5f56f0
  ecx = edx = 0;  // @45_5f56f0
  L5f578e:;
  eax = (u32)(8192);  // @47_5f56f0
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) | (eax & 0xffff))); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @48_5f56f0
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @49_5f56f0
  L5f579a:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @51_5f56f0
  edx = 0;  // @52_5f56f0
  FL[3] = edx;  // @53_5f56f0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (u32)(15));  // @54_5f56f0
  ecx = edx;  // @55_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @56_5f56f0
  if (FL[2] != 0) ecx = eax;  // @57_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @58_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @59_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @60_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 141), &v, sizeof v); }  // @61_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @62_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @63_5f56f0
  goto L5f57f3;  // @64_5f56f0
  L5f57d7:;
  PV[0] = (u32)(eax);  // @66_5f56f0
  ecx = (u32)(edi + 52);  // @67_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[0]);  // @68_5f56f0
  ecx = edx = 0;  // @69_5f56f0
  L5f57e0:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @71_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @72_5f56f0
  L5f57e7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @74_5f56f0
  L5f57f0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @76_5f56f0
  L5f57f3:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @78_5f56f0
  FL[2] = ((eax & 0xff) & (u32)(15));  // @79_5f56f0
  if (FL[2] == 0) goto L5f5824;  // @80_5f56f0
  FL[2] = (eax & (u32)(34816));  // @81_5f56f0
  eax = (eax & 0xffffff00u) | ((((FL[2] == 0) ? 1 : 0)) & 0xff);  // @82_5f56f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @83_5f56f0
  if (FL[2] == 0) goto L5f5824;  // @84_5f56f0
  FL[2] = (ecx & ecx);  // @85_5f56f0
  if ((s32)FL[2] <= 0) goto L5f5814;  // @86_5f56f0
  ecx = (ecx - 1);  // @87_5f56f0
  FL[3] = ecx;  // @88_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @89_5f56f0
  goto L5f581c;  // @90_5f56f0
  L5f5814:;
  FL[2] = (edx & edx);  // @92_5f56f0
  if ((s32)FL[2] <= 0) goto L5f8bb6;  // @93_5f56f0
  L5f581c:;
  FL[2] = (edx & edx);  // @95_5f56f0
  if (FL[2] == 0) goto L5f5824;  // @96_5f56f0
  edx = (edx - 1);  // @97_5f56f0
  FL[3] = edx;  // @98_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @99_5f56f0
  L5f5824:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @101_5f56f0
  ecx = edi;  // @102_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 14), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @103_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 14), sizeof v); (u32)v; });  // @104_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; });  // @105_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @106_5f56f0
  ecx = edx = 0;  // @107_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2758), &v, sizeof v); }  // @108_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @109_5f56f0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_5f56f0
  esi = (u32)(eax + 1);  // @111_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @112_5f56f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @113_5f56f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @114_5f56f0
  FL[0] = edx; FL[1] = (u32)(158);  // @115_5f56f0
  if (FL[0] > FL[1]) goto L5f8a77;  // @116_5f56f0
  switch (edx) {  // @117_5f56f0
  case 0: goto L5f57e7;  // @118_5f56f0
  case 1: goto L5f5891;  // @119_5f56f0
  case 2: goto L5f58b2;  // @120_5f56f0
  case 3: goto L5f58e9;  // @121_5f56f0
  case 4: goto L5f595a;  // @122_5f56f0
  case 5: goto L5f5981;  // @123_5f56f0
  case 6: goto L5f59a7;  // @124_5f56f0
  case 7: goto L5f59e9;  // @125_5f56f0
  case 8: goto L5f5a2f;  // @126_5f56f0
  case 9: goto L5f5a48;  // @127_5f56f0
  case 10: goto L5f5a67;  // @128_5f56f0
  case 11: goto L5f5a86;  // @129_5f56f0
  case 12: goto L5f5a98;  // @130_5f56f0
  case 13: goto L5f5acb;  // @131_5f56f0
  case 14: goto L5f5b51;  // @132_5f56f0
  case 15: goto L5f5b82;  // @133_5f56f0
  case 16: goto L5f5ba1;  // @134_5f56f0
  case 17: goto L5f5bd2;  // @135_5f56f0
  case 18: goto L5f5bf1;  // @136_5f56f0
  case 19: goto L5f5c22;  // @137_5f56f0
  case 20: goto L5f5c42;  // @138_5f56f0
  case 21: goto L5f5c9a;  // @139_5f56f0
  case 22: goto L5f5ce7;  // @140_5f56f0
  case 23: goto L5f5ebc;  // @141_5f56f0
  case 24: goto L5f5ce7;  // @142_5f56f0
  case 25: goto L5f5ebc;  // @143_5f56f0
  case 26: goto L5f5ce7;  // @144_5f56f0
  case 27: goto L5f5ebc;  // @145_5f56f0
  case 28: goto L5f5ce7;  // @146_5f56f0
  case 29: goto L5f5ebc;  // @147_5f56f0
  case 30: goto L5f6056;  // @148_5f56f0
  case 31: goto L5f6214;  // @149_5f56f0
  case 32: goto L5f6056;  // @150_5f56f0
  case 33: goto L5f6214;  // @151_5f56f0
  case 34: goto L5f6056;  // @152_5f56f0
  case 35: goto L5f6214;  // @153_5f56f0
  case 36: goto L5f6056;  // @154_5f56f0
  case 37: goto L5f6214;  // @155_5f56f0
  case 38: goto L5f640d;  // @156_5f56f0
  case 39: goto L5f6456;  // @157_5f56f0
  case 40: goto L5f649f;  // @158_5f56f0
  case 41: goto L5f6519;  // @159_5f56f0
  case 42: goto L5f6592;  // @160_5f56f0
  case 43: goto L5f5861;  // @161_5f56f0
  case 44: goto L5f65b9;  // @162_5f56f0
  case 45: goto L5f65ff;  // @163_5f56f0
  case 46: goto L5f6645;  // @164_5f56f0
  case 47: goto L5f66be;  // @165_5f56f0
  case 48: goto L5f66fd;  // @166_5f56f0
  case 49: goto L5f673a;  // @167_5f56f0
  case 50: goto L5f677b;  // @168_5f56f0
  case 51: goto L5f67d6;  // @169_5f56f0
  case 52: goto L5f6808;  // @170_5f56f0
  case 53: goto L5f683a;  // @171_5f56f0
  case 54: goto L5f6897;  // @172_5f56f0
  case 55: goto L5f6903;  // @173_5f56f0
  case 56: goto L5f696c;  // @174_5f56f0
  case 57: goto L5f69db;  // @175_5f56f0
  case 58: goto L5f6a23;  // @176_5f56f0
  case 59: goto L5f6a8f;  // @177_5f56f0
  case 60: goto L5f6afc;  // @178_5f56f0
  case 61: goto L5f6b87;  // @179_5f56f0
  case 62: goto L5f6bf0;  // @180_5f56f0
  case 63: goto L5f6c5a;  // @181_5f56f0
  case 64: goto L5f6cc0;  // @182_5f56f0
  case 65: goto L5f6df0;  // @183_5f56f0
  case 66: goto L5f6cc0;  // @184_5f56f0
  case 67: goto L5f6df0;  // @185_5f56f0
  case 68: goto L5f6cc0;  // @186_5f56f0
  case 69: goto L5f6df0;  // @187_5f56f0
  case 70: goto L5f6cc0;  // @188_5f56f0
  case 71: goto L5f6df0;  // @189_5f56f0
  case 72: goto L5f6f3e;  // @190_5f56f0
  case 73: goto L5f6fbf;  // @191_5f56f0
  case 74: goto L5f7017;  // @192_5f56f0
  case 75: goto L5f587e;  // @193_5f56f0
  case 76: goto L5f7045;  // @194_5f56f0
  case 77: goto L5f7a5c;  // @195_5f56f0
  case 78: goto L5f7068;  // @196_5f56f0
  case 79: goto L5f70b7;  // @197_5f56f0
  case 80: goto L5f70d6;  // @198_5f56f0
  case 81: goto L5f70f8;  // @199_5f56f0
  case 82: goto L5f7127;  // @200_5f56f0
  case 83: goto L5f7136;  // @201_5f56f0
  case 84: goto L5f7173;  // @202_5f56f0
  case 85: goto L5f719c;  // @203_5f56f0
  case 86: goto L5f71c5;  // @204_5f56f0
  case 87: goto L5f71ee;  // @205_5f56f0
  case 88: goto L5f7217;  // @206_5f56f0
  case 89: goto L5f7240;  // @207_5f56f0
  case 90: goto L5f7269;  // @208_5f56f0
  case 91: goto L5f729b;  // @209_5f56f0
  case 92: goto L5f72cd;  // @210_5f56f0
  case 93: goto L5f72ff;  // @211_5f56f0
  case 94: goto L5f7331;  // @212_5f56f0
  case 95: goto L5f7367;  // @213_5f56f0
  case 96: goto L5f738c;  // @214_5f56f0
  case 97: goto L5f73f1;  // @215_5f56f0
  case 98: goto L5f7435;  // @216_5f56f0
  case 99: goto L5f7488;  // @217_5f56f0
  case 100: goto L5f74cb;  // @218_5f56f0
  case 101: goto L5f7522;  // @219_5f56f0
  case 102: goto L5f7559;  // @220_5f56f0
  case 103: goto L5f75d9;  // @221_5f56f0
  case 104: goto L5f760f;  // @222_5f56f0
  case 105: goto L5f7631;  // @223_5f56f0
  case 106: goto L5f7645;  // @224_5f56f0
  case 107: goto L5f76b3;  // @225_5f56f0
  case 108: goto L5f7739;  // @226_5f56f0
  case 109: goto L5f77b9;  // @227_5f56f0
  case 110: goto L5f7887;  // @228_5f56f0
  case 111: goto L5f7952;  // @229_5f56f0
  case 112: goto L5f7982;  // @230_5f56f0
  case 113: goto L5f79f7;  // @231_5f56f0
  case 114: goto L5f7a0b;  // @232_5f56f0
  case 115: goto L5f7a2e;  // @233_5f56f0
  case 116: goto L5f7a47;  // @234_5f56f0
  case 117: goto L5f7a63;  // @235_5f56f0
  case 118: goto L5f7a8c;  // @236_5f56f0
  case 119: goto L5f7a9d;  // @237_5f56f0
  case 120: goto L5f7b02;  // @238_5f56f0
  case 121: goto L5f7b36;  // @239_5f56f0
  case 122: goto L5f8b93;  // @240_5f56f0
  case 123: goto L5f8bb6;  // @241_5f56f0
  case 124: goto L5f7b80;  // @242_5f56f0
  case 125: goto L5f7b9d;  // @243_5f56f0
  case 126: goto L5f7c60;  // @244_5f56f0
  case 127: goto L5f804d;  // @245_5f56f0
  case 128: goto L5f80ed;  // @246_5f56f0
  case 129: goto L5f667b;  // @247_5f56f0
  case 130: goto L5f7f7b;  // @248_5f56f0
  case 131: goto L5f8a77;  // @249_5f56f0
  case 132: goto L5f8a77;  // @250_5f56f0
  case 133: goto L5f8191;  // @251_5f56f0
  case 134: goto L5f84fc;  // @252_5f56f0
  case 135: goto L5f66be;  // @253_5f56f0
  case 136: goto L5f8570;  // @254_5f56f0
  case 137: goto L5f8570;  // @255_5f56f0
  case 138: goto L5f8570;  // @256_5f56f0
  case 139: goto L5f8570;  // @257_5f56f0
  case 140: goto L5f86d9;  // @258_5f56f0
  case 141: goto L5f86d9;  // @259_5f56f0
  case 142: goto L5f86d9;  // @260_5f56f0
  case 143: goto L5f86d9;  // @261_5f56f0
  case 144: goto L5f889b;  // @262_5f56f0
  case 145: goto L5f892a;  // @263_5f56f0
  case 146: goto L5f893c;  // @264_5f56f0
  case 147: goto L5f8971;  // @265_5f56f0
  case 148: goto L5f5861;  // @266_5f56f0
  case 149: goto L5f7c6b;  // @267_5f56f0
  case 150: goto L5f7e2f;  // @268_5f56f0
  case 151: goto L5f801f;  // @269_5f56f0
  case 152: goto L5f8987;  // @270_5f56f0
  case 153: goto L5f89d2;  // @271_5f56f0
  case 154: goto L5f89e4;  // @272_5f56f0
  case 155: goto L5f89f6;  // @273_5f56f0
  case 156: goto L5f8a4e;  // @274_5f56f0
  case 157: goto L5f57e7;  // @275_5f56f0
  case 158: goto L5f8bb6;  // @276_5f56f0
  default: __builtin_trap(); }  // @277_5f56f0
  L5f5861:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @279_5f56f0
  ecx = (u32)(edi + 52);  // @280_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @281_5f56f0
  eax = (u32)(EBP - 108);  // @282_5f56f0
  PV[1] = (u32)(eax);  // @283_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[1]);  // @284_5f56f0
  ecx = edx = 0;  // @285_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @286_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @287_5f56f0
  goto L5f57e7;  // @288_5f56f0
  L5f587e:;
  ecx = (u32)(edi + 64);  // @290_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @291_5f56f0
  edx = 0;  // @292_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @293_5f56f0
  goto L5f57e7;  // @294_5f56f0
  L5f5891:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @296_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @297_5f56f0
  if ((s32)FL[2] >= 0) goto L5f58a2;  // @298_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @299_5f56f0
  goto L5f58c1;  // @300_5f56f0
  L5f58a2:;
  ecx = eax;  // @302_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @303_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + ecx), &v, sizeof v); }  // @304_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; });  // @305_5f56f0
  goto L5f57e0;  // @306_5f56f0
  L5f58b2:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @308_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @309_5f56f0
  if ((s32)FL[2] >= 0) goto L5f58d9;  // @310_5f56f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @311_5f56f0
  L5f58c1:;
  ecx = (u32)(EBP - 108);  // @313_5f56f0
  PV[2] = (u32)(ecx);  // @314_5f56f0
  PV[3] = (u32)(eax);  // @315_5f56f0
  ecx = edi;  // @316_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[3]);  // @317_5f56f0
  ecx = edx = 0;  // @318_5f56f0
  ecx = eax;  // @319_5f56f0
  eax = ext_5f3d40_thiscall2(ecx, PV[2]);  // @320_5f56f0
  ecx = edx = 0;  // @321_5f56f0
  goto L5f57e0;  // @322_5f56f0
  L5f58d9:;
  ecx = eax;  // @324_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @325_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + ecx), &v, sizeof v); }  // @326_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; });  // @327_5f56f0
  goto L5f57e0;  // @328_5f56f0
  L5f58e9:;
  eax = (u32)(EBP - 124);  // @330_5f56f0
  PV[4] = (u32)(eax);  // @331_5f56f0
  ecx = (u32)(edi + 52);  // @332_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[4]);  // @333_5f56f0
  ecx = edx = 0;  // @334_5f56f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @335_5f56f0
  eax = (eax - (u32)(1));  // @336_5f56f0
  FL[3] = eax;  // @337_5f56f0
  if (FL[3] == 0) goto L5f594d;  // @338_5f56f0
  eax = (eax - (u32)(1));  // @339_5f56f0
  FL[3] = eax;  // @340_5f56f0
  if (FL[3] == 0) goto L5f5919;  // @341_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @342_5f56f0
  FL[2] = (eax & eax);  // @343_5f56f0
  if (FL[2] == 0) goto L5f5913;  // @344_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @345_5f56f0
  ecx = edx = 0;  // @346_5f56f0
  goto L5f57e7;  // @347_5f56f0
  L5f5913:;
  __builtin_trap();  // @349_5f56f0
  L5f5919:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @351_5f56f0
  X0[1] = 0;  // @352_5f56f0
  X0[2] = 0;  // @353_5f56f0
  X0[3] = 0;  // @354_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @355_5f56f0
  edx = 0;  // @356_5f56f0
  FL[3] = edx;  // @357_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @358_5f56f0
  eax = (u32)(1);  // @359_5f56f0
  if (__builtin_parity(FL[2] & 0xff)) edx = eax;  // @360_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @361_5f56f0
  L5f5936:;
  eax = (u32)(EBP - 108);  // @363_5f56f0
  PV[5] = (u32)(eax);  // @364_5f56f0
  ecx = (u32)(edi + 52);  // @365_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[5]);  // @366_5f56f0
  ecx = edx = 0;  // @367_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @368_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @369_5f56f0
  goto L5f57f3;  // @370_5f56f0
  L5f594d:;
  eax = 0;  // @372_5f56f0
  FL[3] = eax;  // @373_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = eax;  // @374_5f56f0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @375_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @376_5f56f0
  goto L5f5936;  // @377_5f56f0
  L5f595a:;
  eax = (u32)(EBP - 124);  // @379_5f56f0
  PV[6] = (u32)(eax);  // @380_5f56f0
  ecx = (u32)(edi + 52);  // @381_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[6]);  // @382_5f56f0
  ecx = edx = 0;  // @383_5f56f0
  ecx = (u32)(edi + 52);  // @384_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @385_5f56f0
  edx = 0;  // @386_5f56f0
  FL[2] = (eax & eax);  // @387_5f56f0
  if (FL[2] == 0) goto L5f599e;  // @388_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @389_5f56f0
  if (FL[0] == FL[1]) goto L5f599e;  // @390_5f56f0
  L5f5978:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @392_5f56f0
  goto L5f5936;  // @393_5f56f0
  L5f5981:;
  eax = (u32)(EBP - 124);  // @395_5f56f0
  PV[7] = (u32)(eax);  // @396_5f56f0
  ecx = (u32)(edi + 52);  // @397_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[7]);  // @398_5f56f0
  ecx = edx = 0;  // @399_5f56f0
  ecx = (u32)(edi + 52);  // @400_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @401_5f56f0
  edx = 0;  // @402_5f56f0
  FL[2] = (eax & eax);  // @403_5f56f0
  if (FL[2] != 0) goto L5f5978;  // @404_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = eax;  // @405_5f56f0
  if (FL[0] != FL[1]) goto L5f5978;  // @406_5f56f0
  L5f599e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @408_5f56f0
  goto L5f5936;  // @409_5f56f0
  L5f59a7:;
  eax = (u32)(EBP - 124);  // @411_5f56f0
  PV[8] = (u32)(eax);  // @412_5f56f0
  ecx = (u32)(edi + 52);  // @413_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[8]);  // @414_5f56f0
  ecx = edx = 0;  // @415_5f56f0
  ecx = (u32)(edi + 52);  // @416_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @417_5f56f0
  edx = 0;  // @418_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @419_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @420_5f56f0
  X0[1] = 0;  // @421_5f56f0
  X0[2] = 0;  // @422_5f56f0
  X0[3] = 0;  // @423_5f56f0
  X1[0] = 0;  // @424_5f56f0
  X1[1] = 0;  // @425_5f56f0
  X1[2] = 0;  // @426_5f56f0
  X1[3] = 0;  // @427_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @428_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @429_5f56f0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5f5978;  // @430_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @431_5f56f0
  X0[1] = 0;  // @432_5f56f0
  X0[2] = 0;  // @433_5f56f0
  X0[3] = 0;  // @434_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @435_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @436_5f56f0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5f5978;  // @437_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @438_5f56f0
  goto L5f5936;  // @439_5f56f0
  L5f59e9:;
  eax = (u32)(EBP - 124);  // @441_5f56f0
  PV[9] = (u32)(eax);  // @442_5f56f0
  ecx = (u32)(edi + 52);  // @443_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[9]);  // @444_5f56f0
  ecx = edx = 0;  // @445_5f56f0
  ecx = (u32)(edi + 52);  // @446_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @447_5f56f0
  edx = 0;  // @448_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @449_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @450_5f56f0
  X0[1] = 0;  // @451_5f56f0
  X0[2] = 0;  // @452_5f56f0
  X0[3] = 0;  // @453_5f56f0
  X1[0] = 0;  // @454_5f56f0
  X1[1] = 0;  // @455_5f56f0
  X1[2] = 0;  // @456_5f56f0
  X1[3] = 0;  // @457_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @458_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @459_5f56f0
  if (__builtin_parity(FL[2] & 0xff)) goto L5f599e;  // @460_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @461_5f56f0
  X0[1] = 0;  // @462_5f56f0
  X0[2] = 0;  // @463_5f56f0
  X0[3] = 0;  // @464_5f56f0
  L5f5a19:;
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @466_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @467_5f56f0
  if (__builtin_parity(FL[2] & 0xff)) goto L5f599e;  // @468_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @469_5f56f0
  goto L5f5936;  // @470_5f56f0
  L5f5a2f:;
  eax = (u32)(EBP - 124);  // @472_5f56f0
  PV[10] = (u32)(eax);  // @473_5f56f0
  ecx = (u32)(edi + 52);  // @474_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[10]);  // @475_5f56f0
  ecx = edx = 0;  // @476_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @477_5f56f0
  eax = (~eax);  // @478_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @479_5f56f0
  goto L5f5936;  // @480_5f56f0
  L5f5a48:;
  eax = (u32)(EBP - 124);  // @482_5f56f0
  PV[11] = (u32)(eax);  // @483_5f56f0
  ecx = (u32)(edi + 52);  // @484_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[11]);  // @485_5f56f0
  ecx = edx = 0;  // @486_5f56f0
  ecx = (u32)(edi + 52);  // @487_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @488_5f56f0
  edx = 0;  // @489_5f56f0
  eax = (eax & ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }));  // @490_5f56f0
  FL[3] = eax;  // @491_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @492_5f56f0
  goto L5f5936;  // @493_5f56f0
  L5f5a67:;
  eax = (u32)(EBP - 124);  // @495_5f56f0
  PV[12] = (u32)(eax);  // @496_5f56f0
  ecx = (u32)(edi + 52);  // @497_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[12]);  // @498_5f56f0
  ecx = edx = 0;  // @499_5f56f0
  ecx = (u32)(edi + 52);  // @500_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @501_5f56f0
  edx = 0;  // @502_5f56f0
  eax = (eax | ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }));  // @503_5f56f0
  FL[3] = eax;  // @504_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @505_5f56f0
  goto L5f5936;  // @506_5f56f0
  L5f5a86:;
  ecx = (u32)(edi + 52);  // @508_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @509_5f56f0
  edx = 0;  // @510_5f56f0
  FL[1] = eax;  // @511_5f56f0
  eax = (0u - eax);  // @512_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @513_5f56f0
  goto L5f5936;  // @514_5f56f0
  L5f5a98:;
  ecx = (u32)(edi + 52);  // @516_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @517_5f56f0
  edx = 0;  // @518_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @519_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @520_5f56f0
  X0[1] = 0;  // @521_5f56f0
  X0[2] = 0;  // @522_5f56f0
  X0[3] = 0;  // @523_5f56f0
  eax = (u32)(EBP - 108);  // @524_5f56f0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @525_5f56f0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @526_5f56f0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @527_5f56f0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @528_5f56f0
  ecx = (u32)(edi + 52);  // @529_5f56f0
  PV[13] = (u32)(eax);  // @530_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @531_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[13]);  // @532_5f56f0
  ecx = edx = 0;  // @533_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @534_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @535_5f56f0
  goto L5f57f3;  // @536_5f56f0
  L5f5acb:;
  eax = (u32)(EBP - 124);  // @538_5f56f0
  PV[14] = (u32)(eax);  // @539_5f56f0
  ecx = (u32)(edi + 52);  // @540_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[14]);  // @541_5f56f0
  ecx = edx = 0;  // @542_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @543_5f56f0
  X1[1] = 0;  // @544_5f56f0
  X1[2] = 0;  // @545_5f56f0
  X1[3] = 0;  // @546_5f56f0
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))))) goto L5f5afd;  // @547_5f56f0
  eax = (u32)(EBP - 108);  // @548_5f56f0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @549_5f56f0
  PV[15] = (u32)(eax);  // @550_5f56f0
  ecx = (u32)(EBP - 124);  // @551_5f56f0
  eax = ext_602cd0_thiscall2(ecx, PV[15]);  // @552_5f56f0
  ecx = edx = 0;  // @553_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @554_5f56f0
  X1[1] = 0;  // @555_5f56f0
  X1[2] = 0;  // @556_5f56f0
  X1[3] = 0;  // @557_5f56f0
  L5f5afd:;
  X0[0] = 0;  // @559_5f56f0
  X0[1] = 0;  // @560_5f56f0
  X0[2] = 0;  // @561_5f56f0
  X0[3] = 0;  // @562_5f56f0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5f5b1d;  // @563_5f56f0
  eax = (u32)(EBP - 108);  // @564_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @565_5f56f0
  PV[16] = (u32)(eax);  // @566_5f56f0
  ecx = (u32)(EBP - 124);  // @567_5f56f0
  eax = ext_602cd0_thiscall2(ecx, PV[16]);  // @568_5f56f0
  ecx = edx = 0;  // @569_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @570_5f56f0
  X1[1] = 0;  // @571_5f56f0
  X1[2] = 0;  // @572_5f56f0
  X1[3] = 0;  // @573_5f56f0
  L5f5b1d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @575_5f56f0
  X0[1] = 0;  // @576_5f56f0
  X0[2] = 0;  // @577_5f56f0
  X0[3] = 0;  // @578_5f56f0
  eax = (u32)(EBP - 108);  // @579_5f56f0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @580_5f56f0
  PV[17] = (u32)(eax);  // @581_5f56f0
  ecx = (u32)(EBP - 124);  // @582_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @583_5f56f0
  eax = ext_602cd0_thiscall2(ecx, PV[17]);  // @584_5f56f0
  ecx = edx = 0;  // @585_5f56f0
  eax = (u32)(EBP - 124);  // @586_5f56f0
  PV[18] = (u32)(eax);  // @587_5f56f0
  ecx = (u32)(edi + 52);  // @588_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[18]);  // @589_5f56f0
  ecx = edx = 0;  // @590_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @591_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @592_5f56f0
  goto L5f57f3;  // @593_5f56f0
  L5f5b51:;
  eax = (u32)(EBP - 124);  // @595_5f56f0
  PV[19] = (u32)(eax);  // @596_5f56f0
  ecx = (u32)(edi + 52);  // @597_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[19]);  // @598_5f56f0
  ecx = edx = 0;  // @599_5f56f0
  ecx = (u32)(edi + 52);  // @600_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @601_5f56f0
  edx = 0;  // @602_5f56f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(EBP - 124)) : "st");  // @603_5f56f0
  eax = (u32)(EBP - 108);  // @604_5f56f0
  PV[20] = (u32)(eax);  // @605_5f56f0
  ecx = (u32)(edi + 52);  // @606_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @607_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[20]);  // @608_5f56f0
  ecx = edx = 0;  // @609_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @610_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @611_5f56f0
  goto L5f57f3;  // @612_5f56f0
  L5f5b82:;
  eax = (u32)(EBP - 124);  // @614_5f56f0
  PV[21] = (u32)(eax);  // @615_5f56f0
  ecx = (u32)(edi + 52);  // @616_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[21]);  // @617_5f56f0
  ecx = edx = 0;  // @618_5f56f0
  ecx = (u32)(edi + 52);  // @619_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @620_5f56f0
  edx = 0;  // @621_5f56f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }));  // @622_5f56f0
  FL[3] = eax;  // @623_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @624_5f56f0
  goto L5f5936;  // @625_5f56f0
  L5f5ba1:;
  eax = (u32)(EBP - 124);  // @627_5f56f0
  PV[22] = (u32)(eax);  // @628_5f56f0
  ecx = (u32)(edi + 52);  // @629_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[22]);  // @630_5f56f0
  ecx = edx = 0;  // @631_5f56f0
  ecx = (u32)(edi + 52);  // @632_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @633_5f56f0
  edx = 0;  // @634_5f56f0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(EBP - 124)) : "st");  // @635_5f56f0
  eax = (u32)(EBP - 108);  // @636_5f56f0
  PV[23] = (u32)(eax);  // @637_5f56f0
  ecx = (u32)(edi + 52);  // @638_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @639_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[23]);  // @640_5f56f0
  ecx = edx = 0;  // @641_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @642_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @643_5f56f0
  goto L5f57f3;  // @644_5f56f0
  L5f5bd2:;
  eax = (u32)(EBP - 124);  // @646_5f56f0
  PV[24] = (u32)(eax);  // @647_5f56f0
  ecx = (u32)(edi + 52);  // @648_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[24]);  // @649_5f56f0
  ecx = edx = 0;  // @650_5f56f0
  ecx = (u32)(edi + 52);  // @651_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @652_5f56f0
  edx = 0;  // @653_5f56f0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }));  // @654_5f56f0
  FL[3] = eax;  // @655_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @656_5f56f0
  goto L5f5936;  // @657_5f56f0
  L5f5bf1:;
  eax = (u32)(EBP - 124);  // @659_5f56f0
  PV[25] = (u32)(eax);  // @660_5f56f0
  ecx = (u32)(edi + 52);  // @661_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[25]);  // @662_5f56f0
  ecx = edx = 0;  // @663_5f56f0
  ecx = (u32)(edi + 52);  // @664_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @665_5f56f0
  edx = 0;  // @666_5f56f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(EBP - 124)) : "st");  // @667_5f56f0
  eax = (u32)(EBP - 108);  // @668_5f56f0
  PV[26] = (u32)(eax);  // @669_5f56f0
  ecx = (u32)(edi + 52);  // @670_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @671_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[26]);  // @672_5f56f0
  ecx = edx = 0;  // @673_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @674_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @675_5f56f0
  goto L5f57f3;  // @676_5f56f0
  L5f5c22:;
  eax = (u32)(EBP - 124);  // @678_5f56f0
  PV[27] = (u32)(eax);  // @679_5f56f0
  ecx = (u32)(edi + 52);  // @680_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[27]);  // @681_5f56f0
  ecx = edx = 0;  // @682_5f56f0
  ecx = (u32)(edi + 52);  // @683_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @684_5f56f0
  edx = 0;  // @685_5f56f0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }));  // @686_5f56f0
  FL[3] = eax;  // @687_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @688_5f56f0
  goto L5f5936;  // @689_5f56f0
  L5f5c42:;
  eax = (u32)(EBP - 124);  // @691_5f56f0
  PV[28] = (u32)(eax);  // @692_5f56f0
  ecx = (u32)(edi + 52);  // @693_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[28]);  // @694_5f56f0
  ecx = edx = 0;  // @695_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @696_5f56f0
  X0[1] = 0;  // @697_5f56f0
  X0[2] = 0;  // @698_5f56f0
  X0[3] = 0;  // @699_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @700_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @701_5f56f0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5f5c75;  // @702_5f56f0
  ecx = edi;  // @703_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @704_5f56f0
  ecx = edx = 0;  // @705_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @706_5f56f0
  FL[2] = (eax & eax);  // @707_5f56f0
  if (FL[2] == 0) goto L5f5c74;  // @708_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @709_5f56f0
  ecx = edx = 0;  // @710_5f56f0
  goto L5f5c75;  // @711_5f56f0
  L5f5c74:;
  __builtin_trap();  // @713_5f56f0
  L5f5c75:;
  ecx = (u32)(edi + 52);  // @715_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @716_5f56f0
  edx = 0;  // @717_5f56f0
  __asm__ volatile("fdivs %0" :: "m"(*(float *)(u32)(EBP - 124)) : "st");  // @718_5f56f0
  eax = (u32)(EBP - 108);  // @719_5f56f0
  PV[29] = (u32)(eax);  // @720_5f56f0
  ecx = (u32)(edi + 52);  // @721_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @722_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[29]);  // @723_5f56f0
  ecx = edx = 0;  // @724_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @725_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @726_5f56f0
  goto L5f57f3;  // @727_5f56f0
  L5f5c9a:;
  eax = (u32)(EBP - 124);  // @729_5f56f0
  PV[30] = (u32)(eax);  // @730_5f56f0
  ecx = (u32)(edi + 52);  // @731_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[30]);  // @732_5f56f0
  ecx = edx = 0;  // @733_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @734_5f56f0
  if (FL[0] != FL[1]) goto L5f5cd3;  // @735_5f56f0
  ecx = edi;  // @736_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @737_5f56f0
  ecx = edx = 0;  // @738_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @739_5f56f0
  FL[2] = (eax & eax);  // @740_5f56f0
  if (FL[2] == 0) goto L5f5cd2;  // @741_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @742_5f56f0
  ecx = edx = 0;  // @743_5f56f0
  ecx = (u32)(edi + 52);  // @744_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @745_5f56f0
  edx = 0;  // @746_5f56f0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @747_5f56f0
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @748_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @749_5f56f0
  goto L5f5936;  // @750_5f56f0
  L5f5cd2:;
  __builtin_trap();  // @752_5f56f0
  L5f5cd3:;
  ecx = (u32)(edi + 52);  // @754_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @755_5f56f0
  edx = 0;  // @756_5f56f0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @757_5f56f0
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @758_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @759_5f56f0
  goto L5f5936;  // @760_5f56f0
  L5f5ce7:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @762_5f56f0
  edx = (edx + (u32)(-22));  // @763_5f56f0
  FL[3] = edx;  // @764_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @765_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @766_5f56f0
  if ((s32)FL[2] >= 0) goto L5f5dd4;  // @767_5f56f0
  FL[0] = edx; FL[1] = (u32)(6);  // @768_5f56f0
  if (FL[0] > FL[1]) goto L5f5eaa;  // @769_5f56f0
  switch (edx) {  // @770_5f56f0
  case 0: goto L5f5d09;  // @771_5f56f0
  case 1: goto L5f5eaa;  // @772_5f56f0
  case 2: goto L5f5d38;  // @773_5f56f0
  case 3: goto L5f5eaa;  // @774_5f56f0
  case 4: goto L5f5d46;  // @775_5f56f0
  case 5: goto L5f5eaa;  // @776_5f56f0
  case 6: goto L5f5d75;  // @777_5f56f0
  default: __builtin_trap(); }  // @778_5f56f0
  L5f5d09:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @780_5f56f0
  X0[1] = 0;  // @781_5f56f0
  X0[2] = 0;  // @782_5f56f0
  X0[3] = 0;  // @783_5f56f0
  L5f5d0e:;
  ecx = (u32)(EBP - 108);  // @785_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @786_5f56f0
  PV[31] = (u32)(ecx);  // @787_5f56f0
  PV[32] = (u32)(eax);  // @788_5f56f0
  ecx = edi;  // @789_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[32]);  // @790_5f56f0
  ecx = edx = 0;  // @791_5f56f0
  ecx = eax;  // @792_5f56f0
  eax = ext_5f3db0_thiscall2(ecx, PV[31]);  // @793_5f56f0
  ecx = edx = 0;  // @794_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @795_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @796_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @797_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @798_5f56f0
  goto L5f57f3;  // @799_5f56f0
  L5f5d38:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @801_5f56f0
  X0[1] = 0;  // @802_5f56f0
  X0[2] = 0;  // @803_5f56f0
  X0[3] = 0;  // @804_5f56f0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @805_5f56f0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @806_5f56f0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @807_5f56f0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @808_5f56f0
  goto L5f5d0e;  // @809_5f56f0
  L5f5d46:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @811_5f56f0
  X0[1] = 0;  // @812_5f56f0
  X0[2] = 0;  // @813_5f56f0
  X0[3] = 0;  // @814_5f56f0
  ecx = (u32)(EBP - 108);  // @815_5f56f0
  PV[33] = (u32)(ecx);  // @816_5f56f0
  PV[34] = (u32)(eax);  // @817_5f56f0
  ecx = edi;  // @818_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @819_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[34]);  // @820_5f56f0
  ecx = edx = 0;  // @821_5f56f0
  ecx = eax;  // @822_5f56f0
  eax = ext_5f4e60_thiscall2(ecx, PV[33]);  // @823_5f56f0
  ecx = edx = 0;  // @824_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @825_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @826_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @827_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @828_5f56f0
  goto L5f57f3;  // @829_5f56f0
  L5f5d75:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @831_5f56f0
  X0[1] = 0;  // @832_5f56f0
  X0[2] = 0;  // @833_5f56f0
  X0[3] = 0;  // @834_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @835_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @836_5f56f0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5f5d9c;  // @837_5f56f0
  ecx = edi;  // @838_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @839_5f56f0
  ecx = edx = 0;  // @840_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @841_5f56f0
  FL[2] = (eax & eax);  // @842_5f56f0
  if (FL[2] == 0) goto L5f5d9b;  // @843_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @844_5f56f0
  ecx = edx = 0;  // @845_5f56f0
  goto L5f5d9c;  // @846_5f56f0
  L5f5d9b:;
  __builtin_trap();  // @848_5f56f0
  L5f5d9c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @850_5f56f0
  ecx = edi;  // @851_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2) + 0), 4); v; });  // @852_5f56f0
  X0[1] = 0;  // @853_5f56f0
  X0[2] = 0;  // @854_5f56f0
  X0[3] = 0;  // @855_5f56f0
  eax = (u32)(EBP - 108);  // @856_5f56f0
  PV[35] = (u32)(eax);  // @857_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @858_5f56f0
  PV[36] = (u32)(eax);  // @859_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @860_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[36]);  // @861_5f56f0
  ecx = edx = 0;  // @862_5f56f0
  ecx = eax;  // @863_5f56f0
  eax = ext_5f4110_thiscall2(ecx, PV[35]);  // @864_5f56f0
  ecx = edx = 0;  // @865_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @866_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @867_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @868_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @869_5f56f0
  goto L5f57f3;  // @870_5f56f0
  L5f5dd4:;
  FL[0] = edx; FL[1] = (u32)(6);  // @872_5f56f0
  if (FL[0] > FL[1]) goto L5f5eaa;  // @873_5f56f0
  switch (edx) {  // @874_5f56f0
  case 0: goto L5f5de4;  // @875_5f56f0
  case 1: goto L5f5eaa;  // @876_5f56f0
  case 2: goto L5f5e0e;  // @877_5f56f0
  case 3: goto L5f5eaa;  // @878_5f56f0
  case 4: goto L5f5e38;  // @879_5f56f0
  case 5: goto L5f5eaa;  // @880_5f56f0
  case 6: goto L5f5e62;  // @881_5f56f0
  default: __builtin_trap(); }  // @882_5f56f0
  L5f5de4:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @884_5f56f0
  X0[1] = 0;  // @885_5f56f0
  X0[2] = 0;  // @886_5f56f0
  X0[3] = 0;  // @887_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @888_5f56f0
  ecx = (eax & 0xffff);  // @889_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @890_5f56f0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; })));  // @891_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @892_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @893_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @894_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @895_5f56f0
  goto L5f57f3;  // @896_5f56f0
  L5f5e0e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @898_5f56f0
  ecx = (eax & 0xffff);  // @899_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @900_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @901_5f56f0
  X0[1] = 0;  // @902_5f56f0
  X0[2] = 0;  // @903_5f56f0
  X0[3] = 0;  // @904_5f56f0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; })));  // @905_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @906_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @907_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @908_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @909_5f56f0
  goto L5f57f3;  // @910_5f56f0
  L5f5e38:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @912_5f56f0
  X0[1] = 0;  // @913_5f56f0
  X0[2] = 0;  // @914_5f56f0
  X0[3] = 0;  // @915_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @916_5f56f0
  ecx = (eax & 0xffff);  // @917_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @918_5f56f0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; })));  // @919_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @920_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @921_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @922_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @923_5f56f0
  goto L5f57f3;  // @924_5f56f0
  L5f5e62:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @926_5f56f0
  X0[1] = 0;  // @927_5f56f0
  X0[2] = 0;  // @928_5f56f0
  X0[3] = 0;  // @929_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @930_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @931_5f56f0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5f5e89;  // @932_5f56f0
  ecx = edi;  // @933_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @934_5f56f0
  ecx = edx = 0;  // @935_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @936_5f56f0
  FL[2] = (eax & eax);  // @937_5f56f0
  if (FL[2] == 0) goto L5f5e88;  // @938_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @939_5f56f0
  ecx = edx = 0;  // @940_5f56f0
  goto L5f5e89;  // @941_5f56f0
  L5f5e88:;
  __builtin_trap();  // @943_5f56f0
  L5f5e89:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @945_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @946_5f56f0
  edx = (eax & 0xffff);  // @947_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @948_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + edx) + 0), 4); v; });  // @949_5f56f0
  X0[1] = 0;  // @950_5f56f0
  X0[2] = 0;  // @951_5f56f0
  X0[3] = 0;  // @952_5f56f0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2) + 0), 4); v; })));  // @953_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + edx) + 0), &X0[0], 4);  // @954_5f56f0
  L5f5eaa:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @956_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @957_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @958_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @959_5f56f0
  goto L5f57f3;  // @960_5f56f0
  L5f5ebc:;
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @962_5f56f0
  edx = (edx + (u32)(-23));  // @963_5f56f0
  FL[3] = edx;  // @964_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @965_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @966_5f56f0
  if ((s32)FL[2] >= 0) goto L5f5f8a;  // @967_5f56f0
  FL[0] = edx; FL[1] = (u32)(6);  // @968_5f56f0
  if (FL[0] > FL[1]) goto L5f6044;  // @969_5f56f0
  switch (edx) {  // @970_5f56f0
  case 0: goto L5f5ede;  // @971_5f56f0
  case 1: goto L5f6044;  // @972_5f56f0
  case 2: goto L5f5f09;  // @973_5f56f0
  case 3: goto L5f6044;  // @974_5f56f0
  case 4: goto L5f5f10;  // @975_5f56f0
  case 5: goto L5f6044;  // @976_5f56f0
  case 6: goto L5f5f3b;  // @977_5f56f0
  default: __builtin_trap(); }  // @978_5f56f0
  L5f5ede:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @980_5f56f0
  L5f5ee1:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @982_5f56f0
  eax = (u32)(EBP - 108);  // @983_5f56f0
  PV[37] = (u32)(eax);  // @984_5f56f0
  PV[38] = (u32)(ecx);  // @985_5f56f0
  ecx = edi;  // @986_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[38]);  // @987_5f56f0
  ecx = edx = 0;  // @988_5f56f0
  ecx = eax;  // @989_5f56f0
  eax = ext_5f3d40_thiscall2(ecx, PV[37]);  // @990_5f56f0
  ecx = edx = 0;  // @991_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @992_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @993_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @994_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @995_5f56f0
  goto L5f57f3;  // @996_5f56f0
  L5f5f09:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @998_5f56f0
  FL[1] = eax;  // @999_5f56f0
  eax = (0u - eax);  // @1000_5f56f0
  goto L5f5ee1;  // @1001_5f56f0
  L5f5f10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @1003_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1004_5f56f0
  eax = (u32)(EBP - 108);  // @1005_5f56f0
  PV[39] = (u32)(eax);  // @1006_5f56f0
  PV[40] = (u32)(ecx);  // @1007_5f56f0
  ecx = edi;  // @1008_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[40]);  // @1009_5f56f0
  ecx = edx = 0;  // @1010_5f56f0
  ecx = eax;  // @1011_5f56f0
  eax = ext_5f4e00_thiscall2(ecx, PV[39]);  // @1012_5f56f0
  ecx = edx = 0;  // @1013_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1014_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1015_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1016_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1017_5f56f0
  goto L5f57f3;  // @1018_5f56f0
  L5f5f3b:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1020_5f56f0
  if (FL[0] != FL[1]) goto L5f5f59;  // @1021_5f56f0
  ecx = edi;  // @1022_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @1023_5f56f0
  ecx = edx = 0;  // @1024_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1025_5f56f0
  FL[2] = (eax & eax);  // @1026_5f56f0
  if (FL[2] == 0) goto L5f5f55;  // @1027_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1028_5f56f0
  ecx = edx = 0;  // @1029_5f56f0
  goto L5f5f56;  // @1030_5f56f0
  L5f5f55:;
  __builtin_trap();  // @1032_5f56f0
  L5f5f56:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @1034_5f56f0
  L5f5f59:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1036_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; });  // @1037_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1038_5f56f0
  eax = (u32)(EBP - 108);  // @1039_5f56f0
  PV[41] = (u32)(eax);  // @1040_5f56f0
  PV[42] = (u32)(ecx);  // @1041_5f56f0
  ecx = edi;  // @1042_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[42]);  // @1043_5f56f0
  ecx = edx = 0;  // @1044_5f56f0
  ecx = eax;  // @1045_5f56f0
  eax = ext_5f40b0_thiscall2(ecx, PV[41]);  // @1046_5f56f0
  ecx = edx = 0;  // @1047_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1048_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1049_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1050_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1051_5f56f0
  goto L5f57f3;  // @1052_5f56f0
  L5f5f8a:;
  FL[0] = edx; FL[1] = (u32)(6);  // @1054_5f56f0
  if (FL[0] > FL[1]) goto L5f6044;  // @1055_5f56f0
  switch (edx) {  // @1056_5f56f0
  case 0: goto L5f5f9a;  // @1057_5f56f0
  case 1: goto L5f6044;  // @1058_5f56f0
  case 2: goto L5f5fbb;  // @1059_5f56f0
  case 3: goto L5f6044;  // @1060_5f56f0
  case 4: goto L5f5fdc;  // @1061_5f56f0
  case 5: goto L5f6044;  // @1062_5f56f0
  case 6: goto L5f6001;  // @1063_5f56f0
  default: __builtin_trap(); }  // @1064_5f56f0
  L5f5f9a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @1066_5f56f0
  edx = (ecx & 0xffff);  // @1067_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1068_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @1069_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @1070_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1071_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1072_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1073_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1074_5f56f0
  goto L5f57f3;  // @1075_5f56f0
  L5f5fbb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @1077_5f56f0
  edx = (ecx & 0xffff);  // @1078_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1079_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }) - eax)); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @1080_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @1081_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1082_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1083_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1084_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1085_5f56f0
  goto L5f57f3;  // @1086_5f56f0
  L5f5fdc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @1088_5f56f0
  edx = (ecx & 0xffff);  // @1089_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1090_5f56f0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }));  // @1091_5f56f0
  FL[3] = eax;  // @1092_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @1093_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1094_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1095_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1096_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1097_5f56f0
  goto L5f57f3;  // @1098_5f56f0
  L5f6001:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1100_5f56f0
  if (FL[0] != FL[1]) goto L5f601f;  // @1101_5f56f0
  ecx = edi;  // @1102_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @1103_5f56f0
  ecx = edx = 0;  // @1104_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1105_5f56f0
  FL[2] = (eax & eax);  // @1106_5f56f0
  if (FL[2] == 0) goto L5f601b;  // @1107_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1108_5f56f0
  ecx = edx = 0;  // @1109_5f56f0
  goto L5f601c;  // @1110_5f56f0
  L5f601b:;
  __builtin_trap();  // @1112_5f56f0
  L5f601c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @1114_5f56f0
  L5f601f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @1116_5f56f0
  edi = (ecx & 0xffff);  // @1117_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 158), sizeof v); (u32)v; });  // @1118_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 166), sizeof v); (u32)v; });  // @1119_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi), sizeof v); (u32)v; });  // @1120_5f56f0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @1121_5f56f0
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @1122_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @1123_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @1124_5f56f0
  L5f6044:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1126_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1127_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1128_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1129_5f56f0
  goto L5f57f3;  // @1130_5f56f0
  L5f6056:;
  ecx = (u32)(edi + 52);  // @1132_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @1133_5f56f0
  edx = 0;  // @1134_5f56f0
  esi = (eax & 0xffff);  // @1135_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @1136_5f56f0
  eax = (eax + (u32)(-30));  // @1137_5f56f0
  FL[3] = eax;  // @1138_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @1139_5f56f0
  if ((s32)FL[2] >= 0) goto L5f613c;  // @1140_5f56f0
  FL[0] = eax; FL[1] = (u32)(6);  // @1141_5f56f0
  if (FL[0] > FL[1]) goto L5f6202;  // @1142_5f56f0
  switch (eax) {  // @1143_5f56f0
  case 0: goto L5f6080;  // @1144_5f56f0
  case 1: goto L5f6202;  // @1145_5f56f0
  case 2: goto L5f60b0;  // @1146_5f56f0
  case 3: goto L5f6202;  // @1147_5f56f0
  case 4: goto L5f60bc;  // @1148_5f56f0
  case 5: goto L5f6202;  // @1149_5f56f0
  case 6: goto L5f60ec;  // @1150_5f56f0
  default: __builtin_trap(); }  // @1151_5f56f0
  L5f6080:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1153_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1154_5f56f0
  L5f6088:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1156_5f56f0
  eax = (u32)(EBP - 108);  // @1157_5f56f0
  PV[43] = (u32)(eax);  // @1158_5f56f0
  PV[44] = (u32)(esi);  // @1159_5f56f0
  L5f6090:;
  ecx = edi;  // @1161_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[44]);  // @1162_5f56f0
  ecx = edx = 0;  // @1163_5f56f0
  ecx = eax;  // @1164_5f56f0
  eax = ext_5f3d40_thiscall2(ecx, PV[43]);  // @1165_5f56f0
  ecx = edx = 0;  // @1166_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1167_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1168_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1169_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1170_5f56f0
  goto L5f57f3;  // @1171_5f56f0
  L5f60b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1173_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1174_5f56f0
  FL[1] = eax;  // @1175_5f56f0
  eax = (0u - eax);  // @1176_5f56f0
  goto L5f6088;  // @1177_5f56f0
  L5f60bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1179_5f56f0
  ecx = edi;  // @1180_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1181_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1182_5f56f0
  eax = (u32)(EBP - 108);  // @1183_5f56f0
  PV[45] = (u32)(eax);  // @1184_5f56f0
  PV[46] = (u32)(esi);  // @1185_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[46]);  // @1186_5f56f0
  ecx = edx = 0;  // @1187_5f56f0
  ecx = eax;  // @1188_5f56f0
  eax = ext_5f4e00_thiscall2(ecx, PV[45]);  // @1189_5f56f0
  ecx = edx = 0;  // @1190_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1191_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1192_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1193_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1194_5f56f0
  goto L5f57f3;  // @1195_5f56f0
  L5f60ec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1197_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1198_5f56f0
  if (FL[0] != FL[1]) goto L5f610c;  // @1199_5f56f0
  ecx = edi;  // @1200_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @1201_5f56f0
  ecx = edx = 0;  // @1202_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1203_5f56f0
  FL[2] = (eax & eax);  // @1204_5f56f0
  if (FL[2] == 0) goto L5f610b;  // @1205_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1206_5f56f0
  ecx = edx = 0;  // @1207_5f56f0
  goto L5f610c;  // @1208_5f56f0
  L5f610b:;
  __builtin_trap();  // @1210_5f56f0
  L5f610c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1212_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1213_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1214_5f56f0
  eax = (u32)(EBP - 108);  // @1215_5f56f0
  L5f611a:;
  PV[47] = (u32)(eax);  // @1217_5f56f0
  PV[48] = (u32)(esi);  // @1218_5f56f0
  ecx = edi;  // @1219_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[48]);  // @1220_5f56f0
  ecx = edx = 0;  // @1221_5f56f0
  ecx = eax;  // @1222_5f56f0
  eax = ext_5f40b0_thiscall2(ecx, PV[47]);  // @1223_5f56f0
  ecx = edx = 0;  // @1224_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1225_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1226_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1227_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1228_5f56f0
  goto L5f57f3;  // @1229_5f56f0
  L5f613c:;
  FL[0] = eax; FL[1] = (u32)(6);  // @1231_5f56f0
  if (FL[0] > FL[1]) goto L5f6202;  // @1232_5f56f0
  switch (eax) {  // @1233_5f56f0
  case 0: goto L5f614c;  // @1234_5f56f0
  case 1: goto L5f6202;  // @1235_5f56f0
  case 2: goto L5f6171;  // @1236_5f56f0
  case 3: goto L5f6202;  // @1237_5f56f0
  case 4: goto L5f6196;  // @1238_5f56f0
  case 5: goto L5f6202;  // @1239_5f56f0
  case 6: goto L5f61bf;  // @1240_5f56f0
  default: __builtin_trap(); }  // @1241_5f56f0
  L5f614c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1243_5f56f0
  edx = esi;  // @1244_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1245_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1246_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @1247_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @1248_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1249_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1250_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1251_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1252_5f56f0
  goto L5f57f3;  // @1253_5f56f0
  L5f6171:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1255_5f56f0
  edx = esi;  // @1256_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1257_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1258_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }) - eax)); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @1259_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @1260_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1261_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1262_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1263_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1264_5f56f0
  goto L5f57f3;  // @1265_5f56f0
  L5f6196:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1267_5f56f0
  edx = esi;  // @1268_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1269_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1270_5f56f0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }));  // @1271_5f56f0
  FL[3] = eax;  // @1272_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @1273_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1274_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1275_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1276_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1277_5f56f0
  goto L5f57f3;  // @1278_5f56f0
  L5f61bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1280_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1281_5f56f0
  if (FL[0] != FL[1]) goto L5f61df;  // @1282_5f56f0
  ecx = edi;  // @1283_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @1284_5f56f0
  ecx = edx = 0;  // @1285_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1286_5f56f0
  FL[2] = (eax & eax);  // @1287_5f56f0
  if (FL[2] == 0) goto L5f61de;  // @1288_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1289_5f56f0
  ecx = edx = 0;  // @1290_5f56f0
  goto L5f61df;  // @1291_5f56f0
  L5f61de:;
  __builtin_trap();  // @1293_5f56f0
  L5f61df:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @1295_5f56f0
  edi = esi;  // @1296_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 158), sizeof v); (u32)v; });  // @1297_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 166), sizeof v); (u32)v; });  // @1298_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi), sizeof v); (u32)v; });  // @1299_5f56f0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @1300_5f56f0
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @1301_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @1302_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @1303_5f56f0
  L5f6202:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1305_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1306_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1307_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1308_5f56f0
  goto L5f57f3;  // @1309_5f56f0
  L5f6214:;
  ecx = (u32)(edi + 52);  // @1311_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @1312_5f56f0
  edx = 0;  // @1313_5f56f0
  esi = (eax & 0xffff);  // @1314_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @1315_5f56f0
  eax = (eax + (u32)(-31));  // @1316_5f56f0
  FL[3] = eax;  // @1317_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @1318_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6319;  // @1319_5f56f0
  FL[0] = eax; FL[1] = (u32)(6);  // @1320_5f56f0
  if (FL[0] > FL[1]) goto L5f63fb;  // @1321_5f56f0
  switch (eax) {  // @1322_5f56f0
  case 0: goto L5f623e;  // @1323_5f56f0
  case 1: goto L5f63fb;  // @1324_5f56f0
  case 2: goto L5f6272;  // @1325_5f56f0
  case 3: goto L5f63fb;  // @1326_5f56f0
  case 4: goto L5f6285;  // @1327_5f56f0
  case 5: goto L5f63fb;  // @1328_5f56f0
  case 6: goto L5f62b9;  // @1329_5f56f0
  default: __builtin_trap(); }  // @1330_5f56f0
  L5f623e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1332_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1333_5f56f0
  X0[1] = 0;  // @1334_5f56f0
  X0[2] = 0;  // @1335_5f56f0
  X0[3] = 0;  // @1336_5f56f0
  L5f6248:;
  eax = (u32)(EBP - 108);  // @1338_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @1339_5f56f0
  PV[49] = (u32)(eax);  // @1340_5f56f0
  PV[50] = (u32)(esi);  // @1341_5f56f0
  ecx = edi;  // @1342_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[50]);  // @1343_5f56f0
  ecx = edx = 0;  // @1344_5f56f0
  ecx = eax;  // @1345_5f56f0
  eax = ext_5f3db0_thiscall2(ecx, PV[49]);  // @1346_5f56f0
  ecx = edx = 0;  // @1347_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1348_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1349_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1350_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1351_5f56f0
  goto L5f57f3;  // @1352_5f56f0
  L5f6272:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1354_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1355_5f56f0
  X0[1] = 0;  // @1356_5f56f0
  X0[2] = 0;  // @1357_5f56f0
  X0[3] = 0;  // @1358_5f56f0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @1359_5f56f0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @1360_5f56f0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @1361_5f56f0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @1362_5f56f0
  goto L5f6248;  // @1363_5f56f0
  L5f6285:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1365_5f56f0
  ecx = edi;  // @1366_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1367_5f56f0
  X0[1] = 0;  // @1368_5f56f0
  X0[2] = 0;  // @1369_5f56f0
  X0[3] = 0;  // @1370_5f56f0
  eax = (u32)(EBP - 108);  // @1371_5f56f0
  PV[51] = (u32)(eax);  // @1372_5f56f0
  PV[52] = (u32)(esi);  // @1373_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @1374_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[52]);  // @1375_5f56f0
  ecx = edx = 0;  // @1376_5f56f0
  ecx = eax;  // @1377_5f56f0
  eax = ext_5f4e60_thiscall2(ecx, PV[51]);  // @1378_5f56f0
  ecx = edx = 0;  // @1379_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1380_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1381_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1382_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1383_5f56f0
  goto L5f57f3;  // @1384_5f56f0
  L5f62b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1386_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1387_5f56f0
  X0[1] = 0;  // @1388_5f56f0
  X0[2] = 0;  // @1389_5f56f0
  X0[3] = 0;  // @1390_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @1391_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @1392_5f56f0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5f62e5;  // @1393_5f56f0
  ecx = edi;  // @1394_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @1395_5f56f0
  ecx = edx = 0;  // @1396_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1397_5f56f0
  FL[2] = (eax & eax);  // @1398_5f56f0
  if (FL[2] == 0) goto L5f62e4;  // @1399_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1400_5f56f0
  ecx = edx = 0;  // @1401_5f56f0
  goto L5f62e5;  // @1402_5f56f0
  L5f62e4:;
  __builtin_trap();  // @1404_5f56f0
  L5f62e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1406_5f56f0
  ecx = edi;  // @1407_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1408_5f56f0
  X0[1] = 0;  // @1409_5f56f0
  X0[2] = 0;  // @1410_5f56f0
  X0[3] = 0;  // @1411_5f56f0
  eax = (u32)(EBP - 108);  // @1412_5f56f0
  PV[53] = (u32)(eax);  // @1413_5f56f0
  PV[54] = (u32)(esi);  // @1414_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @1415_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[54]);  // @1416_5f56f0
  ecx = edx = 0;  // @1417_5f56f0
  ecx = eax;  // @1418_5f56f0
  eax = ext_5f4110_thiscall2(ecx, PV[53]);  // @1419_5f56f0
  ecx = edx = 0;  // @1420_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1421_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1422_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1423_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1424_5f56f0
  goto L5f57f3;  // @1425_5f56f0
  L5f6319:;
  FL[0] = eax; FL[1] = (u32)(6);  // @1427_5f56f0
  if (FL[0] > FL[1]) goto L5f63fb;  // @1428_5f56f0
  switch (eax) {  // @1429_5f56f0
  case 0: goto L5f6329;  // @1430_5f56f0
  case 1: goto L5f63fb;  // @1431_5f56f0
  case 2: goto L5f6357;  // @1432_5f56f0
  case 3: goto L5f63fb;  // @1433_5f56f0
  case 4: goto L5f6385;  // @1434_5f56f0
  case 5: goto L5f63fb;  // @1435_5f56f0
  case 6: goto L5f63b3;  // @1436_5f56f0
  default: __builtin_trap(); }  // @1437_5f56f0
  L5f6329:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1439_5f56f0
  edx = esi;  // @1440_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1441_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1442_5f56f0
  X0[1] = 0;  // @1443_5f56f0
  X0[2] = 0;  // @1444_5f56f0
  X0[3] = 0;  // @1445_5f56f0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + edx) + 0), 4); v; })));  // @1446_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + edx) + 0), &X0[0], 4);  // @1447_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1448_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1449_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1450_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1451_5f56f0
  goto L5f57f3;  // @1452_5f56f0
  L5f6357:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1454_5f56f0
  edx = esi;  // @1455_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1456_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + edx) + 0), 4); v; });  // @1457_5f56f0
  X0[1] = 0;  // @1458_5f56f0
  X0[2] = 0;  // @1459_5f56f0
  X0[3] = 0;  // @1460_5f56f0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @1461_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + edx) + 0), &X0[0], 4);  // @1462_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1463_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1464_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1465_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1466_5f56f0
  goto L5f57f3;  // @1467_5f56f0
  L5f6385:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1469_5f56f0
  edx = esi;  // @1470_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1471_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1472_5f56f0
  X0[1] = 0;  // @1473_5f56f0
  X0[2] = 0;  // @1474_5f56f0
  X0[3] = 0;  // @1475_5f56f0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + edx) + 0), 4); v; })));  // @1476_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + edx) + 0), &X0[0], 4);  // @1477_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1478_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1479_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1480_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1481_5f56f0
  goto L5f57f3;  // @1482_5f56f0
  L5f63b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1484_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1485_5f56f0
  X0[1] = 0;  // @1486_5f56f0
  X0[2] = 0;  // @1487_5f56f0
  X0[3] = 0;  // @1488_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @1489_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @1490_5f56f0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5f63df;  // @1491_5f56f0
  ecx = edi;  // @1492_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @1493_5f56f0
  ecx = edx = 0;  // @1494_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1495_5f56f0
  FL[2] = (eax & eax);  // @1496_5f56f0
  if (FL[2] == 0) goto L5f63de;  // @1497_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1498_5f56f0
  ecx = edx = 0;  // @1499_5f56f0
  goto L5f63df;  // @1500_5f56f0
  L5f63de:;
  __builtin_trap();  // @1502_5f56f0
  L5f63df:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1504_5f56f0
  edx = esi;  // @1505_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1506_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + edx) + 0), 4); v; });  // @1507_5f56f0
  X0[1] = 0;  // @1508_5f56f0
  X0[2] = 0;  // @1509_5f56f0
  X0[3] = 0;  // @1510_5f56f0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @1511_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + edx) + 0), &X0[0], 4);  // @1512_5f56f0
  L5f63fb:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1514_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1515_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1516_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1517_5f56f0
  goto L5f57f3;  // @1518_5f56f0
  L5f640d:;
  eax = (u32)(EBP - 124);  // @1520_5f56f0
  PV[55] = (u32)(eax);  // @1521_5f56f0
  ecx = (u32)(edi + 52);  // @1522_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[55]);  // @1523_5f56f0
  ecx = edx = 0;  // @1524_5f56f0
  ecx = (u32)(edi + 52);  // @1525_5f56f0
  eax = ext_5f4ec0_thiscall2(ecx, (u32)(0));  // @1526_5f56f0
  ecx = edx = 0;  // @1527_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @1528_5f56f0
  X0[1] = 0;  // @1529_5f56f0
  X0[2] = 0;  // @1530_5f56f0
  X0[3] = 0;  // @1531_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1532_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1533_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; }))))))) goto L5f57f3;  // @1534_5f56f0
  ecx = (u32)(edi + 52);  // @1535_5f56f0
  eax = ext_5f4f70_thiscall1(ecx);  // @1536_5f56f0
  ecx = edx = 0;  // @1537_5f56f0
  eax = (u32)(EBP - 124);  // @1538_5f56f0
  PV[56] = (u32)(eax);  // @1539_5f56f0
  ecx = (u32)(edi + 52);  // @1540_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[56]);  // @1541_5f56f0
  ecx = edx = 0;  // @1542_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1543_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1544_5f56f0
  goto L5f57f3;  // @1545_5f56f0
  L5f6456:;
  eax = (u32)(EBP - 124);  // @1547_5f56f0
  PV[57] = (u32)(eax);  // @1548_5f56f0
  ecx = (u32)(edi + 52);  // @1549_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[57]);  // @1550_5f56f0
  ecx = edx = 0;  // @1551_5f56f0
  ecx = (u32)(edi + 52);  // @1552_5f56f0
  eax = ext_5f4ec0_thiscall2(ecx, (u32)(0));  // @1553_5f56f0
  ecx = edx = 0;  // @1554_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1555_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1556_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1557_5f56f0
  X0[1] = 0;  // @1558_5f56f0
  X0[2] = 0;  // @1559_5f56f0
  X0[3] = 0;  // @1560_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))))))) goto L5f57f3;  // @1561_5f56f0
  ecx = (u32)(edi + 52);  // @1562_5f56f0
  eax = ext_5f4f70_thiscall1(ecx);  // @1563_5f56f0
  ecx = edx = 0;  // @1564_5f56f0
  eax = (u32)(EBP - 124);  // @1565_5f56f0
  PV[58] = (u32)(eax);  // @1566_5f56f0
  ecx = (u32)(edi + 52);  // @1567_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[58]);  // @1568_5f56f0
  ecx = edx = 0;  // @1569_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1570_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1571_5f56f0
  goto L5f57f3;  // @1572_5f56f0
  L5f649f:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1574_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @1575_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1576_5f56f0
  if ((s32)FL[2] >= 0) goto L5f64ee;  // @1577_5f56f0
  PV[59] = (u32)(eax);  // @1578_5f56f0
  ecx = edi;  // @1579_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[59]);  // @1580_5f56f0
  ecx = edx = 0;  // @1581_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1582_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2) + 0), 4); v; });  // @1583_5f56f0
  X0[1] = 0;  // @1584_5f56f0
  X0[2] = 0;  // @1585_5f56f0
  X0[3] = 0;  // @1586_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; }))))))) goto L5f6507;  // @1587_5f56f0
  eax = (u32)(EBP - 108);  // @1588_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @1589_5f56f0
  PV[60] = (u32)(eax);  // @1590_5f56f0
  PV[61] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @1591_5f56f0
  ecx = edi;  // @1592_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[61]);  // @1593_5f56f0
  ecx = edx = 0;  // @1594_5f56f0
  ecx = eax;  // @1595_5f56f0
  eax = ext_602cd0_thiscall2(ecx, PV[60]);  // @1596_5f56f0
  ecx = edx = 0;  // @1597_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1598_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1599_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1600_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1601_5f56f0
  goto L5f57f3;  // @1602_5f56f0
  L5f64ee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1604_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @1605_5f56f0
  X0[1] = 0;  // @1606_5f56f0
  X0[2] = 0;  // @1607_5f56f0
  X0[3] = 0;  // @1608_5f56f0
  eax = (eax & 0xffff);  // @1609_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; }))))))) goto L5f6507;  // @1610_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X0[0], 4);  // @1611_5f56f0
  L5f6507:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1613_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1614_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1615_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1616_5f56f0
  goto L5f57f3;  // @1617_5f56f0
  L5f6519:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1619_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1620_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1621_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6563;  // @1622_5f56f0
  PV[62] = (u32)(eax);  // @1623_5f56f0
  ecx = edi;  // @1624_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[62]);  // @1625_5f56f0
  ecx = edx = 0;  // @1626_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1627_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1628_5f56f0
  X0[1] = 0;  // @1629_5f56f0
  X0[2] = 0;  // @1630_5f56f0
  X0[3] = 0;  // @1631_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2) + 0), 4); v; });  // @1632_5f56f0
  X1[1] = 0;  // @1633_5f56f0
  X1[2] = 0;  // @1634_5f56f0
  X1[3] = 0;  // @1635_5f56f0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5f6580;  // @1636_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1637_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1638_5f56f0
  ecx = (eax & 0xffff);  // @1639_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1640_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X1[0], 4);  // @1641_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1642_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1643_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1644_5f56f0
  goto L5f57f3;  // @1645_5f56f0
  L5f6563:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1647_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @1648_5f56f0
  X1[1] = 0;  // @1649_5f56f0
  X1[2] = 0;  // @1650_5f56f0
  X1[3] = 0;  // @1651_5f56f0
  eax = (eax & 0xffff);  // @1652_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; });  // @1653_5f56f0
  X0[1] = 0;  // @1654_5f56f0
  X0[2] = 0;  // @1655_5f56f0
  X0[3] = 0;  // @1656_5f56f0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5f6580;  // @1657_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X1[0], 4);  // @1658_5f56f0
  L5f6580:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1660_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1661_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1662_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1663_5f56f0
  goto L5f57f3;  // @1664_5f56f0
  L5f6592:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @1666_5f56f0
  X0[1] = 0;  // @1667_5f56f0
  X0[2] = 0;  // @1668_5f56f0
  X0[3] = 0;  // @1669_5f56f0
  L5f6596:;
  eax = (u32)(EBP - 108);  // @1671_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @1672_5f56f0
  PV[63] = (u32)(eax);  // @1673_5f56f0
  ecx = (u32)(edi + 52);  // @1674_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[63]);  // @1675_5f56f0
  ecx = edx = 0;  // @1676_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1677_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1678_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1679_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1680_5f56f0
  goto L5f57f3;  // @1681_5f56f0
  L5f65b9:;
  ecx = (u32)(edi + 52);  // @1683_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @1684_5f56f0
  edx = 0;  // @1685_5f56f0
  eax = (eax & 0xffff);  // @1686_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1687_5f56f0
  if ((s32)FL[2] >= 0) goto L5f65e5;  // @1688_5f56f0
  PV[64] = (u32)(eax);  // @1689_5f56f0
  ecx = edi;  // @1690_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[64]);  // @1691_5f56f0
  ecx = edx = 0;  // @1692_5f56f0
  PV[65] = (u32)(eax);  // @1693_5f56f0
  ecx = (u32)(edi + 52);  // @1694_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[65]);  // @1695_5f56f0
  ecx = edx = 0;  // @1696_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1697_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1698_5f56f0
  goto L5f57f3;  // @1699_5f56f0
  L5f65e5:;
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; }));  // @1701_5f56f0
  FL[3] = eax;  // @1702_5f56f0
  ecx = (u32)(edi + 52);  // @1703_5f56f0
  PV[66] = (u32)(eax);  // @1704_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[66]);  // @1705_5f56f0
  ecx = edx = 0;  // @1706_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1707_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1708_5f56f0
  goto L5f57f3;  // @1709_5f56f0
  L5f65ff:;
  ecx = (u32)(edi + 52);  // @1711_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @1712_5f56f0
  edx = 0;  // @1713_5f56f0
  eax = (eax & 0xffff);  // @1714_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1715_5f56f0
  if ((s32)FL[2] >= 0) goto L5f662b;  // @1716_5f56f0
  PV[67] = (u32)(eax);  // @1717_5f56f0
  ecx = edi;  // @1718_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[67]);  // @1719_5f56f0
  ecx = edx = 0;  // @1720_5f56f0
  PV[68] = (u32)(eax);  // @1721_5f56f0
  ecx = (u32)(edi + 52);  // @1722_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[68]);  // @1723_5f56f0
  ecx = edx = 0;  // @1724_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1725_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1726_5f56f0
  goto L5f57f3;  // @1727_5f56f0
  L5f662b:;
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; }));  // @1729_5f56f0
  FL[3] = eax;  // @1730_5f56f0
  ecx = (u32)(edi + 52);  // @1731_5f56f0
  PV[69] = (u32)(eax);  // @1732_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[69]);  // @1733_5f56f0
  ecx = edx = 0;  // @1734_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1735_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1736_5f56f0
  goto L5f57f3;  // @1737_5f56f0
  L5f6645:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1739_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1740_5f56f0
  if ((s32)FL[2] >= 0) goto L5f665a;  // @1741_5f56f0
  PV[70] = (u32)(eax);  // @1742_5f56f0
  ecx = edi;  // @1743_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[70]);  // @1744_5f56f0
  ecx = edx = 0;  // @1745_5f56f0
  goto L5f57d7;  // @1746_5f56f0
  L5f665a:;
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; }));  // @1748_5f56f0
  FL[3] = eax;  // @1749_5f56f0
  L5f6660:;
  PV[71] = (u32)(eax);  // @1751_5f56f0
  ecx = (u32)(edi + 52);  // @1752_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[71]);  // @1753_5f56f0
  ecx = edx = 0;  // @1754_5f56f0
  L5f6669:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1756_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1757_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1758_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1759_5f56f0
  goto L5f57f3;  // @1760_5f56f0
  L5f667b:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1762_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1763_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6699;  // @1764_5f56f0
  PV[72] = (u32)(eax);  // @1765_5f56f0
  ecx = edi;  // @1766_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[72]);  // @1767_5f56f0
  ecx = edx = 0;  // @1768_5f56f0
  PV[73] = (u32)(eax);  // @1769_5f56f0
  ecx = (u32)(edi + 52);  // @1770_5f56f0
  eax = ext_5f51e0_thiscall2(ecx, PV[73]);  // @1771_5f56f0
  ecx = edx = 0;  // @1772_5f56f0
  goto L5f57e0;  // @1773_5f56f0
  L5f6699:;
  ecx = eax;  // @1775_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1776_5f56f0
  PV[74] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; });  // @1777_5f56f0
  ecx = (u32)(edi + 52);  // @1778_5f56f0
  eax = ext_5f5390_thiscall2(ecx, PV[74]);  // @1779_5f56f0
  ecx = edx = 0;  // @1780_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1781_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1782_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1783_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1784_5f56f0
  goto L5f57f3;  // @1785_5f56f0
  L5f66be:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1787_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1788_5f56f0
  if ((s32)FL[2] >= 0) goto L5f66dc;  // @1789_5f56f0
  PV[75] = (u32)(eax);  // @1790_5f56f0
  ecx = edi;  // @1791_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[75]);  // @1792_5f56f0
  ecx = edx = 0;  // @1793_5f56f0
  PV[76] = (u32)(eax);  // @1794_5f56f0
  ecx = (u32)(edi + 52);  // @1795_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[76]);  // @1796_5f56f0
  ecx = edx = 0;  // @1797_5f56f0
  goto L5f57e0;  // @1798_5f56f0
  L5f66dc:;
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; }));  // @1800_5f56f0
  FL[3] = eax;  // @1801_5f56f0
  L5f66e2:;
  PV[77] = (u32)(eax);  // @1803_5f56f0
  ecx = (u32)(edi + 52);  // @1804_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[77]);  // @1805_5f56f0
  ecx = edx = 0;  // @1806_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1807_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1808_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1809_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1810_5f56f0
  goto L5f57f3;  // @1811_5f56f0
  L5f66fd:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1813_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1814_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6725;  // @1815_5f56f0
  PV[78] = (u32)(eax);  // @1816_5f56f0
  ecx = edi;  // @1817_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[78]);  // @1818_5f56f0
  ecx = edx = 0;  // @1819_5f56f0
  ecx = (u32)(edi + 52);  // @1820_5f56f0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @1821_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1822_5f56f0
  eax = (u32)(EBP - 108);  // @1823_5f56f0
  PV[79] = (u32)(eax);  // @1824_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[79]);  // @1825_5f56f0
  ecx = edx = 0;  // @1826_5f56f0
  goto L5f57e0;  // @1827_5f56f0
  L5f6725:;
  ecx = eax;  // @1829_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1830_5f56f0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @1831_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1832_5f56f0
  eax = (u32)(EBP - 108);  // @1833_5f56f0
  goto L5f66e2;  // @1834_5f56f0
  L5f673a:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1836_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @1837_5f56f0
  if ((s32)FL[2] >= 0) goto L5f675e;  // @1838_5f56f0
  PV[80] = (u32)(eax);  // @1839_5f56f0
  ecx = edi;  // @1840_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[80]);  // @1841_5f56f0
  ecx = edx = 0;  // @1842_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @1843_5f56f0
  eax = (u32)(EBP - 108);  // @1844_5f56f0
  X0[0] = F2U((float)(s32)X0[0]);  // @1845_5f56f0
  X0[1] = F2U((float)(s32)X0[1]);  // @1846_5f56f0
  X0[2] = F2U((float)(s32)X0[2]);  // @1847_5f56f0
  X0[3] = F2U((float)(s32)X0[3]);  // @1848_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @1849_5f56f0
  goto L5f57d7;  // @1850_5f56f0
  L5f675e:;
  ecx = eax;  // @1852_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1853_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @1854_5f56f0
  eax = (u32)(EBP - 108);  // @1855_5f56f0
  X0[0] = F2U((float)(s32)X0[0]);  // @1856_5f56f0
  X0[1] = F2U((float)(s32)X0[1]);  // @1857_5f56f0
  X0[2] = F2U((float)(s32)X0[2]);  // @1858_5f56f0
  X0[3] = F2U((float)(s32)X0[3]);  // @1859_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @1860_5f56f0
  goto L5f6660;  // @1861_5f56f0
  L5f677b:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1863_5f56f0
  ecx = (u32)(edi + 52);  // @1864_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @1865_5f56f0
  edx = 0;  // @1866_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @1867_5f56f0
  if ((s32)FL[2] >= 0) goto L5f67b9;  // @1868_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 140)) :: "st");  // @1869_5f56f0
  eax = (u32)(EBP - 140);  // @1870_5f56f0
  L5f6797:;
  PV[81] = (u32)(eax);  // @1872_5f56f0
  PV[82] = (u32)(esi);  // @1873_5f56f0
  ecx = edi;  // @1874_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[82]);  // @1875_5f56f0
  ecx = edx = 0;  // @1876_5f56f0
  ecx = eax;  // @1877_5f56f0
  eax = ext_602cd0_thiscall2(ecx, PV[81]);  // @1878_5f56f0
  ecx = edx = 0;  // @1879_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1880_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1881_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1882_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1883_5f56f0
  goto L5f57f3;  // @1884_5f56f0
  L5f67b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1886_5f56f0
  ecx = esi;  // @1887_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1888_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + eax)) :: "st");  // @1889_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1890_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1891_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1892_5f56f0
  goto L5f57f3;  // @1893_5f56f0
  L5f67d6:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1895_5f56f0
  ecx = (u32)(edi + 52);  // @1896_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @1897_5f56f0
  edx = 0;  // @1898_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @1899_5f56f0
  if ((s32)FL[2] >= 0) goto L5f681d;  // @1900_5f56f0
  L5f67e6:;
  PV[83] = (u32)(eax);  // @1902_5f56f0
  PV[84] = (u32)(esi);  // @1903_5f56f0
  ecx = edi;  // @1904_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[84]);  // @1905_5f56f0
  ecx = edx = 0;  // @1906_5f56f0
  ecx = eax;  // @1907_5f56f0
  eax = ext_5002f0_thiscall2(ecx, PV[83]);  // @1908_5f56f0
  ecx = edx = 0;  // @1909_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1910_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1911_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1912_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1913_5f56f0
  goto L5f57f3;  // @1914_5f56f0
  L5f6808:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1916_5f56f0
  ecx = (u32)(edi + 52);  // @1917_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @1918_5f56f0
  edx = 0;  // @1919_5f56f0
  eax = ext_634670_cdecl0();  // @1920_5f56f0
  ecx = edx = 0;  // @1921_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @1922_5f56f0
  if ((s32)FL[2] < 0) goto L5f67e6;  // @1923_5f56f0
  L5f681d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1925_5f56f0
  edx = esi;  // @1926_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @1927_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1928_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1929_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1930_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1931_5f56f0
  goto L5f57f3;  // @1932_5f56f0
  L5f683a:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1934_5f56f0
  ecx = (u32)(edi + 52);  // @1935_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @1936_5f56f0
  edx = 0;  // @1937_5f56f0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @1938_5f56f0
  X0[0] = F2U((float)(s32)X0[0]);  // @1939_5f56f0
  X0[1] = F2U((float)(s32)X0[1]);  // @1940_5f56f0
  X0[2] = F2U((float)(s32)X0[2]);  // @1941_5f56f0
  X0[3] = F2U((float)(s32)X0[3]);  // @1942_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @1943_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6878;  // @1944_5f56f0
  PV[85] = (u32)(ecx);  // @1945_5f56f0
  PV[86] = X0[0];  // @1946_5f56f0
  ecx = edi;  // @1947_5f56f0
  PV[87] = (u32)(esi);  // @1948_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[87]);  // @1949_5f56f0
  ecx = edx = 0;  // @1950_5f56f0
  ecx = eax;  // @1951_5f56f0
  eax = ext_500360_thiscall2(ecx, PV[86]);  // @1952_5f56f0
  ecx = edx = 0;  // @1953_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1954_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1955_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1956_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1957_5f56f0
  goto L5f57f3;  // @1958_5f56f0
  L5f6878:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @1960_5f56f0
  ecx = esi;  // @1961_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1962_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X0[0], 4);  // @1963_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1964_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1965_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1966_5f56f0
  goto L5f57f3;  // @1967_5f56f0
  L5f6897:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1969_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @1970_5f56f0
  if ((s32)FL[2] >= 0) goto L5f68cf;  // @1971_5f56f0
  ecx = (u32)(edi + 52);  // @1972_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @1973_5f56f0
  edx = 0;  // @1974_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @1975_5f56f0
  L5f68aa:;
  eax = (u32)(EBP - 108);  // @1977_5f56f0
  ecx = edi;  // @1978_5f56f0
  PV[88] = (u32)(eax);  // @1979_5f56f0
  PV[89] = (u32)(esi);  // @1980_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[89]);  // @1981_5f56f0
  ecx = edx = 0;  // @1982_5f56f0
  ecx = eax;  // @1983_5f56f0
  eax = ext_5f3db0_thiscall2(ecx, PV[88]);  // @1984_5f56f0
  ecx = edx = 0;  // @1985_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @1986_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @1987_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1988_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1989_5f56f0
  goto L5f57f3;  // @1990_5f56f0
  L5f68cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @1992_5f56f0
  edi = esi;  // @1993_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 158), sizeof v); (u32)v; });  // @1994_5f56f0
  ecx = (u32)(eax + 52);  // @1995_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @1996_5f56f0
  edx = 0;  // @1997_5f56f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi + edi)) : "st");  // @1998_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1999_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2000_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + edi)) :: "st");  // @2001_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2002_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2003_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2004_5f56f0
  goto L5f57f3;  // @2005_5f56f0
  L5f6903:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2007_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2008_5f56f0
  if ((s32)FL[2] >= 0) goto L5f693b;  // @2009_5f56f0
  ecx = (u32)(edi + 52);  // @2010_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2011_5f56f0
  edx = 0;  // @2012_5f56f0
  L5f6913:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2014_5f56f0
  ecx = edi;  // @2015_5f56f0
  eax = (u32)(EBP - 108);  // @2016_5f56f0
  PV[90] = (u32)(eax);  // @2017_5f56f0
  PV[91] = (u32)(esi);  // @2018_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[91]);  // @2019_5f56f0
  ecx = edx = 0;  // @2020_5f56f0
  ecx = eax;  // @2021_5f56f0
  eax = ext_5f3d40_thiscall2(ecx, PV[90]);  // @2022_5f56f0
  ecx = edx = 0;  // @2023_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2024_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2025_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2026_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2027_5f56f0
  goto L5f57f3;  // @2028_5f56f0
  L5f693b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2030_5f56f0
  edi = esi;  // @2031_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 158), sizeof v); (u32)v; });  // @2032_5f56f0
  ecx = (u32)(eax + 52);  // @2033_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2034_5f56f0
  edx = 0;  // @2035_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @2036_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi), sizeof v); (u32)v; });  // @2037_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2038_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2039_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2040_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2041_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2042_5f56f0
  goto L5f57f3;  // @2043_5f56f0
  L5f696c:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2045_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2046_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6995;  // @2047_5f56f0
  ecx = (u32)(edi + 52);  // @2048_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2049_5f56f0
  edx = 0;  // @2050_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @2051_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @2052_5f56f0
  X0[1] = 0;  // @2053_5f56f0
  X0[2] = 0;  // @2054_5f56f0
  X0[3] = 0;  // @2055_5f56f0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @2056_5f56f0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @2057_5f56f0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @2058_5f56f0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @2059_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @2060_5f56f0
  goto L5f68aa;  // @2061_5f56f0
  L5f6995:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2063_5f56f0
  edi = esi;  // @2064_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 158), sizeof v); (u32)v; });  // @2065_5f56f0
  ecx = (u32)(eax + 52);  // @2066_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2067_5f56f0
  edx = 0;  // @2068_5f56f0
  __asm__ volatile("fsubrs %0" :: "m"(*(float *)(u32)(esi + edi)) : "st");  // @2069_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2070_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2071_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 158), sizeof v); (u32)v; });  // @2072_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @2073_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @2074_5f56f0
  X0[1] = 0;  // @2075_5f56f0
  X0[2] = 0;  // @2076_5f56f0
  X0[3] = 0;  // @2077_5f56f0
  __builtin_memcpy((void *)((u32)(edi + eax) + 0), &X0[0], 4);  // @2078_5f56f0
  edi = ecx;  // @2079_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2080_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2081_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2082_5f56f0
  goto L5f57f3;  // @2083_5f56f0
  L5f69db:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2085_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2086_5f56f0
  if ((s32)FL[2] >= 0) goto L5f69f2;  // @2087_5f56f0
  ecx = (u32)(edi + 52);  // @2088_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2089_5f56f0
  edx = 0;  // @2090_5f56f0
  FL[1] = eax;  // @2091_5f56f0
  eax = (0u - eax);  // @2092_5f56f0
  goto L5f6913;  // @2093_5f56f0
  L5f69f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2095_5f56f0
  edi = esi;  // @2096_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 158), sizeof v); (u32)v; });  // @2097_5f56f0
  ecx = (u32)(eax + 52);  // @2098_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2099_5f56f0
  edx = 0;  // @2100_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi), sizeof v); (u32)v; }) - eax)); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @2101_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi), sizeof v); (u32)v; });  // @2102_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2103_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2104_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2105_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2106_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2107_5f56f0
  goto L5f57f3;  // @2108_5f56f0
  L5f6a23:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2110_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2111_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6a5b;  // @2112_5f56f0
  ecx = (u32)(edi + 52);  // @2113_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2114_5f56f0
  edx = 0;  // @2115_5f56f0
  eax = (u32)(EBP - 108);  // @2116_5f56f0
  ecx = edi;  // @2117_5f56f0
  PV[92] = (u32)(eax);  // @2118_5f56f0
  PV[93] = (u32)(esi);  // @2119_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @2120_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[93]);  // @2121_5f56f0
  ecx = edx = 0;  // @2122_5f56f0
  ecx = eax;  // @2123_5f56f0
  eax = ext_5f4e60_thiscall2(ecx, PV[92]);  // @2124_5f56f0
  ecx = edx = 0;  // @2125_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2126_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2127_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2128_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2129_5f56f0
  goto L5f57f3;  // @2130_5f56f0
  L5f6a5b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2132_5f56f0
  edi = esi;  // @2133_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 158), sizeof v); (u32)v; });  // @2134_5f56f0
  ecx = (u32)(eax + 52);  // @2135_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2136_5f56f0
  edx = 0;  // @2137_5f56f0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(esi + edi)) : "st");  // @2138_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2139_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2140_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + edi)) :: "st");  // @2141_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2142_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2143_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2144_5f56f0
  goto L5f57f3;  // @2145_5f56f0
  L5f6a8f:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2147_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2148_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6ac7;  // @2149_5f56f0
  ecx = (u32)(edi + 52);  // @2150_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2151_5f56f0
  edx = 0;  // @2152_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2153_5f56f0
  ecx = edi;  // @2154_5f56f0
  eax = (u32)(EBP - 108);  // @2155_5f56f0
  PV[94] = (u32)(eax);  // @2156_5f56f0
  PV[95] = (u32)(esi);  // @2157_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[95]);  // @2158_5f56f0
  ecx = edx = 0;  // @2159_5f56f0
  ecx = eax;  // @2160_5f56f0
  eax = ext_5f4e00_thiscall2(ecx, PV[94]);  // @2161_5f56f0
  ecx = edx = 0;  // @2162_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2163_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2164_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2165_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2166_5f56f0
  goto L5f57f3;  // @2167_5f56f0
  L5f6ac7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2169_5f56f0
  edi = esi;  // @2170_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 158), sizeof v); (u32)v; });  // @2171_5f56f0
  ecx = (u32)(eax + 52);  // @2172_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2173_5f56f0
  edx = 0;  // @2174_5f56f0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi), sizeof v); (u32)v; }));  // @2175_5f56f0
  FL[3] = eax;  // @2176_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2177_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2178_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @2179_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @2180_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2181_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2182_5f56f0
  goto L5f57f3;  // @2183_5f56f0
  L5f6afc:;
  eax = (u32)(EBP - 124);  // @2185_5f56f0
  PV[96] = (u32)(eax);  // @2186_5f56f0
  ecx = (u32)(edi + 52);  // @2187_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[96]);  // @2188_5f56f0
  ecx = edx = 0;  // @2189_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2190_5f56f0
  X1[1] = 0;  // @2191_5f56f0
  X1[2] = 0;  // @2192_5f56f0
  X1[3] = 0;  // @2193_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @2194_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @2195_5f56f0
  if (__builtin_parity(FL[2] & 0xff)) goto L5f6b75;  // @2196_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2197_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2198_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @2199_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6b4d;  // @2200_5f56f0
  ecx = (u32)(EBP - 124);  // @2201_5f56f0
  PV[97] = (u32)(ecx);  // @2202_5f56f0
  PV[98] = (u32)(eax);  // @2203_5f56f0
  ecx = edi;  // @2204_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[98]);  // @2205_5f56f0
  ecx = edx = 0;  // @2206_5f56f0
  ecx = eax;  // @2207_5f56f0
  eax = ext_5f4110_thiscall2(ecx, PV[97]);  // @2208_5f56f0
  ecx = edx = 0;  // @2209_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2210_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2211_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2212_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2213_5f56f0
  goto L5f57f3;  // @2214_5f56f0
  L5f6b4d:;
  ecx = eax;  // @2216_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2217_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2218_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @2219_5f56f0
  X0[1] = 0;  // @2220_5f56f0
  X0[2] = 0;  // @2221_5f56f0
  X0[3] = 0;  // @2222_5f56f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @2223_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @2224_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2225_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2226_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2227_5f56f0
  goto L5f57f3;  // @2228_5f56f0
  L5f6b75:;
  ecx = edi;  // @2230_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @2231_5f56f0
  ecx = edx = 0;  // @2232_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2233_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2234_5f56f0
  goto L5f57f3;  // @2235_5f56f0
  L5f6b87:;
  eax = (u32)(EBP - 124);  // @2237_5f56f0
  PV[99] = (u32)(eax);  // @2238_5f56f0
  ecx = (u32)(edi + 52);  // @2239_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[99]);  // @2240_5f56f0
  ecx = edx = 0;  // @2241_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2242_5f56f0
  if (FL[0] == FL[1]) goto L5f6b75;  // @2243_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2244_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2245_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @2246_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6bcc;  // @2247_5f56f0
  ecx = (u32)(EBP - 124);  // @2248_5f56f0
  PV[100] = (u32)(ecx);  // @2249_5f56f0
  PV[101] = (u32)(eax);  // @2250_5f56f0
  ecx = edi;  // @2251_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[101]);  // @2252_5f56f0
  ecx = edx = 0;  // @2253_5f56f0
  ecx = eax;  // @2254_5f56f0
  eax = ext_5f40b0_thiscall2(ecx, PV[100]);  // @2255_5f56f0
  ecx = edx = 0;  // @2256_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2257_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2258_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2259_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2260_5f56f0
  goto L5f57f3;  // @2261_5f56f0
  L5f6bcc:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2263_5f56f0
  esi = eax;  // @2264_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi), sizeof v); (u32)v; });  // @2265_5f56f0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @2266_5f56f0
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @2267_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2268_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + esi), &v, sizeof v); }  // @2269_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2270_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2271_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2272_5f56f0
  goto L5f57f3;  // @2273_5f56f0
  L5f6bf0:;
  eax = (u32)(EBP - 124);  // @2275_5f56f0
  PV[102] = (u32)(eax);  // @2276_5f56f0
  ecx = (u32)(edi + 52);  // @2277_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[102]);  // @2278_5f56f0
  ecx = edx = 0;  // @2279_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2280_5f56f0
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2281_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2282_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6c28;  // @2283_5f56f0
  PV[103] = (u32)(esi);  // @2284_5f56f0
  ecx = edi;  // @2285_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[103]);  // @2286_5f56f0
  ecx = edx = 0;  // @2287_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @2288_5f56f0
  X0[1] = 0;  // @2289_5f56f0
  X0[2] = 0;  // @2290_5f56f0
  X0[3] = 0;  // @2291_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))))))) goto L5f6669;  // @2292_5f56f0
  eax = (u32)(EBP - 124);  // @2293_5f56f0
  goto L5f6797;  // @2294_5f56f0
  L5f6c28:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2296_5f56f0
  eax = esi;  // @2297_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2298_5f56f0
  X1[1] = 0;  // @2299_5f56f0
  X1[2] = 0;  // @2300_5f56f0
  X1[3] = 0;  // @2301_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; });  // @2302_5f56f0
  X0[1] = 0;  // @2303_5f56f0
  X0[2] = 0;  // @2304_5f56f0
  X0[3] = 0;  // @2305_5f56f0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5f6669;  // @2306_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2307_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X1[0], 4);  // @2308_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2309_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2310_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2311_5f56f0
  goto L5f57f3;  // @2312_5f56f0
  L5f6c5a:;
  eax = (u32)(EBP - 124);  // @2314_5f56f0
  PV[104] = (u32)(eax);  // @2315_5f56f0
  ecx = (u32)(edi + 52);  // @2316_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[104]);  // @2317_5f56f0
  ecx = edx = 0;  // @2318_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2319_5f56f0
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2320_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2321_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6c92;  // @2322_5f56f0
  PV[105] = (u32)(esi);  // @2323_5f56f0
  ecx = edi;  // @2324_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[105]);  // @2325_5f56f0
  ecx = edx = 0;  // @2326_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2327_5f56f0
  X0[1] = 0;  // @2328_5f56f0
  X0[2] = 0;  // @2329_5f56f0
  X0[3] = 0;  // @2330_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; }))))))) goto L5f6669;  // @2331_5f56f0
  eax = (u32)(EBP - 124);  // @2332_5f56f0
  goto L5f6797;  // @2333_5f56f0
  L5f6c92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2335_5f56f0
  eax = esi;  // @2336_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2337_5f56f0
  X0[1] = 0;  // @2338_5f56f0
  X0[2] = 0;  // @2339_5f56f0
  X0[3] = 0;  // @2340_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; }))))))) goto L5f6669;  // @2341_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2342_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X0[0], 4);  // @2343_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2344_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2345_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2346_5f56f0
  goto L5f57f3;  // @2347_5f56f0
  L5f6cc0:;
  eax = (u32)(EBP - 124);  // @2349_5f56f0
  PV[106] = (u32)(eax);  // @2350_5f56f0
  ecx = (u32)(edi + 52);  // @2351_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[106]);  // @2352_5f56f0
  ecx = edx = 0;  // @2353_5f56f0
  ecx = (u32)(edi + 52);  // @2354_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2355_5f56f0
  edx = 0;  // @2356_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2357_5f56f0
  ecx = (eax & 0xffff);  // @2358_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @2359_5f56f0
  eax = (eax + (u32)(-64));  // @2360_5f56f0
  FL[3] = eax;  // @2361_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @2362_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6d6a;  // @2363_5f56f0
  FL[0] = eax; FL[1] = (u32)(6);  // @2364_5f56f0
  if (FL[0] > FL[1]) goto L5f57f0;  // @2365_5f56f0
  switch (eax) {  // @2366_5f56f0
  case 0: goto L5f6cf9;  // @2367_5f56f0
  case 1: goto L5f57e7;  // @2368_5f56f0
  case 2: goto L5f6d17;  // @2369_5f56f0
  case 3: goto L5f57e7;  // @2370_5f56f0
  case 4: goto L5f6d24;  // @2371_5f56f0
  case 5: goto L5f57e7;  // @2372_5f56f0
  case 6: goto L5f6d42;  // @2373_5f56f0
  default: __builtin_trap(); }  // @2374_5f56f0
  L5f6cf9:;
  eax = (u32)(EBP - 124);  // @2376_5f56f0
  L5f6cfc:;
  PV[107] = (u32)(eax);  // @2378_5f56f0
  PV[108] = (u32)(ecx);  // @2379_5f56f0
  ecx = edi;  // @2380_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[108]);  // @2381_5f56f0
  ecx = edx = 0;  // @2382_5f56f0
  ecx = eax;  // @2383_5f56f0
  eax = ext_5f3d40_thiscall2(ecx, PV[107]);  // @2384_5f56f0
  ecx = edx = 0;  // @2385_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2386_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2387_5f56f0
  goto L5f57f3;  // @2388_5f56f0
  L5f6d17:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2390_5f56f0
  FL[1] = eax;  // @2391_5f56f0
  eax = (0u - eax);  // @2392_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2393_5f56f0
  eax = (u32)(EBP - 108);  // @2394_5f56f0
  goto L5f6cfc;  // @2395_5f56f0
  L5f6d24:;
  eax = (u32)(EBP - 124);  // @2397_5f56f0
  PV[109] = (u32)(eax);  // @2398_5f56f0
  PV[110] = (u32)(ecx);  // @2399_5f56f0
  ecx = edi;  // @2400_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[110]);  // @2401_5f56f0
  ecx = edx = 0;  // @2402_5f56f0
  ecx = eax;  // @2403_5f56f0
  eax = ext_5f4e00_thiscall2(ecx, PV[109]);  // @2404_5f56f0
  ecx = edx = 0;  // @2405_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2406_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2407_5f56f0
  goto L5f57f3;  // @2408_5f56f0
  L5f6d42:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2410_5f56f0
  if (FL[0] == FL[1]) goto L5f6b75;  // @2411_5f56f0
  eax = (u32)(EBP - 124);  // @2412_5f56f0
  PV[111] = (u32)(eax);  // @2413_5f56f0
  PV[112] = (u32)(ecx);  // @2414_5f56f0
  ecx = edi;  // @2415_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[112]);  // @2416_5f56f0
  ecx = edx = 0;  // @2417_5f56f0
  ecx = eax;  // @2418_5f56f0
  eax = ext_5f40b0_thiscall2(ecx, PV[111]);  // @2419_5f56f0
  ecx = edx = 0;  // @2420_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2421_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2422_5f56f0
  goto L5f57f3;  // @2423_5f56f0
  L5f6d6a:;
  FL[0] = eax; FL[1] = (u32)(6);  // @2425_5f56f0
  if (FL[0] > FL[1]) goto L5f57f0;  // @2426_5f56f0
  switch (eax) {  // @2427_5f56f0
  case 0: goto L5f6d7a;  // @2428_5f56f0
  case 1: goto L5f57e7;  // @2429_5f56f0
  case 2: goto L5f6d93;  // @2430_5f56f0
  case 3: goto L5f57e7;  // @2431_5f56f0
  case 4: goto L5f6dac;  // @2432_5f56f0
  case 5: goto L5f57e7;  // @2433_5f56f0
  case 6: goto L5f6dc9;  // @2434_5f56f0
  default: __builtin_trap(); }  // @2435_5f56f0
  L5f6d7a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2437_5f56f0
  edx = ecx;  // @2438_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2439_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @2440_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @2441_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2442_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2443_5f56f0
  goto L5f57f3;  // @2444_5f56f0
  L5f6d93:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2446_5f56f0
  edx = ecx;  // @2447_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2448_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; }) - eax)); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @2449_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @2450_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2451_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2452_5f56f0
  goto L5f57f3;  // @2453_5f56f0
  L5f6dac:;
  edx = ecx;  // @2455_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2456_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @2457_5f56f0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }));  // @2458_5f56f0
  FL[3] = eax;  // @2459_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @2460_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2461_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2462_5f56f0
  goto L5f57f3;  // @2463_5f56f0
  L5f6dc9:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2465_5f56f0
  if (FL[0] == FL[1]) goto L5f6b75;  // @2466_5f56f0
  esi = ecx;  // @2467_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2468_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi), sizeof v); (u32)v; });  // @2469_5f56f0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @2470_5f56f0
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @2471_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2472_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + esi), &v, sizeof v); }  // @2473_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2474_5f56f0
  goto L5f57f3;  // @2475_5f56f0
  L5f6df0:;
  eax = (u32)(EBP - 124);  // @2477_5f56f0
  PV[113] = (u32)(eax);  // @2478_5f56f0
  ecx = (u32)(edi + 52);  // @2479_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[113]);  // @2480_5f56f0
  ecx = edx = 0;  // @2481_5f56f0
  ecx = (u32)(edi + 52);  // @2482_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2483_5f56f0
  edx = 0;  // @2484_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2485_5f56f0
  ecx = (eax & 0xffff);  // @2486_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @2487_5f56f0
  eax = (eax + (u32)(-65));  // @2488_5f56f0
  FL[3] = eax;  // @2489_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @2490_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6e99;  // @2491_5f56f0
  FL[0] = eax; FL[1] = (u32)(6);  // @2492_5f56f0
  if (FL[0] > FL[1]) goto L5f57f0;  // @2493_5f56f0
  switch (eax) {  // @2494_5f56f0
  case 0: goto L5f6e29;  // @2495_5f56f0
  case 1: goto L5f57e7;  // @2496_5f56f0
  case 2: goto L5f6e47;  // @2497_5f56f0
  case 3: goto L5f57e7;  // @2498_5f56f0
  case 4: goto L5f6e5d;  // @2499_5f56f0
  case 5: goto L5f57e7;  // @2500_5f56f0
  case 6: goto L5f6e7b;  // @2501_5f56f0
  default: __builtin_trap(); }  // @2502_5f56f0
  L5f6e29:;
  eax = (u32)(EBP - 124);  // @2504_5f56f0
  L5f6e2c:;
  PV[114] = (u32)(eax);  // @2506_5f56f0
  PV[115] = (u32)(ecx);  // @2507_5f56f0
  ecx = edi;  // @2508_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[115]);  // @2509_5f56f0
  ecx = edx = 0;  // @2510_5f56f0
  ecx = eax;  // @2511_5f56f0
  eax = ext_5f3db0_thiscall2(ecx, PV[114]);  // @2512_5f56f0
  ecx = edx = 0;  // @2513_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2514_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2515_5f56f0
  goto L5f57f3;  // @2516_5f56f0
  L5f6e47:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2518_5f56f0
  X0[1] = 0;  // @2519_5f56f0
  X0[2] = 0;  // @2520_5f56f0
  X0[3] = 0;  // @2521_5f56f0
  eax = (u32)(EBP - 108);  // @2522_5f56f0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @2523_5f56f0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @2524_5f56f0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @2525_5f56f0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @2526_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @2527_5f56f0
  goto L5f6e2c;  // @2528_5f56f0
  L5f6e5d:;
  eax = (u32)(EBP - 124);  // @2530_5f56f0
  PV[116] = (u32)(eax);  // @2531_5f56f0
  PV[117] = (u32)(ecx);  // @2532_5f56f0
  ecx = edi;  // @2533_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[117]);  // @2534_5f56f0
  ecx = edx = 0;  // @2535_5f56f0
  ecx = eax;  // @2536_5f56f0
  eax = ext_5f4e60_thiscall2(ecx, PV[116]);  // @2537_5f56f0
  ecx = edx = 0;  // @2538_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2539_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2540_5f56f0
  goto L5f57f3;  // @2541_5f56f0
  L5f6e7b:;
  eax = (u32)(EBP - 124);  // @2543_5f56f0
  PV[118] = (u32)(eax);  // @2544_5f56f0
  PV[119] = (u32)(ecx);  // @2545_5f56f0
  ecx = edi;  // @2546_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[119]);  // @2547_5f56f0
  ecx = edx = 0;  // @2548_5f56f0
  ecx = eax;  // @2549_5f56f0
  eax = ext_5f4110_thiscall2(ecx, PV[118]);  // @2550_5f56f0
  ecx = edx = 0;  // @2551_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2552_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2553_5f56f0
  goto L5f57f3;  // @2554_5f56f0
  L5f6e99:;
  FL[0] = eax; FL[1] = (u32)(6);  // @2556_5f56f0
  if (FL[0] > FL[1]) goto L5f57f0;  // @2557_5f56f0
  switch (eax) {  // @2558_5f56f0
  case 0: goto L5f6ea9;  // @2559_5f56f0
  case 1: goto L5f57e7;  // @2560_5f56f0
  case 2: goto L5f6ec9;  // @2561_5f56f0
  case 3: goto L5f57e7;  // @2562_5f56f0
  case 4: goto L5f6ee9;  // @2563_5f56f0
  case 5: goto L5f57e7;  // @2564_5f56f0
  case 6: goto L5f6f09;  // @2565_5f56f0
  default: __builtin_trap(); }  // @2566_5f56f0
  L5f6ea9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2568_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2569_5f56f0
  X0[1] = 0;  // @2570_5f56f0
  X0[2] = 0;  // @2571_5f56f0
  X0[3] = 0;  // @2572_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2573_5f56f0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; })));  // @2574_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @2575_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2576_5f56f0
  goto L5f57f3;  // @2577_5f56f0
  L5f6ec9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2579_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2580_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @2581_5f56f0
  X0[1] = 0;  // @2582_5f56f0
  X0[2] = 0;  // @2583_5f56f0
  X0[3] = 0;  // @2584_5f56f0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })));  // @2585_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @2586_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2587_5f56f0
  goto L5f57f3;  // @2588_5f56f0
  L5f6ee9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2590_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2591_5f56f0
  X0[1] = 0;  // @2592_5f56f0
  X0[2] = 0;  // @2593_5f56f0
  X0[3] = 0;  // @2594_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2595_5f56f0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; })));  // @2596_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @2597_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2598_5f56f0
  goto L5f57f3;  // @2599_5f56f0
  L5f6f09:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2601_5f56f0
  X1[1] = 0;  // @2602_5f56f0
  X1[2] = 0;  // @2603_5f56f0
  X1[3] = 0;  // @2604_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @2605_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @2606_5f56f0
  if (__builtin_parity(FL[2] & 0xff)) goto L5f6b75;  // @2607_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2608_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2609_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @2610_5f56f0
  X0[1] = 0;  // @2611_5f56f0
  X0[2] = 0;  // @2612_5f56f0
  X0[3] = 0;  // @2613_5f56f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @2614_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @2615_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2616_5f56f0
  goto L5f57f3;  // @2617_5f56f0
  L5f6f3e:;
  eax = (u32)(EBP - 124);  // @2619_5f56f0
  PV[120] = (u32)(eax);  // @2620_5f56f0
  ecx = (u32)(edi + 52);  // @2621_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[120]);  // @2622_5f56f0
  ecx = edx = 0;  // @2623_5f56f0
  ecx = (u32)(edi + 52);  // @2624_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2625_5f56f0
  edx = 0;  // @2626_5f56f0
  esi = (eax & 0xffff);  // @2627_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2628_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6f94;  // @2629_5f56f0
  PV[121] = (u32)(esi);  // @2630_5f56f0
  ecx = edi;  // @2631_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[121]);  // @2632_5f56f0
  ecx = edx = 0;  // @2633_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @2634_5f56f0
  X0[1] = 0;  // @2635_5f56f0
  X0[2] = 0;  // @2636_5f56f0
  X0[3] = 0;  // @2637_5f56f0
  L5f6f6a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2639_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2640_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))))))) goto L5f57f3;  // @2641_5f56f0
  eax = (u32)(EBP - 124);  // @2642_5f56f0
  PV[122] = (u32)(eax);  // @2643_5f56f0
  PV[123] = (u32)(esi);  // @2644_5f56f0
  L5f6f7b:;
  ecx = edi;  // @2646_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[123]);  // @2647_5f56f0
  ecx = edx = 0;  // @2648_5f56f0
  ecx = eax;  // @2649_5f56f0
  eax = ext_602cd0_thiscall2(ecx, PV[122]);  // @2650_5f56f0
  ecx = edx = 0;  // @2651_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2652_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2653_5f56f0
  goto L5f57f3;  // @2654_5f56f0
  L5f6f94:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2656_5f56f0
  eax = esi;  // @2657_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2658_5f56f0
  X1[1] = 0;  // @2659_5f56f0
  X1[2] = 0;  // @2660_5f56f0
  X1[3] = 0;  // @2661_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2662_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; });  // @2663_5f56f0
  X0[1] = 0;  // @2664_5f56f0
  X0[2] = 0;  // @2665_5f56f0
  X0[3] = 0;  // @2666_5f56f0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5f57f0;  // @2667_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X1[0], 4);  // @2668_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2669_5f56f0
  goto L5f57f3;  // @2670_5f56f0
  L5f6fbf:;
  eax = (u32)(EBP - 124);  // @2672_5f56f0
  PV[124] = (u32)(eax);  // @2673_5f56f0
  ecx = (u32)(edi + 52);  // @2674_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[124]);  // @2675_5f56f0
  ecx = edx = 0;  // @2676_5f56f0
  ecx = (u32)(edi + 52);  // @2677_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2678_5f56f0
  edx = 0;  // @2679_5f56f0
  esi = (eax & 0xffff);  // @2680_5f56f0
  FL[2] = ((esi & 0xffff) & (esi & 0xffff));  // @2681_5f56f0
  if ((s32)FL[2] >= 0) goto L5f6ff0;  // @2682_5f56f0
  PV[125] = (u32)(esi);  // @2683_5f56f0
  ecx = edi;  // @2684_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[125]);  // @2685_5f56f0
  ecx = edx = 0;  // @2686_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2687_5f56f0
  X0[1] = 0;  // @2688_5f56f0
  X0[2] = 0;  // @2689_5f56f0
  X0[3] = 0;  // @2690_5f56f0
  goto L5f6f6a;  // @2691_5f56f0
  L5f6ff0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2693_5f56f0
  eax = esi;  // @2694_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2695_5f56f0
  X0[1] = 0;  // @2696_5f56f0
  X0[2] = 0;  // @2697_5f56f0
  X0[3] = 0;  // @2698_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2699_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; }))))))) goto L5f57f0;  // @2700_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X0[0], 4);  // @2701_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2702_5f56f0
  goto L5f57f3;  // @2703_5f56f0
  L5f7017:;
  eax = (u32)(esi + 2);  // @2705_5f56f0
  PV[126] = (u32)(eax);  // @2706_5f56f0
  ecx = (u32)(edi + 64);  // @2707_5f56f0
  eax = ext_5f53f0_thiscall2(ecx, PV[126]);  // @2708_5f56f0
  ecx = edx = 0;  // @2709_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2710_5f56f0
  ecx = edi;  // @2711_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2712_5f56f0
  PV[127] = (u32)(eax);  // @2713_5f56f0
  eax = ext_5f5680_thiscall2(ecx, PV[127]);  // @2714_5f56f0
  ecx = edx = 0;  // @2715_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2716_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2717_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2718_5f56f0
  goto L5f57f3;  // @2719_5f56f0
  L5f7045:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2721_5f56f0
  ecx = (u32)(edi + 52);  // @2722_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2723_5f56f0
  eax = (u32)(EBP - 108);  // @2724_5f56f0
  PV[128] = (u32)(eax);  // @2725_5f56f0
  eax = ext_5f4fb0_thiscall2(ecx, PV[128]);  // @2726_5f56f0
  ecx = edx = 0;  // @2727_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2728_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2729_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2730_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2731_5f56f0
  goto L5f57f3;  // @2732_5f56f0
  L5f7068:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2734_5f56f0
  ecx = (u32)(edi + 52);  // @2735_5f56f0
  if (FL[0] == FL[1]) goto L5f7078;  // @2736_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2737_5f56f0
  edx = 0;  // @2738_5f56f0
  goto L5f7081;  // @2739_5f56f0
  L5f7078:;
  eax = ext_5f4ec0_thiscall2(ecx, (u32)(0));  // @2741_5f56f0
  ecx = edx = 0;  // @2742_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2743_5f56f0
  L5f7081:;
  FL[2] = (eax & eax);  // @2745_5f56f0
  if (FL[2] == 0) goto L5f70a5;  // @2746_5f56f0
  L5f7085:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2748_5f56f0
  PV[129] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2749_5f56f0
  L5f708d:;
  ecx = edi;  // @2751_5f56f0
  eax = ext_5f5620_thiscall2(ecx, PV[129]);  // @2752_5f56f0
  ecx = edx = 0;  // @2753_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2754_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2755_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2756_5f56f0
  goto L5f57f3;  // @2757_5f56f0
  L5f70a5:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(8))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2759_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2760_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2761_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2762_5f56f0
  goto L5f57f3;  // @2763_5f56f0
  L5f70b7:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2765_5f56f0
  ecx = (u32)(edi + 52);  // @2766_5f56f0
  if (FL[0] == FL[1]) goto L5f70c7;  // @2767_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2768_5f56f0
  edx = 0;  // @2769_5f56f0
  goto L5f70d0;  // @2770_5f56f0
  L5f70c7:;
  eax = ext_5f4ec0_thiscall2(ecx, (u32)(0));  // @2772_5f56f0
  ecx = edx = 0;  // @2773_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @2774_5f56f0
  L5f70d0:;
  FL[2] = (eax & eax);  // @2776_5f56f0
  if (FL[2] != 0) goto L5f70a5;  // @2777_5f56f0
  goto L5f7085;  // @2778_5f56f0
  L5f70d6:;
  ecx = (u32)(edi + 52);  // @2780_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2781_5f56f0
  edx = 0;  // @2782_5f56f0
  FL[2] = (eax & eax);  // @2783_5f56f0
  if (FL[2] == 0) goto L5f8acf;  // @2784_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2785_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2786_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2787_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2788_5f56f0
  goto L5f57f3;  // @2789_5f56f0
  L5f70f8:;
  PV[130] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2791_5f56f0
  L5f70fc:;
  ecx = edi;  // @2793_5f56f0
  eax = ext_5f9130_thiscall3(ecx, PV[130], (u32)(1));  // @2794_5f56f0
  ecx = edx = 0;  // @2795_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2796_5f56f0
  eax = (u32)(34816);  // @2797_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2798_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @2799_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @2800_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2801_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2802_5f56f0
  goto L5f57f3;  // @2803_5f56f0
  L5f7127:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @2805_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2806_5f56f0
  PV[131] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @2807_5f56f0
  goto L5f70fc;  // @2808_5f56f0
  L5f7136:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2810_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @2811_5f56f0
  PV[132] = (u32)(eax);  // @2812_5f56f0
  eax = ext_5f4a80_thiscall2(ecx, PV[132]);  // @2813_5f56f0
  ecx = edx = 0;  // @2814_5f56f0
  PV[133] = (u32)(eax);  // @2815_5f56f0
  ecx = edi;  // @2816_5f56f0
  eax = ext_5f9130_thiscall3(ecx, PV[133], (u32)(1));  // @2817_5f56f0
  ecx = edx = 0;  // @2818_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @2819_5f56f0
  eax = (u32)(34816);  // @2820_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @2821_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @2822_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @2823_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @2824_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @2825_5f56f0
  goto L5f57f3;  // @2826_5f56f0
  L5f7173:;
  eax = (u32)(EBP - 124);  // @2828_5f56f0
  PV[134] = (u32)(eax);  // @2829_5f56f0
  ecx = (u32)(edi + 52);  // @2830_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[134]);  // @2831_5f56f0
  ecx = edx = 0;  // @2832_5f56f0
  ecx = (u32)(edi + 52);  // @2833_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2834_5f56f0
  edx = 0;  // @2835_5f56f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2836_5f56f0
  if ((s32)FL[0] >= (s32)FL[1]) goto L5f599e;  // @2837_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2838_5f56f0
  goto L5f5936;  // @2839_5f56f0
  L5f719c:;
  eax = (u32)(EBP - 124);  // @2841_5f56f0
  PV[135] = (u32)(eax);  // @2842_5f56f0
  ecx = (u32)(edi + 52);  // @2843_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[135]);  // @2844_5f56f0
  ecx = edx = 0;  // @2845_5f56f0
  ecx = (u32)(edi + 52);  // @2846_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2847_5f56f0
  edx = 0;  // @2848_5f56f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2849_5f56f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5f599e;  // @2850_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2851_5f56f0
  goto L5f5936;  // @2852_5f56f0
  L5f71c5:;
  eax = (u32)(EBP - 124);  // @2854_5f56f0
  PV[136] = (u32)(eax);  // @2855_5f56f0
  ecx = (u32)(edi + 52);  // @2856_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[136]);  // @2857_5f56f0
  ecx = edx = 0;  // @2858_5f56f0
  ecx = (u32)(edi + 52);  // @2859_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2860_5f56f0
  edx = 0;  // @2861_5f56f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2862_5f56f0
  if ((s32)FL[0] > (s32)FL[1]) goto L5f599e;  // @2863_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2864_5f56f0
  goto L5f5936;  // @2865_5f56f0
  L5f71ee:;
  eax = (u32)(EBP - 124);  // @2867_5f56f0
  PV[137] = (u32)(eax);  // @2868_5f56f0
  ecx = (u32)(edi + 52);  // @2869_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[137]);  // @2870_5f56f0
  ecx = edx = 0;  // @2871_5f56f0
  ecx = (u32)(edi + 52);  // @2872_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2873_5f56f0
  edx = 0;  // @2874_5f56f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2875_5f56f0
  if ((s32)FL[0] < (s32)FL[1]) goto L5f599e;  // @2876_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2877_5f56f0
  goto L5f5936;  // @2878_5f56f0
  L5f7217:;
  eax = (u32)(EBP - 124);  // @2880_5f56f0
  PV[138] = (u32)(eax);  // @2881_5f56f0
  ecx = (u32)(edi + 52);  // @2882_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[138]);  // @2883_5f56f0
  ecx = edx = 0;  // @2884_5f56f0
  ecx = (u32)(edi + 52);  // @2885_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2886_5f56f0
  edx = 0;  // @2887_5f56f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2888_5f56f0
  if (FL[0] != FL[1]) goto L5f599e;  // @2889_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2890_5f56f0
  goto L5f5936;  // @2891_5f56f0
  L5f7240:;
  eax = (u32)(EBP - 124);  // @2893_5f56f0
  PV[139] = (u32)(eax);  // @2894_5f56f0
  ecx = (u32)(edi + 52);  // @2895_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[139]);  // @2896_5f56f0
  ecx = edx = 0;  // @2897_5f56f0
  ecx = (u32)(edi + 52);  // @2898_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @2899_5f56f0
  edx = 0;  // @2900_5f56f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @2901_5f56f0
  if (FL[0] == FL[1]) goto L5f599e;  // @2902_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2903_5f56f0
  goto L5f5936;  // @2904_5f56f0
  L5f7269:;
  eax = (u32)(EBP - 124);  // @2906_5f56f0
  PV[140] = (u32)(eax);  // @2907_5f56f0
  ecx = (u32)(edi + 52);  // @2908_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[140]);  // @2909_5f56f0
  ecx = edx = 0;  // @2910_5f56f0
  ecx = (u32)(edi + 52);  // @2911_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2912_5f56f0
  edx = 0;  // @2913_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2914_5f56f0
  X0[1] = 0;  // @2915_5f56f0
  X0[2] = 0;  // @2916_5f56f0
  X0[3] = 0;  // @2917_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @2918_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; }))))))) goto L5f599e;  // @2919_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2920_5f56f0
  goto L5f5936;  // @2921_5f56f0
  L5f729b:;
  eax = (u32)(EBP - 124);  // @2923_5f56f0
  PV[141] = (u32)(eax);  // @2924_5f56f0
  ecx = (u32)(edi + 52);  // @2925_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[141]);  // @2926_5f56f0
  ecx = edx = 0;  // @2927_5f56f0
  ecx = (u32)(edi + 52);  // @2928_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2929_5f56f0
  edx = 0;  // @2930_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @2931_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @2932_5f56f0
  X0[1] = 0;  // @2933_5f56f0
  X0[2] = 0;  // @2934_5f56f0
  X0[3] = 0;  // @2935_5f56f0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))))))) goto L5f599e;  // @2936_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2937_5f56f0
  goto L5f5936;  // @2938_5f56f0
  L5f72cd:;
  eax = (u32)(EBP - 124);  // @2940_5f56f0
  PV[142] = (u32)(eax);  // @2941_5f56f0
  ecx = (u32)(edi + 52);  // @2942_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[142]);  // @2943_5f56f0
  ecx = edx = 0;  // @2944_5f56f0
  ecx = (u32)(edi + 52);  // @2945_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2946_5f56f0
  edx = 0;  // @2947_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @2948_5f56f0
  X0[1] = 0;  // @2949_5f56f0
  X0[2] = 0;  // @2950_5f56f0
  X0[3] = 0;  // @2951_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @2952_5f56f0
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; }))))) goto L5f599e;  // @2953_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2954_5f56f0
  goto L5f5936;  // @2955_5f56f0
  L5f72ff:;
  eax = (u32)(EBP - 124);  // @2957_5f56f0
  PV[143] = (u32)(eax);  // @2958_5f56f0
  ecx = (u32)(edi + 52);  // @2959_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[143]);  // @2960_5f56f0
  ecx = edx = 0;  // @2961_5f56f0
  ecx = (u32)(edi + 52);  // @2962_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2963_5f56f0
  edx = 0;  // @2964_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @2965_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @2966_5f56f0
  X0[1] = 0;  // @2967_5f56f0
  X0[2] = 0;  // @2968_5f56f0
  X0[3] = 0;  // @2969_5f56f0
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))))) goto L5f599e;  // @2970_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2971_5f56f0
  goto L5f5936;  // @2972_5f56f0
  L5f7331:;
  eax = (u32)(EBP - 124);  // @2974_5f56f0
  PV[144] = (u32)(eax);  // @2975_5f56f0
  ecx = (u32)(edi + 52);  // @2976_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[144]);  // @2977_5f56f0
  ecx = edx = 0;  // @2978_5f56f0
  ecx = (u32)(edi + 52);  // @2979_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2980_5f56f0
  edx = 0;  // @2981_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @2982_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @2983_5f56f0
  X0[1] = 0;  // @2984_5f56f0
  X0[2] = 0;  // @2985_5f56f0
  X0[3] = 0;  // @2986_5f56f0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @2987_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @2988_5f56f0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5f599e;  // @2989_5f56f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @2990_5f56f0
  goto L5f5936;  // @2991_5f56f0
  L5f7367:;
  eax = (u32)(EBP - 124);  // @2993_5f56f0
  PV[145] = (u32)(eax);  // @2994_5f56f0
  ecx = (u32)(edi + 52);  // @2995_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[145]);  // @2996_5f56f0
  ecx = edx = 0;  // @2997_5f56f0
  ecx = (u32)(edi + 52);  // @2998_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @2999_5f56f0
  edx = 0;  // @3000_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @3001_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @3002_5f56f0
  X0[1] = 0;  // @3003_5f56f0
  X0[2] = 0;  // @3004_5f56f0
  X0[3] = 0;  // @3005_5f56f0
  goto L5f5a19;  // @3006_5f56f0
  L5f738c:;
  ecx = (u32)(edi + 52);  // @3008_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @3009_5f56f0
  edx = 0;  // @3010_5f56f0
  ecx = (eax & 0xffff);  // @3011_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @3012_5f56f0
  if ((s32)FL[2] >= 0) goto L5f73cc;  // @3013_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3014_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3015_5f56f0
  L5f73a4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3017_5f56f0
  eax = (u32)(EBP - 108);  // @3018_5f56f0
  L5f73aa:;
  PV[146] = (u32)(eax);  // @3020_5f56f0
  PV[147] = (u32)(ecx);  // @3021_5f56f0
  ecx = edi;  // @3022_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[147]);  // @3023_5f56f0
  ecx = edx = 0;  // @3024_5f56f0
  ecx = eax;  // @3025_5f56f0
  eax = ext_50d7b0_thiscall2(ecx, PV[146]);  // @3026_5f56f0
  ecx = edx = 0;  // @3027_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3028_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3029_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3030_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3031_5f56f0
  goto L5f57f3;  // @3032_5f56f0
  L5f73cc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3034_5f56f0
  edx = ecx;  // @3035_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3036_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3037_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @3038_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3039_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3040_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3041_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3042_5f56f0
  goto L5f57f3;  // @3043_5f56f0
  L5f73f1:;
  ecx = (u32)(edi + 52);  // @3045_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @3046_5f56f0
  edx = 0;  // @3047_5f56f0
  ecx = (eax & 0xffff);  // @3048_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @3049_5f56f0
  if ((s32)FL[2] >= 0) goto L5f73cc;  // @3050_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3051_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @3052_5f56f0
  X0[1] = 0;  // @3053_5f56f0
  X0[2] = 0;  // @3054_5f56f0
  X0[3] = 0;  // @3055_5f56f0
  eax = (u32)(EBP - 108);  // @3056_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @3057_5f56f0
  L5f7413:;
  PV[148] = (u32)(eax);  // @3059_5f56f0
  PV[149] = (u32)(ecx);  // @3060_5f56f0
  ecx = edi;  // @3061_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[149]);  // @3062_5f56f0
  ecx = edx = 0;  // @3063_5f56f0
  ecx = eax;  // @3064_5f56f0
  eax = ext_602cd0_thiscall2(ecx, PV[148]);  // @3065_5f56f0
  ecx = edx = 0;  // @3066_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3067_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3068_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3069_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3070_5f56f0
  goto L5f57f3;  // @3071_5f56f0
  L5f7435:;
  eax = (u32)(EBP - 124);  // @3073_5f56f0
  PV[150] = (u32)(eax);  // @3074_5f56f0
  ecx = (u32)(edi + 52);  // @3075_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[150]);  // @3076_5f56f0
  ecx = edx = 0;  // @3077_5f56f0
  ecx = (u32)(edi + 52);  // @3078_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @3079_5f56f0
  edx = 0;  // @3080_5f56f0
  eax = (eax & 0xffff);  // @3081_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @3082_5f56f0
  if ((s32)FL[2] >= 0) goto L5f746f;  // @3083_5f56f0
  ecx = (u32)(EBP - 124);  // @3084_5f56f0
  PV[151] = (u32)(ecx);  // @3085_5f56f0
  PV[152] = (u32)(eax);  // @3086_5f56f0
  ecx = edi;  // @3087_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[152]);  // @3088_5f56f0
  ecx = edx = 0;  // @3089_5f56f0
  ecx = eax;  // @3090_5f56f0
  eax = ext_50d7b0_thiscall2(ecx, PV[151]);  // @3091_5f56f0
  ecx = edx = 0;  // @3092_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3093_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3094_5f56f0
  goto L5f57f3;  // @3095_5f56f0
  L5f746f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3097_5f56f0
  edx = eax;  // @3098_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @3099_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @3100_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3101_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3102_5f56f0
  goto L5f57f3;  // @3103_5f56f0
  L5f7488:;
  eax = (u32)(EBP - 124);  // @3105_5f56f0
  PV[153] = (u32)(eax);  // @3106_5f56f0
  ecx = (u32)(edi + 52);  // @3107_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[153]);  // @3108_5f56f0
  ecx = edx = 0;  // @3109_5f56f0
  ecx = (u32)(edi + 52);  // @3110_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @3111_5f56f0
  edx = 0;  // @3112_5f56f0
  eax = (eax & 0xffff);  // @3113_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @3114_5f56f0
  if ((s32)FL[2] >= 0) goto L5f74ae;  // @3115_5f56f0
  ecx = (u32)(EBP - 124);  // @3116_5f56f0
  PV[154] = (u32)(ecx);  // @3117_5f56f0
  PV[155] = (u32)(eax);  // @3118_5f56f0
  goto L5f6f7b;  // @3119_5f56f0
  L5f74ae:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @3121_5f56f0
  X0[1] = 0;  // @3122_5f56f0
  X0[2] = 0;  // @3123_5f56f0
  X0[3] = 0;  // @3124_5f56f0
  ecx = eax;  // @3125_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3126_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3127_5f56f0
  __builtin_memcpy((void *)((u32)(ecx + eax) + 0), &X0[0], 4);  // @3128_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3129_5f56f0
  goto L5f57f3;  // @3130_5f56f0
  L5f74cb:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3132_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @3133_5f56f0
  if ((s32)FL[2] >= 0) goto L5f7502;  // @3134_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 2) + 0), 4); v; });  // @3135_5f56f0
  X0[1] = 0;  // @3136_5f56f0
  X0[2] = 0;  // @3137_5f56f0
  X0[3] = 0;  // @3138_5f56f0
  ecx = (u32)(EBP - 108);  // @3139_5f56f0
  PV[156] = (u32)(ecx);  // @3140_5f56f0
  PV[157] = (u32)(eax);  // @3141_5f56f0
  ecx = edi;  // @3142_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @3143_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[157]);  // @3144_5f56f0
  ecx = edx = 0;  // @3145_5f56f0
  ecx = eax;  // @3146_5f56f0
  eax = ext_602cd0_thiscall2(ecx, PV[156]);  // @3147_5f56f0
  ecx = edx = 0;  // @3148_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3149_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3150_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3151_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3152_5f56f0
  goto L5f57f3;  // @3153_5f56f0
  L5f7502:;
  edx = eax;  // @3155_5f56f0
  L5f7504:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3157_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @3158_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @3159_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3160_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3161_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3162_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3163_5f56f0
  goto L5f57f3;  // @3164_5f56f0
  L5f7522:;
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3166_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @3167_5f56f0
  if ((s32)FL[2] >= 0) goto L5f7555;  // @3168_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @3169_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3170_5f56f0
  eax = (u32)(EBP - 108);  // @3171_5f56f0
  PV[158] = (u32)(eax);  // @3172_5f56f0
  PV[159] = (u32)(ecx);  // @3173_5f56f0
  ecx = edi;  // @3174_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[159]);  // @3175_5f56f0
  ecx = edx = 0;  // @3176_5f56f0
  ecx = eax;  // @3177_5f56f0
  eax = ext_50d7b0_thiscall2(ecx, PV[158]);  // @3178_5f56f0
  ecx = edx = 0;  // @3179_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3180_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3181_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3182_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3183_5f56f0
  goto L5f57f3;  // @3184_5f56f0
  L5f7555:;
  edx = ecx;  // @3186_5f56f0
  goto L5f7504;  // @3187_5f56f0
  L5f7559:;
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3189_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @3190_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @3191_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @3192_5f56f0
  if ((s32)FL[2] >= 0) goto L5f7588;  // @3193_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @3194_5f56f0
  if ((s32)FL[2] >= 0) goto L5f757d;  // @3195_5f56f0
  PV[160] = (u32)(eax);  // @3196_5f56f0
  ecx = edi;  // @3197_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[160]);  // @3198_5f56f0
  ecx = edx = 0;  // @3199_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3200_5f56f0
  goto L5f7413;  // @3201_5f56f0
  L5f757d:;
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; }));  // @3203_5f56f0
  FL[3] = eax;  // @3204_5f56f0
  goto L5f7413;  // @3205_5f56f0
  L5f7588:;
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @3207_5f56f0
  if ((s32)FL[2] >= 0) goto L5f75b8;  // @3208_5f56f0
  PV[161] = (u32)(eax);  // @3209_5f56f0
  ecx = edi;  // @3210_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[161]);  // @3211_5f56f0
  ecx = edx = 0;  // @3212_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3213_5f56f0
  edx = (ecx & 0xffff);  // @3214_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3215_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3216_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @3217_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3218_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3219_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3220_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3221_5f56f0
  goto L5f57f3;  // @3222_5f56f0
  L5f75b8:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3224_5f56f0
  ecx = (ecx & 0xffff);  // @3225_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; });  // @3226_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @3227_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3228_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3229_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3230_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3231_5f56f0
  goto L5f57f3;  // @3232_5f56f0
  L5f75d9:;
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3234_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @3235_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @3236_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @3237_5f56f0
  if ((s32)FL[2] >= 0) goto L5f7588;  // @3238_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @3239_5f56f0
  if ((s32)FL[2] >= 0) goto L5f7604;  // @3240_5f56f0
  PV[162] = (u32)(eax);  // @3241_5f56f0
  ecx = edi;  // @3242_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[162]);  // @3243_5f56f0
  ecx = edx = 0;  // @3244_5f56f0
  ecx = eax;  // @3245_5f56f0
  eax = ext_5f3c40_thiscall1(ecx);  // @3246_5f56f0
  ecx = edx = 0;  // @3247_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3248_5f56f0
  goto L5f73a4;  // @3249_5f56f0
  L5f7604:;
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; }));  // @3251_5f56f0
  FL[3] = eax;  // @3252_5f56f0
  goto L5f73aa;  // @3253_5f56f0
  L5f760f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @3255_5f56f0
  FL[2] = (eax & eax);  // @3256_5f56f0
  if (FL[2] == 0) goto L5f7625;  // @3257_5f56f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[131], (u32)(1));  // @3258_5f56f0
  ecx = edx = 0;  // @3259_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3260_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3261_5f56f0
  goto L5f57f3;  // @3262_5f56f0
  L5f7625:;
  __builtin_trap();  // @3264_5f56f0
  L5f7631:;
  ecx = (u32)(edi + 52);  // @3266_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @3267_5f56f0
  edx = 0;  // @3268_5f56f0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @3269_5f56f0
  X0[0] = F2U((float)(s32)X0[0]);  // @3270_5f56f0
  X0[1] = F2U((float)(s32)X0[1]);  // @3271_5f56f0
  X0[2] = F2U((float)(s32)X0[2]);  // @3272_5f56f0
  X0[3] = F2U((float)(s32)X0[3]);  // @3273_5f56f0
  goto L5f6596;  // @3274_5f56f0
  L5f7645:;
  eax = (u32)(EBP - 124);  // @3276_5f56f0
  PV[163] = (u32)(eax);  // @3277_5f56f0
  ecx = (u32)(edi + 52);  // @3278_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[163]);  // @3279_5f56f0
  ecx = edx = 0;  // @3280_5f56f0
  eax = (u32)(EBP - 176);  // @3281_5f56f0
  PV[164] = (u32)(eax);  // @3282_5f56f0
  ecx = (u32)(edi + 52);  // @3283_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[164]);  // @3284_5f56f0
  ecx = edx = 0;  // @3285_5f56f0
  eax = (u32)(EBP - 124);  // @3286_5f56f0
  PV[165] = (u32)(eax);  // @3287_5f56f0
  ecx = (u32)(edi + 52);  // @3288_5f56f0
  eax = ext_5f51e0_thiscall2(ecx, PV[165]);  // @3289_5f56f0
  ecx = edx = 0;  // @3290_5f56f0
  eax = (u32)(EBP - 176);  // @3291_5f56f0
  PV[166] = (u32)(eax);  // @3292_5f56f0
  ecx = (u32)(edi + 52);  // @3293_5f56f0
  eax = ext_5f51e0_thiscall2(ecx, PV[166]);  // @3294_5f56f0
  ecx = edx = 0;  // @3295_5f56f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @3296_5f56f0
  if (FL[0] != FL[1]) goto L5f7689;  // @3297_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @3298_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3299_5f56f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[131], (u32)(1));  // @3300_5f56f0
  ecx = edx = 0;  // @3301_5f56f0
  L5f7689:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @3303_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @3304_5f56f0
  if (FL[0] != FL[1]) goto L5f76a1;  // @3305_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @3306_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3307_5f56f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @3308_5f56f0
  ecx = edx = 0;  // @3309_5f56f0
  L5f76a1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3311_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3312_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @3313_5f56f0
  goto L5f57f3;  // @3314_5f56f0
  L5f76b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3316_5f56f0
  ecx = (u32)(edi + 52);  // @3317_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @3318_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @3319_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3320_5f56f0
  eax = (u32)(esi + 8);  // @3321_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3322_5f56f0
  eax = (u32)(EBP - 124);  // @3323_5f56f0
  PV[167] = (u32)(eax);  // @3324_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[167]);  // @3325_5f56f0
  ecx = edx = 0;  // @3326_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3327_5f56f0
  esi = 0;  // @3328_5f56f0
  FL[3] = esi;  // @3329_5f56f0
  FL[2] = (ecx & ecx);  // @3330_5f56f0
  if ((s32)FL[2] <= 0) goto L5f7719;  // @3331_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @3332_5f56f0
  L5f76e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3334_5f56f0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3335_5f56f0
  if (FL[0] == FL[1]) goto L5f76fa;  // @3336_5f56f0
  esi = (esi + 1);  // @3337_5f56f0
  FL[3] = esi;  // @3338_5f56f0
  eax = (eax + (u32)(8));  // @3339_5f56f0
  FL[3] = eax;  // @3340_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3341_5f56f0
  FL[0] = esi; FL[1] = ecx;  // @3342_5f56f0
  if ((s32)FL[0] < (s32)FL[1]) goto L5f76e0;  // @3343_5f56f0
  goto L5f7719;  // @3344_5f56f0
  L5f76fa:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3346_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3347_5f56f0
  ecx = edi;  // @3348_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3349_5f56f0
  PV[168] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3350_5f56f0
  eax = ext_5f5620_thiscall2(ecx, PV[168]);  // @3351_5f56f0
  ecx = edx = 0;  // @3352_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3353_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3354_5f56f0
  L5f7719:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @3356_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3357_5f56f0
  FL[0] = eax; FL[1] = (u32)(-1);  // @3358_5f56f0
  if (FL[0] == FL[1]) goto L5f57f0;  // @3359_5f56f0
  FL[0] = esi; FL[1] = ecx;  // @3360_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3361_5f56f0
  if ((s32)FL[0] < (s32)FL[1]) goto L5f57f3;  // @3362_5f56f0
  PV[169] = (u32)(eax);  // @3363_5f56f0
  goto L5f708d;  // @3364_5f56f0
  L5f7739:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3366_5f56f0
  ecx = (u32)(edi + 52);  // @3367_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @3368_5f56f0
  eax = (u32)(esi + 8);  // @3369_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3370_5f56f0
  eax = (u32)(EBP - 124);  // @3371_5f56f0
  PV[170] = (u32)(eax);  // @3372_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[170]);  // @3373_5f56f0
  ecx = edx = 0;  // @3374_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3375_5f56f0
  esi = 0;  // @3376_5f56f0
  FL[3] = esi;  // @3377_5f56f0
  FL[2] = (ecx & ecx);  // @3378_5f56f0
  if ((s32)FL[2] <= 0) goto L5f779f;  // @3379_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @3380_5f56f0
  X1[1] = 0;  // @3381_5f56f0
  X1[2] = 0;  // @3382_5f56f0
  X1[3] = 0;  // @3383_5f56f0
  L5f7761:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3385_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @3386_5f56f0
  X0[1] = 0;  // @3387_5f56f0
  X0[2] = 0;  // @3388_5f56f0
  X0[3] = 0;  // @3389_5f56f0
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5f7780;  // @3390_5f56f0
  esi = (esi + 1);  // @3391_5f56f0
  FL[3] = esi;  // @3392_5f56f0
  eax = (eax + (u32)(8));  // @3393_5f56f0
  FL[3] = eax;  // @3394_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3395_5f56f0
  FL[0] = esi; FL[1] = ecx;  // @3396_5f56f0
  if ((s32)FL[0] < (s32)FL[1]) goto L5f7761;  // @3397_5f56f0
  goto L5f779f;  // @3398_5f56f0
  L5f7780:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3400_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3401_5f56f0
  ecx = edi;  // @3402_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3403_5f56f0
  PV[171] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3404_5f56f0
  eax = ext_5f5620_thiscall2(ecx, PV[171]);  // @3405_5f56f0
  ecx = edx = 0;  // @3406_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3407_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3408_5f56f0
  L5f779f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3410_5f56f0
  FL[0] = esi; FL[1] = ecx;  // @3411_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3412_5f56f0
  if (FL[0] != FL[1]) goto L5f57f3;  // @3413_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(-4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3414_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3415_5f56f0
  goto L5f7085;  // @3416_5f56f0
  L5f77b9:;
  eax = (u32)(34816);  // @3418_5f56f0
  ecx = (u32)(edi + 52);  // @3419_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @3420_5f56f0
  if (FL[2] != 0) goto L5f7825;  // @3421_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @3422_5f56f0
  edx = 0;  // @3423_5f56f0
  FL[2] = (eax & eax);  // @3424_5f56f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xffff);  // @3425_5f56f0
  if (FL[2] == 0) goto L5f77ef;  // @3426_5f56f0
  ecx = (u32)(65522);  // @3427_5f56f0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 141), &v, sizeof v); }  // @3428_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @3429_5f56f0
  FL[3] = (eax & 0xffff);  // @3430_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(2))) & 0xffff);  // @3431_5f56f0
  FL[3] = (eax & 0xffff);  // @3432_5f56f0
  goto L5f77fb;  // @3433_5f56f0
  L5f77ef:;
  ecx = (u32)(65523);  // @3435_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @3436_5f56f0
  FL[3] = (eax & 0xffff);  // @3437_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(3))) & 0xffff);  // @3438_5f56f0
  FL[3] = (eax & 0xffff);  // @3439_5f56f0
  L5f77fb:;
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @3441_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3442_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @3443_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3444_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @3445_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[169]);  // @3446_5f56f0
  ecx = edx = 0;  // @3447_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @3448_5f56f0
  ecx = (u32)(edi + 52);  // @3449_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @3450_5f56f0
  edx = 0;  // @3451_5f56f0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(EBP - 108)) : "st");  // @3452_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + 10)) :: "st");  // @3453_5f56f0
  goto L5f7af0;  // @3454_5f56f0
  L5f7825:;
  eax = ext_5f4f70_thiscall1(ecx);  // @3456_5f56f0
  ecx = edx = 0;  // @3457_5f56f0
  ecx = (u32)(edi + 52);  // @3458_5f56f0
  eax = ext_5f4f70_thiscall1(ecx);  // @3459_5f56f0
  ecx = edx = 0;  // @3460_5f56f0
  eax = ext_5fa630_cdecl1(PV[169]);  // @3461_5f56f0
    // @3462_5f56f0
  edi = eax;  // @3463_5f56f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3464_5f56f0
  eax = ext_5fa630_cdecl0();  // @3465_5f56f0
    // @3466_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3467_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3468_5f56f0
  PV[172] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 36), sizeof v); (u32)v; });  // @3469_5f56f0
  ecx = eax;  // @3470_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @3471_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[172]);  // @3472_5f56f0
  ecx = edx = 0;  // @3473_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3474_5f56f0
  esi = eax;  // @3475_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3476_5f56f0
  ecx = eax;  // @3477_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3478_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 40), sizeof v); (u32)v; });  // @3479_5f56f0
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @3480_5f56f0
  ecx = edx = 0;  // @3481_5f56f0
  PV[173] = (u32)(eax);  // @3482_5f56f0
  PV[174] = (u32)(esi);  // @3483_5f56f0
  PV[175] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @3484_5f56f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 12)))(PV[175], (u32)(7048892), PV[174], PV[173]);  // @3485_5f56f0
  ecx = edx = 0;  // @3486_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3487_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3488_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3489_5f56f0
  goto L5f57f3;  // @3490_5f56f0
  L5f7887:;
  eax = (u32)(34816);  // @3492_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @3493_5f56f0
  if (FL[2] != 0) goto L5f78fd;  // @3494_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @3495_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3496_5f56f0
  eax = (eax + (u32)(4));  // @3497_5f56f0
  FL[3] = eax;  // @3498_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3499_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3500_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @3501_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3502_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @3503_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @3504_5f56f0
  ecx = edx = 0;  // @3505_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3506_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 108)) :: "st");  // @3507_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @3508_5f56f0
  X0[1] = 0;  // @3509_5f56f0
  X0[2] = 0;  // @3510_5f56f0
  X0[3] = 0;  // @3511_5f56f0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @3512_5f56f0
  eax = (eax + (u32)(4));  // @3513_5f56f0
  FL[3] = eax;  // @3514_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3515_5f56f0
  __builtin_memcpy((void *)((u32)(edi + 10) + 0), &X0[0], 4);  // @3516_5f56f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xffff);  // @3517_5f56f0
  FL[2] = (esi & esi);  // @3518_5f56f0
  if (FL[2] != 0) goto L5f8ae9;  // @3519_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3520_5f56f0
  ecx = (u32)(65523);  // @3521_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @3522_5f56f0
  FL[3] = (eax & 0xffff);  // @3523_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3524_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(3))) & 0xffff);  // @3525_5f56f0
  FL[3] = (eax & 0xffff);  // @3526_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @3527_5f56f0
  goto L5f57f3;  // @3528_5f56f0
  L5f78fd:;
  eax = ext_5fa630_cdecl0();  // @3530_5f56f0
    // @3531_5f56f0
  edi = eax;  // @3532_5f56f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3533_5f56f0
  eax = ext_5fa630_cdecl0();  // @3534_5f56f0
    // @3535_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3536_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3537_5f56f0
  PV[176] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 36), sizeof v); (u32)v; });  // @3538_5f56f0
  ecx = eax;  // @3539_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @3540_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[176]);  // @3541_5f56f0
  ecx = edx = 0;  // @3542_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3543_5f56f0
  esi = eax;  // @3544_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3545_5f56f0
  ecx = eax;  // @3546_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3547_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 40), sizeof v); (u32)v; });  // @3548_5f56f0
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @3549_5f56f0
  ecx = edx = 0;  // @3550_5f56f0
  PV[177] = (u32)(eax);  // @3551_5f56f0
  PV[178] = (u32)(esi);  // @3552_5f56f0
  PV[179] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @3553_5f56f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 12)))(PV[179], (u32)(7048892), PV[178], PV[177]);  // @3554_5f56f0
  ecx = edx = 0;  // @3555_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3556_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3557_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3558_5f56f0
  goto L5f57f3;  // @3559_5f56f0
  L5f7952:;
  eax = (u32)(34816);  // @3561_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @3562_5f56f0
  if (FL[2] == 0) goto L5f8b01;  // @3563_5f56f0
  eax = ext_5fa630_cdecl0();  // @3564_5f56f0
    // @3565_5f56f0
  PV[180] = (u32)(eax);  // @3566_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3567_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 12)))(PV[180], (u32)(7048952));  // @3568_5f56f0
  ecx = edx = 0;  // @3569_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3570_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3571_5f56f0
  goto L5f57f3;  // @3572_5f56f0
  L5f7982:;
  ecx = esi;  // @3574_5f56f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @3575_5f56f0
  eax = (u32)(34816);  // @3576_5f56f0
  edx = (u32)(ecx + 1);  // @3577_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @3578_5f56f0
  if (FL[2] != 0) goto L5f79c0;  // @3579_5f56f0
  L5f7998:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @3581_5f56f0
  ecx = (ecx + 1);  // @3582_5f56f0
  FL[3] = ecx;  // @3583_5f56f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @3584_5f56f0
  if (FL[2] != 0) goto L5f7998;  // @3585_5f56f0
  ecx = (ecx - edx);  // @3586_5f56f0
  FL[3] = ecx;  // @3587_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3588_5f56f0
  eax = (u32)(ecx + 1);  // @3589_5f56f0
  ecx = (u32)(100000000);  // @3590_5f56f0
  eax = (eax + esi);  // @3591_5f56f0
  FL[3] = eax;  // @3592_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @3593_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3594_5f56f0
  goto L5f57f3;  // @3595_5f56f0
  L5f79c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @3597_5f56f0
  ecx = (ecx + 1);  // @3598_5f56f0
  FL[3] = ecx;  // @3599_5f56f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @3600_5f56f0
  if (FL[2] != 0) goto L5f79c0;  // @3601_5f56f0
  ecx = (ecx - edx);  // @3602_5f56f0
  FL[3] = ecx;  // @3603_5f56f0
  eax = (u32)(ecx + 1);  // @3604_5f56f0
  eax = (eax + esi);  // @3605_5f56f0
  FL[3] = eax;  // @3606_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3607_5f56f0
  eax = ext_5fa630_cdecl0();  // @3608_5f56f0
    // @3609_5f56f0
  PV[181] = (u32)(eax);  // @3610_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3611_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 12)))(PV[181], (u32)(7049012));  // @3612_5f56f0
  ecx = edx = 0;  // @3613_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3614_5f56f0
  ecx = (u32)(100000000);  // @3615_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @3616_5f56f0
  goto L5f57f3;  // @3617_5f56f0
  L5f79f7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3619_5f56f0
  eax = (u32)(esi + 4);  // @3620_5f56f0
  edx = (edx + 1);  // @3621_5f56f0
  FL[3] = edx;  // @3622_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3623_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @3624_5f56f0
  goto L5f57f0;  // @3625_5f56f0
  L5f7a0b:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @3627_5f56f0
  FL[0] = edx; FL[1] = (u32)(-1);  // @3628_5f56f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5f7085;  // @3629_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3630_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @3631_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3632_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @3633_5f56f0
  goto L5f7085;  // @3634_5f56f0
  L5f7a2e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3636_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 18), &v, sizeof v); }  // @3637_5f56f0
  L5f7a33:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3639_5f56f0
  eax = (u32)(esi + 4);  // @3640_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3641_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3642_5f56f0
  goto L5f57f3;  // @3643_5f56f0
  L5f7a47:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3645_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @3646_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3647_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @3648_5f56f0
  if (FL[0] != FL[1]) goto L5f7a33;  // @3649_5f56f0
  L5f7a5c:;
  PV[182] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3651_5f56f0
  goto L5f708d;  // @3652_5f56f0
  L5f7a63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3654_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @3655_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3656_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @3657_5f56f0
  if (FL[0] != FL[1]) goto L5f7a5c;  // @3658_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3659_5f56f0
  eax = (u32)(esi + 4);  // @3660_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3661_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3662_5f56f0
  goto L5f57f3;  // @3663_5f56f0
  L5f7a8c:;
  eax = (u32)(esi + 4);  // @3665_5f56f0
  PV[183] = (u32)(eax);  // @3666_5f56f0
  ecx = (u32)(edi + 64);  // @3667_5f56f0
  eax = ext_5f53f0_thiscall2(ecx, PV[183]);  // @3668_5f56f0
  ecx = edx = 0;  // @3669_5f56f0
  goto L5f7085;  // @3670_5f56f0
  L5f7a9d:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3672_5f56f0
  if (FL[0] != FL[1]) goto L5f587e;  // @3673_5f56f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xffff);  // @3674_5f56f0
  ecx = (u32)(65521);  // @3675_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @3676_5f56f0
  FL[3] = (eax & 0xffff);  // @3677_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(1))) & 0xffff);  // @3678_5f56f0
  FL[3] = (eax & 0xffff);  // @3679_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @3680_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 18), sizeof v); (u32)v; }); FL[1] = (u32)(-1);  // @3681_5f56f0
  if (FL[0] != FL[1]) goto L5f7ada;  // @3682_5f56f0
  eax = (u32)(16384);  // @3683_5f56f0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 141), &v, sizeof v); }  // @3684_5f56f0
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) | (eax & 0xffff))); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @3685_5f56f0
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @3686_5f56f0
  L5f7ada:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 18), sizeof v); (u32)v; });  // @3688_5f56f0
  FL[0] = eax; FL[1] = (u32)(-1);  // @3689_5f56f0
  if (FL[0] == FL[1]) goto L5f8b41;  // @3690_5f56f0
  PV[184] = (u32)(eax);  // @3691_5f56f0
  ecx = edi;  // @3692_5f56f0
  eax = ext_5f9130_thiscall3(ecx, PV[184], (u32)(1));  // @3693_5f56f0
  ecx = edx = 0;  // @3694_5f56f0
  L5f7af0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 141), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3696_5f56f0
  if (FL[0] != FL[1]) goto L5f8bb6;  // @3697_5f56f0
  goto L5f57e7;  // @3698_5f56f0
  L5f7b02:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @3700_5f56f0
  FL[0] = edx; FL[1] = (u32)(-1);  // @3701_5f56f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5f7b1c;  // @3702_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3703_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @3704_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3705_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @3706_5f56f0
  L5f7b1c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3708_5f56f0
  ecx = edi;  // @3709_5f56f0
  PV[185] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3710_5f56f0
  eax = ext_5f4d80_thiscall2(ecx, PV[185]);  // @3711_5f56f0
  ecx = edx = 0;  // @3712_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3713_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3714_5f56f0
  goto L5f57f3;  // @3715_5f56f0
  L5f7b36:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @3717_5f56f0
  FL[0] = edx; FL[1] = (u32)(-1);  // @3718_5f56f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5f7b50;  // @3719_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3720_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @3721_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3722_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @3723_5f56f0
  L5f7b50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3725_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3726_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3727_5f56f0
  PV[186] = (u32)(eax);  // @3728_5f56f0
  eax = ext_5f4a80_thiscall2(ecx, PV[186]);  // @3729_5f56f0
  ecx = edx = 0;  // @3730_5f56f0
  PV[187] = (u32)(eax);  // @3731_5f56f0
  ecx = edi;  // @3732_5f56f0
  eax = ext_5f4dc0_thiscall2(ecx, PV[187]);  // @3733_5f56f0
  ecx = edx = 0;  // @3734_5f56f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @3735_5f56f0
  if (FL[2] == 0) goto L5f8bb6;  // @3736_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3737_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3738_5f56f0
  goto L5f57f3;  // @3739_5f56f0
  L5f7b80:;
  PV[188] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3741_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3742_5f56f0
  PV[189] = (u32)(edi);  // @3743_5f56f0
  eax = ext_5fbb00_thiscall3(ecx, PV[189], PV[188]);  // @3744_5f56f0
  ecx = edx = 0;  // @3745_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3746_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3747_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3748_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3749_5f56f0
  goto L5f57f3;  // @3750_5f56f0
  L5f7b9d:;
  eax = (u32)(EBP - 124);  // @3752_5f56f0
  PV[190] = (u32)(eax);  // @3753_5f56f0
  ecx = (u32)(edi + 52);  // @3754_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[190]);  // @3755_5f56f0
  ecx = edx = 0;  // @3756_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3757_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @3758_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @3759_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @3760_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @3761_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3762_5f56f0
  FL[2] = (ecx & ecx);  // @3763_5f56f0
  if ((s32)FL[2] < 0) goto L5f7bf5;  // @3764_5f56f0
  FL[0] = ecx; FL[1] = eax;  // @3765_5f56f0
  if ((s32)FL[0] >= (s32)FL[1]) goto L5f7bf5;  // @3766_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @3767_5f56f0
  eax = (u32)((s32)eax * (s32)ecx);  // @3768_5f56f0
  FL[3] = eax;  // @3769_5f56f0
  ecx = (u32)(edi + 52);  // @3770_5f56f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @3771_5f56f0
  FL[3] = eax;  // @3772_5f56f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }));  // @3773_5f56f0
  FL[3] = eax;  // @3774_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3775_5f56f0
  eax = (u32)(EBP - 108);  // @3776_5f56f0
  PV[191] = (u32)(eax);  // @3777_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[191]);  // @3778_5f56f0
  ecx = edx = 0;  // @3779_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3780_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3781_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3782_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3783_5f56f0
  goto L5f57f3;  // @3784_5f56f0
  L5f7bf5:;
  eax = ext_5fa630_cdecl1(PV[182]);  // @3786_5f56f0
    // @3787_5f56f0
  esi = eax;  // @3788_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3789_5f56f0
  ecx = eax;  // @3790_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3791_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3792_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 40), sizeof v); (u32)v; });  // @3793_5f56f0
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @3794_5f56f0
  ecx = edx = 0;  // @3795_5f56f0
  PV[192] = (u32)(eax);  // @3796_5f56f0
  PV[193] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @3797_5f56f0
  eax = (u32)(EBP - 104);  // @3798_5f56f0
  PV[194] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @3799_5f56f0
  PV[195] = (u32)(eax);  // @3800_5f56f0
  PV[196] = (u32)(esi);  // @3801_5f56f0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(PV[196], PV[195], (u32)(7049192), PV[194], PV[193], PV[192]);  // @3802_5f56f0
  ecx = edx = 0;  // @3803_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @3804_5f56f0
  FL[2] = (eax & eax);  // @3805_5f56f0
  if (FL[2] == 0) goto L5f7c47;  // @3806_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @3807_5f56f0
  ecx = edx = 0;  // @3808_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3809_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3810_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3811_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3812_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3813_5f56f0
  goto L5f57f3;  // @3814_5f56f0
  L5f7c47:;
  __builtin_trap();  // @3816_5f56f0
  L5f7c60:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; });  // @3818_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3819_5f56f0
  goto L5f5936;  // @3820_5f56f0
  L5f7c6b:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3822_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3823_5f56f0
  PV[197] = (u32)(eax);  // @3824_5f56f0
  eax = ext_5ffb00_thiscall2(ecx, PV[197]);  // @3825_5f56f0
  ecx = edx = 0;  // @3826_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3827_5f56f0
  esi = eax;  // @3828_5f56f0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @3829_5f56f0
  PV[198] = (u32)(ecx);  // @3830_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3831_5f56f0
  eax = ext_5ffb00_thiscall2(ecx, PV[198]);  // @3832_5f56f0
  ecx = edx = 0;  // @3833_5f56f0
  PV[199] = (u32)(eax);  // @3834_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3835_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[199], (u32)(7049272));  // @3836_5f56f0
  ecx = edx = 0;  // @3837_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3838_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @3839_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3840_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @3841_5f56f0
  ecx = (ecx + (u32)(10));  // @3842_5f56f0
  FL[3] = ecx;  // @3843_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @3844_5f56f0
  eax = (u32)((s32)eax >> (u32)(16));  // @3845_5f56f0
  FL[3] = eax;  // @3846_5f56f0
  eax = (eax & (u32)(2));  // @3847_5f56f0
  FL[3] = eax;  // @3848_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @3849_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @3850_5f56f0
  if (FL[3] == 0) goto L5f7ce4;  // @3851_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3852_5f56f0
  ecx = edi;  // @3853_5f56f0
  PV[200] = (u32)(esi);  // @3854_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3855_5f56f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[200], (u32)(0));  // @3856_5f56f0
  ecx = edx = 0;  // @3857_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @3858_5f56f0
  goto L5f7d03;  // @3859_5f56f0
  L5f7ce4:;
  ecx = (u32)(edi + 52);  // @3861_5f56f0
  eax = ext_5f4ec0_thiscall2(ecx, (u32)(0));  // @3862_5f56f0
  ecx = edx = 0;  // @3863_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3864_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3865_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @3866_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @3867_5f56f0
  ecx = edx = 0;  // @3868_5f56f0
  ecx = (u32)(edi + 52);  // @3869_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @3870_5f56f0
  eax = ext_5f4f70_thiscall1(ecx);  // @3871_5f56f0
  ecx = edx = 0;  // @3872_5f56f0
  L5f7d03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3874_5f56f0
  edx = (u32)(edi + 52);  // @3875_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @3876_5f56f0
  eax = (u32)((s32)eax >> (u32)(8));  // @3877_5f56f0
  FL[3] = eax;  // @3878_5f56f0
  eax = (eax & 0xff);  // @3879_5f56f0
  PV[201] = (u32)(eax);  // @3880_5f56f0
  ecx = (ecx - eax);  // @3881_5f56f0
  FL[3] = ecx;  // @3882_5f56f0
  PV[202] = (u32)(ecx);  // @3883_5f56f0
  PV[203] = (u32)(edx);  // @3884_5f56f0
  ecx = (u32)(EBP - 212);  // @3885_5f56f0
  eax = ext_5f3440_thiscall4(ecx, PV[203], PV[202], PV[201]);  // @3886_5f56f0
  ecx = edx = 0;  // @3887_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @3888_5f56f0
  ecx = (u32)(edi + 52);  // @3889_5f56f0
  esi = (eax & 0xff);  // @3890_5f56f0
  eax = (u32)(EBP - 184);  // @3891_5f56f0
  PV[204] = (u32)(esi);  // @3892_5f56f0
  PV[205] = (u32)(eax);  // @3893_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @3894_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @3895_5f56f0
  eax = ext_5f5490_thiscall3(ecx, PV[205], PV[204]);  // @3896_5f56f0
  ecx = edx = 0;  // @3897_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @3898_5f56f0
  ecx = (u32)(EBP - 260);  // @3899_5f56f0
  PV[206] = (u32)(esi);  // @3900_5f56f0
  eax = (eax - esi);  // @3901_5f56f0
  FL[3] = eax;  // @3902_5f56f0
  PV[207] = (u32)(eax);  // @3903_5f56f0
  eax = (u32)(edi + 52);  // @3904_5f56f0
  PV[208] = (u32)(eax);  // @3905_5f56f0
  eax = ext_5f3440_thiscall4(ecx, PV[208], PV[207], PV[206]);  // @3906_5f56f0
  ecx = edx = 0;  // @3907_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @3908_5f56f0
  ecx = (u32)(EBP - 168);  // @3909_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @3910_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @3911_5f56f0
  eax = (u32)(EBP - 212);  // @3912_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @3913_5f56f0
  eax = (u32)(EBP - 260);  // @3914_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @3915_5f56f0
  eax = (u32)(edi + 2762);  // @3916_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @3917_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @3918_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @3919_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3920_5f56f0
  PV[209] = (u32)(ecx);  // @3921_5f56f0
  ecx = esi;  // @3922_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[209]);  // @3923_5f56f0
  ecx = edx = 0;  // @3924_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3925_5f56f0
  if (FL[0] == FL[1]) goto L5f7dc0;  // @3926_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3927_5f56f0
  ecx = edi;  // @3928_5f56f0
  PV[210] = (u32)(esi);  // @3929_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[210]);  // @3930_5f56f0
  ecx = edx = 0;  // @3931_5f56f0
  goto L5f7dc7;  // @3932_5f56f0
  L5f7dc0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3934_5f56f0
  ecx = esi;  // @3935_5f56f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @3936_5f56f0
  ecx = edx = 0;  // @3937_5f56f0
  L5f7dc7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @3939_5f56f0
  ecx = (u32)(edi + 52);  // @3940_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @3941_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @3942_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3943_5f56f0
  eax = (u32)(EBP - 132);  // @3944_5f56f0
  PV[211] = (u32)(eax);  // @3945_5f56f0
  eax = (u32)(EBP - 148);  // @3946_5f56f0
  PV[212] = (u32)(eax);  // @3947_5f56f0
  eax = ext_5f5520_thiscall3(ecx, PV[212], PV[211]);  // @3948_5f56f0
  ecx = edx = 0;  // @3949_5f56f0
  L5f7df5:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (u32)(15));  // @3951_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3952_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3953_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @3954_5f56f0
  eax = (u32)(34816);  // @3955_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @3956_5f56f0
  if (FL[2] != 0) goto L5f57f3;  // @3957_5f56f0
  L5f7e1a:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3959_5f56f0
  if (FL[0] != FL[1]) goto L5f8bb6;  // @3960_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @3961_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @3962_5f56f0
  goto L5f57f3;  // @3963_5f56f0
  L5f7e2f:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @3965_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @3966_5f56f0
  PV[213] = (u32)(eax);  // @3967_5f56f0
  eax = ext_5ffb00_thiscall2(ecx, PV[213]);  // @3968_5f56f0
  ecx = edx = 0;  // @3969_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @3970_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3971_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @3972_5f56f0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3973_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @3974_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @3975_5f56f0
  if ((s32)FL[2] >= 0) goto L5f7e64;  // @3976_5f56f0
  PV[214] = (u32)(ecx);  // @3977_5f56f0
  ecx = edi;  // @3978_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[214]);  // @3979_5f56f0
  ecx = edx = 0;  // @3980_5f56f0
  goto L5f7e6c;  // @3981_5f56f0
  L5f7e64:;
  eax = ecx;  // @3983_5f56f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; }));  // @3984_5f56f0
  FL[3] = eax;  // @3985_5f56f0
  L5f7e6c:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3987_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @3988_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 166), sizeof v); (u32)v; });  // @3989_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @3990_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6), sizeof v); (u32)v; });  // @3991_5f56f0
  eax = (eax + (u32)(10));  // @3992_5f56f0
  FL[3] = eax;  // @3993_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 166), &v, sizeof v); }  // @3994_5f56f0
  eax = edx;  // @3995_5f56f0
  eax = (u32)((s32)eax >> (u32)(8));  // @3996_5f56f0
  FL[3] = eax;  // @3997_5f56f0
  eax = (eax & 0xff);  // @3998_5f56f0
  PV[215] = (u32)(eax);  // @3999_5f56f0
  ecx = (ecx - eax);  // @4000_5f56f0
  FL[3] = ecx;  // @4001_5f56f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4002_5f56f0
  PV[216] = (u32)(ecx);  // @4003_5f56f0
  edx = (u32)(esi + 52);  // @4004_5f56f0
  PV[217] = (u32)(edx);  // @4005_5f56f0
  ecx = (u32)(EBP - 224);  // @4006_5f56f0
  eax = ext_5f3440_thiscall4(ecx, PV[217], PV[216], PV[215]);  // @4007_5f56f0
  ecx = edx = 0;  // @4008_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @4009_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @4010_5f56f0
  esi = (eax & 0xff);  // @4011_5f56f0
  eax = (u32)(EBP - 192);  // @4012_5f56f0
  PV[218] = (u32)(esi);  // @4013_5f56f0
  PV[219] = (u32)(eax);  // @4014_5f56f0
  ecx = (u32)(ecx + 52);  // @4015_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @4016_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @4017_5f56f0
  eax = ext_5f5490_thiscall3(ecx, PV[219], PV[218]);  // @4018_5f56f0
  ecx = edx = 0;  // @4019_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @4020_5f56f0
  PV[220] = (u32)(esi);  // @4021_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @4022_5f56f0
  eax = (eax - esi);  // @4023_5f56f0
  FL[3] = eax;  // @4024_5f56f0
  esi = (u32)(ecx + 52);  // @4025_5f56f0
  PV[221] = (u32)(eax);  // @4026_5f56f0
  PV[222] = (u32)(esi);  // @4027_5f56f0
  ecx = (u32)(EBP - 272);  // @4028_5f56f0
  eax = ext_5f3440_thiscall4(ecx, PV[222], PV[221], PV[220]);  // @4029_5f56f0
  ecx = edx = 0;  // @4030_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @4031_5f56f0
  ecx = (u32)(EBP - 168);  // @4032_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @4033_5f56f0
  eax = (u32)(EBP - 224);  // @4034_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @4035_5f56f0
  eax = (u32)(EBP - 272);  // @4036_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @4037_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @4038_5f56f0
  eax = (eax + (u32)(2762));  // @4039_5f56f0
  FL[3] = eax;  // @4040_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @4041_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @4042_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @4043_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4044_5f56f0
  PV[223] = (u32)(ecx);  // @4045_5f56f0
  ecx = edi;  // @4046_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[223]);  // @4047_5f56f0
  ecx = edx = 0;  // @4048_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @4049_5f56f0
  ecx = esi;  // @4050_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4051_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @4052_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @4053_5f56f0
  eax = (u32)(EBP - 132);  // @4054_5f56f0
  PV[224] = (u32)(eax);  // @4055_5f56f0
  eax = (u32)(EBP - 148);  // @4056_5f56f0
  PV[225] = (u32)(eax);  // @4057_5f56f0
  eax = ext_5f5520_thiscall3(ecx, PV[225], PV[224]);  // @4058_5f56f0
  ecx = edx = 0;  // @4059_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @4060_5f56f0
  goto L5f7df5;  // @4061_5f56f0
  L5f7f7b:;
  PV[226] = (u32)(esi);  // @4063_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @4064_5f56f0
  eax = ((u32( *)(u32, u32))(esi))(PV[226], (u32)(7047048));  // @4065_5f56f0
  ecx = edx = 0;  // @4066_5f56f0
  FL[2] = (eax & eax);  // @4067_5f56f0
  if (FL[2] != 0) goto L5f7fa7;  // @4068_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4069_5f56f0
  ecx = (u32)(edi + 52);  // @4070_5f56f0
  eax = (u32)(EBP - 132);  // @4071_5f56f0
  PV[227] = (u32)(eax);  // @4072_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[227]);  // @4073_5f56f0
  ecx = edx = 0;  // @4074_5f56f0
  goto L5f7ff4;  // @4075_5f56f0
  L5f7fa7:;
  PV[228] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4077_5f56f0
  eax = ((u32( *)(u32, u32))(esi))(PV[228], (u32)(7049284));  // @4078_5f56f0
  ecx = edx = 0;  // @4079_5f56f0
  FL[2] = (eax & eax);  // @4080_5f56f0
  if (FL[2] != 0) goto L5f7fd2;  // @4081_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4082_5f56f0
  ecx = (u32)(edi + 52);  // @4083_5f56f0
  eax = (u32)(EBP - 132);  // @4084_5f56f0
  PV[229] = (u32)(eax);  // @4085_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[229]);  // @4086_5f56f0
  ecx = edx = 0;  // @4087_5f56f0
  goto L5f7ff4;  // @4088_5f56f0
  L5f7fd2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4090_5f56f0
  ecx = edi;  // @4091_5f56f0
  PV[230] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4092_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4093_5f56f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[230], (u32)(0));  // @4094_5f56f0
  ecx = edx = 0;  // @4095_5f56f0
  esi = eax;  // @4096_5f56f0
  ecx = (u32)(edi + 52);  // @4097_5f56f0
  PV[231] = (u32)(esi);  // @4098_5f56f0
  eax = ext_5f5390_thiscall2(ecx, PV[231]);  // @4099_5f56f0
  ecx = edx = 0;  // @4100_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4101_5f56f0
  ecx = esi;  // @4102_5f56f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @4103_5f56f0
  ecx = edx = 0;  // @4104_5f56f0
  L5f7ff4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4106_5f56f0
  ecx = edx;  // @4107_5f56f0
  esi = (u32)(ecx + 1);  // @4108_5f56f0
  L5f8000:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @4110_5f56f0
  ecx = (ecx + 1);  // @4111_5f56f0
  FL[3] = ecx;  // @4112_5f56f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @4113_5f56f0
  if (FL[2] != 0) goto L5f8000;  // @4114_5f56f0
  ecx = (ecx - esi);  // @4115_5f56f0
  FL[3] = ecx;  // @4116_5f56f0
  eax = (u32)(edx + 1);  // @4117_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4118_5f56f0
  eax = (eax + ecx);  // @4119_5f56f0
  FL[3] = eax;  // @4120_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4121_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4122_5f56f0
  goto L5f57f3;  // @4123_5f56f0
  L5f801f:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4125_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @4126_5f56f0
  PV[232] = (u32)(eax);  // @4127_5f56f0
  eax = ext_5ffb00_thiscall2(ecx, PV[232]);  // @4128_5f56f0
  ecx = edx = 0;  // @4129_5f56f0
  PV[233] = (u32)(eax);  // @4130_5f56f0
  ecx = (u32)(edi + 52);  // @4131_5f56f0
  eax = ext_5f53f0_thiscall2(ecx, PV[233]);  // @4132_5f56f0
  ecx = edx = 0;  // @4133_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4134_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4135_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4136_5f56f0
  ecx = (ecx + 1);  // @4137_5f56f0
  FL[3] = ecx;  // @4138_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4139_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @4140_5f56f0
  goto L5f57f3;  // @4141_5f56f0
  L5f804d:;
  eax = (u32)(EBP - 124);  // @4143_5f56f0
  PV[234] = (u32)(eax);  // @4144_5f56f0
  ecx = (u32)(edi + 52);  // @4145_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[234]);  // @4146_5f56f0
  ecx = edx = 0;  // @4147_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4148_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4149_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4150_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @4151_5f56f0
  if ((s32)FL[2] >= 0) goto L5f809b;  // @4152_5f56f0
  PV[235] = (u32)(eax);  // @4153_5f56f0
  ecx = edi;  // @4154_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[235]);  // @4155_5f56f0
  ecx = edx = 0;  // @4156_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4157_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4158_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @4159_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @4160_5f56f0
  ecx = edx = 0;  // @4161_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @4162_5f56f0
  ecx = edi;  // @4163_5f56f0
  PV[236] = (u32)(esi);  // @4164_5f56f0
  PV[237] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @4165_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @4166_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[237]);  // @4167_5f56f0
  ecx = edx = 0;  // @4168_5f56f0
  ecx = eax;  // @4169_5f56f0
  eax = ext_5f3fc0_thiscall2(ecx, PV[236]);  // @4170_5f56f0
  ecx = edx = 0;  // @4171_5f56f0
  goto L5f80c0;  // @4172_5f56f0
  L5f809b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @4174_5f56f0
  esi = (eax & 0xffff);  // @4175_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4176_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; });  // @4177_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @4178_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4179_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @4180_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @4181_5f56f0
  ecx = edx = 0;  // @4182_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4183_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx), &v, sizeof v); }  // @4184_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @4185_5f56f0
  L5f80c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4187_5f56f0
  ecx = edi;  // @4188_5f56f0
  PV[238] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @4189_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[238]);  // @4190_5f56f0
  ecx = edx = 0;  // @4191_5f56f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @4192_5f56f0
  if (FL[0] != FL[1]) goto L5f80d7;  // @4193_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4194_5f56f0
  ecx = esi;  // @4195_5f56f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @4196_5f56f0
  ecx = edx = 0;  // @4197_5f56f0
  L5f80d7:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(2))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4199_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4200_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4201_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4202_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @4203_5f56f0
  goto L5f57f3;  // @4204_5f56f0
  L5f80ed:;
  eax = (u32)(EBP - 124);  // @4206_5f56f0
  PV[239] = (u32)(eax);  // @4207_5f56f0
  ecx = (u32)(edi + 52);  // @4208_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[239]);  // @4209_5f56f0
  ecx = edx = 0;  // @4210_5f56f0
  ecx = (u32)(edi + 52);  // @4211_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @4212_5f56f0
  edx = 0;  // @4213_5f56f0
  eax = (eax & 0xffff);  // @4214_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4215_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @4216_5f56f0
  if ((s32)FL[2] >= 0) goto L5f8146;  // @4217_5f56f0
  PV[240] = (u32)(eax);  // @4218_5f56f0
  ecx = edi;  // @4219_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[240]);  // @4220_5f56f0
  ecx = edx = 0;  // @4221_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4222_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4223_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @4224_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @4225_5f56f0
  ecx = edx = 0;  // @4226_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @4227_5f56f0
  ecx = esi;  // @4228_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @4229_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4230_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 36), sizeof v); (u32)v; });  // @4231_5f56f0
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @4232_5f56f0
  ecx = edx = 0;  // @4233_5f56f0
  PV[241] = (u32)(eax);  // @4234_5f56f0
  PV[242] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @4235_5f56f0
  ecx = edi;  // @4236_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[242]);  // @4237_5f56f0
  ecx = edx = 0;  // @4238_5f56f0
  ecx = eax;  // @4239_5f56f0
  eax = ext_5f3fc0_thiscall2(ecx, PV[241]);  // @4240_5f56f0
  ecx = edx = 0;  // @4241_5f56f0
  goto L5f816b;  // @4242_5f56f0
  L5f8146:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @4244_5f56f0
  esi = (eax & 0xffff);  // @4245_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4246_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; });  // @4247_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @4248_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4249_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @4250_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @4251_5f56f0
  ecx = edx = 0;  // @4252_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4253_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx), &v, sizeof v); }  // @4254_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @4255_5f56f0
  L5f816b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4257_5f56f0
  ecx = edi;  // @4258_5f56f0
  PV[243] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @4259_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[243]);  // @4260_5f56f0
  ecx = edx = 0;  // @4261_5f56f0
  L5f8175:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @4263_5f56f0
  if (FL[0] != FL[1]) goto L5f8182;  // @4264_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4265_5f56f0
  ecx = esi;  // @4266_5f56f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @4267_5f56f0
  ecx = edx = 0;  // @4268_5f56f0
  L5f8182:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4270_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4271_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @4272_5f56f0
  goto L5f57f3;  // @4273_5f56f0
  L5f8191:;
  ecx = (u32)(edi + 52);  // @4275_5f56f0
  eax = ext_5f4ec0_thiscall2(ecx, (u32)(0));  // @4276_5f56f0
  ecx = edx = 0;  // @4277_5f56f0
  PV[244] = (u32)(eax);  // @4278_5f56f0
  ecx = (u32)(EBP - 124);  // @4279_5f56f0
  eax = ext_5f3bf0_thiscall2(ecx, PV[244]);  // @4280_5f56f0
  ecx = edx = 0;  // @4281_5f56f0
  ecx = esi;  // @4282_5f56f0
  edx = (u32)(ecx + 1);  // @4283_5f56f0
  L5f81b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @4285_5f56f0
  ecx = (ecx + 1);  // @4286_5f56f0
  FL[3] = ecx;  // @4287_5f56f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @4288_5f56f0
  if (FL[2] != 0) goto L5f81b0;  // @4289_5f56f0
  ecx = (ecx - edx);  // @4290_5f56f0
  FL[3] = ecx;  // @4291_5f56f0
  eax = (u32)(ecx + 1);  // @4292_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4293_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4294_5f56f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @4295_5f56f0
  eax = (eax - (u32)(1));  // @4296_5f56f0
  FL[3] = eax;  // @4297_5f56f0
  if (FL[3] == 0) goto L5f823d;  // @4298_5f56f0
  eax = (eax - (u32)(1));  // @4299_5f56f0
  FL[3] = eax;  // @4300_5f56f0
  if (FL[3] == 0) goto L5f8323;  // @4301_5f56f0
  eax = (eax - (u32)(2));  // @4302_5f56f0
  FL[3] = eax;  // @4303_5f56f0
  if (FL[3] == 0) goto L5f81fb;  // @4304_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @4305_5f56f0
  FL[2] = (eax & eax);  // @4306_5f56f0
  if (FL[2] == 0) goto L5f81ef;  // @4307_5f56f0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @4308_5f56f0
  ecx = edx = 0;  // @4309_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4310_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4311_5f56f0
  goto L5f57f3;  // @4312_5f56f0
  L5f81ef:;
  __builtin_trap();  // @4314_5f56f0
  L5f81fb:;
  eax = (u32)(EBP - 124);  // @4316_5f56f0
  PV[245] = (u32)(eax);  // @4317_5f56f0
  ecx = (u32)(edi + 52);  // @4318_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[245]);  // @4319_5f56f0
  ecx = edx = 0;  // @4320_5f56f0
  eax = (u32)(edi + 52);  // @4321_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 228), &v, sizeof v); }  // @4322_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 236), &v, sizeof v); }  // @4323_5f56f0
  ecx = (u32)(EBP - 236);  // @4324_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @4325_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @4326_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @4327_5f56f0
  PV[246] = (u32)(ecx);  // @4328_5f56f0
  PV[247] = (u32)(esi);  // @4329_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @4330_5f56f0
  ecx = esi;  // @4331_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4332_5f56f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[247], PV[246]);  // @4333_5f56f0
  ecx = edx = 0;  // @4334_5f56f0
  goto L5f8175;  // @4335_5f56f0
  L5f823d:;
  PV[248] = (u32)(esi);  // @4337_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[248], (u32)(7047060));  // @4338_5f56f0
  ecx = edx = 0;  // @4339_5f56f0
  FL[2] = (eax & eax);  // @4340_5f56f0
  if (FL[2] != 0) goto L5f8281;  // @4341_5f56f0
  ecx = (u32)(edi + 52);  // @4342_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @4343_5f56f0
  edx = 0;  // @4344_5f56f0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @4345_5f56f0
  FL[2] = (eax & eax);  // @4346_5f56f0
  if (FL[2] != 0) goto L5f826a;  // @4347_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @4348_5f56f0
  L5f826a:;
  eax = (u32)(EBP - 128);  // @4350_5f56f0
  PV[249] = (u32)(eax);  // @4351_5f56f0
  ecx = (u32)(edi + 52);  // @4352_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[249]);  // @4353_5f56f0
  ecx = edx = 0;  // @4354_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4355_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4356_5f56f0
  goto L5f57f3;  // @4357_5f56f0
  L5f8281:;
  PV[250] = (u32)(esi);  // @4359_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[250], (u32)(7046812));  // @4360_5f56f0
  ecx = edx = 0;  // @4361_5f56f0
  FL[2] = (eax & eax);  // @4362_5f56f0
  if (FL[2] != 0) goto L5f82c5;  // @4363_5f56f0
  ecx = (u32)(edi + 52);  // @4364_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @4365_5f56f0
  edx = 0;  // @4366_5f56f0
  ecx = (u32)(edi + 52);  // @4367_5f56f0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @4368_5f56f0
  eax = (u32)(EBP - 132);  // @4369_5f56f0
  X0[0] = F2U((float)(s32)X0[0]);  // @4370_5f56f0
  X0[1] = F2U((float)(s32)X0[1]);  // @4371_5f56f0
  X0[2] = F2U((float)(s32)X0[2]);  // @4372_5f56f0
  X0[3] = F2U((float)(s32)X0[3]);  // @4373_5f56f0
  PV[251] = (u32)(eax);  // @4374_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 132) + 0), &X0[0], 4);  // @4375_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[251]);  // @4376_5f56f0
  ecx = edx = 0;  // @4377_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4378_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4379_5f56f0
  goto L5f57f3;  // @4380_5f56f0
  L5f82c5:;
  PV[252] = (u32)(esi);  // @4382_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[252], (u32)(7047028));  // @4383_5f56f0
  ecx = edx = 0;  // @4384_5f56f0
  FL[2] = (eax & eax);  // @4385_5f56f0
  if (FL[2] != 0) goto L5f8306;  // @4386_5f56f0
  ecx = (u32)(edi + 52);  // @4387_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @4388_5f56f0
  edx = 0;  // @4389_5f56f0
  FL[1] = eax;  // @4390_5f56f0
  eax = (0u - eax);  // @4391_5f56f0
  ecx = (u32)(edi + 52);  // @4392_5f56f0
  eax = (0u - (u32)(FL[1] != 0));  // @4393_5f56f0
  FL[1] = eax;  // @4394_5f56f0
  eax = (0u - eax);  // @4395_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4396_5f56f0
  eax = (u32)(EBP - 132);  // @4397_5f56f0
  PV[253] = (u32)(eax);  // @4398_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[253]);  // @4399_5f56f0
  ecx = edx = 0;  // @4400_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4401_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4402_5f56f0
  goto L5f57f3;  // @4403_5f56f0
  L5f8306:;
  PV[254] = (u32)(esi);  // @4405_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[254], (u32)(7049292));  // @4406_5f56f0
  ecx = edx = 0;  // @4407_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4408_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4409_5f56f0
  FL[2] = (eax & eax);  // @4410_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @4411_5f56f0
  L5f8323:;
  PV[255] = (u32)(esi);  // @4413_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[255], (u32)(7046808));  // @4414_5f56f0
  ecx = edx = 0;  // @4415_5f56f0
  FL[2] = (eax & eax);  // @4416_5f56f0
  if (FL[2] == 0) goto L5f84c6;  // @4417_5f56f0
  PV[256] = (u32)(esi);  // @4418_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[256], (u32)(7047028));  // @4419_5f56f0
  ecx = edx = 0;  // @4420_5f56f0
  FL[2] = (eax & eax);  // @4421_5f56f0
  if (FL[2] == 0) goto L5f84c6;  // @4422_5f56f0
  PV[257] = (u32)(esi);  // @4423_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[257], (u32)(7047060));  // @4424_5f56f0
  ecx = edx = 0;  // @4425_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4426_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4427_5f56f0
  FL[2] = (eax & eax);  // @4428_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @4429_5f56f0
  PV[258] = (u32)(esi);  // @4430_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[258], (u32)(7047100));  // @4431_5f56f0
  ecx = edx = 0;  // @4432_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4433_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4434_5f56f0
  FL[2] = (eax & eax);  // @4435_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @4436_5f56f0
  PV[259] = (u32)(esi);  // @4437_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[259], (u32)(7047112));  // @4438_5f56f0
  ecx = edx = 0;  // @4439_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4440_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4441_5f56f0
  FL[2] = (eax & eax);  // @4442_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @4443_5f56f0
  PV[260] = (u32)(esi);  // @4444_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[260], (u32)(7047132));  // @4445_5f56f0
  ecx = edx = 0;  // @4446_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4447_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4448_5f56f0
  FL[2] = (eax & eax);  // @4449_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @4450_5f56f0
  PV[261] = (u32)(esi);  // @4451_5f56f0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[261], (u32)(7047156));  // @4452_5f56f0
  ecx = edx = 0;  // @4453_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4454_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4455_5f56f0
  FL[2] = (eax & eax);  // @4456_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @4457_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @4458_5f56f0
  ecx = (u32)(EBP - 248);  // @4459_5f56f0
  eax = (eax - 1);  // @4460_5f56f0
  FL[3] = eax;  // @4461_5f56f0
  PV[262] = (u32)(eax);  // @4462_5f56f0
  eax = (u32)(edi + 52);  // @4463_5f56f0
  PV[263] = (u32)(eax);  // @4464_5f56f0
  eax = ext_5f3440_thiscall4(ecx, PV[263], PV[262], (u32)(1));  // @4465_5f56f0
  ecx = edx = 0;  // @4466_5f56f0
  eax = (u32)(EBP - 200);  // @4467_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @4468_5f56f0
  PV[264] = (u32)(eax);  // @4469_5f56f0
  ecx = (u32)(edi + 52);  // @4470_5f56f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @4471_5f56f0
  eax = ext_5f5490_thiscall3(ecx, PV[264], (u32)(1));  // @4472_5f56f0
  ecx = edx = 0;  // @4473_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @4474_5f56f0
  ecx = (u32)(EBP - 284);  // @4475_5f56f0
  eax = (eax - 1);  // @4476_5f56f0
  FL[3] = eax;  // @4477_5f56f0
  PV[265] = (u32)(eax);  // @4478_5f56f0
  eax = (u32)(edi + 52);  // @4479_5f56f0
  PV[266] = (u32)(eax);  // @4480_5f56f0
  eax = ext_5f3440_thiscall4(ecx, PV[266], PV[265], (u32)(1));  // @4481_5f56f0
  ecx = edx = 0;  // @4482_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4483_5f56f0
  ecx = edi;  // @4484_5f56f0
  PV[267] = (u32)(esi);  // @4485_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4486_5f56f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[267], (u32)(0));  // @4487_5f56f0
  ecx = edx = 0;  // @4488_5f56f0
  esi = eax;  // @4489_5f56f0
  { u32 v = (u32)((u32)(7049304)); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @4490_5f56f0
  eax = (u32)(EBP - 248);  // @4491_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @4492_5f56f0
  ecx = (u32)(edi + 2762);  // @4493_5f56f0
  eax = (u32)(EBP - 284);  // @4494_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @4495_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @4496_5f56f0
  ecx = (u32)(EBP - 168);  // @4497_5f56f0
  eax = (u32)(7);  // @4498_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @4499_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4500_5f56f0
  PV[268] = (u32)(ecx);  // @4501_5f56f0
  ecx = esi;  // @4502_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[268]);  // @4503_5f56f0
  ecx = edx = 0;  // @4504_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 240), sizeof v); (u32)v; });  // @4505_5f56f0
  ecx = (u32)(edi + 52);  // @4506_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4507_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 244), sizeof v); (u32)v; });  // @4508_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @4509_5f56f0
  eax = (u32)(EBP - 132);  // @4510_5f56f0
  PV[269] = (u32)(eax);  // @4511_5f56f0
  eax = (u32)(EBP - 148);  // @4512_5f56f0
  PV[270] = (u32)(eax);  // @4513_5f56f0
  eax = ext_5f5520_thiscall3(ecx, PV[270], PV[269]);  // @4514_5f56f0
  ecx = edx = 0;  // @4515_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4516_5f56f0
  ecx = edi;  // @4517_5f56f0
  PV[271] = (u32)(esi);  // @4518_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[271]);  // @4519_5f56f0
  ecx = edx = 0;  // @4520_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4521_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4522_5f56f0
  goto L5f57f3;  // @4523_5f56f0
  L5f84c6:;
  ecx = (u32)(edi + 52);  // @4525_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @4526_5f56f0
  edx = 0;  // @4527_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 132)) :: "st");  // @4528_5f56f0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 132) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @4529_5f56f0
  ecx = (u32)(edi + 52);  // @4530_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4531_5f56f0
  eax = (u32)(EBP - 132);  // @4532_5f56f0
  PV[272] = (u32)(eax);  // @4533_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[272]);  // @4534_5f56f0
  ecx = edx = 0;  // @4535_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4536_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4537_5f56f0
  goto L5f57f3;  // @4538_5f56f0
  L5f84fc:;
  ecx = (u32)(edi + 52);  // @4540_5f56f0
  eax = ext_5f5020_thiscall1(ecx);  // @4541_5f56f0
  edx = 0;  // @4542_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @4543_5f56f0
  X1[1] = 0;  // @4544_5f56f0
  X1[2] = 0;  // @4545_5f56f0
  X1[3] = 0;  // @4546_5f56f0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 140)) :: "st");  // @4547_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 140) + 0), 4); v; });  // @4548_5f56f0
  X0[1] = 0;  // @4549_5f56f0
  X0[2] = 0;  // @4550_5f56f0
  X0[3] = 0;  // @4551_5f56f0
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L5f854c;  // @4552_5f56f0
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))))) goto L5f8556;  // @4553_5f56f0
  eax = (u32)(EBP - 140);  // @4554_5f56f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @4555_5f56f0
  PV[273] = (u32)(eax);  // @4556_5f56f0
  ecx = (u32)(edi + 52);  // @4557_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[273]);  // @4558_5f56f0
  ecx = edx = 0;  // @4559_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4560_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4561_5f56f0
  goto L5f57f3;  // @4562_5f56f0
  L5f854c:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @4564_5f56f0
  L5f8556:;
  eax = (u32)(EBP - 140);  // @4566_5f56f0
  PV[274] = (u32)(eax);  // @4567_5f56f0
  ecx = (u32)(edi + 52);  // @4568_5f56f0
  eax = ext_5f52f0_thiscall2(ecx, PV[274]);  // @4569_5f56f0
  ecx = edx = 0;  // @4570_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4571_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4572_5f56f0
  goto L5f57f3;  // @4573_5f56f0
  L5f8570:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4575_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4576_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @4577_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @4578_5f56f0
  if ((s32)FL[2] >= 0) goto L5f8591;  // @4579_5f56f0
  PV[275] = (u32)(eax);  // @4580_5f56f0
  ecx = edi;  // @4581_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[275]);  // @4582_5f56f0
  ecx = edx = 0;  // @4583_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @4584_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4585_5f56f0
  goto L5f859c;  // @4586_5f56f0
  L5f8591:;
  ecx = eax;  // @4588_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4589_5f56f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @4590_5f56f0
  L5f859c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @4592_5f56f0
  edx = (edx + (u32)(4294967160));  // @4593_5f56f0
  FL[3] = edx;  // @4594_5f56f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @4595_5f56f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @4596_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @4597_5f56f0
  if ((s32)FL[2] >= 0) goto L5f863c;  // @4598_5f56f0
  FL[0] = edx; FL[1] = (u32)(3);  // @4599_5f56f0
  if (FL[0] > FL[1]) goto L5f6202;  // @4600_5f56f0
  switch (edx) {  // @4601_5f56f0
  case 0: goto L5f85ca;  // @4602_5f56f0
  case 1: goto L5f85d7;  // @4603_5f56f0
  case 2: goto L5f85ec;  // @4604_5f56f0
  case 3: goto L5f8614;  // @4605_5f56f0
  default: __builtin_trap(); }  // @4606_5f56f0
  L5f85ca:;
  ecx = (u32)(EBP - 140);  // @4608_5f56f0
  PV[276] = (u32)(ecx);  // @4609_5f56f0
  PV[277] = (u32)(eax);  // @4610_5f56f0
  goto L5f6090;  // @4611_5f56f0
  L5f85d7:;
  ecx = (u32)(EBP - 132);  // @4613_5f56f0
  FL[1] = esi;  // @4614_5f56f0
  esi = (0u - esi);  // @4615_5f56f0
  PV[278] = (u32)(ecx);  // @4616_5f56f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4617_5f56f0
  PV[279] = (u32)(eax);  // @4618_5f56f0
  goto L5f6090;  // @4619_5f56f0
  L5f85ec:;
  ecx = (u32)(EBP - 140);  // @4621_5f56f0
  PV[280] = (u32)(ecx);  // @4622_5f56f0
  PV[281] = (u32)(eax);  // @4623_5f56f0
  ecx = edi;  // @4624_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[281]);  // @4625_5f56f0
  ecx = edx = 0;  // @4626_5f56f0
  ecx = eax;  // @4627_5f56f0
  eax = ext_5f4e00_thiscall2(ecx, PV[280]);  // @4628_5f56f0
  ecx = edx = 0;  // @4629_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4630_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4631_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4632_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4633_5f56f0
  goto L5f57f3;  // @4634_5f56f0
  L5f8614:;
  FL[2] = (esi & esi);  // @4636_5f56f0
  if (FL[2] == 0) goto L5f8623;  // @4637_5f56f0
  eax = (u32)(EBP - 140);  // @4638_5f56f0
  goto L5f611a;  // @4639_5f56f0
  L5f8623:;
  ecx = edi;  // @4641_5f56f0
  eax = ext_5f9260_thiscall1(ecx);  // @4642_5f56f0
  ecx = edx = 0;  // @4643_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4644_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4645_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4646_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4647_5f56f0
  goto L5f57f3;  // @4648_5f56f0
  L5f863c:;
  FL[0] = edx; FL[1] = (u32)(3);  // @4650_5f56f0
  if (FL[0] > FL[1]) goto L5f6202;  // @4651_5f56f0
  switch (edx) {  // @4652_5f56f0
  case 0: goto L5f864c;  // @4653_5f56f0
  case 1: goto L5f866a;  // @4654_5f56f0
  case 2: goto L5f8688;  // @4655_5f56f0
  case 3: goto L5f86ac;  // @4656_5f56f0
  default: __builtin_trap(); }  // @4657_5f56f0
  L5f864c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4659_5f56f0
  ecx = (eax & 0xffff);  // @4660_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4661_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(eax + ecx), &v, sizeof v); }  // @4662_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; });  // @4663_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4664_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4665_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4666_5f56f0
  goto L5f57f3;  // @4667_5f56f0
  L5f866a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4669_5f56f0
  ecx = (eax & 0xffff);  // @4670_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4671_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; }) - esi)); __builtin_memcpy((void *)(u32)(eax + ecx), &v, sizeof v); }  // @4672_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; });  // @4673_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4674_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4675_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4676_5f56f0
  goto L5f57f3;  // @4677_5f56f0
  L5f8688:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4679_5f56f0
  edx = (eax & 0xffff);  // @4680_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx), sizeof v); (u32)v; });  // @4681_5f56f0
  eax = (u32)((s32)eax * (s32)esi);  // @4682_5f56f0
  FL[3] = eax;  // @4683_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx), &v, sizeof v); }  // @4684_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4685_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4686_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4687_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4688_5f56f0
  goto L5f57f3;  // @4689_5f56f0
  L5f86ac:;
  FL[2] = (esi & esi);  // @4691_5f56f0
  if (FL[2] == 0) goto L5f8623;  // @4692_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4693_5f56f0
  esi = (eax & 0xffff);  // @4694_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi), sizeof v); (u32)v; });  // @4695_5f56f0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @4696_5f56f0
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @4697_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4698_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + esi), &v, sizeof v); }  // @4699_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4700_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4701_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4702_5f56f0
  goto L5f57f3;  // @4703_5f56f0
  L5f86d9:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4705_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4706_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @4707_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @4708_5f56f0
  if ((s32)FL[2] >= 0) goto L5f86fc;  // @4709_5f56f0
  PV[282] = (u32)(eax);  // @4710_5f56f0
  ecx = edi;  // @4711_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[282]);  // @4712_5f56f0
  ecx = edx = 0;  // @4713_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @4714_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @4715_5f56f0
  X1[1] = 0;  // @4716_5f56f0
  X1[2] = 0;  // @4717_5f56f0
  X1[3] = 0;  // @4718_5f56f0
  goto L5f8709;  // @4719_5f56f0
  L5f86fc:;
  ecx = eax;  // @4721_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4722_5f56f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; });  // @4723_5f56f0
  X1[1] = 0;  // @4724_5f56f0
  X1[2] = 0;  // @4725_5f56f0
  X1[3] = 0;  // @4726_5f56f0
  L5f8709:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @4728_5f56f0
  edx = (edx + (u32)(4294967156));  // @4729_5f56f0
  FL[3] = edx;  // @4730_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X1[0], 4);  // @4731_5f56f0
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @4732_5f56f0
  if ((s32)FL[2] >= 0) goto L5f87d6;  // @4733_5f56f0
  FL[0] = edx; FL[1] = (u32)(3);  // @4734_5f56f0
  if (FL[0] > FL[1]) goto L5f6202;  // @4735_5f56f0
  switch (edx) {  // @4736_5f56f0
  case 0: goto L5f8736;  // @4737_5f56f0
  case 1: goto L5f875e;  // @4738_5f56f0
  case 2: goto L5f8775;  // @4739_5f56f0
  case 3: goto L5f879d;  // @4740_5f56f0
  default: __builtin_trap(); }  // @4741_5f56f0
  L5f8736:;
  eax = (u32)(EBP - 140);  // @4743_5f56f0
  L5f873c:;
  PV[283] = (u32)(eax);  // @4745_5f56f0
  PV[284] = (u32)(ecx);  // @4746_5f56f0
  ecx = edi;  // @4747_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[284]);  // @4748_5f56f0
  ecx = edx = 0;  // @4749_5f56f0
  ecx = eax;  // @4750_5f56f0
  eax = ext_5f3db0_thiscall2(ecx, PV[283]);  // @4751_5f56f0
  ecx = edx = 0;  // @4752_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4753_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4754_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4755_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4756_5f56f0
  goto L5f57f3;  // @4757_5f56f0
  L5f875e:;
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @4759_5f56f0
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @4760_5f56f0
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @4761_5f56f0
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @4762_5f56f0
  eax = (u32)(EBP - 132);  // @4763_5f56f0
  __builtin_memcpy((void *)((u32)(EBP - 132) + 0), &X1[0], 4);  // @4764_5f56f0
  goto L5f873c;  // @4765_5f56f0
  L5f8775:;
  eax = (u32)(EBP - 140);  // @4767_5f56f0
  PV[285] = (u32)(eax);  // @4768_5f56f0
  PV[286] = (u32)(ecx);  // @4769_5f56f0
  ecx = edi;  // @4770_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[286]);  // @4771_5f56f0
  ecx = edx = 0;  // @4772_5f56f0
  ecx = eax;  // @4773_5f56f0
  eax = ext_5f4e60_thiscall2(ecx, PV[285]);  // @4774_5f56f0
  ecx = edx = 0;  // @4775_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4776_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4777_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4778_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4779_5f56f0
  goto L5f57f3;  // @4780_5f56f0
  L5f879d:;
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @4782_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @4783_5f56f0
  if (__builtin_parity(FL[2] & 0xff)) goto L5f8623;  // @4784_5f56f0
  eax = (u32)(EBP - 140);  // @4785_5f56f0
  PV[287] = (u32)(eax);  // @4786_5f56f0
  PV[288] = (u32)(ecx);  // @4787_5f56f0
  ecx = edi;  // @4788_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[288]);  // @4789_5f56f0
  ecx = edx = 0;  // @4790_5f56f0
  ecx = eax;  // @4791_5f56f0
  eax = ext_5f4110_thiscall2(ecx, PV[287]);  // @4792_5f56f0
  ecx = edx = 0;  // @4793_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4794_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4795_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4796_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4797_5f56f0
  goto L5f57f3;  // @4798_5f56f0
  L5f87d6:;
  FL[0] = edx; FL[1] = (u32)(3);  // @4800_5f56f0
  if (FL[0] > FL[1]) goto L5f6202;  // @4801_5f56f0
  switch (edx) {  // @4802_5f56f0
  case 0: goto L5f87e6;  // @4803_5f56f0
  case 1: goto L5f880f;  // @4804_5f56f0
  case 2: goto L5f8838;  // @4805_5f56f0
  case 3: goto L5f8861;  // @4806_5f56f0
  default: __builtin_trap(); }  // @4807_5f56f0
  L5f87e6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4809_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4810_5f56f0
  ecx = (ecx & 0xffff);  // @4811_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @4812_5f56f0
  X0[1] = 0;  // @4813_5f56f0
  X0[2] = 0;  // @4814_5f56f0
  X0[3] = 0;  // @4815_5f56f0
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @4816_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @4817_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4818_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4819_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4820_5f56f0
  goto L5f57f3;  // @4821_5f56f0
  L5f880f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4823_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4824_5f56f0
  ecx = (ecx & 0xffff);  // @4825_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @4826_5f56f0
  X0[1] = 0;  // @4827_5f56f0
  X0[2] = 0;  // @4828_5f56f0
  X0[3] = 0;  // @4829_5f56f0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @4830_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @4831_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4832_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4833_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4834_5f56f0
  goto L5f57f3;  // @4835_5f56f0
  L5f8838:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4837_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4838_5f56f0
  ecx = (ecx & 0xffff);  // @4839_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @4840_5f56f0
  X0[1] = 0;  // @4841_5f56f0
  X0[2] = 0;  // @4842_5f56f0
  X0[3] = 0;  // @4843_5f56f0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @4844_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @4845_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4846_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4847_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4848_5f56f0
  goto L5f57f3;  // @4849_5f56f0
  L5f8861:;
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @4851_5f56f0
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @4852_5f56f0
  if (__builtin_parity(FL[2] & 0xff)) goto L5f8623;  // @4853_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4854_5f56f0
  ecx = (ecx & 0xffff);  // @4855_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4856_5f56f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @4857_5f56f0
  X0[1] = 0;  // @4858_5f56f0
  X0[2] = 0;  // @4859_5f56f0
  X0[3] = 0;  // @4860_5f56f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @4861_5f56f0
  __builtin_memcpy((void *)((u32)(eax + ecx) + 0), &X0[0], 4);  // @4862_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4863_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4864_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4865_5f56f0
  goto L5f57f3;  // @4866_5f56f0
  L5f889b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4868_5f56f0
  FL[2] = (ecx & ecx);  // @4869_5f56f0
  if ((s32)FL[2] >= 0) goto L5f88f1;  // @4870_5f56f0
  eax = ecx;  // @4871_5f56f0
  FL[1] = eax;  // @4872_5f56f0
  eax = (0u - eax);  // @4873_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4874_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 170), sizeof v); (u32)v; });  // @4875_5f56f0
  eax = (eax + ecx);  // @4876_5f56f0
  FL[3] = eax;  // @4877_5f56f0
  ecx = (u32)(edi + 52);  // @4878_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @4879_5f56f0
  eax = (u32)(EBP - 132);  // @4880_5f56f0
  PV[289] = (u32)(eax);  // @4881_5f56f0
  eax = (u32)(EBP - 148);  // @4882_5f56f0
  PV[290] = (u32)(eax);  // @4883_5f56f0
  eax = ext_5f5520_thiscall3(ecx, PV[290], PV[289]);  // @4884_5f56f0
  ecx = edx = 0;  // @4885_5f56f0
  ecx = (u32)(edi + 64);  // @4886_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @4887_5f56f0
  edx = 0;  // @4888_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4889_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4890_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4891_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4892_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 170), &v, sizeof v); }  // @4893_5f56f0
  goto L5f57f3;  // @4894_5f56f0
  L5f88f1:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 170), sizeof v); (u32)v; });  // @4896_5f56f0
  ecx = (u32)(edi + 64);  // @4897_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @4898_5f56f0
  eax = (u32)(EBP - 132);  // @4899_5f56f0
  PV[291] = (u32)(eax);  // @4900_5f56f0
  eax = ext_5f5250_thiscall2(ecx, PV[291]);  // @4901_5f56f0
  ecx = edx = 0;  // @4902_5f56f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; })) & 0xffff);  // @4903_5f56f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4904_5f56f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @4905_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4906_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4907_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 170), &v, sizeof v); }  // @4908_5f56f0
  goto L5f57f3;  // @4909_5f56f0
  L5f892a:;
  ecx = edi;  // @4911_5f56f0
  eax = ext_5f4390_thiscall1(ecx);  // @4912_5f56f0
  ecx = edx = 0;  // @4913_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4914_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4915_5f56f0
  goto L5f57f3;  // @4916_5f56f0
  L5f893c:;
  eax = (u32)(EBP - 124);  // @4918_5f56f0
  PV[292] = (u32)(eax);  // @4919_5f56f0
  ecx = (u32)(edi + 52);  // @4920_5f56f0
  eax = ext_5f4f00_thiscall2(ecx, PV[292]);  // @4921_5f56f0
  ecx = edx = 0;  // @4922_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4923_5f56f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5f8961;  // @4924_5f56f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; })) & 0xffff);  // @4925_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4926_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4927_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @4928_5f56f0
  goto L5f57f3;  // @4929_5f56f0
  L5f8961:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4931_5f56f0
  ecx = (u32)(1000000);  // @4932_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @4933_5f56f0
  goto L5f57f3;  // @4934_5f56f0
  L5f8971:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4936_5f56f0
  eax = (u32)(esi + 4);  // @4937_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4938_5f56f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @4939_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @4940_5f56f0
  goto L5f57f3;  // @4941_5f56f0
  L5f8987:;
  ecx = (u32)(edi + 52);  // @4943_5f56f0
  eax = ext_5f4ff0_thiscall1(ecx);  // @4944_5f56f0
  edx = 0;  // @4945_5f56f0
  eax = (eax & 0xffff);  // @4946_5f56f0
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @4947_5f56f0
  if ((s32)FL[2] >= 0) goto L5f89b4;  // @4948_5f56f0
  PV[293] = (u32)(eax);  // @4949_5f56f0
  ecx = edi;  // @4950_5f56f0
  eax = ext_5f4a00_thiscall2(ecx, PV[293]);  // @4951_5f56f0
  ecx = edx = 0;  // @4952_5f56f0
  ecx = (u32)(edi + 52);  // @4953_5f56f0
  PV[294] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @4954_5f56f0
  eax = ext_5f5390_thiscall2(ecx, PV[294]);  // @4955_5f56f0
  ecx = edx = 0;  // @4956_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4957_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4958_5f56f0
  goto L5f57f3;  // @4959_5f56f0
  L5f89b4:;
  ecx = eax;  // @4961_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @4962_5f56f0
  PV[295] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx), sizeof v); (u32)v; });  // @4963_5f56f0
  ecx = (u32)(edi + 52);  // @4964_5f56f0
  eax = ext_5f5390_thiscall2(ecx, PV[295]);  // @4965_5f56f0
  ecx = edx = 0;  // @4966_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4967_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4968_5f56f0
  goto L5f57f3;  // @4969_5f56f0
  L5f89d2:;
  ecx = edi;  // @4971_5f56f0
  eax = ext_5f90a0_thiscall1(ecx);  // @4972_5f56f0
  ecx = edx = 0;  // @4973_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4974_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4975_5f56f0
  goto L5f57f3;  // @4976_5f56f0
  L5f89e4:;
  ecx = edi;  // @4978_5f56f0
  eax = ext_5f9010_thiscall1(ecx);  // @4979_5f56f0
  ecx = edx = 0;  // @4980_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4981_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4982_5f56f0
  goto L5f57f3;  // @4983_5f56f0
  L5f89f6:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @4985_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4986_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4987_5f56f0
  FL[2] = (eax & (u32)(34816));  // @4988_5f56f0
  if (FL[2] != 0) goto L5f57f3;  // @4989_5f56f0
  FL[2] = (eax & (u32)(4096));  // @4990_5f56f0
  if (FL[2] == 0) goto L5f8a37;  // @4991_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @4992_5f56f0
  FL[2] = (eax & eax);  // @4993_5f56f0
  if (FL[2] == 0) goto L5f8a2b;  // @4994_5f56f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[279], PV[278], PV[277], PV[276]);  // @4995_5f56f0
  ecx = edx = 0;  // @4996_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @4997_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @4998_5f56f0
  goto L5f57f3;  // @4999_5f56f0
  L5f8a2b:;
  __builtin_trap();  // @5001_5f56f0
  L5f8a37:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @5003_5f56f0
  eax = (u32)(36864);  // @5004_5f56f0
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) | (eax & 0xffff))); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @5005_5f56f0
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @5006_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @5007_5f56f0
  goto L5f57f3;  // @5008_5f56f0
  L5f8a4e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @5010_5f56f0
  eax = (u32)(4096);  // @5011_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @5012_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @5013_5f56f0
  if (FL[2] == 0) goto L5f57f3;  // @5014_5f56f0
  eax = (u32)(28671);  // @5015_5f56f0
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff))); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @5016_5f56f0
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @5017_5f56f0
  goto L5f7e1a;  // @5018_5f56f0
  L5f8a77:;
  eax = ext_5fa630_cdecl4(PV[279], PV[278], PV[277], PV[276]);  // @5020_5f56f0
    // @5021_5f56f0
  esi = eax;  // @5022_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @5023_5f56f0
  ecx = eax;  // @5024_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @5025_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5026_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 40), sizeof v); (u32)v; });  // @5027_5f56f0
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @5028_5f56f0
  ecx = edx = 0;  // @5029_5f56f0
  eax = (eax - 1);  // @5030_5f56f0
  FL[3] = eax;  // @5031_5f56f0
  PV[296] = (u32)(eax);  // @5032_5f56f0
  eax = (u32)(EBP - 104);  // @5033_5f56f0
  PV[297] = (u32)(eax);  // @5034_5f56f0
  PV[298] = (u32)(esi);  // @5035_5f56f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 20)))(PV[298], PV[297], (u32)(7049312), PV[296]);  // @5036_5f56f0
  ecx = edx = 0;  // @5037_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @5038_5f56f0
  FL[2] = (eax & eax);  // @5039_5f56f0
  if (FL[2] == 0) goto L5f8abd;  // @5040_5f56f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @5041_5f56f0
  ecx = edx = 0;  // @5042_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @5043_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @5044_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @5045_5f56f0
  goto L5f57f3;  // @5046_5f56f0
  L5f8abd:;
  __builtin_trap();  // @5048_5f56f0
  L5f8acf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; });  // @5050_5f56f0
  ecx = edi;  // @5051_5f56f0
  PV[299] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @5052_5f56f0
  eax = ext_5f5620_thiscall2(ecx, PV[299]);  // @5053_5f56f0
  ecx = edx = 0;  // @5054_5f56f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @5055_5f56f0
  goto L5f8bb6;  // @5056_5f56f0
  L5f8ae9:;
  ecx = (u32)(65522);  // @5058_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @5059_5f56f0
  FL[3] = (eax & 0xffff);  // @5060_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(2))) & 0xffff);  // @5061_5f56f0
  FL[3] = (eax & 0xffff);  // @5062_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @5063_5f56f0
  goto L5f8bb6;  // @5064_5f56f0
  L5f8b01:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xff);  // @5066_5f56f0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(15))) & 0xff);  // @5067_5f56f0
  FL[3] = (eax & 0xff);  // @5068_5f56f0
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @5069_5f56f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xffff);  // @5070_5f56f0
  if (FL[0] != FL[1]) goto L5f8b2c;  // @5071_5f56f0
  ecx = (u32)(65525);  // @5072_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @5073_5f56f0
  FL[3] = (eax & 0xffff);  // @5074_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(5))) & 0xffff);  // @5075_5f56f0
  FL[3] = (eax & 0xffff);  // @5076_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @5077_5f56f0
  goto L5f8bb6;  // @5078_5f56f0
  L5f8b2c:;
  ecx = (u32)(65524);  // @5080_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @5081_5f56f0
  FL[3] = (eax & 0xffff);  // @5082_5f56f0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(4))) & 0xffff);  // @5083_5f56f0
  FL[3] = (eax & 0xffff);  // @5084_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @5085_5f56f0
  goto L5f8bb6;  // @5086_5f56f0
  L5f8b41:;
  eax = ext_5fa630_cdecl1(PV[182]);  // @5088_5f56f0
    // @5089_5f56f0
  edi = eax;  // @5090_5f56f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @5091_5f56f0
  eax = ext_5fa630_cdecl0();  // @5092_5f56f0
    // @5093_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @5094_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @5095_5f56f0
  PV[300] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 36), sizeof v); (u32)v; });  // @5096_5f56f0
  ecx = eax;  // @5097_5f56f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @5098_5f56f0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[300]);  // @5099_5f56f0
  ecx = edx = 0;  // @5100_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5101_5f56f0
  esi = eax;  // @5102_5f56f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @5103_5f56f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 150), sizeof v); (u32)v; });  // @5104_5f56f0
  eax = ext_600800_thiscall1(ecx);  // @5105_5f56f0
    // @5106_5f56f0
  PV[301] = (u32)(eax);  // @5107_5f56f0
  PV[302] = (u32)(esi);  // @5108_5f56f0
  PV[303] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @5109_5f56f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 12)))(PV[303], (u32)(7049080), PV[302], PV[301]);  // @5110_5f56f0
  ecx = edx = 0;  // @5111_5f56f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @5112_5f56f0
  L5f8b93:;
  eax = (u32)(34816);  // @5114_5f56f0
  FL[2] = (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (eax & 0xffff));  // @5115_5f56f0
  eax = (u32)(16384);  // @5116_5f56f0
  if (FL[2] == 0) goto L5f8baf;  // @5117_5f56f0
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 180), sizeof v); (u32)v; }) | (eax & 0xffff))); __builtin_memcpy((void *)(u32)(edi + 180), &v, sizeof v); }  // @5118_5f56f0
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 180), sizeof v); (u32)v; });  // @5119_5f56f0
  goto L5f8bb6;  // @5120_5f56f0
  L5f8baf:;
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) | (eax & 0xffff))); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @5122_5f56f0
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @5123_5f56f0
  L5f8bb6:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; }) & (u32)(15));  // @5125_5f56f0
  if (FL[2] == 0) goto L5f8be6;  // @5126_5f56f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; });  // @5127_5f56f0
  FL[2] = (eax & (u32)(34816));  // @5128_5f56f0
  if (FL[2] != 0) goto L5f8be6;  // @5129_5f56f0
  eax = (eax & (u32)(57343));  // @5130_5f56f0
  FL[3] = eax;  // @5131_5f56f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @5132_5f56f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @5133_5f56f0
  if (FL[0] == FL[1]) goto L5f8be6;  // @5134_5f56f0
  ecx = edi;  // @5135_5f56f0
  eax = ext_5f4ac0_thiscall1(ecx);  // @5136_5f56f0
  ecx = edx = 0;  // @5137_5f56f0
  L5f8be6:;
  ext_633654(G(u32, 0x6f5630));  // @5139_5f56f0
  return eax;  // @5140_5f56f0
}
PCREG(5f56f0, lifted_5f56f0);

