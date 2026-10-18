// batch200073.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc6e0_fastcall2(u32, u32) __asm__("ext_4cc6e0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_41cfd0_thiscall1(u32) __asm__("ext_41cfd0");
extern "C" u32 THISCALL ext_423ff0_thiscall2(u32, u32) __asm__("ext_423ff0");
extern "C" u32 THISCALL ext_42c9a0_thiscall1(u32) __asm__("ext_42c9a0");
extern "C" u32 THISCALL ext_433f30_thiscall1(u32) __asm__("ext_433f30");
extern "C" u32 THISCALL ext_439fd0_thiscall2(u32, u32) __asm__("ext_439fd0");
extern "C" u32 THISCALL ext_43ea20_thiscall1(u32) __asm__("ext_43ea20");
extern "C" u32 THISCALL ext_440e10_thiscall2(u32, u32) __asm__("ext_440e10");
extern "C" u32 THISCALL ext_44b610_thiscall1(u32) __asm__("ext_44b610");
extern "C" u32 THISCALL ext_45f3c0_thiscall2(u32, u32) __asm__("ext_45f3c0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_48fa10_thiscall1(u32) __asm__("ext_48fa10");
extern "C" u32 THISCALL ext_48fa70_thiscall1(u32) __asm__("ext_48fa70");
extern "C" u32 THISCALL ext_4958e0_thiscall1(u32) __asm__("ext_4958e0");
extern "C" u32 THISCALL ext_49b680_thiscall1(u32) __asm__("ext_49b680");
extern "C" u32 THISCALL ext_49df00_thiscall1(u32) __asm__("ext_49df00");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cbf30_thiscall2(u32, u32) __asm__("ext_4cbf30");
extern "C" u32 THISCALL ext_4cc130_thiscall2(u32, u32) __asm__("ext_4cc130");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4e5000_thiscall1(u32) __asm__("ext_4e5000");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4ee210_thiscall4(u32, u32, u32, u32) __asm__("ext_4ee210");
extern "C" u32 THISCALL ext_4ff7b0_thiscall1(u32) __asm__("ext_4ff7b0");
extern "C" u32 THISCALL ext_5378a0_thiscall1(u32) __asm__("ext_5378a0");
extern "C" u32 THISCALL ext_54abf0_thiscall1(u32) __asm__("ext_54abf0");
extern "C" u32 THISCALL ext_561020_thiscall1(u32) __asm__("ext_561020");
extern "C" u32 THISCALL ext_5b6d00_thiscall1(u32) __asm__("ext_5b6d00");
extern "C" u32 THISCALL ext_5eaab0_thiscall3(u32, u32, u32) __asm__("ext_5eaab0");
extern "C" u32 THISCALL ext_5f12d0_thiscall1(u32) __asm__("ext_5f12d0");
extern "C" u32 THISCALL ext_604650_thiscall1(u32) __asm__("ext_604650");
extern "C" u32 THISCALL ext_607f60_thiscall4(u32, u32, u32, u32) __asm__("ext_607f60");
extern "C" u32 THISCALL ext_63ed10_thiscall1(u32) __asm__("ext_63ed10");
extern "C" u32 THISCALL ext_6590a0_thiscall2(u32, u32) __asm__("ext_6590a0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5d6040(u32 ecx_in) {
  SEH_ENTER(0x66c8ce);  // @h_5d6040
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5d6040
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5d6040
  eax = ext_469870_thiscall1(ecx);  // @2_5d6040
  ecx = edx = 0;  // @3_5d6040
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5d6040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5d6040
  ecx = (u32)(EBP - 88);  // @6_5d6040
  reg.state = (s32)((u32)(0));  // @7_5d6040
  { u32 v = (u32)((u32)(7035332)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_5d6040
  eax = ext_469870_thiscall1(ecx);  // @9_5d6040
  ecx = edx = 0;  // @10_5d6040
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @11_5d6040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @12_5d6040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @13_5d6040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_5d6040
  edx = (u32)(EBP - 88);  // @15_5d6040
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @16_5d6040
  reg.state = (s32)((u32)(1));  // @17_5d6040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_5d6040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5d6040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(edx));  // @20_5d6040
  ecx = edx = 0;  // @21_5d6040
  eax = esi;  // @22_5d6040
  SEH_LEAVE();  // @23_5d6040
  return eax;  // @24_5d6040
}
PCREG(5d6040, lifted_5d6040);

extern "C" u32 THISCALL lifted_42ba60(u32 ecx_in) {
  SEH_ENTER(0x66b0fc);  // @h_42ba60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_42ba60
  ecx = (u32)(esi + 12);  // @1_42ba60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_42ba60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @3_42ba60
  eax = (eax - edx);  // @4_42ba60
  reg.state = (s32)((u32)(0));  // @5_42ba60
  if ((edx & edx) == 0) goto L42baa5;  // @6_42ba60
  if ((eax & eax) == 0) goto L42baa5;  // @7_42ba60
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @8_42ba60
  ecx = edx = 0;  // @9_42ba60
  L42baa5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_42ba60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @12_42ba60
  eax = (eax - ecx);  // @13_42ba60
  reg.state = (s32)((u32)(1));  // @14_42ba60
  if ((ecx & ecx) == 0) goto L42bac4;  // @15_42ba60
  if ((eax & eax) == 0) goto L42bac4;  // @16_42ba60
  ecx = esi;  // @17_42ba60
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @18_42ba60
  ecx = edx = 0;  // @19_42ba60
  L42bac4:;
  SEH_LEAVE();  // @21_42ba60
  return eax;  // @22_42ba60
}
PCREG(42ba60, lifted_42ba60);

extern "C" u32 THISCALL lifted_4cd240(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669286);  // @h_4cd240
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4cd240
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1_4cd240
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_4cd240
  reg.state = (s32)((u32)(0));  // @3_4cd240
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_4cd240
  if ((edi & edi) == 0) goto L4cd290;  // @5_4cd240
  L4cd281:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_4cd240
  ecx = esi;  // @8_4cd240
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_4cd240
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(edi));  // @10_4cd240
  ecx = edx = 0;  // @11_4cd240
  if ((edi & edi) != 0) goto L4cd281;  // @12_4cd240
  L4cd290:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @14_4cd240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @15_4cd240
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4cd2af;  // @16_4cd240
  eax = ext_634273_cdecl2((u32)(esi), (u32)(36));  // @17_4cd240
  ecx = edx = 0;  // @18_4cd240
  L4cd2af:;
  eax = esi;  // @20_4cd240
  SEH_LEAVE();  // @21_4cd240
  return eax;  // @22_4cd240
}
PCREG(4cd240, lifted_4cd240);

extern "C" u32 STDCALL lifted_424080(u32 a0, u32 a1) {
  SEH_ENTER(0x66428b);  // @h_424080
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_424080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_424080
  if ((ecx & ecx) == 0) goto L4240fa;  // @2_424080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) == (u32)(0)) goto L4240fa;  // @3_424080
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_424080
  ecx = (u32)(EBP - 144);  // @5_424080
  eax = ext_4cbe80_thiscall2(ecx, (u32)(ecx));  // @6_424080
  ecx = edx = 0;  // @7_424080
  eax = (u32)(EBP - 144);  // @8_424080
  reg.state = (s32)((u32)(0));  // @9_424080
  ecx = (u32)(esi + 9563);  // @10_424080
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @11_424080
  ecx = edx = 0;  // @12_424080
  ecx = (u32)(EBP - 144);  // @13_424080
  eax = ext_4cbec0_thiscall1(ecx);  // @14_424080
  ecx = edx = 0;  // @15_424080
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6975), &v, sizeof v); }  // @16_424080
  goto L42410f;  // @17_424080
  L4240fa:;
  if ((eax & eax) == 0) goto L42410f;  // @19_424080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L42410f;  // @20_424080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_424080
  eax = ext_423ff0_thiscall2(ecx, (u32)(eax));  // @22_424080
  ecx = edx = 0;  // @23_424080
  L42410f:;
  SEH_LEAVE();  // @25_424080
  ext_633654(G(u32, 0x6f5630));  // @26_424080
  return eax;  // @27_424080
}
PCREG(424080, lifted_424080);

extern "C" u32 THISCALL lifted_45a0e0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_45a0e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45a0e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @1_45a0e0
  { u32 v = (u32)((u32)(6829984)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_45a0e0
  if ((ecx & ecx) == 0) goto L45a164;  // @3_45a0e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_45a0e0
  edx = (u32)(EBP - 24);  // @5_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @6_45a0e0
  ecx = edx = 0;  // @7_45a0e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @8_45a0e0
  edx = (u32)(EBP - 24);  // @9_45a0e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @11_45a0e0
  ecx = edx = 0;  // @12_45a0e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L45a164;  // @13_45a0e0
  L45a130:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_45a0e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @16_45a0e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @18_45a0e0
  ecx = edx = 0;  // @19_45a0e0
  if ((eax & eax) == 0) goto L45a152;  // @20_45a0e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_45a0e0
  ecx = eax;  // @22_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @23_45a0e0
  ecx = edx = 0;  // @24_45a0e0
  L45a152:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @26_45a0e0
  edx = (u32)(EBP - 24);  // @27_45a0e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @29_45a0e0
  ecx = edx = 0;  // @30_45a0e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L45a130;  // @31_45a0e0
  L45a164:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @33_45a0e0
  if ((ecx & ecx) == 0) goto L45a171;  // @34_45a0e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_45a0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @36_45a0e0
  ecx = edx = 0;  // @37_45a0e0
  L45a171:;
  ecx = esi;  // @39_45a0e0
  eax = ext_43ea20_thiscall1(ecx);  // @40_45a0e0
  ecx = edx = 0;  // @41_45a0e0
  SEH_LEAVE();  // @42_45a0e0
  return eax;  // @43_45a0e0
}
PCREG(45a0e0, lifted_45a0e0);

extern "C" u32 THISCALL lifted_45cb50(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666666);  // @h_45cb50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_45cb50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_45cb50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @3_45cb50
  if ((edx & edx) == 0) goto L45cbee;  // @4_45cb50
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L45cba8;  // @5_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_45cb50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 84), sizeof v); (u32)v; });  // @8_45cb50
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; })) goto L45cbee;  // @9_45cb50
  L45cba8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 84), sizeof v); (u32)v; });  // @11_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_45cb50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 468)))(ecx, (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @13_45cb50
  ecx = edx = 0;  // @14_45cb50
  ecx = (u32)(EBP - 144);  // @15_45cb50
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @16_45cb50
  ecx = edx = 0;  // @17_45cb50
  eax = (u32)(EBP - 144);  // @18_45cb50
  reg.state = (s32)((u32)(0));  // @19_45cb50
  ecx = edi;  // @20_45cb50
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @21_45cb50
  ecx = edx = 0;  // @22_45cb50
  ecx = (u32)(EBP - 144);  // @23_45cb50
  reg.state = (s32)((u32)(4294967295));  // @24_45cb50
  eax = ext_4cbec0_thiscall1(ecx);  // @25_45cb50
  ecx = edx = 0;  // @26_45cb50
  L45cbee:;
  ecx = (u32)(EBP - 272);  // @28_45cb50
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @29_45cb50
  ecx = edx = 0;  // @30_45cb50
  eax = (u32)(EBP - 272);  // @31_45cb50
  reg.state = (s32)((u32)(1));  // @32_45cb50
  ecx = edi;  // @33_45cb50
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @34_45cb50
  ecx = edx = 0;  // @35_45cb50
  ecx = (u32)(EBP - 272);  // @36_45cb50
  eax = ext_4cbec0_thiscall1(ecx);  // @37_45cb50
  ecx = edx = 0;  // @38_45cb50
  SEH_LEAVE();  // @39_45cb50
  ext_633654(G(u32, 0x6f5630));  // @40_45cb50
  return eax;  // @41_45cb50
}
PCREG(45cb50, lifted_45cb50);

extern "C" u32 THISCALL lifted_57c6f0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66b1bb);  // @h_57c6f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_57c6f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_57c6f0
  ecx = (u32)(ebx + 44);  // @3_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @4_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @6_57c6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @7_57c6f0
  eax = ext_4cbeb0_thiscall1(ecx);  // @8_57c6f0
  ecx = edx = 0;  // @9_57c6f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @10_57c6f0
  ecx = (u32)(EBP + 12);  // @11_57c6f0
  ecx = edi;  // @12_57c6f0
  reg.state = (s32)((u32)(0));  // @13_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @15_57c6f0
  ecx = edx = 0;  // @16_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @20_57c6f0
  ecx = edx = 0;  // @21_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @22_57c6f0
  esi = (u32)(ebx + 12);  // @23_57c6f0
  ebx = (u32)(8);  // @24_57c6f0
  L57c764:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_57c6f0
  ecx = (u32)(EBP + 12);  // @27_57c6f0
  ecx = edi;  // @28_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @29_57c6f0
  ecx = edx = 0;  // @30_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @34_57c6f0
  ecx = edx = 0;  // @35_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @36_57c6f0
  esi = (u32)(esi + 4);  // @37_57c6f0
  ebx = (ebx - (u32)(1));  // @38_57c6f0
  if (ebx != 0) goto L57c764;  // @39_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_57c6f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @42_57c6f0
  ecx = edx = 0;  // @43_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @44_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @45_57c6f0
  eax = ecx;  // @46_57c6f0
  SEH_LEAVE();  // @47_57c6f0
  return eax;  // @48_57c6f0
}
PCREG(57c6f0, lifted_57c6f0);

extern "C" u32 THISCALL lifted_602530(u32 ecx_in) {
  SEH_ENTER(0x66da28);  // @h_602530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_602530
  ecx = (u32)(esi + 36);  // @1_602530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_602530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @3_602530
  eax = (eax - edx);  // @4_602530
  reg.state = (s32)((u32)(0));  // @5_602530
  if ((edx & edx) == 0) goto L602575;  // @6_602530
  if ((eax & eax) == 0) goto L602575;  // @7_602530
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @8_602530
  ecx = edx = 0;  // @9_602530
  L602575:;
  ecx = (u32)(esi + 24);  // @11_602530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_602530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @13_602530
  eax = (eax - edx);  // @14_602530
  reg.state = (s32)((u32)(1));  // @15_602530
  if ((edx & edx) == 0) goto L602595;  // @16_602530
  if ((eax & eax) == 0) goto L602595;  // @17_602530
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @18_602530
  ecx = edx = 0;  // @19_602530
  L602595:;
  ecx = (u32)(esi + 12);  // @21_602530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_602530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @23_602530
  eax = (eax - edx);  // @24_602530
  reg.state = (s32)((u32)(2));  // @25_602530
  if ((edx & edx) == 0) goto L6025b5;  // @26_602530
  if ((eax & eax) == 0) goto L6025b5;  // @27_602530
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @28_602530
  ecx = edx = 0;  // @29_602530
  L6025b5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_602530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @32_602530
  eax = (eax - ecx);  // @33_602530
  reg.state = (s32)((u32)(3));  // @34_602530
  if ((ecx & ecx) == 0) goto L6025d4;  // @35_602530
  if ((eax & eax) == 0) goto L6025d4;  // @36_602530
  ecx = esi;  // @37_602530
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @38_602530
  ecx = edx = 0;  // @39_602530
  L6025d4:;
  SEH_LEAVE();  // @41_602530
  return eax;  // @42_602530
}
PCREG(602530, lifted_602530);

extern "C" u32 THISCALL lifted_4269e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6685bb);  // @h_4269e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  if ((eax & eax) != 0) goto L426a63;  // @8_4269e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_4269e0
  edx = (u32)(EBP - 144);  // @10_4269e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4269e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 320)))(ecx, (u32)(edx));  // @12_4269e0
  ecx = edx = 0;  // @13_4269e0
  ecx = ebx;  // @14_4269e0
  reg.state = (s32)((u32)(0));  // @15_4269e0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @16_4269e0
  ecx = edx = 0;  // @17_4269e0
  ecx = (u32)(EBP - 144);  // @18_4269e0
  reg.state = (s32)((u32)(4294967295));  // @19_4269e0
  eax = ext_4cbec0_thiscall1(ecx);  // @20_4269e0
  ecx = edx = 0;  // @21_4269e0
  L426a63:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_4269e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4269e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @25_4269e0
  ecx = edx = 0;  // @26_4269e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @27_4269e0
  esi = eax;  // @28_4269e0
  ecx = (ecx + (u32)(140));  // @29_4269e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_4269e0
  eax = ext_4cc1d0_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @31_4269e0
  ecx = edx = 0;  // @32_4269e0
  ecx = ebx;  // @33_4269e0
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @34_4269e0
  ecx = edx = 0;  // @35_4269e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edi + 408)))(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }), (u32)(6786332), (u32)(eax));  // @36_4269e0
  ecx = edx = 0;  // @37_4269e0
  SEH_LEAVE();  // @38_4269e0
  ext_633654(G(u32, 0x6f5630));  // @39_4269e0
  return eax;  // @40_4269e0
}
PCREG(4269e0, lifted_4269e0);

extern "C" u32 THISCALL lifted_4ccef0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4ccef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ccef0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1_4ccef0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_4ccef0
  reg.state = (s32)((u32)(0));  // @3_4ccef0
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_4ccef0
  if ((edi & edi) == 0) goto L4ccf40;  // @5_4ccef0
  L4ccf31:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_4ccef0
  ecx = esi;  // @8_4ccef0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_4ccef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(edi));  // @10_4ccef0
  ecx = edx = 0;  // @11_4ccef0
  if ((edi & edi) != 0) goto L4ccf31;  // @12_4ccef0
  L4ccf40:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @14_4ccef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @15_4ccef0
  SEH_LEAVE();  // @16_4ccef0
  return eax;  // @17_4ccef0
}
PCREG(4ccef0, lifted_4ccef0);

