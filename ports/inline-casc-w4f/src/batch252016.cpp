// batch252016.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_420a60_thiscall1(u32) __asm__("ext_420a60");
extern "C" u32 THISCALL ext_48c4b0_thiscall3(u32, u32, u32) __asm__("ext_48c4b0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_420a60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_420a60
  PV[0] = (u32)(ebx);  // @1_420a60
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760d8))(PV[0]);  // @2_420a60
  ecx = edx = 0;  // @3_420a60
  FL[0] = eax; FL[1] = (u32)(-1);  // @4_420a60
  if (FL[0] == FL[1]) goto L420a77;  // @5_420a60
  FL[2] = ((eax & 0xff) & (u32)(16));  // @6_420a60
  if (FL[2] != 0) goto L420ad9;  // @7_420a60
  L420a77:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @9_420a60
  PV[1] = (u32)(ebx);  // @10_420a60
  eax = ((u32( *)(u32, u32))(esi))(PV[1], (u32)(92));  // @11_420a60
  ecx = edx = 0;  // @12_420a60
  PV[2] = (u32)(ebx);  // @13_420a60
  edi = eax;  // @14_420a60
  eax = ((u32( *)(u32, u32))(esi))(PV[2], (u32)(92));  // @15_420a60
  ecx = edx = 0;  // @16_420a60
  eax = (eax - ebx);  // @17_420a60
  FL[3] = eax;  // @18_420a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @19_420a60
  FL[2] = (edi & edi);  // @20_420a60
  if (FL[2] == 0) goto L420ace;  // @21_420a60
  FL[0] = eax; FL[1] = (u32)(2);  // @22_420a60
  if (FL[0] == FL[1]) goto L420ace;  // @23_420a60
  ecx = (u32)(eax + 1);  // @24_420a60
  PV[3] = (u32)(ecx);  // @25_420a60
  eax = ext_41e290_cdecl1(PV[3]);  // @26_420a60
  ecx = edx = 0;  // @27_420a60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @28_420a60
  esi = eax;  // @29_420a60
  PV[4] = (u32)(edi);  // @30_420a60
  PV[5] = (u32)(ebx);  // @31_420a60
  PV[6] = (u32)(esi);  // @32_420a60
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x67642c))(PV[6], PV[5], PV[4]);  // @33_420a60
  ecx = edx = 0;  // @34_420a60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @35_420a60
  FL[2] = (esi & esi);  // @36_420a60
  if (FL[2] == 0) goto L420ace;  // @37_420a60
  ecx = esi;  // @38_420a60
  eax = ext_420a60_thiscall1(ecx);  // @39_420a60
  ecx = edx = 0;  // @40_420a60
  PV[7] = (u32)(esi);  // @41_420a60
  eax = ext_41e2c0_cdecl1(PV[7]);  // @42_420a60
  ecx = edx = 0;  // @43_420a60
  L420ace:;
  PV[8] = (u32)(ebx);  // @45_420a60
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760d4))(PV[8], (u32)(0));  // @46_420a60
  ecx = edx = 0;  // @47_420a60
  L420ad9:;
  return eax;  // @49_420a60
}
PCREG(420a60, lifted_420a60);

extern "C" u32 THISCALL lifted_491140(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664d1b);  // @h_491140
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_491140
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_491140
  PV[0] = (u32)(ecx);  // @3_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @4_491140
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(2), (u32)(0), (u32)(0));  // @5_491140
  ecx = edx = 0;  // @6_491140
  eax = (u32)(EBP - 144);  // @7_491140
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @8_491140
  PV[1] = (u32)(eax);  // @9_491140
  ecx = ebx;  // @10_491140
  eax = ext_48c4b0_thiscall3(ecx, PV[1], (u32)(6871120));  // @11_491140
  ecx = edx = 0;  // @12_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @13_491140
  ecx = (u32)(EBP - 144);  // @14_491140
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @15_491140
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_491140
  PV[3] = (u32)(edi);  // @17_491140
  reg.state = (s32)((u32)(0));  // @18_491140
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_491140
    // @20_491140
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @21_491140
  PV[4] = (u32)(eax);  // @22_491140
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, PV[4], PV[3], PV[2], (u32)(0), (u32)(0));  // @23_491140
  ecx = edx = 0;  // @24_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_491140
  PV[5] = (u32)(ecx);  // @26_491140
  ecx = ebx;  // @27_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @28_491140
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(2), (u32)(0), (u32)(1041865114));  // @29_491140
  ecx = edx = 0;  // @30_491140
  ecx = (u32)(EBP - 144);  // @31_491140
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @32_491140
  eax = ext_4cbec0_thiscall1(ecx);  // @33_491140
  ecx = edx = 0;  // @34_491140
  SEH_LEAVE();  // @35_491140
  ext_633654(G(u32, 0x6f5630));  // @36_491140
  return eax;  // @37_491140
}
PCREG(491140, lifted_491140);

extern "C" u32 THISCALL lifted_4269e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6685bb);  // @h_4269e0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
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

