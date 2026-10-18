// batch244013.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_6014a0_thiscall1(u32, u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_5ec090_thiscall3(u32, u32, u32) __asm__("ext_5ec090");
extern "C" u32 THISCALL ext_5ec340_thiscall3(u32, u32, u32) __asm__("ext_5ec340");
extern "C" u32 THISCALL ext_5ecd80_thiscall3(u32, u32, u32) __asm__("ext_5ecd80");
extern "C" u32 THISCALL ext_5ed2b0_thiscall4(u32, u32, u32, u32) __asm__("ext_5ed2b0");
extern "C" u32 THISCALL ext_606ea0_thiscall3(u32, u32, u32) __asm__("ext_606ea0");
extern "C" u32 THISCALL ext_6073b0_thiscall2(u32, u32) __asm__("ext_6073b0");
extern "C" u32 THISCALL ext_63da80_thiscall2(u32, u32) __asm__("ext_63da80");
extern "C" u32 THISCALL ext_658f50_thiscall1(u32) __asm__("ext_658f50");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_607260(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_607260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 15), sizeof v); (u32)v; });  // @1_607260
  eax = (eax + 1);  // @2_607260
  FL[3] = eax;  // @3_607260
  PV[0] = (u32)(eax);  // @4_607260
  eax = ext_6073b0_thiscall2(ecx, PV[0]);  // @5_607260
  ecx = edx = 0;  // @6_607260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7), sizeof v); (u32)v; });  // @7_607260
  ecx = edi;  // @8_607260
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3), sizeof v); (u32)v; }));  // @9_607260
  FL[3] = eax;  // @10_607260
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_607260
  eax = (u32)((s32)eax >> (u32)(2));  // @12_607260
  FL[3] = eax;  // @13_607260
  PV[1] = (u32)(eax);  // @14_607260
  PV[2] = (u32)(ebx);  // @15_607260
  eax = ext_606ea0_thiscall3(ecx, PV[2], PV[1]);  // @16_607260
  ecx = edx = 0;  // @17_607260
  ecx = (u32)(eax*4);  // @18_607260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3), sizeof v); (u32)v; });  // @19_607260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @20_607260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @21_607260
  esi = eax;  // @22_607260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @23_607260
  FL[2] = (eax & eax);  // @24_607260
  if (FL[2] == 0) goto L6072b9;  // @25_607260
  L6072a1:;
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @27_607260
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @28_607260
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[4], PV[3]);  // @29_607260
  ecx = edx = 0;  // @30_607260
  FL[2] = (eax & eax);  // @31_607260
  if (FL[2] == 0) goto L6072f7;  // @32_607260
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_607260
  FL[2] = (esi & esi);  // @34_607260
  if (FL[2] != 0) goto L6072a1;  // @35_607260
  L6072b9:;
  ecx = edi;  // @37_607260
  eax = ext_6014a0_thiscall1(ecx_in, (u32)(10));  // @38_607260
  ecx = edx = 0;  // @39_607260
  edx = eax;  // @40_607260
  eax = (u32)(edx + 4);  // @41_607260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @42_607260
  FL[2] = (eax & eax);  // @43_607260
  if (FL[2] == 0) goto L6072dd;  // @44_607260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @45_607260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_607260
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xffff);  // @47_607260
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @48_607260
  L6072dd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @50_607260
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @51_607260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @52_607260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3), sizeof v); (u32)v; });  // @53_607260
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + ecx), &v, sizeof v); }  // @54_607260
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 15), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 15), &v, sizeof v); }  // @55_607260
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 15), sizeof v); (u32)v; });  // @56_607260
  return eax;  // @57_607260
  L6072f7:;
  eax = (u32)(esi + 4);  // @59_607260
  return eax;  // @60_607260
}
PCREG(607260, lifted_607260);

