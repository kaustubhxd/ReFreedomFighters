// batch218007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_430620_fastcall4(u32, u32, u32, u32) __asm__("ext_430620");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_430010_thiscall2(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4e5000_thiscall1(u32) __asm__("ext_4e5000");
extern "C" u32 THISCALL ext_4e8450_thiscall2(u32, u32) __asm__("ext_4e8450");
extern "C" u32 THISCALL ext_5eaab0_thiscall3(u32, u32, u32) __asm__("ext_5eaab0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5fad90_thiscall1(u32) __asm__("ext_5fad90");
extern "C" u32 THISCALL ext_5fb110_thiscall2(u32, u32) __asm__("ext_5fb110");
extern "C" u32 THISCALL ext_5fb370_thiscall2(u32, u32) __asm__("ext_5fb370");
extern "C" u32 THISCALL ext_5fb980_thiscall3(u32, u32, u32) __asm__("ext_5fb980");
extern "C" u32 THISCALL ext_602290_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_602290");
extern "C" u32 THISCALL ext_602530_thiscall1(u32) __asm__("ext_602530");
extern "C" u32 THISCALL ext_61bbd0_thiscall1(u32) __asm__("ext_61bbd0");
extern "C" u32 THISCALL ext_61bbe0_thiscall1(u32) __asm__("ext_61bbe0");
extern "C" u32 THISCALL ext_61bbf0_thiscall4(u32, u32, u32, u32) __asm__("ext_61bbf0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_45cc40(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6666bc);  // @h_45cc40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_45cc40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_45cc40
  ecx = (u32)(EBP - 144);  // @2_45cc40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @3_45cc40
  eax = ext_4cbeb0_thiscall1(ecx);  // @4_45cc40
  ecx = edx = 0;  // @5_45cc40
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_45cc40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_45cc40
  ecx = (u32)(EBP - 144);  // @8_45cc40
  PV[1] = (u32)(ecx);  // @9_45cc40
  ecx = esi;  // @10_45cc40
  reg.state = (s32)((u32)(0));  // @11_45cc40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 468)))(ecx, PV[1], PV[0]);  // @12_45cc40
  ecx = edx = 0;  // @13_45cc40
  ecx = (u32)(EBP - 144);  // @14_45cc40
  eax = ext_4cc1d0_thiscall1(ecx);  // @15_45cc40
  ecx = edx = 0;  // @16_45cc40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @17_45cc40
  PV[2] = (u32)(eax);  // @18_45cc40
  eax = ((u32( *)(u32, u32))(ebx))(PV[2], (u32)(47));  // @19_45cc40
  ecx = edx = 0;  // @20_45cc40
  esi = eax;  // @21_45cc40
  if ((esi & esi) == 0) goto L45cd52;  // @22_45cc40
  ecx = (u32)(EBP - 144);  // @23_45cc40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @24_45cc40
  eax = ext_4cc1d0_thiscall1(ecx);  // @25_45cc40
  ecx = edx = 0;  // @26_45cc40
  PV[3] = (u32)(eax);  // @27_45cc40
  eax = ((u32( *)(u32, u32))(ebx))(PV[3], (u32)(92));  // @28_45cc40
  ecx = edx = 0;  // @29_45cc40
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @30_45cc40
  ecx = (u32)(EBP - 400);  // @31_45cc40
  ebx = eax;  // @32_45cc40
  eax = ext_4cbeb0_thiscall1(ecx);  // @33_45cc40
  ecx = edx = 0;  // @34_45cc40
  reg.state = (s32)((u32)(1));  // @35_45cc40
  ecx = (u32)(EBP - 272);  // @36_45cc40
  if ((ebx & ebx) == 0) goto L45cd09;  // @37_45cc40
  eax = (u32)(ebx + 1);  // @38_45cc40
  PV[4] = (u32)(eax);  // @39_45cc40
  eax = ext_4cbe80_thiscall2(ecx, PV[4]);  // @40_45cc40
  ecx = edx = 0;  // @41_45cc40
  reg.state = (s32)((u32)(2));  // @42_45cc40
  goto L45cd16;  // @43_45cc40
  L45cd09:;
  eax = (u32)(esi + 1);  // @45_45cc40
  PV[5] = (u32)(eax);  // @46_45cc40
  eax = ext_4cbe80_thiscall2(ecx, PV[5]);  // @47_45cc40
  ecx = edx = 0;  // @48_45cc40
  reg.state = (s32)((u32)(3));  // @49_45cc40
  L45cd16:;
  eax = (u32)(EBP - 272);  // @51_45cc40
  PV[6] = (u32)(eax);  // @52_45cc40
  ecx = (u32)(EBP - 400);  // @53_45cc40
  eax = ext_4cbee0_thiscall2(ecx, PV[6]);  // @54_45cc40
  ecx = edx = 0;  // @55_45cc40
  ecx = (u32)(EBP - 272);  // @56_45cc40
  reg.state = (s32)((u32)(1));  // @57_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @58_45cc40
  ecx = edx = 0;  // @59_45cc40
  eax = (u32)(EBP - 400);  // @60_45cc40
  ecx = edi;  // @61_45cc40
  PV[7] = (u32)(eax);  // @62_45cc40
  eax = ext_4cbe50_thiscall2(ecx, PV[7]);  // @63_45cc40
  ecx = edx = 0;  // @64_45cc40
  ecx = (u32)(EBP - 400);  // @65_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @66_45cc40
  ecx = edx = 0;  // @67_45cc40
  goto L45cd60;  // @68_45cc40
  L45cd52:;
  eax = (u32)(EBP - 144);  // @70_45cc40
  ecx = edi;  // @71_45cc40
  PV[8] = (u32)(eax);  // @72_45cc40
  eax = ext_4cbe50_thiscall2(ecx, PV[8]);  // @73_45cc40
  ecx = edx = 0;  // @74_45cc40
  L45cd60:;
  ecx = (u32)(EBP - 144);  // @76_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @77_45cc40
  ecx = edx = 0;  // @78_45cc40
  eax = edi;  // @79_45cc40
  SEH_LEAVE();  // @80_45cc40
  ext_633654(G(u32, 0x6f5630));  // @81_45cc40
  return eax;  // @82_45cc40
}
PCREG(45cc40, lifted_45cc40);

extern "C" u32 THISCALL lifted_431ce0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x6654b6);  // @h_431ce0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  edi = ecx;  // @0_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_431ce0
  ecx = (u32)(EBP - 324);  // @2_431ce0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_431ce0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @4_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 332), &v, sizeof v); }  // @5_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @6_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @7_431ce0
  eax = ext_4cbeb0_thiscall1(ecx);  // @8_431ce0
  ecx = edx = 0;  // @9_431ce0
  PV[0] = (u32)(esi);  // @10_431ce0
  ecx = (u32)(EBP - 144);  // @11_431ce0
  reg.state = (s32)((u32)(0));  // @12_431ce0
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @13_431ce0
  ecx = edx = 0;  // @14_431ce0
  eax = (u32)(EBP - 144);  // @15_431ce0
  reg.state = (s32)((u32)(1));  // @16_431ce0
  PV[1] = (u32)(eax);  // @17_431ce0
  ecx = (u32)(EBP - 324);  // @18_431ce0
  eax = ext_4cbee0_thiscall2(ecx, PV[1]);  // @19_431ce0
  ecx = edx = 0;  // @20_431ce0
  ecx = (u32)(EBP - 144);  // @21_431ce0
  reg.state = (s32)((u32)(0));  // @22_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @23_431ce0
  ecx = edx = 0;  // @24_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @25_431ce0
  if ((eax & eax) == 0) goto L431d81;  // @26_431ce0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @27_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @28_431ce0
  goto L431d92;  // @29_431ce0
  L431d81:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @31_431ce0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @32_431ce0
  L431d92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @34_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @35_431ce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @36_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 149), &v, sizeof v); }  // @37_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @39_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @40_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @41_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @42_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @43_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @44_431ce0
  ecx = (u32)(EBP - 324);  // @45_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @46_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @47_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @48_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @49_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @50_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @51_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @52_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @53_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @54_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @55_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @56_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @57_431ce0
  PV[2] = (u32)(ecx);  // @58_431ce0
  ecx = edi;  // @59_431ce0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 159), &v, sizeof v); }  // @60_431ce0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 157), &v, sizeof v); }  // @61_431ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[2]);  // @62_431ce0
  ecx = edx = 0;  // @63_431ce0
  ecx = (u32)(EBP - 324);  // @64_431ce0
  esi = eax;  // @65_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @66_431ce0
  ecx = edx = 0;  // @67_431ce0
  eax = esi;  // @68_431ce0
  SEH_LEAVE();  // @69_431ce0
  ext_633654(G(u32, 0x6f5630));  // @70_431ce0
  return eax;  // @71_431ce0
}
PCREG(431ce0, lifted_431ce0);

