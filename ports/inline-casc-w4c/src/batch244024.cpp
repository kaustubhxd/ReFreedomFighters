// batch244024.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_613690_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_613690");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1440_thiscall2(u32, u32) __asm__("ext_4e1440");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4ef660_thiscall2(u32, u32) __asm__("ext_4ef660");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4f1560(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f1560
  esi = ecx;  // @1_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @2_4f1560
  FL[0] = eax; FL[1] = (u32)(64);  // @3_4f1560
  if ((s32)FL[0] > (s32)FL[1]) goto L4f1667;  // @4_4f1560
  if (FL[0] == FL[1]) goto L4f1652;  // @5_4f1560
  eax = (eax - 1);  // @6_4f1560
  FL[3] = eax;  // @7_4f1560
  FL[0] = eax; FL[1] = (u32)(31);  // @8_4f1560
  if (FL[0] > FL[1]) goto L4f16f6;  // @9_4f1560
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5183308), sizeof v); (u32)v; });  // @10_4f1560
  switch (eax) {  // @11_4f1560
  case 0: goto L4f1597;  // @12_4f1560
  case 1: goto L4f15ac;  // @13_4f1560
  case 2: goto L4f15d8;  // @14_4f1560
  case 3: goto L4f1613;  // @15_4f1560
  case 4: goto L4f1628;  // @16_4f1560
  case 5: goto L4f163d;  // @17_4f1560
  case 6: goto L4f16f6;  // @18_4f1560
  default: __builtin_trap(); }  // @19_4f1560
  L4f1597:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_4f1560
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @22_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 140), sizeof v); (u32)v; });  // @23_4f1560
  eax = ((u32(STDCALL *)(u32))(eax))(PV[0]);  // @24_4f1560
  ecx = edx = 0;  // @25_4f1560
  return eax;  // @26_4f1560
  L4f15ac:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @28_4f1560
  X0[1] = 0;  // @29_4f1560
  X0[2] = 0;  // @30_4f1560
  X0[3] = 0;  // @31_4f1560
  ecx = (u32)(EBP - 8);  // @32_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_4f1560
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @34_4f1560
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @35_4f1560
  X0[1] = 0;  // @36_4f1560
  X0[2] = 0;  // @37_4f1560
  X0[3] = 0;  // @38_4f1560
  PV[1] = (u32)(ecx);  // @39_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @40_4f1560
  ecx = esi;  // @41_4f1560
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @42_4f1560
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[1]);  // @43_4f1560
  ecx = edx = 0;  // @44_4f1560
  return eax;  // @45_4f1560
  L4f15d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_4f1560
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @48_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 152), sizeof v); (u32)v; });  // @49_4f1560
  eax = ((u32(STDCALL *)(u32))(eax))(PV[2]);  // @50_4f1560
  ecx = edx = 0;  // @51_4f1560
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @52_4f1560
  if (FL[2] != 0) goto L4f1606;  // @53_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_4f1560
  ecx = esi;  // @55_4f1560
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @56_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 156), sizeof v); (u32)v; });  // @57_4f1560
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[3]);  // @58_4f1560
  ecx = edx = 0;  // @59_4f1560
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @60_4f1560
  if (FL[2] != 0) goto L4f1606;  // @61_4f1560
  eax = 0;  // @62_4f1560
  FL[3] = eax;  // @63_4f1560
  return eax;  // @64_4f1560
  L4f1606:;
  eax = (u32)(1);  // @66_4f1560
  return eax;  // @67_4f1560
  L4f1613:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @69_4f1560
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @70_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 156), sizeof v); (u32)v; });  // @71_4f1560
  eax = ((u32(STDCALL *)(u32))(eax))(PV[4]);  // @72_4f1560
  ecx = edx = 0;  // @73_4f1560
  return eax;  // @74_4f1560
  L4f1628:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_4f1560
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @77_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; });  // @78_4f1560
  eax = ((u32(STDCALL *)(u32))(eax))(PV[5]);  // @79_4f1560
  ecx = edx = 0;  // @80_4f1560
  return eax;  // @81_4f1560
  L4f163d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @83_4f1560
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @84_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 160), sizeof v); (u32)v; });  // @85_4f1560
  eax = ((u32(STDCALL *)(u32))(eax))(PV[6]);  // @86_4f1560
  ecx = edx = 0;  // @87_4f1560
  return eax;  // @88_4f1560
  L4f1652:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_4f1560
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @91_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 164), sizeof v); (u32)v; });  // @92_4f1560
  eax = ((u32(STDCALL *)(u32))(eax))(PV[7]);  // @93_4f1560
  ecx = edx = 0;  // @94_4f1560
  return eax;  // @95_4f1560
  L4f1667:;
  FL[0] = eax; FL[1] = (u32)(512);  // @97_4f1560
  if ((s32)FL[0] > (s32)FL[1]) goto L4f16e8;  // @98_4f1560
  if (FL[0] == FL[1]) goto L4f16c8;  // @99_4f1560
  FL[0] = eax; FL[1] = (u32)(128);  // @100_4f1560
  if (FL[0] == FL[1]) goto L4f169e;  // @101_4f1560
  FL[0] = eax; FL[1] = (u32)(256);  // @102_4f1560
  if (FL[0] != FL[1]) goto L4f16f6;  // @103_4f1560
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @104_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_4f1560
  { u8 v = (u8)(((FL[0] != FL[1]) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @106_4f1560
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @107_4f1560
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @108_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 172), sizeof v); (u32)v; });  // @109_4f1560
  eax = ((u32(STDCALL *)(u32, u32))(eax))(PV[9], PV[8]);  // @110_4f1560
  ecx = edx = 0;  // @111_4f1560
  return eax;  // @112_4f1560
  L4f169e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_4f1560
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @115_4f1560
  X0[1] = 0;  // @116_4f1560
  X0[2] = 0;  // @117_4f1560
  X0[3] = 0;  // @118_4f1560
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @119_4f1560
  X1[1] = 0;  // @120_4f1560
  X1[2] = 0;  // @121_4f1560
  X1[3] = 0;  // @122_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 168), sizeof v); (u32)v; });  // @123_4f1560
  PV[10] = X0[0];  // @124_4f1560
  PV[11] = X1[0];  // @125_4f1560
  eax = ((u32(STDCALL *)(u32, u32))(eax))(PV[11], PV[10]);  // @126_4f1560
  ecx = edx = 0;  // @127_4f1560
  return eax;  // @128_4f1560
  L4f16c8:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @130_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @131_4f1560
  { u8 v = (u8)(((FL[0] != FL[1]) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @132_4f1560
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @133_4f1560
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @134_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 176), sizeof v); (u32)v; });  // @135_4f1560
  eax = ((u32(STDCALL *)(u32, u32))(eax))(PV[13], PV[12]);  // @136_4f1560
  ecx = edx = 0;  // @137_4f1560
  return eax;  // @138_4f1560
  L4f16e8:;
  FL[0] = eax; FL[1] = (u32)(65536);  // @140_4f1560
  if (FL[0] == FL[1]) goto L4f1718;  // @141_4f1560
  FL[0] = eax; FL[1] = (u32)(1048576);  // @142_4f1560
  if (FL[0] == FL[1]) goto L4f1700;  // @143_4f1560
  L4f16f6:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @145_4f1560
  FL[3] = (eax & 0xff);  // @146_4f1560
  return eax;  // @147_4f1560
  L4f1700:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @149_4f1560
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @150_4f1560
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @151_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 184), sizeof v); (u32)v; });  // @152_4f1560
  eax = ((u32(STDCALL *)(u32, u32))(eax))(PV[15], PV[14]);  // @153_4f1560
  ecx = edx = 0;  // @154_4f1560
  return eax;  // @155_4f1560
  L4f1718:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @157_4f1560
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @158_4f1560
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @159_4f1560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 180), sizeof v); (u32)v; });  // @160_4f1560
  eax = ((u32(STDCALL *)(u32, u32))(eax))(PV[17], PV[16]);  // @161_4f1560
  ecx = edx = 0;  // @162_4f1560
  return eax;  // @163_4f1560
}
PCREG(4f1560, lifted_4f1560);