extern "C" u32 THISCALL lifted_4269e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6685bb);  // @h_4269e0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ecx;  // @0_4269e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_4269e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4269e0
  ebx = (u32)(eax + 12);  // @3_4269e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @4_4269e0
  ecx = ebx;  // @5_4269e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @6_4269e0
  ecx = edx = 0;  // @7_4269e0
  FL[2] = (eax & eax);  // @8_4269e0
  if (FL[2] != 0) goto L426a63;  // @9_4269e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_4269e0
  edx = (u32)(EBP - 144);  // @11_4269e0
  PV[0] = (u32)(edx);  // @12_4269e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4269e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 320)))(ecx, PV[0]);  // @14_4269e0
  ecx = edx = 0;  // @15_4269e0
  PV[1] = (u32)(eax);  // @16_4269e0
  ecx = ebx;  // @17_4269e0
  reg.state = (s32)((u32)(0));  // @18_4269e0
  eax = ext_4cbee0_thiscall2(ecx, PV[1]);  // @19_4269e0
  ecx = edx = 0;  // @20_4269e0
  ecx = (u32)(EBP - 144);  // @21_4269e0
  reg.state = (s32)((u32)(4294967295));  // @22_4269e0
  eax = ext_4cbec0_thiscall1(ecx);  // @23_4269e0
  ecx = edx = 0;  // @24_4269e0
  L426a63:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_4269e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4269e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @28_4269e0
  ecx = edx = 0;  // @29_4269e0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @30_4269e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @31_4269e0
  esi = eax;  // @32_4269e0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @33_4269e0
  ecx = (ecx + (u32)(140));  // @34_4269e0
  FL[3] = ecx;  // @35_4269e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_4269e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @37_4269e0
    // @38_4269e0
  PV[4] = (u32)(eax);  // @39_4269e0
  ecx = ebx;  // @40_4269e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @41_4269e0
    // @42_4269e0
  PV[5] = (u32)(eax);  // @43_4269e0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @44_4269e0
  PV[7] = (u32)(esi);  // @45_4269e0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 408)))(PV[7], PV[6], (u32)(6786332), PV[5], PV[4], PV[3], PV[2]);  // @46_4269e0
  ecx = edx = 0;  // @47_4269e0
  SEH_LEAVE();  // @48_4269e0
  ext_633654(G(u32, 0x6f5630));  // @49_4269e0
  return eax;  // @50_4269e0
}
PCREG(4269e0, lifted_4269e0);

extern "C" u32 THISCALL lifted_5f0080(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5f0080
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_5f0080
  edi = ecx;  // @2_5f0080
  PV[1] = (u32)(esi);  // @3_5f0080
  eax = ext_5ecd80_thiscall3(ecx, PV[1], PV[0]);  // @4_5f0080
  ecx = edx = 0;  // @5_5f0080
  ecx = edi;  // @6_5f0080
  eax = ext_5ec340_thiscall3(ecx, (u32)(4280295456), (u32)(0));  // @7_5f0080
  ecx = edx = 0;  // @8_5f0080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_5f0080
  ecx = esi;  // @10_5f0080
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @11_5f0080
  ecx = edx = 0;  // @12_5f0080
  ecx = esi;  // @13_5f0080
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @14_5f0080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_5f0080
  X0[0] = F2U((float)(s32)X0[0]);  // @16_5f0080
  X0[1] = F2U((float)(s32)X0[1]);  // @17_5f0080
  X0[2] = F2U((float)(s32)X0[2]);  // @18_5f0080
  X0[3] = F2U((float)(s32)X0[3]);  // @19_5f0080
  __builtin_memcpy((void *)((u32)(EBP + 12) + 0), &X0[0], 4);  // @20_5f0080
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @21_5f0080
  ecx = edx = 0;  // @22_5f0080
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @23_5f0080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 215), sizeof v); (u32)v; });  // @24_5f0080
  X0[0] = F2U((float)(s32)X0[0]);  // @25_5f0080
  X0[1] = F2U((float)(s32)X0[1]);  // @26_5f0080
  X0[2] = F2U((float)(s32)X0[2]);  // @27_5f0080
  X0[3] = F2U((float)(s32)X0[3]);  // @28_5f0080
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @29_5f0080
  FL[0] = eax; FL[1] = (u32)(3);  // @30_5f0080
  if (FL[0] > FL[1]) goto L5f013f;  // @31_5f0080
  switch (eax) {  // @32_5f0080
  case 0: goto L5f00d8;  // @33_5f0080
  case 1: goto L5f00fa;  // @34_5f0080
  case 2: goto L5f010b;  // @35_5f0080
  case 3: goto L5f0113;  // @36_5f0080
  default: __builtin_trap(); }  // @37_5f0080
  L5f00d8:;
  L5f00dc:;
  ecx = edi;  // @40_5f0080
  eax = ext_5ed2b0_thiscall4(ecx, (u32)(0), (u32)(0), (u32)(-1));  // @41_5f0080
  edx = 0;  // @42_5f0080
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @43_5f0080
  ecx = edi;  // @44_5f0080
  PV[2] = (u32)(eax);  // @45_5f0080
  eax = ext_5ec090_thiscall3(ecx, PV[2], (u32)(1));  // @46_5f0080
  ecx = edx = 0;  // @47_5f0080
  return eax;  // @48_5f0080
  L5f00fa:;
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @50_5f0080
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @51_5f0080
  PV[3] = (u32)(eax);  // @52_5f0080
  goto L5f00dc;  // @53_5f0080
  L5f010b:;
  goto L5f0129;  // @55_5f0080
  L5f0113:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @57_5f0080
  X0[1] = 0;  // @58_5f0080
  X0[2] = 0;  // @59_5f0080
  X0[3] = 0;  // @60_5f0080
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @61_5f0080
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @62_5f0080
  PV[4] = (u32)(eax);  // @63_5f0080
  L5f0129:;
  ecx = edi;  // @65_5f0080
  eax = ext_5ed2b0_thiscall4(ecx, PV[4], (u32)(0), (u32)(-1));  // @66_5f0080
  edx = 0;  // @67_5f0080
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @68_5f0080
  ecx = edi;  // @69_5f0080
  PV[5] = (u32)(eax);  // @70_5f0080
  eax = ext_5ec090_thiscall3(ecx, (u32)(1), PV[5]);  // @71_5f0080
  ecx = edx = 0;  // @72_5f0080
  L5f013f:;
  return eax;  // @74_5f0080
}
// (lifted_5f0080 replaced by the hand port fn5f0080 below: the lifter mishandled the shared push tails of the jump-table cases)