extern "C" u32 THISCALL lifted_4356e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_4356e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4356e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4357df;  // @2_4356e0
  PV[0] = (u32)(eax);  // @3_4356e0
  ecx = (u32)(EBP - 144);  // @4_4356e0
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @5_4356e0
  ecx = edx = 0;  // @6_4356e0
  ecx = (u32)(EBP - 144);  // @7_4356e0
  reg.state = (s32)((u32)(0));  // @8_4356e0
  esi = 0;  // @9_4356e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @10_4356e0
  ecx = edx = 0;  // @11_4356e0
  if ((eax & eax) == 0) goto L435771;  // @12_4356e0
  L435741:;
  ecx = (u32)(EBP - 144);  // @14_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @15_4356e0
  ecx = edx = 0;  // @16_4356e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L435761;  // @17_4356e0
  ecx = (u32)(EBP - 144);  // @18_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_4356e0
  ecx = edx = 0;  // @20_4356e0
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @21_4356e0
  L435761:;
  ecx = (u32)(EBP - 144);  // @23_4356e0
  esi = (esi + 1);  // @24_4356e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @25_4356e0
  ecx = edx = 0;  // @26_4356e0
  if (esi != eax) goto L435741;  // @27_4356e0
  L435771:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @29_4356e0
  if ((ecx & ecx) == 0) goto L4357d4;  // @30_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4356e0
  edx = (u32)(EBP - 156);  // @32_4356e0
  PV[1] = (u32)(edx);  // @33_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @34_4356e0
  ecx = edx = 0;  // @35_4356e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @36_4356e0
  edx = (u32)(EBP - 156);  // @37_4356e0
  PV[2] = (u32)(edx);  // @38_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[2]);  // @40_4356e0
  ecx = edx = 0;  // @41_4356e0
  if ((eax & eax) == 0) goto L4357d4;  // @42_4356e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @43_4356e0
  L4357a0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_4356e0
  ecx = (u32)(EBP - 144);  // @46_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @47_4356e0
  ecx = edx = 0;  // @48_4356e0
  PV[3] = (u32)(eax);  // @49_4356e0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @50_4356e0
  eax = ((u32( *)(u32, u32))(ebx))(PV[4], PV[3]);  // @51_4356e0
  ecx = edx = 0;  // @52_4356e0
  if ((eax & eax) != 0) goto L4357c1;  // @53_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_4356e0
  ecx = esi;  // @55_4356e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @56_4356e0
  ecx = edx = 0;  // @57_4356e0
  L4357c1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @59_4356e0
  edx = (u32)(EBP - 156);  // @60_4356e0
  PV[5] = (u32)(edx);  // @61_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @63_4356e0
  ecx = edx = 0;  // @64_4356e0
  if ((eax & eax) != 0) goto L4357a0;  // @65_4356e0
  L4357d4:;
  ecx = (u32)(EBP - 144);  // @67_4356e0
  eax = ext_4cbec0_thiscall1(ecx);  // @68_4356e0
  ecx = edx = 0;  // @69_4356e0
  L4357df:;
  SEH_LEAVE();  // @71_4356e0
  ext_633654(G(u32, 0x6f5630));  // @72_4356e0
  return eax;  // @73_4356e0
}
PCREG(4356e0, lifted_4356e0);

