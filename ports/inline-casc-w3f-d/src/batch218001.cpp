// batch218001.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_469980_thiscall4(u32, u32, u32, u32) __asm__("ext_469980");
extern "C" u32 THISCALL ext_48a470_thiscall2(u32, u32) __asm__("ext_48a470");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cbf30_thiscall2(u32, u32) __asm__("ext_4cbf30");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccc30_thiscall3(u32, u32, u32) __asm__("ext_4ccc30");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e5e40_thiscall1(u32) __asm__("ext_4e5e40");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e6330_thiscall2(u32, u32) __asm__("ext_4e6330");
extern "C" u32 THISCALL ext_561020_thiscall1(u32) __asm__("ext_561020");
extern "C" u32 THISCALL ext_5aede0_thiscall1(u32) __asm__("ext_5aede0");
extern "C" u32 THISCALL ext_604ca0_thiscall1(u32) __asm__("ext_604ca0");
extern "C" u32 THISCALL ext_65e090_thiscall1(u32) __asm__("ext_65e090");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_45c4f0_cdecl2(...) __asm__("ext_45c4f0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4ccf60(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4ccf60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ccf60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1_4ccf60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_4ccf60
  { u32 v = (u32)((u32)(6903740)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_4ccf60
  if ((edi & edi) == 0) goto L4ccfaf;  // @4_4ccf60
  L4ccfa0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4ccf60
  ecx = esi;  // @7_4ccf60
  PV[0] = (u32)(edi);  // @8_4ccf60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_4ccf60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[0]);  // @10_4ccf60
  ecx = edx = 0;  // @11_4ccf60
  if ((edi & edi) != 0) goto L4ccfa0;  // @12_4ccf60
  L4ccfaf:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @14_4ccf60
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @15_4ccf60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @16_4ccf60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @17_4ccf60
  SEH_LEAVE();  // @18_4ccf60
  return eax;  // @19_4ccf60
}
PCREG(4ccf60, lifted_4ccf60);


extern "C" u32 THISCALL lifted_4cce40(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cce40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4cce40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @1_4cce40
  { u32 v = (u32)((u32)(6904156)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4cce40
  if ((ecx & ecx) == 0) goto L4cce79;  // @3_4cce40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4cce40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_4cce40
  ecx = edx = 0;  // @6_4cce40
  L4cce79:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @8_4cce40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @9_4cce40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @10_4cce40
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @11_4cce40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @12_4cce40
  reg.state = (s32)((u32)(0));  // @13_4cce40
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_4cce40
  if ((edi & edi) == 0) goto L4ccebf;  // @15_4cce40
  L4cceb0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_4cce40
  ecx = esi;  // @18_4cce40
  PV[0] = (u32)(edi);  // @19_4cce40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @20_4cce40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[0]);  // @21_4cce40
  ecx = edx = 0;  // @22_4cce40
  if ((edi & edi) != 0) goto L4cceb0;  // @23_4cce40
  L4ccebf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @25_4cce40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @26_4cce40
  SEH_LEAVE();  // @27_4cce40
  return eax;  // @28_4cce40
}
PCREG(4cce40, lifted_4cce40);




extern "C" u32 THISCALL lifted_4998c0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664c7f);  // @h_4998c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4998c0
  { u32 v = (u32)((u32)(6875464)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4998c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 312), &v, sizeof v); }  // @2_4998c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @3_4998c0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 296), &v, sizeof v); }  // @4_4998c0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 300), &v, sizeof v); }  // @5_4998c0
  eax = ext_41e290_cdecl1((u32)(16));  // @6_4998c0
  ecx = edx = 0;  // @7_4998c0
  ecx = eax;  // @8_4998c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @9_4998c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @10_4998c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_4998c0
  reg.state = (s32)((u32)(0));  // @12_4998c0
  if ((ecx & ecx) == 0) goto L499944;  // @13_4998c0
  eax = (u32)(edi + ebx);  // @14_4998c0
  PV[0] = (u32)(eax);  // @15_4998c0
  PV[1] = (u32)(edi);  // @16_4998c0
  eax = ext_4ccdd0_thiscall4(ecx, PV[1], PV[0], (u32)(256));  // @17_4998c0
  ecx = edx = 0;  // @18_4998c0
  goto L499946;  // @19_4998c0
  L499944:;
  eax = 0;  // @21_4998c0
  L499946:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @23_4998c0
  eax = esi;  // @24_4998c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @25_4998c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 308), &v, sizeof v); }  // @26_4998c0
  SEH_LEAVE();  // @27_4998c0
  return eax;  // @28_4998c0
}
PCREG(4998c0, lifted_4998c0);



extern "C" u32 FASTCALL lifted_4697d0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665e21);  // @h_4697d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_4697d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4697d0
  PV[0] = (u32)(ecx);  // @2_4697d0
  eax = ext_45c4f0_cdecl2((u32)(148), PV[0]);  // @3_4697d0
  ecx = edx = 0;  // @4_4697d0
  esi = eax;  // @5_4697d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @6_4697d0
  reg.state = (s32)((u32)(0));  // @7_4697d0
  if ((esi & esi) == 0) goto L469856;  // @8_4697d0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_4697d0
  ecx = esi;  // @10_4697d0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_4697d0
  PV[3] = (u32)(edi);  // @12_4697d0
  eax = ext_469980_thiscall4(ecx, PV[3], PV[2], PV[1]);  // @13_4697d0
  ecx = edx = 0;  // @14_4697d0
  eax = 0;  // @15_4697d0
  { u32 v = (u32)((u32)(6846024)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @16_4697d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 146), &v, sizeof v); }  // @17_4697d0
  eax = esi;  // @18_4697d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 142), &v, sizeof v); }  // @19_4697d0
  SEH_LEAVE();  // @20_4697d0
  return eax;  // @21_4697d0
  L469856:;
  eax = 0;  // @23_4697d0
  SEH_LEAVE();  // @24_4697d0
  return eax;  // @25_4697d0
}
PCREG(4697d0, lifted_4697d0);