extern "C" u32 THISCALL lifted_4eec30(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664d1b);  // @h_4eec30
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4eec30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4eec30
  ebx = (u32)(393232);  // @2_4eec30
  FL[0] = eax; FL[1] = (u32)(6);  // @3_4eec30
  if (FL[0] > FL[1]) goto L4eec9e;  // @4_4eec30
  switch (eax) {  // @5_4eec30
  case 0: goto L4eecf0;  // @6_4eec30
  case 1: goto L4eec74;  // @7_4eec30
  case 2: goto L4eec7b;  // @8_4eec30
  case 3: goto L4eec82;  // @9_4eec30
  case 4: goto L4eec89;  // @10_4eec30
  case 5: goto L4eec90;  // @11_4eec30
  case 6: goto L4eec97;  // @12_4eec30
  default: __builtin_trap(); }  // @13_4eec30
  L4eec74:;
  ebx = (u32)(393234);  // @15_4eec30
  goto L4eecf0;  // @16_4eec30
  L4eec7b:;
  ebx = (u32)(393236);  // @18_4eec30
  goto L4eecf0;  // @19_4eec30
  L4eec82:;
  ebx = (u32)(393233);  // @21_4eec30
  goto L4eecf0;  // @22_4eec30
  L4eec89:;
  ebx = (u32)(393240);  // @24_4eec30
  goto L4eecf0;  // @25_4eec30
  L4eec90:;
  ebx = (u32)(393744);  // @27_4eec30
  goto L4eecf0;  // @28_4eec30
  L4eec97:;
  ebx = (u32)(393745);  // @30_4eec30
  goto L4eecf0;  // @31_4eec30
  L4eec9e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @33_4eec30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_4eec30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6912796), (u32)(678));  // @35_4eec30
  ecx = edx = 0;  // @36_4eec30
  edi = eax;  // @37_4eec30
  ecx = (u32)(EBP - 144);  // @38_4eec30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_4eec30
  PV[0] = (u32)(ecx);  // @40_4eec30
  ecx = esi;  // @41_4eec30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 476)))(ecx, PV[0], (u32)(1));  // @42_4eec30
  ecx = edx = 0;  // @43_4eec30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_4eec30
  ecx = eax;  // @45_4eec30
  reg.state = (s32)((u32)(0));  // @46_4eec30
  eax = ext_4cc1d0_thiscall1(ecx);  // @47_4eec30
    // @48_4eec30
  PV[1] = (u32)(eax);  // @49_4eec30
  PV[2] = (u32)(edi);  // @50_4eec30
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[2], (u32)(6915108), PV[1]);  // @51_4eec30
  ecx = edx = 0;  // @52_4eec30
  ecx = (u32)(EBP - 144);  // @53_4eec30
  eax = ext_4cbec0_thiscall1(ecx);  // @54_4eec30
  ecx = edx = 0;  // @55_4eec30
  L4eecf0:;
  eax = ebx;  // @57_4eec30
  SEH_LEAVE();  // @58_4eec30
  ext_633654(G(u32, 0x6f5630));  // @59_4eec30
  return eax;  // @60_4eec30
}
PCREG(4eec30, lifted_4eec30);