extern "C" u32 THISCALL lifted_4cd050(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cd050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4cd050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_4cd050
  { u32 v = (u32)((u32)(6903876)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4cd050
  if ((ecx & ecx) == 0) goto L4cd089;  // @3_4cd050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4cd050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_4cd050
  ecx = edx = 0;  // @6_4cd050
  L4cd089:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @8_4cd050
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @9_4cd050
  reg.state = (s32)((u32)(0));  // @10_4cd050
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_4cd050
  if ((edi & edi) == 0) goto L4cd0b3;  // @12_4cd050
  L4cd0a4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_4cd050
  ecx = esi;  // @15_4cd050
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @16_4cd050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(edi));  // @17_4cd050
  ecx = edx = 0;  // @18_4cd050
  if ((edi & edi) != 0) goto L4cd0a4;  // @19_4cd050
  L4cd0b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @21_4cd050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @22_4cd050
  SEH_LEAVE();  // @23_4cd050
  return eax;  // @24_4cd050
}
PCREG(4cd050, lifted_4cd050);

extern "C" u32 THISCALL lifted_44c060(u32 ecx_in) {
  SEH_ENTER(0x665c56);  // @h_44c060
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edx = ecx;  // @0_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_44c060
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }) == (u32)(0)) goto L44c0df;  // @2_44c060
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @3_44c060
  if ((edx & edx) == 0) goto L44c0df;  // @4_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @5_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_44c060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(edx));  // @7_44c060
  ecx = edx = 0;  // @8_44c060
  esi = eax;  // @9_44c060
  if ((esi & esi) == 0) goto L44c0df;  // @10_44c060
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_44c060
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L44c0df;  // @12_44c060
  ecx = esi;  // @13_44c060
  eax = ext_44b610_thiscall1(ecx);  // @14_44c060
  ecx = edx = 0;  // @15_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_44c060
  reg.state = (s32)((u32)(0));  // @17_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @18_44c060
  if ((ecx & ecx) == 0) goto L44c0df;  // @19_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_44c060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 280)))(ecx, (u32)(esi));  // @21_44c060
  ecx = edx = 0;  // @22_44c060
  L44c0df:;
  SEH_LEAVE();  // @24_44c060
  return eax;  // @25_44c060
}
PCREG(44c060, lifted_44c060);

extern "C" u32 THISCALL lifted_4b6d70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668c0f);  // @h_4b6d70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4b6d70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b6d70
  if ((esi & esi) != 0) goto L4b6ddf;  // @2_4b6d70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; }) == esi) goto L4b6db3;  // @3_4b6d70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @4_4b6d70
  if ((eax & eax) == 0) goto L4b6db2;  // @5_4b6d70
  eax = ((u32(STDCALL *)(void))(eax))();  // @6_4b6d70
  ecx = edx = 0;  // @7_4b6d70
  goto L4b6db3;  // @8_4b6d70
  L4b6db2:;
  __builtin_trap();  // @10_4b6d70
  L4b6db3:;
  eax = ext_41e290_cdecl1((u32)(40));  // @12_4b6d70
  ecx = edx = 0;  // @13_4b6d70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_4b6d70
  reg.state = (s32)((u32)(0));  // @15_4b6d70
  if ((eax & eax) == 0) goto L4b6dd8;  // @16_4b6d70
  ecx = eax;  // @17_4b6d70
  eax = ext_4cca60_thiscall3(ecx, (u32)(4), (u32)(2));  // @18_4b6d70
  ecx = edx = 0;  // @19_4b6d70
  goto L4b6dda;  // @20_4b6d70
  L4b6dd8:;
  eax = 0;  // @22_4b6d70
  L4b6dda:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340852), &v, sizeof v); }  // @24_4b6d70
  L4b6ddf:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @26_4b6d70
  SEH_LEAVE();  // @27_4b6d70
  return eax;  // @28_4b6d70
}
PCREG(4b6d70, lifted_4b6d70);

extern "C" u32 THISCALL lifted_614f10(u32 ecx_in) {
  SEH_ENTER(0x66e46d);  // @h_614f10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_614f10
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) != (u32)(0)) goto L614fe6;  // @1_614f10
  eax = ext_41e290_cdecl1((u32)(20));  // @2_614f10
  ecx = edx = 0;  // @3_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_614f10
  reg.state = (s32)((u32)(0));  // @5_614f10
  if ((eax & eax) == 0) goto L614f66;  // @6_614f10
  ecx = eax;  // @7_614f10
  eax = ext_6590a0_thiscall2(ecx, (u32)(131072));  // @8_614f10
  ecx = edx = 0;  // @9_614f10
  goto L614f68;  // @10_614f10
  L614f66:;
  eax = 0;  // @12_614f10
  L614f68:;
  reg.state = (s32)((u32)(4294967295));  // @14_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 47528), &v, sizeof v); }  // @15_614f10
  eax = ext_41e290_cdecl1((u32)(20));  // @16_614f10
  ecx = edx = 0;  // @17_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @18_614f10
  reg.state = (s32)((u32)(1));  // @19_614f10
  if ((eax & eax) == 0) goto L614f9b;  // @20_614f10
  ecx = eax;  // @21_614f10
  eax = ext_6590a0_thiscall2(ecx, (u32)(32768));  // @22_614f10
  ecx = edx = 0;  // @23_614f10
  goto L614f9d;  // @24_614f10
  L614f9b:;
  eax = 0;  // @26_614f10
  L614f9d:;
  reg.state = (s32)((u32)(4294967295));  // @28_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 47532), &v, sizeof v); }  // @29_614f10
  eax = ext_41e290_cdecl1((u32)(20));  // @30_614f10
  ecx = edx = 0;  // @31_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @32_614f10
  reg.state = (s32)((u32)(2));  // @33_614f10
  if ((eax & eax) == 0) goto L614fd0;  // @34_614f10
  ecx = eax;  // @35_614f10
  eax = ext_6590a0_thiscall2(ecx, (u32)(229376));  // @36_614f10
  ecx = edx = 0;  // @37_614f10
  goto L614fd2;  // @38_614f10
  L614fd0:;
  eax = 0;  // @40_614f10
  L614fd2:;
  ecx = esi;  // @42_614f10
  reg.state = (s32)((u32)(4294967295));  // @43_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 47536), &v, sizeof v); }  // @44_614f10
  eax = ext_63ed10_thiscall1(ecx);  // @45_614f10
  ecx = edx = 0;  // @46_614f10
  L614fe6:;
  SEH_LEAVE();  // @48_614f10
  return eax;  // @49_614f10
}
PCREG(614f10, lifted_614f10);

extern "C" u32 THISCALL lifted_42c380(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d7c);  // @h_42c380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42c380
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42c380
  ecx = (u32)(EBP - 144);  // @2_42c380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @3_42c380
  eax = ext_4cbeb0_thiscall1(ecx);  // @4_42c380
  ecx = edx = 0;  // @5_42c380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_42c380
  ecx = (u32)(EBP - 400);  // @7_42c380
  ecx = esi;  // @8_42c380
  reg.state = (s32)((u32)(0));  // @9_42c380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(ecx));  // @10_42c380
  ecx = edx = 0;  // @11_42c380
  ecx = (u32)(EBP - 144);  // @12_42c380
  reg.state = (s32)((u32)(1));  // @13_42c380
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @14_42c380
  ecx = edx = 0;  // @15_42c380
  ecx = (u32)(EBP - 400);  // @16_42c380
  reg.state = (s32)((u32)(0));  // @17_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @18_42c380
  ecx = edx = 0;  // @19_42c380
  ecx = (u32)(EBP - 144);  // @20_42c380
  eax = ext_4cc5f0_thiscall1(ecx);  // @21_42c380
  ecx = edx = 0;  // @22_42c380
  if ((eax & eax) != 0) goto L42c41d;  // @23_42c380
  eax = (u32)(EBP - 144);  // @24_42c380
  ecx = edi;  // @25_42c380
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @26_42c380
  ecx = edx = 0;  // @27_42c380
  goto L42c48c;  // @28_42c380
  L42c41d:;
  ecx = (u32)(EBP - 272);  // @30_42c380
  eax = ext_4cbeb0_thiscall1(ecx);  // @31_42c380
  ecx = edx = 0;  // @32_42c380
  ecx = (u32)(EBP - 400);  // @33_42c380
  reg.state = (s32)((u32)(2));  // @34_42c380
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789684));  // @35_42c380
  ecx = edx = 0;  // @36_42c380
  eax = (u32)(EBP - 400);  // @37_42c380
  reg.state = (s32)((u32)(3));  // @38_42c380
  ecx = (u32)(EBP - 272);  // @39_42c380
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @40_42c380
  ecx = edx = 0;  // @41_42c380
  ecx = (u32)(EBP - 400);  // @42_42c380
  reg.state = (s32)((u32)(2));  // @43_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @44_42c380
  ecx = edx = 0;  // @45_42c380
  eax = (u32)(EBP - 144);  // @46_42c380
  ecx = (u32)(EBP - 272);  // @47_42c380
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @48_42c380
  ecx = edx = 0;  // @49_42c380
  eax = (u32)(EBP - 272);  // @50_42c380
  ecx = edi;  // @51_42c380
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @52_42c380
  ecx = edx = 0;  // @53_42c380
  ecx = (u32)(EBP - 272);  // @54_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @55_42c380
  ecx = edx = 0;  // @56_42c380
  L42c48c:;
  ecx = (u32)(EBP - 144);  // @58_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @59_42c380
  ecx = edx = 0;  // @60_42c380
  eax = edi;  // @61_42c380
  SEH_LEAVE();  // @62_42c380
  ext_633654(G(u32, 0x6f5630));  // @63_42c380
  return eax;  // @64_42c380
}
PCREG(42c380, lifted_42c380);

extern "C" u32 THISCALL lifted_42fcc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665213);  // @h_42fcc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_42fcc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42fcc0
  ecx = esi;  // @2_42fcc0
  reg.state = (s32)((u32)(0));  // @3_42fcc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @4_42fcc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @5_42fcc0
  eax = ext_4cbeb0_thiscall1(ecx);  // @6_42fcc0
  ecx = edx = 0;  // @7_42fcc0
  edi = (u32)(ebx + 547);  // @8_42fcc0
  reg.state = (s32)((u32)(0));  // @9_42fcc0
  ecx = edi;  // @10_42fcc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @11_42fcc0
  eax = ext_4cc5f0_thiscall1(ecx);  // @12_42fcc0
  ecx = edx = 0;  // @13_42fcc0
  if ((eax & eax) == 0) goto L42fd3d;  // @14_42fcc0
  ecx = esi;  // @15_42fcc0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(edi));  // @16_42fcc0
  ecx = edx = 0;  // @17_42fcc0
  goto L42fda0;  // @18_42fcc0
  L42fd3d:;
  ecx = (u32)(EBP - 144);  // @20_42fcc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789684));  // @21_42fcc0
  ecx = edx = 0;  // @22_42fcc0
  eax = (u32)(EBP - 144);  // @23_42fcc0
  reg.state = (s32)((u32)(1));  // @24_42fcc0
  ecx = esi;  // @25_42fcc0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @26_42fcc0
  ecx = edx = 0;  // @27_42fcc0
  ecx = (u32)(EBP - 144);  // @28_42fcc0
  reg.state = (s32)((u32)(0));  // @29_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @30_42fcc0
  ecx = edx = 0;  // @31_42fcc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_42fcc0
  ecx = (u32)(EBP - 144);  // @33_42fcc0
  ecx = ebx;  // @34_42fcc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(ecx));  // @35_42fcc0
  ecx = edx = 0;  // @36_42fcc0
  ecx = esi;  // @37_42fcc0
  reg.state = (s32)((u32)(2));  // @38_42fcc0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @39_42fcc0
  ecx = edx = 0;  // @40_42fcc0
  ecx = (u32)(EBP - 144);  // @41_42fcc0
  reg.state = (s32)((u32)(0));  // @42_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @43_42fcc0
  ecx = edx = 0;  // @44_42fcc0
  L42fda0:;
  ecx = (u32)(EBP - 144);  // @46_42fcc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789688));  // @47_42fcc0
  ecx = edx = 0;  // @48_42fcc0
  eax = (u32)(EBP - 144);  // @49_42fcc0
  reg.state = (s32)((u32)(3));  // @50_42fcc0
  ecx = esi;  // @51_42fcc0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @52_42fcc0
  ecx = edx = 0;  // @53_42fcc0
  ecx = (u32)(EBP - 144);  // @54_42fcc0
  eax = ext_4cbec0_thiscall1(ecx);  // @55_42fcc0
  ecx = edx = 0;  // @56_42fcc0
  eax = esi;  // @57_42fcc0
  SEH_LEAVE();  // @58_42fcc0
  ext_633654(G(u32, 0x6f5630));  // @59_42fcc0
  return eax;  // @60_42fcc0
}
PCREG(42fcc0, lifted_42fcc0);

extern "C" u32 THISCALL lifted_444eb0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_444eb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_444eb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_444eb0
  eax = ext_440e10_thiscall2(ecx, (u32)(esi));  // @2_444eb0
  ecx = edx = 0;  // @3_444eb0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L444ef7;  // @4_444eb0
  SEH_LEAVE();  // @5_444eb0
  return eax;  // @6_444eb0
  L444ef7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_444eb0
  eax = (u32)(edi + 148);  // @9_444eb0
  ecx = esi;  // @10_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @11_444eb0
  ecx = edx = 0;  // @12_444eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_444eb0
  eax = (u32)(edi + 152);  // @14_444eb0
  ecx = esi;  // @15_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @16_444eb0
  ecx = edx = 0;  // @17_444eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_444eb0
  eax = (u32)(edi + 192);  // @19_444eb0
  ecx = esi;  // @20_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @21_444eb0
  ecx = edx = 0;  // @22_444eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_444eb0
  ecx = (u32)(EBP + 8);  // @24_444eb0
  ecx = esi;  // @25_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @26_444eb0
  ecx = edx = 0;  // @27_444eb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L444f70;  // @28_444eb0
  eax = ext_41e290_cdecl1((u32)(28));  // @29_444eb0
  ecx = edx = 0;  // @30_444eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @31_444eb0
  reg.state = (s32)((u32)(0));  // @32_444eb0
  if ((eax & eax) == 0) goto L444f59;  // @33_444eb0
  ecx = eax;  // @34_444eb0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @35_444eb0
  ecx = edx = 0;  // @36_444eb0
  ecx = eax;  // @37_444eb0
  goto L444f5b;  // @38_444eb0
  L444f59:;
  ecx = 0;  // @40_444eb0
  L444f5b:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 164), &v, sizeof v); }  // @42_444eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_444eb0
  ecx = esi;  // @44_444eb0
  reg.state = (s32)((u32)(4294967295));  // @45_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(ecx));  // @46_444eb0
  ecx = edx = 0;  // @47_444eb0
  L444f70:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_444eb0
  eax = (u32)(edi + 172);  // @50_444eb0
  ecx = esi;  // @51_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @52_444eb0
  ecx = edx = 0;  // @53_444eb0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @54_444eb0
  SEH_LEAVE();  // @55_444eb0
  return eax;  // @56_444eb0
}
PCREG(444eb0, lifted_444eb0);

extern "C" u32 THISCALL lifted_641a40(u32 ecx_in) {
  SEH_ENTER(0x66e926);  // @h_641a40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @1_641a40
  ecx = edx = 0;  // @2_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_641a40
  reg.state = (s32)((u32)(0));  // @4_641a40
  if ((eax & eax) == 0) goto L641a97;  // @5_641a40
  ecx = (u32)(esi + 12);  // @6_641a40
  ecx = eax;  // @7_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088160), (u32)(0), (u32)(ecx));  // @8_641a40
  ecx = edx = 0;  // @9_641a40
  edx = eax;  // @10_641a40
  goto L641a99;  // @11_641a40
  L641a97:;
  edx = 0;  // @13_641a40
  L641a99:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 29), &v, sizeof v); }  // @15_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_641a40
  reg.state = (s32)((u32)(4294967295));  // @17_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @19_641a40
  ecx = edx = 0;  // @20_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @21_641a40
  ecx = edx = 0;  // @22_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @23_641a40
  reg.state = (s32)((u32)(1));  // @24_641a40
  if ((eax & eax) == 0) goto L641ae3;  // @25_641a40
  ecx = (u32)(esi + 4);  // @26_641a40
  ecx = eax;  // @27_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088168), (u32)(0), (u32)(ecx));  // @28_641a40
  ecx = edx = 0;  // @29_641a40
  edx = eax;  // @30_641a40
  goto L641ae5;  // @31_641a40
  L641ae3:;
  edx = 0;  // @33_641a40
  L641ae5:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @35_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_641a40
  reg.state = (s32)((u32)(4294967295));  // @37_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @39_641a40
  ecx = edx = 0;  // @40_641a40
  eax = ext_41e290_cdecl1((u32)(264));  // @41_641a40
  ecx = edx = 0;  // @42_641a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @43_641a40
  reg.state = (s32)((u32)(2));  // @44_641a40
  if ((eax & eax) == 0) goto L641b2f;  // @45_641a40
  ecx = (u32)(esi + 8);  // @46_641a40
  ecx = eax;  // @47_641a40
  eax = ext_4d8330_thiscall4(ecx, (u32)(7088176), (u32)(0), (u32)(ecx));  // @48_641a40
  ecx = edx = 0;  // @49_641a40
  edx = eax;  // @50_641a40
  goto L641b31;  // @51_641a40
  L641b2f:;
  edx = 0;  // @53_641a40
  L641b31:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @55_641a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_641a40
  reg.state = (s32)((u32)(4294967295));  // @57_641a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_641a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @59_641a40
  ecx = edx = 0;  // @60_641a40
  SEH_LEAVE();  // @61_641a40
  return eax;  // @62_641a40
}
PCREG(641a40, lifted_641a40);