extern "C" u32 lifted_48a390(void) {
  SEH_ENTER(0x6676b2);  // @h_48a390
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_48a390
  ecx = (u32)(ecx + 675);  // @1_48a390
  eax = ext_4cc1d0_thiscall1(ecx);  // @2_48a390
  ecx = edx = 0;  // @3_48a390
  esi = eax;  // @4_48a390
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L48a3df;  // @5_48a390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_48a390
  ecx = (u32)(ecx + 803);  // @7_48a390
  eax = ext_4cc1d0_thiscall1(ecx);  // @8_48a390
  ecx = edx = 0;  // @9_48a390
  esi = eax;  // @10_48a390
  L48a3df:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @12_48a390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_48a390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6870192));  // @14_48a390
  ecx = edx = 0;  // @15_48a390
  eax = ext_41e290_cdecl1((u32)(23973));  // @16_48a390
  ecx = edx = 0;  // @17_48a390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @18_48a390
  reg.state = (s32)((u32)(0));  // @19_48a390
  if ((eax & eax) == 0) goto L48a416;  // @20_48a390
  PV[0] = (u32)(esi);  // @21_48a390
  ecx = eax;  // @22_48a390
  eax = ext_48a470_thiscall2(ecx, PV[0]);  // @23_48a390
  ecx = edx = 0;  // @24_48a390
  edx = eax;  // @25_48a390
  goto L48a418;  // @26_48a390
  L48a416:;
  edx = 0;  // @28_48a390
  L48a418:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_48a390
  PV[1] = (u32)(edx);  // @31_48a390
  reg.state = (s32)((u32)(4294967295));  // @32_48a390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_48a390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 260)))(ecx, PV[1]);  // @34_48a390
  ecx = edx = 0;  // @35_48a390
  SEH_LEAVE();  // @36_48a390
  return eax;  // @37_48a390
}
PCREG(48a390, lifted_48a390);

