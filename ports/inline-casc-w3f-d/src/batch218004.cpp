// batch218004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_435580(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_435580
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435580
  ecx = (u32)(EBP - 144);  // @2_435580
  PV[0] = (u32)(eax);  // @3_435580
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @4_435580
  ecx = edx = 0;  // @5_435580
  eax = (u32)(EBP - 144);  // @6_435580
  reg.state = (s32)((u32)(0));  // @7_435580
  edi = (edi + (u32)(140));  // @8_435580
  PV[1] = (u32)(eax);  // @9_435580
  ecx = edi;  // @10_435580
  eax = ext_4cbee0_thiscall2(ecx, PV[1]);  // @11_435580
  ecx = edx = 0;  // @12_435580
  ecx = (u32)(EBP - 144);  // @13_435580
  reg.state = (s32)((u32)(4294967295));  // @14_435580
  eax = ext_4cbec0_thiscall1(ecx);  // @15_435580
  ecx = edx = 0;  // @16_435580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @17_435580
  ecx = edi;  // @18_435580
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_435580
  eax = ext_4cc5f0_thiscall1(ecx);  // @20_435580
  ecx = edx = 0;  // @21_435580
  PV[2] = (u32)(eax);  // @22_435580
  ecx = edi;  // @23_435580
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_435580
  ecx = edx = 0;  // @25_435580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @26_435580
  PV[3] = (u32)(eax);  // @27_435580
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 20)))(ecx, (u32)(6792648), (u32)(8), PV[3], PV[2]);  // @28_435580
  ecx = edx = 0;  // @29_435580
  SEH_LEAVE();  // @30_435580
  ext_633654(G(u32, 0x6f5630));  // @31_435580
  return eax;  // @32_435580
}
PCREG(435580, lifted_435580);

extern "C" u32 THISCALL lifted_45fdf0(u32 ecx_in) {
  SEH_ENTER(0x66d436);  // @h_45fdf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45fdf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_45fdf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @2_45fdf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @3_45fdf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @4_45fdf0
  if ((edi & edi) == 0) goto L45fe6d;  // @5_45fdf0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @6_45fdf0
  if ((ebx & ebx) == 0) goto L45fe62;  // @7_45fdf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @8_45fdf0
  reg.state = (s32)((u32)(0));  // @9_45fdf0
  if ((ecx & ecx) == 0) goto L45fe50;  // @10_45fdf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @11_45fdf0
  if ((edx & edx) == 0) goto L45fe50;  // @12_45fdf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_45fdf0
  PV[0] = (u32)(edx);  // @14_45fdf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @15_45fdf0
  ecx = edx = 0;  // @16_45fdf0
  L45fe50:;
  PV[1] = (u32)(ebx);  // @18_45fdf0
  eax = ext_634273_cdecl2(PV[1], (u32)(16));  // @19_45fdf0
  ecx = edx = 0;  // @20_45fdf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @21_45fdf0
  L45fe62:;
  PV[2] = (u32)(edi);  // @23_45fdf0
  eax = ext_634273_cdecl2(PV[2], (u32)(8));  // @24_45fdf0
  ecx = edx = 0;  // @25_45fdf0
  L45fe6d:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @27_45fdf0
  SEH_LEAVE();  // @28_45fdf0
  return eax;  // @29_45fdf0
}
PCREG(45fdf0, lifted_45fdf0);

extern "C" u32 THISCALL lifted_4373a0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x665a8f);  // @h_4373a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_4373a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4373a0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4373a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[0]);  // @3_4373a0
  ecx = edx = 0;  // @4_4373a0
  if ((eax & eax) == 0) goto L4373e7;  // @5_4373a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 29), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @6_4373a0
  SEH_LEAVE();  // @7_4373a0
  return eax;  // @8_4373a0
  L4373e7:;
  eax = ext_41e290_cdecl1((u32)(35));  // @10_4373a0
  ecx = edx = 0;  // @11_4373a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_4373a0
  reg.state = (s32)((u32)(0));  // @13_4373a0
  if ((eax & eax) == 0) goto L437413;  // @14_4373a0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @15_4373a0
  ecx = eax;  // @16_4373a0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_4373a0
  PV[3] = (u32)(esi);  // @18_4373a0
  eax = ext_4364e0_thiscall5(ecx, PV[3], PV[2], PV[1], (u32)(0));  // @19_4373a0
  ecx = edx = 0;  // @20_4373a0
  edx = eax;  // @21_4373a0
  goto L437415;  // @22_4373a0
  L437413:;
  edx = 0;  // @24_4373a0
  L437415:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4628), sizeof v); (u32)v; });  // @26_4373a0
  PV[4] = (u32)(edx);  // @27_4373a0
  reg.state = (s32)((u32)(4294967295));  // @28_4373a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4373a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[4]);  // @30_4373a0
  ecx = edx = 0;  // @31_4373a0
  SEH_LEAVE();  // @32_4373a0
  return eax;  // @33_4373a0
}
PCREG(4373a0, lifted_4373a0);