extern "C" u32 THISCALL lifted_4264b0(u32 ecx_in) {
  SEH_ENTER(0x665420);  // @h_4264b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @1_4264b0
  { u32 v = (u32)((u32)(6785124)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_4264b0
  if ((ecx & ecx) == 0) goto L426573;  // @3_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4264b0
  edx = (u32)(EBP - 24);  // @5_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(edx));  // @6_4264b0
  ecx = edx = 0;  // @7_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @8_4264b0
  edx = (u32)(EBP - 24);  // @9_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, (u32)(edx));  // @11_4264b0
  ecx = edx = 0;  // @12_4264b0
  esi = eax;  // @13_4264b0
  if ((esi & esi) == 0) goto L426573;  // @14_4264b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6774960), sizeof v); (u32)v; });  // @15_4264b0
  L426512:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @17_4264b0
  if ((ecx & ecx) == 0) goto L426520;  // @18_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @20_4264b0
  ecx = edx = 0;  // @21_4264b0
  L426520:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @23_4264b0
  if ((ecx & ecx) == 0) goto L42652e;  // @24_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @26_4264b0
  ecx = edx = 0;  // @27_4264b0
  L42652e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @29_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4264b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6785452), (u32)(27));  // @31_4264b0
  ecx = edx = 0;  // @32_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_4264b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6785504), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @34_4264b0
  ecx = edx = 0;  // @35_4264b0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(1));  // @36_4264b0
  ecx = edx = 0;  // @37_4264b0
  eax = ((u32(STDCALL *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @38_4264b0
  ecx = edx = 0;  // @39_4264b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @40_4264b0
  edx = (u32)(EBP - 24);  // @41_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 116)))(ecx, (u32)(edx));  // @43_4264b0
  ecx = edx = 0;  // @44_4264b0
  esi = eax;  // @45_4264b0
  if ((esi & esi) != 0) goto L426512;  // @46_4264b0
  L426573:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 268), sizeof v); (u32)v; });  // @48_4264b0
  if ((ecx & ecx) == 0) goto L426583;  // @49_4264b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4264b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @51_4264b0
  ecx = edx = 0;  // @52_4264b0
  L426583:;
  ecx = edi;  // @54_4264b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7340948), &v, sizeof v); }  // @55_4264b0
  eax = ext_433f30_thiscall1(ecx);  // @56_4264b0
  ecx = edx = 0;  // @57_4264b0
  SEH_LEAVE();  // @58_4264b0
  return eax;  // @59_4264b0
}
PCREG(4264b0, lifted_4264b0);

extern "C" u32 THISCALL lifted_431ce0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x6654b6);  // @h_431ce0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  ecx = (u32)(EBP - 144);  // @10_431ce0
  reg.state = (s32)((u32)(0));  // @11_431ce0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(esi));  // @12_431ce0
  ecx = edx = 0;  // @13_431ce0
  eax = (u32)(EBP - 144);  // @14_431ce0
  reg.state = (s32)((u32)(1));  // @15_431ce0
  ecx = (u32)(EBP - 324);  // @16_431ce0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @17_431ce0
  ecx = edx = 0;  // @18_431ce0
  ecx = (u32)(EBP - 144);  // @19_431ce0
  reg.state = (s32)((u32)(0));  // @20_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @21_431ce0
  ecx = edx = 0;  // @22_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @23_431ce0
  if ((eax & eax) == 0) goto L431d81;  // @24_431ce0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @25_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @26_431ce0
  goto L431d92;  // @27_431ce0
  L431d81:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @29_431ce0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @30_431ce0
  L431d92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @32_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @33_431ce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @34_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 149), &v, sizeof v); }  // @35_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @37_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @38_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @39_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @40_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @41_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @42_431ce0
  ecx = (u32)(EBP - 324);  // @43_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @44_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @45_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @46_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @47_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @48_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @49_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @50_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @51_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @52_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @53_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @54_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @55_431ce0
  ecx = edi;  // @56_431ce0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 159), &v, sizeof v); }  // @57_431ce0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 157), &v, sizeof v); }  // @58_431ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(ecx));  // @59_431ce0
  ecx = edx = 0;  // @60_431ce0
  ecx = (u32)(EBP - 324);  // @61_431ce0
  esi = eax;  // @62_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @63_431ce0
  ecx = edx = 0;  // @64_431ce0
  eax = esi;  // @65_431ce0
  SEH_LEAVE();  // @66_431ce0
  ext_633654(G(u32, 0x6f5630));  // @67_431ce0
  return eax;  // @68_431ce0
}
PCREG(431ce0, lifted_431ce0);

extern "C" u32 THISCALL lifted_4f8720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669a96);  // @h_4f8720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f8720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 443), sizeof v); (u32)v; }) == (u32)(0)) goto L4f887a;  // @1_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 224)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @4_4f8720
  ecx = edx = 0;  // @5_4f8720
  esi = (eax & 0xffff);  // @6_4f8720
  if (esi < (u32)(32)) goto L4f887a;  // @7_4f8720
  if (esi == (u32)(42)) goto L4f887a;  // @8_4f8720
  if (esi == (u32)(60)) goto L4f887a;  // @9_4f8720
  if (esi == (u32)(62)) goto L4f887a;  // @10_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 451), sizeof v); (u32)v; });  // @11_4f8720
  edi = esi;  // @12_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 648), sizeof v); (u32)v; });  // @14_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(edi));  // @15_4f8720
  ecx = edx = 0;  // @16_4f8720
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4f887a;  // @17_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 451), sizeof v); (u32)v; });  // @18_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, (u32)(edi));  // @20_4f8720
  ecx = edx = 0;  // @21_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 443), sizeof v); (u32)v; });  // @22_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 467), sizeof v); (u32)v; }));  // @24_4f8720
  ecx = edx = 0;  // @25_4f8720
  if ((eax & eax) != 0) goto L4f87e0;  // @26_4f8720
  if (esi == (u32)(32)) goto L4f887a;  // @27_4f8720
  L4f87e0:;
  if ((s32)eax >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 471), sizeof v); (u32)v; })) goto L4f887a;  // @29_4f8720
  edx = edi;  // @30_4f8720
  ecx = (u32)(EBP - 24);  // @31_4f8720
  eax = ext_4cc6e0_fastcall2(ecx, edx);  // @32_4f8720
  ecx = edx = 0;  // @33_4f8720
  eax = (u32)(EBP - 24);  // @34_4f8720
  ecx = (u32)(EBP - 152);  // @35_4f8720
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @36_4f8720
  ecx = edx = 0;  // @37_4f8720
  eax = (u32)(EBP - 152);  // @38_4f8720
  reg.state = (s32)((u32)(0));  // @39_4f8720
  eax = (u32)(EBP - 280);  // @40_4f8720
  ecx = (u32)(ebx + 143);  // @41_4f8720
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(eax), (u32)(eax));  // @42_4f8720
  ecx = edx = 0;  // @43_4f8720
  ecx = (u32)(ebx + 143);  // @44_4f8720
  reg.state = (s32)((u32)(1));  // @45_4f8720
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @46_4f8720
  ecx = edx = 0;  // @47_4f8720
  ecx = (u32)(EBP - 280);  // @48_4f8720
  eax = ext_4cbec0_thiscall1(ecx);  // @49_4f8720
  ecx = edx = 0;  // @50_4f8720
  ecx = (u32)(EBP - 152);  // @51_4f8720
  reg.state = (s32)((u32)(4294967295));  // @52_4f8720
  eax = ext_4cbec0_thiscall1(ecx);  // @53_4f8720
  ecx = edx = 0;  // @54_4f8720
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_4f8720
  ecx = (u32)(ebx + 143);  // @56_4f8720
  eax = ext_4cc1d0_thiscall1(ecx);  // @57_4f8720
  ecx = edx = 0;  // @58_4f8720
  ecx = ebx;  // @59_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 864)))(ecx, (u32)(eax));  // @60_4f8720
  ecx = edx = 0;  // @61_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 467), sizeof v); (u32)v; });  // @62_4f8720
  ecx = ebx;  // @63_4f8720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_4f8720
  eax = (eax + 1);  // @65_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 868)))(ecx, (u32)(eax));  // @66_4f8720
  ecx = edx = 0;  // @67_4f8720
  L4f887a:;
  SEH_LEAVE();  // @69_4f8720
  ext_633654(G(u32, 0x6f5630));  // @70_4f8720
  return eax;  // @71_4f8720
}
PCREG(4f8720, lifted_4f8720);

extern "C" u32 THISCALL lifted_45e710(u32 ecx_in) {
  SEH_ENTER(0x66d436);  // @h_45e710
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45e710
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L45e825;  // @1_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_45e710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @3_45e710
  ecx = edx = 0;  // @4_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_45e710
  ecx = esi;  // @6_45e710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @7_45e710
  ecx = edx = 0;  // @8_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @9_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @10_45e710
  if ((edx & edx) == 0) goto L45e78c;  // @11_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7261), sizeof v); (u32)v; });  // @14_45e710
  if (edx < ecx) goto L45e781;  // @15_45e710
  if ((ecx & ecx) == 0) goto L45e781;  // @16_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 8), sizeof v); (u32)v; });  // @17_45e710
  eax = (eax & (u32)(536870911));  // @18_45e710
  eax = (eax + ecx);  // @19_45e710
  if (edx < eax) goto L45e78c;  // @20_45e710
  L45e781:;
  eax = ext_634273_cdecl2((u32)(edx), (u32)(24));  // @22_45e710
  ecx = edx = 0;  // @23_45e710
  L45e78c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @25_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @26_45e710
  if ((eax & eax) == 0) goto L45e7a1;  // @27_45e710
  eax = ext_634273_cdecl2((u32)(eax), (u32)(8));  // @28_45e710
  ecx = edx = 0;  // @29_45e710
  L45e7a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @31_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @32_45e710
  if ((eax & eax) == 0) goto L45e811;  // @33_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @34_45e710
  if ((eax & eax) == 0) goto L45e7c5;  // @35_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @36_45e710
  if ((edx & edx) == 0) goto L45e7c5;  // @37_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @38_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(edx));  // @40_45e710
  ecx = edx = 0;  // @41_45e710
  L45e7c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @43_45e710
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @44_45e710
  if ((edi & edi) == 0) goto L45e811;  // @45_45e710
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @46_45e710
  if ((ebx & ebx) == 0) goto L45e806;  // @47_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @48_45e710
  reg.state = (s32)((u32)(0));  // @49_45e710
  if ((ecx & ecx) == 0) goto L45e7f4;  // @50_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @51_45e710
  if ((edx & edx) == 0) goto L45e7f4;  // @52_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @54_45e710
  ecx = edx = 0;  // @55_45e710
  L45e7f4:;
  eax = ext_634273_cdecl2((u32)(ebx), (u32)(16));  // @57_45e710
  ecx = edx = 0;  // @58_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @59_45e710
  L45e806:;
  eax = ext_634273_cdecl2((u32)(edi), (u32)(8));  // @61_45e710
  ecx = edx = 0;  // @62_45e710
  L45e811:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }), (u32)(32));  // @64_45e710
  ecx = edx = 0;  // @65_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @66_45e710
  L45e825:;
  SEH_LEAVE();  // @68_45e710
  return eax;  // @69_45e710
}
PCREG(45e710, lifted_45e710);

extern "C" u32 THISCALL lifted_59f1a0(u32 ecx_in) {
  SEH_ENTER(0x66bdd6);  // @h_59f1a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_59f1a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1930), sizeof v); (u32)v; }) != (u32)(0)) goto L59f2a0;  // @1_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1938), sizeof v); (u32)v; });  // @2_59f1a0
  if ((ecx & ecx) == 0) goto L59f2a0;  // @3_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @4_59f1a0
  ecx = ebx;  // @5_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1836)))(ecx, (u32)(ecx));  // @6_59f1a0
  ecx = edx = 0;  // @7_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_59f1a0
  esi = eax;  // @9_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @10_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(esi));  // @12_59f1a0
  ecx = edx = 0;  // @13_59f1a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1930), &v, sizeof v); }  // @14_59f1a0
  if ((esi & esi) == 0) goto L59f247;  // @15_59f1a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1946), sizeof v); (u32)v; }) == (u32)(0)) goto L59f237;  // @16_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_59f1a0
  ecx = ebx;  // @18_59f1a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1272)))(ecx);  // @19_59f1a0
  ecx = edx = 0;  // @20_59f1a0
  ecx = eax;  // @21_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @22_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 8)))(ecx, (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1930), sizeof v); (u32)v; }));  // @23_59f1a0
  ecx = edx = 0;  // @24_59f1a0
  goto L59f2a0;  // @25_59f1a0
  L59f237:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_59f1a0
  ecx = esi;  // @28_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @29_59f1a0
  ecx = edx = 0;  // @30_59f1a0
  goto L59f2a0;  // @31_59f1a0
  L59f247:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @33_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7005856), (u32)(1388));  // @35_59f1a0
  ecx = edx = 0;  // @36_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_59f1a0
  edi = eax;  // @38_59f1a0
  eax = (u32)(EBP - 144);  // @39_59f1a0
  ecx = ebx;  // @40_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @41_59f1a0
  ecx = edx = 0;  // @42_59f1a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @43_59f1a0
  ecx = eax;  // @44_59f1a0
  reg.state = (s32)((u32)(0));  // @45_59f1a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @46_59f1a0
  ecx = edx = 0;  // @47_59f1a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(7006872), (u32)(eax));  // @48_59f1a0
  ecx = edx = 0;  // @49_59f1a0
  reg.state = (s32)((u32)(4294967295));  // @50_59f1a0
  ecx = (u32)(EBP - 144);  // @51_59f1a0
  eax = ext_4cbec0_thiscall1(ecx);  // @52_59f1a0
  ecx = edx = 0;  // @53_59f1a0
  L59f2a0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1934), sizeof v); (u32)v; }) != (u32)(0)) goto L59f350;  // @55_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1942), sizeof v); (u32)v; });  // @56_59f1a0
  if ((ecx & ecx) == 0) goto L59f350;  // @57_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @58_59f1a0
  ecx = ebx;  // @59_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1836)))(ecx, (u32)(ecx));  // @60_59f1a0
  ecx = edx = 0;  // @61_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_59f1a0
  esi = eax;  // @63_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @64_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(esi));  // @66_59f1a0
  ecx = edx = 0;  // @67_59f1a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1934), &v, sizeof v); }  // @68_59f1a0
  if ((esi & esi) == 0) goto L59f2fe;  // @69_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @70_59f1a0
  ecx = ebx;  // @71_59f1a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1276)))(ecx);  // @72_59f1a0
  ecx = edx = 0;  // @73_59f1a0
  ecx = eax;  // @74_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 8)))(ecx, (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1934), sizeof v); (u32)v; }));  // @76_59f1a0
  ecx = edx = 0;  // @77_59f1a0
  goto L59f350;  // @78_59f1a0
  L59f2fe:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @80_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7005856), (u32)(1403));  // @82_59f1a0
  ecx = edx = 0;  // @83_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @84_59f1a0
  edi = eax;  // @85_59f1a0
  eax = (u32)(EBP - 272);  // @86_59f1a0
  ecx = ebx;  // @87_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @88_59f1a0
  ecx = edx = 0;  // @89_59f1a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @90_59f1a0
  ecx = eax;  // @91_59f1a0
  reg.state = (s32)((u32)(1));  // @92_59f1a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @93_59f1a0
  ecx = edx = 0;  // @94_59f1a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(7006920), (u32)(eax));  // @95_59f1a0
  ecx = edx = 0;  // @96_59f1a0
  ecx = (u32)(EBP - 272);  // @97_59f1a0
  eax = ext_4cbec0_thiscall1(ecx);  // @98_59f1a0
  ecx = edx = 0;  // @99_59f1a0
  L59f350:;
  SEH_LEAVE();  // @101_59f1a0
  ext_633654(G(u32, 0x6f5630));  // @102_59f1a0
  return eax;  // @103_59f1a0
}
PCREG(59f1a0, lifted_59f1a0);

