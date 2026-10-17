// batch218038.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4613a0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x669acb);  // @h_4613a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ecx;  // @0_4613a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4613a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @2_4613a0
  X0[1] = 0;  // @3_4613a0
  X0[2] = 0;  // @4_4613a0
  X0[3] = 0;  // @5_4613a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_4613a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @7_4613a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_4613a0
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X0[0], 4);  // @9_4613a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @10_4613a0
  X0[1] = 0;  // @11_4613a0
  X0[2] = 0;  // @12_4613a0
  X0[3] = 0;  // @13_4613a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @14_4613a0
  PV[0] = (u32)(ecx);  // @15_4613a0
  ecx = ebx;  // @16_4613a0
  __builtin_memcpy((void *)((u32)(EBP - 152) + 0), &X0[0], 4);  // @17_4613a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[0]);  // @18_4613a0
  ecx = edx = 0;  // @19_4613a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @20_4613a0
  FL[2] = (eax & eax);  // @21_4613a0
  if (FL[2] != 0) goto L461470;  // @22_4613a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @23_4613a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4613a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6838324), (u32)(1397));  // @25_4613a0
  ecx = edx = 0;  // @26_4613a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @27_4613a0
  edi = eax;  // @28_4613a0
  eax = (u32)(EBP - 144);  // @29_4613a0
  ecx = ebx;  // @30_4613a0
  PV[1] = (u32)(eax);  // @31_4613a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[1], (u32)(1));  // @32_4613a0
  ecx = edx = 0;  // @33_4613a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_4613a0
  ecx = eax;  // @35_4613a0
  reg.state = (s32)((u32)(0));  // @36_4613a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @37_4613a0
  ecx = edx = 0;  // @38_4613a0
  PV[2] = (u32)(eax);  // @39_4613a0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @40_4613a0
  PV[4] = (u32)(edi);  // @41_4613a0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[4], (u32)(6838660), PV[3], PV[2]);  // @42_4613a0
  ecx = edx = 0;  // @43_4613a0
  reg.state = (s32)((u32)(4294967295));  // @44_4613a0
  ecx = (u32)(EBP - 144);  // @45_4613a0
  eax = ext_4cbec0_thiscall1(ecx);  // @46_4613a0
  ecx = edx = 0;  // @47_4613a0
  L461470:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; });  // @49_4613a0
  X0[1] = 0;  // @50_4613a0
  X0[2] = 0;  // @51_4613a0
  X0[3] = 0;  // @52_4613a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @53_4613a0
  ecx = ebx;  // @54_4613a0
  PV[5] = X0[0];  // @55_4613a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 156) + 0), 4); v; });  // @56_4613a0
  X0[1] = 0;  // @57_4613a0
  X0[2] = 0;  // @58_4613a0
  X0[3] = 0;  // @59_4613a0
  PV[6] = X0[0];  // @60_4613a0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @61_4613a0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @62_4613a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 552)))(ecx, PV[8], PV[7], PV[6], PV[5], (u32)(1065353216));  // @63_4613a0
  ecx = edx = 0;  // @64_4613a0
  SEH_LEAVE();  // @65_4613a0
  ext_633654(G(u32, 0x6f5630));  // @66_4613a0
  return eax;  // @67_4613a0
}
PCREG(4613a0, lifted_4613a0);