extern "C" u32 THISCALL lifted_4e7dd0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6697df);  // @h_4e7dd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4e7dd0
  eax = (u32)(esi + 12);  // @1_4e7dd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @2_4e7dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @3_4e7dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @4_4e7dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @5_4e7dd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @6_4e7dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @7_4e7dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @8_4e7dd0
  { u32 v = (u32)((u32)(6911508)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_4e7dd0
  eax = ext_41e290_cdecl1((u32)(32));  // @10_4e7dd0
  ecx = edx = 0;  // @11_4e7dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_4e7dd0
  reg.state = (s32)((u32)(0));  // @13_4e7dd0
  if ((eax & eax) == 0) goto L4e7e5f;  // @14_4e7dd0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_4e7dd0
  ecx = eax;  // @16_4e7dd0
  eax = ext_4ccc30_thiscall3(ecx, PV[0], (u32)(5));  // @17_4e7dd0
  ecx = edx = 0;  // @18_4e7dd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @19_4e7dd0
  eax = esi;  // @20_4e7dd0
  SEH_LEAVE();  // @21_4e7dd0
  return eax;  // @22_4e7dd0
  L4e7e5f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @24_4e7dd0
  eax = esi;  // @25_4e7dd0
  SEH_LEAVE();  // @26_4e7dd0
  return eax;  // @27_4e7dd0
}
PCREG(4e7dd0, lifted_4e7dd0);

extern "C" u32 THISCALL lifted_567720(u32 ecx_in) {
  SEH_ENTER(0x66c468);  // @h_567720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_567720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_567720
  eax = ext_561020_thiscall1(ecx);  // @2_567720
  ecx = edx = 0;  // @3_567720
  ecx = (u32)(esi + 384);  // @4_567720
  reg.state = (s32)((u32)(0));  // @5_567720
  { u32 v = (u32)((u32)(6975708)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_567720
  eax = ext_5aede0_thiscall1(ecx);  // @7_567720
  ecx = edx = 0;  // @8_567720
  ecx = (u32)(esi + 468);  // @9_567720
  eax = ext_5aede0_thiscall1(ecx);  // @10_567720
  ecx = edx = 0;  // @11_567720
  ecx = (u32)(esi + 552);  // @12_567720
  eax = ext_5aede0_thiscall1(ecx);  // @13_567720
  ecx = edx = 0;  // @14_567720
  ecx = (u32)(esi + 636);  // @15_567720
  eax = ext_65e090_thiscall1(ecx);  // @16_567720
  ecx = edx = 0;  // @17_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1006), &v, sizeof v); }  // @18_567720
  eax = (u32)(esi + 802);  // @19_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1014), &v, sizeof v); }  // @20_567720
  ecx = (u32)(17);  // @21_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1022), &v, sizeof v); }  // @22_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1030), &v, sizeof v); }  // @23_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1038), &v, sizeof v); }  // @24_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1046), &v, sizeof v); }  // @25_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1054), &v, sizeof v); }  // @26_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1062), &v, sizeof v); }  // @27_567720
  L5677e2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @29_567720
  eax = (u32)(eax + 12);  // @30_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 12), &v, sizeof v); }  // @31_567720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @32_567720
  ecx = (ecx - (u32)(1));  // @33_567720
  if (ecx != 0) goto L5677e2;  // @34_567720
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(esi + 801), &v, sizeof v); }  // @35_567720
  eax = esi;  // @36_567720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 656), &v, sizeof v); }  // @37_567720
  SEH_LEAVE();  // @38_567720
  return eax;  // @39_567720
}
PCREG(567720, lifted_567720);

extern "C" u32 THISCALL lifted_5dbd10(u32 ecx_in) {
  SEH_ENTER(0x668ea7);  // @h_5dbd10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5dbd10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5dbd10
  eax = ext_469870_thiscall1(ecx);  // @2_5dbd10
  ecx = edx = 0;  // @3_5dbd10
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5dbd10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5dbd10
  reg.state = (s32)((u32)(0));  // @6_5dbd10
  { u32 v = (u32)((u32)(7039420)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_5dbd10
  eax = ext_41e290_cdecl1((u32)(28));  // @8_5dbd10
  ecx = edx = 0;  // @9_5dbd10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_5dbd10
  reg.state = (s32)((u32)(1));  // @11_5dbd10
  if ((eax & eax) == 0) goto L5dbd7a;  // @12_5dbd10
  ecx = eax;  // @13_5dbd10
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @14_5dbd10
  ecx = edx = 0;  // @15_5dbd10
  goto L5dbd7c;  // @16_5dbd10
  L5dbd7a:;
  eax = 0;  // @18_5dbd10
  L5dbd7c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @20_5dbd10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_5dbd10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @22_5dbd10
  reg.state = (s32)((u32)(0));  // @23_5dbd10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_5dbd10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7039608), (u32)(0), (u32)(7039552), (u32)(18));  // @25_5dbd10
  ecx = edx = 0;  // @26_5dbd10
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422852), &v, sizeof v); }  // @27_5dbd10
  eax = esi;  // @28_5dbd10
  SEH_LEAVE();  // @29_5dbd10
  return eax;  // @30_5dbd10
}
PCREG(5dbd10, lifted_5dbd10);