extern "C" u32 THISCALL lifted_63cfe0(u32 ecx_in) {
  SEH_ENTER(0x66e848);  // @h_63cfe0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_63cfe0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 536), sizeof v); (u32)v; }) != (u32)(0)) goto L63d052;  // @1_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @2_63cfe0
  ecx = edx = 0;  // @3_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_63cfe0
  if ((eax & eax) == 0) goto L63d043;  // @5_63cfe0
  ecx = (u32)(esi + 568);  // @6_63cfe0
  { u32 v = (u32)((u32)(7087124)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @7_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @8_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @9_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @10_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @11_63cfe0
  goto L63d045;  // @12_63cfe0
  L63d043:;
  eax = 0;  // @14_63cfe0
  L63d045:;
  reg.state = (s32)((u32)(4294967295));  // @16_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 536), &v, sizeof v); }  // @17_63cfe0
  L63d052:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 540), sizeof v); (u32)v; }) != (u32)(0)) goto L63d09e;  // @19_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @20_63cfe0
  ecx = edx = 0;  // @21_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_63cfe0
  if ((eax & eax) == 0) goto L63d08f;  // @23_63cfe0
  ecx = (u32)(esi + 568);  // @24_63cfe0
  { u32 v = (u32)((u32)(7087184)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @25_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @26_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @27_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @28_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @29_63cfe0
  goto L63d091;  // @30_63cfe0
  L63d08f:;
  eax = 0;  // @32_63cfe0
  L63d091:;
  reg.state = (s32)((u32)(4294967295));  // @34_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 540), &v, sizeof v); }  // @35_63cfe0
  L63d09e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; }) != (u32)(0)) goto L63d0ea;  // @37_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @38_63cfe0
  ecx = edx = 0;  // @39_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @40_63cfe0
  if ((eax & eax) == 0) goto L63d0db;  // @41_63cfe0
  ecx = (u32)(esi + 568);  // @42_63cfe0
  { u32 v = (u32)((u32)(7087244)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @43_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @44_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @45_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @46_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @47_63cfe0
  goto L63d0dd;  // @48_63cfe0
  L63d0db:;
  eax = 0;  // @50_63cfe0
  L63d0dd:;
  reg.state = (s32)((u32)(4294967295));  // @52_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 544), &v, sizeof v); }  // @53_63cfe0
  L63d0ea:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 548), sizeof v); (u32)v; }) != (u32)(0)) goto L63d136;  // @55_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @56_63cfe0
  ecx = edx = 0;  // @57_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @58_63cfe0
  if ((eax & eax) == 0) goto L63d127;  // @59_63cfe0
  ecx = (u32)(esi + 568);  // @60_63cfe0
  { u32 v = (u32)((u32)(7087304)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @61_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @62_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @63_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @64_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @65_63cfe0
  goto L63d129;  // @66_63cfe0
  L63d127:;
  eax = 0;  // @68_63cfe0
  L63d129:;
  reg.state = (s32)((u32)(4294967295));  // @70_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 548), &v, sizeof v); }  // @71_63cfe0
  L63d136:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 552), sizeof v); (u32)v; }) != (u32)(0)) goto L63d182;  // @73_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @74_63cfe0
  ecx = edx = 0;  // @75_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @76_63cfe0
  if ((eax & eax) == 0) goto L63d173;  // @77_63cfe0
  ecx = (u32)(esi + 568);  // @78_63cfe0
  { u32 v = (u32)((u32)(7087364)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @79_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @80_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @81_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @82_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @83_63cfe0
  goto L63d175;  // @84_63cfe0
  L63d173:;
  eax = 0;  // @86_63cfe0
  L63d175:;
  reg.state = (s32)((u32)(4294967295));  // @88_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 552), &v, sizeof v); }  // @89_63cfe0
  L63d182:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 556), sizeof v); (u32)v; }) != (u32)(0)) goto L63d1ce;  // @91_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @92_63cfe0
  ecx = edx = 0;  // @93_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @94_63cfe0
  if ((eax & eax) == 0) goto L63d1bf;  // @95_63cfe0
  ecx = (u32)(esi + 568);  // @96_63cfe0
  { u32 v = (u32)((u32)(7087424)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @97_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @98_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @99_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @100_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @101_63cfe0
  goto L63d1c1;  // @102_63cfe0
  L63d1bf:;
  eax = 0;  // @104_63cfe0
  L63d1c1:;
  reg.state = (s32)((u32)(4294967295));  // @106_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 556), &v, sizeof v); }  // @107_63cfe0
  L63d1ce:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 560), sizeof v); (u32)v; }) != (u32)(0)) goto L63d21a;  // @109_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @110_63cfe0
  ecx = edx = 0;  // @111_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @112_63cfe0
  if ((eax & eax) == 0) goto L63d20b;  // @113_63cfe0
  ecx = (u32)(esi + 568);  // @114_63cfe0
  { u32 v = (u32)((u32)(7087484)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @115_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @116_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @117_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @118_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @119_63cfe0
  goto L63d20d;  // @120_63cfe0
  L63d20b:;
  eax = 0;  // @122_63cfe0
  L63d20d:;
  reg.state = (s32)((u32)(4294967295));  // @124_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 560), &v, sizeof v); }  // @125_63cfe0
  L63d21a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; }) != (u32)(0)) goto L63d25f;  // @127_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @128_63cfe0
  ecx = edx = 0;  // @129_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @130_63cfe0
  if ((eax & eax) == 0) goto L63d257;  // @131_63cfe0
  ecx = (u32)(esi + 568);  // @132_63cfe0
  { u32 v = (u32)((u32)(7087544)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @133_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @134_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @135_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @136_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @137_63cfe0
  goto L63d259;  // @138_63cfe0
  L63d257:;
  eax = 0;  // @140_63cfe0
  L63d259:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 564), &v, sizeof v); }  // @142_63cfe0
  L63d25f:;
  SEH_LEAVE();  // @144_63cfe0
  return eax;  // @145_63cfe0
}
PCREG(63cfe0, lifted_63cfe0);

extern "C" u32 THISCALL lifted_45cc40(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6666bc);  // @h_45cc40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_45cc40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_45cc40
  ecx = (u32)(EBP - 144);  // @2_45cc40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @3_45cc40
  eax = ext_4cbeb0_thiscall1(ecx);  // @4_45cc40
  ecx = edx = 0;  // @5_45cc40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_45cc40
  ecx = (u32)(EBP - 144);  // @7_45cc40
  ecx = esi;  // @8_45cc40
  reg.state = (s32)((u32)(0));  // @9_45cc40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 468)))(ecx, (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @10_45cc40
  ecx = edx = 0;  // @11_45cc40
  ecx = (u32)(EBP - 144);  // @12_45cc40
  eax = ext_4cc1d0_thiscall1(ecx);  // @13_45cc40
  ecx = edx = 0;  // @14_45cc40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @15_45cc40
  eax = ((u32(STDCALL *)(u32, u32))(ebx))((u32)(eax), (u32)(47));  // @16_45cc40
  ecx = edx = 0;  // @17_45cc40
  esi = eax;  // @18_45cc40
  if ((esi & esi) == 0) goto L45cd52;  // @19_45cc40
  ecx = (u32)(EBP - 144);  // @20_45cc40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @21_45cc40
  eax = ext_4cc1d0_thiscall1(ecx);  // @22_45cc40
  ecx = edx = 0;  // @23_45cc40
  eax = ((u32( *)(u32, u32))(ebx))((u32)(eax), (u32)(92));  // @24_45cc40
  ecx = edx = 0;  // @25_45cc40
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_45cc40
  ecx = (u32)(EBP - 400);  // @27_45cc40
  ebx = eax;  // @28_45cc40
  eax = ext_4cbeb0_thiscall1(ecx);  // @29_45cc40
  ecx = edx = 0;  // @30_45cc40
  reg.state = (s32)((u32)(1));  // @31_45cc40
  ecx = (u32)(EBP - 272);  // @32_45cc40
  if ((ebx & ebx) == 0) goto L45cd09;  // @33_45cc40
  eax = (u32)(ebx + 1);  // @34_45cc40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @35_45cc40
  ecx = edx = 0;  // @36_45cc40
  reg.state = (s32)((u32)(2));  // @37_45cc40
  goto L45cd16;  // @38_45cc40
  L45cd09:;
  eax = (u32)(esi + 1);  // @40_45cc40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @41_45cc40
  ecx = edx = 0;  // @42_45cc40
  reg.state = (s32)((u32)(3));  // @43_45cc40
  L45cd16:;
  eax = (u32)(EBP - 272);  // @45_45cc40
  ecx = (u32)(EBP - 400);  // @46_45cc40
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @47_45cc40
  ecx = edx = 0;  // @48_45cc40
  ecx = (u32)(EBP - 272);  // @49_45cc40
  reg.state = (s32)((u32)(1));  // @50_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @51_45cc40
  ecx = edx = 0;  // @52_45cc40
  eax = (u32)(EBP - 400);  // @53_45cc40
  ecx = edi;  // @54_45cc40
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @55_45cc40
  ecx = edx = 0;  // @56_45cc40
  ecx = (u32)(EBP - 400);  // @57_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @58_45cc40
  ecx = edx = 0;  // @59_45cc40
  goto L45cd60;  // @60_45cc40
  L45cd52:;
  eax = (u32)(EBP - 144);  // @62_45cc40
  ecx = edi;  // @63_45cc40
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @64_45cc40
  ecx = edx = 0;  // @65_45cc40
  L45cd60:;
  ecx = (u32)(EBP - 144);  // @67_45cc40
  eax = ext_4cbec0_thiscall1(ecx);  // @68_45cc40
  ecx = edx = 0;  // @69_45cc40
  eax = edi;  // @70_45cc40
  SEH_LEAVE();  // @71_45cc40
  ext_633654(G(u32, 0x6f5630));  // @72_45cc40
  return eax;  // @73_45cc40
}
PCREG(45cc40, lifted_45cc40);

extern "C" u32 THISCALL lifted_4f1890(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x669912);  // @h_4f1890
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_4f1890
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4f1890
  eax = ext_4ee210_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_4f1890
  ecx = edx = 0;  // @3_4f1890
  ecx = (u32)(ebx + 159);  // @4_4f1890
  reg.state = (s32)((u32)(0));  // @5_4f1890
  { u32 v = (u32)((u32)(6917104)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_4f1890
  eax = ext_4ccad0_thiscall3(ecx, (u32)(32), (u32)(4));  // @7_4f1890
  ecx = edx = 0;  // @8_4f1890
  ecx = (u32)(ebx + 203);  // @9_4f1890
  reg.state = (s32)((u32)(1));  // @10_4f1890
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(0));  // @11_4f1890
  ecx = edx = 0;  // @12_4f1890
  ecx = (u32)(ebx + 243);  // @13_4f1890
  reg.state = (s32)((u32)(2));  // @14_4f1890
  eax = ext_4ccba0_thiscall1(ecx);  // @15_4f1890
  ecx = edx = 0;  // @16_4f1890
  ecx = (u32)(ebx + 423);  // @17_4f1890
  reg.state = (s32)((u32)(3));  // @18_4f1890
  eax = ext_4ccad0_thiscall3(ecx, (u32)(4), (u32)(0));  // @19_4f1890
  ecx = edx = 0;  // @20_4f1890
  reg.state = (s32)((u32)(4));  // @21_4f1890
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1595), &v, sizeof v); }  // @22_4f1890
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 1529), &v, sizeof v); }  // @23_4f1890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 475), &v, sizeof v); }  // @24_4f1890
  { u16 v = (u16)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 1533), &v, sizeof v); }  // @25_4f1890
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 1535), &v, sizeof v); }  // @26_4f1890
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ebx + 155), &v, sizeof v); }  // @27_4f1890
  eax = ext_41e290_cdecl1((u32)(264));  // @28_4f1890
  ecx = edx = 0;  // @29_4f1890
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @30_4f1890
  reg.state = (s32)((u32)(5));  // @31_4f1890
  if ((eax & eax) == 0) goto L4f1987;  // @32_4f1890
  ecx = (u32)(ebx + 471);  // @33_4f1890
  ecx = eax;  // @34_4f1890
  eax = ext_4d8330_thiscall4(ecx, (u32)(6917996), (u32)(6917956), (u32)(ecx));  // @35_4f1890
  ecx = edx = 0;  // @36_4f1890
  edx = eax;  // @37_4f1890
  goto L4f1989;  // @38_4f1890
  L4f1987:;
  edx = 0;  // @40_4f1890
  L4f1989:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 96), &v, sizeof v); }  // @42_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4f1890
  reg.state = (s32)((u32)(4));  // @44_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4f1890
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @46_4f1890
  ecx = edx = 0;  // @47_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @49_4f1890
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4f1890
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @51_4f1890
  ecx = edx = 0;  // @52_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_4f1890
  esi = eax;  // @54_4f1890
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @55_4f1890
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @56_4f1890
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4f1890
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(ebx), (u32)(16));  // @58_4f1890
  ecx = edx = 0;  // @59_4f1890
  ecx = esi;  // @60_4f1890
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6918004), (u32)(eax));  // @61_4f1890
  ecx = edx = 0;  // @62_4f1890
  { u8 v = (u8)((u32)(254)); __builtin_memcpy((void *)(u32)(ebx + 104), &v, sizeof v); }  // @63_4f1890
  eax = ebx;  // @64_4f1890
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 106), &v, sizeof v); }  // @65_4f1890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1591), &v, sizeof v); }  // @66_4f1890
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 107), &v, sizeof v); }  // @67_4f1890
  SEH_LEAVE();  // @68_4f1890
  return eax;  // @69_4f1890
}
PCREG(4f1890, lifted_4f1890);

extern "C" u32 THISCALL lifted_598eb0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66bbbf);  // @h_598eb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_598eb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_598eb0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 7435), &v, sizeof v); }  // @2_598eb0
  if ((esi & esi) == 0) goto L599021;  // @3_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1654), sizeof v); (u32)v; }));  // @7_598eb0
  ecx = edx = 0;  // @8_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7431), &v, sizeof v); }  // @9_598eb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2138), sizeof v); (u32)v; }) != (u32)(0)) goto L598f22;  // @10_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_598eb0
  ecx = esi;  // @12_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6975112));  // @13_598eb0
  ecx = edx = 0;  // @14_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2138), &v, sizeof v); }  // @15_598eb0
  L598f22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2138), sizeof v); (u32)v; });  // @17_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7427), &v, sizeof v); }  // @18_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7435), sizeof v); (u32)v; });  // @19_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1668), sizeof v); (u32)v; });  // @20_598eb0
  eax = (eax - (u32)(2));  // @21_598eb0
  if (eax == 0) goto L598faa;  // @22_598eb0
  eax = (eax - (u32)(1));  // @23_598eb0
  if (eax == 0) goto L598f8c;  // @24_598eb0
  eax = (eax - (u32)(1));  // @25_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @27_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_598eb0
  if (eax == 0) goto L598f7b;  // @29_598eb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @30_598eb0
  ecx = edx = 0;  // @31_598eb0
  ecx = (u32)(EBP + 8);  // @32_598eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @33_598eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_598eb0
  ecx = eax;  // @35_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973184), (u32)(ecx));  // @36_598eb0
  ecx = edx = 0;  // @37_598eb0
  goto L598fda;  // @38_598eb0
  L598f7b:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 312)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @40_598eb0
  ecx = edx = 0;  // @41_598eb0
  ecx = (u32)(EBP - 16);  // @42_598eb0
  goto L598fc6;  // @43_598eb0
  L598f8c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, (u32)(6973232), (u32)(ecx));  // @48_598eb0
  ecx = edx = 0;  // @49_598eb0
  ecx = (u32)(EBP - 16);  // @50_598eb0
  goto L598fc6;  // @51_598eb0
  L598faa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @54_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 312)))(ecx, (u32)(6973216), (u32)(ecx));  // @56_598eb0
  ecx = edx = 0;  // @57_598eb0
  ecx = (u32)(EBP - 16);  // @58_598eb0
  L598fc6:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_598eb0
  ecx = eax;  // @61_598eb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @62_598eb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973200), (u32)(ecx));  // @63_598eb0
  ecx = edx = 0;  // @64_598eb0
  L598fda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_598eb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_598eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_598eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @69_598eb0
  ecx = edx = 0;  // @70_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 7439), &v, sizeof v); }  // @71_598eb0
  eax = ext_41e290_cdecl1((u32)(76));  // @72_598eb0
  ecx = edx = 0;  // @73_598eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @74_598eb0
  reg.state = (s32)((u32)(0));  // @75_598eb0
  if ((eax & eax) == 0) goto L599019;  // @76_598eb0
  ecx = eax;  // @77_598eb0
  eax = ext_5eaab0_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7439), sizeof v); (u32)v; }), (u32)(16));  // @78_598eb0
  ecx = edx = 0;  // @79_598eb0
  goto L59901b;  // @80_598eb0
  L599019:;
  eax = 0;  // @82_598eb0
  L59901b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8919), &v, sizeof v); }  // @84_598eb0
  L599021:;
  SEH_LEAVE();  // @86_598eb0
  return eax;  // @87_598eb0
}
PCREG(598eb0, lifted_598eb0);

