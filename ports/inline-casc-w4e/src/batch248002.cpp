// batch248002.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 THISCALL ext_4db1f0_thiscall2(u32, u32) __asm__("ext_4db1f0");
extern "C" u32 THISCALL ext_5f0af0_thiscall3(u32, u32, u32) __asm__("ext_5f0af0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_462f80(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xff);  // @0_462f80
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @1_462f80
  if (FL[2] != 0) goto L462f93;  // @2_462f80
  L462f8b:;
  eax = (eax | (u32)(4294967295));  // @4_462f80
  FL[3] = eax;  // @5_462f80
  return eax;  // @6_462f80
  L462f93:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @8_462f80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @9_462f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_462f80
  PV[0] = (u32)(edx);  // @11_462f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @12_462f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @13_462f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_462f80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 200)))(ecx, PV[0]);  // @15_462f80
  ecx = edx = 0;  // @16_462f80
  ecx = (ebx & 0xff);  // @17_462f80
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; })) & 0xff);  // @18_462f80
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @19_462f80
  if (FL[0] == FL[1]) goto L462f8b;  // @20_462f80
  eax = (eax & 0xff);  // @21_462f80
  return eax;  // @22_462f80
}
PCREG(462f80, lifted_462f80);

extern "C" u32 THISCALL lifted_5f0700(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 128), sizeof v); (u32)v; });  // @0_5f0700
  ecx = (ecx + (u32)(124));  // @1_5f0700
  FL[3] = ecx;  // @2_5f0700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_5f0700
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @4_5f0700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @5_5f0700
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @6_5f0700
  if (FL[0] == FL[1]) goto L5f073e;  // @7_5f0700
  FL[2] = (edx & edx);  // @8_5f0700
  if (FL[2] == 0) goto L5f0734;  // @9_5f0700
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @10_5f0700
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 4), 4); v; });  // @11_5f0700
  X0[2] = 0;  // @12_5f0700
  X0[3] = 0;  // @13_5f0700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @14_5f0700
  __builtin_memcpy((void *)((u32)(edx) + 0), &X0[0], 4);  // @15_5f0700
  __builtin_memcpy((void *)((u32)(edx) + 4), &X0[1], 4);  // @16_5f0700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @17_5f0700
  L5f0734:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @19_5f0700
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @20_5f0700
  return eax;  // @21_5f0700
  L5f073e:;
  eax = (u32)(EBP - 12);  // @23_5f0700
  PV[0] = (u32)(eax);  // @24_5f0700
  PV[1] = (u32)(edx);  // @25_5f0700
  eax = ext_5f0af0_thiscall3(ecx, PV[1], PV[0]);  // @26_5f0700
  ecx = edx = 0;  // @27_5f0700
  return eax;  // @28_5f0700
}
PCREG(5f0700, lifted_5f0700);

extern "C" u32 THISCALL lifted_4dceb0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4dceb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @1_4dceb0
  FL[2] = (edi & edi);  // @2_4dceb0
  if (FL[2] == 0) goto L4dcf69;  // @3_4dceb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4dceb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @5_4dceb0
  X0[1] = 0;  // @6_4dceb0
  X0[2] = 0;  // @7_4dceb0
  X0[3] = 0;  // @8_4dceb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @9_4dceb0
  X1[1] = 0;  // @10_4dceb0
  X1[2] = 0;  // @11_4dceb0
  X1[3] = 0;  // @12_4dceb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @13_4dceb0
  X2[1] = 0;  // @14_4dceb0
  X2[2] = 0;  // @15_4dceb0
  X2[3] = 0;  // @16_4dceb0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @17_4dceb0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @18_4dceb0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @19_4dceb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @20_4dceb0
  FL[2] = (ecx & ecx);  // @21_4dceb0
  if (FL[2] == 0) goto L4dcf23;  // @22_4dceb0
  eax = (u32)(EBP - 16);  // @23_4dceb0
  PV[0] = (u32)(eax);  // @24_4dceb0
  eax = ext_4db1f0_thiscall2(ecx, PV[0]);  // @25_4dceb0
  ecx = edx = 0;  // @26_4dceb0
  edx = (u32)(edi + 36);  // @27_4dceb0
  ecx = (u32)(EBP - 16);  // @28_4dceb0
  eax = ext_43e960_fastcall2(ecx, edx);  // @29_4dceb0
  ecx = edx = 0;  // @30_4dceb0
  edx = edi;  // @31_4dceb0
  ecx = (u32)(EBP - 16);  // @32_4dceb0
  eax = ext_441a60_fastcall2(ecx, edx);  // @33_4dceb0
  ecx = edx = 0;  // @34_4dceb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @35_4dceb0
  X2[1] = 0;  // @36_4dceb0
  X2[2] = 0;  // @37_4dceb0
  X2[3] = 0;  // @38_4dceb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @39_4dceb0
  X1[1] = 0;  // @40_4dceb0
  X1[2] = 0;  // @41_4dceb0
  X1[3] = 0;  // @42_4dceb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @43_4dceb0
  X0[1] = 0;  // @44_4dceb0
  X0[2] = 0;  // @45_4dceb0
  X0[3] = 0;  // @46_4dceb0
  L4dcf23:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @48_4dceb0
  ecx = (u32)(EBP - 16);  // @49_4dceb0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4dceb0
  if (FL[0] != FL[1]) goto L4dcf3d;  // @51_4dceb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @52_4dceb0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @53_4dceb0
  if (FL[0] != FL[1]) goto L4dcf3d;  // @54_4dceb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @55_4dceb0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @56_4dceb0
  if (FL[0] == FL[1]) goto L4dcf69;  // @57_4dceb0
  L4dcf3d:;
  __builtin_memcpy((void *)((u32)(esi + 36) + 0), &X0[0], 4);  // @59_4dceb0
  __builtin_memcpy((void *)((u32)(esi + 40) + 0), &X1[0], 4);  // @60_4dceb0
  __builtin_memcpy((void *)((u32)(esi + 44) + 0), &X2[0], 4);  // @61_4dceb0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) | (u32)(1048576))); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @62_4dceb0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @63_4dceb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @64_4dceb0
  PV[1] = (u32)(esi);  // @65_4dceb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @66_4dceb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23857), sizeof v); (u32)v; });  // @67_4dceb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_4dceb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[1]);  // @69_4dceb0
  ecx = edx = 0;  // @70_4dceb0
  L4dcf69:;
  ext_633654(G(u32, 0x6f5630));  // @72_4dceb0
  return eax;  // @73_4dceb0
}
PCREG(4dceb0, lifted_4dceb0);