extern "C" u32 THISCALL lifted_4cbae0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665aff);  // @h_4cbae0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4cbae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4cbae0
  eax = (u32)(edi + 80);  // @2_4cbae0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_4cbae0
  ecx = esi;  // @4_4cbae0
  PV[0] = (u32)(eax);  // @5_4cbae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4cbae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 68)))(ecx, PV[0]);  // @7_4cbae0
  ecx = edx = 0;  // @8_4cbae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_4cbae0
  eax = (u32)(edi + 82);  // @10_4cbae0
  PV[1] = (u32)(eax);  // @11_4cbae0
  ecx = esi;  // @12_4cbae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 68)))(ecx, PV[1]);  // @13_4cbae0
  ecx = edx = 0;  // @14_4cbae0
  eax = ext_41e290_cdecl1((u32)(28));  // @15_4cbae0
  ecx = edx = 0;  // @16_4cbae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @17_4cbae0
  reg.state = (s32)((u32)(0));  // @18_4cbae0
  if ((eax & eax) == 0) goto L4cbb48;  // @19_4cbae0
  ecx = eax;  // @20_4cbae0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(2));  // @21_4cbae0
  ecx = edx = 0;  // @22_4cbae0
  goto L4cbb4a;  // @23_4cbae0
  L4cbb48:;
  eax = 0;  // @25_4cbae0
  L4cbb4a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @27_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 88), &v, sizeof v); }  // @28_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 92), &v, sizeof v); }  // @29_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 96), &v, sizeof v); }  // @30_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @31_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 104), &v, sizeof v); }  // @32_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 108), &v, sizeof v); }  // @33_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 112), &v, sizeof v); }  // @34_4cbae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 100), &v, sizeof v); }  // @35_4cbae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_4cbae0
  reg.state = (s32)((u32)(4294967295));  // @37_4cbae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @38_4cbae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4cbae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @40_4cbae0
  ecx = edx = 0;  // @41_4cbae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @42_4cbae0
  esi = eax;  // @43_4cbae0
  PV[2] = (u32)(edi);  // @44_4cbae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4cbae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, PV[2]);  // @46_4cbae0
  ecx = edx = 0;  // @47_4cbae0
  if ((eax & eax) == 0) goto L4cbbb5;  // @48_4cbae0
  ecx = 0;  // @49_4cbae0
  goto L4cbbe6;  // @50_4cbae0
  L4cbbb5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @52_4cbae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @53_4cbae0
  if ((eax & eax) == 0) goto L4cbbd4;  // @54_4cbae0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > edi) goto L4cbbd4;  // @55_4cbae0
  if (edi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L4cbbd4;  // @56_4cbae0
  ecx = edi;  // @57_4cbae0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @58_4cbae0
  ecx = edx = 0;  // @59_4cbae0
  ecx = eax;  // @60_4cbae0
  goto L4cbbe6;  // @61_4cbae0
  L4cbbd4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cbbe3;  // @63_4cbae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4cbae0
  PV[3] = (u32)(edi);  // @65_4cbae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[3]);  // @66_4cbae0
  ecx = edx = 0;  // @67_4cbae0
  L4cbbe3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; });  // @69_4cbae0
  L4cbbe6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @71_4cbae0
  PV[4] = (u32)(ecx);  // @72_4cbae0
  ecx = esi;  // @73_4cbae0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6903412), PV[4], (u32)(4));  // @74_4cbae0
  ecx = edx = 0;  // @75_4cbae0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @76_4cbae0
  SEH_LEAVE();  // @77_4cbae0
  return eax;  // @78_4cbae0
}
PCREG(4cbae0, lifted_4cbae0);