extern "C" u32 THISCALL lifted_5c5f30(u32 ecx_in) {
  SEH_ENTER(0x66c6b6);  // @h_5c5f30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @1_5c5f30
  { u32 v = (u32)((u32)(7029940)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f6c;  // @3_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_5c5f30
  ecx = edx = 0;  // @6_5c5f30
  L5c5f6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @8_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f79;  // @9_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_5c5f30
  ecx = edx = 0;  // @12_5c5f30
  L5c5f79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @14_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f86;  // @15_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_5c5f30
  ecx = edx = 0;  // @18_5c5f30
  L5c5f86:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @20_5c5f30
  if ((ecx & ecx) == 0) goto L5c5f93;  // @21_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @23_5c5f30
  ecx = edx = 0;  // @24_5c5f30
  L5c5f93:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @26_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fff;  // @27_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5c5f30
  edx = (u32)(EBP - 24);  // @29_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @30_5c5f30
  ecx = edx = 0;  // @31_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @32_5c5f30
  edx = (u32)(EBP - 24);  // @33_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @35_5c5f30
  ecx = edx = 0;  // @36_5c5f30
  esi = eax;  // @37_5c5f30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L5c5fff;  // @38_5c5f30
  L5c5fb7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @40_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fc4;  // @41_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @43_5c5f30
  ecx = edx = 0;  // @44_5c5f30
  L5c5fc4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @46_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fd1;  // @47_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @49_5c5f30
  ecx = edx = 0;  // @50_5c5f30
  L5c5fd1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @52_5c5f30
  if ((ecx & ecx) == 0) goto L5c5fde;  // @53_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @55_5c5f30
  ecx = edx = 0;  // @56_5c5f30
  L5c5fde:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @58_5c5f30
  if ((ecx & ecx) == 0) goto L5c5feb;  // @59_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @61_5c5f30
  ecx = edx = 0;  // @62_5c5f30
  L5c5feb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @64_5c5f30
  edx = (u32)(EBP - 24);  // @65_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @67_5c5f30
  ecx = edx = 0;  // @68_5c5f30
  esi = eax;  // @69_5c5f30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L5c5fb7;  // @70_5c5f30
  L5c5fff:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @72_5c5f30
  if ((ecx & ecx) == 0) goto L5c600c;  // @73_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @75_5c5f30
  ecx = edx = 0;  // @76_5c5f30
  L5c600c:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @78_5c5f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @79_5c5f30
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @80_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_5c5f30
  reg.state = (s32)((u32)(0));  // @82_5c5f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @83_5c5f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_5c5f30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(edi));  // @85_5c5f30
  ecx = edx = 0;  // @86_5c5f30
  SEH_LEAVE();  // @87_5c5f30
  return eax;  // @88_5c5f30
}
PCREG(5c5f30, lifted_5c5f30);

extern "C" u32 THISCALL lifted_4b8bf0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66bdd6);  // @h_4b8bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4b8bf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4b8bf0
  ecx = edi;  // @2_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @4_4b8bf0
  ecx = edx = 0;  // @5_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @6_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @8_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @10_4b8bf0
  ecx = edx = 0;  // @11_4b8bf0
  if ((eax & eax) != 0) goto L4b8c93;  // @12_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @13_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6891852), (u32)(20));  // @15_4b8bf0
  ecx = edx = 0;  // @16_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @17_4b8bf0
  edi = eax;  // @18_4b8bf0
  eax = (u32)(EBP - 144);  // @19_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @21_4b8bf0
  ecx = edx = 0;  // @22_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_4b8bf0
  ecx = eax;  // @24_4b8bf0
  reg.state = (s32)((u32)(0));  // @25_4b8bf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @26_4b8bf0
  ecx = edx = 0;  // @27_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(edi), (u32)(6891904), (u32)(eax));  // @28_4b8bf0
  ecx = edx = 0;  // @29_4b8bf0
  ecx = (u32)(EBP - 144);  // @30_4b8bf0
  goto L4b8d68;  // @31_4b8bf0
  L4b8c93:;
  ecx = edi;  // @33_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @34_4b8bf0
  ecx = edx = 0;  // @35_4b8bf0
  ecx = edi;  // @36_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 80), &v, sizeof v); }  // @37_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @38_4b8bf0
  ecx = edx = 0;  // @39_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 84), &v, sizeof v); }  // @40_4b8bf0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 88), &v, sizeof v); }  // @41_4b8bf0
  if ((esi & esi) == 0) goto L4b8d7e;  // @42_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_4b8bf0
  ecx = esi;  // @44_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @45_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097158));  // @46_4b8bf0
  ecx = edx = 0;  // @47_4b8bf0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4b8d20;  // @48_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_4b8bf0
  ecx = ebx;  // @50_4b8bf0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 89), &v, sizeof v); }  // @51_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(16));  // @52_4b8bf0
  ecx = edx = 0;  // @53_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @55_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892012), (u32)(0), (u32)(6891852), (u32)(36));  // @57_4b8bf0
  ecx = edx = 0;  // @58_4b8bf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @59_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @61_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892028), (u32)(0), (u32)(6891852), (u32)(37));  // @63_4b8bf0
  ecx = edx = 0;  // @64_4b8bf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 74), &v, sizeof v); }  // @65_4b8bf0
  goto L4b8d7e;  // @66_4b8bf0
  L4b8d20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @68_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6891852), (u32)(32));  // @70_4b8bf0
  ecx = edx = 0;  // @71_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @72_4b8bf0
  edi = eax;  // @73_4b8bf0
  eax = (u32)(EBP - 272);  // @74_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @76_4b8bf0
  ecx = edx = 0;  // @77_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_4b8bf0
  ecx = eax;  // @79_4b8bf0
  reg.state = (s32)((u32)(1));  // @80_4b8bf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @81_4b8bf0
  ecx = edx = 0;  // @82_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(edi), (u32)(6891960), (u32)(eax));  // @83_4b8bf0
  ecx = edx = 0;  // @84_4b8bf0
  ecx = (u32)(EBP - 272);  // @85_4b8bf0
  L4b8d68:;
  reg.state = (s32)((u32)(4294967295));  // @87_4b8bf0
  eax = ext_4cbec0_thiscall1(ecx);  // @88_4b8bf0
  ecx = edx = 0;  // @89_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_4b8bf0
  ecx = ebx;  // @91_4b8bf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @92_4b8bf0
  ecx = edx = 0;  // @93_4b8bf0
  L4b8d7e:;
  SEH_LEAVE();  // @95_4b8bf0
  ext_633654(G(u32, 0x6f5630));  // @96_4b8bf0
  return eax;  // @97_4b8bf0
}
PCREG(4b8bf0, lifted_4b8bf0);

extern "C" u32 THISCALL lifted_48a880(u32 ecx_in) {
  SEH_ENTER(0x667760);  // @h_48a880
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_48a880
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2788), sizeof v); (u32)v; });  // @1_48a880
  { u32 v = (u32)((u32)(6870332)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_48a880
  if ((edi & edi) == 0) goto L48a8cb;  // @3_48a880
  ecx = edi;  // @4_48a880
  eax = ext_49df00_thiscall1(ecx);  // @5_48a880
  ecx = edx = 0;  // @6_48a880
  eax = ext_634273_cdecl2((u32)(edi), (u32)(8));  // @7_48a880
  ecx = edx = 0;  // @8_48a880
  L48a8cb:;
  ecx = esi;  // @10_48a880
  eax = ext_48fa70_thiscall1(ecx);  // @11_48a880
  ecx = edx = 0;  // @12_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2796), sizeof v); (u32)v; });  // @13_48a880
  if ((eax & eax) == 0) goto L48a8f1;  // @14_48a880
  eax = ext_634273_cdecl2((u32)(eax), (u32)(0));  // @15_48a880
  ecx = edx = 0;  // @16_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2796), &v, sizeof v); }  // @17_48a880
  L48a8f1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2780), sizeof v); (u32)v; });  // @19_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2792), &v, sizeof v); }  // @20_48a880
  if ((ecx & ecx) == 0) goto L48a919;  // @21_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @23_48a880
  ecx = edx = 0;  // @24_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2780), &v, sizeof v); }  // @25_48a880
  L48a919:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @27_48a880
  if ((edi & edi) == 0) goto L48a939;  // @28_48a880
  ecx = edi;  // @29_48a880
  eax = ext_4958e0_thiscall1(ecx);  // @30_48a880
  ecx = edx = 0;  // @31_48a880
  eax = ext_634273_cdecl2((u32)(edi), (u32)(105));  // @32_48a880
  ecx = edx = 0;  // @33_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @34_48a880
  L48a939:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 23861), sizeof v); (u32)v; });  // @36_48a880
  if ((edi & edi) == 0) goto L48a95f;  // @37_48a880
  ecx = edi;  // @38_48a880
  eax = ext_49b680_thiscall1(ecx);  // @39_48a880
  ecx = edx = 0;  // @40_48a880
  eax = ext_634273_cdecl2((u32)(edi), (u32)(65));  // @41_48a880
  ecx = edx = 0;  // @42_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 23861), &v, sizeof v); }  // @43_48a880
  L48a95f:;
  edi = (u32)(esi + 28);  // @45_48a880
  if ((edi & edi) == 0) goto L48a99f;  // @46_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_48a880
  ecx = (u32)(EBP - 24);  // @48_48a880
  ecx = edi;  // @49_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @50_48a880
  ecx = edx = 0;  // @51_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_48a880
  ecx = (u32)(EBP - 24);  // @53_48a880
  ecx = edi;  // @54_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(ecx));  // @55_48a880
  ecx = edx = 0;  // @56_48a880
  if ((eax & eax) == 0) goto L48a99f;  // @57_48a880
  L48a980:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @59_48a880
  if ((ecx & ecx) == 0) goto L48a990;  // @60_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @62_48a880
  ecx = edx = 0;  // @63_48a880
  L48a990:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_48a880
  ecx = (u32)(EBP - 24);  // @66_48a880
  ecx = edi;  // @67_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(ecx));  // @68_48a880
  ecx = edx = 0;  // @69_48a880
  if ((eax & eax) != 0) goto L48a980;  // @70_48a880
  L48a99f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7261), sizeof v); (u32)v; });  // @72_48a880
  if ((eax & eax) == 0) goto L48a9be;  // @73_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7261), &v, sizeof v); }  // @74_48a880
  eax = ext_634273_cdecl2((u32)(eax), (u32)(0));  // @75_48a880
  ecx = edx = 0;  // @76_48a880
  L48a9be:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @78_48a880
  if ((eax & eax) == 0) goto L48a9d0;  // @79_48a880
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @80_48a880
  ecx = edx = 0;  // @81_48a880
  L48a9d0:;
  ecx = esi;  // @83_48a880
  eax = ext_48fa10_thiscall1(ecx);  // @84_48a880
  ecx = edx = 0;  // @85_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2999), sizeof v); (u32)v; });  // @86_48a880
  if ((eax & eax) == 0) goto L48a9f6;  // @87_48a880
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @88_48a880
  ecx = edx = 0;  // @89_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2999), &v, sizeof v); }  // @90_48a880
  L48a9f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3003), sizeof v); (u32)v; });  // @92_48a880
  if ((eax & eax) == 0) goto L48aa15;  // @93_48a880
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @94_48a880
  ecx = edx = 0;  // @95_48a880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3003), &v, sizeof v); }  // @96_48a880
  L48aa15:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @98_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338648), sizeof v); (u32)v; }));  // @100_48a880
  ecx = edx = 0;  // @101_48a880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338648), sizeof v); (u32)v; });  // @102_48a880
  if ((ecx & ecx) == 0) goto L48aa39;  // @103_48a880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_48a880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @105_48a880
  ecx = edx = 0;  // @106_48a880
  L48aa39:;
  ecx = (u32)(esi + 7265);  // @108_48a880
  eax = ext_4d2330_thiscall1(ecx);  // @109_48a880
  ecx = edx = 0;  // @110_48a880
  ecx = (u32)(esi + 3021);  // @111_48a880
  eax = ext_4cbec0_thiscall1(ecx);  // @112_48a880
  ecx = edx = 0;  // @113_48a880
  ecx = (u32)(esi + 2816);  // @114_48a880
  eax = ext_4ccf60_thiscall1(ecx);  // @115_48a880
  ecx = edx = 0;  // @116_48a880
  ecx = edi;  // @117_48a880
  eax = ext_4cce40_thiscall1(ecx);  // @118_48a880
  ecx = edx = 0;  // @119_48a880
  SEH_LEAVE();  // @120_48a880
  return eax;  // @121_48a880
}
PCREG(48a880, lifted_48a880);

extern "C" u32 THISCALL lifted_4637f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666a2d);  // @h_4637f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4637f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4637f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4637f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @3_4637f0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(0)) goto L463838;  // @4_4637f0
  eax = 0;  // @5_4637f0
  goto L46390f;  // @6_4637f0
  L463838:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_4637f0
  esi = 0;  // @9_4637f0
  edx = (u32)(EBP - 144);  // @10_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 324)))(ecx, (u32)(edx), (u32)(edx));  // @12_4637f0
  ecx = edx = 0;  // @13_4637f0
  ecx = eax;  // @14_4637f0
  reg.state = (s32)(esi);  // @15_4637f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_4637f0
  ecx = edx = 0;  // @17_4637f0
  ecx = (u32)(EBP - 144);  // @18_4637f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @19_4637f0
  reg.state = (s32)((u32)(4294967295));  // @20_4637f0
  eax = ext_4cbec0_thiscall1(ecx);  // @21_4637f0
  ecx = edx = 0;  // @22_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_4637f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) == esi) goto L46390d;  // @25_4637f0
  eax = ext_41e290_cdecl1((u32)(44));  // @26_4637f0
  ecx = edx = 0;  // @27_4637f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @28_4637f0
  reg.state = (s32)((u32)(1));  // @29_4637f0
  if ((eax & eax) == 0) goto L4638ac;  // @30_4637f0
  ecx = eax;  // @31_4637f0
  eax = ext_4e5000_thiscall1(ecx);  // @32_4637f0
  ecx = edx = 0;  // @33_4637f0
  esi = eax;  // @34_4637f0
  goto L4638ae;  // @35_4637f0
  L4638ac:;
  esi = 0;  // @37_4637f0
  L4638ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @39_4637f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_4637f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @41_4637f0
  reg.state = (s32)((u32)(4294967295));  // @42_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @43_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @46_4637f0
  ecx = esi;  // @47_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(edi), (u32)(ebx), (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }));  // @48_4637f0
  ecx = edx = 0;  // @49_4637f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L46390d;  // @50_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @51_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6838324), (u32)(453));  // @53_4637f0
  ecx = edx = 0;  // @54_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @55_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6838400), (u32)(ebx));  // @56_4637f0
  ecx = edx = 0;  // @57_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_4637f0
  ecx = esi;  // @59_4637f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @60_4637f0
  ecx = edx = 0;  // @61_4637f0
  esi = 0;  // @62_4637f0
  L46390d:;
  eax = esi;  // @64_4637f0
  L46390f:;
  SEH_LEAVE();  // @66_4637f0
  ext_633654(G(u32, 0x6f5630));  // @67_4637f0
  return eax;  // @68_4637f0
}
PCREG(4637f0, lifted_4637f0);

extern "C" u32 THISCALL lifted_607b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e0b2);  // @h_607b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_607b50
  eax = ext_41e290_cdecl1((u32)(5366));  // @1_607b50
  ecx = edx = 0;  // @2_607b50
  ecx = eax;  // @3_607b50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_607b50
  reg.state = (s32)((u32)(0));  // @5_607b50
  if ((ecx & ecx) == 0) goto L607bae;  // @6_607b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_607b50
  eax = ext_607f60_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2511), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }));  // @8_607b50
  ecx = edx = 0;  // @9_607b50
  esi = eax;  // @10_607b50
  goto L607bb0;  // @11_607b50
  L607bae:;
  esi = 0;  // @13_607b50
  L607bb0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_607b50
  ecx = esi;  // @16_607b50
  reg.state = (s32)((u32)(4294967295));  // @17_607b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 648)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @18_607b50
  ecx = edx = 0;  // @19_607b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_607b50
  ecx = esi;  // @21_607b50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 656)))(ecx);  // @22_607b50
  ecx = edx = 0;  // @23_607b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @24_607b50
  eax = 0;  // @25_607b50
  SEH_LEAVE();  // @26_607b50
  return eax;  // @27_607b50
}
PCREG(607b50, lifted_607b50);

extern "C" u32 STDCALL lifted_5f3050(u32 a0, u32 a1) {
  SEH_ENTER(0x66d04f);  // @h_5f3050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  eax = ext_41e290_cdecl1((u32)(18));  // @0_5f3050
  ecx = edx = 0;  // @1_5f3050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_5f3050
  reg.state = (s32)((u32)(0));  // @3_5f3050
  if ((eax & eax) == 0) goto L5f3097;  // @4_5f3050
  ecx = eax;  // @5_5f3050
  eax = ext_604650_thiscall1(ecx);  // @6_5f3050
  ecx = edx = 0;  // @7_5f3050
  esi = eax;  // @8_5f3050
  goto L5f3099;  // @9_5f3050
  L5f3097:;
  esi = 0;  // @11_5f3050
  L5f3099:;
  reg.state = (s32)((u32)(4294967295));  // @13_5f3050
  if ((esi & esi) == 0) goto L5f30b3;  // @14_5f3050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @15_5f3050
  if ((ecx & ecx) == 0) goto L5f30b3;  // @16_5f3050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_5f3050
  ecx = esi;  // @18_5f3050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(ecx));  // @19_5f3050
  ecx = edx = 0;  // @20_5f3050
  L5f30b3:;
  eax = esi;  // @22_5f3050
  SEH_LEAVE();  // @23_5f3050
  return eax;  // @24_5f3050
}
PCREG(5f3050, lifted_5f3050);