extern "C" u32 THISCALL lifted_64a880(u32 ecx_in) {
  SEH_ENTER(0x66eb38);  // @h_64a880
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_64a880
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65621), sizeof v); (u32)v; })) & 0xff);  // @1_64a880
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) + 1)) & 0xff);  // @2_64a880
  FL[3] = (ebx & 0xff);  // @3_64a880
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65893), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4_64a880
  if (FL[0] != FL[1]) goto L64a900;  // @5_64a880
  eax = ext_41e290_cdecl1((u32)(20));  // @6_64a880
  ecx = edx = 0;  // @7_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @8_64a880
  FL[2] = (eax & eax);  // @9_64a880
  if (FL[2] == 0) goto L64a8f1;  // @10_64a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @11_64a880
  ecx = (ecx + (u32)(568));  // @12_64a880
  FL[3] = ecx;  // @13_64a880
  { u32 v = (u32)((u32)(7089304)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @14_64a880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @15_64a880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @16_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @17_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @18_64a880
  goto L64a8f3;  // @19_64a880
  L64a8f1:;
  eax = 0;  // @21_64a880
  FL[3] = eax;  // @22_64a880
  L64a8f3:;
  reg.state = (s32)((u32)(4294967295));  // @24_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65893), &v, sizeof v); }  // @25_64a880
  L64a900:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65873), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @27_64a880
  if (FL[0] != FL[1]) goto L64a951;  // @28_64a880
  eax = ext_41e290_cdecl1((u32)(20));  // @29_64a880
  ecx = edx = 0;  // @30_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @31_64a880
  FL[2] = (eax & eax);  // @32_64a880
  if (FL[2] == 0) goto L64a942;  // @33_64a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @34_64a880
  ecx = (ecx + (u32)(568));  // @35_64a880
  FL[3] = ecx;  // @36_64a880
  { u32 v = (u32)((u32)(7089364)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_64a880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @38_64a880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @39_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @40_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @41_64a880
  goto L64a944;  // @42_64a880
  L64a942:;
  eax = 0;  // @44_64a880
  FL[3] = eax;  // @45_64a880
  L64a944:;
  reg.state = (s32)((u32)(4294967295));  // @47_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65873), &v, sizeof v); }  // @48_64a880
  L64a951:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65877), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @50_64a880
  if (FL[0] != FL[1]) goto L64a9a2;  // @51_64a880
  eax = ext_41e290_cdecl1((u32)(20));  // @52_64a880
  ecx = edx = 0;  // @53_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @54_64a880
  FL[2] = (eax & eax);  // @55_64a880
  if (FL[2] == 0) goto L64a993;  // @56_64a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @57_64a880
  ecx = (ecx + (u32)(568));  // @58_64a880
  FL[3] = ecx;  // @59_64a880
  { u32 v = (u32)((u32)(7089424)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @60_64a880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @61_64a880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @62_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @63_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @64_64a880
  goto L64a995;  // @65_64a880
  L64a993:;
  eax = 0;  // @67_64a880
  FL[3] = eax;  // @68_64a880
  L64a995:;
  reg.state = (s32)((u32)(4294967295));  // @70_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65877), &v, sizeof v); }  // @71_64a880
  L64a9a2:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65881), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @73_64a880
  if (FL[0] != FL[1]) goto L64a9f3;  // @74_64a880
  eax = ext_41e290_cdecl1((u32)(20));  // @75_64a880
  ecx = edx = 0;  // @76_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @77_64a880
  FL[2] = (eax & eax);  // @78_64a880
  if (FL[2] == 0) goto L64a9e4;  // @79_64a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @80_64a880
  ecx = (ecx + (u32)(568));  // @81_64a880
  FL[3] = ecx;  // @82_64a880
  { u32 v = (u32)((u32)(7089484)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @83_64a880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @84_64a880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @85_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @86_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @87_64a880
  goto L64a9e6;  // @88_64a880
  L64a9e4:;
  eax = 0;  // @90_64a880
  FL[3] = eax;  // @91_64a880
  L64a9e6:;
  reg.state = (s32)((u32)(4294967295));  // @93_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65881), &v, sizeof v); }  // @94_64a880
  L64a9f3:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @96_64a880
  if (FL[0] != FL[1]) goto L64aa44;  // @97_64a880
  eax = ext_41e290_cdecl1((u32)(20));  // @98_64a880
  ecx = edx = 0;  // @99_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @100_64a880
  FL[2] = (eax & eax);  // @101_64a880
  if (FL[2] == 0) goto L64aa35;  // @102_64a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @103_64a880
  ecx = (ecx + (u32)(568));  // @104_64a880
  FL[3] = ecx;  // @105_64a880
  { u32 v = (u32)((u32)(7089544)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @106_64a880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @107_64a880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @108_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @109_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @110_64a880
  goto L64aa37;  // @111_64a880
  L64aa35:;
  eax = 0;  // @113_64a880
  FL[3] = eax;  // @114_64a880
  L64aa37:;
  reg.state = (s32)((u32)(4294967295));  // @116_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65885), &v, sizeof v); }  // @117_64a880
  L64aa44:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65889), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @119_64a880
  if (FL[0] != FL[1]) goto L64aa95;  // @120_64a880
  eax = ext_41e290_cdecl1((u32)(20));  // @121_64a880
  ecx = edx = 0;  // @122_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @123_64a880
  FL[2] = (eax & eax);  // @124_64a880
  if (FL[2] == 0) goto L64aa86;  // @125_64a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @126_64a880
  ecx = (ecx + (u32)(568));  // @127_64a880
  FL[3] = ecx;  // @128_64a880
  { u32 v = (u32)((u32)(7089604)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @129_64a880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @130_64a880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @131_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @132_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @133_64a880
  goto L64aa88;  // @134_64a880
  L64aa86:;
  eax = 0;  // @136_64a880
  FL[3] = eax;  // @137_64a880
  L64aa88:;
  reg.state = (s32)((u32)(4294967295));  // @139_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65889), &v, sizeof v); }  // @140_64a880
  L64aa95:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65897), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @142_64a880
  if (FL[0] != FL[1]) goto L64aae6;  // @143_64a880
  eax = ext_41e290_cdecl1((u32)(20));  // @144_64a880
  ecx = edx = 0;  // @145_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @146_64a880
  FL[2] = (eax & eax);  // @147_64a880
  if (FL[2] == 0) goto L64aad7;  // @148_64a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @149_64a880
  ecx = (ecx + (u32)(568));  // @150_64a880
  FL[3] = ecx;  // @151_64a880
  { u32 v = (u32)((u32)(7089664)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @152_64a880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @153_64a880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @154_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @155_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @156_64a880
  goto L64aad9;  // @157_64a880
  L64aad7:;
  eax = 0;  // @159_64a880
  FL[3] = eax;  // @160_64a880
  L64aad9:;
  reg.state = (s32)((u32)(4294967295));  // @162_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65897), &v, sizeof v); }  // @163_64a880
  L64aae6:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65901), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @165_64a880
  if (FL[0] != FL[1]) goto L64ab30;  // @166_64a880
  eax = ext_41e290_cdecl1((u32)(20));  // @167_64a880
  ecx = edx = 0;  // @168_64a880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @169_64a880
  FL[2] = (eax & eax);  // @170_64a880
  if (FL[2] == 0) goto L64ab28;  // @171_64a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @172_64a880
  ecx = (ecx + (u32)(568));  // @173_64a880
  FL[3] = ecx;  // @174_64a880
  { u32 v = (u32)((u32)(7089724)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @175_64a880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @176_64a880
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @177_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @178_64a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @179_64a880
  goto L64ab2a;  // @180_64a880
  L64ab28:;
  eax = 0;  // @182_64a880
  FL[3] = eax;  // @183_64a880
  L64ab2a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65901), &v, sizeof v); }  // @185_64a880
  L64ab30:;
  SEH_LEAVE();  // @187_64a880
  return eax;  // @188_64a880
}
PCREG(64a880, lifted_64a880);

extern "C" u32 THISCALL lifted_612a20(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_612a20
  esi = ecx;  // @1_612a20
  ecx = ebx;  // @2_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139312), sizeof v); (u32)v; });  // @3_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @4_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @6_612a20
  ecx = edx = 0;  // @7_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @9_612a20
  ecx = (u32)(eax - 1);  // @10_612a20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 147), sizeof v); (u32)v; });  // @11_612a20
  FL[0] = ecx; FL[1] = edi;  // @12_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_612a20
  if (FL[0] < FL[1]) edi = ecx;  // @14_612a20
  ecx = ebx;  // @15_612a20
  PV[0] = (u32)(edi);  // @16_612a20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @17_612a20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 56)))(ecx, PV[0]);  // @18_612a20
  ecx = edx = 0;  // @19_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139268), sizeof v); (u32)v; });  // @20_612a20
  ecx = (u32)(EBP - 8);  // @21_612a20
  PV[1] = (u32)(ecx);  // @22_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @23_612a20
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @24_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @25_612a20
  ecx = (ecx - edi);  // @26_612a20
  FL[3] = ecx;  // @27_612a20
  PV[3] = (u32)(ecx);  // @28_612a20
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @29_612a20
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @30_612a20
  PV[6] = (u32)(edx);  // @31_612a20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 80)))(ecx, PV[6], PV[5], PV[4], PV[3], (u32)(0), PV[2], (u32)(1), PV[1]);  // @32_612a20
  ecx = edx = 0;  // @33_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @34_612a20
  ecx = ebx;  // @35_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @36_612a20
  ecx = edx = 0;  // @37_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @38_612a20
  ecx = ebx;  // @39_612a20
  esi = eax;  // @40_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 28)))(ecx);  // @41_612a20
  ecx = edx = 0;  // @42_612a20
  eax = (u32)((s32)eax * (s32)esi);  // @43_612a20
  FL[3] = eax;  // @44_612a20
  ecx = 0;  // @45_612a20
  FL[3] = ecx;  // @46_612a20
  edx = (u32)(4);  // @47_612a20
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @48_612a20
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @49_612a20
  FL[1] = ecx;  // @50_612a20
  ecx = (0u - ecx);  // @51_612a20
  ecx = (ecx | eax);  // @52_612a20
  FL[3] = ecx;  // @53_612a20
  PV[7] = (u32)(ecx);  // @54_612a20
  eax = ext_41e290_cdecl1(PV[7]);  // @55_612a20
  ecx = edx = 0;  // @56_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_612a20
  ecx = ebx;  // @58_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @59_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @60_612a20
  ecx = edx = 0;  // @61_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_612a20
  ecx = ebx;  // @63_612a20
  esi = eax;  // @64_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 28)))(ecx);  // @65_612a20
  ecx = edx = 0;  // @66_612a20
  eax = (u32)((s32)eax * (s32)esi);  // @67_612a20
  FL[3] = eax;  // @68_612a20
  ecx = 0;  // @69_612a20
  FL[3] = ecx;  // @70_612a20
  edx = (u32)(4);  // @71_612a20
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @72_612a20
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @73_612a20
  FL[1] = ecx;  // @74_612a20
  ecx = (0u - ecx);  // @75_612a20
  ecx = (ecx | eax);  // @76_612a20
  FL[3] = ecx;  // @77_612a20
  PV[8] = (u32)(ecx);  // @78_612a20
  eax = ext_41e290_cdecl1(PV[8]);  // @79_612a20
  ecx = edx = 0;  // @80_612a20
  esi = eax;  // @81_612a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @82_612a20
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @83_612a20
  if (FL[0] >= FL[1]) goto L612bd6;  // @84_612a20
  esi = 0;  // @85_612a20
  FL[3] = esi;  // @86_612a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @87_612a20
  L612af1:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @89_612a20
  ecx = ebx;  // @90_612a20
  PV[9] = (u32)(edi);  // @91_612a20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 56)))(ecx, PV[9]);  // @92_612a20
  ecx = edx = 0;  // @93_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @94_612a20
  ebx = eax;  // @95_612a20
  eax = (u32)(EBP - 44);  // @96_612a20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @97_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_612a20
  PV[10] = (u32)(eax);  // @99_612a20
  PV[11] = (u32)(esi);  // @100_612a20
  PV[12] = (u32)(ecx);  // @101_612a20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[12], PV[11], PV[10], (u32)(0), (u32)(0));  // @102_612a20
  ecx = edx = 0;  // @103_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @104_612a20
  edx = (u32)(EBP - 92);  // @105_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @106_612a20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7067808) + 0), 4); v; });  // @107_612a20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7067808) + 4), 4); v; });  // @108_612a20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7067808) + 8), 4); v; });  // @109_612a20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7067808) + 12), 4); v; });  // @110_612a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @111_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @112_612a20
  eax = (eax << (u32)(2));  // @113_612a20
  FL[3] = eax;  // @114_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @115_612a20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @116_612a20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @117_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @118_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @119_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @120_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @121_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_612a20
  PV[13] = (u32)(edi);  // @123_612a20
  PV[14] = (u32)(edx);  // @124_612a20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @125_612a20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 4), &X0[1], 4);  // @126_612a20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 8), &X0[2], 4);  // @127_612a20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 12), &X0[3], 4);  // @128_612a20
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @129_612a20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @130_612a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[14], PV[13]);  // @131_612a20
  ecx = edx = 0;  // @132_612a20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @133_612a20
  edx = esi;  // @134_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @135_612a20
  ecx = esi;  // @136_612a20
  PV[15] = (u32)(edi);  // @137_612a20
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @138_612a20
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @139_612a20
  eax = ext_613690_fastcall5(ecx, edx, PV[17], PV[16], PV[15]);  // @140_612a20
  ecx = edx = 0;  // @141_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @142_612a20
  eax = (eax + eax);  // @143_612a20
  FL[3] = eax;  // @144_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @145_612a20
  FL[0] = edi; FL[1] = (u32)(62);  // @146_612a20
  if (FL[0] != FL[1]) goto L612b84;  // @147_612a20
  eax = (eax + eax);  // @148_612a20
  FL[3] = eax;  // @149_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @150_612a20
  L612b84:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @152_612a20
  edi = esi;  // @153_612a20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @154_612a20
  esi = 0;  // @155_612a20
  FL[3] = esi;  // @156_612a20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }); FL[1] = esi;  // @157_612a20
  if ((s32)FL[0] <= (s32)FL[1]) goto L612baf;  // @158_612a20
  L612b93:;
  PV[18] = (u32)(eax);  // @160_612a20
  PV[19] = (u32)(edi);  // @161_612a20
  PV[20] = (u32)(ebx);  // @162_612a20
  eax = ext_634d22_cdecl3(PV[20], PV[19], PV[18]);  // @163_612a20
    // @164_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @165_612a20
  esi = (esi + 1);  // @166_612a20
  FL[3] = esi;  // @167_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @168_612a20
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; }));  // @169_612a20
  FL[3] = ebx;  // @170_612a20
  edi = (edi + eax);  // @171_612a20
  FL[3] = edi;  // @172_612a20
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @173_612a20
  if ((s32)FL[0] < (s32)FL[1]) goto L612b93;  // @174_612a20
  L612baf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @176_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @177_612a20
  PV[21] = (u32)(esi);  // @178_612a20
  PV[22] = (u32)(eax);  // @179_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @180_612a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 68)))(ecx, PV[22], PV[21]);  // @181_612a20
  ecx = edx = 0;  // @182_612a20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @183_612a20
  esi = (esi + 1);  // @184_612a20
  FL[3] = esi;  // @185_612a20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @186_612a20
  edi = (edi + 1);  // @187_612a20
  FL[3] = edi;  // @188_612a20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @189_612a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @190_612a20
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @191_612a20
  if (FL[0] < FL[1]) goto L612af1;  // @192_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @193_612a20
  L612bd6:;
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @195_612a20
  eax = ext_634273_cdecl2(PV[23], (u32)(4));  // @196_612a20
  ecx = edx = 0;  // @197_612a20
  PV[24] = (u32)(esi);  // @198_612a20
  eax = ext_634273_cdecl2(PV[24], (u32)(4));  // @199_612a20
  ecx = edx = 0;  // @200_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @201_612a20
  return eax;  // @202_612a20
}
PCREG(612a20, lifted_612a20);

extern "C" u32 THISCALL lifted_4ef3f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66988b);  // @h_4ef3f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4ef3f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @1_4ef3f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4ef3f0
  PV[0] = (u32)(edi);  // @3_4ef3f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @4_4ef3f0
  eax = ext_4ef660_thiscall2(ecx, PV[0]);  // @5_4ef3f0
  ecx = edx = 0;  // @6_4ef3f0
  eax = (u32)(EBP - 160);  // @7_4ef3f0
  ecx = edi;  // @8_4ef3f0
  PV[1] = (u32)(eax);  // @9_4ef3f0
  eax = ext_4e1440_thiscall2(ecx, PV[1]);  // @10_4ef3f0
  ecx = edx = 0;  // @11_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 155), sizeof v); (u32)v; });  // @12_4ef3f0
  FL[2] = (edx & edx);  // @13_4ef3f0
  if (FL[2] == 0) goto L4ef45c;  // @14_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4ef3f0
  PV[2] = (u32)(edx);  // @16_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, PV[2]);  // @18_4ef3f0
  ecx = edx = 0;  // @19_4ef3f0
  L4ef45c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @21_4ef3f0
  ecx = (u32)(6915152);  // @22_4ef3f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @23_4ef3f0
  eax = edx;  // @24_4ef3f0
  L4ef473:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @26_4ef3f0
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4ef3f0
  if (FL[0] != FL[1]) goto L4ef493;  // @28_4ef3f0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @29_4ef3f0
  if (FL[2] == 0) goto L4ef48f;  // @30_4ef3f0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @31_4ef3f0
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @32_4ef3f0
  if (FL[0] != FL[1]) goto L4ef493;  // @33_4ef3f0
  eax = (eax + (u32)(2));  // @34_4ef3f0
  FL[3] = eax;  // @35_4ef3f0
  ecx = (ecx + (u32)(2));  // @36_4ef3f0
  FL[3] = ecx;  // @37_4ef3f0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @38_4ef3f0
  if (FL[2] != 0) goto L4ef473;  // @39_4ef3f0
  L4ef48f:;
  eax = 0;  // @41_4ef3f0
  FL[3] = eax;  // @42_4ef3f0
  goto L4ef498;  // @43_4ef3f0
  L4ef493:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @45_4ef3f0
  eax = (eax | (u32)(1));  // @46_4ef3f0
  FL[3] = eax;  // @47_4ef3f0
  L4ef498:;
  FL[2] = (eax & eax);  // @49_4ef3f0
  if (FL[2] != 0) goto L4ef4d7;  // @50_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; });  // @51_4ef3f0
  FL[0] = eax; FL[1] = (u32)(55);  // @52_4ef3f0
  if (FL[0] == FL[1]) goto L4ef4ac;  // @53_4ef3f0
  FL[0] = eax; FL[1] = (u32)(56);  // @54_4ef3f0
  if (FL[0] != FL[1]) goto L4ef4d7;  // @55_4ef3f0
  L4ef4ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 248)))(ecx, (u32)(35));  // @59_4ef3f0
  ecx = edx = 0;  // @60_4ef3f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @61_4ef3f0
  edx = (u32)(6915192);  // @62_4ef3f0
  L4ef4c7:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @64_4ef3f0
  edx = (u32)(edx + 1);  // @65_4ef3f0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @66_4ef3f0
  eax = (u32)(eax + 1);  // @67_4ef3f0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @68_4ef3f0
  if (FL[2] != 0) goto L4ef4c7;  // @69_4ef3f0
  goto L4ef51e;  // @70_4ef3f0
  L4ef4d7:;
  ecx = (u32)(edx + 1);  // @72_4ef3f0
  L4ef4e0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @74_4ef3f0
  edx = (edx + 1);  // @75_4ef3f0
  FL[3] = edx;  // @76_4ef3f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @77_4ef3f0
  if (FL[2] != 0) goto L4ef4e0;  // @78_4ef3f0
  edx = (edx - ecx);  // @79_4ef3f0
  FL[3] = edx;  // @80_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_4ef3f0
  eax = (u32)(edx + 1);  // @82_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_4ef3f0
  eax = (eax & 0xffff);  // @84_4ef3f0
  PV[3] = (u32)(eax);  // @85_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, PV[3]);  // @86_4ef3f0
  ecx = edx = 0;  // @87_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @88_4ef3f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @89_4ef3f0
  L4ef510:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @91_4ef3f0
  edx = (u32)(edx + 1);  // @92_4ef3f0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @93_4ef3f0
  eax = (u32)(eax + 1);  // @94_4ef3f0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @95_4ef3f0
  if (FL[2] != 0) goto L4ef510;  // @96_4ef3f0
  L4ef51e:;
  eax = (u32)(EBP - 164);  // @98_4ef3f0
  ecx = edi;  // @99_4ef3f0
  PV[4] = (u32)(eax);  // @100_4ef3f0
  eax = ext_4e12e0_thiscall3(ecx, PV[4], (u32)(1));  // @101_4ef3f0
    // @102_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @103_4ef3f0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @104_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @105_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[5]);  // @107_4ef3f0
  ecx = edx = 0;  // @108_4ef3f0
  FL[2] = (eax & eax);  // @109_4ef3f0
  if (FL[2] == 0) goto L4ef555;  // @110_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @111_4ef3f0
  ecx = esi;  // @112_4ef3f0
  PV[6] = (u32)(eax);  // @113_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 636)))(ecx, PV[6]);  // @114_4ef3f0
  ecx = edx = 0;  // @115_4ef3f0
  goto L4ef5c0;  // @116_4ef3f0
  L4ef555:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @118_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6912796), (u32)(1312));  // @120_4ef3f0
  ecx = edx = 0;  // @121_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @122_4ef3f0
  edi = eax;  // @123_4ef3f0
  eax = (u32)(EBP - 156);  // @124_4ef3f0
  ecx = esi;  // @125_4ef3f0
  PV[7] = (u32)(eax);  // @126_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[7], (u32)(1));  // @127_4ef3f0
  ecx = edx = 0;  // @128_4ef3f0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @129_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @130_4ef3f0
  ecx = eax;  // @131_4ef3f0
  reg.state = (s32)((u32)(0));  // @132_4ef3f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @133_4ef3f0
    // @134_4ef3f0
  PV[9] = (u32)(eax);  // @135_4ef3f0
  PV[10] = (u32)(edi);  // @136_4ef3f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[10], (u32)(6915228), PV[9], PV[8]);  // @137_4ef3f0
  ecx = edx = 0;  // @138_4ef3f0
  reg.state = (s32)((u32)(4294967295));  // @139_4ef3f0
  ecx = (u32)(EBP - 156);  // @140_4ef3f0
  eax = ext_4cbec0_thiscall1(ecx);  // @141_4ef3f0
  ecx = edx = 0;  // @142_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @143_4ef3f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @144_4ef3f0
  L4ef5c0:;
  eax = (u32)(EBP - 28);  // @146_4ef3f0
  ecx = edi;  // @147_4ef3f0
  PV[11] = (u32)(eax);  // @148_4ef3f0
  eax = ext_4e12f0_thiscall3(ecx, PV[11], (u32)(3));  // @149_4ef3f0
  ecx = edx = 0;  // @150_4ef3f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; });  // @151_4ef3f0
  X1[1] = 0;  // @152_4ef3f0
  X1[2] = 0;  // @153_4ef3f0
  X1[3] = 0;  // @154_4ef3f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @155_4ef3f0
  X0[1] = 0;  // @156_4ef3f0
  X0[2] = 0;  // @157_4ef3f0
  X0[3] = 0;  // @158_4ef3f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @159_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @161_4ef3f0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6915412) + 0), 4); v; })));  // @162_4ef3f0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); edx = (u32)r_; }  // @163_4ef3f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @164_4ef3f0
  X0[1] = 0;  // @165_4ef3f0
  X0[2] = 0;  // @166_4ef3f0
  X0[3] = 0;  // @167_4ef3f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @168_4ef3f0
  edx = (edx & (u32)(16711680));  // @169_4ef3f0
  FL[3] = edx;  // @170_4ef3f0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @171_4ef3f0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @172_4ef3f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @173_4ef3f0
  X0[1] = 0;  // @174_4ef3f0
  X0[2] = 0;  // @175_4ef3f0
  X0[3] = 0;  // @176_4ef3f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @177_4ef3f0
  eax = (eax & 0xff);  // @178_4ef3f0
  edx = (edx | eax);  // @179_4ef3f0
  FL[3] = edx;  // @180_4ef3f0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6915408) + 0), 4); v; })));  // @181_4ef3f0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @182_4ef3f0
  eax = (eax & (u32)(65280));  // @183_4ef3f0
  FL[3] = eax;  // @184_4ef3f0
  edx = (edx | eax);  // @185_4ef3f0
  FL[3] = edx;  // @186_4ef3f0
  PV[12] = (u32)(edx);  // @187_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 584)))(ecx, PV[12]);  // @188_4ef3f0
  ecx = edx = 0;  // @189_4ef3f0
  ecx = edi;  // @190_4ef3f0
  eax = ext_4e1b30_thiscall1(ecx);  // @191_4ef3f0
  ecx = edx = 0;  // @192_4ef3f0
  SEH_LEAVE();  // @193_4ef3f0
  ext_633654(G(u32, 0x6f5630));  // @194_4ef3f0
  return eax;  // @195_4ef3f0
}
PCREG(4ef3f0, lifted_4ef3f0);