extern "C" u32 THISCALL lifted_5fae50(u32 ecx_in) {
  SEH_ENTER(0x66d392);  // @h_5fae50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5fae50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }) == (u32)(0)) goto L5faec2;  // @1_5fae50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @2_5fae50
  L5fae81:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @4_5fae50
  if ((ecx & ecx) == 0) goto L5fae94;  // @5_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @6_5fae50
  ecx = (ecx - 1);  // @7_5fae50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @8_5fae50
  ebx = (u32)(eax + ecx*4);  // @9_5fae50
  goto L5faea4;  // @10_5fae50
  L5fae94:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @12_5fae50
  if ((eax & eax) == 0) goto L5faea1;  // @13_5fae50
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @14_5fae50
  ecx = edx = 0;  // @15_5fae50
  goto L5faea4;  // @16_5fae50
  L5faea1:;
  __builtin_trap();  // @18_5fae50
  L5faea4:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @20_5fae50
  if ((edi & edi) == 0) goto L5faebc;  // @21_5fae50
  ecx = edi;  // @22_5fae50
  eax = ext_5fad90_thiscall1(ecx);  // @23_5fae50
  ecx = edx = 0;  // @24_5fae50
  PV[0] = (u32)(edi);  // @25_5fae50
  eax = ext_634273_cdecl2(PV[0], (u32)(72));  // @26_5fae50
  ecx = edx = 0;  // @27_5fae50
  L5faebc:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }) != (u32)(0)) goto L5fae81;  // @29_5fae50
  L5faec2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @31_5fae50
  if ((ecx & ecx) == 0) goto L5faecf;  // @32_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_5fae50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @34_5fae50
  ecx = edx = 0;  // @35_5fae50
  L5faecf:;
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @37_5fae50
  eax = ext_41e2c0_cdecl1(PV[1]);  // @38_5fae50
  ecx = edx = 0;  // @39_5fae50
  ecx = (u32)(esi + 24);  // @40_5fae50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @42_5fae50
  eax = (eax - edx);  // @43_5fae50
  reg.state = (s32)((u32)(0));  // @44_5fae50
  if ((edx & edx) == 0) goto L5faefa;  // @45_5fae50
  if ((eax & eax) == 0) goto L5faefa;  // @46_5fae50
  PV[2] = (u32)(eax);  // @47_5fae50
  PV[3] = (u32)(edx);  // @48_5fae50
  eax = ext_54f870_stdcall2(PV[3], PV[2]);  // @49_5fae50
  ecx = edx = 0;  // @50_5fae50
  L5faefa:;
  ecx = (u32)(esi + 12);  // @52_5fae50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @54_5fae50
  eax = (eax - edx);  // @55_5fae50
  reg.state = (s32)((u32)(1));  // @56_5fae50
  if ((edx & edx) == 0) goto L5faf1a;  // @57_5fae50
  if ((eax & eax) == 0) goto L5faf1a;  // @58_5fae50
  PV[4] = (u32)(eax);  // @59_5fae50
  PV[5] = (u32)(edx);  // @60_5fae50
  eax = ext_54f870_stdcall2(PV[5], PV[4]);  // @61_5fae50
  ecx = edx = 0;  // @62_5fae50
  L5faf1a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_5fae50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @65_5fae50
  eax = (eax - ecx);  // @66_5fae50
  reg.state = (s32)((u32)(2));  // @67_5fae50
  if ((ecx & ecx) == 0) goto L5faf39;  // @68_5fae50
  if ((eax & eax) == 0) goto L5faf39;  // @69_5fae50
  PV[6] = (u32)(eax);  // @70_5fae50
  PV[7] = (u32)(ecx);  // @71_5fae50
  ecx = esi;  // @72_5fae50
  eax = ext_54f870_stdcall2(PV[7], PV[6]);  // @73_5fae50
  ecx = edx = 0;  // @74_5fae50
  L5faf39:;
  SEH_LEAVE();  // @76_5fae50
  return eax;  // @77_5fae50
}
PCREG(5fae50, lifted_5fae50);