extern "C" u32 THISCALL lifted_578560(u32 ecx_in) {
  SEH_ENTER(0x66b15e);  // @h_578560
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_578560
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_578560
  eax = ext_561020_thiscall1(ecx);  // @2_578560
  ecx = edx = 0;  // @3_578560
  { u32 v = (u32)((u32)(6986028)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_578560
  reg.state = (s32)((u32)(0));  // @7_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_578560
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6986320), (u32)(0), (u32)(6986276), (u32)(18));  // @9_578560
  ecx = edx = 0;  // @10_578560
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 408), &v, sizeof v); }  // @11_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_578560
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6986340), (u32)(0), (u32)(6986276), (u32)(19));  // @15_578560
  ecx = edx = 0;  // @16_578560
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 410), &v, sizeof v); }  // @17_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @18_578560
  ecx = edx = 0;  // @19_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @20_578560
  reg.state = (s32)((u32)(1));  // @21_578560
  if ((eax & eax) == 0) goto L578621;  // @22_578560
  ecx = (u32)(esi + 424);  // @23_578560
  ecx = eax;  // @24_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986364), (u32)(6975376), (u32)(ecx));  // @25_578560
  ecx = edx = 0;  // @26_578560
  edx = eax;  // @27_578560
  goto L578623;  // @28_578560
  L578621:;
  edx = 0;  // @30_578560
  L578623:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 412), &v, sizeof v); }  // @32_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_578560
  reg.state = (s32)((u32)(0));  // @34_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @36_578560
  ecx = edx = 0;  // @37_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @38_578560
  ecx = edx = 0;  // @39_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @40_578560
  reg.state = (s32)((u32)(2));  // @41_578560
  if ((eax & eax) == 0) goto L578670;  // @42_578560
  ecx = (u32)(esi + 428);  // @43_578560
  ecx = eax;  // @44_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986372), (u32)(6975376), (u32)(ecx));  // @45_578560
  ecx = edx = 0;  // @46_578560
  edx = eax;  // @47_578560
  goto L578672;  // @48_578560
  L578670:;
  edx = 0;  // @50_578560
  L578672:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 416), &v, sizeof v); }  // @52_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_578560
  reg.state = (s32)((u32)(0));  // @54_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @56_578560
  ecx = edx = 0;  // @57_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @58_578560
  ecx = edx = 0;  // @59_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @60_578560
  reg.state = (s32)((u32)(3));  // @61_578560
  if ((eax & eax) == 0) goto L5786bf;  // @62_578560
  ecx = (u32)(esi + 432);  // @63_578560
  ecx = eax;  // @64_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986380), (u32)(6975376), (u32)(ecx));  // @65_578560
  ecx = edx = 0;  // @66_578560
  edx = eax;  // @67_578560
  goto L5786c1;  // @68_578560
  L5786bf:;
  edx = 0;  // @70_578560
  L5786c1:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 420), &v, sizeof v); }  // @72_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_578560
  reg.state = (s32)((u32)(0));  // @74_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @76_578560
  ecx = edx = 0;  // @77_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 424), &v, sizeof v); }  // @78_578560
  eax = esi;  // @79_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 428), &v, sizeof v); }  // @80_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 432), &v, sizeof v); }  // @81_578560
  SEH_LEAVE();  // @82_578560
  return eax;  // @83_578560
}
PCREG(578560, lifted_578560);

extern "C" u32 THISCALL lifted_44a3d0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66612e);  // @h_44a3d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_44a3d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_44a3d0
  eax = ext_45f3c0_thiscall2(ecx, (u32)(esi));  // @2_44a3d0
  ecx = edx = 0;  // @3_44a3d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L44a419;  // @4_44a3d0
  SEH_LEAVE();  // @5_44a3d0
  return eax;  // @6_44a3d0
  L44a419:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @8_44a3d0
  if ((ecx & ecx) == 0) goto L44a42d;  // @9_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_44a3d0
  ecx = edx = 0;  // @12_44a3d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @13_44a3d0
  L44a42d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @15_44a3d0
  if ((ecx & ecx) == 0) goto L44a441;  // @16_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @18_44a3d0
  ecx = edx = 0;  // @19_44a3d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @20_44a3d0
  L44a441:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_44a3d0
  ecx = (u32)(EBP + 8);  // @23_44a3d0
  ecx = esi;  // @24_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(ecx));  // @25_44a3d0
  ecx = edx = 0;  // @26_44a3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L44a4ab;  // @27_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_44a3d0
  ecx = (u32)(EBP - 20);  // @29_44a3d0
  ecx = esi;  // @30_44a3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @31_44a3d0
  ecx = edx = 0;  // @32_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_44a3d0
  ecx = (u32)(EBP - 16);  // @34_44a3d0
  ecx = esi;  // @35_44a3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @36_44a3d0
  ecx = edx = 0;  // @37_44a3d0
  eax = ext_41e290_cdecl1((u32)(28));  // @38_44a3d0
  ecx = edx = 0;  // @39_44a3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @40_44a3d0
  reg.state = (s32)((u32)(0));  // @41_44a3d0
  if ((eax & eax) == 0) goto L44a497;  // @42_44a3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @43_44a3d0
  ecx = (ecx - 1);  // @44_44a3d0
  ecx = eax;  // @45_44a3d0
  eax = ext_4ccbe0_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }), (u32)(ecx));  // @46_44a3d0
  ecx = edx = 0;  // @47_44a3d0
  ecx = eax;  // @48_44a3d0
  goto L44a499;  // @49_44a3d0
  L44a497:;
  ecx = 0;  // @51_44a3d0
  L44a499:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @53_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_44a3d0
  ecx = esi;  // @55_44a3d0
  reg.state = (s32)((u32)(4294967295));  // @56_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(ecx));  // @57_44a3d0
  ecx = edx = 0;  // @58_44a3d0
  L44a4ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_44a3d0
  ecx = (u32)(EBP + 8);  // @61_44a3d0
  ecx = esi;  // @62_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(ecx));  // @63_44a3d0
  ecx = edx = 0;  // @64_44a3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L44a4f7;  // @65_44a3d0
  eax = ext_41e290_cdecl1((u32)(28));  // @66_44a3d0
  ecx = edx = 0;  // @67_44a3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @68_44a3d0
  reg.state = (s32)((u32)(1));  // @69_44a3d0
  if ((eax & eax) == 0) goto L44a4e3;  // @70_44a3d0
  ecx = eax;  // @71_44a3d0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(1));  // @72_44a3d0
  ecx = edx = 0;  // @73_44a3d0
  ecx = eax;  // @74_44a3d0
  goto L44a4e5;  // @75_44a3d0
  L44a4e3:;
  ecx = 0;  // @77_44a3d0
  L44a4e5:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @79_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_44a3d0
  ecx = esi;  // @81_44a3d0
  reg.state = (s32)((u32)(4294967295));  // @82_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(ecx));  // @83_44a3d0
  ecx = edx = 0;  // @84_44a3d0
  L44a4f7:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @86_44a3d0
  SEH_LEAVE();  // @87_44a3d0
  return eax;  // @88_44a3d0
}
PCREG(44a3d0, lifted_44a3d0);

extern "C" u32 THISCALL lifted_45d5c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66676f);  // @h_45d5c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_45d5c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @2_45d5c0
  ecx = edx = 0;  // @3_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @4_45d5c0
  if ((eax & eax) == 0) goto L45d600;  // @5_45d5c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @6_45d5c0
  L45d600:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @9_45d5c0
  eax = ext_4da3a0_thiscall1(ecx);  // @10_45d5c0
  ecx = edx = 0;  // @11_45d5c0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L45d700;  // @12_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_45d5c0
  ecx = ebx;  // @14_45d5c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @15_45d5c0
  ecx = edx = 0;  // @16_45d5c0
  eax = ext_41e290_cdecl1((u32)(28));  // @17_45d5c0
  ecx = edx = 0;  // @18_45d5c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @19_45d5c0
  reg.state = (s32)((u32)(0));  // @20_45d5c0
  if ((eax & eax) == 0) goto L45d641;  // @21_45d5c0
  ecx = eax;  // @22_45d5c0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @23_45d5c0
  ecx = edx = 0;  // @24_45d5c0
  ecx = eax;  // @25_45d5c0
  goto L45d643;  // @26_45d5c0
  L45d641:;
  ecx = 0;  // @28_45d5c0
  L45d643:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @30_45d5c0
  reg.state = (s32)((u32)(4294967295));  // @31_45d5c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @32_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @33_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @34_45d5c0
  if ((ecx & ecx) == 0) goto L45d700;  // @35_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_45d5c0
  edx = (u32)(EBP - 28);  // @37_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @38_45d5c0
  ecx = edx = 0;  // @39_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @40_45d5c0
  edx = (u32)(EBP - 28);  // @41_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @42_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @44_45d5c0
  ecx = edx = 0;  // @45_45d5c0
  edx = eax;  // @46_45d5c0
  if ((edx & edx) == 0) goto L45d700;  // @47_45d5c0
  L45d680:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @49_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @51_45d5c0
  ecx = edx = 0;  // @52_45d5c0
  esi = eax;  // @53_45d5c0
  if ((esi & esi) != 0) goto L45d6a7;  // @54_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @55_45d5c0
  edx = (u32)(EBP - 28);  // @56_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @57_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(edx));  // @59_45d5c0
  ecx = edx = 0;  // @60_45d5c0
  goto L45d6eb;  // @61_45d5c0
  L45d6a7:;
  ecx = ebx;  // @63_45d5c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L45d6bf;  // @64_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @65_45d5c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 272)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }));  // @66_45d5c0
  ecx = edx = 0;  // @67_45d5c0
  goto L45d6eb;  // @68_45d5c0
  L45d6bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @70_45d5c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @71_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 264)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }));  // @72_45d5c0
  ecx = edx = 0;  // @73_45d5c0
  edi = eax;  // @74_45d5c0
  ecx = edi;  // @75_45d5c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @76_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(esi));  // @77_45d5c0
  ecx = edx = 0;  // @78_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @79_45d5c0
  ecx = (ecx | ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @80_45d5c0
  ecx = (ecx & (u32)(4294967283));  // @81_45d5c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @82_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @83_45d5c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @84_45d5c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @85_45d5c0
  L45d6eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @87_45d5c0
  edx = (u32)(EBP - 28);  // @88_45d5c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @89_45d5c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_45d5c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @91_45d5c0
  ecx = edx = 0;  // @92_45d5c0
  edx = eax;  // @93_45d5c0
  if ((edx & edx) != 0) goto L45d680;  // @94_45d5c0
  L45d700:;
  SEH_LEAVE();  // @96_45d5c0
  return eax;  // @97_45d5c0
}
PCREG(45d5c0, lifted_45d5c0);

