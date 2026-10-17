// batch218039.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5a00b0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669acb);  // @h_5a00b0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5a00b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_5a00b0
  if (FL[0] != FL[1]) goto L5a00ee;  // @2_5a00b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1930), sizeof v); (u32)v; });  // @3_5a00b0
  goto L5a00f4;  // @4_5a00b0
  L5a00ee:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1934), sizeof v); (u32)v; });  // @6_5a00b0
  L5a00f4:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @8_5a00b0
  FL[2] = (esi & esi);  // @9_5a00b0
  if (FL[2] != 0) goto L5a0159;  // @10_5a00b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_5a00b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_5a00b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7005856), (u32)(881));  // @13_5a00b0
  ecx = edx = 0;  // @14_5a00b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @15_5a00b0
  edi = eax;  // @16_5a00b0
  eax = (u32)(EBP - 144);  // @17_5a00b0
  ecx = ebx;  // @18_5a00b0
  PV[0] = (u32)(eax);  // @19_5a00b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[0], (u32)(1));  // @20_5a00b0
  ecx = edx = 0;  // @21_5a00b0
  reg.state = (s32)(esi);  // @22_5a00b0
  ecx = eax;  // @23_5a00b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @24_5a00b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @25_5a00b0
  ecx = edx = 0;  // @26_5a00b0
  PV[1] = (u32)(eax);  // @27_5a00b0
  PV[2] = (u32)(edi);  // @28_5a00b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[2], (u32)(7006636), PV[1]);  // @29_5a00b0
  ecx = edx = 0;  // @30_5a00b0
  reg.state = (s32)((u32)(4294967295));  // @31_5a00b0
  ecx = (u32)(EBP - 144);  // @32_5a00b0
  eax = ext_4cbec0_thiscall1(ecx);  // @33_5a00b0
  ecx = edx = 0;  // @34_5a00b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @35_5a00b0
  L5a0159:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_5a00b0
  ecx = ebx;  // @38_5a00b0
  PV[3] = (u32)(esi);  // @39_5a00b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1716), sizeof v); (u32)v; });  // @40_5a00b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[3]);  // @41_5a00b0
  ecx = edx = 0;  // @42_5a00b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @43_5a00b0
  if (FL[2] == 0) goto L5a01be;  // @44_5a00b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @45_5a00b0
  eax = 0;  // @46_5a00b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @47_5a00b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @48_5a00b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @49_5a00b0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @50_5a00b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @51_5a00b0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 4), 4); v; });  // @52_5a00b0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 8), 4); v; });  // @53_5a00b0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 12), 4); v; });  // @54_5a00b0
  PV[4] = (u32)(ecx);  // @55_5a00b0
  ecx = ebx;  // @56_5a00b0
  PV[5] = X0[0];  // @57_5a00b0
  PV[6] = X0[1];  // @58_5a00b0
  PV[7] = X0[2];  // @59_5a00b0
  PV[8] = X0[3];  // @60_5a00b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 1204)))(ecx, (u32)(0), PV[5], PV[6], PV[7], PV[8]);  // @61_5a00b0
  ecx = edx = 0;  // @62_5a00b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @63_5a00b0
  ecx = ebx;  // @64_5a00b0
  PV[9] = (u32)(esi);  // @65_5a00b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1748)))(ecx, PV[9]);  // @66_5a00b0
  ecx = edx = 0;  // @67_5a00b0
  L5a01be:;
  SEH_LEAVE();  // @69_5a00b0
  ext_633654(G(u32, 0x6f5630));  // @70_5a00b0
  return eax;  // @71_5a00b0
}
PCREG(5a00b0, lifted_5a00b0);