extern "C" u32 THISCALL lifted_64d490(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_64d490
  esi = ecx;  // @1_64d490
  PV[0] = (u32)(ebx);  // @2_64d490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @3_64d490
  eax = ext_63da80_thiscall2(ecx, PV[0]);  // @4_64d490
  edx = 0;  // @5_64d490
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @6_64d490
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9), sizeof v); (u32)v; })) & 0xff);  // @7_64d490
  eax = (u32)(edx + 1);  // @8_64d490
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 9), &v, sizeof v); }  // @9_64d490
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @10_64d490
  if (FL[2] != 0) goto L64d4c6;  // @11_64d490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @12_64d490
  PV[1] = (u32)(edi);  // @13_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_64d490
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, PV[1]);  // @15_64d490
  ecx = edx = 0;  // @16_64d490
  L64d4c6:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @18_64d490
  FL[2] = (edi & edi);  // @19_64d490
  if (FL[2] == 0) goto L64d552;  // @20_64d490
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @21_64d490
  eax = (u32)(ecx + 1);  // @22_64d490
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @23_64d490
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @24_64d490
  if (FL[2] != 0) goto L64d4ed;  // @25_64d490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @26_64d490
  PV[2] = (u32)(edi);  // @27_64d490
  eax = ext_63da80_thiscall2(ecx, PV[2]);  // @28_64d490
  edx = 0;  // @29_64d490
  L64d4ed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @31_64d490
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6), sizeof v); (u32)v; });  // @32_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65649), sizeof v); (u32)v; });  // @33_64d490
  ecx = (ecx & (u32)(4095));  // @34_64d490
  FL[3] = ecx;  // @35_64d490
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @36_64d490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @37_64d490
  eax = (u32)(ecx + 1);  // @38_64d490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @39_64d490
  FL[2] = (ecx & ecx);  // @40_64d490
  if (FL[2] != 0) goto L64d518;  // @41_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_64d490
  ecx = esi;  // @43_64d490
  PV[3] = (u32)(edx);  // @44_64d490
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[3]);  // @45_64d490
  ecx = edx = 0;  // @46_64d490
  L64d518:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 98757), sizeof v); (u32)v; });  // @48_64d490
  FL[2] = (esi & esi);  // @49_64d490
  if (FL[2] == 0) goto L64d542;  // @50_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_64d490
  eax = (eax + 1);  // @52_64d490
  FL[3] = eax;  // @53_64d490
  FL[0] = eax; FL[1] = (u32)(8192);  // @54_64d490
  if (FL[0] <= FL[1]) goto L64d53a;  // @55_64d490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @56_64d490
  FL[2] = (eax & eax);  // @57_64d490
  if (FL[2] == 0) goto L64d539;  // @58_64d490
  eax = ((u32(STDCALL *)(void))(eax))();  // @59_64d490
  ecx = edx = 0;  // @60_64d490
  goto L64d53a;  // @61_64d490
  L64d539:;
  __builtin_trap();  // @63_64d490
  L64d53a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @65_64d490
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + eax*4 + 4), &v, sizeof v); }  // @66_64d490
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @67_64d490
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @68_64d490
  L64d542:;
  ecx = edi;  // @70_64d490
  eax = ext_658f50_thiscall1(ecx);  // @71_64d490
    // @72_64d490
  FL[0] = eax; FL[1] = (u32)(1);  // @73_64d490
  if (FL[0] <= FL[1]) goto L64d552;  // @74_64d490
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 5), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(ebx + 5), &v, sizeof v); }  // @75_64d490
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 5), sizeof v); (u32)v; });  // @76_64d490
  L64d552:;
  return eax;  // @78_64d490
}
PCREG(64d490, lifted_64d490);