extern "C" u32 THISCALL lifted_4c6410(u32 ecx_in) {
  SEH_ENTER(0x668f90);  // @h_4c6410
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4c6410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c6410
  eax = ext_469870_thiscall1(ecx);  // @2_4c6410
  ecx = edx = 0;  // @3_4c6410
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4c6410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4c6410
  ebx = (u32)(esi + 88);  // @6_4c6410
  reg.state = (s32)((u32)(0));  // @7_4c6410
  edi = (u32)(esi + 93);  // @8_4c6410
  { u32 v = (u32)((u32)(6900120)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_4c6410
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @10_4c6410
  { u32 v = (u32)((u32)(1148846080)); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @11_4c6410
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @12_4c6410
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @13_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @14_4c6410
  ecx = edx = 0;  // @15_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @16_4c6410
  reg.state = (s32)((u32)(1));  // @17_4c6410
  if ((eax & eax) == 0) goto L4c649f;  // @18_4c6410
  ecx = eax;  // @19_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900288), (u32)(6900252), (u32)(edi));  // @20_4c6410
  ecx = edx = 0;  // @21_4c6410
  edx = eax;  // @22_4c6410
  goto L4c64a1;  // @23_4c6410
  L4c649f:;
  edx = 0;  // @25_4c6410
  L4c64a1:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @27_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4c6410
  reg.state = (s32)((u32)(0));  // @29_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @31_4c6410
  ecx = edx = 0;  // @32_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @33_4c6410
  ecx = edx = 0;  // @34_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @35_4c6410
  reg.state = (s32)((u32)(2));  // @36_4c6410
  if ((eax & eax) == 0) goto L4c64e5;  // @37_4c6410
  ecx = eax;  // @38_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900344), (u32)(6900312), (u32)(edi));  // @39_4c6410
  ecx = edx = 0;  // @40_4c6410
  edx = eax;  // @41_4c6410
  goto L4c64e7;  // @42_4c6410
  L4c64e5:;
  edx = 0;  // @44_4c6410
  L4c64e7:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @46_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_4c6410
  reg.state = (s32)((u32)(0));  // @48_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @50_4c6410
  ecx = edx = 0;  // @51_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @52_4c6410
  ecx = edx = 0;  // @53_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @54_4c6410
  reg.state = (s32)((u32)(3));  // @55_4c6410
  if ((eax & eax) == 0) goto L4c652b;  // @56_4c6410
  ecx = eax;  // @57_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900392), (u32)(6900368), (u32)(ebx));  // @58_4c6410
  ecx = edx = 0;  // @59_4c6410
  edx = eax;  // @60_4c6410
  goto L4c652d;  // @61_4c6410
  L4c652b:;
  edx = 0;  // @63_4c6410
  L4c652d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @65_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_4c6410
  reg.state = (s32)((u32)(0));  // @67_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @69_4c6410
  ecx = edx = 0;  // @70_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @71_4c6410
  ecx = edx = 0;  // @72_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @73_4c6410
  reg.state = (s32)((u32)(4));  // @74_4c6410
  if ((eax & eax) == 0) goto L4c6574;  // @75_4c6410
  ecx = (u32)(esi + 89);  // @76_4c6410
  ecx = eax;  // @77_4c6410
  eax = ext_4d8330_thiscall4(ecx, (u32)(6900424), (u32)(6900408), (u32)(ecx));  // @78_4c6410
  ecx = edx = 0;  // @79_4c6410
  edx = eax;  // @80_4c6410
  goto L4c6576;  // @81_4c6410
  L4c6574:;
  edx = 0;  // @83_4c6410
  L4c6576:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @85_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @86_4c6410
  reg.state = (s32)((u32)(0));  // @87_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @89_4c6410
  ecx = edx = 0;  // @90_4c6410
  eax = esi;  // @91_4c6410
  SEH_LEAVE();  // @92_4c6410
  return eax;  // @93_4c6410
}
PCREG(4c6410, lifted_4c6410);

extern "C" u32 THISCALL lifted_5335d0(u32 ecx_in) {
  SEH_ENTER(0x66a7a2);  // @h_5335d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5335d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_5335d0
  edx = (u32)(EBP - 20);  // @3_5335d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @6_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953228), (u32)(edx));  // @7_5335d0
  ecx = edx = 0;  // @8_5335d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @9_5335d0
  edx = (u32)(EBP - 20);  // @10_5335d0
  eax = (eax & 0xffffff00u) | (((u32)(((eax & 0xff) & (eax & 0xff)) == 0)) & 0xff);  // @11_5335d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 134), &v, sizeof v); }  // @12_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @15_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953240), (u32)(edx));  // @16_5335d0
  ecx = edx = 0;  // @17_5335d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775512), sizeof v); (u32)v; });  // @18_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L53365c;  // @19_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @20_5335d0
  if ((eax & eax) == 0) goto L53365c;  // @21_5335d0
  eax = ((u32( *)(u32))(ebx))((u32)(eax));  // @22_5335d0
  ecx = edx = 0;  // @23_5335d0
  { u8 v = (u8)((u32)((eax & eax) != 0)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @24_5335d0
  L53365c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_5335d0
  edx = (u32)(EBP - 20);  // @27_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @29_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953260), (u32)(edx));  // @30_5335d0
  ecx = edx = 0;  // @31_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L533683;  // @32_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @33_5335d0
  if ((eax & eax) == 0) goto L533683;  // @34_5335d0
  eax = ((u32( *)(u32))(ebx))((u32)(eax));  // @35_5335d0
  ecx = edx = 0;  // @36_5335d0
  L533683:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_5335d0
  edx = (u32)(EBP - 20);  // @39_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @41_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953276), (u32)(edx));  // @42_5335d0
  ecx = edx = 0;  // @43_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5336aa;  // @44_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @45_5335d0
  if ((eax & eax) == 0) goto L5336aa;  // @46_5335d0
  eax = ((u32( *)(u32))(ebx))((u32)(eax));  // @47_5335d0
  ecx = edx = 0;  // @48_5335d0
  L5336aa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_5335d0
  edx = (u32)(EBP - 20);  // @51_5335d0
  esi = (u32)(4);  // @52_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @54_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953296), (u32)(edx));  // @55_5335d0
  ecx = edx = 0;  // @56_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5336ee;  // @57_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @58_5335d0
  if ((eax & eax) == 0) goto L5336ee;  // @59_5335d0
  eax = ((u32(STDCALL *)(u32))(ebx))((u32)(eax));  // @60_5335d0
  ecx = edx = 0;  // @61_5335d0
  esi = eax;  // @62_5335d0
  if ((s32)esi >= (s32)(u32)(1)) goto L5336e4;  // @63_5335d0
  esi = (u32)(1);  // @64_5335d0
  goto L5336ee;  // @65_5335d0
  L5336e4:;
  eax = (u32)(4);  // @67_5335d0
  if ((s32)esi > (s32)eax) esi = eax;  // @68_5335d0
  L5336ee:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 21634), &v, sizeof v); }  // @70_5335d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 13), sizeof v); (u32)v; }) == (u32)(0)) goto L5337a5;  // @71_5335d0
  eax = ext_41e290_cdecl1((u32)(41693));  // @72_5335d0
  ecx = edx = 0;  // @73_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @74_5335d0
  reg.state = (s32)((u32)(0));  // @75_5335d0
  if ((eax & eax) == 0) goto L533724;  // @76_5335d0
  ecx = eax;  // @77_5335d0
  eax = ext_54abf0_thiscall1(ecx);  // @78_5335d0
  ecx = edx = 0;  // @79_5335d0
  edi = eax;  // @80_5335d0
  goto L533726;  // @81_5335d0
  L533724:;
  edi = 0;  // @83_5335d0
  L533726:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_5335d0
  ecx = edi;  // @86_5335d0
  reg.state = (s32)((u32)(4294967295));  // @87_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @88_5335d0
  ecx = edx = 0;  // @89_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_5335d0
  esi = eax;  // @91_5335d0
  eax = (u32)(EBP - 20);  // @92_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 92), sizeof v); (u32)v; });  // @94_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6953312), (u32)(eax));  // @95_5335d0
  ecx = edx = 0;  // @96_5335d0
  ecx = edi;  // @97_5335d0
  eax = (eax & 0xffffff00u) | (((u32)(((eax & 0xff) & (eax & 0xff)) == 0)) & 0xff);  // @98_5335d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 202), &v, sizeof v); }  // @99_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @100_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 172), sizeof v); (u32)v; });  // @101_5335d0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @102_5335d0
  ecx = edx = 0;  // @103_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L533799;  // @104_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @105_5335d0
  ecx = edi;  // @106_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @107_5335d0
  ecx = edx = 0;  // @108_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @109_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; });  // @110_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4 + 21602), &v, sizeof v); }  // @111_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; });  // @112_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 21602), sizeof v); (u32)v; });  // @113_5335d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @114_5335d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 21614), &v, sizeof v); }  // @115_5335d0
  L533799:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @117_5335d0
  ecx = edi;  // @118_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(1));  // @119_5335d0
  ecx = edx = 0;  // @120_5335d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @121_5335d0
  L5337a5:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775112), sizeof v); (u32)v; });  // @123_5335d0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(esi))((u32)(0), (u32)(0), (u32)(1), (u32)(0));  // @124_5335d0
  ecx = edx = 0;  // @125_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7347048), &v, sizeof v); }  // @126_5335d0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(esi))((u32)(0), (u32)(1), (u32)(1), (u32)(0));  // @127_5335d0
  ecx = edx = 0;  // @128_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @129_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7347052), &v, sizeof v); }  // @130_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @131_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @132_5335d0
  ecx = edx = 0;  // @133_5335d0
  esi = eax;  // @134_5335d0
  if ((esi & esi) == 0) goto L53388c;  // @135_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_5335d0
  edx = (u32)(EBP - 24);  // @137_5335d0
  { u32 v = (u32)((u32)(24)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @138_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_5335d0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @140_5335d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @141_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @142_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6792084), (u32)(edx));  // @143_5335d0
  ecx = edx = 0;  // @144_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L53381b;  // @145_5335d0
  eax = ((u32( *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @146_5335d0
  ecx = edx = 0;  // @147_5335d0
  { u8 v = (u8)((u32)((eax & eax) != 0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @148_5335d0
  L53381b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @150_5335d0
  edx = (u32)(EBP - 24);  // @151_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @153_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6792092), (u32)(edx));  // @154_5335d0
  ecx = edx = 0;  // @155_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L533840;  // @156_5335d0
  eax = ((u32( *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @157_5335d0
  ecx = edx = 0;  // @158_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @159_5335d0
  L533840:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @161_5335d0
  eax = (u32)(EBP - 24);  // @162_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @163_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 92), sizeof v); (u32)v; });  // @164_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6791240), (u32)(eax));  // @165_5335d0
  ecx = edx = 0;  // @166_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L533865;  // @167_5335d0
  eax = ((u32( *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @168_5335d0
  ecx = edx = 0;  // @169_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @170_5335d0
  L533865:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @172_5335d0
  ecx = esi;  // @173_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 232)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @174_5335d0
  ecx = edx = 0;  // @175_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @176_5335d0
  ecx = esi;  // @177_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 228)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @178_5335d0
  ecx = edx = 0;  // @179_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @180_5335d0
  ecx = esi;  // @181_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @182_5335d0
  ecx = edx = 0;  // @183_5335d0
  L53388c:;
  ecx = edi;  // @185_5335d0
  eax = ext_5378a0_thiscall1(ecx);  // @186_5335d0
  ecx = edx = 0;  // @187_5335d0
  SEH_LEAVE();  // @188_5335d0
  return eax;  // @189_5335d0
}
PCREG(5335d0, lifted_5335d0);

extern "C" u32 THISCALL lifted_439970(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665b80);  // @h_439970
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_439970
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @2_439970
  if ((ecx & ecx) != 0) goto L439a0f;  // @3_439970
  eax = ext_41e290_cdecl1((u32)(28));  // @4_439970
  ecx = edx = 0;  // @5_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_439970
  reg.state = (s32)((u32)(0));  // @7_439970
  if ((eax & eax) == 0) goto L4399cc;  // @8_439970
  ecx = eax;  // @9_439970
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(45));  // @10_439970
  ecx = edx = 0;  // @11_439970
  goto L4399ce;  // @12_439970
  L4399cc:;
  eax = 0;  // @14_439970
  L4399ce:;
  reg.state = (s32)((u32)(4294967295));  // @16_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4920), &v, sizeof v); }  // @17_439970
  L4399db:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_439970
  L4399de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @21_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @23_439970
  ecx = edx = 0;  // @24_439970
  ebx = eax;  // @25_439970
  ebx = (ebx - (u32)(4));  // @26_439970
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @27_439970
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @28_439970
  reg.state = (s32)((u32)(1));  // @29_439970
  if (ebx == 0) goto L439a93;  // @30_439970
  ecx = ebx;  // @31_439970
  eax = ext_4cbeb0_thiscall1(ecx);  // @32_439970
  ecx = edx = 0;  // @33_439970
  goto L439a95;  // @34_439970
  L439a0f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_439970
  edx = (u32)(EBP - 36);  // @37_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @38_439970
  ecx = edx = 0;  // @39_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @40_439970
  edx = (u32)(EBP - 36);  // @41_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @43_439970
  ecx = edx = 0;  // @44_439970
  ebx = eax;  // @45_439970
  if ((ebx & ebx) == 0) goto L4399db;  // @46_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_439970
  L439a30:;
  ecx = ebx;  // @49_439970
  eax = ext_4cc130_thiscall2(ecx, (u32)(edi));  // @50_439970
  ecx = edx = 0;  // @51_439970
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L439a79;  // @52_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 175), sizeof v); (u32)v; });  // @53_439970
  if ((eax & eax) == 0) goto L439a79;  // @54_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 175), sizeof v); (u32)v; });  // @55_439970
  if ((ecx & ecx) == 0) goto L439a79;  // @56_439970
  L439a50:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @58_439970
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L439a70;  // @59_439970
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L439a6c;  // @60_439970
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @61_439970
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L439a70;  // @62_439970
  eax = (eax + (u32)(2));  // @63_439970
  ecx = (ecx + (u32)(2));  // @64_439970
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L439a50;  // @65_439970
  L439a6c:;
  eax = 0;  // @67_439970
  goto L439a75;  // @68_439970
  L439a70:;
  eax = 0;  // @70_439970
  eax = (eax | (u32)(1));  // @71_439970
  L439a75:;
  if ((eax & eax) == 0) goto L439a9c;  // @73_439970
  L439a79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @75_439970
  edx = (u32)(EBP - 36);  // @76_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @78_439970
  ecx = edx = 0;  // @79_439970
  ebx = eax;  // @80_439970
  if ((ebx & ebx) != 0) goto L439a30;  // @81_439970
  goto L4399de;  // @82_439970
  L439a93:;
  ebx = 0;  // @84_439970
  L439a95:;
  reg.state = (s32)((u32)(4294967295));  // @86_439970
  L439a9c:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 160), sizeof v); (u32)v; })) & 0xff);  // @88_439970
  ecx = ebx;  // @89_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @90_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 161), sizeof v); (u32)v; });  // @91_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 161), &v, sizeof v); }  // @92_439970
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 165), sizeof v); (u32)v; })) & 0xff);  // @93_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 165), &v, sizeof v); }  // @94_439970
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; })) & 0xff);  // @95_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 166), &v, sizeof v); }  // @96_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 167), sizeof v); (u32)v; });  // @97_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 167), &v, sizeof v); }  // @98_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 171), sizeof v); (u32)v; });  // @99_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 171), &v, sizeof v); }  // @100_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 175), sizeof v); (u32)v; });  // @101_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 175), &v, sizeof v); }  // @102_439970
  eax = ext_4cbee0_thiscall2(ecx, (u32)(edi));  // @103_439970
  ecx = edx = 0;  // @104_439970
  esi = ebx;  // @105_439970
  eax = (u32)(edi + 128);  // @106_439970
  edx = 0;  // @107_439970
  esi = (esi - edi);  // @108_439970
  L439b04:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_439970
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @111_439970
  if (ecx == (u32)(-1)) goto L439b20;  // @112_439970
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + eax), &v, sizeof v); }  // @113_439970
  edx = (edx + 1);  // @114_439970
  eax = (eax + (u32)(4));  // @115_439970
  if ((s32)edx < (s32)(u32)(4)) goto L439b04;  // @116_439970
  goto L439b38;  // @117_439970
  L439b20:;
  if ((s32)edx >= (s32)(u32)(4)) goto L439b38;  // @119_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @120_439970
  edi = (u32)(edx + 32);  // @121_439970
  ecx = (ecx - edx);  // @122_439970
  edi = (u32)(ebx + edi*4);  // @123_439970
  eax = (eax | (u32)(4294967295));  // @124_439970
  while (ecx) { __builtin_memcpy((void *)(u32)edi, &eax, 4); edi += 4; ecx--; }  // @125_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @126_439970
  L439b38:;
  ecx = 0;  // @128_439970
  eax = (u32)(edi + 144);  // @129_439970
  L439b40:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @131_439970
  if (edx == (u32)(-1)) goto L439b55;  // @132_439970
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @133_439970
  ecx = (ecx + 1);  // @134_439970
  eax = (eax + (u32)(4));  // @135_439970
  if ((s32)ecx < (s32)(u32)(4)) goto L439b40;  // @136_439970
  goto L439b6c;  // @137_439970
  L439b55:;
  if ((s32)ecx >= (s32)(u32)(4)) goto L439b6c;  // @139_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @140_439970
  edi = (u32)(ecx + 36);  // @141_439970
  eax = (eax - ecx);  // @142_439970
  edi = (u32)(ebx + edi*4);  // @143_439970
  ecx = eax;  // @144_439970
  eax = (eax | (u32)(4294967295));  // @145_439970
  while (ecx) { __builtin_memcpy((void *)(u32)edi, &eax, 4); edi += 4; ecx--; }  // @146_439970
  L439b6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 175), sizeof v); (u32)v; });  // @148_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @149_439970
  if ((ecx & ecx) != 0) goto L439b8a;  // @150_439970
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @151_439970
  ecx = ebx;  // @152_439970
  eax = ext_4cc1d0_thiscall1(ecx);  // @153_439970
  ecx = edx = 0;  // @154_439970
  ecx = edi;  // @155_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, (u32)(eax));  // @156_439970
  ecx = edx = 0;  // @157_439970
  goto L439ba7;  // @158_439970
  L439b8a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @160_439970
  ecx = edi;  // @161_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(ecx));  // @162_439970
  ecx = edx = 0;  // @163_439970
  edi = eax;  // @164_439970
  if ((edi & edi) == 0) goto L439bb9;  // @165_439970
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_439970
  ecx = ebx;  // @167_439970
  eax = ext_4cc1d0_thiscall1(ecx);  // @168_439970
  ecx = edx = 0;  // @169_439970
  ecx = edi;  // @170_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 16)))(ecx, (u32)(eax));  // @171_439970
  ecx = edx = 0;  // @172_439970
  L439ba7:;
  if ((eax & eax) == 0) goto L439bb9;  // @174_439970
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L439bb9;  // @175_439970
  ecx = (u32)(eax - 4);  // @176_439970
  eax = ext_439fd0_thiscall2(ecx, (u32)(ebx));  // @177_439970
  ecx = edx = 0;  // @178_439970
  L439bb9:;
  SEH_LEAVE();  // @180_439970
  return eax;  // @181_439970
}
PCREG(439970, lifted_439970);

extern "C" u32 THISCALL lifted_5b6e20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c39e);  // @h_5b6e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @1_5b6e20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @2_5b6e20
  eax = ext_5b6d00_thiscall1(ecx);  // @3_5b6e20
  ecx = edx = 0;  // @4_5b6e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_5b6e20
  ecx = (u32)(EBP - 24);  // @6_5b6e20
  ecx = esi;  // @7_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @9_5b6e20
  ecx = edx = 0;  // @10_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @11_5b6e20
  if ((eax & eax) == 0) goto L5b7078;  // @12_5b6e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @13_5b6e20
  if ((s32)(eax & eax) <= 0) goto L5b7078;  // @14_5b6e20
  L5b6e80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_5b6e20
  ecx = (u32)(EBP - 28);  // @17_5b6e20
  ecx = esi;  // @18_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @19_5b6e20
  ecx = edx = 0;  // @20_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @21_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @23_5b6e20
  ecx = edx = 0;  // @24_5b6e20
  edi = eax;  // @25_5b6e20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @26_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @27_5b6e20
  ecx = edx = 0;  // @28_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @29_5b6e20
  reg.state = (s32)((u32)(0));  // @30_5b6e20
  if ((eax & eax) == 0) goto L5b6ec2;  // @31_5b6e20
  ecx = eax;  // @32_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(29));  // @33_5b6e20
  ecx = edx = 0;  // @34_5b6e20
  goto L5b6ec4;  // @35_5b6e20
  L5b6ec2:;
  eax = 0;  // @37_5b6e20
  L5b6ec4:;
  reg.state = (s32)((u32)(4294967295));  // @39_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @40_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @41_5b6e20
  ecx = edx = 0;  // @42_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @43_5b6e20
  reg.state = (s32)((u32)(1));  // @44_5b6e20
  if ((eax & eax) == 0) goto L5b6ef2;  // @45_5b6e20
  ecx = eax;  // @46_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(32));  // @47_5b6e20
  ecx = edx = 0;  // @48_5b6e20
  goto L5b6ef4;  // @49_5b6e20
  L5b6ef2:;
  eax = 0;  // @51_5b6e20
  L5b6ef4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @53_5b6e20
  ecx = esi;  // @54_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_5b6e20
  eax = (u32)(edi + 56);  // @56_5b6e20
  reg.state = (s32)((u32)(4294967295));  // @57_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @58_5b6e20
  ecx = edx = 0;  // @59_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_5b6e20
  eax = (u32)(edi + 96);  // @61_5b6e20
  ecx = esi;  // @62_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(36));  // @63_5b6e20
  ecx = edx = 0;  // @64_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @65_5b6e20
  eax = (u32)(edi + 72);  // @66_5b6e20
  ecx = esi;  // @67_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @68_5b6e20
  ecx = edx = 0;  // @69_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_5b6e20
  eax = (u32)(edi + 84);  // @71_5b6e20
  ecx = esi;  // @72_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @73_5b6e20
  ecx = edx = 0;  // @74_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @75_5b6e20
  eax = (u32)(edi + 60);  // @76_5b6e20
  ecx = esi;  // @77_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @78_5b6e20
  ecx = edx = 0;  // @79_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_5b6e20
  eax = (u32)(edi + 8);  // @81_5b6e20
  ecx = esi;  // @82_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(48));  // @83_5b6e20
  ecx = edx = 0;  // @84_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @85_5b6e20
  eax = (u32)(edi + 132);  // @86_5b6e20
  ecx = esi;  // @87_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @88_5b6e20
  ecx = edx = 0;  // @89_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_5b6e20
  eax = (u32)(edi + 136);  // @91_5b6e20
  ecx = esi;  // @92_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @93_5b6e20
  ecx = edx = 0;  // @94_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_5b6e20
  eax = (u32)(edi + 140);  // @96_5b6e20
  ecx = esi;  // @97_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(1));  // @98_5b6e20
  ecx = edx = 0;  // @99_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_5b6e20
  ecx = (u32)(EBP + 8);  // @101_5b6e20
  ecx = esi;  // @102_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @103_5b6e20
  ecx = edx = 0;  // @104_5b6e20
  ebx = 0;  // @105_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b6ffd;  // @106_5b6e20
  L5b6f90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_5b6e20
  ecx = (u32)(EBP - 32);  // @109_5b6e20
  ecx = esi;  // @110_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @111_5b6e20
  ecx = edx = 0;  // @112_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @113_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @114_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @115_5b6e20
  ecx = edx = 0;  // @116_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @117_5b6e20
  edi = eax;  // @118_5b6e20
  ecx = esi;  // @119_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(edi), (u32)(4));  // @120_5b6e20
  ecx = edx = 0;  // @121_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @122_5b6e20
  ecx = (u32)(edi + 4);  // @123_5b6e20
  ecx = esi;  // @124_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(ecx), (u32)(4));  // @125_5b6e20
  ecx = edx = 0;  // @126_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @127_5b6e20
  eax = (u32)(edi + 8);  // @128_5b6e20
  ecx = esi;  // @129_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @130_5b6e20
  ecx = edx = 0;  // @131_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_5b6e20
  eax = (u32)(edi + 12);  // @133_5b6e20
  ecx = esi;  // @134_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(1));  // @135_5b6e20
  ecx = edx = 0;  // @136_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_5b6e20
  eax = (u32)(edi + 13);  // @138_5b6e20
  ecx = esi;  // @139_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @140_5b6e20
  ecx = edx = 0;  // @141_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_5b6e20
  eax = (u32)(edi + 17);  // @143_5b6e20
  ecx = esi;  // @144_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @145_5b6e20
  ecx = edx = 0;  // @146_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @147_5b6e20
  ebx = (ebx + 1);  // @148_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b6f90;  // @149_5b6e20
  L5b6ffd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @151_5b6e20
  ecx = (u32)(EBP + 8);  // @152_5b6e20
  ecx = esi;  // @153_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @154_5b6e20
  ecx = edx = 0;  // @155_5b6e20
  ebx = 0;  // @156_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b7065;  // @157_5b6e20
  L5b7011:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @159_5b6e20
  ecx = (u32)(EBP - 36);  // @160_5b6e20
  ecx = esi;  // @161_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @162_5b6e20
  ecx = edx = 0;  // @163_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @164_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @166_5b6e20
  ecx = edx = 0;  // @167_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @168_5b6e20
  edi = eax;  // @169_5b6e20
  ecx = esi;  // @170_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(edi), (u32)(12));  // @171_5b6e20
  ecx = edx = 0;  // @172_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @173_5b6e20
  ecx = (u32)(edi + 12);  // @174_5b6e20
  ecx = esi;  // @175_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(ecx), (u32)(12));  // @176_5b6e20
  ecx = edx = 0;  // @177_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @178_5b6e20
  eax = (u32)(edi + 28);  // @179_5b6e20
  ecx = esi;  // @180_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @181_5b6e20
  ecx = edx = 0;  // @182_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @183_5b6e20
  eax = (u32)(edi + 24);  // @184_5b6e20
  ecx = esi;  // @185_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @186_5b6e20
  ecx = edx = 0;  // @187_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @188_5b6e20
  ebx = (ebx + 1);  // @189_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b7011;  // @190_5b6e20
  L5b7065:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @192_5b6e20
  ebx = (ebx + 1);  // @193_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @194_5b6e20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @195_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) goto L5b6e80;  // @196_5b6e20
  L5b7078:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @198_5b6e20
  SEH_LEAVE();  // @199_5b6e20
  return eax;  // @200_5b6e20
}
PCREG(5b6e20, lifted_5b6e20);