extern "C" u32 THISCALL lifted_5b6d00(u32 ecx_in) {
  SEH_ENTER(0x665c2f);  // @h_5b6d00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5b6d00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_5b6d00
  ecx = edx = 0;  // @5_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_5b6d00
  esi = eax;  // @7_5b6d00
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @8_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @9_5b6d00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_5b6d00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_5b6d00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[0], (u32)(16));  // @12_5b6d00
  ecx = edx = 0;  // @13_5b6d00
  PV[1] = (u32)(eax);  // @14_5b6d00
  ecx = esi;  // @15_5b6d00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6970372), PV[1]);  // @16_5b6d00
  ecx = edx = 0;  // @17_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5b6d00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @21_5b6d00
  ecx = edx = 0;  // @22_5b6d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @23_5b6d00
  esi = eax;  // @24_5b6d00
  PV[2] = (u32)(ebx);  // @25_5b6d00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_5b6d00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, PV[2]);  // @27_5b6d00
  ecx = edx = 0;  // @28_5b6d00
  if ((eax & eax) == 0) goto L5b6d89;  // @29_5b6d00
  ecx = 0;  // @30_5b6d00
  goto L5b6dba;  // @31_5b6d00
  L5b6d89:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @33_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @34_5b6d00
  if ((eax & eax) == 0) goto L5b6da8;  // @35_5b6d00
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > ebx) goto L5b6da8;  // @36_5b6d00
  if (ebx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L5b6da8;  // @37_5b6d00
  ecx = ebx;  // @38_5b6d00
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @39_5b6d00
  ecx = edx = 0;  // @40_5b6d00
  ecx = eax;  // @41_5b6d00
  goto L5b6dba;  // @42_5b6d00
  L5b6da8:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L5b6db7;  // @44_5b6d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_5b6d00
  PV[3] = (u32)(ebx);  // @46_5b6d00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[3]);  // @47_5b6d00
  ecx = edx = 0;  // @48_5b6d00
  L5b6db7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 4), sizeof v); (u32)v; });  // @50_5b6d00
  L5b6dba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_5b6d00
  PV[4] = (u32)(ecx);  // @53_5b6d00
  ecx = esi;  // @54_5b6d00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6998220), PV[4], (u32)(4));  // @55_5b6d00
  ecx = edx = 0;  // @56_5b6d00
  eax = ext_41e290_cdecl1((u32)(28));  // @57_5b6d00
  ecx = edx = 0;  // @58_5b6d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @59_5b6d00
  reg.state = (s32)((u32)(0));  // @60_5b6d00
  if ((eax & eax) == 0) goto L5b6e04;  // @61_5b6d00
  ecx = eax;  // @62_5b6d00
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(10), (u32)(141));  // @63_5b6d00
  ecx = edx = 0;  // @64_5b6d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @65_5b6d00
  SEH_LEAVE();  // @66_5b6d00
  return eax;  // @67_5b6d00
  L5b6e04:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @69_5b6d00
  SEH_LEAVE();  // @70_5b6d00
  return eax;  // @71_5b6d00
}
PCREG(5b6d00, lifted_5b6d00);