extern "C" u32 lifted_605400(void) {
  SEH_ENTER(0x66dda7);  // @h_605400
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ext_41e290_cdecl1((u32)(18));  // @0_605400
  ecx = edx = 0;  // @1_605400
  esi = eax;  // @2_605400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_605400
  reg.state = (s32)((u32)(0));  // @4_605400
  if ((esi & esi) == 0) goto L605491;  // @5_605400
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @6_605400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @7_605400
  reg.state = (s32)((u32)(1));  // @8_605400
  { u32 v = (u32)((u32)(7052156)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_605400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489384), sizeof v); (u32)v; }) != (u32)(0)) goto L605466;  // @10_605400
  ecx = esi;  // @11_605400
  eax = ext_604ca0_thiscall1(ecx);  // @12_605400
  ecx = edx = 0;  // @13_605400
  L605466:;
  eax = ext_41e290_cdecl1((u32)(12));  // @15_605400
  ecx = edx = 0;  // @16_605400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @17_605400
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @18_605400
  eax = (u32)(12);  // @19_605400
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @20_605400
  eax = esi;  // @21_605400
  SEH_LEAVE();  // @22_605400
  return eax;  // @23_605400
  L605491:;
  eax = 0;  // @25_605400
  SEH_LEAVE();  // @26_605400
  return eax;  // @27_605400
}
PCREG(605400, lifted_605400);


extern "C" u32 THISCALL lifted_4a4fb0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_4a4fb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4a4fb0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4a4fb0
  eax = ext_469870_thiscall1(ecx);  // @2_4a4fb0
  ecx = edx = 0;  // @3_4a4fb0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4a4fb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4a4fb0
  { u32 v = (u32)((u32)(6880780)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4a4fb0
  eax = (u32)(esi + 183);  // @7_4a4fb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @8_4a4fb0
  ecx = (u32)(EBP - 20);  // @9_4a4fb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @10_4a4fb0
  reg.state = (s32)((u32)(0));  // @11_4a4fb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 187), &v, sizeof v); }  // @12_4a4fb0
  if (eax == ecx) goto L4a5022;  // @13_4a4fb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @14_4a4fb0
  L4a5022:;
  ecx = (u32)(esi + 147);  // @16_4a4fb0
  eax = ext_4de7a0_thiscall1(ecx);  // @17_4a4fb0
  ecx = edx = 0;  // @18_4a4fb0
  eax = 0;  // @19_4a4fb0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 191), &v, sizeof v); }  // @20_4a4fb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 95), &v, sizeof v); }  // @21_4a4fb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 99), &v, sizeof v); }  // @22_4a4fb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 103), &v, sizeof v); }  // @23_4a4fb0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @24_4a4fb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 204), &v, sizeof v); }  // @25_4a4fb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 208), &v, sizeof v); }  // @26_4a4fb0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 212), &v, sizeof v); }  // @27_4a4fb0
  eax = esi;  // @28_4a4fb0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 143), &v, sizeof v); }  // @29_4a4fb0
  { u16 v = (u16)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 196), &v, sizeof v); }  // @30_4a4fb0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 198), &v, sizeof v); }  // @31_4a4fb0
  { u32 v = (u32)((u32)(1103626240)); __builtin_memcpy((void *)(u32)(esi + 199), &v, sizeof v); }  // @32_4a4fb0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 203), &v, sizeof v); }  // @33_4a4fb0
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(esi + 192), &v, sizeof v); }  // @34_4a4fb0
  SEH_LEAVE();  // @35_4a4fb0
  return eax;  // @36_4a4fb0
}
PCREG(4a4fb0, lifted_4a4fb0);

extern "C" u32 THISCALL lifted_431580(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664d1b);  // @h_431580
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_431580
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_431580
  ecx = (u32)(EBP - 144);  // @2_431580
  eax = ext_4cbeb0_thiscall1(ecx);  // @3_431580
  ecx = edx = 0;  // @4_431580
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_431580
  ecx = (u32)(EBP - 144);  // @6_431580
  PV[0] = (u32)(eax);  // @7_431580
  reg.state = (s32)((u32)(0));  // @8_431580
  eax = ext_4cbf30_thiscall2(ecx, PV[0]);  // @9_431580
  ecx = edx = 0;  // @10_431580
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_431580
  ecx = (u32)(EBP - 144);  // @12_431580
  eax = ext_4cc1d0_thiscall1(ecx);  // @13_431580
  ecx = edx = 0;  // @14_431580
  PV[1] = (u32)(eax);  // @15_431580
  PV[2] = (u32)(ebx);  // @16_431580
  ecx = edi;  // @17_431580
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 104)))(ecx, PV[2], PV[1]);  // @18_431580
  ecx = edx = 0;  // @19_431580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_431580
  ecx = (u32)(EBP - 144);  // @21_431580
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @22_431580
  eax = ext_4cc1d0_thiscall1(ecx);  // @23_431580
  ecx = edx = 0;  // @24_431580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_431580
  PV[3] = (u32)(eax);  // @26_431580
  PV[4] = (u32)(ebx);  // @27_431580
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, PV[4], PV[3]);  // @28_431580
  ecx = edx = 0;  // @29_431580
  ecx = (u32)(EBP - 144);  // @30_431580
  eax = ext_4cbec0_thiscall1(ecx);  // @31_431580
  ecx = edx = 0;  // @32_431580
  SEH_LEAVE();  // @33_431580
  ext_633654(G(u32, 0x6f5630));  // @34_431580
  return eax;  // @35_431580
}
PCREG(431580, lifted_431580);