extern "C" u32 THISCALL lifted_42b460(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664b9e);  // @h_42b460
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42b460
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_42b460
  { u32 v = (u32)((u32)(6789024)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_42b460
  edi = (u32)(esi + 28);  // @3_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @4_42b460
  ebx = (u32)(esi + 36);  // @5_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_42b460
  ecx = (u32)(esi + 163);  // @7_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @8_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @9_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @10_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @11_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @12_42b460
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @13_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @14_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @15_42b460
  ecx = edx = 0;  // @16_42b460
  ecx = (u32)(esi + 291);  // @17_42b460
  reg.state = (s32)((u32)(0));  // @18_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @19_42b460
  ecx = edx = 0;  // @20_42b460
  ecx = (u32)(esi + 419);  // @21_42b460
  reg.state = (s32)((u32)(1));  // @22_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @23_42b460
  ecx = edx = 0;  // @24_42b460
  ecx = (u32)(esi + 547);  // @25_42b460
  reg.state = (s32)((u32)(2));  // @26_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @27_42b460
  ecx = edx = 0;  // @28_42b460
  ecx = (u32)(esi + 675);  // @29_42b460
  reg.state = (s32)((u32)(3));  // @30_42b460
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789488));  // @31_42b460
  ecx = edx = 0;  // @32_42b460
  ecx = (u32)(esi + 803);  // @33_42b460
  reg.state = (s32)((u32)(4));  // @34_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @35_42b460
  ecx = edx = 0;  // @36_42b460
  ecx = (u32)(esi + 931);  // @37_42b460
  reg.state = (s32)((u32)(5));  // @38_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @39_42b460
  ecx = edx = 0;  // @40_42b460
  ecx = (u32)(esi + 1059);  // @41_42b460
  reg.state = (s32)((u32)(6));  // @42_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @43_42b460
  ecx = edx = 0;  // @44_42b460
  ecx = (u32)(esi + 1187);  // @45_42b460
  reg.state = (s32)((u32)(7));  // @46_42b460
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789504));  // @47_42b460
  ecx = edx = 0;  // @48_42b460
  ecx = (u32)(esi + 1315);  // @49_42b460
  reg.state = (s32)((u32)(8));  // @50_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @51_42b460
  ecx = edx = 0;  // @52_42b460
  ecx = (u32)(esi + 1443);  // @53_42b460
  reg.state = (s32)((u32)(9));  // @54_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @55_42b460
  ecx = edx = 0;  // @56_42b460
  ecx = (u32)(esi + 1571);  // @57_42b460
  reg.state = (s32)((u32)(10));  // @58_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @59_42b460
  ecx = edx = 0;  // @60_42b460
  ecx = (u32)(esi + 1699);  // @61_42b460
  reg.state = (s32)((u32)(11));  // @62_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @63_42b460
  ecx = edx = 0;  // @64_42b460
  ecx = (u32)(esi + 1827);  // @65_42b460
  reg.state = (s32)((u32)(12));  // @66_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @67_42b460
  ecx = edx = 0;  // @68_42b460
  ecx = (u32)(esi + 1955);  // @69_42b460
  reg.state = (s32)((u32)(13));  // @70_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @71_42b460
  ecx = edx = 0;  // @72_42b460
  ecx = (u32)(esi + 2083);  // @73_42b460
  reg.state = (s32)((u32)(14));  // @74_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @75_42b460
  ecx = edx = 0;  // @76_42b460
  ecx = (u32)(esi + 2211);  // @77_42b460
  reg.state = (s32)((u32)(15));  // @78_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @79_42b460
  ecx = edx = 0;  // @80_42b460
  ecx = (u32)(esi + 2339);  // @81_42b460
  reg.state = (s32)((u32)(16));  // @82_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @83_42b460
  ecx = edx = 0;  // @84_42b460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @85_42b460
  ecx = (u32)(esi + 6423);  // @86_42b460
  reg.state = (s32)((u32)(17));  // @87_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2511), &v, sizeof v); }  // @88_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @89_42b460
  ecx = edx = 0;  // @90_42b460
  ecx = (u32)(esi + 6551);  // @91_42b460
  reg.state = (s32)((u32)(18));  // @92_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @93_42b460
  ecx = edx = 0;  // @94_42b460
  ecx = (u32)(esi + 6679);  // @95_42b460
  reg.state = (s32)((u32)(19));  // @96_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @97_42b460
  ecx = edx = 0;  // @98_42b460
  ecx = (u32)(esi + 6839);  // @99_42b460
  reg.state = (s32)((u32)(20));  // @100_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6815), &v, sizeof v); }  // @101_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6819), &v, sizeof v); }  // @102_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6823), &v, sizeof v); }  // @103_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @104_42b460
  ecx = edx = 0;  // @105_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7004), &v, sizeof v); }  // @106_42b460
  ecx = (u32)(EBP - 160);  // @107_42b460
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 6808), &v, sizeof v); }  // @108_42b460
  eax = (u32)(esi + 76);  // @109_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6993), &v, sizeof v); }  // @110_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6997), &v, sizeof v); }  // @111_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7001), &v, sizeof v); }  // @112_42b460
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7340956), &v, sizeof v); }  // @113_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6827), &v, sizeof v); }  // @114_42b460
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2487), &v, sizeof v); }  // @115_42b460
  { u32 v = (u32)((u32)(16777216)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @116_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @117_42b460
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 6976), &v, sizeof v); }  // @118_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6980), &v, sizeof v); }  // @119_42b460
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 6984), &v, sizeof v); }  // @120_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6812), &v, sizeof v); }  // @121_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2531), &v, sizeof v); }  // @122_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6807), &v, sizeof v); }  // @123_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 127), &v, sizeof v); }  // @124_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 147), &v, sizeof v); }  // @125_42b460
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 151), &v, sizeof v); }  // @126_42b460
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 143), &v, sizeof v); }  // @127_42b460
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @128_42b460
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @129_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @130_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2489), &v, sizeof v); }  // @131_42b460
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 2467), &v, sizeof v); }  // @132_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6967), &v, sizeof v); }  // @133_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2503), &v, sizeof v); }  // @134_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @135_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2491), &v, sizeof v); }  // @136_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2495), &v, sizeof v); }  // @137_42b460
  { u32 v = (u32)((u32)(7227576)); __builtin_memcpy((void *)(u32)(esi + 6411), &v, sizeof v); }  // @138_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6974), &v, sizeof v); }  // @139_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6415), &v, sizeof v); }  // @140_42b460
  { u32 v = (u32)((u32)(1040187392)); __builtin_memcpy((void *)(u32)(esi + 2471), &v, sizeof v); }  // @141_42b460
  { u32 v = (u32)((u32)(1056293519)); __builtin_memcpy((void *)(u32)(esi + 2475), &v, sizeof v); }  // @142_42b460
  { u32 v = (u32)((u32)(1061158912)); __builtin_memcpy((void *)(u32)(esi + 2479), &v, sizeof v); }  // @143_42b460
  { u32 v = (u32)((u32)(1025758986)); __builtin_memcpy((void *)(u32)(esi + 2483), &v, sizeof v); }  // @144_42b460
  reg.state = (s32)((u32)(21));  // @145_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6989), &v, sizeof v); }  // @146_42b460
  { u32 v = (u32)((u32)(1114636288)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @147_42b460
  if (eax == ecx) goto L42b7bc;  // @148_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @149_42b460
  L42b7bc:;
  eax = (u32)(EBP - 164);  // @151_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @152_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @153_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @154_42b460
  if (edi == eax) goto L42b7e1;  // @155_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @156_42b460
  L42b7e1:;
  eax = (u32)(EBP - 168);  // @158_42b460
  if (ebx == eax) goto L42b7f1;  // @159_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @160_42b460
  L42b7f1:;
  ecx = (u32)(EBP - 144);  // @162_42b460
  { u32 v = (u32)((u32)(1114636288)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @163_42b460
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @164_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @165_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7003), &v, sizeof v); }  // @166_42b460
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789528));  // @167_42b460
  ecx = edx = 0;  // @168_42b460
  eax = (u32)(EBP - 144);  // @169_42b460
  reg.state = (s32)((u32)(22));  // @170_42b460
  ecx = (u32)(esi + 2211);  // @171_42b460
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @172_42b460
  ecx = edx = 0;  // @173_42b460
  ecx = (u32)(EBP - 144);  // @174_42b460
  reg.state = (s32)((u32)(21));  // @175_42b460
  eax = ext_4cbec0_thiscall1(ecx);  // @176_42b460
  ecx = edx = 0;  // @177_42b460
  ecx = (u32)(esi + 1955);  // @178_42b460
  eax = ext_4cbf30_thiscall2(ecx, (u32)(0));  // @179_42b460
  ecx = edx = 0;  // @180_42b460
  ecx = (u32)(esi + 2083);  // @181_42b460
  eax = ext_4cbf30_thiscall2(ecx, (u32)(0));  // @182_42b460
  ecx = edx = 0;  // @183_42b460
  ecx = (u32)(EBP - 144);  // @184_42b460
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789540));  // @185_42b460
  ecx = edx = 0;  // @186_42b460
  eax = (u32)(EBP - 144);  // @187_42b460
  reg.state = (s32)((u32)(23));  // @188_42b460
  ecx = (u32)(esi + 419);  // @189_42b460
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @190_42b460
  ecx = edx = 0;  // @191_42b460
  ecx = (u32)(EBP - 144);  // @192_42b460
  reg.state = (s32)((u32)(21));  // @193_42b460
  eax = ext_4cbec0_thiscall1(ecx);  // @194_42b460
  ecx = edx = 0;  // @195_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7005), &v, sizeof v); }  // @196_42b460
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(esi + 6971), &v, sizeof v); }  // @197_42b460
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 6973), &v, sizeof v); }  // @198_42b460
  eax = ext_41e290_cdecl1((u32)(12));  // @199_42b460
  ecx = edx = 0;  // @200_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @201_42b460
  if ((eax & eax) == 0) goto L42b8d5;  // @202_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @203_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @204_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @205_42b460
  goto L42b8d7;  // @206_42b460
  L42b8d5:;
  eax = 0;  // @208_42b460
  L42b8d7:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 7009), &v, sizeof v); }  // @210_42b460
  eax = ext_41e290_cdecl1((u32)(9));  // @211_42b460
  ecx = edx = 0;  // @212_42b460
  edi = eax;  // @213_42b460
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @214_42b460
  reg.state = (s32)((u32)(24));  // @215_42b460
  if ((edi & edi) == 0) goto L42b927;  // @216_42b460
  ecx = edi;  // @217_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @218_42b460
  eax = ext_6014a0_stdcall1((u32)(37));  // @219_42b460
  ecx = edx = 0;  // @220_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @221_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @222_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @223_42b460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @224_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @225_42b460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @226_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @227_42b460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @228_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @229_42b460
  goto L42b929;  // @230_42b460
  L42b927:;
  edi = 0;  // @232_42b460
  L42b929:;
  reg.state = (s32)((u32)(21));  // @234_42b460
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 7013), &v, sizeof v); }  // @235_42b460
  eax = ext_41e290_cdecl1((u32)(12));  // @236_42b460
  ecx = edx = 0;  // @237_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @238_42b460
  if ((eax & eax) == 0) goto L42b95d;  // @239_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @240_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @241_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @242_42b460
  goto L42b95f;  // @243_42b460
  L42b95d:;
  eax = 0;  // @245_42b460
  L42b95f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 7017), &v, sizeof v); }  // @247_42b460
  eax = ext_41e290_cdecl1((u32)(12));  // @248_42b460
  ecx = edx = 0;  // @249_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @250_42b460
  if ((eax & eax) == 0) goto L42b98f;  // @251_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @252_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @253_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @254_42b460
  goto L42b991;  // @255_42b460
  L42b98f:;
  eax = 0;  // @257_42b460
  L42b991:;
  ecx = esi;  // @259_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 7021), &v, sizeof v); }  // @260_42b460
  eax = ext_42c9a0_thiscall1(ecx);  // @261_42b460
  ecx = edx = 0;  // @262_42b460
  eax = esi;  // @263_42b460
  SEH_LEAVE();  // @264_42b460
  ext_633654(G(u32, 0x6f5630));  // @265_42b460
  return eax;  // @266_42b460
}
PCREG(42b460, lifted_42b460);

extern "C" u32 lifted_4216f0(void) {
  SEH_ENTER(0x664311);  // @h_4216f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; }) != (u32)(0)) goto L4217ad;  // @0_4216f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340968), sizeof v); (u32)v; }) == (u32)(0)) goto L421737;  // @1_4216f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2_4216f0
  if ((eax & eax) == 0) goto L421736;  // @3_4216f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @4_4216f0
  ecx = edx = 0;  // @5_4216f0
  goto L421737;  // @6_4216f0
  L421736:;
  __builtin_trap();  // @8_4216f0
  L421737:;
  eax = ext_41e290_cdecl1((u32)(4116));  // @10_4216f0
  ecx = edx = 0;  // @11_4216f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_4216f0
  reg.state = (s32)((u32)(0));  // @13_4216f0
  if ((eax & eax) == 0) goto L42175d;  // @14_4216f0
  ecx = eax;  // @15_4216f0
  eax = ext_5f12d0_thiscall1(ecx);  // @16_4216f0
  ecx = edx = 0;  // @17_4216f0
  ecx = eax;  // @18_4216f0
  goto L42175f;  // @19_4216f0
  L42175d:;
  ecx = 0;  // @21_4216f0
  L42175f:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340964), &v, sizeof v); }  // @23_4216f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4216f0
  reg.state = (s32)((u32)(4294967295));  // @25_4216f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @26_4216f0
  ecx = edx = 0;  // @27_4216f0
  eax = ext_41e290_cdecl1((u32)(52));  // @28_4216f0
  ecx = edx = 0;  // @29_4216f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @30_4216f0
  reg.state = (s32)((u32)(1));  // @31_4216f0
  if ((eax & eax) == 0) goto L421794;  // @32_4216f0
  ecx = eax;  // @33_4216f0
  eax = ext_4ff7b0_thiscall1(ecx);  // @34_4216f0
  ecx = edx = 0;  // @35_4216f0
  ecx = eax;  // @36_4216f0
  goto L421796;  // @37_4216f0
  L421794:;
  ecx = 0;  // @39_4216f0
  L421796:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340968), &v, sizeof v); }  // @41_4216f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4216f0
  reg.state = (s32)((u32)(4294967295));  // @43_4216f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @44_4216f0
  ecx = edx = 0;  // @45_4216f0
  eax = ext_41cfd0_thiscall1(ecx);  // @46_4216f0
  ecx = edx = 0;  // @47_4216f0
  L4217ad:;
  SEH_LEAVE();  // @49_4216f0
  return eax;  // @50_4216f0
}
PCREG(4216f0, lifted_4216f0);