extern "C" u32 THISCALL lifted_537bb0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_537bb0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_537bb0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20666), sizeof v); (u32)v; })) & 0xff);  // @1_537bb0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_537bb0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @3_537bb0
  if (FL[2] == 0) goto L537c91;  // @4_537bb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_537bb0
  FL[0] = edi; FL[1] = (u32)(-1);  // @6_537bb0
  if (FL[0] != FL[1]) goto L537c00;  // @7_537bb0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @8_537bb0
  FL[3] = (eax & 0xff);  // @9_537bb0
  goto L537c93;  // @10_537bb0
  L537c00:;
  ecx = (u32)(EBP - 144);  // @12_537bb0
  eax = ext_4cbeb0_thiscall1(ecx);  // @13_537bb0
    // @14_537bb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @15_537bb0
  edx = (u32)(EBP - 272);  // @16_537bb0
  PV[0] = (u32)(ebx);  // @17_537bb0
  PV[1] = (u32)(edx);  // @18_537bb0
  reg.state = (s32)((u32)(0));  // @19_537bb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_537bb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 208)))(ecx, PV[1], PV[0]);  // @21_537bb0
  ecx = edx = 0;  // @22_537bb0
  PV[2] = (u32)(eax);  // @23_537bb0
  ecx = (u32)(EBP - 144);  // @24_537bb0
  reg.state = (s32)((u32)(1));  // @25_537bb0
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @26_537bb0
  ecx = edx = 0;  // @27_537bb0
  ecx = (u32)(EBP - 272);  // @28_537bb0
  reg.state = (s32)((u32)(0));  // @29_537bb0
  eax = ext_4cbec0_thiscall1(ecx);  // @30_537bb0
  ecx = edx = 0;  // @31_537bb0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @32_537bb0
  ecx = (u32)(EBP - 144);  // @33_537bb0
  { u32 v = (u32)((u32)(257)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @34_537bb0
  { u32 v = (u32)((u32)(140)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @35_537bb0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @36_537bb0
  eax = ext_4cc1d0_thiscall1(ecx);  // @37_537bb0
    // @38_537bb0
  edx = (u32)(ebx + 12);  // @39_537bb0
  edx = (edx - eax);  // @40_537bb0
  FL[3] = edx;  // @41_537bb0
  L537c70:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @43_537bb0
  eax = (u32)(eax + 1);  // @44_537bb0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @45_537bb0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @46_537bb0
  if (FL[2] != 0) goto L537c70;  // @47_537bb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @48_537bb0
  ecx = (u32)(EBP - 144);  // @49_537bb0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @50_537bb0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @51_537bb0
  eax = ext_4cbec0_thiscall1(ecx);  // @52_537bb0
  ecx = edx = 0;  // @53_537bb0
  L537c91:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @55_537bb0
  L537c93:;
  SEH_LEAVE();  // @57_537bb0
  ext_633654(G(u32, 0x6f5630));  // @58_537bb0
  return eax;  // @59_537bb0
}
PCREG(537bb0, lifted_537bb0);


// 0x5f0080 hand port: thiscall(a0 object, a1) ret 8. 0x5ecd80(this, a0, a1); 0x5ec340(this, 0xff202020, 0); w = (float)a0->slot0(), h = (float)a0->slot4();
// switch [this+0xd7]: 0: 0x5ed2b0(0,0,-1), 0x5ec090(w,1); 1: 0x5ed2b0(0,h-c,-1), 0x5ec090(w,1); 2: 0x5ed2b0(0,0,-1), 0x5ec090(1,h); 3: 0x5ed2b0(w-c,0,-1), 0x5ec090(1,h);
// c = float at 0x678858; other values return the mode in eax. Float to int conversions are cvttss2si.
typedef u32(THISCALL *w4c_v0b_t)(void *);
static u32 THISCALL fn5f0080(u8 *self, u8 *obj, u32 a1) {
  ext_5ecd80_thiscall3((u32)self, (u32)obj, a1);
  ext_5ec340_thiscall3((u32)self, 0xff202020u, 0);
  float w = (float)(s32)(*(w4c_v0b_t **)obj)[0](obj);
  float h = (float)(s32)(*(w4c_v0b_t **)obj)[4 / 4](obj);
  u32 mode = *(u32 *)(self + 0xd7);
  float c = *(float *)0x678858;
  switch (mode) {
    case 0:
      ext_5ed2b0_thiscall4((u32)self, 0, 0, (u32)-1);
      return ext_5ec090_thiscall3((u32)self, (u32)(s32)w, 1);
    case 1:
      ext_5ed2b0_thiscall4((u32)self, 0, (u32)(s32)(h - c), (u32)-1);
      return ext_5ec090_thiscall3((u32)self, (u32)(s32)w, 1);
    case 2:
      ext_5ed2b0_thiscall4((u32)self, 0, 0, (u32)-1);
      return ext_5ec090_thiscall3((u32)self, 1, (u32)(s32)h);
    case 3:
      ext_5ed2b0_thiscall4((u32)self, (u32)(s32)(w - c), 0, (u32)-1);
      return ext_5ec090_thiscall3((u32)self, 1, (u32)(s32)h);
  }
  return mode;
}
PCREG(5f0080, fn5f0080);