extern "C" u32 THISCALL lifted_6025f0(u32 ecx_in) {
  SEH_ENTER(0x66da62);  // @h_6025f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @0_6025f0
  ebx = (u32)(ecx + 1);  // @1_6025f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_6025f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5), sizeof v); (u32)v; });  // @3_6025f0
  if (esi == eax) goto L6026cb;  // @4_6025f0
  L602630:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @6_6025f0
  if ((edi & edi) == 0) goto L60268b;  // @7_6025f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @8_6025f0
  { u32 v = (u32)((u32)(7051460)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @9_6025f0
  if ((ebx & ebx) == 0) goto L602656;  // @10_6025f0
  ecx = ebx;  // @11_6025f0
  eax = ext_602530_thiscall1(ecx);  // @12_6025f0
  ecx = edx = 0;  // @13_6025f0
  PV[0] = (u32)(ebx);  // @14_6025f0
  eax = ext_634273_cdecl2(PV[0], (u32)(48));  // @15_6025f0
  ecx = edx = 0;  // @16_6025f0
  L602656:;
  ecx = (u32)(edi + 4);  // @18_6025f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @20_6025f0
  eax = (eax - edx);  // @21_6025f0
  reg.state = (s32)((u32)(0));  // @22_6025f0
  if ((edx & edx) == 0) goto L602676;  // @23_6025f0
  if ((eax & eax) == 0) goto L602676;  // @24_6025f0
  PV[1] = (u32)(eax);  // @25_6025f0
  PV[2] = (u32)(edx);  // @26_6025f0
  eax = ext_54f870_stdcall2(PV[2], PV[1]);  // @27_6025f0
  ecx = edx = 0;  // @28_6025f0
  L602676:;
  PV[3] = (u32)(edi);  // @30_6025f0
  reg.state = (s32)((u32)(4294967295));  // @31_6025f0
  eax = ext_634273_cdecl2(PV[3], (u32)(40));  // @32_6025f0
  ecx = edx = 0;  // @33_6025f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @34_6025f0
  L60268b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @36_6025f0
  if ((eax & eax) == 0) goto L6026ab;  // @37_6025f0
  esi = eax;  // @38_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @39_6025f0
  if ((eax & eax) == 0) goto L6026c3;  // @40_6025f0
  L6026a0:;
  esi = eax;  // @42_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @43_6025f0
  if ((eax & eax) != 0) goto L6026a0;  // @44_6025f0
  goto L6026c3;  // @45_6025f0
  L6026ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; });  // @47_6025f0
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; })) goto L6026bd;  // @48_6025f0
  L6026b3:;
  esi = eax;  // @50_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @51_6025f0
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; })) goto L6026b3;  // @52_6025f0
  L6026bd:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }) != eax) esi = eax;  // @54_6025f0
  L6026c3:;
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) goto L602630;  // @56_6025f0
  L6026cb:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L6026f7;  // @58_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @59_6025f0
  ecx = ebx;  // @60_6025f0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @61_6025f0
  eax = ext_5fb370_thiscall2(ecx, PV[4]);  // @62_6025f0
  ecx = edx = 0;  // @63_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_6025f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @65_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @66_6025f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @67_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_6025f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @69_6025f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @70_6025f0
  L6026f7:;
  reg.state = (s32)((u32)(1));  // @72_6025f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L60272a;  // @73_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @74_6025f0
  ecx = ebx;  // @75_6025f0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @76_6025f0
  eax = ext_5fb370_thiscall2(ecx, PV[5]);  // @77_6025f0
  ecx = edx = 0;  // @78_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @79_6025f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @80_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @81_6025f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @82_6025f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @83_6025f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @84_6025f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @85_6025f0
  L60272a:;
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_6025f0
  ecx = ebx;  // @88_6025f0
  reg.state = (s32)((u32)(2));  // @89_6025f0
  eax = ext_54f870_stdcall2(PV[6], (u32)(29));  // @90_6025f0
  ecx = edx = 0;  // @91_6025f0
  SEH_LEAVE();  // @92_6025f0
  return eax;  // @93_6025f0
}
PCREG(6025f0, lifted_6025f0);