extern "C" u32 THISCALL lifted_4b1130(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_4b1130
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4b1130
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b1130
  ecx = esi;  // @2_4b1130
  eax = ext_4e5e60_thiscall1(ecx);  // @3_4b1130
  ecx = edx = 0;  // @4_4b1130
  ecx = esi;  // @5_4b1130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @6_4b1130
  eax = ext_4e5e40_thiscall1(ecx);  // @7_4b1130
  ecx = edx = 0;  // @8_4b1130
  ecx = esi;  // @9_4b1130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @10_4b1130
  eax = ext_4e5e60_thiscall1(ecx);  // @11_4b1130
  ecx = edx = 0;  // @12_4b1130
  ecx = esi;  // @13_4b1130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 82), &v, sizeof v); }  // @14_4b1130
  eax = ext_4e5e60_thiscall1(ecx);  // @15_4b1130
  ecx = edx = 0;  // @16_4b1130
  ecx = esi;  // @17_4b1130
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 214), &v, sizeof v); }  // @18_4b1130
  eax = ext_4e5ea0_thiscall1(ecx);  // @19_4b1130
  ecx = edx = 0;  // @20_4b1130
  if ((eax & eax) == 0) goto L4b11c6;  // @21_4b1130
  PV[0] = (u32)(eax);  // @22_4b1130
  ecx = (u32)(EBP - 144);  // @23_4b1130
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @24_4b1130
  ecx = edx = 0;  // @25_4b1130
  eax = (u32)(EBP - 144);  // @26_4b1130
  reg.state = (s32)((u32)(0));  // @27_4b1130
  PV[1] = (u32)(eax);  // @28_4b1130
  ecx = (u32)(edi + 86);  // @29_4b1130
  eax = ext_4cbee0_thiscall2(ecx, PV[1]);  // @30_4b1130
  ecx = edx = 0;  // @31_4b1130
  ecx = (u32)(EBP - 144);  // @32_4b1130
  eax = ext_4cbec0_thiscall1(ecx);  // @33_4b1130
  ecx = edx = 0;  // @34_4b1130
  L4b11c6:;
  SEH_LEAVE();  // @36_4b1130
  ext_633654(G(u32, 0x6f5630));  // @37_4b1130
  return eax;  // @38_4b1130
}
PCREG(4b1130, lifted_4b1130);

extern "C" u32 THISCALL lifted_566bc0(u32 ecx_in) {
  SEH_ENTER(0x66c3da);  // @h_566bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_566bc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_566bc0
  eax = ext_561020_thiscall1(ecx);  // @2_566bc0
  ecx = edx = 0;  // @3_566bc0
  edi = (u32)(esi + 388);  // @4_566bc0
  reg.state = (s32)((u32)(0));  // @5_566bc0
  { u32 v = (u32)((u32)(6975128)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_566bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 392), &v, sizeof v); }  // @7_566bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 404), &v, sizeof v); }  // @8_566bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 412), &v, sizeof v); }  // @9_566bc0
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @10_566bc0
  eax = ext_41e290_cdecl1((u32)(264));  // @11_566bc0
  ecx = edx = 0;  // @12_566bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @13_566bc0
  reg.state = (s32)((u32)(1));  // @14_566bc0
  if ((eax & eax) == 0) goto L566c56;  // @15_566bc0
  PV[0] = (u32)(edi);  // @16_566bc0
  ecx = eax;  // @17_566bc0
  eax = ext_4d8330_thiscall4(ecx, (u32)(6791420), (u32)(6975376), PV[0]);  // @18_566bc0
  ecx = edx = 0;  // @19_566bc0
  edx = eax;  // @20_566bc0
  goto L566c58;  // @21_566bc0
  L566c56:;
  edx = 0;  // @23_566bc0
  L566c58:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @25_566bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_566bc0
  PV[1] = (u32)(edx);  // @27_566bc0
  reg.state = (s32)((u32)(0));  // @28_566bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_566bc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[1]);  // @30_566bc0
  ecx = edx = 0;  // @31_566bc0
  eax = esi;  // @32_566bc0
  SEH_LEAVE();  // @33_566bc0
  return eax;  // @34_566bc0
}
PCREG(566bc0, lifted_566bc0);



